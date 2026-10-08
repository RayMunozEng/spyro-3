#include "common.h"
#include "pad.h"

/* Retail-selected 16-byte PadState; shared selector stored at 0x8006C570. */
extern PadState* D_8006C570;

void func_cutscene_64_80076DE0(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_64_80076E00(void) {}

void func_cutscene_64_80076E08(void) {}

void func_cutscene_64_80076E10(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_64_80076E30(void) {}

void func_cutscene_64_80076E38(void) {}
