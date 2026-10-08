#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_22/animation", func_level_22_80096434);

int Callback22First42A44(void) __asm__("func_80042A44");
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 numeric decode.
 * Original animation callback at 80097D08; private+0x30 child pointer,
 * child+0x38 halfword, player+0x74 vector, byte offsets +0x24/-0x74/+0x58.
 * Unsigned halfword load with signed shifts 16/17 and signed guarded division
 * follow original instructions. Empty constraints preserve original register
 * lifetimes and scheduling; they emit no instructions. Helper meanings, units,
 * cadence and runtime semantics remain unresolved. Acceptance requires every
 * original word/internal jump, strict complete TU, EXE and every overlay hash.
 */
extern int Callback22Step __asm__("D_80070328+0x144");
extern int Callback22Z __asm__("D_80070328+8");
extern int Callback22Limit __asm__("D_80070328+0x280");
extern Spyro Callback22Player __asm__("D_80070328");
int Callback22Call80037058(int x, int y) __asm__("func_80037058");
int Callback22Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback22Call80041930(void) __asm__("func_80041930");
void Callback22Call80041AE8(void) __asm__("func_80041AE8");
void Callback22Call80041C20(void) __asm__("func_80041C20");
void Callback22Call80042A44(void) __asm__("func_80042A44");
void Callback22Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback22Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38,D_8006C648;
int Callback22Query(Vector3D*,int) __asm__("func_8001A358");
extern unsigned char* Callback22Table[] __asm__("D_8006EE2C");
extern unsigned char Callback22Source[] __asm__("D_80070328+0x74");
extern int D_80071908;
extern Vector3D D_80071918;
void Callback22Call8004F110(Vector3D*,int) __asm__("func_8004F110");
int Callback22Call80038000(Moby*,Vector3D*,int,int,int) __asm__("func_80038000");
void Callback22Call8004F1C8(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004F1C8");
void Callback22Call8003BE70(int) __asm__("func_8003BE70");
void func_level_22_80097D08(void) {
    struct {Vector3D first; int reserved24; Vector3D second; int reserved34; Vector3D third; int reserved44;} local;
    register Moby* descriptorMoby __asm__("$2");
    register unsigned int selector __asm__("$16");

    register int positionDelta __asm__("$2");
    register int positionValue __asm__("$3");

    switch(Callback22Player.animationState) {
    case 0x14:
    case 0x64:
        if(func_800438F4()==0)func_80043728();
        Callback22Call80041C20();
        Callback22Player.unk9a=0;
        goto call42A44;
    case 0x20:
    case 0x35:
    case 0x36:
    case 0x67:
    case 0x69:
    case 0x6C:
        Callback22Call80041C20();
call42A44:
        Callback22Call80042A44();
clearSharedValue:
        Callback22Player.unk4[0]=0;
        return;
    case 0x66:
        Callback22Call80041C20();
        Callback22Call80042A44();
        descriptorMoby=Callback22Player.critterMobyPtr;
        __asm__ volatile("" : "=r"(descriptorMoby) : "0"(descriptorMoby) : "memory");
        Callback22Player.unk4[0]=0;
        goto descriptorTail;
    case 0x65:
        func_800438F4();
        Callback22Call80041C20();
        Callback22Call80042A44();
        Callback22Call80041930();
        goto queryC00;
    case 0x13:
    case 0x15:
        Callback22Call80041C20();
        Callback22Call80042A44();
        Callback22Call80041930();
        goto clearSharedValue;
    case 0x1A:
    case 0x68:
        Callback22Call80041C20();
        Callback22Call80042A44();
queryC00:
        Callback22Call80043A38(0xC00);
        goto clearSharedValue;
    case 0x6B:
        Callback22Call80041C20();
        Callback22Call80042A44();
        Callback22Call80041930();
        if(Callback22Player.unk7a[3].z<0 && Callback22Player.animationStateFrames>=4)
            Callback22Player.unk5=1;
        goto clearSharedValue;
        case 0x1E: {
            register int* zWord __asm__("$5")=&Callback22Z;
            register int velocity __asm__("$6")=Callback22Step;
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
            status=Callback22Limit;
            velocity+=tick;
            Callback22Step=velocity;
            __asm__("" : : : "memory");
            if(status>=0 && D_8006FA38<0)goto lowerLimit;
            {
                register int limit __asm__("$3")=0x9000;
                register int exceeded __asm__("$2");
                __asm__("" : "=r"(limit) : "0"(limit));
                exceeded=limit<velocity;
                if(exceeded)Callback22Step=limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2")=velocity<0x2581;
                if(!below)Callback22Step=0x2580;
            }
        limitsDone:
            Callback22Call80041C20();
            Callback22Call80042A44();
            func_8004F178(&local.first,&Callback22Player.position);
            local.first.z+=0x400;
            Callback22Player.unk4[0]=Callback22Query(&local.first,0xC00);
            positionDelta=(int)Callback22Player.union144.a.unk13cb;
            positionValue=Callback22Player.position.z;
            positionDelta >>= 6;
            positionValue-=positionDelta;
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            Callback22Player.position.z=positionValue;
            return;
        }
    case 0x24:
    case 0x25:
    case 0x30:
        Callback22Call80041C20();
        Callback22Call80042A44();
        Callback22Call80043A38(0xC00);
        if ((Callback22Player.ticksSinceLastSurfaceTouch == 0) && (func_80040954(Callback22Player.unk11[2]) == 9)) {
            func_8004F178((Vector3D *) ((unsigned char*)&Callback22Player.ticksSinceLastSurfaceTouch + 0x94), (Vector3D *) ((unsigned char*)&Callback22Player.ticksSinceLastSurfaceTouch + 0x14));
            Callback22Player.union144.a.unk13da = Callback22Player.unk7a[3].z;
        }
        Callback22Player.unk4[0] = 0;
        if ((Callback22Player.unk5 == 1) && ((Callback22Player.animationStateFrames >= 0xD) || !(Callback22Word8006E538 & 0x40))) {
            Callback22Player.unk5 = 2;
        }
        if (Callback22Player.unk5 != 3) {
            Callback22Player.union144.a.unk13db.x = 0;
            Callback22Player.union144.a.unk13db.y = 0;
            return;
        }
        break;
    case 0x6A:
    case 0x6D: {
        register unsigned char* privateData __asm__("$17")=Callback22Player.critterMobyPtr->mobyTag;
        register int changed __asm__("$20")=0;
        register Vector3D* vectorBase __asm__("$16");
        register Vector3D* copyBase __asm__("$18");
        register unsigned char* sourceBase __asm__("$19");
        register int queryHeight __asm__("$16");
        if(*(Moby**)(privateData+0x30)!=0) {
            vectorBase=&local.second;
            sourceBase=Callback22Source;
            func_8004F178(vectorBase,(Vector3D*)sourceBase);
            Callback22Call8004F110(vectorBase,6);
            {
                Moby* child=*(Moby**)(privateData+0x30);
                child->position.z+=((int)((unsigned int)*(unsigned short*)((unsigned char*)child+0x38)<<16))>>17;
            }
            func_8004F194(vectorBase,vectorBase,(Vector3D*)((unsigned char*)*(Moby**)(privateData+0x30)+0xC));
            copyBase=&local.third;
            func_8004F178(copyBase,vectorBase);
            {
                int height=((int)((unsigned int)*(unsigned short*)((unsigned char*)*(Moby**)(privateData+0x30)+0x38)<<16))>>17;
                register int result=Callback22Call80038000(*(Moby**)(privateData+0x30),vectorBase,height,height,0x1022);
                register Vector3D* childVector __asm__("$4")=vectorBase;
                if(result!=0) {
                    register Vector3D* childCopy __asm__("$6")=copyBase;
                    {register Moby* childArgument __asm__("$5")=*(Moby**)(privateData+0x30);
                    __asm__ volatile("" : "=r"(changed) : "0"(changed) : "memory");
                    changed=1;
                    Callback22Call8004F1C8(childVector,(Vector3D*)((unsigned char*)childArgument+0xC),childCopy);}
                    func_8004F0E8(vectorBase,6);
                    func_8004F194((Vector3D*)sourceBase,(Vector3D*)sourceBase,vectorBase);
                }
            }
            Callback22Call80041C20();
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
                Callback22Call8004F1C8(argument0,argument0,vectorBase);
            }}
            {register Moby* child __asm__("$2")=*(Moby**)(privateData+0x30);
            register int childValue __asm__("$3")=*(short*)((unsigned char*)child+0x38);
            register int playerValue __asm__("$2")=Callback22Player.unk4a;
            playerValue+=childValue;
            __asm__("" : "=r"(playerValue) : "0"(playerValue));
            queryHeight=playerValue+64;}
            if(Callback22Query((Vector3D*)(sourceBase-0x74),queryHeight)!=0 && Callback22Player.unk7a[2].z<=0) {
                if(Callback22Player.unk7a[2].z>=-2047)
                    Callback22Player.position.z=D_80071908+queryHeight-64;
                Callback22Player.ticksSinceLastSurfaceTouch=0;
                func_8004F178((Vector3D*)(sourceBase+0x58),&D_80071918);
            } else {
                register int* counterPointer __asm__("$2")=&Callback22Player.ticksSinceLastSurfaceTouch;
                register int counterValue __asm__("$3");
                register int vectorZ __asm__("$4");
                __asm__("" : "=r"(counterPointer) : "0"(counterPointer));
                Callback22Player.unk9e.x=0;
                Callback22Player.unk9e.y=0;
                counterValue=*counterPointer;
                __asm__ volatile("" : "=r"(counterPointer) : "0"(counterPointer) : "memory");
                vectorZ=4096;
                Callback22Player.unk9e.z=vectorZ;
                counterValue+=1;
                *counterPointer=counterValue;
            }
        } else Callback22Call80041C20();
        Callback22Player.unk4[0]=0;
        if(Callback22Player.animationState!=0x6A)return;
        descriptorMoby=Callback22Player.critterMobyPtr;
descriptorTail:
        selector=Callback22Table[descriptorMoby->mobyClass][6];
        if(selector!=(unsigned int)Callback22Player.unk22[3]) {
            if(Callback22Call8003BF6C(Callback22Player.unk22[3],Callback22Player.unk22[2])!=0)
                Callback22Call8003BE70(Callback22Player.unk22[2]);
            Callback22Player.unk22[2]=-1;
        }
        Callback22Player.unk22[3]=selector;
        if(Callback22Call8003BF6C(selector,Callback22Player.unk22[2])==0)
            Callback22Player.unk22[2]=PlaySound(Callback22Player.unk22[3],0,4);
        return;
    }
    default:
        return;
    }
}


#define LEVEL_ID 22
#define PlaySpyroSounds_level_22 func_level_22_800983C0
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_22_8009852C(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x14:
    case 0x1a:
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
    case 0x15:
    case 0x66:
    case 0x67:
    case 0x6a:
    case 0x6b:
        func_80043ABC(0);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 800985A8.
 * Reuses verified33 private0/4/8 swirl and15 flags490/trig producer, verified21
 * squish, verified37 drowning/vector, verified24 walk and signed-halfword routes.
 * Original22 supplies state13 skateboard vector14C/98, scalar2000 minimum,
 * roll5C saved in144, shared35/36 clears, and64..6D independent special states.
 * Original68 flags400 copy from21C/scale6 or signed65920/658A0 table shift1.
 * Numeric offsets are bytes; widths, branches and shifts are source-native.
 * Empty constraints retain original register lifetimes without emitting opcodes.
 * Require every original code/local jump/owned table word, strict complete TU
 * and complete EXE/every overlay hashes. Helper/audio semantics, units, cadence
 * and live runtime parity remain open. Execution is once per invocation.
 */
extern int D_8006C700;
void Transition22_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");
int Transition22_func_8004E880(int,int,int) __asm__("func_8004E880");

extern Spyro Transition22_D_80070328 __asm__("D_80070328");
int Transition22_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
int Transition22_func_8003636C(int low, int high) __asm__("func_8003636C");
void Transition22_func_80043A38(int scale) __asm__("func_80043A38");
void Transition22_func_800441F0(void) __asm__("func_800441F0");
void Transition22_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition22_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition22RawUnion[] __asm__("D_80070328+0x144");
extern int Transition22RawMovement __asm__("D_80070328+0x50");
extern void (*Call22Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw22State[] __asm__("D_80070328+0x50");
extern short Signed22TableA[] __asm__("D_800658A0");
extern short Signed22TableB[] __asm__("D_80065920");

int Call22EA2C(int) __asm__("func_8004EA2C");
int Call22E9E4(int) __asm__("func_8004E9E4");
void func_level_22_800985A8(int arg0){
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");



    int shiftedValue;
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
    case 0x14:
        Transition22_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition22_D_80070328.unk5 = 0;
        Transition22_func_800441F0();
        Transition22_D_80070328.grounded = 1;
        Transition22_D_80070328.union144.a.unk13cb = Transition22_func_8003636C(1, 3);
        Transition22_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        stateBase=(unsigned char*)&Transition22RawMovement;
        privateData = Transition22_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition22_D_80070328.unk5 = 0;
        Transition22_D_80070328.grounded = 0;
        Transition22_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition22_D_80070328.m_WhirlwindPointer;
        yawValue=Transition22_D_80070328.rotation.yaw;
        positionZ=Transition22_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition22_D_80070328.union144.a.unk13cc=yawValue;
        Transition22_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition22_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition22_D_80070328.union144.a.unk13ce.z=heightValue;
        __asm__ volatile("" : : : "memory");
        heightValue = ((int) (heightValue << 0xA) >> 0xA) + 0x400;
        __asm__("" : "=r"(heightValue) : "0"(heightValue));
        Transition22_D_80070328.union144.a.unk13ce.y = heightValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
        Transition22_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition22_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition22_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition22_D_80070328.unk13e[0] = (int) Transition22_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition22_D_80070328.unk20a = 0;
        Transition22_D_80070328.critterMobyPtr = 0;
        Transition22_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x15:
        Transition22_D_80070328.movementState=7;
        Transition22_D_80070328.grounded=0;
        Transition22_D_80070328.unk5=0;
        if(Transition22_D_80070328.unk17a&0x490){
            register int first __asm__("$2")=Transition22_D_80070328.unk17e.x;
            register int second __asm__("$3")=Transition22_D_80070328.unk17e.z;
            register int third __asm__("$2");
            __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second));
            first<<=6;
            Transition22_D_80070328.unk7a[2].x=first;
            __asm__ volatile("" : : : "memory");
            third=Transition22_D_80070328.unk17e.y;
            __asm__("" : "=r"(third),"=r"(second) : "0"(third),"1"(second));
            second<<=6;
            Transition22_D_80070328.unk7a[2].z=second;
            __asm__ volatile("" : "=r"(third) : "0"(third) : "memory");
            third<<=6;
            Transition22_D_80070328.unk7a[2].y=third;
        }else{
            shiftedValue=Transition22_func_8004E880(-Transition22_D_80070328.unk7a[2].x,-Transition22_D_80070328.unk7a[2].y,1);
            Transition22_D_80070328.unk7b=shiftedValue;
            Transition22_D_80070328.unk7a[2].x=(Call22EA2C(shiftedValue)<<12)>>12;
            Transition22_D_80070328.unk7a[2].y=(Call22E9E4(Transition22_D_80070328.unk7b)<<12)>>12;
            Transition22_D_80070328.unk7a[2].z=0x1000;
        }
        goto clearPointers;
    case 0x1A:
        savedBase = Transition22RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        oldMovementC = Transition22RawMovement;
        Transition22RawMovement = MOVEMENT_STATE_HURT;
        Transition22_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementC;
        Transition22_func_8004F168(destination);
        Transition22_D_80070328.grounded = 1;
        Transition22_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        soundSelector=D_8006C654->squish;
        soundZero=0;
        PlaySound(soundSelector,(Moby*)soundZero,0);
        goto clearPointers;
    case 0x1E: {
        register int oldState __asm__("$3")=Transition22RawMovement;
        register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$8")=SpawnParticle;
        register int* stateWord __asm__("$2");
        register int value __asm__("$2");
        __asm__ volatile("" : "=r"(oldState), "=r"(callback) : "0"(oldState), "1"(callback) : "memory");
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Transition22RawMovement=value;
        value=1;
        __asm__("" : "=r"(value) : "0"(value));
        Transition22_D_80070328.grounded=value;
        value=15;
        __asm__("" : "=r"(value) : "0"(value));
        Transition22_D_8006E524=value;
        stateWord=(int*)Transition22RawUnion;
        __asm__("" : "=r"(stateWord) : "0"(stateWord));
        Transition22_D_80070328.unk5=0;
        *stateWord=oldState;
        __asm__ volatile("" : : : "memory");
        *stateWord=0;
        if(callback)callback(5,10,0,0);
        Transition22_D_80070328.unk22[2]=PlaySound((int)D_8006C654->drown,0,0);
        value=(int)D_8006C654->drown;
        __asm__ volatile("" : "=r"(value) : "0"(value) : "memory");
        Transition22_D_80070328.unk20a=0;
        Transition22_D_80070328.critterMobyPtr=0;
        Transition22_D_80070328.unk22[3]=value;
        return;
    }
    case 0x20:
        Transition22_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition22_D_80070328.unk5 = 0;
        Transition22_func_80043A38(0xC00);
        Transition22_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition22_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x24:case 0x25:case 0x30: {
        register unsigned char* state __asm__("$16")=Raw22State;
        register int kind __asm__("$17");
        register int previous __asm__("$2")=*(int*)state;
        register int currentScalar __asm__("$2");
        register int scalar __asm__("$3");
        register int savedRoll __asm__("$3");
        __asm__("" : "=r"(previous) : "0"(previous));
        kind=19;
        __asm__("" : "=r"(kind) : "0"(kind));

        destination=(Vector3D*)(state+0x48);
        if(previous!=kind){
            Transition22_D_80070328.union144.a.unk13db.z=0;
            Transition22_D_80070328.unk5=0;
            Transition22_func_8004F168((Vector3D*)(state+0xFC));
            Transition22_D_80070328.union144.a.unk13da=0;
            __asm__ volatile("" : "=r"(state) : "0"(state) : "memory");
            destination=(Vector3D*)(state+0x48);
        }
        *(int*)state=kind;
        Transition22_D_80070328.unk8[0]=Transition22_func_8004EDE8(destination,0);
        currentScalar=D_8006C700;
        __asm__("" : "=r"(currentScalar) : "0"(currentScalar));
        scalar=0x2000;
        __asm__("" : "=r"(scalar) : "0"(scalar));
        Transition22_D_80070328.horizontalSpeed=scalar;
        __asm__ volatile("" : "=r"(currentScalar) : "0"(currentScalar) : "memory");
        if(currentScalar<0x2000)D_8006C700=scalar;
        Transition22_func_80043A38(0xC00);
        savedRoll=Transition22_D_80070328.rotation.roll;
        __asm__("" : "=r"(savedRoll) : "0"(savedRoll));
        Transition22_D_80070328.grounded=1;
        Transition22_D_80070328.unk15c=0;
        Transition22_D_80070328.union144.a.unk13cc=0;
        Transition22_D_80070328.union144.a.unk13db.x=0;
        Transition22_D_80070328.union144.a.unk13db.y=0;
        Transition22_D_80070328.unk13a[0]=0x20000;
        Transition22_D_80070328.union144.a.unk13cb=savedRoll;
        return;
    }
    case 0x35:
    case 0x36:
        Transition22_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition22_D_80070328.unk5 = 0;
        Transition22_func_800441F0();
        Transition22_D_80070328.grounded = 1;
clearPointers:
        Transition22_D_80070328.unk20a=0;
        Transition22_D_80070328.critterMobyPtr=0;
        return;
    case 0x64:
    case 0x6D:
        Transition22_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition22_D_80070328.unk5 = 0;
        Transition22_func_800441F0();
        Transition22_D_80070328.grounded = 1;
        return;
    case 0x65:
        Transition22_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition22_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((unsigned char*)(unsigned char*)&Transition22_D_80070328.movementState + 0x3C), (Vector3D *) ((unsigned char*)(unsigned char*)&Transition22_D_80070328.movementState + 0x48));
            Transition22_D_80070328.unk5 = 1;
        } else {
            Transition22_D_80070328.unk5 = 0;
        }
        Transition22_D_80070328.unk8[0] = Transition22_func_8004EDE8(&Transition22_D_80070328.unk7a[3], 0);
        Transition22_func_80043A38(0xC00);
        Transition22_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition22_D_80070328.grounded = 1;
        goto clearSpecialTail;
    case 0x69:
        Transition22_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition22_D_80070328.unk5 = 0;
        Transition22_func_80043A38(0xC00);
        Transition22_D_80070328.grounded = 1;
        goto clearDeathFlag;
    case 0x66:case 0x67:case 0x6A:
        stateBaseA=Raw22State;
        __asm__("" : "=r"(stateBaseA) : "0"(stateBaseA));
        destination=(Vector3D*)(stateBaseA+0x48);
        *(int*)stateBaseA=3;
        Transition22_D_80070328.unk8[0]=Transition22_func_8004EDE8(destination,0);
        Transition22_D_80070328.unk15b=1;
        Transition22_D_80070328.grounded=0;
        Transition22_D_80070328.union144.a.unk13cb=0x14;
clearSpecialTail:
        Transition22_D_80070328.idle=0;
        Transition22_D_80070328.unk15g=0;
        return;
    case 0x6B:
        savedBase = Transition22RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Transition22RawMovement;
        Transition22RawMovement = MOVEMENT_STATE_HURT;
        Transition22_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Transition22_D_80070328.unk8[0] = Transition22_func_8004EDE8(sourceC, 0);
        Transition22_D_80070328.unk7a[2].z = 0xDC0;
        Transition22_D_80070328.grounded = 0;
        Transition22_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Transition22_D_80070328.damageFlags & 0x200) {
            Transition22_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition22_D_80070328.union144.a.unk13cc = 1;
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        return;
    case 0x6C:
        Transition22_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition22_D_80070328.unk5 = 0;
        Transition22_func_80043A38(0xC00);
        Transition22_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
clearDeathFlag:
        Transition22_D_8006E524 = 0xF;
        return;
    case 0x68: {
        register int previousMovement __asm__("$2")=Transition22RawMovement;
        register int kind __asm__("$3");
        register int flags __asm__("$3");
        register unsigned char* unionPointer __asm__("$5");
        __asm__("" : "=r"(previousMovement) : "0"(previousMovement));
        kind=7;
        __asm__("" : "=r"(kind) : "0"(kind));
        Transition22RawMovement=kind;
        __asm__ volatile("" : : : "memory");
        flags=Transition22_D_80070328.unk17a;
        __asm__ volatile("" : "=r"(flags) : "0"(flags) : "memory");
        unionPointer=Transition22RawUnion;
        __asm__("" : "=r"(flags),"=r"(unionPointer) : "0"(flags),"1"(unionPointer));
        Transition22_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(flags) : "0"(flags) : "memory");
        *(int*)unionPointer=previousMovement;
        if(flags&0x400){
            sourceC=(Vector3D*)(unionPointer-0xB8);
            func_8004F178(sourceC,(Vector3D*)(unionPointer+0xD8));
            Transition22_func_8004F0E8(sourceC,6);
        }else if(Transition22_D_80070328.unk22[5]>=0){
            tableOffsetOrValue=Transition22_D_80070328.unk22[5]*2;
            tableValueA=*(short*)((unsigned char*)Signed22TableB+tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            Transition22_D_80070328.unk7a[2].x=tableValueA>>1;
            tableOffsetOrValue=*(short*)((unsigned char*)Signed22TableA+tableOffsetOrValue);
            Transition22_D_80070328.unk7a[2].z=0;
            __asm__ volatile("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Transition22_D_80070328.unk7a[2].y=tableOffsetOrValue>>1;
        }else Transition22_func_8004F168((Vector3D*)(unionPointer-0xB8));
        destination=&Transition22_D_80070328.unk7a[1];
        func_8004F178(destination,(Vector3D*)((unsigned char*)destination+0xC));
        Transition22_D_80070328.grounded=1;
        Transition22_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        return;
    }
    default:return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_22/animation", func_level_22_80098E80);
