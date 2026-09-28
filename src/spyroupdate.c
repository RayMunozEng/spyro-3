#include "common.h"
#include "ovl_header.h"
#include "spu.h"
#include "spyro.h"
#include "pad.h"
#include "camera.h"

extern int D_8006C58C; // level index
extern char D_80067968[40][4]; // WalkingSoundIdPerSurface... maybe a struct array?
extern Unk_8006d048 D_8006D048;
extern char D_80070328;
extern void func_8004F168(void*);
extern unsigned char D_80066530[];

///////////////////////////////////////////////////////////////////////////////

/* Retail source: asm/nonmatchings/spyroupdate/func_8003E83C.s,
 * 0x8003E83C..0x8003E968; call sequence executes once on call. */
extern char g_CheatFlags;
void func_80044240(void);
void func_80047C7C(void);
void func_80048948(void);
void func_800491F4(void);
void func_8003E83C(void) {
    char* pivot = &D_80070328 + 0x74;
    func_8004F168(pivot);
    func_800489CC();
    func_800473E4();
    func_8003E968();
    func_8003F194();
    func_8004CCA0();
    func_80045D70();
    func_80044240();
    func_800451C4();
    func_800458F8();
    func_80048948();
    func_800491F4();
    func_80047C7C();
    if (*(int*)(&D_80070328 + 0x50) == 6) {
        if (*(int*)(&D_80070328 + 0x24C) == 10) {
            func_80055F14(*(void**)(&D_80070328 + 0x250), 0, pivot + 0x234);
            func_80055F14(*(void**)(&D_80070328 + 0x250), 1, pivot + 0x240);
        } else {
            func_80049ACC(0x56, pivot + 0x234);
            func_80049ACC(0x55, pivot + 0x240);
        }
    }
    if (*((unsigned char*)&g_CheatFlags + 6) != 0) {
        unsigned char* active = (unsigned char*)&D_80070328 + 0x11;
        if (*active == 0) *active = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_8003E968);

// Apply surface effects
// There's a bunch of surface functions here
INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_8003F194);

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_8003F6F4);

// Run surface type function
INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_8003FD58);

/* Retail source: asm/nonmatchings/spyroupdate/func_800408B8.s,
 * 0x800408B8..0x80040954; matrix/vector domains are preserved. */
void func_8004F194(Vector3D*, Vector3D*, Vector3D*);
void func_8004ED6C(SHORTMATRIX*, Vector3D*, Vector3D*);
int func_80018368(Vector3D*, Vector3D*);
extern int D_80071924;
int func_800408B8(SHORTMATRIX* matrix, Vector3D* first, Vector3D* second) {
    func_8004ED6C(matrix, first, first);
    func_8004F194(first, first, (Vector3D*)&D_80070328);
    func_8004ED6C(0, second, second);
    func_8004F194(second, second, (Vector3D*)&D_80070328);
    if (func_80018368(first, second) != 0)
        return func_80040954(D_80071924);
    return -1;
}

/**
 * ???() - func_80040954()
 * Roughly equivalent to func_80057380 from spyro-1
 * Checks if the surface is a special surface, and returns its type
 * D_8006D048 struct updated
 * https://decomp.me/scratch/cwjZ4
 */
int func_80040954(int arg0) {
    int index = arg0 & 0x3F;
    if (index == 0x3F) {
        return -1;
    }
    return D_8006D048.m_SurfaceData[index]->m_Type;
}

extern int D_8006C6C0, D_8006C710, D_8006C74C;
extern char* D_8006EE2C;
extern void func_8004BEF8(unsigned int);
/* Retail source: USA Rev 0 PSX.EXE 0x80040994..0x80040BCC (142 words).
 * One call decodes the raw input bitfield, updates integer retry counters,
 * and selects the retail movement state using the current player and object
 * fields. Confidence: exact; falsifiable by all instruction words and the
 * complete executable/overlay SHA-256 checks. */
int func_80040994(void) {
    int var_a0;
    int var_v0 = 0;

    if (*(int*)(&D_80070328 + 0x284) == 0) {
        var_v0 = 0;
        if (*(int*)(&D_80070328 + 0x1CC) == 0) {
            if (*(int*)(&D_80070328 + 0x24) & 0x3F9) {
                *(int*)(&D_80070328 + 0x284) = 0x5A;
                if ((*(int*)(&D_80070328 + 0x240) != 0) ||
                    (D_8006C74C != 0)) {
                    if (*(int*)(&D_80070328 + 0x280) < 0)
                        *(int*)(&D_80070328 + 0x280) = 0;
                } else {
                    D_8006C6C0 += 1;
                    D_8006C710 += 1;
                    if (*(int*)(&D_80070328 + 0x280) >= 0)
                        *(int*)(&D_80070328 + 0x280) -= 1;
                }
                if (*(int*)(&D_80070328 + 0x24) & 1) {
                    var_a0 = 0x10;
                    if ((unsigned int)(*(int*)(&D_80070328 + 0x50) - 0xB) < 2)
                        var_a0 = 0x39;
                    goto activate;
                }
                var_a0 = 0x1A;
                if (!(*(int*)(&D_80070328 + 0x24) & 0x10)) {
                    var_a0 = 9;
                    if (!(*(int*)(&D_80070328 + 0x24) & 0x20)) {
                        var_a0 = 0x1D;
                        if (!(*(int*)(&D_80070328 + 0x24) & 0x80)) {
                            var_a0 = 0x17;
                            if (!(*(int*)(&D_80070328 + 0x24) & 0x100)) {
                                if (*(int*)(&D_80070328 + 0x24) & 8) {
                                    if (*(int*)(&D_80070328 + 0x280) < 0) {
                                        var_a0 = 0x1F;
                                        if (*(int*)(D_8006EE2C + 0x124) != 0)
                                            var_a0 = 0x3A;
                                    } else {
                                        goto grounded;
                                    }
                                    goto activate;
                                }
                                if (*(int*)(&D_80070328 + 0x24) & 0x40) {
                                    if (*(int*)(&D_80070328 + 0x280) < 0) {
                                        var_a0 = 0x38;
                                        if (*(int*)(D_8006EE2C + 0x128) != 0)
                                            var_a0 = 0x3B;
                                    } else {
                                        var_a0 = 0x38;
                                    }
                                    goto activate;
                                }
                                var_v0 = 1;
                                if (*(int*)(&D_80070328 + 0x24) & 0x200) {
                                    if (*(int*)(&D_80070328 + 0x280) < 0) {
                                        var_a0 = 0x1F;
                                        if (*(int*)(D_8006EE2C + 0xB4) != 0)
                                            var_a0 = 0x1E;
                                    } else {
grounded:
                                        var_a0 = 0x1C;
                                    }
                                    goto activate;
                                }
                                return var_v0;
                            }
                        }
                    }
                }
activate:
                func_8004BEF8(var_a0);
                return 1;
            }
            var_v0 = 0;
            return var_v0;
        }
    }
    return var_v0;
}

extern int func_80040994(void);
extern void func_8004F1C8(void*, void*, void*);
extern int func_8004E880(int, int, int);
extern int func_8004EDE8(void*, int);
extern void func_8004F178(void*, void*);
extern Vector3D D_80071918;
extern int D_80071920;
int func_80040BCC(void) {
    int state = *(int*)(&D_80070328 + 0x50);
    int controls;
    int result;
    if (state == 9) {
        if ((*(int*)(&D_80070328 + 0x24) & 0x4000) == 0) goto zero;
        goto activate;
    }
    controls = *(int*)(&D_80070328 + 0x24) & 6;
    switch (controls) {
    case 2:
        {
            char* source = *(char**)(&D_80070328 + 0x138);
            int position[3];
            register int angle asm("$3");
            register int magnitude asm("$2");
            register int raw asm("$2");
            if (source == 0) goto zero;
            if (state == 12) goto zero;
            func_8004F1C8(position, source + 12, &D_80070328);
            raw = func_8004E880(position[0], position[1], 1);
            raw -= *(int*)(&D_80070328 + 0x64);
            angle = raw & 0xFFF;
            if (angle > 0x800) angle -= 0x1000;
            magnitude = angle;
            if (angle < 0) magnitude = -magnitude;
            if (magnitude >= 0x200) goto zero;
            goto activate;
        }
    case 4:
        if (state == 12) goto zero;
        goto activate;
    activate:
        func_8004BEF8(14);
        result = 1;
        goto done;
    case 6:
        result = func_80040994();
        goto done;
    default:
        goto zero;
    }
zero:
    result = 0;
done:
    return result;
}
INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_80040D10);

/**
 * ???() - func_80040F48() - MATCHING
 * Just needs variable cleanups / labelling
 * https://decomp.me/scratch/kqmRi
 */
typedef struct { int unk0, unk4; } SpyroInputPair;
typedef struct {
    int unk0, unk4, unk8;
    unsigned char unkC, unkD, unkE, unkF;
} SpyroInputSource;
extern SpyroInputSource* D_8006C570;
extern short D_8006E040;
extern unsigned char D_8006E536;
int func_8004E9E4(int);
int func_8004EA2C(int);
void func_80040F48(SpyroInputPair* arg0, int arg1) {
    SpyroInputPair sp10;
    if (D_8006E536 != 0) {
        sp10.unk0 = D_8006C570->unkE - 0x7F;
        sp10.unk4 = 0x7F - D_8006C570->unkF;
    } else {
        if (D_8006C570->unk0 & 0x1000) sp10.unk4 = 0x7F;
        else if (D_8006C570->unk0 & 0x4000) sp10.unk4 = -0x7F;
        else sp10.unk4 = 0;
        if (D_8006C570->unk0 & 0x2000) sp10.unk0 = 0x7F;
        else if (D_8006C570->unk0 & 0x8000) sp10.unk0 = -0x7F;
        else sp10.unk0 = 0;
    }
    if (arg1 != 0) {
        int temp_s0 = (((Spyro*)&D_80070328)->rotation.yaw - D_8006E040) & 0xFFF;
        arg0->unk0 = ((-sp10.unk0 * func_8004EA2C(temp_s0)) - (sp10.unk4 * func_8004E9E4(temp_s0))) >> 0xC;
        arg0->unk4 = ((sp10.unk4 * func_8004EA2C(temp_s0)) - (sp10.unk0 * func_8004E9E4(temp_s0))) >> 0xC;
    } else {
        arg0->unk0 = sp10.unk0;
        arg0->unk4 = sp10.unk4;
    }
}

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_800410F8);

/* Rev 0 source hypothesis: asm/nonmatchings/spyroupdate/func_80041404.s. */
extern volatile int D_8007038C;
void func_80041404(int amount) {
    register volatile int* rotation asm("$18");
    register int firstCos asm("$19");
    register int firstSin asm("$20");
    register int secondCos asm("$16");
    int secondSin;
    volatile int finalStored;
    volatile int verticalStored;
    volatile int headingStored;
    register int firstChange asm("$2");
    register int secondChange asm("$4");
    register int verticalProduct asm("$7");
    register int thirdChange asm("$2");
    register int finalProduct asm("$5");
    register int finalChange asm("$3");
    int nextHeading;
    int priorRotation;
    int currentRotation;
    rotation = (volatile int*)(&D_80070328 + 0x5C);
    __asm__("" : "=r"(rotation) : "0"(rotation));
    firstCos = func_8004EA2C(rotation[0]);
    firstSin = func_8004E9E4(rotation[0]);
    secondCos = func_8004EA2C((-rotation[1]) & 0xFFF);
    secondSin = func_8004E9E4((-rotation[1]) & 0xFFF);
    if (secondCos == 0) secondCos = 1;
    firstChange = (amount * secondSin) / secondCos;
    secondChange = (amount * firstCos) / secondCos;
    __asm__("" : : "r"(secondCos));
    verticalProduct = amount * firstSin;
    __asm__ volatile("" : : "r"(verticalProduct) : "memory");
    priorRotation = rotation[1];
    __asm__ volatile("nop" : : "r"(priorRotation));
    __asm__("" : : "r"(firstChange), "r"(priorRotation));
    __asm__ volatile("mult %0,%1" : : "r"(firstChange), "r"(firstCos));
    thirdChange = verticalProduct >> 12;
    verticalStored = thirdChange;
    nextHeading = (D_8007038C + secondChange) & 0xFFF;
    rotation[1] = (priorRotation + thirdChange) & 0xFFF;
    __asm__ volatile("" : : "r"(nextHeading) : "memory");
    headingStored = secondChange;
    D_8007038C = nextHeading;
    currentRotation = rotation[0];
    __asm__ volatile("mflo %0" : "=r"(finalProduct));
    finalChange = finalProduct >> 12;
    finalStored = finalChange;
    rotation[0] = (currentRotation + finalChange) & 0xFFF;
}





extern int D_8006C5BC;
int func_80041580(int minimum, int increment) {
    int angle;
    if (D_8006C5BC == 42 && *(int*)(&D_80070328 + 0x24C) == 1) {
        minimum <<= 1;
        increment <<= 1;
    }
    { int raw = *(int*)(&D_80070328 + 0xA4) - *(int*)(&D_80070328 + 0x64);
      angle = raw & 0xFFF; }
    if (angle > 0x800) angle -= 0x1000;
    if (angle > 0) {
        int value = (*(int*)(&D_80070328 + 0xA8));
        if (value < 0) {
            (*(int*)(&D_80070328 + 0xA8)) = 0;
            value = *(volatile int*)(&D_80070328 + 0xA8);
        }
        (*(int*)(&D_80070328 + 0xA8)) = value + increment;
        if (minimum < (*(int*)(&D_80070328 + 0xA8))) (*(int*)(&D_80070328 + 0xA8)) = minimum;
        if (angle < (*(int*)(&D_80070328 + 0xA8))) (*(int*)(&D_80070328 + 0xA8)) = angle;
    } else if (angle < 0) {
        int value = (*(int*)(&D_80070328 + 0xA8));
        if (value > 0) {
            (*(int*)(&D_80070328 + 0xA8)) = 0;
            value = *(volatile int*)(&D_80070328 + 0xA8);
        }
        minimum = -minimum;
        (*(int*)(&D_80070328 + 0xA8)) = value - increment;
        if ((*(int*)(&D_80070328 + 0xA8)) < minimum) (*(int*)(&D_80070328 + 0xA8)) = minimum;
        if ((*(int*)(&D_80070328 + 0xA8)) < angle) (*(int*)(&D_80070328 + 0xA8)) = angle;
    } else {
        (*(int*)(&D_80070328 + 0xA8)) = 0;
        return 0;
    }
    func_80041404((*(int*)(&D_80070328 + 0xA8)));
    return angle;
}

int func_800416F4(void) {
    int changed = 0;
    if (D_8006E536 != 0 && !(*(int*)(&D_80070328 + 0x20C) & 0x40)) {
        SpyroInputSource* input = D_8006C570;
        if ((*(int*)((char*)input + 0xC) & 0xFFFF0000) != 0x7F7F0000) {
            Vector3D vector;
            int magnitude;
            int current;
            int difference;
            int absolute;
            register int target __asm__("$2");
            vector.x = input->unkE - 0x7F;
            vector.y = input->unkF - 0x7F;
            vector.z = 0;
            magnitude = func_8004EDE8(&vector, 0);
            if (magnitude < 0x60) {
                target = *(int*)(&D_80070328 + 0xA4);
                __asm__ volatile ("" : "=r"(target) : "0"(target));
                current = *(int*)(&D_80070328 + 0x64);
                difference = (target - current) & 0xFFF;
                if (difference > 0x800) difference -= 0x1000;
                absolute = difference;
                if (absolute < 0) {
                    __asm__ volatile ("" : "=r"(absolute) : "0"(absolute));
                    absolute = -absolute;
                }
                if (absolute > 0x100) changed = 1;
                *(int*)(&D_80070328 + 0xA4) = (current + ((magnitude * difference) >> 9)) & 0xFFF;
            }
        }
    }
    return changed;
}

void func_800417FC(int rise, int fall) {
    register volatile int* bounds __asm__("$7") = (volatile int*)(&D_80070328 + 0xAC);
    register int limit __asm__("$6");
    register int value __asm__("$3");
    register int result __asm__("$2");
    int clamp;
    __asm__ volatile ("" : "=r"(bounds) : "0"(bounds));
    limit = bounds[0];
    __asm__ volatile ("" : "=r"(limit) : "0"(limit));
    value = bounds[1];
    __asm__ volatile ("" : "=r"(value) : "0"(value));
    if (value < limit) {
        result = value + rise;
        __asm__ volatile ("" : "=r"(result) : "0"(result));
        bounds[1] = result;
        clamp = limit < result;
    } else {
        result = value - fall;
        __asm__ volatile ("" : "=r"(result) : "0"(result));
        bounds[1] = result;
        clamp = result < limit;
    }
    if (clamp) bounds[1] = limit;
}

extern int D_8006C5BC;
extern volatile int D_800703D8;
extern int D_800703AC;
extern int D_800703B0;
void func_80041848(void) {
    int pending = D_800703D8;
    int level = D_8006C5BC;
    register int* output __asm__("$16") = (int*)(&D_80070328 + 0x80);
    __asm__ volatile ("" : "=r"(output) : "0"(output));
    D_800703AC = 0;
    D_800703B0 = 0;
    output[0] = pending;
    if (level == 0x2A && *(int*)(&D_80070328 + 0x24C) == 1) {
        int angle = *(int*)(&D_80070328 + 0xA4);
        int product = D_800703D8 * func_8004EA2C(angle);
        angle = *(int*)(&D_80070328 + 0xA4);
        output[0] = product >> 12;
        {
            int product = D_800703D8 * func_8004E9E4(angle);
            D_800703B0 = 0;
            D_800703AC = product >> 12;
        }
    } else {
        SHORTMATRIX* matrix = (SHORTMATRIX*)(&D_80070328 + 0x30);
        Vector3D* vector = (Vector3D*)((char*)matrix + 0x50);
        func_8004ED6C(matrix, vector, vector);
    }
}

/* Retail source: USA Rev 0 PSX.EXE 0x80041930..0x80041AE8 (110 words).
 * Builds two signed world-coordinate probes from Spyro's height, transforms
 * them once per call, and records the collision normal and polygon when the
 * signed angle result is at least 0x17. Confidence: exact; falsifiable by the
 * instruction words and the complete executable/overlay SHA-256 checks. */
void func_80041930(void) {
    Vector3D first;
    Vector3D second;
    register int var_v0 asm("$2");
    register int var_v0_2 asm("$2");
    register int var_v1 asm("$3");
    register char* temp_s1 asm("$17");
    register char* temp_s2 asm("$18");

    if ((*(int*)(&D_80070328 + 0x50) == 1) ||
        (*(int*)(&D_80070328 + 0x50) == 0x10)) {
        first.y = 0;
        first.x = 0;
        second.y = 0;
        var_v0 = -*(int*)(&D_80070328 + 0x44) + 0x20;
        var_v1 = *(int*)(&D_80070328 + 0x44) + 0x60;
        first.z = var_v0;
        goto block_9;
    }
    if (*(int*)(&D_80070328 + 0x50) == 0xA) {
        first.y = 0;
        first.x = 0;
        first.z = 0;
        second.y = 0;
        second.z = 0;
        second.x = *(int*)(&D_80070328 + 0x44) + 0x60;
    } else {
        if (*(int*)(&D_80070328 + 0x50) == 0xD) {
            first.y = 0;
            first.x = 0;
            second.y = 0;
            var_v0_2 = -*(int*)(&D_80070328 + 0x44);
            var_v1 = *(int*)(&D_80070328 + 0x44) + 0xA0;
        } else {
            first.y = 0;
            first.x = 0;
            second.y = 0;
            var_v0_2 = -*(int*)(&D_80070328 + 0x44);
            var_v1 = *(int*)(&D_80070328 + 0x44) + 0x60;
        }
        first.z = var_v0_2;
        var_v0 = var_v0_2 - 0x40;
block_9:
        second.x = var_v1;
        second.z = var_v0;
    }
    temp_s2 = &D_80070328 + 0x30;
    __asm__ volatile("" : "=r"(temp_s2) : "0"(temp_s2));
    func_8004ED6C((SHORTMATRIX*)temp_s2, &first, &first);
    temp_s1 = temp_s2 - 0x30;
    func_8004F194(&first, &first, (Vector3D*)temp_s1);
    func_8004ED6C(0, &second, &second);
    func_8004F194(&second, &second, (Vector3D*)temp_s1);
    if ((func_80018368(&first, &second) != 0) &&
        ((signed char)func_8004E880(D_80071920,
            func_8004EDE8(&D_80071918, 0), 0) >= 0x17)) {
        *(temp_s2 + 0xCE) = 1;
        func_8004F178((Vector3D*)(temp_s2 + 0xA8), &D_80071918);
        *(int*)(temp_s2 + 0xE0) = D_80071924;
    }
}

/* Retail source: asm/nonmatchings/spyroupdate/func_80041AE8.s,
 * 0x80041AE8..0x80041B64; runtime vector bytes at Spyro +0x8C. */
int func_8004EDE8(void*, int);
void func_8004F1C8(void*, void*, void*);
void func_8004F178(void*, void*);
void func_80041AE8(void) {
    Vector3D temp;
    char* position = &D_80070328 + 0x8C;
    if (func_8004EDE8(position, 0) >= 0x181) {
        func_8004F1C8(&temp, position + 0xC, position);
        if (func_8004EDE8(&temp, 0) >= 0xC1) {
            temp.z = 0;
            func_8004F178(position + 0x4C, &temp);
            *(&D_80070328 + 0xFE) = 1;
        }
    }
}

/* Retail source: asm/nonmatchings/spyroupdate/func_80041B64.s,
 * 0x80041B64..0x80041C20; runtime vector dot product is Q12. */
void func_8004EF04(Vector3D*, int);
void func_8004F08C(Vector3D*, int, int);
void func_8004F194(Vector3D*, Vector3D*, Vector3D*);
void func_80041B64(void) {
    Vector3D* position = (Vector3D*)(&D_80070328 + 0x8C);
    Vector3D* direction = (Vector3D*)(&D_80070328 + 0xD8);
    func_8004F178(position, (Vector3D*)((char*)position - 0xC));
    if (*(unsigned char*)(&D_80070328 + 0xFE) != 0) {
        int projection;
        *(int*)(&D_80070328 + 0xE0) = 0;
        func_8004EF04(direction, 0x1000);
        projection = ((-position->x * direction->x) -
                      (position->y * direction->y)) >> 12;
        if (projection > 0) {
            func_8004F08C(direction, 0x1000, projection);
            func_8004F194(position, position, direction);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_80041C20);

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_80042A44);

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_80042F64);

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_80043194);

/* Retail source: asm/nonmatchings/spyroupdate/func_80043728.s,
 * 0x80043728..0x800438F4; runtime position vectors, once per call. */
extern Spyro gSpyro __asm__("D_80070328");
extern CollisionData D_80071900;
void func_80043728(void) {
    Vector3D delta;
    Vector3D lower;
    Vector3D upper;
    register Vector3D* upperp __asm__("$17");
    register Vector3D* firstArg __asm__("$4");
    register char* state __asm__("$19");
    register Vector3D* lowerp __asm__("$16");
    register Vector3D* position __asm__("$18");
    int height;
    int surface;
    upperp = &upper;
    firstArg = upperp;
    state = &D_80070328 + 0x44;
    __asm__ volatile ("" : "=r"(state) : "0"(state));
    height = *(int*)state;
    delta.x = 0;
    delta.y = 0;
    delta.z = -height;
    func_8004F178(firstArg, &delta);
    lowerp = &lower;
    upper.z -= 0x80;
    func_8004F178(lowerp, &delta);
    lower.z += 0x80;
    func_8004ED6C((SHORTMATRIX*)(state - 0x14), upperp, upperp);
    position = (Vector3D*)(state - 0x44);
    func_8004F194(upperp, position, upperp);
    func_8004ED6C(0, lowerp, lowerp);
    func_8004F194(lowerp, position, lowerp);
    func_8004ED6C(0, &delta, &delta);
    func_8004F194(&delta, position, &delta);
    if (func_80018368(lowerp, upperp) && D_80071900.D_80071918.z > 0) {
        func_8004F1C8(&delta, &D_80071900.D_80071900, &delta);
        if (ABS(delta.x) < 8) delta.x = 0;
        if (ABS(delta.y) < 8) delta.y = 0;
        if (ABS(delta.z) < 8) delta.z = 0;
        func_8004F194(position, position, &delta);
        surface = D_80071924;
        *(int*)(state + 0x74) = 0;
        *(int*)(state + 0xC8) = surface;
    } else {
        int* counter = (int*)(&D_80070328 + 0xB8);
        (*counter)++;
    }
}

extern void func_8004F5DC(int, Vector3D*);
extern void func_8004F0E8(Vector3D*, int);

/* Retail source: asm/nonmatchings/spyroupdate/func_800438F4.s,
 * 0x800438F4..0x80043A38; signed runtime vectors, integer divide by three. */
int func_800438F4(void) {
    register int* source asm("$17") = (int*)(&D_80070328 + 0x2C0);
    Vector3D vectors[3];
    Vector3D average;
    register Vector3D* vector asm("$16");
    register Vector3D* sum asm("$19");
    register int i asm("$18");
    if (*source >= 0) {
        register int object asm("$4");
        register Vector3D* callArg asm("$5");
        vector = &average;
        func_8004F168(vector);
        object = *source;
        callArg = &vectors[0];
        i = 0;
        sum = vector;
        /* Preserve the retail call setup with GCC 2.7.2; these emit no instructions. */
        asm volatile ("" : : "r"(sum) : "memory");
        source++;
        asm volatile ("" : "=r"(callArg) : "0"(callArg) : "memory");
        vector = &vectors[0];
        func_8004F5DC(object, callArg);
        do {
            func_8004F1C8(vector, vector, (Vector3D*)source);
            func_8004F194(sum, sum, vector);
            source += 3;
            i++;
            vector++;
        } while (i < 3);
        average.x /= 3;
        average.y /= 3;
        average.z /= 3;
        func_8004F0E8(sum, 6);
        func_8004F194((Vector3D*)(&D_80070328 + 0x74), (Vector3D*)(&D_80070328 + 0x74), sum);
        if (func_8004EDE8(sum, 1) >= 33) {
            return 1;
        }
    }
    return 0;
}

/* Retail source: asm/nonmatchings/spyroupdate/func_80043A38.s,
 * 0x80043A38..0x80043ABC; vectors use signed runtime coordinates. */
void func_80043A38(int scale) {
    Vector3D* target = (Vector3D*)(&D_80070328 + 0xE8);
    func_8004F178(target, (Vector3D*)((char*)target - 0x1C));
    func_8004EF04(target, scale);
    target->x = -target->x;
    target->y = -target->y;
    target->z = -target->z;
}

/**
 * ???() - func_80043ABC() - MATCHING
 * Aligns Spyro's angles to something
 * https://decomp.me/scratch/APNca
 */
extern Spyro gSpyro __asm__("D_80070328");
/* Retail source: 0x80043ABC..0x80043E00. Motion uses signed
 * runtime vectors and 12-bit angle wrap. */
int func_8004F388(int);
void func_80043ABC(Vector3D* arg0) {
    Vector3D sp10;
    Angle12 sp20;
    if (gSpyro.unk9ha[0] >= 0x17 && gSpyro.movementState != MOVEMENT_STATE_SLIDE)
        arg0 = 0;
    if (arg0 != 0) {
        sp10.x = ((arg0->x * func_8004EA2C(gSpyro.rotation.yaw)) + (arg0->y * func_8004E9E4(gSpyro.rotation.yaw))) >> 12;
        sp10.y = ((arg0->y * func_8004EA2C(gSpyro.rotation.yaw)) - (arg0->x * func_8004E9E4(gSpyro.rotation.yaw))) >> 12;
        sp10.z = arg0->z;
        sp20.roll = -func_8004E880(func_8004F388((sp10.x * sp10.x) + (sp10.z * sp10.z)), sp10.y, 1);
        sp20.pitch = -func_8004E880(sp10.z, sp10.x, 1);
    } else {
        sp20.roll = 0;
        sp20.pitch = 0;
    }
    SUB_ANGLE(sp20.roll, sp20.roll, gSpyro.rotation.roll);
    SUB_ANGLE(sp20.pitch, sp20.pitch, gSpyro.rotation.pitch);
    gSpyro.unk7.roll += (((sp20.roll << 2) >> 4) - ((gSpyro.unk7.roll << 4) >> 6));
    gSpyro.unk7.pitch += (((sp20.pitch << 2) >> 4) - ((gSpyro.unk7.pitch << 4) >> 6));
    sp20.roll = gSpyro.unk7.roll >> 2;
    sp20.pitch = gSpyro.unk7.pitch >> 2;
    ADD_ANGLE(gSpyro.rotation.roll, gSpyro.rotation.roll, sp20.roll);
    ADD_ANGLE(gSpyro.rotation.pitch, gSpyro.rotation.pitch, sp20.pitch);
    if (arg0 != 0 && (((gSpyro.bodyRotation.roll - 0x20) & 0xFF) > 0xC0U) && (((gSpyro.bodyRotation.pitch - 0x20) & 0xFF) > 0xC0U)) {
        sp10.y = (-func_8004E9E4(sp20.roll) * (gSpyro.unk4a + 0x10)) >> 12;
        sp10.x = (-func_8004E9E4(sp20.pitch) * (gSpyro.unk4a + 0x10)) >> 12;
        sp10.z = ((0x2000 - func_8004EA2C(sp20.roll) - func_8004EA2C(sp20.pitch)) * (gSpyro.unk4a + 0x10)) >> 12;
        func_8004ED6C(&gSpyro.mat30, &sp10, &sp10);
        func_8004F194(&gSpyro.position, &gSpyro.position, &sp10);
    }
}

/**
 * ???() - func_80043E00() - MATCHING
 * Aligns Spyro's angles to something
 * https://decomp.me/scratch/rKluO
 */
/* Retail source: asm/nonmatchings/spyroupdate/func_80043E00.s,
 * 0x80043E00..0x80043F3C. Angles are signed 12-bit values. */
int func_8004E880(int, int, int);
void func_80043E00(Vector3D* arg0) {
    Angle12 sp10;
    sp10.roll = 0;
    sp10.yaw = func_8004EDE8(arg0, 0);
    sp10.pitch = func_8004E880(sp10.yaw, arg0->z, 1) + 0x8E;
    SUB_ANGLE(sp10.roll, sp10.roll, gSpyro.rotation.roll);
    SUB_ANGLE(sp10.pitch, sp10.pitch, gSpyro.rotation.pitch);
    gSpyro.unk7.roll += ((sp10.roll << 2) >> 4) - ((gSpyro.unk7.roll << 4) >> 6);
    gSpyro.unk7.pitch += ((sp10.pitch << 2) >> 4) - ((gSpyro.unk7.pitch << 4) >> 6);
    sp10.roll = gSpyro.unk7.roll >> 2;
    sp10.pitch = gSpyro.unk7.pitch >> 2;
    ADD_ANGLE(gSpyro.rotation.roll, gSpyro.rotation.roll, sp10.roll);
    ADD_ANGLE(gSpyro.rotation.pitch, gSpyro.rotation.pitch, sp10.pitch);
}
/**
 * AlignSpyroToLadder() - func_80043F3C() - MATCHING
 * https://decomp.me/scratch/Y8ufi
 */
/* Retail source: 0x80043F3C..0x800441F0. Ladder alignment uses
 * 12-bit signed angles and runtime Vector3D position units. */
void func_8004EA90(Angle*, SHORTMATRIX*, int*);
void func_80043F3C(Vector3D* arg0) {
    Angle12 sp10;
    Vector3D sp20;
    Vector3D sp30;
    Angle sp40;
    SHORTMATRIX sp48;
    sp10.roll = 0;
    if (gSpyro.unk10[2] != 0) {
        sp10.pitch = func_8004E880(arg0->z, func_8004EDE8(arg0, 0), 1);
        sp10.yaw = func_8004E880(-arg0->x, -arg0->y, 1);
    } else {
        sp10.pitch = gSpyro.rotation.pitch + 0x400;
        sp10.yaw = gSpyro.rotation.yaw;
    }
    SUB_ANGLE(sp10.roll, sp10.roll, gSpyro.rotation.roll);
    SUB_ANGLE(sp10.pitch, sp10.pitch - 0x400, gSpyro.rotation.pitch);
    SUB_ANGLE(sp10.yaw, sp10.yaw, gSpyro.rotation.yaw);
    gSpyro.unk7.roll += ((sp10.roll << 2) >> 4) - ((gSpyro.unk7.roll << 4) >> 6);
    gSpyro.unk7.pitch += ((sp10.pitch << 2) >> 4) - ((gSpyro.unk7.pitch << 4) >> 6);
    gSpyro.unk7.yaw += ((sp10.yaw << 2) >> 4) - ((gSpyro.unk7.yaw << 4) >> 6);
    sp10.roll = gSpyro.unk7.roll >> 2;
    sp10.pitch = gSpyro.unk7.pitch >> 2;
    sp10.yaw = gSpyro.unk7.yaw >> 2;
    ADD_ANGLE(gSpyro.rotation.roll, gSpyro.rotation.roll, sp10.roll);
    ADD_ANGLE(gSpyro.rotation.pitch, gSpyro.rotation.pitch, sp10.pitch);
    ADD_ANGLE(gSpyro.rotation.yaw, gSpyro.rotation.yaw, sp10.yaw);
    sp20.z = 0;
    sp20.y = 0;
    sp20.x = gSpyro.unk4a;
    func_8004F178(&sp30, &sp20);
    func_8004ED6C(&gSpyro.mat30, &sp20, &sp20);
    sp40.roll = gSpyro.rotation.roll >> 4;
    sp40.pitch = gSpyro.rotation.pitch >> 4;
    sp40.yaw = gSpyro.rotation.yaw >> 4;
    func_8004EA90(&sp40, &sp48, 0);
    func_8004ED6C(&sp48, &sp30, &sp30);
    func_8004F1C8(&sp30, &sp30, &sp20);
    func_8004F1C8(&gSpyro.position, &gSpyro.position, &sp30);
}

/**
 * ???() - func_800441F0() - MATCHING
 * https://decomp.me/scratch/31veX
 */
void func_800441F0(void) {
    char* state = &D_80070328 + 0x98;
    func_8004F168(state);
    func_8004F168(state - 0x18);
    func_8004F168(state - 0xC);
    *(int*)(&D_80070328 + 0xAC) = 0;
    *(int*)(&D_80070328 + 0xB0) = 0;
}

/**
 * ???() - func_80044240() - MATCHING
 * https://decomp.me/scratch/K5K7t
 */
/* Retail source: 0x80044240..0x800443A4; animation dispatch advances
 * once for each D_8006C648 tick. */
typedef struct {
    int unk0, unk4, unk8, unkC, unk10, unk14;
} SpyroAnimRoot;
extern SpyroAnimRoot** D_8006C558;
extern int D_8006C648;
void func_800443EC(void);
void func_800445F8(void);
void func_80044C28(void);
void func_80044CF0(void);
void func_80047138(void);
void func_80044240(void) {
    int i;
    if (g_Spyro.unk20a != 0) {
        g_Spyro.bodyAnimation.id = 0;
        g_Spyro.bodyAnimation.nextId = 0;
        g_Spyro.bodyAnimation.frame = 0;
        g_Spyro.bodyAnimation.nextFrame = 0;
        g_Spyro.unk3[0] = ((*D_8006C558)->unk14 >> 14) & 0xF0;
        func_80047138();
        return;
    }
    for (i = 0; i < D_8006C648; i++) {
        if (g_Spyro.unk17q != 0 || g_Spyro.animationState != g_Spyro.unknownAnimationStateVariable)
            func_800445F8();
        else
            func_800443EC();
        if (g_Spyro.unk13f[0] == g_Spyro.spitState) {
            if (g_Spyro.unk17t == 0)
                func_80044C28();
            else if (g_Spyro.unk17t == 6)
                func_80047138();
            else
                func_80044CF0();
        } else {
            func_80044CF0();
        }
    }
}

/**
 * ???() - func_800443A4() - MATCHING
 * https://decomp.me/scratch/dIIES
 */
void func_800443A4(int arg0) {
    unsigned char* mode = (unsigned char*)&D_80070328 + 0x1C;
    unsigned int value = *mode;
    if (value >= 0x10) {
        int selected = D_80066530[value];
        *(int*)((char*)&D_80070328 + 0x1F8) = selected;
        *mode = selected >> 4;
    }
    *(int*)((char*)&D_80070328 + 0x1F4) = arg0;
}

extern unsigned char D_80067AA8[];
extern unsigned char D_80067AA9[];
extern volatile unsigned char D_8007033F;
void func_800443EC(void) {
    register unsigned char* frame __asm__("$5") = (unsigned char*)&D_80070328 + 0x1C;
    register unsigned int raw __asm__("$4");
    register int changed __asm__("$6");
    unsigned int newFrame;
    register unsigned int check __asm__("$3");
    __asm__ volatile ("" : "=r"(frame) : "0"(frame));
    raw = *frame;
    __asm__ volatile ("" : "=r"(raw) : "0"(raw));
    check = (unsigned char)raw;
    changed = 0;
    if (check < 0x10) {
        int acc = *(int*)(frame + 0x1DC) + *(int*)(&D_80070328 + 0x1F4);
        *(int*)(frame + 0x1DC) = acc;
        if (acc >= 0x100) {
            *(int*)(frame + 0x1DC) = acc - 0x100;
            changed = 1;
        }
        newFrame = *(int*)(frame + 0x1DC) >> 4;
    } else {
        register unsigned int high __asm__("$2") = check >> 4;
        register unsigned int low __asm__("$3") = raw & 0xF;
        register unsigned int preserved __asm__("$2");
        if (low != high) {
            preserved = raw & 0xF0;
            __asm__ volatile ("" : "=r"(preserved) : "0"(preserved));
            low++;
            newFrame = preserved + low;
        } else {
            unsigned int selector = *((unsigned char*)&D_80070328 + 0x15);
            SpyroAnimRoot** roots = D_8006C558;
            unsigned int animation = *((unsigned char*)&D_80070328 + 0x17);
            char* base = (char*)roots[selector];
            int offset = animation * 20;
            int value = *(int*)(base + offset + 20);
            changed = 1;
            newFrame = (value >> 14) & 0xF0;
        }
    }
    *frame = newFrame;
    if (changed) {
        register unsigned int animation __asm__("$3") = g_Spyro.bodyAnimation.nextFrame;
        register unsigned int selector __asm__("$4") = *((unsigned char*)&D_80070328 + 0x15);
        register unsigned int next __asm__("$2") = animation + 1;
        *(volatile unsigned char*)(&D_80070328 + 0x14) = selector;
        *(volatile unsigned char*)(&D_80070328 + 0x16) = animation;
        D_8007033F = next;
        if ((unsigned char)next >= D_80067AA9[selector * 4])
            *(volatile unsigned char*)(&D_80070328 + 0x17) = D_80067AA8[selector * 4];
    }
    __asm__ volatile ("" : : "r"(frame));
}

extern unsigned char D_80067AAA[];
void func_80044514(void) {
    unsigned char* state = (unsigned char*)&D_80070328;
    register unsigned char* frame __asm__("$7") = state + 0x1C;
    register unsigned int raw __asm__("$4");
    unsigned int high, low;
    register unsigned int preserved __asm__("$2");
    __asm__ volatile ("" : "=r"(frame) : "0"(frame));
    raw = *frame;
    high = raw >> 4;
    __asm__ volatile ("" : "=r"(high) : "0"(high));
    low = raw & 15;
    if (low != high) {
        preserved = raw & 0xF0;
        __asm__ volatile ("" : "=r"(preserved) : "0"(preserved));
        low++;
        *frame = preserved + low;
        return;
    }
    {
        unsigned int selector;
        register SpyroAnimRoot** roots __asm__("$3");
        unsigned int animation;
        int value;
        register unsigned int next __asm__("$3");
        register char* base __asm__("$3");
        int offset;
        register int frameValue __asm__("$2");
        selector = state[0x15];
        roots = D_8006C558;
        animation = state[0x17];
        base = (char*)roots[selector];
        offset = animation * 20;
        base += offset;
        value = *(int*)(base + 20);
        next = animation + 1;
        frameValue = value >> 14;
        *(volatile unsigned char*)(state + 0x14) = selector;
        *(volatile unsigned char*)(state + 0x16) = animation;
        *(volatile unsigned char*)(state + 0x17) = next;
        __asm__ volatile ("" : "=r"(frameValue) : "0"(frameValue));
        frameValue &= 0xF0;
        *frame = frameValue;
        if ((unsigned char)next >= D_80067AAA[selector * 4] - 1) {
            int reset = *(int*)(state + 0x48);
            state[0x17] = 0;
            *frame = 0x71;
            *(int*)(state + 0x1F0) = 0;
            state[0x15] = reset;
            *(int*)(state + 0x1EC) = reset;
        }
    }
}


INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_800445F8);

/* Retail source: asm/nonmatchings/spyroupdate/func_80044C28.s,
 * 0x80044C28..0x80044CF0. Animation bytes advance on call. */
extern unsigned char D_80067AA8[];
extern unsigned char D_80067AA9[];
void func_80044C28(void) {
    unsigned char* state = (unsigned char*)&D_80070328;
    register unsigned char* frame __asm__("$7") = state + 0x1D;
    register unsigned int raw __asm__("$4");
    unsigned int high, low;
    register unsigned int preserved __asm__("$2");
    __asm__ volatile ("" : "=r"(frame) : "0"(frame));
    raw = *frame;
    high = raw >> 4;
    __asm__ volatile ("" : "=r"(high) : "0"(high));
    low = raw & 15;
    if (low != high) {
        preserved = raw & 0xF0;
        __asm__ volatile ("" : "=r"(preserved) : "0"(preserved));
        low++;
        *frame = preserved + low;
        return;
    }
    {
        unsigned int selector;
        register SpyroAnimRoot** roots __asm__("$3");
        unsigned int animation;
        int value;
        register unsigned int next __asm__("$3");
        register char* base __asm__("$3");
        int offset;
        register int frameValue __asm__("$2");
        selector = state[0x19];
        roots = D_8006C558;
        animation = state[0x1B];
        base = (char*)roots[selector];
        offset = animation * 20;
        base += offset;
        value = *(int*)(base + 20);
        next = animation + 1;
        frameValue = value >> 14;
        *(volatile unsigned char*)(state + 0x18) = selector;
        *(volatile unsigned char*)(state + 0x1A) = animation;
        *(volatile unsigned char*)(state + 0x1B) = next;
        __asm__ volatile ("" : "=r"(frameValue) : "0"(frameValue));
        frameValue &= 0xF0;
        *frame = frameValue;
        if ((unsigned char)next >= D_80067AA9[selector * 4])
            state[0x1B] = D_80067AA8[selector * 4];
    }
}
INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_80044CF0);

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_800451C4);

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_800458F8);

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_80045D70);

/* Retail source: asm/nonmatchings/spyroupdate/func_80046FF8.s,
 * 0x80046FF8..0x80047138; raw 12-bit angles and signed integer rates. */
extern int D_800704A4, D_800704A8, D_800704AC;
extern int D_800704B0, D_800704B4, D_800704B8;
extern volatile int D_800704BC, D_800704C0, D_800704C4;
void func_80046FF8(void) {
    register int x asm("$6");
    register int y asm("$7");
    register int z asm("$8");
    register int delta asm("$5");
    register int scaled asm("$4");
    register int rate asm("$2");
    register int other asm("$3");
    register int byteValue asm("$2");
    register int scaledZ asm("$3");
    register int oldRateScaled asm("$4");
    register int newY asm("$3");
    register int newZ asm("$2");
    rate = D_800704B0;
    x = D_800704A4;
    delta = (rate - x) & 0xFFF;
    if (delta > 0x800) delta -= 0x1000;
    scaled = delta << 7;
    other = D_800704B4;
    y = D_800704A8;
    other -= y;
    rate = D_800704BC;
    delta = other & 0xFFF;
    scaled -= rate << 4;
    scaled >>= 6;
    rate += scaled;
    D_800704BC = rate;
    asm volatile ("" : : : "memory");
    x += rate >> 6;
    D_800704A4 = x;
    if (delta > 0x800) delta -= 0x1000;
    scaled = delta << 7;
    other = D_800704B8;
    z = D_800704AC;
    other -= z;
    rate = D_800704C0;
    delta = other & 0xFFF;
    scaled -= rate << 4;
    scaled >>= 6;
    rate += scaled;
    D_800704C0 = rate;
    asm volatile ("" : : : "memory");
    newY = y + (rate >> 6);
    D_800704A8 = newY;
    if (delta > 0x800) delta -= 0x1000;
    byteValue = x >> 4;
    *(unsigned char*)(&D_80070328 + 0x10) = byteValue;
    byteValue = newY >> 4;
    *(unsigned char*)(&D_80070328 + 0x11) = byteValue;
    rate = D_800704C4;
    scaledZ = delta << 7;
    oldRateScaled = rate << 4;
    scaledZ -= oldRateScaled;
    scaledZ >>= 6;
    rate += scaledZ;
    D_800704C4 = rate;
    asm volatile ("" : : : "memory");
    newZ = z + (rate >> 6);
    D_800704AC = newZ;
    asm volatile ("" : : : "memory");
    byteValue = newZ >> 4;
    *(unsigned char*)(&D_80070328 + 0x12) = byteValue;
}

void func_80047138(void) {
    volatile unsigned char* state = (unsigned char*)&D_80070328;
    unsigned char a = state[0x14];
    unsigned char b = state[0x15];
    unsigned char c = state[0x16];
    unsigned char d = state[0x17];
    unsigned char e = state[0x1C];
    state[0x18] = a;
    state[0x19] = b;
    state[0x1A] = c;
    state[0x1B] = d;
    state[0x1D] = e;
}

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_80047190);

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_800473E4);

/* Retail source: asm/nonmatchings/spyroupdate/func_80047C7C.s,
 * 0x80047C7C..0x80047D00; input state uses Spyro runtime word offsets. */
extern int D_8006E3D0, D_8006E508;
void func_8003A964(void*, void*);
void func_80047C7C(void) {
    if (*(int*)(&D_80070328 + 0x20C) & 0x2C142) {
        func_8003A964(&D_8006E3D0, &D_8006E508);
    } else {
        *(int*)(&D_80070328 + 0x240) = 0;
    }
    {
        int* input = (int*)(&D_80070328 + 0x20C);
        int value = *input;
        if (!(value & 0x140)) *(int*)(&D_80070328 + 0x214) = 0;
        *(int*)(&D_80070328 + 0x210) = value;
        *input = 0;
    }
}

extern int D_8006C5C4;
extern short D_80065920[];
extern short D_800658A0[];
/* Retail source: asm/nonmatchings/spyroupdate/func_80047D00.s,
 * 0x80047D00..0x80047E6C; signed trigonometric table values. */
void func_80047D00(Moby* object) {
    Moby* moby = object;
    Vector3D offset;
    *(int*)(&D_80070328 + 0x20C) |= 0x10000040;

    func_8004F1C8(&offset, &D_80070328, &moby->position);
    *(int*)(&D_80070328 + 0x238) = func_8004E880(-offset.x, -offset.y, 0);
    if (D_8006C5C4) {
        int cosine;
        offset.x = (D_80065920[moby->angle.yaw] * 39) >> 6;
        cosine = D_800658A0[moby->angle.yaw];
        offset.z = 0;
        offset.y = (cosine * 39) >> 6;
    } else {
        int cosine;
        offset.x = (D_80065920[moby->angle.yaw] * 13) >> 5;
        cosine = D_800658A0[moby->angle.yaw];
        offset.z = 0;
        offset.y = (cosine * 13) >> 5;
    }
    func_8004F194((Vector3D*)(&D_80070328 + 0x22C), &offset, &moby->position);
    *(int*)(&D_80070328 + 0x218) = 0;
}

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_80047E6C);

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_80048210);

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_80048444);

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_800486FC);

/* Retail source: asm/nonmatchings/spyroupdate/func_80048948.s,
 * 0x80048948..0x800489CC; state offsets are runtime Spyro words. */
extern int D_8006C648;
void func_80048948(void) {
    int movement = *(int*)(&D_80070328 + 0x50);
    *(int*)(&D_80070328 + 0x298) = -1;
    *(int*)(&D_80070328 + 0x24) = 0;
    if (movement != 7) {
        int value = *(int*)(&D_80070328 + 0x284) - D_8006C648;
        *(int*)(&D_80070328 + 0x284) = value;
        if (value < 0) *(int*)(&D_80070328 + 0x284) = 0;
    }
    if (*(int*)(&D_80070328 + 0x244) != 0) {
        char* target = *(char**)(&D_80070328 + 0x250);
        *(int*)(target + 0x18) = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_800489CC);

extern Vector3D D_8006E020;
extern short D_80065920[];
extern short D_800658A0[];
void func_800491F4(void) {
    Vector3D delta;
    int angle;
    int radius;
    int cosine;
    func_8004F1C8(&delta, &D_8006E020, (Vector3D*)&D_80070328);
    angle = func_8004E880(delta.x, delta.y, 0);
    cosine = D_80065920[angle];
    radius = *(int*)(&D_80070328 + 0x44);
    delta.x = (cosine * radius) >> 12;
    delta.y = (D_800658A0[angle] * radius) >> 12;
    delta.z = 0;
    func_8004F194(&delta, &delta, (Vector3D*)&D_80070328);
    if (!func_80013E38(&D_8006E020, &delta, 0))
        *(&D_80070328 + 0x1E) = 0;
    else
        *(&D_80070328 + 0x1E) = 5;
}

/* Retail source: asm/nonmatchings/spyroupdate/func_800492DC.s,
 * 0x800492DC..0x80049484; angles are 12-bit turns. */
extern volatile int turnA __asm__("D_80070328+396");
extern volatile int turnB __asm__("D_80070328+400");
extern volatile int turnFlags __asm__("D_80070328+524");
void func_8004ECF4(SHORTMATRIX*, void*);
int func_8004EDE8(void*, int);
void func_800492DC(Vector3D* source) {
    SHORTMATRIX matrix;
    Vector3D vector;
    int angle;
    register int mask __asm__("$3");
    int flags;
    vector.x = 100;
    vector.y = 0;
    vector.z = 64;
    func_8004ED6C((SHORTMATRIX*)(&D_80070328 + 0x30), &vector, &vector);
    func_8004F194(&vector, &vector, (Vector3D*)&D_80070328);
    func_8004F1C8(&vector, source, &vector);
    func_8004ECF4(&matrix, &D_80070328 + 0x30);
    func_8004ED6C(&matrix, &vector, &vector);
    angle = func_8004E880(func_8004EDE8(&vector, 0), vector.z, 1) & 0xFFF;
    turnA = angle;
    if (angle > 0x800) turnA = angle - 0x1000;
    if (turnA < -0x180) turnA = -0x180;
    if (turnA > 0x180) turnA = 0x180;
    angle = func_8004E880(vector.x, vector.y, 1) & 0xFFF;
    turnB = angle;
    if (angle > 0x800) turnB = angle - 0x1000;
    if (turnB < -0x200) turnB = -0x200;
    mask = 0x10000000;
    if (turnB > 0x200) {
        turnB = 0x200;
        __asm__ volatile("" : "=r"(mask) : "0"(mask));
    }
    flags = turnFlags;
    mask |= 4;
    turnFlags = flags | mask;
}

void func_80049484(int arg0) {
    func_80049ACC(0xC1, arg0);
}

extern void func_8004F178(void*, void*);
extern int func_8001BA30(Vector3D*, int, int, int, int, int);
extern int func_80019138(Vector3D*, int, int, int, int, int);
void func_800494A8(void) {
    Vector3D point;
    int flag = 0x80000;
    func_8004F178(&point, &D_80070328);
    point.z -= *(int*)(&D_80070328 + 0x44);
    func_8001BA30(&point, 0x80, 1, 0, flag,
                   *(int*)(&D_80070328 + 0x250));
    if (func_80019138(&point, 0x80, 1, 0, flag, 0)) {
        register int* surface __asm__("$16") = &D_80071924;
        if (func_80040954(*surface) == 3) {
            D_8006D048.m_SurfaceData[*surface & 0x3F]->unk4 |= flag;
        }
    }
}

extern void func_8004F110(Vector3D*, int);
extern int func_8001830C(Vector3D*, Vector3D*, int, int, int);
void func_80049590(void) {
    Vector3D point;
    int flag;
    int state = *(int*)(&D_80070328 + 0x130);
    if (state & 0x40000) flag = 0x600000;
    else if (state & 0x20000) flag = 0x200000;
    else return;
    func_8004F178(&point, &D_80070328 + 0x80);
    func_8004F110(&point, 3);
    func_8004F194(&point, &point, (Vector3D*)&D_80070328);
    if (func_8001830C((Vector3D*)&D_80070328, &point, 0, flag, 0)) {
        register int* surface __asm__("$16") = &D_80071924;
        if (func_80040954(*surface) == 3) {
            D_8006D048.m_SurfaceData[*surface & 0x3F]->unk4 |= flag;
        }
    }
}

/* Retail source hypothesis: asm/nonmatchings/spyroupdate/func_80049688.s, 0x80049688..0x800498C0. */
extern int D_8006C418[2];
extern int D_8006C568;
extern unsigned char D_8007042A;
extern char* D_8006EE2C;
typedef struct {
    int pad[15];
    int unk3C;
} ScratchAnimObject_49688;


int func_80049688(unsigned char* arg3) {
    int temp_v0;
    register int tableOffset asm("$2");
    register int* temp_a0 asm("$4");
    register int* table asm("$6");
    register int* var_v1 asm("$3");
    int var_s0;
    register unsigned char* var_a1 asm("$5");
    register unsigned char* var_a3 asm("$7");

    var_a3 = arg3;
    if ((g_Spyro.unk20[2] == 0) && !(g_Spyro.unk17a & 8) && (g_Spyro.unk13f[0] == 0) && ((D_8006C5BC != 0xC) || (D_8006C568 != 1) || (g_Spyro.animationState != ANIMATION_STATE_STAND))) {
        var_a1 = (unsigned char*)&g_Spyro.bodyAnimation.nextId;
        __asm__("" : "=r"(var_a1) : "0"(var_a1));
        if ((*var_a1 == g_Spyro.bodyAnimation.id) && ((unsigned char) g_Spyro.bodyAnimation.nextFrame < (unsigned char) g_Spyro.bodyAnimation.frame)) {
            if (g_Spyro.union144.a.unk13cc == 0) {
                g_Spyro.union144.a.unk13cc = 1;
                if (g_Spyro.animationState == ANIMATION_STATE_STAND) {
                    temp_v0 = g_Spyro.union144.a.unk13cb - 1;
                    g_Spyro.union144.a.unk13cb = temp_v0;
                    if (temp_v0 <= 0) {
                        var_s0 = D_8007042A;
                        table = D_8006C418;
                        tableOffset = var_s0 << 2;
                        temp_a0 = (int*)((char*)table + tableOffset);
                        if (((ScratchAnimObject_49688*)(D_8006EE2C + (*temp_a0 * 4)))->unk3C == 0) {
                            var_a3 = var_a1 + 0xED;
                            var_a1 = D_8006EE2C;
                            var_v1 = temp_a0;
                            var_s0 += 1;
loop_13:

                            var_v1 += 1;
                            if ((int) var_s0 >= 2) {
                                var_v1 = table;
                                var_s0 = 0;
                            }
                            if (var_s0 != *var_a3) {
                                var_s0 += 1;
                                if (((ScratchAnimObject_49688*)(var_a1 + (*var_v1 * 4)))->unk3C != 0) {
                                    var_s0 -= 1;
                                } else {
                                    goto loop_13;
                                }
                            }
                            if (
                                ((ScratchAnimObject_49688*)((D_8006C418[var_s0] * 4 + D_8006EE2C)))->unk3C == 0
                            ) {
                                return 0;
                            }
                        }
                        func_8004BEF8(D_8006C418[var_s0++]);
                        if (var_s0 >= 2) {
                            var_s0 = 0;
                        }
                        g_Spyro.unk10[6] = var_s0;
                        return 1;
                    }
                    return 0;
                }
                func_8004BEF8(0);
                return 1;
            }
            return 0;
        }
    }
    g_Spyro.union144.a.unk13cc = 0;
    return 0;
}

extern int D_8006582C, D_80065834;
extern unsigned char D_8006C408, D_8006C409, D_8006C40A, D_8006C40B;
extern int D_8006C5BC, D_8006C5C8, D_8006C658;
extern int D_8006C6BC, D_8006C70C, D_8006C784, D_8006C7E4;
extern int D_8006FA38, D_8006FBD0;
extern char D_8006D088;
void func_8003B74C(void*);
void func_80054AF8(void);
/* Retail source: USA Rev 0 PSX.EXE 0x800498C0..0x80049ACC (131 words).
 * One call updates integer death and level counters, consumes at most one
 * life, and selects checkpoint reset or game over using the retail level and
 * state tests. Confidence: exact; falsifiable by all instruction words and
 * the complete executable/overlay SHA-256 checks. */
void func_800498C0(void) {
    if (D_8006FA38 < 0) {
        D_8006C70C += 1;
        D_8006C6BC += 1;
    }
    if (D_8006C658 == 1) {
        D_8006C7E4 = D_8006C658;
        return;
    }
    if (D_8006C5BC == 0x11) {
        D_8006C408 += 1;
    } else if (D_8006C5BC == 0x1B) {
        D_8006C409 += 1;
    } else if (D_8006C5BC == 0x25) {
        D_8006C40A += 1;
    } else if (D_8006C5BC == 0x2F) {
        D_8006C40B += 1;
    }
    D_8006582C = 0;
    if ((D_8006FA38 < 0) &&
        ((D_8006C5BC != 0x15) || (D_8006C5C8 != 1))) {
        *(int*)(&D_80070328 + 0x280) = D_80065834;
        if (((D_8006C5BC / 10) * 10) != (D_8006C5BC - 8)) {
            D_8006C784 -= 1;
        }
        if (D_8006C784 >= 0) {
            func_8003B74C(&D_8006D088);
            D_8006FBD0 = 1;
            *(int*)(&D_80070328 + 0x240) = 0;
            return;
        }
        func_80054AF8();
        return;
    }
    func_8003B74C(&D_8006D088);
}

INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_80049ACC);

// has overlay version in "animation.c"
INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_80049D70);

// has overlay version in "animation.c"
INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_8004B324);

/**
 * PlaySpyroSounds() - func_8004BA6C() - MATCHING
 * Exe version of the PlaySpyroSounds from overlay
 * https://decomp.me/scratch/yR0vS
 */
void PlaySpyroSounds() {
    int animationId;
    int animationFrame;

    if (g_Spyro.unk20a != 0) {
        animationId = g_Spyro.critterMobyPtr->animationState.id;
        switch (g_Spyro.critterMode) {
        case CRITTER_SHEILA:
            animationId += ANIMATION_STATE_SHEILA_IDLE;
            break;
        case CRITTER_BENTLEY:
            animationId += ANIMATION_STATE_BENTLEY_IDLE;
            break;
        case CRITTER_SGT_BYRD:
            animationId += ANIMATION_STATE_SGT_BYRD_IDLE;
            break;
        case CRITTER_AGENT_9:
            animationId += ANIMATION_STATE_AGENT_9_IDLE;
            break;
        case CRITTER_BENTLEY_BOXING:
            animationId += ANIMATION_STATE_BENTLEY_BOXING_IDLE;
            break;
        case CRITTER_SUBS:
            animationId += ANIMATION_STATE_SUB_IDLE;
            break;
        case CRITTER_SPARX:
            animationId += ANIMATION_STATE_SPARX_IDLE;
            break;
        case CRITTER_HUNTER_4:
            animationId += ANIMATION_STATE_HUNTER_4_FLY;
            break;
        case CRITTER_HUNTER_3:
            animationId += ANIMATION_STATE_HUNTER_3_IDLE;
            break;
        case CRITTER_HUNTER_1:
            animationId += ANIMATION_STATE_HUNTER_1_PLANE;
            break;
        }
        animationFrame = g_Spyro.critterMobyPtr->animationState.frame;
    }
    else {
        animationId = g_Spyro.bodyAnimation.id;
        animationFrame = g_Spyro.bodyAnimation.frame;
    }

    if (g_Spyro.movementState == MOVEMENT_STATE_SWIM_UNDERWATER || g_Spyro.movementState == MOVEMENT_STATE_SWIM_CHARGE) {
        if (func_8003BF6C(g_SoundTablePtr->underwater, g_Spyro.unk22[4]) == 0) {
            g_Spyro.unk22[4] = PlaySound(g_SoundTablePtr->underwater, 0, 4);
        }
    }
    else if (func_8003BF6C(g_SoundTablePtr->underwater, g_Spyro.unk22[4]) != 0) {
        func_8003BE70(g_Spyro.unk22[4]);
        g_Spyro.unk22[4] = -1;
    }

    if (g_Spyro.unk22[6] != animationFrame) {
        switch (animationId) {
        case ANIMATION_STATE_TIPTOE:
            if (animationFrame == 5 || animationFrame == 13) {
                int surface = g_Spyro.unk11[2] >> 6;
                func_8003BB10(0, D_80067968[D_8006C58C][surface], 0);
                g_Spyro.unk22[6] = animationFrame;
            }
            break;
        case ANIMATION_STATE_RUN:
            if (animationFrame == 7 || animationFrame == 9 || animationFrame == 17 || animationFrame == 0) {
                int surface = g_Spyro.unk11[2] >> 6;
                func_8003BB10(0, D_80067968[D_8006C58C][surface], 0);
                g_Spyro.unk22[6] = animationFrame;
            }
            break;
        case ANIMATION_STATE_BONK:
            {
                int handler;
                if (animationFrame == 2 || animationFrame == 5) {
                    handler = PlaySound(g_SoundTablePtr->spyroStop, 0, 0);
                    g_Spyro.unk22[6] = animationFrame;
                    if (handler >= 0 && animationFrame == 5) {
                        func_8003C140(handler, 0xC00);
                        func_8003C0B0(handler, 0xE00);
                    }
                }
                break;
            }
        case ANIMATION_STATE_HURT:
            {
                int handler;
                if (animationFrame == 11 || animationFrame == 14) {
                    handler = PlaySound(g_SoundTablePtr->spyroStop, 0, 0);
                    g_Spyro.unk22[6] = animationFrame;
                    if (handler >= 0) {
                        if (animationFrame == 14) {
                            func_8003C140(handler, 0xC00);
                            func_8003C0B0(handler, 0xE00);
                        }
                    }
                }
                break;
            }
        case 2:
            if (animationFrame == 2 || animationFrame == 12) {
                int surface = g_Spyro.unk11[2] >> 6;
                func_8003BB10(0, D_80067968[D_8006C58C][surface], 0);
                g_Spyro.unk22[6] = animationFrame;
            }
            break;
        case ANIMATION_STATE_DEATH_FALL_OVER:
            {
                int handler;
                if (animationFrame == 12 || animationFrame == 20) {
                    handler = PlaySound(g_SoundTablePtr->spyroStop, 0, 0);
                    g_Spyro.unk22[6] = animationFrame;
                    if (handler >= 0) {
                        if (animationFrame == 20) {
                            func_8003C140(handler, 0xC00);
                            func_8003C0B0(handler, 0xE00);
                        }
                    }
                }
                break;
            }
        default:
            if (g_PlaySpyroSounds != 0) {
                g_PlaySpyroSounds();
            }
            break;
        }
    }

    if (animationFrame != g_Spyro.unk22[6]) {
        g_Spyro.unk22[6] = -1;
    }
}

/**
 * AlignSpyroRotation() - func_8004BDF0() - MATCHING
 * Exe version of the align Spyro rotation function from overlay
 * https://decomp.me/scratch/wthTK
 */
/* Retail source: asm/nonmatchings/spyroupdate/func_8004BDF0.s,
 * 0x8004BDF0..0x8004BEF8. State dispatch runs once per call. */
extern char D_8006E548[];
void func_8004BDF0(int slot) {
    if (!(*(int*)(&D_80070328 + 0x20C) & 0x8000)) {
        D_8006C570 = (SpyroInputSource*)(D_8006E548 + slot * 16);
        switch (*(int*)(&D_80070328 + 0x48)) {
        case 0: case 1: case 2: case 3: case 4: case 5:
        case 8: case 13: case 14: case 15: case 16: case 31:
            func_80043ABC((Vector3D*)(&D_80070328 + 0xCC));
            break;
        case 6:
            if (*(int*)(&D_80070328 + 0x50) == 13)
                func_80043F3C((Vector3D*)(&D_80070328 + 0xD8));
            else
                func_80043ABC(0);
            break;
        case 7: case 18: case 46:
            func_80043ABC(0);
            break;
        case 22:
            func_80043E00((Vector3D*)(&D_80070328 + 0x8C));
            break;
        case 17: case 24:
            break;
        default:
            if (unk_ovlheader_800742F8 != 0)
                unk_ovlheader_800742F8(slot);
            break;
        }
        (*(int*)(&D_80070328 + 0x54))++;
    }
}

/**
 * UpdateMovementState() - func_8004BEF8() - MATCHING
 * Ready to add, but there's some oddities in here
 * https://decomp.me/scratch/RSA1r
 */
/* Retail Rev 0: asm/nonmatchings/spyroupdate/func_8004BEF8.s,
 * 0x8004BEF8..0x8004CCA0 plus 48 jump-table words at 0x80010AF8.
 * Movement state dispatch runs once per call. C hypothesis:
 * https://decomp.me/scratch/RSA1r */
extern Moby* D_8006C550;
extern Moby* D_8006C704;
extern short D_80065920[0x100], D_800658A0[0x100];
void func_8004BEF8(unsigned int arg0) {
    Vector3D sp10;
    SpyroInputPair something;
    Vector3D sp28;
    Vector3D sp38;
    Vector3D sp48;
    int var_s4;
    int var_v1_2;

    if ((D_8006C5BC == 11) && ((arg0 == 0x2A) || (arg0 == 0x28) || (arg0 == 0x29))) {
        arg0 = 0x2C;
    }

    if (g_Spyro.unk22[2] >= 0) {
        if (func_8003BF6C(g_Spyro.unk22[3], g_Spyro.unk22[2]) != 0) {
            func_8003BE70(g_Spyro.unk22[2]);
        }
        g_Spyro.unk22[2] = -1;
    }

    g_Spyro.unk22[6] = -1;
    if ((arg0 == 0x11) && (g_Spyro.superflyTimer != 0)) {
        arg0 = 0x21;
    }

    g_Spyro.unk13a[0] = 0;

    if (g_Spyro.unk20a != 0) {
        g_Spyro.unk4a = g_Spyro.critterMobyPtr->distanceToGround;
    }
    else {
        g_Spyro.unk4a = 0x164;
    }

    switch (arg0) {
    case 0:
    case 15:
        g_Spyro.movementState = MOVEMENT_STATE_STAND;
        g_Spyro.unk5 = 0;
        func_800441F0();
        g_Spyro.grounded = 1;
        g_Spyro.union144.a.unk13cb = func_8003636C(1, 3);
        g_Spyro.union144.a.unk13cc = 0;
        g_Spyro.unk20a = 0;
        g_Spyro.critterMobyPtr = 0;
        break;

    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        g_Spyro.movementState = MOVEMENT_STATE_WALK;
        g_Spyro.unk5 = 0;
        g_Spyro.unk8[0] = func_8004EDE8(&g_Spyro.unk7a[3], 0);
        if (arg0 == 4) {
            MAX(g_Spyro.unk8[0], 0x1400);
            if (g_Spyro.animationState != ANIMATION_STATE_FALL_OFF_SKATEBOARD) {
                PlaySound(g_SoundTablePtr->spyroSkid, 0, 0);
            }
        } else if (arg0 == 5) {
            MIN(g_Spyro.unk7c, 0);
            PlaySound(g_SoundTablePtr->spyroSkid, 0, 0);
        }
        func_80043A38(0xC00);
        g_Spyro.union144.a.unk13cb = 0;
        g_Spyro.grounded = 1;
        g_Spyro.unk20a = 0;
        g_Spyro.critterMobyPtr = 0;
        break;

    case 6:
        if ((g_Spyro.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (SpawnParticle != 0) && (g_Spyro.unk4[0] < 0)) {
            func_8004F178(&sp10, &g_Spyro.position);
            sp10.z = -g_Spyro.unk4[0];
            SpawnParticle(6, 0x2E, &sp10, 0);
            SpawnParticle(4, 0x29, &sp10, 0);
        }
        if (g_Spyro.movementState == MOVEMENT_STATE_LADDER) {
            g_Spyro.unk5 = 0;
            if (((unsigned char)pad.dpadPressed) != 0) {
                something.unk0 = 0;
                something.unk4 = 0x7F;
            } else {
                func_80040F48(&something, 0);
                if (ABS(something.unk0) > ABS(something.unk4)) {
                    g_Spyro.unk5 |= 0x80;
                    g_Spyro.union144.a.unk13cb = g_Spyro.position.z;
                }
                something.unk0 = ((something.unk0 * 55) << 6) >> 7;
            }
            g_Spyro.unk7a[2].x = ( something.unk0 * func_8004E9E4(g_Spyro.rotation.yaw)) >> 12;
            g_Spyro.unk7a[2].y = (-something.unk0 * func_8004EA2C(g_Spyro.rotation.yaw)) >> 12;
            g_Spyro.unk7a[2].z = ((something.unk4 + 0x40) * 0xDC0) >> 7;
            MAX(g_Spyro.unk7a[2].z, 0xDC0); // would be nice if I could merge this with the line above
            g_Spyro.unk8[0] = func_8004EDE8(&g_Spyro.unk7a[2], 0);
        } else {
            g_Spyro.movementState = MOVEMENT_STATE_JUMP_HOVER;
            func_8004F178(&g_Spyro.unk7a[2], &g_Spyro.unk7a[3]);
            g_Spyro.unk8[0] = func_8004EDE8(&g_Spyro.unk7a[3], 0);
            g_Spyro.unk7a[2].z = 0xDC0;
            g_Spyro.unk5 = 0;
            if (g_Spyro.animationState == ANIMATION_STATE_SINK) {
                g_Spyro.union144.a.unk13cb = 1;
            } else {
                g_Spyro.union144.a.unk13cb = 0;
            }
        }
        g_Spyro.grounded = 0;
        PlaySound(g_SoundTablePtr->jump, 0, 0); //0,0
        g_Spyro.unk20a = 0;
        g_Spyro.critterMobyPtr = 0;
        break;

    case 7:
        if (g_Spyro.animationState == ANIMATION_STATE_BONK) {
            g_Spyro.unk5 = 2;
        } else {
            g_Spyro.unk5 = 0;
        }
        g_Spyro.movementState = MOVEMENT_STATE_FALL;
        g_Spyro.unk8[0] = func_8004EDE8(&g_Spyro.unk7a[3], 0);
        g_Spyro.grounded = 0;
        g_Spyro.unk15b = 1;
        g_Spyro.unk20a = 0;
        g_Spyro.critterMobyPtr = 0;
        break;

    case 8:
        g_Spyro.movementState = MOVEMENT_STATE_STAND;
        g_Spyro.unk5 = 0;
        func_800441F0();
        g_Spyro.grounded = 1;
        g_Spyro.unk20a = 0;
        g_Spyro.critterMobyPtr = 0;
        break;

    case 13:
        g_Spyro.movementState = MOVEMENT_STATE_CHARGE;
        g_Spyro.unk5 = 0;
        g_Spyro.unk8[0] = func_8004EDE8(&g_Spyro.unk7a[3], 0);
        g_Spyro.horizontalSpeed = 0x1E80;
        func_80043A38(0xC00);
        g_Spyro.grounded = 1;
        g_Spyro.unk13a[0] = 0x20000;
        g_Spyro.union144.a.unk13cb = 0;
        var_s4 = 0x1869F; // ??????
        var_v1_2 = (g_Spyro.rotation.yaw - camera.unk48) & 0xFFF;
        MAX_SIGNED(var_v1_2, 0x800);
        if (ABS(var_v1_2) >= 0x100) {
            Moby* var_s2 = D_8006C550;
            while (var_s2 < D_8006C704) {
                if (!(var_s2->state & 0x80) && (var_s2->unknownCollision != 0)) {
                    func_8004F1C8(&sp28, &var_s2->position, &g_Spyro.position);
                    sp28.z += g_Spyro.unk4a;
                    if (ABS(sp28.z) < 0x400) {
                        int var_v1_3 = (func_8004E880(sp28.x, sp28.y, 1) - g_Spyro.rotation.yaw) & 0xFFF;
                        MAX_SIGNED(var_v1_3, 0x800);
                        if (ABS(var_v1_3) < 0x200) {
                            int temp_v0_3 = func_8004EDE8(&sp28, 0);
                            int temp_v0_4;
                            int temp_v1;
                            if (temp_v0_3 < 0x1800) {
                                temp_v0_4 = temp_v0_3 - 0x800;
                                temp_v1 = ABS(temp_v0_4);
                                temp_v1 += (ABS(var_v1_3) * 4);
                                if (temp_v1 < var_s4) {
                                    g_Spyro.union144.a.unk13cb = (int)var_s2; // ??????
                                    var_s4 = temp_v1; // ??????
                                }
                            }
                        }
                    }
                }
                var_s2++;
            }
        }
        g_Spyro.unk20a = 0;
        g_Spyro.critterMobyPtr = 0;
        break;

    case 14:
        if (SpawnParticle != 0) {
            SpawnParticle(8, 0x21, 0, (Vector3D* )1); // wtf? check the signature lol
        }
        g_Spyro.movementState = MOVEMENT_STATE_WALK;
        g_Spyro.unk5 = 0;
        func_8004F168(&sp38);
        func_8004F1C8(&g_Spyro.unk7a[2], &sp38, &g_Spyro.unk7a[1]);
        func_8004F110(&g_Spyro.unk7a[2], 2);
        func_8004F178(&g_Spyro.unk7a[1], &g_Spyro.unk7a[2]);
        MIN(g_Spyro.unk7a[2].z,0);
        g_Spyro.grounded = 1;
        PlaySound(g_SoundTablePtr->bonk, 0, 0); // 0,0
        pad.unk3[3] = 0x78;
        pad.unk3[2] = 0xF;
        g_Spyro.unk20a = 0;
        g_Spyro.critterMobyPtr = 0;
        break;

    case 16:
        g_Spyro.union144.a.unk13cb = g_Spyro.movementState;
        g_Spyro.movementState = MOVEMENT_STATE_HURT;
        g_Spyro.unk5 = 0;
        if (g_Spyro.unk17a & 0x400) {
            func_8004F178(&g_Spyro.unk7a[2], &g_Spyro.unk17e);
            func_8004F0E8(&g_Spyro.unk7a[2], 6);
        } else {
            if (g_Spyro.unk22[5] >= 0) {
                g_Spyro.unk7a[2].x = (D_80065920[g_Spyro.unk22[5]] << 1) >> 2;
                g_Spyro.unk7a[2].y = (D_800658A0[g_Spyro.unk22[5]] << 1) >> 2;
                g_Spyro.unk7a[2].z = 0;
            } else {
                func_8004F168(&g_Spyro.unk7a[2]);
            }
        }
        func_8004F178(&g_Spyro.unk7a[1], &g_Spyro.unk7a[2]);
        func_80043A38(0xC00);
        g_Spyro.grounded = 1;
        pad.unk3[0] = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        PlaySound(g_SoundTablePtr->spyroHurt, 0, 0); //0,0
        g_Spyro.unk20a = 0;
        g_Spyro.critterMobyPtr = 0;
        break;

    case 17:
    case 24:
        // &g_Spyro.unk7a[3] might need usage before the func_8004F178 call?
        if (g_Spyro.movementState != MOVEMENT_STATE_GLIDE) {
            g_Spyro.movementState = MOVEMENT_STATE_GLIDE;
            g_Spyro.unk5 = 0;
            func_8004F178(&g_Spyro.unk7a[2], &g_Spyro.unk7a[3]);
            MAX(g_Spyro.unk7a[2].z,0);
            g_Spyro.unk8[0] = func_8004EDE8(&g_Spyro.unk7a[3], 0);
            MIN(g_Spyro.unk8[0],0x780);
            MAX(g_Spyro.unk8[0],0x1900);
            g_Spyro.grounded = 0;
            g_Spyro.unk15b = 0;
            g_Spyro.union144.a.unk13cc = g_Spyro.position.z;
        }
        g_Spyro.unk20a = 0;
        g_Spyro.critterMobyPtr = 0;
        break;

    case 18:
        if ((g_Spyro.movementState != MOVEMENT_STATE_GLIDE) || (g_Spyro.unk17a & 0x80)) {
            g_Spyro.union144.a.unk13cc = g_Spyro.position.z + 0x400;
        }
        g_Spyro.movementState = MOVEMENT_STATE_JUMP_HOVER;
        g_Spyro.unk5 = 0;
        func_8004F178(&g_Spyro.unk7a[2], &g_Spyro.unk7a[3]);
        g_Spyro.unk8[0] = func_8004EDE8(&g_Spyro.unk7a[3], 0);
        g_Spyro.unk7a[2].z = 0xC00;
        g_Spyro.grounded = 0;
        g_Spyro.unk20a = 0;
        g_Spyro.critterMobyPtr = 0;
        break;

    case 22:
        if (g_Spyro.movementState != MOVEMENT_STATE_SUPERCHARGE) {
            if (g_Spyro.movementState == 11 || g_Spyro.movementState == 12) {
                PlaySound(g_SoundTablePtr->waterSurface, 0, 0); // 0,0
                func_8004F178(&sp48, &g_Spyro.position);
                sp48.z += 0x400;
                sp48.z = func_8001A358(&sp48, 0x800);
                if (sp48.z != 0) {
                    if (D_80071900.D_80071934 != 0) {
                        if (SpawnParticle != 0) {
                            SpawnParticle(6, 0x2E, &sp48, 0);
                            SpawnParticle(4, 0x29, &sp48, 0);
                        }
                    }
                }
                g_Spyro.unk5 = 3;
            } else if (g_Spyro.ticksSinceLastSurfaceTouch >= 4) {
                g_Spyro.unk5 = 2; // DOUBLE JUMP PATCH: make this zero, or remove this else if statement
            } else {
                g_Spyro.unk5 = 0;
            }
            g_Spyro.movementState = MOVEMENT_STATE_CHARGE;
            g_Spyro.unk13a[0] = 0x20000;
            g_Spyro.unk8[0] = func_8004EDE8(&g_Spyro.unk7a[3], 0);
            if (g_Spyro.unk8[0] < 0x800) {
                g_Spyro.unk8[0] = 0x800;
                g_Spyro.unk7a[2].x = (D_80065920[g_Spyro.bodyRotation.yaw] << 1) >> 2;
                g_Spyro.unk7a[2].y = (D_800658A0[g_Spyro.bodyRotation.yaw] << 1) >> 2;
                g_Spyro.unk7a[2].z = 0; // DOUBLE JUMP PATCH: remove this line
                if (g_Spyro.unk5 == 3) {
                    g_Spyro.unk7a[2].z = g_Spyro.unk7a[3].z;
                }
            } else {
                func_8004F178(&g_Spyro.unk7a[2], &g_Spyro.unk7a[3]);
            }
            g_Spyro.horizontalSpeed = 0x1800;
        } else {
            g_Spyro.unk13a[0] = 0x60000;
            g_Spyro.unk5 = 0;
        }
        g_Spyro.grounded = 0;
        g_Spyro.union144.a.unk13cb = 0;
        g_Spyro.unk20a = 0;
        g_Spyro.critterMobyPtr = 0;
        break;

    case 31:
        g_Spyro.movementState = MOVEMENT_STATE_DEATH;
        g_Spyro.unk5 = 0;
        func_80043A38(0xC00);
        g_Spyro.grounded = 1;
        pad.unk3[0] = 0xF;
        g_Spyro.unk20a = 0;
        g_Spyro.critterMobyPtr = 0;
        break;

    case 46:
        g_Spyro.movementState = MOVEMENT_STATE_HEADBASH;
        g_Spyro.unk5 = 0;
        func_8004F168(&g_Spyro.unk7a[2]);
        g_Spyro.unk7a[2].z = 0x800;
        g_Spyro.grounded = 0;
        g_Spyro.unk13a[0] = 0x20000;
        g_Spyro.union144.a.unk13cb = 0;
        g_Spyro.unk20a = 0;
        g_Spyro.critterMobyPtr = 0;
        break;

    default:
        if (unk_ovlheader_800742FC != 0) {
            unk_ovlheader_800742FC(arg0);
        }
        break;
    }

    g_Spyro.unk6b = g_Spyro.animationStateFrames;
    g_Spyro.unk15c = 0;
    g_Spyro.unk15e = 0;
    g_Spyro.unk16a[1] = 0;
    g_Spyro.animationState = arg0;
    g_Spyro.animationStateFrames = 0;

}

// has overlay version in "animation.c"
INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_8004CCA0);

/* Retail source: asm/nonmatchings/spyroupdate/func_8004E4E4.s,
 * 0x8004E4E4..0x8004E56C; raw 12-bit style angle units. */
extern int D_8006C5BC;
int func_8004F388(int);
int func_8004E4E4(int arg0) {
    int delta = *(int*)(&D_80070328 + 0xF8) - arg0;
    int value;
    if (delta < 0) value = 0x1040 - (func_8004F388(-delta) << 7);
    else value = 0x1040 + (func_8004F388(delta) << 6);
    if (D_8006C5BC == 0x2D) value += 0xAAA;
    if (value > 0x5900) value = 0x5900;
    if (value < 0x800) value = 0x800;
    return value;
}

/* Retail Rev 0: 0x8004E56C..0x8004E664; signed halfword basis
 * components, 12-bit angles, evaluated once per call. */
void func_8004E56C(int* out, void* source) {
    register short* basis __asm__("$16") = (short*)source;
    short horizontalA = basis[4];
    short horizontalB = basis[3];
    int magnitude = func_8004F388(horizontalA * horizontalA + horizontalB * horizontalB);
    int cosine;
    out[1] = -func_8004E880(magnitude, basis[5], 1);
    cosine = func_8004EA2C(out[1]);
    if (cosine < 0) cosine = -cosine;
    if (cosine < 16) {
        int sine;
        out[0] = 0;
        sine = func_8004E9E4(out[1]);
        if (sine < 0) {
            out[2] = func_8004E880(-basis[7], basis[1], 1) & 0xFFF;
        } else {
            out[2] = func_8004E880(basis[7], -basis[1], 1) & 0xFFF;
        }
    } else {
        out[2] = func_8004E880(basis[8], -basis[2], 1);
        out[0] = func_8004E880(basis[4], basis[3], 1);
    }
}
