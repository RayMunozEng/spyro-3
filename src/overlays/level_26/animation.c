extern unsigned char Raw26Union[] __asm__("D_80070328+0x144");
extern int Raw26Movement __asm__("D_80070328+0x50");
extern short Signed26A[] __asm__("D_800658A0");
extern short Signed26B[] __asm__("D_80065920");
#include "common.h"
#include "ovl_header.h"
#include "drawutil.h"
#include "spu.h"
#include "hud.h"
#include "mobyutil.h"
#include "stdutil.h"
#include "camera.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_26/animation", func_level_26_80088AD8);

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80089710.
 * Reuses verified13 child/vector and descriptor routes; original26 selectors
 * 64..6D and shared numeric tails preserved. Byte offsets private30 child,
 * child38 halfword, source74+24/-74/+58 and descriptor table6 remain numeric.
 * Signed halfword-2/0/2 maps-1/0/1 via original16/17 shifts. Division vector
 * -7/0/7 by2 gives-3/0/3; original zero/overflow traps retained.
 * Empty constraints emit no instructions. All original code/internal jumps/
 * dispatch words, strict full TU and every original EXE/overlay hash required.
 * Units, helper meanings, audio semantics, cadence and live parity remain open.
 */
extern Spyro Callback26Player __asm__("D_80070328");
int Callback26Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback26Call80041930(void) __asm__("func_80041930");
void Callback26Call80041C20(void) __asm__("func_80041C20");
void Callback26Call80042A44(void) __asm__("func_80042A44");
void Callback26Call80043A38(int scale) __asm__("func_80043A38");
extern int D_8006C648;
int Callback26Query(Vector3D*,int) __asm__("func_8001A358");
extern unsigned char* Callback26Table[] __asm__("D_8006EE2C");
extern unsigned char Callback26Source[] __asm__("D_80070328+0x74");
extern int D_80071908;
extern Vector3D D_80071918;
void Callback26Call8004F110(Vector3D*,int) __asm__("func_8004F110");
int Callback26Call80038000(Moby*,Vector3D*,int,int,int) __asm__("func_80038000");
void Callback26Call8004F1C8(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004F1C8");
void Callback26Call8003BE70(int) __asm__("func_8003BE70");
void func_level_26_80089710(void) {
    Vector3D localVector;
    int reserved;
    Vector3D copyVector;
    register Moby* descriptorMoby __asm__("$2");
    register unsigned int selector __asm__("$16");


    switch(Callback26Player.animationState) {
    case 0x64:
        if(func_800438F4()==0)func_80043728();
        Callback26Call80041C20();
        Callback26Player.unk9a=0;
        goto call42A44;
    case 0x67:
    case 0x69:
    case 0x6C:
        Callback26Call80041C20();
call42A44:
        Callback26Call80042A44();
clearSharedValue:
        Callback26Player.unk4[0]=0;
        return;
    case 0x66:
        Callback26Call80041C20();
        Callback26Call80042A44();
        descriptorMoby=Callback26Player.critterMobyPtr;
        __asm__ volatile("" : "=r"(descriptorMoby) : "0"(descriptorMoby) : "memory");
        Callback26Player.unk4[0]=0;
        goto descriptorTail;
    case 0x65:
        func_800438F4();
        Callback26Call80041C20();
        Callback26Call80042A44();
        Callback26Call80041930();
        goto queryC00;
    case 0x68:
        Callback26Call80041C20();
        Callback26Call80042A44();
queryC00:
        Callback26Call80043A38(0xC00);
        goto clearSharedValue;
    case 0x6B:
        Callback26Call80041C20();
        Callback26Call80042A44();
        Callback26Call80041930();
        if(Callback26Player.unk7a[3].z<0 && Callback26Player.animationStateFrames>=4)
            Callback26Player.unk5=1;
        goto clearSharedValue;
    case 0x6A:
    case 0x6D: {
        register unsigned char* privateData __asm__("$16")=Callback26Player.critterMobyPtr->mobyTag;
        register int changed __asm__("$19")=0;
        register Vector3D* copyBase __asm__("$17");
        register unsigned char* sourceBase __asm__("$18");
        register int queryHeight __asm__("$16");
        if(*(Moby**)(privateData+0x30)!=0) {
            sourceBase=Callback26Source;
            func_8004F178((&localVector),(Vector3D*)sourceBase);
            Callback26Call8004F110((&localVector),6);
            {
                Moby* child=*(Moby**)(privateData+0x30);
                child->position.z+=((int)((unsigned int)*(unsigned short*)((unsigned char*)child+0x38)<<16))>>17;
            }
            func_8004F194((&localVector),(&localVector),(Vector3D*)((unsigned char*)*(Moby**)(privateData+0x30)+0xC));
            copyBase=&copyVector;
            func_8004F178(copyBase,(&localVector));
            {
                int height=((int)((unsigned int)*(unsigned short*)((unsigned char*)*(Moby**)(privateData+0x30)+0x38)<<16))>>17;
                register int result=Callback26Call80038000(*(Moby**)(privateData+0x30),(&localVector),height,height,0x1022);
                register Vector3D* childVector __asm__("$4")=(&localVector);
                if(result!=0) {
                    register Vector3D* childCopy __asm__("$6")=copyBase;
                    {register Moby* childArgument __asm__("$5")=*(Moby**)(privateData+0x30);
                    __asm__ volatile("" : "=r"(changed) : "0"(changed) : "memory");
                    changed=1;
                    Callback26Call8004F1C8(childVector,(Vector3D*)((unsigned char*)childArgument+0xC),childCopy);}
                    func_8004F0E8((&localVector),6);
                    func_8004F194((Vector3D*)sourceBase,(Vector3D*)sourceBase,(&localVector));
                }
            }
            Callback26Call80041C20();
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
                Callback26Call8004F1C8(argument0,argument0,(&localVector));
            }}
            {register Moby* child __asm__("$2")=*(Moby**)(privateData+0x30);
            register int childValue __asm__("$3")=*(short*)((unsigned char*)child+0x38);
            register int playerValue __asm__("$2")=Callback26Player.unk4a;
            playerValue+=childValue;
            __asm__("" : "=r"(playerValue) : "0"(playerValue));
            queryHeight=playerValue+64;}
            if(Callback26Query((Vector3D*)(sourceBase-0x74),queryHeight)!=0 && Callback26Player.unk7a[2].z<=0) {
                if(Callback26Player.unk7a[2].z>=-2047)
                    Callback26Player.position.z=D_80071908+queryHeight-64;
                Callback26Player.ticksSinceLastSurfaceTouch=0;
                func_8004F178((Vector3D*)(sourceBase+0x58),&D_80071918);
            } else {
                register int* counterPointer __asm__("$2")=&Callback26Player.ticksSinceLastSurfaceTouch;
                register int counterValue __asm__("$3");
                register int vectorZ __asm__("$4");
                __asm__("" : "=r"(counterPointer) : "0"(counterPointer));
                Callback26Player.unk9e.x=0;
                Callback26Player.unk9e.y=0;
                counterValue=*counterPointer;
                __asm__ volatile("" : "=r"(counterPointer) : "0"(counterPointer) : "memory");
                vectorZ=4096;
                Callback26Player.unk9e.z=vectorZ;
                counterValue+=1;
                *counterPointer=counterValue;
            }
        } else Callback26Call80041C20();
        Callback26Player.unk4[0]=0;
        if(Callback26Player.animationState!=0x6A)return;
        descriptorMoby=Callback26Player.critterMobyPtr;
descriptorTail:
        selector=Callback26Table[descriptorMoby->mobyClass][6];
        if(selector!=(unsigned int)Callback26Player.unk22[3]) {
            if(Callback26Call8003BF6C(Callback26Player.unk22[3],Callback26Player.unk22[2])!=0)
                Callback26Call8003BE70(Callback26Player.unk22[2]);
            Callback26Player.unk22[2]=-1;
        }
        Callback26Player.unk22[3]=selector;
        if(Callback26Call8003BF6C(selector,Callback26Player.unk22[2])==0)
            Callback26Player.unk22[2]=PlaySound(Callback26Player.unk22[3],0,4);
        return;
    }
    default:
        return;
    }
}




#define LEVEL_ID 26
#define PlaySpyroSounds_level_26 func_level_26_80089BC4
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_26_80089CEC(int index) {
    Vector3D* position;
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x64: case 0x65: case 0x68: case 0x69: case 0x6C: case 0x6D:
        position = &spyro.unk9e;
        break;
    case 0x66: case 0x67: case 0x6A: case 0x6B:
        position = 0;
        break;
    default: return;
    }
    func_80043ABC(position);
}

extern Spyro Callback26_D_80070328 __asm__("D_80070328");
extern short Callback26_D_800658A0[], Callback26_D_80065920[] __asm__("D_800658A0");
int Callback26_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Callback26_func_80043A38(int scale) __asm__("func_80043A38");
void Callback26_func_800441F0(void) __asm__("func_800441F0");
void Callback26_func_8004F0E8(Vector3D*, int) __asm__("func_8004F0E8");
void Callback26_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Callback26_D_8006E524 __asm__("D_8006E524");

void func_level_26_80089D68(int arg0) {
    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* savedBase __asm__("$3");
    register unsigned char* hurtBase __asm__("$5");
    register Vector3D* destination __asm__("$4");
    register int flags __asm__("$3");
    register int hurtState __asm__("$3");
    register Vector3D *sourceA __asm__("$16");
    register Vector3D *sourceB __asm__("$16");
    register int savedMovementA __asm__("$6");
    register int savedMovementB __asm__("$2");

    switch (arg0) {
    case 0x64:
    case 0x6D:
        Callback26_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback26_D_80070328.unk5 = 0;
        Callback26_func_800441F0();
        Callback26_D_80070328.grounded = 1;
        return;
    case 0x65:
        Callback26_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Callback26_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((unsigned char*)&Callback26_D_80070328.movementState + 0x3C), (Vector3D *) ((unsigned char*)&Callback26_D_80070328.movementState + 0x48));
            Callback26_D_80070328.unk5 = 1;
        } else {
            Callback26_D_80070328.unk5 = 0;
        }
        Callback26_D_80070328.unk8[0] = Callback26_func_8004EDE8(&Callback26_D_80070328.unk7a[3], 0);
        Callback26_func_80043A38(0xC00);
        Callback26_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Callback26_D_80070328.grounded = 1;
        goto clearTail;
    case 0x69:
        Callback26_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Callback26_D_80070328.unk5 = 0;
        Callback26_func_80043A38(0xC00);
        Callback26_D_80070328.grounded = 1;
        goto storeCommonValue;
    case 0x66:
    case 0x67:
    case 0x6A:
        Callback26_D_80070328.movementState = MOVEMENT_STATE_FALL;
        Callback26_D_80070328.unk8[0] = Callback26_func_8004EDE8((Vector3D *) ((unsigned char*)&Callback26_D_80070328.movementState + 0x48), 0);
        Callback26_D_80070328.unk15b = 1;
        Callback26_D_80070328.grounded = 0;
        Callback26_D_80070328.union144.a.unk13cb = 0x14;
clearTail:
        Callback26_D_80070328.idle = 0;
        Callback26_D_80070328.unk15g = 0;
        return;
    case 0x6B:
        savedBase = Raw26Union;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceA = (Vector3D*)(savedBase - 0xAC);
        savedMovementA = Raw26Movement;
        Raw26Movement = MOVEMENT_STATE_HURT;
        Callback26_D_80070328.unk5 = 0;
        *(int*)savedBase = savedMovementA;
        func_8004F178(destination, sourceA);
        Callback26_D_80070328.unk8[0] = Callback26_func_8004EDE8(sourceA, 0);
        Callback26_D_80070328.unk7a[2].z = 0xDC0;
        Callback26_D_80070328.grounded = 0;
        Callback26_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Callback26_D_80070328.damageFlags & 0x200) {
            Callback26_D_80070328.union144.a.unk13cc = 0;
            return;
        }
        Callback26_D_80070328.union144.a.unk13cc = 1;
        PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        return;
    case 0x6C:
        Callback26_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Callback26_D_80070328.unk5 = 0;
        Callback26_func_80043A38(0xC00);
        Callback26_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
storeCommonValue:
        Callback26_D_8006E524 = 0xF;
        return;
    case 0x68:
        savedMovementB = Raw26Movement;
        __asm__("" : "=r"(savedMovementB) : "0"(savedMovementB));
        hurtState = 7;
        Raw26Movement = hurtState;
        flags = Callback26_D_80070328.unk17a;
        __asm__("" : "=r"(flags) : "0"(flags));
        hurtBase = Raw26Union;
        __asm__("" : "=r"(hurtBase) : "0"(hurtBase));
        Callback26_D_80070328.unk5 = 0;
        __asm__ __volatile__("" : "=r"(flags) : "0"(flags) : "memory");
        *(int*)hurtBase = savedMovementB;
        if (flags & 0x400) {
            sourceB = (Vector3D*)(hurtBase - 0xB8);
            func_8004F178(sourceB, (Vector3D *) (hurtBase + 0xD8));
            Callback26_func_8004F0E8(sourceB, 6);
        } else if (Callback26_D_80070328.unk22[5] >= 0) {
            tableOffsetOrValue = Callback26_D_80070328.unk22[5] * 2;
            tableValueA = *(short*)((unsigned char*)Signed26B + tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            Callback26_D_80070328.unk7a[2].x = tableValueA >> 1;
            tableOffsetOrValue = *(short*)((unsigned char*)Signed26A + tableOffsetOrValue);
            Callback26_D_80070328.unk7a[2].z = 0;
            __asm__ __volatile__("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Callback26_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
        } else {
            Callback26_func_8004F168((Vector3D*)(hurtBase - 0xB8));
        }
        func_8004F178(&Callback26_D_80070328.unk7a[1], (Vector3D*)((unsigned char*)&Callback26_D_80070328.unk7a[1] + 0xC));
        Callback26_D_80070328.grounded = 1;
        Callback26_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }

    default:
        return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_26/animation", func_level_26_8008A144);
