#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_42/animation", func_level_42_80089628);

/* AI generated; not human reviewed. SCUS-94467 8008C0C4..8008C964.
 * Verified11 standalone case47/table,23 shared flag and43 clamp/case31 paths
 * combined only against original42 instructions. All original words, strict
 * complete TU and every retail hash required; units/helpers/cadence unresolved.
 * Original42 independent1D/13 blocks at8008C17C..8008C1A8 target query/helper
 * tails separately; source order and every internal jump target agree.
 * Standalone stack18 vector andS1 mask02000000 retain original case47 numeric
 * chain. Byte offsets28+70,44-14/44-44 and table8006D048+14 are not semantics.
 * Empty constraints emit no instructions; compiled equality is not runtime parity.
 */
extern Spyro Callback42Player __asm__("D_80070328");
int Callback42Call80037058(int x, int y) __asm__("func_80037058");
void Callback42Call80041930(void) __asm__("func_80041930");
void Callback42Call80041AE8(void) __asm__("func_80041AE8");
void Callback42Call80041C20(void) __asm__("func_80041C20");
void Callback42Call80042A44(void) __asm__("func_80042A44");
void Callback42Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback42Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38,D_8006C648;
extern int D_80071924;
extern int** Callback42Table __asm__("D_8006D048+0x14");
int Callback42Call80055E84(Moby*) __asm__("func_80055E84");
void Callback42Call8004ED6C(void*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
void Callback42Call8001BA30(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int Callback42Call80019138(Vector3D*,int,int,int,int,Moby*) __asm__("func_80019138");
int Callback42Call8001830C(Vector3D*,Vector3D*,int,int,Moby*) __asm__("func_8001830C");
extern int Callback42Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback42Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback42Values[] __asm__("D_8006FCF0");
void Callback42Call80049590(void) __asm__("func_80049590");
int Callback42Call8003BF6C(int,int) __asm__("func_8003BF6C");
extern int Callback42FlagWord __asm__("D_80070328+0x4C");
extern int D_8006C648;
int Callback42Length(Vector3D*,int) __asm__("func_8004EDE8");
void func_level_42_8008C0C4(void) {
    Vector3D localVector;
    register int computedValue __asm__("$4");
    register int clampedValue __asm__("$4");
    register int numerator __asm__("$2");
    register int belowLimit __asm__("$2");
    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    int descriptorResult;
    int flagOffset;

    register int positionDelta __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback42Player.animationState) {
    case 0x14:
    case 0x41:
        if(func_800438F4()==0)func_80043728();
        Callback42Call80041C20();
        Callback42Player.unk9a=0;
        Callback42Call80042A44();
        goto clearSharedValue;
    default:
        return;
    case 0x44:
    case 0x4A:
        Callback42Call80041C20();
        Callback42Call80042A44();
        goto clearSharedValue;
    case 0x42:
    case 0x45:
        func_800438F4();
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80041930();
        goto queryC00;
    case 0x1D:
        Callback42Call80041C20();
        Callback42Call80042A44();
        goto queryC00;
    case 0x13:
        Callback42Call80041C20();
        Callback42Call80042A44();
        goto call41930;
    case 0x1C:
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80041930();
        if(Callback42Player.unk7a[3].z < 0 && Callback42Player.animationStateFrames >= 4) {
setFirstFlag:
            Callback42Player.unk5=1;
        }
        goto clearSharedValue;
    case 0x26:
    case 0x28:
    case 0x29:
        Callback42Call80041C20();
        Callback42Call80042A44();
        descriptor=&Callback42Player.unk22[2];
        if (Callback42Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback42Values + valueOffset);
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
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80049590();
        descriptor=&Callback42Player.unk22[2];
        if (Callback42Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback42Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback42Player.unk22[2];
        }
        if (Callback42Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback42Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback42Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback42Flags[flagOffset] = Callback42Flags[flagOffset] | 0x10;
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80041AE8();
        if ((unsigned char) Callback42Player.unk10[4] != 0) {
            computedValue = -Callback42Player.unk9ha[4] - Callback42Call80037058(Callback42Player.position.x, Callback42Player.position.y);
            positionValue = Callback42Player.unk4a - computedValue;
            Callback42Player.unk4[0] = computedValue;
            positionDelta = (int) Callback42Player.union144.a.unk13cc >> 6;
            positionValue -= positionDelta;
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            Callback42Player.position.z=positionValue;
            return;
        }
        break;
    case 0x2F:
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80041930();
        func_80042F64();
        goto clearSharedValue;
    case 0x31:
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80043A38(0xC00);
        if (func_80040954(Callback42Player.unk11[2]) == 0xA) {
            Callback42Player.union144.a.unk13cb = 0;
        } else {
            Callback42Player.union144.a.unk13cb += D_8006C648;
        }
        Callback42Player.unk4[0] = 0;
        if (Callback42Call8003BF6C((int) D_8006C654->unk32, Callback42Player.unk22[2]) == 0) {
            Callback42Player.unk22[2] = PlaySound((int) D_8006C654->unk32, 0, 4);
            Callback42Player.unk22[3] = (int) D_8006C654->unk32;
            return;
        }
        break;
    case 0x32:
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80041930();
        func_80042F64();
        numerator=(int)((unsigned int)Callback42Player.unk7a[3].z << 2);
        Callback42Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)((unsigned int)ABS(numerator) + 0x300U) / 1536;
        __asm__("" : "=r"(quotient) : "0"(quotient));
        clampedValue=quotient<<4;}
        belowLimit = clampedValue < 0x10;
        __asm__("" : "=r"(belowLimit) : "0"(belowLimit));
        if (belowLimit) {
            clampedValue = 0x10;
            goto compareUpperLimit;
        }
        goto compareUpperLimit;
    case 0x33:
    case 0x34:
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80041930();
        func_80042F64();
        Callback42Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)(((unsigned int)Callback42Length((Vector3D *) ((unsigned char*)Callback42Player.unk4 + 0x70), 0) << 2) + 0x300U) / 1536;
        __asm__("" : "=r"(quotient) : "0"(quotient));
        clampedValue=quotient<<4;}
        belowLimit = clampedValue < 8;
        __asm__("" : "=r"(belowLimit) : "0"(belowLimit));
        if (belowLimit) {
            clampedValue = 8;
            goto compareUpperLimit;
        }
        goto compareUpperLimit;
compareUpperLimit:
        belowLimit=clampedValue<0x41;
applyUpperLimit:
        if(!belowLimit)clampedValue=0x40;
        func_800443A4(clampedValue);
        return;
    case 0x3A:
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Player.cheatColour.a=255;
        Callback42Player.unk4[0]=0;
        Callback42Player.cheatColour.b=32;
        Callback42Player.cheatColour.g=32;
        Callback42Player.cheatColour.r=32;
        return;
    case 0x43:
    case 0x46:
    case 0x49:
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80041930();
        if(Callback42Player.unk7a[3].z < 0 && Callback42Player.animationStateFrames >= 4)goto setFirstFlag;
        {register int* flagWord __asm__("$3")=&Callback42FlagWord;
        __asm__("" : "=r"(flagWord) : "0"(flagWord));
        if(*flagWord==0 && !(Callback42Word8006E538 & 0x40) && Callback42Player.union144.a.unk13cb==0)
            *flagWord=2;}
        goto clearSharedValue;
    case 0x47: {
        register int progress __asm__("$4");
        register int value __asm__("$2");
        register int* sourceBase __asm__("$16");
        register int flags __asm__("$17");
        if(Callback42Player.ticksSinceLastSurfaceTouch) {
            Callback42Call80041C20();
            Callback42Call80042A44();
        } else {
            func_800438F4();
            Callback42Call80041C20();
            Callback42Call80042A44();
            Callback42Call80041930();
            Callback42Call80043A38(0xC00);
        }
        progress=Callback42Call80055E84(Callback42Player.critterMobyPtr);
        if(Callback42Player.critterMobyPtr->animationState.id==6 && (unsigned int)(progress-2)<6) {
            if(progress<6)value=(progress<<10)/6;
            else value=0x400;
            localVector.x=value;
            __asm__ volatile("" : : : "memory");
            sourceBase=&Callback42Player.unk4a;
            localVector.y=0;
            localVector.z=0x200-*sourceBase;
            Callback42Call8004ED6C((unsigned char*)sourceBase-0x14,(&localVector),(&localVector));
            {register Vector3D* argument0 __asm__("$4")=(&localVector);
            register Vector3D* argument1 __asm__("$5")=(&localVector);
            __asm__("" : "=r"(argument0), "=r"(argument1) : "0"(argument0), "1"(argument1));
            sourceBase=(int*)((unsigned char*)sourceBase-0x44);
            func_8004F194(argument0,argument1,(Vector3D*)sourceBase);}
            flags=0x02000000;
            Callback42Call8001BA30((&localVector),0x200,0,0,flags,Callback42Player.critterMobyPtr);
            if((Callback42Call80019138((&localVector),0x200,0,0,flags,Callback42Player.critterMobyPtr)!=0 ||
                Callback42Call8001830C((Vector3D*)sourceBase,(&localVector),0,0x02000000,Callback42Player.critterMobyPtr)!=0)) {
                register int* selector __asm__("$16")=&D_80071924;
                if(func_80040954(*selector)==3) {
                    register int index __asm__("$2")=*selector;
                    register int** table __asm__("$3")=Callback42Table;
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
        Callback42Call80041C20();
        Callback42Call80042A44();
        if(Callback42Player.unk5==1)func_800494A8();
        goto clearSharedValue;
    case 0x48:
        Callback42Call80041C20();
        Callback42Call80042A44();
        if(Callback42Player.unk5!=0)goto call41930;
queryC00:
        Callback42Call80043A38(0xC00);
        goto clearSharedValue;
call41930:
        Callback42Call80041930();
clearSharedValue:
        Callback42Player.unk4[0]=0;
        return;
    }
}


#define LEVEL_ID 42
#define PlaySpyroSounds_level_42 func_level_42_8008C968
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_42_8008CB78(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x13:
    case 0x1c:
    case 0x43:
    case 0x44:
    case 0x46:
    case 0x49:
    case 0x4b:
    case 0x4c:
    case 0x4d:
        func_80043ABC(0);
        break;
    case 0x2f:
    case 0x32:
    case 0x33:
    case 0x34:
        func_80043F3C(&spyro.unk9h);
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
    case 0x1d:
    case 0x2b:
    case 0x2c:
    case 0x31:
    case 0x3a:
    case 0x41:
    case 0x42:
    case 0x45:
    case 0x4a:
        func_80043ABC(&spyro.unk9e);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008CC20.
 * Verified11 water/character,37 numeric1D,23 vector/ladder,21 entry26,
 * 32 slide. Original42 shared hurt call at1C and independent entry26 retained.
 * Numeric offsets are bytes. Stack10/20/30 water and40 jump preserved.
 * Word60 wrap800/801/FFF gives0/-7FF/-1; signed table-2/0/2 gives-1/0/1.
 * Each invocation preserves every code/internal jump/owned table word;
 * strict complete TU and every original hash required. Helper meanings,
 * physical units, audio, cadence and live parity remain open.
 */
extern short D_800658A0[];
extern short D_80065920[];
extern int Raw42Animation __asm__("D_80070328+0x48");
extern unsigned char Raw42Union[] __asm__("D_80070328+0x144");
extern unsigned char Raw42Movement[] __asm__("D_80070328+0x50");
extern int Raw42X __asm__("D_80070328+0x8C");
extern int Raw42Word __asm__("D_80070328+0x50");
int Transition42_func_8004E880(int,int,int) __asm__("func_8004E880");
void Transition42_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");
extern Spyro Transition42_D_80070328 __asm__("D_80070328");
int Transition42_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition42_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition42_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition42RawUnion[] __asm__("D_80070328+0x144");
extern int Transition42RawMovement __asm__("D_80070328+0x50");
extern void (*Call42Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw42State[] __asm__("D_80070328+0x50");

extern int D_80071934;
int Call42A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw42NegativeWord __asm__("D_80070328+0x28");
int Transition42_func_8003636C(int,int) __asm__("func_8003636C");
void Transition42_func_800441F0(void) __asm__("func_800441F0");
void Transition42_func_80043A38(int) __asm__("func_80043A38");
int Transition42_func_8004E880(int,int,int) __asm__("func_8004E880");
void func_level_42_8008CC20(int arg0){
    struct {Vector3D first; int gap1; Vector3D second; int gap2; Vector3D third; int gap3; Vector3D fourth;} vectors;
    register int negativeWord __asm__("$3");
    int firstResult,secondResult,firstWrappedWord,secondWrappedWord,firstParticleKind,secondParticleKind,firstParticleSubtype,secondParticleSubtype;
    register Vector3D* destination __asm__("$4");

    int lengthResult;


    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* savedBase __asm__("$3");
    register unsigned char* privateData __asm__("$16");
    register unsigned char* stateBase __asm__("$17");
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
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");
    switch(arg0){
    case 0x14:
        Transition42_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.unk5 = 0;
        Transition42_func_800441F0();
        Transition42_D_80070328.grounded = 1;
        Transition42_D_80070328.union144.a.unk13cb = Transition42_func_8003636C(1, 3);
        Transition42_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        stateBase=(unsigned char*)&Transition42RawMovement;
        privateData = Transition42_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition42_D_80070328.unk5 = 0;
        Transition42_D_80070328.grounded = 0;
        Transition42_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition42_D_80070328.m_WhirlwindPointer;
        yawValue=Transition42_D_80070328.rotation.yaw;
        positionZ=Transition42_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition42_D_80070328.union144.a.unk13cc=yawValue;
        Transition42_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition42_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition42_D_80070328.union144.a.unk13ce.z=heightValue;
        __asm__ volatile("" : : : "memory");
        heightValue = ((int) (heightValue << 0xA) >> 0xA) + 0x400;
        __asm__("" : "=r"(heightValue) : "0"(heightValue));
        Transition42_D_80070328.union144.a.unk13ce.y = heightValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
        Transition42_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition42_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition42_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition42_D_80070328.unk13e[0] = (int) Transition42_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition42_D_80070328.unk20a = 0;
        Transition42_D_80070328.critterMobyPtr = 0;
        Transition42_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x1D: {
        register int oldState __asm__("$4")=Transition42RawMovement;
        register int first __asm__("$3")=Transition42_D_80070328.unk17e.x;
        register int second __asm__("$2");
        register int third __asm__("$3");
        __asm__("" : "=r"(oldState),"=r"(first) : "0"(oldState),"1"(first) : "memory");
        second=7;
        __asm__("" : "=r"(second) : "0"(second));
        Transition42RawMovement=second;
        __asm__ volatile("" : : : "memory");
        second=Transition42_D_80070328.unk17e.y;
        __asm__ volatile("" : "=r"(second) : "0"(second) : "memory");
        Transition42_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(first) : "0"(first) : "memory");
        first<<=6;
        __asm__("" : "=r"(first) : "0"(first));
        Transition42_D_80070328.unk7a[2].x=first;
        __asm__ volatile("" : : : "memory");
        third=Transition42_D_80070328.unk17e.z;
        second<<=6;
        Transition42_D_80070328.union144.a.unk13cb=oldState;
        Transition42_D_80070328.unk7a[2].y=second;
        second=third<<6;
        if(third==0)second=Transition42_D_80070328.unk7a[3].z;
        Transition42_D_80070328.unk7a[2].z=second;
        Transition42_func_80043A38(0xC00);
        Transition42_D_80070328.grounded=1;
        Transition42_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        soundSelector=D_8006C654->spyroHurt;
        soundZero=0;
        goto sharedHurtSound;
        goto clearPointers;
    }

    case 0x1C:
        savedBase = Transition42RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Transition42RawMovement;
        Transition42RawMovement = MOVEMENT_STATE_HURT;
        Transition42_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8(sourceC, 0);
        Transition42_D_80070328.unk7a[2].z = 0xDC0;
        Transition42_D_80070328.grounded = 0;
        Transition42_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        soundZero=0;
        if (Transition42_D_80070328.damageFlags & 0x200) {
            Transition42_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition42_D_80070328.union144.a.unk13cc = 1;
            soundSelector=D_8006C654->lavaBurn;
sharedHurtSound:
            PlaySound(soundSelector,(Moby*)soundZero,0);
        }
        goto clearPointers;
    case 0x3A:
        Transition42_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition42_D_80070328.unk5 = 0;
        Transition42_func_80043A38(0xC00);
        Transition42_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition42_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x26:
        Transition42_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        if (Transition42_D_80070328.animationState == 0x2A) {
            Transition42_D_80070328.unk5 = 2;
        }
        Transition42_func_8004F168((Vector3D *) ((unsigned char*)&Transition42_D_80070328.movementState + 0xFC));
        Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition42_D_80070328.movementState + 0x48), 0);
        Transition42_D_80070328.grounded = 1;
        Transition42_D_80070328.unk4a = 0x280;
        return;
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition42_D_80070328.movementState - 0xB) >= 2U) && (Transition42_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition42_D_80070328.movementState - 0x50));
                if ((Transition42_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw42NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition42_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call42A358(&vectors.first, 0x800);
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
            firstWrappedWord = Transition42_D_80070328.rotation.pitch & 0xFFF;
            Transition42_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition42_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition42_D_80070328.rotation.pitch > 0) {
                Transition42_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition42_D_80070328.unk5 = 1;
            }
            Transition42_func_8004F168((Vector3D *) ((unsigned char*)&Transition42_D_80070328.rotation.pitch + 0xEC));
            Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition42_D_80070328.rotation.pitch + 0x38), 0);
            Transition42_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition42_D_80070328.animationState == 0x2A) {
            Transition42_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition42_D_80070328.union144.a.unk13da = 0;
        }
        Transition42_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition42_D_80070328.unk20a = 0;
        Transition42_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw42State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw42NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition42_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call42A358(localVector, 0x800);
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
            if (Transition42_D_80070328.animationState == 0x2E) {
                Transition42_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition42_D_80070328.rotation.pitch & 0xFFF;
            Transition42_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition42_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition42_D_80070328.rotation.pitch > 0) {
                Transition42_D_80070328.rotation.pitch = 0;
            }
            Transition42_D_80070328.unk5 = 1;
            Transition42_func_8004F168((Vector3D *) ((unsigned char*)&Transition42_D_80070328.animationState + 0x104));
            Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition42_D_80070328.animationState + 0x50), 0);
            Transition42_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition42_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition42_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition42RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition42RawUnion;
            *(int*)unionPointer=(-Transition42_D_80070328.unk7a[2].z)>>2;
            if(Transition42RawMovement!=8){Transition42_D_80070328.union144.a.unk13cc=0x5900;Transition42RawMovement=10;}
            Transition42_D_80070328.unk5=0;
            Transition42_D_80070328.unk8[0]=Transition42_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition42_D_80070328.grounded=1;
            Transition42_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call42A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x31: {
        register unsigned char* lengthBase __asm__("$5")=(unsigned char*)&Transition42_D_80070328.unk8[0];
        register int valueA __asm__("$4");
        register int valueB __asm__("$5");
        register int valueKind __asm__("$6");
        *(int*)lengthBase=0;
        if(Transition42_D_80070328.animationState==0xD || Transition42_D_80070328.movementState==1)
            func_8004F178((Vector3D*)(lengthBase-0x30),(Vector3D*)(lengthBase-0x18));
        else Transition42_func_8004F168((Vector3D*)(lengthBase-0x30));
        func_8004F178(&Transition42_D_80070328.unk7a[2],(Vector3D*)((unsigned char*)&Transition42_D_80070328.unk7a[2]-0xC));
        Transition42_D_80070328.movementState=17;
        Transition42_D_80070328.unk5=0;
        Transition42_func_80043A38(0xC00);
        Transition42_D_80070328.grounded=0;
        Transition42_D_80070328.union144.a.unk13cb=0;
        valueKind=1;
        if(Transition42_D_80070328.unk9ha[0]>=11) {
            valueA=Transition42_D_80070328.unk9e.x;
            valueB=Transition42_D_80070328.unk9e.y;
        } else {
            valueA=Transition42_D_80070328.unk7a[3].x;
            valueB=valueA;
        }
        Transition42_D_80070328.union144.a.unk13cc=Transition42_func_8004E880(valueA,valueB,valueKind);
        goto clearPointers;
    }
    case 0x2F:case 0x32:case 0x33:case 0x34:
        savedBase=Raw42Movement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition42_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            Transition42_D_80070328.grounded=1;
        }
clearPointers:
        Transition42_D_80070328.unk20a=0;
        Transition42_D_80070328.critterMobyPtr=0;
        return;
    case 0x41:
        Transition42_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition42_func_800441F0();
        Transition42_D_80070328.grounded = 1;
        return;
    case 0x42:
    case 0x45:
        Transition42_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition42_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition42_D_80070328.movementState) + 0x3C)), (Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition42_D_80070328.movementState) + 0x48)));
            Transition42_D_80070328.unk5 = MOVEMENT_STATE_WALK;
        } else {
            Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        }
        Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8(&Transition42_D_80070328.unk7a[3], 0);
        Transition42_func_80043A38(0xC00);
        Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.grounded = 1;
        goto clearFlags;
    case 0x43:
    case 0x49:
        initialMovement=Raw42Movement;
        __asm__("" : "=r"(initialMovement) : "0"(initialMovement));
        comparisonKind=10;
        __asm__("" : "=r"(comparisonKind) : "0"(comparisonKind));
        {register Moby* critter __asm__("$3")=Transition42_D_80070328.critterMobyPtr;
        register int current __asm__("$4")=*(int*)initialMovement;
        __asm__("" : "=r"(critter),"=r"(current) : "0"(critter),"1"(current));
        jumpPrivate=critter->mobyTag;
        __asm__("" : "=r"(jumpPrivate) : "0"(jumpPrivate));
        if ((current == comparisonKind) && (SpawnParticle != 0) && (Transition42_D_80070328.unk4[0] < 0)) {
            jumpVector=&vectors.fourth;
            func_8004F178(jumpVector, (Vector3D*)(initialMovement-0x50));
            vectors.fourth.z = -Transition42_D_80070328.unk4[0];
            SpawnParticle(6, 0x2E, jumpVector, 0);
            SpawnParticle(4, 0x29, jumpVector, 0);
        }
        }
        movement=Raw42Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        firstJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) firstJumpSource);
        Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8((Vector3D *) firstJumpSource, 0);
        if (arg0 == 0x49) {
            Transition42_D_80070328.unk7a[2].z = 0x2580;
        } else {
            Transition42_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)jumpPrivate+0x4C) = 0;
        }
        Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
        goto playJumpSound;
    case 0x44:
        Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        if (Transition42_D_80070328.movementState == MOVEMENT_STATE_JUMP_HOVER) {
            if(Transition42_D_80070328.animationState==0x43)Transition42_D_80070328.unk5=1;
            else if(Transition42_D_80070328.animationState==0x46)Transition42_D_80070328.unk5=Transition42_D_80070328.movementState;
            else if(Transition42_D_80070328.animationState==0x49)Transition42_D_80070328.unk5=4;
        } else {
            Transition42_D_80070328.movementState = MOVEMENT_STATE_FALL;
        }
        Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8(&Transition42_D_80070328.unk7a[3], 0);
        Transition42_D_80070328.grounded = 0;
        goto clearFlags;
    case 0x46:
        movement=Raw42Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        secondJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) secondJumpSource);
        Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8((Vector3D *) secondJumpSource, 0);
        Transition42_D_80070328.unk7a[2].z = 0x12C0;
        Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
playJumpSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
        return;
    case 0x47:
        if (Transition42_D_80070328.ticksSinceLastSurfaceTouch != 0) {
            if (Transition42_D_80070328.movementState != MOVEMENT_STATE_FALL) {
                if (Transition42_D_80070328.animationState == 0x43) {
                    Transition42_D_80070328.unk5 = MOVEMENT_STATE_WALK;
                } else if (Transition42_D_80070328.animationState == 0x46) {
                    Transition42_D_80070328.unk5 = MOVEMENT_STATE_JUMP_HOVER;
                } else {
                    Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
                }
            }
            Transition42_D_80070328.movementState = MOVEMENT_STATE_FALL;
            Transition42_D_80070328.grounded = 0;
            Transition42_D_80070328.idle = 0;
            Transition42_D_80070328.unk15g = 0;
        } else {
            Transition42_D_80070328.movementState = MOVEMENT_STATE_WALK;
            Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            Transition42_func_80043A38(0xC00);
            Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition42_D_80070328.grounded = 1;
        }
        Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8(&Transition42_D_80070328.unk7a[3], 0);
        goto clearFlags;
clearFlags:
        Transition42_D_80070328.idle = 0;
        Transition42_D_80070328.unk15g = 0;
        return;
    case 0x48: {
        register Moby* critter __asm__("$2")=Transition42_D_80070328.critterMobyPtr;
        __asm__ volatile("" : "=r"(critter) : "0"(critter) : "memory");
        damagePrivate=critter->mobyTag;
        __asm__ volatile("" : "=r"(damagePrivate) : "0"(damagePrivate) : "memory");
        previousValue=Raw42Word;
        __asm__ volatile("" : "=r"(previousValue) : "0"(previousValue) : "memory");
        unionBase=Raw42Union;
        __asm__("" : "=r"(previousValue),"=r"(unionBase) : "0"(previousValue),"1"(unionBase));
        *(int*)unionBase=previousValue;
        Raw42Word = MOVEMENT_STATE_HURT;
        if (Transition42_D_80070328.damageFlags & 8) {
            damageSource = (Vector3D *) (unionBase - 0xAC);
            Transition42_D_80070328.unk5 = MOVEMENT_STATE_WALK;
            func_8004F178((Vector3D *) (unionBase - 0xB8), damageSource);
            Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8(damageSource, 0);
            soundTable=(unsigned char*)D_8006C654;
            soundZero=0;
            __asm__ volatile("" : "=r"(soundTable),"=r"(soundZero) : "0"(soundTable),"1"(soundZero) : "memory");
            Transition42_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)damagePrivate+0x4C) = 0;
            Transition42_D_80070328.grounded = 0;
            Transition42_D_80070328.union144.a.unk13cc = 1;
            PlaySound(soundTable[12],(Moby*)soundZero,0);
        } else {
            Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            damageDestination = (Vector3D *) (unionBase - 0xB8);
            if (Transition42_D_80070328.unk17a & 0x400) {
                func_8004F178(damageDestination, (Vector3D *) ((Vector3D *) (unionBase + 0xD8)));
                Transition42_func_8004F0E8(damageDestination, 6);
            } else if (Transition42_D_80070328.unk22[5] >= 0) {
                tableIndex=Transition42_D_80070328.unk22[5]*2;
                tableValue=*(short*)((unsigned char*)D_80065920+tableIndex);
                __asm__("" : "=r"(tableValue) : "0"(tableValue));
                Raw42X=tableValue>>1;
                tableIndex=*(short*)((unsigned char*)D_800658A0+tableIndex);
                Transition42_D_80070328.unk7a[2].z=0;
                __asm__ volatile("" : "=r"(tableIndex) : "0"(tableIndex) : "memory");
                Transition42_D_80070328.unk7a[2].y=tableIndex>>1;
            } else {
                    __asm__("" : "=r"(unionBase) : "0"(unionBase));
                Transition42_func_8004F168((Vector3D*)(unionBase-0xB8));
            }
            func_8004F178(&Transition42_D_80070328.unk7a[1], (Vector3D *) ((unsigned char*)(&Transition42_D_80070328.unk7a[1]) + 0xC));
            Transition42_func_80043A38(0xC00);
            Transition42_D_80070328.grounded = 1;
        }
        Transition42_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
        break;
    }
    case 0x4A:
        Transition42_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition42_func_80043A38(0xC00);
        Transition42_D_80070328.grounded = 1;
        Transition42_D_8006E524 = 0xF;
        return;
    case 0x4B:
        firstAnimation=Raw42Animation;
        __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        if(firstAnimation==0x44){
            if(Transition42_D_80070328.unk5==4)goto setHeadbashFlag;
            comparisonKind=0x49;
            __asm__ volatile("" : "=r"(comparisonKind) : "0"(comparisonKind) : "memory");
            firstAnimation=Raw42Animation;
            __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        }else comparisonKind=0x49;
        if(firstAnimation==comparisonKind){
setHeadbashFlag:
            Transition42_D_80070328.union144.a.unk13cc=1;
        }else Transition42_D_80070328.union144.a.unk13cc=0;
        Transition42_D_80070328.movementState = MOVEMENT_STATE_HEADBASH;
        Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition42_func_8004F168((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition42_D_80070328.movementState) + 0x3C)));
        Transition42_D_80070328.unk7a[2].z = 0x800;
        Transition42_D_80070328.grounded = 0;
        Transition42_D_80070328.unk13a[0] = 0x20000;
        Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        return;
    case 0x4C:
        Transition42_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=1;
        goto setHeadbashSubstate;
    case 0x4D:
        Transition42_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=2;
setHeadbashSubstate:
        Transition42_D_80070328.unk5=nextSubstate;
        Transition42_D_80070328.grounded=0;
        Transition42_D_80070328.unk13a[0]=0x20000;
        return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_42/animation", func_level_42_8008DD24);
