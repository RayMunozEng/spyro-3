#include "common.h"
#include "spu.h"
#include "ovl_header.h"
#include "stdutil.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_17/animation", func_level_17_80082528);

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
/* AI generated adaptation; not human reviewed.
 * SCUS-94467 USA Rev0 80082B84..80082DC0 and original mode dispatch.
 * Reuses verified level40_800863B8 ordered helpers and raw mode30 step/
 * position update: signed shift6, tick shift9, limits9000/2580, sampled
 * vector Z+400 and query argumentC00. Original modes26/29/32 and28/58
 * add their exact helper routes, signed word gates and byte/word stores.
 * Physical units, all producer/helper meanings and caller cadence are open.
 * Acceptance: every original code/table word and complete retail hashes.
 */
void func_level_17_80082B84(void) {
    Vector3D sample;
    switch (spyro.animationState) {
    case 20:
        if (!func_800438F4()) {
            func_80043728();
        }
        func_80041C20();
        spyro.unk9a = 0;
        func_80042A44();
        spyro.unk4[0] = 0;
        break;
    case 32:
        func_80041C20();
        func_80042A44();
        spyro.unk4[0] = 0;
        break;
    case 26: case 29:
        func_80041C20();
        func_80042A44();
        func_80043A38(0xC00);
        spyro.unk4[0] = 0;
        break;
    case 28:
        func_80041C20();
        func_80042A44();
        func_80041930();
        if (DecodedAnimationWordA0 < 0 && spyro.animationStateFrames >= 4)
            DecodedAnimationWord4C = 1;
        spyro.unk4[0] = 0;
        break;
    case 30: {
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
        break;
    }
    case 58:
        func_80041C20();
        func_80042A44();
        DecodedAnimationByte23 = 255;
        spyro.unk4[0] = 0;
        DecodedAnimationByte22 = 32;
        DecodedAnimationByte21 = 32;
        DecodedAnimationByte20 = 32;
        break;
    }
}

#define LEVEL_ID 17
#define PlaySpyroSounds_level_17 func_level_17_80082DC4
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_17_80082ECC(int index) {
    Vector3D* position;
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x14: case 0x1a: case 0x1d: case 0x1e: case 0x20: case 0x3a: position = &spyro.unk9e; break;
    case 0x1c: position = 0; break;
    case 0x15: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1b: case 0x1f: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f: case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: case 0x38: case 0x39: return;
    default: return;
    }
    func_80043ABC(position);
}

/* SCUS-94467: 80082F48..80083328; dispatch table 80074BBC..80074C58.
 * Empty constraints preserve original register lifetimes and memory ordering.
 * Existing field names do not establish helper, sound or state semantics.
 */
extern unsigned char Actor17SavedBase[] __asm__("D_80070328+0x144");
extern int Actor17Movement __asm__("D_80070328+0x50");
int Actor17CallSound15(int, Moby*, int) __asm__("PlaySound");
int Actor17CallSound09(int, Moby*, int) __asm__("PlaySound");
extern Spyro Actor17Spyro __asm__("D_80070328");
int Actor17Call8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
int Actor17Call8003636C(int low, int high) __asm__("func_8003636C");
void Actor17Call80043A38(int scale) __asm__("func_80043A38");
void Actor17Call800441F0(void) __asm__("func_800441F0");
void Actor17Call8004F168(Vector3D*) __asm__("func_8004F168");
extern int Actor17Word6E524 __asm__("D_8006E524");
void func_level_17_80082F48(int arg0) {
    register Vector3D *sourceVector __asm__("$16");
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register int previousMovementA0 __asm__("$4");
    register int previousMovementA1 __asm__("$5");
    register int previousMovementA2 __asm__("$6");
    register int previousMovementV1 __asm__("$3");
    register volatile int* savedWordPointer __asm__("$2");

    switch (arg0) {
    case 0x14:
        Actor17Movement = MOVEMENT_STATE_STAND;
        Actor17Spyro.unk5 = 0;
        Actor17Call800441F0();
        Actor17Spyro.grounded = 1;
        Actor17Spyro.union144.a.unk13cb = Actor17Call8003636C(1, 3);
        Actor17Spyro.union144.a.unk13cc = 0;
        goto clearSharedWords;
    default:
        return;
    case 0x1D:
        {
            register int component __asm__("$3");
            register int value __asm__("$2");
            previousMovementA0 = Actor17Movement;
            component = Actor17Spyro.unk17e.x;
            __asm__ __volatile__("" : : : "$2", "memory");
            value = 7;
            Actor17Movement = value;
            __asm__ __volatile__("" : : : "memory");
            value = Actor17Spyro.unk17e.y;
            Actor17Spyro.unk5 = 0;
            __asm__ __volatile__("" : : : "memory");
            component <<= 6;
            Actor17Spyro.unk7a[2].x = component;
            __asm__ __volatile__("" : : : "memory");
            component = Actor17Spyro.unk17e.z;
            value <<= 6;
            Actor17Spyro.union144.a.unk13cb = previousMovementA0;
            __asm__ __volatile__("" : : : "memory");
            Actor17Spyro.unk7a[2].y = value;
            value = component << 6;
            if (component == 0) {
                value = Actor17Spyro.unk7a[3].z;
            }
            __asm__("" : "=r"(value) : "0"(value));
            Actor17Spyro.unk7a[2].z = value;
        }
        Actor17Call80043A38(0xC00);
        Actor17Spyro.grounded = 1;
        Actor17Word6E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        Actor17CallSound15((int) D_8006C654->spyroHurt, 0, 0);
        goto clearSharedWords;
    case 0x1A:
        savedBase = Actor17SavedBase;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        previousMovementA1 = Actor17Movement;
        Actor17Movement = MOVEMENT_STATE_HURT;
        Actor17Spyro.unk5 = 0;
        *(int*)savedBase = previousMovementA1;
        Actor17Call8004F168(destination);
        Actor17Spyro.grounded = 1;
        Actor17Word6E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        Actor17CallSound09((int) D_8006C654->squish, 0, 0);
        goto clearSharedWords;
    case 0x1C:
        savedBase = Actor17SavedBase;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceVector = (Vector3D*)(savedBase - 0xAC);
        previousMovementA2 = Actor17Movement;
        Actor17Movement = MOVEMENT_STATE_HURT;
        Actor17Spyro.unk5 = 0;
        *(int*)savedBase = previousMovementA2;
        func_8004F178(destination, sourceVector);
        Actor17Spyro.unk8[0] = Actor17Call8004EDE8(sourceVector, 0);
        Actor17Spyro.unk7a[2].z = 0xDC0;
        Actor17Spyro.grounded = 0;
        Actor17Word6E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Actor17Spyro.damageFlags & 0x200) {
            Actor17Spyro.union144.a.unk13cc = 0;
        } else {
            Actor17Spyro.union144.a.unk13cc = 1;
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        goto clearSharedWords;
    case 0x1E:
        {
            register char* (*particles)(int,int,Vector3D*,Vector3D*) __asm__("$8");
            register int value __asm__("$2");
            previousMovementV1 = Actor17Movement;
            particles = SpawnParticle;
            __asm__ __volatile__("" : : : "$2", "memory");
            value = 7;
            __asm__("" : "=r"(particles) : "0"(particles), "r"(value));
            Actor17Movement = value;
            value = 1;
            Actor17Spyro.grounded = value;
            value = 15;
            Actor17Word6E524 = value;
            __asm__ __volatile__("" : : : "$2", "memory");
            savedWordPointer = (volatile int*)Actor17SavedBase;
            __asm__("" : "=r"(savedWordPointer) : "0"(savedWordPointer));
            Actor17Spyro.unk5 = 0;
            /* Preserve both original stores; the zero store fills a branch delay. */
            *savedWordPointer = previousMovementV1;
            *(int*)savedWordPointer = 0;
            if (particles) {
                particles(5, 10, 0, 0);
            }
        }
        Actor17Spyro.unk22[2] = PlaySound((int) D_8006C654->drown, 0, 0);
        {
            register int descriptor __asm__("$2") = D_8006C654->drown;
            __asm__ __volatile__("" : : : "memory");
            Actor17Spyro.unk20a = 0;
            Actor17Spyro.critterMobyPtr = 0;
            __asm__("" : "=r"(descriptor) : "0"(descriptor));
            Actor17Spyro.unk22[3] = descriptor;
        }
        return;
    case 0x20:
    case 0x3A:
        Actor17Movement = MOVEMENT_STATE_DEATH;
        Actor17Spyro.unk5 = 0;
        Actor17Call80043A38(0xC00);
        Actor17Spyro.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Actor17Word6E524 = 0xF;
        goto clearSharedWords;
    }
clearSharedWords:
    Actor17Spyro.unk20a = 0;
    Actor17Spyro.critterMobyPtr = 0;
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_17/animation", func_level_17_8008332C);
