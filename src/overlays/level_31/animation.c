#include "common.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_31/animation", func_level_31_8008C864);

INCLUDE_ASM("asm/nonmatchings/overlays/level_31/animation", func_level_31_8008D64C);

#define LEVEL_ID 31
#define PlaySpyroSounds_level_31 func_level_31_8008DCF8
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_31_8008DE1C(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x87:
    case 0x8b:
    case 0x8e:
    case 0x8f:
    case 0x90:
    case 0x91:
    case 0x93:
        {
            int* tag = spyro.critterMobyPtr->mobyTag;
            tag[10]++;
            if (tag[10] > 60) tag[10] = 60;
            func_80043ABC(&spyro.unk9e);
        }
        break;
    case 0xa:
    case 0xb:
    case 0xc:
    case 0x14:
    case 0x1a:
    case 0x1d:
    case 0x20:
    case 0x88:
    case 0x89:
    case 0x8a:
    case 0x8c:
    case 0x8d:
    case 0x92:
        func_80043ABC(&spyro.unk9e);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 8008DEC0..8008E3C4.
 * Baseline: verified level27_80088AE4 transition case1A and numeric schemas.
 * Original31 supplies independent private-data routes88/89/8A, byte offsets
 * 0x28/0x3C and signed trig reads from byte-scaled table indices.
 * Empty constraints preserve original stores/load delays and duplicated calls;
 * otherwise unused V0 call results establish no helper-return meaning.
 * Source units/producers, sound semantics, helper contracts, invocation cadence
 * and runtime/browser parity remain open. Test every original code/table word
 * and all complete retail EXE/overlay hashes before acceptance.
 */
int Transition31Zero(Vector3D*) __asm__("func_8004F168");
int Transition31Call441F0(void) __asm__("func_800441F0");
extern Spyro Callback31_D_80070328 __asm__("D_80070328");
extern short Callback31_D_800658A0[] __asm__("D_800658A0");
extern short Callback31_D_80065920[] __asm__("D_80065920");
int Callback31_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
int Callback31_func_8003636C(int low, int high) __asm__("func_8003636C");
void Callback31_func_80043A38(int scale) __asm__("func_80043A38");
void Callback31_func_800441F0(void) __asm__("func_800441F0");
void Callback31_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Callback31_D_8006E524 __asm__("D_8006E524");
extern unsigned char Raw31Union[] __asm__("D_80070328+0x144");
extern int Raw31Movement __asm__("D_80070328+0x50");
int Squish31Call(int,int,int) __asm__("PlaySound");
void func_level_31_8008DEC0(int selector) {
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register int oldMovementC __asm__("$5");
    register int oldMovement __asm__("$4");
    register int shiftedZ __asm__("$2");
    register int tableByteOffset __asm__("$3");
    unsigned char *private88;
    unsigned char *private89;
    unsigned char *private8A;

    switch (selector) {
    case 0x14:
        Callback31_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback31_D_80070328.unk5 = 0;
        Callback31_func_800441F0();
        Callback31_D_80070328.grounded = 1;
        Callback31_D_80070328.union144.a.unk13cb = Callback31_func_8003636C(1, 3);
        Callback31_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0xA:
    case 0xB:
    case 0xC:
        Callback31_D_80070328.movementState = MOVEMENT_STATE_ICE_SKATE;
        Callback31_D_80070328.unk5 = 0;
        Callback31_D_80070328.unk8[0] = Callback31_func_8004EDE8((Vector3D *) ((unsigned char*)&Callback31_D_80070328.movementState + 0x48), 0);
        Callback31_func_80043A38(0xC00);
        Callback31_D_80070328.grounded = 1;
        goto clearPointers;
    case 0x1D: {
        register int component __asm__("$3");
        register int word __asm__("$2");
        oldMovement=Raw31Movement;
        component=Callback31_D_80070328.unk17e.x;
        __asm__("" : "=r"(oldMovement), "=r"(component) : "0"(oldMovement), "1"(component));
        word=7;
        Raw31Movement=word;
        word=Callback31_D_80070328.unk17e.y;
        Callback31_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(component), "=r"(word) : "0"(component), "1"(word) : "memory");
        component<<=6;
        Callback31_D_80070328.unk7a[2].x=component;
        component=Callback31_D_80070328.unk17e.z;
        __asm__ volatile("" : "=r"(word) : "0"(word) : "memory");
        word<<=6;
        __asm__("" : "=r"(word) : "0"(word));
        *(int*)Raw31Union=oldMovement;
        Callback31_D_80070328.unk7a[2].y=word;
        shiftedZ=component<<6;
        if(component==0)shiftedZ=Callback31_D_80070328.unk7a[3].z;
        Callback31_D_80070328.unk7a[2].z=shiftedZ;
        Callback31_func_80043A38(0xC00);
        Callback31_D_80070328.grounded = 1;
        Callback31_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        PlaySound((int) D_8006C654->spyroHurt, 0, 0);
        goto clearPointers;
    }
    case 0x1A:
        savedBase = Raw31Union;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        oldMovementC = Raw31Movement;
        Raw31Movement = MOVEMENT_STATE_HURT;
        Callback31_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementC;
        Callback31_func_8004F168(destination);
        Callback31_D_80070328.grounded = 1;
        Callback31_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        Squish31Call((int) D_8006C654->squish, 0, 0);
        goto clearPointers;
    case 0x20:
        Callback31_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Callback31_D_80070328.unk5 = 0;
        Callback31_func_80043A38(0xC00);
        Callback31_D_80070328.grounded = 1;
        if ((selector == 0x3A) || (selector == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Callback31_D_8006E524 = 0xF;
clearPointers:
        Callback31_D_80070328.unk20a = 0;
        Callback31_D_80070328.critterMobyPtr = 0;
        return;
    case 0x87:
    case 0x8B:
    case 0x93:
        Callback31_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback31_D_80070328.unk5 = 0;
        {register int callResult __asm__("$2")=Transition31Call441F0();
        __asm__ volatile("" : : "r"(callResult) : "$4");}
        goto markGrounded;
    default:
        return;
    case 0x8E:
    case 0x8F:
    case 0x90:
    case 0x91:
        Callback31_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((selector == 0x57) && (Callback31_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((unsigned char*)&Callback31_D_80070328.movementState + 0x3C), (Vector3D *) ((unsigned char*)&Callback31_D_80070328.movementState + 0x48));
            Callback31_D_80070328.unk5 = 1;
        } else {
            Callback31_D_80070328.unk5 = 0;
        }
        Callback31_D_80070328.unk8[0] = Callback31_func_8004EDE8(&Callback31_D_80070328.unk7a[3], 0);
        Callback31_func_80043A38(0xC00);
        Callback31_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Callback31_D_80070328.grounded = 1;
        Callback31_D_80070328.idle = 0;
        Callback31_D_80070328.unk15g = 0;
        return;
    case 0x88:
        private88 = Callback31_D_80070328.critterMobyPtr->mobyTag;
        *(int*)(private88 + 0x28) = (int) (*(int*)(private88 + 0x28) - 0xF);
        {register int zeroResult __asm__("$2")=Transition31Zero((Vector3D*)(private88 + 0x3C));
        __asm__ volatile("" : : "r"(zeroResult) : "$5");}
        Callback31_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback31_D_80070328.unk5 = 0;
        {register int callResult __asm__("$2")=Transition31Call441F0();
        __asm__ volatile("" : : "r"(callResult) : "$5");}
        goto markGrounded;
    case 0x89:
        private89 = Callback31_D_80070328.critterMobyPtr->mobyTag;
        *(int*)(private89 + 0x28) = (int) (*(int*)(private89 + 0x28) - 0x1E);
        {register int zeroResult __asm__("$2")=Transition31Zero((Vector3D*)(private89 + 0x3C));
        __asm__ volatile("" : : "r"(zeroResult) : "$6");}
        Callback31_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback31_D_80070328.unk5 = 0;
        {register int callResult __asm__("$2")=Transition31Call441F0();
        __asm__ volatile("" : : "r"(callResult) : "$6");}
        goto markGrounded;
    case 0x8A:
        private8A = Callback31_D_80070328.critterMobyPtr->mobyTag;
        *(int*)(private8A + 0x28) = (int) (*(int*)(private8A + 0x28) - 0x14);
        {register int zeroResult __asm__("$2")=Transition31Zero((Vector3D*)(private8A + 0x3C));
        __asm__ volatile("" : : "r"(zeroResult) : "$7");}
        Callback31_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback31_D_80070328.unk5 = 0;
        {register int callResult __asm__("$2")=Transition31Call441F0();
        __asm__ volatile("" : : "r"(callResult) : "$7");}
        goto markGrounded;
    case 0x8C:
    case 0x8D:
        Callback31_D_80070328.movementState = MOVEMENT_STATE_HURT;
        Callback31_D_80070328.unk5 = 0;
        Callback31_func_800441F0();
        tableByteOffset = Callback31_D_80070328.unk22[5] * 2;
        if (Callback31_D_80070328.unk22[5] < 0) {
            {register int yaw __asm__("$2")=Callback31_D_80070328.bodyRotation.yaw;
            __asm__("" : "=r"(yaw) : "0"(yaw));
            yaw += 0x80;
            yaw &= 0xFF;
            tableByteOffset=yaw<<1;}
        }
        Callback31_D_80070328.unk7a[1].x = (int) *(short*)((unsigned char*)Callback31_D_80065920 + tableByteOffset);
        {register int sample __asm__("$2")=*(short*)((unsigned char*)Callback31_D_800658A0 + tableByteOffset);
        __asm__ volatile("" : "=r"(sample) : "0"(sample) : "memory");
        Callback31_D_80070328.unk7a[1].z=0;
        Callback31_D_80070328.unk7a[1].y=sample;}
        Callback31_func_80043A38(0xC00);
        Callback31_D_80070328.grounded = 1;
        Callback31_D_8006E524 = 0xF;
        return;
    case 0x92:
        Callback31_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Callback31_D_80070328.unk5 = 0;
        Callback31_func_80043A38(0xC00);
markGrounded:
        Callback31_D_80070328.grounded = 1;
        return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_31/animation", func_level_31_8008E3C8);
