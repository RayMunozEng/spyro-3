#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_10/animation", func_level_10_800881FC);

/* AI generated; not human reviewed. SCUS-94467 800897A4..80089B98.
 * Verified37 independent table and50 particle routes adapted to original10
 * standalone stack10 vector, saved countS1/sourceS2 and original selector scope.
 * Original10 retains frame38 with two reserved stack words; their source
 * meaning is unknown and no accesses are invented. Source148-B0 and-98 are
 * byte offsets. Final callbackV0/store-delay words independently agree.
 * Units/helpers/cadence unresolved. All original words, strict full TU and
 * every retail hash required; compiled equality is not runtime parity.
 */
extern Spyro Callback10Player __asm__("D_80070328");
int Callback10Call80037058(int x, int y) __asm__("func_80037058");
int Callback10Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback10Call80041930(void) __asm__("func_80041930");
void Callback10Call80041AE8(void) __asm__("func_80041AE8");
void Callback10Call80041C20(void) __asm__("func_80041C20");
void Callback10Call80042A44(void) __asm__("func_80042A44");
extern int D_8006FA38,D_8006C648;
extern int Callback10Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback10Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback10Values[] __asm__("D_8006FCF0");
void Callback10Call80049590(void) __asm__("func_80049590");
extern short Callback10Count __asm__("D_80070328+0x148");
void Callback10Call8004F110(Vector3D*,int) __asm__("func_8004F110");
void func_level_10_800897A4(void) {
    Vector3D localVector;
    int reservedStackWords[2];
    register int computedValue __asm__("$4");
    register unsigned char* countBase __asm__("$5");
    register unsigned char* sourceBytes __asm__("$18");
    register int iteration __asm__("$16");
    register int secondLimit __asm__("$17");
    register int sample __asm__("$2");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    register char* (*particles)(int,int,Vector3D*,Vector3D*) __asm__("$2");
    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    int descriptorResult;
    int flagOffset;

    register int positionDelta __asm__("$2");
    register int positionValue __asm__("$3");

    switch(Callback10Player.animationState) {
    case 0x13:
        Callback10Call80041C20();
        Callback10Call80042A44();
        Callback10Call80041930();
clearSharedValue:
        Callback10Player.unk4[0]=0;
        return;
        case 0x21:
        case 0x22:
        case 0x23:
            Callback10Call80041C20();
            Callback10Call80042A44();
            Callback10Call80041930();
            if (SpawnParticle != 0) {
                countBase=(unsigned char*)&Callback10Count;
                if (*(short*)countBase == 0) goto clearSharedValue;
                secondLimit = 1;
                if (*(short*)countBase >= 2) {
                    secondLimit = 2;
                }
                iteration = 0;
                if (secondLimit != 0) {
                    __asm__("" : "=r"(countBase) : "0"(countBase));
                    sourceBytes=countBase-0xB0;
                    do {
                        func_8004F178((&localVector), (Vector3D *) sourceBytes);
                        Callback10Call8004F110((&localVector), 7);
                        iteration += 1;
                        sample=rand();
                        component=localVector.x;
                        sample &= 254;
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        localVector.x=component;
                        sample=rand();
                        component=localVector.y;
                        sample &= 254;
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        localVector.y=component;
                        sample=rand();
                        kind=1;
                        subtype=0x17;
                        position=sourceBytes - 0x98;
                        __asm__("" : "=r"(kind), "=r"(subtype), "=r"(position) : "0"(kind), "1"(subtype), "2"(position), "r"(sample) : "$3", "memory");
                        component=localVector.z;
                        __asm__("" : "=r"(component) : "0"(component), "r"(sample));
                        sample &=254;
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component) : "$2", "memory");
                        particles=SpawnParticle;
                        __asm__ volatile("" : "=r"(particles) : "0"(particles) : "$7");
                        vector=(&localVector);
                        __asm__("" : "=r"(particles), "=r"(vector), "=r"(component) : "0"(particles), "1"(vector), "2"(component));
                        localVector.z=component;
                        particles(kind,subtype,(Vector3D*)position,vector);
                    } while (iteration < secondLimit);
                }
            }
            goto clearSharedValue;
    case 0x28:
    case 0x29:
        Callback10Call80041C20();
        Callback10Call80042A44();
        descriptor=&Callback10Player.unk22[2];
        if (Callback10Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback10Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setDecreasingFlag;
            tableValue=decreasingValue-0xC8;
            goto storeDecreasingValue;
            }
            goto setDecreasingFlag;
storeDecreasingValue:
            *(int*)(Callback10Values + valueOffset) = tableValue;
setDecreasingFlag:
            flagOffset = *descriptor * 0x2C;
            Callback10Flags[flagOffset] = Callback10Flags[flagOffset] | 0x10;
            __asm__ volatile("" : : : "memory");
        }
        goto clearSharedValue;
    case 0x2A:
        Callback10Call80041C20();
        Callback10Call80042A44();
        Callback10Call80049590();
        descriptor=&Callback10Player.unk22[2];
        if (Callback10Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback10Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback10Player.unk22[2];
        }
        if (Callback10Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback10Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback10Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback10Flags[flagOffset] = Callback10Flags[flagOffset] | 0x10;
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
        Callback10Call80041C20();
        Callback10Call80042A44();
        Callback10Call80041AE8();
        if ((unsigned char) Callback10Player.unk10[4] != 0) {
            computedValue = -Callback10Player.unk9ha[4] - Callback10Call80037058(Callback10Player.position.x, Callback10Player.position.y);
            positionValue = Callback10Player.unk4a - computedValue;
            Callback10Player.unk4[0] = computedValue;
            positionDelta = (int) Callback10Player.union144.a.unk13cc >> 6;
            goto storePosition;
        }
        break;
storePosition:
        positionValue -= positionDelta;
        __asm__("" : "=r"(positionValue) : "0"(positionValue));
        Callback10Player.position.z=positionValue;
        return;
    default:
        return;
    }
}


/**
 * func_level_10_80089B9C() - ???() - MATCHING
 * Ready to add. Probably a Spyro animation sounds related one. Probably try making an animation.inc.h.
 * https://decomp.me/scratch/HatAh
 */
#define LEVEL_ID 10
#define PlaySpyroSounds_level_10 func_level_10_80089B9C
#include "overlay/animation.inc.h"

/**
 * func_level_10_80089CA4() - ???() - MATCHING
 * Ready to add. Check comments in scratch first, will probably try adding this using an animation.inc.h instead.
 * Likely has matches across other levels.
 * https://decomp.me/scratch/4KNXz
 */
extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_10_80089CA4(int index) {
    Vector3D* position;
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x2B: case 0x2C:
        position = &spyro.unk9e;
        break;
    case 0x13:
        position = 0;
        break;
    case 0x14: case 0x15: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1c: case 0x1d: case 0x1e: case 0x1f: case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: return;
    default: return;
    }
    func_80043ABC(position);
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80089D20.
 * Reuses verified41 private0/4/8 swirl and fly clamp800/4B00 with conditional
 * selector<A0 pointer clear, verified37 underwater/surface vectors stack10/20/30.
 * Original10 selector13,21..23,28..2C and244/250 tail. Word60 FFF wrap/801/clamp
 * vectors800/801/FFF yield0/-7FF/-1 before helpers. Offsets are bytes, shifts,
 * widths and branches source-native. Empty constraints emit no instructions.
 * Require every code/internal jump/owned dispatch word and complete EXE/overlay
 * retail hashes. Helper/audio semantics, units, cadence and live parity are open.
 */
extern Spyro Transition10_D_80070328 __asm__("D_80070328");
int Transition10_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition10_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern unsigned char Transition10RawUnion[] __asm__("D_80070328+0x144");
extern int Transition10RawMovement __asm__("D_80070328+0x50");
extern void (*Call10Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw10State[] __asm__("D_80070328+0x50");

extern int D_80071934;
int Call10A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw10NegativeWord __asm__("D_80070328+0x28");
void func_80047138(void);
void func_level_10_80089D20(int arg0){
    struct {Vector3D first; int gap1; Vector3D second; int gap2; Vector3D third;} vectors;
    register int negativeWord __asm__("$3");
    int firstResult,secondResult,firstWrappedWord,secondWrappedWord,firstParticleKind,secondParticleKind,firstParticleSubtype,secondParticleSubtype;

    int lengthResult;


    register unsigned char* privateData __asm__("$16");
    register unsigned char* stateBase __asm__("$17");
    int maskedValue;
    switch(arg0){
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        stateBase=(unsigned char*)&Transition10RawMovement;
        privateData = Transition10_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition10_D_80070328.unk5 = 0;
        Transition10_D_80070328.grounded = 0;
        Transition10_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition10_D_80070328.m_WhirlwindPointer;
        yawValue=Transition10_D_80070328.rotation.yaw;
        positionZ=Transition10_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition10_D_80070328.union144.a.unk13cc=yawValue;
        Transition10_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition10_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition10_D_80070328.union144.a.unk13ce.z=heightValue;
        __asm__ volatile("" : : : "memory");
        heightValue = ((int) (heightValue << 0xA) >> 0xA) + 0x400;
        __asm__("" : "=r"(heightValue) : "0"(heightValue));
        Transition10_D_80070328.union144.a.unk13ce.y = heightValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
        Transition10_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition10_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition10_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition10_D_80070328.unk13e[0] = (int) Transition10_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition10_D_80070328.unk20a = 0;
        Transition10_D_80070328.critterMobyPtr = 0;
        Transition10_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x21:
    case 0x22:
    case 0x23: {
        register unsigned char* flyState __asm__("$16")=(unsigned char*)&Transition10RawMovement;
        if(*(int*)flyState!=6) {
            *(int*)flyState=6;
            Transition10_D_80070328.unk5=0;
            Transition10_func_8004F168((Vector3D*)(flyState+0x104));
            Transition10_D_80070328.union144.a.unk13db.y=0;
            lengthResult=Transition10_func_8004EDE8((Vector3D*)(flyState+0x48),0);
            Transition10_D_80070328.unk8[0]=lengthResult;
            if(lengthResult<0x800)Transition10_D_80070328.unk8[0]=0x800;
            if(Transition10_D_80070328.unk8[0]>=0x4B01)Transition10_D_80070328.unk8[0]=0x4B00;
            Transition10_D_80070328.union144.a.unk13cb=0;
            Transition10_D_80070328.union144.b.unk148=0;
            Transition10_D_80070328.union144.a.unk13ce.x=0;
            Transition10_D_80070328.union144.a.unk13ce.y=0;
            Transition10_D_80070328.grounded=0;
            Transition10_D_80070328.unk15b=0;
        }
        if(arg0<0xA0)goto clearPointers;
        return;
    }
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition10_D_80070328.movementState - 0xB) >= 2U) && (Transition10_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition10_D_80070328.movementState - 0x50));
                if ((Transition10_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw10NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition10_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call10A358(&vectors.first, 0x800);
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
            firstWrappedWord = Transition10_D_80070328.rotation.pitch & 0xFFF;
            Transition10_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition10_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition10_D_80070328.rotation.pitch > 0) {
                Transition10_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition10_D_80070328.unk5 = 1;
            }
            Transition10_func_8004F168((Vector3D *) ((unsigned char*)&Transition10_D_80070328.rotation.pitch + 0xEC));
            Transition10_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition10_D_80070328.unk8[0] = Transition10_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition10_D_80070328.rotation.pitch + 0x38), 0);
            Transition10_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition10_D_80070328.animationState == 0x2A) {
            Transition10_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition10_D_80070328.union144.a.unk13da = 0;
        }
        Transition10_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition10_D_80070328.unk20a = 0;
        Transition10_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw10State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw10NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition10_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call10A358(localVector, 0x800);
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
            if (Transition10_D_80070328.animationState == 0x2E) {
                Transition10_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition10_D_80070328.rotation.pitch & 0xFFF;
            Transition10_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition10_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition10_D_80070328.rotation.pitch > 0) {
                Transition10_D_80070328.rotation.pitch = 0;
            }
            Transition10_D_80070328.unk5 = 1;
            Transition10_func_8004F168((Vector3D *) ((unsigned char*)&Transition10_D_80070328.animationState + 0x104));
            Transition10_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition10_D_80070328.unk8[0] = Transition10_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition10_D_80070328.animationState + 0x50), 0);
            Transition10_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition10_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition10_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition10RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition10RawUnion;
            *(int*)unionPointer=(-Transition10_D_80070328.unk7a[2].z)>>2;
            if(Transition10RawMovement!=8){Transition10_D_80070328.union144.a.unk13cc=0x5900;Transition10RawMovement=10;}
            Transition10_D_80070328.unk5=0;
            Transition10_D_80070328.unk8[0]=Transition10_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition10_D_80070328.grounded=1;
            Transition10_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call10A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
clearPointers:
        Transition10_D_80070328.unk20a=0;
        Transition10_D_80070328.critterMobyPtr=0;
        return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_10/animation", func_level_10_8008A444);
