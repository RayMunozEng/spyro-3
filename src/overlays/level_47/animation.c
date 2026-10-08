#include "common.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_47/animation", func_level_47_8008BBD8);

/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * 8008CABC..8008CC44, 98 original instructions plus dispatch.
 * Baseline verified level27_8008874C; original modes19/27/60 retained.
 * Byte colors and word stores preserve widths. Semantic labels, helper
 * identities, input producers and caller cadence remain unresolved.
 * Test: original linked code/dispatch words and complete retail hashes.
 */
void func_level_47_8008CABC(void) {
    switch (spyro.animationState) {
    case 0x14:
        if (func_800438F4() == 0) {
            func_80043728();
        }
        func_80041C20();
        spyro.unk9a = 0;
        func_80042A44();
        goto clearWord28;
    case 0x1D:
        func_80041C20();
        func_80042A44();
        func_80043A38(0xC00);
        goto clearWord28;
    case 0x13:
        func_80041C20();
        func_80042A44();
        goto run41930;
    case 0x1C:
        func_80041C20();
        func_80042A44();
        func_80041930();
        if ((spyro.unk7a[3].z < 0) && (spyro.animationStateFrames >= 4)) {
            spyro.unk5 = 1;
        }
        goto clearWord28;
    case 0x3A:
        func_80041C20();
        func_80042A44();
        spyro.cheatColour.a = 0xFF;
        spyro.unk4[0] = 0;
        spyro.cheatColour.b = 0x20;
        spyro.cheatColour.g = 0x20;
        spyro.cheatColour.r = 0x20;
        return;

    case 0x1B:
    case 0x3C:
        func_80041C20();
        func_80042A44();
        if (spyro.movementState != 6) goto clearWord28;
run41930:
        func_80041930();
clearWord28:
        spyro.unk4[0] = 0;
        return;
    default:
        return;
    }
}

#define LEVEL_ID 47
#define PlaySpyroSounds_level_47 func_level_47_8008CC44
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_47_8008CD4C(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x14:
    case 0x1D:
    case 0x3A:
        func_80043ABC(&spyro.unk9e);
        break;
    case 0x1B:
    case 0x3C:
        if (*(int*)((char*)&spyro + 0x50) == 6) break;
    case 0x13:
    case 0x1C:
        func_80043ABC(0);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 8008CDDC..8008D2F0.
 * Baselines: verified level31_8008DEC0 case1D register/load-delay chain
 * and level27_80088AE4 case1C numeric pointer producers.
 * Original47 supplies case13's S1/S0/A2/A1/V0/V3/A0 chain, private words0/4/8,
 * signed shifts10, numeric pointer offsets and the remaining selector scope.
 * Empty lifetime constraints retain original loads/stores and independent calls;
 * otherwise unused V0 call results establish no helper-return meaning.
 * Source units/producers, audio semantics, helper contracts and caller cadence
 * remain open. Acceptance requires all original linked code/table words and
 * every complete retail EXE/overlay hash. Runtime/browser parity is not proved.
 */
extern Spyro Callback47_D_80070328 __asm__("D_80070328");
int Callback47_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
int Callback47_func_8003636C(int low, int high) __asm__("func_8003636C");
void Callback47_func_80043A38(int scale) __asm__("func_80043A38");
void Callback47_func_800441F0(void) __asm__("func_800441F0");
void Callback47_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Callback47_D_8006E524 __asm__("D_8006E524");
extern unsigned char Raw47Union[] __asm__("D_80070328+0x144");
extern int Raw47Movement __asm__("D_80070328+0x50");
void func_level_47_8008CDDC(int selector) {
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");
    register int oldMovement __asm__("$4");
    register int shiftedZ __asm__("$2");

    int deltaValue;

    short classValue;
    int lengthResult;

    int shiftedValue;
    int maskedValue;
    register unsigned char* privateData __asm__("$16");

    switch (selector) {
    case 0x14:
        Callback47_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback47_D_80070328.unk5 = 0;
        Callback47_func_800441F0();
        Callback47_D_80070328.grounded = 1;
        Callback47_D_80070328.union144.a.unk13cb = Callback47_func_8003636C(1, 3);
        Callback47_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        privateData = Callback47_D_80070328.m_WhirlwindPointer->mobyTag;
        Callback47_D_80070328.movementState = MOVEMENT_STATE_WHIRLWIND;
        Callback47_D_80070328.unk5 = 0;
        Callback47_D_80070328.grounded = 0;
        Callback47_func_8004F168((Vector3D *) ((unsigned char*)&Callback47_D_80070328.movementState + 0x3C));
        sourceMoby=Callback47_D_80070328.m_WhirlwindPointer;
        yawValue=Callback47_D_80070328.rotation.yaw;
        positionZ=Callback47_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Callback47_D_80070328.union144.a.unk13cc=yawValue;
        Callback47_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Callback47_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Callback47_D_80070328.union144.a.unk13ce.z=heightValue;
        deltaValue=heightValue;
        shiftedValue = ((int) (deltaValue << 0xA) >> 0xA) + 0x400;
        Callback47_D_80070328.union144.a.unk13ce.y = shiftedValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - shiftedValue) & 0xFFF;
        Callback47_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Callback47_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Callback47_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) ((unsigned char*)&Callback47_D_80070328.movementState + 0x10C), &sourceMoby->position);
        Callback47_D_80070328.unk13e[0] = (int) Callback47_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Callback47_D_80070328.unk20a = 0;
        Callback47_D_80070328.critterMobyPtr = 0;
        Callback47_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x1D: {
        register int component __asm__("$3");
        register int word __asm__("$2");
        oldMovement=Raw47Movement;
        component=Callback47_D_80070328.unk17e.x;
        __asm__("" : "=r"(oldMovement), "=r"(component) : "0"(oldMovement), "1"(component));
        word=7;
        Raw47Movement=word;
        word=Callback47_D_80070328.unk17e.y;
        Callback47_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(component), "=r"(word) : "0"(component), "1"(word) : "memory");
        component<<=6;
        Callback47_D_80070328.unk7a[2].x=component;
        component=Callback47_D_80070328.unk17e.z;
        __asm__ volatile("" : "=r"(word) : "0"(word) : "memory");
        word<<=6;
        __asm__("" : "=r"(word) : "0"(word));
        *(int*)Raw47Union=oldMovement;
        Callback47_D_80070328.unk7a[2].y=word;
        shiftedZ=component<<6;
        if(component==0)shiftedZ=Callback47_D_80070328.unk7a[3].z;
        Callback47_D_80070328.unk7a[2].z=shiftedZ;
        Callback47_func_80043A38(0xC00);
        Callback47_D_80070328.grounded = 1;
        Callback47_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        {register int soundResult __asm__("$2")=PlaySound((int)D_8006C654->spyroHurt,0,0);
        __asm__ volatile("" : : "r"(soundResult) : "$4");}
        goto clearPointers;
    }
    case 0x1C:
        savedBase = Raw47Union;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Raw47Movement;
        Raw47Movement = MOVEMENT_STATE_HURT;
        Callback47_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Callback47_D_80070328.unk8[0] = Callback47_func_8004EDE8(sourceC, 0);
        Callback47_D_80070328.unk7a[2].z = 0xDC0;
        Callback47_D_80070328.grounded = 0;
        Callback47_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Callback47_D_80070328.damageFlags & 0x200) {
            Callback47_D_80070328.union144.a.unk13cc = 0;
        } else {
            Callback47_D_80070328.union144.a.unk13cc = 1;
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        goto clearPointers;
    case 0x3A:
        Callback47_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Callback47_D_80070328.unk5 = 0;
        Callback47_func_80043A38(0xC00);
        Callback47_D_80070328.grounded = 1;
        if ((selector == 0x3A) || (selector == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Callback47_D_8006E524 = 0xF;
clearPointers:
        Callback47_D_80070328.unk20a=0;
        Callback47_D_80070328.critterMobyPtr=0;
        return;
    case 0x1B:
    case 0x3C:
        if ((Callback47_D_80070328.critterMobyPtr != 0) && ((classValue = Callback47_D_80070328.critterMobyPtr->mobyClass, (classValue == 0x2F5)) || (classValue == 0xF0))) {
            if (Callback47_D_80070328.movementState != MOVEMENT_STATE_SUPERFLY) {
                Callback47_D_80070328.movementState = MOVEMENT_STATE_SUPERFLY;
                Callback47_D_80070328.unk5 = 0;
                Callback47_func_8004F168((Vector3D *) ((unsigned char*)&Callback47_D_80070328.critterMobyPtr - 0xFC));
                Callback47_D_80070328.union144.a.unk13db.y = 0;
                lengthResult = Callback47_func_8004EDE8((Vector3D *) ((unsigned char*)&Callback47_D_80070328.critterMobyPtr - 0x1B8), 0);
                Callback47_D_80070328.unk8[0] = lengthResult;
                if (lengthResult < 0x800) {
                    Callback47_D_80070328.unk8[0] = 0x800;
                }
                if (Callback47_D_80070328.unk8[0] >= 0x4B01) {
                    Callback47_D_80070328.unk8[0] = 0x4B00;
                }
                Callback47_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                Callback47_D_80070328.union144.b.unk148 = 0;
                Callback47_D_80070328.union144.a.unk13ce.x = 0;
                Callback47_D_80070328.union144.a.unk13ce.y = 0;
                Callback47_D_80070328.grounded = 0;
                Callback47_D_80070328.unk15b = 0;
                return;
            }
        } else {
            Callback47_D_80070328.movementState = MOVEMENT_STATE_UNK_12;
            Callback47_D_80070328.unk5 = 0;
            Callback47_D_80070328.unk8[0] = Callback47_func_8004EDE8((Vector3D *) ((unsigned char*)&Callback47_D_80070328.movementState + 0x48), 0);
            Callback47_D_80070328.grounded = 1;
            Callback47_func_80043A38(0xC00);
            Callback47_D_80070328.unk4a = 0x300;
        default:
            return;
        }
        break;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_47/animation", func_level_47_8008D2F4);
