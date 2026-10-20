#include "common.h"
#include "moby/moby260.h"
#include "spyro.h"
#include "camera.h"
#include "savepoint.h"
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
void func_level_27_80074DEC(Moby* argument) {
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
void func_level_27_80075478(void *input) {
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
void func_level_27_800769C8(Moby* moby) {
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

extern int D_8006E020, D_8006E024, D_8007191C, D_80071920;
extern Vector3D D_8007190C;
extern int D_8006C644;
extern short D_800658A0[], D_80065920[];
int func_80019194(Vector3D*, int);
int func_8001A358(Vector3D*, int);
void func_8004EF04(Vector3D*, int);
void func_8004F08C(Vector3D*, int, int);
void func_8005629C(Moby*);
void func_level_27_80076B04(Moby *moby) {
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
void func_level_27_80076E08(void *input) {
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


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007797C.
 * AI generated; not human reviewed. All2086 native instructions,42
 * absolute selectors,actual targets and symbol addends remain mandatory.
 * Parent acceptance also requires all linked EXE and overlay hashes.
 * Original frame118 saves S0..S7/FP/RA at SPF0..114. Caller stack
 * arguments use SP10..1C. Local scalar/vector homes occupy SP20..D0;
 * unused reserved fields are never read for content. No initializer was
 * invented. Primary EXE4F178/4F194/4F1C8 produce all three output words;
 * 55F14 copies A2 to T9 and both transform paths reach T9[0/4/8].
 * OwnerS4 is the parameter and privateS3 is owner+0. Saved register names
 * describe successive original roles,not simultaneous live aliases.
 * Frame,position,index,full return and table phases have explicit producers.
 * FP is the naturally allocated initialized adjusted difficulty int. The
 * decoder's false u8 FP narrowing is absent. No fixed FP/SP or incoming
 * saved value is used. No manual outgoing argument home is written.
 * The original private+78/+9C CRC work uses unsigned32 shift/XOR; byte
 * widths,short signedness,conditional paths and update order are retained.
 * All six original MULTs consume complete initialized signed64 products.
 * Compiler-local unions project full low32 or high32 words with conditional
 * MIPSEB member order. The unions never escape or describe retail memory.
 * Low32 is narrowed to signed int before its original signed shift. Short
 * trig*8000 and the *39 and *3 reductions stay in their proved int32 domain.
 * Empty metadata templates emit zero CPU instructions. Inputs are complete
 * initialized values/addresses; dead GP phase clobbers precede fresh actual
 * producers. Table selection uses its original full initialized byte; no
 * difficulty bound,alias invariant or substitute branch value is assumed.
 * The two original reset30 tails retain distinct complete value producers.
 * Shared labels own their original address/argument producers; delay-slot
 * motion follows the original graph and every actual transfer is audited.
 * Helper declarations are32-bit ABI views using void* for address words.
 * E880 has3 known formal words and F110 has2; variadic caller views retain
 * their original additional A3/A2 staging without claiming those helpers
 * consume it. Rand's old-style caller view likewise retains original
 * incidental A0 staging. Broader helper semantics remain separate evidence.
 * Allocation/caller/writer closure for external actors/private/path data,
 * units,cadence beyond invocation,Rev1 correspondence,synchronized runtime
 * captures and human review are unresolved. This source establishes native
 * original-compiler identity for this slice,not complete game behavior.
 */
extern unsigned char Level27_7797CByteC640 __asm__("D_8006C640");
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
    }
    words;
}
Level27_7797CCompleteProduct;
#define Level27_7797CField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
#define Level27_7797CCompleteValue(v) __asm__("":"=r"(v):"0"(v))
void Level27_7797C_func_80013ACC(void*,int) __asm__("func_80013ACC");
void Level27_7797C_func_80013AE4(void*,void*) __asm__("func_80013AE4");
void Level27_7797C_func_80013D44(void*,int,void*,int) __asm__("func_80013D44");
int Level27_7797C_func_8001A358(void*,int) __asm__("func_8001A358");
void Level27_7797C_func_80021ED8(int,int,int) __asm__("func_80021ED8");
int Level27_7797C_func_8002803C(int,int,void*,void*,void*,void*,int) __asm__("func_8002803C");
int Level27_7797C_func_80028154(int) __asm__("func_80028154");
void Level27_7797C_func_80034F40(void*,int) __asm__("func_80034F40");
int Level27_7797C_func_80035194(void*,void*) __asm__("func_80035194");
void Level27_7797C_func_80035734(void*) __asm__("func_80035734");
int Level27_7797C_func_8003573C(void*,int,int,int) __asm__("func_8003573C");
int Level27_7797C_func_8003585C(void*,int,int,int,int,int) __asm__("func_8003585C");
int Level27_7797C_func_800359A4(void*,int) __asm__("func_800359A4");
int Level27_7797C_func_80035DDC(void*,int,int,int,int) __asm__("func_80035DDC");
int Level27_7797C_func_8003636C(int,int) __asm__("func_8003636C");
int Level27_7797C_func_800363DC(int,int) __asm__("func_800363DC");
void Level27_7797C_func_800369B8(void*,int) __asm__("func_800369B8");
void Level27_7797C_func_80038F14(void*,void*,unsigned int,int) __asm__("func_80038F14");
void Level27_7797C_func_8003B7B4(void*,int,void*) __asm__("func_8003B7B4");
void Level27_7797C_func_8003BA00(void*) __asm__("func_8003BA00");
int Level27_7797C_func_8003BB10(void*,int,int) __asm__("func_8003BB10");
void Level27_7797C_func_8003BE70(int) __asm__("func_8003BE70");
int Level27_7797C_func_8003BFC0(void*,int) __asm__("func_8003BFC0");
int Level27_7797C_func_8004E880(int,int,int,...) __asm__("func_8004E880");
int Level27_7797C_func_8004EDE8(void*,int) __asm__("func_8004EDE8");
void Level27_7797C_func_8004F08C(void*,int,int) __asm__("func_8004F08C");
void Level27_7797C_func_8004F110(void*,int,...) __asm__("func_8004F110");
void Level27_7797C_func_8004F178(void*,void*) __asm__("func_8004F178");
void Level27_7797C_func_8004F194(void*,void*,void*) __asm__("func_8004F194");
void Level27_7797C_func_8004F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Level27_7797C_func_8004F264(int,int) __asm__("func_8004F264");
int Level27_7797C_func_8004F334(void*,void*) __asm__("func_8004F334");
void Level27_7797C_func_80055B18(void*) __asm__("func_80055B18");
void Level27_7797C_func_80055D24(void*,int) __asm__("func_80055D24");
int Level27_7797C_func_80055E84(void*) __asm__("func_80055E84");
void Level27_7797C_func_80055F14(void*,int,void*) __asm__("func_80055F14");
int Level27_7797C_rand() __asm__("rand");
extern int Level27_7797C_D_8006580C __asm__("D_8006580C");
extern int Level27_7797C_D_80065834 __asm__("D_80065834");
extern int Level27_7797C_D_800658A0 __asm__("D_800658A0");
extern int Level27_7797C_D_80065920 __asm__("D_80065920");
extern signed char Level27_7797C_D_8006C408 __asm__("D_8006C408");
extern unsigned char Level27_7797C_D_8006C409 __asm__("D_8006C409");
extern int Level27_7797C_D_8006C58C __asm__("D_8006C58C");
extern int Level27_7797C_D_8006C640 __asm__("D_8006C640");
extern int Level27_7797C_D_8006C770 __asm__("D_8006C770");
extern int Level27_7797C_D_8006C7C4 __asm__("D_8006C7C4");
extern int Level27_7797C_D_8006C7F8 __asm__("D_8006C7F8");
extern int Level27_7797C_D_8006D088 __asm__("D_8006D088");
extern int Level27_7797C_D_8006E048 __asm__("D_8006E048");
extern int Level27_7797C_D_8006E1D4 __asm__("D_8006E1D4");
extern int Level27_7797C_D_8006E1D8 __asm__("D_8006E1D8");
extern int Level27_7797C_D_8006E788 __asm__("D_8006E788");
extern int Level27_7797C_D_80070328 __asm__("D_80070328");
extern unsigned char Level27_7797C_D_8007158D __asm__("D_8007158D");
extern int Level27_7797C_D_level_27_80089BE0 __asm__("D_level_27_80089BE0");
extern int (*Level27_7797C_SpawnMoby)() __asm__("SpawnMoby");
extern int (*Level27_7797C_SpawnParticle)() __asm__("SpawnParticle");
extern int Level27_7797C_func_level_27_80074DEC __asm__("func_level_27_80074DEC");
extern int Level27_7797C_main_TEXT_END __asm__("main_TEXT_END");
extern int Level27_7797C_main_TEXT_START __asm__("main_TEXT_START");
extern int Level27_7797C_unk_ovlheader_80074364 __asm__("unk_ovlheader_80074364");
extern int Level27_7797C_unk_ovlheader_80074368 __asm__("unk_ovlheader_80074368");
extern int Level27_7797C_unk_ovlheader_8007436C __asm__("unk_ovlheader_8007436C");
void func_level_27_8007797C(void* ownerParameter) {
    register int indexPositionOrFlags16 __asm__("$16"),positionOrOutput17 __asm__("$17"),cursorOrVector18 __asm__("$18"),private19 __asm__("$19"),owner20 __asm__("$20"),scoreTableOrVector21 __asm__("$21"),modeOrTable22 __asm__("$22"),classOrTable23 __asm__("$23");
    register int resultOrField2 __asm__("$2"),fieldOrArithmetic3 __asm__("$3"),argumentOrField4 __asm__("$4"),argumentOrField5 __asm__("$5"),argumentOrField6 __asm__("$6"),argumentOrField7 __asm__("$7");
    struct {
        int sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4,spB8,spBC,spC0,spC4,spC8,spCC,spD0,spD4,spD8,spDC,spE0,spE4,spE8,spEC;
    }
    originalFrame;
    Level27_7797CCompleteProduct ratioProduct,vectorProduct0,vectorProduct1,vectorProduct2,cosProduct,sinProduct;
    register int vectorFirstLow6 __asm__("$6"),vectorSecondLow3 __asm__("$3"),cosineLow9 __asm__("$9"),sineLow8 __asm__("$8"),frameSnapshot8 __asm__("$8"),frameSnapshot9 __asm__("$9"),ratioHighWord9 __asm__("$9"),firstLow10 __asm__("$10"),secondLow9 __asm__("$9"),vectorThirdLow10 __asm__("$10"),cosLow3 __asm__("$3"),sinLow3 __asm__("$3");
    int var_a1_3;
    int resetTimerThirty;
    int temp_a0;
    int temp_a0_3;
    int temp_a1_2;
    int temp_a1_3;
    int temp_v0_12;
    int temp_v0_16;
    int temp_a0_2;
    int temp_a0_6;
    int temp_v0;
    int temp_v0_8;
    int privateSubmode90;
    int resetPredicate;
    int var_v0_7;
    int var_v1;
    int var_v0_3;
    int temp_v0_10;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_9;
    int temp_v1_6;
    int stateByte49;
    int adjustedDifficulty;
    int temp_a0_7;
    int temp_v0_14;
    int temp_v0_15;
    int spawnedOwner;
    int temp_v1_7;
    owner20=(int)ownerParameter;
    Level27_7797CCompleteValue(owner20);
    indexPositionOrFlags16=owner20+12;
    originalFrame.spC0 = 0;
    private19 = Level27_7797CField(owner20, int*, 0);
    originalFrame.spC8 = Level27_7797C_func_8004F334((void*)(indexPositionOrFlags16),(void*)( (int)&Level27_7797C_D_80070328));
    resultOrField2=Level27_7797C_func_8004F334((void*)(indexPositionOrFlags16),(void*)(private19));
    adjustedDifficulty=Level27_7797C_D_8006C409;
    fieldOrArithmetic3=Level27_7797C_D_8006C7C4;
    modeOrTable22=2;
    originalFrame.spD0=resultOrField2;
    if(fieldOrArithmetic3==modeOrTable22){
        adjustedDifficulty-=4;
        if(adjustedDifficulty<0)adjustedDifficulty=0;
    }
    else if(fieldOrArithmetic3==1){
        adjustedDifficulty+=2;
    }
    else if(fieldOrArithmetic3==0){
        adjustedDifficulty+=5;
    }
    if (Level27_7797C_D_8007158D != 0) {
        adjustedDifficulty = 0;
    }
    if ((int) adjustedDifficulty <= 0) {
        modeOrTable22 = 3;
    }
    if ((unsigned int) (Level27_7797CField((int)&Level27_7797C_D_80070328, int *, 0x50) - 7) < 2U) {
        Level27_7797CField(private19, short *, 0x46) = 0;
    }
    if (Level27_7797CField(private19, int *, 0x2C) == 0) {
        Level27_7797CField(private19, int *, 0x2C) = 1;
        Level27_7797CField(private19, int *, 0x30) = modeOrTable22;
        Level27_7797CField(private19, int *, 0x34) = (int) (modeOrTable22 * 3);
        Level27_7797C_func_80013ACC((void*)(owner20), 0xD);
        if (Level27_7797CField(private19, int *, 0x80) < 0) {
            Level27_7797CField(private19,int*,128)=(short)Level27_7797C_func_8002803C(0x17, 0x10E,(void*)( Level27_7797C_unk_ovlheader_80074368),(void*)( Level27_7797C_unk_ovlheader_8007436C),(void*)( Level27_7797C_unk_ovlheader_80074364),(void*)( private19 + 0x34), Level27_7797CField(private19, int *, 0x34));
        }
    }
    resultOrField2=Level27_7797CField(private19,volatile int*,120);
    fieldOrArithmetic3=(int)&Level27_7797C_func_level_27_80074DEC;
    resultOrField2=(unsigned int)resultOrField2<(unsigned int)fieldOrArithmetic3;
    indexPositionOrFlags16=private19+120;
    if(!resultOrField2){
        __asm__ volatile(""::"r"(private19):"$2");
        argumentOrField5=0;
        argumentOrField6=(int)&Level27_7797C_D_level_27_80089BE0;
        Level27_7797CCompleteValue(argumentOrField6);
    actor2086OverlayCRC:
        /* Original incremental overlay-byte CRC; complete unsigned32 shift and XOR values. */
        fieldOrArithmetic3=Level27_7797CField(private19,volatile int*,120);
        resultOrField2=(unsigned int)fieldOrArithmetic3<(unsigned int)argumentOrField6;
        if(resultOrField2){
            argumentOrField4=0;
            resultOrField2=Level27_7797CField(fieldOrArithmetic3,unsigned char*,0);
            fieldOrArithmetic3=Level27_7797CField(private19,volatile int*,156);
            resultOrField2<<=8;
            fieldOrArithmetic3^=resultOrField2;
            Level27_7797CField(private19,volatile int*,156)=fieldOrArithmetic3;
            do{
                fieldOrArithmetic3=Level27_7797CField(private19,volatile int*,156);
                if(fieldOrArithmetic3&0x8000)resultOrField2=((unsigned int)fieldOrArithmetic3<<1)^0x8005U;
                else resultOrField2=(unsigned int)fieldOrArithmetic3<<1;
                Level27_7797CField(private19,volatile int*,156)=resultOrField2;
                argumentOrField4++;
            }
            while(argumentOrField4<8);
            resultOrField2=Level27_7797CField(private19,volatile int*,120);
            argumentOrField5++;
            resultOrField2++;
            Level27_7797CField(private19,volatile int*,120)=resultOrField2;
            if(argumentOrField5<64)goto actor2086OverlayCRC;
        }
        __asm__ volatile("":"=r"(private19):"0"(private19):"memory");
        indexPositionOrFlags16=private19+120;
    }
    Level27_7797C_func_8003B7B4((void*)(indexPositionOrFlags16), 4,(void*)( (int)&Level27_7797C_D_8006D088));
    Level27_7797C_func_8003B7B4((void*)(indexPositionOrFlags16), 4,(void*)( (int)&Level27_7797C_D_8006C7F8));
    indexPositionOrFlags16 = private19 + 0x9C;
    Level27_7797C_func_8003B7B4((void*)(indexPositionOrFlags16), 4,(void*)( (int)&Level27_7797C_D_8006D088));
    Level27_7797C_func_8003B7B4((void*)(indexPositionOrFlags16), 4,(void*)( (int)&Level27_7797C_D_8006C7F8));
    if (Level27_7797CField(private19, int *, 0x38) == 0) {
        if (((Level27_7797CField(owner20, int *, 0x18) != 0) || (Level27_7797CField((int)&Level27_7797C_D_80070328, int *, 0x50) != 0)) && (Level27_7797CField((int)&Level27_7797C_D_80070328, int *, 0x240) == 0)) {
            Level27_7797CField(private19, short *, 0x4C) = 0x1E;
            Level27_7797CField(private19, int *, 0x38) = 1;
            Level27_7797C_func_80013ACC((void*)(owner20), 0xD);
        }
    }
    else {
        if ((Level27_7797CField(private19, unsigned int *, 0x78) == (int)&Level27_7797C_D_level_27_80089BE0) && (Level27_7797CField(private19, int *, 0x9C) != 0)) {
            Level27_7797C_D_8006580C = 1;
            Level27_7797C_D_80065834 = 1;
            Level27_7797CField(private19, int *, 0x9C) = 0;
        }
        if (Level27_7797CField(private19, short *, 0x48) == 0) {
            scoreTableOrVector21=0x05F5E0FF;
            cursorOrVector18=(int)&Level27_7797C_D_8006E788;
            Level27_7797CCompleteValue(cursorOrVector18);
            indexPositionOrFlags16=Level27_7797CField(cursorOrVector18,int*,0);
            cursorOrVector18+=4;
            __asm__("":"=r"(cursorOrVector18):"0"(cursorOrVector18):"$23");
            classOrTable23=60;
            if(indexPositionOrFlags16){
                do {
                    if ((Level27_7797CField(indexPositionOrFlags16, short *, 0x36) == 0x280) && (Level27_7797CField(Level27_7797CField(indexPositionOrFlags16, int *, 0), short *, 8) > classOrTable23) && (Level27_7797CField(indexPositionOrFlags16, unsigned char *, 0x48) == 0)) {
                        temp_v0 = Level27_7797C_func_8004F334((void*)(owner20 + 0xC),(void*)( indexPositionOrFlags16 + 0xC));
                        if (temp_v0 >= 0xBB9) {
                            positionOrOutput17 = temp_v0 + (Level27_7797C_func_8004F264(Level27_7797C_func_8004E880(Level27_7797CField(indexPositionOrFlags16, int *, 0xC) - Level27_7797CField(owner20, int *, 0xC), Level27_7797CField(indexPositionOrFlags16, int *, 0x10) - Level27_7797CField(owner20, int *, 0x10), 0), Level27_7797CField(owner20, unsigned char *, 0x46)) << 6);
                            if (positionOrOutput17 < scoreTableOrVector21) {
                                originalFrame.spC0 = indexPositionOrFlags16;
                                scoreTableOrVector21 = positionOrOutput17;
                            }
                        }
                    }
                    indexPositionOrFlags16 = Level27_7797CField(cursorOrVector18,int*,0);
                    cursorOrVector18 += 4;
                }
                while (indexPositionOrFlags16 != 0);
            }
        }
        resultOrField2=Level27_7797CField(private19,volatile int*,120);
        if(!resultOrField2){
            Level27_7797CField(private19,volatile int*,120)=Level27_7797C_D_8006C58C+((int)&Level27_7797C_main_TEXT_START+2);
            resultOrField2=Level27_7797CField(private19,volatile int*,120);
        }
        fieldOrArithmetic3=(int)&Level27_7797C_main_TEXT_END;
        Level27_7797CCompleteValue(fieldOrArithmetic3);
        argumentOrField5=0;
        if((unsigned int)resultOrField2<(unsigned int)fieldOrArithmetic3){
            argumentOrField6=fieldOrArithmetic3;
            Level27_7797CCompleteValue(argumentOrField6);
        actor2086MainCRC:
            fieldOrArithmetic3=Level27_7797CField(private19,volatile int*,120);
            if((unsigned int)fieldOrArithmetic3<(unsigned int)argumentOrField6){
                argumentOrField4=0;
                resultOrField2=Level27_7797CField(fieldOrArithmetic3,unsigned char*,0);
                fieldOrArithmetic3=Level27_7797CField(private19,volatile int*,156);
                resultOrField2<<=8;
                fieldOrArithmetic3^=resultOrField2;
                Level27_7797CField(private19,volatile int*,156)=fieldOrArithmetic3;
                do{
                    fieldOrArithmetic3=Level27_7797CField(private19,volatile int*,156);
                    if(fieldOrArithmetic3&0x8000)resultOrField2=((unsigned int)fieldOrArithmetic3<<1)^0x8005U;
                    else resultOrField2=(unsigned int)fieldOrArithmetic3<<1;
                    Level27_7797CField(private19,volatile int*,156)=resultOrField2;
                    argumentOrField4++;
                }
                while(argumentOrField4<8);
                argumentOrField5++;
                resultOrField2=Level27_7797CField(private19,volatile int*,156);
                fieldOrArithmetic3=Level27_7797CField(private19,volatile int*,120);
                resultOrField2&=3;
                resultOrField2++;
                fieldOrArithmetic3+=resultOrField2;
                Level27_7797CField(private19,int*,120)=fieldOrArithmetic3;
                if(argumentOrField5<64)goto actor2086MainCRC;
                resultOrField2=(int)&Level27_7797C_main_TEXT_END;
                Level27_7797CCompleteValue(resultOrField2);
                if((unsigned int)fieldOrArithmetic3<(unsigned int)resultOrField2){
                    argumentOrField4=private19+76;
                    goto actor2086FirstTimer;
                }
            }
            Level27_7797CField(private19,volatile int*,120)=(int)&Level27_7797C_func_level_27_80074DEC;
        }
        argumentOrField4=private19+76;
        actor2086FirstTimer:Level27_7797C_func_800359A4((void*)(argumentOrField4),2);
        Level27_7797C_func_800359A4((void*)(private19 + 0x48), 2);
        Level27_7797C_func_800359A4((void*)(private19 + 0x3C), 2);
        if (Level27_7797CField(private19, short *, 0x3C) == 0) {
            if (Level27_7797CField(owner20, int *, 0x18) & 0x100000) {
                temp_v1_6 = Level27_7797CField(owner20, unsigned char *, 0x48);
                if (temp_v1_6 != 2) {
                    if (temp_v1_6 != 0xB) {
                        Level27_7797CField(private19, short *, 0x3E) = 0;
                        Level27_7797CField(private19, int *, 0x30) = (int) (Level27_7797CField(private19, int *, 0x30) - 1);
                        Level27_7797CField(private19, int *, 0x34) = (int) (Level27_7797CField(private19, int *, 0x34) - 1);
                        if ((Level27_7797CField((int)&Level27_7797C_D_80070328, int *, 0x170) == 8) && (Level27_7797CField((int)&Level27_7797C_D_80070328, int *, 0x178) < 0x46)) {
                            Level27_7797CField((int)&Level27_7797C_D_80070328, int *, 0x178) = 0x46;
                        }
                        temp_v1_7 = Level27_7797CField(private19, int*, 0x54);
                        if (temp_v1_7 != 0) {
                            temp_a0 = Level27_7797CField(temp_v1_7, short *, 0x36);
                            if (temp_a0 == 0x182) {
                                Level27_7797CField(Level27_7797CField(temp_v1_7, int*, 0), short *, 0x14) = 0;
                            }
                            else if (temp_a0 == 0x3E0) {
                                Level27_7797CField(Level27_7797CField(temp_v1_7, int*, 0), int *, 0x10) = 0;
                            }
                        }
                        if (Level27_7797CField(private19, int *, 0x30) <= 0) {
                            Level27_7797CField(private19, int *, 0x30) = modeOrTable22;
                            resultOrField2=Level27_7797CField(private19,int*,40);
                            resultOrField2++;
                            Level27_7797CField(private19,int*,40)=resultOrField2;
                            fieldOrArithmetic3=Level27_7797CField(private19,volatile int*,40);
                            resultOrField2=1;
                            if(fieldOrArithmetic3==resultOrField2){
                                cursorOrVector18 = 0;
                                positionOrOutput17 = 0;
                                indexPositionOrFlags16 = private19;
                                do {
                                    Level27_7797CField(indexPositionOrFlags16, int *, 0x60) = (int) (positionOrOutput17 + Level27_7797C_func_8003636C(0, 0x5A));
                                    positionOrOutput17 += 0x78;
                                    cursorOrVector18 += 1;
                                    indexPositionOrFlags16 += 4;
                                }
                                while (cursorOrVector18 < 3);
                                Level27_7797CField(owner20, unsigned char *, 0x49) = 0U;
                            }
                            if (Level27_7797CField(private19, int *, 0x34) <= 0) {
                                Level27_7797C_func_80038F14((void*)(owner20),(void*)( private19 + 0xC), 1, 0xB);
                                Level27_7797CField(private19, short *, 0x10) = 0x140;
                                Level27_7797CField(private19, signed char *, 0x1A) = 9;
                                temp_a0_2 = Level27_7797CField(private19, int *, 0x80);
                                Level27_7797CField(private19, signed char *, 0x1F) = 0;
                                Level27_7797CField(private19, short *, 0x12) = 0;
                                Level27_7797CField(private19, int *, 0x94) = 5;
                                if (temp_a0_2 != -1) {
                                    Level27_7797C_func_80028154(temp_a0_2);
                                }
                                argumentOrField4=owner20;
                                var_a1_3=11;
                                var_v0_3 = 0xB;
                                Level27_7797CField(private19, int *, 0x80) = -1;
                                goto block_185;
                            }
                            goto block_76;
                        }
                    block_76:
                        Level27_7797CField(private19, short *, 0x3C) = 0x78;
                        Level27_7797CField(private19, short *, 0x4C) = 0;
                        Level27_7797C_func_80038F14((void*)(owner20),(void*)( private19 + 0xC), 1, 2);
                        Level27_7797CField(private19, short *, 0x10) = 0x140;
                        Level27_7797CField(private19, signed char *, 0x1F) = 0;
                        Level27_7797CField(private19, short *, 0x12) = 0;
                        Level27_7797CField(private19, signed char *, 0x1A) = 9;
                        Level27_7797CField(owner20, signed char *, 0x51) = 0;
                        goto block_77;
                    }
                    goto block_78;
                }
            }
        block_77:
            goto block_78;
        }
    block_78:
        resultOrField2=(int)0x91A2B3C5U;
        frameSnapshot8=*(volatile int*)&originalFrame.spC8;
        ratioProduct.full=(long long)frameSnapshot8*(long long)resultOrField2;
        __asm__("":"=x"(ratioProduct.full):"0"(ratioProduct.full),"r"(resultOrField2),"r"(frameSnapshot8));
        argumentOrField4=(int)&originalFrame.sp20;
        __asm__ volatile(""::"r"(argumentOrField4):"$17");
        positionOrOutput17=(int)&Level27_7797C_D_80070328+152;
        argumentOrField5=positionOrOutput17;
        __asm__ volatile(""::"r"(argumentOrField4),"r"(argumentOrField5):"memory");
        Level27_7797CField(owner20,int*,24)=0;
        __asm__ volatile(""::"r"(argumentOrField4),"r"(argumentOrField5):"$2","memory");
        resultOrField2=frameSnapshot8>>31;
        ratioHighWord9=ratioProduct.words.high;
        Level27_7797CCompleteValue(ratioHighWord9);
        indexPositionOrFlags16=ratioHighWord9+frameSnapshot8;
        indexPositionOrFlags16>>=8;
        indexPositionOrFlags16-=resultOrField2;
        Level27_7797CCompleteValue(indexPositionOrFlags16);
        indexPositionOrFlags16*=2;
        Level27_7797C_func_8004F178((void*)(argumentOrField4),(void*)(positionOrOutput17));
        resultOrField2=originalFrame.sp20;
        Level27_7797CCompleteValue(resultOrField2);
        vectorProduct0.full=(long long)resultOrField2*(long long)indexPositionOrFlags16;
        __asm__("":"=x"(vectorProduct0.full):"0"(vectorProduct0.full));
        vectorFirstLow6=(int)vectorProduct0.words.low;
        resultOrField2=originalFrame.sp24;
        __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(vectorFirstLow6));
        vectorProduct1.full=(long long)resultOrField2*(long long)indexPositionOrFlags16;
        __asm__("":"=x"(vectorProduct1.full):"0"(vectorProduct1.full));
        vectorSecondLow3=(int)vectorProduct1.words.low;
        resultOrField2=originalFrame.sp28;
        __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(vectorSecondLow3));
        vectorProduct2.full=(long long)resultOrField2*(long long)indexPositionOrFlags16;
        argumentOrField4=(int)&originalFrame.sp20;
        argumentOrField5=6;
        originalFrame.sp20=vectorFirstLow6;
        originalFrame.sp24=vectorSecondLow3;
        __asm__ volatile("":"=x"(vectorProduct2.full):"0"(vectorProduct2.full),"r"(argumentOrField4),"r"(argumentOrField5):"memory");
        vectorThirdLow10=(int)vectorProduct2.words.low;
        Level27_7797CCompleteValue(vectorThirdLow10);
        originalFrame.sp28=vectorThirdLow10;
        Level27_7797C_func_8004F110((void*)(argumentOrField4),argumentOrField5,vectorFirstLow6);
        Level27_7797C_func_8004F194((void*)(&originalFrame.sp20),(void*)( &originalFrame.sp20),(void*)( positionOrOutput17 - 0x98));
        Level27_7797C_func_8004E880(originalFrame.sp20 - Level27_7797CField(owner20, int *, 0xC), originalFrame.sp24 - Level27_7797CField(owner20, int *, 0x10), 0);
        if (Level27_7797CField((int)&Level27_7797C_D_80070328, int *, 0x170) == 8) {
            if (Level27_7797CField(private19, int *, 0xA0) == -1) {
                Level27_7797C_func_8003BB10((void*)(owner20), 7, 1);
            }
            if (Level27_7797C_func_8003BFC0((void*)(owner20), Level27_7797CField(private19, int *, 0xA0)) == 0) {
                Level27_7797CField(private19, int *, 0xA0) = Level27_7797C_func_8003BB10((void*)(owner20), 8, 5);
            }
        }
        else {
            if (Level27_7797C_func_8003BFC0((void*)(owner20), Level27_7797CField(private19, int *, 0xA0)) != 0) {
                Level27_7797C_func_8003BE70(Level27_7797CField(private19, int *, 0xA0));
            }
            Level27_7797CField(private19, int *, 0xA0) = -1;
        }
        resultOrField2=Level27_7797CField(private19,int*,40);
        if(resultOrField2<=0)goto actor2086DispatchReload;
        fieldOrArithmetic3=Level27_7797CField(owner20,unsigned char*,72);
        if(fieldOrArithmetic3==15)goto actor2086DispatchReload;
        resultOrField2=11;
        if(fieldOrArithmetic3==resultOrField2)goto actor2086DispatchReady;
        modeOrTable22=0;
        classOrTable23=990;
        do{
            indexPositionOrFlags16=modeOrTable22*4;
            argumentOrField4=indexPositionOrFlags16+96;
            argumentOrField4=private19+argumentOrField4;
            resultOrField2=Level27_7797C_func_800359A4((void*)(argumentOrField4),4);
            if(resultOrField2){
                positionOrOutput17=Level27_7797C_SpawnMoby(990,owner20);
                if(positionOrOutput17){
                    scoreTableOrVector21=0;
                    resultOrField2=Level27_7797C_func_8003636C(360,600);
                    fieldOrArithmetic3=indexPositionOrFlags16+private19;
                    Level27_7797CField(fieldOrArithmetic3,int*,96)=resultOrField2;
                actor2086Attempt:
                    /* Original bounded retry entry; S5 counts attempts while S0 becomes the actor-list cursor. */
                    resultOrField2=scoreTableOrVector21<14;
                    if(!resultOrField2)goto actor2086NextSpawn;
                    argumentOrField4=0;
                    __asm__ volatile(""::"r"(argumentOrField4):"memory");
                    resultOrField2=Level27_7797CField(private19,int*,36);
                    argumentOrField5=Level27_7797CField(resultOrField2,short*,0);
                    __asm__ volatile("":::"$18","memory");
                    cursorOrVector18=1;
                    resultOrField2=Level27_7797C_func_8003636C(argumentOrField4,argumentOrField5-1);
                    fieldOrArithmetic3=Level27_7797CField(private19,int*,36);
                    argumentOrField4=positionOrOutput17+12;
                    argumentOrField5=Level27_7797CField(fieldOrArithmetic3,int*,12);
                    resultOrField2*=16;
                    Level27_7797C_func_8004F178((void*)(argumentOrField4),(void*)(argumentOrField5+resultOrField2));
                    resultOrField2=Level27_7797CField(positionOrOutput17,int*,20);
                    indexPositionOrFlags16=(int)&Level27_7797C_D_8006E788;
                    resultOrField2-=50;
                    Level27_7797CField(positionOrOutput17,int*,20)=resultOrField2;
                    while((argumentOrField5=Level27_7797CField(indexPositionOrFlags16,int*,0),indexPositionOrFlags16+=4,argumentOrField5)){
                        resultOrField2=Level27_7797CField(argumentOrField5,short*,54);
                        if(resultOrField2==classOrTable23&&Level27_7797C_func_8004F334((void*)(positionOrOutput17+12),(void*)(argumentOrField5+12))<7168)cursorOrVector18=0;
                    }
                    scoreTableOrVector21++;
                    if(!cursorOrVector18)goto actor2086Attempt;
                }
            }
            actor2086NextSpawn:modeOrTable22++;
        }
        while(modeOrTable22<3);
    actor2086DispatchReload:
        /* Refresh the original full byte selector after timer/spawn work. */fieldOrArithmetic3=Level27_7797CField(owner20,unsigned char*,72);
    actor2086DispatchReady:
        /* The original42-entry table includes its actual default paths. */
        switch(fieldOrArithmetic3){
            default:goto block_346;
        case 15:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            if ((Level27_7797C_func_80055E84((void*)(owner20)) >= 0x1B) && (Level27_7797CField(owner20, unsigned char *, 0x49) == 0)) {
                Level27_7797CField(owner20, unsigned char *, 0x49) = 1U;
                Level27_7797C_D_8006E1D4 = 0x1388;
                if (Level27_7797C_D_8006E1D8 < 0x3C) {
                    Level27_7797C_D_8006E1D8 = 0x3C;
                }
                Level27_7797C_func_80021ED8(0, 0xFC, 0);
                Level27_7797C_func_8003BB10((void*)(owner20), 5, 1);
                cursorOrVector18=(int)&Level27_7797C_D_8006E788;
                Level27_7797CCompleteValue(cursorOrVector18);
                positionOrOutput17=Level27_7797CField(cursorOrVector18,int*,0);
                cursorOrVector18+=4;
                if (positionOrOutput17 != 0) {
                    do {
                        if ((Level27_7797CField(positionOrOutput17, short *, 0x36) == 0x27F) && (Level27_7797CField(positionOrOutput17, unsigned char *, 0x48) == 0)) {
                            indexPositionOrFlags16 = Level27_7797CField(positionOrOutput17, int *, 0);
                            Level27_7797CField(indexPositionOrFlags16, int *, 8) = Level27_7797C_func_8003636C(0xC8, 0xE6);
                            Level27_7797CField(positionOrOutput17, unsigned char *, 0x48) = 0xEU;
                        }
                        positionOrOutput17 = Level27_7797CField(cursorOrVector18,int*,0);
                        cursorOrVector18 += 4;
                    }
                    while (positionOrOutput17 != 0);
                }
                fieldOrArithmetic3=Level27_7797CField(private19,int*,36);
                resultOrField2=Level27_7797CField(fieldOrArithmetic3,short*,0);
                indexPositionOrFlags16=0;
                if(resultOrField2>0){
                    positionOrOutput17=(int)&originalFrame.sp30;
                    argumentOrField4=positionOrOutput17;
                    do{
                        resultOrField2=Level27_7797CField(fieldOrArithmetic3,int*,12);
                        argumentOrField5=indexPositionOrFlags16*16;
                        Level27_7797C_func_8004F178((void*)(argumentOrField4),(void*)(resultOrField2+argumentOrField5));
                        originalFrame.sp40=0;
                        originalFrame.sp44=0;
                        originalFrame.sp48=Level27_7797C_func_8003636C(12,20);
                        Level27_7797C_SpawnParticle(1,0,positionOrOutput17,&originalFrame.sp40);
                        fieldOrArithmetic3=Level27_7797CField(private19,int*,36);
                        resultOrField2=Level27_7797CField(fieldOrArithmetic3,short*,0);
                        __asm__ volatile("":"=r"(indexPositionOrFlags16):"0"(indexPositionOrFlags16):"memory");
                        indexPositionOrFlags16++;
                        argumentOrField4=positionOrOutput17;
                    }
                    while(indexPositionOrFlags16<resultOrField2);
                }
            }
        case 14:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            if (Level27_7797C_D_8006C770 != 0) {
                Level27_7797CField(owner20, unsigned char *, 0x48) = 0U;
                goto block_330;
            }
            goto block_347;
        case 33:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            if (Level27_7797CField(owner20, unsigned char *, 0x3D) != 1) {
                Level27_7797C_D_8006C770 = 0;
                Level27_7797CField(owner20, signed char *, 0x40) = 0x72;
                Level27_7797CField(owner20, unsigned char *, 0x3D) = 1U;
                Level27_7797CField(owner20, signed char *, 0x3F) = 0;
                Level27_7797C_func_80035734((void*)(owner20));
            }
            if (Level27_7797C_func_8003585C((void*)(owner20), Level27_7797C_func_8004E880(Level27_7797CField(private19, int *, 0) - Level27_7797CField(owner20, int *, 0xC), Level27_7797CField(private19, int *, 4) - Level27_7797CField(owner20, int *, 0x10), 0), 5, 0x14, 1, 0) != 0) {
                temp_v0_3 = Level27_7797CField(private19, unsigned short *, 0x4A) + 0xF;
                Level27_7797CField(private19, unsigned short *, 0x4A) = temp_v0_3;
                if ((short) temp_v0_3 >= 0xF1) {
                    Level27_7797CField(private19, unsigned short *, 0x4A) = 0xF0U;
                }
                Level27_7797C_func_80035DDC((void*)(owner20), (short) Level27_7797CField(private19, unsigned short *, 0x4A), 0, 0, 5);
                resetPredicate = Level27_7797C_func_8004F334((void*)(owner20 + 0xC),(void*)( private19)) < 0x200;
                goto block_147;
            }
            goto block_347;
        case 32:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            stateByte49 = Level27_7797CField(owner20, unsigned char *, 0x49);
            switch(stateByte49){
                default:goto block_347;
            case 0:
                if (Level27_7797CField(owner20, unsigned char *, 0x3D) != 1) {
                    Level27_7797C_D_8006C770 = 0;
                    Level27_7797CField(owner20, signed char *, 0x40) = 0x72;
                    Level27_7797CField(owner20, unsigned char *, 0x3D) = 1U;
                    Level27_7797CField(owner20, signed char *, 0x3F) = 0;
                    Level27_7797C_func_80035734((void*)(owner20));
                }
                temp_a1_2 = Level27_7797CField(private19, int*, 0x74);
                if ((temp_a1_2 != 0) && (Level27_7797CField(temp_a1_2, unsigned char *, 0x48) == 0) && (Level27_7797CField(temp_a1_2, short *, 0x36) == 0x27F)) {
                    if (Level27_7797C_func_8003585C((void*)(owner20), Level27_7797C_func_8004E880(Level27_7797CField(temp_a1_2, int *, 0xC) - Level27_7797CField(owner20, int *, 0xC), Level27_7797CField(temp_a1_2, int *, 0x10) - Level27_7797CField(owner20, int *, 0x10), 0), 5, 0x14, 1, 0) != 0) {
                        temp_v0_4 = Level27_7797CField(private19, unsigned short *, 0x4A) + 0xF;
                        Level27_7797CField(private19, unsigned short *, 0x4A) = temp_v0_4;
                        if ((short) temp_v0_4 >= 0xF1) {
                            Level27_7797CField(private19, unsigned short *, 0x4A) = 0xF0U;
                        }
                        Level27_7797C_func_80035DDC((void*)(owner20), (short) Level27_7797CField(private19, unsigned short *, 0x4A), 0, 0, 5);
                        if (Level27_7797C_func_8004F334((void*)(owner20 + 0xC),(void*)( Level27_7797CField(private19, int*, 0x74) + 0xC)) < 0xBB8) {
                            if (Level27_7797CField(owner20, unsigned char *, 0x3D) != 9) {
                                Level27_7797C_D_8006C770 = 0;
                                Level27_7797CField(owner20, signed char *, 0x40) = 0x72;
                                Level27_7797CField(owner20, unsigned char *, 0x3D) = 9U;
                                Level27_7797CField(owner20, signed char *, 0x3F) = 0;
                                Level27_7797C_func_80035734((void*)(owner20));
                            }
                            Level27_7797CField(owner20, unsigned char *, 0x49) = (unsigned char) (Level27_7797CField(owner20, unsigned char *, 0x49) + 1);
                        }
                    }
                    goto block_347;
                }
                goto block_148;
            case 1:
                if (Level27_7797C_func_80055E84((void*)(owner20)) >= 0xA) {
                    temp_a0_3 = Level27_7797CField(private19, int*, 0x74);
                    if ((temp_a0_3 != 0) && (Level27_7797CField(temp_a0_3, unsigned char *, 0x48) == 0) && (Level27_7797CField(temp_a0_3, short *, 0x36) == 0x27F)) {
                        Level27_7797CField(temp_a0_3, unsigned char *, 0x48) = 0xBU;
                    }
                }
                resetPredicate=Level27_7797C_D_8006C770;
                block_147:if(!resetPredicate)goto block_347;
                block_148:Level27_7797CField(owner20,unsigned char*,72)=0;
                Level27_7797C_func_80034F40((void*)(owner20),0);
                __asm__ volatile(""::"r"(owner20):"memory");
                return;
            }
            break;
        case 0:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            indexPositionOrFlags16 = Level27_7797CField(owner20, unsigned char *, 0x3C) == 0;
            Level27_7797C_func_8003573C((void*)(owner20), 5, 0, 0);
            if (indexPositionOrFlags16 == 0) {
                if (Level27_7797CField(owner20, unsigned char *, 0x3D) != 0) {
                    Level27_7797C_D_8006C770 = 0;
                    Level27_7797CField(owner20, signed char *, 0x40) = 0x72;
                    Level27_7797CField(owner20, unsigned char *, 0x3D) = 0U;
                    Level27_7797CField(owner20, signed char *, 0x3F) = 0;
                    Level27_7797C_func_80035734((void*)(owner20));
                    return;
                }
            }
            else {
                if (Level27_7797CField(private19, int *, 0x70) == 1) {
                    Level27_7797CField(private19, int *, 0x70) = 0;
                    frameSnapshot8=originalFrame.spD0;
                    Level27_7797CCompleteValue(frameSnapshot8);
                    resultOrField2=frameSnapshot8<5121;
                    Level27_7797CCompleteValue(resultOrField2);
                    if(!resultOrField2){
                        Level27_7797CField(private19,unsigned short*,74)=50;
                        goto block_233;
                    }
                    cursorOrVector18=(int)&Level27_7797C_D_8006E788;
                    Level27_7797CCompleteValue(cursorOrVector18);
                    positionOrOutput17=Level27_7797CField(cursorOrVector18,int*,0);
                    cursorOrVector18+=4;
                    if(positionOrOutput17){
                        scoreTableOrVector21=(int)&Level27_7797C_D_80070328;
                        do{
                            if(Level27_7797CField(positionOrOutput17,short*,54)!=639)goto actor2086NextSelected;
                            resultOrField2=Level27_7797C_func_8004F334((void*)(owner20+12),(void*)(positionOrOutput17+12));
                            resultOrField2-=4501;
                            if((unsigned int)resultOrField2>=18027)goto actor2086NextSelected;
                            if(Level27_7797CField(positionOrOutput17,unsigned char*,72))goto actor2086NextSelected;
                            resultOrField2=Level27_7797C_func_8004E880(Level27_7797CField(positionOrOutput17,int*,12)-Level27_7797CField(owner20,int*,12),Level27_7797CField(positionOrOutput17,int*,16)-Level27_7797CField(owner20,int*,16),0);
                            argumentOrField6=0;
                            __asm__ volatile(""::"r"(argumentOrField6):"$16");
                            indexPositionOrFlags16=resultOrField2;
                            argumentOrField7=Level27_7797CField(scoreTableOrVector21,int*,0);
                            argumentOrField4=Level27_7797CField(owner20,int*,12);
                            fieldOrArithmetic3=Level27_7797CField(scoreTableOrVector21,int*,4);
                            argumentOrField5=Level27_7797CField(owner20,int*,16);
                            argumentOrField4=argumentOrField7-argumentOrField4;
                            argumentOrField5=fieldOrArithmetic3-argumentOrField5;
                            resultOrField2=Level27_7797C_func_8004E880(argumentOrField4,argumentOrField5,argumentOrField6,argumentOrField7);
                            resultOrField2=Level27_7797C_func_8004F264(indexPositionOrFlags16,resultOrField2);
                            if(resultOrField2<25)goto actor2086NextSelected;
                            resultOrField2=Level27_7797CField(positionOrOutput17,int*,0);
                            resultOrField2=Level27_7797CField(resultOrField2,short*,22);
                            if(resultOrField2>=481)goto actor2086SelectedLink;
                            actor2086NextSelected:positionOrOutput17=Level27_7797CField(cursorOrVector18,int*,0);
                            cursorOrVector18+=4;
                        }
                        while(positionOrOutput17);
                    }
                block_163:
                    Level27_7797CField(owner20, unsigned char *, 0x48) = 0U;
                    Level27_7797C_func_80034F40((void*)(owner20), 0);
                    __asm__ volatile(""::"r"(owner20):"memory");
                    goto block_164;
                }
            block_164:
                /* Original three-way private+28 state graph; shared labels preserve actual native joins. */
                fieldOrArithmetic3=Level27_7797CField(private19,int*,40);
                switch(fieldOrArithmetic3){
                case 0:
                    __asm__("":::"$2","$3");
                    indexPositionOrFlags16=0;
                    resultOrField2=Level27_7797CField(private19,short*,76);
                    if(resultOrField2)goto actor2086IdleAnimation;
                    Level27_7797CCompleteValue(indexPositionOrFlags16);
                    __asm__("":::"$2");
                    resultOrField2=Level27_7797C_func_8004F264(Level27_7797CField(owner20,unsigned char*,70),Level27_7797C_func_8004E880(Level27_7797CField((int)&Level27_7797C_D_80070328,int*,0)-Level27_7797CField(owner20,int*,12),Level27_7797CField((int)&Level27_7797C_D_80070328,int*,4)-Level27_7797CField(owner20,int*,16),0));
                    frameSnapshot9=*(volatile int*)&originalFrame.spC8;
                    __asm__ volatile("":"=r"(resultOrField2):"0"(resultOrField2):"memory");
                    fieldOrArithmetic3=resultOrField2;
                    resultOrField2=frameSnapshot9<6144;
                    if(resultOrField2&&(resultOrField2=fieldOrArithmetic3<64))goto actor2086Mode01Done;
                    frameSnapshot8=*(volatile int*)&originalFrame.spC8;
                    resultOrField2=frameSnapshot8<10241;
                actor2086SharedRandom:
                    /* Original shared random threshold branch for submodes0 and1. */
                    if(!resultOrField2||(Level27_7797C_rand()&255)>=128)indexPositionOrFlags16=1;
                actor2086Mode01Done:
                    resultOrField2=1;
                    Level27_7797CField(private19,int*,112)=resultOrField2;
                    if(!indexPositionOrFlags16)goto actor2086ModeShort31;
                    resultOrField2=13;
                    goto actor2086Mode13Store;
                case 1:
                    if(!Level27_7797CField(private19,short*,72)){
                        frameSnapshot9=*(volatile int*)&originalFrame.spC0;
                        resultOrField2=40;
                        if(frameSnapshot9){
                            Level27_7797CField(private19,int*,80)=frameSnapshot9;
                            goto actor2086Mode28Store;
                        }
                    }
                    if(Level27_7797CField(private19,short*,62)){
                        resultOrField2=Level27_7797C_func_8003573C((void*)(owner20),7,20,1);
                        argumentOrField4=1;
                        if(!resultOrField2)return;
                        argumentOrField5=24;
                        Level27_7797CCompleteValue(argumentOrField5);
                        argumentOrField6=owner20;
                        resultOrField2=(int)Level27_7797C_SpawnParticle;
                        argumentOrField7=12;
                        Level27_7797CField(private19,short*,62)=0;
                        Level27_7797CField(private19,short*,68)=0;
                        ((int(*)())resultOrField2)(argumentOrField4,argumentOrField5,argumentOrField6,argumentOrField7);
                        argumentOrField4=owner20;
                        var_a1_3=10;
                        var_v0_3=10;
                        block_185:argumentOrField5=var_a1_3;
                        resultOrField2=var_v0_3;
                        Level27_7797CField(argumentOrField4,unsigned char*,72)=resultOrField2;
                        Level27_7797C_func_80034F40((void*)(argumentOrField4),argumentOrField5);
                        __asm__ volatile(""::"r"(owner20):"memory");
                        return;
                    }
                    __asm__("":::"$2","$3");
                    indexPositionOrFlags16=0;
                    resultOrField2=Level27_7797CField(private19,short*,76);
                    if(resultOrField2)goto actor2086IdleAnimation;
                    Level27_7797CCompleteValue(indexPositionOrFlags16);
                    __asm__("":::"$2");
                    resultOrField2=Level27_7797C_func_8004F264(Level27_7797CField(owner20,unsigned char*,70),Level27_7797C_func_8004E880(Level27_7797CField((int)&Level27_7797C_D_80070328,int*,0)-Level27_7797CField(owner20,int*,12),Level27_7797CField((int)&Level27_7797C_D_80070328,int*,4)-Level27_7797CField(owner20,int*,16),0));
                    frameSnapshot8=*(volatile int*)&originalFrame.spC8;
                    __asm__ volatile("":"=r"(resultOrField2):"0"(resultOrField2):"memory");
                    fieldOrArithmetic3=resultOrField2;
                    resultOrField2=frameSnapshot8<6144;
                    if(resultOrField2&&(resultOrField2=fieldOrArithmetic3<64))goto actor2086Mode01Done;
                    frameSnapshot9=*(volatile int*)&originalFrame.spC8;
                    resultOrField2=frameSnapshot9<10241;
                    goto actor2086SharedRandom;
                case 2:
                    if(!Level27_7797CField(private19,short*,72)){
                        frameSnapshot8=*(volatile int*)&originalFrame.spC0;
                        resultOrField2=40;
                        if(frameSnapshot8){
                            Level27_7797CField(private19,int*,80)=frameSnapshot8;
                        actor2086Mode28Store:
                            /* Both incoming paths already produced the complete value40. */Level27_7797CField(private19,short*,74)=resultOrField2;
                            resultOrField2=30;
                            Level27_7797CField(owner20,unsigned char*,72)=resultOrField2;
                            return;
                        }
                    }
                    resultOrField2=Level27_7797CField(private19,short*,62);
                    if(resultOrField2){
                        Level27_7797CField(private19,short*,62)=0;
                        Level27_7797CField(private19,short*,68)=0;
                        Level27_7797CField(owner20,unsigned char*,72)=40;
                        return;
                    }
                    __asm__("":::"$2","$3");
                    indexPositionOrFlags16=0;
                    resultOrField2=Level27_7797CField(private19,short*,76);
                    if(resultOrField2)goto actor2086IdleAnimation;
                    Level27_7797CCompleteValue(indexPositionOrFlags16);
                    __asm__("":::"$2");
                    resultOrField2=Level27_7797C_func_8004F264(Level27_7797CField(owner20,unsigned char*,70),Level27_7797C_func_8004E880(Level27_7797CField((int)&Level27_7797C_D_80070328,int*,0)-Level27_7797CField(owner20,int*,12),Level27_7797CField((int)&Level27_7797C_D_80070328,int*,4)-Level27_7797CField(owner20,int*,16),0));
                    frameSnapshot9=*(volatile int*)&originalFrame.spC8;
                    __asm__ volatile("":"=r"(resultOrField2):"0"(resultOrField2):"memory");
                    fieldOrArithmetic3=resultOrField2;
                    resultOrField2=frameSnapshot9<6144;
                    if(resultOrField2&&(resultOrField2=fieldOrArithmetic3<64))goto actor2086Mode2Done;
                    frameSnapshot8=*(volatile int*)&originalFrame.spC8;
                    resultOrField2=frameSnapshot8<10241;
                    Level27_7797CCompleteValue(resultOrField2);
                    if(!resultOrField2||(Level27_7797C_rand()&255)>=128)indexPositionOrFlags16=1;
                    actor2086Mode2Done:resultOrField2=1;
                    Level27_7797CField(private19,int*,112)=resultOrField2;
                    if(indexPositionOrFlags16)goto actor2086Mode13;
                actor2086ModeShort31:
                    /* Original late shared timer/state producer. */resultOrField2=300;
                    Level27_7797CField(private19,short*,78)=resultOrField2;
                    resultOrField2=31;
                    Level27_7797CField(owner20,unsigned char*,72)=resultOrField2;
                    return;
                    actor2086Mode13:resultOrField2=13;
                    actor2086Mode13Store:Level27_7797CField(owner20,unsigned char*,72)=resultOrField2;
                    Level27_7797C_func_80034F40((void*)(owner20),13);
                    __asm__ volatile(""::"r"(owner20):"memory");
                    return;
                default:
                    actor2086IdleAnimation:if(Level27_7797CField(owner20,unsigned char*,61)){
                        Level27_7797C_D_8006C770=0;
                        Level27_7797CField(owner20,unsigned char*,64)=114;
                        Level27_7797CField(owner20,unsigned char*,61)=0;
                        Level27_7797CField(owner20,unsigned char*,63)=0;
                        Level27_7797C_func_80035734((void*)(owner20));
                    }
                    goto block_347;
                }
            }
            break;
        case 13:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            Level27_7797C_func_8003573C((void*)(owner20), 8, 0x14, 1);
            if (Level27_7797C_D_8006C770 != 0) {
                Level27_7797CField(private19, short *, 0x44) = 0;
                if ((int) adjustedDifficulty <= 0) {
                    var_v0_7 = Level27_7797CField(private19, int *, 0x28) + 2;
                }
                else {
                    var_v0_7 = Level27_7797CField(private19, int *, 0x28) + 1;
                }
                Level27_7797CField(private19, int *, 0x5C) = var_v0_7;
                Level27_7797CField(owner20, unsigned char *, 0x48) = 0xCU;
                __asm__ volatile(""::"r"(owner20):"$4","$5","memory");
                Level27_7797C_func_80034F40((void*)(owner20), 0xC);
                __asm__ volatile(""::"r"(owner20):"memory");
            }
            goto block_347;
        case 12:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            if (Level27_7797C_func_80055E84((void*)(owner20)) >= 9) {
                if (Level27_7797CField(private19, short *, 0x44) == 0) {
                    argumentOrField4=413;
                    __asm__ volatile(""::"r"(argumentOrField4):"$2","memory");
                    argumentOrField5=owner20;
                    fieldOrArithmetic3=(int)Level27_7797C_SpawnMoby;
                    resultOrField2=1;
                    Level27_7797CField(private19,short*,68)=resultOrField2;
                    ((int(*)())fieldOrArithmetic3)(argumentOrField4,argumentOrField5);
                }
            }
            Level27_7797C_func_8003573C((void*)(owner20), 8, 0x14, 1);
            if (Level27_7797C_D_8006C770 != 0) {
                Level27_7797CField(private19, short *, 0x44) = 0;
                temp_v0_8 = Level27_7797CField(private19, int *, 0x5C) - 1;
                Level27_7797CField(private19, int *, 0x5C) = temp_v0_8;
                if (temp_v0_8 <= 0) {
                    argumentOrField4=owner20;
                    argumentOrField5=0xE;
                    Level27_7797CField(private19, short *, 0x4C) = 0x78;
                    resultOrField2=0xE;
                    goto block_304;
                }
            }
            goto block_347;
        case 31:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            if (Level27_7797CField(owner20, unsigned char *, 0x3D) != 1) {
                Level27_7797C_D_8006C770 = 0;
                Level27_7797CField(owner20, signed char *, 0x40) = 0x72;
                Level27_7797CField(owner20, unsigned char *, 0x3D) = 1U;
                Level27_7797CField(owner20, signed char *, 0x3F) = 0;
                Level27_7797C_func_80035734((void*)(owner20));
            }
            if (Level27_7797C_func_8003573C((void*)(owner20), 3, 0x14, 1) != 0) {
                var_v1 = 0xF0;
                if ((int) adjustedDifficulty >= 8) {
                    var_v1 = 0xDC;
                }
                if (Level27_7797C_D_8006C7C4 == 1) {
                    var_v1 -= 0xA;
                }
                else if (Level27_7797C_D_8006C7C4 == 0) {
                    var_v1 -= 0x14;
                }
                temp_v0_9 = Level27_7797CField(private19, unsigned short *, 0x4A) + 0xF;
                Level27_7797CField(private19, unsigned short *, 0x4A) = temp_v0_9;
                if (var_v1 < (short) temp_v0_9) {
                    Level27_7797CField(private19, unsigned short *, 0x4A) = (unsigned short) var_v1;
                }
                Level27_7797C_func_80035DDC((void*)(owner20), (short) Level27_7797CField(private19, unsigned short *, 0x4A), 0, 0, 5);
            }
            frameSnapshot9=originalFrame.spD0;
            resultOrField2=frameSnapshot9<13001;
            Level27_7797CCompleteValue(resultOrField2);
            if(!resultOrField2){
                block_233:Level27_7797CField(owner20,unsigned char*,72)=33;
                return;
            }
            frameSnapshot8=originalFrame.spC8;
            resultOrField2=frameSnapshot8<4800;
            Level27_7797CCompleteValue(resultOrField2);
            if(resultOrField2) {
                argumentOrField4=owner20;
                argumentOrField5=9;
                Level27_7797CField(private19, unsigned short *, 0x4A) = 0xD2U;
                resultOrField2=9;
                goto block_304;
            }
            goto block_347;
        case 9:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            resultOrField2=Level27_7797C_func_80055E84((void*)(owner20));
            argumentOrField4=owner20;
            argumentOrField5=14;
            argumentOrField6=0;
            argumentOrField7=0;
            __asm__("":"=r"(argumentOrField4),"=r"(argumentOrField5),"=r"(argumentOrField6),"=r"(argumentOrField7):"0"(argumentOrField4),"1"(argumentOrField5),"2"(argumentOrField6),"3"(argumentOrField7):"memory");
            indexPositionOrFlags16=resultOrField2;
            Level27_7797C_func_8003573C((void*)(argumentOrField4),argumentOrField5,argumentOrField6,argumentOrField7);
            if(Level27_7797CField((int)&Level27_7797C_D_80070328,int*,80)==4){
                if(Level27_7797CField(private19,short*,74)>=171){
                    resultOrField2=170;
                    goto actor2086ClampHeading;
                }
            }
            else if(Level27_7797CField(private19,short*,74)>=241){
                resultOrField2=240;
                actor2086ClampHeading:Level27_7797CField(private19,short*,74)=resultOrField2;
            }
            resultOrField2=indexPositionOrFlags16-11;
            resultOrField2=(unsigned int)resultOrField2<7;
            if(resultOrField2){
                fieldOrArithmetic3=(int)&Level27_7797C_D_8006E1D8;
                Level27_7797CCompleteValue(fieldOrArithmetic3);
                resultOrField2=Level27_7797CField(fieldOrArithmetic3,int*,0);
                if(!resultOrField2){
                    Level27_7797C_D_8006E1D4=4000;
                    Level27_7797CField(fieldOrArithmetic3,int*,0)=40;
                }
            }
            resultOrField2=indexPositionOrFlags16<10;
            Level27_7797CCompleteValue(resultOrField2);
            if(resultOrField2){
                if (Level27_7797C_func_8004F334((void*)(owner20 + 0xC),(void*)( (int)&Level27_7797C_D_80070328)) < 0xDAC) {
                    Level27_7797CField(private19, unsigned short *, 0x4A) = 0U;
                }
                if ((short) Level27_7797CField(private19, unsigned short *, 0x4A) < 0) {
                    Level27_7797CField(private19, unsigned short *, 0x4A) = 0U;
                }
                Level27_7797C_func_80035DDC((void*)(owner20), (short) Level27_7797CField(private19, unsigned short *, 0x4A), 0, 0, 5);
            }
            Level27_7797C_func_80055D24((void*)(owner20),5);
            goto actor2086Default67;
        case 30:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            if (Level27_7797CField(owner20, unsigned char *, 0x3D) != 1) {
                Level27_7797C_D_8006C770 = 0;
                Level27_7797CField(owner20, signed char *, 0x40) = 0x72;
                Level27_7797CField(owner20, unsigned char *, 0x3D) = 1U;
                Level27_7797CField(owner20, signed char *, 0x3F) = 0;
                Level27_7797C_func_80035734((void*)(owner20));
            }
            temp_a1_3 = Level27_7797CField(private19, int*, 0x50);
            if (Level27_7797CField(temp_a1_3, unsigned char *, 0x48) != 0) {
                argumentOrField4=owner20;
                argumentOrField5=0;
                resetTimerThirty=30;
                __asm__("":"=r"(resetTimerThirty):"0"(resetTimerThirty));
                Level27_7797CField(private19,short*,72)=resetTimerThirty;
                goto block_293;
            }
            if (Level27_7797C_func_8003585C((void*)(owner20), Level27_7797C_func_8004E880(Level27_7797CField(temp_a1_3, int *, 0xC) - Level27_7797CField(owner20, int *, 0xC), Level27_7797CField(temp_a1_3, int *, 0x10) - Level27_7797CField(owner20, int *, 0x10), 0), 5, 0x14, 1, 0) != 0) {
                temp_v0_10 = Level27_7797CField(private19, unsigned short *, 0x4A) + 0xF;
                Level27_7797CField(private19, unsigned short *, 0x4A) = temp_v0_10;
                if ((short) temp_v0_10 >= 0xF1) {
                    Level27_7797CField(private19, unsigned short *, 0x4A) = 0xF0U;
                }
                Level27_7797C_func_80035DDC((void*)(owner20), (short) Level27_7797CField(private19, unsigned short *, 0x4A), 0, 0, 5);
                if (Level27_7797C_func_8004F334((void*)(owner20 + 0xC),(void*)( Level27_7797CField(private19, int*, 0x50) + 0xC)) < 0xBB8) {
                    Level27_7797CField(owner20, unsigned char *, 0x48) = 8U;
                    Level27_7797C_func_80034F40((void*)(owner20), 8);
                    __asm__ volatile(""::"r"(owner20):"memory");
                }
            }
            goto block_347;
        case 8:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            resultOrField2=Level27_7797C_func_80055E84((void*)(owner20));
            fieldOrArithmetic3=Level27_7797CField(private19,volatile int*,80);
            argumentOrField4=resultOrField2;
            if(fieldOrArithmetic3){
                fieldOrArithmetic3=Level27_7797CField(fieldOrArithmetic3,unsigned char*,72);
                if(fieldOrArithmetic3&&fieldOrArithmetic3!=13){
                    argumentOrField5=0;
                    argumentOrField4=owner20;
                    resultOrField2=30;
                    Level27_7797CField(private19,short*,72)=resultOrField2;
                    goto block_293;
                }
                fieldOrArithmetic3=Level27_7797CField(private19,volatile int*,80);
                if(fieldOrArithmetic3){
                    resultOrField2=argumentOrField4<13;
                    Level27_7797CCompleteValue(resultOrField2);
                    if(!resultOrField2){
                        Level27_7797CField(fieldOrArithmetic3,unsigned char*,72)=13;
                        Level27_7797C_func_80055D24((void*)(owner20),4);
                        argumentOrField4=owner20;
                        argumentOrField5=12;
                        __asm__ volatile(""::"r"(argumentOrField4),"r"(argumentOrField5):"$16");
                        indexPositionOrFlags16=(int)&originalFrame.sp30;
                        Level27_7797C_func_80055F14((void*)(argumentOrField4),argumentOrField5,(void*)(indexPositionOrFlags16));
                        positionOrOutput17=(int)&originalFrame.sp50;
                        Level27_7797C_func_8004F1C8((void*)(positionOrOutput17),(void*)(indexPositionOrFlags16),(void*)(Level27_7797CField(private19,int*,80)+12));
                        resultOrField2=Level27_7797C_func_8004EDE8((void*)(positionOrOutput17),1);
                        argumentOrField4=positionOrOutput17;
                        __asm__("":"=r"(argumentOrField4):"0"(argumentOrField4):"memory");
                        indexPositionOrFlags16=resultOrField2;
                        Level27_7797C_func_8004F08C((void*)(argumentOrField4),indexPositionOrFlags16,100);
                        argumentOrField4=Level27_7797CField(private19,int*,80);
                        argumentOrField6=positionOrOutput17;
                        argumentOrField4+=12;
                        Level27_7797C_func_8004F194((void*)(argumentOrField4),(void*)(argumentOrField4),(void*)(argumentOrField6));
                        if(indexPositionOrFlags16<120){
                            indexPositionOrFlags16=0;
                            Level27_7797C_func_80055B18((void*)(Level27_7797CField(private19,int*,80)));
                            Level27_7797CField(private19,int*,80)=0;
                        }
                        else indexPositionOrFlags16=0;
                        do {
                            Level27_7797C_func_8004F178((void*)(&originalFrame.sp60),(void*)( Level27_7797CField(private19, int*, 0x50) + 0xC));
                            originalFrame.sp60 += Level27_7797C_func_800363DC(0, 0x12C);
                            originalFrame.sp64 += Level27_7797C_func_800363DC(0, 0x12C);
                            indexPositionOrFlags16 += 1;
                            originalFrame.sp68 += Level27_7797C_func_800363DC(0, 0x12C);
                            originalFrame.sp70 = Level27_7797C_rand() & 7;
                            originalFrame.sp74 = Level27_7797C_rand() & 7;
                            originalFrame.sp78 = 0xA;
                            Level27_7797C_SpawnParticle(1, 0xD, &originalFrame.sp60, &originalFrame.sp70);
                        }
                        while (indexPositionOrFlags16 < 4);
                    }
                    temp_v0_12 = Level27_7797CField(private19, int*, 0x50);
                    if (temp_v0_12 != 0) {
                        Level27_7797C_func_8003585C((void*)(owner20), Level27_7797C_func_8004E880(Level27_7797CField(temp_v0_12, int *, 0xC) - Level27_7797CField(owner20, int *, 0xC), Level27_7797CField(temp_v0_12, int *, 0x10) - Level27_7797CField(owner20, int *, 0x10), 0), 7, 0x14, 1, 0);
                    }
                }
                goto block_273;
            }
        block_273:
            if (Level27_7797C_D_8006C770 != 0) {
                Level27_7797CField(private19, short *, 0x3E) = 1;
                argumentOrField4=owner20;
                argumentOrField5=0;
                Level27_7797CField(private19, short *, 0x48) = 0x78;
                goto block_323;
            }
            goto block_347;
        case 10:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            resultOrField2=Level27_7797C_func_80055E84((void*)(owner20));
            argumentOrField4=owner20;
            argumentOrField5=4;
            __asm__("":"=r"(argumentOrField4),"=r"(argumentOrField5):"0"(argumentOrField4),"1"(argumentOrField5):"memory");
            modeOrTable22=resultOrField2;
            Level27_7797C_func_80055D24((void*)(argumentOrField4),argumentOrField5);
            originalFrame.sp30 = 0;
            originalFrame.sp34 = 0;
            originalFrame.sp38 = 0;
            if (modeOrTable22 >= 0x13) {
                argumentOrField4=owner20;
                if (modeOrTable22 >= 0x23) {
                    originalFrame.sp38 = 0x64;
                    indexPositionOrFlags16=1;
                    cursorOrVector18=(int)&originalFrame.sp60;
                    scoreTableOrVector21=(int)&originalFrame.sp30;
                    __asm__ volatile(""::"r"(cursorOrVector18),"r"(scoreTableOrVector21):"$17");
                    positionOrOutput17=modeOrTable22-34;
                    Level27_7797CCompleteValue(positionOrOutput17);
                    do {
                        Level27_7797C_func_80055F14((void*)(argumentOrField4),indexPositionOrFlags16+12,(void*)(cursorOrVector18));
                        temp_a0_6=Level27_7797CByteC640*2;
                        originalFrame.sp30 = (int) (Level27_7797CField((int)&Level27_7797C_D_80065920,short*,0 + temp_a0_6) * 3) >> 0xA;
                        fieldOrArithmetic3=Level27_7797CField((int)&Level27_7797C_D_800658A0,short*,temp_a0_6);
                        originalFrame.sp38=0;
                        resultOrField2=fieldOrArithmetic3*3;
                        originalFrame.sp34=resultOrField2>>10;
                        originalFrame.sp38 = (Level27_7797C_rand(temp_a0_6) & 0xF) + 0x1F;
                        resultOrField2=Level27_7797C_SpawnParticle(1,25,cursorOrVector18,scoreTableOrVector21);
                        argumentOrField4=resultOrField2;
                        if(argumentOrField4){
                            resultOrField2=Level27_7797CField(argumentOrField4,unsigned char*,12);
                            fieldOrArithmetic3=Level27_7797CField(argumentOrField4,unsigned char*,14);
                            resultOrField2-=positionOrOutput17;
                            Level27_7797CField(argumentOrField4,unsigned char*,12)=resultOrField2;
                            resultOrField2=Level27_7797CField(argumentOrField4,unsigned char*,13);
                            fieldOrArithmetic3-=positionOrOutput17;
                            Level27_7797CField(argumentOrField4,unsigned char*,14)=fieldOrArithmetic3;
                            resultOrField2-=positionOrOutput17;
                            Level27_7797CField(argumentOrField4,unsigned char*,13)=resultOrField2;
                        }
                        resultOrField2=modeOrTable22<40;
                        Level27_7797CCompleteValue(resultOrField2);
                        if(resultOrField2){
                            originalFrame.sp38=(Level27_7797C_rand()&15)+31;
                            Level27_7797C_SpawnParticle(1,25,cursorOrVector18,scoreTableOrVector21);
                        }
                        indexPositionOrFlags16 += 1;
                        argumentOrField4=owner20;
                    }
                    while (indexPositionOrFlags16 < 6);
                }
                goto actor2086SevenReady;
            }
            else if ((int) Level27_7797C_D_8006C640 & 1) {
                Level27_7797C_func_80055F14((void*)(owner20), 0xC,(void*)( &originalFrame.sp60));
                Level27_7797C_SpawnParticle(1, 0x18, owner20, (int *)0xC);
            }
            argumentOrField4=owner20;
        actor2086SevenReady:
            /* This original entry already has initialized A0; skip the other path reload. */Level27_7797C_func_8003573C((void*)(argumentOrField4),7,0,0);
            resultOrField2=Level27_7797CField(private19,short*,68);
            if(!resultOrField2&&(resultOrField2=modeOrTable22<19,!resultOrField2)) {
                Level27_7797C_SpawnMoby(0x3E2, owner20);
                Level27_7797CField(private19, short *, 0x44) = 1;
            }
            if (Level27_7797C_D_8006C770 != 0) {
                argumentOrField4=owner20;
                argumentOrField5=0;
                Level27_7797CField(private19,short*,76)=180;
            block_293:
                /* Original shared zero-state call; A0/A1 are initialized before each incoming timer store. */Level27_7797CField(argumentOrField4,signed char*,72)=0;
                Level27_7797C_func_80034F40((void*)(argumentOrField4),argumentOrField5);
                __asm__ volatile(""::"r"(owner20):"memory");
                return;
            }
            goto block_346;
        case 40:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            if (Level27_7797CField(owner20, unsigned char *, 0x3D) != 1) {
                Level27_7797C_D_8006C770 = 0;
                Level27_7797CField(owner20, signed char *, 0x40) = 0x72;
                Level27_7797CField(owner20, unsigned char *, 0x3D) = 1U;
                Level27_7797CField(owner20, signed char *, 0x3F) = 0;
                Level27_7797C_func_80035734((void*)(owner20));
            }
            if (Level27_7797C_func_8004F334((void*)(owner20 + 0xC),(void*)( private19)) >= 0x1801) {
                if (Level27_7797C_func_8003585C((void*)(owner20), Level27_7797C_func_8004E880(Level27_7797CField(private19, int *, 0) - Level27_7797CField(owner20, int *, 0xC), Level27_7797CField(private19, int *, 4) - Level27_7797CField(owner20, int *, 0x10), 0), 5, 0, 0, 0) < 0x30) {
                    Level27_7797C_func_80035DDC((void*)(owner20), 0xF0, 0, 0, 5);
                }
            }
            else {
                Level27_7797CField(owner20, unsigned char *, 0x48) = 0x29U;
            }
            goto block_347;
        case 41:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            if (Level27_7797C_func_8003573C((void*)(owner20), 5, 0x20, 1) != 0) {
                Level27_7797CField(owner20, unsigned char *, 0x48) = 4U;
                Level27_7797C_func_80034F40((void*)(owner20), 4);
                __asm__ volatile(""::"r"(owner20):"memory");
            }
            goto block_347;
        case 4:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            Level27_7797C_func_8003573C((void*)(owner20), 5, 0, 0);
            if (Level27_7797C_D_8006C770 != 0) {
                argumentOrField4=owner20;
                argumentOrField5=5;
                resultOrField2=20;
                Level27_7797CField(private19,short*,66)=resultOrField2;
                resultOrField2=5;
                Level27_7797CField(private19, short *, 0x44) = 0;
            block_304:
                /* All incoming paths already initialized A0/A1 and the full state valueV0. */Level27_7797CField(owner20,unsigned char*,72)=resultOrField2;
                Level27_7797C_func_80034F40((void*)(argumentOrField4),argumentOrField5);
                __asm__ volatile(""::"r"(owner20):"memory");
            }
            goto block_347;
        case 5:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            Level27_7797C_func_8003573C((void*)(owner20), 5, 0, 0);
            if (Level27_7797C_func_800359A4((void*)(private19 + 0x42), 2) != 0) {
                if (Level27_7797CField(private19, short *, 0x44) == 0) {
                    temp_v0_14 = Level27_7797C_SpawnMoby(0x182, owner20);
                    Level27_7797CField(private19, int*, 0x54) = temp_v0_14;
                    if (temp_v0_14 != 0) {
                        Level27_7797CField(private19, short *, 0x44) = 1;
                    }
                    goto block_309;
                }
                goto block_310;
            }
        block_309:
            if (Level27_7797CField(private19, short *, 0x44) != 0) {
            block_310:
                temp_v0_15 = Level27_7797CField(private19, int*, 0x54);
                if (temp_v0_15 != 0) {
                    if (Level27_7797CField(temp_v0_15, unsigned char *, 0x49) == 1) {
                        Level27_7797CField(private19, short *, 0x44) = 2;
                    }
                    temp_a0_7 = Level27_7797CField(private19, int*, 0x54);
                    if ((Level27_7797CField(temp_a0_7, unsigned char *, 0x48) & 0x80) || (Level27_7797CField(temp_a0_7, unsigned char *, 0x49) == 2) || (Level27_7797CField(temp_a0_7, short *, 0x36) != 0x182)) {
                        Level27_7797CField(private19, int*, 0x54) = 0;
                    }
                }
                else if (Level27_7797C_D_8006C770 != 0) {
                    if (Level27_7797CField(private19, short *, 0x44) == 1) {
                        Level27_7797CField(owner20, unsigned char *, 0x48) = 7U;
                        Level27_7797C_func_80034F40((void*)(owner20), 7);
                        __asm__ volatile(""::"r"(owner20):"memory");
                    }
                    else {
                        Level27_7797CField(owner20, unsigned char *, 0x48) = 6U;
                        Level27_7797C_func_80034F40((void*)(owner20), 6);
                        __asm__ volatile(""::"r"(owner20):"memory");
                    }
                }
            }
            goto block_347;
        case 6:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
        case 7:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
        actor2086Default67:
            if (Level27_7797C_D_8006C770 != 0) {
                argumentOrField4=owner20;
                argumentOrField5=0;
                Level27_7797CField(private19, short *, 0x4C) = 0xB4;
            block_323:
                Level27_7797CField(owner20, unsigned char *, 0x48) = 0U;
                Level27_7797C_func_80034F40((void*)(argumentOrField4),argumentOrField5);
                __asm__ volatile(""::"r"(owner20):"memory");
            }
            goto block_347;
        case 2:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            Level27_7797C_func_8003573C((void*)(owner20), 7, 0, 0);
            Level27_7797C_func_8004F1C8((void*)(&originalFrame.sp80),(void*)( owner20 + 0xC),(void*)( Level27_7797CField(Level27_7797CField(private19, int*, 0xA4), int*, 0xC)));
            if (Level27_7797C_func_8004EDE8((void*)(&originalFrame.sp80), 0) >= 0x32C9) {
                Level27_7797CField(private19, short *, 0x10) = 0;
            }
            Level27_7797C_func_80035194((void*)(owner20),(void*)( private19 + 0xC));
            Level27_7797C_func_80055D24((void*)(owner20), 1);
            if (Level27_7797C_D_8006C770 != 0) {
                if (Level27_7797CField(private19, int *, 0x28) == 1) {
                    Level27_7797CField(owner20, unsigned char *, 0x48) = 0xFU;
                    Level27_7797C_func_80034F40((void*)(owner20), 0xF);
                    __asm__ volatile(""::"r"(owner20):"memory");
                }
                else {
                    Level27_7797CField(owner20,unsigned char*,72)=0;
                    block_330:Level27_7797C_func_80034F40((void*)(owner20),0);
                    __asm__ volatile(""::"r"(owner20):"memory");
                }
            }
            goto block_347;
        case 11:
            __asm__ volatile(""::"r"(fieldOrArithmetic3));
            temp_v0_16 = Level27_7797CField(Level27_7797CField(private19, int*, 0x24), int*, 0xC);
            resultOrField2 = Level27_7797C_func_8004E880(Level27_7797CField(temp_v0_16, int *, 0) - Level27_7797CField(owner20, int *, 0xC), Level27_7797CField(temp_v0_16, int *, 4) - Level27_7797CField(owner20, int *, 0x10), 0);
            argumentOrField4=(int)&originalFrame.spA0;
            __asm__ volatile(""::"r"(argumentOrField4):"$17");
            positionOrOutput17=owner20+12;
            argumentOrField5=positionOrOutput17;
            __asm__("":"=r"(argumentOrField4),"=r"(argumentOrField5):"0"(argumentOrField4),"1"(argumentOrField5):"memory");
            indexPositionOrFlags16=resultOrField2-80;
            Level27_7797C_func_8004F178((void*)(argumentOrField4),(void*)(argumentOrField5));
            originalFrame.spA8 += 0x384;
            Level27_7797C_func_8004F178((void*)(&originalFrame.sp90),(void*)( positionOrOutput17));
            resultOrField2=Level27_7797CField(private19,int*,152);
            indexPositionOrFlags16+=resultOrField2;
            resultOrField2++;
            __asm__("":"=r"(resultOrField2):"0"(resultOrField2));
            indexPositionOrFlags16=(indexPositionOrFlags16&255)*2;
            Level27_7797CField(private19,int*,152)=resultOrField2;
            resultOrField2=Level27_7797CField((int)&Level27_7797C_D_80065920,short*,indexPositionOrFlags16);
            __asm__ volatile(""::"r"(owner20):"memory","$4");
            argumentOrField4=8000;
            __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(argumentOrField4));
            cosProduct.full=(long long)resultOrField2*(long long)argumentOrField4;
            resultOrField2=*(volatile int*)&originalFrame.sp90;
            __asm__("":"=x"(cosProduct.full):"0"(cosProduct.full),"r"(resultOrField2));
            cosineLow9=(int)cosProduct.words.low;
            Level27_7797CCompleteValue(cosineLow9);
            fieldOrArithmetic3=cosineLow9>>12;
            resultOrField2+=fieldOrArithmetic3;
            originalFrame.sp90=resultOrField2;
            resultOrField2=Level27_7797CField((int)&Level27_7797C_D_800658A0,short*,indexPositionOrFlags16);
            __asm__("":"=r"(resultOrField2):"0"(resultOrField2),"r"(cosineLow9));
            sinProduct.full=(long long)resultOrField2*(long long)argumentOrField4;
            resultOrField2=*(volatile int*)&originalFrame.sp98;
            __asm__ volatile("":::"$22","memory");
            modeOrTable22=(int)&Level27_7797C_D_80065920;
            Level27_7797CCompleteValue(modeOrTable22);
            resultOrField2+=2500;
            originalFrame.sp98=resultOrField2;
            resultOrField2=originalFrame.sp94;
            __asm__ volatile("":"=x"(sinProduct.full):"0"(sinProduct.full),"r"(resultOrField2):"memory");
            sineLow8=(int)sinProduct.words.low;
            Level27_7797CCompleteValue(sineLow8);
            fieldOrArithmetic3=sineLow8>>12;
            resultOrField2+=fieldOrArithmetic3;
            originalFrame.sp94=resultOrField2;
            privateSubmode90=Level27_7797CField(private19,int*,144);
            classOrTable23=(int)&Level27_7797C_D_800658A0;
            switch(privateSubmode90){
                default:goto block_347;
            case 0:
                if (Level27_7797C_func_800359A4((void*)(private19 + 0x94), 4) == 2) {
                    Level27_7797C_func_80013AE4((void*)(&originalFrame.sp90),(void*)( &originalFrame.spA0));
                    if (Level27_7797CField((int)&Level27_7797C_D_80070328, int *, 0x280) < 0) {
                        Level27_7797CField((int)&Level27_7797C_D_80070328, int *, 0x280) = 0;
                    }
                }
                if (Level27_7797C_D_8006E048 & 1) {
                    Level27_7797CField(private19, int *, 0x90) = (int) (Level27_7797CField(private19, int *, 0x90) + 1);
                }
                goto block_347;
            case 1:
                if (Level27_7797CField((int)&Level27_7797C_D_80070328, int *, 0x280) < 0) {
                    Level27_7797CField((int)&Level27_7797C_D_80070328, int *, 0x280) = 0;
                }
                Level27_7797C_func_80013AE4((void*)(&originalFrame.sp90),(void*)( &originalFrame.spA0));
                if (Level27_7797C_D_8006C770 != 0) {
                    spawnedOwner = Level27_7797C_SpawnMoby(0x84, owner20);
                    indexPositionOrFlags16 = spawnedOwner + 0xC;
                    if (spawnedOwner != 0) {
                        cursorOrVector18 = Level27_7797CField(spawnedOwner, short **, 0);
                        Level27_7797C_func_8004F178((void*)(indexPositionOrFlags16),(void*)( Level27_7797CField(Level27_7797CField(private19, int*, 0x24), int*, 0xC)));
                        Level27_7797CField(spawnedOwner, int *, 0x14) = (int) (Level27_7797CField(spawnedOwner, int *, 0x14) + 0x1F4);
                        resultOrField2=Level27_7797C_func_8001A358((void*)(indexPositionOrFlags16),8192);
                        positionOrOutput17=(int)&originalFrame.spB0;
                        argumentOrField4=positionOrOutput17;
                        argumentOrField5=indexPositionOrFlags16;
                        __asm__("":"=r"(argumentOrField4),"=r"(argumentOrField5):"0"(argumentOrField4),"1"(argumentOrField5):"memory");
                        Level27_7797CField(spawnedOwner,int*,20)=resultOrField2;
                        Level27_7797CField(cursorOrVector18,short*,0)=0;
                        indexPositionOrFlags16=Level27_7797CField(spawnedOwner,unsigned char*,70);
                        __asm__ volatile("":::"$2","memory");
                        resultOrField2=1;
                        Level27_7797CField(spawnedOwner,unsigned char*,72)=resultOrField2;
                        Level27_7797C_func_8004F178((void*)(argumentOrField4),(void*)(argumentOrField5));
                        argumentOrField4=positionOrOutput17;
                        argumentOrField6=0;
                        indexPositionOrFlags16*=2;
                        resultOrField2=indexPositionOrFlags16+modeOrTable22;
                        Level27_7797CCompleteValue(resultOrField2);
                        fieldOrArithmetic3=Level27_7797CField(resultOrField2,short*,0);
                        argumentOrField5=Level27_7797CField((int)&Level27_7797C_D_80070328,int*,68);
                        resultOrField2=fieldOrArithmetic3*39;
                        fieldOrArithmetic3=originalFrame.spB0;
                        resultOrField2>>=6;
                        fieldOrArithmetic3+=resultOrField2;
                        resultOrField2=originalFrame.spB8;
                        indexPositionOrFlags16+=classOrTable23;
                        originalFrame.spB0=fieldOrArithmetic3;
                        fieldOrArithmetic3=Level27_7797CField(indexPositionOrFlags16,short*,0);
                        resultOrField2+=argumentOrField5;
                        originalFrame.spB8=resultOrField2;
                        resultOrField2=fieldOrArithmetic3*39;
                        fieldOrArithmetic3=originalFrame.spB4;
                        resultOrField2>>=6;
                        fieldOrArithmetic3+=resultOrField2;
                        originalFrame.spB4=fieldOrArithmetic3;
                        argumentOrField5=Level27_7797CField(spawnedOwner,unsigned char*,70);
                        argumentOrField7=0;
                        Level27_7797C_func_80013D44((void*)(argumentOrField4),argumentOrField5+128,(void*)(argumentOrField6),argumentOrField7);
                    }
                    Level27_7797C_D_8006C408 = 0;
                    Level27_7797C_func_80055D24((void*)(owner20), 4);
                    Level27_7797C_func_8003BA00((void*)(owner20));
                    Level27_7797C_func_800369B8((void*)(owner20), 0x40);
                    Level27_7797C_func_80055B18((void*)(owner20));
                    Level27_7797C_D_8007158D = 1;
                    return;
                }
                goto block_346;
            }
            break;
        }
        goto actor2086FunctionDone;
    actor2086SelectedLink:
        /* Original late selected-owner write and byte-state transition. */resultOrField2=32;
        Level27_7797CField(private19,int*,116)=positionOrOutput17;
        Level27_7797CField(owner20,unsigned char*,73)=0;
        Level27_7797CField(owner20,unsigned char*,72)=resultOrField2;
        goto actor2086FunctionDone;
    block_346:
        block_347:Level27_7797C_func_80055D24((void*)(owner20),4);
    }
    actor2086FunctionDone:return;
}
#undef Level27_7797CField
#undef Level27_7797CCompleteValue


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
#define Controller79A14Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))


int Controller79A14_func_8001BA30() __asm__("func_8001BA30"); /* extern */
int Controller79A14_func_8001C288() __asm__("func_8001C288");    /* extern */
int Controller79A14_func_80034F80() __asm__("func_80034F80");             /* extern */
int Controller79A14_func_8003BB10() __asm__("func_8003BB10");    /* extern */
int Controller79A14_func_8004EDE8() __asm__("func_8004EDE8");                  /* extern */
int Controller79A14_func_8004F1C8() __asm__("func_8004F1C8"); /* extern */
int Controller79A14_func_80055D24() __asm__("func_80055D24");    /* extern */
int Controller79A14_func_80055F14() __asm__("func_80055F14");      /* extern */
extern Vector3D Controller79A14_D_8006E020 __asm__("D_8006E020");
extern Vector3D Controller79A14_D_80070328 __asm__("D_80070328");

void func_level_27_80079A14(Moby *incomingMoby) {
    struct {Vector3D sp18;int pad24;Vector3D sp28;int pad34;Vector3D sp38;int pad44;Vector3D sp48;int pad54;Vector3D sp58;int pad64;} frame;

register Moby *moby __asm__("$18")=incomingMoby;

    register Vector3D * position17 __asm__("$17");
    register Vector3D * position17Again __asm__("$17");
    register Vector3D * position17Last __asm__("$17");
    int priorValueAgain;
    int adjustedValueAgain;
    int priorValue;
    int adjustedValue;
    int height;
    register int value2 __asm__("$2");register int call4 __asm__("$4");register Vector3D *stackVector16 __asm__("$16");
    unsigned char state;
    unsigned char sizeByte;
    register void * tag19 __asm__("$19");
    register void * linkedTag20 __asm__("$20");

    __asm__("" : "=r"(moby):"0"(moby));
    tag19 = moby->mobyTag;
    state = moby->state;
    linkedTag20 = Controller79A14Field(Controller79A14Field(tag19, void **, 0), void **, 0);
    switch (state) {                              /* irregular */
    case 0:
        if ((moby->position.x < 0x400) || (moby->position.y < 0x400) || (moby->position.z < 0x400)) {
            moby->state = 2;
        }
        if (Controller79A14Field(tag19, unsigned char *, 0xC) != 0) {
            if (func_8004F264((int) moby->angle.yaw, func_8004E880(Controller79A14_D_80070328.x - moby->position.x, Controller79A14_D_80070328.y - moby->position.y, 0)) < 0x30) {
                height = moby->position.z;
                if ((Controller79A14_D_80070328.z + 0x200) < height) {
                    Controller79A14Field(tag19, int *, 8) = (int) (Controller79A14Field(tag19, int *, 8) - 0xF);
                } else if (Controller79A14_D_80070328.z < height) {
                    priorValueAgain = Controller79A14Field(tag19, int *, 8);
                    if (priorValueAgain < 0) {
                        adjustedValueAgain = priorValueAgain + 0xF;
                        Controller79A14Field(tag19, int *, 8) = adjustedValueAgain;
                        if (adjustedValueAgain > 0) {
                            Controller79A14Field(tag19, int *, 8) = 0;
                        }
                    }
                } else if (height < (Controller79A14_D_80070328.z - 0x200)) {
                    Controller79A14Field(tag19, int *, 8) = (int) (Controller79A14Field(tag19, int *, 8) + 0xF);
                } else if (height < Controller79A14_D_80070328.z) {
                    value2=Controller79A14Field(tag19,int*,8);if(value2>0){value2-=15;Controller79A14Field(tag19,int*,8)=value2;if(value2<0)Controller79A14Field(tag19,int*,8)=0;}
                }
                if (Controller79A14Field(tag19, int *, 8) >= 0x79) {
                    Controller79A14Field(tag19, int *, 8) = 0x78;
                }
                if (Controller79A14Field(tag19, int *, 8) < -0x78) {
                    Controller79A14Field(tag19, int *, 8) = -0x78;
                }
                moby->position.z += Controller79A14Field(tag19, int *, 8);
            }
            func_80035EE0(moby, (int) Controller79A14Field(tag19, unsigned char *, 0xF), 0x190, 0, 0, 0);
            Controller79A14_func_8004F1C8(&frame.sp18, &Controller79A14_D_8006E020, &moby->position);
            moby->angle.yaw = func_8004E880(frame.sp18.x, frame.sp18.y, 0);
            moby->angle.pitch = func_8004E880(Controller79A14_func_8004EDE8(&frame.sp18, 0), frame.sp18.z, 0);
        } else {
            moby->angle.pitch += Controller79A14Field(tag19, unsigned char *, 0xD);
            moby->angle.yaw += Controller79A14Field(tag19, unsigned char *, 0xE);
            Controller79A14_func_80055D24(moby,4);
            Controller79A14_func_80055F14(moby, 0, &frame.sp28);
            call4=(int)&frame.sp28;__asm__("" : "=r"(call4):"0"(call4));position17 = &moby->position;
            Controller79A14_func_8004F1C8(call4, position17, (Vector3D *) &frame.sp28);
            func_8004F194(position17, Controller79A14Field(tag19, void **, 0) + 0xC, (Vector3D *) &frame.sp28);
        }
        stackVector16=&frame.sp38;call4=(int)stackVector16;__asm__("" : "=r"(call4):"0"(call4));position17Again=&moby->position;func_8004F178((Vector3D*)call4,position17Again);
        frame.sp38.z = Controller79A14Field(linkedTag20, int *, 8) + 0x200;
        if (Controller79A14_func_8001BA30(&frame.sp38, 0x12C, 0, 0, 0x10000000, moby) != 0) {
            Controller79A14_func_8003BB10(moby, 4, 0);__asm__ volatile("":::"memory");
            goto block_42;
        }
        if (Controller79A14_func_8001C288(position17Again, 0x190, 0x26) != 0) {
            if (Controller79A14Field(tag19, unsigned char *, 0xC) != 0) {
                func_8004F178(position17Again, &Controller79A14_D_80070328);
                Controller79A14_func_8003BB10(moby, 4, 0);__asm__ volatile("":::"memory");
                goto block_42;
            }
            Controller79A14_func_80055F14(moby, 0, &frame.sp48);
            Controller79A14_func_8004F1C8(&frame.sp48, position17Again, (Vector3D *) &frame.sp48);
            func_8004F194(position17Again, &Controller79A14_D_80070328, (Vector3D *) &frame.sp48);
            Controller79A14Field(tag19, int *, 4) = 0x2D;
            Controller79A14_func_80034F80(moby, 2);
            moby->state = 1;
            return;
        }
        if ((func_800359A4(tag19 + 4, 4) != 0) || ((Controller79A14Field(tag19, unsigned char *, 0xC) == 0) && (Controller79A14Field(Controller79A14Field(tag19, void **, 0), unsigned char *, 0x48) == 2))) {
            moby->size = 0x20;
block_42:
            moby->state = 2;
            return;
        }
        return;
    case 1:
        moby->angle.pitch += Controller79A14Field(tag19, unsigned char *, 0xD);
        moby->angle.yaw += Controller79A14Field(tag19, unsigned char *, 0xE);
        Controller79A14_func_80055D24(moby, 4);
        Controller79A14_func_80055F14(moby, 0, &frame.sp58);
        call4=(int)&frame.sp58;__asm__("" : "=r"(call4):"0"(call4));position17Last = &moby->position;
        Controller79A14_func_8004F1C8(call4, position17Last, (Vector3D *) &frame.sp58);
        func_8004F194(position17Last, &Controller79A14_D_80070328, (Vector3D *) &frame.sp58);
        if (func_800359A4(tag19 + 4, 4) != 0) {
goto block_47;
        }
        break;
    case 2:
        sizeByte = moby->size;
        if (sizeByte < 0x78U) {
            moby->size = sizeByte + 8;
            return;
        }
block_47:func_80055B18(moby);
        break;
    }
}
#undef Controller79A14Field


/* AI generated; not human reviewed. SCUS-94467 USA Rev0
 * Original raw447 local controller words are authoritative. Factory
 * descendants, private producer, live counter writers/cadence unresolved. */
extern int D_8006C578,D_8006C574,D_8006C648,D_8006C770;
extern int DecodedRaw447Counters[] __asm__("D_80066EEC");
extern unsigned char DecodedRaw447Player[] __asm__("D_80070328");
int func_80037A60(Moby*,void*,int,int,int);
void func_level_27_80079ED0(Moby* argument) {
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
void func_level_27_8007A230(Moby* moby) {
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007A3C0.
 * AI generated; not human reviewed. All804 native/linked instructions and
 * actual branch,call and internal destinations must match. No owned selector
 * or padding words occur in this function. FrameA0 saves S0..S7/FP/RA and
 * retains SP38..77 local storage and original13-argument callback slots.
 * Natural FP is an ordinary initialized scalar; no fixedFP binding is used.
 * Signed LH trig samples and the complete3636C result feed both MULTs.
 * Each complete signed64 C product has both original operands. Empty
 * metadata takes the complete HILO pair and names its original signed low32
 * word; the following whole-word consumer retains the original SRA12.
 * It emits no CPU instruction. No isolated partial high value,wrong product,
 * incoming hardware value or synthetic multiplication is supplied.
 * Original538 MULT precedes539 SP60 count load. Complete count and result
 * phases share T1 sequentially:539/541/542 load,increment,store the count;
 * original543 then moves the independent low product into fresh T1.
 * Falsifiable arithmetic vectors:32767*11000=360437000,whose signed>>12 is
 * 87997; -32768*6000=-196608000,whose signed>>12 is-48000. These assert raw
 * instruction arithmetic; physical sample/speed units remain unresolved.
 * CRC BYTE views,private/list WORDs,signed LH widths,spawned-record phases,
 * height updates and callback argument producers retain their disc order.
 * Other empty metadata consumes initialized words/addresses or written
 * fields,or clobbers dead values before fresh complete producers. No live
 * GP aliases overlap. Compiler,filter,flags and all gates are unchanged.
 * Known timer,RNG and angle contracts reuse mobyutil.h/stdutil.h and the
 * matched EXE. Confidence is binary identity after every data/hash gate;
 * full helper/caller semantics,cadence beyond invocation,Rev1 mapping and
 * synchronized retail runtime are open. Next:human review and captures.
 * Falsification:every original word,actual transfer,owned byte and complete
 * EXE/every-overlay retail hash must remain identical.
 */
/* Original assembly SHA256 9a73dfbc133dca3fb41ae5f6a177403e292f16d1d722faf536a371ec73de640c */
#define Level27_7A3C0Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Level27_7A3C0Call34F40View1() __asm__("func_80034F40");
int Level27_7A3C0Call35734View1() __asm__("func_80035734");
int Level27_7A3C0Call359A4View1(void*,int) __asm__("func_800359A4");
int Level27_7A3C0Call3636CView1(int,int) __asm__("func_8003636C");
int Level27_7A3C0Call365E4View1() __asm__("func_800365E4");
int Level27_7A3C0Call37BBCView1() __asm__("func_80037BBC");
int Level27_7A3C0Call3B7B4View1() __asm__("func_8003B7B4");
int Level27_7A3C0Call3BABCView1() __asm__("func_8003BABC");
int Level27_7A3C0Call4E880View1(int,int,int) __asm__("func_8004E880");
int Level27_7A3C0Call4F178View1() __asm__("func_8004F178");
int Level27_7A3C0Call4F194View1() __asm__("func_8004F194");
int Level27_7A3C0Call4F334View1() __asm__("func_8004F334");
int Level27_7A3C0Call512E4View1() __asm__("func_800512E4");
int Level27_7A3C0Call55B18View1() __asm__("func_80055B18");
int Level27_7A3C0DatarandView1(void) __asm__("rand");
extern int Level27_7A3C0Data658A0View1 __asm__("D_800658A0");
extern int Level27_7A3C0Data65920View1 __asm__("D_80065920");
extern unsigned char Level27_7A3C0Data6C409View1 __asm__("D_8006C409");
extern int Level27_7A3C0Data6C550View1 __asm__("D_8006C550");
extern int Level27_7A3C0Data6C598View1 __asm__("D_8006C598");
extern int Level27_7A3C0Data6C770View1 __asm__("D_8006C770");
extern int Level27_7A3C0Data6C7C4View1 __asm__("D_8006C7C4");
extern int Level27_7A3C0Data6C7F8View1 __asm__("D_8006C7F8");
extern int Level27_7A3C0Data6D088View1 __asm__("D_8006D088");
extern int Level27_7A3C0Data6E344View1 __asm__("D_8006E344");
extern int Level27_7A3C0Data6E788View1 __asm__("D_8006E788");
extern int Level27_7A3C0Data70300View1 __asm__("D_80070300");
extern int Level27_7A3C0Data70328View1 __asm__("D_80070328");
extern signed char Level27_7A3C0Data71586View1 __asm__("D_80071586");
extern signed char Level27_7A3C0Data71587View1 __asm__("D_80071587");
extern unsigned char Level27_7A3C0Data7158DView1 __asm__("D_8007158D");
extern int Level27_7A3C0Data722B8View1 __asm__("D_800722B8");
extern int(*Level27_7A3C0DataSpawnMobyView1)() __asm__("SpawnMoby");
extern int(*Level27_7A3C0Data74314View1)() __asm__("unk_ovlheader_80074314");
extern int Level27_7A3C0Data74448View1 __asm__("unk_ovlheader_80074448");
extern unsigned char Level27_7A3C0Call3A40CView1 __asm__("func_8003A40C");
extern unsigned char Level27_7A3C0Call3A584View1 __asm__("func_8003A584");
extern unsigned char Level27_7A3C0Data70300View2 __asm__("D_80070300 + 0x1");
extern unsigned char Level27_7A3C0Data70300View3 __asm__("D_80070300 + 0x2");
extern unsigned char Level27_7A3C0Data70300View4 __asm__("D_80070300 + 0x3");
extern unsigned char Level27_7A3C0Data70300View5 __asm__("D_80070300 + 0x4");
extern unsigned char Level27_7A3C0Data70300View6 __asm__("D_80070300 + 0xa");
extern unsigned char Level27_7A3C0Data70300View7 __asm__("D_80070300 + 0xb");
extern unsigned char Level27_7A3C0Data70300View8 __asm__("D_80070300 + 0xc");
extern unsigned char Level27_7A3C0Data70300View9 __asm__("D_80070300 + 0xd");
extern int Level27_7A3C0Data70328View2 __asm__("D_80070328");
extern int Level27_7A3C0Data70328View3 __asm__("D_80070328 + 4");
void func_level_27_8007A3C0(void *ownerParameter) {
    register int rawWord2 __asm__("$2"),rawWord3 __asm__("$3"),argumentWord4 __asm__("$4"),argumentWord5 __asm__("$5"),argumentWord6 __asm__("$6"),argumentWord7 __asm__("$7"),temporaryWord8 __asm__("$8"),countOrSignedLowProduct9 __asm__("$9");
    register void *ownerRecord21 __asm__("$21");
    register int privateRecord20 __asm__("$20"),retainedCountRecordOrSineBase16 __asm__("$16"),retainedCountRecordOrSineAddress17 __asm__("$17"),retainedLinkedRecordOrPosition18 __asm__("$18"),retainedOriginalPosition19 __asm__("$19"),retainedOriginalAngle23 __asm__("$23"),retainedCreatedRecord22 __asm__("$22");
    struct{
        int sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74;
    }
    originalFrame;
    int retainedFramePhaseScalar;
    ownerRecord21=ownerParameter;
    __asm__("":"=r"(ownerRecord21):"0"(ownerRecord21));
    argumentWord4=(int)ownerRecord21+12;
    __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
    retainedFramePhaseScalar=0;
    originalFrame.sp60 = 0;
    privateRecord20 = Level27_7A3C0Field(ownerRecord21, void **, 0);
    __asm__(""::"r"(privateRecord20):"$16");
    retainedCountRecordOrSineBase16=0;
    rawWord3=Level27_7A3C0Field(privateRecord20,int*,0x38);
    __asm__("":"=r"(rawWord3):"0"(rawWord3):"$17");
    retainedCountRecordOrSineAddress17=1;
    rawWord2=rawWord3*88;
    rawWord3=Level27_7A3C0Data6C550View1;
    retainedLinkedRecordOrPosition18=rawWord3+rawWord2;
    countOrSignedLowProduct9=Level27_7A3C0Field(retainedLinkedRecordOrPosition18,int*,0);
    argumentWord5=retainedLinkedRecordOrPosition18+12;
    originalFrame.sp50=countOrSignedLowProduct9;
    originalFrame.sp58=Level27_7A3C0Call4F334View1(argumentWord4,argumentWord5);
    rawWord2=2;
    argumentWord4=Level27_7A3C0Data6C7C4View1;
    rawWord3=Level27_7A3C0Data6C409View1;
    if(argumentWord4==rawWord2){
        rawWord3-=4;
        if(rawWord3<0)rawWord3=0;
    }
    else if(argumentWord4==retainedCountRecordOrSineAddress17)rawWord3+=2;
    else if(argumentWord4==0)rawWord3+=5;
    if (Level27_7A3C0Data7158DView1 != 0) {
        rawWord3 = 0;
    }
    if ((int) rawWord3 <= 0) {
        retainedCountRecordOrSineAddress17 = 0;
    }
    if(({rawWord2=rawWord3<5;__asm__("":"=r"(rawWord2):"0"(rawWord2));!rawWord2;})) {
        retainedCountRecordOrSineAddress17 = 2;
    }
    if (Level27_7A3C0Field(privateRecord20, short *, 0x36) == 0) {
        Level27_7A3C0Field(privateRecord20, short *, 0x36) = 1;
        Level27_7A3C0Field(privateRecord20, short *, 0x34) = Level27_7A3C0Call3636CView1(0xB4, 0x1F4);
    }
    if (Level27_7A3C0Field(privateRecord20, unsigned char **, 0x4C) == 0) {
        Level27_7A3C0Field(privateRecord20, unsigned char **, 0x4C) = &Level27_7A3C0Call3A40CView1;
    }
    rawWord3 = Level27_7A3C0Field(privateRecord20, unsigned char **, 0x4C);
    argumentWord4 = 0;
    if ((unsigned int) rawWord3 < (unsigned int) &Level27_7A3C0Call3A584View1) {
        argumentWord5 = 0x80050000;
        Level27_7A3C0Field(privateRecord20, int *, 0x48) = (int) (Level27_7A3C0Field(privateRecord20, int *, 0x48) ^ (Level27_7A3C0Field(rawWord3,unsigned char*,0) << 0x18));
        do {
            rawWord2 = Level27_7A3C0Field(privateRecord20, int *, 0x48);
            if (rawWord2 < 0) {
                rawWord2 = (rawWord2 * 2) ^ 0x80050000;
            }
            else {
                rawWord2 = rawWord2 * 2;
            }
            Level27_7A3C0Field(privateRecord20, int *, 0x48) = rawWord2;
            argumentWord4 += 1;
        }
        while (argumentWord4 < 8);
        Level27_7A3C0Field(privateRecord20, unsigned char **, 0x4C) = (unsigned char *) (Level27_7A3C0Field(privateRecord20, unsigned char **, 0x4C) + 1);
    }
    else {
        argumentWord5 = 0xFFFF0;
        if (((((int) Level27_7A3C0Field(privateRecord20, int *, 0x48) >> 0xC) & 0xFFFF0) | (Level27_7A3C0Data722B8View1 & 0xFFF0000F)) != Level27_7A3C0Data74448View1) {
            rawWord2=Level27_7A3C0Data70300View2;
            argumentWord4=Level27_7A3C0Data70300View4;
            rawWord3=Level27_7A3C0Data70300View5;
            rawWord2^=1;
            Level27_7A3C0Data70300View2=rawWord2;
            rawWord2=Level27_7A3C0Data70300View3;
            rawWord3^=1;
            Level27_7A3C0Data70300View5=rawWord3;
            rawWord3=Level27_7A3C0Data70300View7;
            Level27_7A3C0Data71587View1=0;
            Level27_7A3C0Data71586View1=0;
            Level27_7A3C0Data70300View4=argumentWord4;
            rawWord2^=1;
            Level27_7A3C0Data70300View3=rawWord2;
            rawWord2=Level27_7A3C0Data70300View6;
            rawWord3^=1;
            Level27_7A3C0Data70300View7=rawWord3;
            rawWord3=Level27_7A3C0Data70300View9;
            rawWord2^=1;
            Level27_7A3C0Data70300View6=rawWord2;
            rawWord2=Level27_7A3C0Data70300View8;
            rawWord3^=1;
            Level27_7A3C0Data70300View9=rawWord3;
            rawWord2^=1;
            Level27_7A3C0Data70300View8=rawWord2;
            Level27_7A3C0Field(privateRecord20, int *, 0x48) = 0;
        }
    }
    rawWord3 = Level27_7A3C0Field(ownerRecord21, unsigned char *, 0x48);
    switch (rawWord3) {
    case 0:
        rawWord2=Level27_7A3C0Field(ownerRecord21,unsigned char*,0x49);
        rawWord3=1;
        if(rawWord2){
            rawWord2=Level27_7A3C0Data6E344View1;
            retainedCountRecordOrSineBase16=privateRecord20+0x44;
            if(rawWord2==rawWord3)return;
            argumentWord4=retainedCountRecordOrSineBase16;
            argumentWord5=4;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            retainedLinkedRecordOrPosition18=(int)&Level27_7A3C0Data6D088View1;
            __asm__("":"=r"(retainedLinkedRecordOrPosition18):"0"(retainedLinkedRecordOrPosition18));
            argumentWord6=retainedLinkedRecordOrPosition18;
            Level27_7A3C0Field(privateRecord20,int*,0x44)=rawWord3;
            Level27_7A3C0Call3B7B4View1(argumentWord4,argumentWord5,argumentWord6);
            argumentWord4=retainedCountRecordOrSineBase16;
            argumentWord5=4;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            retainedCountRecordOrSineAddress17=(int)&Level27_7A3C0Data6C7F8View1;
            __asm__("":"=r"(retainedCountRecordOrSineAddress17):"0"(retainedCountRecordOrSineAddress17));
            Level27_7A3C0Call3B7B4View1(argumentWord4,argumentWord5,retainedCountRecordOrSineAddress17);
            argumentWord4=(int)ownerRecord21;
            argumentWord5=1;
            rawWord2=1;
            Level27_7A3C0Field(ownerRecord21,unsigned char*,0x48)=rawWord2;
            goto stateZeroCall;
        }
        rawWord2=Level27_7A3C0Field(privateRecord20,int*,0x44);
        if(rawWord2){
            rawWord2=1;
            Level27_7A3C0Field(ownerRecord21,unsigned char*,0x48)=rawWord2;
            argumentWord4=(int)ownerRecord21;
            argumentWord5=1;
            stateZeroCall:Level27_7A3C0Call34F40View1(argumentWord4,argumentWord5);
            retainedCountRecordOrSineBase16=(int)ownerRecord21+0x48;
            Level27_7A3C0Call3B7B4View1(retainedCountRecordOrSineBase16,1,(int)&Level27_7A3C0Data6D088View1);
            Level27_7A3C0Call3B7B4View1(retainedCountRecordOrSineBase16,1,(int)&Level27_7A3C0Data6C7F8View1);
            return;
        }
        retainedCountRecordOrSineBase16=1;
        Level27_7A3C0Field(ownerRecord21,short*,0x38)=0;
        Level27_7A3C0Field(privateRecord20,unsigned char*,5)=retainedCountRecordOrSineBase16;
        rawWord2=Level27_7A3C0Data6C598View1;
        argumentWord4=(int)ownerRecord21;
        if(rawWord2)return;
        __asm__("":::"$2","$3");
        rawWord2=Level27_7A3C0Call37BBCView1(argumentWord4,0);
        argumentWord4=(int)ownerRecord21;
        if(!rawWord2)return;
        Level27_7A3C0Call512E4View1(argumentWord4,1,0);
        Level27_7A3C0Field(ownerRecord21,unsigned char*,0x49)=retainedCountRecordOrSineBase16;
        return;
    case 1:
        rawWord3=(int)&Level27_7A3C0Data6E788View1;
        rawWord2=Level27_7A3C0Field(rawWord3,int*,0);
        rawWord3+=4;
        if(rawWord2){
            temporaryWord8=639;
            __asm__("":"=r"(temporaryWord8):"0"(temporaryWord8):"$7");
            argumentWord7=640;
            __asm__("":"=r"(argumentWord7):"0"(argumentWord7):"$6");
            argumentWord6=447;
            __asm__("":"=r"(argumentWord6):"0"(argumentWord6):"$5");
            argumentWord5=16;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5):"$4");
            argumentWord4=211;
            do{
                rawWord2=Level27_7A3C0Field(rawWord2,short*,0x36);
                if(rawWord2==temporaryWord8){
                    countOrSignedLowProduct9=originalFrame.sp60;
                    countOrSignedLowProduct9++;
                    originalFrame.sp60=countOrSignedLowProduct9;
                }
                if(rawWord2==argumentWord7)retainedFramePhaseScalar++;
                if(rawWord2==argumentWord6)retainedCountRecordOrSineBase16++;
                if(rawWord2==argumentWord5||rawWord2==argumentWord4)retainedCountRecordOrSineBase16++;
                rawWord2=Level27_7A3C0Field(rawWord3,int*,0);
                rawWord3+=4;
            }
            while(rawWord2);
        }
        if (Level27_7A3C0Field(ownerRecord21, unsigned char *, 0x3D) != 1) {
            Level27_7A3C0Data6C770View1 = 0;
            Level27_7A3C0Field(ownerRecord21, signed char *, 0x40) = 0x72;
            Level27_7A3C0Field(ownerRecord21, unsigned char *, 0x3D) = 1U;
            Level27_7A3C0Field(ownerRecord21, signed char *, 0x3F) = 0;
            Level27_7A3C0Call35734View1(ownerRecord21);
        }
        if (Level27_7A3C0Field(ownerRecord21, int *, 0x14) >= 0x2019) {
            if (Level27_7A3C0Field(ownerRecord21, unsigned char *, 0x4F) == 0) {
                Level27_7A3C0Field(ownerRecord21, unsigned char *, 0x4F) = 0x20U;
            }
            rawWord2=Level27_7A3C0Field(ownerRecord21,volatile unsigned char*,0x4F)-1;
            Level27_7A3C0Field(ownerRecord21, unsigned char *, 0x4F) = rawWord2;
            if ((unsigned int) (rawWord2 & 0xFF) < 0x18U) {
                Level27_7A3C0Field(ownerRecord21, unsigned char *, 0x4F) = 0x18U;
            }
        }
        argumentWord4=Level27_7A3C0Field(ownerRecord21,int*,20);
        rawWord2=9216;
        rawWord3=rawWord2-argumentWord4;
        if(rawWord3>=121){
            rawWord3=120;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
        }
        if(rawWord3< -120){
            rawWord3=-120;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
        }
        rawWord2=argumentWord4+rawWord3;
        Level27_7A3C0Field(ownerRecord21,int*,20)=rawWord2;
        if (({rawWord2=Level27_7A3C0Field(privateRecord20,int*,0x3C);argumentWord6=0;rawWord2==0;}) && (Level27_7A3C0Field(({countOrSignedLowProduct9=originalFrame.sp50;__asm__("":"=r"(countOrSignedLowProduct9):"0"(countOrSignedLowProduct9));countOrSignedLowProduct9;}), int *, 0x28) > 0) && (retainedFramePhaseScalar < 4)) {
            rawWord3=Level27_7A3C0Field(ownerRecord21,int*,12);
            argumentWord4=Level27_7A3C0Data70328View2;
            rawWord2=Level27_7A3C0Field(ownerRecord21,int*,16);
            argumentWord5=Level27_7A3C0Data70328View3;
            Level27_7A3C0Call4E880View1(rawWord3-argumentWord4,rawWord2-argumentWord5,argumentWord6);
            rawWord3=Level27_7A3C0Field(privateRecord20,int*,0x24);
            __asm__("":"=r"(rawWord3):"0"(rawWord3):"$4");
            argumentWord4=rawWord2;
            rawWord3=Level27_7A3C0Field(rawWord3,short*,10);
            __asm__("":"=r"(rawWord3):"0"(rawWord3):"$2");
            rawWord2=1;
            argumentWord7=argumentWord4-8;
            if(rawWord3==rawWord2)argumentWord7=argumentWord4+8;
            argumentWord4=(int)ownerRecord21;
            argumentWord5=(int)&Level27_7A3C0Data70328View1;
            argumentWord6=Level27_7A3C0Field(privateRecord20,int*,0x30);
            Level27_7A3C0Data74314View1(argumentWord4,argumentWord5,argumentWord6>>1,argumentWord7&255,4,200,3,128,255,255,0,0,0);
        }
        else{
            rawWord2=Level27_7A3C0Field(privateRecord20,int*,0x24);
            argumentWord7=Level27_7A3C0Field(ownerRecord21,int*,12);
            rawWord2=Level27_7A3C0Field(rawWord2,int*,12);
            rawWord3=Level27_7A3C0Field(ownerRecord21,int*,16);
            argumentWord4=Level27_7A3C0Field(rawWord2,int*,0);
            argumentWord5=Level27_7A3C0Field(rawWord2,int*,4);
            Level27_7A3C0Call4E880View1(argumentWord7-argumentWord4,rawWord3-argumentWord5,argumentWord6);
            rawWord3=Level27_7A3C0Field(privateRecord20,int*,0x24);
            __asm__("":"=r"(rawWord3):"0"(rawWord3):"$4");
            argumentWord4=rawWord2;
            rawWord3=Level27_7A3C0Field(rawWord3,short*,10);
            __asm__("":"=r"(rawWord3):"0"(rawWord3):"$2");
            rawWord2=1;
            argumentWord7=argumentWord4-8;
            if(rawWord3==rawWord2)argumentWord7=argumentWord4+8;
            argumentWord4=(int)ownerRecord21;
            rawWord3=Level27_7A3C0Field(privateRecord20,int*,0x24);
            Level27_7A3C0Data74314View1(argumentWord4,Level27_7A3C0Field(rawWord3,int*,12),Level27_7A3C0Field(privateRecord20,int*,0x30),argumentWord7&255,4,200,3,128,255,255,0,0,0);
        }
        if ((unsigned char) Level27_7A3C0Field(retainedLinkedRecordOrPosition18, unsigned char *, 0x48) < 0x80U) {
            if ((Level27_7A3C0Field(ownerRecord21, unsigned char *, 0x4C) != 0) && ({rawWord2=retainedCountRecordOrSineBase16<retainedCountRecordOrSineAddress17;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord2;}) && (Level27_7A3C0Field((int)&Level27_7A3C0Data70328View1, int *, 0x280) < 2) && (Level27_7A3C0Call359A4View1(privateRecord20 + 0x34, 2) != 0)) {
                retainedCountRecordOrSineAddress17=Level27_7A3C0DataSpawnMobyView1(447,ownerRecord21);
                __asm__("":"=r"(retainedCountRecordOrSineAddress17):"0"(retainedCountRecordOrSineAddress17));
                if (retainedCountRecordOrSineAddress17 != 0) {
                    retainedCountRecordOrSineBase16 = Level27_7A3C0Field(retainedCountRecordOrSineAddress17, void **, 0);
                    Level27_7A3C0Call4F178View1(retainedCountRecordOrSineAddress17 + 0xC, ownerRecord21 + 0xC);
                    Level27_7A3C0Field(retainedCountRecordOrSineAddress17, unsigned char *, 0x4A) = 0xFF;
                    Level27_7A3C0Field(retainedCountRecordOrSineAddress17, signed char *, 0x48) = 0xA;
                    Level27_7A3C0Field(retainedCountRecordOrSineBase16, int *, 8) = -0x28;
                }
                Level27_7A3C0Field(privateRecord20, short *, 0x34) = Level27_7A3C0Call3636CView1(0x12C, 0x2BC);
            }
            rawWord2 = Level27_7A3C0Field(({countOrSignedLowProduct9=originalFrame.sp50;__asm__("":"=r"(countOrSignedLowProduct9):"0"(countOrSignedLowProduct9));countOrSignedLowProduct9;}), int *, 0x28);
            if (rawWord2 == 0) {
                if(({countOrSignedLowProduct9=originalFrame.sp60;rawWord2=countOrSignedLowProduct9<4;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord2;})) {
                    if (Level27_7A3C0Call359A4View1(privateRecord20 + 0x40, 2) != 0) {
                        retainedCreatedRecord22=Level27_7A3C0DataSpawnMobyView1(639,ownerRecord21);
                        __asm__("":"=r"(retainedCreatedRecord22):"0"(retainedCreatedRecord22));
                        if (retainedCreatedRecord22 != 0) {
                            retainedLinkedRecordOrPosition18 = Level27_7A3C0Field(retainedCreatedRecord22, void **, 0);
                            Level27_7A3C0Field(retainedCreatedRecord22, int *, 0x1C) = (int) (Level27_7A3C0Field(retainedCreatedRecord22, int *, 0x1C) | 0x80000000);
                            rawWord2=Level27_7A3C0DatarandView1();
                            retainedOriginalAngle23=rawWord2&255;
                            __asm__("":"=r"(retainedOriginalAngle23):"0"(retainedOriginalAngle23));
                            argumentWord4=retainedOriginalAngle23*2;
                            rawWord3=Level27_7A3C0Field((int)&Level27_7A3C0Data65920View1,short*,argumentWord4);
                            __asm__("":"=r"(rawWord3):"0"(rawWord3):"$16");
                            retainedCountRecordOrSineBase16=(int)&Level27_7A3C0Data65920View1;
                            __asm__("":"=r"(retainedCountRecordOrSineBase16):"0"(retainedCountRecordOrSineBase16));
                            rawWord2=rawWord3*125;
                            rawWord2>>=11;
                            Level27_7A3C0Field(retainedLinkedRecordOrPosition18,int*,0)=rawWord2;
                            rawWord2=retainedOriginalAngle23+128;
                            retainedOriginalAngle23=rawWord2&255;
                            retainedCountRecordOrSineAddress17=retainedOriginalAngle23*2;
                            __asm__("":"=r"(retainedCountRecordOrSineAddress17):"0"(retainedCountRecordOrSineAddress17));
                            rawWord3=Level27_7A3C0Field((int)&Level27_7A3C0Data658A0View1,short*,argumentWord4);
                            retainedCountRecordOrSineBase16=retainedCountRecordOrSineAddress17+retainedCountRecordOrSineBase16;
                            Level27_7A3C0Field(retainedLinkedRecordOrPosition18,int*,8)=0;
                            rawWord2=rawWord3*125;
                            rawWord2>>=11;
                            Level27_7A3C0Field(retainedLinkedRecordOrPosition18,int*,4)=rawWord2;
                            rawWord3=Level27_7A3C0Field(retainedCountRecordOrSineBase16,short*,0);
                            rawWord2=rawWord3*15;
                            rawWord2>>=2;
                            originalFrame.sp38=rawWord2;
                            rawWord2=(int)&Level27_7A3C0Data658A0View1;
                            retainedCountRecordOrSineAddress17+=rawWord2;
                            rawWord3=Level27_7A3C0Field(retainedCountRecordOrSineAddress17,short*,0);
                            __asm__("":"=r"(rawWord3):"0"(rawWord3):"$19");
                            retainedOriginalPosition19=retainedCreatedRecord22+12;
                            __asm__("":"=r"(retainedOriginalPosition19):"0"(retainedOriginalPosition19));
                            originalFrame.sp40=0;
                            __asm__(""::"m"(originalFrame.sp40),"r"(rawWord3));
                            rawWord2=rawWord3*15;
                            rawWord2>>=2;
                            originalFrame.sp3C=rawWord2;
                            rawWord2=Level27_7A3C0Field(privateRecord20,int*,0x24);
                            __asm__("":"=r"(rawWord2):"0"(rawWord2):"$6");
                            argumentWord6=(int)&originalFrame.sp38;
                            __asm__("":"=r"(argumentWord6):"0"(argumentWord6));
                            argumentWord5=Level27_7A3C0Field(rawWord2,int*,12);
                            Level27_7A3C0Call4F194View1(retainedOriginalPosition19,argumentWord5,argumentWord6);
                            rawWord2=Level27_7A3C0Call3636CView1(6000,11000);
                            {
                                long long firstCompleteSignedProduct;
                                int firstSignedLowWord;
                                rawWord3=Level27_7A3C0Field(retainedCountRecordOrSineBase16,short*,0);
                                firstCompleteSignedProduct=(long long)rawWord3*(long long)rawWord2;
                                __asm__("":"=l"(firstSignedLowWord):"x"(firstCompleteSignedProduct));
                                countOrSignedLowProduct9=firstSignedLowWord;
                                __asm__("":"=r"(countOrSignedLowProduct9):"0"(countOrSignedLowProduct9));
                                rawWord3=countOrSignedLowProduct9>>12;
                                originalFrame.sp38=rawWord3;
                            }
                            {
                                long long secondCompleteSignedProduct;
                                int secondSignedLowWord;
                                rawWord3=Level27_7A3C0Field(retainedCountRecordOrSineAddress17,short*,0);
                                secondCompleteSignedProduct=(long long)rawWord3*(long long)rawWord2;
                                __asm__("":"=l"(secondSignedLowWord):"x"(secondCompleteSignedProduct));
                                countOrSignedLowProduct9=originalFrame.sp60;
                                originalFrame.sp40=0;
                                countOrSignedLowProduct9++;
                                originalFrame.sp60=countOrSignedLowProduct9;
                                countOrSignedLowProduct9=secondSignedLowWord;
                                __asm__("":"=r"(countOrSignedLowProduct9):"0"(countOrSignedLowProduct9));
                                rawWord3=countOrSignedLowProduct9>>12;
                                originalFrame.sp3C=rawWord3;
                            }
                            rawWord3=Level27_7A3C0Field(privateRecord20,int*,0x24);
                            argumentWord4=(int)&originalFrame.sp38;
                            argumentWord5=Level27_7A3C0Field(rawWord3,int*,12);
                            argumentWord6=argumentWord4;
                            originalFrame.sp48=rawWord2;
                            Level27_7A3C0Call4F194View1(argumentWord4,argumentWord5,argumentWord6);
                            Level27_7A3C0Field(retainedLinkedRecordOrPosition18,int*,8)=Level27_7A3C0Call365E4View1(retainedOriginalPosition19,&originalFrame.sp38,250,-16,&originalFrame.sp48);
                            Level27_7A3C0Field(retainedCreatedRecord22, signed char *, 0x48) = 0xA;
                            Level27_7A3C0Field(retainedCreatedRecord22, signed char *, 0x4C) = 0x3F;
                            Level27_7A3C0Field(retainedCreatedRecord22, signed char *, 0x4E) = 0x3F;
                            Level27_7A3C0Field(retainedCreatedRecord22, signed char *, 0x46) = retainedOriginalAngle23;
                            Level27_7A3C0Field(retainedLinkedRecordOrPosition18, signed char *, 0x13) = 0;
                            Level27_7A3C0Field(retainedLinkedRecordOrPosition18, short *, 0x14) = 0xA;
                            Level27_7A3C0Call3BABCView1(retainedCreatedRecord22, 0, 0);
                            countOrSignedLowProduct9=originalFrame.sp60;
                            rawWord2=countOrSignedLowProduct9*240;
                            Level27_7A3C0Field(privateRecord20,short*,0x40)=rawWord2;
                            if (Level27_7A3C0Field(({countOrSignedLowProduct9=originalFrame.sp50;__asm__("":"=r"(countOrSignedLowProduct9):"0"(countOrSignedLowProduct9));countOrSignedLowProduct9;}), int *, 0x28) == 0) {
                                rawWord3 = Level27_7A3C0Field(privateRecord20, void **, 0x24);
                                rawWord2=Level27_7A3C0Field(rawWord3,short*,10);
                                __asm__("":"=r"(rawWord2):"0"(rawWord2):"$5");
                                argumentWord5=9000;
                                __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
                                rawWord2=-rawWord2;
                                Level27_7A3C0Field(rawWord3,short*,10)=rawWord2;
                                Level27_7A3C0Field(privateRecord20, int *, 0x30) = Level27_7A3C0Call3636CView1(0xFA0,argumentWord5);
                            }
                        }
                    }
                    if(({rawWord2=Level27_7A3C0Field(privateRecord20,short*,0x42);countOrSignedLowProduct9=originalFrame.sp60;rawWord2=countOrSignedLowProduct9<rawWord2;__asm__("":"=r"(rawWord2):"0"(rawWord2));rawWord2;})) {
                        switch(countOrSignedLowProduct9) {
                        case 0:
                            Level27_7A3C0Field(privateRecord20, short *, 0x40) = 0;
                            break;
                        case 1:
                            if (Level27_7A3C0Field(privateRecord20, short *, 0x40) >= 0xF1) {
                                Level27_7A3C0Field(privateRecord20, short *, 0x40) = 0xF0;
                            }
                            break;
                        }
                    }
                }
                rawWord2 = Level27_7A3C0Field(({countOrSignedLowProduct9=originalFrame.sp50;__asm__("":"=r"(countOrSignedLowProduct9):"0"(countOrSignedLowProduct9));countOrSignedLowProduct9;}), int *, 0x28);
            }
            if (rawWord2 > 0) {
                if (retainedFramePhaseScalar < 4) {
                    if (Level27_7A3C0Field(privateRecord20, void **, 0x3C) == 0) {
                        if ((Level27_7A3C0Call359A4View1(privateRecord20 + 0x2C, 2) != 0) && ({countOrSignedLowProduct9=originalFrame.sp58;rawWord2=countOrSignedLowProduct9<2501;__asm__("":"=r"(rawWord2):"0"(rawWord2));!rawWord2;}) && (Level27_7A3C0Field(ownerRecord21, unsigned char *, 0x4D) == 0)) {
                            argumentWord5=Level27_7A3C0DataSpawnMobyView1(640,ownerRecord21);
                            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
                            Level27_7A3C0Field(privateRecord20,int*,0x3C)=argumentWord5;
                            if(argumentWord5){
                                argumentWord4=0x80000000;
                                rawWord2=Level27_7A3C0Field(argumentWord5,int*,0x1C);
                                rawWord3=Level27_7A3C0Field(argumentWord5,int*,0);
                                rawWord2|=argumentWord4;
                                Level27_7A3C0Field(argumentWord5,int*,0x1C)=rawWord2;
                                Level27_7A3C0Field(rawWord3, short *, 0) = 0;
                                Level27_7A3C0Field(rawWord3, short *, 2) = 0;
                                Level27_7A3C0Field(rawWord3, short *, 4) = 0;
                                Level27_7A3C0Field(Level27_7A3C0Field(privateRecord20, void **, 0x3C), signed char *, 0x48) = 0xD;
                                Level27_7A3C0Field(Level27_7A3C0Field(privateRecord20, void **, 0x3C), signed char *, 0x4C) = 0x3F;
                                Level27_7A3C0Field(Level27_7A3C0Field(privateRecord20, void **, 0x3C), signed char *, 0x4E) = 0x3F;
                                Level27_7A3C0Field(rawWord3, signed char *, 0x13) = 1;
                                Level27_7A3C0Field(rawWord3, signed char *, 0x14) = 0xA;
                                Level27_7A3C0Field(rawWord3, signed char *, 0x15) = (signed char) Level27_7A3C0Field(({countOrSignedLowProduct9=originalFrame.sp50;__asm__("":"=r"(countOrSignedLowProduct9):"0"(countOrSignedLowProduct9));countOrSignedLowProduct9;}), int *, 0x28);
                                Level27_7A3C0Field(rawWord3, short *, 0xE) = (short) Level27_7A3C0Field(privateRecord20, int *, 0x38);
                                Level27_7A3C0Field(Level27_7A3C0Field(privateRecord20, void **, 0x3C), unsigned char *, 0x46) = (unsigned char) Level27_7A3C0Field(ownerRecord21, unsigned char *, 0x46);
                                Level27_7A3C0Call4F178View1(Level27_7A3C0Field(privateRecord20, void **, 0x3C) + 0xC, ownerRecord21 + 0xC);
                                retainedFramePhaseScalar += 1;
                                argumentWord5 = Level27_7A3C0Field(privateRecord20, void **, 0x3C);
                                Level27_7A3C0Field(argumentWord5, int *, 0x14) = (int) (Level27_7A3C0Field(argumentWord5, int *, 0x14) - Level27_7A3C0Field((int)&Level27_7A3C0Data70328View1, int *, 0x44));
                                rawWord3 = Level27_7A3C0Field(privateRecord20, void **, 0x24);
                                Level27_7A3C0Field(privateRecord20, short *, 0x2C) = 0x96;
                                rawWord2=Level27_7A3C0Field(rawWord3,short*,10);
                                __asm__("":"=r"(rawWord2):"0"(rawWord2):"$5");
                                argumentWord5=9000;
                                __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
                                rawWord2=-rawWord2;
                                Level27_7A3C0Field(rawWord3,short*,10)=rawWord2;
                                Level27_7A3C0Field(privateRecord20, int *, 0x30) = Level27_7A3C0Call3636CView1(0xFA0,argumentWord5);
                                goto block_100;
                            }
                            goto block_101;
                        }
                    block_100:
                        if (Level27_7A3C0Field(privateRecord20, void **, 0x3C) == 0) {
                        block_101:
                            if (retainedFramePhaseScalar < Level27_7A3C0Field(privateRecord20, short *, 0x2E)) {
                                switch (retainedFramePhaseScalar) {
                                case 0:
                                    Level27_7A3C0Field(privateRecord20, short *, 0x2C) = 0;
                                    break;
                                case 1:
                                    if (Level27_7A3C0Field(privateRecord20, short *, 0x2C) >= 0xB5) {
                                        Level27_7A3C0Field(privateRecord20, short *, 0x2C) = 0xB4;
                                    }
                                    break;
                                }
                            }
                            goto block_108;
                        }
                        goto block_109;
                    }
                    goto block_109;
                }
            block_108:
                if (Level27_7A3C0Field(privateRecord20, void **, 0x3C) != 0) {
                block_109:
                    retainedCountRecordOrSineBase16 = ownerRecord21 + 0xC;
                    rawWord2=Level27_7A3C0Call4F334View1(retainedCountRecordOrSineBase16,Level27_7A3C0Field(Level27_7A3C0Field(privateRecord20,void**,0x24),void**,12));
                    argumentWord5=Level27_7A3C0Field(privateRecord20,int*,0x3C);
                    retainedCountRecordOrSineAddress17=rawWord2;
                    if(({rawWord3=Level27_7A3C0Field(argumentWord5,int*,0);countOrSignedLowProduct9=originalFrame.sp50;argumentWord4=Level27_7A3C0Field(rawWord3,unsigned char*,0x15);rawWord3=Level27_7A3C0Field(countOrSignedLowProduct9,int*,0x28);argumentWord4!=rawWord3;})) {
                        Level27_7A3C0Call55B18View1(argumentWord5);
                        Level27_7A3C0Field(privateRecord20, void **, 0x3C) = 0;
                        Level27_7A3C0Field(privateRecord20, short *, 0x2C) = 0;
                        return;
                    }
                    Level27_7A3C0Call4F178View1(argumentWord5 + 0xC, retainedCountRecordOrSineBase16);
                    rawWord2 = Level27_7A3C0Field(privateRecord20, void **, 0x3C);
                    Level27_7A3C0Field(rawWord2, int *, 0x14) = (int) (Level27_7A3C0Field(rawWord2, int *, 0x14) - Level27_7A3C0Field((int)&Level27_7A3C0Data70328View1, int *, 0x44));
                    if (Level27_7A3C0Call359A4View1(privateRecord20 + 0x2C, 2) != 0) {
                        rawWord3 = Level27_7A3C0Field(privateRecord20, int *, 0x30);
                        rawWord2 = rawWord3 - retainedCountRecordOrSineAddress17;
                        if(rawWord2<0)goto negativeDistance;
                        rawWord2=rawWord2<1000;
                        __asm__("":"=r"(rawWord2):"0"(rawWord2));
                        if(!rawWord2)goto block_119;
                        __asm__(""::"i"(0));
                        goto block_116;
                        negativeDistance:rawWord2=retainedCountRecordOrSineAddress17-rawWord3;
                        rawWord2=rawWord2<1000;
                        __asm__("":"=r"(rawWord2):"0"(rawWord2));
                        if(!rawWord2)goto block_119;
                        {
                        block_116:
                            if (Level27_7A3C0Field(Level27_7A3C0Field(privateRecord20, void **, 0x3C), short *, 0x36) == 0x280) {
                                Level27_7A3C0Field(privateRecord20, short *, 0x2C) = (short) (retainedFramePhaseScalar * 0xB4);
                            }
                            Level27_7A3C0Field(Level27_7A3C0Field(privateRecord20, void **, 0x3C), signed char *, 0x49) = 1;
                            Level27_7A3C0Field(privateRecord20, void **, 0x3C) = 0;
                        }
                    }
                    goto block_119;
                }
                goto block_119;
            }
        block_119:
            countOrSignedLowProduct9=Level27_7A3C0Field(&originalFrame.sp60,unsigned short*,0);
            Level27_7A3C0Field(privateRecord20,short*,0x2E)=retainedFramePhaseScalar;
            Level27_7A3C0Field(privateRecord20,short*,0x42)=countOrSignedLowProduct9;
        }
        break;
    }
}
#undef Level27_7A3C0Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original level27 controller8007B050.
 * Assembly SHA256 463a2360e407192b61eb84a78c74c6b06119cd45fb4a2ca04dc3f160491a7a2e.
 * AI generated; not human reviewed.1121 original native instructions,
 * 15 original state selectors and one zero pad=1137 owned words.
 * Field widths,offsets,helper words,constants and control destinations are
 * from this body. Names identify storage roles,without assigning asset or
 * gameplay meanings. The original 0x120 frame keeps SP18..F3 local homes.
 * SP18 is cleared by4F168; SP28,B8,C8,D8 are written by4F178 before use.
 * SP38/78 vectors and SP70/B0 three angle bytes are explicitly initialized;
 * 4EA90 writes all20 consumed matrix bytes in each24-byte local reservation;
 * 4ED6C reads precisely those20 bytes. The fourth loaded angle byte is
 * padding: all three original table selectors mask it away before use.
 * SP48/88 copies follow that initialized output. SPE8/EC/F0 are all written
 * before the original particle call. Padding/local reservation is not read.
 * Difficulty begins with a complete byte load and stays a signed32 word
 * through its original -4,+2,+5 adjustments; no byte truncation is added.
 * Both child trajectories use bounded signed16 table words*75>>10 then
 * signed16 pitch products>>12; these scalar products fit signed32 exactly.
 * State6's timer is signed16 and both initialized1500/600 factor roles are
 * retained through original /50 sequences. State7 initializes all three
 * signed64 dot products,keeps each low32 word,then sums modulo2^32.
 * The late normal-Z reload has its own ordinary control-flow assignment;
 * no GNU statement-expression temporary adds an unused8-byte frame slot.
 * Original case0/case14 share the state11-store exit straight to epilogue;
 * its J target does not enter the later common interaction path.
 * Known views reuse original stdutil vector/matrix and mobyutil ABI.
 * Other helpers preserve their original physical word call view only.
 * Empty metadata emits no CPU words and observes complete initialized
 * values/objects or ends a dead GP phase. All fixed aliases have disjoint
 * live phases; no incoming saved value,unwritten local,partial HI/LO input,
 * opcode asm,fixed FP/SP or invented default is used. Natural FP allocation
 * is the compiler's choice for the initialized difficulty word.
 * Source is for the frozen original MIPS compiler's32-bit numeric model;
 * portable C arithmetic,helper/asset/SFX meanings,units,cadence beyond each
 * original invocation,Rev1 mapping and synchronized captures remain open.
 * Acceptance requires every linked native/selector/pad word,actual branch/
 * J/call/data symbol+addend and all retail executable/overlay hashes.
 */
#define Actor1121Keep(x) __asm__("":"=r"(x):"0"(x))
#define Actor1121Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Actor1121_func_80018368() __asm__("func_80018368");
int Actor1121_func_80019194() __asm__("func_80019194");
int Actor1121_func_8001BA30() __asm__("func_8001BA30");
int Actor1121_func_8001C288() __asm__("func_8001C288");
int Actor1121_func_800359A4(void*,int) __asm__("func_800359A4");
int Actor1121_func_80035D38() __asm__("func_80035D38");
int Actor1121_func_800360F8() __asm__("func_800360F8");
int Actor1121_func_8003613C() __asm__("func_8003613C");
int Actor1121_func_8003636C(int,int) __asm__("func_8003636C");
int Actor1121_func_800363DC(int,int) __asm__("func_800363DC");
int Actor1121_func_80037A60() __asm__("func_80037A60");
int Actor1121_func_8003BABC() __asm__("func_8003BABC");
int Actor1121_func_8003C140() __asm__("func_8003C140");
int Actor1121_func_8004E880(int,int,int) __asm__("func_8004E880");
void Actor1121_func_8004EA90(void*,void*,int) __asm__("func_8004EA90");
void Actor1121_func_8004ED6C(void*,void*,void*) __asm__("func_8004ED6C");
int Actor1121_func_8004EDE8(void*,int) __asm__("func_8004EDE8");
int Actor1121_func_8004EF74(void*,void*,void*) __asm__("func_8004EF74");
void Actor1121_func_8004F0E8(void*,int) __asm__("func_8004F0E8");
void Actor1121_func_8004F168(void*) __asm__("func_8004F168");
void Actor1121_func_8004F178(void*,void*) __asm__("func_8004F178");
void Actor1121_func_8004F194(void*,void*,void*) __asm__("func_8004F194");
void Actor1121_func_8004F1C8(void*,void*,void*) __asm__("func_8004F1C8");
int Actor1121_func_8004F264(int,int) __asm__("func_8004F264");
int Actor1121_func_8004F334(void*,void*) __asm__("func_8004F334");
int Actor1121_func_80055B18() __asm__("func_80055B18");
int Actor1121_func_80055D24() __asm__("func_80055D24");
int Actor1121_func_8005629C() __asm__("func_8005629C");
int Actor1121_rand(void) __asm__("rand");
extern int Actor1121_D_800658A0 __asm__("D_800658A0");
extern int Actor1121_D_80065920 __asm__("D_80065920");
extern unsigned char Actor1121_D_8006C409 __asm__("D_8006C409");
extern int Actor1121_D_8006C550 __asm__("D_8006C550");
extern int Actor1121_D_8006C574 __asm__("D_8006C574");
extern int Actor1121_D_8006C578 __asm__("D_8006C578");
extern int Actor1121_D_8006C648 __asm__("D_8006C648");
extern int Actor1121_D_8006C7C4 __asm__("D_8006C7C4");
extern int Actor1121_D_8006E1D4 __asm__("D_8006E1D4");
extern int Actor1121_D_8006E1D8 __asm__("D_8006E1D8");
extern int Actor1121_D_8006E788 __asm__("D_8006E788");
extern int Actor1121_D_80070328 __asm__("D_80070328");
extern unsigned char Actor1121_D_8007158D __asm__("D_8007158D");
extern int Actor1121_D_80071918 __asm__("D_80071918");
extern int Actor1121_D_8007191C __asm__("D_8007191C");
extern int Actor1121_D_80071920 __asm__("D_80071920");
extern int(*Actor1121_SpawnMoby)() __asm__("SpawnMoby");
extern int(*Actor1121_SpawnParticle)() __asm__("SpawnParticle");
void func_level_27_8007B050(void* input) {
    register int ownerAddress19 __asm__("$19"),privateAddress20 __asm__("$20"),retainedScalarOrAddress16 __asm__("$16"),retainedScalarOrAddress17 __asm__("$17"),counterRadiusOrHeading18 __asm__("$18"),factorOrMatrixAddress21 __asm__("$21"),factorOrTableAddress22 __asm__("$22"),factorOrTableAddress23 __asm__("$23");
    register int resultWord2 __asm__("$2"),intermediateWord3 __asm__("$3"),argumentWord4 __asm__("$4"),argumentWord5 __asm__("$5"),argumentWord6 __asm__("$6"),argumentWord7 __asm__("$7");
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
        signed char sp70,sp71,sp72,sp73;
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
        signed char spB0,spB1,spB2,spB3;
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
    }
    originalFrame;
    int temporaryWord15;
    int temporaryWord7;
    int temporaryWord9;
    int temporaryWord17;
    int temporaryWord18;
    int temporaryWord20;
    int temporaryWord5;
    int temporaryWord10;
    int temporaryWord13;
    int temporaryWord1;
    int temporaryWord8;
    int temporaryWord14;
    int temporaryWord16;
    int difficultyAdjustment;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord4;
    int temporaryWord6;
    int temporaryWord11;
    int temporaryWord12;
    ownerAddress19=(int)input;
    __asm__("":"=r"(ownerAddress19):"0"(ownerAddress19));
    difficultyAdjustment = Actor1121_D_8006C409;
    privateAddress20 = Actor1121Field(ownerAddress19, int **, 0);
    intermediateWord3=Actor1121_D_8006C7C4;
    resultWord2=2;
    if(intermediateWord3==resultWord2){
        difficultyAdjustment-=4;
        if(difficultyAdjustment<0)difficultyAdjustment=0;
    }
    else{
        resultWord2=1;
        if(intermediateWord3==resultWord2)difficultyAdjustment+=2;
        else if(intermediateWord3==0)difficultyAdjustment+=5;
    }
    if (Actor1121_D_8007158D != 0) {
        difficultyAdjustment = 0;
    }
    temporaryWord14 = Actor1121Field(ownerAddress19, unsigned char *, 0x48);
    switch (temporaryWord14) {
    case 0:
        intermediateWord3=Actor1121_D_8006C648;
        temporaryWord1=Actor1121Field(privateAddress20,unsigned short*,0xC);
        temporaryWord1+=intermediateWord3;
        Actor1121Field(privateAddress20, unsigned short *, 0xC) = temporaryWord1;
        if ((short) temporaryWord1 >= 0x2711) {
            Actor1121Field(privateAddress20, unsigned short *, 0xC) = 0x2710U;
        }
        intermediateWord3=Actor1121_D_8006C648;
        temporaryWord8=Actor1121Field(privateAddress20,unsigned short*,0x16);
        temporaryWord8+=intermediateWord3;
        Actor1121Field(privateAddress20, unsigned short *, 0x16) = temporaryWord8;
        if ((short) temporaryWord8 >= 0x7531) {
            Actor1121Field(privateAddress20, unsigned short *, 0x16) = 0x7530U;
        }
        if (!(Actor1121Field(ownerAddress19, int *, 0x18) & 0x10000000)) {
            retainedScalarOrAddress17=(int)&Actor1121_D_8006E788;
            Actor1121Keep(retainedScalarOrAddress17);
            Actor1121_func_8004F168(&originalFrame.sp18);
            retainedScalarOrAddress16=Actor1121Field(retainedScalarOrAddress17,int*,0);
            if(retainedScalarOrAddress16!=0){
                retainedScalarOrAddress17+=4;
                counterRadiusOrHeading18=(int)&Actor1121_D_80065920;
                Actor1121Keep(counterRadiusOrHeading18);
                do {
                    if (retainedScalarOrAddress16 != ownerAddress19) {
                        temporaryWord15 = Actor1121Field(retainedScalarOrAddress16, short *, 0x36);
                        if (temporaryWord15 == 0x27F) {
                            if ((unsigned int) (Actor1121Field(retainedScalarOrAddress16, unsigned char *, 0x48) - 5) >= 2U) {
                                temporaryWord20 = Actor1121_func_8004F334(retainedScalarOrAddress16 + 0xC, ownerAddress19 + 0xC) < 0x28A;
                                goto block_25;
                            }
                            goto block_23;
                        }
                    block_23:
                        if (temporaryWord15 == 0x15F) {
                            temporaryWord20 = Actor1121_func_8004F334(retainedScalarOrAddress16 + 0xC, ownerAddress19 + 0xC) < 0x578;
                        block_25:
                            if (temporaryWord20 != 0) {
                                temporaryWord9 = Actor1121_func_8004E880(Actor1121Field(ownerAddress19, int *, 0xC) - Actor1121Field(retainedScalarOrAddress16, int *, 0xC), Actor1121Field(ownerAddress19, int *, 0x10) - Actor1121Field(retainedScalarOrAddress16, int *, 0x10), 0) * 2;
                                Actor1121Field(ownerAddress19, int *, 0xC) = (int) (Actor1121Field(ownerAddress19, int *, 0xC) + ((int) (Actor1121Field(temporaryWord9+counterRadiusOrHeading18,short*,0) * 0x19) >> 9));
                                Actor1121Field(ownerAddress19, int *, 0x10) = (int) (Actor1121Field(ownerAddress19, int *, 0x10) + ((int) (Actor1121Field((int)&Actor1121_D_800658A0,short*,temporaryWord9) * 0x19) >> 9));
                                Actor1121_func_80055D24(ownerAddress19, 2);
                            }
                        }
                    }
                    retainedScalarOrAddress16 = Actor1121Field(retainedScalarOrAddress17,int*,0);
                    retainedScalarOrAddress17 += 4;
                }
                while (retainedScalarOrAddress16 != 0);
            }
            goto runOriginalCommonTail;
        }
        goto storeState11AndReturn;
    case 3:
        if ((Actor1121Field(ownerAddress19, int *, 0xC) >= 0x400) && (Actor1121Field(ownerAddress19, int *, 0x10) >= 0x400) && (Actor1121Field(ownerAddress19, int *, 0x14) >= 0x400)) {
            argumentWord4=(int)&originalFrame.sp28;
            Actor1121Keep(argumentWord4);
            retainedScalarOrAddress16=ownerAddress19+0xC;
            Actor1121_func_8004F178(argumentWord4,retainedScalarOrAddress16);
            Actor1121_func_8004F194(retainedScalarOrAddress16, retainedScalarOrAddress16, privateAddress20);
            temporaryWord11 = Actor1121_func_8001BA30(retainedScalarOrAddress16, 0x15E, 0, 0, 0x100000, ownerAddress19);
            if (temporaryWord11 != 0) {
                Actor1121Field(temporaryWord11, signed char *, 0x51) = Actor1121_func_8004E880(Actor1121Field(privateAddress20, int *, 0), Actor1121Field(privateAddress20, int *, 4), 0);
                Actor1121Field(ownerAddress19, unsigned char *, 0x48) = 5U;
            }
            if (Actor1121_func_80019194(retainedScalarOrAddress16, 0x15E) != 0) {
                Actor1121Field(ownerAddress19, unsigned char *, 0x48) = 5U;
            }
            if (Actor1121_func_80018368(&originalFrame.sp28, retainedScalarOrAddress16) != 0) {
                Actor1121Field(ownerAddress19, unsigned char *, 0x48) = 5U;
            }
            if (Actor1121_func_80037A60(ownerAddress19, privateAddress20 + 8, 4, 0xA, -0xC8) != 0) {
                Actor1121Field(ownerAddress19, unsigned char *, 0x48) = 5U;
            }
            goto refreshBeforeCommonTail;
        }
        goto deleteOriginalOwner;
    case 5:
        Actor1121_func_8003BABC(ownerAddress19, 2, 0);
        Actor1121_D_8006E1D4 = 0x1388;
        Actor1121_D_8006E1D8 = 0x1E;
        intermediateWord3=Actor1121_func_80035D38(ownerAddress19);
        if(!intermediateWord3)goto originalState5ZeroArgument;
        intermediateWord3+=400;
        resultWord2=Actor1121Field(ownerAddress19,int*,0x14)<intermediateWord3;
        argumentWord6=0;
        if(!resultWord2)goto originalState5TableBases;
        Actor1121Field(ownerAddress19,int*,0x14)=intermediateWord3;
    originalState5ZeroArgument:
        argumentWord6=0;
        __asm__ volatile("":"=r"(argumentWord6):"0"(argumentWord6));
    originalState5TableBases:
        factorOrTableAddress23=(int)&Actor1121_D_80065920;
        __asm__ volatile(""::"r"(factorOrTableAddress23):"memory");
        Actor1121Field(privateAddress20,unsigned short*,0xC)=50;
        Actor1121Field(ownerAddress19,signed char*,0x41)=0;
        Actor1121Field(ownerAddress19,signed char*,0x4C)=0;
        Actor1121Field(ownerAddress19,signed char*,0x4D)=0;
        argumentWord4=Actor1121Field(privateAddress20,int*,0);
        argumentWord5=Actor1121Field(privateAddress20,int*,4);
        __asm__ volatile("":::"$22","memory");
        factorOrTableAddress22=(int)&Actor1121_D_800658A0;
        Actor1121Keep(factorOrTableAddress22);
        factorOrMatrixAddress21=0;
        Actor1121Field(ownerAddress19,signed char*,0x46)=Actor1121_func_8004E880(argumentWord4,argumentWord5,argumentWord6);
    spawnFirstOriginalChildren:
        if ((Actor1121_D_8006C578 - Actor1121_D_8006C574) >= 0x15) {
            temporaryWord12 = Actor1121_SpawnMoby(Actor1121Field(ownerAddress19, short *, 0x36), ownerAddress19);
            if (temporaryWord12 != 0) {
                retainedScalarOrAddress17 = Actor1121Field(temporaryWord12, int **, 0);
                temporaryWord13 = Actor1121_func_8003636C(1, 3);
                Actor1121Field(temporaryWord12, signed char *, 0x48) = temporaryWord13;
                Actor1121Field(temporaryWord12, signed char *, 0x3C) = temporaryWord13;
                Actor1121Field(temporaryWord12, int *, 8) = 0;
                retainedScalarOrAddress16 = Actor1121_func_8003636C(-0x20, 0xE0);
                resultWord2=Actor1121_rand();
                resultWord2=(resultWord2&255)*2;
                intermediateWord3=resultWord2+factorOrTableAddress23;
                Actor1121Keep(intermediateWord3);
                retainedScalarOrAddress16=(retainedScalarOrAddress16&255)*2;
                argumentWord4=Actor1121Field(intermediateWord3,short*,0);
                __asm__ volatile("":::"$5");
                argumentWord5=retainedScalarOrAddress16+factorOrTableAddress23;
                Actor1121Keep(argumentWord5);
                intermediateWord3=argumentWord4*4+argumentWord4;
                Actor1121Keep(intermediateWord3);
                argumentWord4=intermediateWord3*16-intermediateWord3;
                Actor1121Keep(argumentWord4);
                intermediateWord3=Actor1121Field(argumentWord5,short*,0);
                argumentWord4>>=10;
                Actor1121Field(retainedScalarOrAddress17,int*,0)=(argumentWord4*intermediateWord3)>>12;
                resultWord2+=factorOrTableAddress22;
                intermediateWord3=Actor1121Field(resultWord2,short*,0);
                resultWord2=intermediateWord3*4+intermediateWord3;
                Actor1121Keep(resultWord2);
                intermediateWord3=resultWord2*16-resultWord2;
                Actor1121Keep(intermediateWord3);
                resultWord2=Actor1121Field(argumentWord5,short*,0);
                intermediateWord3>>=10;
                retainedScalarOrAddress16+=factorOrTableAddress22;
                Actor1121Keep(retainedScalarOrAddress16);
                argumentWord6=retainedScalarOrAddress17;
                argumentWord4=temporaryWord12+0xC;
                __asm__("":"=r"(argumentWord4),"=r"(argumentWord6):"0"(argumentWord4),"1"(argumentWord6));
                Actor1121Field(retainedScalarOrAddress17,int*,4)=(intermediateWord3*resultWord2)>>12;
                resultWord2=Actor1121Field(retainedScalarOrAddress16,short*,0);
                Actor1121Field(retainedScalarOrAddress17,int*,8)=(resultWord2*75)>>10;
                Actor1121_func_8004F194(argumentWord4,argumentWord4,argumentWord6);
                Actor1121Field(temporaryWord12, signed char *, 0x48) = 7;
                Actor1121Field(retainedScalarOrAddress17, short *, 0xC) = Actor1121_func_8003636C(0x32, 0x46);
            }
            factorOrMatrixAddress21 += 1;
            if (factorOrMatrixAddress21 < 0xC) {
                goto spawnFirstOriginalChildren;
            }
        }
        Actor1121Field(ownerAddress19, unsigned char *, 0x48) = 6U;
    case 6:
        factorOrMatrixAddress21=1500;
        Actor1121Keep(factorOrMatrixAddress21);
        argumentWord4=Actor1121Field(privateAddress20,short*,0xC);
        factorOrTableAddress23=600;
        if(argumentWord4>=26){
            Actor1121Keep(factorOrTableAddress23);
            intermediateWord3=50-argumentWord4;
            argumentWord4=intermediateWord3*factorOrMatrixAddress21;
            intermediateWord3=intermediateWord3*factorOrTableAddress23;
            resultWord2=argumentWord4/50;
            Actor1121Keep(resultWord2);
            factorOrMatrixAddress21=resultWord2+750;
            resultWord2=intermediateWord3/50;
        }
        else{
            Actor1121Keep(factorOrTableAddress23);
            intermediateWord3=argumentWord4*factorOrMatrixAddress21;
            argumentWord4=argumentWord4*factorOrTableAddress23;
            resultWord2=intermediateWord3/50;
            Actor1121Keep(resultWord2);
            factorOrMatrixAddress21=resultWord2+750;
            resultWord2=argumentWord4/50;
        }
        factorOrTableAddress23=resultWord2+300;
        counterRadiusOrHeading18 = 0;
        if ((short) Actor1121Field(privateAddress20, unsigned short *, 0xC) >= 0xB) {
            factorOrTableAddress22=(int)&originalFrame.sp58;
            Actor1121Keep(factorOrTableAddress22);
            retainedScalarOrAddress17=(int)&originalFrame.sp38;
            Actor1121Keep(retainedScalarOrAddress17);
            retainedScalarOrAddress16=(int)&originalFrame.sp48;
            Actor1121Keep(retainedScalarOrAddress16);
            do {
                originalFrame.sp70 = 0;
                originalFrame.sp71 = Actor1121_rand();
                originalFrame.sp72 = Actor1121_rand();
                Actor1121_func_8004EA90(&originalFrame.sp70, factorOrTableAddress22, 0);
                originalFrame.sp38 = Actor1121_func_8003636C(0x3C, 0x64);
                originalFrame.sp3C = 0;
                originalFrame.sp40 = 0;
                Actor1121_func_8004ED6C(factorOrTableAddress22, retainedScalarOrAddress17, retainedScalarOrAddress17);
                Actor1121_func_8004F178(retainedScalarOrAddress16, retainedScalarOrAddress17);
                Actor1121_func_8004F0E8(retainedScalarOrAddress16, 2);
                __asm__ volatile("":"=r"(ownerAddress19):"0"(ownerAddress19));
                Actor1121_func_8004F194(retainedScalarOrAddress16,retainedScalarOrAddress16,ownerAddress19+0xC);
                argumentWord4=1;
                argumentWord5=13;
                argumentWord6=retainedScalarOrAddress16;
                argumentWord7=retainedScalarOrAddress17;
                __asm__ volatile("":"=r"(argumentWord4),"=r"(argumentWord5),"=r"(argumentWord6),"=r"(argumentWord7):"0"(argumentWord4),"1"(argumentWord5),"2"(argumentWord6),"3"(argumentWord7):"memory");
                counterRadiusOrHeading18+=1;
                Actor1121_SpawnParticle(argumentWord4,argumentWord5,argumentWord6,argumentWord7);
                __asm__ volatile("":"=r"(ownerAddress19):"0"(ownerAddress19));
            }
            while (counterRadiusOrHeading18 < 0xE);
            Actor1121_SpawnParticle(4, 0x46, ownerAddress19 + 0xC, (int *)0x10);
        }
        counterRadiusOrHeading18=0;
        retainedScalarOrAddress17=64;
        Actor1121Keep(retainedScalarOrAddress17);
    loop_58:
        if ((Actor1121_D_8006C578 - Actor1121_D_8006C574) >= 0x15) {
            temporaryWord2 = Actor1121_SpawnMoby(0x146, ownerAddress19);
            if (temporaryWord2 != 0) {
                Actor1121Field(temporaryWord2, signed char *, 0x4C) = retainedScalarOrAddress17;
                Actor1121Field(temporaryWord2, signed char *, 0x4E) = retainedScalarOrAddress17;
                Actor1121Field(temporaryWord2, int *, 0xC) = (int) (Actor1121Field(temporaryWord2, int *, 0xC) + Actor1121_func_800363DC(0, factorOrMatrixAddress21));
                Actor1121Field(temporaryWord2, int *, 0x10) = (int) (Actor1121Field(temporaryWord2, int *, 0x10) + Actor1121_func_800363DC(0, factorOrMatrixAddress21));
                Actor1121Field(temporaryWord2, int *, 0x14) = (int) (Actor1121Field(temporaryWord2, int *, 0x14) + Actor1121_func_800363DC(0,factorOrTableAddress23));
            }
            counterRadiusOrHeading18 += 1;
            if (counterRadiusOrHeading18 < 3) {
                goto loop_58;
            }
        }
        retainedScalarOrAddress17 = ownerAddress19 + 0xC;
        temporaryWord3 = Actor1121_func_8001BA30(retainedScalarOrAddress17, factorOrMatrixAddress21 + 0x3E8, 1, 0, 0x100000, ownerAddress19);
        if (temporaryWord3 != 0) {
            Actor1121Field(temporaryWord3, signed char *, 0x51) = Actor1121_func_8004E880(Actor1121Field(temporaryWord3, int *, 0xC) - Actor1121Field(ownerAddress19, int *, 0xC), Actor1121Field(temporaryWord3, int *, 0x10) - Actor1121Field(ownerAddress19, int *, 0x10), 0);
        }
        Actor1121_func_8001C288(retainedScalarOrAddress17, (int) (factorOrMatrixAddress21 + 0x190) / 2, 7);
        argumentWord4 = privateAddress20 + 0xC;
        goto callOriginalCountdown;
    case 11:
        Actor1121_func_8003BABC(ownerAddress19, 2, 0);
        factorOrMatrixAddress21=0;
        Actor1121Keep(factorOrMatrixAddress21);
        factorOrTableAddress23=(int)&Actor1121_D_80065920;
        Actor1121Keep(factorOrTableAddress23);
        factorOrTableAddress22=(int)&Actor1121_D_800658A0;
        Actor1121Keep(factorOrTableAddress22);
        Actor1121Field(ownerAddress19, signed char *, 0x41) = 0;
        Actor1121Field(ownerAddress19, signed char *, 0x4C) = 0;
        Actor1121Field(ownerAddress19, signed char *, 0x4D) = 0;
    loop_66:
        if ((Actor1121_D_8006C578 - Actor1121_D_8006C574) >= 0x15) {
            temporaryWord4 = Actor1121_SpawnMoby(Actor1121Field(ownerAddress19, short *, 0x36), ownerAddress19);
            if (temporaryWord4 != 0) {
                retainedScalarOrAddress17 = Actor1121Field(temporaryWord4, int **, 0);
                temporaryWord5 = Actor1121_func_8003636C(1, 3);
                Actor1121Field(temporaryWord4, signed char *, 0x48) = temporaryWord5;
                Actor1121Field(temporaryWord4, signed char *, 0x3C) = temporaryWord5;
                Actor1121Field(temporaryWord4, int *, 8) = 0;
                retainedScalarOrAddress16 = Actor1121_func_8003636C(-0x20, 0xE0);
                resultWord2=Actor1121_rand();
                resultWord2=(resultWord2&255)*2;
                intermediateWord3=resultWord2+factorOrTableAddress23;
                Actor1121Keep(intermediateWord3);
                retainedScalarOrAddress16=(retainedScalarOrAddress16&255)*2;
                argumentWord4=Actor1121Field(intermediateWord3,short*,0);
                __asm__ volatile("":::"$5");
                argumentWord5=retainedScalarOrAddress16+factorOrTableAddress23;
                Actor1121Keep(argumentWord5);
                intermediateWord3=argumentWord4*4+argumentWord4;
                Actor1121Keep(intermediateWord3);
                argumentWord4=intermediateWord3*16-intermediateWord3;
                Actor1121Keep(argumentWord4);
                intermediateWord3=Actor1121Field(argumentWord5,short*,0);
                argumentWord4>>=10;
                Actor1121Field(retainedScalarOrAddress17,int*,0)=(argumentWord4*intermediateWord3)>>12;
                resultWord2+=factorOrTableAddress22;
                intermediateWord3=Actor1121Field(resultWord2,short*,0);
                resultWord2=intermediateWord3*4+intermediateWord3;
                Actor1121Keep(resultWord2);
                intermediateWord3=resultWord2*16-resultWord2;
                Actor1121Keep(intermediateWord3);
                resultWord2=Actor1121Field(argumentWord5,short*,0);
                intermediateWord3>>=10;
                retainedScalarOrAddress16+=factorOrTableAddress22;
                Actor1121Keep(retainedScalarOrAddress16);
                argumentWord6=retainedScalarOrAddress17;
                argumentWord4=temporaryWord4+0xC;
                __asm__("":"=r"(argumentWord4),"=r"(argumentWord6):"0"(argumentWord4),"1"(argumentWord6));
                Actor1121Field(retainedScalarOrAddress17,int*,4)=(intermediateWord3*resultWord2)>>12;
                resultWord2=Actor1121Field(retainedScalarOrAddress16,short*,0);
                Actor1121Field(retainedScalarOrAddress17,int*,8)=(resultWord2*75)>>10;
                Actor1121_func_8004F194(argumentWord4,argumentWord4,argumentWord6);
                Actor1121Field(temporaryWord4, signed char *, 0x4F) = Actor1121_func_8003636C(0x46, 0x64);
                Actor1121Field(temporaryWord4, signed char *, 0x48) = 7;
                Actor1121Field(retainedScalarOrAddress17, short *, 0xC) = Actor1121_func_8003636C(0x32, 0x50);
            }
            factorOrMatrixAddress21 += 1;
            if (factorOrMatrixAddress21 < 8) {
                goto loop_66;
            }
        }
        Actor1121Field(privateAddress20, unsigned short *, 0xC) = 0xAU;
        Actor1121Field(ownerAddress19, unsigned char *, 0x48) = 0xCU;
    case 12:
        factorOrTableAddress22=500;
        Actor1121Keep(factorOrTableAddress22);
        factorOrTableAddress23=300;
        if ((short) Actor1121Field(privateAddress20, unsigned short *, 0xC) >= 0xB) {
            Actor1121Keep(factorOrTableAddress23);
            counterRadiusOrHeading18 = 0;
            factorOrMatrixAddress21=(int)&originalFrame.sp98;
            Actor1121Keep(factorOrMatrixAddress21);
            retainedScalarOrAddress17=(int)&originalFrame.sp78;
            Actor1121Keep(retainedScalarOrAddress17);
            retainedScalarOrAddress16=(int)&originalFrame.sp88;
            Actor1121Keep(retainedScalarOrAddress16);
            do {
                originalFrame.spB0 = 0;
                originalFrame.spB1 = Actor1121_rand();
                originalFrame.spB2 = Actor1121_rand();
                Actor1121_func_8004EA90(&originalFrame.spB0, factorOrMatrixAddress21, 0);
                originalFrame.sp78 = Actor1121_func_8003636C(0x3C, 0x64);
                originalFrame.sp7C = 0;
                originalFrame.sp80 = 0;
                Actor1121_func_8004ED6C(factorOrMatrixAddress21, retainedScalarOrAddress17, retainedScalarOrAddress17);
                Actor1121_func_8004F178(retainedScalarOrAddress16, retainedScalarOrAddress17);
                Actor1121_func_8004F0E8(retainedScalarOrAddress16, 2);
                __asm__ volatile("":"=r"(ownerAddress19):"0"(ownerAddress19));
                Actor1121_func_8004F194(retainedScalarOrAddress16,retainedScalarOrAddress16,ownerAddress19+0xC);
                argumentWord4=1;
                argumentWord5=13;
                argumentWord6=retainedScalarOrAddress16;
                argumentWord7=retainedScalarOrAddress17;
                __asm__ volatile("":"=r"(argumentWord4),"=r"(argumentWord5),"=r"(argumentWord6),"=r"(argumentWord7):"0"(argumentWord4),"1"(argumentWord5),"2"(argumentWord6),"3"(argumentWord7):"memory");
                counterRadiusOrHeading18+=1;
                Actor1121_SpawnParticle(argumentWord4,argumentWord5,argumentWord6,argumentWord7);
                __asm__ volatile("":"=r"(ownerAddress19):"0"(ownerAddress19));
            }
            while (counterRadiusOrHeading18 < 5);
            Actor1121_SpawnParticle(4, 0x46, ownerAddress19 + 0xC, (int *)0x10);
        }
        Actor1121Keep(factorOrTableAddress23);
        counterRadiusOrHeading18=0;
        retainedScalarOrAddress17=64;
        Actor1121Keep(retainedScalarOrAddress17);
    spawnOriginalTwoClass326Children:
        argumentWord4=326;
        if ((Actor1121_D_8006C578 - Actor1121_D_8006C574) >= 0x15) {
            __asm__ volatile("":"=r"(argumentWord4):"0"(argumentWord4));
            temporaryWord6 = Actor1121_SpawnMoby(argumentWord4, ownerAddress19);
            if (temporaryWord6 != 0) {
                Actor1121Field(temporaryWord6, signed char *, 0x4C) = retainedScalarOrAddress17;
                Actor1121Field(temporaryWord6, signed char *, 0x4E) = retainedScalarOrAddress17;
                Actor1121Field(temporaryWord6, int *, 0xC) = (int) (Actor1121Field(temporaryWord6, int *, 0xC) + Actor1121_func_800363DC(0,factorOrTableAddress22));
                Actor1121Field(temporaryWord6, int *, 0x10) = (int) (Actor1121Field(temporaryWord6, int *, 0x10) + Actor1121_func_800363DC(0,factorOrTableAddress22));
                Actor1121Field(temporaryWord6, int *, 0x14) = (int) (Actor1121Field(temporaryWord6, int *, 0x14) + Actor1121_func_800363DC(0,factorOrTableAddress23));
            }
            counterRadiusOrHeading18 += 1;
            __asm__ volatile("":::"$4");
            argumentWord4 = privateAddress20 + 0xC;
            if (counterRadiusOrHeading18 >= 2) {
            }
            else {
                goto spawnOriginalTwoClass326Children;
            }
        }
        else {
            goto prepareCountdownArgument;
        }
        goto callOriginalCountdown;
    case 14:
        Actor1121_func_80037A60(ownerAddress19, privateAddress20 + 8, 4, 0xC, -0xC8);
        if (Actor1121Field(privateAddress20, int *, 8) < 0) {
        storeState11AndReturn:
            Actor1121Field(ownerAddress19, unsigned char *, 0x48) = 0xBU;
            return;
        }
        goto runOriginalCommonTail;
    case 13:
        if (Actor1121Field(ownerAddress19, unsigned char *, 0x49) != 0) {
            Actor1121Field(ownerAddress19, unsigned char *, 0x49) = 0U;
            Actor1121Field(ownerAddress19, unsigned char *, 0x48) = 0xAU;
        }
        goto runOriginalCommonTail;
    case 10:
        temporaryWord17 = Actor1121Field(ownerAddress19, int *, 0x14);
        if ((temporaryWord17 < 0x5001) && (Actor1121Field(ownerAddress19, int *, 0xC) >= 0x400) && (Actor1121Field(ownerAddress19, int *, 0x10) >= 0x400) && (temporaryWord17 >= 0x400)) {
            argumentWord4=(int)&originalFrame.spB8;
            Actor1121Keep(argumentWord4);
            retainedScalarOrAddress16=ownerAddress19+0xC;
            Actor1121_func_8004F178(argumentWord4,retainedScalarOrAddress16);
            Actor1121_func_8004F194(retainedScalarOrAddress16, retainedScalarOrAddress16, privateAddress20);
            argumentWord4=privateAddress20;
            argumentWord5=1;
            __asm__ volatile("":"=r"(argumentWord4),"=r"(argumentWord5):"0"(argumentWord4),"1"(argumentWord5):"memory");
            resultWord2=Actor1121Field(privateAddress20,int*,8);
            __asm__ volatile("":::"$18");
            counterRadiusOrHeading18=350;
            Actor1121Keep(counterRadiusOrHeading18);
            Actor1121Field(privateAddress20,int*,8)=resultWord2-16;
            temporaryWord18 = Actor1121_func_8004EDE8(argumentWord4, argumentWord5) + 8;
            if (counterRadiusOrHeading18 < temporaryWord18) {
                counterRadiusOrHeading18 = temporaryWord18;
            }
            Actor1121_func_80055D24(ownerAddress19, 2);
            if ((Actor1121_func_800359A4(privateAddress20 + 0x14, 2) != 0) && (Actor1121_func_80019194(retainedScalarOrAddress16, counterRadiusOrHeading18) != 0)) {
                retainedScalarOrAddress17=(int)&Actor1121_D_80071920;
                Actor1121Keep(retainedScalarOrAddress17);
                factorOrMatrixAddress21=retainedScalarOrAddress17-8;
                argumentWord4=factorOrMatrixAddress21;
                Actor1121Keep(argumentWord4);
                Actor1121Field(privateAddress20,unsigned char*,0x13)=0;
                retainedScalarOrAddress16=Actor1121Field(retainedScalarOrAddress17,int*,0);
                if (retainedScalarOrAddress16 < 0) {
                    retainedScalarOrAddress16 = -retainedScalarOrAddress16;
                }
                resultWord2=Actor1121_func_8004EDE8(argumentWord4,0);
                retainedScalarOrAddress16=retainedScalarOrAddress16<resultWord2;
                if(retainedScalarOrAddress16){
                    retainedScalarOrAddress16=(int)&originalFrame.spC8;
                    Actor1121_func_8004F178(retainedScalarOrAddress16,factorOrMatrixAddress21);
                    if (Actor1121_func_8004EF74(privateAddress20,retainedScalarOrAddress16,privateAddress20) != 0) {
                        Actor1121Field(privateAddress20, int *, 0) = (int) (Actor1121Field(privateAddress20, int *, 0) * 6) >> 3;
                        Actor1121Field(privateAddress20, int *, 4) = (int) ((int) (Actor1121Field(privateAddress20, int *, 4) * 6) >> 3);
                        Actor1121Field(privateAddress20, int *, 8) = (int) ((int) (Actor1121Field(privateAddress20, int *, 8) * 6) >> 3);
                        argumentWord4 = Actor1121_func_8003BABC(ownerAddress19, 1, 0);
                        if (argumentWord4 >= 0) {
                            resultWord2 = Actor1121Field(privateAddress20, int *, 8);
                            if (resultWord2 < 0) {
                                resultWord2 = -resultWord2;
                            }
                            Actor1121Keep(resultWord2);
                            Actor1121_func_8003C140(argumentWord4, resultWord2 * 0x28);
                        }
                    }
                }
                else {
                    retainedScalarOrAddress16=Actor1121Field(retainedScalarOrAddress17,int*,0);
                    Actor1121Keep(retainedScalarOrAddress16);
                    if ((retainedScalarOrAddress16>=0) || (Actor1121Field(privateAddress20,int*,8)<=0)) {
                        if ((retainedScalarOrAddress16>0) && (Actor1121Field(privateAddress20,int*,8)<0)) {
                            goto applyOriginalVerticalBounce;
                        }
                    }
                    else {
                    applyOriginalVerticalBounce:
                        Actor1121Field(privateAddress20, int *, 0) = 0;
                        Actor1121Field(privateAddress20, int *, 4) = 0;
                        resultWord2=Actor1121Field(privateAddress20,int*,8);
                        resultWord2=(int)(0U-(unsigned int)resultWord2);
                        Actor1121Keep(resultWord2);
                        resultWord2=(int)((unsigned int)resultWord2<<2);
                        Actor1121Field(privateAddress20,int*,8)=resultWord2>>3;
                        argumentWord4 = Actor1121_func_8003BABC(ownerAddress19, 1, 0);
                        if (argumentWord4 >= 0) {
                            resultWord2 = Actor1121Field(privateAddress20, int *, 8);
                            if (resultWord2 < 0) {
                                resultWord2 = -resultWord2;
                            }
                            Actor1121Keep(resultWord2);
                            Actor1121_func_8003C140(argumentWord4, resultWord2 * 0x28);
                        }
                        if (Actor1121Field(privateAddress20, int *, 8) < 0x28) {
                            Actor1121Field(ownerAddress19, int *, 0x14) = (int) (Actor1121_func_80035D38(ownerAddress19) + counterRadiusOrHeading18);
                            Actor1121Field(privateAddress20, unsigned short *, 0xC) = 0U;
                            Actor1121Field(ownerAddress19, unsigned char *, 0x48) = 0U;
                        }
                    }
                }
            }
            if (Actor1121Field(privateAddress20, unsigned char *, 0x13) != 0) {
                Actor1121_func_8004F178(&originalFrame.spD8, ownerAddress19 + 0xC);
                Actor1121_func_8004F1C8(&originalFrame.spD8, &originalFrame.spD8, privateAddress20);
                originalFrame.spE8 = Actor1121_rand() & 0xF;
                originalFrame.spEC = Actor1121_rand() & 0xF;
                originalFrame.spF0 = 0xA;
                Actor1121_SpawnParticle(1, 0xD, &originalFrame.spD8, &originalFrame.spE8);
            }
        refreshBeforeCommonTail:
            Actor1121_func_80035D38(ownerAddress19);
            Actor1121_func_8005629C(ownerAddress19);
            goto runOriginalCommonTail;
        }
        goto deleteOriginalOwner;
    case 7:
        if ((Actor1121Field(ownerAddress19, int *, 0xC) >= 0x400) && (Actor1121Field(ownerAddress19, int *, 0x10) >= 0x400) && (Actor1121Field(ownerAddress19, int *, 0x14) >= 0x400)) {
            resultWord2=Actor1121_func_80019194(ownerAddress19+0xC,0x8C);
            __asm__ volatile("":"=r"(ownerAddress19),"=r"(resultWord2):"0"(ownerAddress19),"1"(resultWord2));
            argumentWord4=ownerAddress19+0xC;
            if(resultWord2){
                argumentWord5=(int)&Actor1121_D_80071918;
                Actor1121Keep(argumentWord5);
                intermediateWord3=Actor1121Field(privateAddress20,int*,0);
                resultWord2=Actor1121Field(argumentWord5,int*,0);
                argumentWord6=(int)((long long)intermediateWord3*(long long)resultWord2);
                Actor1121Keep(argumentWord6);
                intermediateWord3=Actor1121Field(privateAddress20,int*,4);
                resultWord2=Actor1121_D_8007191C;
                argumentWord4=(int)((long long)intermediateWord3*(long long)resultWord2);
                Actor1121Keep(argumentWord4);
                intermediateWord3=Actor1121Field(privateAddress20,int*,8);
                resultWord2=Actor1121_D_80071920;
                intermediateWord3=(int)((long long)intermediateWord3*(long long)resultWord2);
                Actor1121Keep(intermediateWord3);
                resultWord2=(int)((unsigned int)argumentWord6+(unsigned int)argumentWord4+(unsigned int)intermediateWord3);
                __asm__ volatile("":"=r"(ownerAddress19),"=r"(resultWord2):"0"(ownerAddress19),"1"(resultWord2));
                argumentWord4=ownerAddress19+0xC;
                if(resultWord2<0){
                    resultWord2=Actor1121_func_8004EF74(privateAddress20,argumentWord5,privateAddress20);
                    __asm__ volatile("":"=r"(ownerAddress19),"=r"(resultWord2):"0"(ownerAddress19),"1"(resultWord2));
                    argumentWord4=ownerAddress19+0xC;
                    if(resultWord2){
                        Actor1121Field(privateAddress20,int*,0)=(Actor1121Field(privateAddress20,int*,0)*6)>>3;
                        Actor1121Field(privateAddress20,int*,4)=(Actor1121Field(privateAddress20,int*,4)*6)>>3;
                        Actor1121Field(privateAddress20,int*,8)=(Actor1121Field(privateAddress20,int*,8)*6)>>3;
                    }
                }
            }
            Actor1121Keep(argumentWord4);
            Actor1121_func_8004F194(argumentWord4,argumentWord4,privateAddress20);
            temporaryWord7 = Actor1121Field(privateAddress20, int *, 8) - 0xE;
            Actor1121Field(privateAddress20, int *, 8) = temporaryWord7;
            if (temporaryWord7 < -0x12C) {
                Actor1121Field(privateAddress20, int *, 8) = -0x12C;
            }
            goto prepareCountdownArgument;
        }
        goto deleteOriginalOwner;
    prepareCountdownArgument:
        argumentWord4=privateAddress20+0xC;
    callOriginalCountdown:
        if (Actor1121_func_800359A4(argumentWord4, 2) != 0) {
            goto deleteOriginalOwner;
        }
        goto runOriginalCommonTail;
    deleteOriginalOwner:
        Actor1121_func_80055B18(ownerAddress19);
        return;
    default:
    runOriginalCommonTail:
        if ((Actor1121Field(ownerAddress19, int *, 0x18) & 0x20000) && ((temporaryWord16 = Actor1121Field(ownerAddress19, unsigned char *, 0x48), (temporaryWord16 == 0)) || (temporaryWord16 == 0xA))) {
            Actor1121Field(ownerAddress19, signed char *, 0x51) = 0;
            counterRadiusOrHeading18 = Actor1121_func_800360F8(Actor1121_func_8004E880(Actor1121Field(ownerAddress19, int *, 0xC) - Actor1121Field((int)&Actor1121_D_80070328, int *, 0), Actor1121Field(ownerAddress19, int *, 0x10) - Actor1121Field((int)&Actor1121_D_80070328, int *, 4), 0), Actor1121Field((int)&Actor1121_D_80070328, unsigned char *, 0xE), 0x20, 0x50);
            temporaryWord10 = Actor1121_func_8004E880(Actor1121Field(Actor1121_D_8006C550, int *, 0xC) - Actor1121Field(ownerAddress19, int *, 0xC), Actor1121Field(Actor1121_D_8006C550, int *, 0x10) - Actor1121Field(ownerAddress19, int *, 0x10), 0);
            retainedScalarOrAddress17 = counterRadiusOrHeading18 & 0xFF;
            if (Actor1121_func_8004F264(retainedScalarOrAddress17, temporaryWord10) < 0x10) {
                intermediateWord3=Actor1121_func_8003613C(retainedScalarOrAddress17,temporaryWord10);
                if(difficultyAdjustment>=7){
                    resultWord2=intermediateWord3<10;
                    if(!resultWord2){
                        intermediateWord3=9;
                        Actor1121Keep(intermediateWord3);
                    }
                    resultWord2=intermediateWord3<-9;
                    if(resultWord2)intermediateWord3=-9;
                }
                else{
                    resultWord2=intermediateWord3<7;
                    if(!resultWord2){
                        intermediateWord3=6;
                        Actor1121Keep(intermediateWord3);
                    }
                    resultWord2=intermediateWord3<-6;
                    if(resultWord2)intermediateWord3=-6;
                }
                counterRadiusOrHeading18+=intermediateWord3;
            }
            argumentWord4=ownerAddress19;
            argumentWord5=3;
            __asm__("":"=r"(argumentWord4),"=r"(argumentWord5):"0"(argumentWord4),"1"(argumentWord5));
            argumentWord7=(counterRadiusOrHeading18&255)*2;
            intermediateWord3=Actor1121Field((int)&Actor1121_D_80065920,short*,argumentWord7);
            __asm__ volatile("":::"$6");
            argumentWord6=0;
            __asm__("":"=r"(intermediateWord3),"=r"(argumentWord6):"0"(intermediateWord3),"1"(argumentWord6));
            resultWord2=(intermediateWord3*125)>>10;
            Actor1121Field(privateAddress20,int*,0)=resultWord2;
            __asm__ volatile(""::"m"(Actor1121Field(privateAddress20,int*,0)):"memory");
            intermediateWord3=Actor1121Field((int)&Actor1121_D_800658A0,short*,argumentWord7);
            resultWord2=130;
            Actor1121Field(privateAddress20,int*,8)=resultWord2;
            __asm__ volatile(""::"m"(Actor1121Field(privateAddress20,int*,8)):"memory");
            resultWord2=(intermediateWord3*125)>>10;
            Actor1121Field(privateAddress20,int*,4)=resultWord2;
            Actor1121Field(argumentWord4,unsigned char*,0x48)=3;
            Actor1121_func_8003BABC(argumentWord4,argumentWord5,argumentWord6);
        }
        return;
    }
}
#undef Actor1121Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007C1D4.
* AI generated; not human reviewed. All812 original instructions,18 selectors
* and every actual destination must match:830 owned words. FrameC8hex=200
* bytes saves S0..S6/RA and retains original SP18..A7 vector/matrix workspace.
* All18 states share their original dispatch. Original cleanup646 and contact
* position419/call420 are distinct entries; no helper or default is bypassed.
* Trig samples retain signed halfword reads,whole 75/25/35 products,original
* shifts9/11,three RNG-independent vector producers and their memory widths.
* State17 keeps original full700 S1 producer,whole signed products and /60
* including compiler's signed correction. Timer60 gives350;timer30 gives700.
* No partial HI/LO values or CPU opcode assembly are used. Complete product
* identities retire the old scalar register before the next full producer.
* Original S5 constant64 is produced once before the two-spawn particle loop.
* Callback targets/arguments precede their late counters exactly as on disc.
* Signed short comparisons occur after original low-half stores:0xFFF0 is-16.
* Complete stride88 list phases,uncached post-helper reads and independent
* X/Y/Z updates retain every source producer and actual branch destination.
* S0 position/spawn/signed-value and S1 vector/magnitude/data phases do not
* overlap. Empty metadata reads initialized complete values/addresses or
* clobbers dead values before fresh complete producers;zero CPU words.
* Known timer,angle and spawn views reuse matched EXE/header evidence.
* Compiler/filter/flags unchanged;no fixedFP,undefined saved values or live
* overlapping aliases. Units/fixed point,full helper/caller chains,cadence
* beyond invocation,Rev1 mapping and synchronized runtime remain unresolved.
* Confidence is binary identity after all gates. Next:human review and retail
* captures. Every original native/linked word,target,selector byte and full
* EXE/every-overlay retail hash must remain identical.
*/
/* Original assembly SHA256 5576e3662f0f343d3169b1dfbb9a7ba7a951f701f1b3e838671572b9c6f97116 */
#define Level27_7C1D4Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
int Level27_7C1D4Call13ACCView1() __asm__("func_80013ACC");
int Level27_7C1D4Call18368View1() __asm__("func_80018368");
int Level27_7C1D4Call19194View1() __asm__("func_80019194");
int Level27_7C1D4Call1BA30View1() __asm__("func_8001BA30");
int Level27_7C1D4Call359A4View1(void*, int) __asm__("func_800359A4");
int Level27_7C1D4Call35D38View1() __asm__("func_80035D38");
int Level27_7C1D4Call3613CView1() __asm__("func_8003613C");
int Level27_7C1D4Call363DCView1() __asm__("func_800363DC");
int Level27_7C1D4Call3BABCView1() __asm__("func_8003BABC");
int Level27_7C1D4Call3BB10View1() __asm__("func_8003BB10");
int Level27_7C1D4Call49484View1() __asm__("func_80049484");
int Level27_7C1D4Call4E880View1(int, int, int) __asm__("func_8004E880");
int Level27_7C1D4Call4EA90View1() __asm__("func_8004EA90");
int Level27_7C1D4Call4ED6CView1() __asm__("func_8004ED6C");
int Level27_7C1D4Call4EDE8View1() __asm__("func_8004EDE8");
int Level27_7C1D4Call4EF74View1() __asm__("func_8004EF74");
int Level27_7C1D4Call4F178View1() __asm__("func_8004F178");
int Level27_7C1D4Call4F194View1() __asm__("func_8004F194");
int Level27_7C1D4Call4F1C8View1() __asm__("func_8004F1C8");
int Level27_7C1D4Call4F334View1() __asm__("func_8004F334");
int Level27_7C1D4Call55B18View1() __asm__("func_80055B18");
int Level27_7C1D4Call55D24View1() __asm__("func_80055D24");
int Level27_7C1D4Call5629CView1() __asm__("func_8005629C");
extern int Level27_7C1D4Data658A0View1 __asm__("D_800658A0");
extern int Level27_7C1D4Data65920View1 __asm__("D_80065920");
extern int Level27_7C1D4Data6C550View1 __asm__("D_8006C550");
extern int Level27_7C1D4Data6C574View1 __asm__("D_8006C574");
extern int Level27_7C1D4Data6C578View1 __asm__("D_8006C578");
extern int Level27_7C1D4Data6C648View1 __asm__("D_8006C648");
extern unsigned short Level27_7C1D4Data6E03EView1 __asm__("D_8006E03E");
extern unsigned short Level27_7C1D4Data6E040View1 __asm__("D_8006E040");
extern int Level27_7C1D4Data6E044View1 __asm__("D_8006E044");
extern int Level27_7C1D4Data6E1D4View1 __asm__("D_8006E1D4");
extern int Level27_7C1D4Data6E1D8View1 __asm__("D_8006E1D8");
extern int Level27_7C1D4Data70328View1 __asm__("D_80070328");
extern int Level27_7C1D4Data71920View1 __asm__("D_80071920");
extern void*(*Level27_7C1D4DataSpawnMobyView1)(int, void*) __asm__("SpawnMoby");
extern void*(*Level27_7C1D4DataSpawnParticleView1)(int, int, void*, void*) __asm__("SpawnParticle");
void func_level_27_8007C1D4(void *ownerParameter) {
    register int rawWord2 __asm__("$2"), rawWord3 __asm__("$3"), argumentWord4 __asm__("$4"), argumentWord5 __asm__("$5"), argumentWord6 __asm__("$6"), argumentWord7 __asm__("$7"), originalParticleChannel64At21 __asm__("$21");
    int originalDispatchState;
    register void *ownerRecord18 __asm__("$18");
    register int privateRecord19 __asm__("$19"), retainedPositionSpawnOrSignedValue16 __asm__("$16"), retainedVectorMagnitudeOrData17 __asm__("$17"), retainedMinimumCounterOrVector20 __asm__("$20"), originalParticleClass22 __asm__("$22");
    struct{
        int sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C, sp80, sp84, sp88, sp8C, sp90, sp94, sp98, sp9C, spA0, spA4;
    }
    originalFrame;
    int temporaryWord1;
    int temporaryWord7;
    int temporaryWord8;
    int temporaryWord2;
    int temporaryWord3;
    int temporaryWord6;
    int temporaryWord9;
    int temporaryWord11;
    int temporaryWord12;
    int temporaryWord13;
    int temporaryWord10;
    int temporaryWord4;
    int temporaryWord5;
    ownerRecord18 = ownerParameter;
    __asm__("":"=r"(ownerRecord18):"0"(ownerRecord18));
    privateRecord19 = Level27_7C1D4Field(ownerRecord18, void **, 0);
    rawWord3 = Level27_7C1D4Field(privateRecord19, unsigned char*, 21);
    originalParticleClass22 = 2;
    if (rawWord3 == 1) goto writeOriginalClassOne20;
    if (rawWord3 == originalParticleClass22) goto writeOriginalClassTwo24;
    goto readOriginalOwnerState25;
    writeOriginalClassOne20:Level27_7C1D4Field(ownerRecord18, unsigned char*, 84) = 1;
    originalParticleClass22 = 0;
    goto readOriginalOwnerState25;
    writeOriginalClassTwo24:Level27_7C1D4Field(ownerRecord18, unsigned char*, 84) = 8;
readOriginalOwnerState25:
    originalDispatchState = Level27_7C1D4Field(ownerRecord18, unsigned char*, 72);
    if (originalDispatchState < 0xDU) {
        rawWord2 = 2;
        if (originalDispatchState != rawWord2) {
            retainedPositionSpawnOrSignedValue16 = 0;
            if (Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x49) != 0) {
                do {
                    argumentWord4 = 4;
                    argumentWord5 = 12;
                    argumentWord6 = (int)ownerRecord18;
                    argumentWord7 = originalParticleClass22;
                    rawWord2 = (int)Level27_7C1D4DataSpawnParticleView1;
                    __asm__("":"=r"(rawWord2):"0"(rawWord2), "r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6), "r"(argumentWord7));
                    retainedPositionSpawnOrSignedValue16++;
                    ((int(*)())rawWord2)(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
                }
                while (retainedPositionSpawnOrSignedValue16 < 5);
                Level27_7C1D4Call3BB10View1(ownerRecord18, 9, 0);
                goto removeOriginalOwner646;
            }
            if (Level27_7C1D4Call4F334View1(ownerRecord18 + 0xC, (int)&Level27_7C1D4Data70328View1) < 0x3E8) {
                temporaryWord9 = Level27_7C1D4Field(ownerRecord18, int *, 0x14) - Level27_7C1D4Field(ownerRecord18, short *, 0x38);
                temporaryWord2 = temporaryWord9 - Level27_7C1D4Field((int)&Level27_7C1D4Data70328View1, int *, 8);
                if (temporaryWord2 >= 0) {
                    retainedPositionSpawnOrSignedValue16 = 0;
                    if (temporaryWord2 < 700) goto emitOriginalContactParticles77;
                    __asm__ volatile(""::"r"(privateRecord19));
                    goto reloadOriginalState111;
                }
                retainedPositionSpawnOrSignedValue16 = 0;
                if ((Level27_7C1D4Field((int)&Level27_7C1D4Data70328View1, int *, 8) - temporaryWord9) < 0x2BC) {
                emitOriginalContactParticles77:
                    do {
                        argumentWord4 = 4;
                        argumentWord5 = 12;
                        argumentWord6 = (int)ownerRecord18;
                        argumentWord7 = originalParticleClass22;
                        rawWord2 = (int)Level27_7C1D4DataSpawnParticleView1;
                        __asm__("":"=r"(rawWord2):"0"(rawWord2), "r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6), "r"(argumentWord7));
                        retainedPositionSpawnOrSignedValue16++;
                        ((int(*)())rawWord2)(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
                    }
                    while (retainedPositionSpawnOrSignedValue16 < 5);
                    Level27_7C1D4Call3BB10View1(ownerRecord18, 9, 0);
                    temporaryWord10 = Level27_7C1D4Field(privateRecord19, unsigned char *, 0x15);
                    if (temporaryWord10 == 1) {
                        Level27_7C1D4Field((int)&Level27_7C1D4Data70328View1, int *, 0x1D4) = (int) temporaryWord10;
                        goto removeOriginalOwner646;
                    }
                    Level27_7C1D4Field((int)&Level27_7C1D4Data70328View1, int *, 0x20C) = 0x10001000;
                    Level27_7C1D4Field((int)&Level27_7C1D4Data70328View1, void **, 0x218) = ownerRecord18;
                    Level27_7C1D4Field(ownerRecord18, signed char *, 0x41) = 0;
                    Level27_7C1D4Field(ownerRecord18, signed char *, 0x4C) = 0;
                    Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x4D) = 0U;
                    Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x48) = 0xEU;
                    goto reloadOriginalState111;
                }
                goto reloadOriginalState111;
            }
        reloadOriginalState111:
            goto enterOriginalStateReload111;
        }
        goto checkOriginalStateRange113;
    }
enterOriginalStateReload111:
    originalDispatchState = Level27_7C1D4Field(ownerRecord18, unsigned char*, 72);
checkOriginalStateRange113:
dispatchOriginalState114:
    if ((unsigned)originalDispatchState < 18) {
        switch (originalDispatchState) {
        case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 11:case 12:case 14:goto updateOriginalCommon786;
        case 2:
            Level27_7C1D4Field(ownerRecord18, signed char *, 0x4F) = 0x20;
            Level27_7C1D4Field(ownerRecord18, signed char *, 0x4C) = 0x50;
            Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x45) = 0U;
            Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x4D) = 1U;
            Level27_7C1D4Field(ownerRecord18, signed char *, 0x41) = 1;
            Level27_7C1D4Field(ownerRecord18, signed char *, 0x4C) = 0x3F;
            Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x4D) = 1U;
            argumentWord4 = ownerRecord18 + 0xC;
            if (Level27_7C1D4Data6E044View1 == 7) {
                __asm__("":"=r"(ownerRecord18):"0"(ownerRecord18):"$4");
                argumentWord4 = (int)ownerRecord18+12;
                Level27_7C1D4Call49484View1(argumentWord4);
            }
            else{
                __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
                Level27_7C1D4Field(ownerRecord18, int *, 0xC) = (int) ((int) (Level27_7C1D4Field((int)&Level27_7C1D4Data65920View1, short*, (Level27_7C1D4Field((int)&Level27_7C1D4Data70328View1, unsigned char *, 0xE) * 2)) * 0x4B) >> 9);
                temporaryWord1 = Level27_7C1D4Field((int)&Level27_7C1D4Data658A0View1, short*, (Level27_7C1D4Field((int)&Level27_7C1D4Data70328View1, unsigned char *, 0xE) * 2));
                Level27_7C1D4Field(ownerRecord18, int *, 0x14) = 0xC8;
                Level27_7C1D4Field(ownerRecord18, int *, 0x10) = (int) ((int) (temporaryWord1 * 0x4B) >> 9);
                Level27_7C1D4Call4F194View1(argumentWord4, argumentWord4, ((int)&Level27_7C1D4Data70328View1 + 0xE) - 0xE);
            }
            argumentWord4 = (int)&originalFrame.sp18;
            retainedVectorMagnitudeOrData17 = (int)&Level27_7C1D4Data70328View1+14;
            __asm__("":"=r"(retainedVectorMagnitudeOrData17):"0"(retainedVectorMagnitudeOrData17), "r"(argumentWord4));
            argumentWord7 = Level27_7C1D4Field(retainedVectorMagnitudeOrData17, unsigned char*, 0);
            argumentWord5 = argumentWord4;
            argumentWord7 *= 2;
            rawWord3 = Level27_7C1D4Field((int)&Level27_7C1D4Data65920View1, short*, argumentWord7);
            __asm__ volatile(""::"r"(argumentWord7), "r"(argumentWord5):"$6", "memory");
            argumentWord6 = retainedVectorMagnitudeOrData17-14;
            originalFrame.sp18 = (rawWord3*25) >> 9;
            rawWord3 = Level27_7C1D4Field((int)&Level27_7C1D4Data658A0View1, short*, argumentWord7);
            originalFrame.sp20 = 200;
            originalFrame.sp1C = (rawWord3*25) >> 9;
            Level27_7C1D4Call4F194View1(argumentWord4, argumentWord5, argumentWord6);
            argumentWord4 = (int)&originalFrame.sp18;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4):"$16");
            retainedPositionSpawnOrSignedValue16 = ownerRecord18 + 0xC;
            if (Level27_7C1D4Call18368View1(argumentWord4, retainedPositionSpawnOrSignedValue16) != 0) {
                Level27_7C1D4Call4F178View1(retainedPositionSpawnOrSignedValue16, &originalFrame.sp18);
            }
            Level27_7C1D4Field(privateRecord19, unsigned char *, 0x10) = 0U;
            Level27_7C1D4Field(privateRecord19, unsigned char *, 0x12) = (unsigned char) (Level27_7C1D4Field(retainedVectorMagnitudeOrData17, unsigned char*, 0)+Level27_7C1D4Field((int)&Level27_7C1D4Data70328View1, unsigned char*, 18));
            if (Level27_7C1D4Data6E044View1 == 7) {
                Level27_7C1D4Field(privateRecord19, unsigned char *, 0x11) = (unsigned char) (4 - ((int) (Level27_7C1D4Data6E03EView1 << 0x10) >> 0x14));
                Level27_7C1D4Field(privateRecord19, unsigned char *, 0x12) = (unsigned char) ((unsigned short) Level27_7C1D4Data6E040View1 >> 4);
            }
            else {
                Level27_7C1D4Field(privateRecord19, unsigned char *, 0x11) = 4U;
            }
            Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x44) = (unsigned char) Level27_7C1D4Field(privateRecord19, unsigned char *, 0x10);
            Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x45) = (unsigned char) Level27_7C1D4Field(privateRecord19, unsigned char *, 0x11);
            Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x46) = (unsigned char) Level27_7C1D4Field(privateRecord19, unsigned char *, 0x12);
            Level27_7C1D4Field(privateRecord19, short *, 8) = 0xB4;
            Level27_7C1D4Field(privateRecord19, short *, 0xA) = 0x1C2;
            Level27_7C1D4Call3BABCView1(ownerRecord18, 0, 0);
            Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x48) = 0xFU;
            goto updateOriginalCommon786;
        case 15:
            argumentWord4 = privateRecord19+16;
            retainedPositionSpawnOrSignedValue16 = (int)&originalFrame.sp48;
            argumentWord5 = retainedPositionSpawnOrSignedValue16;
            rawWord2 = Level27_7C1D4Field(privateRecord19, short*, 6);
            argumentWord6 = 0;
            rawWord3 = rawWord2*2;
            rawWord2 += 14;
            argumentWord7 = Level27_7C1D4Field((int)&Level27_7C1D4Data65920View1, short*, rawWord3);
            rawWord3 = Level27_7C1D4Field((int)&Level27_7C1D4Data658A0View1, short*, rawWord3);
            __asm__("":"=r"(rawWord2):"0"(rawWord2), "r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6), "r"(argumentWord7), "r"(rawWord3):"memory");
            Level27_7C1D4Field(privateRecord19, short*, 6) = rawWord2&255;
            originalFrame.sp38 = 450;
            originalFrame.sp3C = (argumentWord7*35) >> 11;
            originalFrame.sp40 = (rawWord3*35) >> 11;
            Level27_7C1D4Call4EA90View1(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
            Level27_7C1D4Call4ED6CView1(retainedPositionSpawnOrSignedValue16, &originalFrame.sp38, &originalFrame.sp38);
            rawWord2 = originalFrame.sp38;
            rawWord3 = Level27_7C1D4Data6C550View1;
            Level27_7C1D4Field(privateRecord19, short*, 0) = rawWord2;
            Level27_7C1D4Field(privateRecord19, short*, 2) = originalFrame.sp3C;
            Level27_7C1D4Field(privateRecord19, short*, 4) = originalFrame.sp40;
            argumentWord6 = 0;
            argumentWord7 = Level27_7C1D4Field(rawWord3, int*, 12);
            argumentWord4 = Level27_7C1D4Field(ownerRecord18, int*, 12);
            rawWord2 = Level27_7C1D4Field(rawWord3, int*, 16);
            argumentWord5 = Level27_7C1D4Field(ownerRecord18, int*, 16);
            rawWord2 = Level27_7C1D4Call4E880View1(argumentWord7-argumentWord4, rawWord2-argumentWord5, argumentWord6);
            rawWord3 = Level27_7C1D4Call3613CView1(Level27_7C1D4Field(privateRecord19, unsigned char*, 18), rawWord2);
            if (rawWord3 < 24){
                if (rawWord3 >= 2){
                    rawWord3 = 1;
                    __asm__("":"=r"(rawWord3):"0"(rawWord3));
                }
                if (rawWord3 < -1)rawWord3 = -1;
                Level27_7C1D4Field(privateRecord19, unsigned char*, 18) += rawWord3;
            }
            retainedVectorMagnitudeOrData17 = (int)&originalFrame.sp38;
            rawWord2 = Level27_7C1D4Call4EDE8View1(retainedVectorMagnitudeOrData17, 0);
            argumentWord4 = rawWord2;
            argumentWord6 = 0;
            argumentWord5 = originalFrame.sp40;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4), "r"(argumentWord6):"$20");
            retainedMinimumCounterOrVector20 = 225;
            rawWord2 = Level27_7C1D4Call4E880View1(argumentWord4, argumentWord5, argumentWord6);
            __asm__("":"=r"(retainedMinimumCounterOrVector20):"0"(retainedMinimumCounterOrVector20), "r"(rawWord2));
            Level27_7C1D4Field(ownerRecord18, unsigned char*, 69) = rawWord2-64;
            rawWord2 = Level27_7C1D4Call4E880View1(originalFrame.sp38, originalFrame.sp3C, 0);
            argumentWord4 = (int)&originalFrame.sp28;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4), "r"(rawWord2):"$16");
            retainedPositionSpawnOrSignedValue16 = (int)ownerRecord18+12;
            Level27_7C1D4Field(ownerRecord18, unsigned char*, 70) = rawWord2;
            Level27_7C1D4Call4F178View1(argumentWord4, retainedPositionSpawnOrSignedValue16);
            Level27_7C1D4Call4F194View1(retainedPositionSpawnOrSignedValue16, retainedPositionSpawnOrSignedValue16, &originalFrame.sp38);
            temporaryWord11 = Level27_7C1D4Call4EDE8View1(&originalFrame.sp38, 1) + 8;
            if (temporaryWord11 > retainedMinimumCounterOrVector20) {
                retainedMinimumCounterOrVector20 = temporaryWord11;
            }
            Level27_7C1D4DataSpawnParticleView1(1, 0xC, ownerRecord18, originalParticleClass22);
            if (Level27_7C1D4Call359A4View1(privateRecord19 + 8, 2) != 0) {
                Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x48) = 0x10U;
            }
            if ((Level27_7C1D4Field(ownerRecord18, int *, 0xC) < 0x400) || (Level27_7C1D4Field(ownerRecord18, int *, 0x10) < 0x400) || (Level27_7C1D4Field(ownerRecord18, int *, 0x14) < 0x400)) {
                Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x48) = 0x10U;
            }
            argumentWord4 = (int)&originalFrame.sp28;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4):"$16");
            retainedPositionSpawnOrSignedValue16 = (int)ownerRecord18+12;
            if (Level27_7C1D4Call18368View1(argumentWord4, retainedPositionSpawnOrSignedValue16) != 0) {
                Level27_7C1D4Call4F1C8View1(retainedPositionSpawnOrSignedValue16, retainedPositionSpawnOrSignedValue16, &originalFrame.sp38);
                Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x48) = 0x10U;
            }
            retainedPositionSpawnOrSignedValue16 = Level27_7C1D4Call1BA30View1(retainedPositionSpawnOrSignedValue16, 300, 0, 0, 0x100000, ownerRecord18);
            __asm__("":"=r"(ownerRecord18):"0"(ownerRecord18), "r"(retainedPositionSpawnOrSignedValue16));
            if (!retainedPositionSpawnOrSignedValue16) goto prepareOriginalContactPosition419;
            rawWord3 = Level27_7C1D4Field(retainedPositionSpawnOrSignedValue16, short*, 54);
            argumentWord4 = (int)ownerRecord18+12;
            if (rawWord3 == 447) goto callOriginalContact420;
            rawWord2 = Level27_7C1D4Call4E880View1(Level27_7C1D4Field(privateRecord19, short*, 0), Level27_7C1D4Field(privateRecord19, short*, 2), 0);
            Level27_7C1D4Field(retainedPositionSpawnOrSignedValue16, unsigned char*, 81) = rawWord2;
            if (!(rawWord2&255))Level27_7C1D4Field(retainedPositionSpawnOrSignedValue16, unsigned char*, 81) = 1;
            Level27_7C1D4Field(ownerRecord18, unsigned char*, 72) = 16;
            prepareOriginalContactPosition419:argumentWord4 = (int)ownerRecord18+12;
            callOriginalContact420:if (Level27_7C1D4Call19194View1(argumentWord4, retainedMinimumCounterOrVector20))Level27_7C1D4Field(ownerRecord18, unsigned char*, 72) = 16;
            goto updateOriginalCommon786;
        case 16:
            Level27_7C1D4Data6E1D4View1 = 0x9C4;
            Level27_7C1D4Data6E1D8View1 = 0x1E;
            Level27_7C1D4Call3BABCView1(ownerRecord18, 1, 0);
            Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x48) = 0x11U;
            Level27_7C1D4Field(ownerRecord18, signed char *, 0x41) = 0;
            Level27_7C1D4Field(ownerRecord18, signed char *, 0x4C) = 0;
            Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x4D) = 0U;
            Level27_7C1D4Field(privateRecord19, short *, 8) = 0x3C;
            if (Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x3A) == 0) {
                Level27_7C1D4Call13ACCView1(Level27_7C1D4Data6C550View1, 0xD);
            }
        case 17:
            rawWord3 = Level27_7C1D4Field(privateRecord19, short*, 8);
            retainedVectorMagnitudeOrData17 = 700;
            if (rawWord3 >= 31){
                __asm__("":"=r"(retainedVectorMagnitudeOrData17):"0"(retainedVectorMagnitudeOrData17));
                rawWord2 = (60-rawWord3)*retainedVectorMagnitudeOrData17;
                __asm__("":"=r"(rawWord2):"0"(rawWord2):"$3");
                rawWord3 = rawWord2/60;
                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                retainedVectorMagnitudeOrData17 = rawWord3+350;
            }
            else{
                __asm__("":"=r"(retainedVectorMagnitudeOrData17):"0"(retainedVectorMagnitudeOrData17));
                rawWord3 = rawWord3*retainedVectorMagnitudeOrData17;
                __asm__("":"=r"(rawWord3):"0"(rawWord3):"$2");
                rawWord2 = rawWord3/60;
                __asm__("":"=r"(rawWord2):"0"(rawWord2));
                retainedVectorMagnitudeOrData17 = rawWord2+350;
            }
            if (Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x49) != 0xFF) {
                temporaryWord4 = Level27_7C1D4Call1BA30View1(ownerRecord18 + 0xC, 0x3E8, 1, 0, 0x10100000, ownerRecord18);
                if (temporaryWord4 != 0) {
                    Level27_7C1D4Field(temporaryWord4, unsigned char *, 0x51) = Level27_7C1D4Call4E880View1(Level27_7C1D4Field(temporaryWord4, int *, 0xC) - Level27_7C1D4Field(ownerRecord18, int *, 0xC), Level27_7C1D4Field(temporaryWord4, int *, 0x10) - Level27_7C1D4Field(ownerRecord18, int *, 0x10), 0);
                }
            }
            retainedMinimumCounterOrVector20 = 0;
            originalParticleChannel64At21 = 64;
            __asm__("":"=r"(originalParticleChannel64At21):"0"(originalParticleChannel64At21));
        spawnOriginalDebrisLoop505:
            if ((Level27_7C1D4Data6C578View1 - Level27_7C1D4Data6C574View1) >= 0x15) {
                temporaryWord5 = Level27_7C1D4DataSpawnMobyView1(0x146, ownerRecord18);
                if (temporaryWord5 != 0) {
                    Level27_7C1D4Field(temporaryWord5, int *, 0xC) = (int) (Level27_7C1D4Field(temporaryWord5, int *, 0xC) + Level27_7C1D4Call363DCView1(0, retainedVectorMagnitudeOrData17));
                    Level27_7C1D4Field(temporaryWord5, int *, 0x10) = (int) (Level27_7C1D4Field(temporaryWord5, int *, 0x10) + Level27_7C1D4Call363DCView1(0, retainedVectorMagnitudeOrData17));
                    temporaryWord6 = Level27_7C1D4Call363DCView1(0, retainedVectorMagnitudeOrData17);
                    Level27_7C1D4Field(temporaryWord5, signed char*, 76) = originalParticleChannel64At21;
                    Level27_7C1D4Field(temporaryWord5, signed char*, 78) = originalParticleChannel64At21;
                    Level27_7C1D4Field(temporaryWord5, int *, 0x14) = (int) (Level27_7C1D4Field(temporaryWord5, int *, 0x14) + temporaryWord6);
                }
                retainedMinimumCounterOrVector20 += 1;
                if (retainedMinimumCounterOrVector20 < 2) {
                    goto spawnOriginalDebrisLoop505;
                }
            }
            __asm__ volatile("":::"$4");
            if (Level27_7C1D4Call359A4View1(privateRecord19+8, 2) != 0) goto removeOriginalOwner646;
            goto updateOriginalCommon786;
        case 0:
            rawWord2 = Level27_7C1D4Field(privateRecord19, short*, 14);
            argumentWord4 = Level27_7C1D4Data6C648View1;
            rawWord3 = rawWord2*11;
            rawWord2 = Level27_7C1D4Data6C550View1;
            __asm__ volatile(""::"r"(rawWord3):"memory");
            rawWord3 = rawWord3*8+rawWord2;
            rawWord2 = Level27_7C1D4Field(privateRecord19, unsigned short*, 8);
            argumentWord5 = Level27_7C1D4Field(rawWord3, int*, 0);
            temporaryWord7 = rawWord2+argumentWord4;
            Level27_7C1D4Field(privateRecord19, short *, 8) = temporaryWord7;
            if ((short)temporaryWord7 >= 0x2711) {
                Level27_7C1D4Field(privateRecord19, short *, 8) = 0x2710;
            }
            if (Level27_7C1D4Field(argumentWord5, int*, 40) != Level27_7C1D4Field(privateRecord19, unsigned char*, 21)) {
                Level27_7C1D4Field(privateRecord19, short *, 4) = 0x64;
                Level27_7C1D4Field(privateRecord19, short *, 0) = 0;
                Level27_7C1D4Field(privateRecord19, short *, 2) = 0;
                Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x48) = 1U;
            }
            goto updateOriginalCommon786;
        case 13:
            if (Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x49) != 0) {
                Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x49) = 0U;
                Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x48) = 0xAU;
            }
            goto updateOriginalCommon786;
        case 1:
            Level27_7C1D4Field(ownerRecord18, int *, 0xC) = (int) (Level27_7C1D4Field(ownerRecord18, int *, 0xC) + Level27_7C1D4Field(privateRecord19, short *, 0));
            Level27_7C1D4Field(ownerRecord18, int *, 0x10) = (int) (Level27_7C1D4Field(ownerRecord18, int *, 0x10) + Level27_7C1D4Field(privateRecord19, short *, 2));
            Level27_7C1D4Field(ownerRecord18, int *, 0x14) = (int) (Level27_7C1D4Field(ownerRecord18, int *, 0x14) + Level27_7C1D4Field(privateRecord19, short *, 4));
            rawWord2 = Level27_7C1D4Field(privateRecord19, unsigned short*, 4)-16;
            temporaryWord8 = rawWord2;
            rawWord2 = temporaryWord8;
            Level27_7C1D4Field(privateRecord19, short*, 4) = rawWord2;
            __asm__ volatile("":::"memory");
            retainedPositionSpawnOrSignedValue16 = 0;
            if ((short)temporaryWord8 < -0x14) {
                do {
                    argumentWord4 = 4;
                    argumentWord5 = 12;
                    argumentWord6 = (int)ownerRecord18;
                    argumentWord7 = originalParticleClass22;
                    rawWord2 = (int)Level27_7C1D4DataSpawnParticleView1;
                    __asm__("":"=r"(rawWord2):"0"(rawWord2), "r"(argumentWord4), "r"(argumentWord5), "r"(argumentWord6), "r"(argumentWord7));
                    retainedPositionSpawnOrSignedValue16++;
                    ((int(*)())rawWord2)(argumentWord4, argumentWord5, argumentWord6, argumentWord7);
                }
                while (retainedPositionSpawnOrSignedValue16 < 5);
                goto removeOriginalOwner646;
            }
            goto updateOriginalCommon786;
        case 10:
            temporaryWord12 = Level27_7C1D4Field(ownerRecord18, int *, 0x14);
            if ((temporaryWord12 >= 0x5001) || (Level27_7C1D4Field(ownerRecord18, int *, 0xC) < 0x400) || (Level27_7C1D4Field(ownerRecord18, int *, 0x10) < 0x400) || (temporaryWord12 < 0x400)) {
                goto removeOriginalOwner646;
            }
            goto updateOriginalMovingState650;
            removeOriginalOwner646:Level27_7C1D4Call55B18View1(ownerRecord18);
            return;
        updateOriginalMovingState650:
            argumentWord4 = (int)&originalFrame.sp60;
            __asm__("":"=r"(argumentWord4):"0"(argumentWord4):"$17");
            retainedVectorMagnitudeOrData17 = (int)ownerRecord18+12;
            Level27_7C1D4Call4F178View1(argumentWord4, retainedVectorMagnitudeOrData17);
            rawWord3 = Level27_7C1D4Field(privateRecord19, short*, 0);
            rawWord2 = Level27_7C1D4Field(ownerRecord18, int*, 12);
            Level27_7C1D4Field(ownerRecord18, int*, 12) = rawWord2+rawWord3;
            __asm__ volatile("":::"memory");
            rawWord3 = Level27_7C1D4Field(privateRecord19, short*, 2);
            rawWord2 = Level27_7C1D4Field(ownerRecord18, int*, 16);
            Level27_7C1D4Field(ownerRecord18, int*, 16) = rawWord2+rawWord3;
            __asm__ volatile("":::"memory");
            rawWord3 = Level27_7C1D4Field(privateRecord19, short*, 4);
            rawWord2 = Level27_7C1D4Field(ownerRecord18, int*, 20);
            __asm__ volatile(""::"r"(rawWord3):"$4", "memory");
            argumentWord4 = (int)&originalFrame.sp70;
            Level27_7C1D4Field(ownerRecord18, int*, 20) = rawWord2+rawWord3;
            Level27_7C1D4Field(privateRecord19, short *, 4) = (short) ((unsigned short) Level27_7C1D4Field(privateRecord19, short *, 4) - 0x10);
            originalFrame.sp70 = (int) Level27_7C1D4Field(privateRecord19, short *, 0);
            originalFrame.sp74 = (int) Level27_7C1D4Field(privateRecord19, short *, 2);
            argumentWord5 = 1;
            rawWord2 = Level27_7C1D4Field(privateRecord19, short*, 4);
            __asm__ volatile(""::"r"(argumentWord4), "r"(argumentWord5):"$16", "memory");
            retainedPositionSpawnOrSignedValue16 = 225;
            originalFrame.sp78 = rawWord2;
            rawWord2 = Level27_7C1D4Call4EDE8View1(argumentWord4, argumentWord5);
            __asm__("":"=r"(retainedPositionSpawnOrSignedValue16):"0"(retainedPositionSpawnOrSignedValue16), "r"(rawWord2));
            temporaryWord13 = rawWord2+8;
            if (temporaryWord13 > retainedPositionSpawnOrSignedValue16) {
                retainedPositionSpawnOrSignedValue16 = temporaryWord13;
            }
            Level27_7C1D4Call55D24View1(ownerRecord18, 2);
            if ((Level27_7C1D4Call359A4View1(privateRecord19 + 0x14, 1) != 0) && (Level27_7C1D4Call19194View1(retainedVectorMagnitudeOrData17, retainedPositionSpawnOrSignedValue16) != 0)) {
                argumentWord5 = 0;
                retainedVectorMagnitudeOrData17 = (int)&Level27_7C1D4Data71920View1;
                __asm__("":"=r"(retainedVectorMagnitudeOrData17):"0"(retainedVectorMagnitudeOrData17), "r"(argumentWord5));
                retainedMinimumCounterOrVector20 = retainedVectorMagnitudeOrData17-8;
                __asm__("":"=r"(retainedMinimumCounterOrVector20):"0"(retainedMinimumCounterOrVector20), "r"(argumentWord5):"$4", "memory");
                rawWord2 = Level27_7C1D4Field(privateRecord19, short*, 0);
                argumentWord4 = retainedMinimumCounterOrVector20;
                originalFrame.sp80 = rawWord2;
                __asm__ volatile(""::"r"(argumentWord4):"memory");
                originalFrame.sp84 = (int) Level27_7C1D4Field(privateRecord19, short *, 2);
                retainedPositionSpawnOrSignedValue16 = Level27_7C1D4Field(retainedVectorMagnitudeOrData17, int*, 0);
                rawWord2 = Level27_7C1D4Field(privateRecord19, short*, 4);
                if (retainedPositionSpawnOrSignedValue16 < 0)retainedPositionSpawnOrSignedValue16 = -retainedPositionSpawnOrSignedValue16;
                originalFrame.sp88 = rawWord2;
                rawWord2 = Level27_7C1D4Call4EDE8View1(argumentWord4, argumentWord5);
                retainedPositionSpawnOrSignedValue16 = retainedPositionSpawnOrSignedValue16 < rawWord2;
                __asm__("":"=r"(retainedPositionSpawnOrSignedValue16):"0"(retainedPositionSpawnOrSignedValue16));
                if (retainedPositionSpawnOrSignedValue16){
                    Level27_7C1D4Call4F178View1(&originalFrame.sp90, retainedMinimumCounterOrVector20);
                    if (Level27_7C1D4Call4EF74View1(&originalFrame.sp80, &originalFrame.sp90, &originalFrame.sp80) != 0) {
                        originalFrame.sp80 = (int) (originalFrame.sp80 * 6) >> 3;
                        originalFrame.sp84 = (int) (originalFrame.sp84 * 6) >> 3;
                        originalFrame.sp88 = (int) (originalFrame.sp88 * 6) >> 3;
                    }
                }
                else if ((retainedPositionSpawnOrSignedValue16 = Level27_7C1D4Field(retainedVectorMagnitudeOrData17, int*, 0), ((retainedPositionSpawnOrSignedValue16 < 0) && (originalFrame.sp88 > 0)) || ((retainedPositionSpawnOrSignedValue16 > 0) && (originalFrame.sp88 < 0)))){
                    originalFrame.sp80 = 0;
                    originalFrame.sp84 = 0;
                    rawWord2 = -originalFrame.sp88;
                    __asm__("":"=r"(rawWord2):"0"(rawWord2));
                    temporaryWord3 = (rawWord2*4) >> 3;
                    originalFrame.sp88 = temporaryWord3;
                    if (temporaryWord3 < 0x28) {
                        Level27_7C1D4Field(ownerRecord18, int *, 0x14) = (int) (Level27_7C1D4Call35D38View1(ownerRecord18) + 0xE1);
                        Level27_7C1D4Field(privateRecord19, short *, 8) = 0;
                        Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x48) = 0U;
                    }
                }
                Level27_7C1D4Field(privateRecord19, short *, 0) = (short) originalFrame.sp80;
                Level27_7C1D4Field(privateRecord19, short *, 2) = (short) originalFrame.sp84;
                Level27_7C1D4Field(privateRecord19, short *, 4) = (short) originalFrame.sp88;
            }
            Level27_7C1D4Call35D38View1(ownerRecord18);
            Level27_7C1D4Call5629CView1(ownerRecord18);
            goto updateOriginalCommon786;
        }
    }
    else {
    updateOriginalCommon786:
        if ((Level27_7C1D4Field(privateRecord19, unsigned char *, 0x13) != 0) && (Level27_7C1D4Field(ownerRecord18, unsigned char *, 0x4D) != 0)) {
            Level27_7C1D4DataSpawnParticleView1(1, 0xC, ownerRecord18, originalParticleClass22);
        }
    }
}
#undef Level27_7C1D4Field


extern Vector3D DecodedTimedBurstPlayer __asm__("D_8006E020");
extern int D_8006E024;
extern unsigned short DecodedTimedBurstYaw __asm__("D_8006E040");
extern int DecodedTimedBurstPlayerFlags __asm__("D_80070328 + 0x24");
extern Vector3D DecodedTimedBurstSpyro __asm__("D_80070328");
extern Moby* D_8006C550;
int DecodedTimedBurstSignedRandom(int,int) __asm__("func_800363DC");
int rand(void);
void func_level_27_8007CE84(Moby* moby) {
    int* timer = moby->mobyTag;
    Vector3D position, velocity;
    unsigned char* particle;
    int index;
    switch (moby->state) {
    case 0:
        for (index = 0; index < 3; index++) {
            func_8004F178(&position,&moby->position);
            velocity.x = DecodedTimedBurstSignedRandom(0,20);
            velocity.y = DecodedTimedBurstSignedRandom(0,20);
            velocity.z = func_8003636C(20,40);
            SpawnParticle(1,0,&position,&velocity);
        }
        if (func_800359A4(timer,4)) {
            *timer = 0xF0;
            moby->state = 1;
        }
        break;
    case 1:
        if (func_8004F334(&moby->position,&DecodedTimedBurstPlayer) < 1700) goto remove;
        if (func_8004F264((short)DecodedTimedBurstYaw >> 4,func_8004E880(moby->position.x-DecodedTimedBurstPlayer.x,moby->position.y-D_8006E024,0)) < 40) {
            for (index = 0; index < 6; index++) {
                func_8004F178(&position,&moby->position);
                position.x += DecodedTimedBurstSignedRandom(0,30);
                position.y += DecodedTimedBurstSignedRandom(0,30);
                position.z += DecodedTimedBurstSignedRandom(0,40);
                velocity.x = DecodedTimedBurstSignedRandom(0,24);
                velocity.y = DecodedTimedBurstSignedRandom(0,24);
                velocity.z = func_8003636C(110,170);
                particle = (unsigned char*)SpawnParticle(1,13,&position,&velocity);
                particle[11] = rand() & 3;
            }
        }
        if (func_8004F334(&moby->position,&DecodedTimedBurstSpyro) < 450) DecodedTimedBurstPlayerFlags |= 14;
        if (D_8006C550->state == 11 && *timer > 30) *timer = 30;
        if (func_800359A4(timer,4)) {
remove:
            func_80055B18(moby);
        }
        break;
    }
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
void func_level_27_8007D118(Moby* arg0) {
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
/* AI generated adaptation; not human reviewed. Original SCUS-94467 level17 8007C3D0. */
typedef struct {int unk0;PathTag* path;int timer;} Vehicle883Tag;
extern Moby* Vehicle883Moby __asm__("D_8006C65C");
extern int D_8006C770;
void func_80034F80(Moby*,int);
void func_level_27_8007D9A0(Moby* arg0) {
    Vector3D sp10,sp20,sp30,sp40,sp50,sp60;
    int temp_v1_3;
    Vehicle883Tag* mobyTag;

    mobyTag = (Vehicle883Tag*)arg0->mobyTag;
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
            if(Vehicle883Moby!=0) {
                *((unsigned char*)Vehicle883Moby+0x4C)=0;
                *((unsigned char*)Vehicle883Moby+0x4D)=0;
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
                if ((D_80070104.loadLevel == 0x28) && (eggsCollectedArray[lvlIdToIndex[37]] == 0)) {
                    D_80070104.loadLevel = 0x25;
                }
                // BUG // Spike Bug
                // In NTSC-U Rev 0, the game checks if "Bianca Strikes Back" has been seen instead of "Spike Is Born"
                // As this cutscene is always seen by this point in normal play, "Spike Is Born" is never shown to the player
                // This was fixed in all later revisions
                if ((D_80070104.loadLevel != 0x25) || (progressFlags.lvl67_AMonsterToEndAllMonsters != 0)) {
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


extern int D_8006C528, D_8006C598, D_8006C73C, currentLevel;
extern unsigned char D_8006C7B4, eggsCollectedArray[40], lvlIdToIndex[0x48];
extern ProgressFlags progressFlags;
extern short D_800658A0[0x100], D_80065920[0x100];
extern int func_8001A358(Vector3D*, int);
extern int func_8003BABC(Moby*, int, char);
extern int func_8003BFC0(Moby*, int);
extern void func_8003BE70(int);
extern void func_80054F94(int, Moby*);
extern void func_800584BC(int, int);

typedef struct {
    int unk0;
    int unk4;
    PathTag* unk8;
    int unkC; // countdown timer of some sort
    int unk10;
} MobyTag_651;
/* Adaptation from upstream func_level_17_8007D19C; integration is AI generated
 * and not human reviewed. SCUS-94467 USA Rev0 8007E76C..8007F204,
 * plus original ten-entry state dispatch. Retain all native integer arithmetic,
 * field widths, post-helper reads and the original Rev0 progress-flag branch.
 * Units, vehicle/path producers and caller cadence are not established here.
 * Acceptance: original linked words, dispatch entries and complete retail hashes.
 */
void func_level_27_8007E76C(Moby* arg0) {
    Vector3D sp10;
    Vector3D sp20;
    Vector3D sp30;
    Vector3D sp40;
    Vector3D sp50;
    Vector3D sp60;
    int temp_v1_3;
    MobyTag_651* mobyTag;

    mobyTag = (MobyTag_651*)arg0->mobyTag;
    switch (arg0->state) {

    case 0:
        switch (arg0->substate) {
        case 0:
            if (progressFlags.lvl30_RocketUsable || ((currentLevel != 0x14) && !progressFlags.lvl20_WhirligigUsable)) {
                func_80055B18(arg0);
                return;
            }
            else {
                arg0->position.z += 0x1000;
                spyro.unk17a = 0x10018000;
                spyro.unk20[1] = 0;
                func_8004F178(&spyro.unk19, &arg0->position);
                spyro.unk19.z += spyro.unk4a + 0x133;
                spyro.unk18.roll = arg0->angle.roll;
                spyro.unk18.pitch = arg0->angle.pitch;
                spyro.unk18.yaw = arg0->angle.yaw;
                arg0->substate = 1;
                func_8003B7B4(&arg0->substate, 1, &savedData);
                func_8003B7B4(&arg0->substate, 1, &unsavedData);
                arg0->state = 7;
                if ((D_8006C73C != 0) && (currentLevel != D_8006C73C) && ((temp_v1_3 = D_8006C73C % 10, (temp_v1_3 == 0)) || ((temp_v1_3 == 7) && (D_8006C73C < 0x3C))) && (arg0->mobyClass == D_8006C528)) {
                    arg0->position.z += 0xC00;
                    func_800136F0(&camera.unk170, (Vector3D*)mobyTag->unk8->nodes, &arg0->position);
                    camera.unk170.yaw = 0;
                    camera.unk170.pitch = 0;
                    spyro.unk17a = 0x10018000;
                    spyro.unk20[1] = 0;
                    camera.unk170.pos.azimuth -= spyro.rotation.yaw;
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
                    D_80070104.loadLevel = ((currentLevel / 10) + 1) * 0xA;
                    arg0->state = 4U;
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
        sp20.x = D_80065920[arg0->angle.yaw];
        sp20.y = D_800658A0[arg0->angle.yaw];
        sp20.z = 0;
        func_8004F194(&sp20, &sp20, &arg0->position);
        if (ovlHeader.unk2c(&sp20) != 0) {
            spyro.unk17c = 0;
            ovlHeader.unk2b(&sp20, arg0->angle.yaw, 0);
            arg0->state = 6U;
        }
        break;

    case 6:
        sp30.x = D_80065920[arg0->angle.yaw];
        sp30.y = D_800658A0[arg0->angle.yaw];
        sp30.z = 0;
        func_8004F194(&sp30, &sp30, &arg0->position);
        if (ovlHeader.unk2b(&sp30, arg0->angle.yaw, 0) != 0) {
            func_8004F178(&sp40, &spyro.position);
            sp40.z -= spyro.unk4a;
            func_8003B634(&savedData, &sp40, spyro.bodyRotation.yaw);
            mobyTag->unkC = 0x78;
            arg0->substate = 0;
            arg0->state = 8;
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
        func_8004F178(&sp50, &arg0->position);
        arg0->position.z += 0x400;
        sp50.z += 0x200;
        sp50.z = func_8001A358(&sp50, 0x200);
        if (sp50.z != 0) {
            arg0->position.z = sp50.z;
            func_80013B7C(0);
            arg0->state = 5U;
        } else {
            arg0->position.z -= 0x400;
        }
        func_80055D24(arg0, 2);
        break;

    case 8:
        func_80034F40(arg0, 1);
        if (mobyTag->unkC != 0) {
            arg0->position.z += 0x40;
            func_800359A4(&mobyTag->unkC, 4);
            if (arg0->substate == 0) {
                spyro.unk17a = 0x10000002;
                if (spyro.movementState == 0) {
                    arg0->substate = 1;
                }
            }
        }
        if (D_8006C7B4 & 1) {
            arg0->state = 9;
        }
        break;

    case 9:
        spyro.unk17a = 0x10000002;
        func_80034F40(arg0, 1);
        arg0->position.z -= 0x40;
        func_8004F178(&sp60, &arg0->position);
        arg0->position.z += 0x400;
        sp60.z += 0x200;
        sp60.z = func_8001A358(&sp60, 0x200);
        if (sp60.z != 0) {
            arg0->position.z = sp60.z;
            arg0->substate = 0;
            arg0->state = 1;
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
void func_level_27_8007F208(void *input) {
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


void func_level_27_8008035C(Moby* moby) {
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
void func_level_27_8008037C(Moby* argument) {
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
/* SCUS-94467 USA Rev0, func_level_27_8008057C.
 * AI generated; not human reviewed.
 * Complete original 32-bit word phases are kept separate when one machine
 * register changes roles. A2 phase objects and the two T1 phases have disjoint
 * live ranges; no source value is inferred from an incoming saved register.
 * Empty asm templates express complete initialized-value lifetimes only.
 * Each multiplication has one complete signed 64-bit product. Its original
 * low/high projection is read before another product or call can replace it.
 * The frame represents the original 520-byte o32 reservation. Its real
 * outgoing fifth argument is passed by the C call ABI, not a manual SP write.
 * int arguments carry the exact original four-byte o32 words, including
 * target pointer words. This source targets the frozen 32-bit MIPS compiler.
 */
#define Level27_8057CField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
#define Level27_8057CKeep(v) __asm__("":"=r"(v):"0"(v))
int Level27_8057C_func_8001C288(int,int,int) __asm__("func_8001C288");
int Level27_8057C_func_800359A4(int,int) __asm__("func_800359A4");
int Level27_8057C_func_8003615C(int,int) __asm__("func_8003615C");
int Level27_8057C_func_8003BABC(int,int,int) __asm__("func_8003BABC");
void Level27_8057C_func_8003BE70(int) __asm__("func_8003BE70");
int Level27_8057C_func_8003BFC0(int,int) __asm__("func_8003BFC0");
int Level27_8057C_func_8004E880(int,int,int) __asm__("func_8004E880");
int Level27_8057C_func_8004E9E4(int) __asm__("func_8004E9E4");
int Level27_8057C_func_8004EA2C(int) __asm__("func_8004EA2C");
int Level27_8057C_func_8004EDE8(int,int) __asm__("func_8004EDE8");
void Level27_8057C_func_8004F08C(int,int,int) __asm__("func_8004F08C");
void Level27_8057C_func_8004F0E8(int,int) __asm__("func_8004F0E8");
void Level27_8057C_func_8004F110(int,int) __asm__("func_8004F110");
void Level27_8057C_func_8004F168(int) __asm__("func_8004F168");
void Level27_8057C_func_8004F178(int,int) __asm__("func_8004F178");
void Level27_8057C_func_8004F194(int,int,int) __asm__("func_8004F194");
void Level27_8057C_func_8004F1C8(int,int,int) __asm__("func_8004F1C8");
int Level27_8057C_func_8004F334(int,int) __asm__("func_8004F334");
int Level27_8057C_func_80050B00(int,int,int,int,int) __asm__("func_80050B00");
void Level27_8057C_func_80050B88(int) __asm__("func_80050B88");
void Level27_8057C_func_80055B18(int) __asm__("func_80055B18");
void Level27_8057C_func_80055D24(int,int) __asm__("func_80055D24");
void Level27_8057C_func_80055F14(int,int,int) __asm__("func_80055F14");
int Level27_8057C_rand(void) __asm__("rand");
extern int Level27_8057C_D_800658A0 __asm__("D_800658A0");
extern int Level27_8057C_D_80065920 __asm__("D_80065920");
extern int Level27_8057C_D_8006C640 __asm__("D_8006C640");
extern int Level27_8057C_D_8006C644 __asm__("D_8006C644");
extern int Level27_8057C_D_8006E020 __asm__("D_8006E020");
extern int Level27_8057C_D_80070328 __asm__("D_80070328");
extern int (*Level27_8057C_SpawnParticle)(int,int,int,int) __asm__("SpawnParticle");
typedef union{long long full;
struct{
#if defined(__MIPSEB__)
int high;
unsigned low;
#else
unsigned low;
int high;
#endif
}words;
}Level27_8057CProduct;
static __inline__ int Level27_8057CAt23(int value){register int whole __asm__("$23")=value;
__asm__("":"=r"(whole):"0"(whole));
return whole;
}
extern int Level27_8057CGlobal70328_4 __asm__("D_80070328+4");
extern int Level27_8057CGlobal70328_8 __asm__("D_80070328+8");
extern int Level27_8057CGlobal70328_36 __asm__("D_80070328+36");
void func_level_27_8008057C(void*input){
register int workWord2 __asm__("$2");
register int workWord3 __asm__("$3");
register int argumentWord4 __asm__("$4");
register int argumentWord5 __asm__("$5");
register int argumentWord7 __asm__("$7");
register int workWord10 __asm__("$10");
register int workWord11 __asm__("$11");
int workWord12;
register int workWord13 __asm__("$13");
register int workWord14 __asm__("$14");
register int workWord15 __asm__("$15");
register int savedWord16 __asm__("$16");
register int savedWord17 __asm__("$17");
register int savedWord18 __asm__("$18");
register int savedWord19 __asm__("$19");
register int savedWord20 __asm__("$20");
register int savedWord21 __asm__("$21");
register int savedWord22 __asm__("$22");
register int workWord24 __asm__("$24");
register int workWord25 __asm__("$25");
register int workWord8 __asm__("$8");
int retainedWord23,retainedWord30,fifthArgument;
register int argumentOrMathWord6Phase0 __asm__("$6");
register int argumentOrMathWord6Phase1 __asm__("$6");
register int argumentOrMathWord6Phase2 __asm__("$6");
int argumentOrMathWord6Phase3;
int argumentOrMathWord6Phase4;
int argumentOrMathWord6Phase5;
register int argumentOrMathWord6Phase6 __asm__("$6");
register int argumentOrMathWord6Phase7 __asm__("$6");
int argumentOrMathWord6Phase8;
register int argumentOrMathWord6Phase9 __asm__("$6");
int argumentOrMathWord6Phase10;
register int argumentOrMathWord6Phase11 __asm__("$6");
int argumentOrMathWord6Phase12;
register int argumentOrMathWord6Phase13 __asm__("$6");
int argumentOrMathWord6Phase14;
register int argumentOrMathWord6Phase15 __asm__("$6");
int argumentOrMathWord6Phase16;
register int argumentOrMathWord6Phase17 __asm__("$6");
int argumentOrMathWord6Phase18;
register int argumentOrMathWord6Phase19 __asm__("$6");
int argumentOrMathWord6Phase20;
register int argumentOrMathWord6Phase21 __asm__("$6");
int argumentOrMathWord6Phase22;
register int argumentOrMathWord6Phase23 __asm__("$6");
int argumentOrMathWord6Phase24;
register int argumentOrMathWord6Phase25 __asm__("$6");
register int argumentOrMathWord6Phase26 __asm__("$6");
register int argumentOrMathWord6Phase27 __asm__("$6");
register int argumentOrMathWord6Phase28 __asm__("$6");
register int argumentOrMathWord6Phase29 __asm__("$6");
register int argumentOrMathWord6Phase30 __asm__("$6");
register int argumentOrMathWord6Phase31 __asm__("$6");
register int argumentOrMathWord6Phase32 __asm__("$6");
register int argumentOrMathWord6Phase33 __asm__("$6");
register int argumentOrMathWord6Phase34 __asm__("$6");
register int argumentOrMathWord6Phase35 __asm__("$6");
int argumentOrMathWord6Phase36;
register int argumentOrMathWord6Phase37 __asm__("$6");
int argumentOrMathWord6Phase38;
int argumentOrMathWord6Phase39;
int argumentOrMathWord6Phase40;
register int argumentOrMathWord6Phase41 __asm__("$6");
register int argumentOrMathWord6Phase42 __asm__("$6");
int argumentOrMathWord6Phase43;
register int argumentOrMathWord6Phase44 __asm__("$6");
register int argumentOrMathWord6Phase45 __asm__("$6");
int argumentOrMathWord6Phase46;
int argumentOrMathWord6Phase47;
register int argumentOrMathWord6Phase48 __asm__("$6");
int argumentOrMathWord6Phase49;
int argumentOrMathWord6Phase50;
int argumentOrMathWord6Phase51;
register int argumentOrMathWord6Phase52 __asm__("$6");
int argumentOrMathWord6Phase53;
register int argumentOrMathWord6Phase54 __asm__("$6");
int argumentOrMathWord6Phase55;
register int argumentOrMathWord6Phase56 __asm__("$6");
register int argumentOrMathWord6Phase57 __asm__("$6");
register int argumentOrMathWord6Phase58 __asm__("$6");
register int argumentOrMathWord6Phase59 __asm__("$6");
int argumentOrMathWord6Phase60;
register int argumentOrMathWord6Phase61 __asm__("$6");
register int argumentOrMathWord6Phase62 __asm__("$6");
register int argumentOrMathWord6Phase63 __asm__("$6");
register int argumentOrMathWord6Phase64 __asm__("$6");
register int argumentOrMathWord6Phase65 __asm__("$6");
register int argumentOrMathWord6Phase66 __asm__("$6");
register int argumentOrMathWord6Phase67 __asm__("$6");
register int argumentOrMathWord6Phase68 __asm__("$6");
register int argumentOrMathWord6Phase69 __asm__("$6");
register int argumentOrMathWord6Phase70 __asm__("$6");
int argumentOrMathWord6Phase71;
register int argumentOrMathWord6Phase72 __asm__("$6");
register int argumentOrMathWord6Phase73 __asm__("$6");
register int argumentOrMathWord6Phase74 __asm__("$6");
int colorWord8;
register int colorWord9 __asm__("$9");
register int workWord9 __asm__("$9");
struct {
    int sp18,
        sp1C,
        sp20,
        sp24,
        sp28,
        sp2C,
        sp30,
        sp34,
        sp38,
        sp3C,
        sp40,
        sp44,
        sp48,
        sp4C,
        sp50,
        sp54,
        sp58,
        sp5C,
        sp60,
        sp64,
        sp68,
        sp6C,
        sp70,
        sp74,
        sp78,
        sp7C,
        sp80,
        sp84,
        sp88,
        sp8C,
        sp90,
        sp94,
        sp98,
        sp9C,
        spA0,
        spA4,
        spA8,
        spAC,
        spB0,
        spB4,
        spB8,
        spBC,
        spC0,
        spC4,
        spC8,
        spCC,
        spD0,
        spD4,
        spD8,
        spDC,
        spE0,
        spE4,
        spE8,
        spEC,
        spF0,
        spF4,
        spF8,
        spFC,
        sp100,
        sp104,
        sp108,
        sp10C,
        sp110,
        sp114,
        sp118,
        sp11C,
        sp120,
        sp124,
        sp128,
        sp12C,
        sp130,
        sp134,
        sp138,
        sp13C,
        sp140,
        sp144,
        sp148,
        sp14C,
        sp150,
        sp154,
        sp158,
        sp15C,
        sp160,
        sp164,
        sp168,
        sp16C,
        sp170,
        sp174,
        sp178,
        sp17C,
        sp180,
        sp184,
        sp188,
        sp18C,
        sp190,
        sp194,
        sp198,
        sp19C,
        sp1A0,
        sp1A4,
        sp1A8,
        sp1AC,
        sp1B0,
        sp1B4,
        sp1B8,
        sp1BC,
        sp1C0,
        sp1C4,
        sp1C8,
        sp1CC,
        sp1D0,
        sp1D4,
        sp1D8,
        sp1DC;
} originalFrame;
Level27_8057CProduct product0,
    product1,
    product2,
    product3,
    product4,
    product5,
    product6,
    product7,
    product8,
    product9,
    product10,
    product11,
    product12,
    product13,
    product14,
    product15,
    product16,
    product17,
    product18,
    product19,
    product20,
    product21,
    product22,
    product23,
    product24,
    product25,
    product26,
    product27,
    product28,
    product29,
    product30,
    product31,
    product32,
    product33,
    product34,
    product35,
    product36,
    product37,
    product38,
    product39,
    product40,
    product41,
    product42,
    product43,
    product44,
    product45,
    product46,
    product47,
    product48,
    product49,
    product50,
    product51,
    product52,
    product53,
    product54,
    product55,
    product56,
    product57,
    product58,
    product59,
    product60,
    product61,
    product62,
    product63,
    product64,
    product65,
    product66,
    product67,
    product68,
    product69,
    product70,
    product71,
    product72,
    product73;
argumentWord4=(int)input;
originalFrame.spD0=argumentWord4;
workWord24=Level27_8057CField(argumentWord4,int*,0);
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
originalFrame.spD8=workWord24;
workWord25=Level27_8057CField(workWord24,int*,0);
originalFrame.spE0=workWord25;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
argumentWord5=Level27_8057CField(workWord25,int*,16);
originalFrame.spE8=workWord24;
workWord2=Level27_8057C_func_8003BFC0(argumentWord4,argumentWord5);
argumentWord5=0+1;
if(workWord2!=0)goto original_800805F4;
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
argumentOrMathWord6Phase74=0+4;
workWord2=Level27_8057C_func_8003BABC(argumentWord4,argumentWord5,argumentOrMathWord6Phase74);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
Level27_8057CField(workWord25,int*,16)=workWord2;
original_800805F4:
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
workWord3=Level27_8057CField(workWord24,unsigned char*,72);
workWord2=0+1;
if(workWord3==0)goto original_8008061C;
if(workWord3==workWord2)goto original_80082270;
goto originalReturn;
original_8008061C:
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
workWord2=Level27_8057CField(workWord25,short*,22);
workWord2=workWord2<512;
if(workWord2!=0)goto original_800806FC;
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,200)):"$16","memory");savedWord16=(int)&Level27_8057C_D_80070328;Level27_8057CKeep(savedWord16);
argumentWord5=savedWord16+0;
workWord2=Level27_8057C_func_8004F334(argumentWord4,argumentWord5);
workWord2=workWord2<251;
argumentOrMathWord6Phase73=0+0;
if(workWord2!=0)goto original_800806F0;
workWord3=Level27_8057CField(savedWord16,int*,0);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,200)):"$2","memory");workWord2=Level27_8057CGlobal70328_4;
argumentWord4=Level27_8057CField(workWord24,int*,0);
__asm__ volatile(""::"r"(workWord24),"m"(Level27_8057CField(workWord24,int*,0)):"memory");
argumentWord5=Level27_8057CField(workWord24,int*,4);
__asm__ volatile("":"=r"(workWord3),"=r"(argumentWord4):"0"(workWord3),"1"(argumentWord4),"m"(Level27_8057CField(workWord24,int*,4)):"memory");
argumentWord4=workWord3-argumentWord4;
argumentWord5=workWord2-argumentWord5;
workWord2=Level27_8057C_func_8004E880(argumentWord4,argumentWord5,argumentOrMathWord6Phase73);
workWord2=(int)((unsigned int)workWord2<<1);
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
argumentOrMathWord6Phase72=Level27_8057CField(((int)&Level27_8057C_D_80065920+workWord2),short*,0);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
__asm__ volatile("":"=r"(argumentOrMathWord6Phase72):"0"(argumentOrMathWord6Phase72),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,200)):"memory");workWord3=(int)((unsigned int)argumentOrMathWord6Phase72<<5);
workWord3=workWord3-argumentOrMathWord6Phase72;
workWord3=(int)((unsigned int)workWord3<<2);
workWord3=workWord3+argumentOrMathWord6Phase72;
workWord3=(workWord3>>11);
originalFrame.sp18=workWord3;
workWord3=Level27_8057CField(((int)&Level27_8057C_D_800658A0+workWord2),short*,0);
__asm__ volatile(""::"m"(originalFrame.sp18):"$6","memory");
argumentOrMathWord6Phase71=(int)&originalFrame.sp18;
Level27_8057CKeep(argumentOrMathWord6Phase71);
originalFrame.sp20=0;
workWord2=(int)((unsigned int)workWord3<<5);
workWord2=workWord2-workWord3;
workWord2=(int)((unsigned int)workWord2<<2);
workWord2=workWord2+workWord3;
workWord2=(workWord2>>11);
originalFrame.sp1C=workWord2;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase71);
workWord2=Level27_8057CGlobal70328_8;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
Level27_8057CField(workWord25,int*,8)=workWord2;
goto original_800806FC;
original_800806F0:
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
argumentWord5=savedWord16+0;
Level27_8057C_func_8004F178(argumentWord4,argumentWord5);
original_800806FC:
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
workWord2=Level27_8057CField(workWord24,unsigned char*,73);
if(workWord2==0)goto original_80080854;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
workWord2=Level27_8057CField(workWord25,short*,20);
if(workWord2==0)goto original_80080778;
argumentWord7=(int)0x1000000AU;
workWord3=(int)&Level27_8057C_D_80070328+524;
Level27_8057CKeep(workWord3);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,208);
__asm__ volatile("":"=r"(workWord3):"0"(workWord3),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,208)):"memory");argumentWord4=workWord3+16;
workWord2=Level27_8057CField(argumentWord5,int*,8);
__asm__ volatile("":"=r"(workWord3):"0"(workWord3),"m"(Level27_8057CField(argumentWord5,int*,8)):"memory");
argumentOrMathWord6Phase70=workWord3+-524;
workWord2=workWord2+64;
Level27_8057CField(argumentWord5,int*,8)=workWord2;
Level27_8057CField(workWord3,int*,0)=argumentWord7;
Level27_8057C_func_8004F1C8(argumentWord4,argumentWord5,argumentOrMathWord6Phase70);
workWord2=Level27_8057CGlobal70328_36;
workWord2=workWord2|32;
Level27_8057CGlobal70328_36=workWord2;
goto original_80080854;
original_80080778:
savedWord17=(int)&originalFrame.sp28;
argumentWord4=savedWord17+0;
__asm__ volatile(""::"r"(argumentWord4):"$16","memory");
savedWord16=(int)&Level27_8057C_D_80070328;
Level27_8057CKeep(savedWord16);
argumentWord5=savedWord16+0;
Level27_8057C_func_8004F178(argumentWord4,argumentWord5);
workWord2=Level27_8057C_rand();
workWord3=Level27_8057CField(&originalFrame.sp18,
        volatile int*,16);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,16)):"memory");workWord2=workWord2&127;
workWord3=workWord3+-64;
workWord3=workWord3+workWord2;
originalFrame.sp28=workWord3;
workWord2=Level27_8057C_rand();
workWord3=Level27_8057CField(&originalFrame.sp18,
        volatile int*,20);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,20)):"memory");workWord2=workWord2&127;
workWord3=workWord3+-64;
workWord3=workWord3+workWord2;
originalFrame.sp2C=workWord3;
workWord2=Level27_8057C_rand();
argumentWord4=(int)&originalFrame.sp18;
argumentWord5=savedWord16+152;
workWord3=Level27_8057CField(&originalFrame.sp18,
        volatile int*,24);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,24)):"memory");workWord2=workWord2&127;
workWord3=workWord3+-64;
workWord3=workWord3-workWord2;
originalFrame.sp30=workWord3;
Level27_8057C_func_8004F178(argumentWord4,argumentWord5);
argumentWord4=(int)&originalFrame.sp18;
argumentWord5=0+8;
Level27_8057C_func_8004F110(argumentWord4,argumentWord5);
workWord2=Level27_8057C_rand();
workWord3=Level27_8057CField(&originalFrame.sp18,
        volatile int*,0);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,0)):"memory");workWord2=workWord2&16;
workWord3=workWord3+-8;
workWord3=workWord3+workWord2;
originalFrame.sp18=workWord3;
workWord2=Level27_8057C_rand();
workWord3=Level27_8057CField(&originalFrame.sp18,
        volatile int*,4);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,4)):"memory");workWord2=workWord2&16;
workWord3=workWord3+-8;
workWord3=workWord3+workWord2;
originalFrame.sp1C=workWord3;
workWord2=Level27_8057C_rand();
argumentWord4=0+1;
argumentWord5=0+22;
argumentOrMathWord6Phase69=savedWord17+0;
argumentWord7=(int)&originalFrame.sp18;
__asm__ volatile("":"=r"(workWord2),"=r"(argumentWord4),"=r"(argumentWord5),"=r"(argumentOrMathWord6Phase69),"=r"(argumentWord7):"0"(workWord2),"1"(argumentWord4),"2"(argumentWord5),"3"(argumentOrMathWord6Phase69),"4"(argumentWord7):"memory");
workWord2=workWord2&7;
__asm__ volatile(""::"r"(workWord2):"$3","memory");
workWord3=(int)Level27_8057C_SpawnParticle;
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,4)):"memory");workWord2=workWord2+8;
originalFrame.sp20=workWord2;
workWord2=((int(*)(int,int,int,int))workWord3)(argumentWord4,argumentWord5,argumentOrMathWord6Phase69,argumentWord7);
original_80080854:
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
argumentWord4=Level27_8057CField(workWord24,int*,16);
argumentWord5=0+4;
Level27_8057C_func_80055D24(argumentWord4,argumentWord5);
argumentWord5=0+12;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,192)):"$18","memory");savedWord18=(int)&originalFrame.sp38;
argumentWord4=Level27_8057CField(workWord25,int*,16);
argumentOrMathWord6Phase68=savedWord18+0;
Level27_8057C_func_80055F14(argumentWord4,argumentWord5,argumentOrMathWord6Phase68);
argumentWord5=0+18;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,192)):"$16","memory");savedWord16=(int)&originalFrame.sp48;
argumentWord4=Level27_8057CField(workWord24,int*,16);
argumentOrMathWord6Phase67=savedWord16+0;
Level27_8057C_func_80055F14(argumentWord4,argumentWord5,argumentOrMathWord6Phase67);
argumentWord5=0+19;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,192)):"$17","memory");savedWord17=(int)&originalFrame.sp58;
argumentWord4=Level27_8057CField(workWord25,int*,16);
argumentOrMathWord6Phase66=savedWord17+0;
Level27_8057C_func_80055F14(argumentWord4,argumentWord5,argumentOrMathWord6Phase66);
argumentWord4=savedWord16+0;
argumentWord5=savedWord16+0;
argumentOrMathWord6Phase65=savedWord17+0;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase65);
argumentWord4=savedWord16+0;
argumentWord5=0+1;
Level27_8057C_func_8004F110(argumentWord4,argumentWord5);
argumentWord4=savedWord16+0;
argumentWord5=savedWord18+0;
argumentOrMathWord6Phase64=argumentWord4+0;
Level27_8057C_func_8004F1C8(argumentWord4,argumentWord5,argumentOrMathWord6Phase64);
savedWord16=(int)&originalFrame.sp68;
argumentWord4=savedWord16+0;
__asm__ volatile(""::"r"(argumentWord4):"$5","memory");
argumentWord5=(int)&Level27_8057C_D_80070328;
Level27_8057CKeep(argumentWord5);
argumentOrMathWord6Phase63=savedWord18+0;
Level27_8057C_func_8004F1C8(argumentWord4,argumentWord5,argumentOrMathWord6Phase63);
argumentWord4=savedWord16+0;
argumentWord5=0+0;
workWord2=Level27_8057C_func_8004EDE8(argumentWord4,argumentWord5);
workWord3=(int)0x84210000U;
Level27_8057CKeep(workWord3);
workWord3=workWord3|2115;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
__asm__("":"=r"(workWord2),"=r"(workWord3):"0"(workWord2),"1"(workWord3));
__asm__ volatile(""::"m"(originalFrame.spE0):"hi","lo","memory");
product0.full=(long long)workWord2*(long long)workWord3;
__asm__ volatile("":"=x"(product0.full):"0"(product0.full));
workWord25=workWord25+20;
originalFrame.sp100=workWord25;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
workWord25=workWord25+2332;
originalFrame.sp110=workWord25;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
workWord25=workWord25+5004;
originalFrame.sp120=workWord25;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
workWord25=workWord25+5884;
originalFrame.sp130=workWord25;
__asm__ volatile("":"=x"(product0.full):"0"(product0.full));
workWord24=(int)product0.words.high;
Level27_8057CKeep(workWord24);
workWord3=workWord24+workWord2;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
__asm__ volatile("":"=r"(workWord3):"0"(workWord3),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,200)):"memory");workWord3=(workWord3>>4);
workWord24=workWord24+1176;
originalFrame.sp108=workWord24;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,200)):"memory");workWord2=(workWord2>>31);
workWord24=workWord24+3848;
originalFrame.sp118=workWord24;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
__asm__ volatile("":"=r"(workWord3),"=r"(workWord2):"0"(workWord3),"1"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,200)):"memory");workWord3=workWord3-workWord2;
workWord24=workWord24+5136;
originalFrame.sp128=workWord24;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
__asm__ volatile("":"=r"(workWord3):"0"(workWord3),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,200)):"memory");workWord2=workWord3<641;
originalFrame.spF0=workWord3;
workWord24=workWord24+6632;
originalFrame.sp138=workWord24;
if(workWord2!=0)goto original_800809A0;
workWord25=0+640;
goto original_800809B4;
original_800809A0:
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,216);
workWord2=workWord24<8;
workWord25=0+8;
if(workWord2==0)goto original_800809B8;
original_800809B4:
originalFrame.spF0=workWord25;
original_800809B8:
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,192)):"$5","memory");argumentWord5=0+2;
argumentWord4=workWord24+20;
workWord2=Level27_8057C_func_800359A4(argumentWord4,argumentWord5);
argumentWord5=workWord2+0;
if(argumentWord5==0)goto original_80080A2C;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
workWord2=Level27_8057CField(workWord25,int*,12);
workWord2=workWord2+-3;
Level27_8057CField(workWord25,int*,12)=workWord2;
if(workWord2>0)goto original_80080A60;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
workWord2=Level27_8057CField(workWord24,unsigned char*,73);
if(workWord2==0?(workWord2=0+60,1):(workWord2=0+60,0))goto original_80080A18;
__asm__ volatile(""::"r"(workWord2));
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
Level27_8057CField(workWord25,short*,20)=workWord2;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
original_80080A18:
__asm__ volatile(""::"r"(workWord2));
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,184)):"$2","memory");workWord2=0+2;
Level27_8057CField(workWord24,unsigned char*,73)=workWord2;
workWord2=0+1;
Level27_8057CField(workWord24,unsigned char*,72)=workWord2;
goto original_80080A60;
original_80080A2C:
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
argumentWord4=Level27_8057CField(workWord25,short*,22);
__asm__ volatile(""::"r"(workWord25),"m"(Level27_8057CField(workWord25,short*,22)):"memory");
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,216);
workWord2=workWord24<argumentWord4;
workWord3=argumentWord4+0;
if(workWord2==0)goto original_80080A54;
workWord2=0+640;
goto original_80080A5C;
original_80080A54:
workWord2=workWord3+32;
originalFrame.spF0=argumentWord4;
original_80080A5C:
Level27_8057CField(workWord25,short*,22)=workWord2;
original_80080A60:
if(argumentWord5!=0)goto original_80080A84;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
workWord2=Level27_8057CField(workWord24,short*,22);
workWord2=workWord2<640;
if(workWord2!=0)goto original_80080A9C;
original_80080A84:
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,256);
workWord2=Level27_8057CField(workWord25,int*,44);
if(workWord2!=0)goto original_80080AB4;
original_80080A9C:
__asm__ volatile(""::"r"(workWord2):"$24","memory");
workWord24=0+1;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,200)):"$2","memory");workWord2=0+93;
originalFrame.spF8=workWord24;
Level27_8057CField(workWord25,int*,12)=workWord2;
goto original_80080AB8;
original_80080AB4:
originalFrame.spF8=0;
original_80080AB8:
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,48);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,52);
argumentOrMathWord6Phase62=0+0;
workWord2=Level27_8057C_func_8004E880(argumentWord4,argumentWord5,argumentOrMathWord6Phase62);
workWord2=workWord2+64;
savedWord21=workWord2&255;
argumentOrMathWord6Phase61=(int)((unsigned int)savedWord21<<1);
workWord3=Level27_8057C_D_8006C644;
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,52)):"$5","memory");argumentWord5=(int)&Level27_8057C_D_80065920;Level27_8057CKeep(argumentWord5);
workWord3=(int)((unsigned int)workWord3<<2);
Level27_8057CKeep(workWord3);
workWord3=workWord3&255;
originalFrame.sp140=workWord3;
workWord3=Level27_8057CField(((int)&Level27_8057C_D_80065920+argumentOrMathWord6Phase61),short*,0);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,296);
__asm__ volatile("":"=r"(workWord3):"0"(workWord3),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,296)):"memory");workWord2=(int)((unsigned int)workWord3<<2);
workWord2=workWord2+workWord3;
workWord3=(int)((unsigned int)workWord2<<4);
workWord3=workWord3-workWord2;
argumentWord4=(int)((unsigned int)workWord24<<3);
argumentWord4=argumentWord4&480;
argumentWord7=argumentWord4+argumentWord5;
Level27_8057CKeep(argumentWord7);
Level27_8057CKeep(argumentWord7);
workWord2=Level27_8057CField(argumentWord7,short*,0);
__asm__ volatile("":"=r"(workWord3):"0"(workWord3),"m"(Level27_8057CField(argumentWord7,short*,0)):"memory");
workWord3=(workWord3>>12);
__asm__("":"=r"(workWord3),"=r"(workWord2):"0"(workWord3),"1"(workWord2));
__asm__ volatile(""::"m"(originalFrame.sp140):"hi","lo","memory");
product1.full=(long long)workWord3*(long long)workWord2;
__asm__ volatile("":"=x"(product1.full):"0"(product1.full));
workWord8=(int)&Level27_8057C_D_800658A0;
Level27_8057CKeep(workWord8);
workWord9=argumentOrMathWord6Phase61+workWord8;
__asm__ volatile("":"=x"(product1.full):"0"(product1.full));
workWord25=(int)product1.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.sp78=workWord2;
workWord3=Level27_8057CField(workWord9,short*,0);
workWord2=(int)((unsigned int)workWord3<<2);
workWord2=workWord2+workWord3;
workWord3=(int)((unsigned int)workWord2<<4);
workWord3=workWord3-workWord2;
workWord2=Level27_8057CField(argumentWord7,short*,0);
__asm__ volatile("":"=r"(workWord3):"0"(workWord3),"m"(Level27_8057CField(argumentWord7,short*,0)):"memory");
workWord3=(workWord3>>12);
__asm__("":"=r"(workWord3),"=r"(workWord2):"0"(workWord3),"1"(workWord2));
__asm__ volatile(""::"m"(originalFrame.sp78):"hi","lo","memory");
product2.full=(long long)workWord3*(long long)workWord2;
__asm__ volatile("":"=x"(product2.full):"0"(product2.full));
savedWord19=0+0;
retainedWord30=(int)&originalFrame.sp78;
savedWord22=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
savedWord21=Level27_8057CField(&originalFrame.sp18,
        volatile int*,240);
savedWord20=Level27_8057CField(&originalFrame.sp18,
        volatile int*,232);
savedWord17=Level27_8057CField(&originalFrame.sp18,
        volatile int*,256);
__asm__ volatile("":"=r"(argumentWord4),"=r"(workWord8):"0"(argumentWord4),"1"(workWord8),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,256)):"memory");argumentWord4=argumentWord4+workWord8;
originalFrame.sp158=argumentOrMathWord6Phase61;
__asm__ volatile("":"=x"(product2.full):"0"(product2.full));
workWord24=(int)product2.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.sp7C=workWord2;
workWord2=Level27_8057CField(argumentWord4,short*,0);
__asm__ volatile(""::"m"(Level27_8057CField(argumentWord4,short*,0)):"$18","memory");
savedWord18=0+0;
originalFrame.sp160=workWord9;
workWord3=(int)((unsigned int)workWord2<<2);
workWord3=workWord3+workWord2;
workWord2=(int)((unsigned int)workWord3<<4);
workWord2=workWord2-workWord3;
workWord2=(workWord2>>12);
originalFrame.sp80=workWord2;
original_80080BB4:
workWord2=(int)0x55550000U;
Level27_8057CKeep(workWord2);
workWord2=workWord2|21846;
argumentWord7=(int)((unsigned int)savedWord19<<8);
__asm__("":"=r"(argumentWord7),"=r"(workWord2):"0"(argumentWord7),"1"(workWord2));
__asm__ volatile(""::"m"(originalFrame.sp80):"hi","lo","memory");
product3.full=(long long)argumentWord7*(long long)workWord2;
__asm__ volatile("":"=x"(product3.full):"0"(product3.full));
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
__asm__ volatile("":"=r"(argumentWord7):"0"(argumentWord7),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,184)):"memory");argumentWord7=(argumentWord7>>31);
workWord2=Level27_8057CField(workWord25,unsigned char*,68);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,320);
__asm__ volatile("":"=x"(product3.full):"0"(product3.full));
workWord24=(int)product3.words.high;
Level27_8057CKeep(workWord24);
argumentWord7=workWord24-argumentWord7;
argumentWord7=argumentWord7+workWord2;
__asm__ volatile("":"=r"(argumentWord7):"0"(argumentWord7):"memory");
workWord24=(int)&Level27_8057C_D_80065920;
Level27_8057CKeep(workWord24);
workWord2=workWord25+workWord24;
Level27_8057CKeep(workWord2);
argumentWord7=argumentWord7&255;
argumentWord7=(int)((unsigned int)argumentWord7<<1);
workWord3=Level27_8057CField(workWord2,short*,0);
__asm__ volatile("":"=r"(argumentWord7),"=r"(workWord24):"0"(argumentWord7),"1"(workWord24),"m"(Level27_8057CField(workWord2,short*,0)):"memory");
argumentWord4=argumentWord7+workWord24;
workWord2=(int)((unsigned int)workWord3<<1);
workWord2=workWord2+workWord3;
workWord2=(int)((unsigned int)workWord2<<3);
workWord2=workWord2+workWord3;
workWord3=Level27_8057CField(argumentWord4,short*,0);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(argumentWord4,short*,0)):"memory");
workWord2=(workWord2>>11);
__asm__("":"=r"(workWord2),"=r"(workWord3):"0"(workWord2),"1"(workWord3));
__asm__ volatile(""::"m"(originalFrame.sp158):"hi","lo","memory");
product4.full=(long long)workWord2*(long long)workWord3;
__asm__ volatile("":"=x"(product4.full):"0"(product4.full));
retainedWord23=(int)&originalFrame.sp88;
retainedWord23=Level27_8057CAt23(retainedWord23);
savedWord16=retainedWord23+savedWord18;
Level27_8057CKeep(savedWord16);
__asm__ volatile("":"=x"(product4.full):"0"(product4.full));
workWord25=(int)product4.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
Level27_8057CField(savedWord16,int*,0)=workWord2;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,328);
workWord3=Level27_8057CField(workWord24,short*,0);
workWord2=(int)((unsigned int)workWord3<<1);
workWord2=workWord2+workWord3;
workWord2=(int)((unsigned int)workWord2<<3);
workWord2=workWord2+workWord3;
workWord3=Level27_8057CField(argumentWord4,short*,0);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(argumentWord4,short*,0)):"memory");
workWord2=(workWord2>>11);
__asm__("":"=r"(workWord2),"=r"(workWord3):"0"(workWord2),"1"(workWord3));
__asm__ volatile(""::"m"(originalFrame.sp160):"hi","lo","memory");
product5.full=(long long)workWord2*(long long)workWord3;
__asm__ volatile("":"=x"(product5.full):"0"(product5.full));
argumentWord5=savedWord16+0;
argumentOrMathWord6Phase60=(int)&originalFrame.sp38;
Level27_8057CKeep(argumentOrMathWord6Phase60);
savedWord18=savedWord18+12;
savedWord19=savedWord19+1;
workWord24=(int)&Level27_8057C_D_800658A0;
Level27_8057CKeep(workWord24);
argumentWord7=argumentWord7+workWord24;
__asm__ volatile("":"=x"(product5.full):"0"(product5.full));
workWord25=(int)product5.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
Level27_8057CField(savedWord16,int*,4)=workWord2;
workWord3=Level27_8057CField(argumentWord7,short*,0);
__asm__ volatile("":"=r"(savedWord17):"0"(savedWord17),"m"(Level27_8057CField(argumentWord7,short*,0)):"memory");
argumentWord4=savedWord17+0;
workWord2=(int)((unsigned int)workWord3<<1);
workWord2=workWord2+workWord3;
workWord2=(int)((unsigned int)workWord2<<3);
workWord2=workWord2+workWord3;
workWord2=(workWord2>>11);
Level27_8057CField(savedWord16,int*,8)=workWord2;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase60);
argumentWord4=savedWord20+0;
argumentWord5=savedWord17+0;
argumentOrMathWord6Phase59=retainedWord30+0;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase59);
argumentWord4=savedWord21+0;
argumentWord5=savedWord17+0;
argumentOrMathWord6Phase58=retainedWord30+0;
Level27_8057C_func_8004F1C8(argumentWord4,argumentWord5,argumentOrMathWord6Phase58);
argumentWord4=savedWord16+0;
argumentWord5=0+2;
Level27_8057C_func_8004F0E8(argumentWord4,argumentWord5);
argumentWord4=savedWord22+0;
argumentWord5=savedWord17+0;
argumentOrMathWord6Phase57=savedWord16+0;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase57);
savedWord22=savedWord22+12;
savedWord21=savedWord21+12;
savedWord20=savedWord20+12;
workWord2=savedWord19<3;
savedWord17=savedWord17+12;
if(workWord2!=0)goto original_80080BB4;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,296);
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(originalFrame.sp140):"memory");
workWord25=workWord25+240;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25):"memory");
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,48);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,52);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,52)):"$6","memory");argumentOrMathWord6Phase56=0+1;
originalFrame.sp140=workWord25;
workWord2=Level27_8057C_func_8004E880(argumentWord4,argumentWord5,argumentOrMathWord6Phase56);
savedWord21=workWord2+0;
savedWord16=(int)&originalFrame.sp58;
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,256);
argumentWord4=savedWord16+0;
Level27_8057C_func_8004F178(argumentWord4,argumentWord5);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,224);
savedWord22=0+1;
if(workWord24==0)goto original_80081074;
workWord25=(int)&originalFrame.sp38;
originalFrame.sp170=retainedWord30;
retainedWord30=0+3;
originalFrame.sp168=workWord25;
originalFrame.sp178=retainedWord23;
original_80080D50:
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,336);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,208);
argumentOrMathWord6Phase55=(int)&originalFrame.sp58;
Level27_8057C_func_8004F1C8(argumentWord4,argumentWord5,argumentOrMathWord6Phase55);
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,32);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,36);
argumentOrMathWord6Phase54=0+1;
workWord2=Level27_8057C_func_8004E880(argumentWord4,argumentWord5,argumentOrMathWord6Phase54);
argumentWord4=savedWord21+0;
argumentWord5=workWord2+0;
workWord2=Level27_8057C_func_8003615C(argumentWord4,argumentWord5);
savedWord17=workWord2+0;
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,336);
argumentWord5=0+1;
workWord2=Level27_8057C_func_8004EDE8(argumentWord4,argumentWord5);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
workWord2=Level27_8057CField(workWord24,short*,20);
if(workWord2==0)goto original_80080DAC;
originalFrame.sp40=0;
goto original_80080DE0;
original_80080DAC:
workWord2=Level27_8057CField(&originalFrame.sp18,
        volatile int*,40);
__asm__("":"=r"(workWord2),"=r"(savedWord22):"0"(workWord2),"1"(savedWord22));
__asm__ volatile(""::"m"(originalFrame.sp40):"hi","lo","memory");
product6.full=(long long)workWord2*(long long)savedWord22;
__asm__ volatile("":"=x"(product6.full):"0"(product6.full));
__asm__ volatile("":"=x"(product6.full):"0"(product6.full));
workWord3=(int)product6.words.low;
Level27_8057CKeep(workWord3);
__asm__("":"=r"(workWord3),"=r"(savedWord22):"0"(workWord3),"1"(savedWord22));
__asm__ volatile(""::"m"(originalFrame.sp40):"hi","lo","memory");
product7.full=(long long)workWord3*(long long)savedWord22;
__asm__ volatile("":"=x"(product7.full):"0"(product7.full));
__asm__ volatile("":"=x"(product7.full):"0"(product7.full));
workWord2=(int)product7.words.low;
Level27_8057CKeep(workWord2);
if(workWord2>=0)goto original_80080DD8;
workWord2=workWord2+1023;
original_80080DD8:
workWord2=(workWord2>>10);
originalFrame.sp40=workWord2;
original_80080DE0:
workWord2=savedWord21+savedWord17;
savedWord21=workWord2&4095;
argumentWord4=savedWord21+0;
workWord2=Level27_8057C_func_8004EA2C(argumentWord4);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,216);
__asm__("":"=r"(workWord2),"=r"(workWord24):"0"(workWord2),"1"(workWord24));
__asm__ volatile(""::"m"(originalFrame.spF0):"hi","lo","memory");
product8.full=(long long)workWord2*(long long)workWord24;
__asm__ volatile("":"=x"(product8.full):"0"(product8.full));
argumentWord4=savedWord21+0;
__asm__ volatile("":"=x"(product8.full):"0"(product8.full));
workWord3=(int)product8.words.low;
Level27_8057CKeep(workWord3);
workWord2=(workWord3>>12);
originalFrame.sp38=workWord2;
workWord2=Level27_8057C_func_8004E9E4(argumentWord4);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,216);
__asm__("":"=r"(workWord2),"=r"(workWord24):"0"(workWord2),"1"(workWord24));
__asm__ volatile(""::"m"(originalFrame.spF0):"hi","lo","memory");
product9.full=(long long)workWord2*(long long)workWord24;
__asm__ volatile("":"=x"(product9.full):"0"(product9.full));
argumentWord4=(int)&originalFrame.sp58;
argumentWord5=argumentWord4+0;
argumentOrMathWord6Phase53=(int)&originalFrame.sp38;
Level27_8057CKeep(argumentOrMathWord6Phase53);
__asm__ volatile("":"=x"(product9.full):"0"(product9.full));
workWord3=(int)product9.words.low;
Level27_8057CKeep(workWord3);
workWord2=(workWord3>>12);
originalFrame.sp3C=workWord2;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase53);
argumentWord4=0+16;
workWord3=argumentWord4-savedWord22;
if(workWord3>=0)goto original_80080E4C;
workWord3=0-workWord3;
original_80080E4C:
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,296);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,296)):"$24","memory");workWord24=(int)&Level27_8057C_D_800658A0;Level27_8057CKeep(workWord24);
workWord2=workWord25&255;
workWord2=(int)((unsigned int)workWord2<<1);
workWord2=workWord2+workWord24;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
workWord2=Level27_8057CField(workWord2,unsigned short*,0);
__asm__ volatile("":"=r"(argumentWord4),"=r"(workWord3):"0"(argumentWord4),"1"(workWord3),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,296)):"memory");savedWord19=argumentWord4-workWord3;
workWord2=(int)((unsigned int)workWord2<<16);
workWord2=(workWord2>>18);
__asm__("":"=r"(workWord2),"=r"(savedWord19):"0"(workWord2),"1"(savedWord19));
__asm__ volatile(""::"m"(originalFrame.sp140):"hi","lo","memory");
product10.full=(long long)workWord2*(long long)savedWord19;
__asm__ volatile("":"=x"(product10.full):"0"(product10.full));
workWord2=savedWord21+512;
__asm__ volatile("":"=x"(product10.full):"0"(product10.full));
savedWord16=(int)product10.words.low;
Level27_8057CKeep(savedWord16);
savedWord17=workWord2&4095;
if(savedWord16>=0)goto original_80080E8C;
savedWord16=savedWord16+15;
original_80080E8C:
argumentWord4=savedWord17+0;
savedWord16=(savedWord16>>4);
workWord2=Level27_8057C_func_8004EA2C(argumentWord4);
__asm__("":"=r"(workWord2),"=r"(savedWord16):"0"(workWord2),"1"(savedWord16));
__asm__ volatile(""::"m"(originalFrame.sp140):"hi","lo","memory");
product11.full=(long long)workWord2*(long long)savedWord16;
__asm__ volatile("":"=x"(product11.full):"0"(product11.full));
argumentWord4=savedWord17+0;
__asm__ volatile("":"=x"(product11.full):"0"(product11.full));
workWord3=(int)product11.words.low;
Level27_8057CKeep(workWord3);
workWord2=(workWord3>>12);
originalFrame.sp68=workWord2;
workWord2=Level27_8057C_func_8004E9E4(argumentWord4);
__asm__("":"=r"(workWord2),"=r"(savedWord16):"0"(workWord2),"1"(savedWord16));
__asm__ volatile(""::"m"(originalFrame.sp68):"hi","lo","memory");
product12.full=(long long)workWord2*(long long)savedWord16;
__asm__ volatile("":"=x"(product12.full):"0"(product12.full));
workWord25=(int)&Level27_8057C_D_800658A0;
Level27_8057CKeep(workWord25);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,296);
__asm__ volatile("":"=x"(product12.full):"0"(product12.full));
workWord3=(int)product12.words.low;
Level27_8057CKeep(workWord3);
workWord2=(workWord3>>12);
originalFrame.sp6C=workWord2;
workWord2=(int)((unsigned int)workWord24<<1);
workWord2=workWord2+workWord24;
workWord2=workWord2&255;
workWord2=(int)((unsigned int)workWord2<<1);
workWord2=workWord2+workWord25;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
workWord2=Level27_8057CField(workWord2,unsigned short*,0);
workWord2=(int)((unsigned int)workWord2<<16);
workWord2=(workWord2>>20);
__asm__("":"=r"(workWord2),"=r"(savedWord19):"0"(workWord2),"1"(savedWord19));
__asm__ volatile(""::"m"(originalFrame.sp6C):"hi","lo","memory");
product13.full=(long long)workWord2*(long long)savedWord19;
__asm__ volatile("":"=x"(product13.full):"0"(product13.full));
__asm__ volatile("":"=x"(product13.full):"0"(product13.full));
workWord2=(int)product13.words.low;
Level27_8057CKeep(workWord2);
if(workWord2>=0)goto original_80080F04;
workWord2=workWord2+31;
original_80080F04:
workWord2=(workWord2>>5);
argumentWord4=(savedWord17>>4);
argumentWord4=(int)((unsigned int)argumentWord4<<1);
workWord24=(int)&Level27_8057C_D_80065920;
Level27_8057CKeep(workWord24);
originalFrame.sp70=workWord2;
workWord2=argumentWord4+workWord24;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
workWord3=Level27_8057CField(workWord2,short*,0);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,296);
__asm__ volatile("":"=r"(workWord3):"0"(workWord3),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,296)):"memory");workWord2=(int)((unsigned int)workWord3<<2);
workWord2=workWord2+workWord3;
workWord3=(int)((unsigned int)workWord2<<4);
workWord3=workWord3-workWord2;
argumentWord5=(int)((unsigned int)workWord25<<3);
argumentWord5=argumentWord5&504;
argumentOrMathWord6Phase52=argumentWord5+workWord24;
Level27_8057CKeep(argumentOrMathWord6Phase52);
Level27_8057CKeep(argumentOrMathWord6Phase52);
workWord2=Level27_8057CField(argumentOrMathWord6Phase52,short*,0);
__asm__ volatile("":"=r"(workWord3):"0"(workWord3),"m"(Level27_8057CField(argumentOrMathWord6Phase52,short*,0)):"memory");
workWord3=(workWord3>>12);
__asm__("":"=r"(workWord3),"=r"(workWord2):"0"(workWord3),"1"(workWord2));
__asm__ volatile(""::"m"(originalFrame.sp140):"hi","lo","memory");
product14.full=(long long)workWord3*(long long)workWord2;
__asm__ volatile("":"=x"(product14.full):"0"(product14.full));
workWord25=(int)&Level27_8057C_D_800658A0;
Level27_8057CKeep(workWord25);
argumentWord4=argumentWord4+workWord25;
__asm__ volatile("":"=x"(product14.full):"0"(product14.full));
workWord24=(int)product14.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.sp78=workWord2;
workWord3=Level27_8057CField(argumentWord4,short*,0);
workWord2=(int)((unsigned int)workWord3<<2);
workWord2=workWord2+workWord3;
workWord3=(int)((unsigned int)workWord2<<4);
workWord3=workWord3-workWord2;
workWord2=Level27_8057CField(argumentOrMathWord6Phase52,short*,0);
__asm__ volatile("":"=r"(workWord3):"0"(workWord3),"m"(Level27_8057CField(argumentOrMathWord6Phase52,short*,0)):"memory");
workWord3=(workWord3>>12);
__asm__("":"=r"(workWord3),"=r"(workWord2):"0"(workWord3),"1"(workWord2));
__asm__ volatile(""::"m"(originalFrame.sp78):"hi","lo","memory");
product15.full=(long long)workWord3*(long long)workWord2;
__asm__ volatile("":"=x"(product15.full):"0"(product15.full));
savedWord19=0+0;
retainedWord23=retainedWord30+0;
retainedWord23=Level27_8057CAt23(retainedWord23);
argumentWord5=argumentWord5+workWord25;
__asm__ volatile("":"=x"(product15.full):"0"(product15.full));
workWord24=(int)product15.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.sp7C=workWord2;
workWord2=Level27_8057CField(argumentWord5,short*,0);
savedWord20=Level27_8057CField(&originalFrame.sp18,
        volatile int*,352);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,352)):"memory");workWord3=(int)((unsigned int)workWord2<<2);
workWord3=workWord3+workWord2;
workWord2=(int)((unsigned int)workWord3<<4);
workWord2=workWord2-workWord3;
workWord2=(workWord2>>12);
originalFrame.sp80=workWord2;
original_80080FC4:
workWord2=retainedWord23+savedWord19;
savedWord16=(int)((unsigned int)workWord2<<1);
savedWord16=savedWord16+workWord2;
savedWord16=(int)((unsigned int)savedWord16<<2);
argumentWord5=savedWord16+-36;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,256);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,256)):"$6","memory");argumentOrMathWord6Phase51=(int)&originalFrame.sp38;Level27_8057CKeep(argumentOrMathWord6Phase51);
savedWord18=workWord25+savedWord16;
argumentWord4=savedWord18+0;
__asm__ volatile("":"=r"(argumentWord5):"0"(argumentWord5),"r"(argumentWord4),"r"(argumentOrMathWord6Phase51):"memory");
argumentWord5=workWord25+argumentWord5;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase51);
argumentWord5=savedWord18+0;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,232);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,232)):"$6","memory");argumentOrMathWord6Phase50=(int)&originalFrame.sp68;Level27_8057CKeep(argumentOrMathWord6Phase50);
savedWord17=workWord24+savedWord16;
argumentWord4=savedWord17+0;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase50);
argumentWord5=savedWord17+0;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,240);
argumentOrMathWord6Phase49=Level27_8057CField(&originalFrame.sp18,
        volatile int*,344);Level27_8057CKeep(argumentOrMathWord6Phase49);
argumentWord4=workWord25+savedWord16;
Level27_8057C_func_8004F1C8(argumentWord4,argumentWord5,argumentOrMathWord6Phase49);
argumentWord5=savedWord17+0;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
__asm__ volatile("":"=r"(savedWord20):"0"(savedWord20),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,248)):"memory");argumentOrMathWord6Phase48=savedWord20+0;
argumentWord4=workWord24+savedWord16;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase48);
argumentWord4=savedWord17+0;
argumentOrMathWord6Phase47=Level27_8057CField(&originalFrame.sp18,
        volatile int*,344);Level27_8057CKeep(argumentOrMathWord6Phase47);
argumentWord5=argumentWord4+0;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase47);
savedWord19=savedWord19+1;
workWord2=savedWord19<3;
savedWord20=savedWord20+12;
if(workWord2!=0)goto original_80080FC4;
retainedWord30=retainedWord30+3;
savedWord22=savedWord22+1;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,296);
__asm__ volatile("":"=r"(savedWord22):"0"(savedWord22),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,296)):"memory");workWord2=savedWord22<31;
workWord25=workWord25+240;
originalFrame.sp140=workWord25;
if(workWord2!=0)goto original_80080D50;
savedWord17=(int)&originalFrame.sp38;
goto original_800813E4;
original_80081074:
retainedWord23=(int)&originalFrame.sp38;
retainedWord23=Level27_8057CAt23(retainedWord23);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,256);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,256)):"$24","memory");workWord24=0+3;
originalFrame.sp180=savedWord16;
originalFrame.sp188=retainedWord30;
originalFrame.sp1D0=workWord24;
workWord25=workWord25+36;
originalFrame.sp1D8=workWord25;
original_80081094:
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,208);
argumentOrMathWord6Phase46=Level27_8057CField(&originalFrame.sp18,
        volatile int*,360);Level27_8057CKeep(argumentOrMathWord6Phase46);
argumentWord4=retainedWord23+0;
Level27_8057C_func_8004F1C8(argumentWord4,argumentWord5,argumentOrMathWord6Phase46);
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,32);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,36);
argumentOrMathWord6Phase45=0+1;
workWord2=Level27_8057C_func_8004E880(argumentWord4,argumentWord5,argumentOrMathWord6Phase45);
argumentWord4=savedWord21+0;
argumentWord5=workWord2+0;
workWord2=Level27_8057C_func_8003615C(argumentWord4,argumentWord5);
savedWord17=workWord2+0;
argumentWord4=retainedWord23+0;
argumentWord5=0+1;
workWord2=Level27_8057C_func_8004EDE8(argumentWord4,argumentWord5);
workWord2=Level27_8057CField(&originalFrame.sp18,
        volatile int*,40);
__asm__("":"=r"(workWord2),"=r"(savedWord22):"0"(workWord2),"1"(savedWord22));
__asm__ volatile(""::"m"(originalFrame.sp40):"hi","lo","memory");
product16.full=(long long)workWord2*(long long)savedWord22;
__asm__ volatile("":"=x"(product16.full):"0"(product16.full));
__asm__ volatile("":"=x"(product16.full):"0"(product16.full));
workWord3=(int)product16.words.low;
Level27_8057CKeep(workWord3);
__asm__("":"=r"(workWord3),"=r"(savedWord22):"0"(workWord3),"1"(savedWord22));
__asm__ volatile(""::"m"(originalFrame.sp40):"hi","lo","memory");
product17.full=(long long)workWord3*(long long)savedWord22;
__asm__ volatile("":"=x"(product17.full):"0"(product17.full));
__asm__ volatile("":"=x"(product17.full):"0"(product17.full));
workWord3=(int)product17.words.low;
Level27_8057CKeep(workWord3);
workWord2=savedWord21+savedWord17;
if(workWord3>=0)goto original_800810FC;
workWord3=workWord3+1023;
original_800810FC:
savedWord21=workWord2&4095;
argumentWord4=savedWord21+0;
workWord2=(workWord3>>10);
originalFrame.sp40=workWord2;
workWord2=Level27_8057C_func_8004EA2C(argumentWord4);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,216);
__asm__("":"=r"(workWord2),"=r"(workWord24):"0"(workWord2),"1"(workWord24));
__asm__ volatile(""::"m"(originalFrame.spF0):"hi","lo","memory");
product18.full=(long long)workWord2*(long long)workWord24;
__asm__ volatile("":"=x"(product18.full):"0"(product18.full));
argumentWord4=savedWord21+0;
__asm__ volatile("":"=x"(product18.full):"0"(product18.full));
workWord25=(int)product18.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.sp38=workWord2;
workWord2=Level27_8057C_func_8004E9E4(argumentWord4);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,216);
__asm__("":"=r"(workWord2),"=r"(workWord24):"0"(workWord2),"1"(workWord24));
__asm__ volatile(""::"m"(originalFrame.spF0):"hi","lo","memory");
product19.full=(long long)workWord2*(long long)workWord24;
__asm__ volatile("":"=x"(product19.full):"0"(product19.full));
argumentOrMathWord6Phase44=retainedWord23+0;
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,360);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,360);
__asm__ volatile("":"=x"(product19.full):"0"(product19.full));
workWord25=(int)product19.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.sp3C=workWord2;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase44);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,360);
argumentOrMathWord6Phase43=Level27_8057CField(&originalFrame.sp18,
        volatile int*,448);Level27_8057CKeep(argumentOrMathWord6Phase43);
argumentWord4=retainedWord23+0;
Level27_8057C_func_8004F1C8(argumentWord4,argumentWord5,argumentOrMathWord6Phase43);
argumentWord4=retainedWord23+0;
argumentWord5=0+1;
workWord2=Level27_8057C_func_8004EDE8(argumentWord4,argumentWord5);
savedWord16=workWord2+0;
workWord2=savedWord16<201;
argumentWord4=retainedWord23+0;
if(workWord2!=0)goto original_80081198;
argumentWord5=savedWord16+0;
argumentOrMathWord6Phase42=0+200;
Level27_8057C_func_8004F08C(argumentWord4,argumentWord5,argumentOrMathWord6Phase42);
argumentWord4=0+16;
goto original_800811A4;
original_80081198:
argumentWord5=0+3;
Level27_8057C_func_8004F110(argumentWord4,argumentWord5);
argumentWord4=0+16;
original_800811A4:
workWord3=argumentWord4-savedWord22;
if(workWord3>=0)goto original_800811B4;
workWord3=0-workWord3;
original_800811B4:
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,296);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,296)):"$25","memory");workWord25=(int)&Level27_8057C_D_800658A0;Level27_8057CKeep(workWord25);
savedWord18=(int)((unsigned int)workWord24<<1);
workWord2=savedWord18+workWord25;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
workWord2=Level27_8057CField(workWord2,unsigned short*,0);
__asm__ volatile("":"=r"(argumentWord4),"=r"(workWord3):"0"(argumentWord4),"1"(workWord3),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,296)):"memory");savedWord19=argumentWord4-workWord3;
workWord2=(int)((unsigned int)workWord2<<16);
workWord2=(workWord2>>18);
__asm__("":"=r"(workWord2),"=r"(savedWord19):"0"(workWord2),"1"(savedWord19));
__asm__ volatile(""::"m"(originalFrame.sp140):"hi","lo","memory");
product20.full=(long long)workWord2*(long long)savedWord19;
__asm__ volatile("":"=x"(product20.full):"0"(product20.full));
workWord2=savedWord21+512;
__asm__ volatile("":"=x"(product20.full):"0"(product20.full));
argumentWord5=(int)product20.words.low;
Level27_8057CKeep(argumentWord5);
savedWord17=workWord2&4095;
if(argumentWord5>=0)goto original_800811F0;
argumentWord5=argumentWord5+15;
original_800811F0:
savedWord16=(argumentWord5>>4);
argumentWord4=savedWord17+0;
workWord2=Level27_8057C_func_8004EA2C(argumentWord4);
__asm__("":"=r"(workWord2),"=r"(savedWord16):"0"(workWord2),"1"(savedWord16));
__asm__ volatile(""::"m"(originalFrame.sp140):"hi","lo","memory");
product21.full=(long long)workWord2*(long long)savedWord16;
__asm__ volatile("":"=x"(product21.full):"0"(product21.full));
argumentWord4=savedWord17+0;
__asm__ volatile("":"=x"(product21.full):"0"(product21.full));
workWord3=(int)product21.words.low;
Level27_8057CKeep(workWord3);
workWord2=(workWord3>>12);
originalFrame.sp68=workWord2;
workWord2=Level27_8057C_func_8004E9E4(argumentWord4);
__asm__("":"=r"(workWord2),"=r"(savedWord16):"0"(workWord2),"1"(savedWord16));
__asm__ volatile(""::"m"(originalFrame.sp68):"hi","lo","memory");
product22.full=(long long)workWord2*(long long)savedWord16;
__asm__ volatile("":"=x"(product22.full):"0"(product22.full));
workWord25=(int)&Level27_8057C_D_800658A0;
Level27_8057CKeep(workWord25);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,296);
__asm__ volatile("":"=x"(product22.full):"0"(product22.full));
workWord3=(int)product22.words.low;
Level27_8057CKeep(workWord3);
workWord2=(workWord3>>12);
originalFrame.sp6C=workWord2;
workWord2=savedWord18+workWord24;
workWord2=workWord2&255;
workWord2=(int)((unsigned int)workWord2<<1);
workWord2=workWord2+workWord25;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
workWord2=Level27_8057CField(workWord2,unsigned short*,0);
workWord2=(int)((unsigned int)workWord2<<16);
workWord2=(workWord2>>20);
__asm__("":"=r"(workWord2),"=r"(savedWord19):"0"(workWord2),"1"(savedWord19));
__asm__ volatile(""::"m"(originalFrame.sp6C):"hi","lo","memory");
product23.full=(long long)workWord2*(long long)savedWord19;
__asm__ volatile("":"=x"(product23.full):"0"(product23.full));
__asm__ volatile("":"=x"(product23.full):"0"(product23.full));
workWord2=(int)product23.words.low;
Level27_8057CKeep(workWord2);
if(workWord2>=0)goto original_80081264;
workWord2=workWord2+31;
original_80081264:
workWord2=(workWord2>>5);
argumentWord4=(savedWord17>>4);
argumentWord4=(int)((unsigned int)argumentWord4<<1);
workWord24=(int)&Level27_8057C_D_80065920;
Level27_8057CKeep(workWord24);
originalFrame.sp70=workWord2;
workWord2=argumentWord4+workWord24;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
workWord3=Level27_8057CField(workWord2,short*,0);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,296);
__asm__ volatile("":"=r"(workWord3):"0"(workWord3),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,296)):"memory");workWord2=(int)((unsigned int)workWord3<<2);
workWord2=workWord2+workWord3;
workWord3=(int)((unsigned int)workWord2<<4);
workWord3=workWord3-workWord2;
argumentWord5=(int)((unsigned int)workWord25<<3);
argumentWord5=argumentWord5&504;
argumentOrMathWord6Phase41=argumentWord5+workWord24;
Level27_8057CKeep(argumentOrMathWord6Phase41);
Level27_8057CKeep(argumentOrMathWord6Phase41);
workWord2=Level27_8057CField(argumentOrMathWord6Phase41,short*,0);
__asm__ volatile("":"=r"(workWord3):"0"(workWord3),"m"(Level27_8057CField(argumentOrMathWord6Phase41,short*,0)):"memory");
workWord3=(workWord3>>12);
__asm__("":"=r"(workWord3),"=r"(workWord2):"0"(workWord3),"1"(workWord2));
__asm__ volatile(""::"m"(originalFrame.sp140):"hi","lo","memory");
product24.full=(long long)workWord3*(long long)workWord2;
__asm__ volatile("":"=x"(product24.full):"0"(product24.full));
workWord25=(int)&Level27_8057C_D_800658A0;
Level27_8057CKeep(workWord25);
argumentWord4=argumentWord4+workWord25;
__asm__ volatile("":"=x"(product24.full):"0"(product24.full));
workWord24=(int)product24.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.sp78=workWord2;
workWord3=Level27_8057CField(argumentWord4,short*,0);
workWord2=(int)((unsigned int)workWord3<<2);
workWord2=workWord2+workWord3;
workWord3=(int)((unsigned int)workWord2<<4);
workWord3=workWord3-workWord2;
workWord2=Level27_8057CField(argumentOrMathWord6Phase41,short*,0);
__asm__ volatile("":"=r"(workWord3):"0"(workWord3),"m"(Level27_8057CField(argumentOrMathWord6Phase41,short*,0)):"memory");
workWord3=(workWord3>>12);
__asm__("":"=r"(workWord3),"=r"(workWord2):"0"(workWord3),"1"(workWord2));
__asm__ volatile(""::"m"(originalFrame.sp78):"hi","lo","memory");
product25.full=(long long)workWord3*(long long)workWord2;
__asm__ volatile("":"=x"(product25.full):"0"(product25.full));
savedWord19=0+0;
savedWord20=(int)&originalFrame.sp88;
argumentWord5=argumentWord5+workWord25;
__asm__ volatile("":"=x"(product25.full):"0"(product25.full));
workWord24=(int)product25.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.sp7C=workWord2;
workWord2=Level27_8057CField(argumentWord5,short*,0);
retainedWord30=Level27_8057CField(&originalFrame.sp18,
        volatile int*,440);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,440)):"memory");workWord3=(int)((unsigned int)workWord2<<2);
workWord3=workWord3+workWord2;
workWord2=(int)((unsigned int)workWord3<<4);
workWord2=workWord2-workWord3;
workWord2=(workWord2>>12);
originalFrame.sp80=workWord2;
original_80081324:
workWord2=retainedWord30+savedWord19;
savedWord16=(int)((unsigned int)workWord2<<1);
savedWord16=savedWord16+workWord2;
savedWord16=(int)((unsigned int)savedWord16<<2);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,256);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,256)):"$6","memory");argumentOrMathWord6Phase40=(int)&originalFrame.sp38;Level27_8057CKeep(argumentOrMathWord6Phase40);
savedWord17=workWord25+savedWord16;
argumentWord4=savedWord17+0;
argumentWord5=savedWord17+0;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase40);
argumentWord5=savedWord17+0;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,232);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,232)):"$6","memory");argumentOrMathWord6Phase39=(int)&originalFrame.sp68;Level27_8057CKeep(argumentOrMathWord6Phase39);
savedWord18=workWord24+savedWord16;
argumentWord4=savedWord18+0;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase39);
argumentWord5=savedWord18+0;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,240);
argumentOrMathWord6Phase38=Level27_8057CField(&originalFrame.sp18,
        volatile int*,368);Level27_8057CKeep(argumentOrMathWord6Phase38);
argumentWord4=workWord25+savedWord16;
Level27_8057C_func_8004F1C8(argumentWord4,argumentWord5,argumentOrMathWord6Phase38);
argumentWord5=savedWord18+0;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
__asm__ volatile("":"=r"(savedWord20):"0"(savedWord20),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,248)):"memory");argumentOrMathWord6Phase37=savedWord20+0;
argumentWord4=workWord24+savedWord16;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase37);
argumentWord4=savedWord18+0;
argumentOrMathWord6Phase36=Level27_8057CField(&originalFrame.sp18,
        volatile int*,368);Level27_8057CKeep(argumentOrMathWord6Phase36);
argumentWord5=argumentWord4+0;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase36);
savedWord19=savedWord19+1;
workWord2=savedWord19<3;
savedWord20=savedWord20+12;
if(workWord2!=0)goto original_80081324;
savedWord22=savedWord22+1;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,296);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,440);
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,440)):"memory");workWord2=workWord25+240;
workWord2=workWord2&255;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,448);
__asm__ volatile("":"=r"(workWord24):"0"(workWord24),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,448)):"memory");workWord24=workWord24+3;
originalFrame.sp140=workWord2;
workWord2=savedWord22<31;
originalFrame.sp1D0=workWord24;
workWord25=workWord25+36;
originalFrame.sp1D8=workWord25;
if(workWord2!=0)goto original_80081094;
savedWord17=(int)&originalFrame.sp38;
original_800813E4:
argumentWord4=savedWord17+0;
savedWord18=(int)&originalFrame.sp58;
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,208);
argumentOrMathWord6Phase35=savedWord18+0;
Level27_8057C_func_8004F1C8(argumentWord4,argumentWord5,argumentOrMathWord6Phase35);
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,32);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,36);
argumentOrMathWord6Phase34=0+1;
workWord2=Level27_8057C_func_8004E880(argumentWord4,argumentWord5,argumentOrMathWord6Phase34);
argumentWord4=savedWord21+0;
argumentWord5=workWord2+0;
workWord2=Level27_8057C_func_8003615C(argumentWord4,argumentWord5);
savedWord16=workWord2+0;
argumentWord4=savedWord17+0;
argumentWord5=0+1;
workWord2=Level27_8057C_func_8004EDE8(argumentWord4,argumentWord5);
savedWord16=(savedWord16>>2);
savedWord16=savedWord21+savedWord16;
savedWord21=savedWord16&4095;
argumentWord4=savedWord21+0;
workWord2=Level27_8057C_func_8004EA2C(argumentWord4);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,216);
__asm__("":"=r"(workWord2),"=r"(workWord24):"0"(workWord2),"1"(workWord24));
__asm__ volatile(""::"m"(originalFrame.spF0):"hi","lo","memory");
product26.full=(long long)workWord2*(long long)workWord24;
__asm__ volatile("":"=x"(product26.full):"0"(product26.full));
argumentWord4=savedWord21+0;
__asm__ volatile("":"=x"(product26.full):"0"(product26.full));
workWord25=(int)product26.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.sp38=workWord2;
workWord2=Level27_8057C_func_8004E9E4(argumentWord4);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,216);
__asm__("":"=r"(workWord2),"=r"(workWord24):"0"(workWord2),"1"(workWord24));
__asm__ volatile(""::"m"(originalFrame.spF0):"hi","lo","memory");
product27.full=(long long)workWord2*(long long)workWord24;
__asm__ volatile("":"=x"(product27.full):"0"(product27.full));
savedWord22=0+31;
argumentWord4=savedWord18+0;
argumentWord5=savedWord18+0;
argumentOrMathWord6Phase33=savedWord17+0;
savedWord16=0+93;
originalFrame.sp40=0;
__asm__ volatile("":"=x"(product27.full):"0"(product27.full));
workWord25=(int)product27.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.sp3C=workWord2;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase33);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,224);
argumentWord4=savedWord17+0;
if(workWord24!=0)goto original_80081548;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,256);
__asm__ volatile("":"=r"(savedWord18):"0"(savedWord18),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,256)):"memory");argumentWord5=savedWord18+0;
argumentOrMathWord6Phase32=workWord25+1116;
Level27_8057C_func_8004F1C8(argumentWord4,argumentWord5,argumentOrMathWord6Phase32);
argumentWord4=savedWord17+0;
argumentWord5=0+1;
workWord2=Level27_8057C_func_8004EDE8(argumentWord4,argumentWord5);
argumentWord5=workWord2+0;
workWord2=argumentWord5<201;
argumentWord4=savedWord17+0;
if(workWord2!=0)goto original_800814D8;
argumentOrMathWord6Phase31=0+200;
Level27_8057C_func_8004F08C(argumentWord4,argumentWord5,argumentOrMathWord6Phase31);
argumentWord4=(int)&originalFrame.sp38;
goto original_800814E4;
original_800814D8:
argumentWord5=0+3;
Level27_8057C_func_8004F110(argumentWord4,argumentWord5);
argumentWord4=(int)&originalFrame.sp38;
original_800814E4:
argumentWord5=(int)((unsigned int)savedWord16<<1);
argumentWord5=argumentWord5+savedWord16;
argumentWord5=(int)((unsigned int)argumentWord5<<2);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,256);
__asm__ volatile("":"=r"(argumentWord4):"0"(argumentWord4),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,256)):"memory");argumentOrMathWord6Phase30=argumentWord4+0;
argumentWord5=workWord24+argumentWord5;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase30);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
workWord2=Level27_8057CField(workWord25,unsigned char*,73);
if(workWord2==0)goto original_8008152C;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,208);
workWord2=Level27_8057CField(workWord24,int*,8);
originalFrame.sp40=workWord2;
goto original_80081550;
original_8008152C:
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
workWord2=Level27_8057CField(workWord25,int*,16);
workWord2=Level27_8057CField(workWord2,int*,20);
originalFrame.sp40=workWord2;
goto original_80081550;
original_80081548:
argumentWord5=savedWord18+0;
Level27_8057C_func_8004F178(argumentWord4,argumentWord5);
original_80081550:
savedWord19=0+0;
Level27_8057CKeep(savedWord19);
workWord2=(int)((unsigned int)savedWord22<<1);
savedWord18=workWord2+savedWord22;
savedWord17=(int)&originalFrame.sp38;
workWord2=savedWord18+savedWord19;
original_80081564:
savedWord16=(int)((unsigned int)workWord2<<1);
savedWord16=savedWord16+workWord2;
savedWord16=(int)((unsigned int)savedWord16<<2);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,256);
__asm__ volatile("":"=r"(savedWord17):"0"(savedWord17),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,256)):"memory");argumentWord5=savedWord17+0;
argumentWord4=workWord24+savedWord16;
Level27_8057C_func_8004F178(argumentWord4,argumentWord5);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,232);
__asm__ volatile("":"=r"(savedWord17):"0"(savedWord17),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,232)):"memory");argumentWord5=savedWord17+0;
argumentWord4=workWord25+savedWord16;
Level27_8057C_func_8004F178(argumentWord4,argumentWord5);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,240);
__asm__ volatile("":"=r"(savedWord17):"0"(savedWord17),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,240)):"memory");argumentWord5=savedWord17+0;
argumentWord4=workWord24+savedWord16;
Level27_8057C_func_8004F178(argumentWord4,argumentWord5);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
__asm__ volatile("":"=r"(savedWord17):"0"(savedWord17),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,248)):"memory");argumentWord5=savedWord17+0;
argumentWord4=workWord25+savedWord16;
Level27_8057C_func_8004F178(argumentWord4,argumentWord5);
savedWord19=savedWord19+1;
workWord2=savedWord19<3;
if(workWord2!=0?(workWord2=savedWord18+savedWord19,1):(workWord2=savedWord18+savedWord19,0))goto original_80081564;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
__asm__ volatile("":"=r"(savedWord17):"0"(savedWord17),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,184)):"memory");argumentWord5=savedWord17+0;
argumentWord4=workWord24+12;
Level27_8057C_func_8004F178(argumentWord4,argumentWord5);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
workWord2=Level27_8057CField(workWord25,unsigned char*,73);
if(workWord2==0)goto original_80081D68;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
workWord2=Level27_8057CField(workWord24,short*,20);
if(workWord2==0)goto original_80081D68;
workWord2=Level27_8057CField(workWord25,unsigned char*,72);
workWord25=(int)&originalFrame.spB0;
if(workWord2!=0)goto original_80081D68;
savedWord17=(int)&Level27_8057C_D_8006E020;
Level27_8057CKeep(savedWord17);
argumentWord5=savedWord17+0;
savedWord16=(int)&Level27_8057C_D_80070328;
Level27_8057CKeep(savedWord16);
originalFrame.sp1A0=workWord25;
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,392);
argumentOrMathWord6Phase29=savedWord16+0;
Level27_8057C_func_8004F1C8(argumentWord4,argumentWord5,argumentOrMathWord6Phase29);
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,152);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,156);
argumentOrMathWord6Phase28=0+0;
workWord2=Level27_8057C_func_8004E880(argumentWord4,argumentWord5,argumentOrMathWord6Phase28);
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,392);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,392)):"$5","memory");argumentWord5=0+0;
originalFrame.sp190=workWord2;
workWord2=Level27_8057C_func_8004EDE8(argumentWord4,argumentWord5);
argumentWord4=workWord2+0;
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,160);
argumentOrMathWord6Phase27=0+0;
workWord2=Level27_8057C_func_8004E880(argumentWord4,argumentWord5,argumentOrMathWord6Phase27);
argumentWord5=savedWord16+0;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,248)):"$3","memory");workWord3=Level27_8057C_D_8006C640;
__asm__ volatile("":"=r"(savedWord17):"0"(savedWord17),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,248)):"memory");argumentOrMathWord6Phase26=savedWord17+0;
originalFrame.sp198=workWord2;
workWord24=workWord24+1152;
workWord3=(int)((unsigned int)workWord3<<4);
originalFrame.sp1A8=workWord24;
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,400);
retainedWord30=workWord3&255;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase26);
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,400);
argumentWord5=0+1;
Level27_8057C_func_8004F110(argumentWord4,argumentWord5);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
workWord2=Level27_8057CField(workWord25,int*,1160);
__asm__ volatile(""::"m"(Level27_8057CField(workWord25,int*,1160)):"$19","memory");
savedWord19=(int)&Level27_8057C_D_80065920;
Level27_8057CKeep(savedWord19);
workWord2=workWord2+64;
Level27_8057CField(workWord25,int*,1160)=workWord2;
workWord2=(int)((unsigned int)retainedWord30<<1);
workWord2=Level27_8057CField(((int)&Level27_8057C_D_800658A0+workWord2),unsigned short*,0);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,376);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,376)):"memory");workWord2=(int)((unsigned int)workWord2<<16);
workWord2=(workWord2>>22);
savedWord21=workWord24&255;
savedWord21=(int)((unsigned int)savedWord21<<1);
workWord25=savedWord21+savedWord19;
Level27_8057CKeep(workWord25);
originalFrame.sp1B8=workWord25;
workWord3=Level27_8057CField(workWord25,short*,0);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(workWord25,short*,0)):"memory");
argumentOrMathWord6Phase25=workWord2+448;
__asm__("":"=r"(workWord3),"=r"(argumentOrMathWord6Phase25):"0"(workWord3),"1"(argumentOrMathWord6Phase25));
__asm__ volatile(""::"m"(originalFrame.sp1B8):"hi","lo","memory");
product28.full=(long long)workWord3*(long long)argumentOrMathWord6Phase25;
__asm__ volatile("":"=x"(product28.full):"0"(product28.full));
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,384);
workWord3=workWord24+32;
workWord3=workWord3&255;
workWord3=(int)((unsigned int)workWord3<<1);
argumentWord5=workWord3+savedWord19;
Level27_8057CKeep(argumentWord5);
__asm__ volatile("":"=x"(product28.full):"0"(product28.full));
workWord25=(int)product28.words.low;
Level27_8057CKeep(workWord25);
argumentWord4=Level27_8057CField(argumentWord5,short*,0);
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(argumentWord5,short*,0)):"memory");
workWord2=(workWord25>>12);
__asm__("":"=r"(workWord2),"=r"(argumentWord4):"0"(workWord2),"1"(argumentWord4));
__asm__ volatile(""::"m"(originalFrame.sp198):"hi","lo","memory");
product29.full=(long long)workWord2*(long long)argumentWord4;
__asm__ volatile("":"=x"(product29.full):"0"(product29.full));
savedWord18=(int)&Level27_8057C_D_800658A0;
Level27_8057CKeep(savedWord18);
savedWord21=savedWord21+savedWord18;
__asm__ volatile("":"=x"(product29.full):"0"(product29.full));
workWord24=(int)product29.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.spB0=workWord2;
workWord2=Level27_8057CField(savedWord21,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase25):"0"(workWord2),"1"(argumentOrMathWord6Phase25));
__asm__ volatile(""::"m"(originalFrame.spB0):"hi","lo","memory");
product30.full=(long long)workWord2*(long long)argumentOrMathWord6Phase25;
__asm__ volatile("":"=x"(product30.full):"0"(product30.full));
__asm__ volatile("":"=x"(product30.full):"0"(product30.full));
workWord25=(int)product30.words.low;
Level27_8057CKeep(workWord25);
argumentWord4=Level27_8057CField(argumentWord5,short*,0);
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(argumentWord5,short*,0)):"memory");
workWord2=(workWord25>>12);
__asm__("":"=r"(workWord2),"=r"(argumentWord4):"0"(workWord2),"1"(argumentWord4));
__asm__ volatile(""::"m"(originalFrame.spB0):"hi","lo","memory");
product31.full=(long long)workWord2*(long long)argumentWord4;
__asm__ volatile("":"=x"(product31.full):"0"(product31.full));
workWord3=workWord3+savedWord18;
__asm__ volatile("":"=x"(product31.full):"0"(product31.full));
workWord24=(int)product31.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.spB4=workWord2;
workWord2=Level27_8057CField(workWord3,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase25):"0"(workWord2),"1"(argumentOrMathWord6Phase25));
__asm__ volatile(""::"m"(originalFrame.spB4):"hi","lo","memory");
product32.full=(long long)workWord2*(long long)argumentOrMathWord6Phase25;
__asm__ volatile("":"=x"(product32.full):"0"(product32.full));
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,400);
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,400)):"memory");argumentWord4=workWord25+1164;
argumentOrMathWord6Phase24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,392);Level27_8057CKeep(argumentOrMathWord6Phase24);
__asm__ volatile("":"=x"(product32.full):"0"(product32.full));
workWord24=(int)product32.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.spB8=workWord2;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase24);
workWord2=retainedWord30+47;
retainedWord30=workWord2&255;
workWord2=(int)((unsigned int)retainedWord30<<1);
workWord2=workWord2+savedWord18;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
workWord2=Level27_8057CField(workWord2,unsigned short*,0);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,376);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,376)):"memory");workWord2=(int)((unsigned int)workWord2<<16);
workWord2=(workWord2>>22);
savedWord17=workWord25+16;
savedWord17=savedWord17&255;
savedWord17=(int)((unsigned int)savedWord17<<1);
savedWord16=savedWord17+savedWord19;
Level27_8057CKeep(savedWord16);
Level27_8057CKeep(savedWord16);
workWord3=Level27_8057CField(savedWord16,short*,0);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(savedWord16,short*,0)):"memory");
argumentOrMathWord6Phase23=workWord2+448;
__asm__("":"=r"(workWord3),"=r"(argumentOrMathWord6Phase23):"0"(workWord3),"1"(argumentOrMathWord6Phase23));
__asm__ volatile(""::"m"(originalFrame.sp190):"hi","lo","memory");
product33.full=(long long)workWord3*(long long)argumentOrMathWord6Phase23;
__asm__ volatile("":"=x"(product33.full):"0"(product33.full));
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,384);
savedWord22=workWord24+16;
savedWord22=savedWord22&255;
savedWord22=(int)((unsigned int)savedWord22<<1);
workWord25=savedWord22+savedWord19;
Level27_8057CKeep(workWord25);
originalFrame.sp1C0=workWord25;
__asm__ volatile("":"=x"(product33.full):"0"(product33.full));
workWord24=(int)product33.words.low;
Level27_8057CKeep(workWord24);
workWord3=Level27_8057CField(workWord25,short*,0);
__asm__ volatile("":"=r"(workWord24):"0"(workWord24),"m"(Level27_8057CField(workWord25,short*,0)):"memory");
workWord2=(workWord24>>12);
__asm__("":"=r"(workWord2),"=r"(workWord3):"0"(workWord2),"1"(workWord3));
__asm__ volatile(""::"m"(originalFrame.sp1C0):"hi","lo","memory");
product34.full=(long long)workWord2*(long long)workWord3;
__asm__ volatile("":"=x"(product34.full):"0"(product34.full));
savedWord17=savedWord17+savedWord18;
__asm__ volatile("":"=x"(product34.full):"0"(product34.full));
workWord25=(int)product34.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.spB0=workWord2;
workWord2=Level27_8057CField(savedWord17,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase23):"0"(workWord2),"1"(argumentOrMathWord6Phase23));
__asm__ volatile(""::"m"(originalFrame.spB0):"hi","lo","memory");
product35.full=(long long)workWord2*(long long)argumentOrMathWord6Phase23;
__asm__ volatile("":"=x"(product35.full):"0"(product35.full));
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,424);
__asm__ volatile("":"=x"(product35.full):"0"(product35.full));
workWord25=(int)product35.words.low;
Level27_8057CKeep(workWord25);
workWord3=Level27_8057CField(workWord24,short*,0);
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord24,short*,0)):"memory");
workWord2=(workWord25>>12);
__asm__("":"=r"(workWord2),"=r"(workWord3):"0"(workWord2),"1"(workWord3));
__asm__ volatile(""::"m"(originalFrame.sp1C0):"hi","lo","memory");
product36.full=(long long)workWord2*(long long)workWord3;
__asm__ volatile("":"=x"(product36.full):"0"(product36.full));
savedWord22=savedWord22+savedWord18;
__asm__ volatile("":"=x"(product36.full):"0"(product36.full));
workWord24=(int)product36.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.spB4=workWord2;
workWord2=Level27_8057CField(savedWord22,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase23):"0"(workWord2),"1"(argumentOrMathWord6Phase23));
__asm__ volatile(""::"m"(originalFrame.spB4):"hi","lo","memory");
product37.full=(long long)workWord2*(long long)argumentOrMathWord6Phase23;
__asm__ volatile("":"=x"(product37.full):"0"(product37.full));
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,400);
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,400)):"memory");argumentWord4=workWord25+1176;
argumentOrMathWord6Phase22=Level27_8057CField(&originalFrame.sp18,
        volatile int*,392);Level27_8057CKeep(argumentOrMathWord6Phase22);
__asm__ volatile("":"=x"(product37.full):"0"(product37.full));
workWord24=(int)product37.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.spB8=workWord2;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase22);
workWord2=retainedWord30+47;
retainedWord30=workWord2&255;
workWord2=(int)((unsigned int)retainedWord30<<1);
workWord2=workWord2+savedWord18;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
argumentWord4=Level27_8057CField(workWord2,unsigned short*,0);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,376);
__asm__ volatile("":"=r"(argumentWord4):"0"(argumentWord4),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,376)):"memory");argumentWord4=(int)((unsigned int)argumentWord4<<16);
argumentWord4=(argumentWord4>>22);
workWord3=workWord25+32;
workWord3=workWord3&255;
workWord3=(int)((unsigned int)workWord3<<1);
workWord2=workWord3+savedWord19;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
workWord2=Level27_8057CField(workWord2,short*,0);
__asm__ volatile("":"=r"(argumentWord4):"0"(argumentWord4),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,376)):"memory");argumentOrMathWord6Phase21=argumentWord4+448;
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase21):"0"(workWord2),"1"(argumentOrMathWord6Phase21));
__asm__ volatile(""::"m"(originalFrame.sp190):"hi","lo","memory");
product38.full=(long long)workWord2*(long long)argumentOrMathWord6Phase21;
__asm__ volatile("":"=x"(product38.full):"0"(product38.full));
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,384);
savedWord20=workWord24&255;
savedWord20=(int)((unsigned int)savedWord20<<1);
workWord25=savedWord20+savedWord19;
Level27_8057CKeep(workWord25);
originalFrame.sp1C8=workWord25;
__asm__ volatile("":"=x"(product38.full):"0"(product38.full));
workWord24=(int)product38.words.low;
Level27_8057CKeep(workWord24);
argumentWord4=Level27_8057CField(workWord25,short*,0);
__asm__ volatile("":"=r"(workWord24):"0"(workWord24),"m"(Level27_8057CField(workWord25,short*,0)):"memory");
workWord2=(workWord24>>12);
__asm__("":"=r"(workWord2),"=r"(argumentWord4):"0"(workWord2),"1"(argumentWord4));
__asm__ volatile(""::"m"(originalFrame.sp1C8):"hi","lo","memory");
product39.full=(long long)workWord2*(long long)argumentWord4;
__asm__ volatile("":"=x"(product39.full):"0"(product39.full));
workWord3=workWord3+savedWord18;
__asm__ volatile("":"=x"(product39.full):"0"(product39.full));
workWord25=(int)product39.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.spB0=workWord2;
workWord2=Level27_8057CField(workWord3,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase21):"0"(workWord2),"1"(argumentOrMathWord6Phase21));
__asm__ volatile(""::"m"(originalFrame.spB0):"hi","lo","memory");
product40.full=(long long)workWord2*(long long)argumentOrMathWord6Phase21;
__asm__ volatile("":"=x"(product40.full):"0"(product40.full));
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,432);
__asm__ volatile("":"=x"(product40.full):"0"(product40.full));
workWord25=(int)product40.words.low;
Level27_8057CKeep(workWord25);
workWord3=Level27_8057CField(workWord24,short*,0);
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord24,short*,0)):"memory");
workWord2=(workWord25>>12);
__asm__("":"=r"(workWord2),"=r"(workWord3):"0"(workWord2),"1"(workWord3));
__asm__ volatile(""::"m"(originalFrame.sp1C8):"hi","lo","memory");
product41.full=(long long)workWord2*(long long)workWord3;
__asm__ volatile("":"=x"(product41.full):"0"(product41.full));
savedWord20=savedWord20+savedWord18;
__asm__ volatile("":"=x"(product41.full):"0"(product41.full));
workWord24=(int)product41.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.spB4=workWord2;
workWord2=Level27_8057CField(savedWord20,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase21):"0"(workWord2),"1"(argumentOrMathWord6Phase21));
__asm__ volatile(""::"m"(originalFrame.spB4):"hi","lo","memory");
product42.full=(long long)workWord2*(long long)argumentOrMathWord6Phase21;
__asm__ volatile("":"=x"(product42.full):"0"(product42.full));
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,400);
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,400)):"memory");argumentWord4=workWord25+1188;
argumentOrMathWord6Phase20=Level27_8057CField(&originalFrame.sp18,
        volatile int*,392);Level27_8057CKeep(argumentOrMathWord6Phase20);
__asm__ volatile("":"=x"(product42.full):"0"(product42.full));
workWord24=(int)product42.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.spB8=workWord2;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase20);
workWord2=retainedWord30+47;
retainedWord30=workWord2&255;
workWord2=(int)((unsigned int)retainedWord30<<1);
workWord2=workWord2+savedWord18;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
workWord2=Level27_8057CField(workWord2,unsigned short*,0);
workWord3=Level27_8057CField(savedWord16,short*,0);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(savedWord16,short*,0)):"memory");
workWord2=(int)((unsigned int)workWord2<<16);
workWord2=(workWord2>>22);
argumentOrMathWord6Phase19=workWord2+448;
__asm__("":"=r"(workWord3),"=r"(argumentOrMathWord6Phase19):"0"(workWord3),"1"(argumentOrMathWord6Phase19));
__asm__ volatile(""::"m"(originalFrame.spB8):"hi","lo","memory");
product43.full=(long long)workWord3*(long long)argumentOrMathWord6Phase19;
__asm__ volatile("":"=x"(product43.full):"0"(product43.full));
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,384);
savedWord16=workWord25+240;
savedWord16=savedWord16&255;
savedWord16=(int)((unsigned int)savedWord16<<1);
retainedWord23=savedWord16+savedWord19;
retainedWord23=Level27_8057CAt23(retainedWord23);
Level27_8057CKeep(retainedWord23);
__asm__ volatile("":"=x"(product43.full):"0"(product43.full));
workWord24=(int)product43.words.low;
Level27_8057CKeep(workWord24);
workWord3=Level27_8057CField(retainedWord23,short*,0);
__asm__ volatile("":"=r"(workWord24):"0"(workWord24),"m"(Level27_8057CField(retainedWord23,short*,0)):"memory");
workWord2=(workWord24>>12);
__asm__("":"=r"(workWord2),"=r"(workWord3):"0"(workWord2),"1"(workWord3));
__asm__ volatile(""::"m"(originalFrame.sp198):"hi","lo","memory");
product44.full=(long long)workWord2*(long long)workWord3;
__asm__ volatile("":"=x"(product44.full):"0"(product44.full));
__asm__ volatile("":"=x"(product44.full):"0"(product44.full));
workWord25=(int)product44.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.spB0=workWord2;
workWord2=Level27_8057CField(savedWord17,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase19):"0"(workWord2),"1"(argumentOrMathWord6Phase19));
__asm__ volatile(""::"m"(originalFrame.spB0):"hi","lo","memory");
product45.full=(long long)workWord2*(long long)argumentOrMathWord6Phase19;
__asm__ volatile("":"=x"(product45.full):"0"(product45.full));
__asm__ volatile("":"=x"(product45.full):"0"(product45.full));
workWord24=(int)product45.words.low;
Level27_8057CKeep(workWord24);
workWord3=Level27_8057CField(retainedWord23,short*,0);
__asm__ volatile("":"=r"(workWord24):"0"(workWord24),"m"(Level27_8057CField(retainedWord23,short*,0)):"memory");
workWord2=(workWord24>>12);
__asm__("":"=r"(workWord2),"=r"(workWord3):"0"(workWord2),"1"(workWord3));
__asm__ volatile(""::"m"(originalFrame.spB0):"hi","lo","memory");
product46.full=(long long)workWord2*(long long)workWord3;
__asm__ volatile("":"=x"(product46.full):"0"(product46.full));
savedWord16=savedWord16+savedWord18;
__asm__ volatile("":"=x"(product46.full):"0"(product46.full));
workWord25=(int)product46.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.spB4=workWord2;
workWord2=Level27_8057CField(savedWord16,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase19):"0"(workWord2),"1"(argumentOrMathWord6Phase19));
__asm__ volatile(""::"m"(originalFrame.spB4):"hi","lo","memory");
product47.full=(long long)workWord2*(long long)argumentOrMathWord6Phase19;
__asm__ volatile("":"=x"(product47.full):"0"(product47.full));
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,400);
__asm__ volatile("":"=r"(workWord24):"0"(workWord24),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,400)):"memory");argumentWord4=workWord24+1200;
argumentOrMathWord6Phase18=Level27_8057CField(&originalFrame.sp18,
        volatile int*,392);Level27_8057CKeep(argumentOrMathWord6Phase18);
__asm__ volatile("":"=x"(product47.full):"0"(product47.full));
workWord25=(int)product47.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.spB8=workWord2;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase18);
workWord2=retainedWord30+47;
retainedWord30=workWord2&255;
workWord2=(int)((unsigned int)retainedWord30<<1);
workWord2=workWord2+savedWord18;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
workWord2=Level27_8057CField(workWord2,unsigned short*,0);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,416);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,416)):"memory");workWord2=(int)((unsigned int)workWord2<<16);
workWord2=(workWord2>>22);
workWord3=Level27_8057CField(workWord24,short*,0);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(workWord24,short*,0)):"memory");
argumentOrMathWord6Phase17=workWord2+448;
__asm__("":"=r"(workWord3),"=r"(argumentOrMathWord6Phase17):"0"(workWord3),"1"(argumentOrMathWord6Phase17));
__asm__ volatile(""::"m"(originalFrame.sp1B8):"hi","lo","memory");
product48.full=(long long)workWord3*(long long)argumentOrMathWord6Phase17;
__asm__ volatile("":"=x"(product48.full):"0"(product48.full));
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,384);
workWord3=workWord25+224;
workWord3=workWord3&255;
workWord3=(int)((unsigned int)workWord3<<1);
argumentWord5=workWord3+savedWord19;
Level27_8057CKeep(argumentWord5);
__asm__ volatile("":"=x"(product48.full):"0"(product48.full));
workWord24=(int)product48.words.low;
Level27_8057CKeep(workWord24);
argumentWord4=Level27_8057CField(argumentWord5,short*,0);
__asm__ volatile("":"=r"(workWord24):"0"(workWord24),"m"(Level27_8057CField(argumentWord5,short*,0)):"memory");
workWord2=(workWord24>>12);
__asm__("":"=r"(workWord2),"=r"(argumentWord4):"0"(workWord2),"1"(argumentWord4));
__asm__ volatile(""::"m"(originalFrame.sp198):"hi","lo","memory");
product49.full=(long long)workWord2*(long long)argumentWord4;
__asm__ volatile("":"=x"(product49.full):"0"(product49.full));
__asm__ volatile("":"=x"(product49.full):"0"(product49.full));
workWord25=(int)product49.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.spB0=workWord2;
workWord2=Level27_8057CField(savedWord21,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase17):"0"(workWord2),"1"(argumentOrMathWord6Phase17));
__asm__ volatile(""::"m"(originalFrame.spB0):"hi","lo","memory");
product50.full=(long long)workWord2*(long long)argumentOrMathWord6Phase17;
__asm__ volatile("":"=x"(product50.full):"0"(product50.full));
__asm__ volatile("":"=x"(product50.full):"0"(product50.full));
workWord24=(int)product50.words.low;
Level27_8057CKeep(workWord24);
argumentWord4=Level27_8057CField(argumentWord5,short*,0);
__asm__ volatile("":"=r"(workWord24):"0"(workWord24),"m"(Level27_8057CField(argumentWord5,short*,0)):"memory");
workWord2=(workWord24>>12);
__asm__("":"=r"(workWord2),"=r"(argumentWord4):"0"(workWord2),"1"(argumentWord4));
__asm__ volatile(""::"m"(originalFrame.spB0):"hi","lo","memory");
product51.full=(long long)workWord2*(long long)argumentWord4;
__asm__ volatile("":"=x"(product51.full):"0"(product51.full));
workWord3=workWord3+savedWord18;
__asm__ volatile("":"=x"(product51.full):"0"(product51.full));
workWord25=(int)product51.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.spB4=workWord2;
workWord2=Level27_8057CField(workWord3,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase17):"0"(workWord2),"1"(argumentOrMathWord6Phase17));
__asm__ volatile(""::"m"(originalFrame.spB4):"hi","lo","memory");
product52.full=(long long)workWord2*(long long)argumentOrMathWord6Phase17;
__asm__ volatile("":"=x"(product52.full):"0"(product52.full));
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,400);
__asm__ volatile("":"=r"(workWord24):"0"(workWord24),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,400)):"memory");argumentWord4=workWord24+1212;
argumentOrMathWord6Phase16=Level27_8057CField(&originalFrame.sp18,
        volatile int*,392);Level27_8057CKeep(argumentOrMathWord6Phase16);
__asm__ volatile("":"=x"(product52.full):"0"(product52.full));
workWord25=(int)product52.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.spB8=workWord2;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase16);
workWord2=retainedWord30+47;
retainedWord30=workWord2&255;
workWord2=(int)((unsigned int)retainedWord30<<1);
workWord2=workWord2+savedWord18;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
argumentWord4=Level27_8057CField(workWord2,unsigned short*,0);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,376);
__asm__ volatile("":"=r"(argumentWord4):"0"(argumentWord4),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,376)):"memory");argumentWord4=(int)((unsigned int)argumentWord4<<16);
argumentWord4=(argumentWord4>>22);
workWord2=workWord24+240;
workWord2=workWord2&255;
workWord2=(int)((unsigned int)workWord2<<1);
workWord3=workWord2+savedWord19;
Level27_8057CKeep(workWord3);
Level27_8057CKeep(workWord3);
workWord3=Level27_8057CField(workWord3,short*,0);
__asm__ volatile("":"=r"(argumentWord4):"0"(argumentWord4),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,376)):"memory");argumentOrMathWord6Phase15=argumentWord4+448;
__asm__("":"=r"(workWord3),"=r"(argumentOrMathWord6Phase15):"0"(workWord3),"1"(argumentOrMathWord6Phase15));
__asm__ volatile(""::"m"(originalFrame.sp190):"hi","lo","memory");
product53.full=(long long)workWord3*(long long)argumentOrMathWord6Phase15;
__asm__ volatile("":"=x"(product53.full):"0"(product53.full));
__asm__ volatile("":"=x"(product53.full):"0"(product53.full));
workWord25=(int)product53.words.low;
Level27_8057CKeep(workWord25);
argumentWord4=Level27_8057CField(retainedWord23,short*,0);
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(retainedWord23,short*,0)):"memory");
workWord3=(workWord25>>12);
__asm__("":"=r"(workWord3),"=r"(argumentWord4):"0"(workWord3),"1"(argumentWord4));
__asm__ volatile(""::"m"(originalFrame.sp190):"hi","lo","memory");
product54.full=(long long)workWord3*(long long)argumentWord4;
__asm__ volatile("":"=x"(product54.full):"0"(product54.full));
workWord2=workWord2+savedWord18;
__asm__ volatile("":"=x"(product54.full):"0"(product54.full));
workWord24=(int)product54.words.low;
Level27_8057CKeep(workWord24);
workWord3=(workWord24>>12);
originalFrame.spB0=workWord3;
workWord2=Level27_8057CField(workWord2,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase15):"0"(workWord2),"1"(argumentOrMathWord6Phase15));
__asm__ volatile(""::"m"(originalFrame.spB0):"hi","lo","memory");
product55.full=(long long)workWord2*(long long)argumentOrMathWord6Phase15;
__asm__ volatile("":"=x"(product55.full):"0"(product55.full));
__asm__ volatile("":"=x"(product55.full):"0"(product55.full));
workWord25=(int)product55.words.low;
Level27_8057CKeep(workWord25);
workWord3=Level27_8057CField(retainedWord23,short*,0);
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(retainedWord23,short*,0)):"memory");
workWord2=(workWord25>>12);
__asm__("":"=r"(workWord2),"=r"(workWord3):"0"(workWord2),"1"(workWord3));
__asm__ volatile(""::"m"(originalFrame.spB0):"hi","lo","memory");
product56.full=(long long)workWord2*(long long)workWord3;
__asm__ volatile("":"=x"(product56.full):"0"(product56.full));
__asm__ volatile("":"=x"(product56.full):"0"(product56.full));
workWord24=(int)product56.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.spB4=workWord2;
workWord2=Level27_8057CField(savedWord16,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase15):"0"(workWord2),"1"(argumentOrMathWord6Phase15));
__asm__ volatile(""::"m"(originalFrame.spB4):"hi","lo","memory");
product57.full=(long long)workWord2*(long long)argumentOrMathWord6Phase15;
__asm__ volatile("":"=x"(product57.full):"0"(product57.full));
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,400);
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,400)):"memory");argumentWord4=workWord25+1224;
argumentOrMathWord6Phase14=Level27_8057CField(&originalFrame.sp18,
        volatile int*,392);Level27_8057CKeep(argumentOrMathWord6Phase14);
__asm__ volatile("":"=x"(product57.full):"0"(product57.full));
workWord24=(int)product57.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.spB8=workWord2;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase14);
workWord2=retainedWord30+47;
retainedWord30=workWord2&255;
workWord2=(int)((unsigned int)retainedWord30<<1);
workWord2=workWord2+savedWord18;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
workWord2=Level27_8057CField(workWord2,unsigned short*,0);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,376);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,376)):"memory");workWord2=(int)((unsigned int)workWord2<<16);
workWord2=(workWord2>>22);
savedWord16=workWord25+224;
savedWord16=savedWord16&255;
savedWord16=(int)((unsigned int)savedWord16<<1);
savedWord17=savedWord16+savedWord19;
Level27_8057CKeep(savedWord17);
Level27_8057CKeep(savedWord17);
workWord3=Level27_8057CField(savedWord17,short*,0);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(savedWord17,short*,0)):"memory");
argumentOrMathWord6Phase13=workWord2+448;
__asm__("":"=r"(workWord3),"=r"(argumentOrMathWord6Phase13):"0"(workWord3),"1"(argumentOrMathWord6Phase13));
__asm__ volatile(""::"m"(originalFrame.sp190):"hi","lo","memory");
product58.full=(long long)workWord3*(long long)argumentOrMathWord6Phase13;
__asm__ volatile("":"=x"(product58.full):"0"(product58.full));
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,432);
__asm__ volatile("":"=x"(product58.full):"0"(product58.full));
workWord25=(int)product58.words.low;
Level27_8057CKeep(workWord25);
workWord3=Level27_8057CField(workWord24,short*,0);
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord24,short*,0)):"memory");
workWord2=(workWord25>>12);
__asm__("":"=r"(workWord2),"=r"(workWord3):"0"(workWord2),"1"(workWord3));
__asm__ volatile(""::"m"(originalFrame.sp1C8):"hi","lo","memory");
product59.full=(long long)workWord2*(long long)workWord3;
__asm__ volatile("":"=x"(product59.full):"0"(product59.full));
savedWord16=savedWord16+savedWord18;
__asm__ volatile("":"=x"(product59.full):"0"(product59.full));
workWord24=(int)product59.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.spB0=workWord2;
workWord2=Level27_8057CField(savedWord16,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase13):"0"(workWord2),"1"(argumentOrMathWord6Phase13));
__asm__ volatile(""::"m"(originalFrame.spB0):"hi","lo","memory");
product60.full=(long long)workWord2*(long long)argumentOrMathWord6Phase13;
__asm__ volatile("":"=x"(product60.full):"0"(product60.full));
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,432);
__asm__ volatile("":"=x"(product60.full):"0"(product60.full));
workWord24=(int)product60.words.low;
Level27_8057CKeep(workWord24);
workWord3=Level27_8057CField(workWord25,short*,0);
__asm__ volatile("":"=r"(workWord24):"0"(workWord24),"m"(Level27_8057CField(workWord25,short*,0)):"memory");
workWord2=(workWord24>>12);
__asm__("":"=r"(workWord2),"=r"(workWord3):"0"(workWord2),"1"(workWord3));
__asm__ volatile(""::"m"(originalFrame.sp1C8):"hi","lo","memory");
product61.full=(long long)workWord2*(long long)workWord3;
__asm__ volatile("":"=x"(product61.full):"0"(product61.full));
__asm__ volatile("":"=x"(product61.full):"0"(product61.full));
workWord25=(int)product61.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.spB4=workWord2;
workWord2=Level27_8057CField(savedWord20,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase13):"0"(workWord2),"1"(argumentOrMathWord6Phase13));
__asm__ volatile(""::"m"(originalFrame.spB4):"hi","lo","memory");
product62.full=(long long)workWord2*(long long)argumentOrMathWord6Phase13;
__asm__ volatile("":"=x"(product62.full):"0"(product62.full));
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,400);
__asm__ volatile("":"=r"(workWord24):"0"(workWord24),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,400)):"memory");argumentWord4=workWord24+1236;
argumentOrMathWord6Phase12=Level27_8057CField(&originalFrame.sp18,
        volatile int*,392);Level27_8057CKeep(argumentOrMathWord6Phase12);
__asm__ volatile("":"=x"(product62.full):"0"(product62.full));
workWord25=(int)product62.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.spB8=workWord2;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase12);
workWord2=retainedWord30+47;
retainedWord30=workWord2&255;
workWord2=(int)((unsigned int)retainedWord30<<1);
workWord2=workWord2+savedWord18;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
workWord2=Level27_8057CField(workWord2,unsigned short*,0);
workWord3=Level27_8057CField(savedWord17,short*,0);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(savedWord17,short*,0)):"memory");
workWord2=(int)((unsigned int)workWord2<<16);
workWord2=(workWord2>>22);
argumentOrMathWord6Phase11=workWord2+448;
__asm__("":"=r"(workWord3),"=r"(argumentOrMathWord6Phase11):"0"(workWord3),"1"(argumentOrMathWord6Phase11));
__asm__ volatile(""::"m"(originalFrame.spB8):"hi","lo","memory");
product63.full=(long long)workWord3*(long long)argumentOrMathWord6Phase11;
__asm__ volatile("":"=x"(product63.full):"0"(product63.full));
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,424);
__asm__ volatile("":"=x"(product63.full):"0"(product63.full));
workWord25=(int)product63.words.low;
Level27_8057CKeep(workWord25);
workWord3=Level27_8057CField(workWord24,short*,0);
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord24,short*,0)):"memory");
workWord2=(workWord25>>12);
__asm__("":"=r"(workWord2),"=r"(workWord3):"0"(workWord2),"1"(workWord3));
__asm__ volatile(""::"m"(originalFrame.sp1C0):"hi","lo","memory");
product64.full=(long long)workWord2*(long long)workWord3;
__asm__ volatile("":"=x"(product64.full):"0"(product64.full));
__asm__ volatile("":"=x"(product64.full):"0"(product64.full));
workWord24=(int)product64.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.spB0=workWord2;
workWord2=Level27_8057CField(savedWord16,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase11):"0"(workWord2),"1"(argumentOrMathWord6Phase11));
__asm__ volatile(""::"m"(originalFrame.spB0):"hi","lo","memory");
product65.full=(long long)workWord2*(long long)argumentOrMathWord6Phase11;
__asm__ volatile("":"=x"(product65.full):"0"(product65.full));
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,424);
__asm__ volatile("":"=x"(product65.full):"0"(product65.full));
workWord24=(int)product65.words.low;
Level27_8057CKeep(workWord24);
workWord3=Level27_8057CField(workWord25,short*,0);
__asm__ volatile("":"=r"(workWord24):"0"(workWord24),"m"(Level27_8057CField(workWord25,short*,0)):"memory");
workWord2=(workWord24>>12);
__asm__("":"=r"(workWord2),"=r"(workWord3):"0"(workWord2),"1"(workWord3));
__asm__ volatile(""::"m"(originalFrame.sp1C0):"hi","lo","memory");
product66.full=(long long)workWord2*(long long)workWord3;
__asm__ volatile("":"=x"(product66.full):"0"(product66.full));
__asm__ volatile("":"=x"(product66.full):"0"(product66.full));
workWord25=(int)product66.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.spB4=workWord2;
workWord2=Level27_8057CField(savedWord22,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase11):"0"(workWord2),"1"(argumentOrMathWord6Phase11));
__asm__ volatile(""::"m"(originalFrame.spB4):"hi","lo","memory");
product67.full=(long long)workWord2*(long long)argumentOrMathWord6Phase11;
__asm__ volatile("":"=x"(product67.full):"0"(product67.full));
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,400);
__asm__ volatile("":"=r"(workWord24):"0"(workWord24),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,400)):"memory");argumentWord4=workWord24+1248;
argumentOrMathWord6Phase10=Level27_8057CField(&originalFrame.sp18,
        volatile int*,392);Level27_8057CKeep(argumentOrMathWord6Phase10);
__asm__ volatile("":"=x"(product67.full):"0"(product67.full));
workWord25=(int)product67.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.spB8=workWord2;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase10);
workWord2=retainedWord30+47;
retainedWord30=workWord2&255;
workWord2=(int)((unsigned int)retainedWord30<<1);
workWord2=workWord2+savedWord18;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
workWord2=Level27_8057CField(workWord2,unsigned short*,0);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,376);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,376)):"memory");workWord2=(int)((unsigned int)workWord2<<16);
workWord2=(workWord2>>22);
savedWord16=(int)((unsigned int)workWord24<<1);
workWord3=savedWord16+savedWord19;
Level27_8057CKeep(workWord3);
Level27_8057CKeep(workWord3);
workWord3=Level27_8057CField(workWord3,short*,0);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,376)):"memory");argumentOrMathWord6Phase9=workWord2+448;
__asm__("":"=r"(workWord3),"=r"(argumentOrMathWord6Phase9):"0"(workWord3),"1"(argumentOrMathWord6Phase9));
__asm__ volatile(""::"m"(originalFrame.sp190):"hi","lo","memory");
product68.full=(long long)workWord3*(long long)argumentOrMathWord6Phase9;
__asm__ volatile("":"=x"(product68.full):"0"(product68.full));
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,384);
savedWord20=(int)((unsigned int)workWord25<<1);
savedWord19=savedWord20+savedWord19;
Level27_8057CKeep(savedWord19);
__asm__ volatile("":"=x"(product68.full):"0"(product68.full));
workWord24=(int)product68.words.low;
Level27_8057CKeep(workWord24);
workWord3=Level27_8057CField(savedWord19,short*,0);
__asm__ volatile("":"=r"(workWord24):"0"(workWord24),"m"(Level27_8057CField(savedWord19,short*,0)):"memory");
workWord2=(workWord24>>12);
__asm__("":"=r"(workWord2),"=r"(workWord3):"0"(workWord2),"1"(workWord3));
__asm__ volatile(""::"m"(originalFrame.sp198):"hi","lo","memory");
product69.full=(long long)workWord2*(long long)workWord3;
__asm__ volatile("":"=x"(product69.full):"0"(product69.full));
__asm__ volatile("":"=x"(product69.full):"0"(product69.full));
workWord25=(int)product69.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.spB0=workWord2;
workWord2=savedWord16+savedWord18;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
workWord2=Level27_8057CField(workWord2,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase9):"0"(workWord2),"1"(argumentOrMathWord6Phase9));
__asm__ volatile(""::"m"(originalFrame.spB0):"hi","lo","memory");
product70.full=(long long)workWord2*(long long)argumentOrMathWord6Phase9;
__asm__ volatile("":"=x"(product70.full):"0"(product70.full));
__asm__ volatile("":"=x"(product70.full):"0"(product70.full));
workWord24=(int)product70.words.low;
Level27_8057CKeep(workWord24);
workWord3=Level27_8057CField(savedWord19,short*,0);
__asm__ volatile("":"=r"(workWord24):"0"(workWord24),"m"(Level27_8057CField(savedWord19,short*,0)):"memory");
workWord2=(workWord24>>12);
__asm__("":"=r"(workWord2),"=r"(workWord3):"0"(workWord2),"1"(workWord3));
__asm__ volatile(""::"m"(originalFrame.spB0):"hi","lo","memory");
product71.full=(long long)workWord2*(long long)workWord3;
__asm__ volatile("":"=x"(product71.full):"0"(product71.full));
__asm__ volatile("":"=x"(product71.full):"0"(product71.full));
workWord25=(int)product71.words.low;
Level27_8057CKeep(workWord25);
workWord2=(workWord25>>12);
originalFrame.spB4=workWord2;
workWord2=savedWord20+savedWord18;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
workWord2=Level27_8057CField(workWord2,short*,0);
__asm__("":"=r"(workWord2),"=r"(argumentOrMathWord6Phase9):"0"(workWord2),"1"(argumentOrMathWord6Phase9));
__asm__ volatile(""::"m"(originalFrame.spB4):"hi","lo","memory");
product72.full=(long long)workWord2*(long long)argumentOrMathWord6Phase9;
__asm__ volatile("":"=x"(product72.full):"0"(product72.full));
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,400);
argumentWord5=argumentWord4+0;
__asm__ volatile(""::"r"(argumentWord5):"memory");
argumentOrMathWord6Phase8=Level27_8057CField(&originalFrame.sp18,
        volatile int*,392);Level27_8057CKeep(argumentOrMathWord6Phase8);
__asm__ volatile("":"=x"(product72.full):"0"(product72.full));
workWord24=(int)product72.words.low;
Level27_8057CKeep(workWord24);
workWord2=(workWord24>>12);
originalFrame.spB8=workWord2;
Level27_8057C_func_8004F194(argumentWord4,argumentWord5,argumentOrMathWord6Phase8);
goto original_80081E34;
original_80081D68:
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord25+1152;
Level27_8057C_func_8004F168(argumentWord4);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord24+1164;
Level27_8057C_func_8004F168(argumentWord4);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord25+1176;
Level27_8057C_func_8004F168(argumentWord4);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord24+1188;
Level27_8057C_func_8004F168(argumentWord4);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord25+1200;
Level27_8057C_func_8004F168(argumentWord4);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord24+1212;
Level27_8057C_func_8004F168(argumentWord4);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord25+1224;
Level27_8057C_func_8004F168(argumentWord4);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord24+1236;
Level27_8057C_func_8004F168(argumentWord4);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord25+1248;
Level27_8057C_func_8004F168(argumentWord4);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord24+1260;
Level27_8057C_func_8004F168(argumentWord4);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord25+1272;
Level27_8057C_func_8004F168(argumentWord4);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord24+1284;
Level27_8057C_func_8004F168(argumentWord4);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord25+1296;
Level27_8057C_func_8004F168(argumentWord4);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord24+1308;
Level27_8057C_func_8004F168(argumentWord4);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord25+1320;
Level27_8057C_func_8004F168(argumentWord4);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord24+1332;
Level27_8057C_func_8004F168(argumentWord4);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
argumentWord4=workWord25+1344;
Level27_8057C_func_8004F168(argumentWord4);
original_80081E34:
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,256);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,256)):"$2","memory");workWord2=0+-1;
Level27_8057CField(workWord24,int*,1152)=workWord2;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,232);
Level27_8057CField(workWord25,int*,1152)=workWord2;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,240);
Level27_8057CField(workWord24,int*,1152)=workWord2;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
Level27_8057CField(workWord25,int*,1260)=workWord2;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,224);
workWord3=0+32;
if(workWord24==0)goto original_80082084;
savedWord22=0+0;
workWord15=(int)0x55550000U;
Level27_8057CKeep(workWord15);
workWord15=workWord15|21846;
workWord12=0+1;
Level27_8057CKeep(workWord12);
__asm__ volatile(""::"r"(workWord12):"$11","memory");
workWord11=0+2;
__asm__ volatile(""::"r"(workWord11):"$14","memory");
workWord14=0+3;
__asm__ volatile(""::"r"(workWord14):"$13","memory");
workWord13=0+0;
__asm__ volatile(""::"r"(workWord13):"$4","memory");
argumentWord4=0+128;
__asm__ volatile(""::"r"(argumentWord4):"$25","memory");
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,264);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,264)):"$2","memory");workWord2=0+20;
Level27_8057CField(workWord25,unsigned char*,2)=workWord2;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,2)):"memory");
Level27_8057CField(workWord25,unsigned char*,5)=workWord2;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,5)):"memory");
workWord2=0+4;
Level27_8057CField(workWord25,unsigned char*,8)=workWord2;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,8)):"memory");
Level27_8057CField(workWord25,unsigned char*,8)=workWord2;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,8)):"memory");
workWord2=0+2;
Level27_8057CField(workWord25,unsigned char*,12)=workWord2;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,12)):"memory");
workWord2=0+16;
Level27_8057CField(workWord25,unsigned char*,13)=workWord2;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,13)):"memory");
Level27_8057CField(workWord25,unsigned char*,14)=workWord2;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,14)):"memory");
workWord2=0+8;
Level27_8057CField(workWord25,unsigned char*,16)=workWord2;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,16)):"memory");
workWord2=0+64;
Level27_8057CField(workWord25,unsigned char*,0)=workWord3;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,0)):"memory");
Level27_8057CField(workWord25,unsigned char*,1)=argumentWord4;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,1)):"memory");
Level27_8057CField(workWord25,unsigned char*,4)=workWord3;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,4)):"memory");
Level27_8057CField(workWord25,unsigned char*,6)=argumentWord4;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,6)):"memory");
Level27_8057CField(workWord25,unsigned char*,9)=workWord3;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,9)):"memory");
Level27_8057CField(workWord25,unsigned char*,10)=workWord3;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,10)):"memory");
Level27_8057CField(workWord25,unsigned char*,9)=workWord3;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,9)):"memory");
Level27_8057CField(workWord25,unsigned char*,10)=workWord3;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,10)):"memory");
Level27_8057CField(workWord25,unsigned char*,17)=workWord2;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,17)):"memory");
Level27_8057CField(workWord25,unsigned char*,18)=workWord2;
__asm__ volatile("":"=r"(workWord25):"0"(workWord25),"m"(Level27_8057CField(workWord25,unsigned char*,18)):"memory");
original_80081EF8:
savedWord19=0+0;
workWord10=workWord13+0;
colorWord9=workWord14+0;
original_80081F04:
argumentWord7=workWord10+savedWord19;
workWord2=savedWord19+1;
colorWord8=colorWord9+savedWord19;
__asm__("":"=r"(workWord2),"=r"(workWord15):"0"(workWord2),"1"(workWord15));
__asm__ volatile(""::"m"(originalFrame.sp120):"hi","lo","memory");
product73.full=(long long)workWord2*(long long)workWord15;
__asm__ volatile("":"=x"(product73.full):"0"(product73.full));
savedWord19=workWord2+0;
argumentWord5=(int)((unsigned int)argumentWord7<<3);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,272);
__asm__ volatile("":"=r"(savedWord19):"0"(savedWord19),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,272)):"memory");workWord2=(savedWord19>>31);
argumentWord4=argumentWord5+workWord24;
Level27_8057CKeep(argumentWord4);
Level27_8057CKeep(argumentWord4);
Level27_8057CField(argumentWord4,unsigned char*,0)=argumentWord7;
Level27_8057CField(argumentWord4,unsigned char*,2)=colorWord8;
Level27_8057CField(argumentWord4,unsigned char*,4)=0;
Level27_8057CField(argumentWord4,unsigned char*,5)=0;
Level27_8057CField(argumentWord4,unsigned char*,6)=0;
Level27_8057CField(argumentWord4,unsigned char*,7)=0;
__asm__ volatile("":"=x"(product73.full):"0"(product73.full));
workWord25=(int)product73.words.high;
Level27_8057CKeep(workWord25);
workWord2=workWord25-workWord2;
workWord3=(int)((unsigned int)workWord2<<1);
workWord3=workWord3+workWord2;
workWord3=savedWord19-workWord3;
argumentOrMathWord6Phase7=workWord10+workWord3;
workWord3=colorWord9+workWord3;
Level27_8057CField(argumentWord4,unsigned char*,1)=argumentOrMathWord6Phase7;
Level27_8057CField(argumentWord4,unsigned char*,3)=workWord3;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,280);
workWord2=argumentWord5+workWord24;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
Level27_8057CField(workWord2,unsigned char*,0)=argumentWord7;
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(workWord2,unsigned char*,0)):"memory");
Level27_8057CField(workWord2,unsigned char*,1)=argumentOrMathWord6Phase7;
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(workWord2,unsigned char*,1)):"memory");
Level27_8057CField(workWord2,unsigned char*,2)=colorWord8;
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(workWord2,unsigned char*,2)):"memory");
Level27_8057CField(workWord2,unsigned char*,3)=workWord3;
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(workWord2,unsigned char*,3)):"memory");
Level27_8057CField(workWord2,unsigned char*,4)=workWord12;
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(workWord2,unsigned char*,4)):"memory");
Level27_8057CField(workWord2,unsigned char*,5)=workWord12;
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(workWord2,unsigned char*,5)):"memory");
Level27_8057CField(workWord2,unsigned char*,6)=workWord12;
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(workWord2,unsigned char*,6)):"memory");
Level27_8057CField(workWord2,unsigned char*,7)=workWord12;
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(workWord2,unsigned char*,7)):"memory");
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,288);
__asm__ volatile("":"=r"(savedWord19):"0"(savedWord19),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,288)):"memory");workWord2=savedWord19<3;
argumentWord5=argumentWord5+workWord25;
Level27_8057CKeep(argumentWord5);
Level27_8057CKeep(argumentWord5);
Level27_8057CField(argumentWord5,unsigned char*,0)=argumentWord7;
Level27_8057CField(argumentWord5,unsigned char*,1)=argumentOrMathWord6Phase7;
Level27_8057CField(argumentWord5,unsigned char*,2)=colorWord8;
Level27_8057CField(argumentWord5,unsigned char*,3)=workWord3;
Level27_8057CField(argumentWord5,unsigned char*,4)=workWord11;
Level27_8057CField(argumentWord5,unsigned char*,5)=workWord11;
Level27_8057CField(argumentWord5,unsigned char*,6)=workWord11;
Level27_8057CField(argumentWord5,unsigned char*,7)=workWord11;
if(workWord2!=0)goto original_80081F04;
workWord14=workWord14+3;
savedWord22=savedWord22+1;
workWord2=savedWord22<31;
workWord13=workWord13+3;
if(workWord2!=0)goto original_80081EF8;
workWord2=0+96;
argumentWord7=0+97;
argumentWord5=0+99;
Level27_8057CField(workWord25,unsigned char*,744)=workWord2;
workWord2=0+98;
argumentOrMathWord6Phase6=0+4;
workWord3=0+3;
argumentWord4=0+96;
Level27_8057CField(workWord25,unsigned char*,746)=argumentWord5;
Level27_8057CField(workWord25,unsigned char*,753)=argumentWord5;
argumentWord5=0+101;
Level27_8057CField(workWord25,unsigned char*,747)=workWord2;
workWord2=0+100;
Level27_8057CField(workWord25,unsigned char*,754)=argumentWord5;
Level27_8057CField(workWord25,unsigned char*,761)=argumentWord5;
argumentWord5=0+103;
Level27_8057CField(workWord25,unsigned char*,755)=workWord2;
workWord2=0+102;
Level27_8057CField(workWord25,unsigned char*,763)=workWord2;
workWord2=0+104;
Level27_8057CField(workWord25,unsigned char*,745)=argumentWord7;
Level27_8057CField(workWord25,unsigned char*,748)=argumentOrMathWord6Phase6;
Level27_8057CField(workWord25,unsigned char*,749)=workWord3;
Level27_8057CField(workWord25,unsigned char*,750)=workWord3;
Level27_8057CField(workWord25,unsigned char*,751)=workWord3;
Level27_8057CField(workWord25,unsigned char*,752)=argumentWord4;
Level27_8057CField(workWord25,unsigned char*,756)=argumentOrMathWord6Phase6;
Level27_8057CField(workWord25,unsigned char*,757)=workWord3;
Level27_8057CField(workWord25,unsigned char*,758)=workWord3;
Level27_8057CField(workWord25,unsigned char*,759)=workWord3;
Level27_8057CField(workWord25,unsigned char*,760)=argumentWord4;
Level27_8057CField(workWord25,unsigned char*,762)=argumentWord5;
Level27_8057CField(workWord25,unsigned char*,764)=argumentOrMathWord6Phase6;
Level27_8057CField(workWord25,unsigned char*,765)=workWord3;
Level27_8057CField(workWord25,unsigned char*,766)=workWord3;
Level27_8057CField(workWord25,unsigned char*,767)=workWord3;
Level27_8057CField(workWord25,unsigned char*,768)=argumentWord4;
Level27_8057CField(workWord25,unsigned char*,769)=argumentWord5;
Level27_8057CField(workWord25,unsigned char*,770)=argumentWord7;
Level27_8057CField(workWord25,unsigned char*,771)=workWord2;
Level27_8057CField(workWord25,unsigned char*,772)=argumentOrMathWord6Phase6;
Level27_8057CField(workWord25,unsigned char*,773)=workWord3;
Level27_8057CField(workWord25,unsigned char*,774)=workWord3;
Level27_8057CField(workWord25,unsigned char*,775)=workWord3;
original_80082084:
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,200)):"$4","memory");argumentWord4=0+-1;
workWord2=Level27_8057CField(workWord24,int*,12);
__asm__ volatile(""::"r"(workWord24),"m"(Level27_8057CField(workWord24,int*,12)):"memory");
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,272);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,272)):"memory");workWord2=(int)((unsigned int)workWord2<<3);
workWord2=workWord2+workWord25;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
Level27_8057CField(workWord2,int*,0)=argumentWord4;
workWord2=Level27_8057CField(workWord24,int*,12);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,280);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,280)):"memory");workWord2=(int)((unsigned int)workWord2<<3);
workWord2=workWord2+workWord24;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
Level27_8057CField(workWord2,int*,0)=argumentWord4;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
workWord3=Level27_8057CField(workWord25,int*,12);
__asm__ volatile(""::"m"(Level27_8057CField(workWord25,int*,12)):"$2","memory");
workWord2=0+93;
if(workWord3!=workWord2?(workWord2=(int)((unsigned int)workWord3<<3),1):(workWord2=(int)((unsigned int)workWord3<<3),0))goto original_800820D8;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,288);
Level27_8057CField(workWord24,int*,776)=argumentWord4;
goto original_800820E8;
original_800820D8:
__asm__ volatile("":"=r"(workWord3):"0"(workWord3):"memory");
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,288);
workWord2=workWord2+workWord25;
Level27_8057CKeep(workWord2);
Level27_8057CKeep(workWord2);
Level27_8057CField(workWord2,int*,0)=argumentWord4;
original_800820E8:
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
workWord2=Level27_8057CField(workWord24,int*,4);
if(workWord2!=0)goto original_80082134;
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,232);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,264);
workWord2=Level27_8057CField(workWord24,int*,16);
argumentOrMathWord6Phase5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,272);Level27_8057CKeep(argumentOrMathWord6Phase5);
argumentWord7=Level27_8057CField(workWord2,int*,0);
__asm__ volatile(""::"m"(originalFrame.sp128):"$2","memory");
workWord2=0+1;
fifthArgument=workWord2;
argumentWord7=argumentWord7+248;
workWord2=Level27_8057C_func_80050B00(argumentWord4,argumentWord5,argumentOrMathWord6Phase5,argumentWord7,fifthArgument);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
Level27_8057CField(workWord25,int*,4)=workWord2;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
original_80082134:
workWord2=Level27_8057CField(workWord24,int*,8);
if(workWord2!=0)goto original_80082178;
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,240);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,264);
workWord2=Level27_8057CField(workWord24,int*,16);
argumentOrMathWord6Phase4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,280);Level27_8057CKeep(argumentOrMathWord6Phase4);
argumentWord7=Level27_8057CField(workWord2,int*,0);
__asm__ volatile(""::"m"(originalFrame.sp130):"$2","memory");
workWord2=0+1;
fifthArgument=workWord2;
argumentWord7=argumentWord7+248;
workWord2=Level27_8057C_func_80050B00(argumentWord4,argumentWord5,argumentOrMathWord6Phase4,argumentWord7,fifthArgument);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
Level27_8057CField(workWord25,int*,8)=workWord2;
original_80082178:
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
workWord2=Level27_8057CField(workWord24,int*,12);
if(workWord2!=0)goto original_800821CC;
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,248);
workWord2=Level27_8057CField(workWord24,int*,16);
argumentWord5=Level27_8057CField(&originalFrame.sp18,
        volatile int*,264);
workWord3=Level27_8057CField(workWord2,int*,0);
__asm__ volatile(""::"r"(workWord2),"m"(Level27_8057CField(workWord2,int*,0)):"memory");
argumentOrMathWord6Phase3=Level27_8057CField(&originalFrame.sp18,
        volatile int*,288);Level27_8057CKeep(argumentOrMathWord6Phase3);
workWord2=Level27_8057CField(workWord3,unsigned short*,262);
__asm__ volatile("":"=r"(workWord3):"0"(workWord3),"m"(Level27_8057CField(workWord3,unsigned short*,262)):"memory");
argumentWord7=workWord3+256;
workWord2=workWord2|32;
Level27_8057CField(workWord3,short*,262)=workWord2;
workWord2=0+1;
fifthArgument=workWord2;
workWord2=Level27_8057C_func_80050B00(argumentWord4,argumentWord5,argumentOrMathWord6Phase3,argumentWord7,fifthArgument);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
Level27_8057CField(workWord25,int*,12)=workWord2;
original_800821CC:
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
workWord2=Level27_8057CField(workWord24,unsigned char*,73);
if(workWord2!=0)goto originalReturn;
workWord2=0+93;
__asm__ volatile(""::"r"(workWord2):"memory");
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
workWord3=Level27_8057CField(workWord25,int*,12);
savedWord22=0+1;
if(workWord3!=workWord2)goto originalReturn;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,232);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,232)):"$16","memory");savedWord16=0+1;
savedWord17=workWord24+36;
original_80082208:
argumentWord4=savedWord17+0;
argumentWord5=0+128;
argumentOrMathWord6Phase2=0+38;
workWord2=Level27_8057C_func_8001C288(argumentWord4,argumentWord5,argumentOrMathWord6Phase2);
argumentWord5=0+0;
if(workWord2==0)goto original_80082258;
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
argumentOrMathWord6Phase1=0+0;
workWord2=Level27_8057C_func_8003BABC(argumentWord4,argumentWord5,argumentOrMathWord6Phase1);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,184)):"$5","memory");argumentWord5=(int)&Level27_8057C_D_80070328;Level27_8057CKeep(argumentWord5);
argumentWord4=workWord25+12;
Level27_8057C_func_8004F178(argumentWord4,argumentWord5);
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
Level27_8057CField(workWord24,unsigned char*,73)=savedWord16;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,192)):"$2","memory");workWord2=0+120;
Level27_8057CField(workWord25,short*,20)=workWord2;
original_80082258:
savedWord22=savedWord22+1;
workWord2=savedWord22<32;
savedWord17=savedWord17+36;
if(workWord2!=0)goto original_80082208;
goto originalReturn;
original_80082270:
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
argumentWord4=Level27_8057CField(workWord24,int*,4);
if(argumentWord4==0)goto original_800822A0;
Level27_8057C_func_80050B88(argumentWord4);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
Level27_8057CField(workWord25,int*,4)=0;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
original_800822A0:
argumentWord4=Level27_8057CField(workWord24,int*,8);
if(argumentWord4==0)goto original_800822C8;
Level27_8057C_func_80050B88(argumentWord4);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
Level27_8057CField(workWord25,int*,8)=0;
original_800822C8:
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
argumentWord4=Level27_8057CField(workWord24,int*,12);
argumentWord5=0+2;
if(argumentWord4==0)goto original_800822FC;
Level27_8057C_func_80050B88(argumentWord4);
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
Level27_8057CField(workWord25,int*,12)=0;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,192);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,192)):"$5","memory");argumentWord5=0+2;
original_800822FC:
argumentWord4=workWord24+20;
workWord2=Level27_8057C_func_800359A4(argumentWord4,argumentWord5);
savedWord18=(int)&originalFrame.spC0;
if(workWord2==0)goto original_8008235C;
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
argumentWord5=Level27_8057CField(workWord25,int*,16);
workWord2=Level27_8057C_func_8003BFC0(argumentWord4,argumentWord5);
if(workWord2==0)goto original_8008233C;
workWord24=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
argumentWord4=Level27_8057CField(workWord24,int*,16);
Level27_8057C_func_8003BE70(argumentWord4);
original_8008233C:
workWord25=Level27_8057CField(&originalFrame.sp18,
        volatile int*,200);
__asm__ volatile(""::"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,200)):"$2","memory");workWord2=0+-1;
Level27_8057CField(workWord25,int*,16)=workWord2;
argumentWord4=Level27_8057CField(&originalFrame.sp18,
        volatile int*,184);
Level27_8057C_func_80055B18(argumentWord4);
goto originalReturn;
original_8008235C:
argumentWord4=savedWord18+0;
__asm__ volatile(""::"r"(argumentWord4):"$17","memory");
savedWord17=(int)&Level27_8057C_D_80070328;
Level27_8057CKeep(savedWord17);
argumentWord5=savedWord17+0;
Level27_8057C_func_8004F178(argumentWord4,argumentWord5);
workWord2=Level27_8057C_rand();
workWord3=Level27_8057CField(&originalFrame.sp18,
        volatile int*,168);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,168)):"memory");workWord2=workWord2&127;
workWord3=workWord3+-64;
workWord3=workWord3+workWord2;
originalFrame.spC0=workWord3;
workWord2=Level27_8057C_rand();
workWord3=Level27_8057CField(&originalFrame.sp18,
        volatile int*,172);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,172)):"memory");workWord2=workWord2&127;
workWord3=workWord3+-64;
workWord3=workWord3+workWord2;
originalFrame.spC4=workWord3;
workWord2=Level27_8057C_rand();
savedWord16=(int)&originalFrame.sp28;
argumentWord4=savedWord16+0;
argumentWord5=savedWord17+152;
workWord3=Level27_8057CField(&originalFrame.sp18,
        volatile int*,176);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,176)):"memory");workWord2=workWord2&127;
workWord3=workWord3+-64;
workWord3=workWord3-workWord2;
originalFrame.spC8=workWord3;
Level27_8057C_func_8004F178(argumentWord4,argumentWord5);
argumentWord4=savedWord16+0;
argumentWord5=0+8;
Level27_8057C_func_8004F110(argumentWord4,argumentWord5);
workWord2=Level27_8057C_rand();
workWord3=Level27_8057CField(&originalFrame.sp18,
        volatile int*,16);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,16)):"memory");workWord2=workWord2&16;
workWord3=workWord3+-8;
workWord3=workWord3+workWord2;
originalFrame.sp28=workWord3;
workWord2=Level27_8057C_rand();
workWord3=Level27_8057CField(&originalFrame.sp18,
        volatile int*,20);
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,20)):"memory");workWord2=workWord2&16;
workWord3=workWord3+-8;
workWord3=workWord3+workWord2;
originalFrame.sp2C=workWord3;
workWord2=Level27_8057C_rand();
argumentWord4=0+1;
argumentWord5=0+22;
argumentOrMathWord6Phase0=savedWord18+0;
argumentWord7=savedWord16+0;
__asm__ volatile("":"=r"(workWord2),"=r"(argumentWord4),"=r"(argumentWord5),"=r"(argumentOrMathWord6Phase0),"=r"(argumentWord7):"0"(workWord2),"1"(argumentWord4),"2"(argumentWord5),"3"(argumentOrMathWord6Phase0),"4"(argumentWord7):"memory");
workWord2=workWord2&7;
__asm__ volatile(""::"r"(workWord2):"$3","memory");
workWord3=(int)Level27_8057C_SpawnParticle;
__asm__ volatile("":"=r"(workWord2):"0"(workWord2),"m"(Level27_8057CField(&originalFrame.sp18,
        volatile int*,20)):"memory");workWord2=workWord2+8;
originalFrame.sp30=workWord2;
workWord2=((int(*)(int,int,int,int))workWord3)(argumentWord4,argumentWord5,argumentOrMathWord6Phase0,argumentWord7);
originalReturn:return;
}
#undef Level27_8057CField
#undef Level27_8057CKeep


/* Private offsets +0, +4 and +0x10 follow the retail timer/vector/pointer reads. */
typedef struct {
    int timer;
    Vector3D previousOffset;
    char* previousParticle;
} DecodedTwoParticleTag;
typedef struct {
    Vector3D vector;
    int reserved0C;
} DecodedTwoParticleSlot;
extern int DecodedTwoParticlePhase __asm__("D_80070328 + 0x64");
extern int DecodedTwoParticlePhaseAdd __asm__("D_80070328 + 0x184");
extern short DecodedTwoParticleCos[] __asm__("D_80065920");
extern short DecodedTwoParticleSin[] __asm__("D_800658A0");
int DecodedTwoParticleTimer(void*,int) __asm__("func_800359A4");
void DecodedTwoParticleBasis(Vector3D*) __asm__("func_80049484");
void DecodedTwoParticleCopy(Vector3D*,Vector3D*) __asm__("func_8004F178");
void DecodedTwoParticleScale(Vector3D*,int) __asm__("func_8004F110");
void DecodedTwoParticleAdd(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004F194");
void DecodedTwoParticleDifference(Vector3D*,void*) __asm__("func_8004F554");
void DecodedTwoParticleShift(Vector3D*,int) __asm__("func_8004F0E8");
void func_level_27_8008246C(Moby* moby) {
    DecodedTwoParticleTag* tag = moby->mobyTag;
    DecodedTwoParticleSlot slots[4];
    register Vector3D* second __asm__("$18");
    register Vector3D* third __asm__("$19");
    Vector3D* fourth;
    register int* phaseSource __asm__("$5");
    register char* particle __asm__("$17");
    char* secondParticle;
    int result;
    register int phase __asm__("$3");
    result = DecodedTwoParticleTimer(tag,4);
    if (result == 2) { moby->substate = 1; return; }
    if (result) {
        if (!moby->substate) tag->timer = 180;
        return;
    }
    if (!moby->substate) {
        third = &slots[2].vector;
        DecodedTwoParticleBasis(third);
        /* Retain the original +0x64 producer and +0x34 source-pointer step. */
        phaseSource = &DecodedTwoParticlePhase;
        phase = ((*phaseSource+DecodedTwoParticlePhaseAdd) >> 4) & 255;
        second = &slots[1].vector;
        __asm__("" : "=r"(phase) : "0"(phase));
        slots[0].vector.x = (DecodedTwoParticleCos[phase] * 25) >> 10;
        slots[0].vector.y = (DecodedTwoParticleSin[phase] * 25) >> 10;
        slots[0].vector.z = 0;
        DecodedTwoParticleCopy(second,(Vector3D*)((char*)phaseSource+0x34));
        second->z = 0;
        DecodedTwoParticleScale(second,5);
        DecodedTwoParticleAdd(&slots[0].vector,&slots[0].vector,second);
        /* Retail dereferences both callback results without a null guard. */
        particle = SpawnParticle(1,29,third,&slots[0].vector);
        fourth = &slots[3].vector;
        moby->substate += 3;
        *(unsigned short*)(particle+30)=moby->substate;
        __asm__ volatile ("" : : "r"(particle), "r"(second), "r"(third));
        DecodedTwoParticleDifference(fourth,tag->previousParticle+4);
        DecodedTwoParticleShift(fourth,2);
        DecodedTwoParticleAdd(third,third,fourth);
        DecodedTwoParticleScale(third,1);
        DecodedTwoParticleAdd(second,&slots[0].vector,&tag->previousOffset);
        DecodedTwoParticleScale(second,1);
        tag->previousParticle = particle;
        secondParticle = SpawnParticle(1,29,third,second);
        moby->substate += 3;
        *(unsigned short*)(secondParticle+30)=moby->substate;
        DecodedTwoParticleCopy(&tag->previousOffset,&slots[0].vector);
    } else {
        moby->substate = 1;
        tag->timer = 0;
    }
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_27/moby/func_level_27_800826A0.s SHA256 7cd671547cfd07bab3441266e4272ac5ead9d164694ea2ac96333607b37ece0e. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Spike826A0Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))

int Spike826A0_func_800359A4() __asm__("func_800359A4");                 /* extern */
int Spike826A0_func_8004E880() __asm__("func_8004E880");                /* extern */
int Spike826A0_func_8004EDE8() __asm__("func_8004EDE8");                  /* extern */
int Spike826A0_func_8004F08C() __asm__("func_8004F08C");             /* extern */
int Spike826A0_func_8004F110() __asm__("func_8004F110");         /* extern */
int Spike826A0_func_8004F178() __asm__("func_8004F178");               /* extern */
int Spike826A0_func_8004F194() __asm__("func_8004F194");         /* extern */
int Spike826A0_func_8004F1C8() __asm__("func_8004F1C8");         /* extern */
int Spike826A0_func_8004F264() __asm__("func_8004F264");                         /* extern */
int Spike826A0_func_80050B00() __asm__("func_80050B00"); /* extern */
int Spike826A0_func_80050B88() __asm__("func_80050B88");                         /* extern */
int Spike826A0_func_80055B18() __asm__("func_80055B18");                     /* extern */
int Spike826A0_func_80055D24() __asm__("func_80055D24");              /* extern */
int Spike826A0_func_80055F14() __asm__("func_80055F14");     /* extern */
int Spike826A0_rand() __asm__("rand");                                      /* extern */
extern unsigned char Spike826A0_D_800658A0 __asm__("D_800658A0");
extern unsigned char Spike826A0_D_80065920 __asm__("D_80065920");
extern int Spike826A0_D_8006C640 __asm__("D_8006C640");
extern int Spike826A0_D_80070328 __asm__("D_80070328");
extern int (*Spike826A0_SpawnParticle)() __asm__("SpawnParticle");

void func_level_27_800826A0(void **ownerRecord) {
    register int temporary9 __asm__("$9");
    register int temporary10 __asm__("$10");
    register void *pointer9 __asm__("$9");
    register void *pointer10 __asm__("$10");
    register void *vector17 __asm__("$17");
    register void *vector22 __asm__("$22");
    register int global3 __asm__("$3");
    register int byte2 __asm__("$2");

    /* Original frame: 0xC8 bytes; saved registers start at SP+0xA0.
     * The scratch fields retain their original SP offsets and padding.
     * Packet records advance by 24 bytes; selector records by 8 bytes.
     * Table loads retain distinct original LH/LHU producers. Empty
     * constraints preserve raw register lifetimes and emit no instruction.
     * Helper contracts, physical units and caller cadence remain open. */
    struct {int sp18;
        int sp1C;
        int sp20;
        unsigned char pad24[4];
        int sp28;
        int sp2C;
        int sp30;
        unsigned char pad34[4];
        int sp38;
        int sp3C;
        int sp40;
        unsigned char pad44[4];
        void **sp48;
        unsigned char pad4C[4];
        int sp50;
        unsigned char pad54[4];
        void *sp58;
        unsigned char pad5C[4];
        void *sp60;
        unsigned char pad64[4];
        void *sp68;
        unsigned char pad6C[4];
        int sp70;
        unsigned char pad74[4];
        int sp78;
        unsigned char pad7C[4];
        int sp80;
        unsigned char pad84[4];
        short *sp88;
        unsigned char pad8C[12];
        int sp98;
        unsigned char pad9C[4];} originalFrame;

    int *privateWord4;
    register void *rootPosition4 __asm__("$4");
    register void *gateVector4 __asm__("$4");
    register int gateResult5 __asm__("$5");
    register void *globalPointer16 __asm__("$16");
    register void *argumentPointer5 __asm__("$5");
    register int product9 __asm__("$9");
    register int product10 __asm__("$10");
    register int modeArg6 __asm__("$6");
    register void *argumentPointer6 __asm__("$6");
    register int scanCode8 __asm__("$8");
    register int scanTimer7 __asm__("$7");
    register int slotArg4 __asm__("$4");
    register int slotArg5 __asm__("$5");
    register void *slotArg7 __asm__("$7");
    register void *loadPointer4 __asm__("$4");

    register void *rootRecord20 __asm__("$20");
    void *childCursor4;
    register void *packetCursor19 __asm__("$19");
    int handleWord4;
    register int tableValue4 __asm__("$4");
    register int randomOffset16 __asm__("$16");
    register int randomOffset17 __asm__("$17");
    register int randomOffset17b __asm__("$17");
    register int stepAngle18 __asm__("$18");
    register int randomOffset18 __asm__("$18");
    int timerResult;
    int gateResult;
    register int randomResult2 __asm__("$2");
    register int rootValue3 __asm__("$3");
    register int childOrdinal5 __asm__("$5");
    register int recordGate5 __asm__("$5");
    register int selectorOrdinal5 __asm__("$5");
    int rootGateWord;
    register int selectorCount16 __asm__("$16");
    register int packetOrdinal21 __asm__("$21");
    register int phaseWord23 __asm__("$23");
    register int rootUpdate2 __asm__("$2");
    register int temporaryWord2b __asm__("$2");
    register int temporaryWord2c __asm__("$2");
    register int selectorIndex3 __asm__("$3");
    register int selectorIndex21 __asm__("$21");
    unsigned short *headingTablePointer3;
    register int angleWord2 __asm__("$2");
    register void *ownerPosition16 __asm__("$16");
    void **linkedPrivatePointer2;
    register void *selectedPacket6 __asm__("$6");
    register int nextByte2 __asm__("$2");
    register int comparison2 __asm__("$2");
    register int headerValue2 __asm__("$2");
    register int (*slotCall3)() __asm__("$3");
    void *privateRecord;
    void *childRecord3;
    void *linkedPrivateRecord3;
    register void *selectorCursor4 __asm__("$4");

    originalFrame.sp48 = ownerRecord;
    privateRecord = *ownerRecord;
    originalFrame.sp78 = 0;
    __asm__ volatile("" : : : "memory");
    privateWord4 = Spike826A0Field(privateRecord, int **, 4);
    temporary9=*privateWord4;
    __asm__("" : "=r"(temporary9):"0"(temporary9));
    originalFrame.sp50=temporary9;
    rootRecord20 = Spike826A0Field(privateRecord, int **, 0);
    __asm__ volatile("" : : : "$5");
    Spike826A0_func_80055D24(privateWord4,4);
    childOrdinal5=0xC;
    __asm__("" : "=r"(childOrdinal5):"0"(childOrdinal5));
    pointer10=originalFrame.sp48;
    __asm__("" : "=r"(pointer10):"0"(pointer10));
    Spike826A0_func_80055F14(Spike826A0Field(privateRecord,int**,4),childOrdinal5,pointer10+0xC);
    timerResult = Spike826A0_func_800359A4(privateRecord + 0x10, 4);
    pointer9=rootRecord20+0x54;
    pointer10=rootRecord20+0x1F0;
    __asm__("" : "=r"(pointer10):"0"(pointer10),"r"(pointer9));
    originalFrame.sp58=pointer9;
    pointer9=rootRecord20+0x1F4;
    __asm__("" : "=r"(pointer9):"0"(pointer9),"r"(pointer10));
    originalFrame.sp60=pointer10;
    originalFrame.sp68=pointer9;
    if (timerResult != 0) {
        if (Spike826A0Field(privateRecord, void ***, 8) == 0) {
            childOrdinal5 = 0;
            scanCode8=0x3E0;
            __asm__("" : "=r"(scanCode8):"0"(scanCode8));
            scanTimer7=timerResult-1;
            __asm__("" : "=r"(scanTimer7):"0"(scanTimer7),"r"(scanCode8));
            childCursor4 = rootRecord20;
            do {
                childRecord3 = Spike826A0Field(childCursor4, void **, 0x34);
                if ((childRecord3 != 0) && (Spike826A0Field(childRecord3, short *, 0x36) == scanCode8)) {
                    Spike826A0Field(Spike826A0Field(childRecord3, void **, 0), int *, 0x10) = scanTimer7;
                }
                childOrdinal5 += 1;
                childCursor4 += 4;
            } while (childOrdinal5 < 7);
        }
    }
    if (timerResult == 2) {
        Spike826A0Field(rootRecord20, int *, 0x30) = 0x800;
    }
    if ((timerResult != 0) && (Spike826A0Field(rootRecord20, int *, 0x30) < 0x79)) {
        handleWord4 = Spike826A0Field(privateRecord, int *, 0xC);
        if (handleWord4 != 0) {
            Spike826A0_func_80050B88(handleWord4);
        }
        Spike826A0_func_80055B18(originalFrame.sp48);
        return;
    }
    if (Spike826A0Field(privateRecord, int *, 0x10) == 0) {
        rootUpdate2 = Spike826A0Field(rootRecord20, int *, 0x30) - 0x78;
        goto storeRootUpdate;
    }
    rootValue3 = Spike826A0Field(rootRecord20, int *, 0x30);
    if (rootValue3<0x800) {
        rootUpdate2=rootValue3+0x1E;
storeRootUpdate:
        Spike826A0Field(rootRecord20, int *, 0x30) = rootUpdate2;
    }
    pointer10=originalFrame.sp48;
    __asm__("" : "=r"(pointer10):"0"(pointer10));
    modeArg6=0;
    if (Spike826A0Field(pointer10,unsigned char*,0x49) != 0) {
        __asm__("" : "=r"(rootRecord20):"0"(rootRecord20));
        globalPointer16=&Spike826A0_D_80070328;
        byte2=Spike826A0_func_8004E880(Spike826A0Field(globalPointer16,int*,0)-Spike826A0Field(rootRecord20,int*,0),Spike826A0Field(&Spike826A0_D_80070328,int*,4)-Spike826A0Field(rootRecord20,int*,4),modeArg6);
        rootPosition4=rootRecord20+0x20;
        argumentPointer5=globalPointer16;
        __asm__("" : "=r"(argumentPointer5):"0"(argumentPointer5),"r"(rootPosition4),"r"(byte2));
        Spike826A0Field(rootRecord20,unsigned char*,0x2C)=byte2;
        global3=Spike826A0_D_8006C640;
        __asm__("" : "=r"(global3):"0"(global3));
        byte2=0x18;
        Spike826A0Field(rootRecord20,unsigned char*,0x2F)=byte2;
        byte2=Spike826A0Field(rootRecord20,unsigned char*,0x2E);
        __asm__("" : "=r"(byte2):"0"(byte2),"r"(global3));
        global3*=0x10;
        __asm__("" : "=r"(global3):"0"(global3),"r"(byte2));
        phaseWord23=byte2+global3;
        Spike826A0_func_8004F178(rootPosition4,argumentPointer5);
        Spike826A0Field(rootRecord20, int *, 0x28) = (int) Spike826A0Field(rootRecord20, int *, 8);
    } else {
        byte2=Spike826A0Field(rootRecord20,unsigned char*,0x2C);
        global3=Spike826A0Field(rootRecord20,unsigned char*,0x2D);
        __asm__("" : "=r"(global3):"0"(global3),"r"(byte2));
        angleWord2=byte2+global3;
        Spike826A0Field(rootRecord20, unsigned char *, 0x2C) = angleWord2;
        __asm__ volatile("" : : : "memory");
        byte2=(angleWord2&0xFF)*2;
        global3=Spike826A0Field(&Spike826A0_D_80065920,short*,byte2);
        byte2=Spike826A0Field(rootRecord20,int*,0x18);
        __asm__("" : "=r"(byte2):"0"(byte2),"r"(global3));
        product9=global3*byte2;
        byte2=Spike826A0Field(rootRecord20,unsigned char*,0x2C)*2;
        __asm__("" : "=r"(product9):"0"(product9),"r"(byte2));
        global3=product9>>12;
        Spike826A0Field(rootRecord20,int*,0x20)=global3;
        global3=Spike826A0Field(&Spike826A0_D_800658A0,short*,byte2);
        byte2=Spike826A0Field(rootRecord20,int*,0x18);
        __asm__("" : "=r"(byte2):"0"(byte2),"r"(global3));
        product10=global3*byte2;
        rootPosition4=rootRecord20+0x20;
        __asm__("" : "=r"(rootPosition4):"0"(rootPosition4));
        Spike826A0Field(rootRecord20,int*,0x28)=0;
        byte2=Spike826A0_D_8006C640;
        global3=Spike826A0Field(rootRecord20,unsigned char*,0x2E);
        byte2*=4;
        phaseWord23=global3+byte2;
        __asm__("" : "=r"(product10):"0"(product10),"r"(phaseWord23));
        byte2=product10>>12;
        __asm__("" : "=r"(byte2):"0"(byte2),"r"(product10));
        Spike826A0Field(rootRecord20,int*,0x24)=byte2;
        Spike826A0_func_8004F194(rootPosition4, rootPosition4, rootRecord20);
    }
    gateVector4=&originalFrame.sp18;
    argumentPointer5=rootRecord20+0x20;
    __asm__("" : "=r"(argumentPointer5):"0"(argumentPointer5),"r"(gateVector4));
    pointer9=originalFrame.sp48;
    byte2=Spike826A0Field(rootRecord20,unsigned char*,0x2C);
    __asm__("" : "=r"(byte2):"0"(byte2),"r"(pointer9));
    argumentPointer6=pointer9+0xC;
    __asm__("" : "=r"(byte2):"0"(byte2),"r"(argumentPointer6));
    stepAngle18=byte2+0x40;
    Spike826A0_func_8004F1C8(gateVector4,argumentPointer5,argumentPointer6);
    gateResult = Spike826A0_func_8004EDE8(&originalFrame.sp18, 0);
    __asm__ volatile("" : : : "$4");
    rootGateWord = Spike826A0Field(rootRecord20, int *, 0x30);
    gateVector4=&originalFrame.sp18;
    if ((rootGateWord >= (gateResult >> 4)) && (rootGateWord = 0x400, ((gateResult < 0x4001) == 0))) {
        __asm__ volatile("" : : : "$4");
        Spike826A0_func_8004F110(&originalFrame.sp18, 4, 0x400);
    } else {
        Spike826A0_func_8004F08C(gateVector4,gateResult,rootGateWord);
    }
    pointer10=originalFrame.sp48;
    loadPointer4=originalFrame.sp58;
    __asm__("" : "=r"(loadPointer4):"0"(loadPointer4),"r"(pointer10));
    ownerPosition16=pointer10+0xC;
    Spike826A0_func_8004F178(loadPointer4,ownerPosition16);
    pointer9=originalFrame.sp58;
    __asm__ volatile("" : "=r"(pointer9):"0"(pointer9):"$5");
    argumentPointer5=ownerPosition16;
    Spike826A0_func_8004F178(pointer9+0xC,argumentPointer5);
    vector17=&originalFrame.sp28;
    __asm__("" : "=r"(vector17):"0"(vector17));
    Spike826A0_func_8004F1C8(vector17,ownerPosition16,rootRecord20);
    modeArg6=0;
    __asm__("" : "=r"(modeArg6):"0"(modeArg6));
    packetOrdinal21 = 2;
    vector22=vector17;
    __asm__("" : "=r"(vector22):"0"(vector22));
    pointer10=originalFrame.sp58;
    __asm__("" : "=r"(pointer10):"0"(pointer10));
    loadPointer4=(void *)originalFrame.sp28;
    argumentPointer5=(void *)originalFrame.sp2C;
    __asm__("" : "=r"(argumentPointer5):"0"(argumentPointer5),"r"(loadPointer4),"r"(pointer10));
    temporary9=0x24;
    originalFrame.sp98=temporary9;
    __asm__ volatile("" : : : "memory");
    packetCursor19=pointer10+0x18;
    byte2=(Spike826A0_func_8004E880(loadPointer4,argumentPointer5,modeArg6)+0x80)&0xFF;
    recordGate5=0x1000;
    __asm__("" : "=r"(recordGate5):"0"(recordGate5),"r"(byte2));
    originalFrame.sp70=byte2;
    byte2=(stepAngle18&0xFF)*2;
    pointer9=&Spike826A0_D_800658A0;
    __asm__("" : "=r"(pointer9):"0"(pointer9),"r"(byte2));
    originalFrame.sp80=byte2;
    __asm__ volatile("" : : : "memory");
    temporary10=originalFrame.sp80;
    byte2=originalFrame.sp30;
    pointer9=(void *)(temporary10+(unsigned int)pointer9);
    byte2+=0x140;
    originalFrame.sp88=(short *)pointer9;
    originalFrame.sp30=byte2;
    __asm__ volatile("" : : : "memory");
appendPacketRecord:
    if ((unsigned int) (recordGate5 - 0x801) < 0x33FFU) {
        Spike826A0_func_8004F194(vector22,vector22, &originalFrame.sp18);
        global3=(phaseWord23&0xFF)*2;
        __asm__("" : "=r"(global3):"0"(global3));
        pointer10=&Spike826A0_D_800658A0;
        headingTablePointer3=(unsigned short *)(global3+pointer10);
        byte2=*headingTablePointer3;
        temporary9=originalFrame.sp80;
        byte2<<=16;
        tableValue4=Spike826A0Field(&Spike826A0_D_80065920,short*,temporary9);
        byte2>>=18;
        product10=tableValue4*byte2;
        pointer9=originalFrame.sp88;
        __asm__("" : "=r"(product10):"0"(product10),"r"(pointer9));
        byte2=product10>>12;
        __asm__("" : "=r"(byte2):"0"(byte2),"r"(product10));
        originalFrame.sp38=byte2;
        byte2=*headingTablePointer3;
        global3=Spike826A0Field(pointer9,short*,0);
        byte2<<=16;
        byte2>>=18;
        product10=global3*byte2;
        originalFrame.sp40=0;
        __asm__("" : "=r"(product10):"0"(product10));
        byte2=product10>>12;
        __asm__("" : "=r"(byte2):"0"(byte2),"r"(product10));
        originalFrame.sp3C=byte2;
        phaseWord23 += Spike826A0Field(rootRecord20, unsigned char *, 0x2F);
        Spike826A0_func_8004F194(vector22,vector22, &originalFrame.sp38);
        Spike826A0_func_8004F194(packetCursor19,vector22, rootRecord20);
        pointer9=originalFrame.sp58;
        temporary10=originalFrame.sp98;
        __asm__("" : "=r"(temporary10):"0"(temporary10),"r"(pointer9));
        Spike826A0_func_8004F178(pointer9+temporary10,packetCursor19);
        randomOffset16=Spike826A0_rand()&0x3FF;
        __asm__("" : "=r"(randomOffset16):"0"(randomOffset16));
        randomOffset16-=0x200;
        randomOffset17=Spike826A0_rand()&0x3FF;
        __asm__("" : "=r"(randomOffset17):"0"(randomOffset17));
        randomOffset17-=0x200;
        randomOffset18=Spike826A0_rand()&0x1FF;
        __asm__("" : "=r"(randomOffset18):"0"(randomOffset18));
        randomOffset18-=0x100;
        global3=Spike826A0Field(packetCursor19,int*,0);
        tableValue4=Spike826A0Field(packetCursor19,int*,4);
        randomResult2=Spike826A0Field(packetCursor19,int*,8);
        __asm__("" : "=r"(randomResult2):"0"(randomResult2),"r"(global3),"r"(tableValue4),"r"(randomOffset18));
        global3+=randomOffset16;
        tableValue4+=randomOffset17;
        __asm__("" : "=r"(randomResult2):"0"(randomResult2),"r"(global3),"r"(tableValue4));
        randomResult2+=randomOffset18;
        __asm__("" : "=r"(randomResult2):"0"(randomResult2),"r"(global3),"r"(tableValue4));
        Spike826A0Field(packetCursor19,int*,0)=global3;
        Spike826A0Field(packetCursor19,int*,4)=tableValue4;
        __asm__ volatile("" : : : "memory");
        Spike826A0Field(packetCursor19,int*,8)=randomResult2;
        byte2=Spike826A0_rand(tableValue4)&0x1FF;
        global3=Spike826A0Field(packetCursor19,int*,0xC);
        randomOffset16+=byte2;
        global3-=0x100;
        __asm__("" : "=r"(global3):"0"(global3),"r"(randomOffset16));
        global3+=randomOffset16;
        Spike826A0Field(packetCursor19,int*,0xC)=global3;
        byte2=Spike826A0_rand()&0x1FF;
        randomOffset17+=byte2;
        global3=Spike826A0Field(packetCursor19,int*,0x10);
        byte2=Spike826A0Field(packetCursor19,int*,0x14);
        global3-=0x100;
        byte2+=0x80;
        __asm__("" : "=r"(byte2):"0"(byte2),"r"(global3),"r"(randomOffset17));
        byte2+=randomOffset18;
        Spike826A0Field(packetCursor19,int*,0x14)=byte2;
        __asm__ volatile("" : : : "memory");
        byte2=Spike826A0Field(packetCursor19,int*,0);
        __asm__("" : "=r"(byte2):"0"(byte2),"r"(global3));
        global3+=randomOffset17;
        Spike826A0Field(packetCursor19,int*,0x10)=global3;
        global3=Spike826A0Field(&Spike826A0_D_80070328,int*,0);
        __asm__("" : "=r"(global3):"0"(global3),"r"(byte2));
        temporaryWord2b=byte2-global3;
        if (temporaryWord2b < 0) {
            temporaryWord2b = -temporaryWord2b;
        }
        if (temporaryWord2b < 0x140) {
            byte2=Spike826A0Field(packetCursor19,int*,4);
            global3=Spike826A0Field(&Spike826A0_D_80070328,int*,4);
            __asm__("" : "=r"(global3):"0"(global3),"r"(byte2));
            temporaryWord2c=byte2-global3;
            if (temporaryWord2c < 0) {
                temporaryWord2c = -temporaryWord2c;
            }
            if (temporaryWord2c < 0x140) {
                temporary9=1;
                __asm__("" : "=r"(temporary9):"0"(temporary9));
                originalFrame.sp78=temporary9;
            }
        }
        if (Spike826A0_func_8004F264(originalFrame.sp70, Spike826A0_func_8004E880(originalFrame.sp28, originalFrame.sp2C, 0)) < 0x40) {
            Spike826A0_func_8004F1C8(&originalFrame.sp38,vector22, rootRecord20 + 0xC);
            if (Spike826A0_func_8004F264(originalFrame.sp70,Spike826A0_func_8004E880(originalFrame.sp38,originalFrame.sp3C,0))<0xE) {
                recordGate5=0;
                goto finishRecordGate;
            }
            gateVector4=vector22;
            goto issueRecordGate;
        }
        gateVector4=&originalFrame.sp28;
issueRecordGate:
        recordGate5=Spike826A0_func_8004EDE8(gateVector4,0);
finishRecordGate:;
        packetCursor19+=0x18;
        __asm__("" : "=r"(packetCursor19):"0"(packetCursor19));
        packetOrdinal21+=2;
        temporary10=originalFrame.sp98;
        __asm__("" : "=r"(temporary10):"0"(temporary10),"r"(packetOrdinal21));
        comparison2=packetOrdinal21<0x22;
        __asm__("" : "=r"(comparison2):"0"(comparison2),"r"(temporary10));
        temporary10+=0x18;
        originalFrame.sp98=temporary10;
        if (comparison2) {
            goto appendPacketRecord;
        }
    }
    byte2=packetOrdinal21*0xC;
    __asm__("" : "=r"(byte2):"0"(byte2));
    pointer9=originalFrame.sp58;
    global3=-1;
    byte2+=(unsigned int)pointer9;
    __asm__("" : "=r"(byte2):"0"(byte2),"r"(global3));
    Spike826A0Field(byte2,int*,0)=global3;
    pointer10=originalFrame.sp60;
    __asm__("" : "=r"(pointer10):"0"(pointer10));
    headerValue2=0x20;
    __asm__("" : "=r"(pointer10):"0"(pointer10),"r"(headerValue2));
    Spike826A0Field(pointer10,unsigned char*,0)=headerValue2;
    Spike826A0Field(pointer10,unsigned char*,1)=headerValue2;
    headerValue2=0xFF;
    Spike826A0Field(pointer10,unsigned char*,2)=headerValue2;
    comparison2=recordGate5<0x3401;
    __asm__("" : "=r"(comparison2):"0"(comparison2));
    originalFrame.sp18 = 0;
    originalFrame.sp1C = 0;
    originalFrame.sp20 = 0;
    if (!comparison2) {
        selectorCount16 = packetOrdinal21 - 4;
    } else {
        selectorCount16 = packetOrdinal21 - 2;
    }
    slotArg4=1;
    slotArg5=0x1A;
    __asm__("" : "=r"(slotArg5):"0"(slotArg5),"r"(slotArg4));
    selectedPacket6=(void *)(selectorCount16*0xC);
    slotArg7=&originalFrame.sp18;
    __asm__("" : "=r"(slotArg7):"0"(slotArg7),"r"(selectedPacket6));
    pointer9=originalFrame.sp58;
    pointer10=originalFrame.sp48;
    slotCall3=Spike826A0_SpawnParticle;
    __asm__("" : "=r"(slotCall3):"0"(slotCall3),"r"(pointer9),"r"(pointer10),"r"(selectedPacket6));
    byte2=Spike826A0Field(pointer10,int*,0x14);
    selectedPacket6=(void *)((unsigned int)selectedPacket6+(unsigned int)pointer9);
    Spike826A0Field(selectedPacket6,int*,8)=byte2;
    byte2=Spike826A0Field(pointer10,int*,0x14);
    __asm__ volatile("" : : : "$21");
    selectorIndex21=0;
    Spike826A0Field(selectedPacket6,int*,0x14)=byte2;
    slotCall3(slotArg4,slotArg5,selectedPacket6,slotArg7);
    selectorOrdinal5 = 0;
    if (selectorCount16 > 0) {
        selectorCursor4 = originalFrame.sp68;
        do {
            nextByte2=selectorIndex21+1;
            selectorIndex3=selectorIndex21+2;
            __asm__("" : "=r"(selectorIndex3):"0"(selectorIndex3),"r"(nextByte2));
            Spike826A0Field(selectorCursor4,unsigned char*,1)=nextByte2;
            nextByte2=selectorIndex21+3;
            Spike826A0Field(selectorCursor4, signed char *, 0) = selectorIndex21;
            Spike826A0Field(selectorCursor4, signed char *, 2) = selectorIndex3;
            Spike826A0Field(selectorCursor4,unsigned char*,3)=nextByte2;
            Spike826A0Field(selectorCursor4, signed char *, 4) = 0;
            Spike826A0Field(selectorCursor4, signed char *, 5) = 0;
            Spike826A0Field(selectorCursor4, signed char *, 6) = 0;
            Spike826A0Field(selectorCursor4, signed char *, 7) = 0;
            __asm__("" : "=r"(selectorCursor4):"0"(selectorCursor4):"memory");
            selectorCursor4 += 8;
            selectorIndex21 = selectorIndex3;
            selectorOrdinal5 += 1;
        } while (selectorIndex21 < selectorCount16);
    }
    byte2=selectorOrdinal5*8;
    __asm__("" : "=r"(byte2):"0"(byte2));
    pointer9=originalFrame.sp68;
    global3=-1;
    byte2+=(unsigned int)pointer9;
    __asm__("" : "=r"(byte2):"0"(byte2),"r"(global3));
    Spike826A0Field(byte2,int*,0)=global3;
    byte2=Spike826A0Field(privateRecord,int*,0xC);
    if (byte2 == 0) {
        byte2=1;
        loadPointer4=originalFrame.sp58;
        argumentPointer5=originalFrame.sp60;
        argumentPointer6=originalFrame.sp68;
        temporary10=originalFrame.sp50;

        Spike826A0Field(privateRecord,int*,0xC)=Spike826A0_func_80050B00(loadPointer4,argumentPointer5,argumentPointer6,temporary10+0x108,byte2);
    }
    temporary9=originalFrame.sp78;
    __asm__("" : "=r"(temporary9):"0"(temporary9));
    if (temporary9 != 0) {
        Spike826A0Field(&Spike826A0_D_80070328, int *, 0x24) = (int) (Spike826A0Field(&Spike826A0_D_80070328, int *, 0x24) | 0x26);
        linkedPrivatePointer2 = Spike826A0Field(privateRecord, void ***, 8);
        if (linkedPrivatePointer2 != 0) {
            linkedPrivateRecord3 = *linkedPrivatePointer2;
            if (Spike826A0Field(linkedPrivateRecord3, int *, 0x10) >= 0x1F) {
                Spike826A0Field(linkedPrivateRecord3, int *, 0x10) = 0x1E;
            }
        } else if (Spike826A0Field(privateRecord, int *, 0x10) >= 0x1F) {
            Spike826A0Field(privateRecord, int *, 0x10) = 0x1E;
        }
    }
}
#undef Spike826A0Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80082E44.
 * AI generated; not human reviewed. All828 native and linked instructions,
 * every actual conditional/internal-jump/call/data target, EXE and every
 * overlay hash are mandatory. This function owns no selectors or padding.
 * Original frame100hex=256 bytes saves S0..S7/FP/RA at SPD8..FC, with
 * SP18..D7 local extent. FP holds an ordinary initialized angle accumulator;
 * no explicit FP/SP binding or undefined incoming saved value is used.
 * Frame gaps are never read. All pointer values/offsets remain raw 32-bit
 * byte addresses. The indirect private chain retains both original loads.
 * Original owner/private/parent fields retain byte, signed/unsigned halfword
 * and word widths and callback read order. Two topology stores inferred as
 * words by the raw decoder are original byte stores and remain bytes here.
 * All11 static MULT sites have complete signed64 C products of initialized
 * signed32 operands. Six low consumers narrow to signed32 before >>12;
 * division uses88888889 /15,55555556 /3,2AAAAAAB /6 and sign correction.
 * Each topology alternative captures the high component of its shared whole
 * product after its two written byte fields. Both products are defined before
 * the original conditional; no partial HILO value or synthetic result exists.
 * Empty metadata observes full initialized values, complete products or fields
 * written just before the observation, or clobbers a dead register before a
 * fresh producer. It emits zero CPU instructions and never reads padding.
 * Original global camera angle uses LHU,SLL16,SRA20: a signed12-bit view;
 * the raw decoder's unsigned8 truncation is not used. Flag predicate and
 * pre-call ORI14 preserve the original branch delay instruction. Original
 * actor scan and16-by6 points,16 vectors,15-by6 topology and15 final records
 * retain all physical entries, helper calls and byte stores.
 * Falsification vectors: n=0,256,512,768,1024,1280 divided by6 give
 * 0,42,85,128,170,213; topology1..6 modulo6 gives1,2,3,4,5,0;
 * camera raw0x8000 yields-2048 after SLL16/SRA20, not an unsigned byte.
 * Helper views reuse matched original stdutil/tracer/spu/delete contracts;
 * int address parameters record the exact original 32-bit ABI words.
 * Confidence is binary identity after every gate. Semantic units/fixed-point
 * domains, complete caller/helper/consumer chains, cadence beyond invocation
 * and synchronized retail runtime remain open. No engine/browser changes.
 * Compiler/filter/flags unchanged. Next: human review and retail captures.
 */
/* Original assembly SHA256 5d04789f085897e9e4fab93ca4065275023d1113890c1ea58f28a7f02a5ea45b */
#define Level27_82E44Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
struct Level27_82E44Frame {
    int sp18[3];
    unsigned char reserved24[4];
    unsigned char sp28[24];
    signed char sp40;
    signed char sp41;
    signed char sp42;
    unsigned char reserved43[5];
    int sp48;
    int sp4C;
    int sp50;
    unsigned char reserved54[4];
    int sp58;
    int sp5C;
    unsigned char reserved60[8];
    int sp68;
    unsigned char reserved6c[4];
    int sp70;
    unsigned char reserved74[4];
    int sp78;
    unsigned char reserved7c[4];
    int sp80;
    unsigned char reserved84[4];
    int sp88;
    unsigned char reserved8c[4];
    int sp90;
    unsigned char reserved94[4];
    int sp98;
    unsigned char reserved9c[4];
    int spA0;
    unsigned char reserveda4[4];
    int spA8;
    unsigned char reservedac[4];
    int spB0;
    unsigned char reservedb4[4];
    int spB8;
    unsigned char reservedbc[4];
    int spC0;
    unsigned char reservedc4[4];
    int spC8;
    unsigned char reservedcc[4];
    int spD0;
    unsigned char reservedD4[4];
}
;
int Level27_82E44Call3BB10View1(int,int,int) __asm__("func_8003BB10");
int Level27_82E44Call4E880View1(int,int,int) __asm__("func_8004E880");
void Level27_82E44Call4EA90View1(int,int,int) __asm__("func_8004EA90");
void Level27_82E44Call4ED6CView1(int,int,int) __asm__("func_8004ED6C");
int Level27_82E44Call4EDE8View1(int,int) __asm__("func_8004EDE8");
void Level27_82E44Call4F194View1(int,int,int) __asm__("func_8004F194");
void Level27_82E44Call4F1C8View1(int,int,int) __asm__("func_8004F1C8");
int Level27_82E44Call4F264View1(int,int) __asm__("func_8004F264");
int Level27_82E44Call4F334View1(int,int) __asm__("func_8004F334");
void* Level27_82E44Call50B00View1(int,int,int,int,int) __asm__("func_80050B00");
void Level27_82E44Call50B88View1(int) __asm__("func_80050B88");
void Level27_82E44Call55B18View1(int) __asm__("func_80055B18");
extern unsigned char Level27_82E44Data658A0View1 __asm__("D_800658A0");
extern unsigned char Level27_82E44Data65920View1 __asm__("D_80065920");
extern unsigned char Level27_82E44Data6C409View1 __asm__("D_8006C409");
extern int Level27_82E44Data6C640View1 __asm__("D_8006C640");
extern int Level27_82E44Data6E020View1 __asm__("D_8006E020");
extern int Level27_82E44Data6E024View1 __asm__("D_8006E024");
extern unsigned short Level27_82E44Data6E040View1 __asm__("D_8006E040");
extern int Level27_82E44Data6E788View1 __asm__("D_8006E788");
extern unsigned char Level27_82E44Data70328View1 __asm__("D_80070328");
void func_level_27_80082E44(int ownerParameter) {
    register int rawWord2 __asm__("$2");
    register int rawWord3 __asm__("$3");
    register int rawWord4 __asm__("$4");
    register int rawWord5 __asm__("$5");
    register int rawWord6 __asm__("$6");
    register int rawWord7 __asm__("$7");
    register int rawWord8 __asm__("$8");
    register int rawWord9 __asm__("$9");
    register int rawWord10 __asm__("$10");
    register int rawWord11 __asm__("$11");
    register int rawWord12 __asm__("$12");
    register int rawWord13 __asm__("$13");
    register int rawWord14 __asm__("$14");
    register int rawWord15 __asm__("$15");
    volatile struct Level27_82E44Frame originalFrame;
    register int angleOrVertexOrActor16 __asm__("$16");
    register int listCursorOrRingIndex17 __asm__("$17");
    register int pointIndex18 __asm__("$18");
    register int amplitudeOrVectorOffset19 __asm__("$19");
    register int mirroredRingOrVectorOffset20 __asm__("$20");
    register int heightOrVectorOffset21 __asm__("$21");
    register int colorBytes22 __asm__("$22");
    register int retainedPrivateSubrecord23 __asm__("$23");
    register int rawAddressOrCapturedProduct24 __asm__("$24");
    long long completeTopologyProduct1,completeTopologyProduct2;
    int topologyHigh1,topologyHigh2,topologyHigh3,topologyHigh4;
    int originalPlayerFlagsPredicate;
    int angleAccumulator;
    long long completeLowProduct1;
    int completeLowCapture1;
    long long completeLowProduct2;
    int completeLowCapture2;
    long long completeLowProduct3;
    int completeLowCapture3;
    long long completeLowProduct4;
    int completeLowCapture4;
    long long completeLowProduct5;
    int completeLowCapture5;
    long long completeLowProduct6;
    int completeLowCapture6;
    long long completeDivProduct1;
    int completeHighCapture1;
    long long completeDivProduct2;
    int completeHighCapture2;
    long long completeDivProduct3;
    int completeHighCapture3;
    originalFrame.sp68=ownerParameter;
    originalFrame.sp80=0;
    rawAddressOrCapturedProduct24=Level27_82E44Field(ownerParameter,int*,0);
    originalFrame.sp70=rawAddressOrCapturedProduct24;
    rawAddressOrCapturedProduct24=350;
    __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
    originalFrame.sp88=rawAddressOrCapturedProduct24;
    rawAddressOrCapturedProduct24=originalFrame.sp70;
    rawWord2=Level27_82E44Field(rawAddressOrCapturedProduct24,int*,8);
    rawWord4=Level27_82E44Data6C409View1;
    rawWord2=Level27_82E44Field(rawWord2,int*,0);
    rawWord3=2;
    originalFrame.sp78=rawWord2;
    rawWord2=Level27_82E44Field(rawWord2,int*,40);
    retainedPrivateSubrecord23=Level27_82E44Field(rawAddressOrCapturedProduct24,int*,4);
    if(rawWord2==rawWord3){
        rawWord2=rawWord4<10;
        rawAddressOrCapturedProduct24=450;
        __asm__(""::"r"(rawAddressOrCapturedProduct24));
        originalFrame.sp88=rawAddressOrCapturedProduct24;
    }
    else{
        rawWord2=rawWord4<10;
    }
    if(rawWord2==0){
        rawWord3=rawWord4-9;
        rawWord2=rawWord3<6;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        if(rawWord2){
            rawWord2=rawWord3<<2;
        }
        else{
            rawWord3=5;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            rawWord2=rawWord3<<2;
        }
        rawWord2=rawWord2+rawWord3;
        rawAddressOrCapturedProduct24=originalFrame.sp88;
        rawWord2<<=2;
        rawAddressOrCapturedProduct24=rawAddressOrCapturedProduct24-rawWord2;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        originalFrame.sp88=rawAddressOrCapturedProduct24;
    }
    rawWord4=(int)&originalFrame.sp18;
    rawAddressOrCapturedProduct24=originalFrame.sp68;
    __asm__ volatile("":::"$6","memory");
    rawWord6=(int)&Level27_82E44Data70328View1;
    __asm__(""::"r"(rawWord4),"r"(rawAddressOrCapturedProduct24),"r"(rawWord6));
    Level27_82E44Call4F1C8View1(rawWord4,rawAddressOrCapturedProduct24+12,rawWord6);
    rawWord2=Level27_82E44Call4EDE8View1((int)&originalFrame.sp18,0);
    rawAddressOrCapturedProduct24=originalFrame.sp70;
    rawWord5=Level27_82E44Field((int)&Level27_82E44Data70328View1,int*,8);
    rawWord4=Level27_82E44Field(rawAddressOrCapturedProduct24,int*,0);
    rawAddressOrCapturedProduct24=originalFrame.sp68;
    rawWord2=rawWord2-rawWord4;
    if(rawWord2<0)rawWord2=-rawWord2;
    rawWord3=Level27_82E44Field(rawAddressOrCapturedProduct24,int*,20);
    rawWord2=rawWord2<450;
    rawWord5=rawWord5-rawWord3;
    if (rawWord2) {
        rawWord2 = rawWord5;
        if (rawWord5 < 0) {
            rawWord2 = -rawWord2;
        }
        if (rawWord2 < 0x226) {
            rawWord2=Level27_82E44Field((int)&Level27_82E44Data70328View1,int*,36);
            originalPlayerFlagsPredicate=rawWord2;
            if(originalPlayerFlagsPredicate==0){
                rawWord2|=14;
                rawWord4=originalFrame.sp68;
                __asm__ volatile("":::"$5","memory");
                rawWord5=1;
                Level27_82E44Call3BB10View1(rawWord4,rawWord5,0);
                rawWord2=Level27_82E44Field((int)&Level27_82E44Data70328View1,int*,36);
                rawWord2|=14;
            }
            else{
                rawWord2|=14;
            }
            Level27_82E44Field((int)&Level27_82E44Data70328View1,int*,36)=rawWord2;
        }
    }
    listCursorOrRingIndex17=(int)&Level27_82E44Data6E788View1;
    goto loadOriginalNextActor;
scanOriginalNextActor:
    rawWord3=Level27_82E44Field(angleOrVertexOrActor16,short*,54);
    rawWord2=447;
    if(rawWord3!=rawWord2)goto loadOriginalNextActor;
    rawAddressOrCapturedProduct24=originalFrame.sp68;
    rawWord5=angleOrVertexOrActor16+12;
    rawWord2=Level27_82E44Call4F334View1(rawAddressOrCapturedProduct24+12,rawWord5);
    rawAddressOrCapturedProduct24=originalFrame.sp70;
    rawWord3=Level27_82E44Field(rawAddressOrCapturedProduct24,int*,0);
    rawWord2-=rawWord3;
    if(rawWord2<0)rawWord2=-rawWord2;
    rawWord2=rawWord2<450;
    rawWord6=0;
    if(rawWord2==0)goto loadOriginalNextActor;
    rawWord3=Level27_82E44Field(angleOrVertexOrActor16,int*,12);
    rawAddressOrCapturedProduct24=originalFrame.sp68;
    rawWord2=Level27_82E44Field(angleOrVertexOrActor16,int*,16);
    rawWord4=Level27_82E44Field(rawAddressOrCapturedProduct24,int*,12);
    rawWord5=Level27_82E44Field(rawAddressOrCapturedProduct24,int*,16);
    rawWord4=rawWord3-rawWord4;
    rawWord2=Level27_82E44Call4E880View1(rawWord4,rawWord2-rawWord5,rawWord6);
    rawAddressOrCapturedProduct24=originalFrame.sp68;
    rawWord4=Level27_82E44Field(rawAddressOrCapturedProduct24,unsigned char*,70);
    rawWord2=Level27_82E44Call4F264View1(rawWord4,rawWord2);
    rawWord2=rawWord2<35;
    rawWord3=0x100000;
    if(rawWord2==0)goto loadOriginalNextActor;
    rawWord2=Level27_82E44Field(angleOrVertexOrActor16,int*,24);
    rawWord2|=rawWord3;
    Level27_82E44Field(angleOrVertexOrActor16,int*,24)=rawWord2;
    rawAddressOrCapturedProduct24=originalFrame.sp68;
    rawWord2=Level27_82E44Field(rawAddressOrCapturedProduct24,unsigned char*,70);
    Level27_82E44Field(angleOrVertexOrActor16,unsigned char*,81)=rawWord2;
    if(rawWord2==0){
        rawWord2=1;
        Level27_82E44Field(angleOrVertexOrActor16,unsigned char*,81)=rawWord2;
    }
loadOriginalNextActor:
    angleOrVertexOrActor16=Level27_82E44Field(listCursorOrRingIndex17,int*,0);
    listCursorOrRingIndex17+=4;
    if(angleOrVertexOrActor16!=0)goto scanOriginalNextActor;
    __asm__("":::"$16");
    rawAddressOrCapturedProduct24=retainedPrivateSubrecord23+20;
    colorBytes22=retainedPrivateSubrecord23+1368;
    originalFrame.sp90=rawAddressOrCapturedProduct24;
    rawAddressOrCapturedProduct24=retainedPrivateSubrecord23+1432;
    originalFrame.sp98=rawAddressOrCapturedProduct24;
    rawAddressOrCapturedProduct24=retainedPrivateSubrecord23+2272;
    originalFrame.spA0=rawAddressOrCapturedProduct24;
    rawAddressOrCapturedProduct24=retainedPrivateSubrecord23+3112;
    originalFrame.spA8=rawAddressOrCapturedProduct24;
    rawAddressOrCapturedProduct24=retainedPrivateSubrecord23+3952;
    listCursorOrRingIndex17=0;
    __asm__("":"=r"(listCursorOrRingIndex17):"0"(listCursorOrRingIndex17));
    originalFrame.spB0=rawAddressOrCapturedProduct24;
    rawAddressOrCapturedProduct24=(int)&originalFrame.sp48;
    originalFrame.spC0=rawAddressOrCapturedProduct24;
    rawWord2=Level27_82E44Field(retainedPrivateSubrecord23,int*,28);
    angleAccumulator=0;
    rawWord2=(unsigned int)rawWord2<1;
    originalFrame.spB8=rawWord2;
    do {
        heightOrVectorOffset21=500;
        rawWord2=(int)0x88888889u;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        completeDivProduct1=(long long)angleAccumulator*(long long)rawWord2;
        rawWord4=(int)&originalFrame.sp40;
        rawWord5=(int)&originalFrame.sp28;
        rawAddressOrCapturedProduct24=originalFrame.sp68;
        rawWord6=0;
        originalFrame.sp40=0;
        originalFrame.sp41=0;
        rawWord7=Level27_82E44Field(rawAddressOrCapturedProduct24,unsigned char*,70);
        rawWord3=angleAccumulator>>31;
        rawWord7-=35;
        __asm__ volatile("":"=h"(completeHighCapture1):"x"(completeDivProduct1),"r"(rawWord4),"r"(rawWord5),"r"(rawWord6),"r"(rawWord7),"r"(rawWord3));
        rawAddressOrCapturedProduct24=completeHighCapture1;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        rawWord2=rawAddressOrCapturedProduct24+angleAccumulator;
        rawWord2>>=3;
        rawWord2-=rawWord3;
        rawWord7+=rawWord2;
        angleOrVertexOrActor16=rawWord7+2;
        rawWord7+=66;
        *(signed char*)&originalFrame.sp42=rawWord7;
        Level27_82E44Call4EA90View1(rawWord4,rawWord5,rawWord6);
        rawWord3=listCursorOrRingIndex17<<6;
        __asm__("":"=r"(rawWord3):"0"(rawWord3));
        rawWord4=Level27_82E44Data6C640View1;
        __asm__ volatile("":::"$24","memory");
        rawAddressOrCapturedProduct24=(int)&Level27_82E44Data658A0View1;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        rawWord2=rawWord4*12;
        rawWord3+=rawWord2;
        rawWord3&=255;
        rawWord3<<=1;
        rawWord3+=rawAddressOrCapturedProduct24;
        rawWord3=Level27_82E44Field(rawWord3,short*,0);
        __asm__("":"=r"(rawWord3):"0"(rawWord3));
        rawWord2=rawWord3*15;
        rawWord2>>=9;
        amplitudeOrVectorOffset19=rawWord2+440;
        __asm__ volatile(""::"r"(amplitudeOrVectorOffset19):"$20");
        mirroredRingOrVectorOffset20=listCursorOrRingIndex17;
        if (listCursorOrRingIndex17 >= 8) {
            rawWord2=15;
            __asm__("":"=r"(rawWord2):"0"(rawWord2));
            mirroredRingOrVectorOffset20=rawWord2-listCursorOrRingIndex17;
        }
        if (mirroredRingOrVectorOffset20 == 0) {
            amplitudeOrVectorOffset19 = amplitudeOrVectorOffset19 >> 3;
        }
        else if (mirroredRingOrVectorOffset20 == 1) {
            rawWord3=0x55555556;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            rawWord2=amplitudeOrVectorOffset19<<1;
            completeDivProduct2=(long long)rawWord2*(long long)rawWord3;
            rawWord2>>=31;
            __asm__ volatile("":"=h"(completeHighCapture2):"x"(completeDivProduct2),"r"(rawWord2));
            rawAddressOrCapturedProduct24=completeHighCapture2;
            __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
            amplitudeOrVectorOffset19=rawAddressOrCapturedProduct24-rawWord2;
        }
        rawWord4=(angleOrVertexOrActor16&255)<<1;
        rawAddressOrCapturedProduct24=(int)&Level27_82E44Data65920View1;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        rawWord2=rawWord4+rawAddressOrCapturedProduct24;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        rawAddressOrCapturedProduct24=originalFrame.sp70;
        rawWord3=Level27_82E44Field(rawWord2,short*,0);
        rawWord2=Level27_82E44Field(rawAddressOrCapturedProduct24,int*,0);
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        completeLowProduct1=(long long)rawWord3*(long long)rawWord2;
        rawAddressOrCapturedProduct24=originalFrame.sp68;
        rawWord5=Level27_82E44Field(rawAddressOrCapturedProduct24,volatile int*,12);
        __asm__ volatile("":"=l"(completeLowCapture1):"x"(completeLowProduct1));
        rawAddressOrCapturedProduct24=completeLowCapture1;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        rawWord2=rawAddressOrCapturedProduct24>>12;
        rawAddressOrCapturedProduct24=(int)&Level27_82E44Data658A0View1;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        rawWord4+=rawAddressOrCapturedProduct24;
        __asm__("":"=r"(rawWord4):"0"(rawWord4));
        rawAddressOrCapturedProduct24=originalFrame.sp70;
        rawWord5+=rawWord2;
        originalFrame.sp58=rawWord5;
        rawWord3=Level27_82E44Field(rawWord4,short*,0);
        __asm__ volatile("":::"$2","memory");
        rawWord2=Level27_82E44Field(rawAddressOrCapturedProduct24,int*,0);
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        completeLowProduct2=(long long)rawWord3*(long long)rawWord2;
        rawWord6=0;
        rawWord4=Level27_82E44Data6E020View1;
        __asm__ volatile("":"=l"(completeLowCapture2):"x"(completeLowProduct2),"r"(rawWord6));
        rawAddressOrCapturedProduct24=completeLowCapture2;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        rawWord3=rawAddressOrCapturedProduct24>>12;
        rawAddressOrCapturedProduct24=originalFrame.sp68;
        rawWord4=rawWord5-rawWord4;
        rawWord2=Level27_82E44Field(rawAddressOrCapturedProduct24,int*,16);
        rawWord5=Level27_82E44Data6E024View1;
        rawWord2+=rawWord3;
        rawWord5=rawWord2-rawWord5;
        *(int*)&originalFrame.sp5C=rawWord2;
        rawWord2=Level27_82E44Call4E880View1(rawWord4,rawWord5,rawWord6);
        rawWord4=Level27_82E44Data6E040View1;
        rawWord5=rawWord2;
        rawWord4<<=16;
        __asm__("":"=r"(rawWord4):"0"(rawWord4));
        rawWord2=Level27_82E44Call4F264View1(rawWord4>>20,rawWord5);
        rawWord2=rawWord2<81;
        pointIndex18=0;
        if(rawWord2==0){
            rawAddressOrCapturedProduct24=originalFrame.sp68;
            rawWord5=(int)&Level27_82E44Data6E020View1;
            rawWord2=Level27_82E44Call4F334View1(rawAddressOrCapturedProduct24+12,rawWord5);
            rawAddressOrCapturedProduct24=originalFrame.sp70;
            rawWord3=Level27_82E44Field(rawAddressOrCapturedProduct24,int*,0);
            rawWord2+=4000;
            rawWord2=rawWord2<rawWord3;
            if(rawWord2){
                rawAddressOrCapturedProduct24=1;
                originalFrame.sp80=rawAddressOrCapturedProduct24;
            }
            pointIndex18=0;
        }
        rawWord2 = (angleOrVertexOrActor16 & 0xFF) * 2;
        rawAddressOrCapturedProduct24=(int)&Level27_82E44Data65920View1;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        rawAddressOrCapturedProduct24=rawWord2+rawAddressOrCapturedProduct24;
        originalFrame.spC8=rawAddressOrCapturedProduct24;
        rawAddressOrCapturedProduct24=(int)&Level27_82E44Data658A0View1;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        rawAddressOrCapturedProduct24=rawWord2+rawAddressOrCapturedProduct24;
        originalFrame.spD0=rawAddressOrCapturedProduct24;
    buildOriginalNextPoint:
        rawWord3=0x2aaaaaab;
        __asm__("":"=r"(rawWord3):"0"(rawWord3));
        rawWord2=pointIndex18<<8;
        completeDivProduct3=(long long)rawWord2*(long long)rawWord3;
        rawWord2>>=31;
        __asm__ volatile("":"=h"(completeHighCapture3):"x"(completeDivProduct3),"r"(rawWord2));
        rawAddressOrCapturedProduct24=completeHighCapture3;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        rawWord4=rawAddressOrCapturedProduct24-rawWord2;
        rawWord2 = 0x80 - ((rawWord4 + 0x80) & 0xFF);
        if (rawWord2 < 0) {
            rawWord2 = -rawWord2;
        }
        rawWord5 = amplitudeOrVectorOffset19;
        if (rawWord2 < 0x15) {
            __asm__("":"=r"(rawWord5):"0"(rawWord5));
            rawWord5*=4;
        }
        rawWord3=rawWord4<<1;
        rawAddressOrCapturedProduct24=(int)&Level27_82E44Data65920View1;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        rawWord2=rawWord3+rawAddressOrCapturedProduct24;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        originalFrame.sp48=0;
        rawWord2=Level27_82E44Field(rawWord2,short*,0);
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        completeLowProduct3=(long long)rawWord2*(long long)rawWord5;
        __asm__ volatile("":"=l"(completeLowCapture3):"x"(completeLowProduct3));
        rawAddressOrCapturedProduct24=completeLowCapture3;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        rawWord2=rawAddressOrCapturedProduct24>>12;
        rawAddressOrCapturedProduct24=(int)&Level27_82E44Data658A0View1;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        rawWord3+=rawAddressOrCapturedProduct24;
        __asm__("":"=r"(rawWord3):"0"(rawWord3));
        originalFrame.sp4C=rawWord2;
        rawWord2=Level27_82E44Field(rawWord3,short*,0);
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        completeLowProduct4=(long long)rawWord2*(long long)rawWord5;
        __asm__ volatile("":"=l"(completeLowCapture4):"x"(completeLowProduct4));
        rawAddressOrCapturedProduct24=completeLowCapture4;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        rawWord2=rawAddressOrCapturedProduct24>>12;
        rawWord3=rawWord2-heightOrVectorOffset21;
        rawWord2=mirroredRingOrVectorOffset20<2;
        *(int*)&originalFrame.sp50=rawWord3;
        if(rawWord2==0)heightOrVectorOffset21>>=2;
        rawWord2=rawWord3<(-500);
        if(rawWord2){
            rawWord2=-500;
            originalFrame.sp50=rawWord2;
        }
        Level27_82E44Call4ED6CView1((int)&originalFrame.sp28, originalFrame.spC0, originalFrame.spC0);
        angleOrVertexOrActor16=((listCursorOrRingIndex17*6)+pointIndex18)*12;
        rawAddressOrCapturedProduct24=originalFrame.sp90;
        rawWord6=originalFrame.spC0;
        angleOrVertexOrActor16=rawAddressOrCapturedProduct24+angleOrVertexOrActor16;
        __asm__("":"=r"(angleOrVertexOrActor16):"0"(angleOrVertexOrActor16));
        rawAddressOrCapturedProduct24=originalFrame.sp68;
        rawWord4=angleOrVertexOrActor16;
        Level27_82E44Call4F194View1(rawWord4,rawAddressOrCapturedProduct24+12,rawWord6);
        rawAddressOrCapturedProduct24=originalFrame.spC8;
        rawWord3=Level27_82E44Field(rawAddressOrCapturedProduct24,short*,0);
        rawAddressOrCapturedProduct24=originalFrame.sp70;
        rawWord2=Level27_82E44Field(rawAddressOrCapturedProduct24,int*,0);
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        completeLowProduct5=(long long)rawWord3*(long long)rawWord2;
        rawWord2=Level27_82E44Field(angleOrVertexOrActor16,volatile int*,0);
        __asm__ volatile("":"=l"(completeLowCapture5):"x"(completeLowProduct5));
        rawAddressOrCapturedProduct24=completeLowCapture5;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        rawWord3=rawAddressOrCapturedProduct24>>12;
        rawWord2+=rawWord3;
        Level27_82E44Field(angleOrVertexOrActor16,int*,0)=rawWord2;
        rawAddressOrCapturedProduct24=originalFrame.spD0;
        rawWord3=Level27_82E44Field(rawAddressOrCapturedProduct24,short*,0);
        rawAddressOrCapturedProduct24=originalFrame.sp70;
        rawWord2=Level27_82E44Field(rawAddressOrCapturedProduct24,int*,0);
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        completeLowProduct6=(long long)rawWord3*(long long)rawWord2;
        pointIndex18++;
        rawWord2=Level27_82E44Field(angleOrVertexOrActor16,volatile int*,4);
        __asm__ volatile("":"=l"(completeLowCapture6):"x"(completeLowProduct6));
        rawAddressOrCapturedProduct24=completeLowCapture6;
        __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
        rawWord3=rawAddressOrCapturedProduct24>>12;
        rawWord2+=rawWord3;
        Level27_82E44Field(angleOrVertexOrActor16,int*,4)=rawWord2;
        if (pointIndex18 < 6) {
            goto buildOriginalNextPoint;
        }
        listCursorOrRingIndex17 += 1;
        angleAccumulator += 0x46;
    }
    while (listCursorOrRingIndex17 < 0x10);
    pointIndex18 = 0;
    heightOrVectorOffset21 = 0x24;
    mirroredRingOrVectorOffset20 = 0x18;
    amplitudeOrVectorOffset19 = 0x480;
    do {
        rawAddressOrCapturedProduct24=originalFrame.sp90;
        angleOrVertexOrActor16=rawAddressOrCapturedProduct24+amplitudeOrVectorOffset19;
        rawWord4=angleOrVertexOrActor16;
        listCursorOrRingIndex17=rawAddressOrCapturedProduct24+mirroredRingOrVectorOffset20;
        Level27_82E44Call4F1C8View1(rawWord4,listCursorOrRingIndex17,rawAddressOrCapturedProduct24+heightOrVectorOffset21);
        Level27_82E44Call4F194View1(angleOrVertexOrActor16, angleOrVertexOrActor16, listCursorOrRingIndex17);
        heightOrVectorOffset21 += 0x48;
        mirroredRingOrVectorOffset20 += 0x48;
        pointIndex18 += 1;
        amplitudeOrVectorOffset19 += 0xC;
    }
    while (pointIndex18 < 0x10);
    rawAddressOrCapturedProduct24=originalFrame.sp90;
    rawWord2=-1;
    Level27_82E44Field(rawAddressOrCapturedProduct24,int*,1344)=rawWord2;
    rawAddressOrCapturedProduct24=originalFrame.spB8;
    if(rawAddressOrCapturedProduct24!=0){
        rawWord2=192;
        rawWord3=96;
        rawWord4=48;
        __asm__(""::"r"(rawWord2),"r"(rawWord3),"r"(rawWord4));
        Level27_82E44Field(colorBytes22,unsigned char*,0)=rawWord2;
        Level27_82E44Field(colorBytes22,unsigned char*,1)=rawWord2;
        Level27_82E44Field(colorBytes22,unsigned char*,4)=rawWord2;
        Level27_82E44Field(colorBytes22,unsigned char*,8)=rawWord2;
        Level27_82E44Field(colorBytes22,unsigned char*,12)=rawWord2;
        Level27_82E44Field(colorBytes22,unsigned char*,16)=rawWord2;
        Level27_82E44Field(colorBytes22,unsigned char*,20)=rawWord2;
        Level27_82E44Field(colorBytes22,unsigned char*,24)=rawWord2;
        Level27_82E44Field(colorBytes22,unsigned char*,25)=rawWord2;
        rawWord2=24;
        __asm__("":"=r"(rawWord2):"0"(rawWord2));
        Level27_82E44Field(colorBytes22,unsigned char*,2)=0;
        Level27_82E44Field(colorBytes22,unsigned char*,5)=rawWord3;
        Level27_82E44Field(colorBytes22,unsigned char*,6)=0;
        Level27_82E44Field(colorBytes22,unsigned char*,9)=rawWord4;
        Level27_82E44Field(colorBytes22,unsigned char*,10)=0;
        Level27_82E44Field(colorBytes22,unsigned char*,13)=0;
        Level27_82E44Field(colorBytes22,unsigned char*,14)=0;
        Level27_82E44Field(colorBytes22,unsigned char*,17)=rawWord4;
        Level27_82E44Field(colorBytes22,unsigned char*,18)=0;
        Level27_82E44Field(colorBytes22,unsigned char*,21)=rawWord3;
        Level27_82E44Field(colorBytes22,unsigned char*,22)=0;
        Level27_82E44Field(colorBytes22,unsigned char*,26)=0;
        Level27_82E44Field(colorBytes22,unsigned char*,28)=rawWord3;
        Level27_82E44Field(colorBytes22,unsigned char*,29)=rawWord2;
        Level27_82E44Field(colorBytes22,unsigned char*,30)=0;
        Level27_82E44Field(colorBytes22,unsigned char*,32)=0;
        Level27_82E44Field(colorBytes22,unsigned char*,33)=0;
        Level27_82E44Field(colorBytes22,unsigned char*,34)=0;
        Level27_82E44Field(colorBytes22,unsigned char*,36)=rawWord2;
        Level27_82E44Field(colorBytes22,unsigned char*,37)=rawWord4;
        Level27_82E44Field(colorBytes22,unsigned char*,38)=rawWord3;
        Level27_82E44Field(colorBytes22,unsigned char*,40)=0;
        Level27_82E44Field(colorBytes22,unsigned char*,41)=0;
        Level27_82E44Field(colorBytes22,unsigned char*,42)=0;
    }
    listCursorOrRingIndex17 = 0;
    rawWord10=0x2aaaaaab;
    __asm__("":"=r"(rawWord10):"0"(rawWord10));
    rawWord11 = 6;
    rawWord8 = 0;
    rawWord12 = originalFrame.sp98;
    rawWord13 = originalFrame.spA0;
    rawWord14 = originalFrame.spA8;
    rawWord15 = originalFrame.spB0;
    do {
        pointIndex18 = 0;
        rawWord9=rawWord11;
        __asm__("":"=r"(rawWord9):"0"(rawWord9));
        rawWord5=1;
        rawWord7 = rawWord11;
        rawWord6 = rawWord8;
    buildOriginalNextTopology:
        rawWord4 = rawWord13;
        if ((unsigned int) (pointIndex18 - 2) < 2U) {
            rawWord13 += 8;
        }
        else if ((pointIndex18 == 1) || (rawWord4 = rawWord14, (pointIndex18 == 4))) {
            rawWord4 = rawWord12;
            rawWord12 += 8;
        }
        else {
            rawWord14 += 8;
        }
        if (pointIndex18 < 3) {
            rawWord2=Level27_82E44Data6C640View1;
            rawWord2&=4;
            completeTopologyProduct1=(long long)rawWord5*(long long)rawWord10;
            if(rawWord2){
                rawWord3=rawWord5>>31;
                Level27_82E44Field(rawWord4, signed char *, 1) = rawWord6;
                Level27_82E44Field(rawWord4, signed char *, 0) = rawWord7;
                __asm__ volatile("":"=h"(topologyHigh1):"x"(completeTopologyProduct1),"r"(rawWord3),"m"(Level27_82E44Field(rawWord4,signed char*,1)),"m"(Level27_82E44Field(rawWord4,signed char*,0)));
                rawAddressOrCapturedProduct24=topologyHigh1;
                __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
                rawWord3=rawAddressOrCapturedProduct24-rawWord3;
                rawWord2=rawWord3*6;
                rawWord2=rawWord5-rawWord2;
                rawWord3=rawWord8+rawWord2;
                rawWord2=rawWord9+rawWord2;
                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                __asm__("":"=r"(rawWord2):"0"(rawWord2));
                Level27_82E44Field(rawWord4, signed char *, 3) = rawWord3;
                Level27_82E44Field(rawWord4, signed char *, 2) = rawWord2;
            }
            else {
                rawWord3=rawWord5>>31;
                Level27_82E44Field(rawWord4, signed char *, 0) = rawWord6;
                Level27_82E44Field(rawWord4, signed char *, 1) = rawWord7;
                __asm__ volatile("":"=h"(topologyHigh2):"x"(completeTopologyProduct1),"r"(rawWord3),"m"(Level27_82E44Field(rawWord4,signed char*,0)),"m"(Level27_82E44Field(rawWord4,signed char*,1)));
                rawAddressOrCapturedProduct24=topologyHigh2;
                __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
                rawWord3=rawAddressOrCapturedProduct24-rawWord3;
                rawWord2=rawWord3*6;
                rawWord2=rawWord5-rawWord2;
                rawWord3=rawWord8+rawWord2;
                rawWord2=rawWord9+rawWord2;
                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                __asm__("":"=r"(rawWord2):"0"(rawWord2));
                Level27_82E44Field(rawWord4, signed char *, 2) = rawWord3;
                Level27_82E44Field(rawWord4, signed char *, 3) = rawWord2;
            }
            Level27_82E44Field(rawWord4, signed char *, 5) = pointIndex18;
            Level27_82E44Field(rawWord4, signed char *, 7) = rawWord5;
            Level27_82E44Field(rawWord4, signed char *, 4) = pointIndex18;
            Level27_82E44Field(rawWord4, signed char *, 6) = rawWord5;
        }
        else {
            rawWord2=Level27_82E44Data6C640View1;
            rawWord2&=4;
            completeTopologyProduct2=(long long)rawWord5*(long long)rawWord10;
            if(rawWord2){
                rawWord3=rawWord5>>31;
                Level27_82E44Field(rawWord4, signed char *, 2) = rawWord6;
                Level27_82E44Field(rawWord4, signed char *, 3) = rawWord7;
                __asm__ volatile("":"=h"(topologyHigh3):"x"(completeTopologyProduct2),"r"(rawWord3),"m"(Level27_82E44Field(rawWord4,signed char*,2)),"m"(Level27_82E44Field(rawWord4,signed char*,3)));
                rawAddressOrCapturedProduct24=topologyHigh3;
                __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
                rawWord3=rawAddressOrCapturedProduct24-rawWord3;
                rawWord2=rawWord3*6;
                rawWord2=rawWord5-rawWord2;
                rawWord3=rawWord8+rawWord2;
                rawWord2=rawWord9+rawWord2;
                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                __asm__("":"=r"(rawWord2):"0"(rawWord2));
                Level27_82E44Field(rawWord4, signed char *, 0) = rawWord3;
                Level27_82E44Field(rawWord4, signed char *, 1) = rawWord2;
            }
            else {
                rawWord3=rawWord5>>31;
                Level27_82E44Field(rawWord4, signed char *, 3) = rawWord6;
                Level27_82E44Field(rawWord4, signed char *, 2) = rawWord7;
                __asm__ volatile("":"=h"(topologyHigh4):"x"(completeTopologyProduct2),"r"(rawWord3),"m"(Level27_82E44Field(rawWord4,signed char*,3)),"m"(Level27_82E44Field(rawWord4,signed char*,2)));
                rawAddressOrCapturedProduct24=topologyHigh4;
                __asm__("":"=r"(rawAddressOrCapturedProduct24):"0"(rawAddressOrCapturedProduct24));
                rawWord3=rawAddressOrCapturedProduct24-rawWord3;
                rawWord2=rawWord3*6;
                rawWord2=rawWord5-rawWord2;
                rawWord3=rawWord8+rawWord2;
                rawWord2=rawWord9+rawWord2;
                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                __asm__("":"=r"(rawWord2):"0"(rawWord2));
                Level27_82E44Field(rawWord4, signed char *, 1) = rawWord3;
                Level27_82E44Field(rawWord4, signed char *, 0) = rawWord2;
            }
            Level27_82E44Field(rawWord4, signed char *, 7) = pointIndex18;
            Level27_82E44Field(rawWord4, signed char *, 5) = rawWord5;
            Level27_82E44Field(rawWord4, signed char *, 6) = pointIndex18;
            Level27_82E44Field(rawWord4, signed char *, 4) = rawWord5;
        }
        rawWord5 += 1;
        rawWord7 += 1;
        pointIndex18 += 1;
        rawWord6 += 1;
        if (pointIndex18 < 6) {
            goto buildOriginalNextTopology;
        }
        rawWord11 += 6;
        listCursorOrRingIndex17 += 1;
        rawWord8 += 6;
    }
    while (listCursorOrRingIndex17 < 0xF);
    pointIndex18 = 0;
    rawWord9=7;
    rawWord8=8;
    __asm__("":"=r"(rawWord9):"0"(rawWord9));
    __asm__("":"=r"(rawWord8):"0"(rawWord8));
    rawWord7 = 0x61;
    rawWord6 = 8;
    rawWord5 = 2;
    rawWord3 = rawWord15 + 4;
    do {
        rawWord4 = pointIndex18 + 0x60;
        if (Level27_82E44Data6C640View1 & 4) {
            Level27_82E44Field(rawWord3, signed char *, -2) = rawWord5;
            Level27_82E44Field(rawWord15,unsigned char*,0) = rawWord4;
            Level27_82E44Field(rawWord3, signed char *, -1) = rawWord6;
            Level27_82E44Field(rawWord3, signed char *, -3) = rawWord7;
        }
        else {
            Level27_82E44Field(rawWord3, signed char *, -1) = rawWord5;
            Level27_82E44Field(rawWord3, signed char *, -3) = rawWord4;
            Level27_82E44Field(rawWord3, signed char *, -2) = rawWord6;
            Level27_82E44Field(rawWord15,unsigned char*,0) = rawWord7;
        }
        Level27_82E44Field(rawWord3, signed char *, 3) = rawWord9;
        Level27_82E44Field(rawWord3, signed char *, 1) = rawWord8;
        Level27_82E44Field(rawWord3, signed char *, 2) = rawWord9;
        Level27_82E44Field(rawWord3, signed char *, 0) = rawWord8;
        rawWord3 += 8;
        rawWord15 += 8;
        __asm__("":"=r"(rawWord15):"0"(rawWord15));
        rawWord7 += 1;
        rawWord6 += 6;
        pointIndex18 += 1;
        rawWord5 += 6;
    }
    while (pointIndex18 < 0xF);
    Level27_82E44Field(rawWord12,int*,0) = -1;
    Level27_82E44Field(rawWord13,int*,0) = -1;
    Level27_82E44Field(rawWord14,int*,0) = -1;
    Level27_82E44Field(rawWord15,int*,0) = -1;
    rawWord2=Level27_82E44Field(retainedPrivateSubrecord23,int*,0);
    if(rawWord2==0){
        rawWord5=colorBytes22;
        rawWord4=originalFrame.sp90;
        rawWord6=originalFrame.spA0;
        rawAddressOrCapturedProduct24=originalFrame.sp78;
        rawWord2=(int)Level27_82E44Call50B00View1(rawWord4,rawWord5,rawWord6,rawAddressOrCapturedProduct24+184,1);
        Level27_82E44Field(retainedPrivateSubrecord23,int*,0)=rawWord2;
    }
    rawWord2=Level27_82E44Field(retainedPrivateSubrecord23,int*,4);
    if(rawWord2==0){
        rawWord5=colorBytes22;
        rawWord4=originalFrame.sp90;
        rawWord6=originalFrame.sp98;
        rawAddressOrCapturedProduct24=originalFrame.sp78;
        rawWord2=(int)Level27_82E44Call50B00View1(rawWord4,rawWord5,rawWord6,rawAddressOrCapturedProduct24+176,1);
        Level27_82E44Field(retainedPrivateSubrecord23,int*,4)=rawWord2;
    }
    rawWord2=Level27_82E44Field(retainedPrivateSubrecord23,int*,8);
    if(rawWord2==0){
        rawWord5=colorBytes22;
        rawWord4=originalFrame.sp90;
        rawWord6=originalFrame.spA8;
        rawAddressOrCapturedProduct24=originalFrame.sp78;
        rawWord2=(int)Level27_82E44Call50B00View1(rawWord4,rawWord5,rawWord6,rawAddressOrCapturedProduct24+168,1);
        Level27_82E44Field(retainedPrivateSubrecord23,int*,8)=rawWord2;
    }
    rawWord2=Level27_82E44Field(retainedPrivateSubrecord23,int*,12);
    if(rawWord2==0){
        rawWord5=colorBytes22;
        rawWord4=originalFrame.sp90;
        rawAddressOrCapturedProduct24=originalFrame.sp78;
        rawWord6=originalFrame.spB0;
        rawWord7=rawAddressOrCapturedProduct24+192;
        rawWord2=Level27_82E44Field(rawAddressOrCapturedProduct24,unsigned short*,198);
        rawWord3=Level27_82E44Field(rawAddressOrCapturedProduct24,unsigned short*,238);
        rawWord2|=32;
        rawWord3|=32;
        Level27_82E44Field(rawAddressOrCapturedProduct24,unsigned short*,198)=rawWord2;
        Level27_82E44Field(rawAddressOrCapturedProduct24,unsigned short*,238)=rawWord3;
        rawWord2=(int)Level27_82E44Call50B00View1(rawWord4,rawWord5,rawWord6,rawWord7,1);
        Level27_82E44Field(retainedPrivateSubrecord23,int*,12)=rawWord2;
    }
    rawWord2=Level27_82E44Field(retainedPrivateSubrecord23,int*,16);
    if(rawWord2==0){
        rawWord5=colorBytes22+8;
        rawWord4=originalFrame.sp90;
        rawAddressOrCapturedProduct24=originalFrame.sp78;
        rawWord6=originalFrame.spB0;
        rawWord7=rawAddressOrCapturedProduct24+200;
        rawWord2=Level27_82E44Field(rawAddressOrCapturedProduct24,unsigned short*,206);
        rawWord3=Level27_82E44Field(rawAddressOrCapturedProduct24,unsigned short*,246);
        rawWord2|=64;
        rawWord3|=64;
        Level27_82E44Field(rawAddressOrCapturedProduct24,unsigned short*,206)=rawWord2;
        Level27_82E44Field(rawAddressOrCapturedProduct24,unsigned short*,246)=rawWord3;
        rawWord2=(int)Level27_82E44Call50B00View1(rawWord4,rawWord5,rawWord6,rawWord7,1);
        Level27_82E44Field(retainedPrivateSubrecord23,int*,16)=rawWord2;
    }
    if(Level27_82E44Data6C640View1&2){
        rawWord3=Level27_82E44Field(retainedPrivateSubrecord23,int*,0);
        if(rawWord3){
            rawAddressOrCapturedProduct24=originalFrame.sp78;
            rawWord2=rawAddressOrCapturedProduct24+184;
            Level27_82E44Field(rawWord3,int*,12)=rawWord2;
        }
        rawWord3=Level27_82E44Field(retainedPrivateSubrecord23,int*,4);
        if(rawWord3){
            rawAddressOrCapturedProduct24=originalFrame.sp78;
            rawWord2=rawAddressOrCapturedProduct24+176;
            Level27_82E44Field(rawWord3,int*,12)=rawWord2;
        }
        rawWord3=Level27_82E44Field(retainedPrivateSubrecord23,int*,8);
        if(rawWord3){
            rawAddressOrCapturedProduct24=originalFrame.sp78;
            rawWord2=rawAddressOrCapturedProduct24+168;
            Level27_82E44Field(rawWord3,int*,12)=rawWord2;
        }
        rawWord3=Level27_82E44Field(retainedPrivateSubrecord23,int*,12);
        if(rawWord3){
            rawAddressOrCapturedProduct24=originalFrame.sp78;
            rawWord2=rawAddressOrCapturedProduct24+192;
            Level27_82E44Field(rawWord3,int*,12)=rawWord2;
        }
        rawWord3=Level27_82E44Field(retainedPrivateSubrecord23,int*,16);
        if(rawWord3){
            rawAddressOrCapturedProduct24=originalFrame.sp78;
            rawWord2=rawAddressOrCapturedProduct24+200;
            goto storeOriginalFinalPointer;
        }
    }
    else{
        rawWord3=Level27_82E44Field(retainedPrivateSubrecord23,int*,0);
        if(rawWord3){
            rawAddressOrCapturedProduct24=originalFrame.sp78;
            rawWord2=rawAddressOrCapturedProduct24+224;
            Level27_82E44Field(rawWord3,int*,12)=rawWord2;
        }
        rawWord3=Level27_82E44Field(retainedPrivateSubrecord23,int*,4);
        if(rawWord3){
            rawAddressOrCapturedProduct24=originalFrame.sp78;
            rawWord2=rawAddressOrCapturedProduct24+216;
            Level27_82E44Field(rawWord3,int*,12)=rawWord2;
        }
        rawWord3=Level27_82E44Field(retainedPrivateSubrecord23,int*,8);
        if(rawWord3){
            rawAddressOrCapturedProduct24=originalFrame.sp78;
            rawWord2=rawAddressOrCapturedProduct24+208;
            Level27_82E44Field(rawWord3,int*,12)=rawWord2;
        }
        rawWord3=Level27_82E44Field(retainedPrivateSubrecord23,int*,12);
        if(rawWord3){
            rawAddressOrCapturedProduct24=originalFrame.sp78;
            rawWord2=rawAddressOrCapturedProduct24+232;
            Level27_82E44Field(rawWord3,int*,12)=rawWord2;
        }
        rawWord3=Level27_82E44Field(retainedPrivateSubrecord23,int*,16);
        if(rawWord3){
            rawAddressOrCapturedProduct24=originalFrame.sp78;
            rawWord2=rawAddressOrCapturedProduct24+240;
            goto storeOriginalFinalPointer;
        }
        goto continueOriginalPrivateUpdate;
        storeOriginalFinalPointer:Level27_82E44Field(rawWord3,int*,12)=rawWord2;
    }
    continueOriginalPrivateUpdate:;
    rawAddressOrCapturedProduct24=originalFrame.sp70;
    rawWord2=Level27_82E44Field(rawAddressOrCapturedProduct24,int*,0);
    rawAddressOrCapturedProduct24=originalFrame.sp88;
    rawWord2=rawWord2+rawAddressOrCapturedProduct24;
    __asm__("":"=r"(rawWord2):"0"(rawWord2));
    rawAddressOrCapturedProduct24=originalFrame.sp70;
    Level27_82E44Field(rawAddressOrCapturedProduct24,int*,0)=rawWord2;
    rawWord2=rawWord2<32001;
    if(rawWord2!=0){
        rawAddressOrCapturedProduct24=originalFrame.sp80;
        if(rawAddressOrCapturedProduct24==0)goto finishOriginalInvocation;
    }
    {
        rawWord4 = Level27_82E44Field(retainedPrivateSubrecord23, int*, 0);
        if (rawWord4 != 0) {
            Level27_82E44Call50B88View1(rawWord4);
        }
        rawWord4 = Level27_82E44Field(retainedPrivateSubrecord23, int*, 4);
        if (rawWord4 != 0) {
            Level27_82E44Call50B88View1(rawWord4);
        }
        rawWord4 = Level27_82E44Field(retainedPrivateSubrecord23, int*, 8);
        if (rawWord4 != 0) {
            Level27_82E44Call50B88View1(rawWord4);
        }
        rawWord4 = Level27_82E44Field(retainedPrivateSubrecord23, int*, 0xC);
        if (rawWord4 != 0) {
            Level27_82E44Call50B88View1(rawWord4);
        }
        rawWord4 = Level27_82E44Field(retainedPrivateSubrecord23, int*, 0x10);
        if (rawWord4 != 0) {
            Level27_82E44Call50B88View1(rawWord4);
        }
        Level27_82E44Call55B18View1(originalFrame.sp68);
    }
    finishOriginalInvocation:;
}
#undef Level27_82E44Field

