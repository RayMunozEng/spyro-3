#include "common.h"
#include "camera.h"
#include "mobyutil.h"
#include "spu.h"
#include "hud.h"
#include "drawutil.h"
#include "stdutil.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_15/animation", func_level_15_80086D54);

extern Spyro Callback15Player __asm__("D_80070328");
int Callback15_80037058(int x, int y) __asm__("func_80037058");
int Callback15_8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback15_80041930(void) __asm__("func_80041930");
void Callback15_80041AE8(void) __asm__("func_80041AE8");
void Callback15_80041C20(void) __asm__("func_80041C20");
void Callback15_80042A44(void) __asm__("func_80042A44");
void Callback15_80043A38(int scale) __asm__("func_80043A38");
void Callback15_80049590(void) __asm__("func_80049590");
void Callback15_8004F110(Vector3D*, int) __asm__("func_8004F110");
extern int Callback15_8006E344 __asm__("D_8006E344");
extern int Callback15_8006E52C __asm__("D_8006E52C");
extern int Callback15_8006E530 __asm__("D_8006E530");
extern int Callback15_8006E538 __asm__("D_8006E538");
void func_level_15_800882B8(void) {
    struct { Vector3D value; int reserved[2]; } local;
    register int sample __asm__("$2");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    unsigned char *sourceBytes;
    register int value __asm__("$4");
    register int height __asm__("$3");
    register int iteration __asm__("$16");
    register int iterationLimit __asm__("$17");

    switch (Callback15Player.animationState) {
    case 0x35:
    case 0x36:
    case 0xB0:
        Callback15_80041C20();
        Callback15_80042A44();
        goto clearValue;
    case 0x19:
        Callback15_80041C20();
        Callback15_80042A44();
        Callback15_80041930();
        Callback15_80049590();
        if ((Callback15Player.movementState == MOVEMENT_STATE_SUPERCHARGE) && (SpawnParticle != 0)) {
            SpawnParticle(1, 9, 0, 0);
        }
        if ((Callback15Player.unk7a[3].z < 0) && (Callback15Player.animationStateFrames >= 4)) {
            Callback15Player.unk5 = 1;
        } else if ((Callback15Player.unk5 == 0) && !(Callback15_8006E538 & 0x40)) {
            Callback15Player.unk5 = 2;
        }
        goto clearValue;
    case 0x21:
    case 0x22:
    case 0x23:
        Callback15_80041C20();
        Callback15_80042A44();
        Callback15_80041930();
        if ((SpawnParticle != 0) && (Callback15Player.union144.b.unk148 != 0)) {
            iterationLimit = 1;
            if (Callback15Player.union144.b.unk148 >= 2) {
                iterationLimit = 2;
            }
            iteration = 0;
            if (iterationLimit != 0) {
                sourceBytes = (unsigned char*)&Callback15Player.union144.a.unk13cc - 0xB0;
                do {
                    func_8004F178(&local.value, (Vector3D *) sourceBytes);
                    Callback15_8004F110(&local.value, 7);
                    iteration += 1;
                    sample = rand();
                    component = local.value.x;
                    sample &=  254;
                    component -=  127;
                    component = component + sample;
                    __asm__("" : "=r"(component) : "0"(component));
                    local.value.x = component;
                    sample = rand();
                    component = local.value.y;
                    sample &=  254;
                    component -=  127;
                    component = component + sample;
                    __asm__("" : "=r"(component) : "0"(component));
                    local.value.y = component;
                    sample = rand();
                    kind = 1;
                    subtype = 23;
                    position = sourceBytes - 152;
                    vector = &local.value;
                    __asm__("" : "=r"(sample) : "0"(sample), "r"(kind), "r"(subtype), "r"(position), "r"(vector));
                    sample &=  254;
                    component = local.value.z;
                    component -=  127;
                    component = component + sample;

                    local.value.z = component;
                    SpawnParticle(kind, subtype, (Vector3D*)position, vector);
                } while (iteration < iterationLimit);
            }
        }
        goto clearValue;
    case 0x2B:
    case 0x2C:
    case 0x37:
        Callback15_80041C20();
        Callback15_80042A44();
        Callback15_80041AE8();
        if ((unsigned char) Callback15Player.unk10[4] != 0) {
            sample = Callback15_80037058(Callback15Player.position.x, Callback15Player.position.y);
            value = Callback15Player.unk9ha[4];
            height = Callback15Player.unk4a;
            __asm__("" : "=r"(value), "=r"(height) : "0"(value), "1"(height), "r"(sample));
            value = -value - sample;
            sample = (int)Callback15Player.union144.a.unk13cc;
            height -= value;
            Callback15Player.unk4[0] = value;
            sample >>= 6;
            height -= sample;
            Callback15Player.position.z = height;

            return;
        }
    default:
        return;
    case 0x3D:
        Callback15_80041C20();
        Callback15_80042A44();
        Callback15_80043A38(0xC00);
        Callback15_80049590();
        if (SpawnParticle != 0) {
            SpawnParticle(1, 9, 0, 0);
        }
        Callback15_8006E530 = 0x78;
        Callback15Player.unk4[0] = 0;
        Callback15_8006E52C = 4;
        if ((Callback15_8006E344 == 0) && (Callback15_8003BF6C((int) D_8006C654->supercharge, Callback15Player.unk22[2]) == 0)) {
            Callback15Player.unk22[2] = PlaySound((int) D_8006C654->supercharge, 0, 4);
            Callback15Player.unk22[3] = (int) D_8006C654->supercharge;
        }
        break;
    case 0xAF:
        Callback15_80041C20();
        Callback15_80042A44();
        value = Callback15Player.unk9ha[4];
        height = Callback15Player.unk4a;
        sample = Callback15Player.position.z;
        __asm__("" : "=r"(value), "=r"(height), "=r"(sample) : "0"(value), "1"(height), "2"(sample));
        value = value + height;
        if (sample < value) Callback15Player.position.z = value;
        Callback15_80041930();
clearValue:
        Callback15Player.unk4[0] = 0;
        return;
    }
}


#define LEVEL_ID 15
#define PlaySpyroSounds_level_15 func_level_15_800886FC
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_level_15_80088804(int index) {
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
        return;
    } else {
        if (value == 0x3D) goto vector;
        if (value >= 0x3E) {
            if (value == 0xAF) return;
            if (value == 0xB0) goto reset;
            return;
        }
        if (value >= 0x38) return;
        if (value < 0x35) return;
    }
vector:
    __asm__("" : : "r"(value));
    func_80043ABC(&spyro.unk9e);
    return;
reset:
    func_80043ABC(0);
    return;
other:
    func_80043E00((Vector3D*)((char*)state + 0x44));
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 800888D4.
 * Reuses verified25/35 fly/surface/charge; original15 AF shares fly with
 * preserved<A0 pointer tail; B0 state8/ground1/timer15 retains pointers.
 * Offsets are bytes, original widths and sound selector22/7 retained.
 * Clamp7FF/800/4B00/4B01 ->800/800/4B00/4B00 before subsequent helpers.
 * Empty constraints emit no instructions. All original code/internal jumps/
 * owned words, strict complete TU and every retail hash required. Helpers,
 * physical units, audio semantics, cadence and live runtime parity remain open.
 */
extern Spyro Transition15Player __asm__("D_80070328");
extern int D_80071934;
extern int Raw15Word __asm__("D_80070328+0x50");
extern unsigned char Raw15State[] __asm__("D_80070328+0x50");
extern unsigned char Raw15Union[] __asm__("D_80070328+0x144");
extern int Raw15Spit __asm__("D_80070328+0x170");
void Call15_8004F168(Vector3D*) __asm__("func_8004F168");
int Call15_8004EDE8(Vector3D*,int) __asm__("func_8004EDE8");
int Call15A358(Vector3D*,int) __asm__("func_8001A358");
void Call15_800441F0(void) __asm__("func_800441F0");
void Call15_80043A38(int) __asm__("func_80043A38");
void func_80047138(void);
extern int Transition15DamageTimer __asm__("D_8006E524");
void func_level_15_800888D4(int arg0) {
    Vector3D surfaceVector;
    int vectorLength,surfaceResult;
    unsigned char soundSelector;
    register unsigned char* stateBase __asm__("$3");
    register int* spitWord __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* soundTable __asm__("$3");
    register int originalZ __asm__("$2");
    switch(arg0){
    case 0x35:
        __asm__ volatile("" : : : "memory");
        goto standEntry;
    case 0x36:
standEntry:
        Transition15Player.movementState = MOVEMENT_STATE_STAND;
        Transition15Player.unk5 = 0;
        Call15_800441F0();
        Transition15Player.grounded = 1;
        goto clearPointers;

    case 0x19:
        soundZero=0;
        __asm__("" : "=r"(soundZero) : "0"(soundZero));
        soundTable=(unsigned char*)D_8006C654;
        __asm__("" : "=r"(soundTable) : "0"(soundTable));
        Transition15Player.movementState = MOVEMENT_STATE_SUPERCHARGE;
        Transition15Player.unk13a[0] = 0x60000;
        Transition15Player.unk5 = 0;
        Transition15Player.union144.a.unk13cb = 0;
        Transition15Player.grounded = 0;
        Transition15Player.unk15b = 1;
        soundSelector = soundTable[0x22];
playSharedSound:
        PlaySound((int) soundSelector, (Moby*)soundZero, 0);
        goto clearPointers;
    case 0xAF:
    case 0x21:
    case 0x22:
    case 0x23: {
        register unsigned char* flyState __asm__("$17")=(unsigned char*)&Raw15Word;
        if(*(int*)flyState!=6) {
            *(int*)flyState=6;
            Transition15Player.unk5=0;
            Call15_8004F168((Vector3D*)(flyState+0x104));
            Transition15Player.union144.a.unk13db.y=0;
            vectorLength=Call15_8004EDE8((Vector3D*)(flyState+0x48),0);
            Transition15Player.unk8[0]=vectorLength;
            if(vectorLength<0x800)Transition15Player.unk8[0]=0x800;
            if(Transition15Player.unk8[0]>=0x4B01)Transition15Player.unk8[0]=0x4B00;
            Transition15Player.union144.a.unk13cb=0;
            Transition15Player.union144.b.unk148=0;
            Transition15Player.union144.a.unk13ce.x=0;
            Transition15Player.union144.a.unk13ce.y=0;
            Transition15Player.grounded=0;
            Transition15Player.unk15b=0;
        }
        if(arg0<0xA0)goto clearPointers;
        return;
    }
    case 0x2B:case 0x2C:{

        register unsigned char* unionPointer __asm__("$16");
        {register int stateWord __asm__("$3")=Raw15Word;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Raw15Union;
            *(int*)unionPointer=(-Transition15Player.unk7a[2].z)>>2;
            if(Raw15Word!=8){Transition15Player.union144.a.unk13cc=0x5900;Raw15Word=10;}
            Transition15Player.unk5=0;
            Transition15Player.unk8[0]=Call15_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition15Player.grounded=1;
            Transition15Player.unk15b=1;
            func_8004F178(&surfaceVector,(Vector3D*)(unionPointer-0x144));
            surfaceVector.z+=0x400;
            surfaceResult=Call15A358(&surfaceVector,0x800);
            surfaceVector.z=surfaceResult;
            if(surfaceResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,&surfaceVector,0);SpawnParticle(6,0x2E,&surfaceVector,0);}
        }
        }
        goto clearPointers;

    }

    case 0x37:
        originalZ=8;
        __asm__("" : "=r"(originalZ) : "0"(originalZ));
        Raw15Word=originalZ;
        __asm__ volatile("" : : : "memory");
        originalZ=Transition15Player.unk7a[2].z;
        __asm__("" : "=r"(originalZ) : "0"(originalZ));
        {register int flagValue __asm__("$3")=1;
        __asm__("" : "=r"(flagValue) : "0"(flagValue));
        Transition15Player.unk15b=flagValue;
        __asm__ volatile("" : : : "memory");}
        soundTable=(unsigned char*)D_8006C654;
        __asm__("" : "=r"(soundTable) : "0"(soundTable));
        Transition15Player.union144.a.unk13cc = 0;
        Transition15Player.unk5 = 0;
        Transition15Player.grounded = 0;
        __asm__ volatile("" : "=r"(originalZ) : "0"(originalZ) : "memory");
        Transition15Player.union144.a.unk13cb = -originalZ >> 2;
        soundSelector = soundTable[7];
        soundZero=0;
        goto playSharedSound;
    case 0x3D:
        stateBase=Raw15State;
        *(int*)stateBase = MOVEMENT_STATE_SUPERCHARGE;
        Transition15Player.unk5 = 0;
        Transition15Player.unk13a[0] = 0x60000;
        Transition15Player.unk8[0] = Call15_8004EDE8((Vector3D *) (stateBase + 0x48), 0);
        Transition15Player.horizontalSpeed = 0x1E80;
        Call15_80043A38(0xC00);
        Transition15Player.grounded = 1;
        if ((Transition15Player.unk13f[0] != 0) || (Transition15Player.spitState != 0) || (Transition15Player.unk17t != 6)) {
            spitWord=&Raw15Spit;
            if (((unsigned) (*spitWord - 3) < 2U) || (*spitWord == 5)) {
                *spitWord = 5;
            } else {
                *spitWord = 0;
            }
            Transition15Player.spitState = 0;
            Transition15Player.unk17t = 6;
            func_80047138();
        }
clearPointers:
        Transition15Player.unk20a=0;
        Transition15Player.critterMobyPtr=0;
        return;
    case 0xB0:
        originalZ=8;
        __asm__("" : "=r"(originalZ) : "0"(originalZ));
        Raw15Word=originalZ;
        Transition15Player.unk5=0;
        Call15_80043A38(0xC00);
        Transition15Player.grounded=1;
        Transition15DamageTimer=15;
        return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_15/animation", func_level_15_80088D88);
