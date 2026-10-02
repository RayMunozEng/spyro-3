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
void func_80049ACC();
void func_8003F194(void);

///////////////////////////////////////////////////////////////////////////////

/* Retail source: asm/nonmatchings/spyroupdate/func_8003E83C.s,
 * 0x8003E83C..0x8003E968; call sequence executes once on call. */
extern char g_CheatFlags;
void func_80044240(void);
void func_800458F8(void);
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

/* Retail source: USA Rev 0 SCUS-94467 PSX.EXE,
 * asm/nonmatchings/spyroupdate/func_8003E968.s, 0x8003E968..0x8003F194.
 * Executes once per invocation from func_8003E83C. Raw field offsets,
 * table strides, signed shifts, and call order retain the instruction units.
 * Confidence: exact linked bytes; falsification gate is the complete EXE hash
 * e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f.
 */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((signed char *)(expr) + (offset)))
void func_80049D70(int);                         /* extern */
void func_80055D24(void *, int);             /* extern */
void func_8005F21C(signed char *, signed char *);                  /* extern */
extern int D_800676E8[];
extern int D_8006E044;
extern int D_8006E048;
extern int D_8006E160;
extern int D_8006E174;
extern int D_8006E178;
extern int D_8006E17C;
extern int D_8006E1B8;
extern int D_8006E53C;

extern int D_8006C648, D_8006C5C8, D_8006C5BC, D_8006E344;
extern void *spyroField250 asm("D_80070328+0x250");
void func_8003E968(void) {
    struct { Vector3D value; int reserved[4]; } scratch;
    signed char *temp_a0;
    signed char *var_a0_2;
    int var_s0;
    int var_s0_2;
    signed char *temp_s0;
    signed char *temp_s0_2;
    signed char *temp_s0_3;
    signed char *temp_s0_4;
    register signed char *temp_s0_5 asm("$16");
    signed char *temp_s1;
    unsigned int var_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_s0_6;
    void *temp_s0_7;
    register void *temp_s1_2 asm("$17");
    void *temp_v1;
    void *temp_v1_2;

    var_s0 = 0;
    if (D_8006C648 > 0) {
        do {
            func_80049D70(var_s0);
            var_s0 += 1;
        } while (var_s0 < D_8006C648);
    }
    var_s0_2 = 0;
    func_8003F6F4();
    func_8004B324();
    PlaySpyroSounds();
    if (D_8006C648 > 0) {
        do {
            func_8004BDF0(var_s0_2);
            var_s0_2 += 1;
        } while (var_s0_2 < D_8006C648);
    }
    temp_s0 = &D_80070328 + 0xC;
    temp_s1 = temp_s0 + 0x24;
    M2C_FIELD(&D_80070328, unsigned char *, 0xC) = (unsigned char) ((int) M2C_FIELD(&D_80070328, int *, 0x5C) >> 4);
    M2C_FIELD(&D_80070328, unsigned char *, 0xD) = (unsigned char) ((int) M2C_FIELD(&D_80070328, int *, 0x60) >> 4);
    M2C_FIELD(&D_80070328, unsigned char *, 0xE) = (unsigned char) ((int) M2C_FIELD(&D_80070328, int *, 0x64) >> 4);
    func_8004EA90((Angle *) temp_s0, (SHORTMATRIX *) temp_s1, 0);
    temp_s0_2 = temp_s0 + 0x194;
    func_8004EA90((Angle *) (temp_s0 + 4), (SHORTMATRIX *) temp_s0_2, 0);
    func_8005F35C(temp_s1, temp_s0_2, temp_s0_2);
    if (M2C_FIELD(&g_CheatFlags, unsigned char *, 6) != 0) {
        func_8005F21C(temp_s0_2, &g_CheatFlags + 6 + 2);
    }
    if ((M2C_FIELD(&D_80070328, int *, 8) < 0x400) || ((M2C_FIELD(&D_80070328, int *, 0x50) == 3) && (M2C_FIELD(&D_80070328, int *, 0x4C) == 0x7F) && (M2C_FIELD(&D_80070328, int *, 0x54) >= 0x5A))) {
        func_800498C0();
    } else if ((({ register int rowOffset asm("$2"); register int slotOffset asm("$3"); register signed char *tableBase asm("$4"); rowOffset = D_8006C58C; tableBase = (signed char *)D_800676E8; slotOffset = D_8006C5C8;  rowOffset <<= 4; rowOffset += (int)tableBase; slotOffset <<= 2; slotOffset += rowOffset; __asm__ ("" : "=r"(slotOffset) : "0"(slotOffset)); M2C_FIELD(&D_80070328, int *, 8) < *(int *)slotOffset; })) && ((unsigned int) (M2C_FIELD(&D_80070328, int *, 0x50) - 0xB) >= 2U) && ((unsigned int) (M2C_FIELD(&D_80070328, int *, 0x50) - 7) >= 2U)) {
        if (M2C_FIELD(&D_80070328, int *, 0x50) != 3) {
            if (M2C_FIELD(&D_80070328, int *, 0x244) != 0) {
                if (M2C_FIELD(&D_80070328, int *, 0x24C) != 3) {
                    goto skip_reaction;
                }
                var_a0 = 0x67;
            } else {
                var_a0 = 7;
            }
            func_8004BEF8(var_a0);
        }
skip_reaction:
        {
            register int *movementBase asm("$6");
            register signed char *cameraBase asm("$5");
            movementBase = (int *)(&D_80070328 + 0x4C);

            if (*movementBase != 0x7F) {
                cameraBase = (signed char *)&D_8006E044;

                *movementBase = 0x7F;
                M2C_FIELD(&D_80070328, int *, 0x54) = 0;
                if (*(int *)cameraBase != 9) {
                    func_8004F178(cameraBase + 0x16C, cameraBase - 0x24);
                } else {
                    func_8004F178(cameraBase + 0x16C, (signed char *)movementBase - 0x4C);
                    D_8006E1B8 += 0x800;
                }
                D_8006E160 = 9;
                func_80016764(9);
                D_8006E048 = 2;
            }
        }
        func_8004F178(((signed char *)&D_8006E17C), &D_80070328);
        func_800136F0(((signed char *)&D_8006E17C) - 0x14, ((signed char *)&D_8006E17C) + 0x34, (Vector3D *) &D_80070328);
        D_8006E174 = 0;
        D_8006E178 = 0;
    } else if ((M2C_FIELD(&D_80070328, int *, 0) < 0x800) || (M2C_FIELD(&D_80070328, int *, 4) < 0x800)) {
        if (M2C_FIELD(&D_80070328, int *, 0x48) == 7) {
            M2C_FIELD(&D_80070328, int *, 0x98) = 0;
            M2C_FIELD(&D_80070328, int *, 0x9C) = 0;
            M2C_FIELD(&D_80070328, int *, 0x8C) = 0;
            M2C_FIELD(&D_80070328, int *, 0x90) = 0;
        } else {
            func_8004F168(&D_80070328 + 0x98);
            func_8004F168(&D_80070328 + 0x8C);
            func_8004BEF8(7U);
        }
        {
            register signed char *cameraRoot asm("$17");
            register int movementState asm("$2");
            register signed char *movementPtr asm("$16");
            movementPtr = &D_80070328 + 0x4C;

            movementState = 0x7F;

            cameraRoot = (signed char *)&D_8006E044;
            __asm__("" : "=r"(cameraRoot) : "0"(cameraRoot));
            *(int *)movementPtr = movementState;
            if (*(int *)cameraRoot != 9) {
                D_8006E160 = 9;
                func_80016764(9);
                D_8006E048 = 2;
            }
            temp_s0_3 = movementPtr - 0x4C;
            func_8004F178(cameraRoot + 0x138, temp_s0_3);
            func_800136F0((CameraPosition *)(cameraRoot + 0x124), (Vector3D *)(cameraRoot - 0x24), (Vector3D *)temp_s0_3);
        }
    }
    if ((M2C_FIELD(&D_80070328, int *, 0x244) != 0) || ((unsigned int) (M2C_FIELD(&D_80070328, int *, 0x50) - 0x12) < 2U) || (((D_8006C5BC == 0x2F) || ((D_8006C5BC == 0x32) && (D_8006C5C8 == 3) && (D_8006E344 != 0xD))) && (M2C_FIELD(&D_80070328, int *, 0x50) == 6)) || (M2C_FIELD(&D_80070328, int *, 0x48) == 0x26)) {
        temp_s0_4 = &D_80070328 + 0x30;
        scratch.value.x = 0;
        scratch.value.y = 0;
        scratch.value.z = (int) -M2C_FIELD(spyroField250, short *, 0x38);
        func_8004ED6C((SHORTMATRIX *) temp_s0_4, (Vector3D *) &scratch.value.x, (Vector3D *) &scratch.value.x);
        func_8004F194(spyroField250 + 0xC, (Vector3D *) (temp_s0_4 - 0x30), (Vector3D *) &scratch.value.x);
        M2C_FIELD(spyroField250, signed char *, 0x44) = (signed char) ((int) M2C_FIELD(&D_80070328, int *, 0x5C) >> 4);
        if ((D_8006C5BC == 0xE) && (D_8006C5C8 == 2) && (M2C_FIELD(&D_80070328, int *, 0x50) == 0x12)) {
            unk_ovlheader_8007441C();
        }
        if (M2C_FIELD(&D_80070328, int *, 0x48) != 0xB0) {
            M2C_FIELD(spyroField250, signed char *, 0x45) = (signed char) ((int) M2C_FIELD(&D_80070328, int *, 0x60) >> 4);
        }
        M2C_FIELD(spyroField250, signed char *, 0x46) = (signed char) ((int) M2C_FIELD(&D_80070328, int *, 0x64) >> 4);
        func_80055D24(spyroField250, 6);
        if (M2C_FIELD(&D_80070328, int *, 0x24C) == 3) {
            temp_s1_2 = M2C_FIELD(spyroField250, void **, 0);
            temp_v1 = M2C_FIELD(temp_s1_2, void **, 0x30);
            if (temp_v1 != 0) {
                if (M2C_FIELD(spyroField250, unsigned char *, 0x4C) == 0) {
                    M2C_FIELD(temp_v1, signed char *, 0x4C) = 0;
                    M2C_FIELD(M2C_FIELD(temp_s1_2, void **, 0x30), signed char *, 0x4D) = 0;
                } else {
                    M2C_FIELD(temp_v1, signed char *, 0x4C) = 0x10;
                }
                temp_s0_5 = &D_80070328 + 0x44;
                __asm__("" : "=r"(temp_s0_5) : "0"(temp_s0_5));
                scratch.value.x = -0xC0;
                scratch.value.y = 0;
                scratch.value.z = -M2C_FIELD(temp_s0_5, int *, 0) - M2C_FIELD(M2C_FIELD(temp_s1_2, void **, 0x30), short *, 0x38);
                func_8004ED6C((SHORTMATRIX *) (temp_s0_5 - 0x14), (Vector3D *) &scratch.value.x, (Vector3D *) &scratch.value.x);
                func_8004F194(M2C_FIELD(temp_s1_2, void **, 0x30) + 0xC, (Vector3D *) (temp_s0_5 - 0x44), (Vector3D *) &scratch.value.x);
                if (!(D_8006E53C & 0x80) || (M2C_FIELD(&D_80070328, int *, 0x50) == 0)) {
                    if (((unsigned int) (M2C_FIELD(&D_80070328, int *, 0x50) - 7) < 2U) || (M2C_FIELD(&D_80070328, int *, 0x210) & 0x40)) {
                        M2C_FIELD(temp_s1_2, int *, 0x38) = 1;
                        M2C_FIELD(temp_s1_2, int *, 0x34) = 0;
                        return;
                    }
                    M2C_FIELD(temp_s1_2, int *, 0x38) = 0;
                    return;
                }
                goto block_60;
            }
block_60:
            M2C_FIELD(temp_s1_2, int *, 0x38) = 1;
            return;
        }
        if (M2C_FIELD(&D_80070328, int *, 0x24C) == 4) {
            temp_s0_6 = M2C_FIELD(spyroField250, void **, 0);
            temp_v1_2 = M2C_FIELD(temp_s0_6, void **, 0x78);
            if (temp_v1_2 != 0) {
                if (M2C_FIELD(spyroField250, unsigned char *, 0x4C) == 0) {
                    M2C_FIELD(temp_v1_2, signed char *, 0x4C) = 0;
                    M2C_FIELD(M2C_FIELD(temp_s0_6, void **, 0x78), signed char *, 0x4D) = 0;
                    return;
                }
                M2C_FIELD(temp_v1_2, signed char *, 0x4C) = 0x10;
                ((void (*)(void *, void *, int))unk_ovlheader_800743A8)(M2C_FIELD(temp_s0_6, void **, 0x78), spyroField250, 1);
                if (M2C_FIELD(&D_80070328, int *, 0x48) == 0x81) {
                    M2C_FIELD(M2C_FIELD(temp_s0_6, void **, 0x78), int *, 0x54) = (int) ((M2C_FIELD(&D_80070328, int *, 0xF4) & 0xFFFFFF) | 0x80000000);
                    return;
                }
                M2C_FIELD(M2C_FIELD(temp_s0_6, void **, 0x78), int *, 0x54) = 0;
            }
        } else if ((M2C_FIELD(&D_80070328, int *, 0x24C) == 9) && (M2C_FIELD(&D_80070328, int *, 0x48) != 0xAC)) {
            temp_s0_7 = M2C_FIELD(spyroField250, void **, 0);
            temp_a0_2 = M2C_FIELD(temp_s0_7, void **, 0x28);
            if (temp_a0_2 != 0) {
                func_8004F178(temp_a0_2 + 0xC, (&D_80070328 + 0x48) - 0x48);
                temp_a0_3 = M2C_FIELD(temp_s0_7, void **, 0x28);
                M2C_FIELD(temp_a0_3, int *, 0x14) = (int) (M2C_FIELD(temp_a0_3, int *, 0x14) - M2C_FIELD(&D_80070328, int *, 0x44));
                M2C_FIELD(M2C_FIELD(temp_s0_7, void **, 0x28), unsigned char *, 0x44) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0xC);
                M2C_FIELD(M2C_FIELD(temp_s0_7, void **, 0x28), unsigned char *, 0x45) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0xD);
                M2C_FIELD(M2C_FIELD(temp_s0_7, void **, 0x28), unsigned char *, 0x46) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0xE);
            }
        }
    }
}

#undef M2C_FIELD


// Apply surface effects
// There's a bunch of surface functions here
#define M2C_FIELD_3F194(p, t, o) (*(t *)((char *)(p) + (o)))
extern int D_8006C5BC, D_8006C6C0, D_8006C710, D_8006C74C;
extern int D_8006FA38, D_80071908, D_80071924;
extern Vector3D D_8006E020;
extern char* D_8006EE2C;
int func_8003FD58(int, int);
int func_8001A310(Vector3D*, int, int, Moby*);
int func_8001A358(Vector3D*, int);
int func_80040954(int);
void func_8004BEF8(unsigned int);

/* Retail source: USA Rev 0 PSX.EXE 0x8003F194..0x8003F6F4
 * (344 words; raw text SHA-256
 * 408e7a1a28f2005620dae59405028a90bcb317532586b5f0a5b32d5791c8c2a7).
 * Called once per player update by func_8003E83C. Player and collision heights
 * are raw signed world integers; probes use 0x400, 0xC00, and 0x1000 height
 * ranges, the player height at +0x44 is halved arithmetically, and state,
 * animation, and retry fields are integer selectors/counters. Confidence:
 * exact; falsifiable by 488 instruction/relocation records and the complete
 * executable and overlay SHA-256 checks. */
void func_8003F194(void) {
    int var_v1;
    register signed char *temp_a3 asm ("$7");
    register unsigned int var_a0 asm ("$4");

    var_v1 = 0;
    if (M2C_FIELD_3F194(&D_80070328, int, 0xB8) == 0) {
        var_v1 = func_8003FD58(M2C_FIELD_3F194(&D_80070328, int, 0x10C), 1);
    }
    if ((var_v1 == 0) && (func_8003FD58(M2C_FIELD_3F194(&D_80070328, int, 0x108), 0) == 0) && (func_8003FD58(M2C_FIELD_3F194(&D_80070328, int, 0x110), 2), (M2C_FIELD_3F194(&D_80070328, int, 0xF4) != 0)) && (M2C_FIELD_3F194(&D_80070328, int, 0x280) >= 0) && (M2C_FIELD_3F194(&D_80070328, int, 0x50) != 0x12) && (M2C_FIELD_3F194(&D_80070328, int, 0x24C) != 8) && (M2C_FIELD_3F194(&D_80070328, int, 0x24C) != 0xA)) {
        if (D_8006C5BC != 0x20) goto regular_surface;
        if (M2C_FIELD_3F194(&D_80070328, int, 0x1CC) != 0) goto regular_surface;
        if (M2C_FIELD_3F194(&D_80070328, int, 0x50) == 8) goto regular_surface;
        if (((M2C_FIELD_3F194(&D_80070328, int, 0x50) == 2) || (M2C_FIELD_3F194(&D_80070328, int, 0x50) == 7)) &&
            (M2C_FIELD_3F194(&D_80070328, int, 0xA0) > 0)) return;
        M2C_FIELD_3F194(&D_80070328, int, 0x284) = 0x5A;
        D_8006C6C0 += 1;
        D_8006C710 += 1;
        if ((M2C_FIELD_3F194(&D_80070328, int, 0x240) != 0) || (D_8006C74C != 0)) {
            if (M2C_FIELD_3F194(&D_80070328, int, 0x280) < 0) M2C_FIELD_3F194(&D_80070328, int, 0x280) = 0;
            goto check_death_counter;
        }
        if (M2C_FIELD_3F194(&D_80070328, int, 0x280) >= 0) M2C_FIELD_3F194(&D_80070328, int, 0x280) -= 1;
check_death_counter:
        if (M2C_FIELD_3F194(&D_80070328, int, 0x280) >= 0) goto death_surface_28;
death_surface_30:
        func_8004BEF8(0x1E);
        return;
death_surface_28:
        func_8004BEF8(0x1C);
        return;
regular_surface:
        if (D_8006FA38 < 0) goto negative_spawn;
        if (M2C_FIELD_3F194(&D_80070328, int, 0x50) == 8) goto block_60;
        var_a0 = 0x37;
        goto apply_surface;
negative_spawn:
        temp_a3 = &D_80070328 + 0x48;
        __asm__ volatile ("" : "=r"(temp_a3) : "0"(temp_a3));
        { register int animation asm ("$5") = *(volatile int *)temp_a3;
        if (animation >= 0x96) goto block_60;
        if ((M2C_FIELD_3F194(&D_80070328, int, 0x50) == 0xB) || (animation == 0x39)) {
            if (M2C_FIELD_3F194(&D_80070328, int, 0x8) < M2C_FIELD_3F194(&D_80070328, int, 0xF4)) goto block_60;
            var_a0 = 0x2C;
            if (animation != 0x28) goto apply_surface;
            if (M2C_FIELD_3F194(&D_80070328, int, 0x4C) == 1) goto block_60;
            goto apply_surface;
        }
        if (M2C_FIELD_3F194(&D_80070328, int, 0x50) == 0xC) {
            if (M2C_FIELD_3F194(&D_80070328, int, 0x8) < M2C_FIELD_3F194(&D_80070328, int, 0xF4)) goto block_60;
            if (M2C_FIELD_3F194(&D_80070328, int, 0x4C) == 1) goto block_60;
            var_a0 = 0x16;
            goto apply_surface;
        }
        if (M2C_FIELD_3F194(&D_80070328, int, 0xA0) > 0) goto block_60;
        if (M2C_FIELD_3F194(&D_80070328, int, 0x50) == 0xA) goto block_60;
        if ((M2C_FIELD_3F194(&D_80070328, int, 0xF4) + (M2C_FIELD_3F194(&D_80070328, int, 0x44) >> 1)) < M2C_FIELD_3F194(&D_80070328, int, 0x8)) goto block_60;
        if (M2C_FIELD_3F194(&D_80070328, int, 0x24C) == 1) {
            var_a0 = 0x4F;
            goto apply_surface;
        }
        if (M2C_FIELD_3F194(&D_80070328, int, 0x24C) == 4) {
            if (animation == 0x81) goto block_60;
            var_a0 = 0x81;
            if (M2C_FIELD_3F194(&D_80070328, int, 0x1CC) != 0) goto apply_surface;
            if (M2C_FIELD_3F194(&D_80070328, int, 0x50) == 8) goto apply_surface;
            { register int ninety asm ("$3") = 0x5A;
              register int counter asm ("$2") = D_8006C6C0;
              M2C_FIELD_3F194(temp_a3, int, 0x23C) = ninety;
              D_8006C6C0 = counter + 1; }
            D_8006C710 += 1;
            if ((M2C_FIELD_3F194(&D_80070328, int, 0x240) != 0) || (D_8006C74C != 0)) {
                if (M2C_FIELD_3F194(&D_80070328, int, 0x280) < 0) M2C_FIELD_3F194(&D_80070328, int, 0x280) = 0;
            } else if (M2C_FIELD_3F194(&D_80070328, int, 0x280) >= 0) {
                M2C_FIELD_3F194(&D_80070328, int, 0x280) -= 1;
            }
            var_a0 = 0x81;
            goto apply_surface;
        }
        if (animation == 0x16) goto run_collision_probe;
        var_a0 = 0x2C;
        if (animation != 0x2E) goto apply_surface;
run_collision_probe:
        {
            register void *probeArg0 asm ("$4") = temp_a3 - 0x48;
            register int probeArg1 asm ("$5") = 0x400;
            register int probeArg2 asm ("$6") = 1;
            register int probeArg3 asm ("$7");
            int collisionResult;
            __asm__ volatile ("" : "=r"(probeArg0), "=r"(probeArg1), "=r"(probeArg2) : "0"(probeArg0), "1"(probeArg1), "2"(probeArg2));
            probeArg3 = 0;
            collisionResult = func_8001A310(probeArg0, probeArg1, probeArg2, (Moby *)probeArg3);
            __asm__ volatile ("" : "=r"(collisionResult) : "0"(collisionResult));
            var_a0 = 0x2C;
            if (collisionResult == 0) {
                var_a0 = 0x2A;
                if (M2C_FIELD_3F194(D_8006EE2C, int, 0xDC) == 0) var_a0 = 0x2C;
            }
            goto apply_surface;
        }
        }
apply_surface:
        func_8004BEF8(var_a0);
        goto block_60;
    }
block_60:
        {
            register int *firstFloor asm ("$16") = (int *)(&D_80070328 + 0x2C);
            *firstFloor = 0;
            if ((func_8001A358((Vector3D *)(firstFloor - 11), 0xC00) != 0) &&
                (func_80040954(D_80071924) == 4) &&
                ((M2C_FIELD_3F194(&D_80070328, int, 0x8) - M2C_FIELD_3F194(&D_80070328, int, 0x44)) >= D_80071908)) {
                *firstFloor = M2C_FIELD_3F194(&D_80070328, int, 0x8) - D_80071908;
            }
        }
        {
            register int *secondFloor asm ("$17") = (int *)(&D_80070328 + 0x2C);
            if (*secondFloor == 0 && func_8001A358((Vector3D *)&D_8006E020, 0x1000) != 0) {
                register int *floorHeight asm ("$16") = &D_80071908;
                if (((M2C_FIELD_3F194(&D_80070328, int, 0x8) - M2C_FIELD_3F194(&D_80070328, int, 0x44)) >= *floorHeight) &&
                    (func_80040954(D_80071924) == 4)) {
                    *secondFloor = M2C_FIELD_3F194(&D_80070328, int, 0x8) - *floorHeight;
                }
            }
        }
}
#undef M2C_FIELD_3F194

/* Retail source: USA Rev 0 PSX.EXE 0x8003F6F4..0x8003FD58
 * (409 instructions; raw bytes from SCUS-94467 Rev 0).
 * Flags at player state +0x254 select the constraint path. Vector products
 * use Q12 fixed point, angles wrap to 12 bits, and the update runs once per
 * call. Confidence: confirmed retail exact against the identified executable.
 * Falsifiable vectors: flag bits 1/2/4/8 independently and combined; signed
 * vector components around zero; bounds at 0x264/0x274/0x278; distances
 * 0x1FFF/0x2000/0x2001; final components 0x3FF/0x400. */
extern short D_80065920[];
extern short D_800658A0[];

#define SPYRO_FIELD(expr, type_ptr, offset) (*(type_ptr)((signed char *)(expr) + (offset)))

void func_8003F6F4(void) {
    Vector3D sp10;
    Vector3D sp20;
    short *temp_a0;
    short *temp_a1;
    short *temp_v1;
    short *temp_v1_2;
    int temp_a3;
    int adjusted;
    int y_value;
    int y_threshold;
    int temp_s1;
    int temp_v1_3;
    int temp_v1_4;
    int temp_v1_5;
    int temp_v1_6;
    int var_a1;
    int var_s1;
    signed char *temp_a0_2;
    signed char *temp_a0_3;
    signed char *temp_s0;
    signed char *temp_s0_2;

    temp_s0 = &D_80070328 + 0x254;
    if (SPYRO_FIELD(&D_80070328, int *, 0x254) & 1) {
        func_8004F168(&sp20);
        func_8004F178(&sp10, temp_s0 - 0x1E0);
        func_8004F110(&sp10, 6);
        func_8004F194(&sp10, &sp10, (Vector3D *) (temp_s0 - 0x254));
        if (SPYRO_FIELD(&D_80070328, int *, 0x254) & 8) {
            func_8004F1C8(&sp10, temp_s0 + 0x14, &sp10);
            temp_a0 = &D_80065920[SPYRO_FIELD(&D_80070328, int *, 0x27C)];
            temp_v1 = &D_800658A0[SPYRO_FIELD(&D_80070328, int *, 0x27C)];
            temp_a3 = (int) ((sp10.x * *temp_a0) - (sp10.y * *temp_v1)) >> 0xC;
            sp20.x = temp_a3;
            sp20.y = (int) ((sp10.x * *temp_v1) + (sp10.y * *temp_a0)) >> 0xC;
            if (SPYRO_FIELD(&D_80070328, int *, 0x254) & 2) {
                if (SPYRO_FIELD(&D_80070328, int *, 0x274) < temp_a3) {
                    sp20.x = temp_a3 - SPYRO_FIELD(&D_80070328, int *, 0x274);
                } else if (temp_a3 < -SPYRO_FIELD(&D_80070328, int *, 0x274)) {
                    sp20.x = temp_a3 + SPYRO_FIELD(&D_80070328, int *, 0x274);
                } else {
                    sp20.x = 0;
                }
                y_value = sp20.y;
                y_threshold = SPYRO_FIELD(&D_80070328, int *, 0x278);
                if (y_threshold < y_value) {
                    sp20.y = y_value - y_threshold;
                } else if (y_value < -y_threshold) {
                    sp20.y = y_value + y_threshold;
                } else {
                    sp20.y = 0;
                }
            } else {
                if ((SPYRO_FIELD(&D_80070328, int *, 0x274) - 0x2000) < temp_a3) {
                    adjusted = temp_a3 - 0x2000;
                    __asm__ volatile("" : "=r"(adjusted) : "0"(adjusted));
                    sp20.x = adjusted - SPYRO_FIELD(&D_80070328, int *, 0x274);
                } else if (temp_a3 < (-SPYRO_FIELD(&D_80070328, int *, 0x274) + 0x2000)) {
                    adjusted = temp_a3 + 0x2000;
                    __asm__ volatile("" : "=r"(adjusted) : "0"(adjusted));
                    sp20.x = adjusted + SPYRO_FIELD(&D_80070328, int *, 0x274);
                } else {
                    sp20.x = 0;
                }
                if ((SPYRO_FIELD(&D_80070328, int *, 0x278) + 0x2000) < sp20.y) {
                    adjusted = sp20.y - 0x2000;
                    __asm__ volatile("" : "=r"(adjusted) : "0"(adjusted));
                    sp20.y = adjusted - SPYRO_FIELD(&D_80070328, int *, 0x278);
                } else if (sp20.y < (-SPYRO_FIELD(&D_80070328, int *, 0x278) - 0x2000)) {
                    adjusted = sp20.y + 0x2000;
                    __asm__ volatile("" : "=r"(adjusted) : "0"(adjusted));
                    sp20.y = adjusted + SPYRO_FIELD(&D_80070328, int *, 0x278);
                } else {
                    sp20.y = 0;
                }
                sp20.x = sp20.x >> 8;
                sp20.y = sp20.y >> 8;
            }
            temp_a1 = &D_80065920[SPYRO_FIELD(&D_80070328, int *, 0x27C)];
            temp_v1_2 = &D_800658A0[SPYRO_FIELD(&D_80070328, int *, 0x27C)];
            sp10.x = (int) ((sp20.x * *temp_a1) + (sp20.y * *temp_v1_2)) >> 0xC;
            sp10.y = (int) ((-sp20.x * *temp_v1_2) + (sp20.y * *temp_a1)) >> 0xC;
            sp10.z = 0;
            func_8004F0E8(&sp10, 6);
            goto block_37;
        }
        func_8004F1C8(&sp10, temp_s0 + 4, &sp10);
        if (SPYRO_FIELD(&D_80070328, int *, 0x254) & 4) {
            var_a1 = func_8004EDE8(&sp10, 1);
        } else {
            var_a1 = func_8004EDE8(&sp10, 0);
            sp10.z = 0;
        }
        if (SPYRO_FIELD(&D_80070328, int *, 0x254) & 2) {
            if (var_a1 >= SPYRO_FIELD(&D_80070328, int *, 0x264)) {
                func_8004F110(&sp10, 6);
                func_8004EF04(&sp10, 0x1000);
                temp_s1 = (int) ((sp10.x * SPYRO_FIELD(&D_80070328, int *, 0x74)) + (sp10.y * SPYRO_FIELD(&D_80070328, int *, 0x78)) + (sp10.z * SPYRO_FIELD(&D_80070328, int *, 0x7C))) >> 0xC;
                if (temp_s1 < 0) {
                    if (SPYRO_FIELD(&D_80070328, int *, 0x254) & 4) {
                        temp_v1_3 = (func_8004E880(func_8004EDE8(&sp10, 0), sp10.z, 1) - SPYRO_FIELD(&D_80070328, int *, 0x60)) & 0xFFF;
                        sp20.y = temp_v1_3;
                        if (temp_v1_3 >= 0x801) {
                            sp20.y = temp_v1_3 - 0x1000;
                        }
                    }
                    temp_v1_4 = (func_8004E880(sp10.x, sp10.y, 1) - SPYRO_FIELD(&D_80070328, int *, 0x64)) & 0xFFF;
                    sp20.z = temp_v1_4;
                    if (temp_v1_4 >= 0x801) {
                        sp20.z = temp_v1_4 - 0x1000;
                    }
                    func_8004F110((Vector3D *) &sp20, 5);
                    SPYRO_FIELD(&D_80070328, int *, 0x60) = (int) (SPYRO_FIELD(&D_80070328, int *, 0x60) + sp20.y);
                    SPYRO_FIELD(&D_80070328, int *, 0x64) = (int) (SPYRO_FIELD(&D_80070328, int *, 0x64) + sp20.z);
                    func_8004F08C(&sp10, 0x1000, -temp_s1);
block_37:
                    temp_a0_2 = &D_80070328 + 0x74;
                    func_8004F194((Vector3D *) temp_a0_2, (Vector3D *) temp_a0_2, &sp10);
                }
            }
        } else if ((SPYRO_FIELD(&D_80070328, int *, 0x264) - 0x2000) < var_a1) {
            adjusted = var_a1 + 0x2000;
            __asm__ volatile("" : "=r"(adjusted) : "0"(adjusted));
            var_s1 = adjusted - SPYRO_FIELD(&D_80070328, int *, 0x264);
            func_8004F08C(&sp10, var_a1, var_s1);
            temp_a0_3 = (&D_80070328 + 0x254) - 0x1E0;
            func_8004F194((Vector3D *) temp_a0_3, (Vector3D *) temp_a0_3, &sp10);
            if (SPYRO_FIELD(&D_80070328, int *, 0x254) & 4) {
                temp_v1_5 = (func_8004E880(func_8004EDE8(&sp10, 0), sp10.z, 1) - SPYRO_FIELD(&D_80070328, int *, 0x60)) & 0xFFF;
                sp20.y = temp_v1_5;
                if (temp_v1_5 >= 0x801) {
                    sp20.y = temp_v1_5 - 0x1000;
                }
            }
            temp_v1_6 = (func_8004E880(sp10.x, sp10.y, 1) - SPYRO_FIELD(&D_80070328, int *, 0x64)) & 0xFFF;
            sp20.z = temp_v1_6;
            if (temp_v1_6 >= 0x801) {
                sp20.z = temp_v1_6 - 0x1000;
            }
            if (var_s1 >= 0x2001) {
                var_s1 = 0x2000;
            }
            func_8004F08C((Vector3D *) &sp20, 0x2000, var_s1);
            func_8004F110((Vector3D *) &sp20, 3);
            SPYRO_FIELD(&D_80070328, int *, 0x60) = (int) (SPYRO_FIELD(&D_80070328, int *, 0x60) + sp20.y);
            SPYRO_FIELD(&D_80070328, int *, 0x64) = (int) (SPYRO_FIELD(&D_80070328, int *, 0x64) + sp20.z);
        }
    }
    temp_s0_2 = &D_80070328 + 0x74;
    func_8004F178(&sp10, temp_s0_2);
    func_8004F110(&sp10, 6);
    func_8004F194(&sp10, &sp10, (Vector3D *) (temp_s0_2 - 0x74));
    {
        register int *tail asm("$16") = (int *) temp_s0_2;
        __asm__("" : "=r"(tail) : "0"(tail));
        if (sp10.x < 0x400) {
            tail[0] = tail[0] - (sp10.x << 6);
        }
        if (sp10.y < 0x400) {
            tail[1] = tail[1] - (sp10.y << 6);
        }
    }
}

#undef SPYRO_FIELD

// Run surface type function
/* Retail source: USA Rev 0 SCUS-94467, PSX.EXE 0x8003FD58..0x800408B8.
 * Surface IDs use the low six bits; descriptor types and per-level flags are
 * unsigned bytes, and descriptor payloads and player counters are signed words.
 * Cadence: one surface response invocation; arg1 selects the retail contact phase.
 * Falsifiable vectors: surface ID 63, types 0/1/2/4/5/6/7/9/10/12,
 * contact phases 0/1/2, signed counter boundaries -1/0/1 and character IDs 1/3/4/9/10.
 * Confidence: complete retail executable and overlay hash match.
 * Empty register constraints emit no instructions; the mode alias preserves
 * independently issued retail reads of the same player state word. */
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
void func_80053F50(int);
extern unsigned char D_8006C7B4;
extern unsigned char D_80070300;
extern volatile int surfacePlayerMode asm("D_80070328+0x50");

int func_8003FD58(int arg0, int arg1) {
    register Moby *var_s0_2 asm("$16");
    register SpecialSurface *temp_v0 asm("$2");
    register int temp_a0 asm("$4");
    register int modeArg asm("$5");
    register SpecialSurface **surfaces asm("$3");
    register int index asm("$2");
    register int *surfaceData asm("$4");
    register int temp_v0_2 asm("$2");
    register int one asm("$16");
    register int life asm("$3");
    int temp_v0_3;
    int var_a0_2;
    int var_a1;
    int var_v0;
    register int var_v0_2 asm("$2");
    register signed char *temp_a1 asm("$5");
    register signed char *temp_a2 asm("$6");
    register signed char *temp_s1 asm("$17");
    register signed char *temp_s1_2 asm("$17");
    register signed char *var_s0 asm("$16");
    register signed char *var_s0_3 asm("$16");
    register unsigned int var_a0 asm("$4");
    unsigned int temp_v1;

    modeArg = arg1;
    __asm__("" : "=r"(modeArg) : "0"(modeArg));
    temp_a0 = arg0 & 0x3F;
    if (temp_a0 != 0x3F) {
        surfaces = D_8006D048.m_SurfaceData;
        __asm__("" : "=r"(surfaces) : "0"(surfaces), "r"(temp_a0));
        index = temp_a0 << 2;
        index += (int)surfaces;
        __asm__("" : "=r"(index) : "0"(index));
        temp_v0 = *(SpecialSurface **)index;
        temp_v1 = *(unsigned char *)temp_v0;
        __asm__("" : "=r"(temp_v1) : "0"(temp_v1));
        surfaceData = (int *)((char *)temp_v0 + 4);
        __asm__("" : "=r"(surfaceData) : "0"(surfaceData), "r"(temp_v1));
        switch (temp_v1) {
        default: goto block_140;                          /* switch 1 */
        case 0:                                     /* switch 1 */
            if (modeArg == 1) {
                temp_a2 = ((char *)&D_80070328 + 0xA0);
                __asm__("" : "=r"(temp_a2) : "0"(temp_a2));
                if (*(int *)temp_a2 <= 0) {
                    if (M2C_FIELD(&D_80070328, int *, 0x1CC) == 0) {
                        if ((unsigned int) (M2C_FIELD(&D_80070328, int *, 0x24C) - 9) >= 2U) {
                            if (surfacePlayerMode != 8) {
                                if (M2C_FIELD(&D_80070328, int *, 0x24C) == 4) {
                                    if (M2C_FIELD(&D_80070328, int *, 0x48) != 0x81) {
                                        { register int timer asm("$3") = 0x5A;
                                        temp_v0_2 = D_8006C6C0;
                                        __asm__("" : : "r"(timer), "r"(temp_v0_2));
                                        M2C_FIELD(temp_a2, int *, 0x1E4) = timer;
                                        D_8006C6C0 = temp_v0_2 + 1; }
                                        D_8006C710 += 1;
                                        if ((M2C_FIELD(&D_80070328, int *, 0x240) != 0) || (D_8006C74C != 0)) {
                                            var_a0 = 0x81;
                                            if (M2C_FIELD(temp_a2, int *, 0x1E0) < 0) {
                                                M2C_FIELD(temp_a2, int *, 0x1E0) = 0;
                                            }
                                        } else {
                                            temp_v0_2 = M2C_FIELD(temp_a2, int *, 0x1E0);
                                            if (temp_v0_2 >= 0) {
                                                M2C_FIELD(temp_a2, int *, 0x1E0) = (int) (temp_v0_2 - 1);
                                            }
                                            var_a0 = 0x81;
                                        }
                                        func_8004BEF8(var_a0); return 1;
                                    }
                                } else if (M2C_FIELD(&D_80070328, int *, 0x24C) == 3) {
                                    M2C_FIELD(&D_80070328, int *, 0x284) = 0x5A;
                                    D_8006C6C0 += 1;
                                    D_8006C710 += 1;
                                    if ((M2C_FIELD(&D_80070328, int *, 0x240) != 0) || (D_8006C74C != 0)) {
                                        if (M2C_FIELD(&D_80070328, int *, 0x280) < 0) {
                                            M2C_FIELD(&D_80070328, int *, 0x280) = 0;
                                            goto block_24;
                                        }
                                        goto block_26;
                                    }
                                    if (M2C_FIELD(&D_80070328, int *, 0x280) >= 0) {
                                        M2C_FIELD(&D_80070328, int *, 0x280) = (int) (M2C_FIELD(&D_80070328, int *, 0x280) - 1);
block_24:
                                        if (M2C_FIELD(&D_80070328, int *, 0x280) >= 0) goto block_26;
block_25:
                                        var_a0 = 0x6C;
                                        func_8004BEF8(var_a0); return 1;
block_26:
                                        if (surfacePlayerMode == 8) goto block_139;
                                        var_a0 = 0x6B;
                                        func_8004BEF8(var_a0); return 1;
                                    } else {
                                        goto block_25;
                                    }
                                } else if (M2C_FIELD(&D_80070328, int *, 0x48) != 0x1E) {
                                    M2C_FIELD(&D_80070328, int *, 0x284) = 0x5A;
                                    D_8006C6C0 += 1;
                                    D_8006C710 += 1;
                                    if (D_8006FA38 < 0) {
                                        temp_v0_2 = *(int *)surfaceData;
                                        __asm__("" : "=r"(temp_v0_2) : "0"(temp_v0_2));
                                        if (temp_v0_2 != 0) {
                                            var_v0_2 = -1;
                                        } else {
                                            temp_v0_2 = M2C_FIELD(&D_80070328, int *, 0x280);
                                            __asm__("" : "=r"(temp_v0_2) : "0"(temp_v0_2));
                                            if (temp_v0_2 < 0) goto surface_life_done;
                                            var_v0_2 = temp_v0_2 - 1;
                                        }
                                        M2C_FIELD(&D_80070328, int *, 0x280) = var_v0_2;
                                    }
surface_life_done:
                                    var_a0 = 0x1E;
                                    func_8004BEF8(var_a0); return 1;
                                }
                                goto block_139;
                            }
                            goto block_140;
                        }
                    }
                }
            }
            return 0;
        case 2:                                     /* switch 1 */
            if (D_8006FA38 >= 0) {
                if (M2C_FIELD(&D_80070328, int *, 0x50) == 6) {
                    var_a0 = 0x3D;
                    func_8004BEF8(var_a0); return 1;
                }
                return 0;
            }
            if ((D_8006C5BC != 0xD) || (D_8006C7B4 & 4) || (*(&D_80070300 + D_8006C58C) & 4)) {
                if (modeArg == 1) {
                    M2C_FIELD(&D_80070328, int *, 0x1C4) = modeArg;
                    return 0;
                }
                return 0;
            }
            goto block_140;
        case 4:                                     /* switch 1 */
            if (modeArg == 1) {
                if (M2C_FIELD(&D_80070328, int *, 0x50) != 0x10) {
                    if ((unsigned int) (M2C_FIELD(&D_80070328, int *, 0x50) - 7) >= 2U) {
                        var_a0 = 0xA;
                        if (M2C_FIELD(&D_80070328, int *, 0x48) != 0xE) {
                            func_8004BEF8(var_a0); return 1;
                        }
                        goto block_140;
                    }
                    return 0;
                }
                goto block_140;
            }
            return 0;
        case 5:                                     /* switch 1 */
            if (modeArg == 2) {
                temp_v0_2 = 0xE;
                temp_s1 = ((char *)&D_80070328 + 0x48);
                __asm__("" : "=r"(temp_s1) : "0"(temp_s1));
                var_s0 = temp_s1 + 0x90;
                if (*(int *)temp_s1 != temp_v0_2) {
                    func_8004BEF8(0xEU);
                    __asm__("" : "=r"(temp_s1) : "0"(temp_s1));
                    var_s0 = temp_s1 + 0x90;
                }
                func_8004EF04((Vector3D *) var_s0, 0x800);
                func_8004F178(temp_s1 + 0x44, var_s0);
                func_8004F178(temp_s1 + 0x38, var_s0);
                var_s0_2 = SpawnMoby(0x2CC, 0);
                if (var_s0_2 != 0) {
                    func_8004F178(&var_s0_2->position, temp_s1 - 0x48);
                    var_a0_2 = M2C_FIELD(temp_s1, int *, 0x90);
                    var_a1 = M2C_FIELD(&D_80070328, int *, 0xDC);
                    goto block_57;
                }
                goto block_139;
            }
            if (modeArg == 0) {
                temp_s1_2 = ((char *)&D_80070328 + 0x48);
                __asm__("" : "=r"(temp_s1_2) : "0"(temp_s1_2));
                var_s0_3 = temp_s1_2 + 0xCC;
                if (*(int *)temp_s1_2 != 0xE) {
                    func_8004BEF8(0xEU);
                    __asm__("" : "=r"(temp_s1_2) : "0"(temp_s1_2));
                    var_s0_3 = temp_s1_2 + 0xCC;
                }
                func_8004EF04((Vector3D *) var_s0_3, 0x800);
                func_8004F178(temp_s1_2 + 0x44, var_s0_3);
                func_8004F178(temp_s1_2 + 0x38, var_s0_3);
                var_s0_2 = SpawnMoby(0x2CC, 0);
                if (var_s0_2 != 0) {
                    func_8004F178(&var_s0_2->position, temp_s1_2 - 0x48);
                    var_a0_2 = M2C_FIELD(temp_s1_2, int *, 0xCC);
                    var_a1 = M2C_FIELD(&D_80070328, int *, 0x118);
block_57:
                    var_s0_2->angle.yaw = func_8004E880(var_a0_2, var_a1, 0);
                }
                goto block_139;
            }
            return 0;
        case 6:                                     /* switch 1 */
            func_80053F50(*(int *)surfaceData);
            return 0;
        case 7:                                     /* switch 1 */
            if (modeArg == 1) {
                temp_a1 = ((char *)&D_80070328 + 0xA0);
                __asm__("" : "=r"(temp_a1) : "0"(temp_a1));
                if (*(int *)temp_a1 <= 0) {
                    if (M2C_FIELD(&D_80070328, int *, 0x1CC) == 0) {
                        if (surfacePlayerMode != 8) {
                            if (D_8006C5BC == 0x2A) {
                                if (*(int *)surfaceData != 0) {
                                    { register int timer asm("$3") = 0x5A;
                                        temp_v0_2 = D_8006C6C0;
                                        __asm__("" : : "r"(timer), "r"(temp_v0_2));
                                        M2C_FIELD(temp_a1, int *, 0x1E4) = timer;
                                        D_8006C6C0 = temp_v0_2 + 1; }
                                    D_8006C710 += 1;
                                    if ((M2C_FIELD(&D_80070328, int *, 0x240) != 0) || (D_8006C74C != 0)) {
                                        if (M2C_FIELD(temp_a1, int *, 0x1E0) < 0) {
                                            M2C_FIELD(temp_a1, int *, 0x1E0) = 0;
                                            goto block_69;
                                        }
                                        goto block_70;
                                    }
block_69:
                                    if (M2C_FIELD(&D_80070328, int *, 0x280) >= 0) {
block_70:
                                        M2C_FIELD(&D_80070328, int *, 0x280) = (int) (M2C_FIELD(&D_80070328, int *, 0x280) - 1);
                                    }
                                    temp_v0_2 = M2C_FIELD(&D_80070328, int *, 0x24C);
                                    one = 1;
                                    __asm__("" : "=r"(one) : "0"(one), "r"(temp_v0_2));
                                    if (temp_v0_2 == one) {
                                        temp_v0_2 = M2C_FIELD(&D_80070328, int *, 0x24);
                                        life = M2C_FIELD(&D_80070328, int *, 0x280);
                                        __asm__("" : "=r"(life) : "0"(life), "r"(temp_v0_2));
                                        M2C_FIELD(&D_80070328, int *, 0x24) = temp_v0_2 | 8;
                                        __asm__ volatile("" : : : "memory");
                                        __asm__("" : "=r"(life) : "0"(life));
                                        var_a0 = 0x48;
                                        if (life < 0) {
                                            var_a0 = 0x4A;
                                        }
                                        func_8004BEF8(var_a0); return 1;
                                    }
                                    var_a0 = 0x1C;
                                    if (M2C_FIELD(&D_80070328, int *, 0x280) < 0) {
                                        var_a0 = 0x3A;
                                        if (M2C_FIELD(D_8006EE2C, int *, 0x124) == 0) {
block_76:
                                            func_8004BEF8(0x1FU);
                                            __asm__ volatile("" : : : "memory");
                                            var_v0 = 1;
                                            if (D_8006FA38 >= 0) {
                                                M2C_FIELD(&D_80070328, int *, 0x4C) = one;
                                            }
                                            return var_v0;
                                        }
                                    }
                                    func_8004BEF8(var_a0); return 1;
                                }
                                goto block_140;
                            }
                            M2C_FIELD(&D_80070328, int *, 0x284) = 0x5A;
                            D_8006C6C0 += 1;
                            D_8006C710 += 1;
                            if ((M2C_FIELD(&D_80070328, int *, 0x240) != 0) || (D_8006C74C != 0)) {
                                if (M2C_FIELD(&D_80070328, int *, 0x280) < 0) {
                                    M2C_FIELD(&D_80070328, int *, 0x280) = 0;
                                    goto block_84;
                                }
                                goto mode_seven_nine;
                            }
                            if (M2C_FIELD(&D_80070328, int *, 0x280) >= 0) {
                                M2C_FIELD(&D_80070328, int *, 0x280) -= 1;
block_84:
                                if (M2C_FIELD(&D_80070328, int *, 0x280) >= 0) goto mode_seven_nine;
                            }
                            var_a0 = 0x1F;
                            if (M2C_FIELD(D_8006EE2C, int *, 0x124) != 0) var_a0 = 0x3A;
                            func_8004BEF8(var_a0); return 1;
mode_seven_nine:
                            func_8004BEF8(9); return 1;
                        }
                        goto block_140;
                    }
                }
            }
            return 0;
        case 1:                                     /* switch 1 */
            if (!(M2C_FIELD(&D_80070328, int *, 0x20C) & 0x40000) && (var_v0 = 0, (modeArg == 1)) && (var_v0 = 0, (M2C_FIELD(&D_80070328, int *, 0x1CC) == 0))) {
                {
                    life = M2C_FIELD(&D_80070328, int *, 0x50);
                    if (life == 8) return 0;
                    if ((life != 2) && (life != 7)) goto mode_one_body;
                    if (M2C_FIELD(&D_80070328, int *, 0xA0) > 0) return 0;
mode_one_body:
                        if (D_8006FA38 >= 0) {
                            temp_v0_2 = 8;
                            __asm__("" : "=r"(temp_v0_2) : "0"(temp_v0_2));
                            life = surfacePlayerMode;
                            __asm__("" : "=r"(life) : "0"(life));
                            if (life == temp_v0_2) goto block_139;
                            func_8004BEF8(0x3A); return 1;
                        }
                        __asm__ volatile("" : : : "$3", "memory");
                        M2C_FIELD(&D_80070328, int *, 0x284) = 0x5A;
                        D_8006C6C0 += 1;
                        D_8006C710 += 1;
                        if ((M2C_FIELD(&D_80070328, int *, 0x240) != 0) || (D_8006C74C != 0)) {
                            if (M2C_FIELD(&D_80070328, int *, 0x280) < 0) {
                                M2C_FIELD(&D_80070328, int *, 0x280) = 0;
                            }
                        } else if (((D_8006C5BC != 0x20) || (D_8006C5C8 != 2)) && (M2C_FIELD(&D_80070328, int *, 0x280) >= 0)) {
                            M2C_FIELD(&D_80070328, int *, 0x280) = (int) (M2C_FIELD(&D_80070328, int *, 0x280) - 1);
                        }
                        if (M2C_FIELD(&D_80070328, int *, 0x24C) == 3) {
                            var_a0 = 0x6B;
                            if (M2C_FIELD(&D_80070328, int *, 0x280) < 0) {
                                var_a0 = 0x6C;
                            }
                            func_8004BEF8(var_a0); return 1;
                        }
                        one = 1;
                        __asm__("" : "=r"(one) : "0"(one));
                        if (M2C_FIELD(&D_80070328, int *, 0x24C) == one) {
                            M2C_FIELD(&D_80070328, int *, 0x24) = (int) (M2C_FIELD(&D_80070328, int *, 0x24) | 8);
                            if (M2C_FIELD(&D_80070328, int *, 0x280) < 0) {
                                func_8004BEF8(0x4A); return 1;
                            }
                            func_8004BEF8(0x48); return 1;
                        }
                        var_a0 = 0x1C;
                        if (M2C_FIELD(&D_80070328, int *, 0x280) < 0) {
                            var_a0 = 0x3A;
                            if (M2C_FIELD(D_8006EE2C, int *, 0x124) != 0) {
                                func_8004BEF8(var_a0); return 1;
                            }
                            goto block_76;
                        }
                        func_8004BEF8(var_a0); return 1;
                }
            } else {
                return 0;
            }
            break;
        case 9:                                     /* switch 1 */
            if (M2C_FIELD(&D_80070328, int *, 0x48) == 0x3D) {
                M2C_FIELD(&D_80070328, int *, 0x4C) = 1;
                return 0;
            }
            if (M2C_FIELD(&D_80070328, int *, 0x48) == 0x24) {
                if (*(int *)surfaceData < 3) {
                    temp_v0_2 = 3;
                    __asm__("" : "=r"(temp_v0_2) : "0"(temp_v0_2));
                    M2C_FIELD(&D_80070328, int *, 0x4C) = temp_v0_2;
                    __asm__ volatile("" : : : "memory");
                    M2C_FIELD(&D_80070328, signed char *, 0x1B6) = 0;
                    temp_v0_2 = M2C_FIELD(&D_80070328, int *, 0x160);
                    life = *(int *)surfaceData;
                    __asm__("" : "=r"(life) : "0"(life), "r"(temp_v0_2));
                    temp_v0_2 += 1;
                    __asm__ volatile("" : "=r"(temp_v0_2) : "0"(temp_v0_2), "r"(life) : "memory");
                    M2C_FIELD(&D_80070328, int *, 0x15C) = life;
                    __asm__ volatile("" : : : "memory");
                    M2C_FIELD(&D_80070328, int *, 0x160) = temp_v0_2;
                    return 0;
                }
                goto block_140;
            }
            return 0;
        case 10:                                    /* switch 1 */
            if (modeArg == 1) {
                if ((M2C_FIELD(&D_80070328, int *, 0x50) != 0x13) && (M2C_FIELD(&D_80070328, int *, 0x50) != 0x11)) {
                    if ((unsigned int) (M2C_FIELD(&D_80070328, int *, 0x50) - 7) >= 2U) {
                        var_a0 = 0x31;
                        func_8004BEF8(var_a0); return 1;
                    }
                    return 0;
                }
                goto block_140;
            }
            return 0;
        case 12:                                    /* switch 1 */
            if (M2C_FIELD(&D_80070328, int *, 0x1CC) == 0) {
                if (M2C_FIELD(&D_80070328, int *, 0x50) == 0xD) {
                    if (*(int *)surfaceData != 0) {
                        M2C_FIELD(&D_80070328, int *, 0x284) = 0x5A;
                        D_8006C6C0 += 1;
                        D_8006C710 += 1;
                        if ((M2C_FIELD(&D_80070328, int *, 0x240) != 0) || (D_8006C74C != 0)) {
                            if (M2C_FIELD(&D_80070328, int *, 0x280) < 0) {
                                M2C_FIELD(&D_80070328, int *, 0x280) = 0;
                                goto block_132;
                            }
                            goto block_133;
                        }
block_132:
                        if (M2C_FIELD(&D_80070328, int *, 0x280) >= 0) {
block_133:
                            temp_v0_3 = M2C_FIELD(&D_80070328, int *, 0x280) - 1;
                            M2C_FIELD(&D_80070328, int *, 0x280) = temp_v0_3;
                            if (temp_v0_3 < 0) {
                                goto block_134;
                            }
                            goto mode_twelve_life;
                        }
block_134:
                        var_a0 = 0x3A;
                        if (M2C_FIELD(D_8006EE2C, int *, 0x124) == 0) {
                            func_8004BEF8(0x1FU);
                            if (D_8006FA38 >= 0) {
                                M2C_FIELD(&D_80070328, int *, 0x4C) = 1;
                                return 1;
                            }
                            goto block_139;
                        }
                        func_8004BEF8(var_a0); return 1;
                    }
                    goto block_140;
                }
            }
            return 0;
        }
mode_twelve_life:
        func_8004BEF8(0x1C);
block_139:
        return 1;
    } else {
block_140:
        return 0;
    }
}

#undef M2C_FIELD

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
typedef struct { int unk0, unk4; } SpyroInputPair;
typedef struct {
    int unk0, unk4, unk8;
    unsigned char unkC, unkD, unkE, unkF;
} SpyroInputSource;
extern SpyroInputSource* D_8006C570;
extern int D_8006C5BC;
extern short D_8006E040;
extern signed char D_8006E535;
extern unsigned char D_8006E536;

/* Retail evidence: USA Rev 0 PSX.EXE 0x80040D10..0x80040F48 (142 words).
 * Raw unsigned pad axes are centered at 0x7F; yaw is Q12 and speed is scaled
 * by arg0/128 once per call. Confidence: exact. Falsifiable by the full-image
 * hash and a word comparison over this address span. */
void func_80040D10(int arg0) {
    Vector3D sp10;
    int temp_a0;
    int temp_a1;
    int temp_v0;
    int temp_v0_2;
    int temp_v1;
    int temp_v1_2;
    int var_v0_3;
    int var_v1;

    if (D_8006E536 != 0) {
        sp10.x = D_8006C570->unkE;
        sp10.y = D_8006C570->unkF;
    } else {
        temp_v1 = D_8006C570->unk0;
        {
            register int selector __asm__("$2");
            selector = temp_v1 & 0x1000;
            if (selector) {
                sp10.y = 0;
            } else {
                selector = temp_v1 & 0x4000;
                if (!selector) {
                    selector = 0x7F;
                } else {
                    selector = 0xFF;
                }
                sp10.y = selector;
            }
        }
        temp_v1_2 = D_8006C570->unk0;
        {
            register int selector __asm__("$2");
            selector = temp_v1_2 & 0x2000;
            if (!selector) {
                selector = temp_v1_2 & 0x8000;
                if (selector) {
                    sp10.x = 0;
                    goto input_done;
                }
                selector = 0x7F;
            } else {
                selector = 0xFF;
            }
            sp10.x = selector;
        }
    }
input_done:
    if ((D_8006C5BC == 0x2A) &&
        (*(int*)(&D_80070328 + 0x24C) == 1)) {
        sp10.y = 0x7F;
        if (sp10.x == 0x7F) {
            D_8006E535 = 1;
            goto block_15;
        }
        goto block_19;
    }
block_15:
    if (sp10.x == 0x7F) {
        if (sp10.y == sp10.x) {
            *(int*)(&D_80070328 + 0xAC) = 0;
            *(int*)(&D_80070328 + 0xA4) = *(int*)(&D_80070328 + 0x64);
        } else {
            goto block_20;
        }
    } else {
block_19:
block_20:
        temp_a0 = 0x7F - sp10.y;
        temp_a1 = 0x7F - sp10.x;
        sp10.x = temp_a1;
        sp10.y = temp_a0;
        temp_v0 = func_8004E880(temp_a0, temp_a1, 1);
        *(int*)(&D_80070328 + 0xA4) = temp_v0;
        *(int*)(&D_80070328 + 0xA4) = (temp_v0 + D_8006E040) & 0xFFF;
        temp_v0_2 = (arg0 * func_8004EDE8(&sp10, 0)) >> 7;
        *(int*)(&D_80070328 + 0xAC) = temp_v0_2;
        if (arg0 < temp_v0_2) {
            *(int*)(&D_80070328 + 0xAC) = arg0;
        }
    }
    if ((D_8006C5BC == 0x2A) &&
        (*(int*)(&D_80070328 + 0x24C) == 1)) {
        var_v1 = *(int*)(&D_80070328 + 0xA4) & 0xFFF;
        if (var_v1 >= 0x801) {
            var_v1 -= 0x1000;
        }
        var_v0_3 = (var_v1 >= 0) ? var_v1 : -var_v1;
        if (var_v0_3 >= 0x401) {
            *(int*)(&D_80070328 + 0xA4) = 0x800;
            return;
        }
        *(int*)(&D_80070328 + 0xA4) = 0;
    }
}

/**
 * ???() - func_80040F48() - MATCHING
 * Just needs variable cleanups / labelling
 * https://decomp.me/scratch/kqmRi
 */
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

/* Retail source: USA Rev 0 PSX.EXE 0x800410F8..0x80041404 (195 words).
 * Updates signed camera-input accumulators once per input tick. Analog bytes
 * are centered on 0x7f; accumulated values clamp to [-0x7f, 0x7f], and the
 * digital decay step is 0x20. Confidence is exact: all 195 words and the
 * complete executable match; any mismatch in either falsifies this decode. */
void func_800410F8(SpyroInputPair* output, Vector3D* state, int usePitch) {
    SpyroInputPair input;
    int temp_a3;
    int temp_a3_2;
    int temp_v0;
    int temp_v0_10;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;
    int temp_v0_7;
    int temp_v0_8;
    int temp_v0_9;
    int temp_v1;
    int temp_v1_2;
    int var_v1;
    int var_v1_2;

    if (D_8006E536 != 0) {
        temp_v0 = D_8006C570->unkE - 0x7F;
        input.unk0 = temp_v0;
        input.unk4 = 0x7F - D_8006C570->unkF;
        temp_v0_2 = temp_v0 - state->z;
        input.unk0 = temp_v0_2;
        if (temp_v0_2 < -0x10) input.unk0 = -0x10;
        if (input.unk0 >= 0x11) input.unk0 = 0x10;
        temp_v0_3 = state->z + input.unk0;
        state->z = temp_v0_3;
        if (temp_v0_3 < -0x7F) state->z = -0x7F;
        if (state->z >= 0x80) state->z = 0x7F;
        input.unk0 = state->z;
        temp_v0_4 = input.unk4 - state->y;
        input.unk4 = temp_v0_4;
        if (temp_v0_4 < -0x10) input.unk4 = -0x10;
        if (input.unk4 >= 0x11) input.unk4 = 0x10;
        temp_v0_5 = state->y + input.unk4;
        state->y = temp_v0_5;
        if (temp_v0_5 < -0x7F) state->y = -0x7F;
        if (state->y >= 0x80) state->y = 0x7F;
        input.unk4 = state->y;
    } else {
        temp_v1 = D_8006C570->unk0;
        if (temp_v1 & 0x1000) {
            temp_v0_6 = state->y + 0x10;
            state->y = temp_v0_6;
            if (temp_v0_6 >= 0x80) state->y = 0x7F;
        } else if (temp_v1 & 0x4000) {
            temp_v0_7 = state->y - 0x10;
            state->y = temp_v0_7;
            if (temp_v0_7 < -0x7F) state->y = -0x7F;
        } else {
            temp_a3 = state->y;
            var_v1 = -temp_a3;
            if (var_v1 >= 0x21) var_v1 = 0x20;
            if (var_v1 < -0x20) var_v1 = -0x20;
            state->y = temp_a3 + var_v1;
        }
        input.unk4 = state->y;
        temp_v1_2 = D_8006C570->unk0;
        if (temp_v1_2 & 0x2000) {
            temp_v0_8 = state->z + 0x10;
            state->z = temp_v0_8;
            if (temp_v0_8 >= 0x80) state->z = 0x7F;
        } else if (temp_v1_2 & 0x8000) {
            temp_v0_9 = state->z - 0x10;
            state->z = temp_v0_9;
            if (temp_v0_9 < -0x7F) state->z = -0x7F;
        } else {
            temp_a3_2 = state->z;
            var_v1_2 = -temp_a3_2;
            if (var_v1_2 >= 0x21) var_v1_2 = 0x20;
            if (var_v1_2 < -0x20) var_v1_2 = -0x20;
            state->z = temp_a3_2 + var_v1_2;
        }
        input.unk0 = state->z;
    }
    output->unk0 = -input.unk0;
    if (input.unk4 == 0 && usePitch == 0) {
        temp_v0_10 = *(int*)(&D_80070328 + 0x60) >> 3;
        output->unk4 = temp_v0_10;
        if (temp_v0_10 >= 0x80) output->unk4 = 0x7F;
        if (output->unk4 < -0x7F) output->unk4 = -0x7F;
    } else {
        output->unk4 = input.unk4;
    }
}

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

/* Retail source: USA Rev 0 PSX.EXE 0x80042A44..0x80042F64
 * (328 instructions; linked bytes SHA-256
 * c2f493402ae048dc2d254f6d6b551c12db65cbccb885736dbfcbff7c6db8c24a).
 * Called by the player update and level animation collision paths. Runtime
 * positions and probe heights are signed integers; the contact angle result
 * is narrowed to a signed byte before storage. Each call resets and updates
 * one collision-contact result set. Confidence: exact. Falsifiable by the
 * complete instruction/relocation stream and executable/overlay hashes. */
#define M2C_FIELD(p,t,o) (*(t)((char *)(p) + (o)))
extern char D_80070328_s2 asm ("D_80070328");
extern char D_80070328_b8_check asm ("D_80070328");
extern char D_80070328_b8_store asm ("D_80070328");
extern char D_80070328_bc_check asm ("D_80070328");
extern int D_8007192C, D_80071930, D_80071934;
void func_8004EA90(Angle*, SHORTMATRIX*, int*);
void func_8004F5DC(int, Vector3D*);
int func_8001A358(Vector3D*, int);
void func_80042A44(void) {
    Vector3D sp18;
    Vector3D sp28;
    SHORTMATRIX sp38;
    Angle sp50;
    Vector3D sp58;
    SHORTMATRIX *var_a0;
    SHORTMATRIX *var_a0_2;
    int temp_v0_3;
    register int temp_v1 asm ("$3");
    signed char *temp_s0;
    signed char *temp_s0_2;
    signed char *temp_s0_3;
    signed char *temp_s1;
    register signed char *temp_s2 asm ("$18");
    signed char temp_v0;
    signed char temp_v0_2;

    temp_s0 = &D_80070328 + 0xB8;
    M2C_FIELD(&D_80070328, int *, 0xB8) = (int) (M2C_FIELD(&D_80070328, int *, 0xB8) + 1);
    func_8004F168(temp_s0 + 0x14);
    M2C_FIELD(&D_80070328, int *, 0xD4) = 0x1000;
    M2C_FIELD(&D_80070328, int *, 0xE4) = 0;
    M2C_FIELD(&D_80070328, signed char *, 0xFC) = 0;
    M2C_FIELD(&D_80070328, int *, 0x2C0) = -1;
    if (M2C_FIELD(&D_80070328, unsigned char *, 0xFD) == 0) {
        temp_v1 = -M2C_FIELD(&D_80070328, int *, 0x44);
        sp18.z = temp_v1 + 0x60;
        sp28.z = temp_v1 - 0x60;
        sp18.x = 0;
        sp28.x = 0;
        sp18.y = 0;
        sp28.y = 0;
        if (M2C_FIELD(&D_80070328, int *, 0x50) == 0x13) {
            sp50.roll = 0;
            sp50.pitch = M2C_FIELD(&D_80070328, unsigned char *, 0xD);
            sp50.yaw = M2C_FIELD(&D_80070328, unsigned char *, 0xE);
            func_8004EA90((Angle *) &sp50, &sp38, 0);
            var_a0 = &sp38;
        } else {
            var_a0 = (SHORTMATRIX *) (temp_s0 - 0x88);
        }
        func_8004ED6C(var_a0, (Vector3D *) &sp18, (Vector3D *) &sp18);
        func_8004F194((Vector3D *) &sp18, (Vector3D *) &sp18, (Vector3D *) &D_80070328);
        func_8004ED6C(0, (Vector3D *) &sp28, (Vector3D *) &sp28);
        func_8004F194((Vector3D *) &sp28, (Vector3D *) &sp28, (Vector3D *) &D_80070328);
        if (func_8001830C((Vector3D *) &sp18, (Vector3D *) &sp28, 4, 0, 0) != 0) {
            func_8004F178(&D_80070328 + 0xCC, &D_80071918);
            temp_v0 = func_8004E880(D_80071920, func_8004EDE8(&D_80071918, 0), 0);
            M2C_FIELD(&D_80070328, int *, 0xE4) = (int) temp_v0;
            if (temp_v0 < 0) {
                M2C_FIELD(&D_80070328, int *, 0xE4) = 0x400;
            }
            if (D_8007192C < 0) {
                M2C_FIELD(&D_80070328, int *, 0x13C) = (int) D_80071930;
            } else {
                M2C_FIELD(&D_80070328, int *, 0x13C) = 0;
            }
            temp_s0_2 = &D_80070328 + 0xE4;
            if ((M2C_FIELD(&D_80070328, int *, 0xE4) < 0x21) || (M2C_FIELD(&D_80070328, int *, 0x48) == 0x24)) {
                M2C_FIELD(&D_80070328, int *, 0xB8) = 0;
                M2C_FIELD(&D_80070328, signed char *, 0x1B5) = (signed char) (M2C_FIELD(&D_80070328, int *, 0xE4) < 0x17);
                M2C_FIELD(&D_80070328, int *, 0x10C) = (int) D_80071924;
                M2C_FIELD(&D_80070328, int *, 0x2C0) = (int) D_8007192C;
                if (D_8007192C >= 0) {
                    func_8004F5DC(D_8007192C, (Vector3D *) (temp_s0_2 + 0x1E0));
                }
                sp18.y = 0;
                sp28.y = 0;
                {
                    register int lower asm ("$2");
                    int height = M2C_FIELD(&D_80070328, int *, 0x44);
                    lower = height - 0x60;
                    temp_v1 = -height;
                    sp18.x = lower;
                }
                sp18.z = temp_v1 + 0x60;
                sp28.z = temp_v1 - 0x60;
                sp28.x = M2C_FIELD(&D_80070328, int *, 0x44) + 0x60;
                if (M2C_FIELD(&D_80070328, int *, 0x50) == 0x13) {
                    var_a0_2 = &sp38;
                } else {
                    var_a0_2 = (SHORTMATRIX *) (temp_s0_2 - 0xB4);
                }
                func_8004ED6C(var_a0_2, (Vector3D *) &sp18, (Vector3D *) &sp18);
                func_8004F194((Vector3D *) &sp18, (Vector3D *) &sp18, (Vector3D *) &D_80070328);
                func_8004ED6C(0, (Vector3D *) &sp28, (Vector3D *) &sp28);
                func_8004F194((Vector3D *) &sp28, (Vector3D *) &sp28, (Vector3D *) &D_80070328);
                if (func_80018368((Vector3D *) &sp18, (Vector3D *) &sp28) == 0) {
                    M2C_FIELD(&D_80070328, signed char *, 0xFC) = 1;
                }
            }
        } else {
            M2C_FIELD(&D_80070328, int *, 0x13C) = 0;
        }
        temp_s2 = &D_80070328_s2 + 0x48;
        __asm__ volatile ("" : "=r"(temp_s2) : "0"(temp_s2));
        if (M2C_FIELD(temp_s2, int *, 0) != 0xD) {
            if ((M2C_FIELD(temp_s2, int *, 0) != 3) && (M2C_FIELD(&D_80070328_b8_check, int *, 0xB8) != 0) && (M2C_FIELD(&D_80070328_bc_check, int *, 0xBC) == 0)) {
                temp_s1 = temp_s2 - 0x48;
                sp18.x = 0;
                sp18.y = 0;
                sp28.x = 0;
                sp28.y = 0;
                temp_v1 = -M2C_FIELD(&D_80070328, int *, 0x44);
                sp18.z = temp_v1 + 0x60;
                sp28.z = temp_v1 - 0x60;
                func_8004F194((Vector3D *) &sp18, (Vector3D *) &sp18, (Vector3D *) temp_s1);
                func_8004F194((Vector3D *) &sp28, (Vector3D *) &sp28, (Vector3D *) temp_s1);
                if (func_8001830C((Vector3D *) &sp18, (Vector3D *) &sp28, 4, 0, 0) != 0) {
                    temp_s0_3 = temp_s2 + 0x84;
                    func_8004F178(temp_s0_3, &D_80071918);
                    temp_v0_2 = func_8004E880(M2C_FIELD(&D_80070328, int *, 0xD4), func_8004EDE8(temp_s0_3, 0), 0);
                    M2C_FIELD(&D_80070328, int *, 0xE4) = (int) temp_v0_2;
                    if (temp_v0_2 < 0) {
                        M2C_FIELD(&D_80070328, int *, 0xE4) = 0x400;
                    }
                    {
                        register int contactAngle asm ("$5");
                        contactAngle = M2C_FIELD(&D_80070328, int *, 0xE4);
                    if ((contactAngle < 0x21) || (M2C_FIELD(temp_s2, int *, 0) == 0x24)) {
                        register int shallowContact asm ("$2");
                        register int surfaceValue asm ("$3");
                        register int collisionIndex asm ("$4");
                        surfaceValue = D_80071924;
                        collisionIndex = D_8007192C;
                        shallowContact = contactAngle < 0x17;
                        M2C_FIELD(&D_80070328_b8_store, int *, 0xB8) = 0;
                        M2C_FIELD(temp_s2, signed char *, 0x16D) = (signed char) shallowContact;
                        M2C_FIELD(temp_s2, int *, 0xC4) = surfaceValue;
                        M2C_FIELD(temp_s2, int *, 0x278) = collisionIndex;
                        if (collisionIndex >= 0) {
                            func_8004F5DC(collisionIndex, (Vector3D *) (temp_s2 + 0x27C));
                        }
                    }
                    }
                }
            }
        }
    }
    func_8004F178(&sp58, &D_80070328);
    {
        register Vector3D *probePosition asm ("$4");
        register int positionZ asm ("$2");
        register int height asm ("$3");
        register int probeHeight asm ("$5");
        probePosition = &sp58;
        height = M2C_FIELD(&D_80070328, volatile int *, 0x44);
        positionZ = *(volatile int *)&sp58.z;
        probeHeight = (height * 2) + 0x200;
        positionZ += 0x100;
        positionZ += height;
        sp58.z = positionZ;
        temp_v0_3 = func_8001A358(probePosition, probeHeight);
    }
    sp58.z = temp_v0_3;
    if ((temp_v0_3 != 0) && (D_80071934 != 0)) {
        M2C_FIELD(&D_80070328, unsigned char *, 0x100) = 1U;
        M2C_FIELD(&D_80070328, int *, 0xF4) = temp_v0_3;
        return;
    }
    if (M2C_FIELD(&D_80070328, unsigned char *, 0x100) == 0) {
        M2C_FIELD(&D_80070328, int *, 0xF4) = 0;
    }
    M2C_FIELD(&D_80070328, unsigned char *, 0x100) = 0U;
}
#undef M2C_FIELD

/* Retail source: USA Rev 0 asm/nonmatchings/spyroupdate/func_80042F64.s,
 * 0x80042F64..0x80043194 (140 instruction words). The function derives
 * signed byte angles from runtime vectors, transforms three Vector3D points,
 * and applies collision displacement once per call. Confidence: confirmed by
 * a 140/140 word comparison and PSX.EXE SHA-256
 * e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f;
 * changing any branch, field offset, angle shift, or 8-unit dead zone is a
 * falsifiable mismatch against that executable. */
extern CollisionData D_80071900;
void func_8004EA90(Angle*, SHORTMATRIX*, int*);
void func_80042F64(void) {
    Vector3D sp10;
    Vector3D sp20;
    Vector3D sp30;
    Angle sp40;
    SHORTMATRIX sp48;
    register unsigned char* flag __asm__("$16") =
        (unsigned char*)&D_80070328 + 0xFE;
    Vector3D* position;
    int value;

    if (*flag != 0) {
        sp40.roll = 0;
        sp40.pitch = -func_8004E880(
            func_8004EDE8((Vector3D*)(flag - 0x26), 0),
            *(int*)(&D_80070328 + 0xE0), 0);
        sp40.yaw = func_8004E880(-*(int*)(flag - 0x26),
                                 -*(int*)(&D_80070328 + 0xDC), 0);
    } else {
        sp40.roll = *(int*)(&D_80070328 + 0x5C) >> 4;
        sp40.pitch = *(int*)(&D_80070328 + 0x60) >> 4;
        sp40.yaw = *(int*)(&D_80070328 + 0x64) >> 4;
    }
    func_8004EA90(&sp40, &sp48, 0);
    sp30.y = 0;
    sp30.z = 0;
    sp30.x = *(int*)(&D_80070328 + 0x44);
    func_8004F178(&sp20, &sp30);
    sp20.x += 0xA0;
    func_8004F178(&sp10, &sp30);
    sp10.x -= 0x80;
    func_8004ED6C(&sp48, &sp10, &sp10);
    position = (Vector3D*)&D_80070328;
    func_8004F194(&sp10, position, &sp10);
    func_8004ED6C(0, &sp20, &sp20);
    func_8004F194(&sp20, position, &sp20);
    func_8004ED6C(0, &sp30, &sp30);
    func_8004F194(&sp30, position, &sp30);
    if (func_80018368(&sp10, &sp20) != 0) {
        func_8004F1C8(&sp30, &D_80071900.D_80071900, &sp30);
        value = sp30.x;
        if (value < 0) {
            value = -value;
        }
        if (value < 8) {
            sp30.x = 0;
        }
        value = sp30.y;
        if (value < 0) {
            value = -value;
        }
        if (value < 8) {
            sp30.y = 0;
        }
        value = sp30.z;
        if (value < 0) {
            value = -value;
        }
        if (value < 8) {
            sp30.z = 0;
        }
        func_8004F194(position, position, &sp30);
    }
}

/* Retail source: USA Rev 0 PSX.EXE 0x80043194..0x80043728
 * (357 words; raw text SHA-256
 * d7d426dd6913d7f9c1bf23a3271d890d1c1bfe5606c5da5a794da19673373d63).
 * Each caller invocation builds the current player rotation matrix and runs
 * the selector's collision probe set. Selectors 0..3 run two directional
 * probes; selector 4 runs four. Bounds are signed runtime world units using
 * the retail offsets 0x40, 0x60, 0x80, and 0xA0. Player rotations are signed
 * bytes derived from the stored angles by arithmetic shifts of four bits.
 * Confidence: exact; falsifiable by 419 instruction/relocation records, the
 * six-entry dispatch table, and the complete executable and overlay hashes. */
typedef struct {
    int sp10, sp14, sp18, pad1C;
    int sp20, sp24, sp28, pad2C;
    signed char sp30, sp31, sp32, pad33[5];
    SHORTMATRIX sp38;
} Frame43194;

#define M2C_FIELD_43194(p, t, o) (*(t *)((signed char *)(p) + (o)))
extern int D_8007191C;

int func_80043194(unsigned int arg0) {
    Frame43194 frame;
    int first = arg0;
    register int second asm("$16");
    register int third asm("$18");
    register int fourth asm("$19");
    register unsigned char *playerFlag asm("$4") = (unsigned char *)&D_80070328 + 0xFE;
    register SHORTMATRIX *callA0 asm("$4");
    register int *callA1 asm("$5");
    register int *callA2 asm("$6");
    int result;
    int initial_v0;
    int c0_v0, c0_a3, c0b_v0, c0b_a3;
    int c1_v0, c1_v1; register int c1b_v0 asm("$2"); register int c1b_v1 asm("$3");
    int c2_v1, c2b_a3;
    int c3_v0, c3_v0b, c3_a3, c3_v1, c3b_a3, c3b_v0, c3b_v1;
    int c4a_v1, c4a_v0, c4b_v1, c4b_v0;
    int c4c_v0, c4c_a3, c4d_a3, c4d_v0;
    register int angle01 asm("$2");
    register int angle2 asm("$3");

    if (*playerFlag == 0) return 0;
    playerFlag -= 0xCE;
    frame.sp24 = 0;
    frame.sp10 = 0;
    frame.sp14 = 0;
    initial_v0 = -M2C_FIELD_43194(&D_80070328, int, 0x44) - 0x40;
    frame.sp20 = M2C_FIELD_43194(&D_80070328, int, 0x44) + 0x60;
    frame.sp28 = initial_v0;
    frame.sp18 = initial_v0;
    result = func_800408B8(playerFlag, &frame.sp10, &frame.sp20);
    if ((result == 8) || (result == 0xC)) {
        frame.sp30 = 0;
        second = (int)&D_80071918;
        frame.sp31 = -func_8004E880(func_8004EDE8((Vector3D *)second, 0), D_80071920, 0);
        frame.sp32 = func_8004E880(-*(int *)second, -D_8007191C, 0);
    } else {
        angle01 = M2C_FIELD_43194(&D_80070328, int, 0x5C);
        angle2 = M2C_FIELD_43194(&D_80070328, int, 0x64);
        frame.sp30 = angle01 >> 4;
        __asm__ volatile ("" : : : "memory");
        angle01 = M2C_FIELD_43194(&D_80070328, int, 0x60);
        frame.sp32 = angle2 >> 4;
        frame.sp31 = angle01 >> 4;
    }
    func_8004EA90(&frame.sp30, &frame.sp38, 0);

    switch (first) {
    case 0:
        first = 0;
        frame.sp20 = M2C_FIELD_43194(&D_80070328, int, 0x44) + 0xA0;
        c0_v0 = -M2C_FIELD_43194(&D_80070328, int, 0x44) + 0x40;
        c0_a3 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0x60;
        frame.sp24 = c0_v0;
        frame.sp28 = c0_a3;
        frame.sp10 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0x40;
        frame.sp14 = c0_v0;
        frame.sp18 = c0_a3;
        result = func_800408B8(&frame.sp38, &frame.sp10, &frame.sp20);
        if ((result == 8) || (second = 0, result == 0xC)) { first = 1; second = 0; }
        callA0 = &frame.sp38; callA1 = &frame.sp10; callA2 = &frame.sp20;
        frame.sp20 = M2C_FIELD_43194(&D_80070328, int, 0x44) + 0xA0;
        c0b_v0 = -M2C_FIELD_43194(&D_80070328, int, 0x44);
        c0b_a3 = c0b_v0 + 0x40;
        frame.sp24 = c0b_a3;
        frame.sp28 = c0b_v0;
        frame.sp10 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0x40;
        frame.sp14 = c0b_a3;
        frame.sp18 = c0b_v0;
        goto second_probe;
    case 1:
        first = 0;
        frame.sp20 = M2C_FIELD_43194(&D_80070328, int, 0x44) + 0xA0;
        c1_v0 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0x40;
        c1_v1 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0x60;
        frame.sp24 = c1_v0;
        frame.sp28 = c1_v1;
        frame.sp10 = c1_v0;
        frame.sp14 = c1_v0;
        frame.sp18 = c1_v1;
        result = func_800408B8(&frame.sp38, &frame.sp10, &frame.sp20);
        if ((result == 8) || (second = 0, result == 0xC)) { first = 1; second = 0; }
        callA0 = &frame.sp38; callA1 = &frame.sp10; callA2 = &frame.sp20;
        c1b_v1 = M2C_FIELD_43194(&D_80070328, int, 0x44);
        c1b_v0 = c1b_v1 + 0xA0;
        frame.sp20 = c1b_v0;
        c1b_v0 = c1b_v1 - 0x40;
        c1b_v1 = -c1b_v1;
        frame.sp24 = c1b_v0;
        frame.sp28 = c1b_v1;
        frame.sp10 = c1b_v0;
        frame.sp14 = c1b_v0;
        frame.sp18 = c1b_v1;
        goto second_probe;
    case 2:
        first = 0;
        c2_v1 = -M2C_FIELD_43194(&D_80070328, int, 0x44) + 0xA0;
        frame.sp20 = M2C_FIELD_43194(&D_80070328, int, 0x44) + 0xA0;
        frame.sp24 = c2_v1;
        frame.sp28 = M2C_FIELD_43194(&D_80070328, int, 0x44);
        frame.sp10 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0x40;
        frame.sp14 = c2_v1;
        frame.sp18 = M2C_FIELD_43194(&D_80070328, int, 0x44);
        result = func_800408B8(&frame.sp38, &frame.sp10, &frame.sp20);
        if ((result == 8) || (second = 0, result == 0xC)) { first = 1; second = 0; }
        callA0 = &frame.sp38; callA1 = &frame.sp10; callA2 = &frame.sp20;
        c2b_a3 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0xA0;
        frame.sp20 = M2C_FIELD_43194(&D_80070328, int, 0x44) + 0xA0;
        frame.sp24 = c2b_a3;
        frame.sp28 = M2C_FIELD_43194(&D_80070328, int, 0x44);
        frame.sp10 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0x40;
        frame.sp14 = c2b_a3;
        frame.sp18 = M2C_FIELD_43194(&D_80070328, int, 0x44);
        goto second_probe;
    case 3:
        first = 0;
        frame.sp20 = M2C_FIELD_43194(&D_80070328, int, 0x44) + 0xA0;
        c3_v0 = -M2C_FIELD_43194(&D_80070328, int, 0x44);
        c3_a3 = c3_v0 + 0xA0;
        c3_v0b = c3_v0 - 0xA0;
        c3_v1 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0x40;
        frame.sp24 = c3_a3;
        frame.sp28 = c3_v0b;
        frame.sp10 = c3_v1;
        frame.sp14 = c3_a3;
        frame.sp18 = c3_v0b;
        result = func_800408B8(&frame.sp38, &frame.sp10, &frame.sp20);
        if ((result == 8) || (second = 0, result == 0xC)) { first = 1; second = 0; }
        callA0 = &frame.sp38; callA1 = &frame.sp10; callA2 = &frame.sp20;
        c3b_a3 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0xA0;
        frame.sp20 = M2C_FIELD_43194(&D_80070328, int, 0x44) + 0xA0;
        c3b_v0 = -M2C_FIELD_43194(&D_80070328, int, 0x44) - 0xA0;
        c3b_v1 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0x40;
        frame.sp24 = c3b_a3;
        frame.sp28 = c3b_v0;
        frame.sp10 = c3b_v1;
        frame.sp14 = c3b_a3;
        frame.sp18 = c3b_v0;
second_probe:
        result = func_800408B8(callA0, callA1, callA2);
        if ((result == 8) || (result == 0xC)) second = 1;
        return first & second;
    case 4:
        fourth = 0;
        frame.sp20 = M2C_FIELD_43194(&D_80070328, int, 0x44) + 0xA0;
        c4a_v1 = -M2C_FIELD_43194(&D_80070328, int, 0x44) + 0xA0;
        c4a_v0 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0x40;
        frame.sp24 = c4a_v1;
        frame.sp28 = c4a_v0;
        frame.sp10 = c4a_v0;
        frame.sp14 = c4a_v1;
        frame.sp18 = c4a_v0;
        result = func_800408B8(&frame.sp38, &frame.sp10, &frame.sp20);
        if ((result == 8) || (third = 0, result == 0xC)) { fourth = 1; third = 0; }
        frame.sp20 = M2C_FIELD_43194(&D_80070328, int, 0x44) + 0xA0;
        c4b_v1 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0xA0;
        c4b_v0 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0x40;
        frame.sp24 = c4b_v1;
        frame.sp28 = c4b_v0;
        frame.sp10 = c4b_v0;
        frame.sp14 = c4b_v1;
        frame.sp18 = c4b_v0;
        result = func_800408B8(&frame.sp38, &frame.sp10, &frame.sp20);
        if ((result == 8) || (first = 0, result == 0xC)) { third = 1; first = 0; }
        frame.sp20 = M2C_FIELD_43194(&D_80070328, int, 0x44) + 0xA0;
        c4c_v0 = -M2C_FIELD_43194(&D_80070328, int, 0x44);
        c4c_a3 = c4c_v0 + 0x80;
        frame.sp24 = c4c_a3;
        frame.sp28 = c4c_v0;
        frame.sp10 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0x40;
        frame.sp14 = c4c_a3;
        frame.sp18 = c4c_v0;
        result = func_800408B8(&frame.sp38, &frame.sp10, &frame.sp20);
        if ((result == 8) || (second = 0, result == 0xC)) { first = 1; second = 0; }
        c4d_a3 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0x80;
        frame.sp20 = M2C_FIELD_43194(&D_80070328, int, 0x44) + 0xA0;
        c4d_v0 = -M2C_FIELD_43194(&D_80070328, int, 0x44);
        frame.sp24 = c4d_a3;
        frame.sp28 = c4d_v0;
        frame.sp10 = M2C_FIELD_43194(&D_80070328, int, 0x44) - 0x40;
        frame.sp14 = c4d_a3;
        frame.sp18 = c4d_v0;
        result = func_800408B8(&frame.sp38, &frame.sp10, &frame.sp20);
        if ((result == 8) || (result == 0xC)) second = 1;
        return fourth & third & first & second;
    }
    return 0;
}

#undef M2C_FIELD_43194

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


/* Retail source: USA Rev 0 SCUS-94467 PSX.EXE,
 * 0x800445F8..0x80044C28. The byte at D_80067BAC indexes a 62-byte
 * previous-animation row by the current animation state and selects one of
 * twelve transition paths. Animation selectors and frames are bytes; the
 * transition mode and animation states are 32-bit values. func_80044240 calls
 * this once per D_8006C648 animation tick when the state or transition mode
 * changes. Confidence: exact instruction and relocation match (627/627).
 * Falsifiable vector: modes 0, 4, and 5 plus transition codes 1..12 must
 * reproduce the stores and calls in the cited retail range.
 */
extern unsigned char D_80067BAC[];
extern SpyroAnimRoot ** volatile D_8006C558_volatile __asm__("D_8006C558");
extern volatile int previousAnimationState __asm__("D_80070328+0x1EC");
extern volatile unsigned char outerNextFrame __asm__("D_80070328+0x17");
extern volatile unsigned char transitionNextFrame __asm__("D_80070328+0x17");
extern unsigned char outerFrameCounts[] __asm__("D_80067AA9");
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))
void func_800445F8(void) {
    int temp_a0;
    int temp_v1;
    unsigned char temp_v0;
    unsigned char temp_v0_2;
    int mode;

    mode = M2C_FIELD(&D_80070328, int *, 0x1F0);
    if (mode == 0) goto process;
    if (mode == 4) goto mode_4;
    if (mode == 5) goto mode_5;
    goto process;

mode_4:
    {
        register unsigned char *table asm("$2") = D_80067BAC;
        register int previous asm("$4") = M2C_FIELD(&D_80070328, int *, 0x1EC);
        register int current asm("$5") = M2C_FIELD(&D_80070328, int *, 0x48);
        __asm__ volatile("" : "=r"(table), "=r"(previous), "=r"(current) : "0"(table), "1"(previous), "2"(current));
        {
            register int offset asm("$3") = previous * 0x3E;
            offset += (int) table;
            __asm__ volatile("" : "=r"(offset) : "0"(offset));
            temp_v0 = ((unsigned char *) offset)[current];
        }
        if (((unsigned int) (temp_v0 - 4) < 2U) || (current == previous)) {
            goto block_31;
        }
    }
    goto process;

mode_5:
    __asm__ volatile("" : : "r"(mode));
    if ((unsigned char) D_80066530[M2C_FIELD(&D_80070328, unsigned char *, 0x1C)] >= 0x60U) {
        M2C_FIELD(&D_80070328, unsigned char *, 0x14) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x15);
        M2C_FIELD(&D_80070328, unsigned char *, 0x16) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x17);
    }
    M2C_FIELD(&D_80070328, unsigned char *, 0x1C) = 0x71U;
    {
        register unsigned char nextFrame asm("$2") = outerFrameCounts[M2C_FIELD(&D_80070328, unsigned char *, 0x14) * 4];
        __asm__ volatile("" : "=r"(nextFrame) : "0"(nextFrame));
        M2C_FIELD(&D_80070328, int *, 0x1F0) = 4;
        outerNextFrame = nextFrame;
    }
    return;

process:
if (previousAnimationState != M2C_FIELD(&D_80070328, int *, 0x48)) {
    {
        register int previous asm("$3") = M2C_FIELD(&D_80070328, int *, 0x1EC);
        register unsigned char *table asm("$4");
        __asm__ volatile("" : "=r"(previous) : "0"(previous));
        table = D_80067BAC;
        __asm__ volatile("" : "=r"(table) : "0"(table));
        {
            register int offset asm("$2") = previous * 0x3E;
            offset += (int) table;
            __asm__ volatile("" : "=r"(offset) : "0"(offset));
            temp_v0 = ((unsigned char *) offset)[M2C_FIELD(&D_80070328, int *, 0x48)];
        }
    }
    switch (temp_v0) {                  /* switch 2 */
    case 1:                             /* switch 2 */
        if ((unsigned char) D_80066530[M2C_FIELD(&D_80070328, unsigned char *, 0x1C)] >= 0x60U) {
            M2C_FIELD(&D_80070328, unsigned char *, 0x14) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x15);
            M2C_FIELD(&D_80070328, unsigned char *, 0x16) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x17);
        }
        M2C_FIELD(&D_80070328, unsigned char *, 0x17) = 0U;
        M2C_FIELD(&D_80070328, unsigned char *, 0x15) = (unsigned char) M2C_FIELD(&D_80070328, int *, 0x48);
        if ((M2C_FIELD(&D_80070328, int *, 0x50) == 6) && (M2C_FIELD(&D_80070328, int *, 0x1EC) == 0x23)) {
            if (M2C_FIELD(&D_80070328, short *, 0x148) != 0) {
                M2C_FIELD(&D_80070328, unsigned char *, 0x1C) = 0xF1U;
            } else {
                goto block_20;
            }
        } else {
block_20:
            M2C_FIELD(&D_80070328, unsigned char *, 0x1C) = 0x71U;
        }
        M2C_FIELD(&D_80070328, int *, 0x1F0) = 0;
        M2C_FIELD(&D_80070328, int *, 0x1EC) = (int) M2C_FIELD(&D_80070328, int *, 0x48);
        return;
    case 2:                             /* switch 2 */
        M2C_FIELD(&D_80070328, unsigned char *, 0x16) = 0U;
        M2C_FIELD(&D_80070328, unsigned char *, 0x14) = (unsigned char) M2C_FIELD(&D_80070328, int *, 0x48);
        M2C_FIELD(&D_80070328, unsigned char *, 0x15) = (unsigned char) M2C_FIELD(&D_80070328, int *, 0x48);
        if (M2C_FIELD(&D_80070328, int *, 0x48) == 0x1A) {
            M2C_FIELD(&D_80070328, unsigned char *, 0x17) = 0U;
            M2C_FIELD(&D_80070328, unsigned char *, 0x1C) = 0U;
        } else {
            transitionNextFrame = 1U;
            M2C_FIELD(&D_80070328, unsigned char *, 0x1C) = (unsigned char) (((int) D_8006C558_volatile[M2C_FIELD(&D_80070328, int *, 0x48) & 0xFF]->unk14 >> 0xE) & 0xF0);
        }
        func_80047138();
        temp_v1 = M2C_FIELD(&D_80070328, int *, 0x48);
        M2C_FIELD(&D_80070328, int *, 0x200) = 6;
        M2C_FIELD(&D_80070328, int *, 0x1F0) = 0;
        goto block_48;
    case 3:                             /* switch 2 */
        if ((unsigned char) D_80066530[M2C_FIELD(&D_80070328, unsigned char *, 0x1C)] >= 0x60U) {
            register unsigned char oldFrame asm("$3") = M2C_FIELD(&D_80070328, unsigned char *, 0x17);
            register int frameOffset asm("$4") = M2C_FIELD(&D_80070328, unsigned char *, 0x14);
            register unsigned char nextFrame asm("$2") = oldFrame + 1;
            frameOffset *= 4;
            M2C_FIELD(&D_80070328, unsigned char *, 0x16) = oldFrame;
            M2C_FIELD(&D_80070328, unsigned char *, 0x17) = nextFrame;
            if ((unsigned int) (nextFrame & 0xFF) >= D_80067AA9[frameOffset]) {
                M2C_FIELD(&D_80070328, unsigned char *, 0x17) = D_80067AA8[frameOffset];
            }
        }
        M2C_FIELD(&D_80070328, unsigned char *, 0x1C) = 0x31U;
        temp_v1 = M2C_FIELD(&D_80070328, int *, 0x48);
        goto block_47;
    case 4:                             /* switch 2 */
        M2C_FIELD(&D_80070328, int *, 0x1F0) = 4;
block_31:
        func_80044514();
        return;
    case 5:                             /* switch 2 */
        if ((unsigned char) D_80066530[M2C_FIELD(&D_80070328, unsigned char *, 0x1C)] >= 0x60U) {
            M2C_FIELD(&D_80070328, unsigned char *, 0x14) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x15);
            M2C_FIELD(&D_80070328, unsigned char *, 0x16) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x17);
        }
        M2C_FIELD(&D_80070328, unsigned char *, 0x1C) = 0x71U;
        if ((M2C_FIELD(&D_80070328, int *, 0x1EC) == 7) && (M2C_FIELD(&D_80070328, int *, 0x58) < 0x18)) {
            M2C_FIELD(&D_80070328, unsigned char *, 0x17) = 1U;
            temp_v1 = M2C_FIELD(&D_80070328, int *, 0x48);
            goto block_47;
        }
        temp_v0 = D_80067AA9[M2C_FIELD(&D_80070328, unsigned char *, 0x14) * 4];
        __asm__ volatile("" : "=r"(temp_v0) : "0"(temp_v0));
        M2C_FIELD(&D_80070328, int *, 0x1F0) = 4;
        M2C_FIELD(&D_80070328, unsigned char *, 0x17) = temp_v0;
        return;
    case 10:                            /* switch 2 */
        if ((unsigned char) D_80066530[M2C_FIELD(&D_80070328, unsigned char *, 0x1C)] >= 0x60U) {
            M2C_FIELD(&D_80070328, unsigned char *, 0x14) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x15);
            M2C_FIELD(&D_80070328, unsigned char *, 0x16) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x17);
        }
        {
            register int current asm("$3") = M2C_FIELD(&D_80070328, int *, 0x48);
            register int index asm("$2") = (current & 0xFF) * 4;
            register unsigned char frame asm("$4");
            __asm__ volatile("" : "=r"(index) : "0"(index));
            M2C_FIELD(&D_80070328, unsigned char *, 0x15) = (unsigned char) current;
            __asm__ volatile("" : : : "memory");
            frame = D_80067AA8[index];
            M2C_FIELD(&D_80070328, unsigned char *, 0x1C) = 0x71U;
            M2C_FIELD(&D_80070328, int *, 0x1EC) = current;
            M2C_FIELD(&D_80070328, int *, 0x1F0) = 0;
            M2C_FIELD(&D_80070328, unsigned char *, 0x17) = frame;
        }
        return;
    case 11:                            /* switch 2 */
        if ((unsigned char) D_80066530[M2C_FIELD(&D_80070328, unsigned char *, 0x1C)] >= 0x60U) {
            M2C_FIELD(&D_80070328, unsigned char *, 0x14) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x15);
            M2C_FIELD(&D_80070328, unsigned char *, 0x16) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x17);
        }
        {
            register int current asm("$3") = M2C_FIELD(&D_80070328, int *, 0x48);
            register int index asm("$2") = (current & 0xFF) * 4;
            register unsigned char frame asm("$4");
            __asm__ volatile("" : "=r"(index) : "0"(index));
            M2C_FIELD(&D_80070328, unsigned char *, 0x15) = (unsigned char) current;
            __asm__ volatile("" : : : "memory");
            frame = D_80067AA9[index];
            M2C_FIELD(&D_80070328, unsigned char *, 0x1C) = 0x71U;
            M2C_FIELD(&D_80070328, int *, 0x1EC) = current;
            M2C_FIELD(&D_80070328, int *, 0x1F0) = 4;
            M2C_FIELD(&D_80070328, unsigned char *, 0x17) = frame;
        }
        return;
    case 12:                            /* switch 2 */
        if ((unsigned char) D_80066530[M2C_FIELD(&D_80070328, unsigned char *, 0x1C)] >= 0x60U) {
            M2C_FIELD(&D_80070328, unsigned char *, 0x14) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x15);
            M2C_FIELD(&D_80070328, unsigned char *, 0x16) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x17);
        }
        M2C_FIELD(&D_80070328, unsigned char *, 0x17) = 0U;
        M2C_FIELD(&D_80070328, unsigned char *, 0x1C) = 0xF1U;
        temp_v1 = M2C_FIELD(&D_80070328, int *, 0x48);
        goto block_47;
    }
} else {
    return;
}
    return;

block_47:
    M2C_FIELD(&D_80070328, int *, 0x1F0) = 0;
    M2C_FIELD(&D_80070328, unsigned char *, 0x15) = (unsigned char) temp_v1;
block_48:
    M2C_FIELD(&D_80070328, int *, 0x1EC) = temp_v1;
}
#undef M2C_FIELD


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
/* Retail source: USA Rev 0 PSX.EXE 0x80044CF0..0x800451C4
 * (309 instructions; linked bytes SHA-256
 * 3a976cc68ef17ed59429c3f6ddeca5542dcc38944afa776ca24524edcea2d9d6).
 * Called once per D_8006C648 animation tick from func_80044240 when the
 * secondary animation path is active. Animation selectors and frames are
 * unsigned bytes; packed transition frames use high/low nibbles. State and
 * selector-table transitions occur once per call. Confidence: exact.
 * Falsifiable by the complete instruction/relocation stream and the
 * executable/overlay manifest hashes. */
#define M2C_FIELD(p,t,o) (*(t)((char *)(p) + (o)))
extern char D_80067BA0, D_80068AB0;
extern char **D_8006C558_raw asm ("D_8006C558");
extern char D_80070328_anim asm ("D_80070328");
extern char D_80070328_frame asm ("D_80070328");
extern char D_80070328_case0 asm ("D_80070328");
extern char D_80070328_third_old asm ("D_80070328");
extern char D_80070328_third_new asm ("D_80070328");
void func_80044CF0(void) {
    register signed char *temp_s0 asm ("$16");
    int mode;
    register int six asm ("$17");
    unsigned char temp_s0_2;
    unsigned char temp_s0_3;
    unsigned char temp_v1_2;
    unsigned char temp_v1_3;

    temp_s0 = &D_80070328 + 0x200;
    __asm__ volatile ("" : "=r"(temp_s0) : "0"(temp_s0));
    mode = M2C_FIELD(temp_s0, int *, 0);
    six = 6;
    if ((mode != six) && (mode != 0)) {
        register unsigned int packedFrame asm ("$4");
        register int highNibble asm ("$2");
        register int lowNibble asm ("$3");
        packedFrame = M2C_FIELD(temp_s0, unsigned char *, -0x1E3);
        highNibble = packedFrame >> 4;
        lowNibble = packedFrame & 0xF;
        if (lowNibble != highNibble) {
            highNibble = packedFrame & 0xF0;
            lowNibble += 1;
            highNibble += lowNibble;
            M2C_FIELD(temp_s0, unsigned char *, -0x1E3) = highNibble;
        } else {
            register unsigned int frame asm ("$4");
            register unsigned int anim asm ("$6");
            register int temp_a3 asm ("$7");
            char *record;
            char **roots;
            anim = M2C_FIELD(&D_80070328_anim, unsigned char *, 0x19);
            roots = D_8006C558_raw;
            __asm__ volatile ("" : "=r"(roots) : "0"(roots));
            frame = M2C_FIELD(&D_80070328_frame, unsigned char *, 0x1B);
            __asm__ volatile ("" : "=r"(frame) : "0"(frame));
            temp_a3 = anim * 4;
            record = roots[anim] + (frame * 0x14);
            M2C_FIELD(temp_s0, unsigned char *, -0x1E3) = (unsigned char) ((M2C_FIELD(record, int *, 0x14) >> 0xE) & 0xF0);
            switch (mode) { /* switch 1; irregular */
            case 1:                                 /* switch 1 */
                M2C_FIELD(&D_80070328, unsigned char *, 0x18) = anim;
                M2C_FIELD(&D_80070328, unsigned char *, 0x1A) = frame;
                M2C_FIELD(temp_s0, int *, 0) = 9;
                break;
            case 8:                                 /* switch 1 */
                func_80047138();
                {
                    register int savedIndexNow asm ("$2");
                    savedIndexNow = M2C_FIELD(&D_80070328, int *, 0x170);
                    M2C_FIELD(temp_s0, int *, 0) = six;
                    M2C_FIELD(&D_80070328, int *, 0x1FC) = savedIndexNow;
                }
                break;
            case 4:                                 /* switch 1 */
                temp_v1_2 = frame + 1;
                M2C_FIELD(&D_80070328, unsigned char *, 0x18) = anim;
                M2C_FIELD(&D_80070328, unsigned char *, 0x1A) = frame;
                M2C_FIELD(&D_80070328, unsigned char *, 0x1B) = temp_v1_2;
                if ((temp_v1_2 & 0xFF) >= (*(D_80067AAA + temp_a3) - 1)) {
                    M2C_FIELD(temp_s0, int *, 0) = 9;
                }
                break;
            case 7:                                 /* switch 1 */
                temp_v1_3 = frame + 1;
                M2C_FIELD(&D_80070328, unsigned char *, 0x18) = anim;
                M2C_FIELD(&D_80070328, unsigned char *, 0x1A) = frame;
                M2C_FIELD(&D_80070328, unsigned char *, 0x1B) = temp_v1_3;
                if ((temp_v1_3 & 0xFF) >= (*(D_80067AAA + temp_a3) - 1)) {
                    M2C_FIELD(temp_s0, unsigned char *, -0x1E3) = 0x71U;
                    {
                        register unsigned int previousAnim asm ("$3");
                        register unsigned int previousFrame asm ("$4");
                        register int savedIndex asm ("$5");
                        previousAnim = M2C_FIELD(&D_80070328, unsigned char *, 0x15);
                        __asm__ volatile ("" : "=r"(previousAnim) : "0"(previousAnim) : "memory");
                        previousFrame = M2C_FIELD(&D_80070328, unsigned char *, 0x17);
                        savedIndex = M2C_FIELD(&D_80070328, int *, 0x170);
                        M2C_FIELD(temp_s0, int *, 0) = 8;
                        M2C_FIELD(&D_80070328, unsigned char *, 0x19) = previousAnim;
                        M2C_FIELD(&D_80070328, unsigned char *, 0x1B) = previousFrame;
                        M2C_FIELD(&D_80070328, int *, 0x1FC) = savedIndex;
                    }
                }
                break;
            }
        }
    }
    if (M2C_FIELD(&D_80070328, int *, 0x200) == 9) {
        register int oldIndex asm ("$4");
        register int newIndex asm ("$2");
        oldIndex = M2C_FIELD(&D_80070328, int *, 0x1FC);
        newIndex = M2C_FIELD(&D_80070328, int *, 0x170);
        if (oldIndex == newIndex) {
            {
                register unsigned char *transitionTable asm ("$2");
                register int transitionOffset asm ("$3");
                transitionTable = (unsigned char *)&D_80068AB0;
                transitionOffset = oldIndex * 4;
                transitionOffset += oldIndex;
                transitionOffset *= 2;
                transitionOffset += (int) transitionTable;
                transitionOffset += oldIndex;
                temp_s0_2 = *(unsigned char *)transitionOffset;
            }
            switch (temp_s0_2) {                    /* switch 2; irregular */
            case 6:                                 /* switch 2 */
                if (M2C_FIELD(&D_80070328, unsigned char *, 0x19) == M2C_FIELD(&D_80070328, unsigned char *, 0x15)) {
                    func_80047138();
                    M2C_FIELD(&D_80070328, int *, 0x200) = (int) temp_s0_2;
                } else {
                    M2C_FIELD(&D_80070328, unsigned char *, 0x19) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x15);
                    M2C_FIELD(&D_80070328, unsigned char *, 0x1D) = 0x71U;
                    M2C_FIELD(&D_80070328, int *, 0x200) = 1;
                    M2C_FIELD(&D_80070328, unsigned char *, 0x1B) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x17);
                }
                break;
            case 0:                                 /* switch 2 */
            {
                register unsigned char *mappedAnim asm ("$3");
                register unsigned char *mapBase asm ("$2");
                register unsigned int activeAnim asm ("$4");
                mapBase = (unsigned char *)&D_80067BA0;
                __asm__ volatile ("" : "=r"(mapBase) : "0"(mapBase));
                mappedAnim = (unsigned char *)(oldIndex + (int)mapBase);
                __asm__ volatile ("" : "=r"(mappedAnim) : "0"(mappedAnim));
                activeAnim = M2C_FIELD(&D_80070328_case0, unsigned char *, 0x19);
                if (activeAnim == *mappedAnim) {
                    M2C_FIELD(&D_80070328, int *, 0x200) = 0;
                    M2C_FIELD(&D_80070328, unsigned char *, 0x1D) = 0x71U;
                    func_80044C28();
                } else {
                    register unsigned int activeFrame asm ("$2");
                    register unsigned int mappedValue asm ("$3");
                    activeFrame = M2C_FIELD(&D_80070328_case0, unsigned char *, 0x1B);
                    __asm__ volatile ("" : "=r"(activeFrame) : "0"(activeFrame));
                    M2C_FIELD(&D_80070328, unsigned char *, 0x18) = activeAnim;
                    M2C_FIELD(&D_80070328, unsigned char *, 0x1A) = activeFrame;
                    mappedValue = *mappedAnim;
                    __asm__ volatile ("" : "=r"(mappedValue) : "0"(mappedValue));
                    M2C_FIELD(&D_80070328, unsigned char *, 0x1D) = 0x71U;
                    M2C_FIELD(&D_80070328, unsigned char *, 0x1B) = 0U;
                    M2C_FIELD(&D_80070328, int *, 0x200) = 1;
                    M2C_FIELD(&D_80070328, unsigned char *, 0x19) = mappedValue;
                }
                break;
            }
            case 7:                                 /* switch 2 */
                M2C_FIELD(&D_80070328, int *, 0x200) = (int) temp_s0_2;
                M2C_FIELD(&D_80070328, unsigned char *, 0x1B) = (unsigned char) (M2C_FIELD(&D_80070328, unsigned char *, 0x1B) + 1);
                break;
            }
            goto block_32;
        }
        goto block_33;
    }
block_32:
    if (M2C_FIELD(&D_80070328, int *, 0x1FC) != M2C_FIELD(&D_80070328, int *, 0x170)) {
block_33:
    {
        register int oldIndex asm ("$4");
        register int newIndex asm ("$5");
        {
            register unsigned char *transitionTable asm ("$2");
            register int transitionOffset asm ("$3");
            transitionTable = (unsigned char *)&D_80068AB0;
            oldIndex = M2C_FIELD(&D_80070328_third_old, int *, 0x1FC);
            newIndex = M2C_FIELD(&D_80070328_third_new, int *, 0x170);
            transitionOffset = oldIndex * 4;
            transitionOffset += oldIndex;
            transitionOffset *= 2;
            transitionOffset += (int) transitionTable;
            transitionOffset += newIndex;
            temp_s0_3 = *(unsigned char *)transitionOffset;
        }
        switch (temp_s0_3) {                        /* switch 3; irregular */
        case 1:                                     /* switch 3 */
        {
            register unsigned int mappedValue asm ("$3");
            if ((unsigned char) D_80066530[M2C_FIELD(&D_80070328, unsigned char *, 0x1D)] >= 0x60U) {
                M2C_FIELD(&D_80070328, unsigned char *, 0x18) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x19);
                M2C_FIELD(&D_80070328, unsigned char *, 0x1A) = (unsigned char) M2C_FIELD(&D_80070328, unsigned char *, 0x1B);
            }
            mappedValue = (unsigned char) *(&D_80067BA0 + newIndex);
            __asm__ volatile ("" : "=r"(mappedValue) : "0"(mappedValue));
            M2C_FIELD(&D_80070328, unsigned char *, 0x1B) = 0U;
            M2C_FIELD(&D_80070328, unsigned char *, 0x1D) = 0x71U;
            M2C_FIELD(&D_80070328, int *, 0x1FC) = newIndex;
            M2C_FIELD(&D_80070328, int *, 0x200) = (int) temp_s0_3;
            M2C_FIELD(&D_80070328, unsigned char *, 0x19) = mappedValue;
            return;
        }
        case 6:                                     /* switch 3 */
            func_80047138();
            M2C_FIELD(&D_80070328, int *, 0x200) = (int) temp_s0_3;
            M2C_FIELD(&D_80070328, int *, 0x1FC) = (int) M2C_FIELD(&D_80070328, int *, 0x170);
            return;
        case 4:                                     /* switch 3 */
            if (M2C_FIELD(&D_80070328, unsigned char *, 0x19) == *(&D_80067BA0 + oldIndex)) {
                M2C_FIELD(&D_80070328, int *, 0x200) = (int) temp_s0_3;
            }
            M2C_FIELD(&D_80070328, int *, 0x1FC) = newIndex;
            break;
        }
    }
    }
}
#undef M2C_FIELD

/* Retail source: USA Rev 0 SCUS-94467 PSX.EXE,
 * 0x800451C4..0x800458F8. Runs once per player update while D_80071834
 * is active. Animation/effect selectors are bytes; packed model components are
 * sign-extended 11-bit integers before matrix transforms. Confidence: exact
 * instruction and relocation match (597/597). Falsifiable vectors: active
 * flag 0/1, selector values 13/14, effect slots 0..7, and null/non-null
 * SpawnParticle. */
extern char **D_8006C558_raw __asm__("D_8006C558");
extern int D_80071924;
extern Unk_8006d048 D_8006D048;
#define D_8006C558 D_8006C558_raw
#define M2C_FIELD_451C4(expr,type_ptr,offset) (*(type_ptr)((signed char *)(expr)+(offset)))
int func_8004F554(Vector3D *, void *, int);     /* extern */
int rand();                                         /* extern */
extern char D_80069598[];
extern char D_800695EC[];
extern char D_800695F8[];
extern char D_800698B8[];
extern unsigned char D_80069C58[];
extern char D_80069C68[];
extern Vector3D D_8007179C;
extern unsigned char D_800717A8;
extern unsigned char D_800717A9;
extern unsigned char D_800717AA;
extern unsigned char D_800717BC[];
extern unsigned char D_800717C4[];
extern unsigned char D_800717CC[];
extern unsigned char D_80071834;
extern unsigned char D_80071835;
extern unsigned char D_80071836;
extern SHORTMATRIX D_80071838;
extern char D_80071860[];

typedef struct {
    Vector3D sp18;
    char pad24[4];
    Vector3D sp28;
    char pad34[4];
    Vector3D sp38;
    char pad44[4];
    int sp48;
    char pad4C[8];
} Stack451C4;
void func_800451C4(void) {
    Stack451C4 frame;
    register char *var_a1 asm("$5");
    register char *var_s6 asm("$22");
    register char *var_v0 asm("$2");
    SpecialSurface *temp_v1_2;
    register int temp_a3 asm("$7");
    register int temp_t1 asm("$9");
    int var_a0;
    int var_a2;
    int var_a3;
    int var_fp;
    int var_lo;
    register int var_s4 asm("$20");
    signed char *temp_s0;
    signed char *temp_s1;
    register unsigned char *var_s3 asm("$19");
    register unsigned char *var_s5 asm("$21");
    unsigned char temp_a1;
    void *temp_v1;
    register Vector3D *workPos asm("$17");
    register SHORTMATRIX *matrix asm("$23");
    register Vector3D *scratchPos asm("$18");

    frame.sp48 = 0;
    if (D_80071834 != 0) {
        if ((M2C_FIELD_451C4(&D_80070328, int *, 0xB8) == 0) && ((unsigned char) M2C_FIELD_451C4(&D_80070328, unsigned char *, 0xD) >= 0x81U)) {
            M2C_FIELD_451C4(&D_80070328, int *, 0x18C) = (int) ((0x100 - M2C_FIELD_451C4(&D_80070328, unsigned char *, 0xD)) * 8);
        } else {
            M2C_FIELD_451C4(&D_80070328, int *, 0x18C) = 0;
        }
        {
            register int loopDelta asm("$4") = D_8006C648;
            register int loopIndex asm("$7") = 0;
            if (loopDelta > 0) {
                register unsigned char *loopState asm("$5") = &D_80071835;
                register unsigned char *lookup asm("$6") = D_80069C58;
                register int thirtyTwo asm("$8") = 0x20;
                register unsigned char *entry asm("$2");
                register unsigned char entryIndex asm("$3");
                register unsigned char nextState asm("$2");
                register int outputValue asm("$2");
                register unsigned char stateValue asm("$3");
                do {
                    stateValue = loopState[0];
                    if (stateValue < 8U) {
                        __asm__ volatile("" : : : "memory");
                        entry = (unsigned char *)((loopState[2] * 8) + (int)lookup);
                        entry += stateValue;
                        entryIndex = *entry;
                        __asm__ volatile("" : : "r"(entryIndex));
                        outputValue = loopDelta - loopIndex;
                        __asm__ volatile("" : : "r"(outputValue));
                        D_800717BC[entryIndex] = outputValue;
                        entry = (unsigned char *)((loopState[2] * 8) + (int)lookup);
                        entry += loopState[0];
                        D_800717C4[*entry] = thirtyTwo;
                        entry = (unsigned char *)((loopState[2] * 8) + (int)lookup);
                        entry += loopState[0];
                        D_800717CC[*entry] = 0;
                    }
                    loopIndex += 1;
                    nextState = loopState[0];
                    loopDelta = D_8006C648;
                    nextState += 1;
                    loopState[0] = nextState;
                } while (loopIndex < loopDelta);
            }
        }
        {
            register unsigned char *active asm("$17") = &D_80071836;
            if (*active != 0) {
            func_80049484((int) &frame.sp18);
            {
            register Vector3D *collisionPos asm("$4") = &frame.sp18;
            register int collisionRadius asm("$5") = 0xA0;
            register int collisionZero asm("$6") = 0;
            register int collisionObject asm("$2");
            register int collisionFourth asm("$7");
            __asm__ volatile("" : "=r"(collisionPos), "=r"(collisionRadius), "=r"(collisionZero) : "0"(collisionPos), "1"(collisionRadius), "2"(collisionZero));
            temp_s0 = &D_80070328 + 0x250;
            collisionFourth = 0;
            __asm__ volatile("" : "=r"(collisionFourth) : "0"(collisionFourth));
            collisionObject = *(int *)temp_s0;
            __asm__ volatile("" : "=r"(collisionObject) : "0"(collisionObject));
            temp_t1 = 0x10000;
            __asm__ volatile("" : "=r"(temp_t1) : "0"(temp_t1));
            func_8001BA30(collisionPos, collisionRadius, collisionZero, collisionFourth, temp_t1, collisionObject);
            }
            D_800717A8 = M2C_FIELD_451C4(&D_80070328, unsigned char *, 0xC);
            D_800717A9 = M2C_FIELD_451C4(&D_80070328, unsigned char *, 0xD);
            D_800717AA = M2C_FIELD_451C4(&D_80070328, unsigned char *, 0xE);
            func_8004E7D4((int *) (active + 2), (int *) (temp_s0 - 0xB0), 0x14);
            {
                register unsigned int packedAddress asm("$3") = M2C_FIELD_451C4(&D_80070328, unsigned char *, 0x14);
                register char **models asm("$2") = D_8006C558;
                register unsigned int frameIndex asm("$6") = M2C_FIELD_451C4(&D_80070328, unsigned char *, 0x16);
                packedAddress = (unsigned int)models[packedAddress];
                packedAddress += frameIndex * 0x14;
                temp_a3 = M2C_FIELD_451C4(packedAddress, int *, 0x1C);
            }
            {
                register int packedComponent asm("$2");
                packedComponent = temp_a3 >> 0x15;
                frame.sp18.x = packedComponent;
                packedComponent = (int) (temp_a3 << 0xB) >> 0x15;
                frame.sp18.y = packedComponent;
                packedComponent = (int) (temp_a3 << 0x16) >> 0x15;
                frame.sp18.z = packedComponent;
            }
            func_8004ED6C((SHORTMATRIX *) (temp_s0 - 0x220), &frame.sp18, &frame.sp18);
            func_8004F194((Vector3D *) (active - 0x9A), &frame.sp18, (Vector3D *) (temp_s0 - 0x250));
            {
                unsigned int animationState = (unsigned char) M2C_FIELD_451C4(&D_80071835, unsigned char *, 0);
                register Vector3D *callPos asm("$4");
                if (animationState < 0xEU) {
                    callPos = &frame.sp18;
                    var_a1 = ((animationState >> 1) * 0xC) + D_80069598;
                } else {
                    callPos = &frame.sp18;
                    var_a1 = D_800695EC;
                }
                var_s4 = 0;
                func_8004F178(callPos, var_a1);
            }
            temp_s1 = &D_80070328 + 0x1A0;
            func_8004ED6C((SHORTMATRIX *) temp_s1, &frame.sp18, &frame.sp18);
            func_8004F194(&D_8007179C, &D_8007179C, &frame.sp18);
            func_8004F1C8((Vector3D *)((char *)&D_8007179C + 0x124), &D_8007179C, temp_s1 - 0x1A0);
        } else {
            func_8004F194((Vector3D *) (active - 0x9A), (Vector3D *) &D_80070328, (Vector3D *) (active + 0x8A));
            var_s4 = 0;
        }
        }
        workPos = &frame.sp28;
        scratchPos = &frame.sp38;
        var_fp = 0;
        matrix = &D_80071838;
        var_s3 = (unsigned char *)((char *)matrix - 0x7C);
        var_s5 = (unsigned char *)((char *)matrix - 0x6C);
        var_s6 = D_80071860;
        do {
            if (*var_s3 != 0) {
                var_a2 = 0x16;
                if (var_s4 < 4) {
                    var_a0 = 0x1E;
                } else {
                    var_a2 = 0x1C;
                    var_a0 = 0x24;
                }
                if (*var_s5 != 0) {
                    *var_s3 += D_8006C648;
                }
                if ((int) *var_s3 >= var_a0) {
                    *var_s3 = 0;
                    goto block_44;
                }
                if (*var_s5 != 2) {
                    var_lo = var_s4 * var_a2;
                    if (var_s4 < 4) {
                        var_v0 = D_800695F8;
                    } else {
                        register int tableIndex asm("$2") = var_s4 - 4;
                        __asm__ volatile("" : "=r"(tableIndex) : "0"(tableIndex));
                        var_lo = tableIndex * var_a2;
                        var_v0 = D_800698B8;
                    }
                    {
                        register int tableOffsetBytes asm("$3");
                        temp_t1 = var_lo;
                        __asm__ volatile("" : "=r"(temp_t1) : "0"(temp_t1));
                        tableOffsetBytes = temp_t1 * 8;
                        __asm__ volatile("" : "=r"(tableOffsetBytes) : "0"(tableOffsetBytes));
                        temp_v1 = (void *)(tableOffsetBytes + (int)var_v0);
                    }
                    temp_a1 = *var_s3;
                    if ((int) temp_a1 < (var_a2 - 1)) {
                        func_8004F554(workPos, temp_v1 + ((temp_a1 + 1) * 8), var_a2);
                        func_8004ED6C(matrix, workPos, workPos);
                        func_8004F194(workPos, workPos, (Vector3D *)((char *)matrix - 0x9C));
                        if (*var_s5 == 0) {
                            func_8004F178(&frame.sp38, &D_80070328);
                            *var_s5 = 1;
                        } else {
                            func_8004F178(&frame.sp38, var_s6);
                        }
                        func_8004F178(var_s6, workPos);
                        {
                        register Vector3D *collisionPos2 asm("$4") = workPos;
                        register int collisionRadius2 asm("$5") = 0xA0;
                        register int collisionZero2 asm("$6") = 0;
                        register int collisionFourth2 asm("$7");
                        register int collisionObject2 asm("$2");
                        int collisionHit;
                        __asm__ volatile("" : "=r"(collisionPos2), "=r"(collisionRadius2), "=r"(collisionZero2) : "0"(collisionPos2), "1"(collisionRadius2), "2"(collisionZero2));
                        temp_s0 = &D_80070328 + 0x250;
                        collisionFourth2 = 0;
                        __asm__ volatile("" : "=r"(collisionFourth2) : "0"(collisionFourth2));
                        collisionObject2 = *(int *)temp_s0;
                        __asm__ volatile("" : "=r"(collisionObject2) : "0"(collisionObject2));
                        temp_t1 = 0x10000;
                        __asm__ volatile("" : "=r"(temp_t1) : "0"(temp_t1));
                        collisionHit = func_8001BA30(collisionPos2, collisionRadius2, collisionZero2, collisionFourth2, temp_t1, collisionObject2);
                        if ((collisionHit != 0) || (func_8001830C(&frame.sp38, workPos, 0, 0x10000, *(int *)temp_s0) != 0)) {
                            *var_s5 = 2;
                            *(D_800717C4 + var_s4) = *var_s3;
                            if (SpawnParticle != 0) {
                                {
                                    int particleRand;
                                    frame.sp38.x = -0x10;
                                    particleRand = rand();
                                    temp_t1 = (int)D_80071860;
                                    __asm__ volatile("" : : "r"(temp_t1));
                                    frame.sp38.y = (particleRand & 0x1F) - 0x10;
                                    frame.sp38.z = 0;
                                    func_8004ED6C((SHORTMATRIX *)(temp_t1 - 0x28), scratchPos, scratchPos);
                                }
                                frame.sp38.z = 0;
                                SpawnParticle(1, 1, workPos, scratchPos);
                                SpawnParticle(4, 0x4E, workPos, 0);
                                frame.sp38.x = 0x30;
                                frame.sp38.y = 0;
                                frame.sp38.z = 0;
                                func_8004ED6C(0, scratchPos, scratchPos);
                                SpawnParticle(5, 0x4F, workPos, scratchPos);
                            }
                            {
                                register int *surface asm("$16") = &D_80071924;
                                if (func_80040954(*surface) == 3) {
                                    {
                                        register SpecialSurface *surfaceData asm("$3");
                                        surfaceData = D_8006D048.m_SurfaceData[*surface & 0x3F];
                                        __asm__ volatile("" : : "r"(surfaceData));
                                        temp_t1 = 0x10000;
                                        surfaceData->unk4 |= temp_t1;
                                    }
                                }
                            }
                        }
                        }
                        goto block_44;
                    }
                    if ((var_a2 < (temp_a1 + D_8006C648)) && (var_a2 >= (int) temp_a1) && (func_8004F554(workPos, temp_v1 + ((var_a2 - 2) * 8), var_a2), func_8004ED6C(matrix, workPos, workPos), func_8004F194(workPos, workPos, (Vector3D *)((char *)matrix - 0x9C)), func_8004F168(scratchPos), (SpawnParticle != 0))) {
                        SpawnParticle(1, 0, workPos, scratchPos);
                        SpawnParticle(4, 0x4E, workPos, 0);
                        func_8004ED6C(0, var_fp + D_80069C68, scratchPos);
                        SpawnParticle(5, 0x4F, workPos, scratchPos);
                        __asm__ volatile("" : : : "memory");
                        var_fp += 0xC;
                    } else {
                        goto block_44;
                    }
                } else {
                    goto block_44;
                }
            } else {
                temp_t1 = frame.sp48;
                temp_t1 += 1;
                frame.sp48 = temp_t1;
block_44:
                var_fp += 0xC;
            }
            var_s3 += 1;
            var_s5 += 1;
            var_s4 += 1;
            var_s6 += 0xC;
        } while (var_s4 < 8);
        temp_t1 = frame.sp48;
        if (temp_t1 == 8) {
            D_80071834 = 0;
        }
    }
}
#undef M2C_FIELD_451C4
#undef D_8006C558

/* Retail source: USA Rev 0 PSX.EXE 0x800458F8..0x80045D70
 * (286 instructions; linked bytes SHA-256
 * 945dd8f78afd55854f7755e6faa9c38b25097b30a556404a6639343cab777631).
 * Called once per player-update frame by func_8003E83C. Positions and collision
 * probes are signed runtime coordinates; rotations use byte angles and Q12
 * sine/cosine results. The eight probe slots update one bit per call.
 * Confidence: exact. Falsifiable by the complete instruction/relocation stream,
 * the linked function hash above, and the executable/overlay manifest hashes. */extern int D_8006FBA8;
extern int D_8006FBB4;
extern int D_8006FBB8;
extern unsigned char D_8006FBB9, D_8006FBBA;
extern signed char D_8006FBBB;
extern int D_8006FBBC, D_8006FBC0;
extern char D_80068C4C;
extern int D_8007191C;
extern void func_8004E7D4(int*, int*, int);
extern int func_8001A358(Vector3D*, int);
extern int func_8004F388(int);

void func_800458F8(void) {
    Vector3D vector;
    SHORTMATRIX matrix;
    register char* state __asm__("$19") = &D_80070328 + 0x1E;
    register int* cameraMode __asm__("$18");
    int slope;
    int ground;

    if (*(unsigned char*)state < 0x7F)
        *(unsigned char*)state = 5;
    cameraMode = &D_8006FBBC;
    {
        register int cameraModeValue __asm__("$2") = 3;
        int height = *(int*)(&D_80070328 + 0x44);
        *cameraMode = cameraModeValue;
        vector.z = -height;
    }
    __asm__ volatile ("" : "=r"(cameraMode) : "0"(cameraMode));
    D_8006FBBB = 0;
    vector.x = 0;
    vector.y = 0;

    if (*(int*)(&D_80070328 + 0x50) == 13) {
        Vector3D* camera = (Vector3D*)((char*)cameraMode - 0x10);
        Vector3D* player = (Vector3D*)(state - 0x1E);
        *(unsigned char*)((char*)cameraMode - 4) = *(unsigned char*)(&D_80070328 + 0xC);
        D_8006FBB9 = *(unsigned char*)(&D_80070328 + 0xD) + 0x40;
        D_8006FBBA = *(unsigned char*)(&D_80070328 + 0xE);
        func_8004EA90((Angle*)((char*)cameraMode - 4), &matrix, 0);
        func_8004ED6C(&matrix, &vector, &vector);
        func_8004F194(camera, &vector, player);
        func_8004F1C8(&vector, camera, player);
        func_8004F194(&vector, &vector, camera);
        if (func_80018368(player, &vector) == 0)
            D_8006FBBB = 1;
    } else {
        SHORTMATRIX* playerMatrix = (SHORTMATRIX*)(state + 0x12);
        Vector3D* camera = (Vector3D*)((char*)cameraMode - 0x10);
        func_8004ED6C(playerMatrix, &vector, &vector);
        func_8004F194(camera, &vector, (Vector3D*)(state - 0x1E));
        D_8006FBB4 += 0x80;
        D_8006FBB4 = func_8001A358(camera, 0x10000);

        if (*(int*)(&D_80070328 + 0x50) < 2) {
            func_8004E7D4((int*)&matrix, (int*)playerMatrix, 0x14);
            slope = *(int*)(&D_80070328 + 0xE4);
            D_8006FBB8 = *(int*)(&D_80070328 + 0xC);
        } else {
            register int sine __asm__("$16") = func_8004EA2C(*(int*)(&D_80070328 + 0x64));
            int cosine = func_8004E9E4(*(int*)(&D_80070328 + 0x64));
            vector.x = ((D_80071918.x * sine) + (D_8007191C * cosine)) >> 12;
            sine = func_8004EA2C(*(int*)(&D_80070328 + 0x64));
            cosine = func_8004E9E4(*(int*)(&D_80070328 + 0x64));
            vector.y = ((D_8007191C * sine) - (D_80071918.x * cosine)) >> 12;
            vector.z = D_80071920;
            {
                int roll = func_8004E880(func_8004F388((vector.x * vector.x) + (vector.z * vector.z)), vector.y, 0);
                register int zero __asm__("$6") = 0;
                register int secondZ __asm__("$4") = vector.z;
                register int secondX __asm__("$5") = vector.x;
                __asm__ volatile (""
                    : "=r"(zero), "=r"(secondZ), "=r"(secondX)
                    : "0"(zero), "1"(secondZ), "2"(secondX));
                *(unsigned char*)((char*)cameraMode - 4) = -roll;
                D_8006FBB9 = -func_8004E880(secondZ, secondX, zero);
            }
            D_8006FBBA = *(unsigned char*)(&D_80070328 + 0xE);
            func_8004EA90((Angle*)((char*)cameraMode - 4), &matrix, 0);
            slope = func_8004E880(D_80071920, func_8004EDE8(&D_80071918, 0), 0);
        }

        if (D_8006FBB4 < 0x401 || *(int*)(&D_80070328 + 0x28) < 0)
            D_8006FBBB = 1;
        {
            register int* cameraHeight __asm__("$16") = &D_8006FBB4;
            {
                int playerZ = *(int*)(&D_80070328 + 8);
                int cameraZ = *cameraHeight;
                int baseZ = *(int*)(&D_80070328 + 0x44);
                playerZ -= cameraZ;
                baseZ += 0x100;
                if (baseZ < playerZ)
                    D_8006FBBC = 5;
            }

            D_8006FBC0 = (D_8006FBC0 + 1) & 7;
            func_8004ED6C(&matrix, (Vector3D*)(&D_80068C4C + D_8006FBC0 * 12), &vector);
            func_8004F194(&vector, &vector, (Vector3D*)((char*)cameraHeight - 8));
            vector.z += 0x200;
            ground = func_8001A358(&vector, 0x400);
            {
                int difference;
                difference = vector.z - 0x200;
                vector.z = difference;
                difference -= ground;
                if (difference < 0) {
                    __asm__ volatile ("");
                    difference = -difference;
                }
                difference = difference < 0x40;
                if (!difference || slope >= 0x21)
                    D_8006FBA8 |= 1 << D_8006FBC0;
                else
                    D_8006FBA8 &= 0xFF - (1 << D_8006FBC0);
            }
        }
    }
    __asm__ volatile ("" : : "r"(state), "r"(cameraMode));
}

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

extern int D_8006E344;
extern int D_8006FA38;
extern int D_80067648[];
void func_8005F35C(void*, void*, void*);
/* Retail source: USA Rev 0 PSX.EXE 0x80047190..0x800473E4 (149 words).
 * The saved position and rotation vectors use runtime integer units; this
 * routine runs once per reset, clears the 0x2E8-byte Spyro state outside mode
 * 13, restores the retained vectors and counter, rebuilds both matrices, and
 * initializes the retail sound, animation, and camera fields. Confidence:
 * exact; falsifiable by all 149 instruction words, the executable SHA-256,
 * and every overlay SHA-256 in sha256sum.txt. */
void func_80047190(void) {
    Vector3D position;
    Vector3D rotation;
    register char* state __asm__("$18");
    register int* soundIndex __asm__("$16");
    register char* rotationState __asm__("$17");
    register int savedCounter __asm__("$19");
    register int* gameMode __asm__("$20");
    register int resetMode __asm__("$21");
    register int minusOne __asm__("$3");
    register int byteMax __asm__("$2");
    register Vector3D* positionArg __asm__("$4");

    soundIndex = (int*)(&D_80070328 + 0x28C);
    if (*soundIndex >= 0 &&
        func_8003BF6C(*(int*)(&D_80070328 + 0x290), *soundIndex) != 0) {
        func_8003BE70(*soundIndex);
    }
    soundIndex = (int*)(&D_80070328 + 0x294);
    positionArg = &position;
    if (*soundIndex >= 0) {
        int soundActive =
            func_8003BF6C(*((unsigned char*)D_8006C654 + 6), *soundIndex);

        positionArg = &position;
        if (soundActive != 0) {
            func_8003BE70(*soundIndex);
            positionArg = &position;
        }
    }

    state = &D_80070328;
    func_8004F178(positionArg, state);
    {
        register void* destination __asm__("$4");

        soundIndex = (int*)&rotation;
        destination = soundIndex;
        __asm__ volatile("" : "=r"(destination) : "0"(destination));
        rotationState = state + 0x5C;
        func_8004F178(destination, rotationState);
    }
    gameMode = &D_8006E344;
    resetMode = 13;
    byteMax = *gameMode;
    __asm__ volatile("" : "=r"(state) : "0"(state));
    savedCounter = *(int*)(state + 0x280);
    if (byteMax != resetMode) {
        func_8004E790(state, 0, 0x2E8);
    }
    {
        register void* destination __asm__("$4") = state;

        __asm__ volatile("" : "=r"(destination) : "0"(destination));
        minusOne = -1;
        byteMax = 0xFF;
        *(int*)(&D_80070328 + 0x28C) = minusOne;
        *(int*)(&D_80070328 + 0x294) = minusOne;
        *(int*)(&D_80070328 + 0x108) = byteMax;
        *(int*)(&D_80070328 + 0x10C) = byteMax;
        *(int*)(&D_80070328 + 0x110) = byteMax;
        *(int*)(&D_80070328 + 0x2C0) = minusOne;
        func_8004F178(destination, &position);
    }
    func_8004F178(state + 0x124, state);
    func_8004F178(rotationState, &rotation);

    {
        register Angle* angle __asm__("$4") = (Angle*)(state + 0xC);
        __asm__ volatile("" : "=r"(angle) : "0"(angle));
        rotationState = state + 0x30;
        func_8004EA90(angle, (SHORTMATRIX*)rotationState, 0);
    }
    {
        register Angle* angle __asm__("$4") = (Angle*)(state + 0x10);
        __asm__ volatile("" : "=r"(angle) : "0"(angle));
        soundIndex = (int*)(state + 0x1A0);
        func_8004EA90(angle, (SHORTMATRIX*)soundIndex, 0);
    }
    func_8005F35C(rotationState, soundIndex, soundIndex);

    byteMax = *gameMode;
    *(int*)(&D_80070328 + 0x280) = savedCounter;
    if (byteMax != resetMode) {
        minusOne = D_8006FA38;
        *(int*)(&D_80070328 + 0xF8) = D_80067648[D_8006C58C];
        if (minusOne >= 0) {
            func_8004BEF8(0x21);
            *(int*)(&D_80070328 + 0xB0) = 0x800;
            func_80041848();
            soundIndex = (int*)(state + 0x80);
            func_8004F178(state + 0x8C, soundIndex);
            func_8004F178(state + 0x98, soundIndex);
        } else {
            func_8004BEF8(0);
        }
        *(unsigned char*)(&D_80070328 + 0x1C) = 0x10;
        *(unsigned char*)(&D_80070328 + 0x1D) = 0x10;
        *(int*)(&D_80070328 + 0x200) = 6;
    }
}

/* Retail source: USA Rev 0 SCUS-94467, PSX.EXE 0x800473E4..0x80047C7C.
 * Player command flags and state fields preserve retail byte/word access widths.
 * Angles wrap to 12 bits; packed unsigned angles expand by 4 bits, while the
 * relative yaw command is signed 8-bit. Vector helpers retain retail operands.
 * Cadence: one player command update invocation.
 * Falsifiable vectors: command masks 0x2..0x20000, null/non-null actor pointer,
 * state IDs 0/8/46/115, character range boundaries 65..180 and zero actor count.
 * Confidence: complete retail executable and overlay hash match.
 * Empty constraints emit no instructions; yaw aliases preserve absolute accesses. */
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern char D_8006E508, D_8006E3D0;
extern int D_8006E538;
extern int playerYawRead asm("D_80070328+0x64");
extern int playerYawWrite asm("D_80070328+0x064");
extern int D_8006E404;
extern int D_8006E414;

void func_800473E4(void) {
    struct { Vector3D first; int gap; Vector3D second; int reserved[4]; } frame;
    register Vector3D *var_a1 asm("$5");
    register int *var_a0_2 asm("$4");
    register int *var_v1 asm("$3");
    int temp_v0;
    register int flagBits asm("$2");
    register int mask asm("$4");
    unsigned int mode;
    register int *flags3 asm("$3");
    register int *flags2 asm("$2");
    register int temp_v1 asm("$3");
    register int count0 asm("$4");
    register int count1 asm("$7");
    register int var_a1_2 asm("$5");
    register int var_a1_3 asm("$5");
    register int var_a2 asm("$6");
    signed char *temp_a0;
    signed char *temp_a0_2;
    register signed char *temp_a0_3 asm("$4");
    register signed char *temp_a0_4 asm("$4");
    register signed char *temp_s0 asm("$16");
    register signed char *temp_s0_2 asm("$16");
    register signed char *temp_s0_3 asm("$16");
    register signed char *temp_s1 asm("$17");
    register signed char *temp_s1_2 asm("$17");
    register signed char *var_a0 asm("$4");
    unsigned int var_a0_3;

    if (!(M2C_FIELD(&D_80070328, int *, 0x20C) & 0x2000) && (M2C_FIELD(&D_80070328, int *, 0x210) & 0x2000)) {
        M2C_FIELD(&D_80070328, int *, 0x288) = 0;
    }
    temp_s0 = ((char *)&D_80070328 + 0x20C);
    __asm__("" : "=r"(temp_s0) : "0"(temp_s0));
    if (*(int *)temp_s0 & 0x10000000) {
        if (*(int *)temp_s0 & 2) {
            func_8003A964(&D_8006E508, &D_8006E3D0);
            M2C_FIELD(&D_80070328, int *, 0x240) = 1;
            M2C_FIELD(&D_80070328, signed char *, 0x1B9) = 0;
        }
        if (*(int *)temp_s0 & 0x4000) {
            func_8003A964(&D_8006E508, &D_8006E3D0);
        }
        if (*(int *)temp_s0 & 8) {
            func_8004F178(&frame.first, temp_s0 + 0x10);
            func_8004F0E8(&frame.first, 6);
            temp_a0 = temp_s0 - 0x198;
            func_8004F194((Vector3D *) temp_a0, (Vector3D *) temp_a0, &frame.first);
            playerYawWrite = (playerYawRead + M2C_FIELD(&D_80070328, signed char *, 0x22A)) & 0xFFF;
        }
        if ((*(int *)temp_s0 & 0x10) && (M2C_FIELD(&D_80070328, unsigned int *, 0x48) != 0x15)) {
            func_8004BEF8(0x15U);
        }
        if ((M2C_FIELD(&D_80070328, int *, 0x20C) & 0x20) && (M2C_FIELD(&D_80070328, int *, 0x50) != 0xE) && (M2C_FIELD(&D_80070328, int *, 0x50) != 6) && (M2C_FIELD(&D_80070328, int *, 0x50) != 9) && (M2C_FIELD(&D_80070328, int *, 0x280) >= 0) && (M2C_FIELD(M2C_FIELD(&D_80070328, void **, 0x218), short *, 0x36) == 0x3FF)) {
            func_8004BEF8(0x13U);
        }
        temp_s1 = ((char *)&D_80070328 + 0x20C);
    __asm__("" : "=r"(temp_s1) : "0"(temp_s1));
        if (*(int *)temp_s1 & 0x40) {
            func_8003A964(&D_8006E508, &D_8006E3D0);
            if (!(M2C_FIELD(&D_80070328, int *, 0x210) & 0x40)) {
                func_8004F1C8(&frame.second, temp_s1 - 0x20C, temp_s1 + 0x20);
                if ((func_8004EDE8(&frame.second, 0) < 0x100) && (M2C_FIELD(&D_80070328, int *, 0xB4) < 0x640)) {
                    M2C_FIELD(&D_80070328, int *, 0x214) = 1;
                }
            }
            temp_a0_2 = ((char *)&D_80070328 + 0x50);
            if (M2C_FIELD(&D_80070328, int *, 0x50) == 0xB) {
                func_800486FC((Vector3D *) (temp_a0_2 + 0x1DC));
            } else {
                var_a1 = M2C_FIELD(&D_80070328, void **, 0x218);
                if (var_a1 != 0) {
                    var_a1 = (Vector3D *)((char *)var_a1 + 12);
                    var_a0 = temp_a0_2 + 0x1DC;
                } else {
                    var_a1 = (Vector3D *)((char *)var_a1 + 12);
                    __asm__("" : "=r"(var_a1) : "0"(var_a1));
                    var_a0 = temp_a0_2 + 0x1DC;
                    var_a1 = 0;
                }
                func_80047E6C((Vector3D *) var_a0, var_a1);
            }
            M2C_FIELD(&D_80070328, int *, 0x240) = 1;
            M2C_FIELD(&D_80070328, signed char *, 0x1B9) = 0;
        }
        if ((M2C_FIELD(&D_80070328, int *, 0x20C) & 0x80) && (M2C_FIELD(&D_80070328, int *, 0x50) != 8) && (M2C_FIELD(&D_80070328, unsigned int *, 0x48) != M2C_FIELD(&D_80070328, unsigned int *, 0x23C))) {
            func_8004BEF8(M2C_FIELD(&D_80070328, unsigned int *, 0x23C));
        }
        temp_s1_2 = ((char *)&D_80070328 + 0x20C);
    __asm__("" : "=r"(temp_s1_2) : "0"(temp_s1_2));
        if (*(int *)temp_s1_2 & 0x100) {
            func_8003A964(&D_8006E508, &D_8006E3D0);
            func_80048210((Vector3D *) (temp_s1_2 + 0x20));
            M2C_FIELD(&D_80070328, int *, 0x240) = 1;
            M2C_FIELD(&D_80070328, signed char *, 0x1B9) = 0;
        }
        if (*(int *)temp_s1_2 & 0x400) {
            temp_s0_2 = temp_s1_2 - 0x180;
            func_8004F178(temp_s0_2, temp_s1_2 + 0x10);
            func_8004F0E8((Vector3D *) temp_s0_2, 6);
            func_8004F178(temp_s1_2 - 0x18C, temp_s0_2);
        }
        temp_v1 = *(int *)temp_s1_2;
        if (temp_v1 & 0x2000) {
            M2C_FIELD(&D_80070328, int *, 0x288) = 1;
        }
        flagBits = temp_v1 & 0x8000;
        __asm__("" : "=r"(flagBits) : "0"(flagBits));
        if (flagBits) {
            func_8003A964(&D_8006E508, &D_8006E3D0);
            M2C_FIELD(&D_80070328, int *, 0x240) = 1;
            M2C_FIELD(&D_80070328, signed char *, 0x1B9) = 0;

            if (M2C_FIELD(&D_80070328, unsigned int *, 0x48) != M2C_FIELD(&D_80070328, unsigned int *, 0x23C)) {
                func_8004BEF8(M2C_FIELD(&D_80070328, unsigned int *, 0x23C));
            }
            temp_s0_3 = temp_s1_2 - 0x198;
            func_8004F1C8(temp_s0_3, temp_s1_2 + 0x20, temp_s1_2 - 0x20C);
            func_8004F0E8((Vector3D *) temp_s0_3, 6);
            {
                register int x asm("$2") = M2C_FIELD(&D_80070328, unsigned char *, 0x228);
                register int z asm("$3") = M2C_FIELD(&D_80070328, unsigned char *, 0x22A);
                x <<= 4;
                __asm__("" : "=r"(x) : "0"(x));
                M2C_FIELD(&D_80070328, int *, 0x5C) = x;
                __asm__ volatile("" : : : "memory");
                x = M2C_FIELD(&D_80070328, unsigned char *, 0x229);
                __asm__("" : "=r"(x) : "0"(x), "r"(z));
                z <<= 4;
                __asm__("" : "=r"(z) : "0"(z), "r"(x));
                M2C_FIELD(&D_80070328, int *, 0x64) = z;
                __asm__ volatile("" : : : "memory");
                x <<= 4;
                __asm__("" : "=r"(x) : "0"(x));
                M2C_FIELD(&D_80070328, int *, 0x60) = x;
            }
        }
        temp_v1 = M2C_FIELD(&D_80070328, int *, 0x20C);
        if (temp_v1 & 0x10000) {
            M2C_FIELD(&D_80070328, signed char *, 0xFD) = 1;
        }
        flagBits = temp_v1 & 0x20000;
        __asm__("" : "=r"(flagBits) : "0"(flagBits));
        if (flagBits) {
            if (M2C_FIELD(&D_80070328, int *, 0x24C) == 4) {
                if (D_8006E044 != 0x1F) {
                    flags3 = &D_8006E53C;
                    __asm__("" : "=r"(flags3) : "0"(flags3));
                    *flags3 |= 0x10;
                } else {
                    mask = ~0x10;
                    __asm__("" : "=r"(mask) : "0"(mask));
                    flags2 = &D_8006E53C;
                    __asm__("" : "=r"(flags2) : "0"(flags2));
                    *flags2 &= mask;
                }
                goto block_55;
            }
            var_a1_2 = 0;
            if (M2C_FIELD(&D_80070328, int *, 0x50) != 0) {
                __asm__("" : : "r"(var_a1_2));
                func_8004BEF8(0U);
block_55:
                var_a1_2 = 0;
            }
            var_v1 = &D_8006E538;
            __asm__("" : "=r"(var_v1) : "0"(var_v1));
            flagBits = *var_v1;
            count0 = D_8006C648;
            __asm__("" : "=r"(count0) : "0"(count0), "r"(flagBits));
            *var_v1 = flagBits | 0x10;
            if (count0 > 0) {
                var_v1 = (int *)((char *)var_v1 + 0x10);
                do {
                    var_a1_2 += 1;
                    *var_v1 |= 0x10;
                    var_v1 = (int *)((char *)var_v1 + 0x10);
                } while (var_a1_2 < count0);
            }
            func_8003A964(&D_8006E508, &D_8006E3D0);
            if ((D_8006C5BC == 0x18) || (D_8006C5BC == 0x2C)) {
                D_8006E53C |= D_8006E404 & 0x20;
                var_a1_3 = 0;
                count1 = D_8006C648;
                if (count1 > 0) {
                    var_a0_2 = ((char *)&D_8006E508 + 0x44);
                    var_a2 = 0;
                    do {
                        temp_v0 = *(int *)((char *)&D_8006E414 + var_a2);
                        var_a2 += 0x10;
                        var_a1_3 += 1;
                        *var_a0_2 |= temp_v0 & 0x20;
                        var_a0_2 = (int *)((char *)var_a0_2 + 0x10);
                    } while (var_a1_3 < count1);
                }
            }
            M2C_FIELD(&D_80070328, signed char *, 0x1B9) = 1;
            M2C_FIELD(&D_80070328, int *, 0x240) = 1;
            M2C_FIELD(&D_80070328, int *, 0x288) = 1;
        }
    } else {
        mode = M2C_FIELD(&D_80070328, unsigned int *, 0x48);
        *(int *)temp_s0 = 0;
        M2C_FIELD(&D_80070328, int *, 0x214) = 0;
        M2C_FIELD(&D_80070328, int *, 0x240) = 0;
        switch (mode) {
        case 0x0:
        case 0x8:
        case 0xF:
        case 0x14:
        case 0x27:
        case 0x29:
        case 0x2C:
        case 0x2F:
        case 0x35:
        case 0x36:
        case 0x41:
        case 0x55:
        case 0x64:
        case 0x73:
            if (M2C_FIELD(&D_80070328, unsigned char *, 0x1BA) != 0) {
                if (!(D_8006E538 & 0x10)) {
                    M2C_FIELD(&D_80070328, unsigned char *, 0x1BA) = 0U;
                    M2C_FIELD(&D_80070328, signed char *, 0x1B9) = 1;
                }
            } else {
                M2C_FIELD(&D_80070328, signed char *, 0x1B9) = 1;
            }
            break;
        case 0x2E:
            M2C_FIELD(&D_80070328, unsigned char *, 0x1BA) = 1U;
            goto block_74;
        default:
            M2C_FIELD(&D_80070328, unsigned char *, 0x1BA) = 0U;
block_74:
            M2C_FIELD(&D_80070328, signed char *, 0x1B9) = 0;
            break;
        }
    }
    temp_a0_3 = ((char *)&D_80070328 + 0x244);
    __asm__("" : "=r"(temp_a0_3) : "0"(temp_a0_3));
    if (*(int *)temp_a0_3 != 0) {
        M2C_FIELD(&D_80070328, int *, 0x288) = 1;
        if ((int) M2C_FIELD(&D_80070328, unsigned int *, 0x48) < 0x3E) {
            temp_v1 = M2C_FIELD(temp_a0_3, int *, 4);
            __asm__("" : "=r"(temp_v1) : "0"(temp_v1), "r"(temp_a0_3));
            temp_a0_4 = temp_a0_3 + 4;
            if ((unsigned int) (temp_v1 - 0x41) < 0x14U) {
                M2C_FIELD(&D_80070328, int *, 0x24C) = 1;
            } else if ((unsigned int) (temp_v1 - 0x55) < 0xFU) {
                M2C_FIELD(&D_80070328, int *, 0x24C) = 2;
            } else if ((unsigned int) (temp_v1 - 0x64) < 0xFU) {
                M2C_FIELD(&D_80070328, int *, 0x24C) = 3;
            } else if ((unsigned int) (temp_v1 - 0x73) < 0x14U) {
                M2C_FIELD(&D_80070328, int *, 0x24C) = 4;
            } else if ((unsigned int) (temp_v1 - 0x87) < 0xFU) {
                M2C_FIELD(&D_80070328, int *, 0x24C) = 5;
            } else if ((unsigned int) (temp_v1 - 0x96) < 2U) {
                M2C_FIELD(&D_80070328, int *, 0x24C) = 6;
            } else if ((unsigned int) (temp_v1 - 0x98) < 8U) {
                M2C_FIELD(&D_80070328, int *, 0x24C) = 7;
            } else if ((unsigned int) (temp_v1 - 0xA0) < 5U) {
                M2C_FIELD(&D_80070328, int *, 0x24C) = 8;
            } else {
                flagBits = temp_v1 - 0xA5;
                __asm__("" : "=r"(flagBits) : "0"(flagBits));
                if ((unsigned int)flagBits < 0xAU) {
                M2C_FIELD(&D_80070328, int *, 0x24C) = 9;
            } else if ((unsigned int) (M2C_FIELD(temp_a0_4, int *, 0) - 0xAF) < 5U) {
                M2C_FIELD(temp_a0_4, int *, 4) = 0xA;
            } else {
                M2C_FIELD(temp_a0_4, int *, 4) = 0;
            }
            }
            var_a0_3 = M2C_FIELD(&D_80070328, unsigned int *, 0x248);
            goto block_100;
        }
    } else {
        M2C_FIELD(&D_80070328, int *, 0x24C) = 0;
        var_a0_3 = 0;
        if ((int) M2C_FIELD(&D_80070328, unsigned int *, 0x48) >= 0x3E) {
block_100:
            func_8004BEF8(var_a0_3);
        }
    }
}

#undef M2C_FIELD

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

/* Retail source: USA Rev 0 PSX.EXE 0x80047E6C..0x80048210 (233 words),
 * boot SHA-256 CB819EE78C556D403779309859CB08A7111331F624759BC1BC380946261BB26E,
 * raw function SHA-256 C2A75AAD7FEA127F9B55EA6C45FF1214696FDD61E9B20B8166F546E1D4FA0C50.
 * Target and origin are runtime integer Vector3D positions; angles wrap in the
 * signed 12-bit domain, and sine/cosine products are Q12. One call updates
 * steering and copies exactly D_8006C648 history entries. Confidence is exact:
 * all 233 words and relocations match. Falsify with a null origin (zero relative
 * angle), target distance above 0x60 (saturates to 0x60), and packed Q12 outputs
 * indexed by ((angle - D_8006E040) >> 3) & 0x1FE.
 */
extern signed char D_8006E546, D_8006E547;
extern int D_8006E544;
void func_80047E6C(Vector3D* targetArg, Vector3D* originArg) {
    register Vector3D* target __asm__("$21") = targetArg;
    register Vector3D* origin __asm__("$22") = originArg;
    register int relativeAngle __asm__("$16");
    register int targetAngle __asm__("$17");
    register int targetDistance __asm__("$18");
    register int originDistance __asm__("$19");
    register int originAngle __asm__("$20");
    register int* steeringState __asm__("$4");
    Vector3D delta;
    int absolute;
    volatile int stackPad[2];

    __asm__ ("move %0,$0" : "=r"(originAngle) : "r"(target), "r"(origin));

    *(signed char*)&D_8006E508 = 3;
    func_8004F1C8(&delta, target, (Vector3D*)&D_80070328);
    targetDistance = func_8004EDE8(&delta, 0) >> 2;
    if (targetDistance >= 0x61) targetDistance = 0x60;
    if (origin != 0) {
        func_8004F1C8(&delta, target, origin);
        originDistance = func_8004EDE8(&delta, 0);
        if (originDistance >= 0x80) {
            targetAngle = func_8004E880(delta.x, delta.y, 1);
            func_8004F1C8(&delta, (Vector3D*)&D_80070328, origin);
            originAngle = func_8004E880(delta.x, delta.y, 1);
            {
                register int difference __asm__("$2") = targetAngle - originAngle;
                relativeAngle = difference & 0xFFF;
            }
            if (relativeAngle >= 0x801) relativeAngle -= 0x1000;
        } else {
            relativeAngle = 0;
        }
    } else {
        __asm__ volatile ("move %0,$0" : "=r"(originDistance));
        relativeAngle = 0;
    }

    steeringState = (int*)(&D_80070328 + 0x214);
    if (*steeringState != 0) goto follow_47e6c;
    {
        register int initialAbsolute __asm__("$2");
        initialAbsolute = relativeAngle < 0 ? -relativeAngle : relativeAngle;
        if (initialAbsolute < 0x20 && targetDistance < 0x10) {
follow_47e6c:
        {
            register int desired __asm__("$2") = *(int*)(&D_80070328 + 0x238);
            register int current __asm__("$3") = steeringState[-108];
            relativeAngle = desired << 4;
            targetAngle = (relativeAngle - current) & 0xFFF;
        }
        if (targetAngle >= 0x801) targetAngle -= 0x1000;
        absolute = targetAngle < 0 ? -targetAngle : targetAngle;
        targetDistance = 0;
        if (absolute < 0x50) {
            *steeringState = 2;
            steeringState[-108] = relativeAngle;
        } else {
            targetDistance = absolute >> 5;
            if (targetDistance >= 5) targetDistance = 4;
            if (targetAngle > 0) targetAngle = 0x400;
            else targetAngle = -0x400;
            {
                register int currentYaw __asm__("$2") = *(int*)(&D_80070328 + 0x64);
                currentYaw += targetAngle;
                relativeAngle = currentYaw & 0xFFF;
            }
            if (relativeAngle >= 0x801) relativeAngle -= 0x1000;
            *(int*)(&D_80070328 + 0x214) = 1;
        }
        goto pack_47e6c;
        }
    }
    {
        if (originDistance < 0x80) {
            func_8004F178(&delta, target);
            if (targetDistance < 0x10) *(int*)(&D_80070328 + 0x214) = 1;
        } else {
            if (relativeAngle >= 0x41) relativeAngle = 0x40;
            if (relativeAngle < -0x40) relativeAngle = -0x40;
            relativeAngle += originAngle;
            delta.x = (func_8004EA2C(relativeAngle) * originDistance) >> 12;
            delta.y = (func_8004E9E4(relativeAngle) * originDistance) >> 12;
            delta.z = 0;
            func_8004F194(&delta, &delta, origin);
        }
        func_8004F1C8(&delta, &delta, (Vector3D*)&D_80070328);
        relativeAngle = func_8004E880(delta.x, delta.y, 1);
    }

pack_47e6c:
    {
        register int index __asm__("$4");
        register signed char* output __asm__("$5") = &D_8006E546;
        register int adjusted __asm__("$2");
        int i;
        register int* destination __asm__("$3");
        register int* source __asm__("$5");
        adjusted = relativeAngle - D_8006E040;
        relativeAngle = adjusted >> 3;
        index = relativeAngle & 0x1FE;
        *output = 0x7F - ((targetDistance * *(short*)((char*)D_800658A0 + index)) >> 12);
        D_8006E547 = 0x7F - ((targetDistance * *(short*)((char*)D_80065920 + index)) >> 12);
        __asm__ volatile ("" ::: "memory");
        if ((D_8006E544 & 0xFFFF0000) != 0x7F7F0000) {
            D_8006E536 = 1;
            D_8006E535 = 0;
        }
        i = 0;
        if (D_8006C648 > 0) {
            destination = (int*)(output + 0xE);
            source = destination;
            do {
                *destination = source[-4];
                i++;
                destination += 4;
            } while (i < D_8006C648);
        }
    }
}

/* Retail source: USA Rev 0 asm/nonmatchings/spyroupdate/func_80048210.s,
 * 0x80048210..0x80048444 (141 instruction words). The input and Spyro
 * positions use runtime Vector3D units; the derived direction is a signed
 * angle byte, and the history-copy loop runs once per D_8006C648 tick.
 * Confidence: confirmed by a 141/141 word comparison and PSX.EXE SHA-256
 * e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f;
 * changing the state gates, Q12 trig shifts, 0x7F clamp, or copy cadence is
 * a falsifiable mismatch against that executable. */
extern signed char D_8006E534, D_8006E546, D_8006E547;
extern int D_8006E538, D_8006E544;
extern char D_8006E548[], D_8006E54C[];
extern int D_8006C648;
void func_80048210(Vector3D* target) {
    struct {
        Vector3D delta;
        int pad1;
        int pad2;
    } local;
    register int angle __asm__("$16");
    register int distance __asm__("$17");

    *(signed char*)&D_8006E508 = 3;
    func_8004F1C8(&local.delta, target, (Vector3D*)&D_80070328);
    distance = func_8004EDE8(&local.delta, 0) >> 1;
    if (distance >= 0x80) {
        distance = 0x7F;
    }
    angle = func_8004E880(local.delta.x, local.delta.y, 1);
    if (*(int*)(&D_80070328 + 0x214) == 0) {
        if (*(int*)(&D_80070328 + 0x50) != 2) {
            func_8004BEF8(6);
        }
        D_8006E538 = 0x40;
        if (*(int*)(&D_80070328 + 0xB8) != 0) {
            *(int*)(&D_80070328 + 0x214) = 1;
        }
    } else if (*(int*)(&D_80070328 + 0x214) == 1) {
        D_8006E538 = 0x40;
        if (*(int*)(&D_80070328 + 0xB8) == 0 ||
            *(int*)(&D_80070328 + 0x50) != 2) {
            *(int*)(&D_80070328 + 0x214) = 2;
        }
    }
    if (*(int*)(&D_80070328 + 0x214) < 2) {
        register int index __asm__("$4");
        register signed char* output __asm__("$6");
        register int adjusted __asm__("$2");
        int product;
        int i;
        int offset;
        register int* destination __asm__("$4");
        register int* source __asm__("$6");

        adjusted = angle - D_8006E040;
        angle = adjusted >> 3;
        index = angle & 0x1FE;
        output = &D_8006E546;
        *output = 0x7F - ((distance * *(short*)((char*)D_800658A0 + index)) >> 12);
        product = distance * *(short*)((char*)D_80065920 + index);
        D_8006E534 = 0;
        D_8006E547 = 0x7F - (product >> 12);
        __asm__ volatile ("" ::: "memory");
        if ((D_8006E544 & 0xFFFF0000) != 0x7F7F0000) {
            D_8006E536 = 1;
            D_8006E535 = 0;
        }
        i = 0;
        if (D_8006C648 > 0) {
            destination = (int*)(output + 0xE);
            source = destination;
            offset = 0;
            do {
                *destination = source[-4];
                i++;
                *(int*)((char*)D_8006E548 + offset) = source[-7];
                destination += 4;
                *(int*)((char*)D_8006E54C + offset) = source[-6];
                offset += 0x10;
            } while (i < D_8006C648);
        }
    }
}

int func_8004F284(int, int);
int func_8004F2C8(int, int);
/* Retail source: USA Rev 0 PSX.EXE 0x80048444..0x800486FC (174 words).
 * The target and Spyro position deltas use runtime integer Vector3D units;
 * rotations are wrapped 12-bit angles, and this pursuit update runs once per
 * call. Confidence is exact: falsify by comparing the rebuilt 174 words or
 * the complete executable and overlay hashes against the retail manifest.
 */
int func_80048444(Vector3D* target) {
    Vector3D delta;
    register int angle __asm__("$16");
    register int change __asm__("$17");
    register int maximum __asm__("$18");
    register int* yaw __asm__("$19");
    register int scale __asm__("$20");
    register Vector3D* originalTarget __asm__("$21") = target;
    register int temp __asm__("$2");
    register int pitch __asm__("$3");
    register int roll __asm__("$7");

    func_8004F1C8(&delta, originalTarget, (Vector3D*)&D_80070328);
    angle = func_8004E880(delta.x, delta.y, 1);
    change = func_8004F284(angle, *(int*)(&D_80070328 + 0x64));
    if (change >= 0x320) {
        scale = 0;
        maximum = 0x80;
    } else {
        temp = 0x320 - change;
        scale = temp >> 2;
        if (scale >= 0x65) scale = 0x64;
        temp = change >> 3;
        maximum = temp + 4;
    }

    yaw = (int*)(&D_80070328 + 0x64);
    change = func_8004F2C8(angle, *yaw);
    if (change < -maximum) change = -maximum;
    if (change > maximum) change = maximum;
    *yaw += change;
    func_8004F168((char*)yaw + 0x124);
    func_80046FF8();

    pitch = *(int*)(&D_80070328 + 0x60);
    temp = -pitch;
    angle = temp & 0xFFF;
    if (angle >= 0x801) angle -= 0x1000;
    if (angle < -0x1E) angle = -0x1E;
    if (angle >= 0x1F) angle = 0x1E;
    pitch += angle;
    *(int*)(&D_80070328 + 0x60) = pitch;

    roll = *(int*)(&D_80070328 + 0x5C);
    temp = (-change) << 3;
    temp -= roll;
    angle = temp & 0xFFF;
    if (angle >= 0x801) angle -= 0x1000;
    if (angle < -0x10) angle = -0x10;
    {
        register Angle* rotation __asm__("$4") =
            (Angle*)((char*)yaw - 0x58);
        register SHORTMATRIX* matrix __asm__("$5");

        if (angle >= 0x11) angle = 0x10;
        matrix = (SHORTMATRIX*)((char*)yaw - 0x34);
        temp = roll + angle;
        *(int*)(&D_80070328 + 0x5C) = temp;
        *(volatile signed char*)((char*)yaw - 0x58) = temp >> 4;
        *(signed char*)(&D_80070328 + 0xE) = *yaw >> 4;
        *(signed char*)(&D_80070328 + 0xD) = pitch >> 4;
        __asm__ volatile("" : "=r"(rotation), "=r"(matrix) :
                             "0"(rotation), "1"(matrix));
        func_8004EA90(rotation, matrix, 0);
    }

    angle = func_8004EDE8(&delta, 0);
    if (angle < 0x101) {
        func_8004F178((char*)yaw - 0x64, originalTarget);
        return 0;
    }
    *(int*)(&D_80070328 + 0xB0) = scale;
    func_80041848();
    {
        register int quotient __asm__("$6") = (delta.z * scale) / angle;
        register int positionX __asm__("$3") =
            *(int*)(&D_80070328 + 0);
        register int velocityX __asm__("$4") =
            *(int*)(&D_80070328 + 0x80);
        register int velocityY __asm__("$5") =
            *(int*)(&D_80070328 + 0x84);
        register int positionZ __asm__("$4");

        *(volatile int*)(&D_80070328 + 0) = positionX + velocityX;
        __asm__ volatile("" ::: "memory");
        positionX = *(int*)(&D_80070328 + 4);
        positionZ = *(int*)(&D_80070328 + 8);
        *(int*)(&D_80070328 + 4) = positionX + velocityY;
        *(int*)(&D_80070328 + 8) = positionZ + quotient;
    }
    return angle;
}

/* Retail source: USA Rev 0 PSX.EXE 0x800486FC..0x80048948 (147 words).
 * The target and Spyro positions use runtime integer Vector3D units; rotation
 * fields use signed deltas in the 12-bit 0x000..0xFFF angle domain. One call
 * normalizes the target vector, advances the three rotation words by at most
 * 0x40, and advances the lock state when both residual angles are below 0x20.
 * Confidence: exact; falsifiable by all 147 instruction words, the executable
 * SHA-256, and every overlay SHA-256 in sha256sum.txt. */
void func_800486FC(Vector3D* target) {
    Vector3D delta;
    register int distance __asm__("$16");
    register int targetPitch __asm__("$17");
    register int targetYaw __asm__("$18");
    register int pitchChange __asm__("$6");
    register int yawChange __asm__("$4");
    register int value __asm__("$2");

    func_8004F1C8(&delta, target, (Vector3D*)&D_80070328);
    distance = func_8004EDE8(&delta, 1);
    if (*(int*)(&D_80070328 + 0x214) == 0) {
        targetYaw = func_8004E880(delta.x, delta.y, 1);
        targetPitch = func_8004E880(func_8004EDE8(&delta, 0), delta.z, 1);
        if (distance < 0x201) {
            *(int*)(&D_80070328 + 0x214) = 1;
        }
    } else {
        value = *(int*)(&D_80070328 + 0x238);
        targetPitch = 0;
        targetYaw = value << 4;
    }
    if (distance >= 0x81) {
        func_8004F08C(&delta, distance, 0x80);
    }
    func_8004F0E8(&delta, 4);
    func_8004F178(&D_80070328 + 0x80, &delta);
    func_8004F178(&D_80070328 + 0x8C, &D_80070328 + 0x80);

    value = targetYaw - *(int*)(&D_80070328 + 0x64);
    yawChange = value & 0xFFF;
    if (yawChange >= 0x801) {
        yawChange -= 0x1000;
    }
    value = targetPitch - *(int*)(&D_80070328 + 0x60);
    pitchChange = value & 0xFFF;
    if (pitchChange >= 0x801) {
        pitchChange -= 0x1000;
    }
    if (*(int*)(&D_80070328 + 0x214) == 1) {
        value = ABS(yawChange);
        if (value < 0x20) {
            value = ABS(pitchChange);
            if (value < 0x20) {
                *(int*)(&D_80070328 + 0x214) = 2;
            }
        }
    }
    if (yawChange < -0x40) yawChange = -0x40;
    if (yawChange >= 0x41) yawChange = 0x40;
    if (pitchChange < -0x40) pitchChange = -0x40;
    if (pitchChange >= 0x41) pitchChange = 0x40;
    {
        register int* yaw __asm__("$5") =
            (int*)(&D_80070328 + 0x64);
        register int currentYaw __asm__("$3") = *yaw;
        register int currentPitch __asm__("$2");
        register int currentRoll __asm__("$7");

        currentRoll = *(int*)(&D_80070328 + 0x5C);
        __asm__ volatile("" : : "r"(currentRoll) : "memory");
        currentPitch = *(int*)(&D_80070328 + 0x60);

        currentYaw += yawChange;
        yawChange = (-currentRoll) & 0xFFF;
        currentPitch += pitchChange;
        *yaw = currentYaw;
        *(int*)(&D_80070328 + 0x60) = currentPitch;
        if (yawChange >= 0x801) yawChange -= 0x1000;
        if (yawChange < -0x40) yawChange = -0x40;
        if (yawChange >= 0x41) yawChange = 0x40;
        value = currentRoll + yawChange;
        *(int*)(&D_80070328 + 0x5C) = value;
    }
}

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

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((signed char *)(expr) + (offset)))
/* Retail source: USA Rev 0 SCUS-94467 PSX.EXE,
 * asm/nonmatchings/spyroupdate/func_800489CC.s, 0x800489CC..0x800491F4.
 * Raw timers, table indices, byte fields, and particle counter updates retain
 * their instruction units and run once per call from func_8003E83C.
 * Confidence: exact linked bytes; falsifiable via the full EXE hash gate. */
void *func_80050844(signed char *, int, int, int); /* extern */
void func_800509E8(void *);                      /* extern */
extern int D_8006C644;

extern void *spyroField2A4 asm("D_80070328+0x2A4");
void func_800489CC(void) {
    struct { Vector3D first; int reserved; Vector3D second; } frame;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_5;
    register int var_v0 asm("$2");
    register int var_v0_2 asm("$2");
    int var_v1;
    char *temp_s0;

    if (((unsigned char) M2C_FIELD(&g_CheatFlags, char *, 0) != 0) && (M2C_FIELD(&D_80070328, int *, 0x1CC) < 0x1E)) {
        M2C_FIELD(&D_80070328, int *, 0x1CC) = 0x1E;
    }
    if ((D_8006FA38 < 0) && (M2C_FIELD(&D_80070328, int *, 0xB8) == 0) && (M2C_FIELD(&D_80070328, int *, 8) > M2C_FIELD(&D_80070328, int *, 0xF8))) {
        M2C_FIELD(&D_80070328, int *, 0x1BC) = 0;
    }
    {
        register int *timerPtr asm("$3");
        register int ticks asm("$4");
        register int timerValue asm("$5");
        int remaining;
        timerPtr = (int *)(&D_80070328 + 0x1BC);
        remaining = *timerPtr;
        ticks = D_8006C648;
        remaining -= ticks;
        *timerPtr = remaining;
        if (remaining < 0) *timerPtr = 0;
        remaining = M2C_FIELD(&D_80070328, int *, 0x1CC) - ticks;
        M2C_FIELD(&D_80070328, int *, 0x1CC) = remaining;
        if (remaining < 0) M2C_FIELD(&D_80070328, int *, 0x1CC) = 0;
        timerValue = M2C_FIELD(&D_80070328, int *, 0x1D0);
        if (timerValue != 0 && M2C_FIELD(&D_80070328, int *, 0x170) == 6) {
            remaining = timerValue - ticks;
            M2C_FIELD(&D_80070328, int *, 0x1D0) = remaining;
            if (remaining <= 0) M2C_FIELD(&D_80070328, int *, 0x1D0) = 1;
        } else {
            temp_v0_4 = M2C_FIELD(&D_80070328, int *, 0x1D0) - D_8006C648;
            M2C_FIELD(&D_80070328, int *, 0x1D0) = temp_v0_4;
            if (temp_v0_4 < 0) M2C_FIELD(&D_80070328, int *, 0x1D0) = 0;
        }
    }
    if ((D_8006E344 == 1) || (D_8006E344 == 0xF)) {
        M2C_FIELD(&D_80070328, int *, 0x1BC) = 0;
        M2C_FIELD(&D_80070328, int *, 0x1CC) = 0;
        M2C_FIELD(&D_80070328, int *, 0x1D0) = 0;
    }
    {
        register int *counterPtr asm("$16");
        counterPtr = (int *)(&D_80070328 + 0x1C0);
        if (*counterPtr != 0) {
            if ((unsigned int)(M2C_FIELD(&D_80070328, int *, 0x50) - 7) < 2 || M2C_FIELD(&D_80070328, int *, 0x50) == 6 || M2C_FIELD(&D_80070328, int *, 0x1BC) == 0) {
                M2C_FIELD(&D_80070328, int *, 0x1C0) = 0;
            } else {
                if (M2C_FIELD(&D_80070328, int *, 0x50) == 5) goto reaction21;
                if (M2C_FIELD(&D_80070328, int *, 0x50) != 2) goto reaction6;
                if (M2C_FIELD(&D_80070328, int *, 0xA0) >= 0) goto counter_done;
reaction21:
                func_8004BEF8(0x21);
                *counterPtr = 0;
                goto counter_done;
reaction6:
                func_8004BEF8(6);
                M2C_FIELD(&D_80070328, int *, 0x144) = 1;
            }
        }
counter_done:;
    }
    if (M2C_FIELD(&D_80070328, int *, 0x1C8) != 0) {
        func_8004BEF8(0x3DU);
        M2C_FIELD(&D_80070328, int *, 0x4C) = 2;
    }
    M2C_FIELD(&D_80070328, int *, 0x1C8) = 0;
    if (D_8006FA38 >= 0) {
        if (M2C_FIELD(&D_80070328, int *, 0x1BC) < 0x1E) {
            M2C_FIELD(&D_80070328, int *, 0x1BC) = 0x1E;
        }
        M2C_FIELD(&D_80070328, int *, 0x1C4) = 1;
    }
    if (M2C_FIELD(&D_80070328, int *, 0x1CC) != 0) {
        if ((M2C_FIELD(&D_80070328, int *, 0x1CC) >= 0xB5) || ((M2C_FIELD(&D_80070328, int *, 0x1CC) != 0) && (M2C_FIELD(&D_80070328, int *, 0x1CC) & 0x10))) {
            M2C_FIELD(&D_80070328, char *, 0x20) = 0x90;
            M2C_FIELD(&D_80070328, char *, 0x21) = 0x20;
            M2C_FIELD(&D_80070328, char *, 0x22) = 0x10;
            M2C_FIELD(&D_80070328, char *, 0x23) = 0xD8;
        } else {
            goto block_63;
        }
    } else if ((M2C_FIELD(&D_80070328, int *, 0x1D4) != 0) || (M2C_FIELD(&D_80070328, int *, 0x170) == 8)) {
        var_v0 = D_8006C644;
        M2C_FIELD(&D_80070328, char *, 0x20) = 0x90;
        var_v0 = *(unsigned short *)((char *)D_80065920 + ((var_v0 * 4) & 0x1FC));
        M2C_FIELD(&D_80070328, char *, 0x22) = 0x10;
        M2C_FIELD(&D_80070328, char *, 0x23) = 0xD8;
        var_v0 = (short)var_v0 >> 5;
        __asm__ ("" : : "r"(var_v0));

        if (var_v0 < 0) {
            var_v0 = -var_v0;
        }
        M2C_FIELD(&D_80070328, char *, 0x21) = (char) (var_v0 + 0x20);
        func_80049484((int) &frame.first.x);
        frame.first.x += (rand() & 0x7E) - 0x3F;
        frame.first.y += (rand() & 0x7E) - 0x3F;
        temp_v0_5 = rand();
        frame.second.x = 8;
        frame.second.y = 0;
        frame.second.z = 0;
        frame.first.z -= temp_v0_5 & 0x3F;
        func_8004ED6C((SHORTMATRIX *) ((&D_80070328 + 0x1CC) - 0x19C), (Vector3D *) &frame.second.x, (Vector3D *) &frame.second.x);
        frame.second.z += 0x12;
        frame.second.x += (rand() & 0xE) - 7;
        frame.second.y += (rand() & 0xE) - 7;
        SpawnParticle(1, 0x16, (Vector3D *) &frame.first.x, (Vector3D *) &frame.second.x);
    } else if ((M2C_FIELD(&D_80070328, int *, 0x1D0) != 0) && (D_8006C5BC != 0x25)) {
        var_v1 = M2C_FIELD(&D_80070328, int *, 0x1D0) * 2;
        if (M2C_FIELD(&D_80070328, int *, 0x1D0) < 0xB4) {
            var_v1 += (0xB4 - M2C_FIELD(&D_80070328, int *, 0x1D0)) * 8;
        }
        M2C_FIELD(&D_80070328, char *, 0x20) = 0x90;
        __asm__ volatile("" : : : "memory");
        var_v0_2 = (unsigned short)D_80065920[var_v1 & 0xFF];
        M2C_FIELD(&D_80070328, char *, 0x22) = 0x10;
        M2C_FIELD(&D_80070328, char *, 0x23) = 0xD8;
        var_v0_2 = (short)var_v0_2 >> 5;
        __asm__ ("" : : "r"(var_v0_2));

        if (var_v0_2 < 0) {
            var_v0_2 = -var_v0_2;
        }
        M2C_FIELD(&D_80070328, char *, 0x21) = (char) (var_v0_2 + 0x20);
    } else if (M2C_FIELD(&g_CheatFlags, unsigned char *, 0x14) != 0) {
        switch (M2C_FIELD(&g_CheatFlags, unsigned char *, 0x14)) {
        case 1:
            M2C_FIELD(&D_80070328, char *, 0x20) = 0x90;
            M2C_FIELD(&D_80070328, char *, 0x21) = 0;
block_60:
            M2C_FIELD(&D_80070328, char *, 0x22) = 0;
            M2C_FIELD(&D_80070328, char *, 0x23) = 0xA0;
            break;
        case 2:
            M2C_FIELD(&D_80070328, char *, 0x20) = 0x18;
            M2C_FIELD(&D_80070328, char *, 0x21) = 0x30;
            M2C_FIELD(&D_80070328, char *, 0x22) = 0xA0;
            M2C_FIELD(&D_80070328, char *, 0x23) = 0xA0;
            break;
        case 3:
            M2C_FIELD(&D_80070328, char *, 0x20) = 0xFF;
            M2C_FIELD(&D_80070328, char *, 0x21) = 0x80;
            M2C_FIELD(&D_80070328, char *, 0x22) = 0x80;
            M2C_FIELD(&D_80070328, char *, 0x23) = 0xA0;
            break;
        case 4:
            M2C_FIELD(&D_80070328, char *, 0x20) = 0x10;
            M2C_FIELD(&D_80070328, char *, 0x21) = 0x90;
            M2C_FIELD(&D_80070328, char *, 0x22) = 0;

            M2C_FIELD(&D_80070328, char *, 0x23) = 0xA0;
            break;
        case 5:
            M2C_FIELD(&D_80070328, char *, 0x20) = 0xFF;
            M2C_FIELD(&D_80070328, char *, 0x21) = 0xFF;
            M2C_FIELD(&D_80070328, char *, 0x22) = 0x80;
            M2C_FIELD(&D_80070328, char *, 0x23) = 0xFF;
            break;
        case 6:
            M2C_FIELD(&D_80070328, char *, 0x20) = 0x18;
            M2C_FIELD(&D_80070328, char *, 0x21) = 0x18;
            M2C_FIELD(&D_80070328, char *, 0x22) = 0x18;
            M2C_FIELD(&D_80070328, char *, 0x23) = 0xFF;
            break;
        }
    } else {
block_63:
        M2C_FIELD(&D_80070328, char *, 0x23) = 0;
    }
    temp_s0 = &D_80070328 + 0x50;
    if ((M2C_FIELD(&D_80070328, int *, 0x50) == 6) && ((M2C_FIELD(&D_80070328, int *, 0x24C) == 0) || (M2C_FIELD(&D_80070328, int *, 0x48) == 0xAF))) {
        if (M2C_FIELD(&D_80070328, void **, 0x2A0) == 0) {
            M2C_FIELD(&D_80070328, void **, 0x2A0) = func_80050844(temp_s0 + 0x258, -3, 6, 0x303030);
        }
        if (spyroField2A4 == 0) {
            spyroField2A4 = func_80050844(temp_s0 + 0x264, -3, 6, 0x303030);
        }
        if (M2C_FIELD(&D_80070328, int *, 0x48) == 0x22) {
            if (M2C_FIELD(&D_80070328, void **, 0x2A0) != 0) {
                M2C_FIELD(M2C_FIELD(&D_80070328, void **, 0x2A0), unsigned char *, 0x65) = 3U;
            }
            if (spyroField2A4 != 0) {
                M2C_FIELD(spyroField2A4, unsigned char *, 0x65) = 3U;
            }
        } else {
            if (M2C_FIELD(&D_80070328, void **, 0x2A0) != 0) {
                M2C_FIELD(M2C_FIELD(&D_80070328, void **, 0x2A0), unsigned char *, 0x65) = (unsigned char) (M2C_FIELD(M2C_FIELD(&D_80070328, void **, 0x2A0), unsigned char *, 0x65) + 1);
                if ((unsigned char) M2C_FIELD(M2C_FIELD(&D_80070328, void **, 0x2A0), unsigned char *, 0x65) >= 7U) {
                    M2C_FIELD(M2C_FIELD(&D_80070328, void **, 0x2A0), unsigned char *, 0x65) = 6U;
                }
            }
            {
                register void *particle asm("$2");
                particle = spyroField2A4;

                if (particle != 0) {
                    M2C_FIELD(particle, unsigned char *, 0x65) = M2C_FIELD(particle, unsigned char *, 0x65) + 1;
                    if (M2C_FIELD(spyroField2A4, unsigned char *, 0x65) >= 7U) {
                        M2C_FIELD(spyroField2A4, unsigned char *, 0x65) = 6U;
                    }
                }
            }
        }
    } else {
        if (M2C_FIELD(&D_80070328, void **, 0x2A0) != 0) {
            func_800509E8(M2C_FIELD(&D_80070328, void **, 0x2A0));
            M2C_FIELD(&D_80070328, void **, 0x2A0) = 0;
        }
        if (spyroField2A4 != 0) {
            func_800509E8(spyroField2A4);
            spyroField2A4 = 0;
        }
    }
}

#undef M2C_FIELD


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

void func_800560AC(int, Vector3D*, unsigned char, unsigned char, int);
void func_8004F1FC(Vector3D*, Vector3D*, int);

/* Retail source: USA Rev 0 PSX.EXE 0x80049ACC..0x80049D70 (169 words).
 * Animation positions use packed signed 11-bit components and runtime vector
 * units; blend weights are unsigned bytes. One call samples one animation
 * frame, optionally blends the paired pose, and applies the retail transforms.
 * Confidence is confirmed by exact word and executable comparisons; falsify
 * with any mismatch in the cited address span. */
void func_80049ACC(int arg0, void* arg1) {
    Vector3D blendPosition;
    Vector3D primaryPosition;
    Vector3D secondaryPosition;
    register int frame __asm__("$16") = arg0;
    register Vector3D* output __asm__("$18");
    register int secondFrame __asm__("$17");
    register unsigned char* state __asm__("$19");
    register Vector3D* finalOffset __asm__("$6");
    register Vector3D* finalOutput __asm__("$4");
    register Vector3D* finalInput __asm__("$5");
    SpyroAnimRoot* root;
    int frameCount;
    int packed;

    root = D_8006C558[0];
    frameCount = *((unsigned char*)root + 2);
    output = arg1;
    __asm__ volatile ("" : "=r"(output) : "0"(output));
    if (frame < frameCount) {
        secondFrame = 0;
    } else {
        secondFrame = 1;
        frame -= frameCount;
    }

    {
        register int callFrame __asm__("$4") = frame;
        __asm__ volatile ("" : "=r"(callFrame) : "0"(callFrame));
        state = (unsigned char*)&D_80070328 + 0x14;
        __asm__ volatile ("" : "=r"(state) : "0"(state));
        __asm__ volatile ("sw %0, 16($sp)" : : "r"(secondFrame) : "memory");
        ((void (*)(int, Vector3D*, unsigned char, unsigned char))func_800560AC)(
            callFrame, output, state[0], state[2]);
    }
    if (D_80066530[state[8]] != 0) {
        func_800560AC(frame, &blendPosition,
                      *((unsigned char*)&D_80070328 + 0x15),
                      *((unsigned char*)&D_80070328 + 0x17), secondFrame);
        func_8004F1FC(output, output, 0x100 - D_80066530[state[8]]);
        func_8004F1FC(&blendPosition, &blendPosition, D_80066530[state[8]]);
        func_8004F194(output, output, &blendPosition);
        func_8004F110(output, 8);
    }

    if (secondFrame == 0) {
        func_8004ED6C((SHORTMATRIX*)(state + 0x1C), output, output);
        finalOutput = output;
        finalInput = finalOutput;
        __asm__ volatile ("" : "=r"(finalOutput), "=r"(finalInput)
                         : "0"(finalOutput), "1"(finalInput));
        finalOffset = (Vector3D*)(state - 0x14);
        goto add_final_offset;
    } else {
        packed = (int)D_8006C558[state[0]] + state[2] * 0x14;
        packed = *(int*)(packed + 0x1C);
        primaryPosition.x = packed >> 21;
        primaryPosition.y = (packed << 11) >> 21;
        {
            register unsigned int weightIndex __asm__("$7") = state[8];
        primaryPosition.z = (packed << 22) >> 21;
        if (D_80066530[weightIndex] != 0) {
            packed = (int)D_8006C558[
                *((unsigned char*)&D_80070328 + 0x15)] +
                *((unsigned char*)&D_80070328 + 0x17) * 0x14;
            packed = *(int*)(packed + 0x1C);
            secondaryPosition.x = packed >> 21;
            secondaryPosition.y = (packed << 11) >> 21;
            secondaryPosition.z = (packed << 22) >> 21;
            func_8004F1FC(&primaryPosition, &primaryPosition,
                          0x100 - D_80066530[weightIndex]);
            func_8004F1FC(&secondaryPosition, &secondaryPosition,
                          D_80066530[state[8]]);
            func_8004F194(&primaryPosition, &primaryPosition, &secondaryPosition);
            func_8004F110(&primaryPosition, 8);
        }
        }
        func_8004ED6C((SHORTMATRIX*)(state + 0x1C), &primaryPosition, &primaryPosition);
        func_8004ED6C((SHORTMATRIX*)(state + 0x18C), output, output);
        func_8004F194(output, output, (Vector3D*)(state - 0x14));
        finalOutput = output;
        finalInput = finalOutput;
        finalOffset = &primaryPosition;
        __asm__ volatile ("" : "=r"(finalOutput), "=r"(finalInput),
                           "=r"(finalOffset)
                         : "0"(finalOutput), "1"(finalInput),
                           "2"(finalOffset));
    }
add_final_offset:
    func_8004F194(finalOutput, finalInput, finalOffset);
}

// has overlay version in "animation.c"
INCLUDE_ASM("asm/nonmatchings/spyroupdate", func_80049D70);

// has overlay version in "animation.c"
/* Retail source: USA Rev 0 SCUS-94467,
 * asm/nonmatchings/spyroupdate/func_8004B324.s, 0x8004B324..0x8004BA6C.
 * Raw offsets and constants retain the instruction representation per call.
 * Exact linked function bytes and complete EXE/overlay hashes are the match gate. */
#define SPYRO_FIELD(expr, type_ptr, offset) (*(type_ptr)((signed char *)(expr) + (offset)))
extern unsigned char D_80067A08[];
extern int D_8006C708, D_8006C6D4;
void func_8004B324(void) {
    int var_a0;
    register int var_v0 asm("$2");
    register int temp_s0 asm("$16");

    if (SPYRO_FIELD(&D_80070328, int *, 0x20C) & 0x8000) {
        func_80041C20();
        if ((D_8006C5BC == 0x2C) && (SPYRO_FIELD(&D_80070328, int *, 0x24C) == 4) && (SPYRO_FIELD(&D_80070328, int *, 0x24) != 0) && (((int (*)(int))unk_ovlheader_8007431C)(1) != 0)) {
            D_8006C6D4 = 0xFF;
        }
    } else {
        if (SPYRO_FIELD(&D_80070328, int *, 0xB8) == 0) {
            SPYRO_FIELD(&D_80070328, int *, 0x120) = (int) SPYRO_FIELD(&D_80070328, int *, 0x10C);
        }
        switch (SPYRO_FIELD(&D_80070328, int *, 0x48)) {
        case 0:
        case 15:
            if (func_800438F4() == 0) {
                func_80043728();
            }
            func_80041C20();
            SPYRO_FIELD(&D_80070328, int *, 0xBC) = 0;
            goto block_56;
        case 1:
        case 2:
            func_800438F4();
            func_80041C20();
            func_80042A44();
            func_80041930();
            func_80043A38(0xC00);
            if (SPYRO_FIELD(&D_80070328, int *, 0xB4) != 0) {
                var_a0 = (int) (SPYRO_FIELD(&D_80070328, int *, 0xB4) * 0x15) >> 8;
            } else {
                var_a0 = SPYRO_FIELD(&D_80070328, int *, 0xA8) * 4;
            }
            if (var_a0 < 0x10) {
                var_a0 = 0x10;
            }
            if (var_a0 >= 0x61) {
                var_a0 = 0x60;
            }
            func_800443A4(var_a0);
block_21:
            SPYRO_FIELD(&D_80070328, int *, 0x28) = 0;
            break;
        case 3:
            func_800438F4();
            func_80041C20();
            func_80042A44();
            func_80041930();
            goto block_58;
        case 4:
            func_800438F4();
            func_80041C20();
            func_80042A44();
            func_80041930();
            func_80043A38(0xC00);
            if (SpawnParticle != 0) {
                SpawnParticle(1, 0x21, 0, 0);
            }
            goto block_21;
        case 5:
            func_800438F4();
            func_80041C20();
            func_80042A44();
            func_80041930();
            func_80043A38(0xC00);
            if (SpawnParticle != 0) {
                SpawnParticle(1, 0x21, 0, 0);
            __asm__ volatile("" : : : "memory");
            }
            goto block_21;
        case 6:
            func_80041C20();
            func_80042A44();
            func_80041930();
            if (SPYRO_FIELD(&D_80070328, int *, 0x50) == 0xD) {
                func_80042F64();
                if ((SPYRO_FIELD(&D_80070328, int *, 0xA0) < 0) && (SPYRO_FIELD(&D_80070328, int *, 0x54) >= 4)) {
                    SPYRO_FIELD(&D_80070328, int *, 0x4C) = (int) ((SPYRO_FIELD(&D_80070328, int *, 0x4C) & 0x80) | 1);
                    goto block_34;
                }
                if (!(SPYRO_FIELD(&D_80070328, int *, 0x4C) & 0x80)) {
                    if (!(D_8006E538 & 0x40)) {
                        { register int nextState asm("$2") = 2; __asm__("" : "=r"(nextState) : "0"(nextState)); SPYRO_FIELD(&D_80070328, int *, 0x4C) = nextState; }
                    }
block_34:
                    if (SPYRO_FIELD(&D_80070328, int *, 0x4C) & 0x80) {
                        goto block_35;
                    }
                } else {
block_35:
                    if (SPYRO_FIELD(&D_80070328, int *, 0x8) <= SPYRO_FIELD(&D_80070328, int *, 0x144)) {
                        SPYRO_FIELD(&D_80070328, int *, 0x4C) = (int) (SPYRO_FIELD(&D_80070328, int *, 0x4C) & ~0x80);
                    }
                }
            } else if ((SPYRO_FIELD(&D_80070328, int *, 0xA0) < 0) && (SPYRO_FIELD(&D_80070328, int *, 0x54) >= 4)) {
                if ((unsigned int) (SPYRO_FIELD(&D_80070328, int *, 0x4C) - 3) < 2U) {
                    SPYRO_FIELD(&D_80070328, int *, 0x4C) = 4;
                } else {
                    { register int nextState asm("$2") = 1; __asm__("" : "=r"(nextState) : "0"(nextState)); SPYRO_FIELD(&D_80070328, int *, 0x4C) = nextState; }
                }
            } else if ((SPYRO_FIELD(&D_80070328, int *, 0x4C) == 0) && !(D_8006E538 & 0x40) && (SPYRO_FIELD(&D_80070328, int *, 0x144) == 0)) {
                { register int nextState asm("$2") = 2; __asm__("" : "=r"(nextState) : "0"(nextState)); SPYRO_FIELD(&D_80070328, int *, 0x4C) = nextState; }
            }
            goto block_21;
        case 13:
            func_800438F4();
            func_80041C20();
            func_80042A44();
            if ((SPYRO_FIELD(&D_80070328, int *, 0xB8) != 0) && (SPYRO_FIELD(&D_80070328, int *, 0xBC) == 0)) {
                SPYRO_FIELD(&D_80070328, int *, 0xE4) = (int) (signed char)func_8004E880(SPYRO_FIELD(&D_80070328, int *, 0xC8), func_8004EDE8((Vector3D *)(&D_80070328 + 0xC0), 0), 0);
            }
            func_80043A38(0xC00);
            func_80049590();
            {
                register int tableOffset asm("$2");
                register unsigned char *soundTable asm("$3");
                tableOffset = SPYRO_FIELD(&D_80070328, int *, 0x10C);
                __asm__ ("" : "=r"(tableOffset) : "0"(tableOffset));
                temp_s0 = tableOffset >> 6;
                __asm__ volatile ("" : "=r"(temp_s0) : "0"(temp_s0));
                tableOffset = D_8006C58C << 2;
                soundTable = D_80067A08;
                SPYRO_FIELD(&D_80070328, int *, 0x28) = 0;
                tableOffset += (int)soundTable;
                tableOffset += temp_s0;
                temp_s0 = ((unsigned char *)D_8006C708)[*(unsigned char *)tableOffset];
            }
            if (temp_s0 != SPYRO_FIELD(&D_80070328, int *, 0x290)) {
                if (func_8003BF6C(SPYRO_FIELD(&D_80070328, int *, 0x290), SPYRO_FIELD(&D_80070328, int *, 0x28C)) != 0) {
                    func_8003BE70(SPYRO_FIELD(&D_80070328, int *, 0x28C));
                }
                SPYRO_FIELD(&D_80070328, int *, 0x28C) = -1;
            }
            SPYRO_FIELD(&D_80070328, int *, 0x290) = (int) temp_s0;
            if (func_8003BF6C((int) temp_s0, SPYRO_FIELD(&D_80070328, int *, 0x28C)) == 0) {
                SPYRO_FIELD(&D_80070328, int *, 0x28C) = PlaySound(SPYRO_FIELD(&D_80070328, int *, 0x290), 0, 4);
            }
            break;
        case 7:
        case 8:
        case 14:
        case 31:
            func_80041C20();
block_56:
            func_80042A44();
            goto block_21;
        case 16:
            func_80041C20();
            func_80042A44();
block_58:
            func_80043A38(0xC00);
            goto block_21;
        case 17:
        case 18:
        case 24:
            func_80041C20();
            func_80042A44();
            func_80041930();
            goto block_21;
        case 22:
            func_80041C20();
            func_80042A44();
            func_80041930();
            func_80049590();
            if ((SPYRO_FIELD(&D_80070328, int *, 0x50) == 9) && (SpawnParticle != 0)) {
                SpawnParticle(1, 9, 0, 0);
            }
            if ((SPYRO_FIELD(&D_80070328, int *, 0xA0) < 0) && (SPYRO_FIELD(&D_80070328, int *, 0x54) >= 4)) {
                SPYRO_FIELD(&D_80070328, int *, 0x4C) = 1;
            } else if ((SPYRO_FIELD(&D_80070328, int *, 0x4C) == 0) && !(D_8006E538 & 0x40)) {
                SPYRO_FIELD(&D_80070328, int *, 0x4C) = 2;
            }
            goto block_21;
        case 46:
            func_80041C20();
            func_80042A44();
            if (SPYRO_FIELD(&D_80070328, int *, 0x4C) == 1) {
                func_800494A8();
            }
            goto block_21;
        default:
            if (unk_ovlheader_800742F0 != 0) {
                unk_ovlheader_800742F0();
            }
            break;
        }
        if (SPYRO_FIELD(&D_80070328, int *, 0xB8) != 0) {
            SPYRO_FIELD(&D_80070328, int *, 0x10C) = (int) SPYRO_FIELD(&D_80070328, int *, 0x120);
        }
        SPYRO_FIELD(&D_80070328, unsigned char *, 0xFD) = 0;
    }
}

#undef SPYRO_FIELD


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
