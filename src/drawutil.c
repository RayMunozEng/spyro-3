#define PRED2(x) ({ register int predicate2 asm("$2"); predicate2=(x); __asm__("" : "=r"(predicate2) : "0"(predicate2)); predicate2; })
#define SCALE_BYTE(p,field,b) ({ register int value2 asm("$2"); register int scale3 asm("$3"); register int low9 asm("$9"); scale3=(b); value2=(p)->field; low9=value2*scale3; value2=low9>>8; value2; })
#define READ9(x) ({ register int reload9 asm("$9"); reload9=(x); __asm__("" : "=r"(reload9) : "0"(reload9)); reload9; })
#include "common.h"
#include "drawutil.h"
#include "hud.h"
#include "mobyfunc.h"
#include "stdutil.h"

extern void VSync(int);
extern int D_8006C668;

extern char D_80067570[16][12]; // might be an array of structs, not sure
extern PauseData pauseData; // 8006fbc4

////////////////////////////////////////////////////////////////////////////////////

// I'm using the REORDER_HACK in here which should just equal the normal INCLUDE_ASM right now
// At time of writing this is a file that would fail when changing to -G8 so this is just saving me time later

/**
 * ???() - func_8001EBAC() - MATCHING
 * https://decomp.me/scratch/v2ehU
 */
void func_8001EBAC() {
    RECT rect;

    DrawSync(0);
    VSync(0);
    rect.x = 0;
    rect.y = 0;
    rect.w = 512;
    rect.h = 240;
    ClearImage(&rect, 0, 0, 0);
    rect.y = 228;
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
}

void func_8001EC24(void) {
    func_8004E7AC((char*)D_8006C668 - 0x3000, 0, 0x1C00);
    func_80022378();
}

/* Retail source: asm/nonmatchings/drawutil/func_8001EC5C.s,
 * 0x8001EC5C..0x8001EDEC; calls occur once per function invocation. */
extern char D_80070328[];
extern int D_8006E344, D_8006C4F8;
extern unsigned char D_80071834;
long long func_8001EC5C(void) {
    int saved;
    unsigned char oldMode;
    int mode;
    func_8004E7AC((char*)D_8006C668 - 0x3000, 0, 0xC00);
    func_80030478();
    func_80031124();
    func_80033C5C();
    func_8002DDA8();
    if (*(int*)(D_80070328 + 0x288) == 0) {
        if (D_8006E344 != 13 || D_8006C4F8 == 2) {
            saved = *(int*)(D_80070328 + 0x2C);
            if (saved != 0) {
                int x = *(int*)(D_80070328 + 8);
                int y = *(int*)(D_80070328 + 0x10C);
                oldMode = D_80070328[0x1E];
                *(int*)(D_80070328 + 8) = x - saved * 2;
                mode = func_80040954(y);
                D_80070328[0x1E] = mode == 4 ? 0xFA : 0xF4;
                func_8003CDA0();
                {
                    extern int drawCounter __asm__("D_80070328+44");
                    extern int drawPosition __asm__("D_80070328+8");
                    register int offset __asm__("$2") = drawCounter;
                    register int* pos __asm__("$4") = &drawPosition;
                    drawCounter = 0;
                    D_80070328[0x1E] = oldMode;
                    *pos += offset * 2;
                }
            }
            func_8003CDA0();
            func_8002D9BC();
            if (D_80071834 != 0) {
                func_8002D2C4();
            }
            *(int*)(D_80070328 + 0x2C) = saved;
        }
    }
    if (D_8006E344 == 6 && D_80071834 != 0) {
        func_8002D2C4();
    }
}

#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
#define MULT_HI(a,b) ({ int high; __asm__ volatile("" : "=h"(high) : "l"((int)(a)*(int)(b)) : "memory"); high; })
extern int D_8006C5BC;
void func_8001C8C8(int);             /* extern */
int func_8004E9E4(int);                             /* extern */
int func_8004EA2C(short);                             /* extern */
int func_8004ED6C(int *, int *, int *);     /* extern */
int func_8004EDE8(int *, int);                  /* extern */
int func_8004F0E8(int *, int);              /* extern */
int func_8004F110(int *, int);              /* extern */
int func_8004F168(Vector3D *);                  /* extern */
void func_8004F1C8(Vector3D *, void *, Vector3D *); /* extern */
int func_8004F2C8(short, short);                        /* extern */
int func_8004F408(Vector3D *, int *, int);      /* extern */
int func_8004F4BC(int, int, int);                   /* extern */
extern int D_80065920;
extern int D_8006C530;
extern int D_8006C5E0;
extern int D_8006C644;
extern int D_8006E00C;
extern Vector3D D_8006E020;
extern int D_8006E024;
extern int D_8006ED88;
extern int D_8006ED8C;
extern int D_8006ED90;
extern int D_8006ED94;
extern int D_8006ED98;
extern int D_8006ED9C;
extern short D_8006EDA0;
extern short D_8006EDA2;
extern short D_8006EDA4;
extern short D_8006EDA6;
extern int D_8006EDA8;
extern int D_8006EDAC;

/* SCUS-94467 USA Rev 0: 0x8001EDEC..0x8001FABC (820 instructions).
 * Reconstructed from asm/nonmatchings/drawutil/func_8001EDEC.s.
 * Integer widths, signed division, shifts and stack byte offsets follow retail.
 * Work runs once per invocation. Instruction-free compiler constraints retain
 * register/HI/LO scheduling; fix_coff_debug.py preserves load-delay labels.
 * Acceptance vector: linked executable and all overlay retail SHA-256 hashes.
 */
void func_8001EDEC(void) {
    struct {
        Vector3D v10; int gap1c;
        Vector3D v20; int gap2c;
        Vector3D v30; int gap3c;
        Vector3D v40; int gap4c[7];
        Vector3D v68[5]; int gapa4;
        int a8[5]; int gapbc;
        int c0[5]; int gapd4;
        Vector3D vd8; int gape4;
        Vector3D ve8; int gapf4;
        int f8; int gapfc;
        volatile int f100; int gap104;
        int f108; int gap10c;
        volatile int f110; int gap114;
        volatile int f118; int gap11c;
        Vector3D *volatile f120; int gap124;
        volatile int f128; int gap12c;
        volatile int f130; int gap134;
        int f138; int gap13c;
        Vector3D *volatile f140; int gap144;
        int *volatile f148; int gap14c[5];
        volatile int f160;
    } frame;
    Vector3D *var_a1;
    register int projection6 asm("$6");
    register Vector3D *projection4 asm("$4"); register Vector3D *projection5 asm("$5");
    Vector3D *var_a2;
    register Vector3D *add4 asm("$4"), *add5 asm("$5");
    register Vector3D *var_s0_3 asm("$16");
    register int *temp_a0_6 asm("$4");
    register int *temp_s1 asm("$17");
    register int *temp_s6 asm("$22");
    int *var_a2_2;
    int *var_v1;
    int *var_v1_2;
    int temp_a0_4;
    int temp_a0_5;
    int temp_a1_3;
    int temp_a1_4;
    int temp_a2;
    int temp_a2_3;
    int temp_a3;
    register int firstAngle2 asm("$2");
    register int temp_s0 asm("$16");
    int temp_s0_2;
    register int temp_s0_3 asm("$16");
    register int temp_t1 asm("$9");
    register int temp_t1_2 asm("$9");
    register int temp_t1_3 asm("$9");
    register int temp_v0_2 asm("$2");
    register int temp_v0_3 asm("$2");
    int temp_v1_4;
    register int var_a0 asm("$4");
    int var_a1_2;
    register int var_a3 asm("$7");
    register int var_fp asm("$30");
    register int var_s0 asm("$16");
    register int var_s0_2 asm("$16");
    register int var_s1 asm("$17");
    register short portalAngle17 asm("$17");
    register int var_s1_2 asm("$17");
    register int var_s1_3 asm("$17");
    register int var_s2 asm("$18");
    register int var_s2_2 asm("$18");
    register int var_s3 asm("$19");
    register int offset20 asm("$20");
    register Vector3D *work19 asm("$19");
    register int *edgeBase20 asm("$20");
    Vector3D *edgeLeft30;
    register Vector3D *edgeRight23 asm("$23");
    register int var_s5 asm("$21");
    register int var_s5_2 asm("$21");
    register int var_s6 asm("$22");
    register int var_s7 asm("$23");
    register int var_t1 asm("$9");
    int var_v0;
    int var_v0_2;
    register int var_v0_3 asm("$2");
    register int var_v0_4 asm("$2");
    int var_v0_5;
    unsigned short *temp_v1_3;
    register unsigned int temp_v0 asm("$2");
    register void *temp_a0 asm("$4");
    register void *temp_a0_2 asm("$4");
    register void *temp_a0_3 asm("$4");
    void *temp_a1;
    register void *temp_a1_2 asm("$5");
    register void *temp_a2_2 asm("$6");
    void *temp_a3_2;
    void *temp_v0_4;
    register void *temp_v1 asm("$3");
    register void *temp_v1_2 asm("$3");

    /* Flowgraph is not reducible, falling back to gotos-only mode. */
    frame.f8 = 0;
    if (D_8006C5E0 <= 0) {
        goto block_103;
    }
    {
        register int init9 asm("$9");
        init9 = (int)&frame.v20;
        __asm__("" : "=r"(init9) : "0"(init9));
        frame.f120 = (Vector3D *)init9;
        init9 = 0x66666667;
        __asm__("" : "=r"(init9) : "0"(init9));
        frame.f128 = init9;
        init9 = (int)&frame.v68[0];
        __asm__("" : "=r"(init9) : "0"(init9));
        frame.f140 = (Vector3D *)init9;
        init9 = (int)&frame.v10.x;
        __asm__("" : "=r"(init9) : "0"(init9));
        frame.f148 = (int *)init9;
    }
    frame.f160 = 0;
    do {
loop_2:
    { register int base2 asm("$2");
      register int offset9 asm("$9");
      base2 = D_8006C530;
      var_t1 = frame.f160;
      __asm__("" : "=r"(var_t1) : "0"(var_t1), "r"(base2));
      temp_v1 = (void *)(var_t1 + base2);
    }
    if (M2C_FIELD(temp_v1, unsigned char *, 0x40) == 0) {
        goto block_101;
    }
    temp_v0 = M2C_FIELD(temp_v1, unsigned char *, 0x43);
    __asm__("" : "=r"(temp_v0) : "0"(temp_v0));
    if (temp_v0 == 0) {
        goto block_9;
    }
{ register Vector3D *address4 asm("$4"); address4=&frame.v10; __asm__ volatile("" : : "r"(address4)); }
    var_s0 = temp_v0 + 0x10;
    __asm__("" : "=r"(var_s0) : "0"(var_s0));
    if (var_s0 < 0x100) {
        goto block_6;
    }
    var_s0 = 0;
block_6:
    M2C_FIELD(temp_v1, unsigned char *, 0x43) = (unsigned char) var_s0;
    func_8004F168(&frame.v20);
    var_s0_2 = 0;
    var_s1 = 0;
    var_s2 = frame.f160;
    __asm__("" : "=r"(var_s0_2), "=r"(var_s1), "=r"(var_s2) : "0"(var_s0_2), "1"(var_s1), "2"(var_s2));
    do {
loop_7:
    var_s0_2 += 1;
    func_8004F194(frame.f120, frame.f120, (Vector3D *)(D_8006C530 + var_s2 + var_s1));
    var_s1 += 0xC;
    } while (var_s0_2 < 5);
    { register int x3 asm("$3"); register int y4 asm("$4");
      register int z5 asm("$5"); register int magic9 asm("$9");
      register int high8 asm("$8"); register int high6 asm("$6");
      register int high7 asm("$7"); register int value2 asm("$2");
      x3=frame.v20.x; magic9=frame.f128;
      high8=MULT_HI(x3,magic9);
      y4=frame.v20.y;
      high6=MULT_HI(y4,magic9);
      z5=frame.v20.z;
      high7=MULT_HI(z5,magic9);
      x3 >>= 31; value2=(high8>>1)-x3; y4>>=31; frame.v20.x=value2;
      value2=(high6>>1)-y4; z5>>=31; frame.v20.y=value2;
      value2=(high7>>1)-z5; frame.v20.z=value2;
    }
    __asm__ volatile("" ::: "$4","memory");
    {register Vector3D *setup4 asm("$4"); setup4=&frame.v10;
     __asm__ volatile("" : "=r"(setup4) : "0"(setup4));}
block_9:
    { register Vector3D *address4 asm("$4");
      register int base5 asm("$5");
      register int offset9 asm("$9");
      register Vector3D *camera6 asm("$6");
      __asm__ volatile("" : "=r"(address4));
      base5 = D_8006C530;
      offset9 = frame.f160;
      __asm__("" : "=r"(offset9) : "0"(offset9), "r"(base5));
      camera6 = &D_8006E020;
      __asm__("" : "=r"(camera6) : "0"(camera6));
      func_8004F1C8(address4, (void *)(base5 + offset9 + 24), camera6);
    }
    frame.v10.z -= 0x540;
    func_8004F110(&frame.v10.x, 2);
    { register int *matrix4 asm("$4");
      matrix4 = &D_8006E00C;
      __asm__("" : "=r"(matrix4) : "0"(matrix4));
      func_8004ED6C(matrix4, &frame.v10.x, &frame.v10.x);
    }
    func_8004F0E8(&frame.v10.x, 2);
    { register int position4 asm("$4");
      position4 = frame.v10.x;
      __asm__("" : "=r"(position4) : "0"(position4));
      if (position4 < -0x7FF) {
        goto block_100;
    }
    { register int base2 asm("$2");
      base2 = D_8006C530;
      var_t1 = frame.f160;
      __asm__("" : "=r"(var_t1) : "0"(var_t1), "r"(base2));
      temp_a1 = (void *)(var_t1 + base2);
    }
    if (position4 >= (M2C_FIELD(temp_a1, unsigned char *, 0x40) << 0xA)) {
        goto block_101;
    }
    if ((frame.v10.y - 0xA00) >= position4) {
        goto block_101;
    }
    if (-(frame.v10.y + 0x800) >= position4) {
        goto block_101;
    }
    if (position4 >= 0) {
        goto block_15;
    }
    frame.v10.x = 0;
    }
block_15:
    { register int x3 asm("$3"); register int shifted2 asm("$2");
      register int left7 asm("$7"); register int x4 asm("$4");
      register int right2 asm("$2"); register int y5 asm("$5");
      register int one6 asm("$6");
      x3=frame.v10.x;
      one6=1;
      shifted2=x3>>7; x3=-(x3>=0x4000);
      __asm__("" : "=r"(x3), "=r"(shifted2) : "0"(x3), "1"(shifted2));
      D_8006ED9C=shifted2;
      left7=M2C_FIELD(temp_a1,int *,0x30);
      x4=M2C_FIELD(temp_a1,int *,0);
      right2=M2C_FIELD(temp_a1,int *,0x34);
      y5=M2C_FIELD(temp_a1,int *,4);
      frame.f100=x3&3;
      x4=left7-x4; y5=right2-y5;
      firstAngle2=func_8004E880(x4,y5,one6);
    }
    { register int base3 asm("$3"); register int offset9 asm("$9");
      register int cameraX8 asm("$8"); register int cameraY7 asm("$7");
      register int inputX4 asm("$4"); register int inputY5 asm("$5");
      register int one6 asm("$6"); register int angleResult2 asm("$2");
      one6=1;
      __asm__("" : "=r"(one6),"=r"(firstAngle2) : "0"(one6),"1"(firstAngle2));
      temp_s0=firstAngle2;
      base3=D_8006C530; offset9=frame.f160;
      __asm__("" : "=r"(offset9) : "0"(offset9), "r"(base3));
      cameraX8=D_8006E020.x; cameraY7=D_8006E024;
      base3=offset9+base3;
      inputX4=M2C_FIELD(base3,int *,0x18); inputY5=M2C_FIELD(base3,int *,0x1C);
      inputX4=cameraX8-inputX4; inputY5=cameraY7-inputY5;
      angleResult2=func_8004E880(inputX4,inputY5,one6);
      temp_s0 <<=16;portalAngle17=temp_s0>>16;
      temp_v0_2=func_8004F2C8(portalAngle17,angleResult2);
    }
    frame.f110 = temp_v0_2;
    if ((unsigned int) (temp_v0_2 + 0x40) < 0x81U) {
        goto block_100;
    }
    { register int angle9 asm("$9"); angle9=frame.f110; __asm__("" : "=r"(angle9) : "0"(angle9));
    if ((unsigned int) (angle9 + 0x7BF) >= 0xF7FU) {
        goto block_100;
    }
    if (angle9 >= 0) {
        goto block_19;
    }
    { register int base2 asm("$2"); base2=D_8006C530; var_t1=frame.f160;
      __asm__("" : "=r"(var_t1) : "0"(var_t1), "r"(base2));
      base2 = var_t1+base2; var_t1 += 0x44;
      if (M2C_FIELD(base2, unsigned char *, 0x41) == 0) {
        goto block_102;
    }
    }
    }
block_19:
    temp_a0=(void*)D_8006C530;
    __asm__ volatile("" : "=r"(temp_a0) : "0"(temp_a0) : "memory");
    var_t1=frame.f160; temp_a0=(void*)(var_t1+(int)temp_a0);
    frame.v30.x = D_8006E020.x - M2C_FIELD(temp_a0, int *, 0x18);
    frame.v30.y = D_8006E024 - M2C_FIELD(temp_a0, int *, 0x1C);
    temp_s0_2 = func_8004E9E4(frame.f110);
    var_t1 = temp_s0_2 * func_8004EDE8(&frame.v30.x, 0);
    __asm__("" : "=r"(var_t1) : "0"(var_t1));
    var_v0 = var_t1 >> 0xC;
    if (var_v0 >= 0) {
        goto block_21;
    }
    var_v0 = -var_v0;
block_21:
    if (var_v0 < 0xA0) {
        goto block_100;
    }
    frame.v40.x = func_8004E9E4(portalAngle17);
    frame.v40.y = -func_8004EA2C(portalAngle17);
    frame.v40.z = 0;
    { register int *matrix4 asm("$4");
      matrix4 = &D_8006E00C;
      __asm__("" : "=r"(matrix4) : "0"(matrix4));
      func_8004ED6C(matrix4, &frame.v40.x, &frame.v40.x);
    }
    if (READ9(frame.f110) >= 0) {
        goto block_24;
    }
    *(int*)&frame.f118 = -frame.v40.x;
    goto block_25;
block_24:
    var_t1=frame.v40.x;
    __asm__("" : "=r"(var_t1) : "0"(var_t1));
    frame.f118=var_t1;
block_25:
    if (PRED2(READ9(frame.f118) < 0x801) == 0) {
        goto block_100;
    }
    var_t1=1;
    __asm__("" : "=r"(var_t1) : "0"(var_t1));
    frame.f108=var_t1;
    if (frame.v10.x >= 0x5000) {
        goto block_28;
    }
block_27:
    if (READ9(frame.f108) < 0) {
        goto block_100;
    }
block_28:
    var_s6 = 0x400;
loop_29:
    __asm__ volatile("" ::: "$16", "$17", "$18", "$19", "$20", "$21", "$23", "$30");
    var_s7 = -0x400;
    var_fp = 0x400;
    __asm__("" : "=r"(var_fp) : "0"(var_fp));
    var_t1=-0x400;
    __asm__("" : "=r"(var_t1) : "0"(var_t1));
    frame.f138=var_t1;
    __asm__ volatile("" ::: "memory", "$21", "$19", "$20", "$16", "$18");
    var_t1=-1;
    __asm__("" : "=r"(var_t1) : "0"(var_t1));
    var_s5 = 0;
    work19 = &frame.v30;
    offset20 = frame.f160;
    __asm__("" : "=r"(work19), "=r"(offset20) : "0"(work19), "1"(offset20));
    var_s0_3 = frame.f140;
    var_s2 = 0;
    frame.f130=var_t1;
    __asm__("" : "=r"(var_s7), "=r"(var_fp), "=r"(var_s5), "=r"(var_s0_3), "=r"(var_s2) : "0"(var_s7), "1"(var_fp), "2"(var_s5), "3"(var_s0_3), "4"(var_s2));
    do {
loop_30:
    if (READ9(frame.f108) == 0) {
        goto block_34;
    }
    { register int base2 asm("$2"); base2=D_8006C530;
      __asm__("" : "=r"(base2) : "0"(base2));
      temp_a1_2=offset20+base2; }
    if (M2C_FIELD(temp_a1_2, unsigned char *, 0x43) == 0) {
        goto block_33;
    }
    func_8004F1C8(var_s0_3, temp_a1_2 + var_s2, frame.f120);
    temp_a0_2 = offset20 + D_8006C530;
    var_s0_3->x = SCALE_BYTE(var_s0_3, x, M2C_FIELD(temp_a0_2, unsigned char *, 0x43));
    var_s0_3->y = SCALE_BYTE(var_s0_3, y, M2C_FIELD(temp_a0_2, unsigned char *, 0x43));
    { register int value2 asm("$2"); register int scale3 asm("$3");
      register int low9 asm("$9"); register Vector3D *arg4 asm("$4");
      register Vector3D *arg5 asm("$5"); register Vector3D *arg6 asm("$6");
      scale3=M2C_FIELD(temp_a0_2, unsigned char *,0x43);value2=var_s0_3->z;
      low9=value2*scale3;
      arg5=var_s0_3;arg4=var_s0_3;arg6=frame.f120;


      value2=low9>>8;
      var_s0_3->z=value2;
      func_8004F194(arg4,arg5,arg6);
    }
    projection4=var_s0_3;
    projection6=frame.f100;
    __asm__ volatile("" : "=r"(projection6) : "0"(projection6) : "$5");
    projection5=var_s0_3;
    goto block_41;
block_33:
    projection4=var_s0_3;
    projection6=frame.f100;
    projection5=(Vector3D *)((char *)temp_a1_2 + var_s2);
    goto block_41;
block_34:
    temp_a2 = D_8006C530 + offset20;
    func_8004F1C8(&frame.v30, temp_a2 + var_s2, temp_a2 + 0x18);
    { register int dividend4 asm("$4"); register int factor9 asm("$9");
      register int sign2 asm("$2"); register int quotient3 asm("$3");
      register int product2 asm("$2"); int nativeHigh;
      dividend4=D_8006C5BC; factor9=frame.f128;
      __asm__ volatile("" : "=h"(nativeHigh) : "l"(dividend4*factor9) : "memory");
      sign2=dividend4>>31;
      var_t1=nativeHigh;
      quotient3=(var_t1>>2)-sign2;
      __asm__("" : "=r"(quotient3) : "0"(quotient3), "r"(var_t1));
      product2=quotient3*10;
      if(dividend4!=product2) goto block_36;
    }
    var_v0_2 = frame.v30.z + 0x540;
    goto block_37;
block_36:
    var_v0_2 = frame.v30.z + 0x320;
block_37:
    frame.v30.z = var_v0_2;
    __asm__ volatile("" ::: "memory");
    { register int *arg4 asm("$4"); arg4=(int*)work19;
      __asm__("" : "=r"(arg4) : "0"(arg4));
      func_8004F110(arg4,6); }
    { register int base2 asm("$2");base2=D_8006C530;
      __asm__("" : "=r"(base2) : "0"(base2));
      temp_a2_2=offset20+base2;
      __asm__("" : "=r"(temp_a2_2) : "0"(temp_a2_2)); }
    if (M2C_FIELD(temp_a2_2, unsigned char *, 0x43) == 0) {
        goto block_39;
    }
    func_8004F1C8(var_s0_3, temp_a2_2 + var_s2, frame.f120);
    temp_a0_3 = offset20 + D_8006C530;
    var_s0_3->x = SCALE_BYTE(var_s0_3, x, M2C_FIELD(temp_a0_3, unsigned char *, 0x43));
    var_s0_3->y = SCALE_BYTE(var_s0_3, y, M2C_FIELD(temp_a0_3, unsigned char *, 0x43));
    { register int value2 asm("$2"); register int scale3 asm("$3");
      register int low9 asm("$9"); register Vector3D *arg4 asm("$4");
      register Vector3D *arg5 asm("$5"); register Vector3D *arg6 asm("$6");
      scale3=M2C_FIELD(temp_a0_3, unsigned char *,0x43);value2=var_s0_3->z;
      low9=value2*scale3;
      arg5=var_s0_3;arg4=var_s0_3;arg6=frame.f120;


      value2=low9>>8;
      var_s0_3->z=value2;
      func_8004F194(arg4,arg5,arg6);
    }
    add4=work19;add5=work19;
    __asm__("" : "=r"(add4),"=r"(add5) : "0"(add4),"1"(add5));
    var_a2 = var_s0_3;
    goto block_40;
block_39:
    add4=work19;add5=work19;
    __asm__("" : "=r"(add4),"=r"(add5) : "0"(add4),"1"(add5));
    var_a2 = (Vector3D *)((char *)temp_a2_2 + var_s2);
block_40:
    func_8004F194(add4, add5, var_a2);
    projection4=var_s0_3;
    projection6=frame.f100;
    projection5=&frame.v30;
block_41:
    func_8004F408(projection4, projection5, projection6);
    { register int index2 asm("$2");var_t1=(int)frame.f148;
      __asm__("" : "=r"(var_t1) : "0"(var_t1));
      index2=var_s5<<2;temp_s1=(int*)(index2+var_t1); }
    M2C_FIELD(temp_s1, int *, 0x98) = (int) ((unsigned short) M2C_FIELD(var_s0_3, int *, 0) + (var_s0_3->y << 0x10));
    temp_a0_4 = var_s0_3->x;
    if (temp_a0_4 >= var_s6) {
        goto block_43;
    }
    var_s6 = temp_a0_4;
block_43:
    if (var_s7 >= temp_a0_4) {
        goto block_45;
    }
    var_s7 = temp_a0_4;
block_45:
    temp_a1_3 = var_s0_3->y;
    if (temp_a1_3 >= var_fp) {
        goto block_47;
    }
    var_fp = temp_a1_3;
block_47:
    if (PRED2(READ9(frame.f138) < temp_a1_3) == 0) {
        goto block_49;
    }
    frame.f138 = temp_a1_3;
block_49:
    temp_a2_3 = var_s0_3->z;
    var_s0_3 = (Vector3D *)((char *)var_s0_3 + 12);
    var_s2 += 0xC;
    temp_v0_3 = func_8004F4BC(temp_a0_4, temp_a1_3, temp_a2_3);
    var_s5 += 1;
    temp_t1 = frame.f130 & temp_v0_3;
    frame.f130 = temp_t1;
    M2C_FIELD(temp_s1, int *, 0xB0) = temp_v0_3;
    } while (var_s5 < 5);
    if (temp_t1 != 0) {
        goto block_98;
    }
    __asm__ volatile("" ::: "$9");
    if (var_s6 >= 0) {
        goto block_53;
    }
    var_s6 = 0;
block_53:
    if (var_s7 < 0x201) {
        goto block_55;
    }
    var_s7 = 0x200;
block_55:
    if (var_fp >= 0xC) {
        goto block_57;
    }
    var_fp = 0xC;
block_57:
    if (PRED2(READ9(frame.f138) < 0xE5)) {
        goto block_59;
    }
    var_t1=0xE4;
    __asm__("" : "=r"(var_t1) : "0"(var_t1));
    frame.f138=var_t1;
block_59:
    { register int base2 asm("$2"); register int timer3 asm("$3");
      register int cosine2 asm("$2"); register int trigIndex3 asm("$3");
      register unsigned short *trigPointer3 asm("$3");
      register int rawTrig2 asm("$2"); register int phase2 asm("$2");
      base2=D_8006C530;
      var_t1=frame.f138;
      __asm__("" : "=r"(var_t1) : "0"(var_t1), "r"(base2));
      timer3=D_8006C644;
      var_s5_2=0;
      D_8006ED8C=var_t1;
      var_t1=frame.f160;
      var_s1_2=0;
      D_8006ED90=var_s6; D_8006ED94=var_s7; D_8006ED88=var_fp;
      base2=var_t1+base2;
      base2=M2C_FIELD(base2,int *,0x3C);
      var_t1=frame.f8;
      timer3<<=2;
      D_8006ED98=base2;
      phase2=var_t1<<6;
      __asm__("" : "=r"(phase2) : "0"(phase2));
      trigIndex3=timer3+phase2;
      __asm__("" : "=r"(trigIndex3) : "0"(trigIndex3));
      trigIndex3&=0xFF;
      cosine2=(int)&D_80065920;
      trigIndex3<<=1;
      trigPointer3=(unsigned short *)(trigIndex3+cosine2);
      rawTrig2=*trigPointer3;
      var_a2_2=frame.f148;
      D_8006EDA0=((rawTrig2<<16)>>20)+0xE00;
      rawTrig2=*trigPointer3;
      D_8006EDA4=0xC00;
      D_8006EDA2=((rawTrig2<<16)>>20)+0xE00;
    }
    do {
loop_60:
    { register int left4 asm("$4"); register int sign2 asm("$2");
      register int quotient3 asm("$3"); register int right2 asm("$2");
      register int factor9 asm("$9"); register int flags3 asm("$3"); int nativeHigh;
      var_a1_2=var_s1_2+1;
      factor9=frame.f128; left4=var_s1_2<<2;
      __asm__ volatile("" : "=h"(nativeHigh) : "l"(var_a1_2*factor9) : "memory");
      sign2=var_a1_2>>31;
      var_t1=(int)frame.f148;
      left4+=var_t1;
      __asm__ volatile("" : "=r"(left4) : "0"(left4) : "memory");
      var_t1=nativeHigh;
      quotient3=(var_t1>>1)-sign2;
      __asm__("" : "=r"(quotient3) : "0"(quotient3), "r"(var_t1));
      right2=quotient3*5;
      right2=var_a1_2-right2;
      right2<<=2;
      var_t1=(int)frame.f148;
      flags3=M2C_FIELD(left4,int *,0xB0);
      right2+=var_t1;
      right2=M2C_FIELD(right2,int *,0xB0);
      flags3 &= right2;
      if(flags3!=0) goto block_62;
    }
    M2C_FIELD(var_a2_2,int *,0x40)=var_s1_2;
    var_a2_2=(int *)((char *)var_a2_2+4);
    var_s5_2+=1;
block_62:
    var_s1_2=var_a1_2;
    } while(var_a1_2<5);
    if (var_s5_2 != 0) {
        goto block_66;
    }
    if (READ9(frame.f118) >= 0) {
        goto block_98;
    }
    if (((frame.c0[0] | frame.c0[1] | frame.c0[2] | frame.c0[3] | frame.c0[4]) & 0xF) != 0xF) {
        goto block_98;
    }
block_66:
    D_8006EDA8 = var_s5_2;
    var_s1_3 = 0;
    if (var_s5_2 <= 0) {
        goto block_92;
    }
    __asm__ volatile("" ::: "$20", "$23", "$30");
{ register Vector3D *left30 asm("$30");
 edgeBase20=&D_8006EDAC; left30=&frame.vd8;
 __asm__ volatile("" : "=r"(edgeBase20),"=r"(left30) : "0"(edgeBase20),"1"(left30));
 edgeLeft30=left30;
 edgeRight23=&frame.ve8;
 __asm__("" : "=r"(edgeRight23) : "0"(edgeRight23)); }
    var_s3 = 0;
    var_s2_2 = 0;
    do {
loop_68:
    { register int index2 asm("$2"); register int first7 asm("$7");
      register int next4 asm("$4"); register int sign2 asm("$2");
      register int quotient3 asm("$3"); register int product2 asm("$2");
      register int remainder16 asm("$16"); int nativeHigh;
      var_t1=(int)frame.f148; index2=var_s1_3<<2;
      index2+=var_t1; first7=M2C_FIELD(index2,int *,0x40);
      var_t1=frame.f128; next4=first7+1;
      __asm__ volatile("" : "=h"(nativeHigh) : "l"(next4*var_t1) : "memory");
      sign2=next4>>31; var_t1=nativeHigh;
      __asm__("" : "=r"(var_t1) : "0"(var_t1));
      quotient3=var_t1>>1; remainder16=quotient3-sign2;
      __asm__("" : "=r"(remainder16) : "0"(remainder16));
      product2=remainder16*5;
      var_t1=READ9(frame.f110);
      remainder16=next4-product2;

      temp_a3=first7; temp_s0_3=remainder16;

    }
    if (var_t1 >= 0) {
        goto block_70;
    }
    var_v1 = ((var_s2_2 + 1) * 4) + (int)edgeBase20;
    goto block_71;
block_70:
    __asm__ volatile("" ::: "$3");
    var_v1 = var_s3 + (int)edgeBase20;
block_71:
    *var_v1 = M2C_FIELD((void*)(READ9(frame.f148)+(temp_a3*4)), int *, 0x98);
    if (READ9(frame.f110) <= 0) {
        goto block_73;
    }
    var_v1_2 = ((var_s2_2 + 1) * 4) + (int)edgeBase20;
    goto block_74;
block_73:
    __asm__ volatile("" ::: "$3");
    var_v1_2 = var_s3 + (int)edgeBase20;
block_74:
{ register int index2 asm("$2"); register int value2 asm("$2");
 var_t1=READ9(frame.f148); index2=temp_s0_3<<2;
 temp_a0_6=(int*)(index2+var_t1);
 value2=M2C_FIELD(temp_a0_6,int*,0x98);
 *var_v1_2=value2; index2=temp_a3<<2;
 temp_s6=(int*)(index2+var_t1); }
    if (M2C_FIELD(temp_s6, int *, 0xB0) & 0x10) {
        goto block_76;
    }
    if (!(M2C_FIELD(temp_a0_6, int *, 0xB0) & 0x10)) {
        goto block_91;
    }
block_76:
{ register Vector3D *address4 asm("$4"), *camera6 asm("$6"); register int index5 asm("$5"), base2 asm("$2");
 address4=edgeLeft30; camera6=&D_8006E020; index5=temp_a3*3;
 base2=D_8006C530; var_t1=frame.f160;
__asm__("" : "=r"(var_t1) : "0"(var_t1),"r"(base2),"r"(index5));
 index5<<=2; base2+=var_t1; index5=base2+index5;
__asm__("" : "=r"(address4),"=r"(camera6) : "0"(address4),"1"(camera6));
func_8004F1C8(address4,(void*)index5,camera6); }
{ register Vector3D *address4 asm("$4"), *camera6 asm("$6"); register int index5 asm("$5"), base2 asm("$2");
 address4=edgeRight23; camera6=&D_8006E020; index5=temp_s0_3*3;
 base2=D_8006C530; var_t1=frame.f160;
__asm__("" : "=r"(var_t1) : "0"(var_t1),"r"(base2),"r"(index5));
 index5<<=2; base2+=var_t1; index5=base2+index5;
__asm__("" : "=r"(address4),"=r"(camera6) : "0"(address4),"1"(camera6));
func_8004F1C8(address4,(void*)index5,camera6); }
    { register int *matrix4 asm("$4");
      matrix4 = &D_8006E00C;
      __asm__("" : "=r"(matrix4) : "0"(matrix4));
      func_8004ED6C(matrix4, &edgeLeft30->x, &edgeLeft30->x);
    }
    { register int *matrix4 asm("$4");
      matrix4 = &D_8006E00C;
      __asm__("" : "=r"(matrix4) : "0"(matrix4));
      func_8004ED6C(matrix4, &edgeRight23->x, &edgeRight23->x);
    }
    { register int leftX3 asm("$3"); register int right2 asm("$2");
      register int leftY7 asm("$7"); register int fraction5 asm("$5");
      register int numerator4 asm("$4"); register int denominator3 asm("$3");
      register int deltaY6 asm("$6"); register int leftZ4 asm("$4");
      register int deltaZ3 asm("$3");
      leftX3=frame.vd8.x; right2=frame.ve8.y; leftY7=frame.vd8.y;
      fraction5=leftX3-0x100; right2-=leftY7;
      numerator4=right2*fraction5; right2=frame.ve8.x;
      denominator3=leftX3-right2;
      deltaY6=numerator4/denominator3;

      right2=frame.ve8.z; leftZ4=frame.vd8.z;
      right2=(right2-leftZ4)*fraction5;
      deltaZ3=right2/denominator3;

      leftY7+=deltaY6;

      {register int value2 asm("$2");register int limit3 asm("$3");
      value2=leftY7*5;
leftZ4+=deltaZ3;
__asm__("" : "=r"(leftZ4) : "0"(leftZ4),"r"(value2));
limit3=value2<<4; value2+=limit3; value2<<=2; value2+=leftY7;
value2/=256; __asm__("" : "=r"(value2) : "0"(value2));
      limit3=0x100; __asm__("" : "=r"(limit3) : "0"(limit3));
      var_a3=limit3-value2;}
      __asm__("" : "=r"(var_a3) : "0"(var_a3));
      var_a0=leftZ4;
    }
    if(PRED2(var_a3 < 0x400)) goto block_78;
    var_a3=0x3FF;
    __asm__ volatile("" : "=r"(var_a3) : "0"(var_a3));

block_78:
    var_v0_3=PRED2(var_a3 < -0x400);
    if(var_v0_3==0) goto block_80;
    var_a3=-0x400;
block_80:
    {register int value2 asm("$2");register int limit3 asm("$3");
    value2=(var_a0*213)/256; __asm__("" : "=r"(value2) : "0"(value2));
    limit3=0x78; __asm__("" : "=r"(limit3) : "0"(limit3));
    var_a0=limit3-value2;}
    __asm__("" : "=r"(var_a0) : "0"(var_a0));
    if(PRED2(var_a0 < 0x400)) goto block_82;
    var_a0=0x3FF;
    __asm__ volatile("" : "=r"(var_a0) : "0"(var_a0));

block_82:
    var_v0_4=PRED2(var_a0 < -0x400);
    if(var_v0_4==0) goto block_84;
    var_a0=-0x400;
block_84:
    if (!(M2C_FIELD(temp_s6, int *, 0xB0) & 0x10)) {
        goto block_87;
    }
    if (READ9(frame.f110) < 0) {
        goto block_88;
    }
    var_a1_2 = (int) (var_s3 + (int)edgeBase20);
    goto block_90;
block_87:
    if (READ9(frame.f110) <= 0) {
        goto block_89;
    }
block_88:
    var_v0_5 = var_s2_2 + 1;
    var_a1_2 = (int) ((var_v0_5 * 4) + (int)edgeBase20);
    goto block_90;
block_89:
    var_a1_2 = (int) (var_s3 + (int)edgeBase20);
block_90:
    { register int packed3 asm("$3"); register int mask2 asm("$2");
      packed3=var_a0<<16; mask2=var_a3&0xFFFF;
      __asm__("" : "=r"(packed3),"=r"(mask2) : "0"(packed3),"1"(mask2));
      packed3+=mask2;
      __asm__("" : "=r"(packed3) : "0"(packed3));
      *(int *)var_a1_2=packed3;
    }
block_91:
    var_s3 += 8;
    var_s1_3 += 1;
    var_s2_2 += 2;
    } while (var_s1_3 < var_s5_2);
block_92:
    if (frame.v10.x < 0x5000) {
        goto block_94;
    }
    D_8006EDA6 = 0xFFF;
    goto block_97;
block_94:
    if (frame.v10.x < 0x4000) {
        goto block_96;
    }
    D_8006EDA6 = frame.v10.x - 0x4000;
    goto block_97;
block_96:
    D_8006EDA6 = 0;
block_97:
    func_8001C8C8(frame.f108);
block_98:
    temp_t1_2 = READ9(frame.f108) - 1;
    frame.f108 = temp_t1_2;
    if (frame.v10.x < 0x5000) {
        goto block_27;
    }
    var_s6 = 0x400;
    if (temp_t1_2 > 0) {
        goto loop_29;
    }
block_100:
    var_t1 = frame.f160;
block_101:
    var_t1 += 0x44;
block_102:
    frame.f160 = var_t1;
    temp_t1_3 = frame.f8 + 1;
    frame.f8 = temp_t1_3;
    } while (PRED2(temp_t1_3 < D_8006C5E0));
block_103:
    return;
}

#undef MULT_HI
#undef M2C_FIELD


/**
 * ???() - func_8001FABC()
 * https://decomp.me/scratch/RfQhe
 */
void func_8001FABC(int arg0) {
    void* packet = D_8006C664;
    func_8005C564(packet, 1, 0, arg0, 0);
    func_8004E758(packet);
    D_8006C664 = (char*)packet + 12;
}

extern int D_800722D8, D_8006C7DC, D_800722D4, D_800722D0, D_8006FC6C, D_8006FCE0;
void func_8001FB10(int arg0) {
    int top;
    int bottom;
    DrawSync(0);
    D_8006C7DC = arg0;
    top = D_800722D8 - arg0;
    bottom = top - arg0;
    D_800722D4 = top;
    D_800722D0 = bottom;
    D_8006FC6C = bottom;
    D_8006FCE0 = top;
}

/**
 * ???() - func_8001FB74() - MATCHING
 * Draw line under NPC name
 * https://decomp.me/scratch/9NQVn
 */
void func_8001FB74(int x0, int y0, int x1, int y1) {

    LINE_G2* line;

    line = D_8006C664;

    line->tag = 0x04000000;
    line->code = 0x50;
    setXY2(line, x0, y0, x1, y1);
    setRGB0(line, 180, 154, 17);
    setRGB1(line, 180, 154, 17);

    func_8004E758(line);

    line++;
    D_8006C664 = line;

    line->tag = 0x04000000;
    line->code = 0x50;
    setXY2(line, x0 + 1, y0 + 1, x1 + 1, y1 + 1);
    setRGB0(line, 128, 82, 0);
    setRGB1(line, 128, 82, 0);

    func_8004E758(line);
    D_8006C664 = line + 1;
}

/**
 * ???() - func_8001FC90() - MATCHING
 * https://decomp.me/scratch/8lG9w
 */
void func_8001FC90(int x0, int x1, int y0, int y1) {
    POLY_F4* p;

    p = D_8006C664;
    p->tag = 0x05000000;

    *(int*)&p->r0 = 0x2A080808;

    p->x0 = x0;
    p->x1 = x1;
    p->x2 = x0;
    p->x3 = x1;
    p->y0 = y0;
    p->y1 = y0;
    p->y2 = y1;
    p->y3 = y1;

    func_8004E758(p);
    D_8006C664 = p + 1;
}

/* Retail source: asm/nonmatchings/drawutil/func_8001FD00.s,
 * 0x8001FD00..0x8001FE48; integer screen coordinates and
 * on-call corner sprite draws. */
extern short D_800719D0;
void func_8001FD00(int left, int right, int top, int bottom) {
    int innerTop = top + 8;
    int innerBottom = bottom - 8;
    int innerLeft = left + 12;
    int innerRight = right - 12;
    short* frame = &D_800719D0;
    func_8001FABC(0x18);
    func_8001FC90(left, right, innerTop, innerBottom);
    func_8001FC90(innerLeft, innerRight, top, innerTop);
    func_8001FC90(innerLeft, innerRight, innerBottom, bottom);
    func_800289C8(&D_8006C788[*frame], left, top);
    func_800289C8(&D_8006C788[*frame + 1], innerRight, top);
    func_800289C8(&D_8006C788[*frame + 2], left, innerBottom);
    func_800289C8(&D_8006C788[*frame + 3], innerRight, innerBottom);
}

/**
 * ???() - func_8001FE48() - MATCHING
 * https://decomp.me/scratch/bNzDh
 */
void func_8001FE48(int arg0, int arg1, int arg2, int arg3) {
    func_8001FABC(0x18);
    func_8001FC90(arg0 + 3, arg1 - 3,    arg2,        arg2 + 1);
    func_8001FC90(arg0 + 1, arg1 - 1,    arg2 + 1,    arg2 + 2);
    func_8001FC90(arg0,     arg1,        arg2 + 2,    arg3 - 2);
    func_8001FC90(arg0 + 1, arg1 - 1,    arg3 - 2,    arg3 - 1);
    func_8001FC90(arg0 + 3, arg1 - 3,    arg3 - 1,    arg3);
}

/* Retail source: asm/nonmatchings/drawutil/func_8001FF44.s,
 * 0x8001FF44..0x800200A0; border size is an integer screen coordinate. */
extern int D_8006C74C;
extern int D_8006C64C;
extern char D_80070328[];
void func_8001FF44(void) {
    int i;
    char* packet;
    int size;
    if (*(int*)(D_80070328 + 0x210) & 0x80000) {
        D_8006C74C = 0;
    }
    if (D_8006C74C != 0) {
        if (D_8006C64C < 12) {
            D_8006C64C++;
        }
    } else if (D_8006C64C != 0) {
        D_8006C64C--;
    }
    if (D_8006C64C == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        packet = D_8006C664;
        *(int*)packet = 0x05000000;
        packet[7] = 0x28;
        *(short*)(packet + 8) = 0;
        *(short*)(packet + 12) = 0x200;
        *(short*)(packet + 16) = 0;
        *(short*)(packet + 20) = 0x200;
        if (i == 0) {
            size = D_8006C64C;
            *(short*)(packet + 10) = 12;
            size += 12;
            __asm__ volatile("" : "=r"(size) : "0"(size));
            *(short*)(packet + 18) = size;
        } else {
            register int bottomSize __asm__("$2") = D_8006C64C;
            *(short*)(packet + 10) = 0xE4;
            *(short*)(packet + 18) = 0xE4 - bottomSize;
        }
        *(short*)(packet + 14) = *(unsigned short*)(packet + 10);
        *(short*)(packet + 22) = *(unsigned short*)(packet + 18);
        packet[4] = 0;
        packet[5] = 0;
        packet[6] = 0;
        func_8004E758(packet);
        D_8006C664 = packet + 24;
    }
}

/* Retail source: asm/nonmatchings/drawutil/func_800200A0.s,
 * 0x800200A0..0x80020168; primitive fields use byte offsets. */
void func_800200A0(int arg0, char red, char green, char blue) {
    char* packet = (char*)D_8006C664;
    char* poly;
    func_8005C564(packet, 1, 0, arg0 << 5, 0);
    func_8004E758(packet);
    poly = packet + 12;
    *(int*)(packet + 0xC) = 0x05000000;
    packet[0x13] = 0x2A;
    *(short*)(packet + 0x16) = 12;
    *(short*)(packet + 0x1A) = 12;
    *(short*)(packet + 0x14) = 0;
    *(short*)(packet + 0x18) = 0x200;
    *(short*)(packet + 0x1C) = 0;
    *(short*)(packet + 0x1E) = 0xE4;
    *(short*)(packet + 0x20) = 0x200;
    *(short*)(packet + 0x22) = 0xE4;
    packet[0x10] = red;
    packet[0x11] = green;
    packet[0x12] = blue;
    func_8004E758(poly);
    D_8006C664 = packet + 0x24;
}

/**
 * ???() - func_80020168()
 * https://decomp.me/scratch/qLRGj
 */
/* Retail source: asm/nonmatchings/drawutil/func_80020168.s,
 * 0x80020168..0x800202DC; one loop iteration per frame. */
extern char D_8006FBFC;
extern char D_8006FC14, D_8006FC88;
extern char* D_8006C600;
extern int D_8006C634, D_8006C7D4;
extern void* func_8004E664(int);
void func_80020168(void) {
    RECT rect;
    register int top __asm__("$2");
    register int destY __asm__("$6");
    int i;
    char* next;
    register void* packet __asm__("$3");
    register int count __asm__("$2");
    DrawSync(0);
    VSync(0);
    top = 12;
    __asm__ volatile("" : "=r"(top) : "0"(top));
    rect.x = 0;
    if (D_8006C600 != &D_8006FBFC) {
        top = 240;
    }
    rect.y = top;
    rect.w = 512;
    rect.h = 216;
    destY = 12;
    if (D_8006C600 == &D_8006FBFC) {
        destY = 240;
    }
    MoveImage(&rect, 0, destY);
    DrawSync(0);
    i = 0;
    D_8006FC14 = 0;
    D_8006FC88 = 0;
    do {
        next = D_8006C600 == &D_8006FBFC ? &D_8006FBFC + 0x74 : &D_8006FBFC;
        count = D_8006C634;
        D_8006C600 = next;
        packet = *(void**)(next + 0x70);
        __asm__ volatile("" : "=r"(packet), "=r"(count) : "0"(packet), "1"(count));
        D_8006C7D4 = count + 0x1000;
        __asm__ volatile("" ::: "memory");
        D_8006C664 = packet;
        if (i == 0) {
            func_800200A0(2, 16, 16, 16);
        } else {
            func_800200A0(2, 32, 32, 32);
        }
        i++;
        DrawSync(0);
        VSync(0);
        PutDispEnv((DISPENV*)(D_8006C600 + 0x5C));
        PutDrawEnv((DRAWENV*)D_8006C600);
        DrawOTag(func_8004E664(0x580));
    } while (i < 16);
    func_8001EBAC();
    D_8006FC14 = 1;
    D_8006FC88 = 1;
}

/**
 * DrawStringCentered() - func_800202DC() - MATCHING
 * https://decomp.me/scratch/iAe5h
 */
void DrawStringCentered(char* arg0, int arg1, int arg2, int arg3) {
    int x = arg1;
    x -= (func_8002EBB0(arg0) >> 1);
    func_8002E748(arg0, x, arg2, arg3, 0);
}

void func_80020344(const char* arg0, int arg1, int arg2, int arg3) {
    int halfWidth = func_8002EBB0((void*)arg0) >> 1;

    func_8001FE48(arg1 - halfWidth - 8, arg1 + halfWidth + 8, arg2 - 2, arg2 + 11);
    DrawStringCentered((char*)arg0, arg1, arg2, arg3);
}

/**
 * DrawStringRightAligned() - func_800203C4() - MATCHING
 * https://decomp.me/scratch/YCZcN
 */
void DrawStringRightAligned(char* arg0, int arg1, int arg2, int arg3) {
    int x = arg1;
    x -= func_8002EBB0(arg0);
    func_8002E748(arg0, x, arg2, arg3, 0);
}

extern char D_8006C3D8[];
extern char D_8006C3DC[];
extern int D_8006FBF8;
extern int D_8006C76C;
void func_80020428(int value, int x, int y, int color) {
    char buffer[8];
    sprintf(buffer, D_8006C3D8, value);
    if (x < 0) {
        x = -x - 12 * strlen(buffer);
    }
    if (D_8006FBF8 != 0) {
        func_8002E970(buffer, x, y, color, 0);
    } else {
        func_8002E748(buffer, x, y, color, 0);
        if (D_8006C76C != 2 && value >= 1000) {
            x += 10;
            if (value >= 10000) {
                x += 12;
            }
            func_8002E748(D_8006C3DC, x, y + 1, color, 0);
        }
    }
}

/* Retail: asm/nonmatchings/drawutil/func_80020530.s, 0x80020530..0x80020790; public decomp.me scratch i0k7F (score 0). */
extern int D_8006C598;
extern int D_8006C76C;

extern int D_8006FBD0;
extern short D_80070158;

typedef struct {
    char* stringsmaybe[45];
} Something;

extern Something D_80069DE4;

typedef struct {
    int unk0;
    int unkn8;
} TempMenuSomething;

//unk0 = int
extern TempMenuSomething D_8006FBCC;

void func_80020530(signed char* arg0) {

    int var_s4 = 256;
    int var_s0;
    int var_s2;
    int var_t0;
    int var_a1;
    int var_a2;
    int var_a3;
    Something* var_s5;
    TempMenuSomething* menu;
    unsigned char charidx; //
    int offset;
    int mid;
    char* stringmaybe;
    Something* temp_s3;

    int temp_a3;
    var_s2 = 80;
    var_t0 = 192;
    var_a1 = 320;
    var_a2 = 76;
    var_a3 = 172;
    //var_s4 = 256;


    if (D_8006FBD0 == 0xD) {
        var_s0 = 0;
        if ((unsigned char)arg0[1] != 0xFF) {
            do {
                var_s0++;
            } while ((unsigned char)arg0[var_s0 + 1] != 0xFF);
        }
        D_80070158 = var_s0;

        var_s0 = ((var_s0 * 8) - var_s0) * 2;
        var_s0 += 21;

        mid = (var_a2 + var_a3) >> 1;

        offset = var_s2 - var_a2;
        var_s2 = mid - (var_s0 >> 1);
        var_a2 = var_s2 - offset;
        var_a3 = var_s2 + var_s0 + offset;

        var_t0 -= 0x14;
        var_a1 += 0x14;
    } else if (D_8006FBD0 == 0xE) {
        var_t0 = 0x20;
        var_a1 = 0x1E0;
    } else {
        D_80070158 = 5;
    }
    func_8001FD00(var_t0, var_a1, var_a2, var_a3);


    temp_s3 = &D_80069DE4;
    DrawStringCentered(temp_s3[D_8006C76C].stringsmaybe[(unsigned char)arg0[0]], var_s4, var_s2, 2);
    var_s2 += 21;
    var_s0 = 1;
    if ((unsigned char)arg0[1] != 0xFF) {
        var_s5 = temp_s3;
        menu = &D_8006FBCC;
        arg0++;

        do {

            charidx = *arg0;

            if (charidx != 0x2E) {

                stringmaybe = var_s5[D_8006C76C].stringsmaybe[charidx];

                if (D_8006C598 == 0) {
                    temp_a3 = 0;
                    if (menu->unk0 == var_s0) {
                        int menuField = *(int*)((unsigned char*)menu - 8);
                        int mask = menuField & 0x1F;
                        temp_a3 = (mask < 0x16) ? 1 : 0;
                    }
                    temp_a3 += 2;
                } else {
                    int a3mask = (D_8006FBCC.unk0 == var_s0) ? 1 : 0;
                    temp_a3 = a3mask + 2;
                }

                charidx = arg0[0];
                if (  ( (unsigned int)(charidx - 0x25) < 8) && (temp_a3 == 2)  ) {
                    charidx = charidx - 0x25;
                    if ( !(charidx & 1) ) {
                        temp_a3 = 4;
                    }
                }

                DrawStringCentered(stringmaybe, var_s4, var_s2, temp_a3);
            }
            var_s2 += 0xE;
            arg0++;
            var_s0++;
        } while ((unsigned char)*arg0 != 0xFF);
    }
}

/* Retail: asm/nonmatchings/drawutil/func_80020790.s, 0x80020790..0x80020D70.
 * The menu selection, width pass, centering bounds, and draw calls follow the retail instruction/data chain. */
extern int D_8006C5BC;
extern int D_8006C5C8;
extern int D_8006FA3C;
extern void* D_80071484[];
#define DRAWUTIL_FIELD(expr, type_ptr, offset) (*(type_ptr)((signed char*)(expr) + (offset)))
void func_80020790(void) {
    int sp18;
    int sp20;
    short temp_v1;
    int temp_s7;
    int temp_v1_2;
    register int var_a0 asm("$23");
    int var_a3;
    int var_a3_2;
    int var_fp;
    int var_s0;
    int var_s1_3;
    register int var_s2 asm("$18");
    register int var_s4 asm("$20");
    int var_s6;
    int var_v0;
    signed char *temp_a0_3;
    signed char *sentinel;
    signed char *temp_s5;
    signed char *var_s0_2;
    int temp_a0_4;
    void **var_s1;
    void **table;
    void *temp_a0;
    void *temp_a0_2;
    Something *stringTable;
    TempMenuSomething *menuState;

    var_s2 = 0;
    var_s6 = 0;
    var_fp = 0x85;
    sp18 = 0x17B;
    var_s4 = 0x32;
    var_a0 = 0x80;
    sp20 = 0x180;
    if (((D_8006C5BC / 10) * 0xA) == (D_8006C5BC - 5)) {
        if (D_8006FA3C == 3) {
            switch (D_8006C5BC) {                   /* switch 1; irregular */
            case 15:                                /* switch 1 */
                var_s2 = 0x15;
                break;
            case 25:                                /* switch 1 */
                var_s2 = 0x16;
                break;
            case 35:                                /* switch 1 */
                var_s2 = 0x17;
                break;
            case 45:                                /* switch 1 */
                var_s2 = 0x18;
                break;
            }
        } else {
            var_s2 = 3;
            if (D_8006FA3C == 2) {
                var_s2 = 4;
            }
        }
    } else if (DRAWUTIL_FIELD(D_80070328, int *, 0x24C) == 0) {
        if ((D_8006C5BC == 0x18) && (D_8006C5C8 == 1)) {
            var_s2 = 0x10;
        } else if (D_8006C5BC == 0x1F) {
            var_s2 = 0x11;
        } else if (DRAWUTIL_FIELD(D_80070328, int *, 0x48) == 0x26) {
            var_s2 = 5;
        } else if (DRAWUTIL_FIELD(D_80070328, int *, 0x50) == 0x13) {
            if ((D_8006C5BC == 0x20) || (var_s2 = 0xE, (D_8006C5BC == 0x32))) {
                var_s2 = 0xF;
            }
        } else if (D_8006C5BC == 0x2F) {
            if (DRAWUTIL_FIELD(D_80070328, void **, 0x250) != ((void*)0)) {
                temp_v1 = DRAWUTIL_FIELD(DRAWUTIL_FIELD(D_80070328, void **, 0x250), short *, 0x36);
                if (temp_v1 != 0x2F5) {
                    if (temp_v1 == 0x2EA) {
                        var_s2 = 0x1B;
                    }
                } else {
                    goto block_35;
                }
            }
        } else if (D_8006C5BC == 0x32) {
            if (DRAWUTIL_FIELD(D_80070328, void **, 0x250) != ((void*)0)) {
                if (DRAWUTIL_FIELD(DRAWUTIL_FIELD(D_80070328, void **, 0x250), short *, 0x36) == 0xF0) {
block_35:
                    var_s2 = 0x14;
                }
            }
        } else if (DRAWUTIL_FIELD(D_80070328, int *, 0x50) == 0x12) {
            var_s2 = 0xD;
            if (D_8006C5BC == 0x2B) {
                var_s2 = 0x13;
            }
        } else if (DRAWUTIL_FIELD(D_80070328, int *, 0x50) == 0xA) {
            var_s2 = 1;
        } else if ((unsigned int) (DRAWUTIL_FIELD(D_80070328, int *, 0x50) - 0xB) < 2U) {
            var_s2 = 2;
        }
    } else {
        switch (DRAWUTIL_FIELD(D_80070328, int *, 0x24C)) {
        case 1:
            var_s2 = 6;
            break;
        case 2:
            var_s2 = 8;
            if (D_8006C5BC == 0x24) {
                var_s2 = 9;
            }
            break;
        case 3:
            var_s2 = 7;
            break;
        case 4:
            if (D_8006C5BC != 0x21) {
                var_s2 = 0x1A;
                if (D_8006C5BC != 0x2C) {
                    var_s2 = 0xB;
                }
            } else {
                var_s2 = 0x19;
            }
            break;
        case 5:
            var_s2 = 0xA;
            break;
        case 6:
            var_s2 = 0x12;
            break;
        case 7:
            var_s2 = 0xC;
            break;
        }
    }
    { register signed char *tableBase asm("$4"); register int tableOffset asm("$3"); register int tableIndex asm("$2");
      tableIndex = 0xA; tableBase = (signed char *)D_80071484; tableOffset = var_s2 << 2; D_80070158 = tableIndex;
      tableIndex = D_8006C76C; tableOffset += (int)tableBase; tableIndex <<= 2; tableIndex += tableOffset;
      var_s1 = *(void ***)tableIndex; }
    temp_s5 = D_80067570[D_8006FBD0];
    if ((var_s1 != ((void*)0)) && (*var_s1 != (void *)-1)) {
        do {
            temp_a0 = *var_s1;
            var_s1 += 1;
            var_s0 = func_8002EBB0(temp_a0);
            temp_a0_2 = *var_s1;
            if (temp_a0_2 != (void *)-1) {
                var_s1 += 1;
                var_s0 += func_8002EBB0(temp_a0_2);
                var_s0 += 0x1A;
            }
            if (var_s6 < var_s0) {
                var_s6 = var_s0;
            }
        } while (*var_s1 != (void *)-1);
    }
    if (var_s6 >= 0x101) {
        { register int screenWidth asm("$3"); register int centered asm("$2"); int rightEdge;
        screenWidth = 0x200; centered = screenWidth - var_s6; temp_s7 = centered >> 1;
        rightEdge = screenWidth - temp_s7; sp20 = rightEdge; __asm__ volatile("" ::: "memory");
        var_fp = temp_s7 + 5; screenWidth = screenWidth - var_fp; sp18 = screenWidth; }
        var_a0 = temp_s7;
    }
    func_8001FD00(var_a0, sp20, 0x2E, 0xD3);
    DrawStringCentered((&D_80069DE4)[D_8006C76C].stringsmaybe[(unsigned char) DRAWUTIL_FIELD(temp_s5, signed char *, 0)], 0x100, var_s4, 2);
    { register signed char *tableBase2 asm("$4"); register int tableOffset2 asm("$2"); register int tableIndex2 asm("$3");
      tableBase2 = (signed char *)D_80071484; tableOffset2 = var_s2 << 2; tableIndex2 = D_8006C76C;
      tableOffset2 += (int)tableBase2; tableIndex2 <<= 2; tableOffset2 = tableIndex2 + tableOffset2;
      var_s1 = *(void ***)tableOffset2; var_s4 += 0x15;
      if (var_s1 == ((void*)0)) { tableOffset2 = (int)tableBase2; tableOffset2 += tableIndex2; __asm__ volatile("" : "=r"(tableOffset2) : "0"(tableOffset2)); var_s1 = *(void ***)tableOffset2; } }
    if ((var_s1 != ((void*)0)) && (*var_s1 != -1)) {
        sentinel = (signed char *)-1;
loop_72:
        { register signed char *arg0 asm("$4"); register int arg1 asm("$5"); register int arg2 asm("$6"); register int arg3 asm("$7");
          arg1 = var_fp; arg2 = var_s4; arg3 = 2; __asm__ volatile("" ::: "memory"); arg0 = *var_s1; var_s1 += 1;
          func_8002E748(arg0, arg1, arg2, arg3, ((void*)0)); }
        temp_a0_3 = DRAWUTIL_FIELD(var_s1, signed char **, 0);
        if (temp_a0_3 != sentinel) {
            DrawStringRightAligned(temp_a0_3, sp18, var_s4, 2);
            __asm__ volatile("" ::: "memory");
            var_s1 += 1;
            var_s4 += 0xE;
            if (*var_s1 != sentinel) {
                goto loop_72;
            }
        }
    }
    var_s4 = 0xC5;
    var_s1_3 = 1;
    if ((unsigned char) temp_s5[1] != 0xFF) {
        stringTable = &D_80069DE4;
        menuState = &D_8006FBCC;
        var_s0_2 = &temp_s5[1];
        do {
            temp_a0_4 = (unsigned char) *var_s0_2;
            if (temp_a0_4 != 0x2E) {
                temp_a0_3 = stringTable[D_8006C76C].stringsmaybe[temp_a0_4];
                if (D_8006C598 == 0) {
                    var_a3 = 0;
                    if (menuState->unk0 == var_s1_3) {
                        temp_v1_2 = DRAWUTIL_FIELD(menuState, int *, -8) & 0x1F; var_a3 = temp_v1_2 < 0x16;
                    }
                    var_a3_2 = var_a3 + 2;
                } else {
                    temp_v1_2 = (unsigned int) (D_8006FBCC.unk0 ^ var_s1_3) < 1U; var_a3_2 = temp_v1_2 + 2;
                }
                DrawStringCentered(temp_a0_3, 0x100, var_s4, var_a3_2);
            }
            var_s4 += 0xE;
            var_s0_2 += 1;
            var_s1_3 += 1;
        } while ((unsigned char) *var_s0_2 != 0xFF);
    }
}
#undef DRAWUTIL_FIELD

/**
 * ???() - func_80020D70() - MATCHING
 * https://decomp.me/scratch/iZDl3
 */
void func_80020D70() {
    func_80020530((signed char*)&D_80067570[pauseData.menuType]);
}

/**
 * DrawStringRowCentered() - func_80020DAC() - MATCHING
 * https://decomp.me/scratch/0lU0I
 */
void DrawStringRowCentered(char** arg0, int arg1, int arg2, int arg3) {
    int i;
    int var_s3;
    int var_s2 = 0;
    char **p = arg0;

    while (*p[var_s2] != 0) var_s2++;

    var_s3 = arg2 - var_s2 * 7;
    for (i = 0; i < var_s2; i++) {
        DrawStringCentered(arg0[i], arg1, var_s3, arg3);
        var_s3 += 14;
    }
}
