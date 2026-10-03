/* SCUS-94467 USA Rev 0: func_800144B4, 0x800144B4..0x80016568.
 * Each call executes the original camera mode dispatcher. Offsets are bytes;
 * signed shifts and integer constants preserve the original instructions.
 * Typed aliases refer to existing retail symbols, allowing this function's
 * access widths without changing declarations used by other matched functions.
 * Empty asm constraints preserve GCC 2.7.2 register allocation and scheduling;
 * they emit no instructions. Verified function SHA-256:
 * f5d210f07cd7821c33fc2980928e77d3c0c34f9a9710c5673a267a0f3464f9d2.
 * Falsifiable check: all 2093 linked words and the 36-entry jump table equal
 * the original disassembly bytes; full EXE and all overlay hashes also match.
 */
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
#define READ2(v) ({register int r asm("$2");r=(v);__asm__ volatile("" : "=r"(r):"0"(r));r;})
#define READ3(v) ({register int r asm("$3");r=(v);__asm__ volatile("" : "=r"(r):"0"(r));r;})
#define READ4(v) ({register int r asm("$4");r=(v);__asm__ volatile("" : "=r"(r):"0"(r));r;})
#define READ5(v) ({register int r asm("$5");r=(v);__asm__ volatile("" : "=r"(r):"0"(r));r;})
#define PRED2(c) READ2(!!(c))
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern s32 cameraUpdate_D_80068B17 asm("D_80068B17");
extern s32 cameraUpdate_D_80068CAC asm("D_80068CAC");
extern s32 cameraUpdate_D_80068F7C asm("D_80068F7C");
extern s32 cameraUpdate_D_80068FB8 asm("D_80068FB8");
extern s32 cameraUpdate_D_80068FE0 asm("D_80068FE0");
extern s32 cameraUpdate_D_80068FE8 asm("D_80068FE8");
extern s32 cameraUpdate_D_80068FEC asm("D_80068FEC");
extern s32 cameraUpdate_D_80068FF0 asm("D_80068FF0");
extern s32 cameraUpdate_D_8006929C asm("D_8006929C");
extern s32 cameraUpdate_D_80069300 asm("D_80069300");
extern s32 cameraUpdate_D_80069314 asm("D_80069314");
extern s32 cameraUpdate_D_80069328 asm("D_80069328");
extern s32 cameraUpdate_D_8006938C asm("D_8006938C");
extern s32 cameraUpdate_D_800693A0 asm("D_800693A0");
extern s32 cameraUpdate_D_800693B4 asm("D_800693B4");
extern s32 cameraUpdate_D_800693C8 asm("D_800693C8");
extern s32 cameraUpdate_D_8006C598 asm("D_8006C598");
extern void *cameraUpdate_D_8006C5A8 asm("D_8006C5A8");
extern s32 cameraUpdate_D_8006C648 asm("D_8006C648");
extern s32 cameraUpdate_D_8006C74C asm("D_8006C74C");
extern s32 cameraUpdate_D_8006C758 asm("D_8006C758");
extern s32 cameraUpdate_D_8006E020 asm("D_8006E020");
extern s32 cameraUpdate_D_8006E038 asm("D_8006E038");
extern s16 cameraUpdate_D_8006E040 asm("D_8006E040");
extern u32 cameraUpdate_D_8006E044 asm("D_8006E044");
extern s32 cameraUpdate_D_8006E048 asm("D_8006E048");
extern s32 cameraUpdate_D_8006E04C asm("D_8006E04C");
extern s32 cameraUpdate_D_8006E050 asm("D_8006E050");
extern u8 cameraUpdate_D_8006E054 asm("D_8006E054");
extern s32 cameraUpdate_D_8006E064 asm("D_8006E064");
extern s32 cameraUpdate_D_8006E074 asm("D_8006E074");
extern s32 cameraUpdate_D_8006E078 asm("D_8006E078");
extern s32 cameraUpdate_D_8006E07C asm("D_8006E07C");
extern s32 cameraUpdate_D_8006E088 asm("D_8006E088");
extern s32 cameraUpdate_D_8006E08C asm("D_8006E08C");
extern s32 cameraUpdate_D_8006E090 asm("D_8006E090");
extern s32 cameraUpdate_D_8006E094 asm("D_8006E094");
extern s32 cameraUpdate_D_8006E098 asm("D_8006E098");
extern s32 cameraUpdate_D_8006E09C asm("D_8006E09C");
extern s32 cameraUpdate_D_8006E0D8 asm("D_8006E0D8");
extern s32 cameraUpdate_D_8006E100 asm("D_8006E100");
extern s32 cameraUpdate_D_8006E114 asm("D_8006E114");
extern s32 cameraUpdate_D_8006E118 asm("D_8006E118");
extern s32 cameraUpdate_D_8006E11C asm("D_8006E11C");
extern s32 cameraUpdate_D_8006E120 asm("D_8006E120");
extern s32 cameraUpdate_D_8006E124 asm("D_8006E124");
extern s32 cameraUpdate_D_8006E128 asm("D_8006E128");
extern s32 cameraUpdate_D_8006E12C asm("D_8006E12C");
extern s32 cameraUpdate_D_8006E130 asm("D_8006E130");
extern s32 cameraUpdate_D_8006E13B asm("D_8006E13B");
extern u8 cameraUpdate_D_8006E13C asm("D_8006E13C");
extern u8 cameraUpdate_D_8006E13D asm("D_8006E13D");
extern s32 cameraUpdate_D_8006E140 asm("D_8006E140");
extern s32 cameraUpdate_D_8006E144 asm("D_8006E144");
extern s32 cameraUpdate_D_8006E148 asm("D_8006E148");
extern s32 cameraUpdate_D_8006E160 asm("D_8006E160");
extern s32 cameraUpdate_D_8006E164 asm("D_8006E164");
extern void *cameraUpdate_D_8006E19C asm("D_8006E19C");
extern s32 cameraUpdate_D_8006E1A0 asm("D_8006E1A0");
extern s32 cameraUpdate_D_8006E1AC asm("D_8006E1AC");
extern s32 cameraUpdate_D_8006E1BC asm("D_8006E1BC");
extern s32 cameraUpdate_D_8006E1C0 asm("D_8006E1C0");
extern s32 cameraUpdate_D_8006E1C4 asm("D_8006E1C4");
extern s32 cameraUpdate_D_8006E1E0 asm("D_8006E1E0");
extern s32 cameraUpdate_D_8006E1E4 asm("D_8006E1E4");
extern s32 cameraUpdate_D_8006E1E8 asm("D_8006E1E8");
extern s32 cameraUpdate_D_8006E344 asm("D_8006E344");
extern s32 cameraUpdate_D_8006E538 asm("D_8006E538");
extern s32 cameraUpdate_D_80070328 asm("D_80070328");
extern s32 cameraUpdate_D_80071900 asm("D_80071900");
void cameraUpdate_func_800135A4(void*,void*,int) asm("func_800135A4");
void cameraUpdate_func_800135F8(void*,void*,void*) asm("func_800135F8");
int cameraUpdate_func_800136F0(void*,void*,void*) asm("func_800136F0");
void cameraUpdate_func_800138A0(void*,void*) asm("func_800138A0");
void cameraUpdate_func_80013900(void*) asm("func_80013900");
void cameraUpdate_func_80013918(int) asm("func_80013918");
void cameraUpdate_func_800142E0(void) asm("func_800142E0");
void cameraUpdate_func_80014354(void) asm("func_80014354");
void cameraUpdate_func_80014450(void) asm("func_80014450");
void cameraUpdate_func_80016764(int) asm("func_80016764");
int cameraUpdate_func_80018368(void*,void*) asm("func_80018368");
int cameraUpdate_func_8001A358(void*,int) asm("func_8001A358");
void cameraUpdate_func_800410F8(void*,void*,int) asm("func_800410F8");
int cameraUpdate_func_8004E880(int,int,int) asm("func_8004E880");
int cameraUpdate_func_8004EDE8(void*,int) asm("func_8004EDE8");
void cameraUpdate_func_8004F08C(void*,int,int) asm("func_8004F08C");
void cameraUpdate_func_8004F110(void*,int) asm("func_8004F110");
void cameraUpdate_func_8004F168(void*) asm("func_8004F168");
void cameraUpdate_func_8004F178(void*,void*) asm("func_8004F178");
void cameraUpdate_func_8004F194(void*,void*,void*) asm("func_8004F194");
void cameraUpdate_func_8004F1C8(void*,void*,void*) asm("func_8004F1C8");
int cameraUpdate_func_8004F284(int,int) asm("func_8004F284");
extern void (*cameraUpdate_unk_ovlheader_80074304)(void) asm("unk_ovlheader_80074304");
extern s8 cameraUpdate_D_8006E138 asm("D_8006E138");
extern s8 cameraUpdate_D_8006E13A asm("D_8006E13A");
extern u16 cameraUpdate_D_8006E1EC asm("D_8006E1EC");
extern u16 cameraUpdate_D_8006E1EE asm("D_8006E1EE");
extern u16 cameraUpdate_D_8006E1F0 asm("D_8006E1F0");
extern s8 cameraUpdate_D_80071834 asm("D_80071834");
extern s32 cameraUpdate_g_CheatFlags asm("g_CheatFlags");

void func_800144B4(void) {
    struct {
        s32 sp10;
        s32 sp14;
        s32 sp18;
        s32 sp1C;
        s32 sp20;
        s32 sp24;
        s32 sp28;
        s32 sp2C;
        s32 sp30;
        s32 sp34;
        s32 sp38;
        s32 sp3C;
        s32 sp40;
        s32 sp44;
        s32 sp48;
        s32 sp4C;
        s32 sp50;
        s32 sp54;
        s32 sp58;
        s32 sp5C;
        s32 sp60;
        s32 sp64;
        s32 sp68;
        s32 sp6C;
    } frame;
    void *temp_s0_10;
    void *temp_s0_2;
    void *temp_s0_5;
    void *temp_s0_7;
    void *temp_s0_8;
    void *temp_s0_9;
    void *temp_s1_2;
    void *temp_s1_3;
    register void *temp_s1_4 asm("$17");
    register void *temp_s1_5 asm("$17");
    void *temp_s1_6;
    void *temp_s2;
    void *temp_s2_2;
    void *var_a0_10;
    void *var_a0_3;
    void *var_a0_4;
    void *var_a0_8;
    void *var_a1;
    register void *var_a1_2 asm("$5");
    register void *var_a1_3 asm("$5");
    register void *var_v1_3 asm("$3");
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_s0;
    s32 temp_s0_11;
    s32 temp_s0_14;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_6;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_10;
    s32 temp_v0_11;
    s32 temp_v0_12;
    s32 temp_v0_13;
    s32 temp_v0_14;
    s32 temp_v0_15;
    s32 temp_v0_16;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v1;
    s32 temp_v1_10;
    s32 temp_v1_11;
    s32 temp_v1_12;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_8;
    s32 temp_v1_9;
    s32 var_a0;
    s32 var_a0_11;
    register s32 var_a0_12 asm("$4");
    register s32 var_a0_2 asm("$4");
    s32 var_a0_5;
    s32 var_a0_6;
    register s32 var_a0_7 asm("$4");
    s32 var_s2;
    register s32 var_v0 asm("$2");
    register s32 var_v0_10 asm("$2");
    register s32 var_v0_11 asm("$2");
    register s32 var_v0_12 asm("$2");
    register s32 var_v0_13 asm("$2");
    s32 var_v0_14;
    s32 var_v0_15;
    s32 var_v0_16;
    register s32 var_v0_17 asm("$2");
    register int counter3 asm("$3");
    s32 var_v0_18;
    s32 var_v0_19;
    s32 var_v0_20;
    s32 var_v0_21;
    s32 var_v0_22;
    s32 var_v0_23;
    register s32 var_v0_2 asm("$2");
    register s32 var_v0_3 asm("$2");
    register s32 var_v0_4 asm("$2");
    register s32 var_v0_5 asm("$2");
    register s32 var_v0_6 asm("$2");
    register s32 var_v0_7 asm("$2");
    register s32 var_v0_8 asm("$2");
    register s32 var_v0_9 asm("$2");
    s32 var_v1;
    s32 var_v1_2;
    void *temp_s0_12;
    void *temp_s0_13;
    void *temp_v1_13;
    void *var_a0_9;
    register void *var_a1_4 asm("$5");
    register int commonZero6 asm("$6");

    register void *init5 asm("$5");
    register int condition2 asm("$2");
        condition2=cameraUpdate_D_8006E13C; init5=&cameraUpdate_D_8006E148;
    __asm__ volatile("" : "=r"(init5) : "0"(init5));
    M2C_FIELD(init5,s32*,0)=0;
    if(condition2==0) goto block_2;
    cameraUpdate_func_800135A4(init5-0xAC,init5-0xD4,0);
block_2:
    var_s2 = (s32) (cameraUpdate_D_8006E130 + 2) >> 2;
    if (var_s2 < 5) {
        goto block_4;
    }
    var_s2 = 4;
block_4:
    if ((u32) cameraUpdate_D_8006E044 >= 0x24U) {
        goto block_305;
    }
    switch (cameraUpdate_D_8006E044) {                            /* jump table: jtbl_80010070 */
case 0:
    cameraUpdate_func_80013918(0x400);
    if (cameraUpdate_D_8006E148 == 0) {
        goto block_9;
    }
    {register int one2 asm("$2");register int mode3 asm("$3");one2=1;mode3=cameraUpdate_D_8006E048;__asm__ volatile("" : "=r"(mode3):"0"(mode3),"r"(one2));
    cameraUpdate_D_8006E13A = one2;__asm__ volatile("" ::: "$2");
    if (mode3 != 1) {
        goto block_10;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) = 0;
    goto block_10; }
block_9:
    cameraUpdate_D_8006E13A = 0;
block_10:
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E12C), s32 *, 0) != 0) {
        goto block_12;
    }
    cameraUpdate_func_80014354();
    goto block_13;
block_12:
    cameraUpdate_D_8006E148 = 0;
block_13:
    cameraUpdate_func_800142E0();
    temp_s0 = var_s2 * 0x14;
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E0D8), temp_s0 + ((void*)&cameraUpdate_D_8006929C), 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E0D8) + 0x14, temp_s0 + ((void*)&cameraUpdate_D_80069328), 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E0D8) + 0x3C, ((void*)&cameraUpdate_D_800693B4), 0);
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) != 1) {
        goto block_16;
    }
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E0D8), s32 *, 0x3C) < 9) {
        goto block_16;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_8006E0D8), s32 *, 0x3C) = 8;
block_16:
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E100), ((void*)&cameraUpdate_D_800693C8), 0);
    if (cameraUpdate_D_8006E050 & 2) {
        goto block_307;
    }
    cameraUpdate_func_800136F0(((void*)&cameraUpdate_D_8006E100) - 0x8C, ((void*)&cameraUpdate_D_8006E100) - 0xE0, ((void*)&cameraUpdate_D_8006E100) - 0xA8);
    cameraUpdate_D_8006E09C = M2C_FIELD(((void*)&cameraUpdate_D_8006E100), s32 *, -0x8C);
    goto block_307;
case 1:
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E12C), s32 *, 0) != 0) {
        goto block_36;
    }
    if (cameraUpdate_D_8006E054 != 0) {
        goto block_23;
    }
    if (cameraUpdate_func_8004F284(M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x64), cameraUpdate_D_8006E074) >= 0x140) {
        goto block_23;
    }
    if ((cameraUpdate_D_8006E538 & 3) == 3) {
        goto block_23;
    }
    cameraUpdate_func_80014450();
    goto block_24;
block_23:
    cameraUpdate_func_80014354();
block_24:
    temp_s0_2 = ((void*)&cameraUpdate_D_80070328) + 0x8C;
    cameraUpdate_func_8004F178(&frame.sp10, temp_s0_2);
    cameraUpdate_func_8004F110(&frame.sp10, 2);
    cameraUpdate_func_8004F194(&frame.sp10, temp_s0_2 - 0x8C, &frame.sp10);
    cameraUpdate_func_8004F1C8(&frame.sp10, &frame.sp10, ((void*)&cameraUpdate_D_8006E020));
    var_a0 = (cameraUpdate_func_8004E880(frame.sp10, frame.sp14, 1) - cameraUpdate_D_8006E040) & 0xFFF;
    if (PRED2(var_a0 < 0x801)) {
        goto block_26;
    }
    var_a0 -= 0x1000;
block_26:
    var_v0 = var_a0 * 2;
{register int product2 asm("$2"); register int factor3 asm("$3");
 product2=var_v0+var_a0;
 factor3=product2<<4; product2+=factor3;
 product2<<=2; product2+=var_a0; var_a0_2=product2>>8; }

    if (var_a0_2 < 0xC1) {
        goto block_28;
    }
    var_a0_2 = 0xC0;

block_28:
    if (var_a0_2 >= -0xC0) {
        goto block_30;
    }
    var_a0_2 = -0xC0;
block_30:
    var_v0_3 = var_a0_2;
    if (var_a0_2 >= 0) {
        goto block_32;
    }
    var_v0_3 = -var_v0_3;
block_32:
    if (var_v0_3 < 9) {
        goto block_34;
    }
    cameraUpdate_D_8006E098 = var_a0_2;
    goto block_35;
block_34:
    cameraUpdate_D_8006E098 = 0;
block_35:
    cameraUpdate_func_80013918(0x400);
block_36:
    cameraUpdate_func_800142E0();
    temp_s0_3 = var_s2 * 0x14;
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E0D8), temp_s0_3 + ((void*)&cameraUpdate_D_8006929C), 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E0D8) + 0x14, temp_s0_3 + ((void*)&cameraUpdate_D_80069328), 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E0D8) + 0x3C, ((void*)&cameraUpdate_D_800693B4), 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E0D8) + 0x28, ((void*)&cameraUpdate_D_800693C8), 0);
    if (cameraUpdate_D_8006E050 & 2) {
        goto block_307;
    }
    cameraUpdate_func_800136F0(((void*)&cameraUpdate_D_8006E0D8) - 0x64, ((void*)&cameraUpdate_D_8006E0D8) - 0xB8, ((void*)&cameraUpdate_D_8006E0D8) - 0x80);
    cameraUpdate_D_8006E09C = M2C_FIELD(((void*)&cameraUpdate_D_8006E0D8), s32 *, -0x64);
    goto block_307;
case 2:
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E12C), s32 *, 0) != 0) {
        goto block_40;
    }
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E12C) - 0xA4, ((void*)&cameraUpdate_D_80068FB8), cameraUpdate_D_8006E064);
block_40:
    cameraUpdate_func_800142E0();
    temp_s1 = var_s2 * 0x14;
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E12C) - 0x54, temp_s1 + ((void*)&cameraUpdate_D_8006929C), 0);
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E12C), s32 *, -0x54) >= 0x100) {
        goto block_42;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_8006E12C), s32 *, -0x54) = 0x100;
block_42:
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E12C) - 0x40, temp_s1 + ((void*)&cameraUpdate_D_80069328), 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E12C) - 0x2C, ((void*)&cameraUpdate_D_800693C8), 0);
    var_a1 = ((void*)&cameraUpdate_D_800693B4);
    var_a0_3 = ((void*)&cameraUpdate_D_8006E12C) - 0x18;
    goto block_147;
case 6:
    cameraUpdate_func_80013918(0x400);
    if (cameraUpdate_D_8006E148 == 0) {
        goto block_45;
    }
    cameraUpdate_D_8006E13A = 1;
    cameraUpdate_D_8006E04C = 0;
    goto block_46;
block_45:
    cameraUpdate_D_8006E13A = 0;
block_46:
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E12C), s32 *, 0) == 0) {
        goto block_48;
    }
    cameraUpdate_D_8006E148 = 0;
block_48:
    cameraUpdate_func_800142E0();
    temp_s0_4 = var_s2 * 0x14;
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E12C) - 0x54, temp_s0_4 + ((void*)&cameraUpdate_D_8006929C), 0);
    var_a0_4 = ((void*)&cameraUpdate_D_8006E12C) - 0x40;
    var_a1_2=((void*)&cameraUpdate_D_80069328);__asm__ volatile("" : "=r"(var_a1_2):"0"(var_a1_2));var_a1_2=(void*)(temp_s0_4+(int)var_a1_2);
    goto block_146;
case 7:
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) == 0) {
        goto block_52;
    }
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) == 1) {
        goto block_59;
    }
    goto block_63;
block_52:
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E12C), s32 *, 0) != 0) {
        goto block_57;
    }
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E048) + 0x40, ((void*)&cameraUpdate_D_80068FE0), cameraUpdate_D_8006E064);
    {register int lhs2 asm("$2");register int rhs3 asm("$3");lhs2=cameraUpdate_D_8006E090;rhs3=cameraUpdate_D_8006E07C;__asm__ volatile("" : "=r"(lhs2),"=r"(rhs3):"0"(lhs2),"1"(rhs3));var_v0_4=lhs2-rhs3;}
    if (var_v0_4 >= 0) {
        goto block_55;
    }
    var_v0_4 = -var_v0_4;
block_55:
    if (var_v0_4 >= 0x200) {
        goto block_57;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) = 2;
block_57:
    {register void* root5 asm("$5");root5=&cameraUpdate_D_8006E13C;__asm__ volatile("" : "=r"(root5):"0"(root5));
    if (M2C_FIELD(root5,u8*,0)==0) goto block_145;
    cameraUpdate_func_800135A4(root5-0xB4,root5-0xC8,0);}

    M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) = 1;
    goto block_145;
block_59:
{register int value2 asm("$2");register int y3 asm("$3");register int z4 asm("$4");register int old5 asm("$5");value2=cameraUpdate_D_80068FE8;y3=cameraUpdate_D_80068FEC;z4=cameraUpdate_D_80068FF0;old5=cameraUpdate_D_8006E07C;__asm__ volatile("" : "=r"(value2),"=r"(y3),"=r"(z4),"=r"(old5):"0"(value2),"1"(y3),"2"(z4),"3"(old5));cameraUpdate_D_8006E090=value2;var_v0_5=value2-old5;
    if (var_v0_5 >= 0) {
        goto block_61;
    }
    var_v0_5 = -var_v0_5;
block_61:
    cameraUpdate_D_8006E094 = y3;
    cameraUpdate_D_8006E098 = z4;
}
    if (var_v0_5 >= 0x200) {
        goto block_145;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) = 2;
    goto block_145;
block_63:
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E12C), s32 *, 0) != 0) {
        goto block_145;
    }
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E12C) - 0xA4, ((void*)&cameraUpdate_D_80068FE0), cameraUpdate_D_8006E064);
    cameraUpdate_func_800410F8(&frame.sp20, ((void*)&cameraUpdate_D_8006E12C) + 0x28, 1);
    if (!(M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x210) & 0x20000)) {
        goto block_71;
    }
    temp_a0 = cameraUpdate_D_8006E140 + ((s32) -frame.sp20 >> 2);
    cameraUpdate_D_8006E140 = temp_a0;
    temp_v0 = cameraUpdate_D_8006E144 + (frame.sp24 >> 2);
    cameraUpdate_D_8006E144 = temp_v0;
    if (temp_v0 >= -0x200) {
        goto block_67;
    }
    cameraUpdate_D_8006E144 = -0x200;
block_67:
    temp_v1 = temp_a0 & 0xFFF;
    if (cameraUpdate_D_8006E144 < 0x201) {
        goto block_69;
    }
    cameraUpdate_D_8006E144 = 0x200;
block_69:
    cameraUpdate_D_8006E140 = temp_v1;
    if (PRED2(temp_v1 < 0x801)) goto block_88;
    var_v0_6=temp_v1-0x1000; goto block_87;
block_71:
    if ((u32) (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) - 3) >= 2U) {
        goto block_80;
    }
    temp_a0_2 = cameraUpdate_D_8006E140 + ((s32) -frame.sp20 >> 2);
    cameraUpdate_D_8006E140 = temp_a0_2;
    temp_v0_2 = cameraUpdate_D_8006E144 + (frame.sp24 >> 2);
    cameraUpdate_D_8006E144 = temp_v0_2;
    if (temp_v0_2 >= -0x200) {
        goto block_74;
    }
    cameraUpdate_D_8006E144 = -0x200;
block_74:

    if (cameraUpdate_D_8006E144 < 0x201) {
        goto block_76;
    }
    cameraUpdate_D_8006E144 = 0x200;

block_76:
    if(temp_a0_2 >= -0x300) {
        goto block_78;
    }
    cameraUpdate_D_8006E140 = -0x300;
block_78:
    if (READ2(cameraUpdate_D_8006E140) < 0x301) goto block_88;
    var_v0_6=0x300;
    goto block_87;
block_80:
    temp_a0_3 = cameraUpdate_D_8006E140 + ((s32) -frame.sp20 >> 1);
    cameraUpdate_D_8006E140 = temp_a0_3;
    temp_v0_3 = cameraUpdate_D_8006E144 + (frame.sp24 >> 1);
    cameraUpdate_D_8006E144 = temp_v0_3;
    if (temp_v0_3 >= -0x3D0) {
        goto block_82;
    }
    cameraUpdate_D_8006E144 = -0x3D0;
block_82:

    if (cameraUpdate_D_8006E144 < 0x501) {
        goto block_84;
    }
    cameraUpdate_D_8006E144 = 0x500;

block_84:
    if(temp_a0_3 >= -0x400) {
        goto block_86;
    }
    cameraUpdate_D_8006E140 = -0x400;
block_86:
    if (READ2(cameraUpdate_D_8006E140) < 0x401) goto block_88;
    var_v0_6=0x400;
block_87:
    cameraUpdate_D_8006E140 = var_v0_6;
block_88:
    {register int *address4 asm("$4"); register int value2 asm("$2"); register int delta3 asm("$3"); register int vertical5 asm("$5");
    address4=&cameraUpdate_D_8006E088; __asm__ volatile("" : "=r"(address4):"0"(address4));
    value2=*address4; delta3=cameraUpdate_D_8006E140; vertical5=cameraUpdate_D_8006E144;
    __asm__ volatile("" : "=r"(value2),"=r"(delta3),"=r"(vertical5):"0"(value2),"1"(delta3),"2"(vertical5));
    value2-=delta3; *address4=value2;
    if(vertical5>=-0x140) goto block_90;
    value2=cameraUpdate_D_8006E08C;delta3=cameraUpdate_D_8006E094;
    value2-=0x140;delta3+=0x140;delta3+=vertical5;
    cameraUpdate_D_8006E08C=value2;cameraUpdate_D_8006E094=delta3; goto block_91;
block_90:
    value2=cameraUpdate_D_8006E08C;value2+=vertical5; cameraUpdate_D_8006E08C=value2;
block_91: ; }
    temp_v1_2 = -cameraUpdate_D_8006E140;
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x190) = temp_v1_2;
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x50) != 0xB) {
        goto block_96;
    }
    if (temp_v1_2 >= -0x140) {
        goto block_94;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x190) = -0x140;
block_94:
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x190) < 0x141) {
        goto block_105;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x190) = 0x140;
    goto block_105;
block_96:
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x50) != 0xA) {
        goto block_101;
    }
    if (temp_v1_2 >= -0x200) {
        goto block_99;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x190) = -0x200;
block_99:
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x190) < 0x201) {
        goto block_105;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x190) = 0x200;
    goto block_105;
block_101:
    if (temp_v1_2 >= -0x300) {
        goto block_103;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x190) = -0x300;
block_103:
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x190) < 0x301) {
        goto block_105;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x190) = 0x300;
block_105:
    temp_v1_3 = -cameraUpdate_D_8006E144;
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x18C) = temp_v1_3;
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x50) != 0xB) {
        goto block_108;
    }
    if (temp_v1_3 >= -0x100) {
        goto block_113;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x18C) = -0x100;
    goto block_113;
block_108:
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x50) != 0xA) {
        goto block_111;
    }
    if (temp_v1_3 >= -0x140) {
        goto block_113;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x18C) = -0x140;
    goto block_113;
block_111:
    if (temp_v1_3 >= -0x200) {
        goto block_113;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x18C) = -0x200;
block_113:
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x18C) < 0x201) {
        goto block_115;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x18C) = 0x200;
block_115:
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x170) == 3) {
        goto block_117;
    }
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x48) != 0x64) {
        goto block_129;
    }
block_117:
    if ((u32) (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) - 3) < 2U) {
        goto block_129;
    }
    var_a0_5 = (cameraUpdate_D_8006E088 - cameraUpdate_D_8006E074) & 0xFFF;
    if (var_a0_5 < 0x801) {
        goto block_120;
    }
    var_a0_5 -= 0x1000;
block_120:
    var_v1 = (cameraUpdate_D_8006E08C - cameraUpdate_D_8006E078) & 0xFFF;
    if (var_v1 < 0x801) {
        goto block_122;
    }
    var_v1 -= 0x1000;
block_122:
    var_v0_9 = var_a0_5;
    if (var_a0_5 >= 0) {
        goto block_124;
    }
    var_v0_9 = -var_v0_9;
block_124:
    if (var_v0_9 >= 0x80) {
        goto block_145;
    }
    var_v0_10 = var_v1;
    if (var_v1 >= 0) {
        goto block_127;
    }
    var_v0_10 = -var_v0_10;
block_127:
    if (var_v0_10 >= 0x80) {
        goto block_145;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) = 3;
    goto block_145;
block_129:
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x1D0) != 0) {
        goto block_132;
    }
    if (M2C_FIELD(&cameraUpdate_g_CheatFlags, u8 *, 3) != 0) {
        goto block_132;
    }
    if (!(M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x210) & 0x20000)) {
        goto block_145;
    }
block_132:
    if (M2C_FIELD(&cameraUpdate_D_80068B17,u8*,M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x48)*4) == 0) {
        goto block_145;
    }
    if ((u32) (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) - 3) < 2U) {
        goto block_145;
    }
    var_a0_6 = (cameraUpdate_D_8006E088 - cameraUpdate_D_8006E074) & 0xFFF;
    if (var_a0_6 < 0x801) {
        goto block_136;
    }
    var_a0_6 -= 0x1000;
block_136:
    var_v1_2 = (cameraUpdate_D_8006E08C - cameraUpdate_D_8006E078) & 0xFFF;
    if (var_v1_2 < 0x801) {
        goto block_138;
    }
    var_v1_2 -= 0x1000;
block_138:
    var_v0_11 = var_a0_6;
    if (var_a0_6 >= 0) {
        goto block_140;
    }
    var_v0_11 = -var_v0_11;
block_140:
    if (var_v0_11 >= 0x80) {
        goto block_145;
    }
    var_v0_12 = var_v1_2;
    if (var_v1_2 >= 0) {
        goto block_143;
    }
    var_v0_12 = -var_v0_12;
block_143:
    if (var_v0_12 >= 0x80) {
        goto block_145;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) = 3;
block_145:
    cameraUpdate_func_800142E0();
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E0D8), ((void*)&cameraUpdate_D_80069300), 0);
    var_a0_4 = ((void*)&cameraUpdate_D_8006E0D8) + 0x14;
    var_a1_2 = ((void*)&cameraUpdate_D_8006938C);
block_146:
    cameraUpdate_func_800135A4(var_a0_4, var_a1_2, 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E114), ((void*)&cameraUpdate_D_800693B4), 0);
    var_a0_3 = ((void*)&cameraUpdate_D_8006E100);
    var_a1 = ((void*)&cameraUpdate_D_800693C8);
block_147:
    cameraUpdate_func_800135A4(var_a0_3, var_a1, 0);
    goto block_307;
case 8: { void* modeRoot;
    cameraUpdate_func_800142E0();
    if ((u32) (cameraUpdate_D_8006E160 - 0xC) >= 2U) {
        goto block_151;
    }
    if (cameraUpdate_D_8006E164 == 0) {
        goto block_151;
    }
    cameraUpdate_func_8004F1C8(&frame.sp28, cameraUpdate_D_8006E164 + 0xC, ((void*)&cameraUpdate_D_80070328));
    cameraUpdate_D_8006E064 = cameraUpdate_func_8004E880(frame.sp28, frame.sp2C, 1);
block_151:
{register void* root16 asm("$16");root16=&cameraUpdate_D_8006E048;__asm__ volatile("" : "=r"(root16):"0"(root16));modeRoot=root16;}
    if (M2C_FIELD(modeRoot, s32 *, 0) == 1) {
        goto block_163;
    }
    if (M2C_FIELD(modeRoot, s32 *, 0) >= 2) {
        goto block_169;
    }
    if (M2C_FIELD(modeRoot, s32 *, 0) != 0) {
        goto block_169;
    }
    if (M2C_FIELD(modeRoot, s32 *, 4) >= 0x3D) {
        goto block_168;
    }
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E12C), s32 *, 0) != 0) {
        goto block_162;
    }
    cameraUpdate_func_80014354();
    if ((((s32*)&cameraUpdate_D_80068CAC))[M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x48)] != 0x1E) {
        goto block_159;
    }
    if (M2C_FIELD(*M2C_FIELD(((void*)&cameraUpdate_D_80070328), void ***, 0x250), s32 *, 0x2C) == 0) {
        goto block_159;
    }
    cameraUpdate_D_8006E090 = 0xC00;
    cameraUpdate_D_8006E08C = 0x400;
    cameraUpdate_D_8006E094 = -0x80;
block_159:
    cameraUpdate_func_800135A4(&frame.sp38, ((void*)&cameraUpdate_D_8006E088), 0);
    temp_s0_5 = ((void*)&cameraUpdate_D_8006E088) - 0x30;
    frame.sp40 += 0x140;
    cameraUpdate_func_800135F8(&frame.sp50, &frame.sp38, temp_s0_5);
    if (cameraUpdate_func_80018368(temp_s0_5, &frame.sp50) == 0) {
        goto block_169;
    }
    cameraUpdate_func_8004F1C8(&frame.sp50, ((void*)&cameraUpdate_D_80071900), temp_s0_5);
    temp_v0_4 = cameraUpdate_func_8004EDE8(&frame.sp50, 1) - 0x140;
    cameraUpdate_D_8006E090 = temp_v0_4;
    if (temp_v0_4 >= cameraUpdate_D_80068FE8) {
        goto block_169;
    }
    cameraUpdate_D_8006E090 = cameraUpdate_D_80068FE8;
    goto block_169;
block_162:
    M2C_FIELD(modeRoot, s32 *, 0) = 1;
    M2C_FIELD(modeRoot, s32 *, 4) = 0;
    goto block_169;
block_163:
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E12C), s32 *, 0) != 0) {
        goto block_169;
    }
{register int value2 asm("$2");register int y3 asm("$3");register int z4 asm("$4");register int old5 asm("$5");value2=cameraUpdate_D_80068FE8;y3=cameraUpdate_D_80068FEC;z4=cameraUpdate_D_80068FF0;old5=cameraUpdate_D_8006E07C;__asm__ volatile("" : "=r"(value2),"=r"(y3),"=r"(z4),"=r"(old5):"0"(value2),"1"(y3),"2"(z4),"3"(old5));cameraUpdate_D_8006E090=value2;var_v0_13=value2-old5;
    if (var_v0_13 >= 0) {
        goto block_166;
    }
    var_v0_13 = -var_v0_13;
block_166:
    cameraUpdate_D_8006E094 = y3;
    cameraUpdate_D_8006E098 = z4;
}
    if (var_v0_13 < 0x200) {
        goto block_168;
    }
    if (cameraUpdate_D_8006E04C < 0x3D) {
        goto block_169;
    }
block_168:
    cameraUpdate_func_800135A4(modeRoot + 0x40, modeRoot + 0x2C, 0);
    M2C_FIELD(modeRoot, s32 *, 0) = 2;
block_169:
    {void* endRoot;{register void* root16 asm("$16");root16=&cameraUpdate_D_8006E148;__asm__ volatile("" : "=r"(root16):"0"(root16));endRoot=root16;}
    M2C_FIELD(endRoot,s32*,0)=0;
    cameraUpdate_func_800135A4(endRoot - 0x70, ((void*)&cameraUpdate_D_80069314), 0);
    cameraUpdate_func_800135A4(endRoot - 0x5C, ((void*)&cameraUpdate_D_800693A0), 0);
    cameraUpdate_func_800135A4(endRoot - 0x48, ((void*)&cameraUpdate_D_800693C8), 0);
    cameraUpdate_D_8006E114 = -1;
    cameraUpdate_D_8006E118 = -1;
    cameraUpdate_D_8006E11C = -1;
    cameraUpdate_D_8006E120 = -1;
    cameraUpdate_D_8006E124 = -1;
    if (cameraUpdate_D_8006E04C >= 0x1E) {
        goto block_307;
    }
    if (cameraUpdate_D_8006E128 < 0x1000) {
        goto block_307;
    }
    if (cameraUpdate_D_8006E160 == 0xD) {
        goto block_307;
    }
    {register int flags2 asm("$2");var_a0_7=0x10000000;__asm__ volatile("" : : "r"(var_a0_7));var_v1_3=((void*)&cameraUpdate_D_80070328)+0x20C;
    flags2=*(s32*)var_v1_3;__asm__ volatile("" : "=r"(flags2):"0"(flags2),"r"(var_v1_3));
    var_a0_7|=0x4000;*(s32*)var_v1_3=flags2|var_a0_7;goto block_307;}

}
}
case 9:
    temp_v0_5 = M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) & ~0x80;
    if (temp_v0_5 == 0) {
        goto block_189;
    }
    if (temp_v0_5 < 0) {
        goto block_283;
    }
    if (temp_v0_5 >= 3) {
        goto block_283;
    }
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E048) + 0x40, ((void*)&cameraUpdate_D_8006E048) + 0x120, 0);
    cameraUpdate_func_8004F178(((void*)&cameraUpdate_D_8006E048) + 0x10, ((void*)&cameraUpdate_D_8006E048) + 0x134);
    cameraUpdate_D_8006E064 = 0;
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x48) != 7) {
        goto block_179;
    }
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x4C) != 0x7F) {
        goto block_179;
    }
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E048) + 0x90, ((void*)&cameraUpdate_D_80069300), 0);
    var_a1_3 = ((void*)&cameraUpdate_D_8006938C);
    var_a0_8 = ((void*)&cameraUpdate_D_8006E048) + 0xA4;
    goto block_180;
block_179:
    temp_s0_6 = var_s2 * 0x14;
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E0D8), temp_s0_6 + ((void*)&cameraUpdate_D_8006929C), 0);
    var_a0_8 = ((void*)&cameraUpdate_D_8006E0D8) + 0x14;
    var_a1_3=((void*)&cameraUpdate_D_80069328);__asm__ volatile("" : "=r"(var_a1_3):"0"(var_a1_3));var_a1_3=(void*)(temp_s0_6+(int)var_a1_3);
block_180:
    cameraUpdate_func_800135A4(var_a0_8, var_a1_3, 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E100), ((void*)&cameraUpdate_D_800693C8), 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E100) + 0x14, ((void*)&cameraUpdate_D_800693B4), 0);
    if ((cameraUpdate_D_8006E048 & ~0x80) != 1) {
        goto block_185;
    }
    temp_v0_6 = 0x100 - ((cameraUpdate_D_8006E04C - 0x10) * 0x10);
    cameraUpdate_D_8006C598 = temp_v0_6;
    if (temp_v0_6 > 0) {
        goto block_183;
    }
    cameraUpdate_D_8006C598 = 0;
    cameraUpdate_D_8006E048 = (cameraUpdate_D_8006E048 & 0x80) | 2;
block_183:
    if (cameraUpdate_D_8006C598 < 0x100) {
        goto block_185;
    }
    cameraUpdate_D_8006C598 = 0xFF;
block_185:
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) != 1) {
        goto block_187;
    }
    cameraUpdate_D_8006C74C = M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0);
    goto block_284;
block_187:
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) != 0x81) {
        goto block_284;
    }
    cameraUpdate_D_8006C74C = 0;
    goto block_283;
block_189:
    temp_v0_7 = cameraUpdate_D_8006E04C * 0x10;
    cameraUpdate_D_8006C598 = temp_v0_7;

    if (temp_v0_7 < 0x100) {
        goto block_191;
    }
    cameraUpdate_D_8006C598 = 0xFF;

block_191:
    if(cameraUpdate_D_8006E04C < 0x11) {
        goto block_284;
    }
    temp_s0_7 = ((void*)&cameraUpdate_D_8006E048) + 0x40;
    M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) = (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) & 0x80) | 1;
    cameraUpdate_func_800135A4(temp_s0_7, ((void*)&cameraUpdate_D_8006E048) + 0x120, 0);
    temp_s2 = ((void*)&cameraUpdate_D_8006E048) + 0x10;
    cameraUpdate_func_8004F178(temp_s2, ((void*)&cameraUpdate_D_8006E048) + 0x134);
    temp_s1_2 = ((void*)&cameraUpdate_D_8006E048) + 0x54;
    cameraUpdate_D_8006E064 = 0;
    cameraUpdate_func_800135A4(temp_s1_2, temp_s0_7, 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E048) + 0x2C, temp_s0_7, 0);
    cameraUpdate_func_80013900(((void*)&cameraUpdate_D_8006E048) + 0x7C);
    temp_s0_8 = ((void*)&cameraUpdate_D_8006E048) + 0x20;
    cameraUpdate_func_800135F8(temp_s0_8, temp_s1_2, temp_s2);
    cameraUpdate_func_8004F178(((void*)&cameraUpdate_D_8006E048) - 0x28, temp_s0_8);
block_193:
    cameraUpdate_D_8006E13D = 0;
    goto block_284;
case 10:
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) == 3) {
        goto block_217;
    }
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) >= 4) {
        goto block_200;
    }
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) == 1) {
        goto block_204;
    }
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) >= 2) {
        goto block_212;
    }
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) == 0) {
        goto block_239;
    }
    goto block_284;
block_200:
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) == 0x81) {
        goto block_232;
    }
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) >= 0x82) {
        goto block_283;
    }
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) == 0x80) {
        goto block_243;
    }
    goto block_284;
block_204:
    temp_v0_8 = 0x100 - ((cameraUpdate_D_8006E04C - 0x10) * 0x10);
    cameraUpdate_D_8006C598 = temp_v0_8;
    if (temp_v0_8 > 0) {
        goto block_206;
    }
    cameraUpdate_D_8006C598 = 0;
    M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) = 2;
block_206:
    if (cameraUpdate_D_8006C598 < 0x100) {
        goto block_208;
    }
    cameraUpdate_D_8006C598 = 0xFF;
block_208:
    cameraUpdate_D_8006C74C = 1;
    if (cameraUpdate_D_8006E344 != 0xE) {
        goto block_254;
    }
    temp_v0_9 = cameraUpdate_D_8006E1A0 + 1;
    cameraUpdate_D_8006E1A0 = temp_v0_9;
    temp_v1_4 = M2C_FIELD(cameraUpdate_D_8006E19C, s32 *, 0);
    if (temp_v0_9 < temp_v1_4) {
        goto block_254;
    }

    if (cameraUpdate_D_8006E1AC & 4) {
        goto block_252;
    }
    {register int limit2 asm("$2");limit2=temp_v1_4-1;__asm__ volatile("# counter 208" : : "r"(limit2));var_v0_15=limit2;}goto block_253;
block_212:
    cameraUpdate_D_8006C74C = 1;
    if (cameraUpdate_D_8006E1AC & 1) {
        goto block_254;
    }
    temp_v0_10 = cameraUpdate_D_8006E1A0 + 1;
    cameraUpdate_D_8006E1A0 = temp_v0_10;
    temp_v1_5 = M2C_FIELD(cameraUpdate_D_8006E19C, s32 *, 0);
    if (temp_v0_10 < temp_v1_5) {
        goto block_254;
    }
    if (cameraUpdate_D_8006E1AC & 4) {
        goto block_252;
    }
    if(cameraUpdate_D_8006E1AC&8){var_v0_15=temp_v1_5-1;goto block_253;}
    var_v0_15=temp_v1_5-1;cameraUpdate_D_8006E1A0=var_v0_15;
    M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) = 0x80;
    cameraUpdate_D_8006E04C = 0;
    goto block_254;
block_217:
    if (cameraUpdate_D_8006E04C < 0x40) {
        goto block_219;
    }
    cameraUpdate_D_8006E04C = 0x40;
    M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) = 2;
block_219:
    frame.sp38 = M2C_FIELD(cameraUpdate_D_8006E19C, u16 *, 4) * 4;
    frame.sp3C = M2C_FIELD(cameraUpdate_D_8006E19C, u16 *, 6) * 4;
    frame.sp40 = M2C_FIELD(cameraUpdate_D_8006E19C, u16 *, 8) * 4;
    frame.sp60 = (s32) M2C_FIELD(cameraUpdate_D_8006E19C, s16 *, 0xA);
    temp_s2_2 = ((void*)&cameraUpdate_D_8006E048) + 0x168;
    frame.sp64 = (s32) M2C_FIELD(cameraUpdate_D_8006E19C, s16 *, 0xC);
    frame.sp68 = (s32) M2C_FIELD(cameraUpdate_D_8006E19C, s16 *, 0xE);
    cameraUpdate_func_8004F1C8(&frame.sp38, &frame.sp38, temp_s2_2);
    temp_v1_6 = (frame.sp60 - cameraUpdate_D_8006E1BC) & 0xFFF;
    frame.sp60 = temp_v1_6;
    if (temp_v1_6 < 0x801) {
        goto block_221;
    }
    frame.sp60 = temp_v1_6 - 0x1000;
block_221:
    temp_v1_7 = (frame.sp64 - cameraUpdate_D_8006E1C0) & 0xFFF;
    frame.sp64 = temp_v1_7;
    if (temp_v1_7 < 0x801) {
        goto block_223;
    }
    frame.sp64 = temp_v1_7 - 0x1000;
block_223:
    temp_v1_8 = (frame.sp68 - cameraUpdate_D_8006E1C4) & 0xFFF;
    frame.sp68 = temp_v1_8;
    if (temp_v1_8 < 0x801) {
        goto block_225;
    }
    frame.sp68 = temp_v1_8 - 0x1000;
block_225:
    cameraUpdate_func_8004F08C(&frame.sp38, 0x40, cameraUpdate_D_8006E04C);
    cameraUpdate_func_8004F08C(&frame.sp60, 0x40, cameraUpdate_D_8006E04C);
    cameraUpdate_func_8004F194(((void*)&cameraUpdate_D_8006E048) + 0x198, &frame.sp38, temp_s2_2);
    temp_v1_9 = (frame.sp60 + cameraUpdate_D_8006E1BC) & 0xFFF;
    cameraUpdate_D_8006E1EC = (u16) temp_v1_9;
    if (temp_v1_9 < 0x801) {
        goto block_227;
    }
    cameraUpdate_D_8006E1EC = temp_v1_9 - 0x1000;
block_227:
    temp_v1_10 = (frame.sp64 + cameraUpdate_D_8006E1C0) & 0xFFF;
    cameraUpdate_D_8006E1EE = (u16) temp_v1_10;
    if (temp_v1_10 < 0x801) {
        goto block_229;
    }
    cameraUpdate_D_8006E1EE = temp_v1_10 - 0x1000;
block_229:
    temp_v1_11 = (frame.sp68 + cameraUpdate_D_8006E1C4) & 0xFFF;
    cameraUpdate_D_8006E1F0 = (u16) temp_v1_11;
    if (temp_v1_11 < 0x801) {
        goto block_231;
    }
    cameraUpdate_D_8006E1F0 = temp_v1_11 - 0x1000;
block_231:
    cameraUpdate_D_8006C74C = 1;
    goto block_284;
block_232:
    temp_v0_11 = 0x100 - ((cameraUpdate_D_8006E04C - 0x10) * 0x10);
    cameraUpdate_D_8006C598 = temp_v0_11;
    if (temp_v0_11 > 0) {
        goto block_234;
    }
    cameraUpdate_D_8006C598 = 0;
    M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) = 0x82;
block_234:
    cameraUpdate_D_8006C74C = 0;
    if (cameraUpdate_D_8006C598 < 0x100) {
        goto block_236;
    }
    cameraUpdate_D_8006C598 = 0xFF;
block_236:
    if (cameraUpdate_D_8006E13D != 0) {
        goto block_254;
    }
    if (cameraUpdate_D_8006E160 != 0) {
        goto block_284;
    }
    cameraUpdate_func_800142E0();
    cameraUpdate_func_80014354();
    goto block_284;
block_239:
    temp_v0_12 = cameraUpdate_D_8006E04C * 0x10;
    cameraUpdate_D_8006C598 = temp_v0_12;

    if (temp_v0_12 < 0x100) {
        goto block_241;
    }
    cameraUpdate_D_8006C598 = 0xFF;

block_241:
    if(cameraUpdate_D_8006E04C < 0x11) {
        goto block_284;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) = 1;__asm__ volatile("" ::: "memory");
    cameraUpdate_D_8006E13D = 1;
    counter3=cameraUpdate_D_8006E1A0; var_v0_17=counter3*2;
    goto block_255;
block_243:
    temp_v0_13 = cameraUpdate_D_8006E04C * 0x10;
    cameraUpdate_D_8006C598 = temp_v0_13;

    if (temp_v0_13 < 0x100) {
        goto block_245;
    }
    cameraUpdate_D_8006C598 = 0xFF;

block_245:
    if(cameraUpdate_D_8006E04C < 0x11) {
        goto block_249;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) = 0x81;
    if (cameraUpdate_D_8006E160 != 0) {
        goto block_248;
    }
    {register void* header4 asm("$4");register int index3 asm("$3");register void* table5 asm("$5");register int offset2 asm("$2");register void* record2 asm("$2");register void* recordArg4 asm("$4");
    {register int flags2 asm("$2");flags2=0x10018000;__asm__ volatile("" : : "r"(flags2):"$16","memory");header4=cameraUpdate_D_8006E19C;__asm__ volatile("" : "=r"(header4):"0"(header4):"$16","memory");temp_s0_9=((void*)&cameraUpdate_D_80070328)+0x20C;M2C_FIELD(temp_s0_9,s32*,0)=flags2;}
    index3=M2C_FIELD(header4,s32*,0);table5=(void*)cameraUpdate_D_8006C758;index3--;
    __asm__ volatile("" : "=r"(index3):"0"(index3),"r"(table5));
    offset2=index3<<1;offset2+=index3;offset2<<=2;record2=table5+offset2;
    offset2=M2C_FIELD(record2,u16*,4);offset2<<=2;__asm__ volatile("" : "=r"(temp_s0_9):"0"(temp_s0_9),"r"(offset2));M2C_FIELD(temp_s0_9,s32*,0x20)=offset2;
    index3=M2C_FIELD(header4,s32*,0);index3--;__asm__ volatile("" : "=r"(index3):"0"(index3));
    offset2=index3<<1;offset2+=index3;offset2<<=2;record2=table5+offset2;
    offset2=M2C_FIELD(record2,u16*,6);temp_s0_10=temp_s0_9+0x20;offset2<<=2;
    M2C_FIELD(((void*)&cameraUpdate_D_80070328),s32*,0x230)=offset2;
    index3=M2C_FIELD(header4,s32*,0);recordArg4=temp_s0_10;__asm__ volatile("" : "=r"(recordArg4):"0"(recordArg4));index3--;__asm__ volatile("" : "=r"(index3):"0"(index3));
    offset2=index3<<1;offset2+=index3;offset2<<=2;table5=table5+offset2;
    offset2=M2C_FIELD(table5,u16*,8);offset2<<=2;M2C_FIELD(((void*)&cameraUpdate_D_80070328),s32*,0x234)=offset2;
    temp_v0_14 = cameraUpdate_func_8001A358(recordArg4,0x1000);
    }
    {register int model3 asm("$3");register void* afterHeader4 asm("$4");model3=M2C_FIELD(((void*)&cameraUpdate_D_80070328),s32*,0x44);__asm__ volatile("" : "=r"(model3):"0"(model3):"$4","memory");afterHeader4=cameraUpdate_D_8006E19C;__asm__ volatile("" : "=r"(afterHeader4):"0"(afterHeader4),"r"(model3):"memory");
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s8 *, 0x228) = 0;
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s8 *, 0x229) = 0;__asm__ volatile("" : "=r"(model3):"0"(model3):"memory");
    M2C_FIELD(((void*)&cameraUpdate_D_80070328),s32*,0x234)=temp_v0_14+model3;
    {register void* header4 asm("$4");register int index3 asm("$3");register int offset2 asm("$2");register void* table3 asm("$3");register void* argument5 asm("$5");
    header4=afterHeader4; index3=M2C_FIELD(header4,s32*,0);argument5=temp_s0_10;index3--;
    __asm__ volatile("" : "=r"(index3):"0"(index3),"r"(argument5));
    offset2=index3<<1;offset2+=index3;table3=(void*)cameraUpdate_D_8006C758;__asm__ volatile("" : "=r"(table3):"0"(table3),"r"(offset2));offset2<<=2;table3=table3+offset2;
    offset2=M2C_FIELD(table3,u16*,0xE);
    M2C_FIELD(((void*)&cameraUpdate_D_80070328),s32*,0x23C)=0;
    M2C_FIELD(((void*)&cameraUpdate_D_80070328),u8*,0x22A)=((unsigned int)offset2)>>4;}
}
    cameraUpdate_func_8004F178(((void*)&cameraUpdate_D_8006E048) + 0x10, temp_s0_10);
    cameraUpdate_D_8006E064 = M2C_FIELD(((void*)&cameraUpdate_D_80070328), u8 *, 0x22A) * 0x10;
    cameraUpdate_func_80014354();
    cameraUpdate_D_8006E138 = 1;
    goto block_193;
block_248:
    cameraUpdate_func_8004F178(((void*)&cameraUpdate_D_8006E048) + 0x10, ((void*)&cameraUpdate_D_80070328));
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E048) + 0x40, ((void*)&cameraUpdate_D_8006E048) + 0x140, 0);
    goto block_193;
block_249:
    if (cameraUpdate_D_8006E160 != 0) {
        goto block_254;
    }
    temp_v0_15 = cameraUpdate_D_8006E1A0 + 1;
    cameraUpdate_D_8006E1A0 = temp_v0_15;
    temp_v1_12 = M2C_FIELD(cameraUpdate_D_8006E19C, s32 *, 0);
    if (temp_v0_15 < temp_v1_12) {
        goto block_254;
    }

    if(!(cameraUpdate_D_8006E1AC&4)){var_v0_15=temp_v1_12-1;goto block_253;}
block_252:
    cameraUpdate_D_8006E1A0 = 0;
    goto block_254;
block_253:
    cameraUpdate_D_8006E1A0 = var_v0_15;
block_254:
    counter3=cameraUpdate_D_8006E1A0; var_v0_17=counter3*2;
block_255:
    temp_v1_13 = cameraUpdate_D_8006E19C + ((var_v0_17+counter3)*4);
    cameraUpdate_D_8006E1E0 = M2C_FIELD(temp_v1_13, u16 *, 4) * 4;
    cameraUpdate_D_8006E1E4 = M2C_FIELD(temp_v1_13, u16 *, 6) * 4;
    cameraUpdate_D_8006E1E8 = M2C_FIELD(temp_v1_13, u16 *, 8) * 4;
    cameraUpdate_D_8006E1EC = M2C_FIELD(temp_v1_13, u16 *, 0xA);
    cameraUpdate_D_8006E1EE = M2C_FIELD(temp_v1_13, u16 *, 0xC);
    cameraUpdate_D_8006E1F0 = M2C_FIELD(temp_v1_13, u16 *, 0xE);
    goto block_284;
case 11:
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) == 0) {
        goto block_264;
    }
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) != 1) {
        goto block_284;
    }
    cameraUpdate_func_800142E0();
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E048) + 0x40, ((void*)&cameraUpdate_D_8006E048) + 0x120, cameraUpdate_D_8006E064);
    temp_s0_11 = var_s2 * 0x14;
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E048) + 0x90, temp_s0_11 + ((void*)&cameraUpdate_D_8006929C), 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E048) + 0xA4, temp_s0_11 + ((void*)&cameraUpdate_D_80069328), 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E048) + 0xB8, ((void*)&cameraUpdate_D_800693C8), 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E048) + 0xCC, ((void*)&cameraUpdate_D_800693B4), 0);
    if (cameraUpdate_D_8006E160 == 9) {
        goto block_260;
    }
    cameraUpdate_D_8006C598 = 0x100 - ((cameraUpdate_D_8006E04C - 0x10) * 0x10);
block_260:
    if (cameraUpdate_D_8006C598 > 0) {
        goto block_262;
    }
    cameraUpdate_D_8006C598 = 0;
    cameraUpdate_D_8006E160 = 0;
block_262:
    cameraUpdate_D_8006C74C = 0;
    if (cameraUpdate_D_8006C598 < 0x100) {
        goto block_284;
    }
    cameraUpdate_D_8006C598 = 0xFF;
    goto block_283;
block_264:
    temp_v0_16 = cameraUpdate_D_8006E04C * 0x10;
    cameraUpdate_D_8006C598 = temp_v0_16;

    if (temp_v0_16 < 0x100) {
        goto block_266;
    }
    cameraUpdate_D_8006C598 = 0xFF;

block_266:
    if(cameraUpdate_D_8006E04C < 0x11) {
        goto block_284;
    }
    temp_s1_3 = ((void*)&cameraUpdate_D_80070328) + 0x23C;
    cameraUpdate_D_80071834 = 0;
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x23C) != 0x29) {
        goto block_269;
    }
    cameraUpdate_func_8004F178(temp_s1_3 - 0x23C, temp_s1_3 - 0x10);
    goto block_273;
block_269:
    cameraUpdate_func_8004F178(&frame.sp60, temp_s1_3 - 0x10);
    frame.sp68 += 0x200;
    frame.sp68 = cameraUpdate_func_8001A358(&frame.sp60, 0x800);
    cameraUpdate_func_8004F178(temp_s1_3 - 0x23C, &frame.sp60);
    if (frame.sp68 != 0) {
        goto block_271;
    }
    var_v0_20 = M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x234);
    goto block_272;
block_271:
    var_v0_20 = M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 8) + 0x164;
block_272:
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 8) = var_v0_20;
block_273:
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x64) = (s32) M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x238);
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x20C) = (s32) (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x20C) | 0x10010480);
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x23C) == 0x29) {
        goto block_275;
    }
    cameraUpdate_D_8006E038 = 0;
block_275:
    cameraUpdate_func_8004F168(((void*)&cameraUpdate_D_80070328) + 0x64 + 0x1B8);
    cameraUpdate_func_800142E0();
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x280) >= 0) {
        goto block_277;
    }
    M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x280) = 0;
block_277:
    M2C_FIELD(((void*)&cameraUpdate_D_8006E13B), s8 *, 0) = 0;
    if (M2C_FIELD(((void*)&cameraUpdate_D_80070328), s32 *, 0x23C) != 0x98) {
        goto block_279;
    }
    cameraUpdate_D_8006E160 = 0;
    cameraUpdate_func_80016764(0x25);
    goto block_284;
block_279:
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E13B), s32 *, 0x41) == 0) {
        goto block_281;
    }
    temp_s0_12 = ((void*)&cameraUpdate_D_8006E13B) - 0xB3;
    cameraUpdate_func_800136F0(temp_s0_12, ((void*)&cameraUpdate_D_8006E13B) + 0x41, ((void*)&cameraUpdate_D_8006E13B) - 0xE3);
    cameraUpdate_func_800138A0(temp_s0_12, temp_s0_12);
    var_a0_9 = ((void*)&cameraUpdate_D_8006E13B) + 0x2D;
    var_a1_4 = temp_s0_12;__asm__ volatile("" : "=r"(var_a1_4):"0"(var_a1_4));
{register int value2 asm("$2");register int delta3 asm("$3");value2=M2C_FIELD(((void*)&cameraUpdate_D_8006E13B),s32*,-0xB3);delta3=cameraUpdate_D_8006E064;__asm__ volatile("" : "=r"(value2),"=r"(delta3):"0"(value2),"1"(delta3):"memory");commonZero6=0;__asm__ volatile("" : "=r"(commonZero6):"0"(commonZero6));value2+=delta3;value2&=0xFFF;M2C_FIELD(((void*)&cameraUpdate_D_8006E13B),s32*,-0xB3)=value2;}
    goto block_282;
block_281:
    temp_s0_13 = ((void*)&cameraUpdate_D_8006E13B) + 0x2D;
    cameraUpdate_func_800135A4(temp_s0_13, ((void*)&cameraUpdate_D_80068F7C), cameraUpdate_D_8006E064);
    var_a0_9 = ((void*)&cameraUpdate_D_8006E13B) - 0xB3;
    var_a1_4 = temp_s0_13;__asm__ volatile("" : "=r"(var_a1_4):"0"(var_a1_4));
{register int value2 asm("$2");register int delta3 asm("$3");value2=M2C_FIELD(((void*)&cameraUpdate_D_8006E13B),s32*,0x2D);delta3=cameraUpdate_D_8006E064;__asm__ volatile("" : "=r"(value2),"=r"(delta3):"0"(value2),"1"(delta3):"memory");commonZero6=0;__asm__ volatile("" : "=r"(commonZero6):"0"(commonZero6));value2-=delta3;value2&=0xFFF;M2C_FIELD(((void*)&cameraUpdate_D_8006E13B),s32*,0x2D)=value2;}
block_282:
    cameraUpdate_func_800135A4(var_a0_9,var_a1_4,commonZero6);
{register void* tailRoot asm("$16");tailRoot=&cameraUpdate_D_8006E09C;__asm__ volatile("" : "=r"(tailRoot):"0"(tailRoot));
    {register void* arg4 asm("$4");arg4=tailRoot;__asm__ volatile("" : "=r"(arg4):"0"(arg4));temp_s1_4=tailRoot-0x14;cameraUpdate_func_800135A4(arg4,temp_s1_4,cameraUpdate_D_8006E064);}

    cameraUpdate_func_800135A4(tailRoot - 0x28, temp_s1_4, cameraUpdate_D_8006E064);
    cameraUpdate_func_80013900(tailRoot + 0x28);
    temp_s1_5 = tailRoot - 0x34;
    cameraUpdate_func_800135F8(temp_s1_5, tailRoot, tailRoot - 0x44);
    cameraUpdate_func_8004F178(tailRoot - 0x7C, temp_s1_5);
}
    M2C_FIELD(((void*)&cameraUpdate_D_8006E12C), s32 *, 0) = 0;
    cameraUpdate_D_8006E130 = 0;
    cameraUpdate_D_8006E13D = 0;
    M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) = 1;
block_283:
block_284:
    var_a0_7=0x10000000;var_v1_3=((void*)&cameraUpdate_D_80070328)+0x20C;
block_285:
    {register int flags2 asm("$2");flags2=*(s32*)var_v1_3;__asm__ volatile("" : "=r"(flags2):"0"(flags2),"r"(var_a0_7));var_a0_7|=2;*(s32*)var_v1_3=flags2|var_a0_7;}

    goto block_307;
case 18: {register void* caseRoot17 asm("$17");caseRoot17=&cameraUpdate_D_8006E12C;__asm__ volatile("" : "=r"(caseRoot17):"0"(caseRoot17));
{register void* first4 asm("$4");register int condition2 asm("$2");condition2=M2C_FIELD(caseRoot17,s32*,0);first4=caseRoot17-0xA4;if(condition2!=0)goto block_288;cameraUpdate_func_800135A4(first4,caseRoot17+0x3C,cameraUpdate_D_8006E064);}
block_288:
    var_a0_10 = caseRoot17 - 0x54;
    if (M2C_FIELD(((void*)&cameraUpdate_D_8006E048), s32 *, 0) != 0) {
        goto block_290;
    }
    cameraUpdate_func_800142E0();__asm__ volatile("" : "=r"(caseRoot17):"0"(caseRoot17));
    cameraUpdate_D_8006E064 = (M2C_FIELD(cameraUpdate_D_8006C5A8, u8 *, 0x46) * 0x10) + 0x800;__asm__ volatile("" ::: "$4","memory");
    var_a0_10 = caseRoot17 - 0x54;
block_290:
    temp_s0_14 = var_s2 * 0x14;
    cameraUpdate_func_800135A4(var_a0_10, temp_s0_14 + ((void*)&cameraUpdate_D_8006929C), 0);
    cameraUpdate_func_800135A4(caseRoot17 - 0x40, temp_s0_14 + ((void*)&cameraUpdate_D_80069328), 0);
    cameraUpdate_func_800135A4(caseRoot17 - 0x2C, ((void*)&cameraUpdate_D_800693C8), 0);
    cameraUpdate_func_800135A4(caseRoot17 - 0x18, ((void*)&cameraUpdate_D_800693B4), 0);
    if (cameraUpdate_D_8006E050 & 2) {
        goto block_307;
    }
    cameraUpdate_func_800136F0(caseRoot17 - 0xB8, caseRoot17 - 0x10C, caseRoot17 - 0xD4);
    cameraUpdate_D_8006E09C = M2C_FIELD(caseRoot17, s32 *, -0xB8);
    goto block_307;
}
case 35:
    cameraUpdate_func_80014354();
    temp_s1_6 = ((void*)&cameraUpdate_D_80070328) + 0x8C;
    cameraUpdate_func_8004F178(&frame.sp60, temp_s1_6);
    cameraUpdate_func_8004F110(&frame.sp60, 2);
    cameraUpdate_func_8004F194(&frame.sp60, temp_s1_6 - 0x8C, &frame.sp60);
    cameraUpdate_func_8004F1C8(&frame.sp60, &frame.sp60, ((void*)&cameraUpdate_D_8006E020));
    var_a0_11 = (cameraUpdate_func_8004E880(frame.sp60, frame.sp64, 1) - cameraUpdate_D_8006E040) & 0xFFF;
    if (PRED2(var_a0_11 < 0x801)) {
        goto block_294;
    }
    var_a0_11 -= 0x1000;
block_294:
    var_v0_21 = var_a0_11 * 2;
{register int product2 asm("$2"); register int factor3 asm("$3");
 product2=var_v0_21+var_a0_11;
 factor3=product2<<4; product2+=factor3;
 product2<<=2; product2+=var_a0_11; var_a0_12=product2>>8; }

    if (var_a0_12 < 0xC1) {
        goto block_296;
    }
    var_a0_12 = 0xC0;

block_296:
    if(var_a0_12>=-0xC0) {
        goto block_298;
    }
    var_a0_12 = -0xC0;
block_298:
    var_v0_23 = var_a0_12;
    if (var_a0_12 >= 0) {
        goto block_300;
    }
    var_v0_23 = -var_v0_23;
block_300:
    if (var_v0_23 < 9) {
        goto block_302;
    }
    cameraUpdate_D_8006E098 = var_a0_12;
    goto block_303;
block_302:
    cameraUpdate_D_8006E098 = 0;
block_303:
    cameraUpdate_func_800142E0();
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E0D8), ((void*)&cameraUpdate_D_80069300), 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E0D8) + 0x14, ((void*)&cameraUpdate_D_8006938C), 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E0D8) + 0x3C, ((void*)&cameraUpdate_D_800693B4), 0);
    cameraUpdate_func_800135A4(((void*)&cameraUpdate_D_8006E0D8) + 0x28, ((void*)&cameraUpdate_D_800693C8), 0);
    if (cameraUpdate_D_8006E050 & 2) {
        goto block_307;
    }
    cameraUpdate_func_800136F0(((void*)&cameraUpdate_D_8006E0D8) - 0x64, ((void*)&cameraUpdate_D_8006E0D8) - 0xB8, ((void*)&cameraUpdate_D_8006E0D8) - 0x80);
    cameraUpdate_D_8006E09C = M2C_FIELD(((void*)&cameraUpdate_D_8006E0D8), s32 *, -0x64);
    goto block_307;
case 3:
case 4:
case 5:
case 12:
case 13:
case 14:
case 15:
case 16:
case 17:
case 19:
case 20:
case 21:
case 22:
case 23:
case 24:
case 25:
case 26:
case 27:
case 28:
case 29:
case 30:
case 31:
case 32:
case 33:
case 34:
block_305:
    if (cameraUpdate_unk_ovlheader_80074304 == 0) {
        goto block_307;
    }
    cameraUpdate_unk_ovlheader_80074304();
block_307:
{register int* count2 asm("$2");register int count3 asm("$3");register int cadence4 asm("$4"); count2=&cameraUpdate_D_8006E04C; __asm__ volatile("" : "=r"(count2):"0"(count2)); count3=*count2; cadence4=READ4(cameraUpdate_D_8006C648); count3+=cadence4; *count2=count3;}
    return;
}
}

#undef READ2
#undef READ3
#undef READ4
#undef READ5
#undef PRED2
#undef M2C_FIELD
