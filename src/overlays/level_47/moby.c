#include "common.h"
#include "spu.h"
#include "spyro.h"
#include "ovl_header.h"
#include "stdutil.h"
#include "moby/mobytag.h"
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
void func_level_47_80074D7C(Moby* argument) {
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
void func_level_47_80075408(void *input) {
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
void func_level_47_80076958(Moby* moby) {
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
void func_level_47_80076A94(Moby* moby) {
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
void func_level_47_80076B50(Moby* moby) {
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
void func_level_47_80076C04(Moby *moby) {
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
void func_level_47_80076F08(void *input) {
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


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 original
 * 80077A7C,360 instructions, sibling4619. Raw units/helper meanings and
 * cadence unresolved; uninstalled until exact native instructions match. */
#define P47F(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int P47H4F178() __asm__("func_8004F178");
int P47H359A4() __asm__("func_800359A4");
int P47H1BA30() __asm__("func_8001BA30");
int P47H4E880() __asm__("func_8004E880");
int P47H360F8() __asm__("func_800360F8");
int P47H1830C() __asm__("func_8001830C");
int P47H19138() __asm__("func_80019138");
int P47H4F168() __asm__("func_8004F168");
int P47H1A358() __asm__("func_8001A358");
int P47H5629C() __asm__("func_8005629C");
int P47H55D24() __asm__("func_80055D24");
int P47H1C288() __asm__("func_8001C288");
int P47H3BABC() __asm__("func_8003BABC");
int P47H4EA90() __asm__("func_8004EA90");
int P47H4ED6C() __asm__("func_8004ED6C");
int P47H4F0E8() __asm__("func_8004F0E8");
int P47H4F194() __asm__("func_8004F194");
int P47H55B18() __asm__("func_80055B18");
int P47Rand() __asm__("rand");
extern int P47Tick __asm__("D_8006C640");
extern int P47Gate __asm__("D_8006C54C");
extern int P47Flag0 __asm__("D_8006580C");
extern int P47Flag1 __asm__("D_80065834");
extern void* (*P47Spawn)() __asm__("SpawnMoby");
extern void* (*P47Particle)() __asm__("SpawnParticle");
void func_level_47_80077A7C(void* input){
 struct {int old[4],zero[4],vector[4],position[4],matrix[6];signed char angles[8];} frame;
 register unsigned char* owner __asm__("$17")=input;
 register unsigned char* tag __asm__("$19");
 register int x __asm__("$6");register int y __asm__("$5");register int z __asm__("$4");
 register int maximum __asm__("$3");register int work2 __asm__("$2");register int work3 __asm__("$3");
 register int heading16 __asm__("$16");register unsigned char* target18 __asm__("$18");
 register unsigned char* child16 __asm__("$16");register void* position18 __asm__("$18");
 register void* vector18 __asm__("$18");register void* point16 __asm__("$16");
 register void* matrix21 __asm__("$21");register int index20 __asm__("$20");
 register unsigned char* extra3 __asm__("$3");
 register void* call4 __asm__("$4");register int call5 __asm__("$5");
 register void* call6 __asm__("$6");register void* call7 __asm__("$7");
 __asm__("" : "=r"(owner):"0"(owner));
 x=P47F(owner,int*,12);tag=P47F(owner,unsigned char**,0);
 if(x<1024)goto cleanup;
 y=P47F(owner,int*,16);if(y<1024)goto cleanup;
 z=P47F(owner,int*,20);if(z<1024)goto cleanup;
 maximum=256000;__asm__("" : "=r"(maximum):"0"(maximum));
 work2=x>maximum;__asm__("" : "=r"(work2):"0"(work2));if(work2)goto cleanup;
 work2=y>maximum;__asm__("" : "=r"(work2):"0"(work2));if(work2)goto cleanup;
 work2=z>maximum;__asm__("" : "=r"(work2):"0"(work2));if(work2)goto cleanup;
 P47H4F178(frame.old,owner+12);
 P47F(owner,int*,12)+=P47F(tag,int*,0);
 P47F(owner,int*,16)+=P47F(tag,int*,4);
 P47F(owner,int*,20)+=P47F(tag,int*,8);
 work3=P47F(tag,short*,12);work2=P47F(tag,int*,8);call4=(void*)P47Tick;
 work2+=work3;P47F(tag,int*,8)=work2;
 if(call4 && !P47Gate){P47Flag0=1;P47Flag1=1;}
 switch(owner[72]){
 case 0:goto moving;
 case 98:goto impact;
 case 99:goto particles;
 default:goto done;
 }
 moving:
 owner[68]+=4;P47H359A4(tag+14,2);
 if(!tag[18]){target18=0;goto timer;}
 {
  target18=P47H1BA30(owner+12,512,1,0,0x10170000,owner);
  if(target18){
   work2=P47H4E880(P47F(target18,int*,12)-P47F(owner,int*,12),P47F(target18,int*,16)-P47F(owner,int*,16),0);
   {register int zero6 __asm__("$6")=0;
    __asm__("" : "=r"(zero6):"0"(zero6),"r"(work2));heading16=work2;
    work2=P47H4E880(P47F(tag,int*,0),P47F(tag,int*,4),zero6);}
   target18[81]=P47H360F8(heading16,work2,32,64);
  }
 }
 timer:
 if(P47H359A4(tag+16,2))goto collision;
 call4=frame.old;if(target18)goto collision;
 __asm__("" : "=r"(call4):"0"(call4):"$18");position18=owner+12;
 work2=P47H1830C(call4,position18,0,0,P47F(tag,int*,20));call4=position18;
 if(work2)goto collision;
 __asm__("" ::: "$2");
 if(!P47H19138(call4,256,0,0,0,P47F(tag,int*,20)))goto no_collision;
 collision:
 work2=P47F(tag,short*,14);
 __asm__("" : "=r"(work2):"0"(work2));call4=owner+12;
 if(!work2){
  __asm__("" ::: "$2");
  P47F(tag,int*,0)=0;P47F(tag,int*,4)=0;P47F(tag,int*,8)=0;
  P47H4F178(call4,frame.old);owner[72]=98;goto feedback;
 }
 goto feedback_prepared;
 no_collision:
 if(P47Tick&1){point16=frame.zero;P47H4F168(point16);P47Particle(1,49,position18,point16);}
 feedback:
 call4=owner+12;
 feedback_prepared:
 P47H1A358(call4,8192);P47H5629C(owner);P47H55D24(owner,2);goto done;
 impact:
 position18=owner+12;
 if(tag[18]){
  child16=P47H1BA30(position18,1024,1,0,0x10170000,owner);
  if(child16)child16[81]=P47H4E880(P47F(child16,int*,12)-P47F(owner,int*,12),P47F(child16,int*,16)-P47F(owner,int*,16),0);
  P47H19138(position18,1024,0,0,0x10040000,owner);
 }
 if(tag[19])P47H1C288(owner+12,1024,7);
 P47H3BABC(owner,0,0);P47F(tag,short*,16)=0;
 work2=P47F(owner,int*,20);work3=99;work2-=15360;work2=work2<1024;owner[72]=work3;
 if(work2){extra3=P47Spawn(156,owner);if(extra3)P47F(extra3,int*,20)=15360;}
 particles:
 index20=0;matrix21=frame.matrix;vector18=frame.vector;point16=frame.position;
 do{
  frame.angles[0]=0;frame.angles[1]=P47Rand();frame.angles[2]=P47Rand();
  P47H4EA90(frame.angles,matrix21,0);
  index20++;work2=P47Rand();
  __asm__ volatile("" : "=r"(work2):"0"(work2):"$4","$5","$6");
  call4=matrix21;call5=(int)vector18;call6=vector18;
  __asm__ volatile("" : "=r"(call4),"=r"(call5),"=r"(call6),"=r"(work2):"0"(call4),"1"(call5),"2"(call6),"3"(work2):"memory");
  work2=(work2&31)+48;frame.vector[0]=work2;frame.vector[1]=0;frame.vector[2]=0;
  P47H4ED6C(call4,(void*)call5,call6);
  P47H4F178(point16,vector18);P47H4F0E8(point16,2);
  __asm__("" : "=r"(owner):"0"(owner));P47H4F194(point16,point16,owner+12);
  P47Particle(1,13,point16,vector18);
  __asm__("" : "=r"(owner):"0"(owner));
 }while(index20<4);
 P47Particle(8,70,owner+12,(void*)16);
 work2=P47F(owner,int*,20)-15360;if(work2<1024)goto counter;
 child16=P47Spawn(326,owner);
 if(child16){
  child16[71]=4;owner[76]=64;owner[78]=64;
  if(P47F(tag,short*,16)){
   frame.angles[0]=0;frame.angles[1]=P47Rand();frame.angles[2]=P47Rand();
   P47H4EA90(frame.angles,matrix21,0);work2=P47Rand();
   __asm__ volatile("" : "=r"(work2):"0"(work2):"$4","$5","$6");
   call4=matrix21;call5=(int)vector18;call6=vector18;
   __asm__ volatile("" : "=r"(call4),"=r"(call5),"=r"(call6),"=r"(work2):"0"(call4),"1"(call5),"2"(call6),"3"(work2):"memory");
   work2&=255;__asm__("" : "=r"(work2):"0"(work2));work2+=256;frame.vector[0]=work2;frame.vector[1]=0;frame.vector[2]=0;
   P47H4ED6C(call4,(void*)call5,call6);P47H4F194(child16+12,child16+12,vector18);
  }
 }
 counter:
 work2=P47F(tag,unsigned short*,16)+1;P47F(tag,short*,16)=work2;
 if((short)work2<5)goto done;
 cleanup:P47H55B18(owner);
 done:__asm__ volatile("" ::: "memory");
}
#undef P47F


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
extern void* (*DecodedProximityParticle)(int,int,Moby*,void*) __asm__("SpawnParticle");
int func_8004F334(Vector3D*,Vector3D*);
/* SCUS-94467 USA Rev0 0x8007801C..0x80078514,319 original words.
 * Reuses verified func_level_11_8007B388. This original variant gates on
 * global player+244 only and shares the animation19 completion branch.
 * Raw selector/state/tag widths, helper order and numeric IDs remain retail.
 * Units, complete producer/helper semantics and caller cadence remain open.
 * Empty constraints preserve compiler lifetimes without instructions.
 * AI generated; not human reviewed. See batch2026-10-05-1618.
 */
void func_level_47_8007801C(Moby* argument) {
    Vector3D difference;
    int kind;
    register Moby* moby __asm__("$17") = argument;
    register DecodedProximityTag* tag __asm__("$18");
    register Vector3D* position __asm__("$19");
    register int two __asm__("$20");
    register int* disabledArgument __asm__("$5") = (int*)(DecodedProximityPlayer + 0x244);
    register int distance __asm__("$21");
    register Vector3D* playerPosition __asm__("$22");
    __asm__("" : "=r"(moby) : "0"(moby));
    __asm__("" : "=r"(disabledArgument) : "0"(disabledArgument));
    tag = moby->mobyTag;
    if (*disabledArgument) {
        if (moby->state) moby->state = 2;
        return;
    }
    two = 2;
    if (moby->state == two) moby->state = 1;
    playerPosition = (Vector3D*)((char*)disabledArgument - 0x244);
    kind = tag->selector & 0x7F;
    position = &moby->position;
    func_8004F1C8(&difference, playerPosition, position);
    distance = func_8004EDE8(&difference, 0);
    /* Shared state transitions preserve the original dispatch/jump structure. */
    if (!kind) goto activate;
    {
        register int one __asm__("$4") = 1;
        register int substate __asm__("$3");
        register int condition __asm__("$2");
        __asm__("" : "=r"(one) : "0"(one));
        if (kind == one) {
            substate = moby->substate;
            if (substate == kind) goto kindOneWaiting;
            if (substate < 2) {
                if (!substate) goto kindOneInitial;
                goto update;
            }
            if (substate == two) goto kindOneActive;
            if (substate == 3) goto kindOneFinished;
            goto update;
        kindOneInitial:
            if (distance < tag->radialLimit + 0x400 && ABS(difference.z) < 0x400) {
                tag->timer = 60;
                moby->substate = 1;
            }
            goto update;
        kindOneWaiting:
            if (!func_800359A4(&tag->timer, 4)) goto update;
            goto secondSubstate;
        kindOneActive:
            if (DecodedProximityAnimation != 19) goto update;
            goto thirdSubstate;
        kindOneFinished:
            if (DecodedProximityAnimation != 19 && func_800359A4(&tag->timer, 4)) {
                moby->substate = 0;
                moby->state = 0;
            }
            goto update;
        } else if (kind == 3) {
            substate = moby->substate;
            if (substate == one) goto kindThreeWaiting;
            if (substate < 2) {
                if (!substate) goto kindThreeInitial;
                goto update;
            }
            if (substate == two) goto kindThreeActive;
            if (substate == kind) goto kindThreeFinished;
            goto update;
        kindThreeInitial:
            if (distance <= tag->radialLimit + 0x800 || distance >= 0x2000) goto update;
            condition = ABS(difference.z) < 0x400;
            goto checkSecond;
        kindThreeWaiting:
            condition = distance > tag->radialLimit + 0x800;
        checkSecond:
            if (!condition) goto update;
        timedSecond:
            tag->timer = 60;
        secondSubstate:
            moby->substate = 2;
        activate:
            moby->state = 1;
            goto update;
        kindThreeActive:
            if (DecodedProximityAnimation != 19 && distance <= 0x2800 && DecodedProximityZ - moby->position.z <= 0xC00) goto update;
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
            if (func_8004F334(position, playerPosition) > 0x800 && D_8006C640 > 0) goto clearKind;
        }
    } else if (kind == 5) {
        if (tag->linkedIndex != -1 && D_8006C550[tag->linkedIndex].state >= 0x80) goto clearKind;
    }
    goto update;
clearKind:
    tag->selector &= 0x80;
update:
    /* Active/inactive sound-handle paths and both callbacks retain retail order. */
    __asm__("" : : "r"(two));
    if (moby->state) {
        if (!func_8003BFC0(moby, tag->soundHandle)) tag->soundHandle = PlaySound(DecodedProximitySounds[0x1D], moby, 4);
        if (!(D_8006C640 & 1)) DecodedProximityParticle(1, 6, moby, 0);
        DecodedProximityParticle(1, 0x52, moby, 0);
        if (DecodedProximityAnimation != 19 && distance < tag->radialLimit && !D_8006E344
            && difference.z >= -0x3FF && difference.z < tag->verticalLimit
            && DecodedProximityZ + 0xC00 < moby->position.z + tag->verticalLimit) {
            DecodedProximityRequest = 0x10000020;
            DecodedProximityOwner = moby;
            __asm__("" : : "r"(tag), "r"(distance));
        }
    } else {
        if (func_8003BFC0(moby, tag->soundHandle)) {
            func_8003BE70(tag->soundHandle);
            tag->soundHandle = -1;
        }
    }
}

void func_8001C288(Vector3D*, int, int);
void func_80055B18(Moby*);
extern int D_8006C770;
void func_level_47_80078518(Moby* moby) {
    func_8001C288(&moby->position, 0x800, 7);
    if (D_8006C770) func_80055B18(moby);
}

void func_80039714(Moby*);
void func_level_47_80078568(Moby* moby) {
    if (moby->animationState.id != 0) func_80039714(moby);
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
void func_level_47_80078598(void *input) {
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


typedef struct { int radius; Moby* parent; } DecodedExpandingCollisionTag;
extern int D_8006C648, D_8006C770, D_80071924;
extern int** DecodedExpandingCollisionLinks __asm__("D_8006D048 + 0x14");
extern int DecodedExpandingPlayerRadius __asm__("D_80070328 + 0x44");
extern int DecodedExpandingPlayerHeading __asm__("D_80070328 + 0x298");
Moby* DecodedExpandingMobyQuery(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int DecodedExpandingPlayerQuery(Vector3D*,int,int) __asm__("func_8001C288");
int DecodedExpandingLinkQuery(Vector3D*,int,int,int,int,Moby*) __asm__("func_80019138");
int func_80040954(int);
void func_level_47_800796EC(Moby* moby) {
    DecodedExpandingCollisionTag* tag;
    register int cadence __asm__("$3") = D_8006C648;
    register Vector3D* position __asm__("$4");
    register int radius __asm__("$5");
    register int expansion __asm__("$2");
    register int flags __asm__("$18");
    register int* linkIndex __asm__("$16");
    Moby* target;
    __asm__("" : "=r"(cadence) : "0"(cadence));
    position = &moby->position;
    __asm__("" : "=r"(position) : "0"(position), "r"(cadence));
    tag = moby->mobyTag;
    __asm__("" : "=r"(cadence) : "0"(cadence), "r"(tag));
    expansion = cadence * 5;
    radius = tag->radius;
    __asm__("" : "=r"(radius), "=r"(expansion) : "0"(radius), "1"(expansion));
    expansion *= 4;
    radius += expansion;
    tag->radius = radius;
    __asm__("" : "=r"(radius) : "0"(radius) : "memory");
    if (DecodedExpandingPlayerQuery(position, radius - DecodedExpandingPlayerRadius, 7)) {
        DecodedExpandingPlayerHeading = func_8004E880(spyro.position.x - moby->position.x, spyro.position.y - moby->position.y, 0);
        if (DecodedExpandingPlayerHeading <= 0) DecodedExpandingPlayerHeading = 1;
    }
    target = DecodedExpandingMobyQuery(&moby->position, tag->radius, 0, 0, 0x950000, moby);
    if (target) {
        target->unkb = func_8004E880(target->position.x - moby->position.x, target->position.y - moby->position.y, 0);
        if (!target->unkb) target->unkb = 1;
    }
    flags = 0x950000;
    if (DecodedExpandingLinkQuery(&moby->position, tag->radius - DecodedExpandingPlayerRadius, 2, 0, flags, moby)) {
        linkIndex = &D_80071924;
        __asm__("" : "=r"(linkIndex) : "0"(linkIndex));
        if (func_80040954(*linkIndex) == 3) DecodedExpandingCollisionLinks[*linkIndex & 0x3F][1] |= flags;
    }
    if (D_8006C770) func_80055B18(moby);
}

void func_level_47_800798A4(Moby* moby) {
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
void func_level_47_800798C4(Moby* argument) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0; AI generated, not human reviewed; uninstalled. */
#define Level47_79AC4Keep(v) __asm__("" : "=r"(v) : "0"(v))
#define Level47_79AC4Field(p, t, o) (*(t)((unsigned char *)(p) + (o)))
int Level47_79AC4_ActivateSparxPowers() __asm__("ActivateSparxPowers");
int Level47_79AC4_func_80034F40() __asm__("func_80034F40");
int Level47_79AC4_func_8003585C() __asm__("func_8003585C");
int Level47_79AC4_func_800359A4() __asm__("func_800359A4");
int Level47_79AC4_func_80035EE0() __asm__("func_80035EE0");
int Level47_79AC4_func_8003613C() __asm__("func_8003613C");
int Level47_79AC4_func_8003645C() __asm__("func_8003645C");
int Level47_79AC4_func_80037BBC() __asm__("func_80037BBC");
int Level47_79AC4_func_8003B7B4() __asm__("func_8003B7B4");
int Level47_79AC4_func_8004E790() __asm__("func_8004E790");
int Level47_79AC4_func_8004E880() __asm__("func_8004E880");
int Level47_79AC4_func_8004F194() __asm__("func_8004F194");
int Level47_79AC4_func_8004F264() __asm__("func_8004F264");
int Level47_79AC4_func_8004F334() __asm__("func_8004F334");
int Level47_79AC4_func_800512E4() __asm__("func_800512E4");
int Level47_79AC4_func_80055B18() __asm__("func_80055B18");
int Level47_79AC4_func_800584BC() __asm__("func_800584BC");
int Level47_79AC4_rand() __asm__("rand");
extern int Level47_79AC4_D_800658A0 __asm__("D_800658A0");
extern int Level47_79AC4_D_80065920 __asm__("D_80065920");
extern int Level47_79AC4_D_80066EAE __asm__("D_80066EAE");
extern int Level47_79AC4_D_80066EEC __asm__("D_80066EEC");
extern int Level47_79AC4_D_8006C408 __asm__("D_8006C408");
extern int Level47_79AC4_D_8006C40B __asm__("D_8006C40B");
extern int Level47_79AC4_D_8006C550 __asm__("D_8006C550");
extern int Level47_79AC4_D_8006C598 __asm__("D_8006C598");
extern int Level47_79AC4_D_8006C660 __asm__("D_8006C660");
extern int Level47_79AC4_D_8006C71C __asm__("D_8006C71C");
extern int Level47_79AC4_D_8006C770 __asm__("D_8006C770");
extern int Level47_79AC4_D_8006C7C4 __asm__("D_8006C7C4");
extern int Level47_79AC4_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level47_79AC4_D_8006D088 __asm__("D_8006D088");
extern int Level47_79AC4_D_8006E344 __asm__("D_8006E344");
extern int Level47_79AC4_D_80070300 __asm__("D_80070300");
extern int Level47_79AC4_D_80070328 __asm__("D_80070328");
extern int Level47_79AC4_D_8007145C __asm__("D_8007145C");
extern int Level47_79AC4_D_8007158F __asm__("D_8007158F");
extern int Level47_79AC4_D_80071A10 __asm__("D_80071A10");
extern int Level47_79AC4_D_80071AB0 __asm__("D_80071AB0");
extern int Level47_79AC4_D_80071FB0 __asm__("D_80071FB0");
extern int Level47_79AC4_D_800722B8 __asm__("D_800722B8");
extern int Level47_79AC4_SpawnMoby __asm__("SpawnMoby");
extern int Level47_79AC4_func_8002AB38 __asm__("func_8002AB38");
extern int Level47_79AC4_func_8002AE00 __asm__("func_8002AE00");
extern int Level47_79AC4_speedwayRecords __asm__("speedwayRecords");
extern int Level47_79AC4_unk_ovlheader_80074460 __asm__("unk_ovlheader_80074460");
void func_level_47_80079AC4(void *ownerInput) {
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
    register int privateState __asm__("$19");
    register int owner __asm__("$20");
    register int saved21 __asm__("$21");
    register int saved22 __asm__("$22");
    register int saved23 __asm__("$23");
    register int temporary24 __asm__("$24");
    register int temporary25 __asm__("$25");
    int nearestDistance, stackArgument4, stackArgument5, remainingScans;
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
    } locals;
    __asm__("" : "=m"(locals.sp90));
    owner = (int)ownerInput;
    Level47_79AC4Keep(owner);
    argument0 = (int)ownerInput;
    Level47_79AC4Field(&locals.sp18, volatile int *, 32) = 0;
    Level47_79AC4Field(&locals.sp18, volatile int *, 40) = 0;
    Level47_79AC4Field(&locals.sp18, volatile int *, 48) = 0;
    Level47_79AC4Field(&locals.sp18, volatile int *, 56) = 0;
    privateState = Level47_79AC4Field(owner, int *, 0);
    Level47_79AC4Keep(privateState);
    saved21 = 0 + -1;
    Level47_79AC4Keep(saved21);
    Level47_79AC4Field(&locals.sp18, volatile int *, 64) = 0;
    temporary3 = Level47_79AC4Field(privateState, int *, 116);
    Level47_79AC4Keep(temporary3);
    saved23 = 0 + -1;
    Level47_79AC4Keep(saved23);
    Level47_79AC4Field(&locals.sp18, volatile int *, 72) = 0;
    __asm__ volatile("" : "=r"(saved23) : "0"(saved23) : "memory");
    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level47_79AC4Keep(temporary3);
    temporary3 = Level47_79AC4Field(temporary3, int *, -15024);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(temporary2);
    temporary8 = 0 + -1;
    Level47_79AC4Keep(temporary8);
    Level47_79AC4Field(&locals.sp18, volatile int *, 80) = temporary8;
    Level47_79AC4Field(&locals.sp18, volatile int *, 24) = temporary2;
    temporary2 = Level47_79AC4Field(temporary2, int *, 52);
    Level47_79AC4Keep(temporary2);
    temporary8 = 0 + 1;
    Level47_79AC4Keep(temporary8);
    Level47_79AC4Field(&locals.sp18, int *, 96) = temporary8;
    if (temporary2 == 0)
        goto original1481_818;
    temporary2 = 0 + 2;
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level47_79AC4Keep(temporary3);
    temporary3 = Level47_79AC4Field(temporary3, int *, -14396);
    Level47_79AC4Keep(temporary3);
    saved16 = (int)0x80070000U;
    Level47_79AC4Keep(saved16);
    saved16 = Level47_79AC4Field(saved16, unsigned char *, -15349);
    Level47_79AC4Keep(saved16);
    if (temporary3 != temporary2)
        goto original1481_50;
    saved16 = saved16 + -1;
    Level47_79AC4Keep(saved16);
    if (saved16 >= 0)
        goto original1481_59;
    saved16 = 0 + 0;
    goto original1481_59;
original1481_50:
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 96);
    Level47_79AC4Keep(temporary8);

    if (temporary3 != temporary8)
        goto original1481_56;
    saved16 = saved16 + 3;
    goto original1481_59;
original1481_56:
    if (temporary3 != 0)
        goto original1481_59;
    saved16 = saved16 + 5;
    Level47_79AC4Keep(saved16);
original1481_59:
    saved17 = (int)&Level47_79AC4_D_8007158F;
    Level47_79AC4Keep(saved17);
    temporary2 = Level47_79AC4Field(saved17, unsigned char *, 0);
    Level47_79AC4Keep(temporary2);

    if (temporary2 == 0)
        goto original1481_66;
    saved16 = 0 + 0;
    Level47_79AC4Keep(saved16);
original1481_66:
    temporary2 = Level47_79AC4Field(privateState, int *, 120);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0)
        goto original1481_73;
    temporary2 = (int)&Level47_79AC4_func_8002AB38;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(privateState, int *, 120) = temporary2;
original1481_73:
    temporary3 = Level47_79AC4Field(privateState, int *, 120);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)&Level47_79AC4_func_8002AE00;
    Level47_79AC4Keep(temporary2);
    temporary2 = (unsigned int)temporary3 < (unsigned int)temporary2;
    Level47_79AC4Keep(temporary2);
    if (temporary2 == 0 ? (argument0 = 0 + 0, 1) : (argument0 = 0 + 0, 0))
        goto original1481_103;
    argument1 = (int)0x80050000U;
    Level47_79AC4Keep(argument1);
    temporary2 = Level47_79AC4Field(temporary3, unsigned char *, 0);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(privateState, int *, 124);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 24);
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary3 ^ temporary2;
    Level47_79AC4Keep(temporary3);
    Level47_79AC4Field(privateState, int *, 124) = temporary3;
original1481_85:
    temporary2 = Level47_79AC4Field(privateState, int *, 124);
    Level47_79AC4Keep(temporary2);

    if (temporary2 >= 0)
        goto original1481_92;
    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 ^ argument1;
    goto original1481_93;
original1481_92:
    temporary2 = (int)((unsigned int)temporary2 << 1);
    Level47_79AC4Keep(temporary2);
original1481_93:
    Level47_79AC4Field(privateState, int *, 124) = temporary2;
    argument0 = argument0 + 1;
    Level47_79AC4Keep(argument0);
    temporary2 = argument0 < 8;
    Level47_79AC4Keep(temporary2);
    if (temporary2 != 0)
        goto original1481_85;
    temporary2 = Level47_79AC4Field(privateState, int *, 120);
    Level47_79AC4Keep(temporary2);

    temporary2 = temporary2 + 1;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(privateState, int *, 120) = temporary2;
    goto original1481_188;
original1481_103:
    argument1 = (int)0x000F0000U;
    Level47_79AC4Keep(argument1);
    argument1 = argument1 | 65520;
    Level47_79AC4Keep(argument1);
    argument0 = (int)0xFFF00000U;
    Level47_79AC4Keep(argument0);
    argument0 = argument0 | 15;
    Level47_79AC4Keep(argument0);
    temporary2 = Level47_79AC4Field(privateState, int *, 124);
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level47_79AC4Keep(temporary3);
    temporary3 = Level47_79AC4Field(temporary3, int *, 8888);
    Level47_79AC4Keep(temporary3);
    temporary2 = (temporary2 >> 12);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 & argument1;
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary3 & argument0;
    Level47_79AC4Keep(temporary3);
    argument0 = (int)0x80070000U;
    Level47_79AC4Keep(argument0);
    argument0 = Level47_79AC4Field(argument0, int *, 17504);
    Level47_79AC4Keep(argument0);
    temporary2 = temporary2 | temporary3;
    Level47_79AC4Keep(temporary2);
    if (temporary2 == argument0)
        goto original1481_188;
    argument0 = (int)&Level47_79AC4_D_80070300;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 0;
    Level47_79AC4Keep(argument1);

    Level47_79AC4Field((int)&Level47_79AC4_D_8006C660, int *, 0) = 0;
    argument2 = 0 + 40;
    Level47_79AC4_func_8004E790(argument0, argument1, argument2);
    argument0 = (int)&Level47_79AC4_D_80071A10;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 0;
    Level47_79AC4Keep(argument1);

    Level47_79AC4Field((int)&Level47_79AC4_D_8006C71C, int *, 0) = 0;
    argument2 = 0 + 160;
    Level47_79AC4_func_8004E790(argument0, argument1, argument2);
    argument0 = (int)&Level47_79AC4_D_80071AB0;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 0;
    Level47_79AC4Keep(argument1);
    argument2 = 0 + 1280;
    Level47_79AC4_func_8004E790(argument0, argument1, argument2);
    argument0 = (int)&Level47_79AC4_D_80071FB0;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 0;
    Level47_79AC4Keep(argument1);
    argument2 = 0 + 40;
    Level47_79AC4_func_8004E790(argument0, argument1, argument2);
    argument0 = saved17 + -31;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 0;
    Level47_79AC4Keep(argument1);
    argument2 = 0 + 76;
    Level47_79AC4_func_8004E790(argument0, argument1, argument2);
    argument0 = (int)&Level47_79AC4_D_8007145C;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 0;
    Level47_79AC4Keep(argument1);
    argument2 = 0 + 40;
    Level47_79AC4_func_8004E790(argument0, argument1, argument2);
    argument0 = (int)&Level47_79AC4_D_8006C408;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 0;
    Level47_79AC4Keep(argument1);
    argument2 = 0 + 8;
    Level47_79AC4_func_8004E790(argument0, argument1, argument2);
    argument0 = (int)&Level47_79AC4_D_80066EEC;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 0;
    Level47_79AC4Keep(argument1);
    argument2 = 0 + 32;
    Level47_79AC4_func_8004E790(argument0, argument1, argument2);
    temporary2 = 0 + 44;
    Level47_79AC4Keep(temporary2);
original1481_162:

    Level47_79AC4Field(((int)&Level47_79AC4_D_80066EAE + temporary2), short *, 0) = 0;
    temporary2 = temporary2 + -4;
    Level47_79AC4Keep(temporary2);
    if (temporary2 >= 0 ? (argument0 = 0 + 0, 1) : (argument0 = 0 + 0, 0))
        goto original1481_162;
    argument1 = 0 | 36000;
    Level47_79AC4Keep(argument1);
    temporary3 = 0 + 0;
    Level47_79AC4Keep(temporary3);
original1481_170:

    Level47_79AC4Field(((int)&Level47_79AC4_speedwayRecords + 16 + temporary3), int *, 0) = 0;

    Level47_79AC4Field(((int)&Level47_79AC4_speedwayRecords + 20 + temporary3), int *, 0) =
        argument1;

    Level47_79AC4Field(((int)&Level47_79AC4_speedwayRecords + 28 + temporary3), int *, 0) = 0;
    __asm__ volatile("" : "=r"(argument0) : "0"(argument0) : "memory");
    argument0 = argument0 + 1;
    Level47_79AC4Keep(argument0);
    temporary2 = argument0 < 4;
    Level47_79AC4Keep(temporary2);
    if (temporary2 != 0 ? (temporary3 = temporary3 + 44, 1) : (temporary3 = temporary3 + 44, 0))
        goto original1481_170;

    Level47_79AC4_ActivateSparxPowers(argument0, argument1);
    argument0 = 0 + 0;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 10;
    Level47_79AC4_func_800584BC(argument0, argument1);
original1481_188:
    temporary3 = Level47_79AC4Field(privateState, int *, 116);
    Level47_79AC4Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level47_79AC4Keep(temporary3);
    temporary3 = Level47_79AC4Field(temporary3, int *, -15024);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary2, unsigned char *, 72);
    Level47_79AC4Keep(temporary3);
    temporary2 = 0 + 25;
    Level47_79AC4Keep(temporary2);
    if (temporary3 != temporary2 ? (temporary2 = 0 + 9, 1) : (temporary2 = 0 + 9, 0))
        goto original1481_210;
    temporary3 = Level47_79AC4Field(owner, unsigned char *, 72);
    Level47_79AC4Keep(temporary3);

    if (temporary3 == temporary2 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1481_214;
    argument1 = 0 + 0;
    Level47_79AC4_func_80034F40(argument0, argument1);
    temporary2 = 0 + 9;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(owner, unsigned char *, 72) = temporary2;
original1481_210:
    temporary3 = Level47_79AC4Field(owner, unsigned char *, 72);
    Level47_79AC4Keep(temporary3);
    temporary2 = 0 + 9;
    Level47_79AC4Keep(temporary2);
    if (temporary3 != temporary2 ? (saved17 = 0 + 0, 1) : (saved17 = 0 + 0, 0))
        goto original1481_238;
original1481_214:
    saved17 = 0 + 0;
    Level47_79AC4Keep(saved17);
    saved16 = privateState + 0;
    Level47_79AC4Keep(saved16);
original1481_216:
    temporary2 = Level47_79AC4Field(saved16, int *, 100);
    Level47_79AC4Keep(temporary2);

    if (temporary2 == 0)
        goto original1481_232;
    temporary2 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(temporary2);

    argument0 = Level47_79AC4Field(temporary2, int *, 4);
    Level47_79AC4Keep(argument0);

    if (argument0 == 0)
        goto original1481_228;

    Level47_79AC4_func_80055B18(argument0);
original1481_228:
    argument0 = Level47_79AC4Field(saved16, int *, 100);
    Level47_79AC4Keep(argument0);

    Level47_79AC4_func_80055B18(argument0);
    Level47_79AC4Field(saved16, int *, 100) = 0;
original1481_232:
    saved17 = saved17 + 1;
    Level47_79AC4Keep(saved17);
    temporary2 = saved17 < 3;
    Level47_79AC4Keep(temporary2);
    saved16 = saved16 + 4;
    if (temporary2 != 0)
        goto original1481_216;
    __asm__ volatile("" : "=r"(privateState) : "0"(privateState));
    goto original1481Return;
original1481_238:
    argument1 = (int)0x80070000U;
    Level47_79AC4Keep(argument1);
    argument1 = Level47_79AC4Field(argument1, int *, -15024);
    Level47_79AC4Keep(argument1);
    argument3 = 0 + 1;
    Level47_79AC4Keep(argument3);
    argument2 = 0 + 2;
    Level47_79AC4Keep(argument2);
    argument0 = privateState + 0;
    Level47_79AC4Keep(argument0);
original1481_243:
    temporary3 = Level47_79AC4Field(argument0, int *, 44);
    Level47_79AC4Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + argument1;
    Level47_79AC4Keep(temporary2);
    temporary2 = Level47_79AC4Field(temporary2, unsigned char *, 73);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0)
        goto original1481_256;
    saved21 = saved17 + 0;
    Level47_79AC4Keep(saved21);
original1481_256:
    if (temporary2 != argument3)
        goto original1481_262;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 40);
    Level47_79AC4Keep(temporary8);

    temporary8 = temporary8 + 1;
    Level47_79AC4Keep(temporary8);
    Level47_79AC4Field(&locals.sp18, volatile int *, 40) = temporary8;
original1481_262:
    if (temporary2 != argument2)
        goto original1481_268;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 32);
    Level47_79AC4Keep(temporary8);

    temporary8 = temporary8 + 1;
    Level47_79AC4Keep(temporary8);
    Level47_79AC4Field(&locals.sp18, volatile int *, 32) = temporary8;
original1481_268:
    saved17 = saved17 + 1;
    Level47_79AC4Keep(saved17);
    temporary2 = saved17 < 5;
    Level47_79AC4Keep(temporary2);
    if (temporary2 != 0 ? (argument0 = argument0 + 4, 1) : (argument0 = argument0 + 4, 0))
        goto original1481_243;
    Level47_79AC4Keep(temporary2);
    saved17 = 0 + 0;
    Level47_79AC4Keep(saved17);
    argument1 = (int)0x80070000U;
    Level47_79AC4Keep(argument1);
    argument1 = Level47_79AC4Field(argument1, int *, -15024);
    Level47_79AC4Keep(argument1);
    argument3 = 0 + 1;
    Level47_79AC4Keep(argument3);
    argument2 = 0 + 2;
    Level47_79AC4Keep(argument2);
    argument0 = privateState + 0;
    Level47_79AC4Keep(argument0);
original1481_278:
    temporary3 = Level47_79AC4Field(argument0, int *, 64);
    Level47_79AC4Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + argument1;
    Level47_79AC4Keep(temporary2);
    temporary2 = Level47_79AC4Field(temporary2, unsigned char *, 73);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0)
        goto original1481_291;
    saved23 = saved17 + 0;
    Level47_79AC4Keep(saved23);
original1481_291:
    if (temporary2 != argument3)
        goto original1481_297;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 56);
    Level47_79AC4Keep(temporary8);

    temporary8 = temporary8 + 1;
    Level47_79AC4Keep(temporary8);
    Level47_79AC4Field(&locals.sp18, volatile int *, 56) = temporary8;
original1481_297:
    if (temporary2 != argument2)
        goto original1481_303;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 48);
    Level47_79AC4Keep(temporary8);

    temporary8 = temporary8 + 1;
    Level47_79AC4Keep(temporary8);
    Level47_79AC4Field(&locals.sp18, volatile int *, 48) = temporary8;
original1481_303:
    saved17 = saved17 + 1;
    Level47_79AC4Keep(saved17);
    temporary2 = saved17 < 3;
    Level47_79AC4Keep(temporary2);
    if (temporary2 != 0 ? (argument0 = argument0 + 4, 1) : (argument0 = argument0 + 4, 0))
        goto original1481_278;
    Level47_79AC4Keep(temporary2);
    saved17 = 0 + 0;
    Level47_79AC4Keep(saved17);
    argument1 = (int)0x80070000U;
    Level47_79AC4Keep(argument1);
    argument1 = Level47_79AC4Field(argument1, int *, -15024);
    Level47_79AC4Keep(argument1);
    argument3 = 0 + 1;
    Level47_79AC4Keep(argument3);
    argument2 = 0 + 2;
    Level47_79AC4Keep(argument2);
    argument0 = privateState + 0;
    Level47_79AC4Keep(argument0);
original1481_313:
    temporary3 = Level47_79AC4Field(argument0, int *, 76);
    Level47_79AC4Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + argument1;
    Level47_79AC4Keep(temporary2);
    temporary2 = Level47_79AC4Field(temporary2, unsigned char *, 73);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0)
        goto original1481_326;
    Level47_79AC4Field(&locals.sp18, volatile int *, 80) = saved17;
original1481_326:
    if (temporary2 != argument3)
        goto original1481_332;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 72);
    Level47_79AC4Keep(temporary8);

    temporary8 = temporary8 + 1;
    Level47_79AC4Keep(temporary8);
    Level47_79AC4Field(&locals.sp18, volatile int *, 72) = temporary8;
original1481_332:
    if (temporary2 != argument2)
        goto original1481_338;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 64);
    Level47_79AC4Keep(temporary8);

    temporary8 = temporary8 + 1;
    Level47_79AC4Keep(temporary8);
    Level47_79AC4Field(&locals.sp18, volatile int *, 64) = temporary8;
original1481_338:
    saved17 = saved17 + 1;
    Level47_79AC4Keep(saved17);
    temporary2 = saved17 < 3;
    Level47_79AC4Keep(temporary2);
    if (temporary2 != 0 ? (argument0 = argument0 + 4, 1) : (argument0 = argument0 + 4, 0))
        goto original1481_313;
    temporary2 = saved16 < 11;
    Level47_79AC4Keep(temporary2);
    if (temporary2 != 0 ? (temporary8 = 0 + 1, 1) : (temporary8 = 0 + 1, 0))
        goto original1481_347;
    temporary8 = 0 + 3;
    goto original1481_351;
original1481_347:
    temporary2 = saved16 < 6;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(&locals.sp18, int *, 88) = temporary8;
    if (temporary2 != 0)
        goto original1481_352;
    temporary8 = 0 + 2;
    Level47_79AC4Keep(temporary8);
original1481_351:
    Level47_79AC4Field(&locals.sp18, int *, 88) = temporary8;
original1481_352:
    saved17 = 0 + 0;
    Level47_79AC4Keep(saved17);
    saved16 = privateState + 0;
    Level47_79AC4Keep(saved16);
original1481_354:
    temporary2 = Level47_79AC4Field(saved16, int *, 100);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0 ? (argument0 = 0 + 765, 1) : (argument0 = 0 + 765, 0))
        goto original1481_364;
    Level47_79AC4Keep(argument0);
    temporary2 = (int)0x80070000U;
    Level47_79AC4Keep(temporary2);
    temporary2 = Level47_79AC4Field(temporary2, int *, 17120);
    Level47_79AC4Keep(temporary2);

    argument1 = owner + 0;
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(saved16, int *, 100) = temporary2;
original1481_364:
    saved17 = saved17 + 1;
    Level47_79AC4Keep(saved17);
    temporary2 = saved17 < 3;
    Level47_79AC4Keep(temporary2);
    if (temporary2 != 0 ? (saved16 = saved16 + 4, 1) : (saved16 = saved16 + 4, 0))
        goto original1481_354;
    temporary2 = Level47_79AC4Field(privateState, int *, 128);
    Level47_79AC4Keep(temporary2);

    if (temporary2 == 0)
        goto original1481_818;
    argument0 = privateState + 94;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 2;
    temporary2 = Level47_79AC4_func_800359A4(argument0, argument1);
    Level47_79AC4Keep(temporary2);
    if (temporary2 == 0)
        goto original1481_818;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 24);
    Level47_79AC4Keep(temporary8);

    temporary2 = Level47_79AC4Field(temporary8, int *, 36);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0)
        goto original1481_523;
    if (saved21 < 0)
        goto original1481_523;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 40);
    Level47_79AC4Keep(temporary8);

    temporary2 = temporary8 < 3;
    Level47_79AC4Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = (int)((unsigned int)saved21 << 2), 1)
                        : (temporary2 = (int)((unsigned int)saved21 << 2), 0))
        goto original1481_522;
    temporary2 = temporary2 + privateState;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary2, int *, 44);
    Level47_79AC4Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level47_79AC4Keep(temporary3);
    temporary3 = Level47_79AC4Field(temporary3, int *, -15024);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    saved17 = temporary3 + temporary2;
    Level47_79AC4Keep(saved17);
    temporary2 = Level47_79AC4Field(saved17, unsigned char *, 73);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0)
        goto original1481_522;
    temporary2 = Level47_79AC4Field(saved17, unsigned char *, 76);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0)
        goto original1481_522;
    saved18 = Level47_79AC4Field(saved17, int *, 0);
    Level47_79AC4Keep(saved18);

    temporary2 = Level47_79AC4_rand();
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(privateState, int *, 32);
    Level47_79AC4Keep(temporary3);

    temporary3 = Level47_79AC4Field(temporary3, short *, 0);
    Level47_79AC4Keep(temporary3);

    temporary3 = temporary2 % temporary3;
    Level47_79AC4Keep(temporary3);

    remainingScans = temporary3 + 1;
    Level47_79AC4Keep(remainingScans);
    if (remainingScans == 0 ? (argument2 = 0 + 0, 1) : (argument2 = 0 + 0, 0))
        goto original1481_460;
    Level47_79AC4Keep(argument2);
original1481_431:
    temporary3 = Level47_79AC4Field(privateState, int *, 32);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(saved18, unsigned char *, 4);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary3, short *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = temporary2 + 1;
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary2 % temporary3;
    Level47_79AC4Keep(temporary3);

    Level47_79AC4Field(saved18, unsigned char *, 4) = temporary3;
    temporary2 = Level47_79AC4Field(privateState, int *, 32);
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary3 & 255;
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 12);
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)((unsigned int)temporary3 << 4);
    Level47_79AC4Keep(temporary3);
    temporary3 = temporary3 + temporary2;
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0)
        goto original1481_458;
    remainingScans = remainingScans + -1;
    Level47_79AC4Keep(remainingScans);
original1481_458:
    if (remainingScans != 0 ? (argument2 = 0 + 0, 1) : (argument2 = 0 + 0, 0))
        goto original1481_431;
    Level47_79AC4Keep(argument2);
original1481_460:
    temporary2 = Level47_79AC4Field(saved18, unsigned char *, 4);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(privateState, int *, 32);
    Level47_79AC4Keep(temporary3);
    argument0 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(argument0);
    temporary3 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(argument0, int *, 12);
    Level47_79AC4Keep(temporary3);
    argument3 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(argument3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 4);
    Level47_79AC4Keep(temporary2);
    argument0 = Level47_79AC4Field(temporary3, int *, 0);
    Level47_79AC4Keep(argument0);
    argument1 = Level47_79AC4Field(temporary3, int *, 4);
    Level47_79AC4Keep(argument1);
    argument0 = argument3 - argument0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level47_79AC4_func_8004E880(argument0, argument1, argument2);
    Level47_79AC4Keep(temporary2);
    saved16 = temporary2 + 0;
    Level47_79AC4Keep(saved16);
    argument0 = Level47_79AC4Field(privateState, int *, 32);
    Level47_79AC4Keep(argument0);
    temporary3 = Level47_79AC4Field(saved18, unsigned char *, 4);
    Level47_79AC4Keep(temporary3);
    argument0 = Level47_79AC4Field(argument0, int *, 12);
    Level47_79AC4Keep(argument0);
    temporary3 = (int)((unsigned int)temporary3 << 4);
    Level47_79AC4Keep(temporary3);
    temporary3 = temporary3 + argument0;
    Level47_79AC4Keep(temporary3);
    argument0 = saved21 + 1;
    Level47_79AC4Keep(argument0);
    Level47_79AC4Field(temporary3, int *, 12) = argument0;
    temporary3 = (int)((unsigned int)saved16 << 1);
    Level47_79AC4Keep(temporary3);

    temporary2 = Level47_79AC4Field(((int)&Level47_79AC4_D_80065920 + temporary3), short *, 0);
    Level47_79AC4Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(&locals.sp18, volatile int *, 0) = temporary2;

    temporary2 = Level47_79AC4Field(((int)&Level47_79AC4_D_800658A0 + temporary3), short *, 0);
    Level47_79AC4Keep(temporary2);
    temporary3 = 0 + 8192;
    Level47_79AC4Keep(temporary3);
    Level47_79AC4Field(&locals.sp18, volatile int *, 8) = temporary3;
    __asm__ volatile(""
                     : "=r"(temporary2), "=r"(temporary3)
                     : "0"(temporary2), "1"(temporary3)
                     : "memory");
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(&locals.sp18, volatile int *, 4) = temporary2;
    temporary2 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(temporary2);
    argument2 = (int)&locals.sp18;
    Level47_79AC4Keep(argument2);
    argument1 = Level47_79AC4Field(temporary2, int *, 12);
    Level47_79AC4Keep(argument1);
    argument0 = saved17 + 12;
    Level47_79AC4_func_8004F194(argument0, argument1, argument2);
    temporary3 = 0 + 1;
    Level47_79AC4Keep(temporary3);
    temporary2 = 0 + 64;
    Level47_79AC4Keep(temporary2);
    saved16 = saved16 + -128;
    Level47_79AC4Keep(saved16);
    Level47_79AC4Field(saved17, unsigned char *, 65) = temporary3;
    Level47_79AC4Field(saved17, unsigned char *, 76) = temporary2;
    Level47_79AC4Field(saved17, unsigned char *, 77) = temporary3;
    Level47_79AC4Field(saved17, unsigned char *, 70) = saved16;
    temporary3 = Level47_79AC4Field(privateState, int *, 32);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(saved18, unsigned char *, 4);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(saved17, short *, 56);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 8);
    Level47_79AC4Keep(temporary2);

    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(saved18, int *, 8) = temporary2;
    temporary2 = 0 + 255;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(saved17, unsigned char *, 74) = temporary2;
    temporary2 = 0 + 120;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(privateState, short *, 94) = temporary2;
original1481_522:
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 24);
    Level47_79AC4Keep(temporary8);
original1481_523:

    temporary3 = Level47_79AC4Field(temporary8, int *, 36);
    Level47_79AC4Keep(temporary3);
    temporary2 = 0 + 1;
    Level47_79AC4Keep(temporary2);
    if (temporary3 != temporary2)
        goto original1481_667;
    if (saved23 < 0)
        goto original1481_667;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 56);
    Level47_79AC4Keep(temporary8);

    temporary2 = temporary8 < 2;
    Level47_79AC4Keep(temporary2);
    if (temporary2 == 0 ? (temporary2 = (int)((unsigned int)saved23 << 2), 1)
                        : (temporary2 = (int)((unsigned int)saved23 << 2), 0))
        goto original1481_667;
    temporary2 = temporary2 + privateState;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary2, int *, 64);
    Level47_79AC4Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level47_79AC4Keep(temporary3);
    temporary3 = Level47_79AC4Field(temporary3, int *, -15024);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    saved17 = temporary3 + temporary2;
    Level47_79AC4Keep(saved17);
    temporary2 = Level47_79AC4Field(saved17, unsigned char *, 73);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0)
        goto original1481_667;
    temporary2 = Level47_79AC4Field(saved17, unsigned char *, 76);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0)
        goto original1481_667;
    saved18 = Level47_79AC4Field(saved17, int *, 0);
    Level47_79AC4Keep(saved18);

    temporary2 = Level47_79AC4_rand();
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(privateState, int *, 36);
    Level47_79AC4Keep(temporary3);

    temporary3 = Level47_79AC4Field(temporary3, short *, 0);
    Level47_79AC4Keep(temporary3);

    temporary3 = temporary2 % temporary3;
    Level47_79AC4Keep(temporary3);

    remainingScans = temporary3 + 1;
    Level47_79AC4Keep(remainingScans);
    if (remainingScans == 0 ? (argument2 = 0 + 0, 1) : (argument2 = 0 + 0, 0))
        goto original1481_605;
    Level47_79AC4Keep(argument2);
original1481_576:
    temporary3 = Level47_79AC4Field(privateState, int *, 36);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(saved18, unsigned char *, 4);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary3, short *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = temporary2 + 1;
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary2 % temporary3;
    Level47_79AC4Keep(temporary3);

    Level47_79AC4Field(saved18, unsigned char *, 4) = temporary3;
    temporary2 = Level47_79AC4Field(privateState, int *, 36);
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary3 & 255;
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 12);
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)((unsigned int)temporary3 << 4);
    Level47_79AC4Keep(temporary3);
    temporary3 = temporary3 + temporary2;
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0)
        goto original1481_603;
    remainingScans = remainingScans + -1;
    Level47_79AC4Keep(remainingScans);
original1481_603:
    if (remainingScans != 0 ? (argument2 = 0 + 0, 1) : (argument2 = 0 + 0, 0))
        goto original1481_576;
    Level47_79AC4Keep(argument2);
original1481_605:
    temporary2 = Level47_79AC4Field(saved18, unsigned char *, 4);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(privateState, int *, 36);
    Level47_79AC4Keep(temporary3);
    argument0 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(argument0);
    temporary3 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(argument0, int *, 12);
    Level47_79AC4Keep(temporary3);
    argument3 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(argument3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 4);
    Level47_79AC4Keep(temporary2);
    argument0 = Level47_79AC4Field(temporary3, int *, 0);
    Level47_79AC4Keep(argument0);
    argument1 = Level47_79AC4Field(temporary3, int *, 4);
    Level47_79AC4Keep(argument1);
    argument0 = argument3 - argument0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level47_79AC4_func_8004E880(argument0, argument1, argument2);
    Level47_79AC4Keep(temporary2);
    saved16 = temporary2 + 0;
    Level47_79AC4Keep(saved16);
    argument0 = Level47_79AC4Field(privateState, int *, 36);
    Level47_79AC4Keep(argument0);
    temporary3 = Level47_79AC4Field(saved18, unsigned char *, 4);
    Level47_79AC4Keep(temporary3);
    argument0 = Level47_79AC4Field(argument0, int *, 12);
    Level47_79AC4Keep(argument0);
    temporary3 = (int)((unsigned int)temporary3 << 4);
    Level47_79AC4Keep(temporary3);
    temporary3 = temporary3 + argument0;
    Level47_79AC4Keep(temporary3);
    argument0 = saved23 + 1;
    Level47_79AC4Keep(argument0);
    Level47_79AC4Field(temporary3, int *, 12) = argument0;
    temporary3 = (int)((unsigned int)saved16 << 1);
    Level47_79AC4Keep(temporary3);

    temporary2 = Level47_79AC4Field(((int)&Level47_79AC4_D_80065920 + temporary3), short *, 0);
    Level47_79AC4Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(&locals.sp18, volatile int *, 0) = temporary2;

    temporary2 = Level47_79AC4Field(((int)&Level47_79AC4_D_800658A0 + temporary3), short *, 0);
    Level47_79AC4Keep(temporary2);
    temporary3 = 0 + 8192;
    Level47_79AC4Keep(temporary3);
    Level47_79AC4Field(&locals.sp18, volatile int *, 8) = temporary3;
    __asm__ volatile(""
                     : "=r"(temporary2), "=r"(temporary3)
                     : "0"(temporary2), "1"(temporary3)
                     : "memory");
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(&locals.sp18, volatile int *, 4) = temporary2;
    temporary2 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(temporary2);
    argument2 = (int)&locals.sp18;
    Level47_79AC4Keep(argument2);
    argument1 = Level47_79AC4Field(temporary2, int *, 12);
    Level47_79AC4Keep(argument1);
    argument0 = saved17 + 12;
    Level47_79AC4_func_8004F194(argument0, argument1, argument2);
    temporary3 = 0 + 1;
    Level47_79AC4Keep(temporary3);
    temporary2 = 0 + 64;
    Level47_79AC4Keep(temporary2);
    saved16 = saved16 + 96;
    Level47_79AC4Keep(saved16);
    Level47_79AC4Field(saved17, unsigned char *, 65) = temporary3;
    Level47_79AC4Field(saved17, unsigned char *, 76) = temporary2;
    Level47_79AC4Field(saved17, unsigned char *, 77) = temporary3;
    Level47_79AC4Field(saved17, unsigned char *, 70) = saved16;
    temporary3 = Level47_79AC4Field(privateState, int *, 36);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(saved18, unsigned char *, 4);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(saved17, short *, 56);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 8);
    Level47_79AC4Keep(temporary2);

    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(saved18, int *, 8) = temporary2;
    temporary2 = 0 + 255;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(saved17, unsigned char *, 74) = temporary2;
    temporary2 = 0 + 120;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(privateState, short *, 94) = temporary2;
original1481_667:
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 24);
    Level47_79AC4Keep(temporary8);

    temporary3 = Level47_79AC4Field(temporary8, int *, 36);
    Level47_79AC4Keep(temporary3);
    temporary2 = 0 + 2;
    Level47_79AC4Keep(temporary2);
    if (temporary3 != temporary2)
        goto original1481_818;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 80);
    Level47_79AC4Keep(temporary8);

    if (temporary8 < 0)
        goto original1481_818;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 72);
    Level47_79AC4Keep(temporary8);

    temporary2 = temporary8 < 2;
    Level47_79AC4Keep(temporary2);
    if (temporary2 == 0)
        goto original1481_818;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 80);
    Level47_79AC4Keep(temporary8);

    temporary2 = (int)((unsigned int)temporary8 << 2);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + privateState;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary2, int *, 76);
    Level47_79AC4Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level47_79AC4Keep(temporary3);
    temporary3 = Level47_79AC4Field(temporary3, int *, -15024);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    saved17 = temporary3 + temporary2;
    Level47_79AC4Keep(saved17);
    temporary2 = Level47_79AC4Field(saved17, unsigned char *, 73);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0)
        goto original1481_818;
    temporary2 = Level47_79AC4Field(saved17, unsigned char *, 76);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0)
        goto original1481_818;
    saved18 = Level47_79AC4Field(saved17, int *, 0);
    Level47_79AC4Keep(saved18);

    temporary2 = Level47_79AC4_rand();
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(privateState, int *, 40);
    Level47_79AC4Keep(temporary3);

    temporary3 = Level47_79AC4Field(temporary3, short *, 0);
    Level47_79AC4Keep(temporary3);

    temporary3 = temporary2 % temporary3;
    Level47_79AC4Keep(temporary3);

    remainingScans = temporary3 + 1;
    Level47_79AC4Keep(remainingScans);
    if (remainingScans == 0 ? (argument2 = 0 + 0, 1) : (argument2 = 0 + 0, 0))
        goto original1481_755;
    Level47_79AC4Keep(argument2);
original1481_726:
    temporary3 = Level47_79AC4Field(privateState, int *, 40);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(saved18, unsigned char *, 4);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary3, short *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = temporary2 + 1;
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary2 % temporary3;
    Level47_79AC4Keep(temporary3);

    Level47_79AC4Field(saved18, unsigned char *, 4) = temporary3;
    temporary2 = Level47_79AC4Field(privateState, int *, 40);
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary3 & 255;
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 12);
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)((unsigned int)temporary3 << 4);
    Level47_79AC4Keep(temporary3);
    temporary3 = temporary3 + temporary2;
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0)
        goto original1481_753;
    remainingScans = remainingScans + -1;
    Level47_79AC4Keep(remainingScans);
original1481_753:
    if (remainingScans != 0 ? (argument2 = 0 + 0, 1) : (argument2 = 0 + 0, 0))
        goto original1481_726;
    Level47_79AC4Keep(argument2);
original1481_755:
    temporary2 = Level47_79AC4Field(saved18, unsigned char *, 4);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(privateState, int *, 40);
    Level47_79AC4Keep(temporary3);
    argument0 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(argument0);
    temporary3 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(argument0, int *, 12);
    Level47_79AC4Keep(temporary3);
    argument3 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(argument3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 4);
    Level47_79AC4Keep(temporary2);
    argument0 = Level47_79AC4Field(temporary3, int *, 0);
    Level47_79AC4Keep(argument0);
    argument1 = Level47_79AC4Field(temporary3, int *, 4);
    Level47_79AC4Keep(argument1);
    argument0 = argument3 - argument0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level47_79AC4_func_8004E880(argument0, argument1, argument2);
    Level47_79AC4Keep(temporary2);
    saved16 = temporary2 + 0;
    Level47_79AC4Keep(saved16);
    argument0 = Level47_79AC4Field(privateState, int *, 40);
    Level47_79AC4Keep(argument0);
    temporary3 = Level47_79AC4Field(saved18, unsigned char *, 4);
    Level47_79AC4Keep(temporary3);
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 80);
    Level47_79AC4Keep(temporary8);
    argument0 = Level47_79AC4Field(argument0, int *, 12);
    Level47_79AC4Keep(argument0);
    temporary3 = (int)((unsigned int)temporary3 << 4);
    Level47_79AC4Keep(temporary3);
    temporary3 = temporary3 + argument0;
    Level47_79AC4Keep(temporary3);
    argument0 = temporary8 + 1;
    Level47_79AC4Keep(argument0);
    Level47_79AC4Field(temporary3, int *, 12) = argument0;
    temporary3 = (int)((unsigned int)saved16 << 1);
    Level47_79AC4Keep(temporary3);

    temporary2 = Level47_79AC4Field(((int)&Level47_79AC4_D_80065920 + temporary3), short *, 0);
    Level47_79AC4Keep(temporary2);

    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(&locals.sp18, volatile int *, 0) = temporary2;

    temporary2 = Level47_79AC4Field(((int)&Level47_79AC4_D_800658A0 + temporary3), short *, 0);
    Level47_79AC4Keep(temporary2);
    temporary3 = 0 + 8192;
    Level47_79AC4Keep(temporary3);
    Level47_79AC4Field(&locals.sp18, volatile int *, 8) = temporary3;
    __asm__ volatile(""
                     : "=r"(temporary2), "=r"(temporary3)
                     : "0"(temporary2), "1"(temporary3)
                     : "memory");
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(&locals.sp18, volatile int *, 4) = temporary2;
    temporary2 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(temporary2);
    argument2 = (int)&locals.sp18;
    Level47_79AC4Keep(argument2);
    argument1 = Level47_79AC4Field(temporary2, int *, 12);
    Level47_79AC4Keep(argument1);
    argument0 = saved17 + 12;
    Level47_79AC4_func_8004F194(argument0, argument1, argument2);
    temporary3 = 0 + 1;
    Level47_79AC4Keep(temporary3);
    temporary2 = 0 + 64;
    Level47_79AC4Keep(temporary2);
    saved16 = saved16 + 96;
    Level47_79AC4Keep(saved16);
    Level47_79AC4Field(saved17, unsigned char *, 65) = temporary3;
    Level47_79AC4Field(saved17, unsigned char *, 76) = temporary2;
    Level47_79AC4Field(saved17, unsigned char *, 77) = temporary3;
    Level47_79AC4Field(saved17, unsigned char *, 70) = saved16;
    temporary3 = Level47_79AC4Field(privateState, int *, 40);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(saved18, unsigned char *, 4);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(saved17, short *, 56);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 8);
    Level47_79AC4Keep(temporary2);

    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(saved18, int *, 8) = temporary2;
    temporary2 = 0 + 255;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(saved17, unsigned char *, 74) = temporary2;
    temporary2 = 0 + 120;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(privateState, short *, 94) = temporary2;
original1481_818:
    temporary3 = Level47_79AC4Field(owner, unsigned char *, 72);
    Level47_79AC4Keep(temporary3);

    switch ((unsigned int)temporary3) {
    case 0:
        Level47_79AC4Keep(temporary3);
        goto original1481_829;
    case 1:
        Level47_79AC4Keep(temporary3);
        goto original1481_1342;
    case 2:
        Level47_79AC4Keep(temporary3);
        goto original1481_1342;
    case 3:
        Level47_79AC4Keep(temporary3);
        goto original1481_1338;
    case 4:
        Level47_79AC4Keep(temporary3);
        goto original1481_1342;
    case 5:
        Level47_79AC4Keep(temporary3);
        goto original1481Return;
    case 6:
        Level47_79AC4Keep(temporary3);
        goto original1481Return;
    case 7:
        Level47_79AC4Keep(temporary3);
        goto original1481Return;
    case 8:
        Level47_79AC4Keep(temporary3);
        goto original1481_1425;
    default:
        goto original1481Return;
    }
original1481_829:
    temporary2 = Level47_79AC4Field(privateState, int *, 128);
    __asm__("" : "=r"(temporary2) : "0"(temporary2), "r"(temporary3));

    Level47_79AC4Field(&locals.sp18, int *, 104) = 0;
    if (temporary2 != 0)
        goto original1481_851;
    temporary2 = 0 + 1;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(owner, short *, 56) = 0;
    Level47_79AC4Field(privateState, unsigned char *, 5) = temporary2;
    temporary2 = (int)0x80070000U;
    Level47_79AC4Keep(temporary2);
    temporary2 = Level47_79AC4Field(temporary2, int *, -14952);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1481Return;
    Level47_79AC4Keep(temporary2);
    argument1 = 0 + 0;
    temporary2 = Level47_79AC4_func_80037BBC(argument0, argument1);
    Level47_79AC4Keep(temporary2);
    if (temporary2 == 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1481Return;
    argument1 = 0 + 0;
    Level47_79AC4Keep(argument1);
    argument2 = 0 + 8;
    Level47_79AC4_func_800512E4(argument0, argument1, argument2);
    temporary2 = 0 + 8;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(owner, unsigned char *, 72) = temporary2;
    goto original1481Return;
original1481_851:
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 24);
    Level47_79AC4Keep(temporary8);

    temporary2 = Level47_79AC4Field(temporary8, int *, 52);
    Level47_79AC4Keep(temporary2);

    if (temporary2 == 0)
        goto original1481Return;
    argument0 = Level47_79AC4Field(privateState, int *, 88);
    Level47_79AC4Keep(argument0);

    if (argument0 == 0 ? (temporary2 = 0 + 257, 1) : (temporary2 = 0 + 257, 0))
        goto original1481_909;
    temporary3 = Level47_79AC4Field(argument0, unsigned short *, 72);
    Level47_79AC4Keep(temporary3);

    if (temporary3 != temporary2 ? (temporary2 = 0 + 747, 1) : (temporary2 = 0 + 747, 0))
        goto original1481_909;
    temporary3 = Level47_79AC4Field(argument0, short *, 54);
    Level47_79AC4Keep(temporary3);

    if (temporary3 != temporary2 ? (temporary2 = 0 + 746, 1) : (temporary2 = 0 + 746, 0))
        goto original1481_875;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 32);
    Level47_79AC4Keep(temporary8);

    temporary2 = temporary8 < 3;
    Level47_79AC4Keep(temporary2);
    if (temporary2 != 0 ? (argument0 = 0 + 197, 1) : (argument0 = 0 + 197, 0))
        goto original1481_897;
    temporary2 = 0 + 746;
    Level47_79AC4Keep(temporary2);
original1481_875:
    if (temporary3 != temporary2)
        goto original1481_881;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 48);
    Level47_79AC4Keep(temporary8);

    if (temporary8 <= 0 ? (argument0 = 0 + 197, 1) : (argument0 = 0 + 197, 0))
        goto original1481_897;
original1481_881:
    temporary2 = 0 + 757;
    Level47_79AC4Keep(temporary2);
    if (temporary3 != temporary2)
        goto original1481_888;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 64);
    Level47_79AC4Keep(temporary8);

    if (temporary8 <= 0 ? (argument0 = 0 + 197, 1) : (argument0 = 0 + 197, 0))
        goto original1481_897;
original1481_888:
    temporary2 = 0 + 765;
    Level47_79AC4Keep(temporary2);
    if (temporary3 != temporary2)
        goto original1481_909;
    temporary2 = Level47_79AC4Field(privateState, unsigned char *, 99);
    Level47_79AC4Keep(temporary2);
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 88);
    Level47_79AC4Keep(temporary8);

    temporary2 = temporary2 < temporary8;
    Level47_79AC4Keep(temporary2);
    if (temporary2 == 0 ? (argument0 = 0 + 197, 1) : (argument0 = 0 + 197, 0))
        goto original1481_909;
original1481_897:
    __asm__ volatile("" : "=r"(argument0) : "0"(argument0) : "$2", "memory");
    temporary2 = (int)0x80070000U;
    Level47_79AC4Keep(temporary2);
    temporary2 = Level47_79AC4Field(temporary2, int *, 17120);
    Level47_79AC4Keep(temporary2);
    argument1 = owner + 0;
    Level47_79AC4Keep(argument1);
    Level47_79AC4Field(&locals.sp18, int *, 96) = 0;
    temporary2 = ((int (*)())temporary2)(argument0, argument1);
    Level47_79AC4Keep(temporary2);
    argument0 = owner + 0;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 3;
    Level47_79AC4Keep(argument1);
    temporary2 = 0 + 3;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(owner, unsigned char *, 72) = temporary2;
    Level47_79AC4_func_80034F40(argument0, argument1);

    goto original1481_1016;
original1481_909:
    __asm__ volatile("" : "=r"(privateState) : "0"(privateState) : "$2", "memory");
    temporary2 = (int)0x80070000U;
    Level47_79AC4Keep(temporary2);
    temporary2 = Level47_79AC4Field(temporary2, int *, 1448);
    Level47_79AC4Keep(temporary2);

    temporary2 = temporary2 < 2;
    Level47_79AC4Keep(temporary2);
    if (temporary2 == 0)
        goto original1481_1016;
    temporary2 = Level47_79AC4Field(privateState, unsigned char *, 99);
    Level47_79AC4Keep(temporary2);
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 88);
    Level47_79AC4Keep(temporary8);

    temporary2 = temporary2 < temporary8;
    Level47_79AC4Keep(temporary2);
    if (temporary2 == 0)
        goto original1481_1016;
    temporary2 = Level47_79AC4Field(privateState, int *, 100);
    Level47_79AC4Keep(temporary2);

    if (temporary2 == 0)
        goto original1481_929;
    temporary2 = Level47_79AC4Field(temporary2, unsigned char *, 72);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0 ? (saved18 = 0 + -1, 1) : (saved18 = 0 + -1, 0))
        goto original1481_945;
original1481_929:
    temporary2 = Level47_79AC4Field(privateState, int *, 104);
    Level47_79AC4Keep(temporary2);

    if (temporary2 == 0)
        goto original1481_937;
    temporary2 = Level47_79AC4Field(temporary2, unsigned char *, 72);
    Level47_79AC4Keep(temporary2);

    if (temporary2 != 0 ? (saved18 = 0 + -1, 1) : (saved18 = 0 + -1, 0))
        goto original1481_945;
original1481_937:
    temporary2 = Level47_79AC4Field(privateState, int *, 108);
    Level47_79AC4Keep(temporary2);

    if (temporary2 == 0)
        goto original1481_1016;
    temporary2 = Level47_79AC4Field(temporary2, unsigned char *, 72);
    Level47_79AC4Keep(temporary2);

    if (temporary2 == 0 ? (saved18 = 0 + -1, 1) : (saved18 = 0 + -1, 0))
        goto original1481_1016;
original1481_945:
    argument2 = 0 + 0;
    Level47_79AC4Keep(argument2);
    saved16 = 0 + 0;
    Level47_79AC4Keep(saved16);
    saved17 = privateState + 0;
    Level47_79AC4Keep(saved17);
    temporary3 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(temporary3);
    argument0 = Level47_79AC4Field(owner, int *, 12);
    Level47_79AC4Keep(argument0);
    argument1 = Level47_79AC4Field(owner, int *, 16);
    Level47_79AC4Keep(argument1);
    temporary2 = Level47_79AC4Field(temporary3, short *, 2);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 4);
    Level47_79AC4Keep(temporary2);
    argument0 = temporary3 - argument0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level47_79AC4_func_8004E880(argument0, argument1, argument2);
    Level47_79AC4Keep(temporary2);
    saved21 = temporary2 + 0;
    Level47_79AC4Keep(saved21);
original1481_961:
    argument1 = Level47_79AC4Field(saved17, int *, 100);
    Level47_79AC4Keep(argument1);

    if (argument1 == 0 ? (temporary2 = 0 + 1, 1) : (temporary2 = 0 + 1, 0))
        goto original1481_991;
    temporary3 = Level47_79AC4Field(argument1, unsigned char *, 73);
    Level47_79AC4Keep(temporary3);

    if (temporary3 != temporary2 ? (argument2 = 0 + 0, 1) : (argument2 = 0 + 0, 0))
        goto original1481_991;
    Level47_79AC4Keep(argument2);
    temporary2 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(temporary2);
    argument0 = Level47_79AC4Field(argument1, int *, 12);
    Level47_79AC4Keep(argument0);
    temporary2 = Level47_79AC4Field(temporary2, int *, 12);
    Level47_79AC4Keep(temporary2);
    argument1 = Level47_79AC4Field(argument1, int *, 16);
    Level47_79AC4Keep(argument1);
    temporary3 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 4);
    Level47_79AC4Keep(temporary2);
    argument0 = temporary3 - argument0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level47_79AC4_func_8004E880(argument0, argument1, argument2);
    Level47_79AC4Keep(temporary2);
    saved22 = temporary2 + 0;
    Level47_79AC4Keep(saved22);
    argument0 = saved21 + 0;
    Level47_79AC4Keep(argument0);
    argument1 = saved22 + 0;
    temporary2 = Level47_79AC4_func_8004F264(argument0, argument1);
    Level47_79AC4Keep(temporary2);
    if (saved18 <= 0 ? (temporary3 = temporary2 + 0, 1) : (temporary3 = temporary2 + 0, 0))
        goto original1481_989;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 112);
    Level47_79AC4Keep(temporary8);

    temporary2 = temporary3 < temporary8;
    Level47_79AC4Keep(temporary2);
    if (temporary2 == 0)
        goto original1481_991;
original1481_989:
    Level47_79AC4Field(&locals.sp18, volatile int *, 112) = temporary3;
    saved18 = saved16 + 0;
    Level47_79AC4Keep(saved18);
original1481_991:
    saved16 = saved16 + 1;
    Level47_79AC4Keep(saved16);
    temporary2 = saved16 < 3;
    Level47_79AC4Keep(temporary2);
    if (temporary2 != 0 ? (saved17 = saved17 + 4, 1) : (saved17 = saved17 + 4, 0))
        goto original1481_961;
    if (saved18 < 0 ? (temporary2 = (int)((unsigned int)saved18 << 2), 1)
                    : (temporary2 = (int)((unsigned int)saved18 << 2), 0))
        goto original1481_1016;
    temporary2 = temporary2 + privateState;
    Level47_79AC4Keep(temporary2);
    temporary2 = Level47_79AC4Field(temporary2, int *, 100);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(temporary3);
    argument2 = 0 + 0;
    Level47_79AC4Keep(argument2);
    Level47_79AC4Field(&locals.sp18, int *, 96) = 0;
    Level47_79AC4Field(privateState, int *, 88) = temporary2;
    temporary3 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary3);
    argument0 = Level47_79AC4Field(temporary2, int *, 12);
    Level47_79AC4Keep(argument0);
    argument1 = Level47_79AC4Field(temporary2, int *, 16);
    Level47_79AC4Keep(argument1);
    argument3 = Level47_79AC4Field(temporary3, int *, 0);
    Level47_79AC4Keep(argument3);
    temporary3 = Level47_79AC4Field(temporary3, int *, 4);
    Level47_79AC4Keep(temporary3);
    argument0 = argument3 - argument0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary3 - argument1;
    temporary2 = Level47_79AC4_func_8004E880(argument0, argument1, argument2);
    Level47_79AC4Keep(temporary2);
    saved22 = temporary2 + 0;
    Level47_79AC4Keep(saved22);
    argument0 = saved21 + 0;
    Level47_79AC4Keep(argument0);
    argument1 = saved22 + 0;
    temporary2 = Level47_79AC4_func_8003613C(argument0, argument1);
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(&locals.sp18, int *, 104) = temporary2;
original1481_1016:
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 96);
    Level47_79AC4Keep(temporary8);

    if (temporary8 == 0 ? (saved18 = 0 + -1, 1) : (saved18 = 0 + -1, 0))
        goto original1481_1261;
    saved21 = 0 + -1;
    Level47_79AC4Keep(saved21);
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 72);
    Level47_79AC4Keep(temporary8);

    saved23 = 0 + -1;
    if (temporary8 <= 0)
        goto original1481_1093;
    argument2 = 0 + 0;
    Level47_79AC4Keep(argument2);
    saved16 = 0 + 0;
    Level47_79AC4Keep(saved16);
    saved17 = privateState + 0;
    Level47_79AC4Keep(saved17);
    temporary3 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(temporary3);
    argument0 = Level47_79AC4Field(owner, int *, 12);
    Level47_79AC4Keep(argument0);
    argument1 = Level47_79AC4Field(owner, int *, 16);
    Level47_79AC4Keep(argument1);
    temporary2 = Level47_79AC4Field(temporary3, short *, 2);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 4);
    Level47_79AC4Keep(temporary2);
    argument0 = temporary3 - argument0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level47_79AC4_func_8004E880(argument0, argument1, argument2);
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(&locals.sp18, volatile int *, 120) = temporary2;
original1481_1041:
    temporary3 = Level47_79AC4Field(saved17, int *, 76);
    Level47_79AC4Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level47_79AC4Keep(temporary3);
    temporary3 = Level47_79AC4Field(temporary3, int *, -15024);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    argument1 = temporary3 + temporary2;
    Level47_79AC4Keep(argument1);
    temporary3 = Level47_79AC4Field(argument1, unsigned char *, 73);
    Level47_79AC4Keep(temporary3);
    temporary2 = 0 + 1;
    Level47_79AC4Keep(temporary2);
    if (temporary3 != temporary2 ? (argument2 = 0 + 0, 1) : (argument2 = 0 + 0, 0))
        goto original1481_1075;
    Level47_79AC4Keep(argument2);
    temporary2 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(temporary2);
    argument0 = Level47_79AC4Field(argument1, int *, 12);
    Level47_79AC4Keep(argument0);
    temporary2 = Level47_79AC4Field(temporary2, int *, 12);
    Level47_79AC4Keep(temporary2);
    argument1 = Level47_79AC4Field(argument1, int *, 16);
    Level47_79AC4Keep(argument1);
    temporary3 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 4);
    Level47_79AC4Keep(temporary2);
    argument0 = temporary3 - argument0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level47_79AC4_func_8004E880(argument0, argument1, argument2);
    Level47_79AC4Keep(temporary2);
    saved22 = temporary2 + 0;
    Level47_79AC4Keep(saved22);
    argument0 = Level47_79AC4Field(&locals.sp18, volatile int *, 120);
    Level47_79AC4Keep(argument0);
    argument1 = saved22 + 0;
    temporary2 = Level47_79AC4_func_8004F264(argument0, argument1);
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary2 + 0;
    if (saved18 <= 0)
        goto original1481_1073;
    temporary2 = temporary3 < nearestDistance;
    Level47_79AC4Keep(temporary2);
    if (temporary2 == 0)
        goto original1481_1075;
original1481_1073:
    nearestDistance = temporary3 + 0;
    Level47_79AC4Keep(nearestDistance);
    saved18 = saved16 + 0;
    Level47_79AC4Keep(saved18);
original1481_1075:
    saved16 = saved16 + 1;
    Level47_79AC4Keep(saved16);
    temporary2 = saved16 < 3;
    Level47_79AC4Keep(temporary2);
    if (temporary2 != 0 ? (saved17 = saved17 + 4, 1) : (saved17 = saved17 + 4, 0))
        goto original1481_1041;
    temporary2 = (int)((unsigned int)saved18 << 2);
    if (saved18 < 0)
        goto original1481_1093;
    temporary2 = temporary2 + privateState;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary2, int *, 76);
    Level47_79AC4Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level47_79AC4Keep(temporary3);
    temporary3 = Level47_79AC4Field(temporary3, int *, -15024);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary3 + temporary2;
    Level47_79AC4Keep(temporary3);
    Level47_79AC4Field(privateState, int *, 88) = temporary3;
original1481_1093:
    temporary2 = 0 + -1;
    Level47_79AC4Keep(temporary2);
    if (saved18 != temporary2)
        goto original1481_1243;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 56);
    Level47_79AC4Keep(temporary8);

    if (temporary8 <= 0 ? (argument2 = 0 + 0, 1) : (argument2 = 0 + 0, 0))
        goto original1481_1170;
    Level47_79AC4Keep(argument2);
    saved16 = 0 + 0;
    Level47_79AC4Keep(saved16);
    saved17 = privateState + 0;
    Level47_79AC4Keep(saved17);
    temporary3 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(temporary3);
    argument0 = Level47_79AC4Field(owner, int *, 12);
    Level47_79AC4Keep(argument0);
    argument1 = Level47_79AC4Field(owner, int *, 16);
    Level47_79AC4Keep(argument1);
    temporary2 = Level47_79AC4Field(temporary3, short *, 2);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 4);
    Level47_79AC4Keep(temporary2);
    argument0 = temporary3 - argument0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level47_79AC4_func_8004E880(argument0, argument1, argument2);
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(&locals.sp18, volatile int *, 120) = temporary2;
original1481_1115:
    temporary3 = Level47_79AC4Field(saved17, int *, 64);
    Level47_79AC4Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level47_79AC4Keep(temporary3);
    temporary3 = Level47_79AC4Field(temporary3, int *, -15024);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    argument1 = temporary3 + temporary2;
    Level47_79AC4Keep(argument1);
    temporary3 = Level47_79AC4Field(argument1, unsigned char *, 73);
    Level47_79AC4Keep(temporary3);
    temporary2 = 0 + 1;
    Level47_79AC4Keep(temporary2);
    if (temporary3 != temporary2 ? (argument2 = 0 + 0, 1) : (argument2 = 0 + 0, 0))
        goto original1481_1149;
    Level47_79AC4Keep(argument2);
    temporary2 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(temporary2);
    argument0 = Level47_79AC4Field(argument1, int *, 12);
    Level47_79AC4Keep(argument0);
    temporary2 = Level47_79AC4Field(temporary2, int *, 12);
    Level47_79AC4Keep(temporary2);
    argument1 = Level47_79AC4Field(argument1, int *, 16);
    Level47_79AC4Keep(argument1);
    temporary3 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 4);
    Level47_79AC4Keep(temporary2);
    argument0 = temporary3 - argument0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level47_79AC4_func_8004E880(argument0, argument1, argument2);
    Level47_79AC4Keep(temporary2);
    saved22 = temporary2 + 0;
    Level47_79AC4Keep(saved22);
    argument0 = Level47_79AC4Field(&locals.sp18, volatile int *, 120);
    Level47_79AC4Keep(argument0);
    argument1 = saved22 + 0;
    temporary2 = Level47_79AC4_func_8004F264(argument0, argument1);
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary2 + 0;
    if (saved21 <= 0)
        goto original1481_1147;
    temporary2 = temporary3 < nearestDistance;
    Level47_79AC4Keep(temporary2);
    if (temporary2 == 0)
        goto original1481_1149;
original1481_1147:
    nearestDistance = temporary3 + 0;
    Level47_79AC4Keep(nearestDistance);
    saved21 = saved16 + 0;
    Level47_79AC4Keep(saved21);
original1481_1149:
    saved16 = saved16 + 1;
    Level47_79AC4Keep(saved16);
    temporary2 = saved16 < 3;
    Level47_79AC4Keep(temporary2);
    if (temporary2 != 0 ? (saved17 = saved17 + 4, 1) : (saved17 = saved17 + 4, 0))
        goto original1481_1115;
    if (saved21 < 0 ? (temporary2 = (int)((unsigned int)saved21 << 2), 1)
                    : (temporary2 = (int)((unsigned int)saved21 << 2), 0))
        goto original1481_1167;
    temporary2 = temporary2 + privateState;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary2, int *, 64);
    Level47_79AC4Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level47_79AC4Keep(temporary3);
    temporary3 = Level47_79AC4Field(temporary3, int *, -15024);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary3 + temporary2;
    Level47_79AC4Keep(temporary3);
    Level47_79AC4Field(privateState, int *, 88) = temporary3;
original1481_1167:
    temporary2 = 0 + -1;
    Level47_79AC4Keep(temporary2);
    if (saved18 != temporary2)
        goto original1481_1243;
original1481_1170:
    if (saved21 != saved18)
        goto original1481_1243;
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 40);
    Level47_79AC4Keep(temporary8);

    if (temporary8 <= 0 ? (argument2 = 0 + 0, 1) : (argument2 = 0 + 0, 0))
        goto original1481_1243;
    Level47_79AC4Keep(argument2);
    saved16 = 0 + 0;
    Level47_79AC4Keep(saved16);
    saved17 = privateState + 0;
    Level47_79AC4Keep(saved17);
    temporary3 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(temporary3);
    argument0 = Level47_79AC4Field(owner, int *, 12);
    Level47_79AC4Keep(argument0);
    argument1 = Level47_79AC4Field(owner, int *, 16);
    Level47_79AC4Keep(argument1);
    temporary2 = Level47_79AC4Field(temporary3, short *, 2);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 4);
    Level47_79AC4Keep(temporary2);
    argument0 = temporary3 - argument0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level47_79AC4_func_8004E880(argument0, argument1, argument2);
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(&locals.sp18, volatile int *, 120) = temporary2;
original1481_1191:
    temporary3 = Level47_79AC4Field(saved17, int *, 44);
    Level47_79AC4Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level47_79AC4Keep(temporary3);
    temporary3 = Level47_79AC4Field(temporary3, int *, -15024);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    argument1 = temporary3 + temporary2;
    Level47_79AC4Keep(argument1);
    temporary3 = Level47_79AC4Field(argument1, unsigned char *, 73);
    Level47_79AC4Keep(temporary3);
    temporary2 = 0 + 1;
    Level47_79AC4Keep(temporary2);
    if (temporary3 != temporary2 ? (argument2 = 0 + 0, 1) : (argument2 = 0 + 0, 0))
        goto original1481_1225;
    Level47_79AC4Keep(argument2);
    temporary2 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(temporary2);
    argument0 = Level47_79AC4Field(argument1, int *, 12);
    Level47_79AC4Keep(argument0);
    temporary2 = Level47_79AC4Field(temporary2, int *, 12);
    Level47_79AC4Keep(temporary2);
    argument1 = Level47_79AC4Field(argument1, int *, 16);
    Level47_79AC4Keep(argument1);
    temporary3 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 4);
    Level47_79AC4Keep(temporary2);
    argument0 = temporary3 - argument0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level47_79AC4_func_8004E880(argument0, argument1, argument2);
    Level47_79AC4Keep(temporary2);
    saved22 = temporary2 + 0;
    Level47_79AC4Keep(saved22);
    argument0 = Level47_79AC4Field(&locals.sp18, volatile int *, 120);
    Level47_79AC4Keep(argument0);
    argument1 = saved22 + 0;
    temporary2 = Level47_79AC4_func_8004F264(argument0, argument1);
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary2 + 0;
    if (saved23 <= 0)
        goto original1481_1223;
    temporary2 = temporary3 < nearestDistance;
    Level47_79AC4Keep(temporary2);
    if (temporary2 == 0)
        goto original1481_1225;
original1481_1223:
    nearestDistance = temporary3 + 0;
    Level47_79AC4Keep(nearestDistance);
    saved23 = saved16 + 0;
    Level47_79AC4Keep(saved23);
original1481_1225:
    saved16 = saved16 + 1;
    Level47_79AC4Keep(saved16);
    temporary2 = saved16 < 5;
    Level47_79AC4Keep(temporary2);
    if (temporary2 != 0 ? (saved17 = saved17 + 4, 1) : (saved17 = saved17 + 4, 0))
        goto original1481_1191;
    if (saved23 < 0 ? (temporary2 = (int)((unsigned int)saved23 << 2), 1)
                    : (temporary2 = (int)((unsigned int)saved23 << 2), 0))
        goto original1481_1243;
    temporary2 = temporary2 + privateState;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary2, int *, 44);
    Level47_79AC4Keep(temporary3);

    temporary2 = (int)((unsigned int)temporary3 << 1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary2 = (int)((unsigned int)temporary2 << 2);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 - temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = (int)0x80070000U;
    Level47_79AC4Keep(temporary3);
    temporary3 = Level47_79AC4Field(temporary3, int *, -15024);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 3);
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary3 + temporary2;
    Level47_79AC4Keep(temporary3);
    Level47_79AC4Field(privateState, int *, 88) = temporary3;
original1481_1243:
    argument1 = Level47_79AC4Field(privateState, int *, 88);
    Level47_79AC4Keep(argument1);

    if (argument1 == 0 ? (argument2 = 0 + 0, 1) : (argument2 = 0 + 0, 0))
        goto original1481_1261;
    Level47_79AC4Keep(argument2);
    temporary2 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(temporary2);
    argument0 = Level47_79AC4Field(argument1, int *, 12);
    Level47_79AC4Keep(argument0);
    temporary2 = Level47_79AC4Field(temporary2, int *, 12);
    Level47_79AC4Keep(temporary2);
    argument1 = Level47_79AC4Field(argument1, int *, 16);
    Level47_79AC4Keep(argument1);
    temporary3 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 4);
    Level47_79AC4Keep(temporary2);
    argument0 = temporary3 - argument0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level47_79AC4_func_8004E880(argument0, argument1, argument2);
    Level47_79AC4Keep(temporary2);
    saved22 = temporary2 + 0;
    Level47_79AC4Keep(saved22);
    argument0 = Level47_79AC4Field(&locals.sp18, volatile int *, 120);
    Level47_79AC4Keep(argument0);
    argument1 = saved22 + 0;
    temporary2 = Level47_79AC4_func_8003613C(argument0, argument1);
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(&locals.sp18, int *, 104) = temporary2;
original1481_1261:
    temporary8 = Level47_79AC4Field(&locals.sp18, volatile int *, 104);
    Level47_79AC4Keep(temporary8);

    temporary2 = temporary8 < -4;
    Level47_79AC4Keep(temporary2);
    if (temporary2 == 0 ? (argument0 = owner + 12, 1) : (argument0 = owner + 12, 0))
        goto original1481_1299;
    temporary3 = Level47_79AC4Field(privateState, int *, 24);
    Level47_79AC4Keep(temporary3);
    temporary2 = 0 + 1;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(privateState, short *, 92) = saved22;
    Level47_79AC4Field(temporary3, short *, 10) = temporary2;
    argument1 = Level47_79AC4Field(privateState, int *, 24);
    Level47_79AC4Keep(argument1);
    argument2 = (int)&locals.sp28;
    Level47_79AC4_func_8003645C(argument0, argument1, argument2);
    temporary3 = Level47_79AC4Field(privateState, int *, 24);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(&locals.sp18, volatile int *, 16);
    Level47_79AC4Keep(temporary2);

    Level47_79AC4Field(temporary3, short *, 2) = temporary2;
    argument2 = Level47_79AC4Field(privateState, int *, 24);
    Level47_79AC4Keep(argument2);

    temporary2 = Level47_79AC4Field(argument2, short *, 2);
    Level47_79AC4Keep(temporary2);
    argument0 = Level47_79AC4Field(argument2, short *, 10);
    Level47_79AC4Keep(argument0);
    temporary3 = Level47_79AC4Field(argument2, short *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = temporary2 + argument0;
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary2 % temporary3;
    Level47_79AC4Keep(temporary3);
    argument1 = 0 + 1;
    Level47_79AC4Keep(argument1);
    argument0 = owner + 0;
    Level47_79AC4Keep(argument0);
    temporary2 = 0 + 1;
    goto original1481_1333;
original1481_1299:
    temporary2 = temporary8 < 5;
    Level47_79AC4Keep(temporary2);
    if (temporary2 != 0 ? (temporary2 = 0 + -1, 1) : (temporary2 = 0 + -1, 0))
        goto original1481Return;
    temporary3 = Level47_79AC4Field(privateState, int *, 24);
    Level47_79AC4Keep(temporary3);
    Level47_79AC4Field(privateState, short *, 92) = saved22;
    Level47_79AC4Field(temporary3, short *, 10) = temporary2;
    argument1 = Level47_79AC4Field(privateState, int *, 24);
    Level47_79AC4Keep(argument1);
    argument2 = (int)&locals.sp28;
    Level47_79AC4_func_8003645C(argument0, argument1, argument2);
    temporary3 = Level47_79AC4Field(privateState, int *, 24);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(&locals.sp18, volatile int *, 16);
    Level47_79AC4Keep(temporary2);

    Level47_79AC4Field(temporary3, short *, 2) = temporary2;
    argument2 = Level47_79AC4Field(privateState, int *, 24);
    Level47_79AC4Keep(argument2);

    temporary2 = Level47_79AC4Field(argument2, short *, 2);
    Level47_79AC4Keep(temporary2);
    argument0 = Level47_79AC4Field(argument2, short *, 10);
    Level47_79AC4Keep(argument0);
    temporary3 = Level47_79AC4Field(argument2, short *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = temporary2 + argument0;
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary2 % temporary3;
    Level47_79AC4Keep(temporary3);
    argument1 = 0 + 2;
    Level47_79AC4Keep(argument1);
    argument0 = owner + 0;
    Level47_79AC4Keep(argument0);
    temporary2 = 0 + 2;
    Level47_79AC4Keep(temporary2);
original1481_1333:
    Level47_79AC4Field(argument2, short *, 2) = temporary3;
    Level47_79AC4Field(argument0, unsigned char *, 72) = temporary2;
    Level47_79AC4_func_80034F40(argument0, argument1);

    goto original1481Return;
original1481_1338:
    temporary2 = (int)0x80070000U;
    Level47_79AC4Keep(temporary2);
    temporary2 = Level47_79AC4Field(temporary2, int *, -14480);
    Level47_79AC4Keep(temporary2);

    goto original1481_1418;
original1481_1342:
    argument2 = 0 + 0;
    Level47_79AC4Keep(argument2);
    temporary3 = Level47_79AC4Field(privateState, int *, 24);
    Level47_79AC4Keep(temporary3);
    argument0 = Level47_79AC4Field(owner, int *, 12);
    Level47_79AC4Keep(argument0);
    argument1 = Level47_79AC4Field(owner, int *, 16);
    Level47_79AC4Keep(argument1);
    temporary2 = Level47_79AC4Field(temporary3, short *, 2);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 4);
    Level47_79AC4Keep(temporary2);
    argument0 = temporary3 - argument0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level47_79AC4_func_8004E880(argument0, argument1, argument2);
    Level47_79AC4Keep(temporary2);
    argument0 = owner + 0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary2 + 0;
    Level47_79AC4Keep(argument1);
    argument2 = 0 + 200;
    Level47_79AC4Keep(argument2);
    argument3 = 0 + 0;
    Level47_79AC4Keep(argument3);
    stackArgument4 = 0;
    stackArgument5 = 0;
    Level47_79AC4_func_80035EE0(argument0, argument1, argument2, argument3, stackArgument4,
                                stackArgument5);
    argument2 = 0 + 0;
    Level47_79AC4Keep(argument2);
    temporary3 = Level47_79AC4Field(privateState, int *, 28);
    Level47_79AC4Keep(temporary3);
    argument0 = Level47_79AC4Field(owner, int *, 12);
    Level47_79AC4Keep(argument0);
    argument1 = Level47_79AC4Field(owner, int *, 16);
    Level47_79AC4Keep(argument1);
    temporary2 = Level47_79AC4Field(temporary3, short *, 2);
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary3, int *, 12);
    Level47_79AC4Keep(temporary3);
    temporary2 = (int)((unsigned int)temporary2 << 4);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = Level47_79AC4Field(temporary2, int *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = Level47_79AC4Field(temporary2, int *, 4);
    Level47_79AC4Keep(temporary2);
    argument0 = temporary3 - argument0;
    Level47_79AC4Keep(argument0);
    argument1 = temporary2 - argument1;
    temporary2 = Level47_79AC4_func_8004E880(argument0, argument1, argument2);
    Level47_79AC4Keep(temporary2);
    argument0 = owner + 0;
    Level47_79AC4Keep(argument0);
    saved16 = temporary2 + 0;
    Level47_79AC4Keep(saved16);
    argument1 = saved16 + 0;
    Level47_79AC4Keep(argument1);
    argument2 = 0 + 4;
    Level47_79AC4Keep(argument2);
    argument3 = 0 + 0;
    Level47_79AC4Keep(argument3);
    temporary2 = 0 + 1;
    Level47_79AC4Keep(temporary2);
    stackArgument4 = temporary2;
    stackArgument5 = 0;
    Level47_79AC4_func_8003585C(argument0, argument1, argument2, argument3, stackArgument4,
                                stackArgument5);
    temporary2 = Level47_79AC4Field(privateState, int *, 24);
    Level47_79AC4Keep(temporary2);
    argument0 = owner + 12;
    Level47_79AC4Keep(argument0);
    argument1 = Level47_79AC4Field(temporary2, short *, 2);
    Level47_79AC4Keep(argument1);
    temporary2 = Level47_79AC4Field(temporary2, int *, 12);
    Level47_79AC4Keep(temporary2);
    argument1 = (int)((unsigned int)argument1 << 4);
    Level47_79AC4Keep(argument1);
    argument1 = temporary2 + argument1;
    temporary2 = Level47_79AC4_func_8004F334(argument0, argument1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 < 200;
    Level47_79AC4Keep(temporary2);
    if (temporary2 == 0)
        goto original1481_1414;
    argument0 = Level47_79AC4Field(privateState, int *, 24);
    Level47_79AC4Keep(argument0);

    temporary2 = Level47_79AC4Field(argument0, short *, 2);
    Level47_79AC4Keep(temporary2);
    argument1 = Level47_79AC4Field(argument0, short *, 10);
    Level47_79AC4Keep(argument1);
    temporary3 = Level47_79AC4Field(argument0, short *, 0);
    Level47_79AC4Keep(temporary3);
    temporary2 = temporary2 + argument1;
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 + temporary3;
    Level47_79AC4Keep(temporary2);
    temporary3 = temporary2 % temporary3;
    Level47_79AC4Keep(temporary3);

    Level47_79AC4Field(argument0, short *, 2) = temporary3;
original1481_1414:
    argument1 = Level47_79AC4Field(privateState, short *, 92);
    Level47_79AC4Keep(argument1);
    argument0 = saved16 + 0;
    temporary2 = Level47_79AC4_func_8004F264(argument0, argument1);
    Level47_79AC4Keep(temporary2);
    temporary2 = temporary2 < 4;
    Level47_79AC4Keep(temporary2);
original1481_1418:
    if (temporary2 == 0 ? (argument0 = owner + 0, 1) : (argument0 = owner + 0, 0))
        goto original1481Return;
    __asm__ volatile("" : "=r"(owner) : "0"(owner));
    Level47_79AC4Field(owner, unsigned char *, 72) = 0;
    argument1 = 0 + 0;
    Level47_79AC4_func_80034F40(argument0, argument1);

    goto original1481Return;
original1481_1425:
    temporary2 = (int)0x80070000U;
    Level47_79AC4Keep(temporary2);
    temporary2 = Level47_79AC4Field(temporary2, int *, -7356);
    Level47_79AC4Keep(temporary2);
    temporary3 = 0 + 1;
    Level47_79AC4Keep(temporary3);
    if (temporary2 == temporary3 ? (saved16 = privateState + 128, 1)
                                 : (saved16 = privateState + 128, 0))
        goto original1481Return;
    argument0 = saved16 + 0;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 4;
    Level47_79AC4Keep(argument1);
    saved17 = (int)&Level47_79AC4_D_8006D088;
    Level47_79AC4Keep(saved17);
    argument2 = saved17 + 0;
    Level47_79AC4Keep(argument2);
    Level47_79AC4Field(privateState, int *, 128) = temporary3;
    Level47_79AC4_func_8003B7B4(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 4;
    Level47_79AC4Keep(argument1);
    saved18 = (int)&Level47_79AC4_D_8006C7F8;
    Level47_79AC4Keep(saved18);
    argument2 = saved18 + 0;
    Level47_79AC4_func_8003B7B4(argument0, argument1, argument2);
    argument0 = owner + 0;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 4;
    Level47_79AC4Keep(argument1);
    temporary2 = 0 + 4;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(owner, unsigned char *, 72) = temporary2;
    Level47_79AC4_func_80034F40(argument0, argument1);
    saved16 = owner + 72;
    Level47_79AC4Keep(saved16);
    argument0 = saved16 + 0;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 1;
    Level47_79AC4Keep(argument1);
    argument2 = saved17 + 0;
    Level47_79AC4_func_8003B7B4(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 1;
    Level47_79AC4Keep(argument1);
    argument2 = saved18 + 0;
    Level47_79AC4_func_8003B7B4(argument0, argument1, argument2);
    saved16 = privateState + 94;
    Level47_79AC4Keep(saved16);
    argument0 = saved16 + 0;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 2;
    Level47_79AC4Keep(argument1);
    argument2 = saved17 + 0;
    Level47_79AC4Keep(argument2);
    temporary2 = 0 + 120;
    Level47_79AC4Keep(temporary2);
    Level47_79AC4Field(privateState, short *, 94) = temporary2;
    Level47_79AC4_func_8003B7B4(argument0, argument1, argument2);
    argument0 = saved16 + 0;
    Level47_79AC4Keep(argument0);
    argument1 = 0 + 2;
    Level47_79AC4Keep(argument1);
    argument2 = saved18 + 0;
    Level47_79AC4_func_8003B7B4(argument0, argument1, argument2);
original1481Return:
    return;
}
#undef Level47_79AC4Field
#undef Level47_79AC4Keep
#undef Level47_79AC4Low


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007B1E8.
* AI generated; not human reviewed. All894 original instructions,5 actual
* selectors and one zero padding word must match, including destinations.
* Frame58 saves S0..S3/RA; complete original SP20..3F locals are retained.
* Original irregular substate dispatch has distinct0/1/2 physical entries;
* decoder else-if placement originally moved state1 after state2. Shared
* owner state1/state2 stores remain at421..423 and623..625. Distinct full
* initialized value markers keep both joins without copying CPU opcodes.
* Player distance+8 entry, independent250 pointer test, low32 linked-vector
* loads and signed SRA2 consumers retain original load widths and ordering.
* Original HUD result's signed16 consumer is explicit after the known int
* helper return. Callback symbols retain their exact original addresses.
* Original signed trig225/SRA12,120 store, final127 byte write and original
* linked-record producer retain their original order and actual data views.
* Empty metadata uses complete initialized values or clobbers dead registers
* before new producers; zero CPU instructions. No opcode assembly,partialHI,
* fixedFP, undefined saved inputs, overlapping aliases or pipeline changes.
* Units/fixed point, full helper/caller chains, cadence beyond invocation
* and synchronized retail runtime remain open. Confidence is binary identity
* after all gates. Next evidence: human review and retail runtime captures.
* Falsification: all native/linked words, actual transfer/table targets,
* original owned data, full EXE and every overlay retail hash must match.
*/
/* Original assembly SHA256 ca7e659160f8426365da4dca48e80583dffe0b9c6d271d8cb62d89f16213e40b */
extern int Level47_7B1E8Call27E40View1 __asm__("func_80027E40");
extern int Level47_7B1E8Call27A60View1 __asm__("func_80027A60");
extern int Level47_7B1E8Call29904View1 __asm__("func_80029904");
#define Level47_7B1E8Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level47_7B1E8Call1A358View1() __asm__("func_8001A358");
int Level47_7B1E8Call2803CView1() __asm__("func_8002803C");
int Level47_7B1E8Call28154View1() __asm__("func_80028154");
void Level47_7B1E8Call34F40View1(void*, int) __asm__("func_80034F40");
int Level47_7B1E8Call34F80View1() __asm__("func_80034F80");
int Level47_7B1E8Call359A4View1(void*, int) __asm__("func_800359A4");
int Level47_7B1E8Call35D38View1() __asm__("func_80035D38");
int Level47_7B1E8Call35EE0View1() __asm__("func_80035EE0");
int Level47_7B1E8Call3BABCView1() __asm__("func_8003BABC");
int Level47_7B1E8Call3BE70View1() __asm__("func_8003BE70");
int Level47_7B1E8Call3BFC0View1() __asm__("func_8003BFC0");
int Level47_7B1E8Call48210View1() __asm__("func_80048210");
int Level47_7B1E8Call4E880View1(int, int, int) __asm__("func_8004E880");
int Level47_7B1E8Call4F178View1() __asm__("func_8004F178");
int Level47_7B1E8Call4F334View1() __asm__("func_8004F334");
int Level47_7B1E8Call55B18View1() __asm__("func_80055B18");
int Level47_7B1E8Call55D24View1() __asm__("func_80055D24");
int Level47_7B1E8Call55E84View1() __asm__("func_80055E84");
int Level47_7B1E8Call5629CView1() __asm__("func_8005629C");
extern int Level47_7B1E8Data658A0View1 __asm__("D_800658A0");
extern int Level47_7B1E8Data65920View1 __asm__("D_80065920");
extern int Level47_7B1E8Data6C550View1 __asm__("D_8006C550");
extern int Level47_7B1E8Data6C770View1 __asm__("D_8006C770");
extern int Level47_7B1E8Data6E160View1 __asm__("D_8006E160");
extern int Level47_7B1E8Data6E538View1 __asm__("D_8006E538");
extern int Level47_7B1E8Data6E53CView1 __asm__("D_8006E53C");
extern int Level47_7B1E8Data70328View1 __asm__("D_80070328");
extern void*(*Level47_7B1E8DataSpawnMobyView1)(int, void*) __asm__("SpawnMoby");
void func_level_47_8007B1E8(void *input) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6");
    register void *ownerRecord18 __asm__("$18");
    register int privateRecord19 __asm__("$19"), retainedVector16 __asm__("$16"), retainedLinkedRecord17 __asm__("$17");
    struct{
        int sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C;
    }
    originalFrame;
    int temporaryWord11;
    int temporaryWord15;
    int temporaryWord8;
    int temporaryWord14;
    int temporaryWord16;
    int temporaryWord17;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord9;
    int temporaryWord10;
    int temporaryWord12;
    int temporaryWord13;
    int temporaryWord18;
    ownerRecord18 = input;
    __asm__("":"=r"(ownerRecord18):"0"(ownerRecord18));
    argumentWord5 = Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x49);
    privateRecord19 = Level47_7B1E8Field(ownerRecord18, int *, 0);
    switch (argumentWord5) {
    case 0:
        if (({rawWord2 = Level47_7B1E8Field(ownerRecord18, unsigned char*, 72);__asm__("":"=r"(rawWord2):"0"(rawWord2));argumentWord4 = (int)ownerRecord18;rawWord2 == 0;})) {
            argumentWord5 = 2;
            Level47_7B1E8Field(ownerRecord18, signed char *, 0x41) = 0;
            Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x4C) = 0U;
            Level47_7B1E8Field(ownerRecord18, signed char *, 0x4D) = 0;
            Level47_7B1E8Field(ownerRecord18, int *, 0x14) = 0x1400;
            Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x4F) = 0U;
            goto callSharedOriginalStateHelper;
        }
        if (({rawWord2 = Level47_7B1E8Field(ownerRecord18, unsigned char*, 76);__asm__("":"=r"(rawWord2):"0"(rawWord2));argumentWord4 = 750;rawWord2 != 0;})) {
            argumentWord5 = (int)ownerRecord18;
            rawWord2 = 1;
            Level47_7B1E8Field(argumentWord5, unsigned char*, 72) = 0;
            __asm__("":::"memory");
            Level47_7B1E8Field(argumentWord5, unsigned char*, 73) = rawWord2;
            rawWord3 = (int)Level47_7B1E8DataSpawnMobyView1;
            __asm__("":::"$2", "memory");
            rawWord2 = 10;
            Level47_7B1E8Field(privateRecord19, int*, 28) = rawWord2;
            rawWord2 = ((int(*)())rawWord3)(argumentWord4, argumentWord5);
            Level47_7B1E8Field(privateRecord19, int*, 16) = rawWord2;
            return;
        }
    default:
        return;
    case 1:
        argumentWord4 = Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x48);
        Level47_7B1E8Field(ownerRecord18, int *, 0x1C) = (int) (Level47_7B1E8Field(ownerRecord18, int *, 0x1C) & 0x7FFFFFFF);
        if (argumentWord4 == argumentWord5) goto originalSubstateOne;
        if (argumentWord4 >= 2) goto testOriginalSubstateTwo;
        if (argumentWord4 == 0) goto originalSubstateZero;
        return;
        testOriginalSubstateTwo:if (argumentWord4 == 2) goto originalSubstateTwo;
        return;
        originalSubstateZero:;
        retainedLinkedRecord17 = Level47_7B1E8Field(((Level47_7B1E8Field(privateRecord19, int *, 0) * 0x58) + Level47_7B1E8Data6C550View1), int*, 0);
        temporaryWord10 = (Level47_7B1E8Field(privateRecord19, unsigned char *, 4) * 0x10) + Level47_7B1E8Field(Level47_7B1E8Field(retainedLinkedRecord17, int *, 0x24), int *, 0xC);
        Level47_7B1E8Call35EE0View1(ownerRecord18, Level47_7B1E8Call4E880View1(Level47_7B1E8Field(temporaryWord10, int *, 0) - Level47_7B1E8Field(ownerRecord18, int *, 0xC), Level47_7B1E8Field(temporaryWord10, int *, 4) - Level47_7B1E8Field(ownerRecord18, int *, 0x10), 0), 0x32, 0, 0, 0);
        Level47_7B1E8Call55D24View1(ownerRecord18, 6);
        retainedVector16 = ownerRecord18 + 0xC;
        Level47_7B1E8Call1A358View1(retainedVector16, 0x2800);
        Level47_7B1E8Call5629CView1(ownerRecord18);
        rawWord2 = Level47_7B1E8Call4F334View1(retainedVector16, Level47_7B1E8Field(Level47_7B1E8Field(retainedLinkedRecord17, int*, 36), int*, 12)+Level47_7B1E8Field(privateRecord19, unsigned char*, 4)*16);
        rawWord2 = rawWord2 < 1024;
        if (rawWord2){
            rawWord2 = 1;
            __asm__ volatile(""::"r"(rawWord2));
            goto originalHaveState1;
        }
        rawWord2 = 1;
        return;
    originalSubstateOne:
        if (({rawWord2 = Level47_7B1E8Field(privateRecord19, int*, 16);__asm__("":"=r"(rawWord2):"0"(rawWord2));argumentWord4 = 166;rawWord2 == 0;})){
            rawWord2 = (int)Level47_7B1E8DataSpawnMobyView1;
            argumentWord5 = (int)ownerRecord18;
            Level47_7B1E8Field(ownerRecord18, int*, 24) = 0;
            temporaryWord12 = ((int(*)())rawWord2)(argumentWord4, argumentWord5);
            Level47_7B1E8Field(privateRecord19, int *, 0x28) = temporaryWord12;
            if (temporaryWord12 != 0) {
                Level47_7B1E8Field(temporaryWord12, unsigned char *, 0x4C) = (unsigned char) Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x4C);
                Level47_7B1E8Field(Level47_7B1E8Field(privateRecord19, int *, 0x28), unsigned char *, 0x4E) = (unsigned char) Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x4C);
                temporaryWord6 = Level47_7B1E8Field(privateRecord19, int *, 0x28);
                Level47_7B1E8Field(temporaryWord6, int *, 0x1C) = (int) (Level47_7B1E8Field(temporaryWord6, int *, 0x1C) | 0x80000000);
                Level47_7B1E8Call1A358View1(Level47_7B1E8Field(privateRecord19, int *, 0x28) + 0xC, 0x2800);
                Level47_7B1E8Call5629CView1(Level47_7B1E8Field(privateRecord19, int *, 0x28));
                Level47_7B1E8Field(Level47_7B1E8Field(privateRecord19, int *, 0x28), unsigned char *, 0x46) = (unsigned char) Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x46);
                Level47_7B1E8Field(ownerRecord18, int *, 0x14) = 0x1400;
                Level47_7B1E8Call55D24View1(ownerRecord18, 2);
                Level47_7B1E8Field(privateRecord19, int *, 0x20) = (int) Level47_7B1E8Field(Level47_7B1E8Field(((Level47_7B1E8Field(privateRecord19, int *, 0x18) * 0x58) + Level47_7B1E8Data6C550View1), int*, 0), int *, 0x24);
                goto prepareOriginalOwnerState2;
            }
        }
        return;
    originalSubstateTwo:
        argumentWord5 = Level47_7B1E8Field(Level47_7B1E8Field(privateRecord19, int*, 0)*88+Level47_7B1E8Data6C550View1, int*, 0);
        argumentWord4 = Level47_7B1E8Field(privateRecord19, int*, 40);
        rawWord3 = Level47_7B1E8Field(argumentWord5, int*, 36);
        rawWord2 = Level47_7B1E8Field(privateRecord19, unsigned char*, 4);
        rawWord3 = Level47_7B1E8Field(rawWord3, int*, 12);
        rawWord2 *= 16;
        rawWord2 += rawWord3;
        rawWord2 = Level47_7B1E8Field(rawWord2, int*, 0);
        __asm__("":::"$3", "memory");
        rawWord3 = Level47_7B1E8Field(argumentWord4, int*, 12);
        rawWord2 -= rawWord3;
        rawWord2 >>= 2;
        rawWord3 += rawWord2;
        Level47_7B1E8Field(argumentWord4, int*, 12) = rawWord3;
        rawWord3 = Level47_7B1E8Field(argumentWord5, int*, 36);
        __asm__("":::"$2", "memory");
        rawWord2 = Level47_7B1E8Field(privateRecord19, unsigned char*, 4);
        __asm__("":::"$4", "memory");
        argumentWord4 = Level47_7B1E8Field(privateRecord19, int*, 40);
        rawWord3 = Level47_7B1E8Field(rawWord3, int*, 12);
        rawWord2 *= 16;
        rawWord2 += rawWord3;
        rawWord2 = Level47_7B1E8Field(rawWord2, int*, 4);
        __asm__("":::"$3", "memory");
        rawWord3 = Level47_7B1E8Field(argumentWord4, int*, 16);
        rawWord2 -= rawWord3;
        rawWord2 >>= 2;
        rawWord3 += rawWord2;
        Level47_7B1E8Field(argumentWord4, int*, 16) = rawWord3;
        temporaryWord4 = Level47_7B1E8Field(privateRecord19, int *, 0x28);
        Level47_7B1E8Field(temporaryWord4, int *, 0x14) = (int) (Level47_7B1E8Field(temporaryWord4, int *, 0x14) + Level47_7B1E8Field(privateRecord19, int *, 0xC));
        temporaryWord5 = Level47_7B1E8Field(privateRecord19, int *, 0x28);
        temporaryWord15 = Level47_7B1E8Field(privateRecord19, int *, 8);
        Level47_7B1E8Field(privateRecord19, int *, 0xC) = (int) (Level47_7B1E8Field(privateRecord19, int *, 0xC) - 0x14);
        if (Level47_7B1E8Field(temporaryWord5, int *, 0x14) < temporaryWord15) {
            Level47_7B1E8Field(temporaryWord5, int *, 0x14) = temporaryWord15;
            temporaryWord11 = (int) -Level47_7B1E8Field(privateRecord19, int *, 0xC) >> 3;
            Level47_7B1E8Field(privateRecord19, int *, 0xC) = temporaryWord11;
            if (temporaryWord11 < 0x20) {
                Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x49) = 2U;
                Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x48) = 0U;
                return;
            }
        }
        return;
        break;
    case 2:
        if (Level47_7B1E8Field(ownerRecord18, int *, 0x18) & 0x140000) {
            temporaryWord16 = Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x48);
            if ((temporaryWord16 == 1) || (temporaryWord16 == 4) || (temporaryWord16 == argumentWord5)) {
                Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x24) = (int) (Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x24) | 0x80);
                Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x298) = (int) (Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x46) + 0x80);
                Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x21C) = (int) ((int) (Level47_7B1E8Field((int)&Level47_7B1E8Data65920View1, short*, (Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x46) * 2)) * 0xE1) >> 0xC);
                rawWord3 = Level47_7B1E8Field((int)&Level47_7B1E8Data658A0View1, short*, Level47_7B1E8Field(ownerRecord18, unsigned char*, 70)*2);
                __asm__("":::"$2", "memory");
                rawWord2 = 120;
                Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int*, 548) = rawWord2;
                __asm__("":"=r"(rawWord3):"0"(rawWord3), "r"(rawWord2):"memory");
                Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int*, 544) = (rawWord3*225) >> 12;
                Level47_7B1E8Call28154View1(Level47_7B1E8Field(privateRecord19, int *, 0x24), argumentWord5);
                Level47_7B1E8Field(privateRecord19, int *, 0x24) = -1;
                goto checkOriginalOwnerState;
            }
            if (temporaryWord16 != 3) {
                temporaryWord7 = Level47_7B1E8Field(privateRecord19, int *, 0x28);
                if (temporaryWord7 != 0) {
                    retainedVector16 = Level47_7B1E8Field(temporaryWord7, int *, 0x14);
                    if (retainedVector16 == 0x1400) {
                        Level47_7B1E8Call4F178View1(temporaryWord7 + 0xC, ownerRecord18 + 0xC);
                        Level47_7B1E8Field(ownerRecord18, int *, 0x14) = retainedVector16;
                        Level47_7B1E8Call55D24View1(ownerRecord18, 6);
                    }
                    Level47_7B1E8Field(Level47_7B1E8Field(privateRecord19, int *, 0x28), unsigned char *, 0x46) = (unsigned char) Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x46);
                    Level47_7B1E8Field(Level47_7B1E8Field(privateRecord19, int *, 0x28), unsigned char *, 0x4F) = 0x20U;
                }
                Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x48) = 3U;
                Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x4F) = 0x20U;
                Level47_7B1E8Field(ownerRecord18, int *, 0x18) = 0;
                goto checkOriginalOwnerState;
            }
        }
        else {
        checkOriginalOwnerState:
            temporaryWord8 = Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x48);
            if ((temporaryWord8 != 3) && (Level47_7B1E8Field(privateRecord19, int *, 0x20) != Level47_7B1E8Field(Level47_7B1E8Field(((Level47_7B1E8Field(privateRecord19, int *, 0x18) * 0x58) + Level47_7B1E8Data6C550View1), int*, 0), int *, 0x24)) && (temporaryWord8 != 1) && (temporaryWord8 != 4) && (temporaryWord8 != 2)) {
                temporaryWord9 = Level47_7B1E8Field(privateRecord19, int *, 0x28);
                if (temporaryWord9 != 0) {
                    retainedVector16 = Level47_7B1E8Field(temporaryWord9, int *, 0x14);
                    if (retainedVector16 == 0x1400) {
                        Level47_7B1E8Call4F178View1(temporaryWord9 + 0xC, ownerRecord18 + 0xC);
                        Level47_7B1E8Field(ownerRecord18, int *, 0x14) = retainedVector16;
                        Level47_7B1E8Call55D24View1(ownerRecord18, 6);
                    }
                    Level47_7B1E8Field(Level47_7B1E8Field(privateRecord19, int *, 0x28), unsigned char *, 0x4F) = 0x20U;
                    Level47_7B1E8Field(Level47_7B1E8Field(privateRecord19, int *, 0x28), unsigned char *, 0x46) = (unsigned char) Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x46);
                }
                Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x48) = 3U;
                Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x4F) = 0x20U;
            }
        }
        temporaryWord17 = Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x48);
        switch (temporaryWord17) {
        case 0:
            argumentWord5 = (int)&Level47_7B1E8Data70328View1+8;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            rawWord2 = Level47_7B1E8Field(argumentWord5, int*, 0);
            rawWord3 = Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int*, 68);
            argumentWord6 = Level47_7B1E8Field(privateRecord19, int*, 40);
            rawWord2 -= rawWord3;
            rawWord3 = Level47_7B1E8Field(argumentWord6, int*, 20);
            __asm__("":::"$4", "memory");
            argumentWord4 = Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int*, 592);
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            if (argumentWord4) return;
            rawWord2 -= rawWord3;
            rawWord2 -= 1;
            if ((unsigned int)rawWord2 >= 319){
                argumentWord4 = argumentWord6+12;
                return;
            }
            argumentWord4 = argumentWord6+12;
            argumentWord5 -= 8;
            rawWord2 = Level47_7B1E8Call4F334View1(argumentWord4, argumentWord5);
            if (rawWord2 >= 768){
                argumentWord4 = (int)ownerRecord18+12;
                return;
            }
            argumentWord4 = (int)ownerRecord18+12;
            argumentWord5 = Level47_7B1E8Field(privateRecord19, int*, 40);
            argumentWord5 += 12;
            Level47_7B1E8Call4F178View1(argumentWord4, argumentWord5);
            argumentWord4 = (int)ownerRecord18;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4):"$5", "memory");
            argumentWord5 = 6;
            rawWord3 = Level47_7B1E8Field(privateRecord19, int*, 40);
            rawWord2 = 5120;
            Level47_7B1E8Field(rawWord3, int*, 20) = rawWord2;
            callSharedOriginalStateHelper:Level47_7B1E8Call55D24View1(argumentWord4, argumentWord5);
            prepareOriginalOwnerState1:rawWord2 = 1;
            originalHaveState1:__asm__ volatile("":"=r"(rawWord2):"0"(rawWord2), "i"(1));
            Level47_7B1E8Field(ownerRecord18, unsigned char*, 72) = rawWord2;
            return;
        case 1:
            if (Level47_7B1E8Call3BFC0View1(ownerRecord18, Level47_7B1E8Field(privateRecord19, int *, 0x2C)) == 0) {
                Level47_7B1E8Field(privateRecord19, int *, 0x2C) = Level47_7B1E8Call3BABCView1(ownerRecord18, 0, 4);
            }
            Level47_7B1E8Field(Level47_7B1E8Field(privateRecord19, int *, 0x14), int*, 0) = ownerRecord18;
            if ((Level47_7B1E8Data6E53CView1 & 0x40) || (Level47_7B1E8Field(privateRecord19, int *, 0x20) != Level47_7B1E8Field(Level47_7B1E8Field(((Level47_7B1E8Field(privateRecord19, int *, 0x18) * 0x58) + Level47_7B1E8Data6C550View1), int*, 0), int *, 0x24)) || ((unsigned int) (Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x50) - 7) < 2U) || (Level47_7B1E8Data6E160View1 != 0xD) || (Level47_7B1E8Call4F334View1(ownerRecord18 + 0xC, ((int)&Level47_7B1E8Data70328View1 + 0x50) - 0x50) >= 0x301) || ((Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0xB8) == 0) && (Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x13C) != ownerRecord18))) {
                Level47_7B1E8Call4F178View1(Level47_7B1E8Field(privateRecord19, int *, 0x28) + 0xC, ownerRecord18 + 0xC);
                Level47_7B1E8Field(ownerRecord18, int *, 0x14) = 0x1400;
                Level47_7B1E8Call55D24View1(ownerRecord18, 6);
                if (Level47_7B1E8Call3BFC0View1(ownerRecord18, Level47_7B1E8Field(privateRecord19, int *, 0x2C)) != 0) {
                    Level47_7B1E8Call3BE70View1(Level47_7B1E8Field(privateRecord19, int *, 0x2C));
                }
                Level47_7B1E8Field(privateRecord19, int *, 0x2C) = -1;
                Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x48) = 0U;
                Level47_7B1E8Field(Level47_7B1E8Field(privateRecord19, int *, 0x14), int*, 0) = 0;
                return;
            }
            if (Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x214) == 2) {
                if (Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x13C) == ownerRecord18) {
                    Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x23C) = 0x3C;
                    Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x250) = ownerRecord18;
                    Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x20C) = (int) (Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x20C) | 0x10000080);
                    Level47_7B1E8Field(privateRecord19, unsigned char *, 5) = 0U;
                    Level47_7B1E8Field(privateRecord19, signed char *, 6) = 0;
                    Level47_7B1E8Field(privateRecord19, int *, 0x24) = (int)(short) Level47_7B1E8Call2803CView1(0x15, 0x1D8, &Level47_7B1E8Call27E40View1, &Level47_7B1E8Call27A60View1, &Level47_7B1E8Call29904View1, privateRecord19 + 0x1C, Level47_7B1E8Field(privateRecord19, int *, 0x1C));
                    Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x48) = 4U;
                    return;
                }
                goto updateOriginalPlayerDescriptor;
            }
        updateOriginalPlayerDescriptor:
            Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x20C) = 0x10000040;
            Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x218) = ownerRecord18;
            Level47_7B1E8Call4F178View1((int)&Level47_7B1E8Data70328View1 + 0x20C + 0x20, ownerRecord18 + 0xC);
            Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x238) = (int) Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x46);
            return;
        case 4:
            if (Level47_7B1E8Call3BFC0View1(ownerRecord18, Level47_7B1E8Field(privateRecord19, int *, 0x2C)) == 0) {
                Level47_7B1E8Field(privateRecord19, int *, 0x2C) = Level47_7B1E8Call3BABCView1(ownerRecord18, 0, 4);
            }
            if ((Level47_7B1E8Field(privateRecord19, int *, 0x20) != Level47_7B1E8Field(Level47_7B1E8Field(((Level47_7B1E8Field(privateRecord19, int *, 0x18) * 0x58) + Level47_7B1E8Data6C550View1), int*, 0), int *, 0x24)) || (Level47_7B1E8Data6E538View1 & 0x40) || (Level47_7B1E8Field(privateRecord19, int *, 0x1C) < 0)) {
                Level47_7B1E8Call4F178View1(&originalFrame.sp20, (int)&Level47_7B1E8Data70328View1);
                rawWord2 = Level47_7B1E8Call1A358View1(&originalFrame.sp20, 0x800);
                argumentWord4 = (int)&originalFrame.sp20;
                __asm__("":"=r"(argumentWord4):"0"(argumentWord4), "r"(rawWord2));
                originalFrame.sp28 = rawWord2;
                Level47_7B1E8Call48210View1(argumentWord4);
                rawWord2 = 2;
                goto storeOriginalOwnerState2;
            }
            if ((unsigned int)(Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int*, 80)-7) < 2U){
                prepareOriginalOwnerState2:rawWord2 = 2;
                storeOriginalOwnerState2:__asm__ volatile("":"=r"(rawWord2):"0"(rawWord2), "i"(2));
                Level47_7B1E8Field(ownerRecord18, unsigned char*, 72) = rawWord2;
                return;
            }
            if (Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x50) == 0x12) {
                temporaryWord1 = Level47_7B1E8Field(privateRecord19, int *, 0x28);
                Level47_7B1E8Field(temporaryWord1, int *, 0x1C) = (int) (Level47_7B1E8Field(temporaryWord1, int *, 0x1C) & 0x7FFFFFFF);
                Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x48) = 2U;
                Level47_7B1E8Field(ownerRecord18, int *, 0x1C) = (int) (Level47_7B1E8Field(ownerRecord18, int *, 0x1C) | 0x80000000);
                return;
            }
            Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x23C) = 0x3C;
            Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x250) = ownerRecord18;
            Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x20C) = (int) (Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x20C) | 0x10000080);
            return;
        case 2:
            if (Level47_7B1E8Call3BFC0View1(ownerRecord18, Level47_7B1E8Field(privateRecord19, int *, 0x2C)) == 0) {
                Level47_7B1E8Field(privateRecord19, int *, 0x2C) = Level47_7B1E8Call3BABCView1(ownerRecord18, 0, 4);
            }
            Level47_7B1E8Call55D24View1(ownerRecord18, 6);
            Level47_7B1E8Call35D38View1(ownerRecord18);
            Level47_7B1E8Call5629CView1(ownerRecord18);
            if (Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x50) != 0x12) {
                Level47_7B1E8Field((int)&Level47_7B1E8Data70328View1, int *, 0x250) = 0;
                Level47_7B1E8Field(ownerRecord18, int *, 0x1C) = (int) (Level47_7B1E8Field(ownerRecord18, int *, 0x1C) & 0x7FFFFFFF);
                Level47_7B1E8Call4F178View1(Level47_7B1E8Field(privateRecord19, int *, 0x28) + 0xC, ownerRecord18 + 0xC);
                temporaryWord2 = Level47_7B1E8Field(privateRecord19, int *, 0x28);
                Level47_7B1E8Field(temporaryWord2, int *, 0x1C) = (int) (Level47_7B1E8Field(temporaryWord2, int *, 0x1C) | 0x80000000);
                Level47_7B1E8Field(Level47_7B1E8Field(privateRecord19, int *, 0x28), unsigned char *, 0x46) = (unsigned char) Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x46);
                Level47_7B1E8Field(Level47_7B1E8Field(privateRecord19, int *, 0x28), unsigned char *, 0x4F) = 0x20U;
                Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x4F) = 0x20U;
                if (Level47_7B1E8Call3BFC0View1(ownerRecord18, Level47_7B1E8Field(privateRecord19, int *, 0x2C)) != 0) {
                    Level47_7B1E8Call3BE70View1(Level47_7B1E8Field(privateRecord19, int *, 0x2C));
                }
                Level47_7B1E8Field(privateRecord19, int *, 0x2C) = -1;
                Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x48) = 3U;
                Level47_7B1E8Field(Level47_7B1E8Field(privateRecord19, int *, 0x14), int*, 0) = 0;
                Level47_7B1E8Call28154View1(Level47_7B1E8Field(privateRecord19, int *, 0x24));
                Level47_7B1E8Field(privateRecord19, int *, 0x24) = -1;
                return;
            }
            if ((Level47_7B1E8Field(privateRecord19, int *, 0x20) != Level47_7B1E8Field(Level47_7B1E8Field(((Level47_7B1E8Field(privateRecord19, int *, 0x18) * 0x58) + Level47_7B1E8Data6C550View1), int*, 0), int *, 0x24)) || (Level47_7B1E8Data6E538View1 & 0x40) || (Level47_7B1E8Field(privateRecord19, int *, 0x1C) < 0)) {
                Level47_7B1E8Call4F178View1(&originalFrame.sp30, (int)&Level47_7B1E8Data70328View1);
                originalFrame.sp38 = Level47_7B1E8Call1A358View1(&originalFrame.sp30, 0x800);
                Level47_7B1E8Call48210View1(&originalFrame.sp30);
            }
            if ((Level47_7B1E8Call359A4View1(privateRecord19 + 6, 1) != 0) && (Level47_7B1E8Data6E538View1 & 0x20)) {
                Level47_7B1E8Call34F80View1(ownerRecord18, 1);
                Level47_7B1E8Field(ownerRecord18, signed char *, 0x3E) = 0;
                Level47_7B1E8Field(ownerRecord18, signed char *, 0x3F) = 1;
                Level47_7B1E8Field(privateRecord19, signed char *, 6) = 0x32;
                Level47_7B1E8Field(privateRecord19, int *, 0x1C) = (int) (Level47_7B1E8Field(privateRecord19, int *, 0x1C) - 1);
            }
            if (Level47_7B1E8Field(ownerRecord18, unsigned short *, 0x3C) == 0x101) {
                if ((Level47_7B1E8Call55E84View1(ownerRecord18) >= 4) && (Level47_7B1E8Field(privateRecord19, unsigned char *, 5) == 0)) {
                    temporaryWord13 = Level47_7B1E8DataSpawnMobyView1(0x254, ownerRecord18);
                    if (temporaryWord13 != 0) {
                        Level47_7B1E8Call3BABCView1(ownerRecord18, 1, 0);
                        Level47_7B1E8Field(temporaryWord13, int *, 8) = 0;
                        Level47_7B1E8Field(privateRecord19, unsigned char *, 5) = 1U;
                    }
                }
                if (Level47_7B1E8Data6C770View1 != 0) {
                    if (Level47_7B1E8Field(privateRecord19, int *, 0x1C) == 0) {
                        Level47_7B1E8Field(privateRecord19, int *, 0x1C) = -1;
                    }
                    Level47_7B1E8Field(privateRecord19, unsigned char *, 5) = 0U;
                    Level47_7B1E8Call34F40View1(ownerRecord18, 0);
                    return;
                }
            }
            break;
        case 3:
            if (Level47_7B1E8Call3BFC0View1(ownerRecord18, Level47_7B1E8Field(privateRecord19, int *, 0x2C)) != 0) {
                Level47_7B1E8Call3BE70View1(Level47_7B1E8Field(privateRecord19, int *, 0x2C));
            }
            __asm__ volatile("":::"$2", "memory");
            rawWord3 = Level47_7B1E8Data6C770View1;
            rawWord2 = -1;
            Level47_7B1E8Field(privateRecord19, int*, 44) = rawWord2;
            if (rawWord3 != 0) {
                Level47_7B1E8Field(privateRecord19, unsigned char *, 5) = 0U;
                Level47_7B1E8Call34F40View1(ownerRecord18, 0);
            }
            temporaryWord14 = Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x4F) + 4;
            Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x4F) = temporaryWord14;
            temporaryWord18 = Level47_7B1E8Field(privateRecord19, int *, 0x28);
            if (temporaryWord18 != 0) {
                Level47_7B1E8Field(temporaryWord18, unsigned char *, 0x4F) = temporaryWord14;
            }
            if ((unsigned char) Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x4F) >= 0x2CU) {
                Level47_7B1E8Field(ownerRecord18, int *, 0x14) = 0x1400;
                Level47_7B1E8Call55D24View1(ownerRecord18, 6);
            }
            if ((unsigned char) Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x4F) >= 0x80U) {
                rawWord3 = Level47_7B1E8Field(Level47_7B1E8Field(privateRecord19, int*, 0)*88+Level47_7B1E8Data6C550View1, int*, 0);
                __asm__("":::"$2", "memory");
                rawWord2 = 127;
                Level47_7B1E8Field(ownerRecord18, unsigned char*, 79) = rawWord2;
                Level47_7B1E8Field(Level47_7B1E8Field(privateRecord19, unsigned char*, 4)*16+Level47_7B1E8Field(Level47_7B1E8Field(rawWord3, int*, 36), int*, 12), int*, 12) = 0;
                Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x49) = 0U;
                Level47_7B1E8Field(ownerRecord18, unsigned char *, 0x48) = 0U;
                temporaryWord3 = Level47_7B1E8Field(privateRecord19, int *, 0x28);
                if (temporaryWord3 != 0) {
                    Level47_7B1E8Call55B18View1(temporaryWord3);
                    Level47_7B1E8Field(privateRecord19, int *, 0x28) = 0;
                }
            }
            break;
        }
        break;
    }
}
#undef Level47_7B1E8Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007BFE0.
* AI generated; not human reviewed. All924 original instructions and actual
* destinations must match. Frame50 saves S0..S4/RA,SP20..37 locals retained.
* Related8007B1E8 supplies the verified full vector/spawn pattern; this
* function retains its own linked descriptor32 and child56 byte offsets.
* Original0/1/2/4 physical owner entries remain in order. Reset645..696
* precedes live697..791. Original9/11 mode branches reuse V1 at536; only
* the default helper path reloads global mode534 before the mode14 test.
* The raw decoder's stale pre-call default value is not used. Original619
* supplies complete13 in V1 for the direct live entry. Saved S0 retains
* the original mode address, not a cached mutable mode value across calls.
* Complete player-height difference survives its helper; V0 holds range
* predicates. Original descriptor byte/zero order and independent masked
* words remain. One private+6 producer after the join retains762/776 delay
* copies. Shared shifted-byte store remains911..914, not in early case0.
* Original HUD signed16 consumer, spawn callbacks, load widths, signed
* shifts, full products and original global addresses remain unchanged.
* Empty metadata consumes full initialized values or clobbers only before
* new producers; zero CPU instructions. No opcode assembly,partialHI,
* fixedFP, undefined saved inputs, overlapping aliases or pipeline changes.
* Units/fixed point, full helper/caller chains, cadence beyond invocation
* and synchronized runtime remain open. Confidence is binary identity after
* all gates. Next: human review and synchronized retail runtime captures.
* Falsification: every native/linked word, actual transfer target, owned
* data, full EXE and every overlay retail hash must remain identical.
*/
/* Original assembly SHA256 0978d48fc24f7c94c779c3d72f21289a2d668bb85574dfdd99b3728d20e677a2 */
extern int Level47_7BFE0Call27E40View1 __asm__("func_80027E40");
extern int Level47_7BFE0Call27A60View1 __asm__("func_80027A60");
extern int Level47_7BFE0Call29904View1 __asm__("func_80029904");
#define Level47_7BFE0Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level47_7BFE0Call13ACCView1() __asm__("func_80013ACC");
int Level47_7BFE0Call1A358View1() __asm__("func_8001A358");
int Level47_7BFE0Call2803CView1() __asm__("func_8002803C");
int Level47_7BFE0Call28154View1() __asm__("func_80028154");
int Level47_7BFE0Call359A4View1(void*, int) __asm__("func_800359A4");
int Level47_7BFE0Call35D38View1() __asm__("func_80035D38");
int Level47_7BFE0Call35EE0View1() __asm__("func_80035EE0");
int Level47_7BFE0Call3BABCView1() __asm__("func_8003BABC");
int Level47_7BFE0Call3BE70View1() __asm__("func_8003BE70");
int Level47_7BFE0Call3BFC0View1() __asm__("func_8003BFC0");
int Level47_7BFE0Call410F8View1() __asm__("func_800410F8");
int Level47_7BFE0Call48210View1() __asm__("func_80048210");
int Level47_7BFE0Call4E880View1(int, int, int) __asm__("func_8004E880");
int Level47_7BFE0Call4F168View1() __asm__("func_8004F168");
int Level47_7BFE0Call4F178View1() __asm__("func_8004F178");
int Level47_7BFE0Call4F334View1() __asm__("func_8004F334");
int Level47_7BFE0Call55B18View1() __asm__("func_80055B18");
int Level47_7BFE0Call55D24View1() __asm__("func_80055D24");
int Level47_7BFE0Call5629CView1() __asm__("func_8005629C");
extern int Level47_7BFE0Data6C550View1 __asm__("D_8006C550");
extern int Level47_7BFE0Data6E160View1 __asm__("D_8006E160");
extern int Level47_7BFE0Data6E53CView1 __asm__("D_8006E53C");
extern int Level47_7BFE0Data70328View1 __asm__("D_80070328");
extern void*(*Level47_7BFE0DataSpawnMobyView1)(int, void*) __asm__("SpawnMoby");
void func_level_47_8007BFE0(void *input) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6");
    register void *ownerRecord18 __asm__("$18");
    register int privateRecord19 __asm__("$19"), retainedDistanceOrModeAddress16 __asm__("$16"), retainedLinkedOrPlayerAddress17 __asm__("$17"), retainedOldValue20 __asm__("$20");
    struct{
        int sp20, sp24, sp28, sp2C, sp30, sp34;
    }
    originalFrame;
    int temporaryWord9;
    int temporaryWord16;
    int temporaryWord20;
    int temporaryWord1;
    int temporaryWord11;
    int temporaryWord12;
    int temporaryWord13;
    int temporaryWord15;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord10;
    int temporaryWord17;
    int temporaryWord19;
    int temporaryWord22;
    int temporaryWord23;
    int temporaryWord24;
    int temporaryWord8;
    int temporaryWord14;
    int temporaryWord18;
    int temporaryWord21;
    ownerRecord18 = input;
    __asm__("":"=r"(ownerRecord18):"0"(ownerRecord18));
    temporaryWord1 = Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x49);
    privateRecord19 = Level47_7BFE0Field(ownerRecord18, int *, 0);
    switch (temporaryWord1) {
    case 0:
        if (({rawWord2 = Level47_7BFE0Field(ownerRecord18, unsigned char*, 72);__asm__("":"=r"(rawWord2):"0"(rawWord2));argumentWord4 = (int)ownerRecord18;rawWord2 == 0;})) {
            argumentWord5 = 2;
            Level47_7BFE0Field(ownerRecord18, signed char *, 0x41) = 0;
            Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x4C) = 0U;
            Level47_7BFE0Field(ownerRecord18, signed char *, 0x4D) = 0;
            Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x4F) = 0U;
            Level47_7BFE0Field(ownerRecord18, int *, 0x14) = 0x1400;
            Level47_7BFE0Call55D24View1(argumentWord4, argumentWord5);
            rawWord2 = 1;
            goto storeSharedOriginalOwnerState1;
        }
        if (({rawWord2 = Level47_7BFE0Field(ownerRecord18, unsigned char*, 76);__asm__("":"=r"(rawWord2):"0"(rawWord2));argumentWord4 = 750;rawWord2 != 0;})){
            argumentWord5 = (int)ownerRecord18;
            rawWord2 = 1;
            Level47_7BFE0Field(ownerRecord18, unsigned char*, 72) = 0;
            __asm__("":::"memory");
            Level47_7BFE0Field(ownerRecord18, unsigned char*, 73) = rawWord2;
            rawWord3 = (int)Level47_7BFE0DataSpawnMobyView1;
            __asm__("":::"$2", "memory");
            rawWord2 = 10;
            Level47_7BFE0Field(privateRecord19, int*, 48) = 0;
            Level47_7BFE0Field(privateRecord19, int*, 28) = rawWord2;
            rawWord2 = ((int(*)())rawWord3)(argumentWord4, argumentWord5);
            Level47_7BFE0Field(privateRecord19, int*, 16) = rawWord2;
            Level47_7BFE0Field(ownerRecord18, int*, 28) |= 0x80000000;
            return;
        }
        return;
    case 1:
        temporaryWord13 = Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x48);
        if (temporaryWord13 == temporaryWord1) goto originalSubstateOne;
        if (temporaryWord13 >= 2) goto testOriginalSubstateTwo;
        if (temporaryWord13 == 0) goto originalSubstateZero;
        return;
        testOriginalSubstateTwo:if (temporaryWord13 == 2) goto originalSubstateTwo;
        return;
        originalSubstateZero:;
        retainedLinkedOrPlayerAddress17 = Level47_7BFE0Field(((Level47_7BFE0Field(privateRecord19, int *, 0) * 0x58) + Level47_7BFE0Data6C550View1), int*, 0);
        temporaryWord8 = (Level47_7BFE0Field(privateRecord19, unsigned char *, 4) * 0x10) + Level47_7BFE0Field(Level47_7BFE0Field(retainedLinkedOrPlayerAddress17, int *, 0x20), int *, 0xC);
        Level47_7BFE0Call35EE0View1(ownerRecord18, Level47_7BFE0Call4E880View1(Level47_7BFE0Field(temporaryWord8, int *, 0) - Level47_7BFE0Field(ownerRecord18, int *, 0xC), Level47_7BFE0Field(temporaryWord8, int *, 4) - Level47_7BFE0Field(ownerRecord18, int *, 0x10), 0), 0x32, 0, 0, 0);
        Level47_7BFE0Call55D24View1(ownerRecord18, 6);
        retainedDistanceOrModeAddress16 = ownerRecord18 + 0xC;
        Level47_7BFE0Call1A358View1(retainedDistanceOrModeAddress16, 0x2800);
        Level47_7BFE0Call5629CView1(ownerRecord18);
        rawWord2 = Level47_7BFE0Call4F334View1(retainedDistanceOrModeAddress16, Level47_7BFE0Field(Level47_7BFE0Field(retainedLinkedOrPlayerAddress17, int *, 0x20), int *, 0xC) + (Level47_7BFE0Field(privateRecord19, unsigned char *, 4) * 0x10)) < 0x400;
        if (!rawWord2){
            rawWord2 = 1;
            return;
        }
        rawWord2 = 1;
        storeSharedOriginalOwnerState1:__asm__ volatile("":"=r"(rawWord2):"0"(rawWord2), "i"(17));
        Level47_7BFE0Field(ownerRecord18, unsigned char*, 72) = rawWord2;
        return;
        return;
    originalSubstateOne:
        if (({rawWord2 = Level47_7BFE0Field(privateRecord19, int*, 16);__asm__("":"=r"(rawWord2):"0"(rawWord2));argumentWord4 = 165;rawWord2 == 0;})){
            rawWord2 = (int)Level47_7BFE0DataSpawnMobyView1;
            argumentWord5 = (int)ownerRecord18;
            Level47_7BFE0Field(ownerRecord18, int*, 24) = 0;
            temporaryWord10 = ((int(*)())rawWord2)(argumentWord4, argumentWord5);
            Level47_7BFE0Field(privateRecord19, int *, 0x38) = temporaryWord10;
            if (temporaryWord10 != 0) {
                Level47_7BFE0Field(temporaryWord10, unsigned char *, 0x4C) = (unsigned char) Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x4C);
                Level47_7BFE0Field(Level47_7BFE0Field(privateRecord19, int *, 0x38), unsigned char *, 0x4E) = (unsigned char) Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x4C);
                temporaryWord5 = Level47_7BFE0Field(privateRecord19, int *, 0x38);
                Level47_7BFE0Field(temporaryWord5, int *, 0x1C) = (int) (Level47_7BFE0Field(temporaryWord5, int *, 0x1C) | 0x80000000);
                Level47_7BFE0Call1A358View1(Level47_7BFE0Field(privateRecord19, int *, 0x38) + 0xC, 0x2800);
                Level47_7BFE0Call5629CView1(Level47_7BFE0Field(privateRecord19, int *, 0x38));
                Level47_7BFE0Field(Level47_7BFE0Field(privateRecord19, int *, 0x38), unsigned char *, 0x46) = (unsigned char) Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x46);
                Level47_7BFE0Field(ownerRecord18, int *, 0x14) = 0x1400;
                Level47_7BFE0Call55D24View1(ownerRecord18, 2);
                Level47_7BFE0Field(privateRecord19, int *, 0x20) = (int) Level47_7BFE0Field(Level47_7BFE0Field(((Level47_7BFE0Field(privateRecord19, int *, 0x18) * 0x58) + Level47_7BFE0Data6C550View1), int*, 0), int *, 0x24);
                Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x48) = 2U;
                return;
            }
        }
        return;
    originalSubstateTwo:
        argumentWord5 = Level47_7BFE0Field(Level47_7BFE0Field(privateRecord19, int*, 0)*88+Level47_7BFE0Data6C550View1, int*, 0);
        argumentWord4 = Level47_7BFE0Field(privateRecord19, int*, 56);
        rawWord3 = Level47_7BFE0Field(argumentWord5, int*, 32);
        rawWord2 = Level47_7BFE0Field(privateRecord19, unsigned char*, 4);
        rawWord3 = Level47_7BFE0Field(rawWord3, int*, 12);
        rawWord2 *= 16;
        rawWord2 += rawWord3;
        rawWord2 = Level47_7BFE0Field(rawWord2, int*, 0);
        __asm__("":::"$3", "memory");
        rawWord3 = Level47_7BFE0Field(argumentWord4, int*, 12);
        rawWord2 -= rawWord3;
        rawWord2 >>= 2;
        rawWord3 += rawWord2;
        Level47_7BFE0Field(argumentWord4, int*, 12) = rawWord3;
        rawWord3 = Level47_7BFE0Field(argumentWord5, int*, 32);
        __asm__("":::"$2", "memory");
        rawWord2 = Level47_7BFE0Field(privateRecord19, unsigned char*, 4);
        __asm__("":::"$4", "memory");
        argumentWord4 = Level47_7BFE0Field(privateRecord19, int*, 56);
        rawWord3 = Level47_7BFE0Field(rawWord3, int*, 12);
        rawWord2 *= 16;
        rawWord2 += rawWord3;
        rawWord2 = Level47_7BFE0Field(rawWord2, int*, 4);
        __asm__("":::"$3", "memory");
        rawWord3 = Level47_7BFE0Field(argumentWord4, int*, 16);
        rawWord2 -= rawWord3;
        rawWord2 >>= 2;
        rawWord3 += rawWord2;
        Level47_7BFE0Field(argumentWord4, int*, 16) = rawWord3;
        temporaryWord3 = Level47_7BFE0Field(privateRecord19, int *, 0x38);
        Level47_7BFE0Field(temporaryWord3, int *, 0x14) = (int) (Level47_7BFE0Field(temporaryWord3, int *, 0x14) + Level47_7BFE0Field(privateRecord19, int *, 0xC));
        temporaryWord4 = Level47_7BFE0Field(privateRecord19, int *, 0x38);
        temporaryWord16 = Level47_7BFE0Field(privateRecord19, int *, 8);
        Level47_7BFE0Field(privateRecord19, int *, 0xC) = (int) (Level47_7BFE0Field(privateRecord19, int *, 0xC) - 0x14);
        if (Level47_7BFE0Field(temporaryWord4, int *, 0x14) < temporaryWord16) {
            Level47_7BFE0Field(temporaryWord4, int *, 0x14) = temporaryWord16;
            temporaryWord9 = (int) -Level47_7BFE0Field(privateRecord19, int *, 0xC) >> 3;
            Level47_7BFE0Field(privateRecord19, int *, 0xC) = temporaryWord9;
            if (temporaryWord9 < 0x20) {
                temporaryWord17 = Level47_7BFE0Field(privateRecord19, int *, 0x38);
                Level47_7BFE0Field(temporaryWord17, int *, 0x1C) = (int) (Level47_7BFE0Field(temporaryWord17, int *, 0x1C) & 0x7FFFFFFF);
                Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x49) = 2U;
                Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x48) = 0U;
                Level47_7BFE0Field(ownerRecord18, int *, 0x1C) = (int) (Level47_7BFE0Field(ownerRecord18, int *, 0x1C) & 0x7FFFFFFF);
                return;
            }
        }
        return;
        break;
    case 2:
        if (Level47_7BFE0Field(ownerRecord18, int *, 0x18) & 0x140000) {
            if ((unsigned int) (Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x48) - 1) < 2U) {
                Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int *, 0x24) = (int) (Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int *, 0x24) | 7);
                if (Level47_7BFE0Data6E160View1 == 0xE) {
                    temporaryWord22 = (Level47_7BFE0Field(privateRecord19, int *, 0x18) * 0x58) + Level47_7BFE0Data6C550View1;
                    temporaryWord18 = Level47_7BFE0Field(temporaryWord22, int*, 0);
                    if (Level47_7BFE0Field(temporaryWord18, short *, 0x82) != 0) {
                        temporaryWord22 = Level47_7BFE0Field(temporaryWord18, int *, 0x9C);
                    }
                    Level47_7BFE0Call13ACCView1(temporaryWord22, 0xD);
                }
                Level47_7BFE0Field(Level47_7BFE0Field(privateRecord19, int *, 0x14), int*, 0) = 0;
                Level47_7BFE0Call28154View1(Level47_7BFE0Field(privateRecord19, int *, 0x34));
                Level47_7BFE0Field(privateRecord19, int *, 0x34) = -1;
            }
            if (Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x48) != 4) {
                temporaryWord6 = Level47_7BFE0Field(privateRecord19, int *, 0x38);
                if (temporaryWord6 != 0) {
                    retainedDistanceOrModeAddress16 = Level47_7BFE0Field(temporaryWord6, int *, 0x14);
                    if (retainedDistanceOrModeAddress16 == 0x1400) {
                        Level47_7BFE0Call4F178View1(temporaryWord6 + 0xC, ownerRecord18 + 0xC);
                        Level47_7BFE0Field(ownerRecord18, int *, 0x14) = retainedDistanceOrModeAddress16;
                        Level47_7BFE0Call55D24View1(ownerRecord18, 6);
                    }
                    Level47_7BFE0Field(Level47_7BFE0Field(privateRecord19, int *, 0x38), unsigned char *, 0x46) = (unsigned char) Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x46);
                    Level47_7BFE0Field(Level47_7BFE0Field(privateRecord19, int *, 0x38), unsigned char *, 0x4F) = 0x20U;
                }
                Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x48) = 4U;
                Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x4F) = 0x20U;
                Level47_7BFE0Field(ownerRecord18, int *, 0x18) = 0;
                goto checkOriginalOwnerState;
            }
        }
        else {
        checkOriginalOwnerState:
            argumentWord4 = Level47_7BFE0Field(ownerRecord18, unsigned char*, 72);
            __asm__("":::"$2", "memory");
            rawWord2 = 4;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4), "r"(rawWord2));
            rawWord3 = argumentWord4&255;
            if ((rawWord3 != rawWord2) && (Level47_7BFE0Field(privateRecord19, int *, 0x20) != Level47_7BFE0Field(Level47_7BFE0Field(((Level47_7BFE0Field(privateRecord19, int *, 0x18) * 0x58) + Level47_7BFE0Data6C550View1), int*, 0), int *, 0x24)) && (({rawWord2 = argumentWord4-1;rawWord2 = (unsigned int)rawWord2 < 2;__asm__("":"=r"(rawWord2):"0"(rawWord2));!rawWord2;}))) {
                temporaryWord7 = Level47_7BFE0Field(privateRecord19, int *, 0x38);
                if (temporaryWord7 != 0) {
                    retainedDistanceOrModeAddress16 = Level47_7BFE0Field(temporaryWord7, int *, 0x14);
                    if (retainedDistanceOrModeAddress16 == 0x1400) {
                        Level47_7BFE0Call4F178View1(temporaryWord7 + 0xC, ownerRecord18 + 0xC);
                        Level47_7BFE0Field(ownerRecord18, int *, 0x14) = retainedDistanceOrModeAddress16;
                        Level47_7BFE0Call55D24View1(ownerRecord18, 6);
                    }
                    Level47_7BFE0Field(Level47_7BFE0Field(privateRecord19, int *, 0x38), unsigned char *, 0x46) = (unsigned char) Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x46);
                    Level47_7BFE0Field(Level47_7BFE0Field(privateRecord19, int *, 0x38), unsigned char *, 0x4F) = 0x20U;
                }
                Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x48) = 4U;
                Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x4F) = 0x20U;
            }
        }
        rawWord3 = Level47_7BFE0Field(ownerRecord18, unsigned char*, 72);
        __asm__("":::"$2", "memory");
        rawWord2 = 1;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        if (rawWord3 == rawWord2) goto originalOwnerStateOne;
        if (rawWord3 >= 2) goto testOriginalOwnerStateTwo;
        argumentWord4 = privateRecord19+36;
        if (rawWord3 == 0) goto originalOwnerStateZero;
        Level47_7BFE0Field(ownerRecord18, int*, 24) = 0;
        goto originalAnimate;
        testOriginalOwnerStateTwo:rawWord2 = 2;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        if (rawWord3 == rawWord2) goto originalOwnerStateTwo;
        rawWord2 = 4;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        if (rawWord3 == rawWord2) goto originalOwnerStateFour;
        Level47_7BFE0Field(ownerRecord18, int*, 24) = 0;
        goto originalAnimate;
    originalOwnerStateZero:
        retainedLinkedOrPlayerAddress17 = (int)&Level47_7BFE0Data70328View1+8;
        __asm__("":"=r"(retainedLinkedOrPlayerAddress17):"0"(retainedLinkedOrPlayerAddress17));
        rawWord2 = Level47_7BFE0Field(retainedLinkedOrPlayerAddress17, int*, 0);
        rawWord3 = Level47_7BFE0Field(privateRecord19, int*, 56);
        argumentWord5 = Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int*, 68);
        rawWord3 = Level47_7BFE0Field(rawWord3, int*, 20);
        rawWord2 -= argumentWord5;
        retainedDistanceOrModeAddress16 = rawWord2-rawWord3;
        Level47_7BFE0Call4F168View1(argumentWord4, argumentWord5);
        rawWord2 = Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int*, 592);
        if (rawWord2){
            argumentWord5 = retainedLinkedOrPlayerAddress17-8;
            goto clearOriginalOwnerFlags;
        }
        argumentWord5 = retainedLinkedOrPlayerAddress17-8;
        argumentWord4 = Level47_7BFE0Field(privateRecord19, int*, 56);
        argumentWord4 += 12;
        rawWord2 = Level47_7BFE0Call4F334View1(argumentWord4, argumentWord5);
        if (rawWord2 >= 1024){
            rawWord2 = retainedDistanceOrModeAddress16-321;
            goto clearOriginalOwnerFlags;
        }
        rawWord2 = retainedDistanceOrModeAddress16-321;
        if ((unsigned int)rawWord2 >= 319){
            argumentWord4 = (int)ownerRecord18+12;
            goto clearOriginalOwnerFlags;
        }
        argumentWord4 = (int)ownerRecord18+12;
        argumentWord5 = Level47_7BFE0Field(privateRecord19, int*, 56);
        argumentWord5 += 12;
        Level47_7BFE0Call4F178View1(argumentWord4, argumentWord5);
        argumentWord4 = (int)ownerRecord18;
        __asm__("":"=r"(argumentWord4):"0"(argumentWord4):"$5", "memory");
        argumentWord5 = 6;
        __asm__("":"=r"(argumentWord5):"0"(argumentWord5):"memory");
        rawWord3 = Level47_7BFE0Field(privateRecord19, int*, 56);
        __asm__("":::"$2", "memory");
        rawWord2 = 5120;
        Level47_7BFE0Field(rawWord3, int*, 20) = rawWord2;
        Level47_7BFE0Call55D24View1(argumentWord4, argumentWord5);
        rawWord2 = 1;
        Level47_7BFE0Field(ownerRecord18, unsigned char*, 72) = rawWord2;
        goto clearOriginalOwnerFlags;
    originalOwnerStateOne:
        Level47_7BFE0Field(Level47_7BFE0Field(privateRecord19, int *, 0x14), int*, 0) = ownerRecord18;
        if ((Level47_7BFE0Data6E53CView1 & 0x40) || (Level47_7BFE0Field(privateRecord19, int *, 0x20) != Level47_7BFE0Field(Level47_7BFE0Field(((Level47_7BFE0Field(privateRecord19, int *, 0x18) * 0x58) + Level47_7BFE0Data6C550View1), int*, 0), int *, 0x24)) || ((unsigned int) (Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int *, 0x50) - 7) < 2U) || (Level47_7BFE0Call4F334View1(ownerRecord18 + 0xC, ((int)&Level47_7BFE0Data70328View1 + 0x50) - 0x50) >= 0x401) || ((Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int *, 0xB8) == 0) && (Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int *, 0x13C) != ownerRecord18))) {
            Level47_7BFE0Call4F178View1(Level47_7BFE0Field(privateRecord19, int *, 0x38) + 0xC, ownerRecord18 + 0xC);
            Level47_7BFE0Field(ownerRecord18, int *, 0x14) = 0x1400;
            Level47_7BFE0Call55D24View1(ownerRecord18, 2);
            Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x48) = 0U;
            if (Level47_7BFE0Data6E160View1 == 0xE) {
                temporaryWord24 = (Level47_7BFE0Field(privateRecord19, int *, 0x18) * 0x58) + Level47_7BFE0Data6C550View1;
                temporaryWord14 = Level47_7BFE0Field(temporaryWord24, int*, 0);
                if (Level47_7BFE0Field(temporaryWord14, short *, 0x82) != 0) {
                    temporaryWord24 = Level47_7BFE0Field(temporaryWord14, int *, 0x9C);
                }
                Level47_7BFE0Call13ACCView1(temporaryWord24, 0xD);
            }
            Level47_7BFE0Field(Level47_7BFE0Field(privateRecord19, int *, 0x14), int*, 0) = 0;
        }
        else {
            rawWord3 = Level47_7BFE0Data6E160View1;
            rawWord2 = 14;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            if (rawWord3 == rawWord2) goto originalMode14;
            rawWord2 = 11;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            if (rawWord3 == rawWord2) goto testOriginalMode14;
            rawWord2 = 9;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            argumentWord4 = (int)ownerRecord18;
            if (rawWord3 == rawWord2) goto testOriginalMode14;
            Level47_7BFE0Call13ACCView1(argumentWord4, 14);
            rawWord3 = Level47_7BFE0Data6E160View1;
            testOriginalMode14:rawWord2 = 14;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            if (rawWord3 != rawWord2) goto clearOriginalOwnerFlags;
        originalMode14:
            Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int *, 0x20C) = 0x10000040;
            Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int *, 0x218) = ownerRecord18;
            Level47_7BFE0Call4F178View1((int)&Level47_7BFE0Data70328View1 + 0x20C + 0x20, ownerRecord18 + 0xC);
            Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int *, 0x238) = (int) Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x46);
            if ((Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int *, 0x214) == 2) && (Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int *, 0x13C) == ownerRecord18)) {
                Level47_7BFE0Field(privateRecord19, signed char *, 6) = 0;
                Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x48) = 2U;
                Level47_7BFE0Field(privateRecord19, int *, 0x34) = (int)(short) Level47_7BFE0Call2803CView1(0x15, 0x1D7, &Level47_7BFE0Call27E40View1, &Level47_7BFE0Call27A60View1, &Level47_7BFE0Call29904View1, privateRecord19 + 0x1C, Level47_7BFE0Field(privateRecord19, int *, 0x1C));
            }
        }
        goto clearOriginalOwnerFlags;
    originalOwnerStateTwo:
        if (Level47_7BFE0Data6E53CView1&64) goto resetOriginalOwnerState2;
        if ((Level47_7BFE0Field(privateRecord19, int *, 0x20) != Level47_7BFE0Field(Level47_7BFE0Field(((Level47_7BFE0Field(privateRecord19, int *, 0x18) * 0x58) + Level47_7BFE0Data6C550View1), int*, 0), int *, 0x24)) || ((unsigned int) (({retainedLinkedOrPlayerAddress17 = (int)&Level47_7BFE0Data70328View1+80;__asm__("":"=r"(retainedLinkedOrPlayerAddress17):"0"(retainedLinkedOrPlayerAddress17));Level47_7BFE0Field(retainedLinkedOrPlayerAddress17, int*, 0);}) - 7) < 2U) || (Level47_7BFE0Field(privateRecord19, int *, 0x1C) < 0) || (({rawWord2 = Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int*, 316);__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord3 = 13;rawWord2 != (int)ownerRecord18;}))) {
            if (!(Level47_7BFE0Data6E53CView1 & 0x40) && ((unsigned int) (({argumentWord5 = (int)&Level47_7BFE0Data70328View1+80;__asm__("":"=r"(argumentWord5):"0"(argumentWord5));Level47_7BFE0Field(argumentWord5, int*, 0);}) - 7) >= 2U)) {
                Level47_7BFE0Call4F178View1(&originalFrame.sp28, argumentWord5-80);
                originalFrame.sp30 = Level47_7BFE0Call1A358View1(&originalFrame.sp28, 0x800);
                Level47_7BFE0Call48210View1(&originalFrame.sp28);
            }
            goto resetOriginalOwnerState2;
        }
        goto originalLiveOwnerStateTwo;
    resetOriginalOwnerState2:
        Level47_7BFE0Call4F178View1(Level47_7BFE0Field(privateRecord19, int *, 0x38) + 0xC, ownerRecord18 + 0xC);
        Level47_7BFE0Field(ownerRecord18, int *, 0x14) = 0x1400;
        Level47_7BFE0Call55D24View1(ownerRecord18, 2);
        Level47_7BFE0Field(Level47_7BFE0Field(privateRecord19, int *, 0x38), unsigned char *, 0x46) = (unsigned char) Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x46);
        Level47_7BFE0Field(Level47_7BFE0Field(privateRecord19, int *, 0x38), unsigned char *, 0x4F) = 0x20U;
        Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x48) = 4U;
        Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x4F) = 0x20U;
        if (Level47_7BFE0Data6E160View1 == 0xE) {
            temporaryWord23 = (Level47_7BFE0Field(privateRecord19, int *, 0x18) * 0x58) + Level47_7BFE0Data6C550View1;
            temporaryWord21 = Level47_7BFE0Field(temporaryWord23, int*, 0);
            if (Level47_7BFE0Field(temporaryWord21, short *, 0x82) != 0) {
                temporaryWord23 = Level47_7BFE0Field(temporaryWord21, int *, 0x9C);
            }
            Level47_7BFE0Call13ACCView1(temporaryWord23, 0xD);
        }
        Level47_7BFE0Field(Level47_7BFE0Field(privateRecord19, int *, 0x14), int*, 0) = 0;
        Level47_7BFE0Call28154View1(Level47_7BFE0Field(privateRecord19, int *, 0x34));
        Level47_7BFE0Field(privateRecord19, int *, 0x34) = -1;
        goto updateOriginalOwnerStateTwo;
    originalLiveOwnerStateTwo:
        retainedDistanceOrModeAddress16 = (int)&Level47_7BFE0Data6E160View1;
        __asm__("":"=r"(retainedDistanceOrModeAddress16):"0"(retainedDistanceOrModeAddress16));
        rawWord2 = Level47_7BFE0Field(retainedDistanceOrModeAddress16, int*, 0);
        retainedOldValue20 = Level47_7BFE0Field(privateRecord19, int*, 48);
        if (rawWord2 == rawWord3) {
            Level47_7BFE0Call13ACCView1(ownerRecord18, 0xE);
        }
        if (Level47_7BFE0Field(retainedDistanceOrModeAddress16, int*, 0) == 0xE) {
            Level47_7BFE0Call410F8View1(&originalFrame.sp20, privateRecord19 + 0x24, 1);
            Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x46) = (unsigned char) (Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x46) + ((int) (originalFrame.sp20 + 0xA) >> 5));
            Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int *, 0x20C) = 0x10018000;
            Level47_7BFE0Call4F178View1(retainedLinkedOrPlayerAddress17+0x1DC, ownerRecord18 + 0xC);
            Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int *, 0x234) = (int) (Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int *, 0x234) + 0x283);
            Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, unsigned char *, 0x228) = (unsigned char) Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x44);
            Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, unsigned char *, 0x229) = (unsigned char) Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x45);
            rawWord2 = Level47_7BFE0Field(ownerRecord18, unsigned char*, 70);
            __asm__("":::"memory");
            Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, int*, 572) = 0;
            __asm__("":"=r"(rawWord2):"0"(rawWord2):"memory");
            Level47_7BFE0Field((int)&Level47_7BFE0Data70328View1, unsigned char*, 554) = rawWord2;
            temporaryWord20 = Level47_7BFE0Field(privateRecord19, int *, 0x30) - (originalFrame.sp24 >> 5);
            Level47_7BFE0Field(privateRecord19, int *, 0x30) = temporaryWord20;
            if (temporaryWord20 < 0) {
                Level47_7BFE0Field(privateRecord19, int *, 0x30) = 0;
            }
            if (Level47_7BFE0Field(privateRecord19, int *, 0x30) >= 0x41) {
                Level47_7BFE0Field(privateRecord19, int *, 0x30) = 0x40;
            }
        }
        if (({rawWord2 = -8;rawWord3 = Level47_7BFE0Field(privateRecord19, int*, 48);argumentWord4 = retainedOldValue20&rawWord2;rawWord3 &= rawWord2;__asm__("":"=r"(argumentWord4):"0"(argumentWord4));argumentWord4 != rawWord3;})) {
            if (Level47_7BFE0Call3BFC0View1(ownerRecord18, Level47_7BFE0Field(privateRecord19, unsigned char *, 7)) != 0) {
                Level47_7BFE0Call3BE70View1(Level47_7BFE0Field(privateRecord19, unsigned char *, 7));
            }
            Level47_7BFE0Field(privateRecord19, unsigned char *, 7) = Level47_7BFE0Call3BABCView1(ownerRecord18, 0, 0);
        }
        argumentWord4 = privateRecord19+6;
        if ((Level47_7BFE0Call359A4View1(argumentWord4, 1) != 0) && (Level47_7BFE0Data6E53CView1 & 0x20)) {
            Level47_7BFE0Field(privateRecord19, unsigned char *, 5) = 1U;
            Level47_7BFE0Field(privateRecord19, int *, 0x1C) = (int) (Level47_7BFE0Field(privateRecord19, int *, 0x1C) - 1);
        }
        updateOriginalOwnerStateTwo:;
        Level47_7BFE0Call55D24View1(ownerRecord18, 4);
        Level47_7BFE0Call35D38View1(ownerRecord18);
        Level47_7BFE0Call5629CView1(ownerRecord18);
        Level47_7BFE0Field(ownerRecord18, int *, 0x18) = 0;
        goto originalAnimate;
    originalOwnerStateFour:
        temporaryWord11 = Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x4F) + 4;
        Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x4F) = temporaryWord11;
        temporaryWord19 = Level47_7BFE0Field(privateRecord19, int *, 0x38);
        if (temporaryWord19 != 0) {
            Level47_7BFE0Field(temporaryWord19, unsigned char *, 0x4F) = temporaryWord11;
        }
        if ((unsigned char) Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x4F) >= 0x80U) {
            rawWord3 = Level47_7BFE0Field(Level47_7BFE0Field(privateRecord19, int*, 0)*88+Level47_7BFE0Data6C550View1, int*, 0);
            __asm__("":::"$2", "memory");
            rawWord2 = 127;
            Level47_7BFE0Field(ownerRecord18, unsigned char*, 79) = rawWord2;
            Level47_7BFE0Field(Level47_7BFE0Field(privateRecord19, unsigned char*, 4)*16+Level47_7BFE0Field(Level47_7BFE0Field(rawWord3, int*, 32), int*, 12), int*, 12) = 0;
            Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x49) = 0U;
            Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x48) = 0U;
            temporaryWord2 = Level47_7BFE0Field(privateRecord19, int *, 0x38);
            if (temporaryWord2 != 0) {
                Level47_7BFE0Call55B18View1(temporaryWord2);
                Level47_7BFE0Field(privateRecord19, int *, 0x38) = 0;
            }
        }
        goto clearOriginalOwnerFlags;
        clearOriginalOwnerFlags:Level47_7BFE0Field(ownerRecord18, int*, 24) = 0;
        originalAnimate:;
        temporaryWord15 = Level47_7BFE0Field(privateRecord19, unsigned char *, 5);
        switch (temporaryWord15) {
        case 0:
            Level47_7BFE0Field(ownerRecord18, signed char *, 0x3C) = 0;
            Level47_7BFE0Field(ownerRecord18, signed char *, 0x3D) = 2;
            Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x3E) = 0U;
            Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x3F) = 0U;
            goto storeSharedOriginalShiftedByte;
        case 1:
            Level47_7BFE0Call3BABCView1(ownerRecord18, 1, 0);
            Level47_7BFE0Call55D24View1(ownerRecord18, 4);
            Level47_7BFE0DataSpawnMobyView1(0xC2, ownerRecord18);
            Level47_7BFE0Field(privateRecord19, signed char *, 6) = 0x1E;
            Level47_7BFE0Field(ownerRecord18, signed char *, 0x3C) = 1;
            Level47_7BFE0Field(ownerRecord18, signed char *, 0x3D) = 3;
            Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x3E) = 0U;
            Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x3F) = 0U;
            Level47_7BFE0Field(ownerRecord18, signed char *, 0x40) = (signed char) ((int) Level47_7BFE0Field(privateRecord19, int *, 0x30) >> 3);
            Level47_7BFE0Field(privateRecord19, unsigned char *, 5) = 2U;
            return;
        case 2:
            Level47_7BFE0Field(ownerRecord18, signed char *, 0x3C) = 1;
            Level47_7BFE0Field(ownerRecord18, signed char *, 0x3D) = 3;
            temporaryWord12 = Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x3E) + 1;
            Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x3E) = temporaryWord12;
            if ((unsigned int) (temporaryWord12 & 0xFF) >= 0xEU) {
                Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x3E) = 0xEU;
                Level47_7BFE0Field(privateRecord19, unsigned char *, 5) = 0U;
                if (Level47_7BFE0Field(privateRecord19, int *, 0x1C) == 0) {
                    Level47_7BFE0Field(privateRecord19, int *, 0x1C) = -1;
                }
            }
            Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x3F) = (unsigned char) Level47_7BFE0Field(ownerRecord18, unsigned char *, 0x3E);
            storeSharedOriginalShiftedByte:rawWord2 = Level47_7BFE0Field(privateRecord19, int*, 48);
            rawWord2 >>= 3;
            Level47_7BFE0Field(ownerRecord18, unsigned char*, 64) = rawWord2;
            return;
        }
        break;
    }
}
#undef Level47_7BFE0Field


void func_80055B18(Moby*);
void func_level_47_8007CE50(Moby* moby) {
    Moby** tag = moby->mobyTag;
    if (moby->animationState.id) func_80039714(moby);
    else if (moby->damageFlags == 0x10000 || (*tag)->damageFlags == 1) {
        ((int*)(*tag)->mobyTag)[4] = 0;
        moby->position.z += 0xA00;
        func_800391E8(0x14, 0x2EE, moby, 1, 3, 0x80, 0x100);
        func_80055B18(moby);
    } else {
        moby->damageFlags = 0;
        (*tag)->damageFlags = 0;
        func_8004F178(&moby->position, &(*tag)->position);
        func_80055D24(moby, 3);
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original level47 controller8007CF38.
 * Assembly SHA256 57896d1550fbed3307fdf589728321def19590b443c9a87f3584c7cee385d8b4.
 * AI generated; not human reviewed.2006 native instructions plus36 actual
 * original .rodata selectors at800745D0..8007465C,without padding=2042 words.
 * Names describe physical fields/register phases; no gameplay,asset,SFX or
 * animation meaning is inferred. The frame reserves264 original bytes.
 * Live local vectors occupy SP20..28,30..38,40..48,50..58,60..68,70..78,
 * 80..88,90..98,A0..A8,B0..B8,C0..C8.16 bytes of original frame capacity
 * aboveC8 are never initialized,read,addressed or supplied to metadata.
 * Original CC..DC has no native semantic access; saved GP begins atE0.
 * This capacity is no substitute for any missing producer.
 * Finite original CFG audit checks3263 states/3626 edges,all36 selectors,
 * complete GP/HILO/call/outgoing-home inputs,and every local vector read.
 * F178/F194/F1C8/F168 and55F14 define all three real output words.
 * Every call destroys caller GP/HILO/outgoing homes; no incoming saved
 * value,unwritten local,guessed minimum,count or default is consumed.
 * C7C4 is an explicit original2/1/0 switch,with its real default path;
 * it is never used as an invented bounded local-cell index.
 * Seven signed32x32 MULTs produce complete initialized signed64 values:
 * distance450,three low32 vector products,distance180,and two signed16
 * trig/scale products. Each HI/LO projection consumes the entire correct
 * product,with a distinct scalar capture. No isolated HI/LO input exists.
 * Magic division retains signed32 high+input,arithmetic shift8 or7 and
 * sign correction. Low products preserve original low32 before shift12.
 * Constant trig ladders retain25>>10 and13>>5. Original CRC retains both
 * exact byte ranges,cursor steps,64-byte budget,eight rounds and8005 XOR.
 * Raw decoder temporary aliases were split where a prior byte,halfword,
 * heading or predicate remains live after a newer physical-register phase.
 * Shared timer,state,heading and animation entries retain actual original
 * incoming destinations,including the state9 entry which skips its owner
 * producer when the preceding branch already defines the complete A0.
 * Empty metadata emits no CPU instruction. It observes initialized full
 * words/addresses/frame cells or real original branch-source fields.
 * Immediate selector observations are actual dominating inner0/1/2 values.
 * Dead-register boundaries retire only a proven old phase before its new
 * definition. Fixed GP roles have disjoint live meanings. There is no
 * opcode asm,fixed FP/SP,manual outgoing home,incoming saved read or
 * overlapping live alias. Physical ABI views retain every original word.
 * Matching targets the frozen32-bit MIPS wrap,narrow and arithmetic-shift
 * behavior. Portable C domains,full helper/caller/archive/heap ownership,
 * units,invocation cadence,Rev1 mappings,synchronized retail captures and
 * human review remain open. All linked instructions,actual transfers,
 * data/addends,36 absolute selectors and every retail hash are mandatory.
 */
#define Actor2006Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
#define Actor2006Keep(v) __asm__("":"=r"(v):"0"(v))
void Actor2006_func_80013ACC(void*,int) __asm__("func_80013ACC");
void Actor2006_func_80013AE4(void*,void*) __asm__("func_80013AE4");
void Actor2006_func_80013B7C(int) __asm__("func_80013B7C");
void Actor2006_func_80013D44(void*,int,int,int) __asm__("func_80013D44");
int Actor2006_func_8002803C(int,int,int,int,int,void*,int) __asm__("func_8002803C");
void Actor2006_func_80028154(int) __asm__("func_80028154");
void Actor2006_func_80034F40(void*,int) __asm__("func_80034F40");
void Actor2006_func_80034F80(void*,int) __asm__("func_80034F80");
void Actor2006_func_80035734(void*) __asm__("func_80035734");
int Actor2006_func_8003573C(void*,int,int,int) __asm__("func_8003573C");
int Actor2006_func_8003585C(void*,int,int,int,int,int) __asm__("func_8003585C");
int Actor2006_func_800359A4(void*,int) __asm__("func_800359A4");
void Actor2006_func_80035DDC(void*,int,int,int,int) __asm__("func_80035DDC");
void Actor2006_func_80035EE0(void*,int,int,int,int,int) __asm__("func_80035EE0");
int Actor2006_func_8003617C(int,int) __asm__("func_8003617C");
int Actor2006_func_8003636C(int,int) __asm__("func_8003636C");
int Actor2006_func_800365E4(void*,void*,int,int,int) __asm__("func_800365E4");
void Actor2006_func_8003B7B4(void*,int,void*) __asm__("func_8003B7B4");
void Actor2006_func_8003BABC(void*,int,int) __asm__("func_8003BABC");
int Actor2006_func_8003BB10(void*,int,int) __asm__("func_8003BB10");
void Actor2006_func_800492DC(void*) __asm__("func_800492DC");
int Actor2006_func_8004E880(int,int,int) __asm__("func_8004E880");
int Actor2006_func_8004EDE8(void*,int) __asm__("func_8004EDE8");
void Actor2006_func_8004F08C(void*,int,int) __asm__("func_8004F08C");
void Actor2006_func_8004F110(void*,int) __asm__("func_8004F110");
void Actor2006_func_8004F168(void*) __asm__("func_8004F168");
void Actor2006_func_8004F178(void*,void*) __asm__("func_8004F178");
void Actor2006_func_8004F194(void*,void*,void*) __asm__("func_8004F194");
void Actor2006_func_8004F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Actor2006_func_8004F264(int,int) __asm__("func_8004F264");
int Actor2006_func_8004F334(void*,void*) __asm__("func_8004F334");
void Actor2006_func_80055B18(void*) __asm__("func_80055B18");
void Actor2006_func_80055D24(void*,int) __asm__("func_80055D24");
int Actor2006_func_80055E84(void*) __asm__("func_80055E84");
void Actor2006_func_80055F14(void*,int,void*) __asm__("func_80055F14");
void Actor2006_func_800584BC(int,int) __asm__("func_800584BC");
int Actor2006_rand(void) __asm__("rand");
extern int Actor2006_D_8006580C __asm__("D_8006580C");
extern int Actor2006_D_80065834 __asm__("D_80065834");
extern short Actor2006_D_800658A0[] __asm__("D_800658A0");
extern short Actor2006_D_80065920[] __asm__("D_80065920");
extern signed char Actor2006_D_8006C408 __asm__("D_8006C408");
extern unsigned char Actor2006_D_8006C40B __asm__("D_8006C40B");
extern int Actor2006_D_8006C550 __asm__("D_8006C550");
extern int Actor2006_D_8006C58C __asm__("D_8006C58C");
extern int Actor2006_D_8006C770 __asm__("D_8006C770");
extern unsigned char Actor2006_D_8006C7B4 __asm__("D_8006C7B4");
extern int Actor2006_D_8006C7C4 __asm__("D_8006C7C4");
extern int Actor2006_D_8006C7F8 __asm__("D_8006C7F8");
extern int Actor2006_D_8006D088 __asm__("D_8006D088");
extern int Actor2006_D_8006E048 __asm__("D_8006E048");
extern int Actor2006_D_8006E160 __asm__("D_8006E160");
extern int Actor2006_D_8006E164 __asm__("D_8006E164");
extern unsigned char Actor2006_D_80070328[] __asm__("D_80070328");
extern unsigned char Actor2006_D_8007158F __asm__("D_8007158F");
extern int Actor2006_D_level_47_8008DF5C __asm__("D_level_47_8008DF5C");
extern int(*Actor2006_SpawnMoby)(int,void*) __asm__("SpawnMoby");
extern void(*Actor2006_SpawnParticle)(int,int,void*,void*) __asm__("SpawnParticle");
extern unsigned char Actor2006_func_level_47_80074D7C __asm__("func_level_47_80074D7C");
extern int Actor2006_main_TEXT_END __asm__("main_TEXT_END");
extern int Actor2006_main_TEXT_START __asm__("main_TEXT_START");
extern int Actor2006_unk_ovlheader_80074364 __asm__("unk_ovlheader_80074364");
extern int Actor2006_unk_ovlheader_80074368 __asm__("unk_ovlheader_80074368");
extern int Actor2006_unk_ovlheader_8007436C __asm__("unk_ovlheader_8007436C");
void func_level_47_8007CF38(void* input) {
    register int resultWord2 __asm__("$2"),intermediateWord3 __asm__("$3"),argumentWord4 __asm__("$4"),argumentWord5 __asm__("$5"),argumentWord6 __asm__("$6"),argumentWord7 __asm__("$7"),completeProductProjection8 __asm__("$8"),completeProductProjection9 __asm__("$9");
    register int ownerAddress20 __asm__("$20"),privateAddress19 __asm__("$19"),retainedScalarOrVectorAddress16 __asm__("$16"),retainedHeadingIndexOrVectorAddress17 __asm__("$17"),retainedTableOrVectorAddress18 __asm__("$18"),retainedDifficultyScaleOrOwnerAddress21 __asm__("$21"),retainedDistanceOrSineAddress22 __asm__("$22"),retainedPrivateDistance23 __asm__("$23");
    long long initializedSignedProduct64;
    int division450High,division180High,vectorProductXLow,vectorProductYLow,vectorProductZLow,cosineProductLow,sineProductLow;
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
        unsigned char originalUnconsumedCapacity[16];
    }
    originalFrame;
    ownerAddress20=(int)input;
    Actor2006Keep(ownerAddress20);
    retainedScalarOrVectorAddress16 = ownerAddress20 + 0xC;
    privateAddress19 = Actor2006Field(ownerAddress20, int *, 0);
    resultWord2=Actor2006_func_8004F334(retainedScalarOrVectorAddress16,(int)&Actor2006_D_80070328);
    argumentWord4=retainedScalarOrVectorAddress16;
    __asm__(""::"r"(argumentWord4));
    retainedDistanceOrSineAddress22=resultWord2;
    retainedPrivateDistance23=Actor2006_func_8004F334(argumentWord4,privateAddress19);
    retainedDifficultyScaleOrOwnerAddress21 = Actor2006_D_8006C40B;
    if(Actor2006_D_8006C7C4==2){
        retainedDifficultyScaleOrOwnerAddress21-=1;
        if(retainedDifficultyScaleOrOwnerAddress21<0)retainedDifficultyScaleOrOwnerAddress21=0;
    }
    else if(Actor2006_D_8006C7C4==1)retainedDifficultyScaleOrOwnerAddress21+=3;
    else if(Actor2006_D_8006C7C4==0)retainedDifficultyScaleOrOwnerAddress21+=5;
    if (Actor2006_D_8007158F != 0) {
        retainedDifficultyScaleOrOwnerAddress21 = 0;
    }
    if ((unsigned int) (Actor2006Field((int)&Actor2006_D_80070328, int *, 0x50) - 7) < 2U) {
        Actor2006Field(privateAddress19, short *, 0x46) = 0;
    }
    if (Actor2006Field(privateAddress19, int *, 0x28) == 0) {
        Actor2006Field(privateAddress19, int *, 0x2C) = 2;
        Actor2006Field((int)&Actor2006_D_80070328, int *, 0x258) = 0x10C00;
        Actor2006Field((int)&Actor2006_D_80070328, int *, 0x25C) = 0x10C00;
        Actor2006Field((int)&Actor2006_D_80070328, int *, 0x254) = 5;
        Actor2006Field((int)&Actor2006_D_80070328, int *, 0x260) = 0x3C00;
        Actor2006Field((int)&Actor2006_D_80070328, int *, 0x264) = 0x72D0;
        Actor2006Field(privateAddress19, int *, 0x58) = Actor2006_SpawnMoby(0x2F7, ownerAddress20);
        Actor2006Field(ownerAddress20, unsigned char *, 0x4E) = 0x40;
        Actor2006Field(privateAddress19, int *, 0x28) = 1;
        Actor2006Field(privateAddress19, int *, 0x30) = 0xC;
        Actor2006_func_80013ACC(ownerAddress20, 0xD);
        if (Actor2006Field(privateAddress19, int *, 0x38) < 0) {
            Actor2006Field(privateAddress19, int *, 0x38) = (short) Actor2006_func_8002803C(0x17, 0x1D6, Actor2006_unk_ovlheader_80074368, Actor2006_unk_ovlheader_8007436C, Actor2006_unk_ovlheader_80074364, privateAddress19 + 0x30, Actor2006Field(privateAddress19, int *, 0x30));
        }
    }
    if (Actor2006Field(privateAddress19, int *, 0xA0) == 0) {
        Actor2006Field(privateAddress19, int *, 0xA0) = (int) (Actor2006_D_8006C58C + ((int)&Actor2006_main_TEXT_START + 2));
    }
    resultWord2=Actor2006Field(privateAddress19,int*,0xA0);
    intermediateWord3=(int)&Actor2006_main_TEXT_END;
    argumentWord5=0;
    if((unsigned int)resultWord2<(unsigned int)intermediateWord3){
        argumentWord6=intermediateWord3;
        Actor2006Keep(argumentWord6);
    originalMainCrcByte:
        intermediateWord3=Actor2006Field(privateAddress19,int*,0xA0);
        if((unsigned int)intermediateWord3<(unsigned int)argumentWord6){
            argumentWord4=0;
            resultWord2=Actor2006Field(intermediateWord3,unsigned char*,0);
            intermediateWord3=Actor2006Field(privateAddress19,int*,0xA4);
            resultWord2<<=8;
            intermediateWord3^=resultWord2;
            Actor2006Field(privateAddress19,int*,0xA4)=intermediateWord3;
            do{
                intermediateWord3=Actor2006Field(privateAddress19,int*,0xA4);
                resultWord2=intermediateWord3&0x8000;
                if(intermediateWord3&0x8000)resultWord2=intermediateWord3*2^0x8005;
                else resultWord2=intermediateWord3*2;
                Actor2006Field(privateAddress19,int*,0xA4)=resultWord2;
                argumentWord4++;
                resultWord2=argumentWord4<8;
            }
            while(resultWord2);
            argumentWord5++;
            resultWord2=Actor2006Field(privateAddress19,int*,0xA4);
            intermediateWord3=Actor2006Field(privateAddress19,int*,0xA0);
            resultWord2&=3;
            resultWord2++;
            intermediateWord3+=resultWord2;
            Actor2006Field(privateAddress19,int*,0xA0)=intermediateWord3;
            resultWord2=argumentWord5<64;
            if(resultWord2)goto originalMainCrcByte;
            resultWord2=(int)&Actor2006_main_TEXT_END;
            if((unsigned int)intermediateWord3<(unsigned int)resultWord2){
                retainedScalarOrVectorAddress16=privateAddress19+0xA0;
                goto originalMainCrcDone;
            }
        }
        resultWord2=(int)&Actor2006_func_level_47_80074D7C;
        Actor2006Field(privateAddress19,int*,0xA0)=resultWord2;
    }
    retainedScalarOrVectorAddress16=privateAddress19+0xA0;
originalMainCrcDone:
    Actor2006_func_8003B7B4(retainedScalarOrVectorAddress16, 4, (int)&Actor2006_D_8006D088);
    Actor2006_func_8003B7B4(retainedScalarOrVectorAddress16, 4, (int)&Actor2006_D_8006C7F8);
    retainedScalarOrVectorAddress16 = privateAddress19 + 0xA4;
    Actor2006_func_8003B7B4(retainedScalarOrVectorAddress16, 4, (int)&Actor2006_D_8006D088);
    Actor2006_func_8003B7B4(retainedScalarOrVectorAddress16, 4, (int)&Actor2006_D_8006C7F8);
    if (Actor2006Field(privateAddress19, int *, 0x34) == 0) {
        if (((Actor2006Field(ownerAddress20, int *, 0x18) != 0) || (Actor2006Field((int)&Actor2006_D_80070328, int *, 0x50) != 0)) && (Actor2006Field((int)&Actor2006_D_80070328, int *, 0x240) == 0)) {
            Actor2006Field(privateAddress19, short *, 0x48) = 0x1E;
            Actor2006Field(privateAddress19, int *, 0x34) = 1;
            Actor2006_func_80013ACC(ownerAddress20, 0xD);
        }
    }
    else {
        resultWord2=(int)0x91A2B3C5;
        initializedSignedProduct64=(long long)retainedDistanceOrSineAddress22*(long long)resultWord2;
        __asm__ volatile(""::"x"(initializedSignedProduct64));
        argumentWord4=(int)&originalFrame.sp20;
        retainedHeadingIndexOrVectorAddress17=(int)&Actor2006_D_80070328+0x98;
        argumentWord5=retainedHeadingIndexOrVectorAddress17;
        __asm__(""::"r"(argumentWord4),"r"(argumentWord5));
        resultWord2=retainedDistanceOrSineAddress22>>31;
        __asm__("":"=h"(division450High):"x"(initializedSignedProduct64),"r"(resultWord2));
        completeProductProjection8=division450High;
        Actor2006Keep(completeProductProjection8);
        retainedScalarOrVectorAddress16=completeProductProjection8+retainedDistanceOrSineAddress22;
        Actor2006Keep(retainedScalarOrVectorAddress16);
        retainedScalarOrVectorAddress16>>=8;
        retainedScalarOrVectorAddress16-=resultWord2;
        Actor2006Keep(retainedScalarOrVectorAddress16);
        retainedScalarOrVectorAddress16*=2;
        Actor2006_func_8004F178(argumentWord4,argumentWord5);
        resultWord2=originalFrame.sp20;
        initializedSignedProduct64=(long long)resultWord2*(long long)retainedScalarOrVectorAddress16;
        __asm__ volatile(""::"x"(initializedSignedProduct64));
        __asm__("":"=l"(vectorProductXLow):"x"(initializedSignedProduct64));
        argumentWord6=vectorProductXLow;
        Actor2006Keep(argumentWord6);
        resultWord2=originalFrame.sp24;
        __asm__("":"=r"(resultWord2):"0"(resultWord2),"r"(argumentWord6));
        initializedSignedProduct64=(long long)resultWord2*(long long)retainedScalarOrVectorAddress16;
        __asm__ volatile(""::"x"(initializedSignedProduct64));
        __asm__("":"=l"(vectorProductYLow):"x"(initializedSignedProduct64));
        intermediateWord3=vectorProductYLow;
        Actor2006Keep(intermediateWord3);
        resultWord2=originalFrame.sp28;
        __asm__("":"=r"(resultWord2):"0"(resultWord2),"r"(intermediateWord3));
        initializedSignedProduct64=(long long)resultWord2*(long long)retainedScalarOrVectorAddress16;
        __asm__ volatile(""::"x"(initializedSignedProduct64));
        argumentWord4=(int)&originalFrame.sp20;
        argumentWord5=6;
        __asm__(""::"r"(argumentWord4),"r"(argumentWord5));
        originalFrame.sp20=argumentWord6;
        originalFrame.sp24=intermediateWord3;
        __asm__("":"=l"(vectorProductZLow):"x"(initializedSignedProduct64),"m"(originalFrame.sp20),"m"(originalFrame.sp24));
        completeProductProjection9=vectorProductZLow;
        Actor2006Keep(completeProductProjection9);
        originalFrame.sp28=completeProductProjection9;
        Actor2006_func_8004F110(argumentWord4,argumentWord5);
        Actor2006_func_8004F194(&originalFrame.sp20, &originalFrame.sp20, retainedHeadingIndexOrVectorAddress17 - 0x98);
        Actor2006_func_8004E880(originalFrame.sp20 - Actor2006Field(ownerAddress20, int *, 0xC), originalFrame.sp24 - Actor2006Field(ownerAddress20, int *, 0x10), 0);
        Actor2006_func_800359A4(privateAddress19 + 0x48, 2);
        Actor2006_func_800359A4(privateAddress19 + 0x4A, 2);
        if ((Actor2006Field(privateAddress19, int *, 0xA0) == (int)&Actor2006_D_level_47_8008DF5C) && (Actor2006Field(privateAddress19, int *, 0xA4) != 0)) {
            Actor2006_D_8006580C = 0;
            Actor2006_D_80065834 = 0;
            Actor2006Field(privateAddress19, int *, 0xA4) = 0;
        }
        {
            resultWord2=Actor2006Field(privateAddress19,short*,0x4A);
            if(resultWord2)goto clearOriginalOwnerFlagsAndContinue;
            intermediateWord3=0x140000;
            resultWord2=Actor2006Field(ownerAddress20,int*,0x18);
            resultWord2&=intermediateWord3;
            if(!resultWord2)goto clearOriginalOwnerFlagsAndContinue;
            resultWord2=1;
            intermediateWord3=Actor2006Field(ownerAddress20,unsigned char*,0x48);
            Actor2006Keep(intermediateWord3);
            argumentWord4=intermediateWord3&255;
            if(argumentWord4==resultWord2)goto clearOriginalOwnerFlagsAndContinue;
            resultWord2=15;
            if(argumentWord4==resultWord2)goto clearOriginalOwnerFlagsAndContinue;
            resultWord2=intermediateWord3-23;
            resultWord2=(unsigned int)resultWord2<5;
            if(resultWord2)goto clearOriginalOwnerFlagsAndContinue;
            resultWord2=intermediateWord3-11;
            resultWord2=(unsigned int)resultWord2<2;
            if(resultWord2)goto clearOriginalOwnerFlagsAndContinue;
            {
                intermediateWord3 = Actor2006Field(Actor2006Field(privateAddress19, int *, 0x58), int *, 0);
                Actor2006Field(intermediateWord3, unsigned char *, 0x10) = 0x96;
                Actor2006Field(intermediateWord3, unsigned char *, 0x11) = 0x33;
                Actor2006Field(intermediateWord3, unsigned char *, 0x12) = 0xA0;
                Actor2006Field(privateAddress19, int *, 0x2C) = (int) (Actor2006Field(privateAddress19, int *, 0x2C) - 1);
                resultWord2 = Actor2006Field(privateAddress19, int *, 0x30) - 1;
                Actor2006Field(privateAddress19, int *, 0x30) = resultWord2;
                if (Actor2006Field(privateAddress19, int *, 0x2C) <= 0) {
                    if (resultWord2 <= 0) {
                        resultWord2 = Actor2006_func_8004E880(Actor2006Field(ownerAddress20, int *, 0xC) - Actor2006Field(privateAddress19, int *, 0), Actor2006Field(ownerAddress20, int *, 0x10) - Actor2006Field(privateAddress19, int *, 4), 0);
                        retainedScalarOrVectorAddress16=(int)&originalFrame.sp30;
                        argumentWord4=retainedScalarOrVectorAddress16;
                        Actor2006Keep(argumentWord4);
                        retainedHeadingIndexOrVectorAddress17=resultWord2;
                        intermediateWord3=retainedHeadingIndexOrVectorAddress17*2;
                        resultWord2=Actor2006Field((int)&Actor2006_D_80065920,short*,intermediateWord3);
                        __asm__ volatile("":::"$5","memory");
                        argumentWord5=retainedScalarOrVectorAddress16;
                        __asm__(""::"r"(argumentWord5));
                        resultWord2*=4;
                        originalFrame.sp30=resultWord2;
                        resultWord2=Actor2006Field((int)&Actor2006_D_800658A0,short*,intermediateWord3);
                        __asm__ volatile("":::"$6","memory");
                        argumentWord6=privateAddress19;
                        originalFrame.sp38=0;
                        resultWord2*=4;
                        originalFrame.sp34=resultWord2;
                        Actor2006_func_8004F194(argumentWord4,argumentWord5,argumentWord6);
                        retainedDifficultyScaleOrOwnerAddress21=ownerAddress20+12;
                        resultWord2=Actor2006_func_8004F334(retainedDifficultyScaleOrOwnerAddress21,&originalFrame.sp30);
                        intermediateWord3=(int)0xB60B60B7;
                        initializedSignedProduct64=(long long)resultWord2*(long long)intermediateWord3;
                        __asm__ volatile(""::"x"(initializedSignedProduct64));
                        retainedTableOrVectorAddress18=(int)&Actor2006_D_80065920;
                        retainedDistanceOrSineAddress22=(int)&Actor2006_D_800658A0;
                        __asm__("":"=h"(division180High):"x"(initializedSignedProduct64),"r"(retainedTableOrVectorAddress18),"r"(retainedDistanceOrSineAddress22));
                        completeProductProjection8=division180High;
                        Actor2006Keep(completeProductProjection8);
                        intermediateWord3=(completeProductProjection8+resultWord2)>>7;
                        resultWord2>>=31;
                        intermediateWord3-=resultWord2;
                        resultWord2=intermediateWord3<50;
                        if(resultWord2 ? (resultWord2=intermediateWord3<350,1):(resultWord2=intermediateWord3<350,0)){
                            intermediateWord3=50;
                            Actor2006Keep(intermediateWord3);
                            resultWord2=intermediateWord3<350;
                        }
                        argumentWord4=retainedDifficultyScaleOrOwnerAddress21;
                        if(resultWord2)intermediateWord3=350;
                        argumentWord5=retainedScalarOrVectorAddress16;
                        argumentWord6=(short)intermediateWord3;
                        argumentWord7=-12;
                        Actor2006Field(privateAddress19,unsigned char*,0x1D)=retainedHeadingIndexOrVectorAddress17;
                        Actor2006Field(privateAddress19,short*,0x10)=intermediateWord3;
                        resultWord2=Actor2006_func_800365E4(argumentWord4,argumentWord5,argumentWord6,argumentWord7,0);
                        argumentWord4=privateAddress19+0xAC;
                        argumentWord5=(int)&originalFrame.sp40;
                        __asm__(""::"r"(argumentWord5));
                        Actor2006Field(privateAddress19,short*,0x12)=resultWord2;
                        resultWord2=retainedHeadingIndexOrVectorAddress17+0x60;
                        resultWord2&=255;
                        resultWord2*=2;
                        intermediateWord3=resultWord2+retainedTableOrVectorAddress18;
                        __asm__ volatile(""::"r"(intermediateWord3):"$6");
                        argumentWord6=retainedScalarOrVectorAddress16;
                        intermediateWord3=Actor2006Field(intermediateWord3,short*,0);
                        resultWord2+=retainedDistanceOrSineAddress22;
                        intermediateWord3*=2;
                        originalFrame.sp40=intermediateWord3;
                        resultWord2=Actor2006Field(resultWord2,short*,0);
                        intermediateWord3=0xC00;
                        originalFrame.sp48=intermediateWord3;
                        resultWord2*=2;
                        originalFrame.sp44=resultWord2;
                        Actor2006_func_8004F194(argumentWord4,argumentWord5,argumentWord6);
                        intermediateWord3=(int)&Actor2006_D_8006E164;
                        Actor2006Keep(intermediateWord3);
                        resultWord2=Actor2006Field(intermediateWord3,int*,0);
                        if(resultWord2==ownerAddress20){
                            Actor2006_D_8006E160=0;
                            Actor2006Field(intermediateWord3,int*,0)=0;
                        }
                        resultWord2=Actor2006Field(privateAddress19,unsigned char*,0x1D);
                        retainedScalarOrVectorAddress16=(int)&originalFrame.sp50;
                        resultWord2+=0xC0;
                        resultWord2&=255;
                        resultWord2*=2;
                        resultWord2+=retainedTableOrVectorAddress18;
                        intermediateWord3=Actor2006Field(resultWord2,short*,0);
                        argumentWord4=retainedScalarOrVectorAddress16;
                        resultWord2=(intermediateWord3*13)>>5;
                        originalFrame.sp50=resultWord2;
                        resultWord2=Actor2006Field(privateAddress19,unsigned char*,0x1D);
                        argumentWord5=retainedScalarOrVectorAddress16;
                        resultWord2+=0xC0;
                        resultWord2&=255;
                        resultWord2*=2;
                        resultWord2+=retainedDistanceOrSineAddress22;
                        Actor2006Keep(resultWord2);
                        intermediateWord3=Actor2006Field(resultWord2,short*,0);
                        resultWord2=Actor2006Field((int)&Actor2006_D_80070328,int*,0x44);
                        argumentWord6=privateAddress19;
                        originalFrame.sp58=0;
                        __asm__ volatile(""::"m"(originalFrame.sp58));
                        originalFrame.sp58=resultWord2;
                        resultWord2=(intermediateWord3*13)>>5;
                        originalFrame.sp54=resultWord2;
                        Actor2006_func_8004F194(argumentWord4,argumentWord5,argumentWord6);
                        Actor2006_func_80013D44(&originalFrame.sp50, (Actor2006Field(privateAddress19, unsigned char *, 0x1D) + 0x40) & 0xFF, 0, 0);
                        if (Actor2006Field((int)&Actor2006_D_80070328, int *, 0x280) < 0) {
                            Actor2006Field((int)&Actor2006_D_80070328, int *, 0x280) = 0;
                        }
                        Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0xBU;
                        Actor2006_func_80034F40(ownerAddress20, 0xB);
                        return;
                    }
                    resultWord2 = Actor2006Field(privateAddress19, int *, 0x24);
                    Actor2006Field(privateAddress19, int *, 0x24) = (int) (resultWord2 + 1);
                    Actor2006Field(privateAddress19, int *, 0x2C) = (int) ((resultWord2 + 2) * 2);
                    goto storeOriginalOuterState1;
                }
            storeOriginalOuterState1:
                Actor2006Field(privateAddress19, short *, 0x4A) = 0x5A;
                Actor2006Field(privateAddress19, short *, 0x48) = 0;
                Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 1U;
                Actor2006_func_80034F40(ownerAddress20, 1);
                goto clearOriginalOwnerFlagsAndContinue;
            }
        }
    clearOriginalOwnerFlagsAndContinue:
        Actor2006Field(ownerAddress20, int *, 0x18) = 0;
        resultWord2=Actor2006Field(privateAddress19,int*,0xA0);
        intermediateWord3=(int)&Actor2006_func_level_47_80074D7C;
        if((unsigned int)resultWord2>=(unsigned int)intermediateWord3){
            argumentWord5=0;
            argumentWord6=(int)&Actor2006_D_level_47_8008DF5C;
            Actor2006Keep(argumentWord6);
        originalOverlayCrcByte:
            intermediateWord3=Actor2006Field(privateAddress19,int*,0xA0);
            if((unsigned int)intermediateWord3<(unsigned int)argumentWord6){
                argumentWord4=0;
                resultWord2=Actor2006Field(intermediateWord3,unsigned char*,0);
                intermediateWord3=Actor2006Field(privateAddress19,int*,0xA4);
                resultWord2<<=8;
                intermediateWord3^=resultWord2;
                Actor2006Field(privateAddress19,int*,0xA4)=intermediateWord3;
                do{
                    intermediateWord3=Actor2006Field(privateAddress19,int*,0xA4);
                    resultWord2=intermediateWord3&0x8000;
                    if(intermediateWord3&0x8000)resultWord2=intermediateWord3*2^0x8005;
                    else resultWord2=intermediateWord3*2;
                    Actor2006Field(privateAddress19,int*,0xA4)=resultWord2;
                    argumentWord4++;
                    resultWord2=argumentWord4<8;
                }
                while(resultWord2);
                resultWord2=Actor2006Field(privateAddress19,int*,0xA0);
                argumentWord5++;
                resultWord2++;
                Actor2006Field(privateAddress19,int*,0xA0)=resultWord2;
                resultWord2=argumentWord5<64;
                if(resultWord2)goto originalOverlayCrcByte;
            }
        }
        intermediateWord3 = Actor2006Field(ownerAddress20, unsigned char *, 0x48);
        switch (intermediateWord3) {
        case 35:
            Actor2006_func_8003573C(ownerAddress20, 5, 0, 0);
            resultWord2 = Actor2006Field(privateAddress19, unsigned short *, 0x44) + 0xF;
            Actor2006Field(privateAddress19, unsigned short *, 0x44) = resultWord2;
            if ((short) resultWord2 >= 0xF1) {
                Actor2006Field(privateAddress19, unsigned short *, 0x44) = 0xF0U;
            }
            Actor2006_func_80035DDC(ownerAddress20, (short) Actor2006Field(privateAddress19, unsigned short *, 0x44), 0, 0, 5);
            retainedScalarOrVectorAddress16 = ownerAddress20 + 0xC;
            if (Actor2006_func_8004F334(retainedScalarOrVectorAddress16, (int)&Actor2006_D_80070328) >= 0x800) {
                if (Actor2006Field(Actor2006Field(privateAddress19,int*,0x40),int*,0) != 0) {
                produceOriginalTimer180AndState31:
                    Actor2006Field(privateAddress19, short *, 0x48) = 0xB4;
                    goto storeOriginalOuterState31AndReturn;
                }
                if (Actor2006_func_8004F334(retainedScalarOrVectorAddress16, privateAddress19) < 0x2C01) {
                    if (Actor2006Field(privateAddress19, short *, 0x48) == 0) {
                        argumentWord4=ownerAddress20;
                        argumentWord5=0;
                        resultWord2 = 0x3C;
                        goto storeOriginalTimerAndAnimate0;
                    }
                default:
                    return;
                }
                goto storeOriginalOuterState30AndReturn;
            }
            goto originalProduce14;
        case 14:
            intermediateWord3 = Actor2006Field(Actor2006Field(privateAddress19, int *, 0x58), int *, 0);
            Actor2006Field(intermediateWord3, unsigned char *, 0x10) = 0xD;
            Actor2006Field(intermediateWord3, unsigned char *, 0x11) = 0xA2;
            Actor2006Field(intermediateWord3, unsigned char *, 0x12) = 0x31;
            if (Actor2006_func_80055E84(ownerAddress20) >= 9) {
                Actor2006_SpawnMoby(0x4D, ownerAddress20);
                Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0x21U;
            }
        case 33:
            if(Actor2006_D_8006C770){
                argumentWord4=ownerAddress20;
                __asm__(""::"r"(argumentWord4));
                resultWord2=Actor2006Field(privateAddress19,int*,0x58);
                __asm__ volatile("":::"$5","memory");
                argumentWord5=0;
                __asm__(""::"r"(argumentWord5));
                intermediateWord3=Actor2006Field(resultWord2,int*,0);
                resultWord2=150;
                Actor2006Field(intermediateWord3,unsigned char*,16)=resultWord2;
                resultWord2=51;
                Actor2006Field(intermediateWord3,unsigned char*,17)=resultWord2;
                resultWord2=160;
                Actor2006Field(intermediateWord3,unsigned char*,18)=resultWord2;
                goto produceOriginalTimer120;
            }
            break;
        case 11:
            if (Actor2006_D_8006E048 == 1) {
                Actor2006Field(Actor2006Field(privateAddress19, int *, 0x58), unsigned char *, 0x49) = 1;
                Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0xCU;
            }
        case 12:
            if ((Actor2006_D_8006C770 != 0) && (Actor2006Field(ownerAddress20, unsigned char *, 0x3C) == 0xB)) {
                Actor2006_func_80034F40(ownerAddress20, 0xC);
            }
            if (Actor2006Field(ownerAddress20, unsigned char *, 0x48) != 0xB) {
                Actor2006_func_80013AE4(privateAddress19 + 0xAC, ownerAddress20 + 0xC);
            }
            Actor2006_func_8003585C(ownerAddress20, (Actor2006Field(privateAddress19, unsigned char *, 0x1D) + 0x80) & 0xFF, 7, 0, 0, 0);
            Actor2006_func_80035EE0(ownerAddress20, Actor2006Field(privateAddress19, unsigned char *, 0x1D), Actor2006Field(privateAddress19, short *, 0x10), 0, 0, 0);
            Actor2006Field(ownerAddress20, int *, 0x14) = (int) (Actor2006Field(ownerAddress20, int *, 0x14) + Actor2006Field(privateAddress19, short *, 0x12));
            Actor2006Field(privateAddress19, short *, 0x12) = (short) ((unsigned short) Actor2006Field(privateAddress19, short *, 0x12) - 0xC);
            if (Actor2006Field(ownerAddress20, int *, 0x14) < (Actor2006Field(privateAddress19, int *, 8) - 0x80)) {
                Actor2006_func_8004F178(privateAddress19 + 0xB8, ownerAddress20 + 0xC);
                Actor2006Field(ownerAddress20, int *, 0x54) = (int) ((Actor2006Field(privateAddress19, int *, 8) & 0xFFFFFF) | 0x80000000);
                Actor2006Field(Actor2006Field(privateAddress19, int *, 0x58), int *, 0x54) = (int) ((Actor2006Field(privateAddress19, int *, 8) & 0xFFFFFF) | 0x80000000);
                Actor2006_func_80034F40(ownerAddress20, 0xD);
                Actor2006_D_8007158F = 1;
                Actor2006_D_8006C408 = 0;
                Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0xFU;
            }
            Actor2006_func_80055D24(ownerAddress20, 4);
            return;
        case 15:
            resultWord2=Actor2006_func_80055E84(ownerAddress20);
            argumentWord4=(int)&originalFrame.sp60;
            __asm__(""::"r"(argumentWord4));
            retainedScalarOrVectorAddress16=resultWord2;
            Actor2006_func_8004F168(argumentWord4);
            intermediateWord3=Actor2006Field(ownerAddress20,unsigned char*,0x3D);
            resultWord2=13;
            if(intermediateWord3==resultWord2){
                resultWord2=(unsigned int)(retainedScalarOrVectorAddress16-1)<3;
                Actor2006Keep(resultWord2);
                if(resultWord2)goto originalParticleRand;
                resultWord2=(unsigned int)(retainedScalarOrVectorAddress16-18)<2;
                Actor2006Keep(resultWord2);
                if(resultWord2)goto originalParticleRand;
                resultWord2=(unsigned int)(retainedScalarOrVectorAddress16-31)<2;
                Actor2006Keep(resultWord2);
                if(resultWord2){
                originalParticleRand:
                    resultWord2=Actor2006_func_8003636C(0,255);
                    retainedScalarOrVectorAddress16=0;
                    retainedDifficultyScaleOrOwnerAddress21=(int)&Actor2006_D_80065920;
                    retainedTableOrVectorAddress18=(int)&originalFrame.sp40;
                    retainedHeadingIndexOrVectorAddress17=resultWord2;
                    do{
                        argumentWord4=retainedTableOrVectorAddress18;
                        argumentWord5=ownerAddress20+12;
                        argumentWord6=retainedHeadingIndexOrVectorAddress17&255;
                        argumentWord6*=2;
                        resultWord2=argumentWord6+retainedDifficultyScaleOrOwnerAddress21;
                        intermediateWord3=Actor2006Field(resultWord2,short*,0);
                        retainedHeadingIndexOrVectorAddress17+=16;
                        resultWord2=(intermediateWord3*25)>>10;
                        originalFrame.sp60=resultWord2;
                        intermediateWord3=Actor2006Field((int)&Actor2006_D_800658A0,short*,argumentWord6);
                        retainedScalarOrVectorAddress16++;
                        originalFrame.sp68=0;
                        resultWord2=(intermediateWord3*25)>>10;
                        originalFrame.sp64=resultWord2;
                        Actor2006_func_8004F178(argumentWord4,argumentWord5);
                        argumentWord4=1;
                        argumentWord5=13;
                        __asm__(""::"r"(argumentWord4),"r"(argumentWord5));
                        argumentWord6=retainedTableOrVectorAddress18;
                        resultWord2=Actor2006Field(privateAddress19,int*,8);
                        intermediateWord3=(int)Actor2006_SpawnParticle;
                        argumentWord7=(int)&originalFrame.sp60;
                        originalFrame.sp48=resultWord2;
                        ((void(*)(int,int,void*,void*))intermediateWord3)(argumentWord4,argumentWord5,argumentWord6,argumentWord7);
                        resultWord2=retainedScalarOrVectorAddress16<16;
                    }
                    while(resultWord2);
                }
            }
            else{
                intermediateWord3=Actor2006Field(privateAddress19,int*,8);
                resultWord2=Actor2006Field(ownerAddress20,int*,20);
                intermediateWord3-=resultWord2;
                resultWord2=intermediateWord3<901;
                retainedDifficultyScaleOrOwnerAddress21=600;
                if(!resultWord2){
                    resultWord2=1700;
                    retainedDifficultyScaleOrOwnerAddress21=resultWord2-intermediateWord3;
                }
                resultWord2=retainedDifficultyScaleOrOwnerAddress21<200;
                if(!resultWord2){
                    retainedScalarOrVectorAddress16=0;
                    retainedTableOrVectorAddress18=(int)&originalFrame.sp40;
                    retainedHeadingIndexOrVectorAddress17=(int)&Actor2006_D_80065920;
                    do{
                        resultWord2=Actor2006Field(retainedHeadingIndexOrVectorAddress17,short*,0);
                        initializedSignedProduct64=(long long)resultWord2*(long long)retainedDifficultyScaleOrOwnerAddress21;
                        __asm__ volatile(""::"x"(initializedSignedProduct64));
                        __asm__("":"=l"(cosineProductLow):"x"(initializedSignedProduct64));
                        completeProductProjection8=cosineProductLow;
                        Actor2006Keep(completeProductProjection8);
                        resultWord2=completeProductProjection8>>12;
                        originalFrame.sp40=resultWord2;
                        resultWord2=retainedScalarOrVectorAddress16<<5;
                        resultWord2=Actor2006Field((int)&Actor2006_D_800658A0,short*,resultWord2);
                        initializedSignedProduct64=(long long)resultWord2*(long long)retainedDifficultyScaleOrOwnerAddress21;
                        __asm__ volatile(""::"x"(initializedSignedProduct64));
                        argumentWord4=retainedTableOrVectorAddress18;
                        argumentWord5=ownerAddress20+12;
                        argumentWord6=retainedTableOrVectorAddress18;
                        __asm__(""::"r"(argumentWord4),"r"(argumentWord5),"r"(argumentWord6));
                        retainedHeadingIndexOrVectorAddress17+=32;
                        retainedScalarOrVectorAddress16++;
                        originalFrame.sp48=0;
                        __asm__("":"=l"(sineProductLow):"x"(initializedSignedProduct64),"m"(originalFrame.sp48));
                        completeProductProjection8=sineProductLow;
                        Actor2006Keep(completeProductProjection8);
                        resultWord2=completeProductProjection8>>12;
                        originalFrame.sp44=resultWord2;
                        Actor2006_func_8004F194(argumentWord4,argumentWord5,argumentWord6);
                        argumentWord4=1;
                        argumentWord5=13;
                        __asm__(""::"r"(argumentWord4),"r"(argumentWord5));
                        argumentWord6=retainedTableOrVectorAddress18;
                        resultWord2=Actor2006Field(privateAddress19,int*,8);
                        intermediateWord3=(int)Actor2006_SpawnParticle;
                        argumentWord7=(int)&originalFrame.sp60;
                        originalFrame.sp48=resultWord2;
                        ((void(*)(int,int,void*,void*))intermediateWord3)(argumentWord4,argumentWord5,argumentWord6,argumentWord7);
                        resultWord2=retainedScalarOrVectorAddress16<16;
                    }
                    while(resultWord2);
                }
            }
            if (Actor2006_D_8006C770 != 0) {
                if (Actor2006Field(ownerAddress20, unsigned char *, 0x3D) != 0xF) {
                    Actor2006_func_8003BABC(ownerAddress20, 0, 0);
                }
                Actor2006_func_80034F40(ownerAddress20, 0xF);
            }
            intermediateWord3=Actor2006Field(ownerAddress20,int*,0x14);
            intermediateWord3-=15;
            Actor2006Field(ownerAddress20,int*,0x14)=intermediateWord3;
            if (intermediateWord3 < (Actor2006Field(privateAddress19, int *, 8) - 0x400)) {
                Actor2006Field(ownerAddress20, int *, 0x1C) = (int) (Actor2006Field(ownerAddress20, int *, 0x1C) & 0x7FFFFFFF);
            }
            if (Actor2006Field(ownerAddress20, int *, 0x14) < (Actor2006Field(privateAddress19, int *, 8) - 0x800)) {
                retainedDifficultyScaleOrOwnerAddress21 = Actor2006_SpawnMoby(0x84, ownerAddress20);
                Actor2006Keep(retainedDifficultyScaleOrOwnerAddress21);
                if (retainedDifficultyScaleOrOwnerAddress21 != 0) {
                    retainedTableOrVectorAddress18 = Actor2006Field(retainedDifficultyScaleOrOwnerAddress21, int *, 0);
                    Actor2006_func_80055F14(Actor2006Field(privateAddress19, int *, 0x58), 0, &originalFrame.sp70);
                    Actor2006_func_80055F14(Actor2006Field(privateAddress19, int *, 0x58), 1, &originalFrame.sp80);
                    Actor2006_func_8004F194(&originalFrame.sp70, &originalFrame.sp70, &originalFrame.sp80);
                    Actor2006_func_8004F110(&originalFrame.sp70, 1);
                    retainedHeadingIndexOrVectorAddress17 = retainedDifficultyScaleOrOwnerAddress21 + 0xC;
                    Actor2006_func_8004F178(retainedHeadingIndexOrVectorAddress17, &originalFrame.sp70);
                    Actor2006Field(retainedDifficultyScaleOrOwnerAddress21, unsigned char *, 0x46) = (unsigned char) Actor2006Field(Actor2006Field(privateAddress19, int *, 0x58), unsigned char *, 0x46);
                    Actor2006Field(retainedDifficultyScaleOrOwnerAddress21, unsigned char *, 0x45) = (unsigned char) Actor2006Field(Actor2006Field(privateAddress19, int *, 0x58), unsigned char *, 0x45);
                    Actor2006Field(retainedTableOrVectorAddress18,short*,0) = 0;
                    Actor2006Field(retainedDifficultyScaleOrOwnerAddress21, unsigned char *, 0x4C) = 0x40;
                    Actor2006Field(retainedDifficultyScaleOrOwnerAddress21, unsigned char *, 0x4E) = 0x40;
                    Actor2006Field(privateAddress19, unsigned char *, 0x1D) = Actor2006_func_8004E880(Actor2006Field(privateAddress19, int *, 0) - Actor2006Field(retainedDifficultyScaleOrOwnerAddress21, int *, 0xC), Actor2006Field(privateAddress19, int *, 4) - Actor2006Field(retainedDifficultyScaleOrOwnerAddress21, int *, 0x10), 0);
                    Actor2006Field(privateAddress19, short *, 0x10) = 0xAF;
                    Actor2006Field(privateAddress19, short *, 0x12) = Actor2006_func_800365E4(retainedHeadingIndexOrVectorAddress17, privateAddress19, 0xAF, -6, 0);
                    Actor2006Field(privateAddress19, int *, 0xC4) = retainedDifficultyScaleOrOwnerAddress21;
                    Actor2006_func_8003BB10(retainedDifficultyScaleOrOwnerAddress21, 2, 0);
                    Actor2006_func_80034F80(Actor2006Field(privateAddress19, int *, 0x58), 1);
                    Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0x15U;
                    return;
                }
            }
            break;
        case 21:
            resultWord2 = Actor2006Field(privateAddress19, int *, 0xC4);
            Actor2006_func_8003585C(Actor2006Field(privateAddress19, int *, 0xC4), Actor2006_func_8004E880(Actor2006Field((int)&Actor2006_D_80070328, int *, 0) - Actor2006Field(resultWord2, int *, 0xC), Actor2006Field((int)&Actor2006_D_80070328, int *, 4) - Actor2006Field(resultWord2, int *, 0x10), 0), 7, 0, 0, 0);
            argumentWord4 = Actor2006Field(privateAddress19, int *, 0xC4);
            intermediateWord3=Actor2006Field(argumentWord4,unsigned char*,0x45);
            Actor2006Keep(intermediateWord3);
            resultWord2=intermediateWord3&255;
            if(resultWord2){
                if((unsigned int)resultWord2>=129U ? (resultWord2=intermediateWord3-1,1):(resultWord2=intermediateWord3-1,0))resultWord2=intermediateWord3+1;
                Actor2006Field(argumentWord4,unsigned char*,0x45)=resultWord2;
            }
            Actor2006_func_80035EE0(Actor2006Field(privateAddress19, int *, 0xC4), Actor2006Field(privateAddress19, unsigned char *, 0x1D), Actor2006Field(privateAddress19, short *, 0x10), 0, 0, 0);
            retainedHeadingIndexOrVectorAddress17=(int)&originalFrame.sp80;
            argumentWord4=retainedHeadingIndexOrVectorAddress17;
            __asm__(""::"r"(argumentWord4));
            retainedScalarOrVectorAddress16=privateAddress19+0xB8;
            argumentWord5 = Actor2006Field(privateAddress19, int *, 0xC4);
            Actor2006Field(argumentWord5, int *, 0x14) = (int) (Actor2006Field(argumentWord5, int *, 0x14) + Actor2006Field(privateAddress19, short *, 0x12));
            Actor2006Field(privateAddress19, short *, 0x12) = (short) ((unsigned short) Actor2006Field(privateAddress19, short *, 0x12) - 6);
            Actor2006_func_8004F1C8(argumentWord4, Actor2006Field(privateAddress19, int *, 0xC4) + 0xC, retainedScalarOrVectorAddress16);
            Actor2006_func_8004F110(&originalFrame.sp80, 3);
            Actor2006_func_8004F194(retainedScalarOrVectorAddress16, retainedScalarOrVectorAddress16, &originalFrame.sp80);
            Actor2006_func_80013AE4(privateAddress19 + 0xAC, retainedScalarOrVectorAddress16);
            intermediateWord3 = Actor2006Field(ownerAddress20, int *, 0x14);
            if ((Actor2006Field(privateAddress19, int *, 8) - 0xC00) < intermediateWord3) {
                resultWord2=intermediateWord3-15;
                Actor2006Keep(resultWord2);
                Actor2006Field(ownerAddress20,int*,0x14)=resultWord2;
            }
            else {
                argumentWord4 = Actor2006Field(privateAddress19, int *, 0x58);
                if (argumentWord4 != 0) {
                    Actor2006_func_80055B18(argumentWord4);
                    Actor2006Field(privateAddress19, int *, 0x58) = 0;
                }
            }
            if (Actor2006Field(privateAddress19, short *, 0x12) < 0) {
                argumentWord4 = Actor2006Field(privateAddress19, int *, 0xC4);
                if (Actor2006Field(argumentWord4, int *, 0x14) < Actor2006Field(privateAddress19, int *, 8)) {
                    Actor2006_func_8003BB10(argumentWord4, 3, 0);
                    Actor2006Field(Actor2006Field(privateAddress19, int *, 0xC4), int *, 0x14) = (int) Actor2006Field(privateAddress19, int *, 8);
                    Actor2006Field(privateAddress19, int *, 0xA8) = 0x3C;
                    Actor2006_func_80013B7C(1);
                    Actor2006Field(ownerAddress20, unsigned char *, 0x41) = 0;
                    Actor2006Field(ownerAddress20, unsigned char *, 0x4C) = 0;
                    Actor2006Field(ownerAddress20, unsigned char *, 0x4D) = 0;
                    Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0x16U;
                    return;
                }
            }
            break;
        case 22:
            resultWord2 = Actor2006Field(privateAddress19, int *, 0xC4);
            Actor2006_func_8003585C(Actor2006Field(privateAddress19, int *, 0xC4), Actor2006_func_8004E880(Actor2006Field((int)&Actor2006_D_80070328, int *, 0) - Actor2006Field(resultWord2, int *, 0xC), Actor2006Field((int)&Actor2006_D_80070328, int *, 4) - Actor2006Field(resultWord2, int *, 0x10), 0), 7, 0, 0, 0);
            if (Actor2006_func_800359A4(privateAddress19 + 0xA8, 4) != 0) {
                retainedScalarOrVectorAddress16 = Actor2006Field(Actor2006Field(privateAddress19, int *, 0xC4), int *, 0);
                Actor2006Field(retainedScalarOrVectorAddress16, short *, 6) = Actor2006_func_8004E880(Actor2006Field((int)&Actor2006_D_80070328, int *, 0) - Actor2006Field(ownerAddress20, int *, 0xC), Actor2006Field((int)&Actor2006_D_80070328, int *, 4) - Actor2006Field(ownerAddress20, int *, 0x10), 0);
                Actor2006Field(Actor2006Field(privateAddress19, int *, 0xC4), unsigned char *, 0x48) = 1;
                Actor2006Field(privateAddress19, int *, 0xA8) = 0x1E;
                Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0x17U;
                return;
            }
            break;
        case 23:
            if ((Actor2006_D_8006C7B4 & 1) && (Actor2006_func_800359A4(privateAddress19 + 0xA8, 4) != 0)) {
                argumentWord4 = Actor2006Field(privateAddress19, int *, 0x38);
                if (argumentWord4 >= 0) {
                    Actor2006_func_80028154(argumentWord4);
                    Actor2006Field(privateAddress19, int *, 0x38) = -1;
                }
                Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0x18U;
                Actor2006Field(privateAddress19, int *, 0xA8) = 0x78;
                return;
            }
            break;
        case 24:
            Actor2006_func_8004F178(&originalFrame.sp90, ownerAddress20 + 0xC);
            originalFrame.sp98 += 0xC00;
            Actor2006_func_800492DC(&originalFrame.sp90);
            if (Actor2006_func_800359A4(privateAddress19 + 0xA8, 4) != 0) {
                intermediateWord3 = Actor2006Field(privateAddress19, int *, 0xC8);
                if (intermediateWord3 != -1) {
                    Actor2006_func_8004F178(Actor2006_D_8006C550 + (intermediateWord3 * 0x58) + 0xC, (int)&Actor2006_D_80070328);
                    Actor2006Field(((Actor2006Field(privateAddress19, int *, 0xC8) * 0x58) + Actor2006_D_8006C550), unsigned char *, 0x48) = 1;
                }
                Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0x19U;
                Actor2006Field(privateAddress19, int *, 0xA8) = 0xB4;
                return;
            }
            break;
        case 25:
            if (Actor2006_func_800359A4(privateAddress19 + 0xA8, 4) != 0) {
                resultWord2 = Actor2006Field(privateAddress19, int *, 0xCC);
                if (resultWord2 != 0) {
                    Actor2006_func_8004F178(ownerAddress20 + 0xC, Actor2006Field(resultWord2, int *, 0xC));
                    Actor2006Field(ownerAddress20, unsigned char *, 0x46) = Actor2006_func_8004E880(Actor2006Field(privateAddress19, int *, 0) - Actor2006Field(ownerAddress20, int *, 0xC), Actor2006Field(privateAddress19, int *, 4) - Actor2006Field(ownerAddress20, int *, 0x10), 0);
                }
                originalFrame.spA0 = (int) Actor2006Field((int)(int)&Actor2006_D_80065920,short*,(Actor2006_func_8003617C(0x10, Actor2006_func_8004E880(Actor2006Field(privateAddress19, int *, 0) - Actor2006Field(ownerAddress20, int *, 0xC), Actor2006Field(privateAddress19, int *, 4) - Actor2006Field(ownerAddress20, int *, 0x10), 0)))*2);
                resultWord2=Actor2006_func_8003617C(16,Actor2006_func_8004E880(Actor2006Field(privateAddress19,int*,0)-Actor2006Field(ownerAddress20,int*,12),Actor2006Field(privateAddress19,int*,4)-Actor2006Field(ownerAddress20,int*,16),0));
                retainedScalarOrVectorAddress16=(int)&originalFrame.spA0;
                argumentWord4=retainedScalarOrVectorAddress16;
                argumentWord5=retainedScalarOrVectorAddress16;
                __asm__(""::"r"(argumentWord4),"r"(argumentWord5));
                resultWord2*=2;
                Actor2006Keep(resultWord2);
                retainedHeadingIndexOrVectorAddress17=ownerAddress20+12;
                resultWord2=Actor2006Field((int)&Actor2006_D_800658A0,short*,resultWord2);
                originalFrame.spA8 = 0;
                originalFrame.spA4 = (int) resultWord2;
                Actor2006_func_8004F194(argumentWord4,argumentWord5,retainedHeadingIndexOrVectorAddress17);
                originalFrame.spA8 = Actor2006Field(privateAddress19, int *, 8) + 0xC04;
                Actor2006Field(ownerAddress20, unsigned char *, 0x41) = 1;
                Actor2006Field(ownerAddress20, unsigned char *, 0x4C) = 0x20;
                Actor2006Field(ownerAddress20, unsigned char *, 0x4D) = 1;
                Actor2006Field(ownerAddress20, int *, 0x54) = (int) ((Actor2006Field(privateAddress19, int *, 8) & 0xFFFFFF) | 0x80000000);
                Actor2006_func_80013AE4(&originalFrame.spA0, retainedHeadingIndexOrVectorAddress17);
                Actor2006Field(ownerAddress20, int *, 0x14) = (int) (Actor2006Field(privateAddress19, int *, 8) - 0x800);
                Actor2006_func_80034F80(ownerAddress20, 0x10);
                Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0x1AU;
                Actor2006Field(privateAddress19, int *, 0xA8) = 0xF0;
                return;
            }
            break;
        case 26:
            Actor2006Field(ownerAddress20, int *, 0x14) = (int) (Actor2006Field(ownerAddress20, int *, 0x14) + 0xF);
            if ((Actor2006_func_800359A4(privateAddress19 + 0xA8, 4) != 0) && (Actor2006_D_8006C770 != 0)) {
                Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0x1BU;
                Actor2006_func_800584BC(6, 0x45);
                return;
            }
            break;
        case 1:
            if (Actor2006_D_8006C770 != 0) {
                if (Actor2006Field(Actor2006Field(privateAddress19,int*,0x40),int*,0) == 0) {
                    if (Actor2006Field(ownerAddress20, unsigned char *, 0x3D) != 0) {
                        Actor2006_D_8006C770 = 0;
                        Actor2006Field(ownerAddress20, unsigned char *, 0x40) = 0x72;
                        Actor2006Field(ownerAddress20, unsigned char *, 0x3D) = 0U;
                        Actor2006Field(ownerAddress20, unsigned char *, 0x3F) = 0;
                        Actor2006_func_80035734(ownerAddress20);
                        Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0U;
                        return;
                    }
                    goto clearOriginalOuterStateAndReturn;
                }
                else {
                    goto originalProduceTimer180;
                }
            }
            break;
        case 4:
            intermediateWord3 = Actor2006Field(Actor2006Field(privateAddress19, int *, 0x58), int *, 0);
            Actor2006Field(intermediateWord3, unsigned char *, 0x10) = 0x33;
            Actor2006Field(intermediateWord3, unsigned char *, 0x11) = 0x96;
            Actor2006Field(intermediateWord3, unsigned char *, 0x12) = 0xA0;
            if (Actor2006_D_8006C770 != 0) {
                Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 5U;
                Actor2006_func_80034F40(ownerAddress20, 5);
                return;
            }
            break;
        case 5:
            Actor2006_func_8003573C(ownerAddress20, 5, 0, 0);
            if (Actor2006_D_8006C770 != 0) {
                Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 8U;
                Actor2006_func_80034F40(ownerAddress20, 8);
                return;
            }
            break;
        case 8:
            Actor2006_func_8003573C(ownerAddress20,5,0,0);
            resultWord2=Actor2006_D_8006C770;
            if(!resultWord2)break;
            resultWord2=Actor2006Field(privateAddress19,int*,0x40);
            resultWord2=Actor2006Field(resultWord2,int*,0);
            argumentWord4=ownerAddress20;
            if(resultWord2){
                resultWord2=Actor2006Field(privateAddress19,int*,0x58);
                argumentWord5=10;
                intermediateWord3=Actor2006Field(resultWord2,int*,0);
                resultWord2=150;
                Actor2006Field(intermediateWord3,unsigned char*,16)=resultWord2;
                resultWord2=51;
                Actor2006Field(intermediateWord3,unsigned char*,17)=resultWord2;
                resultWord2=160;
                Actor2006Field(intermediateWord3,unsigned char*,18)=resultWord2;
                __asm__ volatile(""::"m"(Actor2006Field(privateAddress19,int*,0x40)));
                resultWord2=10;
                goto storeOriginalStateAndAnimate;
            }
            argumentWord5=9;
            __asm__ volatile(""::"r"(argumentWord5):"$2");
            resultWord2=9;
            Actor2006Field(ownerAddress20,unsigned char*,0x48)=resultWord2;
            Actor2006_func_80034F40(argumentWord4,argumentWord5);
            intermediateWord3=Actor2006Field(privateAddress19,short*,0x54);
            resultWord2=2;
            if(intermediateWord3==resultWord2){
                resultWord2=34;
                Actor2006Field(ownerAddress20,unsigned char*,0x48)=resultWord2;
                return;
            }
            break;
        case 34:
            resultWord2=Actor2006_func_80055E84(ownerAddress20);
            resultWord2=resultWord2<50;
            argumentWord4=ownerAddress20;
            if(!resultWord2){
                argumentWord4=0x2F8;
                resultWord2=(int)Actor2006_SpawnMoby;
                __asm__ volatile("":::"$5","memory");
                argumentWord5=ownerAddress20;
                Actor2006Field(privateAddress19,int*,0x50)=0;
                ((int(*)(int,void*))resultWord2)(argumentWord4,argumentWord5);
                Actor2006Field(privateAddress19, unsigned short *, 0x56) = (unsigned short) (Actor2006Field(privateAddress19, unsigned short *, 0x56) - 1);
                Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 9U;
            case 9:
                argumentWord4=ownerAddress20;
            }
            Actor2006_func_8003573C(argumentWord4, 5, 0, 0);
            resultWord2=Actor2006_D_8006C770;
            argumentWord4=0x2F8;
            if(resultWord2){
                resultWord2=(int)Actor2006_SpawnMoby;
                __asm__ volatile("":::"$5","memory");
                argumentWord5=ownerAddress20;
                Actor2006Field(privateAddress19,int*,0x50)=0;
                ((int(*)(int,void*))resultWord2)(argumentWord4,argumentWord5);
                Actor2006Field(privateAddress19, unsigned short *, 0x56) = (unsigned short) (Actor2006Field(privateAddress19, unsigned short *, 0x56) - 1);
                if (Actor2006Field(privateAddress19, short *, 0x54) == 2) {
                    Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0x22U;
                }
            }
            resultWord2=Actor2006Field(privateAddress19,short*,0x56);
            argumentWord4=ownerAddress20;
            if(resultWord2<=0)goto originalCase9Color;
            resultWord2=Actor2006Field(privateAddress19,int*,0x40);
            resultWord2=Actor2006Field(resultWord2,int*,0);
            if(resultWord2)goto originalCase9Color;
            resultWord2=retainedDistanceOrSineAddress22<0xC00;
            Actor2006Keep(resultWord2);
            if(resultWord2){
            originalCase9Color:
                resultWord2=Actor2006Field(privateAddress19,int*,0x58);
                argumentWord5=10;
                intermediateWord3=Actor2006Field(resultWord2,int*,0);
                resultWord2=150;
                Actor2006Field(intermediateWord3,unsigned char*,16)=resultWord2;
                resultWord2=51;
                Actor2006Field(intermediateWord3,unsigned char*,17)=resultWord2;
                resultWord2=160;
                Actor2006Field(intermediateWord3,unsigned char*,18)=resultWord2;
                __asm__ volatile(""::"m"(Actor2006Field(privateAddress19,short*,0x56)));
                resultWord2=10;
                goto storeOriginalStateAndAnimate;
            }
            break;
        case 10:
            resultWord2=Actor2006_D_8006C770;
            if(resultWord2 ? (resultWord2=retainedDistanceOrSineAddress22<0x800,1):(resultWord2=retainedDistanceOrSineAddress22<0x800,0)){
                if(resultWord2){
                    argumentWord4=ownerAddress20;
                    argumentWord5=14;
                    __asm__ volatile(""::"r"(argumentWord4),"r"(argumentWord5):"$2");
                    resultWord2=14;
                    Actor2006Field(privateAddress19,short*,0x48)=0;
                    Actor2006Field(ownerAddress20,unsigned char*,0x48)=resultWord2;
                    Actor2006_func_80034F40(argumentWord4,argumentWord5);
                    resultWord2=retainedDistanceOrSineAddress22<0x1800;
                    goto originalCase10Distance;
                }
                resultWord2=Actor2006Field(privateAddress19,int*,0x40);
                resultWord2=Actor2006Field(resultWord2,int*,0);
                if(resultWord2 ? (resultWord2=50,1):(resultWord2=50,0)){
                    Actor2006Field(privateAddress19,short*,0x44)=resultWord2;
                    resultWord2=180;
                    Actor2006Field(privateAddress19,short*,0x48)=resultWord2;
                    intermediateWord3=Actor2006Field(ownerAddress20,unsigned char*,0x3D);
                    __asm__ volatile("":::"$2","memory");
                    resultWord2=2;
                    argumentWord4=ownerAddress20;
                    if(intermediateWord3!=resultWord2){
                        resultWord2=0x72;
                        Actor2006_D_8006C770=0;
                        Actor2006Field(ownerAddress20,unsigned char*,0x40)=resultWord2;
                        resultWord2=2;
                        Actor2006Field(ownerAddress20,unsigned char*,0x3D)=resultWord2;
                        Actor2006Field(ownerAddress20,unsigned char*,0x3F)=0;
                        Actor2006_func_80035734(argumentWord4);
                    }
                    resultWord2=31;
                    Actor2006Field(ownerAddress20,unsigned char*,0x48)=resultWord2;
                }
                resultWord2=retainedDistanceOrSineAddress22<0x1800;
            originalCase10Distance:
                if(resultWord2 ? (resultWord2=120,1):(resultWord2=120,0)){
                    Actor2006Field(privateAddress19,short*,0x48)=resultWord2;
                    intermediateWord3=Actor2006Field(ownerAddress20,unsigned char*,0x3D);
                    __asm__ volatile("":::"$2","memory");
                    resultWord2=2;
                    argumentWord4=ownerAddress20;
                    if(intermediateWord3!=resultWord2){
                        resultWord2=0x72;
                        Actor2006_D_8006C770=0;
                        Actor2006Field(ownerAddress20,unsigned char*,0x40)=resultWord2;
                        resultWord2=2;
                        Actor2006Field(ownerAddress20,unsigned char*,0x3D)=resultWord2;
                        Actor2006Field(ownerAddress20,unsigned char*,0x3F)=0;
                        Actor2006_func_80035734(argumentWord4);
                    }
                    resultWord2=35;
                    goto storeOriginalOuterState35AndReturn;
                }
            produceOriginalTimer120:
                argumentWord4=ownerAddress20;
                argumentWord5=0;
                resultWord2 = 0x78;
            storeOriginalTimerAndAnimate0:
                Actor2006Field(privateAddress19, short *, 0x48) = resultWord2;
                Actor2006Field(argumentWord4, unsigned char *, 0x48) = 0;
                Actor2006_func_80034F40(argumentWord4,argumentWord5);
                return;
            }
            break;
        case 0:
            retainedScalarOrVectorAddress16 = Actor2006Field(ownerAddress20, unsigned char *, 0x3C) == 0;
            Actor2006_func_8003573C(ownerAddress20, 5, 0, 0);
            if (retainedScalarOrVectorAddress16 == 0) {
                if (Actor2006Field(ownerAddress20, unsigned char *, 0x3D) != 0) {
                    Actor2006_D_8006C770 = 0;
                    Actor2006Field(ownerAddress20, unsigned char *, 0x40) = 0x72;
                    Actor2006Field(ownerAddress20, unsigned char *, 0x3D) = 0U;
                    Actor2006Field(ownerAddress20, unsigned char *, 0x3F) = 0;
                    Actor2006_func_80035734(ownerAddress20);
                    return;
                }
            }
            else {
                if (Actor2006Field(privateAddress19, int *, 0x3C) == 1) {
                    resultWord2=retainedPrivateDistance23<0x1401;
                    Actor2006Keep(resultWord2);
                    Actor2006Field(privateAddress19,int*,0x3C)=0;
                    if(!resultWord2){
                        Actor2006Field(privateAddress19, unsigned short *, 0x44) = 0x32U;
                    storeOriginalOuterState30AndReturn:
                        Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0x1EU;
                        return;
                    }
                    __asm__ volatile("":::"$2");
                    resultWord2=retainedDistanceOrSineAddress22 < 0x1800;
                    Actor2006Keep(resultWord2);
                    if(resultWord2) {
                        if (Actor2006Field(ownerAddress20, unsigned char *, 0x3D) != 2) {
                            Actor2006_D_8006C770 = 0;
                            Actor2006Field(ownerAddress20, unsigned char *, 0x40) = 0x72;
                            Actor2006Field(ownerAddress20, unsigned char *, 0x3D) = 2U;
                            Actor2006Field(ownerAddress20, unsigned char *, 0x3F) = 0;
                            Actor2006_func_80035734(ownerAddress20);
                        }
                        Actor2006Field(privateAddress19, short *, 0x48) = 0x78;
                        Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0x23U;
                    }
                    goto testOriginalPrivate40Flag;
                }
            testOriginalPrivate40Flag:
                if (Actor2006Field(Actor2006Field(privateAddress19,int*,0x40),int*,0) != 0) {
                    Actor2006Field(privateAddress19, unsigned short *, 0x44) = 0x32U;
                    goto produceOriginalTimer180AndState31;
                }
                intermediateWord3 = Actor2006Field(privateAddress19, int *, 0x24);
                argumentWord4=1;
                Actor2006Keep(argumentWord4);
                if(intermediateWord3==argumentWord4)goto originalInner1;
                resultWord2=intermediateWord3<2;
                if(!resultWord2)goto originalInnerCheck2;
                if(!intermediateWord3)goto originalInner0;
                return;
            originalInnerCheck2:
                resultWord2=2;
                if(intermediateWord3==resultWord2)goto originalInner2;
                return;
                {
                originalInner0:
                    resultWord2=Actor2006Field(privateAddress19,short*,0x48);
                    Actor2006Keep(resultWord2);
                    if(resultWord2)return;
                    resultWord2=Actor2006Field(privateAddress19,short*,0x82);
                    __asm__ volatile(""::"r"(resultWord2),"i"(0));
                    Actor2006Field(privateAddress19,int*,0x3C)=argumentWord4;
                    if(resultWord2)return;
                    resultWord2=retainedDistanceOrSineAddress22<0x800;
                    Actor2006Keep(resultWord2);
                    if(resultWord2)goto originalProduce14;
                    resultWord2=retainedDistanceOrSineAddress22<0x1C01;
                    Actor2006Keep(resultWord2);
                    if(resultWord2)return;
                    resultWord2=Actor2006_rand();
                    resultWord2&=255;
                    resultWord2=resultWord2<127;
                    argumentWord4=ownerAddress20;
                    if(!resultWord2)goto originalSecondRand0;
                    argumentWord5=4;
                    resultWord2=1;
                    Actor2006Field(privateAddress19,short*,0x54)=resultWord2;
                    resultWord2=3;
                    Actor2006Field(privateAddress19,short*,0x56)=resultWord2;
                    __asm__ volatile(""::"i"(0));
                    resultWord2=4;
                    goto storeOriginalStateAndAnimate;
                originalSecondRand0:
                    __asm__ volatile(""::"r"(argumentWord4));
                    resultWord2=Actor2006_rand();
                    resultWord2&=255;
                    resultWord2=resultWord2<127;
                    argumentWord4=ownerAddress20;
                    if(resultWord2)goto produceOriginalOuterState3;
                    intermediateWord3=Actor2006Field(ownerAddress20,unsigned char*,0x3D);
                    resultWord2=2;
                    if(intermediateWord3!=resultWord2){
                        resultWord2=0x72;
                        Actor2006_D_8006C770=0;
                        Actor2006Field(ownerAddress20,unsigned char*,0x40)=resultWord2;
                        resultWord2=2;
                        Actor2006Field(ownerAddress20,unsigned char*,0x3D)=resultWord2;
                        Actor2006Field(ownerAddress20,unsigned char*,0x3F)=0;
                        Actor2006_func_80035734(ownerAddress20);
                    }
                    resultWord2=300;
                    Actor2006Field(privateAddress19,short*,0x48)=resultWord2;
                    resultWord2=35;
                storeOriginalOuterState35AndReturn:
                    Actor2006Field(ownerAddress20,unsigned char*,0x48)=resultWord2;
                    return;
                originalInner1:
                    Actor2006Keep(argumentWord4);
                    resultWord2=Actor2006Field(privateAddress19,short*,0x48);
                    Actor2006Keep(resultWord2);
                    if(resultWord2)return;
                    resultWord2=Actor2006Field(privateAddress19,short*,0x82);
                    __asm__ volatile(""::"r"(resultWord2),"i"(1));
                    Actor2006Field(privateAddress19,int*,0x3C)=argumentWord4;
                    if(resultWord2)return;
                    resultWord2=retainedDistanceOrSineAddress22<0x800;
                    Actor2006Keep(resultWord2);
                    if(resultWord2)goto originalProduce14;
                    resultWord2=retainedDistanceOrSineAddress22<0x1C01;
                    Actor2006Keep(resultWord2);
                    if(resultWord2)return;
                    resultWord2=Actor2006_rand();
                    resultWord2&=255;
                    resultWord2=resultWord2<127;
                    if(resultWord2)goto scaleOriginalDifficultyCounter;
                    resultWord2=Actor2006_rand();
                    resultWord2&=255;
                    resultWord2=resultWord2<127;
                    argumentWord4=ownerAddress20;
                    if(resultWord2)goto produceOriginalOuterState3;
                    argumentWord5=4;
                    resultWord2=1;
                    Actor2006Field(privateAddress19,short*,0x54)=resultWord2;
                    resultWord2=3;
                    Actor2006Field(privateAddress19,short*,0x56)=resultWord2;
                    __asm__ volatile(""::"i"(1));
                    resultWord2=4;
                    goto storeOriginalStateAndAnimate;
                originalInner2:
                    resultWord2=Actor2006Field(privateAddress19,short*,0x48);
                    Actor2006Keep(resultWord2);
                    if(resultWord2)return;
                    resultWord2=Actor2006Field(privateAddress19,short*,0x82);
                    __asm__ volatile(""::"r"(resultWord2),"i"(2));
                    Actor2006Field(privateAddress19,int*,0x3C)=argumentWord4;
                    if(resultWord2)return;
                    resultWord2=retainedDistanceOrSineAddress22<0x800;
                    Actor2006Keep(resultWord2);
                    if(resultWord2)goto originalProduce14;
                    resultWord2=retainedDistanceOrSineAddress22<0x1C01;
                    Actor2006Keep(resultWord2);
                    if(resultWord2)return;
                    resultWord2=Actor2006_rand();
                    resultWord2&=255;
                    resultWord2=resultWord2<127;
                    if(!resultWord2)goto originalSecondRand2;
                scaleOriginalDifficultyCounter:
                    intermediateWord3=Actor2006Field(privateAddress19,int*,0x24);
                    resultWord2=2;
                    Actor2006Field(privateAddress19,short*,0x54)=resultWord2;
                    resultWord2=intermediateWord3*4;
                    intermediateWord3=resultWord2+intermediateWord3;
                    resultWord2=intermediateWord3*2;
                    Actor2006Field(privateAddress19,short*,0x56)=resultWord2;
                    resultWord2=retainedDifficultyScaleOrOwnerAddress21<6;
                    if(resultWord2 ? (resultWord2=retainedDifficultyScaleOrOwnerAddress21<11,1):(resultWord2=retainedDifficultyScaleOrOwnerAddress21<11,0)){
                        if(resultWord2)goto originalDifficultyDone;
                    }
                    intermediateWord3=(short)(intermediateWord3*2);
                    resultWord2=intermediateWord3*2;
                    resultWord2+=intermediateWord3;
                    resultWord2>>=2;
                    Actor2006Field(privateAddress19,short*,0x56)=resultWord2;
                originalDifficultyDone:
                    resultWord2=4;
                    Actor2006Field(ownerAddress20,unsigned char*,0x48)=resultWord2;
                    Actor2006_func_80034F40(ownerAddress20,4);
                    return;
                originalSecondRand2:
                    resultWord2=Actor2006_rand();
                    resultWord2&=255;
                    resultWord2=resultWord2<127;
                    argumentWord4=ownerAddress20;
                    if(resultWord2)goto produceOriginalOuterState3;
                    argumentWord5=4;
                    resultWord2=1;
                    Actor2006Field(privateAddress19,short*,0x54)=resultWord2;
                    resultWord2=3;
                    Actor2006Field(privateAddress19,short*,0x56)=resultWord2;
                    __asm__ volatile(""::"i"(2));
                    resultWord2=4;
                    goto storeOriginalStateAndAnimate;
                }
            }
            break;
        case 30:
            if (Actor2006Field(ownerAddress20, unsigned char *, 0x3D) != 2) {
                Actor2006_D_8006C770 = 0;
                Actor2006Field(ownerAddress20, unsigned char *, 0x40) = 0x72;
                Actor2006Field(ownerAddress20, unsigned char *, 0x3D) = 2U;
                Actor2006Field(ownerAddress20, unsigned char *, 0x3F) = 0;
                Actor2006_func_80035734(ownerAddress20);
            }
            resultWord2=retainedDistanceOrSineAddress22<0x800;
            if(resultWord2 ? (resultWord2=14,0):(resultWord2=14,1)){
                __asm__ volatile(""::"r"(resultWord2));
                resultWord2=Actor2006Field(privateAddress19,int*,0x40);
                resultWord2=Actor2006Field(resultWord2,int*,0);
                if(resultWord2){
                    Actor2006Field(privateAddress19, short *, 0x48) = 0xB4;
                    Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0x1FU;
                }
                if (Actor2006_func_8003585C(ownerAddress20, Actor2006_func_8004E880(Actor2006Field(privateAddress19, int *, 0) - Actor2006Field(ownerAddress20, int *, 0xC), Actor2006Field(privateAddress19, int *, 4) - Actor2006Field(ownerAddress20, int *, 0x10), 0), 5, 0x14, 1, 0) != 0) {
                    resultWord2 = Actor2006Field(privateAddress19, unsigned short *, 0x44) + 0xF;
                    Actor2006Field(privateAddress19, unsigned short *, 0x44) = resultWord2;
                    if ((short) resultWord2 >= 0xF1) {
                        Actor2006Field(privateAddress19, unsigned short *, 0x44) = 0xF0U;
                    }
                    Actor2006_func_80035DDC(ownerAddress20, (short) Actor2006Field(privateAddress19, unsigned short *, 0x44), 0, 0, 5);
                    Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0x1EU;
                    if (Actor2006_func_8004F334(ownerAddress20 + 0xC, privateAddress19) < 0x200) {
                        Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0U;
                        return;
                    }
                }
            }
            else {
                goto originalProduce14;
            }
            break;
        case 3:
            retainedScalarOrVectorAddress16 = Actor2006Field(Actor2006Field(privateAddress19, int *, 0x58), int *, 0);
            Actor2006_func_8003573C(ownerAddress20, 5, 0, 0);
            resultWord2=Actor2006Field(privateAddress19,short*,0x54);
            if(!resultWord2){
                resultWord2=160;
                Actor2006Keep(resultWord2);
                Actor2006Field(retainedScalarOrVectorAddress16,unsigned char*,16)=resultWord2;
                resultWord2=149;
                Actor2006Field(retainedScalarOrVectorAddress16,unsigned char*,17)=resultWord2;
                resultWord2=62;
            }
            else{
                resultWord2=160;
                Actor2006Keep(resultWord2);
                Actor2006Field(retainedScalarOrVectorAddress16,unsigned char*,16)=resultWord2;
                resultWord2=21;
                Actor2006Field(retainedScalarOrVectorAddress16,unsigned char*,17)=resultWord2;
                resultWord2=14;
            }
            Actor2006Field(retainedScalarOrVectorAddress16,unsigned char*,18)=resultWord2;
            if (Actor2006_func_80055E84(ownerAddress20) >= 0x25) {
                Actor2006Field(privateAddress19, int *, 0x50) = (int) Actor2006Field(Actor2006Field(privateAddress19,int*,0x40),int*,0);
                if (Actor2006Field(privateAddress19, short *, 0x54) == 0) {
                    Actor2006_SpawnMoby(0x2F3, ownerAddress20);
                    Actor2006Field(privateAddress19, int *, 0x50) = 0;
                    Actor2006Field(retainedScalarOrVectorAddress16, unsigned char *, 0x10) = 0x96;
                    Actor2006Field(retainedScalarOrVectorAddress16, unsigned char *, 0x11) = 0x33;
                    Actor2006Field(retainedScalarOrVectorAddress16, unsigned char *, 0x12) = 0xA0;
                    Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0x20U;
                }
                else {
                    resultWord2=Actor2006_SpawnMoby(0x3C4,ownerAddress20);
                    argumentWord4=resultWord2;
                    Actor2006Keep(argumentWord4);
                    Actor2006Field(privateAddress19,int*,0x9C)=argumentWord4;
                    if(argumentWord4){
                        intermediateWord3=Actor2006_D_8006E160;
                        resultWord2=14;
                        if(intermediateWord3!=resultWord2){
                            Actor2006_func_80013ACC(argumentWord4,13);
                        }
                        Actor2006Field(privateAddress19, short *, 0x82) = 1;
                        Actor2006Field(privateAddress19, short *, 0x80) = 0x384;
                        Actor2006_func_80055D24(ownerAddress20, 4);
                        Actor2006_func_80055F14(ownerAddress20, 0xA, &originalFrame.spB0);
                        Actor2006_func_80055F14(ownerAddress20, 9, &originalFrame.spC0);
                        retainedScalarOrVectorAddress16 = privateAddress19 + 0x90;
                        Actor2006_func_8004F1C8(retainedScalarOrVectorAddress16, &originalFrame.spB0, &originalFrame.spC0);
                        Actor2006_func_8004F08C(retainedScalarOrVectorAddress16, Actor2006_func_8004EDE8(retainedScalarOrVectorAddress16, 1), 0xC8);
                        argumentWord5=0;
                        __asm__ volatile(""::"r"(argumentWord5):"$16");
                        retainedScalarOrVectorAddress16 = privateAddress19 + 0x84;
                        Actor2006_func_80055F14(Actor2006Field(privateAddress19, int *, 0x58), 0, retainedScalarOrVectorAddress16);
                        Actor2006_func_8004F178(Actor2006Field(privateAddress19, int *, 0x9C) + 0xC, retainedScalarOrVectorAddress16);
                    }
                }
            }
        case 32:
            resultWord2=Actor2006_D_8006C770;
            if(!resultWord2)break;
            resultWord2=Actor2006Field(privateAddress19,int*,0x40);
            resultWord2=Actor2006Field(resultWord2,int*,0);
            __asm__ volatile(""::"r"(resultWord2),"m"(Actor2006_D_8006C770));
            if(resultWord2){
            originalProduceTimer180:
                resultWord2=180;
            storeOriginalTimer180:
                Actor2006Field(privateAddress19,short*,0x48)=resultWord2;
                intermediateWord3=Actor2006Field(ownerAddress20,unsigned char*,0x3D);
                __asm__ volatile("":::"$2","memory");
                resultWord2=2;
                argumentWord4=ownerAddress20;
                if(intermediateWord3!=resultWord2){
                    resultWord2=0x72;
                    Actor2006_D_8006C770=0;
                    Actor2006Field(ownerAddress20,unsigned char*,0x40)=resultWord2;
                    resultWord2=2;
                    Actor2006Field(ownerAddress20,unsigned char*,0x3D)=resultWord2;
                    Actor2006Field(ownerAddress20,unsigned char*,0x3F)=0;
                    Actor2006_func_80035734(argumentWord4);
                }
            storeOriginalOuterState31AndReturn:
                resultWord2=31;
                Actor2006Field(ownerAddress20,unsigned char*,0x48)=resultWord2;
                return;
            }
            resultWord2=Actor2006Field(ownerAddress20,unsigned char*,0x3D);
            argumentWord4=ownerAddress20;
            if(!resultWord2)goto clearOriginalOuterStateAndReturn;
            resultWord2=0x72;
            Actor2006_D_8006C770=0;
            Actor2006Field(ownerAddress20,unsigned char*,0x40)=resultWord2;
            Actor2006Field(ownerAddress20,unsigned char*,0x3D)=0;
            __asm__ volatile(""::"m"(Actor2006_D_8006C770));
            Actor2006Field(ownerAddress20,unsigned char*,0x3F)=0;
            Actor2006_func_80035734(argumentWord4);
            __asm__ volatile(""::"m"(Actor2006_D_8006C770));
            Actor2006Field(ownerAddress20,unsigned char*,0x48)=0;
            return;
        case 31:
            resultWord2=Actor2006Field(privateAddress19,unsigned short*,0x44);
            resultWord2+=15;
            Actor2006Field(privateAddress19,short*,0x44)=resultWord2;
            resultWord2=(short)resultWord2;
            resultWord2=resultWord2<241;
            if(!resultWord2){
                resultWord2=240;
                Actor2006Field(privateAddress19,short*,0x44)=resultWord2;
            }
            resultWord2=retainedDistanceOrSineAddress22<0x800;
            if(resultWord2 ? (resultWord2=14,1):(resultWord2=14,0)){
            originalProduce14:
                resultWord2=14;
            storeOriginalOuterState14AndAnimate:
                Actor2006Field(ownerAddress20,unsigned char*,0x48)=resultWord2;
                Actor2006_func_80034F40(ownerAddress20,14);
                return;
            }
            __asm__ volatile(""::"r"(resultWord2));
            resultWord2=Actor2006Field(privateAddress19,short*,0x48);
            if(resultWord2 ? (resultWord2=retainedDistanceOrSineAddress22<0x1800,1):(resultWord2=retainedDistanceOrSineAddress22<0x1800,0))goto selectOriginalSteeringPhase;
            resultWord2=Actor2006_func_8004E880(Actor2006Field((int)&Actor2006_D_80070328,int*,0)-Actor2006Field(ownerAddress20,int*,12),Actor2006Field((int)&Actor2006_D_80070328,int*,4)-Actor2006Field(ownerAddress20,int*,16),0);
            resultWord2=Actor2006_func_8004F264(Actor2006Field(ownerAddress20,unsigned char*,0x46),resultWord2);
            resultWord2=resultWord2<8;
            if(resultWord2 ? (argumentWord4=ownerAddress20,1):(argumentWord4=ownerAddress20,0)){
            produceOriginalOuterState3:
                argumentWord5=3;
                resultWord2=3;
                Actor2006Field(privateAddress19,short*,0x54)=0;
            storeOriginalStateAndAnimate:
                Actor2006Field(argumentWord4,unsigned char*,0x48)=resultWord2;
                Actor2006_func_80034F40(argumentWord4,argumentWord5);
                return;
            }
            __asm__ volatile(""::"r"(argumentWord4):"$2");
            resultWord2=retainedDistanceOrSineAddress22<0x1800;
        selectOriginalSteeringPhase:
            Actor2006Keep(resultWord2);
            if(resultWord2)goto originalHeadingHome;
            resultWord2=retainedPrivateDistance23<0x2C01;
            if(!resultWord2){
            originalHeadingHome:
                intermediateWord3=Actor2006Field(privateAddress19,int*,0);
                argumentWord4=Actor2006Field(ownerAddress20,int*,12);
                resultWord2=Actor2006Field(privateAddress19,int*,4);
                argumentWord5=Actor2006Field(ownerAddress20,int*,16);
                argumentWord6=0;
                goto callOriginalHeadingFromLoadedWords;
            }
            resultWord2=retainedPrivateDistance23<0x1C00;
            argumentWord6=0;
            if(resultWord2){
                intermediateWord3=Actor2006Field(ownerAddress20,int*,12);
                argumentWord4=Actor2006Field((int)&Actor2006_D_80070328,int*,0);
                resultWord2=Actor2006Field(ownerAddress20,int*,16);
                argumentWord5=Actor2006Field((int)&Actor2006_D_80070328,int*,4);
            callOriginalHeadingFromLoadedWords:
                argumentWord4=intermediateWord3-argumentWord4;
                argumentWord5=resultWord2-argumentWord5;
                resultWord2=Actor2006_func_8004E880(argumentWord4,argumentWord5,argumentWord6);
            }
            else resultWord2=Actor2006Field(ownerAddress20,unsigned char*,0x46);
            Actor2006_func_8003585C(ownerAddress20,resultWord2,5,20,1,0);
            Actor2006_func_80035DDC(ownerAddress20,Actor2006Field(privateAddress19,short*,0x44),0,0,5);
            if(Actor2006Field(ownerAddress20,unsigned char*,0x3D)!=2){
                Actor2006_D_8006C770=0;
                Actor2006Field(ownerAddress20,unsigned char*,0x40)=0x72;
                Actor2006Field(ownerAddress20,unsigned char*,0x3D)=2;
                Actor2006Field(ownerAddress20,unsigned char*,0x3F)=0;
                Actor2006_func_80035734(ownerAddress20);
            }
            if(!Actor2006Field(Actor2006Field(privateAddress19,int*,0x40),int*,0))goto clearOriginalOuterStateAndReturn;
            break;
        }
        return;
    clearOriginalOuterStateAndReturn:
        Actor2006Field(ownerAddress20, unsigned char *, 0x48) = 0U;
        return;
    }
}
#undef Actor2006Field
#undef Actor2006Keep


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007EE90.
 * AI generated; not human reviewed. All849 native and linked instructions,
 * every actual transfer/data target, EXE and every overlay hash are required.
 * This body owns no selector,padding or packed data. FrameE0=224 bytes saves
 * S0..S7/FP/RA at SPB8..DC; local extent SP18..B7 retains original vector,
 * matrix,angle and helper homes. Unwritten gaps are never read. Natural FP
 * holds the geometry address, with no explicit FP/SP binding or saved input.
 * S5 holds the private record then color bytes. S6 holds world base,radius,
 * then history index. S7 holds original history offset then COS base. S2
 * holds owner then a vector address. No overlapping live fixed aliases.
 * State1/state3 and the common12-slot,two5-point-ring/topology renderer reuse
 * independently present matched842 instructions with every frame home mapped:
 * angle70..72,matrix58/88,point78..80,helperA0,topologyB0. Level47's 1BA30
 * final owner argument is retained; the level50 indexed-actor argument is
 * not substituted. State0 normalizes its original position vector via4F08C,
 * retains signed LH private+12 timer and original speed/update thresholds.
 * Initial original global6C40B byte and6C7C4 word reads remain, even though
 * their semantic purpose is unresolved. Private+0x10 timer is signed LH.
 * Every MULT has a complete initialized signed64 C product. Full high/low
 * captures narrow before original signed shifts; all /12,/5,/20 chains
 * retain sign correction. Palette40,100,140 and read/store widths remain.
 * Radius starts600 on every state3 path; its300 half-base and original
 * 600*timer/20 or600*(20-timer)/20 adjustment remain. A signed timer0 gives
 * radius300, timer10 gives600, timer20 gives300. Binary words falsify all
 * pointer/constant/branch claims; no visual inference is used.
 * Empty metadata reads full initialized words/addresses/products or clobbers
 * a dead register before its fresh producer;zero CPU words. No opcode asm,
 * partial products,undefined saved inputs or unwritten padding is used.
 * Helper views reuse existing stdutil/spu/tracer/delete contracts. Physical
 * units/fixed point,complete helper/caller/consumer chains,cadence beyond
 * invocation and synchronized retail runtime remain open. Binary identity
 * requires every gate. Engine/browser unchanged;compiler/filter/flags frozen.
 * Next evidence:human review and synchronized retail captures.
 */
/* Original assembly SHA256 dcfa99989ec3f14239c9772f379c854b73ca6544578fcdad32905605f670a2a1 */
#define Level47_7EE90Keep(v) __asm__("":"=r"(v):"0"(v))
#define Level47_7EE90MultiplyComplete(a,b) do{completeSignedProduct=(long long)(int)(a)*(long long)(int)(b);__asm__ volatile(""::"x"(completeSignedProduct));}while(0)
#define Level47_7EE90CaptureHigh(dst) do{int wholeCapturedHigh;__asm__("":"=h"(wholeCapturedHigh):"x"(completeSignedProduct));(dst)=wholeCapturedHigh;Level47_7EE90Keep(dst);}while(0)
#define Level47_7EE90CaptureLow(dst) do{int wholeCapturedLow;__asm__("":"=l"(wholeCapturedLow):"x"(completeSignedProduct));(dst)=wholeCapturedLow;Level47_7EE90Keep(dst);}while(0)
#define Level47_7EE90Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Level47_7EE90Call1830CView1(void*,void*,int,int,int) __asm__("func_8001830C");
int Level47_7EE90Call19138View1(void*,int,int,int,int,void*) __asm__("func_80019138");
void* Level47_7EE90Call1BA30View1(void*,int,int,int,int,int) __asm__("func_8001BA30");
int Level47_7EE90Call1C288View1(void*,int,int) __asm__("func_8001C288");
int Level47_7EE90Call359A4View1(void*,int) __asm__("func_800359A4");
int Level47_7EE90Call3BABCView1(void*,int,int) __asm__("func_8003BABC");
int Level47_7EE90Call40954View1(int) __asm__("func_80040954");
int Level47_7EE90Call4E880View1(int,int,int) __asm__("func_8004E880");
void Level47_7EE90Call4EA90View1(void*,void*,int) __asm__("func_8004EA90");
void Level47_7EE90Call4ED6CView1(void*,void*,void*) __asm__("func_8004ED6C");
int Level47_7EE90Call4EDE8View1(void*,int) __asm__("func_8004EDE8");
void Level47_7EE90Call4F08CView1(void*,int,int) __asm__("func_8004F08C");
void Level47_7EE90Call4F0E8View1(void*,int) __asm__("func_8004F0E8");
void Level47_7EE90Call4F178View1(void*,void*) __asm__("func_8004F178");
void Level47_7EE90Call4F194View1(void*,void*,void*) __asm__("func_8004F194");
void Level47_7EE90Call4F1C8View1(void*,void*,void*) __asm__("func_8004F1C8");
void* Level47_7EE90Call50B00View1(int,int,int,int,int) __asm__("func_80050B00");
void Level47_7EE90Call50B88View1(void*) __asm__("func_80050B88");
void Level47_7EE90Call55B18View1(void*) __asm__("func_80055B18");
void Level47_7EE90Call55D24View1(void*,int) __asm__("func_80055D24");
int Level47_7EE90DatarandView1(void) __asm__("rand");
extern unsigned char Level47_7EE90Data658A0View1[] __asm__("D_800658A0");
extern unsigned char Level47_7EE90Data65920View1[] __asm__("D_80065920");
extern int Level47_7EE90Data6C574View1 __asm__("D_8006C574");
extern int Level47_7EE90Data6C578View1 __asm__("D_8006C578");
extern int Level47_7EE90Data6C640View1 __asm__("D_8006C640");
extern int Level47_7EE90Data6C648View1 __asm__("D_8006C648");
extern int Level47_7EE90Data6C7E8View1 __asm__("D_8006C7E8");
extern unsigned char Level47_7EE90Data6D048View1[] __asm__("D_8006D048");
extern unsigned char Level47_7EE90Data6E020View1[] __asm__("D_8006E020");
extern unsigned char Level47_7EE90Data70328View1[] __asm__("D_80070328");
extern int Level47_7EE90Data71924View1 __asm__("D_80071924");
extern int Level47_7EE90Data71934View1 __asm__("D_80071934");
extern int(*Level47_7EE90DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int(*Level47_7EE90DataSpawnParticleView1)() __asm__("SpawnParticle");
extern unsigned char Level47_7EE90Data6C40BView1 __asm__("D_8006C40B");
extern int Level47_7EE90Data6C7C4View1 __asm__("D_8006C7C4");
void func_level_47_8007EE90(unsigned char* ownerParameter) {
    register int recordOrCountOrDivisionMagic16 __asm__("$16"),positionOrCreatedOrVectorOrFlags17 __asm__("$17"),ownerThenVectorAddress18 __asm__("$18"),countOrRingRecord19 __asm__("$19"),emissionCountOrGeometryAddress20 __asm__("$20"),privateThenColorRecord21 __asm__("$21"),worldBaseOrRadiusOrHistoryIndex22 __asm__("$22"),historyOffsetThenSinBase23 __asm__("$23");
    register int resultOrField2 __asm__("$2"),fieldOrCapturedHigh3 __asm__("$3"),argumentOrField4 __asm__("$4"),argumentOrField5 __asm__("$5"),argumentOrField6 __asm__("$6"),argumentOrField7 __asm__("$7"),capturedHighOrStoredAddress8 __asm__("$8");
    int retainedGeometryAddress;
    long long completeSignedProduct;
    struct {
        int sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4;
    }
    originalFrame;
    int temp_a0;
    int temp_a0_5;
    int temp_a1;
    int temp_v0;
    int temp_v0_3;
    int temp_v0_6;
    int temp_v1;
    int temp_v0_8;
    int var_a0;
    ownerThenVectorAddress18=(int)ownerParameter;
    Level47_7EE90Keep(ownerThenVectorAddress18);
    argumentOrField4=Level47_7EE90Data6C40BView1;
    privateThenColorRecord21 = Level47_7EE90Field(ownerThenVectorAddress18, int **, 0);
    fieldOrCapturedHigh3=Level47_7EE90Data6C7C4View1;
    __asm__ volatile(""::"r"(argumentOrField4),"r"(fieldOrCapturedHigh3));
    capturedHighOrStoredAddress8=Level47_7EE90Field(privateThenColorRecord21,int*,12);
    originalFrame.spA0=capturedHighOrStoredAddress8;
    temp_a1 = Level47_7EE90Field(ownerThenVectorAddress18, int *, 0xC);
    if ((temp_a1 >= 0x400) && (temp_a0 = Level47_7EE90Field(ownerThenVectorAddress18, int *, 0x10), ((temp_a0 < 0x400) == 0)) && (Level47_7EE90Field(ownerThenVectorAddress18, int *, 0x14) >= 0x400) && (temp_a1 <= 0x3C000) && (temp_a0 <= 0x3C000)) {
        Level47_7EE90Call359A4View1(privateThenColorRecord21 + 0x14, 2);
        positionOrCreatedOrVectorOrFlags17 = ownerThenVectorAddress18 + 0xC;
        if (Level47_7EE90Field(ownerThenVectorAddress18, unsigned char *, 0x49) == 0) {
            capturedHighOrStoredAddress8=originalFrame.spA0;
            Level47_7EE90Keep(capturedHighOrStoredAddress8);
            recordOrCountOrDivisionMagic16=Level47_7EE90Field(capturedHighOrStoredAddress8,int*,0);
            Level47_7EE90Field(ownerThenVectorAddress18, unsigned char *, 0x49) = 1U;
            Level47_7EE90Call4F178View1(recordOrCountOrDivisionMagic16 + 4, positionOrCreatedOrVectorOrFlags17);
            Level47_7EE90Field(recordOrCountOrDivisionMagic16, short *, 0) = 1;
            Level47_7EE90Field(recordOrCountOrDivisionMagic16, short *, 2) = 1;
            if (Level47_7EE90Call1C288View1(positionOrCreatedOrVectorOrFlags17, 0x1C2, 7) != 0) {
                temp_v0 = Level47_7EE90Call4E880View1(Level47_7EE90Field(privateThenColorRecord21, int *, 0), Level47_7EE90Field(privateThenColorRecord21, int *, 4), 0);
                Level47_7EE90Field(&Level47_7EE90Data70328View1, int *, 0x298) = temp_v0;
                if (temp_v0 <= 0) {
                    Level47_7EE90Field(&Level47_7EE90Data70328View1, int *, 0x298) = 1;
                }
                Level47_7EE90Field(ownerThenVectorAddress18, unsigned char *, 0x48) = 1U;
            }
        }
        temp_v1 = Level47_7EE90Field(ownerThenVectorAddress18, unsigned char *, 0x48);
        switch (temp_v1) {
        case 0:
            resultOrField2=Level47_7EE90Field(privateThenColorRecord21,short*,18);
            Level47_7EE90Keep(resultOrField2);
            fieldOrCapturedHigh3=resultOrField2;
            resultOrField2=resultOrField2<50;
            if(resultOrField2){
                resultOrField2=Level47_7EE90Data6C648View1;
                resultOrField2=fieldOrCapturedHigh3+resultOrField2;
                Level47_7EE90Field(privateThenColorRecord21,short*,18)=resultOrField2;
            }
            capturedHighOrStoredAddress8=originalFrame.spA0;
            resultOrField2=Level47_7EE90Field(ownerThenVectorAddress18,int*,20);
            fieldOrCapturedHigh3=Level47_7EE90Field(capturedHighOrStoredAddress8,int*,24);
            resultOrField2-=fieldOrCapturedHigh3;
            resultOrField2=resultOrField2<4096;
            recordOrCountOrDivisionMagic16=(int)&originalFrame.sp28;
            if(resultOrField2){
                Level47_7EE90Call4F1C8View1(recordOrCountOrDivisionMagic16,capturedHighOrStoredAddress8+16,ownerThenVectorAddress18+12);
                Level47_7EE90Call4F08CView1(&originalFrame.sp28, Level47_7EE90Call4EDE8View1(&originalFrame.sp28, 1), Level47_7EE90Field(privateThenColorRecord21, short *, 0x12));
                Level47_7EE90Call4F194View1(privateThenColorRecord21, privateThenColorRecord21, &originalFrame.sp28);
                Level47_7EE90Call4F08CView1(privateThenColorRecord21, Level47_7EE90Call4EDE8View1(privateThenColorRecord21, 1), 0x1B8);
                Level47_7EE90Field(ownerThenVectorAddress18, unsigned char *, 0x45) = Level47_7EE90Call4E880View1(Level47_7EE90Call4EDE8View1(privateThenColorRecord21, 0), Level47_7EE90Field(privateThenColorRecord21, int *, 8), 0);
                Level47_7EE90Field(ownerThenVectorAddress18, unsigned char *, 0x46) = Level47_7EE90Call4E880View1(Level47_7EE90Field(privateThenColorRecord21, int *, 0), Level47_7EE90Field(privateThenColorRecord21, int *, 4), 0);
            }
            argumentOrField4=(int)&originalFrame.sp18;
            __asm__ volatile(""::"r"(argumentOrField4):"$16");
            recordOrCountOrDivisionMagic16=ownerThenVectorAddress18+12;
            Level47_7EE90Call4F178View1(argumentOrField4,recordOrCountOrDivisionMagic16);
            Level47_7EE90Field(ownerThenVectorAddress18, int *, 0xC) = (int) (Level47_7EE90Field(ownerThenVectorAddress18, int *, 0xC) + Level47_7EE90Field(privateThenColorRecord21, int *, 0));
            Level47_7EE90Field(ownerThenVectorAddress18, int *, 0x10) = (int) (Level47_7EE90Field(ownerThenVectorAddress18, int *, 0x10) + Level47_7EE90Field(privateThenColorRecord21, int *, 4));
            Level47_7EE90Field(ownerThenVectorAddress18, int *, 0x14) = (int) (Level47_7EE90Field(ownerThenVectorAddress18, int *, 0x14) + Level47_7EE90Field(privateThenColorRecord21, int *, 8));
            Level47_7EE90Data71934View1 = 0;
            if (Level47_7EE90Call1830CView1(&originalFrame.sp18, recordOrCountOrDivisionMagic16, 2, 0x950000, 0) != 0) {
                Level47_7EE90Call4F178View1(recordOrCountOrDivisionMagic16, &originalFrame.sp18);
                Level47_7EE90Field(ownerThenVectorAddress18, unsigned char *, 0x48) = 1U;
            }
            if (Level47_7EE90Call1C288View1(recordOrCountOrDivisionMagic16, 0x12C, 7) != 0) {
                temp_v0_3 = Level47_7EE90Call4E880View1(Level47_7EE90Field(privateThenColorRecord21, int *, 0), Level47_7EE90Field(privateThenColorRecord21, int *, 4), 0);
                Level47_7EE90Field(&Level47_7EE90Data70328View1, int *, 0x298) = temp_v0_3;
                if (temp_v0_3 <= 0) {
                    Level47_7EE90Field(&Level47_7EE90Data70328View1, int *, 0x298) = 1;
                }
                Level47_7EE90Field(ownerThenVectorAddress18, unsigned char *, 0x48) = 1U;
            }
            Level47_7EE90Keep(ownerThenVectorAddress18);
            var_a0 = ownerThenVectorAddress18 + 0xC;
            if (Level47_7EE90Field(privateThenColorRecord21, short *, 0x14) == 0) {
                recordOrCountOrDivisionMagic16 = Level47_7EE90Call1BA30View1(var_a0, 0x190, 0, 0, 0x950000, ownerThenVectorAddress18);
                resultOrField2=recordOrCountOrDivisionMagic16;
                __asm__("":"=r"(ownerThenVectorAddress18):"0"(ownerThenVectorAddress18),"r"(resultOrField2));
                var_a0=ownerThenVectorAddress18+12;
                if (recordOrCountOrDivisionMagic16 != 0) {
                    resultOrField2 = Level47_7EE90Call4E880View1(Level47_7EE90Field(privateThenColorRecord21, int *, 0), Level47_7EE90Field(privateThenColorRecord21, int *, 4), 0);
                    Level47_7EE90Field(recordOrCountOrDivisionMagic16,unsigned char*,0x51)=resultOrField2;
                    resultOrField2&=255;
                    if(!resultOrField2){
                        resultOrField2=1;
                        Level47_7EE90Field(recordOrCountOrDivisionMagic16,unsigned char*,0x51)=resultOrField2;
                    }
                    resultOrField2=1;
                    Level47_7EE90Field(ownerThenVectorAddress18,unsigned char*,0x48)=resultOrField2;
                    __asm__("":"=r"(ownerThenVectorAddress18):"0"(ownerThenVectorAddress18),"r"(resultOrField2));
                    var_a0=ownerThenVectorAddress18+12;
                }
            }
            if (Level47_7EE90Call19138View1(var_a0, 0x12C, 2, 0, 0x950000, ownerThenVectorAddress18) != 0) {
                Level47_7EE90Field(ownerThenVectorAddress18, unsigned char *, 0x48) = 1U;
            }
            if ((Level47_7EE90Field(ownerThenVectorAddress18, unsigned char *, 0x48) == 0) && (Level47_7EE90Call359A4View1(privateThenColorRecord21 + 0x10, 2) != 0)) {
                capturedHighOrStoredAddress8=originalFrame.spA0;
                Level47_7EE90Keep(capturedHighOrStoredAddress8);
                argumentOrField4=Level47_7EE90Field(capturedHighOrStoredAddress8,int*,4);
                resultOrField2=1;
                if(argumentOrField4){
                    Level47_7EE90Call50B88View1(argumentOrField4);
                    capturedHighOrStoredAddress8=originalFrame.spA0;
                    Level47_7EE90Keep(capturedHighOrStoredAddress8);
                    resultOrField2=1;
                }
                Level47_7EE90Field(capturedHighOrStoredAddress8,int*,4)=0;
                Level47_7EE90Field(ownerThenVectorAddress18,unsigned char*,0x48)=resultOrField2;
            }
            default:goto block_77;
        case 1:
            Level47_7EE90Call3BABCView1(ownerThenVectorAddress18, 1, 0);
            if (((Level47_7EE90Data6C578View1 - Level47_7EE90Data6C574View1) >= 0x15) && (Level47_7EE90Data6C7E8View1 >= 0x7531)) {
                temp_v0_6 = Level47_7EE90DataSpawnMobyView1(0x146, ownerThenVectorAddress18);
                if (temp_v0_6 != 0) {
                    Level47_7EE90Data6C7E8View1 -= 0x5DC;
                    Level47_7EE90Field(temp_v0_6, signed char *, 0x47) = 7;
                }
            }
            emissionCountOrGeometryAddress20=0;
            if((Level47_7EE90Data6C578View1-Level47_7EE90Data6C574View1)<21)goto originalStateOneEnd;
            worldBaseOrRadiusOrHistoryIndex22=(int)&Level47_7EE90Data6E020View1;
            Level47_7EE90Keep(worldBaseOrRadiusOrHistoryIndex22);
            countOrRingRecord19=0;
        emitOriginalNextRecord:
            resultOrField2=Level47_7EE90Data6C7E8View1;
            argumentOrField4=541;
            if(resultOrField2<30001)goto originalStateOneEnd;
            positionOrCreatedOrVectorOrFlags17=Level47_7EE90DataSpawnMobyView1(argumentOrField4,ownerThenVectorAddress18);
            if(positionOrCreatedOrVectorOrFlags17){
                argumentOrField6=0;
                resultOrField2=Level47_7EE90Field(ownerThenVectorAddress18,int*,12);
                argumentOrField4=Level47_7EE90Field(worldBaseOrRadiusOrHistoryIndex22,int*,0);
                fieldOrCapturedHigh3=Level47_7EE90Field(ownerThenVectorAddress18,int*,16);
                argumentOrField5=Level47_7EE90Field(worldBaseOrRadiusOrHistoryIndex22,int*,4);
                argumentOrField4=resultOrField2-argumentOrField4;
                resultOrField2=Level47_7EE90Data6C7E8View1;
                resultOrField2-=1000;
                Level47_7EE90Data6C7E8View1=resultOrField2;
                argumentOrField5=fieldOrCapturedHigh3-argumentOrField5;
                resultOrField2=Level47_7EE90Call4E880View1(argumentOrField4,argumentOrField5,argumentOrField6);
                recordOrCountOrDivisionMagic16=resultOrField2;
                resultOrField2=Level47_7EE90DatarandView1();
                recordOrCountOrDivisionMagic16+=64;
                resultOrField2&=31;
                recordOrCountOrDivisionMagic16+=resultOrField2;
                Level47_7EE90Field(positionOrCreatedOrVectorOrFlags17,unsigned char*,0x46)=recordOrCountOrDivisionMagic16;
                resultOrField2=Level47_7EE90DatarandView1();
                resultOrField2&=30;
                resultOrField2=countOrRingRecord19+resultOrField2;
                resultOrField2-=15;
                Level47_7EE90Field(positionOrCreatedOrVectorOrFlags17,unsigned char*,0x45)=resultOrField2;
                resultOrField2=8;
                Level47_7EE90Field(positionOrCreatedOrVectorOrFlags17,unsigned char*,0x47)=resultOrField2;
                resultOrField2=42;
                Level47_7EE90Field(positionOrCreatedOrVectorOrFlags17,unsigned char*,0x4C)=resultOrField2;
            }
            emissionCountOrGeometryAddress20++;
            countOrRingRecord19+=51;
            if(emissionCountOrGeometryAddress20>=5)goto originalStateOneEnd;
            if((Level47_7EE90Data6C578View1-Level47_7EE90Data6C574View1)>=21)goto emitOriginalNextRecord;
        originalStateOneEnd:
            Level47_7EE90Call55D24View1(ownerThenVectorAddress18, 2);
            Level47_7EE90Field(ownerThenVectorAddress18, signed char *, 0x41) = 0;
            Level47_7EE90Field(ownerThenVectorAddress18, signed char *, 0x4C) = 0;
            Level47_7EE90Field(ownerThenVectorAddress18, signed char *, 0x4D) = 0;
            Level47_7EE90Field(privateThenColorRecord21, short *, 0x10) = 0x14;
            Level47_7EE90Field(ownerThenVectorAddress18, unsigned char *, 0x48) = 3U;
        case 3:
            resultOrField2=Level47_7EE90Field(privateThenColorRecord21,short*,16);
            worldBaseOrRadiusOrHistoryIndex22=600;
            if(resultOrField2>=6){
                Level47_7EE90Keep(worldBaseOrRadiusOrHistoryIndex22);
                countOrRingRecord19=0;
                emissionCountOrGeometryAddress20=(int)&originalFrame.sp58;
                positionOrCreatedOrVectorOrFlags17=(int)&originalFrame.sp38;
                recordOrCountOrDivisionMagic16=(int)&originalFrame.sp48;
                do{
                    Level47_7EE90Field(&originalFrame.sp70,unsigned char*,0)=0;
                    resultOrField2=Level47_7EE90DatarandView1();
                    Level47_7EE90Field(&originalFrame.sp70,unsigned char*,1)=resultOrField2;
                    resultOrField2=Level47_7EE90DatarandView1();
                    argumentOrField4=(int)&originalFrame.sp70;
                    __asm__("":"=r"(argumentOrField4):"0"(argumentOrField4),"r"(resultOrField2));
                    argumentOrField5=emissionCountOrGeometryAddress20;
                    argumentOrField6=0;
                    Level47_7EE90Field(&originalFrame.sp70,unsigned char*,2)=resultOrField2;
                    Level47_7EE90Call4EA90View1(argumentOrField4,argumentOrField5,argumentOrField6);
                    countOrRingRecord19++;
                    resultOrField2=Level47_7EE90DatarandView1();
                    argumentOrField4=emissionCountOrGeometryAddress20;
                    argumentOrField5=positionOrCreatedOrVectorOrFlags17;
                    argumentOrField6=positionOrCreatedOrVectorOrFlags17;
                    resultOrField2&=31;
                    resultOrField2+=48;
                    originalFrame.sp38=resultOrField2;
                    originalFrame.sp3C=0;
                    originalFrame.sp40=0;
                    Level47_7EE90Call4ED6CView1(argumentOrField4,argumentOrField5,argumentOrField6);
                    Level47_7EE90Call4F178View1(recordOrCountOrDivisionMagic16,positionOrCreatedOrVectorOrFlags17);
                    Level47_7EE90Call4F0E8View1(recordOrCountOrDivisionMagic16,2);
                    Level47_7EE90Keep(ownerThenVectorAddress18);
                    Level47_7EE90Call4F194View1(recordOrCountOrDivisionMagic16,recordOrCountOrDivisionMagic16,ownerThenVectorAddress18+12);
                    Level47_7EE90DataSpawnParticleView1(1,13,recordOrCountOrDivisionMagic16,positionOrCreatedOrVectorOrFlags17);
                    argumentOrField4=6;
                }
                while(countOrRingRecord19<4);
                Level47_7EE90Keep(ownerThenVectorAddress18);
                Level47_7EE90DataSpawnParticleView1(argumentOrField4,70,ownerThenVectorAddress18+12,16);
            }
            if (!(Level47_7EE90Data6C640View1 & 1) && ((Level47_7EE90Data6C578View1 - Level47_7EE90Data6C574View1) >= 0x15) && (Level47_7EE90Data6C7E8View1 >= 0x7531)) {
                temp_v0_8 = Level47_7EE90DataSpawnMobyView1(0x1E2, ownerThenVectorAddress18);
                if (temp_v0_8 != 0) {
                    Level47_7EE90Data6C7E8View1 -= 0x5DC;
                    Level47_7EE90Field(temp_v0_8, signed char *, 0x4C) = 0x2A;
                    Level47_7EE90Field(temp_v0_8, signed char *, 0x47) = 0xA;
                }
            }
            Level47_7EE90Keep(worldBaseOrRadiusOrHistoryIndex22);
            fieldOrCapturedHigh3=Level47_7EE90Field(privateThenColorRecord21,short*,16);
            Level47_7EE90Keep(fieldOrCapturedHigh3);
            resultOrField2=fieldOrCapturedHigh3<11;
            Level47_7EE90Keep(resultOrField2);
            completeSignedProduct=(long long)(int)worldBaseOrRadiusOrHistoryIndex22*(long long)(int)fieldOrCapturedHigh3;
            if(!resultOrField2){
                __asm__ volatile(""::"x"(completeSignedProduct));
                resultOrField2=20-fieldOrCapturedHigh3;
                Level47_7EE90MultiplyComplete(worldBaseOrRadiusOrHistoryIndex22,resultOrField2);
                Level47_7EE90CaptureLow(resultOrField2);
                fieldOrCapturedHigh3=0x66666667;
                Level47_7EE90Keep(fieldOrCapturedHigh3);
                Level47_7EE90MultiplyComplete(resultOrField2,fieldOrCapturedHigh3);
                argumentOrField4=worldBaseOrRadiusOrHistoryIndex22>>1;
                resultOrField2>>=31;
                Level47_7EE90CaptureHigh(capturedHighOrStoredAddress8);
                fieldOrCapturedHigh3=capturedHighOrStoredAddress8>>3;
                fieldOrCapturedHigh3-=resultOrField2;
                worldBaseOrRadiusOrHistoryIndex22=argumentOrField4+fieldOrCapturedHigh3;
            }
            else{
                Level47_7EE90CaptureLow(fieldOrCapturedHigh3);
                resultOrField2=0x66666667;
                Level47_7EE90Keep(resultOrField2);
                Level47_7EE90MultiplyComplete(fieldOrCapturedHigh3,resultOrField2);
                argumentOrField4=worldBaseOrRadiusOrHistoryIndex22>>1;
                fieldOrCapturedHigh3>>=31;
                Level47_7EE90CaptureHigh(capturedHighOrStoredAddress8);
                resultOrField2=capturedHighOrStoredAddress8>>3;
                resultOrField2-=fieldOrCapturedHigh3;
                worldBaseOrRadiusOrHistoryIndex22=argumentOrField4+resultOrField2;
            }
            Level47_7EE90Keep(ownerThenVectorAddress18);
            argumentOrField4=ownerThenVectorAddress18+12;
            argumentOrField5=worldBaseOrRadiusOrHistoryIndex22+500;
            argumentOrField6=7;
            resultOrField2=Level47_7EE90Call1C288View1(argumentOrField4,argumentOrField5,argumentOrField6);
            __asm__("":"=r"(ownerThenVectorAddress18):"0"(ownerThenVectorAddress18),"r"(resultOrField2));
            argumentOrField4=ownerThenVectorAddress18+12;
            if(resultOrField2){
                argumentOrField4=Level47_7EE90Field(privateThenColorRecord21,int*,0);
                argumentOrField5=Level47_7EE90Field(privateThenColorRecord21,int*,4);
                argumentOrField6=0;
                resultOrField2=Level47_7EE90Call4E880View1(argumentOrField4,argumentOrField5,argumentOrField6);
                fieldOrCapturedHigh3=(int)&Level47_7EE90Data70328View1+0x298;
                Level47_7EE90Field(fieldOrCapturedHigh3,int*,0)=resultOrField2;
                if(resultOrField2<=0){
                    resultOrField2=1;
                    Level47_7EE90Field(fieldOrCapturedHigh3,int*,0)=resultOrField2;
                }
                __asm__("":"=r"(ownerThenVectorAddress18):"0"(ownerThenVectorAddress18),"r"(resultOrField2));
                argumentOrField4=ownerThenVectorAddress18+12;
            }
            resultOrField2=Level47_7EE90Call1BA30View1(argumentOrField4,worldBaseOrRadiusOrHistoryIndex22+1000,0,0,0x950000,ownerThenVectorAddress18);
            recordOrCountOrDivisionMagic16=resultOrField2;
            argumentOrField6=0;
            if(recordOrCountOrDivisionMagic16){
                fieldOrCapturedHigh3=Level47_7EE90Field(recordOrCountOrDivisionMagic16,int*,12);
                argumentOrField4=Level47_7EE90Field(ownerThenVectorAddress18,int*,12);
                resultOrField2=Level47_7EE90Field(recordOrCountOrDivisionMagic16,int*,16);
                argumentOrField5=Level47_7EE90Field(ownerThenVectorAddress18,int*,16);
                argumentOrField4=fieldOrCapturedHigh3-argumentOrField4;
                argumentOrField5=resultOrField2-argumentOrField5;
                resultOrField2=Level47_7EE90Call4E880View1(argumentOrField4,argumentOrField5,argumentOrField6);
                Level47_7EE90Field(recordOrCountOrDivisionMagic16,unsigned char*,0x51)=resultOrField2;
                resultOrField2&=255;
                __asm__("":"=r"(ownerThenVectorAddress18):"0"(ownerThenVectorAddress18),"r"(resultOrField2));
                argumentOrField4=ownerThenVectorAddress18+12;
                if(!resultOrField2){
                    resultOrField2=1;
                    Level47_7EE90Field(recordOrCountOrDivisionMagic16,unsigned char*,0x51)=resultOrField2;
                    goto continueOriginalOwnerAddress;
                }
            }
            else{
            continueOriginalOwnerAddress:
                Level47_7EE90Keep(ownerThenVectorAddress18);
                argumentOrField4=ownerThenVectorAddress18+12;
            }
            argumentOrField5=worldBaseOrRadiusOrHistoryIndex22+700;
            argumentOrField6=2;
            argumentOrField7=0;
            __asm__ volatile(""::"r"(argumentOrField7):"$17");
            positionOrCreatedOrVectorOrFlags17=0x950000;
            Level47_7EE90Keep(positionOrCreatedOrVectorOrFlags17);
            resultOrField2=Level47_7EE90Call19138View1(argumentOrField4,argumentOrField5,argumentOrField6,argumentOrField7,positionOrCreatedOrVectorOrFlags17,ownerThenVectorAddress18);
            __asm__("":"=r"(privateThenColorRecord21):"0"(privateThenColorRecord21),"r"(resultOrField2));
            argumentOrField4=privateThenColorRecord21+16;
            if(resultOrField2){
                recordOrCountOrDivisionMagic16=(int)&Level47_7EE90Data71924View1;
                Level47_7EE90Keep(recordOrCountOrDivisionMagic16);
                argumentOrField4=Level47_7EE90Field(recordOrCountOrDivisionMagic16,int*,0);
                resultOrField2=Level47_7EE90Call40954View1(argumentOrField4);
                fieldOrCapturedHigh3=3;
                __asm__("":"=r"(privateThenColorRecord21):"0"(privateThenColorRecord21),"r"(resultOrField2));
                argumentOrField4=privateThenColorRecord21+16;
                if(resultOrField2==fieldOrCapturedHigh3){
                    resultOrField2=Level47_7EE90Field(recordOrCountOrDivisionMagic16,int*,0);
                    fieldOrCapturedHigh3=Level47_7EE90Field(&Level47_7EE90Data6D048View1,int*,20);
                    resultOrField2=(resultOrField2&63)*4;
                    resultOrField2+=fieldOrCapturedHigh3;
                    fieldOrCapturedHigh3=Level47_7EE90Field(resultOrField2,int*,0);
                    resultOrField2=Level47_7EE90Field(fieldOrCapturedHigh3,int*,4);
                    resultOrField2|=positionOrCreatedOrVectorOrFlags17;
                    Level47_7EE90Field(fieldOrCapturedHigh3,int*,4)=resultOrField2;
                }
            }
            resultOrField2=Level47_7EE90Call359A4View1(argumentOrField4,2);
            if(resultOrField2)goto block_74;
            goto block_77;
        }
    }
    else {
    block_74:
        capturedHighOrStoredAddress8=originalFrame.spA0;
        Level47_7EE90Keep(capturedHighOrStoredAddress8);
        temp_a0_5=Level47_7EE90Field(capturedHighOrStoredAddress8,int*,4);
        if (temp_a0_5 != 0) {
            Level47_7EE90Call50B88View1(temp_a0_5);
        }
        Level47_7EE90Call55B18View1(ownerThenVectorAddress18);
        return;
    }
block_77:
    capturedHighOrStoredAddress8=originalFrame.spA0;
    Level47_7EE90Keep(capturedHighOrStoredAddress8);
    countOrRingRecord19=Level47_7EE90Field(capturedHighOrStoredAddress8,int*,0);
    recordOrCountOrDivisionMagic16=0x2AAAAAAB;
    fieldOrCapturedHigh3=Level47_7EE90Field(countOrRingRecord19,short*,0);
    argumentOrField6=fieldOrCapturedHigh3+1;
    __asm__("":"=r"(fieldOrCapturedHigh3):"0"(fieldOrCapturedHigh3),"r"(argumentOrField6));
    Level47_7EE90Keep(argumentOrField6);
    Level47_7EE90MultiplyComplete(argumentOrField6,recordOrCountOrDivisionMagic16);
    argumentOrField5=ownerThenVectorAddress18+12;
    resultOrField2=fieldOrCapturedHigh3*12;
    emissionCountOrGeometryAddress20=resultOrField2+4;
    argumentOrField4=countOrRingRecord19+emissionCountOrGeometryAddress20;
    resultOrField2=argumentOrField6>>31;
    Level47_7EE90CaptureHigh(capturedHighOrStoredAddress8);
    fieldOrCapturedHigh3=capturedHighOrStoredAddress8>>1;
    worldBaseOrRadiusOrHistoryIndex22=fieldOrCapturedHigh3-resultOrField2;
    Level47_7EE90Keep(worldBaseOrRadiusOrHistoryIndex22);
    resultOrField2=worldBaseOrRadiusOrHistoryIndex22*12;
    worldBaseOrRadiusOrHistoryIndex22=argumentOrField6-resultOrField2;
    Level47_7EE90Call4F178View1(argumentOrField4,argumentOrField5);
    argumentOrField5=Level47_7EE90Field(countOrRingRecord19,short*,0);
    Level47_7EE90Keep(argumentOrField5);
    argumentOrField5++;
    Level47_7EE90MultiplyComplete(argumentOrField5,recordOrCountOrDivisionMagic16);
    retainedGeometryAddress=countOrRingRecord19+0x94;
    argumentOrField4=Level47_7EE90Field(countOrRingRecord19,unsigned short*,2);
    __asm__("":"=r"(countOrRingRecord19):"0"(countOrRingRecord19),"r"(argumentOrField4));
    privateThenColorRecord21=countOrRingRecord19+0x110;
    argumentOrField4++;
    __asm__("":"=r"(argumentOrField5):"0"(argumentOrField5),"r"(argumentOrField4));
    resultOrField2=argumentOrField5>>31;
    Level47_7EE90Field(countOrRingRecord19,short*,2)=argumentOrField4;
    argumentOrField4=(short)argumentOrField4;
    argumentOrField4=argumentOrField4<13;
    Level47_7EE90CaptureHigh(capturedHighOrStoredAddress8);
    fieldOrCapturedHigh3=capturedHighOrStoredAddress8>>1;
    fieldOrCapturedHigh3-=resultOrField2;
    resultOrField2=fieldOrCapturedHigh3*12;
    argumentOrField5-=resultOrField2;
    capturedHighOrStoredAddress8=countOrRingRecord19+0x118;
    Level47_7EE90Field(countOrRingRecord19,short*,0)=argumentOrField5;
    originalFrame.spB0=capturedHighOrStoredAddress8;
    if(!argumentOrField4){
        resultOrField2=12;
        Level47_7EE90Field(countOrRingRecord19,short*,2)=resultOrField2;
    }
    resultOrField2=Level47_7EE90Field(countOrRingRecord19,short*,2);
    argumentOrField4=(int)&originalFrame.sp70;
    if(resultOrField2<12)worldBaseOrRadiusOrHistoryIndex22=0;
    argumentOrField5=(int)&originalFrame.sp88;
    Level47_7EE90Keep(argumentOrField5);
    argumentOrField6=0;
    Level47_7EE90Keep(argumentOrField6);
    recordOrCountOrDivisionMagic16=0;
    fieldOrCapturedHigh3=Level47_7EE90Data6C640View1;
    positionOrCreatedOrVectorOrFlags17=(int)&originalFrame.sp78;
    resultOrField2=fieldOrCapturedHigh3*7;
    Level47_7EE90Field(&originalFrame.sp70,unsigned char*,0)=resultOrField2;
    resultOrField2=Level47_7EE90Field(ownerThenVectorAddress18,unsigned char*,0x45);
    historyOffsetThenSinBase23=emissionCountOrGeometryAddress20;
    Level47_7EE90Field(&originalFrame.sp70,unsigned char*,1)=resultOrField2;
    resultOrField2=Level47_7EE90Field(ownerThenVectorAddress18,unsigned char*,0x46);
    emissionCountOrGeometryAddress20=retainedGeometryAddress;
    Level47_7EE90Field(&originalFrame.sp70,unsigned char*,2)=resultOrField2;
    Level47_7EE90Call4EA90View1(argumentOrField4,argumentOrField5,argumentOrField6);
    Level47_7EE90Call55D24View1(ownerThenVectorAddress18,4);
    do{
        fieldOrCapturedHigh3=0x66666667;
        Level47_7EE90Keep(fieldOrCapturedHigh3);
        resultOrField2=recordOrCountOrDivisionMagic16<<8;
        Level47_7EE90MultiplyComplete(resultOrField2,fieldOrCapturedHigh3);
        argumentOrField4=(int)&originalFrame.sp88;
        Level47_7EE90Keep(argumentOrField4);
        argumentOrField5=positionOrCreatedOrVectorOrFlags17;
        resultOrField2>>=31;
        originalFrame.sp78=0;
        Level47_7EE90CaptureHigh(capturedHighOrStoredAddress8);
        argumentOrField7=capturedHighOrStoredAddress8>>1;
        argumentOrField7-=resultOrField2;
        Level47_7EE90Keep(argumentOrField7);
        argumentOrField7*=2;
        capturedHighOrStoredAddress8=(int)&Level47_7EE90Data65920View1;
        Level47_7EE90Keep(capturedHighOrStoredAddress8);
        resultOrField2=argumentOrField7+capturedHighOrStoredAddress8;
        Level47_7EE90Keep(resultOrField2);
        resultOrField2=Level47_7EE90Field(resultOrField2,short*,0);
        Level47_7EE90Keep(resultOrField2);
        argumentOrField6=positionOrCreatedOrVectorOrFlags17;
        fieldOrCapturedHigh3=resultOrField2*5;
        Level47_7EE90Keep(fieldOrCapturedHigh3);
        resultOrField2=fieldOrCapturedHigh3*15;
        resultOrField2>>=11;
        originalFrame.sp7C=resultOrField2;
        resultOrField2=Level47_7EE90Field(&Level47_7EE90Data658A0View1,short*,argumentOrField7);
        Level47_7EE90Keep(resultOrField2);
        recordOrCountOrDivisionMagic16++;
        fieldOrCapturedHigh3=resultOrField2*5;
        Level47_7EE90Keep(fieldOrCapturedHigh3);
        resultOrField2=fieldOrCapturedHigh3*15;
        resultOrField2>>=11;
        originalFrame.sp80=resultOrField2;
        Level47_7EE90Call4ED6CView1(argumentOrField4,argumentOrField5,argumentOrField6);
        argumentOrField4=emissionCountOrGeometryAddress20;
        argumentOrField5=countOrRingRecord19+historyOffsetThenSinBase23;
        argumentOrField6=positionOrCreatedOrVectorOrFlags17;
        Level47_7EE90Call4F194View1(argumentOrField4,argumentOrField5,argumentOrField6);
        emissionCountOrGeometryAddress20+=12;
    }
    while(recordOrCountOrDivisionMagic16<5);
    recordOrCountOrDivisionMagic16=0;
    historyOffsetThenSinBase23=(int)&Level47_7EE90Data65920View1;
    ownerThenVectorAddress18=positionOrCreatedOrVectorOrFlags17;
    resultOrField2=worldBaseOrRadiusOrHistoryIndex22*12;
    emissionCountOrGeometryAddress20=resultOrField2+4;
    positionOrCreatedOrVectorOrFlags17=60;
    do{
        fieldOrCapturedHigh3=0x66666667;
        Level47_7EE90Keep(fieldOrCapturedHigh3);
        resultOrField2=recordOrCountOrDivisionMagic16<<8;
        Level47_7EE90MultiplyComplete(resultOrField2,fieldOrCapturedHigh3);
        argumentOrField4=(int)&originalFrame.sp88;
        Level47_7EE90Keep(argumentOrField4);
        argumentOrField5=ownerThenVectorAddress18;
        resultOrField2>>=31;
        originalFrame.sp78=0;
        Level47_7EE90CaptureHigh(capturedHighOrStoredAddress8);
        argumentOrField7=capturedHighOrStoredAddress8>>1;
        argumentOrField7-=resultOrField2;
        Level47_7EE90Keep(argumentOrField7);
        argumentOrField7*=2;
        resultOrField2=argumentOrField7+historyOffsetThenSinBase23;
        Level47_7EE90Keep(resultOrField2);
        fieldOrCapturedHigh3=Level47_7EE90Field(resultOrField2,short*,0);
        Level47_7EE90Keep(fieldOrCapturedHigh3);
        argumentOrField6=ownerThenVectorAddress18;
        resultOrField2=fieldOrCapturedHigh3*3;
        resultOrField2*=8;
        resultOrField2+=fieldOrCapturedHigh3;
        resultOrField2>>=10;
        originalFrame.sp7C=resultOrField2;
        fieldOrCapturedHigh3=Level47_7EE90Field(&Level47_7EE90Data658A0View1,short*,argumentOrField7);
        Level47_7EE90Keep(fieldOrCapturedHigh3);
        recordOrCountOrDivisionMagic16++;
        resultOrField2=fieldOrCapturedHigh3*3;
        resultOrField2*=8;
        resultOrField2+=fieldOrCapturedHigh3;
        resultOrField2>>=10;
        originalFrame.sp80=resultOrField2;
        Level47_7EE90Call4ED6CView1(argumentOrField4,argumentOrField5,argumentOrField6);
        argumentOrField4=retainedGeometryAddress+positionOrCreatedOrVectorOrFlags17;
        argumentOrField5=countOrRingRecord19+emissionCountOrGeometryAddress20;
        argumentOrField6=ownerThenVectorAddress18;
        Level47_7EE90Call4F194View1(argumentOrField4,argumentOrField5,argumentOrField6);
        positionOrCreatedOrVectorOrFlags17+=12;
    }
    while(recordOrCountOrDivisionMagic16<5);
    resultOrField2=-1;
    Level47_7EE90Field(retainedGeometryAddress,int*,0x78)=resultOrField2;
    resultOrField2=40;
    Level47_7EE90Field(privateThenColorRecord21,unsigned char*,0)=resultOrField2;
    resultOrField2=100;
    Level47_7EE90Field(privateThenColorRecord21,unsigned char*,1)=resultOrField2;
    resultOrField2=140;
    Level47_7EE90Field(privateThenColorRecord21,unsigned char*,2)=resultOrField2;
    argumentOrField5=Level47_7EE90Field(countOrRingRecord19,short*,2);
    argumentOrField4=12;
    if(argumentOrField5<12){
        fieldOrCapturedHigh3=Level47_7EE90Field(privateThenColorRecord21,unsigned char*,0);
        __asm__("":"=r"(argumentOrField4):"0"(argumentOrField4),"r"(fieldOrCapturedHigh3));
        resultOrField2=argumentOrField4-argumentOrField5;
        Level47_7EE90Keep(fieldOrCapturedHigh3);
        Level47_7EE90MultiplyComplete(fieldOrCapturedHigh3,resultOrField2);
        Level47_7EE90CaptureLow(fieldOrCapturedHigh3);
        argumentOrField5=0x2AAAAAAB;
        Level47_7EE90Keep(argumentOrField5);
        Level47_7EE90MultiplyComplete(fieldOrCapturedHigh3,argumentOrField5);
        fieldOrCapturedHigh3>>=31;
        Level47_7EE90CaptureHigh(capturedHighOrStoredAddress8);
        resultOrField2=capturedHighOrStoredAddress8>>1;
        resultOrField2-=fieldOrCapturedHigh3;
        Level47_7EE90Field(privateThenColorRecord21,unsigned char*,4)=resultOrField2;
        resultOrField2=Level47_7EE90Field(countOrRingRecord19,short*,2);
        fieldOrCapturedHigh3=Level47_7EE90Field(privateThenColorRecord21,unsigned char*,1);
        resultOrField2=argumentOrField4-resultOrField2;
        Level47_7EE90Keep(fieldOrCapturedHigh3);
        Level47_7EE90MultiplyComplete(fieldOrCapturedHigh3,resultOrField2);
        Level47_7EE90CaptureLow(fieldOrCapturedHigh3);
        Level47_7EE90MultiplyComplete(fieldOrCapturedHigh3,argumentOrField5);
        fieldOrCapturedHigh3>>=31;
        Level47_7EE90CaptureHigh(capturedHighOrStoredAddress8);
        resultOrField2=capturedHighOrStoredAddress8>>1;
        resultOrField2-=fieldOrCapturedHigh3;
        Level47_7EE90Field(privateThenColorRecord21,unsigned char*,5)=resultOrField2;
        resultOrField2=Level47_7EE90Field(countOrRingRecord19,short*,2);
        fieldOrCapturedHigh3=Level47_7EE90Field(privateThenColorRecord21,unsigned char*,2);
        argumentOrField4-=resultOrField2;
        Level47_7EE90Keep(fieldOrCapturedHigh3);
        Level47_7EE90MultiplyComplete(fieldOrCapturedHigh3,argumentOrField4);
        Level47_7EE90CaptureLow(fieldOrCapturedHigh3);
        Level47_7EE90MultiplyComplete(fieldOrCapturedHigh3,argumentOrField5);
        fieldOrCapturedHigh3>>=31;
        Level47_7EE90CaptureHigh(capturedHighOrStoredAddress8);
        resultOrField2=capturedHighOrStoredAddress8>>1;
        resultOrField2-=fieldOrCapturedHigh3;
        Level47_7EE90Field(privateThenColorRecord21,unsigned char*,6)=resultOrField2;
    }
    else{
        Level47_7EE90Field(privateThenColorRecord21,unsigned char*,4)=0;
        Level47_7EE90Field(privateThenColorRecord21,unsigned char*,5)=0;
        Level47_7EE90Field(privateThenColorRecord21,unsigned char*,6)=0;
    }
    recordOrCountOrDivisionMagic16=0;
    argumentOrField6=0x66666667;
    Level47_7EE90Keep(argumentOrField6);
    argumentOrField5=1;
    do{
        fieldOrCapturedHigh3=recordOrCountOrDivisionMagic16+1;
        argumentOrField4=recordOrCountOrDivisionMagic16*8;
        Level47_7EE90MultiplyComplete(fieldOrCapturedHigh3,argumentOrField6);
        capturedHighOrStoredAddress8=originalFrame.spB0;
        resultOrField2=recordOrCountOrDivisionMagic16+5;
        argumentOrField4+=capturedHighOrStoredAddress8;
        Level47_7EE90Field(argumentOrField4,unsigned char*,0)=recordOrCountOrDivisionMagic16;
        recordOrCountOrDivisionMagic16=fieldOrCapturedHigh3;
        Level47_7EE90Field(argumentOrField4,unsigned char*,2)=resultOrField2;
        resultOrField2=recordOrCountOrDivisionMagic16>>31;
        Level47_7EE90Field(argumentOrField4,unsigned char*,4)=0;
        Level47_7EE90Field(argumentOrField4,unsigned char*,5)=0;
        Level47_7EE90Field(argumentOrField4,unsigned char*,6)=argumentOrField5;
        Level47_7EE90Field(argumentOrField4,unsigned char*,7)=argumentOrField5;
        Level47_7EE90CaptureHigh(capturedHighOrStoredAddress8);
        fieldOrCapturedHigh3=capturedHighOrStoredAddress8>>1;
        fieldOrCapturedHigh3-=resultOrField2;
        resultOrField2=fieldOrCapturedHigh3*5;
        resultOrField2=recordOrCountOrDivisionMagic16-resultOrField2;
        Level47_7EE90Field(argumentOrField4,unsigned char*,1)=resultOrField2;
        resultOrField2+=5;
        Level47_7EE90Field(argumentOrField4,unsigned char*,3)=resultOrField2;
    }
    while(recordOrCountOrDivisionMagic16<5);
    capturedHighOrStoredAddress8=originalFrame.spB0;
    resultOrField2=-1;
    Level47_7EE90Field(capturedHighOrStoredAddress8,int*,40)=resultOrField2;
    capturedHighOrStoredAddress8=originalFrame.spA0;
    Level47_7EE90Keep(capturedHighOrStoredAddress8);
    resultOrField2=Level47_7EE90Field(capturedHighOrStoredAddress8,int*,4);
    argumentOrField4=retainedGeometryAddress;
    if(!resultOrField2){
        argumentOrField5=privateThenColorRecord21;
        argumentOrField7=capturedHighOrStoredAddress8+8;
        argumentOrField6=originalFrame.spB0;
        resultOrField2=Level47_7EE90Call50B00View1(argumentOrField4,argumentOrField5,argumentOrField6,argumentOrField7,1);
        capturedHighOrStoredAddress8=originalFrame.spA0;
        Level47_7EE90Field(capturedHighOrStoredAddress8,int*,4)=resultOrField2;
    }
    return;
}
#undef Level47_7EE90Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007FBD4.
* AI generated; not human reviewed. All1037 original instructions and five
* original selector entries,1042 owned words, must match with every actual
* transfer/table destination. Frame70 saves S0..S7/FP/RA,SP18..47 locals;
* original incoming owner parameter home70 and its address consumer remain.
* Reuses accepted894/924 physical0/1/2 and raw32 byte-address view patterns.
* Independent shared setup460/state-one462/state-two661 entries remain in
* their original physical positions. Both full1A358 returns keep original
* frame stores. Signed225/shift12 samples precede the independent120 field.
* Distinct exact-address player field views retain original relocations.
* Complete10000000 C values feed original OR128/OR64 paths; no partialHI.
* The no-call branch preserves the original owner snapshot for byte73 and
* independently reloads parameter home70 for byte72. Both coordinate deltas
* retain original source/old-coordinate reads, signed shifts and stores.
* Two constructors retain full spawn pointers, vector, saved helper returns,
* independent literal4 helper argument and a complete retained4 that naturally
* allocates to FP. S0's position/base/255 phases and saved8 remain disjoint.
* Final private/index/home loads precede their original byte/field consumers.
* Empty identities consume initialized full words/addresses; output-only
* metadata and clobbers are dead before their next full C producers. No CPU
* assembly,fixedFP,undefined saved inputs,overlapping aliases or pipeline
* changes. Physical units/fixed point,complete helper/caller chains,cadence
* beyond invocation and synchronized runtime remain open. Confidence is
* binary identity after all gates. Next: human review and retail captures.
* Falsification: every native/linked word, actual destination, owned data,
* full EXE and every-overlay retail hash must remain identical.
*/
/* Original assembly SHA256 dd2eb95d821b64a89d6d1626aeb6971db98feb60c727e698f5a164bcfd661ecd */
extern int Level47_7FBD4Data70328View1 __asm__("D_80070328 + 36");
extern int Level47_7FBD4Data70328View2 __asm__("D_80070328 + 664");
extern int Level47_7FBD4Data70328View3 __asm__("D_80070328 + 540");
extern int Level47_7FBD4Data70328View4 __asm__("D_80070328 + 548");
extern int Level47_7FBD4Data70328View5 __asm__("D_80070328 + 544");
#define Level47_7FBD4Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level47_7FBD4Call1A358View1() __asm__("func_8001A358");
int Level47_7FBD4Call34F80View1() __asm__("func_80034F80");
int Level47_7FBD4Call359A4View1(void*, int) __asm__("func_800359A4");
int Level47_7FBD4Call35EE0View1() __asm__("func_80035EE0");
int Level47_7FBD4Call3636CView1() __asm__("func_8003636C");
int Level47_7FBD4Call3BABCView1() __asm__("func_8003BABC");
int Level47_7FBD4Call3BE70View1() __asm__("func_8003BE70");
int Level47_7FBD4Call3BFC0View1() __asm__("func_8003BFC0");
int Level47_7FBD4Call48210View1() __asm__("func_80048210");
int Level47_7FBD4Call4E880View1(int, int, int) __asm__("func_8004E880");
int Level47_7FBD4Call4ED6CView1() __asm__("func_8004ED6C");
int Level47_7FBD4Call4F178View1() __asm__("func_8004F178");
int Level47_7FBD4Call4F194View1() __asm__("func_8004F194");
int Level47_7FBD4Call4F334View1() __asm__("func_8004F334");
int Level47_7FBD4Call55B18View1() __asm__("func_80055B18");
int Level47_7FBD4Call55D24View1() __asm__("func_80055D24");
int Level47_7FBD4Call5629CView1() __asm__("func_8005629C");
extern int Level47_7FBD4Data658A0View1 __asm__("D_800658A0");
extern int Level47_7FBD4Data65920View1 __asm__("D_80065920");
extern int Level47_7FBD4Data6C550View1 __asm__("D_8006C550");
extern int Level47_7FBD4Data6E020View1 __asm__("D_8006E020");
extern int Level47_7FBD4Data6E024View1 __asm__("D_8006E024");
extern int Level47_7FBD4Data6E028View1 __asm__("D_8006E028");
extern int Level47_7FBD4Data6E160View1 __asm__("D_8006E160");
extern int Level47_7FBD4Data6E538View1 __asm__("D_8006E538");
extern int Level47_7FBD4Data6E53CView1 __asm__("D_8006E53C");
extern int Level47_7FBD4Data70328View6 __asm__("D_80070328");
extern void*(*Level47_7FBD4DataSpawnMobyView1)(int, void*) __asm__("SpawnMoby");
void func_level_47_8007FBD4(void *ownerParameterHome70) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), spawnedRecord17 __asm__("$17"), retainedVectorAddress19 __asm__("$19"), retainedHelperResult21 __asm__("$21"), retainedHelperResult22 __asm__("$22"), retainedFlagByte23 __asm__("$23");
    int retainedPrivateHalfwordFour;
    int ownerSnapshotBeforeCalls;
    register int privateRecord18 __asm__("$18"), retainedAddressOrByte16 __asm__("$16"), retainedHelperResult20 __asm__("$20");
    struct{
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44;
    }
    originalFrame;
    int temporaryWord11;
    int temporaryWord14;
    int temporaryWord8;
    int temporaryWord13;
    int temporaryWord15;
    int temporaryWord16;
    int temporaryWord1;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord5;
    int temporaryWord6;
    int temporaryWord7;
    int temporaryWord9;
    int temporaryWord10;
    int temporaryWord12;
    int temporaryWord17;
    argumentWord4 = Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x49);
    privateRecord18 = Level47_7FBD4Field(ownerParameterHome70, int *, 0);
    switch (argumentWord4) {
    case 0:
        argumentWord5 = 2;
        if (Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x48) == 0) {
            Level47_7FBD4Field(ownerParameterHome70, signed char *, 0x41) = 0;
            Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x4C) = 0U;
            Level47_7FBD4Field(ownerParameterHome70, signed char *, 0x4D) = 0;
            rawWord3 = ownerParameterHome70;
            Level47_7FBD4Field(rawWord3, unsigned char *, 0x4F) = 0U;
            argumentWord4 = (int)ownerParameterHome70;
            rawWord2 = 5120;
            goto callSharedOriginalStateSetup;
        }
        if (({rawWord2 = Level47_7FBD4Field(ownerParameterHome70, unsigned char*, 76);__asm__("":"=r"(rawWord2):"0"(rawWord2));argumentWord4 = 750;rawWord2 != 0;})) {
            Level47_7FBD4Field(ownerParameterHome70, unsigned char*, 72) = 0;
            rawWord2 = (int)ownerParameterHome70;
            Level47_7FBD4Field(rawWord2, unsigned char*, 68) = 0;
            rawWord2 = (int)ownerParameterHome70;
            Level47_7FBD4Field(rawWord2, unsigned char*, 69) = 0;
            rawWord3 = (int)ownerParameterHome70;
            rawWord2 = 1;
            Level47_7FBD4Field(rawWord3, unsigned char*, 73) = rawWord2;
            argumentWord5 = (int)ownerParameterHome70;
            rawWord3 = (int)Level47_7FBD4DataSpawnMobyView1;
            __asm__("":::"$2", "memory");
            rawWord2 = 10;
            Level47_7FBD4Field(privateRecord18, int*, 28) = rawWord2;
            rawWord2 = ((int(*)())rawWord3)(argumentWord4, argumentWord5);
            Level47_7FBD4Field(privateRecord18, int*, 16) = rawWord2;
            return;
        }
    default:
        return;
    case 1:
        temporaryWord13 = Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x48);
        if (temporaryWord13 == argumentWord4) goto enterOriginalSubstateOne;
        if (temporaryWord13 >= 2) goto testOriginalSubstateTwo;
        if (temporaryWord13 == 0) goto enterOriginalSubstateZero;
        return;
        testOriginalSubstateTwo:if (temporaryWord13 == 2) goto enterOriginalSubstateTwo;
        return;
        enterOriginalSubstateZero:;
        retainedAddressOrByte16 = Level47_7FBD4Field(((Level47_7FBD4Field(privateRecord18, int *, 0) * 0x58) + Level47_7FBD4Data6C550View1), int*, 0);
        temporaryWord10 = (Level47_7FBD4Field(privateRecord18, unsigned char *, 4) * 0x10) + Level47_7FBD4Field(Level47_7FBD4Field(retainedAddressOrByte16, int *, 0x24), int *, 0xC);
        Level47_7FBD4Call35EE0View1(ownerParameterHome70, Level47_7FBD4Call4E880View1(Level47_7FBD4Field(temporaryWord10, int *, 0) - Level47_7FBD4Field(ownerParameterHome70, int *, 0xC), Level47_7FBD4Field(temporaryWord10, int *, 4) - Level47_7FBD4Field(ownerParameterHome70, int *, 0x10), 0), 0x32, 0, 0, 0);
        Level47_7FBD4Call55D24View1(ownerParameterHome70, 6);
        Level47_7FBD4Call1A358View1(ownerParameterHome70 + 0xC, 0x2800);
        Level47_7FBD4Call5629CView1(ownerParameterHome70);
        if (Level47_7FBD4Call4F334View1(ownerParameterHome70 + 0xC, Level47_7FBD4Field(Level47_7FBD4Field(retainedAddressOrByte16, int *, 0x24), int *, 0xC) + (Level47_7FBD4Field(privateRecord18, unsigned char *, 4) * 0x10)) < 0x400) {
            goto writeSharedOriginalStateOne;
        }
        return;
    enterOriginalSubstateOne:
        if (({rawWord2 = Level47_7FBD4Field(privateRecord18, int*, 16);__asm__("":"=r"(rawWord2):"0"(rawWord2));argumentWord4 = 171;rawWord2 == 0;})){
            rawWord2 = (int)Level47_7FBD4DataSpawnMobyView1;
            argumentWord5 = (int)ownerParameterHome70;
            Level47_7FBD4Field(argumentWord5, int*, 24) = 0;
            temporaryWord12 = ((int(*)())rawWord2)(argumentWord4, argumentWord5);
            Level47_7FBD4Field(privateRecord18, int *, 0x28) = temporaryWord12;
            if (temporaryWord12 != 0) {
                Level47_7FBD4Field(temporaryWord12, unsigned char *, 0x4C) = (unsigned char) Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x4C);
                Level47_7FBD4Field(Level47_7FBD4Field(privateRecord18, int *, 0x28), unsigned char *, 0x4E) = (unsigned char) Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x4C);
                temporaryWord6 = Level47_7FBD4Field(privateRecord18, int *, 0x28);
                Level47_7FBD4Field(temporaryWord6, int *, 0x1C) = (int) (Level47_7FBD4Field(temporaryWord6, int *, 0x1C) | 0x80000000);
                Level47_7FBD4Call1A358View1(Level47_7FBD4Field(privateRecord18, int *, 0x28) + 0xC, 0x2800);
                Level47_7FBD4Call5629CView1(Level47_7FBD4Field(privateRecord18, int *, 0x28));
                Level47_7FBD4Field(Level47_7FBD4Field(privateRecord18, int *, 0x28), unsigned char *, 0x46) = (unsigned char) Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x46);
                Level47_7FBD4Field(ownerParameterHome70, int *, 0x14) = 0x1400;
                Level47_7FBD4Call55D24View1(ownerParameterHome70, 2);
                Level47_7FBD4Field(privateRecord18, int *, 0x20) = (int) Level47_7FBD4Field(Level47_7FBD4Field(((Level47_7FBD4Field(privateRecord18, int *, 0x18) * 0x58) + Level47_7FBD4Data6C550View1), int*, 0), int *, 0x24);
                goto writeSharedOriginalStateTwo;
            }
        }
        return;
    enterOriginalSubstateTwo:
        ownerSnapshotBeforeCalls = (int)ownerParameterHome70;
        rawWord3 = Level47_7FBD4Field(privateRecord18, int*, 0);
        rawWord2 = rawWord3*88;
        rawWord3 = Level47_7FBD4Data6C550View1;
        rawWord2 += rawWord3;
        argumentWord5 = Level47_7FBD4Field(rawWord2, int*, 0);
        __asm__("":::"$4", "memory");
        argumentWord4 = Level47_7FBD4Field(privateRecord18, int*, 40);
        __asm__("":::"$3", "memory");
        rawWord3 = Level47_7FBD4Field(argumentWord5, int*, 36);
        __asm__("":::"$2", "memory");
        rawWord2 = Level47_7FBD4Field(privateRecord18, unsigned char*, 4);
        rawWord3 = Level47_7FBD4Field(rawWord3, int*, 12);
        rawWord2 *= 16;
        rawWord2 += rawWord3;
        rawWord2 = Level47_7FBD4Field(rawWord2, int*, 0);
        __asm__("":::"$3", "memory");
        rawWord3 = Level47_7FBD4Field(argumentWord4, int*, 12);
        rawWord2 -= rawWord3;
        rawWord2 >>= 2;
        rawWord3 += rawWord2;
        Level47_7FBD4Field(argumentWord4, int*, 12) = rawWord3;
        rawWord3 = Level47_7FBD4Field(argumentWord5, int*, 36);
        __asm__("":::"$2", "memory");
        rawWord2 = Level47_7FBD4Field(privateRecord18, unsigned char*, 4);
        __asm__("":::"$4", "memory");
        argumentWord4 = Level47_7FBD4Field(privateRecord18, int*, 40);
        __asm__("":::"memory");
        rawWord3 = Level47_7FBD4Field(rawWord3, int*, 12);
        rawWord2 *= 16;
        rawWord2 += rawWord3;
        rawWord2 = Level47_7FBD4Field(rawWord2, int*, 4);
        __asm__("":::"$3", "memory");
        rawWord3 = Level47_7FBD4Field(argumentWord4, int*, 16);
        rawWord2 -= rawWord3;
        rawWord2 >>= 2;
        rawWord3 += rawWord2;
        Level47_7FBD4Field(argumentWord4, int*, 16) = rawWord3;
        temporaryWord4 = Level47_7FBD4Field(privateRecord18, int *, 0x28);
        Level47_7FBD4Field(temporaryWord4, int *, 0x14) = (int) (Level47_7FBD4Field(temporaryWord4, int *, 0x14) + Level47_7FBD4Field(privateRecord18, int *, 0xC));
        temporaryWord5 = Level47_7FBD4Field(privateRecord18, int *, 0x28);
        temporaryWord14 = Level47_7FBD4Field(privateRecord18, int *, 8);
        Level47_7FBD4Field(privateRecord18, int *, 0xC) = (int) (Level47_7FBD4Field(privateRecord18, int *, 0xC) - 0x14);
        if (Level47_7FBD4Field(temporaryWord5, int *, 0x14) < temporaryWord14) {
            Level47_7FBD4Field(temporaryWord5, int *, 0x14) = temporaryWord14;
            temporaryWord11 = (int) -Level47_7FBD4Field(privateRecord18, int *, 0xC) >> 3;
            Level47_7FBD4Field(privateRecord18, int *, 0xC) = temporaryWord11;
            if (temporaryWord11 < 0x20) {
                rawWord2 = 2;
                Level47_7FBD4Field(ownerSnapshotBeforeCalls, unsigned char*, 73) = rawWord2;
                Level47_7FBD4Field(ownerParameterHome70, unsigned char*, 72) = 0;
                return;
            }
        }
        return;
        break;
    case 2:
        if (Level47_7FBD4Field(ownerParameterHome70, int *, 0x18) & 0x140000) {
            temporaryWord15 = Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x48);
            if ((temporaryWord15 == 1) || (temporaryWord15 == 4) || (temporaryWord15 == argumentWord4)) {
                rawWord3 = (int)&Level47_7FBD4Data70328View1;
                rawWord2 = Level47_7FBD4Field(rawWord3, int*, 0);
                argumentWord4 = (int)ownerParameterHome70;
                rawWord2 |= 128;
                Level47_7FBD4Field(rawWord3, int*, 0) = rawWord2;
                Level47_7FBD4Data70328View2 = (int) (Level47_7FBD4Field(argumentWord4, unsigned char*, 70) + 0x80);
                Level47_7FBD4Data70328View3 = (int) ((int) (Level47_7FBD4Field((int)&Level47_7FBD4Data65920View1, short*, (Level47_7FBD4Field(argumentWord4, unsigned char*, 70) * 2)) * 0xE1) >> 0xC);
                rawWord3 = Level47_7FBD4Field((int)&Level47_7FBD4Data658A0View1, short*, Level47_7FBD4Field(argumentWord4, unsigned char*, 70)*2);
                __asm__("":::"$2", "memory");
                rawWord2 = 120;
                Level47_7FBD4Data70328View4 = rawWord2;
                __asm__("":"=r"(rawWord3):"0"(rawWord3), "m"(Level47_7FBD4Data70328View4));
                Level47_7FBD4Data70328View5 = (rawWord3*225) >> 12;
                Level47_7FBD4Field(privateRecord18, int *, 0x24) = -1;
                goto checkOriginalLinkedRecord;
            }
            if (temporaryWord15 != 3) {
                temporaryWord7 = Level47_7FBD4Field(privateRecord18, int *, 0x28);
                if (temporaryWord7 != 0) {
                    retainedAddressOrByte16 = Level47_7FBD4Field(temporaryWord7, int *, 0x14);
                    if (retainedAddressOrByte16 == 0x1400) {
                        Level47_7FBD4Call4F178View1(temporaryWord7 + 0xC, ownerParameterHome70 + 0xC);
                        Level47_7FBD4Field(ownerParameterHome70, int *, 0x14) = retainedAddressOrByte16;
                        Level47_7FBD4Call55D24View1(ownerParameterHome70, 6);
                    }
                    Level47_7FBD4Field(Level47_7FBD4Field(privateRecord18, int *, 0x28), unsigned char *, 0x44) = (unsigned char) Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x44);
                    Level47_7FBD4Field(Level47_7FBD4Field(privateRecord18, int *, 0x28), unsigned char *, 0x45) = (unsigned char) Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x45);
                    Level47_7FBD4Field(Level47_7FBD4Field(privateRecord18, int *, 0x28), unsigned char *, 0x46) = (unsigned char) Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x46);
                    Level47_7FBD4Field(Level47_7FBD4Field(privateRecord18, int *, 0x28), unsigned char *, 0x4F) = 0x20U;
                }
                Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x48) = 3U;
                Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x4F) = 0x20U;
                Level47_7FBD4Field(ownerParameterHome70, int *, 0x18) = 0;
                goto checkOriginalLinkedRecord;
            }
        }
        else {
        checkOriginalLinkedRecord:
            temporaryWord8 = Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x48);
            if ((temporaryWord8 != 3) && (Level47_7FBD4Field(privateRecord18, int *, 0x20) != Level47_7FBD4Field(Level47_7FBD4Field(((Level47_7FBD4Field(privateRecord18, int *, 0x18) * 0x58) + Level47_7FBD4Data6C550View1), int*, 0), int *, 0x24)) && (temporaryWord8 != 1) && (temporaryWord8 != 4) && (temporaryWord8 != 2)) {
                temporaryWord9 = Level47_7FBD4Field(privateRecord18, int *, 0x28);
                if (temporaryWord9 != 0) {
                    retainedAddressOrByte16 = Level47_7FBD4Field(temporaryWord9, int *, 0x14);
                    if (retainedAddressOrByte16 == 0x1400) {
                        Level47_7FBD4Call4F178View1(temporaryWord9 + 0xC, ownerParameterHome70 + 0xC);
                        Level47_7FBD4Field(ownerParameterHome70, int *, 0x14) = retainedAddressOrByte16;
                        Level47_7FBD4Call55D24View1(ownerParameterHome70, 6);
                    }
                    Level47_7FBD4Field(Level47_7FBD4Field(privateRecord18, int *, 0x28), unsigned char *, 0x4F) = 0x20U;
                    Level47_7FBD4Field(Level47_7FBD4Field(privateRecord18, int *, 0x28), unsigned char *, 0x46) = (unsigned char) Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x46);
                }
                Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x48) = 3U;
                Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x4F) = 0x20U;
            }
        }
        temporaryWord16 = Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x48);
        switch (temporaryWord16) {
        case 0:
            argumentWord5 = (int)&Level47_7FBD4Data70328View6+8;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            rawWord2 = Level47_7FBD4Field(argumentWord5, int*, 0);
            rawWord3 = Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int*, 68);
            argumentWord6 = Level47_7FBD4Field(privateRecord18, int*, 40);
            rawWord2 -= rawWord3;
            rawWord3 = Level47_7FBD4Field(argumentWord6, int*, 20);
            __asm__("":::"$4", "memory");
            argumentWord4 = Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int*, 592);
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            if (argumentWord4) return;
            rawWord2 -= rawWord3;
            rawWord2 -= 1;
            if ((unsigned int)rawWord2 >= 319){
                argumentWord4 = argumentWord6+12;
                return;
            }
            argumentWord4 = argumentWord6+12;
            argumentWord5 -= 8;
            rawWord2 = Level47_7FBD4Call4F334View1(argumentWord4, argumentWord5);
            if (rawWord2 >= 768) return;
            argumentWord4 = (int)ownerParameterHome70;
            argumentWord5 = Level47_7FBD4Field(privateRecord18, int*, 40);
            argumentWord4 += 12;
            argumentWord5 += 12;
            Level47_7FBD4Call4F178View1(argumentWord4, argumentWord5);
            argumentWord5 = 6;
            argumentWord4 = (int)ownerParameterHome70;
            rawWord3 = Level47_7FBD4Field(privateRecord18, int*, 40);
            __asm__("":::"$2", "memory");
            rawWord2 = 5120;
            callSharedOriginalStateSetup:Level47_7FBD4Field(rawWord3, int*, 20) = rawWord2;
            Level47_7FBD4Call55D24View1(argumentWord4, argumentWord5);
            writeSharedOriginalStateOne:rawWord3 = (int)ownerParameterHome70;
            rawWord2 = 1;
            Level47_7FBD4Field(rawWord3, unsigned char*, 72) = rawWord2;
            return;
        case 1:
            if (Level47_7FBD4Call3BFC0View1(ownerParameterHome70, Level47_7FBD4Field(privateRecord18, unsigned char *, 7)) == 0) {
                Level47_7FBD4Field(privateRecord18, unsigned char *, 7) = Level47_7FBD4Call3BABCView1(ownerParameterHome70, 0, 4);
            }
            Level47_7FBD4Field(Level47_7FBD4Field(privateRecord18, int *, 0x14), int*, 0) = ownerParameterHome70;
            if ((Level47_7FBD4Data6E53CView1 & 0x40) || (Level47_7FBD4Field(privateRecord18, int *, 0x20) != Level47_7FBD4Field(Level47_7FBD4Field(((Level47_7FBD4Field(privateRecord18, int *, 0x18) * 0x58) + Level47_7FBD4Data6C550View1), int*, 0), int *, 0x24)) || ((unsigned int) (Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int *, 0x50) - 7) < 2U) || (Level47_7FBD4Data6E160View1 != 0xD) || (Level47_7FBD4Call4F334View1(ownerParameterHome70 + 0xC, ((int)&Level47_7FBD4Data70328View6 + 0x50) - 0x50) >= 0x301) || ((Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int *, 0xB8) == 0) && (Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int *, 0x13C) != ownerParameterHome70))) {
                Level47_7FBD4Call4F178View1(Level47_7FBD4Field(privateRecord18, int *, 0x28) + 0xC, ownerParameterHome70 + 0xC);
                Level47_7FBD4Field(ownerParameterHome70, int *, 0x14) = 0x1400;
                Level47_7FBD4Call55D24View1(ownerParameterHome70, 6);
                if (Level47_7FBD4Call3BFC0View1(ownerParameterHome70, Level47_7FBD4Field(privateRecord18, unsigned char *, 7)) != 0) {
                    Level47_7FBD4Call3BE70View1(Level47_7FBD4Field(privateRecord18, unsigned char *, 7));
                }
                Level47_7FBD4Field(privateRecord18, unsigned char *, 7) = 0xFFU;
                Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x48) = 0U;
                Level47_7FBD4Field(Level47_7FBD4Field(privateRecord18, int *, 0x14), int*, 0) = 0;
                return;
            }
            rawWord3 = Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int*, 532);
            rawWord2 = 2;
            argumentWord5 = 0x10000000;
            if (rawWord3 == rawWord2){
                argumentWord5 = Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int*, 316);
                rawWord2 = (int)ownerParameterHome70;
                argumentWord4 = 0x10000000;
                if (argumentWord5 == rawWord2){
                    __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
                    argumentWord4 |= 128;
                    rawWord3 = Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int*, 524);
                    rawWord2 = 60;
                    Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int*, 572) = rawWord2;
                    Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int*, 592) = argumentWord5;
                    rawWord3 |= argumentWord4;
                    Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int*, 524) = rawWord3;
                    Level47_7FBD4Field(privateRecord18, unsigned char*, 5) = 0;
                    Level47_7FBD4Field(privateRecord18, unsigned char*, 6) = 0;
                    rawWord3 = (int)ownerParameterHome70;
                    rawWord2 = 4;
                    Level47_7FBD4Field(rawWord3, unsigned char*, 72) = rawWord2;
                    return;
                }
                argumentWord5 = 0x10000000;
            }
            prepareOriginalPlayerFields:__asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            argumentWord5 |= 64;
            rawWord2 = (int)&Level47_7FBD4Data70328View6+524;
            __asm__("":"=r"(rawWord2):"0"(rawWord2):"memory");
            rawWord3 = (int)ownerParameterHome70;
            argumentWord4 = rawWord2+32;
            Level47_7FBD4Field(rawWord2, int*, 0) = argumentWord5;
            Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int*, 536) = rawWord3;
            argumentWord5 = rawWord3+12;
            Level47_7FBD4Call4F178View1(argumentWord4, argumentWord5);
            Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int*, 568) = Level47_7FBD4Field(ownerParameterHome70, unsigned char*, 70);
            return;
        case 4:
            if (Level47_7FBD4Call3BFC0View1(ownerParameterHome70, Level47_7FBD4Field(privateRecord18, unsigned char *, 7)) == 0) {
                Level47_7FBD4Field(privateRecord18, unsigned char *, 7) = Level47_7FBD4Call3BABCView1(ownerParameterHome70, 0, 4);
            }
            if ((Level47_7FBD4Field(privateRecord18, int *, 0x20) != Level47_7FBD4Field(Level47_7FBD4Field(((Level47_7FBD4Field(privateRecord18, int *, 0x18) * 0x58) + Level47_7FBD4Data6C550View1), int*, 0), int *, 0x24)) || (Level47_7FBD4Data6E538View1 & 0x40) || (Level47_7FBD4Field(privateRecord18, int *, 0x1C) < 0)) {
                Level47_7FBD4Call4F178View1(&originalFrame.sp18, (int)&Level47_7FBD4Data70328View6);
                rawWord2 = Level47_7FBD4Call1A358View1(&originalFrame.sp18, 2048);
                argumentWord4 = (int)&originalFrame.sp18;
                __asm__("":"=r"(argumentWord4):"0"(argumentWord4), "r"(rawWord2));
                originalFrame.sp20 = rawWord2;
                Level47_7FBD4Call48210View1(argumentWord4);
                goto writeSharedOriginalStateTwo;
            }
            if ((unsigned int)(Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int*, 80)-7) < 2U){
                writeSharedOriginalStateTwo:rawWord3 = (int)ownerParameterHome70;
                rawWord2 = 2;
                Level47_7FBD4Field(rawWord3, unsigned char*, 72) = rawWord2;
                return;
            }
            if (Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int *, 0x50) == 6) {
                temporaryWord1 = Level47_7FBD4Field(privateRecord18, int *, 0x28);
                Level47_7FBD4Field(temporaryWord1, int *, 0x1C) = (int) (Level47_7FBD4Field(temporaryWord1, int *, 0x1C) & 0x7FFFFFFF);
                argumentWord4 = (int)ownerParameterHome70;
                rawWord2 = 2;
                Level47_7FBD4Field(argumentWord4, unsigned char*, 72) = rawWord2;
                rawWord2 = Level47_7FBD4Field(argumentWord4, int*, 28);
                rawWord3 = 0x80000000;
                rawWord2 |= rawWord3;
                Level47_7FBD4Field(argumentWord4, int*, 28) = rawWord2;
                return;
            }
            Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int *, 0x23C) = 0x3C;
            Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int *, 0x20C) = (int) (Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int *, 0x20C) | 0x10000080);
            Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int *, 0x250) = ownerParameterHome70;
            return;
        case 2:
            if (Level47_7FBD4Call3BFC0View1(ownerParameterHome70, Level47_7FBD4Field(privateRecord18, unsigned char *, 7)) == 0) {
                Level47_7FBD4Field(privateRecord18, unsigned char *, 7) = Level47_7FBD4Call3BABCView1(ownerParameterHome70, 0, 4);
            }
            Level47_7FBD4Call55D24View1(ownerParameterHome70, 6);
            Level47_7FBD4Call1A358View1(&ownerParameterHome70, 0x2800);
            Level47_7FBD4Call5629CView1(ownerParameterHome70);
            if (Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int *, 0x50) != 6) {
                Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int *, 0x250) = 0;
                Level47_7FBD4Field(ownerParameterHome70, int *, 0x1C) = (int) (Level47_7FBD4Field(ownerParameterHome70, int *, 0x1C) & 0x7FFFFFFF);
                Level47_7FBD4Call4F178View1(Level47_7FBD4Field(privateRecord18, int *, 0x28) + 0xC, ownerParameterHome70 + 0xC);
                temporaryWord2 = Level47_7FBD4Field(privateRecord18, int *, 0x28);
                Level47_7FBD4Field(temporaryWord2, int *, 0x1C) = (int) (Level47_7FBD4Field(temporaryWord2, int *, 0x1C) | 0x80000000);
                Level47_7FBD4Field(Level47_7FBD4Field(privateRecord18, int *, 0x28), unsigned char *, 0x46) = (unsigned char) Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x46);
                Level47_7FBD4Field(Level47_7FBD4Field(privateRecord18, int *, 0x28), unsigned char *, 0x4F) = 0x20U;
                Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x4F) = 0x20U;
                if (Level47_7FBD4Call3BFC0View1(ownerParameterHome70, Level47_7FBD4Field(privateRecord18, unsigned char *, 7)) != 0) {
                    Level47_7FBD4Call3BE70View1(Level47_7FBD4Field(privateRecord18, unsigned char *, 7));
                }
                Level47_7FBD4Field(privateRecord18, unsigned char *, 7) = 0xFFU;
                Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x48) = 3U;
                Level47_7FBD4Field(Level47_7FBD4Field(privateRecord18, int *, 0x14), int*, 0) = 0;
                Level47_7FBD4Field(privateRecord18, int *, 0x24) = -1;
                return;
            }
            if ((Level47_7FBD4Field(privateRecord18, int *, 0x20) != Level47_7FBD4Field(Level47_7FBD4Field(((Level47_7FBD4Field(privateRecord18, int *, 0x18) * 0x58) + Level47_7FBD4Data6C550View1), int*, 0), int *, 0x24)) || (Level47_7FBD4Data6E538View1 & 0x40) || (Level47_7FBD4Field(privateRecord18, int *, 0x1C) < 0)) {
                retainedAddressOrByte16 = (int)&originalFrame.sp28;
                Level47_7FBD4Call4F178View1(retainedAddressOrByte16, (int)&Level47_7FBD4Data70328View6);
                originalFrame.sp30 = Level47_7FBD4Call1A358View1(retainedAddressOrByte16, 2048);
                Level47_7FBD4Call48210View1(retainedAddressOrByte16);
            }
            if ((Level47_7FBD4Call359A4View1(privateRecord18 + 6, 1) != 0) && (Level47_7FBD4Data6E538View1 & 0x20)) {
                if (Level47_7FBD4DataSpawnMobyView1(0x2EF, ownerParameterHome70) != 0) {
                    Level47_7FBD4Call3BABCView1(ownerParameterHome70, 1, 0);
                    Level47_7FBD4Field(privateRecord18, signed char *, 6) = 0x32;
                    Level47_7FBD4Field(privateRecord18, signed char *, 5) = 1;
                }
                spawnedRecord17 = Level47_7FBD4DataSpawnMobyView1(445, ownerParameterHome70);
                __asm__("":"=r"(spawnedRecord17):"0"(spawnedRecord17));
                if (spawnedRecord17 != 0) {
                    rawWord2 = Level47_7FBD4Field(spawnedRecord17, int*, 0);
                    __asm__ volatile("":"=r"(retainedPrivateHalfwordFour)::"memory");
                    retainedPrivateHalfwordFour = 4;
                    __asm__("":"=r"(retainedPrivateHalfwordFour):"0"(retainedPrivateHalfwordFour), "r"(rawWord2));
                    Level47_7FBD4Field(rawWord2, short*, 2) = retainedPrivateHalfwordFour;
                    originalFrame.sp38 = 0x400;
                    originalFrame.sp3C = 0;
                    originalFrame.sp40 = 0;
                    Level47_7FBD4Call55D24View1(ownerParameterHome70, 4);
                    retainedVectorAddress19 = (int)&originalFrame.sp38;
                    Level47_7FBD4Call4ED6CView1(ownerParameterHome70+32, retainedVectorAddress19, retainedVectorAddress19);
                    retainedAddressOrByte16 = spawnedRecord17+12;
                    __asm__("":"=r"(retainedAddressOrByte16):"0"(retainedAddressOrByte16));
                    Level47_7FBD4Call4F194View1(retainedAddressOrByte16, ownerParameterHome70+12, retainedVectorAddress19);
                    argumentWord4 = 0;
                    argumentWord5 = 255;
                    __asm__(""::"r"(argumentWord4), "r"(argumentWord5):"$23", "memory");
                    retainedFlagByte23 = 8;
                    __asm__("":"=r"(retainedFlagByte23):"0"(retainedFlagByte23));
                    Level47_7FBD4Field(spawnedRecord17, unsigned char*, 71) = retainedFlagByte23;
                    retainedHelperResult22 = Level47_7FBD4Call3636CView1(argumentWord4, argumentWord5);
                    argumentWord4 = retainedAddressOrByte16;
                    __asm__(""::"r"(argumentWord4):"$16", "memory");
                    retainedAddressOrByte16 = (int)&Level47_7FBD4Data6E020View1;
                    __asm__("":"=r"(retainedAddressOrByte16):"0"(retainedAddressOrByte16));
                    argumentWord5 = retainedAddressOrByte16;
                    Level47_7FBD4Field(spawnedRecord17, signed char *, 0x44) = retainedHelperResult22;
                    retainedHelperResult21 = Level47_7FBD4Call4E880View1(Level47_7FBD4Call4F334View1(argumentWord4, argumentWord5), Level47_7FBD4Data6E028View1 - Level47_7FBD4Field(spawnedRecord17, int *, 0x14), 0);
                    Level47_7FBD4Field(spawnedRecord17, signed char *, 0x45) = retainedHelperResult21;
                    rawWord2 = Level47_7FBD4Call4E880View1(Level47_7FBD4Field(retainedAddressOrByte16, int*, 0)-Level47_7FBD4Field(spawnedRecord17, int*, 12), Level47_7FBD4Data6E024View1-Level47_7FBD4Field(spawnedRecord17, int*, 16), 0);
                    argumentWord4 = spawnedRecord17;
                    argumentWord5 = 2;
                    __asm__("":"=r"(rawWord2):"0"(rawWord2), "r"(argumentWord4), "r"(argumentWord5):"$20", "memory");
                    retainedHelperResult20 = rawWord2;
                    __asm__(""::"r"(retainedHelperResult20):"$16", "memory");
                    retainedAddressOrByte16 = 255;
                    __asm__("":"=r"(retainedAddressOrByte16):"0"(retainedAddressOrByte16));
                    rawWord2 = 13;
                    Level47_7FBD4Field(argumentWord4, unsigned char*, 87) = rawWord2;
                    rawWord2 = 2;
                    Level47_7FBD4Field(argumentWord4, signed char *, 0x46) = retainedHelperResult20;
                    Level47_7FBD4Field(argumentWord4, unsigned char*, 0x54) = retainedAddressOrByte16;
                    Level47_7FBD4Field(argumentWord4, signed char *, 0x55) = 0;
                    Level47_7FBD4Field(argumentWord4, signed char *, 0x56) = 0;
                    Level47_7FBD4Field(argumentWord4, int *, 8) = 0;
                    Level47_7FBD4Field(argumentWord4, unsigned char*, 74) = retainedAddressOrByte16;
                    Level47_7FBD4Field(argumentWord4, unsigned char*, 72) = rawWord2;
                    Level47_7FBD4Call34F80View1(argumentWord4, argumentWord5);
                    spawnedRecord17 = Level47_7FBD4DataSpawnMobyView1(445, ownerParameterHome70);
                    __asm__("":"=r"(spawnedRecord17):"0"(spawnedRecord17));
                    if (spawnedRecord17 != 0) {
                        argumentWord4 = spawnedRecord17+12;
                        argumentWord6 = retainedVectorAddress19;
                        argumentWord5 = (int)ownerParameterHome70;
                        __asm__(""::"r"(argumentWord6), "r"(argumentWord5):"$2", "memory");
                        rawWord2 = Level47_7FBD4Field(spawnedRecord17, int*, 0);
                        argumentWord5 += 12;
                        Level47_7FBD4Field(rawWord2, short*, 2) = retainedPrivateHalfwordFour;
                        Level47_7FBD4Call4F194View1(argumentWord4, argumentWord5, argumentWord6);
                        Level47_7FBD4Field(spawnedRecord17, signed char *, 0x56) = 0x40;
                        Level47_7FBD4Field(spawnedRecord17, signed char *, 0x57) = 0xF;
                        Level47_7FBD4Field(spawnedRecord17, unsigned char*, 71) = retainedFlagByte23;
                        Level47_7FBD4Field(spawnedRecord17, signed char *, 0x44) = retainedHelperResult22;
                        Level47_7FBD4Field(spawnedRecord17, signed char *, 0x45) = retainedHelperResult21;
                        Level47_7FBD4Field(spawnedRecord17, signed char *, 0x46) = retainedHelperResult20;
                        Level47_7FBD4Field(spawnedRecord17, unsigned char*, 0x54) = retainedAddressOrByte16;
                        Level47_7FBD4Field(spawnedRecord17, unsigned char*, 0x55) = retainedAddressOrByte16;
                        Level47_7FBD4Field(spawnedRecord17, int *, 8) = 0;
                        Level47_7FBD4Field(spawnedRecord17, unsigned char*, 74) = retainedAddressOrByte16;
                        Level47_7FBD4Field(spawnedRecord17, signed char *, 0x48) = 3;
                        Level47_7FBD4Call34F80View1(spawnedRecord17, 3);
                    }
                }
                if (Level47_7FBD4Field(privateRecord18, int *, 0x1C) == 0) {
                    Level47_7FBD4Field(privateRecord18, int *, 0x1C) = -1;
                    return;
                }
            }
            break;
        case 3:
            if (Level47_7FBD4Call3BFC0View1(ownerParameterHome70, Level47_7FBD4Field(privateRecord18, unsigned char *, 7)) != 0) {
                Level47_7FBD4Call3BE70View1(Level47_7FBD4Field(privateRecord18, unsigned char *, 7));
            }
            Level47_7FBD4Field(privateRecord18, unsigned char *, 7) = 0xFFU;
            if (Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int *, 0x250) == ownerParameterHome70) {
                Level47_7FBD4Field((int)&Level47_7FBD4Data70328View6, int *, 0x250) = 0;
            }
            Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x4F) = (unsigned char) (Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x4F) + 4);
            temporaryWord17 = Level47_7FBD4Field(privateRecord18, int *, 0x28);
            if (temporaryWord17 != 0) {
                Level47_7FBD4Field(temporaryWord17, unsigned char *, 0x4F) = (unsigned char) Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x4F);
            }
            if ((unsigned char) Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x4F) >= 0x2CU) {
                Level47_7FBD4Field(ownerParameterHome70, int *, 0x14) = 0x1400;
                Level47_7FBD4Call55D24View1(ownerParameterHome70, 6);
            }
            argumentWord4 = (int)ownerParameterHome70;
            if (Level47_7FBD4Field(argumentWord4, unsigned char*, 79) >= 128){
                rawWord3 = Level47_7FBD4Field(Level47_7FBD4Field(privateRecord18, int*, 0)*88+Level47_7FBD4Data6C550View1, int*, 0);
                __asm__("":::"$2", "memory");
                rawWord2 = 127;
                Level47_7FBD4Field(argumentWord4, unsigned char*, 79) = rawWord2;
                __asm__("":::"memory");
                rawWord2 = Level47_7FBD4Field(privateRecord18, unsigned char*, 4);
                rawWord3 = Level47_7FBD4Field(rawWord3, int*, 36);
                __asm__("":::"$4", "memory");
                argumentWord4 = (int)ownerParameterHome70;
                rawWord3 = Level47_7FBD4Field(rawWord3, int*, 12);
                __asm__("":"=r"(rawWord2):"0"(rawWord2), "r"(argumentWord4):"memory");
                rawWord2 *= 16;
                rawWord2 += rawWord3;
                Level47_7FBD4Field(rawWord2, int*, 12) = 0;
                Level47_7FBD4Field(argumentWord4, unsigned char*, 73) = 0;
                Level47_7FBD4Field(ownerParameterHome70, unsigned char *, 0x48) = 0U;
                temporaryWord3 = Level47_7FBD4Field(privateRecord18, int *, 0x28);
                if (temporaryWord3 != 0) {
                    Level47_7FBD4Call55B18View1(temporaryWord3);
                    Level47_7FBD4Field(privateRecord18, int *, 0x28) = 0;
                }
            }
            break;
        }
        break;
    }
}
#undef Level47_7FBD4Field


/* Original function-owned message and alignment; bytes copied unchanged. */
INCLUDE_RODATA("asm/nonmatchings/overlays/level_47/moby", D_level_47_80074674);

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
#define M2C_FIELD(p,t,o) (*(t)((unsigned char*)(p)+(o)))


int Source80C08_func_80013ACC() __asm__("func_80013ACC");             /* extern */
int Source80C08_func_8004EDE8() __asm__("func_8004EDE8");             /* extern */
int Source80C08_func_8004F08C() __asm__("func_8004F08C");    /* extern */
int Source80C08_func_8004F110() __asm__("func_8004F110");         /* extern */
int Source80C08_func_8004F1C8() __asm__("func_8004F1C8"); /* extern */
int Source80C08_func_8004F334() __asm__("func_8004F334");          /* extern */
int Source80C08_func_800509E8() __asm__("func_800509E8");                      /* extern */
int Source80C08_func_80055B18() __asm__("func_80055B18");                         /* extern */
int Source80C08_func_80055D24() __asm__("func_80055D24");             /* extern */
int Source80C08_func_80055F14() __asm__("func_80055F14"); /* extern */
int Source80C08_func_8005F5FC() __asm__("func_8005F5FC");                   /* extern */
extern unsigned char Source80C08_D_800658A0 __asm__("D_800658A0");
extern unsigned char Source80C08_D_80065920 __asm__("D_80065920");
extern int Source80C08_D_8006C644 __asm__("D_8006C644");
extern int Source80C08_D_8006E160 __asm__("D_8006E160");
extern char OriginalMessage74674[] __asm__("D_level_47_80074674");
extern Vector3D Source80C08_D_80070328 __asm__("D_80070328");

void func_level_47_80080C08(Moby *input_arg0) {
    struct {Vector3D sp10;char pad_1c[4];Vector3D sp20;char pad_2c[4];Vector3D sp30;char pad_3c[4];Vector3D sp40;char pad_4c[4];unsigned char *volatile sp50;char pad_54[4];} originalStack;

register Moby *arg0 __asm__("$20")=input_arg0;

    register Vector3D *call4 __asm__("$4");
    register int value3 __asm__("$3");
    register Vector3D *call6 __asm__("$6");
    register Vector3D *call5 __asm__("$5");
    register unsigned char *var_a3 __asm__("$7");
    unsigned char *sinBase30;
    register int value2 __asm__("$2");
    Moby *temp_v0;
    register Vector3D * temp_s0 __asm__("$16");
    register Vector3D * temp_s0_2 __asm__("$16");
    register Vector3D * temp_s1 __asm__("$17");
    register Vector3D *var_a1 __asm__("$5");
    register short *temp_a1_2 __asm__("$5");
    register int temp_a0_4 __asm__("$4");
    register int temp_a1 __asm__("$5");
    register int temp_a2 __asm__("$6");
    int temp_v1;
    int temp_v1_2;
    int temp_v1_3;
    register int var_s1 __asm__("$17");
    register int var_s5 __asm__("$21");
    register int var_s6 __asm__("$22");
    register int var_s7 __asm__("$23");
    int var_v0;
    int var_v0_3;
    int var_v0_5;
    unsigned char temp_a0_5;
    unsigned char temp_a0_6;
    unsigned char temp_a0_7;
    unsigned char temp_a2_2;
    unsigned char temp_a2_3;
    unsigned char temp_a2_4;
    unsigned char temp_v0_2;
    unsigned char temp_v0_3;
    unsigned char temp_v0_4;
    unsigned char var_v0_2;
    unsigned char var_v0_4;
    unsigned char var_v0_6;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a1_3;
    void *temp_a1_4;
    void *temp_a1_5;
    register void * temp_s2 __asm__("$18");
    register void * temp_s3 __asm__("$19");
    register void * var_s0 __asm__("$16");

    __asm__("" : "=r"(arg0):"0"(arg0));
    temp_s2 = arg0->mobyTag;
    temp_s0 = &arg0->position;
    temp_v0 = M2C_FIELD(temp_s2, Moby **, 0);
    temp_s3 = temp_v0->mobyTag;
    func_8004F178(temp_s0, &temp_v0->position);
    Source80C08_func_80055D24(M2C_FIELD(temp_s2, Moby **, 0), 4);
    Source80C08_func_80055F14(M2C_FIELD(temp_s2, Moby **, 0), 9, temp_s0);
    Source80C08_func_80055F14(M2C_FIELD(temp_s2, Moby **, 0), 0xA, &originalStack.sp10);
    Source80C08_func_8004F1C8(&originalStack.sp30, temp_s0, &originalStack.sp10);
    arg0->angle.yaw = func_8004E880(originalStack.sp10.x - arg0->position.x, originalStack.sp10.y - arg0->position.y, 0);
    arg0->angle.pitch = func_8004E880(Source80C08_func_8004F334(temp_s0, &originalStack.sp10), originalStack.sp10.z - arg0->position.z, 0) - 0x40;
    if (arg0->substate != 0) {
        temp_a0 = M2C_FIELD(temp_s2, void **, 4);
        if (temp_a0 != 0) {
            Source80C08_func_800509E8(temp_a0);
            M2C_FIELD(temp_s2, void **, 4) = 0;
        }
        temp_a0_2 = M2C_FIELD(temp_s2, void **, 8);
        if (temp_a0_2 != 0) {
            Source80C08_func_800509E8(temp_a0_2);
            M2C_FIELD(temp_s2, void **, 8) = 0;
        }
        temp_a0_3 = M2C_FIELD(temp_s2, void **, 0xC);
        if (temp_a0_3 != 0) {
            Source80C08_func_800509E8(temp_a0_3);
            M2C_FIELD(temp_s2, void **, 0xC) = 0;
        }
        Source80C08_func_80055D24(arg0, 4);
        return;
    }
    if (M2C_FIELD(temp_s3, short *, 0x82) != 0) {
        if (M2C_FIELD(temp_s3, int *, 0x8C) < 0x400) {
            Source80C08_func_8005F5FC(OriginalMessage74674);
            M2C_FIELD(temp_s3, short *, 0x80) = 0;
        } else {
            temp_a1 = M2C_FIELD(temp_s3, int *, 0x50);
            if (temp_a1 != 0) {
                call4=&originalStack.sp40;
                __asm__("" : "=r"(call4):"0"(call4));
                var_a1 = (Vector3D *)(temp_a1 + 0xC);
            } else {
                call4=&originalStack.sp40;
                __asm__("" : "=r"(call4):"0"(call4));
                var_a1 = &Source80C08_D_80070328;
            }
            call6=(Vector3D *)(temp_s3+0x84);
            Source80C08_func_8004F1C8(call4, var_a1, call6);
            __asm__ __volatile__("" : "=r"(temp_s3):"0"(temp_s3):"memory");
            temp_s0=&originalStack.sp40;
            __asm__("" : "=r"(temp_s0):"0"(temp_s0));
            originalStack.sp40.z += 0x400;
            Source80C08_func_8004F08C(temp_s0, Source80C08_func_8004EDE8(temp_s0, 1), 0x14);
            temp_s1 = temp_s3 + 0x90;
            func_8004F194(temp_s1, temp_s1, temp_s0);
            Source80C08_func_8004F08C(temp_s1, Source80C08_func_8004EDE8(temp_s1, 1), 0xC8);
            temp_s0_2 = temp_s3 + 0x84;
            __asm__("" : "=r"(temp_s0_2):"0"(temp_s0_2));
            func_8004F194(temp_s0_2, temp_s0_2, temp_s1);
            func_8004F178(&originalStack.sp10, temp_s0_2);
            func_8004F178(M2C_FIELD(temp_s3, int *, 0x9C) + 0xC, temp_s0_2);
        }
        value2=func_800359A4(temp_s3+0x80,2);
        __asm__("" : "=r"(value2):"0"(value2));
        if(value2 !=0) {
            /* Original word148 loads the raw comparison value in the outer
             * branch delay. Its producer also reaches block_20 on zero. */
            value2=14;__asm__("" : "=r"(value2):"0"(value2));
            if (Source80C08_D_8006E160 != value2) {
                Source80C08_func_80013ACC(M2C_FIELD(temp_s2, Moby **, 0), 0xD);
            }
            __asm__ __volatile__("" : "=r"(var_s7));
            var_s7=0;
            Source80C08_func_80055B18(M2C_FIELD(temp_s3, int *, 0x9C));
            M2C_FIELD(temp_s3, int *, 0x9C) = 0;
            M2C_FIELD(temp_s3, short *, 0x82) = 0;
        } else {
            value2=14;
            goto block_20;
        }
    } else {
        Source80C08_func_80055D24(arg0, 4);
        Source80C08_func_80055F14(arg0, 0, &originalStack.sp10);
        Source80C08_func_80055F14(arg0, 1, &originalStack.sp20);
        func_8004F194(&originalStack.sp10, &originalStack.sp10, &originalStack.sp20);
        /* Preserve this helper's raw ABI result at the shared register join;
         * the result's meaning is not inferred. The constraint emits no opcode. */
        value2=Source80C08_func_8004F110(&originalStack.sp10, 1);
block_20:
        __asm__ __volatile__("" : "=r"(var_s7):"r"(value2));
        var_s7 = 0;
    }
    var_a3 = &Source80C08_D_80065920;
    sinBase30=&Source80C08_D_800658A0;
    __asm__("" : "=r"(sinBase30):"0"(sinBase30));
    var_s0 = temp_s2;
    value2=Source80C08_D_8006C644;
    var_s6=0x5C;
    __asm__("" : "=r"(value2),"=r"(var_s6):"0"(value2),"1"(var_s6));
    value3=value2*2;var_s5=value3+value2;
    var_s1=(value2*8)+43;
    do {
        temp_a0_4 = (var_s5 & 0xFF) * 2;
        value2=temp_a0_4+(int)var_a3;
        __asm__("" : "=r"(value2):"0"(value2));
        temp_a2 = (var_s1 & 0xFF) * 2;
        value2=value2;
        __asm__("" : "=r"(value2):"0"(value2));
        value2=*(short *)value2;
        __asm__ __volatile__("" : : "r"(value2):"memory");
        temp_a1_2=(short *)(temp_a2+(int)var_a3);
        __asm__("" : "=r"(value2),"=r"(temp_a1_2):"0"(value2),"1"(temp_a1_2));
        value3=value2*5;
        value2=*temp_a1_2;
        __asm__("" : "=r"(value2):"0"(value2));
        value3=value3>>6;
        originalStack.sp20.x=(value3*value2)>>12;
        temp_a0_4+=(int)sinBase30;
        __asm__("" : "=r"(temp_a0_4):"0"(temp_a0_4));
        value3=*(short *)temp_a0_4;
        __asm__("" : "=r"(value3):"0"(value3));
        value2=value3*5;
        value3=*temp_a1_2;
        __asm__("" : "=r"(value3):"0"(value3));
        value2=value2>>6;
        temp_a2+=(int)sinBase30;
        call4=(Vector3D *)(temp_s3+var_s6);
        call5=&originalStack.sp10;
        __asm__("" : "=r"(temp_a2),"=r"(call4),"=r"(call5):"0"(temp_a2),"1"(call4),"2"(call5));
        originalStack.sp20.y=(value2*value3)>>12;
        value3=*(short *)temp_a2;
        __asm__("" : "=r"(value3):"0"(value3));
        call6=&originalStack.sp20;
        __asm__("" : "=r"(call6):"0"(call6));
        originalStack.sp50=var_a3;
        __asm__ __volatile__("" : : : "memory");
        originalStack.sp20.z=(value3*5)>>6;
        func_8004F194(call4,call5,call6);
        temp_a1_3 = M2C_FIELD(var_s0, void **, 4);
        temp_a2_2 = M2C_FIELD(temp_s2, unsigned char *, 0x10);
        temp_a0_5 = M2C_FIELD(temp_a1_3, unsigned char *, 0x68);
        var_a3 = originalStack.sp50;
        temp_v1 = temp_a0_5 - temp_a2_2;
        var_v0 = temp_v1;
        if (temp_v1 < 0) {
            __asm__("" : "=r"(var_v0):"0"(var_v0));
            var_v0 = -var_v0;
        }
        if (var_v0 < 3) {
            M2C_FIELD(temp_a1_3, unsigned char *, 0x68) = temp_a2_2;
        } else {
            var_v0_2 = temp_a0_5 - 3;
            if ((temp_v1 > 0) || (var_v0_2 = temp_a0_5 + 3, (temp_v1 < 0))) {
                M2C_FIELD(temp_a1_3, unsigned char *, 0x68) = var_v0_2;
            }
        }
        temp_a1_4 = M2C_FIELD(var_s0, void **, 4);
        temp_a2_3 = M2C_FIELD(temp_s2, unsigned char *, 0x11);
        temp_a0_6 = M2C_FIELD(temp_a1_4, unsigned char *, 0x69);
        temp_v1_2 = temp_a0_6 - temp_a2_3;
        var_v0_3 = temp_v1_2;
        if (temp_v1_2 < 0) {
            __asm__("" : "=r"(var_v0_3):"0"(var_v0_3));
            var_v0_3 = -var_v0_3;
        }
        if (var_v0_3 < 3) {
            M2C_FIELD(temp_a1_4, unsigned char *, 0x69) = temp_a2_3;
        } else {
            var_v0_4 = temp_a0_6 - 3;
            if ((temp_v1_2 > 0) || (var_v0_4 = temp_a0_6 + 3, (temp_v1_2 < 0))) {
                M2C_FIELD(temp_a1_4, unsigned char *, 0x69) = var_v0_4;
            }
        }
        temp_a1_5 = M2C_FIELD(var_s0, void **, 4);
        temp_a2_4 = M2C_FIELD(temp_s2, unsigned char *, 0x12);
        temp_a0_7 = M2C_FIELD(temp_a1_5, unsigned char *, 0x6A);
        temp_v1_3 = temp_a0_7 - temp_a2_4;
        var_v0_5 = temp_v1_3;
        if (temp_v1_3 < 0) {
            __asm__("" : "=r"(var_v0_5):"0"(var_v0_5));
            var_v0_5 = -var_v0_5;
        }
        if (var_v0_5 < 3) {
            M2C_FIELD(temp_a1_5, unsigned char *, 0x6A) = temp_a2_4;
        } else {
            var_v0_6 = temp_a0_7 - 3;
            if ((temp_v1_3 > 0) || (var_v0_6 = temp_a0_7 + 3, (temp_v1_3 < 0))) {
                M2C_FIELD(temp_a1_5, unsigned char *, 0x6A) = var_v0_6;
            }
        }
        var_s5 += 0x55;
        var_s1 += 0x55;
        var_s0 += 4;
        var_s7 += 1;
        var_s6 += 0xC;
    } while (var_s7 < 3);
    temp_v0_2 = M2C_FIELD(M2C_FIELD(temp_s2, void **, 4), unsigned char *, 0x68);
    arg0->colour.r = temp_v0_2 + (temp_v0_2 >> 1);
    temp_v0_3 = M2C_FIELD(M2C_FIELD(temp_s2, void **, 4), unsigned char *, 0x69);
    arg0->colour.g = temp_v0_3 + (temp_v0_3 >> 1);
    temp_v0_4 = M2C_FIELD(M2C_FIELD(temp_s2, void **, 4), unsigned char *, 0x6A);
    arg0->colour.a = 0;
    arg0->colour.b = temp_v0_4 + (temp_v0_4 >> 1);
}
#undef M2C_FIELD


typedef struct { Vector3D velocity; int gravity, floorZ; } DecodedAttractedMovingTag;
void DecodedAttractedFloorQuery(Vector3D*,int) __asm__("func_8001A358");
void func_8005629C(Moby*);
void func_level_47_80081120(Moby* moby) {
    DecodedAttractedMovingTag* tag = moby->mobyTag;
    Vector3D delta;
    if (moby->position.x < 0x400 || moby->position.y < 0x400 || moby->position.z < 0x400 || moby->position.x > 0x3C000 || moby->position.y > 0x3C000) goto remove;
    switch (moby->state) {
    case 0:
        moby->position.x += tag->velocity.x;
        moby->position.y += tag->velocity.y;
        moby->position.z += tag->velocity.z;
        tag->velocity.z += tag->gravity;
        func_8004F1C8(&delta, (Vector3D*)&spyro, &moby->position);
        func_8004F08C(&delta, func_8004EDE8(&delta, 1), 0x32);
        func_8004F194(&moby->position, &moby->position, &delta);
        if (moby->position.z <= tag->floorZ) {
            moby->position.z = tag->floorZ;
            moby->state = 1;
        }
        DecodedAttractedFloorQuery(&moby->position, moby->position.z - tag->floorZ + 0x400);
        func_8005629C(moby);
        break;
    case 1:
        SpawnMoby(0x2FB, moby);
    remove:
        func_80055B18(moby);
        break;
    }
}

extern int D_8006C648, D_8006C770, D_80071924;
extern int** DecodedExpandingCollisionLinks __asm__("D_8006D048 + 0x14");
extern int DecodedExpandingPlayerRadius __asm__("D_80070328 + 0x44");
extern int DecodedExpandingPlayerHeading __asm__("D_80070328 + 0x298");
Moby* DecodedExpandingMobyQuery(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int DecodedExpandingPlayerQuery(Vector3D*,int,int) __asm__("func_8001C288");
int DecodedExpandingLinkQuery(Vector3D*,int,int,int,int,Moby*) __asm__("func_80019138");
int func_80040954(int);
void func_level_47_800812AC(Moby* moby) {
    DecodedExpandingCollisionTag* tag;
    register int cadence __asm__("$3") = D_8006C648;
    register Vector3D* position __asm__("$4");
    register int radius __asm__("$5");
    register int expansion __asm__("$2");
    register int flags __asm__("$18");
    register int* linkIndex __asm__("$16");
    Moby* target;
    __asm__("" : "=r"(cadence) : "0"(cadence));
    position = &moby->position;
    __asm__("" : "=r"(position) : "0"(position), "r"(cadence));
    tag = moby->mobyTag;
    __asm__("" : "=r"(cadence) : "0"(cadence), "r"(tag));
    expansion = cadence * 15;
    radius = tag->radius;
    __asm__("" : "=r"(radius), "=r"(expansion) : "0"(radius), "1"(expansion));
    expansion *= 2;
    radius += expansion;
    tag->radius = radius;
    __asm__("" : "=r"(radius) : "0"(radius) : "memory");
    if (DecodedExpandingPlayerQuery(position, radius - DecodedExpandingPlayerRadius, 7)) {
        DecodedExpandingPlayerHeading = func_8004E880(spyro.position.x - moby->position.x, spyro.position.y - moby->position.y, 0);
        if (DecodedExpandingPlayerHeading <= 0) DecodedExpandingPlayerHeading = 1;
    }
    target = DecodedExpandingMobyQuery(&moby->position, tag->radius, 0, 0, 0x950000, tag->parent);
    if (target) {
        target->unkb = func_8004E880(target->position.x - moby->position.x, target->position.y - moby->position.y, 0);
        if (!target->unkb) target->unkb = 1;
    }
    flags = 0x950000;
    if (DecodedExpandingLinkQuery(&moby->position, tag->radius - DecodedExpandingPlayerRadius, 2, 0, flags, 0)) {
        linkIndex = &D_80071924;
        __asm__("" : "=r"(linkIndex) : "0"(linkIndex));
        if (func_80040954(*linkIndex) == 3) DecodedExpandingCollisionLinks[*linkIndex & 0x3F][1] |= flags;
    }
    if (D_8006C770) func_80055B18(moby);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original 80081468.
* AI generated; not human reviewed. Acceptance requires all 657 native and
* linked instructions, six original selectors at 80074688, every actual
* transfer/data target, EXE and every overlay hash. No selector padding.
* Original 0x50 frame is 80 bytes, saving S0..S7/RA. Its 16-byte volatile
* reservation retains SP18..27; no contents or uninitialized padding read.
* Every address/offset is a raw 32-bit byte address. Original byte, signed
* and unsigned halfword and word accesses retain widths and read cadence.
* The private record's nested pointer chain follows both original loads.
* The raw decoder moved private+0xA before call35D38; original237/238 load
* both halfwords AFTER that call. This source retains the original order.
* The signed turn delta remains in V1 while V0 holds its absolute value.
* Negating signed private+8 retains its full 32-bit result before >>1;
* -32768 therefore yields16384, with no invented signed16 truncation.
* Two dynamic remainder chains and one division retain all zero and signed
* overflow traps. The variable MULT has a complete signed64 C result,
* whose low32 capture is initialized before its signed >>7 consumer.
* Original stride88 is staged as11 followed by<<3 around its base reload.
* State0 and state5 preserve distinct physical entries and reused branch
* delay predicates. Shared final call5629C remains a single original call.
* The only nonnegative selected-angle producers also produce reverseAngle;
* the initial -1 path cannot read it, so no incoming S7 input is assumed.
* Empty metadata observes complete initialized values or clobbers a dead
* register before a fresh producer. It emits no CPU instructions. No opcode
* asm, partial products, fixed SP/FP or overlapping live aliases is used.
* Helper views reuse existing mobyutil/stdutil contracts where established;
* raw address-word views preserve original argument words. Original A1 at
* call35734 remains explicit although that matched callee is a no-op.
* Falsification: original words/targets and hashes; -32768 negation vector;
* state5 branch616 enters635 using its delay predicate and skips634.
* Confidence is binary identity after all gates. Units/fixed point, full
* helper/caller/consumer contracts, cadence beyond invocation and synced
* retail runtime remain open. Next: human review and retail captures.
* Compiler, filters and flags unchanged. Engine/browser unchanged.
*/
/* Original assembly SHA256 972eefaf92644f22a4efa8b3248d1e886340f20b2cc30e97ac3d18e3d397586d */
#define Level47_81468Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Level47_81468Call1A358View1(int,int) __asm__("func_8001A358");
void Level47_81468Call35734View1(void*,int) __asm__("func_80035734");
int Level47_81468Call3585CView1(void*,int,int,int,int,int) __asm__("func_8003585C");
int Level47_81468Call359A4View1(int,int) __asm__("func_800359A4");
int Level47_81468Call35D38View1(void*) __asm__("func_80035D38");
int Level47_81468Call35DDCView1(void*,int,int,int,int) __asm__("func_80035DDC");
int Level47_81468Call35EE0View1(void*,int,int,int,int,int) __asm__("func_80035EE0");
int Level47_81468Call3613CView1(int,int) __asm__("func_8003613C");
int Level47_81468Call3636CView1(int,int) __asm__("func_8003636C");
int Level47_81468Call363DCView1(int,int) __asm__("func_800363DC");
void Level47_81468Call369B8View1(void*,int) __asm__("func_800369B8");
int Level47_81468Call3BABCView1(void*,int,int) __asm__("func_8003BABC");
int Level47_81468Call4E880View1(int,int,int) __asm__("func_8004E880");
void Level47_81468Call4F178View1(int,int) __asm__("func_8004F178");
int Level47_81468Call4F264View1(int,int) __asm__("func_8004F264");
int Level47_81468Call4F2ECView1(int,int,int,int) __asm__("func_8004F2EC");
int Level47_81468Call4F334View1(int,int) __asm__("func_8004F334");
void Level47_81468Call55B18View1(void*) __asm__("func_80055B18");
void Level47_81468Call55D24View1(int,int) __asm__("func_80055D24");
void Level47_81468Call5629CView1(void*) __asm__("func_8005629C");
int Level47_81468DatarandView1(void) __asm__("rand");
extern int Level47_81468Data6C550View1 __asm__("D_8006C550");
extern int Level47_81468Data6C648View1 __asm__("D_8006C648");
extern int Level47_81468Data6C770View1 __asm__("D_8006C770");
extern unsigned char Level47_81468Data70328View1 __asm__("D_80070328");
extern void*(*Level47_81468DataSpawnMobyView1)(int,void*) __asm__("SpawnMoby");
void func_level_47_80081468(void *ownerParameter) {
    register int rawWord2 __asm__("$2");
    register int rawWord3 __asm__("$3");
    register int rawWord4 __asm__("$4");
    register int rawWord5 __asm__("$5");
    register int rawWord6 __asm__("$6");
    register int rawWord7 __asm__("$7");
    register int rawWord8 __asm__("$8");
    long long completeSignedProduct;
    int completeProductLow;
    volatile struct{
        unsigned char reserved[16];
    }
    originalFrameReserve;
    register void* ownerRecord17 __asm__("$17");
    register int retainedAnglePositionOrDistance16 __asm__("$16");
    register int privateRecord18 __asm__("$18");
    register int retainedIndirectRecord19 __asm__("$19");
    register int previousIndexOrDataBase20 __asm__("$20");
    register int selectedAngle21 __asm__("$21");
    register int nextIndex22 __asm__("$22");
    register int reverseAngle23 __asm__("$23");
    int firstCandidateAngle;
    int secondCandidateAngle;
    int firstCandidateDelta;
    ownerRecord17=ownerParameter;
    __asm__(""::"r"(ownerRecord17));
    privateRecord18 = Level47_81468Field(ownerRecord17, void **, 0);
    retainedIndirectRecord19 = Level47_81468Field(Level47_81468Field(privateRecord18,void**,0),void**,0);
    if ((unsigned char) Level47_81468Field(ownerRecord17, unsigned char *, 0x48) >= 3U) {
        if (Level47_81468Field(ownerRecord17, int *, 0x18) != 0) {
            Level47_81468Call3BABCView1(ownerRecord17,0,0);
            Level47_81468DataSpawnMobyView1(0x10, ownerRecord17);
            Level47_81468Call55D24View1(ownerRecord17, 4);
            Level47_81468Call369B8View1(ownerRecord17, 0x20);
            Level47_81468Field(retainedIndirectRecord19, unsigned char *, 0x63) = (unsigned char) (Level47_81468Field(retainedIndirectRecord19, unsigned char *, 0x63) - 1);
            Level47_81468Call55B18View1(ownerRecord17);
            return;
        }
    }
    rawWord3 = Level47_81468Field(ownerRecord17, unsigned char *, 0x48);
    switch (rawWord3) {
    case 0:
        rawWord2 = Level47_81468Field(retainedIndirectRecord19, void **, 0x1C);
        rawWord4 = Level47_81468Call4F334View1(ownerRecord17 + 0xC, Level47_81468Field(rawWord2, int *, 0xC) + (Level47_81468Field(rawWord2, short *, 2) * 0x10));
        if(!((Level47_81468Field(privateRecord18,short*,0x12)<0x79)||(rawWord4>=0x1800)))goto originalDormant;
        rawWord2=rawWord4<0x1400;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        if(rawWord2){
            rawWord2=rawWord4<0xc01;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            rawWord2=Level47_81468Field(ownerRecord17,int*,0x18);
            if(rawWord2)goto originalDormant;
            rawWord2=Level47_81468Field(privateRecord18,int*,4);
            rawWord2=Level47_81468Field(rawWord2,int*,0x18);
            __asm__("":"=r"(rawWord4):"0"(rawWord4));
            if(rawWord2){
                rawWord2=rawWord4<0xc01;
                goto originalDormant;
            }
            rawWord2=rawWord4<0xc01;
        }
        else{
            rawWord2=rawWord4<0xc01;
        }
    originalNearRangeTest:
        if(rawWord2==0){
            rawWord3 = Level47_81468Field(retainedIndirectRecord19, void **, 0x1C);
            rawWord2 = (Level47_81468Field(rawWord3, short *, 2) * 0x10) + Level47_81468Field(rawWord3, int *, 0xC);
            retainedAnglePositionOrDistance16 = Level47_81468Call4E880View1(Level47_81468Field(rawWord2, int *, 0) - Level47_81468Field(ownerRecord17, int *, 0xC), Level47_81468Field(rawWord2, int *, 4) - Level47_81468Field(ownerRecord17, int *, 0x10), 0);
            if (Level47_81468Field(privateRecord18, short *, 0x12) >= 0x79) {
                retainedAnglePositionOrDistance16 += 0x40;
                Level47_81468Call359A4View1(privateRecord18 + 0x12, 2);
                rawWord7 = 0;
            }
            else {
                rawWord7 = 0x400;
            }
            rawWord2 = Level47_81468Field(privateRecord18, void **, 4);
            Level47_81468Field(rawWord2, int *, 0x14) = (int) (Level47_81468Field(rawWord2, int *, 0x14) + 0x1000);
            if ((Level47_81468Call35EE0View1(ownerRecord17, retainedAnglePositionOrDistance16, 0x32, rawWord7, rawWord7, 0x22) != 0) && (rawWord2=Level47_81468Field(privateRecord18,short*,0x12),rawWord3=rawWord2,({rawWord2=rawWord2<120;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord2;}))) {
                rawWord2=Level47_81468Data6C648View1;
                rawWord2=rawWord3+rawWord2;
                Level47_81468Field(privateRecord18,short*,0x12)=rawWord2;
                rawWord2=(short)rawWord2;
                retainedAnglePositionOrDistance16 = ownerRecord17 + 0xC;
                if (rawWord2 >= 0x78) {
                    Level47_81468Field(privateRecord18, short *, 0x12) = 0xB4;
                    goto copyOriginalPosition;
                }
            }
            else {
            copyOriginalPosition:
                retainedAnglePositionOrDistance16 = ownerRecord17 + 0xC;
            }
            Level47_81468Call4F178View1(Level47_81468Field(privateRecord18, void **, 4) + 0xC, retainedAnglePositionOrDistance16);
            Level47_81468Call55D24View1(Level47_81468Field(privateRecord18, void **, 4), 3);
            Level47_81468Call55D24View1(ownerRecord17, 3);
            Level47_81468Call1A358View1(retainedAnglePositionOrDistance16, 0x2800);
            goto originalFinalUpdate;
        default:
            return;
        }
    originalDormant:
        Level47_81468Field(ownerRecord17, int *, 0x18) = 0;
        Level47_81468Field(Level47_81468Field(privateRecord18, void **, 4), int *, 0x18) = 0;
        Level47_81468Field(ownerRecord17, unsigned char *, 0x48) = 1U;
        Level47_81468Field(ownerRecord17, signed char *, 0x49) = 1;
        return;
    case 1:
        if ((Level47_81468Field(ownerRecord17, int *, 0x18) != 0) || (Level47_81468Field(Level47_81468Field(privateRecord18, void **, 4), int *, 0x18) != 0)) {
            Level47_81468Call55B18View1(Level47_81468Field(privateRecord18, void **, 4));
            rawWord4 = 0;
            rawWord3 = retainedIndirectRecord19;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            Level47_81468Field(privateRecord18, void **, 4) = 0;
            do {
                if (Level47_81468Field(rawWord3, int *, 0x64) == ownerRecord17) {
                    Level47_81468Field(rawWord3, int *, 0x64) = 0;
                }
                rawWord4 += 1;
                rawWord3 += 4;
            }
            while (rawWord4 < 3);
            Level47_81468Field(retainedIndirectRecord19, unsigned char *, 0x63) = (unsigned char) (Level47_81468Field(retainedIndirectRecord19, unsigned char *, 0x63) + 1);
            Level47_81468Field(privateRecord18, short *, 0xA) = -1;
            Level47_81468Field(privateRecord18, short *, 0xC) = 0x96;
            Level47_81468Field(privateRecord18, unsigned short *, 8) = 0U;
            Level47_81468Field(privateRecord18, short *, 0x12) = 0;
            Level47_81468Field(ownerRecord17, int *, 0x18) = 0;
            Level47_81468Field(ownerRecord17, unsigned char *, 0x48) = 2U;
            return;
        }
        break;
    case 2:
    case 4:
        Level47_81468Field(ownerRecord17, unsigned char *, 0x46) = (unsigned char) (Level47_81468Field(ownerRecord17, unsigned char *, 0x46) + 4);
        if (Level47_81468Field(ownerRecord17, unsigned char *, 0x48) == 4) {
            Level47_81468Field(ownerRecord17, unsigned char *, 0x44) = Level47_81468Call4F2ECView1(Level47_81468Field(ownerRecord17, unsigned char *, 0x44), 0, 0x10, 0x10);
            Level47_81468Field(ownerRecord17, unsigned char *, 0x45) = Level47_81468Call4F2ECView1(Level47_81468Field(ownerRecord17, unsigned char *, 0x45), 0, 0x10, 0x10);
        }
        else {
            Level47_81468Field(ownerRecord17, unsigned char *, 0x44) = (unsigned char) (Level47_81468Field(ownerRecord17, unsigned char *, 0x44) + 5);
            Level47_81468Field(ownerRecord17, unsigned char *, 0x45) = (unsigned char) (Level47_81468Field(ownerRecord17, unsigned char *, 0x45) + 6);
        }
        rawWord2 = Level47_81468Field(privateRecord18, unsigned short *, 8) - 0xF;
        Level47_81468Field(privateRecord18, unsigned short *, 8) = rawWord2;
        Level47_81468Field(ownerRecord17, int *, 0x14) = (int) (Level47_81468Field(ownerRecord17, int *, 0x14) + (short) rawWord2);
        rawWord2=Level47_81468Call35D38View1(ownerRecord17);
        rawWord3=Level47_81468Field(ownerRecord17,short*,0x38);
        rawWord5=Level47_81468Field(privateRecord18,short*,0xA);
        retainedAnglePositionOrDistance16=rawWord2+rawWord3;
        if (rawWord5 >= 0) {
            Level47_81468Call35EE0View1(ownerRecord17, rawWord5, Level47_81468Field(privateRecord18, short *, 0xC), 0x140, 0x140, 0x22);
        }
        if (retainedAnglePositionOrDistance16 >= Level47_81468Field(ownerRecord17, int *, 0x14)) {
            Level47_81468Field(ownerRecord17, int *, 0x14) = retainedAnglePositionOrDistance16;
            Level47_81468Field(privateRecord18, unsigned short *, 8) = (-(int)Level47_81468Field(privateRecord18,short*,8)>>1);
            Level47_81468Field(privateRecord18, short *, 0xC) = (short) ((int) ((unsigned short) Level47_81468Field(privateRecord18, short *, 0xC) << 0x10) >> 0x11);
            rawWord2=Level47_81468DatarandView1()&255;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            Level47_81468Field(privateRecord18,short*,10)=rawWord2;
            rawWord3=Level47_81468Field(ownerRecord17,unsigned char*,0x48);
            __asm__ volatile("":::"$2","memory");
            rawWord2=4;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            if(rawWord3==rawWord2){
                rawWord2=3;
                Level47_81468Field(ownerRecord17, unsigned char *, 0x44) = 0U;
                Level47_81468Field(ownerRecord17, unsigned char *, 0x45) = 0U;
                goto storeOriginalStateByte;
            }
            rawWord2=Level47_81468Field(privateRecord18,short*,8);
            rawWord2=rawWord2<48;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            if(rawWord2){
                rawWord2=4;
            storeOriginalStateByte:
                Level47_81468Field(ownerRecord17, unsigned char *, 0x48) = rawWord2;
            }
        }
        Level47_81468Call55D24View1(ownerRecord17, 2);
        Level47_81468Call35D38View1(ownerRecord17);
        goto originalFinalUpdate;
    case 3:
        selectedAngle21 = -1;
        retainedAnglePositionOrDistance16 = ownerRecord17 + 0xC;
        if (Level47_81468Call4F334View1(retainedAnglePositionOrDistance16, &Level47_81468Data70328View1) < 0x1C00) {
            selectedAngle21 = Level47_81468Call4E880View1(Level47_81468Field(&Level47_81468Data70328View1, int *, 0) - Level47_81468Field(ownerRecord17, int *, 0xC), Level47_81468Field(&Level47_81468Data70328View1, int *, 4) - Level47_81468Field(ownerRecord17, int *, 0x10), 0);
            rawWord6=0;
            __asm__("":"=r"(rawWord6):"0"(rawWord6));
            rawWord4 = Level47_81468Field(ownerRecord17, int *, 0xC) - Level47_81468Field(&Level47_81468Data70328View1, int *, 0);
            rawWord5 = Level47_81468Field(ownerRecord17, int *, 0x10) - Level47_81468Field(&Level47_81468Data70328View1, int *, 4);
            goto computeOriginalReverseAngle;
        }
        if (Level47_81468Call4F334View1(retainedAnglePositionOrDistance16, Level47_81468Data6C550View1 + (Level47_81468Field(retainedIndirectRecord19, int *, 0x74) * 0x58) + 0xC) < 0x1400) {
            rawWord6=0;
            __asm__("":"=r"(rawWord6):"0"(rawWord6));
            rawWord2 = (Level47_81468Field(retainedIndirectRecord19, int *, 0x74) * 0x58) + Level47_81468Data6C550View1;
            selectedAngle21 = Level47_81468Call4E880View1(Level47_81468Field(rawWord2, int *, 0xC) - Level47_81468Field(ownerRecord17, int *, 0xC), Level47_81468Field(rawWord2, int *, 0x10) - Level47_81468Field(ownerRecord17, int *, 0x10), 0);
            rawWord6=0;
            __asm__("":"=r"(rawWord6):"0"(rawWord6));
            rawWord3=Level47_81468Field(retainedIndirectRecord19,int*,0x74);
            rawWord7=Level47_81468Field(ownerRecord17,int*,12);
            rawWord2=rawWord3*11;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            rawWord3=Level47_81468Data6C550View1;
            rawWord2=rawWord2<<3;
            rawWord2=rawWord2+rawWord3;
            rawWord4=Level47_81468Field(rawWord2,int*,12);
            rawWord3=Level47_81468Field(ownerRecord17,int*,16);
            rawWord5=Level47_81468Field(rawWord2,int*,16);
            rawWord4=rawWord7-rawWord4;
            rawWord5=rawWord3-rawWord5;
        computeOriginalReverseAngle:
            reverseAngle23 = Level47_81468Call4E880View1(rawWord4, rawWord5, rawWord6);
        }
        if (selectedAngle21 >= 0) {
            rawWord6=0;
            __asm__ volatile(""::"r"(rawWord6):"memory");
            rawWord5 = Level47_81468Field(retainedIndirectRecord19, void **, 0x70);
            rawWord4 = Level47_81468Field(privateRecord18, unsigned char *, 0xE);
            rawWord3 = Level47_81468Field(rawWord5, short *, 0);
            nextIndex22 = (int) (rawWord4 + 1) % rawWord3;
            rawWord2=rawWord3-1;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            rawWord4=rawWord4+rawWord2;
            previousIndexOrDataBase20=rawWord4%rawWord3;
            rawWord2 = (nextIndex22 * 0x10) + Level47_81468Field(rawWord5, int *, 0xC);
            firstCandidateAngle = Level47_81468Call4E880View1(Level47_81468Field(rawWord2, int *, 0) - Level47_81468Field(ownerRecord17, int *, 0xC), Level47_81468Field(rawWord2, int *, 4) - Level47_81468Field(ownerRecord17, int *, 0x10), rawWord6);
            rawWord3 = (previousIndexOrDataBase20 * 0x10) + Level47_81468Field(Level47_81468Field(retainedIndirectRecord19, void **, 0x70), int *, 0xC);
            rawWord7 = Level47_81468Field(rawWord3, int *, 0);
            secondCandidateAngle = Level47_81468Call4E880View1(rawWord7 - Level47_81468Field(ownerRecord17, int *, 0xC), Level47_81468Field(rawWord3, int *, 4) - Level47_81468Field(ownerRecord17, int *, 0x10), 0);
            firstCandidateDelta = Level47_81468Call4F264View1(selectedAngle21, firstCandidateAngle);
            if (Level47_81468Call4F264View1(selectedAngle21, secondCandidateAngle) < firstCandidateDelta) {
                Level47_81468Field(privateRecord18, unsigned char *, 0xE) = (unsigned char) nextIndex22;
            }
            else {
                Level47_81468Field(privateRecord18, unsigned char *, 0xE) = (unsigned char) previousIndexOrDataBase20;
            }
            rawWord2 = (Level47_81468Field(privateRecord18, unsigned char *, 0xE) * 0x10) + Level47_81468Field(Level47_81468Field(retainedIndirectRecord19, void **, 0x70), int *, 0xC);
            rawWord2 = Level47_81468Call4E880View1(Level47_81468Field(rawWord2, int *, 0) - Level47_81468Field(ownerRecord17, int *, 0xC), Level47_81468Field(rawWord2, int *, 4) - Level47_81468Field(ownerRecord17, int *, 0x10), 0);
            rawWord4=0;
            rawWord5=32;
            __asm__(""::"r"(rawWord4),"r"(rawWord5),"r"(rawWord2));
            retainedAnglePositionOrDistance16=rawWord2;
            rawWord2=Level47_81468Call363DCView1(rawWord4,rawWord5);
            retainedAnglePositionOrDistance16=retainedAnglePositionOrDistance16+rawWord2;
            rawWord2=Level47_81468Call3613CView1(reverseAngle23,retainedAnglePositionOrDistance16&255);
            rawWord3=108;
            completeSignedProduct=(long long)rawWord2*(long long)rawWord3;
            rawWord4=70;
            rawWord5=90;
            __asm__("":"=l"(completeProductLow):"x"(completeSignedProduct),"r"(rawWord4),"r"(rawWord5));
            rawWord8=completeProductLow;
            __asm__("":"=r"(rawWord8):"0"(rawWord8));
            rawWord2=rawWord8>>7;
            rawWord2=reverseAngle23+rawWord2;
            Level47_81468Field(privateRecord18,short*,10)=rawWord2;
            Level47_81468Field(privateRecord18, short *, 0x10) = Level47_81468Call3636CView1(rawWord4,rawWord5);
            Level47_81468Field(privateRecord18, short *, 0xC) = 0;
            rawWord2 = (int) (Level47_81468Call4F334View1(ownerRecord17 + 0xC, Level47_81468Field(Level47_81468Field(retainedIndirectRecord19, void **, 0x70), int *, 0xC) + (Level47_81468Field(privateRecord18, unsigned char *, 0xE) * 0x10)) / (short) Level47_81468Field(privateRecord18, short *, 0x10)) >> 1;
            Level47_81468Field(privateRecord18, short *, 0x12) = (short) rawWord2;
            if ((short) rawWord2 >= 0x5B) {
                Level47_81468Field(privateRecord18, short *, 0x12) = 0x5A;
            }
            if (Level47_81468Field(ownerRecord17, unsigned char *, 0x3D) != 1) {
                Level47_81468Data6C770View1 = 0;
                rawWord3 = Level47_81468Field(ownerRecord17, unsigned char *, 0x3D);
                rawWord5 = Level47_81468Field(ownerRecord17, unsigned char *, 0x3F);
                Level47_81468Field(ownerRecord17, signed char *, 0x40) = 0x72;
                Level47_81468Field(ownerRecord17, unsigned char *, 0x3D) = 1U;
                Level47_81468Field(ownerRecord17, unsigned char *, 0x3F) = 0U;
                Level47_81468Field(ownerRecord17, unsigned char *, 0x3C) = rawWord3;
                Level47_81468Field(ownerRecord17, unsigned char *, 0x3E) = rawWord5;
                Level47_81468Call35734View1(ownerRecord17, rawWord5);
            }
            Level47_81468Field(ownerRecord17, unsigned char *, 0x48) = 5U;
            return;
        }
        if ((Level47_81468Data6C770View1 != 0) && (Level47_81468Field(ownerRecord17, unsigned char *, 0x3D) != 0)) {
            Level47_81468Data6C770View1 = 0;
            rawWord2 = Level47_81468Field(ownerRecord17, unsigned char *, 0x3D);
            rawWord5 = Level47_81468Field(ownerRecord17, unsigned char *, 0x3F);
            Level47_81468Field(ownerRecord17, signed char *, 0x40) = 0x72;
            Level47_81468Field(ownerRecord17, unsigned char *, 0x3D) = 0U;
            Level47_81468Field(ownerRecord17, unsigned char *, 0x3F) = 0U;
            Level47_81468Field(ownerRecord17, unsigned char *, 0x3C) = rawWord2;
            Level47_81468Field(ownerRecord17, unsigned char *, 0x3E) = rawWord5;
            Level47_81468Call35734View1(ownerRecord17, rawWord5);
            return;
        }
        break;
    case 5:
        retainedAnglePositionOrDistance16 = Level47_81468Call4F334View1(ownerRecord17 + 0xC, Level47_81468Field(Level47_81468Field(retainedIndirectRecord19, void **, 0x70), int *, 0xC) + (Level47_81468Field(privateRecord18, unsigned char *, 0xE) * 0x10));
        rawWord2 = Level47_81468Field(privateRecord18, short *, 0xC);
        rawWord3=Level47_81468Field(privateRecord18,short*,0x10);
        rawWord4=rawWord2;
        __asm__("":"=r"(rawWord4):"0"(rawWord4));
        rawWord2=rawWord2<rawWord3;
        if(rawWord2){
            rawWord2=rawWord4+10;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            Level47_81468Field(privateRecord18,short*,0xC)=rawWord2;
        }
        if (Level47_81468Call359A4View1(privateRecord18 + 0x12, 2) != 0) {
            rawWord2 = (Level47_81468Field(privateRecord18, unsigned char *, 0xE) * 0x10) + Level47_81468Field(Level47_81468Field(retainedIndirectRecord19, void **, 0x70), int *, 0xC);
            rawWord3 = Level47_81468Call3613CView1(Level47_81468Call4E880View1(Level47_81468Field(rawWord2, int *, 0) - Level47_81468Field(ownerRecord17, int *, 0xC), Level47_81468Field(rawWord2, int *, 4) - Level47_81468Field(ownerRecord17, int *, 0x10), 0), Level47_81468Field(privateRecord18, short *, 0xA));
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            rawWord2 = rawWord3;
            if (rawWord3 < 0) {
                rawWord2 = -rawWord2;
            }
            rawWord4 = 1;
            if (rawWord2 >= 0x1F) {
                rawWord4 = 2;
            }
            if (rawWord3 > 0) {
                rawWord2 = (unsigned short) Level47_81468Field(privateRecord18, short *, 0xA) - rawWord4;
                goto storeOriginalAdjustedAngle;
            }
            if (rawWord3 < 0) {
                rawWord2 = (unsigned short) Level47_81468Field(privateRecord18, short *, 0xA) + rawWord4;
            storeOriginalAdjustedAngle:
                Level47_81468Field(privateRecord18, short *, 0xA) = rawWord2;
            }
        }
        if (Level47_81468Call3585CView1(ownerRecord17, Level47_81468Field(privateRecord18, short *, 0xA), 5, 0x14, 1, 0) != 0) {
            if (Level47_81468Call35DDCView1(ownerRecord17, Level47_81468Field(privateRecord18, short *, 0xC), 0x12C, 0x12C, 5) != 0) {
                Level47_81468Field(privateRecord18, unsigned char *, 0xF) = (unsigned char) (Level47_81468Field(privateRecord18, unsigned char *, 0xF) + 1);
            }
            else {
                Level47_81468Field(privateRecord18, unsigned char *, 0xF) = 0U;
            }
            rawWord2=Level47_81468Field(privateRecord18,unsigned char*,15);
            rawWord2=(unsigned)rawWord2<4;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            if(rawWord2){
                rawWord2=retainedAnglePositionOrDistance16<0x708;
                goto originalFinalDistanceCheck;
            }
            rawWord2=retainedAnglePositionOrDistance16<0x708;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            {
                if (Level47_81468Data6C770View1 != 0) {
                    if (retainedAnglePositionOrDistance16 < 0x1400) {
                        Level47_81468Field(ownerRecord17, unsigned char *, 0x48) = 3U;
                    }
                    else {
                        Level47_81468Field(privateRecord18, short *, 0xA) = (short) ((unsigned short) Level47_81468Field(privateRecord18, short *, 0xA) + Level47_81468Call363DCView1(0x3C, 0x64));
                    }
                }
                goto recomputeOriginalDistancePredicate;
            }
        }
        else {
        recomputeOriginalDistancePredicate:
            rawWord2 = retainedAnglePositionOrDistance16 < 0x708;
        }
    originalFinalDistanceCheck:
        if ((rawWord2 != 0) && (Level47_81468Data6C770View1 != 0)) {
            Level47_81468Field(ownerRecord17, unsigned char *, 0x48) = 3U;
        }
        goto originalFinalUpdate;
    }
    return;
originalFinalUpdate:
    Level47_81468Call5629CView1(ownerRecord17);
}
#undef Level47_81468Field


/* SCUS-94467 USA Rev 0: original instructions at 0x8007D730.
 * Signed halfword motion and timers; angles consume the low unsigned byte.
 * One update per invocation; caller cadence and particle semantics unresolved.
 * Empty asm constraints emit no instructions and preserve retail scheduling.
 */
typedef struct {
    short velocityX, velocityY, velocityZ;
    short rollDelta, pitchDelta, yawDelta;
    short lifetime, reserved0E;
    int reserved10;
    short bounceCount, particleTimer;
} DecodedBounceTag;
extern int DecodedBounceFloor __asm__("D_80071908");
int DecodedBounceContact(Vector3D*, int, int, Moby*) __asm__("func_8001A310");
int DecodedBounceFragments(Moby*) __asm__("func_80039714");
int DecodedBounceRandom(int, int) __asm__("func_8003636C");
int DecodedBounceCountdown(void*, int) __asm__("func_800359A4");
void DecodedBounceDelete(Moby*) __asm__("func_80055B18");
void func_level_47_80081EAC(Moby* argument) {
    Vector3D velocity;
    int reserved1C;
    Vector3D position;
    int reserved2C;
    register Moby* moby __asm__("$16") = argument;
    register DecodedBounceTag* tag __asm__("$17") = moby->mobyTag;
    register unsigned char* particle __asm__("$3");
    int index;
    if (!moby->state && DecodedBounceContact(&moby->position, 150, 3, moby)) {
        if (tag->bounceCount < 3) {
            register int coefficient __asm__("$3") = 3 - tag->bounceCount;
            __asm__("" : "=r"(coefficient) : "0"(coefficient));
            {
                register int vertical __asm__("$2") = coefficient * 50;
                tag->velocityZ = vertical;
            }
            {
                register unsigned int count __asm__("$3") = (unsigned short)tag->bounceCount;
                count++;
                __asm__("" : "=r"(count) : "0"(count));
                tag->bounceCount = count;
            }
            __asm__ volatile("" : : : "memory");
            {
                register int floor __asm__("$2") = DecodedBounceFloor;
                moby->position.z = floor + 155;
            }
            tag->velocityX = tag->velocityX * 2 / 3;
            tag->velocityY = tag->velocityY * 2 / 3;
            tag->lifetime = 150;
        } else {
            moby->state = 1;
            moby->position.z = DecodedBounceFloor;
            tag->lifetime = 100;
        }
    }
    switch (moby->state) {
    case 3:
        if (DecodedBounceFragments(moby)) {
            for (index = 0; index < 3; index++) {
                {
                    int sample = DecodedBounceRandom(0, 2048);
                    register int coordinate __asm__("$3") = moby->position.x - 1024;
                    __asm__("" : "=r"(coordinate) : "0"(coordinate));
                    coordinate += sample;
                    __asm__("" : "=r"(coordinate) : "0"(coordinate));
                    position.x = coordinate;
                }
                {
                    int sample = DecodedBounceRandom(0, 2048);
                    register int coordinate __asm__("$3") = moby->position.y - 1024;
                    __asm__("" : "=r"(coordinate) : "0"(coordinate));
                    coordinate += sample;
                    __asm__("" : "=r"(coordinate) : "0"(coordinate));
                    position.y = coordinate;
                }
                {
                    int sample = DecodedBounceRandom(0, 2048);
                    int coordinate;
                    register char* (*spawn)(int, int, Vector3D*, Vector3D*) __asm__("$3");
                    register int kind __asm__("$4") = 1;
                    register int selector __asm__("$5") = 1;
                    register Vector3D* positionArgument __asm__("$6") = &position;
                    register Vector3D* velocityArgument __asm__("$7");
                    __asm__("" : : "r"(kind), "r"(selector), "r"(positionArgument));
                    coordinate = moby->position.z;
                    velocity.z = -30;
                    __asm__ volatile("" : : : "memory");
                    spawn = SpawnParticle;
                    __asm__("" : : "r"(spawn) : "$7");
                    velocityArgument = &velocity;
                    __asm__("" : : "r"(spawn), "r"(velocityArgument));
                    velocity.x = 0;
                    velocity.y = 0;
                    coordinate -= 1024;
                    coordinate += sample;
                    __asm__("" : "=r"(coordinate) : "0"(coordinate));
                    position.z = coordinate;
                    particle = spawn(kind, selector, positionArgument, velocityArgument);
                }
                __asm__("" : "=r"(particle) : "0"(particle));
                if (particle) {
                    particle[10] = 180;
                }
            }
        }
        break;
    case 2:
        DecodedBounceFragments(moby);
        break;
    case 0:
        velocity.x = 0;
        velocity.y = 0;
        velocity.z = 30;
        SpawnParticle(1, 1, &moby->position, &velocity);
        moby->position.x += tag->velocityX;
        moby->position.y += tag->velocityY;
        tag->velocityZ -= 10;
        if (tag->velocityZ < -200) {
            tag->velocityZ = -200;
        }
        moby->position.z += tag->velocityZ;
        moby->angle.roll += *(unsigned char*)&tag->rollDelta;
        moby->angle.pitch += *(unsigned char*)&tag->pitchDelta;
        moby->angle.yaw += *(unsigned char*)&tag->yawDelta;
        if (DecodedBounceCountdown(&tag->lifetime, 2)) {
            DecodedBounceDelete(moby);
        }
        break;
    case 1:
        if (!tag->particleTimer) {
            velocity.x = DecodedBounceRandom(0, 20) - 10;
            velocity.y = DecodedBounceRandom(0, 20) - 10;
            velocity.z = 20;
            moby->position.z += 50;
            {
                unsigned char* result = SpawnParticle(1, 0, &moby->position, &velocity);
                register int restoredZ __asm__("$3") = moby->position.z;
                __asm__("" : "=r"(restoredZ) : "0"(restoredZ));
                restoredZ -= 50;
                moby->position.z = restoredZ;
                __asm__("" : : "r"(restoredZ));
                particle = result;
                __asm__("" : "=r"(particle) : "0"(particle));
            }
            if (particle) {
                particle[10] = 50;
            }
            tag->particleTimer = 5;
        } else {
            DecodedBounceCountdown(&tag->particleTimer, 2);
        }
        if (DecodedBounceCountdown(&tag->lifetime, 2)) {
            DecodedBounceDelete(moby);
        }
        break;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0; original 80082248.
* Original assembly SHA256 a51ebd475d90ada78591b2387ca6c38d1fba6542abf8c02bb4764b8fe37ca15b.
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
#define Level47_82248Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Level47_82248Call13E38() __asm__("func_80013E38");
int Level47_82248Call1830C() __asm__("func_8001830C");
int Level47_82248Call19138() __asm__("func_80019138");
void * Level47_82248Call1AD60() __asm__("func_8001AD60");
int Level47_82248Call1C288() __asm__("func_8001C288");
int Level47_82248Call34F80() __asm__("func_80034F80");
int Level47_82248Call3573C() __asm__("func_8003573C");
int Level47_82248Call359A4(void*,int) __asm__("func_800359A4");
int Level47_82248Call3636C() __asm__("func_8003636C");
int Level47_82248Call3BABC() __asm__("func_8003BABC");
int Level47_82248Call40954() __asm__("func_80040954");
int Level47_82248Call4E880(int,int,int) __asm__("func_8004E880");
int Level47_82248Call4ED6C() __asm__("func_8004ED6C");
int Level47_82248Call4EDE8() __asm__("func_8004EDE8");
int Level47_82248Call4EF74() __asm__("func_8004EF74");
int Level47_82248Call4F08C() __asm__("func_8004F08C");
int Level47_82248Call4F178() __asm__("func_8004F178");
int Level47_82248Call4F194() __asm__("func_8004F194");
int Level47_82248Call4F1C8() __asm__("func_8004F1C8");
int Level47_82248Call4F334() __asm__("func_8004F334");
int Level47_82248Call55B18() __asm__("func_80055B18");
int Level47_82248Call55D24() __asm__("func_80055D24");
int Level47_82248Datarand(void) __asm__("rand");
extern int Level47_82248Data658A0 __asm__("D_800658A0");
extern int Level47_82248Data65920 __asm__("D_80065920");
extern int Level47_82248Data6C550 __asm__("D_8006C550");
extern int Level47_82248Data6D048 __asm__("D_8006D048");
extern int Level47_82248Data6E020 __asm__("D_8006E020");
extern int Level47_82248Data6E024 __asm__("D_8006E024");
extern int Level47_82248Data6E028 __asm__("D_8006E028");
extern unsigned short Level47_82248Data6E03E __asm__("D_8006E03E");
extern unsigned short Level47_82248Data6E040 __asm__("D_8006E040");
extern void * Level47_82248Data6E788 __asm__("D_8006E788");
extern int Level47_82248Data70328 __asm__("D_80070328");
extern int Level47_82248Data71900 __asm__("D_80071900");
extern int Level47_82248Data71918 __asm__("D_80071918");
extern int Level47_82248Data71924 __asm__("D_80071924");
extern void*(*Level47_82248DataSpawnMoby)() __asm__("SpawnMoby");
extern void*(*Level47_82248DataSpawnParticle)() __asm__("SpawnParticle");
extern int(*Level47_82248Data74424)() __asm__("unk_ovlheader_80074424");
extern void*(*Level47_82248Data74428)() __asm__("unk_ovlheader_80074428");
void func_level_47_80082248(void *ownerParameter) {
    register void *ownerRecord19 __asm__("$19");
    register int retainedAngleOrRecord16 __asm__("$16"),retainedRecordOrVector17 __asm__("$17"),retainedAngleOrAddress18 __asm__("$18"),retainedRecordOrDataAddress20 __asm__("$20"),privateRecord21 __asm__("$21"),retainedSearchPosition22 __asm__("$22"),retainedSelectedRecord23 __asm__("$23");
    register int rangeBoundOrProductHigh10 __asm__("$10");
    register int rawWord2 __asm__("$2"),rawWord3,argumentWord4 __asm__("$4"),argumentWord5 __asm__("$5"),argumentWord6 __asm__("$6"),argumentWord7 __asm__("$7"),nearestDifference8 __asm__("$8"),directionSign9 __asm__("$9");
    int retainedMinimumScoreOrDataAddress;
    struct{
        int sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74;
    }
    originalFrame;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a0_5;
    void *temp_a0_6;
    void *temp_a0_7;
    void *temp_v0_12;
    ownerRecord19=ownerParameter;
    __asm__("":"=r"(ownerRecord19):"0"(ownerRecord19));
    privateRecord21=(int)Level47_82248Field(ownerRecord19,void**,0);
    Level47_82248Call55D24(ownerParameter,6);
    rawWord3 = Level47_82248Field(ownerRecord19, unsigned char *, 0x48);
    retainedSearchPosition22 = 0;
    switch (rawWord3) {
    case 5:
        retainedMinimumScoreOrDataAddress = 0x1869F;
        retainedSelectedRecord23 = 0;
        retainedRecordOrDataAddress20=(int)&Level47_82248Data6E788;
        retainedRecordOrVector17=Level47_82248Field(retainedRecordOrDataAddress20,int*,0);
        retainedRecordOrDataAddress20+=4;
        if (retainedRecordOrVector17 != 0) {
            retainedSearchPosition22 = ownerRecord19 + 0xC;
            do {
                if ((Level47_82248Field(retainedRecordOrVector17, short *, 0x36) != 0x63) && !(Level47_82248Field(retainedRecordOrVector17, unsigned char *, 0x48) & 0x80) && (Level47_82248Field(retainedRecordOrVector17, int *, 8) != 0) && (Level47_82248Field(ownerRecord19, unsigned char *, 0x4D) != 0)) {
                    rangeBoundOrProductHigh10=0x8000;
                    __asm__("":"=r"(rangeBoundOrProductHigh10):"0"(rangeBoundOrProductHigh10):"$2","$3","$4","$5","$6","$7","$8","$9");
                    rawWord3=Level47_82248Field(retainedRecordOrVector17,int*,0xC);
                    rawWord2=Level47_82248Field(ownerRecord19,int*,0xC);
                    argumentWord4=rawWord3-rawWord2;
                    rawWord2 = argumentWord4;
                    if (argumentWord4 < 0) {
                        __asm__("":"=r"(rawWord2):"0"(rawWord2));
                        rawWord2=-rawWord2;
                    }
                    if (rawWord2 <= rangeBoundOrProductHigh10) {
                        rawWord3=Level47_82248Field(retainedRecordOrVector17,int*,0x10);
                        rawWord2=Level47_82248Field(ownerRecord19,int*,0x10);
                        argumentWord5=rawWord3-rawWord2;
                        rawWord2 = argumentWord5;
                        if (argumentWord5 < 0) {
                            __asm__("":"=r"(rawWord2):"0"(rawWord2));
                            rawWord2=-rawWord2;
                        }
                        if (rawWord2 <= rangeBoundOrProductHigh10) {
                            retainedAngleOrRecord16 = (Level47_82248Call4E880(argumentWord4, argumentWord5, 0) - Level47_82248Field(ownerRecord19, unsigned char *, 0x46)) & 0xFF;
                            __asm__("":"=r"(retainedSearchPosition22):"0"(retainedSearchPosition22),"r"(retainedAngleOrRecord16));
                            argumentWord4=retainedSearchPosition22;
                            if (retainedAngleOrRecord16 >= 0x81) {
                                retainedAngleOrRecord16 -= 0x100;
                            }
                            __asm__ __volatile__("":::"$18");
                            retainedAngleOrAddress18 = retainedRecordOrVector17 + 0xC;
                            rawWord3 = (Level47_82248Call4E880(Level47_82248Call4F334(argumentWord4, retainedAngleOrAddress18), Level47_82248Field(retainedRecordOrVector17, int *, 0x14) - Level47_82248Field(ownerRecord19, int *, 0x14), 0) - Level47_82248Field(ownerRecord19, unsigned char *, 0x45)) & 0xFF;
                            if (rawWord3 >= 0x81) {
                                rawWord3 -= 0x100;
                            }
                            if (retainedAngleOrRecord16 < 0) {
                                retainedAngleOrRecord16 = -retainedAngleOrRecord16;
                            }
                            if (rawWord3 < 0) {
                                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                                rawWord3=-rawWord3;
                            }
                            __asm__("":"=r"(retainedAngleOrRecord16):"0"(retainedAngleOrRecord16),"r"(rawWord3));
                            if ((retainedAngleOrRecord16 < 8) && (rawWord3 < 8)) {
                                retainedAngleOrRecord16=(retainedAngleOrRecord16*8)+rawWord3;
                                __asm__("":"=r"(retainedAngleOrRecord16):"0"(retainedAngleOrRecord16));
                                retainedAngleOrRecord16+=Level47_82248Call4F334(retainedSearchPosition22,retainedAngleOrAddress18)>>10;
                                if ((retainedAngleOrRecord16 < retainedMinimumScoreOrDataAddress) && (Level47_82248Call13E38(retainedSearchPosition22, retainedAngleOrAddress18, 4) != 0)) {
                                    retainedSelectedRecord23 = retainedRecordOrVector17;
                                    retainedMinimumScoreOrDataAddress = retainedAngleOrRecord16;
                                }
                            }
                        }
                    }
                }
                retainedRecordOrVector17 = Level47_82248Field(retainedRecordOrDataAddress20,void**,0);
                retainedRecordOrDataAddress20 += 4;
            }
            while (retainedRecordOrVector17 != 0);
        }
        argumentWord4=privateRecord21;
        if(retainedSelectedRecord23!=0){
            argumentWord5=retainedSelectedRecord23+12;
            argumentWord6=Level47_82248Data6C550;
            rawWord2=7;
            Level47_82248Field(ownerRecord19,unsigned char*,0x48)=rawWord2;
            argumentWord6=retainedSelectedRecord23-argumentWord6;
            rawWord2=argumentWord6<<5;
            rawWord2-=argumentWord6;
            rawWord2<<=5;
            rawWord2+=argumentWord6;
            rawWord3=rawWord2<<3;
            rawWord2+=rawWord3;
            rawWord3=rawWord2<<15;
            rawWord3-=rawWord2;
            rawWord3<<=2;
            rawWord3+=argumentWord6;
            rawWord3=-rawWord3;
            rawWord2=Level47_82248Field(ownerRecord19,unsigned char*,0x46);
            rawWord3>>=3;
            Level47_82248Field(ownerRecord19,unsigned char*,0x49)=rawWord3;
            Level47_82248Field(argumentWord4,unsigned char*,0xF)=rawWord2;
            Level47_82248Call4F178(argumentWord4,argumentWord5,argumentWord6);
            return;
        }
        Level47_82248Field(ownerRecord19, unsigned char *, 0x48) = 0U;
        retainedSearchPosition22 = 1;
    case 6:
        if (Level47_82248Field(ownerRecord19, unsigned char *, 0x48) == 6) {
            Level47_82248Call3573C(ownerRecord19, 0x80, 0, 0);
            Level47_82248Field(ownerRecord19, unsigned char *, 0x45) = Level47_82248Call4E880(Level47_82248Call4F334(ownerRecord19 + 0xC, ((void*)&Level47_82248Data70328)), Level47_82248Field(((void*)&Level47_82248Data70328), int *, 8) - Level47_82248Field(ownerRecord19, int *, 0x14), 0);
            Level47_82248Call55D24(ownerRecord19, 4);
            argumentWord4=(int)ownerRecord19+0x20;
            argumentWord5=(int)&originalFrame.sp18;
            rawWord2=Level47_82248Field(privateRecord21,short*,0xC);
            __asm__ __volatile__(""::"r"(argumentWord5));
            argumentWord6=privateRecord21;
            originalFrame.sp1C=0;
            originalFrame.sp20=0;
            originalFrame.sp18=rawWord2;
            Level47_82248Call4ED6C(argumentWord4,argumentWord5,argumentWord6);
            Level47_82248Field(ownerRecord19, unsigned char *, 0x48) = 0U;
        case 7:
        }
        retainedAngleOrAddress18 = 0;
        if (Level47_82248Field(ownerRecord19, unsigned char *, 0x48) == 7) {
            argumentWord4=(int)&originalFrame.sp18;
            __asm__ __volatile__(""::"r"(argumentWord4));
            rawWord3=Level47_82248Field(ownerRecord19,unsigned char*,0x49);
            argumentWord5=(int)ownerRecord19+12;
            rawWord2=rawWord3*88;
            rawWord3=Level47_82248Data6C550;
            retainedRecordOrDataAddress20=rawWord3+rawWord2;
            retainedAngleOrRecord16=retainedRecordOrDataAddress20+12;
            __asm__("":"=r"(retainedAngleOrRecord16):"0"(retainedAngleOrRecord16));
            Level47_82248Call4F1C8(argumentWord4,argumentWord5,retainedAngleOrRecord16);
            rawWord2=Level47_82248Call4E880(originalFrame.sp18,originalFrame.sp1C,0);
            retainedRecordOrVector17=(int)&originalFrame.sp28;
            argumentWord4=retainedRecordOrVector17;
            __asm__ __volatile__(""::"r"(argumentWord4));
            argumentWord5=retainedAngleOrRecord16;
            rawWord3=rawWord2-128;
            Level47_82248Field(ownerRecord19,unsigned char*,0x46)=rawWord3;
            retainedAngleOrRecord16=Level47_82248Field(retainedRecordOrDataAddress20,unsigned char*,0x46);
            __asm__ __volatile__(""::"r"(retainedAngleOrRecord16));
            argumentWord6=privateRecord21;
            retainedAngleOrRecord16-=rawWord2;
            retainedAngleOrRecord16&=255;
            Level47_82248Call4F1C8(argumentWord4,argumentWord5,argumentWord6);
            rawWord2=Level47_82248Call4EDE8(retainedRecordOrVector17,0);
            retainedAngleOrRecord16+=64;
            retainedAngleOrRecord16&=255;
            retainedAngleOrRecord16<<=1;
            rawWord3=Level47_82248Field(&Level47_82248Data65920,short*,retainedAngleOrRecord16);
            {
                long long completeFirstSignedProduct;
                int firstProductLowWord;
                completeFirstSignedProduct=(long long)rawWord2*(long long)rawWord3;
                __asm__("":"=l"(firstProductLowWord):"x"(completeFirstSignedProduct));
                rawWord2=firstProductLowWord;
            }
            {
                long long completeSecondSignedProduct;
                int secondProductHighWord;
                rawWord3=0x1B4E81B5;
                completeSecondSignedProduct=(long long)rawWord2*(long long)rawWord3;
                directionSign9=1;
                rawWord2>>=31;
                __asm__("":"=h"(secondProductHighWord):"x"(completeSecondSignedProduct));
                rangeBoundOrProductHigh10=secondProductHighWord;
                __asm__("":"=r"(rangeBoundOrProductHigh10):"0"(rangeBoundOrProductHigh10));
                rawWord3=rangeBoundOrProductHigh10>>6;
                argumentWord6=rawWord3-rawWord2;
            }
            __asm__("":"=r"(argumentWord6):"0"(argumentWord6):"$8");
            nearestDifference8 = 0x2710;
            if (argumentWord6 < 0) {
                directionSign9 = -1;
            }
            argumentWord6=argumentWord6&0xFFF;
            __asm__("":"=r"(argumentWord6):"0"(argumentWord6));
            rawWord2=argumentWord6>>6;
            argumentWord4=rawWord2-2;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
            argumentWord7 = argumentWord4 + 4;
            if (argumentWord4 < 0) {
                argumentWord4 = 0;
                __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
                argumentWord7=argumentWord4+4;
            }
            if (argumentWord4 < argumentWord7) {
                rawWord2=argumentWord4*2;
                rawWord3=(int)&Level47_82248Data658A0;
                argumentWord5=rawWord2+rawWord3;
                do {
                    rawWord2 = Level47_82248Field(argumentWord5,short*,0) - argumentWord6;
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
                }
                while (argumentWord4 < argumentWord7);
            }
            rawWord2=nearestDifference8<0x79;
            __asm__ __volatile__(""::"r"(nearestDifference8));
            if(!rawWord2){
                retainedAngleOrAddress18 = 0;
                goto block_50;
            }
            rawWord2 = retainedAngleOrAddress18 < 0xB;
            if (directionSign9 < 0) {
                rawWord2=retainedAngleOrAddress18+0x80;
                retainedAngleOrAddress18=rawWord2&0xFF;
            block_50:
                rawWord2 = retainedAngleOrAddress18 < 0xB;
            }
            if(rawWord2==0){
                __asm__ __volatile__("":::"$2");
                retainedAngleOrAddress18 = 0xA;
            }
            else if (retainedAngleOrAddress18 < -0xA) {
                retainedAngleOrAddress18 = -0xA;
            }
            retainedAngleOrRecord16=(int)&originalFrame.sp28;
            __asm__("":"=r"(retainedAngleOrRecord16):"0"(retainedAngleOrRecord16));
            Level47_82248Call4F178(retainedAngleOrRecord16,retainedRecordOrDataAddress20+12,argumentWord6,argumentWord7);
            argumentWord4=(int)ownerRecord19+12;
            rawWord2=originalFrame.sp30;
            argumentWord5=retainedAngleOrRecord16;
            rawWord2+=500;
            originalFrame.sp30=rawWord2;
            rawWord2=Level47_82248Call4F334(argumentWord4,argumentWord5);
            argumentWord4=rawWord2;
            rawWord2=originalFrame.sp30;
            argumentWord5=Level47_82248Field(ownerRecord19,int*,0x14);
            argumentWord6=0;
            argumentWord5=rawWord2-argumentWord5;
            Level47_82248Field(ownerRecord19,unsigned char*,0x45)=Level47_82248Call4E880(argumentWord4,argumentWord5,argumentWord6);
            Level47_82248Field(ownerRecord19, unsigned char *, 0x46) = (unsigned char) (Level47_82248Field(ownerRecord19, unsigned char *, 0x46) + retainedAngleOrAddress18);
            originalFrame.sp28 = 0x258;
            originalFrame.sp2C = 0;
            originalFrame.sp30 = 0;
            Level47_82248Call55D24(ownerRecord19, 4);
            Level47_82248Call4ED6C(ownerRecord19+0x20,retainedAngleOrRecord16,privateRecord21);
            Level47_82248Field(ownerRecord19, unsigned char *, 0x45) = Level47_82248Call4E880(Level47_82248Call4EDE8(privateRecord21, 1), Level47_82248Field(privateRecord21, int *, 8), 0);
            Level47_82248Field(ownerRecord19, unsigned char *, 0x46) = Level47_82248Call4E880(Level47_82248Field(privateRecord21, int *, 0), Level47_82248Field(privateRecord21, int *, 4), 0);
            Level47_82248Field(ownerRecord19, unsigned char *, 0x48) = 0U;
        }
    case 0:
        retainedAngleOrRecord16 = 0;
        rawWord3=Level47_82248Field(ownerRecord19,unsigned char*,0x3A);
        __asm__("":"=r"(rawWord3):"0"(rawWord3));
        retainedRecordOrVector17 = 0;
        if (rawWord3 < 0xFFU) {
            rawWord2=rawWord3*88;
            rawWord3=Level47_82248Data6C550;
            retainedAngleOrRecord16=rawWord3+rawWord2;
        }
        if ((retainedSearchPosition22 != 0) && (retainedAngleOrRecord16 != 0)) {
            Level47_82248Call4F178(&originalFrame.sp48, retainedAngleOrRecord16 + 0xC);
            originalFrame.sp50 += 0x200;
        }
        else {
            Level47_82248Call4F178(&originalFrame.sp48, ownerRecord19 + 0xC);
        }
        argumentWord4=(int)&originalFrame.sp38;
        __asm__ __volatile__(""::"r"(argumentWord4));
        retainedAngleOrAddress18=(int)ownerRecord19+12;
        Level47_82248Call4F194(argumentWord4,retainedAngleOrAddress18,privateRecord21);
        if ((originalFrame.sp38 < 0x1068) || (originalFrame.sp3C < 0x1068) || (originalFrame.sp40 < 0x1068) || (originalFrame.sp38 > 0x3E738) || (originalFrame.sp3C > 0x3E738) || (originalFrame.sp40 > 0x3E738)) {
            temp_a0_2 = Level47_82248Field(privateRecord21, void **, 0x14);
            if (temp_a0_2 != 0) {
                Level47_82248Call55B18(temp_a0_2);
                __asm__ __volatile__(""::"i"(103111):"memory");
                Level47_82248Field(privateRecord21, void **, 0x14) = 0;
            }
            goto block_134;
        }
        if ((retainedAngleOrRecord16 != 0) && (Level47_82248Field(retainedAngleOrRecord16, short *, 0x36) != 0x63) && (Level47_82248Call1C288(retainedAngleOrAddress18, 0xC8, 1) != 0)) {
            argumentWord4=197;
            argumentWord5=0;
            __asm__ __volatile__(""::"r"(argumentWord5):"memory");
            rawWord2=Level47_82248Field(ownerRecord19,unsigned char*,0x46);
            rawWord3=(int)Level47_82248DataSpawnMoby;
            __asm__ __volatile__(""::"r"(rawWord2),"r"(rawWord3):"$17");
            retainedRecordOrVector17=(int)&Level47_82248Data70328+0x298;
            Level47_82248Field(retainedRecordOrVector17,int*,0)=rawWord2;
            retainedAngleOrRecord16=((void*(*)())rawWord3)(argumentWord4,argumentWord5);
            __asm__("":"=r"(retainedAngleOrRecord16):"0"(retainedAngleOrRecord16));
            if (retainedAngleOrRecord16 != 0) {
                rawWord3 = Level47_82248Field(retainedAngleOrRecord16, void **, 0);
                Level47_82248Field(retainedAngleOrRecord16, signed char *, 0x48) = 4;
                Level47_82248Field(retainedAngleOrRecord16, signed char *, 0x41) = 0;
                Level47_82248Field(retainedAngleOrRecord16, signed char *, 0x4C) = 0;
                Level47_82248Field(retainedAngleOrRecord16, signed char *, 0x4D) = 0;
                Level47_82248Field(rawWord3, short *, 0x10) = 0xF;
                Level47_82248Field(rawWord3, short *, 0x12) = 1;
                Level47_82248Call4F178(retainedAngleOrRecord16 + 0xC, retainedRecordOrVector17-0x298);
                Level47_82248Field(retainedAngleOrRecord16, int *, 0x14) = (int) Level47_82248Field(ownerRecord19, int *, 0x14);
            }
            goto block_94;
        }
        if (Level47_82248Field(privateRecord21, short *, 0xC) >= 0xFA1) {
            rawWord2 = Level47_82248Data74424(&originalFrame.sp48, &originalFrame.sp38, 0, 1) == 0;
        }
        else {
            rawWord2 = Level47_82248Call1830C(&originalFrame.sp48, &originalFrame.sp38, 2, 1, 0);
        }
        if(rawWord2==0){
            rawWord2=Level47_82248Field(privateRecord21,short*,0xC);
            if(rawWord2>=4001){
                argumentWord4=(int)&originalFrame.sp48;
                argumentWord5=(int)&originalFrame.sp38;
                __asm__ __volatile__(""::"r"(argumentWord5):"memory");
                rawWord2=(int)Level47_82248Data74428;
                argumentWord6=0;
                retainedAngleOrRecord16=((void*(*)())rawWord2)(argumentWord4,argumentWord5,argumentWord6);
            }
            else{
                argumentWord4=(int)&originalFrame.sp48;
                argumentWord5=(int)&originalFrame.sp38;
                argumentWord6=0;
                argumentWord7=0;
                retainedAngleOrRecord16=Level47_82248Call1AD60(argumentWord4,argumentWord5,argumentWord6,argumentWord7,ownerRecord19);
            }
            if (retainedAngleOrRecord16 != 0) {
                goto block_89;
            }
            goto block_120;
        }
        if (Level47_82248Field(privateRecord21, short *, 0xC) >= 0xFA1) {
            retainedAngleOrRecord16 = Level47_82248Data74428(&originalFrame.sp48, ((void*)&Level47_82248Data71900), 0);
        }
        else {
            retainedAngleOrRecord16 = Level47_82248Call1AD60(&originalFrame.sp48, ((void*)&Level47_82248Data71900), 0, 0, ownerRecord19);
        }
        if (retainedAngleOrRecord16 != 0) {
        block_89:
            rawWord2=Level47_82248Call4E880(Level47_82248Field(privateRecord21,int*,0),Level47_82248Field(privateRecord21,int*,4),0);
            argumentWord4=197;
            argumentWord5=0;
            __asm__ __volatile__(""::"r"(argumentWord4),"r"(argumentWord5):"memory");
            Level47_82248Field(retainedAngleOrRecord16,unsigned char*,0x51)=rawWord2;
            rawWord2=0x10000;
            rawWord3=Level47_82248Field(retainedAngleOrRecord16,int*,0x18);
            argumentWord6=(int)Level47_82248DataSpawnMoby;
            rawWord3|=rawWord2;
            Level47_82248Field(retainedAngleOrRecord16,int*,0x18)=rawWord3;
            retainedRecordOrVector17=((void*(*)())argumentWord6)(argumentWord4,argumentWord5,argumentWord6);
            __asm__("":"=r"(retainedRecordOrVector17):"0"(retainedRecordOrVector17));
            if (retainedRecordOrVector17 != 0) {
                rawWord3 = Level47_82248Field(retainedRecordOrVector17, void **, 0);
                Level47_82248Field(retainedRecordOrVector17, signed char *, 0x48) = 4;
                Level47_82248Field(retainedRecordOrVector17, signed char *, 0x41) = 0;
                Level47_82248Field(retainedRecordOrVector17, signed char *, 0x4C) = 0;
                Level47_82248Field(retainedRecordOrVector17, signed char *, 0x4D) = 0;
                Level47_82248Field(rawWord3, short *, 0x10) = 0xF;
                Level47_82248Field(rawWord3, short *, 0x12) = 1;
                Level47_82248Call4F178(retainedRecordOrVector17 + 0xC, retainedAngleOrRecord16 + 0xC);
                Level47_82248Field(retainedRecordOrVector17, int *, 0x14) = (int) Level47_82248Field(ownerRecord19, int *, 0x14);
            }
            goto block_94;
        }
        if(Level47_82248Field(privateRecord21,unsigned char*,0xE)!=0){
            __asm__("":"=r"(retainedAngleOrRecord16):"0"(retainedAngleOrRecord16));
            retainedRecordOrVector17 = Level47_82248DataSpawnMoby(0xC5, 0);
            __asm__("":"=r"(retainedRecordOrVector17):"0"(retainedRecordOrVector17));
            if (retainedRecordOrVector17 != 0) {
                rawWord3 = Level47_82248Field(retainedRecordOrVector17, void **, 0);
                Level47_82248Field(retainedRecordOrVector17, signed char *, 0x48) = 4;
                Level47_82248Field(retainedRecordOrVector17, signed char *, 0x41) = 0;
                Level47_82248Field(retainedRecordOrVector17, signed char *, 0x4C) = 0;
                Level47_82248Field(retainedRecordOrVector17, signed char *, 0x4D) = 0;
                Level47_82248Field(rawWord3, short *, 0x10) = 0x1E;
                Level47_82248Field(rawWord3, short *, 0x12) = 0xF;
                Level47_82248Call4F178(retainedRecordOrVector17 + 0xC, ((void*)&Level47_82248Data71900));
            }
        block_94:
            retainedRecordOrVector17 = 1;
            goto block_120;
        }
        else{
            __asm__("":"=r"(retainedAngleOrRecord16):"0"(retainedAngleOrRecord16));
            retainedAngleOrAddress18=(int)&Level47_82248Data71924;
            if (Level47_82248Call40954(Level47_82248Field(retainedAngleOrAddress18,int*,0)) == 3) {
                temp_a0_5 = Level47_82248Field(Level47_82248Field(((void*)&Level47_82248Data6D048),int*,0x14),void**,(Level47_82248Field(retainedAngleOrAddress18,int*,0)&0x3F)*4);
                Level47_82248Field(temp_a0_5, int *, 4) = (int) (Level47_82248Field(temp_a0_5, int *, 4) | 0x10000);
            }
            Level47_82248Field(privateRecord21, unsigned char *, 0xE) = (unsigned char) (Level47_82248Field(privateRecord21, unsigned char *, 0xE) + 1);
            Level47_82248Field(ownerRecord19, unsigned char *, 0x48) = 0U;
            retainedRecordOrVector17 = Level47_82248DataSpawnMoby(0xC5, 0);
            __asm__("":"=r"(retainedRecordOrVector17):"0"(retainedRecordOrVector17));
            retainedAngleOrRecord16 = retainedRecordOrVector17 + 0xC;
            if (retainedRecordOrVector17 != 0) {
                argumentWord4=retainedAngleOrRecord16;
                __asm__("":"=r"(retainedAngleOrAddress18):"0"(retainedAngleOrAddress18),"r"(argumentWord4));
                retainedMinimumScoreOrDataAddress=retainedAngleOrAddress18-0x24;
                Level47_82248Field(Level47_82248Field(retainedRecordOrVector17, void **, 0), short *, 0x10) = 2;
                Level47_82248Call4F178(retainedAngleOrRecord16, retainedMinimumScoreOrDataAddress);
                rawWord2=Level47_82248Call3636C(0,0xFF);
                argumentWord4=retainedAngleOrRecord16;
                retainedAngleOrRecord16=(int)&Level47_82248Data6E020;
                argumentWord5=retainedAngleOrRecord16;
                __asm__("":"=r"(rawWord2):"0"(rawWord2),"r"(argumentWord5));
                retainedSearchPosition22=rawWord2;
                Level47_82248Field(retainedRecordOrVector17, signed char *, 0x44) = retainedSearchPosition22;
                rawWord2=Level47_82248Call4F334(argumentWord4,argumentWord5);
                argumentWord4=rawWord2;
                rawWord2=Level47_82248Data6E028;
                argumentWord5=Level47_82248Field(retainedRecordOrVector17,int*,0x14);
                argumentWord6=0;
                argumentWord5=rawWord2-argumentWord5;
                rawWord2=Level47_82248Call4E880(argumentWord4,argumentWord5,argumentWord6);
                argumentWord6=0;
                __asm__("":"=r"(rawWord2):"0"(rawWord2),"r"(argumentWord6));
                retainedRecordOrDataAddress20=rawWord2;
                Level47_82248Field(retainedRecordOrVector17, unsigned char *, 0x45) = retainedRecordOrDataAddress20;
                rawWord2=Level47_82248Call4E880(Level47_82248Field(retainedAngleOrRecord16,int*,0)-Level47_82248Field(retainedRecordOrVector17,int*,0xC),Level47_82248Data6E024-Level47_82248Field(retainedRecordOrVector17,int*,0x10),argumentWord6);
                argumentWord4=retainedRecordOrVector17;
                argumentWord5=1;
                __asm__("":"=r"(rawWord2):"0"(rawWord2),"r"(argumentWord4),"r"(argumentWord5));
                retainedAngleOrAddress18=rawWord2;
                rawWord2=1;
                __asm__ __volatile__(""::"r"(rawWord2):"$16");
                retainedAngleOrRecord16=255;
                Level47_82248Field(argumentWord4,unsigned char*,0x48)=rawWord2;
                rawWord2=13;
                Level47_82248Field(argumentWord4,unsigned char*,0x46)=retainedAngleOrAddress18;
                Level47_82248Field(argumentWord4,unsigned char*,0x54)=retainedAngleOrRecord16;
                Level47_82248Field(argumentWord4,unsigned char*,0x55)=0;
                Level47_82248Field(argumentWord4,unsigned char*,0x56)=0;
                Level47_82248Field(argumentWord4,unsigned char*,0x57)=rawWord2;
                Level47_82248Call34F80(argumentWord4,argumentWord5);
                retainedRecordOrVector17 = Level47_82248DataSpawnMoby(0xC5, 0);
                __asm__("":"=r"(retainedRecordOrVector17):"0"(retainedRecordOrVector17));
                if (retainedRecordOrVector17 != 0) {
                    Level47_82248Field(Level47_82248Field(retainedRecordOrVector17, void **, 0), short *, 0x10) = 2;
                    Level47_82248Field(retainedRecordOrVector17, signed char *, 0x57) = 0xF;
                    Level47_82248Field(retainedRecordOrVector17, signed char *, 0x44) = retainedSearchPosition22;
                    Level47_82248Field(retainedRecordOrVector17, unsigned char *, 0x45) = retainedRecordOrDataAddress20;
                    Level47_82248Field(retainedRecordOrVector17, unsigned char *, 0x46) = retainedAngleOrAddress18;
                    Level47_82248Field(retainedRecordOrVector17,signed char*,0x54)=retainedAngleOrRecord16;
                    Level47_82248Field(retainedRecordOrVector17,signed char*,0x55)=retainedAngleOrRecord16;
                    Level47_82248Field(retainedRecordOrVector17,signed char*,0x56)=retainedAngleOrRecord16;
                    Level47_82248Field(retainedRecordOrVector17, signed char *, 0x48) = 3;
                    Level47_82248Call4F178(retainedRecordOrVector17 + 0xC, retainedMinimumScoreOrDataAddress);
                    Level47_82248Call34F80(retainedRecordOrVector17, 3);
                }
            }
            Level47_82248Call4F178(ownerRecord19 + 0xC, ((void*)&Level47_82248Data71900));
            Level47_82248Call4F178(&originalFrame.sp38, ((void*)&Level47_82248Data71900) + 0x18);
            argumentWord4=originalFrame.sp40;
            if(argumentWord4==0)goto clearOriginalVerticalComponent;
            rawWord3=originalFrame.sp38;
            rawWord2=rawWord3*100;
            rawWord2/=argumentWord4;
            if(rawWord2<0)rawWord2=-rawWord2;
            if(rawWord2>=6)goto clearOriginalVerticalComponent;
            rawWord3=originalFrame.sp3C;
            rawWord2=rawWord3*100;
            rawWord2/=argumentWord4;
            if(rawWord2<0)rawWord2=-rawWord2;
            rawWord2=rawWord2<6;
            argumentWord4=privateRecord21;
            if(rawWord2)goto integrateOriginalVector;
            clearOriginalVerticalComponent:originalFrame.sp40=0;
            argumentWord4=privateRecord21;
            integrateOriginalVector:__asm__ __volatile__("":::"$17");
            retainedRecordOrVector17=(int)&originalFrame.sp38;
            Level47_82248Call4EF74(argumentWord4,retainedRecordOrVector17,privateRecord21);
            if (Level47_82248Field(privateRecord21, short *, 0xC) >= 0xFA1) {
                Level47_82248Field(privateRecord21, short *, 0xC) = 0x258;
            }
            Level47_82248Call4F08C(privateRecord21, Level47_82248Call4EDE8(privateRecord21, 1), Level47_82248Field(privateRecord21, short *, 0xC));
            Level47_82248Call4F178(retainedRecordOrVector17, privateRecord21);
            Level47_82248Call4F08C(retainedRecordOrVector17, Level47_82248Call4EDE8(retainedRecordOrVector17, 1), 0x320);
            argumentWord4=retainedRecordOrVector17;
            __asm__ __volatile__(""::"r"(argumentWord4));
            retainedAngleOrAddress18=(int)ownerRecord19+12;
            Level47_82248Call4F194(argumentWord4,retainedAngleOrAddress18,retainedRecordOrVector17);
            Level47_82248Field(ownerRecord19, unsigned char *, 0x45) = Level47_82248Call4E880(Level47_82248Call4EDE8(privateRecord21, 1), Level47_82248Field(privateRecord21, int *, 8), 0);
            Level47_82248Field(ownerRecord19, unsigned char *, 0x46) = Level47_82248Call4E880(Level47_82248Field(privateRecord21, int *, 0), Level47_82248Field(privateRecord21, int *, 4), 0);
            Level47_82248Call3BABC(ownerRecord19, 1, 0);
            retainedAngleOrRecord16=(int)&originalFrame.sp58;
            argumentWord4=retainedAngleOrRecord16;
            __asm__ __volatile__(""::"r"(argumentWord4):"$20");
            retainedRecordOrDataAddress20=(int)&Level47_82248Data71918;
            Level47_82248Call4F178(argumentWord4,retainedRecordOrDataAddress20);
            Level47_82248Call4F08C(&originalFrame.sp58, Level47_82248Call4EDE8(&originalFrame.sp58, 1), 0x37);
            Level47_82248Call4F194(&originalFrame.sp58, retainedAngleOrAddress18, &originalFrame.sp58);
            if ((Level47_82248Call19138(&originalFrame.sp58, 0x32, 1, 0, 0, 0) != 0) || (Level47_82248Call1830C(retainedRecordOrVector17, &originalFrame.sp58, 3, 0, 0) != 0)) {
                if (Level47_82248Call40954(Level47_82248Data71924) == 3) {
                    temp_a0_6 = Level47_82248Field(Level47_82248Field(((void*)&Level47_82248Data6D048),int*,0x14),void**,(Level47_82248Data71924&0x3F)*4);
                    Level47_82248Field(temp_a0_6, int *, 4) = (int) (Level47_82248Field(temp_a0_6, int *, 4) | 0x10000);
                }
                retainedRecordOrVector17 = Level47_82248DataSpawnMoby(0xC5, 0);
                __asm__("":"=r"(retainedRecordOrVector17):"0"(retainedRecordOrVector17));
                if (retainedRecordOrVector17 != 0) {
                    rawWord3 = Level47_82248Field(retainedRecordOrVector17, void **, 0);
                    Level47_82248Field(retainedRecordOrVector17, signed char *, 0x48) = 4;
                    Level47_82248Field(retainedRecordOrVector17, signed char *, 0x41) = 0;
                    Level47_82248Field(retainedRecordOrVector17, signed char *, 0x4C) = 0;
                    Level47_82248Field(retainedRecordOrVector17, signed char *, 0x4D) = 0;
                    Level47_82248Field(rawWord3, short *, 0x10) = 0x1E;
                    Level47_82248Field(rawWord3, short *, 0x12) = 0xF;
                    Level47_82248Call4F178(retainedRecordOrVector17 + 0xC, retainedRecordOrDataAddress20-0x18);
                }
                temp_a0_7 = Level47_82248Field(privateRecord21, void **, 0x14);
                if (temp_a0_7 != 0) {
                    Level47_82248Call55B18(temp_a0_7);
                    __asm__ __volatile__(""::"i"(103113):"memory");
                    Level47_82248Field(privateRecord21, void **, 0x14) = 0;
                }
                goto block_134;
            }
            Level47_82248Call4F178(retainedAngleOrAddress18, retainedRecordOrVector17);
            rawWord3 = Level47_82248Field(privateRecord21, void **, 0x14);
            if (rawWord3 != 0) {
                Level47_82248Field(rawWord3, unsigned char *, 0x45) = (unsigned char) Level47_82248Field(ownerRecord19, unsigned char *, 0x45);
                Level47_82248Field(Level47_82248Field(privateRecord21, void **, 0x14), unsigned char *, 0x46) = (unsigned char) Level47_82248Field(ownerRecord19, unsigned char *, 0x46);
                Level47_82248Call4F178(Level47_82248Field(privateRecord21, void **, 0x14) + 0xC, retainedAngleOrAddress18);
                rawWord3=Level47_82248Field(privateRecord21,int*,0x14);
                rawWord2=255;
                Level47_82248Field(rawWord3,unsigned char*,0x54)=rawWord2;
                Level47_82248Field(Level47_82248Field(privateRecord21, void **, 0x14), signed char *, 0x55) = 0;
                Level47_82248Field(Level47_82248Field(privateRecord21, void **, 0x14), signed char *, 0x56) = 0;
                Level47_82248Field(Level47_82248Field(privateRecord21, void **, 0x14), signed char *, 0x57) = 0x38;
                Level47_82248Call34F80(Level47_82248Field(privateRecord21, void **, 0x14), 4);
                return;
            }
        default:
            return;
        }
    block_120:
        if ((retainedRecordOrVector17 != 0) || (Level47_82248Call359A4(privateRecord21 + 0x10, 2) != 0)) {
            temp_a0_3 = Level47_82248Field(privateRecord21, void **, 0x14);
            if (temp_a0_3 != 0) {
                Level47_82248Call55B18(temp_a0_3);
                __asm__ __volatile__(""::"i"(103112):"memory");
                Level47_82248Field(privateRecord21, void **, 0x14) = 0;
            }
            goto block_134;
        }
        Level47_82248Call4F178(ownerRecord19 + 0xC, &originalFrame.sp38);
        temp_a0_4 = Level47_82248Field(privateRecord21, void **, 0x14);
        if (temp_a0_4 != 0) {
            Level47_82248Call4F178(temp_a0_4 + 0xC, &originalFrame.sp38);
            Level47_82248Field(Level47_82248Field(privateRecord21, void **, 0x14), unsigned char *, 0x45) = (unsigned char) Level47_82248Field(ownerRecord19, unsigned char *, 0x45);
            Level47_82248Field(Level47_82248Field(privateRecord21, void **, 0x14), unsigned char *, 0x46) = (unsigned char) Level47_82248Field(ownerRecord19, unsigned char *, 0x46);
            return;
        }
        break;
    case 4:
        Level47_82248Field(ownerRecord19, signed char *, 0x41) = 0;
        Level47_82248Field(ownerRecord19, signed char *, 0x4C) = 0;
        Level47_82248Field(ownerRecord19, unsigned char *, 0x4D) = 0U;
        if (Level47_82248Field(privateRecord21, short *, 0x10) != 0) {
            originalFrame.sp68 = (Level47_82248Datarand() & 0xF) - 7;
            originalFrame.sp6C = (Level47_82248Datarand() & 0xF) - 7;
            originalFrame.sp70 = Level47_82248Datarand() & 0x3F;
            Level47_82248DataSpawnParticle(1, 0, ownerRecord19 + 0xC, &originalFrame.sp68);
        }
        if (Level47_82248Field(privateRecord21, short *, 0x12) != 0) {
            Level47_82248Call359A4(privateRecord21 + 0x12, 2);
            temp_v0_12 = Level47_82248DataSpawnParticle(1, 0x3D, ownerRecord19 + 0xC, (int *)0x808080);
            if (temp_v0_12 != 0) {
                Level47_82248Field(temp_v0_12, signed char *, 0xA) = 0x32;
            }
        }
        if (Level47_82248Call359A4(privateRecord21 + 0x10, 2) != 0) {
            goto block_134;
        }
        break;
    case 1:
    case 3:
        if(Level47_82248Field(privateRecord21,short*,0x10)!=0)goto continueOriginalStatesOneOrThree;
        block_134:Level47_82248Call55B18(ownerRecord19);
        return;
    continueOriginalStatesOneOrThree:
        if (Level47_82248Call359A4(privateRecord21 + 0x10, 2) != 0) {
            rawWord2=48;
            Level47_82248Field(ownerRecord19,unsigned char*,0x4F)=rawWord2;
            rawWord2=Level47_82248Field(ownerRecord19,unsigned char*,0x54);
            rawWord3=13;
            Level47_82248Field(ownerRecord19,unsigned char*,0x57)=rawWord3;
            rawWord3=Level47_82248Field(ownerRecord19,unsigned char*,0x56);
            rawWord2>>=3;
            Level47_82248Field(ownerRecord19,unsigned char*,0x54)=rawWord2;
            rawWord2=Level47_82248Field(ownerRecord19,unsigned char*,0x55);
            rawWord3=(unsigned int)rawWord3>>3;
            Level47_82248Field(ownerRecord19,unsigned char*,0x56)=rawWord3;
            rawWord2>>=3;
            Level47_82248Field(ownerRecord19,unsigned char*,0x55)=rawWord2;
        }
        Level47_82248Field(ownerRecord19, unsigned char *, 0x46) = (unsigned char) (((int) (Level47_82248Data6E040 << 0x10) >> 0x14) - 0x80);
        Level47_82248Field(ownerRecord19, unsigned char *, 0x45) = (unsigned char) ((unsigned short) Level47_82248Data6E03E >> 4);
        break;
    }
}
#undef Level47_82248Field


/* AI generated; not yet human reviewed. SCUS-94467 USA Rev 0.
 * Original 412-instruction actor callback and 23-word dispatch table.
 * Field offsets, signed/unsigned access widths, callback order and the
 * 136-byte stack frame are preserved. Empty compiler constraints emit no
 * opcodes; they preserve original register producers and store boundaries.
 * Vector units, helper contracts, caller cadence and synchronized runtime
 * semantics remain unresolved. Acceptance requires every linked original
 * word, owned table word and the full EXE/every-overlay hashes to match.
 */
#define M2C_FIELD(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Probe83264func_800359A4() __asm__("func_800359A4");
int Probe83264func_8004E880() __asm__("func_8004E880");
int Probe83264func_8004ED6C() __asm__("func_8004ED6C");
int Probe83264func_8004F178() __asm__("func_8004F178");
int Probe83264func_8004F194() __asm__("func_8004F194");
int Probe83264func_8004F334() __asm__("func_8004F334");
int Probe83264func_80050844() __asm__("func_80050844");
int Probe83264func_800509E8() __asm__("func_800509E8");
int Probe83264func_80055B18() __asm__("func_80055B18");
int Probe83264func_80055D24() __asm__("func_80055D24");
extern unsigned char Probe83264D_800658A0[] __asm__("D_800658A0");
extern unsigned char Probe83264D_80065920[] __asm__("D_80065920");
extern int Probe83264D_8006C550 __asm__("D_8006C550");
extern int Probe83264D_8006C648 __asm__("D_8006C648");
extern int Probe83264D_8006E020 __asm__("D_8006E020");
extern int Probe83264D_8006E024 __asm__("D_8006E024");
extern int Probe83264D_8006E028 __asm__("D_8006E028");
extern int (*Probe83264SpawnParticle)() __asm__("SpawnParticle");
void func_level_47_80083264(void *owner) {
    struct { int sp10,sp14,sp18,pad1c,sp20,sp24,sp28,pad2c,sp30,sp34,sp38,pad3c,sp40,sp44,sp48,pad4c,sp50,sp54,sp58,pad5c,pad60,pad64; } frame;
    register int savedStateHalfword __asm__("21");
    register int phaseWord3 __asm__("3");
    register int workWord2 __asm__("2");
    int *referenceBase;
    int handleWord;
    int nextVerticalWord;
    register unsigned char stateByte49 __asm__("4");
    register unsigned int color2 __asm__("2");
    register unsigned int color3 __asm__("3");
    unsigned char selector48;
    void *ownerPosition13;
    void *linkedActor20;
    register void *positionOrVector __asm__("16");
    void *linkedActor;
    void *linkedActor21;
    register void *matrix11 __asm__("17");
    register void *matrix10 __asm__("17");
    register void *state __asm__("18");
    void *ownerPosition23;
    register void *ownerPosition __asm__("20");
    void *var_a0;
    register void *helperArg4 __asm__("4");
    register void *helperArg5 __asm__("5");
    register void *helperArg6 __asm__("6");
    register int savedWordArg4 __asm__("4");
    register int tickWord3 __asm__("3");

    selector48 = M2C_FIELD(owner, unsigned char *, 0x48);
    state = M2C_FIELD(owner, void **, 0);
    switch (selector48) {
    case 22:
        positionOrVector = owner + 0xC;
        frame.sp10 = (int) (((short *)Probe83264D_80065920)[M2C_FIELD(owner, unsigned char *, 0x46)] * 0x19) >> 9;

        frame.sp14 = (int) (((short *)Probe83264D_800658A0)[M2C_FIELD(owner, unsigned char *, 0x46)] * 0x19) >> 9;
        frame.sp18 = 0;
        Probe83264func_8004F194(positionOrVector, positionOrVector, &frame.sp10);
        M2C_FIELD(owner, int *, 0x14) = (int) (M2C_FIELD(owner, int *, 0x14) + M2C_FIELD(state, int *, 8));
        nextVerticalWord = M2C_FIELD(state, int *, 8) - 0x10;
        M2C_FIELD(state, int *, 8) = nextVerticalWord;
        if (nextVerticalWord < -0x12C) {
            M2C_FIELD(state, int *, 8) = -0x12C;
        }
        Probe83264func_8004F178(M2C_FIELD(state, int *, 0xC) + 0xC, positionOrVector);
        M2C_FIELD(owner, unsigned char *, 0x45) = (unsigned char) (M2C_FIELD(owner, unsigned char *, 0x45) - (Probe83264D_8006C648 * 2));
        Probe83264SpawnParticle(1, 0xC, M2C_FIELD(state, int *, 0xC), 5);
        if ((Probe83264func_800359A4(state + 2, 2) == 0) && (M2C_FIELD(((M2C_FIELD(owner, unsigned char *, 0x3A) * 0x58) + Probe83264D_8006C550), unsigned char *, 0x49) != 0xA)) {
            return;
        }
        goto releaseOwner;
    case 2:
    case 3:
        if (M2C_FIELD(state, short *, 2) != 0) {
            if (Probe83264func_800359A4(state + 2, 2) != 0) {
                color2 = 0x30;
                M2C_FIELD(owner, unsigned char *, 0x4F) = color2;
                color2 = M2C_FIELD(owner, unsigned char *, 0x54);
                color3 = 13;
                M2C_FIELD(owner, unsigned char *, 0x57) = color3;
                color3 = M2C_FIELD(owner, unsigned char *, 0x56);
                color2 >>= 3;
                M2C_FIELD(owner, unsigned char *, 0x54) = color2;
                color2 = M2C_FIELD(owner, unsigned char *, 0x55);
                color3 >>= 3;
                M2C_FIELD(owner, unsigned char *, 0x56) = color3;
                color2 >>= 3;
                M2C_FIELD(owner, unsigned char *, 0x55) = color2;
            }
            linkedActor = Probe83264D_8006C550 + (M2C_FIELD(owner, unsigned char *, 0x3A) * 0x58);
            M2C_FIELD(owner, unsigned char *, 0x44) = (unsigned char) M2C_FIELD(linkedActor, unsigned char *, 0x44);
            M2C_FIELD(owner, unsigned char *, 0x45) = (unsigned char) M2C_FIELD(linkedActor, unsigned char *, 0x45);
            M2C_FIELD(owner, unsigned char *, 0x46) = (unsigned char) M2C_FIELD(linkedActor, unsigned char *, 0x46);
            Probe83264func_80055D24(owner, 4);
            frame.sp20 = 0x400;
            frame.sp24 = 0;
            frame.sp28 = 0;
            Probe83264func_8004ED6C(owner + 0x20, &frame.sp20, &frame.sp20);
            ownerPosition23 = owner + 0xC;
            Probe83264func_8004F194(ownerPosition23, linkedActor + 0xC, &frame.sp20);
            referenceBase = &Probe83264D_8006E020;
            M2C_FIELD(owner, unsigned char *, 0x45) = Probe83264func_8004E880(Probe83264func_8004F334(ownerPosition23, referenceBase), Probe83264D_8006E028 - M2C_FIELD(owner, int *, 0x14), 0);
            M2C_FIELD(owner, unsigned char *, 0x46) = Probe83264func_8004E880(*referenceBase - M2C_FIELD(owner, int *, 0xC), Probe83264D_8006E024 - M2C_FIELD(owner, int *, 0x10), 0);
            return;
        }
        goto releaseOwner;
    case 13:
        if (M2C_FIELD(state, int *, 4) == 0) {
            M2C_FIELD(state, int *, 4) = Probe83264func_80050844(owner + 0xC, 8, 0xA, 0x40C0C0);
            }
        frame.sp30 = 0x1B8;
        frame.sp34 = 0;
        frame.sp38 = 0;
        Probe83264func_8004ED6C(owner + 0x20, &frame.sp30, &frame.sp30);
        ownerPosition13 = owner + 0xC;
        Probe83264func_8004F194(ownerPosition13, ownerPosition13, &frame.sp30);
        if (Probe83264func_800359A4(state + 2, 2) != 0) {
            goto releaseHandle;
        }
        return;
    case 21:
        linkedActor21 = Probe83264D_8006C550 + (M2C_FIELD(owner, unsigned char *, 0x3A) * 0x58);
        M2C_FIELD(owner, unsigned char *, 0x44) = (unsigned char) M2C_FIELD(linkedActor21, unsigned char *, 0x44);
        M2C_FIELD(owner, unsigned char *, 0x45) = (unsigned char) M2C_FIELD(linkedActor21, unsigned char *, 0x45);
        M2C_FIELD(owner, unsigned char *, 0x46) = (unsigned char) M2C_FIELD(linkedActor21, unsigned char *, 0x46);
        Probe83264func_80055D24(owner, 4);
        frame.sp40 = 0x9C4;
        frame.sp44 = 0;
        frame.sp48 = 0;
        Probe83264func_8004ED6C(owner + 0x20, &frame.sp40, &frame.sp40);
        Probe83264func_8004F194(owner + 0xC, linkedActor21 + 0xC, &frame.sp40);
        M2C_FIELD(owner, unsigned char *, 0x4F) = (unsigned char) (M2C_FIELD(owner, unsigned char *, 0x4F) + (Probe83264D_8006C648 * 4));
        if (Probe83264func_800359A4(state + 2, 2) != 0) {
            goto releaseOwner;
        }
        break;
    case 20:
        ownerPosition = owner + 0xC;
        if (M2C_FIELD(owner, unsigned char *, 0x49) != 0xC) {
            goto case20_main;
        }
releaseHandle:
        handleWord = M2C_FIELD(state, int *, 4);
        if (handleWord != 0) {
            Probe83264func_800509E8(handleWord);
        }
releaseOwner:
        Probe83264func_80055B18(owner);
        return;
case20_main:
        linkedActor20 = Probe83264D_8006C550 + (M2C_FIELD(owner, unsigned char *, 0x3A) * 0x58);
        M2C_FIELD(owner, unsigned char *, 0x44) = (unsigned char) M2C_FIELD(linkedActor20, unsigned char *, 0x44);
        M2C_FIELD(owner, unsigned char *, 0x45) = (unsigned char) M2C_FIELD(linkedActor20, unsigned char *, 0x45);
        M2C_FIELD(owner, unsigned char *, 0x46) = (unsigned char) M2C_FIELD(linkedActor20, unsigned char *, 0x46);
        Probe83264func_8004F178(ownerPosition, linkedActor20 + 0xC);
        savedStateHalfword = M2C_FIELD(state, short *, 0);
        if (savedStateHalfword < 0x320) {
            savedWordArg4 = savedStateHalfword;
            __asm__("" : "=r"(savedWordArg4) : "0"(savedWordArg4));
            tickWord3 = Probe83264D_8006C648;
            workWord2 = savedWordArg4 + tickWord3 * 12;
            M2C_FIELD(state, short *, 0) = workWord2;
        }
        workWord2 = Probe83264D_8006C648;
        __asm__("" : "=r"(workWord2) : "0"(workWord2));
        phaseWord3 = M2C_FIELD(state, unsigned short *, 2);
        phaseWord3 += workWord2;
        M2C_FIELD(state, short *, 2) = phaseWord3;
        stateByte49 = M2C_FIELD(owner, unsigned char *, 0x49);
        if (stateByte49 == 0xB) {
            Probe83264func_80055D24(owner, 4);
            matrix11 = owner + 0x20;
            frame.sp50 = 0x9C4;
            frame.sp54 = 0;
            frame.sp58 = 0;
            Probe83264func_8004ED6C(matrix11, &frame.sp50, &frame.sp50);
            Probe83264func_8004F194(ownerPosition, ownerPosition, &frame.sp50);
            M2C_FIELD(owner, unsigned char *, 0x46) = (unsigned char) (M2C_FIELD(owner, unsigned char *, 0x46) + (M2C_FIELD(state, short *, 2) * 8));
            Probe83264func_80055D24(owner, 4);
            helperArg4 = matrix11;
            positionOrVector = &frame.sp50;
            helperArg5 = positionOrVector;
            __asm__("" : "=r"(helperArg5) : "0"(helperArg5));
            helperArg6 = positionOrVector;
            __asm__("" : "=r"(helperArg4),"=r"(helperArg6) : "0"(helperArg4),"1"(helperArg6));
            frame.sp50 = (int) savedStateHalfword;
            __asm__("" : : : "memory");
            frame.sp54 = 0;
            goto vector_tail;
        } else if (stateByte49 == 0xA) {
            Probe83264func_80055D24(owner, 4);
            matrix10 = owner + 0x20;
            frame.sp50 = 0x9C4;
            frame.sp54 = 0;
            frame.sp58 = 0;
            Probe83264func_8004ED6C(matrix10, &frame.sp50, &frame.sp50);
            Probe83264func_8004F194(ownerPosition, ownerPosition, &frame.sp50);
            M2C_FIELD(owner, unsigned char *, 0x45) = (unsigned char) (M2C_FIELD(owner, unsigned char *, 0x45) + (M2C_FIELD(state, short *, 2) * 8));
            Probe83264func_80055D24(owner, 4);
            helperArg4 = matrix10;
            positionOrVector = &frame.sp50;
            helperArg5 = positionOrVector;
            __asm__("" : "=r"(helperArg5) : "0"(helperArg5));
            helperArg6 = positionOrVector;
            __asm__("" : "=r"(helperArg4),"=r"(helperArg6) : "0"(helperArg4),"1"(helperArg6));
            frame.sp50 = (int) savedStateHalfword;
            frame.sp54 = 0;
        } else {
            helperArg4 = owner;
            helperArg5 = (void *)4;
            __asm__("" : "=r"(helperArg4),"=r"(phaseWord3),"=r"(helperArg5) : "0"(helperArg4),"1"(phaseWord3),"2"(helperArg5));
            workWord2 = phaseWord3 << 16;
            phaseWord3 = M2C_FIELD(owner, unsigned char *, 0x44);
            workWord2 >>= 13;
            phaseWord3 += workWord2;
            M2C_FIELD(owner, unsigned char *, 0x44) = phaseWord3;
            Probe83264func_80055D24(helperArg4, helperArg5);
            helperArg4 = owner + 0x20;
            positionOrVector = &frame.sp50;
            helperArg5 = positionOrVector;
            __asm__("" : "=r"(helperArg5) : "0"(helperArg5));
            helperArg6 = positionOrVector;
            __asm__("" : "=r"(helperArg4),"=r"(helperArg6) : "0"(helperArg4),"1"(helperArg6));
            frame.sp50 = 0x9C4;
            frame.sp54 = (int) savedStateHalfword;
        }
vector_tail:
        frame.sp58 = 0;
        Probe83264func_8004ED6C(helperArg4, helperArg5, helperArg6);
        Probe83264func_8004F194(ownerPosition, ownerPosition, positionOrVector);
        if (M2C_FIELD(state, int *, 4) == 0) {
            M2C_FIELD(state, int *, 4) = Probe83264func_80050844(owner + 0xC, 8, 0xA, 0x40C0C0);
        }
    case 0:
    default:
        __asm__("" : : : "memory");
        return;
    }
}

#undef M2C_FIELD


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_47/moby/func_level_47_800838D4.s SHA256 c9b13914cba87a4c5e7311e4bef5214f9537f69aea96689d9898c5f1b504c29f. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p,t,o) (*(t)((unsigned char*)(p)+(o)))


int Sorceress838D4_func_80019138() __asm__("func_80019138"); /* extern */
int Sorceress838D4_func_8001A358() __asm__("func_8001A358");         /* extern */
void *Sorceress838D4_func_8001BA30() __asm__("func_8001BA30"); /* extern */
int Sorceress838D4_func_8001C288() __asm__("func_8001C288");    /* extern */
int Sorceress838D4_func_8004ED6C() __asm__("func_8004ED6C"); /* extern */
int Sorceress838D4_func_8004F168() __asm__("func_8004F168");                  /* extern */
int Sorceress838D4_func_8004F334() __asm__("func_8004F334");           /* extern */
int Sorceress838D4_func_80055B18() __asm__("func_80055B18");                      /* extern */
int Sorceress838D4_func_80055D24() __asm__("func_80055D24");             /* extern */
int Sorceress838D4_func_8005629C() __asm__("func_8005629C");                      /* extern */
extern unsigned char Sorceress838D4_D_800658A0 __asm__("D_800658A0");
extern unsigned char Sorceress838D4_D_80065920 __asm__("D_80065920");
extern int Sorceress838D4_D_8006C550 __asm__("D_8006C550");
extern int Sorceress838D4_D_8006C574 __asm__("D_8006C574");
extern int Sorceress838D4_D_8006C578 __asm__("D_8006C578");
extern unsigned char Sorceress838D4_D_80070328 __asm__("D_80070328");

Moby *Controller838D4Spawn() __asm__("func_800391E8");
/* Rev1 raw596 entry800839B4,421 words, SHA256
 * E3151914A9B1211BB479FB21D91C76E833E065A745170ABCED0FEC7990C9F4A5
 * provides the verified structural reuse lead; Rev0 resolves every word. */
void func_level_47_800838D4(Moby *inputOwner) {
    struct {Vector3D sp20;char pad_2c[4];Vector3D sp30;char pad_3c[4];int sp40;int sp44;int sp48;char pad_4c[4];} originalStack;

register Moby *owner __asm__("$18")=inputOwner;

    register Moby *fragment __asm__("$2");
    register Moby *spawnedChild __asm__("$4");
    register Vector3D * workingVector __asm__("$16");
    register Vector3D * ownerPosition __asm__("$16");
    int remainingCount;
    int fallingStep;
    register int fragmentCount16 __asm__("$16");
    register int childCount16 __asm__("$16");
    register int contact17 __asm__("$17");
    register int childAngle17 __asm__("$17");
    register int queryOrSavedConstant20 __asm__("$20");
    register signed char *particleState1 __asm__("$4");
    register signed char *particleOtherState __asm__("$3");
    register int state __asm__("$3");
    register int linkedMobyIndex __asm__("$3");
    register void *collisionResult __asm__("$4");
    register void * privateData __asm__("$19");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register int childState17 __asm__("$17");
    register int childSize19 __asm__("$19");
    register int spawn200 __asm__("$21");
    register int gate22 __asm__("$22");
    register Vector3D *privateVector __asm__("$17");

    __asm__("" : "=r"(owner):"0"(owner));
    queryOrSavedConstant20 = 0;
    state = owner->state;
    privateData = owner->mobyTag;
    contact17 = 0;
    if (state != 2) {
        if (state == 1) {
            originalStack.sp40 = 0;
            originalStack.sp44 = 0x96;
            originalStack.sp48 = 0;
            if (M2C_FIELD(privateData, int *, 0) == (queryOrSavedConstant20=5)) {
                originalStack.sp44 = 0x2BC;
            }
            Sorceress838D4_func_80055D24(owner, 4);
            argument4=(int)&owner->rotationMatrix;
            __asm__("" : "=r"(argument4):"0"(argument4));
            privateVector = (Vector3D *)&originalStack.sp40;
            Sorceress838D4_func_8004ED6C(argument4, privateVector, privateVector);
            workingVector = &owner->position;
            func_8004F194(workingVector, workingVector, privateVector);
            originalStack.sp40 = 0;
            originalStack.sp44 = 0;
            value3=M2C_FIELD(privateData,int*,0);
            value3=queryOrSavedConstant20-value3;
            originalStack.sp48 = -(value3*6);
            particleState1 = SpawnParticle(1, 0xD, workingVector, privateVector);
            if (particleState1 != 0) {
                value2=M2C_FIELD(privateData,int*,0);
                value2=queryOrSavedConstant20-value2;
                value3=value2*22;
                value2=120;
                value2-=value3;
                M2C_FIELD(particleState1,unsigned char*,10)=value2;
            }
            remainingCount = M2C_FIELD(privateData, int *, 0) - 1;
            M2C_FIELD(privateData, int *, 0) = remainingCount;
            if (remainingCount > 0) goto done;
            goto releaseOwner;
        } else {
            func_8004F178(&originalStack.sp20, &owner->position);
            value2=func_800363DC(0,100);
            value3=originalStack.sp20.x - 50;
            __asm__("" : "=r"(value3):"0"(value3));
            value3+=value2;
            originalStack.sp20.x=value3;
            value2=func_800363DC(0,100);
            value3=originalStack.sp20.y - 50;
            __asm__("" : "=r"(value3):"0"(value3));
            value3+=value2;
            originalStack.sp20.y=value3;
            value2=func_800363DC(0,100);
            value3=originalStack.sp20.z - 50;
            __asm__("" : "=r"(value3):"0"(value3));
            value3+=value2;
            originalStack.sp20.z=value3;
            workingVector=&originalStack.sp30;
            Sorceress838D4_func_8004F168(workingVector);
            particleOtherState = SpawnParticle(1, 0xD, &originalStack.sp20, workingVector);
            if (particleOtherState != 0) {
                M2C_FIELD(particleOtherState, signed char *, 0xA) = 0xA;
            }
            func_80035DDC(owner, 0x12C, 0, 0, 0);
            if (M2C_FIELD(privateData, int *, 8) != 0) {
                owner->position.z += M2C_FIELD(privateData, int *, 4);
                fallingStep = M2C_FIELD(privateData, int *, 4) - 0x10;
                M2C_FIELD(privateData, int *, 4) = fallingStep;
                if (fallingStep < -0x190) {
                    M2C_FIELD(privateData, int *, 4) = -0x190;
                }
            }
            owner->unknown |= 0x80000000;
            Sorceress838D4_func_8001A358(&owner->position, 0x2000);
            Sorceress838D4_func_8005629C(owner);
            Sorceress838D4_func_80055D24(owner, 2);
            if ((owner->position.x < 0x400) || (owner->position.y < 0x400) || (owner->position.z < 0x400) || (func_800359A4(privateData, 4) != 0)) {
                contact17 = 1;
            }
            collisionResult = Sorceress838D4_func_8001BA30(&owner->position, 0xC8, 3, 0, 0, owner);
            if ((contact17 == 0) && (collisionResult != 0) && (M2C_FIELD(collisionResult, short *, 0x36) != 0x254)) {
                M2C_FIELD(collisionResult, int *, 0x18) = 0x100000;
                contact17 = 1;
                M2C_FIELD(collisionResult, unsigned char *, 0x51) = (unsigned char) owner->angle.yaw;
                owner->position.z = M2C_FIELD(collisionResult, int *, 0x14);
            } else if ((M2C_FIELD(privateData, int *, 0xC) != 0) && (Sorceress838D4_func_8001C288(&owner->position, 8, 7) != 0)) {
                value2=0x10000000;
                value3=owner->angle.yaw;
                __asm__("" : "=r"(value2),"=r"(value3):"0"(value2),"1"(value3));
                value2 |= 0x400;
                M2C_FIELD(&Sorceress838D4_D_80070328,int*,0x20C)=value2;
                M2C_FIELD(&Sorceress838D4_D_80070328,int*,0x298)=value3;
                value2=owner->angle.yaw*2;
                value3=M2C_FIELD(&Sorceress838D4_D_80065920,short*,value2);
                __asm__("" : "=r"(value3):"0"(value3));
                value2=(value3*25)>>11;
                M2C_FIELD(&Sorceress838D4_D_80070328,int*,0x21C)=value2;
                value2=owner->angle.yaw*2;
                value3=M2C_FIELD(&Sorceress838D4_D_800658A0,short*,value2);
                __asm__("" : "=r"(value3):"0"(value3):"$17");
                contact17=1;
                M2C_FIELD(&Sorceress838D4_D_80070328,int*,0x224)=0;
                __asm__ volatile("" : "=r"(value3),"=r"(contact17):"0"(value3),"1"(contact17):"memory");
                value2=(value3*25)>>11;
                M2C_FIELD(&Sorceress838D4_D_80070328,int*,0x220)=value2;
            }
            argument4=(int)&originalStack.sp20;
            __asm__("" : "=r"(argument4):"0"(argument4));
            ownerPosition = &owner->position;
            func_8004F178(argument4, ownerPosition);
            originalStack.sp20.z += 0x80;
            if ((contact17 != 0) || (queryOrSavedConstant20 = ({argument4=(int)&originalStack.sp20; __asm__("" : "=r"(argument4),"=r"(contact17):"0"(argument4),"1"(contact17)); Sorceress838D4_func_80019138(argument4, 0xFA, 1, 0, 0, 0);}), (queryOrSavedConstant20 != 0))) {
                argument4=(int)owner;argument5=0;
                __asm__("" : "=r"(argument4),"=r"(argument5):"0"(argument4),"1"(argument5));
                argument6=0;
                __asm__("" : "=r"(argument6):"0"(argument6));
                gate22=0;
                func_8003BABC(argument4, argument5, argument6);
                __asm__("" : "=r"(gate22):"0"(gate22));
                if (queryOrSavedConstant20 != 0) {
                    if (Sorceress838D4_func_8004F334(ownerPosition, &Sorceress838D4_D_80070328) < 0x7D0) {
                        value3=0x10000000;
                        value2=7;
                        M2C_FIELD(&Sorceress838D4_D_80070328,int*,0x24)=value2;
                        value2=owner->angle.yaw;
                        __asm__("" : "=r"(value2),"=r"(value3):"0"(value2),"1"(value3));
                        value3 |= 0x400;
                        M2C_FIELD(&Sorceress838D4_D_80070328,int*,0x20C)=value3;
                        M2C_FIELD(&Sorceress838D4_D_80070328,int*,0x298)=value2;
                        value2=owner->angle.yaw*2;
                        value3=M2C_FIELD(&Sorceress838D4_D_80065920,short*,value2);
                        __asm__("" : "=r"(value3):"0"(value3));
                        value2=(value3*15)>>11;
                        M2C_FIELD(&Sorceress838D4_D_80070328,int*,0x21C)=value2;
                        value2=owner->angle.yaw*2;
                        value3=M2C_FIELD(&Sorceress838D4_D_800658A0,short*,value2);
                        __asm__("" : "=r"(value3):"0"(value3));
                        M2C_FIELD(&Sorceress838D4_D_80070328,int*,0x224)=0;
                        __asm__ volatile("" : "=r"(value3):"0"(value3):"memory");
                        value2=(value3*15)>>11;
                        M2C_FIELD(&Sorceress838D4_D_80070328,int*,0x220)=value2;
                    }
                    linkedMobyIndex = owner->linkedMoby;
                    __asm__("" : "=r"(linkedMobyIndex):"0"(linkedMobyIndex));
                    if ((linkedMobyIndex != 0xFF) && (M2C_FIELD(((linkedMobyIndex * 0x58) + Sorceress838D4_D_8006C550), short *, 0x36) == 0x253)) {
                        Sorceress838D4_func_8001BA30(ownerPosition, 0x200, 3, 0, 0x100000, owner);
                    }
                }
                fragmentCount16 = 0;
                childState17=2;spawn200=200;queryOrSavedConstant20=256;childSize19=28;
                do {
                    fragment = Controller838D4Spawn(1, 0x54, owner, 0, childState17, spawn200, queryOrSavedConstant20);
                    if (fragment != 0) {
                        fragment->state = childState17;
                        fragment->size = childSize19;
                    }
                    fragmentCount16 += 1;
                } while (fragmentCount16 < 5);
                if (gate22 == 0) {
                    __asm__("" : "=r"(gate22):"0"(gate22));
                    argument6=0;
                    __asm__("" : "=r"(argument6):"0"(argument6));
                    childCount16 = 0;
                    owner->angle.yaw = func_8004E880(M2C_FIELD(&Sorceress838D4_D_80070328, int *, 0) - owner->position.x, M2C_FIELD(&Sorceress838D4_D_80070328, int *, 4) - owner->position.y, argument6);
                    childAngle17 = func_8003636C(0, 0x7F);
spawnChildLoop:
                    if ((Sorceress838D4_D_8006C578 - Sorceress838D4_D_8006C574) >= 0x15) {
                        spawnedChild = SpawnMoby(0x254, owner);
                        __asm__("" : "=r"(spawnedChild):"0"(spawnedChild));
                        if (spawnedChild != 0) {
                            spawnedChild->unknown3[0] = 0;
                            spawnedChild->lowDrawDistance = 0;
                            spawnedChild->drawn = 0;
                            value3=owner->angle.yaw;
                            value2=1;
                            spawnedChild->state = value2;
                            spawnedChild->angle.yaw = value3;
                            __asm__ volatile("" : : : "memory");
                            value3=(int)spawnedChild->mobyTag;
                            value2=5;
                            spawnedChild->angle.roll = (unsigned char) childAngle17;
                            spawnedChild->unknownCollision = 0;
                            M2C_FIELD((void*)value3,int*,0)=value2;
                        }
                        childCount16 += 1;
                        childAngle17 += 0x33;
                        if (childCount16 >= 5) {

                        } else {
                            goto spawnChildLoop;
                        }
                    }
                }
                SpawnParticle(0xA, 0x46, &owner->position, (Vector3D *)0x10);
releaseOwner:
                Sorceress838D4_func_80055B18(owner);
            }
        }
    }
done:;
}
#undef M2C_FIELD


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-derived C. Original source asm/nonmatchings/overlays/level_47/moby/func_level_47_80083F68.s SHA256 9d9a2ea49b2ff0bdd40454e40d91b2fd1e7b25d7479d8247e9769816201d4052. Original6080 verifies the common Super Bonus raw751 routes plus the Sorceress-only radius1500 and signed quotient gate. Rev1 raw751 entry0x80084048,564 words,SHA256 2A36299BB31DE9CB8E37078D68CF02D7A09C3429C16E2E6FAEC98FC73415174C is recorded by tools/yotd_re/playable_sorceress_raw751_crosswalk_runtime.py. Arithmetic is signed32 with original wrap/truncation and division traps; fields retain original widths. Confidence: exact native source identity; cadence per invocation only. Global producers, helper/callback contracts, child lifetime, units/fixed point and synchronized retail captures remain unresolved. No whole-encounter or runtime parity claim. Exact native/linked/full retail hashes required. */
#define SorceressField(p,t,o) (*(t)((unsigned char*)(p)+(o)))


int Sorceress751_func_8001830C() __asm__("func_8001830C"); 
int Sorceress751_func_80019138() __asm__("func_80019138"); 
void *Sorceress751_func_8001AD60() __asm__("func_8001AD60"); 
void *Sorceress751_func_8001BA30() __asm__("func_8001BA30"); 
int Sorceress751_func_8001C288() __asm__("func_8001C288");    
int Sorceress751_func_8004ED6C() __asm__("func_8004ED6C"); 
int Sorceress751_func_8004F168() __asm__("func_8004F168");                  
int Sorceress751_func_80055B18() __asm__("func_80055B18");                      
int Sorceress751_func_80055D24() __asm__("func_80055D24");             
int Sorceress751_rand() __asm__("rand");                            
extern unsigned char Sorceress751_D_800658A0 __asm__("D_800658A0");
extern unsigned char Sorceress751_D_80065920 __asm__("D_80065920");
extern int Sorceress751_D_8006C550 __asm__("D_8006C550");
extern int Sorceress751_D_8006C648 __asm__("D_8006C648");
extern int Sorceress751_D_8006E020 __asm__("D_8006E020");
extern int Sorceress751_D_8006E024 __asm__("D_8006E024");
extern int Sorceress751_D_80071920 __asm__("D_80071920");
extern int Sorceress751_D_80071918 __asm__("D_80071918");
extern int Sorceress751_D_8007191C __asm__("D_8007191C");
extern int Sorceress751_D_80071908 __asm__("D_80071908");
extern Moby *(*Sorceress751MobyCallback)() __asm__("SpawnMoby");
extern unsigned char Sorceress751_D_80070328 __asm__("D_80070328");

extern signed char *(*Sorceress751ParticleCallback)() __asm__("SpawnParticle");
void func_level_47_80083F68(Moby *inputMoby) {
    /* Raw stack offsets and field widths follow the original instructions.
     * Empty constraints preserve code generation without adding instructions. */
    struct {Vector3D sp18;char pad_24[4];Vector3D sp28;char pad_34[4];Vector3D sp38;char pad_44[4];int sp48;int sp4C;int sp50;char pad_54[4];Vector3D sp58;char pad_64[4];int sp68;int sp6C;int sp70;char pad_74[4];} originalStack;

Moby *moby=inputMoby;

    register Moby *previousChild4 __asm__("$4");
    register Moby * child18 __asm__("$18");
    register Moby *spawnedChild7 __asm__("$7");
    register Vector3D *position4 __asm__("$4");
    register Vector3D * position16 __asm__("$16");
    register Vector3D * queryPosition16 __asm__("$16");
    register Vector3D * transitionPosition16 __asm__("$16");
    register Vector3D * contactPosition16 __asm__("$16");
    register int randomOffset2 __asm__("$2");
    register int particleType5 __asm__("$5");
    register int queryResult18 __asm__("$18");
    register int particleIndex18 __asm__("$18");
    int contactFlag19;
    register signed char *firstParticle16 __asm__("$16");
    register signed char *loopParticle3 __asm__("$3");
    register signed char *lastParticle3 __asm__("$3");
    register int firstSize3 __asm__("$3");
    register int secondSize3 __asm__("$3");
    register int updatedSize2 __asm__("$2");
    register void * childData16 __asm__("$16");
    register void * privateData20 __asm__("$20");
    register void * childData21 __asm__("$21");
    register void *contact3 __asm__("$3");

    register int denominator4 __asm__("$4");
    register int gate5 __asm__("$5");
    register Moby *specialChild3 __asm__("$3");
    register void *specialData3 __asm__("$3");
    register Moby *(*factory3)() __asm__("$3");
    register int value2 __asm__("$2");
    register int value3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register int argument7 __asm__("$7");
    register signed char *(*particleCallback3)() __asm__("$3");
    register Vector3D *loopVector16 __asm__("$16");
    Vector3D *loopZeroVector19;
    register Vector3D *lastVector18 __asm__("$18");
    __asm__("" : "=r"(moby):"0"(moby));
    value2=moby->state;
    privateData20 = moby->mobyTag;
    if(value2==0) {
        __asm__("" : "=r"(value2):"0"(value2));
        contactFlag19 = 0;
        __asm__("" : "=r"(contactFlag19):"0"(contactFlag19));
        queryResult18 = 0;
        __asm__("" : "=r"(queryResult18):"0"(queryResult18));
        argument4=(int)&originalStack.sp28;
        __asm__("" : "=r"(argument4):"0"(argument4));
        position16=&moby->position;
        func_8004F178(argument4,position16);
        func_8004F178(&originalStack.sp18, position16);
        value2=func_8003636C(0,512);
        value3=originalStack.sp18.x;
        value3-=256;
        value3+=value2;
        originalStack.sp18.x=value3;
        value2=func_8003636C(0,512);
        value3=originalStack.sp18.y;
        value3-=256;
        value3+=value2;
        originalStack.sp18.y=value3;
        value2=func_8003636C(0,512);
        value3=originalStack.sp18.z;
        value3-=256;
        value3+=value2;
        originalStack.sp18.z=value3;
        firstParticle16 = SpawnParticle(1, 0x42, &originalStack.sp18, 0);
        argument4=(int)&moby->rotationMatrix;
        if (firstParticle16 != 0) {
            if (Sorceress751_rand(argument4) & 1) {
                value2=255;
                SorceressField(firstParticle16,unsigned char*,12)=value2;
                SorceressField(firstParticle16,unsigned char*,13)=value2;
                __asm__ volatile("" : : : "memory");
                value2=128;
            } else {
                value2=255;
                SorceressField(firstParticle16,unsigned char*,12)=value2;
                value2=128;
                SorceressField(firstParticle16,unsigned char*,13)=value2;
            }
            __asm__("" : : "r"(value2));
            SorceressField(firstParticle16,unsigned char*,14)=value2;
            argument4=(int)&moby->rotationMatrix;
        }
        moby->angle.roll += Sorceress751_D_8006C648 * 8;
        value2=SorceressField(privateData20,short*,2);
        originalStack.sp18.y=0;
        originalStack.sp18.z=0;
        originalStack.sp18.x=value2;
        Sorceress751_func_8004ED6C(argument4, &originalStack.sp18, &originalStack.sp18);
        position4 = &moby->position;
        func_8004F194(position4, position4, (Vector3D *) &originalStack.sp18);
        Sorceress751_func_80055D24(moby, 2);
        if (moby->substate == 1) {
            firstSize3 = moby->size;
            if (firstSize3 < 0x21U) {
                moby->size = func_8003636C(0, 8) + 0x38;
                return;
            }
            updatedSize2=firstSize3-8;
            moby->size=updatedSize2;
            return;
        }
        secondSize3 = moby->size;
        if (secondSize3 < 0x21U) {
            updatedSize2 = func_8003636C(0, 8) + 0x18;
        } else {
            updatedSize2 = secondSize3 - 8;
        }
        moby->size = updatedSize2;
        __asm__ volatile("" : : : "memory");
        queryPosition16 = &moby->position;
        contact3 = Sorceress751_func_8001BA30(queryPosition16, 0xC8, 3, 0, 0, Sorceress751_D_8006C550 + (moby->linkedMoby * 0x58));
        __asm__("" : "=r"(contact3):"0"(contact3));
        if ((contact3 != 0) || (contact3 = ({ __asm__("" : "=r"(contact3):"0"(contact3)); argument4=(int)&originalStack.sp28; argument5=(int)queryPosition16; __asm__("" : "=r"(argument4),"=r"(argument5):"0"(argument4),"1"(argument5)); argument6=0; __asm__("" : "=r"(argument6):"0"(argument6)); Sorceress751_func_8001AD60(argument4, argument5, argument6, 0, Sorceress751_D_8006C550 + (moby->linkedMoby * 0x58)); }), (contact3 != 0))) {
            contactFlag19 = 1;
            SorceressField(contact3, int *, 0x18) = 0x100000;
            SorceressField(contact3, unsigned char *, 0x51) = (unsigned char) moby->angle.yaw;
            func_8004F178(queryPosition16, &originalStack.sp28);
        } else if ((SorceressField(privateData20, int *, 4) != 0) && (Sorceress751_func_8001C288(queryPosition16, 0xC8, 7) != 0)) {
            value2=0x10000000;
            value3=moby->angle.yaw;
            __asm__("" : "=r"(value2),"=r"(value3):"0"(value2),"1"(value3));
            value2|=0x400;
            SorceressField(&Sorceress751_D_80070328,int*,0x20C)=value2;
            SorceressField(&Sorceress751_D_80070328,int*,0x298)=value3;
            value2=moby->angle.yaw;
            value3=SorceressField(&Sorceress751_D_80065920,signed short*,value2*2);
            SorceressField(&Sorceress751_D_80070328,int*,0x21C)=(value3*25)>>11;
            value2=moby->angle.yaw;
            value3=SorceressField(&Sorceress751_D_800658A0,signed short*,value2*2);
            __asm__("" : "=r"(value3),"=r"(contactFlag19):"0"(value3),"1"(contactFlag19));
            contactFlag19=1;
            SorceressField(&Sorceress751_D_80070328,int*,0x224)=0;
            __asm__ volatile("" : "=r"(value3):"0"(value3):"memory");
            SorceressField(&Sorceress751_D_80070328,int*,0x220)=(value3*25)>>11;
        }
        argument4=(int)&originalStack.sp18;
        __asm__("" : "=r"(argument4):"0"(argument4));
        transitionPosition16 = &moby->position;
        func_8004F178(argument4,transitionPosition16);
        originalStack.sp18.z += 0x80;
        __asm__("" : "=r"(contactFlag19):"0"(contactFlag19));
        if ((contactFlag19 != 0) || (moby->position.x < 0x400) || (moby->position.y < 0x400) || (moby->position.z < 0x400) || (func_800359A4(privateData20, 2) != 0) || (queryResult18 = ({ __asm__("" : "=r"(contactFlag19):"0"(contactFlag19)); Sorceress751_func_80019138(&originalStack.sp18, 0xFA, 1, 0, 0, Sorceress751_D_8006C550 + (moby->linkedMoby * 0x58)); }), (queryResult18 != 0)) || (queryResult18 = ({ __asm__("" : "=r"(queryResult18):"0"(queryResult18)); Sorceress751_func_8001830C(&originalStack.sp28, transitionPosition16, 3, 0, Sorceress751_D_8006C550 + (moby->linkedMoby * 0x58)); }), (queryResult18 != 0))) {
            previousChild4 = SorceressField(privateData20, Moby **, 8);
            if (previousChild4 != 0) {
                Sorceress751_func_80055B18(previousChild4);
                SorceressField(privateData20, Moby **, 8) = 0;
            }

            if (queryResult18 != 0) {
                Sorceress751_func_8001BA30(&moby->position, 1500, 3, 0, 0x100000, moby);
                denominator4=Sorceress751_D_80071920;gate5=0;
                if(denominator4>0){
                    value3=Sorceress751_D_80071918;value2=(value3*100)/denominator4;
                    if(value2<0){__asm__("" : "=r"(value2):"0"(value2));value2=-value2;}
                    if(value2<6){
                        value3=Sorceress751_D_8007191C;value2=(value3*100)/denominator4;
                        if(value2<0){__asm__("" : "=r"(value2):"0"(value2));value2=-value2;}
                        __asm__ volatile("" : "=r"(value2):"0"(value2));
                        gate5=value2<6;
                    }
                }
                if(gate5){
                    argument4=1000;value2=Sorceress751_D_80071908;factory3=Sorceress751MobyCallback;
                    __asm__("" : "=r"(argument4),"=r"(factory3),"=r"(value2):"0"(argument4),"1"(factory3),"2"(value2));
                    argument5=(int)moby;
                    moby->position.z=value2;specialChild3=factory3(argument4,argument5);
                    __asm__("" : "=r"(specialChild3):"0"(specialChild3));
                    if(specialChild3){
                        specialChild3->state=1;specialData3=specialChild3->mobyTag;
                        SorceressField(specialData3,short *,2)=400;SorceressField(specialData3,short *,20)=30;SorceressField(specialData3,short *,22)=80;
                    }
                    goto releaseParent;
                }
                func_8004F178(&moby->position, &originalStack.sp28);
            }
            moby->unknown3[0] = 0;
            moby->lowDrawDistance = 0;
            moby->drawn = 0;
            moby->state = 1;
            goto updateStateOne;
        }
    } else {
updateStateOne:
        if (moby->state == 1) {
            func_8003BABC(moby, 0, 0);
            moby->substate = 0x14;
            spawnedChild7 = SpawnMoby(0x3F7, moby);
            __asm__("" : "=r"(spawnedChild7):"0"(spawnedChild7));
            SorceressField(privateData20, Moby **, 8) = spawnedChild7;
            if (spawnedChild7 != 0) {
                argument6=0;
                __asm__("" : "=r"(argument6):"0"(argument6));
                particleIndex18 = 0;
                loopVector16=(Vector3D*)&originalStack.sp48;
                loopZeroVector19=&originalStack.sp38;
                spawnedChild7->unknown4 = 8;
                childData21 = spawnedChild7->mobyTag;
                moby->angle.yaw = func_8004E880(Sorceress751_D_8006E020 - moby->position.x, Sorceress751_D_8006E024 - moby->position.y, argument6);
                do {
                    moby->angle.roll = particleIndex18 << 5;
                    originalStack.sp48 = 0;
                    originalStack.sp4C = 0x4E2;
                    originalStack.sp50 = 0;
                    Sorceress751_func_80055D24(moby, 4);
                    Sorceress751_func_8004ED6C(&moby->rotationMatrix, loopVector16, loopVector16);
                    func_8004F194(loopVector16, &moby->position, loopVector16);
                    Sorceress751_func_8004F168(loopZeroVector19);
                    loopParticle3 = SpawnParticle(1, 0xD, loopVector16, loopZeroVector19);
                    if (loopParticle3 != 0) {
                        SorceressField(loopParticle3, signed char *, 0xA) = 0x3C;
                    }
                    particleIndex18 += 1;
                } while (particleIndex18 < 8);
                __asm__ volatile("" : "=r"(moby):"0"(moby));
                argument4=16;
                argument5=70;
                argument6=(int)&moby->position;
                argument7=32;
                __asm__("" : "=r"(argument4),"=r"(argument5),"=r"(argument6),"=r"(argument7):"0"(argument4),"1"(argument5),"2"(argument6),"3"(argument7));
                SorceressField(childData21,short*,2)=400;
                moby->state=2;
                particleCallback3=Sorceress751ParticleCallback;
                __asm__("" : "=r"(particleCallback3):"0"(particleCallback3));
                value2=90;
                moby->unknownCollision=0;
                SorceressField(privateData20,short*,0)=value2;
                particleCallback3(argument4,argument5,argument6,argument7);
                goto updateStateTwo;
            }
        } else {
updateStateTwo:
            if (moby->state == 2) {
                child18 = SorceressField(privateData20, Moby **, 8);
                childData16 = child18->mobyTag;
                value3=10;
                value2=moby->substate;
                if ((value2 == value3) || (func_800359A4(privateData20, 2) != 0)) {
releaseParent:
                    Sorceress751_func_80055B18(moby);
                    return;
                }
                child18->angle.yaw = func_8004E880(Sorceress751_D_8006E020 - moby->position.x, Sorceress751_D_8006E024 - moby->position.y, 0);
                if (SorceressField(childData16, short *, 0x14) < 3) {
                    SorceressField(childData16, unsigned short *, 0) = (unsigned short) (SorceressField(childData16, unsigned short *, 0) + 0x32);
                }
                if (SorceressField(childData16, short *, 0x14) < 4) {
                    SorceressField(childData16, unsigned short *, 0x16) = (unsigned short) (SorceressField(childData16, unsigned short *, 0x16) + 0x32);
                }
                SorceressField(childData16, unsigned short *, 2) = (unsigned short) (SorceressField(childData16, unsigned short *, 2) + 0x64);
                if (SorceressField(childData16, short *, 0x14) < 7) {
                    lastVector18=&originalStack.sp58;
                    func_8004F178(lastVector18,&moby->position);
                    value2=func_8003636C(0,200);
                    value3=originalStack.sp58.x;
                    value3-=100;
                    value3+=value2;
                    originalStack.sp58.x=value3;
                    value2=func_8003636C(0,200);
                    value3=originalStack.sp58.y;
                    value3-=100;
                    value3+=value2;
                    originalStack.sp58.y=value3;
                    originalStack.sp58.z += 0xC8;
                    randomOffset2 = func_8003636C(0, 0xC8);
                    originalStack.sp68 = 0;
                    originalStack.sp6C = 0;
                    originalStack.sp70 = 0;
                    value3=originalStack.sp58.z;
                    value3-=100;
                    value3+=randomOffset2;
                    originalStack.sp58.z=value3;
                    value2=SorceressField(childData16,short*,20);
                    argument4=1;
                    if(value2<4) {
                        particleType5=0;
                    } else {
                        particleType5=13;
                        __asm__ volatile("" : "=r"(particleType5):"0"(particleType5));
                    }
                    lastParticle3 = SpawnParticle(argument4, particleType5, lastVector18, (Vector3D *) &originalStack.sp68);
                    if (lastParticle3 != 0) {
                        SorceressField(lastParticle3, signed char *, 0xA) = 0x64;
                    }
                }
            }
        }
    }
}
#undef SorceressField

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original 80084838.
 * AI generated; not human reviewed. Every 573 original native/linked word
 * and actual branch,call and internal target must match. No owned selector,
 * padding or packed-data words occur. FrameD0 retains SP18..A7 local extent
 * and S0..S7/FP/RA at SPA8..CC. Unwritten reserve contents are never read.
 * Nine initialized caller slots SP80..A0 retain the original complete values.
 * Natural FP retains the original first COS address and later SIN projection;
 * no fixed FP/SP binding or overlapping live fixed-register aliases occurs.
 * Every signed MULT consumes both complete original signed32 operands in a
 * signed64 C product. Empty metadata observes its complete HILO result's low
 * or high signed32 word; narrowing precedes each original signed shift12.
 * Initialized producer/argument identities preserve original load,product,
 * callback,spill and delay-slot cadence. Every template emits zero CPU words.
 * Geometry loops retain16*6 points; topology loops retain15*6 records and
 * original /3,/6,/90 high-word corrections,signs,byte offsets and sentinels.
 * Original clamp2500 and particle thirdvector0 are distinct target words.
 * Natural literal fifth argument1 preserves each SW/SP10,JAL,ADDIU/A3 delay.
 * Raw arithmetic:32767*900=29490300; signedSRA12 yields7199. Signed -10/3
 * truncates toward zero to-3. Geometry scalar domains,physical units,full
 * helper/caller contracts,cadence beyond invocation,Rev1 mapping and retail
 * runtime remain open. Confidence is binary identity after all source/data
 * and complete EXE/every-overlay hashes. Next:human review and synchronized
 * retail capture. Compiler,filter,flags and acceptance gates are unchanged.
 */
/* Original assembly SHA256 43c3de06384a4d65922ec7c82914e9e6b7223948dc30740d486bb1898fcff3a6 */
#define Level47_84838Low(a,b) ({long long completeSignedProduct=(long long)(int)(a)*(long long)(int)(b);int lowWord;__asm__("":"=l"(lowWord):"x"(completeSignedProduct));lowWord;})
#define Level47_84838F(p,t,o) (*(t)((unsigned char*)(p)+(o)))
#define Level47_84838W(p,o) Level47_84838F(p,int*,o)
#define Level47_84838P(p,o) Level47_84838F(p,unsigned char**,o)
#define Level47_84838B(p,o) Level47_84838F(p,unsigned char*,o)
#define Level47_84838H(p,o) Level47_84838F(p,short*,o)
#define Level47_84838U(p,o) Level47_84838F(p,unsigned short*,o)
#define Level47_84838Owner() ({phasePointerOrLowWord24=originalFrame.owner;Level47_84838KEEP(phasePointerOrLowWord24);phasePointerOrLowWord24;})
#define Level47_84838KEEP(v) __asm__("" : "=r"(v):"0"(v))
extern short Level47_84838Cos[] __asm__("D_80065920"),Level47_84838Sin[] __asm__("D_800658A0");
extern int Level47_84838Counter __asm__("D_8006C640");
extern char* (*Level47_84838Particle)(int,int,void*,void*) __asm__("SpawnParticle");
void Level47_84838H4F194_4(void*,void*,void*) __asm__("func_8004F194");
void* Level47_84838H50B00_5(int,int,int,int,int) __asm__("func_80050B00");
void Level47_84838H4F194_6(void*,void*,void*) __asm__("func_8004F194");
void* Level47_84838H50B00_7(int,int,int,int,int) __asm__("func_80050B00");
void Level47_84838H50B88_8(void*) __asm__("func_80050B88");
void Level47_84838H50B88_9(void*) __asm__("func_80050B88");
void Level47_84838H55B18_10(void*) __asm__("func_80055B18");
void func_level_47_80084838(unsigned char* ownerParameter){
    struct {
        int first[4],second[4];
        unsigned char* owner;
        int pad3C;
        unsigned char* private;
        int pad44;
        unsigned char* parent;
        int pad4C;
        int size,pad54;
        unsigned char* base;
        int pad5C;
        unsigned char* header;
        int pad64;
        unsigned char* table;
        int pad6C;
        short* sin;
        int pad74;
        int heading,pad7C;
        int spill[9],padA4;
    }
    originalFrame;
    register int cosOffset23 __asm__("$23");
    register unsigned char* phasePointerOrLowWord24 __asm__("$24");
    register unsigned char* pointRecord16 __asm__("$16");
    register int innerIndex17 __asm__("$17");
    register int angleOrCosAddress18 __asm__("$18");
    register int radiusOrSinAddress19 __asm__("$19");
    register int baseIndexOrRadius20 __asm__("$20");
    register int outerIndex21 __asm__("$21");
    register int sinOffsetOrBaseIndex22 __asm__("$22");
    int cosAddressOrSinOffset;
    register int resultOrField2 __asm__("$2"),sampleOrField3 __asm__("$3");
    register int argumentOrAngle4 __asm__("$4"),argumentOrLowWord5 __asm__("$5"),argumentOrLowWord6 __asm__("$6"),argumentOrVerticalOffset7 __asm__("$7");
    register int cosAddressMagicOrHigh8 __asm__("$8"),sinAddressMagicOrHigh9 __asm__("$9"),phaseIndexOrHigh10 __asm__("$10"),topologyLiteral11 __asm__("$11");
    register unsigned char* headerRecord12 __asm__("$12");
    register short* sinTable11 __asm__("$11"),*cosTableOrMagic13 __asm__("$13");
    register unsigned char* pointBase14 __asm__("$14");
    register unsigned char* topologyBase15 __asm__("$15");
    long long completeSignedProduct;
    int signedHighWord,signedLowWord;
    originalFrame.owner=ownerParameter;
    phasePointerOrLowWord24=Level47_84838P(ownerParameter,0);
    originalFrame.private=phasePointerOrLowWord24;
    resultOrField2=Level47_84838W(phasePointerOrLowWord24,16);
    resultOrField2=Level47_84838W(resultOrField2,0);
    originalFrame.parent=(unsigned char*)resultOrField2;
    Level47_84838B(ownerParameter,0x41)=0;
    phasePointerOrLowWord24=originalFrame.owner;
    sampleOrField3=Level47_84838B(phasePointerOrLowWord24,0x48);
    resultOrField2=1;
    Level47_84838B(phasePointerOrLowWord24,0x4C)=0;
    Level47_84838B(phasePointerOrLowWord24,0x4D)=0;
    if(sampleOrField3==resultOrField2){
        phasePointerOrLowWord24=originalFrame.private;
        resultOrField2=Level47_84838U(phasePointerOrLowWord24,0)+300;
        Level47_84838U(phasePointerOrLowWord24,0)=resultOrField2;
        resultOrField2=(short)resultOrField2;
        if(resultOrField2>2500){
            resultOrField2=2500;
            Level47_84838U(phasePointerOrLowWord24,0)=resultOrField2;
            phasePointerOrLowWord24=originalFrame.owner;
            resultOrField2=2;
            Level47_84838B(phasePointerOrLowWord24,0x48)=resultOrField2;
        }
    }
    phasePointerOrLowWord24=originalFrame.private;
    originalFrame.heading=0;
    originalFrame.base=({ phasePointerOrLowWord24=Level47_84838P(phasePointerOrLowWord24,4); Level47_84838KEEP(phasePointerOrLowWord24); phasePointerOrLowWord24; });
    phasePointerOrLowWord24=originalFrame.private;
    originalFrame.size=({ phasePointerOrLowWord24=(unsigned char *)(int)Level47_84838H(phasePointerOrLowWord24,0); Level47_84838KEEP(phasePointerOrLowWord24); (int)phasePointerOrLowWord24; });
    phasePointerOrLowWord24=originalFrame.base;
    outerIndex21=0;
    phasePointerOrLowWord24+=0x43C;
    originalFrame.header=phasePointerOrLowWord24;
    phasePointerOrLowWord24=originalFrame.base;
    baseIndexOrRadius20=0;
    phasePointerOrLowWord24+=0x47C;
    originalFrame.table=phasePointerOrLowWord24;
    do{
        argumentOrAngle4=Level47_84838B(Level47_84838Owner(),0x46);
        Level47_84838KEEP(argumentOrAngle4);
        phasePointerOrLowWord24=(unsigned char*)originalFrame.heading;
        argumentOrAngle4+=(int)phasePointerOrLowWord24;
        sampleOrField3=(argumentOrAngle4&255)<<1;
        __asm__ volatile(""::"r"(sampleOrField3):"$24");
        phasePointerOrLowWord24=(unsigned char*)Level47_84838Cos;
        Level47_84838KEEP(phasePointerOrLowWord24);
        resultOrField2=sampleOrField3+(int)phasePointerOrLowWord24;
        Level47_84838KEEP(resultOrField2);
        resultOrField2=*(short*)resultOrField2;
        phasePointerOrLowWord24=(unsigned char*)originalFrame.size;
        Level47_84838KEEP(phasePointerOrLowWord24);
        completeSignedProduct=(long long)resultOrField2*(long long)(int)phasePointerOrLowWord24;
        __asm__ volatile(""::"x"(completeSignedProduct));
        innerIndex17=0;
        __asm__("":"=r"(innerIndex17):"0"(innerIndex17):"$24");
        phasePointerOrLowWord24=(unsigned char*)Level47_84838Sin;
        Level47_84838KEEP(phasePointerOrLowWord24);
        sampleOrField3=sampleOrField3+(int)phasePointerOrLowWord24;
        Level47_84838KEEP(sampleOrField3);
        resultOrField2=*(short*)sampleOrField3;
        __asm__("":"=l"(signedLowWord):"x"(completeSignedProduct),"r"(resultOrField2));
        argumentOrLowWord5=signedLowWord;
        Level47_84838KEEP(argumentOrLowWord5);
        phasePointerOrLowWord24=(unsigned char*)originalFrame.size;
        Level47_84838KEEP(phasePointerOrLowWord24);
        angleOrCosAddress18=0;
        __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(argumentOrLowWord5));
        completeSignedProduct=(long long)resultOrField2*(long long)(int)phasePointerOrLowWord24;
        __asm__ volatile(""::"x"(completeSignedProduct));
        argumentOrAngle4=((argumentOrAngle4+64)&255)<<1;
        phasePointerOrLowWord24=originalFrame.private;
        cosOffset23=argumentOrLowWord5>>12;
        radiusOrSinAddress19=Level47_84838H(phasePointerOrLowWord24,2);
        phasePointerOrLowWord24=(unsigned char*)Level47_84838Sin;
        Level47_84838KEEP(phasePointerOrLowWord24);
        phasePointerOrLowWord24=(unsigned char*)(argumentOrAngle4+(int)phasePointerOrLowWord24);
        originalFrame.sin=(short*)phasePointerOrLowWord24;
        phasePointerOrLowWord24=(unsigned char*)Level47_84838Cos;
        Level47_84838KEEP(phasePointerOrLowWord24);
        cosAddressOrSinOffset=argumentOrAngle4+(int)phasePointerOrLowWord24;
        __asm__("":"=l"(signedLowWord):"x"(completeSignedProduct),"r"(cosAddressOrSinOffset));
        sampleOrField3=signedLowWord;
        Level47_84838KEEP(sampleOrField3);
        sinOffsetOrBaseIndex22=sampleOrField3>>12;
        do{
            sampleOrField3=(angleOrCosAddress18&255)<<1;
            phasePointerOrLowWord24=(unsigned char*)Level47_84838Cos;
            Level47_84838KEEP(phasePointerOrLowWord24);
            resultOrField2=sampleOrField3+(int)phasePointerOrLowWord24;
            originalFrame.first[0]=0;
            __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"m"(originalFrame.first[0]));
            resultOrField2=*(short*)resultOrField2;
            phasePointerOrLowWord24=(unsigned char*)Level47_84838Low(resultOrField2,radiusOrSinAddress19);
            Level47_84838KEEP(phasePointerOrLowWord24);
            argumentOrAngle4=(int)phasePointerOrLowWord24>>12;
            originalFrame.first[1]=argumentOrAngle4;
            phasePointerOrLowWord24=(unsigned char*)Level47_84838Sin;
            Level47_84838KEEP(phasePointerOrLowWord24);
            sampleOrField3=sampleOrField3+(int)phasePointerOrLowWord24;
            Level47_84838KEEP(sampleOrField3);
            resultOrField2=*(short*)sampleOrField3;
            phasePointerOrLowWord24=(unsigned char*)Level47_84838Low(resultOrField2,radiusOrSinAddress19);
            Level47_84838KEEP(phasePointerOrLowWord24);
            resultOrField2=(int)phasePointerOrLowWord24>>12;
            phasePointerOrLowWord24=(unsigned char*)originalFrame.sin;
            originalFrame.first[2]=resultOrField2;
            resultOrField2=*(short*)phasePointerOrLowWord24;
            completeSignedProduct=(long long)argumentOrAngle4*(long long)resultOrField2;
            __asm__ volatile(""::"x"(completeSignedProduct));
            sampleOrField3=baseIndexOrRadius20+innerIndex17;
            phasePointerOrLowWord24=originalFrame.base;
            __asm__("":"=r"(sampleOrField3):"0"(sampleOrField3),"r"(phasePointerOrLowWord24));
            resultOrField2=sampleOrField3*12;
            Level47_84838KEEP(resultOrField2);
            pointRecord16=phasePointerOrLowWord24+resultOrField2;
            Level47_84838KEEP(pointRecord16);
            __asm__("":"=l"(signedLowWord):"x"(completeSignedProduct),"r"(pointRecord16));
            phasePointerOrLowWord24=(unsigned char*)signedLowWord;
            Level47_84838KEEP(phasePointerOrLowWord24);
            resultOrField2=-(int)phasePointerOrLowWord24;
            resultOrField2>>=12;
            Level47_84838W(pointRecord16,0)=resultOrField2;
            sampleOrField3=*(short*)cosAddressOrSinOffset;
            resultOrField2=originalFrame.first[1];
            completeSignedProduct=(long long)resultOrField2*(long long)sampleOrField3;
            __asm__ volatile(""::"x"(completeSignedProduct));
            phasePointerOrLowWord24=originalFrame.owner;
            argumentOrAngle4=(int)pointRecord16;
            argumentOrLowWord5=(int)phasePointerOrLowWord24+12;
            __asm__("":"=l"(signedLowWord):"x"(completeSignedProduct),"r"(argumentOrAngle4),"r"(argumentOrLowWord5));
            phasePointerOrLowWord24=(unsigned char*)signedLowWord;
            Level47_84838KEEP(phasePointerOrLowWord24);
            resultOrField2=(int)phasePointerOrLowWord24>>12;
            Level47_84838W(pointRecord16,4)=resultOrField2;
            resultOrField2=originalFrame.first[2];
            argumentOrLowWord6=(int)pointRecord16;
            Level47_84838W(pointRecord16,8)=resultOrField2;
            Level47_84838H4F194_4(argumentOrAngle4,argumentOrLowWord5,argumentOrLowWord6);
            resultOrField2=Level47_84838W(pointRecord16,0);
            sampleOrField3=Level47_84838W(pointRecord16,4);
            resultOrField2+=cosOffset23;
            sampleOrField3+=sinOffsetOrBaseIndex22;
            Level47_84838W(pointRecord16,0)=resultOrField2;
            Level47_84838W(pointRecord16,4)=sampleOrField3;
            if(Level47_84838B(Level47_84838Owner(),0x48)==1&&!innerIndex17){
                argumentOrAngle4=1;
                Level47_84838KEEP(innerIndex17);
                argumentOrLowWord5=60;
                argumentOrLowWord6=(int)pointRecord16;
                resultOrField2=(int)Level47_84838Particle;
                __asm__ volatile(""::"r"(resultOrField2):"$7");
                argumentOrVerticalOffset7=(int)originalFrame.second;
                __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(argumentOrAngle4),"r"(argumentOrLowWord5),"r"(argumentOrLowWord6),"r"(argumentOrVerticalOffset7));
                originalFrame.second[0]=0;
                originalFrame.second[1]=0;
                originalFrame.second[2]=0;
                sampleOrField3=((char*(*)(int,int,void*,void*))resultOrField2)(argumentOrAngle4,argumentOrLowWord5,argumentOrLowWord6,argumentOrVerticalOffset7);
                if(sampleOrField3){
                    resultOrField2=40;
                    Level47_84838B(sampleOrField3,10)=resultOrField2;
                }
            }
            innerIndex17++;
            angleOrCosAddress18+=42;
        }
        while(innerIndex17<6);
        baseIndexOrRadius20+=6;
        outerIndex21++;
        phasePointerOrLowWord24=(unsigned char*)originalFrame.heading;
        resultOrField2=outerIndex21<16;
        phasePointerOrLowWord24+=17;
        originalFrame.heading=(int)phasePointerOrLowWord24;
    }
    while(resultOrField2);
    outerIndex21=0;
    sinAddressMagicOrHigh9=0x2AAAAAAB;
    Level47_84838KEEP(sinAddressMagicOrHigh9);
    cosAddressMagicOrHigh8=(int)0xB60B60B7;
    Level47_84838KEEP(cosAddressMagicOrHigh8);
    argumentOrVerticalOffset7=0;
    phasePointerOrLowWord24=originalFrame.base;
    Level47_84838W(phasePointerOrLowWord24,0x438)=-1;
    phasePointerOrLowWord24=originalFrame.header;
    Level47_84838B(phasePointerOrLowWord24,0)=25;
    Level47_84838B(phasePointerOrLowWord24,1)=25;
    Level47_84838B(phasePointerOrLowWord24,2)=50;
    do{
        innerIndex17=0;
        do{
            resultOrField2=innerIndex17+1;
            completeSignedProduct=(long long)resultOrField2*(long long)sinAddressMagicOrHigh9;
            __asm__ volatile(""::"x"(completeSignedProduct));
            sampleOrField3=argumentOrVerticalOffset7+innerIndex17;
            argumentOrLowWord6=innerIndex17+6;
            innerIndex17=resultOrField2;
            argumentOrLowWord5=sampleOrField3*8;
            argumentOrLowWord6=argumentOrVerticalOffset7+argumentOrLowWord6;
            phasePointerOrLowWord24=originalFrame.table;
            resultOrField2=innerIndex17>>31;
            argumentOrLowWord5=(int)phasePointerOrLowWord24+argumentOrLowWord5;
            __asm__("":"=h"(signedHighWord):"x"(completeSignedProduct),"r"(argumentOrLowWord5));
            phaseIndexOrHigh10=signedHighWord;
            Level47_84838KEEP(phaseIndexOrHigh10);
            Level47_84838B(argumentOrLowWord5,0)=sampleOrField3;
            Level47_84838B(argumentOrLowWord5,4)=0;
            __asm__("":"=r"(argumentOrLowWord6):"0"(argumentOrLowWord6),"r"(phaseIndexOrHigh10),"m"(Level47_84838B(argumentOrLowWord5,4)));
            completeSignedProduct=(long long)argumentOrLowWord6*(long long)cosAddressMagicOrHigh8;
            __asm__ volatile(""::"x"(completeSignedProduct));
            Level47_84838B(argumentOrLowWord5,5)=0;
            Level47_84838B(argumentOrLowWord5,6)=0;
            Level47_84838B(argumentOrLowWord5,7)=0;
            __asm__ volatile("":"=r"(resultOrField2):"0"(resultOrField2),"m"(Level47_84838B(argumentOrLowWord5,5)),"m"(Level47_84838B(argumentOrLowWord5,6)),"m"(Level47_84838B(argumentOrLowWord5,7)));
            resultOrField2=phaseIndexOrHigh10-resultOrField2;
            argumentOrAngle4=resultOrField2*6;
            argumentOrAngle4=innerIndex17-argumentOrAngle4;
            resultOrField2=argumentOrVerticalOffset7+argumentOrAngle4;
            argumentOrAngle4+=6;
            argumentOrAngle4=argumentOrVerticalOffset7+argumentOrAngle4;
            __asm__("":"=h"(signedHighWord):"x"(completeSignedProduct),"r"(argumentOrAngle4));
            sampleOrField3=signedHighWord;
            Level47_84838KEEP(sampleOrField3);
            Level47_84838B(argumentOrLowWord5,1)=resultOrField2;
            resultOrField2=sampleOrField3+argumentOrLowWord6;
            __asm__("":"=r"(argumentOrAngle4):"0"(argumentOrAngle4),"r"(sampleOrField3));
            completeSignedProduct=(long long)argumentOrAngle4*(long long)cosAddressMagicOrHigh8;
            __asm__ volatile(""::"x"(completeSignedProduct));
            resultOrField2>>=6;
            sampleOrField3=argumentOrLowWord6>>31;
            resultOrField2-=sampleOrField3;
            resultOrField2*=90;
            argumentOrLowWord6-=resultOrField2;
            sampleOrField3=argumentOrAngle4>>31;
            Level47_84838B(argumentOrLowWord5,2)=argumentOrLowWord6;
            __asm__("":"=h"(signedHighWord):"x"(completeSignedProduct),"m"(Level47_84838B(argumentOrLowWord5,2)));
            phaseIndexOrHigh10=signedHighWord;
            Level47_84838KEEP(phaseIndexOrHigh10);
            resultOrField2=phaseIndexOrHigh10+argumentOrAngle4;
            resultOrField2>>=6;
            resultOrField2-=sampleOrField3;
            resultOrField2*=90;
            argumentOrAngle4-=resultOrField2;
            Level47_84838B(argumentOrLowWord5,3)=argumentOrAngle4;
        }
        while(innerIndex17<6);
        outerIndex21++;
        argumentOrVerticalOffset7+=6;
    }
    while(outerIndex21<15);
    Level47_84838W(phasePointerOrLowWord24,0x2D0)=-1;
    phasePointerOrLowWord24=originalFrame.private;
    if(!Level47_84838W(phasePointerOrLowWord24,8)){
        argumentOrAngle4=(int)originalFrame.base;
        argumentOrLowWord5=(int)originalFrame.header;
        argumentOrLowWord6=(int)originalFrame.table;
        phasePointerOrLowWord24=originalFrame.parent;
        resultOrField2=Level47_84838H50B00_5(argumentOrAngle4,argumentOrLowWord5,argumentOrLowWord6,(int)phasePointerOrLowWord24+12,1);
        phasePointerOrLowWord24=originalFrame.private;
        Level47_84838W(phasePointerOrLowWord24,8)=resultOrField2;
    }
    outerIndex21=0;
    sinTable11=Level47_84838Sin;
    cosTableOrMagic13=Level47_84838Cos;
    phasePointerOrLowWord24=originalFrame.private;
    sinOffsetOrBaseIndex22=0;
    resultOrField2=Level47_84838W(phasePointerOrLowWord24,4);
    phaseIndexOrHigh10=0;
    pointBase14=(unsigned char*)resultOrField2+0x758;
    headerRecord12=(unsigned char*)resultOrField2+0xB94;
    topologyBase15=(unsigned char*)resultOrField2+0xBD4;
    Level47_84838KEEP(topologyBase15);
    do{
        sampleOrField3=Level47_84838Counter;
        phasePointerOrLowWord24=originalFrame.private;
        resultOrField2=sampleOrField3*20;
        resultOrField2=phaseIndexOrHigh10+resultOrField2;
        resultOrField2=(resultOrField2&255)<<1;
        resultOrField2+=(int)sinTable11;
        sampleOrField3=*(short*)resultOrField2;
        resultOrField2=Level47_84838H(phasePointerOrLowWord24,0x16);
        completeSignedProduct=(long long)sampleOrField3*(long long)resultOrField2;
        __asm__ volatile(""::"x"(completeSignedProduct));
        phasePointerOrLowWord24=originalFrame.owner;
        __asm__("":"=r"(outerIndex21):"0"(outerIndex21),"r"(phasePointerOrLowWord24));
        resultOrField2=outerIndex21*17;
        Level47_84838KEEP(resultOrField2);
        argumentOrAngle4=Level47_84838B(phasePointerOrLowWord24,0x46);
        phasePointerOrLowWord24=(unsigned char*)originalFrame.size;
        Level47_84838KEEP(phasePointerOrLowWord24);
        argumentOrAngle4+=resultOrField2;
        sampleOrField3=(argumentOrAngle4&255)<<1;
        resultOrField2=sampleOrField3+(int)sinTable11;
        Level47_84838KEEP(resultOrField2);
        __asm__("":"=l"(signedLowWord):"x"(completeSignedProduct),"r"(resultOrField2));
        argumentOrLowWord6=signedLowWord;
        Level47_84838KEEP(argumentOrLowWord6);
        resultOrField2=*(short*)resultOrField2;
        __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(argumentOrLowWord6));
        completeSignedProduct=(long long)resultOrField2*(long long)(int)phasePointerOrLowWord24;
        sampleOrField3=sampleOrField3+(int)cosTableOrMagic13;
        Level47_84838KEEP(sampleOrField3);
        __asm__("":"=l"(signedLowWord):"x"(completeSignedProduct),"r"(sampleOrField3));
        argumentOrLowWord5=signedLowWord;
        Level47_84838KEEP(argumentOrLowWord5);
        resultOrField2=*(short*)sampleOrField3;
        __asm__ volatile(""::"r"(resultOrField2):"$17");
        innerIndex17=0;
        __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(argumentOrLowWord5));
        completeSignedProduct=(long long)resultOrField2*(long long)(int)phasePointerOrLowWord24;
        __asm__ volatile(""::"x"(completeSignedProduct));
        radiusOrSinAddress19=(int)sinTable11;
        angleOrCosAddress18=(int)cosTableOrMagic13;
        argumentOrAngle4=((argumentOrAngle4+64)&255)<<1;
        sinAddressMagicOrHigh9=argumentOrAngle4+(int)sinTable11;
        cosAddressMagicOrHigh8=argumentOrAngle4+(int)cosTableOrMagic13;
        argumentOrVerticalOffset7=argumentOrLowWord6>>12;
        phasePointerOrLowWord24=originalFrame.private;
        cosAddressOrSinOffset=argumentOrLowWord5>>12;
        baseIndexOrRadius20=Level47_84838H(phasePointerOrLowWord24,0x14);
        __asm__("":"=l"(signedLowWord):"x"(completeSignedProduct),"r"(baseIndexOrRadius20));
        sampleOrField3=signedLowWord;
        Level47_84838KEEP(sampleOrField3);
        cosOffset23=sampleOrField3>>12;
        do{
            originalFrame.first[0]=0;
            resultOrField2=*(short*)angleOrCosAddress18;
            phasePointerOrLowWord24=(unsigned char*)Level47_84838Low(resultOrField2,baseIndexOrRadius20);
            Level47_84838KEEP(phasePointerOrLowWord24);
            sampleOrField3=(int)phasePointerOrLowWord24>>12;
            originalFrame.first[1]=sampleOrField3;
            resultOrField2=*(short*)radiusOrSinAddress19;
            phasePointerOrLowWord24=(unsigned char*)Level47_84838Low(resultOrField2,baseIndexOrRadius20);
            Level47_84838KEEP(phasePointerOrLowWord24);
            resultOrField2=(int)phasePointerOrLowWord24>>12;
            originalFrame.first[2]=resultOrField2;
            resultOrField2=*(short*)sinAddressMagicOrHigh9;
            completeSignedProduct=(long long)sampleOrField3*(long long)resultOrField2;
            __asm__ volatile(""::"x"(completeSignedProduct));
            resultOrField2=sinOffsetOrBaseIndex22+innerIndex17;
            Level47_84838KEEP(resultOrField2);
            pointRecord16=pointBase14+resultOrField2*12;
            Level47_84838KEEP(pointRecord16);
            __asm__("":"=l"(signedLowWord):"x"(completeSignedProduct),"r"(pointRecord16));
            phasePointerOrLowWord24=(unsigned char*)signedLowWord;
            Level47_84838KEEP(phasePointerOrLowWord24);
            resultOrField2=-(int)phasePointerOrLowWord24;
            resultOrField2>>=12;
            Level47_84838W(pointRecord16,0)=resultOrField2;
            sampleOrField3=*(short*)cosAddressMagicOrHigh8;
            resultOrField2=originalFrame.first[1];
            completeSignedProduct=(long long)resultOrField2*(long long)sampleOrField3;
            __asm__ volatile(""::"x"(completeSignedProduct));
            angleOrCosAddress18+=84;
            argumentOrAngle4=(int)pointRecord16;
            phasePointerOrLowWord24=originalFrame.owner;
            __asm__ volatile(""::"r"(phasePointerOrLowWord24):"$6");
            argumentOrLowWord6=(int)pointRecord16;
            argumentOrLowWord5=(int)phasePointerOrLowWord24+12;
            __asm__("":"=l"(signedLowWord):"x"(completeSignedProduct),"r"(argumentOrAngle4),"r"(argumentOrLowWord6),"r"(angleOrCosAddress18));
            phasePointerOrLowWord24=(unsigned char*)signedLowWord;
            Level47_84838KEEP(phasePointerOrLowWord24);
            resultOrField2=(int)phasePointerOrLowWord24>>12;
            Level47_84838W(pointRecord16,4)=resultOrField2;
            resultOrField2=originalFrame.first[2];
            innerIndex17++;
            Level47_84838W(pointRecord16,8)=resultOrField2;
            originalFrame.spill[0]=argumentOrVerticalOffset7;
            originalFrame.spill[1]=cosAddressMagicOrHigh8;
            originalFrame.spill[2]=sinAddressMagicOrHigh9;
            originalFrame.spill[3]=phaseIndexOrHigh10;
            originalFrame.spill[4]=(int)sinTable11;
            originalFrame.spill[5]=(int)headerRecord12;
            originalFrame.spill[6]=(int)cosTableOrMagic13;
            originalFrame.spill[7]=(int)pointBase14;
            originalFrame.spill[8]=(int)topologyBase15;
            Level47_84838H4F194_6(argumentOrAngle4,argumentOrLowWord5,argumentOrLowWord6);
            resultOrField2=Level47_84838W(pointRecord16,0);
            Level47_84838KEEP(resultOrField2);
            resultOrField2+=cosOffset23;
            Level47_84838W(pointRecord16,0)=resultOrField2;
            resultOrField2=Level47_84838W(pointRecord16,4);
            sampleOrField3=Level47_84838W(pointRecord16,8);
            resultOrField2+=cosAddressOrSinOffset;
            Level47_84838W(pointRecord16,4)=resultOrField2;
            argumentOrVerticalOffset7=originalFrame.spill[0];
            resultOrField2=innerIndex17<6;
            sampleOrField3+=argumentOrVerticalOffset7;
            Level47_84838W(pointRecord16,8)=sampleOrField3;
            cosAddressMagicOrHigh8=originalFrame.spill[1];
            sinAddressMagicOrHigh9=originalFrame.spill[2];
            phaseIndexOrHigh10=originalFrame.spill[3];
            sinTable11=(short*)originalFrame.spill[4];
            headerRecord12=(unsigned char*)originalFrame.spill[5];
            cosTableOrMagic13=(short*)originalFrame.spill[6];
            pointBase14=(unsigned char*)originalFrame.spill[7];
            topologyBase15=(unsigned char*)originalFrame.spill[8];
            __asm__("":"=r"(radiusOrSinAddress19):"0"(radiusOrSinAddress19),"r"(cosAddressMagicOrHigh8),"r"(sinAddressMagicOrHigh9),"r"(phaseIndexOrHigh10),"r"(sinTable11),"r"(headerRecord12),"r"(cosTableOrMagic13),"r"(pointBase14),"r"(topologyBase15));
            radiusOrSinAddress19+=84;
        }
        while(resultOrField2);
        sinOffsetOrBaseIndex22+=6;
        outerIndex21++;
        phaseIndexOrHigh10+=80;
    }
    while(outerIndex21<16);
    outerIndex21=0;
    cosTableOrMagic13=(short*)(int)0xB60B60B7;
    Level47_84838KEEP(cosTableOrMagic13);
    topologyLiteral11=2;
    phaseIndexOrHigh10=0;
    Level47_84838W(pointBase14,0x438)=-1;
    Level47_84838B(headerRecord12,0)=150;
    Level47_84838B(headerRecord12,1)=150;
    Level47_84838B(headerRecord12,2)=150;
    Level47_84838B(headerRecord12,4)=70;
    Level47_84838B(headerRecord12,5)=70;
    Level47_84838B(headerRecord12,6)=70;
    Level47_84838B(headerRecord12,8)=20;
    Level47_84838B(headerRecord12,9)=20;
    Level47_84838B(headerRecord12,10)=20;
    do{
        innerIndex17=0;
        do{
            resultOrField2=0x55555556;
            completeSignedProduct=(long long)innerIndex17*(long long)resultOrField2;
            __asm__ volatile(""::"x"(completeSignedProduct));
            resultOrField2=0x2AAA0000;
            Level47_84838KEEP(resultOrField2);
            __asm__("":"=h"(signedHighWord):"x"(completeSignedProduct),"r"(resultOrField2));
            cosAddressMagicOrHigh8=signedHighWord;
            Level47_84838KEEP(cosAddressMagicOrHigh8);
            __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(cosAddressMagicOrHigh8));
            resultOrField2|=0xAAAB;
            argumentOrAngle4=innerIndex17+1;
            __asm__("":"=r"(argumentOrAngle4):"0"(argumentOrAngle4),"r"(cosAddressMagicOrHigh8));
            completeSignedProduct=(long long)argumentOrAngle4*(long long)resultOrField2;
            __asm__ volatile(""::"x"(completeSignedProduct));
            sampleOrField3=phaseIndexOrHigh10+innerIndex17;
            argumentOrLowWord5=innerIndex17+6;
            argumentOrLowWord5=phaseIndexOrHigh10+argumentOrLowWord5;
            resultOrField2=sampleOrField3*8;
            argumentOrLowWord6=(int)topologyBase15+resultOrField2;
            resultOrField2=innerIndex17>>31;
            argumentOrVerticalOffset7=cosAddressMagicOrHigh8-resultOrField2;
            __asm__("":"=h"(signedHighWord):"x"(completeSignedProduct),"r"(argumentOrVerticalOffset7));
            sinAddressMagicOrHigh9=signedHighWord;
            Level47_84838KEEP(sinAddressMagicOrHigh9);
            resultOrField2=argumentOrVerticalOffset7*3;
            __asm__("":"=r"(argumentOrLowWord5):"0"(argumentOrLowWord5),"r"(sinAddressMagicOrHigh9));
            completeSignedProduct=(long long)argumentOrLowWord5*(long long)(int)cosTableOrMagic13;
            __asm__ volatile(""::"x"(completeSignedProduct));
            argumentOrVerticalOffset7=innerIndex17-resultOrField2;
            Level47_84838B(argumentOrLowWord6,0)=sampleOrField3;
            sampleOrField3=argumentOrAngle4>>31;
            sampleOrField3=sinAddressMagicOrHigh9-sampleOrField3;
            resultOrField2=sampleOrField3*6;
            argumentOrAngle4-=resultOrField2;
            resultOrField2=phaseIndexOrHigh10+argumentOrAngle4;
            argumentOrAngle4+=6;
            argumentOrAngle4=phaseIndexOrHigh10+argumentOrAngle4;
            __asm__("":"=h"(signedHighWord):"x"(completeSignedProduct),"r"(argumentOrAngle4));
            cosAddressMagicOrHigh8=signedHighWord;
            Level47_84838KEEP(cosAddressMagicOrHigh8);
            sampleOrField3=argumentOrLowWord5>>31;
            Level47_84838B(argumentOrLowWord6,1)=resultOrField2;
            __asm__("":"=r"(argumentOrAngle4):"0"(argumentOrAngle4),"r"(cosAddressMagicOrHigh8));
            completeSignedProduct=(long long)argumentOrAngle4*(long long)(int)cosTableOrMagic13;
            __asm__ volatile(""::"x"(completeSignedProduct));
            resultOrField2=cosAddressMagicOrHigh8+argumentOrLowWord5;
            resultOrField2>>=6;
            resultOrField2-=sampleOrField3;
            resultOrField2*=90;
            argumentOrLowWord5-=resultOrField2;
            sampleOrField3=argumentOrAngle4>>31;
            Level47_84838B(argumentOrLowWord6,2)=argumentOrLowWord5;
            __asm__("":"=h"(signedHighWord):"x"(completeSignedProduct),"m"(Level47_84838B(argumentOrLowWord6,2)));
            sinAddressMagicOrHigh9=signedHighWord;
            Level47_84838KEEP(sinAddressMagicOrHigh9);
            resultOrField2=sinAddressMagicOrHigh9+argumentOrAngle4;
            resultOrField2>>=6;
            resultOrField2-=sampleOrField3;
            resultOrField2*=90;
            argumentOrAngle4-=resultOrField2;
            Level47_84838B(argumentOrLowWord6,3)=argumentOrAngle4;
            if(!argumentOrVerticalOffset7){
                Level47_84838B(argumentOrLowWord6,4)=0;
                Level47_84838B(argumentOrLowWord6,5)=topologyLiteral11;
                Level47_84838B(argumentOrLowWord6,6)=0;
                Level47_84838B(argumentOrLowWord6,7)=topologyLiteral11;
            }
            else if(argumentOrVerticalOffset7==1){
                Level47_84838B(argumentOrLowWord6,4)=topologyLiteral11;
                Level47_84838B(argumentOrLowWord6,5)=topologyLiteral11;
                Level47_84838B(argumentOrLowWord6,6)=topologyLiteral11;
                Level47_84838B(argumentOrLowWord6,7)=topologyLiteral11;
            }
            else if(argumentOrVerticalOffset7==topologyLiteral11){
                Level47_84838B(argumentOrLowWord6,4)=topologyLiteral11;
                Level47_84838B(argumentOrLowWord6,5)=0;
                Level47_84838B(argumentOrLowWord6,6)=topologyLiteral11;
                Level47_84838B(argumentOrLowWord6,7)=0;
            }
            innerIndex17++;
        }
        while(innerIndex17<6);
        outerIndex21++;
        phaseIndexOrHigh10+=6;
    }
    while(outerIndex21<15);
    Level47_84838W(topologyBase15,0x2D0)=-1;
    phasePointerOrLowWord24=originalFrame.private;
    if(!Level47_84838W(phasePointerOrLowWord24,12)){
        argumentOrAngle4=(int)pointBase14;
        argumentOrLowWord5=(int)headerRecord12;
        argumentOrLowWord6=(int)topologyBase15;
        phasePointerOrLowWord24=originalFrame.parent;
        resultOrField2=Level47_84838H50B00_7(argumentOrAngle4,argumentOrLowWord5,argumentOrLowWord6,(int)phasePointerOrLowWord24+12,1);
        phasePointerOrLowWord24=originalFrame.private;
        Level47_84838W(phasePointerOrLowWord24,12)=resultOrField2;
    }
    if(Level47_84838B(Level47_84838Owner(),0x48)==2){
        phasePointerOrLowWord24=originalFrame.private;
        argumentOrAngle4=Level47_84838W(phasePointerOrLowWord24,8);
        if(argumentOrAngle4)Level47_84838H50B88_8(argumentOrAngle4);
        phasePointerOrLowWord24=originalFrame.private;
        argumentOrAngle4=Level47_84838W(phasePointerOrLowWord24,12);
        if(argumentOrAngle4)Level47_84838H50B88_9(argumentOrAngle4);
        Level47_84838H55B18_10(originalFrame.owner);
    }
}
#undef Level47_84838F
#undef Level47_84838W
#undef Level47_84838P
#undef Level47_84838B
#undef Level47_84838H
#undef Level47_84838U
#undef Level47_84838Owner
#undef Level47_84838KEEP
#undef Level47_84838Low


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0; original 8008512C.
* Original assembly SHA256 fb319579d91d77e1454ae00cc5fd625caf435194bce4fcc6f92278c3c9970be1.
* AI generated; not human reviewed. All 440 original instructions and
* actual conditional/J/call targets must match; no separate owned data.
* Original B8hex frame saves S0..S7/FP/RA and retains SP18..8B storage.
* Per invocation, original loops write 16*8 twelve-byte records, then
* 105 eight-byte records with four indices and four signed remainder
* equals-zero bytes. Their consumers and physical units remain unresolved.
* Every MULT low/high input is a complete initialized signed64 C product.
* Each next producer depends on the complete prior captured GPR so the
* unchanged scheduler cannot overlap two DI values in the same HI/LO pair.
* Original delayed captures remain after their exact scalar/store producers.
* The /3 and /10 magic constants, signed corrections, byte/halfword widths,
* actual pointer arithmetic, counter bounds and original load order remain.
* Identical whole upper literals on both original SP58 decision paths let
* reorg merge the LUI into slot72 without a stale V0 marker blocking49/158.
* SP88 has its original ordinary store and explicit volatile reload so the
* store occupies the original call delay slot; no invented value is read.
* Empty metadata reads complete produced values or already-written fields,
* or clobbers dead words before fresh full producers; emits zero CPU words.
* No opcode asm, partial HI/LO inputs, fixed FP, undefined saved input or
* overlapping live fixed aliases. Compiler/filter/flags remain unchanged.
* Existing tracers.h and moby260.h contracts supply typed helper ABI views.
* Confidence: binary identity after all native/linked word, actual target
* and full EXE/every-overlay retail hash gates. Full helper/caller chains,
* physical units/fixed point, cadence beyond one invocation, Rev1 mapping
* and synchronized retail runtime remain open. Next: human review/captures.
*/
#define Level47_8512CCompleteProductLow(a,b) ({long long fullProduct=(long long)(int)(a)*(long long)(int)(b);int fullLow;__asm__("":"=l"(fullLow):"x"(fullProduct));fullLow;})
#define Level47_8512CCompleteProductHigh(a,b) ({ long long computedProduct=(long long)(int)(a)*(long long)(int)(b);int nativeHigh;__asm__("":"=h"(nativeHigh):"x"(computedProduct));nativeHigh; })
#define Level47_8512CField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Level47_8512CCall4ED6CView1() __asm__("func_8004ED6C");
int Level47_8512CCall4F194View1() __asm__("func_8004F194");
void *Level47_8512CCall50B00View1(int,int,int,int,int) __asm__("func_80050B00");
void Level47_8512CCall50B88View1(void*) __asm__("func_80050B88");
void Level47_8512CCall55B18View1(void*) __asm__("func_80055B18");
int Level47_8512CCall55D24View1() __asm__("func_80055D24");
extern unsigned char Level47_8512CData658A0View1[] __asm__("D_800658A0");
extern unsigned char Level47_8512CData65920View1[] __asm__("D_80065920");
extern int Level47_8512CData6C550View1 __asm__("D_8006C550");
extern void *(*Level47_8512CDataSpawnParticleView1)() __asm__("SpawnParticle");
void func_level_47_8008512C(void *ownerParameter) {
    long long completeTenDivisionProduct,completeDelayedSignedProduct,completeLastSignedProduct;
    int tenDivisionProductHigh,delayedSignedProductLow,lastSignedProductLow;
    register int divisionProductHigh9 __asm__("$9");
    register int signedThirdMagic8 __asm__("$8");
    register int rawAddressOrHigh15 __asm__("$15");
    register int originalStateTwenty4 __asm__("$4");
    struct {
        volatile int sp18;
        volatile int sp1C;
        volatile int sp20;
        int pad24;
        int sp28;
        int sp2C;
        int sp30;
        int pad34;
        void * volatile sp38;
        int pad3C;
        int volatile sp40;
        int pad44;
        void * volatile sp48;
        int pad4C;
        int sp50;
        int pad54;
        int volatile sp58;
        int pad5C;
        int gap60[6];
        short *volatile sp78;
        short *volatile sp7C;
        unsigned char *volatile sp80;
        unsigned char *volatile sp84;
        void *sp88;
    }
    originalFrame;
    register unsigned char *table658A0Base12 __asm__("$12");
    register unsigned char *table65920Base13 __asm__("$13");
    register short *table658A0Entry10 __asm__("$10");
    register short *table65920Entry11 __asm__("$11");
    register int tableHalfword4 __asm__("$4");
    register int counterLimitWord4 __asm__("$4");
    register int rawWord2 __asm__("$2");
    register int counterPredicateWord2 __asm__("$2");
    register int counterWord2 __asm__("$2");
    register int scaledCounter4 __asm__("$4");
    register int remainderDividend7 __asm__("$7");
    register int delayedLowProduct24 __asm__("$24");
    register int fullLowProduct8 __asm__("$8");
    register int argumentWord5 __asm__("$5");
    register int rawPhaseWord2 __asm__("$2");
    register int recordPredicateWord2 __asm__("$2");
    register int rawWord3 __asm__("$3");
    register int argumentWord4 __asm__("$4");
    register int innerRecordIndex16 __asm__("$16");
    register int signedRemainderTen18 __asm__("$18");
    register int signedRemainderThree19 __asm__("$19");
    register int tableByteOffset20 __asm__("$20");
    register int totalRecordIndex21 __asm__("$21");
    register int recordColumn21 __asm__("$21");
    register int outerRecordIndex22 __asm__("$22");
    register int eightByteRecordIndex22 __asm__("$22");
    register int thirdIndex4 __asm__("$4");
    register int argumentWord6 __asm__("$6");
    register int eightByteRecordVertex16 __asm__("$16");
    register void *callOwnerOrSpawnResult4 __asm__("$4");
    register void *firstCleanupRecord4 __asm__("$4");
    register void *secondCleanupRecord4 __asm__("$4");
    void *retainedHeaderAddress;
    register void *privateRecord23 __asm__("$23");
    register void *eightByteRecordCursor7 __asm__("$7");
    register void *recordCursor17 __asm__("$17");
    register void *recordArrayBase14 __asm__("$14");
    originalFrame.sp38=ownerParameter;
    privateRecord23=Level47_8512CField(ownerParameter,void**,0);
    __asm__("" : "=r"(totalRecordIndex21):"r"(privateRecord23));
    totalRecordIndex21=0;
    rawPhaseWord2=(int)Level47_8512CField(privateRecord23,void**,0x10);
    __asm__("" : "=r"(signedRemainderThree19):"r"(rawPhaseWord2));
    signedRemainderThree19=0;
    rawPhaseWord2=Level47_8512CField((void*)rawPhaseWord2,int*,0);
    __asm__("" : "=r"(signedRemainderTen18):"r"(rawPhaseWord2));
    signedRemainderTen18=1;
    originalFrame.sp40=rawPhaseWord2;
    Level47_8512CField(ownerParameter,unsigned char*,0x41)=0;
    rawAddressOrHigh15=(int)originalFrame.sp38;
    originalStateTwenty4=20;
    Level47_8512CField(rawAddressOrHigh15,unsigned char*,0x4C)=0;
    Level47_8512CField(rawAddressOrHigh15,unsigned char*,0x4D)=0;
    recordArrayBase14=Level47_8512CField(privateRecord23,void**,4);
    rawAddressOrHigh15=Level47_8512CField(privateRecord23,short*,2);
    retainedHeaderAddress=recordArrayBase14+0x604;
    __asm__("" : "=r"(retainedHeaderAddress):"0"(retainedHeaderAddress),"r"(rawAddressOrHigh15));
    originalFrame.sp58=rawAddressOrHigh15;
    rawAddressOrHigh15=(int)recordArrayBase14+0x644;
    originalFrame.sp48=(void*)rawAddressOrHigh15;
    rawAddressOrHigh15=(int)originalFrame.sp38;
    rawWord3=Level47_8512CField(&originalFrame.sp58,volatile unsigned short*,0);
    rawWord2=Level47_8512CField(rawAddressOrHigh15,unsigned char*,0x48);
    rawAddressOrHigh15=Level47_8512CField(privateRecord23,short*,0);
    originalFrame.sp50=rawAddressOrHigh15;
    if(rawWord2!=originalStateTwenty4){
        rawWord2=rawWord3+350;
        Level47_8512CField(privateRecord23,short*,2)=rawWord2;
        rawAddressOrHigh15=(int)originalFrame.sp38;
        rawWord2=Level47_8512CField(rawAddressOrHigh15,unsigned char*,0x48);
        outerRecordIndex22=0;
        if(rawWord2!=originalStateTwenty4){
            rawWord2=Level47_8512CField(privateRecord23,short*,0x16);
            rawWord3=rawWord2;
            rawWord2=rawWord2<1850;
            __asm__("" : "=r"(rawWord2),"=r"(rawWord3):"0"(rawWord2),"1"(rawWord3));
            if(rawWord2){
                rawWord2=rawWord3+250;
                Level47_8512CField(privateRecord23,short*,0x16)=rawWord2;
                goto initializeOriginalOuterIndex;
            }
        }
    }
    else{
        initializeOriginalOuterIndex:outerRecordIndex22=0;
    }
    table65920Base13=Level47_8512CData65920View1;
    table658A0Base12=Level47_8512CData658A0View1;
    do {
        __asm__ volatile("":::"$2");
        innerRecordIndex16 = 0;
        tableByteOffset20 = 0x80;
        rawPhaseWord2=(totalRecordIndex21<<1)+totalRecordIndex21;
        rawPhaseWord2<<=2;
        recordCursor17=(void*)(rawPhaseWord2+(int)recordArrayBase14);
        rawPhaseWord2 = ((Level47_8512CField((rawAddressOrHigh15=(int)originalFrame.sp38), unsigned char *, 0x46) + (outerRecordIndex22 * 8)) & 0xFF) * 2;
        table65920Entry11=(short*)(rawPhaseWord2+(int)table65920Base13);
        table658A0Entry10=(short*)(rawPhaseWord2+(int)table658A0Base12);
    writeOriginalInnerRecord:
        argumentWord4=Level47_8512CField(&originalFrame.sp50,volatile int*,0);
        if(signedRemainderThree19==0){
            rawWord2=0x55550000;
            argumentWord4=originalFrame.sp58;
        }
        else{
            rawWord2=0x55550000;
        }
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        rawWord2|=0x5556;
        rawWord3 = signedRemainderThree19 + 1;
        rawAddressOrHigh15 = Level47_8512CCompleteProductHigh(rawWord3, rawWord2);
        rawWord2 = rawWord3 >> 31;
        __asm__("":"=r"(rawAddressOrHigh15):"0"(rawAddressOrHigh15),"r"(rawWord2));
        signedRemainderThree19 = rawAddressOrHigh15 - rawWord2;
        __asm__("" : "=r"(signedRemainderThree19) : "0"(signedRemainderThree19));
        rawWord2 = signedRemainderThree19 * 3;
        signedRemainderThree19 = rawWord3 - rawWord2;
        if (signedRemainderTen18 == 0) {
            argumentWord4 = (int) Level47_8512CField(privateRecord23, short *, 0x16);
        }
        rawWord2 = tableByteOffset20 + (int)table65920Base13;
        originalFrame.sp18 = 0;
        rawWord2 = Level47_8512CField(rawWord2, short*, 0);
        rawWord3=Level47_8512CCompleteProductLow(rawWord2,argumentWord4);
        rawWord2 = tableByteOffset20 + (int)table658A0Base12;
        __asm__("" : "=r"(rawWord3), "=r"(rawWord2) : "0"(rawWord3), "1"(rawWord2));
        rawWord3 >>= 12;
        originalFrame.sp1C = rawWord3;
        rawWord2 = Level47_8512CField(rawWord2, short*, 0);
        fullLowProduct8=Level47_8512CCompleteProductLow(rawWord2,argumentWord4);
        __asm__("" : "=r"(fullLowProduct8) : "0"(fullLowProduct8));
        rawWord2 = fullLowProduct8 >> 12;
        originalFrame.sp20 = rawWord2;
        tableHalfword4 = *table658A0Entry10;
        rawWord3=Level47_8512CCompleteProductLow(rawWord3,tableHalfword4);
        remainderDividend7 = signedRemainderTen18 + 1;
        __asm__("" : "=r"(rawWord3), "=r"(remainderDividend7) : "0"(rawWord3), "1"(remainderDividend7) : "$2");
        rawWord2 = 0x66666667;
        completeTenDivisionProduct = (long long)remainderDividend7 * (long long)rawWord2;
        __asm__ volatile("" : : "x"(completeTenDivisionProduct));
        fullLowProduct8 = rawWord3 >> 12;
        rawWord3 = *table65920Entry11;
        __asm__("":"=r"(fullLowProduct8):"0"(fullLowProduct8),"r"(rawWord3));
        rawWord2 = -fullLowProduct8;
        Level47_8512CField(recordCursor17, int*, 0) = rawWord2;
        __asm__("" : "=h"(tenDivisionProductHigh) : "x"(completeTenDivisionProduct),"m"(Level47_8512CField(recordCursor17,int*,0)));
        divisionProductHigh9=tenDivisionProductHigh;
        __asm__("" : "=r"(divisionProductHigh9) : "0"(divisionProductHigh9));
        rawWord2 = originalFrame.sp1C;
        __asm__("":"=r"(rawWord2):"0"(rawWord2),"r"(divisionProductHigh9));
        fullLowProduct8=Level47_8512CCompleteProductLow(rawWord2,rawWord3);
        __asm__("":"=r"(fullLowProduct8):"0"(fullLowProduct8));
        rawWord2 = originalFrame.sp18;
        __asm__("":"=r"(rawWord2):"0"(rawWord2),"r"(fullLowProduct8));
        completeDelayedSignedProduct=(long long)rawWord2*(long long)tableHalfword4;
        __asm__ volatile(""::"x"(completeDelayedSignedProduct));
        argumentWord6 = (int)recordCursor17;
        totalRecordIndex21 += 1;
        innerRecordIndex16 += 1;
        rawAddressOrHigh15 = (int)originalFrame.sp38;
        __asm__("":"=r"(tableByteOffset20):"0"(tableByteOffset20),"r"(rawAddressOrHigh15));
        tableByteOffset20 += 0x20;
        argumentWord5 = rawAddressOrHigh15 + 12;
        __asm__("":"=r"(divisionProductHigh9):"0"(divisionProductHigh9),"r"(argumentWord5),"r"(tableByteOffset20));
        rawWord3 = divisionProductHigh9 >> 2;
        __asm__("" : "=r"(rawWord3) : "0"(rawWord3) : "$2", "$4");
        argumentWord4 = (int)recordCursor17;
        rawWord2 = remainderDividend7 >> 31;
        signedRemainderTen18 = rawWord3 - rawWord2;
        __asm__("" : "=r"(signedRemainderTen18) : "0"(signedRemainderTen18));
        __asm__("":"=r"(fullLowProduct8):"0"(fullLowProduct8),"r"(signedRemainderTen18));
        fullLowProduct8 >>= 12;
        __asm__("":"=l"(delayedSignedProductLow):"x"(completeDelayedSignedProduct),"r"(fullLowProduct8),"r"(signedRemainderTen18));
        delayedLowProduct24=delayedSignedProductLow;
        __asm__("" : "=r"(delayedLowProduct24) : "0"(delayedLowProduct24));
        rawWord2 = delayedLowProduct24 >> 12;
        rawWord2 += fullLowProduct8;
        Level47_8512CField(recordCursor17, int*, 4) = rawWord2;
        rawWord2 = signedRemainderTen18 * 10;
        rawWord3 = originalFrame.sp20;
        __asm__("":"=r"(rawWord2):"0"(rawWord2),"r"(rawWord3));
        signedRemainderTen18 = remainderDividend7 - rawWord2;
        __asm__("":"=r"(rawWord3):"0"(rawWord3),"r"(signedRemainderTen18));
        Level47_8512CField(recordCursor17, int*, 8) = rawWord3;
        originalFrame.sp78 = table658A0Entry10;
        originalFrame.sp7C = table65920Entry11;
        originalFrame.sp80 = table658A0Base12;
        originalFrame.sp84 = table65920Base13;
        originalFrame.sp88 = recordArrayBase14;
        Level47_8512CCall4F194View1(argumentWord4, argumentWord5, argumentWord6, remainderDividend7);
        rawPhaseWord2=innerRecordIndex16<8;
        __asm__ volatile("":"=r"(rawPhaseWord2):"0"(rawPhaseWord2));
        table658A0Entry10=originalFrame.sp78;
        table65920Entry11=originalFrame.sp7C;
        table658A0Base12=originalFrame.sp80;
        table65920Base13=originalFrame.sp84;
        recordArrayBase14=Level47_8512CField(&originalFrame.sp88,void *volatile*,0);
        __asm__ volatile("":"=r"(recordCursor17):"0"(recordCursor17),"r"(recordArrayBase14));
        recordCursor17 += 0xC;
        if (rawPhaseWord2) {
            goto writeOriginalInnerRecord;
        }
        outerRecordIndex22 += 1;
    }
    while (outerRecordIndex22 < 0x10);
    Level47_8512CField(recordArrayBase14, int *, 0x600) = -1;
    rawWord3=Level47_8512CField(privateRecord23,short*,0x14);
    if(rawWord3>=7){
        rawPhaseWord2=rawWord3-6;
        __asm__("" : "=r"(rawPhaseWord2):"0"(rawPhaseWord2));
        rawWord3=rawPhaseWord2*10;
        __asm__("" : "=r"(rawWord3):"0"(rawWord3));
        rawPhaseWord2=64-rawWord3;
        __asm__("" : "=r"(rawPhaseWord2):"0"(rawPhaseWord2));
        if(rawPhaseWord2<0)rawPhaseWord2=0;
        Level47_8512CField(retainedHeaderAddress,unsigned char*,0)=rawPhaseWord2;
        rawPhaseWord2>>=1;
        Level47_8512CField(retainedHeaderAddress,unsigned char*,1)=rawPhaseWord2;
        rawPhaseWord2=(unsigned int)(rawPhaseWord2&255)>>1;
        goto writeOriginalHeaderByteTwo;
    }
    if(rawWord3>=4){
        rawPhaseWord2=rawWord3-3;
        __asm__("" : "=r"(rawPhaseWord2):"0"(rawPhaseWord2));
        rawPhaseWord2<<=4;
        rawWord3=128;
        rawPhaseWord2=rawWord3-rawPhaseWord2;
        Level47_8512CField(retainedHeaderAddress,unsigned char*,0)=rawPhaseWord2;
        Level47_8512CField(retainedHeaderAddress,unsigned char*,1)=rawPhaseWord2;
        Level47_8512CField(retainedHeaderAddress,unsigned char*,2)=0;
    }
    else{
        rawPhaseWord2=128;
        Level47_8512CField(retainedHeaderAddress,unsigned char*,0)=rawPhaseWord2;
        Level47_8512CField(retainedHeaderAddress,unsigned char*,1)=rawPhaseWord2;
        rawPhaseWord2=Level47_8512CField(privateRecord23,short*,0x14);
        rawWord3=128;
        rawPhaseWord2<<=5;
        rawPhaseWord2=rawWord3-rawPhaseWord2;
        __asm__("" : "=r"(rawPhaseWord2):"0"(rawPhaseWord2));
        if(rawPhaseWord2<0)rawPhaseWord2=0;
    writeOriginalHeaderByteTwo:
        Level47_8512CField(retainedHeaderAddress,unsigned char*,2)=rawPhaseWord2;
    }
    rawWord3=Level47_8512CField(privateRecord23,short*,0x14);
    rawPhaseWord2=rawWord3<6;
    __asm__("":"=r"(rawPhaseWord2):"0"(rawPhaseWord2));
    if(rawPhaseWord2){
        rawPhaseWord2=255;
    }
    else{
        rawPhaseWord2=16-rawWord3;
        __asm__("" : "=r"(rawPhaseWord2):"0"(rawPhaseWord2));
        rawPhaseWord2<<=3;
    }
    __asm__("" : "=r"(rawPhaseWord2):"0"(rawPhaseWord2));
    Level47_8512CField(retainedHeaderAddress,unsigned char*,4)=rawPhaseWord2;
    Level47_8512CField(retainedHeaderAddress,unsigned char*,5)=rawPhaseWord2;
    Level47_8512CField(retainedHeaderAddress,unsigned char*,6)=0;
    __asm__ volatile("" : : : "memory");
    eightByteRecordVertex16 = 0;
    recordColumn21 = 0;
    eightByteRecordIndex22 = 0;
    signedThirdMagic8 = 0x55555556;
    eightByteRecordCursor7 = originalFrame.sp48;
    {
        long long completeFourIndexProduct;
        int fourIndexProductHigh;
        register int firstProductHigh11 __asm__("$11");
        register int secondOrFourthProductHigh10 __asm__("$10");
        register int thirdProductHigh9 __asm__("$9");
        register int fourthIndex5 __asm__("$5");
        do {
            completeFourIndexProduct=(long long)eightByteRecordVertex16*(long long)signedThirdMagic8;
            __asm__("":"=h"(fourIndexProductHigh):"x"(completeFourIndexProduct));
            firstProductHigh11=fourIndexProductHigh;
            __asm__("":"=r"(firstProductHigh11):"0"(firstProductHigh11));
            argumentWord6=eightByteRecordVertex16+1;
            __asm__("":"=r"(argumentWord6):"0"(argumentWord6),"r"(firstProductHigh11));
            completeFourIndexProduct=(long long)argumentWord6*(long long)signedThirdMagic8;
            __asm__ volatile(""::"x"(completeFourIndexProduct));
            recordColumn21+=1;
            thirdIndex4=eightByteRecordVertex16+9;
            fourthIndex5=eightByteRecordVertex16+8;
            rawWord3=eightByteRecordVertex16>>31;
            __asm__("":"=h"(fourIndexProductHigh):"x"(completeFourIndexProduct));
            secondOrFourthProductHigh10=fourIndexProductHigh;
            __asm__("":"=r"(secondOrFourthProductHigh10):"0"(secondOrFourthProductHigh10));
            Level47_8512CField(eightByteRecordCursor7,unsigned char*,0)=eightByteRecordVertex16;
            Level47_8512CField(eightByteRecordCursor7,unsigned char*,1)=argumentWord6;
            __asm__ volatile("":"=r"(thirdIndex4):"0"(thirdIndex4),"r"(secondOrFourthProductHigh10),"m"(Level47_8512CField(eightByteRecordCursor7,unsigned char*,0)),"m"(Level47_8512CField(eightByteRecordCursor7,unsigned char*,1)));
            completeFourIndexProduct=(long long)thirdIndex4*(long long)signedThirdMagic8;
            __asm__ volatile(""::"x"(completeFourIndexProduct));
            Level47_8512CField(eightByteRecordCursor7,unsigned char*,2)=thirdIndex4;
            Level47_8512CField(eightByteRecordCursor7,unsigned char*,3)=fourthIndex5;
            __asm__ volatile("":"=r"(rawWord3):"0"(rawWord3),"x"(completeFourIndexProduct),"m"(Level47_8512CField(eightByteRecordCursor7,unsigned char*,2)),"m"(Level47_8512CField(eightByteRecordCursor7,unsigned char*,3)));
            rawWord3=firstProductHigh11-rawWord3;
            recordPredicateWord2=rawWord3*3;
            recordPredicateWord2=eightByteRecordVertex16-recordPredicateWord2;
            eightByteRecordVertex16=argumentWord6;
            __asm__("" : "=r"(eightByteRecordVertex16) : "0"(eightByteRecordVertex16));
            recordPredicateWord2=(unsigned int)recordPredicateWord2<1;
            rawWord3=eightByteRecordVertex16>>31;
            Level47_8512CField(eightByteRecordCursor7,unsigned char*,4)=recordPredicateWord2;
            __asm__("":"=r"(rawWord3):"0"(rawWord3),"m"(Level47_8512CField(eightByteRecordCursor7,unsigned char*,4)));
            rawWord3=secondOrFourthProductHigh10-rawWord3;
            __asm__("":"=h"(fourIndexProductHigh):"x"(completeFourIndexProduct),"r"(rawWord3));
            thirdProductHigh9=fourIndexProductHigh;
            __asm__("":"=r"(thirdProductHigh9):"0"(thirdProductHigh9));
            recordPredicateWord2=rawWord3*3;
            __asm__("":"=r"(fourthIndex5):"0"(fourthIndex5),"r"(thirdProductHigh9),"r"(recordPredicateWord2));
            completeFourIndexProduct=(long long)fourthIndex5*(long long)signedThirdMagic8;
            __asm__ volatile(""::"x"(completeFourIndexProduct));
            recordPredicateWord2=eightByteRecordVertex16-recordPredicateWord2;
            recordPredicateWord2=(unsigned int)recordPredicateWord2<1;
            rawWord3=thirdIndex4>>31;
            Level47_8512CField(eightByteRecordCursor7,unsigned char*,5)=recordPredicateWord2;
            __asm__("":"=r"(rawWord3):"0"(rawWord3),"m"(Level47_8512CField(eightByteRecordCursor7,unsigned char*,5)));
            rawWord3=thirdProductHigh9-rawWord3;
            recordPredicateWord2=rawWord3*3;
            thirdIndex4-=recordPredicateWord2;
            __asm__("" : "=r"(thirdIndex4) : "0"(thirdIndex4));
            thirdIndex4=(unsigned int)thirdIndex4<1;
            rawWord3=fourthIndex5>>31;
            Level47_8512CField(eightByteRecordCursor7,unsigned char*,6)=thirdIndex4;
            __asm__("":"=h"(fourIndexProductHigh):"x"(completeFourIndexProduct),"r"(rawWord3),"m"(Level47_8512CField(eightByteRecordCursor7,unsigned char*,6)));
            secondOrFourthProductHigh10=fourIndexProductHigh;
            __asm__("":"=r"(secondOrFourthProductHigh10):"0"(secondOrFourthProductHigh10));
            rawWord3=secondOrFourthProductHigh10-rawWord3;
            recordPredicateWord2=rawWord3*3;
            fourthIndex5-=recordPredicateWord2;
            __asm__("":"=r"(fourthIndex5):"0"(fourthIndex5));
            fourthIndex5=(unsigned int)fourthIndex5<1;
            __asm__("":"=r"(fourthIndex5):"0"(fourthIndex5));
            Level47_8512CField(eightByteRecordCursor7,unsigned char*,7)=fourthIndex5;
            if(recordColumn21>=7){
                eightByteRecordVertex16+=1;
                recordColumn21=0;
            }
            eightByteRecordIndex22+=1;
            eightByteRecordCursor7+=8;
        }
        while(eightByteRecordIndex22<105);
    }
    rawAddressOrHigh15 = (int)originalFrame.sp48;
    rawWord2 = -1;
    Level47_8512CField(rawAddressOrHigh15, int*, 0x348) = rawWord2;
    rawWord2 = (int)Level47_8512CField(privateRecord23, void**, 8);
    argumentWord4 = (int)recordArrayBase14;
    if (rawWord2 == 0) {
        argumentWord5 = (int)retainedHeaderAddress;
        argumentWord6 = (int)originalFrame.sp48;
        rawAddressOrHigh15 = originalFrame.sp40;
        rawWord2 = 1;
        rawWord2 = (int)Level47_8512CCall50B00View1(argumentWord4, argumentWord5, argumentWord6, rawAddressOrHigh15+12, rawWord2);
        Level47_8512CField(privateRecord23, void**, 8) = (void*)rawWord2;
    }
    if (Level47_8512CField((rawAddressOrHigh15=(int)originalFrame.sp38), unsigned char *, 0x48) != 0x14) {
        counterPredicateWord2=Level47_8512CField(privateRecord23,short*,20);
        rawWord3=counterPredicateWord2<<2;
        scaledCounter4=rawWord3+counterPredicateWord2;
        counterPredicateWord2=counterPredicateWord2<7;
        __asm__("":"=r"(counterPredicateWord2),"=r"(scaledCounter4):"0"(counterPredicateWord2),"1"(scaledCounter4));
        rawWord3=80;
        if (!counterPredicateWord2) {
            __asm__ volatile("":::"$2");
            Level47_8512CField(privateRecord23,void**,12)=0;
        }
        else {
            scaledCounter4<<=3;
            originalFrame.sp18=0;
            originalFrame.sp1C=0;
            originalFrame.sp20=rawWord3;
            rawPhaseWord2=*(short*)(Level47_8512CData658A0View1+scaledCounter4);
            fullLowProduct8=Level47_8512CCompleteProductLow(rawPhaseWord2,rawWord3);
            __asm__("":"=r"(fullLowProduct8):"0"(fullLowProduct8));
            rawPhaseWord2=*(short*)(Level47_8512CData65920View1+scaledCounter4);
            __asm__("":"=r"(rawPhaseWord2):"0"(rawPhaseWord2),"r"(fullLowProduct8));
            completeLastSignedProduct=(long long)rawPhaseWord2*(long long)rawWord3;
            __asm__ volatile(""::"x"(completeLastSignedProduct));
            callOwnerOrSpawnResult4=originalFrame.sp38;
            __asm__("":"=r"(callOwnerOrSpawnResult4):"0"(callOwnerOrSpawnResult4):"$5");
            argumentWord5=4;
            originalFrame.sp2C=0;
            __asm__("":"=r"(fullLowProduct8):"0"(fullLowProduct8),"m"(originalFrame.sp2C));
            rawWord3=fullLowProduct8>>12;
            rawPhaseWord2=-rawWord3;
            originalFrame.sp28=rawPhaseWord2;
            __asm__("":"=l"(lastSignedProductLow):"x"(completeLastSignedProduct),"r"(callOwnerOrSpawnResult4),"r"(argumentWord5),"m"(originalFrame.sp28));
            argumentWord6=lastSignedProductLow;
            __asm__("":"=r"(argumentWord6):"0"(argumentWord6));
            rawWord3=argumentWord6>>12;
            originalFrame.sp30=rawWord3;
            Level47_8512CCall55D24View1(callOwnerOrSpawnResult4,argumentWord5,argumentWord6);
            Level47_8512CCall4ED6CView1((rawAddressOrHigh15=(int)originalFrame.sp38)+0x20, &originalFrame.sp28, &originalFrame.sp28);
            callOwnerOrSpawnResult4 = Level47_8512CDataSpawnParticleView1(1, 0xD, (rawAddressOrHigh15=(int)originalFrame.sp38)+0xC, &originalFrame.sp28);
            if (Level47_8512CField(privateRecord23, void **, 0xC) != 0) {
                Level47_8512CField(callOwnerOrSpawnResult4, unsigned char *, 0xC) = 0xFF;
                Level47_8512CField(callOwnerOrSpawnResult4, unsigned char *, 0xD) = 0xFF;
                Level47_8512CField(callOwnerOrSpawnResult4, unsigned char *, 0xE) = 0xFF;
            }
            if (callOwnerOrSpawnResult4 != 0) {
                Level47_8512CField(privateRecord23, void **, 0xC) = callOwnerOrSpawnResult4;
                Level47_8512CField(callOwnerOrSpawnResult4, unsigned char *, 0xA) = 0xBE;
                Level47_8512CField(callOwnerOrSpawnResult4, unsigned char *, 0xE) = 0xFF;
            }
        }
    }
    Level47_8512CField(privateRecord23, short *, 0x14) = (short) ((unsigned short) Level47_8512CField(privateRecord23, short *, 0x14) + 1);
    if (Level47_8512CField((rawAddressOrHigh15=(int)originalFrame.sp38), unsigned char *, 0x48) != 0x14) {
        counterWord2=Level47_8512CField(privateRecord23,short*,0);
        rawWord3=counterWord2;
        counterWord2=counterWord2<600;
        __asm__("":"=r"(counterWord2),"=r"(rawWord3):"0"(counterWord2),"1"(rawWord3));
        if(counterWord2){
            counterWord2=rawWord3+100;
            Level47_8512CField(privateRecord23,short*,0)=counterWord2;
        }
    }
    counterLimitWord4=Level47_8512CField(privateRecord23,short*,0x14);
    rawPhaseWord2=counterLimitWord4<11;
    if(rawPhaseWord2){
        rawPhaseWord2=counterLimitWord4<16;
        goto testOriginalSixteenLimit;
    }
    rawAddressOrHigh15=(int)originalFrame.sp38;
    rawWord3=Level47_8512CField(rawAddressOrHigh15,unsigned char*,0x48);
    rawPhaseWord2=20;
    if(rawWord3==rawPhaseWord2){
        rawPhaseWord2=counterLimitWord4<16;
        goto writeOriginalLinkedByte;
    }
    rawPhaseWord2=counterLimitWord4<16;
testOriginalSixteenLimit:
    rawAddressOrHigh15=0;
    if(rawPhaseWord2)goto testOriginalCleanupAddress;
    rawAddressOrHigh15=(int)originalFrame.sp38;
    rawWord3=Level47_8512CField(rawAddressOrHigh15,unsigned char*,0x48);
    rawPhaseWord2=20;
    if(rawWord3!=rawPhaseWord2)goto cleanupOriginalRecords;
    __asm__ volatile("" : : : "memory");
    rawAddressOrHigh15=0;
testOriginalCleanupAddress:
    __asm__("" : "=r"(rawAddressOrHigh15):"0"(rawAddressOrHigh15));
    rawPhaseWord2=20;
    if(rawAddressOrHigh15==0)goto returnOriginalInvocation;
    rawAddressOrHigh15=(int)originalFrame.sp38;
    rawWord3=Level47_8512CField(rawAddressOrHigh15,unsigned char*,0x48);
    if(rawWord3!=rawPhaseWord2)goto cleanupOriginalRecords;
writeOriginalLinkedByte:
    rawWord3=Level47_8512CField(rawAddressOrHigh15,unsigned char*,0x3A);
    rawPhaseWord2=rawWord3*88;
    rawWord3=Level47_8512CData6C550View1;
    rawPhaseWord2+=rawWord3;
    rawWord3=10;
    Level47_8512CField(rawPhaseWord2,unsigned char*,0x49)=rawWord3;
cleanupOriginalRecords:
    firstCleanupRecord4=Level47_8512CField(privateRecord23,void**,8);
    if(firstCleanupRecord4!=0)Level47_8512CCall50B88View1(firstCleanupRecord4);
    secondCleanupRecord4=Level47_8512CField(privateRecord23,void**,0xC);
    if(secondCleanupRecord4!=0)Level47_8512CCall50B88View1(secondCleanupRecord4);
    Level47_8512CCall55B18View1(originalFrame.sp38);
    returnOriginalInvocation:;
}
#undef Level47_8512CField
#undef Level47_8512CCompleteProductHigh
#undef Level47_8512CCompleteProductLow
