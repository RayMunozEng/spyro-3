#include "common.h"
#include "pad.h"

/* Retail-selected 16-byte PadState; shared selector stored at 0x8006C570. */
extern PadState* D_8006C570;

void func_cutscene_73_800772F8(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_73_80077318(void) {
}

void func_cutscene_73_80077320(void) {
}

void func_cutscene_73_80077328(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_73_80077348(void) {
}

void func_cutscene_73_80077350(void) {
}
