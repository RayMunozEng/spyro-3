#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008E694.
 * Assembly SHA256 2f89af3fa03475ef4403b47d16095013f4983142f87c0750df4fa6a9193462ad.
 * AI-generated; not human reviewed. All1800 original instructions and
 * 93 selectors (bias40) are required. Frame0x120 retains scratch10..104,
 * savedS0..S4, incoming slotS2 and combinedS3.
 * Seven exact groups and near50/128 reuse verified21/23/34/42/11 with
 * original concrete fields, frame/register maps and all actual branch targets.
 * Complete115..132 retains both mode40 callback/argument branches, signed
 * scalar/vector/trig arithmetic, control gates, byte flags, child writes and
 * original callbacks4454/432C. State122/123 uses ordinary signed /56 and /40
 * with an independent short scalar result; no high-product shortcut is used.
 * Ordinary product lifetimes preserve original T0 roles. Shared121 owns119's
 * clamp;130 owns the scalar/vector tails and +/-23/192 event stores;
 * 131's terminal callback remains after the switch at8009027C.
 * Original50 jumps to57's vector copy at8008F564, not the function epilogue.
 * Typed aliases remain distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit every word.
 * Identified Rev1 Agent9 tables/body contracts support interpretation;
 * every original Rev0 word, target and full retail hash remains authoritative.
 * Raw units/fixed point, complete helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every native/linked instruction, conditional/internal target,
 * selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Physics44Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
unsigned char Physics44Call41B64View1() __asm__("func_80041B64");
int Physics44Call4E9E4View1() __asm__("func_8004E9E4");
int Physics44Call4EA2CView1() __asm__("func_8004EA2C");
int Physics44Call4EDE8View1() __asm__("func_8004EDE8");
unsigned char Physics44Call4F08CView1() __asm__("func_8004F08C");
unsigned char Physics44Call4F194View1() __asm__("func_8004F194");
unsigned char Physics44Call4F1C8View1() __asm__("func_8004F1C8");
extern void *Physics44Data6C570View1 __asm__("D_8006C570");
extern unsigned char Physics44Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics44Player0View1 __asm__("D_80070328");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics44Call40D10View1() __asm__("func_80040D10");
int Physics44Call40F48View1() __asm__("func_80040F48");
int Physics44Call41580View1() __asm__("func_80041580");
int Physics44Call416F4View1() __asm__("func_800416F4");
int Physics44Call417FCView1() __asm__("func_800417FC");
int Physics44Call41848View1() __asm__("func_80041848");
int Physics44Call41B64View2() __asm__("func_80041B64");
int Physics44Call4E9E4View2() __asm__("func_8004E9E4");
int Physics44Call4EA2CView2() __asm__("func_8004EA2C");
int Physics44Call4EDE8View2() __asm__("func_8004EDE8");
int Physics44Call4F08CView2() __asm__("func_8004F08C");
int Physics44Call4F168View1() __asm__("func_8004F168");
int Physics44Call4F178View1() __asm__("func_8004F178");
int Physics44Call4F194View2() __asm__("func_8004F194");
int Physics44Call4F1C8View2() __asm__("func_8004F1C8");
extern short Physics44Data6E040View1 __asm__("D_8006E040");
extern int Physics44Data6E044View1 __asm__("D_8006E044");
extern int Physics44Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics44Player0View2 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics44PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics44Player94View1 __asm__("D_80070328+0x94");
extern int Physics44PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics44Player80View1 __asm__("D_80070328+0x80");
extern int Physics44PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics44Player64View1 __asm__("D_80070328+0x64");
extern int Physics44Player144View1 __asm__("D_80070328+0x144");
extern int Physics44Player60View1 __asm__("D_80070328+0x60");
extern int Physics44PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics44Player4CView1 __asm__("D_80070328+0x4C");
extern int Physics44Player5CView1 __asm__("D_80070328+0x5C");
extern unsigned char Physics44PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics44PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics44Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics44Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics44Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics44Player101View1 __asm__("D_80070328+0x101");
extern int Physics44PlayerA4View1 __asm__("D_80070328+0xA4");
int Physics44Call40F48View2() __asm__("func_80040F48");
int Physics44Call43194View1() __asm__("func_80043194");
int Physics44Call4E880View1() __asm__("func_8004E880");
int Physics44Call4ED6CView1() __asm__("func_8004ED6C");
int Physics44Call4EDE8View3() __asm__("func_8004EDE8");
int Physics44Call4F08CView3() __asm__("func_8004F08C");
int Physics44Call4F168View2() __asm__("func_8004F168");
int Physics44Call4F194View3() __asm__("func_8004F194");
int Physics44Call4F1C8View3() __asm__("func_8004F1C8");
extern int Physics44Data6E044View2 __asm__("D_8006E044");
extern unsigned char Physics44Player0View3 __asm__("D_80070328");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics12_SpawnParticle)() __asm__("SpawnParticle");
int Physics44Call40D10View2() __asm__("func_80040D10");
int Physics44Call410F8View1() __asm__("func_800410F8");
int Physics44Call41580View2() __asm__("func_80041580");
int Physics44Call417FCView2() __asm__("func_800417FC");
int Physics44Call41848View2() __asm__("func_80041848");
int Physics44Call41B64View3() __asm__("func_80041B64");
int Physics44Call4EA2CView3() __asm__("func_8004EA2C");
int Physics44Call4ED6CView2() __asm__("func_8004ED6C");
int Physics44Call4F110View1() __asm__("func_8004F110");
int Physics44Call4F168View3() __asm__("func_8004F168");
int Physics44Call4F178View2() __asm__("func_8004F178");
int Physics44Call4F194View4() __asm__("func_8004F194");
int Physics44CallRandView1() __asm__("rand");
extern int* Physics44Data6C570View2 __asm__("D_8006C570");
extern int Physics44Data6C640View1 __asm__("D_8006C640");
extern int Physics44Data6E044View3 __asm__("D_8006E044");
extern unsigned char Physics44Player0View4 __asm__("D_80070328");
extern void *(*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics44Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics44Player158View1 __asm__("D_80070328+0x158");
extern int Physics44Player20CView2 __asm__("D_80070328+0x20C");
extern void *(*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics44Player8CView2 __asm__("D_80070328+0x8C");
extern int Physics44Player80View2 __asm__("D_80070328+0x80");
extern void *(*Physics44_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Physics44Slot4454)() __asm__("unk_ovlheader_80074454");
extern int (*Physics44Slot432C)() __asm__("unk_ovlheader_8007432C");
extern int Physics44Player50View1 __asm__("D_80070328+0x50");
extern int Physics44Player250View1 __asm__("D_80070328+0x250");
int Physics44Call4E880View2() __asm__("func_8004E880");
void func_level_44_8008E694(int slotIndex) {
    int agentProduct0,agentProduct1,agentProduct2,agentProduct3,agentProduct4,agentProduct5,agentProduct6,agentProduct7;
    register void *fieldA4State28 __asm__("$16");
    register void *vector8CState28 __asm__("$17");
    register int signedWord19 __asm__("$20");
    register int signedWord20 __asm__("$21");
    register int signedWord21 __asm__("$22");
    register void *savedPointer22 __asm__("$19");
    register void *savedPointer17 __asm__("$17");
    register void *(*particleCall3)() __asm__("$3");
    register int particleArg7 __asm__("$7");
    register int workWord2 __asm__("$2");
    register int stateWord3 __asm__("$3");
    register void *vectorAt40 __asm__("$16");
    register void *vectorAt30 __asm__("$17");
    register void *call4 __asm__("$4");
    register void *call5 __asm__("$5");
    register void *call6 __asm__("$6");
    int lowProduct0,lowProduct1,lowProduct2,lowProduct3,lowProduct4,lowProduct5;
    register void *globalPointer __asm__("$3");
    struct {
        int sp10,sp14,sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4,spB8,spBC,spC0,spC4,spC8,spCC,spD0,spD4,spD8,spDC,spE0,spE4,spE8,spEC,spF0,spF4,spF8,spFC,sp100,sp104;
    }
    originalFrame;
    register void *globalVector80 __asm__("$16");
    register void *globalVector8CState20 __asm__("$18");
    register void *globalVector8C __asm__("$18");
    register void *var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$19");
    int temp_v0_4;
    register int workWord3 __asm__("$3");
    register void *globalField4CPointer __asm__("$16");
    register void *globalFieldA4Pointer __asm__("$17");
    register int savedSlotIndex __asm__("$18");
    int lowProduct6;
    int raw21_var_a0_2;
    int raw21_var_a1_4;
    void *raw21_temp_s0_9;
    int raw21_temp_a0_5;
    int raw21_temp_a0_6;
    int raw21_temp_a0_7;
    int raw21_temp_a1_2;
    int raw21_temp_a1_3;
    int raw21_temp_a1_4;
    int raw21_temp_s0_10;
    register int raw21_temp_s0_8 __asm__("$16");
    int raw21_temp_s1_4;
    int raw21_temp_v1_13;
    int raw21_temp_v1_14;
    int raw21_temp_v1_6;
    int raw21_temp_v1_7;
    int raw21_var_v0_2;
    void *raw21_temp_s0_11;
    void *raw21_temp_s0_7;
    register void *raw21_temp_s1_5 __asm__("$17");
    void *raw21_temp_s1_6;
    void *raw21_temp_s1_7;
    void *raw21_temp_s2_3;
    void *raw21_temp_s4;
    savedSlotIndex=slotIndex;
    workWord2=savedSlotIndex*16;
    globalPointer=&Physics44Data6E548View1;
    workWord2+=(int)globalPointer;
    __asm__("":"=r"(workWord2):"0"(workWord2));
    Physics44Data6C570View1=(void*)workWord2;
    workWord2=Physics44Field(&Physics44Player0View1,int*,0x54);
    stateWord3=Physics44Field(&Physics44Player0View1,int*,0x48);
    combinedIndex=workWord2+savedSlotIndex;
    switch (stateWord3) {
    case 40:{
            register int numeric4 __asm__("$4");
            call5=&Physics44Player20CView2;
            __asm__("":"=r"(call5):"0"(call5));
            workWord2=Physics44Field(call5,int*,0)&64;
            call4=&originalFrame.sp10;
            if(workWord2)goto block_132;
            call5-=192;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics44Call410F8View1(call4,call5,0);
            workWord3=Physics44Player4CView1;
            workWord2=1;
            if(workWord3==workWord2){
                workWord2=512;
                workWord3=Physics44Player60View1;
                numeric4=Physics44Player144View1;
                workWord2-=workWord3;
                workWord3=numeric4<<4;
                workWord2-=workWord3;
                workWord3=workWord2&4095;
                originalFrame.sp14=workWord3;
                workWord2=workWord3<2049;
                if(!workWord2){
                    workWord2=workWord3-4096;
                    __asm__("":"=r"(workWord2):"0"(workWord2));
                    originalFrame.sp14=workWord2;
                }
                __asm__ volatile("":::"memory");
                workWord2=originalFrame.sp14;
                workWord3=numeric4+1;
                Physics44Player144View1=workWord3;
                workWord3=workWord3<21;
                workWord2=(workWord2<<7)>>8;
                originalFrame.sp14=workWord2;
                if(!workWord3){
                    __asm__ volatile("":"=r"(workWord3):"0"(workWord3));
                    Physics44Player4CView1=0;
                }
            }
            raw21_temp_s1_4 = (int) (originalFrame.sp10 * 0x14) >> 7;
            Physics44Field(&Physics44Player0View4, int *, 0x64) = (int) ((Physics44Field(&Physics44Player0View4, int *, 0x64) + raw21_temp_s1_4) & 0xFFF);
            raw21_temp_v1_6 = (Physics44Field(&Physics44Player0View4, int *, 0x60) + ((int) (originalFrame.sp14 * -0xF) >> 7)) & 0xFFF;
            Physics44Field(&Physics44Player0View4, int *, 0x60) = raw21_temp_v1_6;
            if (raw21_temp_v1_6 >= 0x801) {
                Physics44Field(&Physics44Player0View4, int *, 0x60) = (int) (raw21_temp_v1_6 - 0x1000);
            }
            if (Physics44Field(&Physics44Player0View4, int *, 0x60) < -0x320) {
                Physics44Field(&Physics44Player0View4, int *, 0x60) = -0x320;
            }
            if (Physics44Field(&Physics44Player0View4, int *, 0x60) >= 0x321) {
                Physics44Field(&Physics44Player0View4, int *, 0x60) = 0x320;
            }
            if ((*Physics44Data6C570View2 & 0x40) || (Physics44Field(&Physics44Player0View4, int *, 0x4C) == 1)) {
                Physics44Field(&Physics44Player0View4, int *, 0xAC) = 0xE00;
            }
            else {
                Physics44Field(&Physics44Player0View4, int *, 0xAC) = 0;
            }
            if (Physics44Field(&Physics44Player0View4, int *, 0x4C) == 2) {
                Physics44Call417FCView2(0xC0, 0xC0);
                if (Physics44Field(&Physics44Player0View4, int *, 0xB0) < 0xE01) {
                    Physics44Field(&Physics44Player0View4, int *, 0x4C) = 0;
                }
            }
            else {
                Physics44Call417FCView2(0xC0, 0x30);
            }
            raw21_temp_s0_7 = &Physics44Player0View4 + 0x60;
            raw21_temp_a0_5 = (((int) (raw21_temp_s1_4 * -(Physics44Call4EA2CView3(Physics44Field(&Physics44Player0View4, int *, 0x60)) << 5)) >> 0xC) - ((int) (Physics44Field(&Physics44Player0View4, int *, 0x14C) * 0x10) >> 6)) - ((int) (Physics44Field(&Physics44Player0View4, int *, 0x5C) << 6) >> 6);
            raw21_temp_v1_7 = Physics44Field(&Physics44Player0View4, int *, 0x14C) + raw21_temp_a0_5;
            Physics44Field(&Physics44Player0View4, int *, 0x14C) = raw21_temp_v1_7;
            raw21_temp_a1_2 = (Physics44Field(&Physics44Player0View4, int *, 0x5C) + (raw21_temp_v1_7 >> 6)) & 0xFFF;
            Physics44Field(&Physics44Player0View4, int *, 0x5C) = raw21_temp_a1_2;
            if (raw21_temp_a1_2 >= 0x801) {
                Physics44Field(&Physics44Player0View4, int *, 0x5C) = (int) (raw21_temp_a1_2 - 0x1000);
            }
            if (Physics44Field(&Physics44Player0View4, int *, 0x5C) < -0x300) {
                Physics44Field(&Physics44Player0View4, int *, 0x5C) = -0x300;
            }
            if (Physics44Field(&Physics44Player0View4, int *, 0x5C) >= 0x301) {
                Physics44Field(&Physics44Player0View4, int *, 0x5C) = 0x300;
            }
            Physics44Call41848View2(raw21_temp_a0_5, raw21_temp_a1_2);
            Physics44Call4F178View2(raw21_temp_s0_7 + 0x2C, raw21_temp_s0_7 + 0x20);
            workWord2=Physics44CallRandView1()&31;
            if(workWord2)goto block_130;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            particleCall3=Physics21_SpawnParticle;
            call4=(void*)1;
            if(!particleCall3)goto block_130;
            call5=(void*)44;
            call6=&originalFrame.sp18;
            particleArg7=0;
            __asm__("":"=r"(particleArg7):"0"(particleArg7));
            workWord2=544;
            originalFrame.sp18=workWord2;
            workWord2=64;
            originalFrame.sp1C=0;
            __asm__ volatile(""::"i"(0x8008E9FC):"memory");
            originalFrame.sp20=workWord2;
            goto block_129;
        }
    case 41:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            int product41;
            raw21_temp_s1_5 = &Physics44Player0View4 + 0x20C;
            if (!(Physics44Field(&Physics44Player0View4, int *, 0x20C) & 0x40)) {
                if (Physics44Data6E044View3 != 7) {
                    Physics44Call410F8View1(&originalFrame.sp18, raw21_temp_s1_5 - 0xC0, 0);
                    workWord3=originalFrame.sp18;
                    numeric4=originalFrame.sp1C;
                    workWord2=workWord3*5;
                    workWord2<<=2;
                    raw21_temp_s0_8=workWord2>>7;
                    workWord2=numeric4<<4;
                    numeric4-=workWord2;
                    numeric4>>=7;
                    workWord3=Physics44Player64View1;
                    workWord2=Physics44Player60View1;
                    workWord3+=raw21_temp_s0_8;
                    workWord3&=4095;
                    workWord2+=numeric4;
                    Physics44Player64View1=workWord3;
                    workWord3=workWord2&4095;
                    workWord2=workWord3<2049;
                    Physics44Player60View1=workWord3;
                    if(!workWord2){
                        workWord2=workWord3-4096;
                        __asm__("":"=r"(workWord2):"0"(workWord2));
                        Physics44Player60View1=workWord2;
                    }
                    if (Physics44Field(&Physics44Player0View4, int *, 0x60) < -0x320) {
                        Physics44Field(&Physics44Player0View4, int *, 0x60) = -0x320;
                    }
                    if (Physics44Field(&Physics44Player0View4, int *, 0x60) >= 0x321) {
                        Physics44Field(&Physics44Player0View4, int *, 0x60) = 0x320;
                    }
                    workWord2=Physics44Call4EA2CView3(Physics44Player60View1);
                    workWord2<<=5;
                    workWord2=-workWord2;
                    product41=raw21_temp_s0_8*workWord2;
                    workWord3=Physics44Field(raw21_temp_s1_5,int*,-192);
                    numeric5=Physics44Player5CView1;
                    workWord2=(workWord3<<4)>>6;
                    numeric4=product41>>12;
                    numeric4-=workWord2;
                    workWord2=(numeric5<<6)>>6;
                    numeric4-=workWord2;
                    workWord3+=numeric4;
                    Physics44Field(raw21_temp_s1_5,int*,-192)=workWord3;
                    workWord3>>=6;
                    numeric5+=workWord3;
                    numeric5&=4095;
                    workWord2=numeric5<2049;
                    Physics44Player5CView1=numeric5;
                    if(!workWord2){
                        workWord2=numeric5-4096;
                        __asm__("":"=r"(workWord2):"0"(workWord2));
                        Physics44Player5CView1=workWord2;
                    }
                    if (Physics44Field(&Physics44Player0View4, int *, 0x5C) < -0x300) {
                        Physics44Field(&Physics44Player0View4, int *, 0x5C) = -0x300;
                    }
                    if (Physics44Field(&Physics44Player0View4, int *, 0x5C) >= 0x301) {
                        Physics44Field(&Physics44Player0View4, int *, 0x5C) = 0x300;
                    }
                }
                raw21_temp_s0_9 = &Physics44Player0View4 + 0x80;
                Physics44Call4F168View3(raw21_temp_s0_9);
                Physics44Call4F168View3(raw21_temp_s0_9 + 0xC);
                workWord2=Physics44CallRandView1()&31;
                if(workWord2)goto block_130;
                __asm__("":"=r"(workWord2):"0"(workWord2));
                particleCall3=Physics21_SpawnParticle;
                call4=(void*)1;
                if(!particleCall3)goto block_130;
                call5=(void*)44;
                call6=&originalFrame.sp28;
                particleArg7=0;
                __asm__("":"=r"(particleArg7):"0"(particleArg7));
                workWord2=544;
                originalFrame.sp28=workWord2;
                workWord2=64;
                originalFrame.sp2C=0;
                originalFrame.sp30=workWord2;
                block_129:particleCall3(call4,call5,call6,particleArg7);
                block_130:globalPointer=&Physics44Player158View1;
                workWord2=Physics44Field(globalPointer,int*,0);
                workWord2++;
                __asm__ volatile(""::"i"(0x8008EC18):"memory");
                Physics44Field(globalPointer,int*,0)=workWord2;
                return;
            }
            goto block_132;
        }
    case 42:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            call5=&Physics44Player20CView2;
            __asm__("":"=r"(call5):"0"(call5));
            workWord2=Physics44Field(call5,int*,0)&64;
            call4=&originalFrame.sp28;
            if(!workWord2)goto run42;
            block_132:Physics44PlayerACView1=0;
            Physics44PlayerB0View1=0;
            return;
            run42:call5-=192;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics44Call410F8View1(call4,call5,0);
            workWord3=Physics44Player4CView1;
            workWord2=1;
            if(workWord3==workWord2){
                workWord2=512;
                workWord3=Physics44Player60View1;
                numeric5=Physics44Player144View1;
                workWord2-=workWord3;
                workWord3=numeric5<<4;
                workWord2-=workWord3;
                workWord3=workWord2&4095;
                originalFrame.sp2C=workWord3;
                workWord2=workWord3<2049;
                if(!workWord2){
                    workWord2=workWord3-4096;
                    __asm__("":"=r"(workWord2):"0"(workWord2));
                    originalFrame.sp2C=workWord2;
                }
                __asm__ volatile("":::"memory");
                numeric4=originalFrame.sp2C;
                workWord3=numeric5+1;
                Physics44Player144View1=workWord3;
                workWord3=workWord3<13;
                workWord2=numeric4*3;
                workWord2<<=5;
                workWord2>>=8;
                originalFrame.sp2C=workWord2;
                if(!workWord3){
                    __asm__ volatile("":"=r"(workWord3):"0"(workWord3));
                    Physics44Player4CView1=0;
                }
            }
            raw21_temp_s1_6 = &Physics44Player0View4 + 0x64;
            raw21_temp_s0_10 = (int) (originalFrame.sp28 * 0x14) >> 7;
            Physics44Field(&Physics44Player0View4, int *, 0x64) = (int) ((Physics44Field(&Physics44Player0View4, int *, 0x64) + raw21_temp_s0_10) & 0xFFF);
            raw21_temp_v1_13 = (Physics44Field(&Physics44Player0View4, int *, 0x60) + ((int) (originalFrame.sp2C * -0xF) >> 7)) & 0xFFF;
            Physics44Field(&Physics44Player0View4, int *, 0x60) = raw21_temp_v1_13;
            if (raw21_temp_v1_13 >= 0x801) {
                Physics44Field(&Physics44Player0View4, int *, 0x60) = (int) (raw21_temp_v1_13 - 0x1000);
            }
            if (Physics44Field(&Physics44Player0View4, int *, 0x60) < -0x320) {
                Physics44Field(&Physics44Player0View4, int *, 0x60) = -0x320;
            }
            if (Physics44Field(&Physics44Player0View4, int *, 0x60) >= 0x321) {
                Physics44Field(&Physics44Player0View4, int *, 0x60) = 0x320;
            }
            Physics44Field(&Physics44Player0View4, int *, 0xAC) = 0x1C00;
            Physics44Call417FCView2(0x240, 0x30);
            raw21_temp_a0_6 = (((int) (raw21_temp_s0_10 * -(Physics44Call4EA2CView3(Physics44Field(&Physics44Player0View4, int *, 0x60)) << 5)) >> 0xC) - ((int) (Physics44Field(&Physics44Player0View4, int *, 0x14C) * 0x10) >> 6)) - ((int) (Physics44Field(&Physics44Player0View4, int *, 0x5C) << 6) >> 6);
            raw21_temp_v1_14 = Physics44Field(&Physics44Player0View4, int *, 0x14C) + raw21_temp_a0_6;
            Physics44Field(&Physics44Player0View4, int *, 0x14C) = raw21_temp_v1_14;
            raw21_temp_a1_3 = (Physics44Field(&Physics44Player0View4, int *, 0x5C) + (raw21_temp_v1_14 >> 6)) & 0xFFF;
            Physics44Field(&Physics44Player0View4, int *, 0x5C) = raw21_temp_a1_3;
            if (raw21_temp_a1_3 >= 0x801) {
                Physics44Field(&Physics44Player0View4, int *, 0x5C) = (int) (raw21_temp_a1_3 - 0x1000);
            }
            if (Physics44Field(&Physics44Player0View4, int *, 0x5C) < -0x300) {
                Physics44Field(&Physics44Player0View4, int *, 0x5C) = -0x300;
            }
            if (Physics44Field(&Physics44Player0View4, int *, 0x5C) >= 0x301) {
                Physics44Field(&Physics44Player0View4, int *, 0x5C) = 0x300;
            }
            Physics44Call41848View2(raw21_temp_a0_6, raw21_temp_a1_3);
            Physics44Call4F178View2(raw21_temp_s1_6 + 0x28, raw21_temp_s1_6 + 0x1C);
            if ((Physics21_SpawnParticle != 0) && (Physics44Field(&Physics44Player0View4, int *, 0xB4) >= 0x7D1)) {
                originalFrame.sp38 = -0x190;
                originalFrame.sp3C = 0x40 - (Physics44CallRandView1() & 0x7F);
                originalFrame.sp40 = -0x12C;
                Physics21_SpawnParticle(1, 0x2C, &originalFrame.sp38, 0);
                return;
            }
            break;
        }
    default:
        return;
    case 43:case 44:globalField4CPointer=&Physics44Player4CView1;
        __asm__("":"=r"(globalField4CPointer):"0"(globalField4CPointer));
        workWord3=Physics44Field(globalField4CPointer,int*,0);
        workWord2=1;
        if(workWord3==workWord2)goto clear47Calls;
        continue43:workWord2=7;
        workWord3=Physics44Data6E044View3;
        if (workWord3 == workWord2) {
            Physics44Field(&Physics44Player0View4, int *, 0xB0) = 0;
        }
        else {
            Physics44Call40D10View2(0x980);
            raw21_var_v0_2 = Physics44Call41580View2(0x5A, 0x10);
            if (raw21_var_v0_2 < 0) {
                raw21_var_v0_2 = -raw21_var_v0_2;
            }
            if (raw21_var_v0_2 >= 0x201) {
                Physics44Field(&Physics44Player0View4, int *, 0xAC) = 0;
            }
            raw21_var_a0_2 = 0xC0;
            if (Physics44Field(&Physics44Player0View4, int *, 0xB0) >= 0xC81) {
                raw21_var_a0_2 = 0;
                raw21_var_a1_4 = 0xC0;
            }
            else {
                raw21_var_a1_4 = 0x40;
            }
            Physics44Call417FCView2(raw21_var_a0_2, raw21_var_a1_4);
        }
        raw21_temp_s0_11 = &Physics44Player0View4 + 0xB0;
        if (Physics44Field(&Physics44Player0View4, int *, 0xB0) != 0) {
            Physics44Call41848View2();
            Physics44Call41B64View3();
            Physics44Field(&Physics44Player0View4, int *, 0x94) = 0;
        }
        else {
            Physics44Call4F168View3(raw21_temp_s0_11 - 0x30);
            Physics44Call4F168View3(raw21_temp_s0_11 - 0x24);
        }
        if (Physics21_SpawnParticle != 0) {
            raw21_temp_s4 = &Physics44Player0View4 + 0x28;
            if (Physics44Field(&Physics44Player0View4, int *, 0x28) < 0) {
                if ((Physics44Field(&Physics44Player0View4, int *, 0xB0) >= 0x401) && (savedSlotIndex < 2) && (Physics44Data6C640View1 & 1)) {
                    Physics44Call4F178View2(&originalFrame.sp38, raw21_temp_s4 - 0x28);
                    originalFrame.sp4C = 0x40;
                    originalFrame.sp50 = 0;
                    originalFrame.sp48 = (int) Physics44Field(&Physics44Player0View4, int *, 0xB0) >> 5;
                    if (savedSlotIndex != 0) {
                        originalFrame.sp4C = -0x40;
                    }
                    raw21_temp_s2_3 = raw21_temp_s4 + 8;
                    Physics44Call4ED6CView2(raw21_temp_s2_3, &originalFrame.sp48, &originalFrame.sp58);
                    Physics44Call4F194View4(&originalFrame.sp38, &originalFrame.sp38, &originalFrame.sp58);
                    originalFrame.sp48 = 0;
                    originalFrame.sp40 = -Physics44Field(&Physics44Player0View4, int *, 0x28);
                    Physics44Call4ED6CView2(raw21_temp_s2_3, &originalFrame.sp48, &originalFrame.sp48);
                    Physics44Call4F110View1(&originalFrame.sp48, 3);
                    Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp38, &originalFrame.sp48);
                    if (!(Physics44CallRandView1() & 0x1F)) {
                        Physics21_SpawnParticle(1, 0x29, &originalFrame.sp38, 0);
                    }
                }
                else {
                    raw21_temp_s1_7 = &Physics44Player0View4 + 0xB0;
                    if ((Physics44Field(&Physics44Player0View4, int *, 0xB0) < 0x201) && (savedSlotIndex == 0) && !(Physics44Data6C640View1 & 7) && !(Physics44CallRandView1() & 3)) {
                        originalFrame.sp68 = 0x80;
                        __asm__("":"=r"(savedSlotIndex):"0"(savedSlotIndex));
                        originalFrame.sp6C = 0;
                        originalFrame.sp70 = 0;
                        Physics44Call4ED6CView2(raw21_temp_s1_7 - 0x80, &originalFrame.sp68, &originalFrame.sp68);
                        Physics44Call4F194View4(&originalFrame.sp68, &originalFrame.sp68, raw21_temp_s1_7 - 0xB0);
                        originalFrame.sp70 = -Physics44Field(&Physics44Player0View4, int *, 0x28);
                        Physics21_SpawnParticle(1, 0x2B, &originalFrame.sp68, (int *)1);
                    }
                }
            }
        }
        raw21_temp_a1_4 = Physics44Field(&Physics44Player0View4, int *, 0x144) - ((int) ((Physics44Field(&Physics44Player0View4, int *, 0x148) * 2) + (Physics44Field(&Physics44Player0View4, int *, 0x144) * 0x14)) >> 8);
        raw21_temp_a0_7 = Physics44Field(&Physics44Player0View4, int *, 0x148) + raw21_temp_a1_4;
        Physics44Field(&Physics44Player0View4, int *, 0x144) = raw21_temp_a1_4;
        Physics44Field(&Physics44Player0View4, int *, 0x148) = raw21_temp_a0_7;
        if (raw21_temp_a0_7 >= 0x5901) {
            Physics44Field(&Physics44Player0View4, int *, 0x148) = 0x5900;
        }
        if (Physics44Field(&Physics44Player0View4, int *, 0x148) < -0x5900) {
            Physics44Field(&Physics44Player0View4, int *, 0x148) = -0x5900;
            return;
        }
        break;
    case 47:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            workWord3=Physics44Data6E044View2;
            workWord2=7;
            if(workWord3==workWord2)goto zero47;
            Physics44Call40F48View2(&originalFrame.sp58,0);
            workWord2=originalFrame.sp58;
            numeric6=originalFrame.sp5C;
            originalFrame.sp78=0;
            workWord3=(workWord2*9<<7)>>7;
            workWord2=(numeric6*3<<9)>>7;
            originalFrame.sp58=workWord3;
            workWord3=-workWord3;
            originalFrame.sp5C=workWord2;
            originalFrame.sp7C=workWord3;
            originalFrame.sp80=workWord2;
            workWord2=Physics44Call4EDE8View3(&originalFrame.sp78,0,numeric6);
            numeric4=originalFrame.sp80;
            workWord3=numeric4;
            if(numeric4<0){
                __asm__("":"=r"(workWord3):"0"(workWord3));
                workWord3=-workWord3;
            }
            workWord3=workWord3<workWord2;
            if(workWord3){
                workWord2=originalFrame.sp7C;
                originalFrame.sp80=0;
                __asm__ volatile("":::"$4");
                numeric4=0;
                if(workWord2>0){
                    __asm__ volatile(""::"i"(0x8008F2D4):"memory");
                    numeric4=1;
                }
                if(!Physics44Call43194View1(numeric4)){
                    originalFrame.sp7C=0;
                }
            }
            else{
                __asm__ volatile("":::"$3");
                originalFrame.sp7C=0;
                originalFrame.sp78=0;
                if(numeric4>0){
                    __asm__ volatile(""::"i"(0x8008F2FC):"memory");
                    numeric4=2;
                }
                else numeric4=3;
                if(!Physics44Call43194View1(numeric4)){
                    originalFrame.sp80=0;
                }
            }
            call4=&originalFrame.sp78;
            workWord2=Physics44Call4EDE8View3(call4,1);
            Physics44PlayerACView1=workWord2;
            __asm__ volatile(""::"i"(0x8008F32C):"memory");
            goto clear47;
            zero47:Physics44PlayerACView1=0;
            clear47:globalVector80=&Physics44Player80View1;
            __asm__ volatile(""::"r"(globalVector80):"memory");
            clear47Calls:call4=&Physics44Player80View2;
            __asm__("":"=r"(call4):"0"(call4));
            Physics44Call4F168View2(call4);
            call4=&Physics44Player8CView2;
            __asm__("":"=r"(call4):"0"(call4));
            Physics44Call4F168View2(call4);
            return;
        }
    case 0x32:
    case 0x33:
    case 52:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            Physics44Call40F48View2(&originalFrame.sp88,0);
            workWord2=originalFrame.sp88;
            numeric6=originalFrame.sp8C;
            originalFrame.sp90=0;
            workWord3=(workWord2*9<<7)>>7;
            workWord2=(numeric6*3<<9)>>7;
            originalFrame.sp88=workWord3;
            workWord3=-workWord3;
            originalFrame.sp8C=workWord2;
            originalFrame.sp94=workWord3;
            originalFrame.sp98=workWord2;
            workWord2=Physics44Call4EDE8View3(&originalFrame.sp90,0,numeric6);
            numeric4=originalFrame.sp98;
            workWord3=numeric4;
            if(numeric4<0){
                __asm__("":"=r"(workWord3):"0"(workWord3));
                workWord3=-workWord3;
            }
            workWord3=workWord3<workWord2;
            if(workWord3){
                workWord2=originalFrame.sp94;
                originalFrame.sp98=0;
                __asm__ volatile("":::"$4");
                numeric4=0;
                if(workWord2>0){
                    __asm__ volatile(""::"i"(0x8008F3F4):"memory");
                    numeric4=1;
                }
                if(!Physics44Call43194View1(numeric4)){
                    originalFrame.sp94=0;
                }
            }
            else{
                __asm__ volatile("":::"$3");
                originalFrame.sp94=0;
                originalFrame.sp90=0;
                if(numeric4>0){
                    __asm__ volatile(""::"i"(0x8008F41C):"memory");
                    numeric4=2;
                }
                else numeric4=3;
                if(!Physics44Call43194View1(numeric4)){
                    originalFrame.sp98=0;
                }
            }
            vectorAt30=&originalFrame.sp90;
            workWord2=Physics44Call4EDE8View3(vectorAt30,1);
            numeric6=1;
            __asm__("":"=r"(numeric6):"0"(numeric6));
            numeric4=originalFrame.sp88;
            numeric5=originalFrame.sp8C;
            globalVector80=&Physics44PlayerACView1;
            Physics44Field(globalVector80,int*,0)=workWord2;
            workWord2=Physics44Call4E880View1(numeric4,numeric5,numeric6);
            workWord3=workWord2;
            workWord2=workWord3<2049;
            Physics44PlayerA4View1=workWord3;
            call4=globalVector80-124;
            if(!workWord2){
                workWord2=workWord3-4096;
                Physics44PlayerA4View1=workWord2;
            }
            call5=vectorAt30;
            workWord2=originalFrame.sp90;
            call6=vectorAt30;
            workWord2+=1024;
            originalFrame.sp90=workWord2;
            Physics44Call4ED6CView1(call4,call5,call6);
            call4=vectorAt30;
            call5=vectorAt30;
            __asm__("":"=r"(globalVector80):"0"(globalVector80),"r"(call4),"r"(call5));
            globalVector8CState20=globalVector80-32;
            Physics44Call4F1C8View3(call4,call5,globalVector8CState20);
            call5=(void*)Physics44Call4EDE8View3(vectorAt30,0);
            workWord2=(int)call5<385;
            if(!workWord2)Physics44Call4F08CView3(vectorAt30,call5,384);
            globalVector80-=44;
            __asm__("":"=r"(globalVector80):"0"(globalVector80));
            Physics44Call4F194View3(globalVector80,globalVector8CState20,vectorAt30);
            goto block_188;
        }
    case 57:if ((workWord2=combinedIndex<9)==0) {
            Physics44Field(&Physics44Player0View4, int *, 0x80) = (int) (Physics44Field(&Physics44Player0View4, int *, 0x8C) * 0xF8);
            Physics44Field(&Physics44Player0View4, int *, 0x84) = (int) (Physics44Field(&Physics44Player0View4, int *, 0x90) * 0xF8);
            Physics44Field(&Physics44Player0View4, int *, 0x88) = (int) (Physics44Field(&Physics44Player0View4, int *, 0x94) * 0xF8);
            Physics44Call4F110View1(&Physics44Player0View4 + 0x80, 8);
        }
        block_188:call4=&Physics44Player8CView1;
        call5=&Physics44Player80View1;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        Physics44Call4F178View2(call4,call5);
        return;
    case 128:globalVector80=&Physics44Player0View2+0xB8;
        workWord2=Physics44Field(globalVector80,int*,0);
        if(!workWord2)goto zero128;
        vectorAt30=&originalFrame.spA0;
        Physics44Call4F168View1(vectorAt30);
        call4=vectorAt30;
        call5=vectorAt30;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalVector8CState20=globalVector80-44;
        Physics44Call4F1C8View2(call4,call5,globalVector8CState20);
        originalFrame.spA8=0;
        call5=(void*)Physics44Call4EDE8View2(vectorAt30,0);
        workWord2=(int)call5<65;
        if(!workWord2)Physics44Call4F08CView2(vectorAt30,call5,64);
        originalFrame.spA8=-192;
        globalVector80-=56;
        Physics44Call4F194View2(globalVector80,globalVector8CState20,vectorAt30);
        Physics44Call4F178View1(globalVector8CState20,globalVector80);
        goto clamp128;
        zero128:Physics44Call4F168View1(globalVector80-56);
        Physics44Call4F168View1(globalVector80-44);
        goto clamp128;
        clamp128:globalPointer=&Physics44Player94View1;
        workWord2=Physics44Field(globalPointer,int*,0);
        workWord2=workWord2<-8960;
        if(workWord2){
            workWord2=-8960;
            Physics44Field(globalPointer,int*,0)=workWord2;
        }
        return;
    case 115:case 120:case 126:
        globalVector80=&Physics44Player80View1;
        Physics44Call4F168View1(globalVector80);
        Physics44Call4F168View1(globalVector80+12);
        workWord3=Physics44Data6E044View1;
        workWord2=40;
        if(workWord3!=workWord2)goto ordinary115;
        Physics44Slot4454();
        goto bytes115;
        ordinary115:workWord2=31;
        if(workWord3==workWord2)goto bytes115;
        Physics44Call40D10View1(3840);
        Physics44Call416F4View1();
        Physics44Call41580View1(90,16);
        bytes115:globalPointer=&Physics44Player1BAView1;
        workWord2=Physics44Field(globalPointer,unsigned char*,0);
        if(!workWord2)goto byteOne115;
        workWord2=Physics44Data6E538View1&16;
        if(workWord2)return;
        workWord2=1;
        Physics44Field(globalPointer,unsigned char*,0)=0;
        Physics44Player1B9View1=workWord2;
        return;
        byteOne115:workWord2=1;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        Physics44Player1B9View1=workWord2;
        return;
    case 116:case 117:{
            register void *mode16 __asm__("$16");
            register int mode17 __asm__("$17");
            register int callback18 __asm__("$18");
            mode16=&Physics44Data6E044View1;
            workWord3=Physics44Field(mode16,int*,0);
            mode17=40;
            if(workWord3==mode17)goto callback131;
            workWord2=8;
            if(workWord3!=workWord2)Physics44Call40D10View1(3840);
            workWord2=Physics44Data6E538View1&12;
            if(workWord2)Physics44PlayerACView1=0;
            workWord2=Physics44Call416F4View1();
            workWord3=Physics44Field(mode16,int*,0);
            callback18=workWord2;
            if(workWord3==mode17){
                call4=(void*)30;
                call5=(void*)1;
            }
            else{
                call4=(void*)90;
                call5=(void*)16;
            }
            workWord2=Physics44Call41580View1(call4,call5);
            workWord3=workWord2;
            workWord2=Physics44PlayerA8View1;
            if(workWord2<0)workWord2=-workWord2;
            workWord2=workWord2<8;
            if(!workWord2)goto reset116;
            workWord2=Physics44Data6E538View1&12;
            if(!workWord2)goto reset116;
            workWord2=Physics44Player144View1;
            workWord2++;
            Physics44Player144View1=workWord2;
            goto saved116;
            reset116:Physics44Player144View1=0;
            saved116:call4=&Physics44PlayerACView1;
            globalVector80=(void*)Physics44Field(call4,int*,0);
            if(callback18)goto collision116;
            workWord2=workWord3;
            if(workWord3<0)workWord2=-workWord2;
            workWord2=workWord2<513;
            if(workWord2)goto pass116;
            collision116:workWord2=Physics44Player20CView1&64;
            if(workWord2)Physics44Field(call4,int*,0)=0;
            else{
                workWord3=Physics44PlayerB0View1;
                workWord2=workWord3<(int)globalVector80;
                if(workWord2)Physics44Field(call4,int*,0)=workWord3;
            }
            pass116:Physics44Call417FCView1(320,192);
            workWord2=Physics44Player101View1;
            call4=&Physics44PlayerACView1;
            Physics44Field(call4,int*,0)=(int)globalVector80;
            if(workWord2){
                Physics44Call4F168View1(call4-32);
                goto fields116;
            }
            Physics44Call41848View1(call4);
            Physics44Call41B64View2();
            fields116:call6=&Physics44PlayerFCView1;
            workWord2=Physics44Field(call6,unsigned char*,0);
            if(workWord2)goto scalar130;
            workWord2=Physics44PlayerB8View1;
            call4=call6-112;
            if(workWord2)goto scalar130;
            goto vector130Input;
        }
    case 131:case 132:goto callback131;
    case 118:
        Physics44Call40D10View1(3200);
        workWord3=Physics44Data6E044View1;
        workWord2=40;
        call4=(void*)40;
        if(workWord3==workWord2){
            call4=(void*)30;
            call5=(void*)1;
        }
        else call5=(void*)8;
        Physics44Call41580View1(call4,call5);
        Physics44Call417FCView1(320,192);
        globalFieldA4Pointer=&Physics44PlayerA4View1;
        globalVector8C=globalFieldA4Pointer-24;
        workWord2=Physics44Call4EA2CView1(Physics44Field(globalFieldA4Pointer,int*,0));
        workWord3=Physics44PlayerB0View1;
        agentProduct0=workWord3*workWord2;
        call4=(void*)Physics44Field(globalFieldA4Pointer,int*,0);
        workWord2=agentProduct0>>12;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        originalFrame.spB0=workWord2;
        workWord2=Physics44Call4E9E4View1(call4);
        workWord3=Physics44PlayerB0View1;
        agentProduct1=workWord3*workWord2;
        vectorAt40=&originalFrame.spB0;
        call4=vectorAt40;
        call5=vectorAt40;
        call6=globalVector8C;
        workWord2=agentProduct1>>12;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        originalFrame.spB4=workWord2;
        Physics44Call4F1C8View1(call4,call5,call6);
        call4=vectorAt40;
        call5=0;
        __asm__ volatile(""::"r"(call4),"r"(call5):"memory");
        originalFrame.spB8=0;
        vector118Read:__asm__ volatile(""::"i"(0x8008F980):"memory");
        workWord2=Physics44Call4EDE8View1(call4,call5);
        __asm__ volatile(""::"r"(workWord2):"memory");
        call5=(void*)workWord2;
        __asm__ volatile(""::"r"(call5):"memory");
        workWord2=(int)call5<641;
        __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
        call4=globalFieldA4Pointer-36;
        if(!workWord2){
            Physics44Call4F08CView1(vectorAt40,call5,640);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            call4=globalFieldA4Pointer-36;
        }
        Physics44Call4F194View1(call4,globalVector8C,vectorAt40);
        Physics44Call41B64View1();
        gate118:__asm__ volatile(""::"i"(0x8008F9BC):"memory");
        workWord2=combinedIndex<13;
        if(!workWord2)goto subtract192_130;
        workWord2=Physics44Player4CView1;
        __asm__ volatile(""::"i"(0x8008F9D4):"memory");
        if(workWord2)goto subtract192_130;
        workWord2=(int)Physics44Data6C570View1;
        workWord2=Physics44Field((void*)workWord2,int*,0)&64;
        if(workWord2)goto add23_130;
        workWord2=Physics44Player144View1;
        __asm__ volatile(""::"i"(0x8008FA08):"memory");
        if(!workWord2)goto subtract192_130;
        __asm__ volatile(""::"i"(0x8008FA10):"memory");
        goto add23_130;
    case 119:globalFieldA4Pointer=&Physics44Player50View1;
        workWord3=Physics44Field(globalFieldA4Pointer,int*,0);
        workWord2=3;
        if(workWord3!=workWord2)goto airborne119;
        Physics44Call40D10View1(1600);
        Physics44Call41580View1(22,4);
        Physics44Call417FCView1(320,192);
        globalVector8C=globalFieldA4Pointer+60;
        workWord2=Physics44Call4EA2CView1(Physics44PlayerA4View1);
        workWord3=Physics44PlayerB0View1;
        agentProduct2=workWord3*workWord2;
        call4=(void*)Physics44PlayerA4View1;
        workWord2=agentProduct2>>12;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        originalFrame.spC0=workWord2;
        workWord2=Physics44Call4E9E4View1(call4);
        workWord3=Physics44PlayerB0View1;
        agentProduct3=workWord3*workWord2;
        vectorAt40=&originalFrame.spC0;
        call4=vectorAt40;
        call5=vectorAt40;
        call6=globalVector8C;
        workWord2=agentProduct3>>12;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        originalFrame.spC4=workWord2;
        Physics44Call4F1C8View1(call4,call5,call6);
        originalFrame.spC8=0;
        temp_v0_4=Physics44Call4EDE8View1(vectorAt40,0);
        __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
        var_a0_3=globalFieldA4Pointer+48;
        if(temp_v0_4>=321){
            Physics44Call4F08CView1(vectorAt40,temp_v0_4,320);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3=globalFieldA4Pointer+48;
        }
        Physics44Call4F194View1(var_a0_3,globalVector8C,vectorAt40);
        Physics44Call41B64View1();
        workWord2=Physics44Player94View1;
        workWord2-=192;
        Physics44Player94View1=workWord2;
        workWord2=workWord2<-8960;
        goto clamp119;
        airborne119:Physics44Call40D10View1(3200);
        workWord3=Physics44Data6E044View1;
        workWord2=40;
        call4=(void*)40;
        if(workWord3==workWord2){
            call4=(void*)30;
            call5=(void*)1;
        }
        else call5=(void*)8;
        Physics44Call41580View1(call4,call5);
        Physics44Call417FCView1(320,192);
        globalFieldA4Pointer=&Physics44PlayerA4View1;
        globalVector8C=globalFieldA4Pointer-24;
        workWord2=Physics44Call4EA2CView1(Physics44Field(globalFieldA4Pointer,int*,0));
        workWord3=Physics44PlayerB0View1;
        agentProduct4=workWord3*workWord2;
        call4=(void*)Physics44Field(globalFieldA4Pointer,int*,0);
        workWord2=agentProduct4>>12;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        originalFrame.spC0=workWord2;
        workWord2=Physics44Call4E9E4View1(call4);
        workWord3=Physics44PlayerB0View1;
        agentProduct5=workWord3*workWord2;
        vectorAt40=&originalFrame.spC0;
        call4=vectorAt40;
        call5=vectorAt40;
        call6=globalVector8C;
        workWord2=agentProduct5>>12;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        originalFrame.spC4=workWord2;
        Physics44Call4F1C8View1(call4,call5,call6);
        call4=vectorAt40;
        call5=0;
        __asm__ volatile(""::"r"(call4),"r"(call5):"memory");
        originalFrame.spC8=0;
        goto vector118Read;
    case 121:vectorAt40=&originalFrame.spD0;
        Physics44Call4F168View1(vectorAt40);
        call4=vectorAt40;
        call5=call4;
        Physics44Call4F1C8View2(call4,call5,&Physics44Player8CView2);
        workWord2=Physics44PlayerB8View1;
        call4=vectorAt40;
        if(!workWord2)goto detached121;
        originalFrame.spD8=0;
        workWord2=Physics44Call4EDE8View2(call4,0);
        call5=(void*)workWord2;
        workWord2=(int)call5<9;
        call4=vectorAt40;
        if(workWord2)goto vectors121;
        call6=(void*)8;
        goto limit121;
        detached121:workWord2=Physics44Call4EDE8View2(call4,1);
        call5=(void*)workWord2;
        workWord2=(int)call5<65;
        call4=vectorAt40;
        if(workWord2)goto vectors121;
        call6=(void*)64;
        limit121:__asm__ volatile(""::"r"(call4),"r"(call5),"r"(call6):"memory");
        Physics44Call4F08CView2(call4,call5,call6);
        vectors121:globalVector80=&Physics44Player80View1;
        call4=globalVector80;
        __asm__ volatile(""::"r"(call4):"memory");
        globalFieldA4Pointer=globalVector80+12;
        call5=globalFieldA4Pointer;
        call6=&originalFrame.spD0;
        __asm__ volatile(""::"r"(call5),"r"(call6):"memory");
        workWord2=-192;
        originalFrame.spD8=workWord2;
        Physics44Call4F194View2(call4,call5,call6);
        Physics44Call4F178View1(globalFieldA4Pointer,globalVector80);
        workWord2=Physics44Player94View1;
        workWord2=workWord2<-8960;
        clamp119:if(workWord2){
            workWord2=-8960;
            Physics44Player94View1=workWord2;
        }
        return;
    case 122:case 123:{
            int boundedScalar122;
            int numerator122a,numerator122b;
            register void *child18 __asm__("$18");
            register void *position19 __asm__("$19");
            register void *player20 __asm__("$20");
            register void *input16 __asm__("$16");
            register int trig17 __asm__("$17");
            register void *vector17 __asm__("$17");
            register int length16 __asm__("$16");
            register int secondTrig16 __asm__("$16");
            register int numeric5 __asm__("$5");
            call4=&originalFrame.spE0;
            workWord2=Physics44Player250View1;
            child18=Physics44Field((void*)workWord2,void**,0);
            Physics44Call40F48View1(call4,0);
            input16=&Physics44Data6E040View1;
            workWord2=Physics44Call4EA2CView2(Physics44Field(input16,short*,0));
            position19=child18+100;
            trig17=workWord2;
            workWord2=Physics44Call4E9E4View2(Physics44Field(input16,short*,0));
            workWord3=originalFrame.spE4;
            numeric5=workWord3*trig17;
            workWord3=originalFrame.spE0;
            workWord3*=workWord2;
            call4=(void*)Physics44Field(input16,short*,0);
            workWord2=numeric5+workWord3;
            workWord2>>=13;
            originalFrame.spE8=workWord2;
            workWord2=Physics44Call4EA2CView2(call4);
            call4=(void*)Physics44Field(input16,short*,0);
            __asm__ volatile(""::"r"(call4):"memory");
            secondTrig16=workWord2;
            workWord2=Physics44Call4E9E4View2(call4);
            workWord3=originalFrame.spE0;
            workWord3=-workWord3;
            numeric5=workWord3*secondTrig16;
            workWord3=originalFrame.spE4;
            workWord3*=workWord2;
            vector17=&originalFrame.spE8;
            call4=vector17;
            player20=&Physics44Player0View2;
            workWord2=numeric5+workWord3;
            workWord2>>=13;
            originalFrame.spEC=workWord2;
            workWord2=Physics44Field(child18,int*,100);
            workWord3=originalFrame.spE8;
            call6=player20;
            workWord2+=workWord3;
            Physics44Field(child18,int*,100)=workWord2;
            workWord2=Physics44Field(child18,int*,104);
            workWord3=originalFrame.spEC;
            call5=position19;
            workWord2+=workWord3;
            Physics44Field(child18,int*,104)=workWord2;
            Physics44Call4F1C8View2(call4,call5,call6);
            originalFrame.spF0=0;
            workWord2=Physics44Call4EDE8View2(vector17,0);
            length16=workWord2;
            workWord2=length16<13313;
            if(!workWord2){
                call4=vector17;
                call5=(void*)length16;
                call6=(void*)13312;
                goto clamp122;
            }
            workWord2=length16<1024;
            call4=vector17;
            if(!workWord2)goto selector122;
            call5=(void*)length16;
            call6=(void*)1024;
            clamp122:Physics44Call4F08CView2(call4,call5,call6);
            Physics44Call4F194View2(position19,player20,vector17);
            selector122:call4=(void*)originalFrame.spE8;
            call5=(void*)originalFrame.spEC;
            workWord2=Physics44Call4E880View2(call4,call5,1);
            workWord3=Physics44Data6E044View1;
            __asm__ volatile(""::"r"(workWord3),"r"(workWord2):"memory");
            Physics44PlayerA4View1=workWord2;
            workWord2=40;
            call4=(void*)24;
            if(workWord3==workWord2){
                call4=(void*)30;
                call5=(void*)1;
            }
            else call5=(void*)4;
            Physics44Call41580View1(call4,call5);
            workWord2=length16<6145;
            if(workWord2)goto below122;
            boundedScalar122=(length16-6144)/56+384;
            goto store122;
            below122:boundedScalar122=384-((6144-length16)/40);
            store122:__asm__ volatile(""::"r"(length16):"memory");
            Physics44Field(child18,int*,92)=boundedScalar122;
            __asm__ volatile("":::"memory");
            workWord2=Physics44Field(child18,int*,92);
            workWord2=workWord2<256;
            if(workWord2)Physics44Field(child18,int*,92)=256;
            workWord2=Physics44Field(child18,int*,92);
            workWord2=workWord2<513;
            if(!workWord2)Physics44Field(child18,int*,92)=512;
            call4=(void*)Physics44Player250View1;
            Physics44Slot432C(call4);
            return;
        }
    case 124:case 129:clear30:globalVector80 = &Physics44Player0View3 + 0x80;
        Physics44Call4F168View2(globalVector80);
        Physics44Call4F168View2(globalVector80 + 0xC);
        return;
    case 130:{
            register int callback17 __asm__("$17");
            globalVector80=&Physics44Player50View1;
            workWord3=Physics44Field(globalVector80,int*,0);
            workWord2=1;
            if(workWord3!=workWord2)goto airborne130;
            workWord2=8;
            __asm__ volatile(""::"r"(workWord2):"memory");
            globalVector80=&Physics44Data6E044View1;
            __asm__("":"=r"(globalVector80):"0"(globalVector80));
            workWord3=Physics44Field(globalVector80,int*,0);
            if(workWord3!=workWord2)Physics44Call40D10View1(3840);
            workWord2=Physics44Data6E538View1&12;
            if(workWord2)Physics44PlayerACView1=0;
            workWord2=Physics44Call416F4View1();
            callback17=workWord2;
            workWord3=Physics44Field(globalVector80,int*,0);
            workWord2=40;
            call4=(void*)90;
            if(workWord3==workWord2){
                call4=(void*)30;
                call5=(void*)1;
            }
            else call5=(void*)16;
            workWord2=Physics44Call41580View1(call4,call5);
            workWord3=workWord2;
            workWord2=Physics44PlayerA8View1;
            if(workWord2<0)workWord2=-workWord2;
            workWord2=workWord2<8;
            if(!workWord2)goto reset130;
            workWord2=Physics44Data6E538View1&12;
            if(!workWord2)goto reset130;
            workWord2=Physics44Player144View1;
            workWord2++;
            Physics44Player144View1=workWord2;
            goto saved130;
            reset130:Physics44Player144View1=0;
            saved130:call4=&Physics44PlayerACView1;
            globalVector80=(void*)Physics44Field(call4,int*,0);
            if(callback17)goto collision130;
            workWord2=workWord3;
            if(workWord3<0)workWord2=-workWord2;
            workWord2=workWord2<513;
            if(workWord2)goto pass130;
            collision130:workWord2=Physics44Player20CView1&64;
            if(workWord2)Physics44Field(call4,int*,0)=0;
            else{
                workWord3=Physics44PlayerB0View1;
                workWord2=workWord3<(int)globalVector80;
                if(workWord2)Physics44Field(call4,int*,0)=workWord3;
            }
            pass130:Physics44Call417FCView1(320,192);
            workWord2=Physics44Player101View1;
            call4=&Physics44PlayerACView1;
            Physics44Field(call4,int*,0)=(int)globalVector80;
            if(workWord2){
                Physics44Call4F168View1(call4-32);
                goto fields130;
            }
            Physics44Call41848View1(call4);
            Physics44Call41B64View2();
            fields130:call6=&Physics44PlayerFCView1;
            workWord2=Physics44Field(call6,unsigned char*,0);
            if(workWord2)goto scalar130;
            workWord2=Physics44PlayerB8View1;
            call4=call6-112;
            if(!workWord2)goto vector130Input;
            scalar130:workWord2=Physics44PlayerA0View1;
            workWord2-=192;
            Physics44Player94View1=workWord2;
            return;
            vector130Input:__asm__ volatile(""::"i"(0x800900EC):"memory");
            call5=call4;
            Physics44Call4F194View2(call4,call5,call6-20);
            return;
            airborne130:Physics44Call40D10View1(3200);
            workWord3=Physics44Data6E044View1;
            workWord2=40;
            call4=(void*)40;
            if(workWord3==workWord2){
                call4=(void*)30;
                call5=(void*)1;
            }
            else call5=(void*)8;
            Physics44Call41580View1(call4,call5);
            Physics44Call417FCView1(320,192);
            globalFieldA4Pointer=&Physics44PlayerA4View1;
            globalVector8C=globalFieldA4Pointer-24;
            workWord2=Physics44Call4EA2CView1(Physics44Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics44PlayerB0View1;
            agentProduct6=workWord3*workWord2;
            call4=(void*)Physics44Field(globalFieldA4Pointer,int*,0);
            workWord2=agentProduct6>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.spF8=workWord2;
            workWord2=Physics44Call4E9E4View1(call4);
            workWord3=Physics44PlayerB0View1;
            agentProduct7=workWord3*workWord2;
            vectorAt40=&originalFrame.spF8;
            call4=vectorAt40;
            call5=vectorAt40;
            call6=globalVector8C;
            workWord2=agentProduct7>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.spFC=workWord2;
            Physics44Call4F1C8View1(call4,call5,call6);
            originalFrame.sp100=0;
            temp_v0_4=Physics44Call4EDE8View1(vectorAt40,0);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3=globalFieldA4Pointer-36;
            if(temp_v0_4>=641){
                Physics44Call4F08CView1(vectorAt40,temp_v0_4,640);
                __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3=globalFieldA4Pointer-36;
            }
            Physics44Call4F194View1(var_a0_3,globalVector8C,vectorAt40);
            Physics44Call41B64View1();
            workWord2=combinedIndex<13;
            if(!workWord2)goto subtract192_130;
            workWord2=Physics44Player4CView1;
            if(workWord2)goto subtract192_130;
            workWord2=(int)Physics44Data6C570View1;
            workWord2=Physics44Field((void*)workWord2,int*,0)&64;
            if(workWord2)goto add23_130;
            workWord2=Physics44Player144View1;
            if(!workWord2)goto subtract192_130;
            add23_130:workWord2=Physics44Player94View1;
            workWord2+=23;
            Physics44Player94View1=workWord2;
            return;
            subtract192_130:globalPointer=&Physics44Player94View1;
            workWord2=Physics44Field(globalPointer,int*,0);
            workWord2-=192;
            Physics44Field(globalPointer,int*,0)=workWord2;
            return;
        }
    }
    return;
    callback131:__asm__ volatile(""::"i"(0x8009027C):"memory");
    Physics44Slot4454();
    return;
}
#undef Physics44Field


/* AI generated; not human reviewed. SCUS-94467 800902B4..80090908.
 * Verified43 scalar/clamp and verified50 descriptor-table routes form baseline.
 * Original44 supplies every selector and numeric access; byte offsets and helper
 * names establish no units, meanings or caller cadence. All code/table words,
 * strict complete translation unit and every retail hash required for acceptance.
 */
extern int Callback44Step __asm__("D_80070328+0x144");
extern int Callback44Z __asm__("D_80070328+8");
extern int Callback44Limit __asm__("D_80070328+0x280");
extern Spyro Callback44Player __asm__("D_80070328");
int Callback44Call80037058(int x, int y) __asm__("func_80037058");
int Callback44Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback44Call80041930(void) __asm__("func_80041930");
void Callback44Call80041AE8(void) __asm__("func_80041AE8");
void Callback44Call80041C20(void) __asm__("func_80041C20");
void Callback44Call80042A44(void) __asm__("func_80042A44");
void Callback44Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback44Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38,D_8006C648;
int Callback44Query(Vector3D*,int) __asm__("func_8001A358");
int Callback44Length(Vector3D*, int) __asm__("func_8004EDE8");
extern int Callback44Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback44Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback44Values[] __asm__("D_8006FCF0");
void Callback44Call80049590(void) __asm__("func_80049590");
void func_level_44_800902B4(void) {
    struct {Vector3D first; int reserved1C;} local;
    register int computedValue __asm__("$4");
    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    int descriptorResult;
    int flagOffset;

    register int clampedValue __asm__("$4");
    register int positionDelta __asm__("$2");
    register int numerator __asm__("$2");
    register int belowLimit __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback44Player.animationState) {
    case 0x73:
    case 0x78:
    case 0x7A:
    case 0x7B:
    case 0x7C:
    case 0x7E:
        if (func_800438F4() == 0) {
            func_80043728();
        }
        Callback44Call80041C20();
        Callback44Player.unk9a = 0;
        Callback44Call80042A44();
        goto clearSharedValue;
    default:
        return;
    case 0x80:
        Callback44Call80041C20();
        Callback44Call80042A44();
        goto clearSharedValue;
    case 0x79:
        Callback44Call80041C20();
        Callback44Call80042A44();
        goto queryC00;
        case 0x81: {
            register int* zWord __asm__("$5")=&Callback44Z;
            register int velocity __asm__("$6")=Callback44Step;
            register int scalarPosition __asm__("$2")=*zWord;
            register int tick __asm__("$3")=D_8006C648;
            register int increment __asm__("$4");
            register int status __asm__("$2");
            __asm__("" : "=r"(velocity) : "0"(velocity));
            __asm__("" : "=r"(scalarPosition) : "0"(scalarPosition));
            __asm__("" : "=r"(tick) : "0"(tick));
            increment=velocity>>6;
            __asm__("" : "=r"(increment) : "0"(increment));
            scalarPosition+=increment;
            __asm__("" : "=r"(tick) : "0"(tick), "r"(scalarPosition));
            tick<<=9;
            *zWord=scalarPosition;
            status=Callback44Limit;
            velocity+=tick;
            Callback44Step=velocity;
            __asm__("" : : : "memory");
            if(status>=0 && D_8006FA38<0)goto lowerLimit;
            {
                register int limit __asm__("$3")=0x9000;
                register int exceeded __asm__("$2");
                __asm__("" : "=r"(limit) : "0"(limit));
                exceeded=limit<velocity;
                if(exceeded)Callback44Step=limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2")=velocity<0x2581;
                if(!below)Callback44Step=0x2580;
            }
        limitsDone:
            Callback44Call80041C20();
            Callback44Call80042A44();
            func_8004F178(&local.first,&Callback44Player.position);
            local.first.z+=0x400;
            Callback44Player.unk4[0]=Callback44Query(&local.first,0xC00);
            positionDelta=(int)Callback44Player.union144.a.unk13cb;
            positionValue=Callback44Player.position.z;
            positionDelta >>= 6;
            goto storePosition;
        }
    case 0x28:
    case 0x29:
    case 0x39:
        Callback44Call80041C20();
        Callback44Call80042A44();
        descriptor=&Callback44Player.unk22[2];
        if (Callback44Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback44Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=decreasingValue-0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
        }
        goto clearSharedValue;
    case 0x2A:
        Callback44Call80041C20();
        Callback44Call80042A44();
        Callback44Call80049590();
        descriptor=&Callback44Player.unk22[2];
        if (Callback44Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback44Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback44Player.unk22[2];
        }
        if (Callback44Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback44Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback44Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback44Flags[flagOffset] = Callback44Flags[flagOffset] | 0x10;
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
        Callback44Call80041C20();
        Callback44Call80042A44();
        Callback44Call80041AE8();
        if ((unsigned char) Callback44Player.unk10[4] != 0) {
            computedValue = -Callback44Player.unk9ha[4] - Callback44Call80037058(Callback44Player.position.x, Callback44Player.position.y);
            positionValue = Callback44Player.unk4a - computedValue;
            Callback44Player.unk4[0] = computedValue;
            positionDelta = (int) Callback44Player.union144.a.unk13cc >> 6;
            goto storePosition;
        }
        break;
storePosition:
        positionValue -= positionDelta;
        __asm__("" : "=r"(positionValue) : "0"(positionValue));
        Callback44Player.position.z=positionValue;
        return;
    case 0x2F:
        Callback44Call80041C20();
        Callback44Call80042A44();
        Callback44Call80041930();
        func_80042F64();
        goto clearSharedValue;
    case 0x32:
        Callback44Call80041C20();
        Callback44Call80042A44();
        Callback44Call80041930();
        func_80042F64();
        numerator=(int)((unsigned int)Callback44Player.unk7a[3].z << 2);
        Callback44Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)((unsigned int)ABS(numerator) + 0x300U) / 1536;
        __asm__("" : "=r"(quotient) : "0"(quotient));
        clampedValue=quotient<<4;}
        belowLimit = clampedValue < 0x10;
        __asm__("" : "=r"(belowLimit) : "0"(belowLimit));
        if (belowLimit) {
            clampedValue = 0x10;
            goto compareUpperLimit;
        }
        goto compareUpperLimit;
    case 0x33:
    case 0x34:
        Callback44Call80041C20();
        Callback44Call80042A44();
        Callback44Call80041930();
        func_80042F64();
        Callback44Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)(((unsigned int)Callback44Length((Vector3D *) ((unsigned char*)Callback44Player.unk4 + 0x70), 0) << 2) + 0x300U) / 1536;
        __asm__("" : "=r"(quotient) : "0"(quotient));
        clampedValue=quotient<<4;}
        belowLimit = clampedValue < 8;
        __asm__("" : "=r"(belowLimit) : "0"(belowLimit));
        if (belowLimit) {
            clampedValue = 8;
            goto compareUpperLimit;
        }
        goto compareUpperLimit;
compareUpperLimit:
        belowLimit=clampedValue<0x41;
applyUpperLimit:
        if(!belowLimit)clampedValue=0x40;
        func_800443A4(clampedValue);
        return;
    case 0x76:
    case 0x77:
        Callback44Call80041C20();
        Callback44Call80042A44();
        Callback44Call80041930();
        if (Callback44Player.unk5 != 0x7F) {
            if ((Callback44Player.unk7a[3].z < 0) && (Callback44Player.animationStateFrames >= 4)) {
                Callback44Player.unk5 = 1;
            } else {
                goto checkSecondFlag;
            }
        }
        goto clearSharedValue;
    case 0x82:
        if (Callback44Player.movementState != MOVEMENT_STATE_WALK) goto other82;
    case 0x74:
        case 0x75:
        case 0x83:
        case 0x84:
            func_800438F4();
            Callback44Call80041C20();
            Callback44Call80042A44();
            Callback44Call80041930();
queryC00:
            Callback44Call80043A38(0xC00);
            goto clearSharedValue;
other82:
        Callback44Call80041C20();
        Callback44Call80042A44();
        Callback44Call80041930();
        if ((Callback44Player.unk7a[3].z < 0) && (Callback44Player.animationStateFrames >= 4)) {
            Callback44Player.unk5 = 1;
        } else {
checkSecondFlag:
                if ((Callback44Player.unk5 == 0) && !(Callback44Word8006E538 & 0x40) && (Callback44Player.union144.a.unk13cb == 0)) {
                    Callback44Player.unk5 = 2;
                }
        }
clearSharedValue:
        Callback44Player.unk4[0]=0;
        return;
    }
}


#define LEVEL_ID 44
#define PlaySpyroSounds_level_44 func_level_44_8009090C
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_44_80090B48(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x28:
        break;

    case 0x76:
    case 0x77:
        func_80043ABC(0);
        break;
    case 0x2f:
    case 0x32:
    case 0x33:
    case 0x34:
        func_80043F3C(&spyro.unk9h);
        break;
    case 0x82:
        {
            register int* state __asm__("$4") = (int*)((char*)&spyro + 0xB8);
            __asm__("" : "=r"(state) : "0"(state));
            if (*state) func_80043ABC(0);
            else func_80043ABC(&spyro.unk9e);
        }
        break;
    case 0x2b:
    case 0x2c:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x78:
    case 0x79:
    case 0x7a:
    case 0x7b:
    case 0x7c:
    case 0x7e:
    case 0x80:
    case 0x81:
    case 0x83:
    case 0x84:
        func_80043ABC(&spyro.unk9e);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80090BF0.
 * Reuses verified30 independent underwater/surface stack vectors and special
 * routes. Original44 removes1C, retains separate2F and32/33/34 ladder branches,
 * and adds39: signed index298; negative index replaced by((word64+800)>>4)&FF;
 * signed halfword tables65920/658A0 write8C/90, word94=0, byte vectors80/8C.
 * Callback selector is original table byte19; its audible meaning is unproven.
 * Numeric offsets are bytes. Scalar60 wrap/clamp uses FFF/801/1000; inputs
 * 800/801/FFF yield0/-7FF/-1 before helper calls. Two distinct ladder blocks
 * and numeric load/store order are retained with empty constraints, no opcodes.
 * Exact code/local jumps/owned table words, strict full TU and complete EXE/all
 * overlay hashes are required. Units, helper meaning, caller cadence and live
 * runtime parity remain open. Once per invocation is the demonstrated cadence.
 */
extern Spyro Transition44_D_80070328 __asm__("D_80070328");
int Transition44_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition44_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition44_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition44RawUnion[] __asm__("D_80070328+0x144");
extern int Transition44RawMovement __asm__("D_80070328+0x50");
extern int Raw44Movement __asm__("D_80070328+0x50");
extern int Raw44Union __asm__("D_80070328+0x144");
void Call44ED6C(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
extern void (*Call44Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw44State[] __asm__("D_80070328+0x50");
extern Spyro Special44_D_80070328 __asm__("D_80070328");
extern short Signed44TableA[] __asm__("D_800658A0");
extern short Signed44TableB[] __asm__("D_80065920");
int Special44_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Special44_func_80043A38(int scale) __asm__("func_80043A38");
void Special44_func_800441F0(void) __asm__("func_800441F0");
void Special44_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Special44_D_8006E524 __asm__("D_8006E524");

extern int D_80071934;
int Call44A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw44NegativeWord __asm__("D_80070328+0x28");
extern int Raw44TableIndex __asm__("D_80070328+0x298");
extern int Raw44Yaw __asm__("D_80070328+0x64");
void func_level_44_80090BF0(int arg0){
    struct {Vector3D first; int gap1; Vector3D second; int gap2; Vector3D third;} vectors;
    register int negativeWord __asm__("$3");
    int firstResult,secondResult,firstWrappedWord,secondWrappedWord,firstParticleKind,secondParticleKind,firstParticleSubtype,secondParticleSubtype;
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");

    int lengthResult;

    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    register unsigned char *sourceBytesA __asm__("$16");

    register unsigned char* walkBase __asm__("$5");
    register int walkFlag __asm__("$16");
    register int groundValue __asm__("$2");
    switch(arg0){
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition44_D_80070328.movementState - 0xB) >= 2U) && (Transition44_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition44_D_80070328.movementState - 0x50));
                if ((Transition44_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw44NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition44_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call44A358(&vectors.first, 0x800);
                    vectors.first.z = firstResult;
                    if (firstResult != 0) {
                        firstParticleKind = 6;
                        if (D_80071934 != 0) {
                            firstParticleSubtype = 0x2E;
emitFirstParticle:
                            SpawnParticle(firstParticleKind, firstParticleSubtype, &vectors.first, 0);
                        }
                    }
                }
            }
            firstWrappedWord = Transition44_D_80070328.rotation.pitch & 0xFFF;
            Transition44_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition44_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition44_D_80070328.rotation.pitch > 0) {
                Transition44_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition44_D_80070328.unk5 = 1;
            }
            Transition44_func_8004F168((Vector3D *) ((unsigned char*)&Transition44_D_80070328.rotation.pitch + 0xEC));
            Transition44_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition44_D_80070328.unk8[0] = Transition44_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition44_D_80070328.rotation.pitch + 0x38), 0);
            Transition44_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition44_D_80070328.animationState == 0x2A) {
            Transition44_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition44_D_80070328.union144.a.unk13da = 0;
        }
        Transition44_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition44_D_80070328.unk20a = 0;
        Transition44_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw44State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw44NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition44_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call44A358(localVector, 0x800);
                    vectors.second.z = secondResult;
                    if (secondResult != 0) {
                        secondParticleKind = 6;
                        if (D_80071934 != 0) {
                            secondParticleSubtype = 0x2E;
emitSecondParticle:
                            SpawnParticle(secondParticleKind, secondParticleSubtype, localVector, 0);
                        }
                    }
                }
            }
            if (Transition44_D_80070328.animationState == 0x2E) {
                Transition44_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition44_D_80070328.rotation.pitch & 0xFFF;
            Transition44_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition44_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition44_D_80070328.rotation.pitch > 0) {
                Transition44_D_80070328.rotation.pitch = 0;
            }
            Transition44_D_80070328.unk5 = 1;
            Transition44_func_8004F168((Vector3D *) ((unsigned char*)&Transition44_D_80070328.animationState + 0x104));
            Transition44_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition44_D_80070328.unk8[0] = Transition44_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition44_D_80070328.animationState + 0x50), 0);
            Transition44_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition44_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition44_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition44RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition44RawUnion;
            *(int*)unionPointer=(-Transition44_D_80070328.unk7a[2].z)>>2;
            if(Transition44RawMovement!=8){Transition44_D_80070328.union144.a.unk13cc=0x5900;Transition44RawMovement=10;}
            Transition44_D_80070328.unk5=0;
            Transition44_D_80070328.unk8[0]=Transition44_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition44_D_80070328.grounded=1;
            Transition44_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call44A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x2F:
        savedBase=(unsigned char*)&Transition44RawMovement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition44_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            Transition44_D_80070328.grounded=1;
            __asm__ volatile("" : : : "memory");
        }
        goto clearPointers;
    case 0x32:case 0x33:case 0x34:
        savedBase=(unsigned char*)&Transition44RawMovement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition44_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            Transition44_D_80070328.grounded=1;
        }
        goto clearPointers;
    case 0x39: {
        register int previousMovement __asm__("$2")=Transition44RawMovement;
        register int numericKind __asm__("$3");
        register int indexWord __asm__("$3");
        register unsigned char* unionPointer __asm__("$5");
        register int tableOffset __asm__("$2");
        register int tableWord __asm__("$3");
        __asm__("" : "=r"(previousMovement) : "0"(previousMovement));
        numericKind=7;
        __asm__("" : "=r"(numericKind) : "0"(numericKind));
        Transition44RawMovement=numericKind;
        __asm__ volatile("" : : : "memory");
        indexWord=Raw44TableIndex;
        __asm__ volatile("" : "=r"(indexWord) : "0"(indexWord) : "memory");
        unionPointer=Transition44RawUnion;
        __asm__("" : "=r"(indexWord),"=r"(unionPointer) : "0"(indexWord),"1"(unionPointer) : "memory");
        Transition44_D_80070328.unk5=0;
        *(int*)unionPointer=previousMovement;
        if(indexWord<0)Raw44TableIndex=((Raw44Yaw+0x800)>>4)&0xFF;
        tableOffset=Raw44TableIndex*2;
        tableWord=*(short*)((unsigned char*)Signed44TableB+tableOffset);
        destination=(Vector3D*)(unionPointer-0xC4);
        *(int*)(unionPointer-0xB8)=tableWord;
        tableOffset=*(short*)((unsigned char*)Signed44TableA+tableOffset);
        Transition44_D_80070328.unk7a[2].z=0;
        Transition44_D_80070328.unk7a[2].y=tableOffset;
        func_8004F178(destination,(Vector3D*)(unionPointer-0xB8));
        Transition44_D_80070328.grounded=1;
        Transition44_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        PlaySound((int)D_8006C654->underwaterHit,0,0);
    }
clearPointers:
        Transition44_D_80070328.unk20a=0;
        Transition44_D_80070328.critterMobyPtr=0;
        return;
    case 0x73:
    case 0x78:
    case 0x7E:
        Special44_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Special44_D_80070328.unk5 = 0;
        Special44_func_800441F0();
        Special44_D_80070328.grounded = 1;
        return;
    case 0x74:
    case 0x75:
    case 0x83:
    case 0x84:
        walkBase=Raw44State;
        walkFlag=1;
        __asm__("" : "=r"(walkFlag) : "0"(walkFlag));
        *(int*)walkBase=walkFlag;
        if(arg0==0x57 && Special44_D_80070328.ticksSinceLastSurfaceTouch!=0) {
            __asm__ volatile("" : : : "memory");
            destination=(Vector3D*)(walkBase+0x3C);
            goto copyWalkVector;
        }
        goto clearWalkFlag;
    case 0x80:
        Special44_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Special44_D_80070328.unk5 = 0;
        Special44_func_80043A38(0xC00);
        Special44_D_80070328.grounded = 1;
        Special44_D_8006E524 = 0xF;
        return;
    case 0x81: {
        register int oldState __asm__("$3")=Raw44Movement;
        register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$8")=SpawnParticle;
        register int* stateWord __asm__("$2");
        register int value __asm__("$2");
        __asm__ volatile("" : "=r"(oldState), "=r"(callback) : "0"(oldState), "1"(callback) : "memory");
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Raw44Movement=value;
        value=1;
        __asm__("" : "=r"(value) : "0"(value));
        Special44_D_80070328.grounded=value;
        value=15;
        __asm__("" : "=r"(value) : "0"(value));
        Special44_D_8006E524=value;
        Special44_D_80070328.unk5=0;
        stateWord=&Raw44Union;
        __asm__("" : "=r"(stateWord) : "0"(stateWord));
        Special44_D_80070328.unk5=0;
        *stateWord=oldState;
        __asm__ volatile("" : : : "memory");
        *stateWord=0;
        if(callback)callback(5,10,0,0);
        Special44_D_80070328.unk22[2]=PlaySound((int)D_8006C654->drown,0,0);
        Special44_D_80070328.unk22[3]=(int)D_8006C654->drown;
        return;
    }
    case 0x79:
        Special44_D_80070328.movementState = MOVEMENT_STATE_HURT;
        Special44_D_80070328.unk5 = 0;
        if (Special44_D_80070328.unk22[5] >= 0) {
            tableOffsetOrValue = Special44_D_80070328.unk22[5] * 2;
            tableValueA = *(short*)((unsigned char*)Signed44TableB + tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            tableValueA >>= 1;
            Special44_D_80070328.unk7a[2].x = tableValueA;
            tableOffsetOrValue = *(short*)((unsigned char*)Signed44TableA + tableOffsetOrValue);
            Special44_D_80070328.unk7a[2].z = 0;
            __asm__ __volatile__("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Special44_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
        } else {
            Special44_func_8004F168((Vector3D *) ((unsigned char*)&Special44_D_80070328.movementState + 0x3C));
        }
        Special44_D_80070328.unk7a[2].z = 0x200;
        func_8004F178((Vector3D *) ((unsigned char*)&Special44_D_80070328.unk7a[2].z - 0x14), (Vector3D *) ((unsigned char*)&Special44_D_80070328.unk7a[2].z - 8));
        Special44_D_80070328.grounded = 1;
        Special44_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
    default:
        return;
    case 0x7A: {
        register unsigned char* privateData __asm__("$17")=Special44_D_80070328.critterMobyPtr->mobyTag;
        register unsigned char* state __asm__("$18")=Raw44State;
        register Vector3D* vector __asm__("$16");
        *(int*)state=0;
        Special44_D_80070328.unk5=0;
        vector=(Vector3D*)(privateData+0x64);
        Special44_func_800441F0();
        Special44_D_80070328.grounded=1;
        Special44_D_80070328.idle=0;
        Special44_D_80070328.unk15g=0;
        *(int*)(privateData+0x5C)=0x180;
        *(int*)(privateData+0x64)=0x1800;
        *(int*)(privateData+0x68)=0;
        *(int*)(privateData+0x6C)=0;
        Call44ED6C((Vector3D*)(state-0x20),vector,vector);
        func_8004F194(vector,vector,(Vector3D*)(state-0x50));
        Call44Header(Special44_D_80070328.critterMobyPtr);
        return;
    }
    case 0x7B:
        Special44_D_80070328.movementState=0;
        Special44_func_800441F0();
        groundValue=1;
        goto sharedGround;
    case 0x7C: {
        register unsigned char* privateData __asm__("$16")=Special44_D_80070328.critterMobyPtr->mobyTag;
        register unsigned char* child __asm__("$4");
        Special44_D_80070328.movementState=0;
        Special44_func_800441F0();
        Special44_D_80070328.grounded=1;
        Special44_D_80070328.idle=0;
        Special44_D_80070328.unk15g=0;
        child=*(unsigned char**)(privateData+0x78);
        if(child) {
            if(*(short*)(privateData+0x74)==0x22A)child[0x48]=0x50;
            else child[0x48]=1;
        }
        return;
    }
    case 0x76:
        stateBaseA = Raw44State;
        __asm__("" : "=r"(stateBaseA) : "0"(stateBaseA));
        destination = (Vector3D*)(stateBaseA + 0x3C);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceBytesA = stateBaseA + 0x48;
        *(int*)stateBaseA = 2;
        func_8004F178(destination, (Vector3D*)sourceBytesA);
        Special44_D_80070328.unk8[0] = Special44_func_8004EDE8((Vector3D *) sourceBytesA, 0);
        Special44_D_80070328.unk7a[2].z = 0xDC0;
        Special44_D_80070328.unk5 = 0;
        if(Special44_D_80070328.animationState==0x81)Special44_D_80070328.union144.a.unk13cb=1;
        else Special44_D_80070328.union144.a.unk13cb=0;
        Special44_D_80070328.grounded = 0;
        PlaySound((int) D_8006C654->jump, 0, 0);
        return;
    case 0x77: {
        register unsigned char* state __asm__("$6")=Raw44State;
        if(*(int*)state!=2) {
            *(int*)state=3;
            Special44_D_80070328.unk8[0]=Special44_func_8004EDE8((Vector3D*)(state+0x48),0);
            Special44_D_80070328.grounded=0;
            Special44_D_80070328.unk15b=1;
            goto clearTail;
        }
        return;
    }
    case 0x82: {
        walkBase=Raw44State;
        if(*(int*)walkBase!=2) {
            walkFlag=1;
            __asm__("" : "=r"(walkFlag) : "0"(walkFlag));
            *(int*)walkBase=walkFlag;
            if(arg0==0x57 && Special44_D_80070328.ticksSinceLastSurfaceTouch!=0) {
                destination=(Vector3D*)(walkBase+0x3C);
copyWalkVector:
                func_8004F178(destination,(Vector3D*)(walkBase+0x48));
                Special44_D_80070328.unk5=walkFlag;
            } else {
clearWalkFlag:
                Special44_D_80070328.unk5=0;
            }
            Special44_D_80070328.unk8[0]=Special44_func_8004EDE8((Vector3D*)((unsigned char*)&Special44_D_80070328.movementState+0x48),0);
            Special44_func_80043A38(0xC00);
            groundValue=1;
            __asm__("" : "=r"(groundValue) : "0"(groundValue));
            Special44_D_80070328.union144.a.unk13cb=0;
sharedGround:
            Special44_D_80070328.grounded=groundValue;
clearTail:
            Special44_D_80070328.idle=0;
            Special44_D_80070328.unk15g=0;
        }
        return;
    }
    }
}


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80091774.
 * Assembly SHA256 438f4dae940b463394074d53bc2acf6f3dfe2050b262a44d6c80cd69abd9d4ba.
 * AI-generated; not human reviewed. Verified donor state C is adapted to
 * all1449 original instructions and93 state-table entries (bias40).
 * Verified donor33 original115..132 state chains retain callback1, collision/input
 * priority, private78/7C/4C fields, masks and mode31/40 gates, signed products,
 * original partial effect/sound calls, counters, water/helper paths and the
 * shared selector119 call that restores the original saved word54 afterward.
 * The original0x18 frame retains savedS0. Generic
 * state C is reused from verified donors with every original selector/join.
 * Rev1's identified Agent9 callback/table and snapshot-writer decoders are
 * cross-references only; no browser-derived behavior or values are used.
 * Typed view aliases remain distinct; exact symbols are in provenance.
 * Empty initialized constraints and original-address metadata emit no CPU
 * instructions. Every CPU word is emitted by the frozen C toolchain.
 * Raw physical units/fixed point, helper contracts and invocation rate
 * remain unresolved. Cadence is per invocation; rate unknown.
 * Falsification: every original native/linked instruction, branch/internal
 * target, selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
extern int Anim44Player48View1 __asm__("D_80070328 + 0x48");
extern int Anim44Player4CView1 __asm__("D_80070328 + 0x4C");
extern int Anim44PlayerA0View1 __asm__("D_80070328 + 0xA0");
extern int Anim44PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim44Data6E538View1 __asm__("D_8006E538"),Anim44Data6E53CView1 __asm__("D_8006E53C");
int Anim44Call40994View1() __asm__("func_80040994");
int Anim44Call4BEF8View1() __asm__("func_8004BEF8");
extern int Anim44PlayerB4View1 __asm__("D_80070328 + 0xB4");
extern int Anim44PlayerA4View1 __asm__("D_80070328 + 0xA4");
extern int Anim44Player4CView2 __asm__("D_80070328 + 0x4C");
extern int Anim44Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim44PlayerB0View1 __asm__("D_80070328 + 0xB0");
extern int Anim44Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim44Player280View1 __asm__("D_80070328 + 0x280");
extern int Anim44Data6E538View2 __asm__("D_8006E538"),Anim44Data6E53CView2 __asm__("D_8006E53C");
extern int Anim44Data6E044View1 __asm__("D_8006E044"),A21Gate __asm__("D_8006E344"),A21Count __asm__("D_8006C514");
extern int (*Anim44Data74374View1)() __asm__("unk_ovlheader_80074374");
int Anim44Call40994View2() __asm__("func_80040994");
int Anim44Call4BEF8View2() __asm__("func_8004BEF8");
extern volatile int Anim44Player20CView1 __asm__("D_80070328 + 0x20C");
extern int Anim44Player214View1 __asm__("D_80070328 + 0x214");
extern unsigned char Anim44Player100View1 __asm__("D_80070328 + 0x100");
extern unsigned char Anim44Data6E535View1 __asm__("D_8006E535");
extern unsigned char* Anim44Data6EE2CView1 __asm__("D_8006EE2C");
int Anim44Call40BCCView1() __asm__("func_80040BCC");
int Anim44Call1A310View1() __asm__("func_8001A310");
extern int Anim44Player48View2 __asm__("D_80070328 + 0x48");
extern int Anim44Player50View1 __asm__("D_80070328 + 0x50");
extern int Anim44Player54View2 __asm__("D_80070328 + 0x54");
extern int Anim44Player58View1 __asm__("D_80070328 + 0x58");
extern int Anim44Player8CView1 __asm__("D_80070328 + 0x8C");
extern int Anim44Player90View1 __asm__("D_80070328 + 0x90");
extern int Anim44Player94View1 __asm__("D_80070328 + 0x94");
extern int Anim44PlayerA8View1 __asm__("D_80070328 + 0xA8");
extern int Anim44PlayerACView2 __asm__("D_80070328 + 0xAC");
extern int Anim44PlayerB0View2 __asm__("D_80070328 + 0xB0");
extern int Anim44PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim44PlayerCCView1 __asm__("D_80070328 + 0xCC");
extern int Anim44PlayerD0View1 __asm__("D_80070328 + 0xD0");
extern int Anim44PlayerD4View1 __asm__("D_80070328 + 0xD4");
extern int Anim44PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern int Anim44Player144View2 __asm__("D_80070328 + 0x144");
extern int Anim44Player280View2 __asm__("D_80070328 + 0x280");
extern unsigned char *Anim44Player250View1 __asm__("D_80070328 + 0x250");
extern unsigned char Anim44Player1B6View1 __asm__("D_80070328 + 0x1B6");
extern unsigned char Anim44Data6E535View2 __asm__("D_8006E535");
extern int Anim44Data6E538View3 __asm__("D_8006E538");
extern int Anim44Data6E53CView3 __asm__("D_8006E53C");
extern int Anim44Data6E530View1 __asm__("D_8006E530");
extern int Anim44Data6E52CView1 __asm__("D_8006E52C");
extern unsigned char *Anim44Data6C654View1 __asm__("D_8006C654");
extern int (*Anim44Data7431CView1)(int) __asm__("unk_ovlheader_8007431C");
extern int (*Anim44DataSpawnParticleView1)(int,int,void*,int) __asm__("SpawnParticle");
int Anim44Call55E84View1(void*) __asm__("func_80055E84");
int Anim44Call4BEF8View3(int) __asm__("func_8004BEF8");
int Anim44CallPlaySoundView1(unsigned char,int,int) __asm__("PlaySound");
extern int Anim44PlayerB4View2 __asm__("D_80070328 + 0xB4");
extern int Anim44Player28CView1 __asm__("D_80070328 + 0x28C");
extern int Anim44Player290View1 __asm__("D_80070328 + 0x290");
extern int Anim44Data6E044View2 __asm__("D_8006E044");
int Anim44Call498C0View1(void*) __asm__("func_800498C0");
int Anim44Call3BF6CView1(int,int) __asm__("func_8003BF6C");
int Anim44Call3BE70View1(int) __asm__("func_8003BE70");
#define Anim44Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
void func_level_44_80091774(void){
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int nextSelector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* record16 __asm__("$16");
    register int (*callback3)(int) __asm__("$3");
    register int savedWord16 __asm__("$16");
    rawValue2=Anim44Player48View1;
    switch(rawValue2){
    case 40:
        if(Anim44Call40994View2())return;
        if((Anim44Data6E538View2&128) && Anim44Player4CView2!=1){
            nextSelector4=42;
            goto select;
        }
        if(Anim44PlayerB0View1)return;
        rawValue2=Anim44Player20CView1&64;
        nextSelector4=41;
        if(!rawValue2)goto select;
        if(Anim44Player214View1<=0)return;
        goto select;
    case 41:
        if(Anim44Call40994View2())return;
        nextSelector4=Anim44Data6E538View2;
        rawValue2=nextSelector4&128;
        if(rawValue2){
            nextSelector4=42;
            goto select;
        }
        rawValue2=7;
        rawValue3=Anim44Data6E044View1;
        if(rawValue3==rawValue2)return;
        rawValue2=nextSelector4&64;
        nextSelector4=40;
        if(rawValue2)goto select;
        if(!(Anim44Player20CView1&64))return;
        if(!Anim44Player214View1)goto select;
        return;
    case 42:
        if(Anim44Call40BCCView1())return;
        if((Anim44Data6E538View2&128) || Anim44Player4CView2==1)goto flag64;
        rawValue2=Anim44Player20CView1&128;
        nextSelector4=40;
        if(!rawValue2)goto select;
        flag64:rawValue2=Anim44Player20CView1&64;
        nextSelector4=40;
        if(!rawValue2)return;
        goto select;
    case 43:
        {
            register unsigned char* byte4 __asm__("$4");
            if(Anim44Call40994View2())return;
            if((Anim44Data6E53CView2&64) && Anim44Player54View1>=9){
                nextSelector4=6;
                goto partialCall;
            }
            byte4=&Anim44Player100View1;
            __asm__("" : "=r"(byte4):"0"(byte4));
            if(!*byte4){
                nextSelector4=7;
                goto partialCall;
            }
            if(!(Anim44Data6E53CView2&128))goto check44;
            if(Anim44Player54View1<9)goto check44;
            rawValue2=*(int*)(Anim44Data6EE2CView1+220);
            byte4-=256;
            if(!rawValue2)goto check44;
            rawValue2=Anim44Call1A310View1(byte4,1024,1,0);
            nextSelector4=40;
            if(rawValue2)goto check44;
            goto select;
            partialCall:Anim44Call4BEF8View2(nextSelector4);
            check44:rawValue2=Anim44Data6E535View1;
            nextSelector4=44;
            if(!rawValue2)return;
            goto select;
        }
    case 44:
        {
            register unsigned char* byte4 __asm__("$4");
            register int (*callback2)() __asm__("$2");
            rawValue3=Anim44Player4CView2;
            rawValue2=1;
            if(rawValue3!=rawValue2)goto other44;
            if(Anim44Data6E53CView2&0x850)goto callback44;
            if(Anim44Player54View1<61)return;
            callback44:callback2=Anim44Data74374View1;
            __asm__("" : "=r"(callback2):"0"(callback2));
            if(!callback2)goto missingCallback;
            callback2();
            return;
            missingCallback:goto call498C0;
            other44:if(Anim44Call40994View2())return;
            if((Anim44Data6E53CView2&64) && Anim44Player54View1>=9){
                nextSelector4=6;
                goto select;
            }
            byte4=&Anim44Player100View1;
            __asm__("" : "=r"(byte4):"0"(byte4));
            if(!*byte4){
                nextSelector4=7;
                goto select;
            }
            if(!(Anim44Data6E53CView2&128))goto mode44;
            if(Anim44Player54View1<9)goto mode44;
            rawValue2=*(int*)(Anim44Data6EE2CView1+220);
            byte4-=256;
            if(!rawValue2)goto mode44;
            rawValue2=Anim44Call1A310View1(byte4,1024,1,0);
            nextSelector4=40;
            if(!rawValue2)goto select;
            mode44:rawValue3=Anim44Data6E044View1;
            rawValue2=7;
            if(rawValue3==rawValue2)return;
            rawValue2=Anim44Data6E535View1;
            nextSelector4=43;
            if(rawValue2)return;
            goto select;
        }
    case 47:
        if(Anim44Call40994View1())return;
        if(Anim44Data6E53CView1&64){
            rawValue2=Anim44Data6E538View1&16384;
            nextSelector4=6;
            if(rawValue2)goto specialJump;
            __asm__ volatile("" ::: "memory");
            goto select;
        }
        rawValue2=Anim44PlayerACView1;
        nextSelector4=50;
        if(!rawValue2)return;
        goto select;
    case 50:
        if(Anim44Call40994View1())return;
        if(Anim44Data6E53CView1&64){
            rawValue2=Anim44Data6E538View1&16384;
            nextSelector4=6;
            if(rawValue2)goto specialJump;
            goto select;
        }
        rawValue2=Anim44PlayerACView1;
        nextSelector4=47;
        if(!rawValue2)goto select;
        rawValue2=Anim44PlayerA0View1;
        rawValue3=Anim44PlayerB4View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<rawValue3;
        if(!rawValue2)return;
        rawValue2=Anim44PlayerA4View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<1024;
        nextSelector4=52;
        if(!rawValue2)goto select;
        nextSelector4=51;
        goto select;
    case 51:case 52:
        if(Anim44Call40994View1())return;
        if(Anim44Data6E53CView1&64){
            rawValue2=Anim44Data6E538View1&16384;
            nextSelector4=6;
            if(!rawValue2)goto select;
            specialJump:Anim44Call4BEF8View1(7);
            rawValue2=3;
            Anim44Player4CView1=rawValue2;
            return;
        }
        rawValue2=Anim44PlayerACView1;
        nextSelector4=47;
        if(!rawValue2)goto select;
        rawValue2=Anim44PlayerA0View1;
        rawValue3=Anim44PlayerB4View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<rawValue3;
        nextSelector4=50;
        if(rawValue2)return;
        __asm__ volatile("" ::: "memory");
        goto select;
    case 57:
        if(Anim44Player54View1<25)return;
        if(Anim44Player280View1<0){
            __asm__ volatile(""::"i"(0x80091D50):"memory");
            nextSelector4=31;
            goto select;
        }
        rawValue2=10;
        rawValue3=Anim44Player144View1;
        nextSelector4=41;
        if(rawValue3!=rawValue2)goto select;
        nextSelector4=44;
        goto select;
    case 115:
        rawValue2=(int)Anim44Player250View1;
        callback3=Anim44Data7431CView1;
        record16=Anim44Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue2=Anim44PlayerB8View1<4;
        if(!rawValue2)goto airborne115;
        rawValue2=Anim44PlayerE4View1<23;
        if(rawValue2)goto ground115;
        airborne115:__asm__ volatile(""::"i"(0x80091DC8):"memory");
        nextSelector4=119;
        goto select;
    ground115:
        rawValue2=Anim44Data6E53CView3&64;
        nextSelector4=118;
        if(rawValue2)goto select;
        rawValue2=Anim44Field(record16,int*,0x78);
        if(!rawValue2)goto input115;
        rawValue2=Anim44Field(record16,int*,0x7C);
        nextSelector4=122;
        if(rawValue2)goto select;
    input115:
        rawValue2=Anim44Data6E538View3;
        rawValue3=8;
        rawValue2&=15;
        if(rawValue2==rawValue3){
            rawValue2=31;
            rawValue3=Anim44Data6E044View2;
            nextSelector4=131;
            if(rawValue3!=rawValue2)goto select;
        }
        __asm__ volatile("":::"memory");
        rawValue2=Anim44Data6E538View3;
        rawValue3=4;
        rawValue2&=15;
        if(rawValue2==rawValue3){
            rawValue2=31;
            rawValue3=Anim44Data6E044View2;
            nextSelector4=132;
            if(rawValue3!=rawValue2)goto select;
        }
        rawValue2=Anim44PlayerA8View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<17;
        nextSelector4=116;
        if(!rawValue2)goto select;
        rawValue2=Anim44PlayerACView2;
        if(rawValue2)goto select;
        rawValue2=25;
        rawValue3=Anim44Field(record16,int*,0x4C);
        nextSelector4=126;
        if(rawValue3!=rawValue2)return;
        goto select;
    case 116:
        rawValue2=(int)Anim44Player250View1;
        callback3=Anim44Data7431CView1;
        record16=Anim44Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue2=Anim44PlayerB8View1<4;
        if(!rawValue2)goto airborne116;
        rawValue2=Anim44PlayerE4View1<23;
        if(rawValue2)goto ground116;
        airborne116:__asm__ volatile(""::"i"(0x80091F04):"memory");
        nextSelector4=119;
        goto select;
    ground116:
        rawValue2=Anim44Data6E53CView3&64;
        nextSelector4=118;
        if(rawValue2)goto select;
        rawValue2=Anim44Field(record16,int*,0x78);
        if(!rawValue2)goto input116;
        rawValue2=Anim44Field(record16,int*,0x7C);
        if(!rawValue2)goto reload116;
        rawValue2=Anim44Data6E538View3&128;
        nextSelector4=130;
        if(!rawValue2)goto select;
        reload116:__asm__ volatile("":::"memory");
        rawValue2=Anim44Field(record16,int*,0x78);
        if(!rawValue2)goto input116;
        rawValue2=Anim44Field(record16,int*,0x7C)<12;
        nextSelector4=122;
        if(!rawValue2)goto select;
    input116:
        rawValue2=Anim44Data6E538View3;
        rawValue3=rawValue2&15;
        rawValue2=8;
        if(rawValue3==rawValue2){
            __asm__ volatile(""::"i"(0x80091F9C):"memory");
            nextSelector4=131;
            goto select;
        }
        rawValue2=4;
        nextSelector4=132;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim44Data6E535View2;
        if(!rawValue2)goto afterLatch116;
        rawValue2=Anim44PlayerB0View2;
        if(!rawValue2)goto latch116;
        rawValue2=40;
        rawValue3=Anim44Data6E044View2;
        if(rawValue3!=rawValue2)goto afterLatch116;
        latch116:__asm__ volatile(""::"i"(0x80091FE8):"memory");
        nextSelector4=115;
        goto select;
    afterLatch116:
        rawValue2=Anim44PlayerB4View2<3073;
        if(rawValue2)return;
        nextSelector4=(int)Anim44Player250View1;
        rawValue2=Anim44Call55E84View1((void*)nextSelector4);
        rawValue2=rawValue2<37;
        nextSelector4=117;
        if(rawValue2)return;
        goto select;
    case 117:
        rawValue2=(int)Anim44Player250View1;
        callback3=Anim44Data7431CView1;
        record16=Anim44Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue2=Anim44PlayerB8View1<4;
        if(!rawValue2)goto airborne117;
        rawValue2=Anim44PlayerE4View1<23;
        if(rawValue2)goto ground117;
        airborne117:__asm__ volatile(""::"i"(0x80092080):"memory");
        nextSelector4=119;
        goto select;
    ground117:
        rawValue2=Anim44Data6E53CView3&64;
        nextSelector4=118;
        if(rawValue2)goto select;
        rawValue2=Anim44Field(record16,int*,0x78);
        if(!rawValue2)goto input117;
        rawValue2=Anim44Field(record16,int*,0x7C);
        if(!rawValue2)goto reload117;
        rawValue2=Anim44Data6E538View3&128;
        nextSelector4=130;
        if(!rawValue2)goto select;
        reload117:__asm__ volatile("":::"memory");
        rawValue2=Anim44Field(record16,int*,0x78);
        if(!rawValue2)goto input117;
        rawValue2=Anim44Field(record16,int*,0x7C)<12;
        nextSelector4=122;
        if(!rawValue2)goto select;
    input117:
        rawValue2=Anim44Data6E538View3;
        rawValue3=rawValue2&15;
        rawValue2=8;
        if(rawValue3==rawValue2){
            __asm__ volatile(""::"i"(0x80092118):"memory");
            nextSelector4=131;
            goto select;
        }
        rawValue2=4;
        nextSelector4=132;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim44Data6E535View2;
        if(!rawValue2)goto afterLatch117;
        rawValue2=Anim44PlayerB0View2;
        if(!rawValue2)goto latch117;
        rawValue2=40;
        rawValue3=Anim44Data6E044View2;
        if(rawValue3!=rawValue2)goto afterLatch117;
        latch117:__asm__ volatile(""::"i"(0x80092164):"memory");
        nextSelector4=115;
        goto select;
    afterLatch117:
        rawValue2=Anim44PlayerB4View2<2560;
        if(!rawValue2)return;
        nextSelector4=(int)Anim44Player250View1;
        rawValue2=Anim44Player48View2;
        rawValue3=Anim44Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=115;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim44Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=116;
        if(!rawValue2){
            return;
        }
        __asm__ volatile(""::"i"(0x800921B8):"memory");
        goto select;
    case 118:
        rawValue2=(int)Anim44Player250View1;
        callback3=Anim44Data7431CView1;
        record16=Anim44Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue2=Anim44PlayerB8View1;
        if(rawValue2)goto private118;
        rawValue2=Anim44Player54View2<16;
        if(rawValue2)goto private118;
        rawValue2=Anim44PlayerE4View1<23;
        if(!rawValue2)return;
        rawValue3=Anim44PlayerCCView1;
        rawValue2=Anim44Player8CView1;
        product5=rawValue3*rawValue2;
        rawValue3=Anim44PlayerD0View1;
        rawValue2=Anim44Player90View1;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim44PlayerD4View1;
        rawValue2=Anim44Player94View1;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)return;
        rawValue2=Anim44Data6E538View3;
        rawValue3=rawValue2&15;
        rawValue2=8;
        if(rawValue3==rawValue2){
            __asm__ volatile(""::"i"(0x800922A8):"memory");
            nextSelector4=131;
            goto select;
        }
        rawValue2=4;
        nextSelector4=132;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim44PlayerACView2;
        nextSelector4=120;
        if(!rawValue2)goto select;
        rawValue2=Anim44PlayerB4View2<3073;
        nextSelector4=116;
        if(rawValue2)goto select;
        __asm__ volatile(""::"i"(0x800922E4):"memory");
        nextSelector4=117;
        goto select;
        private118:rawValue2=Anim44Field(record16,int*,0x78);
        if(!rawValue2)goto finish118;
        rawValue2=Anim44Field(record16,int*,0x7C);
        if(!rawValue2)goto finish118;
        rawValue2=Anim44Data6E538View3&128;
        nextSelector4=130;
        if(!rawValue2)goto select;
    finish118:
        nextSelector4=(int)Anim44Player250View1;
        rawValue2=Anim44Player48View2;
        rawValue3=Anim44Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=115;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim44Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2){
            return;
        }
        __asm__ volatile(""::"i"(0x80092358):"memory");
        goto preserveAge;
    case 119:
        rawValue2=(int)Anim44Player250View1;
        callback3=Anim44Data7431CView1;
        record16=Anim44Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue2=Anim44PlayerB8View1;
        rawValue3=2;
        if(rawValue2)goto other119;
        rawValue2=Anim44PlayerE4View1<23;
        if(!rawValue2)return;
        rawValue2=Anim44Data6E538View3;
        rawValue3=rawValue2&15;
        rawValue2=8;
        if(rawValue3==rawValue2){
            __asm__ volatile(""::"i"(0x800923CC):"memory");
            nextSelector4=131;
            goto effect119;
        }
        rawValue2=4;
        nextSelector4=132;
        if(rawValue3==rawValue2)goto effect119;
        rawValue2=Anim44PlayerACView2;
        if(rawValue2)goto distance119;
        nextSelector4=120;
        goto effect119;
        distance119:rawValue2=Anim44PlayerB4View2<3073;
        nextSelector4=116;
        if(rawValue2)goto effect119;
        nextSelector4=117;
        effect119:Anim44Call4BEF8View3(nextSelector4);
        {
            register int (*spawn2)(int,int,void*,int) __asm__("$2")=Anim44DataSpawnParticleView1;
            if(spawn2)spawn2(8,33,0,2);
        }
        rawValue2=(int)Anim44Data6C654View1;
        product5=0;
        nextSelector4=Anim44Field((void*)rawValue2,unsigned char*,0x12);
        Anim44CallPlaySoundView1((unsigned char)nextSelector4,product5,0);
        rawValue2=Anim44Player58View1<24;
        if(rawValue2)return;
        rawValue2=120;
        Anim44Data6E530View1=rawValue2;
        rawValue2=15;
        Anim44Data6E52CView1=rawValue2;
        return;
        other119:rawValue2=2;
        rawValue3=Anim44Player50View1;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim44Field(record16,int*,0x78);
        if(!rawValue2)return;
        rawValue2=Anim44Field(record16,int*,0x7C);
        if(!rawValue2)return;
        rawValue2=Anim44Data6E538View3&128;
        nextSelector4=130;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x800924D8):"memory");
        goto select;
    case 120:
        rawValue2=(int)Anim44Player250View1;
        callback3=Anim44Data7431CView1;
        record16=Anim44Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue2=Anim44Data6E53CView3&64;
        nextSelector4=118;
        if(rawValue2)goto select;
        rawValue2=Anim44PlayerB8View1<4;
        nextSelector4=119;
        if(!rawValue2)goto select;
        rawValue2=Anim44PlayerE4View1<23;
        if(!rawValue2)goto select;
        rawValue2=Anim44Field(record16,int*,0x78);
        if(!rawValue2)goto input120;
        rawValue2=Anim44Field(record16,int*,0x7C);
        nextSelector4=122;
        if(rawValue2)goto select;
    input120:
        rawValue2=Anim44Data6E538View3;
        rawValue3=rawValue2&15;
        rawValue2=8;
        if(rawValue3==rawValue2){
            __asm__ volatile(""::"i"(0x80092588):"memory");
            nextSelector4=131;
            goto select;
        }
        rawValue2=4;
        nextSelector4=132;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim44Data6E535View2;
        nextSelector4=116;
        if(!rawValue2)goto select;
        __asm__ volatile("":::"memory");
        rawValue2=Anim44Data6E53CView3&32;
        nextSelector4=115;
        if(rawValue2)goto select;
        nextSelector4=(int)Anim44Player250View1;
        rawValue2=Anim44Player48View2;
        rawValue3=Anim44Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=115;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim44Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=115;
        if(!rawValue2){
            return;
        }
        __asm__ volatile(""::"i"(0x800925F8):"memory");
        goto select;
    case 121:
        nextSelector4=(int)Anim44Player250View1;
        rawValue2=Anim44Player48View2;
        rawValue3=Anim44Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=115;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim44Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2){
            return;
        }
        goto done121;
        done121:rawValue2=Anim44Player280View2;
        if(rawValue2<0){
            nextSelector4=128;
            goto select;
        }
        rawValue2=Anim44PlayerB8View1;
        nextSelector4=115;
        if(!rawValue2)goto select;
        nextSelector4=119;
        goto select;
    case 122:
        rawValue2=Anim44Data7431CView1(1);
        if(rawValue2)return;
        rawValue2=Anim44PlayerB8View1<4;
        if(!rawValue2)goto airborne122;
        rawValue2=Anim44PlayerE4View1<23;
        if(rawValue2)goto ground122;
        airborne122:__asm__ volatile(""::"i"(0x800926B8):"memory");
        nextSelector4=119;
        goto select;
    ground122:
        nextSelector4=(int)Anim44Player250View1;
        rawValue2=Anim44Player48View2;
        rawValue3=Anim44Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=115;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim44Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=123;
        if(!rawValue2){
            return;
        }
        __asm__ volatile(""::"i"(0x800926F4):"memory");
        goto select;
    case 123:
        rawValue2=Anim44Data7431CView1(1);
        if(rawValue2)return;
        rawValue2=Anim44PlayerB8View1<4;
        if(!rawValue2)goto airborne123;
        rawValue2=Anim44PlayerE4View1<23;
        if(rawValue2)goto ground123;
        airborne123:__asm__ volatile(""::"i"(0x80092748):"memory");
        nextSelector4=119;
        goto select;
    ground123:
        rawValue2=Anim44Data6E538View3&128;
        nextSelector4=124;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x80092768):"memory");
        goto select;
    case 124:
        rawValue2=Anim44Data7431CView1(1);
        if(rawValue2)return;
        rawValue2=Anim44PlayerB8View1<4;
        if(!rawValue2)goto airborne124;
        rawValue2=Anim44PlayerE4View1<23;
        if(rawValue2)goto ground124;
        airborne124:__asm__ volatile(""::"i"(0x800927BC):"memory");
        nextSelector4=119;
        goto select;
    ground124:
        nextSelector4=(int)Anim44Player250View1;
        rawValue2=Anim44Player48View2;
        rawValue3=Anim44Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=115;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim44Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=115;
        if(!rawValue2){
            return;
        }
        __asm__ volatile(""::"i"(0x800927F8):"memory");
        goto select;
    case 126:
        rawValue2=(int)Anim44Player250View1;
        callback3=Anim44Data7431CView1;
        record16=Anim44Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue2=Anim44PlayerB8View1<4;
        if(!rawValue2)goto airborne126;
        rawValue2=Anim44PlayerE4View1<23;
        if(rawValue2)goto ground126;
        airborne126:__asm__ volatile(""::"i"(0x80092854):"memory");
        nextSelector4=119;
        goto select;
    ground126:
        rawValue2=Anim44Data6E53CView3&64;
        nextSelector4=118;
        if(rawValue2)goto select;
        rawValue2=Anim44Field(record16,int*,0x78);
        if(!rawValue2)goto input126;
        rawValue2=Anim44Field(record16,int*,0x7C);
        nextSelector4=122;
        if(rawValue2)goto select;
    input126:
        rawValue2=Anim44Data6E538View3;
        rawValue3=8;
        rawValue2&=15;
        if(rawValue2==rawValue3){
            rawValue2=31;
            rawValue3=Anim44Data6E044View2;
            nextSelector4=131;
            if(rawValue3!=rawValue2)goto select;
        }
        __asm__ volatile("":::"memory");
        rawValue2=Anim44Data6E538View3;
        rawValue3=4;
        rawValue2&=15;
        if(rawValue2==rawValue3){
            rawValue2=31;
            rawValue3=Anim44Data6E044View2;
            nextSelector4=132;
            if(rawValue3!=rawValue2)goto select;
        }
        rawValue2=Anim44PlayerA8View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<17;
        nextSelector4=116;
        if(!rawValue2)goto select;
        rawValue2=Anim44PlayerACView2;
        if(rawValue2)goto select;
        nextSelector4=(int)Anim44Player250View1;
        rawValue2=Anim44Player48View2;
        rawValue3=Anim44Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=115;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim44Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=115;
        if(!rawValue2){
            return;
        }
        __asm__ volatile(""::"i"(0x80092958):"memory");
        goto select;
    case 128:
        nextSelector4=(int)Anim44Player250View1;
        rawValue2=Anim44Player48View2;
        rawValue3=Anim44Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=115;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim44Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2){
            return;
        }
        goto helper128;
        call498C0:helper128:Anim44Call498C0View1((void*)nextSelector4);
        return;
    case 129:
        rawValue2=Anim44Data6E53CView3&64;
        if(rawValue2){
            rawValue2=1;
            Anim44Player1B6View1=rawValue2;
        }
        nextSelector4=(int)&Anim44Player280View2;
        rawValue2=*(int*)nextSelector4;
        if(rawValue2<0){
            rawValue2=36863;
            rawValue3=Anim44Player144View2;
            rawValue2=rawValue2<rawValue3;
            if(!rawValue2)return;
            rawValue2=-1;
            Anim44Player28CView1=rawValue2;
            goto helper128;
        }
        rawValue3=Anim44Player54View2;
        rawValue2=rawValue3<61;
        if(!rawValue2){
            rawValue2=-1;
            *(int*)nextSelector4=rawValue2;
            return;
        }
        rawValue2=rawValue3<16;
        if(rawValue2)return;
        rawValue2=Anim44Player1B6View1;
        if(!rawValue2)return;
        product5=Anim44Player28CView1;
        nextSelector4=118;
        if(product5<0)goto select;
        nextSelector4=Anim44Player290View1;
        rawValue2=Anim44Call3BF6CView1(nextSelector4,product5);
        if(rawValue2){
            nextSelector4=Anim44Player28CView1;
            Anim44Call3BE70View1(nextSelector4);
        }
        rawValue2=-1;
        Anim44Player28CView1=rawValue2;
        nextSelector4=118;
        goto select;
    case 130:
        rawValue2=Anim44Data7431CView1(1);
        if(rawValue2)return;
        nextSelector4=(int)Anim44Player250View1;
        rawValue2=Anim44Player48View2;
        rawValue3=Anim44Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=115;
        if(rawValue3!=rawValue2)goto other130;
        rawValue2=Anim44Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2){
            goto other130;
        }
        goto completed130;
        completed130:rawValue2=Anim44PlayerB8View1;
        if(rawValue2)goto preserveAge;
        rawValue2=Anim44Data6E535View2;
        if(rawValue2)goto latch130;
        rawValue2=Anim44PlayerB4View2<2560;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=116;
        if(rawValue2)goto select;
        __asm__ volatile(""::"i"(0x80092B24):"memory");
        nextSelector4=117;
        goto select;
        latch130:__asm__ volatile(""::"i"(0x80092B2C):"memory");
        nextSelector4=115;
        goto select;
        preserveAge:savedWord16=Anim44Player54View2;
        Anim44Call4BEF8View3(119);
        Anim44Player54View2=savedWord16;
        return;
        other130:nextSelector4=(int)&Anim44Player50View1;
        rawValue3=*(int*)nextSelector4;
        rawValue2=2;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim44PlayerB8View1;
        if(rawValue2)return;
        rawValue2=1;
        *(int*)nextSelector4=rawValue2;
        goto select116;
    case 131:
        rawValue2=(int)Anim44Player250View1;
        callback3=Anim44Data7431CView1;
        record16=Anim44Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue2=Anim44PlayerB8View1<4;
        if(!rawValue2)goto airborne131;
        rawValue2=Anim44PlayerE4View1<23;
        if(rawValue2)goto ground131;
        airborne131:__asm__ volatile(""::"i"(0x80092BDC):"memory");
        nextSelector4=119;
        goto select;
    ground131:
        rawValue2=Anim44Data6E53CView3&64;
        nextSelector4=118;
        if(rawValue2)goto select;
        rawValue2=Anim44Field(record16,int*,0x78);
        if(!rawValue2)goto input131;
        rawValue2=Anim44Field(record16,int*,0x7C);
        if(!rawValue2)goto reload131;
        rawValue2=Anim44Data6E538View3&128;
        nextSelector4=130;
        if(!rawValue2)goto select;
        reload131:__asm__ volatile("":::"memory");
        rawValue2=Anim44Field(record16,int*,0x78);
        if(!rawValue2)goto input131;
        rawValue2=Anim44Field(record16,int*,0x7C)<12;
        nextSelector4=122;
        if(!rawValue2)goto select;
    input131:
        rawValue2=Anim44Data6E538View3;
        rawValue3=rawValue2&15;
        rawValue2=8;
        if(rawValue3==rawValue2)return;
        rawValue2=4;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=132;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim44Data6E535View2;
        nextSelector4=116;
        if(!rawValue2)goto select;
        rawValue2=Anim44PlayerB0View2;
        if(!rawValue2)goto latch131;
        rawValue2=40;
        rawValue3=Anim44Data6E044View2;
        if(rawValue3!=rawValue2)goto select;
        latch131:__asm__ volatile(""::"i"(0x80092CB8):"memory");
        nextSelector4=115;
        goto select;
    case 132:
        rawValue2=(int)Anim44Player250View1;
        callback3=Anim44Data7431CView1;
        record16=Anim44Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue2=Anim44PlayerB8View1<4;
        if(!rawValue2)goto airborne132;
        rawValue2=Anim44PlayerE4View1<23;
        if(rawValue2)goto ground132;
        airborne132:__asm__ volatile(""::"i"(0x80092D14):"memory");
        nextSelector4=119;
        goto select;
    ground132:
        rawValue2=Anim44Data6E53CView3&64;
        nextSelector4=118;
        if(rawValue2)goto select;
        rawValue2=Anim44Field(record16,int*,0x78);
        if(!rawValue2)goto input132;
        rawValue2=Anim44Field(record16,int*,0x7C);
        if(!rawValue2)goto reload132;
        rawValue2=Anim44Data6E538View3&128;
        nextSelector4=130;
        if(!rawValue2)goto select;
        reload132:__asm__ volatile("":::"memory");
        rawValue2=Anim44Field(record16,int*,0x78);
        if(!rawValue2)goto input132;
        rawValue2=Anim44Field(record16,int*,0x7C)<12;
        nextSelector4=122;
        if(!rawValue2)goto select;
    input132:
        rawValue2=Anim44Data6E538View3;
        rawValue3=rawValue2&15;
        rawValue2=4;
        if(rawValue3==rawValue2)return;
        rawValue2=8;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=131;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim44Data6E535View2;
        nextSelector4=116;
        if(!rawValue2)goto select;
        rawValue2=Anim44PlayerB0View2;
        if(!rawValue2)goto latch132;
        rawValue2=40;
        rawValue3=Anim44Data6E044View2;
        if(rawValue3!=rawValue2)goto select;
        latch132:__asm__ volatile(""::"i"(0x80092DF0):"memory");
        nextSelector4=115;
        goto select;
        default:return;
    }
    select116:nextSelector4=116;
    select:Anim44Call4BEF8View1(nextSelector4);
    return;
}
#undef Anim44Field
