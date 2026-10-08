#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_34/animation", func_level_34_80094D30);

int Callback34First42A44(void) __asm__("func_80042A44");
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 numeric decode.
 * Original animation callback at 80096124; private+0x30 child pointer,
 * child+0x38 halfword, player+0x74 vector, byte offsets +0x24/-0x74/+0x58.
 * Unsigned halfword load with signed shifts 16/17 and signed guarded division
 * follow original instructions. Empty constraints preserve original register
 * lifetimes and scheduling; they emit no instructions. Helper meanings, units,
 * cadence and runtime semantics remain unresolved. Acceptance requires every
 * original word/internal jump, strict complete TU, EXE and every overlay hash.
 */
extern int Callback34Step __asm__("D_80070328+0x144");
extern int Callback34Z __asm__("D_80070328+8");
extern int Callback34Limit __asm__("D_80070328+0x280");
extern Spyro Callback34Player __asm__("D_80070328");
int Callback34Call80037058(int x, int y) __asm__("func_80037058");
int Callback34Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback34Call80041930(void) __asm__("func_80041930");
void Callback34Call80041AE8(void) __asm__("func_80041AE8");
void Callback34Call80041C20(void) __asm__("func_80041C20");
void Callback34Call80042A44(void) __asm__("func_80042A44");
void Callback34Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback34Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38,D_8006C648;
int Callback34Query(Vector3D*,int) __asm__("func_8001A358");
int Callback34Length(Vector3D*, int) __asm__("func_8004EDE8");
extern unsigned char* Callback34Table[] __asm__("D_8006EE2C");
extern unsigned char Callback34Source[] __asm__("D_80070328+0x74");
extern int D_80071908;
extern Vector3D D_80071918;
void Callback34Call8004F110(Vector3D*,int) __asm__("func_8004F110");
int Callback34Call80038000(Moby*,Vector3D*,int,int,int) __asm__("func_80038000");
void Callback34Call8004F1C8(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004F1C8");
void Callback34Call8003BE70(int) __asm__("func_8003BE70");
void func_level_34_80096124(void) {
    struct {Vector3D first; int reserved24; Vector3D second; int reserved34; Vector3D third; int reserved44;} local;
    register int computedValue __asm__("$4");
    register Moby* descriptorMoby __asm__("$2");
    register unsigned int selector __asm__("$16");

    register int clampedValue __asm__("$4");
    register int positionDelta __asm__("$2");
    register int numerator __asm__("$2");
    register int belowLimit __asm__("$2");
    register int positionValue __asm__("$3");

    switch(Callback34Player.animationState) {
    case 0x64:
        if(func_800438F4()==0)func_80043728();
        Callback34Call80041C20();
        Callback34Player.unk9a=0;
        goto call42A44;
    case 0x20:
    case 0x35:
    case 0x36:
    case 0x67:
    case 0x69:
    case 0x6C:
        Callback34Call80041C20();
call42A44:
        Callback34Call80042A44();
clearSharedValue:
        Callback34Player.unk4[0]=0;
        return;
    case 0x66:
        Callback34Call80041C20();
        Callback34Call80042A44();
        descriptorMoby=Callback34Player.critterMobyPtr;
        __asm__ volatile("" : "=r"(descriptorMoby) : "0"(descriptorMoby) : "memory");
        Callback34Player.unk4[0]=0;
        goto descriptorTail;
    case 0x65:
        func_800438F4();
        Callback34Call80041C20();
        Callback34Call80042A44();
        Callback34Call80041930();
        goto queryC00;
    case 0x13:
        Callback34Call80041C20();
        Callback34Call80042A44();
        Callback34Call80041930();
        goto clearSharedValue;
    case 0x1A:
    case 0x1D:
    case 0x68:
        Callback34Call80041C20();
        Callback34Call80042A44();
queryC00:
        Callback34Call80043A38(0xC00);
        goto clearSharedValue;
    case 0x6B:
        Callback34Call80041C20();
        Callback34Call80042A44();
        Callback34Call80041930();
        if(Callback34Player.unk7a[3].z<0 && Callback34Player.animationStateFrames>=4)
            Callback34Player.unk5=1;
        goto clearSharedValue;
        case 0x1E: {
            register int* zWord __asm__("$5")=&Callback34Z;
            register int velocity __asm__("$6")=Callback34Step;
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
            status=Callback34Limit;
            velocity+=tick;
            Callback34Step=velocity;
            __asm__("" : : : "memory");
            if(status>=0 && D_8006FA38<0)goto lowerLimit;
            {
                register int limit __asm__("$3")=0x9000;
                register int exceeded __asm__("$2");
                __asm__("" : "=r"(limit) : "0"(limit));
                exceeded=limit<velocity;
                if(exceeded)Callback34Step=limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2")=velocity<0x2581;
                if(!below)Callback34Step=0x2580;
            }
        limitsDone:
            Callback34Call80041C20();
            Callback34Call80042A44();
            func_8004F178(&local.first,&Callback34Player.position);
            local.first.z+=0x400;
            Callback34Player.unk4[0]=Callback34Query(&local.first,0xC00);
            positionDelta=(int)Callback34Player.union144.a.unk13cb;
            positionValue=Callback34Player.position.z;
            positionDelta >>= 6;
            positionValue-=positionDelta;
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            Callback34Player.position.z=positionValue;
            return;
        }
    case 0x2F:
        Callback34Call80041C20();
        Callback34Call80042A44();
        Callback34Call80041930();
        func_80042F64();
        goto clearSharedValue;
    case 0x32:
        Callback34Call80041C20();
        Callback34Call80042A44();
        Callback34Call80041930();
        func_80042F64();
        numerator=(int)((unsigned int)Callback34Player.unk7a[3].z << 2);
        Callback34Player.unk4[0] = 0;
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
        Callback34Call80041C20();
        Callback34Call80042A44();
        Callback34Call80041930();
        func_80042F64();
        Callback34Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)(((unsigned int)Callback34Length((Vector3D *) ((unsigned char*)Callback34Player.unk4 + 0x70), 0) << 2) + 0x300U) / 1536;
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
    case 0x6A:
    case 0x6D: {
        register unsigned char* privateData __asm__("$17")=Callback34Player.critterMobyPtr->mobyTag;
        register int changed __asm__("$20")=0;
        register Vector3D* vectorBase __asm__("$16");
        register Vector3D* copyBase __asm__("$18");
        register unsigned char* sourceBase __asm__("$19");
        register int queryHeight __asm__("$16");
        if(*(Moby**)(privateData+0x30)!=0) {
            vectorBase=&local.second;
            sourceBase=Callback34Source;
            func_8004F178(vectorBase,(Vector3D*)sourceBase);
            Callback34Call8004F110(vectorBase,6);
            {
                Moby* child=*(Moby**)(privateData+0x30);
                child->position.z+=((int)((unsigned int)*(unsigned short*)((unsigned char*)child+0x38)<<16))>>17;
            }
            func_8004F194(vectorBase,vectorBase,(Vector3D*)((unsigned char*)*(Moby**)(privateData+0x30)+0xC));
            copyBase=&local.third;
            func_8004F178(copyBase,vectorBase);
            {
                int height=((int)((unsigned int)*(unsigned short*)((unsigned char*)*(Moby**)(privateData+0x30)+0x38)<<16))>>17;
                register int result=Callback34Call80038000(*(Moby**)(privateData+0x30),vectorBase,height,height,0x1022);
                register Vector3D* childVector __asm__("$4")=vectorBase;
                if(result!=0) {
                    register Vector3D* childCopy __asm__("$6")=copyBase;
                    {register Moby* childArgument __asm__("$5")=*(Moby**)(privateData+0x30);
                    __asm__ volatile("" : "=r"(changed) : "0"(changed) : "memory");
                    changed=1;
                    Callback34Call8004F1C8(childVector,(Vector3D*)((unsigned char*)childArgument+0xC),childCopy);}
                    func_8004F0E8(vectorBase,6);
                    func_8004F194((Vector3D*)sourceBase,(Vector3D*)sourceBase,vectorBase);
                }
            }
            Callback34Call80041C20();
            {register Vector3D* argument0 __asm__("$4")=(Vector3D*)(sourceBase+0x24);
            if(changed!=0) {
                register int componentX __asm__("$8")=local.second.x;
                register int divisor __asm__("$2")=D_8006C648;
                register int componentY __asm__("$7");
                register int componentZ __asm__("$3");
                componentX/=divisor;
                __asm__("" : "=r"(componentX) : "0"(componentX));
                componentY=local.second.y/divisor;
                __asm__("" : "=r"(componentY) : "0"(componentY));
                componentZ=local.second.z/divisor;
                __asm__ volatile("" : "=r"(componentZ), "=r"(argument0) : "0"(componentZ), "1"(argument0) : "memory");
                local.second.x=componentX;
                local.second.y=componentY;
                local.second.z=componentZ;
                Callback34Call8004F1C8(argument0,argument0,vectorBase);
            }}
            {register Moby* child __asm__("$2")=*(Moby**)(privateData+0x30);
            register int childValue __asm__("$3")=*(short*)((unsigned char*)child+0x38);
            register int playerValue __asm__("$2")=Callback34Player.unk4a;
            playerValue+=childValue;
            __asm__("" : "=r"(playerValue) : "0"(playerValue));
            queryHeight=playerValue+64;}
            if(Callback34Query((Vector3D*)(sourceBase-0x74),queryHeight)!=0 && Callback34Player.unk7a[2].z<=0) {
                if(Callback34Player.unk7a[2].z>=-2047)
                    Callback34Player.position.z=D_80071908+queryHeight-64;
                Callback34Player.ticksSinceLastSurfaceTouch=0;
                func_8004F178((Vector3D*)(sourceBase+0x58),&D_80071918);
            } else {
                register int* counterPointer __asm__("$2")=&Callback34Player.ticksSinceLastSurfaceTouch;
                register int counterValue __asm__("$3");
                register int vectorZ __asm__("$4");
                __asm__("" : "=r"(counterPointer) : "0"(counterPointer));
                Callback34Player.unk9e.x=0;
                Callback34Player.unk9e.y=0;
                counterValue=*counterPointer;
                __asm__ volatile("" : "=r"(counterPointer) : "0"(counterPointer) : "memory");
                vectorZ=4096;
                Callback34Player.unk9e.z=vectorZ;
                counterValue+=1;
                *counterPointer=counterValue;
            }
        } else Callback34Call80041C20();
        Callback34Player.unk4[0]=0;
        if(Callback34Player.animationState!=0x6A)return;
        descriptorMoby=Callback34Player.critterMobyPtr;
descriptorTail:
        selector=Callback34Table[descriptorMoby->mobyClass][6];
        if(selector!=(unsigned int)Callback34Player.unk22[3]) {
            if(Callback34Call8003BF6C(Callback34Player.unk22[3],Callback34Player.unk22[2])!=0)
                Callback34Call8003BE70(Callback34Player.unk22[2]);
            Callback34Player.unk22[2]=-1;
        }
        Callback34Player.unk22[3]=selector;
        if(Callback34Call8003BF6C(selector,Callback34Player.unk22[2])==0)
            Callback34Player.unk22[2]=PlaySound(Callback34Player.unk22[3],0,4);
        return;
    }
    default:
        return;
    }
}


#define LEVEL_ID 34
#define PlaySpyroSounds_level_34 func_level_34_80096828
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_34_80096A28(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x1a:
    case 0x1d:
    case 0x1e:
    case 0x20:
    case 0x35:
    case 0x36:
    case 0x64:
    case 0x65:
    case 0x68:
    case 0x69:
    case 0x6c:
    case 0x6d:
        func_80043ABC(&spyro.unk9e);
        break;
    case 0x13:
    case 0x66:
    case 0x67:
    case 0x6a:
    case 0x6b:
        func_80043ABC(0);
        break;
    case 0x2f:
    case 0x32:
    case 0x33:
    case 0x34:
        func_80043F3C(&spyro.unk9h);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80096AC0.
 * Reuses verified22 private0/4/8 swirl, squish, drowning and64..6D producers,
 * verified37 numeric21C/220/224 hurt/fallbackA0 and independent sound call.
 * Original34 adds independent2F and32/33/34 ladder blocks sharing grounded
 * store with35/36 before244/250 clear. Original access widths and byte offsets,
 * signed table shifts1, flags400/copy21C/scale6, masks and branches are retained.
 * Empty constraints retain original scheduling without emitting instructions.
 * Require every code/internal jump/owned dispatch word and complete retail
 * hashes. Helper/audio meanings, units, cadence and live parity remain open.
 */
void Transition34_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");

extern Spyro Transition34_D_80070328 __asm__("D_80070328");
int Transition34_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition34_func_80043A38(int scale) __asm__("func_80043A38");
void Transition34_func_800441F0(void) __asm__("func_800441F0");
void Transition34_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition34_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition34RawUnion[] __asm__("D_80070328+0x144");
extern int Transition34RawMovement __asm__("D_80070328+0x50");
extern void (*Call34Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw34State[] __asm__("D_80070328+0x50");
extern short Signed34TableA[] __asm__("D_800658A0");
extern short Signed34TableB[] __asm__("D_80065920");

void func_level_34_80096AC0(int arg0){
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");



    int maskedValue;
    register unsigned char* privateData __asm__("$16");

    register unsigned char* stateBase __asm__("$17");
    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");

    register int oldMovementC __asm__("$5");
    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    switch(arg0){
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        stateBase=(unsigned char*)&Transition34RawMovement;
        privateData = Transition34_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition34_D_80070328.unk5 = 0;
        Transition34_D_80070328.grounded = 0;
        Transition34_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition34_D_80070328.m_WhirlwindPointer;
        yawValue=Transition34_D_80070328.rotation.yaw;
        positionZ=Transition34_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition34_D_80070328.union144.a.unk13cc=yawValue;
        Transition34_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition34_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition34_D_80070328.union144.a.unk13ce.z=heightValue;
        __asm__ volatile("" : : : "memory");
        heightValue = ((int) (heightValue << 0xA) >> 0xA) + 0x400;
        __asm__("" : "=r"(heightValue) : "0"(heightValue));
        Transition34_D_80070328.union144.a.unk13ce.y = heightValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
        Transition34_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition34_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition34_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition34_D_80070328.unk13e[0] = (int) Transition34_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition34_D_80070328.unk20a = 0;
        Transition34_D_80070328.critterMobyPtr = 0;
        Transition34_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x1D: {
        register int oldState __asm__("$4")=Transition34RawMovement;
        register int first __asm__("$3")=Transition34_D_80070328.unk17e.x;
        register int second __asm__("$2");
        register int third __asm__("$3");
        __asm__("" : "=r"(oldState),"=r"(first) : "0"(oldState),"1"(first) : "memory");
        second=7;
        __asm__("" : "=r"(second) : "0"(second));
        Transition34RawMovement=second;
        __asm__ volatile("" : : : "memory");
        second=Transition34_D_80070328.unk17e.y;
        __asm__ volatile("" : "=r"(second) : "0"(second) : "memory");
        Transition34_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(first) : "0"(first) : "memory");
        first<<=6;
        __asm__("" : "=r"(first) : "0"(first));
        Transition34_D_80070328.unk7a[2].x=first;
        __asm__ volatile("" : : : "memory");
        third=Transition34_D_80070328.unk17e.z;
        second<<=6;
        Transition34_D_80070328.union144.a.unk13cb=oldState;
        Transition34_D_80070328.unk7a[2].y=second;
        second=third<<6;
        if(third==0)second=Transition34_D_80070328.unk7a[3].z;
        Transition34_D_80070328.unk7a[2].z=second;
        Transition34_func_80043A38(0xC00);
        Transition34_D_80070328.grounded=1;
        Transition34_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        soundSelector=D_8006C654->spyroHurt;
        soundZero=0;
        PlaySound(soundSelector,(Moby*)soundZero,0);
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    }

    case 0x1A:
        savedBase = Transition34RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        oldMovementC = Transition34RawMovement;
        Transition34RawMovement = MOVEMENT_STATE_HURT;
        Transition34_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementC;
        Transition34_func_8004F168(destination);
        Transition34_D_80070328.grounded = 1;
        Transition34_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        soundSelector=D_8006C654->squish;
        soundZero=0;
        PlaySound(soundSelector,(Moby*)soundZero,0);
        goto clearPointers;
    case 0x1E: {
        register int oldState __asm__("$3")=Transition34RawMovement;
        register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$8")=SpawnParticle;
        register int* stateWord __asm__("$2");
        register int value __asm__("$2");
        __asm__ volatile("" : "=r"(oldState), "=r"(callback) : "0"(oldState), "1"(callback) : "memory");
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Transition34RawMovement=value;
        value=1;
        __asm__("" : "=r"(value) : "0"(value));
        Transition34_D_80070328.grounded=value;
        value=15;
        __asm__("" : "=r"(value) : "0"(value));
        Transition34_D_8006E524=value;
        stateWord=(int*)Transition34RawUnion;
        __asm__("" : "=r"(stateWord) : "0"(stateWord));
        Transition34_D_80070328.unk5=0;
        *stateWord=oldState;
        __asm__ volatile("" : : : "memory");
        *stateWord=0;
        if(callback)callback(5,10,0,0);
        Transition34_D_80070328.unk22[2]=PlaySound((int)D_8006C654->drown,0,0);
        value=(int)D_8006C654->drown;
        __asm__ volatile("" : "=r"(value) : "0"(value) : "memory");
        Transition34_D_80070328.unk20a=0;
        Transition34_D_80070328.critterMobyPtr=0;
        Transition34_D_80070328.unk22[3]=value;
        return;
    }
    case 0x20:
        Transition34_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition34_D_80070328.unk5 = 0;
        Transition34_func_80043A38(0xC00);
        Transition34_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition34_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x2F:
        savedBase=(unsigned char*)&Transition34RawMovement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition34_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            __asm__ volatile("" : : : "memory");
            goto setGrounded;
        }
        goto clearPointers;
    case 0x32:case 0x33:case 0x34:
        savedBase=(unsigned char*)&Transition34RawMovement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition34_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            goto setGrounded;
        }
        goto clearPointers;
    case 0x35:
    case 0x36:
        Transition34_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition34_D_80070328.unk5 = 0;
        Transition34_func_800441F0();
setGrounded:
        Transition34_D_80070328.grounded = 1;
clearPointers:
        Transition34_D_80070328.unk20a=0;
        Transition34_D_80070328.critterMobyPtr=0;
        return;
    case 0x64:
    case 0x6D:
        Transition34_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition34_D_80070328.unk5 = 0;
        Transition34_func_800441F0();
        Transition34_D_80070328.grounded = 1;
        return;
    case 0x65:
        Transition34_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition34_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((unsigned char*)(unsigned char*)&Transition34_D_80070328.movementState + 0x3C), (Vector3D *) ((unsigned char*)(unsigned char*)&Transition34_D_80070328.movementState + 0x48));
            Transition34_D_80070328.unk5 = 1;
        } else {
            Transition34_D_80070328.unk5 = 0;
        }
        Transition34_D_80070328.unk8[0] = Transition34_func_8004EDE8(&Transition34_D_80070328.unk7a[3], 0);
        Transition34_func_80043A38(0xC00);
        Transition34_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition34_D_80070328.grounded = 1;
        goto clearSpecialTail;
    case 0x69:
        Transition34_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition34_D_80070328.unk5 = 0;
        Transition34_func_80043A38(0xC00);
        Transition34_D_80070328.grounded = 1;
        goto clearDeathFlag;
    case 0x66:case 0x67:case 0x6A:
        stateBaseA=Raw34State;
        __asm__("" : "=r"(stateBaseA) : "0"(stateBaseA));
        destination=(Vector3D*)(stateBaseA+0x48);
        *(int*)stateBaseA=3;
        Transition34_D_80070328.unk8[0]=Transition34_func_8004EDE8(destination,0);
        Transition34_D_80070328.unk15b=1;
        Transition34_D_80070328.grounded=0;
        Transition34_D_80070328.union144.a.unk13cb=0x14;
clearSpecialTail:
        Transition34_D_80070328.idle=0;
        Transition34_D_80070328.unk15g=0;
        return;
    case 0x6B:
        savedBase = Transition34RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Transition34RawMovement;
        Transition34RawMovement = MOVEMENT_STATE_HURT;
        Transition34_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Transition34_D_80070328.unk8[0] = Transition34_func_8004EDE8(sourceC, 0);
        Transition34_D_80070328.unk7a[2].z = 0xDC0;
        Transition34_D_80070328.grounded = 0;
        Transition34_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Transition34_D_80070328.damageFlags & 0x200) {
            Transition34_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition34_D_80070328.union144.a.unk13cc = 1;
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        return;
    case 0x6C:
        Transition34_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition34_D_80070328.unk5 = 0;
        Transition34_func_80043A38(0xC00);
        Transition34_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
clearDeathFlag:
        Transition34_D_8006E524 = 0xF;
        return;
    case 0x68: {
        register int previousMovement __asm__("$2")=Transition34RawMovement;
        register int kind __asm__("$3");
        register int flags __asm__("$3");
        register unsigned char* unionPointer __asm__("$5");
        __asm__("" : "=r"(previousMovement) : "0"(previousMovement));
        kind=7;
        __asm__("" : "=r"(kind) : "0"(kind));
        Transition34RawMovement=kind;
        __asm__ volatile("" : : : "memory");
        flags=Transition34_D_80070328.unk17a;
        __asm__ volatile("" : "=r"(flags) : "0"(flags) : "memory");
        unionPointer=Transition34RawUnion;
        __asm__("" : "=r"(flags),"=r"(unionPointer) : "0"(flags),"1"(unionPointer));
        Transition34_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(flags) : "0"(flags) : "memory");
        *(int*)unionPointer=previousMovement;
        if(flags&0x400){
            sourceC=(Vector3D*)(unionPointer-0xB8);
            func_8004F178(sourceC,(Vector3D*)(unionPointer+0xD8));
            Transition34_func_8004F0E8(sourceC,6);
        }else if(Transition34_D_80070328.unk22[5]>=0){
            tableOffsetOrValue=Transition34_D_80070328.unk22[5]*2;
            tableValueA=*(short*)((unsigned char*)Signed34TableB+tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            Transition34_D_80070328.unk7a[2].x=tableValueA>>1;
            tableOffsetOrValue=*(short*)((unsigned char*)Signed34TableA+tableOffsetOrValue);
            Transition34_D_80070328.unk7a[2].z=0;
            __asm__ volatile("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Transition34_D_80070328.unk7a[2].y=tableOffsetOrValue>>1;
        }else Transition34_func_8004F168((Vector3D*)(unionPointer-0xB8));
        destination=&Transition34_D_80070328.unk7a[1];
        func_8004F178(destination,(Vector3D*)((unsigned char*)destination+0xC));
        Transition34_D_80070328.grounded=1;
        Transition34_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        return;
    }
    default:return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_34/animation", func_level_34_800972CC);
