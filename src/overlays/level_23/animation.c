#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_23/animation", func_level_23_8009153C);

/* AI generated; not human reviewed. SCUS-94467 80093120..800937D0.
 * Verified43 scalar/clamp and original23 case47 numeric pointer chain.
 * Original800935CC..8009373C supplies case47 register/call/access chain.
 * Player+44-14 and44-44 are byte offsets, not typed-element arithmetic.
 * Table8006D048+14, selector80071924&63, stride4 and entry+4 mask02000000
 * are numeric provenance. Original helper meaning and source producer remain open.
 * Separate absolute flagWord alias retains originalV3 producer at80093538;
 * empty lifetime/memory constraints emit no instructions. Units/cadence unresolved.
 * Acceptance requires every original code/table word, strict full TU/all hashes.
 */
extern int Callback23Step __asm__("D_80070328+0x144");
extern int Callback23Z __asm__("D_80070328+8");
extern int Callback23Limit __asm__("D_80070328+0x280");
extern Spyro Callback23Player __asm__("D_80070328");
int Callback23Call80037058(int x, int y) __asm__("func_80037058");
void Callback23Call80041930(void) __asm__("func_80041930");
void Callback23Call80041AE8(void) __asm__("func_80041AE8");
void Callback23Call80041C20(void) __asm__("func_80041C20");
void Callback23Call80042A44(void) __asm__("func_80042A44");
void Callback23Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback23Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38,D_8006C648;
int Callback23Query(Vector3D*,int) __asm__("func_8001A358");
int Callback23Length(Vector3D*, int) __asm__("func_8004EDE8");
extern int Callback23FlagWord __asm__("D_80070328+0x4C");
extern int D_80071924;
extern int** Callback23Table __asm__("D_8006D048+0x14");
int Callback23Call80055E84(Moby*) __asm__("func_80055E84");
void Callback23Call8004ED6C(void*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
void Callback23Call8001BA30(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int Callback23Call80019138(Vector3D*,int,int,int,int,Moby*) __asm__("func_80019138");
int Callback23Call8001830C(Vector3D*,Vector3D*,int,int,Moby*) __asm__("func_8001830C");
void func_level_23_80093120(void) {
    struct {Vector3D first; int reserved24; Vector3D second; int reserved34;} local;
    register int computedValue __asm__("$4");

    register int clampedValue __asm__("$4");
    register int positionDelta __asm__("$2");
    register int numerator __asm__("$2");
    register int belowLimit __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback23Player.animationState) {
    case 0x41:
        if(func_800438F4()==0)func_80043728();
        Callback23Call80041C20();
        Callback23Player.unk9a=0;
        Callback23Call80042A44();
        goto clearSharedValue;
    default:
        return;
    case 0x44:
    case 0x4A:
        Callback23Call80041C20();
        Callback23Call80042A44();
        goto clearSharedValue;
    case 0x42:
    case 0x45:
        func_800438F4();
        Callback23Call80041C20();
        Callback23Call80042A44();
        Callback23Call80041930();
        goto queryC00;
    case 0x13:
        Callback23Call80041C20();
        Callback23Call80042A44();
        goto call41930;
    case 0x1C:
        Callback23Call80041C20();
        Callback23Call80042A44();
        Callback23Call80041930();
        if(Callback23Player.unk7a[3].z < 0 && Callback23Player.animationStateFrames >= 4) {
setFirstFlag:
            Callback23Player.unk5=1;
        }
        goto clearSharedValue;
        case 0x1E: {
            register int* zWord __asm__("$5")=&Callback23Z;
            register int velocity __asm__("$6")=Callback23Step;
            register int scalarPosition __asm__("$2")=*zWord;
            register int tick __asm__("$3")=D_8006C648;
            register int increment __asm__("$4");
            register int status __asm__("$2");
            __asm__("" : "=r"(velocity) : "0"(velocity));
            __asm__("" : "=r"(scalarPosition) : "0"(scalarPosition));
            __asm__("" : "=r"(tick) : "0"(tick));
            increment=velocity>>6;
            __asm__("" : "=r"(increment) : "0"(increment));
            scalarPosition+=increment;
            __asm__("" : "=r"(tick) : "0"(tick), "r"(scalarPosition));
            tick<<=9;
            *zWord=scalarPosition;
            status=Callback23Limit;
            velocity+=tick;
            Callback23Step=velocity;
            __asm__("" : : : "memory");
            if(status>=0 && D_8006FA38<0)goto lowerLimit;
            {
                register int limit __asm__("$3")=0x9000;
                register int exceeded __asm__("$2");
                __asm__("" : "=r"(limit) : "0"(limit));
                exceeded=limit<velocity;
                if(exceeded)Callback23Step=limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2")=velocity<0x2581;
                if(!below)Callback23Step=0x2580;
            }
        limitsDone:
            Callback23Call80041C20();
            Callback23Call80042A44();
            func_8004F178(&local.first,&Callback23Player.position);
            __asm__ volatile("" : : : "$16", "memory");
            local.first.z+=0x400;
            {register int queryResult __asm__("$2")=Callback23Query(&local.first,0xC00);
            __asm__("" : "=r"(queryResult) : "0"(queryResult));
            Callback23Player.unk4[0]=-queryResult;
            __asm__ volatile("" : : : "memory");}
            positionDelta=(int)Callback23Player.union144.a.unk13cb;
            positionValue=Callback23Player.position.z;
            positionDelta >>= 6;
            goto storePosition;
        }
    case 0x2B:
    case 0x2C:
        Callback23Call80041C20();
        Callback23Call80042A44();
        Callback23Call80041AE8();
        if ((unsigned char) Callback23Player.unk10[4] != 0) {
            computedValue = -Callback23Player.unk9ha[4] - Callback23Call80037058(Callback23Player.position.x, Callback23Player.position.y);
            positionValue = Callback23Player.unk4a - computedValue;
            Callback23Player.unk4[0] = computedValue;
            positionDelta = (int) Callback23Player.union144.a.unk13cc >> 6;
            goto storePosition;
        }
        break;
storePosition:
        positionValue -= positionDelta;
        __asm__("" : "=r"(positionValue) : "0"(positionValue));
        Callback23Player.position.z=positionValue;
        return;
    case 0x2F:
        Callback23Call80041C20();
        Callback23Call80042A44();
        Callback23Call80041930();
        func_80042F64();
        goto clearSharedValue;
    case 0x32:
        Callback23Call80041C20();
        Callback23Call80042A44();
        Callback23Call80041930();
        func_80042F64();
        numerator=(int)((unsigned int)Callback23Player.unk7a[3].z << 2);
        Callback23Player.unk4[0] = 0;
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
        Callback23Call80041C20();
        Callback23Call80042A44();
        Callback23Call80041930();
        func_80042F64();
        Callback23Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)(((unsigned int)Callback23Length((Vector3D *) ((unsigned char*)Callback23Player.unk4 + 0x70), 0) << 2) + 0x300U) / 1536;
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
    case 0x43:
    case 0x46:
    case 0x49:
        Callback23Call80041C20();
        Callback23Call80042A44();
        Callback23Call80041930();
        if(Callback23Player.unk7a[3].z < 0 && Callback23Player.animationStateFrames >= 4)goto setFirstFlag;
        {register int* flagWord __asm__("$3")=&Callback23FlagWord;
        __asm__("" : "=r"(flagWord) : "0"(flagWord));
        if(*flagWord==0 && !(Callback23Word8006E538 & 0x40) && Callback23Player.union144.a.unk13cb==0)
            *flagWord=2;}
        goto clearSharedValue;
    case 0x47: {
        register int progress __asm__("$4");
        register int value __asm__("$2");
        register int* sourceBase __asm__("$16");
        register Vector3D* vectorBase __asm__("$17");
        register int flags __asm__("$18");
        if(Callback23Player.ticksSinceLastSurfaceTouch) {
            Callback23Call80041C20();
            Callback23Call80042A44();
        } else {
            func_800438F4();
            Callback23Call80041C20();
            Callback23Call80042A44();
            Callback23Call80041930();
            Callback23Call80043A38(0xC00);
        }
        progress=Callback23Call80055E84(Callback23Player.critterMobyPtr);
        if(Callback23Player.critterMobyPtr->animationState.id==6 && (unsigned int)(progress-2)<6) {
            if(progress<6)value=(progress<<10)/6;
            else value=0x400;
            local.second.x=value;
            __asm__ volatile("" : : : "memory");
            sourceBase=&Callback23Player.unk4a;
            vectorBase=&local.second;
            local.second.y=0;
            local.second.z=0x200-*sourceBase;
            Callback23Call8004ED6C((unsigned char*)sourceBase-0x14,vectorBase,vectorBase);
            {register Vector3D* argument0 __asm__("$4")=vectorBase;
            register Vector3D* argument1 __asm__("$5")=vectorBase;
            __asm__("" : "=r"(argument0), "=r"(argument1) : "0"(argument0), "1"(argument1));
            sourceBase=(int*)((unsigned char*)sourceBase-0x44);
            func_8004F194(argument0,argument1,(Vector3D*)sourceBase);}
            flags=0x02000000;
            Callback23Call8001BA30(vectorBase,0x200,0,0,flags,Callback23Player.critterMobyPtr);
            if((Callback23Call80019138(vectorBase,0x200,0,0,flags,Callback23Player.critterMobyPtr)!=0 ||
                Callback23Call8001830C((Vector3D*)sourceBase,vectorBase,0,0x02000000,Callback23Player.critterMobyPtr)!=0)) {
                register int* selector __asm__("$16")=&D_80071924;
                if(func_80040954(*selector)==3) {
                    register int index __asm__("$2")=*selector;
                    register int** table __asm__("$3")=Callback23Table;
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
        Callback23Call80041C20();
        Callback23Call80042A44();
        if(Callback23Player.unk5==1)func_800494A8();
        goto clearSharedValue;
    case 0x48:
        Callback23Call80041C20();
        Callback23Call80042A44();
        if(Callback23Player.unk5!=0)goto call41930;
queryC00:
        Callback23Call80043A38(0xC00);
        goto clearSharedValue;
call41930:
        Callback23Call80041930();
clearSharedValue:
        Callback23Player.unk4[0]=0;
        return;
    }
}


#define LEVEL_ID 23
#define PlaySpyroSounds_level_23 func_level_23_800937D4
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_23_800939C0(int index) {
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
    case 0x1e:
    case 0x2b:
    case 0x2c:
    case 0x41:
    case 0x42:
    case 0x45:
    case 0x4a:
        func_80043ABC(&spyro.unk9e);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80093A68.
 * Verified16 character41..4D,32 swirl/drowning,37 vector/damage200, original23
 * grouped ladder and distinct stack10 surface / stack20 jump producers.
 * Numeric offsets are bytes. Signed table -2/0/2 maps to -1/0/1; original
 * word60 wrap800/801/FFF yields0/-7FF/-1. Each invocation preserves original
 * code/internal jumps/owned tables; strict complete TU and all hashes required.
 * Helper meanings, physical units, audio, cadence and live parity remain open.
 */
extern unsigned char Transition23RawUnion[] __asm__("D_80070328+0x144");
extern int Transition23RawMovement __asm__("D_80070328+0x50");
void Transition23_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");
void Transition23_func_8004F168(Vector3D*) __asm__("func_8004F168");
void Transition23_func_80043A38(int) __asm__("func_80043A38");
void Transition23_func_800441F0(void) __asm__("func_800441F0");
extern int Raw23Word __asm__("D_80070328+0x50");
extern int Raw23X __asm__("D_80070328+0x8C");
extern unsigned char Raw23Movement[] __asm__("D_80070328+0x50");
extern unsigned char Raw23Union[] __asm__("D_80070328+0x144");
extern int Raw23Animation __asm__("D_80070328+0x48");
extern short D_80065920[];
extern short D_800658A0[];
extern Spyro Transition23_D_80070328 __asm__("D_80070328");
int Transition23_func_8004EDE8(Vector3D*,int) __asm__("func_8004EDE8");
int Call23A358(Vector3D*,int) __asm__("func_8001A358");
extern int Transition23_D_8006E524 __asm__("D_8006E524");
extern int D_80071934;
void func_level_23_80093A68(int arg0) {
    struct {Vector3D first; int gap; Vector3D second;} vectors;
    register Vector3D *damageSource __asm__("$16");
    register Vector3D *damageDestination __asm__("$16");
    Vector3D *firstJumpSource;
    Vector3D *secondJumpSource;
    enum MovementState nextSubstate;
    int lengthResult;
    register int comparisonKind __asm__("$2");
    register int previousValue __asm__("$2");
    register int firstAnimation __asm__("$3");
    register int tableIndex __asm__("$2");
    register int tableValue __asm__("$3");
    register unsigned char* soundTable __asm__("$3");
    register unsigned char* unionBase __asm__("$5");
    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* movement __asm__("$3");
    register unsigned char* initialMovement __asm__("$5");
    register void *jumpPrivate __asm__("$18");
    register void *damagePrivate __asm__("$18");

    register Vector3D* jumpVector __asm__("$16");
    register unsigned char* stateBase __asm__("$17");
    register unsigned char* privateData __asm__("$16");
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");
    int maskedValue;
    switch (arg0) {
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        stateBase=(unsigned char*)&Transition23RawMovement;
        privateData = Transition23_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition23_D_80070328.unk5 = 0;
        Transition23_D_80070328.grounded = 0;
        Transition23_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition23_D_80070328.m_WhirlwindPointer;
        yawValue=Transition23_D_80070328.rotation.yaw;
        positionZ=Transition23_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition23_D_80070328.union144.a.unk13cc=yawValue;
        Transition23_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition23_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition23_D_80070328.union144.a.unk13ce.z=heightValue;
        __asm__ volatile("" : : : "memory");
        heightValue = ((int) (heightValue << 0xA) >> 0xA) + 0x400;
        __asm__("" : "=r"(heightValue) : "0"(heightValue));
        Transition23_D_80070328.union144.a.unk13ce.y = heightValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
        Transition23_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition23_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition23_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition23_D_80070328.unk13e[0] = (int) Transition23_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition23_D_80070328.unk20a = 0;
        Transition23_D_80070328.critterMobyPtr = 0;
        Transition23_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x1C:
        savedBase = Transition23RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Transition23RawMovement;
        Transition23RawMovement = MOVEMENT_STATE_HURT;
        Transition23_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Transition23_D_80070328.unk8[0] = Transition23_func_8004EDE8(sourceC, 0);
        Transition23_D_80070328.unk7a[2].z = 0xDC0;
        Transition23_D_80070328.grounded = 0;
        Transition23_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Transition23_D_80070328.damageFlags & 0x200) {
            Transition23_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition23_D_80070328.union144.a.unk13cc = 1;
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        goto clearPointers;
    case 0x1E: {
        register int oldState __asm__("$3")=Transition23RawMovement;
        register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$8")=SpawnParticle;
        register int* stateWord __asm__("$2");
        register int value __asm__("$2");
        __asm__ volatile("" : "=r"(oldState), "=r"(callback) : "0"(oldState), "1"(callback) : "memory");
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Transition23RawMovement=value;
        value=1;
        __asm__("" : "=r"(value) : "0"(value));
        Transition23_D_80070328.grounded=value;
        value=15;
        __asm__("" : "=r"(value) : "0"(value));
        Transition23_D_8006E524=value;
        stateWord=(int*)Transition23RawUnion;
        __asm__("" : "=r"(stateWord) : "0"(stateWord));
        Transition23_D_80070328.unk5=0;
        *stateWord=oldState;
        __asm__ volatile("" : : : "memory");
        *stateWord=0;
        if(callback)callback(5,10,0,0);
        Transition23_D_80070328.unk22[2]=PlaySound((int)D_8006C654->drown,0,0);
        value=(int)D_8006C654->drown;
        __asm__ volatile("" : "=r"(value) : "0"(value) : "memory");
        Transition23_D_80070328.unk20a=0;
        Transition23_D_80070328.critterMobyPtr=0;
        Transition23_D_80070328.unk22[3]=value;
        return;
    }
    case 0x2B:case 0x2C: {
        register unsigned char* unionPointer __asm__("$16");
        {register int stateWord __asm__("$3")=Raw23Word;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Raw23Union;
            *(int*)unionPointer=(-Transition23_D_80070328.unk7a[2].z)>>2;
            if(Raw23Word!=8){Transition23_D_80070328.union144.a.unk13cc=0x5900;Raw23Word=10;}
            Transition23_D_80070328.unk5=0;
            Transition23_D_80070328.unk8[0]=Transition23_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition23_D_80070328.grounded=1;
            Transition23_D_80070328.unk15b=1;
            func_8004F178(&vectors.first,(Vector3D*)(unionPointer-0x144));
            vectors.first.z+=0x400;
            lengthResult=Call23A358(&vectors.first,0x800);
            vectors.first.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,&vectors.first,0);SpawnParticle(6,0x2E,&vectors.first,0);}
        }
        }
        goto clearPointers;
    }
    case 0x2F:case 0x32:case 0x33:case 0x34:
        savedBase=Raw23Movement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition23_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            Transition23_D_80070328.grounded=1;
        }
clearPointers:
        Transition23_D_80070328.unk20a=0;
        Transition23_D_80070328.critterMobyPtr=0;
        return;
    case 0x41:
        Transition23_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition23_func_800441F0();
        Transition23_D_80070328.grounded = 1;
        return;
    case 0x42:
    case 0x45:
        Transition23_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition23_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition23_D_80070328.movementState) + 0x3C)), (Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition23_D_80070328.movementState) + 0x48)));
            Transition23_D_80070328.unk5 = MOVEMENT_STATE_WALK;
        } else {
            Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        }
        Transition23_D_80070328.unk8[0] = Transition23_func_8004EDE8(&Transition23_D_80070328.unk7a[3], 0);
        Transition23_func_80043A38(0xC00);
        Transition23_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition23_D_80070328.grounded = 1;
        goto clearFlags;
    case 0x43:
    case 0x49:
        initialMovement=Raw23Movement;
        __asm__("" : "=r"(initialMovement) : "0"(initialMovement));
        comparisonKind=10;
        __asm__("" : "=r"(comparisonKind) : "0"(comparisonKind));
        {register Moby* critter __asm__("$3")=Transition23_D_80070328.critterMobyPtr;
        register int current __asm__("$4")=*(int*)initialMovement;
        __asm__("" : "=r"(critter),"=r"(current) : "0"(critter),"1"(current));
        jumpPrivate=critter->mobyTag;
        __asm__("" : "=r"(jumpPrivate) : "0"(jumpPrivate));
        if ((current == comparisonKind) && (SpawnParticle != 0) && (Transition23_D_80070328.unk4[0] < 0)) {
            jumpVector=&vectors.second;
            func_8004F178(jumpVector, (Vector3D*)(initialMovement-0x50));
            vectors.second.z = -Transition23_D_80070328.unk4[0];
            SpawnParticle(6, 0x2E, jumpVector, 0);
            SpawnParticle(4, 0x29, jumpVector, 0);
        }
        }
        movement=Raw23Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        firstJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) firstJumpSource);
        Transition23_D_80070328.unk8[0] = Transition23_func_8004EDE8((Vector3D *) firstJumpSource, 0);
        if (arg0 == 0x49) {
            Transition23_D_80070328.unk7a[2].z = 0x2580;
        } else {
            Transition23_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)jumpPrivate+0x4C) = 0;
        }
        Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition23_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition23_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
        goto playJumpSound;
    case 0x44:
        Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        if (Transition23_D_80070328.movementState == MOVEMENT_STATE_JUMP_HOVER) {
            if(Transition23_D_80070328.animationState==0x43)Transition23_D_80070328.unk5=1;
            else if(Transition23_D_80070328.animationState==0x46)Transition23_D_80070328.unk5=Transition23_D_80070328.movementState;
            else if(Transition23_D_80070328.animationState==0x49)Transition23_D_80070328.unk5=4;
        } else {
            Transition23_D_80070328.movementState = MOVEMENT_STATE_FALL;
        }
        Transition23_D_80070328.unk8[0] = Transition23_func_8004EDE8(&Transition23_D_80070328.unk7a[3], 0);
        Transition23_D_80070328.grounded = 0;
        goto clearFlags;
    case 0x46:
        movement=Raw23Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        secondJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) secondJumpSource);
        Transition23_D_80070328.unk8[0] = Transition23_func_8004EDE8((Vector3D *) secondJumpSource, 0);
        Transition23_D_80070328.unk7a[2].z = 0x12C0;
        Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition23_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition23_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
playJumpSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
        return;
    case 0x47:
        if (Transition23_D_80070328.ticksSinceLastSurfaceTouch != 0) {
            if (Transition23_D_80070328.movementState != MOVEMENT_STATE_FALL) {
                if (Transition23_D_80070328.animationState == 0x43) {
                    Transition23_D_80070328.unk5 = MOVEMENT_STATE_WALK;
                } else if (Transition23_D_80070328.animationState == 0x46) {
                    Transition23_D_80070328.unk5 = MOVEMENT_STATE_JUMP_HOVER;
                } else {
                    Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
                }
            }
            Transition23_D_80070328.movementState = MOVEMENT_STATE_FALL;
            Transition23_D_80070328.grounded = 0;
            Transition23_D_80070328.idle = 0;
            Transition23_D_80070328.unk15g = 0;
        } else {
            Transition23_D_80070328.movementState = MOVEMENT_STATE_WALK;
            Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            Transition23_func_80043A38(0xC00);
            Transition23_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition23_D_80070328.grounded = 1;
        }
        Transition23_D_80070328.unk8[0] = Transition23_func_8004EDE8(&Transition23_D_80070328.unk7a[3], 0);
        goto clearFlags;
clearFlags:
        Transition23_D_80070328.idle = 0;
        Transition23_D_80070328.unk15g = 0;
        return;
    case 0x48: {
        register Moby* critter __asm__("$2")=Transition23_D_80070328.critterMobyPtr;
        __asm__ volatile("" : "=r"(critter) : "0"(critter) : "memory");
        damagePrivate=critter->mobyTag;
        __asm__ volatile("" : "=r"(damagePrivate) : "0"(damagePrivate) : "memory");
        previousValue=Raw23Word;
        __asm__ volatile("" : "=r"(previousValue) : "0"(previousValue) : "memory");
        unionBase=Raw23Union;
        __asm__("" : "=r"(previousValue),"=r"(unionBase) : "0"(previousValue),"1"(unionBase));
        *(int*)unionBase=previousValue;
        Raw23Word = MOVEMENT_STATE_HURT;
        if (Transition23_D_80070328.damageFlags & 8) {
            damageSource = (Vector3D *) (unionBase - 0xAC);
            Transition23_D_80070328.unk5 = MOVEMENT_STATE_WALK;
            func_8004F178((Vector3D *) (unionBase - 0xB8), damageSource);
            Transition23_D_80070328.unk8[0] = Transition23_func_8004EDE8(damageSource, 0);
            soundTable=(unsigned char*)D_8006C654;
            soundZero=0;
            __asm__ volatile("" : "=r"(soundTable),"=r"(soundZero) : "0"(soundTable),"1"(soundZero) : "memory");
            Transition23_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)damagePrivate+0x4C) = 0;
            Transition23_D_80070328.grounded = 0;
            Transition23_D_80070328.union144.a.unk13cc = 1;
            PlaySound(soundTable[12],(Moby*)soundZero,0);
        } else {
            Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            damageDestination = (Vector3D *) (unionBase - 0xB8);
            if (Transition23_D_80070328.unk17a & 0x400) {
                func_8004F178(damageDestination, (Vector3D *) ((Vector3D *) (unionBase + 0xD8)));
                Transition23_func_8004F0E8(damageDestination, 6);
            } else if (Transition23_D_80070328.unk22[5] >= 0) {
                tableIndex=Transition23_D_80070328.unk22[5]*2;
                tableValue=*(short*)((unsigned char*)D_80065920+tableIndex);
                __asm__("" : "=r"(tableValue) : "0"(tableValue));
                Raw23X=tableValue>>1;
                tableIndex=*(short*)((unsigned char*)D_800658A0+tableIndex);
                Transition23_D_80070328.unk7a[2].z=0;
                __asm__ volatile("" : "=r"(tableIndex) : "0"(tableIndex) : "memory");
                Transition23_D_80070328.unk7a[2].y=tableIndex>>1;
            } else {
                    __asm__("" : "=r"(unionBase) : "0"(unionBase));
                Transition23_func_8004F168((Vector3D*)(unionBase-0xB8));
            }
            func_8004F178(&Transition23_D_80070328.unk7a[1], (Vector3D *) ((unsigned char*)(&Transition23_D_80070328.unk7a[1]) + 0xC));
            Transition23_func_80043A38(0xC00);
            Transition23_D_80070328.grounded = 1;
        }
        Transition23_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
        break;
    }
    case 0x4A:
        Transition23_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition23_func_80043A38(0xC00);
        Transition23_D_80070328.grounded = 1;
        Transition23_D_8006E524 = 0xF;
        return;
    case 0x4B:
        firstAnimation=Raw23Animation;
        __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        if(firstAnimation==0x44){
            if(Transition23_D_80070328.unk5==4)goto setHeadbashFlag;
            comparisonKind=0x49;
            __asm__ volatile("" : "=r"(comparisonKind) : "0"(comparisonKind) : "memory");
            firstAnimation=Raw23Animation;
            __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        }else comparisonKind=0x49;
        if(firstAnimation==comparisonKind){
setHeadbashFlag:
            Transition23_D_80070328.union144.a.unk13cc=1;
        }else Transition23_D_80070328.union144.a.unk13cc=0;
        Transition23_D_80070328.movementState = MOVEMENT_STATE_HEADBASH;
        Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition23_func_8004F168((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition23_D_80070328.movementState) + 0x3C)));
        Transition23_D_80070328.unk7a[2].z = 0x800;
        Transition23_D_80070328.grounded = 0;
        Transition23_D_80070328.unk13a[0] = 0x20000;
        Transition23_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        return;
    case 0x4C:
        Transition23_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=1;
        goto setHeadbashSubstate;
    case 0x4D:
        Transition23_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=2;
setHeadbashSubstate:
        Transition23_D_80070328.unk5=nextSubstate;
        Transition23_D_80070328.grounded=0;
        Transition23_D_80070328.unk13a[0]=0x20000;
        return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_23/animation", func_level_23_8009459C);
