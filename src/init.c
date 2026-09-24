#include "common.h"
#include "init.h"
#include "spu.h"
#include "stdutil.h"
#include "str.h"

// psyq
extern int func_8005DB08(void* param_1);
extern int func_8005DB1C(); // CdInit
extern int func_8005E0BC(char param_1, char* param_2, char* param_3);
extern void func_8005D384(); // InitGeom
extern void func_8005D35C(int, int); // SetGeomOffset
extern void func_8005955C(int); // SetGeomScreen

// rodata
extern int* overlayStartPtr; // 80011254

// bss
extern WadHeader wadHeader;

////////////////////////////////////////////////////////////////////////////////////

/**
 * InitSpu() - func_8002A794() - MATCHING
 * https://decomp.me/scratch/7EzZI
 */
void InitSpu() {
    func_8003CCF0();
}

/**
 * InitCdAndWad() - func_8002A7B4() - MATCHING
 * https://decomp.me/scratch/Zz25L
 */
void InitCdAndWad() {
    char sp10[8];

    sp10[0] = 0x80;
    func_8005DB1C();
    func_8005E0BC(0xE, &sp10[0], 0);
    func_8005DB08(&CDReadDone);
    cdState.wadSector = 0x1F4;
    CDLoadSync(0x1F4, overlayStartPtr, 0x800, 0);
    func_8004E7D4((int*)&wadHeader, overlayStartPtr, 0x620);
}

/**
 * SetupDrawDispEnvs() - func_8002A834()
 * https://decomp.me/scratch/YrgPC
 */
/* Retail source: asm/nonmatchings/init/func_8002A834.s,
 * 0x8002A834..0x8002A99C; setup occurs once when called. */
extern char D_8006FBFC;
extern short D_8006FC7A, D_8006FC04, D_8006FC06, D_8006FC78;
extern short D_8006FCD4, D_8006FC60, D_8006FCD6, D_8006FC62;
extern unsigned char D_8006FC14, D_8006FC88, D_8006FC12, D_8006FC86;
extern void* D_8006C600;
void func_8005E500();
void func_8005E5C0();
void func_8002A834(void) {
    char* first;
    register char* second __asm__("$18");
    register int height __asm__("$17");
    VSync(0);
    SetDispMask(0);
    ResetGraph(0);
    SetGraphDebug(0);
    first = &D_8006FBFC;
    {
        register char* a0 __asm__("$4") = first;
        register int a1 __asm__("$5") = 0;
        register int a2 __asm__("$6") = 12;
        register int a3 __asm__("$7") = 512;
        /* Keep the first four argument registers before assigning height. */
        __asm__ volatile ("" : "=r"(a0), "=r"(a1), "=r"(a2), "=r"(a3)
                         : "0"(a0), "1"(a1), "2"(a2), "3"(a3));
        height = 0xD8;
        func_8005E500(a0, a1, a2, a3, height);
    }
    second = first + 0x74;
    func_8005E500(second, 0, 240, 512, height);
    {
        register char* a0 __asm__("$4") = first + 0x5C;
        register int a1 __asm__("$5") = 0;
        register int a2 __asm__("$6") = 228;
        register int a3 __asm__("$7") = 512;
        /* Keep the first four argument registers before assigning height. */
        __asm__ volatile ("" : "=r"(a0), "=r"(a1), "=r"(a2), "=r"(a3)
                         : "0"(a0), "1"(a1), "2"(a2), "3"(a3));
        height = 240;
        func_8005E5C0(a0, a1, a2, a3, height);
    }
    first += 0xD0;
    func_8005E5C0(first, 0, 0, 512, height);
    D_8006FC7A = 228;
    D_8006FC04 = 0;
    D_8006FC06 = 0;
    D_8006FC78 = 0;
    D_8006FCD4 = 0;
    D_8006FC60 = 0;
    D_8006FCD6 = 0;
    D_8006FC62 = 0;
    D_8006FC14 = 1;
    D_8006FC88 = 1;
    D_8006FC12 = 1;
    D_8006FC86 = 1;
    func_8001EBAC();
    VSync(0);
    D_8006C600 = second;
    PutDispEnv((DISPENV*)first);
    PutDrawEnv(D_8006C600);
    SetDispMask(1);
}

/**
 * InitGeom?() - func_8002A99C() - MATCHING
 * https://decomp.me/scratch/853Zu
 */
void func_8002A99C() {
    func_8005D384();
    func_8005D35C(0x100, 0x78);
    func_8005955C(0x155);
}

extern char D_80071438;
extern char D_800718DC;
extern unsigned char D_8006E50C;
extern unsigned char D_8007201C;
extern void func_8005CCFC(void*, void*);
extern void func_8005DC6C(void);
extern void func_8003A9EC(void);
extern void func_8003A40C(void);
extern void* VSyncCallback(void*);
void func_8002A9D0(void) {
    func_8005CCFC(&D_80071438, &D_800718DC);
    func_8005DC6C();
    func_8003A9EC();
    D_8006E50C = 1;
    D_8007201C = 1;
    VSyncCallback((void*)func_8003A40C);
}

/**
 * ???() - func_8002AA34()
 * Not quite there yet, might just be a reordering job
 * Has some very up to date versions of some structs (pauseData v3)
 * https://decomp.me/scratch/jFcXG
 */
/* Retail source: 0x8002AA34..0x8002AAFC. All offsets are raw
 * RAM bytes from the Rev 0 executable; the two clears are 8 and 0x2C00. */
extern int D_800722E0, D_800722E4, D_800722DC, D_800722B8;
extern int D_800722D8, D_800722D4, D_800722D0;
extern int D_8006FC6C, D_8006FCE0, D_8006C638, D_8006C634;
extern int D_80011254;
void func_8002AA34(void) {
    int base = D_800722E0;
    int first = 0x801FF800;
    int span = 0xFFFE4000;
    int* begin;
    int* end;
    D_800722E4 = first;
    D_800722B8 = D_80011254;
    begin = (int*)(base - 0x2C08);
    D_800722DC = base - 0x2C00;
    end = (int*)((int)begin + span);
    D_800722D8 = (int)begin;
    D_800722D4 = (int)end;
    D_800722D0 = (int)end + span;
    D_8006FC6C = D_800722D0;
    D_8006FCE0 = (int)end;
    func_8004E790(begin, 0, 8);
    func_8004E790((void*)D_800722DC, 0, 0x2C00);
    D_8006C638 = D_800722D8;
    D_8006C634 = D_800722DC;
}

/**
 * crc16() - func_8002AAFC() - MATCHING
 * https://decomp.me/scratch/nrPlb
 */
int crc16(unsigned char* data, int in) { // crc16step
  int i = 7;
  int out = in ^ (*data << 8);
  for (i; i >= 0; i--) {
    if (out & 0x8000) {
      out = (out * 2) ^ 0x8005; // 0x8005 = CRC16
    }
    else out *= 2;
  }
  return out;
}

/**
 * Init() - func_8002AB38() - MATCHING
 * Retail title/main CRC checks during initialization.
 * https://decomp.me/scratch/t8DgR
 */
/* Retail source: asm/nonmatchings/init/func_8002AB38.s,
 * 0x8002AB38..0x8002AE00. CRC stepping is once per selected byte. */
extern void main(void);
extern char main_TEXT_END, title_text_end;
extern int D_8006C714, D_8006C7B8, D_8006E470;
extern void ResetCallback(void), func_8004F8EC(void), func_80054E5C(void);
extern int rand(void);
extern void func_title_80074DEC(int), func_title_8007AED8(void);

static inline int crc16ptr(unsigned char* start, unsigned char* end, int in) {
    int sum = in;
    unsigned char* ptr;
    for (ptr = start; ptr < end; ptr += (sum & 3) + 1)
        sum = crc16(ptr, sum);
    return sum;
}
static inline int crc16ptr3(unsigned char* start, unsigned char* end) {
    int sum = 0;
    while (start < end) {
        sum = crc16(start, sum);
        start += (sum & 3) + 1;
    }
    return sum;
}

#define CRC16_RANGE(start, end, check) do { \
    count = 0; p = (unsigned char*)(start); \
    length = (int)(end) - (int)(start); \
    while (count < length) { check = crc16(p, check); p++; count++; } \
    check &= 0xffff; \
} while (0)
#define CRC16_RANGE_RESET(start, end, check) do { \
    p = (unsigned char*)(start); length = (int)(end) - (int)(start); \
    do { check = 0; } while (0); count = 0; \
    while (count < length) { check = crc16(p, check); p++; count++; } \
    check &= 0xffff; \
} while (0)
#define CRC16_RANGE_SECOND(start, end, check) do { \
    p1 = (unsigned char*)(start); length1 = (int)(end) - (int)(start); count1 = 0; \
    while (count1 < length1) { check = crc16(p1, check); p1++; count1++; } \
    check &= 0xffff; \
} while (0)
#define CRC16_RANGE_RESET_SECOND(start, end, check) do { \
    p1 = (unsigned char*)(start); length1 = (int)(end) - (int)(start); \
    count1 = 0; check = 0; \
    while (count1 < length1) { check = crc16(p1, check); p1++; count1++; } \
    check &= 0xffff; \
} while (0)

void func_8002AB38(void) {
    int check;
    unsigned char* p;
    int length;
    int count;
    register unsigned char* p1 __asm__("$16");
    int length1;
    int count1;

    ResetCallback();
    func_8002A834();
    InitSpu();
    InitCdAndWad();
    func_8004F8EC();
    func_8002A99C();
    CDLoadSync(D_8006E470, overlayStartPtr, wadHeader.titleOvl.size, wadHeader.titleOvl.offset);
    D_8006C714 = wadHeader.titleOvl.size;

    check = crc16ptr((unsigned char*)&func_title_80074DEC, (unsigned char*)&title_text_end, 0);
    CRC16_RANGE(&main, &main_TEXT_END, check);
    if (check) ((int*)&InitCdAndWad)[rand() & 0xf] = 0;

    CRC16_RANGE_RESET(&func_title_80074DEC, &title_text_end, check);
    if (check) ((int*)&func_8002A834)[rand() & 0x1f] = 0;

    func_title_80074DEC(1);

    check = crc16ptr3((unsigned char*)&func_title_80074DEC, (unsigned char*)&title_text_end);
    CRC16_RANGE_SECOND(&main, &main_TEXT_END, check);
    if (check) ((int*)&func_8002AB38)[rand() & 0x3f] = 0;

    CRC16_RANGE_RESET_SECOND(&func_title_80074DEC, &title_text_end, check);
    if (check) ((int*)&crc16)[rand() & 0x3f] = 0;
    else func_title_8007AED8();

    D_8006C7B8 = 1;
    func_80054E5C();
}
