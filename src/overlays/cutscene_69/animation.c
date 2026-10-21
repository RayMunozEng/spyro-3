#include "common.h"
#include "pad.h"

/* Retail-selected 16-byte PadState; shared selector stored at 0x8006C570. */
extern PadState* D_8006C570;

void func_cutscene_69_8007677C(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_69_8007679C(void) {
}

void func_cutscene_69_800767A4(void) {
}

void func_cutscene_69_800767AC(int index) {
    D_8006C570 = &pad.store[index];
}

void func_cutscene_69_800767CC(void) {
}

void func_cutscene_69_800767D4(void) {
}
