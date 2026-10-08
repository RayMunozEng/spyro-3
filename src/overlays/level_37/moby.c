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
extern int (*DecodedButterflyPursuit)(Moby*, Vector3D*, int, int, int, int, int, int, int, int, int, int, int) __asm__("unk_ovlheader_80074314");
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
    __asm__("" : "=r"(moby) : "0"(moby));
    tag = moby->mobyTag;
    initialPlayer = (Vector3D*)DecodedButterflyPlayer;
    __asm__("" : "=r"(initialPlayer) : "0"(initialPlayer));
    distanceOrTurned = DecodedButterflyDistance(&moby->position, initialPlayer);
    if (moby->state == 2) {
        moby->angle.yaw += 2;
        return;
    }
    if (distanceOrTurned < 3000) {
        int height = moby->position.z - moby->distanceToGround;
        int playerHeight = *(int*)(DecodedButterflyPlayer + 8);
        /* Retail keeps two distinct signed height-admission paths. */
        if (height - playerHeight < 0) goto negativeHeight;
        if (height - playerHeight >= 2800) goto dispatch;
        __asm__ volatile("" : : : "memory");
        goto closeHeight;
negativeHeight:
        if (playerHeight - height >= 2800) goto dispatch;
closeHeight:
        {
            activeSparx = DecodedButterflySparx;
            __asm__("" : "=r"(activeSparx) : "0"(activeSparx));
            if (activeSparx == 0) {
                int* recovery = &DecodedButterflyRecovery;
                if (*recovery >= 0) {
                    DecodedButterflySparx = SpawnMoby(120, moby);
                    if (DecodedButterflySparx != 0) {
                        sparxTag = DecodedButterflySparx->mobyTag;
                        if (!DecodedButterflySoundActive(DecodedButterflySparx, sparxTag->sound))
                            sparxTag->sound = DecodedButterflySound(DecodedButterflySparx, 0, 0);
                        if (moby->mobyClass == 16) *recovery = 1;
                        else {
                            *recovery = 3;
                            DecodedButterflyLives++;
                            if (DecodedButterflyLives >= 100) DecodedButterflyLives = 99;
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
                    delta = DecodedButterflyAngle(moby->position.x - *(int*)DecodedButterflyPlayer,
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
        } else if (!moby->drawn) goto hidden;
        if (distanceOrTurned < 12289) {
            if (DecodedButterflyCountdown(&tag->turnTimer, 1)) {
                int heading;
                __asm__("" : : "r"(distanceOrTurned));
                heading = DecodedButterflyHeadingRandom(30, 90);
                if (rand() & 1) heading = -heading;
                tag->heading = DecodedButterflyAddAngle(tag->heading, heading);
                tag->turnTimer = DecodedButterflyRandom(60, 140);
            }
            distanceOrTurned = DecodedButterflyTurn(moby, tag->heading, 4, 10, 1, 0);
            speed = 30;
            if (DecodedButterflyTick == 3) speed = 45;
            else if (DecodedButterflyTick == 4) speed = 60;
            candidatePosition.x = (DecodedButterflyCos[moby->angle.yaw] * speed) >> 12;
            candidatePosition.y = (DecodedButterflySin[moby->angle.yaw] * speed) >> 12;
            candidatePosition.z = 0;
            position = &moby->position;
            __asm__("" : "=r"(position) : "0"(position));
            DecodedButterflyAdd(&candidatePosition, &candidatePosition, position);
            collision = DecodedButterflyCollision(&candidatePosition, 50);
            if (!collision) DecodedButterflyCopy(position, &candidatePosition);
            if (!(DecodedButterflyFlags & 4)) {
                DecodedButterflyGroundQuery(position, 2048);
                DecodedButterflyRefresh(moby);
            }
            if (distanceOrTurned && collision) {
                tag->heading = DecodedButterflyAddAngle(tag->heading, DecodedButterflyRandom(98, 158));
                tag->turnTimer = DecodedButterflyRandom(30, 80);
            }
            if (!(DecodedButterflyFlags & 3) && DecodedButterflyDistance(&moby->position, &tag->anchor) >= 2001) {
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
            delta = DecodedButterflyAngle(moby->position.x - player->x,
                moby->position.y - *(int*)(DecodedButterflyPlayer + 4), zeroArgument);
            delta = DecodedButterflyAddAngle(delta, tag->turnSign * 10);
            if (DecodedButterflyPursuit(moby, player, 800, delta, 8, 120, 14, 128, 255, 255, 0, 0, 0) < 0 && DecodedButterflySparx != 0)
                ((DecodedButterflySparxTag*)DecodedButterflySparx->mobyTag)->counter = 0;
        } else moby->state = 0;
        break;
    }
    if (!moby->drawn) {
hidden:
        if (moby->state != 1) goto effect;
    }
    {
        register Moby* refreshArgument __asm__("$4");
        int result = DecodedButterflyGround(moby);
        refreshArgument = moby;
        __asm__("" : : "r"(refreshArgument));
        groundHeight = result;
        DecodedButterflyRefresh(refreshArgument);
    }
    if (groundHeight != 0) {
        phase = tag->phase;
        targetZ = groundHeight + 640 + ((DecodedButterflySin[phase] * tag->amplitude) >> 12);
        /* The random result is truncated to the original amplitude byte. */
        if (phase == 0 || phase == 128) tag->amplitude = DecodedButterflyRandom(256, 512);
        tag->phase -= 4;
        groundHeight = targetZ - moby->position.z;
        if (groundHeight > 32) groundHeight = 32;
        if (groundHeight < -32) groundHeight = -32;
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
#define Controller75F38Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Controller75F38Helper19194(void*,int) __asm__("func_80019194");
void* Controller75F38Helper2EC50(int,int,int) __asm__("func_8002EC50");
int Controller75F38Helper34F40(void*,int) __asm__("func_80034F40");
int Controller75F38Helper35734(void*,int) __asm__("func_80035734");
int Controller75F38Helper3585C(void*,int,int,int,int,int) __asm__("func_8003585C");
int Controller75F38Helper359A4(void*,int) __asm__("func_800359A4");
int Controller75F38Helper36018(int,int,int) __asm__("func_80036018");
unsigned int Controller75F38Helper3636C(int,int) __asm__("func_8003636C");
int Controller75F38Helper3BABC(void*,int,int) __asm__("func_8003BABC");
int Controller75F38Helper3BFC0(void*,int) __asm__("func_8003BFC0");
int Controller75F38Helper4E880(int,int,int) __asm__("func_8004E880");
int Controller75F38Helper4EA74(int) __asm__("func_8004EA74");
int Controller75F38Helper4ECF4(void*,void*) __asm__("func_8004ECF4");
int Controller75F38Helper4ED6C(void*,void*,void*) __asm__("func_8004ED6C");
int Controller75F38Helper4EDE8(void*,int) __asm__("func_8004EDE8");
int Controller75F38Helper4EF04(void*,int) __asm__("func_8004EF04");
int Controller75F38Helper4F08C(void*,int,int) __asm__("func_8004F08C");
int Controller75F38Helper4F110(void*,int) __asm__("func_8004F110");
int Controller75F38Helper4F178(void*,void*) __asm__("func_8004F178");
int Controller75F38Helper4F194(void*,void*,void*) __asm__("func_8004F194");
int Controller75F38Helper4F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Controller75F38Helper4F2A4(int,int) __asm__("func_8004F2A4");
int Controller75F38Helper4F334(void*,void*) __asm__("func_8004F334");
int Controller75F38Helper4F504(void*,void*) __asm__("func_8004F504");
int Controller75F38Helper4F554(void*,void*) __asm__("func_8004F554");
int Controller75F38Helper55B18(void*) __asm__("func_80055B18");
int Controller75F38Helper55D24(void*,int) __asm__("func_80055D24");
int Controller75F38Helper55F14(void*,int,void*) __asm__("func_80055F14");
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
extern void* (*Controller75F38SpawnMoby)(int,void*) __asm__("SpawnMoby");
extern int (*Controller75F38SpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
extern int (*Controller75F38Callback)(void*,void*,int,int,int,int,int,int,int,int,int,int,int) __asm__("unk_ovlheader_80074314");
void func_level_37_8007541C(void *input) {
    register unsigned char *owner __asm__("$20")=input;
    struct {
        struct {int x,y,z;} first;int p44;
        struct {int x,y,z;} second;int p54;
        struct {int x,y,z;} third;int p64;
        struct {int x,y,z;} fourth;int p74;
        struct {int x,y,z;} fifth;int p84;
        int matrix[6];
        struct {int x,y,z;} sixth;int padAC[1];
    } frame;
    short temp_a0_2;
    short temp_a0_7;
    short temp_v0_12;
    register int temp_v1_10 __asm__("$3");
    register int var_v0_8 __asm__("$2");
    int var_v0_9;
    unsigned char *temp_a0_4;
    unsigned char *temp_a0_5;
    unsigned char *temp_a0_6;
    unsigned char *temp_a1;
    unsigned char *temp_a2;
    register unsigned char *temp_s0_2 __asm__("$16");
    register unsigned char *temp_s0_4 __asm__("$16");
    register unsigned char *temp_s0_5 __asm__("$16");
    register unsigned char *temp_s1 __asm__("$17");
    register unsigned char *ownerPosition __asm__("$22");
    unsigned char *temp_v0_11;
    register unsigned char * temp_v0_8 __asm__("$2");
    unsigned char *temp_v1_2;
    register unsigned char *var_a2_5 __asm__("$6");
    register void *matrixFirst __asm__("$4");
    register void *matrixSecond __asm__("$5");
    register void *commonOwner __asm__("$4");
    register void *movementPosition __asm__("$4");
    register int movementRadius __asm__("$5");
    register int temp_a1_4 __asm__("$5");
    register int temp_s0 __asm__("$16");
    register int magnitudeDelta __asm__("$16");
    register unsigned char *temp_s1_3 __asm__("$17");
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
    register unsigned char *candidateBase __asm__("$5");
    register unsigned char *candidateRecords __asm__("$18");
    register int var_v0_3 __asm__("$2");
    int var_v0_5;
    int var_v0_6;
    int var_v0_7;
    register int var_v1 __asm__("$3");
    register int var_v1_2 __asm__("$3");
    register unsigned int temp_s0_3 __asm__("$16");
    unsigned int temp_v0_13;
    register unsigned char *var_s0 __asm__("$16");
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
    register void * temp_a0 __asm__("$4");
    register void *tag __asm__("$19");
    register void * temp_v0 __asm__("$2");
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1_15;
    void *temp_v1_3;
    register void *var_s1 __asm__("$17");

    tag = Controller75F38Field(owner, void **, 0);
    originalAngle = Controller75F38Field(owner, unsigned char *, 0x46);
    if (((unsigned int) (Controller75F38Field(Controller75F38D_80070328, int *, 0x50) - 0xB) < 2U) && (Controller75F38Field(tag, unsigned char *, 0xA) == 0) && (Controller75F38Field(owner, unsigned char *, 0x4D) != 0)) {
        {register int one __asm__("$6");
         register int model __asm__("$5");
         register int value __asm__("$3");
        temp_v0 = Controller75F38SpawnMoby(0xAA, owner);
        temp_a0 = Controller75F38Field(temp_v0, void **, 0);
        __asm__("" : "=r"(temp_a0) : "0"(temp_a0) : "$6");
        one=1;
        __asm__("" : "=r"(temp_a0),"=r"(one) : "0"(temp_a0),"1"(one) : "$3","$5");
        Controller75F38Field(temp_a0,void**,4)=owner;
        Controller75F38Field(temp_a0,unsigned char*,0)=one;
        __asm__ volatile("" ::: "$3","memory");
        model=Controller75F38Field(owner,unsigned short*,0x36);
        __asm__("" : "=r"(model) : "0"(model) : "$3");
        value=28;
        __asm__("" : "=r"(value) : "0"(value));
        Controller75F38Field(temp_a0,short*,2)=value;
        value=127;
        __asm__("" : "=r"(value),"=r"(model) : "0"(value),"1"(model) : "memory");
        Controller75F38Field(temp_a0,unsigned char*,1)=model;
        Controller75F38Field(temp_v0,unsigned char*,0x4F)=value;
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Controller75F38Field(temp_v0,unsigned char*,0x47)=value;
        Controller75F38Field(tag,unsigned char*,0xA)=one;
        }
    }
    if ((Controller75F38Field(Controller75F38D_80070328, int *, 0x280) >= 2) && (Controller75F38Field(owner, unsigned char *, 0x4D) != 0)) {
        {register void *particleVector __asm__("$16")=&frame.second.x;
         register void *first __asm__("$4")=particleVector;
         register int angleIndex __asm__("$3")=Controller75F38Field(owner,unsigned char*,0x46);
         register void *second __asm__("$5");
         register int sample __asm__("$6");
         register int value __asm__("$2");
         register int otherSample __asm__("$3");
         register void *third __asm__("$6");
         __asm__("" : "=r"(first),"=r"(angleIndex) : "0"(first),"1"(angleIndex) : "$5");
         second=&frame.first.x;
         __asm__("" : "=r"(second) : "0"(second) : "$17");
         angleIndex=((angleIndex+64)&255)*2;
         sample=*(short*)(Controller75F38D_80065920+angleIndex);
         __asm__("" : "=r"(sample) : "0"(sample) : "$17");
         temp_s1=owner+12;
         value=(sample*25)>>10;frame.first.x=value;
         otherSample=*(short*)(Controller75F38D_800658A0+angleIndex);
         __asm__("" : "=r"(otherSample) : "0"(otherSample) : "$6");
         third=temp_s1;
         frame.first.z=0;
         __asm__ volatile("" ::: "$2","memory");
         value=(otherSample*25)>>10;frame.first.y=value;
         Controller75F38Helper4F194(first,second,third);
         Controller75F38SpawnParticle(2,0x42,particleVector,0);
         Controller75F38Helper4F1C8(particleVector,temp_s1,&frame.first.x);
         Controller75F38SpawnParticle(2,0x42,particleVector,0);
        }
    }
    if ((Controller75F38Field(Controller75F38D_80070328, int *, 0x280) >= 3) && (Controller75F38Field(owner, unsigned char *, 0x4C) != 0)) {
        if (Controller75F38Field(tag, void **, 0x10) == 0) {
            Controller75F38Field(tag, void **, 0x10) = Controller75F38Helper2EC50(1, 0x40, 0x489090);
        }
    } else {
        temp_v0_2 = Controller75F38Field(tag, void **, 0x10);
        if (temp_v0_2 != 0) {
            Controller75F38Field(temp_v0_2, signed char *, 0x10) = 0;
            Controller75F38Field(tag, void **, 0x10) = 0;
        }
    }
    temp_a1 = Controller75F38D_80070328 + 0x280;
    if (Controller75F38Field(Controller75F38D_80070328, int *, 0x280) <= 0) {
        temp_v1_2 = Controller75F38Field(tag, unsigned char **, 0x14);
        if ((temp_v1_2 != 0) && ((unsigned char) Controller75F38Field(temp_v1_2, unsigned char *, 0x48) < 0x80U) && ((temp_a0_2 = Controller75F38Field(temp_v1_2, short *, 0x36), (temp_a0_2 == 0x10)) || (temp_a0_2 == 0xD3))) {
            Controller75F38Field(temp_v1_2, unsigned char *, 0x48) = 0U;
        }
        temp_v0_3 = Controller75F38Field(tag, void **, 0x10);
        Controller75F38D_8006C65C = 0;
        if (temp_v0_3 != 0) {
            Controller75F38Field(temp_v0_3, signed char *, 0x10) = 0;
            Controller75F38Field(tag, void **, 0x10) = 0;
        }
        Controller75F38Helper55B18(owner);
        return;
    }
    if ((Controller75F38Field(tag, unsigned char **, 0x14) != 0) && (Controller75F38Helper4F334(owner + 0xC, temp_a1 - 0x280) >= 0xC01)) {
        Controller75F38Field(tag, short *, 0) = 0;
    }
    temp_v1_3 = Controller75F38Field(tag, void **, 0x10);
    if (temp_v1_3 != 0) {
        Controller75F38Field(temp_v1_3, signed char *, 0x13) = 4;
    }
    scanEnabled=Controller75F38D_80065820;
    __asm__("" : "=r"(scanEnabled) : "0"(scanEnabled) : "$5");
    candidateBase=Controller75F38D_80065830;
    __asm__("" : "=r"(scanEnabled),"=r"(candidateBase) : "0"(scanEnabled),"1"(candidateBase));
    Controller75F38Field(candidateBase, void **, 0) = 0;
    if ((scanEnabled != 0) && ((Controller75F38D_8006E538 & 0xE) == 0xE)) {
        var_s1 = Controller75F38D_8006C550;
        var_a0 = Controller75F38Field(var_s1, unsigned char *, 0x48);
        if ((var_a0 & 0xFF) != 0xFF) {
            candidateRecords=candidateBase;
            __asm__("" : "=r"(candidateRecords) : "0"(candidateRecords) : "$16");
            var_s0 = var_s1 + 0x48;
            do {
                if ((unsigned int)(var_a0&255)<128) {
                    if(Controller75F38Field(var_s0,short*,-0x12)==1) goto eligibleCandidate;
                    temp_v1_4=Controller75F38Field(var_s0,unsigned char*,8);
                    {register unsigned int index __asm__("$2")=temp_v1_4-1;
                     index=index<2;
                     __asm__("" : "=r"(index) : "0"(index) : "$4");
                     __asm__("" : "=r"(temp_v1_4) : "0"(temp_v1_4));
                     temp_v1_4&=255;
                     if(index) goto eligibleCandidate;
                     if(temp_v1_4==5) goto eligibleCandidate;
                     if(temp_v1_4==10) goto eligibleCandidate;
                     if(temp_v1_4!=25) goto nextCandidate;
                    }
eligibleCandidate:
                    __asm__ volatile("" ::: "$4");
                    Controller75F38Helper4F1C8(&frame.first.x, var_s1 + 0xC, Controller75F38D_80070328);
                    var_a0_2 = frame.first.x;
                    var_v1 = frame.first.y;
                    var_v0 = frame.first.z;
                    __asm__("" : "=r"(var_a0_2),"=r"(var_v1),"=r"(var_v0) : "0"(var_a0_2),"1"(var_v1),"2"(var_v0));
                    if (var_a0_2 < 0) {
                        var_a0_2 = -var_a0_2;
                    }
                    if (var_v1 < 0) {
                        var_v1 = -var_v1;
                    }
                    var_a0_2+=var_v1;
                    __asm__("" : "=r"(var_a0_2),"=r"(var_v0) : "0"(var_a0_2),"1"(var_v0));
                    if (var_v0 < 0) {
                        var_v0 = -var_v0;
                    }
                    var_a0_3 = var_a0_2 + var_v0;
                    if (var_a0_3 < 0x4000) {
                        var_a0_3 = Controller75F38Helper4EDE8(&frame.first.x, 1);
                    }
                    if ((Controller75F38Field(candidateRecords, void **, 0) == 0) || (var_a0_3 < Controller75F38Field(candidateRecords, int *, -8))) {
                        Controller75F38Field(candidateRecords, void **, 0) = var_s1;
                        Controller75F38Field(candidateRecords, int *, -8) = var_a0_3;
                    }
                }
nextCandidate:
                var_s0 += 0x58;
                var_a0 = *var_s0;
                var_s1 += 0x58;
            } while ((var_a0 & 0xFF) != 0xFF);
        }
    }
    if (Controller75F38Field(tag, unsigned char **, 0x14) != 0) {
        temp_v1_6 = Controller75F38Field(owner, unsigned char *, 0x49);
        switch (temp_v1_6) {                        /* switch 1 */
        case 0:                                     /* switch 1 */
            temp_s1_2 = Controller75F38Field(owner, unsigned char *, 0x3D);
            Controller75F38Helper4F178(&frame.third.x, Controller75F38Field(tag, unsigned char **, 0x14) + 0xC);
            if (temp_s1_2 == 0) {
                __asm__ volatile("" : "=r"(temp_s1_2) : "0"(temp_s1_2));
                frame.third.x -= (int) (*(unsigned short*)(Controller75F38D_80065920 + (Controller75F38Field(Controller75F38Field(tag, unsigned char **, 0x14), unsigned char *, 0x46) * 2)) << 0x10) >> 0x14;
                var_v0_2 = *(unsigned short*)(Controller75F38D_800658A0 + (Controller75F38Field(Controller75F38Field(tag, unsigned char **, 0x14), unsigned char *, 0x46) * 2));
                __asm__("" : "=r"(var_v0_2) : "0"(var_v0_2) : "$3");
                thirdY=frame.third.y;
                __asm__("" : "=r"(var_v0_2),"=r"(thirdY) : "0"(var_v0_2),"1"(thirdY));
                var_v0_2=(var_v0_2<<16)>>0x14;
            } else {
                frame.third.x -= (int) (*(unsigned short*)(Controller75F38D_80065920 + (Controller75F38Field(Controller75F38Field(tag, unsigned char **, 0x14), unsigned char *, 0x46) * 2)) << 0x10) >> 0x16;
                var_v0_2 = *(unsigned short*)(Controller75F38D_800658A0 + (Controller75F38Field(Controller75F38Field(tag, unsigned char **, 0x14), unsigned char *, 0x46) * 2));
                __asm__("" : "=r"(var_v0_2) : "0"(var_v0_2) : "$3");
                thirdY=frame.third.y;
                __asm__("" : "=r"(var_v0_2),"=r"(thirdY) : "0"(var_v0_2),"1"(thirdY));
                var_v0_2=(var_v0_2<<16)>>0x16;
            }
            thirdY-=var_v0_2;frame.third.y=thirdY;
            if (temp_s1_2 != 0) {
                if ((unsigned char) Controller75F38Field(owner, unsigned char *, 0x3F) >= 7U) {
                    Controller75F38Field(owner, unsigned char *, 0x49) = (unsigned char) (Controller75F38Field(owner, unsigned char *, 0x49) + 1);
                }
                temp_a0_3 = Controller75F38Field(owner, unsigned char *, 0x45);
                var_v1_2 = -(int) temp_a0_3;
                if ((unsigned int) ((temp_a0_3 - 3) & 0xFF) < 0xFBU) {
                    var_v0_3=var_v1_2<3;
                    if(var_v0_3) {
                        var_v0_3=var_v1_2<-2;
                    }else {
                        var_v1_2=2;
                        __asm__("" : "=r"(var_v1_2) : "0"(var_v1_2));
                        var_v0_3=var_v1_2<-2;
                    }
                    if(var_v0_3) {
                        var_v1_2=-2;
                        __asm__("" : "=r"(var_v1_2) : "0"(var_v1_2));
                        var_v0_3=temp_a0_3+var_v1_2;
                    }else var_v0_3=temp_a0_3+var_v1_2;
                    Controller75F38Field(owner,unsigned char*,0x45)=var_v0_3;
                }
            }
            temp_s0_2=(unsigned char*)&frame.third.x;
            __asm__("" : "=r"(temp_s0_2) : "0"(temp_s0_2));
            Controller75F38Helper4F1C8(temp_s0_2,temp_s0_2,owner+12);
            temp_s0 = Controller75F38Helper4EDE8(temp_s0_2,1);
            if ((temp_s1_2 == 0) && (Controller75F38Helper359A4(tag, 2) != 0)) {
                __asm__ volatile("" : "=r"(temp_s1_2) : "0"(temp_s1_2));
                if (Controller75F38Helper3BFC0(owner, Controller75F38Field(tag, unsigned char *, 2)) == 0) {
                    Controller75F38Field(tag, unsigned char *, 2) = Controller75F38Helper3BABC(owner, 0, 0);
                }
                if (Controller75F38Field(owner, unsigned char *, 0x3D) != 1) {
                    Controller75F38D_8006C770 = 0;
                    temp_v1_7 = Controller75F38Field(owner, unsigned char *, 0x3D);
                    temp_a1_2 = Controller75F38Field(owner, unsigned char *, 0x3F);
                    Controller75F38Field(owner, signed char *, 0x40) = 0x72;
                    Controller75F38Field(owner, unsigned char *, 0x3D) = 1U;
                    Controller75F38Field(owner, unsigned char *, 0x3F) = 0U;
                    Controller75F38Field(owner, unsigned char *, 0x3C) = temp_v1_7;
                    Controller75F38Field(owner, unsigned char *, 0x3E) = temp_a1_2;
                    Controller75F38Helper35734(owner, temp_a1_2);
                }
            }
            var_a2 = 0x82;
            if (temp_s1_2 != 0) {
                var_a2 = 0x96;
            }
            temp_v1_8 = var_a2 + 5;
            {register void *adjustedVector __asm__("$4");
             register int magnitude __asm__("$5");
             if(temp_v1_8<temp_s0) {
                adjustedVector=&frame.third.x;magnitude=temp_s0;
                __asm__("" : "=r"(adjustedVector),"=r"(magnitude) : "0"(adjustedVector),"1"(magnitude));
                var_a2_2=temp_v1_8;goto stateZeroAdjust;
             }
             adjustedVector=&frame.third.x;magnitude=temp_s0;
             __asm__("" : "=r"(adjustedVector),"=r"(magnitude) : "0"(adjustedVector),"1"(magnitude));
             var_a2_2=var_a2-5;
stateZeroAdjust:
             Controller75F38Helper4F08C(adjustedVector,magnitude,var_a2_2);
            }
            {register void *first __asm__("$4")=owner+12;
             register void *second __asm__("$5")=first;
             __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$16","$17");
             temp_s0_2=(unsigned char*)&frame.third.x;
             __asm__("" : "=r"(temp_s0_2) : "0"(temp_s0_2));
             Controller75F38Helper4F194(first,second,temp_s0_2);
            }
            Controller75F38Helper3585C(owner, Controller75F38Helper4E880(frame.third.x, frame.third.y, 0), 0xAU, 0, 0, 0);
            tailMagnitude = Controller75F38Helper4EDE8(temp_s0_2,0);
            __asm__ volatile("" : "=r"(tailMagnitude) : "0"(tailMagnitude) : "$6");
                var_a0_4=tailMagnitude;
            var_a1 = frame.third.z;
            goto block_97;
        case 1:                                     /* switch 1 */
            if (Controller75F38Field(Controller75F38Field(tag, unsigned char **, 0x14), short *, 0x36) == 0x10) {
                temp_v0_5 = Controller75F38Field(Controller75F38D_80070328, int *, 0x280) + 1;
                Controller75F38Field(Controller75F38D_80070328, int *, 0x280) = temp_v0_5;
                if (Controller75F38D_8006580C < temp_v0_5) {
                    Controller75F38Field(Controller75F38D_80070328, int *, 0x280) = (int) Controller75F38D_8006580C;
                }
            } else {
                temp_v0_6 = Controller75F38D_8006C784 + 1;
                Controller75F38D_8006C784 = temp_v0_6;
                Controller75F38Field(Controller75F38D_80070328, int *, 0x280) = (int) Controller75F38D_8006580C;
                if (temp_v0_6 >= 0x64) {
                    Controller75F38D_8006C784 = 0x63;
                }
            }
            Controller75F38Field(owner, unsigned char *, 0x49) = (unsigned char) (Controller75F38Field(owner, unsigned char *, 0x49) + 1);
            Controller75F38Helper55B18(Controller75F38Field(tag, unsigned char **, 0x14));
            break;
        case 2:                                     /* switch 1 */
            if (Controller75F38D_8006C770 != 0) {
                register void *callbackOwner __asm__("$4")=owner;
                if (Controller75F38Field(owner, unsigned char *, 0x3D) != 0) {
                    __asm__("" : "=r"(callbackOwner) : "0"(callbackOwner));
                    Controller75F38D_8006C770 = 0;
                    temp_v0_7 = Controller75F38Field(owner, unsigned char *, 0x3D);
                    temp_a1_3 = Controller75F38Field(owner, unsigned char *, 0x3F);
                    {register int value __asm__("$3");
                     __asm__("" : "=r"(temp_v0_7),"=r"(temp_a1_3) : "0"(temp_v0_7),"1"(temp_a1_3) : "$3");
                     value=114;
                     __asm__("" : "=r"(value) : "0"(value));
                     Controller75F38Field(owner,unsigned char*,0x40)=value;
                    Controller75F38Field(owner, unsigned char *, 0x3D) = 0U;
                    Controller75F38Field(owner, unsigned char *, 0x3F) = 0U;
                    Controller75F38Field(owner, unsigned char *, 0x3C) = temp_v0_7;
                    Controller75F38Field(owner, unsigned char *, 0x3E) = temp_a1_3;
                    Controller75F38Helper35734(callbackOwner, temp_a1_3);
                    }
                }
                Controller75F38Field(owner, unsigned char *, 0x49) = 0U;
                Controller75F38Field(tag, unsigned char **, 0x14) = 0;
            }
            break;
        case 4:                                     /* switch 1 */
            temp_v0_8 = Controller75F38Field(tag, unsigned char **, 0x14);
            temp_s1_3 = Controller75F38Field(temp_v0_8, void **, 0);
            temp_s0_4=(unsigned char*)&frame.fourth.x;
            __asm__("" : "=r"(temp_s0_4) : "0"(temp_s0_4));
            Controller75F38Helper4F1C8(temp_s0_4,temp_v0_8+12,owner+12);
            temp_v0_9=Controller75F38Helper4EDE8(temp_s0_4,1);
            if (temp_v0_9 < 0x200) {
                Controller75F38Helper55D24(Controller75F38Field(tag, unsigned char **, 0x14), 4);
                temp_a2 = Controller75F38Field(tag, unsigned char **, 0x14);
                Controller75F38SpawnParticle(4, 0xC, temp_a2, Controller75F38Field(temp_a2, unsigned char *, 0x49));
                Controller75F38Field(temp_s1_3, short *, 0xA) = 0;
                Controller75F38Field(temp_s1_3, signed char *, 0xE) = (signed char) (rand() & 0xE);
                Controller75F38Field(temp_s1_3, signed char *, 0xF) = (signed char) (rand() & 0xE);
                Controller75F38Field(temp_s1_3, signed char *, 0x10) = (signed char) (rand() & 0xE);
                Controller75F38Helper4F504(temp_s1_3 + 4, Controller75F38Field(tag, unsigned char **, 0x14) + 0xC);
                Controller75F38Field(Controller75F38Field(tag, unsigned char **, 0x14), unsigned char *, 0x48) = 3U;
                Controller75F38Helper3BABC(Controller75F38Field(tag, unsigned char **, 0x14), 1, 0);
                Controller75F38Field(tag, unsigned char **, 0x14) = 0;
            } else {
                {register int threshold __asm__("$2")=310;
                 register void *adjustedVector __asm__("$4");
                 __asm__("" : "=r"(threshold) : "0"(threshold));
                 if(threshold<temp_v0_9) {
                    var_a2_3=310;
                    adjustedVector=temp_s0_4;
                    goto stateFourAdjust;
                 }
                 adjustedVector=temp_s0_4;
                 __asm__("" : "=r"(adjustedVector) : "0"(adjustedVector));
                 var_a2_3=290;
stateFourAdjust:
                 Controller75F38Helper4F08C(adjustedVector,temp_v0_9,var_a2_3);
                }
                {register void *first __asm__("$4")=owner+12;
                 register void *second __asm__("$5")=first;
                 __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$16","$18");
                 temp_s0_4=(unsigned char*)&frame.fourth.x;
                 __asm__("" : "=r"(temp_s0_4) : "0"(temp_s0_4));
                 Controller75F38Helper4F194(first,second,temp_s0_4);
                }
                Controller75F38Helper3585C(owner, Controller75F38Helper4E880(frame.fourth.x, frame.fourth.y, 0), 0xAU, 0, 0, 0);
                tailMagnitude = Controller75F38Helper4EDE8(temp_s0_4,0);
                __asm__ volatile("" : "=r"(tailMagnitude) : "0"(tailMagnitude) : "$7");
                var_a0_4=tailMagnitude;
                var_a1 = frame.fourth.z;
                goto block_97;
            }
            break;
        case 5:
            {register int value __asm__("$2");
             register int offset __asm__("$3");
             register void *first __asm__("$4");
             register void *second __asm__("$5");
             register void *third __asm__("$6");
             temp_s0_5=(unsigned char*)&frame.fifth.x;
             __asm__("" : "=r"(temp_s0_5) : "0"(temp_s0_5));
             value=(int)Controller75F38Field(tag,void**,0x14);
             offset=Controller75F38Field(tag,short*,4);
             value=Controller75F38Field((void*)value,int*,12);
             __asm__("" : "=r"(value),"=r"(offset) : "0"(value),"1"(offset) : "$4");
             first=temp_s0_5;
             value+=offset;frame.fifth.x=value;
             value=(int)Controller75F38Field(tag,void**,0x14);
             offset=Controller75F38Field(tag,short*,6);
             value=Controller75F38Field((void*)value,int*,16);
             __asm__("" : "=r"(value),"=r"(offset) : "0"(value),"1"(offset) : "$5");
             second=temp_s0_5;
             value+=offset;frame.fifth.y=value;
             value=(int)Controller75F38Field(tag,void**,0x14);
             offset=Controller75F38Field(tag,short*,8);
             value=Controller75F38Field((void*)value,int*,20);
             __asm__("" : "=r"(value),"=r"(offset) : "0"(value),"1"(offset) : "$6");
             third=owner+12;
             value+=offset;frame.fifth.z=value;
             Controller75F38Helper4F1C8(first,second,third);
            }
            temp_v0_10 = Controller75F38Helper4EDE8(temp_s0_5,1);
            if (temp_v0_10 < 0x200) {
                temp_v0_11 = Controller75F38Field(tag, unsigned char **, 0x14);
                Controller75F38Field(temp_v0_11, int *, 0x18) = (int) (Controller75F38Field(temp_v0_11, int *, 0x18) | 0x10000000);
                Controller75F38Field(tag, unsigned char **, 0x14) = 0;
            } else {
                var_a2_4 = Controller75F38D_80065814 + 0xA;
                if (var_a2_4 >= temp_v0_10) {
                    var_a2_4 = Controller75F38D_80065814 - 0xA;
                }
                {register void *adjustedVector __asm__("$4")=temp_s0_5;
                 __asm__("" : "=r"(adjustedVector) : "0"(adjustedVector));
                 Controller75F38Helper4F08C(adjustedVector,temp_v0_10,var_a2_4);}
                __asm__ volatile("" : "=r"(owner) : "0"(owner));
                {register void *first __asm__("$4")=owner+12;
                 register void *second __asm__("$5")=first;
                 __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$16","$17","$18","$21","$22","memory");
                 {register unsigned char *stack __asm__("$29");
                  __asm__ volatile("" : "=r"(stack));
                  temp_s0_5=stack+0x78;}
                 __asm__("" : "=r"(temp_s0_5) : "0"(temp_s0_5));
                 Controller75F38Helper4F194(first,second,temp_s0_5);
                }
                Controller75F38Helper3585C(owner, Controller75F38Helper4E880(frame.fifth.x, frame.fifth.y, 0), 0xAU, 0, 0, 0);
                var_a0_4 = Controller75F38Helper4EDE8(temp_s0_5,0);
                var_a1 = frame.fifth.z;
                goto block_97;
            }
            break;
block_97:
            temp_v0_4 = Controller75F38Helper4E880(var_a0_4, var_a1, 0);
            Controller75F38Field(owner, unsigned char *, 0x45) = temp_v0_4;
            Controller75F38Field(owner, unsigned char *, 0x45) = Controller75F38Helper36018(temp_v0_4 & 0xFF, 0, 0x30);
            break;
        case 9:                                     /* switch 1 */
            Controller75F38Field(tag, short *, 8) = 0x180;
            Controller75F38Field(tag, short *, 4) = 0;
            Controller75F38Field(tag, short *, 6) = 0;
            Controller75F38Field(owner, unsigned char *, 0x49) = 5U;
            break;
        }
    } else if (Controller75F38Field(Controller75F38D_80065830, void **, 0) != 0) {
        Controller75F38Helper4F1C8(&frame.first.x, Controller75F38Field(Controller75F38D_80065830, void **, 0) + 0xC, Controller75F38D_80070328);
        if (Controller75F38D_80065828 >= 0x401) {
            if (Controller75F38D_80065828 >= 0x4001) {
                Controller75F38Helper4F110(&frame.first.x, Controller75F38Helper4EA74(Controller75F38D_80065828) - 0xE);
            }
            {register int sample __asm__("$2")=*(unsigned short*)(Controller75F38D_800658A0+((Controller75F38D_8006C644*16)&0x1F0));
             register void *vector __asm__("$4");
             __asm__("" : "=r"(sample) : "0"(sample) : "$4");
             vector=&frame.first.x;
             __asm__("" : "=r"(sample),"=r"(vector) : "0"(sample),"1"(vector));
             sample=(sample<<16)>>21;
             Controller75F38Helper4EF04(vector,sample+1024);}
        }
        if (frame.first.z < -0x100) {
            frame.first.z = -0x100;
        }
        Controller75F38Field(owner, signed char *, 0x44) = 0;
        Controller75F38Field(owner, unsigned char *, 0x45) = Controller75F38Helper4E880(Controller75F38Helper4EDE8(&frame.first.x, 0), frame.first.z, 0);
        Controller75F38Field(owner, unsigned char *, 0x46) = Controller75F38Helper4E880(Controller75F38Field(owner, int *, 0xC) - Controller75F38Field(Controller75F38D_80070328, int *, 0), Controller75F38Field(owner, int *, 0x10) - Controller75F38Field(Controller75F38D_80070328, int *, 4), 0);
        Controller75F38Helper4F194(&frame.first.x, &frame.first.x, Controller75F38D_80070328);
        {register void *first __asm__("$4")=&frame.first.x;
         register void *second __asm__("$5")=first;
         __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$16");
         temp_s0_2=owner+12;
         Controller75F38Helper4F1C8(first,second,temp_s0_2);}
        Controller75F38Helper4F110(&frame.first.x, 2);
        Controller75F38Helper4F194(temp_s0_2, temp_s0_2, &frame.first.x);
        if (Controller75F38Helper19194(temp_s0_2, 0x100) != 0) {
            Controller75F38Helper4F178(temp_s0_2, Controller75F38D_8007190C);
        }
    } else {
        var_a1_2 = 0;
        if ((Controller75F38Field(Controller75F38D_80070328, int *, 0x50) == 0) && (Controller75F38Field(Controller75F38D_80070328, int *, 0x240) == 0) && !(Controller75F38Field(Controller75F38D_80070328, int *, 0x20C) & 8)) {
            var_a1_2 = Controller75F38D_8006E534 != 0;
        }
        if (var_a1_2 != 0) {
            var_a1_2 = Controller75F38Helper359A4(tag + 0xD, 1);
        } else {
            Controller75F38Field(tag, signed char *, 0xD) = 0x78;
        }
        temp_v0_12 = Controller75F38Field(tag, short *, 0);
        if (temp_v0_12 <= 0) {
            temp_v1_9 = Controller75F38Field(tag, unsigned char *, 3);
            __asm__("" : "=r"(temp_v1_9) : "0"(temp_v1_9));
            switch(temp_v1_9) {
            case 0:case 1:case 3:case 6:
                __asm__ volatile("" : : "r"(temp_v1_9));
                if((var_a1_2!=0)&&(rand()<0x2AAA)) {
                    temp_v0_13=Controller75F38Helper3636C(0,9);
                    switch(temp_v0_13) {
                    case 0:case 1:case 2:case 3:
                        stateValue=16;Controller75F38Field(tag,unsigned char*,12)=stateValue;
                        stateValue=3;__asm__("" : "=r"(stateValue) : "0"(stateValue));
                        Controller75F38Field(tag,unsigned char*,3)=stateValue;goto reloadSelectedState;
                    case 4:case 5:case 6:
                        stateValue=12;Controller75F38Field(tag,unsigned char*,12)=stateValue;
                        stateValue=2;__asm__("" : "=r"(stateValue) : "0"(stateValue));
                        Controller75F38Field(tag,unsigned char*,3)=stateValue;goto reloadSelectedState;
                    case 7:case 8:
                        stateValue=20;Controller75F38Field(tag,unsigned char*,12)=stateValue;
                        stateValue=6;__asm__("" : "=r"(stateValue) : "0"(stateValue));
                        Controller75F38Field(tag,unsigned char*,3)=stateValue;goto reloadSelectedState;
                    case 9:
                        stateValue=16;Controller75F38Field(tag,unsigned char*,12)=stateValue;
                        goto selectFour;
                    }
                    goto reloadSelectedState;
                }
                temp_v1_9=Controller75F38Field(tag,unsigned char*,3);
                if(temp_v1_9==3) goto resetLarge;
                stateValue=4;Controller75F38Field(tag,unsigned char*,12)=stateValue;
                goto resetZero;
            case 2:
                stateValue=12;Controller75F38Field(tag,unsigned char*,12)=stateValue;
                if(var_a1_2==0) goto selectOneNoRandom;
                stateValue=rand()<0x3FFF;
                if(!stateValue) {stateValue=1;goto selectOne;}
selectFour:
                stateValue=4;__asm__("" : "=r"(stateValue) : "0"(stateValue));
                Controller75F38Field(tag,unsigned char*,3)=stateValue;goto reloadSelectedState;
selectOneNoRandom:
                stateValue=1;
selectOne:
                __asm__("" : "=r"(stateValue) : "0"(stateValue));
                Controller75F38Field(tag,unsigned char*,3)=stateValue;goto reloadSelectedState;
            case 4:
                stateValue=16;Controller75F38Field(tag,unsigned char*,12)=stateValue;
                stateValue=5;__asm__("" : "=r"(stateValue) : "0"(stateValue));
                Controller75F38Field(tag,unsigned char*,3)=stateValue;goto reloadSelectedState;
            case 5:
resetLarge:
                stateValue=16;Controller75F38Field(tag,unsigned char*,12)=stateValue;
resetZero:
                Controller75F38Field(tag,unsigned char*,3)=0;
                goto reloadSelectedState;
            default:goto dispatchSelectedState;
            }
reloadSelectedState:
            temp_v1_9=Controller75F38Field(tag,unsigned char*,3);
dispatchSelectedState:
            __asm__ volatile("" : "=r"(temp_v1_9) : "0"(temp_v1_9));
            switch(temp_v1_9) {  /* switch 4 */
            case 0:                                 /* switch 4 */
            case 1:                                 /* switch 4 */
                __asm__ volatile("" : : "r"(temp_v1_9));
                frame.first.x = -0x258;
                frame.first.y = (rand() & 0x310) - 0x188;
                if (Controller75F38D_8006E044 == 2) {
                    var_v0_5 = (rand() & 0x7F) + 0x64;
                } else {
                    var_v0_5 = (rand() & 0x1FF) - 0xC8;
                }
                frame.first.z = var_v0_5;
                if (Controller75F38Field(tag, unsigned char *, 0xA) != 0) {
                    frame.first.x = -0xC8;
                    frame.first.z = (rand() & 0x7F) - 0xFA;
                }
                Controller75F38Field(tag, short *, 4) = (short) frame.first.x;
                Controller75F38Field(tag, short *, 6) = (short) frame.first.y;
                Controller75F38Field(tag, short *, 8) = (short) frame.first.z;
                if (Controller75F38Field(tag, unsigned char *, 3) == 0) {
                    Controller75F38Field(tag, short *, 0) = (short) ((rand() & 0x3F) + 0x3C);
                    Controller75F38Field(tag, unsigned char *, 0xB) = 5U;
                } else goto resetTimer;
                break;
            case 2:                                 /* switch 4 */
                Controller75F38Field(tag, short *, 4) = 0x1F4;
                Controller75F38Field(tag, short *, 8) = 0x12C;
                Controller75F38Field(tag, short *, 6) = 0;
                Controller75F38Field(tag, short *, 0) = 0x78;
                break;
            case 3:                                 /* switch 4 */
                Controller75F38Field(tag, short *, 0) = (short) ((rand() & 0x1F) + 0x3C);
                break;
            case 4:                                 /* switch 4 */
            case 5:                                 /* switch 4 */
                {register int selected __asm__("$2")=Controller75F38Helper3636C(0,3);
                 register int value __asm__("$3")=700;
                 __asm__("" : "=r"(selected),"=r"(value) : "0"(selected),"1"(value) : "$16");
                 temp_s0_3=selected;
                 Controller75F38Field(tag,short*,4)=value;}
                if(Controller75F38Field(tag,unsigned char*,3)==4) {
                    var_v0_8=rand()<0x3FFF;
                    if(var_v0_8) {var_v0_8=temp_s0_3<<1;goto positiveOffset;}
                    var_v0_8=temp_s0_3<<1;var_v0_8+=temp_s0_3;
                    goto negativeCompute;
                }
                var_v0_8=Controller75F38Field(tag,short*,6);
                if(var_v0_8>=0) {var_v0_8=temp_s0_3<<1;goto negativeOffset;}
                var_v0_8=temp_s0_3<<1;
positiveOffset:
                var_v0_8+=temp_s0_3;
                __asm__("" : "=r"(var_v0_8) : "0"(var_v0_8) : "$7");
                var_v0_8=(var_v0_8<<3)+temp_s0_3;var_v0_8<<=1;
                var_v0_8+=100;goto storeOffset;
negativeOffset:
                __asm__ volatile("" : "=r"(temp_s0_3) : "0"(temp_s0_3));
                var_v0_8+=temp_s0_3;
negativeCompute:
                __asm__("" : "=r"(var_v0_8) : "0"(var_v0_8) : "$6");
                var_v0_8=(var_v0_8<<3)+temp_s0_3;var_v0_8<<=1;
                var_v0_8=-var_v0_8-100;
storeOffset:
                Controller75F38Field(tag, short *, 6) = var_v0_8;
                __asm__ volatile("" ::: "memory");
                {register int selected __asm__("$2")=Controller75F38Helper3636C(0,3);
                 temp_v1_10=selected*50;
                 __asm__("" : "=r"(temp_v1_10) : "0"(temp_v1_10) : "$2");
                 stateValue=60;Controller75F38Field(tag,short*,0)=stateValue;
                 stateValue=10;
                 __asm__("" : "=r"(stateValue) : "0"(stateValue));
                 Controller75F38Field(tag,short*,8)=temp_v1_10;
                 Controller75F38Field(tag,unsigned char*,11)=stateValue;}
                break;
            case 6:
resetTimer:
                Controller75F38Field(tag,short*,0)=120;
                break;
            }
        } else {
            Controller75F38Field(tag, short *, 0) = (short) (temp_v0_12 - Controller75F38D_8006C648);
            if ((Controller75F38Field(tag, unsigned char *, 3) != 0) && (var_a1_2 == 0)) {
                Controller75F38Field(tag, short *, 0) = 0;
            }
            temp_v1_11 = Controller75F38Field(tag, unsigned char *, 3);
            switch (temp_v1_11) {                   /* switch 5 */
            case 0:                                 /* switch 5 */
            case 4:                                 /* switch 5 */
            case 5:                                 /* switch 5 */
                temp_v1_12 = Controller75F38Field(tag, unsigned char *, 0xB);
                if (temp_v1_12 & 1) {
                    if ((Controller75F38D_8006E044 == 2) || (Controller75F38Field(Controller75F38D_80070328, int *, 0x50) == 0xC)) {
                        frame.first.x = Controller75F38Field(tag, short *, 4) + ((int) Controller75F38Field(Controller75F38D_80070328, int *, 0xB0) >> 2);
                        frame.first.y = (int) Controller75F38Field(tag, short *, 6);
                        temp_a0_7 = Controller75F38Field(tag, short *, 8);
                        frame.first.z = (int) temp_a0_7;
                        if ((Controller75F38Field(Controller75F38D_80070328, int *, 0x50) != 0xC) && (temp_a0_7 < 0x64)) {
                            frame.first.z = 0x64;
                        }
                    } else {
                        if (Controller75F38D_8006E044 == 7) {
                            var_v0_9 = Controller75F38Field(tag, short *, 4) - 0x200;
                        } else {
                            var_v0_9 = Controller75F38Field(tag, short *, 4);
                        }
                        frame.first.x = (int) var_v0_9;
                        frame.first.y = (int) Controller75F38Field(tag, short *, 6);
                        frame.first.z = (int) Controller75F38Field(tag, short *, 8);
                    }
                    temp_s0_4 = Controller75F38D_80070328 + 0x30;
                    Controller75F38Helper4ED6C(temp_s0_4, &frame.first.x, &frame.first.x);
                    matrixFirst=&frame.first.x;matrixSecond=matrixFirst;
                    __asm__("" : "=r"(matrixFirst),"=r"(matrixSecond) : "0"(matrixFirst),"1"(matrixSecond) : "$6");
                    var_a2_5 = temp_s0_4 - 0x30;
                    goto transformOffset;
                }
                if (temp_v1_12 & 2) {
                    Controller75F38Helper4ECF4(&frame.matrix[0], Controller75F38D_8006E00C);
                    Controller75F38Helper4F554(&frame.first.x, tag + 4);
                    Controller75F38Helper4ED6C(&frame.matrix[0], &frame.first.x, &frame.first.x);
                    matrixFirst=&frame.first.x;matrixSecond=matrixFirst;
                    __asm__("" : "=r"(matrixFirst),"=r"(matrixSecond) : "0"(matrixFirst),"1"(matrixSecond) : "$6");
                    var_a2_5 = Controller75F38D_8006E00C + 0x14;
transformOffset:
                    Controller75F38Helper4F194(matrixFirst,matrixSecond,var_a2_5);
                }
                {register void *first __asm__("$4")=&frame.first.x;
                 register void *second __asm__("$5")=first;
                 __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$16");
                 temp_s0_5=owner+12;
                 Controller75F38Helper4F1C8(first,second,temp_s0_5);}
                Controller75F38Helper4F110(&frame.first.x, 2);
                Controller75F38Helper4F194(temp_s0_5, temp_s0_5, &frame.first.x);
                if (Controller75F38Helper19194(temp_s0_5, 0x100) != 0) {
                    Controller75F38Helper4F178(temp_s0_5, Controller75F38D_8007190C);
                }
                if (frame.first.z >= 0x21) {
                    frame.first.z = 0x20;
                }
                if (frame.first.z < -0x20) {
                    frame.first.z = -0x20;
                }
                Controller75F38Field(owner, signed char *, 0x44) = 0;
                Controller75F38Field(owner, unsigned char *, 0x45) = (unsigned char) frame.first.z;
                temp_v1_13 = Controller75F38Field(tag, unsigned char *, 0xB);
                {register int flag __asm__("$2")=temp_v1_13&4;
                 __asm__("" : "=r"(flag) : "0"(flag) : "$4");
                 commonOwner=owner;
                if (flag) {
                    var_a1_3 = Controller75F38Field(Controller75F38D_80070328, unsigned char *, 0xE);
                    __asm__ volatile("" : "=r"(var_a1_3) : "0"(var_a1_3) : "$6");
                    goto applyOwnerAngle;
                } else {
                    __asm__ volatile("" : "=r"(temp_v1_13) : "0"(temp_v1_13));
                    {register int zero __asm__("$7");
                     flag=temp_v1_13&8;
                     __asm__("" : "=r"(flag) : "0"(flag) : "$7");
                     zero=0;
                    if (flag) {
                    __asm__("" : "=r"(zero) : "0"(zero));
                    Controller75F38Helper3585C(commonOwner, (((int) (Controller75F38D_8006E040 << 0x10) >> 0x14) + 0x80) & 0xFF, Controller75F38Field(tag, unsigned char *, 0xC), zero, 0, 0);
                    }
                    }
                }
                }
                break;
            case 1:                                 /* switch 5 */
            case 2:                                 /* switch 5 */
                temp_s0_5=&frame.sixth.x;
                {register void *vector __asm__("$4")=temp_s0_5;
                 __asm__("" : "=r"(vector) : "0"(vector) : "$22");
                 ownerPosition=owner+12;
                 Controller75F38Helper4F1C8(vector,ownerPosition,Controller75F38D_80070328);}
                initialMagnitude = Controller75F38Helper4EDE8(&frame.sixth.x, 0);
                initialAngle = Controller75F38Helper4E880(frame.sixth.x, frame.sixth.y, 0);
                Controller75F38Helper4F554(&frame.sixth.x, tag + 4);
                Controller75F38Helper4ED6C(Controller75F38D_80070328 + 0x30, &frame.sixth.x, &frame.sixth.x);
                {register int magnitude __asm__("$2")=Controller75F38Helper4EDE8(&frame.sixth.x,0);
                 register int zero __asm__("$6")=0;
                 register int x __asm__("$4"); register int y __asm__("$5");
                 __asm__ volatile("" : "=r"(magnitude) : "0"(magnitude));
                 __asm__("" : "=r"(zero) : "0"(zero) : "$4","$5");
                 x=frame.sixth.x;y=frame.sixth.y;
                 __asm__("" : "=r"(x),"=r"(y),"=r"(magnitude) : "0"(x),"1"(y),"2"(magnitude));
                 magnitudeDelta=magnitude;
                 magnitude=Controller75F38Helper4E880(x,y,zero);
                 x=magnitude;y=initialAngle;
                 __asm__("" : "=r"(x),"=r"(y),"=r"(magnitudeDelta) : "0"(x),"1"(y),"2"(magnitudeDelta));
                 magnitudeDelta=(magnitudeDelta-initialMagnitude)>>3;
                 magnitude=Controller75F38Helper4F2A4(x,y);
                 magnitude>>=3;magnitude=initialAngle+magnitude;
                 adjustedAngle=magnitude&255;}
                temp_a1_4 = adjustedAngle * 2;
                {register int sample __asm__("$2")=*(short*)(Controller75F38D_80065920+temp_a1_4);
                 register int vertical __asm__("$3");register int playerX __asm__("$4");register int playerZ __asm__("$6");
                 register int product __asm__("$8");
                 __asm__("" : "=r"(sample) : "0"(sample) : "$17");
                 adjustedMagnitude=initialMagnitude+magnitudeDelta;
                 product=sample*adjustedMagnitude;
                 vertical=frame.sixth.z;playerX=Controller75F38Field(Controller75F38D_80070328,int*,0);
                 playerZ=Controller75F38Field(Controller75F38D_80070328,int*,8);
                 __asm__("" : "=r"(vertical),"=r"(playerX),"=r"(playerZ),"=r"(product) : "0"(vertical),"1"(playerX),"2"(playerZ),"3"(product));
                 sample=(product>>12)+playerX;Controller75F38Field(owner,int*,12)=sample;
                 sample=*(short*)(Controller75F38D_800658A0+temp_a1_4);
                 product=sample*adjustedMagnitude;
                 __asm__("" : "=r"(sample),"=r"(vertical) : "0"(sample),"1"(vertical) : "$4","$5");
                 vertical+=playerZ;
                 movementPosition=ownerPosition;
                 __asm__("" : "=r"(movementPosition) : "0"(movementPosition) : "$2","$5");
                 sample=Controller75F38Field(owner,int*,20);
                 __asm__("" : "=r"(sample) : "0"(sample) : "$5");
                 movementRadius=256;
                 __asm__("" : "=r"(sample),"=r"(vertical),"=r"(movementRadius) : "0"(sample),"1"(vertical),"2"(movementRadius));
                 vertical-=sample;verticalStep=vertical>>3;
                 sample=Controller75F38Field(owner,int*,20);
                 vertical=Controller75F38Field(Controller75F38D_80070328,int*,4);
                 __asm__("" : "=r"(sample),"=r"(vertical) : "0"(sample),"1"(vertical));
                 sample+=verticalStep;Controller75F38Field(owner,int*,20)=sample;
                 __asm__ volatile("" ::: "memory");
                 sample=(product>>12)+vertical;Controller75F38Field(owner,int*,16)=sample;}
                if (Controller75F38Helper19194(movementPosition, movementRadius) != 0) {
                    Controller75F38Helper4F178(ownerPosition, Controller75F38D_8007190C);
                    __asm__ volatile("" : "=r"(verticalStep) : "0"(verticalStep));
                }
                var_v0_10 = verticalStep < 0x21;
                Controller75F38Field(owner, signed char *, 0x44) = 0;
                if (var_v0_10 == 0) {
                    verticalStep = 0x20;
                }
                if (verticalStep < -0x20) {
                    verticalStep = -0x20;
                }
                Controller75F38Field(owner, unsigned char *, 0x45) = (unsigned char) verticalStep;
                {register int state __asm__("$3")=Controller75F38Field(tag,unsigned char*,3);
                 register int one __asm__("$2");
                 __asm__("" : "=r"(state) : "0"(state) : "$2");
                 one=1;
                if (state == one) {
                    if (Controller75F38Field(tag, short *, 0) < 0x65) {
                        commonOwner=owner;
                        __asm__("" : "=r"(commonOwner) : "0"(commonOwner) : "$5");
                        var_a1_3 = Controller75F38Field(Controller75F38D_80070328, unsigned char *, 0xE);
                        __asm__ volatile("" : "=r"(var_a1_3) : "0"(var_a1_3) : "$7");
                        goto applyOwnerAngle;
                    }
                    var_v0_11 = adjustedAngle - 0x80;
                    goto storeOwnerAngle;
                } else {var_v0_11=adjustedAngle-128;}
                }
storeOwnerAngle:
                __asm__ volatile("" : : "r"(adjustedAngle));
                Controller75F38Field(owner, unsigned char *, 0x46) = var_v0_11;
                break;
            case 3:                                 /* switch 5 */
                {register int angle __asm__("$2")=Controller75F38Helper4E880(Controller75F38D_8006E020 - Controller75F38Field(owner, int *, 0xC), Controller75F38D_8006E024 - Controller75F38Field(owner, int *, 0x10), 0);
                 commonOwner=owner;
                 __asm__("" : "=r"(commonOwner) : "0"(commonOwner) : "$5");
                 var_a1_3=angle;}
applyOwnerAngle:
                Controller75F38Helper3585C(commonOwner,var_a1_3,Controller75F38Field(tag,unsigned char*,12),0,0,0);
                break;
            case 6:                                 /* switch 5 */
                if (Controller75F38Callback(owner, Controller75F38D_80070328, 0, Controller75F38Field(owner, unsigned char *, 0x46), 8, 0xA0, (int) Controller75F38Field(tag, unsigned char *, 0xC), 0x80, 0xFF, 0xFF, 0, 0, 0) < 0) {
                    Controller75F38Field(tag, short *, 0) = 0;
                }
                {register int ownerHeight __asm__("$2")=Controller75F38Field(owner,int*,20);
                 register int playerHeight __asm__("$3")=Controller75F38Field(Controller75F38D_80070328,int*,8);
                 __asm__("" : "=r"(ownerHeight),"=r"(playerHeight) : "0"(ownerHeight),"1"(playerHeight));
                 ownerHeight-=300;playerHeight-=ownerHeight;playerHeight>>=2;
                 frame.first.z=playerHeight;
                 ownerHeight=Controller75F38Field(owner,int*,20);
                 Controller75F38Field(owner,int*,20)=ownerHeight+playerHeight;}
                break;
            }
        }
    }
    if ((Controller75F38Field(tag, void **, 0x10) != 0) && (Controller75F38Field(owner, unsigned char *, 0x46) != originalAngle)) {
        Controller75F38Helper55D24(owner, 4);
    }
    {register int tableIndex __asm__("$2")=Controller75F38Field(Controller75F38TablePlayer,int*,0x280);
     __asm__("" : "=r"(tableIndex) : "0"(tableIndex));
     Controller75F38Field(owner,int*,0x54)=*(int*)(Controller75F38D_8006585C+(tableIndex<<2));}
    __asm__ volatile("" ::: "$4","$5","$6","$7","memory");
    temp_v1_15 = Controller75F38Field(tag, void **, 0x10);
    if (temp_v1_15 != 0) {
        if (Controller75F38Field(Controller75F38D_80070328, int *, 0x280) >= 4) {
            Controller75F38Field(temp_v1_15, signed char *, 0x10) = (signed char) Controller75F38Field(Controller75F38D_80070328, int *, 0x280);
        } else {
            Controller75F38Field(temp_v1_15, signed char *, 0x10) = 1;
        }
        Controller75F38Helper55F14(owner, 0, Controller75F38Field(tag, void **, 0x10));
    }
    if ((Controller75F38Field(owner, unsigned char *, 0x3D) == 1) && (Controller75F38D_8006C770 != 0)) {
        Controller75F38Helper34F40(owner, 0);
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
    if (func_800359A4(tag, 2)) func_80055B18(moby);
    if (tag->unk2 == 0) {
        short value = tag->counter;
        if (value < 8) {
            moby->colour.r = value << 4;
            moby->colour.g = 0;
        } else moby->colour.g = (value - 8) << 4;
    } else if (tag->unk2 == 1) {
        short value = tag->counter;
        if (value < 8) {
            moby->colour.g = value << 4;
            moby->colour.r = 0;
        } else moby->colour.r = (value - 8) << 4;
    } else if (tag->unk2 == 2) {
        moby->colour.r -= 8;
        moby->colour.g -= 8;
        moby->colour.b -= 8;
        moby->colour.a = (unsigned short)tag->counter;
    }
    if (tag->unk3 == 0) moby->size = *(unsigned char*)tag * 2 + 0x30;
    else moby->size = *(unsigned char*)tag * 4 + 0x34;
}

extern int deltaTime;
int func_800359A4(void*, int);
void func_80055B18(Moby*);
void func_level_37_80076AA8(Moby* moby) {
    int* tag = moby->mobyTag;
    if (func_800359A4(tag, 4)) func_80055B18(moby);
    {
        int value = 0x10 - tag[0];
        if (value < 0) value = 0;
        moby->colour.a = value + 0x30;
    }
    moby->size -= deltaTime * 6;
    if (moby->size >= 0x80) moby->size = 0;
    if (moby->size < 0x18) moby->size = 0x18;
}

extern int deltaTime;
int func_800359A4(void*, int);
void func_80055B18(Moby*);
void func_level_37_80076B64(Moby* moby) {
    int* tag = moby->mobyTag;
    if (func_800359A4(tag, 4)) func_80055B18(moby);
    moby->colour.r = tag[0] << 3;
    moby->colour.g = tag[0] << 2;
    moby->size -= deltaTime * 3;
    if (moby->size >= 0x80) moby->size = 0;
    if (moby->size < 0xE) moby->size = 0xE;
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
void func_level_37_80076C18(Moby *moby) {
    Vector3D offset;
    /* Retail reserves eight further stack bytes; their source purpose is unknown. */
    int reservedStack[2];
    Vector3D* collisionBase;
    Vector3D *tagVector;
    Vector3D *position;
    Vector3D *normal;
    int tagZ;
    int positionZ;
    int dotProduct;
    MobyTag_260 *tag;

    tag = moby->mobyTag;
    if (moby->substate == 0) {
        if (tag->unk4 > 0) {
            moby->angle.yaw += 1;
            tagZ = tag->unkC.z - 6;
            tag->unkC.z = tagZ;
            if (tagZ < -0x80) {
                tag->unkC.z = -0x80;
            }
            moby->position.x += tag->unkC.x;
            moby->position.y += tag->unkC.y;
            positionZ = moby->position.z + tag->unkC.z;
            moby->position.z = positionZ;
            position = &moby->position;
            if (positionZ >= 0x400) {
                func_8001A358(position, 0x2000);
                func_8005629C(moby);
                if (func_80019194(position, 0x100) != 0) {
                    collisionBase = &D_8007190C;
                    func_8004F178(position, collisionBase);
                    normal = collisionBase + 1;
                    func_8004EF04(normal, 0x1000);
                    dotProduct = (int) ((tag->unkC.x * ((Vector3D*)(collisionBase + 1))->x) + (tag->unkC.y * D_8007191C) + (tag->unkC.z * D_80071920)) >> 0xB;
                    if (dotProduct < 0) {
                        func_8004F08C(normal, 0x1000, -dotProduct);
                        tagVector = &tag->unkC;
                        func_8004F194(tagVector, tagVector, normal);
                    }
                }
                tag->unk4 = (int) (tag->unk4 - 1);
                return;
            }
            goto deleteActor;
        }
        SpawnParticle(0xA, 0x47, &moby->position, 0);
        goto deleteActor;
    }
    if (tag->unk0->state != 0) {
deleteActor:
        func_80055B18(moby);
        return;
    }
    {
        /* These empty constraints emit no instructions and retain retail scheduling. */
        register int retainedOppositeAngle __asm__("$5");
        int wave;
        register short* sineTable __asm__("$6");
        register int angleByteOffset __asm__("$4");
        register int angle __asm__("$2");
        register int oppositeAngle __asm__("$2");
        register int heading __asm__("$4");
        angle = func_8004E880(D_8006E020 - moby->position.x, D_8006E024 - moby->position.y, 0);
        heading = angle;
        oppositeAngle = angle + 0x80;
        __asm__("" : "=r"(oppositeAngle) : "0"(oppositeAngle));
        sineTable = D_800658A0;
        wave = (int)(*(unsigned short*)((char*)D_800658A0 + ((D_8006C644 * 8) & 0x1F8)) << 16) >> 23;
        retainedOppositeAngle = oppositeAngle;
        __asm__("" : "=r"(wave), "=r"(retainedOppositeAngle), "=r"(sineTable) : "0"(wave), "1"(retainedOppositeAngle), "2"(sineTable));
        wave += oppositeAngle;
        __asm__("" : "=r"(wave) : "0"(wave));
        moby->angle.yaw = wave;
        if (moby->substate == 2) {
            heading = retainedOppositeAngle;
        }
        offset.x = 0;
        offset.y = 0;
        angleByteOffset = heading & 0xFF;
        if (moby->substate != 3) {
            register short* divisionEntry __asm__("$2");
            /* High word of the compiler reciprocal for signed division by 28. */
            register unsigned int divisionMagicHigh __asm__("$5") = 0x92490000U;
            __asm__("" : "=r"(angleByteOffset) : "0"(angleByteOffset), "r"(divisionMagicHigh));
            angleByteOffset *= 2;
            divisionEntry = (short*)(angleByteOffset + (unsigned int)sineTable);
            __asm__("" : "=r"(divisionEntry) : "0"(divisionEntry));
            offset.x = (int)(short)(*divisionEntry / 28);
            offset.y = -*(short*)((char*)D_80065920 + angleByteOffset) / 28;
        }
        offset.z = 0x520;
    func_8004F194(&moby->position, &tag->unk0->position, &offset);
    }
}


#define Controller78288Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Controller78288Helper1A358(void*,int) __asm__("func_8001A358");
void* Controller78288Helper2EC50(int,int,int) __asm__("func_8002EC50");
void* Controller78288Helper2F540(int,int,int) __asm__("func_8002F540");
int Controller78288Helper34F40(void*,int) __asm__("func_80034F40");
int Controller78288Helper3573C(void*,int,int,int) __asm__("func_8003573C");
int Controller78288Helper3585C(void*,int,int,int,int,int) __asm__("func_8003585C");
int Controller78288Helper37BBC(void*,int) __asm__("func_80037BBC");
int Controller78288Helper3B634(void*,void*,int) __asm__("func_8003B634");
int Controller78288Helper3BABC(void*,int,int) __asm__("func_8003BABC");
int Controller78288Helper492DC(void*) __asm__("func_800492DC");
int Controller78288Helper4E880(int,int,int) __asm__("func_8004E880");
int Controller78288Helper4F0E8(void*,int) __asm__("func_8004F0E8");
int Controller78288Helper4F110(void*,int) __asm__("func_8004F110");
int Controller78288Helper4F178(void*,void*) __asm__("func_8004F178");
int Controller78288Helper4F194(void*,void*,void*) __asm__("func_8004F194");
int Controller78288Helper4F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Controller78288Helper4F228(void*,void*,int) __asm__("func_8004F228");
int Controller78288Helper4F334(void*,void*) __asm__("func_8004F334");
int Controller78288Helper512E4(void*,int,int) __asm__("func_800512E4");
int Controller78288Helper55B18(void*) __asm__("func_80055B18");
int Controller78288Helper55D24(void*,int) __asm__("func_80055D24");
int Controller78288Helper55E84(void*) __asm__("func_80055E84");
int Controller78288Helper55F14(void*,int,void*) __asm__("func_80055F14");
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
extern int (*Controller78288SpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
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
void func_level_37_80076F1C(void *input) {
    struct { struct {int x,y,z;} first; int p24; struct {int x,y,z;} second; int p34; struct {int x,y,z;} third; int p44; struct {int x,y,z;} fourth; int p54; } frame;
    register int kind __asm__("$3");
    register unsigned char *owner __asm__("$18")=input;
    register unsigned char *handleOwnerPosition __asm__("$16");
    register unsigned char *playerHeightAddress __asm__("$16");
    register unsigned char *savedOwnerPosition __asm__("$16");
    register unsigned char *particleOwnerPosition __asm__("$16");
    unsigned char *extraHandle;
    unsigned char *allocatedHandle;
    unsigned char *oldPrimaryHandle;
    register unsigned char *cleanupHandle __asm__("$2");
    register unsigned char *extraPosition __asm__("$4");
    register unsigned char *extraTarget __asm__("$5");
    register unsigned char *particleTarget __asm__("$5");
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
    void *indexedOwner;
    register unsigned char *prefixTag __asm__("$17");
    register unsigned char *tag __asm__("$19");

    if (owner >= (unsigned char*)Controller78288D_8006C704) {
        __asm__("" : "=r"(owner) : "0"(owner));
        tag = Controller78288Field(owner, void **, 0);
        prefixTag = 0;
    } else {
        __asm__("" : "=r"(owner) : "0"(owner));
        prefixTag = Controller78288Field(owner, void **, 0);
        tag = prefixTag + 0x2C;
    }
    ownerPositionWord = (int)(owner + 0xC);
    distanceResult = Controller78288Helper4F334((void*)ownerPositionWord, Controller78288D_80070328);
    state = Controller78288Field(owner, unsigned char *, 0x48);
    switch (state) {
    case 0:
        substate = Controller78288Field(owner, unsigned char *, 0x49);
        switch (substate) {
        case 0:
            kind=Controller78288Field(tag,unsigned char*,2);
            __asm__("" : "=r"(kind) : "0"(kind) : "$2");
            {register int two __asm__("$2")=2;__asm__("" : "=r"(two) : "0"(two));
            if (kind==two) goto caseZeroOne;}
            {
                {register int product __asm__("$3")= -(((int)owner - ({register int base __asm__("$4")=Controller78288D_8006C550;__asm__("" : "=r"(base) : "0"(base));base;}))*0x45D1745D); product>>=3; __asm__("" : "=r"(product) : "0"(product)); {register int base __asm__("$2")=Controller78288D_8006C79C;
 register int byte __asm__("$4");
 __asm__("" : "=r"(base) : "0"(base) : "$4");
 byte=Controller78288Field(tag,unsigned char*,4);
 __asm__("" : "=r"(byte) : "0"(byte));
 bitIndex=product+base;
 if(byte==0) Controller78288Field(tag,unsigned char*,4)=Controller78288Field(owner,unsigned char*,0x46);
 }}
                { register int bank __asm__("$3")=Controller78288D_8006C58C;
                  register int address __asm__("$2");
                  __asm__("" : "=r"(bank) : "0"(bank) : "$2");
                  address=(int)Controller78288D_80071AB0;
                  __asm__("" : "=r"(bank),"=r"(address) : "0"(bank),"1"(address));
                  bank<<=5; bank+=address;
                  __asm__("" : "=r"(bank) : "0"(bank));
                  address=(bitIndex>>5)*4;address+=bank;
                  address=*(int*)address;
                  __asm__ volatile("" : "=r"(address) : "0"(address) : "$3");
                  bank=bitIndex&31;
                  address=(address>>bank)&1;
                  if(address) {
                    Controller78288Field(tag, unsigned char *, 2) = 0U;
                }
                }
                if (Controller78288Field(tag, unsigned char *, 2) == 1) {
                    Controller78288Field(prefixTag, unsigned char *, 5) = 1U;
                    Controller78288Field(tag, short *, 6) = -0x280;
                    Controller78288Field(owner, int *, 0x14) = (int) (Controller78288Field(owner, int *, 0x14) - 0x280);
                } else {
                    Controller78288Field(prefixTag, unsigned char *, 5) = 0U;
                }
                {register int heading __asm__("$2")=Controller78288Field(owner,unsigned char*,0x46);
                 kind=Controller78288Field(tag,unsigned char*,2);
                 __asm__("" : "=r"(heading),"=r"(kind) : "0"(heading),"1"(kind));
                 Controller78288Field(tag,unsigned char*,3)=heading;}
                if(kind!=1) goto caseZeroCompare;
                stateValue=Controller78288Field(prefixTag,unsigned char*,5);
                if(stateValue!=0) goto caseZeroOne;
caseZeroCompare:
                stateValue=distanceResult<0x1000;
                if(stateValue) {stateValue=5;goto caseZeroStore;}
            }
caseZeroOne:
            stateValue=1;
caseZeroStore:
            Controller78288Field(owner, unsigned char *, 0x49) = stateValue;
            Controller78288Field(owner, signed char *, 0x41) = 0;
            Controller78288Field(owner, signed char *, 0x4C) = 0;
            Controller78288Field(owner, unsigned char *, 0x4D) = 0U;
            goto clearExtraHandle;
        case 1:
            if ((distanceResult < 0x2400) || (Controller78288Field(tag, unsigned char *, 2) == 2)) {
                {register int one __asm__("$3")=1;
                 __asm__("" : "=r"(one) : "0"(one));
                 Controller78288Field(owner,signed char*,0x4C)=24;
                 Controller78288Field(owner,signed char*,0x41)=one;
                 Controller78288Field(owner,unsigned char*,0x4D)=one;
                 Controller78288Field(owner,unsigned char*,0x4F)=127;}
                if (Controller78288Field(tag, unsigned char *, 2) == 1) {
                    Controller78288Field(owner, unsigned char *, 0x46) = (unsigned char) Controller78288Field(tag, unsigned char *, 3);
                } else {
                    Controller78288Field(owner, unsigned char *, 0x46) = Controller78288Helper4E880(Controller78288Field(Controller78288D_80070328, int *, 0) - Controller78288Field(owner, int *, 0xC), Controller78288Field(Controller78288D_80070328, int *, 4) - Controller78288Field(owner, int *, 0x10), 0);
                }
                Controller78288Field(owner, unsigned char *, 0x49) = 2U;
                Controller78288Field(owner, unsigned char *, 0x46) = (unsigned char) (Controller78288Field(owner, unsigned char *, 0x46) + 0x67);
            }
            goto clearExtraHandle;
        case 2:
            Controller78288Field(owner, unsigned char *, 0x46) = (unsigned char) (Controller78288Field(owner, unsigned char *, 0x46) + 8);
            Controller78288Field(owner, unsigned char *, 0x4F) = (unsigned char) (Controller78288Field(owner, unsigned char *, 0x4F) - 5);
            if ((Controller78288Field(Controller78288D_80070328, int *, 0xB4) >= 0x1400) || (Controller78288Field(tag, unsigned char *, 2) == 2)) {
                Controller78288Field(owner, unsigned char *, 0x46) = (unsigned char) (Controller78288Field(owner, unsigned char *, 0x46) + 8);
                Controller78288Field(owner, unsigned char *, 0x4F) = (unsigned char) (Controller78288Field(owner, unsigned char *, 0x4F) - 5);
            }
            Controller78288Helper55D24(owner, 4);
            Controller78288SpawnParticle(1, 0xC, owner, 5);
            if ((unsigned char) Controller78288Field(owner, unsigned char *, 0x4F) < 0x21U) {
                Controller78288Field(owner, unsigned char *, 0x4F) = 0x20U;
                goto setSubstateFour;
            }
            goto clearExtraHandle;
        case 3:
        case 5:
            if (Controller78288Field(owner, unsigned char *, 0x4F) == 0) {
                Controller78288Field(owner, unsigned char *, 0x4F) = 0x20U;
            }
            Controller78288Field(owner, unsigned char *, 0x46) = (unsigned char) (Controller78288Field(owner, unsigned char *, 0x46) - 8);
            Controller78288Field(owner, unsigned char *, 0x4F) = (unsigned char) (Controller78288Field(owner, unsigned char *, 0x4F) + 5);
            Controller78288Helper55D24(owner, 4);
            if ((unsigned char) Controller78288Field(owner, unsigned char *, 0x4F) >= 0x7FU) {
                Controller78288SpawnParticle(6, 0xC, owner, 5);
                if (Controller78288Field(tag, unsigned char *, 2) == 2) {
                    oldPrimaryHandle = Controller78288Field(tag, int **, 8);
                    if (oldPrimaryHandle != 0) {
                        Controller78288Field(oldPrimaryHandle, signed char *, 0x10) = 0;
                    }
                    Controller78288Helper55B18(owner);
                    return;
                }
                Controller78288Field(owner, signed char *, 0x41) = 0;
                Controller78288Field(owner, signed char *, 0x4C) = 0;
                Controller78288Field(owner, unsigned char *, 0x4D) = 0U;
                {register int state __asm__("$3")=Controller78288Field(owner,unsigned char*,0x49);
                 register int five __asm__("$2")=5;
                 __asm__("" : "=r"(state),"=r"(five) : "0"(state),"1"(five));
                 if(state!=five) goto caseThreeOne;}
                nextSubstate=6;goto storeSubstate;
caseThreeOne:
                nextSubstate=1;goto storeSubstate;
            }
            Controller78288SpawnParticle(1, 0xC, owner, 3);
            goto clearExtraHandle;
        case 4:
            tagKind = Controller78288Field(tag, unsigned char *, 2);
            if (tagKind != 2) {
                if (tagKind == 1) {
                    if (Controller78288Helper37BBC(owner, 0xC) != 0) {
                        Controller78288Helper512E4(owner, 0, 0);
                        {register int diff __asm__("$4")=Controller78288D_8006C550;
                         register int product __asm__("$3");
                         register int bank __asm__("$2");
                         __asm__("" : "=r"(diff) : "0"(diff));
                         diff=(int)owner-diff;product=-(diff*0x45D1745D);
                         __asm__("" : "=r"(product) : "0"(product) : "$2");
                         bank=Controller78288D_8006C79C;
                         product>>=3;product+=bank;
                         __asm__("" : "=r"(product) : "0"(product));
                         bank=Controller78288D_8006C58C;
                         __asm__("" : "=r"(bank) : "0"(bank) : "$4");
                         diff=(int)Controller78288D_80071AB0;
                         __asm__("" : "=r"(diff),"=r"(bank) : "0"(diff),"1"(bank));
                         bank<<=5;bank=bank+diff;
                         __asm__("" : "=r"(bank) : "0"(bank));
                         diff=product>>5;__asm__("" : "=r"(diff) : "0"(diff));diff*=4;diff+=bank;
                         __asm__("" : "=r"(diff) : "0"(diff) : "$3");
                         product&=31;bank=*(int*)diff;product=tagKind<<product;
                         bank|=product;*(int*)diff=bank; }
                        Controller78288Field(tag, unsigned char *, 2) = 0U;
                        Controller78288Field(owner, unsigned char *, 0x49) = 7U;
                    }
                } else {
                    Controller78288Helper3573C(owner, 4, 0, 0);
                    Controller78288Helper55D24(owner, 4);
                    if (distanceResult >= 0x2801) {
                        Controller78288Field(owner, unsigned char *, 0x49) = 3U;
                    } else if (distanceResult < 0x1000) {
                        ownerHeight = Controller78288Field(owner, int *, 0x14) - Controller78288Field(owner, short *, 0x38);
                        heightDelta = ownerHeight - Controller78288Field(Controller78288D_80070328, int *, 8);
                        if (heightDelta >= 0) {
                            if (heightDelta < 0x800) {
                                goto checkHeightAndPlayer;
                            }
                        } else if ((Controller78288Field(Controller78288D_80070328, int *, 8) - ownerHeight) < 0x800) {
checkHeightAndPlayer:
                            playerHeightAddress = Controller78288D_80070328 + 8;
                            if ((((Controller78288Field(owner, int *, 0x14) - Controller78288Field(owner, short *, 0x38)) - Controller78288Field(Controller78288D_80070328, int *, 8)) >= -0x1F3) && ((Controller78288Field(Controller78288D_80070328, int *, 0x50) < 5) || ((unsigned int) (Controller78288Field(Controller78288D_80070328, int *, 0x50) - 0xB) < 2U))) {
                                Controller78288Helper4F178(&frame.first.x, playerHeightAddress + 0x90);
                                { register void *vector __asm__("$4")=&frame.first.x;
                                  register int six __asm__("$5")=6;
                                  register int x __asm__("$2")=frame.first.x;
                                  register int z __asm__("$3")=frame.first.z;
                                  __asm__("" : "=r"(vector),"=r"(six),"=r"(x),"=r"(z) : "0"(vector),"1"(six),"2"(x),"3"(z));
                                  x<<=5;frame.first.x=x;
                                  x=frame.first.y;z<<=5;frame.first.z=z;
                                  __asm__ volatile("" : "=r"(x) : "0"(x) : "memory");
                                  x<<=5;frame.first.y=x;
                                  Controller78288Helper4F110(vector,six); }
                                Controller78288Helper4F194(&frame.first.x, &frame.first.x, playerHeightAddress - 8);
                                if (distanceResult >= 0x800) {
                                    if (Controller78288Helper4F334(owner + 0xC, &frame.first.x) < 0x800) {
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
                Controller78288Field(owner, unsigned char *, 0x48) = 1U;
                Controller78288Helper34F40(owner, 1);
            }
            if ((Controller78288D_8006C644 & 0xF) < 2) {
                {register void *vector __asm__("$17")=&frame.second.x;
                 register void *argument __asm__("$4")=vector;
                 __asm__("" : "=r"(argument) : "0"(argument) : "$16");
                 savedOwnerPosition = owner + 0xC;
                 Controller78288Helper4F178(argument, savedOwnerPosition);}
                Controller78288Helper55F14(owner, 0, savedOwnerPosition);
                Controller78288SpawnParticle(1, 0xC, owner, 3);
                Controller78288Helper4F178(savedOwnerPosition, &frame.second.x);
            }
            goto clearExtraHandle;
        case 6:
            if (distanceResult >= 0x2801) {
                Controller78288Field(owner, unsigned char *, 0x49) = 1U;
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
                Controller78288Field(owner, unsigned char *, 0x49) = nextSubstate;
clearExtraHandle:
            extraHandle = Controller78288Field(tag, int **, 0xC);
            if (extraHandle != 0) {
                Controller78288Field(extraHandle, signed char *, 0x1C) = 0;
                Controller78288Field(tag, int **, 0xC) = 0;
            }
        goto updatePrimaryHandle;
    case 1:
        if (Controller78288Field(tag, unsigned char *, 2) == state) {
            Controller78288Field(Controller78288D_80070328, int *, 0x20C) = 0x10000002;
            Controller78288Helper492DC(ownerPositionWord);
        }
        phaseResult = Controller78288Helper55E84(owner);
        ownerIndex = Controller78288Field(tag, int *, 0x10);
        if (ownerIndex >= 0) {
            indexedOwner = (ownerIndex * 0x58) + Controller78288D_8006C550;
            Controller78288Helper3585C(owner, Controller78288Helper4E880(Controller78288Field(indexedOwner, int *, 0xC) - Controller78288Field(owner, int *, 0xC), Controller78288Field(indexedOwner, int *, 0x10) - Controller78288Field(owner, int *, 0x10), 0), 6, 0, 0, 0);
        } else {
            Controller78288Helper3573C(owner, 6, 0, 0);
        }
        Controller78288Helper55D24(owner, 4);
        if (phaseResult < 0x14) {
            if ((Controller78288Field(tag, unsigned char *, 2) != 2) && (distanceResult >= 0x1001)) {
                Controller78288Field(owner, unsigned char *, 0x48) = 0U;
                Controller78288Helper34F40(owner, 0);
            }
        } else if (({register int within __asm__("$2")=phaseResult<0x1F; __asm__("" : "=r"(within) : "0"(within) : "$3"); within;})) {
            if (Controller78288Field(owner, unsigned char *, 0x49) != 5) {
                Controller78288Helper4F178(&frame.second.x, owner + 0xC);
                savedSelector = Controller78288Field(tag, unsigned char *, 4);
                heightResult = Controller78288Helper1A358(&frame.second.x, 0x800);
                frame.second.z = heightResult;
                if (heightResult == 0) {
                    frame.second.z = Controller78288Field(Controller78288D_80070328, int *, 8);
                }
                Controller78288Helper3B634(Controller78288D_8006D088, &frame.second.x, savedSelector);
                Controller78288Helper3BABC(owner, 0, 0x80);
                Controller78288Field(owner, unsigned char *, 0x49) = 5U;
            }
            {register void *handle __asm__("$2")=Controller78288Field(tag,void**,0xC);
             register void *prepared __asm__("$4")=owner;
             if(handle!=0) goto handleReady;
             {register int close __asm__("$2")=distanceResult<0x1000;
              __asm__("" : "=r"(close) : "0"(close) : "$4");
              prepared=(void*)4;
              if(close) {
                __asm__("" : "=r"(prepared) : "0"(prepared));
                Controller78288Field(tag,void**,0xC)=Controller78288Helper2F540((int)prepared,1,0x608080);
              }}
             handle=Controller78288Field(tag,void**,0xC);prepared=owner;
             if(handle==0) goto handleFinished;
handleReady:
             __asm__("" : "=r"(prepared) : "0"(prepared));
                Controller78288Helper55F14(prepared,0,&frame.third.x);
                Controller78288Helper4F178(Controller78288Field(tag, int **, 0xC), &frame.third.x);
                {register int index __asm__("$3")=Controller78288Field(tag,int*,0x10);
                 register int offset __asm__("$2");
                 if(index>=0) {
                   offset=index*0x58;__asm__("" : "=r"(offset) : "0"(offset) : "$4","$5");
                   extraPosition=Controller78288Field(tag,unsigned char**,0xC);
                   extraTarget=(unsigned char*)Controller78288D_8006C550;
                   __asm__("" : "=r"(extraPosition),"=r"(extraTarget) : "0"(extraPosition),"1"(extraTarget));
                   extraPosition+=12;extraTarget+=offset;extraTarget+=12;
                 }else {
                   extraPosition=Controller78288Field(tag,unsigned char**,0xC);
                   extraTarget=Controller78288D_80070328;
                   __asm__("" : "=r"(extraPosition),"=r"(extraTarget) : "0"(extraPosition),"1"(extraTarget));
                   extraPosition+=12;
                 }}
                Controller78288Helper4F178(extraPosition, extraTarget);
            }
handleFinished:
            {register void *argument __asm__("$4");
             argument=&frame.fourth.x;
             __asm__("" : "=r"(argument) : "0"(argument) : "$16");
             particleOwnerPosition = owner + 0xC;
             Controller78288Helper4F178(argument,particleOwnerPosition);}
            {register int index __asm__("$3")=Controller78288Field(tag,int*,0x10);
             register void *prepared __asm__("$4");
             __asm__("" : "=r"(index) : "0"(index) : "$4");
             prepared=particleOwnerPosition;
             if(index>=0) {
               register int offset __asm__("$2")=index*11;
               __asm__("" : "=r"(offset) : "0"(offset) : "$5");
               particleTarget=(unsigned char*)Controller78288D_8006C550;
               offset*=8;particleTarget+=offset;particleTarget+=12;
             }else particleTarget=Controller78288D_80070328;
             Controller78288Helper4F178(prepared,particleTarget);}
            Controller78288SpawnParticle(1, 0xC, owner, 3);
            Controller78288Helper4F178(owner + 0xC, &frame.fourth.x);
        } else {
            cleanupHandle = Controller78288Field(tag, int **, 0xC);
            if (cleanupHandle != 0) {
                Controller78288Field(cleanupHandle, signed char *, 0x1C) = 0;
                {register int minusOne __asm__("$2")=-1;
                 __asm__("" : "=r"(minusOne) : "0"(minusOne) : "memory");
                 Controller78288Field(tag,int**,0xC)=0;
                 Controller78288Field(tag,int*,0x10)=minusOne;}
            }
        }
        if ((Controller78288Field(tag, short *, 6) < 0) && (Controller78288Field(tag, unsigned char *, 2) != 1)) {
            Controller78288Field(owner, int *, 0x14) = (int) (Controller78288Field(owner, int *, 0x14) + 0x20);
            Controller78288Field(tag, short *, 6) = (short) ((unsigned short) Controller78288Field(tag, short *, 6) + 0x20);
        }
        if (Controller78288D_8006C770 != 0) {
            if (Controller78288Field(tag, unsigned char *, 2) == 1) {
                Controller78288Field(owner, unsigned char *, 0x49) = 4U;
                if ((Controller78288Field(tag, int *, 0x14) != 0) && (Controller78288D_8006E044 == 0x11)) {
                    Controller78288D_8006E160 = 0;
                    Controller78288Field(tag, int *, 0x14) = 0;
                }
            }
            Controller78288Field(owner, unsigned char *, 0x48) = 0U;
            Controller78288Helper34F40(owner, 0);
        }
        goto updatePrimaryHandle;
    }

updatePrimaryHandle:
            __asm__ volatile("" : "=r"(distanceResult) : "0"(distanceResult));
            { register void *handle __asm__("$2")=Controller78288Field(tag,void**,8);
              __asm__("" : "=r"(handle) : "0"(handle) : "$3");
              scaledDistance=distanceResult>>6;
            if (handle == 0) {
                allocatedHandle = Controller78288Helper2EC50(4,0x40,({register int zero __asm__("$6");__asm__ volatile("" : "=r"(handle) : "0"(handle) : "$6");zero=0;zero;}));
                Controller78288Field(tag, int **, 8) = allocatedHandle;
                if (allocatedHandle != 0) {
                    __asm__ volatile("" : "=r"(distanceResult) : "0"(distanceResult));
                    scaledDistance = distanceResult >> 6;
                    __asm__("" : "=r"(scaledDistance) : "0"(scaledDistance));
                    goto clampPrimaryHandle;
                }
            } else {
clampPrimaryHandle:
                clampTest=scaledDistance<0x50;
                if(clampTest) {
                    scaledDistance=0x50;
                    __asm__("" : "=r"(scaledDistance) : "0"(scaledDistance));
                }
                clampTest=scaledDistance<0xA1;
                if(!clampTest) scaledDistance=0xA0;
                Controller78288Field(Controller78288Field(tag, int **, 8), signed char *, 0x11) = (signed char) scaledDistance;
                colourChannel = ((int) (*(unsigned short*)(Controller78288D_80065920 + ((Controller78288D_8006C644 * 8) & 0x1F8)) << 0x10) >> 0x17) + 0x70;
                Controller78288Field(Controller78288Field(tag, int **, 8), int *, 0xC) = (int) (({register int colour __asm__("$3")=colourChannel<<8;__asm__("" : "=r"(colour) : "0"(colour));colour=colourChannel+colour;__asm__("" : "=r"(colour) : "0"(colour));colour;}) + ((colourChannel >> 1) << 0x10));
                if (Controller78288Field(owner, unsigned char *, 0x4D) != 0) {
                    Controller78288Helper55F14(owner, 0, &frame.first.x);
                    {register void *first __asm__("$4")=&frame.first.x;
                     register void *second __asm__("$5")=first;
                     __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second) : "$16");
                     handleOwnerPosition=owner+12;
                     Controller78288Helper4F1C8(first,second,handleOwnerPosition);}
                    Controller78288Helper4F0E8(&frame.first.x, 5);
                    Controller78288Helper4F228(&frame.first.x, &frame.first.x, Controller78288Field(owner, unsigned char *, 0x4F));
                    Controller78288Helper4F194(Controller78288Field(tag, int **, 8), handleOwnerPosition, &frame.first.x);
                    return;
                }
                Controller78288Helper4F178(Controller78288Field(tag, int **, 8), owner + 0xC);
                return;
            }
    }
}

#undef Controller78288Field


INCLUDE_ASM("asm/nonmatchings/overlays/level_37/moby", func_level_37_80077A90);

void func_level_37_8007889C(Moby* moby) {
    func_80039714(moby);
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_37/moby", func_level_37_800788BC);

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * 8007934C..80079664. Original widths and numeric routes are retained;
 * Rev1 raw193 is route context, not authority for pointer/helper semantics. */
extern unsigned char DecodedScorchPlayer[] __asm__("D_80070328");
extern unsigned char* DecodedScorchModels[] __asm__("D_8006EE2C");
void func_level_37_8007934C(Moby* argument) {
 register Moby* moby __asm__("$16")=argument;
 register unsigned char* tag __asm__("$17")=moby->mobyTag;
 register Moby* child __asm__("$18");
 register unsigned char* childTag __asm__("$19");
 if(moby->state!=1 && (func_800359A4(tag+22,1) || moby->damageFlags)) {
  child=SpawnMoby(334,moby);
  __asm__("" : "=r"(child):"0"(child));
  if(child) {
   int angle;
   childTag=child->mobyTag;
   if(moby->damageFlags&0x20000)child->state=1;
   else if(tag[22])child->state=10;
   else child->state=1;
   child->substate=8;*(short*)(childTag+4)=160;*(short*)(childTag+2)=350;
   angle=moby->unkb;
   if(!angle) angle=func_800360F8(func_8004E880(moby->position.x-*(int*)DecodedScorchPlayer,moby->position.y-*(int*)(DecodedScorchPlayer+4),0),DecodedScorchPlayer[14],32,0);
   childTag[1]=angle;*(int*)(childTag+16)=-1;child->position.z+=400;
  }
  func_80038BF8(moby,(EnemyTag*)tag,8,1);
  *(short*)(tag+12)=1;*(short*)(tag+8)=-1;tag[15]=16;tag[14]=5;
  *(short*)(tag+10)=0;*(short*)(tag+6)+=40;*(short*)(tag+4)+=50;
  if(!tag[22])*(short*)(tag+4)=0;
  tag[22]=70;moby->unknownCollision=0;moby->state=1;moby->position.z+=400;
  {
   register unsigned int count __asm__("$2")=**(unsigned char**)(DecodedScorchModels[moby->mobyClass]+0x40);
   register int multipleFrames __asm__("$2");
   moby->animationState.id=1;moby->animationState.nextId=1;
   moby->animationState.frame=0;moby->animationState.nextFrame=1;
   multipleFrames=count>=2;__asm__("" : "=r"(multipleFrames):"0"(multipleFrames));
   moby->animationProgress=-multipleFrames&48;
  }
 }
 switch(moby->state) {
 case 0:
  func_8003573C(moby,7,0,0);
  *(short*)(tag+4)+=20;
  if(*(short*)(tag+4)>=231)*(short*)(tag+4)=230;
  if(func_80035DDC(moby,*(short*)(tag+4),300,0,5)) {
   moby->damageFlags|=0x20000;moby->unkb=moby->angle.yaw+128;
  }
  if(func_8004F334(&moby->position,(Vector3D*)DecodedScorchPlayer)<800) {
   moby->damageFlags|=0x20000;moby->unkb=moby->angle.yaw+128;
  }
  break;
 case 1:
  *(short*)(tag+10)=0;
  if(func_80035194(moby,tag)==256) {
   func_80055D24(moby,4);func_800369B8(moby,32);func_80055B18(moby);return;
  }break;
 }
 func_80055D24(moby,4);
}

typedef struct { Vector3D velocity; int timer; } DecodedBoundedProjectileTag;
extern void (*DecodedBoundedProjectileBurst)(Vector3D*,int,int,int,int) __asm__("unk_ovlheader_80074410");
Moby* DecodedBoundedProjectileQuery(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int func_80018368(Vector3D*,Vector3D*);
void func_level_37_80079664(Moby* moby) {
    DecodedBoundedProjectileTag* tag = moby->mobyTag;
    Vector3D previous;
    Moby* target;
    switch (moby->state) {
    case 0:
        if (moby->position.x < 0x800 || moby->position.y < 0x800 || moby->position.z < 0x800) goto remove;
        if (func_800359A4(&tag->timer, 4)) goto remove;
        if (moby->position.x > 0x3D400 || moby->position.y > 0x3D400 || moby->position.z > 0x1E000) goto remove;
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
                if (!target->unkb) target->unkb = 1;
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

INCLUDE_ASM("asm/nonmatchings/overlays/level_37/moby", func_level_37_80079844);

typedef struct {
    short x,y,z;
    unsigned char roll,reserved07,pitch,reserved09,yaw,reserved0B;
    short timer,lifetime,reserved10,mode;
} DecodedFragmentUpdate;
extern int D_8006C648,D_8006C640;
extern Vector3D D_80071918;
int rand(void);
int func_80019194(Vector3D*,int);
int func_8004EF74(Vector3D*,Vector3D*,Vector3D*);
int func_8003636C(int,int);
void func_level_37_8007A980(Moby* moby) {
    DecodedFragmentUpdate* tag=moby->mobyTag;
    Vector3D vector;
    /* Retail reserves further frame storage; its source purpose is unknown. */
    int reservedStack;
    if(tag->lifetime==0)return;
    if(tag->lifetime>=2) {
        tag->lifetime-=D_8006C648;
        if(tag->lifetime<=0)tag->lifetime=1;
    }
    if(func_800359A4(&tag->timer,2) || (!moby->drawn && tag->lifetime==1)) {
        SpawnParticle(8,0x46,&moby->position,(Vector3D*)0x10);
        func_80055B18(moby);return;
    }
    if(func_80019194(&moby->position,0x12C)) {
        vector.x=tag->x;vector.y=tag->y;vector.z=tag->z;
        if(func_8004EF74(&vector,&D_80071918,&vector)) {
            tag->x=vector.x;tag->y=vector.y;tag->z=vector.z;
        }
    }
    moby->position.x+=tag->x;moby->position.y+=tag->y;
    if(tag->mode==3)tag->z-=5;else tag->z-=10;
    if(tag->z< -0xC8)tag->z= -0xC8;
    moby->position.z+=tag->z;
    moby->angle.roll+=tag->roll;moby->angle.pitch+=tag->pitch;moby->angle.yaw+=tag->yaw;
    if(tag->mode!=2 && D_8006C640%5==0) {
        vector.x=rand()&3;vector.y=rand()&3;vector.z=0x14;
        if(tag->mode==1)SpawnParticle(1,0,&moby->position,&vector);
        else if(tag->mode==0)SpawnParticle(1,1,&moby->position,&vector);
        else if(tag->mode==3) {
            vector.x=tag->x>>2;vector.y=tag->x>>2;vector.z=tag->z>>2;
            vector.z+=func_8003636C(0xA,0x14);
            SpawnParticle(1,0x27,&moby->position,&vector);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_37/moby", func_level_37_8007AC9C);

#define Controller810A0Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern unsigned char Controller810A0Sin[] __asm__("D_800658A0");
extern unsigned char Controller810A0Cos[] __asm__("D_80065920");
extern unsigned short Controller810A0Angle0 __asm__("D_8006E03E"), Controller810A0Angle1 __asm__("D_8006E040");
extern unsigned char Controller810A0Player[] __asm__("D_80070328");
extern void* Controller810A0Models[] __asm__("D_8006EE2C");
extern int D_8006C770;
extern void* (*Controller810A0Spawn)(int,void*) __asm__("SpawnMoby");
int Controller810A0Helper18368(void*,void*) __asm__("func_80018368");
void* Controller810A0Helper1BA30(void*,int,int,int,int,int) __asm__("func_8001BA30");
int Controller810A0Helper1C288(void*,int,int) __asm__("func_8001C288");
int Controller810A0Helper359A4(void*,int) __asm__("func_800359A4");
int Controller810A0Helper3BABC(void*,int,int) __asm__("func_8003BABC");
int Controller810A0Helper4E880(int,int,int) __asm__("func_8004E880");
int Controller810A0Helper4F178(void*,void*) __asm__("func_8004F178");
int Controller810A0Helper4F264(int,int) __asm__("func_8004F264");
int Controller810A0Helper50844(void*,int,int,int) __asm__("func_80050844");
int Controller810A0Helper509E8(int) __asm__("func_800509E8");
int Controller810A0Helper55B18(void*) __asm__("func_80055B18");
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
    register unsigned char* owner __asm__("$19")=input;
    struct { Vector3D previous; int unused[1]; } frame;
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

    { register int stateTwo __asm__("$2");
    __asm__("" : "=r"(owner) : "0"(owner) : "$2");
    stateTwo=2;
    __asm__("" : "=r"(stateTwo) : "0"(stateTwo) : "$3");
    state = Controller810A0Field(owner, unsigned char *, 0x48);
    tag = Controller810A0Field(owner, void **, 0);
    __asm__("" : "=r"(state),"=r"(tag) : "0"(state),"1"(tag));
    if(state==stateTwo) goto moving; }
    if(state<3) {
        entryIndex=0;
        if(state==0) goto initialize;
        goto finished;
    }
    idlePosition=owner+0xC;
    if(state==10) goto idle;
    goto finished;
initialize:
    { register int two __asm__("$22")=2;
      __asm__("" : "=r"(two) : "0"(two));
            do {
                entryOffset = entryIndex * 2;
                if (Controller810A0Helper4F264(Controller810A0Field((entryOffset + Controller810A0Field(tag, int *, 0xC)), unsigned char *, 1), 0x40) < 0x3C) {
                    spawned = Controller810A0Spawn(Controller810A0Field(owner, short *, 0x36), owner);
                    __asm__("" : "=r"(spawned) : "0"(spawned));
                    if (spawned != 0) {
                        spawnTag = Controller810A0Field(spawned, void **, 0);
                        if(Controller810A0Field(spawned,unsigned char*,0x3C)!=two) {
                            register int one __asm__("$3")=1;
                            register int classIndex __asm__("$2")=Controller810A0Field(spawned,short*,0x36);
                            register void* model __asm__("$2");
                            register int selector __asm__("$2");
                            Controller810A0Field(spawned,unsigned char*,0x42)=0;
                            __asm__ volatile("" : "=r"(one),"=r"(classIndex) : "0"(one),"1"(classIndex) : "memory");
                            model=Controller810A0Models[classIndex];
                            model=Controller810A0Field(model,void**,0x44);
                            selector=Controller810A0Field(model,unsigned char*,0);
                            Controller810A0Field(spawned,unsigned char*,0x3C)=two;
                            Controller810A0Field(spawned,unsigned char*,0x3D)=two;
                            Controller810A0Field(spawned,unsigned char*,0x3E)=0;
                            Controller810A0Field(spawned,unsigned char*,0x3F)=one;
                            selector=selector<2U;
                            __asm__("" : "=r"(selector) : "0"(selector));
                            selector^=1;
                            selector=-selector;
                            Controller810A0Field(spawned,unsigned char*,0x40)=selector&0x30;
                        }
                        Controller810A0Field(spawnTag, int *, 8) = Controller810A0Helper50844(spawned + 0xC, 7, 0xA, 0x4080E0);
                        { register int address __asm__("$2")=Controller810A0Field(tag,int*,0xC);
                          register int angle __asm__("$3")=Controller810A0Angle1;
                          register int firstByte __asm__("$2");
                          register int secondByte __asm__("$3");
                          register int word __asm__("$2");
                          address=entryOffset+address;
                          __asm__("" : "=r"(address),"=r"(angle) : "0"(address),"1"(angle));
                          angle<<=16;
                          firstByte=Controller810A0Field(address,unsigned char*,0);
                          angle>>=20;
                          firstByte+=angle;
                          firstByte+=64;
                          __asm__("" : "=r"(firstByte) : "0"(firstByte));
                          Controller810A0Field(spawnTag,unsigned char*,1)=firstByte;
                          address=Controller810A0Field(tag,int*,0xC);
                          __asm__("" : "=r"(address) : "0"(address));
                          address=entryOffset+address;
                          secondByte=Controller810A0Field(address,unsigned char*,1);
                          __asm__("" : "=r"(secondByte) : "0"(secondByte) : "$2");
                          word=50;Controller810A0Field(spawnTag,int*,4)=word;
                          word=450;Controller810A0Field(spawnTag,short*,2)=word;
                          Controller810A0Field(spawnTag,unsigned char*,0)=secondByte;
                        }
                        Controller810A0Field(spawned,unsigned char*,0x44)=Controller810A0Random();
                        Controller810A0Field(spawned, signed char *, 0x48) = two;
                    }
                }
                entryIndex += 1;
            } while (entryIndex < 0x20); }
            Controller810A0Helper3BABC(owner, 0, 0);
            Controller810A0Field(owner, unsigned char *, 0x48) = 0xAU;
            idlePosition = owner + 0xC;
idle:
        nearby = Controller810A0Helper1BA30(idlePosition, 0x7D0, 0, 0, 0x30000, 0);
        if (nearby != 0) {
            Controller810A0Field(nearby, signed char *, 0x51) = Controller810A0Helper4E880(Controller810A0Field(nearby, int *, 0xC) - Controller810A0Field(owner, int *, 0xC), Controller810A0Field(nearby, int *, 0x10) - Controller810A0Field(owner, int *, 0x10), 0);
        }
        if (Controller810A0Helper1C288(idlePosition, 0x4B0, 7) != 0) {
            playerAngle = Controller810A0Helper4E880(Controller810A0Field(&Controller810A0Player, int *, 0) - Controller810A0Field(owner, int *, 0xC), Controller810A0Field(&Controller810A0Player, int *, 4) - Controller810A0Field(owner, int *, 0x10), 0) & 0xFF;
            Controller810A0Field(&Controller810A0Player, int *, 0x298) = playerAngle;
            tableOffset = playerAngle * 2;
            Controller810A0Field(&Controller810A0Player, int *, 0x20C) = 0x10000400;
            Controller810A0Field(&Controller810A0Player, int *, 0x21C) = (int) ((int) (*(short*)(Controller810A0Cos + tableOffset) * 0x23) >> 0xA);
            { register int sample __asm__("$3")=*(short*)(Controller810A0Sin+tableOffset);
              __asm__("" : "=r"(sample) : "0"(sample) : "$2");
              Controller810A0Field(Controller810A0Player,int*,0x224)=40;
              Controller810A0Field(Controller810A0Player,int*,0x220)=(sample*35)>>10; }
        }
        if (D_8006C770 != 0) {
            goto removeOwner;
        }
        goto finished;
moving:
        { register void* preparedVector __asm__("$4")=&frame.previous;
          register int angle __asm__("$2");
          __asm__("" : "=r"(preparedVector) : "0"(preparedVector) : "$2", "$16");
          angle=Controller810A0Angle1;
          __asm__("" : "=r"(angle) : "0"(angle) : "$16");
          position=owner+0xC;
          __asm__("" : "=r"(angle),"=r"(position) : "0"(angle),"1"(position));
          Controller810A0Field(owner,signed char*,0x46)=((angle<<16)>>20)-128;
        Controller810A0Field(owner, signed char *, 0x45) = (signed char) ((unsigned short) Controller810A0Angle0 >> 4);
        Controller810A0Helper4F178(preparedVector, position); }
        Controller810A0Field(owner, int *, 0xC) = (int) (Controller810A0Field(owner, int *, 0xC) + ((int) (((int) (*(short*)(Controller810A0Cos + (Controller810A0Field(tag, unsigned char *, 1) * 2)) * Controller810A0Field(tag, short *, 2)) >> 0xC) * *(short*)(Controller810A0Cos + (Controller810A0Field(tag, unsigned char *, 0) * 2))) >> 0xC));
        Controller810A0Field(owner, int *, 0x10) = (int) (Controller810A0Field(owner, int *, 0x10) + ((int) (((int) (*(short*)(Controller810A0Sin + (Controller810A0Field(tag, unsigned char *, 1) * 2)) * Controller810A0Field(tag, short *, 2)) >> 0xC) * *(short*)(Controller810A0Cos + (Controller810A0Field(tag, unsigned char *, 0) * 2))) >> 0xC));
        Controller810A0Field(owner, int *, 0x14) = (int) (Controller810A0Field(owner, int *, 0x14) + ((int) (*(short*)(Controller810A0Sin + (Controller810A0Field(tag, unsigned char *, 0) * 2)) * Controller810A0Field(tag, short *, 2)) >> 0xC));
        if (Controller810A0Helper18368(&frame.previous, position) != 0) {
            Controller810A0Field(tag, int *, 4) = 0;
        }
        decrementedHalfword = (unsigned short) Controller810A0Field(tag, short *, 2) - 0x1E;
        Controller810A0Field(tag, short *, 2) = decrementedHalfword;
        if (decrementedHalfword < 0) {
            Controller810A0Field(tag, short *, 2) = 0;
        }
        countdown = Controller810A0Field(tag, int *, 4);
        if (countdown < 0x20) {
            Controller810A0Field(owner, signed char *, 0x57) = (signed char) (0x3F - (countdown >> 1));
            Controller810A0Field(owner, signed char *, 0x54) = 0;
            Controller810A0Field(owner, signed char *, 0x55) = 0;
            Controller810A0Field(owner, signed char *, 0x56) = 0;
        }
        if (Controller810A0Helper359A4(tag + 4, 4) != 0) {
            handle = Controller810A0Field(tag, int *, 8);
            if (handle != 0) {
                Controller810A0Helper509E8(handle);
            }
            goto removeOwner;
        }
        goto finished;
removeOwner:
        Controller810A0Helper55B18(owner);
finished:;
}

#undef Controller810A0Field


extern Moby* Actor37B988_D_8006C550 __asm__("D_8006C550");
extern int Actor37B988_D_8006C648 __asm__("D_8006C648");
void Actor37B988_func_80055B18(Moby*) __asm__("func_80055B18");
int Actor37B988_func_800359A4(void* pTimer, int pTimerType) __asm__("func_800359A4");
void func_level_37_8007B988(Moby *actor) {
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
    void *byteAddress;
    void *privateBytes;
    void *sharedBytes;
    register Moby* pool __asm__("$2");

    pool = Actor37B988_D_8006C550;
    __asm__("" : "=r"(pool) : "0"(pool));
    state = actor->state;
    privateBytes = actor->mobyTag;
    sharedBytes = pool->mobyTag;
    switch (state) {
    case 0:
        state = 1;
        __asm__("" : "=r"(state) : "0"(state));
        actor->lowDrawDistance = 0x30;
        actor->unknown3[0] = state;
        actor->drawn = state;
        actor->colour.r = 0;
        actor->colour.g = 0;
        actor->colour.b = 0;
        actor->colour.a = 0x3F;
        actor->highDrawDistance = actor->lowDrawDistance;
        if ((*(int *)((unsigned char*)(privateBytes) + 4)) != 0) {
            actor->unknownCollision = 0;
        }
        actor->angle.yaw = ((*(int *)((unsigned char*)(privateBytes) + 4)) << 8) / 3;
        selector = *(int *)((unsigned char*)privateBytes + 4);
        __asm__("" : "=r"(selector), "=r"(state) : "0"(selector), "1"(state), "m"(actor->angle.yaw));
        *(volatile unsigned char*)&actor->state = state;
        __asm__("" : "=r"(selector) : "0"(selector), "m"(actor->state));
        actor->position.z += selector * 0x258;
        halfwordValue = *(int *)privateBytes;
        __asm__("" : "=r"(halfwordValue) : "0"(halfwordValue));
        if (halfwordValue == 0) {
            halfwordValue = 0x80;
        } else { halfwordValue = 0x40; }
        (*(unsigned short *)((unsigned char*)(privateBytes) + 8)) = halfwordValue;
        (*(int *)((unsigned char*)(sharedBytes) + 0xD4)) = 0;
        (*(short *)((unsigned char*)(privateBytes) + 0xA)) = (short) ((*(int *)((unsigned char*)(privateBytes) + 4)) * 6);

    case 1:
        if (Actor37B988_func_800359A4(privateBytes + 0xA, 2) != 0) {
            if ((*(int *)((unsigned char*)(privateBytes) + 0)) == 0) {
                temp_v1 = actor->colour.r + Actor37B988_D_8006C648;
                actor->colour.r = temp_v1;
                temp_v0 = (int) ((*(unsigned short *)((unsigned char*)(privateBytes) + 8)) << 0x10) >> 0x12;
                if (temp_v0 < (temp_v1 & 0xFF)) {
                    actor->colour.r = (unsigned char) temp_v0;
                }
                temp_v1_2 = actor->colour.g + Actor37B988_D_8006C648;
                actor->colour.g = temp_v1_2;
                temp_v0_2 = (int) ((*(unsigned short *)((unsigned char*)(privateBytes) + 8)) << 0x10) >> 0x12;
                if (temp_v0_2 < (temp_v1_2 & 0xFF)) {
                    actor->colour.g = (unsigned char) temp_v0_2;
                }
                temp_v1_3 = actor->colour.b + (Actor37B988_D_8006C648 * 4);
                actor->colour.b = temp_v1_3;
                temp_v0_3 = (short) (*(unsigned short *)((unsigned char*)(privateBytes) + 8));
                if (temp_v0_3 < (temp_v1_3 & 0xFF)) {
                    actor->colour.b = (unsigned char) temp_v0_3;
                }
            } else {
                temp_v1_4 = actor->colour.r + (Actor37B988_D_8006C648 * 4);
                actor->colour.r = temp_v1_4;
                temp_v0_4 = (short) (*(unsigned short *)((unsigned char*)(privateBytes) + 8));
                if (temp_v0_4 < (temp_v1_4 & 0xFF)) {
                    actor->colour.r = (unsigned char) temp_v0_4;
                }
                temp_v1_5 = actor->colour.g + (Actor37B988_D_8006C648 * 4);
                actor->colour.g = temp_v1_5;
                temp_v0_5 = (short) (*(unsigned short *)((unsigned char*)(privateBytes) + 8));
                if (temp_v0_5 < (temp_v1_5 & 0xFF)) {
                    actor->colour.g = (unsigned char) temp_v0_5;
                }
                temp_v1_6 = actor->colour.b + Actor37B988_D_8006C648;
                actor->colour.b = temp_v1_6;
                temp_v0_6 = (int) ((*(unsigned short *)((unsigned char*)(privateBytes) + 8)) << 0x10) >> 0x12;
                if (temp_v0_6 < (temp_v1_6 & 0xFF)) {
                    actor->colour.b = (unsigned char) temp_v0_6;
                }
            }
        }
        goto updateTail;
    case 2:
        if ((*(int *)((unsigned char*)(privateBytes) + 0)) == 0) {
            temp_v0_8 = actor->colour.r - Actor37B988_D_8006C648;
            actor->colour.r = temp_v0_8;
            if ((unsigned int) (temp_v0_8 & 0xFF) >= 0x81U) {
                actor->colour.r = 0;
            }
            temp_v0_9 = actor->colour.g - Actor37B988_D_8006C648;
            actor->colour.g = temp_v0_9;
            if ((unsigned int) (temp_v0_9 & 0xFF) >= 0x81U) {
                actor->colour.g = 0;
            }
            step = Actor37B988_D_8006C648;
            fade = actor->colour.b;
            __asm__("" : "=r"(step), "=r"(fade) : "0"(step), "1"(fade));
            fadeByte = fade - (step * 4);
            actor->colour.b = fadeByte;
            goto block_33;
        }
        step = Actor37B988_D_8006C648;
            fade = actor->colour.r;
            __asm__("" : "=r"(step), "=r"(fade) : "0"(step), "1"(fade));
            temp_v0_10 = fade - (step * 4);
        actor->colour.r = temp_v0_10;
        if ((unsigned int) (temp_v0_10 & 0xFF) < 0x81U) {
            step = Actor37B988_D_8006C648;
            fade = actor->colour.g;
            __asm__("" : "=r"(step), "=r"(fade) : "0"(step), "1"(fade));
            fadeByte = fade - (step * 4);
            actor->colour.g = fadeByte;
block_33:
            if ((unsigned int) (fadeByte & 0xFF) >= 0x81U) {
                goto block_34;
            }
            goto updateTail;
        }
block_34:
        Actor37B988_func_80055B18(actor);
        return;
    default:
updateTail:
        if ((*(int *)((unsigned char*)(sharedBytes) + 0xD4)) != 0) {
            byteIndex = 0;
            do {
                byteAddress = (unsigned char*)actor + byteIndex;
                byteIndex += 1;
                (*(unsigned char *)((unsigned char*)(byteAddress) + 0x54)) = (unsigned char) ((*(unsigned char *)((unsigned char*)(byteAddress) + 0x54)) + ((*(int *)((unsigned char*)(sharedBytes) + 0xD4)) * 2));
            } while (byteIndex < 3);
            rawSelector = (*(int *)((unsigned char*)(privateBytes) + 4));

            if (rawSelector == 0) {
                Actor37B988_func_800359A4(sharedBytes + 0xD4, 4);
                goto reloadSelector;
            }
            selectorBit = rawSelector & 1;
        } else {
reloadSelector:
            selectorBit = (*(int *)((unsigned char*)(privateBytes) + 4)) & 1;
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


INCLUDE_ASM("asm/nonmatchings/overlays/level_37/moby", func_level_37_8007BD9C);

/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * Original raw447 local controller words are authoritative. Factory
 * descendants, private producer, live counter writers/cadence unresolved. */
extern int D_8006C578,D_8006C574,D_8006C648,D_8006C770;
extern int DecodedRaw447Counters[] __asm__("D_80066EEC");
extern unsigned char DecodedRaw447Player[] __asm__("D_80070328");
int func_80037A60(Moby*,void*,int,int,int);
void func_level_37_8007D694(Moby* argument) {
 register Moby* moby __asm__("$17")=argument;
 register unsigned char* tag __asm__("$18")=moby->mobyTag;
 register int index __asm__("$16");
 if(moby->state<2 && moby->damageFlags) {
  int angle;
  index=0;__asm__("" : "=r"(index):"0"(index));
  do {
   if(D_8006C578-D_8006C574<21)goto finished_requests;
   {register int rawType __asm__("$4")=448;
    register Moby* spawning __asm__("$5")=moby;
    __asm__("" : "=r"(rawType),"=r"(spawning):"0"(rawType),"1"(spawning));
    SpawnMoby(rawType,spawning);index++;}
  }while(index<10);
finished_requests:
  angle=moby->unkb;
  if(!angle)angle=func_800360F8(func_8004E880(moby->position.x-*(int*)DecodedRaw447Player,moby->position.y-*(int*)(DecodedRaw447Player+4),0),DecodedRaw447Player[14],32,64);
  {
   register int rawType __asm__("$4")=16;
   register Moby* spawning __asm__("$5")=moby;
   register Moby* (*spawn)(int,Moby*) __asm__("$2");
   register int initial __asm__("$3");
   __asm__("" : "=r"(rawType),"=r"(spawning):"0"(rawType),"1"(spawning));
   *(int*)(tag+4)=angle;
   spawn=SpawnMoby;__asm__("" : "=r"(spawn):"0"(spawn));
   initial=250;*(int*)tag=initial;*(int*)(tag+8)=0;spawn(rawType,spawning);
  }
  moby->state=2;func_80034F40(moby,2);
 }
 DecodedRaw447Counters[1]+=D_8006C648;
 if(DecodedRaw447Counters[1]>=30001)DecodedRaw447Counters[1]=30000;
 moby->damageFlags=0;
 if(moby->substate<255)moby->substate++;
 switch(moby->state) {
 case 0:
  if(func_800359A4(tag+22,1)) {moby->state=1;func_80034F40(moby,1);}
  func_80037168(moby,(Vector3D*)tag,1);
  if(func_800359A4(tag+23,1)) {tag[23]=(rand()&63)+120;func_8003BABC(moby,3,0);}break;
 case 1:
  if(func_800359A4(tag+23,1)) {tag[23]=(rand()&31)+80;func_8003BABC(moby,rand()%3,0);}
  if(D_8006C770) {tag[22]=func_8003636C(180,255);tag[23]=0;moby->state=0;func_80034F40(moby,0);}break;
 case 2:
  func_80035030(moby,tag,*(int*)(tag+4),tag+8,12,0,300,1);
  if(D_8006C770) {func_80055D24(moby,4);func_800369B8(moby,40);func_80055B18(moby);return;}break;
 case 10:
  if(func_80037A60(moby,tag+8,4,16,-200)) {moby->state=1;func_80034F40(moby,1);}break;
 }
 func_80055D24(moby,1);
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
    if (tag->velocity.z < -24) tag->velocity.z = -24;
    if (!tag->mode) moby->angle.yaw += 12;
    else if (tag->velocity.z < 0) {
        pitch = moby->angle.pitch;
        pitchStep = tag->pitchStep;
        __asm__("" : "=r"(pitch), "=r"(pitchStep) : "0"(pitch), "1"(pitchStep));
        sum = pitch + pitchStep;
        __asm__("" : "=r"(sum) : "0"(sum));
        if (sum == 0x20 || sum == 0xE0) {
            reversed = -pitchStep;
            __asm__("" : "=r"(reversed) : "0"(reversed));
            tag->pitchStep = reversed;
        }
        moby->angle.pitch += *(unsigned char*)&tag->pitchStep;
        moby->position.y += tag->pitchStep;
        if (rand() & 1) moby->angle.yaw++;
    }
    moby->position.z += tag->velocity.z;
    tag->timer--;
    } else func_80055B18(moby);
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_37/moby", func_level_37_8007DB84);

INCLUDE_ASM("asm/nonmatchings/overlays/level_37/moby", func_level_37_8007E1C8);

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
    if (D_8006C770) func_80055B18(moby);
}

INCLUDE_ASM("asm/nonmatchings/overlays/level_37/moby", func_level_37_8007E824);

INCLUDE_ASM("asm/nonmatchings/overlays/level_37/moby", func_level_37_8007EFFC);

INCLUDE_ASM("asm/nonmatchings/overlays/level_37/moby", func_level_37_8007FC30);

extern Moby* D_8006C550;
void func_80055B18(Moby*);
void func_level_37_80080FC0(Moby *moby) {
    Moby *linked;

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
	int DAT_80070104; // 80070104
	int DAT_80070108; // 80070108
	int DAT_8007010c; // 8007010c
	int DAT_80070110; // 80070110
	char DAT_80070114; // 80070114
	char DAT_80070115; // 80070115
	short DAT_80070116; // 80070116, maybe char?
	int DAT_80070118; // 80070118
	int DAT_8007011c; // 8007011c
	int DAT_80070120; // 80070120
	Vector3D DAT_80070124; // 80070124, type is a guess
	char DAT_80070130; // 80070130
	char DAT_80070131; // 80070131
	char DAT_80070132; // 80070132
	char DAT_80070133; // 80070133
	short DAT_80070134; // 80070134
	short DAT_80070136; // 80070136
	int DAT_80070138; // 80070138
	int DAT_8007013c; // 8007013c
	int DAT_80070140; // 80070140
	int DAT_80070144; // 80070144
	int DAT_80070148; // 80070148
	short DAT_8007014c; // 8007014c
	char DAT_8007014e; // 8007014e
	char DAT_8007014f; // 8007014f
	int DAT_80070150; // 80070150
	int DAT_80070154; // 80070154
	short DAT_80070158; // 80070158
	short loadLevel; // 8007015a; i.e. to load via vehicle
	int DAT_8007015c; // 8007015c
} D_80070104;
extern int D_8006C598,D_8006C73C,D_8006C528,currentLevel;
extern short D_800658A0[256],D_80065920[256];
extern Game game;
extern unsigned char lvlIdToIndex[0x48];
extern unsigned char eggsCollectedArray[];
extern int Vehicle506Global __asm__("D_80070148");
void func_8005663C(void);
int func_8001A358(Vector3D*,int);
/* AI generated adaptation; not human reviewed. SCUS-94467 level10 8007F0BC. */
typedef struct {int unk0,unk4,unk8;PathTag* path;int timer;} Vehicle546Tag;
extern unsigned char Vehicle546Table[] __asm__("D_80071FB0");
void func_level_37_80081064(Moby* arg0) {
    Vector3D sp10,sp20,sp30,sp40,sp50;
    int temp_v1_3,count;
    Vehicle546Tag* mobyTag=(Vehicle546Tag*)arg0->mobyTag;
    switch(arg0->state) {
    case 0:
        switch(arg0->substate) {
        case 0:
            if(progressFlags.lvl20_WhirligigUsable)goto deleteVehicle;
            if(D_8006C73C != 0 && currentLevel != D_8006C73C &&
               ((temp_v1_3=D_8006C73C%10,temp_v1_3==0) || (temp_v1_3==7 && D_8006C73C<60))) {
                arg0->position.z+=0xC00;
                func_800136F0(&camera.unk170,(Vector3D*)mobyTag->path->nodes,&arg0->position);
                camera.unk170.pos.azimuth-=spyro.rotation.yaw;
                camera.unk170.yaw=0;camera.unk170.pitch=0;
                func_8004F178(&spyro.position,&arg0->position);
                spyro.position.z+=spyro.unk4a+0x280;
                func_80012BA8(&camera.unk170);
                func_8004F178(&camera.unk184,&camera.unk60);
                arg0->substate=1;arg0->state=7;
            } else {
                count=eggsCollectedArray[lvlIdToIndex[21]]&1;
                if(eggsCollectedArray[lvlIdToIndex[22]]&1)count++;
                if(eggsCollectedArray[lvlIdToIndex[23]]&1)count++;
                if(eggsCollectedArray[lvlIdToIndex[24]]&1)count++;
                if(eggsCollectedArray[lvlIdToIndex[26]]&1)count++;
                if(count==5) {
                deleteVehicle: func_80055B18(arg0);return;
                }
                if(currentLevel!=10 || Vehicle546Table[lvlIdToIndex[17]]!=0) {
                    arg0->substate=1;arg0->state=3;
                } else {
                    arg0->substate=2;arg0->state=1;arg0->position.z+=0xC00;
                }
                func_80055D24(arg0,2);mobyTag->timer=0;
            }
            break;
        case 1:arg0->state=3;break;
        case 2:
            arg0->position.z+=0xC00;func_80055D24(arg0,2);mobyTag->timer=0;arg0->state=1;break;
        }
        func_8003B7B4(&arg0->substate,1,&unsavedData);
        break;
    case 2:
        arg0->position.z-=64;
        func_8004F178(&sp10,&arg0->position);sp10.z+=512;
        sp10.z=func_8001A358(&sp10,512);
        if(sp10.z!=0) {
            arg0->position.z=sp10.z;arg0->state=3;
            func_8003B7B4(&arg0->state,1,&savedData);
            func_8003B7B4(&arg0->state,1,&unsavedData);arg0->substate=0;
        }
        func_80055D24(arg0,2);break;
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
                func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes, &arg0->position);
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
        arg0->position.z = (int) (arg0->position.z + 0x40);
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
                if ((D_80070104.loadLevel == 0x14) && (eggsCollectedArray[lvlIdToIndex[17]] == 0)) {
                    D_80070104.loadLevel = 0x11;
                }
                // BUG // Spike Bug
                // In NTSC-U Rev 0, the game checks if "Bianca Strikes Back" has been seen instead of "Spike Is Born"
                // As this cutscene is always seen by this point in normal play, "Spike Is Born" is never shown to the player
                // This was fixed in all later revisions
                if ((D_80070104.loadLevel != 0x11) || (progressFlags.lvl63_BiancaStrikesBack != 0)) {
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
typedef struct {int unk0;PathTag* path;int timer;} Vehicle864Tag;
extern Moby* Vehicle864Moby __asm__("D_8006C65C");
extern int D_8006C770;
void func_80034F80(Moby*,int);
void func_level_37_800818EC(Moby* arg0) {
    Vector3D sp10,sp20,sp30,sp40,sp50,sp60;
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
            }
            else {
                func_80034F80(arg0,2);
                arg0->position.z+=0x1000;
                if(currentLevel==37)arg0->position.z+=0x800;
                spyro.unk17a=0x1001A000;spyro.unk20[1]=0;
                func_8004F178(&spyro.unk19,&arg0->position);
                spyro.unk19.z+=spyro.unk4a+0x604;
                spyro.unk18.roll=arg0->angle.roll;spyro.unk18.pitch=arg0->angle.pitch;spyro.unk18.yaw=arg0->angle.yaw;
                arg0->substate=1;
                func_8003B7B4(&arg0->substate,1,&savedData);
                func_8003B7B4(&arg0->substate,1,&unsavedData);
                arg0->state=8;
                if ((D_8006C73C != 0) && (currentLevel != D_8006C73C) && ((temp_v1_3 = D_8006C73C % 10, (temp_v1_3 == 0)) || ((temp_v1_3 == 7) && (D_8006C73C < 0x3C))) && (arg0->mobyClass == D_8006C528) && D_8006C73C !=47) {
                    func_80034F80(arg0,2);
                    arg0->position.z += 0xC00;
                    func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes, &arg0->position);
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
            func_80034F80(arg0,2);
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
                    D_80070104.loadLevel=((currentLevel/10)+1)*10;
                    func_80034F40(arg0,1);
                    spyro.unk17a=0x10018000;
                    func_8004F178(&spyro.unk19,&arg0->position);spyro.unk19.z+=0x400;
                    {int height=func_8001A358(&spyro.unk19,0x800);
                     spyro.unk20[1]=0;spyro.unk18.roll=0;spyro.unk18.pitch=0;
                     spyro.unk19.z=height+spyro.unk4a;spyro.unk18.yaw=arg0->angle.yaw;}
                    arg0->state=4;
                }
                func_8004F178(&camera.unk184, &arg0->position);
                func_800136F0(&camera.unk170, (Vector3D*)mobyTag->path->nodes, &arg0->position);
                camera.unk170.yaw = 0;
                camera.unk170.pitch = 0;
                camera.unk168 = 0x11;
            }
        }
        break;

    case 3:
        camera.unk168=0;
        if(D_80070104.loadLevel!=0) {
            func_80034F40(arg0,1);
            spyro.unk17a=0x10018000;
            func_8004F178(&spyro.unk19,&arg0->position);
            spyro.unk19.z+=0x400;
            {int height=func_8001A358(&spyro.unk19,0x800);
             spyro.unk20[1]=0;spyro.unk18.roll=0;spyro.unk18.pitch=0;
             spyro.unk19.z=height+spyro.unk4a;spyro.unk18.yaw=arg0->angle.yaw;}
            arg0->state=4;
        } else arg0->state=6;
        break;
    case 4:
        spyro.unk17a=0x10018000;
        spyro.unk19.z+=0x100-spyro.unk4a;
        {int height=func_8001A358(&spyro.unk19,512);
         spyro.unk20[1]=0;spyro.unk18.roll=0;spyro.unk18.pitch=0;
         spyro.unk19.z=height+spyro.unk4a;spyro.unk18.yaw=arg0->angle.yaw;}
        if(D_8006C770!=0) {
            func_80034F80(arg0,2);spyro.unk17a|=0x2000;
            if(Vehicle864Moby!=0) {
                *((unsigned char*)Vehicle864Moby+0x4C)=0;
                *((unsigned char*)Vehicle864Moby+0x4D)=0;
            }
            mobyTag->timer=120;arg0->state=5;
        }
        break;
    case 5:
        arg0->position.z = (int) (arg0->position.z + 0x40);
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
                if(progressFlags.lvl68_TheEscape!=0) {
                    func_80054F94(D_80070104.loadLevel,arg0);
                } else {progressFlags.lvl68_TheEscape=1;func_800584BC(6,0x44);}
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
            mobyTag->timer=120;arg0->substate=0;
            func_80034F40(arg0,1);arg0->state=10;
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
            func_80034F40(arg0,3);
            spyro.unk17a=0x10018000;
            func_8004F178(&spyro.unk19,&arg0->position);spyro.unk19.z+=0xE00;
            {int height=func_8001A358(&spyro.unk19,0x800);
             spyro.unk20[1]=0;spyro.unk18.roll=0;spyro.unk18.pitch=0;
             spyro.unk19.z=height+spyro.unk4a;spyro.unk18.yaw=arg0->angle.yaw;}
            arg0->state=9;goto updateCollision2;
        } else goto rollbackLanding;
        break;

    case 9:
        spyro.unk17a=0x10018000;
        spyro.unk19.z+=0x100-spyro.unk4a;
        {int height=func_8001A358(&spyro.unk19,512);
         spyro.unk20[1]=0;spyro.unk18.roll=0;spyro.unk18.pitch=0;
         spyro.unk19.z=height+spyro.unk4a;spyro.unk18.yaw=arg0->angle.yaw;}
        func_80013AE4((Vector3D*)mobyTag->path->nodes,&spyro.position);
        if(D_8006C770!=0) {func_80034F80(arg0,0);func_80013B7C(0);arg0->state=6;}
        break;
    case 10:
        if(mobyTag->timer!=0) {
            arg0->position.z+=64;func_800359A4(&mobyTag->timer,4);
            if(arg0->substate==0) {
                spyro.unk17a=0x10000002;
                if(spyro.movementState==0)arg0->substate=1;
            }
        }
        if(D_8006C7B4&1) {func_80034F40(arg0,3);arg0->state=11;}
        else if(arg0->animationState.id==1 && D_8006C770!=0)func_80034F80(arg0,2);
        break;
    case 11:
        if(arg0->animationState.id==3 && D_8006C770!=0)func_80034F80(arg0,0);
        spyro.unk17a=0x10000002;arg0->position.z-=64;
        func_8004F178(&sp60,&arg0->position);arg0->position.z+=1024;sp60.z+=512;
        sp60.z=func_8001A358(&sp60,512);
        if(sp60.z!=0) {
            arg0->position.z=sp60.z;
            if(arg0->animationState.id==0) {arg0->substate=0;arg0->state=1;}
        } else {rollbackLanding: arg0->position.z-=1024;}
        updateCollision2: func_80055D24(arg0,2);break;

    }
    func_80055D24(arg0,1);
}


extern ProgressFlags progressFlags;

extern int D_8006C598,D_8006C73C,D_8006C528,currentLevel;
extern short D_800658A0[256],D_80065920[256];
extern Game game;
extern unsigned char lvlIdToIndex[0x48];
extern unsigned char eggsCollectedArray[];
/* AI generated adaptation of upstream func_level_17_8007D19C; not human reviewed.
 * Original SCUS-94467 level10 800805A0 instruction route; units/cadence open. */
typedef struct {int unk0,unk4;PathTag* unk8;int unkC,unk10;} Vehicle506Tag;
extern int Vehicle506Global __asm__("D_80070148");
void func_8005663C(void);
int func_8001A358(Vector3D*,int);
void func_level_37_8008266C(Moby* arg0) {
    Vector3D sp10;
    Vector3D sp20;
    Vector3D sp30;
    Vector3D sp40;
    int temp_v1_3;
    Vehicle506Tag* mobyTag;

    mobyTag = (Vehicle506Tag*)arg0->mobyTag;
    switch (arg0->state) {

    case 0:
        switch (arg0->substate) {
        case 0:
            if (progressFlags.lvl30_RocketUsable || ((currentLevel != 0x14) && !progressFlags.lvl20_WhirligigUsable)) {
                func_80055B18(arg0);
                return;
            }
            else {
                if ((D_8006C73C != 0) && (currentLevel != D_8006C73C) && ((temp_v1_3 = D_8006C73C % 10, (temp_v1_3 == 0)) || ((temp_v1_3 == 7) && (D_8006C73C < 0x3C))) && (arg0->mobyClass == D_8006C528)) {
                    arg0->position.z += 0xC00;
                    func_800136F0(&camera.unk170, (Vector3D*)mobyTag->unk8->nodes, &arg0->position);
                    camera.unk170.pos.azimuth -= spyro.rotation.yaw;
                    camera.unk170.yaw = 0;
                    camera.unk170.pitch = 0;
                    spyro.unk17a = 0x10018000;
                    spyro.unk20[1] = 0;
                    func_8004F178(&spyro.unk19, &arg0->position);
                    spyro.unk19.z += spyro.unk4a + 0x133;
                    spyro.unk18.roll = arg0->angle.roll;
                    spyro.unk18.pitch = arg0->angle.pitch;
                    spyro.unk18.yaw = arg0->angle.yaw;
                    func_80012BA8(&camera.unk170);
                    func_8004F178(&camera.unk184, &camera.unk60);
                    arg0->state = 7;
                } else if (arg0->state == 0) {
                    arg0->state = 1;
                }
            }
            break;

        default:
            break;

        case 1:
            arg0->position.z += 0xF00;
            func_80055D24(arg0, 2);
            mobyTag->unkC = 0;
            arg0->state = 8;
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
                func_800136F0(&camera.unk170, (Vector3D*)mobyTag->unk8->nodes, &arg0->position);
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
            arg0->state = 4;
        } else {
            arg0->state = 5;
        }
        break;

    case 4:
        func_80034F40(arg0, 1);
        arg0->position.z = (int) (arg0->position.z + 0x40);
        spyro.unk17a = 0x10008000;
        spyro.unk20[1] = 0;
        func_8004F178(&spyro.unk19, &arg0->position);
        spyro.unk19.z += spyro.unk4a + 0x133;
        spyro.unk18.roll = spyro.bodyRotation.roll;
        spyro.unk18.pitch = spyro.bodyRotation.pitch;
        spyro.unk18.yaw = spyro.bodyRotation.yaw;
        func_8004F178(&camera.unk184, &arg0->position);
        func_800136F0(&camera.unk170, (Vector3D*)mobyTag->unk8->nodes, &arg0->position);
        camera.unk170.yaw = 0;
        camera.unk170.pitch = 0;
        camera.unk168 = 0x11;
        if (func_800359A4(&mobyTag->unkC, 4) != 0) {
            D_8006C598 += 0x10;
            if (D_8006C598 >= 0xFF) {
                D_8006C598 = 0xFF;
                if ((D_80070104.loadLevel == 0x1E) && (eggsCollectedArray[lvlIdToIndex[27]] == 0)) {
                    D_80070104.loadLevel = 0x1B;
                }
                // BUG // Spike Bug
                // In NTSC-U Rev 0, the game checks if "Bianca Strikes Back" has been seen instead of "Spike Is Born"
                // As this cutscene is always seen by this point in normal play, "Spike Is Born" is never shown to the player
                // This was fixed in all later revisions
                if ((D_80070104.loadLevel != 0x1B) || (progressFlags.lvl63_BiancaStrikesBack != 0)) {
                    func_80054F94(D_80070104.loadLevel, arg0);
                } else {
                    progressFlags.lvl65_SpikeIsBorn = 1;
                    func_800584BC(6, 0x41);
                }
            }
        }
        func_80055D24(arg0, 2);
        break;

    case 5:
        sp10.x = D_80065920[arg0->angle.yaw];
        sp10.y = D_800658A0[arg0->angle.yaw];
        sp10.z = 0;
        func_8004F194(&sp10, &sp10, &arg0->position);
        if (ovlHeader.unk2c(&sp10) != 0) {
            spyro.unk17c = 0;
            ovlHeader.unk2b(&sp10, arg0->angle.yaw, 0);
            arg0->state = 6U;
        }
        break;

    case 6:
        sp20.x = D_80065920[arg0->angle.yaw];
        sp20.y = D_800658A0[arg0->angle.yaw];
        sp20.z = 0;
        func_8004F194(&sp20, &sp20, &arg0->position);
        if (ovlHeader.unk2b(&sp20, arg0->angle.yaw, 0) != 0) {
            func_8004F178(&sp30, &spyro.position);
            sp30.z -= spyro.unk4a;
            func_8003B634(&savedData, &sp30, spyro.bodyRotation.yaw);
            func_80034F40(arg0, 0);
            arg0->state = 1;
        }
        break;

    case 7:
        func_80034F40(arg0, 1);
        arg0->position.z -= 0x40;
        spyro.unk17a = 0x10018000;
        spyro.unk20[1] = 0;
        func_8004F178(&spyro.unk19, &arg0->position);
        spyro.unk19.z += spyro.unk4a + 0x133;
        spyro.unk18.roll = arg0->angle.roll;
        spyro.unk18.pitch = arg0->angle.pitch;
        spyro.unk18.yaw = arg0->angle.yaw;
        func_80013AE4((Vector3D*)mobyTag->unk8->nodes, &spyro.position);
        func_8004F178(&sp40, &arg0->position);
        arg0->position.z += 0x400;
        sp40.z += 0x200;
        sp40.z = func_8001A358(&sp40, 0x200);
        if (sp40.z != 0) {
            arg0->position.z = sp40.z;
            func_80013B7C(0);
            arg0->state = 5U;
        } else {
            arg0->position.z -= 0x400;
        }
        func_80055D24(arg0, 2);
        break;


    }

    if ((game.state == 0) && (arg0->animationState.nextId == 1)) {
        if (func_8003BFC0(arg0, mobyTag->unk10) == 0) {
            mobyTag->unk10 = func_8003BABC(arg0, 0, 4);
            return;
        }
    } else {
        if (func_8003BFC0(arg0, mobyTag->unk10) != 0) {
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
#define Controller821F8Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Controller821F8CDLoadTime(void) __asm__("CDLoadTime");
int Controller821F8func_8002803C(int,int,void*,int,void*,int,int) __asm__("func_8002803C");
int Controller821F8func_80028154(int) __asm__("func_80028154");
int Controller821F8func_8002AF9C(void*,int,int) __asm__("func_8002AF9C");
int Controller821F8func_80034F40(void*,int) __asm__("func_80034F40");
int Controller821F8func_800359A4(void*,int) __asm__("func_800359A4");
int Controller821F8func_8003613C(int,int) __asm__("func_8003613C");
int Controller821F8func_80039974(int,int,int) __asm__("func_80039974");
int Controller821F8func_8003BABC(void*,int,int) __asm__("func_8003BABC");
int Controller821F8func_8003BE70(int) __asm__("func_8003BE70");
int Controller821F8func_8003BFC0(void*,int) __asm__("func_8003BFC0");
int Controller821F8func_8003C140(int,int) __asm__("func_8003C140");
int Controller821F8func_800492DC(void*,int) __asm__("func_800492DC");
int Controller821F8func_8004E880(int,int,int) __asm__("func_8004E880");
int Controller821F8func_8004F178(void*,void*) __asm__("func_8004F178");
int Controller821F8func_8004F264(int,int) __asm__("func_8004F264");
int Controller821F8func_8004F334(void*,void*) __asm__("func_8004F334");
int Controller821F8func_800527C4(void*,int) __asm__("func_800527C4");
int Controller821F8func_80055B18(void*) __asm__("func_80055B18");
int Controller821F8func_80055D24(void*,int) __asm__("func_80055D24");
int Controller821F8func_80055F14(void*,int,void*) __asm__("func_80055F14");
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
extern unsigned int *Controller821F8D_8006C5B0 __asm__("D_8006C5B0");
extern void* (*Controller821F8SpawnMoby)(int,void*) __asm__("SpawnMoby");
extern int (*Controller821F8SpawnParticle)(int,int,void*,int) __asm__("SpawnParticle");
extern int (*Controller821F8SpawnFragments)(int,int,void*,void*,int,int) __asm__("SpawnFragments");
void func_level_37_80082E54(void *input) {
    register unsigned char *owner __asm__("$17")=input;
    struct {int vector[4];short rect[4];} frame;
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
    register void *finishOwner __asm__("$4");
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
    unsigned char *temp_v1_4;
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
    register void *temp_a0 __asm__("$4");
    void *temp_a0_10;
    void *temp_a0_11;
    void *temp_a0_4;
    void *temp_a0_6;
    void *temp_a0_7;
    void *temp_a0_8;
    void *temp_a0_9;
    register unsigned char *tag __asm__("$16");
    void *childForAngle;
    void *spawnedChild;
    void *spawnedRecord;
    void *temp_v1_10;
    void *temp_v1_12;
    void *temp_v1_14;
    void *temp_v1_8;

    tag = Controller821F8Field(owner, void **, 0);
    distance = Controller821F8func_8004F334(owner + 0xC, Controller821F8D_80070328);
    {register int heightOffset __asm__("$3")=Controller821F8Field(owner,short*,0x38);
     temp_v0=Controller821F8Field(owner,int*,20);
     __asm__("" : "=r"(heightOffset),"=r"(temp_v0) : "0"(heightOffset),"1"(temp_v0));
     temp_v0-=heightOffset;
     __asm__("" : "=r"(temp_v0) : "0"(temp_v0) : "$3");
     heightOffset=Controller821F8Field(Controller821F8D_80070328,int*,8);
     {register int base __asm__("$4")=Controller821F8Field(Controller821F8D_80070328,int*,0x44);
      __asm__("" : "=r"(heightOffset),"=r"(base) : "0"(heightOffset),"1"(base));
      temp_v0-=heightOffset;temp_v0+=base;}}
    temp_a0 = Controller821F8Field(tag, void **, 8);
    verticalDistance = temp_v0;
    if (temp_v0 < 0) {
        verticalDistance = -verticalDistance;
    }
    sharedTailEnabled=0;
    if (temp_a0 != 0) {
        Controller821F8func_80055F14(temp_a0, 0, &frame.vector);
    }
    __asm__ volatile("" : "=r"(sharedTailEnabled) : "0"(sharedTailEnabled));
    temp_v1 = Controller821F8Field(owner, unsigned char *, 0x48);
    switch (temp_v1) {                              /* switch 1 */
    case 0:                                         /* switch 1 */
        if (Controller821F8Field(tag, short *, 6) < 0) {
            Controller821F8Field(tag, short *, 6) = (short) Controller821F8Field(owner, unsigned char *, 0x46);
        }
        temp_v1_2 = Controller821F8Field(tag, short *, 0);
        if (temp_v1_2 >= 0) {
            if ((((int) Controller821F8D_8006C7B4 >> temp_v1_2) & 1) || (((int) *(Controller821F8D_80070300 + Controller821F8D_8006C58C) >> temp_v1_2) & 1)) {
                Controller821F8func_80055B18(owner);
            } else if (Controller821F8func_8004F334(owner + 0xC, Controller821F8D_80070328) < 0x2000) {
                var_v0 = ((Controller821F8Field(owner, int *, 0x14) - Controller821F8Field(owner, short *, 0x38)) - Controller821F8Field(Controller821F8D_80070328, int *, 8)) + Controller821F8Field(Controller821F8D_80070328, int *, 0x44);
                if (var_v0 < 0) {
                    var_v0 = -var_v0;
                }
                if ((var_v0 < 0x800) && ((Controller821F8func_8004F264(Controller821F8Field(owner, unsigned char *, 0x46), Controller821F8func_8004E880(Controller821F8Field(Controller821F8D_80070328, int *, 0) - Controller821F8Field(owner, int *, 0xC), Controller821F8Field(Controller821F8D_80070328, int *, 4) - Controller821F8Field(owner, int *, 0x10), 0)) < 0x20) || (Controller821F8Field(tag, short *, 0x16) != 0))) {
                    Controller821F8Field(owner, unsigned char *, 0x48) = 7U;
                    Controller821F8Field(tag, unsigned short *, 0xC) = 0U;
                }
            }
        }
    default:                                        /* switch 1 */
        goto sharedTail;
    case 7:                                         /* switch 1 */
        if ((distance >= 0x2401) || (verticalDistance >= 0x901)) {
            Controller821F8Field(owner, unsigned char *, 0x48) = 0U;
        } else if ((distance < 0x800) && (verticalDistance < 0x200) && ((Controller821F8Field(Controller821F8D_80070328, int *, 0xB8) == 0) || ((unsigned int) (Controller821F8Field(Controller821F8D_80070328, int *, 0x50) - 0xB) < 2U)) && ((Controller821F8func_8004F264(Controller821F8Field(owner, unsigned char *, 0x46), Controller821F8func_8004E880(Controller821F8Field(Controller821F8D_80070328, int *, 0) - Controller821F8Field(owner, int *, 0xC), Controller821F8Field(Controller821F8D_80070328, int *, 4) - Controller821F8Field(owner, int *, 0x10), 0)) < 0x20) || (Controller821F8Field(tag, short *, 0x16) != 0))) {
            Controller821F8Field(owner, unsigned char *, 0x48) = 1U;
        }
        goto sharedTail;
    case 1:                                         /* switch 1 */
        Controller821F8func_800527C4(owner, Controller821F8Field(tag, short *, 0));
        /* fallthrough */
    case 2:                                         /* switch 1 */
        if (Controller821F8func_8003BFC0(owner, Controller821F8Field(tag, short *, 0x14)) == 0) {
            temp_v0_2 = Controller821F8func_8003BABC(owner, 0, 4);
            Controller821F8Field(tag, short *, 0x14) = temp_v0_2;
            if (temp_v0_2 >= 0) {
                Controller821F8func_8003C140(temp_v0_2, 1);
            }
        }
        temp_a0_2 = Controller821F8Field(tag, short *, 0);
        temp_v1_4 = Controller821F8D_8006C58C + Controller821F8D_80070300;
        temp_a1 = *temp_v1_4;
        if (!(((int) temp_a1 >> temp_a0_2) & 1)) {
            *temp_v1_4 = temp_a1 | (1 << temp_a0_2);
            Controller821F8D_8006C660 += 1;
        } else {
            Controller821F8D_8006C7D0 = 1;
        }
        var_a1=0x10000002;
        {register int flags __asm__("$2")=Controller821F8Field(Controller821F8D_80070328,int*,0x20C);
         __asm__("" : "=r"(flags),"=r"(var_a1) : "0"(flags),"1"(var_a1));
         Controller821F8Field(Controller821F8D_80070328,int*,0x20C)=flags|var_a1;}
        Controller821F8func_800492DC(owner + 0xC,var_a1);
        Controller821F8Field(tag, short *, 2) = 0xB4;
        Controller821F8D_8006C3EC = 0;
        Controller821F8Field(owner, unsigned char *, 0x48) = 3U;
        if (Controller821F8Field(((Controller821F8Field(tag, short *, 0) * 0xC) + Controller821F8D_8006C7A0), unsigned char *, 7) == 0xFF) {
            Controller821F8Field(tag, short *, 4) = -1;
            Controller821F8Field(owner, unsigned char *, 0x49) = 4U;
        } else {
            Controller821F8Field(tag, short *, 4) = Controller821F8func_8002803C(0x36, -1, Controller821F8func_80027F88, 0, Controller821F8func_80029CF8, *(int*)((Controller821F8Field(tag, short *, 0) * 0xC) + Controller821F8D_8006C7A0), 0);
            Controller821F8D_8006E49C = 1;
            Controller821F8Field(owner, unsigned char *, 0x49) = 0U;
        }
        goto sharedTail;
    case 3:                                         /* switch 1 */
        if (Controller821F8func_8003BFC0(owner, Controller821F8Field(tag, short *, 0x14)) == 0) {
            temp_v0_3 = Controller821F8func_8003BABC(owner, 0, 4);
            Controller821F8Field(tag, short *, 0x14) = temp_v0_3;
            var_a0 = (temp_v0_3<<16)>>16;
            if (var_a0 >= 0) {
                var_a1 = Controller821F8D_8006C3EC << 0xC;
                goto updateOwnerHeight;
            }
        } else {
            var_a1 = Controller821F8D_8006C3EC;
            {register int condition __asm__("$2")=var_a1<65;
             __asm__("" : "=r"(condition) : "0"(condition));
             var_a1<<=12;
            if (condition) {
                var_a0 = Controller821F8Field(tag, short *, 0x14);
updateOwnerHeight:
                Controller821F8func_8003C140(var_a0, (var_a1 >> 6) | 1);
            }
            }
        }
        {register int selector __asm__("$4")=1;
         register int kind __asm__("$5")=12;
         register void *particleOwner __asm__("$6")=owner;
         register int mode __asm__("$7")=5;
         register int height __asm__("$2");register int alpha __asm__("$3");
         register int (*particle)(int,int,void*,int) __asm__("$8");
         __asm__("" : "=r"(selector),"=r"(kind),"=r"(particleOwner),"=r"(mode) : "0"(selector),"1"(kind),"2"(particleOwner),"3"(mode) : "$2","$3","$8");
         height=Controller821F8Field(owner,int*,20);alpha=Controller821F8Field(owner,unsigned char*,79);
         __asm__("" : "=r"(height),"=r"(alpha) : "0"(height),"1"(alpha) : "$8");
         particle=Controller821F8SpawnParticle;
         __asm__("" : "=r"(particle),"=r"(height) : "0"(particle),"1"(height));
         height+=128;height-=alpha;Controller821F8Field(owner,int*,20)=height;
         particle(selector,kind,particleOwner,mode);
         height=Controller821F8Field(owner,int*,20);alpha=Controller821F8Field(owner,unsigned char*,79);
         __asm__ volatile("" : "=r"(height),"=r"(alpha) : "0"(height),"1"(alpha) : "$4","memory");
         temp_a0_3=Controller821F8Field(owner,unsigned char*,79);
         __asm__("" : "=r"(temp_a0_3),"=r"(height),"=r"(alpha) : "0"(temp_a0_3),"1"(height),"2"(alpha));
         height-=128;height+=alpha;Controller821F8Field(owner,int*,20)=height;}
        if ((temp_a0_3 != 0) && ((unsigned int) owner >= (unsigned int) Controller821F8D_8006C704)) {
            Controller821F8Field(owner, unsigned char *, 0x4F) = (unsigned char) *(int*)(Controller821F8D_80065398 + 0xA4 + (Controller821F8D_8006C3EC * 0xC));
        }
        Controller821F8Field(owner, unsigned char *, 0x44) = (unsigned char) *(int*)(Controller821F8AngleTable + 0x9C + (Controller821F8D_8006C3EC * 0xC));
        Controller821F8Field(owner, unsigned char *, 0x45) = (unsigned char) *(int*)(Controller821F8D_80065398 + 0xA0 + (Controller821F8D_8006C3EC * 0xC));
        nextTableIndex = Controller821F8D_8006C3EC + 1;
        Controller821F8D_8006C3EC = nextTableIndex;
        if (nextTableIndex >= 0x40) {
            Controller821F8D_8006C3EC = 0x2F;
        }
        temp_v1_5 = Controller821F8Field(owner, unsigned char *, 0x49);
        switch (temp_v1_5) {
        case 0:
            if(Controller821F8D_8006E48C!=0) goto loadingDone;
            if(Controller821F8CDLoadTime()!=0) goto loadingBusy;
            var_a1=0;
            __asm__("" : "=r"(var_a1) : "0"(var_a1) : "$4");
            var_a0=Controller821F8Field(tag,short*,0);
            Controller821F8func_80039974(var_a0,var_a1,0x3000);
            var_v0_2=1;goto storeLoadingState;
        case 1:
            if(Controller821F8CDLoadTime()!=0) goto loadingBusy;
            DrawSync(0);
            frame.rect[0]=0x380;frame.rect[1]=0x100;frame.rect[2]=0x40;frame.rect[3]=0x60;
            LoadImage((RECT*)&frame.rect[0],Controller821F8D_8006C5B0);
            var_v0_2=2;goto storeLoadingState;
        case 2:
            if(Controller821F8CDLoadTime()!=0) goto loadingBusy;
            var_a1=0x3000;
            __asm__("" : "=r"(var_a1) : "0"(var_a1) : "$4");
            var_a0=Controller821F8Field(tag,short*,0);
            Controller821F8func_80039974(var_a0,var_a1,0);
            var_v0_2=3;goto storeLoadingState;
        case 3:
            if(Controller821F8CDLoadTime()!=0) goto loadingBusy;
            var_a1=500;
            __asm__("" : "=r"(var_a1) : "0"(var_a1) : "$4");
            Controller821F8func_8002AF9C(Controller821F8D_8006C5B0,var_a1,0x80400000);
            var_v0_2=4;
storeLoadingState:
            Controller821F8Field(owner,unsigned char*,73)=var_v0_2;
loadingBusy:
        default:
loadingDone:
            break;
        }
        var_a1=0x10000002;
        {register int flags __asm__("$2")=Controller821F8Field(Controller821F8D_80070328,int*,0x20C);
         __asm__("" : "=r"(flags),"=r"(var_a1) : "0"(flags),"1"(var_a1));
         Controller821F8Field(Controller821F8D_80070328,int*,0x20C)=flags|var_a1;}
        Controller821F8func_800492DC(owner + 0xC,var_a1);
        if ((Controller821F8func_800359A4(tag + 2, 2) != 0) && (Controller821F8Field(owner, unsigned char *, 0x49) == 4)) {
            if (Controller821F8Field(((Controller821F8Field(tag, short *, 0) * 0xC) + Controller821F8D_8006C7A0), unsigned char *, 7) == 0xFF) {
                Controller821F8Field(tag, void **, 8) = 0;
            } else {
                Controller821F8Field(tag, void **, 8) = Controller821F8SpawnMoby(0x1F4, owner);
            }
            if (Controller821F8Field(tag, void **, 8) != 0) {
                Controller821F8SpawnFragments(0xD, 0x1F5, owner, Controller821F8D_80065398, 0, 0x100);
                childForAngle = Controller821F8Field(tag, void **, 8);
                Controller821F8Field(Controller821F8Field(tag, void **, 8), signed char *, 0x46) = Controller821F8func_8004E880(Controller821F8Field(Controller821F8D_80070328, int *, 0) - Controller821F8Field(childForAngle, int *, 0xC), Controller821F8Field(Controller821F8D_80070328, int *, 4) - Controller821F8Field(childForAngle, int *, 0x10), 0);
                Controller821F8D_8006E49C = 0;
                Controller821F8Field(owner, unsigned char *, 0x48) = 4U;
                Controller821F8D_8006C3EC = 0;
                Controller821F8Field(owner, signed char *, 0x4C) = 0;
                Controller821F8Field(owner, signed char *, 0x4D) = 0;
                Controller821F8func_80055D24(Controller821F8Field(tag, void **, 8), 4);
                if (Controller821F8func_8003BFC0(owner, Controller821F8Field(tag, short *, 0x14)) != 0) {
                    Controller821F8func_8003BE70(Controller821F8Field(tag, short *, 0x14));
                }
                Controller821F8Field(tag, short *, 0x14) = -1;
                Controller821F8func_8003BABC(owner, 1, 4);
            } else {
                goto enterStateFive;
            }
        }
        goto sharedTail;
    case 4:                                         /* switch 1 */
        var_a1=0x10000002;
        {register int flags __asm__("$2")=Controller821F8Field(Controller821F8D_80070328,int*,0x20C);
         __asm__("" : "=r"(flags),"=r"(var_a1) : "0"(flags),"1"(var_a1));
         Controller821F8Field(Controller821F8D_80070328,int*,0x20C)=flags|var_a1;}
        Controller821F8func_800492DC(&frame.vector,var_a1);
        if (({register unsigned char *child __asm__("$2")=Controller821F8Field(tag,void**,8);__asm__("" : "=r"(child) : "0"(child) : "$4");Controller821F8Field(child,unsigned char*,66)&2;}) || (Controller821F8D_8006E53C & 0x800)) {
            temp_a0_4 = Controller821F8Field(tag, void **, 8);
            Controller821F8Field(tag, short *, 2) = -0x200;
            if (Controller821F8Field(temp_a0_4, unsigned char *, 0x42) & 2) {
                Controller821F8func_80034F40(temp_a0_4, 1);
            }
            Controller821F8func_8004F178(owner + 0xC, &frame.vector);
            heightOffset=Controller821F8Field(tag,short*,2);
            __asm__("" : "=r"(heightOffset) : "0"(heightOffset) : "$3");
            {register unsigned char *child __asm__("$3")=Controller821F8Field(tag,void**,8);
             __asm__("" : "=r"(child),"=r"(heightOffset) : "0"(child),"1"(heightOffset) : "$4");
             temp_a0_5=Controller821F8Field(owner,int*,20);
             temp_v1_6=Controller821F8Field(child,int*,20);}
            if ((temp_a0_5 + heightOffset) < temp_v1_6) {
                Controller821F8Field(tag, short *, 2) = (short) (temp_v1_6 - temp_a0_5);
            }
            spawnedChild = Controller821F8SpawnMoby(0x171, owner);
            Controller821F8Field(tag, void **, 0x10) = spawnedChild;
            if (spawnedChild != 0) {
                Controller821F8Field(spawnedChild, int *, 0x14) = (int) (Controller821F8Field(spawnedChild, int *, 0x14) + Controller821F8Field(tag, short *, 2));
                Controller821F8Field(Controller821F8Field(tag, void **, 0x10), unsigned char *, 0x4F) = 0xFFU;
            }
            Controller821F8func_8003BABC(owner, 2, 0);
            Controller821F8Field(owner, unsigned char *, 0x48) = 8U;
        }
        goto sharedTail;
    case 9:                                         /* switch 1 */
        if (Controller821F8func_8003BFC0(owner, Controller821F8Field(tag, short *, 0x14)) != 0) {
            Controller821F8func_8003BE70(Controller821F8Field(tag, short *, 0x14));
        }
        Controller821F8Field(tag, short *, 0x14) = -1;
        var_a1=0x10000002;
        {register int flags __asm__("$2")=Controller821F8Field(Controller821F8D_80070328,int*,0x20C);
         __asm__("" : "=r"(flags),"=r"(var_a1) : "0"(flags),"1"(var_a1));
         Controller821F8Field(Controller821F8D_80070328,int*,0x20C)=flags|var_a1;}
        Controller821F8func_800492DC(owner + 0xC,var_a1);
        Controller821F8Field(owner, int *, 0x54) = (int) (((Controller821F8Field(owner, int *, 0x14) + Controller821F8Field(tag, short *, 2)) & 0xFFFFFF) | 0x80000000);
        temp_a0_6 = Controller821F8Field(tag, void **, 0x10);
        if (temp_a0_6 != 0) {
            Controller821F8Field(temp_a0_6, int *, 0x14) = (int) (Controller821F8Field(owner, int *, 0x14) + Controller821F8Field(tag, short *, 2));
        }
        temp_v0_7 = (unsigned short) Controller821F8Field(tag, short *, 2) + (Controller821F8D_8006C648 << 5);
        Controller821F8Field(tag, short *, 2) = temp_v0_7;
        if (temp_v0_7 >= 0x185) {
            temp_a0_7 = Controller821F8Field(tag, void **, 0x10);
            temp_v1_7 = Controller821F8Field(temp_a0_7, unsigned char *, 0x4F);
            if (temp_v1_7 < 0x7FU) {
                Controller821F8Field(temp_a0_7, unsigned char *, 0x4F) = (unsigned char) (temp_v1_7 + (Controller821F8D_8006C648 * 8));
            }
            temp_v1_8 = Controller821F8Field(tag, void **, 0x10);
            if ((unsigned char) Controller821F8Field(temp_v1_8, unsigned char *, 0x4F) >= 0x80U) {
                Controller821F8Field(temp_v1_8, unsigned char *, 0x4F) = 0x7FU;
            }
        } else {
            temp_a0_8 = Controller821F8Field(tag, void **, 0x10);
            temp_v1_9 = Controller821F8Field(temp_a0_8, unsigned char *, 0x4F);
            if (temp_v1_9 >= 0x21U) {
                Controller821F8Field(temp_a0_8, unsigned char *, 0x4F) = (unsigned char) (temp_v1_9 - (Controller821F8D_8006C648 * 8));
            }
            temp_v1_10 = Controller821F8Field(tag, void **, 0x10);
            if ((unsigned int) (Controller821F8Field(temp_v1_10, unsigned char *, 0x4F) - 0x20) >= 0x60U) {
                Controller821F8Field(temp_v1_10, unsigned char *, 0x4F) = 0x20U;
            }
        }
        {register int below __asm__("$2")=Controller821F8Field(tag,short*,2)<769;
         __asm__("" : "=r"(below) : "0"(below));
         if(below) goto sharedTail;
         finishOwner=Controller821F8Field(tag,void**,16);
         goto releaseSecondaryChild;}
    case 8:                                         /* switch 1 */
        if (Controller821F8D_8006C770 != 0) {
            Controller821F8func_80034F40(Controller821F8Field(tag, void **, 8), 1);
        }
        var_a1=0x10000002;
        {register int flags __asm__("$2")=Controller821F8Field(Controller821F8D_80070328,int*,0x20C);
         __asm__("" : "=r"(flags),"=r"(var_a1) : "0"(flags),"1"(var_a1));
         Controller821F8Field(Controller821F8D_80070328,int*,0x20C)=flags|var_a1;}
        Controller821F8func_800492DC(&frame.vector,var_a1);
        Controller821F8func_8004F178(owner + 0xC, &frame.vector);
        Controller821F8Field(Controller821F8Field(tag, void **, 8), int *, 0x54) = (int) (((Controller821F8Field(owner, int *, 0x14) + Controller821F8Field(tag, short *, 2)) & 0xFFFFFF) | 0x80000000);
        temp_a0_9 = Controller821F8Field(tag, void **, 0x10);
        if (temp_a0_9 != 0) {
            Controller821F8Field(temp_a0_9, int *, 0x14) = (int) (Controller821F8Field(owner, int *, 0x14) + Controller821F8Field(tag, short *, 2));
        }
        temp_v0_8 = (unsigned short) Controller821F8Field(tag, short *, 2) + (Controller821F8D_8006C648 << 5);
        Controller821F8Field(tag, short *, 2) = temp_v0_8;
        if (temp_v0_8 >= 0x185) {
            temp_a0_10 = Controller821F8Field(tag, void **, 0x10);
            temp_v1_11 = Controller821F8Field(temp_a0_10, unsigned char *, 0x4F);
            if (temp_v1_11 < 0x7FU) {
                Controller821F8Field(temp_a0_10, unsigned char *, 0x4F) = (unsigned char) (temp_v1_11 + (Controller821F8D_8006C648 * 8));
            }
            temp_v1_12 = Controller821F8Field(tag, void **, 0x10);
            if ((unsigned char) Controller821F8Field(temp_v1_12, unsigned char *, 0x4F) >= 0x80U) {
                Controller821F8Field(temp_v1_12, unsigned char *, 0x4F) = 0x7FU;
            }
        } else {
            temp_a0_11 = Controller821F8Field(tag, void **, 0x10);
            temp_v1_13 = Controller821F8Field(temp_a0_11, unsigned char *, 0x4F);
            if (temp_v1_13 >= 0x21U) {
                Controller821F8Field(temp_a0_11, unsigned char *, 0x4F) = (unsigned char) (temp_v1_13 - (Controller821F8D_8006C648 * 8));
            }
            temp_v1_14 = Controller821F8Field(tag, void **, 0x10);
            if ((unsigned int) (Controller821F8Field(temp_v1_14, unsigned char *, 0x4F) - 0x20) >= 0x60U) {
                Controller821F8Field(temp_v1_14, unsigned char *, 0x4F) = 0x20U;
            }
        }
        if (Controller821F8Field(tag, short *, 2) >= 0x301) {
            Controller821F8func_80055B18(Controller821F8Field(tag, void **, 8));
            finishOwner=Controller821F8Field(tag,void**,16);
            Controller821F8Field(tag, void **, 8) = 0;
releaseSecondaryChild:
            if(finishOwner!=0) {
                Controller821F8func_80055B18(finishOwner);
            }
enterStateFive:
            Controller821F8Field(owner,unsigned char*,72)=5;
        }
        goto sharedTail;
    case 5:                                         /* switch 1 */
        Controller821F8Field(Controller821F8D_80070328, int *, 0x20C) = (int) (Controller821F8Field(Controller821F8D_80070328, int *, 0x20C) | 0x10000002);
        spawnedRecord = Controller821F8SpawnMoby(0x110, owner);
        if (spawnedRecord != 0) {
            Controller821F8Field(spawnedRecord, signed char *, 0x46) = (signed char) (unsigned short) Controller821F8Field(tag, short *, 6);
            Controller821F8Field(Controller821F8Field(spawnedRecord, void **, 0), signed char *, 4) = (signed char) (unsigned short) Controller821F8Field(tag, short *, 6);
        }
        Controller821F8func_80028154(Controller821F8Field(tag, short *, 4));
        {register int index __asm__("$2")=Controller821F8Field(tag,short*,0);
         register int level __asm__("$4")=Controller821F8D_8006C58C;
         register int offset __asm__("$3");
         __asm__("" : "=r"(index),"=r"(level) : "0"(index),"1"(level) : "$3");
         offset=(index<<1)+index;
         __asm__("" : "=r"(offset) : "0"(offset) : "$2");
         index=((level<<3)+level)<<1;offset+=index;
         offset=*(Controller821F8InitialTable+offset);
         __asm__("" : "=r"(offset) : "0"(offset) : "$2");
         scanEnabled=Controller821F8D_8006C5C8;
         Controller821F8D_8006C5F4=0;
         __asm__("" : "=r"(scanEnabled),"=r"(offset) : "0"(scanEnabled),"1"(offset));
         temp_t0=offset&0xF0;}
        if (scanEnabled != 0) {
            register unsigned char *scanOutput __asm__("$9");
            register int expectedKind __asm__("$10");
            var_a2=0;expectedKind=16;
            __asm__("" : "=r"(var_a2),"=r"(expectedKind) : "0"(var_a2),"1"(expectedKind) : "$9","$7");
            scanOutput=Controller821F8D_800716AC;
            __asm__("" : "=r"(scanOutput) : "0"(scanOutput) : "$7");
            var_a3=0;
            do {
                register int value __asm__("$2")=Controller821F8Field(tag,short*,0);
                register int selectedKind __asm__("$3");
                register int level __asm__("$5");
                __asm__("" : "=r"(value) : "0"(value));
                if(var_a2==value) goto advanceScan;
                level=Controller821F8D_8006C58C;
                value=((level<<3)+level)<<1;
                __asm__("" : "=r"(value) : "0"(value));
                value=var_a3+value;
                temp_a0_12=*(Controller821F8D_80066BDC+value);
                __asm__("" : "=r"(temp_a0_12) : "0"(temp_a0_12) : "$3");
                selectedKind=Controller821F8D_8006C5C8;
                value=temp_a0_12&15;
                if(value!=selectedKind) goto advanceScan;
                value=temp_a0_12&240;
                if(value!=expectedKind) goto advanceScan;
                value=((level<<1)+level)<<1;
                value+=(int)scanOutput;
                __asm__("" : "=r"(value) : "0"(value));
                value+=var_a2;
                *(unsigned char*)value=0;
advanceScan:
                var_a2+=1;var_a3+=3;
            } while(var_a2<6);
        }
        {register unsigned char *stateEntry __asm__("$2")=Controller821F8D_800715BC;
         register int level __asm__("$7");
         register int value __asm__("$2");
         __asm__("" : "=r"(stateEntry) : "0"(stateEntry) : "$7");
         level=Controller821F8D_8006C58C;
         __asm__("" : "=r"(level) : "0"(level) : "$5");
         temp_a1_2=Controller821F8Field(tag,short*,0);
         __asm__("" : "=r"(temp_a1_2) : "0"(temp_a1_2) : "$3");
         temp_v1_15=((level<<1)+level)<<1;
         stateEntry=(unsigned char*)((int)temp_v1_15+(int)stateEntry);stateEntry+=temp_a1_2;
         value=*stateEntry;
        if(value==0) {
            var_a2_2=2;
            switch(temp_t0) {
            default:goto classificationReady;
            case 16:
            {register unsigned char *entry __asm__("$4")=Controller821F8D_800716AC;
             __asm__("" : "=r"(entry) : "0"(entry));
             entry=(unsigned char*)((int)temp_v1_15+(int)entry);entry+=temp_a1_2;
             __asm__("" : "=r"(entry) : "0"(entry) : "$3");
             var_v1_4=(temp_a1_2<<1)+temp_a1_2;
             value=level<<3;value+=level;value<<=1;var_v1_4+=value;
             var_a0_2=*entry;
             value=*(Controller821F8D_80066BDD+var_v1_4);
             __asm__ volatile("" : "=r"(value),"=r"(var_a0_2) : "0"(value),"1"(var_a0_2) : "$7");
             value=var_a0_2<value;
             if(!value) goto classifyUpper;
             __asm__ volatile("" : "=r"(value) : "0"(value) : "$7");
             var_a2_2=1;goto classificationReady;}
            case 32:
            value=level<<3;
            {register unsigned char *entry __asm__("$4")=Controller821F8D_800716AC;
             __asm__("" : "=r"(entry) : "0"(entry));
             entry=(unsigned char*)((int)temp_v1_15+(int)entry);entry+=temp_a1_2;
             __asm__("" : "=r"(entry) : "0"(entry) : "$3");
             var_v1_4=(temp_a1_2<<1)+temp_a1_2;
             value+=level;value<<=1;var_v1_4+=value;
             var_a0_2=*entry;
             value=*(Controller821F8D_80066BDD+var_v1_4);
             __asm__ volatile("" : "=r"(value),"=r"(var_a0_2) : "0"(value),"1"(var_a0_2) : "$5");
             value=var_a0_2<value;
             if(!value) goto classifyUpper;
             __asm__ volatile("" : "=r"(value) : "0"(value) : "$5");
             var_a2_2=1;goto classificationReady;}
            }
classifyUpper:
            value=*(Controller821F8D_80066BDE+var_v1_4);
            __asm__ volatile("" : "=r"(value),"=r"(var_a0_2) : "0"(value),"1"(var_a0_2));
            var_a2_2=3;
            if(value<var_a0_2) goto classificationReady;
            var_a2_2=2;
classificationReady:
            if (temp_t0 != 0x30) {
                {register int level __asm__("$3")=Controller821F8D_8006C58C;
                 register unsigned char *base __asm__("$4");
                 register int result __asm__("$2");
                 __asm__("" : "=r"(level) : "0"(level) : "$4");
                 base=Controller821F8D_800715BC;
                 __asm__("" : "=r"(level),"=r"(base) : "0"(level),"1"(base));
                 result=((level<<1)+level)<<1;
                 __asm__("" : "=r"(result) : "0"(result) : "$3");
                 level=Controller821F8Field(tag,short*,0);
                 result+=(int)base;result+=level;*(unsigned char*)result=var_a2_2;}
                if(var_a2_2==1) {
                    value=Controller821F8D_8006C7A8-10;
                    Controller821F8D_8006C7A8=value;
                    value=value<-40;
                    if(!value) goto resetClassificationRecord;
                    value=-40;goto storeClassificationCounter;
                } else if(var_a2_2==2) {
                    register int current __asm__("$3")=Controller821F8D_8006C7A8;
                    __asm__("" : "=r"(current) : "0"(current));
                    if(current>0) {
                        value=Controller821F8Field(tag,short*,0);
                        if(value!=0) {
                            value=current-5;Controller821F8D_8006C7A8=value;
                            __asm__ volatile("" ::: "memory");
                            current=Controller821F8D_8006C7A8;
                        }
                    }
                    if(current>=0) goto resetClassificationRecord;
                    value=Controller821F8Field(tag,short*,0);
                    if(value==0) goto resetClassificationRecord;
                    value=current+5;
storeClassificationCounter:
                    Controller821F8D_8006C7A8=value;
                }
resetClassificationRecord:
                {register int level __asm__("$3")=Controller821F8D_8006C58C;
                 register unsigned char *base __asm__("$4");
                 register int result __asm__("$2");
                 __asm__("" : "=r"(level) : "0"(level) : "$4");
                 base=Controller821F8D_800716AC;
                 __asm__("" : "=r"(level),"=r"(base) : "0"(level),"1"(base));
                 result=((level<<1)+level)<<1;
                 __asm__("" : "=r"(result) : "0"(result) : "$3");
                 level=Controller821F8Field(tag,short*,0);
                 result+=(int)base;result+=level;*(unsigned char*)result=0;}
            }
        }
        }
        Controller821F8D_8006C7B4 |= 1 << Controller821F8Field(tag, short *, 0);
        Controller821F8D_8006C62C |= 1 << Controller821F8Field(tag, short *, 0);
        Controller821F8Field(owner, unsigned char *, 0x48) = 0xAU;
        return;
    case 10:                                        /* switch 1 */
        if (Controller821F8CDLoadTime() == 0) {
            Controller821F8D_8006E49C = 0;
            Controller821F8func_80055B18(owner);
            return;
        }
        break;
    }
    return;
sharedTail:
        if (sharedTailEnabled != 0) {
            if ((distance >= 0x2401) || !({register int condition __asm__("$2")=verticalDistance<2305;__asm__("" : "=r"(condition) : "0"(condition));condition;})) {
                if (Controller821F8Field(owner, unsigned short *, 0x44) != 0) {
                    var_v1 = Controller821F8func_8003613C(Controller821F8Field(owner, unsigned char *, 0x44), 0);
                    if (var_v1 < 0) {
                        var_v1 -= 1;
                    } else if (var_v1 > 0) {
                        var_v1 += 1;
                    }
                    Controller821F8Field(owner, unsigned char *, 0x44) = (unsigned char) (Controller821F8Field(owner, unsigned char *, 0x44) + (var_v1 >> 1));
                    return;
                }
            } else {
                if (distance < 0xC00) {
                    distance = 0xC00;
                }
                temp_v1_3 = Controller821F8Field(tag, unsigned short *, 0xC) + ((int) (0x2400 - distance) >> 6);
                Controller821F8Field(tag, unsigned short *, 0xC) = temp_v1_3;
                var_v1_2 = Controller821F8func_8003613C(Controller821F8Field(owner, unsigned char *, 0x44), (int) (*(unsigned short*)(Controller821F8D_800658A0 + (temp_v1_3 & 0x1FE)) << 0x10) >> 0x18);
                if (var_v1_2 < 0) {
                    var_v1_2 -= 1;
                } else if (var_v1_2 > 0) {
                    var_v1_2 += 1;
                }
                Controller821F8Field(owner, unsigned char *, 0x44) = (unsigned char) (Controller821F8Field(owner, unsigned char *, 0x44) + (var_v1_2 >> 1));
                var_v1_3 = Controller821F8func_8003613C(Controller821F8Field(owner, unsigned char *, 0x45), (int) (*(unsigned short*)(Controller821F8D_80065920 + (Controller821F8Field(tag, unsigned short *, 0xC) & 0x1FE)) << 0x10) >> 0x18);
                if (var_v1_3 < 0) {
                    var_v1_3 -= 1;
                } else if (var_v1_3 > 0) {
                    var_v1_3 += 1;
                }
                Controller821F8Field(owner, unsigned char *, 0x45) = (unsigned char) (Controller821F8Field(owner, unsigned char *, 0x45) + (var_v1_3 >> 1));
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
typedef struct { unsigned char reserved00[6]; signed char offset6; unsigned char count7; } DecodedOrbitParentTag;
typedef struct { Moby* parent; } DecodedOrbitTag;
extern unsigned short DecodedOrbitCos[] __asm__("D_80065920");
extern unsigned short DecodedOrbitSin[] __asm__("D_800658A0");
extern int D_8006C644;
extern unsigned char D_80067555[], D_80067556[];
void func_80055B18(Moby*);
static __inline__ short DecodedOrbitQuotientFive(int packed) { return (packed >> 16) / 5; }
static __inline__ short DecodedOrbitQuotientThree(int packed) { return (packed >> 16) / 3; }
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
        __asm__("" : "=r"(positionX), "=r"(phasePart) : "0"(positionX), "1"(phasePart) : "memory");
        parentY = *(volatile int*)&parent->position.y;
        __asm__("" : "=r"(parentY) : "0"(parentY));
        positionX += phasePart;
        __asm__("" : : "r"(positionX), "r"(parentY));
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
    moby->position.z = tag->parent->position.z
        + ((DecodedOrbitParentTag*)tag->parent->mobyTag)->offset6 * 16
        + D_80067556[moby->substate * 4];
    {
        int sample = *(short*)((char*)D_80065920 + ((moby->substate + step) * 8 & 0x1F8));
        __asm__("" : "=r"(phase) : "0"(phase), "r"(sample));
        phase += 0x80;
        __asm__("" : : "r"(phase));
        moby->angle.yaw = phase + ((sample * 3) >> 9);
    }
    if (moby->animationState.id == 0)
        ((DecodedOrbitParentTag*)tag->parent->mobyTag)->count7--;
}
