#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_24/animation", func_level_24_800922B0);

extern Moby* Callback24QueryMoby __asm__("D_80070328+0x250");
extern Moby* Callback24FirstCallMoby __asm__("D_80070328+0x250");
extern Moby* Callback24SecondCallMoby __asm__("D_80070328+0x250");
extern Moby* Callback24InitialMoby __asm__("D_80070328+0x250");
extern int Callback24ClearedWord __asm__("D_80070328+0x28");
extern unsigned char Callback24MobyPointer[] __asm__("D_80070328+0x250");
extern Moby* Callback24Word71930 __asm__("D_80071930");
extern int Callback24WordE1D4 __asm__("D_8006E1D4");
extern int Callback24WordE1D8 __asm__("D_8006E1D8");
extern int Callback24WordE530 __asm__("D_8006E530");
extern int Callback24WordE52C __asm__("D_8006E52C");
extern void (*Callback24Header344)(void) __asm__("unk_ovlheader_80074344");
int Callback24Call80018368(Vector3D*,Vector3D*) __asm__("func_80018368");
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80093C5C.
 * Verified14 supplies byte position and shared query routes; verified13 supplies
 * independently scheduled table/flag paths. Original24 supplies private-data
 * selectors56..61, header344 and numeric helper/vector chains. Pointer offsets
 * are bytes: private4C/50/54/58, selected unsigned byte46 shifted4 and word0,
 * player28+8/-28, playerBC-8C/-BC and global250-250. Vectors at stack18/28
 * use original integers600/0/-380 and400/0/200; their units are unresolved.
 * Separate aliases name the same original addresses to preserve independent
 * loads. Empty constraints emit no instructions and retain original lifetimes,
 * load-delay order and branch targets. Header344 has no newly prepared argument;
 * helper return values are used only in their observed numeric/pointer roles.
 * Helper meanings, selector semantics, cadence and retail runtime remain open.
 * Acceptance requires every code/local-jump/table word, strict full translation
 * unit and complete original EXE and overlay hashes.
 */
extern Spyro Callback24Player __asm__("D_80070328");
int Callback24Call80037058(int x, int y) __asm__("func_80037058");
void Callback24Call80041930(void) __asm__("func_80041930");
void Callback24Call80041AE8(void) __asm__("func_80041AE8");
void Callback24Call80041C20(void) __asm__("func_80041C20");
void Callback24Call80042A44(void) __asm__("func_80042A44");
void Callback24Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback24Word8006E538 __asm__("D_8006E538");
int Callback24Call80055E84(Moby*) __asm__("func_80055E84");
void Callback24Call8004ED6C(void*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
void* Callback24Call8001BA30(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int Callback24Call80019138(Vector3D*,int,int,int,int,Moby*) __asm__("func_80019138");
int Callback24Call8001830C(Vector3D*,Vector3D*,int,int,Moby*) __asm__("func_8001830C");
extern int Callback24Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback24Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback24Values[] __asm__("D_8006FCF0");
void Callback24Call80049590(void) __asm__("func_80049590");
int Callback24Call8003BF6C(int,int) __asm__("func_8003BF6C");
void func_level_24_80093C5C(void) {
    struct {Vector3D first; int reserved24; Vector3D second; int reserved34; } local;
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

    switch(Callback24Player.animationState) {
    case 0x14:
    case 0x55:
        if(func_800438F4()==0)func_80043728();
        Callback24Call80041C20();
        Callback24Player.unk9a=0;
        Callback24Call80042A44();
        goto clearSharedValue;
    case 0x5A:
        Callback24Call80041C20();
        Callback24Call80042A44();
        goto clearSharedValue;
    case 0x1D:
    case 0x58:
        Callback24Call80041C20();
        Callback24Call80042A44();
        goto queryC00;
    case 0x28:
    case 0x29:
    case 0x39:
        Callback24Call80041C20();
        Callback24Call80042A44();
        descriptor=&Callback24Player.unk22[2];
        if (Callback24Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback24Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setDecreasingFlag;
            tableValue=decreasingValue-0xC8;
            goto storeDecreasingValue;
            }
            goto setDecreasingFlag;
storeDecreasingValue:
            *(int*)(Callback24Values + valueOffset) = tableValue;
setDecreasingFlag:
            flagOffset = *descriptor * 0x2C;
            Callback24Flags[flagOffset] = Callback24Flags[flagOffset] | 0x10;
            __asm__ volatile("" : : : "memory");
        }
        goto clearSharedValue;
    case 0x2A:
        Callback24Call80041C20();
        Callback24Call80042A44();
        Callback24Call80049590();
        descriptor=&Callback24Player.unk22[2];
        if (Callback24Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback24Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback24Player.unk22[2];
        }
        if (Callback24Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback24Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback24Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback24Flags[flagOffset] = Callback24Flags[flagOffset] | 0x10;
            __asm__ volatile("" : : : "memory");
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
        Callback24Call80041C20();
        Callback24Call80042A44();
        Callback24Call80041AE8();
        if ((unsigned char) Callback24Player.unk10[4] != 0) {
            computedValue = -Callback24Player.unk9ha[4] - Callback24Call80037058(Callback24Player.position.x, Callback24Player.position.y);
            positionValue = Callback24Player.unk4a - computedValue;
            Callback24Player.unk4[0] = computedValue;
            positionDelta = (int) Callback24Player.union144.a.unk13cc >> 6;
            positionValue -= positionDelta;
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            Callback24Player.position.z=positionValue;
            return;
        }
        break;
    case 0x56:
    case 0x5C:
        privateData=Callback24Player.critterMobyPtr->mobyTag;
        func_800438F4();
        Callback24Call80041C20();
        Callback24Call80042A44();
        Callback24Call80041930();
        if((unsigned char)Callback24Player.unk10[2]!=0) {
            selected=Callback24Word71930;
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
        Callback24Call80041C20();
        Callback24Call80042A44();
        Callback24Call80041930();
        Callback24Call80043A38(0xC00);
        initialMoby=Callback24InitialMoby;
        __asm__ volatile("" : "=r"(initialMoby) : "0"(initialMoby) : "memory");
        clearedWord=&Callback24ClearedWord;
        *clearedWord=0;
        if(initialMoby->animationState.id==2 &&
           Callback24Call80055E84(initialMoby)>=4 &&
           Callback24Call80055E84(Callback24QueryMoby)<13) {
            local.first.x=0x600;
            local.first.y=0;
            local.first.z=-0x380;
            Callback24Call8004ED6C((unsigned char*)clearedWord+8,&local.first,&local.first);
            sourceBase=(unsigned char*)clearedWord-0x28;
            func_8004F194(&local.first,&local.first,(Vector3D*)sourceBase);
            result=Callback24Call8001BA30(&local.first,0x400,1,0,0,Callback24FirstCallMoby);
            if(result) {
                func_8004F178(&local.second,(Vector3D*)((unsigned char*)result+0xC));
                local.second.z+=0x80;
                if(Callback24Call80018368((Vector3D*)sourceBase,&local.second)==0)
                    Callback24Call8001BA30(&local.first,0x400,1,0,0x04000000,Callback24SecondCallMoby);
            }
            {register Vector3D* argument0 __asm__("$4")=&local.first;
            register int argument1 __asm__("$5")=0x400;
            register int argument2 __asm__("$6")=0;
            register int argument3 __asm__("$7")=0;
            register Moby* lastMoby __asm__("$3");
            __asm__ volatile("" : "=r"(argument0), "=r"(argument1), "=r"(argument2), "=r"(argument3) : "0"(argument0), "1"(argument1), "2"(argument2), "3"(argument3) : "memory");
            mobyPointer=(Moby**)Callback24MobyPointer;
            lastMoby=*mobyPointer;
            Callback24Call80019138(argument0,argument1,argument2,argument3,0x04000000,lastMoby); }
            Callback24Call8001830C((Vector3D*)((unsigned char*)mobyPointer-0x250),&local.first,0,0x04000000,*mobyPointer);
            if(Callback24Call80055E84(*mobyPointer)>=8) {
                register int* limitPointer __asm__("$3")=&Callback24WordE1D4;
                if(*limitPointer<0xC00)*limitPointer=0xC00;
                if(Callback24WordE1D8<10)Callback24WordE1D8=10;
                Callback24WordE530=120;
                Callback24WordE52C=5;
            }
        }
        if(Callback24Player.unk5==1) {
            if(Callback24Player.ticksSinceLastSurfaceTouch==0)Callback24Player.unk5=0;
        } else if(Callback24Player.ticksSinceLastSurfaceTouch!=0) {
            Callback24Player.unk5=1;
            Callback24Player.unk7a[2].z=Callback24Player.unk7a[3].z;
        }
        return;
    }
    case 0x59:
        privateOther=Callback24Player.critterMobyPtr->mobyTag;
        Callback24Header344();
        Callback24Call80041C20();
        Callback24Call80042A44();
        Callback24Call80041930();
        if((unsigned char)Callback24Player.unk10[2]!=0) {
            selected=Callback24Word71930;
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
                    Callback24Player.unk5=1;
                } else goto clearSelectedOther;
            }
        } else {
clearSelectedOther:
            *(Moby**)(privateOther+0x4C)=0;
            Callback24Player.unk5=0;
        }
        goto clearSharedValue;
    case 0x5B: {
        register Vector3D* vectorBase __asm__("$16");
        register void* argument0 __asm__("$4");
        if(func_800438F4()==0)func_80043728();
        Callback24Call80041C20();
        Callback24Player.unk9a=0;
        Callback24Call80042A44();
        Callback24Player.unk4[0]=0;
        argument0=(unsigned char*)&Callback24Player.unk9a-0x8C;
        if(Callback24Player.critterMobyPtr->animationState.id==6) {
            vectorBase=&local.second;
            local.second.x=0x400;
            local.second.y=0;
            local.second.z=0x200;
            Callback24Call8004ED6C(argument0,vectorBase,vectorBase);
            func_8004F194(vectorBase,vectorBase,(Vector3D*)((unsigned char*)&Callback24Player.unk9a-0xBC));
            Callback24Call8001BA30(vectorBase,0x400,0,0,0x08000000,Callback24Player.critterMobyPtr);
        }
        return;
    }
    case 0x5D:
    case 0x5E:
        Callback24Call80041C20();
        Callback24Call80042A44();
        Callback24Call80041930();
        if(Callback24Player.unk5!=0x7F) {
            if(Callback24Player.unk7a[3].z<0 && Callback24Player.animationStateFrames>=4)
                Callback24Player.unk5=1;
            else if(Callback24Player.unk5==0 && !(Callback24Word8006E538&0x40) && Callback24Player.union144.a.unk13cb==0)
                Callback24Player.unk5=2;
        }
        goto clearSharedValue;
    case 0x5F:
    case 0x60:
    case 0x61:
        privateData=Callback24Player.critterMobyPtr->mobyTag;
        Callback24Header344();
        func_800438F4();
        Callback24Call80041C20();
        Callback24Call80042A44();
        Callback24Call80041930();
        if((unsigned char)Callback24Player.unk10[2]!=0) {
            selected=Callback24Word71930;
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
        Callback24Call80043A38(0xC00);
clearSharedValue:
        Callback24Player.unk4[0]=0;
        return;
    default:
        return;
    }
}


#define LEVEL_ID 24
#define PlaySpyroSounds_level_24 func_level_24_80094558
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_24_800946C4(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x14:
    case 0x1d:
    case 0x2b:
    case 0x2c:
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
    case 0x59:
    case 0x5d:
    case 0x5e:
        func_80043ABC(0);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80094740.
 * Reuses verified30/44 underwater/surface stack vectors and39 signed table
 * producer, plus verified43 numeric21C/220/224 hurt route. Original24 supplies
 * selector14, shared sound descriptor15/19 call,55..61 routes,58 signed-halfword
 * vectors,5D state50 vector8C/98 and5E saved S1 value2/A1 source98 ordering.
 * Word60 wrap/clamp uses FFF/801/1000; inputs800/801/FFF yield0/-7FF/-1 before
 * helpers. Numeric pointer offsets are bytes, access widths/branches/shifts
 * retain disc instructions. Stack spacing and empty compiler constraints do
 * not imply original C variables. All code/local jumps/owned table words,
 * strict full TU and complete EXE/every overlay hashes are required.
 * Helper meanings, units/conversions, sound semantics and caller cadence are
 * unverified; code executes once per invocation. Live runtime parity is open.
 */
extern Spyro Transition24_D_80070328 __asm__("D_80070328");
int Transition24_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition24_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition24_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition24RawUnion[] __asm__("D_80070328+0x144");
extern int Transition24RawMovement __asm__("D_80070328+0x50");
extern void (*Call24Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw24State[] __asm__("D_80070328+0x50");
extern Spyro Special24_D_80070328 __asm__("D_80070328");
extern short Signed24TableA[] __asm__("D_800658A0");
extern short Signed24TableB[] __asm__("D_80065920");
int Special24_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Special24_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Special24_D_8006E524 __asm__("D_8006E524");

extern int D_80071934;
int Call24A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw24NegativeWord __asm__("D_80070328+0x28");
extern int Raw24TableIndex __asm__("D_80070328+0x298");
extern int Raw24Yaw __asm__("D_80070328+0x64");
int Transition24_func_8003636C(int,int) __asm__("func_8003636C");
void Transition24_func_800441F0(void) __asm__("func_800441F0");
void Transition24_func_80043A38(int) __asm__("func_80043A38");
void func_level_24_80094740(int arg0){
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
    switch(arg0){
    case 0x14:
        Transition24_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition24_D_80070328.unk5 = 0;
        Transition24_func_800441F0();
        Transition24_D_80070328.grounded = 1;
        Transition24_D_80070328.union144.a.unk13cb = Transition24_func_8003636C(1, 3);
        Transition24_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x1D: {
        register int oldState __asm__("$4")=Transition24RawMovement;
        register int first __asm__("$3")=Transition24_D_80070328.unk17e.x;
        register int second __asm__("$2");
        register int third __asm__("$3");
        __asm__("" : "=r"(oldState),"=r"(first) : "0"(oldState),"1"(first) : "memory");
        second=7;
        __asm__("" : "=r"(second) : "0"(second));
        Transition24RawMovement=second;
        __asm__ volatile("" : : : "memory");
        second=Transition24_D_80070328.unk17e.y;
        __asm__ volatile("" : "=r"(second) : "0"(second) : "memory");
        Transition24_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(first) : "0"(first) : "memory");
        first<<=6;
        __asm__("" : "=r"(first) : "0"(first));
        Transition24_D_80070328.unk7a[2].x=first;
        __asm__ volatile("" : : : "memory");
        third=Transition24_D_80070328.unk17e.z;
        second<<=6;
        Transition24_D_80070328.union144.a.unk13cb=oldState;
        Transition24_D_80070328.unk7a[2].y=second;
        second=third<<6;
        if(third==0)second=Transition24_D_80070328.unk7a[3].z;
        Transition24_D_80070328.unk7a[2].z=second;
        Transition24_func_80043A38(0xC00);
        Transition24_D_80070328.grounded=1;
        Transition24_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        soundSelector=D_8006C654->spyroHurt;
        soundZero=0;
        goto sharedSound;
    }

    case 0x28:
    case 0x29:
        if (((unsigned) (Transition24_D_80070328.movementState - 0xB) >= 2U) && (Transition24_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition24_D_80070328.movementState - 0x50));
                if ((Transition24_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw24NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition24_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call24A358(&vectors.first, 0x800);
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
            firstWrappedWord = Transition24_D_80070328.rotation.pitch & 0xFFF;
            Transition24_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition24_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition24_D_80070328.rotation.pitch > 0) {
                Transition24_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition24_D_80070328.unk5 = 1;
            }
            Transition24_func_8004F168((Vector3D *) ((unsigned char*)&Transition24_D_80070328.rotation.pitch + 0xEC));
            Transition24_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition24_D_80070328.unk8[0] = Transition24_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition24_D_80070328.rotation.pitch + 0x38), 0);
            Transition24_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition24_D_80070328.animationState == 0x2A) {
            Transition24_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition24_D_80070328.union144.a.unk13da = 0;
        }
        Transition24_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition24_D_80070328.unk20a = 0;
        Transition24_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw24State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw24NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition24_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call24A358(localVector, 0x800);
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
            if (Transition24_D_80070328.animationState == 0x2E) {
                Transition24_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition24_D_80070328.rotation.pitch & 0xFFF;
            Transition24_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition24_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition24_D_80070328.rotation.pitch > 0) {
                Transition24_D_80070328.rotation.pitch = 0;
            }
            Transition24_D_80070328.unk5 = 1;
            Transition24_func_8004F168((Vector3D *) ((unsigned char*)&Transition24_D_80070328.animationState + 0x104));
            Transition24_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition24_D_80070328.unk8[0] = Transition24_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition24_D_80070328.animationState + 0x50), 0);
            Transition24_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition24_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition24_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition24RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition24RawUnion;
            *(int*)unionPointer=(-Transition24_D_80070328.unk7a[2].z)>>2;
            if(Transition24RawMovement!=8){Transition24_D_80070328.union144.a.unk13cc=0x5900;Transition24RawMovement=10;}
            Transition24_D_80070328.unk5=0;
            Transition24_D_80070328.unk8[0]=Transition24_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition24_D_80070328.grounded=1;
            Transition24_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call24A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x39: {
        register int previousMovement __asm__("$2")=Transition24RawMovement;
        register int numericKind __asm__("$3");
        register int indexWord __asm__("$3");
        register unsigned char* unionPointer __asm__("$5");
        register int tableOffset __asm__("$2");
        register int tableWord __asm__("$3");
        __asm__("" : "=r"(previousMovement) : "0"(previousMovement));
        numericKind=7;
        __asm__("" : "=r"(numericKind) : "0"(numericKind));
        Transition24RawMovement=numericKind;
        __asm__ volatile("" : : : "memory");
        indexWord=Raw24TableIndex;
        __asm__ volatile("" : "=r"(indexWord) : "0"(indexWord) : "memory");
        unionPointer=Transition24RawUnion;
        __asm__("" : "=r"(indexWord),"=r"(unionPointer) : "0"(indexWord),"1"(unionPointer) : "memory");
        Transition24_D_80070328.unk5=0;
        *(int*)unionPointer=previousMovement;
        if(indexWord<0)Raw24TableIndex=((Raw24Yaw+0x800)>>4)&0xFF;
        tableOffset=Raw24TableIndex*2;
        tableWord=*(short*)((unsigned char*)Signed24TableB+tableOffset);
        destination=(Vector3D*)(unionPointer-0xC4);
        *(int*)(unionPointer-0xB8)=tableWord;
        tableOffset=*(short*)((unsigned char*)Signed24TableA+tableOffset);
        Transition24_D_80070328.unk7a[2].z=0;
        Transition24_D_80070328.unk7a[2].y=tableOffset;
        func_8004F178(destination,(Vector3D*)(unionPointer-0xB8));
        Transition24_D_80070328.grounded=1;
        Transition24_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        { register unsigned char* soundTable __asm__("$2")=(unsigned char*)D_8006C654;
        __asm__ volatile("" : "=r"(soundTable) : "0"(soundTable) : "memory");
        soundZero=0;
        soundSelector=soundTable[0x19]; }
sharedSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
    }
clearPointers:
        Transition24_D_80070328.unk20a=0;
        Transition24_D_80070328.critterMobyPtr=0;
        return;
    case 0x55:
    case 0x5B:
        Transition24_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition24_D_80070328.unk5 = 0;
        Transition24_func_800441F0();
        Transition24_D_80070328.grounded = 1;
        return;
    case 0x56:
    case 0x57:
    case 0x5C:
    case 0x5F:
    case 0x60:
    case 0x61:
        Transition24_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition24_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((unsigned char*)(unsigned char*)&Transition24_D_80070328.movementState + 0x3C), (Vector3D *) ((unsigned char*)(unsigned char*)&Transition24_D_80070328.movementState + 0x48));
            Transition24_D_80070328.unk5 = 1;
        } else {
            Transition24_D_80070328.unk5 = 0;
        }
        Transition24_D_80070328.unk8[0] = Transition24_func_8004EDE8(&Transition24_D_80070328.unk7a[3], 0);
        Transition24_func_80043A38(0xC00);
        Transition24_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition24_D_80070328.grounded = 1;
        goto clearSpecialTail;
    case 0x58:
        Special24_D_80070328.movementState = MOVEMENT_STATE_HURT;
        Special24_D_80070328.unk5 = 0;
        if (Special24_D_80070328.unk22[5] >= 0) {
            tableOffsetOrValue = Special24_D_80070328.unk22[5] * 2;
            tableValueA = *(short*)((unsigned char*)Signed24TableB + tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            tableValueA >>= 1;
            Special24_D_80070328.unk7a[2].x = tableValueA;
            tableOffsetOrValue = *(short*)((unsigned char*)Signed24TableA + tableOffsetOrValue);
            Special24_D_80070328.unk7a[2].z = 0;
            __asm__ __volatile__("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Special24_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
        } else {
            Special24_func_8004F168((Vector3D *) ((unsigned char*)&Special24_D_80070328.movementState + 0x3C));
        }
        Special24_D_80070328.unk7a[2].z = 0x200;
        func_8004F178((Vector3D *) ((unsigned char*)&Special24_D_80070328.unk7a[2].z - 0x14), (Vector3D *) ((unsigned char*)&Special24_D_80070328.unk7a[2].z - 8));
        Special24_D_80070328.grounded = 1;
        Special24_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
    default:
        return;
    case 0x5A:
        Transition24_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition24_D_80070328.unk5 = 0;
        Transition24_func_80043A38(0xC00);
        Transition24_D_80070328.grounded = 1;
        Transition24_D_8006E524 = 0xF;
        return;
    case 0x59:
        Transition24_D_80070328.movementState = MOVEMENT_STATE_FALL;
        if (Transition24_D_80070328.animationState == 0x5F) {
            Transition24_D_80070328.unk5 = 1;
        } else {
            Transition24_D_80070328.unk5 = 0;
        }
        Transition24_D_80070328.unk8[0] = Transition24_func_8004EDE8(&Transition24_D_80070328.unk7a[3], 0);
        Transition24_D_80070328.grounded = 0;
        Transition24_D_80070328.unk15b = 1;
clearSpecialTail:
        Transition24_D_80070328.idle = 0;
        Transition24_D_80070328.unk15g = 0;
        return;
    case 0x5D:
        stateBaseA = Raw24State;
        __asm__("" : "=r"(stateBaseA) : "0"(stateBaseA));
        destination = (Vector3D*)(stateBaseA + 0x3C);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceBytesA = stateBaseA + 0x48;
        *(int*)stateBaseA = 2;
        func_8004F178(destination, (Vector3D*)sourceBytesA);
        Special24_D_80070328.unk8[0] = Special24_func_8004EDE8((Vector3D *) sourceBytesA, 0);
        Special24_D_80070328.unk7a[2].z = 0xA00;
        Special24_D_80070328.unk5 = 0;
        Special24_D_80070328.union144.a.unk13cb=0;
        Special24_D_80070328.grounded = 0;
        PlaySound((int) D_8006C654->jump, 0, 0);
        return;
    case 0x5E: {
        register unsigned char* state __asm__("$2")=Raw24State;
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
        Transition24_D_80070328.unk8[0]=Transition24_func_8004EDE8(source,0);
        Transition24_D_80070328.unk5=numericKind;
        Transition24_D_80070328.union144.a.unk13cb=0;
        Transition24_D_80070328.grounded=0;
        return;
    }
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_24/animation", func_level_24_8009518C);
