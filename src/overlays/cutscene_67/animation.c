#include "common.h"
#include "pad.h"

/* Retail-selected 16-byte PadState; shared selector stored at 0x8006C570. */
extern PadState* D_8006C570;

void func_cutscene_67_80076880(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_67_800768A0(void) {}

void func_cutscene_67_800768A8(void) {}

void func_cutscene_67_800768B0(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_67_800768D0(void) {}

void func_cutscene_67_800768D8(void) {}
