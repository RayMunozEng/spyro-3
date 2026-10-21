#include "common.h"
#include "pad.h"

/* Retail-selected 16-byte PadState; shared selector stored at 0x8006C570. */
extern PadState* D_8006C570;

void func_cutscene_61_800769AC(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_61_800769CC(void) {
}

void func_cutscene_61_800769D4(void) {
}

void func_cutscene_61_800769DC(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_61_800769FC(void) {
}

void func_cutscene_61_80076A04(void) {
}
