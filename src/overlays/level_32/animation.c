#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_32/animation", func_level_32_80097550);

/* AI generated; not human reviewed. SCUS-94467 8009953C..80099CDC.
 * Verified37 scalar/independent table,50 case24 and43 case31 routes reused
 * against original32 selectors, query negation and particle numeric writes.
 * Empty constraints preserve original lifetimes; helper meaning, units and
 * invocation cadence remain unresolved. Original800997B0..800997E0 supplies
 * query negation, V3 step and callback A0; shift6 occupies callback load delay.
 * Original8009985C..80099894 supplies final V0 callback, stack vectors30/20,
 * numeric returned bytes2=6 andA=32. These writes establish no helper contract.
 * Every code/table word, strict full TU and every retail hash must agree.
 */
extern int Callback32Step __asm__("D_80070328+0x144");
extern int Callback32Z __asm__("D_80070328+8");
extern int Callback32Limit __asm__("D_80070328+0x280");
extern Spyro Callback32Player __asm__("D_80070328");
int Callback32Call80037058(int x, int y) __asm__("func_80037058");
int Callback32Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback32Call80041930(void) __asm__("func_80041930");
void Callback32Call80041AE8(void) __asm__("func_80041AE8");
void Callback32Call80041C20(void) __asm__("func_80041C20");
void Callback32Call80042A44(void) __asm__("func_80042A44");
void Callback32Call80043A38(int scale) __asm__("func_80043A38");
extern int D_8006FA38,D_8006C648;
int Callback32Query(Vector3D*,int) __asm__("func_8001A358");
extern int Callback32Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback32Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback32Values[] __asm__("D_8006FCF0");
void Callback32Call80049590(void) __asm__("func_80049590");
extern int D_8006C640;
extern int Callback32Word8006E538 __asm__("D_8006E538");
int Callback32Call800363DC(int,int) __asm__("func_800363DC");
void func_level_32_8009953C(void) {
    struct {Vector3D first; int reserved1C; Vector3D second; int reserved2C; Vector3D third; int reserved3C;} local;
    register Vector3D* playerPosition __asm__("$17");
    register Vector3D* particlePosition __asm__("$16");
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

    switch (Callback32Player.animationState) {
    case 0x14:
        if(func_800438F4()==0)func_80043728();
        Callback32Call80041C20();
        Callback32Player.unk9a=0;
        goto call42A44;
    case 0x35:
    case 0x36:
    case 0x96:
    case 0x97:
        Callback32Call80041C20();
call42A44:
        Callback32Call80042A44();
clearSharedValue:
        Callback32Player.unk4[0]=0;
        return;
    case 0x9:
        Callback32Call80041C20();
        Callback32Call80042A44();
        if (Callback32Player.unk5==1) Callback32Call80041930();
        else Callback32Call80043A38(0xC00);
        if ((unsigned char)Callback32Player.bodyAnimation.nextFrame < 10) {
            Callback32Player.cheatColour.a=255;
            if (Callback32Player.bodyAnimation.nextFrame & 1) {
                Callback32Player.cheatColour.b=255;
                Callback32Player.cheatColour.g=255;
                Callback32Player.cheatColour.r=255;
            } else {
                Callback32Player.cheatColour.b=64;
                Callback32Player.cheatColour.g=64;
                Callback32Player.cheatColour.r=64;
            }
        }
        goto clearSharedValue;
    case 0x13:
    case 0x15:
        Callback32Call80041C20();
        Callback32Call80042A44();
        Callback32Call80041930();
        goto clearSharedValue;
    case 0x1C:
        Callback32Call80041C20();
        Callback32Call80042A44();
        Callback32Call80041930();
        if (Callback32Player.unk7a[3].z < 0 && Callback32Player.animationStateFrames >= 4)
            Callback32Player.unk5=1;
        goto clearSharedValue;
        case 0x1E: {
            register int* zWord __asm__("$5")=&Callback32Z;
            register int velocity __asm__("$6")=Callback32Step;
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
            status=Callback32Limit;
            velocity+=tick;
            Callback32Step=velocity;
            __asm__("" : : : "memory");
            if(status>=0 && D_8006FA38<0)goto lowerLimit;
            {
                register int limit __asm__("$3")=0x9000;
                register int exceeded __asm__("$2");
                __asm__("" : "=r"(limit) : "0"(limit));
                exceeded=limit<velocity;
                if(exceeded)Callback32Step=limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2")=velocity<0x2581;
                if(!below)Callback32Step=0x2580;
            }
        limitsDone:
            Callback32Call80041C20();
            Callback32Call80042A44();
            playerPosition=&Callback32Player.position;
            func_8004F178(&local.first,playerPosition);
            local.first.z+=0x400;
            {
                register int result __asm__("$2")=Callback32Query(&local.first,0xC00);
                register int step __asm__("$3")=Callback32Step;
                register int z __asm__("$2");
                register char* (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$4");
                __asm__("" : "=r"(step) : "0"(step), "r"(result));
                result=-result;
                Callback32Player.unk4[0]=result;
                z=Callback32Z;
                callback=SpawnParticle;
                __asm__ volatile("" : "=r"(step) : "0"(step) : "memory");
                step >>=6;
                z-=step;
                Callback32Z=z;
                if(callback==0) return;
            }
            if (D_8006C640 & 1) {
                register int sample __asm__("$2");
                register int component __asm__("$3");
                register int kind __asm__("$4");
                register int subtype __asm__("$5");
                register Vector3D* position __asm__("$6");
                register Vector3D* vector __asm__("$7");
                register char* (*particles)(int,int,Vector3D*,Vector3D*) __asm__("$2");
                register char* returned __asm__("$2");
                particlePosition=&local.third;
                local.second.x=0;
                local.second.y=0;
                local.second.z=14;
                func_8004F178(particlePosition,playerPosition);
                sample=Callback32Call800363DC(0,300);
                component=local.third.x+sample;
                __asm__("" : "=r"(component) : "0"(component));
                local.third.x=component;
                sample=Callback32Call800363DC(0,300);
                component=local.third.y+sample;
                __asm__("" : "=r"(component) : "0"(component));
                local.third.y=component;
                sample=Callback32Call800363DC(0,300);
                kind=1;
                subtype=0x3A;
                __asm__("" : "=r"(kind), "=r"(subtype), "=r"(sample) : "0"(kind), "1"(subtype), "2"(sample) : "memory");
                component=local.third.z;
                __asm__ volatile("" : : : "memory");
                position=particlePosition;
                __asm__("" : "=r"(position) : "0"(position), "r"(sample));
                component+=sample;
                __asm__("" : "=r"(component) : "0"(component) : "$2", "memory");
                particles=SpawnParticle;
                __asm__ volatile("" : "=r"(particles) : "0"(particles) : "$7");
                vector=&local.second;
                __asm__("" : "=r"(particles), "=r"(vector), "=r"(component) : "0"(particles), "1"(vector), "2"(component));
                local.third.z=component;
                returned=particles(kind,subtype,position,vector);
                returned[2]=6;
                returned[10]=32;
            }
            return;
        }
    case 0x24:
    case 0x25:
    case 0x30:
        Callback32Call80041C20();
        Callback32Call80042A44();
        Callback32Call80043A38(0xC00);
        if ((Callback32Player.ticksSinceLastSurfaceTouch == 0) && (func_80040954(Callback32Player.unk11[2]) == 9)) {
            func_8004F178((Vector3D *) ((unsigned char*)&Callback32Player.ticksSinceLastSurfaceTouch + 0x94), (Vector3D *) ((unsigned char*)&Callback32Player.ticksSinceLastSurfaceTouch + 0x14));
            Callback32Player.union144.a.unk13da = Callback32Player.unk7a[3].z;
        }
        Callback32Player.unk4[0] = 0;
        if ((Callback32Player.unk5 == 1) && ((Callback32Player.animationStateFrames >= 0xD) || !(Callback32Word8006E538 & 0x40))) {
            Callback32Player.unk5 = 2;
        }
        if (Callback32Player.unk5 != 3) {
            Callback32Player.union144.a.unk13db.x = 0;
            Callback32Player.union144.a.unk13db.y = 0;
            return;
        }
        break;
    case 0x28:
    case 0x29:
    case 0x39:
        Callback32Call80041C20();
        Callback32Call80042A44();
        descriptor=&Callback32Player.unk22[2];
        if (Callback32Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback32Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setDecreasingFlag;
            tableValue=decreasingValue-0xC8;
            goto storeDecreasingValue;
            }
            goto setDecreasingFlag;
storeDecreasingValue:
            *(int*)(Callback32Values + valueOffset) = tableValue;
setDecreasingFlag:
            flagOffset = *descriptor * 0x2C;
            Callback32Flags[flagOffset] = Callback32Flags[flagOffset] | 0x10;
            __asm__ volatile("" : : : "memory");
        }
        goto clearSharedValue;
    case 0x2A:
        Callback32Call80041C20();
        Callback32Call80042A44();
        Callback32Call80049590();
        descriptor=&Callback32Player.unk22[2];
        if (Callback32Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback32Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback32Player.unk22[2];
        }
        if (Callback32Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback32Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback32Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback32Flags[flagOffset] = Callback32Flags[flagOffset] | 0x10;
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
        Callback32Call80041C20();
        Callback32Call80042A44();
        Callback32Call80041AE8();
        if ((unsigned char) Callback32Player.unk10[4] != 0) {
            computedValue = -Callback32Player.unk9ha[4] - Callback32Call80037058(Callback32Player.position.x, Callback32Player.position.y);
            positionValue = Callback32Player.unk4a - computedValue;
            Callback32Player.unk4[0] = computedValue;
            positionDelta = (int) Callback32Player.union144.a.unk13cc >> 6;
            positionValue -= positionDelta;
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            Callback32Player.position.z=positionValue;
            return;
        }
        break;
    case 0x31:
        Callback32Call80041C20();
        Callback32Call80042A44();
        Callback32Call80043A38(0xC00);
        if (func_80040954(Callback32Player.unk11[2]) == 0xA) {
            Callback32Player.union144.a.unk13cb = 0;
        } else {
            Callback32Player.union144.a.unk13cb += D_8006C648;
        }
        Callback32Player.unk4[0] = 0;
        if (Callback32Call8003BF6C((int) D_8006C654->unk32, Callback32Player.unk22[2]) == 0) {
            Callback32Player.unk22[2] = PlaySound((int) D_8006C654->unk32, 0, 4);
            Callback32Player.unk22[3] = (int) D_8006C654->unk32;
            return;
        }
        break;
    default:
        return;
    }
}


#define LEVEL_ID 32
#define PlaySpyroSounds_level_32 func_level_32_80099CE0
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_32_80099E1C(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0xa:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1d:
    case 0x1f:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2d:
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4a:
    case 0x4b:
    case 0x4c:
    case 0x4d:
    case 0x4e:
    case 0x4f:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x5c:
    case 0x5d:
    case 0x5e:
    case 0x5f:
    case 0x60:
    case 0x61:
    case 0x62:
    case 0x63:
    case 0x64:
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6a:
    case 0x6b:
    case 0x6c:
    case 0x6d:
    case 0x6e:
    case 0x6f:
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x78:
    case 0x79:
    case 0x7a:
    case 0x7b:
    case 0x7c:
    case 0x7d:
    case 0x7e:
    case 0x7f:
    case 0x80:
    case 0x81:
    case 0x82:
    case 0x83:
    case 0x84:
    case 0x85:
    case 0x86:
    case 0x87:
    case 0x88:
    case 0x89:
    case 0x8a:
    case 0x8b:
    case 0x8c:
    case 0x8d:
    case 0x8e:
    case 0x8f:
    case 0x90:
    case 0x91:
    case 0x92:
    case 0x93:
    case 0x94:
    case 0x95:
    case 0x96:
    case 0x97:
        break;

    case 0x9:
        {
            register int* state __asm__("$4") = (int*)((char*)&spyro + 0x4C);
            __asm__("" : "=r"(state) : "0"(state));
            if (*state == 1) func_80043ABC(0);
            else func_80043ABC((Vector3D*)((char*)state + 0x80));
        }
        break;
    case 0x14:
    case 0x1e:
    case 0x2b:
    case 0x2c:
    case 0x31:
    case 0x35:
    case 0x36:
        func_80043ABC(&spyro.unk9e);
        break;
    case 0x13:
    case 0x15:
    case 0x1c:
        func_80043ABC(0);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80099EB8.
 * Reuses verified41 water/swirl/slide/table,12 helper9 producer,22 numeric15
 * and skateboard,37 vector/drowning. Original32 helper input10C, vector8C/98
 * or flags400 copy21C/scale6/signed table; independent35/36; skateboard scalar
 * 2440 minimum and separate130 flag20000;96/97 animation<96 helper14C/98 route.
 * Numeric offsets are bytes. Word60 wrap/clamp vectors800/801/FFF give0/-7FF/-1.
 * Original widths/shifts/branches and empty constraints preserve instructions.
 * Require every code/internal jump/owned table word, strict full TU and all
 * retail hashes. Helper/audio semantics, units, cadence and live parity are open.
 */
extern int D_8006C700;
int Call32E9E4(int) __asm__("func_8004E9E4");
int Call32EA2C(int) __asm__("func_8004EA2C");
extern int Transition32_D_8006E528 __asm__("D_8006E528");
void Transition32_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");
int Transition32_func_80040954(int) __asm__("func_80040954");
extern int Transition32RawX __asm__("D_80070328+0x8C");
extern short Transition32SignedB[] __asm__("D_80065920");
extern short Transition32SignedA[] __asm__("D_800658A0");
extern Spyro Transition32_D_80070328 __asm__("D_80070328");
int Transition32_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition32_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition32_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition32RawUnion[] __asm__("D_80070328+0x144");
extern int Transition32RawMovement __asm__("D_80070328+0x50");
extern void (*Call32Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw32State[] __asm__("D_80070328+0x50");
extern short Signed32TableA[] __asm__("D_800658A0");
extern short Signed32TableB[] __asm__("D_80065920");

extern int D_80071934;
int Call32A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw32NegativeWord __asm__("D_80070328+0x28");
extern int Raw32TableIndex __asm__("D_80070328+0x298");
extern int Raw32Yaw __asm__("D_80070328+0x64");
int Transition32_func_8003636C(int,int) __asm__("func_8003636C");
void Transition32_func_800441F0(void) __asm__("func_800441F0");
void Transition32_func_80043A38(int) __asm__("func_80043A38");
int Transition32_func_8004E880(int,int,int) __asm__("func_8004E880");
void func_level_32_80099EB8(int arg0){
    struct {Vector3D first; int gap1; Vector3D second; int gap2; Vector3D third;} vectors;
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
    register int oldMovementA __asm__("$3");
    register int oldMovementB __asm__("$3");
    register int flags __asm__("$2");
    register unsigned char* header __asm__("$17");
    register int* sourceA __asm__("$16");
    int* sourceB;
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");
    int shiftedValue;
    switch(arg0){
    case 0x14:
        Transition32_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition32_D_80070328.unk5 = 0;
        Transition32_func_800441F0();
        Transition32_D_80070328.grounded = 1;
        Transition32_D_80070328.union144.a.unk13cb = Transition32_func_8003636C(1, 3);
        Transition32_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x35:
        Transition32_D_80070328.movementState=0;
        Transition32_D_80070328.unk5=0;
        Transition32_func_800441F0();
        Transition32_D_80070328.grounded=1;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x9:
        header = (unsigned char*)&Transition32_D_80070328.unk11[2];
        if (Transition32_func_80040954(*(int*)header) == 7) {
            sourceA = (int*)(header - 0x74);
            oldMovementA = Transition32RawMovement;
            Transition32RawMovement = MOVEMENT_STATE_HURT;
            Transition32_D_80070328.unk5 = 1;
            Transition32_D_80070328.union144.a.unk13cb = oldMovementA;
            func_8004F178((Vector3D *) (header - 0x80), (Vector3D *) sourceA);
            Transition32_D_80070328.unk8[0] = Transition32_func_8004EDE8((Vector3D *) sourceA, 0);
            Transition32_D_80070328.unk7a[2].z = 0xDC0;
            Transition32_D_80070328.grounded = 0;
        } else {
            oldMovementB = Transition32RawMovement;
            flags = Transition32_D_80070328.unk17a;
            __asm__("" : "=r"(oldMovementB), "=r"(flags) : "0"(oldMovementB), "1"(flags));
            Transition32RawMovement = MOVEMENT_STATE_HURT;
            Transition32_D_80070328.unk5 = 0;
            __asm__ __volatile__("" : "=r"(flags) : "0"(flags) : "memory");
            Transition32_D_80070328.union144.a.unk13cb = oldMovementB;
            sourceB = (int*)(header - 0x80);
            if (flags & 0x400) {
                func_8004F178((Vector3D *) sourceB, (Vector3D *) (header + 0x110));
                Transition32_func_8004F0E8((Vector3D *) sourceB, 6);
            } else if (Transition32_D_80070328.unk22[5] >= 0) {
                tableIndex = Transition32_D_80070328.unk22[5] * 2;
                tableValue = *(short*)((unsigned char*)Transition32SignedB + tableIndex);
                __asm__("" : "=r"(tableValue) : "0"(tableValue));
                Transition32RawX = tableValue >> 1;
                tableIndex = *(short*)((unsigned char*)Transition32SignedA + tableIndex);
                Transition32_D_80070328.unk7a[2].z = 0;
                __asm__ __volatile__("" : "=r"(tableIndex) : "0"(tableIndex) : "memory");
                Transition32_D_80070328.unk7a[2].y = tableIndex >> 1;
            } else {
                __asm__("" : "=r"(header) : "0"(header));
                destination = (Vector3D*)(header - 0x80);
                Transition32_func_8004F168(destination);
            }
            func_8004F178(&Transition32_D_80070328.unk7a[1], (Vector3D*)((unsigned char*)&Transition32_D_80070328.unk7a[1] + 0xC));
            Transition32_func_80043A38(0xC00);
            Transition32_D_80070328.grounded = 1;
        }
        Transition32_D_8006E528 = 0x2D;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        goto clearPointers;
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        stateBase=(unsigned char*)&Transition32RawMovement;
        privateData = Transition32_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition32_D_80070328.unk5 = 0;
        Transition32_D_80070328.grounded = 0;
        Transition32_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition32_D_80070328.m_WhirlwindPointer;
        yawValue=Transition32_D_80070328.rotation.yaw;
        positionZ=Transition32_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition32_D_80070328.union144.a.unk13cc=yawValue;
        Transition32_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition32_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition32_D_80070328.union144.a.unk13ce.z=heightValue;
        __asm__ volatile("" : : : "memory");
        heightValue = ((int) (heightValue << 0xA) >> 0xA) + 0x400;
        __asm__("" : "=r"(heightValue) : "0"(heightValue));
        Transition32_D_80070328.union144.a.unk13ce.y = heightValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
        Transition32_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition32_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition32_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition32_D_80070328.unk13e[0] = (int) Transition32_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition32_D_80070328.unk20a = 0;
        Transition32_D_80070328.critterMobyPtr = 0;
        Transition32_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x15:
        Transition32_D_80070328.movementState=7;
        Transition32_D_80070328.grounded=0;
        Transition32_D_80070328.unk5=0;
        if(Transition32_D_80070328.unk17a&0x490){
            register int first __asm__("$2")=Transition32_D_80070328.unk17e.x;
            register int second __asm__("$3")=Transition32_D_80070328.unk17e.z;
            register int third __asm__("$2");
            __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second));
            first<<=6;
            Transition32_D_80070328.unk7a[2].x=first;
            __asm__ volatile("" : : : "memory");
            third=Transition32_D_80070328.unk17e.y;
            __asm__("" : "=r"(third),"=r"(second) : "0"(third),"1"(second));
            second<<=6;
            Transition32_D_80070328.unk7a[2].z=second;
            __asm__ volatile("" : "=r"(third) : "0"(third) : "memory");
            third<<=6;
            Transition32_D_80070328.unk7a[2].y=third;
        }else{
            shiftedValue=Transition32_func_8004E880(-Transition32_D_80070328.unk7a[2].x,-Transition32_D_80070328.unk7a[2].y,1);
            Transition32_D_80070328.unk7b=shiftedValue;
            Transition32_D_80070328.unk7a[2].x=(Call32EA2C(shiftedValue)<<12)>>12;
            Transition32_D_80070328.unk7a[2].y=(Call32E9E4(Transition32_D_80070328.unk7b)<<12)>>12;
            Transition32_D_80070328.unk7a[2].z=0x1000;
        }
        goto clearPointers;
    case 0x1C:
        savedBase = Transition32RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Transition32RawMovement;
        Transition32RawMovement = MOVEMENT_STATE_HURT;
        Transition32_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Transition32_D_80070328.unk8[0] = Transition32_func_8004EDE8(sourceC, 0);
        Transition32_D_80070328.unk7a[2].z = 0xDC0;
        Transition32_D_80070328.grounded = 0;
        Transition32_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Transition32_D_80070328.damageFlags & 0x200) {
            Transition32_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition32_D_80070328.union144.a.unk13cc = 1;
            soundSelector=D_8006C654->lavaBurn;
            soundZero=0;
            goto sharedSound;
        }
        goto clearPointers;
    case 0x1E: {
        register int oldState __asm__("$3")=Transition32RawMovement;
        register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$8")=SpawnParticle;
        register int* stateWord __asm__("$2");
        register int value __asm__("$2");
        __asm__ volatile("" : "=r"(oldState), "=r"(callback) : "0"(oldState), "1"(callback) : "memory");
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Transition32RawMovement=value;
        value=1;
        __asm__("" : "=r"(value) : "0"(value));
        Transition32_D_80070328.grounded=value;
        value=15;
        __asm__("" : "=r"(value) : "0"(value));
        Transition32_D_8006E524=value;
        stateWord=(int*)Transition32RawUnion;
        __asm__("" : "=r"(stateWord) : "0"(stateWord));
        Transition32_D_80070328.unk5=0;
        *stateWord=oldState;
        __asm__ volatile("" : : : "memory");
        *stateWord=0;
        if(callback)callback(5,10,0,0);
        Transition32_D_80070328.unk22[2]=PlaySound((int)D_8006C654->drown,0,0);
        value=(int)D_8006C654->drown;
        __asm__ volatile("" : "=r"(value) : "0"(value) : "memory");
        Transition32_D_80070328.unk20a=0;
        Transition32_D_80070328.critterMobyPtr=0;
        Transition32_D_80070328.unk22[3]=value;
        return;
    }
    case 0x24:case 0x25:case 0x30: {
        register unsigned char* state __asm__("$16")=Raw32State;
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
            Transition32_D_80070328.union144.a.unk13db.z=0;
            Transition32_D_80070328.unk5=0;
            Transition32_func_8004F168((Vector3D*)(state+0xFC));
            Transition32_D_80070328.union144.a.unk13da=0;
            __asm__ volatile("" : "=r"(state) : "0"(state) : "memory");
            destination=(Vector3D*)(state+0x48);
        }
        *(int*)state=kind;
        Transition32_D_80070328.unk8[0]=Transition32_func_8004EDE8(destination,0);
        currentScalar=D_8006C700;
        __asm__("" : "=r"(currentScalar) : "0"(currentScalar));
        scalar=0x2440;
        __asm__("" : "=r"(scalar) : "0"(scalar));
        Transition32_D_80070328.horizontalSpeed=scalar;
        __asm__ volatile("" : "=r"(currentScalar) : "0"(currentScalar) : "memory");
        if(currentScalar<0x2440)D_8006C700=scalar;
        Transition32_func_80043A38(0xC00);
        savedRoll=Transition32_D_80070328.rotation.roll;
        __asm__("" : "=r"(savedRoll) : "0"(savedRoll));
        Transition32_D_80070328.grounded=1;
        Transition32_D_80070328.unk15c=0;
        Transition32_D_80070328.union144.a.unk13cc=0;
        Transition32_D_80070328.union144.a.unk13db.x=0;
        Transition32_D_80070328.union144.a.unk13db.y=0;
        Transition32_D_80070328.unk13a[0]=0x20000;
        Transition32_D_80070328.union144.a.unk13cb=savedRoll;
        return;
    }
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition32_D_80070328.movementState - 0xB) >= 2U) && (Transition32_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition32_D_80070328.movementState - 0x50));
                if ((Transition32_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw32NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition32_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call32A358(&vectors.first, 0x800);
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
            firstWrappedWord = Transition32_D_80070328.rotation.pitch & 0xFFF;
            Transition32_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition32_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition32_D_80070328.rotation.pitch > 0) {
                Transition32_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition32_D_80070328.unk5 = 1;
            }
            Transition32_func_8004F168((Vector3D *) ((unsigned char*)&Transition32_D_80070328.rotation.pitch + 0xEC));
            Transition32_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition32_D_80070328.unk8[0] = Transition32_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition32_D_80070328.rotation.pitch + 0x38), 0);
            Transition32_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition32_D_80070328.animationState == 0x2A) {
            Transition32_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition32_D_80070328.union144.a.unk13da = 0;
        }
        Transition32_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition32_D_80070328.unk20a = 0;
        Transition32_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw32State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw32NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition32_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call32A358(localVector, 0x800);
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
            if (Transition32_D_80070328.animationState == 0x2E) {
                Transition32_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition32_D_80070328.rotation.pitch & 0xFFF;
            Transition32_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition32_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition32_D_80070328.rotation.pitch > 0) {
                Transition32_D_80070328.rotation.pitch = 0;
            }
            Transition32_D_80070328.unk5 = 1;
            Transition32_func_8004F168((Vector3D *) ((unsigned char*)&Transition32_D_80070328.animationState + 0x104));
            Transition32_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition32_D_80070328.unk8[0] = Transition32_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition32_D_80070328.animationState + 0x50), 0);
            Transition32_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition32_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition32_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition32RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition32RawUnion;
            *(int*)unionPointer=(-Transition32_D_80070328.unk7a[2].z)>>2;
            if(Transition32RawMovement!=8){Transition32_D_80070328.union144.a.unk13cc=0x5900;Transition32RawMovement=10;}
            Transition32_D_80070328.unk5=0;
            Transition32_D_80070328.unk8[0]=Transition32_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition32_D_80070328.grounded=1;
            Transition32_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call32A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x31: {
        register unsigned char* lengthBase __asm__("$5")=(unsigned char*)&Transition32_D_80070328.unk8[0];
        register int valueA __asm__("$4");
        register int valueB __asm__("$5");
        register int valueKind __asm__("$6");
        *(int*)lengthBase=0;
        if(Transition32_D_80070328.animationState==0xD || Transition32_D_80070328.movementState==1)
            func_8004F178((Vector3D*)(lengthBase-0x30),(Vector3D*)(lengthBase-0x18));
        else Transition32_func_8004F168((Vector3D*)(lengthBase-0x30));
        func_8004F178(&Transition32_D_80070328.unk7a[2],(Vector3D*)((unsigned char*)&Transition32_D_80070328.unk7a[2]-0xC));
        Transition32_D_80070328.movementState=17;
        Transition32_D_80070328.unk5=0;
        Transition32_func_80043A38(0xC00);
        Transition32_D_80070328.grounded=0;
        Transition32_D_80070328.union144.a.unk13cb=0;
        valueKind=1;
        if(Transition32_D_80070328.unk9ha[0]>=11) {
            valueA=Transition32_D_80070328.unk9e.x;
            valueB=Transition32_D_80070328.unk9e.y;
        } else {
            valueA=Transition32_D_80070328.unk7a[3].x;
            valueB=valueA;
        }
        Transition32_D_80070328.union144.a.unk13cc=Transition32_func_8004E880(valueA,valueB,valueKind);
        goto clearPointers;
    }
    case 0x36:
        Transition32_D_80070328.movementState=0;
        Transition32_D_80070328.unk5=0;
        Transition32_func_800441F0();
        Transition32_D_80070328.grounded=1;
        goto clearPointers;
    case 0x39: {
        register int previousMovement __asm__("$2")=Transition32RawMovement;
        register int numericKind __asm__("$3");
        register int indexWord __asm__("$3");
        register unsigned char* unionPointer __asm__("$5");
        register int tableOffset __asm__("$2");
        register int tableWord __asm__("$3");
        __asm__("" : "=r"(previousMovement) : "0"(previousMovement));
        numericKind=7;
        __asm__("" : "=r"(numericKind) : "0"(numericKind));
        Transition32RawMovement=numericKind;
        __asm__ volatile("" : : : "memory");
        indexWord=Raw32TableIndex;
        __asm__ volatile("" : "=r"(indexWord) : "0"(indexWord) : "memory");
        unionPointer=Transition32RawUnion;
        __asm__("" : "=r"(indexWord),"=r"(unionPointer) : "0"(indexWord),"1"(unionPointer) : "memory");
        Transition32_D_80070328.unk5=0;
        *(int*)unionPointer=previousMovement;
        if(indexWord<0)Raw32TableIndex=((Raw32Yaw+0x800)>>4)&0xFF;
        tableOffset=Raw32TableIndex*2;
        tableWord=*(short*)((unsigned char*)Signed32TableB+tableOffset);
        destination=(Vector3D*)(unionPointer-0xC4);
        *(int*)(unionPointer-0xB8)=tableWord;
        tableOffset=*(short*)((unsigned char*)Signed32TableA+tableOffset);
        Transition32_D_80070328.unk7a[2].z=0;
        Transition32_D_80070328.unk7a[2].y=tableOffset;
        func_8004F178(destination,(Vector3D*)(unionPointer-0xB8));
        Transition32_D_80070328.grounded=1;
        Transition32_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        { register unsigned char* soundTable __asm__("$2")=(unsigned char*)D_8006C654;
        __asm__ volatile("" : "=r"(soundTable) : "0"(soundTable) : "memory");
        soundZero=0;
        soundSelector=soundTable[0x19]; }
sharedSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
    }
clearPointers:
        Transition32_D_80070328.unk20a=0;
        Transition32_D_80070328.critterMobyPtr=0;
        return;
    case 0x96:case 0x97: {
        register unsigned char* animation __asm__("$16")=(unsigned char*)&Transition32_D_80070328.animationState;
        if(*(int*)animation<0x96){
            Transition32_func_8004F168((Vector3D*)(animation+0x104));
            Transition32_D_80070328.union144.a.unk13cb=0;
            Transition32_D_80070328.unk8[0]=Transition32_func_8004EDE8((Vector3D*)(animation+0x50),0);
            Transition32_D_80070328.grounded=1;
            Transition32_D_80070328.union144.a.unk13da=0;
            Transition32_D_80070328.movementState=MOVEMENT_STATE_SWIM_UNDERWATER;
        }
        return;
    }
    default:return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_32/animation", func_level_32_8009ACBC);
