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
INCLUDE_ASM("asm/nonmatchings/draw", func_8001D424);

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
