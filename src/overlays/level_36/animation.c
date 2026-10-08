extern unsigned char Raw36State[] __asm__("D_80070328+0x50");
#include "common.h"
#include "ovl_header.h"
#include "drawutil.h"
#include "spu.h"
#include "hud.h"
#include "mobyutil.h"
#include "stdutil.h"
#include "camera.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_36/animation", func_level_36_80084060);

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80084D08.
 * Reuses verified24 private selector55..61 C. Original36 dispatch and BC base
 * lifetime preserved. Byte offsets private4C/50/54/58; unsigned selected46
 * shifts4, signed class36 filters4B/4F/2FF. Source vectors stack18/28 retain
 * 600/0/-380 and400/0/200; helper roles/units/physical meaning remain open.
 * Numeric vectors byte46=0/80/FF ->0/800/FF0 before subsequent helpers.
 * Empty constraints emit no instructions. Every original code/internal jump/
 * dispatch word, strict full TU and every EXE/overlay hash required. Cadence,
 * audio semantics and live runtime parity remain open.
 */
extern Moby* Callback36QueryMoby __asm__("D_80070328+0x250");
extern Moby* Callback36FirstCallMoby __asm__("D_80070328+0x250");
extern Moby* Callback36SecondCallMoby __asm__("D_80070328+0x250");
extern Moby* Callback36InitialMoby __asm__("D_80070328+0x250");
extern int Callback36ClearedWord __asm__("D_80070328+0x28");
extern unsigned char Callback36MobyPointer[] __asm__("D_80070328+0x250");
extern Moby* Callback36Word71930 __asm__("D_80071930");
extern int Callback36WordE1D4 __asm__("D_8006E1D4");
extern int Callback36WordE1D8 __asm__("D_8006E1D8");
extern int Callback36WordE530 __asm__("D_8006E530");
extern int Callback36WordE52C __asm__("D_8006E52C");
extern void (*Callback36Header344)(void) __asm__("unk_ovlheader_80074344");
int Callback36Call80018368(Vector3D*,Vector3D*) __asm__("func_80018368");
extern Spyro Callback36Player __asm__("D_80070328");
void Callback36Call80041930(void) __asm__("func_80041930");
void Callback36Call80041C20(void) __asm__("func_80041C20");
void Callback36Call80042A44(void) __asm__("func_80042A44");
void Callback36Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback36Word8006E538 __asm__("D_8006E538");
int Callback36Call80055E84(Moby*) __asm__("func_80055E84");
void Callback36Call8004ED6C(void*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
void* Callback36Call8001BA30(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int Callback36Call80019138(Vector3D*,int,int,int,int,Moby*) __asm__("func_80019138");
int Callback36Call8001830C(Vector3D*,Vector3D*,int,int,Moby*) __asm__("func_8001830C");
void func_level_36_80084D08(void) {
    struct {Vector3D first; int reserved24; Vector3D second; int reserved34; } local;
    register unsigned char* privateData __asm__("$16");
    register unsigned char* privateOther __asm__("$16");
    register Moby* selected __asm__("$2");
    register int selectedClass __asm__("$3");


    switch(Callback36Player.animationState) {
    case 0x55:
        if(func_800438F4()==0)func_80043728();
        Callback36Call80041C20();
        Callback36Player.unk9a=0;
        Callback36Call80042A44();
        goto clearSharedValue;
    case 0x5A:
        Callback36Call80041C20();
        Callback36Call80042A44();
        goto clearSharedValue;
    case 0x58:
        Callback36Call80041C20();
        Callback36Call80042A44();
        goto queryC00;
    case 0x56:
    case 0x5C:
        privateData=Callback36Player.critterMobyPtr->mobyTag;
        func_800438F4();
        Callback36Call80041C20();
        Callback36Call80042A44();
        Callback36Call80041930();
        if((unsigned char)Callback36Player.unk10[2]!=0) {
            selected=Callback36Word71930;
            *(Moby**)(privateData+0x4C)=selected;
            if(selected) {
                selectedClass=selected->mobyClass;
                if(selectedClass!=0x4B && selectedClass!=0x4F && selectedClass!=0x2FF) {
                    *(Moby**)(privateData+0x4C)=0;
                    goto queryC00;
                }
                goto copySelected;
            }
        } else goto clearSelected;
        goto queryC00;
    case 0x57: {
        register unsigned char* sourceBase __asm__("$17");
        register int* clearedWord __asm__("$16");
        register Moby** mobyPointer __asm__("$16");
        void* result;
        register Moby* initialMoby __asm__("$4");
        func_800438F4();
        Callback36Call80041C20();
        Callback36Call80042A44();
        Callback36Call80041930();
        Callback36Call80043A38(0xC00);
        initialMoby=Callback36InitialMoby;
        __asm__ volatile("" : "=r"(initialMoby) : "0"(initialMoby) : "memory");
        clearedWord=&Callback36ClearedWord;
        *clearedWord=0;
        if(initialMoby->animationState.id==2 &&
           Callback36Call80055E84(initialMoby)>=4 &&
           Callback36Call80055E84(Callback36QueryMoby)<13) {
            local.first.x=0x600;
            local.first.y=0;
            local.first.z=-0x380;
            Callback36Call8004ED6C((unsigned char*)clearedWord+8,&local.first,&local.first);
            {register Vector3D* destination __asm__("$4")=&local.first;
            register Vector3D* firstSource __asm__("$5")=destination;
            __asm__("" : "=r"(destination),"=r"(firstSource) : "0"(destination),"1"(firstSource));
            sourceBase=(unsigned char*)clearedWord-0x28;
            func_8004F194(destination,firstSource,(Vector3D*)sourceBase);}

            result=Callback36Call8001BA30(&local.first,0x400,1,0,0,Callback36FirstCallMoby);
            if(result) {
                func_8004F178(&local.second,(Vector3D*)((unsigned char*)result+0xC));
                local.second.z+=0x80;
                if(Callback36Call80018368((Vector3D*)sourceBase,&local.second)==0)
                    Callback36Call8001BA30(&local.first,0x400,1,0,0x04000000,Callback36SecondCallMoby);
            }
            {register Vector3D* argument0 __asm__("$4")=&local.first;
            register int argument1 __asm__("$5")=0x400;
            register int argument2 __asm__("$6")=0;
            register int argument3 __asm__("$7")=0;
            register Moby* lastMoby __asm__("$3");
            __asm__ volatile("" : "=r"(argument0), "=r"(argument1), "=r"(argument2), "=r"(argument3) : "0"(argument0), "1"(argument1), "2"(argument2), "3"(argument3) : "memory");
            mobyPointer=(Moby**)Callback36MobyPointer;
            lastMoby=*mobyPointer;
            Callback36Call80019138(argument0,argument1,argument2,argument3,0x04000000,lastMoby); }
            Callback36Call8001830C((Vector3D*)((unsigned char*)mobyPointer-0x250),&local.first,0,0x04000000,*mobyPointer);
            if(Callback36Call80055E84(*mobyPointer)>=8) {
                register int* limitPointer __asm__("$3")=&Callback36WordE1D4;
                if(*limitPointer<0xC00)*limitPointer=0xC00;
                if(Callback36WordE1D8<10)Callback36WordE1D8=10;
                Callback36WordE530=120;
                Callback36WordE52C=5;
            }
        }
        if(Callback36Player.unk5==1) {
            if(Callback36Player.ticksSinceLastSurfaceTouch==0)Callback36Player.unk5=0;
        } else if(Callback36Player.ticksSinceLastSurfaceTouch!=0) {
            Callback36Player.unk5=1;
            Callback36Player.unk7a[2].z=Callback36Player.unk7a[3].z;
        }
        return;
    }
    case 0x59:
        privateOther=Callback36Player.critterMobyPtr->mobyTag;
        Callback36Header344();
        Callback36Call80041C20();
        Callback36Call80042A44();
        Callback36Call80041930();
        if((unsigned char)Callback36Player.unk10[2]!=0) {
            selected=Callback36Word71930;
            *(Moby**)(privateOther+0x4C)=selected;
            if(selected) {
                selectedClass=selected->mobyClass;
                if(selectedClass==0x4B || selectedClass==0x4F || selectedClass==0x2FF) {
                    register Moby* bytePointer __asm__("$2")=*(Moby**)(privateOther+0x4C);
                    register int shiftedByte __asm__("$2")=((unsigned char*)bytePointer)[0x46];
                    register Moby* propertyPointer __asm__("$3");
                    register int propertyWord __asm__("$2");
                    __asm__ volatile("" : : : "memory");
                    propertyPointer=*(Moby**)(privateOther+0x4C);
                    shiftedByte<<=4;
                    *(int*)(privateOther+0x50)=shiftedByte;
                    propertyWord=*(int*)propertyPointer;
                    __asm__ volatile("" : : : "memory");
                    *(int*)(privateOther+0x58)=0;
                    *(int*)(privateOther+0x54)=propertyWord;
                    Callback36Player.unk5=1;
                } else goto clearSelectedOther;
            }
        } else {
clearSelectedOther:
            *(Moby**)(privateOther+0x4C)=0;
            Callback36Player.unk5=0;
        }
        goto clearSharedValue;
    case 0x5B: {
        register unsigned char* originalBase __asm__("$17");
        register Vector3D* vectorBase __asm__("$16");
        register void* argument0 __asm__("$4");
        if(func_800438F4()==0)func_80043728();
        Callback36Call80041C20();
        originalBase=(unsigned char*)&Callback36Player.unk9a;
        *(int*)originalBase=0;
        Callback36Call80042A44();
        Callback36Player.unk4[0]=0;
        argument0=originalBase-0x8C;
        if(Callback36Player.critterMobyPtr->animationState.id==6) {
            vectorBase=&local.second;
            local.second.x=0x400;
            local.second.y=0;
            local.second.z=0x200;
            Callback36Call8004ED6C(argument0,vectorBase,vectorBase);
            func_8004F194(vectorBase,vectorBase,(Vector3D*)(originalBase-0xBC));
            Callback36Call8001BA30(vectorBase,0x400,0,0,0x08000000,Callback36Player.critterMobyPtr);
        }
        return;
    }
    case 0x5D:
    case 0x5E:
        Callback36Call80041C20();
        Callback36Call80042A44();
        Callback36Call80041930();
        if(Callback36Player.unk5!=0x7F) {
            if(Callback36Player.unk7a[3].z<0 && Callback36Player.animationStateFrames>=4)
                Callback36Player.unk5=1;
            else if(Callback36Player.unk5==0 && !(Callback36Word8006E538&0x40) && Callback36Player.union144.a.unk13cb==0)
                Callback36Player.unk5=2;
        }
        goto clearSharedValue;
    case 0x5F:
    case 0x60:
    case 0x61:
        privateData=Callback36Player.critterMobyPtr->mobyTag;
        Callback36Header344();
        func_800438F4();
        Callback36Call80041C20();
        Callback36Call80042A44();
        Callback36Call80041930();
        if((unsigned char)Callback36Player.unk10[2]!=0) {
            selected=Callback36Word71930;
            *(Moby**)(privateData+0x4C)=selected;
            if(selected) {
                selectedClass=selected->mobyClass;
                if(selectedClass==0x4B || selectedClass==0x4F || selectedClass==0x2FF)goto copySelected;
                goto clearSelected;
            }
        } else goto clearSelected;
        goto queryC00;
copySelected: {
        register Moby* bytePointer __asm__("$2")=*(Moby**)(privateData+0x4C);
        register int shiftedByte __asm__("$2")=((unsigned char*)bytePointer)[0x46];
        register Moby* propertyPointer __asm__("$3");
        register int propertyWord __asm__("$2");
        __asm__ volatile("" : : : "memory");
        propertyPointer=*(Moby**)(privateData+0x4C);
        shiftedByte<<=4;
        *(int*)(privateData+0x50)=shiftedByte;
        propertyWord=*(int*)propertyPointer;
        __asm__ volatile("" : : : "memory");
        *(int*)(privateData+0x58)=0;
        *(int*)(privateData+0x54)=propertyWord;
        goto queryC00;
    }
clearSelected:
        *(Moby**)(privateData+0x4C)=0;
queryC00:
        Callback36Call80043A38(0xC00);
clearSharedValue:
        Callback36Player.unk4[0]=0;
        return;
    default:
        return;
    }
}




#define LEVEL_ID 36
#define PlaySpyroSounds_level_36 func_level_36_8008537C
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_36_800854A4(int index) {
    Vector3D* position;
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x55: case 0x56: case 0x57: case 0x58: case 0x5a: case 0x5b: case 0x5c: case 0x5f: case 0x60: case 0x61:
        position = &spyro.unk9e;
        break;
    case 0x59: case 0x5d: case 0x5e:
        position = 0;
        break;
    default: return;
    }
    func_80043ABC(position);
}

extern Spyro Callback36_D_80070328 __asm__("D_80070328");
extern short Signed36TableA[] __asm__("D_800658A0");
extern short Signed36TableB[] __asm__("D_80065920");
int Callback36_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Callback36_func_80043A38(int scale) __asm__("func_80043A38");
void Callback36_func_800441F0(void) __asm__("func_800441F0");
void Callback36_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Callback36_D_8006E524 __asm__("D_8006E524");

void func_level_36_80085520(int arg0) {
    register Vector3D* destination __asm__("$4");
    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    register unsigned char* stateBaseB __asm__("$2");
    register unsigned char *sourceBytesA __asm__("$16");
    register unsigned char *sourceBytesB __asm__("$16");

    switch (arg0) {
    case 0x55:
    case 0x5B:
        Callback36_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback36_D_80070328.unk5 = 0;
        Callback36_func_800441F0();
        Callback36_D_80070328.grounded = 1;
        return;
    case 0x56:
    case 0x57:
    case 0x5C:
    case 0x5F:
    case 0x60:
    case 0x61:
        Callback36_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Callback36_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((unsigned char*)&Callback36_D_80070328.movementState + 0x3C), (Vector3D *) ((unsigned char*)&Callback36_D_80070328.movementState + 0x48));
            Callback36_D_80070328.unk5 = 1;
        } else {
            Callback36_D_80070328.unk5 = 0;
        }
        Callback36_D_80070328.unk8[0] = Callback36_func_8004EDE8(&Callback36_D_80070328.unk7a[3], 0);
        Callback36_func_80043A38(0xC00);
        Callback36_D_80070328.union144.a.unk13cb = 0;
        Callback36_D_80070328.grounded = 1;
        goto clearTail;
    case 0x58:
        Callback36_D_80070328.movementState = MOVEMENT_STATE_HURT;
        Callback36_D_80070328.unk5 = 0;
        if (Callback36_D_80070328.unk22[5] >= 0) {
            tableOffsetOrValue = Callback36_D_80070328.unk22[5] * 2;
            tableValueA = *(short*)((unsigned char*)Signed36TableB + tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            tableValueA >>= 1;
            Callback36_D_80070328.unk7a[2].x = tableValueA;
            tableOffsetOrValue = *(short*)((unsigned char*)Signed36TableA + tableOffsetOrValue);
            Callback36_D_80070328.unk7a[2].z = 0;
            __asm__ __volatile__("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Callback36_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
        } else {
            Callback36_func_8004F168((Vector3D *) ((unsigned char*)&Callback36_D_80070328.movementState + 0x3C));
        }
        Callback36_D_80070328.unk7a[2].z = 0x200;
        func_8004F178((Vector3D *) ((unsigned char*)&Callback36_D_80070328.unk7a[2].z - 0x14), (Vector3D *) ((unsigned char*)&Callback36_D_80070328.unk7a[2].z - 8));
        Callback36_D_80070328.grounded = 1;
        Callback36_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
    default:
        return;
    case 0x5A:
        Callback36_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Callback36_D_80070328.unk5 = 0;
        Callback36_func_80043A38(0xC00);
        Callback36_D_80070328.grounded = 1;
        Callback36_D_8006E524 = 0xF;
        return;
    case 0x59:
        Callback36_D_80070328.movementState = MOVEMENT_STATE_FALL;
        if (Callback36_D_80070328.animationState == 0x5F) {
            Callback36_D_80070328.unk5 = 1;
        } else {
            Callback36_D_80070328.unk5 = 0;
        }
        Callback36_D_80070328.unk8[0] = Callback36_func_8004EDE8(&Callback36_D_80070328.unk7a[3], 0);
        Callback36_D_80070328.grounded = 0;
        Callback36_D_80070328.unk15b = 1;
clearTail:
        Callback36_D_80070328.idle = 0;
        Callback36_D_80070328.unk15g = 0;
        return;
    case 0x5D:
        stateBaseA = Raw36State;
        __asm__("" : "=r"(stateBaseA) : "0"(stateBaseA));
        destination = (Vector3D*)(stateBaseA + 0x3C);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceBytesA = stateBaseA + 0x48;
        *(int*)stateBaseA = 2;
        func_8004F178(destination, (Vector3D*)sourceBytesA);
        Callback36_D_80070328.unk8[0] = Callback36_func_8004EDE8((Vector3D *) sourceBytesA, 0);
        Callback36_D_80070328.unk7a[2].z = 0xA00;
        Callback36_D_80070328.unk5 = 0;
        Callback36_D_80070328.union144.a.unk13cb = 0;
        Callback36_D_80070328.grounded = 0;
        PlaySound((int) D_8006C654->jump, 0, 0);
        return;
    case 0x5E:
        stateBaseB = Raw36State;
        __asm__("" : "=r"(stateBaseB) : "0"(stateBaseB));
        destination = (Vector3D*)(stateBaseB + 0x3C);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceBytesB = stateBaseB + 0x48;
        *(int*)stateBaseB = 2;
        func_8004F178(destination, (Vector3D*)sourceBytesB);
        Callback36_D_80070328.unk8[0] = Callback36_func_8004EDE8((Vector3D *) sourceBytesB, 0);
        Callback36_D_80070328.unk5 = 2;
        Callback36_D_80070328.union144.a.unk13cb = 0;
        Callback36_D_80070328.grounded = 0;
        break;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_36/animation", func_level_36_80085870);
