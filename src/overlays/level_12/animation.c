#include "common.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_12/animation", func_level_12_8008864C);

void Callback12Call80043A38(int) __asm__("func_80043A38");
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80089B6C callback.
 * Reuses verified10 particle, verified13 table and verified43 timer producers.
 * Original12 supplies dispatch and byte colour selectors: nextFrame unsigned
 * comparison10/parity1, colour bytesFF/40/20. Count148-B0 and source-98 are byte
 * offsets, table stride2C and flag10 retained, original timer helper selectorA.
 * Stack vectorSP10, frame38 and reserved spacing follow original output;
 * reserved words establish no retail variable meaning. Empty constraints
 * emit no instructions; preserve original register lifetimes/load scheduling.
 * Units, helper meanings, sound semantics and caller cadence unresolved.
 * Acceptance: every original code/local jump/table word, strict complete TU,
 * complete EXE and every retail overlay hash. Runtime parity remains open.
 */
extern Spyro Callback12Player __asm__("D_80070328");
int Callback12Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback12Call80041930(void) __asm__("func_80041930");
void Callback12Call80041C20(void) __asm__("func_80041C20");
void Callback12Call80042A44(void) __asm__("func_80042A44");
extern int D_8006C648;
extern unsigned char Callback12Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback12Values[] __asm__("D_8006FCF0");
extern short Callback12Count __asm__("D_80070328+0x148");
void Callback12Call8004F110(Vector3D*,int) __asm__("func_8004F110");
void func_level_12_80089B6C(void) {
    Vector3D localVector;
    int reservedStackWords[2];
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
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    register int flagOffset __asm__("$3");


    switch(Callback12Player.animationState) {
    case 0x14:
        if(func_800438F4()==0)func_80043728();
        Callback12Call80041C20();
        Callback12Player.unk9a=0;
        Callback12Call80042A44();
clearSharedValue:
        Callback12Player.unk4[0]=0;
        return;
    case 0x9:
        Callback12Call80041C20();
        Callback12Call80042A44();
        if(Callback12Player.unk5==1)Callback12Call80041930();
        else Callback12Call80043A38(0xC00);
        if((unsigned char)Callback12Player.bodyAnimation.nextFrame<10U) {
            Callback12Player.cheatColour.a=255;
            if(Callback12Player.bodyAnimation.nextFrame&1) {
                Callback12Player.cheatColour.b=255;
                Callback12Player.cheatColour.g=255;
                Callback12Player.cheatColour.r=255;
            } else {
                Callback12Player.cheatColour.b=64;
                Callback12Player.cheatColour.g=64;
                Callback12Player.cheatColour.r=64;
            }
        }
        goto clearSharedValue;
    case 0x13:
        Callback12Call80041C20();
        Callback12Call80042A44();
        Callback12Call80041930();
        goto clearSharedValue;
    case 0x1C:
        Callback12Call80041C20();
        Callback12Call80042A44();
        Callback12Call80041930();
        if(Callback12Player.unk7a[3].z<0 && Callback12Player.animationStateFrames>=4)
            Callback12Player.unk5=1;
        goto clearSharedValue;
    case 0x21:
    case 0x22:
    case 0x23:
        Callback12Call80041C20();
        Callback12Call80042A44();
        Callback12Call80041930();
        if (SpawnParticle != 0) {
            countBase=(unsigned char*)&Callback12Count;
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
                    Callback12Call8004F110((&localVector), 7);
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
    case 0x26:
        Callback12Call80041C20();
        Callback12Call80042A44();
        descriptor=&Callback12Player.unk22[2];
        if (Callback12Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback12Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setDecreasingFlag;
            tableValue=decreasingValue-0xC8;
            goto storeDecreasingValue;
            }
            goto setDecreasingFlag;
storeDecreasingValue:
            *(int*)(Callback12Values + valueOffset) = tableValue;
setDecreasingFlag:
            flagOffset = *descriptor * 0x2C;
            Callback12Flags[flagOffset] = Callback12Flags[flagOffset] | 0x10;
            __asm__ volatile("" : : : "memory");
        }
        goto clearSharedValue;
    case 0x31:
        Callback12Call80041C20();
        Callback12Call80042A44();
        Callback12Call80043A38(0xC00);
        if (func_80040954(Callback12Player.unk11[2]) == 0xA) {
            Callback12Player.union144.a.unk13cb = 0;
        } else {
            Callback12Player.union144.a.unk13cb += D_8006C648;
        }
        Callback12Player.unk4[0] = 0;
        if (Callback12Call8003BF6C((int) D_8006C654->unk32, Callback12Player.unk22[2]) == 0) {
            Callback12Player.unk22[2] = PlaySound((int) D_8006C654->unk32, 0, 4);
            Callback12Player.unk22[3] = (int) D_8006C654->unk32;
            return;
        }
        break;
    case 0x3A:
        Callback12Call80041C20();
        Callback12Call80042A44();
        Callback12Player.cheatColour.a=255;
        Callback12Player.unk4[0]=0;
        Callback12Player.cheatColour.b=32;
        Callback12Player.cheatColour.g=32;
        Callback12Player.cheatColour.r=32;
        return;
    default:
        return;
    }
}


/**
 * func_level_12_80089FE4() - ???() - MATCHING
 * Ready to add. Currently appropriate for introducing as an animation.inc.h.
 * https://decomp.me/scratch/CMQIW
 */
#define LEVEL_ID 12
#define PlaySpyroSounds_level_12 func_level_12_80089FE4
#include "overlay/animation.inc.h"

/**
 * func_level_12_8008A0EC() - ???() - MATCHING
 * Ready to add. The case order seems to be a mess here.
 * https://decomp.me/scratch/pcTDp
 */
extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_12_8008A0EC(int index) {
    Vector3D* vector;
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 9:
        {
            register int* state __asm__("$4") = (int*)((char*)&spyro + 0x4C);
            __asm__("" : "=r"(state) : "0"(state));
            if (*state == 1) goto reset;
            vector = (Vector3D*)((char*)state + 0x80);
            goto apply;
        }
    case 0x14:
    case 0x31:
    case 0x3A:
        vector = &spyro.unk9e;
        goto apply;
    case 0x13:
    case 0x1C:
reset:
        vector = 0;
apply:
        func_80043ABC(vector);
        break;
    }
}

extern short Transition12SignedA[] __asm__("D_800658A0");
extern short Transition12SignedB[] __asm__("D_80065920");
extern int Transition12RawX __asm__("D_80070328+0x8C");
int Transition12_func_80040954(int) __asm__("func_80040954");
void Transition12_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");
extern int Transition12_D_8006E528 __asm__("D_8006E528");
int Transition12_func_8004E880(int,int,int) __asm__("func_8004E880");
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008A188 transition.
 * Reuses verified47 private words0/4/8 and verified27 case9/1C producers.
 * Original12 supplies saved movement pointer and selectors21/22/23/26/31.
 * All pointer arithmetic is in bytes: header10C-74/-80/+110, movement50+
 * 104/48/FC/10C and lengthB0-30/-18; slide copies8C from80. Movement6,
 * signed table halfwords/shift1, signed clamp800/4B00 and yaw wrapFFF follow
 * original target instructions. Empty constraints emit no instructions and
 * preserve original scheduling/register lifetimes. Helper meanings, units,
 * audio semantics, caller cadence and live/runtime behavior remain unresolved.
 * Acceptance requires all original code/local jumps/table words, strict full
 * translation unit and complete EXE/every original overlay hashes.
 */
extern Spyro Transition12_D_80070328 __asm__("D_80070328");
int Transition12_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
int Transition12_func_8003636C(int low, int high) __asm__("func_8003636C");
void Transition12_func_80043A38(int scale) __asm__("func_80043A38");
void Transition12_func_800441F0(void) __asm__("func_800441F0");
void Transition12_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition12_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition12RawUnion[] __asm__("D_80070328+0x144");
extern int Transition12RawMovement __asm__("D_80070328+0x50");
void func_level_12_8008A188(int selector) {
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");

    int deltaValue;

    int lengthResult;

    int shiftedValue;
    int maskedValue;
    register unsigned char* privateData __asm__("$16");

    register int tableIndex __asm__("$2");
    register int tableValue __asm__("$3");
    register int oldMovementA __asm__("$3");
    register int oldMovementB __asm__("$3");
    register int flags __asm__("$2");
    register unsigned char* header __asm__("$17");
    register int *sourceA __asm__("$16");
    int *sourceB;
    register unsigned char* stateBase __asm__("$17");
    switch (selector) {
    case 0x14:
        Transition12_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition12_D_80070328.unk5 = 0;
        Transition12_func_800441F0();
        Transition12_D_80070328.grounded = 1;
        Transition12_D_80070328.union144.a.unk13cb = Transition12_func_8003636C(1, 3);
        Transition12_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x9:
        header = (unsigned char*)&Transition12_D_80070328.unk11[2];
        if (Transition12_func_80040954(*(int*)header) == 7) {
            sourceA = (int*)(header - 0x74);
            oldMovementA = Transition12RawMovement;
            Transition12RawMovement = MOVEMENT_STATE_HURT;
            Transition12_D_80070328.unk5 = 1;
            Transition12_D_80070328.union144.a.unk13cb = oldMovementA;
            func_8004F178((Vector3D *) (header - 0x80), (Vector3D *) sourceA);
            Transition12_D_80070328.unk8[0] = Transition12_func_8004EDE8((Vector3D *) sourceA, 0);
            Transition12_D_80070328.unk7a[2].z = 0xDC0;
            Transition12_D_80070328.grounded = 0;
        } else {
            oldMovementB = Transition12RawMovement;
            flags = Transition12_D_80070328.unk17a;
            __asm__("" : "=r"(oldMovementB), "=r"(flags) : "0"(oldMovementB), "1"(flags));
            Transition12RawMovement = MOVEMENT_STATE_HURT;
            Transition12_D_80070328.unk5 = 0;
            __asm__ __volatile__("" : "=r"(flags) : "0"(flags) : "memory");
            Transition12_D_80070328.union144.a.unk13cb = oldMovementB;
            sourceB = (int*)(header - 0x80);
            if (flags & 0x400) {
                func_8004F178((Vector3D *) sourceB, (Vector3D *) (header + 0x110));
                Transition12_func_8004F0E8((Vector3D *) sourceB, 6);
            } else if (Transition12_D_80070328.unk22[5] >= 0) {
                tableIndex = Transition12_D_80070328.unk22[5] * 2;
                tableValue = *(short*)((unsigned char*)Transition12SignedB + tableIndex);
                __asm__("" : "=r"(tableValue) : "0"(tableValue));
                Transition12RawX = tableValue >> 1;
                tableIndex = *(short*)((unsigned char*)Transition12SignedA + tableIndex);
                Transition12_D_80070328.unk7a[2].z = 0;
                __asm__ __volatile__("" : "=r"(tableIndex) : "0"(tableIndex) : "memory");
                Transition12_D_80070328.unk7a[2].y = tableIndex >> 1;
            } else {
                __asm__("" : "=r"(header) : "0"(header));
                destination = (Vector3D*)(header - 0x80);
                Transition12_func_8004F168(destination);
            }
            func_8004F178(&Transition12_D_80070328.unk7a[1], (Vector3D*)((unsigned char*)&Transition12_D_80070328.unk7a[1] + 0xC));
            Transition12_func_80043A38(0xC00);
            Transition12_D_80070328.grounded = 1;
        }
        Transition12_D_8006E528 = 0x2D;
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
        stateBase=(unsigned char*)&Transition12RawMovement;
        privateData = Transition12_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition12_D_80070328.unk5 = 0;
        Transition12_D_80070328.grounded = 0;
        Transition12_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition12_D_80070328.m_WhirlwindPointer;
        yawValue=Transition12_D_80070328.rotation.yaw;
        positionZ=Transition12_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition12_D_80070328.union144.a.unk13cc=yawValue;
        Transition12_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition12_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition12_D_80070328.union144.a.unk13ce.z=heightValue;
        deltaValue=heightValue;
        shiftedValue = ((int) (deltaValue << 0xA) >> 0xA) + 0x400;
        Transition12_D_80070328.union144.a.unk13ce.y = shiftedValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - shiftedValue) & 0xFFF;
        Transition12_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition12_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition12_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition12_D_80070328.unk13e[0] = (int) Transition12_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition12_D_80070328.unk20a = 0;
        Transition12_D_80070328.critterMobyPtr = 0;
        Transition12_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x1C:
        savedBase = Transition12RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Transition12RawMovement;
        Transition12RawMovement = MOVEMENT_STATE_HURT;
        Transition12_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Transition12_D_80070328.unk8[0] = Transition12_func_8004EDE8(sourceC, 0);
        Transition12_D_80070328.unk7a[2].z = 0xDC0;
        Transition12_D_80070328.grounded = 0;
        Transition12_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Transition12_D_80070328.damageFlags & 0x200) {
            Transition12_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition12_D_80070328.union144.a.unk13cc = 1;
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        goto clearPointers;
    case 0x3A:
        Transition12_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition12_D_80070328.unk5 = 0;
        Transition12_func_80043A38(0xC00);
        Transition12_D_80070328.grounded = 1;
        if ((selector == 0x3A) || (selector == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition12_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x21:
    case 0x22:
    case 0x23: {
        register unsigned char* flyState __asm__("$16")=(unsigned char*)&Transition12RawMovement;
        if(*(int*)flyState!=6) {
            *(int*)flyState=6;
            Transition12_D_80070328.unk5=0;
            Transition12_func_8004F168((Vector3D*)(flyState+0x104));
            Transition12_D_80070328.union144.a.unk13db.y=0;
            lengthResult=Transition12_func_8004EDE8((Vector3D*)(flyState+0x48),0);
            Transition12_D_80070328.unk8[0]=lengthResult;
            if(lengthResult<0x800)Transition12_D_80070328.unk8[0]=0x800;
            if(Transition12_D_80070328.unk8[0]>=0x4B01)Transition12_D_80070328.unk8[0]=0x4B00;
            Transition12_D_80070328.union144.a.unk13cb=0;
            Transition12_D_80070328.union144.b.unk148=0;
            Transition12_D_80070328.union144.a.unk13ce.x=0;
            Transition12_D_80070328.union144.a.unk13ce.y=0;
            Transition12_D_80070328.grounded=0;
            Transition12_D_80070328.unk15b=0;
        }
        if(selector<0xA0)goto clearPointers;
        return;
    }
    case 0x26: {
        register unsigned char* state __asm__("$16")=(unsigned char*)&Transition12RawMovement;
        *(int*)state=11;
        if(Transition12_D_80070328.animationState==0x2A)Transition12_D_80070328.unk5=2;
        Transition12_func_8004F168((Vector3D*)(state+0xFC));
        Transition12_D_80070328.union144.a.unk13cb=0;
        Transition12_D_80070328.unk8[0]=Transition12_func_8004EDE8((Vector3D*)(state+0x48),0);
        Transition12_D_80070328.grounded=1;
        Transition12_D_80070328.unk4a=0x280;
        return;
    }
    case 0x31: {
        register unsigned char* lengthBase __asm__("$5")=(unsigned char*)&Transition12_D_80070328.unk8[0];
        register int valueA __asm__("$4");
        register int valueB __asm__("$5");
        register int valueKind __asm__("$6");
        *(int*)lengthBase=0;
        if(Transition12_D_80070328.animationState==0xD || Transition12_D_80070328.movementState==1)
            func_8004F178((Vector3D*)(lengthBase-0x30),(Vector3D*)(lengthBase-0x18));
        else Transition12_func_8004F168((Vector3D*)(lengthBase-0x30));
        func_8004F178(&Transition12_D_80070328.unk7a[2],(Vector3D*)((unsigned char*)&Transition12_D_80070328.unk7a[2]-0xC));
        Transition12_D_80070328.movementState=17;
        Transition12_D_80070328.unk5=0;
        Transition12_func_80043A38(0xC00);
        Transition12_D_80070328.grounded=0;
        Transition12_D_80070328.union144.a.unk13cb=0;
        valueKind=1;
        if(Transition12_D_80070328.unk9ha[0]>=11) {
            valueA=Transition12_D_80070328.unk9e.x;
            valueB=Transition12_D_80070328.unk9e.y;
        } else {
            valueA=Transition12_D_80070328.unk7a[3].x;
            valueB=valueA;
        }
        Transition12_D_80070328.union144.a.unk13cc=Transition12_func_8004E880(valueA,valueB,valueKind);
clearPointers:
        Transition12_D_80070328.unk20a=0;
        Transition12_D_80070328.critterMobyPtr=0;
        return;
    }
    default:
        return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_12/animation", func_level_12_8008A82C);
