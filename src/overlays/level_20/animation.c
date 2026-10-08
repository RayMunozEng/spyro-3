#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_20/animation", func_level_20_800895A0);

/* AI generated; not human reviewed. SCUS-94467 8008A804..8008AC80.
 * Verified37 independent table tails and43 clamp producers reused against
 * original20 selectors and independent case2B store. Numeric byte accesses
 * establish no helper meanings, units/cadence. Original20 frame18 has no
 * local vector. Table8006FCF0/8006FCE6 stride44 and numeric200/5096 limits
 * plus signed division1536 match original words, not inferred semantics.
 * All words, strict full TU and every retail EXE/overlay hash required.
 */
extern Spyro Callback20Player __asm__("D_80070328");
int Callback20Call80037058(int x, int y) __asm__("func_80037058");
int Callback20Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback20Call80041930(void) __asm__("func_80041930");
void Callback20Call80041AE8(void) __asm__("func_80041AE8");
void Callback20Call80041C20(void) __asm__("func_80041C20");
void Callback20Call80042A44(void) __asm__("func_80042A44");
void Callback20Call80043A38(int scale) __asm__("func_80043A38");
extern int D_8006FA38,D_8006C648;
extern int Callback20Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback20Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback20Values[] __asm__("D_8006FCF0");
void Callback20Call80049590(void) __asm__("func_80049590");
int Callback20Length(Vector3D*,int) __asm__("func_8004EDE8");
void func_level_20_8008A804(void) {
    register int computedValue __asm__("$4");
    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    int descriptorResult;
    int flagOffset;

    register int clampedValue __asm__("$4");
    register int positionDelta __asm__("$2");
    register int numerator __asm__("$2");
    register int belowLimit __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback20Player.animationState) {
    case 0x14:
        if(func_800438F4()==0)func_80043728();
        Callback20Call80041C20();
        Callback20Player.unk9a=0;
        goto call42A44;
    case 0x35:
    case 0x36:
        Callback20Call80041C20();
call42A44:
        Callback20Call80042A44();
clearSharedValue:
        Callback20Player.unk4[0]=0;
        return;
    case 0xA:
    case 0xB:
    case 0xC:
        func_800438F4();
        Callback20Call80041C20();
        Callback20Call80042A44();
        Callback20Call80041930();
        Callback20Call80043A38(0xC00);
        goto clearSharedValue;
    case 0x26:
    case 0x28:
    case 0x29:
        Callback20Call80041C20();
        Callback20Call80042A44();
        descriptor=&Callback20Player.unk22[2];
        if (Callback20Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback20Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setDecreasingFlag;
            tableValue=decreasingValue-0xC8;
            goto storeDecreasingValue;
            }
            goto setDecreasingFlag;
storeDecreasingValue:
            *(int*)(Callback20Values + valueOffset) = tableValue;
setDecreasingFlag:
            flagOffset = *descriptor * 0x2C;
            Callback20Flags[flagOffset] = Callback20Flags[flagOffset] | 0x10;
            __asm__ volatile("" : : : "memory");
        }
        goto clearSharedValue;
    case 0x2A:
        Callback20Call80041C20();
        Callback20Call80042A44();
        Callback20Call80049590();
        descriptor=&Callback20Player.unk22[2];
        if (Callback20Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback20Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback20Player.unk22[2];
        }
        if (Callback20Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback20Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback20Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback20Flags[flagOffset] = Callback20Flags[flagOffset] | 0x10;
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
        Callback20Call80041C20();
        Callback20Call80042A44();
        Callback20Call80041AE8();
        if ((unsigned char) Callback20Player.unk10[4] != 0) {
            computedValue = -Callback20Player.unk9ha[4] - Callback20Call80037058(Callback20Player.position.x, Callback20Player.position.y);
            positionValue = Callback20Player.unk4a - computedValue;
            Callback20Player.unk4[0] = computedValue;
            positionDelta = (int) Callback20Player.union144.a.unk13cc >> 6;
            goto storePosition;
        }
        break;
storePosition:
        positionValue -= positionDelta;
        __asm__("" : "=r"(positionValue) : "0"(positionValue));
        Callback20Player.position.z=positionValue;
        return;
    case 0x2F:
        Callback20Call80041C20();
        Callback20Call80042A44();
        Callback20Call80041930();
        func_80042F64();
        goto clearSharedValue;
    case 0x32:
        Callback20Call80041C20();
        Callback20Call80042A44();
        Callback20Call80041930();
        func_80042F64();
        numerator=(int)((unsigned int)Callback20Player.unk7a[3].z << 2);
        Callback20Player.unk4[0] = 0;
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
        Callback20Call80041C20();
        Callback20Call80042A44();
        Callback20Call80041930();
        func_80042F64();
        Callback20Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)(((unsigned int)Callback20Length((Vector3D *) ((unsigned char*)Callback20Player.unk4 + 0x70), 0) << 2) + 0x300U) / 1536;
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
    default:
        return;
    }
}


#define LEVEL_ID 20
#define PlaySpyroSounds_level_20 func_level_20_8008AC84
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_20_8008AED4(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0xa:
    case 0xb:
    case 0xc:
    case 0x14:
    case 0x2b:
    case 0x2c:
    case 0x35:
    case 0x36:
        func_80043ABC(&spyro.unk9e);
        break;
    case 0x2f:
    case 0x32:
    case 0x33:
    case 0x34:
        func_80043F3C(&spyro.unk9h);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008AF5C.
 * Reuses verified37 underwater/surface vectors, verified34 independent ladders
 * and shared grounded tail, verified21 state10 ice and stateB helper14C/98.
 * Original20 retains scalar44=280 and shared244/250 clears. Word60 FFF wrap,
 * signed801 boundary and positive clamp:800/801/FFF yield0/-7FF/-1 before helpers.
 * Numeric offsets are bytes; original widths, shifts and branches are retained.
 * Empty constraints preserve lifetimes without emitting instructions. Acceptance
 * requires all code/internal jumps/owned tables and complete retail binary hashes.
 * Helper/audio semantics, units, cadence and live runtime parity remain open.
 */
extern Spyro Transition20_D_80070328 __asm__("D_80070328");
int Transition20_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition20_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern unsigned char Transition20RawUnion[] __asm__("D_80070328+0x144");
extern int Transition20RawMovement __asm__("D_80070328+0x50");
extern void (*Call20Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw20State[] __asm__("D_80070328+0x50");

extern int D_80071934;
int Call20A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw20NegativeWord __asm__("D_80070328+0x28");
int Transition20_func_8003636C(int,int) __asm__("func_8003636C");
void Transition20_func_800441F0(void) __asm__("func_800441F0");
void Transition20_func_80043A38(int) __asm__("func_80043A38");
void func_80047138(void);
void func_level_20_8008AF5C(int arg0){
    struct {Vector3D first; int gap1; Vector3D second; int gap2; Vector3D third;} vectors;
    register int negativeWord __asm__("$3");
    int firstResult,secondResult,firstWrappedWord,secondWrappedWord,firstParticleKind,secondParticleKind,firstParticleSubtype,secondParticleSubtype;
    register Vector3D* destination __asm__("$4");

    int lengthResult;


    register unsigned char* savedBase __asm__("$3");
    switch(arg0){
    case 0x14:
        Transition20_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition20_D_80070328.unk5 = 0;
        Transition20_func_800441F0();
        Transition20_D_80070328.grounded = 1;
        Transition20_D_80070328.union144.a.unk13cb = Transition20_func_8003636C(1, 3);
        Transition20_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0xA:case 0xB:case 0xC: {
        register unsigned char* state __asm__("$2")=Raw20State;
        register int kind __asm__("$3");
        destination=(Vector3D*)(state+0x48);
        __asm__("" : "=r"(destination) : "0"(destination));
        kind=16;
        __asm__("" : "=r"(kind) : "0"(kind));
        *(int*)state=kind;
        Transition20_D_80070328.unk5=0;
        Transition20_D_80070328.unk8[0]=Transition20_func_8004EDE8(destination,0);
        Transition20_func_80043A38(0xC00);
        goto setGrounded;
    }
    case 0x26:
        Transition20_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        if (Transition20_D_80070328.animationState == 0x2A) {
            Transition20_D_80070328.unk5 = 2;
        }
        Transition20_func_8004F168((Vector3D *) ((unsigned char*)&Transition20_D_80070328.movementState + 0xFC));
        Transition20_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition20_D_80070328.unk8[0] = Transition20_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition20_D_80070328.movementState + 0x48), 0);
        Transition20_D_80070328.grounded = 1;
        Transition20_D_80070328.unk4a = 0x280;
        return;
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition20_D_80070328.movementState - 0xB) >= 2U) && (Transition20_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition20_D_80070328.movementState - 0x50));
                if ((Transition20_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw20NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition20_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call20A358(&vectors.first, 0x800);
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
            firstWrappedWord = Transition20_D_80070328.rotation.pitch & 0xFFF;
            Transition20_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition20_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition20_D_80070328.rotation.pitch > 0) {
                Transition20_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition20_D_80070328.unk5 = 1;
            }
            Transition20_func_8004F168((Vector3D *) ((unsigned char*)&Transition20_D_80070328.rotation.pitch + 0xEC));
            Transition20_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition20_D_80070328.unk8[0] = Transition20_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition20_D_80070328.rotation.pitch + 0x38), 0);
            Transition20_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition20_D_80070328.animationState == 0x2A) {
            Transition20_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition20_D_80070328.union144.a.unk13da = 0;
        }
        Transition20_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition20_D_80070328.unk20a = 0;
        Transition20_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw20State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw20NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition20_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call20A358(localVector, 0x800);
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
            if (Transition20_D_80070328.animationState == 0x2E) {
                Transition20_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition20_D_80070328.rotation.pitch & 0xFFF;
            Transition20_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition20_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition20_D_80070328.rotation.pitch > 0) {
                Transition20_D_80070328.rotation.pitch = 0;
            }
            Transition20_D_80070328.unk5 = 1;
            Transition20_func_8004F168((Vector3D *) ((unsigned char*)&Transition20_D_80070328.animationState + 0x104));
            Transition20_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition20_D_80070328.unk8[0] = Transition20_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition20_D_80070328.animationState + 0x50), 0);
            Transition20_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition20_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition20_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition20RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition20RawUnion;
            *(int*)unionPointer=(-Transition20_D_80070328.unk7a[2].z)>>2;
            if(Transition20RawMovement!=8){Transition20_D_80070328.union144.a.unk13cc=0x5900;Transition20RawMovement=10;}
            Transition20_D_80070328.unk5=0;
            Transition20_D_80070328.unk8[0]=Transition20_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition20_D_80070328.grounded=1;
            Transition20_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call20A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x2F:
        savedBase=(unsigned char*)&Transition20RawMovement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition20_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            __asm__ volatile("" : : : "memory");
            goto setGrounded;
        }
        goto clearPointers;
    case 0x32:case 0x33:case 0x34:
        savedBase=(unsigned char*)&Transition20RawMovement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition20_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            goto setGrounded;
        }
        goto clearPointers;
    case 0x35:
    case 0x36:
        Transition20_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition20_D_80070328.unk5 = 0;
        Transition20_func_800441F0();
setGrounded:
        Transition20_D_80070328.grounded = 1;
clearPointers:
        Transition20_D_80070328.unk20a=0;
        Transition20_D_80070328.critterMobyPtr=0;
        return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_20/animation", func_level_20_8008B628);
