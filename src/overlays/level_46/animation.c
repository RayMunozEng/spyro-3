#include "common.h"
#include "spu.h"
#include "ovl_header.h"
#include "stdutil.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_46/animation", func_level_46_8008E538);

extern unsigned char DecodedAnimationPlayer[] __asm__("D_80070328");
extern int D_8006C648, D_8006FA38;
extern int DecodedAnimationStep __asm__("D_80070328 + 0x144");
extern int DecodedAnimationZ __asm__("D_80070328 + 8");
extern int DecodedAnimationLimitSelector __asm__("D_80070328 + 0x280");
int func_8001A358(Vector3D*, int);
extern int DecodedAnimationWordA0 __asm__("D_80070328 + 0xA0");
extern int DecodedAnimationWord4C __asm__("D_80070328 + 0x4C");
extern unsigned char DecodedAnimationByte23 __asm__("D_80070328 + 0x23");
extern unsigned char DecodedAnimationByte22 __asm__("D_80070328 + 0x22");
extern unsigned char DecodedAnimationByte21 __asm__("D_80070328 + 0x21");
extern unsigned char DecodedAnimationByte20 __asm__("D_80070328 + 0x20");
void func_80043A38(int);
extern int D_8006E538;
/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * 8008F2D8..8008F5CC,190 code words plus18 dispatch words.
 * Signed-step branch reused from verified level17_80082B84; original
 * modes115..132 and all raw word gates/helper call order retained.
 * Units, input/player producers, helper semantics and cadence unresolved.
 * Test: original linked code/dispatch words and complete retail hashes.
 */
void func_level_46_8008F2D8(void) {
    Vector3D sample;
    switch (spyro.animationState) {
    case 115: case 120: case 122: case 123: case 124: case 126:
        if (!func_800438F4()) func_80043728();
        func_80041C20();
        spyro.unk9a = 0;
        func_80042A44();
        goto clearWord28;
    case 128:
        func_80041C20();
        func_80042A44();
        goto clearWord28;
    case 121:
        func_80041C20();
        func_80042A44();
        goto query;
    case 129: {
        register int* zPointer __asm__("$5") = (int*)(DecodedAnimationPlayer + 8);
        register int velocity __asm__("$6") = DecodedAnimationStep;
        register int position __asm__("$2") = *zPointer;
        register int tick __asm__("$3") = D_8006C648;
        register int status __asm__("$2");
        register int increment __asm__("$4");
        __asm__("" : "=r"(velocity) : "0"(velocity));
        __asm__("" : "=r"(position) : "0"(position));
        __asm__("" : "=r"(tick) : "0"(tick));
        increment = velocity >> 6;
        __asm__("" : "=r"(increment) : "0"(increment));
        position += increment;
        __asm__("" : "=r"(tick) : "0"(tick), "r"(position));
        tick <<= 9;
        *zPointer = position;
        status = DecodedAnimationLimitSelector;
        velocity += tick;
        DecodedAnimationStep = velocity;
        __asm__("" : : : "memory");
        if (status >= 0 && D_8006FA38 < 0) goto lowerLimit;
        {
            register int limit __asm__("$3") = 0x9000;
            register int exceeded __asm__("$2");
            __asm__("" : "=r"(limit) : "0"(limit));
            exceeded = limit < velocity;
            if (exceeded) DecodedAnimationStep = limit;
        }
        goto limitsDone;
    lowerLimit:
        {
            register int below __asm__("$2") = velocity < 0x2581;
            if (!below) DecodedAnimationStep = 0x2580;
        }
    limitsDone:
        func_80041C20();
        func_80042A44();
        func_8004F178(&sample, (Vector3D*)DecodedAnimationPlayer);
        sample.z += 0x400;
        spyro.unk4[0] = func_8001A358(&sample, 0xC00);
        DecodedAnimationZ -= DecodedAnimationStep >> 6;
        return;
    }
    case 118: case 119: {
        register int* state __asm__("$4");
        func_80041C20();
        func_80042A44();
        func_80041930();
        state = &DecodedAnimationWord4C;
        /* Retain original A0 address base; this constraint emits no code. */
        __asm__("" : "=r"(state) : "0"(state));
        if (*state == 127) goto clearWord28;
        if (DecodedAnimationWordA0 < 0 && spyro.animationStateFrames >= 4) {
            *state = 1;
            goto clearWord28;
        }
        goto transition;
    }
    case 130:
        if (spyro.movementState != 1) goto alternative;
    case 116: case 117: case 131: case 132:
        func_800438F4();
        func_80041C20();
        func_80042A44();
        func_80041930();
    query:
        func_80043A38(0xC00);
        goto clearWord28;
    alternative:
        func_80041C20();
        func_80042A44();
        func_80041930();
        if (DecodedAnimationWordA0 < 0 && spyro.animationStateFrames >= 4) {
            DecodedAnimationWord4C = 1;
            goto clearWord28;
        }
    transition: {
        int* state = &DecodedAnimationWord4C;
        if (*state == 0 && !(D_8006E538 & 0x40) && DecodedAnimationStep == 0)
            *state = 2;
    }
    clearWord28:
        spyro.unk4[0] = 0;
        return;
    }
}

#define LEVEL_ID 46
#define PlaySpyroSounds_level_46 func_level_46_8008F5D0
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_46_8008F6F8(int index) {
    register Vector3D* position __asm__("$4");
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x76: case 0x77:
        __asm__("" : : : "memory");
        position = 0;
        break;
    case 0x82:
        position = (Vector3D*)((char*)&spyro + 0xB8);
        __asm__("" : "=r"(position) : "0"(position));
        if (position->x) { position = 0; break; }
    case 0x73: case 0x74: case 0x75: case 0x78: case 0x79: case 0x7A: case 0x7B: case 0x7C: case 0x7E: case 0x80: case 0x81: case 0x83: case 0x84:
        position = &g_Spyro.unk9e;
        break;
    default: return;
    }
    func_80043ABC(position);
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008F788 callback.
 * Reuses verified level36 transition table/copy producer. Original46 supplies
 * selectors73..84, private+5C/64/68/6C and private+74 signed halfword/+78 pointer,
 * child+48 byte writes, and original callback argument Moby+250.
 * Numeric offsets are bytes. Signed table shifts, constants and original
 * independent walk queries follow original instructions. Empty constraints
 * preserve register lifetimes/scheduling; no instruction-emitting asm.
 * Source units, helper meanings, audio semantics and update cadence unresolved.
 * Falsifiable acceptance: every original code/local jump/table word, strict
 * complete translation unit and complete EXE/every overlay hashes.
 */
extern int Raw46Movement __asm__("D_80070328+0x50");
extern int Raw46Union __asm__("D_80070328+0x144");
void Call46ED6C(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
extern void (*Call46Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw46State[] __asm__("D_80070328+0x50");
extern Spyro Callback46_D_80070328 __asm__("D_80070328");
extern short Signed46TableA[] __asm__("D_800658A0");
extern short Signed46TableB[] __asm__("D_80065920");
int Callback46_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Callback46_func_80043A38(int scale) __asm__("func_80043A38");
void Callback46_func_800441F0(void) __asm__("func_800441F0");
void Callback46_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Callback46_D_8006E524 __asm__("D_8006E524");

void func_level_46_8008F788(int arg0) {
    register Vector3D* destination __asm__("$4");
    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    register unsigned char *sourceBytesA __asm__("$16");

    register unsigned char* walkBase __asm__("$5");
    register int walkFlag __asm__("$16");
    register int selector __asm__("$4");
    register int groundValue __asm__("$2");
    switch (arg0) {
    case 0x73:
    case 0x78:
    case 0x7E:
        Callback46_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback46_D_80070328.unk5 = 0;
        Callback46_func_800441F0();
        Callback46_D_80070328.grounded = 1;
        return;
    case 0x74:
    case 0x75:
    case 0x83:
    case 0x84:
        walkBase=Raw46State;
        walkFlag=1;
        __asm__("" : "=r"(walkFlag) : "0"(walkFlag));
        selector=arg0;
        __asm__("" : "=r"(selector) : "0"(selector));
        *(int*)walkBase=walkFlag;
        if(selector==0x57 && Callback46_D_80070328.ticksSinceLastSurfaceTouch!=0) {
            __asm__ volatile("" : : : "memory");
            destination=(Vector3D*)(walkBase+0x3C);
            goto copyWalkVector;
        }
        goto clearWalkFlag;
    case 0x80:
        Callback46_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Callback46_D_80070328.unk5 = 0;
        Callback46_func_80043A38(0xC00);
        Callback46_D_80070328.grounded = 1;
        Callback46_D_8006E524 = 0xF;
        return;
    case 0x81: {
        register int oldState __asm__("$3")=Raw46Movement;
        register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$8")=SpawnParticle;
        register int* stateWord __asm__("$2");
        register int value __asm__("$2");
        __asm__ volatile("" : "=r"(oldState), "=r"(callback) : "0"(oldState), "1"(callback) : "memory");
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Raw46Movement=value;
        value=1;
        __asm__("" : "=r"(value) : "0"(value));
        Callback46_D_80070328.grounded=value;
        value=15;
        __asm__("" : "=r"(value) : "0"(value));
        Callback46_D_8006E524=value;
        Callback46_D_80070328.unk5=0;
        stateWord=&Raw46Union;
        __asm__("" : "=r"(stateWord) : "0"(stateWord));
        Callback46_D_80070328.unk5=0;
        *stateWord=oldState;
        __asm__ volatile("" : : : "memory");
        *stateWord=0;
        if(callback)callback(5,10,0,0);
        Callback46_D_80070328.unk22[2]=PlaySound((int)D_8006C654->drown,0,0);
        Callback46_D_80070328.unk22[3]=(int)D_8006C654->drown;
        return;
    }
    case 0x79:
        Callback46_D_80070328.movementState = MOVEMENT_STATE_HURT;
        Callback46_D_80070328.unk5 = 0;
        if (Callback46_D_80070328.unk22[5] >= 0) {
            tableOffsetOrValue = Callback46_D_80070328.unk22[5] * 2;
            tableValueA = *(short*)((unsigned char*)Signed46TableB + tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            tableValueA >>= 1;
            Callback46_D_80070328.unk7a[2].x = tableValueA;
            tableOffsetOrValue = *(short*)((unsigned char*)Signed46TableA + tableOffsetOrValue);
            Callback46_D_80070328.unk7a[2].z = 0;
            __asm__ __volatile__("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Callback46_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
        } else {
            Callback46_func_8004F168((Vector3D *) ((unsigned char*)&Callback46_D_80070328.movementState + 0x3C));
        }
        Callback46_D_80070328.unk7a[2].z = 0x200;
        func_8004F178((Vector3D *) ((unsigned char*)&Callback46_D_80070328.unk7a[2].z - 0x14), (Vector3D *) ((unsigned char*)&Callback46_D_80070328.unk7a[2].z - 8));
        Callback46_D_80070328.grounded = 1;
        Callback46_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
    default:
        return;
    case 0x7A: {
        register unsigned char* privateData __asm__("$17")=Callback46_D_80070328.critterMobyPtr->mobyTag;
        register unsigned char* state __asm__("$18")=Raw46State;
        register Vector3D* vector __asm__("$16");
        *(int*)state=0;
        Callback46_D_80070328.unk5=0;
        vector=(Vector3D*)(privateData+0x64);
        Callback46_func_800441F0();
        Callback46_D_80070328.grounded=1;
        Callback46_D_80070328.idle=0;
        Callback46_D_80070328.unk15g=0;
        *(int*)(privateData+0x5C)=0x180;
        *(int*)(privateData+0x64)=0x1800;
        *(int*)(privateData+0x68)=0;
        *(int*)(privateData+0x6C)=0;
        Call46ED6C((Vector3D*)(state-0x20),vector,vector);
        func_8004F194(vector,vector,(Vector3D*)(state-0x50));
        Call46Header(Callback46_D_80070328.critterMobyPtr);
        return;
    }
    case 0x7B:
        Callback46_D_80070328.movementState=0;
        Callback46_func_800441F0();
        groundValue=1;
        goto sharedGround;
    case 0x7C: {
        register unsigned char* privateData __asm__("$16")=Callback46_D_80070328.critterMobyPtr->mobyTag;
        register unsigned char* child __asm__("$4");
        Callback46_D_80070328.movementState=0;
        Callback46_func_800441F0();
        Callback46_D_80070328.grounded=1;
        Callback46_D_80070328.idle=0;
        Callback46_D_80070328.unk15g=0;
        child=*(unsigned char**)(privateData+0x78);
        if(child) {
            if(*(short*)(privateData+0x74)==0x22A)child[0x48]=0x50;
            else child[0x48]=1;
        }
        return;
    }
    case 0x76:
        stateBaseA = Raw46State;
        __asm__("" : "=r"(stateBaseA) : "0"(stateBaseA));
        destination = (Vector3D*)(stateBaseA + 0x3C);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceBytesA = stateBaseA + 0x48;
        *(int*)stateBaseA = 2;
        func_8004F178(destination, (Vector3D*)sourceBytesA);
        Callback46_D_80070328.unk8[0] = Callback46_func_8004EDE8((Vector3D *) sourceBytesA, 0);
        Callback46_D_80070328.unk7a[2].z = 0xDC0;
        Callback46_D_80070328.unk5 = 0;
        if(Callback46_D_80070328.animationState==0x81)Callback46_D_80070328.union144.a.unk13cb=1;
        else Callback46_D_80070328.union144.a.unk13cb=0;
        Callback46_D_80070328.grounded = 0;
        PlaySound((int) D_8006C654->jump, 0, 0);
        return;
    case 0x77: {
        register unsigned char* state __asm__("$6")=Raw46State;
        if(*(int*)state!=2) {
            *(int*)state=3;
            Callback46_D_80070328.unk8[0]=Callback46_func_8004EDE8((Vector3D*)(state+0x48),0);
            Callback46_D_80070328.grounded=0;
            Callback46_D_80070328.unk15b=1;
            goto clearTail;
        }
        return;
    }
    case 0x82: {
        walkBase=Raw46State;
        if(*(int*)walkBase!=2) {
            walkFlag=1;
            __asm__("" : "=r"(walkFlag) : "0"(walkFlag));
            *(int*)walkBase=walkFlag;
            if(arg0==0x57 && Callback46_D_80070328.ticksSinceLastSurfaceTouch!=0) {
                destination=(Vector3D*)(walkBase+0x3C);
copyWalkVector:
                func_8004F178(destination,(Vector3D*)(walkBase+0x48));
                Callback46_D_80070328.unk5=walkFlag;
            } else {
clearWalkFlag:
                Callback46_D_80070328.unk5=0;
            }
            Callback46_D_80070328.unk8[0]=Callback46_func_8004EDE8((Vector3D*)((unsigned char*)&Callback46_D_80070328.movementState+0x48),0);
            Callback46_func_80043A38(0xC00);
            groundValue=1;
            __asm__("" : "=r"(groundValue) : "0"(groundValue));
            Callback46_D_80070328.union144.a.unk13cb=0;
sharedGround:
            Callback46_D_80070328.grounded=groundValue;
clearTail:
            Callback46_D_80070328.idle=0;
            Callback46_D_80070328.unk15g=0;
        }
        return;
    }
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_46/animation", func_level_46_8008FC9C);
