#include "common.h"
#include "drawutil.h"

extern unsigned char* D_8006C668;
extern int D_8006FBC4, D_8006C518, D_8006C76C, D_8006C598;
extern const char* D_loading_8007B708[];
extern const char* D_loading_8007B70C[];
void func_80059358(int, int);
void func_8004E7AC(void*, int, int);
void func_8003CDA0(void);
void DecodedLoadingFade(int, int, int, int) __asm__("func_800200A0");
void func_loading_80076EE8(void) {
    register int* timer __asm__("$16");
    func_80059358(0x80, 0x80);
    func_8004E7AC(D_8006C668 - 0x3000, 0, 0xC00);
    func_8003CDA0();
    timer = &D_8006FBC4;
    __asm__("" : "=r"(timer) : "0"(timer));
    if (*timer >= 0x78 && D_8006C518 >= 7) {
        func_80020344(D_loading_8007B708[D_8006C76C], 0x100, 0x1E, 2);
        {
            register int style __asm__("$7") = 2;
            register const char** table __asm__("$4") = D_loading_8007B70C;
            register unsigned int index __asm__("$3");
            register int ticks __asm__("$2");
            const char** entry;
            __asm__("" : "=r"(table) : "0"(table), "r"(style) : "$2", "$3");
            index = D_8006C76C;
            ticks = *timer;
            __asm__("" : "=r"(ticks) : "0"(ticks), "r"(index));
            index *= 4;
            __asm__("" : "=r"(index) : "0"(index), "r"(ticks));
            entry = (const char**)(index + (unsigned int)table);
            if ((ticks & 0x1F) < 0x16) style = 3;
            func_80020344(*entry, 0x100, 0xC8, style);
        }
    }
    if (D_8006C598) DecodedLoadingFade(2, D_8006C598, D_8006C598, D_8006C598);
}

INCLUDE_ASM("asm/nonmatchings/overlays/loading/loading3", func_loading_80076FEC);

INCLUDE_ASM("asm/nonmatchings/overlays/loading/loading3", func_loading_80077438);

INCLUDE_ASM("asm/nonmatchings/overlays/loading/loading3", func_loading_80077964);
