#include "common.h"
#include "drawutil.h"
#include "hud.h"
#include "mobyfunc.h"
#include "stdutil.h"

extern void VSync(int);
extern int D_8006C668;

extern char D_80067570[16][12]; // might be an array of structs, not sure
extern PauseData pauseData; // 8006fbc4

////////////////////////////////////////////////////////////////////////////////////

// I'm using the REORDER_HACK in here which should just equal the normal INCLUDE_ASM right now
// At time of writing this is a file that would fail when changing to -G8 so this is just saving me time later

/**
 * ???() - func_8001EBAC() - MATCHING
 * https://decomp.me/scratch/v2ehU
 */
void func_8001EBAC() {
    RECT rect;

    DrawSync(0);
    VSync(0);
    rect.x = 0;
    rect.y = 0;
    rect.w = 512;
    rect.h = 240;
    ClearImage(&rect, 0, 0, 0);
    rect.y = 228;
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
}

void func_8001EC24(void) {
    func_8004E7AC((char*)D_8006C668 - 0x3000, 0, 0x1C00);
    func_80022378();
}

/* Retail source: asm/nonmatchings/drawutil/func_8001EC5C.s,
 * 0x8001EC5C..0x8001EDEC; calls occur once per function invocation. */
extern char D_80070328[];
extern int D_8006E344, D_8006C4F8;
extern unsigned char D_80071834;
long long func_8001EC5C(void) {
    int saved;
    unsigned char oldMode;
    int mode;
    func_8004E7AC((char*)D_8006C668 - 0x3000, 0, 0xC00);
    func_80030478();
    func_80031124();
    func_80033C5C();
    func_8002DDA8();
    if (*(int*)(D_80070328 + 0x288) == 0) {
        if (D_8006E344 != 13 || D_8006C4F8 == 2) {
            saved = *(int*)(D_80070328 + 0x2C);
            if (saved != 0) {
                int x = *(int*)(D_80070328 + 8);
                int y = *(int*)(D_80070328 + 0x10C);
                oldMode = D_80070328[0x1E];
                *(int*)(D_80070328 + 8) = x - saved * 2;
                mode = func_80040954(y);
                D_80070328[0x1E] = mode == 4 ? 0xFA : 0xF4;
                func_8003CDA0();
                {
                    extern int drawCounter __asm__("D_80070328+44");
                    extern int drawPosition __asm__("D_80070328+8");
                    register int offset __asm__("$2") = drawCounter;
                    register int* pos __asm__("$4") = &drawPosition;
                    drawCounter = 0;
                    D_80070328[0x1E] = oldMode;
                    *pos += offset * 2;
                }
            }
            func_8003CDA0();
            func_8002D9BC();
            if (D_80071834 != 0) {
                func_8002D2C4();
            }
            *(int*)(D_80070328 + 0x2C) = saved;
        }
    }
    if (D_8006E344 == 6 && D_80071834 != 0) {
        func_8002D2C4();
    }
}

INCLUDE_ASM_REORDER_HACK("asm/nonmatchings/drawutil", func_8001EDEC);

/**
 * ???() - func_8001FABC()
 * https://decomp.me/scratch/RfQhe
 */
void func_8001FABC(int arg0) {
    void* packet = D_8006C664;
    func_8005C564(packet, 1, 0, arg0, 0);
    func_8004E758(packet);
    D_8006C664 = (char*)packet + 12;
}

extern int D_800722D8, D_8006C7DC, D_800722D4, D_800722D0, D_8006FC6C, D_8006FCE0;
void func_8001FB10(int arg0) {
    int top;
    int bottom;
    DrawSync(0);
    D_8006C7DC = arg0;
    top = D_800722D8 - arg0;
    bottom = top - arg0;
    D_800722D4 = top;
    D_800722D0 = bottom;
    D_8006FC6C = bottom;
    D_8006FCE0 = top;
}

/**
 * ???() - func_8001FB74() - MATCHING
 * Draw line under NPC name
 * https://decomp.me/scratch/9NQVn
 */
void func_8001FB74(int x0, int y0, int x1, int y1) {

    LINE_G2* line;

    line = D_8006C664;

    line->tag = 0x04000000;
    line->code = 0x50;
    setXY2(line, x0, y0, x1, y1);
    setRGB0(line, 180, 154, 17);
    setRGB1(line, 180, 154, 17);

    func_8004E758(line);

    line++;
    D_8006C664 = line;

    line->tag = 0x04000000;
    line->code = 0x50;
    setXY2(line, x0 + 1, y0 + 1, x1 + 1, y1 + 1);
    setRGB0(line, 128, 82, 0);
    setRGB1(line, 128, 82, 0);

    func_8004E758(line);
    D_8006C664 = line + 1;
}

/**
 * ???() - func_8001FC90() - MATCHING
 * https://decomp.me/scratch/8lG9w
 */
void func_8001FC90(int x0, int x1, int y0, int y1) {
    POLY_F4* p;

    p = D_8006C664;
    p->tag = 0x05000000;

    *(int*)&p->r0 = 0x2A080808;

    p->x0 = x0;
    p->x1 = x1;
    p->x2 = x0;
    p->x3 = x1;
    p->y0 = y0;
    p->y1 = y0;
    p->y2 = y1;
    p->y3 = y1;

    func_8004E758(p);
    D_8006C664 = p + 1;
}

/* Retail source: asm/nonmatchings/drawutil/func_8001FD00.s,
 * 0x8001FD00..0x8001FE48; integer screen coordinates and
 * on-call corner sprite draws. */
extern short D_800719D0;
void func_8001FD00(int left, int right, int top, int bottom) {
    int innerTop = top + 8;
    int innerBottom = bottom - 8;
    int innerLeft = left + 12;
    int innerRight = right - 12;
    short* frame = &D_800719D0;
    func_8001FABC(0x18);
    func_8001FC90(left, right, innerTop, innerBottom);
    func_8001FC90(innerLeft, innerRight, top, innerTop);
    func_8001FC90(innerLeft, innerRight, innerBottom, bottom);
    func_800289C8(&D_8006C788[*frame], left, top);
    func_800289C8(&D_8006C788[*frame + 1], innerRight, top);
    func_800289C8(&D_8006C788[*frame + 2], left, innerBottom);
    func_800289C8(&D_8006C788[*frame + 3], innerRight, innerBottom);
}

/**
 * ???() - func_8001FE48() - MATCHING
 * https://decomp.me/scratch/bNzDh
 */
void func_8001FE48(int arg0, int arg1, int arg2, int arg3) {
    func_8001FABC(0x18);
    func_8001FC90(arg0 + 3, arg1 - 3,    arg2,        arg2 + 1);
    func_8001FC90(arg0 + 1, arg1 - 1,    arg2 + 1,    arg2 + 2);
    func_8001FC90(arg0,     arg1,        arg2 + 2,    arg3 - 2);
    func_8001FC90(arg0 + 1, arg1 - 1,    arg3 - 2,    arg3 - 1);
    func_8001FC90(arg0 + 3, arg1 - 3,    arg3 - 1,    arg3);
}

/* Retail source: asm/nonmatchings/drawutil/func_8001FF44.s,
 * 0x8001FF44..0x800200A0; border size is an integer screen coordinate. */
extern int D_8006C74C;
extern int D_8006C64C;
extern char D_80070328[];
void func_8001FF44(void) {
    int i;
    char* packet;
    int size;
    if (*(int*)(D_80070328 + 0x210) & 0x80000) {
        D_8006C74C = 0;
    }
    if (D_8006C74C != 0) {
        if (D_8006C64C < 12) {
            D_8006C64C++;
        }
    } else if (D_8006C64C != 0) {
        D_8006C64C--;
    }
    if (D_8006C64C == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        packet = D_8006C664;
        *(int*)packet = 0x05000000;
        packet[7] = 0x28;
        *(short*)(packet + 8) = 0;
        *(short*)(packet + 12) = 0x200;
        *(short*)(packet + 16) = 0;
        *(short*)(packet + 20) = 0x200;
        if (i == 0) {
            size = D_8006C64C;
            *(short*)(packet + 10) = 12;
            size += 12;
            __asm__ volatile("" : "=r"(size) : "0"(size));
            *(short*)(packet + 18) = size;
        } else {
            register int bottomSize __asm__("$2") = D_8006C64C;
            *(short*)(packet + 10) = 0xE4;
            *(short*)(packet + 18) = 0xE4 - bottomSize;
        }
        *(short*)(packet + 14) = *(unsigned short*)(packet + 10);
        *(short*)(packet + 22) = *(unsigned short*)(packet + 18);
        packet[4] = 0;
        packet[5] = 0;
        packet[6] = 0;
        func_8004E758(packet);
        D_8006C664 = packet + 24;
    }
}

/* Retail source: asm/nonmatchings/drawutil/func_800200A0.s,
 * 0x800200A0..0x80020168; primitive fields use byte offsets. */
void func_800200A0(int arg0, char red, char green, char blue) {
    char* packet = (char*)D_8006C664;
    char* poly;
    func_8005C564(packet, 1, 0, arg0 << 5, 0);
    func_8004E758(packet);
    poly = packet + 12;
    *(int*)(packet + 0xC) = 0x05000000;
    packet[0x13] = 0x2A;
    *(short*)(packet + 0x16) = 12;
    *(short*)(packet + 0x1A) = 12;
    *(short*)(packet + 0x14) = 0;
    *(short*)(packet + 0x18) = 0x200;
    *(short*)(packet + 0x1C) = 0;
    *(short*)(packet + 0x1E) = 0xE4;
    *(short*)(packet + 0x20) = 0x200;
    *(short*)(packet + 0x22) = 0xE4;
    packet[0x10] = red;
    packet[0x11] = green;
    packet[0x12] = blue;
    func_8004E758(poly);
    D_8006C664 = packet + 0x24;
}

/**
 * ???() - func_80020168()
 * https://decomp.me/scratch/qLRGj
 */
/* Retail source: asm/nonmatchings/drawutil/func_80020168.s,
 * 0x80020168..0x800202DC; one loop iteration per frame. */
extern char D_8006FBFC;
extern char D_8006FC14, D_8006FC88;
extern char* D_8006C600;
extern int D_8006C634, D_8006C7D4;
extern void* func_8004E664(int);
void func_80020168(void) {
    RECT rect;
    register int top __asm__("$2");
    register int destY __asm__("$6");
    int i;
    char* next;
    register void* packet __asm__("$3");
    register int count __asm__("$2");
    DrawSync(0);
    VSync(0);
    top = 12;
    __asm__ volatile("" : "=r"(top) : "0"(top));
    rect.x = 0;
    if (D_8006C600 != &D_8006FBFC) {
        top = 240;
    }
    rect.y = top;
    rect.w = 512;
    rect.h = 216;
    destY = 12;
    if (D_8006C600 == &D_8006FBFC) {
        destY = 240;
    }
    MoveImage(&rect, 0, destY);
    DrawSync(0);
    i = 0;
    D_8006FC14 = 0;
    D_8006FC88 = 0;
    do {
        next = D_8006C600 == &D_8006FBFC ? &D_8006FBFC + 0x74 : &D_8006FBFC;
        count = D_8006C634;
        D_8006C600 = next;
        packet = *(void**)(next + 0x70);
        __asm__ volatile("" : "=r"(packet), "=r"(count) : "0"(packet), "1"(count));
        D_8006C7D4 = count + 0x1000;
        __asm__ volatile("" ::: "memory");
        D_8006C664 = packet;
        if (i == 0) {
            func_800200A0(2, 16, 16, 16);
        } else {
            func_800200A0(2, 32, 32, 32);
        }
        i++;
        DrawSync(0);
        VSync(0);
        PutDispEnv((DISPENV*)(D_8006C600 + 0x5C));
        PutDrawEnv((DRAWENV*)D_8006C600);
        DrawOTag(func_8004E664(0x580));
    } while (i < 16);
    func_8001EBAC();
    D_8006FC14 = 1;
    D_8006FC88 = 1;
}

/**
 * DrawStringCentered() - func_800202DC() - MATCHING
 * https://decomp.me/scratch/iAe5h
 */
void DrawStringCentered(char* arg0, int arg1, int arg2, int arg3) {
    int x = arg1;
    x -= (func_8002EBB0(arg0) >> 1);
    func_8002E748(arg0, x, arg2, arg3, 0);
}

void func_80020344(const char* arg0, int arg1, int arg2, int arg3) {
    int halfWidth = func_8002EBB0((void*)arg0) >> 1;

    func_8001FE48(arg1 - halfWidth - 8, arg1 + halfWidth + 8, arg2 - 2, arg2 + 11);
    DrawStringCentered((char*)arg0, arg1, arg2, arg3);
}

/**
 * DrawStringRightAligned() - func_800203C4() - MATCHING
 * https://decomp.me/scratch/YCZcN
 */
void DrawStringRightAligned(char* arg0, int arg1, int arg2, int arg3) {
    int x = arg1;
    x -= func_8002EBB0(arg0);
    func_8002E748(arg0, x, arg2, arg3, 0);
}

extern char D_8006C3D8[];
extern char D_8006C3DC[];
extern int D_8006FBF8;
extern int D_8006C76C;
void func_80020428(int value, int x, int y, int color) {
    char buffer[8];
    sprintf(buffer, D_8006C3D8, value);
    if (x < 0) {
        x = -x - 12 * strlen(buffer);
    }
    if (D_8006FBF8 != 0) {
        func_8002E970(buffer, x, y, color, 0);
    } else {
        func_8002E748(buffer, x, y, color, 0);
        if (D_8006C76C != 2 && value >= 1000) {
            x += 10;
            if (value >= 10000) {
                x += 12;
            }
            func_8002E748(D_8006C3DC, x, y + 1, color, 0);
        }
    }
}

/* Retail: asm/nonmatchings/drawutil/func_80020530.s, 0x80020530..0x80020790; public decomp.me scratch i0k7F (score 0). */
extern int D_8006C598;
extern int D_8006C76C;

extern int D_8006FBD0;
extern short D_80070158;

typedef struct {
    char* stringsmaybe[45];
} Something;

extern Something D_80069DE4;

typedef struct {
    int unk0;
    int unkn8;
} TempMenuSomething;

//unk0 = int
extern TempMenuSomething D_8006FBCC;

void func_80020530(signed char* arg0) {

    int var_s4 = 256;
    int var_s0;
    int var_s2;
    int var_t0;
    int var_a1;
    int var_a2;
    int var_a3;
    Something* var_s5;
    TempMenuSomething* menu;
    unsigned char charidx; //
    int offset;
    int mid;
    char* stringmaybe;
    Something* temp_s3;

    int temp_a3;
    var_s2 = 80;
    var_t0 = 192;
    var_a1 = 320;
    var_a2 = 76;
    var_a3 = 172;
    //var_s4 = 256;


    if (D_8006FBD0 == 0xD) {
        var_s0 = 0;
        if ((unsigned char)arg0[1] != 0xFF) {
            do {
                var_s0++;
            } while ((unsigned char)arg0[var_s0 + 1] != 0xFF);
        }
        D_80070158 = var_s0;

        var_s0 = ((var_s0 * 8) - var_s0) * 2;
        var_s0 += 21;

        mid = (var_a2 + var_a3) >> 1;

        offset = var_s2 - var_a2;
        var_s2 = mid - (var_s0 >> 1);
        var_a2 = var_s2 - offset;
        var_a3 = var_s2 + var_s0 + offset;

        var_t0 -= 0x14;
        var_a1 += 0x14;
    } else if (D_8006FBD0 == 0xE) {
        var_t0 = 0x20;
        var_a1 = 0x1E0;
    } else {
        D_80070158 = 5;
    }
    func_8001FD00(var_t0, var_a1, var_a2, var_a3);


    temp_s3 = &D_80069DE4;
    DrawStringCentered(temp_s3[D_8006C76C].stringsmaybe[(unsigned char)arg0[0]], var_s4, var_s2, 2);
    var_s2 += 21;
    var_s0 = 1;
    if ((unsigned char)arg0[1] != 0xFF) {
        var_s5 = temp_s3;
        menu = &D_8006FBCC;
        arg0++;

        do {

            charidx = *arg0;

            if (charidx != 0x2E) {

                stringmaybe = var_s5[D_8006C76C].stringsmaybe[charidx];

                if (D_8006C598 == 0) {
                    temp_a3 = 0;
                    if (menu->unk0 == var_s0) {
                        int menuField = *(int*)((unsigned char*)menu - 8);
                        int mask = menuField & 0x1F;
                        temp_a3 = (mask < 0x16) ? 1 : 0;
                    }
                    temp_a3 += 2;
                } else {
                    int a3mask = (D_8006FBCC.unk0 == var_s0) ? 1 : 0;
                    temp_a3 = a3mask + 2;
                }

                charidx = arg0[0];
                if (  ( (unsigned int)(charidx - 0x25) < 8) && (temp_a3 == 2)  ) {
                    charidx = charidx - 0x25;
                    if ( !(charidx & 1) ) {
                        temp_a3 = 4;
                    }
                }

                DrawStringCentered(stringmaybe, var_s4, var_s2, temp_a3);
            }
            var_s2 += 0xE;
            arg0++;
            var_s0++;
        } while ((unsigned char)*arg0 != 0xFF);
    }
}

/* Retail: asm/nonmatchings/drawutil/func_80020790.s, 0x80020790..0x80020D70.
 * The menu selection, width pass, centering bounds, and draw calls follow the retail instruction/data chain. */
extern int D_8006C5BC;
extern int D_8006C5C8;
extern int D_8006FA3C;
extern void* D_80071484[];
#define DRAWUTIL_FIELD(expr, type_ptr, offset) (*(type_ptr)((signed char*)(expr) + (offset)))
void func_80020790(void) {
    int sp18;
    int sp20;
    short temp_v1;
    int temp_s7;
    int temp_v1_2;
    register int var_a0 asm("$23");
    int var_a3;
    int var_a3_2;
    int var_fp;
    int var_s0;
    int var_s1_3;
    register int var_s2 asm("$18");
    register int var_s4 asm("$20");
    int var_s6;
    int var_v0;
    signed char *temp_a0_3;
    signed char *sentinel;
    signed char *temp_s5;
    signed char *var_s0_2;
    int temp_a0_4;
    void **var_s1;
    void **table;
    void *temp_a0;
    void *temp_a0_2;
    Something *stringTable;
    TempMenuSomething *menuState;

    var_s2 = 0;
    var_s6 = 0;
    var_fp = 0x85;
    sp18 = 0x17B;
    var_s4 = 0x32;
    var_a0 = 0x80;
    sp20 = 0x180;
    if (((D_8006C5BC / 10) * 0xA) == (D_8006C5BC - 5)) {
        if (D_8006FA3C == 3) {
            switch (D_8006C5BC) {                   /* switch 1; irregular */
            case 15:                                /* switch 1 */
                var_s2 = 0x15;
                break;
            case 25:                                /* switch 1 */
                var_s2 = 0x16;
                break;
            case 35:                                /* switch 1 */
                var_s2 = 0x17;
                break;
            case 45:                                /* switch 1 */
                var_s2 = 0x18;
                break;
            }
        } else {
            var_s2 = 3;
            if (D_8006FA3C == 2) {
                var_s2 = 4;
            }
        }
    } else if (DRAWUTIL_FIELD(D_80070328, int *, 0x24C) == 0) {
        if ((D_8006C5BC == 0x18) && (D_8006C5C8 == 1)) {
            var_s2 = 0x10;
        } else if (D_8006C5BC == 0x1F) {
            var_s2 = 0x11;
        } else if (DRAWUTIL_FIELD(D_80070328, int *, 0x48) == 0x26) {
            var_s2 = 5;
        } else if (DRAWUTIL_FIELD(D_80070328, int *, 0x50) == 0x13) {
            if ((D_8006C5BC == 0x20) || (var_s2 = 0xE, (D_8006C5BC == 0x32))) {
                var_s2 = 0xF;
            }
        } else if (D_8006C5BC == 0x2F) {
            if (DRAWUTIL_FIELD(D_80070328, void **, 0x250) != ((void*)0)) {
                temp_v1 = DRAWUTIL_FIELD(DRAWUTIL_FIELD(D_80070328, void **, 0x250), short *, 0x36);
                if (temp_v1 != 0x2F5) {
                    if (temp_v1 == 0x2EA) {
                        var_s2 = 0x1B;
                    }
                } else {
                    goto block_35;
                }
            }
        } else if (D_8006C5BC == 0x32) {
            if (DRAWUTIL_FIELD(D_80070328, void **, 0x250) != ((void*)0)) {
                if (DRAWUTIL_FIELD(DRAWUTIL_FIELD(D_80070328, void **, 0x250), short *, 0x36) == 0xF0) {
block_35:
                    var_s2 = 0x14;
                }
            }
        } else if (DRAWUTIL_FIELD(D_80070328, int *, 0x50) == 0x12) {
            var_s2 = 0xD;
            if (D_8006C5BC == 0x2B) {
                var_s2 = 0x13;
            }
        } else if (DRAWUTIL_FIELD(D_80070328, int *, 0x50) == 0xA) {
            var_s2 = 1;
        } else if ((unsigned int) (DRAWUTIL_FIELD(D_80070328, int *, 0x50) - 0xB) < 2U) {
            var_s2 = 2;
        }
    } else {
        switch (DRAWUTIL_FIELD(D_80070328, int *, 0x24C)) {
        case 1:
            var_s2 = 6;
            break;
        case 2:
            var_s2 = 8;
            if (D_8006C5BC == 0x24) {
                var_s2 = 9;
            }
            break;
        case 3:
            var_s2 = 7;
            break;
        case 4:
            if (D_8006C5BC != 0x21) {
                var_s2 = 0x1A;
                if (D_8006C5BC != 0x2C) {
                    var_s2 = 0xB;
                }
            } else {
                var_s2 = 0x19;
            }
            break;
        case 5:
            var_s2 = 0xA;
            break;
        case 6:
            var_s2 = 0x12;
            break;
        case 7:
            var_s2 = 0xC;
            break;
        }
    }
    { register signed char *tableBase asm("$4"); register int tableOffset asm("$3"); register int tableIndex asm("$2");
      tableIndex = 0xA; tableBase = (signed char *)D_80071484; tableOffset = var_s2 << 2; D_80070158 = tableIndex;
      tableIndex = D_8006C76C; tableOffset += (int)tableBase; tableIndex <<= 2; tableIndex += tableOffset;
      var_s1 = *(void ***)tableIndex; }
    temp_s5 = D_80067570[D_8006FBD0];
    if ((var_s1 != ((void*)0)) && (*var_s1 != (void *)-1)) {
        do {
            temp_a0 = *var_s1;
            var_s1 += 1;
            var_s0 = func_8002EBB0(temp_a0);
            temp_a0_2 = *var_s1;
            if (temp_a0_2 != (void *)-1) {
                var_s1 += 1;
                var_s0 += func_8002EBB0(temp_a0_2);
                var_s0 += 0x1A;
            }
            if (var_s6 < var_s0) {
                var_s6 = var_s0;
            }
        } while (*var_s1 != (void *)-1);
    }
    if (var_s6 >= 0x101) {
        { register int screenWidth asm("$3"); register int centered asm("$2"); int rightEdge;
        screenWidth = 0x200; centered = screenWidth - var_s6; temp_s7 = centered >> 1;
        rightEdge = screenWidth - temp_s7; sp20 = rightEdge; __asm__ volatile("" ::: "memory");
        var_fp = temp_s7 + 5; screenWidth = screenWidth - var_fp; sp18 = screenWidth; }
        var_a0 = temp_s7;
    }
    func_8001FD00(var_a0, sp20, 0x2E, 0xD3);
    DrawStringCentered((&D_80069DE4)[D_8006C76C].stringsmaybe[(unsigned char) DRAWUTIL_FIELD(temp_s5, signed char *, 0)], 0x100, var_s4, 2);
    { register signed char *tableBase2 asm("$4"); register int tableOffset2 asm("$2"); register int tableIndex2 asm("$3");
      tableBase2 = (signed char *)D_80071484; tableOffset2 = var_s2 << 2; tableIndex2 = D_8006C76C;
      tableOffset2 += (int)tableBase2; tableIndex2 <<= 2; tableOffset2 = tableIndex2 + tableOffset2;
      var_s1 = *(void ***)tableOffset2; var_s4 += 0x15;
      if (var_s1 == ((void*)0)) { tableOffset2 = (int)tableBase2; tableOffset2 += tableIndex2; __asm__ volatile("" : "=r"(tableOffset2) : "0"(tableOffset2)); var_s1 = *(void ***)tableOffset2; } }
    if ((var_s1 != ((void*)0)) && (*var_s1 != -1)) {
        sentinel = (signed char *)-1;
loop_72:
        { register signed char *arg0 asm("$4"); register int arg1 asm("$5"); register int arg2 asm("$6"); register int arg3 asm("$7");
          arg1 = var_fp; arg2 = var_s4; arg3 = 2; __asm__ volatile("" ::: "memory"); arg0 = *var_s1; var_s1 += 1;
          func_8002E748(arg0, arg1, arg2, arg3, ((void*)0)); }
        temp_a0_3 = DRAWUTIL_FIELD(var_s1, signed char **, 0);
        if (temp_a0_3 != sentinel) {
            DrawStringRightAligned(temp_a0_3, sp18, var_s4, 2);
            __asm__ volatile("" ::: "memory");
            var_s1 += 1;
            var_s4 += 0xE;
            if (*var_s1 != sentinel) {
                goto loop_72;
            }
        }
    }
    var_s4 = 0xC5;
    var_s1_3 = 1;
    if ((unsigned char) temp_s5[1] != 0xFF) {
        stringTable = &D_80069DE4;
        menuState = &D_8006FBCC;
        var_s0_2 = &temp_s5[1];
        do {
            temp_a0_4 = (unsigned char) *var_s0_2;
            if (temp_a0_4 != 0x2E) {
                temp_a0_3 = stringTable[D_8006C76C].stringsmaybe[temp_a0_4];
                if (D_8006C598 == 0) {
                    var_a3 = 0;
                    if (menuState->unk0 == var_s1_3) {
                        temp_v1_2 = DRAWUTIL_FIELD(menuState, int *, -8) & 0x1F; var_a3 = temp_v1_2 < 0x16;
                    }
                    var_a3_2 = var_a3 + 2;
                } else {
                    temp_v1_2 = (unsigned int) (D_8006FBCC.unk0 ^ var_s1_3) < 1U; var_a3_2 = temp_v1_2 + 2;
                }
                DrawStringCentered(temp_a0_3, 0x100, var_s4, var_a3_2);
            }
            var_s4 += 0xE;
            var_s0_2 += 1;
            var_s1_3 += 1;
        } while ((unsigned char) *var_s0_2 != 0xFF);
    }
}
#undef DRAWUTIL_FIELD

/**
 * ???() - func_80020D70() - MATCHING
 * https://decomp.me/scratch/iZDl3
 */
void func_80020D70() {
    func_80020530((signed char*)&D_80067570[pauseData.menuType]);
}

/**
 * DrawStringRowCentered() - func_80020DAC() - MATCHING
 * https://decomp.me/scratch/0lU0I
 */
void DrawStringRowCentered(char** arg0, int arg1, int arg2, int arg3) {
    int i;
    int var_s3;
    int var_s2 = 0;
    char **p = arg0;

    while (*p[var_s2] != 0) var_s2++;

    var_s3 = arg2 - var_s2 * 7;
    for (i = 0; i < var_s2; i++) {
        DrawStringCentered(arg0[i], arg1, var_s3, arg3);
        var_s3 += 14;
    }
}
