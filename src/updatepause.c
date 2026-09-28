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

extern int D_8006C598, D_8006C648;
extern Moby* D_8006C65C;
extern int D_8006FBC8, D_8006FBCC, D_8006FBD4;
extern unsigned short D_8006E040;
extern Moby* D_8006E788[];
extern int D_8006E78C;
extern unsigned char D_80070115;
extern short D_80070116;
extern int D_80070118, D_8007011C, D_80070120;
extern Vector3D D_80070124;
extern unsigned char D_80070130, D_80070131;
extern signed char D_80070132;
extern short D_80070136, D_80070158;
extern char* (*UpdateParticles)(int);
int func_800359A4(short*, int);
void func_8004F178(Vector3D*, Vector3D*);
void func_80055854(Moby**, int);
void func_80034DAC(Moby*);

/* Retail source: USA Rev 0 PSX.EXE 0x80056ECC..0x80057154 (162 words).
 * Pause state and frame delta are runtime scalar units; camera angle is a
 * signed 12-bit-style value reduced by four fractional bits. This update runs
 * once per paused frame. Confidence is confirmed only by exact instruction and
 * executable comparisons; falsify with any word mismatch in the cited span. */
void func_80056ECC(void) {
    register int offset __asm__("$2");
    int shift;

    if ((D_8006FBC8 == 0x15) && (D_8006FBD4 == 1)) {
        func_8004F178(&D_8006C65C->position, &D_80070124);
    }
    if (D_8006C598 == 0) {
        register short* randomTimer __asm__("$16") = &D_80070116;
        if (func_800359A4(randomTimer, 2) != 0) {
            *randomTimer = (rand() & 0x7F) + 0x1E;
            D_80070115 = rand() & 1;
        }
    }

    D_80070118 = 0x800;
    if (D_8006FBC8 == 3) {
        offset = D_8006FBCC + 8;
    } else {
        offset = D_8006FBCC - 1;
    }
    D_80070120 = 0x6E - offset * 0x87;
    __asm__ volatile ("" ::: "memory");
    {
        register int* coordinate __asm__("$5") = &D_80070120;
        register int vertical __asm__("$3") = D_80070158;
        register unsigned int direction __asm__("$4") = D_80070115;
        vertical -= 5;
        *coordinate += (vertical * 0x87) >> 1;

        if (direction != 0) {
            D_8007011C = 0x1AE;
            D_80070132 = ((short)D_8006E040 >> 4) - 0x40;
        } else {
            D_8007011C = -0x1AE;
            D_80070132 = ((short)D_8006E040 >> 4) + 0x40;
        }
    }

    if (D_80070136 != 0) {
        shift = D_80070136 / 8 - 1;
        if (shift >= 7) {
            shift = 6;
        }
        D_8007011C <<= shift;
    }

    D_80070130 = 0;
    D_80070131 = 0;
    if (D_8006C65C != 0) {
        D_8006E788[0] = D_8006C65C;
        D_8006E78C = 0;
        func_80055854(D_8006E788, 2);
        if (D_8006C648 >= 3) {
            func_80055854(D_8006E788, D_8006C648 + 0x7FFFFFFE);
        }
        func_80034DAC(D_8006C65C);
    }
    if (UpdateParticles != 0) {
        UpdateParticles(D_8006C648);
    }
}

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
