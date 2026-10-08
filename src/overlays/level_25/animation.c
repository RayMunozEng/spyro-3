#include "common.h"
#include "ovl_header.h"
#include "drawutil.h"
#include "spu.h"
#include "hud.h"
#include "mobyutil.h"
#include "stdutil.h"
#include "camera.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_25/animation", func_level_25_800870B4);

extern Spyro Callback25Player __asm__("D_80070328");
int Callback25_80037058(int x, int y) __asm__("func_80037058");
int Callback25_8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback25_80041930(void) __asm__("func_80041930");
void Callback25_80041AE8(void) __asm__("func_80041AE8");
void Callback25_80041C20(void) __asm__("func_80041C20");
void Callback25_80042A44(void) __asm__("func_80042A44");
void Callback25_80043A38(int scale) __asm__("func_80043A38");
void Callback25_80049590(void) __asm__("func_80049590");
void Callback25_8004F110(Vector3D*, int) __asm__("func_8004F110");
extern int Callback25_8006E344 __asm__("D_8006E344");
extern int Callback25_8006E52C __asm__("D_8006E52C");
extern int Callback25_8006E530 __asm__("D_8006E530");
extern int Callback25_8006E538 __asm__("D_8006E538");

/* AI-generated; not human reviewed. Original numeric callback and byte addresses. */
void func_level_25_80087F34(void) {
    struct { Vector3D value; int reserved[2]; } local;
    register int sample __asm__("$2");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    unsigned char *sourceBytes;
    int value;
    register int iteration __asm__("$16");
    register int iterationLimit __asm__("$17");

    switch (Callback25Player.animationState) {
    case 0x35:
    case 0x36:
        Callback25_80041C20();
        Callback25_80042A44();
block_3:
        Callback25Player.unk4[0]  =  0;
        return;
    case 0x19:
        Callback25_80041C20();
        Callback25_80042A44();
        Callback25_80041930();
        Callback25_80049590();
        if ((Callback25Player.movementState == MOVEMENT_STATE_SUPERCHARGE) && (SpawnParticle != 0)) {
            SpawnParticle(1, 9, 0, 0);
        }
        if ((Callback25Player.unk7a[3].z < 0) && (Callback25Player.animationStateFrames >= 4)) {
            Callback25Player.unk5  =  1;
        } else if ((Callback25Player.unk5 == 0) && !(Callback25_8006E538 & 0x40)) {
            Callback25Player.unk5  =  2;
        }
        goto block_3;
    case 0x21:
    case 0x22:
    case 0x23:
        Callback25_80041C20();
        Callback25_80042A44();
        Callback25_80041930();
        if ((SpawnParticle != 0) && (Callback25Player.union144.b.unk148 != 0)) {
            iterationLimit  =  1;
            if (Callback25Player.union144.b.unk148 >= 2) {
                iterationLimit  =  2;
            }
            iteration  =  0;
            if (iterationLimit != 0) {
                sourceBytes  =  (unsigned char*)&Callback25Player.union144.a.unk13cc - 0xB0;
                do {
                    func_8004F178(&local.value, (Vector3D *) sourceBytes);
                    Callback25_8004F110(&local.value, 7);
                    iteration +=  1;
                    sample = rand();
                    component = local.value.x;
                    sample&= 254;
                    component-= 127;
                    component  =  component + sample;
                    __asm__("" : "=r"(component) : "0"(component));
                    local.value.x  =  component;
                    sample = rand();
                    component = local.value.y;
                    sample&= 254;
                    component-= 127;
                    component  =  component + sample;
                    __asm__("" : "=r"(component) : "0"(component));
                    local.value.y  =  component;
                    sample = rand();
                    kind = 1;
                    subtype = 23;
                    position = sourceBytes - 152;
                    vector = &local.value;
                    __asm__("" : "=r"(sample) : "0"(sample), "r"(kind), "r"(subtype), "r"(position), "r"(vector));
                    sample&= 254;
                    component = local.value.z;
                    component-= 127;
                    component = component + sample;

                    local.value.z = component;
                    SpawnParticle(kind, subtype, (Vector3D*)position, vector);
                } while (iteration < iterationLimit);
            }
        }
        goto block_3;
    case 0x2B:
    case 0x2C:
    case 0x37:
        Callback25_80041C20();
        Callback25_80042A44();
        Callback25_80041AE8();
        if ((unsigned char) Callback25Player.unk10[4] != 0) {
            value  =  -Callback25Player.unk9ha[4] - Callback25_80037058(Callback25Player.position.x, Callback25Player.position.y);
            Callback25Player.unk4[0]  =  value;
            Callback25Player.position.z  =  (Callback25Player.unk4a - value) - ((int) Callback25Player.union144.a.unk13cc >> 6);
            return;
        }
    default:
        return;
    case 0x3D:
        Callback25_80041C20();
        Callback25_80042A44();
        Callback25_80043A38(0xC00);
        Callback25_80049590();
        if (SpawnParticle != 0) {
            SpawnParticle(1, 9, 0, 0);
        }
        Callback25_8006E530  =  0x78;
        Callback25Player.unk4[0]  =  0;
        Callback25_8006E52C  =  4;
        if ((Callback25_8006E344 == 0) && (Callback25_8003BF6C((int) D_8006C654->supercharge, Callback25Player.unk22[2]) == 0)) {
            Callback25Player.unk22[2]  =  PlaySound((int) D_8006C654->supercharge, 0, 4);
            Callback25Player.unk22[3]  =  (int) D_8006C654->supercharge;
        }
        break;
    }
}


#define LEVEL_ID 25
#define PlaySpyroSounds_level_25 func_level_25_800882C4
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_level_25_800883CC(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x2B: case 0x2C: case 0x35: case 0x36: case 0x37: case 0x3D:
        func_80043ABC(&spyro.unk9e);break;
    case 0x19:
        func_80043E00((Vector3D*)((char*)&spyro+0x8C));break;
case 0x1a: case 0x1b: case 0x1c: case 0x1d: case 0x1e: case 0x1f: case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2d: case 0x2e: case 0x2f: case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80088454.
 * Reuses verified10 fly clamp800/4B00 and23 surface stack10; original25
 * selectors19/37 share the original sound call after19, selector3D preserves
 * word170 reload and selector<A0 pointer clearing. Offsets are bytes. Exact
 * code/internal jumps/owned dispatch words, complete TU and every retail hash
 * required. Helpers, physical units, audio meaning, cadence and live parity open.
 * Clamp vectors7FF/800/4B00/4B01 yield800/800/4B00/4B00 before later helpers.
 */
extern Spyro Transition25Player __asm__("D_80070328");
extern int D_80071934;
extern int Raw25Word __asm__("D_80070328+0x50");
extern unsigned char Raw25State[] __asm__("D_80070328+0x50");
extern unsigned char Raw25Union[] __asm__("D_80070328+0x144");
extern int Raw25Spit __asm__("D_80070328+0x170");
void Call25_8004F168(Vector3D*) __asm__("func_8004F168");
int Call25_8004EDE8(Vector3D*,int) __asm__("func_8004EDE8");
int Call25A358(Vector3D*,int) __asm__("func_8001A358");
void Call25_800441F0(void) __asm__("func_800441F0");
void Call25_80043A38(int) __asm__("func_80043A38");
void func_80047138(void);
void func_level_25_80088454(int arg0) {
    Vector3D surfaceVector;
    int vectorLength;
    int surfaceResult;
    unsigned char soundSelector;
    register unsigned char* stateBase __asm__("$3");
    register int* spitWord __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* soundTable __asm__("$3");
    register int originalZ __asm__("$2");

    switch (arg0) {
    case 0x35:
    case 0x36:
        Transition25Player.movementState = MOVEMENT_STATE_STAND;
        Transition25Player.unk5 = 0;
        Call25_800441F0();
        Transition25Player.grounded = 1;
        goto clearPointers;
    case 0x19:
        soundZero=0;
        __asm__("" : "=r"(soundZero) : "0"(soundZero));
        soundTable=(unsigned char*)D_8006C654;
        __asm__("" : "=r"(soundTable) : "0"(soundTable));
        Transition25Player.movementState = MOVEMENT_STATE_SUPERCHARGE;
        Transition25Player.unk13a[0] = 0x60000;
        Transition25Player.unk5 = 0;
        Transition25Player.union144.a.unk13cb = 0;
        Transition25Player.grounded = 0;
        Transition25Player.unk15b = 1;
        soundSelector = soundTable[0x22];
playSharedSound:
        PlaySound((int) soundSelector, (Moby*)soundZero, 0);
        goto clearPointers;
    case 0x21:
    case 0x22:
    case 0x23: {
        register unsigned char* flyState __asm__("$16")=(unsigned char*)&Raw25Word;
        if(*(int*)flyState!=6) {
            *(int*)flyState=6;
            Transition25Player.unk5=0;
            Call25_8004F168((Vector3D*)(flyState+0x104));
            Transition25Player.union144.a.unk13db.y=0;
            vectorLength=Call25_8004EDE8((Vector3D*)(flyState+0x48),0);
            Transition25Player.unk8[0]=vectorLength;
            if(vectorLength<0x800)Transition25Player.unk8[0]=0x800;
            if(Transition25Player.unk8[0]>=0x4B01)Transition25Player.unk8[0]=0x4B00;
            Transition25Player.union144.a.unk13cb=0;
            Transition25Player.union144.b.unk148=0;
            Transition25Player.union144.a.unk13ce.x=0;
            Transition25Player.union144.a.unk13ce.y=0;
            Transition25Player.grounded=0;
            Transition25Player.unk15b=0;
        }
        if(arg0<0xA0)goto clearPointers;
        return;
    }
    case 0x2B:case 0x2C: {
        register unsigned char* unionPointer __asm__("$16");
        {register int stateWord __asm__("$3")=Raw25Word;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Raw25Union;
            *(int*)unionPointer=(-Transition25Player.unk7a[2].z)>>2;
            if(Raw25Word!=8){Transition25Player.union144.a.unk13cc=0x5900;Raw25Word=10;}
            Transition25Player.unk5=0;
            Transition25Player.unk8[0]=Call25_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition25Player.grounded=1;
            Transition25Player.unk15b=1;
            func_8004F178(&surfaceVector,(Vector3D*)(unionPointer-0x144));
            surfaceVector.z+=0x400;
            surfaceResult=Call25A358(&surfaceVector,0x800);
            surfaceVector.z=surfaceResult;
            if(surfaceResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,&surfaceVector,0);SpawnParticle(6,0x2E,&surfaceVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x37:
        originalZ=8;
        __asm__("" : "=r"(originalZ) : "0"(originalZ));
        Raw25Word=originalZ;
        __asm__ volatile("" : : : "memory");
        originalZ=Transition25Player.unk7a[2].z;
        __asm__("" : "=r"(originalZ) : "0"(originalZ));
        {register int flagValue __asm__("$3")=1;
        __asm__("" : "=r"(flagValue) : "0"(flagValue));
        Transition25Player.unk15b=flagValue;
        __asm__ volatile("" : : : "memory");}
        soundTable=(unsigned char*)D_8006C654;
        __asm__("" : "=r"(soundTable) : "0"(soundTable));
        Transition25Player.union144.a.unk13cc = 0;
        Transition25Player.unk5 = 0;
        Transition25Player.grounded = 0;
        __asm__ volatile("" : "=r"(originalZ) : "0"(originalZ) : "memory");
        Transition25Player.union144.a.unk13cb = -originalZ >> 2;
        soundSelector = soundTable[7];
        soundZero=0;
        goto playSharedSound;
    case 0x3D:
        stateBase=Raw25State;
        *(int*)stateBase = MOVEMENT_STATE_SUPERCHARGE;
        Transition25Player.unk5 = 0;
        Transition25Player.unk13a[0] = 0x60000;
        Transition25Player.unk8[0] = Call25_8004EDE8((Vector3D *) (stateBase + 0x48), 0);
        Transition25Player.horizontalSpeed = 0x1E80;
        Call25_80043A38(0xC00);
        Transition25Player.grounded = 1;
        if ((Transition25Player.unk13f[0] != 0) || (Transition25Player.spitState != 0) || (Transition25Player.unk17t != 6)) {
            spitWord=&Raw25Spit;
            if (((unsigned) (*spitWord - 3) < 2U) || (*spitWord == 5)) {
                *spitWord = 5;
            } else {
                *spitWord = 0;
            }
            Transition25Player.spitState = 0;
            Transition25Player.unk17t = 6;
            func_80047138();
        }
clearPointers:
        Transition25Player.unk20a=0;
        Transition25Player.critterMobyPtr=0;
        return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_25/animation", func_level_25_80088868);
