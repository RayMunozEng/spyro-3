#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_13/animation", func_level_13_80088BDC);

extern unsigned char Callback13Values[] __asm__("D_8006FCF0");
extern unsigned char Callback13Flags[] __asm__("D_8006FCE6");
extern int Callback13Word8006E530 __asm__("D_8006E530");
extern int Callback13Word8006E52C __asm__("D_8006E52C");
extern int Callback13Word8006E344 __asm__("D_8006E344");
void Callback13Call80049590(void) __asm__("func_80049590");
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80089E88 callback.
 * Reuses verified22 child/vector path and verified21 table/flag producers.
 * Original13 supplies selector scope, independent case19 flag store, private
 * pointer S0, changed flag S3, source S2 and copy S1; standalone vectors SP18/28.
 * Private+30 child, child+38 halfword and byte source offsets24/-74/58 follow
 * original instructions. Table stride2C/flags10 and signed division preserved.
 * Empty constraints emit no instructions; retain original scheduling/lifetimes.
 * Units, helper meanings, audio semantics and update cadence remain unresolved.
 * Falsifiable acceptance: all original code/internal jumps/table words, strict
 * complete translation unit, complete EXE and every overlay retail hash.
 */
extern Spyro Callback13Player __asm__("D_80070328");
int Callback13Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback13Call80041930(void) __asm__("func_80041930");
void Callback13Call80041C20(void) __asm__("func_80041C20");
void Callback13Call80042A44(void) __asm__("func_80042A44");
void Callback13Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback13Word8006E538 __asm__("D_8006E538");
extern int D_8006C648;
int Callback13Query(Vector3D*,int) __asm__("func_8001A358");
extern unsigned char* Callback13Table[] __asm__("D_8006EE2C");
extern unsigned char Callback13Source[] __asm__("D_80070328+0x74");
extern int D_80071908;
extern Vector3D D_80071918;
void Callback13Call8004F110(Vector3D*,int) __asm__("func_8004F110");
int Callback13Call80038000(Moby*,Vector3D*,int,int,int) __asm__("func_80038000");
void Callback13Call8004F1C8(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004F1C8");
void Callback13Call8003BE70(int) __asm__("func_8003BE70");
void func_level_13_80089E88(void) {
    Vector3D localVector;
    int reserved;
    Vector3D copyVector;
    register Moby* descriptorMoby __asm__("$2");
    register unsigned int selector __asm__("$16");


    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    register int flagOffset __asm__("$3");
    switch(Callback13Player.animationState) {
    case 0x14:
    case 0x64:
        if(func_800438F4()==0)func_80043728();
        Callback13Call80041C20();
        Callback13Player.unk9a=0;
        goto call42A44;
    case 0x67:
    case 0x69:
    case 0x6C:
        Callback13Call80041C20();
call42A44:
        Callback13Call80042A44();
clearSharedValue:
        Callback13Player.unk4[0]=0;
        return;
    case 0x66:
        Callback13Call80041C20();
        Callback13Call80042A44();
        descriptorMoby=Callback13Player.critterMobyPtr;
        __asm__ volatile("" : "=r"(descriptorMoby) : "0"(descriptorMoby) : "memory");
        Callback13Player.unk4[0]=0;
        goto descriptorTail;
    case 0x65:
        func_800438F4();
        Callback13Call80041C20();
        Callback13Call80042A44();
        Callback13Call80041930();
        goto queryC00;
    case 0x1D:
    case 0x68:
        Callback13Call80041C20();
        Callback13Call80042A44();
queryC00:
        Callback13Call80043A38(0xC00);
        goto clearSharedValue;
    case 0x19:
        Callback13Call80041C20();
        Callback13Call80042A44();
        Callback13Call80041930();
        Callback13Call80049590();
        if (Callback13Player.movementState==MOVEMENT_STATE_SUPERCHARGE && SpawnParticle!=0)
            SpawnParticle(1,9,0,0);
        if(Callback13Player.unk7a[3].z<0 && Callback13Player.animationStateFrames>=4)
            {Callback13Player.unk5=1;
            __asm__ volatile("" : : : "memory");}
        else if(Callback13Player.unk5==0 && !(Callback13Word8006E538 & 0x40))
            Callback13Player.unk5=2;
        goto clearSharedValue;
    case 0x1C:
    case 0x6B:
        Callback13Call80041C20();
        Callback13Call80042A44();
        Callback13Call80041930();
        if(Callback13Player.unk7a[3].z<0 && Callback13Player.animationStateFrames>=4)
            Callback13Player.unk5=1;
        goto clearSharedValue;
    case 0x26:
        Callback13Call80041C20();
        Callback13Call80042A44();
        descriptor=&Callback13Player.unk22[2];
        if (Callback13Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback13Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setDecreasingFlag;
            tableValue=decreasingValue-0xC8;
            goto storeDecreasingValue;
            }
            goto setDecreasingFlag;
storeDecreasingValue:
            *(int*)(Callback13Values + valueOffset) = tableValue;
setDecreasingFlag:
            flagOffset = *descriptor * 0x2C;
            Callback13Flags[flagOffset] = Callback13Flags[flagOffset] | 0x10;
            __asm__ volatile("" : : : "memory");
        }
        goto clearSharedValue;
    case 0x3A:
        Callback13Call80041C20();
        Callback13Call80042A44();
        Callback13Player.cheatColour.a=255;
        Callback13Player.unk4[0]=0;
        Callback13Player.cheatColour.b=32;
        Callback13Player.cheatColour.g=32;
        Callback13Player.cheatColour.r=32;
        return;
    case 0x3D:
        Callback13Call80041C20();
        Callback13Call80042A44();
        Callback13Call80043A38(0xC00);
        Callback13Call80049590();
        if(SpawnParticle!=0)SpawnParticle(1,9,0,0);
        Callback13Word8006E530=120;
        Callback13Player.unk4[0]=0;
        Callback13Word8006E52C=4;
        if(Callback13Word8006E344==0 && Callback13Call8003BF6C((int)D_8006C654->supercharge,Callback13Player.unk22[2])==0) {
            Callback13Player.unk22[2]=PlaySound((int)D_8006C654->supercharge,0,4);
            Callback13Player.unk22[3]=(int)D_8006C654->supercharge;
        }
        break;
    case 0x6A:
    case 0x6D: {
        register unsigned char* privateData __asm__("$16")=Callback13Player.critterMobyPtr->mobyTag;
        register int changed __asm__("$19")=0;
        register Vector3D* copyBase __asm__("$17");
        register unsigned char* sourceBase __asm__("$18");
        register int queryHeight __asm__("$16");
        if(*(Moby**)(privateData+0x30)!=0) {
            sourceBase=Callback13Source;
            func_8004F178((&localVector),(Vector3D*)sourceBase);
            Callback13Call8004F110((&localVector),6);
            {
                Moby* child=*(Moby**)(privateData+0x30);
                child->position.z+=((int)((unsigned int)*(unsigned short*)((unsigned char*)child+0x38)<<16))>>17;
            }
            func_8004F194((&localVector),(&localVector),(Vector3D*)((unsigned char*)*(Moby**)(privateData+0x30)+0xC));
            copyBase=&copyVector;
            func_8004F178(copyBase,(&localVector));
            {
                int height=((int)((unsigned int)*(unsigned short*)((unsigned char*)*(Moby**)(privateData+0x30)+0x38)<<16))>>17;
                register int result=Callback13Call80038000(*(Moby**)(privateData+0x30),(&localVector),height,height,0x1022);
                register Vector3D* childVector __asm__("$4")=(&localVector);
                if(result!=0) {
                    register Vector3D* childCopy __asm__("$6")=copyBase;
                    {register Moby* childArgument __asm__("$5")=*(Moby**)(privateData+0x30);
                    __asm__ volatile("" : "=r"(changed) : "0"(changed) : "memory");
                    changed=1;
                    Callback13Call8004F1C8(childVector,(Vector3D*)((unsigned char*)childArgument+0xC),childCopy);}
                    func_8004F0E8((&localVector),6);
                    func_8004F194((Vector3D*)sourceBase,(Vector3D*)sourceBase,(&localVector));
                }
            }
            Callback13Call80041C20();
            {register Vector3D* argument0 __asm__("$4")=(Vector3D*)(sourceBase+0x24);
            if(changed!=0) {
                register int componentX __asm__("$8")=localVector.x;
                register int divisor __asm__("$2")=D_8006C648;
                register int componentY __asm__("$7");
                register int componentZ __asm__("$3");
                componentX/=divisor;
                __asm__("" : "=r"(componentX) : "0"(componentX));
                componentY=localVector.y/divisor;
                __asm__("" : "=r"(componentY) : "0"(componentY));
                componentZ=localVector.z/divisor;
                __asm__ volatile("" : "=r"(componentZ), "=r"(argument0) : "0"(componentZ), "1"(argument0) : "memory");
                localVector.x=componentX;
                localVector.y=componentY;
                localVector.z=componentZ;
                Callback13Call8004F1C8(argument0,argument0,(&localVector));
            }}
            {register Moby* child __asm__("$2")=*(Moby**)(privateData+0x30);
            register int childValue __asm__("$3")=*(short*)((unsigned char*)child+0x38);
            register int playerValue __asm__("$2")=Callback13Player.unk4a;
            playerValue+=childValue;
            __asm__("" : "=r"(playerValue) : "0"(playerValue));
            queryHeight=playerValue+64;}
            if(Callback13Query((Vector3D*)(sourceBase-0x74),queryHeight)!=0 && Callback13Player.unk7a[2].z<=0) {
                if(Callback13Player.unk7a[2].z>=-2047)
                    Callback13Player.position.z=D_80071908+queryHeight-64;
                Callback13Player.ticksSinceLastSurfaceTouch=0;
                func_8004F178((Vector3D*)(sourceBase+0x58),&D_80071918);
            } else {
                register int* counterPointer __asm__("$2")=&Callback13Player.ticksSinceLastSurfaceTouch;
                register int counterValue __asm__("$3");
                register int vectorZ __asm__("$4");
                __asm__("" : "=r"(counterPointer) : "0"(counterPointer));
                Callback13Player.unk9e.x=0;
                Callback13Player.unk9e.y=0;
                counterValue=*counterPointer;
                __asm__ volatile("" : "=r"(counterPointer) : "0"(counterPointer) : "memory");
                vectorZ=4096;
                Callback13Player.unk9e.z=vectorZ;
                counterValue+=1;
                *counterPointer=counterValue;
            }
        } else Callback13Call80041C20();
        Callback13Player.unk4[0]=0;
        if(Callback13Player.animationState!=0x6A)return;
        descriptorMoby=Callback13Player.critterMobyPtr;
descriptorTail:
        selector=Callback13Table[descriptorMoby->mobyClass][6];
        if(selector!=(unsigned int)Callback13Player.unk22[3]) {
            if(Callback13Call8003BF6C(Callback13Player.unk22[3],Callback13Player.unk22[2])!=0)
                Callback13Call8003BE70(Callback13Player.unk22[2]);
            Callback13Player.unk22[2]=-1;
        }
        Callback13Player.unk22[3]=selector;
        if(Callback13Call8003BF6C(selector,Callback13Player.unk22[2])==0)
            Callback13Player.unk22[2]=PlaySound(Callback13Player.unk22[3],0,4);
        return;
    }
    default:
        return;
    }
}


#define LEVEL_ID 13
#define PlaySpyroSounds_level_13 func_level_13_8008A5E4
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_13_8008A750(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x14:
    case 0x1d:
    case 0x3a:
    case 0x3d:
    case 0x64:
    case 0x65:
    case 0x68:
    case 0x69:
    case 0x6c:
    case 0x6d:
        func_80043ABC(&spyro.unk9e);
        break;
    case 0x1c:
    case 0x66:
    case 0x67:
    case 0x6a:
    case 0x6b:
        func_80043ABC(0);
        break;
    case 0x19:
        func_80043E00((Vector3D*)((char*)&spyro + 0x8C));
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008A7E8.
 * Reuses verified21 numeric1D/state9/B/3D, verified37 vector1C/DC0/damage200,
 * verified22 special64..6D. Original13 shared15/22/C descriptor call remains
 * at1C; 244/250 tail follows3D. Offsets are bytes, original widths/shifts and
 * branches retained. Empty constraints emit no opcodes and retain lifetimes.
 * Require every code/internal jump/owned dispatch word and complete retail
 * hashes. Helper/audio meanings, units, cadence and live parity remain open.
 */
extern short Signed13TableA[] __asm__("D_800658A0");
extern short Signed13TableB[] __asm__("D_80065920");
void Transition13_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");
extern Spyro Transition13_D_80070328 __asm__("D_80070328");
int Transition13_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition13_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition13_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition13RawUnion[] __asm__("D_80070328+0x144");
extern int Transition13RawMovement __asm__("D_80070328+0x50");
extern void (*Call13Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw13State[] __asm__("D_80070328+0x50");
extern short Signed13TableA[] __asm__("D_800658A0");
extern short Signed13TableB[] __asm__("D_80065920");

extern int D_80071934;
int Transition13_func_8003636C(int,int) __asm__("func_8003636C");
void Transition13_func_800441F0(void) __asm__("func_800441F0");
void Transition13_func_80043A38(int) __asm__("func_80043A38");
void func_80047138(void);
void func_level_13_8008A7E8(int arg0){
    register Vector3D* destination __asm__("$4");



    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");
    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    switch(arg0){
    case 0x14:
        Transition13_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition13_D_80070328.unk5 = 0;
        Transition13_func_800441F0();
        Transition13_D_80070328.grounded = 1;
        Transition13_D_80070328.union144.a.unk13cb = Transition13_func_8003636C(1, 3);
        Transition13_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x1D: {
        register int oldState __asm__("$4")=Transition13RawMovement;
        register int first __asm__("$3")=Transition13_D_80070328.unk17e.x;
        register int second __asm__("$2");
        register int third __asm__("$3");
        __asm__("" : "=r"(oldState),"=r"(first) : "0"(oldState),"1"(first) : "memory");
        second=7;
        __asm__("" : "=r"(second) : "0"(second));
        Transition13RawMovement=second;
        __asm__ volatile("" : : : "memory");
        second=Transition13_D_80070328.unk17e.y;
        __asm__ volatile("" : "=r"(second) : "0"(second) : "memory");
        Transition13_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(first) : "0"(first) : "memory");
        first<<=6;
        __asm__("" : "=r"(first) : "0"(first));
        Transition13_D_80070328.unk7a[2].x=first;
        __asm__ volatile("" : : : "memory");
        third=Transition13_D_80070328.unk17e.z;
        second<<=6;
        Transition13_D_80070328.union144.a.unk13cb=oldState;
        Transition13_D_80070328.unk7a[2].y=second;
        second=third<<6;
        if(third==0)second=Transition13_D_80070328.unk7a[3].z;
        Transition13_D_80070328.unk7a[2].z=second;
        Transition13_func_80043A38(0xC00);
        Transition13_D_80070328.grounded=1;
        Transition13_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        soundSelector=D_8006C654->spyroHurt;
        soundZero=0;
        goto sharedSound;
        goto clearPointers;
    }

    case 0x19:
        Transition13_D_80070328.movementState = MOVEMENT_STATE_SUPERCHARGE;
        Transition13_D_80070328.unk13a[0] = 0x60000;
        Transition13_D_80070328.unk5 = 0;
        Transition13_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition13_D_80070328.grounded = 0;
        Transition13_D_80070328.unk15b = 1;
        soundSelector=D_8006C654->jump;
        soundZero=0;
        goto sharedSound;
    case 0x1C:
        savedBase = Transition13RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Transition13RawMovement;
        Transition13RawMovement = MOVEMENT_STATE_HURT;
        Transition13_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Transition13_D_80070328.unk8[0] = Transition13_func_8004EDE8(sourceC, 0);
        Transition13_D_80070328.unk7a[2].z = 0xDC0;
        Transition13_D_80070328.grounded = 0;
        Transition13_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        soundZero=0;
        if (Transition13_D_80070328.damageFlags & 0x200) {
            Transition13_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition13_D_80070328.union144.a.unk13cc = 1;
            soundSelector=D_8006C654->lavaBurn;
sharedSound:
            PlaySound(soundSelector,(Moby*)soundZero,0);
        }
        goto clearPointers;
    case 0x3A:
        Transition13_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition13_D_80070328.unk5 = 0;
        Transition13_func_80043A38(0xC00);
        Transition13_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition13_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x26:
        Transition13_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        if (Transition13_D_80070328.animationState == 0x2A) {
            Transition13_D_80070328.unk5 = 2;
        }
        Transition13_func_8004F168((Vector3D *) ((unsigned char*)&Transition13_D_80070328.movementState + 0xFC));
        Transition13_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition13_D_80070328.unk8[0] = Transition13_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition13_D_80070328.movementState + 0x48), 0);
        Transition13_D_80070328.grounded = 1;
        Transition13_D_80070328.unk4a = 0x280;
        return;
    case 0x3D:
        Transition13_D_80070328.movementState = MOVEMENT_STATE_SUPERCHARGE;
        Transition13_D_80070328.unk5 = 0;
        Transition13_D_80070328.unk13a[0] = 0x60000;
        Transition13_D_80070328.unk8[0] = Transition13_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition13_D_80070328.movementState + 0x48), 0);
        Transition13_D_80070328.horizontalSpeed = 0x1E80;
        Transition13_func_80043A38(0xC00);
        Transition13_D_80070328.grounded = 1;
        if ((Transition13_D_80070328.unk13f[0] != 0) || (Transition13_D_80070328.spitState != 0) || (Transition13_D_80070328.unk17t != 6)) {
            if (((unsigned) (Transition13_D_80070328.unk13f[0] - 3) < 2U) || (Transition13_D_80070328.unk13f[0] == 5)) {
                Transition13_D_80070328.unk13f[0] = 5;
            } else {
                Transition13_D_80070328.unk13f[0] = 0;
            }
            Transition13_D_80070328.spitState = 0;
            Transition13_D_80070328.unk17t = 6;
            func_80047138();
        }
clearPointers:
        Transition13_D_80070328.unk20a=0;
        Transition13_D_80070328.critterMobyPtr=0;
        return;
    case 0x64:
    case 0x6D:
        Transition13_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition13_D_80070328.unk5 = 0;
        Transition13_func_800441F0();
        Transition13_D_80070328.grounded = 1;
        return;
    case 0x65:
        Transition13_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition13_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((unsigned char*)(unsigned char*)&Transition13_D_80070328.movementState + 0x3C), (Vector3D *) ((unsigned char*)(unsigned char*)&Transition13_D_80070328.movementState + 0x48));
            Transition13_D_80070328.unk5 = 1;
        } else {
            Transition13_D_80070328.unk5 = 0;
        }
        Transition13_D_80070328.unk8[0] = Transition13_func_8004EDE8(&Transition13_D_80070328.unk7a[3], 0);
        Transition13_func_80043A38(0xC00);
        Transition13_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition13_D_80070328.grounded = 1;
        goto clearSpecialTail;
    case 0x69:
        Transition13_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition13_D_80070328.unk5 = 0;
        Transition13_func_80043A38(0xC00);
        Transition13_D_80070328.grounded = 1;
        goto clearDeathFlag;
    case 0x66:case 0x67:case 0x6A:
        stateBaseA=Raw13State;
        __asm__("" : "=r"(stateBaseA) : "0"(stateBaseA));
        destination=(Vector3D*)(stateBaseA+0x48);
        *(int*)stateBaseA=3;
        Transition13_D_80070328.unk8[0]=Transition13_func_8004EDE8(destination,0);
        Transition13_D_80070328.unk15b=1;
        Transition13_D_80070328.grounded=0;
        Transition13_D_80070328.union144.a.unk13cb=0x14;
clearSpecialTail:
        Transition13_D_80070328.idle=0;
        Transition13_D_80070328.unk15g=0;
        return;
    case 0x6B:
        savedBase = Transition13RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Transition13RawMovement;
        Transition13RawMovement = MOVEMENT_STATE_HURT;
        Transition13_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Transition13_D_80070328.unk8[0] = Transition13_func_8004EDE8(sourceC, 0);
        Transition13_D_80070328.unk7a[2].z = 0xDC0;
        Transition13_D_80070328.grounded = 0;
        Transition13_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Transition13_D_80070328.damageFlags & 0x200) {
            Transition13_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition13_D_80070328.union144.a.unk13cc = 1;
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        return;
    case 0x6C:
        Transition13_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition13_D_80070328.unk5 = 0;
        Transition13_func_80043A38(0xC00);
        Transition13_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
clearDeathFlag:
        Transition13_D_8006E524 = 0xF;
        return;
    case 0x68: {
        register int previousMovement __asm__("$2")=Transition13RawMovement;
        register int kind __asm__("$3");
        register int flags __asm__("$3");
        register unsigned char* unionPointer __asm__("$5");
        __asm__("" : "=r"(previousMovement) : "0"(previousMovement));
        kind=7;
        __asm__("" : "=r"(kind) : "0"(kind));
        Transition13RawMovement=kind;
        __asm__ volatile("" : : : "memory");
        flags=Transition13_D_80070328.unk17a;
        __asm__ volatile("" : "=r"(flags) : "0"(flags) : "memory");
        unionPointer=Transition13RawUnion;
        __asm__("" : "=r"(flags),"=r"(unionPointer) : "0"(flags),"1"(unionPointer));
        Transition13_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(flags) : "0"(flags) : "memory");
        *(int*)unionPointer=previousMovement;
        if(flags&0x400){
            sourceC=(Vector3D*)(unionPointer-0xB8);
            func_8004F178(sourceC,(Vector3D*)(unionPointer+0xD8));
            Transition13_func_8004F0E8(sourceC,6);
        }else if(Transition13_D_80070328.unk22[5]>=0){
            tableOffsetOrValue=Transition13_D_80070328.unk22[5]*2;
            tableValueA=*(short*)((unsigned char*)Signed13TableB+tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            Transition13_D_80070328.unk7a[2].x=tableValueA>>1;
            tableOffsetOrValue=*(short*)((unsigned char*)Signed13TableA+tableOffsetOrValue);
            Transition13_D_80070328.unk7a[2].z=0;
            __asm__ volatile("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Transition13_D_80070328.unk7a[2].y=tableOffsetOrValue>>1;
        }else Transition13_func_8004F168((Vector3D*)(unionPointer-0xB8));
        destination=&Transition13_D_80070328.unk7a[1];
        func_8004F178(destination,(Vector3D*)((unsigned char*)destination+0xC));
        Transition13_D_80070328.grounded=1;
        Transition13_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        return;
    }
    default:return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_13/animation", func_level_13_8008AFCC);
