#include "matching.h"
#include "common.h"
#include "spyro.h"
#include "camera.h"
#include "savepoint.h"
#include "spu.h"
#include "ovl_header.h"
#include "moby/mobytag.h"
#include "stdutil.h"
#include "mobyutil.h"
extern void func_80039714(Moby*);

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
void func_level_37_80074D90(Moby* argument) {
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
void func_level_37_8007541C(void* input) {
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


typedef struct {
    short counter;
    unsigned char unk2, unk3;
} DecodedColourTag;
void func_80055B18(Moby*);
void func_level_37_8007696C(Moby* moby) {
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
void func_level_37_80076AA8(Moby* moby) {
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
void func_level_37_80076B64(Moby* moby) {
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
void func_level_37_80076C18(Moby* moby) {
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
void func_level_37_80076F1C(void* input) {
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
        tag = Controller78288Field(owner, void**, 0);
        prefixTag = 0;
    } else {
        MATCHING_KEEP(owner);
        prefixTag = Controller78288Field(owner, void**, 0);
        tag = prefixTag + 0x2C;
    }
    ownerPositionWord = (int)(owner + 0xC);
    distanceResult = Controller78288ApproximatePlanarDistance((void*)ownerPositionWord,
                                                              Controller78288D_80070328);
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
                                Controller78288Field(tag, unsigned char*, 2) = 0U;
                            }
                        }
                        if (Controller78288Field(tag, unsigned char*, 2) == 1) {
                            Controller78288Field(prefixTag, unsigned char*, 5) = 1U;
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
                                Controller78288Helper512E4(owner, 0, 0);
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
                    if (Controller78288D_8006E344 != 1) {
                        goto setSubstateFour;
                    }
                    goto clearExtraHandle;
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
                Controller78288Helper492DC(ownerPositionWord);
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

#undef Controller78288Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0; three original899-word actor functions.
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
extern Vector3D Original899PlayerPositionView __asm__("D_80070328");
extern Vector3D Original899CameraPositionView __asm__("D_8006E020");
/* Local views preserve existing TU declarations. Symbols and word ABI are
* verified against original callers and existing tracers.h/tracers.c. */
void* Original899CreateHandleView(int, int, int, int, int) __asm__("func_80050B00");
void Original899ReleaseHandleView(int*) __asm__("func_80050B88");
#include "ovl_header.h"
extern int D_8006C574, D_8006C578, D_8006C640, D_8006C7E8, D_80071924, D_80071934;
extern unsigned char* Original899ModelTableView[] __asm__("D_8006EE2C");
extern unsigned char D_8006D048[];
extern short D_800658A0[256], D_80065920[256];
int func_8001830C(Vector3D*, Vector3D*, int, int, int);
int func_80019138(Vector3D*, int, int, int, int, Moby*);
Moby* func_8001BA30(Vector3D*, int, int, int, int, Moby*);
int func_80040954(int);
void func_8004EA90(Angle*, SHORTMATRIX*, int);
void func_8004F0E8(Vector3D*, int);
void Original899MatrixCallView(void*, Vector3D*, Vector3D*) __asm__("func_8004ED6C");
int func_8004EDE8(Vector3D*, int);
int Original899PlayMobySoundEventView(Moby*, int, int) __asm__("func_8003BABC");
void func_80055D24(Moby*, int);
int rand(void);
typedef struct {
    unsigned char current0, next1, other2, otherNext3, byte4, byte5, byte6, byte7;
} Original899IndexWords;
typedef struct {
    short cursor0;
    unsigned short count2;
    Vector3D positions4[12];
    Vector3D vertices94[10];
    int sentinel10C;
    unsigned char colours110[8];
    Original899IndexWords indices118[5];
    int sentinel140;
} Original899Buffer;
typedef struct {
    Vector3D16 vector0;
    unsigned char byte6, timer7;
    Original899Buffer* buffer8;
    int* handleC;
    int words10[2];
} Original899PrivateRecord;
typedef struct {
    int word0;
    unsigned int word4;
} Original899FlagWords;
static __inline__ void Original899InitializeChild(Moby* child) {
    unsigned char* descriptor;
    unsigned int first, flag;
    ((volatile Moby*)child)->state = 1;
    child->unknown3[1] = 0;
    descriptor = *(unsigned char**)(Original899ModelTableView[child->mobyClass] + 0x40);
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
} Original899CompleteProduct;
void func_level_37_80077A90(Moby* arg0) {
    Moby* owner = arg0;
    int x = owner->position.x;
    register Original899PrivateRecord* tag __asm__("$22") = owner->mobyTag;
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
    Original899IndexWords* indices;
    if (x < 1024 || (y = owner->position.y) < 1024 || owner->position.z < 1024 || x > 0x3C000 ||
        y > 0x3C000) {
        if (tag->handleC)
            Original899ReleaseHandleView(tag->handleC);
        func_80055B18(owner);
        /* Original continues after this helper; no early return is added. */
    }
    MATCHING_OBSERVE(tag);
    if (owner->state != 2 && owner->substate == 0) {
        Vector3D* position = &owner->position;
        Original899Buffer* buffer = tag->buffer8;
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
        if (func_8001830C(&owner->position, &Original899PlayerPositionView, 2, 0, 0))
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
                    Original899InitializeChild(child);
                }
            }
            if (owner->state == 0 && func_800359A4((char*)&tag->timer7, 1)) {
                if (tag->handleC)
                    Original899ReleaseHandleView(tag->handleC);
                tag->handleC = 0;
                owner->state = 1;
            }
            break;
        }
        case 1: {
            register int loopIndex __asm__("$20");
            Original899PlayMobySoundEventView(owner, 1, 0);
            if (D_8006C578 - D_8006C574 >= 21 && D_8006C7E8 >= 30001) {
                Moby* child = SpawnMoby(326, owner);
                if (child) {
                    D_8006C7E8 -= 1500;
                    child->unknown4 = 7;
                }
            }
            loopIndex = 0;
            if (D_8006C578 - D_8006C574 >= 21) {
                register Vector3D* cameraPosition __asm__("$21") = &Original899CameraPositionView;
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
                    Original899MatrixCallView(&originalFrame.matrix48, &originalFrame.vector28,
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
                    Original899FlagWords* flags =
                        (*(Original899FlagWords***)(D_8006D048 + 0x14))[*sourceWord & 63];
                    flags->word4 |= 0x950000;
                }
            }
            if (func_800359A4((char*)&tag->timer7, 1)) {
                if (tag->handleC)
                    Original899ReleaseHandleView(tag->handleC);
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
        Original899Buffer* buffer = tag->buffer8;
        register int previousCursor3 __asm__("$3") = buffer->cursor0;
        register int previousPositionByteOffset2 __asm__("$2") = previousCursor3 * 12;
        register int initialPositionByteOffset20 __asm__("$20");
        int retainedPositionByteOffset;
        register int nextCursorInput6 __asm__("$6") = previousCursor3 + 1;
        Original899CompleteProduct completeDivisionProduct;
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
            Original899MatrixCallView(&originalFrame.matrix78, firstVector68, firstVector68);
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
                Original899MatrixCallView(&originalFrame.matrix78, secondVector18, secondVector18);
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
            Original899IndexWords* item = (Original899IndexWords*)(loopIndex * 8 + (int)indices);
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
            tag->handleC = (int*)Original899CreateHandleView(callVertices, callColours, callIndices,
                                                             callWords, 1);
        }
    }
}


void func_level_37_8007889C(Moby* moby) {
    func_80039714(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_37/moby/func_level_37_800788BC.s SHA256 9e581b414f770b37513f0e06ad242dca341f2418cbd92bc6629f9ea6a665e21f. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level37_788BCField(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Level37_788BC_func_80019194() __asm__("func_80019194");
/* extern */
int Level37_788BCCountTimerDown() __asm__("func_800359A4");
/* extern */
int Level37_788BCProbeGroundFromRaisedMoby() __asm__("func_80035D38");
/* extern */
unsigned int Level37_788BC_func_80035EE0() __asm__("func_80035EE0");
/* extern */
int Level37_788BCRandBetween() __asm__("func_8003636C");
/* extern */
int Level37_788BCRandSignedBetween() __asm__("func_800363DC");
/* extern */
unsigned int Level37_788BC_func_80037014() __asm__("func_80037014");
/* extern */
int Level37_788BC_func_80037A60() __asm__("func_80037A60");
/* extern */
unsigned int Level37_788BCPlayMobySoundEvent() __asm__("func_8003BABC");
/* extern */
unsigned int Level37_788BC_func_8004E790() __asm__("func_8004E790");
/* extern */
int Level37_788BCPlanarHeadingLookup() __asm__("func_8004E880");
/* extern */
unsigned int Level37_788BCNormalizeVectorToLength() __asm__("func_8004EF04");
/* extern */
unsigned int Level37_788BCScaleVectorRatioQ15() __asm__("func_8004F08C");
/* extern */
unsigned int Level37_788BCClearVector() __asm__("func_8004F168");
/* extern */
unsigned int Level37_788BCCopyVector() __asm__("func_8004F178");
/* extern */
unsigned int Level37_788BCDeleteMoby() __asm__("func_80055B18");
/* extern */
unsigned int Level37_788BCRefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
/* extern */
int Level37_788BC_rand() __asm__("rand");
/* extern */
extern unsigned char Level37_788BC_D_800658A0 __asm__("D_800658A0");
extern unsigned char Level37_788BC_D_80065920 __asm__("D_80065920");
extern int* Level37_788BC_D_8006C550 __asm__("D_8006C550");
extern int Level37_788BC_D_8006C574 __asm__("D_8006C574");
extern int Level37_788BC_D_8006C578 __asm__("D_8006C578");
extern int Level37_788BC_D_8006C648 __asm__("D_8006C648");
extern unsigned char Level37_788BC_D_8006EE2C __asm__("D_8006EE2C");
extern unsigned char Level37_788BC_D_80070328 __asm__("D_80070328");
extern int Level37_788BC_D_80071918 __asm__("D_80071918");
extern int Level37_788BC_D_8007191C __asm__("D_8007191C");
extern int Level37_788BC_D_80071920 __asm__("D_80071920");
extern int** (*Level37_788BC_SpawnMoby)() __asm__("SpawnMoby");
extern unsigned char (*Level37_788BC_SpawnParticle)() __asm__("SpawnParticle");

/* Original66..85: signed LH inputs at private+0/+2/+4, cached global
 * word0 and separate global words+4/+8. MULT wraps into its raw low word;
 * partial products use5/4 and the final product3, then the sum is2.
 * Initialized empty constraints preserve the original latency placement.
 * This helper is inlined;
  exact acceptance forbids an added runtime call. */
static __inline__ int Level37_788BC_CompleteDot(short* p, int* v0, int* v1, int* v2) {
    register int word3 __asm__("$3");
    register int word2 __asm__("$2");
    register int product5 __asm__("$5");
    register int product4 __asm__("$4");
    word3 = p[0];
    word2 = *v0;
    MATCHING_KEEP2(word3, word2);
    product5 = word3 * word2;
    word3 = p[1];
    word2 = *v1;
    MATCHING_KEEP2(word3, word2);
    product4 = word3 * word2;
    word3 = p[2];
    word2 = *v2;
    MATCHING_KEEP2(word3, word2);
    word3 *= word2;
    word2 = product5 + product4;
    __asm__("" : "=r"(word3) : "0"(word3), "r"(word2), "r"(product5), "r"(product4));
    word2 += word3;
    return word2;
}
void func_level_37_800788BC(void* inputOwner) {
    register void* ownerRecord19 __asm__("$19") = inputOwner;
    /* Original0x78-byte frame: scratch begins SP+0x18;
     saved S0 at
     * SP+0x58. Address literals are original byte offsets, not int-pointer
     * scaling. The descriptor table atD6EE2C uses LW;
      its selected payload
     * byte uses LBU. Duplicate mode0/1 blocks remain independently emitted.
     * Units/helper meanings/frame cadence are unresolved;
      per invocation only. */
    struct {
        int sp18;
        int sp1C;
        int sp20;
        unsigned char pad24[4];
        int sp28;
        unsigned char pad2C[12];
        unsigned char sp38;
        unsigned char pad39[7];
        int sp40;
        unsigned char pad44[20];
    } originalFrame;

    short* temp_v1;
    register int temp_a0_2 __asm__("$4");
    register int temp_a0_3 __asm__("$4");
    register int temp_a0_4 __asm__("$4");
    register int temp_a1 __asm__("$5");
    int temp_s0_2;
    int temp_s1_2;
    int temp_v0_2;
    int temp_v1_5;
    register int var_v0 __asm__("$2");
    int var_v0_2;
    register int var_v0_3 __asm__("$2");
    int var_v0_4;
    register int var_v0_6 __asm__("$2");
    int var_v0_7;
    register int var_v0_8 __asm__("$2");
    int var_v1_2;
    int** particleRecord16;
    int** spawnedRecord17;
    int* privateRecord16;
    int* activePrivate16;
    int* temp_s0_4;
    int* temp_s1;
    register int* temp_s4 __asm__("$20");
    int temp_a3;
    int temp_s2;
    register int temp_s4_2 __asm__("$20");
    register int initialData21 __asm__("$21");
    int temp_v0;
    int firstDot, secondDot;
    int temp_v0_3;
    int temp_v1_4;
    int spawnIndex17;
    int var_v0_5;
    int var_v1;
    unsigned int temp_v0_5;
    register unsigned int temp_a0 __asm__("$4");
    register unsigned int temp_s2_2 __asm__("$18");
    unsigned int temp_v1_2;
    unsigned int temp_v1_3;
    void* var_a0;
    register int phaseEight2 __asm__("$2");
    int tableByteIndex;
    int firstDotProduct, secondDotProduct, lastDotLow;
    register int derivedWord2 __asm__("$2");
    int firstOriginalValue, secondOriginalValue;
    int savedHelperResult;
    register void* helperOwner4 __asm__("$4");
    register int helperMode5 __asm__("$5");
    register int finalWord4 __asm__("$4");
    register int tableBase17 __asm__("$17");
    register int firstCoefficient4 __asm__("$4");
    int packedCoefficient, rawProduct, lookupWord;
    register int packedValue __asm__("$2");
    unsigned char* globalWords17;

    MATCHING_KEEP_CLOBBER(ownerRecord19, "$2");
    temp_a0 = Level37_788BCField(ownerRecord19, unsigned char*, 0x48);
    initialData21 = *Level37_788BC_D_8006C550;
    if (temp_a0 != 3) {
        goto block_17;
    }
    privateRecord16 = Level37_788BCField(ownerRecord19, int**, 0);
    if (Level37_788BCField(ownerRecord19, int*, 0xC) < 0x400) {
        goto block_70;
    }
    if (Level37_788BCField(ownerRecord19, int*, 0x10) < 0x400) {
        goto block_70;
    }
    if (Level37_788BCField(ownerRecord19, int*, 0x14) < 0x400) {
        goto block_70;
    }
    if (Level37_788BCField(ownerRecord19, unsigned char*, 0x4D) != 0) {
        goto block_7;
    }
    var_a0 = ((unsigned char*)privateRecord16 + 0xC);
    if (Level37_788BCField(privateRecord16, int*, 0xC) < 0x29) {
        goto block_8;
    }
    Level37_788BCField(privateRecord16, int*, 0xC) = 0x28;
block_7:
    var_a0 = ((unsigned char*)privateRecord16 + 0xC);
block_8:
    if (Level37_788BCCountTimerDown(var_a0, 4) == 0) {
        goto block_10;
    }
    Level37_788BC_SpawnParticle(8, 0x46, ownerRecord19 + 0xC, (int*)0x10);
    goto block_70;
block_10:
    if (Level37_788BC_func_80019194(ownerRecord19 + 0xC, 0x12C) == 0) {
        goto block_13;
    }
    globalWords17 = &Level37_788BC_D_80071918;
    MATCHING_KEEP(globalWords17);
    Level37_788BCNormalizeVectorToLength(globalWords17, 0x1000);
    temp_v0 = Level37_788BC_CompleteDot((short*)privateRecord16, (int*)globalWords17,
                                        &Level37_788BC_D_8007191C, &Level37_788BC_D_80071920);
    temp_a3 = temp_v0 >> 0xB;
    if (temp_a3 >= 0) {
        goto block_13;
    }
    Level37_788BCScaleVectorRatioQ15(globalWords17, 0x1000, (temp_v0 >> 0xD) - temp_a3, temp_a3);
    Level37_788BCField(privateRecord16, short*, 0) =
        (short)((unsigned short)Level37_788BCField(privateRecord16, short*, 0) +
                Level37_788BCField(globalWords17, int*, 0));
    Level37_788BCField(privateRecord16, short*, 2) =
        (short)((unsigned short)Level37_788BCField(privateRecord16, short*, 2) +
                Level37_788BC_D_8007191C);
    Level37_788BCField(privateRecord16, short*, 4) =
        (short)((unsigned short)Level37_788BCField(privateRecord16, short*, 4) +
                Level37_788BC_D_80071920);
block_13:
    Level37_788BCField(ownerRecord19, int*, 0xC) =
        (int)(Level37_788BCField(ownerRecord19, int*, 0xC) +
              Level37_788BCField(privateRecord16, short*, 0));
    Level37_788BCField(ownerRecord19, int*, 0x10) =
        (int)(Level37_788BCField(ownerRecord19, int*, 0x10) +
              Level37_788BCField(privateRecord16, short*, 2));
    temp_v0_2 = (unsigned short)Level37_788BCField(privateRecord16, short*, 4) - 0xA;
    Level37_788BCField(privateRecord16, short*, 4) = temp_v0_2;
    temp_v0_2 = (short)temp_v0_2;
    if (temp_v0_2 >= -0xC8) {
        goto block_15;
    }
    Level37_788BCField(privateRecord16, short*, 4) = -0xC8;
block_15:
    Level37_788BCField(ownerRecord19, int*, 0x14) =
        (int)(Level37_788BCField(ownerRecord19, int*, 0x14) +
              Level37_788BCField(privateRecord16, short*, 4));
    Level37_788BCField(ownerRecord19, unsigned char*, 0x44) =
        (unsigned char)(Level37_788BCField(ownerRecord19, unsigned char*, 0x44) +
                        Level37_788BCField(privateRecord16, unsigned char*, 6));
    Level37_788BCField(ownerRecord19, unsigned char*, 0x45) =
        (unsigned char)(Level37_788BCField(ownerRecord19, unsigned char*, 0x45) +
                        Level37_788BCField(privateRecord16, unsigned char*, 8));
    Level37_788BCField(ownerRecord19, unsigned char*, 0x46) =
        (unsigned char)(Level37_788BCField(ownerRecord19, unsigned char*, 0x46) +
                        Level37_788BCField(privateRecord16, unsigned char*, 0xA));
    if (Level37_788BCField(privateRecord16, int*, 0xC) & 3) {
        goto block_96;
    }
    originalFrame.sp18 = Level37_788BC_rand() & 3;
    originalFrame.sp1C = Level37_788BC_rand() & 3;
    originalFrame.sp20 = 0x14;
    Level37_788BC_SpawnParticle(1, 0, ownerRecord19 + 0xC, &originalFrame.sp18);
    return;
block_17:
    MATCHING_KEEP(temp_a0);
    if (temp_a0 == 0) {
        goto block_20;
    }
    if (temp_a0 == 1) {
        goto block_23;
    }
    return;
block_20:
    temp_s4 = Level37_788BCField(ownerRecord19, int**, 0);
    Level37_788BCClearVector(&originalFrame.sp28);
    MATCHING_KEEP(temp_s4);
    Level37_788BCCopyVector(&originalFrame.sp38, ownerRecord19 + 0xC);
    originalFrame.sp40 += 0x190;
    Level37_788BC_SpawnParticle(1, 0, &originalFrame.sp38, &originalFrame.sp28);
    if (Level37_788BC_func_80037A60(ownerRecord19, ((unsigned char*)temp_s4 + 2), 2,
                                    -Level37_788BCField(temp_s4, short*, 6), -0xC8) == 0) {
        goto block_22;
    }
    temp_s1 = Level37_788BCField(ownerRecord19, int**, 0);
    temp_s2 = Level37_788BCField(temp_s4, int*, 8);
    temp_s0_2 = Level37_788BCField(temp_s4, short*, 2);
    Level37_788BC_func_8004E790(temp_s1, 0, 0x18);
    Level37_788BCField(temp_s1, short*, 8) = (short)temp_s2;
    Level37_788BCField(temp_s1, short*, 0xE) = (short)(-temp_s0_2 / 3);
    Level37_788BCField(ownerRecord19, unsigned char*, 0x48) = 1U;
    return;
block_22:
    Level37_788BC_func_80035EE0(ownerRecord19, Level37_788BCField(temp_s4, unsigned char*, 4),
                                Level37_788BCField(temp_s4, short*, 0), 0, 0, 0x4001);
    Level37_788BCRefreshMobySpatialGridAndBasis(ownerRecord19, 3);
    return;
block_23:
    activePrivate16 = Level37_788BCField(ownerRecord19, int**, 0);
    temp_s2_2 = (unsigned char)Level37_788BCField(activePrivate16, short*, 4);
    savedHelperResult = Level37_788BCProbeGroundFromRaisedMoby(ownerRecord19);
    helperOwner4 = ownerRecord19;
    helperMode5 = 3;
    MATCHING_KEEP2(helperOwner4, helperMode5);
    temp_s4_2 = savedHelperResult;
    Level37_788BCRefreshMobySpatialGridAndBasis(helperOwner4, helperMode5);
    MATCHING_KEEP2(temp_s4_2, temp_s2_2);
    Level37_788BCField(activePrivate16, unsigned short*, 4) =
        (unsigned short)(Level37_788BCField(activePrivate16, unsigned short*, 4) +
                         (Level37_788BC_D_8006C648 * 6));
    if (Level37_788BCCountTimerDown(((unsigned char*)activePrivate16 + 6), 2) == 0) {
        goto block_38;
    }
    phaseEight2 = 8;
    temp_a0_2 = Level37_788BCField(activePrivate16, short*, 0);
    Level37_788BCField(activePrivate16, short*, 6) = phaseEight2;
    __asm__ __volatile__("" : "=r"(temp_a0_2) : "0"(temp_a0_2), "r"(phaseEight2) : "memory");
    var_v0 = temp_a0_2;
    if (temp_a0_2 >= 0) {
        goto block_26;
    }
    MATCHING_KEEP(var_v0);
    var_v0 = -var_v0;
block_26:
    if (var_v0 > 0) {
        goto block_28;
    }
    Level37_788BCField(activePrivate16, short*, 0) = 0;
    goto block_31;
block_28:
    firstOriginalValue = temp_a0_2;
    MATCHING_KEEP_CLOBBER(firstOriginalValue, "$2");
    var_v0_2 = firstOriginalValue - 1;
    if (temp_a0_2 >= 0) {
        goto block_30;
    }
    var_v0_2 = firstOriginalValue + 1;
block_30:
    Level37_788BCField(activePrivate16, short*, 0) = var_v0_2;
block_31:
    temp_a0_3 = Level37_788BCField(activePrivate16, short*, 2);
    MATCHING_KEEP(temp_a0_3);
    var_v0_3 = temp_a0_3;
    if (temp_a0_3 >= 0) {
        goto block_33;
    }
    MATCHING_KEEP(var_v0_3);
    var_v0_3 = -var_v0_3;
block_33:
    if (var_v0_3 > 0) {
        goto block_35;
    }
    Level37_788BCField(activePrivate16, short*, 2) = 0;
    goto block_38;
block_35:
    secondOriginalValue = temp_a0_3;
    MATCHING_KEEP_CLOBBER(secondOriginalValue, "$2");
    var_v0_4 = secondOriginalValue - 1;
    if (temp_a0_3 >= 0) {
        goto block_37;
    }
    var_v0_4 = secondOriginalValue + 1;
block_37:
    Level37_788BCField(activePrivate16, short*, 2) = var_v0_4;
block_38:
    tableBase17 = (int)&Level37_788BC_D_800658A0;
    MATCHING_KEEP_CLOBBER(tableBase17, "$2");
    tableByteIndex = temp_s2_2 * 2;
    __asm__("" : "=r"(tableByteIndex) : "0"(tableByteIndex) : "$2", "$18");
    tableByteIndex += tableBase17;
    temp_v1 = (short*)tableByteIndex;
    firstCoefficient4 = *temp_v1;
    MATCHING_BARRIER_GNU_VOLATILE("memory");
    packedValue = Level37_788BCField(activePrivate16, short*, 0);
    MATCHING_KEEP(packedValue);
    __asm__("" : "=r"(firstCoefficient4) : "0"(firstCoefficient4), "r"(packedValue));
    rawProduct = firstCoefficient4 * packedValue;
    Level37_788BCField(ownerRecord19, unsigned char*, 0x44) = rawProduct >> 12;
    packedCoefficient = *temp_v1;
    MATCHING_BARRIER_GNU_VOLATILE("memory");
    packedValue = Level37_788BCField(activePrivate16, short*, 2);
    MATCHING_KEEP(packedValue);
    rawProduct = packedCoefficient * packedValue;
    Level37_788BCField(ownerRecord19, unsigned char*, 0x45) = rawProduct >> 12;
    if (!(Level37_788BCField(ownerRecord19, int*, 0x18) & 0x20000)) {
        goto block_40;
    }
    temp_v0_3 =
        Level37_788BCPlanarHeadingLookup(Level37_788BCField(ownerRecord19, int*, 0xC) -
                                             Level37_788BCField(&Level37_788BC_D_80070328, int*, 0),
                                         Level37_788BCField(ownerRecord19, int*, 0x10) -
                                             Level37_788BCField(&Level37_788BC_D_80070328, int*, 4),
                                         0) *
        2;
    lookupWord = *(short*)(&Level37_788BC_D_80065920 + temp_v0_3);
    temp_v0_3 += tableBase17;
    lookupWord <<= 4;
    lookupWord = -lookupWord;
    lookupWord >>= 12;
    Level37_788BCField(activePrivate16, short*, 2) = lookupWord;
    temp_v0_3 = *(short*)temp_v0_3;
    Level37_788BCField(activePrivate16, unsigned short*, 4) = 0;
    temp_v0_3 <<= 4;
    temp_v0_3 = -temp_v0_3;
    temp_v0_3 >>= 12;
    Level37_788BCField(activePrivate16, short*, 0) = temp_v0_3;
block_40:
    Level37_788BCField(ownerRecord19, int*, 0x18) = 0;
    if (Level37_788BCCountTimerDown(((unsigned char*)activePrivate16 + 8), 2) == 0) {
        goto block_71;
    }
    temp_v1_2 = Level37_788BCField(ownerRecord19, unsigned char*, 0x49);
    spawnedRecord17 = 0;
    if (temp_v1_2 == 1) {
        goto block_49;
    }
    if ((int)temp_v1_2 >= 2) {
        goto block_45;
    }
    if (temp_v1_2 == 0) {
        goto block_48;
    }
    goto block_55;
block_45:
    if (temp_v1_2 == 2) {
        goto block_51;
    }
    if (temp_v1_2 == 3) {
        goto block_53;
    }
    goto block_55;
block_48:
    spawnedRecord17 = Level37_788BC_SpawnMoby(0x2B9, ownerRecord19);
    goto block_55;
block_49:
    spawnedRecord17 = Level37_788BC_SpawnMoby(0xC1, ownerRecord19);
    if (spawnedRecord17 == 0) {
        goto block_57;
    }
    temp_s0_4 = *spawnedRecord17;
    Level37_788BCPlayMobySoundEvent(spawnedRecord17, 0, 1);
    Level37_788BCField(temp_s0_4, unsigned char*, 0x16) = 0xFF;
    goto block_55;
block_51:
    spawnedRecord17 = Level37_788BC_SpawnMoby(0x1B7, ownerRecord19);
    if (spawnedRecord17 == 0) {
        goto block_57;
    }
    **spawnedRecord17 = 0x1A4;
    goto block_55;
block_53:
    spawnedRecord17 = Level37_788BC_SpawnMoby(0x10B, ownerRecord19);
    if (spawnedRecord17 == 0) {
        goto block_57;
    }
    derivedWord2 = initialData21 + 0x74;
    __asm__("" : "=r"(derivedWord2) : "0"(derivedWord2), "r"(initialData21));
    Level37_788BCField(spawnedRecord17, int**, 0) = (int*)derivedWord2;
    Level37_788BCField(spawnedRecord17, short*, 0x38) = 0x28A;
    MATCHING_KEEP(initialData21);

block_55:
    if (spawnedRecord17 == 0) {
        goto block_57;
    }
    Level37_788BCField(spawnedRecord17, int*, 0x1C) =
        (int)(Level37_788BCField(spawnedRecord17, int*, 0x1C) | 0x80000000);
    Level37_788BC_func_80037014(spawnedRecord17);
    Level37_788BCField(spawnedRecord17, signed char*, 0x4C) = 0x3F;
    Level37_788BCField(spawnedRecord17, signed char*, 0x4E) = 0x3F;
    Level37_788BCField(spawnedRecord17, signed char*, 0x46) =
        Level37_788BCPlanarHeadingLookup(Level37_788BCField(&Level37_788BC_D_80070328, int*, 0) -
                                             Level37_788BCField(spawnedRecord17, int*, 0xC),
                                         Level37_788BCField(&Level37_788BC_D_80070328, int*, 4) -
                                             Level37_788BCField(spawnedRecord17, int*, 0x10),
                                         0);
    Level37_788BCField(spawnedRecord17, int*, 0x14) =
        (int)(Level37_788BCField(spawnedRecord17, int*, 0x14) +
              (Level37_788BCField(spawnedRecord17, short*, 0x38) -
               Level37_788BCField(ownerRecord19, short*, 0x38)));
block_57:
    spawnIndex17 = 0;
    do {
    loop_58:
        if ((Level37_788BC_D_8006C578 - Level37_788BC_D_8006C574) < 0x15) {
            goto block_69;
        }
        particleRecord16 = Level37_788BC_SpawnMoby(0xB5, ownerRecord19);
        if (particleRecord16 == 0) {
            goto block_68;
        }
        Level37_788BCCopyVector(((unsigned char*)particleRecord16 + 0xC), ownerRecord19 + 0xC);
        Level37_788BCField(particleRecord16, signed char*, 0x48) = Level37_788BCRandBetween(3, 5);
        Level37_788BCField(particleRecord16, signed char*, 0x42) = 0;
        Level37_788BCField(particleRecord16, signed char*, 0x40) =
            (signed char)(-((unsigned char)*Level37_788BCField(
                                ((Level37_788BCRandBetween(3, 5) * 4) +
                                 *(int*)(&Level37_788BC_D_8006EE2C +
                                         (Level37_788BCField(particleRecord16, short*, 0x36) * 4))),
                                unsigned char**, 0x3C) >= 2U) &
                          0x30);
        Level37_788BCField(particleRecord16, signed char*, 0x3C) = Level37_788BCRandBetween(3, 5);
        Level37_788BCField(particleRecord16, signed char*, 0x3D) = Level37_788BCRandBetween(3, 5);
        Level37_788BCField(particleRecord16, signed char*, 0x3F) = 1;
        Level37_788BCField(particleRecord16, signed char*, 0x3E) = 0;
        Level37_788BCField(particleRecord16, signed char*, 0x46) = 0;
        Level37_788BCField(particleRecord16, int*, 8) = 0;
        Level37_788BCField(particleRecord16, signed char*, 0x4C) = 0x3F;
        Level37_788BCField(particleRecord16, signed char*, 0x4E) = 0x3F;
        temp_v1_3 = Level37_788BCField(ownerRecord19, unsigned char*, 0x3D);
        if (temp_v1_3 != 0) {
            goto block_62;
        }
        Level37_788BCField(particleRecord16, int*, 0x14) =
            (int)(Level37_788BCField(particleRecord16, int*, 0x14) +
                  Level37_788BCRandBetween(0x64, 0x2BC));
        Level37_788BCField(particleRecord16, int*, 0xC) =
            (int)(Level37_788BCField(particleRecord16, int*, 0xC) +
                  Level37_788BCRandBetween(-0x190, 0x190));
        var_v0_5 = Level37_788BCRandBetween(-0x190, 0x190);
        finalWord4 = Level37_788BCField(particleRecord16, int*, 0x10);
        MATCHING_KEEP_CLOBBER(finalWord4, "$3");
        MATCHING_OBSERVE_GNU_VOLATILE(finalWord4);
        var_v1 = 0x30;
        goto block_66;
    block_62:
        if (temp_v1_3 != 1) {
            goto block_64;
        }
        Level37_788BCField(particleRecord16, int*, 0x14) =
            (int)(Level37_788BCField(particleRecord16, int*, 0x14) +
                  Level37_788BCRandBetween(0x64, 0x2BC));
        Level37_788BCField(particleRecord16, int*, 0xC) =
            (int)(Level37_788BCField(particleRecord16, int*, 0xC) +
                  Level37_788BCRandBetween(-0x190, 0x190));
        var_v0_5 = Level37_788BCRandBetween(-0x190, 0x190);
        finalWord4 = Level37_788BCField(particleRecord16, int*, 0x10);
        MATCHING_KEEP_CLOBBER(finalWord4, "$3");
        var_v1 = 0x30;
        goto block_66;
    block_64:
        if (temp_v1_3 != 2) {
            goto block_67;
        }
        Level37_788BCField(particleRecord16, int*, 0x14) =
            (int)(Level37_788BCField(particleRecord16, int*, 0x14) +
                  Level37_788BCRandBetween(0x64, 0x44C));
        Level37_788BCField(particleRecord16, int*, 0xC) =
            (int)(Level37_788BCField(particleRecord16, int*, 0xC) +
                  Level37_788BCRandBetween(-0x258, 0x258));
        var_v0_5 = Level37_788BCRandBetween(-0x258, 0x258);
        finalWord4 = Level37_788BCField(particleRecord16, int*, 0x10);
        MATCHING_KEEP_CLOBBER(finalWord4, "$3");
        var_v1 = 0x19;
    block_66:
        Level37_788BCField(particleRecord16, signed char*, 0x4F) = var_v1;
        MATCHING_KEEP_GNU_VOLATILE_CLOBBER(finalWord4, "memory");
        finalWord4 += var_v0_5;
        Level37_788BCField(particleRecord16, int*, 0x10) = finalWord4;
    block_67:
        Level37_788BCField(particleRecord16, signed char*, 0x48) = 3;
    block_68:
        spawnIndex17 += 1;
    } while (spawnIndex17 < 0xC);
block_69:
    Level37_788BCPlayMobySoundEvent(ownerRecord19, 0, 0);
block_70:
    Level37_788BCDeleteMoby(ownerRecord19);
    return;
block_71:
    if (Level37_788BCField(activePrivate16, short*, 8) >= 0xB4) {
        goto block_90;
    }
    if (Level37_788BCCountTimerDown(((unsigned char*)activePrivate16 + 0xA), 2) == 0) {
        goto block_74;
    }
    Level37_788BCField(activePrivate16, unsigned short*, 0xE) =
        Level37_788BCRandBetween(0x3C, 0x5A);
    Level37_788BCField(activePrivate16, short*, 0xA) = Level37_788BCRandBetween(0x28, 0x3C);
block_74:
    if (Level37_788BCCountTimerDown(((unsigned char*)activePrivate16 + 0xC), 2) == 0) {
        goto block_90;
    }
    if ((unsigned int)((Level37_788BCField(ownerRecord19, unsigned char*, 0x44) - 3) & 0xFF) <
        0xFBU) {
        goto block_90;
    }
    if ((unsigned int)((Level37_788BCField(ownerRecord19, unsigned char*, 0x45) - 3) & 0xFF) <
        0xFBU) {
        goto block_90;
    }
    temp_s1_2 = Level37_788BCRandSignedBetween(4, 8);
    temp_a1 = Level37_788BCRandSignedBetween(4, 8);
    MATCHING_KEEP(temp_a1);
    var_v1_2 = Level37_788BCField(activePrivate16, short*, 0);
    temp_a0_4 = Level37_788BCField(activePrivate16, short*, 2);
    if (var_v1_2 >= 0) {
        goto block_79;
    }
    var_v1_2 = -var_v1_2;
block_79:
    MATCHING_BARRIER_GNU_VOLATILE("$2");
    if (var_v1_2 >= temp_a0_4) {
        goto block_82;
    }
    var_v1_2 = temp_a0_4;
    if (temp_a0_4 >= 0) {
        goto block_82;
    }
    var_v1_2 = -var_v1_2;
block_82:
    MATCHING_KEEP(temp_a0_4);
    var_v0_6 = temp_s1_2;
    if (temp_s1_2 >= 0) {
        goto block_84;
    }
    MATCHING_KEEP(var_v0_6);
    var_v0_6 = -var_v0_6;
block_84:
    if (var_v1_2 < var_v0_6) {
        goto block_88;
    }
    var_v0_7 = temp_a1;
    if (temp_a1 >= 0) {
        goto block_87;
    }
    var_v0_7 = -var_v0_7;
block_87:
    if (var_v1_2 >= var_v0_7) {
        goto block_89;
    }
block_88:
    Level37_788BCField(activePrivate16, short*, 0) = temp_s1_2;
    Level37_788BCField(activePrivate16, short*, 2) = temp_a1;
block_89:
    Level37_788BCField(activePrivate16, short*, 0xC) = Level37_788BCRandBetween(0x14, 0x28);
block_90:
    temp_v0_5 = Level37_788BCField(activePrivate16, unsigned short*, 0xE) - 0xA;
    Level37_788BCField(activePrivate16, unsigned short*, 0xE) = temp_v0_5;
    temp_v1_4 = Level37_788BCField(ownerRecord19, int*, 0x14) + (short)temp_v0_5;
    if (temp_v1_4 >= temp_s4_2) {
        goto block_95;
    }
    Level37_788BCField(ownerRecord19, int*, 0x14) = temp_s4_2;
    temp_v1_5 = (short)Level37_788BCField(activePrivate16, unsigned short*, 0xE);
    var_v0_8 = temp_v1_5;
    if (temp_v1_5 >= 0) {
        goto block_93;
    }
    MATCHING_KEEP(var_v0_8);
    var_v0_8 = -var_v0_8;
block_93:
    if (var_v0_8 < 0x29) {
        goto block_96;
    }
    Level37_788BCField(activePrivate16, unsigned short*, 0xE) =
        (unsigned short)((int)-(temp_v1_5 * 5) / 8);
    return;
block_95:
    Level37_788BCField(ownerRecord19, int*, 0x14) = temp_v1_4;
block_96:
    return;
}
#undef Level37_788BCField


/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 8007934C..80079664. Original widths and numeric routes are retained;
 * Rev1 raw193 is route context, not authority for pointer/helper semantics. */
extern unsigned char DecodedScorchPlayer[] __asm__("D_80070328");
extern unsigned char* DecodedScorchModels[] __asm__("D_8006EE2C");
void func_level_37_8007934C(Moby* argument) {
    register Moby* moby __asm__("$16") = argument;
    register unsigned char* tag __asm__("$17") = moby->mobyTag;
    register Moby* child __asm__("$18");
    register unsigned char* childTag __asm__("$19");
    if (moby->state != 1 && (func_800359A4(tag + 22, 1) || moby->damageFlags)) {
        child = SpawnMoby(334, moby);
        MATCHING_KEEP(child);
        if (child) {
            int angle;
            childTag = child->mobyTag;
            if (moby->damageFlags & 0x20000)
                child->state = 1;
            else if (tag[22])
                child->state = 10;
            else
                child->state = 1;
            child->substate = 8;
            *(short*)(childTag + 4) = 160;
            *(short*)(childTag + 2) = 350;
            angle = moby->unkb;
            if (!angle)
                angle = func_800360F8(
                    func_8004E880(moby->position.x - *(int*)DecodedScorchPlayer,
                                  moby->position.y - *(int*)(DecodedScorchPlayer + 4), 0),
                    DecodedScorchPlayer[14], 32, 0);
            childTag[1] = angle;
            *(int*)(childTag + 16) = -1;
            child->position.z += 400;
        }
        func_80038BF8(moby, (EnemyTag*)tag, 8, 1);
        *(short*)(tag + 12) = 1;
        *(short*)(tag + 8) = -1;
        tag[15] = 16;
        tag[14] = 5;
        *(short*)(tag + 10) = 0;
        *(short*)(tag + 6) += 40;
        *(short*)(tag + 4) += 50;
        if (!tag[22])
            *(short*)(tag + 4) = 0;
        tag[22] = 70;
        moby->unknownCollision = 0;
        moby->state = 1;
        moby->position.z += 400;
        {
            register unsigned int count __asm__("$2") =
                **(unsigned char**)(DecodedScorchModels[moby->mobyClass] + 0x40);
            register int multipleFrames __asm__("$2");
            moby->animationState.id = 1;
            moby->animationState.nextId = 1;
            moby->animationState.frame = 0;
            moby->animationState.nextFrame = 1;
            multipleFrames = count >= 2;
            MATCHING_KEEP(multipleFrames);
            moby->animationProgress = -multipleFrames & 48;
        }
    }
    switch (moby->state) {
        case 0:
            func_8003573C(moby, 7, 0, 0);
            *(short*)(tag + 4) += 20;
            if (*(short*)(tag + 4) >= 231)
                *(short*)(tag + 4) = 230;
            if (func_80035DDC(moby, *(short*)(tag + 4), 300, 0, 5)) {
                moby->damageFlags |= 0x20000;
                moby->unkb = moby->angle.yaw + 128;
            }
            if (func_8004F334(&moby->position, (Vector3D*)DecodedScorchPlayer) < 800) {
                moby->damageFlags |= 0x20000;
                moby->unkb = moby->angle.yaw + 128;
            }
            break;
        case 1:
            *(short*)(tag + 10) = 0;
            if (func_80035194(moby, tag) == 256) {
                func_80055D24(moby, 4);
                func_800369B8(moby, 32);
                func_80055B18(moby);
                return;
            }
            break;
    }
    func_80055D24(moby, 4);
}

typedef struct {
    Vector3D velocity;
    int timer;
} DecodedBoundedProjectileTag;
extern void (*DecodedBoundedProjectileBurst)(Vector3D*, int, int, int,
                                             int) __asm__("unk_ovlheader_80074410");
Moby* DecodedBoundedProjectileQuery(Vector3D*, int, int, int, int, Moby*) __asm__("func_8001BA30");
int func_80018368(Vector3D*, Vector3D*);
void func_level_37_80079664(Moby* moby) {
    DecodedBoundedProjectileTag* tag = moby->mobyTag;
    Vector3D previous;
    Moby* target;
    switch (moby->state) {
        case 0:
            if (moby->position.x < 0x800 || moby->position.y < 0x800 || moby->position.z < 0x800)
                goto remove;
            if (func_800359A4(&tag->timer, 4))
                goto remove;
            if (moby->position.x > 0x3D400 || moby->position.y > 0x3D400 ||
                moby->position.z > 0x1E000)
                goto remove;
            if (!moby->substate) {
                func_8003BABC(moby, 0, 0);
                moby->substate = 1;
            }
            func_8004F178(&previous, &moby->position);
            func_8004F194(&moby->position, &moby->position, &tag->velocity);
            if (func_80018368(&previous, &moby->position)) {
                func_8004F178(&moby->position, &previous);
                moby->state = 1;
            } else {
                target = DecodedBoundedProjectileQuery(&moby->position, 0xC8, 0, 0, 0x100000, 0);
                if (target) {
                    moby->state = 1;
                    target->unkb = func_8004E880(tag->velocity.x, tag->velocity.y, 0);
                    if (!target->unkb)
                        target->unkb = 1;
                }
            }
            func_80055D24(moby, 2);
            break;
        case 1:
            DecodedBoundedProjectileBurst(&moby->position, 0xD, 0xC, 0x19, 0x23);
        remove:
            func_80055B18(moby);
            break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80079844.
 * AI generated; not human reviewed. Acceptance requires1103 native instructions,
 * every actual transfer/data target,41 original selectors+1 zero pad and every
 * original EXE/overlay hash. Original assembly SHA256 is recorded below.
 * Frame70 (112 bytes) saves S0..S7/FP/RA at48..6C. Explicit storage18..47
 * preserves the original initialized vectors,frame values and their consumers.
 * The ordinary retainedDistance variable allocates naturally to FP;there is no
 * fixedFP/SP binding or incoming saved-register input. Fixed GP roles never
 * overlap live aliases;their different phases have explicit original producers.
 * The adjusted count retains full32-bit arithmetic after the original LBU:
 * base1,selector2 gives0; base255,selector0 gives260. A byte cast here would
 * change retail behavior. The animation comparison reads LHU3C for0707;
 * the raw decoder's LBU3C could never satisfy that original comparison.
 * Seven variable MULT sites form complete signed64 products from signed32
 * operands. Every low capture consumes the whole initialized product,then
 * narrows low32 before the original signed shift. Guarded variable DIV and
 * its original trap paths remain. Vector differences initialize all local
 * components before length/copy helpers and later arithmetic consume them.
 * Shared state40,substate increment,animation and private-state entries retain
 * their distinct original forward targets. Single common count/difficulty
 * comparisons allow original delay-slot copies without duplicate C predicates.
 * The signed75/2048 vector tail and signed3/2 correction retain32-bit domains.
 * Falsifiable vectors:low32(32767*32767)>>12=262128;
 * signed3/2(-5)=-7; signed3/2(5)=7; -32768*75>>11=-1200.
 * Known helper views come from existing headers and matched executable sources.
 * Empty metadata observes only complete initialized values or clobbers dead
 * GP roles before fresh original producers;it emits zero CPU instructions.
 * There is no opcode template,partial HILO,padding read or pipeline change.
 * Confirmed after all gates:binary identity. Full allocation/caller/helper
 * chains,physical units,fixed-point domains,cadence beyond invocation,Rev1
 * mapping and synchronized retail runtime remain unresolved. Next:human
 * review and synchronized retail captures. Engine/browser unchanged.
 */
/* Original assembly SHA256 91e1508fddb67100c52c6d213e07479b9c0ef7a137c6fbd2703eb4f7fddfaf79 */
#define Level37_79844MultiplyComplete(a, b)                                \
    do {                                                                   \
        completeSignedProduct = (long long)(int)(a) * (long long)(int)(b); \
        __asm__ volatile("" ::"x"(completeSignedProduct));                 \
    } while (0)
#define Level37_79844CaptureLow(v)                                 \
    do {                                                           \
        int wholeLow;                                              \
        __asm__("" : "=l"(wholeLow) : "x"(completeSignedProduct)); \
        v = wholeLow;                                              \
        Level37_79844Keep(v);                                      \
    } while (0)
#define Level37_79844Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level37_79844Keep(v) __asm__("" : "=r"(v) : "0"(v))
void Level37_79844Call13ACCView1(void*, int) __asm__("func_80013ACC");
void Level37_79844RequestMobyAnimationView1(void*, int) __asm__("func_80034F40");
int Level37_79844Call35194View1(void*, void*) __asm__("func_80035194");
void Level37_79844EmptyAnimationTransitionHookView1(void*) __asm__("func_80035734");
int Level37_79844TurnMobyTowardPlayerView1(void*, int, int, int) __asm__("func_8003573C");
int Level37_79844TurnMobyTowardHeadingView1(void*, int, int, int, int,
                                            int) __asm__("func_8003585C");
int Level37_79844CountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level37_79844Call35DDCView1(void*, int, int, int, int) __asm__("func_80035DDC");
int Level37_79844Call35EE0View1(void*, int, int, int, int, int) __asm__("func_80035EE0");
int Level37_79844SubAngle8View1(int, int) __asm__("func_8003613C");
void Level37_79844Call369B8View1(void*, int) __asm__("func_800369B8");
int Level37_79844Call37A60View1(void*, void*, int, int, int) __asm__("func_80037A60");
void Level37_79844Call38BF8View1(void*, void*, int, int) __asm__("func_80038BF8");
int Level37_79844PlayMobySoundEventView1(void*, int, int) __asm__("func_8003BABC");
void Level37_79844Call3BE70View1(int) __asm__("func_8003BE70");
int Level37_79844Call3BFC0View1(void*, int) __asm__("func_8003BFC0");
int Level37_79844PlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level37_79844MeasureVectorLengthView1(void*, int) __asm__("func_8004EDE8");
void Level37_79844CopyVectorView1(void*, void*) __asm__("func_8004F178");
void Level37_79844SubtractVectorView1(void*, void*, void*) __asm__("func_8004F1C8");
int Level37_79844AbsoluteByteAngleDeltaView1(int, int) __asm__("func_8004F264");
int Level37_79844ApproximatePlanarDistanceView1(void*, void*) __asm__("func_8004F334");
void Level37_79844DeleteMobyView1(void*) __asm__("func_80055B18");
void Level37_79844RefreshMobySpatialGridAndBasisView1(void*, int) __asm__("func_80055D24");
int Level37_79844Call55E84View1() __asm__("func_80055E84");
extern int Level37_79844Data658A0View1 __asm__("D_800658A0");
extern int Level37_79844Data65920View1 __asm__("D_80065920");
extern unsigned char Level37_79844Data6C40AView1 __asm__("D_8006C40A");
extern int Level37_79844Data6C550View1 __asm__("D_8006C550");
extern int Level37_79844Data6C770View1 __asm__("D_8006C770");
extern int Level37_79844Data6C7C4View1 __asm__("D_8006C7C4");
extern int Level37_79844Data6E020View1 __asm__("D_8006E020");
extern int Level37_79844Data6E024View1 __asm__("D_8006E024");
extern unsigned short Level37_79844Data6E040View1 __asm__("D_8006E040");
extern int Level37_79844Data6E160View1 __asm__("D_8006E160");
extern int Level37_79844Data6E164View1 __asm__("D_8006E164");
extern int Level37_79844Data6EE2CView1 __asm__("D_8006EE2C");
extern int Level37_79844Data70328View1 __asm__("D_80070328");
extern unsigned char Level37_79844Data7158EView1 __asm__("D_8007158E");
void func_level_37_80079844(void* ownerParameter) {
    register int predicateOrValue16 __asm__("$16");
    register int owner17 __asm__("$17");
    register int privateRecord18 __asm__("$18");
    register int sharedAddress19 __asm__("$19");
    register int scanFinished20 __asm__("$20");
    register int relatedOwner21 __asm__("$21");
    register int retainedDistance22 __asm__("$22");
    register int adjustedCount23 __asm__("$23");
    register int resultOrField2 __asm__("$2"), fieldOrIntermediate3 __asm__("$3"),
        argumentOrField4 __asm__("$4"), argumentOrField5 __asm__("$5"),
        argumentOrField6 __asm__("$6"), argumentOrField7 __asm__("$7"),
        capturedLowOrFrameValue8 __asm__("$8"), scratch9 __asm__("$9");
    long long completeSignedProduct;
    struct {
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44;
    } originalFrame;
    short temp_a2;
    short temp_v0_5;
    short temp_v0_6;
    short temp_v0_8;
    int temp_v0_4;
    int temp_v0_7;
    int retainedDistance;
    int var_v0_4;
    unsigned short temp_v1_3;
    unsigned int temp_v0_3;
    unsigned char temp_v0;
    unsigned char temp_v1;
    unsigned char temp_v1_2;
    unsigned char temp_v1_4;
    unsigned char temp_v1_5;
    unsigned char temp_v1_6;
    unsigned char var_v0_5;
    owner17 = (int)ownerParameter;
    Level37_79844Keep(owner17);
    adjustedCount23 = Level37_79844Data6C40AView1;
    fieldOrIntermediate3 = 2;
    originalFrame.sp38 = 0;
    privateRecord18 = Level37_79844Field(owner17, int*, 0);
    __asm__ volatile("" ::: "$2", "$4", "memory");
    resultOrField2 = Level37_79844Data6C550View1;
    argumentOrField4 = Level37_79844Data6C7C4View1;
    relatedOwner21 = Level37_79844Field(resultOrField2, int*, 0);
    if (argumentOrField4 == fieldOrIntermediate3) {
        adjustedCount23 -= 4;
        if (adjustedCount23 < 0)
            adjustedCount23 = 0;
    } else {
        resultOrField2 = 1;
        if (argumentOrField4 == resultOrField2)
            adjustedCount23 += 2;
        else if (argumentOrField4 == 0)
            adjustedCount23 += 5;
    }
    resultOrField2 = Level37_79844Data7158EView1;
    __asm__ volatile("" ::: "$4", "memory");
    argumentOrField4 = (int)&originalFrame.sp18;
    if (resultOrField2)
        adjustedCount23 = 0;
    sharedAddress19 = (int)&Level37_79844Data70328View1;
    Level37_79844Keep(sharedAddress19);
    argumentOrField5 = sharedAddress19;
    predicateOrValue16 = owner17 + 12;
    Level37_79844SubtractVectorView1(argumentOrField4, argumentOrField5, predicateOrValue16);
    resultOrField2 = Level37_79844MeasureVectorLengthView1(&originalFrame.sp18, 0);
    fieldOrIntermediate3 = Level37_79844Field(relatedOwner21, int*, 56);
    argumentOrField4 = (int)&originalFrame.sp18;
    argumentOrField6 = Level37_79844Field(fieldOrIntermediate3, int*, 12);
    __asm__ volatile("" ::: "$5", "memory");
    argumentOrField5 = sharedAddress19;
    Level37_79844SubtractVectorView1(argumentOrField4, argumentOrField5,
                                     (originalFrame.sp40 = resultOrField2, argumentOrField6));
    retainedDistance = Level37_79844MeasureVectorLengthView1(&originalFrame.sp18, 0);
    Level37_79844SubtractVectorView1(
        &originalFrame.sp18, predicateOrValue16,
        Level37_79844Field(Level37_79844Field(relatedOwner21, int*, 0x38), int*, 0xC));
    retainedDistance22 = Level37_79844MeasureVectorLengthView1(&originalFrame.sp18, 0);
    if ((Level37_79844Field(owner17, int*, 0x18) & 0x120000) &&
        (Level37_79844AbsoluteByteAngleDeltaView1(
             Level37_79844Field((int)&Level37_79844Data70328View1, unsigned char*, 0xE),
             Level37_79844PlanarHeadingLookupView1(Level37_79844Field(owner17, int*, 0xC) -
                                                       Level37_79844Field(sharedAddress19, int*, 0),
                                                   Level37_79844Field(owner17, int*, 0x10) -
                                                       Level37_79844Field(sharedAddress19, int*, 4),
                                                   0)) < 0x3A)) {
        fieldOrIntermediate3 = Level37_79844Field(owner17, unsigned char*, 72);
        if ((unsigned int)(fieldOrIntermediate3 - 8) >= 2U) {
            argumentOrField4 = owner17;
            MATCHING_KEEP_CLOBBER(argumentOrField4, "memory");
            resultOrField2 = fieldOrIntermediate3 ^ 1;
            Level37_79844Keep(resultOrField2);
            Level37_79844Field(owner17, signed char*, 81) = 0;
            predicateOrValue16 = (unsigned int)resultOrField2 < 1;
            if (Level37_79844Call3BFC0View1(argumentOrField4,
                                            Level37_79844Field(privateRecord18, int*, 0x40)) != 0) {
                Level37_79844Call3BE70View1(Level37_79844Field(privateRecord18, int*, 0x40));
            }
            Level37_79844Field(privateRecord18, int*, 0x40) = -1;
            Level37_79844Call38BF8View1(owner17, privateRecord18, 0, 8);
            resultOrField2 = Level37_79844Field(owner17, short*, 54);
            __asm__ volatile("" ::: "$3", "memory");
            fieldOrIntermediate3 = 8;
            Level37_79844Keep(fieldOrIntermediate3);
            Level37_79844Field(owner17, unsigned char*, 72) = fieldOrIntermediate3;
            resultOrField2 *= 4;
            resultOrField2 =
                Level37_79844Field((int)&Level37_79844Data6EE2CView1 + resultOrField2, int*, 0);
            resultOrField2 = Level37_79844Field(resultOrField2, int*, 92);
            resultOrField2 = Level37_79844Field(resultOrField2, unsigned char*, 0);
            Level37_79844Field(owner17, unsigned char*, 60) = fieldOrIntermediate3;
            Level37_79844Field(owner17, unsigned char*, 61) = fieldOrIntermediate3;
            fieldOrIntermediate3 = 1;
            Level37_79844Field(owner17, unsigned char*, 62) = 0;
            Level37_79844Field(owner17, unsigned char*, 63) = fieldOrIntermediate3;
            resultOrField2 = -(resultOrField2 >= 2U) & 48;
            Level37_79844Field(owner17, signed char*, 64) = resultOrField2;
            Level37_79844Field(privateRecord18, unsigned short*, 4) = 0x190U;
            if (Level37_79844Field(owner17, int*, 24) & 0x100000)
                goto originalCountCompare;
            if (!predicateOrValue16)
                goto originalCountCompare;
            resultOrField2 = Level37_79844Field(privateRecord18, short*, 28);
            if (resultOrField2 < 251)
                goto originalCountCompare;
            resultOrField2 = Level37_79844AbsoluteByteAngleDeltaView1(
                Level37_79844Field(owner17, unsigned char*, 70),
                Level37_79844PlanarHeadingLookupView1(Level37_79844Field(sharedAddress19, int*, 0) -
                                                          Level37_79844Field(owner17, int*, 12),
                                                      Level37_79844Field(sharedAddress19, int*, 4) -
                                                          Level37_79844Field(owner17, int*, 16),
                                                      0));
            if (resultOrField2 >= 24)
                goto originalCountCompare;
            fieldOrIntermediate3 = Level37_79844Field(privateRecord18, unsigned short*, 4);
            __asm__ volatile("" ::: "$8", "memory");
            capturedLowOrFrameValue8 = 1;
            originalFrame.sp38 = capturedLowOrFrameValue8;
            fieldOrIntermediate3 = (unsigned int)fieldOrIntermediate3 << 16;
            resultOrField2 = fieldOrIntermediate3 >> 16;
            fieldOrIntermediate3 = (unsigned int)fieldOrIntermediate3 >> 31;
            resultOrField2 += fieldOrIntermediate3;
            resultOrField2 >>= 1;
            Level37_79844Field(privateRecord18, short*, 4) = resultOrField2;
        originalCountCompare:
            resultOrField2 = adjustedCount23 < 6;
            Level37_79844Field(owner17, int*, 0x18) = 0;
            if (resultOrField2 == 0) {
                fieldOrIntermediate3 = adjustedCount23 - 5;
                Level37_79844Keep(fieldOrIntermediate3);
                resultOrField2 = fieldOrIntermediate3 < 6;
                if (resultOrField2) {
                    resultOrField2 = fieldOrIntermediate3 * 4;
                } else {
                    fieldOrIntermediate3 = 5;
                    Level37_79844Keep(fieldOrIntermediate3);
                    resultOrField2 = fieldOrIntermediate3 * 4;
                }
                resultOrField2 = (resultOrField2 + fieldOrIntermediate3) * 4;
                fieldOrIntermediate3 = Level37_79844Field(privateRecord18, short*, 4);
                resultOrField2 += 256;
                Level37_79844MultiplyComplete(fieldOrIntermediate3, resultOrField2);
                Level37_79844CaptureLow(capturedLowOrFrameValue8);
                resultOrField2 = capturedLowOrFrameValue8 >> 8;
                Level37_79844Field(privateRecord18, short*, 4) = resultOrField2;
            }
            scanFinished20 = 0;
            sharedAddress19 = (int)&originalFrame.sp28;
            Level37_79844Keep(sharedAddress19);
            do {
                predicateOrValue16 = Level37_79844Field(privateRecord18, short*, 4);
                resultOrField2 = Level37_79844Field(privateRecord18, unsigned char*, 14);
                argumentOrField4 = predicateOrValue16 / resultOrField2;
                Level37_79844Keep(argumentOrField4);
                Level37_79844MultiplyComplete(resultOrField2, resultOrField2);
                Level37_79844CaptureLow(fieldOrIntermediate3);
                predicateOrValue16 -= fieldOrIntermediate3;
                Level37_79844MultiplyComplete(predicateOrValue16, argumentOrField4);
                argumentOrField5 = owner17 + 12;
                Level37_79844CaptureLow(predicateOrValue16);
                Level37_79844CopyVectorView1(sharedAddress19, argumentOrField5);
                resultOrField2 = Level37_79844Field(privateRecord18, unsigned char*, 17);
                resultOrField2 *= 2;
                resultOrField2 = Level37_79844Field(
                    (int)&Level37_79844Data65920View1 + resultOrField2, short*, 0);
                Level37_79844MultiplyComplete(resultOrField2, predicateOrValue16);
                resultOrField2 = originalFrame.sp28;
                Level37_79844CaptureLow(fieldOrIntermediate3);
                fieldOrIntermediate3 >>= 12;
                resultOrField2 += fieldOrIntermediate3;
                originalFrame.sp28 = resultOrField2;
                resultOrField2 = Level37_79844Field(privateRecord18, unsigned char*, 17);
                resultOrField2 *= 2;
                resultOrField2 = Level37_79844Field(
                    (int)&Level37_79844Data658A0View1 + resultOrField2, short*, 0);
                Level37_79844MultiplyComplete(resultOrField2, predicateOrValue16);
                resultOrField2 = originalFrame.sp2C;
                Level37_79844CaptureLow(fieldOrIntermediate3);
                fieldOrIntermediate3 >>= 12;
                resultOrField2 += fieldOrIntermediate3;
                originalFrame.sp2C = resultOrField2;
                if ((unsigned int)(0x5164 - Level37_79844ApproximatePlanarDistanceView1(
                                                sharedAddress19,
                                                Level37_79844Field(
                                                    Level37_79844Field(relatedOwner21, int*, 0x38),
                                                    int*, 0xC))) >= 0x1F41U) {
                    scanFinished20 = 1;
                } else {
                    Level37_79844Field(privateRecord18, unsigned short*, 4) =
                        (unsigned short)(Level37_79844Field(privateRecord18, unsigned short*, 4) +
                                         0x1E);
                }
            } while (scanFinished20 == 0);
        }
    }
    __asm__ volatile("" ::: "$2", "$3", "memory");
    temp_v1_2 = Level37_79844Field(owner17, unsigned char*, 0x48);
    switch (temp_v1_2) {
        case 2:
            Level37_79844TurnMobyTowardPlayerView1(owner17, 5, 0, 0);
            if (Level37_79844Data6C770View1 != 0) {
                Level37_79844Field(owner17, unsigned char*, 0x49) = 0U;
                Level37_79844Field(owner17, unsigned char*, 0x48) = 0U;
                Level37_79844RequestMobyAnimationView1(owner17, 0);
            }
            goto applySharedPrivateState;
        case 0:
            if (Level37_79844Data6E160View1 != 9) {
                Level37_79844Call13ACCView1(owner17, 0xD);
            }
            Level37_79844TurnMobyTowardPlayerView1(owner17, 4, 0, 0);
            if ((Level37_79844CountTimerDownView1(privateRecord18 + 0x1E, 2) != 0) &&
                (retainedDistance < 0x3800) &&
                (Level37_79844AbsoluteByteAngleDeltaView1(
                     (int)(Level37_79844Data6E040View1 << 0x10) >> 0x14,
                     Level37_79844PlanarHeadingLookupView1(
                         Level37_79844Field(owner17, int*, 0xC) - Level37_79844Data6E020View1,
                         Level37_79844Field(owner17, int*, 0x10) - Level37_79844Data6E024View1,
                         0)) < 0x10) &&
                (Level37_79844AbsoluteByteAngleDeltaView1(
                     Level37_79844Field(owner17, unsigned char*, 0x46),
                     Level37_79844PlanarHeadingLookupView1(
                         Level37_79844Field((int)&Level37_79844Data70328View1, int*, 0) -
                             Level37_79844Field(owner17, int*, 0xC),
                         Level37_79844Field((int)&Level37_79844Data70328View1, int*, 4) -
                             Level37_79844Field(owner17, int*, 0x10),
                         0)) < 8)) {
                Level37_79844Field(privateRecord18, short*, 0x1E) = 0x14;
                Level37_79844Field(privateRecord18, short*, 0x1C) = 0x96;
                Level37_79844Field(owner17, unsigned char*, 0x48) = 1U;
            }
            if ((Level37_79844Field((int)&Level37_79844Data70328View1, int*, 72) == 28) ||
                (Level37_79844Field((int)&Level37_79844Data70328View1, int*, 72) == 58) ||
                (retainedDistance >= 0x392D)) {
                capturedLowOrFrameValue8 = originalFrame.sp40;
                resultOrField2 = capturedLowOrFrameValue8 < 0x2800;
                if (resultOrField2 == 0)
                    goto applySharedPrivateState;
                argumentOrField6 = 0;
                MATCHING_OBSERVE_VOLATILE(argumentOrField6);
                goto enterSharedState40;
            }
            goto applySharedPrivateState;
        case 40:
            predicateOrValue16 = Level37_79844Field(owner17, unsigned char*, 0x49);
            switch (predicateOrValue16) {
                case 0:
                    argumentOrField4 = owner17;
                    __asm__ volatile("" ::"r"(argumentOrField4) : "$16", "memory");
                    argumentOrField6 = 0;
                    Level37_79844TurnMobyTowardPlayerView1(argumentOrField4, 5, argumentOrField6,
                                                           0);
                    var_v0_4 = Level37_79844Data6C770View1;
                    goto advanceSharedSubstate;
                case 1:
                    Level37_79844CopyVectorView1(
                        &originalFrame.sp28,
                        Level37_79844Field(Level37_79844Field(relatedOwner21, int*, 0x38), int*,
                                           0xC));
                    originalFrame.sp28 +=
                        (int)(Level37_79844Field(
                                  (int)&Level37_79844Data65920View1 +
                                      (Level37_79844Field(privateRecord18, short*, 0x34) * 2),
                                  short*, 0) *
                              0x84D) >>
                        0xA;
                    originalFrame.sp2C +=
                        (int)(Level37_79844Field(
                                  (int)&Level37_79844Data658A0View1 +
                                      (Level37_79844Field(privateRecord18, short*, 0x34) * 2),
                                  short*, 0) *
                              0x84D) >>
                        0xA;
                    if (Level37_79844Field(owner17, unsigned char*, 0x3D) != predicateOrValue16) {
                        Level37_79844Data6C770View1 = 0;
                        Level37_79844Field(owner17, signed char*, 0x40) = 0x72;
                        Level37_79844Field(owner17, unsigned char*, 0x3D) = 1U;
                        Level37_79844Field(owner17, signed char*, 0x3F) = 0;
                        Level37_79844EmptyAnimationTransitionHookView1(owner17);
                    }
                    if (Level37_79844TurnMobyTowardHeadingView1(
                            owner17,
                            Level37_79844PlanarHeadingLookupView1(
                                originalFrame.sp28 - Level37_79844Field(owner17, int*, 0xC),
                                originalFrame.sp2C - Level37_79844Field(owner17, int*, 0x10), 0),
                            7, 0x1E, (int)predicateOrValue16, 0) != 0) {
                        temp_v0_5 =
                            (unsigned short)Level37_79844Field(privateRecord18, short*, 0x1C) +
                            0x1E;
                        Level37_79844Field(privateRecord18, short*, 0x1C) = temp_v0_5;
                        if (temp_v0_5 >= 0x12D) {
                            Level37_79844Field(privateRecord18, short*, 0x1C) = 0x12C;
                        }
                        Level37_79844Call35DDCView1(
                            owner17, Level37_79844Field(privateRecord18, short*, 0x1C), 0, 0, 5);
                    }
                    var_v0_4 = Level37_79844ApproximatePlanarDistanceView1(
                                   owner17 + 12, &originalFrame.sp28) < 0x400;
                advanceSharedSubstate:
                    if (var_v0_4 != 0) {
                        Level37_79844Field(owner17, unsigned char*, 0x49) =
                            (unsigned char)(Level37_79844Field(owner17, unsigned char*, 0x49) + 1);
                    }
                    break;
                case 2:
                    if (Level37_79844TurnMobyTowardPlayerView1(owner17, 5, 0xA, 1) != 0) {
                        Level37_79844Field(owner17, unsigned char*, 0x48) = 0U;
                        Level37_79844RequestMobyAnimationView1(owner17, 0);
                    }
                    break;
            }
            goto applySharedPrivateState;
        case 1:
            Level37_79844TurnMobyTowardPlayerView1(owner17, 1, 0, 0);
            temp_v0_6 = (unsigned short)Level37_79844Field(privateRecord18, short*, 0x1C) + 0x32;
            Level37_79844Field(privateRecord18, short*, 0x1C) = temp_v0_6;
            if (temp_v0_6 >= 0x15F) {
                Level37_79844Field(privateRecord18, short*, 0x1C) = 0x15E;
            }
            Level37_79844Call35DDCView1(owner17, Level37_79844Field(privateRecord18, short*, 0x1C),
                                        0, 0, 5);
            if ((capturedLowOrFrameValue8 = originalFrame.sp40,
                 resultOrField2 = capturedLowOrFrameValue8 < 0xDAC, resultOrField2)) {
                if (Level37_79844AbsoluteByteAngleDeltaView1(
                        Level37_79844Field(owner17, unsigned char*, 0x46),
                        Level37_79844PlanarHeadingLookupView1(
                            Level37_79844Field((int)&Level37_79844Data70328View1, int*, 0) -
                                Level37_79844Field(owner17, int*, 0xC),
                            Level37_79844Field((int)&Level37_79844Data70328View1, int*, 4) -
                                Level37_79844Field(owner17, int*, 0x10),
                            0)) < 0x20) {
                    temp_v1_4 = Level37_79844Field(owner17, unsigned char*, 0x3C);
                    if ((temp_v1_4 == Level37_79844Field(owner17, unsigned char*, 0x3D)) &&
                        (temp_v1_4 != 7)) {
                        Level37_79844Data6C770View1 = 0;
                        Level37_79844Field(owner17, signed char*, 0x40) = 0x72;
                        Level37_79844Field(owner17, unsigned char*, 0x3D) = 7U;
                        Level37_79844Field(owner17, signed char*, 0x3F) = 0;
                        Level37_79844EmptyAnimationTransitionHookView1(owner17);
                    }
                }
            }
            if (Level37_79844AbsoluteByteAngleDeltaView1(
                    Level37_79844Field(owner17, unsigned char*, 0x46),
                    Level37_79844PlanarHeadingLookupView1(
                        Level37_79844Field((int)&Level37_79844Data70328View1, int*, 0) -
                            Level37_79844Field(owner17, int*, 0xC),
                        Level37_79844Field((int)&Level37_79844Data70328View1, int*, 4) -
                            Level37_79844Field(owner17, int*, 0x10),
                        0)) >= 0x33) {
                Level37_79844Field(privateRecord18, short*, 0x1E) = 0x50;
                Level37_79844Field(owner17, unsigned char*, 0x48) = 0U;
                Level37_79844RequestMobyAnimationView1(owner17, 0);
                return;
            }
            if (retainedDistance >= 0x392D) {
                temp_v0_7 =
                    Level37_79844Field(Level37_79844Field(relatedOwner21, int*, 0x38), int*, 0xC);
                Level37_79844Field(privateRecord18, short*, 0x34) =
                    Level37_79844PlanarHeadingLookupView1(
                        Level37_79844Field(temp_v0_7, int*, 0) -
                            Level37_79844Field((int)&Level37_79844Data70328View1, int*, 0),
                        Level37_79844Field(temp_v0_7, int*, 4) -
                            Level37_79844Field((int)&Level37_79844Data70328View1, int*, 4),
                        0);
                Level37_79844Field(privateRecord18, short*, 0x1C) = 0x28;
                Level37_79844Field(owner17, unsigned char*, 0x49) = 0U;
                if (Level37_79844Field(owner17, unsigned char*, 0x3D) != 6) {
                    Level37_79844Data6C770View1 = 0;
                    Level37_79844Field(owner17, signed char*, 0x40) = 0x72;
                    Level37_79844Field(owner17, unsigned char*, 0x3D) = 6U;
                    Level37_79844Field(owner17, signed char*, 0x3F) = 0;
                    Level37_79844EmptyAnimationTransitionHookView1(owner17);
                }
                Level37_79844Field(owner17, unsigned char*, 0x48) = 0x28U;
            }
            if (Level37_79844Field(owner17, unsigned short*, 0x3C) == 0x707) {
                Level37_79844TurnMobyTowardPlayerView1(owner17, 4, 0, 0);
                if (((capturedLowOrFrameValue8 = originalFrame.sp40,
                      resultOrField2 = capturedLowOrFrameValue8 < 0x7D0, resultOrField2)) &&
                    ((Level37_79844Field((int)&Level37_79844Data70328View1, int*, 0x50) != 4) ||
                     (Level37_79844AbsoluteByteAngleDeltaView1(
                          Level37_79844Field((int)&Level37_79844Data70328View1, unsigned char*,
                                             0xE),
                          Level37_79844PlanarHeadingLookupView1(
                              Level37_79844Field(owner17, int*, 0xC) -
                                  Level37_79844Field((int)&Level37_79844Data70328View1, int*, 0),
                              Level37_79844Field(owner17, int*, 0x10) -
                                  Level37_79844Field((int)&Level37_79844Data70328View1, int*, 4),
                              0)) >= 0x20)) &&
                    (Level37_79844Call55E84View1(owner17) >= 6)) {
                    if ((Level37_79844AbsoluteByteAngleDeltaView1(
                             Level37_79844Field((int)&Level37_79844Data70328View1, unsigned char*,
                                                0xE),
                             Level37_79844PlanarHeadingLookupView1(
                                 Level37_79844Field(owner17, int*, 0xC) -
                                     Level37_79844Field((int)&Level37_79844Data70328View1, int*, 0),
                                 Level37_79844Field(owner17, int*, 0x10) -
                                     Level37_79844Field((int)&Level37_79844Data70328View1, int*, 4),
                                 0)) < 0x51) ||
                        (Level37_79844Field((int)&Level37_79844Data70328View1, int*, 0x50) != 4)) {
                        capturedLowOrFrameValue8 = 2;
                        originalFrame.sp38 = capturedLowOrFrameValue8;
                    }
                    Level37_79844Field(privateRecord18, short*, 0x1E) = 0x5A;
                    Level37_79844Field(owner17, unsigned char*, 0x48) = 7U;
                    Level37_79844RequestMobyAnimationView1(owner17, 7);
                }
            }
            temp_v1_5 = Level37_79844Field(owner17, unsigned char*, 0x3D);
            if ((temp_v1_5 != 7) && (temp_v1_5 != 1)) {
                Level37_79844Data6C770View1 = 0;
                Level37_79844Field(owner17, signed char*, 0x40) = 0x72;
                Level37_79844Field(owner17, unsigned char*, 0x3D) = 1U;
                Level37_79844Field(owner17, signed char*, 0x3F) = 0;
                Level37_79844EmptyAnimationTransitionHookView1(owner17);
            }
            goto applySharedPrivateState;
        case 7:
            Level37_79844TurnMobyTowardPlayerView1(owner17, 5, 0, 0);
            if (Level37_79844Data6C770View1 != 0) {
                Level37_79844Field(owner17, unsigned char*, 0x48) = 0U;
                Level37_79844RequestMobyAnimationView1(owner17, 0);
            }
            argumentOrField6 = 0;
            if (retainedDistance < 0x392D)
                goto applySharedPrivateState;
        enterSharedState40:
            temp_v0_4 =
                Level37_79844Field(Level37_79844Field(relatedOwner21, int*, 0x38), int*, 0xC);
            Level37_79844Field(privateRecord18, short*, 0x34) =
                Level37_79844PlanarHeadingLookupView1(
                    Level37_79844Field(temp_v0_4, int*, 0) -
                        Level37_79844Field((int)&Level37_79844Data70328View1, int*, 0),
                    Level37_79844Field(temp_v0_4, int*, 4) -
                        Level37_79844Field((int)&Level37_79844Data70328View1, int*, 4),
                    argumentOrField6);
            Level37_79844Field(privateRecord18, short*, 0x1C) = 0x28;
            Level37_79844Field(owner17, unsigned char*, 0x49) = 0U;
            if (Level37_79844Field(owner17, unsigned char*, 0x3D) != 6) {
                Level37_79844Data6C770View1 = 0;
                Level37_79844Field(owner17, signed char*, 0x40) = 0x72;
                Level37_79844Field(owner17, unsigned char*, 0x3D) = 6U;
                Level37_79844Field(owner17, signed char*, 0x3F) = 0;
                Level37_79844EmptyAnimationTransitionHookView1(owner17);
            }
            Level37_79844Field(owner17, unsigned char*, 0x48) = 0x28U;
            goto applySharedPrivateState;
        case 8:
            if (retainedDistance22 >= 0x5359) {
                Level37_79844Field(privateRecord18, unsigned short*, 4) = 0U;
            }
            if (((unsigned int)(retainedDistance22 - 0x3419) < 0xF9FU) &&
                ((short)Level37_79844Field(privateRecord18, unsigned short*, 4) < 0x78)) {
                Level37_79844Field(privateRecord18, unsigned short*, 4) = 0x78U;
            }
            if (Level37_79844Call35194View1(owner17, privateRecord18) == 0x100) {
                if ((resultOrField2 = retainedDistance22 < 0x3801, resultOrField2 == 0)) {
                    Level37_79844PlayMobySoundEventView1(owner17, 0, 0);
                    Level37_79844Field(owner17, unsigned char*, 0x49) = 0U;
                    Level37_79844Field(owner17, unsigned char*, 0x48) = 9U;
                    Level37_79844RequestMobyAnimationView1(owner17, 9);
                } else {
                    Level37_79844Field(owner17, unsigned char*, 0x48) = 0x14U;
                }
            }
            goto applySharedPrivateState;
        case 20:
            Level37_79844Field(owner17, unsigned char*, 0x49) = 0U;
            Level37_79844Field(owner17, unsigned char*, 0x48) = 0x15U;
        case 21:
            resultOrField2 = Level37_79844Call55E84View1(owner17);
            argumentOrField4 = owner17;
            argumentOrField5 = 7;
            argumentOrField6 = 0;
            argumentOrField7 = 0;
            MATCHING_OBSERVE4_VOLATILE(argumentOrField4, argumentOrField5, argumentOrField6,
                                       argumentOrField7);
            Level37_79844TurnMobyTowardPlayerView1(
                argumentOrField4, argumentOrField5, argumentOrField6,
                (predicateOrValue16 = resultOrField2, argumentOrField7));
            temp_v1_6 = Level37_79844Field(owner17, unsigned char*, 0x49);
            switch (temp_v1_6) {
                case 0:
                    argumentOrField6 = 0;
                    __asm__ volatile(""
                                     : "=r"(argumentOrField6)
                                     : "0"(argumentOrField6)
                                     : "$19", "memory");
                    sharedAddress19 = (int)&Level37_79844Data70328View1;
                    Level37_79844Keep(sharedAddress19);
                    resultOrField2 = Level37_79844PlanarHeadingLookupView1(
                        Level37_79844Field(owner17, int*, 12) -
                            Level37_79844Field(sharedAddress19, int*, 0),
                        Level37_79844Field(owner17, int*, 16) -
                            Level37_79844Field((int)&Level37_79844Data70328View1, int*, 4),
                        argumentOrField6);
                    argumentOrField6 = Level37_79844Field(privateRecord18, short*, 54);
                    fieldOrIntermediate3 = 25;
                    if (argumentOrField6)
                        fieldOrIntermediate3 = -25;
                    predicateOrValue16 = resultOrField2 + fieldOrIntermediate3;
                    argumentOrField4 = privateRecord18 + 32;
                    argumentOrField5 = sharedAddress19;
                    Level37_79844Field(privateRecord18, short*, 54) = argumentOrField6 == 0;
                    Level37_79844CopyVectorView1(argumentOrField4, argumentOrField5);
                    predicateOrValue16 &= 255;
                    predicateOrValue16 *= 2;
                    resultOrField2 = Level37_79844Field(
                        (int)&Level37_79844Data65920View1 + predicateOrValue16, short*, 0);
                    capturedLowOrFrameValue8 = originalFrame.sp40;
                    Level37_79844MultiplyComplete(resultOrField2, capturedLowOrFrameValue8);
                    resultOrField2 = Level37_79844Field(privateRecord18, int*, 32);
                    Level37_79844CaptureLow(capturedLowOrFrameValue8);
                    fieldOrIntermediate3 = capturedLowOrFrameValue8 >> 12;
                    resultOrField2 += fieldOrIntermediate3;
                    Level37_79844Field(privateRecord18, int*, 32) = resultOrField2;
                    resultOrField2 = Level37_79844Field(
                        (int)&Level37_79844Data658A0View1 + predicateOrValue16, short*, 0);
                    capturedLowOrFrameValue8 = originalFrame.sp40;
                    Level37_79844MultiplyComplete(resultOrField2, capturedLowOrFrameValue8);
                    argumentOrField6 = 0;
                    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentOrField6, "memory");
                    resultOrField2 = Level37_79844Field(privateRecord18, int*, 36);
                    Level37_79844CaptureLow(capturedLowOrFrameValue8);
                    fieldOrIntermediate3 = capturedLowOrFrameValue8 >> 12;
                    resultOrField2 += fieldOrIntermediate3;
                    Level37_79844Field(privateRecord18, int*, 36) = resultOrField2;
                    Level37_79844Field(owner17, unsigned char*, 0x49) =
                        (unsigned char)(Level37_79844Field(owner17, unsigned char*, 0x49) + 1);
                    if (Level37_79844SubAngle8View1(
                            Level37_79844Field(owner17, unsigned char*, 0x46),
                            Level37_79844PlanarHeadingLookupView1(
                                Level37_79844Field(privateRecord18, int*, 0x20) -
                                    Level37_79844Field(owner17, int*, 0xC),
                                Level37_79844Field(privateRecord18, int*, 0x24) -
                                    Level37_79844Field(owner17, int*, 0x10),
                                0)) < 0) {
                        if (Level37_79844Field(owner17, unsigned char*, 0x3D) != 4) {
                            argumentOrField4 = owner17;
                            MATCHING_KEEP_CLOBBER(argumentOrField4, "memory");
                            resultOrField2 = 114;
                            Level37_79844Keep(resultOrField2);
                            Level37_79844Data6C770View1 = 0;
                            Level37_79844Field(owner17, signed char*, 64) = resultOrField2;
                            resultOrField2 = 4;
                            goto applySharedAnimation;
                        }
                    } else if (Level37_79844Field(owner17, unsigned char*, 0x3D) != 5) {
                        argumentOrField4 = owner17;
                        MATCHING_KEEP_CLOBBER(argumentOrField4, "memory");
                        resultOrField2 = 114;
                        Level37_79844Keep(resultOrField2);
                        Level37_79844Data6C770View1 = 0;
                        Level37_79844Field(owner17, signed char*, 64) = resultOrField2;
                        resultOrField2 = 5;
                    applySharedAnimation:
                        Level37_79844Field(owner17, unsigned char*, 0x3D) = resultOrField2;
                        Level37_79844Field(owner17, signed char*, 0x3F) = 0;
                        Level37_79844EmptyAnimationTransitionHookView1(argumentOrField4);
                    }
                    Level37_79844Field(privateRecord18, unsigned char*, 0x11) =
                        Level37_79844PlanarHeadingLookupView1(
                            Level37_79844Field(privateRecord18, int*, 0x20) -
                                Level37_79844Field(owner17, int*, 0xC),
                            Level37_79844Field(privateRecord18, int*, 0x24) -
                                Level37_79844Field(owner17, int*, 0x10),
                            0);
                    break;
                case 1:
                    if (({
                            resultOrField2 = predicateOrValue16 - 5;
                            Level37_79844Keep(resultOrField2);
                            (unsigned int)resultOrField2 < 18;
                        })) {
                        Level37_79844Call35EE0View1(
                            owner17, Level37_79844Field(privateRecord18, unsigned char*, 0x11),
                            0xA5, 0, 0, (int)temp_v1_6);
                    }
                    if (Level37_79844Field(privateRecord18, short*, 0x38) == 0) {
                        Level37_79844Field(privateRecord18, short*, 0x38) = 0x33;
                    }
                    break;
            }
            goto applySharedPrivateState;
        case 9:
            if ((resultOrField2 = retainedDistance22 < 0x4994, resultOrField2)) {
                Level37_79844Call35EE0View1(
                    owner17, Level37_79844Field(privateRecord18, unsigned char*, 0x11), 0x78, 0, 0,
                    0);
                Level37_79844Call37A60View1(owner17, privateRecord18 + 6, 2, 0x10, -0xC8);
            }
            predicateOrValue16 = (int)&Level37_79844Data6E160View1;
            Level37_79844Keep(predicateOrValue16);
            if ((Level37_79844Field(predicateOrValue16, int*, 0) != 9) &&
                (Level37_79844Call55E84View1(owner17) >= 0x1F) &&
                (Level37_79844Data6E164View1 == owner17)) {
                Level37_79844Field(predicateOrValue16, int*, 0) = 0;
                Level37_79844Data6E164View1 = 0;
            }
            if (Level37_79844Data6C770View1 != 0) {
                Level37_79844RefreshMobySpatialGridAndBasisView1(owner17, 4);
                Level37_79844Call369B8View1(owner17, 0x30);
                Level37_79844DeleteMobyView1(owner17);
                return;
            }
            goto applySharedPrivateState;
        default:
        applySharedPrivateState:
            fieldOrIntermediate3 = Level37_79844Field(privateRecord18, unsigned short*, 56);
            resultOrField2 = fieldOrIntermediate3 - 51;
            if ((unsigned int)resultOrField2 >= 2) {
                resultOrField2 = (short)fieldOrIntermediate3;
                fieldOrIntermediate3 = 53;
                if (resultOrField2 == fieldOrIntermediate3)
                    goto resumeSharedAnimation;
                goto afterOriginalPrivateState;
            }
            resultOrField2 = (short)fieldOrIntermediate3;
            fieldOrIntermediate3 = 51;
            if (resultOrField2 != fieldOrIntermediate3)
                goto originalDifficultyCompare;
            resultOrField2 = 53;
            Level37_79844Field(privateRecord18, short*, 56) = resultOrField2;
        originalDifficultyCompare:
            resultOrField2 = adjustedCount23 < 7;
            if (resultOrField2 == 0) {
                resultOrField2 = Level37_79844Field(privateRecord18, short*, 30);
                if (resultOrField2 < 60)
                    Level37_79844Field(privateRecord18, short*, 30) = 60;
            } else if (({
                           resultOrField2 = adjustedCount23 < 2;
                           Level37_79844Keep(resultOrField2);
                           resultOrField2 == 0;
                       })) {
                resultOrField2 = Level37_79844Field(privateRecord18, short*, 30);
                if (resultOrField2 < 40)
                    Level37_79844Field(privateRecord18, short*, 30) = 40;
            } else {
                resultOrField2 = Level37_79844Field(privateRecord18, short*, 30);
                if (resultOrField2 < 30)
                    Level37_79844Field(privateRecord18, short*, 30) = 30;
            }
        resumeSharedAnimation:
            if ((Level37_79844Field(privateRecord18, short*, 0x38) == 0x34) ||
                (Level37_79844Data6C770View1 != 0)) {
                Level37_79844Field(privateRecord18, short*, 0x38) = 0;
                Level37_79844Field(owner17, unsigned char*, 0x49) = 0U;
                Level37_79844Field(owner17, unsigned char*, 0x48) =
                    (unsigned char)Level37_79844Field(privateRecord18, unsigned short*, 0x3A);
                Level37_79844RequestMobyAnimationView1(
                    owner17, (short)Level37_79844Field(privateRecord18, unsigned short*, 0x3A));
            }
        afterOriginalPrivateState:
            capturedLowOrFrameValue8 = originalFrame.sp38;
            argumentOrField6 = 0;
            if (capturedLowOrFrameValue8) {
                resultOrField2 = Level37_79844PlanarHeadingLookupView1(
                    Level37_79844Field((int)&Level37_79844Data70328View1, int*, 0) -
                        Level37_79844Field(owner17, int*, 12),
                    Level37_79844Field((int)&Level37_79844Data70328View1, int*, 4) -
                        Level37_79844Field(owner17, int*, 16),
                    argumentOrField6);
                resultOrField2 &= 255;
                resultOrField2 *= 2;
                fieldOrIntermediate3 = Level37_79844Field(
                    (int)&Level37_79844Data65920View1 + resultOrField2, short*, 0);
                argumentOrField4 = fieldOrIntermediate3 * 5;
                Level37_79844Keep(argumentOrField4);
                fieldOrIntermediate3 = argumentOrField4 * 16 - argumentOrField4;
                fieldOrIntermediate3 >>= 11;
                Level37_79844Field((int)&Level37_79844Data70328View1, int*, 540) =
                    fieldOrIntermediate3;
                argumentOrField4 = Level37_79844Field(
                    (int)&Level37_79844Data658A0View1 + resultOrField2, short*, 0);
                resultOrField2 = 40;
                Level37_79844Field((int)&Level37_79844Data70328View1, int*, 548) = resultOrField2;
                fieldOrIntermediate3 = argumentOrField4 * 5;
                Level37_79844Keep(fieldOrIntermediate3);
                resultOrField2 = fieldOrIntermediate3 * 16 - fieldOrIntermediate3;
                resultOrField2 >>= 11;
                Level37_79844Field((int)&Level37_79844Data70328View1, int*, 544) = resultOrField2;
                resultOrField2 = 25;
                Level37_79844Field(privateRecord18, int*, 44) = resultOrField2;
                capturedLowOrFrameValue8 = originalFrame.sp38;
                resultOrField2 = 2;
                if (capturedLowOrFrameValue8 == resultOrField2) {
                    MATCHING_BARRIER_VOLATILE("memory");
                    fieldOrIntermediate3 =
                        Level37_79844Field((int)&Level37_79844Data70328View1, int*, 540);
                    resultOrField2 = fieldOrIntermediate3 * 3;
                    Level37_79844Keep(resultOrField2);
                    fieldOrIntermediate3 = (unsigned int)resultOrField2 >> 31;
                    resultOrField2 += fieldOrIntermediate3;
                    fieldOrIntermediate3 =
                        Level37_79844Field((int)&Level37_79844Data70328View1, int*, 544);
                    resultOrField2 >>= 1;
                    Level37_79844Field((int)&Level37_79844Data70328View1, int*, 540) =
                        resultOrField2;
                    resultOrField2 = fieldOrIntermediate3 * 3;
                    Level37_79844Keep(resultOrField2);
                    fieldOrIntermediate3 = (unsigned int)resultOrField2 >> 31;
                    resultOrField2 += fieldOrIntermediate3;
                    resultOrField2 >>= 1;
                    Level37_79844Field((int)&Level37_79844Data70328View1, int*, 544) =
                        resultOrField2;
                    fieldOrIntermediate3 = Level37_79844Field(privateRecord18, int*, 44);
                    resultOrField2 = fieldOrIntermediate3 * 3;
                    Level37_79844Keep(resultOrField2);
                    fieldOrIntermediate3 = (unsigned int)resultOrField2 >> 31;
                    resultOrField2 += fieldOrIntermediate3;
                    resultOrField2 >>= 1;
                    Level37_79844Field(privateRecord18, int*, 44) = resultOrField2;
                }
                goto applyPlayerFlags;
            }
            if (Level37_79844CountTimerDownView1(privateRecord18 + 44, 4) == 0) {
            applyPlayerFlags:
                Level37_79844Field((int)&Level37_79844Data70328View1, int*, 524) = 0x10000480;
                Level37_79844Field((int)&Level37_79844Data70328View1, int*, 572) = 7;
            }
            Level37_79844Field(owner17, int*, 0x18) = 0;
            Level37_79844RefreshMobySpatialGridAndBasisView1(owner17, 5);
            return;
    }
}
#undef Level37_79844MultiplyComplete
#undef Level37_79844CaptureLow
#undef Level37_79844Field
#undef Level37_79844Keep


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
void func_level_37_8007A980(Moby* moby) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-derived C. Original source asm/nonmatchings/overlays/level_37/moby/func_level_37_8007AC9C.s SHA256 24d979b3223d8eec8b7b39e1d933c509c8b5d214da47fc250aeb8f21217fa4f9. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define ScorchField(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Scorch334_func_8001830C() __asm__("func_8001830C");      /* extern */
int Scorch334_func_80036220() __asm__("func_80036220");      /* extern */
int Scorch334_func_80036A68() __asm__("func_80036A68");      /* extern */
int Scorch334_func_80037A60() __asm__("func_80037A60");      /* extern */
int Scorch334_func_800399E8() __asm__("func_800399E8");      /* extern */
int Scorch334_func_80039B6C() __asm__("func_80039B6C");      /* extern */
int Scorch334_func_80040954() __asm__("func_80040954");      /* extern */
int Scorch334MeasureVectorLength() __asm__("func_8004EDE8"); /* extern */
int Scorch334SubtractVector() __asm__("func_8004F1C8");      /* extern */
int Scorch334DeleteMoby() __asm__("func_80055B18");          /* extern */
int Scorch334_rand() __asm__("rand");                        /* extern */
extern unsigned char Scorch334_D_800658A0 __asm__("D_800658A0");
extern unsigned char Scorch334_D_80065920 __asm__("D_80065920");
extern void** Scorch334_D_8006C550 __asm__("D_8006C550");
extern unsigned short Scorch334_D_8006E040 __asm__("D_8006E040");
extern unsigned char* (*CrystalParticle)() __asm__("SpawnParticle");
extern unsigned char ScorchInitialPlayer __asm__("D_80070328");
extern unsigned char Scorch334_D_80070328 __asm__("D_80070328");
extern int Scorch334_D_80071918 __asm__("D_80071918");
extern int Scorch334_D_8007191C __asm__("D_8007191C");
extern int Scorch334_D_80071924 __asm__("D_80071924");

void func_level_37_8007AC9C(Moby* inputOwner) {
    struct {
        unsigned char sp18;
        char pad_19[15];
        Vector3D sp28;
        char pad_34[4];
        Vector3D sp38;
        char pad_44[4];
        int sp48;
        int sp4C;
        int sp50;
        char pad_54[20];
    } frame;

    register Moby* owner __asm__("$19") = inputOwner;

    register Moby* spawned4 __asm__("$4");
    register Vector3D* position16 __asm__("$16");
    register int signedTurn4 __asm__("$4");
    register int signedSpeed4 __asm__("$4");
    register int magnitude2 __asm__("$2");
    register int turnResult2 __asm__("$2");
    register int speedMagnitude2 __asm__("$2");
    register int rawDistance21 __asm__("$21");
    register int rawMotion21 __asm__("$21");
    register int heightDifference2 __asm__("$2");
    register int contactHeight2 __asm__("$2");
    register int rawAngle17 __asm__("$17");
    register int randomX2 __asm__("$2");
    register int randomY2 __asm__("$2");
    register int groundZ3 __asm__("$3");
    register int damage3 __asm__("$3");
    register int contactGroundZ3 __asm__("$3");
    register int activate16 __asm__("$16");
    register int rawAngle16 __asm__("$16");
    register int decay17 __asm__("$17");
    register int decay20 __asm__("$20");
    register int speedResult2 __asm__("$2");
    register int state3 __asm__("$3");
    register int yaw2 __asm__("$2");
    register int nextYaw2 __asm__("$2");
    register void* privateData __asm__("$18");
    register void* attachment3 __asm__("$3");
    register void* timer5 __asm__("$5");

    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register int argument7 __asm__("$7");
    int product;
    register unsigned char* (*callback8)() __asm__("$8");
    register void* vector17 __asm__("$17");
    register void* global16 __asm__("$16");
    register void* vector16 __asm__("$16");
    MATCHING_KEEP(owner);
    value3 = 125;
    value2 = owner->state;
    privateData = owner->mobyTag;
    if (value2 != value3) {
        if (ScorchField(privateData, void**, 0xC) == 0) {
            Scorch334_func_800399E8(inputOwner, privateData + 0xC);
        }
        argument4 = (int)&frame.sp18;
        argument5 = (int)&owner->position;
        MATCHING_KEEP2(argument4, argument5);
        global16 = &ScorchInitialPlayer;
        Scorch334SubtractVector(argument4, argument5, global16);
        value2 = Scorch334MeasureVectorLength(&frame.sp18, 0);
        argument4 = (int)&owner->substate;
        argument5 = 1;
        MATCHING_KEEP2(argument4, argument5);
        rawDistance21 = value2;
        func_800359A4(argument4, argument5);
        state3 = owner->state;
        switch (state3) { /* irregular */
            case 0:
                value2 = ScorchField(&Scorch334_D_80070328, int*, 0x138);
                value3 = owner->substate;
                activate16 = value2 == (int)owner;
                if ((value3 == 0) && ((value2 = rawDistance21 < 800))) {
                    value3 = owner->distanceToGround;
                    value2 = owner->position.z;
                    argument4 = ScorchField(&Scorch334_D_80070328, int*, 8);
                    groundZ3 = value2 - value3;
                    heightDifference2 = groundZ3 - argument4;
                    if (heightDifference2 >= 0) {
                        if (heightDifference2 < 0x258) {
                            MATCHING_KEEP_VOLATILE(activate16);
                            activate16 = 1;
                        }
                    } else if ((heightDifference2 = argument4 - groundZ3) < 600) {
                        activate16 = 1;
                    }
                }
                damage3 = owner->damageFlags;
                if (damage3 & 0x120000) {
                    activate16 = 1;
                }
                if ((value2 = damage3 & 0x10000)) {
                    func_8003BABC(owner, 0, 0);
                    owner->state = 0xA;
                }
                if (activate16 == 0)
                    goto afterState;
                value2 = 1;
                MATCHING_KEEP(value2);
                goto activateState;
                break;
            case 10:
                ScorchField(privateData, signed char*, 0) = 0x64;
                if (ScorchField(privateData, short*, 2) == 0) {
                    ScorchField(privateData, short*, 2) = 0xF0;
                }
                if (ScorchField(privateData, unsigned char*, 1) == 0) {
                    yaw2 = owner->unkb;
                    if (yaw2 == 0) {
                        MATCHING_KEEP(yaw2);
                        yaw2 = func_800360F8(
                            func_8004E880(
                                owner->position.x - ScorchField(global16, int*, 0),
                                owner->position.y - ScorchField(&Scorch334_D_80070328, int*, 4), 0),
                            (int)ScorchField(&Scorch334_D_80070328, unsigned char*, 0xE), 0x20,
                            0x40U);
                    }
                    ScorchField(privateData, unsigned char*, 1) = yaw2;
                }
                ScorchField(privateData, short*, 6) = (short)(func_800363DC(5, 0xB) * 0x10);
                if (ScorchField(privateData, short*, 4) == 0) {
                    ScorchField(privateData, short*, 4) = 0x32;
                }
                owner->state = 3;
                /* fallthrough */
            case 3:
                decay20 = 3;
                decay17 = 4;
                if (owner->damageFlags & 0x10000) {
                    if (ScorchField(privateData, short*, 2) < 0xC8) {
                        ScorchField(privateData, short*, 2) = 0xC8;
                    }
                    nextYaw2 = owner->unkb;
                    if (nextYaw2 == 0) {
                        MATCHING_KEEP(nextYaw2);
                        nextYaw2 = func_800360F8(
                            func_8004E880(
                                owner->position.x - ScorchField(&Scorch334_D_80070328, int*, 0),
                                owner->position.y - ScorchField(&Scorch334_D_80070328, int*, 4), 0),
                            (int)ScorchField(&Scorch334_D_80070328, unsigned char*, 0xE), 0x20,
                            0x40U);
                    }
                    ScorchField(privateData, unsigned char*, 1) = nextYaw2;
                }
                value2 = func_8003BFC0(owner, ScorchField(privateData, int*, 16));
                argument4 = (int)owner;
                if (value2 == 0) {
                    ScorchField(privateData, int*, 16) = func_8003BABC(argument4, 1, 4);
                }
                value2 = owner->substate;
                argument4 = (int)owner;
                if (value2 != 0)
                    goto contactArg5Ready;
                value2 = rawDistance21 < 800;
                timer5 = privateData + 4;
                if (!value2)
                    goto contactArgsReady;
                value3 = owner->distanceToGround;
                value2 = owner->position.z;
                argument4 = ScorchField(&Scorch334_D_80070328, int*, 8);
                contactGroundZ3 = value2 - value3;
                contactHeight2 = contactGroundZ3 - argument4;
                if (contactHeight2 >= 0) {
                    if (contactHeight2 < 600)
                        goto setContactState;
                    argument4 = (int)owner;
                    goto contactArgsReady;
                }
                contactHeight2 = argument4 - contactGroundZ3;
                if (contactHeight2 < 600) {
                setContactState:
                    owner->state = 1;
                }
            contactArgs:
                argument4 = (int)owner;
            contactArg5Ready:
                timer5 = privateData + 4;
            contactArgsReady:
                argument6 = 2;
                argument7 = 14;
                MATCHING_KEEP4(argument4, timer5, argument6, argument7);
                vector16 = &Scorch334_D_80071924;
                ScorchField(vector16, int*, 0) = 255;
                Scorch334_func_80037A60(argument4, timer5, argument6, argument7, -200);
                if (Scorch334_func_80040954(ScorchField(vector16, int*, 0)) != 4) {
                    attachment3 = ScorchField(privateData, void**, 0xC);
                    value2 = 248;
                    if (attachment3 != 0) {
                        ScorchField(attachment3, unsigned char*, 71) = value2;
                        MATCHING_KEEP_CLOBBER(value2, "memory");
                    }
                    MATCHING_BARRIER_VOLATILE("memory");
                    decay20 = 0xE;
                    decay17 = 0x18;
                }
                signedTurn4 = ScorchField(privateData, short*, 6);
                magnitude2 = signedTurn4;
                if (signedTurn4 < 0) {
                    magnitude2 = -magnitude2;
                }
                if (magnitude2 < decay17) {
                    ScorchField(privateData, short*, 6) = 0;
                } else {
                    value3 = signedTurn4;
                    MATCHING_KEEP(value3);
                    turnResult2 = value3 - decay17;
                    if (signedTurn4 < 0) {
                        turnResult2 = value3 + decay17;
                    }
                    ScorchField(privateData, short*, 6) = turnResult2;
                }
                owner->angle.yaw +=
                    (int)((unsigned short)ScorchField(privateData, short*, 6) << 0x10) >> 0x14;
                value2 = func_80035EE0(owner, (int)ScorchField(privateData, unsigned char*, 1),
                                       (int)ScorchField(privateData, short*, 2), 0x1F4, 0xC8, 0x21);
                vector17 = &frame.sp28;
                argument4 = (int)vector17;
                MATCHING_KEEP(argument4);
                position16 = &owner->position;
                argument5 = (int)position16;
                MATCHING_KEEP(argument5);
                rawMotion21 = value2;
                func_8004F178(argument4, argument5);
                frame.sp28.z += 0x96;
                frame.sp28.x =
                    frame.sp28.x +
                    ((int)(ScorchField(&Scorch334_D_80065920, short*,
                                       (ScorchField(privateData, unsigned char*, 1) * 2)) *
                           (ScorchField(privateData, short*, 2) + 0x96)) >>
                     0xC);
                frame.sp28.y +=
                    (int)(ScorchField(&Scorch334_D_800658A0, short*,
                                      (ScorchField(privateData, unsigned char*, 1) * 2)) *
                          (ScorchField(privateData, short*, 2) + 0x96)) >>
                    0xC;
                value2 = Scorch334_func_8001830C(position16, &frame.sp28, 0, 0, owner);
                if (value2 != 0) {
                    rawAngle17 = func_8004E880(Scorch334_D_80071918, Scorch334_D_8007191C, 0);
                    rawAngle16 = rawAngle17 + 0x40;
                    if (func_8004F264(rawAngle16 & 0xFF,
                                      (int)ScorchField(privateData, unsigned char*, 1)) >= 0x41) {
                        rawAngle16 = rawAngle17 - 0x40;
                    }
                    value2 = func_8003613C(ScorchField(privateData, unsigned char*, 1),
                                           rawAngle16 & 255);
                    value3 = ScorchField(privateData, unsigned char*, 1);
                    value2 *= 2;
                    value3 += value2;
                    value2 = ScorchField(privateData, short*, 6);
                    ScorchField(privateData, unsigned char*, 1) = value3;
                    value3 = ScorchField(privateData, short*, 2);
                    value2 = -value2;
                    ScorchField(privateData, short*, 6) = value2;
                    MATCHING_KEEP_CLOBBER(value3, "memory");
                    speedResult2 = (value3 * 3) >> 2;
                    goto storeSpeed;
                }
                if ((value2 = rawMotion21 & 32)) {
                    ScorchField(privateData, signed char*, 0) = 0;
                } else {
                    signedSpeed4 = ScorchField(privateData, short*, 2);
                    speedMagnitude2 = signedSpeed4;
                    if (signedSpeed4 < 0) {
                        speedMagnitude2 = -speedMagnitude2;
                    }
                    if (speedMagnitude2 < decay20) {
                        ScorchField(privateData, short*, 2) = 0;
                    } else {
                        value3 = signedSpeed4;
                        MATCHING_KEEP(value3);
                        speedResult2 = value3 - decay20;
                        if (signedSpeed4 < 0) {
                            speedResult2 = value3 + decay20;
                        }
                    storeSpeed:
                        ScorchField(privateData, short*, 2) = (short)speedResult2;
                    }
                }
                func_8004F178(&frame.sp38, &owner->position);
                value2 = func_800363DC(0, 50);
                argument4 = 0;
                value3 = frame.sp38.z;
                __asm__("" : "=r"(value3) : "0"(value3), "r"(argument4) : "$5");
                argument5 = 250;
                __asm__(""
                        : "=r"(argument4), "=r"(argument5)
                        : "0"(argument4), "1"(argument5), "r"(value3));
                value3 += 675;
                value3 += value2;
                frame.sp38.z = value3;
                frame.sp38.x = frame.sp38.x + func_8003636C(argument4, argument5);
                frame.sp38.y += func_8003636C(0, 0xFA);
                randomX2 = (Scorch334_rand() & 0x1F) - 0x10;
                frame.sp48 = randomX2;
                value2 = Scorch334_rand();
                argument4 = 25;
                argument5 = 35;
                MATCHING_KEEP3(argument4, argument5, value2);
                randomY2 = (value2 & 31) - 16;
                frame.sp4C = randomY2;
                frame.sp50 = func_8003636C(argument4, argument5);

                value2 = ScorchField(privateData, unsigned short*, 2);
                value2 <<= 16;
                MATCHING_KEEP_CLOBBER(value2, "memory");
                value3 = value2 >> 16;
                value2 = (short)(value3 / 3);
                value3 = ScorchField(&Scorch334_D_80065920, short*,
                                     ScorchField(privateData, unsigned char*, 1) * 2);
                product = value3 * value2;
                value2 = frame.sp48;
                value3 = product >> 12;
                value2 += value3;
                frame.sp48 = value2;
                value2 = ScorchField(privateData, unsigned short*, 2);
                value2 <<= 16;
                MATCHING_KEEP_CLOBBER(value2, "memory");
                value3 = value2 >> 16;
                value2 = (short)(value3 / 3);
                value3 = ScorchField(&Scorch334_D_800658A0, short*,
                                     ScorchField(privateData, unsigned char*, 1) * 2);
                product = value3 * value2;
                argument5 = 13;
                MATCHING_KEEP(argument5);
                argument6 = (int)&frame.sp38;
                argument7 = (int)&frame.sp48;
                callback8 = CrystalParticle;
                __asm__(""
                        : "=r"(callback8)
                        : "0"(callback8), "r"(argument5), "r"(argument6), "r"(argument7)
                        : "$4");
                argument4 = 1;
                value2 = frame.sp4C;
                value3 = product >> 12;
                value2 += value3;
                frame.sp4C = value2;
                ScorchField(callback8(argument4, argument5, argument6, argument7), signed char*,
                            2) = 4;
                value2 = func_800359A4(privateData, 1);
                if (value2 == 0)
                    goto afterState;
                value2 = 1;
                MATCHING_KEEP(value2);
            activateState:
                MATCHING_BARRIER_VOLATILE("memory");
                owner->state = value2;
                break;
        }
    afterState:
        owner->damageFlags = 0;
        if (owner->state == 1) {
            spawned4 = SpawnMoby(0x169, owner);
            MATCHING_KEEP(spawned4);
            if (spawned4 != 0) {
                ScorchField(spawned4->mobyTag, int*, 0xC) =
                    (int)ScorchField(*Scorch334_D_8006C550, int*, 0xB8);
                spawned4->angle.yaw = ((int)(Scorch334_D_8006E040 << 0x10) >> 0x14) - 0x40;
            }
            if (owner->gemValue != 0xFF) {
                Scorch334_func_80036A68(owner, 0, 0, 0);
                func_8003BA00(owner);
            }
            if ((ScorchField(privateData, int*, 0x14) != 0) &&
                (Scorch334_func_80036220(&owner->position, privateData + 0x18, 0, 0) != 0)) {
                ScorchField(
                    ((ScorchField(privateData, int*, 0x30) * 0x58) + (int)Scorch334_D_8006C550),
                    signed char*, 0x49) = 1;
            }
            if (func_8003BFC0(owner, ScorchField(privateData, int*, 0x10)) != 0) {
                func_8003BE70(ScorchField(privateData, int*, 0x10));
            }
            ScorchField(privateData, int*, 0x10) = -1;
            Scorch334DeleteMoby(owner);
        }
        if (ScorchField(privateData, void**, 0xC) != 0) {
            Scorch334_func_80039B6C(owner, privateData + 0xC);
        }
    }
}
#undef ScorchField

#define Controller810A0Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern unsigned char Controller810A0Sin[] __asm__("D_800658A0");
extern unsigned char Controller810A0Cos[] __asm__("D_80065920");
extern unsigned short Controller810A0Angle0 __asm__("D_8006E03E"), Controller810A0Angle1
    __asm__("D_8006E040");
extern unsigned char Controller810A0Player[] __asm__("D_80070328");
extern void* Controller810A0Models[] __asm__("D_8006EE2C");
extern int D_8006C770;
extern void* (*Controller810A0Spawn)(int, void*)__asm__("SpawnMoby");
int Controller810A0Helper18368(void*, void*) __asm__("func_80018368");
void* Controller810A0Helper1BA30(void*, int, int, int, int, int) __asm__("func_8001BA30");
int Controller810A0Helper1C288(void*, int, int) __asm__("func_8001C288");
int Controller810A0CountTimerDown(void*, int) __asm__("func_800359A4");
int Controller810A0PlayMobySoundEvent(void*, int, int) __asm__("func_8003BABC");
int Controller810A0PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Controller810A0CopyVector(void*, void*) __asm__("func_8004F178");
int Controller810A0AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
int Controller810A0Helper50844(void*, int, int, int) __asm__("func_80050844");
int Controller810A0Helper509E8(int) __asm__("func_800509E8");
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
void func_level_37_8007B4CC(void* input) {
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
        state = Controller810A0Field(owner, unsigned char*, 0x48);
        tag = Controller810A0Field(owner, void**, 0);
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
                spawned = Controller810A0Spawn(Controller810A0Field(owner, short*, 0x36), owner);
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
                        Controller810A0Helper50844(spawned + 0xC, 7, 0xA, 0x4080E0);
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
    Controller810A0Field(owner, unsigned char*, 0x48) = 0xAU;
    idlePosition = owner + 0xC;
idle:
    nearby = Controller810A0Helper1BA30(idlePosition, 0x7D0, 0, 0, 0x30000, 0);
    if (nearby != 0) {
        Controller810A0Field(nearby, signed char*, 0x51) = Controller810A0PlanarHeadingLookup(
            Controller810A0Field(nearby, int*, 0xC) - Controller810A0Field(owner, int*, 0xC),
            Controller810A0Field(nearby, int*, 0x10) - Controller810A0Field(owner, int*, 0x10), 0);
    }
    if (Controller810A0Helper1C288(idlePosition, 0x4B0, 7) != 0) {
        playerAngle = Controller810A0PlanarHeadingLookup(
                          Controller810A0Field(&Controller810A0Player, int*, 0) -
                              Controller810A0Field(owner, int*, 0xC),
                          Controller810A0Field(&Controller810A0Player, int*, 4) -
                              Controller810A0Field(owner, int*, 0x10),
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
    Controller810A0Field(owner, int*, 0xC) =
        (int)(Controller810A0Field(owner, int*, 0xC) +
              ((int)(((int)(*(short*)(Controller810A0Cos +
                                      (Controller810A0Field(tag, unsigned char*, 1) * 2)) *
                            Controller810A0Field(tag, short*, 2)) >>
                      0xC) *
                     *(short*)(Controller810A0Cos +
                               (Controller810A0Field(tag, unsigned char*, 0) * 2))) >>
               0xC));
    Controller810A0Field(owner, int*, 0x10) =
        (int)(Controller810A0Field(owner, int*, 0x10) +
              ((int)(((int)(*(short*)(Controller810A0Sin +
                                      (Controller810A0Field(tag, unsigned char*, 1) * 2)) *
                            Controller810A0Field(tag, short*, 2)) >>
                      0xC) *
                     *(short*)(Controller810A0Cos +
                               (Controller810A0Field(tag, unsigned char*, 0) * 2))) >>
               0xC));
    Controller810A0Field(owner, int*, 0x14) =
        (int)(Controller810A0Field(owner, int*, 0x14) +
              ((int)(*(short*)(Controller810A0Sin +
                               (Controller810A0Field(tag, unsigned char*, 0) * 2)) *
                     Controller810A0Field(tag, short*, 2)) >>
               0xC));
    if (Controller810A0Helper18368(&frame.previous, position) != 0) {
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
            Controller810A0Helper509E8(handle);
        }
        goto removeOwner;
    }
    goto finished;
removeOwner:
    Controller810A0DeleteMoby(owner);
finished:;
}

#undef Controller810A0Field

extern Moby* Actor37B988_D_8006C550 __asm__("D_8006C550");
extern int Actor37B988_D_8006C648 __asm__("D_8006C648");
void Actor37B988DeleteMoby(Moby*) __asm__("func_80055B18");
int Actor37B988CountTimerDown(void* pTimer, int pTimerType) __asm__("func_800359A4");
void func_level_37_8007B988(Moby* actor) {
    short temp_v0_3;
    short temp_v0_4;
    short temp_v0_5;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_6;
    register int rawSelector __asm__("$2");
    register int selector __asm__("$3");
    register int step __asm__("$3");
    register int fade __asm__("$2");
    int byteIndex;
    register int selectorBit __asm__("$2");
    register int halfwordValue __asm__("$2");
    register int state __asm__("$4");
    unsigned char temp_v0_10;
    unsigned char temp_v0_8;
    unsigned char temp_v0_9;
    unsigned char temp_v1;
    unsigned char temp_v1_2;
    unsigned char temp_v1_3;
    unsigned char temp_v1_4;
    unsigned char temp_v1_5;
    unsigned char temp_v1_6;
    unsigned char yawByte;
    unsigned char fadeByte;
    void* byteAddress;
    void* privateBytes;
    void* sharedBytes;
    register Moby* pool __asm__("$2");

    pool = Actor37B988_D_8006C550;
    MATCHING_KEEP(pool);
    state = actor->state;
    privateBytes = actor->mobyTag;
    sharedBytes = pool->mobyTag;
    switch (state) {
        case 0:
            state = 1;
            MATCHING_KEEP(state);
            actor->lowDrawDistance = 0x30;
            actor->unknown3[0] = state;
            actor->drawn = state;
            actor->colour.r = 0;
            actor->colour.g = 0;
            actor->colour.b = 0;
            actor->colour.a = 0x3F;
            actor->highDrawDistance = actor->lowDrawDistance;
            if ((*(int*)((unsigned char*)(privateBytes) + 4)) != 0) {
                actor->unknownCollision = 0;
            }
            actor->angle.yaw = ((*(int*)((unsigned char*)(privateBytes) + 4)) << 8) / 3;
            selector = *(int*)((unsigned char*)privateBytes + 4);
            __asm__(""
                    : "=r"(selector), "=r"(state)
                    : "0"(selector), "1"(state), "m"(actor->angle.yaw));
            *(volatile unsigned char*)&actor->state = state;
            __asm__("" : "=r"(selector) : "0"(selector), "m"(actor->state));
            actor->position.z += selector * 0x258;
            halfwordValue = *(int*)privateBytes;
            MATCHING_KEEP(halfwordValue);
            if (halfwordValue == 0) {
                halfwordValue = 0x80;
            } else {
                halfwordValue = 0x40;
            }
            (*(unsigned short*)((unsigned char*)(privateBytes) + 8)) = halfwordValue;
            (*(int*)((unsigned char*)(sharedBytes) + 0xD4)) = 0;
            (*(short*)((unsigned char*)(privateBytes) + 0xA)) =
                (short)((*(int*)((unsigned char*)(privateBytes) + 4)) * 6);

        case 1:
            if (Actor37B988CountTimerDown(privateBytes + 0xA, 2) != 0) {
                if ((*(int*)((unsigned char*)(privateBytes) + 0)) == 0) {
                    temp_v1 = actor->colour.r + Actor37B988_D_8006C648;
                    actor->colour.r = temp_v1;
                    temp_v0 =
                        (int)((*(unsigned short*)((unsigned char*)(privateBytes) + 8)) << 0x10) >>
                        0x12;
                    if (temp_v0 < (temp_v1 & 0xFF)) {
                        actor->colour.r = (unsigned char)temp_v0;
                    }
                    temp_v1_2 = actor->colour.g + Actor37B988_D_8006C648;
                    actor->colour.g = temp_v1_2;
                    temp_v0_2 =
                        (int)((*(unsigned short*)((unsigned char*)(privateBytes) + 8)) << 0x10) >>
                        0x12;
                    if (temp_v0_2 < (temp_v1_2 & 0xFF)) {
                        actor->colour.g = (unsigned char)temp_v0_2;
                    }
                    temp_v1_3 = actor->colour.b + (Actor37B988_D_8006C648 * 4);
                    actor->colour.b = temp_v1_3;
                    temp_v0_3 = (short)(*(unsigned short*)((unsigned char*)(privateBytes) + 8));
                    if (temp_v0_3 < (temp_v1_3 & 0xFF)) {
                        actor->colour.b = (unsigned char)temp_v0_3;
                    }
                } else {
                    temp_v1_4 = actor->colour.r + (Actor37B988_D_8006C648 * 4);
                    actor->colour.r = temp_v1_4;
                    temp_v0_4 = (short)(*(unsigned short*)((unsigned char*)(privateBytes) + 8));
                    if (temp_v0_4 < (temp_v1_4 & 0xFF)) {
                        actor->colour.r = (unsigned char)temp_v0_4;
                    }
                    temp_v1_5 = actor->colour.g + (Actor37B988_D_8006C648 * 4);
                    actor->colour.g = temp_v1_5;
                    temp_v0_5 = (short)(*(unsigned short*)((unsigned char*)(privateBytes) + 8));
                    if (temp_v0_5 < (temp_v1_5 & 0xFF)) {
                        actor->colour.g = (unsigned char)temp_v0_5;
                    }
                    temp_v1_6 = actor->colour.b + Actor37B988_D_8006C648;
                    actor->colour.b = temp_v1_6;
                    temp_v0_6 =
                        (int)((*(unsigned short*)((unsigned char*)(privateBytes) + 8)) << 0x10) >>
                        0x12;
                    if (temp_v0_6 < (temp_v1_6 & 0xFF)) {
                        actor->colour.b = (unsigned char)temp_v0_6;
                    }
                }
            }
            goto updateTail;
        case 2:
            if ((*(int*)((unsigned char*)(privateBytes) + 0)) == 0) {
                temp_v0_8 = actor->colour.r - Actor37B988_D_8006C648;
                actor->colour.r = temp_v0_8;
                if ((unsigned int)(temp_v0_8 & 0xFF) >= 0x81U) {
                    actor->colour.r = 0;
                }
                temp_v0_9 = actor->colour.g - Actor37B988_D_8006C648;
                actor->colour.g = temp_v0_9;
                if ((unsigned int)(temp_v0_9 & 0xFF) >= 0x81U) {
                    actor->colour.g = 0;
                }
                step = Actor37B988_D_8006C648;
                fade = actor->colour.b;
                MATCHING_KEEP2(step, fade);
                fadeByte = fade - (step * 4);
                actor->colour.b = fadeByte;
                goto block_33;
            }
            step = Actor37B988_D_8006C648;
            fade = actor->colour.r;
            MATCHING_KEEP2(step, fade);
            temp_v0_10 = fade - (step * 4);
            actor->colour.r = temp_v0_10;
            if ((unsigned int)(temp_v0_10 & 0xFF) < 0x81U) {
                step = Actor37B988_D_8006C648;
                fade = actor->colour.g;
                MATCHING_KEEP2(step, fade);
                fadeByte = fade - (step * 4);
                actor->colour.g = fadeByte;
            block_33:
                if ((unsigned int)(fadeByte & 0xFF) >= 0x81U) {
                    goto block_34;
                }
                goto updateTail;
            }
        block_34:
            Actor37B988DeleteMoby(actor);
            return;
        default:
        updateTail:
            if ((*(int*)((unsigned char*)(sharedBytes) + 0xD4)) != 0) {
                byteIndex = 0;
                do {
                    byteAddress = (unsigned char*)actor + byteIndex;
                    byteIndex += 1;
                    (*(unsigned char*)((unsigned char*)(byteAddress) + 0x54)) =
                        (unsigned char)((*(unsigned char*)((unsigned char*)(byteAddress) + 0x54)) +
                                        ((*(int*)((unsigned char*)(sharedBytes) + 0xD4)) * 2));
                } while (byteIndex < 3);
                rawSelector = (*(int*)((unsigned char*)(privateBytes) + 4));

                if (rawSelector == 0) {
                    Actor37B988CountTimerDown(sharedBytes + 0xD4, 4);
                    goto reloadSelector;
                }
                selectorBit = rawSelector & 1;
            } else {
            reloadSelector:
                selectorBit = (*(int*)((unsigned char*)(privateBytes) + 4)) & 1;
            }
            if (selectorBit != 0) {
                yawByte = actor->angle.yaw + 7;
            } else {
                yawByte = actor->angle.yaw - 7;
            }
            actor->angle.yaw = yawByte;
            return;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
extern int Level37_7BD9CPlayer524 __asm__("D_80070328+524");
#define Level37_7BD9CF8 (*(volatile int*)&originalFrame.spF8)
#define Level37_7BD9CStart(p, a, b)               \
    do {                                          \
        int lhs = (a), rhs = (b);                 \
        p.full = (long long)lhs * (long long)rhs; \
        __asm__("" : "=x"(p.full) : "0"(p.full)); \
    } while (0)
typedef union {
    long long full;
    struct {
#if defined(__MIPSEB__)
        int high;
        unsigned low;
#else
        unsigned low;
        int high;
#endif
    } words;
} Level37_7BD9CProduct;
extern int Level37_7BD9C_D_8006C7C4 __asm__("D_8006C7C4");
/* SCUS-94467 USA Rev0, func_level_37_8007BD9C.
 * AI generated; not human reviewed.
 * All1598 original instructions and six selector destinations are checked
 * independently, including actual branches, calls and data-address addends.
 * Saved words retain their original producer phases. The local ring is
 * written completely before its indexed reads; the original invalid-count
 * divide trap is retained, with no invented initializer or runtime guard.
 * Ten initialized signed64 products precede their original high/low captures.
 * Empty asm templates observe complete initialized values and emit no CPU
 * instructions. The shared T3 objects have disjoint actual C live ranges.
 * The two volatile pointer-word reads in the13-argument callback setup are
 * the existing original reads. Ordinary C emits every outgoing argument;
 * its retained heading becomes savedWord16 at the original call delay.
 * The344-byte o32 frame and four-byte pointer words target this fixed-USA
 * MIPS build. This is not a portable-host-pointer or overflow claim.
 * Companion source, original-producer, numeric and linked gates are required.
 */
#define Level37_7BD9CField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level37_7BD9CKeep(v) __asm__("" : "=r"(v) : "0"(v))
void Level37_7BD9C_func_80013ACC(int, int) __asm__("func_80013ACC");
void Level37_7BD9C_func_80013AE4(int, int) __asm__("func_80013AE4");
void Level37_7BD9C_func_80013D44(int, int, int, int) __asm__("func_80013D44");
int Level37_7BD9C_func_8001A358(int, int) __asm__("func_8001A358");
int Level37_7BD9C_func_8002803C(int, int, int, int, int, int, int) __asm__("func_8002803C");
int Level37_7BD9C_func_80028154(int) __asm__("func_80028154");
void Level37_7BD9CRequestMobyAnimation(int, int) __asm__("func_80034F40");
int Level37_7BD9C_func_80035194(int, int) __asm__("func_80035194");
int Level37_7BD9CTurnMobyTowardPlayer(int, int, int, int) __asm__("func_8003573C");
int Level37_7BD9CTurnMobyTowardHeading(int, int, int, int, int, int) __asm__("func_8003585C");
int Level37_7BD9CCountTimerDown(int, int) __asm__("func_800359A4");
int Level37_7BD9CRandBetween(int, int) __asm__("func_8003636C");
int Level37_7BD9CRandSignedBetween(int, int) __asm__("func_800363DC");
int Level37_7BD9C_func_800365E4(int, int, int, int, int) __asm__("func_800365E4");
void Level37_7BD9C_func_80038BF8(int, int, int, int) __asm__("func_80038BF8");
void Level37_7BD9C_func_8003B7B4(int, int, int) __asm__("func_8003B7B4");
int Level37_7BD9CPlayMobySoundEvent(int, int, int) __asm__("func_8003BABC");
void Level37_7BD9C_func_8003BE70(int) __asm__("func_8003BE70");
int Level37_7BD9C_func_8003BFC0(int, int) __asm__("func_8003BFC0");
int Level37_7BD9CPlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
int Level37_7BD9CMeasureVectorLength(int, int) __asm__("func_8004EDE8");
void Level37_7BD9CShiftVectorRightTowardZero(int, int) __asm__("func_8004F110");
void Level37_7BD9CCopyVector(int, int) __asm__("func_8004F178");
void Level37_7BD9CAddVector(int, int, int) __asm__("func_8004F194");
void Level37_7BD9CSubtractVector(int, int, int) __asm__("func_8004F1C8");
int Level37_7BD9CAbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
void Level37_7BD9CDeleteMoby(int) __asm__("func_80055B18");
void Level37_7BD9CRefreshMobySpatialGridAndBasis(int, int) __asm__("func_80055D24");
int Level37_7BD9C_func_80055E84(int) __asm__("func_80055E84");
void Level37_7BD9CInterpolateMobyVertex(int, int, int) __asm__("func_80055F14");
int Level37_7BD9C_rand(void) __asm__("rand");
extern int Level37_7BD9C_D_8006580C __asm__("D_8006580C");
extern int Level37_7BD9C_D_80065834 __asm__("D_80065834");
extern int Level37_7BD9C_D_800658A0 __asm__("D_800658A0");
extern int Level37_7BD9C_D_80065920 __asm__("D_80065920");
extern unsigned char Level37_7BD9C_D_8006C40A __asm__("D_8006C40A");
extern int Level37_7BD9C_D_8006C574 __asm__("D_8006C574");
extern int Level37_7BD9C_D_8006C578 __asm__("D_8006C578");
extern int Level37_7BD9C_D_8006C58C __asm__("D_8006C58C");
extern int Level37_7BD9C_D_8006C770 __asm__("D_8006C770");
extern int Level37_7BD9C_D_8006C7E8 __asm__("D_8006C7E8");
extern int Level37_7BD9C_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level37_7BD9C_D_8006D088 __asm__("D_8006D088");
extern int Level37_7BD9C_D_8006E048 __asm__("D_8006E048");
extern int Level37_7BD9C_D_8006E160 __asm__("D_8006E160");
extern int Level37_7BD9C_D_8006E788 __asm__("D_8006E788");
extern int Level37_7BD9C_D_8006EE2C __asm__("D_8006EE2C");
extern int Level37_7BD9C_D_80070328 __asm__("D_80070328");
extern signed char Level37_7BD9C_D_8007158E __asm__("D_8007158E");
extern signed char Level37_7BD9C_D_8007159A __asm__("D_8007159A");
extern int Level37_7BD9C_D_level_37_8008BA38 __asm__("D_level_37_8008BA38");
extern int (*Level37_7BD9CSpawnMoby)(int, int) __asm__("SpawnMoby");
extern int Level37_7BD9C_func_80027A60 __asm__("func_80027A60");
extern int Level37_7BD9C_func_80027E40 __asm__("func_80027E40");
extern int Level37_7BD9C_func_80029904 __asm__("func_80029904");
extern unsigned char Level37_7BD9C_func_level_37_80074D90 __asm__("func_level_37_80074D90");
extern int Level37_7BD9C_main_TEXT_END __asm__("main_TEXT_END");
extern int Level37_7BD9C_main_TEXT_START __asm__("main_TEXT_START");
extern int (*volatile Level37_7BD9Cunk_ovlheader_80074314)(int, int, int, int, int, int, int, int,
                                                           int, int, int, int,
                                                           int) __asm__("unk_ovlheader_80074314");
extern int Level37_7BD9C_unk_ovlheader_80074364 __asm__("unk_ovlheader_80074364");
extern int Level37_7BD9C_unk_ovlheader_80074368 __asm__("unk_ovlheader_80074368");
extern int Level37_7BD9C_unk_ovlheader_8007436C __asm__("unk_ovlheader_8007436C");
void func_level_37_8007BD9C(void* input) {
    register int savedWord16 __asm__("$16"), savedWord17 __asm__("$17"), savedWord18 __asm__("$18"),
        savedWord19 __asm__("$19"), privateAddress20 __asm__("$20"), ownerAddress21 __asm__("$21"),
        savedWord22 __asm__("$22"), savedWord23 __asm__("$23");
    register int workWord2 __asm__("$2"), workWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        workWord8 __asm__("$8"), workWord9 __asm__("$9");
    int selectedSpawnFlags, retainedFrameAddress;
    register int divisionHighWord __asm__("$11");
    Level37_7BD9CProduct completeProduct0, completeProduct1, completeProduct2, completeProduct3,
        completeProduct4, completeProduct5, completeProduct6, completeProduct7, completeProduct8,
        completeDivisionProduct3;
    register int workWord11 __asm__("$11"), workWord12 __asm__("$12");
    struct {
        int sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C,
            sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4,
            spA8, spAC, spB0, spB4, spB8, spBC, spC0, spC4, spC8, spCC, spD0, spD4, spD8, spDC,
            spE0, spE4, spE8, spEC, spF0, spF4, spF8, spFC, sp100, sp104, sp108, sp10C, sp110,
            sp114, sp118, sp11C, sp120, sp124, sp128, sp12C;
    } originalFrame;
    int temp_v0_15;
    int temp_v0_6;
    int temp_v0_11;
    int temp_v0_13;
    int temp_v0_16;
    int temp_v0_4;
    int var_a0_9;
    int var_v1;
    int temp_a0_9;
    int temp_a1;
    int temp_v0_3;
    int temp_v0_5;
    int temp_v0_8;
    int temp_v0_9;
    int retainedCallbackHeading;
    int temp_v1_10;
    int var_a0_10;
    int temp_a0;
    int temp_a0_10;
    int temp_a0_11;
    int temp_a0_2;
    int temp_a0_3;
    int temp_a0_4;
    int temp_a0_5;
    int temp_a0_6;
    int temp_a0_7;
    int temp_a0_8;
    int temp_a3;
    int temp_a3_3;
    int temp_v0;
    int temp_v0_14;
    int temp_v0_2;
    int temp_v1;
    int temp_v1_11;
    int temp_v1_12;
    int temp_v1_13;
    int temp_v1_3;
    int temp_v1_6;
    int var_v0;
    int var_v0_2;
    int var_v0_4;
    int var_v0_5;
    int var_v1_5;
    int temp_v1_7;
    int temp_v1_9;
    int temp_v0_10;
    int temp_v0_12;
    int temp_v0_7;
    int temp_v1_8;
    ownerAddress21 = (int)input;
    Level37_7BD9CKeep(ownerAddress21);
    argumentWord4 = Level37_7BD9C_D_8006C40A;
    workWord3 = Level37_7BD9C_D_8006C7C4;
    MATCHING_OBSERVE2_VOLATILE_CLOBBER(argumentWord4, workWord3, "memory");
    privateAddress20 = Level37_7BD9CField(ownerAddress21, int*, 0);
    MATCHING_OBSERVE_VOLATILE_CLOBBER(privateAddress20, "$4");
    argumentWord4 = (int)&originalFrame.sp38;
    MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord4, "$16");
    savedWord16 = (int)&Level37_7BD9C_D_80070328;
    Level37_7BD9CKeep(savedWord16);
    argumentWord5 = savedWord16;
    savedWord17 = ownerAddress21 + 12;
    Level37_7BD9CSubtractVector(argumentWord4, argumentWord5, savedWord17);
    Level37_7BD9CMeasureVectorLength((int)&originalFrame.sp38, 0);
    Level37_7BD9CSubtractVector(
        (int)&originalFrame.sp38, savedWord16,
        Level37_7BD9CField(Level37_7BD9CField(privateAddress20, int*, 0x38), int*, 0xC));
    Level37_7BD9CMeasureVectorLength((int)&originalFrame.sp38, 0);
    Level37_7BD9CSubtractVector(
        (int)&originalFrame.sp38, savedWord17,
        Level37_7BD9CField(Level37_7BD9CField(privateAddress20, int*, 0x38), int*, 0xC));
    savedWord19 = Level37_7BD9CMeasureVectorLength((int)&originalFrame.sp38, 0);
    if ((unsigned int)(Level37_7BD9CField((int)&Level37_7BD9C_D_80070328, int*, 0x50) - 7) < 2U) {
        Level37_7BD9CField(privateAddress20, short*, 0x4E) = 0;
    }
    if (Level37_7BD9CField(privateAddress20, int*, 0x40) == 0) {
        Level37_7BD9CField(privateAddress20, int*, 0x40) = 1;
        Level37_7BD9CField(privateAddress20, int*, 0x44) = 2;
        Level37_7BD9CField(privateAddress20, int*, 0x48) = 9;
        Level37_7BD9C_func_80013ACC(ownerAddress21, 0xD);
        if (Level37_7BD9CField(privateAddress20, int*, 0x58) < 0) {
            Level37_7BD9CField(privateAddress20, int*, 0x58) = (short)Level37_7BD9C_func_8002803C(
                0x17, 0x172, Level37_7BD9C_unk_ovlheader_80074368,
                Level37_7BD9C_unk_ovlheader_8007436C, Level37_7BD9C_unk_ovlheader_80074364,
                privateAddress20 + 0x48, Level37_7BD9CField(privateAddress20, int*, 0x48));
        }
    }
    if (Level37_7BD9CField(privateAddress20, short*, 0x56) == 0) {
        if (((Level37_7BD9CField(ownerAddress21, int*, 0x18) != 0) ||
             (Level37_7BD9CField((int)&Level37_7BD9C_D_80070328, int*, 0x50) != 0)) &&
            (Level37_7BD9CField((int)&Level37_7BD9C_D_80070328, int*, 0x240) == 0)) {
            Level37_7BD9CField(privateAddress20, short*, 0x54) = 0x1E;
            Level37_7BD9CField(privateAddress20, short*, 0x56) = 1;
            Level37_7BD9C_func_80013ACC(ownerAddress21, 0xD);
        }
    } else {
        if ((Level37_7BD9CField(ownerAddress21, int*, 0x18) & 0x100000) &&
            ((unsigned int)(Level37_7BD9CField(ownerAddress21, unsigned char*, 0x48) - 4) >= 2U)) {
            if (Level37_7BD9CField(privateAddress20, int*, 0xBC) != 0) {
                Level37_7BD9CField(privateAddress20, int*, 0xD4) = 0x1E;
                goto block_30;
            }
            if (Level37_7BD9C_func_8003BFC0(
                    ownerAddress21, Level37_7BD9CField(privateAddress20, int*, 0x5C)) != 0) {
                Level37_7BD9C_func_8003BE70(Level37_7BD9CField(privateAddress20, int*, 0x5C));
            }
            Level37_7BD9CField(privateAddress20, int*, 0x5C) = -1;
            Level37_7BD9CField(privateAddress20, int*, 0xD0) = 0x3C;
            temp_v0 = Level37_7BD9CField(privateAddress20, int*, 0x48) - 1;
            Level37_7BD9CField(privateAddress20, int*, 0x48) = temp_v0;
            if ((temp_v0 <= 0) &&
                (Level37_7BD9CField((int)&Level37_7BD9C_D_80070328, int*, 0x50) != 8)) {
                temp_a0 = Level37_7BD9CField(privateAddress20, int*, 0x64);
                if (temp_a0 != -1) {
                    Level37_7BD9C_func_80028154(temp_a0);
                }
                temp_a0_2 = Level37_7BD9CField(privateAddress20, int*, 0x68);
                Level37_7BD9CField(privateAddress20, int*, 0x64) = -1;
                if (temp_a0_2 != -1) {
                    Level37_7BD9C_func_80028154(temp_a0_2);
                }
                temp_a0_3 = Level37_7BD9CField(privateAddress20, int*, 0x58);
                Level37_7BD9CField(privateAddress20, int*, 0x68) = -1;
                if (temp_a0_3 != -1) {
                    Level37_7BD9C_func_80028154(temp_a0_3);
                }
                Level37_7BD9CField(privateAddress20, int*, 0x58) = -1;
                Level37_7BD9C_func_80038BF8(ownerAddress21, privateAddress20 + 0x20, 0, 4);
                workWord3 = Level37_7BD9CField(privateAddress20, int*, 56);
                __asm__ volatile("" ::"r"(privateAddress20) : "$2", "memory");
                workWord2 = 240;
                Level37_7BD9CKeep(workWord2);
                Level37_7BD9CField(privateAddress20, unsigned char*, 0x2F) = workWord2;
                Level37_7BD9CField(privateAddress20, short*, 0x2A) = 0x44C;
                Level37_7BD9CField(privateAddress20, short*, 0x26) = 0;
                Level37_7BD9CField(privateAddress20, unsigned char*, 0x12) = 0xC0U;
                Level37_7BD9CKeep(workWord3);
                Level37_7BD9CCopyVector(privateAddress20, Level37_7BD9CField(workWord3, int*, 12));
                workWord2 = Level37_7BD9CField(privateAddress20, volatile unsigned char*, 0x12);
                workWord2 *= 2;
                Level37_7BD9CKeep(workWord2);
                workWord3 = Level37_7BD9CField((int)&Level37_7BD9C_D_80065920, short*, workWord2);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord2, "memory");
                argumentWord4 = Level37_7BD9CField(privateAddress20, volatile unsigned char*, 0x12);
                workWord2 = workWord3 * 16;
                MATCHING_KEEP2_VOLATILE(workWord2, argumentWord4);
                workWord2 -= workWord3;
                Level37_7BD9CKeep(workWord2);
                workWord2 = workWord2 * 32 - workWord3;
                Level37_7BD9CKeep(workWord2);
                workWord2 = workWord2 * 4 + workWord3;
                Level37_7BD9CKeep(workWord2);
                workWord2 *= 8;
                workWord3 = Level37_7BD9CField(privateAddress20, int*, 0);
                workWord2 >>= 12;
                workWord3 += workWord2;
                workWord2 = Level37_7BD9CField(privateAddress20, int*, 8);
                argumentWord4 *= 2;
                Level37_7BD9CField(privateAddress20, int*, 0) = workWord3;
                workWord3 =
                    Level37_7BD9CField((int)&Level37_7BD9C_D_800658A0, short*, argumentWord4);
                workWord2 += 4000;
                Level37_7BD9CField(privateAddress20, int*, 8) = workWord2;
                workWord2 = 70;
                Level37_7BD9CField(privateAddress20, short*, 16) = workWord2;
                workWord2 = workWord3 * 15;
                Level37_7BD9CKeep(workWord2);
                workWord2 = workWord2 * 32 - workWord3;
                Level37_7BD9CKeep(workWord2);
                workWord2 = workWord2 * 4 + workWord3;
                Level37_7BD9CKeep(workWord2);
                workWord2 *= 8;
                workWord3 = Level37_7BD9CField(privateAddress20, int*, 4);
                workWord2 >>= 12;
                workWord3 += workWord2;
                Level37_7BD9CField(privateAddress20, int*, 4) = workWord3;
                return;
            }
            temp_v0_2 = Level37_7BD9CField(privateAddress20, int*, 0x44) - 1;
            Level37_7BD9CField(privateAddress20, int*, 0x44) = temp_v0_2;
            if (temp_v0_2 <= 0) {
                Level37_7BD9CField(privateAddress20, int*, 0x44) = 2;
                workWord2 = Level37_7BD9CField(privateAddress20, int*, 60);
                workWord2++;
                Level37_7BD9CField(privateAddress20, int*, 60) = workWord2;
                temp_v1 = Level37_7BD9CField(privateAddress20, volatile int*, 60);
                if (temp_v1 == 3) {
                    Level37_7BD9CField(privateAddress20, int*, 0x44) = temp_v1;
                }
            }
            Level37_7BD9C_func_80038BF8(ownerAddress21, privateAddress20 + 0x20, 0, 5);
            Level37_7BD9CField(privateAddress20, short*, 0x26) = 0;
            Level37_7BD9CField(privateAddress20, signed char*, 0x2F) = 0;
            Level37_7BD9CField(privateAddress20, unsigned short*, 0x24) = 0x12CU;
            goto block_30;
        }
    block_30:
        Level37_7BD9CField(ownerAddress21, int*, 0x18) = 0;
        workWord2 = Level37_7BD9CField(privateAddress20, volatile int*, 0xDC);
        if (workWord2 == 0) {
            Level37_7BD9CField(privateAddress20, volatile int*, 0xDC) =
                (unsigned char*)(Level37_7BD9C_D_8006C58C +
                                 ((int)&Level37_7BD9C_main_TEXT_START + 2));
            workWord2 = Level37_7BD9CField(privateAddress20, volatile int*, 0xDC);
        }
        workWord3 = (int)&Level37_7BD9C_main_TEXT_END;
        Level37_7BD9CKeep(workWord3);
        argumentWord5 = 0;
        if ((unsigned int)workWord2 < (unsigned int)workWord3) {
            argumentWord6 = workWord3;
            Level37_7BD9CKeep(argumentWord6);
        loop_34:
            workWord3 = Level37_7BD9CField(privateAddress20, volatile int*, 0xDC);
            argumentWord4 = 0;
            if ((unsigned int)workWord3 < (unsigned int)argumentWord6) {
                Level37_7BD9CField(privateAddress20, volatile int*, 0xD8) =
                    (int)(Level37_7BD9CField(privateAddress20, volatile int*, 0xD8) ^
                          (Level37_7BD9CField(workWord3, unsigned char*, 0) << 8));
                do {
                    workWord3 = Level37_7BD9CField(privateAddress20, volatile int*, 0xD8);
                    if (workWord3 & 0x8000)
                        workWord2 = ((unsigned int)workWord3 << 1) ^ 0x8005U;
                    else
                        workWord2 = (unsigned int)workWord3 << 1;
                    Level37_7BD9CField(privateAddress20, volatile int*, 0xD8) = workWord2;
                    argumentWord4 += 1;
                } while (argumentWord4 < 8);
                workWord2 = Level37_7BD9CField(privateAddress20, volatile int*, 0xD8);
                workWord3 = Level37_7BD9CField(privateAddress20, volatile int*, 0xDC);
                workWord2 &= 3;
                workWord2++;
                workWord3 += workWord2;
                argumentWord5++;
                Level37_7BD9CField(privateAddress20, int*, 0xDC) = workWord3;
                if (argumentWord5 >= 0x40) {
                    workWord2 = (int)&Level37_7BD9C_main_TEXT_END;
                    Level37_7BD9CKeep(workWord2);
                    workWord2 = (unsigned int)workWord3 < (unsigned int)workWord2;
                    Level37_7BD9CKeep(workWord2);
                    argumentWord4 = privateAddress20 + 84;
                    if (!workWord2) {
                        goto block_41;
                    }
                } else {
                    goto loop_34;
                }
            } else {
            block_41:
                Level37_7BD9CField(privateAddress20, volatile int*, 0xDC) =
                    (int)&Level37_7BD9C_func_level_37_80074D90;
                goto block_42;
            }
        } else {
        block_42:
            argumentWord4 = privateAddress20 + 0x54;
        }
        Level37_7BD9CCountTimerDown(argumentWord4, 2);
        if ((Level37_7BD9CField(ownerAddress21, unsigned char*, 0x48) != 4) &&
            (Level37_7BD9C_D_8006E160 == 0)) {
            Level37_7BD9C_func_80013ACC(ownerAddress21, 0xD);
        }
        if ((Level37_7BD9CField(privateAddress20, int*, 0x6C) != 0) ||
            (Level37_7BD9CField((int)&Level37_7BD9C_D_80070328, int*, 0x1E8) != 0)) {
            workWord2 = (int)&Level37_7BD9C_D_80070328 + 464;
            Level37_7BD9CKeep(workWord2);
            workWord3 = 15;
            Level37_7BD9CKeep(workWord3);
            Level37_7BD9CField(workWord2, int*, 0) = workWord3;
            workWord3 = Level37_7BD9CField(workWord2, int*, 24);
            savedWord17 = workWord2 + 24;
            if (workWord3 == 0) {
                temp_a0_4 = Level37_7BD9CField(privateAddress20, int*, 0x64);
                if (temp_a0_4 != -1) {
                    Level37_7BD9C_func_80028154(temp_a0_4);
                }
                Level37_7BD9CField(privateAddress20, int*, 0x64) = -1;
                Level37_7BD9CField(privateAddress20, int*, 0x68) =
                    (short)Level37_7BD9C_func_8002803C(
                        0x15, 0x174, (int)&Level37_7BD9C_func_80027E40,
                        (int)&Level37_7BD9C_func_80027A60, (int)&Level37_7BD9C_func_80029904,
                        privateAddress20 + 0x6C, 0xA);
            } else {
                temp_a0_5 = Level37_7BD9CField(privateAddress20, int*, 0x68);
                if (temp_a0_5 != -1) {
                    Level37_7BD9C_func_80028154(temp_a0_5);
                }
                Level37_7BD9CField(privateAddress20, int*, 0x68) = -1;
                Level37_7BD9CField(privateAddress20, int*, 0x64) =
                    (short)Level37_7BD9C_func_8002803C(
                        0x15, 0x173, (int)&Level37_7BD9C_func_80027E40,
                        (int)&Level37_7BD9C_func_80027A60, (int)&Level37_7BD9C_func_80029904,
                        savedWord17, 0xC8);
            }
        } else {
            temp_a0_6 = Level37_7BD9CField(privateAddress20, int*, 0x64);
            Level37_7BD9CField(privateAddress20, signed char*, 0x70) = 0;
            if (temp_a0_6 != -1) {
                Level37_7BD9C_func_80028154(temp_a0_6);
            }
            temp_a0_7 = Level37_7BD9CField(privateAddress20, int*, 0x68);
            Level37_7BD9CField(privateAddress20, int*, 0x64) = -1;
            if (temp_a0_7 != -1) {
                Level37_7BD9C_func_80028154(temp_a0_7);
            }
            Level37_7BD9CField(privateAddress20, int*, 0x68) = -1;
        }
        workWord2 = Level37_7BD9CField(privateAddress20, volatile int*, 0xDC);
        workWord3 = (int)&Level37_7BD9C_func_level_37_80074D90;
        workWord2 = (unsigned int)workWord2 < (unsigned int)workWord3;
        savedWord16 = privateAddress20 + 220;
        if (!workWord2) {
            MATCHING_OBSERVE_VOLATILE_CLOBBER(savedWord16, "$2");
            argumentWord5 = 0;
            Level37_7BD9CKeep(argumentWord5);
            argumentWord6 = (int)&Level37_7BD9C_D_level_37_8008BA38;
            Level37_7BD9CKeep(argumentWord6);
        loop_62:
            workWord3 = Level37_7BD9CField(privateAddress20, volatile int*, 0xDC);
            argumentWord4 = 0;
            if ((unsigned int)workWord3 < (unsigned int)argumentWord6) {
                Level37_7BD9CField(privateAddress20, volatile int*, 0xD8) =
                    (int)(Level37_7BD9CField(privateAddress20, volatile int*, 0xD8) ^
                          (Level37_7BD9CField(workWord3, unsigned char*, 0) << 8));
                do {
                    workWord3 = Level37_7BD9CField(privateAddress20, volatile int*, 0xD8);
                    if (workWord3 & 0x8000)
                        workWord2 = ((unsigned int)workWord3 << 1) ^ 0x8005U;
                    else
                        workWord2 = (unsigned int)workWord3 << 1;
                    Level37_7BD9CField(privateAddress20, volatile int*, 0xD8) = workWord2;
                    argumentWord4 += 1;
                } while (argumentWord4 < 8);
                argumentWord5 += 1;
                Level37_7BD9CField(privateAddress20, volatile int*, 0xDC) =
                    (unsigned char*)(Level37_7BD9CField(privateAddress20, volatile int*, 0xDC) + 1);
                if (argumentWord5 < 0x40) {
                    goto loop_62;
                }
            }
            savedWord16 = privateAddress20 + 0xDC;
        }
        Level37_7BD9C_func_8003B7B4(savedWord16, 4, (int)&Level37_7BD9C_D_8006D088);
        Level37_7BD9C_func_8003B7B4(savedWord16, 4, (int)&Level37_7BD9C_D_8006C7F8);
        savedWord16 = privateAddress20 + 0xD8;
        Level37_7BD9C_func_8003B7B4(savedWord16, 4, (int)&Level37_7BD9C_D_8006D088);
        Level37_7BD9C_func_8003B7B4(savedWord16, 4, (int)&Level37_7BD9C_D_8006C7F8);
        temp_v1_7 = Level37_7BD9CField(ownerAddress21, unsigned char*, 0x48);
        if ((temp_v1_7 != 1) && (temp_v1_7 != 4) &&
            (Level37_7BD9CCountTimerDown(privateAddress20 + 0xD0, 4) != 0)) {
            savedWord17 = 0;
            savedWord18 = 1;
            MATCHING_OBSERVE2_VOLATILE_CLOBBER(savedWord17, savedWord18, "$16");
            savedWord16 = privateAddress20;
            do {
                if (Level37_7BD9CField(savedWord16, int*, 0xBC) == 0) {
                    temp_v0_4 = Level37_7BD9CSpawnMoby(0x18F, ownerAddress21);
                    if (temp_v0_4 != 0) {
                        temp_v0_5 = Level37_7BD9CField(temp_v0_4, int*, 0);
                        Level37_7BD9CField(savedWord16, int*, 0xBC) = temp_v0_4;
                        Level37_7BD9CField(temp_v0_5, int*, 4) = savedWord17;
                        Level37_7BD9CField(temp_v0_5, int*, 0) = savedWord18;
                    }
                }
                savedWord17 += 1;
                savedWord16 += 4;
            } while (savedWord17 < 5);
        }
        argumentWord5 = 0;
        Level37_7BD9CKeep(argumentWord5);
        argumentWord4 = privateAddress20;
        do {
            MATCHING_OBSERVE_VOLATILE(argumentWord4);
            temp_v1_8 = Level37_7BD9CField(argumentWord4, int*, 0xBC);
            if (temp_v1_8 != 0) {
                Level37_7BD9CField(temp_v1_8, int*, 0xC) =
                    (int)Level37_7BD9CField(ownerAddress21, int*, 0xC);
                Level37_7BD9CField(Level37_7BD9CField(argumentWord4, int*, 0xBC), int*, 0x10) =
                    (int)Level37_7BD9CField(ownerAddress21, int*, 0x10);
            }
            argumentWord5 += 1;
            argumentWord4 += 4;
        } while (argumentWord5 < 5);
        if ((Level37_7BD9CField(privateAddress20, volatile int*, 0xDC) ==
             (int)&Level37_7BD9C_D_level_37_8008BA38) &&
            (Level37_7BD9CField(privateAddress20, volatile int*, 0xD8) != 0)) {
            Level37_7BD9C_D_8006580C = 0;
            Level37_7BD9C_D_80065834 = 0;
            Level37_7BD9CField(privateAddress20, volatile int*, 0xD8) = 0;
        }
        temp_v1_9 = Level37_7BD9CField(ownerAddress21, unsigned char*, 0x48);
        switch (temp_v1_9) {
            case 0:
                savedWord16 = 0;
                Level37_7BD9CTurnMobyTowardPlayer(ownerAddress21, 4, 0, 0);
                argumentWord4 = (int)&Level37_7BD9C_D_8006E788;
                Level37_7BD9CKeep(argumentWord4);
                var_v1 = Level37_7BD9CField(argumentWord4, int*, 0);
                argumentWord4 += 4;
                savedWord17 = 4;
                if (var_v1 != 0) {
                    do {
                        MATCHING_OBSERVE_VOLATILE(argumentWord4);
                        temp_v0_6 = Level37_7BD9CField(var_v1, short*, 0x36);
                        if (temp_v0_6 == 0xB5) {
                            savedWord16 += 1;
                        }
                        if (temp_v0_6 == 0x2B9) {
                            savedWord16 += 1;
                        }
                        if (temp_v0_6 == 0xC1) {
                            savedWord16 += 1;
                        }
                        if (temp_v0_6 == 0x1B7) {
                            savedWord16 += savedWord17;
                        }
                        if ((temp_v0_6 == 0x10B) &&
                            (Level37_7BD9CField(var_v1, unsigned char*, 0x48) != 9)) {
                            savedWord16 += savedWord17;
                        }
                        var_v1 = Level37_7BD9CField(argumentWord4, int*, 0);
                        argumentWord4 += 4;
                    } while (var_v1 != 0);
                }
                if (Level37_7BD9CField(privateAddress20, short*, 0x54) == 0) {
                    argumentWord4 = 0;
                    if (Level37_7BD9CField(privateAddress20, unsigned char*, 0x71) != 0) {
                        argumentWord5 = 2;
                        Level37_7BD9CKeep(argumentWord5);
                        workWord3 = privateAddress20;
                        do {
                            MATCHING_OBSERVE_VOLATILE(workWord3);
                            temp_v0_7 = Level37_7BD9CField(workWord3, int*, 0xBC);
                            if (temp_v0_7 != 0) {
                                Level37_7BD9CField(temp_v0_7, unsigned char*, 72) = argumentWord5;
                                Level37_7BD9CField(workWord3, int*, 0xBC) = 0;
                            }
                            argumentWord4 += 1;
                            workWord3 += 4;
                        } while (argumentWord4 < 5);
                        argumentWord6 = 0;
                        __asm__ volatile("" ::"r"(argumentWord6) : "$3", "memory");
                        workWord3 = Level37_7BD9CField(privateAddress20, int*, 56);
                        workWord2 = 120;
                        Level37_7BD9CField(privateAddress20, int*, 208) = workWord2;
                        Level37_7BD9CField(privateAddress20, unsigned char*, 113) = 0;
                        argumentWord7 = Level37_7BD9CField(ownerAddress21, int*, 12);
                        workWord2 = Level37_7BD9CField(workWord3, int*, 12);
                        workWord3 = Level37_7BD9CField(ownerAddress21, int*, 16);
                        argumentWord4 = Level37_7BD9CField(workWord2, int*, 0);
                        argumentWord5 = Level37_7BD9CField(workWord2, int*, 4);
                        argumentWord4 = argumentWord7 - argumentWord4;
                        argumentWord5 = workWord3 - argumentWord5;
                        workWord2 = Level37_7BD9CPlanarHeadingLookup(argumentWord4, argumentWord5,
                                                                     argumentWord6);
                        argumentWord4 = 48;
                        argumentWord5 = 100;
                        MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
                        savedWord16 = workWord2;
                        workWord2 = Level37_7BD9CRandSignedBetween(argumentWord4, argumentWord5);
                        argumentWord4 = ownerAddress21;
                        argumentWord5 = 1;
                        __asm__(""
                                : "=r"(workWord2)
                                : "0"(workWord2), "r"(argumentWord4), "r"(argumentWord5));
                        savedWord16 += workWord2;
                        Level37_7BD9CKeep(savedWord16);
                        workWord2 = 1;
                        Level37_7BD9CField(privateAddress20, unsigned char*, 114) = savedWord16;
                        Level37_7BD9CField(argumentWord4, unsigned char*, 72) = workWord2;
                        Level37_7BD9CRequestMobyAnimation(argumentWord4, argumentWord5);
                        return;
                    }
                    workWord2 = savedWord16 < savedWord17;
                    __asm__ volatile("" : "=r"(workWord2) : "0"(workWord2), "r"(savedWord17));
                    goto block_108;
                } else {
                    workWord2 = savedWord16 < savedWord17;
                }
            block_108:
                if (workWord2 == 0) {
                    if (Level37_7BD9CField(privateAddress20, short*, 0x54) < 0x78) {
                        Level37_7BD9CField(privateAddress20, short*, 0x54) = 0x78;
                    }
                    goto block_222;
                }
                if (Level37_7BD9CField(privateAddress20, unsigned char*, 0x71) == 0) {
                    if (Level37_7BD9CAbsoluteByteAngleDelta(
                            Level37_7BD9CField(ownerAddress21, unsigned char*, 0x46),
                            Level37_7BD9CPlanarHeadingLookup(
                                Level37_7BD9CField((int)&Level37_7BD9C_D_80070328, int*, 0) -
                                    Level37_7BD9CField(ownerAddress21, int*, 0xC),
                                Level37_7BD9CField((int)&Level37_7BD9C_D_80070328, int*, 4) -
                                    Level37_7BD9CField(ownerAddress21, int*, 0x10),
                                0)) < 0xC) {
                        workWord2 = Level37_7BD9CRandBetween(0, 100);
                        workWord2 = workWord2 < 61;
                        Level37_7BD9CField(privateAddress20, unsigned char*, 115) = 0;
                        if (!workWord2) {
                            Level37_7BD9CField(ownerAddress21, unsigned char*, 0x48) = 3U;
                            Level37_7BD9CRequestMobyAnimation(ownerAddress21, 3);
                            return;
                        }
                        Level37_7BD9CField(ownerAddress21, unsigned char*, 0x48) = 2U;
                        Level37_7BD9CRequestMobyAnimation(ownerAddress21, 2);
                        return;
                    }
                    default:
                    block_222:
                        goto block_223;
                }
                goto block_223;
            case 1:
                argumentWord7 = Level37_7BD9CField(ownerAddress21, int*, 0xC);
                temp_v0_9 =
                    Level37_7BD9CField(Level37_7BD9CField(privateAddress20, int*, 0x38), int*, 0xC);
                workWord2 = Level37_7BD9CPlanarHeadingLookup(
                    argumentWord7 - Level37_7BD9CField(temp_v0_9, int*, 0),
                    Level37_7BD9CField(ownerAddress21, int*, 16) -
                        Level37_7BD9CField(temp_v0_9, int*, 4),
                    0);
                argumentWord4 = ownerAddress21;
                argumentWord5 = Level37_7BD9CField(privateAddress20, int*, 56);
                argumentWord7 = Level37_7BD9CField(privateAddress20, unsigned char*, 114);
                MATCHING_OBSERVE3_VOLATILE(argumentWord4, argumentWord5, argumentWord7);
                Level37_7BD9Cunk_ovlheader_80074314(
                    argumentWord4, Level37_7BD9CField(argumentWord5, volatile int*, 12), 0x3DDC,
                    argumentWord7, 4, 350, 5, 32, 255, 255, 0, 0, ({
                        MATCHING_KEEP(workWord2);
                        retainedCallbackHeading = workWord2;
                        1;
                    }));
                savedWord16 = retainedCallbackHeading;
                var_v0_4 = Level37_7BD9CAbsoluteByteAngleDelta(
                               savedWord16,
                               Level37_7BD9CField(privateAddress20, unsigned char*, 0x72)) < 8;
                goto block_173;
            case 3:
                if ((Level37_7BD9C_func_80055E84(ownerAddress21) >= 0x23) &&
                    (Level37_7BD9CField(privateAddress20, unsigned char*, 0x73) == 0)) {
                    savedWord19 = 20;
                    argumentWord4 = 0;
                    argumentWord5 = 2;
                    Level37_7BD9CKeep(argumentWord5);
                    workWord3 = privateAddress20;
                    do {
                        MATCHING_OBSERVE_VOLATILE(workWord3);
                        temp_v0_10 = Level37_7BD9CField(workWord3, int*, 0xBC);
                        if (temp_v0_10 != 0) {
                            Level37_7BD9CField(temp_v0_10, unsigned char*, 72) = argumentWord5;
                            Level37_7BD9CField(workWord3, int*, 0xBC) = 0;
                        }
                        argumentWord4 += 1;
                        workWord3 += 4;
                    } while (argumentWord4 < 5);
                    workWord2 = 120;
                    Level37_7BD9CKeep(workWord2);
                    argumentWord4 = ownerAddress21;
                    argumentWord5 = 4;
                    MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
                    Level37_7BD9CField(privateAddress20, int*, 208) = workWord2;
                    Level37_7BD9CField(privateAddress20, short*, 0x54) = 0xF0;
                    Level37_7BD9CField(privateAddress20, unsigned char*, 0x71) = 1U;
                    Level37_7BD9CField(privateAddress20, unsigned char*, 0x73) = 1U;
                    Level37_7BD9CRefreshMobySpatialGridAndBasis(ownerAddress21, 4);
                    Level37_7BD9CInterpolateMobyVertex(ownerAddress21, 8, &originalFrame.sp58);
                    Level37_7BD9CInterpolateMobyVertex(ownerAddress21, 9, &originalFrame.sp68);
                    Level37_7BD9CAddVector(&originalFrame.sp48, &originalFrame.sp58,
                                           &originalFrame.sp68);
                    Level37_7BD9CShiftVectorRightTowardZero(&originalFrame.sp48, 1);
                    savedWord16 = 0;
                    if (savedWord19 != 0) {
                        workWord2 = (Level37_7BD9C_D_8006C578 - Level37_7BD9C_D_8006C574) < 21;
                        savedWord17 = 63;
                        if (!workWord2) {
                        loop_125:
                            if (Level37_7BD9C_D_8006C7E8 >= 0x4E21) {
                                temp_v0_11 = Level37_7BD9CSpawnMoby(0x2B7, ownerAddress21);
                                if (temp_v0_11 != 0) {
                                    Level37_7BD9CField(Level37_7BD9CField(temp_v0_11, int*, 0),
                                                       short*, 8) = savedWord16;
                                    Level37_7BD9CField(temp_v0_11, unsigned char*, 76) =
                                        savedWord17;
                                    Level37_7BD9CField(temp_v0_11, unsigned char*, 78) =
                                        savedWord17;
                                }
                                savedWord16 += 1;
                                if (savedWord16 < savedWord19) {
                                    if ((Level37_7BD9C_D_8006C578 - Level37_7BD9C_D_8006C574) <
                                        0x15) {
                                    } else {
                                        goto loop_125;
                                    }
                                }
                            }
                        }
                    }
                }
                goto block_172;
            case 2:
                workWord2 = Level37_7BD9C_func_80055E84(ownerAddress21);
                argumentWord6 = 0;
                __asm__("" : "=r"(workWord2) : "0"(workWord2), "r"(argumentWord6));
                savedWord16 = workWord2;
                workWord3 = Level37_7BD9CField(privateAddress20, int*, 56);
                argumentWord4 = Level37_7BD9CField(ownerAddress21, int*, 12);
                workWord3 = Level37_7BD9CField(workWord3, int*, 12);
                argumentWord5 = Level37_7BD9CField(ownerAddress21, int*, 16);
                argumentWord7 = Level37_7BD9CField(workWord3, int*, 0);
                workWord3 = Level37_7BD9CField(workWord3, int*, 4);
                argumentWord4 = argumentWord7 - argumentWord4;
                argumentWord5 = workWord3 - argumentWord5;
                workWord2 =
                    Level37_7BD9CPlanarHeadingLookup(argumentWord4, argumentWord5, argumentWord6);
                argumentWord4 = ownerAddress21;
                argumentWord6 = 5;
                originalFrame.spD8 = workWord2;
                argumentWord5 = Level37_7BD9CField((int)&originalFrame.spD8, volatile int*, 0);
                argumentWord7 = 0;
                Level37_7BD9CTurnMobyTowardHeading(argumentWord4, argumentWord5, argumentWord6,
                                                   argumentWord7, 0, 0);
                if ((savedWord16 >= 0x16) &&
                    (Level37_7BD9CField(privateAddress20, unsigned char*, 0x73) == 0)) {
                    workWord11 = 80;
                    Level37_7BD9CKeep(workWord11);
                    selectedSpawnFlags = 0;
                    savedWord22 = 0;
                    workWord12 = 1;
                    Level37_7BD9CKeep(workWord12);
                    savedWord23 = 20;
                    originalFrame.spE0 = workWord11;
                    originalFrame.spE8 = workWord12;
                    workWord2 = Level37_7BD9C_rand();
                    workWord2 &= 1;
                    argumentWord4 = 0;
                    if (workWord2) {
                        workWord11 = -1;
                        Level37_7BD9CKeep(workWord11);
                        originalFrame.spE8 = workWord11;
                    }
                    argumentWord5 = 2;
                    Level37_7BD9CKeep(argumentWord5);
                    workWord3 = privateAddress20;
                    do {
                        MATCHING_OBSERVE_VOLATILE(workWord3);
                        temp_v0_12 = Level37_7BD9CField(workWord3, int*, 0xBC);
                        if (temp_v0_12 != 0) {
                            Level37_7BD9CField(temp_v0_12, unsigned char*, 72) = argumentWord5;
                            Level37_7BD9CField(workWord3, int*, 0xBC) = 0;
                        }
                        MATCHING_BARRIER_VOLATILE("memory");
                        argumentWord4++;
                        workWord3 += 4;
                    } while (argumentWord4 < 5);
                    argumentWord4 = ownerAddress21;
                    argumentWord5 = 4;
                    MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
                    workWord2 = 120;
                    Level37_7BD9CKeep(workWord2);
                    Level37_7BD9CField(privateAddress20, int*, 208) = workWord2;
                    workWord2 = 450;
                    Level37_7BD9CKeep(workWord2);
                    savedWord19 = 1;
                    Level37_7BD9CKeep(savedWord19);
                    Level37_7BD9CField(privateAddress20, short*, 84) = workWord2;
                    Level37_7BD9CField(privateAddress20, unsigned char*, 113) = savedWord19;
                    Level37_7BD9CRefreshMobySpatialGridAndBasis(argumentWord4, argumentWord5);
                    Level37_7BD9CInterpolateMobyVertex(ownerAddress21, 8, &originalFrame.spA0);
                    Level37_7BD9CInterpolateMobyVertex(ownerAddress21, 9, &originalFrame.spB0);
                    Level37_7BD9CAddVector(&originalFrame.sp58, &originalFrame.spA0,
                                           &originalFrame.spB0);
                    Level37_7BD9CShiftVectorRightTowardZero(&originalFrame.sp58, 1);
                    MATCHING_KEEP_VOLATILE(selectedSpawnFlags);
                    workWord3 = Level37_7BD9CField(privateAddress20, int*, 60);
                    workWord2 = 1;
                    Level37_7BD9CField(privateAddress20, unsigned char*, 115) = savedWord19;
                    if (workWord3 == workWord2)
                        goto actor1598Select1;
                    workWord2 = workWord3 < 2;
                    Level37_7BD9CKeep(workWord2);
                    if (!workWord2)
                        goto actor1598SelectUpper;
                    workWord2 = 3;
                    if (workWord3 == 0)
                        goto actor1598Select0;
                    goto actor1598AfterCount;
                actor1598SelectUpper:
                    workWord2 = 2;
                    if (workWord3 == workWord2)
                        goto actor1598Select2;
                    workWord2 = 3;
                    argumentWord4 = 0;
                    if (workWord3 == workWord2)
                        goto actor1598Select3;
                    goto actor1598AfterCount;
                actor1598Select0:
                    Level37_7BD9CKeep(workWord3);
                    selectedSpawnFlags = 0;
                    goto actor1598CountEntry;
                actor1598Select1:
                    argumentWord4 = 0;
                    workWord2 = Level37_7BD9CRandBetween(argumentWord4, 100);
                    workWord2 = workWord2 < 41;
                    selectedSpawnFlags = 0;
                    if (!workWord2)
                        goto actor1598FlagOne;
                    argumentWord4 = 2;
                    goto actor1598CountCall;
                actor1598Select2:
                    argumentWord4 = 0;
                    workWord2 = Level37_7BD9CRandBetween(argumentWord4, 100);
                    workWord2 = workWord2 < 41;
                    selectedSpawnFlags = 2;
                    if (!workWord2)
                        goto actor1598OneCount;
                actor1598FlagOne:
                    selectedSpawnFlags = 1;
                actor1598CountEntry:
                    argumentWord4 = 2;
                actor1598CountCall:
                    workWord2 = Level37_7BD9CRandBetween(argumentWord4, 4);
                    savedWord22 = workWord2;
                    goto actor1598CountFinished;
                actor1598Select3:
                    workWord2 = Level37_7BD9CRandBetween(argumentWord4, 100);
                    workWord2 = workWord2 < 41;
                    selectedSpawnFlags = 2;
                    if (workWord2)
                        goto actor1598OneCount;
                    selectedSpawnFlags = 3;
                actor1598OneCount:
                    savedWord22 = 1;
                actor1598CountFinished:
                    workWord2 = 3;
                actor1598AfterCount:
                    if (selectedSpawnFlags == 3) {
                        savedWord23 = 0xB4;
                    }
                    workWord2 = 1;
                    argumentWord4 = 0;
                    if (selectedSpawnFlags == workWord2) {
                        workWord12 = originalFrame.spE0;
                        workWord12 += 20;
                        originalFrame.spE0 = workWord12;
                    }
                    workWord2 = Level37_7BD9CRandBetween(argumentWord4, savedWord22 - 1);
                    workWord3 = workWord2;
                    savedWord18 = 0;
                    if (savedWord22 > 0) {
                        argumentWord4 = (int)&originalFrame.sp38;
                    actor1598RingStore:
                        MATCHING_OBSERVE2_VOLATILE(workWord3, savedWord23);
                        workWord2 = workWord3 * 4;
                        workWord2 += argumentWord4;
                        savedWord18++;
                        Level37_7BD9CField(workWord2, int*, 64) = savedWord23;
                        workWord2 = workWord3 + savedWord22;
                        workWord11 = originalFrame.spE0;
                        workWord12 = originalFrame.spE8;
                        Level37_7BD9CKeep(workWord11);
                        Level37_7BD9CKeep(workWord12);
                        workWord2 += workWord12;
                        workWord3 = workWord2 % savedWord22;
                        workWord2 = savedWord18 < savedWord22;
                        savedWord23 += workWord11;
                        if (workWord2)
                            goto actor1598RingStore;
                    }
                    MATCHING_OBSERVE_VOLATILE(savedWord22);
                    savedWord18 = 0;
                    if (savedWord22 > 0) {
                        workWord11 = originalFrame.spD8;
                        workWord11 += 78;
                        Level37_7BD9CKeep(workWord11);
                        originalFrame.spF0 = workWord11;
                        __asm__ volatile("" ::"r"(workWord11) : "$12", "memory");
                        workWord12 = (int)&originalFrame.spC0;
                        Level37_7BD9CKeep(workWord12);
                        Level37_7BD9CF8 = workWord12;
                        do {
                            savedWord17 = Level37_7BD9CSpawnMoby(181, ownerAddress21);
                            Level37_7BD9CKeep(savedWord17);
                            workWord3 = savedWord22 + 1;
                            if (savedWord17 != 0) {
                                workWord2 = 100;
                                workWord2 = workWord2 / workWord3;
                                workWord3 = savedWord18 + 1;
                                workWord2 &= 255;
                                Level37_7BD9CStart(completeProduct6, workWord2, workWord3);
                                savedWord16 = 9336;
                                Level37_7BD9CKeep(savedWord16);
                                argumentWord4 =
                                    Level37_7BD9CField((int)&originalFrame.spD8, volatile int*, 0);
                                workWord11 =
                                    Level37_7BD9CField((int)&originalFrame.spF0, volatile int*, 0);
                                Level37_7BD9CKeep(workWord11);
                                savedWord19 = Level37_7BD9CField(savedWord17, int*, 0);
                                MATCHING_OBSERVE2_VOLATILE_CLOBBER(argumentWord4, workWord11,
                                                                   "memory");
                                workWord12 = (int)completeProduct6.words.low;
                                Level37_7BD9CKeep(workWord12);
                                savedWord23 = workWord11 + workWord12;
                                workWord2 = Level37_7BD9CAbsoluteByteAngleDelta(argumentWord4,
                                                                                savedWord23 & 255);
                                workWord3 = 128;
                                workWord3 -= workWord2;
                                workWord2 = workWord3 * 5;
                                workWord2 *= 4;
                                savedWord16 -= workWord2;
                                Level37_7BD9CKeep(savedWord16);
                                workWord2 = 3;
                                argumentWord4 = savedWord17;
                                if (selectedSpawnFlags != workWord2)
                                    goto actor1598ClassReady;
                                workWord2 = Level37_7BD9CField(savedWord17, unsigned char*, 60);
                                workWord11 = 2;
                                Level37_7BD9CKeep(workWord11);
                                workWord3 = 1;
                                if (workWord2 == workWord11)
                                    goto actor1598ClassReady;
                                workWord2 = Level37_7BD9CField(savedWord17, short*, 54);
                                Level37_7BD9CField(savedWord17, unsigned char*, 66) = 0;
                                workWord2 *= 4;
                                workWord2 = Level37_7BD9CField((int)&Level37_7BD9C_D_8006EE2C, int*,
                                                               workWord2);
                                workWord2 = Level37_7BD9CField(workWord2, int*, 68);
                                workWord2 = Level37_7BD9CField(workWord2, unsigned char*, 0);
                                __asm__ volatile("" ::"r"(savedWord17) : "$11", "$12", "memory");
                                workWord12 = 2;
                                Level37_7BD9CKeep(workWord12);
                                workWord11 = 2;
                                Level37_7BD9CKeep(workWord11);
                                Level37_7BD9CField(savedWord17, volatile unsigned char*, 60) =
                                    workWord12;
                                Level37_7BD9CField(savedWord17, volatile unsigned char*, 61) =
                                    workWord11;
                                Level37_7BD9CField(savedWord17, volatile unsigned char*, 62) = 0;
                                Level37_7BD9CField(savedWord17, volatile unsigned char*, 63) =
                                    workWord3;
                                workWord2 = (unsigned int)workWord2 < 2;
                                workWord2 ^= 1;
                                workWord2 = -workWord2;
                                workWord2 &= 48;
                                Level37_7BD9CField(savedWord17, unsigned char*, 64) = workWord2;
                                __asm__ volatile("" ::"r"(savedWord17) : "$4", "memory");
                                argumentWord4 = savedWord17;
                            actor1598ClassReady:
                                Level37_7BD9CRefreshMobySpatialGridAndBasis(argumentWord4, 1);
                                workWord2 = 63;
                                workWord3 = savedWord23 & 255;
                                workWord3 *= 2;
                                Level37_7BD9CField(savedWord17, unsigned char*, 76) = workWord2;
                                Level37_7BD9CField(savedWord17, unsigned char*, 78) = workWord2;
                                workWord2 = Level37_7BD9CField((int)&Level37_7BD9C_D_80065920,
                                                               short*, workWord3);
                                Level37_7BD9CKeep(workWord3);
                                Level37_7BD9CStart(completeProduct7, workWord2, savedWord16);
                                workWord12 = (int)completeProduct7.words.low;
                                Level37_7BD9CKeep(workWord12);
                                workWord2 = workWord12 >> 12;
                                originalFrame.spC0 = workWord2;
                                workWord2 = Level37_7BD9CField((int)&Level37_7BD9C_D_800658A0,
                                                               short*, workWord3);
                                Level37_7BD9CStart(completeProduct8, workWord2, savedWord16);
                                argumentWord4 = Level37_7BD9CF8;
                                originalFrame.spC8 = 0;
                                __asm__(""
                                        : "=x"(completeProduct8.full)
                                        : "0"(completeProduct8.full), "m"(originalFrame.spC8));
                                workWord11 = (int)completeProduct8.words.low;
                                Level37_7BD9CKeep(workWord11);
                                workWord2 = workWord11 >> 12;
                                originalFrame.spC4 = workWord2;
                                workWord2 = Level37_7BD9CField(privateAddress20, int*, 56);
                                argumentWord5 = Level37_7BD9CF8;
                                argumentWord6 = Level37_7BD9CField(workWord2, int*, 12);
                                savedWord16 = savedWord17 + 12;
                                Level37_7BD9CAddVector(argumentWord4, argumentWord5, argumentWord6);
                                Level37_7BD9CCopyVector(savedWord16, &originalFrame.sp58);
                                workWord2 = (int)0x55550000;
                                Level37_7BD9CKeep(workWord2);
                                workWord12 = originalFrame.spE0;
                                Level37_7BD9CKeep(workWord12);
                                workWord2 |= 0x5556;
                                Level37_7BD9CKeep(workWord2);
                                Level37_7BD9CStart(completeDivisionProduct3, workWord12, workWord2);
                                argumentWord4 = 0;
                                Level37_7BD9CField(savedWord17, unsigned char*, 73) =
                                    selectedSpawnFlags;
                                __asm__(""
                                        : "=x"(completeDivisionProduct3.full)
                                        : "0"(completeDivisionProduct3.full), "r"(argumentWord4),
                                          "m"(Level37_7BD9CField(savedWord17, unsigned char*, 73)));
                                argumentWord5 = workWord12 >> 31;
                                divisionHighWord = completeDivisionProduct3.words.high;
                                Level37_7BD9CKeep(divisionHighWord);
                                argumentWord5 = divisionHighWord - argumentWord5;
                                workWord2 =
                                    Level37_7BD9CRandSignedBetween(argumentWord4, argumentWord5);
                                argumentWord6 = 0;
                                Level37_7BD9CKeep(argumentWord6);
                                {
                                    int base = (int)&originalFrame.sp78 - 120;
                                    MATCHING_OBSERVE(base);
                                    workWord3 = savedWord18 * 4;
                                    workWord3 = base + workWord3;
                                    Level37_7BD9CKeep(workWord3);
                                }
                                argumentWord4 = Level37_7BD9CField(workWord3, int*, 120);
                                workWord3 = 300;
                                Level37_7BD9CField(savedWord19, short*, 0) = workWord3;
                                argumentWord4 += workWord2;
                                Level37_7BD9CKeep(argumentWord4);
                                Level37_7BD9CField(savedWord19, int*, 8) = argumentWord4;
                                workWord3 = originalFrame.spC0;
                                argumentWord4 = Level37_7BD9CField(savedWord17, int*, 12);
                                workWord2 = originalFrame.spC4;
                                argumentWord5 = Level37_7BD9CField(savedWord17, int*, 16);
                                argumentWord4 = workWord3 - argumentWord4;
                                argumentWord5 = workWord2 - argumentWord5;
                                workWord2 = Level37_7BD9CPlanarHeadingLookup(
                                    argumentWord4, argumentWord5, argumentWord6);
                                argumentWord4 = savedWord16;
                                Level37_7BD9CKeep(argumentWord4);
                                argumentWord5 = Level37_7BD9CF8;
                                argumentWord6 = Level37_7BD9CField(savedWord19, short*, 0);
                                __asm__ volatile("" ::"r"(argumentWord5) : "$7", "memory");
                                argumentWord7 = -16;
                                MATCHING_OBSERVE2_VOLATILE(argumentWord6, argumentWord7);
                                Level37_7BD9CField(savedWord19, unsigned char*, 4) = workWord2;
                                workWord2 = -16;
                                Level37_7BD9CField(savedWord19, short*, 6) = workWord2;
                                workWord2 = (int)&originalFrame.spD0;
                                workWord2 = Level37_7BD9C_func_800365E4(
                                    argumentWord4, argumentWord5, argumentWord6, argumentWord7,
                                    workWord2);
                                Level37_7BD9CField(savedWord19, short*, 2) = workWord2;
                            }
                            savedWord18 += 1;
                        } while (savedWord18 < savedWord22);
                    }
                }
                goto block_172;
            block_172:
                var_v0_4 = Level37_7BD9C_D_8006C770;
            block_173:
                if (var_v0_4 != 0) {
                    Level37_7BD9CField(ownerAddress21, unsigned char*, 0x48) = 0U;
                    Level37_7BD9CRequestMobyAnimation(ownerAddress21, 0);
                }
                goto block_223;
            case 5:
                workWord2 = savedWord19 < 0x4F71;
                if (!workWord2) {
                    Level37_7BD9CField(privateAddress20, unsigned short*, 0x24) = 0U;
                }
                if (Level37_7BD9C_func_80035194(ownerAddress21, privateAddress20 + 0x20) == 0x100) {
                    Level37_7BD9CField(ownerAddress21, signed char*, 0x49) = 0;
                    Level37_7BD9CField(ownerAddress21, unsigned char*, 0x48) = 0U;
                    Level37_7BD9CRequestMobyAnimation(ownerAddress21, 0);
                }
                goto block_223;
            case 4:
                retainedFrameAddress = (int)&originalFrame.sp78;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(retainedFrameAddress, "$12");
                workWord12 = ownerAddress21 + 12;
                originalFrame.sp100 = workWord12;
                MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord12, "memory");
                argumentWord5 = originalFrame.sp100;
                savedWord19 = Level37_7BD9CField(privateAddress20, unsigned char*, 18);
                Level37_7BD9CCopyVector(retainedFrameAddress, argumentWord5);
                savedWord22 = (int)&originalFrame.sp68;
                argumentWord4 = savedWord22;
                argumentWord5 = privateAddress20;
                workWord2 = originalFrame.sp80;
                __asm__ volatile("" ::"r"(argumentWord5) : "$16", "memory");
                savedWord16 = savedWord19 - 128;
                workWord2 += 1500;
                originalFrame.sp80 = workWord2;
                Level37_7BD9CCopyVector(argumentWord4, argumentWord5);
                argumentWord4 = savedWord16 & 255;
                argumentWord4 *= 2;
                workWord2 =
                    Level37_7BD9CField((int)&Level37_7BD9C_D_80065920, short*, argumentWord4);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord2, "$23");
                savedWord23 = 8000;
                Level37_7BD9CKeep(savedWord23);
                Level37_7BD9CKeep(workWord2);
                Level37_7BD9CStart(completeProduct0, workWord2, savedWord23);
                workWord2 = originalFrame.sp68;
                workWord11 = (int)completeProduct0.words.low;
                Level37_7BD9CKeep(workWord11);
                workWord3 = workWord11 >> 12;
                workWord2 += workWord3;
                originalFrame.sp68 = workWord2;
                workWord2 =
                    Level37_7BD9CField((int)&Level37_7BD9C_D_800658A0, short*, argumentWord4);
                Level37_7BD9CStart(completeProduct3, workWord2, savedWord23);
                savedWord17 = (int)&Level37_7BD9C_D_80065920;
                savedWord18 = (int)&Level37_7BD9C_D_800658A0;
                workWord2 = originalFrame.sp70;
                workWord2 += 1000;
                originalFrame.sp70 = workWord2;
                workWord2 = originalFrame.sp6C;
                __asm__(""
                        : "=x"(completeProduct3.full)
                        : "0"(completeProduct3.full), "r"(workWord2), "m"(originalFrame.sp70));
                workWord12 = (int)completeProduct3.words.low;
                Level37_7BD9CKeep(workWord12);
                workWord3 = workWord12 >> 12;
                workWord2 += workWord3;
                originalFrame.sp6C = workWord2;
                temp_v1_13 = Level37_7BD9CField(privateAddress20, int*, 0xC);
                switch (temp_v1_13) {
                    case 0:
                        Level37_7BD9C_func_80035194(ownerAddress21, privateAddress20 + 0x20);
                        if (Level37_7BD9CCountTimerDown(privateAddress20 + 0x10, 2) == 2) {
                            Level37_7BD9CField(privateAddress20, short*, 0x10) = 0x3C;
                            Level37_7BD9C_func_80013AE4(savedWord22, retainedFrameAddress);
                            if (Level37_7BD9CField((int)&Level37_7BD9C_D_80070328, int*, 0x280) <
                                0) {
                                Level37_7BD9CField((int)&Level37_7BD9C_D_80070328, int*, 0x280) = 0;
                            }
                            workWord2 = Level37_7BD9CField(privateAddress20, int*, 12);
                            workWord2 += 1;
                            goto block_207;
                        }
                        goto block_223;
                    case 1:
                        savedWord16 = (int)&Level37_7BD9C_D_80070328 + 640;
                        Level37_7BD9CKeep(savedWord16);
                        if (Level37_7BD9CField(savedWord16, int*, 0) < 0)
                            Level37_7BD9CField(savedWord16, int*, 0) = 0;
                        Level37_7BD9C_func_80035194(ownerAddress21, privateAddress20 + 0x20);
                        if ((Level37_7BD9C_D_8006E048 & 1) ||
                            (Level37_7BD9CCountTimerDown(privateAddress20 + 0x10, 2) != 0)) {
                            Level37_7BD9CPlayer524 = 0x10008000;
                            workWord2 = Level37_7BD9CField(privateAddress20, int*, 56);
                            __asm__ volatile("" ::"r"(privateAddress20) : "$4", "memory");
                            argumentWord4 = savedWord16 - 84;
                            Level37_7BD9CKeep(argumentWord4);
                            argumentWord5 = Level37_7BD9CField(workWord2, int*, 12);
                            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "$16");
                            savedWord16 = (int)&Level37_7BD9C_D_8006E788;
                            Level37_7BD9CKeep(savedWord16);
                            Level37_7BD9CCopyVector(argumentWord4, argumentWord5);
                            argumentWord5 = (int)&Level37_7BD9C_D_80070328 + 12;
                            Level37_7BD9CKeep(argumentWord5);
                            argumentWord4 = (int)&Level37_7BD9C_D_80070328 + 552;
                            Level37_7BD9CKeep(argumentWord4);
                            workWord2 = Level37_7BD9CField(argumentWord5, signed char*, 0);
                            workWord3 = Level37_7BD9CField(argumentWord5, signed char*, 1);
                            Level37_7BD9CKeep(workWord2);
                            MATCHING_OBSERVE_VOLATILE_CLOBBER(argumentWord5, "memory");
                            Level37_7BD9CField(argumentWord4, signed char*, 0) = workWord2;
                            Level37_7BD9CKeep(workWord3);
                            Level37_7BD9CField(argumentWord4, signed char*, 1) = workWord3;
                            workWord2 = Level37_7BD9CField(argumentWord5, signed char*, 2);
                            Level37_7BD9CField(argumentWord4, signed char*, 2) = workWord2;
                            Level37_7BD9CField((int)&Level37_7BD9C_D_80070328, int*, 572) = 0;
                            argumentWord4 = Level37_7BD9CField(savedWord16, int*, 0);
                            savedWord16 += 4;
                            if (argumentWord4) {
                                savedWord22 = 695;
                                savedWord19 = 1;
                                savedWord18 = 516;
                                savedWord17 = 120;
                            actor1598ClearList:
                                Level37_7BD9CKeep(savedWord22);
                                Level37_7BD9CKeep(savedWord19);
                                Level37_7BD9CKeep(savedWord18);
                                Level37_7BD9CKeep(savedWord17);
                                workWord2 = Level37_7BD9CField(argumentWord4, short*, 54);
                                if (workWord2 == savedWord22)
                                    Level37_7BD9CField(argumentWord4, unsigned char*, 73) =
                                        savedWord19;
                                else if (argumentWord4 != ownerAddress21 &&
                                         workWord2 != savedWord18 && workWord2 != savedWord17)
                                    Level37_7BD9CDeleteMoby(argumentWord4);
                                argumentWord4 = Level37_7BD9CField(savedWord16, int*, 0);
                                savedWord16 += 4;
                                if (argumentWord4)
                                    goto actor1598ClearList;
                            }
                            Level37_7BD9CCopyVector((int*)(ownerAddress21 + 0xC), privateAddress20);
                            Level37_7BD9CField(ownerAddress21, int*, 0x18) =
                                (int)(Level37_7BD9CField(ownerAddress21, int*, 0x18) | 0x100000);
                            Level37_7BD9CField(ownerAddress21, unsigned char*, 0x46) =
                                (unsigned char)(Level37_7BD9CField(privateAddress20, unsigned char*,
                                                                   0x12) +
                                                0x80);
                            Level37_7BD9CField(ownerAddress21, unsigned char*, 0x51) =
                                (unsigned char)Level37_7BD9CField(privateAddress20, unsigned char*,
                                                                  0x12);
                            Level37_7BD9CPlayMobySoundEvent(ownerAddress21, 0, 0);
                            Level37_7BD9CField(ownerAddress21, unsigned char*, 0x48) = 0U;
                            Level37_7BD9C_func_80038BF8(ownerAddress21, privateAddress20 + 0x20, 0,
                                                        4);
                            Level37_7BD9CField(privateAddress20, signed char*, 0x2E) = 9;
                            Level37_7BD9CField(privateAddress20, unsigned short*, 0x24) =
                                (unsigned short)(Level37_7BD9CField(privateAddress20,
                                                                    unsigned short*, 0x24) +
                                                 0x78);
                            workWord2 = Level37_7BD9CField(ownerAddress21, short*, 54);
                            workWord2 *= 4;
                            workWord2 =
                                Level37_7BD9CField((int)&Level37_7BD9C_D_8006EE2C, int*, workWord2);
                            workWord2 = Level37_7BD9CField(workWord2, int*, 76);
                            Level37_7BD9C_D_8006C770 = 0;
                            workWord2 = Level37_7BD9CField(workWord2, unsigned char*, 0);
                            __asm__ volatile("" ::"r"(ownerAddress21) : "$3", "memory");
                            workWord3 = 4;
                            Level37_7BD9CKeep(workWord3);
                            Level37_7BD9CField(ownerAddress21, volatile unsigned char*, 60) =
                                workWord3;
                            Level37_7BD9CField(ownerAddress21, volatile unsigned char*, 61) =
                                workWord3;
                            workWord3 = 1;
                            Level37_7BD9CKeep(workWord3);
                            Level37_7BD9CField(ownerAddress21, volatile unsigned char*, 62) = 0;
                            Level37_7BD9CField(ownerAddress21, volatile unsigned char*, 63) =
                                workWord3;
                            workWord2 = (unsigned int)workWord2 < 2;
                            workWord2 ^= 1;
                            workWord2 = -workWord2;
                            workWord2 &= 48;
                            Level37_7BD9CField(ownerAddress21, unsigned char*, 64) = workWord2;
                            workWord2 = 240;
                            Level37_7BD9CKeep(workWord2);
                            Level37_7BD9CField(privateAddress20, unsigned char*, 47) = workWord2;
                            workWord2 = Level37_7BD9CField(privateAddress20, int*, 12);
                            __asm__ volatile("" ::"r"(privateAddress20) : "$3", "memory");
                            workWord3 = 0x46;
                            goto block_206;
                        }
                        goto block_222;
                    case 2:
                        savedWord16 = savedWord19 - 88;
                        Level37_7BD9CCopyVector(savedWord22, privateAddress20);
                        argumentWord4 = savedWord16 & 255;
                        argumentWord4 *= 2;
                        workWord2 = Level37_7BD9CField(savedWord17, short*, argumentWord4);
                        MATCHING_OBSERVE_VOLATILE(savedWord17);
                        Level37_7BD9CStart(completeProduct1, workWord2, savedWord23);
                        argumentWord4 += savedWord18;
                        Level37_7BD9CKeep(argumentWord4);
                        workWord2 = originalFrame.sp68;
                        __asm__(""
                                : "=x"(completeProduct1.full)
                                : "0"(completeProduct1.full), "r"(workWord2));
                        workWord11 = (int)completeProduct1.words.low;
                        Level37_7BD9CKeep(workWord11);
                        workWord3 = workWord11 >> 12;
                        workWord2 += workWord3;
                        originalFrame.sp68 = workWord2;
                        workWord2 = Level37_7BD9CField(argumentWord4, short*, 0);
                        Level37_7BD9CStart(completeProduct4, workWord2, savedWord23);
                        argumentWord5 = retainedFrameAddress;
                        argumentWord4 = savedWord22;
                        MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
                        workWord2 = originalFrame.sp6C;
                        __asm__(""
                                : "=x"(completeProduct4.full)
                                : "0"(completeProduct4.full), "r"(workWord2));
                        workWord12 = (int)completeProduct4.words.low;
                        Level37_7BD9CKeep(workWord12);
                        workWord3 = workWord12 >> 12;
                        workWord2 += workWord3;
                        originalFrame.sp6C = workWord2;
                        Level37_7BD9C_func_80013AE4(argumentWord4, argumentWord5);
                        argumentWord4 = ownerAddress21;
                        MATCHING_OBSERVE_VOLATILE(argumentWord4);
                        savedWord16 = privateAddress20 + 32;
                        Level37_7BD9C_func_80035194(argumentWord4, savedWord16);
                        if (Level37_7BD9CCountTimerDown(privateAddress20 + 0x10, 2) != 0) {
                            Level37_7BD9CCopyVector(originalFrame.sp100, privateAddress20);
                            Level37_7BD9CField(ownerAddress21, int*, 0x18) =
                                (int)(Level37_7BD9CField(ownerAddress21, int*, 0x18) | 0x100000);
                            Level37_7BD9CField(ownerAddress21, unsigned char*, 0x46) =
                                (unsigned char)(Level37_7BD9CField(privateAddress20, unsigned char*,
                                                                   0x12) +
                                                0x80);
                            Level37_7BD9CPlayMobySoundEvent(ownerAddress21, 0, 0);
                            argumentWord4 = ownerAddress21;
                            argumentWord5 = savedWord16;
                            argumentWord6 = 0;
                            workWord2 = Level37_7BD9CField(privateAddress20, unsigned char*, 18);
                            argumentWord7 = 4;
                            Level37_7BD9CField(ownerAddress21, unsigned char*, 72) = 0;
                            Level37_7BD9CField(ownerAddress21, unsigned char*, 81) = workWord2;
                            Level37_7BD9C_func_80038BF8(argumentWord4, argumentWord5, argumentWord6,
                                                        argumentWord7);
                            Level37_7BD9CField(privateAddress20, signed char*, 0x2E) = 8;
                            Level37_7BD9CField(privateAddress20, unsigned short*, 0x24) =
                                (unsigned short)(Level37_7BD9CField(privateAddress20,
                                                                    unsigned short*, 0x24) +
                                                 0x82);
                            workWord2 = Level37_7BD9CField(ownerAddress21, short*, 54);
                            workWord2 *= 4;
                            workWord2 =
                                Level37_7BD9CField((int)&Level37_7BD9C_D_8006EE2C, int*, workWord2);
                            workWord2 = Level37_7BD9CField(workWord2, int*, 76);
                            Level37_7BD9C_D_8006C770 = 0;
                            workWord2 = Level37_7BD9CField(workWord2, unsigned char*, 0);
                            __asm__ volatile("" ::"r"(ownerAddress21) : "$3", "memory");
                            workWord3 = 4;
                            Level37_7BD9CKeep(workWord3);
                            Level37_7BD9CField(ownerAddress21, volatile unsigned char*, 60) =
                                workWord3;
                            Level37_7BD9CField(ownerAddress21, volatile unsigned char*, 61) =
                                workWord3;
                            workWord3 = 1;
                            Level37_7BD9CKeep(workWord3);
                            Level37_7BD9CField(ownerAddress21, volatile unsigned char*, 62) = 0;
                            Level37_7BD9CField(ownerAddress21, volatile unsigned char*, 63) =
                                workWord3;
                            workWord2 = (unsigned int)workWord2 < 2;
                            workWord2 ^= 1;
                            workWord2 = -workWord2;
                            workWord2 &= 48;
                            Level37_7BD9CField(ownerAddress21, unsigned char*, 64) = workWord2;
                            workWord2 = 240;
                            Level37_7BD9CKeep(workWord2);
                            Level37_7BD9CField(privateAddress20, unsigned char*, 47) = workWord2;
                            workWord2 = Level37_7BD9CField(privateAddress20, int*, 12);
                            __asm__ volatile("" ::"r"(privateAddress20) : "$3", "memory");
                            workWord3 = 0xF0;
                            goto actor1598TimeTail;
                        actor1598TimeTail:
                        block_206:
                            Level37_7BD9CField(privateAddress20, short*, 16) = workWord3;
                            workWord2++;
                        block_207:
                            MATCHING_BARRIER_VOLATILE("memory");
                            Level37_7BD9CField(privateAddress20, int*, 12) = workWord2;
                            goto block_223;
                        }
                        goto block_223;
                    case 3:
                        savedWord16 = savedWord19 + 96;
                        Level37_7BD9CCopyVector(savedWord22, privateAddress20);
                        argumentWord4 = savedWord16 & 255;
                        argumentWord4 *= 2;
                        workWord2 = Level37_7BD9CField(savedWord17, short*, argumentWord4);
                        MATCHING_OBSERVE_VOLATILE(savedWord17);
                        Level37_7BD9CStart(completeProduct2, workWord2, savedWord23);
                        argumentWord4 += savedWord18;
                        Level37_7BD9CKeep(argumentWord4);
                        workWord2 = originalFrame.sp68;
                        __asm__(""
                                : "=x"(completeProduct2.full)
                                : "0"(completeProduct2.full), "r"(workWord2));
                        workWord11 = (int)completeProduct2.words.low;
                        Level37_7BD9CKeep(workWord11);
                        workWord3 = workWord11 >> 12;
                        workWord2 += workWord3;
                        originalFrame.sp68 = workWord2;
                        workWord2 = Level37_7BD9CField(argumentWord4, short*, 0);
                        Level37_7BD9CStart(completeProduct5, workWord2, savedWord23);
                        argumentWord5 = retainedFrameAddress;
                        argumentWord4 = savedWord22;
                        MATCHING_OBSERVE2_VOLATILE(argumentWord4, argumentWord5);
                        workWord2 = originalFrame.sp6C;
                        __asm__(""
                                : "=x"(completeProduct5.full)
                                : "0"(completeProduct5.full), "r"(workWord2));
                        workWord12 = (int)completeProduct5.words.low;
                        Level37_7BD9CKeep(workWord12);
                        workWord3 = workWord12 >> 12;
                        workWord2 += workWord3;
                        originalFrame.sp6C = workWord2;
                        Level37_7BD9C_func_80013AE4(argumentWord4, argumentWord5);
                        if (Level37_7BD9CField(privateAddress20, unsigned char*, 0x13) != 0) {
                            Level37_7BD9CField(ownerAddress21, int*, 0x14) =
                                (int)(Level37_7BD9CField(ownerAddress21, int*, 0x14) - 0x5A);
                            goto block_216;
                        }
                        workWord2 =
                            Level37_7BD9C_func_80035194(ownerAddress21, privateAddress20 + 32);
                        argumentWord4 = ownerAddress21;
                        MATCHING_OBSERVE_VOLATILE(argumentWord4);
                        savedWord16 = workWord2;
                        if (Level37_7BD9C_func_80055E84(argumentWord4) >= 39) {
                            Level37_7BD9CField(privateAddress20, unsigned char*, 0x13) = 1U;
                            if (Level37_7BD9CField(privateAddress20, short*, 0x10) >= 0x29) {
                                Level37_7BD9CField(privateAddress20, short*, 0x10) = 0x28;
                            }
                            Level37_7BD9CField(ownerAddress21, int*, 0x54) =
                                (int)((Level37_7BD9CField(ownerAddress21, int*, 0x14) & 0xFFFFFF) |
                                      0x80000000);
                        }
                        var_a0_10 = privateAddress20 + 0x10;
                        if (savedWord16 == 0x100) {
                            Level37_7BD9CField(privateAddress20, short*, 0x10) = 0;
                        block_216:
                            var_a0_10 = privateAddress20 + 0x10;
                        }
                        if ((Level37_7BD9CCountTimerDown(var_a0_10, 2) != 0) ||
                            (Level37_7BD9C_D_8006C770 != 0)) {
                            savedWord19 = Level37_7BD9CSpawnMoby(0x84, ownerAddress21);
                            Level37_7BD9CKeep(savedWord19);
                            savedWord16 = savedWord19 + 0xC;
                            if (savedWord19 != 0) {
                                savedWord18 = Level37_7BD9CField(savedWord19, int*, 0);
                                Level37_7BD9CCopyVector(
                                    savedWord16,
                                    Level37_7BD9CField(
                                        Level37_7BD9CField(privateAddress20, int*, 0x38), int*,
                                        0xC));
                                Level37_7BD9CField(savedWord19, int*, 0x14) =
                                    (int)(Level37_7BD9CField(savedWord19, int*, 0x14) + 0x1F4);
                                workWord2 = Level37_7BD9C_func_8001A358(savedWord16, 8192);
                                savedWord17 = (int)&originalFrame.sp88;
                                argumentWord4 = savedWord17;
                                Level37_7BD9CKeep(argumentWord4);
                                argumentWord5 = savedWord16;
                                Level37_7BD9CKeep(argumentWord5);
                                Level37_7BD9CField(savedWord19, int*, 20) = workWord2;
                                Level37_7BD9CField(savedWord18, short*, 0) = 0;
                                savedWord16 = Level37_7BD9CField(savedWord19, unsigned char*, 70);
                                __asm__ volatile("" ::"r"(savedWord19) : "$2", "memory");
                                workWord2 = 1;
                                Level37_7BD9CField(savedWord19, unsigned char*, 72) = workWord2;
                                Level37_7BD9CCopyVector(argumentWord4, argumentWord5);
                                argumentWord4 = savedWord17;
                                Level37_7BD9CKeep(argumentWord4);
                                savedWord16 *= 2;
                                workWord3 = Level37_7BD9CField((int)&Level37_7BD9C_D_80065920,
                                                               short*, savedWord16);
                                argumentWord5 =
                                    Level37_7BD9CField((int)&Level37_7BD9C_D_80070328, int*, 68);
                                workWord2 = workWord3 * 5;
                                Level37_7BD9CKeep(workWord2);
                                workWord2 = workWord2 * 8 - workWord3;
                                Level37_7BD9CKeep(workWord2);
                                workWord3 = originalFrame.sp88;
                                workWord2 >>= 6;
                                workWord3 += workWord2;
                                workWord2 = originalFrame.sp90;
                                __asm__ volatile("" ::"r"(argumentWord4) : "$6", "memory");
                                argumentWord6 = 0;
                                originalFrame.sp88 = workWord3;
                                workWord3 = Level37_7BD9CField((int)&Level37_7BD9C_D_800658A0,
                                                               short*, savedWord16);
                                workWord2 += argumentWord5;
                                originalFrame.sp90 = workWord2;
                                workWord2 = workWord3 * 5;
                                Level37_7BD9CKeep(workWord2);
                                workWord2 = workWord2 * 8 - workWord3;
                                Level37_7BD9CKeep(workWord2);
                                workWord3 = originalFrame.sp8C;
                                workWord2 >>= 6;
                                workWord3 += workWord2;
                                originalFrame.sp8C = workWord3;
                                Level37_7BD9C_func_80013D44(
                                    argumentWord4,
                                    Level37_7BD9CField(savedWord19, unsigned char*, 70) + 128,
                                    argumentWord6, 0);
                            }
                            Level37_7BD9C_D_8006C40A = 0;
                            Level37_7BD9C_D_8007159A = 0;
                            Level37_7BD9C_D_8007158E = 1;
                            Level37_7BD9CDeleteMoby(ownerAddress21);
                            return;
                        }
                        goto block_222;
                    default:
                        goto block_223;
                }
                break;
        }
    }
    return;
block_223:
    Level37_7BD9CRefreshMobySpatialGridAndBasis(ownerAddress21, 4);
    return;
}
#undef Level37_7BD9CField
#undef Level37_7BD9CKeep

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * Original raw447 local controller words are authoritative. Factory
 * descendants, private producer, live counter writers/cadence unresolved. */
extern int D_8006C578, D_8006C574, D_8006C648, D_8006C770;
extern int DecodedRaw447Counters[] __asm__("D_80066EEC");
extern unsigned char DecodedRaw447Player[] __asm__("D_80070328");
int func_80037A60(Moby*, void*, int, int, int);
void func_level_37_8007D694(Moby* argument) {
    register Moby* moby __asm__("$17") = argument;
    register unsigned char* tag __asm__("$18") = moby->mobyTag;
    register int index __asm__("$16");
    if (moby->state < 2 && moby->damageFlags) {
        int angle;
        index = 0;
        MATCHING_KEEP(index);
        do {
            if (D_8006C578 - D_8006C574 < 21)
                goto finished_requests;
            {
                register int rawType __asm__("$4") = 448;
                register Moby* spawning __asm__("$5") = moby;
                MATCHING_KEEP2(rawType, spawning);
                SpawnMoby(rawType, spawning);
                index++;
            }
        } while (index < 10);
    finished_requests:
        angle = moby->unkb;
        if (!angle)
            angle =
                func_800360F8(func_8004E880(moby->position.x - *(int*)DecodedRaw447Player,
                                            moby->position.y - *(int*)(DecodedRaw447Player + 4), 0),
                              DecodedRaw447Player[14], 32, 64);
        {
            register int rawType __asm__("$4") = 16;
            register Moby* spawning __asm__("$5") = moby;
            register Moby* (*spawn)(int, Moby*)__asm__("$2");
            register int initial __asm__("$3");
            MATCHING_KEEP2(rawType, spawning);
            *(int*)(tag + 4) = angle;
            spawn = SpawnMoby;
            MATCHING_KEEP(spawn);
            initial = 250;
            *(int*)tag = initial;
            *(int*)(tag + 8) = 0;
            spawn(rawType, spawning);
        }
        moby->state = 2;
        func_80034F40(moby, 2);
    }
    DecodedRaw447Counters[1] += D_8006C648;
    if (DecodedRaw447Counters[1] >= 30001)
        DecodedRaw447Counters[1] = 30000;
    moby->damageFlags = 0;
    if (moby->substate < 255)
        moby->substate++;
    switch (moby->state) {
        case 0:
            if (func_800359A4(tag + 22, 1)) {
                moby->state = 1;
                func_80034F40(moby, 1);
            }
            func_80037168(moby, (Vector3D*)tag, 1);
            if (func_800359A4(tag + 23, 1)) {
                tag[23] = (rand() & 63) + 120;
                func_8003BABC(moby, 3, 0);
            }
            break;
        case 1:
            if (func_800359A4(tag + 23, 1)) {
                tag[23] = (rand() & 31) + 80;
                func_8003BABC(moby, rand() % 3, 0);
            }
            if (D_8006C770) {
                tag[22] = func_8003636C(180, 255);
                tag[23] = 0;
                moby->state = 0;
                func_80034F40(moby, 0);
            }
            break;
        case 2:
            func_80035030(moby, tag, *(int*)(tag + 4), tag + 8, 12, 0, 300, 1);
            if (D_8006C770) {
                func_80055D24(moby, 4);
                func_800369B8(moby, 40);
                func_80055B18(moby);
                return;
            }
            break;
        case 10:
            if (func_80037A60(moby, tag + 8, 4, 16, -200)) {
                moby->state = 1;
                func_80034F40(moby, 1);
            }
            break;
    }
    func_80055D24(moby, 1);
}

typedef struct {
    Vector3D16 velocity;
    unsigned char reserved06[6];
    unsigned char timer, settlingTimer;
    short pitchStep;
    int mode;
} DecodedMovingFragmentTag;
int rand(void);
void func_level_37_8007D9F4(Moby* moby) {
    DecodedMovingFragmentTag* tag = moby->mobyTag;
    register int pitch __asm__("$2");
    register int sum __asm__("$3");
    register int reversed __asm__("$2");
    register int pitchStep __asm__("$4");
    if (tag->timer && moby->drawn) {
        moby->position.x += tag->velocity.x;
        moby->position.y += tag->velocity.y;
        tag->velocity.z -= 5;
        if (--tag->settlingTimer == 0) {
            tag->velocity.x = 0;
            tag->velocity.y = 0;
            tag->velocity.z = 0;
        }
        if (tag->velocity.z < -24)
            tag->velocity.z = -24;
        if (!tag->mode)
            moby->angle.yaw += 12;
        else if (tag->velocity.z < 0) {
            pitch = moby->angle.pitch;
            pitchStep = tag->pitchStep;
            MATCHING_KEEP2(pitch, pitchStep);
            sum = pitch + pitchStep;
            MATCHING_KEEP(sum);
            if (sum == 0x20 || sum == 0xE0) {
                reversed = -pitchStep;
                MATCHING_KEEP(reversed);
                tag->pitchStep = reversed;
            }
            moby->angle.pitch += *(unsigned char*)&tag->pitchStep;
            moby->position.y += tag->pitchStep;
            if (rand() & 1)
                moby->angle.yaw++;
        }
        moby->position.z += tag->velocity.z;
        tag->timer--;
    } else
        func_80055B18(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Instruction-matched C candidate. Original source asm/nonmatchings/overlays/level_37/moby/func_level_37_8007DB84.s SHA256 23bdc147e220795da54444211c5710324636629dc1407bcb367ec47dd47c0a6e. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

void* Controller7DB84_func_8001BA30() __asm__("func_8001BA30");               /* extern */
int Controller7DB84_func_8001C288() __asm__("func_8001C288");                 /* extern */
int Controller7DB84BuildPackedAngleBasisMatrix() __asm__("func_8004EA90");    /* extern */
int Controller7DB84TransformVectorByBasis() __asm__("func_8004ED6C");         /* extern */
int Controller7DB84ShiftVectorLeft() __asm__("func_8004F0E8");                /* extern */
int Controller7DB84ApproximatePlanarDistance() __asm__("func_8004F334");      /* extern */
int Controller7DB84DeleteMoby() __asm__("func_80055B18");                     /* extern */
int Controller7DB84RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int Controller7DB84_rand() __asm__("rand");                                   /* extern */
extern unsigned char Controller7DB84_D_800658A0 __asm__("D_800658A0");
extern unsigned char Controller7DB84_D_80065920 __asm__("D_80065920");
extern int Controller7DB84_D_8006C574 __asm__("D_8006C574");
extern int Controller7DB84_D_8006C578 __asm__("D_8006C578");
extern int Controller7DB84_D_8006E160 __asm__("D_8006E160");
extern int Controller7DB84_D_8006E164 __asm__("D_8006E164");
extern unsigned char Controller7DB84_D_80070328 __asm__("D_80070328");

void func_level_37_8007DB84(Moby* inputOwner) {
    struct {
        Vector3D sp18;
        char pad_24[4];
        int sp28;
        int sp2C;
        int sp30;
        char pad_34[4];
        Vector3D sp38;
        char pad_44[4];
        unsigned char sp48;
        char pad_49[23];
        signed char sp60;
        signed char sp61;
        signed char sp62;
        char pad_63[5];
    } originalStack;

    register Moby* owner18 __asm__("$18") = inputOwner;

    register Moby* child16 __asm__("$16");
    register Vector3D* position16 __asm__("$16");
    register Vector3D* position17 __asm__("$17");
    register int timer4 __asm__("$4");
    int randomX;
    int randomY;
    int counter2;
    register int remaining3 __asm__("$3");
    int unusedSign;
    register int particle19 __asm__("$19");
    register int spawn19 __asm__("$19");
    register int radius20 __asm__("$20");
    register int extent2 __asm__("$2");
    register int product4 __asm__("$4");
    register int product3 __asm__("$3");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register Vector3D* argument6 __asm__("$6");
    register Vector3D* argument7 __asm__("$7");
    register int* global4 __asm__("$4");
    int state;
    register void* tag23 __asm__("$23");
    register void* hit16 __asm__("$16");
    register unsigned char* matrix21 __asm__("$21");
    register Vector3D* vector17 __asm__("$17");
    register Vector3D* vector16 __asm__("$16");
    register int height22 __asm__("$22");
    register int size17 __asm__("$17");
    register int divisor3 __asm__("$3");
    register int sample2 __asm__("$2");

    MATCHING_KEEP(owner18);
    tag23 = owner18->mobyTag;
    if ((owner18->damageFlags != 0) && ((unsigned int)(owner18->state - 0xA) >= 2U)) {
        owner18->state = 0xA;
    }
    state = owner18->state;
    switch (state) { /* Original states 0, 10 and 11. */
        case 0:
            sample2 = 9;
            MATCHING_KEEP_VOLATILE(sample2);
            value3 = Controller7DB84_D_8006E160;
            size17 = 230;
            if (value3 != sample2) {
                func_80013ACC(owner18, 0xD);
            }
            argument4 = (int)&originalStack.sp18;
            MATCHING_KEEP(argument4);
            position16 = &owner18->position;
            func_8004F178(argument4, position16);
            sample2 = func_800363DC(0, 0x32);
            value3 = originalStack.sp18.z + 950;
            MATCHING_KEEP(value3);
            value3 += sample2;
            originalStack.sp18.z = value3;
            originalStack.sp18.x = originalStack.sp18.x + func_8003636C(0, 0xFA);
            originalStack.sp18.y += func_8003636C(0, 0xFA);
            randomX = (Controller7DB84_rand() & 0x1F) - 0x10;
            originalStack.sp28 = randomX;
            randomY = (Controller7DB84_rand() & 0x1F) - 0x10;
            originalStack.sp2C = randomY;
            originalStack.sp30 = func_8003636C(0x19, 0x23);
            originalStack.sp28 =
                originalStack.sp28 +
                ((int)(M2C_FIELD(&Controller7DB84_D_80065920, short*, (owner18->angle.yaw * 2)) *
                       (M2C_FIELD(tag23, int*, 4) / 3)) >>
                 0xC);
            originalStack.sp2C =
                originalStack.sp2C +
                ((int)(M2C_FIELD(&Controller7DB84_D_800658A0, short*, (owner18->angle.yaw * 2)) *
                       (M2C_FIELD(tag23, int*, 4) / 3)) >>
                 0xC);
            M2C_FIELD(SpawnParticle(1, 0xD, &originalStack.sp18, (Vector3D*)&originalStack.sp28),
                      signed char*, 2) = 4;
            func_8003573C(owner18, 3, 0, 0);
            counter2 = M2C_FIELD(tag23, int*, 4) + 0x14;
            M2C_FIELD(tag23, int*, 4) = counter2;
            if (counter2 > size17) {
                M2C_FIELD(tag23, int*, 4) = size17;
            }
            if (func_80035DDC(owner18, M2C_FIELD(tag23, int*, 4), 0x12C, 0, 5) != 0) {
                owner18->damageFlags |= 0x20000;
                owner18->unkb = owner18->angle.yaw + 0x80;
            }
            if ((func_800359A4(tag23, 4) != 0) ||
                (Controller7DB84ApproximatePlanarDistance(position16, &Controller7DB84_D_80070328) <
                 0x320)) {
                owner18->damageFlags |= 0x20000;
                owner18->unkb = owner18->angle.yaw + 0x80;
            }
            goto updateOwner;
        case 10:
            func_8003BABC(owner18, 0, 0);
            global4 = &Controller7DB84_D_8006E160;
            if ((*global4 != 9) && (Controller7DB84_D_8006E164 == (int)owner18)) {
                *global4 = 0;
                Controller7DB84_D_8006E164 = 0;
            }
            M2C_FIELD(tag23, int*, 0) = 0x3C;
            owner18->unknown3[0] = 0;
            owner18->lowDrawDistance = 0;
            owner18->drawn = 0;
            owner18->state = 0xB;
            /* fallthrough */
        case 11:
            radius20 = 1400;
            height22 = 700;
            timer4 = M2C_FIELD(tag23, int*, 0);
            if (timer4 >= 31) {
                remaining3 = 60 - timer4;
                product4 = remaining3 * radius20;
                product3 = remaining3 * height22;
                extent2 = product4 / 60;
                radius20 = extent2 + 700;
                extent2 = product3 / 60;
            } else {
                product3 = timer4 * radius20;
                product4 = timer4 * height22;
                extent2 = product3 / 60;
                radius20 = extent2 + 700;
                extent2 = product4 / 60;
            }
            height22 = extent2 + 350;
            particle19 = 0;
            if (M2C_FIELD(tag23, int*, 0) >= 0xB) {
                matrix21 = &originalStack.sp48;
                vector17 = (Vector3D*)&originalStack.sp28;
                vector16 = &originalStack.sp38;
                do {
                    originalStack.sp60 = 0;
                    originalStack.sp61 = Controller7DB84_rand();
                    originalStack.sp62 = Controller7DB84_rand();
                    Controller7DB84BuildPackedAngleBasisMatrix(&originalStack.sp60, matrix21, 0);
                    originalStack.sp28 = func_8003636C(0x3C, 0x64);
                    originalStack.sp2C = 0;
                    originalStack.sp30 = 0;
                    Controller7DB84TransformVectorByBasis(matrix21, vector17, vector17);
                    func_8004F178(vector16, vector17);
                    Controller7DB84ShiftVectorLeft(vector16, 2);
                    func_8004F194(vector16, vector16, &owner18->position);
                    argument4 = 1;
                    argument5 = 13;
                    argument6 = vector16;
                    argument7 = vector17;
                    MATCHING_OBSERVE4(argument4, argument5, argument6, argument7);
                    particle19 += 1;
                    SpawnParticle(argument4, argument5, argument6, argument7);
                    MATCHING_KEEP(owner18);
                    unusedSign = 4;
                } while (particle19 < 0xC);
                SpawnParticle(4, 0x46, &owner18->position, (Vector3D*)0x10);
            }
            spawn19 = 0;
            size17 = 64;
        nextChild:
            if ((Controller7DB84_D_8006C578 - Controller7DB84_D_8006C574) >= 0x15) {
                child16 = SpawnMoby(0x146, owner18);
                if (child16 != 0) {
                    child16->lowDrawDistance = size17;
                    child16->highDrawDistance = size17;
                    child16->position.x += func_800363DC(0, radius20);
                    child16->position.y += func_800363DC(0, radius20);
                    sample2 = func_800363DC(0, height22);
                    value3 = child16->position.z + 700;
                    MATCHING_KEEP(value3);
                    value3 += sample2;
                    child16->position.z = value3;
                }
                spawn19 += 1;
                if (spawn19 < 2) {
                    goto nextChild;
                }
            }
            position17 = &owner18->position;
            hit16 = Controller7DB84_func_8001BA30(position17, radius20 + 0x3E8, 1, 0, 0x100000,
                                                  owner18);
            if (hit16 != 0) {
                M2C_FIELD(hit16, signed char*, 0x51) =
                    func_8004E880(M2C_FIELD(hit16, int*, 0xC) - owner18->position.x,
                                  M2C_FIELD(hit16, int*, 0x10) - owner18->position.y, 0);
            }
            Controller7DB84_func_8001C288(position17, (int)(radius20 + 0x190) / 2, 7);
            if (func_800359A4(tag23, 4) != 0) {
                Controller7DB84DeleteMoby(owner18);
                return;
            }
            goto updateOwner;
    }
updateOwner:
    Controller7DB84RefreshMobySpatialGridAndBasis(owner18, 4);
}
#undef M2C_FIELD

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Instruction-matched C candidate. Original source asm/nonmatchings/overlays/level_37/moby/func_level_37_8007E1C8.s SHA256 faa85d6e4196b3dc7618805c77a1e8d401f488fb80ac0f37d406abebaaba3d64. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p, t, o) (*(t)((unsigned char*)(p) + (o)))

int Controller7E1C8_func_80018368() __asm__("func_80018368");                 /* extern */
int Controller7E1C8_func_80019194() __asm__("func_80019194");                 /* extern */
int Controller7E1C8ApproximatePlanarDistance() __asm__("func_8004F334");      /* extern */
int Controller7E1C8_func_8004F388() __asm__("func_8004F388");                 /* extern */
int Controller7E1C8DeleteMoby() __asm__("func_80055B18");                     /* extern */
int Controller7E1C8RefreshMobySpatialGridAndBasis() __asm__("func_80055D24"); /* extern */
int Controller7E1C8_func_80056504() __asm__("func_80056504");                 /* extern */
int Controller7E1C8_rand() __asm__("rand");                                   /* extern */
extern unsigned char Controller7E1C8_D_800658A0 __asm__("D_800658A0");
extern unsigned char Controller7E1C8_D_80065920 __asm__("D_80065920");
extern void** Controller7E1C8_D_8006C550 __asm__("D_8006C550");
extern int Controller7E1C8_D_8006C648 __asm__("D_8006C648");
extern int Controller7E1C8_D_80070328 __asm__("D_80070328");

void func_level_37_8007E1C8(Moby* inputOwner) {
    struct {
        int sp10;
        int sp14;
        int sp18;
        char pad_1c[4];
        Vector3D sp20;
        char pad_2c[4];
        int sp30;
        int sp34;
        int sp38;
        char pad_3c[12];
    } originalStack;

    register Moby* owner18 __asm__("$18") = inputOwner;

    register Moby* child16 __asm__("$16");
    register Vector3D* position17 __asm__("$17");
    register Vector3D* position21 __asm__("$21");
    register int value2 __asm__("$2");
    register short shortValue2 __asm__("$2");
    register int argument4 __asm__("$4");
    register int step4 __asm__("$4");
    int remainder5;
    register int radius17 __asm__("$17");
    register int seed20 __asm__("$20");
    int offset3;
    register int difference3 __asm__("$3");
    register int distance17 __asm__("$17");
    register int angle20 __asm__("$20");
    register int value3 __asm__("$3");
    register int range3 __asm__("$3");
    register int particleByte3 __asm__("$3");
    register int divisor4 __asm__("$4");
    register int sample2 __asm__("$2");
    register Vector3D* previous16 __asm__("$16");
    signed char* particle4;
    signed char* particle2;
    signed char* particle3;
    unsigned char state;
    register int nextState2 __asm__("$2");
    register void* record16 __asm__("$16");
    register void* tag19 __asm__("$19");

    MATCHING_KEEP(owner18);
    state = owner18->state;
    tag19 = owner18->mobyTag;
    switch (state) { /* Original states 0, 2 and final state 3. */
        case 0:
            record16 = *Controller7E1C8_D_8006C550;
            position21 = &owner18->position;
            seed20 = Controller7E1C8_rand();
            value3 = Controller7E1C8_func_8004F388(func_8003636C(0x640, 0x4204)) * 25;
            MATCHING_KEEP(value3);
            argument4 = (seed20 & 0xFF) * 2;
            sample2 = M2C_FIELD(&Controller7E1C8_D_80065920, short*, argument4);
            MATCHING_KEEP(sample2);
            radius17 = value3 * 4;
            originalStack.sp10 = (sample2 * radius17) >> 12;
            sample2 = M2C_FIELD(&Controller7E1C8_D_800658A0, short*, argument4);
            MATCHING_KEEP(sample2);
            originalStack.sp18 = 0;
            originalStack.sp14 = (sample2 * radius17) >> 12;
            func_8004F194((Vector3D*)&originalStack.sp10, (Vector3D*)&originalStack.sp10,
                          M2C_FIELD(M2C_FIELD(record16, void**, 0x38), Vector3D**, 0xC));
            M2C_FIELD(tag19, int*, 0x14) = originalStack.sp18;
            angle20 = func_8004E880(originalStack.sp10 - owner18->position.x,
                                    originalStack.sp14 - owner18->position.y, 0);
            distance17 = Controller7E1C8ApproximatePlanarDistance(position21, &originalStack.sp10);
            if (M2C_FIELD(tag19, short*, 8) == 0) {
                angle20 = func_8004E880(
                    M2C_FIELD(&Controller7E1C8_D_80070328, int*, 0) - owner18->position.x,
                    M2C_FIELD(&Controller7E1C8_D_80070328, int*, 4) - owner18->position.y, 0);
                distance17 = Controller7E1C8ApproximatePlanarDistance(position21,
                                                                      &Controller7E1C8_D_80070328);
            }
            M2C_FIELD(tag19, short*, 0xA) = func_8003636C(0x17C, 0x262);
            value3 = -(distance17 * 2);
            sample2 = angle20 & 0xFF;
            M2C_FIELD(tag19, short*, 0x12) = sample2;
            if (value3 < 0) {
                value3 += 7;
            }
            M2C_FIELD(tag19, short*, 0x10) =
                (short)(Controller7E1C8_func_8004F388(-(argument4 = value3 >> 3)) * 8);
            remainder5 = (M2C_FIELD(tag19, short*, 8) % 5) << 0x10;
            if (remainder5 == 0) {
                func_8003BABC(owner18, Controller7E1C8_rand() & 1, 1);
            }
            nextState2 = 2;
            goto setInitialState;
        case 2:
            func_8004F178(&originalStack.sp20, &owner18->position);
            owner18->position.z +=
                (int)(M2C_FIELD(tag19, short*, 0xA) * Controller7E1C8_D_8006C648) >> 1;
            value2 = M2C_FIELD(tag19, short*, 0x10);
            if (value2 != 0) {
                value3 = value2;
                sample2 = -(Controller7E1C8_D_8006C648 * 8) >> 1;
                shortValue2 = value3 + sample2;
                M2C_FIELD(tag19, short*, 0x10) = shortValue2;
                if (shortValue2 < 0) {
                    M2C_FIELD(tag19, short*, 0x10) = 0;
                }
                step4 = M2C_FIELD(tag19, short*, 0x10);
                MATCHING_KEEP(step4);
                step4 = (step4 * Controller7E1C8_D_8006C648) >> 1;
                offset3 = (int)(M2C_FIELD(&Controller7E1C8_D_80065920, short*,
                                          (M2C_FIELD(tag19, short*, 0x12) * 2)) *
                                step4) >>
                          0xC;
                originalStack.sp30 = offset3;
                sample2 = M2C_FIELD(&Controller7E1C8_D_800658A0, short*,
                                    M2C_FIELD(tag19, short*, 0x12) * 2);
                MATCHING_KEEP(sample2);
                originalStack.sp38 = 0;
                originalStack.sp34 = (sample2 * step4) >> 12;
                owner18->position.x += offset3;
                owner18->position.y += originalStack.sp34;
            }
            previous16 = &originalStack.sp20;
            argument4 = (int)previous16;
            MATCHING_KEEP(argument4);
            position17 = &owner18->position;
            if (Controller7E1C8_func_80018368(argument4, position17) != 0) {
                func_8004F178(position17, previous16);
                owner18->state = 3;
            }
            if ((M2C_FIELD(tag19, signed char**, 0xC) != 0) ||
                (func_8004F178(previous16, position17),
                 originalStack.sp20.z = M2C_FIELD(tag19, int*, 0x14),
                 particle2 = SpawnParticle(1, 0x32, previous16, 0),
                 M2C_FIELD(tag19, signed char**, 0xC) = particle2, (particle2 != 0))) {
                sample2 = owner18->position.z;
                difference3 = M2C_FIELD(tag19, int*, 0x14);
                MATCHING_OBSERVE2(sample2, difference3);
                divisor4 = 0x4650;
                MATCHING_KEEP(divisor4);
                difference3 = sample2 - difference3;
                if (difference3 > divisor4) {
                    range3 = 0x4650;
                    MATCHING_KEEP(range3);
                    range3 = divisor4 - range3;
                } else {
                    range3 = divisor4 - difference3;
                }
                particleByte3 = (int)((int)(range3 * 0x5DC) / divisor4) / 4;
                if (particleByte3 >= 0x100) {
                    particleByte3 = 0xFF;
                }
                M2C_FIELD(M2C_FIELD(tag19, signed char**, 0xC), signed char*, 0xA) =
                    (signed char)particleByte3;
                func_8004F178((Vector3D*)&originalStack.sp30, position17);
                originalStack.sp38 = M2C_FIELD(tag19, int*, 0x14);
                func_8004F504((Vector3D16*)(M2C_FIELD(tag19, signed char**, 0xC) + 4),
                              (Vector3D16*)&originalStack.sp30);
            }
            M2C_FIELD(tag19, short*, 0xA) =
                (short)((unsigned short)M2C_FIELD(tag19, short*, 0xA) +
                        ((int)-(Controller7E1C8_D_8006C648 * 0x12) >> 1));
            if ((owner18->substate != 0) || (owner18->position.x < 0x400) ||
                (owner18->position.y < 0x400) || (owner18->position.z < 0x400)) {
                particle4 = M2C_FIELD(tag19, signed char**, 0xC);
                if (particle4 != 0) {
                    Controller7E1C8_func_80056504(particle4);
                }
                goto deleteOwner;
            }
            Controller7E1C8RefreshMobySpatialGridAndBasis(owner18, 2);
            if (Controller7E1C8_func_80019194(&owner18->position, 0x1F4) != 0) {
                owner18->state = 3;
            }
            goto checkFinalState;
            break;
        setInitialState:
            owner18->state = nextState2;
        checkFinalState:
        default:
            if (owner18->state == 3) {
                child16 = SpawnMoby(0x2B8, owner18);
                particle3 = M2C_FIELD(tag19, signed char**, 0xC);
                if (particle3 != 0) {
                    M2C_FIELD(particle3, signed char*, 2) = 0x1E;
                    M2C_FIELD(tag19, signed char**, 0xC) = 0;
                }
                if (child16 != 0) {
                    child16->lowDrawDistance = 0x30;
                    child16->highDrawDistance = 0x30;
                    child16->unknown5 = 1;
                    func_8003BABC(child16, 0, 0);
                    func_80037014(child16);
                }
            deleteOwner:
                Controller7E1C8DeleteMoby(owner18);
            }
            break;
    }
}
#undef M2C_FIELD

extern int D_8006C770;
int func_80055E84(Moby*);
Moby* func_8001BA30(Vector3D*, int, int, int, int, Moby*);
void func_8001C288(Vector3D*, int, int);
void func_level_37_8007E758(Moby* moby) {
    int radius = func_80055E84(moby) * 80 + 0xC8;
    Moby* target = func_8001BA30(&moby->position, radius, 1, 0, 0x20000000, moby);
    if (target) {
        target->unkb = func_8004E880(target->position.x - moby->position.x,
                                     target->position.y - moby->position.y, 0);
    }
    func_8001C288(&moby->position, radius, 7);
    if (D_8006C770)
        func_80055B18(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_37/moby/func_level_37_8007E824.s SHA256 8aef3a2a421da6df7dfd54567ac78e4e30d4b0e66c293a37553169ced34ddfc8. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level37_7E824Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern Moby* Level37_7E824_D_8006C550 __asm__("D_8006C550");
extern Spyro Level37_7E824_D_80070328 __asm__("D_80070328");
void Level37_7E824RequestMobyAnimation(Moby* moby, int newId) __asm__("func_80034F40");
void Level37_7E824EmptyAnimationTransitionHook(Moby* moby) __asm__("func_80035734");
int Level37_7E824TurnMobyTowardPlayer(Moby* ownerRecord, int arg1, int arg2,
                                      int arg3) __asm__("func_8003573C");
int Level37_7E824CountTimerDown(void*, int) __asm__("func_800359A4");
int Level37_7E824_func_80035DDC(Moby* ownerRecord, int arg1, int arg2, int arg3,
                                int arg4) __asm__("func_80035DDC");
int Level37_7E824_func_80035EE0(Moby*, int, int, int, int, int) __asm__("func_80035EE0");
int Level37_7E824RandBetween(int low, int high) __asm__("func_8003636C");
int Level37_7E824PlayMobySoundEvent(Moby*, int, int) __asm__("func_8003BABC");
extern int Level37_7E824PlanarHeadingLookup(int, int, int) __asm__("func_8004E880");
extern void Level37_7E824TransformVectorByBasis(SHORTMATRIX*, Vector3D*,
                                                Vector3D*) __asm__("func_8004ED6C");
extern void Level37_7E824CopyVector(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern void Level37_7E824AddVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern int Level37_7E824AbsoluteByteAngleDelta(int, int) __asm__("func_8004F264");
extern int Level37_7E824ApproximatePlanarDistance(Vector3D*, Vector3D*) __asm__("func_8004F334");
extern void Level37_7E824DeleteMoby(Moby*) __asm__("func_80055B18");
extern void Level37_7E824RefreshMobySpatialGridAndBasis(Moby*, int) __asm__("func_80055D24");

int Level37_7E824_func_80037A60() __asm__("func_80037A60");
/* extern */
unsigned char Level37_7E824ClearVector() __asm__("func_8004F168");
/* extern */
extern int Level37_7E824_D_8006C574 __asm__("D_8006C574");
extern int Level37_7E824_D_8006C578 __asm__("D_8006C578");
extern int Level37_7E824_D_8006C770 __asm__("D_8006C770");
extern int Level37_7E824_D_8006E020 __asm__("D_8006E020");
extern int Level37_7E824_D_8006E024 __asm__("D_8006E024");
extern unsigned short Level37_7E824_D_8006E040 __asm__("D_8006E040");
extern unsigned char Level37_7E824_D_8006EE2C __asm__("D_8006EE2C");

void func_level_37_8007E824(Moby* ownerRecord) {
    /* Original 0x68-byte frame: vectors start SP+0x18, SP+0x28 and
     * SP+0x38;
      saved S0 begins SP+0x48. Register suffixes record native
     * roles. Coordinate units and helper effects remain unresolved. */
    struct {
        Vector3D sp18;
        unsigned char pad24[4];
        Vector3D sp28;
        unsigned char pad34[4];
        Vector3D sp38;
        unsigned char pad44[4];
    } scratch;

    Moby* spawnedOwner16;
    register int selectedHalfword2 __asm__("$2");
    register int distanceResult16 __asm__("$16");
    register int initialMetric17 __asm__("$17");
    register int word2 __asm__("$2");
    register int word3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6") = 0;
    register void* pointer2 __asm__("$2");
    register void* pointer3 __asm__("$3");
    register Vector3D* vectorArgument4 __asm__("$4");
    register Vector3D* vectorArgument5 __asm__("$5");
    register Vector3D* vectorArgument6 __asm__("$6");
    register int spawnIndex17 __asm__("$17");
    register int predicate2 __asm__("$2");
    register Moby* ownerArgument4 __asm__("$4");
    register unsigned int selector4 __asm__("$4");
    unsigned int animationFrame5;
    unsigned int animationByte2;
    register unsigned int otherAnimationByte2 __asm__("$2");
    unsigned int stateByte3;
    register unsigned int animationByte3 __asm__("$3");
    register unsigned int selectedFrame5 __asm__("$5");
    register void* privateRecord19 __asm__("$19");
    register void* globalPrivate21 __asm__("$21");
    void* privatePointer4;
    register int literalOne19 __asm__("$19");
    register int animationTableAddress20 __asm__("$20");

    MATCHING_OBSERVE(argument6);
    word3 = ownerRecord->position.x;
    argument4 = Level37_7E824_D_8006E020;
    word2 = ownerRecord->position.y;
    argument5 = Level37_7E824_D_8006E024;
    __asm__("" : "=r"(argument5) : "0"(argument5), "r"(word3), "r"(argument4), "r"(word2));
    privateRecord19 = ownerRecord->mobyTag;
    argument5 = word2 - argument5;
    MATCHING_KEEP_CLOBBER(argument5, "memory");
    pointer2 = Level37_7E824_D_8006C550;
    globalPrivate21 = Level37_7E824Field(pointer2, void**, 0);
    word2 = Level37_7E824PlanarHeadingLookup(word3 - argument4, argument5, argument6);
    initialMetric17 =
        Level37_7E824AbsoluteByteAngleDelta((int)(Level37_7E824_D_8006E040 << 0x10) >> 0x14, word2);
    if (initialMetric17 >= 0x18) {
        Level37_7E824Field(privateRecord19, signed char*, 0xB) = 0x1E;
    }
    if (ownerRecord->damageFlags & 0x930000) {
        spawnIndex17 = 0;
        literalOne19 = 1;
        animationTableAddress20 = (int)&Level37_7E824_D_8006EE2C;
        MATCHING_KEEP2(literalOne19, animationTableAddress20);
    spawnLoop:
        if ((Level37_7E824_D_8006C578 - Level37_7E824_D_8006C574) >= 0x15) {
            spawnedOwner16 = SpawnMoby(0x147, ownerRecord);
            if (spawnedOwner16 != 0) {
                Level37_7E824Field(spawnedOwner16->mobyTag, short*, 0x12) = literalOne19;
                if (spawnIndex17 < 4) {
                    word2 = (unsigned int)spawnIndex17 >> 31;
                    word3 = spawnedOwner16->animationState.id;
                    __asm__("" : "=r"(word3) : "0"(word3), "r"(word2));
                    word2 = ((int)(spawnIndex17 + word2) >> 1) * 2;
                    selector4 = spawnIndex17 - word2;
                    MATCHING_KEEP(selector4);
                    if (word3 != selector4) {
                        word2 = spawnedOwner16->mobyClass;
                        spawnedOwner16->unknown3[1] = 0;
                        word2 <<= 2;
                        /* Original LH class selector becomes a byte offset.
                         * The 32-bit address addition keeps index2 on the left,
                         * then LW fetches the pointer table entry. */
                        word2 += animationTableAddress20;
                        pointer3 = Level37_7E824Field((void*)word2, void**, 0);
                        pointer2 = Level37_7E824Field((unsigned char*)pointer3 + selector4 * 4,
                                                      void**, 0x3C);
                        word2 = Level37_7E824Field(pointer2, unsigned char*, 0);
                        spawnedOwner16->animationState.id = selector4;
                        spawnedOwner16->animationState.nextId = selector4;
                        spawnedOwner16->animationState.frame = 0;
                        spawnedOwner16->animationState.nextFrame = literalOne19;
                        word2 = (unsigned int)word2 < 2U;
                        word2 ^= 1;
                        word2 = -word2;
                        word2 &= 0x30;
                        MATCHING_KEEP(word2);
                        spawnedOwner16->animationProgress = word2;
                    }
                    goto advanceSpawnIndex;
                }
                if (spawnIndex17 < 8) {
                    if (spawnedOwner16->animationState.id != 2) {
                        word3 = 2;
                        word2 = spawnedOwner16->mobyClass;
                        spawnedOwner16->unknown3[1] = 0;
                        word2 <<= 2;
                        word2 += animationTableAddress20;
                        pointer2 = Level37_7E824Field((void*)word2, void**, 0);
                        pointer2 = Level37_7E824Field(pointer2, void**, 0x44);
                        word2 = Level37_7E824Field(pointer2, unsigned char*, 0);
                        spawnedOwner16->animationState.id = word3;
                        spawnedOwner16->animationState.nextId = word3;
                        spawnedOwner16->animationState.frame = 0;
                        spawnedOwner16->animationState.nextFrame = literalOne19;
                        word2 = (unsigned int)word2 < 2U;
                        word2 ^= 1;
                        word2 = -word2;
                        word2 &= 0x30;
                        MATCHING_KEEP(word2);
                        spawnedOwner16->animationProgress = word2;
                    }
                    Level37_7E824CopyVector(&scratch.sp18,
                                            Level37_7E824Field(globalPrivate21, int*, 0x60) +
                                                ((spawnIndex17 % 2) * 0xC));
                    Level37_7E824TransformVectorByBasis(&ownerRecord->rotationMatrix, &scratch.sp18,
                                                        &scratch.sp18);
                    vectorArgument4 = &spawnedOwner16->position;
                    vectorArgument5 = &ownerRecord->position;
                    MATCHING_KEEP2(vectorArgument4, vectorArgument5);
                    word2 = ownerRecord->angle.yaw;
                    /* The original yaw LBU precedes the SP+0x18 argument6
                     * producer. This empty compiler dependency emits no opcode;
                     * argument6 is initialized immediately after it. */
                    __asm__ __volatile__("" : : : "$6", "memory");
                    vectorArgument6 = &scratch.sp18;
                    MATCHING_KEEP2(word2, vectorArgument6);
                    spawnedOwner16->angle.pitch = 0;
                    spawnedOwner16->angle.roll = 0;
                    spawnedOwner16->angle.yaw = word2;
                    Level37_7E824AddVector(vectorArgument4, vectorArgument5, vectorArgument6);
                    spawnIndex17 += 1;
                } else if (spawnIndex17 < 0xA) {
                    if (spawnedOwner16->animationState.id != 3) {
                        word3 = 3;
                        word2 = spawnedOwner16->mobyClass;
                        spawnedOwner16->unknown3[1] = 0;
                        word2 <<= 2;
                        word2 += animationTableAddress20;
                        pointer2 = Level37_7E824Field((void*)word2, void**, 0);
                        pointer2 = Level37_7E824Field(pointer2, void**, 0x48);
                        word2 = Level37_7E824Field(pointer2, unsigned char*, 0);
                        spawnedOwner16->animationState.id = word3;
                        spawnedOwner16->animationState.nextId = word3;
                        spawnedOwner16->animationState.frame = 0;
                        spawnedOwner16->animationState.nextFrame = literalOne19;
                        word2 = (unsigned int)word2 < 2U;
                        word2 ^= 1;
                        word2 = -word2;
                        word2 &= 0x30;
                        MATCHING_KEEP(word2);
                        spawnedOwner16->animationProgress = word2;
                    }
                    vectorArgument4 = &scratch.sp18;
                    MATCHING_KEEP(vectorArgument4);
                    argument5 = (spawnIndex17 % 2) * 0xC;
                    MATCHING_KEEP(argument5);
                    word2 = Level37_7E824Field(globalPrivate21, int*, 0x60);
                    MATCHING_KEEP(word2);
                    argument5 += 0x18;
                    __asm__("" : "=r"(word2) : "0"(word2), "r"(argument5));
                    Level37_7E824CopyVector(vectorArgument4, (Vector3D*)(word2 + argument5));
                    Level37_7E824TransformVectorByBasis(&ownerRecord->rotationMatrix, &scratch.sp18,
                                                        &scratch.sp18);
                    word2 = ownerRecord->angle.yaw;
                    MATCHING_KEEP(word2);
                    spawnedOwner16->angle.pitch = 0;
                    spawnedOwner16->angle.roll = 0;
                    spawnedOwner16->angle.yaw = word2;
                    MATCHING_BARRIER("memory");
                    word2 = spawnIndex17 & 1;
                    vectorArgument4 = &spawnedOwner16->position;
                    if (!word2) {
                        word2 = spawnedOwner16->angle.yaw;
                        word2 += 0x80;
                        spawnedOwner16->angle.yaw = word2;
                    }
                    vectorArgument5 = &ownerRecord->position;
                    vectorArgument6 = &scratch.sp18;
                    Level37_7E824AddVector(vectorArgument4, vectorArgument5, vectorArgument6);
                    spawnIndex17 += 1;
                } else {
                    if (spawnedOwner16->animationState.id != 4) {
                        word3 = 4;
                        word2 = spawnedOwner16->mobyClass;
                        spawnedOwner16->unknown3[1] = 0;
                        word2 <<= 2;
                        word2 += animationTableAddress20;
                        pointer2 = Level37_7E824Field((void*)word2, void**, 0);
                        pointer2 = Level37_7E824Field(pointer2, void**, 0x4C);
                        word2 = Level37_7E824Field(pointer2, unsigned char*, 0);
                        spawnedOwner16->animationState.id = word3;
                        spawnedOwner16->animationState.nextId = word3;
                        spawnedOwner16->animationState.frame = 0;
                        spawnedOwner16->animationState.nextFrame = literalOne19;
                        word2 = (unsigned int)word2 < 2U;
                        word2 ^= 1;
                        word2 = -word2;
                        word2 &= 0x30;
                        MATCHING_KEEP(word2);
                        spawnedOwner16->animationProgress = word2;
                    }
                    vectorArgument4 = &scratch.sp18;
                    MATCHING_KEEP(vectorArgument4);
                    argument5 = (spawnIndex17 % 2) * 0xC;
                    MATCHING_KEEP(argument5);
                    word2 = Level37_7E824Field(globalPrivate21, int*, 0x60);
                    MATCHING_KEEP(word2);
                    argument5 += 0x30;
                    __asm__("" : "=r"(word2) : "0"(word2), "r"(argument5));
                    Level37_7E824CopyVector(vectorArgument4, (Vector3D*)(word2 + argument5));
                    Level37_7E824TransformVectorByBasis(&ownerRecord->rotationMatrix, &scratch.sp18,
                                                        &scratch.sp18);
                    vectorArgument4 = &spawnedOwner16->position;
                    vectorArgument5 = &ownerRecord->position;
                    MATCHING_KEEP2(vectorArgument4, vectorArgument5);
                    word2 = ownerRecord->angle.yaw;
                    __asm__ __volatile__("" : : : "$6", "memory");
                    vectorArgument6 = &scratch.sp18;
                    MATCHING_KEEP2(word2, vectorArgument6);
                    spawnedOwner16->angle.pitch = 0;
                    spawnedOwner16->angle.roll = 0;
                    spawnedOwner16->angle.yaw = word2;
                    Level37_7E824AddVector(vectorArgument4, vectorArgument5, vectorArgument6);
                    if (spawnIndex17 == 0xB) {
                        spawnedOwner16->size = 0x14;
                    }
                    goto advanceSpawnIndex;
                }
            } else {
            advanceSpawnIndex:
                spawnIndex17 += 1;
            }
            if (spawnIndex17 < 0xC) {
                goto spawnLoop;
            }
        }
        MATCHING_KEEP_CLOBBER(ownerRecord, "memory");
        Level37_7E824PlayMobySoundEvent(ownerRecord, 0, 0);
        Level37_7E824DeleteMoby(ownerRecord);
        return;
    }
    ownerRecord->damageFlags = 0;
    if (((unsigned char)ownerRecord->state < 2U) &&
        (Level37_7E824CountTimerDown(privateRecord19, 2) != 0) &&
        (Level37_7E824CountTimerDown(privateRecord19 + 0xB, 1) != 0)) {
        if (ownerRecord->animationState.nextId != 0) {
            Level37_7E824_D_8006C770 = 0;
            animationByte2 = ownerRecord->animationState.nextId;
            animationFrame5 = ownerRecord->animationState.nextFrame;
            ownerRecord->animationProgress = 0x72;
            ownerRecord->animationState.nextId = 0;
            ownerRecord->animationState.nextFrame = 0;
            ownerRecord->animationState.id = animationByte2;
            ownerRecord->animationState.frame = animationFrame5;
            Level37_7E824EmptyAnimationTransitionHook(ownerRecord);
        }
        ownerRecord->state = 0xA;
    }
    stateByte3 = ownerRecord->state;
    switch (stateByte3) {
        case 30:
            Level37_7E824ClearVector(&scratch.sp28);
            Level37_7E824CopyVector(&scratch.sp38, &ownerRecord->position);
            scratch.sp38.z += 0x190;
            SpawnParticle(1, 0, &scratch.sp38, &scratch.sp28);
            if (Level37_7E824_func_80037A60(ownerRecord, privateRecord19 + 8, 2,
                                            -Level37_7E824Field(privateRecord19, short*, 0xC),
                                            -0xC8) != 0) {
                ownerRecord->state = 0x1F;
                return;
            }
            Level37_7E824_func_80035EE0(
                ownerRecord, (int)Level37_7E824Field(privateRecord19, unsigned char*, 0xA),
                (int)Level37_7E824Field(privateRecord19, short*, 6), 0, 0, 0x4001);
            goto prepareCall55;
        case 31:
            if (Level37_7E824CountTimerDown(privateRecord19 + 0xE, 2) != 0) {
                Level37_7E824RefreshMobySpatialGridAndBasis(ownerRecord, 1);
                ownerArgument4 = ownerRecord;
                argument5 = 0;
                __asm__("" : "=r"(ownerArgument4) : "0"(ownerArgument4), "r"(argument5));
                ownerArgument4->unknown3[0] = 1;
                ownerArgument4->lowDrawDistance = 0x40;
                ownerArgument4->drawn = 1;
                goto resetStateAndCall;
            }
        default:
            goto prepareCall55;
        case 0:
        case 1:
            if (ownerRecord->animationState.nextId == 0) {
                Level37_7E824TurnMobyTowardPlayer(ownerRecord, 5, 0x14, 1);
            }
            if (Level37_7E824_D_8006C770 != 0) {
                if (Level37_7E824Field(privateRecord19, short*, 2) == 0) {
                    Level37_7E824RequestMobyAnimation(ownerRecord, 4);
                    Level37_7E824Field(privateRecord19, short*, 2) = Level37_7E824RandBetween(7, 7);
                } else {
                    Level37_7E824RequestMobyAnimation(ownerRecord, 0);
                    Level37_7E824Field(privateRecord19, short*, 2) =
                        (short)((unsigned short)Level37_7E824Field(privateRecord19, short*, 2) - 1);
                }
            }
            goto prepareCall55;
        case 10:
            distanceResult16 = Level37_7E824ApproximatePlanarDistance(
                &ownerRecord->position, &Level37_7E824_D_80070328.position);
            if ((Level37_7E824TurnMobyTowardPlayer(ownerRecord, 6, 0x14, 1) != 0) &&
                (Level37_7E824_func_80035DDC(ownerRecord, 0xB4, 0, 0x190, 0x255) != 0)) {
                Level37_7E824Field(privateRecord19, short*, 0) = 0x78;
                ownerRecord->state = 0;
                Level37_7E824RequestMobyAnimation(ownerRecord, 0);
            }
            if (distanceResult16 < 0x1964) {
                word2 = 5;
                MATCHING_KEEP(word2);
                animationByte3 = ownerRecord->animationState.nextId;
                if (animationByte3 != word2) {
                    ownerArgument4 = ownerRecord;
                    MATCHING_KEEP(ownerArgument4);
                    Level37_7E824_D_8006C770 = 0;
                    MATCHING_BARRIER("memory");
                    animationByte3 = ownerRecord->animationState.nextId;
                    selectedFrame5 = ownerRecord->animationState.nextFrame;
                    __asm__("" : "=r"(selectedFrame5) : "0"(selectedFrame5), "r"(animationByte3));
                    word2 = 0x72;
                    ownerRecord->animationProgress = word2;
                    word2 = 5;
                    ownerRecord->animationState.nextId = word2;
                    ownerRecord->animationState.nextFrame = 0;
                    MATCHING_KEEP_CLOBBER(animationByte3, "memory");
                    ownerRecord->animationState.id = animationByte3;
                    goto updateAnimationFrameAndCall;
                }
                goto checkDistanceAndMovement;
            }
            if (distanceResult16 < 0x1D4D)
                goto checkDistanceAndMovement;
            if (ownerRecord->animationState.nextId == 0)
                goto checkDistanceAndMovement;
            ownerArgument4 = ownerRecord;
            MATCHING_KEEP(ownerArgument4);
            Level37_7E824_D_8006C770 = 0;
            MATCHING_BARRIER("memory");
            otherAnimationByte2 = ownerRecord->animationState.nextId;
            selectedFrame5 = ownerRecord->animationState.nextFrame;
            __asm__("" : "=r"(selectedFrame5) : "0"(selectedFrame5), "r"(otherAnimationByte2));
            word3 = 0x72;
            ownerRecord->animationProgress = word3;
            ownerRecord->animationState.nextId = 0;
            ownerRecord->animationState.nextFrame = 0;
            MATCHING_KEEP_CLOBBER(otherAnimationByte2, "memory");
            ownerRecord->animationState.id = otherAnimationByte2;
        updateAnimationFrameAndCall:
            ownerRecord->animationState.frame = selectedFrame5;
            Level37_7E824EmptyAnimationTransitionHook(ownerArgument4);
        checkDistanceAndMovement:
            predicate2 = distanceResult16 < 0x640;
            if ((predicate2 != 0) ||
                (privatePointer4 = privateRecord19 + 4,
                 (Level37_7E824_D_80070328.movementState == MOVEMENT_STATE_HURT))) {
                privatePointer4 = privateRecord19 + 4;
                if (Level37_7E824Field(privateRecord19, short*, 4) == 0) {
                    Level37_7E824Field(privateRecord19, short*, 4) = 0xA;
                    Level37_7E824_D_80070328.unk22[5] = (int)ownerRecord->angle.yaw;
                }
            }
            if (Level37_7E824CountTimerDown(privatePointer4, 2) == 2) {
                ownerArgument4 = ownerRecord;
                argument5 = 0;
                __asm__("" : "=r"(ownerArgument4) : "0"(ownerArgument4), "r"(argument5));
                selectedHalfword2 = 0x78;
                goto storeSelectedHalfword;
            }
            predicate2 = initialMetric17 < 0x23;
            ownerArgument4 = ownerRecord;

            if (predicate2)
                goto call55WithPreparedOwner;
            argument5 = 0;
            selectedHalfword2 = 0x3C;
    }
storeSelectedHalfword:
    Level37_7E824Field(privateRecord19, short*, 0) = selectedHalfword2;
/* The state31 and final state10 paths share the original late reset. */
resetStateAndCall:
    ownerArgument4->state = 0;
    Level37_7E824RequestMobyAnimation(ownerArgument4, argument5);
    return;
prepareCall55:
    ownerArgument4 = ownerRecord;
/* The final threshold branch targets the original call after its owner
 * argument is ready;
  other paths retain the preceding owner producer. */
call55WithPreparedOwner:
    Level37_7E824RefreshMobySpatialGridAndBasis(ownerArgument4, 5);
    return;
}
#undef Level37_7E824Field

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007EFFC.
* Assembly SHA256 01ecba18c489db3e8b42204b603aa2da70406c97c3deb640cb54c9f7794a533d.
* AI generated;not human reviewed. All781 instructions and every actual
* native/linked target must match. Frame98 preserves S0..S6/RA and full
* SP38..77 local extent. Original code-byte checksum cursor2AB38..2AE00,
* eight bit steps,80050000 polynomial,FFF0000F/000FFFF0 masks and fourteen
* independent70300 byte views retain their exact widths and addresses.
* Analysis-only decoder input folds16 equivalent relocation sums because
* its parser rejected multi-addend symbols;original assembly is unchanged.
* The initial2/1/0 update and0/1/10/5 state dispatch retain original A3=1
* comparisons. Known2-input37BBC/359A4,3-input3B7B4/4E880 and2-input spawn
* views remove unused decoder arguments. Every native argument-register
* producer remains exact. Initial record pointer/S0=1,index/child S1 and
* later private-tag S4 roles retain complete,separate lifetimes. Signed
* clamp1/minus1 producers and every original recheck remain explicit.
* The five-word stack clear/list scan preserves707/447/16/211 comparisons,
* field accesses,counters and original shared state5 stores/call. Two
* complete signed low32 products preserve native MULT/MFLO T2 and their
* original arithmetic shifts12/stack zero placement. The ordinary retained
* rand word copies into S0 in3636C's original call delay. A volatile byte
* view preserves original branch344's reload target without adding a load.
* Initialized empty identities/late inputs/dead clobbers emit zero words.
* No opcode assembly,partialHI,fixedFP,unknown saved-register inputs or
* overlapping live aliases. Raw units/fixed point,remaining complete helper
* contracts,caller cadence and synchronized retail runtime remain open.
* Cadence is per invocation;checksum advances one byte/eight bit steps
* while its original unsigned cursor bound holds. Confidence is Rev0
* binary identity after all gates. Falsification:every native/linked word,
* actual branch/call target,full EXE and every overlay retail hash.
*/
#define Level37_7EFFCField(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Level37_7EFFCCall34F40View1() __asm__("func_80034F40");
int Level37_7EFFCEmptyAnimationTransitionHookView1() __asm__("func_80035734");
int Level37_7EFFCTurnMobyTowardPlayerView1() __asm__("func_8003573C");
int Level37_7EFFCCountTimerDownView1(void*, int) __asm__("func_800359A4");
int Level37_7EFFCSubAngle8View1() __asm__("func_8003613C");
int Level37_7EFFCRandBetweenView1() __asm__("func_8003636C");
int Level37_7EFFCCall365E4View1() __asm__("func_800365E4");
int Level37_7EFFCCall37014View1() __asm__("func_80037014");
int Level37_7EFFCCall37BBCView1(void*, int) __asm__("func_80037BBC");
void Level37_7EFFCCall3B7B4View1(void*, int, void*) __asm__("func_8003B7B4");
int Level37_7EFFCPlayMobySoundEventView1() __asm__("func_8003BABC");
int Level37_7EFFCCall3BE70View1() __asm__("func_8003BE70");
int Level37_7EFFCCall3BFC0View1() __asm__("func_8003BFC0");
int Level37_7EFFCPlanarHeadingLookupView1(int, int, int) __asm__("func_8004E880");
int Level37_7EFFCCopyVectorView1() __asm__("func_8004F178");
int Level37_7EFFCAddVectorView1() __asm__("func_8004F194");
int Level37_7EFFCApproximatePlanarDistanceView1() __asm__("func_8004F334");
int Level37_7EFFCCall512E4View1() __asm__("func_800512E4");
int Level37_7EFFCDeleteMobyView1() __asm__("func_80055B18");
int Level37_7EFFCRefreshMobySpatialGridAndBasisView1() __asm__("func_80055D24");
int Level37_7EFFCDatarandView1(void) __asm__("rand");
extern int Level37_7EFFCData658A0View1 __asm__("D_800658A0");
extern int Level37_7EFFCData65920View1 __asm__("D_80065920");
extern unsigned char Level37_7EFFCData6C40AView1 __asm__("D_8006C40A");
extern int Level37_7EFFCData6C550View1 __asm__("D_8006C550");
extern int Level37_7EFFCData6C598View1 __asm__("D_8006C598");
extern int Level37_7EFFCData6C640View1 __asm__("D_8006C640");
extern int Level37_7EFFCData6C770View1 __asm__("D_8006C770");
extern int Level37_7EFFCData6C7C4View1 __asm__("D_8006C7C4");
extern int Level37_7EFFCData6C7F8View1 __asm__("D_8006C7F8");
extern int Level37_7EFFCData6D088View1 __asm__("D_8006D088");
extern int Level37_7EFFCData6E344View1 __asm__("D_8006E344");
extern int Level37_7EFFCData6E788View1 __asm__("D_8006E788");
extern int Level37_7EFFCData70300View1 __asm__("D_80070300");
extern int Level37_7EFFCData70328View1 __asm__("D_80070328");
extern signed char Level37_7EFFCData71586View1 __asm__("D_80071586");
extern signed char Level37_7EFFCData71587View1 __asm__("D_80071587");
extern unsigned char Level37_7EFFCData7158EView1 __asm__("D_8007158E");
extern int Level37_7EFFCData722B8View1 __asm__("D_800722B8");
extern void* (*Level37_7EFFCDataSpawnMobyView1)(int, void*)__asm__("SpawnMoby");
extern int (*Level37_7EFFCData74314View1)() __asm__("unk_ovlheader_80074314");
extern int Level37_7EFFCData74454View1 __asm__("unk_ovlheader_80074454");
extern unsigned char Level37_7EFFCData2AB38View1 __asm__("func_8002AB38");
extern unsigned char Level37_7EFFCData2AE00View1 __asm__("func_8002AE00");
extern unsigned char Level37_7EFFCData70300View2 __asm__("D_80070300 + 0x1");
extern unsigned char Level37_7EFFCData70300View3 __asm__("D_80070300 + 0x2");
extern unsigned char Level37_7EFFCData70300View4 __asm__("D_80070300 + 0x3");
extern unsigned char Level37_7EFFCData70300View5 __asm__("D_80070300 + 0x4");
extern unsigned char Level37_7EFFCData70300View6 __asm__("D_80070300 + 0xa");
extern unsigned char Level37_7EFFCData70300View7 __asm__("D_80070300 + 0xb");
extern unsigned char Level37_7EFFCData70300View8 __asm__("D_80070300 + 0xc");
extern unsigned char Level37_7EFFCData70300View9 __asm__("D_80070300 + 0xd");
extern unsigned char Level37_7EFFCData70300View10 __asm__("D_80070300 + 0xe");
extern unsigned char Level37_7EFFCData70300View11 __asm__("D_80070300 + 0x13");
extern unsigned char Level37_7EFFCData70300View12 __asm__("D_80070300 + 0x14");
extern unsigned char Level37_7EFFCData70300View13 __asm__("D_80070300 + 0x15");
extern unsigned char Level37_7EFFCData70300View14 __asm__("D_80070300 + 0x16");
extern unsigned char Level37_7EFFCData70300View15 __asm__("D_80070300 + 0x17");
void func_level_37_8007EFFC(void* input) {
    int retainedRandomWord;
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"),
        argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"),
        completeLowProduct10 __asm__("$10"), classConstant8 __asm__("$8"),
        classConstant9 __asm__("$9");
    register void* ownerRecord19 __asm__("$19");
    register int privateRecord18 __asm__("$18"), addressOrResult16 __asm__("$16"),
        retainedResultOrChild17 __asm__("$17"), retainedByteOrRecord20 __asm__("$20"),
        retainedDistance21 __asm__("$21"), retainedRecord22 __asm__("$22");
    struct {
        int sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C,
            sp70, sp74;
    } originalFrame;
    ownerRecord19 = input;
    MATCHING_KEEP(ownerRecord19);
    privateRecord18 = Level37_7EFFCField(ownerRecord19, int*, 0);
    rawWord3 = Level37_7EFFCField(privateRecord18, int*, 0x38);
    MATCHING_KEEP_CLOBBER(rawWord3, "$20");
    retainedByteOrRecord20 = Level37_7EFFCData6C40AView1;
    __asm__("" : "=r"(retainedByteOrRecord20) : "0"(retainedByteOrRecord20), "r"(rawWord3) : "$2");
    rawWord2 = rawWord3 * 88;
    rawWord3 = Level37_7EFFCData6C550View1;
    addressOrResult16 = rawWord3 + rawWord2;
    rawWord2 = 2;
    rawWord3 = Level37_7EFFCData6C7C4View1;
    retainedRecord22 = Level37_7EFFCField(addressOrResult16, int*, 0);
    if (rawWord3 == rawWord2) {
        retainedByteOrRecord20 -= 4;
        if (retainedByteOrRecord20 < 0)
            retainedByteOrRecord20 = 0;
    } else {
        rawWord2 = 1;
        if (rawWord3 == rawWord2)
            retainedByteOrRecord20 += 2;
        else if (rawWord3 == 0)
            retainedByteOrRecord20 += 5;
    }
    if (Level37_7EFFCData7158EView1 != 0) {
        retainedByteOrRecord20 = 0;
    }
    if (Level37_7EFFCField(privateRecord18, unsigned char**, 0x4C) == 0) {
        Level37_7EFFCField(privateRecord18, unsigned char**, 0x4C) = &Level37_7EFFCData2AB38View1;
    }
    rawWord3 = Level37_7EFFCField(privateRecord18, unsigned char**, 0x4C);
    argumentWord4 = 0;
    if ((unsigned int)rawWord3 < (unsigned int)&Level37_7EFFCData2AE00View1) {
        Level37_7EFFCField(privateRecord18, int*, 0x50) =
            (int)(Level37_7EFFCField(privateRecord18, int*, 0x50) ^
                  (Level37_7EFFCField(rawWord3, unsigned char*, 0) << 0x18));
        do {
            rawWord2 = Level37_7EFFCField(privateRecord18, int*, 0x50);
            if (rawWord2 < 0) {
                rawWord2 = (rawWord2 * 2) ^ 0x80050000;
            } else {
                rawWord2 = rawWord2 * 2;
            }
            Level37_7EFFCField(privateRecord18, int*, 0x50) = rawWord2;
            argumentWord4 += 1;
        } while (argumentWord4 < 8);
        Level37_7EFFCField(privateRecord18, unsigned char**, 0x4C) =
            (unsigned char*)(Level37_7EFFCField(privateRecord18, unsigned char**, 0x4C) + 1);
    } else if (((((int)Level37_7EFFCField(privateRecord18, int*, 0x50) >> 0xC) & 0xFFFF0) |
                (Level37_7EFFCData722B8View1 & 0xFFF0000F)) != Level37_7EFFCData74454View1) {
        Level37_7EFFCData71587View1 = 0;
        Level37_7EFFCData71586View1 = 0;
        Level37_7EFFCData70300View2 = (unsigned char)(Level37_7EFFCData70300View2 & 0xFE);
        Level37_7EFFCData70300View3 = (unsigned char)(Level37_7EFFCData70300View3 & 0xFE);
        Level37_7EFFCData70300View4 = (unsigned char)(Level37_7EFFCData70300View4 & 0xFE);
        Level37_7EFFCData70300View5 = (unsigned char)(Level37_7EFFCData70300View5 & 0xFE);
        Level37_7EFFCData70300View6 = (unsigned char)(Level37_7EFFCData70300View6 & 0xFE);
        Level37_7EFFCData70300View7 = (unsigned char)(Level37_7EFFCData70300View7 & 0xFE);
        Level37_7EFFCData70300View8 = (unsigned char)(Level37_7EFFCData70300View8 & 0xFE);
        Level37_7EFFCData70300View9 = (unsigned char)(Level37_7EFFCData70300View9 & 0xFE);
        Level37_7EFFCData70300View10 = (unsigned char)(Level37_7EFFCData70300View10 & 0xFE);
        Level37_7EFFCData70300View11 = (unsigned char)(Level37_7EFFCData70300View11 & 0xFE);
        Level37_7EFFCData70300View12 = (unsigned char)(Level37_7EFFCData70300View12 & 0xFE);
        Level37_7EFFCData70300View13 = (unsigned char)(Level37_7EFFCData70300View13 & 0xFE);
        Level37_7EFFCData70300View14 = (unsigned char)(Level37_7EFFCData70300View14 & 0xFE);
        Level37_7EFFCData70300View15 = (unsigned char)(Level37_7EFFCData70300View15 & 0xFE);
        Level37_7EFFCField(privateRecord18, int*, 0x50) = 0;
    }
    rawWord3 = Level37_7EFFCField(ownerRecord19, unsigned char*, 0x48);
    argumentWord7 = 1;
    MATCHING_KEEP(argumentWord7);
    if (rawWord3 == argumentWord7)
        goto dispatchOriginalStateOne;
    rawWord2 = rawWord3 < 2;
    if (rawWord2) {
        if (rawWord3 == 0)
            goto dispatchOriginalStateZero;
        return;
    }
    rawWord2 = 5;
    if (rawWord3 == rawWord2)
        goto dispatchOriginalStateFive;
    rawWord2 = 10;
    argumentWord6 = 0;
    if (rawWord3 == rawWord2)
        goto dispatchOriginalStateTen;
    return;
dispatchOriginalStateZero:
    if (Level37_7EFFCData6C640View1 == 0) {
        Level37_7EFFCField(ownerRecord19, signed char*, 0x47) = 2;
    }
    if (({
            rawWord2 = Level37_7EFFCField(privateRecord18, int*, 0x58);
            addressOrResult16 = 1;
            rawWord2;
        })) {
        if (Level37_7EFFCData6C640View1 == 0) {
            MATCHING_BARRIER_GNU_VOLATILE("$3");
            argumentWord6 = 0;
            MATCHING_KEEP(argumentWord6);
            rawWord2 =
                Level37_7EFFCField(Level37_7EFFCField(privateRecord18, void**, 0x2C), void**, 0xC);
            rawWord2 = Level37_7EFFCPlanarHeadingLookupView1(
                Level37_7EFFCField((int)&Level37_7EFFCData70328View1, int*, 0) -
                    Level37_7EFFCField(rawWord2, int*, 0),
                Level37_7EFFCField((int)&Level37_7EFFCData70328View1, int*, 4) -
                    Level37_7EFFCField(rawWord2, int*, 4),
                argumentWord6);
            rawWord3 = 22;
            retainedResultOrChild17 = rawWord2;
            Level37_7EFFCField(ownerRecord19, unsigned char*, 0x4F) = rawWord3;
            rawWord2 = Level37_7EFFCField(privateRecord18, int*, 0x2C);
            addressOrResult16 = retainedResultOrChild17 + 64;
            argumentWord5 = Level37_7EFFCField(rawWord2, int*, 12);
            addressOrResult16 &= 255;
            Level37_7EFFCCopyVectorView1(&originalFrame.sp38, argumentWord5);
            addressOrResult16 *= 2;
            originalFrame.sp38 += (int)(Level37_7EFFCField((int)&Level37_7EFFCData65920View1,
                                                           short*, addressOrResult16) *
                                        7) >>
                                  1;
            originalFrame.sp3C += (int)(Level37_7EFFCField((int)&Level37_7EFFCData658A0View1,
                                                           short*, addressOrResult16) *
                                        7) >>
                                  1;
            Level37_7EFFCCopyVectorView1(ownerRecord19 + 0xC, &originalFrame.sp38);
            Level37_7EFFCCall37014View1(ownerRecord19);
            Level37_7EFFCField(ownerRecord19, unsigned char*, 0x52) = 0xFE;
            Level37_7EFFCRefreshMobySpatialGridAndBasisView1(ownerRecord19, 2);
            retainedResultOrChild17 += 0xC0;
            MATCHING_KEEP(retainedResultOrChild17);
            Level37_7EFFCField(ownerRecord19, unsigned char*, 0x46) = retainedResultOrChild17;
        }
        Level37_7EFFCField(ownerRecord19, unsigned char*, 0x48) = 0xAU;
        addressOrResult16 = privateRecord18 + 0x58;
        Level37_7EFFCCall3B7B4View1(addressOrResult16, 4, (int)&Level37_7EFFCData6D088View1);
        Level37_7EFFCCall3B7B4View1(addressOrResult16, 4, (int)&Level37_7EFFCData6C7F8View1);
        Level37_7EFFCCall34F40View1(ownerRecord19, 0);
        return;
    }
    Level37_7EFFCField(ownerRecord19, short*, 0x38) = 0;
    Level37_7EFFCField(privateRecord18, signed char*, 5) = addressOrResult16;
    rawWord2 = Level37_7EFFCData6C598View1;
    argumentWord4 = (int)ownerRecord19;
    if (rawWord2)
        return;
    __asm__ __volatile__("" ::: "$2", "$3");
    rawWord2 = Level37_7EFFCCall37BBCView1(argumentWord4, 0);
    argumentWord4 = (int)ownerRecord19;
    if (!rawWord2)
        return;
    Level37_7EFFCCall512E4View1(argumentWord4, 0, 1);
    Level37_7EFFCField(ownerRecord19, unsigned char*, 0x48) = addressOrResult16;
    return;
dispatchOriginalStateOne:
    addressOrResult16 = privateRecord18 + 0x58;
    if (Level37_7EFFCData6E344View1 != argumentWord7) {
        argumentWord4 = addressOrResult16;
        argumentWord5 = 4;
        argumentWord6 = (int)&Level37_7EFFCData6D088View1;
        __asm__(""
                : "=r"(argumentWord6)
                : "0"(argumentWord6), "r"(argumentWord4), "r"(argumentWord5)
                : "$3");
        Level37_7EFFCField(privateRecord18, int*, 0x58) = argumentWord7;
        Level37_7EFFCCall3B7B4View1(argumentWord4, argumentWord5, argumentWord6);
        Level37_7EFFCCall3B7B4View1(addressOrResult16, 4, (int)&Level37_7EFFCData6C7F8View1);
        argumentWord4 = (int)ownerRecord19;
        MATCHING_KEEP(argumentWord4);
        argumentWord5 = 0;
        rawWord2 = 10;
        goto storeOriginalStateAndCall;
    }
    return;
dispatchOriginalStateTen:
    argumentWord7 = Level37_7EFFCField(ownerRecord19, int*, 0xC);
    rawWord2 = Level37_7EFFCField(Level37_7EFFCField(privateRecord18, void**, 0x2C), void**, 0xC);
    rawWord2 = Level37_7EFFCPlanarHeadingLookupView1(
        argumentWord7 - Level37_7EFFCField(rawWord2, int*, 0),
        Level37_7EFFCField(ownerRecord19, int*, 0x10) - Level37_7EFFCField(rawWord2, int*, 4), 0);
    MATCHING_BARRIER_GNU_VOLATILE("$6");
    argumentWord6 = 0;
    MATCHING_KEEP_CLOBBER(argumentWord6, "$17");
    retainedResultOrChild17 = rawWord2;
    rawWord3 = Level37_7EFFCField(privateRecord18, int*, 0x2C);
    argumentWord4 = Level37_7EFFCField(addressOrResult16, int*, 12);
    rawWord3 = Level37_7EFFCField(rawWord3, int*, 12);
    argumentWord5 = Level37_7EFFCField(addressOrResult16, int*, 16);
    argumentWord7 = Level37_7EFFCField(rawWord3, int*, 0);
    rawWord3 = Level37_7EFFCField(rawWord3, int*, 4);
    argumentWord4 = argumentWord7 - argumentWord4;
    argumentWord5 = rawWord3 - argumentWord5;
    rawWord2 = Level37_7EFFCPlanarHeadingLookupView1(argumentWord4, argumentWord5, argumentWord6);
    argumentWord4 = retainedResultOrChild17 & 255;
    rawWord2 -= 128;
    argumentWord5 = rawWord2 & 255;
    addressOrResult16 = Level37_7EFFCSubAngle8View1(argumentWord4, argumentWord5);
    retainedDistance21 = Level37_7EFFCApproximatePlanarDistanceView1(
        ownerRecord19 + 0xC,
        Level37_7EFFCField(Level37_7EFFCField(privateRecord18, void**, 0x2C), void**, 0xC));
    if (Level37_7EFFCField(ownerRecord19, unsigned char*, 0x4F) == 0) {
        Level37_7EFFCField(ownerRecord19, unsigned char*, 0x4F) = 0x20U;
    }
    rawWord3 = Level37_7EFFCField(ownerRecord19, volatile unsigned char*, 0x4F);
    if ((rawWord3 >= 0x17U) && !(Level37_7EFFCData6C640View1 & 7)) {
        rawWord2 = rawWord3 - 1;
        Level37_7EFFCField(ownerRecord19, unsigned char*, 0x4F) = rawWord2;
    }
    if (addressOrResult16 >= 0) {
        rawWord2 = addressOrResult16;
    } else {
        rawWord2 = addressOrResult16;
        MATCHING_KEEP(rawWord2);
        rawWord2 = -rawWord2;
    }
    argumentWord5 = 4;
    if (rawWord2 >= 0x15) {
        MATCHING_KEEP(argumentWord5);
        if (addressOrResult16 >= 2) {
            addressOrResult16 = 1;
            MATCHING_KEEP(addressOrResult16);
        }
        if (addressOrResult16 < -1) {
            addressOrResult16 = -1;
            MATCHING_KEEP(addressOrResult16);
        }
        rawWord2 = addressOrResult16 * 4;
        addressOrResult16 += rawWord2;
        argumentWord7 = retainedResultOrChild17 + addressOrResult16;
        MATCHING_KEEP(argumentWord7);
        argumentWord4 = (int)ownerRecord19;
        MATCHING_KEEP(argumentWord4);
        Level37_7EFFCData74314View1(
            argumentWord4,
            Level37_7EFFCField(Level37_7EFFCField(privateRecord18, void**, 0x2C), void**, 0xC),
            0x3864, argumentWord7 & 0xFF, 4, 0x6E, 5, 0xC, 0xFF, 0xFF, 0, 0, 0);
        if (Level37_7EFFCField(ownerRecord19, unsigned char*, 0x3D) != 2) {
            argumentWord4 = (int)ownerRecord19;
            MATCHING_KEEP(argumentWord4);
            Level37_7EFFCData6C770View1 = 0;
            Level37_7EFFCField(ownerRecord19, signed char*, 0x40) = 0x72;
            Level37_7EFFCField(ownerRecord19, unsigned char*, 0x3D) = 2U;
            goto callOriginalSharedStateHelper;
        }
    } else if ((Level37_7EFFCTurnMobyTowardPlayerView1(ownerRecord19, argumentWord5, 0, 0) != 0) &&
               (Level37_7EFFCField(ownerRecord19, unsigned char*, 0x3D) != 0)) {
        argumentWord4 = (int)ownerRecord19;
        MATCHING_KEEP(argumentWord4);
        Level37_7EFFCData6C770View1 = 0;
        Level37_7EFFCField(ownerRecord19, signed char*, 0x40) = 0x72;
        Level37_7EFFCField(ownerRecord19, unsigned char*, 0x3D) = 0U;
    callOriginalSharedStateHelper:
        Level37_7EFFCField(ownerRecord19, signed char*, 0x3F) = 0;
        Level37_7EFFCEmptyAnimationTransitionHookView1(argumentWord4);
    }
    if ((Level37_7EFFCField(retainedRecord22, short*, 0x56) != 0) &&
        (addressOrResult16 = 0, ((({
                                     rawWord2 = retainedDistance21 < 0x360D;
                                     MATCHING_KEEP(rawWord2);
                                     rawWord2;
                                 })) == 0))) {
        addressOrResult16 = 0;
        MATCHING_KEEP_CLOBBER(addressOrResult16, "$2");
        retainedResultOrChild17 = 0;
        argumentWord4 = (int)&Level37_7EFFCData6E788View1;
        rawWord3 = 4;
        rawWord2 = (int)&originalFrame.sp48;
        do {
            Level37_7EFFCField(rawWord2, int*, 16) = 0;
            rawWord3--;
            rawWord2 -= 4;
        } while (rawWord3 >= 0);
        rawWord3 = Level37_7EFFCField(argumentWord4, int*, 0);
        argumentWord4 += 4;
        if (rawWord3) {
            classConstant9 = 707;
            MATCHING_KEEP_CLOBBER(classConstant9, "$5");
            argumentWord5 = (int)&originalFrame.sp38;
            MATCHING_KEEP_CLOBBER(argumentWord5, "$8");
            classConstant8 = 447;
            MATCHING_KEEP_CLOBBER(classConstant8, "$7");
            argumentWord7 = 16;
            MATCHING_KEEP_CLOBBER(argumentWord7, "$6");
            argumentWord6 = 211;
            do {
                rawWord2 = Level37_7EFFCField(rawWord3, short*, 0x36);
                if (rawWord2 == classConstant9) {
                    rawWord3 = Level37_7EFFCField(rawWord3, unsigned char*, 0x49);
                    rawWord3 <<= 2;
                    rawWord3 += argumentWord5;
                    rawWord2 = Level37_7EFFCField(rawWord3, int*, 16);
                    addressOrResult16++;
                    rawWord2++;
                    Level37_7EFFCField(rawWord3, int*, 16) = rawWord2;
                } else if (rawWord2 == classConstant8 || rawWord2 == argumentWord7 ||
                           rawWord2 == argumentWord6) {
                    retainedResultOrChild17++;
                }
                rawWord3 = Level37_7EFFCField(argumentWord4, int*, 0);
                argumentWord4 += 4;
            } while (rawWord3);
        }
        if ((Level37_7EFFCCountTimerDownView1(privateRecord18 + 0x30, 4) != 0) && ({
                rawWord2 = addressOrResult16 < 3;
                MATCHING_KEEP(rawWord2);
                rawWord2;
            })) {
            addressOrResult16 = 3;
            if (Level37_7EFFCDatarandView1() & 1) {
                addressOrResult16 = 4;
            }
            rawWord2 = Level37_7EFFCRandBetweenView1(500, 700);
            argumentWord4 = (int)ownerRecord19;
            argumentWord5 = 5;
            __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(argumentWord4));
            Level37_7EFFCField(privateRecord18, int*, 0x30) = rawWord2;
            rawWord2 = 707;
            Level37_7EFFCField(privateRecord18, int*, 0x3C) = rawWord2;
            rawWord2 = 20;
            Level37_7EFFCField(privateRecord18, int*, 0x44) = rawWord2;
            rawWord2 = 5;
            Level37_7EFFCField(privateRecord18, int*, 0x40) = addressOrResult16;
            goto clearOriginalSubstateBeforeSharedCall;
        }
        MATCHING_BARRIER_GNU_VOLATILE("$3");
        rawWord2 = Level37_7EFFCData6C7C4View1;
        rawWord3 = retainedByteOrRecord20 < 7;
        rawWord2 ^= 2;
        addressOrResult16 = (unsigned int)rawWord2 > 0;
        if (rawWord3 == 0) {
            addressOrResult16 = 2;
        }
        if ((Level37_7EFFCField((int)&Level37_7EFFCData70328View1, int*, 0x280) >= 2) &&
            (rawWord3 != 0)) {
            addressOrResult16 = 0;
        }
        if ((Level37_7EFFCCountTimerDownView1(privateRecord18 + 0x34, 4) != 0) && ({
                rawWord2 = retainedResultOrChild17 < addressOrResult16;
                MATCHING_KEEP(rawWord2);
                rawWord2;
            })) {
            rawWord2 = Level37_7EFFCRandBetweenView1(700, 1000);
            argumentWord4 = (int)ownerRecord19;
            argumentWord5 = 5;
            __asm__("" : "=r"(argumentWord5) : "0"(argumentWord5), "r"(argumentWord4));
            Level37_7EFFCField(privateRecord18, int*, 0x34) = rawWord2;
            rawWord2 = 5;
            Level37_7EFFCField(privateRecord18, int*, 0x3C) = rawWord2;
            rawWord2 = 20;
            Level37_7EFFCField(privateRecord18, int*, 0x44) = rawWord2;
            rawWord2 = 5;
            Level37_7EFFCField(privateRecord18, int*, 0x40) = 0;
        clearOriginalSubstateBeforeSharedCall:
            Level37_7EFFCField(argumentWord4, signed char*, 0x49) = 0;
        storeOriginalStateAndCall:
            Level37_7EFFCField(argumentWord4, signed char*, 0x48) = rawWord2;
            Level37_7EFFCCall34F40View1(argumentWord4, argumentWord5);
            return;
        }
    }
    return;
dispatchOriginalStateFive:
    rawWord2 = Level37_7EFFCField(ownerRecord19, unsigned char*, 0x49);
    if (rawWord2 == 0)
        goto processOriginalStateFiveSelectorZero;
    if (rawWord2 == argumentWord7)
        goto processOriginalStateFiveSelectorOne;
    return;
processOriginalStateFiveSelectorZero:
    if (Level37_7EFFCField(privateRecord18, void**, 0x48) == 0) {
        rawWord2 = Level37_7EFFCDataSpawnMobyView1(0x41, ownerRecord19);
        Level37_7EFFCField(privateRecord18, void**, 0x48) = rawWord2;
        Level37_7EFFCField(rawWord2, unsigned char*, 0x46) =
            (unsigned char)Level37_7EFFCField(ownerRecord19, unsigned char*, 0x46);
        argumentWord4 = Level37_7EFFCField(privateRecord18, void**, 0x48);
        Level37_7EFFCField(argumentWord4, int*, 0xC) =
            (int)(Level37_7EFFCField(argumentWord4, int*, 0xC) +
                  ((int)(Level37_7EFFCField(
                             (int)&Level37_7EFFCData65920View1, short*,
                             (Level37_7EFFCField(ownerRecord19, unsigned char*, 0x46) * 2)) *
                         0xAF) >>
                   0xA));
        argumentWord4 = Level37_7EFFCField(privateRecord18, void**, 0x48);
        Level37_7EFFCField(argumentWord4, int*, 0x10) =
            (int)(Level37_7EFFCField(argumentWord4, int*, 0x10) +
                  ((int)(Level37_7EFFCField(
                             (int)&Level37_7EFFCData658A0View1, short*,
                             (Level37_7EFFCField(ownerRecord19, unsigned char*, 0x46) * 2)) *
                         0xAF) >>
                   0xA));
        rawWord3 = Level37_7EFFCField(privateRecord18, void**, 0x48);
        Level37_7EFFCField(rawWord3, int*, 0x14) =
            (int)(Level37_7EFFCField(rawWord3, int*, 0x14) + 0x1C2);
        Level37_7EFFCField(Level37_7EFFCField(privateRecord18, void**, 0x48), signed char*, 0x47) =
            8;
        Level37_7EFFCField(Level37_7EFFCField(privateRecord18, void**, 0x48), signed char*, 0x4C) =
            0x50;
        Level37_7EFFCField(Level37_7EFFCField(privateRecord18, void**, 0x48), signed char*, 0x4E) =
            0x3F;
    }
    if (Level37_7EFFCCall3BFC0View1(ownerRecord19,
                                    Level37_7EFFCField(privateRecord18, int*, 0x54)) == 0) {
        Level37_7EFFCField(privateRecord18, int*, 0x54) =
            Level37_7EFFCPlayMobySoundEventView1(ownerRecord19, 0, 4);
    }
    argumentWord4 = privateRecord18 + 0x44;
    if ((Level37_7EFFCCountTimerDownView1(argumentWord4, 4) != 0) &&
        (Level37_7EFFCTurnMobyTowardPlayerView1(ownerRecord19, 5, 0, 0) != 0)) {
        retainedResultOrChild17 = Level37_7EFFCDataSpawnMobyView1(0x2C3, ownerRecord19);
        MATCHING_KEEP(retainedResultOrChild17);
        if (retainedResultOrChild17 != 0) {
            rawWord3 = 707;
            rawWord2 = Level37_7EFFCField(privateRecord18, int*, 0x40);
            Level37_7EFFCField(retainedResultOrChild17, unsigned char*, 0x49) = rawWord2;
            rawWord2 = Level37_7EFFCField(privateRecord18, int*, 0x3C);
            retainedByteOrRecord20 = Level37_7EFFCField(retainedResultOrChild17, int*, 0);
            if (rawWord2 != rawWord3) {
                rawWord2 = 5;
                Level37_7EFFCField(retainedResultOrChild17, unsigned char*, 0x49) = rawWord2;
            }
            rawWord2 = 20;
            Level37_7EFFCField(retainedResultOrChild17, unsigned char*, 0x48) = rawWord2;
            rawWord2 = 63;
            Level37_7EFFCField(retainedResultOrChild17, unsigned char*, 0x4C) = rawWord2;
            Level37_7EFFCField(retainedResultOrChild17, unsigned char*, 0x4E) = rawWord2;
            rawWord2 = Level37_7EFFCField(ownerRecord19, unsigned char*, 0x46);
            rawWord2 *= 2;
            rawWord3 = Level37_7EFFCField((int)&Level37_7EFFCData65920View1, short*, rawWord2);
            rawWord2 = rawWord3 * 125;
            rawWord3 = Level37_7EFFCField(retainedResultOrChild17, int*, 12);
            rawWord2 >>= 9;
            rawWord3 += rawWord2;
            Level37_7EFFCField(retainedResultOrChild17, int*, 12) = rawWord3;
            rawWord3 = Level37_7EFFCField(ownerRecord19, unsigned char*, 0x46);
            rawWord2 = Level37_7EFFCField(retainedResultOrChild17, int*, 20);
            rawWord3 *= 2;
            rawWord3 = Level37_7EFFCField((int)&Level37_7EFFCData658A0View1, short*, rawWord3);
            rawWord2 += 500;
            Level37_7EFFCField(retainedResultOrChild17, int*, 20) = rawWord2;
            rawWord2 = rawWord3 * 125;
            rawWord3 = Level37_7EFFCField(retainedResultOrChild17, int*, 16);
            rawWord2 >>= 9;
            rawWord3 += rawWord2;
            Level37_7EFFCField(retainedResultOrChild17, int*, 16) = rawWord3;
            retainedRandomWord = Level37_7EFFCDatarandView1();
            rawWord2 = Level37_7EFFCRandBetweenView1(3000, 7000);
            addressOrResult16 = (retainedRandomWord & 255) * 2;
            rawWord3 =
                Level37_7EFFCField((int)&Level37_7EFFCData65920View1, short*, addressOrResult16);
            completeLowProduct10 = rawWord3 * rawWord2;
            MATCHING_KEEP(completeLowProduct10);
            rawWord3 = completeLowProduct10 >> 12;
            originalFrame.sp38 = rawWord3;
            rawWord3 =
                Level37_7EFFCField((int)&Level37_7EFFCData658A0View1, short*, addressOrResult16);
            completeLowProduct10 = rawWord3 * rawWord2;
            originalFrame.sp40 = 0;
            MATCHING_KEEP(completeLowProduct10);
            rawWord2 = completeLowProduct10 >> 12;
            originalFrame.sp3C = rawWord2;
            Level37_7EFFCAddVectorView1(
                &originalFrame.sp38, &originalFrame.sp38,
                Level37_7EFFCField(Level37_7EFFCField(privateRecord18, void**, 0x2C), void**, 0xC));
            Level37_7EFFCField(retainedByteOrRecord20, short*, 0) = 0x140;
            Level37_7EFFCField(retainedByteOrRecord20, short*, 4) =
                Level37_7EFFCPlanarHeadingLookupView1(
                    originalFrame.sp38 - Level37_7EFFCField(retainedResultOrChild17, int*, 0xC),
                    originalFrame.sp3C - Level37_7EFFCField(retainedResultOrChild17, int*, 0x10),
                    0);
            Level37_7EFFCField(retainedByteOrRecord20, short*, 6) = -0xE;
            Level37_7EFFCField(retainedByteOrRecord20, short*, 2) = Level37_7EFFCCall365E4View1(
                retainedResultOrChild17 + 0xC, &originalFrame.sp38,
                Level37_7EFFCField(retainedByteOrRecord20, short*, 0), -0xE, &originalFrame.sp60);
        }
        Level37_7EFFCField(ownerRecord19, unsigned char*, 0x49) =
            (unsigned char)(Level37_7EFFCField(ownerRecord19, unsigned char*, 0x49) + 1);
        Level37_7EFFCField(privateRecord18, int*, 0x44) = 0x1E;
        return;
    }
    return;
processOriginalStateFiveSelectorOne:
    if (Level37_7EFFCCountTimerDownView1(privateRecord18 + 0x44, 4) != 0) {
        if (Level37_7EFFCCall3BFC0View1(ownerRecord19,
                                        Level37_7EFFCField(privateRecord18, int*, 0x54)) != 0) {
            Level37_7EFFCCall3BE70View1(Level37_7EFFCField(privateRecord18, int*, 0x54));
        }
        argumentWord4 = Level37_7EFFCField(privateRecord18, void**, 0x48);
        Level37_7EFFCField(privateRecord18, int*, 0x54) = -1;
        if (argumentWord4 != 0) {
            Level37_7EFFCDeleteMobyView1(argumentWord4);
            Level37_7EFFCField(privateRecord18, void**, 0x48) = 0;
        }
        if (Level37_7EFFCField(ownerRecord19, unsigned char*, 0x3D) != 0) {
            Level37_7EFFCData6C770View1 = 0;
            Level37_7EFFCField(ownerRecord19, signed char*, 0x40) = 0x72;
            Level37_7EFFCField(ownerRecord19, unsigned char*, 0x3D) = 0U;
            Level37_7EFFCField(ownerRecord19, signed char*, 0x3F) = 0;
            Level37_7EFFCEmptyAnimationTransitionHookView1(ownerRecord19);
        }
        Level37_7EFFCField(ownerRecord19, unsigned char*, 0x48) = 0xAU;
    }
    return;
    return;
}
#undef Level37_7EFFCField

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
typedef void (*Level37_7FC30HudCallback)(void*);
typedef union {
    long long full;
    struct {
#if defined(__MIPSEB__)
        int high;
        unsigned low;
#else
        unsigned low;
        int high;
#endif
    } words;
} Level37_7FC30Product;
extern int Level37_7FC30Player488 __asm__("D_80070328+488");
#define Level37_7FC30Multiply(a, b)                               \
    do {                                                          \
        product.full = (long long)(int)(a) * (long long)(int)(b); \
        __asm__("" : "=x"(product.full) : "0"(product.full));     \
    } while (0)
#define Level37_7FC30Low(v)         \
    do {                            \
        v = (int)product.words.low; \
        Level37_7FC30Keep(v);       \
    } while (0)
#define Level37_7FC30Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
#define Level37_7FC30Keep(v) __asm__("" : "=r"(v) : "0"(v))
int Level37_7FC30_func_80018368() __asm__("func_80018368");
int Level37_7FC30_func_80019194() __asm__("func_80019194");
int Level37_7FC30_func_8001BA30() __asm__("func_8001BA30");
int Level37_7FC30_func_8002803C(int, int, Level37_7FC30HudCallback, Level37_7FC30HudCallback,
                                Level37_7FC30HudCallback, int*, int) __asm__("func_8002803C");
int Level37_7FC30CountTimerDown() __asm__("func_800359A4");
int Level37_7FC30ProbeGroundFromRaisedMoby() __asm__("func_80035D38");
int Level37_7FC30SubAngle8() __asm__("func_8003613C");
int Level37_7FC30RandSignedBetween() __asm__("func_800363DC");
int Level37_7FC30_func_80037014() __asm__("func_80037014");
int Level37_7FC30_func_80038000() __asm__("func_80038000");
int Level37_7FC30_func_800391E8() __asm__("func_800391E8");
int Level37_7FC30PlayMobySoundEvent() __asm__("func_8003BABC");
int Level37_7FC30_func_8003BE70() __asm__("func_8003BE70");
int Level37_7FC30_func_8003BFC0() __asm__("func_8003BFC0");
int Level37_7FC30_func_8003C140() __asm__("func_8003C140");
int Level37_7FC30_func_80049484() __asm__("func_80049484");
int Level37_7FC30PlanarHeadingLookup() __asm__("func_8004E880");
int Level37_7FC30BuildPackedAngleBasisMatrix() __asm__("func_8004EA90");
int Level37_7FC30TransformVectorByBasis() __asm__("func_8004ED6C");
int Level37_7FC30MeasureVectorLength() __asm__("func_8004EDE8");
int Level37_7FC30_func_8004EF74() __asm__("func_8004EF74");
int Level37_7FC30ScaleVectorRatioQ15() __asm__("func_8004F08C");
int Level37_7FC30ClearVector() __asm__("func_8004F168");
int Level37_7FC30CopyVector() __asm__("func_8004F178");
int Level37_7FC30AddVector() __asm__("func_8004F194");
int Level37_7FC30SubtractVector() __asm__("func_8004F1C8");
int Level37_7FC30AbsoluteByteAngleDelta() __asm__("func_8004F264");
int Level37_7FC30ApproximatePlanarDistance() __asm__("func_8004F334");
int Level37_7FC30_func_80050844() __asm__("func_80050844");
int Level37_7FC30DeleteMoby() __asm__("func_80055B18");
int Level37_7FC30RefreshMobySpatialGridAndBasis() __asm__("func_80055D24");
int Level37_7FC30_func_8005629C() __asm__("func_8005629C");
int Level37_7FC30_rand() __asm__("rand");
extern int Level37_7FC30_D_800658A0 __asm__("D_800658A0");
extern int Level37_7FC30_D_80065920 __asm__("D_80065920");
extern int Level37_7FC30_D_8006C550 __asm__("D_8006C550");
extern int Level37_7FC30_D_8006C770 __asm__("D_8006C770");
extern unsigned short Level37_7FC30_D_8006E03E __asm__("D_8006E03E");
extern unsigned short Level37_7FC30_D_8006E040 __asm__("D_8006E040");
extern int Level37_7FC30_D_8006E044 __asm__("D_8006E044");
extern int Level37_7FC30_D_8006E788 __asm__("D_8006E788");
extern int Level37_7FC30_D_8006EE2C __asm__("D_8006EE2C");
extern int Level37_7FC30_D_80070328 __asm__("D_80070328");
extern int Level37_7FC30_D_80071920 __asm__("D_80071920");
extern int (*Level37_7FC30SpawnMoby)() __asm__("SpawnMoby");
extern int (*Level37_7FC30SpawnParticle)() __asm__("SpawnParticle");
extern Level37_7FC30HudCallback
    Level37_7FC30_unk_ovlheader_800743B8 __asm__("unk_ovlheader_800743B8");
extern Level37_7FC30HudCallback
    Level37_7FC30_unk_ovlheader_800743BC __asm__("unk_ovlheader_800743BC");
extern Level37_7FC30HudCallback
    Level37_7FC30_unk_ovlheader_800743C0 __asm__("unk_ovlheader_800743C0");
void func_level_37_8007FC30(void* ownerInput) {
    int descriptorAddress;
    Level37_7FC30HudCallback callbackWord3, callbackWord4;

    register int temporary2 __asm__("$2"), temporary3 __asm__("$3"), argument0 __asm__("$4"),
        argument1 __asm__("$5"), argument2 __asm__("$6"), argument3 __asm__("$7"),
        temporary8 __asm__("$8");
    Level37_7FC30Product product;

    register int owner __asm__("$18"), privateState __asm__("$19"), savedPointer21 __asm__("$21"),
        savedPointer23 __asm__("$23");
    register int working16 __asm__("$16"), working17 __asm__("$17"), working20 __asm__("$20"),
        value22 __asm__("$22");
    struct {
        int sp20, sp24, sp28, pad2C;
        int sp30, sp34, sp38, pad3C;
        int sp40[6];
        int sp58, sp5C, sp60, pad64;
        int sp68[6];
        int sp80, sp84, sp88, pad8C;
        int sp90, sp94, sp98, pad9C;
        int spA0, spA4, spA8;
        int unusedOriginalAC_BB[4];
    } locals;
    int var_a1;
    int temp_a3;
    int temp_a3_2;
    int temp_v0_14;
    int temp_v0_15;
    int temp_v0_2;
    int temp_v0_3;
    short temp_v1_3;

    int temp_a0;

    int temp_a0_5;
    int temp_lo;
    int temp_v0;
    int temp_v0_10;
    int temp_v0_6;
    int temp_v0_7;
    int temp_v0_8;
    int temp_v1_2;
    int temp_v1_4;
    int temp_v1_5;
    int temp_v1_7;
    int temp_v1_9;
    int var_v0_2;
    int var_v0_3;

    int var_v0_5;
    int var_v1_2;
    int var_v1_3;

    unsigned char temp_v0_11;
    unsigned char temp_v0_5;
    unsigned char temp_v1;
    int temp_v1_6;

    int temp_a0_10;
    int temp_a0_11;
    int temp_a0_2;
    int temp_a0_3;
    int temp_a0_4;
    int temp_a0_6;
    int temp_a0_7;
    int temp_a0_8;
    int temp_a0_9;
    int temp_v0_12;
    int temp_v0_13;

    int temp_v1_8;
    owner = (int)ownerInput;
    Level37_7FC30Keep(owner);
    privateState = Level37_7FC30Field(owner, int*, 0);
    working16 = Level37_7FC30_D_8006C550;
    temp_v1 = Level37_7FC30Field(owner, unsigned char*, 0x48);
    savedPointer23 = Level37_7FC30Field(working16, int*, 0);
    savedPointer21 = privateState;
    if (temp_v1 != 2) {
        switch (temp_v1) {
            case 21:
                Level37_7FC30Field(owner, signed char*, 0x4F) = 0x20;
                Level37_7FC30Field(owner, signed char*, 0x4C) = 0x50;
                Level37_7FC30Field(owner, unsigned char*, 0x45) = 0U;
                Level37_7FC30Field(owner, signed char*, 0x4D) = 1;
                Level37_7FC30Field(owner, signed char*, 0x41) = 1;
                Level37_7FC30Field(owner, signed char*, 0x4C) = 0x3F;
                Level37_7FC30Field(owner, signed char*, 0x4D) = 1;
                temp_v0 = Level37_7FC30Field(savedPointer23, int*, 0x6C) - 1;
                Level37_7FC30Field(savedPointer23, int*, 0x6C) = temp_v0;
                if (temp_v0 < 0) {
                    Level37_7FC30Field(savedPointer23, int*, 0x6C) = 0;
                }
                argument0 = owner + 0xC;
                if (Level37_7FC30_D_8006E044 == 7) {
                    Level37_7FC30Keep(owner);
                    MATCHING_BARRIER_VOLATILE("$4");
                    Level37_7FC30_func_80049484(owner + 0xC);
                } else {
                    Level37_7FC30Keep(argument0);
                    Level37_7FC30Field(owner, int*, 0xC) =
                        (int)((int)(Level37_7FC30Field(
                                        (int)&Level37_7FC30_D_80065920 +
                                            (Level37_7FC30Field((int)&Level37_7FC30_D_80070328,
                                                                unsigned char*, 0xE) *
                                             2),
                                        short*, 0) *
                                    0x4B) >>
                              9);
                    temp_a3 =
                        Level37_7FC30Field((int)&Level37_7FC30_D_800658A0 +
                                               (Level37_7FC30Field((int)&Level37_7FC30_D_80070328,
                                                                   unsigned char*, 0xE) *
                                                2),
                                           short*, 0);
                    Level37_7FC30Field(owner, int*, 0x14) = 0xC8;
                    Level37_7FC30Field(owner, int*, 0x10) = (int)((int)(temp_a3 * 0x4B) >> 9);
                    Level37_7FC30AddVector(argument0, argument0,
                                           ((int)&Level37_7FC30_D_80070328 + 0xE) - 0xE, temp_a3);
                }
                Level37_7FC30Field(savedPointer21, short*, 0x16) = -1;
                Level37_7FC30Field(savedPointer21, unsigned char*, 0x10) = 0U;
                Level37_7FC30Field(savedPointer21, unsigned char*, 0x12) =
                    (unsigned char)(Level37_7FC30Field((int)&Level37_7FC30_D_80070328,
                                                       unsigned char*, 0xE) +
                                    Level37_7FC30Field((int)&Level37_7FC30_D_80070328,
                                                       unsigned char*, 0x12));
                if (Level37_7FC30_D_8006E044 == 7) {
                    Level37_7FC30Field(savedPointer21, unsigned char*, 0x11) =
                        (unsigned char)(4 - ((int)(Level37_7FC30_D_8006E03E << 0x10) >> 0x14));
                    Level37_7FC30Field(savedPointer21, unsigned char*, 0x12) =
                        (unsigned char)((unsigned short)Level37_7FC30_D_8006E040 >> 4);
                } else if (Level37_7FC30Field(savedPointer23, unsigned char*, 0x70) != 0) {
                    Level37_7FC30Field(savedPointer21, unsigned char*, 0x11) = 4U;
                } else {
                    Level37_7FC30Field(savedPointer21, unsigned char*, 0x11) = 0U;
                }
                Level37_7FC30Field(owner, unsigned char*, 0x44) =
                    (unsigned char)Level37_7FC30Field(savedPointer21, unsigned char*, 0x10);
                Level37_7FC30Field(owner, unsigned char*, 0x45) =
                    (unsigned char)Level37_7FC30Field(savedPointer21, unsigned char*, 0x11);
                Level37_7FC30Field(owner, unsigned char*, 0x46) =
                    (unsigned char)Level37_7FC30Field(savedPointer21, unsigned char*, 0x12);
                Level37_7FC30Field(savedPointer21, short*, 8) = 0xB4;
                Level37_7FC30Field(savedPointer21, short*, 0xE) = -1;
                Level37_7FC30Field(savedPointer21, short*, 0xA) = 0x190;
                if (Level37_7FC30Field(savedPointer23, unsigned char*, 0x70) != 0) {
                    if (Level37_7FC30AbsoluteByteAngleDelta(
                            Level37_7FC30PlanarHeadingLookup(
                                Level37_7FC30Field(working16, int*, 0xC) -
                                    Level37_7FC30Field(owner, int*, 0xC),
                                Level37_7FC30Field(working16, int*, 0x10) -
                                    Level37_7FC30Field(owner, int*, 0x10),
                                0),
                            Level37_7FC30Field(owner, unsigned char*, 0x46)) < 0x10) {
                        Level37_7FC30Field(savedPointer21, short*, 0xE) = 0;
                    }
                    temporary3 = Level37_7FC30Field(owner, unsigned char*, 60);
                    temporary2 = 23;
                    Level37_7FC30Field(owner, unsigned char*, 72) = temporary2;
                    temporary2 = 4;
                    if (temporary3 != temporary2) {
                        temporary3 = 4;
                        Level37_7FC30Keep(temporary3);
                        temporary2 = Level37_7FC30Field(owner, short*, 54);
                        temporary2 *= 4;
                        temporary2 = Level37_7FC30Field((int)&Level37_7FC30_D_8006EE2C + temporary2,
                                                        int*, 0);
                        temporary2 = Level37_7FC30Field(temporary2, int*, 0x4C);
                        Level37_7FC30_D_8006C770 = 0;
                        temporary2 = Level37_7FC30Field(temporary2, unsigned char*, 0);
                        Level37_7FC30Field(owner, unsigned char*, 60) = temporary3;
                        goto block_20;
                    }
                } else {
                    temporary3 = Level37_7FC30Field(owner, unsigned char*, 60);
                    temporary2 = 22;
                    Level37_7FC30Field(owner, unsigned char*, 72) = temporary2;
                    temporary2 = 3;
                    if (temporary3 != temporary2) {
                        temporary3 = 3;
                        Level37_7FC30Keep(temporary3);
                        temporary2 = Level37_7FC30Field(owner, short*, 54);
                        temporary2 *= 4;
                        temporary2 = Level37_7FC30Field((int)&Level37_7FC30_D_8006EE2C + temporary2,
                                                        int*, 0);
                        temporary2 = Level37_7FC30Field(temporary2, int*, 0x48);
                        Level37_7FC30_D_8006C770 = 0;
                        temporary2 = Level37_7FC30Field(temporary2, unsigned char*, 0);
                        Level37_7FC30Field(owner, unsigned char*, 60) = temporary3;
                    block_20:
                        Level37_7FC30Field(owner, signed char*, 61) = temporary3;
                        temporary3 = 1;
                        Level37_7FC30Field(owner, signed char*, 62) = 0;
                        Level37_7FC30Field(owner, signed char*, 63) = temporary3;
                        __asm__ volatile(""
                                         : "=r"(temporary2)
                                         : "0"(temporary2),
                                           "m"(Level37_7FC30Field(owner, signed char*, 63))
                                         : "memory");
                        temporary2 = (unsigned int)temporary2 < 2U;
                        temporary2 ^= 1;
                        temporary2 = -temporary2;
                        Level37_7FC30Keep(temporary2);
                        temporary2 &= 48;
                        Level37_7FC30Field(owner, signed char*, 64) = temporary2;
                    }
                }
                temporary3 = 1;
                temporary2 = 80;
                Level37_7FC30Field(owner, signed char*, 65) = temporary3;
                Level37_7FC30Field(owner, signed char*, 76) = temporary2;
                Level37_7FC30Field(owner, signed char*, 77) = temporary3;
            case 22:
            case 23:
                temporary2 = Level37_7FC30_func_8003BFC0(
                    owner, Level37_7FC30Field(savedPointer21, short*, 22));
                argument0 = owner;
                if (temporary2 == 0) {
                    Level37_7FC30Keep(argument0);
                    argument1 = 3;
                    argument2 = 4;
                    Level37_7FC30Field(savedPointer21, short*, 22) =
                        Level37_7FC30PlayMobySoundEvent(argument0, argument1, argument2);
                }
                argument0 = savedPointer21 + 16;
                if (Level37_7FC30Field(owner, unsigned char*, 0x48) == 0x17) {
                    working16 = (int)&locals.sp40;
                    argument1 = working16;
                    temporary2 = Level37_7FC30Field(savedPointer21, short*, 6);
                    argument2 = 0;
                    temporary3 = temporary2 * 2;
                    temporary2 += 16;
                    Level37_7FC30Keep(temporary2);
                    argument3 =
                        Level37_7FC30Field((int)&Level37_7FC30_D_80065920 + temporary3, short*, 0);
                    temporary3 =
                        Level37_7FC30Field((int)&Level37_7FC30_D_800658A0 + temporary3, short*, 0);
                    Level37_7FC30Keep(temporary3);
                    temporary2 &= 255;
                    Level37_7FC30Field(savedPointer21, short*, 6) = temporary2;
                    locals.sp30 = 400;
                    temporary2 = argument3 * 25;
                    temporary2 >>= 11;
                    locals.sp34 = temporary2;
                    temporary2 = temporary3 * 25;
                    temporary2 >>= 11;
                    locals.sp38 = temporary2;
                    Level37_7FC30BuildPackedAngleBasisMatrix(argument0, argument1, argument2,
                                                             argument3);
                    Level37_7FC30TransformVectorByBasis(working16, &locals.sp30, &locals.sp30);
                    Level37_7FC30Field(savedPointer21, short*, 0) = (short)locals.sp30;
                    Level37_7FC30Field(savedPointer21, short*, 2) = (short)locals.sp34;
                    Level37_7FC30Field(savedPointer21, short*, 4) = (short)locals.sp38;
                    Level37_7FC30Field(owner, unsigned char*, 0x45) =
                        Level37_7FC30PlanarHeadingLookup(
                            Level37_7FC30MeasureVectorLength(&locals.sp30, 0), locals.sp38, 0);
                    Level37_7FC30Field(owner, unsigned char*, 0x46) =
                        Level37_7FC30PlanarHeadingLookup(locals.sp30, locals.sp34, 0);
                    temp_v1_3 = Level37_7FC30Field(savedPointer21, short*, 0xE);
                    if (temp_v1_3 != -1) {
                        Level37_7FC30CopyVector(&locals.sp58, Level37_7FC30_D_8006C550 +
                                                                  (temp_v1_3 * 0x58) + 0xC);
                        locals.sp60 += 0x73A;
                        var_v1_2 = Level37_7FC30SubAngle8(
                            Level37_7FC30Field(savedPointer21, unsigned char*, 0x12),
                            Level37_7FC30PlanarHeadingLookup(
                                locals.sp58 - Level37_7FC30Field(owner, int*, 0xC),
                                locals.sp5C - Level37_7FC30Field(owner, int*, 0x10), 0));
                        if (var_v1_2 >= 3)
                            var_v1_2 = 2;
                        if (var_v1_2 < -2)
                            var_v1_2 = -2;
                        Level37_7FC30Field(savedPointer21, unsigned char*, 0x12) =
                            (unsigned char)(Level37_7FC30Field(savedPointer21, unsigned char*,
                                                               0x12) +
                                            var_v1_2);
                        var_v1_3 = Level37_7FC30SubAngle8(
                            Level37_7FC30Field(savedPointer21, unsigned char*, 0x11),
                            Level37_7FC30PlanarHeadingLookup(
                                Level37_7FC30ApproximatePlanarDistance(owner + 0xC, &locals.sp58),
                                locals.sp60 - Level37_7FC30Field(owner, int*, 0x14), 0));
                        if (var_v1_3 >= 3)
                            var_v1_3 = 2;
                        if (var_v1_3 < -2)
                            var_v1_3 = -2;
                        Level37_7FC30Field(savedPointer21, unsigned char*, 0x11) =
                            (unsigned char)(Level37_7FC30Field(savedPointer21, unsigned char*,
                                                               0x11) +
                                            var_v1_3);
                    }
                } else {
                    working16 = (int)&locals.sp68;
                    argument1 = working16;
                    temporary2 = Level37_7FC30Field(savedPointer21, short*, 6);
                    argument2 = 0;
                    temporary3 = temporary2 * 2;
                    temporary2 += 14;
                    Level37_7FC30Keep(temporary2);
                    temporary3 =
                        Level37_7FC30Field((int)&Level37_7FC30_D_80065920 + temporary3, short*, 0);
                    Level37_7FC30Keep(temporary3);
                    temporary2 &= 255;
                    Level37_7FC30Field(savedPointer21, short*, 6) = temporary2;
                    temporary2 = 400;
                    locals.sp30 = temporary2;
                    locals.sp38 = 0;
                    __asm__ volatile("" ::"m"(locals.sp38));
                    temporary2 = temporary3 * 25;
                    temporary2 >>= 11;
                    locals.sp34 = temporary2;
                    Level37_7FC30BuildPackedAngleBasisMatrix(argument0, argument1, argument2);
                    Level37_7FC30TransformVectorByBasis(working16, &locals.sp30, &locals.sp30);
                    Level37_7FC30Field(savedPointer21, short*, 0) = (short)locals.sp30;
                    Level37_7FC30Field(savedPointer21, short*, 2) = (short)locals.sp34;
                    Level37_7FC30Field(savedPointer21, short*, 4) = (short)locals.sp38;
                    Level37_7FC30Field(owner, unsigned char*, 0x46) =
                        Level37_7FC30PlanarHeadingLookup(locals.sp30, locals.sp34, 0);
                }
                argument0 = (int)&locals.sp20;
                Level37_7FC30Keep(argument0);
                working17 = owner + 12;
                Level37_7FC30CopyVector(argument0, working17);
                Level37_7FC30AddVector(working17, working17, &locals.sp30);

                temporary2 = Level37_7FC30MeasureVectorLength(&locals.sp30, 1);
                working20 = 300;
                Level37_7FC30Keep(working20);
                temporary3 = temporary2 + 8;
                if (temporary3 > working20) {
                    working20 = temporary3;
                }
                if (Level37_7FC30Field(owner, unsigned char*, 0x48) == 0x17) {
                    temporary2 = Level37_7FC30RandSignedBetween(0, 7);
                    argument0 = 0;
                    argument1 = 7;
                    MATCHING_KEEP2_VOLATILE_CLOBBER(argument0, argument1, "memory");
                    locals.sp80 = temporary2;
                    temporary2 = Level37_7FC30RandSignedBetween(argument0, argument1);
                    argument0 = 1;
                    argument1 = 0x3A;
                } else {
                    temporary2 = Level37_7FC30RandSignedBetween(0, 7);
                    argument0 = 0;
                    argument1 = 7;
                    MATCHING_KEEP2_VOLATILE_CLOBBER(argument0, argument1, "memory");
                    locals.sp80 = temporary2;
                    temporary2 = Level37_7FC30RandSignedBetween(argument0, argument1);
                    argument0 = 1;
                    argument1 = 0xD;
                }
                locals.sp84 = temporary2;
                locals.sp88 = 0xF;
                Level37_7FC30SpawnParticle(argument0, argument1, working17, &locals.sp80);
                __asm__ volatile("" ::: "$17", "memory");
                if (Level37_7FC30CountTimerDown(savedPointer21 + 8, 2) != 0) {
                    Level37_7FC30Field(owner, unsigned char*, 0x48) = 0x18U;
                }
                if ((Level37_7FC30Field(owner, int*, 0xC) < 0x400) ||
                    (Level37_7FC30Field(owner, int*, 0x10) < 0x400) ||
                    (Level37_7FC30Field(owner, int*, 0x14) < 0x400)) {
                    Level37_7FC30Field(owner, unsigned char*, 0x48) = 0x18U;
                }
                argument0 = (int)&locals.sp20;
                Level37_7FC30Keep(argument0);
                working16 = owner + 12;
                temporary2 = Level37_7FC30_func_80018368(argument0, working16);
                argument0 = working16;
                if (temporary2) {
                    argument1 = working16;
                    Level37_7FC30SubtractVector(argument0, argument1, &locals.sp30);
                    Level37_7FC30Field(owner, unsigned char*, 0x48) = 0x18U;
                }
                working16 = Level37_7FC30_func_8001BA30(working16, 0x12C, 0, 0, 0x100000, owner);
                Level37_7FC30Keep(working16);
                Level37_7FC30Keep(owner);
                argument0 = owner + 0xC;
                if (working16 != 0) {
                    temp_v0_5 = Level37_7FC30PlanarHeadingLookup(
                        (int)Level37_7FC30Field(savedPointer21, short*, 0),
                        (int)Level37_7FC30Field(savedPointer21, short*, 2), 0);
                    Level37_7FC30Keep(owner);
                    Level37_7FC30Field(working16, unsigned char*, 0x51) = temp_v0_5;
                    if (!(temp_v0_5 & 0xFF)) {
                        Level37_7FC30Field(working16, unsigned char*, 0x51) = 1U;
                    }
                    Level37_7FC30Field(owner, unsigned char*, 0x48) = 0x18U;
                    argument0 = owner + 0xC;
                }
                if (Level37_7FC30_func_80019194(argument0, working20) != 0) {
                    Level37_7FC30Field(owner, unsigned char*, 0x48) = 0x18U;
                }
                goto block_125;
            case 24:
                working20 = 0;
                Level37_7FC30Keep(working20);
                value22 = 2;
                Level37_7FC30Keep(value22);
                privateState = working20 * 2;
                do {
                    if (Level37_7FC30AbsoluteByteAngleDelta(
                            Level37_7FC30Field(privateState +
                                                   Level37_7FC30Field(savedPointer23, int*, 0xB8),
                                               unsigned char*, 0),
                            Level37_7FC30Field(owner, unsigned char*, 0x46)) < 0x3C) {
                        working16 = Level37_7FC30SpawnMoby(0x169, owner);
                        Level37_7FC30Keep(working16);
                        if (working16 != 0) {
                            temporary2 = Level37_7FC30Field(working16, unsigned char*, 60);
                            working17 = Level37_7FC30Field(working16, int*, 0);
                            MATCHING_BARRIER_VOLATILE("$3");
                            if (temporary2 != value22) {
                                temporary3 = 1;
                                Level37_7FC30Keep(temporary3);
                                temporary2 = Level37_7FC30Field(working16, short*, 54);
                                Level37_7FC30Field(working16, signed char*, 66) = 0;
                                temporary2 *= 4;
                                temporary2 = Level37_7FC30Field(
                                    (int)&Level37_7FC30_D_8006EE2C + temporary2, int*, 0);
                                temporary2 = Level37_7FC30Field(temporary2, int*, 68);
                                temporary2 = Level37_7FC30Field(temporary2, unsigned char*, 0);
                                Level37_7FC30Field(working16, unsigned char*, 60) = value22;
                                Level37_7FC30Field(working16, signed char*, 61) = value22;
                                Level37_7FC30Field(working16, signed char*, 62) = 0;
                                Level37_7FC30Field(working16, signed char*, 63) = temporary3;
                                __asm__ volatile(
                                    ""
                                    : "=r"(temporary2)
                                    : "0"(temporary2),
                                      "m"(Level37_7FC30Field(working16, signed char*, 63))
                                    : "memory");
                                temporary2 = (unsigned int)temporary2 < 2U;
                                temporary2 ^= 1;
                                temporary2 = -temporary2;
                                temporary2 &= 48;
                                Level37_7FC30Field(working16, signed char*, 64) = temporary2;
                            }
                            temporary2 =
                                Level37_7FC30_func_80050844(working16 + 12, 7, 10, 0x40E080);
                            Level37_7FC30Field(working17, int*, 8) = temporary2;
                            temporary2 = Level37_7FC30Field(savedPointer23, int*, 184);
                            temporary2 = privateState + temporary2;
                            temporary2 = Level37_7FC30Field(temporary2, unsigned char*, 0);
                            temporary2 += 128;
                            Level37_7FC30Field(working17, signed char*, 1) = temporary2;
                            temporary2 = Level37_7FC30Field(savedPointer23, int*, 184);
                            temporary2 = privateState + temporary2;
                            temporary3 = Level37_7FC30Field(temporary2, unsigned char*, 1);
                            temporary2 = 50;
                            Level37_7FC30Field(working17, int*, 4) = temporary2;
                            temporary2 = 300;
                            Level37_7FC30Field(working17, short*, 2) = temporary2;
                            Level37_7FC30Field(working17, unsigned char*, 0) = temporary3;
                            temporary2 = Level37_7FC30_rand();
                            Level37_7FC30Field(working16, signed char*, 68) = temporary2;
                            Level37_7FC30Field(working16, signed char*, 72) = value22;
                        }
                    }
                    working20 += 1;
                    privateState = working20 * 2;
                } while (working20 < 0x20);
                if (Level37_7FC30_func_8003BFC0(
                        owner, Level37_7FC30Field(savedPointer21, short*, 0x16)) != 0) {
                    Level37_7FC30_func_8003BE70(Level37_7FC30Field(savedPointer21, short*, 0x16));
                }
                Level37_7FC30Field(savedPointer21, short*, 0x16) = -1;
                Level37_7FC30PlayMobySoundEvent(owner, 2, 0);
                goto block_124;
            case 4:
                temp_v0_10 = Level37_7FC30Field(privateState, int*, 0x10) + 0x1F4;
                Level37_7FC30Field(privateState, int*, 0x10) = temp_v0_10;
                if (temp_v0_10 < 0x5DC) {
                    Level37_7FC30Field(privateState, int*, 0x10) = 0x5DC;
                }
                if (Level37_7FC30Field(privateState, int*, 0x10) < 0x7001) {
                    working17 = (int)&Level37_7FC30_D_8006E788;
                    Level37_7FC30Keep(working17);
                    working16 = Level37_7FC30Field(working17, int*, 0);
                    working17 += 4;
                    if (working16 != 0) {
                        do {
                            if ((Level37_7FC30Field(working16, short*, 0x36) != 0x19F) &&
                                (Level37_7FC30ApproximatePlanarDistance(owner + 0xC,
                                                                        working16 + 0xC) <
                                 Level37_7FC30Field(privateState, int*, 0x10))) {
                                Level37_7FC30Field(working16, int*, 0x18) = 0x100000;
                                temp_v0_11 = Level37_7FC30PlanarHeadingLookup(
                                    Level37_7FC30Field(working16, int*, 0xC) -
                                        Level37_7FC30Field(owner, int*, 0xC),
                                    Level37_7FC30Field(working16, int*, 0x10) -
                                        Level37_7FC30Field(owner, int*, 0x10),
                                    0);
                                Level37_7FC30Field(working16, unsigned char*, 0x51) = temp_v0_11;
                                if (!(temp_v0_11 & 0xFF)) {
                                    Level37_7FC30Field(working16, unsigned char*, 0x51) = 1U;
                                }
                            }
                            working16 = Level37_7FC30Field(working17, int*, 0);
                            working17 += 4;
                        } while (working16 != 0);
                    }
                    goto block_125;
                }
                goto block_124;
            case 20:
                temporary3 = Level37_7FC30Field(owner, int*, 20);
                Level37_7FC30Keep(temporary3);
                if (temporary3 >= 30721) {
                    temporary2 = 1;
                    goto block_161;
                }
                temporary2 = Level37_7FC30Field(owner, int*, 12);
                if (temporary2 < 1024) {
                    temporary2 = 1;
                    goto block_161;
                }
                temporary2 = Level37_7FC30Field(owner, int*, 16);
                if (temporary2 < 1024) {
                    temporary2 = 1;
                    goto block_161;
                }
                temporary2 = temporary3 < 1024;
                Level37_7FC30Keep(temporary2);
                if (temporary2) {
                    temporary2 = 1;
                    goto block_161;
                }

                if (Level37_7FC30Field(privateState, int*, 0xC) == 0) {
                    if (Level37_7FC30Field(owner, unsigned char*, 0x49) == 5) {
                        temp_v0_12 = Level37_7FC30SpawnMoby(0x1BF, owner);
                        Level37_7FC30Field(privateState, int*, 0xC) = temp_v0_12;
                        if (temp_v0_12 != 0) {
                            if (Level37_7FC30Field(temp_v0_12, unsigned char*, 0x3C) != 1) {
                                Level37_7FC30Field(temp_v0_12, signed char*, 0x42) = 0;
                                temp_v1_8 = Level37_7FC30Field(privateState, int*, 0xC);
                                Level37_7FC30Field(temp_v1_8, signed char*, 0x40) =
                                    (signed char)(-((unsigned char)Level37_7FC30Field(
                                                        Level37_7FC30Field(
                                                            Level37_7FC30Field(
                                                                (int)&Level37_7FC30_D_8006EE2C +
                                                                    (Level37_7FC30Field(
                                                                         temp_v1_8, short*, 0x36) *
                                                                     4),
                                                                int*, 0),
                                                            unsigned char**, 0x40),
                                                        unsigned char*, 0) >= 2U) &
                                                  0x30);
                                Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                                   unsigned char*, 0x3C) = 1U;
                                Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                                   unsigned char*, 0x3D) = 1U;
                                Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                                   signed char*, 0x3E) = 0;
                                Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                                   signed char*, 0x3F) = 1;
                            }
                            Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                               unsigned char*, 0x48) = 0x63U;
                            Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                               signed char*, 0x4C) = 0x50;
                            Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                               signed char*, 0x4E) = 0x50;
                        }
                    } else {
                        temp_v0_13 =
                            Level37_7FC30SpawnMoby(Level37_7FC30Field(owner, short*, 0x36), owner);
                        Level37_7FC30Field(privateState, int*, 0xC) = temp_v0_13;
                        if (temp_v0_13 != 0) {
                            Level37_7FC30Field(temp_v0_13, signed char*, 0x48) = 2;
                            temp_a0_6 = Level37_7FC30Field(privateState, int*, 0xC);
                            if (Level37_7FC30Field(temp_a0_6, unsigned char*, 0x3C) !=
                                Level37_7FC30Field(owner, unsigned char*, 0x49)) {
                                Level37_7FC30Field(temp_a0_6, signed char*, 0x42) = 0;
                                temp_a0_7 = Level37_7FC30Field(privateState, int*, 0xC);
                                Level37_7FC30Field(temp_a0_7, signed char*, 0x40) =
                                    (signed char)(-((unsigned char)Level37_7FC30Field(
                                                        Level37_7FC30Field(
                                                            ((Level37_7FC30Field(
                                                                  owner, unsigned char*, 0x49) *
                                                              4) +
                                                             Level37_7FC30Field(
                                                                 (int)&Level37_7FC30_D_8006EE2C +
                                                                     (Level37_7FC30Field(
                                                                          temp_a0_7, short*, 0x36) *
                                                                      4),
                                                                 int*, 0)),
                                                            unsigned char**, 0x3C),
                                                        unsigned char*, 0) >= 2U) &
                                                  0x30);
                                Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                                   unsigned char*, 0x3C) =
                                    (unsigned char)Level37_7FC30Field(owner, unsigned char*, 0x49);
                                Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                                   unsigned char*, 0x3D) =
                                    (unsigned char)Level37_7FC30Field(owner, unsigned char*, 0x49);
                                Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                                   signed char*, 0x3E) = 0;
                                Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                                   signed char*, 0x3F) = 1;
                            }
                            Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                               signed char*, 0x4C) = 0x50;
                            Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                               signed char*, 0x4E) = 0x50;
                            if (Level37_7FC30Field(owner, unsigned char*, 0x49) == 1) {
                                Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                                   int*, 0x54) = 0x2A606060;
                            }
                            if ((unsigned int)(Level37_7FC30Field(owner, unsigned char*, 0x49) -
                                               3) < 2U) {
                                Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                                   int*, 0x54) = 0x2A606060;
                                Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                                   signed char*, 0x45) = 0x20;
                            }
                        }
                    }
                }
                temporary2 = Level37_7FC30Field(privateState, short*, 4);
                Level37_7FC30Keep(temporary2);
                temporary2 *= 2;
                temporary3 =
                    Level37_7FC30Field((int)&Level37_7FC30_D_80065920 + temporary2, short*, 0);
                Level37_7FC30Keep(temporary3);
                temporary2 = Level37_7FC30Field(privateState, short*, 0);
                Level37_7FC30Multiply(temporary3, temporary2);
                Level37_7FC30Low(temporary8);
                temporary2 = temporary8 >> 12;
                locals.sp90 = temporary2;
                MATCHING_BARRIER_VOLATILE("memory");
                temporary2 = Level37_7FC30Field(privateState, short*, 4);
                Level37_7FC30Keep(temporary2);
                temporary2 *= 2;
                temporary3 =
                    Level37_7FC30Field((int)&Level37_7FC30_D_800658A0 + temporary2, short*, 0);
                Level37_7FC30Keep(temporary3);
                temporary2 = Level37_7FC30Field(privateState, short*, 0);
                Level37_7FC30Multiply(temporary3, temporary2);
                argument0 = (int)&locals.sp58;
                Level37_7FC30Keep(argument0);
                working17 = owner + 12;
                argument1 = working17;
                locals.sp98 = 0;
                Level37_7FC30Low(temporary8);
                temporary2 = temporary8 >> 12;
                locals.sp94 = temporary2;
                temporary2 = Level37_7FC30Field(privateState, short*, 2);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(temporary2, "$20");
                working20 = 300;
                Level37_7FC30Keep(working20);
                locals.sp98 = temporary2;
                Level37_7FC30CopyVector(argument0, argument1);
                argument0 = working17;
                argument1 = working17;
                working16 = (int)&locals.sp90;
                Level37_7FC30AddVector(argument0, argument1, working16);
                Level37_7FC30Field(privateState, short*, 2) =
                    (short)((unsigned short)Level37_7FC30Field(privateState, short*, 2) +
                            Level37_7FC30Field(privateState, unsigned short*, 6));
                temporary2 = Level37_7FC30MeasureVectorLength(working16, 1);
                temporary3 = temporary2 + 8;
                if (temporary3 > working20) {
                    working20 = temporary3;
                }
                Level37_7FC30RefreshMobySpatialGridAndBasis(owner, 2);
                if (Level37_7FC30_func_80019194(working17, working20) != 0) {
                    temp_a0_8 = Level37_7FC30Field(privateState, int*, 0xC);
                    if ((temp_a0_8 != 0) &&
                        (Level37_7FC30Field(temp_a0_8, short*, 0x36) == 0x1BF)) {
                        temporary2 = Level37_7FC30Field(temp_a0_8, unsigned char*, 72);
                        temporary2 = (unsigned int)temporary2 < 128U;
                        Level37_7FC30Keep(temporary2);
                        if (temporary2) {
                            working16 = Level37_7FC30Field(temp_a0_8, int**, 0);
                            Level37_7FC30_func_80037014(temp_a0_8);
                            temp_a0_9 = Level37_7FC30Field(privateState, int*, 0xC);
                            Level37_7FC30Field(temp_a0_9, int*, 0x1C) =
                                (int)(Level37_7FC30Field(temp_a0_9, int*, 0x1C) | 0x80000000);
                            Level37_7FC30CopyVector(
                                working16, Level37_7FC30Field(privateState, int*, 0xC) + 0xC);
                            Level37_7FC30RefreshMobySpatialGridAndBasis(
                                Level37_7FC30Field(privateState, int*, 0xC), 3);
                            Level37_7FC30Field(Level37_7FC30Field(privateState, int*, 0xC),
                                               unsigned char*, 0x48) = 0U;
                            Level37_7FC30Field(privateState, int*, 0xC) = 0;
                            goto block_160;
                        }
                        temporary2 = 3;
                        goto block_161;
                    }
                    working17 = (int)&Level37_7FC30_D_80071920;
                    working20 = working17 - 8;
                    Level37_7FC30Keep(working20);
                    argument0 = working20;
                    MATCHING_KEEP_VOLATILE_CLOBBER(argument0, "memory");
                    working16 = Level37_7FC30Field(working17, int*, 0);
                    if (working16 < 0) {
                        working16 = -working16;
                    }
                    temporary2 = Level37_7FC30MeasureVectorLength(argument0, 0);
                    working16 = working16 < temporary2;
                    Level37_7FC30Keep(working16);
                    if (working16) {
                        working16 = (int)&locals.spA0;
                        Level37_7FC30CopyVector(working16, working20);
                        if (Level37_7FC30_func_8004EF74(&locals.sp90, working16, &locals.sp90) !=
                            0) {
                            Level37_7FC30Field(privateState, short*, 2) =
                                ((int)(Level37_7FC30Field(privateState, short*, 2) * 3) >> 2);
                            temp_v0_14 = Level37_7FC30PlayMobySoundEvent(owner, 0, 0);
                            if (temp_v0_14 >= 0) {
                                temporary2 = Level37_7FC30Field(privateState, short*, 2);
                                if (temporary2 < 0) {
                                    temporary2 = -temporary2;
                                }
                                MATCHING_KEEP_VOLATILE(temporary2);
                                Level37_7FC30_func_8003C140(temp_v0_14, temporary2 * 0x28);
                            }
                        }
                    } else if (((({
                                     working16 = Level37_7FC30Field(working17, int*, 0);
                                     Level37_7FC30Keep(working16);
                                     working16;
                                 }) < 0) &&
                                (locals.sp98 > 0)) ||
                               ((working16 > 0) && (locals.sp98 < 0))) {
                        Level37_7FC30Field(privateState, short*, 0) = 0;
                        Level37_7FC30Field(privateState, short*, 2) =
                            (-Level37_7FC30Field(privateState, short*, 2) >> 1);
                        temp_v0_15 = Level37_7FC30PlayMobySoundEvent(owner, 0, 0);
                        if (temp_v0_15 >= 0) {
                            temporary2 = Level37_7FC30Field(privateState, short*, 2);
                            if (temporary2 < 0) {
                                temporary2 = -temporary2;
                            }
                            MATCHING_KEEP_VOLATILE(temporary2);
                            Level37_7FC30_func_8003C140(temp_v0_15, temporary2 * 0x28);
                        }
                        if (Level37_7FC30Field(privateState, short*, 2) < 0x28) {
                            Level37_7FC30Field(owner, int*, 0x14) =
                                (int)(Level37_7FC30ProbeGroundFromRaisedMoby(owner) + 0x12C);
                            Level37_7FC30Field(privateState, int*, 8) = 0;
                            Level37_7FC30Field(owner, unsigned char*, 0x48) = 0U;
                        }
                    }
                    goto block_117;
                }
            block_117:
                Level37_7FC30ProbeGroundFromRaisedMoby(owner);
                Level37_7FC30_func_8005629C(owner);
                goto block_125;
            case 3:
                Level37_7FC30_func_800391E8(0xA, 0x6B, owner, 0, 5, 0x6E, 0xC8);
                Level37_7FC30PlayMobySoundEvent(owner, 1, 0);
                if (Level37_7FC30Field(owner, unsigned char*, 0x49) == 2) {
                    Level37_7FC30Field(owner, unsigned char*, 0x48) = 4U;
                    temp_a0_10 = Level37_7FC30Field(privateState, int*, 0xC);
                    if (temp_a0_10 != 0) {
                        Level37_7FC30DeleteMoby(temp_a0_10);
                    }
                    Level37_7FC30Field(owner, signed char*, 0x41) = 0;
                    Level37_7FC30Field(owner, signed char*, 0x4C) = 0;
                    Level37_7FC30Field(owner, signed char*, 0x4D) = 0;
                    return;
                }
            case 1:
                temp_a0_11 = Level37_7FC30Field(privateState, int*, 0xC);
                if (temp_a0_11 != 0) {
                    Level37_7FC30DeleteMoby(temp_a0_11);
                }
            block_124:
                Level37_7FC30DeleteMoby(owner);
                return;
            block_125:
            case 0:
            default:
                if ((Level37_7FC30Field(owner, unsigned char*, 0x48) == 0) ||
                    (Level37_7FC30Field(owner, unsigned char*, 0x48) == 0x14)) {
                    temp_a0_3 = Level37_7FC30Field(privateState, int*, 0xC);
                    if (temp_a0_3 != 0) {
                        Level37_7FC30CopyVector(temp_a0_3 + 0xC, owner + 0xC);
                        temp_a0_4 = Level37_7FC30Field(privateState, int*, 0xC);
                        if (Level37_7FC30Field(temp_a0_4, short*, 0x36) == 0x1BF) {
                            Level37_7FC30Field(temp_a0_4, int*, 0x14) =
                                (int)(Level37_7FC30Field(temp_a0_4, int*, 0x14) - 0x12C);
                        } else {
                            Level37_7FC30Field(temp_a0_4, unsigned char*, 0x46) =
                                (unsigned char)(Level37_7FC30Field(temp_a0_4, unsigned char*,
                                                                   0x46) +
                                                7);
                        }
                    }
                    privateState = (int)&Level37_7FC30_D_8006E788;
                    working17 = 0;
                    Level37_7FC30ClearVector(&locals.spA0);
                    goto actor1252ReadNext;
                loop_142:
                    {
                        if ((working16 != owner) &&
                            (Level37_7FC30Field(working16, unsigned char*, 0x48) != 2) &&
                            (Level37_7FC30Field(working16, short*, 0x36) == 0x2C3) &&
                            (Level37_7FC30ApproximatePlanarDistance(working16 + 0xC, owner + 0xC) <
                             0x258)) {
                            temp_a0_5 = Level37_7FC30Field(working16, int*, 0x14);
                            temp_v1_5 = Level37_7FC30Field(owner, int*, 0x14) -
                                        Level37_7FC30Field(owner, short*, 0x38);
                            working20 = 600;
                            Level37_7FC30Keep(working20);
                            temp_v0_6 = temp_v1_5 - temp_a0_5;
                            if (temp_v0_6 >= 0) {
                                if (temp_v0_6 >= 0x1F4) {
                                } else {
                                    goto block_141;
                                }
                            } else if ((temp_a0_5 - temp_v1_5) < 0x1F4) {
                            block_141:
                                temp_v0_7 = Level37_7FC30PlanarHeadingLookup(
                                                Level37_7FC30Field(owner, int*, 0xC) -
                                                    Level37_7FC30Field(working16, int*, 0xC),
                                                Level37_7FC30Field(owner, int*, 0x10) -
                                                    Level37_7FC30Field(working16, int*, 0x10),
                                                0) *
                                            2;
                                temporary3 = Level37_7FC30Field(
                                    (int)&Level37_7FC30_D_80065920 + temp_v0_7, short*, 0);
                                Level37_7FC30Multiply(temporary3, working20);
                                temporary3 = locals.spA0;
                                Level37_7FC30Low(temporary8);
                                argument0 = temporary8 >> 12;
                                temporary3 += argument0;
                                locals.spA0 = temporary3;
                                temporary2 = Level37_7FC30Field(
                                    (int)&Level37_7FC30_D_800658A0 + temp_v0_7, short*, 0);
                                Level37_7FC30Multiply(temporary2, working20);
                                working17++;
                                temporary2 = locals.spA4;
                                Level37_7FC30Low(temporary8);
                                temporary3 = temporary8 >> 12;
                                temporary2 += temporary3;
                                locals.spA4 = temporary2;
                            }
                        }
                    }
                actor1252ReadNext:
                    working16 = Level37_7FC30Field(privateState, int*, 0);
                    privateState += 4;
                    if (working16)
                        goto loop_142;
                    working16 = (int)&locals.spA0;
                    if (working17 != 0) {
                        temp_lo = locals.spA0 / working17;
                        locals.spA0 = temp_lo;
                        locals.spA4 = locals.spA4 / working17;
                        locals.spA8 = locals.spA8 / working17;
                        Level37_7FC30ScaleVectorRatioQ15(
                            working16, Level37_7FC30MeasureVectorLength(working16, 1, temp_lo),
                            0x64);
                        Level37_7FC30AddVector(working16, owner + 0xC, working16);
                        Level37_7FC30_func_80038000(owner, working16, 0x12C, 0, 0x21);
                    }
                    argument0 = owner + 12;
                    Level37_7FC30Keep(argument0);
                    working16 = (int)&Level37_7FC30_D_80070328;
                    Level37_7FC30Keep(working16);
                    if (Level37_7FC30ApproximatePlanarDistance(argument0, working16) < 0x2BC) {
                        var_v0_5 = ((Level37_7FC30Field(owner, int*, 0x14) -
                                     Level37_7FC30Field(owner, short*, 0x38)) -
                                    Level37_7FC30Field((int)&Level37_7FC30_D_80070328, int*, 8)) +
                                   Level37_7FC30Field((int)&Level37_7FC30_D_80070328, int*, 0x44);
                        if (var_v0_5 < 0) {
                            var_v0_5 = -var_v0_5;
                        }
                        if (var_v0_5 < 0x1F4) {
                            temporary2 = 2;
                            Level37_7FC30Keep(temporary2);
                            temporary3 = Level37_7FC30Field(owner, unsigned char*, 73);
                            Level37_7FC30Keep(temporary3);
                            if (temporary3 == temporary2)
                                goto block_160;
                            temporary2 = (int)temporary3 < 3;
                            Level37_7FC30Keep(temporary2);
                            if (temporary2) {
                                temporary2 = 1;
                                Level37_7FC30Keep(temporary2);
                                argument0 = 4;
                                if (temporary3 == temporary2)
                                    goto actor1252StateOne;
                                temporary2 = 3;
                                goto block_161;
                            }
                            temporary2 = 3;
                            Level37_7FC30Keep(temporary2);
                            if (temporary3 == temporary2)
                                goto actor1252StateThree;
                            temporary2 = 4;
                            Level37_7FC30Keep(temporary2);
                            if (temporary3 == temporary2)
                                goto actor1252StateFour;
                            temporary3 = 1;
                            temporary2 = 3;
                            goto block_161;
                        actor1252StateOne:
                            temporary3 = 420;
                            callbackWord3 = Level37_7FC30_unk_ovlheader_800743B8;
                            callbackWord4 = Level37_7FC30_unk_ovlheader_800743C0;
                            __asm__(""
                                    : "=r"(working16)
                                    : "0"(working16), "r"(callbackWord3), "r"(callbackWord4)
                                    : "$2");
                            descriptorAddress = working16 + 460;
                            __asm__(""
                                    : "=&r"(descriptorAddress)
                                    : "0"(descriptorAddress), "r"(working16));
                            Level37_7FC30Field(working16, int*, 460) = temporary3;
                            Level37_7FC30_func_8002803C(argument0, 8, callbackWord3, callbackWord4,
                                                        Level37_7FC30_unk_ovlheader_800743BC,
                                                        descriptorAddress, temporary3);
                            Level37_7FC30Keep(working16);
                            temporary2 = 3;
                            goto block_161;
                        actor1252StateThree:
                            temporary2 = Level37_7FC30Player488;
                            temporary2 += 50;
                            Level37_7FC30Player488 = temporary2;
                            if (temporary2 < 201) {
                                temporary2 = 3;
                                goto block_161;
                            }
                            temporary2 = 200;
                            Level37_7FC30Player488 = temporary2;
                            temporary2 = 3;
                            goto block_161;
                        actor1252StateFour:
                            temporary3 = 1;
                            temporary2 = Level37_7FC30Field(savedPointer23, int*, 108);
                            Level37_7FC30Field(savedPointer23, unsigned char*, 112) = temporary3;
                            temporary2++;
                            Level37_7FC30Field(savedPointer23, int*, 108) = temporary2;
                        block_160:
                            temporary2 = 3;
                        block_161:
                            Level37_7FC30Field(owner, unsigned char*, 72) = temporary2;
                        }
                    }
                }
                break;
        }
    }
}
#undef Level37_7FC30Field
#undef Level37_7FC30Keep

extern Moby* D_8006C550;
void func_80055B18(Moby*);
void func_level_37_80080FC0(Moby* moby) {
    Moby* linked;

    linked = &D_8006C550[moby->linkedMoby];
    if (linked->animationState.nextId != 5) {
        func_80055B18(moby);
        return;
    }
    func_8004F178(&moby->position, &linked->position);
    moby->angle.roll = linked->angle.roll;
    moby->angle.pitch = linked->angle.pitch;
    moby->angle.yaw = linked->angle.yaw;
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
void func_level_37_80081064(Moby* arg0) {
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

extern unsigned char D_8006C7B4;
/* AI generated adaptation; not human reviewed. Original SCUS-94467 level37 800818EC. */
typedef struct {
    int unk0;
    PathTag* path;
    int timer;
} Vehicle864Tag;
extern Moby* Vehicle864Moby __asm__("D_8006C65C");
extern int D_8006C770;
void func_80034F80(Moby*, int);
void func_level_37_800818EC(Moby* arg0) {
    Vector3D sp10, sp20, sp30, sp40, sp50, sp60;
    int temp_v1_3;
    Vehicle864Tag* mobyTag;

    mobyTag = (Vehicle864Tag*)arg0->mobyTag;
    switch (arg0->state) {

        case 0:
            switch (arg0->substate) {
                case 0:
                    if (currentLevel != 30 && !progressFlags.lvl30_RocketUsable) {
                        func_80055B18(arg0);
                        return;
                    } else {
                        func_80034F80(arg0, 2);
                        arg0->position.z += 0x1000;
                        if (currentLevel == 37)
                            arg0->position.z += 0x800;
                        spyro.unk17a = 0x1001A000;
                        spyro.unk20[1] = 0;
                        func_8004F178(&spyro.unk19, &arg0->position);
                        spyro.unk19.z += spyro.unk4a + 0x604;
                        spyro.unk18.roll = arg0->angle.roll;
                        spyro.unk18.pitch = arg0->angle.pitch;
                        spyro.unk18.yaw = arg0->angle.yaw;
                        arg0->substate = 1;
                        func_8003B7B4(&arg0->substate, 1, &savedData);
                        func_8003B7B4(&arg0->substate, 1, &unsavedData);
                        arg0->state = 8;
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
            switch (arg0->substate) {
                case 0:
                    sp10.x = (D_80065920[arg0->angle.yaw] * 3) >> 3;
                    sp10.y = (D_800658A0[arg0->angle.yaw] * 3) >> 3;
                    sp10.z = 0;
                    func_8004F194(&sp10, &sp10, &arg0->position);
                    if (ovlHeader.unk2b(&sp10, arg0->angle.yaw + 0x80, 0) != 0) {
                        spyro.unk17c = 0;
                        func_8004F178(&sp10, &arg0->position);
                        sp10.z += 0x280;
                        ovlHeader.unk2c(&sp10);
                        arg0->substate = 1;
                    }
                    break;
                case 1:
                    func_8004F178(&sp10, &arg0->position);
                    sp10.z += 0x280;
                    ovlHeader.unk2c(&sp10);
                    break;
            }
            if (spyro.m_StoodOnMoby == arg0) {
                arg0->state = 2;
                case 2:
                    if (spyro.m_StoodOnMoby != arg0) {
                        camera.unk168 = 0;
                        arg0->state = 1;
                    } else {
                        if (ovlHeader.unk2b(&arg0->position, arg0->angle.yaw, 0) != 0) {
                            D_80070104.loadLevel = ((currentLevel / 10) + 1) * 10;
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
                if (Vehicle864Moby != 0) {
                    *((unsigned char*)Vehicle864Moby + 0x4C) = 0;
                    *((unsigned char*)Vehicle864Moby + 0x4D) = 0;
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
                    if (progressFlags.lvl68_TheEscape != 0) {
                        func_80054F94(D_80070104.loadLevel, arg0);
                    } else {
                        progressFlags.lvl68_TheEscape = 1;
                        func_800584BC(6, 0x44);
                    }
                }
            }
            func_80055D24(arg0, 2);
            break;

        case 6:
            sp20.x = D_80065920[arg0->angle.yaw];
            sp20.y = D_800658A0[arg0->angle.yaw];
            sp20.z = 0;
            func_8004F194(&sp20, &sp20, &arg0->position);
            if (ovlHeader.unk2c(&sp20) != 0) {
                spyro.unk17c = 0;
                ovlHeader.unk2b(&sp20, arg0->angle.yaw, 0);
                arg0->state = 7;
            }
            break;

        case 7:
            sp30.x = D_80065920[arg0->angle.yaw];
            sp30.y = D_800658A0[arg0->angle.yaw];
            sp30.z = 0;
            func_8004F194(&sp30, &sp30, &arg0->position);
            if (ovlHeader.unk2b(&sp30, arg0->angle.yaw, 0) != 0) {
                func_8004F178(&sp40, &spyro.position);
                sp40.z -= spyro.unk4a;
                func_8003B634(&savedData, &sp40, spyro.bodyRotation.yaw);
                mobyTag->timer = 120;
                arg0->substate = 0;
                func_80034F40(arg0, 1);
                arg0->state = 10;
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
            func_8004F178(&sp50, &arg0->position);
            arg0->position.z += 0x400;
            sp50.z += 0x200;
            sp50.z = func_8001A358(&sp50, 0x200);
            if (sp50.z != 0) {
                arg0->position.z = sp50.z;
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
                spyro.unk18.yaw = arg0->angle.yaw;
            }
            func_80013AE4((Vector3D*)mobyTag->path->nodes, &spyro.position);
            if (D_8006C770 != 0) {
                func_80034F80(arg0, 0);
                func_80013B7C(0);
                arg0->state = 6;
            }
            break;
        case 10:
            if (mobyTag->timer != 0) {
                arg0->position.z += 64;
                func_800359A4(&mobyTag->timer, 4);
                if (arg0->substate == 0) {
                    spyro.unk17a = 0x10000002;
                    if (spyro.movementState == 0)
                        arg0->substate = 1;
                }
            }
            if (D_8006C7B4 & 1) {
                func_80034F40(arg0, 3);
                arg0->state = 11;
            } else if (arg0->animationState.id == 1 && D_8006C770 != 0)
                func_80034F80(arg0, 2);
            break;
        case 11:
            if (arg0->animationState.id == 3 && D_8006C770 != 0)
                func_80034F80(arg0, 0);
            spyro.unk17a = 0x10000002;
            arg0->position.z -= 64;
            func_8004F178(&sp60, &arg0->position);
            arg0->position.z += 1024;
            sp60.z += 512;
            sp60.z = func_8001A358(&sp60, 512);
            if (sp60.z != 0) {
                arg0->position.z = sp60.z;
                if (arg0->animationState.id == 0) {
                    arg0->substate = 0;
                    arg0->state = 1;
                }
            } else {
            rollbackLanding:
                arg0->position.z -= 1024;
            }
        updateCollision2:
            func_80055D24(arg0, 2);
            break;
    }
    func_80055D24(arg0, 1);
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
void func_level_37_8008266C(Moby* moby) {
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
void func_level_37_80082E54(void* input) {
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

void func_level_37_80083FA8(Moby* moby) {
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
void func_level_37_80083FC8(Moby* argument) {
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
