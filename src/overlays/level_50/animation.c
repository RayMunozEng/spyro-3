#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_50/animation", func_level_50_8009A6B4);

extern int Callback50Word290 __asm__("D_80070328+0x290");
/* AI generated; not human reviewed. SCUS-94467 8009CF04..8009D564.
 * Baseline: verified level35_8008A2EC scalar and particle chains, adapted
 * to original level50 registers, final callback order and dispatch scope.
 * Original word/byte tables at 8006FCF0/8006FCE6 retain byte stride44,
 * numeric limits200/5096 and mask16. No sound or helper meanings are inferred.
 * Units, source producers, invocation cadence and runtime parity remain open.
 * Empty lifetime constraints emit no code; every original code/table word
 * and complete EXE/overlay hash must agree before acceptance.
 */
extern int Callback50Step __asm__("D_80070328+0x144");
extern int Callback50Z __asm__("D_80070328+8");
extern int Callback50Limit __asm__("D_80070328+0x280");
extern Spyro Callback50Player __asm__("D_80070328");
int Callback50Call80037058(int x, int y) __asm__("func_80037058");
int Callback50Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback50Call80041930(void) __asm__("func_80041930");
void Callback50Call80041AE8(void) __asm__("func_80041AE8");
void Callback50Call80041C20(void) __asm__("func_80041C20");
void Callback50Call80042A44(void) __asm__("func_80042A44");
void Callback50Call80043A38(int scale) __asm__("func_80043A38");
void Callback50Call80049590(void) __asm__("func_80049590");
void Callback50Call8004F110(Vector3D*, int) __asm__("func_8004F110");
extern int Callback50Word8006E344 __asm__("D_8006E344");
extern int Callback50Word8006E52C __asm__("D_8006E52C");
extern int Callback50Word8006E530 __asm__("D_8006E530");
extern int Callback50Word8006E538 __asm__("D_8006E538");
extern short Callback50Count __asm__("D_80070328+0x148");
extern int D_8006FA38,D_8006C648;
int Callback50Query(Vector3D*,int) __asm__("func_8001A358");
extern unsigned char Callback50Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback50Values[] __asm__("D_8006FCF0");
void func_level_50_8009CF04(void) {
    struct {
        Vector3D first;
        int reserved1C;
        Vector3D second;
        int reserved2C;
        int reserved[2];
    } local;
    register unsigned char* countBase __asm__("$5");
    register unsigned char* sourceBytes __asm__("$19");
    register Vector3D* vectorPointer __asm__("$17");
    register int* descriptor __asm__("$16");
    register int iteration __asm__("$16");
    register int secondLimit __asm__("$18");
    register int sample __asm__("$2");
    register int height __asm__("$3");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    register char* (*particles)(int,int,Vector3D*,Vector3D*) __asm__("$2");
    int computedValue;
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int computedValueA0 __asm__("$4");

    int descriptorResult;
    int flagOffset;

    register int positionDelta __asm__("$2");
    register int tableValue __asm__("$2");
    register int positionValueV3 __asm__("$3");
    register int valueOffset __asm__("$3");

    switch (Callback50Player.animationState) {
    case 0x35:
    case 0x36:
    case 0x96:
    case 0x97:
        Callback50Call80041C20();
        Callback50Call80042A44();
        goto clearSharedValue;
    default:
        return;
    case 0x15:
        Callback50Call80041C20();
        Callback50Call80042A44();
        Callback50Call80041930();
        goto clearSharedValue;
    case 0x1C:
        Callback50Call80041C20();
        Callback50Call80042A44();
        Callback50Call80041930();
        if ((Callback50Player.unk7a[3].z < 0) && (Callback50Player.animationStateFrames >= 4)) {
            Callback50Player.unk5 = 1;
        }
        goto clearSharedValue;
        case 0x1E: {
            register int* zWord __asm__("$5")=&Callback50Z;
            register int velocity __asm__("$6")=Callback50Step;
            register int positionValue __asm__("$2")=*zWord;
            register int tick __asm__("$3")=D_8006C648;
            register int increment __asm__("$4");
            register int status __asm__("$2");
            __asm__("" : "=r"(velocity) : "0"(velocity));
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            __asm__("" : "=r"(tick) : "0"(tick));
            increment=velocity>>6;
            __asm__("" : "=r"(increment) : "0"(increment));
            positionValue+=increment;
            __asm__("" : "=r"(tick) : "0"(tick), "r"(positionValue));
            tick<<=9;
            *zWord=positionValue;
            status=Callback50Limit;
            velocity+=tick;
            Callback50Step=velocity;
            __asm__("" : : : "memory");
            if(status>=0 && D_8006FA38<0)goto lowerLimit;
            {
                register int limit __asm__("$3")=0x9000;
                register int exceeded __asm__("$2");
                __asm__("" : "=r"(limit) : "0"(limit));
                exceeded=limit<velocity;
                if(exceeded)Callback50Step=limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2")=velocity<0x2581;
                if(!below)Callback50Step=0x2580;
            }
        limitsDone:
            Callback50Call80041C20();
            Callback50Call80042A44();
            func_8004F178(&local.first,&Callback50Player.position);
            local.first.z+=0x400;
            Callback50Player.unk4[0]=Callback50Query(&local.first,0xC00);
            positionDelta=(int)Callback50Player.union144.a.unk13cb;
            positionValueV3=Callback50Player.position.z;
            positionDelta >>= 6;
            goto storePosition;
        }
        case 0x21:
        case 0x22:
        case 0x23:
            Callback50Call80041C20();
            Callback50Call80042A44();
            Callback50Call80041930();
            if (SpawnParticle != 0) {
                countBase=(unsigned char*)&Callback50Count;
                if (*(short*)countBase == 0) goto clearSharedValue;
                secondLimit = 1;
                if (*(short*)countBase >= 2) {
                    secondLimit = 2;
                }
                iteration = 0;
                if (secondLimit != 0) {
                    vectorPointer=&local.second;
                    __asm__("" : "=r"(vectorPointer), "=r"(countBase) : "0"(vectorPointer), "1"(countBase));
                    sourceBytes=countBase-0xB0;
                    do {
                        func_8004F178(vectorPointer, (Vector3D *) sourceBytes);
                        Callback50Call8004F110(vectorPointer, 7);
                        iteration += 1;
                        sample=rand();
                        component=local.second.x;
                        sample &= 254;
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        local.second.x=component;
                        sample=rand();
                        component=local.second.y;
                        sample &= 254;
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        local.second.y=component;
                        sample=rand();
                        kind=1;
                        subtype=0x17;
                        position=sourceBytes - 0x98;
                        __asm__("" : "=r"(kind), "=r"(subtype), "=r"(position) : "0"(kind), "1"(subtype), "2"(position), "r"(sample) : "$3", "memory");
                        component=local.second.z;
                        __asm__("" : "=r"(component) : "0"(component), "r"(sample));
                        sample &=254;
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component) : "$2", "memory");
                        particles=SpawnParticle;
                        __asm__ volatile("" : "=r"(particles) : "0"(particles) : "$7");
                        vector=vectorPointer;
                        __asm__("" : "=r"(particles), "=r"(vector), "=r"(component) : "0"(particles), "1"(vector), "2"(component));
                        local.second.z=component;
                        particles(kind,subtype,(Vector3D*)position,vector);
                    } while (iteration < secondLimit);
                }
            }
            goto clearSharedValue;
    case 0x24:
    case 0x25:
    case 0x30:
        Callback50Call80041C20();
        Callback50Call80042A44();
        Callback50Call80043A38(0xC00);
        if ((Callback50Player.ticksSinceLastSurfaceTouch == 0) && (func_80040954(Callback50Player.unk11[2]) == 9)) {
            func_8004F178((Vector3D *) ((unsigned char*)&Callback50Player.ticksSinceLastSurfaceTouch + 0x94), (Vector3D *) ((unsigned char*)&Callback50Player.ticksSinceLastSurfaceTouch + 0x14));
            Callback50Player.union144.a.unk13da = Callback50Player.unk7a[3].z;
        }
        Callback50Player.unk4[0] = 0;
        if ((Callback50Player.unk5 == 1) && ((Callback50Player.animationStateFrames >= 0xD) || !(Callback50Word8006E538 & 0x40))) {
            Callback50Player.unk5 = 2;
        }
        if (Callback50Player.unk5 != 3) {
            Callback50Player.union144.a.unk13db.x = 0;
            Callback50Player.union144.a.unk13db.y = 0;
            return;
        }
        break;
    case 0x28:
    case 0x29:
    case 0x39:
        Callback50Call80041C20();
        Callback50Call80042A44();
        descriptor=&Callback50Player.unk22[2];
        if (Callback50Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback50Values + valueOffset);
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
        Callback50Call80041C20();
        Callback50Call80042A44();
        Callback50Call80049590();
        descriptor=&Callback50Player.unk22[2];
        if (Callback50Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback50Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback50Player.unk22[2];
        }
        if (Callback50Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback50Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback50Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback50Flags[flagOffset] = Callback50Flags[flagOffset] | 0x10;
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
        Callback50Call80041C20();
        Callback50Call80042A44();
        Callback50Call80041AE8();
        if ((unsigned char) Callback50Player.unk10[4] != 0) {
            computedValueA0 = -Callback50Player.unk9ha[4] - Callback50Call80037058(Callback50Player.position.x, Callback50Player.position.y);
            positionValueV3 = Callback50Player.unk4a - computedValueA0;
            Callback50Player.unk4[0] = computedValueA0;
            positionDelta = (int) Callback50Player.union144.a.unk13cc >> 6;
            goto storePosition;
        }
        break;
storePosition:
        positionValueV3-=positionDelta;
        __asm__("" : "=r"(positionValueV3) : "0"(positionValueV3));
        Callback50Player.position.z=positionValueV3;
        return;
    case 0x3A:
        Callback50Call80041C20();
        Callback50Call80042A44();
        Callback50Player.cheatColour.a = 0xFF;
        Callback50Player.unk4[0] = 0;
        Callback50Player.cheatColour.b = 0x20;
        Callback50Player.cheatColour.g = 0x20;
        Callback50Player.cheatColour.r = 0x20;
        return;
    case 0x1B:
    case 0x3C:
        Callback50Call80041C20();
        Callback50Call80042A44();
        if (Callback50Player.movementState != MOVEMENT_STATE_SUPERFLY) goto clearSharedValue;
call41930:
        Callback50Call80041930();
clearSharedValue:
        Callback50Player.unk4[0] = 0;
        return;
    }
}


#define LEVEL_ID 50
#define PlaySpyroSounds_level_50 func_level_50_8009D568
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_50_8009D6E0(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
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
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3b:
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

    case 0x1e:
    case 0x2b:
    case 0x2c:
    case 0x35:
    case 0x36:
    case 0x3a:
        func_80043ABC(&spyro.unk9e);
        break;
    case 0x1b:
    case 0x3c:
        if (*(int*)((char*)&spyro + 0x50) != 6) func_80043ABC(0);
        break;
    case 0x15:
    case 0x1c:
        func_80043ABC(0);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8009D770.
 * Reuses verified32 water/vector/skateboard/table,10 fly and37 death.
 * Original50 class2F5/F0 branch, pointer250 helpers14C/98, state12/B0/300;
 * shared sound after39 and independent35/36. Numeric offsets are bytes;
 * word60 wrap vectors800/801/FFF give0/-7FF/-1. Scalar2440, flag20000.
 * Require every instruction/internal jump/owned table, strict full TU and
 * complete original hashes. Helper meanings, units, cadence and live parity open.
 */
extern int D_8006C700;
int Call50E9E4(int) __asm__("func_8004E9E4");
int Call50EA2C(int) __asm__("func_8004EA2C");
extern Spyro Transition50_D_80070328 __asm__("D_80070328");
int Transition50_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition50_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition50_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition50RawUnion[] __asm__("D_80070328+0x144");
extern int Transition50RawMovement __asm__("D_80070328+0x50");
extern void (*Call50Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw50State[] __asm__("D_80070328+0x50");
extern short Signed50TableA[] __asm__("D_800658A0");
extern short Signed50TableB[] __asm__("D_80065920");

extern int D_80071934;
int Call50A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw50NegativeWord __asm__("D_80070328+0x28");
extern int Raw50TableIndex __asm__("D_80070328+0x298");
extern int Raw50Yaw __asm__("D_80070328+0x64");
void Transition50_func_800441F0(void) __asm__("func_800441F0");
void Transition50_func_80043A38(int) __asm__("func_80043A38");
int Transition50_func_8004E880(int,int,int) __asm__("func_8004E880");
void func_level_50_8009D770(int arg0){
    struct {Vector3D first; int gap1; Vector3D second; int gap2; Vector3D third;} vectors;
    register int negativeWord __asm__("$3");
    int firstResult,secondResult,firstWrappedWord,secondWrappedWord,firstParticleKind,secondParticleKind,firstParticleSubtype,secondParticleSubtype;
    register Vector3D* destination __asm__("$4");

    int lengthResult;


    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");
    int shiftedValue;
    switch(arg0){
    case 0x35:
        Transition50_D_80070328.movementState=0;
        Transition50_D_80070328.unk5=0;
        Transition50_func_800441F0();
        Transition50_D_80070328.grounded=1;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x15:
        Transition50_D_80070328.movementState=7;
        Transition50_D_80070328.grounded=0;
        Transition50_D_80070328.unk5=0;
        if(Transition50_D_80070328.unk17a&0x490){
            register int first __asm__("$2")=Transition50_D_80070328.unk17e.x;
            register int second __asm__("$3")=Transition50_D_80070328.unk17e.z;
            register int third __asm__("$2");
            __asm__("" : "=r"(first),"=r"(second) : "0"(first),"1"(second));
            first<<=6;
            Transition50_D_80070328.unk7a[2].x=first;
            __asm__ volatile("" : : : "memory");
            third=Transition50_D_80070328.unk17e.y;
            __asm__("" : "=r"(third),"=r"(second) : "0"(third),"1"(second));
            second<<=6;
            Transition50_D_80070328.unk7a[2].z=second;
            __asm__ volatile("" : "=r"(third) : "0"(third) : "memory");
            third<<=6;
            Transition50_D_80070328.unk7a[2].y=third;
        }else{
            shiftedValue=Transition50_func_8004E880(-Transition50_D_80070328.unk7a[2].x,-Transition50_D_80070328.unk7a[2].y,1);
            Transition50_D_80070328.unk7b=shiftedValue;
            Transition50_D_80070328.unk7a[2].x=(Call50EA2C(shiftedValue)<<12)>>12;
            Transition50_D_80070328.unk7a[2].y=(Call50E9E4(Transition50_D_80070328.unk7b)<<12)>>12;
            Transition50_D_80070328.unk7a[2].z=0x1000;
        }
        goto clearPointers;
    case 0x1C:
        savedBase = Transition50RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Transition50RawMovement;
        Transition50RawMovement = MOVEMENT_STATE_HURT;
        Transition50_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Transition50_D_80070328.unk8[0] = Transition50_func_8004EDE8(sourceC, 0);
        Transition50_D_80070328.unk7a[2].z = 0xDC0;
        Transition50_D_80070328.grounded = 0;
        Transition50_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Transition50_D_80070328.damageFlags & 0x200) {
            Transition50_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition50_D_80070328.union144.a.unk13cc = 1;
            soundSelector=D_8006C654->lavaBurn;
            soundZero=0;
            goto sharedSound;
        }
        goto clearPointers;
    case 0x1E: {
        register int oldState __asm__("$3")=Transition50RawMovement;
        register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$8")=SpawnParticle;
        register int* stateWord __asm__("$2");
        register int value __asm__("$2");
        __asm__ volatile("" : "=r"(oldState), "=r"(callback) : "0"(oldState), "1"(callback) : "memory");
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Transition50RawMovement=value;
        value=1;
        __asm__("" : "=r"(value) : "0"(value));
        Transition50_D_80070328.grounded=value;
        value=15;
        __asm__("" : "=r"(value) : "0"(value));
        Transition50_D_8006E524=value;
        stateWord=(int*)Transition50RawUnion;
        __asm__("" : "=r"(stateWord) : "0"(stateWord));
        Transition50_D_80070328.unk5=0;
        *stateWord=oldState;
        __asm__ volatile("" : : : "memory");
        *stateWord=0;
        if(callback)callback(5,10,0,0);
        Transition50_D_80070328.unk22[2]=PlaySound((int)D_8006C654->drown,0,0);
        value=(int)D_8006C654->drown;
        __asm__ volatile("" : "=r"(value) : "0"(value) : "memory");
        Transition50_D_80070328.unk20a=0;
        Transition50_D_80070328.critterMobyPtr=0;
        Transition50_D_80070328.unk22[3]=value;
        return;
    }
    case 0x3A:
        Transition50_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition50_D_80070328.unk5 = 0;
        Transition50_func_80043A38(0xC00);
        Transition50_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition50_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x21:
    case 0x22:
    case 0x23: {
        register unsigned char* flyState __asm__("$16")=(unsigned char*)&Transition50RawMovement;
        if(*(int*)flyState!=6) {
            *(int*)flyState=6;
            Transition50_D_80070328.unk5=0;
            Transition50_func_8004F168((Vector3D*)(flyState+0x104));
            Transition50_D_80070328.union144.a.unk13db.y=0;
            lengthResult=Transition50_func_8004EDE8((Vector3D*)(flyState+0x48),0);
            Transition50_D_80070328.unk8[0]=lengthResult;
            if(lengthResult<0x800)Transition50_D_80070328.unk8[0]=0x800;
            if(Transition50_D_80070328.unk8[0]>=0x4B01)Transition50_D_80070328.unk8[0]=0x4B00;
            Transition50_D_80070328.union144.a.unk13cb=0;
            Transition50_D_80070328.union144.b.unk148=0;
            Transition50_D_80070328.union144.a.unk13ce.x=0;
            Transition50_D_80070328.union144.a.unk13ce.y=0;
            Transition50_D_80070328.grounded=0;
            Transition50_D_80070328.unk15b=0;
        }
        if(arg0<0xA0)goto clearPointers;
        return;
    }
    case 0x24:case 0x25:case 0x30: {
        register unsigned char* state __asm__("$16")=Raw50State;
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
            Transition50_D_80070328.union144.a.unk13db.z=0;
            Transition50_D_80070328.unk5=0;
            Transition50_func_8004F168((Vector3D*)(state+0xFC));
            Transition50_D_80070328.union144.a.unk13da=0;
            __asm__ volatile("" : "=r"(state) : "0"(state) : "memory");
            destination=(Vector3D*)(state+0x48);
        }
        *(int*)state=kind;
        Transition50_D_80070328.unk8[0]=Transition50_func_8004EDE8(destination,0);
        currentScalar=D_8006C700;
        __asm__("" : "=r"(currentScalar) : "0"(currentScalar));
        scalar=0x2440;
        __asm__("" : "=r"(scalar) : "0"(scalar));
        Transition50_D_80070328.horizontalSpeed=scalar;
        __asm__ volatile("" : "=r"(currentScalar) : "0"(currentScalar) : "memory");
        if(currentScalar<0x2440)D_8006C700=scalar;
        Transition50_func_80043A38(0xC00);
        savedRoll=Transition50_D_80070328.rotation.roll;
        __asm__("" : "=r"(savedRoll) : "0"(savedRoll));
        Transition50_D_80070328.grounded=1;
        Transition50_D_80070328.unk15c=0;
        Transition50_D_80070328.union144.a.unk13cc=0;
        Transition50_D_80070328.union144.a.unk13db.x=0;
        Transition50_D_80070328.union144.a.unk13db.y=0;
        Transition50_D_80070328.unk13a[0]=0x20000;
        Transition50_D_80070328.union144.a.unk13cb=savedRoll;
        return;
    }
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition50_D_80070328.movementState - 0xB) >= 2U) && (Transition50_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition50_D_80070328.movementState - 0x50));
                if ((Transition50_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw50NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition50_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call50A358(&vectors.first, 0x800);
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
            firstWrappedWord = Transition50_D_80070328.rotation.pitch & 0xFFF;
            Transition50_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition50_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition50_D_80070328.rotation.pitch > 0) {
                Transition50_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition50_D_80070328.unk5 = 1;
            }
            Transition50_func_8004F168((Vector3D *) ((unsigned char*)&Transition50_D_80070328.rotation.pitch + 0xEC));
            Transition50_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition50_D_80070328.unk8[0] = Transition50_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition50_D_80070328.rotation.pitch + 0x38), 0);
            Transition50_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition50_D_80070328.animationState == 0x2A) {
            Transition50_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition50_D_80070328.union144.a.unk13da = 0;
        }
        Transition50_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition50_D_80070328.unk20a = 0;
        Transition50_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw50State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw50NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition50_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call50A358(localVector, 0x800);
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
            if (Transition50_D_80070328.animationState == 0x2E) {
                Transition50_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition50_D_80070328.rotation.pitch & 0xFFF;
            Transition50_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition50_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition50_D_80070328.rotation.pitch > 0) {
                Transition50_D_80070328.rotation.pitch = 0;
            }
            Transition50_D_80070328.unk5 = 1;
            Transition50_func_8004F168((Vector3D *) ((unsigned char*)&Transition50_D_80070328.animationState + 0x104));
            Transition50_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition50_D_80070328.unk8[0] = Transition50_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition50_D_80070328.animationState + 0x50), 0);
            Transition50_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition50_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition50_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition50RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition50RawUnion;
            *(int*)unionPointer=(-Transition50_D_80070328.unk7a[2].z)>>2;
            if(Transition50RawMovement!=8){Transition50_D_80070328.union144.a.unk13cc=0x5900;Transition50RawMovement=10;}
            Transition50_D_80070328.unk5=0;
            Transition50_D_80070328.unk8[0]=Transition50_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition50_D_80070328.grounded=1;
            Transition50_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call50A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x36:
        Transition50_D_80070328.movementState=0;
        Transition50_D_80070328.unk5=0;
        Transition50_func_800441F0();
        Transition50_D_80070328.grounded=1;
        goto clearPointers;
    case 0x39: {
        register int previousMovement __asm__("$2")=Transition50RawMovement;
        register int numericKind __asm__("$3");
        register int indexWord __asm__("$3");
        register unsigned char* unionPointer __asm__("$5");
        register int tableOffset __asm__("$2");
        register int tableWord __asm__("$3");
        __asm__("" : "=r"(previousMovement) : "0"(previousMovement));
        numericKind=7;
        __asm__("" : "=r"(numericKind) : "0"(numericKind));
        Transition50RawMovement=numericKind;
        __asm__ volatile("" : : : "memory");
        indexWord=Raw50TableIndex;
        __asm__ volatile("" : "=r"(indexWord) : "0"(indexWord) : "memory");
        unionPointer=Transition50RawUnion;
        __asm__("" : "=r"(indexWord),"=r"(unionPointer) : "0"(indexWord),"1"(unionPointer) : "memory");
        Transition50_D_80070328.unk5=0;
        *(int*)unionPointer=previousMovement;
        if(indexWord<0)Raw50TableIndex=((Raw50Yaw+0x800)>>4)&0xFF;
        tableOffset=Raw50TableIndex*2;
        tableWord=*(short*)((unsigned char*)Signed50TableB+tableOffset);
        destination=(Vector3D*)(unionPointer-0xC4);
        *(int*)(unionPointer-0xB8)=tableWord;
        tableOffset=*(short*)((unsigned char*)Signed50TableA+tableOffset);
        Transition50_D_80070328.unk7a[2].z=0;
        Transition50_D_80070328.unk7a[2].y=tableOffset;
        func_8004F178(destination,(Vector3D*)(unionPointer-0xB8));
        Transition50_D_80070328.grounded=1;
        Transition50_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        { register unsigned char* soundTable __asm__("$2")=(unsigned char*)D_8006C654;
        __asm__ volatile("" : "=r"(soundTable) : "0"(soundTable) : "memory");
        soundZero=0;
        soundSelector=soundTable[0x19]; }
sharedSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
    }
clearPointers:
        Transition50_D_80070328.unk20a=0;
        Transition50_D_80070328.critterMobyPtr=0;
        return;
    case 0x1B:case 0x3C: {
        register unsigned char* critterWord __asm__("$16")=(unsigned char*)&Transition50_D_80070328.critterMobyPtr;
        register int classWord __asm__("$3");
        register unsigned char* movement __asm__("$3");
        if(*(Moby**)critterWord && ((classWord=Transition50_D_80070328.critterMobyPtr->mobyClass)==0x2F5 || classWord==0xF0)){
            if(Transition50RawMovement!=6){
                Transition50RawMovement=6;
                Transition50_D_80070328.unk5=0;
                Transition50_func_8004F168((Vector3D*)(critterWord-0xFC));
                Transition50_D_80070328.union144.a.unk13db.y=0;
                lengthResult=Transition50_func_8004EDE8((Vector3D*)(critterWord-0x1B8),0);
                Transition50_D_80070328.unk8[0]=lengthResult;
                if(lengthResult<0x800)Transition50_D_80070328.unk8[0]=0x800;
                if(Transition50_D_80070328.unk8[0]>=0x4B01)Transition50_D_80070328.unk8[0]=0x4B00;
                Transition50_D_80070328.union144.a.unk13cb=0;
                Transition50_D_80070328.union144.b.unk148=0;
                Transition50_D_80070328.union144.a.unk13ce.x=0;
                Transition50_D_80070328.union144.a.unk13ce.y=0;
                Transition50_D_80070328.grounded=0;
                Transition50_D_80070328.unk15b=0;
            }
        }else{
            movement=Raw50State;
            *(int*)movement=18;
            Transition50_D_80070328.unk5=0;
            Transition50_D_80070328.unk8[0]=Transition50_func_8004EDE8((Vector3D*)(movement+0x48),0);
            Transition50_D_80070328.grounded=1;
            Transition50_func_80043A38(0xC00);
            Transition50_D_80070328.unk4a=0x300;
        }
        return;
    }
    case 0x96:case 0x97: {
        register unsigned char* animation __asm__("$16")=(unsigned char*)&Transition50_D_80070328.animationState;
        if(*(int*)animation<0x96){
            Transition50_func_8004F168((Vector3D*)(animation+0x104));
            Transition50_D_80070328.union144.a.unk13cb=0;
            Transition50_D_80070328.unk8[0]=Transition50_func_8004EDE8((Vector3D*)(animation+0x50),0);
            Transition50_D_80070328.grounded=1;
            Transition50_D_80070328.union144.a.unk13da=0;
            Transition50_D_80070328.movementState=MOVEMENT_STATE_SWIM_UNDERWATER;
        }
        return;
    }
    default:return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_50/animation", func_level_50_8009E40C);
