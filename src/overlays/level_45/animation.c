#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_45/animation", func_level_45_800869F4);

/* AI generated; not human reviewed. SCUS-94467 80087D60..800882C4.
 * Reuses verified level15_800882B8 particle arithmetic and typed helpers;
 * original level45 supplies dispatch, two stack vectors and producer ordering.
 * Byte-addressed sources preserve offsets; scalar samples remain signed words.
 * Empty constraints retain original register/memory lifetimes, emitting no code.
 * Helper meanings, source units, sound descriptors and cadence remain unresolved.
 * Acceptance: all original linked words and every complete retail hash.
 */
extern unsigned char Callback45CountBase[] __asm__("D_80070328+0x148");
extern int Callback45HeightF4 __asm__("D_80070328+0xF4");
extern Spyro Callback45Player __asm__("D_80070328");
int Callback45Call80037058(int x, int y) __asm__("func_80037058");
int Callback45Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback45Call80041930(void) __asm__("func_80041930");
void Callback45Call80041AE8(void) __asm__("func_80041AE8");
void Callback45Call80041C20(void) __asm__("func_80041C20");
void Callback45Call80042A44(void) __asm__("func_80042A44");
void Callback45Call80043728(void) __asm__("func_80043728");
int Callback45Call800438F4(void) __asm__("func_800438F4");
void Callback45Call80043A38(int scale) __asm__("func_80043A38");
void Callback45Call80049590(void) __asm__("func_80049590");
void Callback45Call8004F110(Vector3D*, int) __asm__("func_8004F110");
extern int Callback45Word8006E344 __asm__("D_8006E344");
extern int Callback45Word8006E52C __asm__("D_8006E52C");
extern int Callback45Word8006E530 __asm__("D_8006E530");
extern int Callback45Word8006E538 __asm__("D_8006E538");
void func_level_45_80087D60(void) {
    struct {Vector3D first; int reserved1C; Vector3D second; int reserved2C; int reserved[4];} local;
    register unsigned char* firstSource __asm__("$18");
    register unsigned char* secondSource __asm__("$19");
    int clampValue, computedValue;
    register int iteration __asm__("$16");
    register int firstLimit __asm__("$17");
    register int secondLimit __asm__("$18");
    register int sample __asm__("$2");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    register Vector3D* secondVector __asm__("$17");
    register unsigned char* countBase __asm__("$5");
    register int* zWord __asm__("$19");
    register char* (*particles)(int,int,Vector3D*,Vector3D*) __asm__("$8");
    switch (Callback45Player.animationState) {
        case 20:
            if (Callback45Call800438F4() == 0) {
                Callback45Call80043728();
            }
            Callback45Call80041C20();
            Callback45Player.unk9a = 0;
            Callback45Call80042A44();
            goto clearSharedValue;
        case 0x35:
        case 0x36:
            Callback45Call80041C20();
            Callback45Call80042A44();
            goto clearSharedValue;
        case 25:
            Callback45Call80041C20();
            Callback45Call80042A44();
            Callback45Call80041930();
            Callback45Call80049590();
            if ((Callback45Player.movementState == MOVEMENT_STATE_SUPERCHARGE) && (SpawnParticle != 0)) {
                SpawnParticle(1, 9, 0, 0);
            }
            if ((Callback45Player.unk7a[3].z < 0) && (Callback45Player.animationStateFrames >= 4)) {
                Callback45Player.unk5 = 1;
            } else if ((Callback45Player.unk5 == 0) && !(Callback45Word8006E538 & 0x40)) {
                Callback45Player.unk5 = 2;
            }
            goto clearSharedValue;
        case 0x21:
        case 0x22:
        case 0x23:
            Callback45Call80041C20();
            Callback45Call80042A44();
            Callback45Call80041930();
            if (SpawnParticle != 0) {
                countBase=Callback45CountBase;
                __asm__("" : "=r"(countBase) : "0"(countBase));
                if (*(short*)countBase == 0) goto clearSharedValue;
                firstLimit = 1;
                if (*(short*)countBase >= 2) {
                    firstLimit = 2;
                }
                iteration = 0;
                if (firstLimit != 0) {
                    firstSource = countBase - 0xB0;
                    do {
                        func_8004F178(&local.first, (Vector3D *) firstSource);
                        Callback45Call8004F110(&local.first, 7);
                        iteration += 1;
                        sample=rand();
                        component=local.first.x;
                        sample &= 254;
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        local.first.x=component;
                        sample=rand();
                        component=local.first.y;
                        sample &= 254;
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        local.first.y=component;
                        sample=rand();
                        kind=1;
                        subtype=0x17;
                        position=firstSource - 0x98;
                        vector=&local.first;
                        __asm__("" : "=r"(kind), "=r"(subtype), "=r"(position), "=r"(vector) : "0"(kind), "1"(subtype), "2"(position), "3"(vector), "r"(sample) : "$3", "$8", "memory");
                        sample &=254;
                        __asm__("" : "=r"(sample) : "0"(sample) : "$3", "$8", "memory");
                        component=local.first.z;
                        __asm__("" : "=r"(component) : "0"(component) : "$8", "memory");
                        particles=SpawnParticle;
                        __asm__("" : "=r"(particles), "=r"(component) : "0"(particles), "1"(component));
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        local.first.z=component;
                        particles(kind,subtype,(Vector3D*)position,vector);
                    } while (iteration < firstLimit);
                }
            }
            goto clearSharedValue;
        case 0x2B:
        case 0x2C:
        case 0x37:
        Callback45Call80041C20();
        Callback45Call80042A44();
        Callback45Call80041AE8();
        if ((unsigned char) Callback45Player.unk10[4] != 0) {
            computedValue = -Callback45Player.unk9ha[4] - Callback45Call80037058(Callback45Player.position.x, Callback45Player.position.y);
            Callback45Player.unk4[0] = computedValue;
            Callback45Player.position.z = (Callback45Player.unk4a - computedValue) - ((int) Callback45Player.union144.a.unk13cc >> 6);
        }

            return;
        case 0x3D:
            Callback45Call80041C20();
            Callback45Call80042A44();
            Callback45Call80043A38(0xC00);
            Callback45Call80049590();
            if (SpawnParticle != 0) {
                SpawnParticle(1, 9, 0, 0);
            }
            Callback45Word8006E530 = 0x78;
            Callback45Player.unk4[0] = 0;
            Callback45Word8006E52C = 4;
            if ((Callback45Word8006E344 == 0) && (Callback45Call8003BF6C((int) D_8006C654->supercharge, Callback45Player.unk22[2]) == 0)) {
                Callback45Player.unk22[2] = PlaySound((int) D_8006C654->supercharge, 0, 4);
                Callback45Player.unk22[3] = (int) D_8006C654->supercharge;
            }

            return;
        case 0xA0:
        case 0xA1:
        case 0xA2:
        case 0xA3:
                Callback45Call80041C20();
                Callback45Call80042A44();
                zWord=&Callback45Player.position.z;
                __asm__("" : "=r"(zWord) : "0"(zWord));
                clampValue = Callback45HeightF4 + Callback45Player.unk4a;
                if (*zWord < clampValue) {
                    *zWord = clampValue;
                }
                Callback45Call80041930();
                if ((SpawnParticle != 0) && (Callback45Player.union144.b.unk148 != 0)) {
                    secondLimit = 1;
                    if (Callback45Player.union144.b.unk148 >= 2) {
                        secondLimit = 2;
                    }
                    iteration = 0;
                    if (secondLimit != 0) {
                        secondVector=&local.second;
                        __asm__("" : "=r"(secondVector), "=r"(zWord) : "0"(secondVector), "1"(zWord));
                        secondSource = (unsigned char*)zWord + 0x90;
                        do {
                            func_8004F178(secondVector, (Vector3D *) secondSource);
                            Callback45Call8004F110(secondVector, 7);
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
                        position=secondSource - 0x98;
                        vector=secondVector;
                        __asm__("" : "=r"(kind), "=r"(subtype), "=r"(position), "=r"(vector) : "0"(kind), "1"(subtype), "2"(position), "3"(vector), "r"(sample) : "$3", "$8", "memory");
                        sample &=254;
                        __asm__("" : "=r"(sample) : "0"(sample) : "$3", "$8", "memory");
                        component=local.second.z;
                        __asm__("" : "=r"(component) : "0"(component) : "$8", "memory");
                        particles=SpawnParticle;
                        __asm__("" : "=r"(particles), "=r"(component) : "0"(particles), "1"(component));
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        local.second.z=component;
                        particles(kind,subtype,(Vector3D*)position,vector);
                        } while (iteration < secondLimit);
                    }
                }
            goto clearSharedValue;

        default:return;
    }
clearSharedValue:
    Callback45Player.unk4[0]=0;
}


#define LEVEL_ID 45
#define PlaySpyroSounds_level_45 func_level_45_800882C8
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_level_45_800883D0(int index) {
    register int* state __asm__("$5");
    register int value __asm__("$3");
    register unsigned char* base __asm__("$2");
    register unsigned int offset __asm__("$4");
    offset = index * 16;
    __asm__("" : "=r"(offset) : "0"(offset) : "$2");
    base = D_8006E548;
    __asm__("" : "=r"(base) : "0"(base), "r"(offset) : "$5");
    state = &spyro.animationState;
    value = *state;
    __asm__("" : "=r"(value) : "0"(value) : "memory");
    offset = offset + (unsigned int)base;
    __asm__("" : "=r"(offset) : "0"(offset), "r"(value));
    D_8006C570 = (unsigned char*)offset;
    __asm__("" : : "r"(value) : "$2", "memory");
    if (value < 0x2D) {
        if (value >= 0x2B) goto vector;
        if (value == 0x19) goto other;
        if (value >= 0x1A) return;
        if (value == 0x14) goto vector;
        return;
    } else {
        if (value == 0x3D) goto vector;
        if (value >= 0x3E) return;
        if (value >= 0x38) return;
        if (value < 0x35) return;
    }
vector:
    __asm__("" : : "r"(value));
    func_80043ABC(&spyro.unk9e);
    return;
other:
    func_80043E00((Vector3D*)((char*)state + 0x44));
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80088484.
 * Reuses verified25/35 fly/surface/charge blocks. Original45 selector14
 * helper3636C(1,3) result stored144, zero148; A0..A3 shares fly entry but
 * retains pointers via original selector<A0 tail. Surface vector stack10.
 * Byte offsets, original stores/widths and sound selector22/7 retained.
 * Clamp7FF/800/4B00/4B01 ->800/800/4B00/4B00 before subsequent helpers.
 * Empty constraints emit no instructions. Every original code/internal jump/
 * owned word, strict full TU and every original EXE/overlay hash required.
 * Helpers, units, audio semantics, cadence and live parity remain open.
 */
int Call45_8003636C(int,int) __asm__("func_8003636C");
extern Spyro Transition45Player __asm__("D_80070328");
extern int D_80071934;
extern int Raw45Word __asm__("D_80070328+0x50");
extern unsigned char Raw45State[] __asm__("D_80070328+0x50");
extern unsigned char Raw45Union[] __asm__("D_80070328+0x144");
extern int Raw45Spit __asm__("D_80070328+0x170");
void Call45_8004F168(Vector3D*) __asm__("func_8004F168");
int Call45_8004EDE8(Vector3D*,int) __asm__("func_8004EDE8");
int Call45A358(Vector3D*,int) __asm__("func_8001A358");
void Call45_800441F0(void) __asm__("func_800441F0");
void Call45_80043A38(int) __asm__("func_80043A38");
void func_80047138(void);
void func_level_45_80088484(int arg0) {
    Vector3D surfaceVector;
    int vectorLength,surfaceResult;
    unsigned char soundSelector;
    register unsigned char* stateBase __asm__("$3");
    register int* spitWord __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* soundTable __asm__("$3");
    register int originalZ __asm__("$2");
    switch(arg0){
    case 0x14:
        Transition45Player.movementState=0;
        Transition45Player.unk5=0;
        Call45_800441F0();
        Transition45Player.grounded=1;
        Transition45Player.union144.a.unk13cb=Call45_8003636C(1,3);
        Transition45Player.union144.a.unk13cc=0;
        goto clearPointers;

    case 0x35:
        __asm__ volatile("" : : : "memory");
        goto standEntry;
    case 0x36:
standEntry:
        Transition45Player.movementState = MOVEMENT_STATE_STAND;
        Transition45Player.unk5 = 0;
        Call45_800441F0();
        Transition45Player.grounded = 1;
        goto clearPointers;

    case 0x19:
        soundZero=0;
        __asm__("" : "=r"(soundZero) : "0"(soundZero));
        soundTable=(unsigned char*)D_8006C654;
        __asm__("" : "=r"(soundTable) : "0"(soundTable));
        Transition45Player.movementState = MOVEMENT_STATE_SUPERCHARGE;
        Transition45Player.unk13a[0] = 0x60000;
        Transition45Player.unk5 = 0;
        Transition45Player.union144.a.unk13cb = 0;
        Transition45Player.grounded = 0;
        Transition45Player.unk15b = 1;
        soundSelector = soundTable[0x22];
playSharedSound:
        PlaySound((int) soundSelector, (Moby*)soundZero, 0);
        goto clearPointers;
    case 0xA0:case 0xA1:case 0xA2:case 0xA3:
    case 0x21:
    case 0x22:
    case 0x23: {
        register unsigned char* flyState __asm__("$17")=(unsigned char*)&Raw45Word;
        if(*(int*)flyState!=6) {
            *(int*)flyState=6;
            Transition45Player.unk5=0;
            Call45_8004F168((Vector3D*)(flyState+0x104));
            Transition45Player.union144.a.unk13db.y=0;
            vectorLength=Call45_8004EDE8((Vector3D*)(flyState+0x48),0);
            Transition45Player.unk8[0]=vectorLength;
            if(vectorLength<0x800)Transition45Player.unk8[0]=0x800;
            if(Transition45Player.unk8[0]>=0x4B01)Transition45Player.unk8[0]=0x4B00;
            Transition45Player.union144.a.unk13cb=0;
            Transition45Player.union144.b.unk148=0;
            Transition45Player.union144.a.unk13ce.x=0;
            Transition45Player.union144.a.unk13ce.y=0;
            Transition45Player.grounded=0;
            Transition45Player.unk15b=0;
        }
        if(arg0<0xA0)goto clearPointers;
        return;
    }
    case 0x2B:case 0x2C:{

        register unsigned char* unionPointer __asm__("$16");
        {register int stateWord __asm__("$3")=Raw45Word;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Raw45Union;
            *(int*)unionPointer=(-Transition45Player.unk7a[2].z)>>2;
            if(Raw45Word!=8){Transition45Player.union144.a.unk13cc=0x5900;Raw45Word=10;}
            Transition45Player.unk5=0;
            Transition45Player.unk8[0]=Call45_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition45Player.grounded=1;
            Transition45Player.unk15b=1;
            func_8004F178(&surfaceVector,(Vector3D*)(unionPointer-0x144));
            surfaceVector.z+=0x400;
            surfaceResult=Call45A358(&surfaceVector,0x800);
            surfaceVector.z=surfaceResult;
            if(surfaceResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,&surfaceVector,0);SpawnParticle(6,0x2E,&surfaceVector,0);}
        }
        }
        goto clearPointers;

    }

    case 0x37:
        originalZ=8;
        __asm__("" : "=r"(originalZ) : "0"(originalZ));
        Raw45Word=originalZ;
        __asm__ volatile("" : : : "memory");
        originalZ=Transition45Player.unk7a[2].z;
        __asm__("" : "=r"(originalZ) : "0"(originalZ));
        {register int flagValue __asm__("$3")=1;
        __asm__("" : "=r"(flagValue) : "0"(flagValue));
        Transition45Player.unk15b=flagValue;
        __asm__ volatile("" : : : "memory");}
        soundTable=(unsigned char*)D_8006C654;
        __asm__("" : "=r"(soundTable) : "0"(soundTable));
        Transition45Player.union144.a.unk13cc = 0;
        Transition45Player.unk5 = 0;
        Transition45Player.grounded = 0;
        __asm__ volatile("" : "=r"(originalZ) : "0"(originalZ) : "memory");
        Transition45Player.union144.a.unk13cb = -originalZ >> 2;
        soundSelector = soundTable[7];
        soundZero=0;
        goto playSharedSound;
    case 0x3D:
        stateBase=Raw45State;
        *(int*)stateBase = MOVEMENT_STATE_SUPERCHARGE;
        Transition45Player.unk5 = 0;
        Transition45Player.unk13a[0] = 0x60000;
        Transition45Player.unk8[0] = Call45_8004EDE8((Vector3D *) (stateBase + 0x48), 0);
        Transition45Player.horizontalSpeed = 0x1E80;
        Call45_80043A38(0xC00);
        Transition45Player.grounded = 1;
        if ((Transition45Player.unk13f[0] != 0) || (Transition45Player.spitState != 0) || (Transition45Player.unk17t != 6)) {
            spitWord=&Raw45Spit;
            if (((unsigned) (*spitWord - 3) < 2U) || (*spitWord == 5)) {
                *spitWord = 5;
            } else {
                *spitWord = 0;
            }
            Transition45Player.spitState = 0;
            Transition45Player.unk17t = 6;
            func_80047138();
        }
clearPointers:
        Transition45Player.unk20a=0;
        Transition45Player.critterMobyPtr=0;
        return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_45/animation", func_level_45_80088960);
