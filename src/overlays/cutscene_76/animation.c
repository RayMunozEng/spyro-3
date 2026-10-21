#include "common.h"
#include "pad.h"

/* Retail-selected 16-byte PadState; shared selector stored at 0x8006C570. */
extern PadState* D_8006C570;

void func_cutscene_76_80076610(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_76_80076630(void) {
}

void func_cutscene_76_80076638(void) {
}

void func_cutscene_76_80076640(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_76_80076660(void) {
}

void func_cutscene_76_80076668(void) {
}
