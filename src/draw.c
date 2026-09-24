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

INCLUDE_ASM("asm/nonmatchings/draw", func_8001DD1C);

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

/**
 * Draw() - func_8001E638()
 */
INCLUDE_ASM("asm/nonmatchings/draw", Draw);
