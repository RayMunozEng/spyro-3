#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "pad.h"
#include "spyro.h"

#define Controller59D0Word(o) (*(int*)(Controller59D0Player + (o)))
extern unsigned char Controller59D0Player[] __asm__("D_80070328");
extern unsigned char Controller59D0Base[] __asm__("D_80070328 + 0x54");
extern unsigned char Controller59D0Entries[] __asm__("D_8006E548");
extern unsigned char* Controller59D0Output __asm__("D_8006C570");
extern int D_8006E538;
int Controller59D0InterpolateCosine(int) __asm__("func_8004EA2C");
int Controller59D0InterpolateSine(int) __asm__("func_8004E9E4");
void Controller59D0ScaleVectorRatioQ15(Vector3D*, int, int) __asm__("func_8004F08C");
void Controller59D0ClearVector(int*) __asm__("func_8004F168");
void Controller59D0SubtractVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
int Controller59D0MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
/* AI generated; not human reviewed. SCUS-94467 USA Rev 0.
 * Original283 instructions per copy: level28/859D0, level38/87C00,
 * level48/86C38; helper/global symbols and relative branches checked separately.
 * Byte reads+FC/+101, word reads/writes retain original offsets. Entry stride16;
 * stack vectors at10/20/30 keep16-byte spacing. Original signed products shift12,
 * heading mask~511 and vector thresholds640 preserved with post-call rereads.
 * Numeric domains, semantic helper contracts and caller cadence remain open;
 * once per invocation. Existing names do not prove runtime interpretations.
 * Confidence: exact native/linked words and every full retail hash.
 * Falsifiable vectors: all recorded original words and complete retail SHA.
 * Empty constraints preserve original register phases, without opcode patches.
 */
void func_level_48_80086C38(int entryIndex) {
    register int preparedHeading __asm__("$4");
    register int* base __asm__("$16");
    Vector3D difference0;
    int reserved1C;
    Vector3D difference1;
    int reserved2C;
    Vector3D difference2;
    int reserved3C;
    register Vector3D* addend __asm__("$6");
    register int* vector0 __asm__("$16");
    register int* vector1 __asm__("$16");
    register int* vector2 __asm__("$16");
    register int* savedVector0 __asm__("$18");
    register int* savedVector1 __asm__("$18");
    register int* destination __asm__("$4");
    register int* addSource __asm__("$5");
    int temp_lo;
    register int savedHeading __asm__("$17");
    register int flagSet __asm__("$20");
    register int quantizedHeading __asm__("$19");
    int length0;
    int length1;
    int length2;
    int turnValue;
    signed char* pointer0;
    signed char* pointer1;

    {
        register int index __asm__("$4") = entryIndex;
        register unsigned char* entries __asm__("$2");
        register unsigned char* prepared __asm__("$4");
        index <<= 4;
        MATCHING_KEEP_CLOBBER(index, "$2");
        entries = Controller59D0Entries;
        prepared = entries + index;
        MATCHING_KEEP_CLOBBER(prepared, "$16");
        base = (int*)Controller59D0Base;
        MATCHING_KEEP(base);
        Controller59D0Output = prepared;
    }
    switch (Controller59D0Word(0x48)) { /* irregular */
        case 0x98: {
            register int prepared __asm__("$4") = 0x1180;
            register int flags __asm__("$2");
            __asm__("" : "=r"(prepared) : "0"(prepared) : "$2", "$17");
            flags = D_8006E538;
            MATCHING_KEEP_CLOBBER(flags, "$17");
            savedHeading = Controller59D0Word(0xA4);
            MATCHING_KEEP2_CLOBBER(flags, savedHeading, "$20");
            flagSet = (flags & 12) != 0;
            func_80040D10(prepared);
        }
            {
                register int quantized __asm__("$2") = (Controller59D0Word(0xA4) + 255) & ~511;
                Controller59D0Word(0xA4) = quantized;
                MATCHING_KEEP_VOLATILE_CLOBBER(quantized, "memory");
                quantizedHeading = quantized;
            }
            if (flagSet != 0) {
                Controller59D0Word(0xA4) = savedHeading;
            }
            turnValue = func_80041580(0xB4, 0x20);
            if (turnValue < 0) {
                turnValue = -turnValue;
            }
            if (turnValue >= 0x201) {
                Controller59D0Word(0xAC) = 0;
            }
            func_800417FC(0x280, 0x180);
            if ((unsigned char)Controller59D0Player[0x101] != 0) {
                Controller59D0ClearVector((int*)((unsigned char*)base + 0x38));
            } else {
                if (flagSet != 0) {
                    {
                        register int result __asm__("$2") =
                            Controller59D0InterpolateCosine(quantizedHeading);
                        register int speed __asm__("$3") = Controller59D0Word(0xAC);
                        register int product __asm__("$7") = speed * result;
                        register int scaled __asm__("$2") = product >> 12;
                        preparedHeading = quantizedHeading;
                        MATCHING_KEEP3(product, preparedHeading, scaled);
                        base[11] = scaled;
                    }
                    {
                        register int result __asm__("$2") =
                            Controller59D0InterpolateSine(preparedHeading);
                        register int speed __asm__("$3") = Controller59D0Word(0xAC);
                        register int product __asm__("$7") = speed * result;
                        register int scaled __asm__("$2");
                        register Vector3D* first __asm__("$4") = &difference0;
                        register Vector3D* second __asm__("$5") =
                            (Vector3D*)((unsigned char*)base + 0x2C);
                        MATCHING_KEEP2_CLOBBER(first, second, "$16");
                        vector0 = (int*)((unsigned char*)base + 0x38);
                        Controller59D0Word(0x88) = 0;
                        scaled = product >> 12;
                        Controller59D0Word(0x84) = scaled;
                        Controller59D0SubtractVector(first, second, (Vector3D*)vector0);
                    }
                    difference0.z = 0;
                    length0 = Controller59D0MeasureVectorLength(&difference0, 0);
                    destination = vector0;
                    if (length0 >= 0x281) {
                        Controller59D0ScaleVectorRatioQ15(&difference0, length0, 0x280);
                        destination = vector0;
                    }
                    addSource = destination;
                    addend = &difference0;
                } else {
                    savedVector0 = (int*)((unsigned char*)base + 0x38);
                    func_80041848();
                    func_8004F178(&difference1, (Vector3D*)savedVector0);
                    vector1 = (int*)((unsigned char*)base + 0x2C);
                    func_80041B64();
                    func_8004F178((Vector3D*)vector1, (Vector3D*)savedVector0);
                    func_8004F178((Vector3D*)savedVector0, &difference1);
                    Controller59D0SubtractVector(&difference1, (Vector3D*)vector1,
                                                 (Vector3D*)savedVector0);
                    MATCHING_KEEP(flagSet);
                    difference1.z = 0;
                    length1 = Controller59D0MeasureVectorLength(&difference1, 0);
                    destination = savedVector0;
                    if (length1 >= 0x281) {
                        Controller59D0ScaleVectorRatioQ15(&difference1, length1, 0x280);
                        destination = savedVector0;
                    }
                    addSource = destination;
                    addend = &difference1;
                }
                func_8004F194((Vector3D*)destination, (Vector3D*)addSource, addend);
                Controller59D0Word(0x94) = 0;
            }
            if (((unsigned char)Controller59D0Player[0xFC] != 0) ||
                (pointer0 = (signed char*)Controller59D0Player + 0x8C,
                 (Controller59D0Word(0xB8) != 0))) {
                Controller59D0Word(0x94) = Controller59D0Word(0xA0) - 0xC0;
            } else {
                func_8004F194((Vector3D*)pointer0, (Vector3D*)pointer0,
                              (Vector3D*)(Controller59D0Player + 0xE8));
            }
            Controller59D0Word(0x144) = flagSet;
            Controller59D0Word(0x148) = quantizedHeading;
            return;
        case 0x99:
            func_80040D10(0x1A40);
            Controller59D0Word(0xA4) = (Controller59D0Word(0xA4) + 0xFF) & ~0x1FF;
            func_80041580(0x5A, 0x10);
            Controller59D0Word(0xAC) = 0x1A40;
            func_800417FC(0x280, 0x180);
            if ((unsigned char)Controller59D0Player[0x101] != 0) {
                Controller59D0ClearVector((int*)((unsigned char*)base + 0x38));
            } else {
                savedVector1 = (int*)((unsigned char*)base + 0x38);
                func_80041848();
                func_8004F178(&difference2, (Vector3D*)savedVector1);
                func_80041B64();
                if (Controller59D0Word(0x20C) & 0x400) {
                    Controller59D0Word(0x4C) = 0x78;
                }
                vector2 = (int*)((unsigned char*)base + 0x2C);
                if (Controller59D0Word(0x4C) != 0) {
                    Controller59D0Word(0x4C) -= 1;
                    func_8004F178((Vector3D*)vector2, (Vector3D*)savedVector1);
                    func_8004F178((Vector3D*)savedVector1, &difference2);
                    Controller59D0SubtractVector(&difference2, (Vector3D*)vector2,
                                                 (Vector3D*)savedVector1);
                    difference2.z = 0;
                    length2 = Controller59D0MeasureVectorLength(&difference2, 0);
                    if (length2 >= 0x281) {
                        Controller59D0ScaleVectorRatioQ15(&difference2, length2, 0x280);
                    }
                    func_8004F194((Vector3D*)savedVector1, (Vector3D*)savedVector1, &difference2);
                }
                Controller59D0Word(0x94) = 0;
            }
            if (((unsigned char)Controller59D0Player[0xFC] != 0) ||
                (pointer1 = (signed char*)Controller59D0Player + 0x8C,
                 (Controller59D0Word(0xB8) != 0))) {
                Controller59D0Word(0x94) = Controller59D0Word(0xA0) - 0xC0;
            } else {
                func_8004F194((Vector3D*)pointer1, (Vector3D*)pointer1,
                              (Vector3D*)(Controller59D0Player + 0xE8));
            }
            Controller59D0Word(0x144) = 0;
            return;
    }
}

#undef Controller59D0Word


void func_800438F4(void);
void func_80041C20(void);
void func_80042A44(void);
void func_80041930(void);
void func_80043A38(int);
#define ANIMATION_BOUND(expr)                            \
    ({                                                   \
        register int bound asm("$2");                    \
        bound = (expr);                                  \
        __asm__ volatile("" : "=r"(bound) : "0"(bound)); \
        bound;                                           \
    })
void func_level_48_800870A4(void) {
    register int animation asm("$3") = spyro.animationState;
    if (animation < 0x9A && !ANIMATION_BOUND(animation < 0x98)) {
        func_800438F4();
        func_80041C20();
        if (spyro.unk7a[3].z > 0)
            spyro.unk7a[3].z = 0;
        func_80042A44();
        func_80041930();
        func_80043A38(0xC00);
        spyro.unk4[0] = 0;
    }
}
#undef ANIMATION_BOUND

#define LEVEL_ID 48
#define PlaySpyroSounds_level_48 func_level_48_80087124
#include "overlay/animation.inc.h"

extern PadState* D_8006C570;
void func_80043ABC(Vector3D*);
/* Empty register constraint preserves the two retail signed comparisons. */
#define RANGE2(expr)                             \
    ({                                           \
        register int r asm("$2");                \
        r = (expr);                              \
        __asm__ volatile("" : "=r"(r) : "0"(r)); \
        r;                                       \
    })
void func_level_48_8008712C(int index) {
    register int animation asm("$3");
    D_8006C570 = &pad.store[index];
    animation = spyro.animationState;
    if (animation < ANIMATION_STATE_SPARX_CHARGE + 1 &&
        !RANGE2(animation < ANIMATION_STATE_SPARX_IDLE)) {
        func_80043ABC(&spyro.unk9e);
    }
}
#undef RANGE2

int func_8004EDE8(Vector3D*, int);
void func_80043A38(int);
void func_level_48_80087184(int state) {
    if (state < 0x9A) {
        /* Empty constraint retains both original signed range comparisons. */
        MATCHING_KEEP(state);
        if (state >= 0x98) {
            int one = 1;
            int* movement = (int*)&spyro.movementState;
            *movement = one;
            if (state == 0x57 && spyro.ticksSinceLastSurfaceTouch) {
                func_8004F178((Vector3D*)((char*)movement + 0x3C),
                              (Vector3D*)((char*)movement + 0x48));
                spyro.unk5 = one;
            } else {
                spyro.unk5 = 0;
            }
            spyro.unk8[0] = func_8004EDE8(&spyro.unk7a[3], 0);
            func_80043A38(0xC00);
            spyro.grounded = 1;
            spyro.idle = 0;
            spyro.unk15g = 0;
            spyro.union144.a.unk13cb = 0;
        }
    }
}

extern int (*DecodedAnimationInputGate)(int) asm("unk_ovlheader_8007431C");
extern int D_8006E538;
void func_8004BEF8(int);
void func_level_48_80087248(void) {
    switch (spyro.animationState) {
        case 0x98:
            if (!DecodedAnimationInputGate(1) && (D_8006E538 & 0x80))
                func_8004BEF8(0x99);
            break;
        case 0x99:
            if (!DecodedAnimationInputGate(1) && !(D_8006E538 & 0x80))
                func_8004BEF8(0x98);
            break;
    }
}
