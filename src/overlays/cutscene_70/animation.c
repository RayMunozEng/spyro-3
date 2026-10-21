#include "common.h"
#include "pad.h"

/* Retail-selected 16-byte PadState; shared selector stored at 0x8006C570. */
extern PadState* D_8006C570;

void func_cutscene_70_80076B70(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_70_80076B90(void) {
}

void func_cutscene_70_80076B98(void) {
}

void func_cutscene_70_80076BA0(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_70_80076BC0(void) {
}

void func_cutscene_70_80076BC8(void) {
}
