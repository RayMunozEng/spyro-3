#include "common.h"
#include "drawutil.h"

INCLUDE_ASM("asm/nonmatchings/overlays/options/options1", func_options_80074C00);

INCLUDE_ASM("asm/nonmatchings/overlays/options/options1", func_options_80075180);

extern int D_options_8007ABE0, D_80070148, D_8006FBD0;
void func_80058408(void);
void func_options_80074C00(void);
void func_options_80075180(void);
void func_options_80075A38(void) {
    func_80058408();
    switch (D_options_8007ABE0) {
    case 0: case 2:
        if (D_80070148 == 2) return;
        goto draw;
    case 1:
        switch (D_8006FBD0) {
        case 8: goto draw;
        case 9: case 10: goto menu;
        case 11: goto special;
        default: return;
        }
    default: return;
    }
draw:
    func_80020D70(0);
    return;
menu:
    func_options_80074C00();
    return;
special:
    func_options_80075180();
}

INCLUDE_ASM("asm/nonmatchings/overlays/options/options1", func_options_80075B18);

INCLUDE_ASM("asm/nonmatchings/overlays/options/options1", func_options_800761D4);

extern int D_options_8007ABE0;
extern int D_8006FBD0, D_80070148, D_8006FBC8, D_8006FBD4;
extern unsigned char D_options_8007AFB4;
void func_options_800761D4(void);
void func_options_80075B18(void);
void func_options_800777C8(void) {
    register int* state __asm__("$6") = &D_options_8007ABE0;
    __asm__("" : "=r"(state) : "0"(state));
    switch (*state) {
    case 0: {
        register int value __asm__("$2") = 8;
        register int* destination __asm__("$4");
        __asm__("" : "=r"(value) : "0"(value) : "$4");
        destination = &D_8006FBD0;
        *destination = value;
        *state = 1;
        __asm__("" : : "r"(destination));
        if (D_80070148 == 2) {
            *destination = 11;
            D_options_8007AFB4 = 0;
        }
        break;
    }
    case 2:
        D_8006FBC8 = 24;
        D_8006FBD4 = 0;
        break;
    case 1:
        if (D_8006FBD0 == 11) func_options_800761D4();
        else func_options_80075B18();
        break;
    }
}
