#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_41/animation", func_level_41_8008FD90);

extern Moby* Callback41QueryMoby __asm__("D_80070328+0x250");
extern Moby* Callback41InitialMoby __asm__("D_80070328+0x250");
extern int Callback41ClearedWord __asm__("D_80070328+0x28");
extern Moby* Callback41Word71930 __asm__("D_80071930");
extern int Callback41WordE1D4 __asm__("D_8006E1D4");
extern int Callback41WordE1D8 __asm__("D_8006E1D8");
extern int Callback41WordE530 __asm__("D_8006E530");
extern int Callback41WordE52C __asm__("D_8006E52C");
extern void (*Callback41Header344)(void) __asm__("unk_ovlheader_80074344");
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8009250C.
 * Reuses verified24 private4C/50/54/58, independent table/flag and byte-position
 * routes; verified12 supplies particle/timer chains. Original41 adds dispatch,
 * T0 particle callback and selector57 loop. Pointer arithmetic is byte-based:
 * player28+8/-28/+250/-250, playerBC-8C/-BC and count148-B0/source-98.
 * Stack vectors18/28/38/48, frame78 and unaccessed spacing preserve original
 * layout without assigning source-variable meanings. Original loop calls with
 * size190, advances vector after zero return, stops after four or nonzero;
 * mask04000000, later size400 and selector5B mask08000000 remain numeric.
 * Independent aliases and empty constraints retain original load-delay order,
 * argument lifetimes and internal targets; they emit no instructions.
 * Units, helper semantics, audio mapping, caller cadence and retail runtime
 * remain unresolved. Acceptance requires every original code/local-jump/table
 * word, strict complete TU and every EXE/original overlay hash.
 */
extern Spyro Callback41Player __asm__("D_80070328");
int Callback41Call80037058(int x, int y) __asm__("func_80037058");
void Callback41Call80041930(void) __asm__("func_80041930");
void Callback41Call80041AE8(void) __asm__("func_80041AE8");
void Callback41Call80041C20(void) __asm__("func_80041C20");
void Callback41Call80042A44(void) __asm__("func_80042A44");
void Callback41Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback41Word8006E538 __asm__("D_8006E538");
int Callback41Call80055E84(Moby*) __asm__("func_80055E84");
void Callback41Call8004ED6C(void*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
void* Callback41Call8001BA30(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int Callback41Call80019138(Vector3D*,int,int,int,int,Moby*) __asm__("func_80019138");
int Callback41Call8001830C(Vector3D*,Vector3D*,int,int,Moby*) __asm__("func_8001830C");
extern int Callback41Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback41Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback41Values[] __asm__("D_8006FCF0");
void Callback41Call80049590(void) __asm__("func_80049590");
int Callback41Call8003BF6C(int,int) __asm__("func_8003BF6C");
extern short Callback41Count __asm__("D_80070328+0x148");
extern int D_8006C648;
void Callback41Call8004F110(Vector3D*,int) __asm__("func_8004F110");
void func_level_41_8009250C(void) {
    struct {Vector3D particle; int reserved24; Vector3D first; int reserved34; Vector3D second; int reserved44; Vector3D third; int reserved54; } local;
    int reservedStackWords[2];
    register unsigned char* countBase __asm__("$5");
    register unsigned char* sourceBytes __asm__("$18");
    register int iteration __asm__("$16");
    register int secondLimit __asm__("$17");
    register int sample __asm__("$2");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    register char* (*particles)(int,int,Vector3D*,Vector3D*) __asm__("$8");
    register unsigned char* privateData __asm__("$16");
    register unsigned char* privateOther __asm__("$16");
    register Moby* selected __asm__("$2");
    register int selectedClass __asm__("$3");
    register int computedValue __asm__("$4");
    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    int descriptorResult;
    register int flagOffset __asm__("$3");

    register int positionDelta __asm__("$2");
    register int positionValue __asm__("$3");

    switch(Callback41Player.animationState) {
    case 0x14:
    case 0x55:
        if(func_800438F4()==0)func_80043728();
        Callback41Call80041C20();
        Callback41Player.unk9a=0;
        Callback41Call80042A44();
        goto clearSharedValue;
    case 0x20:
    case 0x35:
    case 0x36:
    case 0x5A:
        Callback41Call80041C20();
        Callback41Call80042A44();
        goto clearSharedValue;
    case 0x1A:
    case 0x1D:
    case 0x58:
        Callback41Call80041C20();
        Callback41Call80042A44();
        goto queryC00;
    case 0x13:
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041930();
        goto clearSharedValue;
    case 0x21:
    case 0x22:
    case 0x23:
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041930();
        if (SpawnParticle != 0) {
            countBase=(unsigned char*)&Callback41Count;
            if (*(short*)countBase == 0) goto clearSharedValue;
            secondLimit = 1;
            if (*(short*)countBase >= 2) {
                secondLimit = 2;
            }
            iteration = 0;
            if (secondLimit != 0) {
                __asm__("" : "=r"(countBase) : "0"(countBase));
                sourceBytes=countBase-0xB0;
                do {
                    func_8004F178((&local.particle), (Vector3D *) sourceBytes);
                    Callback41Call8004F110((&local.particle), 7);
                    iteration += 1;
                    sample=rand();
                    component=local.particle.x;
                    sample &= 254;
                    component -=127;
                    component +=sample;
                    __asm__("" : "=r"(component) : "0"(component));
                    local.particle.x=component;
                    sample=rand();
                    component=local.particle.y;
                    sample &= 254;
                    component -=127;
                    component +=sample;
                    __asm__("" : "=r"(component) : "0"(component));
                    local.particle.y=component;
                    sample=rand();
                    kind=1;
                    subtype=0x17;
                    position=sourceBytes-0x98;
                    vector=&local.particle;
                    __asm__("" : "=r"(kind), "=r"(subtype), "=r"(position), "=r"(vector) : "0"(kind), "1"(subtype), "2"(position), "3"(vector), "r"(sample) : "$3", "memory");
                    sample &=254;
                    __asm__("" : "=r"(sample) : "0"(sample) : "memory");
                    component=local.particle.z;
                    particles=SpawnParticle;
                    __asm__("" : "=r"(particles) : "0"(particles), "r"(component), "r"(sample));
                    component -=127;
                    component +=sample;
                    local.particle.z=component;
                    particles(kind,subtype,(Vector3D*)position,vector);
                } while (iteration < secondLimit);
            }
        }
        goto clearSharedValue;
    case 0x28:
    case 0x29:
    case 0x39:
        Callback41Call80041C20();
        Callback41Call80042A44();
        descriptor=&Callback41Player.unk22[2];
        if (Callback41Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback41Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setDecreasingFlag;
            tableValue=decreasingValue-0xC8;
            goto storeDecreasingValue;
            }
            goto setDecreasingFlag;
storeDecreasingValue:
            *(int*)(Callback41Values + valueOffset) = tableValue;
setDecreasingFlag:
            flagOffset = *descriptor * 0x2C;
            Callback41Flags[flagOffset] = Callback41Flags[flagOffset] | 0x10;
            __asm__ volatile("" : : : "memory");
        }
        goto clearSharedValue;
    case 0x2A:
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80049590();
        descriptor=&Callback41Player.unk22[2];
        if (Callback41Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback41Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback41Player.unk22[2];
        }
        if (Callback41Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback41Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback41Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback41Flags[flagOffset] = Callback41Flags[flagOffset] | 0x10;
            __asm__ volatile("" : : : "memory");
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041AE8();
        if ((unsigned char) Callback41Player.unk10[4] != 0) {
            computedValue = -Callback41Player.unk9ha[4] - Callback41Call80037058(Callback41Player.position.x, Callback41Player.position.y);
            positionValue = Callback41Player.unk4a - computedValue;
            Callback41Player.unk4[0] = computedValue;
            positionDelta = (int) Callback41Player.union144.a.unk13cc >> 6;
            positionValue -= positionDelta;
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            Callback41Player.position.z=positionValue;
            return;
        }
        break;
    case 0x31:
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80043A38(0xC00);
        if (func_80040954(Callback41Player.unk11[2]) == 0xA) {
            Callback41Player.union144.a.unk13cb = 0;
        } else {
            Callback41Player.union144.a.unk13cb += D_8006C648;
        }
        Callback41Player.unk4[0] = 0;
        if (Callback41Call8003BF6C((int) D_8006C654->unk32, Callback41Player.unk22[2]) == 0) {
            Callback41Player.unk22[2] = PlaySound((int) D_8006C654->unk32, 0, 4);
            Callback41Player.unk22[3] = (int) D_8006C654->unk32;
            return;
        }
        break;
    case 0x56:
    case 0x5C:
        privateData=Callback41Player.critterMobyPtr->mobyTag;
        func_800438F4();
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041930();
        if((unsigned char)Callback41Player.unk10[2]!=0) {
            selected=Callback41Word71930;
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
        register unsigned char* sourceBase __asm__("$18");
        register int* clearedWord __asm__("$18");
        register Moby** mobyPointer __asm__("$18");
        register Vector3D* firstVector __asm__("$16");
        register Vector3D* secondVector __asm__("$17");
        register int counter __asm__("$16");
        register int mask __asm__("$19");
        register void* argument0 __asm__("$4");
        register Moby* initialMoby __asm__("$4");
        func_800438F4();
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041930();
        Callback41Call80043A38(0xC00);
        initialMoby=Callback41InitialMoby;
        __asm__ volatile("" : "=r"(initialMoby) : "0"(initialMoby) : "memory");
        clearedWord=&Callback41ClearedWord;
        *clearedWord=0;
        if(initialMoby->animationState.id==2 &&
           Callback41Call80055E84(initialMoby)>=4 &&
           Callback41Call80055E84(Callback41QueryMoby)<13) {
            argument0=(unsigned char*)clearedWord+8;
            __asm__("" : "=r"(argument0) : "0"(argument0));
            firstVector=&local.first;
            local.first.x=0x190;
            local.first.y=0;
            local.first.z=0;
            Callback41Call8004ED6C(argument0,firstVector,firstVector);
            secondVector=&local.second;
            argument0=secondVector;
            __asm__("" : "=r"(argument0) : "0"(argument0) : "memory");
            sourceBase=(unsigned char*)clearedWord-0x28;
            func_8004F194((Vector3D*)argument0,(Vector3D*)sourceBase,firstVector);
            counter=0;
            mask=0x04000000;
            mobyPointer=(Moby**)(sourceBase+0x250);
            do {
                register Moby* argumentMoby __asm__("$2");
                register Vector3D* argument0 __asm__("$4");
                register int argument1 __asm__("$5");
                register int argument2 __asm__("$6");
                argument0=secondVector;
                argument1=0x190;
                argument2=1;
                __asm__ volatile("" : "=r"(argument0), "=r"(argument1), "=r"(argument2) : "0"(argument0), "1"(argument1), "2"(argument2) : "$7", "memory");
                argumentMoby=*mobyPointer;
                __asm__ volatile("" : : : "memory");
                if(Callback41Call8001BA30(argument0,argument1,argument2,0,mask,argumentMoby))break;
                func_8004F194(secondVector,secondVector,&local.first);
                counter++;
            } while(counter<4);
            firstVector=&local.first;
            {
                register Moby* argumentMoby __asm__("$2");
                register Vector3D* argument0 __asm__("$4");
                register int argument1 __asm__("$5");
                register int argument2 __asm__("$6");
                argument0=firstVector;
                argument1=0x400;
                argument2=0;
                __asm__ volatile("" : "=r"(argument0), "=r"(argument1), "=r"(argument2) : "0"(argument0), "1"(argument1), "2"(argument2) : "$7", "memory");
                argumentMoby=*mobyPointer;
                __asm__ volatile("" : : : "memory");
                Callback41Call80019138(argument0,argument1,argument2,0,mask,argumentMoby);
            }
            Callback41Call8001830C((Vector3D*)((unsigned char*)mobyPointer-0x250),firstVector,0,0x04000000,*mobyPointer);
            if(Callback41Call80055E84(*mobyPointer)>=8) {
                register int* limitPointer __asm__("$3")=&Callback41WordE1D4;
                if(*limitPointer<0xC00)*limitPointer=0xC00;
                if(Callback41WordE1D8<10)Callback41WordE1D8=10;
                Callback41WordE530=120;
                Callback41WordE52C=5;
            }
        }
        if(Callback41Player.unk5==1) {
            if(Callback41Player.ticksSinceLastSurfaceTouch==0)Callback41Player.unk5=0;
        } else if(Callback41Player.ticksSinceLastSurfaceTouch!=0) {
            Callback41Player.unk5=1;
            Callback41Player.unk7a[2].z=Callback41Player.unk7a[3].z;
        }
        return;
    }
    case 0x59:
        privateOther=Callback41Player.critterMobyPtr->mobyTag;
        Callback41Header344();
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041930();
        if((unsigned char)Callback41Player.unk10[2]!=0) {
            selected=Callback41Word71930;
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
                    Callback41Player.unk5=1;
                } else goto clearSelectedOther;
            }
        } else {
clearSelectedOther:
            *(Moby**)(privateOther+0x4C)=0;
            Callback41Player.unk5=0;
        }
        goto clearSharedValue;
    case 0x5B: {
        register Vector3D* vectorBase __asm__("$16");
        register int* sourceWord __asm__("$17");
        register void* argument0 __asm__("$4");
        if(func_800438F4()==0)func_80043728();
        Callback41Call80041C20();
        sourceWord=&Callback41Player.unk9a;
        *sourceWord=0;
        Callback41Call80042A44();
        Callback41Player.unk4[0]=0;
        argument0=(unsigned char*)sourceWord-0x8C;
        if(Callback41Player.critterMobyPtr->animationState.id==6) {
            vectorBase=&local.third;
            local.third.x=0x400;
            local.third.y=0;
            local.third.z=0x200;
            Callback41Call8004ED6C(argument0,vectorBase,vectorBase);
            func_8004F194(vectorBase,vectorBase,(Vector3D*)((unsigned char*)sourceWord-0xBC));
            Callback41Call8001BA30(vectorBase,0x400,0,0,0x08000000,Callback41Player.critterMobyPtr);
        }
        return;
    }
    case 0x5D:
    case 0x5E:
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041930();
        if(Callback41Player.unk5!=0x7F) {
            if(Callback41Player.unk7a[3].z<0 && Callback41Player.animationStateFrames>=4)
                Callback41Player.unk5=1;
            else if(Callback41Player.unk5==0 && !(Callback41Word8006E538&0x40) && Callback41Player.union144.a.unk13cb==0)
                Callback41Player.unk5=2;
        }
        goto clearSharedValue;
    case 0x5F:
    case 0x60:
    case 0x61:
        privateData=Callback41Player.critterMobyPtr->mobyTag;
        Callback41Header344();
        func_800438F4();
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041930();
        if((unsigned char)Callback41Player.unk10[2]!=0) {
            selected=Callback41Word71930;
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
        Callback41Call80043A38(0xC00);
clearSharedValue:
        Callback41Player.unk4[0]=0;
        return;
    default:
        return;
    }
}


#define LEVEL_ID 41
#define PlaySpyroSounds_level_41 func_level_41_80092FC4
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_41_80093130(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x14:
    case 0x1a:
    case 0x1d:
    case 0x20:
    case 0x2b:
    case 0x2c:
    case 0x31:
    case 0x35:
    case 0x36:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x5a:
    case 0x5b:
    case 0x5c:
    case 0x5f:
    case 0x60:
    case 0x61:
        func_80043ABC(&spyro.unk9e);
        break;
    case 0x13:
    case 0x59:
    case 0x5d:
    case 0x5e:
        func_80043ABC(0);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 800931AC.
 * Reuses verified24 underwater/surface vectors, signed-table and55..61 routes;
 * verified33 private0/4/8 swirl and state6 clamp; verified43 squish and slide.
 * Original41 supplies separate35/36 stand blocks and shared descriptor15/9/19.
 * Numeric byte offsets, signed shift10/6, halfwords, yaw/scalar FFF masks and
 * 800/4B00 limits retain original instructions. Scalar60 inputs800/801/FFF
 * yield0/-7FF/-1 before helpers; private producer positions remain source-native.
 * Empty constraints retain original lifetimes and independent branch blocks,
 * emitting no opcodes. Every code/local jump/owned dispatch word, strict full
 * TU and complete EXE/every overlay hashes are acceptance gates. Helper/audio
 * meanings, units/conversions, caller cadence and live runtime parity remain
 * open. Once per invocation is the only demonstrated update cadence.
 */
extern Spyro Transition41_D_80070328 __asm__("D_80070328");
int Transition41_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition41_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition41_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition41RawUnion[] __asm__("D_80070328+0x144");
extern int Transition41RawMovement __asm__("D_80070328+0x50");
extern void (*Call41Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw41State[] __asm__("D_80070328+0x50");
extern Spyro Special41_D_80070328 __asm__("D_80070328");
extern short Signed41TableA[] __asm__("D_800658A0");
extern short Signed41TableB[] __asm__("D_80065920");
int Special41_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Special41_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Special41_D_8006E524 __asm__("D_8006E524");

extern int D_80071934;
int Call41A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw41NegativeWord __asm__("D_80070328+0x28");
extern int Raw41TableIndex __asm__("D_80070328+0x298");
extern int Raw41Yaw __asm__("D_80070328+0x64");
int Transition41_func_8003636C(int,int) __asm__("func_8003636C");
void Transition41_func_800441F0(void) __asm__("func_800441F0");
void Transition41_func_80043A38(int) __asm__("func_80043A38");
int Transition41_func_8004E880(int,int,int) __asm__("func_8004E880");
void func_level_41_800931AC(int arg0){
    struct {Vector3D first; int gap1; Vector3D second; int gap2; Vector3D third;} vectors;
    register int negativeWord __asm__("$3");
    int firstResult,secondResult,firstWrappedWord,secondWrappedWord,firstParticleKind,secondParticleKind,firstParticleSubtype,secondParticleSubtype;
    register Vector3D* destination __asm__("$4");

    int lengthResult;

    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    register unsigned char *sourceBytesA __asm__("$16");

    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* savedBase __asm__("$3");
    register int oldMovementC __asm__("$5");
    register unsigned char* privateData __asm__("$16");
    register unsigned char* stateBase __asm__("$17");
    int maskedValue;
    switch(arg0){
    case 0x14:
        Transition41_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition41_D_80070328.unk5 = 0;
        Transition41_func_800441F0();
        Transition41_D_80070328.grounded = 1;
        Transition41_D_80070328.union144.a.unk13cb = Transition41_func_8003636C(1, 3);
        Transition41_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x35:
        Transition41_D_80070328.movementState=0;
        Transition41_D_80070328.unk5=0;
        Transition41_func_800441F0();
        Transition41_D_80070328.grounded=1;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        stateBase=(unsigned char*)&Transition41RawMovement;
        privateData = Transition41_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition41_D_80070328.unk5 = 0;
        Transition41_D_80070328.grounded = 0;
        Transition41_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition41_D_80070328.m_WhirlwindPointer;
        yawValue=Transition41_D_80070328.rotation.yaw;
        positionZ=Transition41_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition41_D_80070328.union144.a.unk13cc=yawValue;
        Transition41_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition41_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition41_D_80070328.union144.a.unk13ce.z=heightValue;
        __asm__ volatile("" : : : "memory");
        heightValue = ((int) (heightValue << 0xA) >> 0xA) + 0x400;
        __asm__("" : "=r"(heightValue) : "0"(heightValue));
        Transition41_D_80070328.union144.a.unk13ce.y = heightValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
        Transition41_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition41_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition41_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition41_D_80070328.unk13e[0] = (int) Transition41_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition41_D_80070328.unk20a = 0;
        Transition41_D_80070328.critterMobyPtr = 0;
        Transition41_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x1D: {
        register int oldState __asm__("$4")=Transition41RawMovement;
        register int first __asm__("$3")=Transition41_D_80070328.unk17e.x;
        register int second __asm__("$2");
        register int third __asm__("$3");
        __asm__("" : "=r"(oldState),"=r"(first) : "0"(oldState),"1"(first) : "memory");
        second=7;
        __asm__("" : "=r"(second) : "0"(second));
        Transition41RawMovement=second;
        __asm__ volatile("" : : : "memory");
        second=Transition41_D_80070328.unk17e.y;
        __asm__ volatile("" : "=r"(second) : "0"(second) : "memory");
        Transition41_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(first) : "0"(first) : "memory");
        first<<=6;
        __asm__("" : "=r"(first) : "0"(first));
        Transition41_D_80070328.unk7a[2].x=first;
        __asm__ volatile("" : : : "memory");
        third=Transition41_D_80070328.unk17e.z;
        second<<=6;
        Transition41_D_80070328.union144.a.unk13cb=oldState;
        Transition41_D_80070328.unk7a[2].y=second;
        second=third<<6;
        if(third==0)second=Transition41_D_80070328.unk7a[3].z;
        Transition41_D_80070328.unk7a[2].z=second;
        Transition41_func_80043A38(0xC00);
        Transition41_D_80070328.grounded=1;
        Transition41_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        soundSelector=D_8006C654->spyroHurt;
        soundZero=0;
        goto sharedSound;
    }

    case 0x1A:
        savedBase = Transition41RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        oldMovementC = Transition41RawMovement;
        Transition41RawMovement = MOVEMENT_STATE_HURT;
        Transition41_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementC;
        Transition41_func_8004F168(destination);
        Transition41_D_80070328.grounded = 1;
        Transition41_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        soundSelector=D_8006C654->squish;
        soundZero=0;
        goto sharedSound;
    case 0x20:
        Transition41_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition41_D_80070328.unk5 = 0;
        Transition41_func_80043A38(0xC00);
        Transition41_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition41_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x21:
    case 0x22:
    case 0x23: {
        register unsigned char* flyState __asm__("$16")=(unsigned char*)&Transition41RawMovement;
        if(*(int*)flyState!=6) {
            *(int*)flyState=6;
            Transition41_D_80070328.unk5=0;
            Transition41_func_8004F168((Vector3D*)(flyState+0x104));
            Transition41_D_80070328.union144.a.unk13db.y=0;
            lengthResult=Transition41_func_8004EDE8((Vector3D*)(flyState+0x48),0);
            Transition41_D_80070328.unk8[0]=lengthResult;
            if(lengthResult<0x800)Transition41_D_80070328.unk8[0]=0x800;
            if(Transition41_D_80070328.unk8[0]>=0x4B01)Transition41_D_80070328.unk8[0]=0x4B00;
            Transition41_D_80070328.union144.a.unk13cb=0;
            Transition41_D_80070328.union144.b.unk148=0;
            Transition41_D_80070328.union144.a.unk13ce.x=0;
            Transition41_D_80070328.union144.a.unk13ce.y=0;
            Transition41_D_80070328.grounded=0;
            Transition41_D_80070328.unk15b=0;
        }
        if(arg0<0xA0)goto clearPointers;
        return;
    }
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition41_D_80070328.movementState - 0xB) >= 2U) && (Transition41_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition41_D_80070328.movementState - 0x50));
                if ((Transition41_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw41NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition41_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call41A358(&vectors.first, 0x800);
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
            firstWrappedWord = Transition41_D_80070328.rotation.pitch & 0xFFF;
            Transition41_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition41_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition41_D_80070328.rotation.pitch > 0) {
                Transition41_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition41_D_80070328.unk5 = 1;
            }
            Transition41_func_8004F168((Vector3D *) ((unsigned char*)&Transition41_D_80070328.rotation.pitch + 0xEC));
            Transition41_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition41_D_80070328.unk8[0] = Transition41_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition41_D_80070328.rotation.pitch + 0x38), 0);
            Transition41_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition41_D_80070328.animationState == 0x2A) {
            Transition41_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition41_D_80070328.union144.a.unk13da = 0;
        }
        Transition41_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition41_D_80070328.unk20a = 0;
        Transition41_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw41State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw41NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition41_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call41A358(localVector, 0x800);
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
            if (Transition41_D_80070328.animationState == 0x2E) {
                Transition41_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition41_D_80070328.rotation.pitch & 0xFFF;
            Transition41_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition41_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition41_D_80070328.rotation.pitch > 0) {
                Transition41_D_80070328.rotation.pitch = 0;
            }
            Transition41_D_80070328.unk5 = 1;
            Transition41_func_8004F168((Vector3D *) ((unsigned char*)&Transition41_D_80070328.animationState + 0x104));
            Transition41_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition41_D_80070328.unk8[0] = Transition41_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition41_D_80070328.animationState + 0x50), 0);
            Transition41_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition41_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition41_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition41RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition41RawUnion;
            *(int*)unionPointer=(-Transition41_D_80070328.unk7a[2].z)>>2;
            if(Transition41RawMovement!=8){Transition41_D_80070328.union144.a.unk13cc=0x5900;Transition41RawMovement=10;}
            Transition41_D_80070328.unk5=0;
            Transition41_D_80070328.unk8[0]=Transition41_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition41_D_80070328.grounded=1;
            Transition41_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call41A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x31: {
        register unsigned char* lengthBase __asm__("$5")=(unsigned char*)&Transition41_D_80070328.unk8[0];
        register int valueA __asm__("$4");
        register int valueB __asm__("$5");
        register int valueKind __asm__("$6");
        *(int*)lengthBase=0;
        if(Transition41_D_80070328.animationState==0xD || Transition41_D_80070328.movementState==1)
            func_8004F178((Vector3D*)(lengthBase-0x30),(Vector3D*)(lengthBase-0x18));
        else Transition41_func_8004F168((Vector3D*)(lengthBase-0x30));
        func_8004F178(&Transition41_D_80070328.unk7a[2],(Vector3D*)((unsigned char*)&Transition41_D_80070328.unk7a[2]-0xC));
        Transition41_D_80070328.movementState=17;
        Transition41_D_80070328.unk5=0;
        Transition41_func_80043A38(0xC00);
        Transition41_D_80070328.grounded=0;
        Transition41_D_80070328.union144.a.unk13cb=0;
        valueKind=1;
        if(Transition41_D_80070328.unk9ha[0]>=11) {
            valueA=Transition41_D_80070328.unk9e.x;
            valueB=Transition41_D_80070328.unk9e.y;
        } else {
            valueA=Transition41_D_80070328.unk7a[3].x;
            valueB=valueA;
        }
        Transition41_D_80070328.union144.a.unk13cc=Transition41_func_8004E880(valueA,valueB,valueKind);
        goto clearPointers;
    }
    case 0x36:
        Transition41_D_80070328.movementState=0;
        Transition41_D_80070328.unk5=0;
        Transition41_func_800441F0();
        Transition41_D_80070328.grounded=1;
        goto clearPointers;
    case 0x39: {
        register int previousMovement __asm__("$2")=Transition41RawMovement;
        register int numericKind __asm__("$3");
        register int indexWord __asm__("$3");
        register unsigned char* unionPointer __asm__("$5");
        register int tableOffset __asm__("$2");
        register int tableWord __asm__("$3");
        __asm__("" : "=r"(previousMovement) : "0"(previousMovement));
        numericKind=7;
        __asm__("" : "=r"(numericKind) : "0"(numericKind));
        Transition41RawMovement=numericKind;
        __asm__ volatile("" : : : "memory");
        indexWord=Raw41TableIndex;
        __asm__ volatile("" : "=r"(indexWord) : "0"(indexWord) : "memory");
        unionPointer=Transition41RawUnion;
        __asm__("" : "=r"(indexWord),"=r"(unionPointer) : "0"(indexWord),"1"(unionPointer) : "memory");
        Transition41_D_80070328.unk5=0;
        *(int*)unionPointer=previousMovement;
        if(indexWord<0)Raw41TableIndex=((Raw41Yaw+0x800)>>4)&0xFF;
        tableOffset=Raw41TableIndex*2;
        tableWord=*(short*)((unsigned char*)Signed41TableB+tableOffset);
        destination=(Vector3D*)(unionPointer-0xC4);
        *(int*)(unionPointer-0xB8)=tableWord;
        tableOffset=*(short*)((unsigned char*)Signed41TableA+tableOffset);
        Transition41_D_80070328.unk7a[2].z=0;
        Transition41_D_80070328.unk7a[2].y=tableOffset;
        func_8004F178(destination,(Vector3D*)(unionPointer-0xB8));
        Transition41_D_80070328.grounded=1;
        Transition41_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        { register unsigned char* soundTable __asm__("$2")=(unsigned char*)D_8006C654;
        __asm__ volatile("" : "=r"(soundTable) : "0"(soundTable) : "memory");
        soundZero=0;
        soundSelector=soundTable[0x19]; }
sharedSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
    }
clearPointers:
        Transition41_D_80070328.unk20a=0;
        Transition41_D_80070328.critterMobyPtr=0;
        return;
    case 0x55:
    case 0x5B:
        Transition41_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition41_D_80070328.unk5 = 0;
        Transition41_func_800441F0();
        Transition41_D_80070328.grounded = 1;
        return;
    case 0x56:
    case 0x57:
    case 0x5C:
    case 0x5F:
    case 0x60:
    case 0x61:
        Transition41_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition41_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((unsigned char*)(unsigned char*)&Transition41_D_80070328.movementState + 0x3C), (Vector3D *) ((unsigned char*)(unsigned char*)&Transition41_D_80070328.movementState + 0x48));
            Transition41_D_80070328.unk5 = 1;
        } else {
            Transition41_D_80070328.unk5 = 0;
        }
        Transition41_D_80070328.unk8[0] = Transition41_func_8004EDE8(&Transition41_D_80070328.unk7a[3], 0);
        Transition41_func_80043A38(0xC00);
        Transition41_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition41_D_80070328.grounded = 1;
        goto clearSpecialTail;
    case 0x58:
        Special41_D_80070328.movementState = MOVEMENT_STATE_HURT;
        Special41_D_80070328.unk5 = 0;
        if (Special41_D_80070328.unk22[5] >= 0) {
            tableOffsetOrValue = Special41_D_80070328.unk22[5] * 2;
            tableValueA = *(short*)((unsigned char*)Signed41TableB + tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            tableValueA >>= 1;
            Special41_D_80070328.unk7a[2].x = tableValueA;
            tableOffsetOrValue = *(short*)((unsigned char*)Signed41TableA + tableOffsetOrValue);
            Special41_D_80070328.unk7a[2].z = 0;
            __asm__ __volatile__("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Special41_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
        } else {
            Special41_func_8004F168((Vector3D *) ((unsigned char*)&Special41_D_80070328.movementState + 0x3C));
        }
        Special41_D_80070328.unk7a[2].z = 0x200;
        func_8004F178((Vector3D *) ((unsigned char*)&Special41_D_80070328.unk7a[2].z - 0x14), (Vector3D *) ((unsigned char*)&Special41_D_80070328.unk7a[2].z - 8));
        Special41_D_80070328.grounded = 1;
        Special41_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
    default:
        return;
    case 0x5A:
        Transition41_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition41_D_80070328.unk5 = 0;
        Transition41_func_80043A38(0xC00);
        Transition41_D_80070328.grounded = 1;
        Transition41_D_8006E524 = 0xF;
        return;
    case 0x59:
        Transition41_D_80070328.movementState = MOVEMENT_STATE_FALL;
        if (Transition41_D_80070328.animationState == 0x5F) {
            Transition41_D_80070328.unk5 = 1;
        } else {
            Transition41_D_80070328.unk5 = 0;
        }
        Transition41_D_80070328.unk8[0] = Transition41_func_8004EDE8(&Transition41_D_80070328.unk7a[3], 0);
        Transition41_D_80070328.grounded = 0;
        Transition41_D_80070328.unk15b = 1;
clearSpecialTail:
        Transition41_D_80070328.idle = 0;
        Transition41_D_80070328.unk15g = 0;
        return;
    case 0x5D:
        stateBaseA = Raw41State;
        __asm__("" : "=r"(stateBaseA) : "0"(stateBaseA));
        destination = (Vector3D*)(stateBaseA + 0x3C);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceBytesA = stateBaseA + 0x48;
        *(int*)stateBaseA = 2;
        func_8004F178(destination, (Vector3D*)sourceBytesA);
        Special41_D_80070328.unk8[0] = Special41_func_8004EDE8((Vector3D *) sourceBytesA, 0);
        Special41_D_80070328.unk7a[2].z = 0xA00;
        Special41_D_80070328.unk5 = 0;
        Special41_D_80070328.union144.a.unk13cb=0;
        Special41_D_80070328.grounded = 0;
        PlaySound((int) D_8006C654->jump, 0, 0);
        return;
    case 0x5E: {
        register unsigned char* state __asm__("$2")=Raw41State;
        register Vector3D* source __asm__("$16");
        register Vector3D* argument __asm__("$5");
        register int numericKind __asm__("$17");
        __asm__("" : "=r"(state) : "0"(state));
        destination=(Vector3D*)(state+0x3C);
        __asm__("" : "=r"(destination) : "0"(destination));
        source=(Vector3D*)(state+0x48);
        __asm__ volatile("" : "=r"(source) : "0"(source) : "$17", "memory");
        argument=source;
        __asm__("" : "=r"(argument) : "0"(argument));
        numericKind=2;
        __asm__("" : "=r"(numericKind) : "0"(numericKind));
        *(int*)state=numericKind;
        func_8004F178(destination,argument);
        Transition41_D_80070328.unk8[0]=Transition41_func_8004EDE8(source,0);
        Transition41_D_80070328.unk5=numericKind;
        Transition41_D_80070328.union144.a.unk13cb=0;
        Transition41_D_80070328.grounded=0;
        return;
    }
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_41/animation", func_level_41_80093FF8);
