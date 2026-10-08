#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_21/animation", func_level_21_8008B0BC);

/* AI generated; not human reviewed. SCUS-94467 8008CA58..8008CF7C.
 * Verified20/37 independent table paths; original21 supplies selector scope,
 * case19 and3D callback/flag/table producers. Meanings/units/cadence unresolved.
 * Callbackkind1/subtype9, globals8006E530=120 and8006E52C=4,
 * and descriptor source8006C654 retain original widths and call order.
 * Their numeric equality does not establish audio/event or runtime semantics.
 * Every original word, strict full TU and all retail hashes required.
 */
extern Spyro Callback21Player __asm__("D_80070328");
int Callback21Call80037058(int x, int y) __asm__("func_80037058");
int Callback21Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback21Call80041930(void) __asm__("func_80041930");
void Callback21Call80041AE8(void) __asm__("func_80041AE8");
void Callback21Call80041C20(void) __asm__("func_80041C20");
void Callback21Call80042A44(void) __asm__("func_80042A44");
void Callback21Call80043A38(int scale) __asm__("func_80043A38");
extern int D_8006FA38,D_8006C648;
extern int Callback21Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback21Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback21Values[] __asm__("D_8006FCF0");
void Callback21Call80049590(void) __asm__("func_80049590");
extern int Callback21Word8006E344 __asm__("D_8006E344");
extern int Callback21Word8006E52C __asm__("D_8006E52C");
extern int Callback21Word8006E530 __asm__("D_8006E530");
extern int Callback21Word8006E538 __asm__("D_8006E538");
void func_level_21_8008CA58(void) {
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

    switch (Callback21Player.animationState) {
    case 0x14:
        if(func_800438F4()==0)func_80043728();
        Callback21Call80041C20();
        Callback21Player.unk9a=0;
        goto call42A44;
    case 0x20:
        Callback21Call80041C20();
call42A44:
        Callback21Call80042A44();
clearSharedValue:
        Callback21Player.unk4[0]=0;
        return;
    case 0xA:
    case 0xB:
    case 0xC:
        func_800438F4();
        Callback21Call80041C20();
        Callback21Call80042A44();
        Callback21Call80041930();
        goto queryC00;
    case 0x13:
        Callback21Call80041C20();
        Callback21Call80042A44();
        Callback21Call80041930();
        goto clearSharedValue;
    case 0x19:
        Callback21Call80041C20();
        Callback21Call80042A44();
        Callback21Call80041930();
        Callback21Call80049590();
        if (Callback21Player.movementState==MOVEMENT_STATE_SUPERCHARGE && SpawnParticle!=0)
            SpawnParticle(1,9,0,0);
        if(Callback21Player.unk7a[3].z<0 && Callback21Player.animationStateFrames>=4)
            Callback21Player.unk5=1;
        else if(Callback21Player.unk5==0 && !(Callback21Word8006E538 & 0x40))
            Callback21Player.unk5=2;
        goto clearSharedValue;
    case 0x1A:
    case 0x1D:
        Callback21Call80041C20();
        Callback21Call80042A44();
queryC00:
        Callback21Call80043A38(0xC00);
        goto clearSharedValue;
    case 0x26:
    case 0x28:
    case 0x29:
    case 0x39:
        Callback21Call80041C20();
        Callback21Call80042A44();
        descriptor=&Callback21Player.unk22[2];
        if (Callback21Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback21Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setDecreasingFlag;
            tableValue=decreasingValue-0xC8;
            goto storeDecreasingValue;
            }
            goto setDecreasingFlag;
storeDecreasingValue:
            *(int*)(Callback21Values + valueOffset) = tableValue;
setDecreasingFlag:
            flagOffset = *descriptor * 0x2C;
            Callback21Flags[flagOffset] = Callback21Flags[flagOffset] | 0x10;
            __asm__ volatile("" : : : "memory");
        }
        goto clearSharedValue;
    case 0x2A:
        Callback21Call80041C20();
        Callback21Call80042A44();
        Callback21Call80049590();
        descriptor=&Callback21Player.unk22[2];
        if (Callback21Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback21Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback21Player.unk22[2];
        }
        if (Callback21Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback21Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback21Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback21Flags[flagOffset] = Callback21Flags[flagOffset] | 0x10;
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
        Callback21Call80041C20();
        Callback21Call80042A44();
        Callback21Call80041AE8();
        if ((unsigned char) Callback21Player.unk10[4] != 0) {
            computedValue = -Callback21Player.unk9ha[4] - Callback21Call80037058(Callback21Player.position.x, Callback21Player.position.y);
            positionValue = Callback21Player.unk4a - computedValue;
            Callback21Player.unk4[0] = computedValue;
            positionDelta = (int) Callback21Player.union144.a.unk13cc >> 6;
            goto storePosition;
        }
        break;
storePosition:
        positionValue -= positionDelta;
        __asm__("" : "=r"(positionValue) : "0"(positionValue));
        Callback21Player.position.z=positionValue;
        return;
    case 0x3D:
        Callback21Call80041C20();
        Callback21Call80042A44();
        Callback21Call80043A38(0xC00);
        Callback21Call80049590();
        if(SpawnParticle!=0)SpawnParticle(1,9,0,0);
        Callback21Word8006E530=120;
        Callback21Player.unk4[0]=0;
        Callback21Word8006E52C=4;
        if(Callback21Word8006E344==0 && Callback21Call8003BF6C((int)D_8006C654->supercharge,Callback21Player.unk22[2])==0) {
            Callback21Player.unk22[2]=PlaySound((int)D_8006C654->supercharge,0,4);
            Callback21Player.unk22[3]=(int)D_8006C654->supercharge;
        }
        break;
    default:
        return;
    }
}


#define LEVEL_ID 21
#define PlaySpyroSounds_level_21 func_level_21_8008CF80
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_21_8008D100(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0xa:
    case 0xb:
    case 0xc:
    case 0x14:
    case 0x1a:
    case 0x1d:
    case 0x20:
    case 0x2b:
    case 0x2c:
    case 0x3d:
        func_80043ABC(&spyro.unk9e);
        break;
    case 0x13:
        func_80043ABC(0);
        break;
    case 0x19:
        func_80043E00((Vector3D*)((char*)&spyro + 0x8C));
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008D198.
 * Reuses verified41 underwater/surface stack vectors, private0/4/8 swirl,
 * numeric21C/220/224 hurt, squish and signed-table producers. Original21 adds
 * selectorsA/B/C state10,19 state9/word130=60000,26 stateB/helper14C/98/word44=280,
 * and3D state9/vector98/wordAC=1E80/170,1FC,200 flags plus helper47138.
 * Shared descriptor call remains at the first hurt route; shared244/250 clears
 * follow3D. Numeric offsets are bytes, widths/shifts/branches are source-native.
 * Word60 FFF/801/1000 wrap/clamp inputs800/801/FFF yield0/-7FF/-1 before helpers.
 * Empty constraints emit no opcodes and retain original source lifetimes.
 * Every code/local jump/owned table word, strict complete TU and complete
 * EXE/every overlay hashes are required. Units, helper/audio meanings, caller
 * cadence and live runtime parity are open; execution is once per invocation.
 */
extern Spyro Transition21_D_80070328 __asm__("D_80070328");
int Transition21_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition21_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition21_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition21RawUnion[] __asm__("D_80070328+0x144");
extern int Transition21RawMovement __asm__("D_80070328+0x50");
extern void (*Call21Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw21State[] __asm__("D_80070328+0x50");
extern short Signed21TableA[] __asm__("D_800658A0");
extern short Signed21TableB[] __asm__("D_80065920");

extern int D_80071934;
int Call21A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw21NegativeWord __asm__("D_80070328+0x28");
extern int Raw21TableIndex __asm__("D_80070328+0x298");
extern int Raw21Yaw __asm__("D_80070328+0x64");
int Transition21_func_8003636C(int,int) __asm__("func_8003636C");
void Transition21_func_800441F0(void) __asm__("func_800441F0");
void Transition21_func_80043A38(int) __asm__("func_80043A38");
void func_80047138(void);
void func_level_21_8008D198(int arg0){
    struct {Vector3D first; int gap1; Vector3D second; int gap2; Vector3D third;} vectors;
    register int negativeWord __asm__("$3");
    int firstResult,secondResult,firstWrappedWord,secondWrappedWord,firstParticleKind,secondParticleKind,firstParticleSubtype,secondParticleSubtype;
    register Vector3D* destination __asm__("$4");

    int lengthResult;


    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* savedBase __asm__("$3");
    register int oldMovementC __asm__("$5");
    register unsigned char* privateData __asm__("$16");
    register unsigned char* stateBase __asm__("$17");
    int maskedValue;
    switch(arg0){
    case 0x14:
        Transition21_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition21_D_80070328.unk5 = 0;
        Transition21_func_800441F0();
        Transition21_D_80070328.grounded = 1;
        Transition21_D_80070328.union144.a.unk13cb = Transition21_func_8003636C(1, 3);
        Transition21_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0xA:
    case 0xB:
    case 0xC:
        Transition21_D_80070328.movementState = MOVEMENT_STATE_ICE_SKATE;
        Transition21_D_80070328.unk5 = 0;
        Transition21_D_80070328.unk8[0] = Transition21_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition21_D_80070328.movementState + 0x48), 0);
        Transition21_func_80043A38(0xC00);
        Transition21_D_80070328.grounded = 1;
        goto clearPointers;
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        stateBase=(unsigned char*)&Transition21RawMovement;
        privateData = Transition21_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition21_D_80070328.unk5 = 0;
        Transition21_D_80070328.grounded = 0;
        Transition21_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition21_D_80070328.m_WhirlwindPointer;
        yawValue=Transition21_D_80070328.rotation.yaw;
        positionZ=Transition21_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition21_D_80070328.union144.a.unk13cc=yawValue;
        Transition21_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition21_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition21_D_80070328.union144.a.unk13ce.z=heightValue;
        __asm__ volatile("" : : : "memory");
        heightValue = ((int) (heightValue << 0xA) >> 0xA) + 0x400;
        __asm__("" : "=r"(heightValue) : "0"(heightValue));
        Transition21_D_80070328.union144.a.unk13ce.y = heightValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
        Transition21_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition21_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition21_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition21_D_80070328.unk13e[0] = (int) Transition21_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition21_D_80070328.unk20a = 0;
        Transition21_D_80070328.critterMobyPtr = 0;
        Transition21_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x1D: {
        register int oldState __asm__("$4")=Transition21RawMovement;
        register int first __asm__("$3")=Transition21_D_80070328.unk17e.x;
        register int second __asm__("$2");
        register int third __asm__("$3");
        __asm__("" : "=r"(oldState),"=r"(first) : "0"(oldState),"1"(first) : "memory");
        second=7;
        __asm__("" : "=r"(second) : "0"(second));
        Transition21RawMovement=second;
        __asm__ volatile("" : : : "memory");
        second=Transition21_D_80070328.unk17e.y;
        __asm__ volatile("" : "=r"(second) : "0"(second) : "memory");
        Transition21_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(first) : "0"(first) : "memory");
        first<<=6;
        __asm__("" : "=r"(first) : "0"(first));
        Transition21_D_80070328.unk7a[2].x=first;
        __asm__ volatile("" : : : "memory");
        third=Transition21_D_80070328.unk17e.z;
        second<<=6;
        Transition21_D_80070328.union144.a.unk13cb=oldState;
        Transition21_D_80070328.unk7a[2].y=second;
        second=third<<6;
        if(third==0)second=Transition21_D_80070328.unk7a[3].z;
        Transition21_D_80070328.unk7a[2].z=second;
        Transition21_func_80043A38(0xC00);
        Transition21_D_80070328.grounded=1;
        Transition21_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        soundSelector=D_8006C654->spyroHurt;
        soundZero=0;
sharedSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
        goto clearPointers;
    }

    case 0x19:
        Transition21_D_80070328.movementState = MOVEMENT_STATE_SUPERCHARGE;
        Transition21_D_80070328.unk13a[0] = 0x60000;
        Transition21_D_80070328.unk5 = 0;
        Transition21_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition21_D_80070328.grounded = 0;
        Transition21_D_80070328.unk15b = 1;
        soundSelector=D_8006C654->jump;
        soundZero=0;
        goto sharedSound;
    case 0x1A:
        savedBase = Transition21RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        oldMovementC = Transition21RawMovement;
        Transition21RawMovement = MOVEMENT_STATE_HURT;
        Transition21_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementC;
        Transition21_func_8004F168(destination);
        Transition21_D_80070328.grounded = 1;
        Transition21_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        soundSelector=D_8006C654->squish;
        soundZero=0;
        goto sharedSound;
    case 0x20:
        Transition21_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition21_D_80070328.unk5 = 0;
        Transition21_func_80043A38(0xC00);
        Transition21_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition21_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x26:
        Transition21_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        if (Transition21_D_80070328.animationState == 0x2A) {
            Transition21_D_80070328.unk5 = 2;
        }
        Transition21_func_8004F168((Vector3D *) ((unsigned char*)&Transition21_D_80070328.movementState + 0xFC));
        Transition21_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition21_D_80070328.unk8[0] = Transition21_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition21_D_80070328.movementState + 0x48), 0);
        Transition21_D_80070328.grounded = 1;
        Transition21_D_80070328.unk4a = 0x280;
        return;
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition21_D_80070328.movementState - 0xB) >= 2U) && (Transition21_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition21_D_80070328.movementState - 0x50));
                if ((Transition21_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw21NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition21_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call21A358(&vectors.first, 0x800);
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
            firstWrappedWord = Transition21_D_80070328.rotation.pitch & 0xFFF;
            Transition21_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition21_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition21_D_80070328.rotation.pitch > 0) {
                Transition21_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition21_D_80070328.unk5 = 1;
            }
            Transition21_func_8004F168((Vector3D *) ((unsigned char*)&Transition21_D_80070328.rotation.pitch + 0xEC));
            Transition21_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition21_D_80070328.unk8[0] = Transition21_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition21_D_80070328.rotation.pitch + 0x38), 0);
            Transition21_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition21_D_80070328.animationState == 0x2A) {
            Transition21_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition21_D_80070328.union144.a.unk13da = 0;
        }
        Transition21_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition21_D_80070328.unk20a = 0;
        Transition21_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw21State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw21NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition21_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call21A358(localVector, 0x800);
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
            if (Transition21_D_80070328.animationState == 0x2E) {
                Transition21_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition21_D_80070328.rotation.pitch & 0xFFF;
            Transition21_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition21_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition21_D_80070328.rotation.pitch > 0) {
                Transition21_D_80070328.rotation.pitch = 0;
            }
            Transition21_D_80070328.unk5 = 1;
            Transition21_func_8004F168((Vector3D *) ((unsigned char*)&Transition21_D_80070328.animationState + 0x104));
            Transition21_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition21_D_80070328.unk8[0] = Transition21_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition21_D_80070328.animationState + 0x50), 0);
            Transition21_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition21_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition21_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition21RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition21RawUnion;
            *(int*)unionPointer=(-Transition21_D_80070328.unk7a[2].z)>>2;
            if(Transition21RawMovement!=8){Transition21_D_80070328.union144.a.unk13cc=0x5900;Transition21RawMovement=10;}
            Transition21_D_80070328.unk5=0;
            Transition21_D_80070328.unk8[0]=Transition21_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition21_D_80070328.grounded=1;
            Transition21_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call21A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x39: {
        register int previousMovement __asm__("$2")=Transition21RawMovement;
        register int numericKind __asm__("$3");
        register int indexWord __asm__("$3");
        register unsigned char* unionPointer __asm__("$5");
        register int tableOffset __asm__("$2");
        register int tableWord __asm__("$3");
        __asm__("" : "=r"(previousMovement) : "0"(previousMovement));
        numericKind=7;
        __asm__("" : "=r"(numericKind) : "0"(numericKind));
        Transition21RawMovement=numericKind;
        __asm__ volatile("" : : : "memory");
        indexWord=Raw21TableIndex;
        __asm__ volatile("" : "=r"(indexWord) : "0"(indexWord) : "memory");
        unionPointer=Transition21RawUnion;
        __asm__("" : "=r"(indexWord),"=r"(unionPointer) : "0"(indexWord),"1"(unionPointer) : "memory");
        Transition21_D_80070328.unk5=0;
        *(int*)unionPointer=previousMovement;
        if(indexWord<0)Raw21TableIndex=((Raw21Yaw+0x800)>>4)&0xFF;
        tableOffset=Raw21TableIndex*2;
        tableWord=*(short*)((unsigned char*)Signed21TableB+tableOffset);
        destination=(Vector3D*)(unionPointer-0xC4);
        *(int*)(unionPointer-0xB8)=tableWord;
        tableOffset=*(short*)((unsigned char*)Signed21TableA+tableOffset);
        Transition21_D_80070328.unk7a[2].z=0;
        Transition21_D_80070328.unk7a[2].y=tableOffset;
        func_8004F178(destination,(Vector3D*)(unionPointer-0xB8));
        Transition21_D_80070328.grounded=1;
        Transition21_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        soundSelector=D_8006C654->underwaterHit;
        soundZero=0;
        goto sharedSound;
    }
    case 0x3D:
        Transition21_D_80070328.movementState = MOVEMENT_STATE_SUPERCHARGE;
        Transition21_D_80070328.unk5 = 0;
        Transition21_D_80070328.unk13a[0] = 0x60000;
        Transition21_D_80070328.unk8[0] = Transition21_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition21_D_80070328.movementState + 0x48), 0);
        Transition21_D_80070328.horizontalSpeed = 0x1E80;
        Transition21_func_80043A38(0xC00);
        Transition21_D_80070328.grounded = 1;
        if ((Transition21_D_80070328.unk13f[0] != 0) || (Transition21_D_80070328.spitState != 0) || (Transition21_D_80070328.unk17t != 6)) {
            if (((unsigned) (Transition21_D_80070328.unk13f[0] - 3) < 2U) || (Transition21_D_80070328.unk13f[0] == 5)) {
                Transition21_D_80070328.unk13f[0] = 5;
            } else {
                Transition21_D_80070328.unk13f[0] = 0;
            }
            Transition21_D_80070328.spitState = 0;
            Transition21_D_80070328.unk17t = 6;
            func_80047138();
        }
clearPointers:
        Transition21_D_80070328.unk20a=0;
        Transition21_D_80070328.critterMobyPtr=0;
        return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_21/animation", func_level_21_8008DCD4);
