#include "common.h"
#include "draw.h"

// drawutil
void func_800200A0(int, int, int, int);

// loading overlay functions
void func_loading_80075B74();
void func_loading_80076EE8();
void func_loading_80077964();

// credits overlay functions
void func_credits_80076118();

// Other
extern PauseData pauseData; // 8006fbc4

// sbss
extern int D_8006C514;
extern int D_8006C598;

/////////////////////////////////////////////////////////////

/**
 * ???() - func_8001D274() 
 * Near matching, incorrect struct usage and unnecessary variable usage though
 * https://decomp.me/scratch/pCaWp
 */
/* Retail source: asm/nonmatchings/draw/func_8001D274.s,
 * 0x8001D274..0x8001D424; draw-state update occurs once per call. */
extern int D_8006E038;
extern int D_8006D07C, D_8006D080, D_8006D084;
extern unsigned char D_8006E33C, D_8006E33D, D_8006E33E;
extern unsigned char D_8006FC15, D_8006FC16, D_8006FC17;
extern unsigned char D_8006FC89, D_8006FC8A, D_8006FC8B;
extern int D_8006C658, D_8006C7E4, D_8006C76C;
extern unsigned char D_80071438, D_8007143A, D_8007143B;
extern char* D_80069DE0[];
int func_8002EBB0(void*);
void func_8001FE48(int, int, int, int);
void DrawStringCentered(char*, int, int, int);
void func_8001D274(void) {
    if (D_8006E038 != 0) {
        int first = D_8006D07C;
        int base = D_8006E33C;
        int second = D_8006D080;
        int third = D_8006D084;
        int red = (base + (first >> 4)) >> 1;
        int green = (base + (second >> 4)) >> 1;
        int blue = (base + (third >> 4)) >> 1;
        D_8006FC15 = red;
        D_8006FC16 = green;
        D_8006FC17 = blue;
        D_8006FC89 = red;
        D_8006FC8A = green;
        D_8006FC8B = blue;
    } else {
        unsigned char red = D_8006E33C;
        unsigned char green = D_8006E33D;
        unsigned char blue = D_8006E33E;
        D_8006FC15 = red;
        D_8006FC16 = green;
        D_8006FC17 = blue;
        D_8006FC89 = red;
        D_8006FC8A = green;
        D_8006FC8B = blue;
    }
    func_8001E460(0x3D);
    if (D_8006C658 == 1) {
        int halfWidth;
        if (D_80071438 == 0 &&
            (D_8007143A != 0xFF || D_8007143B != 0xFF)) {
            D_8006C7E4 = 1;
        }
        halfWidth = func_8002EBB0(D_80069DE0[D_8006C76C]) >> 1;
        func_8001FE48(0xF9 - halfWidth, halfWidth + 0x104, 0x32, 0x3F);
        DrawStringCentered(D_80069DE0[D_8006C76C], 0x100, 0x34, 1);
    }
}

// Different in 1.1
/* Retail source: USA Rev 0 SCUS-94467, PSX.EXE 0x8001D424..0x8001DC5C.
 * Text positions are screen pixels; the offset/limit tables are signed 16-bit,
 * and the scroll counters and draw limits are signed 32-bit retail values.
 * Cadence: one draw invocation, with the retail scroll timer decremented here.
 * Falsifiable vectors: states 0/1/2/>=3, timer 24/60, marker IDs 1..5,
 * hidden string tag 0xFF, line-limit edges, and visible-row bounds 142/208.
 * Confidence: complete retail instruction and executable/overlay hash match.
 * Register constraints and assembler mode directives emit no instructions. */
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
void DrawStringRightAligned(char *, int, int, int);
void func_8001FABC(int);
void func_8001FB74(int, int, int, int);
void func_8001FC90(int, int, int, int);
void func_8001FD00(int, int, int, int);
int func_80028378(void *, int);
void func_800289C8(int, short, short);
void func_800291B8(int, int, int, int);
void func_8002E748(unsigned char *, int, int, int, int *);
extern short D_800666B4[];
extern short D_800666D8[];
extern char *D_80069DBC[];
extern char *D_80069DC0[];
extern unsigned char D_8006C3B0;
extern unsigned char D_8006C3B8;
extern unsigned char D_8006C3C0;
extern unsigned char D_8006C3C8;
extern unsigned char D_8006C3D0;
extern unsigned char D_8006C3D4;
extern int D_8006C51C;
extern unsigned char D_8006C53C;
extern short D_8006C544;
extern short D_8006C57C;
extern int D_8006C590;
extern void **D_8006C5A8;
extern unsigned char D_8006C5AC;
extern int D_8006C608;
extern int D_8006C644;
extern int D_8006C6A4;
extern int D_8006C6D8;
extern unsigned char D_8006C6E4;
extern char D_8006C6F0;
extern char D_8006C6F3;
extern short D_8006C6F4;
extern short D_8006C6F6;
extern int D_8006C6FC;
extern int D_8006C71C;
extern int D_8006C750;
extern int D_8006C788;
extern int D_8006C78C;
extern int D_8006C790;
extern unsigned char D_8006C7A4;
extern int D_8006C7BC;
extern int D_80070328;
extern unsigned char *D_80071390;
extern char *D_800713A8[];
extern short D_8007193A;

void func_8001D424(void) {
    struct { int limits[3]; int reserved[7]; } frame;
    register short *var_s2_4 asm("$18");
    register short *var_s3_2 asm("$19");
    register short *var_v1 asm("$3");
    register int var_s0 asm("$16");
    register int temp_a2 asm("$6");
    register int temp_a2_2 asm("$6");
    register int temp_s1 asm("$17");
    register int temp_s1_2 asm("$17");
    register int temp_s4 asm("$20");
    int temp_v0;
    int temp_v0_2;
    int loopLimit;
    register char *callStack asm("$29");
    register int textX asm("$5");
    register int totalLines asm("$3");
    register int remainingLines asm("$2");
    register int temp_v0_4 asm("$2");
    register int markerX asm("$5");
    register int var_a0 asm("$4");
    int var_a3;
    int var_a3_2;
    register int var_s0_2 asm("$16");
    register int var_s0_3 asm("$16");
    register int var_s0_4 asm("$16");
    register int var_s0_5 asm("$16");
    register int var_s0_6 asm("$16");
    register int var_s1 asm("$17");
    register int var_s1_3 asm("$17");
    register int var_s1_4 asm("$17");
    register int var_s2_3 asm("$18");
    register int var_s3 asm("$19");
    register int var_s4 asm("$20");
    int var_v0;
    int temp_v0_3;
    unsigned int temp_v1;
    register unsigned char **var_s1_2 asm("$17");
    register unsigned char **var_s2_2 asm("$18");
    register unsigned char *var_s2 asm("$18");

    if (D_8006C790 < 3) {
        var_s0 = 0x400;
        if (D_8006C790 == 0) {
            temp_v1 = D_8006C78C - 0x18;
            if (temp_v1 < 0x24U) {
                var_s0 = D_800666B4[(int)temp_v1 >> 1];
            } else {
                if (D_8006C78C < 0x3C) {
                    goto block_5;
                }
                goto block_6;
            }
        } else {
block_5:
            if (D_8006C790 == 1) {
block_6:
                var_s0 = 0;
            } else if (D_8006C790 == 2) {
                var_s0 = D_800666D8[D_8006C78C >> 1];
            }
        }
        if (var_s0 != 0x400) {
            func_8001FD00(var_s0 + 0x18, var_s0 + 0x1E8, 0x92, 0xD4);
            if (D_8006C7A4 != 0) {
                var_s2 = &D_8006C3B0;
                if (M2C_FIELD(&D_80070328, int *, 0x24C) == 1) {
                    var_s2 = &D_8006C3B8;
                } else if ((M2C_FIELD(&D_80070328, int *, 0x24C) == 2) || (M2C_FIELD(&D_80070328, int *, 0x24C) == 5)) {
                    var_s2 = &D_8006C3C0;
                } else if (M2C_FIELD(&D_80070328, int *, 0x24C) == 3) {
                    var_s2 = "Sgt. Byrd";
                } else if (M2C_FIELD(&D_80070328, int *, 0x24C) == 4) {
                    var_s2 = &D_8006C3C8;
                }
                { register int value asm("$2") = D_8006C590;
                  __asm__("" : "=r"(value) : "0"(value)); var_s3 = value == 0; }
            } else {
                { register void *actor asm("$2") = D_8006C5A8;
                  register int value asm("$3");
                  __asm__("" : "=r"(actor) : "0"(actor) : "memory");
                  value = D_8006C590;
                  actor = *(void **)actor;
                  var_s3 = value != 0;
                  var_s2 = M2C_FIELD(actor, unsigned char **, 0xC); }
            }
            if ((D_8006C7A4 != 0) || (*var_s2 != 0xFF)) {
                temp_s1 = func_8002EBB0(var_s2);
                if (var_s3 != 0) {
                    { register int edge asm("$2") = var_s0 + 0x1CC;
                      __asm__("" : "=r"(edge) : "0"(edge)); var_s0_2 = edge - temp_s1; }
                } else {
                    var_s0_2 = var_s0 + 0x28;
                }
                func_8001FABC(0x18);
                var_a0 = var_s0_2;
                __asm__("" : "=r"(var_a0) : "0"(var_a0));
                temp_s1_2 = var_s0_2 + temp_s1;
                func_8001FC90(var_a0, temp_s1_2 + 0xE, 0x86, 0x92);
                func_8001FC90(var_s0_2 + 1, temp_s1_2 + 0xD, 0x85, 0x86);
                func_8001FC90(var_s0_2 + 4, temp_s1_2 + 0xA, 0x84, 0x85);
                var_a0 = var_s0_2 + 0x18;
                if (D_8006C790 != 1) {
                    if ((D_8006C790 == 0) && (D_8006C78C >= 0x3C)) {
                        __asm__("" : "=r"(var_s0_2) : "0"(var_s0_2));
                        var_a0 = var_s0_2 + 0x18;
                        goto block_32;
                    }
                } else {
block_32:
                    func_8001FB74(var_a0, 0x91, temp_s1_2 - 0xA, 0x91);
                    func_8002E748(var_s2, var_s0_2 + 8, 0x86, 0, 0);
                }
            }
        }
    }
    if (D_8006C790 == 1) {
        if (D_8006C7A4 != 0) {
            frame.limits[0] = 0;
            frame.limits[1] = 9;
            if (D_8006C53C != 0) {
                var_s0_3 = 0;
                if (D_8006C544 > 0) {
                    register int x asm("$5");
                    register int color asm("$7");
                    register short *baseA asm("$19") = &D_8007193A;
                    register short *baseB asm("$20") = baseA - 1;
                    var_s2_2 = &D_80071390;
                    var_s1 = 0x98;
                    do {
                        x = 0x28;
                        __asm__("" : "=r"(x) : "0"(x));
                        temp_a2 = var_s1;
                        temp_v0 = D_8006C6A4;
                        __asm__ volatile("" : : : "$7", "memory");
                        color = 4;
                        __asm__("" : : "r"(color));
                        temp_v0 += var_s0_3;
                        frame.limits[2] = baseA[temp_v0] - baseB[temp_v0];
                        __asm__("" : "=r"(var_s1) : "0"(var_s1));
                        var_s1 += 12;
                        var_s0_3 += 1;
                        func_8002E748(*var_s2_2, x, temp_a2, color, &frame.limits[0]);
                        var_s2_2 += 1;
                    } while (var_s0_3 < D_8006C544);
                }
            } else {
                totalLines = D_8006C544;
                remainingLines = D_8006C6E4;
                var_s0_4 = 0;
                temp_s4 = totalLines - remainingLines;
                if (totalLines > 0) {
                    register int *limits asm("$19");
                    register short *baseA asm("$21") = &D_8007193A;
                    register short *baseB asm("$22") = baseA - 1;
                    limits = frame.limits;
                    var_s2_3 = 0x98;
                    var_s1_2 = &D_80071390;
                    do {
                        temp_v0_2 = D_8006C6A4 + var_s0_4;
                        frame.limits[2] = baseA[temp_v0_2] - baseB[temp_v0_2];
                        if (var_s0_4 < temp_s4) {
                            func_8002E748(*var_s1_2, 0x31, var_s2_3, 0, limits);
                        } else {
                            var_a3 = 0;
                            if ((D_8006C78C & 0x1F) < 0x10) {
                                var_a3 = var_s0_4 == (temp_s4 + D_8006C57C);
                            }
                            func_8002E748(*var_s1_2, 0x48, var_s2_3, var_a3, limits);
                        }
                        var_s2_3 += 12;
                        __asm__("" : : "r"(var_s0_4));
                        loopLimit = D_8006C544;
                        __asm__("" : "=r"(var_s0_4) : "0"(var_s0_4) : "memory");
                        var_s0_4 += 1;
                        var_s1_2 += 1;
                    } while (var_s0_4 < loopLimit);
                }
                { register int index asm("$2") = temp_s4 + D_8006C57C;
                  __asm__("" : "=r"(index) : "0"(index));
                  func_8002E748(&D_8006C3D0, 0x3C, index * 12 + 0x98, 1, 0); }
            }
            if (D_8006C750 != 0) {
                DrawStringRightAligned(D_80069DBC[D_8006C76C], 0x14A, 0xC4, 1);
                temp_v0_3 = func_80028378(&D_8006C6F0, 0);
                D_8006C6F3 = temp_v0_3;
                func_800289C8(D_8006C788 + ((temp_v0_3 & 0xFF) * 8), D_8006C6F4, D_8006C6F6);
                func_800291B8(D_8006C71C, 0x178, 0xC6, 0);
            }
        } else {
            temp_v0_4 = D_8006C6A4 - 1;
            var_s0_5 = 0;
            if (temp_v0_4 > 0) {
                register int threshold asm("$5") = D_8006C51C;
                register int scanLimit asm("$4") = temp_v0_4;
                var_v1 = &D_8007193A;
loop_54:
                if (*var_v1 < threshold) {
                    var_s0_5 += 1;
                    var_v1 += 1;
                    if (var_s0_5 < scanLimit) {
                        goto loop_54;
                    }
                }
            }
            temp_a2_2 = D_8006C7BC;
            if (temp_a2_2 != 0) {
                D_8006C7BC = temp_a2_2 - 1;
                var_s1_3 = temp_a2_2 + 0xC5;
            } else if (var_s0_5 < 5) {
                { register int y asm("$2") = var_s0_5 * 12;
                  __asm__("" : "=r"(y) : "0"(y)); var_s1_3 = y + 0x96; }
            } else {
                /* Preserve the retail assembler's li-in-branch-delay slot;
                 * these directives do not emit instructions. */
                __asm__(".set\tnoreorder");
                if (D_8006C6FC < var_s0_5) {
                    D_8006C7BC = 0xB;
                }
                __asm__(".set\treorder");
                { register int y asm("$2") = D_8006C7BC;
                  __asm__("" : "=r"(y) : "0"(y)); var_s1_3 = y + 0xC6; }
            }
            D_8006C6FC = var_s0_5;
            var_s4 = var_s0_5 - 5;
            var_v0 = var_s0_5 < var_s4;
            if (var_s4 < 0) {
                var_s4 = 0;
                __asm__("" : "=r"(var_s4) : "0"(var_s4));
                var_v0 = var_s0_5 < var_s4;
            }
            if (var_v0 == 0) {
                { register int indexBytes asm("$2") = var_s0_5 * 2;
                  register short *base asm("$4");
                  register short *prior asm("$3");
                  __asm__("" : "=r"(indexBytes) : "0"(indexBytes));
                  base = &D_8007193A;
                  prior = base - 1;
                  __asm__("" : "=r"(base), "=r"(prior) : "0"(base), "1"(prior));
                  var_s3_2 = (short *)(indexBytes + (int)prior);
                  var_s2_4 = (short *)(indexBytes + (int)base); }
                do {
                    if ((unsigned int) (var_s1_3 - 0x8E) < 0x42U) {
                        frame.limits[0] = 0;
                        frame.limits[1] = 9;
                        frame.limits[2] = *var_s2_4 - *var_s3_2;
                        if (var_s1_3 < 0x96) {
                            frame.limits[0] = 0x96 - var_s1_3;
                        }
                        if (var_s1_3 >= 0xC8) {
                            frame.limits[1] = 0xD0 - var_s1_3;
                        }
                        textX = 0x28;
                        if (D_8006C51C < *var_s2_4) {
                            frame.limits[2] = D_8006C51C - *var_s3_2;
                        }
                        /* The retail caller writes the fifth o32 argument at
                         * sp+0x10 before resolving the indexed text pointer.
                         * Keep that ABI store explicit to retain its order. */
                        { register int screenY asm("$6") = var_s1_3;
                          register int *drawLimits asm("$2");
                          __asm__("" : "=r"(screenY) : "0"(screenY));
                          drawLimits = frame.limits;
                          __asm__("" : "=r"(drawLimits) : "0"(drawLimits));
                          *(int **)(callStack + 16) = drawLimits;
                          __asm__ volatile("" : : : "$2", "memory");
                        { register int offset asm("$2") = var_s0_5 * 4;
                          __asm__("" : "=r"(offset) : "0"(offset));
                          ((void (*)())func_8002E748)(*(char **)((char *)D_800713A8 + offset), textX, screenY, 0); } }
                    }
                    var_s3_2 -= 1;
                    var_s2_4 -= 1;
                    var_s0_5 -= 1;
                    var_s1_3 -= 0xC;
                } while (var_s0_5 >= var_s4);
            }
            if (((D_8006C6D8 != 0) || (D_8006C5AC != 0)) && ((D_8006C644 & 0x1F) < 0x10)) {
                func_8002E748(&D_8006C3D0, 0x1DA, 0xC8, 0, 0);
            }
        }
        if (D_8006C608 != 0) {
            if (D_8006C53C != 0) {
                markerX = 0x17C;
                if (D_8006C7A4 != 0) goto dialogue_markers;
                goto dialogue_done;
            } else {
                markerX = 0x17C;
                if (D_8006C5AC == 0) goto dialogue_done;
            }
dialogue_markers:
            {
                register unsigned char *marker asm("$18");
                register int markerIndex asm("$2");
                register int markerY asm("$6") = 0xC8;
                register int markerColor asm("$7") = 0;
                __asm__("" : "=r"(markerY), "=r"(markerColor) : "0"(markerY), "1"(markerColor) : "$18");
                var_s0_6 = 0;
                __asm__("" : "=r"(var_s0_6) : "0"(var_s0_6) : "$18");
                markerIndex = D_8006C76C;
                __asm__ volatile("" : : : "$18", "memory");
                marker = &D_8006C3D4;
                __asm__("" : "=r"(marker) : "0"(marker) : "memory");
                DrawStringRightAligned(D_80069DC0[markerIndex], markerX, markerY, markerColor);
                var_s1_4 = 0x186;
                do {
                    var_a3_2 = 7;
                    if (var_s0_6 < D_8006C608) var_a3_2 = 6;
                    func_8002E748(marker, var_s1_4, 0xC8, var_a3_2, 0);
                    var_s0_6 += 1;
                    var_s1_4 += 0xE;
                } while (var_s0_6 < 5);
            }
        }
    }
dialogue_done:
    func_8001E460(0x3D);
}

#undef M2C_FIELD

void func_8001DC3C() {
    func_8001E460(0x3D);
}

/* Retail source: 0x8001DC5C..0x8001DD1C. Dispatch by pause state;
 * the draw-state bytes are cleared only for states 1 and 2. */
extern unsigned char D_8006FC15, D_8006FC16, D_8006FC17;
extern unsigned char D_8006FC89, D_8006FC8A, D_8006FC8B;
void func_8001EBAC(void);
void func_8001DC5C(void) {
    switch (pauseData.dat_8006fbc8) {
    case 0:
    case 4:
        if (D_8006C598 == 0xFF) func_8001EBAC();
        func_8001E460(0x3D);
        break;
    case 1:
    case 2:
        D_8006FC15 = 0;
        D_8006FC16 = 0;
        D_8006FC17 = 0;
        D_8006FC89 = 0;
        D_8006FC8A = 0;
        D_8006FC8B = 0;
        break;
    case 3:
        func_800200A0(2, D_8006C598, D_8006C598, D_8006C598);
        break;
    }
}

/* USA Rev 0 retail executable, 0x8001DD1C..0x8001E2A8.
 * 1420 bytes (355 instructions); .text SHA-256:
 * 80aaf361d8a6923e5bfcf220e525d41353bf67ba846b2ac156120645c5fff4dd.
 * Called once per draw dispatch; switch state and framebuffer mutations are
 * reproduced instruction-for-instruction. Confidence: confirmed by object
 * byte comparison. Test vector: build this TU and compare the full range. */
static const char D_8001025C[] = "Type: %d   Msg: %d";
extern unsigned char *speechData[];
extern unsigned char g_CheatFlags;
extern unsigned char *D_8006C600;
extern unsigned char *D_8006C65C;
extern signed int D_8006C664, D_8006C668, D_8006C7DC;
extern signed int D_8006FBC8, D_8006FBD4, D_8006FBF8;
extern unsigned char D_8006FBFC[], D_8006FBFE[];
extern signed char D_8006FC12;
extern unsigned char D_8006FC14[];
extern signed char D_8006FC86, D_8006FC88;
extern signed int D_8006FCE0;
extern unsigned char D_80070134;
extern signed int D_80070148;
extern signed short D_8007014C;
extern unsigned char D_8007014E;
extern signed int D_800722D0, D_800722D4;
extern int sprintf(char *, const char *, ...);
void func_80020790(void);
void func_80020D70(int);
void func_80058408();
void func_atlas_8007839C(void);
void func_options_80075A38(void);

void func_8001DD1C(void) {
    signed short sp2E;
    signed short sp2C;
    signed short sp2A;
    signed short sp28;
    signed char sp10[24];
    void *var_a0;
    signed int temp_v0;
    signed int temp_v0_2;
    signed int temp_v0_3;
    signed int temp_v0_4;
    signed int temp_v1_2;
    unsigned char temp_s0;
    unsigned char temp_s1;
    register unsigned char *temp_v1 asm("$3");
    unsigned char *drawPtr;
    register void *nullArg asm("$4");
    register signed int rectValue asm("$3");

    D_8006FBF8 = 0;
    if (((unsigned char *)&g_CheatFlags)[0x17] != 0) {
        temp_v1 = (unsigned char *)(
            (signed int)(((unsigned char *)&g_CheatFlags)[0x17] * 0xC) -
            -(signed int)(unsigned char *)speechData[D_8006C76C]);
        sprintf(sp10, D_8001025C, temp_v1[-0xC], temp_v1[-0xB]);
        DrawStringCentered(sp10, 0x100, 0xB8, 2);
    }
    switch (D_8006FBC8) {
    case 13: {
        register unsigned char *fcBase asm("$4");
        register signed int workV0 asm("$2");
        register signed int workV1 asm("$3");
        register signed int workA1 asm("$5");
        register signed int workA2 asm("$6");
        register signed int workA3 asm("$7");
        register signed int workT0 asm("$8");
        if (D_8006FBD4 == 0) {
            DrawSync(0);
            fcBase = D_8006FC14;
            __asm__ volatile ("" : "=r" (fcBase) : "0" (fcBase));
            workV1 = D_800722D4;
            workV0 = 1;
            fcBase[0] = workV0;
            D_8006FC88 = workV0;
            D_8006FC12 = workV0;
            D_8006FC86 = workV0;
            workV0 = (signed int)D_8006C600;
            workA1 = D_800722D0;
            workA2 = D_8006E33C;
            workA3 = D_8006E33D;
            workT0 = D_8006E33E;
            D_8006FCE0 = workV1;
            workV0 = *(signed int *)(workV0 + 0x70);
            workV1 -= workA1;
            D_8006C7DC = workV1;
            D_8006FC15 = workA2;
            D_8006FC16 = workA3;
            D_8006FC17 = workT0;
            fcBase[0x75] = workA2;
            fcBase[0x76] = workA3;
            fcBase[0x77] = workT0;
            D_8006C664 = workV0;
            workV0 += workV1;
            D_8006C668 = workV0;
        }
    } /* fallthrough */
    case 0:
    case 15:
        if ((D_8007014E == 0) && (D_80070148 != 3)) {
            func_80020D70(0);
        }
block_9:
        if (D_8006C65C == ((void *)0)) {
            goto block_32;
        }
        drawPtr = D_8006C65C;
        __asm__ volatile ("" : : "r" (drawPtr));
        goto block_18;
    case 1:
    case 6:
    case 8:
        goto block_32;
    case 3:
        if ((D_8007014E == 0) && (D_80070148 != 3)) {
            func_80020790();
        }
        goto block_9;
    case 21:
        if (D_8006FBD4 != 0) {
            goto block_19;
        }
        if (D_80070148 != 2) {
            func_80020D70(0);
        }
        drawPtr = D_8006C65C;
        if (drawPtr == ((void *)0)) {
            goto block_32;
        }
block_18:
        temp_s0 = drawPtr[0x4D];
        temp_s1 = drawPtr[0x4C];
        drawPtr[0x4D] = 0U;
        D_8006C65C[0x4C] = 0U;
        func_8001E460(0x3D);
        D_8006C65C[0x4D] = temp_s0;
        D_8006C65C[0x4C] = temp_s1;
        return;
block_19:
        if (D_8006FBD4 == 1) {
            func_8001E460(0x1D);
            if (D_8006C600 == D_8006FBFC) {
                D_8007014C = 0;
                return;
            }
            D_8007014C = 1;
            return;
        }
        nullArg = ((void *)0);
        if (D_8006FBD4 != 2) {
            goto block_28;
        }
        temp_v0_2 = D_8007014C * 0x74;
        rectValue = *(unsigned short *)(D_8006FBFC + temp_v0_2);
        rectValue += 0x80;
        *(signed short *)((unsigned char *)&sp28 + 0) = rectValue;
        rectValue = *(unsigned short *)(D_8006FBFE + temp_v0_2);
        *(signed short *)((unsigned char *)&sp28 + 4) = 0x100;
        *(signed short *)((unsigned char *)&sp28 + 6) = 0x80;
        rectValue += 0x35;
        *(signed short *)((unsigned char *)&sp28 + 2) = rectValue;
        DrawSync(0);
        MoveImage(&sp28, 0x200, 0);
        DrawSync(0);
        var_a0 = (void *)D_8006FBFC;
        if (D_8006C600 == D_8006FBFC) {
            var_a0 = (void *)(D_8006FBFC + 0x74);
        }
        D_80070134 = 1;
        D_8006FC14[0] = 0;
        D_8006FC88 = 0;
        D_8006FC12 = 0;
        D_8006FC86 = 0;
        D_8006FCE0 = D_800722D0 + 0x8000;
        temp_v0_3 = *(signed int *)((unsigned char *)var_a0 + 0x70);
        D_8006C600 = var_a0;
        D_8006C7DC = 0x8000;
        D_8006C664 = temp_v0_3;
        D_8006C668 = temp_v0_3 + 0x8000;
        func_80058408(var_a0);
        temp_v0 = D_80070148;
        __asm__ volatile ("" : : "r" (temp_v0));
        if (temp_v0 != 2) {
            goto block_35;
        }
        return;
block_28:
        func_80058408(nullArg);
        if (D_80070148 != 2) {
            goto block_35;
        }
        return;
    case 16:
        if (D_8006FBD4 == 0) {
            DrawSync(0);
            D_8006FC14[0] = 0;
            D_8006FC88 = 0;
            D_8006FCE0 = D_800722D0 + 0x8000;
            temp_v0_4 = *(signed int *)(D_8006C600 + 0x70);
            D_8006C7DC = 0x8000;
            D_8006C664 = temp_v0_4;
            D_8006C668 = temp_v0_4 + 0x8000;
        }
        goto block_38;
block_32:
        func_8001E460(0x3D);
        return;
    case 17: {
        register unsigned char *fcBase2 asm("$3");
        DrawSync(0);
        fcBase2 = D_8006FC14;
        __asm__ volatile ("" : "=r" (fcBase2) : "0" (fcBase2));
        fcBase2[0] = 1;
        D_8006FC88 = 1;
        D_8006FC15 = 0;
        D_8006FC16 = 0;
        D_8006FC17 = 0;
        fcBase2[0x75] = 0U;
        fcBase2[0x76] = 0U;
        fcBase2[0x77] = 0U;
        return;
    }
    case 20:
    case 22:
    case 23:
    case 24:
        func_80058408();
        if (D_80070148 == 2) {
            break;
        }
block_35:
        func_80020D70(0);
        return;
    case 18:
        if (D_8006FBD4 == 0) {
            DrawSync(0);
            D_8006FC14[0] = 0;
            D_8006FC88 = 0;
        }
block_38:
        func_800200A0(2, 0x20, 0x20, 0x20);
        return;
    case 19:
        if (D_8006C76C == 0) {
            func_atlas_8007839C();
            return;
        }
        break;
    case 25:
        func_options_80075A38();
        break;
    }
}

/**
 * ???() - func_8001E2A8() - MATCHING
 * https://decomp.me/scratch/Don2Z
 */
void func_8001E2A8() {
    func_8001E460(0x1D);
}

/**
 * ???() - func_8001E2C8() - MATCHING
 * https://decomp.me/scratch/Ded5J
 */
void func_8001E2C8() {
    switch (pauseData.dat_8006fbc8) {
    case 0:
    case 5:
        func_8001E460(0xD);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        func_loading_80075B74();
        break;
    }
}

/**
 * ???() - func_8001E32C() - MATCHING
 * https://decomp.me/scratch/6HI31
 */
void func_8001E32C() {
    if (pauseData.dat_8006fbc8 == 0) {
        func_8001E460(0x3D);
        return;
    }
    if (pauseData.dat_8006fbc8 < 3) {
        func_loading_80076EE8();
    }
}

/**
 * ???() - func_8001E374() - MATCHING
 * https://decomp.me/scratch/V7eXK
 */
void func_8001E374() {
    func_credits_80076118();
}

/**
 * ???() - func_8001E394() - MATCHING
 * https://decomp.me/scratch/Szw3a
 */
void func_8001E394() {
    switch (pauseData.dat_8006fbc8) {
    case 0:
    case 5:
        func_8001E460(0x3D);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        func_loading_80077964();
        break;
    }
}

/**
 * ???() - func_8001E3F8() - MATCHING
 * https://decomp.me/scratch/qdEH2
 */
void func_8001E3F8() {
    switch (D_8006C514) {
    case 0:
    case 1:
    case 8:
    case 9:
        func_8001E460(0x3D);
        break;
    default:
        func_800200A0(2, D_8006C598, D_8006C598, D_8006C598);
        break;
    }
}

/**
 * ???() - func_8001E460() - MATCHING
 * Ready to add
 * https://decomp.me/scratch/k2213
 */
typedef struct { int unk0, unk4, unk8, unkC, unk10; } DrawTracerEntry;
extern DrawTracerEntry D_80070260[8];
extern int D_8006C5B8, D_8006C6D4, D_8006C7C0;
void func_8001C368();
void func_8001EC24();
void func_8001EC5C();
void func_8001EDEC();
void func_8001FF44();
void func_80029E48();
void func_8002A580();
void func_8002ECA8();
void func_8002F098();
void func_8002F5B4();
void func_8002FB68();
void func_8002FEE0(DrawTracerEntry*);
void func_8003AA38();
void func_8001E460(int arg0) {
    int i;
    if (arg0 & 1) func_8001EC5C();
    func_8002A580();
    if (arg0 & 4) func_8001EC24();
    if (arg0 & 0x10) {
        func_8002ECA8();
        func_8002F098();
        func_8002F5B4();
        func_8002FB68();
        for (i = 0; i < 8; i++)
            if (D_80070260[i].unk0 != 0) func_8002FEE0(&D_80070260[i]);
    }
    if (arg0 & 0x20) func_80029E48();
    if (arg0 & 8) {
        if (D_8006C5B8 != 0) func_8001C368();
        func_8001EDEC();
    }
    if (arg0 & 0x10) func_8003AA38();
    if (D_8006C598 != 0) func_800200A0(2, D_8006C598, D_8006C598, D_8006C598);
    if (D_8006C7C0 != 0) func_800200A0(1, D_8006C7C0, D_8006C7C0, D_8006C7C0);
    if (D_8006C6D4 != 0) {
        func_800200A0(1, D_8006C6D4, 0, 0);
        D_8006C6D4 -= 0x20;
        MIN(D_8006C6D4, 0);
    }
    func_8001FF44();
}

/**
 * ???() - func_8001E618() - MATCHING
 * https://decomp.me/scratch/6OYTK
 */
void func_8001E618() {
    func_8001E460(0x3D);
}

/* USA Rev 0 (SCUS-94467) retail executable, 0x8001E638..0x8001EBAC.
 * This once-per-frame dispatcher selects the draw route, waits for the retail
 * VSync cadence, swaps display/draw environments, and submits the ordering
 * table. Pointer deltas are byte counts in the retail packet buffers.
 * Confidence: confirmed by all 349 instructions, including their relocation targets in the
 * 0x574-byte object range. Falsifiable vectors: modes 4 and 13 exercise the
 * temporary packet-buffer routes; every other mode takes the normal route. */
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef s32 M2C_UNK;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((char *)(expr)+(offset)))

s32 VSync(M2C_UNK);
M2C_UNK func_80030478();
M2C_UNK func_80031124();
M2C_UNK func_8003CDA0();
s32 func_8004E664(M2C_UNK);
M2C_UNK func_8004E7AC(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_8004F178(void *, void *);
M2C_UNK func_8004F6C4(M2C_UNK *, void *, void *, s32);
M2C_UNK func_80059038();
M2C_UNK func_title_80077CFC();
extern s32 D_8006C4F8;
extern u8 *D_8006C550;
extern s32 D_8006C5D4;
extern s32 D_8006C5D8;
extern s32 D_8006C634;
extern s32 D_8006C678;
extern s32 *D_8006C6B0;
extern s32 D_8006C718;
extern s32 D_8006C7D4;
extern s32 D_8006C7E8;
extern char D_8006E03C;
extern s32 D_8006E048;
extern u32 D_8006E344;
extern s32 D_8006FC6C;
extern M2C_UNK (*unk_ovlheader_80074380)();
extern M2C_UNK (*unk_ovlheader_80074488)();

void Draw(void) {
    register s32 *temp_s1 asm("$17");
    register s32 temp_s0 asm("$16");
    register s32 temp_s2 asm("$18");
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_a0;
    s32 var_v1_2;
    s32 var_v1_3;
    u8 *temp_s3;
    u8 *var_v1;
    u8 temp_s4;
    s32 previousSync;
    register s32 *syncInit asm("$4");
    register s32 *syncState asm("$16");

    if (D_8006C718 == 0) {
        var_v1 = D_8006FBFC;
        if (D_8006C600 == D_8006FBFC) {
            var_v1 = D_8006FBFC + 0x74;
        }
        {
            register s32 drawStart asm("$2") = D_8006C634 + 0x1000;
            D_8006C600 = var_v1;
            temp_v1 = M2C_FIELD(var_v1, s32 *, 0x70);
            D_8006C664 = temp_v1;
            D_8006C7D4 = drawStart;
            D_8006C668 = temp_v1 + D_8006C7DC;
        }
        func_8004F6C4(&D_8006E03C, &D_8006E03C - 0x30, &D_8006E03C - 0x44, D_8006C7DC);
        func_8004F178(&D_8006E03C - 0x10, &D_8006E03C - 0x1C);
        switch (D_8006E344) {                       /* switch 1 */
        case 1:                                     /* switch 1 */
            func_8001D424();
            break;
        case 15:                                    /* switch 1 */
            func_8001DC3C();
            break;
        case 2:                                     /* switch 1 */
            if (D_8006E048 > 0) {
                unk_ovlheader_80074380();
                var_a0 = 0xC;
                goto block_22;
            } else {
            case 0:                                 /* switch 1 */
            case 14:                                /* switch 1 */
                func_8001D274();
            }
            break;
        case 3:                                     /* switch 1 */
            func_8001DC5C();
            break;
        case 4:                                     /* switch 1 */
            func_8001DD1C();
            break;
        case 5:                                     /* switch 1 */
            func_80059038();
            break;
        case 6:                                     /* switch 1 */
            func_8001E2A8();
            break;
        case 7:                                     /* switch 1 */
            func_8001E2C8();
            break;
        case 9:                                     /* switch 1 */
            func_8001E32C();
            break;
        case 10:                                    /* switch 1 */
            func_8001E374();
            break;
        case 11:                                    /* switch 1 */
            func_title_80077CFC();
            break;
        case 12:                                    /* switch 1 */
            func_8001E394();
            break;
        case 13:                                    /* switch 1 */
            func_8001E3F8();
            break;
        case 16:                                    /* switch 1 */
            func_8001E618();
            break;
        case 18:                                    /* switch 1 */
            unk_ovlheader_80074488();
            var_a0 = 0x3D;
            goto block_22;
        }
        goto block_23;
block_22:
        func_8001E460(var_a0);
block_23:
        D_8006C7E8 = D_8006C668 - D_8006C664;
        DrawSync(0);
        if (D_8006E344 != 9) {
            if (D_8006C678 != 0) {
                VSync(0);
            }
            temp_v0 = VSync(-1);
            previousSync = D_8006C5D4;
            syncInit = &D_8006C5D8;
            *syncInit = temp_v0;
            if ((temp_v0 - previousSync) < 2) {
                syncState = syncInit;
loop_27:
                VSync(0);
                temp_v0_2 = VSync(-1);
                *syncState = temp_v0_2;
                if ((temp_v0_2 - syncState[-1]) < 2) {
                    goto loop_27;
                }
            }
        } else {
            VSync(0);
        }
        D_8006C5D4 = VSync(-1);
        PutDispEnv(D_8006C600 + 0x5C);
        PutDrawEnv((DRAWENV *) D_8006C600);
        if ((D_8006E344 == 4) && (D_8006C65C != 0) && ((u8) D_80070134 != 0) && ((D_8006C668 - D_8006C664) >= 0xA01)) {
            temp_s3 = D_8006C550;
            temp_s4 = M2C_FIELD(D_8006C65C, u8 *, 0xA0);
            {
                register s32 callResult asm("$2") = func_8004E664(0x580);
                register u8 opacity asm("$3") = 0xFFU;
                register u8 *specialDraw asm("$4") = D_8006C65C;
                temp_s1 = D_8006C6B0;
                temp_s2 = callResult;
                D_8006C550 = specialDraw;
                M2C_FIELD(specialDraw, u8 *, 0xA0) = opacity;
            }
            temp_s0 = D_8006C668;
            {
                register u8 *specialBase asm("$3") = D_8006FBFC;
                register u8 *currentDraw asm("$2") = (u8 *)D_8006C600;
                if (currentDraw == specialBase) {
                    var_v1_2 = D_8006FCE0;
                } else {
                    var_v1_2 = D_8006FC6C;
                }
            }
            D_8006C668 = var_v1_2;
            temp_v0_3 = var_v1_2 + D_8006C7DC;
            D_8006C668 = temp_v0_3;
            func_8004E7AC(temp_v0_3 - 0x3000, 0, 0xC00);
            func_80030478();
            func_80031124();
            D_8006C668 = temp_s0;
            *temp_s1 = (*temp_s1 & 0xFF000000) | (func_8004E664(0x580) & 0xFFFFFF);
            D_8006C550 = temp_s3;
            D_8006C7E8 = D_8006C668 - D_8006C664;
            M2C_FIELD(D_8006C65C, u8 *, 0xA0) = temp_s4;
            DrawOTag((u32 *) temp_s2);
            return;
        }
        if ((D_8006E344 == 0xD) && (D_8006C4F8 != 2)) {
            temp_s2 = func_8004E664(0x580);
            temp_s1 = D_8006C6B0;
            temp_s0 = D_8006C668;
            {
                register u8 *specialBase asm("$3") = D_8006FBFC;
                register u8 *currentDraw asm("$2") = (u8 *) D_8006C600;
                if (currentDraw == specialBase) {
                    var_v1_3 = D_8006FCE0;
                } else {
                    var_v1_3 = D_8006FC6C;
                }
            }
            D_8006C668 = var_v1_3;
            temp_v0_4 = var_v1_3 + D_8006C7DC;
            D_8006C668 = temp_v0_4;
            func_8004E7AC(temp_v0_4 - 0x3000, 0, 0xC00);
            func_8003CDA0();
            D_8006C668 = temp_s0;
            *temp_s1 = (*temp_s1 & 0xFF000000) | (func_8004E664(0x580) & 0xFFFFFF);
            DrawOTag((u32 *) temp_s2);
        } else {
            DrawOTag((u32 *) func_8004E664(0x580));
        }
    }
}
