#include "common.h"
#include "pad.h"

/* Retail-selected 16-byte PadState; shared selector stored at 0x8006C570. */
extern PadState* D_8006C570;

void func_cutscene_80_80076BF8(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_80_80076C18(void) {
}

void func_cutscene_80_80076C20(void) {
}

void func_cutscene_80_80076C28(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_80_80076C48(void) {
}

void func_cutscene_80_80076C50(void) {
}
