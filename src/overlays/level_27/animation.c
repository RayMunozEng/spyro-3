#include "common.h"
#include "camera.h"
#include "hud.h"
#include "drawutil.h"
#include "spu.h"
#include "mobyutil.h"
#include "stdutil.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_27/animation", func_level_27_80088028);

void func_level_27_8008874C(void) {
    switch (spyro.animationState) {
    case 0x14:
        if (func_800438F4() == 0) {
            func_80043728();
        }
        func_80041C20();
        spyro.unk9a = 0;
        goto block_6;
    case 0x20:
    case 0x35:
    case 0x36:
        func_80041C20();
block_6:
        func_80042A44();
block_7:
        spyro.unk4[0] = 0;
        return;
    case 0x9:
        func_80041C20();
        func_80042A44();
        if (spyro.unk5 == 1) {
            func_80041930();
        } else {
            func_80043A38(0xC00);
        }
        if ((unsigned char) spyro.bodyAnimation.nextFrame < 0xAU) {
            spyro.cheatColour.a = 0xFF;
            if (spyro.bodyAnimation.nextFrame & 1) {
                spyro.cheatColour.b = 0xFF;
                spyro.cheatColour.g = 0xFF;
                spyro.cheatColour.r = 0xFF;
            } else {
                spyro.cheatColour.b = 0x40;
                spyro.cheatColour.g = 0x40;
                spyro.cheatColour.r = 0x40;
            }
        }
        goto block_7;
    case 0x1A:
        func_80041C20();
        func_80042A44();
        func_80043A38(0xC00);
        goto block_7;
    case 0x1C:
        func_80041C20();
        func_80042A44();
        func_80041930();
        if ((spyro.unk7a[3].z < 0) && (spyro.animationStateFrames >= 4)) {
            spyro.unk5 = 1;
        }
        goto block_7;
    case 0x3A:
        func_80041C20();
        func_80042A44();
        spyro.cheatColour.a = 0xFF;
        spyro.unk4[0] = 0;
        spyro.cheatColour.b = 0x20;
        spyro.cheatColour.g = 0x20;
        spyro.cheatColour.r = 0x20;

    default:
        return;
    }
}


#define LEVEL_ID 27
#define PlaySpyroSounds_level_27 func_level_27_80088940
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_27_80088A48(int index) {
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
    case 0x1A:
    case 0x20:
    case 0x35:
    case 0x36:
    case 0x3A:
        vector = &spyro.unk9e;
        goto apply;
    case 0x1C:
reset:
        vector = 0;
apply:
        func_80043ABC(vector);
        break;
    }
}

extern Spyro Callback27_D_80070328 __asm__("D_80070328");
extern short Callback27_D_800658A0[] __asm__("D_800658A0");
extern short Callback27_D_80065920[] __asm__("D_80065920");
int Callback27_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
int Callback27_func_8003636C(int low, int high) __asm__("func_8003636C");
int Callback27_func_80040954(int arg0) __asm__("func_80040954");
void Callback27_func_80043A38(int scale) __asm__("func_80043A38");
void Callback27_func_800441F0(void) __asm__("func_800441F0");
void Callback27_func_8004F0E8(Vector3D*, int) __asm__("func_8004F0E8");
void Callback27_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Callback27_D_8006E524 __asm__("D_8006E524");
extern int Callback27_D_8006E528 __asm__("D_8006E528");
extern unsigned char Raw27Union[] __asm__("D_80070328+0x144");
extern int Raw27Movement __asm__("D_80070328+0x50");
extern short Signed27A[] __asm__("D_800658A0");
extern short Signed27B[] __asm__("D_80065920");
extern int Raw27X __asm__("D_80070328+0x8C");
int Squish27Call(int,int,int) __asm__("PlaySound");
void func_level_27_80088AE4(int selector) {
    register Vector3D *sourceC __asm__("$16");
    register unsigned char *savedBase __asm__("$3");
    register Vector3D *destination __asm__("$4");
    register int tableIndex __asm__("$2");
    register int tableValue __asm__("$3");
    register int oldMovementC __asm__("$5");
    register int oldMovementD __asm__("$6");
    register int oldMovementA __asm__("$3");
    register int oldMovementB __asm__("$3");
    register int flags __asm__("$2");
    register unsigned char* header __asm__("$17");
    register int *sourceA __asm__("$16");
    int *sourceB;

    switch (selector) {
    case 0x14:
        Callback27_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback27_D_80070328.unk5 = 0;
        Callback27_func_800441F0();
        Callback27_D_80070328.grounded = 1;
        Callback27_D_80070328.union144.a.unk13cb = Callback27_func_8003636C(1, 3);
        Callback27_D_80070328.union144.a.unk13cc = 0;
        goto clearTail;
    case 0x9:
        header = (unsigned char*)&Callback27_D_80070328.unk11[2];
        if (Callback27_func_80040954(*(int*)header) == 7) {
            sourceA = header - 0x74;
            oldMovementA = Raw27Movement;
            Raw27Movement = MOVEMENT_STATE_HURT;
            Callback27_D_80070328.unk5 = 1;
            Callback27_D_80070328.union144.a.unk13cb = oldMovementA;
            func_8004F178((Vector3D *) (header - 0x80), (Vector3D *) sourceA);
            Callback27_D_80070328.unk8[0] = Callback27_func_8004EDE8((Vector3D *) sourceA, 0);
            Callback27_D_80070328.unk7a[2].z = 0xDC0;
            Callback27_D_80070328.grounded = 0;
        } else {
            oldMovementB = Raw27Movement;
            flags = Callback27_D_80070328.unk17a;
            __asm__("" : "=r"(oldMovementB), "=r"(flags) : "0"(oldMovementB), "1"(flags));
            Raw27Movement = MOVEMENT_STATE_HURT;
            Callback27_D_80070328.unk5 = 0;
            __asm__ __volatile__("" : "=r"(flags) : "0"(flags) : "memory");
            Callback27_D_80070328.union144.a.unk13cb = oldMovementB;
            sourceB = header - 0x80;
            if (flags & 0x400) {
                func_8004F178((Vector3D *) sourceB, (Vector3D *) (header + 0x110));
                Callback27_func_8004F0E8((Vector3D *) sourceB, 6);
            } else if (Callback27_D_80070328.unk22[5] >= 0) {
                tableIndex = Callback27_D_80070328.unk22[5] * 2;
                tableValue = *(short*)((unsigned char*)Signed27B + tableIndex);
                __asm__("" : "=r"(tableValue) : "0"(tableValue));
                Raw27X = tableValue >> 1;
                tableIndex = *(short*)((unsigned char*)Signed27A + tableIndex);
                Callback27_D_80070328.unk7a[2].z = 0;
                __asm__ __volatile__("" : "=r"(tableIndex) : "0"(tableIndex) : "memory");
                Callback27_D_80070328.unk7a[2].y = tableIndex >> 1;
            } else {
                __asm__("" : "=r"(header) : "0"(header));
                destination = (Vector3D*)(header - 0x80);
                Callback27_func_8004F168(destination);
            }
            func_8004F178(&Callback27_D_80070328.unk7a[1], (unsigned char*)&Callback27_D_80070328.unk7a[1] + 0xC);
            Callback27_func_80043A38(0xC00);
            Callback27_D_80070328.grounded = 1;
        }
        Callback27_D_8006E528 = 0x2D;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        goto clearTail;
    case 0x1A:
        savedBase = Raw27Union;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        oldMovementC = Raw27Movement;
        Raw27Movement = MOVEMENT_STATE_HURT;
        Callback27_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementC;
        Callback27_func_8004F168(destination);
        Callback27_D_80070328.grounded = 1;
        Callback27_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        Squish27Call((int) D_8006C654->squish, 0, 0);
        goto clearTail;
    case 0x1C:
        savedBase = Raw27Union;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Raw27Movement;
        Raw27Movement = MOVEMENT_STATE_HURT;
        Callback27_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Callback27_D_80070328.unk8[0] = Callback27_func_8004EDE8(sourceC, 0);
        Callback27_D_80070328.unk7a[2].z = 0xDC0;
        Callback27_D_80070328.grounded = 0;
        Callback27_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Callback27_D_80070328.damageFlags & 0x200) {
            Callback27_D_80070328.union144.a.unk13cc = 0;
        } else {
            Callback27_D_80070328.union144.a.unk13cc = 1;
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        goto clearTail;
    case 0x20:
    case 0x3A:
        Callback27_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Callback27_D_80070328.unk5 = 0;
        Callback27_func_80043A38(0xC00);
        Callback27_D_80070328.grounded = 1;
        if ((selector == 0x3A) || (selector == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Callback27_D_8006E524 = 0xF;
        goto clearTail;
    case 0x35:
    case 0x36:
        Callback27_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback27_D_80070328.unk5 = 0;
        Callback27_func_800441F0();
        Callback27_D_80070328.grounded = 1;
clearTail:
        Callback27_D_80070328.unk20a = 0;
        Callback27_D_80070328.critterMobyPtr = 0;
        break;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_27/animation", func_level_27_80088F0C);
