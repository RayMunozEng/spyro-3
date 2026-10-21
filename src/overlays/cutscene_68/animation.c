#include "common.h"
#include "pad.h"

/* Retail-selected 16-byte PadState; shared selector stored at 0x8006C570. */
extern PadState* D_8006C570;

void func_cutscene_68_80076528(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_68_80076548(void) {
}

void func_cutscene_68_80076550(void) {
}

void func_cutscene_68_80076558(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_68_80076578(void) {
}

void func_cutscene_68_80076580(void) {
}
