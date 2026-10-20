#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80089628.
 * Assembly SHA256 7c79cc9bdf4a355ab38ae477f6943f2482fec00979eae7a3edb4acb0441a3c72.
 * AI-generated; not human reviewed. All2727 original instructions and
 * 59 selectors (bias19) and one owned padding word are required. Original frame0x1A0 retains scratch
 * 10..184, savedS0..S4, incoming slotS2 and combinedS3.
 * Ten exact groups and six near groups reuse verified12/13/21/22/34;
 * all concrete fields, registers, frame offsets and actual joins are checked.
 * Original65..77 preserve field widths, independent helper calls, wrapped
 * trig/vector/particle products, byte stores, controller tests and scalar bounds.
 * State68's child pointer and consumed combined/particle values share S3
 * only across disjoint original lifetimes. Ordinary low-product variables
 * retain distinct short lifetimes; initialized square19 keeps original MFLO.
 * Actual joins:29->72 clamp8008BA5C;43->47 clear8008AD70;
 * 38->50 vector8008B0EC;49->71 vector8008B99C;66->71 scalar8008B978;
 * 67->70 +30 scalar8008B698;67/70->73 -320 scalar8008BDF4.
 * Typed aliases remain distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit every word.
 * Identified Rev1 Sheila callback tables are supporting source references;
 * the original Rev0 instructions and complete hashes remain authoritative.
 * Raw units/fixed point, complete helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every native/linked instruction, conditional/internal target,
 * selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Physics42Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Physics42Call363DCView1() __asm__("func_800363DC");
unsigned char Physics42Call40D10View1() __asm__("func_80040D10");
unsigned char Physics42Call41580View1() __asm__("func_80041580");
unsigned char Physics42Call416F4View1() __asm__("func_800416F4");
unsigned char Physics42Call417FCView1() __asm__("func_800417FC");
unsigned char Physics42Call41B64View1() __asm__("func_80041B64");
int Physics42Call4E9E4View1() __asm__("func_8004E9E4");
int Physics42Call4EA2CView1() __asm__("func_8004EA2C");
unsigned char Physics42Call4ED6CView1() __asm__("func_8004ED6C");
int Physics42Call4EDE8View1() __asm__("func_8004EDE8");
unsigned char Physics42Call4F08CView1() __asm__("func_8004F08C");
unsigned char Physics42Call4F168View1() __asm__("func_8004F168");
unsigned char Physics42Call4F178View1() __asm__("func_8004F178");
unsigned char Physics42Call4F194View1() __asm__("func_8004F194");
unsigned char Physics42Call4F1C8View1() __asm__("func_8004F1C8");
int Physics42CallRandView1() __asm__("rand");
extern unsigned char Physics42Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics42Data65920View1 __asm__("D_80065920");
extern void *Physics42Data6C570View1 __asm__("D_8006C570");
extern int Physics42Data6C640View1 __asm__("D_8006C640");
extern int Physics42Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics42Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics42Player0View1 __asm__("D_80070328");
extern int Physics42Player94View1 __asm__("D_80070328+0x94");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics42Call40D10View2() __asm__("func_80040D10");
int Physics42Call410F8View1() __asm__("func_800410F8");
int Physics42Call41580View2() __asm__("func_80041580");
int Physics42Call416F4View2() __asm__("func_800416F4");
int Physics42Call417FCView2() __asm__("func_800417FC");
int Physics42Call41848View1() __asm__("func_80041848");
int Physics42Call41B64View2() __asm__("func_80041B64");
int Physics42Call4EA2CView2() __asm__("func_8004EA2C");
int Physics42Call4EDE8View2() __asm__("func_8004EDE8");
int Physics42Call4F08CView2() __asm__("func_8004F08C");
int Physics42Call4F168View2() __asm__("func_8004F168");
int Physics42Call4F178View2() __asm__("func_8004F178");
int Physics42Call4F194View2() __asm__("func_8004F194");
int Physics42Call4F1C8View2() __asm__("func_8004F1C8");
extern int Physics42Data6E044View2 __asm__("D_8006E044");
extern int Physics42Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics42Player0View2 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics42PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics42Player94View2 __asm__("D_80070328+0x94");
extern int Physics42PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics42Player80View1 __asm__("D_80070328+0x80");
extern int Physics42PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics42Player64View1 __asm__("D_80070328+0x64");
extern int Physics42Player88View1 __asm__("D_80070328+0x88");
extern int Physics42Player84View1 __asm__("D_80070328+0x84");
extern int Physics42Player144View1 __asm__("D_80070328+0x144");
extern int Physics42Player60View1 __asm__("D_80070328+0x60");
extern int Physics42PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics42Player4CView1 __asm__("D_80070328+0x4C");
extern int Physics42Player14CView1 __asm__("D_80070328+0x14C");
extern int Physics42Player5CView1 __asm__("D_80070328+0x5C");
extern unsigned char Physics42PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics42PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics42Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics42Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics42Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics42Player101View1 __asm__("D_80070328+0x101");
extern int Physics42PlayerA4View1 __asm__("D_80070328+0xA4");
int Physics42Call40F48View1() __asm__("func_80040F48");
int Physics42Call43194View1() __asm__("func_80043194");
int Physics42Call4E880View1() __asm__("func_8004E880");
int Physics42Call4ED6CView2() __asm__("func_8004ED6C");
int Physics42Call4EDE8View3() __asm__("func_8004EDE8");
int Physics42Call4F08CView3() __asm__("func_8004F08C");
int Physics42Call4F168View3() __asm__("func_8004F168");
int Physics42Call4F178View3() __asm__("func_8004F178");
int Physics42Call4F194View3() __asm__("func_8004F194");
int Physics42Call4F1C8View3() __asm__("func_8004F1C8");
extern unsigned char Physics42Data658A0View2 __asm__("D_800658A0");
extern unsigned char Physics42Data65920View2 __asm__("D_80065920");
extern int Physics42Data6C514View1 __asm__("D_8006C514");
extern int Physics42Data6E044View3 __asm__("D_8006E044");
extern int Physics42Data6E344View1 __asm__("D_8006E344");
extern unsigned char Physics42Player0View3 __asm__("D_80070328");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics42Player16CView1 __asm__("D_80070328+0x16C");
int Physics42Call417FCView3() __asm__("func_800417FC");
int Physics42Call4E880View2() __asm__("func_8004E880");
int Physics42Call4E9E4View2() __asm__("func_8004E9E4");
int Physics42Call4EA2CView3() __asm__("func_8004EA2C");
int Physics42Call4EDE8View4() __asm__("func_8004EDE8");
int Physics42Call4F08CView4() __asm__("func_8004F08C");
int Physics42Call4F0E8View1() __asm__("func_8004F0E8");
int Physics42Call4F178View4() __asm__("func_8004F178");
int Physics42Call4F194View4() __asm__("func_8004F194");
int Physics42Call4F1C8View4() __asm__("func_8004F1C8");
extern void *(*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics42Player94View3 __asm__("D_80070328+0x94");
extern int Physics42PlayerACView2 __asm__("D_80070328+0xAC");
extern int Physics42PlayerB0View2 __asm__("D_80070328+0xB0");
extern int Physics42Player148View1 __asm__("D_80070328+0x148");
extern int Physics42Player210View1 __asm__("D_80070328+0x210");
extern int Physics42Player220View1 __asm__("D_80070328+0x220");
extern int Physics42Player98View1 __asm__("D_80070328+0x98");
extern int Physics42PlayerA0View2 __asm__("D_80070328+0xA0");
extern int Physics42PlayerB8View2 __asm__("D_80070328+0xB8");
extern int Physics42PlayerCCView1 __asm__("D_80070328+0xCC");
extern int Physics42PlayerD0View1 __asm__("D_80070328+0xD0");
extern int Physics42PlayerE4View1 __asm__("D_80070328+0xE4");
extern unsigned char Physics42PlayerFCView2 __asm__("D_80070328+0xFC");
int Physics42Call40D10View3() __asm__("func_80040D10");
int Physics42Call410F8View2() __asm__("func_800410F8");
int Physics42Call41580View3() __asm__("func_80041580");
int Physics42Call417FCView4() __asm__("func_800417FC");
int Physics42Call41848View2() __asm__("func_80041848");
int Physics42Call41B64View3() __asm__("func_80041B64");
int Physics42Call4EA2CView4() __asm__("func_8004EA2C");
int Physics42Call4ED6CView3() __asm__("func_8004ED6C");
int Physics42Call4F110View1() __asm__("func_8004F110");
int Physics42Call4F168View4() __asm__("func_8004F168");
int Physics42Call4F178View5() __asm__("func_8004F178");
int Physics42Call4F194View5() __asm__("func_8004F194");
int Physics42CallRandView2() __asm__("rand");
extern int* Physics42Data6C570View2 __asm__("D_8006C570");
extern int Physics42Data6C640View2 __asm__("D_8006C640");
extern int Physics42Data6E044View4 __asm__("D_8006E044");
extern unsigned char Physics42Player0View4 __asm__("D_80070328");
extern void *(*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics42Player158View1 __asm__("D_80070328+0x158");
extern int Physics42Player20CView2 __asm__("D_80070328+0x20C");
extern void *(*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics50_SpawnParticle)() __asm__("SpawnParticle");
int Physics42Call4F110View2() __asm__("func_8004F110");
int Physics42Call4F178View6() __asm__("func_8004F178");
int Physics42Call4F194View6() __asm__("func_8004F194");
extern int Physics42Data6E1D4View1 __asm__("D_8006E1D4");
extern int Physics42Data6E1D8View1 __asm__("D_8006E1D8");
extern int Physics42Data6E52CView1 __asm__("D_8006E52C");
extern int Physics42Data6E530View1 __asm__("D_8006E530");
extern unsigned char Physics42Player0View5 __asm__("D_80070328");
extern void *(*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics42Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics42Player80View2 __asm__("D_80070328+0x80");
extern int Physics42Player250View1 __asm__("D_80070328+0x250");
extern int Physics42Player54View1 __asm__("D_80070328+0x54");
extern int Physics42PlayerD4View1 __asm__("D_80070328+0xD4");
extern void *Physics42Data6C654View1 __asm__("D_8006C654");
int Physics42DataPlaySoundView1() __asm__("PlaySound");
extern int Physics42Player8CView2 __asm__("D_80070328+0x8C");
extern int Physics42Player90View1 __asm__("D_80070328+0x90");
void func_level_42_80089628(int slotIndex) {
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
    register int particleThreshold __asm__("$19");
    register void *vectorAt40 __asm__("$16");
    register void *vectorAt30 __asm__("$17");
    register void *call4 __asm__("$4");
    register void *call5 __asm__("$5");
    register void *call6 __asm__("$6");
    int lowProduct0,lowProduct1,lowProduct2,lowProduct3,lowProduct4,lowProduct5;
    register void *globalPointer __asm__("$3");
    struct {
        int sp10,sp14,sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4,spB8,spBC,spC0,spC4,spC8,spCC,spD0,spD4,spD8,spDC,spE0,spE4,spE8,spEC,spF0,spF4,spF8,spFC,sp100,sp104,sp108,sp10C,sp110,sp114,sp118,sp11C,sp120,sp124,sp128,sp12C,sp130,sp134,sp138,sp13C,sp140,sp144,sp148,sp14C,sp150,sp154,sp158,sp15C,sp160,sp164,sp168,sp16C,sp170,sp174,sp178,sp17C,sp180,sp184;
    }
    originalFrame;
    register int signedTableWord __asm__("$7");
    register void *globalVector80 __asm__("$16");
    register void *globalVector80State20 __asm__("$16");
    register void *globalVector8CState20 __asm__("$18");
    register void *globalVector8C __asm__("$18");
    register void *var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$19");
    int temp_v0_4;
    int temp_v0_6;
    register int workWord3 __asm__("$3");
    register int particleIndex __asm__("$17");
    register int nextField94 __asm__("$2");
    register unsigned char *globalByteE __asm__("$18");
    register void *globalField4CPointer __asm__("$16");
    register void *globalFieldB8PointerState20 __asm__("$16");
    register void *globalFieldA4Pointer __asm__("$17");
    void *temp_v0_5;
    void *temp_v0_7;
    void *raw34_temp_a0_3;
    void *raw34_temp_s1_2;
    int raw34_temp_v0_6;
    int raw34_temp_v0_7;
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
    globalPointer=&Physics42Data6E548View1;
    workWord2+=(int)globalPointer;
    __asm__("":"=r"(workWord2):"0"(workWord2));
    Physics42Data6C570View1=(void*)workWord2;
    workWord2=Physics42Field(&Physics42Player0View1,int*,0x54);
    stateWord3=Physics42Field(&Physics42Player0View1,int*,0x48);
    combinedIndex=workWord2+savedSlotIndex;
    switch (stateWord3) {
    case 20:globalVector80 = &Physics42Player0View1 + 0x80;
        Physics42Call4F168View1(globalVector80);
        Physics42Call4F168View1(globalVector80 + 0xC);
        if (Physics42Data6E044View1 != 7) {
            Physics42Call40D10View1(0x1200);
            Physics42Call416F4View1();
            Physics42Call41580View1(0x5A, 0x10);
            return;
        }
        return;
    default:
        return;
    case 19:{
            int product19;
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            register int numeric7 __asm__("$7");
            register int angle16 __asm__("$16");
            register int square8 __asm__("$8");
            register int product10 __asm__("$10");
            workWord3=Physics42Data6E344View1;
            workWord2=13;
            if(workWord3==workWord2){
                workWord2=Physics42Data6C514View1;
                if(workWord2)return;
            }
            vectorAt30=&Physics42Player0View3+8;
            workWord3=Physics42Field(vectorAt30,int*,0);
            workWord2=Physics42Field(&Physics42Player0View3,int*,0x144);
            numeric4=workWord3-workWord2;
            workWord2=numeric4<1024;
            if(!workWord2)goto beyond19;
            workWord2=Physics42Player94View2;
            workWord2+=128;
            Physics42Player94View2=workWord2;
            workWord2=workWord2<4801;
            __asm__("":"=r"(numeric4):"0"(numeric4),"r"(workWord2));
            if(!workWord2){
                workWord2=4800;
                Physics42Player94View2=workWord2;
            }
            product19=numeric4*numeric4;
            call4=&originalFrame.sp10;
            workWord3=Physics42Field(&Physics42Player0View3,int*,0x148);
            __asm__ volatile(""::"r"(workWord2),"r"(workWord3),"r"(call4):"memory");
            workWord2=product19>>11;
            angle16=workWord2+workWord3;
            Physics42Player64View1=angle16;
            __asm__ volatile("":"=r"(vectorAt30):"0"(vectorAt30),"r"(call4):"memory");
            Physics42Call4F178View3(call4,vectorAt30+340);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics42Call4F1C8View3(call4,call5,vectorAt30-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            workWord2=Physics42Call4EDE8View3(call4,call5);
            numeric6=workWord2;
            workWord2=numeric6<1025;
            call4=&originalFrame.sp10;
            if(workWord2)goto commit19;
            call5=(void*)numeric6;
            __asm__ volatile(""::"i"(0x800897C8):"memory");
            numeric6=1024;
            goto limit19;
            beyond19:numeric5=Physics42Field(&Physics42Player0View3,int*,0x14C);
            workWord2=workWord3-numeric5;
            workWord2=workWord2<-1024;
            numeric6=numeric5-workWord3;
            if(!workWord2)goto curve19;
            __asm__ volatile("":"=r"(numeric6):"0"(numeric6),"i"(0x800897EC));
            workWord2=Physics42Player4CView1;
            workWord3=1;
            if(!workWord2){
                workWord2=Physics42Field(&Physics42Player0View3,int*,0x148);
                Physics42Player4CView1=workWord3;
                workWord2+=512;
                Physics42Field(&Physics42Player0View3,int*,0x148)=workWord2;
            }
            workWord2=Physics42Player94View2;
            workWord2+=128;
            Physics42Player94View2=workWord2;
            workWord2=workWord2<4801;
            if(!workWord2)Physics42Player94View2=4800;
            workWord2=Physics42Field(&Physics42Player0View3,int*,0x150);
            numeric6=numeric4-1024;
            workWord3=workWord2*numeric6;
            workWord2=Physics42Field(&Physics42Player0View3,int*,0x154);
            workWord2=workWord3/workWord2;
            call4=&originalFrame.sp10;
            workWord3=Physics42Field(&Physics42Player0View3,int*,0x148);
            angle16=workWord3+workWord2;
            workWord2=(numeric6<<10)>>10;
            workWord2=angle16+workWord2;
            angle16=workWord2&4095;
            Physics42Player64View1=angle16;
            Physics42Call4F178View3(call4,vectorAt30+340);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics42Call4F1C8View3(call4,call5,vectorAt30-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            workWord2=Physics42Call4EDE8View3(call4,call5);
            numeric6=workWord2;
            workWord2=numeric6<1025;
            call4=&originalFrame.sp10;
            if(workWord2)goto commit19;
            call5=(void*)numeric6;
            __asm__ volatile(""::"i"(0x800898FC):"memory");
            numeric6=1024;
            goto limit19;
            curve19:__asm__ volatile("":"=r"(numeric6):"0"(numeric6),"i"(0x80089904));
            workWord2=(numeric6*4800)>>10;
            Physics42Player94View2=workWord2;
            workWord2=Physics42Player16CView1;
            numeric7=Physics42Field(&Physics42Player0View3,int*,0x168);
            workWord3=Physics42Field(&Physics42Player0View3,int*,0x158);
            workWord2&=127;
            numeric4=numeric7<<1;
            Physics42Player16CView1=workWord2;
            workWord2=*(short*)(&Physics42Data65920View2+numeric4);
            workWord3+=1024;
            product10=workWord3*workWord2;
            square8=numeric6*numeric6;
            workWord2=product10>>12;
            originalFrame.sp10=workWord2;
            workWord2=*(short*)(&Physics42Data658A0View2+numeric4);
            workWord3=workWord3*workWord2;
            numeric7<<=4;
            call4=&originalFrame.sp10;
            call5=call4;
            __asm__("":"=r"(vectorAt30):"0"(vectorAt30),"r"(call4),"r"(call5));
            numeric6=(int)vectorAt30+340;
            workWord2=square8>>11;
            angle16=numeric7-workWord2;
            workWord2=workWord3>>12;
            originalFrame.sp14=workWord2;
            Physics42Call4F194View3(call4,call5,numeric6,numeric7);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics42Player64View1=angle16;
            Physics42Call4F1C8View3(call4,call5,vectorAt30-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            workWord2=Physics42Call4EDE8View3(call4,call5);
            numeric6=workWord2;
            workWord2=numeric6<2049;
            call4=&originalFrame.sp10;
            if(workWord2)goto commit19;
            call5=(void*)numeric6;
            numeric6=2048;
            limit19:Physics42Call4F08CView3(call4,call5,numeric6);
            commit19:workWord2=originalFrame.sp10;
            workWord3=originalFrame.sp14;
            Physics42Field(&Physics42Player0View3,int*,0x8C)=workWord2;
            Physics42Field(&Physics42Player0View3,int*,0x90)=workWord3;
            return;
        }
    case 29:Physics42Call4F168View3(&originalFrame.sp20);
        raw34_temp_s1_2 = &Physics42Player0View3 + 0x8C;
        Physics42Call4F1C8View3(&originalFrame.sp20, &originalFrame.sp20, raw34_temp_s1_2);
        if (Physics42Field(&Physics42Player0View3, int *, 0xB8) != 0) {
            originalFrame.sp28 = 0;
            raw34_temp_v0_6 = Physics42Call4EDE8View3(&originalFrame.sp20, 0);
            if (raw34_temp_v0_6 >= 0x41) {
                Physics42Call4F08CView3(&originalFrame.sp20, raw34_temp_v0_6, 0x40);
            }
            originalFrame.sp28 = -0xC0;
            call4=raw34_temp_s1_2-12;
            call5=raw34_temp_s1_2;
            call6=&originalFrame.sp20;
            goto commit29;
        }
        else {
            raw34_temp_v0_7 = Physics42Call4EDE8View3(&originalFrame.sp20, 1);
            if (raw34_temp_v0_7 >= 0x101) {
                Physics42Call4F08CView3(&originalFrame.sp20, raw34_temp_v0_7, 0x100);
            }
            Physics42Call4F194View3(raw34_temp_s1_2, raw34_temp_s1_2, &originalFrame.sp20);
            call4=raw34_temp_s1_2-12;
            call5=raw34_temp_s1_2;
            __asm__("":"=r"(call5):"0"(call5));
            call6=call5+92;
        }
        commit29:Physics42Call4F194View3(call4,call5,call6);
        raw34_temp_a0_3 = &Physics42Player0View3 + 0x8C;
        Physics42Call4F178View3(raw34_temp_a0_3, raw34_temp_a0_3 - 0xC);
        workWord2=Physics42Player94View2;
        __asm__ volatile(""::"i"(0x80089AF8):"memory");
        workWord2=workWord2<-8960;
        goto clamp19;
    case 28:{
            int lowProduct3Case28,lowProduct4Case28;
            Physics42Call40D10View1(0xC80);
            Physics42Call41580View1(0x28, 8);
            Physics42Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics42Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics42Call4EA2CView1(Physics42Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics42Field(&Physics42Player0View1,int*,0xB0);
            lowProduct3Case28=workWord3*workWord2;
            call4=(void*)Physics42Field(globalFieldA4Pointer,int*,0);
            workWord2=lowProduct3Case28>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp30=workWord2;
            workWord2=Physics42Call4E9E4View1(call4);
            workWord3=Physics42Field(&Physics42Player0View1,int*,0xB0);
            lowProduct4Case28=workWord3*workWord2;
            workWord2=lowProduct4Case28>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp34=workWord2;
            Physics42Call4F1C8View1(&originalFrame.sp30, &originalFrame.sp30, globalVector8C);
            originalFrame.sp38 = 0;
            temp_v0_4 = Physics42Call4EDE8View1(&originalFrame.sp30, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics42Call4F08CView1(&originalFrame.sp30, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics42Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp30);
            Physics42Call41B64View1();
            if (combinedIndex < 0xD) {
                __asm__("" :: "r"(combinedIndex));
                nextField94 = Physics42Field(&Physics42Player0View1, int *, 0x94) + 0x17;
            }
            else {
                nextField94 = Physics42Field(&Physics42Player0View1, int *, 0x94) - 0xC0;
            }
            Physics42Player94View1=nextField94;
            __asm__ volatile("" ::: "memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer=&Physics42Player0View1+0x148;
                __asm__("" : "=r"(globalPointer):"0"(globalPointer));
                particleIndex=0;
                if (Physics42Field(globalPointer,int*,0) != 0) {
                    workWord2=combinedIndex*4;
                    __asm__("" : "=r"(workWord2):"0"(workWord2));
                    particleThreshold=workWord2+combinedIndex;
                    globalByteE=globalPointer-0x13A;
                    vectorAt40=&originalFrame.sp50;
                    __asm__("" : "=r"(vectorAt40):"0"(vectorAt40));
                spawnParticleLoop:
                    if (particleThreshold < (Physics42CallRandView1() & 0xFF)) {
                        workWord2=Physics42Call363DCView1(0,0xC);
                        call4=globalByteE+0x22;
                        workWord3=*globalByteE;
                        __asm__("" : "=r"(workWord3):"0"(workWord3));
                        call5=vectorAt40;
                        __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
                        workWord3+=0x80;
                        __asm__("" : "=r"(workWord3):"0"(workWord3));
                        workWord3+=workWord2;
                        __asm__("" : "=r"(workWord3):"0"(workWord3));
                        workWord3=(workWord3&0xFF)*2;
                        signedTableWord = *(short*)(&Physics42Data65920View1 + workWord3);
                        call6=vectorAt40;
                        originalFrame.sp40 = (int) (signedTableWord * 5) >> 0xA;
                        workWord3=*(short*)(&Physics42Data658A0View1 + workWord3);
                        __asm__ volatile("" : "=r"(workWord3):"0"(workWord3):"memory");
                        originalFrame.sp48 = 0xE;
                        originalFrame.sp50 = -0x12C;
                        originalFrame.sp54 = 0;
                        originalFrame.sp58 = -0xC8;
                        __asm__ volatile("" ::: "memory");
                        originalFrame.sp44 = (workWord3 * 5) >> 0xA;
                        Physics42Call4ED6CView1(call4, call5, call6, signedTableWord);
                        originalFrame.sp50 += Physics42Call363DCView1(0, 0x50);
                        originalFrame.sp54 += Physics42Call363DCView1(0, 0x50);
                        originalFrame.sp58 += Physics42Call363DCView1(0, 0x50);
                        Physics42Call4F194View1(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 = Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp40);
                        workWord2=(int)temp_v0_5;
                        workWord3=8;
                        Physics42Field((void*)workWord2,signed char*,2)=workWord3;
                        workWord3=32;
                        Physics42Field((void*)workWord2,signed char*,10)=workWord3;
                    }
                    particleIndex += 1;
                    if (particleIndex < 2) {
                        goto spawnParticleLoop;
                    }
                }
            }
            break;
        }
    case 58:globalFieldB8PointerState20 = &Physics42Player0View1 + 0xB8;
        if (Physics42Field(&Physics42Player0View1, int *, 0xB8) != 0) {
            vectorAt30=&originalFrame.sp40;
            Physics42Call4F168View1(vectorAt30);
            call4=vectorAt30;
            call5=vectorAt30;
            __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
            globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
            Physics42Call4F1C8View1(call4, call5, globalVector8CState20);
            originalFrame.sp48 = 0;
            temp_v0_6 = Physics42Call4EDE8View1(&originalFrame.sp40, 0);
            if (temp_v0_6 >= 0x41) {
                Physics42Call4F08CView1(&originalFrame.sp40, temp_v0_6, 0x40);
            }
            originalFrame.sp48 = -0xC0;
            globalVector80State20 = globalFieldB8PointerState20 - 0x38;
            Physics42Call4F194View1(globalVector80State20, globalVector8CState20, &originalFrame.sp40);
            Physics42Call4F178View1(globalVector8CState20, globalVector80State20);
        }
        else {
            Physics42Call4F168View1(globalFieldB8PointerState20 - 0x38);
            Physics42Call4F168View1(globalFieldB8PointerState20 - 0x2C);
        }
        if (Physics42Field(&Physics42Player0View1, int *, 0x94) < -0x2300) {
            Physics42Field(&Physics42Player0View1, int *, 0x94) = -0x2300;
        }
        if ((Physics42Field(&Physics42Player0View1, int *, 0x48) == 0x3A) && (Controller88028_SpawnParticle != 0) && (Physics42Data6C640View1 & 1)) {
            originalFrame.sp60 = 0;
            originalFrame.sp64 = 0;
            originalFrame.sp68 = 0xE;
            Physics42Call4F178View1(&originalFrame.sp70, (&Physics42Player0View1 + 0x94) - 0x94);
            originalFrame.sp70 += Physics42Call363DCView1(0, 0x12C);
            originalFrame.sp74 += Physics42Call363DCView1(0, 0x12C);
            originalFrame.sp78 += Physics42Call363DCView1(0, 0x12C);
            temp_v0_7 = Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp70, &originalFrame.sp60);
            Physics42Field(temp_v0_7, signed char *, 2) = 6;
            Physics42Field(temp_v0_7, signed char *, 0xA) = 0x20;
        }
        break;
    case 38:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            Physics42Call410F8View1(&originalFrame.sp60,&Physics42Player14CView1,0);
            workWord3=Physics42Player60View1;
            workWord2=workWord3+800;
            workWord2=(unsigned int)workWord2<1825;
            if(!workWord2){
                __asm__ volatile("":::"$2");
                globalVector80=0;
                numeric5=23;
                goto rotate38;
            }
            workWord2=workWord3<801;
            if(!workWord2){
                workWord3=originalFrame.sp64;
                workWord3=-workWord3;
                __asm__("":"=r"(workWord3):"0"(workWord3));
                workWord2=workWord3*23;
                workWord3=originalFrame.sp60;
                __asm__(""::"r"(workWord3),"r"(workWord2));
                numeric5=workWord2>>8;
                goto lateral38;
            }
            workWord3=originalFrame.sp64;
            workWord3=-workWord3;
            __asm__("":"=r"(workWord3):"0"(workWord3));
            workWord2=workWord3*23;
            workWord3=originalFrame.sp60;
            __asm__(""::"r"(workWord3),"r"(workWord2));
            numeric5=workWord2>>7;
            lateral38:workWord2=workWord3*30;
            globalVector80=(void*)(workWord2>>7);
            rotate38:call4=&Physics42Player64View1;
            workWord2=Physics42Field(call4,int*,0);
            workWord3=Physics42Player60View1;
            workWord2+=(int)globalVector80;
            workWord2&=4095;
            workWord3+=numeric5;
            workWord3&=4095;
            Physics42Field(call4,int*,0)=workWord2;
            workWord2=workWord3<2049;
            Physics42Player60View1=workWord3;
            if(!workWord2){
                workWord2=workWord3-4096;
                __asm__("":"=r"(workWord2):"0"(workWord2));
                Physics42Player60View1=workWord2;
            }
            workWord2=Physics42Data6E538View1;
            workWord3=6144;
            Physics42PlayerACView1=workWord3;
            workWord2&=192;
            if(workWord2){
                workWord2=12800;
                Physics42PlayerACView1=workWord2;
            }
            workWord3=Physics42Player4CView1;
            workWord2=2;
            if(workWord3==workWord2){
                Physics42Call417FCView2(320,192);
                workWord2=Physics42PlayerB0View1<6145;
                if(workWord2)Physics42Player4CView1=0;
            }
            else Physics42Call417FCView2(320,80);
            globalFieldA4Pointer=&Physics42Player60View1;
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            workWord2=Physics42Call4EA2CView2(Physics42Field(globalFieldA4Pointer,int*,0));
            workWord2<<=5;
            workWord2=-workWord2;
            lowProduct5=(int)globalVector80*workWord2;
            workWord3=Physics42Player14CView1;
            numeric5=Physics42Player5CView1;
            workWord2=(workWord3<<4)>>6;
            numeric4=lowProduct5>>12;
            numeric4-=workWord2;
            workWord2=(numeric5<<6)>>6;
            numeric4-=workWord2;
            workWord3+=numeric4;
            Physics42Player14CView1=workWord3;
            workWord3>>=6;
            numeric5+=workWord3;
            numeric5&=4095;
            workWord2=numeric5<2049;
            Physics42Player5CView1=numeric5;
            if(!workWord2){
                workWord2=numeric5-4096;
                Physics42Player5CView1=workWord2;
            }
            workWord2=Physics42Player5CView1;
            workWord2=workWord2<-768;
            if(workWord2){
                workWord2=-768;
                Physics42Player5CView1=workWord2;
            }
            workWord2=Physics42Player5CView1;
            workWord2=workWord2<769;
            if(!workWord2){
                workWord2=768;
                Physics42Player5CView1=workWord2;
            }
            Physics42Call41848View1(numeric4,numeric5);
            goto vectorFinal50;
        }
    case 40:{
            register int numeric4 __asm__("$4");
            call5=&Physics42Player20CView2;
            __asm__("":"=r"(call5):"0"(call5));
            workWord2=Physics42Field(call5,int*,0)&64;
            call4=&originalFrame.sp68;
            if(workWord2)goto block_132;
            call5-=192;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics42Call410F8View2(call4,call5,0);
            workWord3=Physics42Player4CView1;
            workWord2=1;
            if(workWord3==workWord2){
                workWord2=512;
                workWord3=Physics42Player60View1;
                numeric4=Physics42Player144View1;
                workWord2-=workWord3;
                workWord3=numeric4<<4;
                workWord2-=workWord3;
                workWord3=workWord2&4095;
                originalFrame.sp6C=workWord3;
                workWord2=workWord3<2049;
                if(!workWord2){
                    workWord2=workWord3-4096;
                    __asm__("":"=r"(workWord2):"0"(workWord2));
                    originalFrame.sp6C=workWord2;
                }
                __asm__ volatile("":::"memory");
                workWord2=originalFrame.sp6C;
                workWord3=numeric4+1;
                Physics42Player144View1=workWord3;
                workWord3=workWord3<21;
                workWord2=(workWord2<<7)>>8;
                originalFrame.sp6C=workWord2;
                if(!workWord3){
                    __asm__ volatile("":"=r"(workWord3):"0"(workWord3));
                    Physics42Player4CView1=0;
                }
            }
            raw21_temp_s1_4 = (int) (originalFrame.sp68 * 0x14) >> 7;
            Physics42Field(&Physics42Player0View4, int *, 0x64) = (int) ((Physics42Field(&Physics42Player0View4, int *, 0x64) + raw21_temp_s1_4) & 0xFFF);
            raw21_temp_v1_6 = (Physics42Field(&Physics42Player0View4, int *, 0x60) + ((int) (originalFrame.sp6C * -0xF) >> 7)) & 0xFFF;
            Physics42Field(&Physics42Player0View4, int *, 0x60) = raw21_temp_v1_6;
            if (raw21_temp_v1_6 >= 0x801) {
                Physics42Field(&Physics42Player0View4, int *, 0x60) = (int) (raw21_temp_v1_6 - 0x1000);
            }
            if (Physics42Field(&Physics42Player0View4, int *, 0x60) < -0x320) {
                Physics42Field(&Physics42Player0View4, int *, 0x60) = -0x320;
            }
            if (Physics42Field(&Physics42Player0View4, int *, 0x60) >= 0x321) {
                Physics42Field(&Physics42Player0View4, int *, 0x60) = 0x320;
            }
            if ((*Physics42Data6C570View2 & 0x40) || (Physics42Field(&Physics42Player0View4, int *, 0x4C) == 1)) {
                Physics42Field(&Physics42Player0View4, int *, 0xAC) = 0xE00;
            }
            else {
                Physics42Field(&Physics42Player0View4, int *, 0xAC) = 0;
            }
            if (Physics42Field(&Physics42Player0View4, int *, 0x4C) == 2) {
                Physics42Call417FCView4(0xC0, 0xC0);
                if (Physics42Field(&Physics42Player0View4, int *, 0xB0) < 0xE01) {
                    Physics42Field(&Physics42Player0View4, int *, 0x4C) = 0;
                }
            }
            else {
                Physics42Call417FCView4(0xC0, 0x30);
            }
            raw21_temp_s0_7 = &Physics42Player0View4 + 0x60;
            raw21_temp_a0_5 = (((int) (raw21_temp_s1_4 * -(Physics42Call4EA2CView4(Physics42Field(&Physics42Player0View4, int *, 0x60)) << 5)) >> 0xC) - ((int) (Physics42Field(&Physics42Player0View4, int *, 0x14C) * 0x10) >> 6)) - ((int) (Physics42Field(&Physics42Player0View4, int *, 0x5C) << 6) >> 6);
            raw21_temp_v1_7 = Physics42Field(&Physics42Player0View4, int *, 0x14C) + raw21_temp_a0_5;
            Physics42Field(&Physics42Player0View4, int *, 0x14C) = raw21_temp_v1_7;
            raw21_temp_a1_2 = (Physics42Field(&Physics42Player0View4, int *, 0x5C) + (raw21_temp_v1_7 >> 6)) & 0xFFF;
            Physics42Field(&Physics42Player0View4, int *, 0x5C) = raw21_temp_a1_2;
            if (raw21_temp_a1_2 >= 0x801) {
                Physics42Field(&Physics42Player0View4, int *, 0x5C) = (int) (raw21_temp_a1_2 - 0x1000);
            }
            if (Physics42Field(&Physics42Player0View4, int *, 0x5C) < -0x300) {
                Physics42Field(&Physics42Player0View4, int *, 0x5C) = -0x300;
            }
            if (Physics42Field(&Physics42Player0View4, int *, 0x5C) >= 0x301) {
                Physics42Field(&Physics42Player0View4, int *, 0x5C) = 0x300;
            }
            Physics42Call41848View2(raw21_temp_a0_5, raw21_temp_a1_2);
            Physics42Call4F178View5(raw21_temp_s0_7 + 0x2C, raw21_temp_s0_7 + 0x20);
            workWord2=Physics42CallRandView2()&31;
            if(workWord2)goto block_130;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            particleCall3=Physics21_SpawnParticle;
            call4=(void*)1;
            if(!particleCall3)goto block_130;
            call5=(void*)44;
            call6=&originalFrame.sp80;
            particleArg7=0;
            __asm__("":"=r"(particleArg7):"0"(particleArg7));
            workWord2=544;
            originalFrame.sp80=workWord2;
            workWord2=64;
            originalFrame.sp84=0;
            __asm__ volatile(""::"i"(0x8008A428):"memory");
            originalFrame.sp88=workWord2;
            goto block_129;
        }
    case 41:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            int product41;
            raw21_temp_s1_5 = &Physics42Player0View4 + 0x20C;
            if (!(Physics42Field(&Physics42Player0View4, int *, 0x20C) & 0x40)) {
                if (Physics42Data6E044View4 != 7) {
                    Physics42Call410F8View2(&originalFrame.sp70, raw21_temp_s1_5 - 0xC0, 0);
                    workWord3=originalFrame.sp70;
                    numeric4=originalFrame.sp74;
                    workWord2=workWord3*5;
                    workWord2<<=2;
                    raw21_temp_s0_8=workWord2>>7;
                    workWord2=numeric4<<4;
                    numeric4-=workWord2;
                    numeric4>>=7;
                    workWord3=Physics42Player64View1;
                    workWord2=Physics42Player60View1;
                    workWord3+=raw21_temp_s0_8;
                    workWord3&=4095;
                    workWord2+=numeric4;
                    Physics42Player64View1=workWord3;
                    workWord3=workWord2&4095;
                    workWord2=workWord3<2049;
                    Physics42Player60View1=workWord3;
                    if(!workWord2){
                        workWord2=workWord3-4096;
                        __asm__("":"=r"(workWord2):"0"(workWord2));
                        Physics42Player60View1=workWord2;
                    }
                    if (Physics42Field(&Physics42Player0View4, int *, 0x60) < -0x320) {
                        Physics42Field(&Physics42Player0View4, int *, 0x60) = -0x320;
                    }
                    if (Physics42Field(&Physics42Player0View4, int *, 0x60) >= 0x321) {
                        Physics42Field(&Physics42Player0View4, int *, 0x60) = 0x320;
                    }
                    workWord2=Physics42Call4EA2CView4(Physics42Player60View1);
                    workWord2<<=5;
                    workWord2=-workWord2;
                    product41=raw21_temp_s0_8*workWord2;
                    workWord3=Physics42Field(raw21_temp_s1_5,int*,-192);
                    numeric5=Physics42Player5CView1;
                    workWord2=(workWord3<<4)>>6;
                    numeric4=product41>>12;
                    numeric4-=workWord2;
                    workWord2=(numeric5<<6)>>6;
                    numeric4-=workWord2;
                    workWord3+=numeric4;
                    Physics42Field(raw21_temp_s1_5,int*,-192)=workWord3;
                    workWord3>>=6;
                    numeric5+=workWord3;
                    numeric5&=4095;
                    workWord2=numeric5<2049;
                    Physics42Player5CView1=numeric5;
                    if(!workWord2){
                        workWord2=numeric5-4096;
                        __asm__("":"=r"(workWord2):"0"(workWord2));
                        Physics42Player5CView1=workWord2;
                    }
                    if (Physics42Field(&Physics42Player0View4, int *, 0x5C) < -0x300) {
                        Physics42Field(&Physics42Player0View4, int *, 0x5C) = -0x300;
                    }
                    if (Physics42Field(&Physics42Player0View4, int *, 0x5C) >= 0x301) {
                        Physics42Field(&Physics42Player0View4, int *, 0x5C) = 0x300;
                    }
                }
                raw21_temp_s0_9 = &Physics42Player0View4 + 0x80;
                Physics42Call4F168View4(raw21_temp_s0_9);
                Physics42Call4F168View4(raw21_temp_s0_9 + 0xC);
                workWord2=Physics42CallRandView2()&31;
                if(workWord2)goto block_130;
                __asm__("":"=r"(workWord2):"0"(workWord2));
                particleCall3=Physics21_SpawnParticle;
                call4=(void*)1;
                if(!particleCall3)goto block_130;
                call5=(void*)44;
                call6=&originalFrame.sp78;
                particleArg7=0;
                __asm__("":"=r"(particleArg7):"0"(particleArg7));
                workWord2=544;
                originalFrame.sp78=workWord2;
                workWord2=64;
                originalFrame.sp7C=0;
                originalFrame.sp80=workWord2;
                block_129:particleCall3(call4,call5,call6,particleArg7);
                block_130:globalPointer=&Physics42Player158View1;
                workWord2=Physics42Field(globalPointer,int*,0);
                workWord2++;
                Physics42Field(globalPointer,int*,0)=workWord2;
                return;
            }
            goto block_132;
        }
    case 42:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            call5=&Physics42Player20CView2;
            __asm__("":"=r"(call5):"0"(call5));
            workWord2=Physics42Field(call5,int*,0)&64;
            call4=&originalFrame.sp78;
            if(!workWord2)goto run42;
            block_132:Physics42PlayerACView1=0;
            Physics42PlayerB0View1=0;
            return;
            run42:call5-=192;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics42Call410F8View2(call4,call5,0);
            workWord3=Physics42Player4CView1;
            workWord2=1;
            if(workWord3==workWord2){
                workWord2=512;
                workWord3=Physics42Player60View1;
                numeric5=Physics42Player144View1;
                workWord2-=workWord3;
                workWord3=numeric5<<4;
                workWord2-=workWord3;
                workWord3=workWord2&4095;
                originalFrame.sp7C=workWord3;
                workWord2=workWord3<2049;
                if(!workWord2){
                    workWord2=workWord3-4096;
                    __asm__("":"=r"(workWord2):"0"(workWord2));
                    originalFrame.sp7C=workWord2;
                }
                __asm__ volatile("":::"memory");
                numeric4=originalFrame.sp7C;
                workWord3=numeric5+1;
                Physics42Player144View1=workWord3;
                workWord3=workWord3<13;
                workWord2=numeric4*3;
                workWord2<<=5;
                workWord2>>=8;
                originalFrame.sp7C=workWord2;
                if(!workWord3){
                    __asm__ volatile("":"=r"(workWord3):"0"(workWord3));
                    Physics42Player4CView1=0;
                }
            }
            raw21_temp_s1_6 = &Physics42Player0View4 + 0x64;
            raw21_temp_s0_10 = (int) (originalFrame.sp78 * 0x14) >> 7;
            Physics42Field(&Physics42Player0View4, int *, 0x64) = (int) ((Physics42Field(&Physics42Player0View4, int *, 0x64) + raw21_temp_s0_10) & 0xFFF);
            raw21_temp_v1_13 = (Physics42Field(&Physics42Player0View4, int *, 0x60) + ((int) (originalFrame.sp7C * -0xF) >> 7)) & 0xFFF;
            Physics42Field(&Physics42Player0View4, int *, 0x60) = raw21_temp_v1_13;
            if (raw21_temp_v1_13 >= 0x801) {
                Physics42Field(&Physics42Player0View4, int *, 0x60) = (int) (raw21_temp_v1_13 - 0x1000);
            }
            if (Physics42Field(&Physics42Player0View4, int *, 0x60) < -0x320) {
                Physics42Field(&Physics42Player0View4, int *, 0x60) = -0x320;
            }
            if (Physics42Field(&Physics42Player0View4, int *, 0x60) >= 0x321) {
                Physics42Field(&Physics42Player0View4, int *, 0x60) = 0x320;
            }
            Physics42Field(&Physics42Player0View4, int *, 0xAC) = 0x1C00;
            Physics42Call417FCView4(0x240, 0x30);
            raw21_temp_a0_6 = (((int) (raw21_temp_s0_10 * -(Physics42Call4EA2CView4(Physics42Field(&Physics42Player0View4, int *, 0x60)) << 5)) >> 0xC) - ((int) (Physics42Field(&Physics42Player0View4, int *, 0x14C) * 0x10) >> 6)) - ((int) (Physics42Field(&Physics42Player0View4, int *, 0x5C) << 6) >> 6);
            raw21_temp_v1_14 = Physics42Field(&Physics42Player0View4, int *, 0x14C) + raw21_temp_a0_6;
            Physics42Field(&Physics42Player0View4, int *, 0x14C) = raw21_temp_v1_14;
            raw21_temp_a1_3 = (Physics42Field(&Physics42Player0View4, int *, 0x5C) + (raw21_temp_v1_14 >> 6)) & 0xFFF;
            Physics42Field(&Physics42Player0View4, int *, 0x5C) = raw21_temp_a1_3;
            if (raw21_temp_a1_3 >= 0x801) {
                Physics42Field(&Physics42Player0View4, int *, 0x5C) = (int) (raw21_temp_a1_3 - 0x1000);
            }
            if (Physics42Field(&Physics42Player0View4, int *, 0x5C) < -0x300) {
                Physics42Field(&Physics42Player0View4, int *, 0x5C) = -0x300;
            }
            if (Physics42Field(&Physics42Player0View4, int *, 0x5C) >= 0x301) {
                Physics42Field(&Physics42Player0View4, int *, 0x5C) = 0x300;
            }
            Physics42Call41848View2(raw21_temp_a0_6, raw21_temp_a1_3);
            Physics42Call4F178View5(raw21_temp_s1_6 + 0x28, raw21_temp_s1_6 + 0x1C);
            if ((Physics21_SpawnParticle != 0) && (Physics42Field(&Physics42Player0View4, int *, 0xB4) >= 0x7D1)) {
                originalFrame.sp90 = -0x190;
                originalFrame.sp94 = 0x40 - (Physics42CallRandView2() & 0x7F);
                originalFrame.sp98 = -0x12C;
                Physics21_SpawnParticle(1, 0x2C, &originalFrame.sp90, 0);
                return;
            }
            break;
        }
    case 43:case 44:
        globalField4CPointer=&Physics42Player4CView1;
        __asm__("":"=r"(globalField4CPointer):"0"(globalField4CPointer));
        workWord3=Physics42Field(globalField4CPointer,int*,0);
        workWord2=1;
        if(workWord3==workWord2)goto clear47Calls;
        continue43:workWord2=7;
        workWord3=Physics42Data6E044View4;
        if (workWord3 == workWord2) {
            Physics42Field(&Physics42Player0View4, int *, 0xB0) = 0;
        }
        else {
            Physics42Call40D10View3(0x980);
            raw21_var_v0_2 = Physics42Call41580View3(0x5A, 0x10);
            if (raw21_var_v0_2 < 0) {
                raw21_var_v0_2 = -raw21_var_v0_2;
            }
            if (raw21_var_v0_2 >= 0x201) {
                Physics42Field(&Physics42Player0View4, int *, 0xAC) = 0;
            }
            raw21_var_a0_2 = 0xC0;
            if (Physics42Field(&Physics42Player0View4, int *, 0xB0) >= 0xC81) {
                raw21_var_a0_2 = 0;
                raw21_var_a1_4 = 0xC0;
            }
            else {
                raw21_var_a1_4 = 0x40;
            }
            Physics42Call417FCView4(raw21_var_a0_2, raw21_var_a1_4);
        }
        raw21_temp_s0_11 = &Physics42Player0View4 + 0xB0;
        if (Physics42Field(&Physics42Player0View4, int *, 0xB0) != 0) {
            Physics42Call41848View2();
            Physics42Call41B64View3();
            Physics42Field(&Physics42Player0View4, int *, 0x94) = 0;
        }
        else {
            Physics42Call4F168View4(raw21_temp_s0_11 - 0x30);
            Physics42Call4F168View4(raw21_temp_s0_11 - 0x24);
        }
        if (Physics21_SpawnParticle != 0) {
            raw21_temp_s4 = &Physics42Player0View4 + 0x28;
            if (Physics42Field(&Physics42Player0View4, int *, 0x28) < 0) {
                if ((Physics42Field(&Physics42Player0View4, int *, 0xB0) >= 0x401) && (savedSlotIndex < 2) && (Physics42Data6C640View2 & 1)) {
                    Physics42Call4F178View5(&originalFrame.sp90, raw21_temp_s4 - 0x28);
                    originalFrame.spA4 = 0x40;
                    originalFrame.spA8 = 0;
                    originalFrame.spA0 = (int) Physics42Field(&Physics42Player0View4, int *, 0xB0) >> 5;
                    if (savedSlotIndex != 0) {
                        originalFrame.spA4 = -0x40;
                    }
                    raw21_temp_s2_3 = raw21_temp_s4 + 8;
                    Physics42Call4ED6CView3(raw21_temp_s2_3, &originalFrame.spA0, &originalFrame.spB0);
                    Physics42Call4F194View5(&originalFrame.sp90, &originalFrame.sp90, &originalFrame.spB0);
                    originalFrame.spA0 = 0;
                    originalFrame.sp98 = -Physics42Field(&Physics42Player0View4, int *, 0x28);
                    Physics42Call4ED6CView3(raw21_temp_s2_3, &originalFrame.spA0, &originalFrame.spA0);
                    Physics42Call4F110View1(&originalFrame.spA0, 3);
                    Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp90, &originalFrame.spA0);
                    if (!(Physics42CallRandView2() & 0x1F)) {
                        Physics21_SpawnParticle(1, 0x29, &originalFrame.sp90, 0);
                    }
                }
                else {
                    raw21_temp_s1_7 = &Physics42Player0View4 + 0xB0;
                    if ((Physics42Field(&Physics42Player0View4, int *, 0xB0) < 0x201) && (savedSlotIndex == 0) && !(Physics42Data6C640View2 & 7) && !(Physics42CallRandView2() & 3)) {
                        originalFrame.spC0 = 0x80;
                        __asm__("":"=r"(savedSlotIndex):"0"(savedSlotIndex));
                        originalFrame.spC4 = 0;
                        originalFrame.spC8 = 0;
                        Physics42Call4ED6CView3(raw21_temp_s1_7 - 0x80, &originalFrame.spC0, &originalFrame.spC0);
                        Physics42Call4F194View5(&originalFrame.spC0, &originalFrame.spC0, raw21_temp_s1_7 - 0xB0);
                        originalFrame.spC8 = -Physics42Field(&Physics42Player0View4, int *, 0x28);
                        Physics21_SpawnParticle(1, 0x2B, &originalFrame.spC0, (int *)1);
                    }
                }
            }
        }
        raw21_temp_a1_4 = Physics42Field(&Physics42Player0View4, int *, 0x144) - ((int) ((Physics42Field(&Physics42Player0View4, int *, 0x148) * 2) + (Physics42Field(&Physics42Player0View4, int *, 0x144) * 0x14)) >> 8);
        raw21_temp_a0_7 = Physics42Field(&Physics42Player0View4, int *, 0x148) + raw21_temp_a1_4;
        Physics42Field(&Physics42Player0View4, int *, 0x144) = raw21_temp_a1_4;
        Physics42Field(&Physics42Player0View4, int *, 0x148) = raw21_temp_a0_7;
        if (raw21_temp_a0_7 >= 0x5901) {
            Physics42Field(&Physics42Player0View4, int *, 0x148) = 0x5900;
        }
        if (Physics42Field(&Physics42Player0View4, int *, 0x148) < -0x5900) {
            Physics42Field(&Physics42Player0View4, int *, 0x148) = -0x5900;
            return;
        }
        break;
    case 47:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            workWord3=Physics42Data6E044View3;
            workWord2=7;
            if(workWord3==workWord2)goto zero47;
            Physics42Call40F48View1(&originalFrame.spB0,0);
            workWord2=originalFrame.spB0;
            numeric6=originalFrame.spB4;
            originalFrame.spD0=0;
            workWord3=(workWord2*9<<7)>>7;
            workWord2=(numeric6*3<<9)>>7;
            originalFrame.spB0=workWord3;
            workWord3=-workWord3;
            originalFrame.spB4=workWord2;
            originalFrame.spD4=workWord3;
            originalFrame.spD8=workWord2;
            workWord2=Physics42Call4EDE8View3(&originalFrame.spD0,0,numeric6);
            numeric4=originalFrame.spD8;
            workWord3=numeric4;
            if(numeric4<0){
                __asm__("":"=r"(workWord3):"0"(workWord3));
                workWord3=-workWord3;
            }
            workWord3=workWord3<workWord2;
            if(workWord3){
                workWord2=originalFrame.spD4;
                originalFrame.spD8=0;
                __asm__ volatile("":::"$4");
                numeric4=0;
                if(workWord2>0){
                    __asm__ volatile(""::"i"(0x8008AD00):"memory");
                    numeric4=1;
                }
                if(!Physics42Call43194View1(numeric4)){
                    originalFrame.spD4=0;
                }
            }
            else{
                __asm__ volatile("":::"$3");
                originalFrame.spD4=0;
                originalFrame.spD0=0;
                if(numeric4>0){
                    __asm__ volatile(""::"i"(0x8008AD28):"memory");
                    numeric4=2;
                }
                else numeric4=3;
                if(!Physics42Call43194View1(numeric4)){
                    originalFrame.spD8=0;
                }
            }
            call4=&originalFrame.spD0;
            workWord2=Physics42Call4EDE8View3(call4,1);
            Physics42PlayerACView1=workWord2;
            __asm__ volatile(""::"i"(0x8008AD58):"memory");
            goto clear47;
            zero47:Physics42PlayerACView1=0;
            clear47:globalVector80=&Physics42Player80View1;
            __asm__ volatile(""::"r"(globalVector80):"memory");
            clear47Calls:call4=&Physics42Player80View2;
            __asm__("":"=r"(call4):"0"(call4));
            Physics42Call4F168View3(call4);
            call4=&Physics42Player8CView1;
            __asm__("":"=r"(call4):"0"(call4));
            Physics42Call4F168View3(call4);
            return;
        }
    case 49:{
            register void *pointer17 __asm__("$17");
            register void *pointer18 __asm__("$18");
            register void *pointer16 __asm__("$16");
            int product49a,product49b;
            pointer17=&Physics42Player210View1;
            workWord2=Physics42Field(pointer17,int*,0)&1024;
            call6=(void*)1;
            if(!workWord2)goto noFlag49;
            __asm__("":"=r"(pointer17):"0"(pointer17));
            call4=(void*)Physics42Field(pointer17,int*,12);
            call5=(void*)Physics42Player220View1;
            __asm__ volatile("":"=r"(pointer17):"0"(pointer17),"r"(call4),"r"(call5):"memory");
            pointer17+=12;
            workWord2=Physics42Call4E880View2(call4,call5,call6);
            pointer16=&originalFrame.spE0;
            call4=pointer16;
            Physics42Player148View1=workWord2;
            Physics42Call4F178View4(call4,pointer17);
            Physics42Call4F0E8View1(pointer16,6);
            workWord2=Physics42Call4EDE8View4(pointer16,1);
            Physics42PlayerB0View2=workWord2;
            call4=(void*)128;
            goto prepare49;
            noFlag49:__asm__("":"=r"(call6):"0"(call6));
            workWord2=Physics42PlayerE4View1;
            workWord2=workWord2<11;
            if(workWord2)goto lowMode49;
            call4=(void*)Physics42PlayerCCView1;
            call5=(void*)Physics42PlayerD0View1;
            __asm__ volatile(""::"i"(0x8008AE30):"memory");
            call6=(void*)1;
            goto query49;
            lowMode49:call4=(void*)Physics42Player98View1;
            call5=call4;
            query49:workWord2=Physics42Call4E880View2(call4,call5,call6);
            Physics42Player148View1=workWord2;
            call4=(void*)128;
            prepare49:call5=(void*)192;
            __asm__ volatile(""::"r"(call5):"memory");
            pointer18=&Physics42PlayerACView2;
            workWord2=3840;
            Physics42Field(pointer18,int*,0)=workWord2;
            Physics42Call417FCView3(call4,call5);
            call4=(void*)Physics42Player148View1;
            pointer17=pointer18-44;
            workWord2=Physics42Call4EA2CView3(call4);
            workWord3=Physics42PlayerB0View2;
            product49a=workWord3*workWord2;
            call4=(void*)Physics42Player148View1;
            workWord2=product49a>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.spE0=workWord2;
            workWord2=Physics42Call4E9E4View2(call4);
            workWord3=Physics42PlayerB0View2;
            product49b=workWord3*workWord2;
            pointer16=&originalFrame.spE0;
            call4=pointer16;
            call5=pointer16;
            call6=pointer17;
            originalFrame.spE8=0;
            workWord2=product49b>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.spE4=workWord2;
            Physics42Call4F1C8View4(call4,call5,call6);
            originalFrame.spE8=0;
            call5=(void*)Physics42Call4EDE8View4(pointer16,0);
            workWord2=(int)call5<257;
            call4=pointer17;
            if(!workWord2){
                Physics42Call4F08CView4(pointer16,call5,256);
                call4=pointer17;
            }
            call5=pointer17;
            Physics42Call4F194View4(call4,call5,pointer16);
            workWord2=Physics42PlayerFCView2;
            if(workWord2)goto scalar49;
            workWord2=Physics42PlayerB8View2;
            call4=pointer18-32;
            if(!workWord2)goto vector49;
            scalar49:workWord2=Physics42PlayerA0View2;
            workWord2-=192;
            store94From2:Physics42Player94View3=workWord2;
            return;
            vector49:call5=pointer17;
            goto vectorCommit49;
        }
    case 0x32:
    case 0x33:
    case 52:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            Physics42Call40F48View1(&originalFrame.spF0,0);
            workWord2=originalFrame.spF0;
            numeric6=originalFrame.spF4;
            originalFrame.spF8=0;
            workWord3=(workWord2*9<<7)>>7;
            workWord2=(numeric6*3<<9)>>7;
            originalFrame.spF0=workWord3;
            workWord3=-workWord3;
            originalFrame.spF4=workWord2;
            originalFrame.spFC=workWord3;
            originalFrame.sp100=workWord2;
            workWord2=Physics42Call4EDE8View3(&originalFrame.spF8,0,numeric6);
            numeric4=originalFrame.sp100;
            workWord3=numeric4;
            if(numeric4<0){
                __asm__("":"=r"(workWord3):"0"(workWord3));
                workWord3=-workWord3;
            }
            workWord3=workWord3<workWord2;
            if(workWord3){
                workWord2=originalFrame.spFC;
                originalFrame.sp100=0;
                __asm__ volatile("":::"$4");
                numeric4=0;
                if(workWord2>0){
                    __asm__ volatile(""::"i"(0x8008AFF4):"memory");
                    numeric4=1;
                }
                if(!Physics42Call43194View1(numeric4)){
                    originalFrame.spFC=0;
                }
            }
            else{
                __asm__ volatile("":::"$3");
                originalFrame.spFC=0;
                originalFrame.spF8=0;
                if(numeric4>0){
                    __asm__ volatile(""::"i"(0x8008B01C):"memory");
                    numeric4=2;
                }
                else numeric4=3;
                if(!Physics42Call43194View1(numeric4)){
                    originalFrame.sp100=0;
                }
            }
            vectorAt30=&originalFrame.spF8;
            workWord2=Physics42Call4EDE8View3(vectorAt30,1);
            numeric6=1;
            __asm__("":"=r"(numeric6):"0"(numeric6));
            numeric4=originalFrame.spF0;
            numeric5=originalFrame.spF4;
            globalVector80=&Physics42PlayerACView1;
            Physics42Field(globalVector80,int*,0)=workWord2;
            workWord2=Physics42Call4E880View1(numeric4,numeric5,numeric6);
            workWord3=workWord2;
            workWord2=workWord3<2049;
            Physics42PlayerA4View1=workWord3;
            call4=globalVector80-124;
            if(!workWord2){
                workWord2=workWord3-4096;
                Physics42PlayerA4View1=workWord2;
            }
            call5=vectorAt30;
            workWord2=originalFrame.spF8;
            call6=vectorAt30;
            workWord2+=1024;
            originalFrame.spF8=workWord2;
            Physics42Call4ED6CView2(call4,call5,call6);
            call4=vectorAt30;
            call5=vectorAt30;
            __asm__("":"=r"(globalVector80):"0"(globalVector80),"r"(call4),"r"(call5));
            globalVector8CState20=globalVector80-32;
            Physics42Call4F1C8View3(call4,call5,globalVector8CState20);
            call5=(void*)Physics42Call4EDE8View3(vectorAt30,0);
            workWord2=(int)call5<385;
            if(!workWord2)Physics42Call4F08CView3(vectorAt30,call5,384);
            globalVector80-=44;
            __asm__("":"=r"(globalVector80):"0"(globalVector80));
            Physics42Call4F194View3(globalVector80,globalVector8CState20,vectorAt30);
            vectorFinal50:call4=&Physics42Player8CView1;
            call5=&Physics42Player80View2;
            __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
            Physics42Call4F178View3(call4,call5);
            return;
        }
    case 65:
        globalVector80=&Physics42Player0View2+0x80;
        Physics42Call4F168View2(globalVector80);
        Physics42Call4F168View2(globalVector80+12);
        if(Physics42Data6E044View2!=7){
            Physics42Call40D10View2(6016);
            Physics42Call416F4View2();
            Physics42Call41580View2(90,16);
        }
        workWord2=Physics42Player1BAView1;
        if(!workWord2)goto byteOne65;
        workWord2=Physics42Data6E538View1&16;
        if(workWord2)return;
        workWord2=1;
        Physics42Player1BAView1=0;
        Physics42Player1B9View1=workWord2;
        return;
        byteOne65:workWord2=1;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        Physics42Player1B9View1=workWord2;
        return;
    case 66:case 69:
        workWord3=Physics42Data6E044View2;
        workWord2=8;
        if(workWord3!=workWord2)Physics42Call40D10View2(6016);
        globalVector80=&Physics42Data6E538View1;
        workWord2=Physics42Field(globalVector80,int*,0)&12;
        if(workWord2)Physics42PlayerACView1=0;
        workWord2=Physics42Call416F4View2();
        call4=(void*)90;
        call5=(void*)16;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalFieldA4Pointer=(void*)workWord2;
        workWord2=Physics42Call41580View2(call4,call5);
        workWord3=Physics42PlayerA8View1;
        if(workWord3<0)workWord3=-workWord3;
        workWord3=workWord3<8;
        __asm__("":"=r"(workWord3):"0"(workWord3),"r"(workWord2));
        call5=(void*)workWord2;
        if(!workWord3)goto reset101;
        workWord2=Physics42Field(globalVector80,int*,0)&12;
        if(!workWord2)goto reset101;
        workWord2=Physics42Player144View1;
        workWord2++;
        Physics42Player144View1=workWord2;
        goto saved101;
        reset101:Physics42Player144View1=0;
        saved101:call4=&Physics42PlayerACView1;
        globalVector80=(void*)Physics42Field(call4,int*,0);
        if(globalFieldA4Pointer)goto collision101;
        workWord2=(int)call5;
        if((int)call5<0)workWord2=-workWord2;
        workWord2=workWord2<513;
        if(workWord2)goto pass101;
        collision101:workWord2=Physics42Player20CView1&64;
        if(workWord2)Physics42Field(call4,int*,0)=0;
        else{
            workWord3=Physics42PlayerB0View1;
            workWord2=workWord3<(int)globalVector80;
            if(workWord2)Physics42Field(call4,int*,0)=workWord3;
        }
        pass101:Physics42Call417FCView2(320,192);
        workWord2=Physics42Player101View1;
        call4=&Physics42PlayerACView1;
        Physics42Field(call4,int*,0)=(int)globalVector80;
        if(workWord2){
            Physics42Call4F168View2(call4-32);
            goto fields101;
        }
        Physics42Call41848View1(call4);
        Physics42Call41B64View2();
        fields101:call6=&Physics42PlayerFCView1;
        workWord2=Physics42Field(call6,unsigned char*,0);
        if(workWord2)goto block_303;
        workWord2=Physics42PlayerB8View1;
        call4=call6-112;
        if(workWord2)goto block_303;
        commit101:call5=call4;
        vectorCommit66:Physics42Call4F194View2(call4,call5,call6-20);
        return;
    case 67:{
            int lowProduct3Case67,lowProduct4Case67;
            Physics42Call40D10View1(0xC80);
            Physics42Call41580View1(0x28, 8);
            Physics42Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics42Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics42Call4EA2CView1(Physics42Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics42Field(&Physics42Player0View1,int*,0xB0);
            lowProduct3Case67=workWord3*workWord2;
            call4=(void*)Physics42Field(globalFieldA4Pointer,int*,0);
            workWord2=lowProduct3Case67>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp108=workWord2;
            workWord2=Physics42Call4E9E4View1(call4);
            workWord3=Physics42Field(&Physics42Player0View1,int*,0xB0);
            lowProduct4Case67=workWord3*workWord2;
            workWord2=lowProduct4Case67>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp10C=workWord2;
            Physics42Call4F1C8View1(&originalFrame.sp108, &originalFrame.sp108, globalVector8C);
            originalFrame.sp110 = 0;
            temp_v0_4 = Physics42Call4EDE8View1(&originalFrame.sp108, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics42Call4F08CView1(&originalFrame.sp108, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics42Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp108);
            Physics42Call41B64View1();
            workWord2=combinedIndex<13;
            if(!workWord2)goto subtract320_73;
            workWord2=Physics42Player4CView1;
            if(workWord2)goto subtract320_73;
            workWord2=(int)Physics42Data6C570View1;
            workWord2=Physics42Field((void*)workWord2,int*,0)&64;
            if(workWord2)goto add30_70;
            workWord2=Physics42Player144View1;
            if(workWord2)goto add30_70;
            goto subtract320_73;
        }
    case 68:{
            register void *child19 __asm__("$19");
            register int numeric5 __asm__("$5");
            int lowProduct3Case68,lowProduct4Case68;
            globalFieldA4Pointer=&Physics42Player4CView1;
            workWord2=2;
            globalPointer=(void*)Physics42Player250View1;
            call4=(void*)Physics42Field(globalFieldA4Pointer,int*,0);
            child19=Physics42Field(globalPointer,void**,0);
            numeric5=1600;
            if((int)call4==workWord2)numeric5=3200;
            Physics42Call40D10View1(numeric5,numeric5);
            Physics42Call41580View1(22,4);
            Physics42Call417FCView1(320,192);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            globalVector8C=globalFieldA4Pointer+64;
            workWord2=Physics42Call4EA2CView1(Physics42Field(globalFieldA4Pointer,int*,88));
            workWord3=Physics42PlayerB0View1;
            lowProduct3Case68=workWord3*workWord2;
            call4=(void*)Physics42Field(globalFieldA4Pointer,int*,88);
            workWord2=lowProduct3Case68>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp118=workWord2;
            workWord2=Physics42Call4E9E4View1(call4);
            workWord3=Physics42PlayerB0View1;
            lowProduct4Case68=workWord3*workWord2;
            workWord2=lowProduct4Case68>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp11C=workWord2;
            Physics42Call4F1C8View1(&originalFrame.sp118, &originalFrame.sp118, globalVector8C);
            originalFrame.sp120 = 0;
            temp_v0_4 = Physics42Call4EDE8View1(&originalFrame.sp118, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer+52;
            if (temp_v0_4 >= 0x141) {
                Physics42Call4F08CView1(&originalFrame.sp118, temp_v0_4, 0x140);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer+52;
            }
            Physics42Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp118);
            Physics42Call41B64View1();
            workWord2=Physics42Player94View2;
            workWord2-=320;
            Physics42Player94View2=workWord2;
            workWord2=workWord2<-12800;
            if(workWord2){
                workWord2=-12800;
                Physics42Field(globalFieldA4Pointer,int*,72)=workWord2;
            }
            workWord2=Physics42Field(globalFieldA4Pointer,unsigned char*,362);
            if(!workWord2)return;
            workWord2=Physics42Field(child19,int*,72);
            workWord2++;
            Physics42Field(child19,int*,72)=workWord2;
            return;
        }
    case 70:{
            int lowProduct3Case70,lowProduct4Case70;
            Physics42Call40D10View1(0xC80);
            Physics42Call41580View1(0x28, 8);
            Physics42Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics42Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics42Call4EA2CView1(Physics42Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics42Field(&Physics42Player0View1,int*,0xB0);
            lowProduct3Case70=workWord3*workWord2;
            call4=(void*)Physics42Field(globalFieldA4Pointer,int*,0);
            workWord2=lowProduct3Case70>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp128=workWord2;
            workWord2=Physics42Call4E9E4View1(call4);
            workWord3=Physics42Field(&Physics42Player0View1,int*,0xB0);
            lowProduct4Case70=workWord3*workWord2;
            workWord2=lowProduct4Case70>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp12C=workWord2;
            Physics42Call4F1C8View1(&originalFrame.sp128, &originalFrame.sp128, globalVector8C);
            originalFrame.sp130 = 0;
            temp_v0_4 = Physics42Call4EDE8View1(&originalFrame.sp128, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics42Call4F08CView1(&originalFrame.sp128, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics42Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp128);
            Physics42Call41B64View1();
            workWord2=combinedIndex<7;
            if(!workWord2)goto subtract320_73;
            workWord3=Physics42Player4CView1;
            workWord2=1;
            if(workWord3==workWord2)goto subtract320_73;
            add30_70:workWord2=Physics42Player94View2;
            workWord2+=30;
            Physics42Player94View2=workWord2;
            return;
        }
    case 71:{
            register int numeric5 __asm__("$5");
            int lowProduct3Case71,lowProduct4Case71;
            globalFieldA4Pointer=&Physics42PlayerB8View1;
            workWord2=Physics42Field(globalFieldA4Pointer,int*,0);
            if(!workWord2)goto grounded71;
            workWord2=2;
            workWord3=Physics42Player4CView1;
            numeric5=1600;
            if(workWord3==workWord2)numeric5=3200;
            Physics42Call40D10View1(numeric5,numeric5);
            Physics42Call41580View1(22,4);
            Physics42Call417FCView1(320,192);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            globalVector8C=globalFieldA4Pointer-44;
            workWord2=Physics42Call4EA2CView1(Physics42PlayerA4View1);
            __asm__ volatile(""::"r"(globalVector8C):"memory");
            workWord3=Physics42PlayerB0View1;
            lowProduct3Case71=workWord3*workWord2;
            call4=(void*)Physics42PlayerA4View1;
            workWord2=lowProduct3Case71>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp138=workWord2;
            workWord2=Physics42Call4E9E4View1(call4);
            workWord3=Physics42PlayerB0View1;
            lowProduct4Case71=workWord3*workWord2;
            workWord2=lowProduct4Case71>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp13C=workWord2;
            Physics42Call4F1C8View1(&originalFrame.sp138, &originalFrame.sp138, globalVector8C);
            originalFrame.sp140 = 0;
            temp_v0_4 = Physics42Call4EDE8View1(&originalFrame.sp138, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer-56;
            if (temp_v0_4 >= 0x141) {
                Physics42Call4F08CView1(&originalFrame.sp138, temp_v0_4, 0x140);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer-56;
            }
            Physics42Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp138);
            Physics42Call41B64View1();
            workWord2=Physics42Player94View2;
            workWord2-=320;
            Physics42Player94View2=workWord2;
            workWord2=workWord2<-12800;
            if(workWord2){
                workWord2=-12800;
                Physics42Player94View2=workWord2;
            }
            return;
        grounded71:
            workWord3=Physics42Data6E044View2;
            workWord2=8;
            if(workWord3!=workWord2)Physics42Call40D10View2(6016);
            globalVector80=&Physics42Data6E538View1;
            workWord2=Physics42Field(globalVector80,int*,0)&12;
            if(workWord2)Physics42PlayerACView1=0;
            workWord2=Physics42Call416F4View2();
            call4=(void*)90;
            call5=(void*)16;
            __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
            globalFieldA4Pointer=(void*)workWord2;
            workWord2=Physics42Call41580View2(call4,call5);
            workWord3=Physics42PlayerA8View1;
            if(workWord3<0)workWord3=-workWord3;
            workWord3=workWord3<8;
            __asm__("":"=r"(workWord3):"0"(workWord3),"r"(workWord2));
            call5=(void*)workWord2;
            if(!workWord3)goto reset71;
            workWord2=Physics42Field(globalVector80,int*,0)&12;
            if(!workWord2)goto reset71;
            workWord2=Physics42Player144View1;
            workWord2++;
            Physics42Player144View1=workWord2;
            goto saved71;
            reset71:Physics42Player144View1=0;
            saved71:call4=&Physics42PlayerACView1;
            globalVector80=(void*)Physics42Field(call4,int*,0);
            if(globalFieldA4Pointer)goto collision71;
            workWord2=(int)call5;
            if((int)call5<0)workWord2=-workWord2;
            workWord2=workWord2<513;
            if(workWord2)goto pass71;
            collision71:workWord2=Physics42Player20CView1&64;
            if(workWord2)Physics42Field(call4,int*,0)=0;
            else{
                workWord3=Physics42PlayerB0View1;
                workWord2=workWord3<(int)globalVector80;
                if(workWord2)Physics42Field(call4,int*,0)=workWord3;
            }
            pass71:Physics42Call417FCView2(320,192);
            workWord2=Physics42Player101View1;
            call4=&Physics42PlayerACView1;
            Physics42Field(call4,int*,0)=(int)globalVector80;
            if(workWord2){
                Physics42Call4F168View2(call4-32);
                goto fields71;
            }
            Physics42Call41848View1(call4);
            Physics42Call41B64View2();
            fields71:call6=&Physics42PlayerFCView1;
            workWord2=Physics42Field(call6,unsigned char*,0);
            if(workWord2)goto block_303;
            workWord2=Physics42PlayerB8View1;
            call4=call6-112;
            if(!workWord2)goto vectorInput71;
            block_303:workWord2=Physics42PlayerA0View1;
            workWord2-=320;
            Physics42Player94View2=workWord2;
            return;
            vectorInput71:call5=call4;
            vectorCommit49:Physics42Call4F194View6(call4,call5,&Physics42Player0View5+0xE8);
            return;
        }
    case 72:{
            int lowProduct3Case72,lowProduct4Case72;
            globalFieldA4Pointer=&Physics42Player4CView1;
            workWord2=Physics42Field(globalFieldA4Pointer,int*,0);
            if(workWord2)goto vector72;
            workWord2=combinedIndex<19;
            call4=globalFieldA4Pointer+64;
            if(workWord2)goto neutralVector72;
            call4=globalFieldA4Pointer+52;
            workWord3=Physics42Player8CView2;
            workWord2=workWord3*7;
            workWord3=Physics42Player90View1;
            workWord2<<=5;
            Physics42Field(globalFieldA4Pointer,int*,52)=workWord2;
            workWord2=workWord3*7;
            workWord3=Physics42Player94View2;
            workWord2<<=5;
            Physics42Player84View1=workWord2;
            workWord2=workWord3*7;
            workWord2<<=5;
            Physics42Player88View1=workWord2;
            Physics42Call4F110View2(call4,8);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            call4=globalFieldA4Pointer+64;
            neutralVector72:Physics42Call4F178View6(call4,globalFieldA4Pointer+52);
            workWord2=Physics42Player94View2;
            workWord2-=192;
            Physics42Player94View2=workWord2;
            workWord2=workWord2<-8960;
            clamp19:if(workWord2){
                workWord2=-8960;
                Physics42Player94View2=workWord2;
            }
            return;
            vector72:Physics42Call40D10View1(3200);
            Physics42Call41580View1(40,8);
            Physics42Call417FCView1(320,192);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            globalVector8C=globalFieldA4Pointer+64;
            workWord2=Physics42Call4EA2CView1(Physics42PlayerA4View1);
            __asm__ volatile(""::"r"(globalVector8C):"memory");
            workWord3=Physics42PlayerB0View1;
            lowProduct3Case72=workWord3*workWord2;
            call4=(void*)Physics42PlayerA4View1;
            workWord2=lowProduct3Case72>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp148=workWord2;
            workWord2=Physics42Call4E9E4View1(call4);
            workWord3=Physics42PlayerB0View1;
            lowProduct4Case72=workWord3*workWord2;
            workWord2=lowProduct4Case72>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp14C=workWord2;
            Physics42Call4F1C8View1(&originalFrame.sp148, &originalFrame.sp148, globalVector8C);
            originalFrame.sp150 = 0;
            temp_v0_4 = Physics42Call4EDE8View1(&originalFrame.sp148, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer+52;
            if (temp_v0_4 >= 0x281) {
                Physics42Call4F08CView1(&originalFrame.sp148, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer+52;
            }
            Physics42Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp148);
            Physics42Call41B64View1();
            if(combinedIndex<13){
                __asm__(""::"r"(combinedIndex));
                workWord2=Physics42Player94View2;
                workWord2+=30;
            }
            else{
                workWord2=Physics42Player94View2;
                workWord2-=320;
            }
            Physics42Player94View2=workWord2;
            __asm__ volatile("" ::: "memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer=&Physics42Player0View1+0x148;
                __asm__("" : "=r"(globalPointer):"0"(globalPointer));
                particleIndex=0;
                if (Physics42Field(globalPointer,int*,0) != 0) {
                    workWord2=combinedIndex*4;
                    __asm__("" : "=r"(workWord2):"0"(workWord2));
                    particleThreshold=workWord2+combinedIndex;
                    globalByteE=globalPointer-0x13A;
                    vectorAt40=&originalFrame.sp168;
                    __asm__("" : "=r"(vectorAt40):"0"(vectorAt40));
                spawnParticleLoop72:
                    if (particleThreshold < (Physics42CallRandView1() & 0xFF)) {
                        workWord2=Physics42Call363DCView1(0,0xC);
                        call4=globalByteE+0x22;
                        workWord3=*globalByteE;
                        __asm__("" : "=r"(workWord3):"0"(workWord3));
                        call5=vectorAt40;
                        __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
                        workWord3+=0x80;
                        __asm__("" : "=r"(workWord3):"0"(workWord3));
                        workWord3+=workWord2;
                        __asm__("" : "=r"(workWord3):"0"(workWord3));
                        workWord3=(workWord3&0xFF)*2;
                        signedTableWord = *(short*)(&Physics42Data65920View1 + workWord3);
                        call6=vectorAt40;
                        originalFrame.sp158 = (int) (signedTableWord * 5) >> 0xA;
                        workWord3=*(short*)(&Physics42Data658A0View1 + workWord3);
                        __asm__ volatile("" : "=r"(workWord3):"0"(workWord3):"memory");
                        originalFrame.sp160 = 0xE;
                        originalFrame.sp168 = -0x12C;
                        originalFrame.sp16C = 0;
                        originalFrame.sp170 = -0xC8;
                        __asm__ volatile("" ::: "memory");
                        originalFrame.sp15C = (workWord3 * 5) >> 0xA;
                        Physics42Call4ED6CView1(call4, call5, call6, signedTableWord);
                        originalFrame.sp168 += Physics42Call363DCView1(0, 0x50);
                        originalFrame.sp16C += Physics42Call363DCView1(0, 0x50);
                        originalFrame.sp170 += Physics42Call363DCView1(0, 0x50);
                        Physics42Call4F194View1(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 = Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp158);
                        workWord2=(int)temp_v0_5;
                        workWord3=8;
                        Physics42Field((void*)workWord2,signed char*,2)=workWord3;
                        workWord3=32;
                        Physics42Field((void*)workWord2,signed char*,10)=workWord3;
                    }
                    particleIndex += 1;
                    if (particleIndex < 2) {
                        goto spawnParticleLoop72;
                    }
                }
            }
            break;
        }
    case 73:{
            int lowProduct3Case73,lowProduct4Case73;
            Physics42Call40D10View1(0x640);
            Physics42Call41580View1(0x28, 8);
            Physics42Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics42Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics42Call4EA2CView1(Physics42Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics42Field(&Physics42Player0View1,int*,0xB0);
            lowProduct3Case73=workWord3*workWord2;
            call4=(void*)Physics42Field(globalFieldA4Pointer,int*,0);
            workWord2=lowProduct3Case73>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp158=workWord2;
            workWord2=Physics42Call4E9E4View1(call4);
            workWord3=Physics42Field(&Physics42Player0View1,int*,0xB0);
            lowProduct4Case73=workWord3*workWord2;
            workWord2=lowProduct4Case73>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp15C=workWord2;
            Physics42Call4F1C8View1(&originalFrame.sp158, &originalFrame.sp158, globalVector8C);
            originalFrame.sp160 = 0;
            temp_v0_4 = Physics42Call4EDE8View1(&originalFrame.sp158, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics42Call4F08CView1(&originalFrame.sp158, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics42Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp158);
            Physics42Call41B64View1();
            workWord2=combinedIndex<19;
            if(!workWord2)goto subtract320_73;
            workWord3=Physics42Player4CView1;
            workWord2=1;
            if(workWord3==workWord2)goto subtract320_73;
            workWord2=Physics42Player94View2;
            workWord2+=100;
            Physics42Player94View2=workWord2;
            return;
            subtract320_73:globalPointer=&Physics42Player94View2;
            workWord2=Physics42Field(globalPointer,int*,0);
            workWord2-=320;
            Physics42Field(globalPointer,int*,0)=workWord2;
            return;
        }
    case 74:
        globalVector80=&Physics42Player0View2+0xB8;
        workWord2=Physics42Field(globalVector80,int*,0);
        if(!workWord2)goto zero105;
        vectorAt30=&originalFrame.sp178;
        Physics42Call4F168View2(vectorAt30);
        call4=vectorAt30;
        call5=vectorAt30;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalVector8CState20=globalVector80-44;
        Physics42Call4F1C8View2(call4,call5,globalVector8CState20);
        originalFrame.sp180=0;
        call5=(void*)Physics42Call4EDE8View2(vectorAt30,0);
        workWord2=(int)call5<65;
        if(!workWord2)Physics42Call4F08CView2(vectorAt30,call5,64);
        originalFrame.sp180=-320;
        globalVector80-=56;
        Physics42Call4F194View2(globalVector80,globalVector8CState20,vectorAt30);
        Physics42Call4F178View2(globalVector8CState20,globalVector80);
        goto clamp74;
        zero105:Physics42Call4F168View2(globalVector80-56);
        Physics42Call4F168View2(globalVector80-44);
        goto clamp74;
        clamp74:globalPointer=&Physics42Player94View2;
        workWord2=Physics42Field(globalPointer,int*,0);
        workWord2=workWord2<-12800;
        if(workWord2){
            workWord2=-12800;
            Physics42Field(globalPointer,int*,0)=workWord2;
        }
        return;
    case 75:case 76:case 77:{
            register int numeric5 __asm__("$5");
            int product75;
            call4=&Physics42Player8CView2;
            __asm__("":"=r"(call4):"0"(call4));
            workWord3=Physics42Field(call4,int*,-64);
            __asm__ volatile(""::"r"(workWord3):"memory");
            numeric5=1;
            __asm__("":"=r"(numeric5):"0"(numeric5));
            Physics42Field(call4,int*,0)=0;
            Physics42Field(call4,int*,4)=0;
            if(workWord3==numeric5)goto descend75;
            workWord2=workWord3<2;
            if(!workWord2)goto larger75;
            if(!workWord3)goto zero75;
            return;
            larger75:workWord2=2;
            if(workWord3==workWord2)goto zeroVelocity75;
            return;
        zero75:
            workWord2=Physics42Player144View1;
            workWord2++;
            Physics42Player144View1=workWord2;
            workWord2=workWord2<42;
            if(workWord2){
                workWord2=Physics42Player94View2;
                workWord2-=32;
                Physics42Player94View2=workWord2;
                return;
            }
            Physics42Field(call4,int*,-64)=numeric5;
            __asm__ volatile("":::"$2","memory");
            Physics42Player54View1=0;
            return;
            descend75:workWord2=Physics42Field(call4,int*,8);
            workWord2-=2048;
            Physics42Field(call4,int*,8)=workWord2;
            workWord2=workWord2<-12800;
            if(workWord2)Physics42Field(call4,int*,8)=-12800;
            workWord2=Physics42PlayerB8View1;
            if(workWord2)return;
            workWord2=Physics42Player54View1;
            workWord2=workWord2<9;
            if(workWord2)return;
            workWord2=Physics42PlayerE4View1;
            workWord2=workWord2<23;
            if(!workWord2)return;
            workWord3=Physics42PlayerD4View1;
            workWord2=Physics42Field(call4,int*,8);
            product75=workWord3*workWord2;
            if(product75>=0)return;
            workWord2=4096;
            particleCall3=Physics42_SpawnParticle;
            __asm__ volatile(""::"r"(particleCall3):"memory");
            Physics42Data6E1D4View1=workWord2;
            workWord2=30;
            Physics42Data6E1D8View1=workWord2;
            workWord2=2;
            Physics42Field(call4,int*,-64)=workWord2;
            Physics42Player54View1=0;
            call4=(void*)8;
            if(particleCall3){
                call5=(void*)33;
                call6=0;
                particleArg7=2;
                particleCall3(call4,call5,call6,particleArg7);
                Physics42_SpawnParticle(8,33,0,3);
            }
            call5=0;
            __asm__ volatile(""::"r"(call5):"memory");
            globalPointer=Physics42Data6C654View1;
            __asm__ volatile(""::"r"(globalPointer):"memory");
            workWord2=120;
            Physics42Data6E530View1=workWord2;
            workWord2=15;
            Physics42Data6E52CView1=workWord2;
            call4=(void*)Physics42Field(globalPointer,unsigned char*,20);
            Physics42DataPlaySoundView1(call4,call5,0);
            return;
            zeroVelocity75:Physics42Player94View2=0;
            return;
        }
    }
}
#undef Physics42Field


/* AI generated; not human reviewed. SCUS-94467 8008C0C4..8008C964.
 * Verified11 standalone case47/table,23 shared flag and43 clamp/case31 paths
 * combined only against original42 instructions. All original words, strict
 * complete TU and every retail hash required; units/helpers/cadence unresolved.
 * Original42 independent1D/13 blocks at8008C17C..8008C1A8 target query/helper
 * tails separately; source order and every internal jump target agree.
 * Standalone stack18 vector andS1 mask02000000 retain original case47 numeric
 * chain. Byte offsets28+70,44-14/44-44 and table8006D048+14 are not semantics.
 * Empty constraints emit no instructions; compiled equality is not runtime parity.
 */
extern Spyro Callback42Player __asm__("D_80070328");
int Callback42Call80037058(int x, int y) __asm__("func_80037058");
void Callback42Call80041930(void) __asm__("func_80041930");
void Callback42Call80041AE8(void) __asm__("func_80041AE8");
void Callback42Call80041C20(void) __asm__("func_80041C20");
void Callback42Call80042A44(void) __asm__("func_80042A44");
void Callback42Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback42Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38,D_8006C648;
extern int D_80071924;
extern int** Callback42Table __asm__("D_8006D048+0x14");
int Callback42Call80055E84(Moby*) __asm__("func_80055E84");
void Callback42Call8004ED6C(void*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
void Callback42Call8001BA30(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int Callback42Call80019138(Vector3D*,int,int,int,int,Moby*) __asm__("func_80019138");
int Callback42Call8001830C(Vector3D*,Vector3D*,int,int,Moby*) __asm__("func_8001830C");
extern int Callback42Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback42Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback42Values[] __asm__("D_8006FCF0");
void Callback42Call80049590(void) __asm__("func_80049590");
int Callback42Call8003BF6C(int,int) __asm__("func_8003BF6C");
extern int Callback42FlagWord __asm__("D_80070328+0x4C");
extern int D_8006C648;
int Callback42Length(Vector3D*,int) __asm__("func_8004EDE8");
void func_level_42_8008C0C4(void) {
    Vector3D localVector;
    register int computedValue __asm__("$4");
    register int clampedValue __asm__("$4");
    register int numerator __asm__("$2");
    register int belowLimit __asm__("$2");
    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    int descriptorResult;
    int flagOffset;

    register int positionDelta __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback42Player.animationState) {
    case 0x14:
    case 0x41:
        if(func_800438F4()==0)func_80043728();
        Callback42Call80041C20();
        Callback42Player.unk9a=0;
        Callback42Call80042A44();
        goto clearSharedValue;
    default:
        return;
    case 0x44:
    case 0x4A:
        Callback42Call80041C20();
        Callback42Call80042A44();
        goto clearSharedValue;
    case 0x42:
    case 0x45:
        func_800438F4();
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80041930();
        goto queryC00;
    case 0x1D:
        Callback42Call80041C20();
        Callback42Call80042A44();
        goto queryC00;
    case 0x13:
        Callback42Call80041C20();
        Callback42Call80042A44();
        goto call41930;
    case 0x1C:
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80041930();
        if(Callback42Player.unk7a[3].z < 0 && Callback42Player.animationStateFrames >= 4) {
setFirstFlag:
            Callback42Player.unk5=1;
        }
        goto clearSharedValue;
    case 0x26:
    case 0x28:
    case 0x29:
        Callback42Call80041C20();
        Callback42Call80042A44();
        descriptor=&Callback42Player.unk22[2];
        if (Callback42Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback42Values + valueOffset);
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
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80049590();
        descriptor=&Callback42Player.unk22[2];
        if (Callback42Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback42Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback42Player.unk22[2];
        }
        if (Callback42Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback42Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback42Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback42Flags[flagOffset] = Callback42Flags[flagOffset] | 0x10;
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80041AE8();
        if ((unsigned char) Callback42Player.unk10[4] != 0) {
            computedValue = -Callback42Player.unk9ha[4] - Callback42Call80037058(Callback42Player.position.x, Callback42Player.position.y);
            positionValue = Callback42Player.unk4a - computedValue;
            Callback42Player.unk4[0] = computedValue;
            positionDelta = (int) Callback42Player.union144.a.unk13cc >> 6;
            positionValue -= positionDelta;
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            Callback42Player.position.z=positionValue;
            return;
        }
        break;
    case 0x2F:
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80041930();
        func_80042F64();
        goto clearSharedValue;
    case 0x31:
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80043A38(0xC00);
        if (func_80040954(Callback42Player.unk11[2]) == 0xA) {
            Callback42Player.union144.a.unk13cb = 0;
        } else {
            Callback42Player.union144.a.unk13cb += D_8006C648;
        }
        Callback42Player.unk4[0] = 0;
        if (Callback42Call8003BF6C((int) D_8006C654->unk32, Callback42Player.unk22[2]) == 0) {
            Callback42Player.unk22[2] = PlaySound((int) D_8006C654->unk32, 0, 4);
            Callback42Player.unk22[3] = (int) D_8006C654->unk32;
            return;
        }
        break;
    case 0x32:
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80041930();
        func_80042F64();
        numerator=(int)((unsigned int)Callback42Player.unk7a[3].z << 2);
        Callback42Player.unk4[0] = 0;
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
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80041930();
        func_80042F64();
        Callback42Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)(((unsigned int)Callback42Length((Vector3D *) ((unsigned char*)Callback42Player.unk4 + 0x70), 0) << 2) + 0x300U) / 1536;
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
    case 0x3A:
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Player.cheatColour.a=255;
        Callback42Player.unk4[0]=0;
        Callback42Player.cheatColour.b=32;
        Callback42Player.cheatColour.g=32;
        Callback42Player.cheatColour.r=32;
        return;
    case 0x43:
    case 0x46:
    case 0x49:
        Callback42Call80041C20();
        Callback42Call80042A44();
        Callback42Call80041930();
        if(Callback42Player.unk7a[3].z < 0 && Callback42Player.animationStateFrames >= 4)goto setFirstFlag;
        {register int* flagWord __asm__("$3")=&Callback42FlagWord;
        __asm__("" : "=r"(flagWord) : "0"(flagWord));
        if(*flagWord==0 && !(Callback42Word8006E538 & 0x40) && Callback42Player.union144.a.unk13cb==0)
            *flagWord=2;}
        goto clearSharedValue;
    case 0x47: {
        register int progress __asm__("$4");
        register int value __asm__("$2");
        register int* sourceBase __asm__("$16");
        register int flags __asm__("$17");
        if(Callback42Player.ticksSinceLastSurfaceTouch) {
            Callback42Call80041C20();
            Callback42Call80042A44();
        } else {
            func_800438F4();
            Callback42Call80041C20();
            Callback42Call80042A44();
            Callback42Call80041930();
            Callback42Call80043A38(0xC00);
        }
        progress=Callback42Call80055E84(Callback42Player.critterMobyPtr);
        if(Callback42Player.critterMobyPtr->animationState.id==6 && (unsigned int)(progress-2)<6) {
            if(progress<6)value=(progress<<10)/6;
            else value=0x400;
            localVector.x=value;
            __asm__ volatile("" : : : "memory");
            sourceBase=&Callback42Player.unk4a;
            localVector.y=0;
            localVector.z=0x200-*sourceBase;
            Callback42Call8004ED6C((unsigned char*)sourceBase-0x14,(&localVector),(&localVector));
            {register Vector3D* argument0 __asm__("$4")=(&localVector);
            register Vector3D* argument1 __asm__("$5")=(&localVector);
            __asm__("" : "=r"(argument0), "=r"(argument1) : "0"(argument0), "1"(argument1));
            sourceBase=(int*)((unsigned char*)sourceBase-0x44);
            func_8004F194(argument0,argument1,(Vector3D*)sourceBase);}
            flags=0x02000000;
            Callback42Call8001BA30((&localVector),0x200,0,0,flags,Callback42Player.critterMobyPtr);
            if((Callback42Call80019138((&localVector),0x200,0,0,flags,Callback42Player.critterMobyPtr)!=0 ||
                Callback42Call8001830C((Vector3D*)sourceBase,(&localVector),0,0x02000000,Callback42Player.critterMobyPtr)!=0)) {
                register int* selector __asm__("$16")=&D_80071924;
                if(func_80040954(*selector)==3) {
                    register int index __asm__("$2")=*selector;
                    register int** table __asm__("$3")=Callback42Table;
                    register int* entry __asm__("$3");
                    index &= 63;
                    entry=table[index];
                    entry[1] |= flags;
                }
            }
        }
        goto clearSharedValue;
    }
    case 0x4B:
    case 0x4C:
    case 0x4D:
        Callback42Call80041C20();
        Callback42Call80042A44();
        if(Callback42Player.unk5==1)func_800494A8();
        goto clearSharedValue;
    case 0x48:
        Callback42Call80041C20();
        Callback42Call80042A44();
        if(Callback42Player.unk5!=0)goto call41930;
queryC00:
        Callback42Call80043A38(0xC00);
        goto clearSharedValue;
call41930:
        Callback42Call80041930();
clearSharedValue:
        Callback42Player.unk4[0]=0;
        return;
    }
}


#define LEVEL_ID 42
#define PlaySpyroSounds_level_42 func_level_42_8008C968
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_42_8008CB78(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x13:
    case 0x1c:
    case 0x43:
    case 0x44:
    case 0x46:
    case 0x49:
    case 0x4b:
    case 0x4c:
    case 0x4d:
        func_80043ABC(0);
        break;
    case 0x2f:
    case 0x32:
    case 0x33:
    case 0x34:
        func_80043F3C(&spyro.unk9h);
        break;
    case 0x47:
    case 0x48:
        {
            register int* state __asm__("$4") = (int*)((char*)&spyro + 0xB8);
            __asm__("" : "=r"(state) : "0"(state));
            if (*state) func_80043ABC(0);
            else func_80043ABC(&spyro.unk9e);
        }
        break;
    case 0x14:
    case 0x1d:
    case 0x2b:
    case 0x2c:
    case 0x31:
    case 0x3a:
    case 0x41:
    case 0x42:
    case 0x45:
    case 0x4a:
        func_80043ABC(&spyro.unk9e);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008CC20.
 * Verified11 water/character,37 numeric1D,23 vector/ladder,21 entry26,
 * 32 slide. Original42 shared hurt call at1C and independent entry26 retained.
 * Numeric offsets are bytes. Stack10/20/30 water and40 jump preserved.
 * Word60 wrap800/801/FFF gives0/-7FF/-1; signed table-2/0/2 gives-1/0/1.
 * Each invocation preserves every code/internal jump/owned table word;
 * strict complete TU and every original hash required. Helper meanings,
 * physical units, audio, cadence and live parity remain open.
 */
extern short D_800658A0[];
extern short D_80065920[];
extern int Raw42Animation __asm__("D_80070328+0x48");
extern unsigned char Raw42Union[] __asm__("D_80070328+0x144");
extern unsigned char Raw42Movement[] __asm__("D_80070328+0x50");
extern int Raw42X __asm__("D_80070328+0x8C");
extern int Raw42Word __asm__("D_80070328+0x50");
int Transition42_func_8004E880(int,int,int) __asm__("func_8004E880");
void Transition42_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");
extern Spyro Transition42_D_80070328 __asm__("D_80070328");
int Transition42_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition42_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition42_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition42RawUnion[] __asm__("D_80070328+0x144");
extern int Transition42RawMovement __asm__("D_80070328+0x50");
extern void (*Call42Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw42State[] __asm__("D_80070328+0x50");

extern int D_80071934;
int Call42A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw42NegativeWord __asm__("D_80070328+0x28");
int Transition42_func_8003636C(int,int) __asm__("func_8003636C");
void Transition42_func_800441F0(void) __asm__("func_800441F0");
void Transition42_func_80043A38(int) __asm__("func_80043A38");
int Transition42_func_8004E880(int,int,int) __asm__("func_8004E880");
void func_level_42_8008CC20(int arg0){
    struct {Vector3D first; int gap1; Vector3D second; int gap2; Vector3D third; int gap3; Vector3D fourth;} vectors;
    register int negativeWord __asm__("$3");
    int firstResult,secondResult,firstWrappedWord,secondWrappedWord,firstParticleKind,secondParticleKind,firstParticleSubtype,secondParticleSubtype;
    register Vector3D* destination __asm__("$4");

    int lengthResult;


    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* savedBase __asm__("$3");
    register unsigned char* privateData __asm__("$16");
    register unsigned char* stateBase __asm__("$17");
    int maskedValue;
    register int tableIndex __asm__("$2");
    register int tableValue __asm__("$3");
    register Vector3D *damageSource __asm__("$16");
    register Vector3D *damageDestination __asm__("$16");
    Vector3D *firstJumpSource;
    Vector3D *secondJumpSource;
    enum MovementState nextSubstate;
    register int comparisonKind __asm__("$2");
    register int previousValue __asm__("$2");
    register int firstAnimation __asm__("$3");
    register unsigned char* soundTable __asm__("$3");
    register unsigned char* unionBase __asm__("$5");
    register unsigned char* movement __asm__("$3");
    register unsigned char* initialMovement __asm__("$5");
    register void *jumpPrivate __asm__("$18");
    register void *damagePrivate __asm__("$18");
    register Vector3D* jumpVector __asm__("$16");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");
    switch(arg0){
    case 0x14:
        Transition42_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.unk5 = 0;
        Transition42_func_800441F0();
        Transition42_D_80070328.grounded = 1;
        Transition42_D_80070328.union144.a.unk13cb = Transition42_func_8003636C(1, 3);
        Transition42_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        stateBase=(unsigned char*)&Transition42RawMovement;
        privateData = Transition42_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition42_D_80070328.unk5 = 0;
        Transition42_D_80070328.grounded = 0;
        Transition42_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition42_D_80070328.m_WhirlwindPointer;
        yawValue=Transition42_D_80070328.rotation.yaw;
        positionZ=Transition42_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition42_D_80070328.union144.a.unk13cc=yawValue;
        Transition42_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition42_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition42_D_80070328.union144.a.unk13ce.z=heightValue;
        __asm__ volatile("" : : : "memory");
        heightValue = ((int) (heightValue << 0xA) >> 0xA) + 0x400;
        __asm__("" : "=r"(heightValue) : "0"(heightValue));
        Transition42_D_80070328.union144.a.unk13ce.y = heightValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
        Transition42_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition42_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition42_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition42_D_80070328.unk13e[0] = (int) Transition42_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition42_D_80070328.unk20a = 0;
        Transition42_D_80070328.critterMobyPtr = 0;
        Transition42_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x1D: {
        register int oldState __asm__("$4")=Transition42RawMovement;
        register int first __asm__("$3")=Transition42_D_80070328.unk17e.x;
        register int second __asm__("$2");
        register int third __asm__("$3");
        __asm__("" : "=r"(oldState),"=r"(first) : "0"(oldState),"1"(first) : "memory");
        second=7;
        __asm__("" : "=r"(second) : "0"(second));
        Transition42RawMovement=second;
        __asm__ volatile("" : : : "memory");
        second=Transition42_D_80070328.unk17e.y;
        __asm__ volatile("" : "=r"(second) : "0"(second) : "memory");
        Transition42_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(first) : "0"(first) : "memory");
        first<<=6;
        __asm__("" : "=r"(first) : "0"(first));
        Transition42_D_80070328.unk7a[2].x=first;
        __asm__ volatile("" : : : "memory");
        third=Transition42_D_80070328.unk17e.z;
        second<<=6;
        Transition42_D_80070328.union144.a.unk13cb=oldState;
        Transition42_D_80070328.unk7a[2].y=second;
        second=third<<6;
        if(third==0)second=Transition42_D_80070328.unk7a[3].z;
        Transition42_D_80070328.unk7a[2].z=second;
        Transition42_func_80043A38(0xC00);
        Transition42_D_80070328.grounded=1;
        Transition42_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        soundSelector=D_8006C654->spyroHurt;
        soundZero=0;
        goto sharedHurtSound;
        goto clearPointers;
    }

    case 0x1C:
        savedBase = Transition42RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Transition42RawMovement;
        Transition42RawMovement = MOVEMENT_STATE_HURT;
        Transition42_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8(sourceC, 0);
        Transition42_D_80070328.unk7a[2].z = 0xDC0;
        Transition42_D_80070328.grounded = 0;
        Transition42_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        soundZero=0;
        if (Transition42_D_80070328.damageFlags & 0x200) {
            Transition42_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition42_D_80070328.union144.a.unk13cc = 1;
            soundSelector=D_8006C654->lavaBurn;
sharedHurtSound:
            PlaySound(soundSelector,(Moby*)soundZero,0);
        }
        goto clearPointers;
    case 0x3A:
        Transition42_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition42_D_80070328.unk5 = 0;
        Transition42_func_80043A38(0xC00);
        Transition42_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition42_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x26:
        Transition42_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        if (Transition42_D_80070328.animationState == 0x2A) {
            Transition42_D_80070328.unk5 = 2;
        }
        Transition42_func_8004F168((Vector3D *) ((unsigned char*)&Transition42_D_80070328.movementState + 0xFC));
        Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition42_D_80070328.movementState + 0x48), 0);
        Transition42_D_80070328.grounded = 1;
        Transition42_D_80070328.unk4a = 0x280;
        return;
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition42_D_80070328.movementState - 0xB) >= 2U) && (Transition42_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition42_D_80070328.movementState - 0x50));
                if ((Transition42_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw42NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition42_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call42A358(&vectors.first, 0x800);
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
            firstWrappedWord = Transition42_D_80070328.rotation.pitch & 0xFFF;
            Transition42_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition42_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition42_D_80070328.rotation.pitch > 0) {
                Transition42_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition42_D_80070328.unk5 = 1;
            }
            Transition42_func_8004F168((Vector3D *) ((unsigned char*)&Transition42_D_80070328.rotation.pitch + 0xEC));
            Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition42_D_80070328.rotation.pitch + 0x38), 0);
            Transition42_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition42_D_80070328.animationState == 0x2A) {
            Transition42_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition42_D_80070328.union144.a.unk13da = 0;
        }
        Transition42_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition42_D_80070328.unk20a = 0;
        Transition42_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw42State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw42NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition42_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call42A358(localVector, 0x800);
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
            if (Transition42_D_80070328.animationState == 0x2E) {
                Transition42_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition42_D_80070328.rotation.pitch & 0xFFF;
            Transition42_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition42_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition42_D_80070328.rotation.pitch > 0) {
                Transition42_D_80070328.rotation.pitch = 0;
            }
            Transition42_D_80070328.unk5 = 1;
            Transition42_func_8004F168((Vector3D *) ((unsigned char*)&Transition42_D_80070328.animationState + 0x104));
            Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition42_D_80070328.animationState + 0x50), 0);
            Transition42_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition42_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition42_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition42RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition42RawUnion;
            *(int*)unionPointer=(-Transition42_D_80070328.unk7a[2].z)>>2;
            if(Transition42RawMovement!=8){Transition42_D_80070328.union144.a.unk13cc=0x5900;Transition42RawMovement=10;}
            Transition42_D_80070328.unk5=0;
            Transition42_D_80070328.unk8[0]=Transition42_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition42_D_80070328.grounded=1;
            Transition42_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call42A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x31: {
        register unsigned char* lengthBase __asm__("$5")=(unsigned char*)&Transition42_D_80070328.unk8[0];
        register int valueA __asm__("$4");
        register int valueB __asm__("$5");
        register int valueKind __asm__("$6");
        *(int*)lengthBase=0;
        if(Transition42_D_80070328.animationState==0xD || Transition42_D_80070328.movementState==1)
            func_8004F178((Vector3D*)(lengthBase-0x30),(Vector3D*)(lengthBase-0x18));
        else Transition42_func_8004F168((Vector3D*)(lengthBase-0x30));
        func_8004F178(&Transition42_D_80070328.unk7a[2],(Vector3D*)((unsigned char*)&Transition42_D_80070328.unk7a[2]-0xC));
        Transition42_D_80070328.movementState=17;
        Transition42_D_80070328.unk5=0;
        Transition42_func_80043A38(0xC00);
        Transition42_D_80070328.grounded=0;
        Transition42_D_80070328.union144.a.unk13cb=0;
        valueKind=1;
        if(Transition42_D_80070328.unk9ha[0]>=11) {
            valueA=Transition42_D_80070328.unk9e.x;
            valueB=Transition42_D_80070328.unk9e.y;
        } else {
            valueA=Transition42_D_80070328.unk7a[3].x;
            valueB=valueA;
        }
        Transition42_D_80070328.union144.a.unk13cc=Transition42_func_8004E880(valueA,valueB,valueKind);
        goto clearPointers;
    }
    case 0x2F:case 0x32:case 0x33:case 0x34:
        savedBase=Raw42Movement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition42_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            Transition42_D_80070328.grounded=1;
        }
clearPointers:
        Transition42_D_80070328.unk20a=0;
        Transition42_D_80070328.critterMobyPtr=0;
        return;
    case 0x41:
        Transition42_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition42_func_800441F0();
        Transition42_D_80070328.grounded = 1;
        return;
    case 0x42:
    case 0x45:
        Transition42_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition42_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition42_D_80070328.movementState) + 0x3C)), (Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition42_D_80070328.movementState) + 0x48)));
            Transition42_D_80070328.unk5 = MOVEMENT_STATE_WALK;
        } else {
            Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        }
        Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8(&Transition42_D_80070328.unk7a[3], 0);
        Transition42_func_80043A38(0xC00);
        Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.grounded = 1;
        goto clearFlags;
    case 0x43:
    case 0x49:
        initialMovement=Raw42Movement;
        __asm__("" : "=r"(initialMovement) : "0"(initialMovement));
        comparisonKind=10;
        __asm__("" : "=r"(comparisonKind) : "0"(comparisonKind));
        {register Moby* critter __asm__("$3")=Transition42_D_80070328.critterMobyPtr;
        register int current __asm__("$4")=*(int*)initialMovement;
        __asm__("" : "=r"(critter),"=r"(current) : "0"(critter),"1"(current));
        jumpPrivate=critter->mobyTag;
        __asm__("" : "=r"(jumpPrivate) : "0"(jumpPrivate));
        if ((current == comparisonKind) && (SpawnParticle != 0) && (Transition42_D_80070328.unk4[0] < 0)) {
            jumpVector=&vectors.fourth;
            func_8004F178(jumpVector, (Vector3D*)(initialMovement-0x50));
            vectors.fourth.z = -Transition42_D_80070328.unk4[0];
            SpawnParticle(6, 0x2E, jumpVector, 0);
            SpawnParticle(4, 0x29, jumpVector, 0);
        }
        }
        movement=Raw42Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        firstJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) firstJumpSource);
        Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8((Vector3D *) firstJumpSource, 0);
        if (arg0 == 0x49) {
            Transition42_D_80070328.unk7a[2].z = 0x2580;
        } else {
            Transition42_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)jumpPrivate+0x4C) = 0;
        }
        Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
        goto playJumpSound;
    case 0x44:
        Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        if (Transition42_D_80070328.movementState == MOVEMENT_STATE_JUMP_HOVER) {
            if(Transition42_D_80070328.animationState==0x43)Transition42_D_80070328.unk5=1;
            else if(Transition42_D_80070328.animationState==0x46)Transition42_D_80070328.unk5=Transition42_D_80070328.movementState;
            else if(Transition42_D_80070328.animationState==0x49)Transition42_D_80070328.unk5=4;
        } else {
            Transition42_D_80070328.movementState = MOVEMENT_STATE_FALL;
        }
        Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8(&Transition42_D_80070328.unk7a[3], 0);
        Transition42_D_80070328.grounded = 0;
        goto clearFlags;
    case 0x46:
        movement=Raw42Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        secondJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) secondJumpSource);
        Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8((Vector3D *) secondJumpSource, 0);
        Transition42_D_80070328.unk7a[2].z = 0x12C0;
        Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition42_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
playJumpSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
        return;
    case 0x47:
        if (Transition42_D_80070328.ticksSinceLastSurfaceTouch != 0) {
            if (Transition42_D_80070328.movementState != MOVEMENT_STATE_FALL) {
                if (Transition42_D_80070328.animationState == 0x43) {
                    Transition42_D_80070328.unk5 = MOVEMENT_STATE_WALK;
                } else if (Transition42_D_80070328.animationState == 0x46) {
                    Transition42_D_80070328.unk5 = MOVEMENT_STATE_JUMP_HOVER;
                } else {
                    Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
                }
            }
            Transition42_D_80070328.movementState = MOVEMENT_STATE_FALL;
            Transition42_D_80070328.grounded = 0;
            Transition42_D_80070328.idle = 0;
            Transition42_D_80070328.unk15g = 0;
        } else {
            Transition42_D_80070328.movementState = MOVEMENT_STATE_WALK;
            Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            Transition42_func_80043A38(0xC00);
            Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition42_D_80070328.grounded = 1;
        }
        Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8(&Transition42_D_80070328.unk7a[3], 0);
        goto clearFlags;
clearFlags:
        Transition42_D_80070328.idle = 0;
        Transition42_D_80070328.unk15g = 0;
        return;
    case 0x48: {
        register Moby* critter __asm__("$2")=Transition42_D_80070328.critterMobyPtr;
        __asm__ volatile("" : "=r"(critter) : "0"(critter) : "memory");
        damagePrivate=critter->mobyTag;
        __asm__ volatile("" : "=r"(damagePrivate) : "0"(damagePrivate) : "memory");
        previousValue=Raw42Word;
        __asm__ volatile("" : "=r"(previousValue) : "0"(previousValue) : "memory");
        unionBase=Raw42Union;
        __asm__("" : "=r"(previousValue),"=r"(unionBase) : "0"(previousValue),"1"(unionBase));
        *(int*)unionBase=previousValue;
        Raw42Word = MOVEMENT_STATE_HURT;
        if (Transition42_D_80070328.damageFlags & 8) {
            damageSource = (Vector3D *) (unionBase - 0xAC);
            Transition42_D_80070328.unk5 = MOVEMENT_STATE_WALK;
            func_8004F178((Vector3D *) (unionBase - 0xB8), damageSource);
            Transition42_D_80070328.unk8[0] = Transition42_func_8004EDE8(damageSource, 0);
            soundTable=(unsigned char*)D_8006C654;
            soundZero=0;
            __asm__ volatile("" : "=r"(soundTable),"=r"(soundZero) : "0"(soundTable),"1"(soundZero) : "memory");
            Transition42_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)damagePrivate+0x4C) = 0;
            Transition42_D_80070328.grounded = 0;
            Transition42_D_80070328.union144.a.unk13cc = 1;
            PlaySound(soundTable[12],(Moby*)soundZero,0);
        } else {
            Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            damageDestination = (Vector3D *) (unionBase - 0xB8);
            if (Transition42_D_80070328.unk17a & 0x400) {
                func_8004F178(damageDestination, (Vector3D *) ((Vector3D *) (unionBase + 0xD8)));
                Transition42_func_8004F0E8(damageDestination, 6);
            } else if (Transition42_D_80070328.unk22[5] >= 0) {
                tableIndex=Transition42_D_80070328.unk22[5]*2;
                tableValue=*(short*)((unsigned char*)D_80065920+tableIndex);
                __asm__("" : "=r"(tableValue) : "0"(tableValue));
                Raw42X=tableValue>>1;
                tableIndex=*(short*)((unsigned char*)D_800658A0+tableIndex);
                Transition42_D_80070328.unk7a[2].z=0;
                __asm__ volatile("" : "=r"(tableIndex) : "0"(tableIndex) : "memory");
                Transition42_D_80070328.unk7a[2].y=tableIndex>>1;
            } else {
                    __asm__("" : "=r"(unionBase) : "0"(unionBase));
                Transition42_func_8004F168((Vector3D*)(unionBase-0xB8));
            }
            func_8004F178(&Transition42_D_80070328.unk7a[1], (Vector3D *) ((unsigned char*)(&Transition42_D_80070328.unk7a[1]) + 0xC));
            Transition42_func_80043A38(0xC00);
            Transition42_D_80070328.grounded = 1;
        }
        Transition42_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
        break;
    }
    case 0x4A:
        Transition42_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition42_func_80043A38(0xC00);
        Transition42_D_80070328.grounded = 1;
        Transition42_D_8006E524 = 0xF;
        return;
    case 0x4B:
        firstAnimation=Raw42Animation;
        __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        if(firstAnimation==0x44){
            if(Transition42_D_80070328.unk5==4)goto setHeadbashFlag;
            comparisonKind=0x49;
            __asm__ volatile("" : "=r"(comparisonKind) : "0"(comparisonKind) : "memory");
            firstAnimation=Raw42Animation;
            __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        }else comparisonKind=0x49;
        if(firstAnimation==comparisonKind){
setHeadbashFlag:
            Transition42_D_80070328.union144.a.unk13cc=1;
        }else Transition42_D_80070328.union144.a.unk13cc=0;
        Transition42_D_80070328.movementState = MOVEMENT_STATE_HEADBASH;
        Transition42_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition42_func_8004F168((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition42_D_80070328.movementState) + 0x3C)));
        Transition42_D_80070328.unk7a[2].z = 0x800;
        Transition42_D_80070328.grounded = 0;
        Transition42_D_80070328.unk13a[0] = 0x20000;
        Transition42_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        return;
    case 0x4C:
        Transition42_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=1;
        goto setHeadbashSubstate;
    case 0x4D:
        Transition42_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=2;
setHeadbashSubstate:
        Transition42_D_80070328.unk5=nextSubstate;
        Transition42_D_80070328.grounded=0;
        Transition42_D_80070328.unk13a[0]=0x20000;
        return;
    }
}


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008DD24.
 * Assembly SHA256 c54a69524e82e2f195ac590113cfd93158e8cd4cc80197f47b993f9c96cd6631.
 * AI-generated; not human reviewed. Verified donor state C is adapted to
 * all1526 original instructions and59 state-table entries (bias19).
 * Original65..77 Sheila chains reuse the fully matched level23 baseline.
 * Each outer case cluster uses the target selectors; original49/66 guarded
 * exits remain distinct. View names preserve the original typed aliases;
 * exact symbol identities and per-state donor provenance are recorded.
 * Empty initialized constraints and original-address metadata emit no CPU
 * instructions. Every CPU word is emitted by the frozen C toolchain.
 * Raw physical units/fixed point, helper contracts and invocation rate
 * remain unresolved. Cadence is per invocation; rate unknown.
 * Falsification: every original native/linked instruction, branch/internal
 * target, selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
extern int Anim42Player48View1 __asm__("D_80070328 + 0x48");
extern int Anim42Player48View2 __asm__("D_80070328 + 0x48");
extern int Anim42Player4CView1 __asm__("D_80070328 + 0x4C");
extern int Anim42Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim42PlayerA0View1 __asm__("D_80070328 + 0xA0");
extern int Anim42PlayerA8View1 __asm__("D_80070328 + 0xA8");
extern int Anim42PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim42PlayerB0View1 __asm__("D_80070328 + 0xB0");
extern int Anim42PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim42PlayerCCView1 __asm__("D_80070328 + 0xCC");
extern int Anim42PlayerD0View1 __asm__("D_80070328 + 0xD0");
extern int Anim42PlayerD4View1 __asm__("D_80070328 + 0xD4");
extern int Anim42Player8CView1 __asm__("D_80070328 + 0x8C");
extern int Anim42Player90View1 __asm__("D_80070328 + 0x90");
extern int Anim42Player94View1 __asm__("D_80070328 + 0x94");
extern int Anim42PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern int Anim42Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim42Player1ECView1 __asm__("D_80070328 + 0x1EC");
extern int Anim42Player1F0View1 __asm__("D_80070328 + 0x1F0");
extern int Anim42Player240View1 __asm__("D_80070328 + 0x240");
extern int Anim42Player280View1 __asm__("D_80070328 + 0x280");
extern unsigned char Anim42Player14View1 __asm__("D_80070328 + 0x14");
extern unsigned char Anim42Player15View1 __asm__("D_80070328 + 0x15");
extern unsigned char Anim42Player16View1 __asm__("D_80070328 + 0x16");
extern unsigned char Anim42Player17View1 __asm__("D_80070328 + 0x17");
extern unsigned char Anim42PlayerFCView1 __asm__("D_80070328 + 0xFC");
extern unsigned char Anim42Player1B5View1 __asm__("D_80070328 + 0x1B5");
extern unsigned char Anim42Player1B6View1 __asm__("D_80070328 + 0x1B6");
extern unsigned char Anim42Data66530View1[] __asm__("D_80066530");
extern int Anim42Data6E538View1 __asm__("D_8006E538"),Anim42Data6E53CView1 __asm__("D_8006E53C");
extern int Anim42Data6E044View1 __asm__("D_8006E044"),A4898Gate __asm__("D_8006E344"),A4898Count __asm__("D_8006C514");
int Anim42Call40994View1() __asm__("func_80040994");
int Anim42Call4BEF8View1() __asm__("func_8004BEF8");
int Anim42Call49688View1() __asm__("func_80049688");
int Anim42Call498C0View1() __asm__("func_800498C0");
extern int Anim42PlayerB4View1 __asm__("D_80070328 + 0xB4");
extern int Anim42PlayerA4View1 __asm__("D_80070328 + 0xA4");
extern int Anim42Player4CView2 __asm__("D_80070328 + 0x4C");
extern int Anim42Player54View2 __asm__("D_80070328 + 0x54");
extern int Anim42PlayerB0View2 __asm__("D_80070328 + 0xB0");
extern int Anim42Player158View1 __asm__("D_80070328 + 0x158");
extern unsigned char Anim42Player0View1[] __asm__("D_80070328");
extern int Anim42Data6E538View2 __asm__("D_8006E538"),Anim42Data6E53CView2 __asm__("D_8006E53C");
extern int Anim42Data6E044View2 __asm__("D_8006E044"),Anim42Data6E344View1 __asm__("D_8006E344"),Anim42Data6C514View1 __asm__("D_8006C514");
extern int (*Anim42Data74374View1)() __asm__("unk_ovlheader_80074374");
int Anim42Call40994View2() __asm__("func_80040994");
int Anim42Call4BEF8View2() __asm__("func_8004BEF8");
int Anim42Call4F334View1() __asm__("func_8004F334");
extern volatile int Anim42Player20CView1 __asm__("D_80070328 + 0x20C");
extern int Anim42Player214View1 __asm__("D_80070328 + 0x214");
extern unsigned char Anim42Player100View1 __asm__("D_80070328 + 0x100");
extern unsigned char Anim42Data6E535View1 __asm__("D_8006E535");
extern unsigned char* Anim42Data6EE2CView1 __asm__("D_8006EE2C");
int Anim42Call40BCCView1() __asm__("func_80040BCC");
int Anim42Call1A310View1() __asm__("func_8001A310");
extern int (*Anim42Data7431CView1)(int) __asm__("unk_ovlheader_8007431C");
extern int Anim42Player44View1 __asm__("D_80070328 + 0x44");
extern int Anim42Player48View3 __asm__("D_80070328 + 0x48");
extern int Anim42Player4CView3 __asm__("D_80070328 + 0x4C");
extern int Anim42Player50View1 __asm__("D_80070328 + 0x50");
extern int Anim42Player54View3 __asm__("D_80070328 + 0x54");
extern int Anim42Player58View1 __asm__("D_80070328 + 0x58");
extern int Anim42Player8CView2 __asm__("D_80070328 + 0x8C");
extern int Anim42Player90View2 __asm__("D_80070328 + 0x90");
extern int Anim42Player94View2 __asm__("D_80070328 + 0x94");
extern int Anim42PlayerA8View2 __asm__("D_80070328 + 0xA8");
extern int Anim42PlayerACView2 __asm__("D_80070328 + 0xAC");
extern int Anim42PlayerB0View3 __asm__("D_80070328 + 0xB0");
extern int Anim42PlayerB8View2 __asm__("D_80070328 + 0xB8");
extern int Anim42PlayerCCView2 __asm__("D_80070328 + 0xCC");
extern int Anim42PlayerD0View2 __asm__("D_80070328 + 0xD0");
extern int Anim42PlayerD4View2 __asm__("D_80070328 + 0xD4");
extern int Anim42PlayerE4View2 __asm__("D_80070328 + 0xE4");
extern int Anim42Player144View2 __asm__("D_80070328 + 0x144");
extern int Anim42Player280View2 __asm__("D_80070328 + 0x280");
extern unsigned char Anim42Player0View2[] __asm__("D_80070328");
extern unsigned char *Anim42Player250View1 __asm__("D_80070328 + 0x250");
extern unsigned char Anim42Player1B6View2 __asm__("D_80070328 + 0x1B6");
extern unsigned char Anim42Data6E535View2 __asm__("D_8006E535");
extern int Anim42Data6E538View3 __asm__("D_8006E538");
extern int Anim42Data6E53CView3 __asm__("D_8006E53C");
extern int Anim42Data6E530View1 __asm__("D_8006E530");
extern int Anim42Data6E52CView1 __asm__("D_8006E52C");
extern unsigned char *Anim42Data6C654View1 __asm__("D_8006C654");
extern int (*Anim42Data7431CView2)(int) __asm__("unk_ovlheader_8007431C");
extern int (*Anim42DataSpawnParticleView1)(int,int,void*,int) __asm__("SpawnParticle");
int Anim42Call55E84View1(void*) __asm__("func_80055E84");
int Anim42Call1A358View1(void*,int) __asm__("func_8001A358");
int Anim42Call4BEF8View3(int) __asm__("func_8004BEF8");
int Anim42CallPlaySoundView1(unsigned char,int,int) __asm__("PlaySound");
#define Anim42Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
void func_level_42_8008DD24(void){
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int nextSelector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* record16 __asm__("$16");
    register int (*callback3)(int) __asm__("$3");
    register int* savedPointer16 __asm__("$16");
    rawValue2=Anim42Player48View1;
    switch(rawValue2){
    case 20:
        if(Anim42Call40994View1())return;
        rawValue2=Anim42Data6E53CView1&64;
        nextSelector4=6;
        if(rawValue2)goto select;
        rawValue2=Anim42PlayerB8View1<4;
        nextSelector4=7;
        if(!rawValue2)goto select;
        if(Anim42PlayerE4View1>=23)goto select;
        rawValue3=Anim42Data6E538View1;
        rawValue2=rawValue3&128;
        nextSelector4=13;
        if(rawValue2)goto select;
        rawValue2=Anim42PlayerA8View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        if(rawValue2>=17){
            nextSelector4=1;
            goto select;
        }
        rawValue2=rawValue3&12;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2));
        if(!rawValue2){
            rawValue2=Anim42PlayerACView1;
            nextSelector4=1;
            if(rawValue2)goto select;
        }
        if(Anim42Data6E044View1==7 || Anim42Player240View1) {
            savedPointer16=&Anim42Player48View2;
            __asm__("" : "=r"(savedPointer16):"0"(savedPointer16));
            if(!*savedPointer16)return;
            Anim42Call4BEF8View1(0);
            if(Anim42Data66530View1[*((unsigned char*)savedPointer16-0x2C)]>=96){
                Anim42Player14View1=Anim42Player15View1;
                Anim42Player16View1=Anim42Player17View1;
            }
            Anim42Player17View1=0;
            rawValue3=*savedPointer16;
            rawValue2=113;
            *((unsigned char*)savedPointer16-0x2C)=rawValue2;
            Anim42Player1F0View1=0;
            Anim42Player15View1=rawValue3;
            Anim42Player1ECView1=rawValue3;
            return;
        }
        rawValue2=Anim42PlayerFCView1;
        nextSelector4=15;
        if(rawValue2)goto select;
        Anim42Call49688View1();
        return;
    case 29:
        if(Anim42Player54View1<25)return;
        if(Anim42Player280View1<0){
            nextSelector4=31;
            goto select;
        }
        rawValue2=10;
        rawValue3=Anim42Player144View1;
        if(rawValue3==rawValue2){
            __asm__ volatile("" ::: "memory");
            nextSelector4=44;
            goto select;
        }
        rawValue2=rawValue3-11;
        if((unsigned)rawValue2<2){
            __asm__ volatile("" ::: "memory");
            nextSelector4=41;
            goto select;
        }
        rawValue2=Anim42PlayerB8View1;
        nextSelector4=0;
        if(!rawValue2)goto select;
        __asm__ volatile("" ::: "memory");
        nextSelector4=7;
        goto select;
    case 19:
        if(Anim42Call40994View2())return;
        rawValue2=13;
        rawValue3=Anim42Data6E344View1;
        if(rawValue3==rawValue2){
            rawValue2=Anim42Data6C514View1;
            nextSelector4=17;
            if(rawValue2)goto select;
        }
        nextSelector4=(int)Anim42Player0View1;
        rawValue2=Anim42Call4F334View1((void*)nextSelector4,(void*)(nextSelector4+348));
        rawValue3=Anim42Player158View1;
        rawValue3=rawValue3<rawValue2;
        nextSelector4=17;
        if(!rawValue3)return;
        goto select;
    case 28:
        if(Anim42Player1B5View1 && (Anim42Data6E53CView1&64))Anim42Player1B6View1=1;
        if(!Anim42PlayerB8View1 && Anim42Player54View1>=16 && Anim42PlayerE4View1<23) {
            rawValue3=Anim42PlayerCCView1;
            rawValue2=Anim42Player8CView1;
            product5=rawValue3*rawValue2;
            rawValue3=Anim42PlayerD0View1;
            rawValue2=Anim42Player90View1;
            nextSelector4=rawValue3*rawValue2;
            rawValue3=Anim42PlayerD4View1;
            rawValue2=Anim42Player94View1;
            rawValue3*=rawValue2;
            rawValue2=product5+nextSelector4;
            rawValue2+=rawValue3;
            if(rawValue2<0) {
                if(Anim42PlayerACView1) {
                    rawValue3=Anim42PlayerB0View1;
                    if(rawValue3>=3841){
                        nextSelector4=3;
                        goto select;
                    }
                    rawValue2=rawValue3<1921;
                    nextSelector4=1;
                    if(rawValue2)goto select;
                    nextSelector4=2;
                    goto select;
                }
                rawValue2=Anim42PlayerB0View1<1920;
                nextSelector4=0;
                if(rawValue2)goto select;
                __asm__ volatile("" ::: "memory");
                nextSelector4=4;
                goto select;
            }
        }
        rawValue2=Anim42Data6E538View1&128;
        if(rawValue2 && Anim42Player4CView1==1){
            nextSelector4=22;
            goto select;
        }
        if(Anim42Player1B5View1 && Anim42Player1B6View1) {
            rawValue3=Anim42Player4CView1;
            rawValue2=1;
            nextSelector4=17;
            if(rawValue3!=rawValue2)return;
            goto select;
        }
        rawValue3=Anim42Player4CView1;
        rawValue2=1;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim42PlayerA0View1<-6400;
        nextSelector4=7;
        if(rawValue2)goto select;
        if(Anim42Player54View1>=91)goto select;
        return;
    case 38:
        {
            register int (*callback2)(int) __asm__("$2");
            callback:callback2=Anim42Data7431CView1;
            callback2(1);
            return;
        }
    case 40:
        if(Anim42Call40994View2())return;
        if((Anim42Data6E538View2&128) && Anim42Player4CView2!=1){
            nextSelector4=42;
            goto select;
        }
        if(Anim42PlayerB0View2)return;
        rawValue2=Anim42Player20CView1&64;
        nextSelector4=41;
        if(!rawValue2)goto select;
        if(Anim42Player214View1<=0)return;
        goto select;
    case 41:
        if(Anim42Call40994View2())return;
        nextSelector4=Anim42Data6E538View2;
        rawValue2=nextSelector4&128;
        if(rawValue2){
            nextSelector4=42;
            goto select;
        }
        rawValue2=7;
        rawValue3=Anim42Data6E044View2;
        if(rawValue3==rawValue2)return;
        rawValue2=nextSelector4&64;
        nextSelector4=40;
        if(rawValue2)goto select;
        if(!(Anim42Player20CView1&64))return;
        if(!Anim42Player214View1)goto select;
        return;
    case 42:
        if(Anim42Call40BCCView1())return;
        if((Anim42Data6E538View2&128) || Anim42Player4CView2==1)goto flag64;
        rawValue2=Anim42Player20CView1&128;
        nextSelector4=40;
        if(!rawValue2)goto select;
        flag64:rawValue2=Anim42Player20CView1&64;
        nextSelector4=40;
        if(!rawValue2)return;
        goto select;
    case 43:
        {
            register unsigned char* byte4 __asm__("$4");
            if(Anim42Call40994View2())return;
            if((Anim42Data6E53CView2&64) && Anim42Player54View2>=9){
                nextSelector4=6;
                goto partialCall;
            }
            byte4=&Anim42Player100View1;
            __asm__("" : "=r"(byte4):"0"(byte4));
            if(!*byte4){
                nextSelector4=7;
                goto partialCall;
            }
            if(!(Anim42Data6E53CView2&128))goto check44;
            if(Anim42Player54View2<9)goto check44;
            rawValue2=*(int*)(Anim42Data6EE2CView1+220);
            byte4-=256;
            if(!rawValue2)goto check44;
            rawValue2=Anim42Call1A310View1(byte4,1024,1,0);
            nextSelector4=40;
            if(rawValue2)goto check44;
            goto select;
            partialCall:Anim42Call4BEF8View2(nextSelector4);
            check44:rawValue2=Anim42Data6E535View1;
            nextSelector4=44;
            if(!rawValue2)return;
            goto select;
        }
    case 44:
        {
            register unsigned char* byte4 __asm__("$4");
            register int (*callback2)() __asm__("$2");
            rawValue3=Anim42Player4CView2;
            rawValue2=1;
            if(rawValue3!=rawValue2)goto other44;
            if(Anim42Data6E53CView2&0x850)goto callback44;
            if(Anim42Player54View2<61)return;
            callback44:callback2=Anim42Data74374View1;
            __asm__("" : "=r"(callback2):"0"(callback2));
            if(!callback2)goto missingCallback;
            callback2();
            return;
            missingCallback:goto call498C0;
            other44:if(Anim42Call40994View2())return;
            if((Anim42Data6E53CView2&64) && Anim42Player54View2>=9){
                nextSelector4=6;
                goto select;
            }
            byte4=&Anim42Player100View1;
            __asm__("" : "=r"(byte4):"0"(byte4));
            if(!*byte4){
                nextSelector4=7;
                goto select;
            }
            if(!(Anim42Data6E53CView2&128))goto mode44;
            if(Anim42Player54View2<9)goto mode44;
            rawValue2=*(int*)(Anim42Data6EE2CView1+220);
            byte4-=256;
            if(!rawValue2)goto mode44;
            rawValue2=Anim42Call1A310View1(byte4,1024,1,0);
            nextSelector4=40;
            if(!rawValue2)goto select;
            mode44:rawValue3=Anim42Data6E044View2;
            rawValue2=7;
            if(rawValue3==rawValue2)return;
            rawValue2=Anim42Data6E535View1;
            nextSelector4=43;
            if(rawValue2)return;
            goto select;
        }
    case 47:
        if(Anim42Call40994View1())return;
        if(Anim42Data6E53CView1&64){
            rawValue2=Anim42Data6E538View1&16384;
            nextSelector4=6;
            if(rawValue2)goto specialJump;
            __asm__ volatile("" ::: "memory");
            goto select;
        }
        rawValue2=Anim42PlayerACView1;
        nextSelector4=50;
        if(!rawValue2)return;
        goto select;
    case 49:
        if(Anim42Call40994View1())return;
        rawValue2=Anim42PlayerB8View1<4;
        nextSelector4=7;
        if(!rawValue2)goto select;
        rawValue2=Anim42Player144View1<16;
        nextSelector4=0;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x8008E65C):"memory");
        goto select;
    case 50:
        if(Anim42Call40994View1())return;
        if(Anim42Data6E53CView1&64){
            rawValue2=Anim42Data6E538View1&16384;
            nextSelector4=6;
            if(rawValue2)goto specialJump;
            goto select;
        }
        rawValue2=Anim42PlayerACView1;
        nextSelector4=47;
        if(!rawValue2)goto select;
        rawValue2=Anim42PlayerA0View1;
        rawValue3=Anim42PlayerB4View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<rawValue3;
        if(!rawValue2)return;
        rawValue2=Anim42PlayerA4View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<1024;
        nextSelector4=52;
        if(!rawValue2)goto select;
        nextSelector4=51;
        goto select;
    case 51:case 52:
        if(Anim42Call40994View1())return;
        if(Anim42Data6E53CView1&64){
            rawValue2=Anim42Data6E538View1&16384;
            nextSelector4=6;
            if(!rawValue2)goto select;
            specialJump:Anim42Call4BEF8View1(7);
            rawValue2=3;
            Anim42Player4CView1=rawValue2;
            return;
        }
        rawValue2=Anim42PlayerACView1;
        nextSelector4=47;
        if(!rawValue2)goto select;
        rawValue2=Anim42PlayerA0View1;
        rawValue3=Anim42PlayerB4View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<rawValue3;
        nextSelector4=50;
        if(rawValue2)return;
        __asm__ volatile("" ::: "memory");
        goto select;
    case 58:
        if(Anim42Player54View1<137)return;
        call498C0:Anim42Call498C0View1();
        return;
    case 65:
        rawValue2=Anim42Data7431CView2(9);
        if(rawValue2)return;
        rawValue3=Anim42Data6E53CView3;
        rawValue2=rawValue3&64;
        if(rawValue2){
            rawValue2=(int)Anim42Player250View1;
            rawValue2=(int)Anim42Field((void*)rawValue2,void**,0);
            rawValue2=Anim42Field((void*)rawValue2,int*,0x48);
            rawValue2=rawValue2<8;
            nextSelector4=67;
            if(!rawValue2)goto select;
            __asm__ volatile(""::"i"(0x8008E838):"memory");
            nextSelector4=73;
            goto select;
        }
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=Anim42PlayerB8View2<4;
        nextSelector4=68;
        if(!rawValue2)goto select;
        rawValue2=Anim42PlayerE4View2<23;
        if(!rawValue2)goto select;
        rawValue2=Anim42PlayerA8View2;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<17;
        nextSelector4=66;
        if(!rawValue2)goto select;
        rawValue2=Anim42Data6E538View3&12;
        if(rawValue2)return;
        rawValue2=Anim42PlayerACView2;
        if(!rawValue2)return;
        goto select;
    case 66:
        rawValue2=Anim42Data7431CView2(9);
        if(rawValue2)return;
        rawValue3=Anim42Data6E53CView3;
        rawValue2=rawValue3&64;
        if(rawValue2){
            rawValue2=(int)Anim42Player250View1;
            rawValue2=(int)Anim42Field((void*)rawValue2,void**,0);
            rawValue2=Anim42Field((void*)rawValue2,int*,0x48);
            rawValue2=rawValue2<8;
            nextSelector4=67;
            if(!rawValue2)goto select;
            __asm__ volatile(""::"i"(0x8008E92C):"memory");
            nextSelector4=73;
            goto select;
        }
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=Anim42PlayerB8View2<4;
        nextSelector4=68;
        if(!rawValue2)goto select;
        rawValue2=Anim42PlayerE4View2<23;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim42Player250View1;
        rawValue2=Anim42Player48View3;
        rawValue3=Anim42Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)goto query66;
        rawValue2=Anim42Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(rawValue2)goto input66;
    query66:
        rawValue2=Anim42Call55E84View1((void*)nextSelector4);
        rawValue2=rawValue2<4;
        if(!rawValue2)return;
    input66:
        rawValue2=Anim42Data6E535View2;
        if(!rawValue2)goto held66;
        rawValue2=Anim42PlayerB0View3;
        nextSelector4=65;
        if(!rawValue2)goto select;
    held66:
        rawValue2=Anim42Data6E538View3&12;
        if(!rawValue2)return;
        rawValue2=Anim42Player144View2<16;
        nextSelector4=65;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x8008EA0C):"memory");
        goto select;
    case 67:
        rawValue2=Anim42Data7431CView2(9);
        if(rawValue2)return;
        rawValue2=Anim42Player54View3<16;
        if(!rawValue2){
            rawValue2=Anim42Data6E53CView3&64;
            nextSelector4=70;
            if(rawValue2)goto select;
        }
        rawValue3=Anim42Data6E53CView3;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            product5=Anim42Player44View1;
            nextSelector4=(int)Anim42Player0View2;
            rawValue2=Anim42Call1A358View1((void*)nextSelector4,product5+512);
            nextSelector4=75;
            if(!rawValue2)goto select;
        }
        rawValue2=Anim42PlayerB8View2;
        if(rawValue2)goto finish67;
        rawValue2=Anim42Player54View3<16;
        if(rawValue2)goto finish67;
        rawValue2=Anim42PlayerE4View2<23;
        if(!rawValue2)return;
        rawValue3=Anim42PlayerCCView2;
        rawValue2=Anim42Player8CView2;
        product5=rawValue3*rawValue2;
        rawValue3=Anim42PlayerD0View2;
        rawValue2=Anim42Player90View2;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim42PlayerD4View2;
        rawValue2=Anim42Player94View2;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)return;
        rawValue2=Anim42PlayerACView2;
        nextSelector4=66;
        if(!rawValue2)goto select65;
        __asm__ volatile(""::"i"(0x8008EB60):"memory");
        goto select;
    finish67:
        nextSelector4=(int)Anim42Player250View1;
        rawValue2=Anim42Player48View3;
        rawValue3=Anim42Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim42Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=68;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x8008EB9C):"memory");
        goto select;
    case 68:
        rawValue2=(int)Anim42Player250View1;
        callback3=Anim42Data7431CView2;
        record16=Anim42Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(9);
        if(rawValue2)return;
        rawValue2=Anim42Data6E53CView3&64;
        if(rawValue2){
            rawValue2=1;
            nextSelector4=(int)&Anim42Player4CView3;
            rawValue3=*(int*)nextSelector4;
            __asm__("":"=r"(rawValue2):"0"(rawValue2));
            if(rawValue3==rawValue2){
                rawValue2=Anim42Player54View3<31;
                nextSelector4-=76;
                if(rawValue2){
                    rawValue2=Anim42Call1A358View1((void*)nextSelector4,1024);
                    if(!rawValue2){
                        nextSelector4=70;
                        goto select;
                    }
                }
            }
            rawValue2=1;
            Anim42Player1B6View2=rawValue2;
            Anim42Field(record16,int*,0x48)=0;
        }
        rawValue3=Anim42Data6E53CView3;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            nextSelector4=(int)&Anim42Player4CView3;
            rawValue2=*(int*)nextSelector4;
            nextSelector4-=76;
            if(rawValue2){
                product5=Anim42Player44View1;
                rawValue2=Anim42Call1A358View1((void*)nextSelector4,product5+512);
                nextSelector4=75;
                if(!rawValue2)goto select;
            }
        }
        rawValue2=Anim42PlayerB8View2;
        if(rawValue2)return;
        rawValue2=Anim42PlayerE4View2<23;
        if(!rawValue2)return;
        rawValue2=Anim42Player1B6View2;
        if(rawValue2){
            rawValue2=Anim42Field(record16,int*,0x48)<7;
            if(rawValue2){
                rawValue2=2;
                rawValue3=Anim42Player50View1;
                nextSelector4=67;
                if(rawValue3!=rawValue2)goto effectSelect;
                nextSelector4=73;
                goto effectSelect;
            }
        }
        rawValue3=Anim42Player50View1;
        rawValue2=2;
        if(rawValue3==rawValue2){
            Anim42Field(record16,int*,0x48)=0;
        }
        else{
            rawValue2=255;
            Anim42Field(record16,int*,0x48)=rawValue2;
        }
        rawValue2=Anim42PlayerACView2;
        nextSelector4=66;
        if(rawValue2)goto effectSelect;
        nextSelector4=69;
        goto effectSelect;
    case 69:
        rawValue2=Anim42Data7431CView2(9);
        if(rawValue2)return;
        rawValue3=Anim42Data6E53CView3;
        rawValue2=rawValue3&64;
        if(rawValue2){
            rawValue2=(int)Anim42Player250View1;
            rawValue2=(int)Anim42Field((void*)rawValue2,void**,0);
            rawValue2=Anim42Field((void*)rawValue2,int*,0x48);
            rawValue2=rawValue2<8;
            nextSelector4=67;
            if(!rawValue2)goto select;
            __asm__ volatile(""::"i"(0x8008ED94):"memory");
            nextSelector4=73;
            goto select;
        }
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=Anim42PlayerB8View2<4;
        nextSelector4=68;
        if(!rawValue2)goto select;
        rawValue2=Anim42PlayerE4View2<23;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim42Player250View1;
        rawValue2=Anim42Player48View3;
        rawValue3=Anim42Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)goto query69;
        rawValue2=Anim42Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(rawValue2)goto input69;
    query69:
        rawValue2=Anim42Call55E84View1((void*)nextSelector4);
        rawValue2=rawValue2<4;
        if(!rawValue2)return;
    input69:
        rawValue2=Anim42Data6E535View2;
        if(!rawValue2)goto held69;
        rawValue2=Anim42PlayerB0View3;
        nextSelector4=65;
        if(!rawValue2)goto select;
    held69:
        rawValue2=Anim42Data6E538View3&12;
        nextSelector4=66;
        if(!rawValue2)goto select;
        rawValue2=Anim42Player144View2<16;
        if(!rawValue2)goto select65;
        goto select;
    case 70:case 73:
        rawValue2=Anim42Data7431CView2(9);
        if(rawValue2)return;
        rawValue3=Anim42Data6E53CView3;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            product5=Anim42Player44View1;
            nextSelector4=(int)Anim42Player0View2;
            rawValue2=Anim42Call1A358View1((void*)nextSelector4,product5+512);
            nextSelector4=75;
            if(!rawValue2)goto select;
        }
        rawValue2=Anim42PlayerB8View2;
        if(rawValue2)goto finish70;
        rawValue2=Anim42Player54View3<16;
        if(rawValue2)goto finish70;
        rawValue2=Anim42PlayerE4View2<23;
        if(!rawValue2)return;
        rawValue3=Anim42PlayerCCView2;
        rawValue2=Anim42Player8CView2;
        product5=rawValue3*rawValue2;
        rawValue3=Anim42PlayerD0View2;
        rawValue2=Anim42Player90View2;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim42PlayerD4View2;
        rawValue2=Anim42Player94View2;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)return;
        rawValue2=Anim42PlayerACView2;
        nextSelector4=66;
        if(!rawValue2)goto select65;
        __asm__ volatile(""::"i"(0x8008EF98):"memory");
        goto select;
    finish70:
        nextSelector4=(int)Anim42Player250View1;
        rawValue2=Anim42Player48View3;
        rawValue3=Anim42Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim42Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=68;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x8008EFD4):"memory");
        goto select;
    case 71:
        rawValue2=Anim42Data7431CView2(9);
        if(rawValue2)return;
        rawValue2=3;
        rawValue3=Anim42Player50View1;
        if(rawValue3!=rawValue2)goto other71;
        rawValue2=Anim42PlayerB8View2;
        if(rawValue2)goto finish71;
        rawValue2=Anim42PlayerE4View2<23;
        nextSelector4=71;
        if(!rawValue2)return;
    effectSelect:
        Anim42Call4BEF8View3(nextSelector4);
        {
            register int (*spawn2)(int,int,void*,int) __asm__("$2")=Anim42DataSpawnParticleView1;
            if(spawn2)spawn2(8,33,0,2);
        }
        rawValue2=(int)Anim42Data6C654View1;
        product5=0;
        nextSelector4=Anim42Field((void*)rawValue2,unsigned char*,0x12);
        Anim42CallPlaySoundView1((unsigned char)nextSelector4,product5,0);
        rawValue2=Anim42Player58View1<24;
        if(rawValue2)return;
        rawValue2=120;
        Anim42Data6E530View1=rawValue2;
        rawValue2=15;
        Anim42Data6E52CView1=rawValue2;
        return;
    finish71:
        nextSelector4=(int)Anim42Player250View1;
        rawValue2=Anim42Player48View3;
        rawValue3=Anim42Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim42Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=68;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x8008F0E4):"memory");
        goto select;
    other71:
        rawValue2=Anim42PlayerB8View2<4;
        nextSelector4=71;
        if(!rawValue2)goto select;
        rawValue2=Anim42PlayerE4View2<23;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim42Player250View1;
        rawValue2=Anim42Player48View3;
        rawValue3=Anim42Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)goto query71;
        rawValue2=Anim42Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)goto query71;
        rawValue2=Anim42Data6E535View2;
        nextSelector4=65;
        if(rawValue2)goto select;
        nextSelector4=66;
        goto select;
    query71:
        rawValue2=Anim42Call55E84View1((void*)nextSelector4);
        rawValue2=rawValue2<16;
        if(rawValue2)return;
        rawValue2=Anim42Data6E535View2;
        nextSelector4=66;
        if(rawValue2)return;
        goto select;
    case 72:
        rawValue2=Anim42Player4CView3;
        if(!rawValue2)goto finish72;
        rawValue2=Anim42Player280View2;
        if(rawValue2<0)goto finish72;
        rawValue2=Anim42Player54View3<16;
        if(!rawValue2){
            rawValue2=Anim42Data6E53CView3&64;
            nextSelector4=70;
            if(rawValue2)goto select;
        }
        rawValue3=Anim42Data6E53CView3;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            product5=Anim42Player44View1;
            nextSelector4=(int)Anim42Player0View2;
            rawValue2=Anim42Call1A358View1((void*)nextSelector4,product5+512);
            nextSelector4=75;
            if(!rawValue2)goto select;
        }
        rawValue2=Anim42PlayerB8View2;
        if(rawValue2)goto finish72;
        rawValue2=Anim42Player54View3<16;
        if(rawValue2)goto finish72;
        rawValue2=Anim42PlayerE4View2<23;
        if(!rawValue2)goto finish72;
        rawValue3=Anim42PlayerCCView2;
        rawValue2=Anim42Player8CView2;
        product5=rawValue3*rawValue2;
        rawValue3=Anim42PlayerD0View2;
        rawValue2=Anim42Player90View2;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim42PlayerD4View2;
        rawValue2=Anim42Player94View2;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)goto finish72;
        rawValue2=Anim42PlayerACView2;
        nextSelector4=66;
        if(!rawValue2)goto select65;
        goto select;
    finish72:
        nextSelector4=(int)Anim42Player250View1;
        rawValue2=Anim42Player48View3;
        rawValue3=Anim42Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim42Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        rawValue2=Anim42Player280View2;
        if(rawValue2<0){
            nextSelector4=74;
            goto select;
        }
        rawValue2=10;
        rawValue3=Anim42Player144View2;
        nextSelector4=79;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim42PlayerB8View2;
        nextSelector4=68;
        if(!rawValue2)goto select65;
        goto select;
    case 74:
        nextSelector4=(int)Anim42Player250View1;
        rawValue2=Anim42Player48View3;
        rawValue3=Anim42Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim42Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        goto call498C0;
    case 75:
        rawValue2=Anim42Data7431CView2(9);
        if(rawValue2)return;
        rawValue2=2;
        rawValue3=Anim42Player4CView3;
        nextSelector4=77;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim42Player54View3<61;
        nextSelector4=68;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim42Player250View1;
        rawValue2=Anim42Player48View3;
        rawValue3=Anim42Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim42Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=76;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x8008F434):"memory");
        goto select;
    case 76:
        rawValue2=Anim42Data7431CView2(9);
        if(rawValue2)return;
        rawValue2=2;
        rawValue3=Anim42Player4CView3;
        nextSelector4=77;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim42Player54View3<61;
        nextSelector4=68;
        if(rawValue2)return;
        goto select;
    case 77:
        rawValue2=Anim42Data7431CView2(9);
        if(rawValue2)return;
        nextSelector4=(int)Anim42Player250View1;
        rawValue2=Anim42Player48View3;
        rawValue3=Anim42Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim42Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
    select65:
        nextSelector4=65;
        goto select;
        default:return;
    }
    select:Anim42Call4BEF8View1(nextSelector4);
    return;
}
#undef Anim42Field
