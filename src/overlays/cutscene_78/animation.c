#include "common.h"
#include "pad.h"

/* Retail-selected 16-byte PadState; shared selector stored at 0x8006C570. */
extern PadState* D_8006C570;

void func_cutscene_78_80076C78(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_78_80076C98(void) {}

void func_cutscene_78_80076CA0(void) {}

void func_cutscene_78_80076CA8(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_78_80076CC8(void) {}

void func_cutscene_78_80076CD0(void) {}
