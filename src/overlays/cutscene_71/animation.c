#include "common.h"
#include "pad.h"

/* Retail-selected 16-byte PadState; shared selector stored at 0x8006C570. */
extern PadState* D_8006C570;

void func_cutscene_71_800767C0(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_71_800767E0(void) {
}

void func_cutscene_71_800767E8(void) {
}

void func_cutscene_71_800767F0(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_71_80076810(void) {
}

void func_cutscene_71_80076818(void) {
}
