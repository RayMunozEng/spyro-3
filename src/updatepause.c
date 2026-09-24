#include "common.h"

/* Retail source: asm/nonmatchings/updatepause/func_800565A0.s,
 * 0x800565A0..0x8005663C. Selector updates once per caller invocation;
 * all branches write a state code to D_8006FBD0. */
extern int D_8006C650;
extern int D_8006C5BC;
extern int D_8006C5C8;
extern int D_8006C508;
extern int D_8006FA38;
extern int D_8006FA3C;
extern int D_8006FBD0;
void func_800565A0(void) {
    register int value __asm__("$2");
    if (D_8006C650 != 0) {
        int kind = D_8006C5BC;
        if (kind == 11 || kind == 22) { value = 6; goto done; }
        value = 5; goto done;
    }
    value = D_8006C5C8;
    if (value > 0) { value = 3; goto done; }
    value = D_8006C508;
    if (value != 0) { value = 1; goto done; }
    value = D_8006FA38;
    if (value < 0) { value = 2; goto done; }
    value = D_8006FA3C;
    if (value != 0) { value = 4; goto done; }
    value = 2;
done:
    __asm__ volatile ("" : "=r"(value) : "0"(value));
    D_8006FBD0 = value;
}INCLUDE_ASM("asm/nonmatchings/updatepause", func_8005663C);

/* Retail source: asm/nonmatchings/updatepause/func_8005693C.s,
 * 0x8005693C..0x800569C0; level table entries have 16-byte stride. */
extern int D_80011254, D_8007013C, D_80070144;
extern int D_8006E470, D_8006C58C, D_80070138, D_80070108;
extern int D_8007015C, D_80072098, D_8006DBE0[];
void func_8004E7D4(void*, int, int);
int CDLoadAsync(int, void*, int, int);
void func_8005693C(void) {
    func_8004E7D4((void*)D_80011254, D_8007013C, D_80070144);
    CDLoadAsync(D_8006E470, (void*)(D_80070108 + D_8007015C),
                D_80070138, D_80072098 + D_8006DBE0[D_8006C58C * 4]);
}

/* Retail source: asm/nonmatchings/updatepause/func_800569C0.s,
 * 0x800569C0..0x80056A3C; the descriptor stride is eight bytes. */
typedef struct { int first, second; } PauseDiscEntry;
extern int D_8006C76C, D_8006FCE0, D_8006E470, D_80070138;
extern PauseDiscEntry D_8006DE68[];
int CDLoadAsync(int, void*, int, int);
void func_800569C0(void) {
    int index = D_8006C76C;
    CDLoadAsync(D_8006E470, (void*)(D_8006FCE0 + 0x8000),
                D_8006DE68[index].second, D_8006DE68[index].first);
    D_80070138 = D_8006DE68[D_8006C76C].second;
}

extern int D_8006DE74;
extern int D_8006DE70;
void func_80056A3C(void) {
    int base = D_8006FCE0;
    int sector = D_8006E470;
    int displacement = 0x8000;
    register int* size __asm__("$16") = &D_8006DE74;
    CDLoadAsync(sector, (void*)(base + displacement), *size, D_8006DE70);
    D_80070138 = *size;
}

INCLUDE_ASM("asm/nonmatchings/updatepause", func_80056A98);

INCLUDE_ASM("asm/nonmatchings/updatepause", func_80056CF0);

INCLUDE_ASM("asm/nonmatchings/updatepause", func_80056ECC);

INCLUDE_ASM("asm/nonmatchings/updatepause", func_80057154);

INCLUDE_ASM("asm/nonmatchings/updatepause", func_80057340);

INCLUDE_ASM("asm/nonmatchings/updatepause", func_80057834);

/**
 * ???() - func_80058408() - MATCHING
 * Ready to add, but there's a weird struct in here
 * Primitive example is in here too
 * https://decomp.me/scratch/5iaVQ
 */
typedef struct {
    unsigned char tag[4];
    unsigned char r0, g0, b0;
    unsigned char code;
    short x0, y0;
    short w, h;
} PauseTile;
extern PauseTile* D_8006C664;
extern int* func_800289C8(void*, short, short);
extern void func_8002ECA8(void);
extern void func_8004E758(PauseTile*);
void func_80058408(void) {
    PauseTile* temp_s0;
    struct {
        char sp10;
        char sp11;
        short sp12;
        signed char sp14;
        char sp15;
        short sp16;
    } unk;
    temp_s0 = D_8006C664;
    unk.sp14 = -1;
    unk.sp15 = 0x7F;
    unk.sp16 = 0x168;
    unk.sp10 = 0;
    unk.sp11 = 0;
    unk.sp12 = 0;
    temp_s0->tag[3] = 3;
    temp_s0->code = 0x60;
    temp_s0->r0 = 1;
    temp_s0->g0 = 1;
    temp_s0->b0 = 1;
    temp_s0->y0 = 0x41;
    temp_s0->x0 = 0x80;
    temp_s0->w = 0x100;
    temp_s0->h = 0x80;
    func_8004E758(temp_s0);
    D_8006C664 = temp_s0 + 1;
    func_800289C8(&unk, 0x80, 0x41);
    func_8002ECA8();
}
