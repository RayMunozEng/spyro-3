#include "common.h"
#include "pad.h"

/* Retail-selected 16-byte PadState; shared selector stored at 0x8006C570. */
extern PadState* D_8006C570;

void func_cutscene_62_80076FD8(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_62_80076FF8(void) {}

void func_cutscene_62_80077000(void) {}

void func_cutscene_62_80077008(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_62_80077028(void) {}

void func_cutscene_62_80077030(void) {}
