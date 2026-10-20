#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008FD90.
 * Assembly SHA256 52450b537b4d51a078f17de092253732abd52c9bf9ff933f4e4667a79a8eaa82.
 * AI-generated; not human reviewed. All2527 original instructions,
 * 79 selectors bias19 and 1 owned padding words are required.
 * Original frame0x140; every concrete field width and producer is retained.
 * Sixteen exact groups plus four identified original differences reuse
 * verified24/11/21/33/43. Original scratch10..124,savedS0..S4,slotS2 and
 * combinedS3 remain. Original33 retains the additional signed-halfword148
 * counter branch,retained A2 scalar and its actual rotation reload/compare
 * joins. Original29 enters88's shared vector call;86 enters87's original
 * helpers;49 enters95's vector copy after A1 production. All95 relative
 * argument producers and real shared94/158 store targets remain original.
 * Repeated identical declarations are removed; distinct typed aliases stay
 * distinct. Initialized empty constraints and original address metadata emit
 * zero CPU instructions; frozen C tools emit words. Units/fixed point,helper
 * contracts and caller rate remain unresolved; cadence is per invocation.
 * Falsification: every native/linked instruction,actual internal/conditional
 * target,selector/data and full EXE/every-overlay retail hashes. Binary identity
 * does not establish synchronized runtime or system completeness. */
#define Physics41Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Physics41Call363DCView1() __asm__("func_800363DC");
unsigned char Physics41Call40D10View1() __asm__("func_80040D10");
unsigned char Physics41Call41580View1() __asm__("func_80041580");
unsigned char Physics41Call416F4View1() __asm__("func_800416F4");
unsigned char Physics41Call417FCView1() __asm__("func_800417FC");
unsigned char Physics41Call41B64View1() __asm__("func_80041B64");
int Physics41Call4E9E4View1() __asm__("func_8004E9E4");
int Physics41Call4EA2CView1() __asm__("func_8004EA2C");
int Physics41Call4EDE8View1() __asm__("func_8004EDE8");
unsigned char Physics41Call4F08CView1() __asm__("func_8004F08C");
unsigned char Physics41Call4F168View1() __asm__("func_8004F168");
unsigned char Physics41Call4F178View1() __asm__("func_8004F178");
unsigned char Physics41Call4F194View1() __asm__("func_8004F194");
unsigned char Physics41Call4F1C8View1() __asm__("func_8004F1C8");
extern void *Physics41Data6C570View1 __asm__("D_8006C570");
extern int Physics41Data6C640View1 __asm__("D_8006C640");
extern int Physics41Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics41Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics41Player0View1 __asm__("D_80070328");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics41Call40D10View2() __asm__("func_80040D10");
int Physics41Call41580View2() __asm__("func_80041580");
int Physics41Call416F4View2() __asm__("func_800416F4");
int Physics41Call417FCView2() __asm__("func_800417FC");
int Physics41Call41848View1() __asm__("func_80041848");
int Physics41Call41B64View2() __asm__("func_80041B64");
int Physics41Call4E9E4View2() __asm__("func_8004E9E4");
int Physics41Call4EA2CView2() __asm__("func_8004EA2C");
int Physics41Call4EDE8View2() __asm__("func_8004EDE8");
int Physics41Call4F08CView2() __asm__("func_8004F08C");
int Physics41Call4F168View2() __asm__("func_8004F168");
int Physics41Call4F178View2() __asm__("func_8004F178");
int Physics41Call4F194View2() __asm__("func_8004F194");
int Physics41Call4F1C8View2() __asm__("func_8004F1C8");
extern int Physics41Data6E044View2 __asm__("D_8006E044");
extern int Physics41Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics41Player0View2 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics41PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics41Player94View1 __asm__("D_80070328+0x94");
extern int Physics41PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics41Player80View1 __asm__("D_80070328+0x80");
extern int Physics41PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics41Player64View1 __asm__("D_80070328+0x64");
extern int Physics41Player84View1 __asm__("D_80070328+0x84");
extern int Physics41Player144View1 __asm__("D_80070328+0x144");
extern int Physics41Player60View1 __asm__("D_80070328+0x60");
extern int Physics41PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics41Player4CView1 __asm__("D_80070328+0x4C");
extern int Physics41Player5CView1 __asm__("D_80070328+0x5C");
extern unsigned char Physics41PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics41PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics41Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics41Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics41Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics41Player101View1 __asm__("D_80070328+0x101");
extern int Physics41PlayerA4View1 __asm__("D_80070328+0xA4");
int Physics41Call4EDE8View3() __asm__("func_8004EDE8");
int Physics41Call4F08CView3() __asm__("func_8004F08C");
int Physics41Call4F168View3() __asm__("func_8004F168");
int Physics41Call4F178View3() __asm__("func_8004F178");
int Physics41Call4F194View3() __asm__("func_8004F194");
int Physics41Call4F1C8View3() __asm__("func_8004F1C8");
extern unsigned char Physics41Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics41Data65920View1 __asm__("D_80065920");
extern int Physics41Data6C514View1 __asm__("D_8006C514");
extern int Physics41Data6E344View1 __asm__("D_8006E344");
extern unsigned char Physics41Player0View3 __asm__("D_80070328");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics41Player16CView1 __asm__("D_80070328+0x16C");
int Physics41Call13E38View1() __asm__("func_80013E38");
int Physics41Call410F8View1() __asm__("func_800410F8");
int Physics41Call417FCView3() __asm__("func_800417FC");
int Physics41Call41848View2() __asm__("func_80041848");
int Physics41Call41B64View3() __asm__("func_80041B64");
int Physics41Call4E4E4View1() __asm__("func_8004E4E4");
int Physics41Call4E880View1() __asm__("func_8004E880");
int Physics41Call4E9E4View3() __asm__("func_8004E9E4");
int Physics41Call4EA2CView3() __asm__("func_8004EA2C");
int Physics41Call4EDE8View4() __asm__("func_8004EDE8");
int Physics41Call4F08CView4() __asm__("func_8004F08C");
int Physics41Call4F0E8View1() __asm__("func_8004F0E8");
int Physics41Call4F178View4() __asm__("func_8004F178");
int Physics41Call4F194View4() __asm__("func_8004F194");
int Physics41Call4F1C8View4() __asm__("func_8004F1C8");
extern int Physics41Data67630View1 __asm__("D_80067630");
extern int Physics41Data67634View1 __asm__("D_80067634");
extern int Physics41Data67638View1 __asm__("D_80067638");
extern int Physics41Data6FA38View1 __asm__("D_8006FA38");
extern int Physics41Data71908View1 __asm__("D_80071908");
extern void *(*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics41Player130View1 __asm__("D_80070328+0x130");
extern int Physics41Player144View2 __asm__("D_80070328+0x144");
extern short Physics41Player148View1 __asm__("D_80070328+0x148");
extern short Physics41Player14AView1 __asm__("D_80070328+0x14A");
extern int Physics41Player14CView1 __asm__("D_80070328+0x14C");
extern int Physics41Player150View1 __asm__("D_80070328+0x150");
extern int Physics41Player154View1 __asm__("D_80070328+0x154");
extern int Physics41Player160View1 __asm__("D_80070328+0x160");
extern int Physics41Player48View1 __asm__("D_80070328+0x48");
extern int Physics41Player4CView2 __asm__("D_80070328+0x4C");
extern int Physics41Player5CView2 __asm__("D_80070328+0x5C");
extern int Physics41Player60View2 __asm__("D_80070328+0x60");
extern int Physics41Player64View2 __asm__("D_80070328+0x64");
extern int Physics41Player8View1 __asm__("D_80070328+0x8");
extern int Physics41Player88View1 __asm__("D_80070328+0x88");
extern int Physics41Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics41Player90View1 __asm__("D_80070328+0x90");
extern int Physics41Player94View2 __asm__("D_80070328+0x94");
extern int Physics41PlayerA8View2 __asm__("D_80070328+0xA8");
extern int Physics41PlayerACView2 __asm__("D_80070328+0xAC");
extern int Physics41PlayerB0View2 __asm__("D_80070328+0xB0");
extern int Physics41PlayerF8View1 __asm__("D_80070328+0xF8");
extern int Physics41Player148View2 __asm__("D_80070328+0x148");
extern int Physics41Player210View1 __asm__("D_80070328+0x210");
extern int Physics41Player220View1 __asm__("D_80070328+0x220");
extern int Physics41Player98View1 __asm__("D_80070328+0x98");
extern int Physics41PlayerB8View2 __asm__("D_80070328+0xB8");
extern int Physics41PlayerCCView1 __asm__("D_80070328+0xCC");
extern int Physics41PlayerD0View1 __asm__("D_80070328+0xD0");
extern int Physics41PlayerE4View1 __asm__("D_80070328+0xE4");
extern unsigned char Physics41PlayerFCView2 __asm__("D_80070328+0xFC");
int Physics41Call40D10View3() __asm__("func_80040D10");
int Physics41Call410F8View2() __asm__("func_800410F8");
int Physics41Call41580View3() __asm__("func_80041580");
int Physics41Call417FCView4() __asm__("func_800417FC");
int Physics41Call41848View3() __asm__("func_80041848");
int Physics41Call41B64View4() __asm__("func_80041B64");
int Physics41Call4EA2CView4() __asm__("func_8004EA2C");
int Physics41Call4ED6CView1() __asm__("func_8004ED6C");
int Physics41Call4F110View1() __asm__("func_8004F110");
int Physics41Call4F168View4() __asm__("func_8004F168");
int Physics41Call4F178View5() __asm__("func_8004F178");
int Physics41Call4F194View5() __asm__("func_8004F194");
int Physics41CallRandView1() __asm__("rand");
extern int* Physics41Data6C570View2 __asm__("D_8006C570");
extern int Physics41Data6C640View2 __asm__("D_8006C640");
extern int Physics41Data6E044View3 __asm__("D_8006E044");
extern unsigned char Physics41Player0View4 __asm__("D_80070328");
extern void *(*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics41Player8CView2 __asm__("D_80070328+0x8C");
extern int Physics41Player158View1 __asm__("D_80070328+0x158");
extern int Physics41Player20CView2 __asm__("D_80070328+0x20C");
extern void *(*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics41Player8CView3 __asm__("D_80070328+0x8C");
extern void *(*Physics44_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Physics44Slot4454)() __asm__("unk_ovlheader_80074454");
extern int (*Physics44Slot432C)() __asm__("unk_ovlheader_8007432C");
extern void *Physics41Player250View1 __asm__("D_80070328+0x250");
extern int Physics41Player88View2 __asm__("D_80070328+0x88");
extern int Physics41PlayerE8View1 __asm__("D_80070328+0xE8");
extern void *(*Physics14_SpawnParticle)() __asm__("SpawnParticle");
void func_level_41_8008FD90(int slotIndex) {
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
        int sp10,sp14,sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4,spB8,spBC,spC0,spC4,spC8,spCC,spD0,spD4,spD8,spDC,spE0,spE4,spE8,spEC,spF0,spF4,spF8,spFC,sp100,sp104,sp108,sp10C,sp110,sp114,sp118,sp11C,sp120,sp124;
    }
    originalFrame;
    register void *globalVector80 __asm__("$16");
    register void *globalVector80State20 __asm__("$16");
    register void *globalVector8CState20 __asm__("$18");
    register void *globalVector8C __asm__("$18");
    register void *var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$19");
    int temp_v0_4;
    int temp_v0_6;
    register int workWord3 __asm__("$3");
    register void *globalField4CPointer __asm__("$16");
    register void *globalFieldB8PointerState1A __asm__("$16");
    register void *globalFieldB8PointerState20 __asm__("$16");
    register void *globalFieldA4Pointer __asm__("$17");
    void *temp_v0_7;
    void *raw34_temp_s1_2;
    int raw34_temp_v0_6;
    int raw34_temp_v0_7;
    int raw34_temp_v0_8;
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
    globalPointer=&Physics41Data6E548View1;
    workWord2+=(int)globalPointer;
    __asm__("":"=r"(workWord2):"0"(workWord2));
    Physics41Data6C570View1=(void*)workWord2;
    workWord2=Physics41Field(&Physics41Player0View1,int*,0x54);
    stateWord3=Physics41Field(&Physics41Player0View1,int*,0x48);
    combinedIndex=workWord2+savedSlotIndex;
    switch(stateWord3){
        default:return;
    case 20:case 53:case 54:globalVector80 = &Physics41Player0View1 + 0x80;
        Physics41Call4F168View1(globalVector80);
        Physics41Call4F168View1(globalVector80 + 0xC);
        if (Physics41Data6E044View1 != 7) {
            Physics41Call40D10View1(0x1200);
            Physics41Call416F4View1();
            Physics41Call41580View1(0x5A, 0x10);
            return;
        }
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
            workWord3=Physics41Data6E344View1;
            workWord2=13;
            if(workWord3==workWord2){
                workWord2=Physics41Data6C514View1;
                if(workWord2)return;
            }
            vectorAt30=&Physics41Player0View3+8;
            workWord3=Physics41Field(vectorAt30,int*,0);
            workWord2=Physics41Field(&Physics41Player0View3,int*,0x144);
            numeric4=workWord3-workWord2;
            workWord2=numeric4<1024;
            if(!workWord2)goto beyond19;
            workWord2=Physics41Player94View1;
            workWord2+=128;
            Physics41Player94View1=workWord2;
            workWord2=workWord2<4801;
            __asm__("":"=r"(numeric4):"0"(numeric4),"r"(workWord2));
            if(!workWord2){
                workWord2=4800;
                Physics41Player94View1=workWord2;
            }
            product19=numeric4*numeric4;
            call4=&originalFrame.sp10;
            workWord3=Physics41Field(&Physics41Player0View3,int*,0x148);
            __asm__ volatile(""::"r"(workWord2),"r"(workWord3),"r"(call4):"memory");
            workWord2=product19>>11;
            angle16=workWord2+workWord3;
            Physics41Player64View1=angle16;
            __asm__ volatile("":"=r"(vectorAt30):"0"(vectorAt30),"r"(call4):"memory");
            Physics41Call4F178View3(call4,vectorAt30+340);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics41Call4F1C8View3(call4,call5,vectorAt30-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            workWord2=Physics41Call4EDE8View3(call4,call5);
            numeric6=workWord2;
            workWord2=numeric6<1025;
            call4=&originalFrame.sp10;
            if(workWord2)goto commit19;
            call5=(void*)numeric6;
            __asm__ volatile(""::"i"(0x8008FF30):"memory");
            numeric6=1024;
            goto limit19;
            beyond19:numeric5=Physics41Field(&Physics41Player0View3,int*,0x14C);
            workWord2=workWord3-numeric5;
            workWord2=workWord2<-1024;
            numeric6=numeric5-workWord3;
            if(!workWord2)goto curve19;
            __asm__ volatile("":"=r"(numeric6):"0"(numeric6),"i"(0x8008FF54));
            workWord2=Physics41Player4CView1;
            workWord3=1;
            if(!workWord2){
                workWord2=Physics41Field(&Physics41Player0View3,int*,0x148);
                Physics41Player4CView1=workWord3;
                workWord2+=512;
                Physics41Field(&Physics41Player0View3,int*,0x148)=workWord2;
            }
            workWord2=Physics41Player94View1;
            workWord2+=128;
            Physics41Player94View1=workWord2;
            workWord2=workWord2<4801;
            if(!workWord2)Physics41Player94View1=4800;
            workWord2=Physics41Field(&Physics41Player0View3,int*,0x150);
            numeric6=numeric4-1024;
            workWord3=workWord2*numeric6;
            workWord2=Physics41Field(&Physics41Player0View3,int*,0x154);
            workWord2=workWord3/workWord2;
            call4=&originalFrame.sp10;
            workWord3=Physics41Field(&Physics41Player0View3,int*,0x148);
            angle16=workWord3+workWord2;
            workWord2=(numeric6<<10)>>10;
            workWord2=angle16+workWord2;
            angle16=workWord2&4095;
            Physics41Player64View1=angle16;
            Physics41Call4F178View3(call4,vectorAt30+340);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics41Call4F1C8View3(call4,call5,vectorAt30-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            workWord2=Physics41Call4EDE8View3(call4,call5);
            numeric6=workWord2;
            workWord2=numeric6<1025;
            call4=&originalFrame.sp10;
            if(workWord2)goto commit19;
            call5=(void*)numeric6;
            __asm__ volatile(""::"i"(0x80090064):"memory");
            numeric6=1024;
            goto limit19;
            curve19:__asm__ volatile("":"=r"(numeric6):"0"(numeric6),"i"(0x8009006C));
            workWord2=(numeric6*4800)>>10;
            Physics41Player94View1=workWord2;
            workWord2=Physics41Player16CView1;
            numeric7=Physics41Field(&Physics41Player0View3,int*,0x168);
            workWord3=Physics41Field(&Physics41Player0View3,int*,0x158);
            workWord2&=127;
            numeric4=numeric7<<1;
            Physics41Player16CView1=workWord2;
            workWord2=*(short*)(&Physics41Data65920View1+numeric4);
            workWord3+=1024;
            product10=workWord3*workWord2;
            square8=numeric6*numeric6;
            workWord2=product10>>12;
            originalFrame.sp10=workWord2;
            workWord2=*(short*)(&Physics41Data658A0View1+numeric4);
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
            Physics41Call4F194View3(call4,call5,numeric6,numeric7);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics41Player64View1=angle16;
            Physics41Call4F1C8View3(call4,call5,vectorAt30-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            workWord2=Physics41Call4EDE8View3(call4,call5);
            numeric6=workWord2;
            workWord2=numeric6<2049;
            call4=&originalFrame.sp10;
            if(workWord2)goto commit19;
            call5=(void*)numeric6;
            numeric6=2048;
            limit19:Physics41Call4F08CView3(call4,call5,numeric6);
            commit19:workWord2=originalFrame.sp10;
            workWord3=originalFrame.sp14;
            Physics41Field(&Physics41Player0View3,int*,0x8C)=workWord2;
            Physics41Field(&Physics41Player0View3,int*,0x90)=workWord3;
            return;
        }
    case 29:Physics41Call4F168View3(&originalFrame.sp20);
        raw34_temp_s1_2 = &Physics41Player0View3 + 0x8C;
        Physics41Call4F1C8View3(&originalFrame.sp20, &originalFrame.sp20, raw34_temp_s1_2);
        if (Physics41Field(&Physics41Player0View3, int *, 0xB8) != 0) {
            originalFrame.sp28 = 0;
            raw34_temp_v0_6 = Physics41Call4EDE8View3(&originalFrame.sp20, 0);
            if (raw34_temp_v0_6 >= 0x41) {
                Physics41Call4F08CView3(&originalFrame.sp20, raw34_temp_v0_6, 0x40);
            }
            originalFrame.sp28 = -0xC0;
            call4=raw34_temp_s1_2-12;
            call5=raw34_temp_s1_2;
            call6=&originalFrame.sp20;
            goto vector29;
        }
        else {
            raw34_temp_v0_7 = Physics41Call4EDE8View3(&originalFrame.sp20, 1);
            if (raw34_temp_v0_7 >= 0x101) {
                Physics41Call4F08CView3(&originalFrame.sp20, raw34_temp_v0_7, 0x100);
            }
            Physics41Call4F194View3(raw34_temp_s1_2, raw34_temp_s1_2, &originalFrame.sp20);
            call4=raw34_temp_s1_2-12;
            call5=raw34_temp_s1_2;
            __asm__("":"=r"(call5):"0"(call5));
            call6=call5+92;
        }
        goto vector29;
    case 26:globalFieldB8PointerState1A = &Physics41Player0View3 + 0xB8;
        if (Physics41Field(&Physics41Player0View3, int *, 0xB8) != 0) {
            raw34_temp_v0_8 = Physics41Field(&Physics41Player0View3, int *, 0x94) - 0x600;
            Physics41Field(&Physics41Player0View3, int *, 0x94) = raw34_temp_v0_8;
            if (raw34_temp_v0_8 < -0x2300) {
                Physics41Field(&Physics41Player0View3, int *, 0x94) = -0x2300;
            }
            Physics41Call4F178View3(globalFieldB8PointerState1A - 0x38, globalFieldB8PointerState1A - 0x2C);
            return;
        }
        goto block_154;
    case 32:globalFieldB8PointerState20 = &Physics41Player0View1 + 0xB8;
        if (Physics41Field(&Physics41Player0View1, int *, 0xB8) != 0) {
            vectorAt30=&originalFrame.sp30;
            Physics41Call4F168View1(vectorAt30);
            call4=vectorAt30;
            call5=vectorAt30;
            __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
            globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
            Physics41Call4F1C8View1(call4, call5, globalVector8CState20);
            originalFrame.sp38 = 0;
            temp_v0_6 = Physics41Call4EDE8View1(&originalFrame.sp30, 0);
            if (temp_v0_6 >= 0x41) {
                Physics41Call4F08CView1(&originalFrame.sp30, temp_v0_6, 0x40);
            }
            originalFrame.sp38 = -0xC0;
            globalVector80State20 = globalFieldB8PointerState20 - 0x38;
            Physics41Call4F194View1(globalVector80State20, globalVector8CState20, &originalFrame.sp30);
            Physics41Call4F178View1(globalVector8CState20, globalVector80State20);
        }
        else {
            Physics41Call4F168View1(globalFieldB8PointerState20 - 0x38);
            Physics41Call4F168View1(globalFieldB8PointerState20 - 0x2C);
        }
        if (Physics41Field(&Physics41Player0View1, int *, 0x94) < -0x2300) {
            Physics41Field(&Physics41Player0View1, int *, 0x94) = -0x2300;
        }
        if ((Physics41Field(&Physics41Player0View1, int *, 0x48) == 0x3A) && (Controller88028_SpawnParticle != 0) && (Physics41Data6C640View1 & 1)) {
            originalFrame.sp40 = 0;
            originalFrame.sp44 = 0;
            originalFrame.sp48 = 0xE;
            Physics41Call4F178View1(&originalFrame.sp50, (&Physics41Player0View1 + 0x94) - 0x94);
            originalFrame.sp50 += Physics41Call363DCView1(0, 0x12C);
            originalFrame.sp54 += Physics41Call363DCView1(0, 0x12C);
            originalFrame.sp58 += Physics41Call363DCView1(0, 0x12C);
            temp_v0_7 = Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp50, &originalFrame.sp40);
            Physics41Field(temp_v0_7, signed char *, 2) = 6;
            Physics41Field(temp_v0_7, signed char *, 0xA) = 0x20;
        }
        break;
    case 33:case 34:case 35:{
            register int numeric4 __asm__("$4");
            register int numeric6 __asm__("$6");
            register int numeric5 __asm__("$5");
            register int delta18 __asm__("$18");
            register int delta19 __asm__("$19");
            register void *pointer17 __asm__("$17");
            register void *pointer16 __asm__("$16");
            register int limit16 __asm__("$16");
            int originalLow;
            call4=&originalFrame.sp40;
            __asm__ volatile(""::"r"(call4):"memory");
            pointer17=&Physics41Player154View1;
            Physics41Call410F8View1(call4,pointer17,0);
            workWord2=originalFrame.sp44;
            numeric4=Physics41Player94View2;
            workWord2=-workWord2;
            workWord3=workWord2*5;
            workWord3<<=2;
            delta18=workWord3>>7;
            numeric4>>=3;
            workWord3=originalFrame.sp40;
            numeric4-=1024;
            originalFrame.sp50=numeric4;
            workWord2=workWord3*5;
            workWord2<<=2;
            delta19=workWord2>>7;
            if(numeric4<0){
                pointer16=&originalFrame.sp48;
                call4=pointer16;
                call5=pointer16;
                __asm__ volatile("":"=r"(pointer17):"0"(pointer17),"r"(call4),"r"(call5):"memory");
                pointer17-=340;
                call6=pointer17;
                workWord2=Physics41Player8CView1;
                workWord3=Physics41Player90View1;
                workWord2>>=3;
                workWord3>>=3;
                originalFrame.sp48=workWord2;
                originalFrame.sp4C=workWord3;
                Physics41Call4F194View4(call4,call5,call6);
                if(!Physics41Call13E38View1(pointer17,pointer16,2)){
                    workWord2=Physics41Player8View1;
                    workWord3=Physics41Data71908View1;
                    workWord2-=workWord3;
                    workWord2>>=3;
                    originalFrame.sp44=workWord2;
                    workWord2=workWord2<11;
                    if(!workWord2)originalFrame.sp44=10;
                    __asm__ volatile("":::"memory");
                    workWord2=originalFrame.sp44;
                    delta18+=workWord2;
                }
            }
            workWord2=Physics41PlayerF8View1;
            workWord3=Physics41Player8View1;
            workWord3=workWord2-workWord3;
            __asm__("":"=r"(workWord3):"0"(workWord3));
            workWord2=workWord3<4096;
            if(workWord2){
                workWord2=workWord3*3;
                workWord2<<=3;
                workWord2+=workWord3;
                workWord2<<=5;
                workWord3=Physics41Player60View2;
                numeric4=workWord2>>12;
                workWord3=numeric4-workWord3;
                numeric4=workWord3&4095;
                workWord2=numeric4<2049;
                if(!workWord2){
                    numeric4-=4096;
                    workWord2=numeric4<delta18;
                }
                else workWord2=numeric4<delta18;
                if(workWord2)delta18=numeric4;
            }
            call4=&Physics41Player64View2;
            workWord2=Physics41Field(call4,int*,0);
            workWord3=Physics41Player60View2;
            Physics41PlayerA8View2=delta19;
            workWord2+=delta19;
            workWord2&=4095;
            workWord3+=delta18;
            workWord3&=4095;
            Physics41Field(call4,int*,0)=workWord2;
            workWord2=workWord3<2049;
            Physics41Player60View2=workWord3;
            if(!workWord2){
                workWord2=workWord3-4096;
                __asm__("":"=r"(workWord2):"0"(workWord2));
                Physics41Player60View2=workWord2;
            }
            workWord2=Physics41Player60View2;
            workWord2=workWord2<-800;
            if(workWord2)Physics41Player60View2=-800;
            workWord2=Physics41Player60View2;
            workWord2=workWord2<801;
            if(!workWord2)Physics41Player60View2=800;
            workWord2=Physics41Data6FA38View1;
            if(workWord2>=0)goto nonnegative33;
            workWord3=Physics41Player60View2;
            if(workWord3>=0)goto positive33;
            numeric4=Physics41Data67634View1;
            workWord2=Physics41Data67630View1;
            workWord2=numeric4-workWord2;
            goto quotient33;
            positive33:if(workWord3<=0)goto zero33;
            workWord2=Physics41Data67638View1;
            numeric4=Physics41Data67634View1;
            workWord2-=numeric4;
            quotient33:workWord2=workWord3*workWord2;
            workWord3=workWord2/800;
            numeric4+=workWord3;
            Physics41PlayerACView2=numeric4;
            goto modifier33;
            zero33:workWord2=Physics41Data67634View1;
            Physics41PlayerACView2=workWord2;
            modifier33:speed33:call5=&Physics41Player144View2;
            numeric6=Physics41PlayerACView2;
            numeric4=Physics41PlayerB0View2;
            workWord3=Physics41Field(call5,int*,0);
            workWord2=numeric6-numeric4;
            workWord2-=workWord3;
            workWord2=(workWord2<<6)>>6;
            workWord3+=workWord2;
            Physics41Field(call5,int*,0)=workWord3;
            workWord3>>=6;
            numeric4+=workWord3;
            Physics41PlayerB0View2=numeric4;
            numeric4=numeric4<2048;
            if(numeric4)Physics41PlayerB0View2=2048;
            workWord2=Physics41PlayerB0View2;
            workWord2=workWord2<19201;
            if(!workWord2)Physics41PlayerB0View2=19200;
            workWord2=Physics41Player148View1;
            workWord3=workWord2;
            if(!workWord2)goto rotationCompare33;
            workWord2=0x60000;
            Physics41Player130View1=workWord2;
            workWord2=workWord3-1;
            Physics41Player148View1=workWord2;
            workWord2<<=16;
            if(workWord2>0){
                workWord2=numeric6+8192;
                goto positiveNegative33;
            }
            workWord3=Physics41PlayerB0View2;
            workWord2=workWord3-numeric6;
            workWord2=workWord2<192;
            if(!workWord2)goto decrementNegative33;
            workWord2=numeric6+8192;
            Physics41PlayerB0View2=workWord2;
            Physics41Player148View1=0;
            goto rotation33;
            decrementNegative33:workWord2=workWord3-192;
            Physics41PlayerB0View2=workWord2;
            workWord2=1;
            Physics41Player148View1=workWord2;
            goto rotation33;
            positiveNegative33:Physics41PlayerB0View2=workWord2;
            goto rotation33;
            nonnegative33:numeric4=Physics41Player8View1;
            limit16=0;
            workWord2=Physics41Call4E4E4View1(numeric4);
            workWord3=Physics41Player148View1;
            __asm__ volatile(""::"r"(workWord3),"r"(workWord2):"memory");
            numeric4=workWord2;
            __asm__("":"=r"(numeric4):"0"(numeric4));
            Physics41PlayerACView2=numeric4;
            numeric5=workWord3;
            if(!workWord3)goto zeroCounter33;
            workWord2=0x60000;
            Physics41Player130View1=workWord2;
            workWord2=numeric5-1;
            Physics41Player148View1=workWord2;
            workWord2<<=16;
            if(workWord2>0)goto positiveCounter33;
            workWord3=Physics41PlayerB0View2;
            workWord2=workWord3-numeric4;
            workWord2=workWord2<192;
            if(workWord2){
                workWord2=numeric4+8192;
                Physics41PlayerB0View2=workWord2;
                Physics41Player148View1=0;
                goto counterClamp33;
            }
            workWord2=workWord3-192;
            Physics41PlayerB0View2=workWord2;
            workWord2=1;
            Physics41Player148View1=workWord2;
            goto counterClamp33;
            positiveCounter33:workWord2=numeric4+8192;
            Physics41PlayerB0View2=workWord2;
            limit16=96;
            goto counterClamp33;
            zeroCounter33:Physics41PlayerB0View2=numeric4;
            __asm__ volatile("":"=r"(limit16):"0"(limit16):"$3","memory");
            Physics41Player130View1=0;
            counterClamp33:globalPointer=&Physics41PlayerB0View2;
            workWord2=Physics41Field(globalPointer,int*,0);
            workWord2=workWord2<22785;
            if(!workWord2)Physics41Field(globalPointer,int*,0)=22784;
            workWord2=Physics41Field(globalPointer,int*,0);
            workWord2=workWord2<2048;
            if(workWord2)Physics41Field(globalPointer,int*,0)=2048;
            numeric5=Physics41Player14CView1;
            workWord3=Physics41Player150View1;
            workWord2=limit16-numeric5;
            workWord2<<=4;
            numeric4=workWord3<<5;
            workWord2-=numeric4;
            workWord2>>=6;
            workWord3+=workWord2;
            Physics41Player150View1=workWord3;
            workWord3>>=4;
            numeric5+=workWord3;
            Physics41Player14CView1=numeric5;
            if(numeric5<0)Physics41Player14CView1=0;
            workWord2=Physics41Player14CView1;
            workWord2=workWord2<97;
            if(!workWord2)Physics41Player14CView1=96;
            rotation33:workWord2=Physics41Player148View1;
            rotationCompare33:__asm__ volatile(""::"i"(0x8009093C):"memory");
            workWord2=workWord2<2;
            if(workWord2)goto spring33;
            workWord3=Physics41Player14AView1;
            __asm__("":"=r"(workWord3):"0"(workWord3));
            workWord2=workWord3*3;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            workWord3=Physics41Player5CView2;
            workWord2<<=11;
            Physics41Player154View1=workWord2;
            workWord2>>=6;
            workWord3+=workWord2;
            workWord3&=4095;
            workWord2=workWord3<2049;
            Physics41Player5CView2=workWord3;
            if(workWord2)goto rotationDone33;
            workWord2=workWord3-4096;
            goto storeAngle33;
            spring33:workWord2=Physics41Call4EA2CView3(Physics41Player60View2);
            workWord2<<=5;
            workWord2=-workWord2;
            originalLow=delta19*workWord2;
            workWord3=Physics41Player154View1;
            numeric5=Physics41Player5CView2;
            workWord2=(workWord3<<4)>>6;
            numeric4=originalLow>>12;
            numeric4-=workWord2;
            workWord2=(numeric5<<6)>>6;
            numeric4-=workWord2;
            workWord3+=numeric4;
            Physics41Player154View1=workWord3;
            workWord3>>=6;
            numeric5+=workWord3;
            numeric5&=4095;
            workWord2=numeric5<2049;
            Physics41Player5CView2=numeric5;
            if(workWord2)goto rotationDone33;
            workWord2=numeric5-4096;
            storeAngle33:Physics41Player5CView2=workWord2;
            rotationDone33:Physics41Call41848View2();
            call5=&Physics41Player4CView2;
            numeric4=Physics41Field(call5,int*,0);
            if(numeric4)goto active33;
            workWord2=(int)Physics41Data6C570View1;
            workWord2=Physics41Field((void*)workWord2,int*,4)&64;
            if(!workWord2)goto end33;
            workWord2=Physics41PlayerF8View1;
            workWord3=Physics41Player8View1;
            workWord2-=512;
            workWord3=workWord3<workWord2;
            if(!workWord3)goto end33;
            workWord3=Physics41Player48View1;
            workWord2=33;
            if(workWord3!=workWord2)goto end33;
            workWord2=1;
            Physics41Field(call5,int*,0)=workWord2;
            __asm__ volatile("":::"$4","memory");
            Physics41Player160View1=0;
            goto end33;
            active33:workWord2=Physics41Player8View1;
            workWord3=Physics41PlayerF8View1;
            workWord2=workWord2<workWord3;
            if(workWord2){
                workWord2=1;
                goto activeRemainder33;
            }
            workWord2=1;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics41Field(call5,int*,0)=0;
            goto end33;
            activeRemainder33:if(numeric4!=workWord2)goto decline33;
            workWord2=Physics41Player160View1;
            workWord2+=512;
            Physics41Player160View1=workWord2;
            workWord2=workWord2<6144;
            if(!workWord2){
                workWord2=6144;
                Physics41Player160View1=workWord2;
                workWord2=2;
                Physics41Field(call5,int*,0)=workWord2;
            }
            goto add88;
            decline33:workWord2=Physics41Player160View1;
            workWord2-=256;
            Physics41Player160View1=workWord2;
            if(workWord2<=0){
                Physics41Player160View1=0;
                Physics41Field(call5,int*,0)=0;
            }
            add88:{
                register void *pointer2 __asm__("$2");
                pointer2=&Physics41Player88View1;
                workWord3=Physics41Field(pointer2,int*,0);
                numeric4=Physics41Player160View1;
                workWord3+=numeric4;
                Physics41Field(pointer2,int*,0)=workWord3;
            }
            end33:Physics41Call41B64View3();
            return;
        }
    case 40:{
            register int numeric4 __asm__("$4");
            call5=&Physics41Player20CView2;
            __asm__("":"=r"(call5):"0"(call5));
            workWord2=Physics41Field(call5,int*,0)&64;
            call4=&originalFrame.sp60;
            if(workWord2)goto block_132;
            call5-=192;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics41Call410F8View2(call4,call5,0);
            workWord3=Physics41Player4CView1;
            workWord2=1;
            if(workWord3==workWord2){
                workWord2=512;
                workWord3=Physics41Player60View1;
                numeric4=Physics41Player144View1;
                workWord2-=workWord3;
                workWord3=numeric4<<4;
                workWord2-=workWord3;
                workWord3=workWord2&4095;
                originalFrame.sp64=workWord3;
                workWord2=workWord3<2049;
                if(!workWord2){
                    workWord2=workWord3-4096;
                    __asm__("":"=r"(workWord2):"0"(workWord2));
                    originalFrame.sp64=workWord2;
                }
                __asm__ volatile("":::"memory");
                workWord2=originalFrame.sp64;
                workWord3=numeric4+1;
                Physics41Player144View1=workWord3;
                workWord3=workWord3<21;
                workWord2=(workWord2<<7)>>8;
                originalFrame.sp64=workWord2;
                if(!workWord3){
                    __asm__ volatile("":"=r"(workWord3):"0"(workWord3));
                    Physics41Player4CView1=0;
                }
            }
            raw21_temp_s1_4 = (int) (originalFrame.sp60 * 0x14) >> 7;
            Physics41Field(&Physics41Player0View4, int *, 0x64) = (int) ((Physics41Field(&Physics41Player0View4, int *, 0x64) + raw21_temp_s1_4) & 0xFFF);
            raw21_temp_v1_6 = (Physics41Field(&Physics41Player0View4, int *, 0x60) + ((int) (originalFrame.sp64 * -0xF) >> 7)) & 0xFFF;
            Physics41Field(&Physics41Player0View4, int *, 0x60) = raw21_temp_v1_6;
            if (raw21_temp_v1_6 >= 0x801) {
                Physics41Field(&Physics41Player0View4, int *, 0x60) = (int) (raw21_temp_v1_6 - 0x1000);
            }
            if (Physics41Field(&Physics41Player0View4, int *, 0x60) < -0x320) {
                Physics41Field(&Physics41Player0View4, int *, 0x60) = -0x320;
            }
            if (Physics41Field(&Physics41Player0View4, int *, 0x60) >= 0x321) {
                Physics41Field(&Physics41Player0View4, int *, 0x60) = 0x320;
            }
            if ((*Physics41Data6C570View2 & 0x40) || (Physics41Field(&Physics41Player0View4, int *, 0x4C) == 1)) {
                Physics41Field(&Physics41Player0View4, int *, 0xAC) = 0xE00;
            }
            else {
                Physics41Field(&Physics41Player0View4, int *, 0xAC) = 0;
            }
            if (Physics41Field(&Physics41Player0View4, int *, 0x4C) == 2) {
                Physics41Call417FCView4(0xC0, 0xC0);
                if (Physics41Field(&Physics41Player0View4, int *, 0xB0) < 0xE01) {
                    Physics41Field(&Physics41Player0View4, int *, 0x4C) = 0;
                }
            }
            else {
                Physics41Call417FCView4(0xC0, 0x30);
            }
            raw21_temp_s0_7 = &Physics41Player0View4 + 0x60;
            raw21_temp_a0_5 = (((int) (raw21_temp_s1_4 * -(Physics41Call4EA2CView4(Physics41Field(&Physics41Player0View4, int *, 0x60)) << 5)) >> 0xC) - ((int) (Physics41Field(&Physics41Player0View4, int *, 0x14C) * 0x10) >> 6)) - ((int) (Physics41Field(&Physics41Player0View4, int *, 0x5C) << 6) >> 6);
            raw21_temp_v1_7 = Physics41Field(&Physics41Player0View4, int *, 0x14C) + raw21_temp_a0_5;
            Physics41Field(&Physics41Player0View4, int *, 0x14C) = raw21_temp_v1_7;
            raw21_temp_a1_2 = (Physics41Field(&Physics41Player0View4, int *, 0x5C) + (raw21_temp_v1_7 >> 6)) & 0xFFF;
            Physics41Field(&Physics41Player0View4, int *, 0x5C) = raw21_temp_a1_2;
            if (raw21_temp_a1_2 >= 0x801) {
                Physics41Field(&Physics41Player0View4, int *, 0x5C) = (int) (raw21_temp_a1_2 - 0x1000);
            }
            if (Physics41Field(&Physics41Player0View4, int *, 0x5C) < -0x300) {
                Physics41Field(&Physics41Player0View4, int *, 0x5C) = -0x300;
            }
            if (Physics41Field(&Physics41Player0View4, int *, 0x5C) >= 0x301) {
                Physics41Field(&Physics41Player0View4, int *, 0x5C) = 0x300;
            }
            Physics41Call41848View3(raw21_temp_a0_5, raw21_temp_a1_2);
            Physics41Call4F178View5(raw21_temp_s0_7 + 0x2C, raw21_temp_s0_7 + 0x20);
            workWord2=Physics41CallRandView1()&31;
            if(workWord2)goto counter40;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            particleCall3=Physics21_SpawnParticle;
            call4=(void*)1;
            if(!particleCall3)goto counter40;
            call5=(void*)44;
            call6=&originalFrame.sp68;
            particleArg7=0;
            __asm__("":"=r"(particleArg7):"0"(particleArg7),"r"(call5),"r"(call6));
            workWord2=544;
            originalFrame.sp68=workWord2;
            workWord2=64;
            originalFrame.sp6C=0;
            originalFrame.sp70=workWord2;
            particleCall3(call4,call5,call6,particleArg7);
            goto counter40;
            counter40:globalPointer=&Physics41Player158View1;
            workWord2=Physics41Field(globalPointer,int*,0);
            __asm__("":"=r"(workWord2):"0"(workWord2),"i"(0x80090E6C));
            workWord2++;
            goto store95;
        }
    case 41:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            int product41;
            raw21_temp_s1_5 = &Physics41Player0View4 + 0x20C;
            if (!(Physics41Field(&Physics41Player0View4, int *, 0x20C) & 0x40)) {
                if (Physics41Data6E044View3 != 7) {
                    Physics41Call410F8View2(&originalFrame.sp68, raw21_temp_s1_5 - 0xC0, 0);
                    workWord3=originalFrame.sp68;
                    numeric4=originalFrame.sp6C;
                    workWord2=workWord3*5;
                    workWord2<<=2;
                    raw21_temp_s0_8=workWord2>>7;
                    workWord2=numeric4<<4;
                    numeric4-=workWord2;
                    numeric4>>=7;
                    workWord3=Physics41Player64View1;
                    workWord2=Physics41Player60View1;
                    workWord3+=raw21_temp_s0_8;
                    workWord3&=4095;
                    workWord2+=numeric4;
                    Physics41Player64View1=workWord3;
                    workWord3=workWord2&4095;
                    workWord2=workWord3<2049;
                    Physics41Player60View1=workWord3;
                    if(!workWord2){
                        workWord2=workWord3-4096;
                        __asm__("":"=r"(workWord2):"0"(workWord2));
                        Physics41Player60View1=workWord2;
                    }
                    if (Physics41Field(&Physics41Player0View4, int *, 0x60) < -0x320) {
                        Physics41Field(&Physics41Player0View4, int *, 0x60) = -0x320;
                    }
                    if (Physics41Field(&Physics41Player0View4, int *, 0x60) >= 0x321) {
                        Physics41Field(&Physics41Player0View4, int *, 0x60) = 0x320;
                    }
                    workWord2=Physics41Call4EA2CView4(Physics41Player60View1);
                    workWord2<<=5;
                    workWord2=-workWord2;
                    product41=raw21_temp_s0_8*workWord2;
                    workWord3=Physics41Field(raw21_temp_s1_5,int*,-192);
                    numeric5=Physics41Player5CView1;
                    workWord2=(workWord3<<4)>>6;
                    numeric4=product41>>12;
                    numeric4-=workWord2;
                    workWord2=(numeric5<<6)>>6;
                    numeric4-=workWord2;
                    workWord3+=numeric4;
                    Physics41Field(raw21_temp_s1_5,int*,-192)=workWord3;
                    workWord3>>=6;
                    numeric5+=workWord3;
                    numeric5&=4095;
                    workWord2=numeric5<2049;
                    Physics41Player5CView1=numeric5;
                    if(!workWord2){
                        workWord2=numeric5-4096;
                        __asm__("":"=r"(workWord2):"0"(workWord2));
                        Physics41Player5CView1=workWord2;
                    }
                    if (Physics41Field(&Physics41Player0View4, int *, 0x5C) < -0x300) {
                        Physics41Field(&Physics41Player0View4, int *, 0x5C) = -0x300;
                    }
                    if (Physics41Field(&Physics41Player0View4, int *, 0x5C) >= 0x301) {
                        Physics41Field(&Physics41Player0View4, int *, 0x5C) = 0x300;
                    }
                }
                raw21_temp_s0_9 = &Physics41Player0View4 + 0x80;
                Physics41Call4F168View4(raw21_temp_s0_9);
                Physics41Call4F168View4(raw21_temp_s0_9 + 0xC);
                workWord2=Physics41CallRandView1()&31;
                if(workWord2)goto block_130;
                __asm__("":"=r"(workWord2):"0"(workWord2));
                particleCall3=Physics21_SpawnParticle;
                call4=(void*)1;
                if(!particleCall3)goto block_130;
                call5=(void*)44;
                call6=&originalFrame.sp78;
                particleArg7=0;
                __asm__("":"=r"(particleArg7):"0"(particleArg7),"r"(call5),"r"(call6));
                workWord2=544;
                originalFrame.sp78=workWord2;
                workWord2=64;
                originalFrame.sp7C=0;
                originalFrame.sp80=workWord2;
                block_129:particleCall3(call4,call5,call6,particleArg7);
                block_130:globalPointer=&Physics41Player158View1;
                workWord2=Physics41Field(globalPointer,int*,0);
                __asm__("":"=r"(workWord2):"0"(workWord2),"i"(0x80091080));
                workWord2++;
                goto store95;
            }
            goto block_132;
        }
    case 42:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            call5=&Physics41Player20CView2;
            __asm__("":"=r"(call5):"0"(call5));
            workWord2=Physics41Field(call5,int*,0)&64;
            call4=&originalFrame.sp78;
            if(!workWord2)goto run42;
            block_132:Physics41PlayerACView1=0;
            Physics41PlayerB0View1=0;
            return;
            run42:call5-=192;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics41Call410F8View2(call4,call5,0);
            workWord3=Physics41Player4CView1;
            workWord2=1;
            if(workWord3==workWord2){
                workWord2=512;
                workWord3=Physics41Player60View1;
                numeric5=Physics41Player144View1;
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
                Physics41Player144View1=workWord3;
                workWord3=workWord3<13;
                workWord2=numeric4*3;
                workWord2<<=5;
                workWord2>>=8;
                originalFrame.sp7C=workWord2;
                if(!workWord3){
                    __asm__ volatile("":"=r"(workWord3):"0"(workWord3));
                    Physics41Player4CView1=0;
                }
            }
            raw21_temp_s1_6 = &Physics41Player0View4 + 0x64;
            raw21_temp_s0_10 = (int) (originalFrame.sp78 * 0x14) >> 7;
            Physics41Field(&Physics41Player0View4, int *, 0x64) = (int) ((Physics41Field(&Physics41Player0View4, int *, 0x64) + raw21_temp_s0_10) & 0xFFF);
            raw21_temp_v1_13 = (Physics41Field(&Physics41Player0View4, int *, 0x60) + ((int) (originalFrame.sp7C * -0xF) >> 7)) & 0xFFF;
            Physics41Field(&Physics41Player0View4, int *, 0x60) = raw21_temp_v1_13;
            if (raw21_temp_v1_13 >= 0x801) {
                Physics41Field(&Physics41Player0View4, int *, 0x60) = (int) (raw21_temp_v1_13 - 0x1000);
            }
            if (Physics41Field(&Physics41Player0View4, int *, 0x60) < -0x320) {
                Physics41Field(&Physics41Player0View4, int *, 0x60) = -0x320;
            }
            if (Physics41Field(&Physics41Player0View4, int *, 0x60) >= 0x321) {
                Physics41Field(&Physics41Player0View4, int *, 0x60) = 0x320;
            }
            Physics41Field(&Physics41Player0View4, int *, 0xAC) = 0x1C00;
            Physics41Call417FCView4(0x240, 0x30);
            raw21_temp_a0_6 = (((int) (raw21_temp_s0_10 * -(Physics41Call4EA2CView4(Physics41Field(&Physics41Player0View4, int *, 0x60)) << 5)) >> 0xC) - ((int) (Physics41Field(&Physics41Player0View4, int *, 0x14C) * 0x10) >> 6)) - ((int) (Physics41Field(&Physics41Player0View4, int *, 0x5C) << 6) >> 6);
            raw21_temp_v1_14 = Physics41Field(&Physics41Player0View4, int *, 0x14C) + raw21_temp_a0_6;
            Physics41Field(&Physics41Player0View4, int *, 0x14C) = raw21_temp_v1_14;
            raw21_temp_a1_3 = (Physics41Field(&Physics41Player0View4, int *, 0x5C) + (raw21_temp_v1_14 >> 6)) & 0xFFF;
            Physics41Field(&Physics41Player0View4, int *, 0x5C) = raw21_temp_a1_3;
            if (raw21_temp_a1_3 >= 0x801) {
                Physics41Field(&Physics41Player0View4, int *, 0x5C) = (int) (raw21_temp_a1_3 - 0x1000);
            }
            if (Physics41Field(&Physics41Player0View4, int *, 0x5C) < -0x300) {
                Physics41Field(&Physics41Player0View4, int *, 0x5C) = -0x300;
            }
            if (Physics41Field(&Physics41Player0View4, int *, 0x5C) >= 0x301) {
                Physics41Field(&Physics41Player0View4, int *, 0x5C) = 0x300;
            }
            Physics41Call41848View3(raw21_temp_a0_6, raw21_temp_a1_3);
            Physics41Call4F178View5(raw21_temp_s1_6 + 0x28, raw21_temp_s1_6 + 0x1C);
            if ((Physics21_SpawnParticle != 0) && (Physics41Field(&Physics41Player0View4, int *, 0xB4) >= 0x7D1)) {
                originalFrame.sp88 = -0x190;
                originalFrame.sp8C = 0x40 - (Physics41CallRandView1() & 0x7F);
                originalFrame.sp90 = -0x12C;
                Physics21_SpawnParticle(1, 0x2C, &originalFrame.sp88, 0);
                return;
            }
            break;
        }
    case 43:case 44:globalField4CPointer=&Physics41Player4CView1;
        __asm__("":"=r"(globalField4CPointer):"0"(globalField4CPointer));
        workWord3=Physics41Field(globalField4CPointer,int*,0);
        workWord2=1;
        if(workWord3!=workWord2)goto continue43;
        block_154:call4=&Physics41Player80View1;
        __asm__("":"=r"(call4):"0"(call4));
        Physics41Call4F168View4(call4);
        call4=&Physics41Player8CView2;
        __asm__("":"=r"(call4):"0"(call4));
        Physics41Call4F168View4(call4);
        return;
        continue43:workWord2=7;
        workWord3=Physics41Data6E044View3;
        if (workWord3 == workWord2) {
            Physics41Field(&Physics41Player0View4, int *, 0xB0) = 0;
        }
        else {
            Physics41Call40D10View3(0x980);
            raw21_var_v0_2 = Physics41Call41580View3(0x5A, 0x10);
            if (raw21_var_v0_2 < 0) {
                raw21_var_v0_2 = -raw21_var_v0_2;
            }
            if (raw21_var_v0_2 >= 0x201) {
                Physics41Field(&Physics41Player0View4, int *, 0xAC) = 0;
            }
            raw21_var_a0_2 = 0xC0;
            if (Physics41Field(&Physics41Player0View4, int *, 0xB0) >= 0xC81) {
                raw21_var_a0_2 = 0;
                raw21_var_a1_4 = 0xC0;
            }
            else {
                raw21_var_a1_4 = 0x40;
            }
            Physics41Call417FCView4(raw21_var_a0_2, raw21_var_a1_4);
        }
        raw21_temp_s0_11 = &Physics41Player0View4 + 0xB0;
        if (Physics41Field(&Physics41Player0View4, int *, 0xB0) != 0) {
            Physics41Call41848View3();
            Physics41Call41B64View4();
            Physics41Field(&Physics41Player0View4, int *, 0x94) = 0;
        }
        else {
            Physics41Call4F168View4(raw21_temp_s0_11 - 0x30);
            Physics41Call4F168View4(raw21_temp_s0_11 - 0x24);
        }
        if (Physics21_SpawnParticle != 0) {
            raw21_temp_s4 = &Physics41Player0View4 + 0x28;
            if (Physics41Field(&Physics41Player0View4, int *, 0x28) < 0) {
                if ((Physics41Field(&Physics41Player0View4, int *, 0xB0) >= 0x401) && (savedSlotIndex < 2) && (Physics41Data6C640View2 & 1)) {
                    Physics41Call4F178View5(&originalFrame.sp88, raw21_temp_s4 - 0x28);
                    originalFrame.sp9C = 0x40;
                    originalFrame.spA0 = 0;
                    originalFrame.sp98 = (int) Physics41Field(&Physics41Player0View4, int *, 0xB0) >> 5;
                    if (savedSlotIndex != 0) {
                        originalFrame.sp9C = -0x40;
                    }
                    raw21_temp_s2_3 = raw21_temp_s4 + 8;
                    Physics41Call4ED6CView1(raw21_temp_s2_3, &originalFrame.sp98, &originalFrame.spA8);
                    Physics41Call4F194View5(&originalFrame.sp88, &originalFrame.sp88, &originalFrame.spA8);
                    originalFrame.sp98 = 0;
                    originalFrame.sp90 = -Physics41Field(&Physics41Player0View4, int *, 0x28);
                    Physics41Call4ED6CView1(raw21_temp_s2_3, &originalFrame.sp98, &originalFrame.sp98);
                    Physics41Call4F110View1(&originalFrame.sp98, 3);
                    Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp88, &originalFrame.sp98);
                    if (!(Physics41CallRandView1() & 0x1F)) {
                        Physics21_SpawnParticle(1, 0x29, &originalFrame.sp88, 0);
                    }
                }
                else {
                    raw21_temp_s1_7 = &Physics41Player0View4 + 0xB0;
                    if ((Physics41Field(&Physics41Player0View4, int *, 0xB0) < 0x201) && (savedSlotIndex == 0) && !(Physics41Data6C640View2 & 7) && !(Physics41CallRandView1() & 3)) {
                        originalFrame.spB8 = 0x80;
                        __asm__("":"=r"(savedSlotIndex):"0"(savedSlotIndex));
                        originalFrame.spBC = 0;
                        originalFrame.spC0 = 0;
                        Physics41Call4ED6CView1(raw21_temp_s1_7 - 0x80, &originalFrame.spB8, &originalFrame.spB8);
                        Physics41Call4F194View5(&originalFrame.spB8, &originalFrame.spB8, raw21_temp_s1_7 - 0xB0);
                        originalFrame.spC0 = -Physics41Field(&Physics41Player0View4, int *, 0x28);
                        Physics21_SpawnParticle(1, 0x2B, &originalFrame.spB8, (int *)1);
                    }
                }
            }
        }
        raw21_temp_a1_4 = Physics41Field(&Physics41Player0View4, int *, 0x144) - ((int) ((Physics41Field(&Physics41Player0View4, int *, 0x148) * 2) + (Physics41Field(&Physics41Player0View4, int *, 0x144) * 0x14)) >> 8);
        raw21_temp_a0_7 = Physics41Field(&Physics41Player0View4, int *, 0x148) + raw21_temp_a1_4;
        Physics41Field(&Physics41Player0View4, int *, 0x144) = raw21_temp_a1_4;
        Physics41Field(&Physics41Player0View4, int *, 0x148) = raw21_temp_a0_7;
        if (raw21_temp_a0_7 >= 0x5901) {
            Physics41Field(&Physics41Player0View4, int *, 0x148) = 0x5900;
        }
        if (Physics41Field(&Physics41Player0View4, int *, 0x148) < -0x5900) {
            Physics41Field(&Physics41Player0View4, int *, 0x148) = -0x5900;
            return;
        }
        break;
    case 49:{
            register void *pointer17 __asm__("$17");
            register void *pointer18 __asm__("$18");
            register void *pointer16 __asm__("$16");
            int product49a,product49b;
            pointer17=&Physics41Player210View1;
            workWord2=Physics41Field(pointer17,int*,0)&1024;
            call6=(void*)1;
            if(!workWord2)goto noFlag49;
            __asm__("":"=r"(pointer17):"0"(pointer17));
            call4=(void*)Physics41Field(pointer17,int*,12);
            call5=(void*)Physics41Player220View1;
            __asm__ volatile("":"=r"(pointer17):"0"(pointer17),"r"(call4),"r"(call5):"memory");
            pointer17+=12;
            workWord2=Physics41Call4E880View1(call4,call5,call6);
            pointer16=&originalFrame.spA8;
            call4=pointer16;
            Physics41Player148View2=workWord2;
            Physics41Call4F178View4(call4,pointer17);
            Physics41Call4F0E8View1(pointer16,6);
            workWord2=Physics41Call4EDE8View4(pointer16,1);
            Physics41PlayerB0View2=workWord2;
            call4=(void*)128;
            goto prepare49;
            noFlag49:__asm__("":"=r"(call6):"0"(call6));
            workWord2=Physics41PlayerE4View1;
            workWord2=workWord2<11;
            if(workWord2)goto lowMode49;
            call4=(void*)Physics41PlayerCCView1;
            call5=(void*)Physics41PlayerD0View1;
            __asm__ volatile(""::"i"(0x80091764):"memory");
            call6=(void*)1;
            goto query49;
            lowMode49:call4=(void*)Physics41Player98View1;
            call5=call4;
            query49:workWord2=Physics41Call4E880View1(call4,call5,call6);
            Physics41Player148View2=workWord2;
            call4=(void*)128;
            prepare49:call5=(void*)192;
            __asm__ volatile(""::"r"(call5):"memory");
            pointer18=&Physics41PlayerACView2;
            workWord2=3840;
            Physics41Field(pointer18,int*,0)=workWord2;
            Physics41Call417FCView3(call4,call5);
            call4=(void*)Physics41Player148View2;
            pointer17=pointer18-44;
            workWord2=Physics41Call4EA2CView3(call4);
            workWord3=Physics41PlayerB0View2;
            product49a=workWord3*workWord2;
            call4=(void*)Physics41Player148View2;
            workWord2=product49a>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.spA8=workWord2;
            workWord2=Physics41Call4E9E4View3(call4);
            workWord3=Physics41PlayerB0View2;
            product49b=workWord3*workWord2;
            pointer16=&originalFrame.spA8;
            call4=pointer16;
            call5=pointer16;
            call6=pointer17;
            originalFrame.spB0=0;
            workWord2=product49b>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.spAC=workWord2;
            Physics41Call4F1C8View4(call4,call5,call6);
            originalFrame.spB0=0;
            call5=(void*)Physics41Call4EDE8View4(pointer16,0);
            workWord2=(int)call5<257;
            call4=pointer17;
            if(!workWord2){
                Physics41Call4F08CView4(pointer16,call5,256);
                call4=pointer17;
            }
            call5=pointer17;
            Physics41Call4F194View4(call4,call5,pointer16);
            workWord2=Physics41PlayerFCView2;
            if(workWord2)goto scalar95;
            workWord2=Physics41PlayerB8View2;
            call4=pointer18-32;
            if(!workWord2)goto vector49;
            goto scalar95;
            vector49:call5=pointer17;
            goto vector95Call;
        }
    case 57:if ((workWord2=combinedIndex<9)==0) {
            Physics41Field(&Physics41Player0View4, int *, 0x80) = (int) (Physics41Field(&Physics41Player0View4, int *, 0x8C) * 0xF8);
            Physics41Field(&Physics41Player0View4, int *, 0x84) = (int) (Physics41Field(&Physics41Player0View4, int *, 0x90) * 0xF8);
            Physics41Field(&Physics41Player0View4, int *, 0x88) = (int) (Physics41Field(&Physics41Player0View4, int *, 0x94) * 0xF8);
            Physics41Call4F110View1(&Physics41Player0View4 + 0x80, 8);
        }
        block_188:call4=&Physics41Player0View4+0x8C;
        call5=call4-12;
        Physics41Call4F178View5(call4,call5);
        return;
    case 85:case 91:globalVector80=&Physics41Player0View2+0x80;
        Physics41Call4F168View2(globalVector80);
        Physics41Call4F168View2(globalVector80+12);
        if(Physics41Data6E044View2!=7){
            Physics41Call40D10View2(3840);
            Physics41Call416F4View2();
            Physics41Call41580View2(90,16);
        }
        workWord2=Physics41Player1BAView1;
        if(!workWord2)goto byteOne65;
        workWord2=Physics41Data6E538View1&16;
        if(workWord2)return;
        workWord2=1;
        Physics41Player1BAView1=0;
        Physics41Player1B9View1=workWord2;
        return;
        byteOne65:workWord2=1;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        Physics41Player1B9View1=workWord2;
        return;
    case 86:case 92:workWord3=Physics41Data6E044View2;
        workWord2=8;
        if(workWord3!=workWord2)Physics41Call40D10View2(3840);
        globalVector80=&Physics41Data6E538View1;
        workWord2=Physics41Field(globalVector80,int*,0)&12;
        if(workWord2)Physics41PlayerACView1=0;
        workWord2=Physics41Call416F4View2();
        call4=(void*)90;
        call5=(void*)16;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalFieldA4Pointer=(void*)workWord2;
        workWord2=Physics41Call41580View2(call4,call5);
        workWord3=Physics41PlayerA8View1;
        if(workWord3<0)workWord3=-workWord3;
        workWord3=workWord3<8;
        __asm__("":"=r"(workWord3):"0"(workWord3),"r"(workWord2));
        call5=(void*)workWord2;
        if(!workWord3)goto reset101;
        workWord2=Physics41Field(globalVector80,int*,0)&12;
        if(!workWord2)goto reset101;
        workWord2=Physics41Player144View1;
        workWord2++;
        Physics41Player144View1=workWord2;
        goto saved101;
        reset101:Physics41Player144View1=0;
        saved101:call4=&Physics41PlayerACView1;
        globalVector80=(void*)Physics41Field(call4,int*,0);
        if(globalFieldA4Pointer)goto collision101;
        workWord2=(int)call5;
        if((int)call5<0)workWord2=-workWord2;
        workWord2=workWord2<513;
        if(workWord2)goto pass101;
        collision101:workWord2=Physics41Player20CView1&64;
        if(workWord2)Physics41Field(call4,int*,0)=0;
        else{
            workWord3=Physics41PlayerB0View1;
            workWord2=workWord3<(int)globalVector80;
            if(workWord2)Physics41Field(call4,int*,0)=workWord3;
        }
        pass101:Physics41Call417FCView2(256,384);
        workWord2=Physics41Player101View1;
        call4=&Physics41PlayerACView1;
        Physics41Field(call4,int*,0)=(int)globalVector80;
        if(workWord2)goto clear87;
        goto groundHelper87;
    case 87:{
            int product87_0,product87_1;
            register void *modePointer17 __asm__("$17");
            register void *vectorPointer18 __asm__("$18");
            register void *framePointer16 __asm__("$16");
            modePointer17=&Physics41Player4CView1;
            workWord3=Physics41Field(modePointer17,int*,0);
            workWord2=1;
            if(workWord3!=workWord2)goto ground87;
            Physics41Call40D10View2(3200);
            Physics41Call41580View2(40,8);
            Physics41Call417FCView2(256,384);
            vectorPointer18=modePointer17+64;
            workWord2=Physics41Call4EA2CView2(Physics41PlayerA4View1);
            workWord3=Physics41PlayerB0View1;
            product87_0=workWord3*workWord2;
            call4=(void*)Physics41PlayerA4View1;
            workWord2=product87_0>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.spC8=workWord2;
            workWord2=Physics41Call4E9E4View2(call4);
            workWord3=Physics41PlayerB0View1;
            product87_1=workWord3*workWord2;
            framePointer16=&originalFrame.spC8;
            call4=framePointer16;
            call5=call4;
            call6=vectorPointer18;
            workWord2=product87_1>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.spCC=workWord2;
            Physics41Call4F1C8View2(call4,call5,call6);
            originalFrame.spD0=0;
            temp_v0_4=Physics41Call4EDE8View2(framePointer16,0);
            __asm__("":"=r"(modePointer17):"0"(modePointer17));
            var_a0_3=modePointer17+52;
            if(temp_v0_4>=641){
                Physics41Call4F08CView2(framePointer16,temp_v0_4,640);
                __asm__("":"=r"(modePointer17):"0"(modePointer17));
                var_a0_3=modePointer17+52;
            }
            Physics41Call4F194View2(var_a0_3,vectorPointer18,framePointer16);
            Physics41Call41B64View2();
            workWord2=combinedIndex<13;
            if(!workWord2)goto subtract87;
            workWord2=Physics41Field(modePointer17,int*,0);
            if(workWord2)goto subtract87;
            workWord2=(int)Physics41Data6C570View1;
            workWord2=Physics41Field((void*)workWord2,int*,0)&64;
            if(workWord2)goto add23_93;
            workWord2=Physics41Player144View1;
            if(workWord2)goto add23_93;
            subtract87:globalPointer=&Physics41Player94View1;
            workWord2=Physics41Field(globalPointer,int*,0);
            __asm__("":"=r"(workWord2):"0"(workWord2),"i"(0x80091C2C));
            workWord2-=192;
            goto store95;
        ground87:
            workWord3=Physics41Data6E044View2;
            workWord2=8;
            if(workWord3!=workWord2)Physics41Call40D10View2(3840);
            globalVector80=&Physics41Data6E538View1;
            workWord2=Physics41Field(globalVector80,int*,0)&12;
            if(workWord2)Physics41PlayerACView1=0;
            workWord2=Physics41Call416F4View2();
            call4=(void*)90;
            call5=(void*)16;
            __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
            globalFieldA4Pointer=(void*)workWord2;
            workWord2=Physics41Call41580View2(call4,call5);
            workWord3=Physics41PlayerA8View1;
            if(workWord3<0)workWord3=-workWord3;
            workWord3=workWord3<8;
            __asm__("":"=r"(workWord3):"0"(workWord3),"r"(workWord2));
            call5=(void*)workWord2;
            if(!workWord3)goto reset87;
            workWord2=Physics41Field(globalVector80,int*,0)&12;
            if(!workWord2)goto reset87;
            workWord2=Physics41Player144View1;
            workWord2++;
            Physics41Player144View1=workWord2;
            goto saved87;
            reset87:Physics41Player144View1=0;
            saved87:call4=&Physics41PlayerACView1;
            globalVector80=(void*)Physics41Field(call4,int*,0);
            if(globalFieldA4Pointer)goto collision87;
            workWord2=(int)call5;
            if((int)call5<0)workWord2=-workWord2;
            workWord2=workWord2<513;
            if(workWord2)goto pass87;
            collision87:workWord2=Physics41Player20CView1&64;
            if(workWord2)Physics41Field(call4,int*,0)=0;
            else{
                workWord3=Physics41PlayerB0View1;
                workWord2=workWord3<(int)globalVector80;
                if(workWord2)Physics41Field(call4,int*,0)=workWord3;
            }
            pass87:Physics41Call417FCView2(256,384);
            workWord2=Physics41Player101View1;
            call4=&Physics41PlayerACView1;
            Physics41Field(call4,int*,0)=(int)globalVector80;
            if(workWord2){
                clear87:__asm__ volatile(""::"i"(0x80091D7C):"memory");
                Physics41Call4F168View2(call4-32);
                goto fields87;
            }
            groundHelper87:__asm__ volatile(""::"i"(0x80091D8C):"memory");
            Physics41Call41848View1(call4);
            Physics41Call41B64View2();
            fields87:call6=&Physics41PlayerFCView1;
            workWord2=Physics41Field(call6,unsigned char*,0);
            if(workWord2)goto scalar95;
            workWord2=Physics41PlayerB8View1;
            call4=call6-112;
            if(workWord2)goto scalar95;
            commit87:call5=call4;
            Physics41Call4F194View2(call4,call5,call6-20);
            return;
        }
    case 88:vectorAt40=&originalFrame.spD8;
        Physics41Call4F168View2(vectorAt40);
        call4=vectorAt40;
        call5=call4;
        Physics41Call4F1C8View2(call4,call5,&Physics41Player8CView3);
        workWord2=Physics41PlayerB8View1;
        call4=vectorAt40;
        if(!workWord2)goto detached121;
        originalFrame.spE0=0;
        workWord2=Physics41Call4EDE8View2(call4,0);
        call5=(void*)workWord2;
        workWord2=(int)call5<9;
        call4=vectorAt40;
        if(workWord2)goto vectors121;
        call6=(void*)8;
        goto limit121;
        detached121:workWord2=Physics41Call4EDE8View2(call4,1);
        call5=(void*)workWord2;
        workWord2=(int)call5<65;
        call4=vectorAt40;
        if(workWord2)goto vectors121;
        call6=(void*)64;
        limit121:__asm__ volatile(""::"r"(call4),"r"(call5),"r"(call6):"memory");
        Physics41Call4F08CView2(call4,call5,call6);
        vectors121:globalVector80=&Physics41Player80View1;
        call4=globalVector80;
        __asm__ volatile(""::"r"(call4):"memory");
        __asm__("":"=r"(globalVector80):"0"(globalVector80));
        globalFieldA4Pointer=globalVector80+12;
        __asm__ volatile(""::"r"(globalFieldA4Pointer):"memory");
        call5=globalFieldA4Pointer;
        call6=&originalFrame.spD8;
        __asm__ volatile(""::"r"(call5),"r"(call6):"memory");
        workWord2=-192;
        originalFrame.spE0=workWord2;
        __asm__ volatile("":::"memory");
        vector29:__asm__ volatile(""::"i"(0x80091E78):"memory");
        Physics41Call4F194View2(call4,call5,call6);
        call4=&Physics41Player8CView3;
        __asm__ volatile(""::"r"(call4):"memory");
        call5=&Physics41Player80View1;
        __asm__ volatile(""::"r"(call5):"memory");
        Physics41Call4F178View2(call4,call5);
        workWord2=Physics41Player94View1;
        workWord2=workWord2<-8960;
        clamp88:clamp119:if(workWord2){
            workWord2=-8960;
            Physics41Player94View1=workWord2;
        }
        return;
    case 89:{
            int product89_0,product89_1,product89_2,product89_3;
            register int numeric4 __asm__("$4");
            workWord3=Physics41Player4CView1;
            workWord2=1;
            if(workWord3!=workWord2)goto free89;
            workWord2=(int)Physics41Player250View1;
            workWord2=Physics41Field((void*)workWord2,int*,0);
            numeric4=Physics41Field((void*)workWord2,int*,80);
            workWord2=Physics41Player64View1;
            workWord3=numeric4-512;
            workWord2-=workWord3;
            workWord3=workWord2&4095;
            workWord2=workWord3<1024;
            if(workWord2){
                workWord3=numeric4;
                goto snapped89;
            }
            workWord2=workWord3<2048;
            if(workWord2){
                workWord3=numeric4+1024;
                goto snapped89;
            }
            workWord2=workWord3<3072;
            workWord3=numeric4+2048;
            if(!workWord2)workWord3=numeric4+3072;
            snapped89:workWord2=1600;
            Physics41PlayerA4View1=workWord3;
            Physics41PlayerACView1=workWord2;
            call4=(void*)22;
            goto speed89;
            free89:Physics41Call40D10View2(1600);
            call4=(void*)22;
            speed89:Physics41Call41580View2(call4,4);
            Physics41Call417FCView2(256,384);
            globalFieldA4Pointer=&Physics41Player4CView1;
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            workWord3=Physics41Field(globalFieldA4Pointer,int*,0);
            workWord2=1;
            if(workWord3!=workWord2)goto air89;
            workWord2=Physics41Call4EA2CView2(Physics41PlayerA4View1);
            workWord3=Physics41PlayerB0View1;
            product89_0=workWord3*workWord2;
            call4=(void*)Physics41PlayerA4View1;
            workWord2=product89_0>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics41Field(globalFieldA4Pointer,int*,52)=workWord2;
            workWord2=Physics41Call4E9E4View2(call4);
            workWord3=Physics41PlayerB0View1;
            product89_1=workWord3*workWord2;
            call4=globalFieldA4Pointer+64;
            workWord2=Physics41Player94View1;
            Physics41Player88View2=workWord2;
            workWord2=product89_1>>12;
            Physics41Player84View1=workWord2;
            Physics41Call4F178View2(call4,globalFieldA4Pointer+52);
            goto subtract89;
            air89:globalVector8C=globalFieldA4Pointer+64;
            workWord2=Physics41Call4EA2CView2(Physics41PlayerA4View1);
            workWord3=Physics41PlayerB0View1;
            product89_2=workWord3*workWord2;
            call4=(void*)Physics41PlayerA4View1;
            workWord2=product89_2>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.spE8=workWord2;
            workWord2=Physics41Call4E9E4View2(call4);
            workWord3=Physics41PlayerB0View1;
            product89_3=workWord3*workWord2;
            globalVector80=&originalFrame.spE8;
            call4=globalVector80;
            call5=globalVector80;
            call6=globalVector8C;
            __asm__("":"=r"(call4),"=r"(call5),"=r"(call6):"0"(call4),"1"(call5),"2"(call6));
            workWord2=product89_3>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.spEC=workWord2;
            Physics41Call4F1C8View2(call4,call5,call6);
            originalFrame.spF0=0;
            temp_v0_4=Physics41Call4EDE8View2(globalVector80,0);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3=globalFieldA4Pointer+52;
            if(temp_v0_4>=321){
                Physics41Call4F08CView2(globalVector80,temp_v0_4,320);
                __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3=globalFieldA4Pointer+52;
            }
            Physics41Call4F194View2(var_a0_3,globalVector8C,globalVector80);
            Physics41Call41B64View2();
            subtract89:globalPointer=&Physics41Player94View1;
            workWord2=Physics41Field(globalPointer,int*,0);
            workWord2-=192;
            Physics41Field(globalPointer,int*,0)=workWord2;
            goto clamp95;
        }
    case 93:case 94:{
            int product93_0,product93_1;
            Physics41Call40D10View1(0xC80);
            Physics41Call41580View1(0x28, 8);
            Physics41Call417FCView1(256,384);
            globalFieldA4Pointer = &Physics41Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics41Call4EA2CView1(Physics41Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics41Field(&Physics41Player0View1,int*,0xB0);
            product93_0=workWord3*workWord2;
            call4=(void*)Physics41Field(globalFieldA4Pointer,int*,0);
            workWord2=product93_0>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spF8=workWord2;
            workWord2=Physics41Call4E9E4View1(call4);
            workWord3=Physics41Field(&Physics41Player0View1,int*,0xB0);
            product93_1=workWord3*workWord2;
            workWord2=product93_1>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spFC=workWord2;
            Physics41Call4F1C8View1(&originalFrame.spF8, &originalFrame.spF8, globalVector8C);
            originalFrame.sp100 = 0;
            temp_v0_4 = Physics41Call4EDE8View1(&originalFrame.spF8, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics41Call4F08CView1(&originalFrame.spF8, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics41Call4F194View1(var_a0_3, globalVector8C, &originalFrame.spF8);
            Physics41Call41B64View1();
            workWord2=combinedIndex<13;
            if(!workWord2)goto subtract93;
            workWord2=Physics41Player4CView1;
            if(workWord2)goto subtract93;
            workWord2=(int)Physics41Data6C570View1;
            workWord2=Physics41Field((void*)workWord2,int*,0)&64;
            if(workWord2)goto add23_93;
            workWord2=Physics41Player144View1;
            if(workWord2)goto add23_93;
            goto subtract93;
            add23_93:workWord2=Physics41Player94View1;
            workWord2+=23;
            Physics41Player94View1=workWord2;
            return;
            subtract93:globalPointer=&Physics41Player94View1;
            workWord2=Physics41Field(globalPointer,int*,0);
            workWord2-=192;
            goto store95;
        }
    case 95:case 96:case 97:{
            int product95_0,product95_1,product95_2;
            register int numeric4 __asm__("$4");
            register int angle17 __asm__("$17");
            register void *vector17 __asm__("$17");
            workWord2=(int)Physics41Player250View1;
            globalVector80=Physics41Field((void*)workWord2,void**,0);
            workWord2=Physics41Field(globalVector80,int*,76);
            if(!workWord2){
                workWord2=Physics41Field(globalVector80,int*,88);
                workWord2++;
                Physics41Field(globalVector80,int*,88)=workWord2;
            }
            workWord3=Physics41Data6E044View2;
            workWord2=8;
            if(workWord3!=workWord2)Physics41Call40D10View2(1536);
            numeric4=Physics41Field(globalVector80,int*,80);
            workWord2=Physics41PlayerA4View1;
            workWord3=numeric4-512;
            workWord2-=workWord3;
            angle17=workWord2&4095;
            workWord2=angle17<1024;
            if(workWord2){
                angle17=numeric4;
                goto snapped95;
            }
            workWord2=angle17<2048;
            if(workWord2){
                angle17=numeric4+1024;
                goto snapped95;
            }
            workWord2=angle17<3072;
            angle17=numeric4+2048;
            if(!workWord2)angle17=numeric4+3072;
            snapped95:globalVector80=&Physics41PlayerA4View1;
            numeric4=Physics41Field(globalVector80,int*,0);
            workWord2=Physics41Call4EA2CView2(numeric4-angle17);
            workWord3=Physics41PlayerACView1;
            product95_0=workWord3*workWord2;
            Physics41Field(globalVector80,int*,0)=angle17;
            workWord2=product95_0>>12;
            Physics41PlayerACView1=workWord2;
            if(workWord2<0)Physics41PlayerACView1=0;
            workWord2=Physics41Call41580View2(90,16);
            angle17=Physics41PlayerACView1;
            if(workWord2<0)workWord2=-workWord2;
            workWord2=workWord2<513;
            call4=(void*)128;
            if(!workWord2){
                workWord3=Physics41PlayerB0View1;
                workWord2=workWord3<angle17;
                if(workWord2)Physics41PlayerACView1=workWord3;
            }
            Physics41Call417FCView2(call4,256);
            call4=(void*)Physics41PlayerA4View1;
            __asm__ volatile(""::"r"(call4):"memory");
            globalVector80=&Physics41PlayerACView1;
            __asm__("":"=r"(globalVector80):"0"(globalVector80));
            Physics41Field(globalVector80,int*,0)=angle17;
            workWord2=Physics41Call4EA2CView2(call4);
            workWord3=Physics41PlayerB0View1;
            product95_1=workWord3*workWord2;
            call4=(void*)Physics41PlayerA4View1;
            workWord2=product95_1>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics41Field(globalVector80,int*,-44)=workWord2;
            workWord2=Physics41Call4E9E4View2(call4);
            workWord3=Physics41PlayerB0View1;
            product95_2=workWord3*workWord2;
            vector17=globalVector80-32;
            __asm__("":"=r"(vector17):"0"(vector17));
            call4=vector17;
            Physics41Player88View2=0;
            workWord2=product95_2>>12;
            Physics41Player84View1=workWord2;
            Physics41Call4F178View2(call4,globalVector80-44);
            workWord2=Physics41PlayerFCView1;
            if(workWord2)goto scalar95;
            workWord2=Physics41PlayerB8View1;
            call4=vector17;
            if(!workWord2)goto vector95;
            scalar95:workWord2=Physics41PlayerA0View1;
            workWord2-=192;
            Physics41Player94View1=workWord2;
            return;
            vector95:__asm__("":"=r"(call4):"0"(call4));
            call5=call4;
            vector95Call:call6=&Physics41PlayerE8View1;
            __asm__ volatile(""::"r"(call6):"memory");
            Physics41Call4F194View2(call4,call5,call6);
            return;
        }
    case 90:globalVector80=&Physics41Player0View2+0xB8;
        workWord2=Physics41Field(globalVector80,int*,0);
        if(!workWord2)goto zero128;
        vectorAt30=&originalFrame.sp108;
        Physics41Call4F168View2(vectorAt30);
        call4=vectorAt30;
        call5=vectorAt30;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalVector8CState20=globalVector80-44;
        Physics41Call4F1C8View2(call4,call5,globalVector8CState20);
        originalFrame.sp110=0;
        call5=(void*)Physics41Call4EDE8View2(vectorAt30,0);
        workWord2=(int)call5<65;
        if(!workWord2)Physics41Call4F08CView2(vectorAt30,call5,64);
        originalFrame.sp110=-192;
        globalVector80-=56;
        Physics41Call4F194View2(globalVector80,globalVector8CState20,vectorAt30);
        Physics41Call4F178View2(globalVector8CState20,globalVector80);
        goto clamp128;
        zero128:Physics41Call4F168View2(globalVector80-56);
        Physics41Call4F168View2(globalVector80-44);
        goto clamp128;
        clamp128:globalPointer=&Physics41Player94View1;
        workWord2=Physics41Field(globalPointer,int*,0);
        clamp95:workWord2=workWord2<-8960;
        if(workWord2){
            workWord2=-8960;
            store95:__asm__ volatile(""::"i"(0x800924E4):"memory");
            Physics41Field(globalPointer,int*,0)=workWord2;
        }
        return;
    }
}
#undef Physics41Field


extern Moby* Callback41QueryMoby __asm__("D_80070328+0x250");
extern Moby* Callback41InitialMoby __asm__("D_80070328+0x250");
extern int Callback41ClearedWord __asm__("D_80070328+0x28");
extern Moby* Callback41Word71930 __asm__("D_80071930");
extern int Callback41WordE1D4 __asm__("D_8006E1D4");
extern int Callback41WordE1D8 __asm__("D_8006E1D8");
extern int Callback41WordE530 __asm__("D_8006E530");
extern int Callback41WordE52C __asm__("D_8006E52C");
extern void (*Callback41Header344)(void) __asm__("unk_ovlheader_80074344");
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8009250C.
 * Reuses verified24 private4C/50/54/58, independent table/flag and byte-position
 * routes; verified12 supplies particle/timer chains. Original41 adds dispatch,
 * T0 particle callback and selector57 loop. Pointer arithmetic is byte-based:
 * player28+8/-28/+250/-250, playerBC-8C/-BC and count148-B0/source-98.
 * Stack vectors18/28/38/48, frame78 and unaccessed spacing preserve original
 * layout without assigning source-variable meanings. Original loop calls with
 * size190, advances vector after zero return, stops after four or nonzero;
 * mask04000000, later size400 and selector5B mask08000000 remain numeric.
 * Independent aliases and empty constraints retain original load-delay order,
 * argument lifetimes and internal targets; they emit no instructions.
 * Units, helper semantics, audio mapping, caller cadence and retail runtime
 * remain unresolved. Acceptance requires every original code/local-jump/table
 * word, strict complete TU and every EXE/original overlay hash.
 */
extern Spyro Callback41Player __asm__("D_80070328");
int Callback41Call80037058(int x, int y) __asm__("func_80037058");
void Callback41Call80041930(void) __asm__("func_80041930");
void Callback41Call80041AE8(void) __asm__("func_80041AE8");
void Callback41Call80041C20(void) __asm__("func_80041C20");
void Callback41Call80042A44(void) __asm__("func_80042A44");
void Callback41Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback41Word8006E538 __asm__("D_8006E538");
int Callback41Call80055E84(Moby*) __asm__("func_80055E84");
void Callback41Call8004ED6C(void*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
void* Callback41Call8001BA30(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int Callback41Call80019138(Vector3D*,int,int,int,int,Moby*) __asm__("func_80019138");
int Callback41Call8001830C(Vector3D*,Vector3D*,int,int,Moby*) __asm__("func_8001830C");
extern int Callback41Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback41Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback41Values[] __asm__("D_8006FCF0");
void Callback41Call80049590(void) __asm__("func_80049590");
int Callback41Call8003BF6C(int,int) __asm__("func_8003BF6C");
extern short Callback41Count __asm__("D_80070328+0x148");
extern int D_8006C648;
void Callback41Call8004F110(Vector3D*,int) __asm__("func_8004F110");
void func_level_41_8009250C(void) {
    struct {Vector3D particle; int reserved24; Vector3D first; int reserved34; Vector3D second; int reserved44; Vector3D third; int reserved54; } local;
    int reservedStackWords[2];
    register unsigned char* countBase __asm__("$5");
    register unsigned char* sourceBytes __asm__("$18");
    register int iteration __asm__("$16");
    register int secondLimit __asm__("$17");
    register int sample __asm__("$2");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    register char* (*particles)(int,int,Vector3D*,Vector3D*) __asm__("$8");
    register unsigned char* privateData __asm__("$16");
    register unsigned char* privateOther __asm__("$16");
    register Moby* selected __asm__("$2");
    register int selectedClass __asm__("$3");
    register int computedValue __asm__("$4");
    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    int descriptorResult;
    register int flagOffset __asm__("$3");

    register int positionDelta __asm__("$2");
    register int positionValue __asm__("$3");

    switch(Callback41Player.animationState) {
    case 0x14:
    case 0x55:
        if(func_800438F4()==0)func_80043728();
        Callback41Call80041C20();
        Callback41Player.unk9a=0;
        Callback41Call80042A44();
        goto clearSharedValue;
    case 0x20:
    case 0x35:
    case 0x36:
    case 0x5A:
        Callback41Call80041C20();
        Callback41Call80042A44();
        goto clearSharedValue;
    case 0x1A:
    case 0x1D:
    case 0x58:
        Callback41Call80041C20();
        Callback41Call80042A44();
        goto queryC00;
    case 0x13:
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041930();
        goto clearSharedValue;
    case 0x21:
    case 0x22:
    case 0x23:
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041930();
        if (SpawnParticle != 0) {
            countBase=(unsigned char*)&Callback41Count;
            if (*(short*)countBase == 0) goto clearSharedValue;
            secondLimit = 1;
            if (*(short*)countBase >= 2) {
                secondLimit = 2;
            }
            iteration = 0;
            if (secondLimit != 0) {
                __asm__("" : "=r"(countBase) : "0"(countBase));
                sourceBytes=countBase-0xB0;
                do {
                    func_8004F178((&local.particle), (Vector3D *) sourceBytes);
                    Callback41Call8004F110((&local.particle), 7);
                    iteration += 1;
                    sample=rand();
                    component=local.particle.x;
                    sample &= 254;
                    component -=127;
                    component +=sample;
                    __asm__("" : "=r"(component) : "0"(component));
                    local.particle.x=component;
                    sample=rand();
                    component=local.particle.y;
                    sample &= 254;
                    component -=127;
                    component +=sample;
                    __asm__("" : "=r"(component) : "0"(component));
                    local.particle.y=component;
                    sample=rand();
                    kind=1;
                    subtype=0x17;
                    position=sourceBytes-0x98;
                    vector=&local.particle;
                    __asm__("" : "=r"(kind), "=r"(subtype), "=r"(position), "=r"(vector) : "0"(kind), "1"(subtype), "2"(position), "3"(vector), "r"(sample) : "$3", "memory");
                    sample &=254;
                    __asm__("" : "=r"(sample) : "0"(sample) : "memory");
                    component=local.particle.z;
                    particles=SpawnParticle;
                    __asm__("" : "=r"(particles) : "0"(particles), "r"(component), "r"(sample));
                    component -=127;
                    component +=sample;
                    local.particle.z=component;
                    particles(kind,subtype,(Vector3D*)position,vector);
                } while (iteration < secondLimit);
            }
        }
        goto clearSharedValue;
    case 0x28:
    case 0x29:
    case 0x39:
        Callback41Call80041C20();
        Callback41Call80042A44();
        descriptor=&Callback41Player.unk22[2];
        if (Callback41Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback41Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setDecreasingFlag;
            tableValue=decreasingValue-0xC8;
            goto storeDecreasingValue;
            }
            goto setDecreasingFlag;
storeDecreasingValue:
            *(int*)(Callback41Values + valueOffset) = tableValue;
setDecreasingFlag:
            flagOffset = *descriptor * 0x2C;
            Callback41Flags[flagOffset] = Callback41Flags[flagOffset] | 0x10;
            __asm__ volatile("" : : : "memory");
        }
        goto clearSharedValue;
    case 0x2A:
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80049590();
        descriptor=&Callback41Player.unk22[2];
        if (Callback41Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback41Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback41Player.unk22[2];
        }
        if (Callback41Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback41Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback41Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback41Flags[flagOffset] = Callback41Flags[flagOffset] | 0x10;
            __asm__ volatile("" : : : "memory");
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041AE8();
        if ((unsigned char) Callback41Player.unk10[4] != 0) {
            computedValue = -Callback41Player.unk9ha[4] - Callback41Call80037058(Callback41Player.position.x, Callback41Player.position.y);
            positionValue = Callback41Player.unk4a - computedValue;
            Callback41Player.unk4[0] = computedValue;
            positionDelta = (int) Callback41Player.union144.a.unk13cc >> 6;
            positionValue -= positionDelta;
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            Callback41Player.position.z=positionValue;
            return;
        }
        break;
    case 0x31:
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80043A38(0xC00);
        if (func_80040954(Callback41Player.unk11[2]) == 0xA) {
            Callback41Player.union144.a.unk13cb = 0;
        } else {
            Callback41Player.union144.a.unk13cb += D_8006C648;
        }
        Callback41Player.unk4[0] = 0;
        if (Callback41Call8003BF6C((int) D_8006C654->unk32, Callback41Player.unk22[2]) == 0) {
            Callback41Player.unk22[2] = PlaySound((int) D_8006C654->unk32, 0, 4);
            Callback41Player.unk22[3] = (int) D_8006C654->unk32;
            return;
        }
        break;
    case 0x56:
    case 0x5C:
        privateData=Callback41Player.critterMobyPtr->mobyTag;
        func_800438F4();
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041930();
        if((unsigned char)Callback41Player.unk10[2]!=0) {
            selected=Callback41Word71930;
            *(Moby**)(privateData+0x4C)=selected;
            if(selected) {
                selectedClass=selected->mobyClass;
                if(selectedClass!=0x4B && selectedClass!=0x4F && selectedClass!=0x2FF) {
                    *(Moby**)(privateData+0x4C)=0;
                    goto queryC00;
                }
                goto copySelected;
            }
        } else goto clearSelected;
        goto queryC00;
    case 0x57: {
        register unsigned char* sourceBase __asm__("$18");
        register int* clearedWord __asm__("$18");
        register Moby** mobyPointer __asm__("$18");
        register Vector3D* firstVector __asm__("$16");
        register Vector3D* secondVector __asm__("$17");
        register int counter __asm__("$16");
        register int mask __asm__("$19");
        register void* argument0 __asm__("$4");
        register Moby* initialMoby __asm__("$4");
        func_800438F4();
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041930();
        Callback41Call80043A38(0xC00);
        initialMoby=Callback41InitialMoby;
        __asm__ volatile("" : "=r"(initialMoby) : "0"(initialMoby) : "memory");
        clearedWord=&Callback41ClearedWord;
        *clearedWord=0;
        if(initialMoby->animationState.id==2 &&
           Callback41Call80055E84(initialMoby)>=4 &&
           Callback41Call80055E84(Callback41QueryMoby)<13) {
            argument0=(unsigned char*)clearedWord+8;
            __asm__("" : "=r"(argument0) : "0"(argument0));
            firstVector=&local.first;
            local.first.x=0x190;
            local.first.y=0;
            local.first.z=0;
            Callback41Call8004ED6C(argument0,firstVector,firstVector);
            secondVector=&local.second;
            argument0=secondVector;
            __asm__("" : "=r"(argument0) : "0"(argument0) : "memory");
            sourceBase=(unsigned char*)clearedWord-0x28;
            func_8004F194((Vector3D*)argument0,(Vector3D*)sourceBase,firstVector);
            counter=0;
            mask=0x04000000;
            mobyPointer=(Moby**)(sourceBase+0x250);
            do {
                register Moby* argumentMoby __asm__("$2");
                register Vector3D* argument0 __asm__("$4");
                register int argument1 __asm__("$5");
                register int argument2 __asm__("$6");
                argument0=secondVector;
                argument1=0x190;
                argument2=1;
                __asm__ volatile("" : "=r"(argument0), "=r"(argument1), "=r"(argument2) : "0"(argument0), "1"(argument1), "2"(argument2) : "$7", "memory");
                argumentMoby=*mobyPointer;
                __asm__ volatile("" : : : "memory");
                if(Callback41Call8001BA30(argument0,argument1,argument2,0,mask,argumentMoby))break;
                func_8004F194(secondVector,secondVector,&local.first);
                counter++;
            } while(counter<4);
            firstVector=&local.first;
            {
                register Moby* argumentMoby __asm__("$2");
                register Vector3D* argument0 __asm__("$4");
                register int argument1 __asm__("$5");
                register int argument2 __asm__("$6");
                argument0=firstVector;
                argument1=0x400;
                argument2=0;
                __asm__ volatile("" : "=r"(argument0), "=r"(argument1), "=r"(argument2) : "0"(argument0), "1"(argument1), "2"(argument2) : "$7", "memory");
                argumentMoby=*mobyPointer;
                __asm__ volatile("" : : : "memory");
                Callback41Call80019138(argument0,argument1,argument2,0,mask,argumentMoby);
            }
            Callback41Call8001830C((Vector3D*)((unsigned char*)mobyPointer-0x250),firstVector,0,0x04000000,*mobyPointer);
            if(Callback41Call80055E84(*mobyPointer)>=8) {
                register int* limitPointer __asm__("$3")=&Callback41WordE1D4;
                if(*limitPointer<0xC00)*limitPointer=0xC00;
                if(Callback41WordE1D8<10)Callback41WordE1D8=10;
                Callback41WordE530=120;
                Callback41WordE52C=5;
            }
        }
        if(Callback41Player.unk5==1) {
            if(Callback41Player.ticksSinceLastSurfaceTouch==0)Callback41Player.unk5=0;
        } else if(Callback41Player.ticksSinceLastSurfaceTouch!=0) {
            Callback41Player.unk5=1;
            Callback41Player.unk7a[2].z=Callback41Player.unk7a[3].z;
        }
        return;
    }
    case 0x59:
        privateOther=Callback41Player.critterMobyPtr->mobyTag;
        Callback41Header344();
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041930();
        if((unsigned char)Callback41Player.unk10[2]!=0) {
            selected=Callback41Word71930;
            *(Moby**)(privateOther+0x4C)=selected;
            if(selected) {
                selectedClass=selected->mobyClass;
                if(selectedClass==0x4B || selectedClass==0x4F || selectedClass==0x2FF) {
                    register Moby* bytePointer __asm__("$2")=*(Moby**)(privateOther+0x4C);
                    register int shiftedByte __asm__("$2")=((unsigned char*)bytePointer)[0x46];
                    register Moby* propertyPointer __asm__("$3");
                    register int propertyWord __asm__("$2");
                    __asm__ volatile("" : : : "memory");
                    propertyPointer=*(Moby**)(privateOther+0x4C);
                    shiftedByte<<=4;
                    *(int*)(privateOther+0x50)=shiftedByte;
                    propertyWord=*(int*)propertyPointer;
                    __asm__ volatile("" : : : "memory");
                    *(int*)(privateOther+0x58)=0;
                    *(int*)(privateOther+0x54)=propertyWord;
                    Callback41Player.unk5=1;
                } else goto clearSelectedOther;
            }
        } else {
clearSelectedOther:
            *(Moby**)(privateOther+0x4C)=0;
            Callback41Player.unk5=0;
        }
        goto clearSharedValue;
    case 0x5B: {
        register Vector3D* vectorBase __asm__("$16");
        register int* sourceWord __asm__("$17");
        register void* argument0 __asm__("$4");
        if(func_800438F4()==0)func_80043728();
        Callback41Call80041C20();
        sourceWord=&Callback41Player.unk9a;
        *sourceWord=0;
        Callback41Call80042A44();
        Callback41Player.unk4[0]=0;
        argument0=(unsigned char*)sourceWord-0x8C;
        if(Callback41Player.critterMobyPtr->animationState.id==6) {
            vectorBase=&local.third;
            local.third.x=0x400;
            local.third.y=0;
            local.third.z=0x200;
            Callback41Call8004ED6C(argument0,vectorBase,vectorBase);
            func_8004F194(vectorBase,vectorBase,(Vector3D*)((unsigned char*)sourceWord-0xBC));
            Callback41Call8001BA30(vectorBase,0x400,0,0,0x08000000,Callback41Player.critterMobyPtr);
        }
        return;
    }
    case 0x5D:
    case 0x5E:
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041930();
        if(Callback41Player.unk5!=0x7F) {
            if(Callback41Player.unk7a[3].z<0 && Callback41Player.animationStateFrames>=4)
                Callback41Player.unk5=1;
            else if(Callback41Player.unk5==0 && !(Callback41Word8006E538&0x40) && Callback41Player.union144.a.unk13cb==0)
                Callback41Player.unk5=2;
        }
        goto clearSharedValue;
    case 0x5F:
    case 0x60:
    case 0x61:
        privateData=Callback41Player.critterMobyPtr->mobyTag;
        Callback41Header344();
        func_800438F4();
        Callback41Call80041C20();
        Callback41Call80042A44();
        Callback41Call80041930();
        if((unsigned char)Callback41Player.unk10[2]!=0) {
            selected=Callback41Word71930;
            *(Moby**)(privateData+0x4C)=selected;
            if(selected) {
                selectedClass=selected->mobyClass;
                if(selectedClass==0x4B || selectedClass==0x4F || selectedClass==0x2FF)goto copySelected;
                goto clearSelected;
            }
        } else goto clearSelected;
        goto queryC00;
copySelected: {
        register Moby* bytePointer __asm__("$2")=*(Moby**)(privateData+0x4C);
        register int shiftedByte __asm__("$2")=((unsigned char*)bytePointer)[0x46];
        register Moby* propertyPointer __asm__("$3");
        register int propertyWord __asm__("$2");
        __asm__ volatile("" : : : "memory");
        propertyPointer=*(Moby**)(privateData+0x4C);
        shiftedByte<<=4;
        *(int*)(privateData+0x50)=shiftedByte;
        propertyWord=*(int*)propertyPointer;
        __asm__ volatile("" : : : "memory");
        *(int*)(privateData+0x58)=0;
        *(int*)(privateData+0x54)=propertyWord;
        goto queryC00;
    }
clearSelected:
        *(Moby**)(privateData+0x4C)=0;
queryC00:
        Callback41Call80043A38(0xC00);
clearSharedValue:
        Callback41Player.unk4[0]=0;
        return;
    default:
        return;
    }
}


#define LEVEL_ID 41
#define PlaySpyroSounds_level_41 func_level_41_80092FC4
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_41_80093130(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x14:
    case 0x1a:
    case 0x1d:
    case 0x20:
    case 0x2b:
    case 0x2c:
    case 0x31:
    case 0x35:
    case 0x36:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x5a:
    case 0x5b:
    case 0x5c:
    case 0x5f:
    case 0x60:
    case 0x61:
        func_80043ABC(&spyro.unk9e);
        break;
    case 0x13:
    case 0x59:
    case 0x5d:
    case 0x5e:
        func_80043ABC(0);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 800931AC.
 * Reuses verified24 underwater/surface vectors, signed-table and55..61 routes;
 * verified33 private0/4/8 swirl and state6 clamp; verified43 squish and slide.
 * Original41 supplies separate35/36 stand blocks and shared descriptor15/9/19.
 * Numeric byte offsets, signed shift10/6, halfwords, yaw/scalar FFF masks and
 * 800/4B00 limits retain original instructions. Scalar60 inputs800/801/FFF
 * yield0/-7FF/-1 before helpers; private producer positions remain source-native.
 * Empty constraints retain original lifetimes and independent branch blocks,
 * emitting no opcodes. Every code/local jump/owned dispatch word, strict full
 * TU and complete EXE/every overlay hashes are acceptance gates. Helper/audio
 * meanings, units/conversions, caller cadence and live runtime parity remain
 * open. Once per invocation is the only demonstrated update cadence.
 */
extern Spyro Transition41_D_80070328 __asm__("D_80070328");
int Transition41_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition41_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition41_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition41RawUnion[] __asm__("D_80070328+0x144");
extern int Transition41RawMovement __asm__("D_80070328+0x50");
extern void (*Call41Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw41State[] __asm__("D_80070328+0x50");
extern Spyro Special41_D_80070328 __asm__("D_80070328");
extern short Signed41TableA[] __asm__("D_800658A0");
extern short Signed41TableB[] __asm__("D_80065920");
int Special41_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Special41_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Special41_D_8006E524 __asm__("D_8006E524");

extern int D_80071934;
int Call41A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw41NegativeWord __asm__("D_80070328+0x28");
extern int Raw41TableIndex __asm__("D_80070328+0x298");
extern int Raw41Yaw __asm__("D_80070328+0x64");
int Transition41_func_8003636C(int,int) __asm__("func_8003636C");
void Transition41_func_800441F0(void) __asm__("func_800441F0");
void Transition41_func_80043A38(int) __asm__("func_80043A38");
int Transition41_func_8004E880(int,int,int) __asm__("func_8004E880");
void func_level_41_800931AC(int arg0){
    struct {Vector3D first; int gap1; Vector3D second; int gap2; Vector3D third;} vectors;
    register int negativeWord __asm__("$3");
    int firstResult,secondResult,firstWrappedWord,secondWrappedWord,firstParticleKind,secondParticleKind,firstParticleSubtype,secondParticleSubtype;
    register Vector3D* destination __asm__("$4");

    int lengthResult;

    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    register unsigned char *sourceBytesA __asm__("$16");

    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* savedBase __asm__("$3");
    register int oldMovementC __asm__("$5");
    register unsigned char* privateData __asm__("$16");
    register unsigned char* stateBase __asm__("$17");
    int maskedValue;
    switch(arg0){
    case 0x14:
        Transition41_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition41_D_80070328.unk5 = 0;
        Transition41_func_800441F0();
        Transition41_D_80070328.grounded = 1;
        Transition41_D_80070328.union144.a.unk13cb = Transition41_func_8003636C(1, 3);
        Transition41_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x35:
        Transition41_D_80070328.movementState=0;
        Transition41_D_80070328.unk5=0;
        Transition41_func_800441F0();
        Transition41_D_80070328.grounded=1;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        stateBase=(unsigned char*)&Transition41RawMovement;
        privateData = Transition41_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition41_D_80070328.unk5 = 0;
        Transition41_D_80070328.grounded = 0;
        Transition41_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition41_D_80070328.m_WhirlwindPointer;
        yawValue=Transition41_D_80070328.rotation.yaw;
        positionZ=Transition41_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition41_D_80070328.union144.a.unk13cc=yawValue;
        Transition41_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition41_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition41_D_80070328.union144.a.unk13ce.z=heightValue;
        __asm__ volatile("" : : : "memory");
        heightValue = ((int) (heightValue << 0xA) >> 0xA) + 0x400;
        __asm__("" : "=r"(heightValue) : "0"(heightValue));
        Transition41_D_80070328.union144.a.unk13ce.y = heightValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
        Transition41_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition41_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition41_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition41_D_80070328.unk13e[0] = (int) Transition41_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition41_D_80070328.unk20a = 0;
        Transition41_D_80070328.critterMobyPtr = 0;
        Transition41_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x1D: {
        register int oldState __asm__("$4")=Transition41RawMovement;
        register int first __asm__("$3")=Transition41_D_80070328.unk17e.x;
        register int second __asm__("$2");
        register int third __asm__("$3");
        __asm__("" : "=r"(oldState),"=r"(first) : "0"(oldState),"1"(first) : "memory");
        second=7;
        __asm__("" : "=r"(second) : "0"(second));
        Transition41RawMovement=second;
        __asm__ volatile("" : : : "memory");
        second=Transition41_D_80070328.unk17e.y;
        __asm__ volatile("" : "=r"(second) : "0"(second) : "memory");
        Transition41_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(first) : "0"(first) : "memory");
        first<<=6;
        __asm__("" : "=r"(first) : "0"(first));
        Transition41_D_80070328.unk7a[2].x=first;
        __asm__ volatile("" : : : "memory");
        third=Transition41_D_80070328.unk17e.z;
        second<<=6;
        Transition41_D_80070328.union144.a.unk13cb=oldState;
        Transition41_D_80070328.unk7a[2].y=second;
        second=third<<6;
        if(third==0)second=Transition41_D_80070328.unk7a[3].z;
        Transition41_D_80070328.unk7a[2].z=second;
        Transition41_func_80043A38(0xC00);
        Transition41_D_80070328.grounded=1;
        Transition41_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        soundSelector=D_8006C654->spyroHurt;
        soundZero=0;
        goto sharedSound;
    }

    case 0x1A:
        savedBase = Transition41RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        oldMovementC = Transition41RawMovement;
        Transition41RawMovement = MOVEMENT_STATE_HURT;
        Transition41_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementC;
        Transition41_func_8004F168(destination);
        Transition41_D_80070328.grounded = 1;
        Transition41_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        soundSelector=D_8006C654->squish;
        soundZero=0;
        goto sharedSound;
    case 0x20:
        Transition41_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition41_D_80070328.unk5 = 0;
        Transition41_func_80043A38(0xC00);
        Transition41_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition41_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x21:
    case 0x22:
    case 0x23: {
        register unsigned char* flyState __asm__("$16")=(unsigned char*)&Transition41RawMovement;
        if(*(int*)flyState!=6) {
            *(int*)flyState=6;
            Transition41_D_80070328.unk5=0;
            Transition41_func_8004F168((Vector3D*)(flyState+0x104));
            Transition41_D_80070328.union144.a.unk13db.y=0;
            lengthResult=Transition41_func_8004EDE8((Vector3D*)(flyState+0x48),0);
            Transition41_D_80070328.unk8[0]=lengthResult;
            if(lengthResult<0x800)Transition41_D_80070328.unk8[0]=0x800;
            if(Transition41_D_80070328.unk8[0]>=0x4B01)Transition41_D_80070328.unk8[0]=0x4B00;
            Transition41_D_80070328.union144.a.unk13cb=0;
            Transition41_D_80070328.union144.b.unk148=0;
            Transition41_D_80070328.union144.a.unk13ce.x=0;
            Transition41_D_80070328.union144.a.unk13ce.y=0;
            Transition41_D_80070328.grounded=0;
            Transition41_D_80070328.unk15b=0;
        }
        if(arg0<0xA0)goto clearPointers;
        return;
    }
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition41_D_80070328.movementState - 0xB) >= 2U) && (Transition41_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition41_D_80070328.movementState - 0x50));
                if ((Transition41_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw41NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition41_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call41A358(&vectors.first, 0x800);
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
            firstWrappedWord = Transition41_D_80070328.rotation.pitch & 0xFFF;
            Transition41_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition41_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition41_D_80070328.rotation.pitch > 0) {
                Transition41_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition41_D_80070328.unk5 = 1;
            }
            Transition41_func_8004F168((Vector3D *) ((unsigned char*)&Transition41_D_80070328.rotation.pitch + 0xEC));
            Transition41_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition41_D_80070328.unk8[0] = Transition41_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition41_D_80070328.rotation.pitch + 0x38), 0);
            Transition41_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition41_D_80070328.animationState == 0x2A) {
            Transition41_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition41_D_80070328.union144.a.unk13da = 0;
        }
        Transition41_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition41_D_80070328.unk20a = 0;
        Transition41_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw41State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw41NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition41_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call41A358(localVector, 0x800);
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
            if (Transition41_D_80070328.animationState == 0x2E) {
                Transition41_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition41_D_80070328.rotation.pitch & 0xFFF;
            Transition41_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition41_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition41_D_80070328.rotation.pitch > 0) {
                Transition41_D_80070328.rotation.pitch = 0;
            }
            Transition41_D_80070328.unk5 = 1;
            Transition41_func_8004F168((Vector3D *) ((unsigned char*)&Transition41_D_80070328.animationState + 0x104));
            Transition41_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition41_D_80070328.unk8[0] = Transition41_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition41_D_80070328.animationState + 0x50), 0);
            Transition41_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition41_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition41_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition41RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition41RawUnion;
            *(int*)unionPointer=(-Transition41_D_80070328.unk7a[2].z)>>2;
            if(Transition41RawMovement!=8){Transition41_D_80070328.union144.a.unk13cc=0x5900;Transition41RawMovement=10;}
            Transition41_D_80070328.unk5=0;
            Transition41_D_80070328.unk8[0]=Transition41_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition41_D_80070328.grounded=1;
            Transition41_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call41A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x31: {
        register unsigned char* lengthBase __asm__("$5")=(unsigned char*)&Transition41_D_80070328.unk8[0];
        register int valueA __asm__("$4");
        register int valueB __asm__("$5");
        register int valueKind __asm__("$6");
        *(int*)lengthBase=0;
        if(Transition41_D_80070328.animationState==0xD || Transition41_D_80070328.movementState==1)
            func_8004F178((Vector3D*)(lengthBase-0x30),(Vector3D*)(lengthBase-0x18));
        else Transition41_func_8004F168((Vector3D*)(lengthBase-0x30));
        func_8004F178(&Transition41_D_80070328.unk7a[2],(Vector3D*)((unsigned char*)&Transition41_D_80070328.unk7a[2]-0xC));
        Transition41_D_80070328.movementState=17;
        Transition41_D_80070328.unk5=0;
        Transition41_func_80043A38(0xC00);
        Transition41_D_80070328.grounded=0;
        Transition41_D_80070328.union144.a.unk13cb=0;
        valueKind=1;
        if(Transition41_D_80070328.unk9ha[0]>=11) {
            valueA=Transition41_D_80070328.unk9e.x;
            valueB=Transition41_D_80070328.unk9e.y;
        } else {
            valueA=Transition41_D_80070328.unk7a[3].x;
            valueB=valueA;
        }
        Transition41_D_80070328.union144.a.unk13cc=Transition41_func_8004E880(valueA,valueB,valueKind);
        goto clearPointers;
    }
    case 0x36:
        Transition41_D_80070328.movementState=0;
        Transition41_D_80070328.unk5=0;
        Transition41_func_800441F0();
        Transition41_D_80070328.grounded=1;
        goto clearPointers;
    case 0x39: {
        register int previousMovement __asm__("$2")=Transition41RawMovement;
        register int numericKind __asm__("$3");
        register int indexWord __asm__("$3");
        register unsigned char* unionPointer __asm__("$5");
        register int tableOffset __asm__("$2");
        register int tableWord __asm__("$3");
        __asm__("" : "=r"(previousMovement) : "0"(previousMovement));
        numericKind=7;
        __asm__("" : "=r"(numericKind) : "0"(numericKind));
        Transition41RawMovement=numericKind;
        __asm__ volatile("" : : : "memory");
        indexWord=Raw41TableIndex;
        __asm__ volatile("" : "=r"(indexWord) : "0"(indexWord) : "memory");
        unionPointer=Transition41RawUnion;
        __asm__("" : "=r"(indexWord),"=r"(unionPointer) : "0"(indexWord),"1"(unionPointer) : "memory");
        Transition41_D_80070328.unk5=0;
        *(int*)unionPointer=previousMovement;
        if(indexWord<0)Raw41TableIndex=((Raw41Yaw+0x800)>>4)&0xFF;
        tableOffset=Raw41TableIndex*2;
        tableWord=*(short*)((unsigned char*)Signed41TableB+tableOffset);
        destination=(Vector3D*)(unionPointer-0xC4);
        *(int*)(unionPointer-0xB8)=tableWord;
        tableOffset=*(short*)((unsigned char*)Signed41TableA+tableOffset);
        Transition41_D_80070328.unk7a[2].z=0;
        Transition41_D_80070328.unk7a[2].y=tableOffset;
        func_8004F178(destination,(Vector3D*)(unionPointer-0xB8));
        Transition41_D_80070328.grounded=1;
        Transition41_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        { register unsigned char* soundTable __asm__("$2")=(unsigned char*)D_8006C654;
        __asm__ volatile("" : "=r"(soundTable) : "0"(soundTable) : "memory");
        soundZero=0;
        soundSelector=soundTable[0x19]; }
sharedSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
    }
clearPointers:
        Transition41_D_80070328.unk20a=0;
        Transition41_D_80070328.critterMobyPtr=0;
        return;
    case 0x55:
    case 0x5B:
        Transition41_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition41_D_80070328.unk5 = 0;
        Transition41_func_800441F0();
        Transition41_D_80070328.grounded = 1;
        return;
    case 0x56:
    case 0x57:
    case 0x5C:
    case 0x5F:
    case 0x60:
    case 0x61:
        Transition41_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition41_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((unsigned char*)(unsigned char*)&Transition41_D_80070328.movementState + 0x3C), (Vector3D *) ((unsigned char*)(unsigned char*)&Transition41_D_80070328.movementState + 0x48));
            Transition41_D_80070328.unk5 = 1;
        } else {
            Transition41_D_80070328.unk5 = 0;
        }
        Transition41_D_80070328.unk8[0] = Transition41_func_8004EDE8(&Transition41_D_80070328.unk7a[3], 0);
        Transition41_func_80043A38(0xC00);
        Transition41_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition41_D_80070328.grounded = 1;
        goto clearSpecialTail;
    case 0x58:
        Special41_D_80070328.movementState = MOVEMENT_STATE_HURT;
        Special41_D_80070328.unk5 = 0;
        if (Special41_D_80070328.unk22[5] >= 0) {
            tableOffsetOrValue = Special41_D_80070328.unk22[5] * 2;
            tableValueA = *(short*)((unsigned char*)Signed41TableB + tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            tableValueA >>= 1;
            Special41_D_80070328.unk7a[2].x = tableValueA;
            tableOffsetOrValue = *(short*)((unsigned char*)Signed41TableA + tableOffsetOrValue);
            Special41_D_80070328.unk7a[2].z = 0;
            __asm__ __volatile__("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Special41_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
        } else {
            Special41_func_8004F168((Vector3D *) ((unsigned char*)&Special41_D_80070328.movementState + 0x3C));
        }
        Special41_D_80070328.unk7a[2].z = 0x200;
        func_8004F178((Vector3D *) ((unsigned char*)&Special41_D_80070328.unk7a[2].z - 0x14), (Vector3D *) ((unsigned char*)&Special41_D_80070328.unk7a[2].z - 8));
        Special41_D_80070328.grounded = 1;
        Special41_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
    default:
        return;
    case 0x5A:
        Transition41_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition41_D_80070328.unk5 = 0;
        Transition41_func_80043A38(0xC00);
        Transition41_D_80070328.grounded = 1;
        Transition41_D_8006E524 = 0xF;
        return;
    case 0x59:
        Transition41_D_80070328.movementState = MOVEMENT_STATE_FALL;
        if (Transition41_D_80070328.animationState == 0x5F) {
            Transition41_D_80070328.unk5 = 1;
        } else {
            Transition41_D_80070328.unk5 = 0;
        }
        Transition41_D_80070328.unk8[0] = Transition41_func_8004EDE8(&Transition41_D_80070328.unk7a[3], 0);
        Transition41_D_80070328.grounded = 0;
        Transition41_D_80070328.unk15b = 1;
clearSpecialTail:
        Transition41_D_80070328.idle = 0;
        Transition41_D_80070328.unk15g = 0;
        return;
    case 0x5D:
        stateBaseA = Raw41State;
        __asm__("" : "=r"(stateBaseA) : "0"(stateBaseA));
        destination = (Vector3D*)(stateBaseA + 0x3C);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceBytesA = stateBaseA + 0x48;
        *(int*)stateBaseA = 2;
        func_8004F178(destination, (Vector3D*)sourceBytesA);
        Special41_D_80070328.unk8[0] = Special41_func_8004EDE8((Vector3D *) sourceBytesA, 0);
        Special41_D_80070328.unk7a[2].z = 0xA00;
        Special41_D_80070328.unk5 = 0;
        Special41_D_80070328.union144.a.unk13cb=0;
        Special41_D_80070328.grounded = 0;
        PlaySound((int) D_8006C654->jump, 0, 0);
        return;
    case 0x5E: {
        register unsigned char* state __asm__("$2")=Raw41State;
        register Vector3D* source __asm__("$16");
        register Vector3D* argument __asm__("$5");
        register int numericKind __asm__("$17");
        __asm__("" : "=r"(state) : "0"(state));
        destination=(Vector3D*)(state+0x3C);
        __asm__("" : "=r"(destination) : "0"(destination));
        source=(Vector3D*)(state+0x48);
        __asm__ volatile("" : "=r"(source) : "0"(source) : "$17", "memory");
        argument=source;
        __asm__("" : "=r"(argument) : "0"(argument));
        numericKind=2;
        __asm__("" : "=r"(numericKind) : "0"(numericKind));
        *(int*)state=numericKind;
        func_8004F178(destination,argument);
        Transition41_D_80070328.unk8[0]=Transition41_func_8004EDE8(source,0);
        Transition41_D_80070328.unk5=numericKind;
        Transition41_D_80070328.union144.a.unk13cb=0;
        Transition41_D_80070328.grounded=0;
        return;
    }
    }
}


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80093FF8.
 * Assembly SHA256 2eb1d2d3481752954213db6d8cf8ffa1b9b3ea55237cdd574083b68b480639ae.
 * AI-generated; not human reviewed. Verified donor state C is adapted to
 * all1601 original instructions and79 state-table entries (bias19).
 * New original85..97 chains retain callback1, input/collision priority,
 * raw nested-object fields, signed wrapped heading thresholds, three-axis
 * products, partial effect callback, raw helper arguments and counter stores.
 * The original0x40 frame retains vectors atSP10/SP20 and savedS0/S1.
 * Verified generic states retain all target selector and branch joins.
 * Rev1's source-locked thirteen transition graphs are decoding references;
 * no browser-derived behavior or values are used. Typed view aliases remain
 * distinct; exact symbols and per-state donors are recorded in provenance.
 * Empty initialized constraints and original-address metadata emit no CPU
 * instructions. Every CPU word is emitted by the frozen C toolchain.
 * Raw physical units/fixed point, helper contracts and invocation rate
 * remain unresolved. Cadence is per invocation; rate unknown.
 * Falsification: every original native/linked instruction, branch/internal
 * target, selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
extern int Anim41Player48View1 __asm__("D_80070328 + 0x48");
extern int Anim41Player48View2 __asm__("D_80070328 + 0x48");
extern int Anim41Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim41PlayerA8View1 __asm__("D_80070328 + 0xA8");
extern int Anim41PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim41PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim41PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern int Anim41Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim41Player1ECView1 __asm__("D_80070328 + 0x1EC");
extern int Anim41Player1F0View1 __asm__("D_80070328 + 0x1F0");
extern int Anim41Player240View1 __asm__("D_80070328 + 0x240");
extern int Anim41Player280View1 __asm__("D_80070328 + 0x280");
extern unsigned char Anim41Player14View1 __asm__("D_80070328 + 0x14");
extern unsigned char Anim41Player15View1 __asm__("D_80070328 + 0x15");
extern unsigned char Anim41Player16View1 __asm__("D_80070328 + 0x16");
extern unsigned char Anim41Player17View1 __asm__("D_80070328 + 0x17");
extern unsigned char Anim41PlayerFCView1 __asm__("D_80070328 + 0xFC");
extern unsigned char Anim41Data66530View1[] __asm__("D_80066530");
extern int Anim41Data6E538View1 __asm__("D_8006E538"),Anim41Data6E53CView1 __asm__("D_8006E53C");
extern int Anim41Data6E044View1 __asm__("D_8006E044"),A4898Gate __asm__("D_8006E344"),A4898Count __asm__("D_8006C514");
int Anim41Call40994View1() __asm__("func_80040994");
int Anim41Call4BEF8View1() __asm__("func_8004BEF8");
int Anim41Call49688View1() __asm__("func_80049688");
extern int Anim41Player4CView1 __asm__("D_80070328 + 0x4C");
extern int Anim41Player54View2 __asm__("D_80070328 + 0x54");
extern int Anim41PlayerB0View1 __asm__("D_80070328 + 0xB0");
extern int Anim41PlayerB8View2 __asm__("D_80070328 + 0xB8");
extern int Anim41Player144View2 __asm__("D_80070328 + 0x144");
extern int Anim41Player158View1 __asm__("D_80070328 + 0x158");
extern int Anim41Player280View2 __asm__("D_80070328 + 0x280");
extern unsigned char Anim41Player0View1[] __asm__("D_80070328");
extern int Anim41Data6E538View2 __asm__("D_8006E538"),Anim41Data6E53CView2 __asm__("D_8006E53C");
extern int Anim41Data6E044View2 __asm__("D_8006E044"),Anim41Data6E344View1 __asm__("D_8006E344"),Anim41Data6C514View1 __asm__("D_8006C514");
extern int (*Anim41Data74374View1)() __asm__("unk_ovlheader_80074374");
extern int Anim41Player24View1 __asm__("D_80070328 + 0x24");
extern unsigned char* Anim41Data6C654View1 __asm__("D_8006C654");
int Anim41CallPlaySoundView1() __asm__("PlaySound");
int Anim41Call40994View2() __asm__("func_80040994");
int Anim41Call4BEF8View2() __asm__("func_8004BEF8");
int Anim41Call4F334View1() __asm__("func_8004F334");
int Anim41Call498C0View1() __asm__("func_800498C0");
extern volatile int Anim41Player20CView1 __asm__("D_80070328 + 0x20C");
extern int Anim41Player214View1 __asm__("D_80070328 + 0x214");
extern unsigned char Anim41Player100View1 __asm__("D_80070328 + 0x100");
extern unsigned char Anim41Data6E535View1 __asm__("D_8006E535");
extern unsigned char* Anim41Data6EE2CView1 __asm__("D_8006EE2C");
int Anim41Call40BCCView1() __asm__("func_80040BCC");
int Anim41Call1A310View1() __asm__("func_8001A310");
extern int Anim41Player4CView2 __asm__("D_80070328 + 0x4C");
extern int Anim41PlayerACView2 __asm__("D_80070328 + 0xAC");
extern int Anim41PlayerB0View2 __asm__("D_80070328 + 0xB0");
extern int Anim41PlayerB8View3 __asm__("D_80070328 + 0xB8");
extern int Anim41PlayerE4View2 __asm__("D_80070328 + 0xE4");
extern int A35Buttons __asm__("D_8006E538"),Anim41Data6E53CView3 __asm__("D_8006E53C");
int Anim41Call40994View3() __asm__("func_80040994");
int Anim41Call4BEF8View3() __asm__("func_8004BEF8");
extern int Anim41PlayerBCView1 __asm__("D_80070328 + 0xBC"), Anim41Player1BCView1 __asm__("D_80070328 + 0x1BC"), Anim41Player60View1 __asm__("D_80070328 + 0x60");
extern short Anim41Player148View1 __asm__("D_80070328 + 0x148");
int Anim41Call43194View1() __asm__("func_80043194");
int Anim41Call4EDE8View1() __asm__("func_8004EDE8");
extern int Anim41Player48View3 __asm__("D_80070328 + 0x48");
extern int Anim41Player4CView3 __asm__("D_80070328 + 0x4C");
extern int Anim41Player54View3 __asm__("D_80070328 + 0x54");
extern int Anim41Player58View1 __asm__("D_80070328 + 0x58");
extern int Anim41Player8CView1 __asm__("D_80070328 + 0x8C");
extern int Anim41Player90View1 __asm__("D_80070328 + 0x90");
extern int Anim41Player94View1 __asm__("D_80070328 + 0x94");
extern int Anim41PlayerA8View2 __asm__("D_80070328 + 0xA8");
extern int Anim41PlayerACView3 __asm__("D_80070328 + 0xAC");
extern int Anim41PlayerB0View3 __asm__("D_80070328 + 0xB0");
extern int Anim41PlayerB8View4 __asm__("D_80070328 + 0xB8");
extern int Anim41PlayerCCView1 __asm__("D_80070328 + 0xCC");
extern int Anim41PlayerD0View1 __asm__("D_80070328 + 0xD0");
extern int Anim41PlayerD4View1 __asm__("D_80070328 + 0xD4");
extern int Anim41PlayerE4View3 __asm__("D_80070328 + 0xE4");
extern int Anim41Player144View3 __asm__("D_80070328 + 0x144");
extern int Anim41Player280View3 __asm__("D_80070328 + 0x280");
extern unsigned char Anim41Player0View2[] __asm__("D_80070328");
extern unsigned char *Anim41Player250View1 __asm__("D_80070328 + 0x250");
extern unsigned char Anim41Data6E535View2 __asm__("D_8006E535");
extern int Anim41Data6E538View3 __asm__("D_8006E538");
extern int Anim41Data6E53CView4 __asm__("D_8006E53C");
extern int Anim41Data6E530View1 __asm__("D_8006E530");
extern int Anim41Data6E52CView1 __asm__("D_8006E52C");
extern int (*Anim41Data7431CView1)(int) __asm__("unk_ovlheader_8007431C");
extern int (*Anim41DataSpawnParticleView1)(int,int,void*,int) __asm__("SpawnParticle");
int Anim41Call55E84View1(void*) __asm__("func_80055E84");
int Anim41Call4BEF8View4(int) __asm__("func_8004BEF8");
extern int Anim41PlayerA4View1 __asm__("D_80070328 + 0xA4");
extern int Anim41PlayerB4View1 __asm__("D_80070328 + 0xB4");
extern int Anim41PlayerA0View1 __asm__("D_80070328 + 0xA0");
int Anim41Call4F1C8View1(void*,void*,void*) __asm__("func_8004F1C8");
int Anim41Call4E880View1(int,int,int) __asm__("func_8004E880");
int Anim41Call3BABCView1(void*,int,int) __asm__("func_8003BABC");
#define Anim41Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
void func_level_41_80093FF8(void){
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int nextSelector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* record16 __asm__("$16");
    register int (*callback3)(int) __asm__("$3");
    struct {
        int at10[4],at20[4];
    }
    frame;
    register int* savedPointer16 __asm__("$16");
    register int* savedPointer17 __asm__("$17");
    rawValue2=Anim41Player48View1;
    switch(rawValue2){
    case 20:
        if(Anim41Call40994View1())return;
        rawValue2=Anim41Data6E53CView1&64;
        nextSelector4=6;
        if(rawValue2)goto select;
        rawValue2=Anim41PlayerB8View1<4;
        nextSelector4=7;
        if(!rawValue2)goto select;
        if(Anim41PlayerE4View1>=23)goto select;
        rawValue3=Anim41Data6E538View1;
        rawValue2=rawValue3&128;
        nextSelector4=13;
        if(rawValue2)goto select;
        rawValue2=Anim41PlayerA8View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        if(rawValue2>=17){
            nextSelector4=1;
            goto select;
        }
        rawValue2=rawValue3&12;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2));
        if(!rawValue2){
            rawValue2=Anim41PlayerACView1;
            nextSelector4=1;
            if(rawValue2)goto select;
        }
        if(Anim41Data6E044View1==7 || Anim41Player240View1) {
            savedPointer16=&Anim41Player48View2;
            __asm__("" : "=r"(savedPointer16):"0"(savedPointer16));
            if(!*savedPointer16)return;
            Anim41Call4BEF8View1(0);
            if(Anim41Data66530View1[*((unsigned char*)savedPointer16-0x2C)]>=96){
                Anim41Player14View1=Anim41Player15View1;
                Anim41Player16View1=Anim41Player17View1;
            }
            Anim41Player17View1=0;
            rawValue3=*savedPointer16;
            rawValue2=113;
            *((unsigned char*)savedPointer16-0x2C)=rawValue2;
            Anim41Player1F0View1=0;
            Anim41Player15View1=rawValue3;
            Anim41Player1ECView1=rawValue3;
            return;
        }
        rawValue2=Anim41PlayerFCView1;
        nextSelector4=15;
        if(rawValue2)goto select;
        Anim41Call49688View1();
        return;
    case 53:case 54:
        if(Anim41Call40994View1())return;
        nextSelector4=0;
        goto select;
    case 29:
        if(Anim41Player54View1<25)return;
        if(Anim41Player280View1<0){
            __asm__ volatile(""::"i"(0x80094214):"memory");
            nextSelector4=31;
            goto select;
        }
        rawValue2=10;
        rawValue3=Anim41Player144View1;
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
        rawValue2=Anim41PlayerB8View1;
        nextSelector4=0;
        if(!rawValue2)goto select;
        __asm__ volatile("" ::: "memory");
        nextSelector4=7;
        goto select;
    case 19:
        if(Anim41Call40994View2())return;
        rawValue2=13;
        rawValue3=Anim41Data6E344View1;
        if(rawValue3==rawValue2){
            rawValue2=Anim41Data6C514View1;
            nextSelector4=17;
            if(rawValue2)goto select;
        }
        nextSelector4=(int)Anim41Player0View1;
        rawValue2=Anim41Call4F334View1((void*)nextSelector4,(void*)(nextSelector4+348));
        rawValue3=Anim41Player158View1;
        rawValue3=rawValue3<rawValue2;
        nextSelector4=17;
        if(!rawValue3)return;
        goto select;
    case 26:
        if(Anim41Player24View1&16)return;
        if(Anim41Player54View2<25)return;
        if(Anim41Player280View2<0){
            nextSelector4=32;
            goto select;
        }
        Anim41CallPlaySoundView1(Anim41Data6C654View1[15],0,0);
        rawValue3=Anim41Player144View2;
        rawValue2=10;
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
        rawValue2=Anim41PlayerB8View2;
        nextSelector4=0;
        if(!rawValue2)goto select;
        __asm__ volatile("" ::: "memory");
        nextSelector4=7;
        goto select;
    case 32:
        if(Anim41Player54View2<125)return;
        call498C0:Anim41Call498C0View1();
        return;
    case 33:
        if(Anim41Call40994View3())return;
        savedPointer17=&Anim41PlayerB8View3;
        __asm__("" : "=r"(savedPointer17):"0"(savedPointer17));
        if(!*savedPointer17){
            if(Anim41PlayerE4View2>=23)Anim41Call4BEF8View3(7);
            if(Anim41PlayerACView2>0){
                rawValue3=Anim41PlayerB0View2;
                rawValue2=rawValue3<3841;
                if(!rawValue2){
                    __asm__ volatile("" ::: "memory");
                    nextSelector4=3;
                    goto select;
                }
                rawValue2=rawValue3<1921;
                __asm__("" : "=r"(rawValue2):"0"(rawValue2));
                nextSelector4=1;
                if(rawValue2)goto select;
                __asm__ volatile("" ::: "memory");
                nextSelector4=2;
                goto select;
            }
            rawValue2=Anim41PlayerB0View2<1920;
            nextSelector4=0;
            if(rawValue2)goto select;
            __asm__ volatile("" ::: "memory");
            nextSelector4=4;
            goto select;
        }
        savedPointer16=&Anim41Data6E53CView3;
        __asm__("" : "=r"(savedPointer16):"0"(savedPointer16));
        rawValue2=*savedPointer16&128;
        nextSelector4=22;
        if(rawValue2)goto select;
        rawValue2=Anim41Call43194View1(4);
        nextSelector4=47;
        if(rawValue2)goto select;
        rawValue2=Anim41PlayerBCView1;
        nextSelector4=7;
        if(!rawValue2)goto select;
        rawValue2=Anim41Player1BCView1;
        nextSelector4=17;
        if(!rawValue2)goto select;
        rawValue2=*savedPointer16&16;
        nextSelector4=18;
        if(rawValue2)goto select;
        nextSelector4=(int)savedPointer17-32;
        rawValue2=Anim41Call4EDE8View1((void*)nextSelector4,1);
        rawValue2=rawValue2<1024;
        nextSelector4=7;
        if(rawValue2)goto select;
        rawValue2=Anim41Player148View1<2;
        nextSelector4=35;
        if(!rawValue2)goto select;
        rawValue2=Anim41Player4CView2;
        nextSelector4=34;
        if(rawValue2)goto select;
        rawValue3=Anim41Player60View1;
        rawValue2=rawValue3<365;
        if(!rawValue2)goto select;
        rawValue2=rawValue3< -364;
        nextSelector4=35;
        if(!rawValue2)return;
        goto select;
    case 34:
        if(Anim41Call40994View3())return;
        savedPointer17=&Anim41PlayerB8View3;
        __asm__("" : "=r"(savedPointer17):"0"(savedPointer17));
        if(!*savedPointer17){
            if(Anim41PlayerE4View2>=23)Anim41Call4BEF8View3(7);
            if(Anim41PlayerACView2>0){
                rawValue3=Anim41PlayerB0View2;
                rawValue2=rawValue3<3841;
                if(!rawValue2){
                    __asm__ volatile("" ::: "memory");
                    nextSelector4=3;
                    goto select;
                }
                rawValue2=rawValue3<1921;
                __asm__("" : "=r"(rawValue2):"0"(rawValue2));
                nextSelector4=1;
                if(rawValue2)goto select;
                __asm__ volatile("" ::: "memory");
                nextSelector4=2;
                goto select;
            }
            rawValue2=Anim41PlayerB0View2<1920;
            nextSelector4=0;
            if(rawValue2)goto select;
            __asm__ volatile("" ::: "memory");
            nextSelector4=4;
            goto select;
        }
        savedPointer16=&Anim41Data6E53CView3;
        __asm__("" : "=r"(savedPointer16):"0"(savedPointer16));
        rawValue2=*savedPointer16&128;
        nextSelector4=22;
        if(rawValue2)goto select;
        rawValue2=Anim41Call43194View1(4);
        nextSelector4=47;
        if(rawValue2)goto select;
        rawValue2=Anim41PlayerBCView1;
        nextSelector4=7;
        if(!rawValue2)goto select;
        rawValue2=Anim41Player1BCView1;
        nextSelector4=17;
        if(!rawValue2)goto select;
        rawValue2=*savedPointer16&16;
        nextSelector4=18;
        if(rawValue2)goto select;
        nextSelector4=(int)savedPointer17-32;
        rawValue2=Anim41Call4EDE8View1((void*)nextSelector4,1);
        rawValue2=rawValue2<1024;
        nextSelector4=7;
        if(rawValue2)goto select;
        rawValue2=Anim41Player148View1<2;
        nextSelector4=35;
        if(!rawValue2)goto select;
        if(Anim41Player60View1>=256)return;
        rawValue2=Anim41Player4CView2;
        nextSelector4=33;
        if(rawValue2)return;
        goto select;
    case 35:
        if(Anim41Call40994View3())return;
        savedPointer17=&Anim41PlayerB8View3;
        __asm__("" : "=r"(savedPointer17):"0"(savedPointer17));
        if(!*savedPointer17){
            if(Anim41PlayerE4View2>=23)Anim41Call4BEF8View3(7);
            if(Anim41PlayerACView2>0){
                rawValue3=Anim41PlayerB0View2;
                rawValue2=rawValue3<3841;
                if(!rawValue2){
                    nextSelector4=3;
                    goto select;
                }
                rawValue2=rawValue3<1921;
                __asm__("" : "=r"(rawValue2):"0"(rawValue2));
                nextSelector4=1;
                if(rawValue2)goto select;
                __asm__ volatile("" ::: "memory");
                nextSelector4=2;
                goto select;
            }
            rawValue2=Anim41PlayerB0View2<1920;
            nextSelector4=0;
            if(rawValue2)goto select;
            __asm__ volatile("" ::: "memory");
            nextSelector4=4;
            goto select;
        }
        savedPointer16=&Anim41Data6E53CView3;
        __asm__("" : "=r"(savedPointer16):"0"(savedPointer16));
        rawValue2=*savedPointer16&128;
        nextSelector4=22;
        if(rawValue2)goto select;
        rawValue2=Anim41Call43194View1(4);
        nextSelector4=47;
        if(rawValue2)goto select;
        rawValue2=Anim41PlayerBCView1;
        nextSelector4=7;
        if(!rawValue2)goto select;
        rawValue2=Anim41Player1BCView1;
        nextSelector4=17;
        if(!rawValue2)goto select;
        rawValue2=*savedPointer16&16;
        nextSelector4=18;
        if(rawValue2)goto select;
        nextSelector4=(int)savedPointer17-32;
        rawValue2=Anim41Call4EDE8View1((void*)nextSelector4,1);
        rawValue2=rawValue2<1024;
        nextSelector4=7;
        if(rawValue2)goto select;
        if(Anim41Player148View1>=2)return;
        rawValue2=Anim41Player4CView2;
        nextSelector4=34;
        if(rawValue2)goto select;
        rawValue2=Anim41Player60View1< -255;
        nextSelector4=33;
        if(rawValue2)return;
        goto select;
    case 40:
        if(Anim41Call40994View2())return;
        if((Anim41Data6E538View2&128) && Anim41Player4CView1!=1){
            nextSelector4=42;
            goto select;
        }
        if(Anim41PlayerB0View1)return;
        rawValue2=Anim41Player20CView1&64;
        nextSelector4=41;
        if(!rawValue2)goto select;
        if(Anim41Player214View1<=0)return;
        goto select;
    case 41:
        if(Anim41Call40994View2())return;
        nextSelector4=Anim41Data6E538View2;
        rawValue2=nextSelector4&128;
        if(rawValue2){
            nextSelector4=42;
            goto select;
        }
        rawValue2=7;
        rawValue3=Anim41Data6E044View2;
        if(rawValue3==rawValue2)return;
        rawValue2=nextSelector4&64;
        nextSelector4=40;
        if(rawValue2)goto select;
        if(!(Anim41Player20CView1&64))return;
        if(!Anim41Player214View1)goto select;
        return;
    case 42:
        if(Anim41Call40BCCView1())return;
        if((Anim41Data6E538View2&128) || Anim41Player4CView1==1)goto flag64;
        rawValue2=Anim41Player20CView1&128;
        nextSelector4=40;
        if(!rawValue2)goto select;
        flag64:rawValue2=Anim41Player20CView1&64;
        nextSelector4=40;
        if(!rawValue2)return;
        goto select;
    case 43:
        {
            register unsigned char* byte4 __asm__("$4");
            if(Anim41Call40994View2())return;
            if((Anim41Data6E53CView2&64) && Anim41Player54View2>=9){
                nextSelector4=6;
                goto partialCall;
            }
            byte4=&Anim41Player100View1;
            __asm__("" : "=r"(byte4):"0"(byte4));
            if(!*byte4){
                nextSelector4=7;
                goto partialCall;
            }
            if(!(Anim41Data6E53CView2&128))goto check44;
            if(Anim41Player54View2<9)goto check44;
            rawValue2=*(int*)(Anim41Data6EE2CView1+220);
            byte4-=256;
            if(!rawValue2)goto check44;
            rawValue2=Anim41Call1A310View1(byte4,1024,1,0);
            nextSelector4=40;
            if(rawValue2)goto check44;
            goto select;
            partialCall:Anim41Call4BEF8View2(nextSelector4);
            check44:rawValue2=Anim41Data6E535View1;
            nextSelector4=44;
            if(!rawValue2)return;
            goto select;
        }
    case 44:
        {
            register unsigned char* byte4 __asm__("$4");
            register int (*callback2)() __asm__("$2");
            rawValue3=Anim41Player4CView1;
            rawValue2=1;
            if(rawValue3!=rawValue2)goto other44;
            if(Anim41Data6E53CView2&0x850)goto callback44;
            if(Anim41Player54View2<61)return;
            callback44:callback2=Anim41Data74374View1;
            __asm__("" : "=r"(callback2):"0"(callback2));
            if(!callback2)goto missingCallback;
            callback2();
            return;
            missingCallback:goto call498C0;
            other44:if(Anim41Call40994View2())return;
            if((Anim41Data6E53CView2&64) && Anim41Player54View2>=9){
                nextSelector4=6;
                goto select;
            }
            byte4=&Anim41Player100View1;
            __asm__("" : "=r"(byte4):"0"(byte4));
            if(!*byte4){
                nextSelector4=7;
                goto select;
            }
            if(!(Anim41Data6E53CView2&128))goto mode44;
            if(Anim41Player54View2<9)goto mode44;
            rawValue2=*(int*)(Anim41Data6EE2CView1+220);
            byte4-=256;
            if(!rawValue2)goto mode44;
            rawValue2=Anim41Call1A310View1(byte4,1024,1,0);
            nextSelector4=40;
            if(!rawValue2)goto select;
            mode44:rawValue3=Anim41Data6E044View2;
            rawValue2=7;
            if(rawValue3==rawValue2)return;
            rawValue2=Anim41Data6E535View1;
            nextSelector4=43;
            if(rawValue2)return;
            goto select;
        }
    case 49:
        if(Anim41Call40994View1())return;
        rawValue2=Anim41PlayerB8View1<4;
        nextSelector4=7;
        if(!rawValue2)goto select;
        rawValue2=Anim41Player144View1<16;
        nextSelector4=0;
        if(rawValue2)return;
        goto select;
    case 57:
        if(Anim41Player54View2<25)return;
        if(Anim41Player280View2<0){
            nextSelector4=31;
            goto select;
        }
        rawValue2=10;
        rawValue3=Anim41Player144View2;
        nextSelector4=41;
        if(rawValue3!=rawValue2)goto select;
        nextSelector4=44;
        goto select;
    case 85:
        rawValue2=Anim41Data7431CView1(1);
        if(rawValue2)return;
        rawValue3=Anim41Data6E53CView4;
        rawValue2=rawValue3&64;
        nextSelector4=93;
        if(rawValue2)goto select;
        rawValue2=Anim41PlayerB8View4<4;
        nextSelector4=89;
        if(!rawValue2)goto select;
        rawValue2=Anim41PlayerE4View3<23;
        if(!rawValue2)goto select;
        rawValue2=rawValue3&32;
        nextSelector4=87;
        if(rawValue2)goto select;
        rawValue2=rawValue3&128;
        nextSelector4=91;
        if(rawValue2)goto select;
        rawValue2=Anim41PlayerA8View2;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<17;
        nextSelector4=86;
        if(!rawValue2)goto select;
        rawValue2=Anim41Data6E538View3&12;
        if(rawValue2)return;
        rawValue2=Anim41PlayerACView3;
        if(!rawValue2)return;
        goto select;
    case 86:
        rawValue2=(int)Anim41Player250View1;
        callback3=Anim41Data7431CView1;
        record16=Anim41Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue3=Anim41Data6E53CView4;
        rawValue2=rawValue3&64;
        nextSelector4=93;
        if(rawValue2)goto select;
        rawValue2=Anim41PlayerB8View4<4;
        nextSelector4=89;
        if(!rawValue2)goto select;
        rawValue2=Anim41PlayerE4View3<23;
        if(!rawValue2)goto select;
        rawValue2=rawValue3&32;
        nextSelector4=87;
        if(rawValue2)goto select;
        rawValue2=rawValue3&128;
        nextSelector4=91;
        if(rawValue2)goto select;
        rawValue2=Anim41Data6E535View2;
        if(!rawValue2)goto held86;
        rawValue2=Anim41PlayerB0View3;
        nextSelector4=85;
        if(!rawValue2)goto select;
        held86:rawValue2=Anim41Data6E538View3&12;
        if(!rawValue2)goto angle86;
        rawValue2=Anim41Player144View3<16;
        nextSelector4=85;
        if(!rawValue2)goto select;
        angle86:rawValue2=Anim41Field(record16,int*,0x4C);
        nextSelector4=(int)frame.at10;
        if(!rawValue2)goto distance86;
        Anim41Call4F1C8View1((void*)nextSelector4,(void*)(rawValue2+12),Anim41Player0View2);
        rawValue2=Anim41Call4E880View1(frame.at10[0],frame.at10[1],1);
        rawValue3=Anim41PlayerA4View1;
        rawValue2-=rawValue3;
        rawValue3=rawValue2&4095;
        rawValue2=rawValue3<2049;
        if(!rawValue2)rawValue3-=4096;
        rawValue2=rawValue3;
        if(rawValue3<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<256;
        nextSelector4=96;
        if(rawValue2)goto select;
        distance86:rawValue2=Anim41PlayerB4View1<3585;
        if(rawValue2)return;
        nextSelector4=(int)Anim41Player250View1;
        rawValue2=Anim41Call55E84View1((void*)nextSelector4);
        rawValue2=rawValue2<33;
        nextSelector4=92;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x80094EB8):"memory");
        goto select;
    case 87:
        rawValue2=Anim41Data7431CView1(1);
        if(rawValue2)return;
        nextSelector4=(int)Anim41Player250View1;
        rawValue2=Anim41Player48View3;
        rawValue3=Anim41Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=85;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim41Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        rawValue2=Anim41PlayerB8View4<4;
        if(!rawValue2)goto airborne87;
        rawValue2=Anim41PlayerE4View3<23;
        if(rawValue2)goto ground87;
        airborne87:__asm__ volatile(""::"i"(0x80094F40):"memory");
        nextSelector4=89;
        goto select;
        ground87:rawValue2=Anim41PlayerACView3;
        nextSelector4=86;
        if(!rawValue2)goto select85;
        __asm__ volatile(""::"i"(0x80094F5C):"memory");
        goto select;
    case 88:
        nextSelector4=(int)Anim41Player250View1;
        rawValue2=Anim41Player48View3;
        rawValue3=Anim41Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=85;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim41Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        rawValue2=Anim41Player280View3;
        nextSelector4=90;
        if(rawValue2<0)goto select;
        rawValue2=Anim41PlayerB8View4;
        nextSelector4=89;
        if(!rawValue2)goto select85;
        goto select;
    case 89:
        rawValue2=Anim41Data7431CView1(1);
        if(rawValue2)return;
        rawValue2=Anim41PlayerB8View4;
        if(rawValue2)return;
        rawValue2=Anim41PlayerE4View3<23;
        if(!rawValue2)return;
        rawValue2=Anim41PlayerACView3;
        nextSelector4=86;
        if(!rawValue2)nextSelector4=85;
        Anim41Call4BEF8View4(nextSelector4);
        {
            register int (*spawn2)(int,int,void*,int) __asm__("$2")=Anim41DataSpawnParticleView1;
            if(spawn2)spawn2(8,33,0,2);
        }
        product5=2;
        nextSelector4=(int)Anim41Player250View1;
        Anim41Call3BABCView1((void*)nextSelector4,product5,0);
        rawValue2=Anim41Player58View1<24;
        if(rawValue2)return;
        rawValue2=120;
        Anim41Data6E530View1=rawValue2;
        rawValue2=15;
        Anim41Data6E52CView1=rawValue2;
        return;
    case 90:
        nextSelector4=(int)Anim41Player250View1;
        rawValue2=Anim41Player48View3;
        rawValue3=Anim41Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=85;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim41Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        goto call498C0;
    case 91:
        rawValue2=Anim41Data7431CView1(1);
        if(rawValue2)return;
        rawValue2=Anim41PlayerB8View4<4;
        if(!rawValue2)goto airborne91;
        rawValue2=Anim41PlayerE4View3<23;
        if(rawValue2)goto held91;
        airborne91:__asm__ volatile(""::"i"(0x80095124):"memory");
        nextSelector4=89;
        goto select;
        held91:rawValue2=Anim41Data6E538View3&128;
        if(rawValue2)goto age91;
        rawValue2=Anim41Player54View3<30;
        if(!rawValue2)goto input91;
        age91:rawValue2=Anim41Player54View3<120;
        if(rawValue2)return;
        input91:rawValue2=Anim41Data6E535View2;
        nextSelector4=85;
        if(rawValue2)goto select;
        nextSelector4=86;
        goto select;
    case 92:
        rawValue2=(int)Anim41Player250View1;
        callback3=Anim41Data7431CView1;
        record16=Anim41Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue3=Anim41Data6E53CView4;
        rawValue2=rawValue3&64;
        nextSelector4=93;
        if(rawValue2)goto select;
        rawValue2=Anim41PlayerB8View4<4;
        nextSelector4=89;
        if(!rawValue2)goto select;
        rawValue2=Anim41PlayerE4View3<23;
        if(!rawValue2)goto select;
        rawValue2=rawValue3&32;
        nextSelector4=87;
        if(rawValue2)goto select;
        rawValue2=rawValue3&128;
        nextSelector4=91;
        if(rawValue2)goto select;
        rawValue2=Anim41Data6E535View2;
        if(!rawValue2)goto held92;
        rawValue2=Anim41PlayerB0View3;
        nextSelector4=85;
        if(!rawValue2)goto select;
        held92:rawValue2=Anim41Data6E538View3&12;
        if(!rawValue2)goto angle92;
        rawValue2=Anim41Player144View3<16;
        nextSelector4=85;
        if(!rawValue2)goto select;
        angle92:rawValue2=Anim41Field(record16,int*,0x4C);
        nextSelector4=(int)frame.at10;
        if(!rawValue2)goto distance92;
        Anim41Call4F1C8View1((void*)nextSelector4,(void*)(rawValue2+12),Anim41Player0View2);
        rawValue2=Anim41Call4E880View1(frame.at10[0],frame.at10[1],1);
        rawValue3=Anim41PlayerA4View1;
        rawValue2-=rawValue3;
        rawValue3=rawValue2&4095;
        rawValue2=rawValue3<2049;
        if(!rawValue2)rawValue3-=4096;
        rawValue2=rawValue3;
        if(rawValue3<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<256;
        nextSelector4=96;
        if(rawValue2)goto select;
        distance92:rawValue2=Anim41PlayerB4View1<3072;
        if(!rawValue2)return;
        rawValue3=(int)Anim41Player250View1;
        rawValue2=Anim41Field((void*)rawValue3,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        rawValue2=Anim41Player48View3;
        rawValue3=Anim41Field((void*)rawValue3,unsigned char*,0x3C);
        rawValue2-=85;
        nextSelector4=86;
        if(rawValue3!=rawValue2)return;
        __asm__ volatile(""::"i"(0x80095324):"memory");
        goto select;
    case 93:
        rawValue2=Anim41Data7431CView1(1);
        if(rawValue2)return;
        rawValue2=Anim41Data6E53CView4&32;
        nextSelector4=87;
        if(rawValue2)goto select;
        rawValue2=Anim41PlayerB8View4;
        if(rawValue2)goto finish93;
        rawValue2=Anim41Player54View3<16;
        if(rawValue2)goto finish93;
        rawValue2=Anim41PlayerE4View3<23;
        if(!rawValue2)return;
        rawValue3=Anim41PlayerCCView1;
        rawValue2=Anim41Player8CView1;
        product5=rawValue3*rawValue2;
        rawValue3=Anim41PlayerD0View1;
        rawValue2=Anim41Player90View1;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim41PlayerD4View1;
        rawValue2=Anim41Player94View1;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)return;
        rawValue2=Anim41PlayerACView3;
        nextSelector4=86;
        if(!rawValue2)goto select85;
        __asm__ volatile(""::"i"(0x8009541C):"memory");
        goto select;
        finish93:nextSelector4=(int)Anim41Player250View1;
        rawValue2=Anim41Player48View3;
        rawValue3=Anim41Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=85;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim41Field((void*)nextSelector4,unsigned char*,0x42)&2;
        nextSelector4=94;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x80095458):"memory");
        goto select;
    case 94:
        rawValue2=Anim41Data7431CView1(1);
        if(rawValue2)return;
        rawValue2=Anim41Data6E53CView4&32;
        nextSelector4=87;
        if(rawValue2)goto select;
        rawValue2=Anim41PlayerB8View4;
        if(rawValue2)goto finish94;
        rawValue2=Anim41Player54View3<16;
        if(rawValue2)goto finish94;
        rawValue2=Anim41PlayerE4View3<23;
        if(!rawValue2)return;
        rawValue3=Anim41PlayerCCView1;
        rawValue2=Anim41Player8CView1;
        product5=rawValue3*rawValue2;
        rawValue3=Anim41PlayerD0View1;
        rawValue2=Anim41Player90View1;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim41PlayerD4View1;
        rawValue2=Anim41Player94View1;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)return;
        rawValue2=Anim41PlayerACView3;
        nextSelector4=86;
        if(!rawValue2)goto select85;
        __asm__ volatile(""::"i"(0x80095550):"memory");
        goto select;
        finish94:rawValue3=Anim41Player4CView3;
        rawValue2=1;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim41PlayerA0View1<-6400;
        nextSelector4=89;
        if(rawValue2)goto select;
        rawValue2=Anim41Player54View3<121;
        if(!rawValue2)goto select;
        return;
    case 95:
        rawValue2=(int)Anim41Player250View1;
        callback3=Anim41Data7431CView1;
        record16=Anim41Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue2=Anim41PlayerB8View4<4;
        if(!rawValue2)goto airborne95;
        rawValue2=Anim41PlayerE4View3<23;
        if(rawValue2)goto input95;
        airborne95:__asm__ volatile(""::"i"(0x800955F8):"memory");
        nextSelector4=89;
        goto select;
        input95:rawValue2=Anim41Data6E535View2;
        if(!rawValue2)goto held95;
        rawValue2=Anim41PlayerB0View3;
        nextSelector4=97;
        if(!rawValue2)goto select;
        held95:rawValue2=Anim41Data6E538View3&12;
        if(!rawValue2)goto private95;
        rawValue2=Anim41Player144View3<16;
        nextSelector4=97;
        if(!rawValue2)goto select;
        private95:rawValue2=Anim41Field(record16,int*,0x58)<16;
        nextSelector4=97;
        if(!rawValue2)goto select;
        rawValue2=Anim41Field(record16,int*,0x4C);
        nextSelector4=(int)frame.at10;
        if(!rawValue2)return;
        Anim41Call4F1C8View1((void*)nextSelector4,(void*)(rawValue2+12),Anim41Player0View2);
        rawValue2=Anim41Call4E880View1(frame.at10[0],frame.at10[1],1);
        rawValue3=Anim41PlayerA4View1;
        rawValue2-=rawValue3;
        rawValue3=rawValue2&4095;
        rawValue2=rawValue3<2049;
        if(!rawValue2)rawValue3-=4096;
        rawValue2=rawValue3;
        if(rawValue3<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<321;
        nextSelector4=97;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x800956D8):"memory");
        goto select;
    case 96:
        rawValue2=(int)Anim41Player250View1;
        callback3=Anim41Data7431CView1;
        record16=Anim41Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue2=Anim41PlayerB8View4<4;
        if(!rawValue2)goto airborne96;
        rawValue2=Anim41PlayerE4View3<23;
        if(rawValue2)goto input96;
        airborne96:__asm__ volatile(""::"i"(0x80095734):"memory");
        nextSelector4=89;
        goto select;
        input96:rawValue2=Anim41Data6E535View2;
        if(!rawValue2)goto held96;
        rawValue2=Anim41PlayerB0View3;
        nextSelector4=97;
        if(!rawValue2)goto select;
        held96:rawValue2=Anim41Data6E538View3&12;
        if(!rawValue2)goto private96;
        rawValue2=Anim41Player144View3<16;
        nextSelector4=97;
        if(!rawValue2)goto select;
        private96:rawValue2=Anim41Field(record16,int*,0x58)<16;
        nextSelector4=97;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim41Player250View1;
        rawValue2=Anim41Player48View3;
        rawValue3=Anim41Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=85;
        if(rawValue3!=rawValue2)goto angle96;
        rawValue2=Anim41Field((void*)nextSelector4,unsigned char*,0x42)&2;
        nextSelector4=95;
        if(rawValue2)goto select;
        angle96:rawValue2=Anim41Field(record16,int*,0x4C);
        nextSelector4=(int)frame.at20;
        if(!rawValue2)return;
        Anim41Call4F1C8View1((void*)nextSelector4,(void*)(rawValue2+12),Anim41Player0View2);
        rawValue2=Anim41Call4E880View1(frame.at20[0],frame.at20[1],1);
        rawValue3=Anim41PlayerA4View1;
        rawValue2-=rawValue3;
        rawValue3=rawValue2&4095;
        rawValue2=rawValue3<2049;
        if(!rawValue2)rawValue3-=4096;
        rawValue2=rawValue3;
        if(rawValue3<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<321;
        nextSelector4=97;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x80095848):"memory");
        goto select;
    case 97:
        rawValue2=Anim41Data7431CView1(1);
        if(rawValue2)return;
        rawValue2=Anim41PlayerB8View4<4;
        if(!rawValue2)goto airborne97;
        rawValue2=Anim41PlayerE4View3<23;
        if(rawValue2)goto finish97;
        airborne97:__asm__ volatile(""::"i"(0x8009589C):"memory");
        nextSelector4=89;
        goto select;
        finish97:nextSelector4=(int)Anim41Player250View1;
        rawValue2=Anim41Player48View3;
        rawValue3=Anim41Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=85;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim41Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        select85:nextSelector4=85;
        goto select;
        default:return;
    }
    select:Anim41Call4BEF8View1(nextSelector4);
    return;
}
#undef Anim41Field
