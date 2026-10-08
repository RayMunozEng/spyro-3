#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_37/animation", func_level_37_80088AD4);

/* AI generated; not human reviewed. SCUS-94467 80089C1C..8008A0D8.
 * Verified30/44 scalar/table code reused only against original37 instructions.
 * Original37 supplies selector scope and independent table tails; meanings,
 * units and cadence remain unresolved. The first shared call/clear block follows
 * original80089C80..80089CA4. Empty memory boundary after first table flag
 * store retains original independent table tails without emitting instructions.
 * All original words, strict full translation unit and retail hashes required.
 */
extern int Callback37Step __asm__("D_80070328+0x144");
extern int Callback37Z __asm__("D_80070328+8");
extern int Callback37Limit __asm__("D_80070328+0x280");
extern Spyro Callback37Player __asm__("D_80070328");
int Callback37Call80037058(int x, int y) __asm__("func_80037058");
int Callback37Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback37Call80041930(void) __asm__("func_80041930");
void Callback37Call80041AE8(void) __asm__("func_80041AE8");
void Callback37Call80041C20(void) __asm__("func_80041C20");
void Callback37Call80042A44(void) __asm__("func_80042A44");
void Callback37Call80043A38(int scale) __asm__("func_80043A38");
extern int D_8006FA38,D_8006C648;
int Callback37Query(Vector3D*,int) __asm__("func_8001A358");
extern int Callback37Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback37Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback37Values[] __asm__("D_8006FCF0");
void Callback37Call80049590(void) __asm__("func_80049590");
void func_level_37_80089C1C(void) {
    struct {Vector3D first; int reserved1C;} local;
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

    switch (Callback37Player.animationState) {
    case 0x14:
        if(func_800438F4()==0)func_80043728();
        Callback37Call80041C20();
        Callback37Player.unk9a=0;
        goto call42A44;
    case 0x35:
    case 0x36:
        Callback37Call80041C20();
call42A44:
        Callback37Call80042A44();
clearSharedValue:
        Callback37Player.unk4[0]=0;
        return;
    case 0x1D:
        Callback37Call80041C20();
        Callback37Call80042A44();
        Callback37Call80043A38(0xC00);
        goto clearSharedValue;
    case 0x1C:
        Callback37Call80041C20();
        Callback37Call80042A44();
        Callback37Call80041930();
        if (Callback37Player.unk7a[3].z < 0 && Callback37Player.animationStateFrames >= 4)
            Callback37Player.unk5=1;
        goto clearSharedValue;
        case 0x1E: {
            register int* zWord __asm__("$5")=&Callback37Z;
            register int velocity __asm__("$6")=Callback37Step;
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
            status=Callback37Limit;
            velocity+=tick;
            Callback37Step=velocity;
            __asm__("" : : : "memory");
            if(status>=0 && D_8006FA38<0)goto lowerLimit;
            {
                register int limit __asm__("$3")=0x9000;
                register int exceeded __asm__("$2");
                __asm__("" : "=r"(limit) : "0"(limit));
                exceeded=limit<velocity;
                if(exceeded)Callback37Step=limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2")=velocity<0x2581;
                if(!below)Callback37Step=0x2580;
            }
        limitsDone:
            Callback37Call80041C20();
            Callback37Call80042A44();
            func_8004F178(&local.first,&Callback37Player.position);
            local.first.z+=0x400;
            Callback37Player.unk4[0]=Callback37Query(&local.first,0xC00);
            positionDelta=(int)Callback37Player.union144.a.unk13cb;
            positionValue=Callback37Player.position.z;
            positionDelta >>= 6;
            goto storePosition;
        }
    case 0x28:
    case 0x29:
        Callback37Call80041C20();
        Callback37Call80042A44();
        descriptor=&Callback37Player.unk22[2];
        if (Callback37Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback37Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setDecreasingFlag;
            tableValue=decreasingValue-0xC8;
            goto storeDecreasingValue;
            }
            goto setDecreasingFlag;
storeDecreasingValue:
            *(int*)(Callback37Values + valueOffset) = tableValue;
setDecreasingFlag:
            flagOffset = *descriptor * 0x2C;
            Callback37Flags[flagOffset] = Callback37Flags[flagOffset] | 0x10;
            __asm__ volatile("" : : : "memory");
        }
        goto clearSharedValue;
    case 0x2A:
        Callback37Call80041C20();
        Callback37Call80042A44();
        Callback37Call80049590();
        descriptor=&Callback37Player.unk22[2];
        if (Callback37Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback37Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback37Player.unk22[2];
        }
        if (Callback37Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback37Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback37Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback37Flags[flagOffset] = Callback37Flags[flagOffset] | 0x10;
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
        Callback37Call80041C20();
        Callback37Call80042A44();
        Callback37Call80041AE8();
        if ((unsigned char) Callback37Player.unk10[4] != 0) {
            computedValue = -Callback37Player.unk9ha[4] - Callback37Call80037058(Callback37Player.position.x, Callback37Player.position.y);
            positionValue = Callback37Player.unk4a - computedValue;
            Callback37Player.unk4[0] = computedValue;
            positionDelta = (int) Callback37Player.union144.a.unk13cc >> 6;
            goto storePosition;
        }
        break;
storePosition:
        positionValue -= positionDelta;
        __asm__("" : "=r"(positionValue) : "0"(positionValue));
        Callback37Player.position.z=positionValue;
        return;
    case 0x3A:
        Callback37Call80041C20();
        Callback37Call80042A44();
        Callback37Player.cheatColour.a=0xFF;
        Callback37Player.unk4[0]=0;
        Callback37Player.cheatColour.b=0x20;
        Callback37Player.cheatColour.g=0x20;
        Callback37Player.cheatColour.r=0x20;
        break;
    default:
        return;
    }
}


#define LEVEL_ID 37
#define PlaySpyroSounds_level_37 func_level_37_8008A0DC
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_37_8008A218(int index) {
    Vector3D* position;
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x14: case 0x1d: case 0x1e: case 0x2b: case 0x2c: case 0x35: case 0x36: case 0x3a: position = &spyro.unk9e; break;
    case 0x1c: position = 0; break;
    case 0x15: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1f: case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2d: case 0x2e: case 0x2f: case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x37: case 0x38: case 0x39: return;
    default: return;
    }
    func_80043ABC(position);
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008A294.
 * Reuses verified21 stack10/20/30 underwater/surface and numeric1D producers,
 * verified33 numeric1C vector/DC0/damage200 and drowning callback lifetimes.
 * Original37 retains independent descriptor15 call, clears244/250 before290
 * in selector1E, and shared35/36 stand. Offsets are bytes; widths and shifts
 * are original. Word60 wrap/clamp vectors800/801/FFF yield0/-7FF/-1.
 * Empty constraints preserve original register lifetimes and emit no opcodes.
 * Require every code/internal jump/owned dispatch word and complete retail
 * hashes. Helper/audio semantics, units, cadence and live parity remain open.
 */
extern Spyro Transition37_D_80070328 __asm__("D_80070328");
int Transition37_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition37_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition37_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition37RawUnion[] __asm__("D_80070328+0x144");
extern int Transition37RawMovement __asm__("D_80070328+0x50");
extern void (*Call37Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw37State[] __asm__("D_80070328+0x50");

extern int D_80071934;
int Call37A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw37NegativeWord __asm__("D_80070328+0x28");
int Transition37_func_8003636C(int,int) __asm__("func_8003636C");
void Transition37_func_800441F0(void) __asm__("func_800441F0");
void Transition37_func_80043A38(int) __asm__("func_80043A38");
void func_80047138(void);
void func_level_37_8008A294(int arg0){
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
    switch(arg0){
    case 0x14:
        Transition37_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition37_D_80070328.unk5 = 0;
        Transition37_func_800441F0();
        Transition37_D_80070328.grounded = 1;
        Transition37_D_80070328.union144.a.unk13cb = Transition37_func_8003636C(1, 3);
        Transition37_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x1D: {
        register int oldState __asm__("$4")=Transition37RawMovement;
        register int first __asm__("$3")=Transition37_D_80070328.unk17e.x;
        register int second __asm__("$2");
        register int third __asm__("$3");
        __asm__("" : "=r"(oldState),"=r"(first) : "0"(oldState),"1"(first) : "memory");
        second=7;
        __asm__("" : "=r"(second) : "0"(second));
        Transition37RawMovement=second;
        __asm__ volatile("" : : : "memory");
        second=Transition37_D_80070328.unk17e.y;
        __asm__ volatile("" : "=r"(second) : "0"(second) : "memory");
        Transition37_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(first) : "0"(first) : "memory");
        first<<=6;
        __asm__("" : "=r"(first) : "0"(first));
        Transition37_D_80070328.unk7a[2].x=first;
        __asm__ volatile("" : : : "memory");
        third=Transition37_D_80070328.unk17e.z;
        second<<=6;
        Transition37_D_80070328.union144.a.unk13cb=oldState;
        Transition37_D_80070328.unk7a[2].y=second;
        second=third<<6;
        if(third==0)second=Transition37_D_80070328.unk7a[3].z;
        Transition37_D_80070328.unk7a[2].z=second;
        Transition37_func_80043A38(0xC00);
        Transition37_D_80070328.grounded=1;
        Transition37_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        soundSelector=D_8006C654->spyroHurt;
        soundZero=0;
        PlaySound(soundSelector,(Moby*)soundZero,0);
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    }

    case 0x1C:
        savedBase = Transition37RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Transition37RawMovement;
        Transition37RawMovement = MOVEMENT_STATE_HURT;
        Transition37_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Transition37_D_80070328.unk8[0] = Transition37_func_8004EDE8(sourceC, 0);
        Transition37_D_80070328.unk7a[2].z = 0xDC0;
        Transition37_D_80070328.grounded = 0;
        Transition37_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Transition37_D_80070328.damageFlags & 0x200) {
            Transition37_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition37_D_80070328.union144.a.unk13cc = 1;
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        goto clearPointers;
    case 0x1E: {
        register int oldState __asm__("$3")=Transition37RawMovement;
        register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$8")=SpawnParticle;
        register int* stateWord __asm__("$2");
        register int value __asm__("$2");
        __asm__ volatile("" : "=r"(oldState), "=r"(callback) : "0"(oldState), "1"(callback) : "memory");
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Transition37RawMovement=value;
        value=1;
        __asm__("" : "=r"(value) : "0"(value));
        Transition37_D_80070328.grounded=value;
        value=15;
        __asm__("" : "=r"(value) : "0"(value));
        Transition37_D_8006E524=value;
        stateWord=(int*)Transition37RawUnion;
        __asm__("" : "=r"(stateWord) : "0"(stateWord));
        Transition37_D_80070328.unk5=0;
        *stateWord=oldState;
        __asm__ volatile("" : : : "memory");
        *stateWord=0;
        if(callback)callback(5,10,0,0);
        Transition37_D_80070328.unk22[2]=PlaySound((int)D_8006C654->drown,0,0);
        value=(int)D_8006C654->drown;
        __asm__ volatile("" : "=r"(value) : "0"(value) : "memory");
        Transition37_D_80070328.unk20a=0;
        Transition37_D_80070328.critterMobyPtr=0;
        Transition37_D_80070328.unk22[3]=value;
        return;
    }
    case 0x3A:
        Transition37_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition37_D_80070328.unk5 = 0;
        Transition37_func_80043A38(0xC00);
        Transition37_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition37_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition37_D_80070328.movementState - 0xB) >= 2U) && (Transition37_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition37_D_80070328.movementState - 0x50));
                if ((Transition37_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw37NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition37_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call37A358(&vectors.first, 0x800);
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
            firstWrappedWord = Transition37_D_80070328.rotation.pitch & 0xFFF;
            Transition37_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition37_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition37_D_80070328.rotation.pitch > 0) {
                Transition37_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition37_D_80070328.unk5 = 1;
            }
            Transition37_func_8004F168((Vector3D *) ((unsigned char*)&Transition37_D_80070328.rotation.pitch + 0xEC));
            Transition37_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition37_D_80070328.unk8[0] = Transition37_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition37_D_80070328.rotation.pitch + 0x38), 0);
            Transition37_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition37_D_80070328.animationState == 0x2A) {
            Transition37_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition37_D_80070328.union144.a.unk13da = 0;
        }
        Transition37_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition37_D_80070328.unk20a = 0;
        Transition37_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw37State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw37NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition37_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call37A358(localVector, 0x800);
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
            if (Transition37_D_80070328.animationState == 0x2E) {
                Transition37_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition37_D_80070328.rotation.pitch & 0xFFF;
            Transition37_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition37_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition37_D_80070328.rotation.pitch > 0) {
                Transition37_D_80070328.rotation.pitch = 0;
            }
            Transition37_D_80070328.unk5 = 1;
            Transition37_func_8004F168((Vector3D *) ((unsigned char*)&Transition37_D_80070328.animationState + 0x104));
            Transition37_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition37_D_80070328.unk8[0] = Transition37_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition37_D_80070328.animationState + 0x50), 0);
            Transition37_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition37_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition37_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition37RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition37RawUnion;
            *(int*)unionPointer=(-Transition37_D_80070328.unk7a[2].z)>>2;
            if(Transition37RawMovement!=8){Transition37_D_80070328.union144.a.unk13cc=0x5900;Transition37RawMovement=10;}
            Transition37_D_80070328.unk5=0;
            Transition37_D_80070328.unk8[0]=Transition37_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition37_D_80070328.grounded=1;
            Transition37_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call37A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x35:
    case 0x36:
        Transition37_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition37_D_80070328.unk5 = 0;
        Transition37_func_800441F0();
        Transition37_D_80070328.grounded = 1;
clearPointers:
        Transition37_D_80070328.unk20a=0;
        Transition37_D_80070328.critterMobyPtr=0;
        return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_37/animation", func_level_37_8008AB0C);
