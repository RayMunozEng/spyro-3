#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_14/animation", func_level_14_80093F80);

/* AI generated; not human reviewed. SCUS-94467 800960DC..80096870.
 * Verified11 shared table/flag and23 saved-vector case47 paths reused only
 * against original14 instructions. Original14 supplies1B/3C word71934/71908,
 * signed Moby38 halfword and private2 threshold/arithmetic chain. Numeric widths,
 * helper meaning,units/cadence unresolved. Original80096418..80096574 controls
 * stack18 copy, saved S0 status71934, source71908, signed Moby+38 and private+2.
 * Thresholds11F9/10CD and signed limits160/40 retain original units unknown.
 * Empty constraints preserve argument/load/branch-delay lifetimes; unused V0
 * result after1D helper establishes no return meaning. Six reserved stack words
 * retain originalframe60 without inventing accesses or source variable meanings.
 * Every code/table word, strict fullTU and every EXE/overlay hash required.
 */
extern Spyro Callback14Player __asm__("D_80070328");
int Callback14Call80037058(int x, int y) __asm__("func_80037058");
void Callback14Call80041930(void) __asm__("func_80041930");
void Callback14Call80041AE8(void) __asm__("func_80041AE8");
void Callback14Call80041C20(void) __asm__("func_80041C20");
void Callback14Call80042A44(void) __asm__("func_80042A44");
void Callback14Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback14Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38,D_8006C648;
extern int D_80071924;
extern int** Callback14Table __asm__("D_8006D048+0x14");
int Callback14Call80055E84(Moby*) __asm__("func_80055E84");
void Callback14Call8004ED6C(void*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
void Callback14Call8001BA30(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int Callback14Call80019138(Vector3D*,int,int,int,int,Moby*) __asm__("func_80019138");
int Callback14Call8001830C(Vector3D*,Vector3D*,int,int,Moby*) __asm__("func_8001830C");
extern int Callback14Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback14Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback14Values[] __asm__("D_8006FCF0");
void Callback14Call80049590(void) __asm__("func_80049590");
int Callback14Call8003BF6C(int,int) __asm__("func_8003BF6C");
extern int D_80071908,D_80071934;
int Callback14First42A44(void) __asm__("func_80042A44");
void func_level_14_800960DC(void) {
    struct {Vector3D first; int reserved24; Vector3D second; int reserved34; int reserved38[6];} local;
    register int computedValue __asm__("$4");
    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    int descriptorResult;
    int flagOffset;

    register int positionDelta __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback14Player.animationState) {
    case 0x14:
    case 0x41:
        if(func_800438F4()==0)func_80043728();
        Callback14Call80041C20();
        Callback14Player.unk9a=0;
        Callback14Call80042A44();
        goto clearSharedValue;
    default:
        return;
    case 0x20:
    case 0x44:
    case 0x4A:
        Callback14Call80041C20();
        Callback14Call80042A44();
        goto clearSharedValue;
    case 0x42:
    case 0x45:
        func_800438F4();
        Callback14Call80041C20();
        Callback14Call80042A44();
        Callback14Call80041930();
        goto queryC00;
    case 0x1D:
        Callback14Call80041C20();
        {register int unusedResult __asm__("$2")=Callback14First42A44();
        __asm__ volatile("" : : "r"(unusedResult));}
        goto queryC00;
    case 0x1A:
        Callback14Call80041C20();
        Callback14Call80042A44();
        goto queryC00;
    case 0x28:
    case 0x29:
    case 0x39:
        Callback14Call80041C20();
        Callback14Call80042A44();
        descriptor=&Callback14Player.unk22[2];
        if (Callback14Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback14Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=decreasingValue-0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
        }
        goto clearSharedValue;
    case 0x2A:
        Callback14Call80041C20();
        Callback14Call80042A44();
        Callback14Call80049590();
        descriptor=&Callback14Player.unk22[2];
        if (Callback14Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback14Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback14Player.unk22[2];
        }
        if (Callback14Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback14Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback14Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback14Flags[flagOffset] = Callback14Flags[flagOffset] | 0x10;
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
    case 0x4E:
    case 0x4F:
        Callback14Call80041C20();
        Callback14Call80042A44();
        Callback14Call80041AE8();
        if ((unsigned char) Callback14Player.unk10[4] != 0) {
            computedValue = -Callback14Player.unk9ha[4] - Callback14Call80037058(Callback14Player.position.x, Callback14Player.position.y);
            positionValue = Callback14Player.unk4a - computedValue;
            Callback14Player.unk4[0] = computedValue;
            positionDelta = (int) Callback14Player.union144.a.unk13cc >> 6;
            positionValue -= positionDelta;
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            Callback14Player.position.z=positionValue;
            return;
        }
        break;
    case 0x1B:
    case 0x3C: {
        register int* statusPointer __asm__("$16");
        register int belowThreshold __asm__("$2");
        register unsigned char* savedBase __asm__("$16");
        register Moby* sourceMoby __asm__("$4");
        register unsigned char* privateData __asm__("$5");
        register int inputValue __asm__("$3");
        register int halfword __asm__("$2");
        register int oldValue __asm__("$3");
        Callback14Call80041C20();
        Callback14Call80042A44();
        {register Vector3D* copyDestination __asm__("$4")=&local.first;
        __asm__("" : "=r"(copyDestination) : "0"(copyDestination));
        savedBase=(unsigned char*)&Callback14Player;
        func_8004F178(copyDestination,(Vector3D*)savedBase);}
        {register Vector3D* argument0 __asm__("$4")=(Vector3D*)savedBase;
        register Vector3D* argument1 __asm__("$5")=&local.first;
        register int argument2 __asm__("$6")=0;
        register int argument3 __asm__("$7")=0;
        __asm__("" : "=r"(argument0), "=r"(argument1), "=r"(argument2), "=r"(argument3) : "0"(argument0), "1"(argument1), "2"(argument2), "3"(argument3));
        statusPointer=&D_80071934;
        *statusPointer=0;
        local.first.z-=0x800;
        Callback14Call8001830C(argument0,argument1,argument2,argument3,Callback14Player.critterMobyPtr);}
        if(*statusPointer!=0) {
            Callback14Player.unk9ha[4]=D_80071908;
            Callback14Player.position.z=D_80071908+Callback14Player.critterMobyPtr->distanceToGround;
        } else Callback14Player.unk9ha[4]=0;
        sourceMoby=Callback14Player.critterMobyPtr;
        __asm__ volatile("" : "=r"(sourceMoby) : "0"(sourceMoby) : "memory");
        if(sourceMoby!=0 && Callback14Player.critterMobyPtr->mobyClass==0x12C) {
            inputValue=Callback14Player.unk8[1];
            privateData=sourceMoby->mobyTag;
            if(inputValue>=0x11F9) {
                halfword=*(short*)(privateData+2);
                oldValue=halfword;
                __asm__("" : "=r"(oldValue) : "0"(oldValue), "r"(halfword));
                if(halfword<160) {
                    halfword=oldValue+40;
                    *(short*)(privateData+2)=halfword;
                }
            } else {
                belowThreshold=inputValue<0x10CD;
                __asm__("" : "=r"(belowThreshold) : "0"(belowThreshold));
                if(!belowThreshold) {
                halfword=*(short*)(privateData+2);
                oldValue=halfword;
                __asm__("" : "=r"(oldValue) : "0"(oldValue), "r"(halfword));
                if(halfword<40) {
                    halfword=oldValue+40;
                    *(short*)(privateData+2)=halfword;
                }
            } else {
                halfword=*(short*)(privateData+2);
                oldValue=halfword;
                if(halfword>0) {
                    halfword=oldValue-40;
                    __asm__("" : "=r"(halfword) : "0"(halfword));
                    *(short*)(privateData+2)=halfword;
                }
            }
            }
            Callback14Player.position.z+=*(short*)(privateData+2);
        }
        goto clearSharedValue;
    }
    case 0x43:
    case 0x46:
    case 0x49:
        Callback14Call80041C20();
        Callback14Call80042A44();
        Callback14Call80041930();
        if(Callback14Player.unk7a[3].z < 0 && Callback14Player.animationStateFrames >= 4) {
            Callback14Player.unk5=1;
        } else {
            if(Callback14Player.unk5==0 && !(Callback14Word8006E538 & 0x40) && Callback14Player.union144.a.unk13cb==0)
                Callback14Player.unk5=2;
        }
        goto clearSharedValue;
    case 0x47: {
        register int progress __asm__("$4");
        register int value __asm__("$2");
        register int* sourceBase __asm__("$16");
        register Vector3D* vectorBase __asm__("$17");
        register int flags __asm__("$18");
        if(Callback14Player.ticksSinceLastSurfaceTouch) {
            Callback14Call80041C20();
            Callback14Call80042A44();
        } else {
            func_800438F4();
            Callback14Call80041C20();
            Callback14Call80042A44();
            Callback14Call80041930();
            Callback14Call80043A38(0xC00);
        }
        progress=Callback14Call80055E84(Callback14Player.critterMobyPtr);
        if(Callback14Player.critterMobyPtr->animationState.id==6 && (unsigned int)(progress-2)<6) {
            if(progress<6)value=(progress<<10)/6;
            else value=0x400;
            local.second.x=value;
            __asm__ volatile("" : : : "memory");
            sourceBase=&Callback14Player.unk4a;
            vectorBase=&local.second;
            local.second.y=0;
            local.second.z=0x200-*sourceBase;
            Callback14Call8004ED6C((unsigned char*)sourceBase-0x14,vectorBase,vectorBase);
            {register Vector3D* argument0 __asm__("$4")=vectorBase;
            register Vector3D* argument1 __asm__("$5")=vectorBase;
            __asm__("" : "=r"(argument0), "=r"(argument1) : "0"(argument0), "1"(argument1));
            sourceBase=(int*)((unsigned char*)sourceBase-0x44);
            func_8004F194(argument0,argument1,(Vector3D*)sourceBase);}
            flags=0x02000000;
            Callback14Call8001BA30(vectorBase,0x200,0,0,flags,Callback14Player.critterMobyPtr);
            if((Callback14Call80019138(vectorBase,0x200,0,0,flags,Callback14Player.critterMobyPtr)!=0 ||
                Callback14Call8001830C((Vector3D*)sourceBase,vectorBase,0,0x02000000,Callback14Player.critterMobyPtr)!=0)) {
                register int* selector __asm__("$16")=&D_80071924;
                if(func_80040954(*selector)==3) {
                    register int index __asm__("$2")=*selector;
                    register int** table __asm__("$3")=Callback14Table;
                    register int* entry __asm__("$3");
                    index &= 63;
                    entry=table[index];
                    entry[1] |= flags;
                }
            }
        }
        goto clearSharedValue;
    }
    case 0x4B:
    case 0x4C:
    case 0x4D:
        Callback14Call80041C20();
        Callback14Call80042A44();
        if(Callback14Player.unk5==1)func_800494A8();
        goto clearSharedValue;
    case 0x48:
        Callback14Call80041C20();
        Callback14Call80042A44();
        if(Callback14Player.unk5!=0)goto call41930;
queryC00:
        Callback14Call80043A38(0xC00);
        goto clearSharedValue;
call41930:
        Callback14Call80041930();
clearSharedValue:
        Callback14Player.unk4[0]=0;
        return;
    }
}


#define LEVEL_ID 14
#define PlaySpyroSounds_level_14 func_level_14_80096874
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_14_8009697C(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x43:
    case 0x44:
    case 0x46:
    case 0x49:
    case 0x4b:
    case 0x4c:
    case 0x4d:
        func_80043ABC(0);
        break;
    case 0x1b:
    case 0x3c:
        if (*(int*)((char*)&spyro + 0x50) != 6) func_80043ABC(0);
        *(int*)((char*)&spyro + 0x60) += *(int*)((char*)&spyro + 0xB4) / 96;
        break;
    case 0x47:
    case 0x48:
        {
            register int* state __asm__("$4") = (int*)((char*)&spyro + 0xB8);
            __asm__("" : "=r"(state) : "0"(state));
            if (*state) func_80043ABC(0);
            else func_80043ABC(&spyro.unk9e);
        }
        break;
    case 0x14:
    case 0x1a:
    case 0x1d:
    case 0x20:
    case 0x2b:
    case 0x2c:
    case 0x41:
    case 0x42:
    case 0x45:
    case 0x4a:
    case 0x4e:
    case 0x4f:
        func_80043ABC(&spyro.unk9e);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80096A68.
 * Verified11 water/character,37 hurt,22 squish/death,32 table,16 surface.
 * Original14 state12/scalar400, stack10/20/30 water,40 jump,50 surface and
 * shared sound after39 preserved. Numeric offsets are bytes; word60 wrap
 * vectors800/801/FFF give0/-7FF/-1, signed table-2/0/2 gives-1/0/1 for48.
 * Every invocation retains original code/internal jumps/owned table words;
 * strict complete TU and every original hash required. Helper meanings,
 * physical units, audio, cadence and live parity remain open.
 */
extern short Signed14TableB[] __asm__("D_80065920");
extern short Signed14TableA[] __asm__("D_800658A0");
extern int Raw14Yaw __asm__("D_80070328+0x64");
extern int Raw14TableIndex __asm__("D_80070328+0x298");
extern short D_800658A0[];
extern short D_80065920[];
extern int Raw14Animation __asm__("D_80070328+0x48");
extern unsigned char Raw14Union[] __asm__("D_80070328+0x144");
extern unsigned char Raw14Movement[] __asm__("D_80070328+0x50");
extern int Raw14X __asm__("D_80070328+0x8C");
extern int Raw14Word __asm__("D_80070328+0x50");
void Transition14_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");
extern Spyro Transition14_D_80070328 __asm__("D_80070328");
int Transition14_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition14_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition14_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition14RawUnion[] __asm__("D_80070328+0x144");
extern int Transition14RawMovement __asm__("D_80070328+0x50");
extern void (*Call14Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw14State[] __asm__("D_80070328+0x50");

extern int D_80071934;
int Call14A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw14NegativeWord __asm__("D_80070328+0x28");
int Transition14_func_8003636C(int,int) __asm__("func_8003636C");
void Transition14_func_800441F0(void) __asm__("func_800441F0");
void Transition14_func_80043A38(int) __asm__("func_80043A38");
void func_level_14_80096A68(int arg0){
    struct {Vector3D first; int gap1; Vector3D second; int gap2; Vector3D third; int gap3; Vector3D fourth; int gap4; Vector3D fifth;} vectors;
    register int negativeWord __asm__("$3");
    int firstResult,secondResult,firstWrappedWord,secondWrappedWord,firstParticleKind,secondParticleKind,firstParticleSubtype,secondParticleSubtype;
    register Vector3D* destination __asm__("$4");

    int lengthResult;


    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* savedBase __asm__("$3");
    int maskedValue;
    register int tableIndex __asm__("$2");
    register int tableValue __asm__("$3");
    register Vector3D *damageSource __asm__("$16");
    register Vector3D *damageDestination __asm__("$16");
    Vector3D *firstJumpSource;
    Vector3D *secondJumpSource;
    enum MovementState nextSubstate;
    register int comparisonKind __asm__("$2");
    register int previousValue __asm__("$2");
    register int firstAnimation __asm__("$3");
    register unsigned char* soundTable __asm__("$3");
    register unsigned char* unionBase __asm__("$5");
    register unsigned char* movement __asm__("$3");
    register unsigned char* initialMovement __asm__("$5");
    register void *jumpPrivate __asm__("$18");
    register void *damagePrivate __asm__("$18");
    register Vector3D* jumpVector __asm__("$16");
    register int oldMovementC __asm__("$5");
    switch(arg0){
    case 0x14:
        Transition14_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition14_D_80070328.unk5 = 0;
        Transition14_func_800441F0();
        Transition14_D_80070328.grounded = 1;
        Transition14_D_80070328.union144.a.unk13cb = Transition14_func_8003636C(1, 3);
        Transition14_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x1D: {
        register int oldState __asm__("$4")=Transition14RawMovement;
        register int first __asm__("$3")=Transition14_D_80070328.unk17e.x;
        register int second __asm__("$2");
        register int third __asm__("$3");
        __asm__("" : "=r"(oldState),"=r"(first) : "0"(oldState),"1"(first) : "memory");
        second=7;
        __asm__("" : "=r"(second) : "0"(second));
        Transition14RawMovement=second;
        second=Transition14_D_80070328.unk17e.y;
        __asm__ volatile("" : "=r"(second) : "0"(second) : "memory");
        Transition14_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(first) : "0"(first) : "memory");
        first<<=6;
        __asm__("" : "=r"(first) : "0"(first));
        Transition14_D_80070328.unk7a[2].x=first;
        third=Transition14_D_80070328.unk17e.z;
        second<<=6;
        Transition14_D_80070328.union144.a.unk13cb=oldState;
        Transition14_D_80070328.unk7a[2].y=second;
        second=third<<6;
        if(third==0)second=Transition14_D_80070328.unk7a[3].z;
        Transition14_D_80070328.unk7a[2].z=second;
        Transition14_func_80043A38(0xC00);
        Transition14_D_80070328.grounded=1;
        Transition14_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        soundSelector=D_8006C654->spyroHurt;
        soundZero=0;
        goto sharedHurtSound;
        goto clearPointers;
    }

    case 0x1A:
        savedBase = Transition14RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        oldMovementC = Transition14RawMovement;
        Transition14RawMovement = MOVEMENT_STATE_HURT;
        Transition14_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementC;
        Transition14_func_8004F168(destination);
        Transition14_D_80070328.grounded = 1;
        Transition14_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        soundSelector=D_8006C654->squish;
        soundZero=0;
        PlaySound(soundSelector,(Moby*)soundZero,0);
        goto clearPointers;
    case 0x20:
        Transition14_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition14_D_80070328.unk5 = 0;
        Transition14_func_80043A38(0xC00);
        Transition14_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition14_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition14_D_80070328.movementState - 0xB) >= 2U) && (Transition14_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition14_D_80070328.movementState - 0x50));
                if ((Transition14_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw14NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition14_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call14A358(&vectors.first, 0x800);
                    vectors.first.z = firstResult;
                    if (firstResult != 0) {
                        firstParticleKind = 6;
                        if (D_80071934 != 0) {
                            firstParticleSubtype = 0x2E;
emitFirstParticle:
                            SpawnParticle(firstParticleKind, firstParticleSubtype, &vectors.first, 0);
                        }
                    }
                }
            }
            firstWrappedWord = Transition14_D_80070328.rotation.pitch & 0xFFF;
            Transition14_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition14_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition14_D_80070328.rotation.pitch > 0) {
                Transition14_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition14_D_80070328.unk5 = 1;
            }
            Transition14_func_8004F168((Vector3D *) ((unsigned char*)&Transition14_D_80070328.rotation.pitch + 0xEC));
            Transition14_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition14_D_80070328.rotation.pitch + 0x38), 0);
            Transition14_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition14_D_80070328.animationState == 0x2A) {
            Transition14_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition14_D_80070328.union144.a.unk13da = 0;
        }
        Transition14_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition14_D_80070328.unk20a = 0;
        Transition14_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw14State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw14NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition14_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call14A358(localVector, 0x800);
                    vectors.second.z = secondResult;
                    if (secondResult != 0) {
                        secondParticleKind = 6;
                        if (D_80071934 != 0) {
                            secondParticleSubtype = 0x2E;
emitSecondParticle:
                            SpawnParticle(secondParticleKind, secondParticleSubtype, localVector, 0);
                        }
                    }
                }
            }
            if (Transition14_D_80070328.animationState == 0x2E) {
                Transition14_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition14_D_80070328.rotation.pitch & 0xFFF;
            Transition14_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition14_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition14_D_80070328.rotation.pitch > 0) {
                Transition14_D_80070328.rotation.pitch = 0;
            }
            Transition14_D_80070328.unk5 = 1;
            Transition14_func_8004F168((Vector3D *) ((unsigned char*)&Transition14_D_80070328.animationState + 0x104));
            Transition14_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition14_D_80070328.animationState + 0x50), 0);
            Transition14_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition14_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition14_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition14RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition14RawUnion;
            *(int*)unionPointer=(-Transition14_D_80070328.unk7a[2].z)>>2;
            if(Transition14RawMovement!=8){Transition14_D_80070328.union144.a.unk13cc=0x5900;Transition14RawMovement=10;}
            Transition14_D_80070328.unk5=0;
            Transition14_D_80070328.unk8[0]=Transition14_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition14_D_80070328.grounded=1;
            Transition14_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call14A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x39: {
        register int previousMovement __asm__("$2")=Transition14RawMovement;
        register int numericKind __asm__("$3");
        register int indexWord __asm__("$3");
        register unsigned char* unionPointer __asm__("$5");
        register int tableOffset __asm__("$2");
        register int tableWord __asm__("$3");
        __asm__("" : "=r"(previousMovement) : "0"(previousMovement));
        numericKind=7;
        __asm__("" : "=r"(numericKind) : "0"(numericKind));
        Transition14RawMovement=numericKind;
        __asm__ volatile("" : : : "memory");
        indexWord=Raw14TableIndex;
        __asm__ volatile("" : "=r"(indexWord) : "0"(indexWord) : "memory");
        unionPointer=Transition14RawUnion;
        __asm__("" : "=r"(indexWord),"=r"(unionPointer) : "0"(indexWord),"1"(unionPointer) : "memory");
        Transition14_D_80070328.unk5=0;
        *(int*)unionPointer=previousMovement;
        if(indexWord<0)Raw14TableIndex=((Raw14Yaw+0x800)>>4)&0xFF;
        tableOffset=Raw14TableIndex*2;
        tableWord=*(short*)((unsigned char*)Signed14TableB+tableOffset);
        destination=(Vector3D*)(unionPointer-0xC4);
        *(int*)(unionPointer-0xB8)=tableWord;
        tableOffset=*(short*)((unsigned char*)Signed14TableA+tableOffset);
        Transition14_D_80070328.unk7a[2].z=0;
        Transition14_D_80070328.unk7a[2].y=tableOffset;
        func_8004F178(destination,(Vector3D*)(unionPointer-0xB8));
        Transition14_D_80070328.grounded=1;
        Transition14_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        { register unsigned char* soundTable __asm__("$2")=(unsigned char*)D_8006C654;
        __asm__ volatile("" : "=r"(soundTable) : "0"(soundTable) : "memory");
        soundZero=0;
        soundSelector=soundTable[0x19]; }
sharedHurtSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
    }
clearPointers:
        Transition14_D_80070328.unk20a=0;
        Transition14_D_80070328.critterMobyPtr=0;
        return;
    case 0x1B:case 0x3C:
        movement=Raw14Movement;
        *(int*)movement=18;
        Transition14_D_80070328.unk5=0;
        Transition14_D_80070328.unk8[0]=Transition14_func_8004EDE8((Vector3D*)(movement+0x48),0);
        Transition14_D_80070328.grounded=1;
        Transition14_D_80070328.unk4a=0x400;
        return;
    case 0x41:
        Transition14_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition14_func_800441F0();
        Transition14_D_80070328.grounded = 1;
        return;
    case 0x42:
    case 0x45:
        Transition14_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition14_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition14_D_80070328.movementState) + 0x3C)), (Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition14_D_80070328.movementState) + 0x48)));
            Transition14_D_80070328.unk5 = MOVEMENT_STATE_WALK;
        } else {
            Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        }
        Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8(&Transition14_D_80070328.unk7a[3], 0);
        Transition14_func_80043A38(0xC00);
        Transition14_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition14_D_80070328.grounded = 1;
        goto clearFlags;
    case 0x43:
    case 0x49:
        initialMovement=Raw14Movement;
        __asm__("" : "=r"(initialMovement) : "0"(initialMovement));
        comparisonKind=10;
        __asm__("" : "=r"(comparisonKind) : "0"(comparisonKind));
        {register Moby* critter __asm__("$3")=Transition14_D_80070328.critterMobyPtr;
        register int current __asm__("$4")=*(int*)initialMovement;
        __asm__("" : "=r"(critter),"=r"(current) : "0"(critter),"1"(current));
        jumpPrivate=critter->mobyTag;
        __asm__("" : "=r"(jumpPrivate) : "0"(jumpPrivate));
        if ((current == comparisonKind) && (SpawnParticle != 0) && (Transition14_D_80070328.unk4[0] < 0)) {
            jumpVector=&vectors.fourth;
            func_8004F178(jumpVector, (Vector3D*)(initialMovement-0x50));
            vectors.fourth.z = -Transition14_D_80070328.unk4[0];
            SpawnParticle(6, 0x2E, jumpVector, 0);
            SpawnParticle(4, 0x29, jumpVector, 0);
        }
        }
        movement=Raw14Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        firstJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) firstJumpSource);
        Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8((Vector3D *) firstJumpSource, 0);
        if (arg0 == 0x49) {
            Transition14_D_80070328.unk7a[2].z = 0x2580;
        } else {
            Transition14_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)jumpPrivate+0x4C) = 0;
        }
        Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition14_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition14_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
        goto playJumpSound;
    case 0x44:
        Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        if (Transition14_D_80070328.movementState == MOVEMENT_STATE_JUMP_HOVER) {
            if(Transition14_D_80070328.animationState==0x43)Transition14_D_80070328.unk5=1;
            else if(Transition14_D_80070328.animationState==0x46)Transition14_D_80070328.unk5=Transition14_D_80070328.movementState;
            else if(Transition14_D_80070328.animationState==0x49)Transition14_D_80070328.unk5=4;
        } else {
            Transition14_D_80070328.movementState = MOVEMENT_STATE_FALL;
        }
        Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8(&Transition14_D_80070328.unk7a[3], 0);
        Transition14_D_80070328.grounded = 0;
        goto clearFlags;
    case 0x46:
        movement=Raw14Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        secondJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) secondJumpSource);
        Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8((Vector3D *) secondJumpSource, 0);
        Transition14_D_80070328.unk7a[2].z = 0x12C0;
        Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition14_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition14_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
playJumpSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
        return;
    case 0x47:
        if (Transition14_D_80070328.ticksSinceLastSurfaceTouch != 0) {
            if (Transition14_D_80070328.movementState != MOVEMENT_STATE_FALL) {
                if (Transition14_D_80070328.animationState == 0x43) {
                    Transition14_D_80070328.unk5 = MOVEMENT_STATE_WALK;
                } else if (Transition14_D_80070328.animationState == 0x46) {
                    Transition14_D_80070328.unk5 = MOVEMENT_STATE_JUMP_HOVER;
                } else {
                    Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
                }
            }
            Transition14_D_80070328.movementState = MOVEMENT_STATE_FALL;
            Transition14_D_80070328.grounded = 0;
            Transition14_D_80070328.idle = 0;
            Transition14_D_80070328.unk15g = 0;
        } else {
            Transition14_D_80070328.movementState = MOVEMENT_STATE_WALK;
            Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            Transition14_func_80043A38(0xC00);
            Transition14_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition14_D_80070328.grounded = 1;
        }
        Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8(&Transition14_D_80070328.unk7a[3], 0);
        goto clearFlags;
clearFlags:
        Transition14_D_80070328.idle = 0;
        Transition14_D_80070328.unk15g = 0;
        return;
    case 0x4E:case 0x4F: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Raw14Word;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Raw14Union;
            *(int*)unionPointer=(-Transition14_D_80070328.unk7a[2].z)>>2;
            if(Raw14Word!=8){Transition14_D_80070328.union144.a.unk13cc=0x5900;Raw14Word=10;}
            Transition14_D_80070328.unk5=0;
            Transition14_D_80070328.unk8[0]=Transition14_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition14_D_80070328.grounded=1;
            Transition14_D_80070328.unk15b=1;
            localVector=&vectors.fifth;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.fifth.z+=0x400;
            lengthResult=Call14A358(localVector,0x800);
            vectors.fifth.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        return;
    }
    case 0x48: {
        register Moby* critter __asm__("$2")=Transition14_D_80070328.critterMobyPtr;
        __asm__ volatile("" : "=r"(critter) : "0"(critter) : "memory");
        damagePrivate=critter->mobyTag;
        __asm__ volatile("" : "=r"(damagePrivate) : "0"(damagePrivate) : "memory");
        previousValue=Raw14Word;
        __asm__ volatile("" : "=r"(previousValue) : "0"(previousValue) : "memory");
        unionBase=Raw14Union;
        __asm__("" : "=r"(previousValue),"=r"(unionBase) : "0"(previousValue),"1"(unionBase));
        *(int*)unionBase=previousValue;
        Raw14Word = MOVEMENT_STATE_HURT;
        if (Transition14_D_80070328.damageFlags & 8) {
            damageSource = (Vector3D *) (unionBase - 0xAC);
            Transition14_D_80070328.unk5 = MOVEMENT_STATE_WALK;
            func_8004F178((Vector3D *) (unionBase - 0xB8), damageSource);
            Transition14_D_80070328.unk8[0] = Transition14_func_8004EDE8(damageSource, 0);
            soundTable=(unsigned char*)D_8006C654;
            soundZero=0;
            __asm__ volatile("" : "=r"(soundTable),"=r"(soundZero) : "0"(soundTable),"1"(soundZero) : "memory");
            Transition14_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)damagePrivate+0x4C) = 0;
            Transition14_D_80070328.grounded = 0;
            Transition14_D_80070328.union144.a.unk13cc = 1;
            PlaySound(soundTable[12],(Moby*)soundZero,0);
        } else {
            Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            damageDestination = (Vector3D *) (unionBase - 0xB8);
            if (Transition14_D_80070328.unk17a & 0x400) {
                func_8004F178(damageDestination, (Vector3D *) ((Vector3D *) (unionBase + 0xD8)));
                Transition14_func_8004F0E8(damageDestination, 6);
            } else if (Transition14_D_80070328.unk22[5] >= 0) {
                tableIndex=Transition14_D_80070328.unk22[5]*2;
                tableValue=*(short*)((unsigned char*)D_80065920+tableIndex);
                __asm__("" : "=r"(tableValue) : "0"(tableValue));
                Raw14X=tableValue>>1;
                tableIndex=*(short*)((unsigned char*)D_800658A0+tableIndex);
                Transition14_D_80070328.unk7a[2].z=0;
                __asm__ volatile("" : "=r"(tableIndex) : "0"(tableIndex) : "memory");
                Transition14_D_80070328.unk7a[2].y=tableIndex>>1;
            } else {
                    __asm__("" : "=r"(unionBase) : "0"(unionBase));
                Transition14_func_8004F168((Vector3D*)(unionBase-0xB8));
            }
            func_8004F178(&Transition14_D_80070328.unk7a[1], (Vector3D *) ((unsigned char*)(&Transition14_D_80070328.unk7a[1]) + 0xC));
            Transition14_func_80043A38(0xC00);
            Transition14_D_80070328.grounded = 1;
        }
        Transition14_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
        break;
    }
    case 0x4A:
        Transition14_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition14_func_80043A38(0xC00);
        Transition14_D_80070328.grounded = 1;
        Transition14_D_8006E524 = 0xF;
        return;
    case 0x4B:
        firstAnimation=Raw14Animation;
        __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        if(firstAnimation==0x44){
            if(Transition14_D_80070328.unk5==4)goto setHeadbashFlag;
            comparisonKind=0x49;
            __asm__ volatile("" : "=r"(comparisonKind) : "0"(comparisonKind) : "memory");
            firstAnimation=Raw14Animation;
            __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        }else comparisonKind=0x49;
        if(firstAnimation==comparisonKind){
setHeadbashFlag:
            Transition14_D_80070328.union144.a.unk13cc=1;
        }else Transition14_D_80070328.union144.a.unk13cc=0;
        Transition14_D_80070328.movementState = MOVEMENT_STATE_HEADBASH;
        Transition14_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition14_func_8004F168((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition14_D_80070328.movementState) + 0x3C)));
        Transition14_D_80070328.unk7a[2].z = 0x800;
        Transition14_D_80070328.grounded = 0;
        Transition14_D_80070328.unk13a[0] = 0x20000;
        Transition14_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        return;
    case 0x4C:
        Transition14_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=1;
        goto setHeadbashSubstate;
    case 0x4D:
        Transition14_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=2;
setHeadbashSubstate:
        Transition14_D_80070328.unk5=nextSubstate;
        Transition14_D_80070328.grounded=0;
        Transition14_D_80070328.unk13a[0]=0x20000;
        return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_14/animation", func_level_14_80097AD0);
