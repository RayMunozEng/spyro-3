#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8009153C.
 * Assembly SHA256 4cdcd5f48f682b78ab85584a187c9c471206279d226dfb807fb72c74dbba5ede.
 * AI-generated; not human reviewed. All1785 original instructions,
 * 59 selectors (bias19) and one owned padding word are required.
 * Frame0x140 retains scratch10..124, savedS0..S4, slotS2 and combinedS3.
 * Fourteen exact groups reuse verified11/34/42 with original frame/address
 * mappings. Near43 retains the original S0-relative +52/+64 clear arguments.
 * Near47's former clear sequence belongs to original30 at80091FC8.
 * Complete65..77 retains all original Sheila scalar/vector/input/particle
 * and child-pointer paths;66/71 preserve their shared A2-relative vector tail.
 * Typed aliases remain distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit every word.
 * Identified Rev1 Sheila source tables support interpretation; all original
 * Rev0 native/linked instructions and full retail hashes remain required.
 * Raw units/fixed point, complete helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every native/linked instruction, conditional/internal target,
 * selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
#define Physics23Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Physics23Call363DCView1() __asm__("func_800363DC");
unsigned char Physics23Call40D10View1() __asm__("func_80040D10");
unsigned char Physics23Call41580View1() __asm__("func_80041580");
unsigned char Physics23Call417FCView1() __asm__("func_800417FC");
unsigned char Physics23Call41B64View1() __asm__("func_80041B64");
int Physics23Call4E9E4View1() __asm__("func_8004E9E4");
int Physics23Call4EA2CView1() __asm__("func_8004EA2C");
unsigned char Physics23Call4ED6CView1() __asm__("func_8004ED6C");
int Physics23Call4EDE8View1() __asm__("func_8004EDE8");
unsigned char Physics23Call4F08CView1() __asm__("func_8004F08C");
unsigned char Physics23Call4F194View1() __asm__("func_8004F194");
unsigned char Physics23Call4F1C8View1() __asm__("func_8004F1C8");
int Physics23CallRandView1() __asm__("rand");
extern unsigned char Physics23Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics23Data65920View1 __asm__("D_80065920");
extern void *Physics23Data6C570View1 __asm__("D_8006C570");
extern unsigned char Physics23Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics23Player0View1 __asm__("D_80070328");
extern int Physics23Player94View1 __asm__("D_80070328+0x94");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics23Call40D10View2() __asm__("func_80040D10");
int Physics23Call41580View2() __asm__("func_80041580");
int Physics23Call416F4View1() __asm__("func_800416F4");
int Physics23Call417FCView2() __asm__("func_800417FC");
int Physics23Call41848View1() __asm__("func_80041848");
int Physics23Call41B64View2() __asm__("func_80041B64");
int Physics23Call4EDE8View2() __asm__("func_8004EDE8");
int Physics23Call4F08CView2() __asm__("func_8004F08C");
int Physics23Call4F168View1() __asm__("func_8004F168");
int Physics23Call4F178View1() __asm__("func_8004F178");
int Physics23Call4F194View2() __asm__("func_8004F194");
int Physics23Call4F1C8View2() __asm__("func_8004F1C8");
extern int Physics23Data6E044View1 __asm__("D_8006E044");
extern int Physics23Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics23Player0View2 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics23PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics23Player94View2 __asm__("D_80070328+0x94");
extern int Physics23PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics23PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics23Player64View1 __asm__("D_80070328+0x64");
extern int Physics23Player88View1 __asm__("D_80070328+0x88");
extern int Physics23Player84View1 __asm__("D_80070328+0x84");
extern int Physics23Player144View1 __asm__("D_80070328+0x144");
extern int Physics23PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics23Player4CView1 __asm__("D_80070328+0x4C");
extern unsigned char Physics23PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics23PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics23Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics23Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics23Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics23Player101View1 __asm__("D_80070328+0x101");
extern int Physics23PlayerA4View1 __asm__("D_80070328+0xA4");
int Physics23Call40F48View1() __asm__("func_80040F48");
int Physics23Call43194View1() __asm__("func_80043194");
int Physics23Call4E880View1() __asm__("func_8004E880");
int Physics23Call4ED6CView2() __asm__("func_8004ED6C");
int Physics23Call4EDE8View3() __asm__("func_8004EDE8");
int Physics23Call4F08CView3() __asm__("func_8004F08C");
int Physics23Call4F168View2() __asm__("func_8004F168");
int Physics23Call4F178View2() __asm__("func_8004F178");
int Physics23Call4F194View3() __asm__("func_8004F194");
int Physics23Call4F1C8View3() __asm__("func_8004F1C8");
extern unsigned char Physics23Data658A0View2 __asm__("D_800658A0");
extern unsigned char Physics23Data65920View2 __asm__("D_80065920");
extern int Physics23Data6C514View1 __asm__("D_8006C514");
extern int Physics23Data6E044View2 __asm__("D_8006E044");
extern int Physics23Data6E344View1 __asm__("D_8006E344");
extern unsigned char Physics23Player0View3 __asm__("D_80070328");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics23Player16CView1 __asm__("D_80070328+0x16C");
extern void *(*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics23PlayerE4View1 __asm__("D_80070328+0xE4");
int Physics23Call40D10View3() __asm__("func_80040D10");
int Physics23Call41580View3() __asm__("func_80041580");
int Physics23Call417FCView3() __asm__("func_800417FC");
int Physics23Call41848View2() __asm__("func_80041848");
int Physics23Call41B64View3() __asm__("func_80041B64");
int Physics23Call4ED6CView3() __asm__("func_8004ED6C");
int Physics23Call4F110View1() __asm__("func_8004F110");
int Physics23Call4F168View3() __asm__("func_8004F168");
int Physics23Call4F178View3() __asm__("func_8004F178");
int Physics23Call4F194View4() __asm__("func_8004F194");
int Physics23CallRandView2() __asm__("rand");
extern int Physics23Data6C640View1 __asm__("D_8006C640");
extern int Physics23Data6E044View3 __asm__("D_8006E044");
extern unsigned char Physics23Player0View4 __asm__("D_80070328");
extern void *(*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics50_SpawnParticle)() __asm__("SpawnParticle");
int Physics23Call4F110View2() __asm__("func_8004F110");
int Physics23Call4F178View4() __asm__("func_8004F178");
int Physics23Call4F194View5() __asm__("func_8004F194");
extern int Physics23Data6E1D4View1 __asm__("D_8006E1D4");
extern int Physics23Data6E1D8View1 __asm__("D_8006E1D8");
extern int Physics23Data6E52CView1 __asm__("D_8006E52C");
extern int Physics23Data6E530View1 __asm__("D_8006E530");
extern void *(*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics23Player250View1 __asm__("D_80070328+0x250");
extern int Physics23Player54View1 __asm__("D_80070328+0x54");
extern int Physics23PlayerD4View1 __asm__("D_80070328+0xD4");
extern void *Physics23Data6C654View1 __asm__("D_8006C654");
int Physics23DataPlaySoundView1() __asm__("PlaySound");
extern int Physics23Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics23Player90View1 __asm__("D_80070328+0x90");
extern void *(*Physics23_SpawnParticle)() __asm__("SpawnParticle");
void func_level_23_8009153C(int slotIndex) {
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
        int sp10,sp14,sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4,spB8,spBC,spC0,spC4,spC8,spCC,spD0,spD4,spD8,spDC,spE0,spE4,spE8,spEC,spF0,spF4,spF8,spFC,sp100,sp104,sp108,sp10C,sp110,sp114,sp118,sp11C,sp120,sp124;
    }
    originalFrame;
    register int signedTableWord __asm__("$7");
    register void *globalVector80 __asm__("$16");
    register void *globalVector8CState20 __asm__("$18");
    register void *globalVector8C __asm__("$18");
    register void *var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$19");
    int temp_v0_4;
    register int workWord3 __asm__("$3");
    register int particleIndex __asm__("$17");
    register int nextField94 __asm__("$2");
    register unsigned char *globalByteE __asm__("$18");
    register void *globalField4CPointer __asm__("$16");
    register void *globalFieldA4Pointer __asm__("$17");
    void *temp_v0_5;
    register int savedSlotIndex __asm__("$18");
    int lowProduct6;
    int raw21_var_a0_2;
    int raw21_var_a1_4;
    int raw21_temp_a0_7;
    int raw21_temp_a1_4;
    int raw21_var_v0_2;
    void *raw21_temp_s0_11;
    void *raw21_temp_s1_7;
    void *raw21_temp_s2_3;
    void *raw21_temp_s4;
    savedSlotIndex=slotIndex;
    workWord2=savedSlotIndex*16;
    globalPointer=&Physics23Data6E548View1;
    workWord2+=(int)globalPointer;
    __asm__("":"=r"(workWord2):"0"(workWord2));
    Physics23Data6C570View1=(void*)workWord2;
    workWord2=Physics23Field(&Physics23Player0View1,int*,0x54);
    stateWord3=Physics23Field(&Physics23Player0View1,int*,0x48);
    combinedIndex=workWord2+savedSlotIndex;
    switch (stateWord3) {
    case 19:{
            int product19;
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            register int numeric7 __asm__("$7");
            register int angle16 __asm__("$16");
            register int square8 __asm__("$8");
            register int product10 __asm__("$10");
            workWord3=Physics23Data6E344View1;
            workWord2=13;
            if(workWord3==workWord2){
                workWord2=Physics23Data6C514View1;
                if(workWord2)return;
            }
            vectorAt30=&Physics23Player0View3+8;
            workWord3=Physics23Field(vectorAt30,int*,0);
            workWord2=Physics23Field(&Physics23Player0View3,int*,0x144);
            numeric4=workWord3-workWord2;
            workWord2=numeric4<1024;
            if(!workWord2)goto beyond19;
            workWord2=Physics23Player94View2;
            workWord2+=128;
            Physics23Player94View2=workWord2;
            workWord2=workWord2<4801;
            __asm__("":"=r"(numeric4):"0"(numeric4),"r"(workWord2));
            if(!workWord2){
                workWord2=4800;
                Physics23Player94View2=workWord2;
            }
            product19=numeric4*numeric4;
            call4=&originalFrame.sp10;
            workWord3=Physics23Field(&Physics23Player0View3,int*,0x148);
            __asm__ volatile(""::"r"(workWord2),"r"(workWord3),"r"(call4):"memory");
            workWord2=product19>>11;
            angle16=workWord2+workWord3;
            Physics23Player64View1=angle16;
            __asm__ volatile("":"=r"(vectorAt30):"0"(vectorAt30),"r"(call4):"memory");
            Physics23Call4F178View2(call4,vectorAt30+340);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics23Call4F1C8View3(call4,call5,vectorAt30-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            workWord2=Physics23Call4EDE8View3(call4,call5);
            numeric6=workWord2;
            workWord2=numeric6<1025;
            call4=&originalFrame.sp10;
            if(workWord2)goto commit19;
            call5=(void*)numeric6;
            __asm__ volatile(""::"i"(0x8009168C):"memory");
            numeric6=1024;
            goto limit19;
            beyond19:numeric5=Physics23Field(&Physics23Player0View3,int*,0x14C);
            workWord2=workWord3-numeric5;
            workWord2=workWord2<-1024;
            numeric6=numeric5-workWord3;
            if(!workWord2)goto curve19;
            __asm__ volatile("":"=r"(numeric6):"0"(numeric6),"i"(0x800916B0));
            workWord2=Physics23Player4CView1;
            workWord3=1;
            if(!workWord2){
                workWord2=Physics23Field(&Physics23Player0View3,int*,0x148);
                Physics23Player4CView1=workWord3;
                workWord2+=512;
                Physics23Field(&Physics23Player0View3,int*,0x148)=workWord2;
            }
            workWord2=Physics23Player94View2;
            workWord2+=128;
            Physics23Player94View2=workWord2;
            workWord2=workWord2<4801;
            if(!workWord2)Physics23Player94View2=4800;
            workWord2=Physics23Field(&Physics23Player0View3,int*,0x150);
            numeric6=numeric4-1024;
            workWord3=workWord2*numeric6;
            workWord2=Physics23Field(&Physics23Player0View3,int*,0x154);
            workWord2=workWord3/workWord2;
            call4=&originalFrame.sp10;
            workWord3=Physics23Field(&Physics23Player0View3,int*,0x148);
            angle16=workWord3+workWord2;
            workWord2=(numeric6<<10)>>10;
            workWord2=angle16+workWord2;
            angle16=workWord2&4095;
            Physics23Player64View1=angle16;
            Physics23Call4F178View2(call4,vectorAt30+340);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics23Call4F1C8View3(call4,call5,vectorAt30-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            workWord2=Physics23Call4EDE8View3(call4,call5);
            numeric6=workWord2;
            workWord2=numeric6<1025;
            call4=&originalFrame.sp10;
            if(workWord2)goto commit19;
            call5=(void*)numeric6;
            __asm__ volatile(""::"i"(0x800917C0):"memory");
            numeric6=1024;
            goto limit19;
            curve19:__asm__ volatile("":"=r"(numeric6):"0"(numeric6),"i"(0x800917C8));
            workWord2=(numeric6*4800)>>10;
            Physics23Player94View2=workWord2;
            workWord2=Physics23Player16CView1;
            numeric7=Physics23Field(&Physics23Player0View3,int*,0x168);
            workWord3=Physics23Field(&Physics23Player0View3,int*,0x158);
            workWord2&=127;
            numeric4=numeric7<<1;
            Physics23Player16CView1=workWord2;
            workWord2=*(short*)(&Physics23Data65920View2+numeric4);
            workWord3+=1024;
            product10=workWord3*workWord2;
            square8=numeric6*numeric6;
            workWord2=product10>>12;
            originalFrame.sp10=workWord2;
            workWord2=*(short*)(&Physics23Data658A0View2+numeric4);
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
            Physics23Call4F194View3(call4,call5,numeric6,numeric7);
            call4=&originalFrame.sp10;
            call5=call4;
            Physics23Player64View1=angle16;
            Physics23Call4F1C8View3(call4,call5,vectorAt30-8);
            call4=&originalFrame.sp10;
            call5=0;
            originalFrame.sp18=0;
            workWord2=Physics23Call4EDE8View3(call4,call5);
            numeric6=workWord2;
            workWord2=numeric6<2049;
            call4=&originalFrame.sp10;
            if(workWord2)goto commit19;
            call5=(void*)numeric6;
            numeric6=2048;
            limit19:Physics23Call4F08CView3(call4,call5,numeric6);
            commit19:workWord2=originalFrame.sp10;
            workWord3=originalFrame.sp14;
            Physics23Field(&Physics23Player0View3,int*,0x8C)=workWord2;
            Physics23Field(&Physics23Player0View3,int*,0x90)=workWord3;
            return;
        }
    default:
        return;
    case 28:{
            int lowProduct3Case28,lowProduct4Case28;
            Physics23Call40D10View1(0xC80);
            Physics23Call41580View1(0x28, 8);
            Physics23Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics23Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics23Call4EA2CView1(Physics23Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics23Field(&Physics23Player0View1,int*,0xB0);
            lowProduct3Case28=workWord3*workWord2;
            call4=(void*)Physics23Field(globalFieldA4Pointer,int*,0);
            workWord2=lowProduct3Case28>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp20=workWord2;
            workWord2=Physics23Call4E9E4View1(call4);
            workWord3=Physics23Field(&Physics23Player0View1,int*,0xB0);
            lowProduct4Case28=workWord3*workWord2;
            workWord2=lowProduct4Case28>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp24=workWord2;
            Physics23Call4F1C8View1(&originalFrame.sp20, &originalFrame.sp20, globalVector8C);
            originalFrame.sp28 = 0;
            temp_v0_4 = Physics23Call4EDE8View1(&originalFrame.sp20, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics23Call4F08CView1(&originalFrame.sp20, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics23Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp20);
            Physics23Call41B64View1();
            if (combinedIndex < 0xD) {
                __asm__("" :: "r"(combinedIndex));
                nextField94 = Physics23Field(&Physics23Player0View1, int *, 0x94) + 0x17;
            }
            else {
                nextField94 = Physics23Field(&Physics23Player0View1, int *, 0x94) - 0xC0;
            }
            Physics23Player94View1=nextField94;
            __asm__ volatile("" ::: "memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer=&Physics23Player0View1+0x148;
                __asm__("" : "=r"(globalPointer):"0"(globalPointer));
                particleIndex=0;
                if (Physics23Field(globalPointer,int*,0) != 0) {
                    workWord2=combinedIndex*4;
                    __asm__("" : "=r"(workWord2):"0"(workWord2));
                    particleThreshold=workWord2+combinedIndex;
                    globalByteE=globalPointer-0x13A;
                    vectorAt40=&originalFrame.sp40;
                    __asm__("" : "=r"(vectorAt40):"0"(vectorAt40));
                spawnParticleLoop:
                    if (particleThreshold < (Physics23CallRandView1() & 0xFF)) {
                        workWord2=Physics23Call363DCView1(0,0xC);
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
                        signedTableWord = *(short*)(&Physics23Data65920View1 + workWord3);
                        call6=vectorAt40;
                        originalFrame.sp30 = (int) (signedTableWord * 5) >> 0xA;
                        workWord3=*(short*)(&Physics23Data658A0View1 + workWord3);
                        __asm__ volatile("" : "=r"(workWord3):"0"(workWord3):"memory");
                        originalFrame.sp38 = 0xE;
                        originalFrame.sp40 = -0x12C;
                        originalFrame.sp44 = 0;
                        originalFrame.sp48 = -0xC8;
                        __asm__ volatile("" ::: "memory");
                        originalFrame.sp34 = (workWord3 * 5) >> 0xA;
                        Physics23Call4ED6CView1(call4, call5, call6, signedTableWord);
                        originalFrame.sp40 += Physics23Call363DCView1(0, 0x50);
                        originalFrame.sp44 += Physics23Call363DCView1(0, 0x50);
                        originalFrame.sp48 += Physics23Call363DCView1(0, 0x50);
                        Physics23Call4F194View1(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 = Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp30);
                        workWord2=(int)temp_v0_5;
                        workWord3=8;
                        Physics23Field((void*)workWord2,signed char*,2)=workWord3;
                        workWord3=32;
                        Physics23Field((void*)workWord2,signed char*,10)=workWord3;
                    }
                    particleIndex += 1;
                    if (particleIndex < 2) {
                        goto spawnParticleLoop;
                    }
                }
            }
            break;
        }
    case 43:case 44:
        globalField4CPointer=&Physics23Player4CView1;
        __asm__("":"=r"(globalField4CPointer):"0"(globalField4CPointer));
        workWord3=Physics23Field(globalField4CPointer,int*,0);
        workWord2=1;
        if(workWord3!=workWord2)goto continue43;
        block_154:Physics23Call4F168View3(globalField4CPointer+52);
        Physics23Call4F168View3(globalField4CPointer+64);
        return;
        continue43:workWord2=7;
        workWord3=Physics23Data6E044View3;
        if (workWord3 == workWord2) {
            Physics23Field(&Physics23Player0View4, int *, 0xB0) = 0;
        }
        else {
            Physics23Call40D10View3(0x980);
            raw21_var_v0_2 = Physics23Call41580View3(0x5A, 0x10);
            if (raw21_var_v0_2 < 0) {
                raw21_var_v0_2 = -raw21_var_v0_2;
            }
            if (raw21_var_v0_2 >= 0x201) {
                Physics23Field(&Physics23Player0View4, int *, 0xAC) = 0;
            }
            raw21_var_a0_2 = 0xC0;
            if (Physics23Field(&Physics23Player0View4, int *, 0xB0) >= 0xC81) {
                raw21_var_a0_2 = 0;
                raw21_var_a1_4 = 0xC0;
            }
            else {
                raw21_var_a1_4 = 0x40;
            }
            Physics23Call417FCView3(raw21_var_a0_2, raw21_var_a1_4);
        }
        raw21_temp_s0_11 = &Physics23Player0View4 + 0xB0;
        if (Physics23Field(&Physics23Player0View4, int *, 0xB0) != 0) {
            Physics23Call41848View2();
            Physics23Call41B64View3();
            Physics23Field(&Physics23Player0View4, int *, 0x94) = 0;
        }
        else {
            Physics23Call4F168View3(raw21_temp_s0_11 - 0x30);
            Physics23Call4F168View3(raw21_temp_s0_11 - 0x24);
        }
        if (Physics21_SpawnParticle != 0) {
            raw21_temp_s4 = &Physics23Player0View4 + 0x28;
            if (Physics23Field(&Physics23Player0View4, int *, 0x28) < 0) {
                if ((Physics23Field(&Physics23Player0View4, int *, 0xB0) >= 0x401) && (savedSlotIndex < 2) && (Physics23Data6C640View1 & 1)) {
                    Physics23Call4F178View3(&originalFrame.sp30, raw21_temp_s4 - 0x28);
                    originalFrame.sp54 = 0x40;
                    originalFrame.sp58 = 0;
                    originalFrame.sp50 = (int) Physics23Field(&Physics23Player0View4, int *, 0xB0) >> 5;
                    if (savedSlotIndex != 0) {
                        originalFrame.sp54 = -0x40;
                    }
                    raw21_temp_s2_3 = raw21_temp_s4 + 8;
                    Physics23Call4ED6CView3(raw21_temp_s2_3, &originalFrame.sp50, &originalFrame.sp60);
                    Physics23Call4F194View4(&originalFrame.sp30, &originalFrame.sp30, &originalFrame.sp60);
                    originalFrame.sp50 = 0;
                    originalFrame.sp38 = -Physics23Field(&Physics23Player0View4, int *, 0x28);
                    Physics23Call4ED6CView3(raw21_temp_s2_3, &originalFrame.sp50, &originalFrame.sp50);
                    Physics23Call4F110View1(&originalFrame.sp50, 3);
                    Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp30, &originalFrame.sp50);
                    if (!(Physics23CallRandView2() & 0x1F)) {
                        Physics21_SpawnParticle(1, 0x29, &originalFrame.sp30, 0);
                    }
                }
                else {
                    raw21_temp_s1_7 = &Physics23Player0View4 + 0xB0;
                    if ((Physics23Field(&Physics23Player0View4, int *, 0xB0) < 0x201) && (savedSlotIndex == 0) && !(Physics23Data6C640View1 & 7) && !(Physics23CallRandView2() & 3)) {
                        originalFrame.sp70 = 0x80;
                        __asm__("":"=r"(savedSlotIndex):"0"(savedSlotIndex));
                        originalFrame.sp74 = 0;
                        originalFrame.sp78 = 0;
                        Physics23Call4ED6CView3(raw21_temp_s1_7 - 0x80, &originalFrame.sp70, &originalFrame.sp70);
                        Physics23Call4F194View4(&originalFrame.sp70, &originalFrame.sp70, raw21_temp_s1_7 - 0xB0);
                        originalFrame.sp78 = -Physics23Field(&Physics23Player0View4, int *, 0x28);
                        Physics21_SpawnParticle(1, 0x2B, &originalFrame.sp70, (int *)1);
                    }
                }
            }
        }
        raw21_temp_a1_4 = Physics23Field(&Physics23Player0View4, int *, 0x144) - ((int) ((Physics23Field(&Physics23Player0View4, int *, 0x148) * 2) + (Physics23Field(&Physics23Player0View4, int *, 0x144) * 0x14)) >> 8);
        raw21_temp_a0_7 = Physics23Field(&Physics23Player0View4, int *, 0x148) + raw21_temp_a1_4;
        Physics23Field(&Physics23Player0View4, int *, 0x144) = raw21_temp_a1_4;
        Physics23Field(&Physics23Player0View4, int *, 0x148) = raw21_temp_a0_7;
        if (raw21_temp_a0_7 >= 0x5901) {
            Physics23Field(&Physics23Player0View4, int *, 0x148) = 0x5900;
        }
        if (Physics23Field(&Physics23Player0View4, int *, 0x148) < -0x5900) {
            Physics23Field(&Physics23Player0View4, int *, 0x148) = -0x5900;
            return;
        }
        break;
    case 47:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            workWord3=Physics23Data6E044View2;
            workWord2=7;
            if(workWord3==workWord2)goto zero47;
            Physics23Call40F48View1(&originalFrame.sp60,0);
            workWord2=originalFrame.sp60;
            numeric6=originalFrame.sp64;
            originalFrame.sp80=0;
            workWord3=(workWord2*9<<7)>>7;
            workWord2=(numeric6*3<<9)>>7;
            originalFrame.sp60=workWord3;
            workWord3=-workWord3;
            originalFrame.sp64=workWord2;
            originalFrame.sp84=workWord3;
            originalFrame.sp88=workWord2;
            workWord2=Physics23Call4EDE8View3(&originalFrame.sp80,0,numeric6);
            numeric4=originalFrame.sp88;
            workWord3=numeric4;
            if(numeric4<0){
                __asm__("":"=r"(workWord3):"0"(workWord3));
                workWord3=-workWord3;
            }
            workWord3=workWord3<workWord2;
            if(workWord3){
                workWord2=originalFrame.sp84;
                originalFrame.sp88=0;
                __asm__ volatile("":::"$4");
                numeric4=0;
                if(workWord2>0){
                    __asm__ volatile(""::"i"(0x80091F60):"memory");
                    numeric4=1;
                }
                if(!Physics23Call43194View1(numeric4)){
                    originalFrame.sp84=0;
                }
            }
            else{
                __asm__ volatile("":::"$3");
                originalFrame.sp84=0;
                originalFrame.sp80=0;
                if(numeric4>0){
                    __asm__ volatile(""::"i"(0x80091F88):"memory");
                    numeric4=2;
                }
                else numeric4=3;
                if(!Physics23Call43194View1(numeric4)){
                    originalFrame.sp88=0;
                }
            }
            call4=&originalFrame.sp80;
            workWord2=Physics23Call4EDE8View3(call4,1);
            Physics23PlayerACView1=workWord2;
            __asm__ volatile(""::"i"(0x80091FB8):"memory");
            goto clear30;
            zero47:Physics23PlayerACView1=0;
            goto clear30;
        }
    case 30:clear30:globalVector80 = &Physics23Player0View3 + 0x80;
        Physics23Call4F168View2(globalVector80);
        Physics23Call4F168View2(globalVector80 + 0xC);
        return;
    case 50:case 51:case 52:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            Physics23Call40F48View1(&originalFrame.sp90,0);
            workWord2=originalFrame.sp90;
            numeric6=originalFrame.sp94;
            originalFrame.sp98=0;
            workWord3=(workWord2*9<<7)>>7;
            workWord2=(numeric6*3<<9)>>7;
            originalFrame.sp90=workWord3;
            workWord3=-workWord3;
            originalFrame.sp94=workWord2;
            originalFrame.sp9C=workWord3;
            originalFrame.spA0=workWord2;
            workWord2=Physics23Call4EDE8View3(&originalFrame.sp98,0,numeric6);
            numeric4=originalFrame.spA0;
            workWord3=numeric4;
            if(numeric4<0){
                __asm__("":"=r"(workWord3):"0"(workWord3));
                workWord3=-workWord3;
            }
            workWord3=workWord3<workWord2;
            if(workWord3){
                workWord2=originalFrame.sp9C;
                originalFrame.spA0=0;
                __asm__ volatile("":::"$4");
                numeric4=0;
                if(workWord2>0){
                    __asm__ volatile(""::"i"(0x80092070):"memory");
                    numeric4=1;
                }
                if(!Physics23Call43194View1(numeric4)){
                    originalFrame.sp9C=0;
                }
            }
            else{
                __asm__ volatile("":::"$3");
                originalFrame.sp9C=0;
                originalFrame.sp98=0;
                if(numeric4>0){
                    __asm__ volatile(""::"i"(0x80092098):"memory");
                    numeric4=2;
                }
                else numeric4=3;
                if(!Physics23Call43194View1(numeric4)){
                    originalFrame.spA0=0;
                }
            }
            vectorAt30=&originalFrame.sp98;
            workWord2=Physics23Call4EDE8View3(vectorAt30,1);
            numeric6=1;
            __asm__("":"=r"(numeric6):"0"(numeric6));
            numeric4=originalFrame.sp90;
            numeric5=originalFrame.sp94;
            globalVector80=&Physics23PlayerACView1;
            Physics23Field(globalVector80,int*,0)=workWord2;
            workWord2=Physics23Call4E880View1(numeric4,numeric5,numeric6);
            workWord3=workWord2;
            workWord2=workWord3<2049;
            Physics23PlayerA4View1=workWord3;
            call4=globalVector80-124;
            if(!workWord2){
                workWord2=workWord3-4096;
                Physics23PlayerA4View1=workWord2;
            }
            call5=vectorAt30;
            workWord2=originalFrame.sp98;
            call6=vectorAt30;
            workWord2+=1024;
            originalFrame.sp98=workWord2;
            Physics23Call4ED6CView2(call4,call5,call6);
            call4=vectorAt30;
            call5=vectorAt30;
            __asm__("":"=r"(globalVector80):"0"(globalVector80),"r"(call4),"r"(call5));
            globalVector8CState20=globalVector80-32;
            Physics23Call4F1C8View3(call4,call5,globalVector8CState20);
            call5=(void*)Physics23Call4EDE8View3(vectorAt30,0);
            workWord2=(int)call5<385;
            if(!workWord2)Physics23Call4F08CView3(vectorAt30,call5,384);
            globalVector80-=44;
            Physics23Call4F194View3(globalVector80,globalVector8CState20,vectorAt30);
            Physics23Call4F178View2(globalVector8CState20,globalVector80);
            return;
        }
    case 65:globalVector80=&Physics23Player0View2+0x80;
        Physics23Call4F168View1(globalVector80);
        Physics23Call4F168View1(globalVector80+12);
        if(Physics23Data6E044View1!=7){
            Physics23Call40D10View2(6016);
            Physics23Call416F4View1();
            Physics23Call41580View2(90,16);
        }
        workWord2=Physics23Player1BAView1;
        if(!workWord2)goto byteOne65;
        workWord2=Physics23Data6E538View1&16;
        if(workWord2)return;
        workWord2=1;
        Physics23Player1BAView1=0;
        Physics23Player1B9View1=workWord2;
        return;
        byteOne65:workWord2=1;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        Physics23Player1B9View1=workWord2;
        return;
    case 66:case 69:workWord3=Physics23Data6E044View1;
        workWord2=8;
        if(workWord3!=workWord2)Physics23Call40D10View2(6016);
        globalVector80=&Physics23Data6E538View1;
        workWord2=Physics23Field(globalVector80,int*,0)&12;
        if(workWord2)Physics23PlayerACView1=0;
        workWord2=Physics23Call416F4View1();
        call4=(void*)90;
        call5=(void*)16;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalFieldA4Pointer=(void*)workWord2;
        workWord2=Physics23Call41580View2(call4,call5);
        workWord3=Physics23PlayerA8View1;
        if(workWord3<0)workWord3=-workWord3;
        workWord3=workWord3<8;
        __asm__("":"=r"(workWord3):"0"(workWord3),"r"(workWord2));
        call5=(void*)workWord2;
        if(!workWord3)goto reset101;
        workWord2=Physics23Field(globalVector80,int*,0)&12;
        if(!workWord2)goto reset101;
        workWord2=Physics23Player144View1;
        workWord2++;
        Physics23Player144View1=workWord2;
        goto saved101;
        reset101:Physics23Player144View1=0;
        saved101:call4=&Physics23PlayerACView1;
        globalVector80=(void*)Physics23Field(call4,int*,0);
        if(globalFieldA4Pointer)goto collision101;
        workWord2=(int)call5;
        if((int)call5<0)workWord2=-workWord2;
        workWord2=workWord2<513;
        if(workWord2)goto pass101;
        collision101:workWord2=Physics23Player20CView1&64;
        if(workWord2)Physics23Field(call4,int*,0)=0;
        else{
            workWord3=Physics23PlayerB0View1;
            workWord2=workWord3<(int)globalVector80;
            if(workWord2)Physics23Field(call4,int*,0)=workWord3;
        }
        pass101:Physics23Call417FCView2(320,192);
        workWord2=Physics23Player101View1;
        call4=&Physics23PlayerACView1;
        Physics23Field(call4,int*,0)=(int)globalVector80;
        if(workWord2){
            Physics23Call4F168View1(call4-32);
            goto fields101;
        }
        Physics23Call41848View1(call4);
        Physics23Call41B64View2();
        fields101:call6=&Physics23PlayerFCView1;
        workWord2=Physics23Field(call6,unsigned char*,0);
        if(workWord2)goto block_303;
        workWord2=Physics23PlayerB8View1;
        call4=call6-112;
        if(workWord2)goto block_303;
        commit101:goto vectorInput71;
    case 67:{
            int lowProduct3Case67,lowProduct4Case67;
            Physics23Call40D10View1(0xC80);
            Physics23Call41580View1(0x28, 8);
            Physics23Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics23Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics23Call4EA2CView1(Physics23Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics23Field(&Physics23Player0View1,int*,0xB0);
            lowProduct3Case67=workWord3*workWord2;
            call4=(void*)Physics23Field(globalFieldA4Pointer,int*,0);
            workWord2=lowProduct3Case67>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spA8=workWord2;
            workWord2=Physics23Call4E9E4View1(call4);
            workWord3=Physics23Field(&Physics23Player0View1,int*,0xB0);
            lowProduct4Case67=workWord3*workWord2;
            workWord2=lowProduct4Case67>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spAC=workWord2;
            Physics23Call4F1C8View1(&originalFrame.spA8, &originalFrame.spA8, globalVector8C);
            originalFrame.spB0 = 0;
            temp_v0_4 = Physics23Call4EDE8View1(&originalFrame.spA8, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics23Call4F08CView1(&originalFrame.spA8, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics23Call4F194View1(var_a0_3, globalVector8C, &originalFrame.spA8);
            Physics23Call41B64View1();
            workWord2=combinedIndex<13;
            if(!workWord2)goto subtract320_73;
            workWord2=Physics23Player4CView1;
            if(workWord2)goto subtract320_73;
            workWord2=(int)Physics23Data6C570View1;
            workWord2=Physics23Field((void*)workWord2,int*,0)&64;
            if(workWord2)goto add30_70;
            workWord2=Physics23Player144View1;
            if(workWord2)goto add30_70;
            goto subtract320_73;
        }
    case 68:{
            register void *child19 __asm__("$19");
            register int numeric5 __asm__("$5");
            int lowProduct3Case68,lowProduct4Case68;
            globalFieldA4Pointer=&Physics23Player4CView1;
            workWord2=2;
            globalPointer=(void*)Physics23Player250View1;
            call4=(void*)Physics23Field(globalFieldA4Pointer,int*,0);
            child19=Physics23Field(globalPointer,void**,0);
            numeric5=1600;
            if((int)call4==workWord2)numeric5=3200;
            Physics23Call40D10View1(numeric5,numeric5);
            Physics23Call41580View1(22,4);
            Physics23Call417FCView1(320,192);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            globalVector8C=globalFieldA4Pointer+64;
            workWord2=Physics23Call4EA2CView1(Physics23Field(globalFieldA4Pointer,int*,88));
            workWord3=Physics23PlayerB0View1;
            lowProduct3Case68=workWord3*workWord2;
            call4=(void*)Physics23Field(globalFieldA4Pointer,int*,88);
            workWord2=lowProduct3Case68>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spB8=workWord2;
            workWord2=Physics23Call4E9E4View1(call4);
            workWord3=Physics23PlayerB0View1;
            lowProduct4Case68=workWord3*workWord2;
            workWord2=lowProduct4Case68>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spBC=workWord2;
            Physics23Call4F1C8View1(&originalFrame.spB8, &originalFrame.spB8, globalVector8C);
            originalFrame.spC0 = 0;
            temp_v0_4 = Physics23Call4EDE8View1(&originalFrame.spB8, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer+52;
            if (temp_v0_4 >= 0x141) {
                Physics23Call4F08CView1(&originalFrame.spB8, temp_v0_4, 0x140);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer+52;
            }
            Physics23Call4F194View1(var_a0_3, globalVector8C, &originalFrame.spB8);
            Physics23Call41B64View1();
            workWord2=Physics23Player94View2;
            workWord2-=320;
            Physics23Player94View2=workWord2;
            workWord2=workWord2<-12800;
            if(workWord2){
                workWord2=-12800;
                Physics23Field(globalFieldA4Pointer,int*,72)=workWord2;
            }
            workWord2=Physics23Field(globalFieldA4Pointer,unsigned char*,362);
            if(!workWord2)return;
            workWord2=Physics23Field(child19,int*,72);
            workWord2++;
            Physics23Field(child19,int*,72)=workWord2;
            return;
        }
    case 70:{
            int lowProduct3Case70,lowProduct4Case70;
            Physics23Call40D10View1(0xC80);
            Physics23Call41580View1(0x28, 8);
            Physics23Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics23Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics23Call4EA2CView1(Physics23Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics23Field(&Physics23Player0View1,int*,0xB0);
            lowProduct3Case70=workWord3*workWord2;
            call4=(void*)Physics23Field(globalFieldA4Pointer,int*,0);
            workWord2=lowProduct3Case70>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spC8=workWord2;
            workWord2=Physics23Call4E9E4View1(call4);
            workWord3=Physics23Field(&Physics23Player0View1,int*,0xB0);
            lowProduct4Case70=workWord3*workWord2;
            workWord2=lowProduct4Case70>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spCC=workWord2;
            Physics23Call4F1C8View1(&originalFrame.spC8, &originalFrame.spC8, globalVector8C);
            originalFrame.spD0 = 0;
            temp_v0_4 = Physics23Call4EDE8View1(&originalFrame.spC8, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics23Call4F08CView1(&originalFrame.spC8, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics23Call4F194View1(var_a0_3, globalVector8C, &originalFrame.spC8);
            Physics23Call41B64View1();
            workWord2=combinedIndex<7;
            if(!workWord2)goto subtract320_73;
            workWord3=Physics23Player4CView1;
            workWord2=1;
            if(workWord3==workWord2)goto subtract320_73;
            add30_70:workWord2=Physics23Player94View2;
            workWord2+=30;
            Physics23Player94View2=workWord2;
            return;
        }
    case 71:{
            register int numeric5 __asm__("$5");
            int lowProduct3Case71,lowProduct4Case71;
            globalFieldA4Pointer=&Physics23PlayerB8View1;
            workWord2=Physics23Field(globalFieldA4Pointer,int*,0);
            if(!workWord2)goto grounded71;
            workWord2=2;
            workWord3=Physics23Player4CView1;
            numeric5=1600;
            if(workWord3==workWord2)numeric5=3200;
            Physics23Call40D10View1(numeric5,numeric5);
            Physics23Call41580View1(22,4);
            Physics23Call417FCView1(320,192);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            globalVector8C=globalFieldA4Pointer-44;
            workWord2=Physics23Call4EA2CView1(Physics23PlayerA4View1);
            __asm__ volatile(""::"r"(globalVector8C):"memory");
            workWord3=Physics23PlayerB0View1;
            lowProduct3Case71=workWord3*workWord2;
            call4=(void*)Physics23PlayerA4View1;
            workWord2=lowProduct3Case71>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spD8=workWord2;
            workWord2=Physics23Call4E9E4View1(call4);
            workWord3=Physics23PlayerB0View1;
            lowProduct4Case71=workWord3*workWord2;
            workWord2=lowProduct4Case71>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spDC=workWord2;
            Physics23Call4F1C8View1(&originalFrame.spD8, &originalFrame.spD8, globalVector8C);
            originalFrame.spE0 = 0;
            temp_v0_4 = Physics23Call4EDE8View1(&originalFrame.spD8, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer-56;
            if (temp_v0_4 >= 0x141) {
                Physics23Call4F08CView1(&originalFrame.spD8, temp_v0_4, 0x140);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer-56;
            }
            Physics23Call4F194View1(var_a0_3, globalVector8C, &originalFrame.spD8);
            Physics23Call41B64View1();
            workWord2=Physics23Player94View2;
            workWord2-=320;
            Physics23Player94View2=workWord2;
            workWord2=workWord2<-12800;
            if(workWord2){
                workWord2=-12800;
                Physics23Player94View2=workWord2;
            }
            return;
        grounded71:
            workWord3=Physics23Data6E044View1;
            workWord2=8;
            if(workWord3!=workWord2)Physics23Call40D10View2(6016);
            globalVector80=&Physics23Data6E538View1;
            workWord2=Physics23Field(globalVector80,int*,0)&12;
            if(workWord2)Physics23PlayerACView1=0;
            workWord2=Physics23Call416F4View1();
            call4=(void*)90;
            call5=(void*)16;
            __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
            globalFieldA4Pointer=(void*)workWord2;
            workWord2=Physics23Call41580View2(call4,call5);
            workWord3=Physics23PlayerA8View1;
            if(workWord3<0)workWord3=-workWord3;
            workWord3=workWord3<8;
            __asm__("":"=r"(workWord3):"0"(workWord3),"r"(workWord2));
            call5=(void*)workWord2;
            if(!workWord3)goto reset71;
            workWord2=Physics23Field(globalVector80,int*,0)&12;
            if(!workWord2)goto reset71;
            workWord2=Physics23Player144View1;
            workWord2++;
            Physics23Player144View1=workWord2;
            goto saved71;
            reset71:Physics23Player144View1=0;
            saved71:call4=&Physics23PlayerACView1;
            globalVector80=(void*)Physics23Field(call4,int*,0);
            if(globalFieldA4Pointer)goto collision71;
            workWord2=(int)call5;
            if((int)call5<0)workWord2=-workWord2;
            workWord2=workWord2<513;
            if(workWord2)goto pass71;
            collision71:workWord2=Physics23Player20CView1&64;
            if(workWord2)Physics23Field(call4,int*,0)=0;
            else{
                workWord3=Physics23PlayerB0View1;
                workWord2=workWord3<(int)globalVector80;
                if(workWord2)Physics23Field(call4,int*,0)=workWord3;
            }
            pass71:Physics23Call417FCView2(320,192);
            workWord2=Physics23Player101View1;
            call4=&Physics23PlayerACView1;
            Physics23Field(call4,int*,0)=(int)globalVector80;
            if(workWord2){
                Physics23Call4F168View1(call4-32);
                goto fields71;
            }
            Physics23Call41848View1(call4);
            Physics23Call41B64View2();
            fields71:call6=&Physics23PlayerFCView1;
            workWord2=Physics23Field(call6,unsigned char*,0);
            if(workWord2)goto block_303;
            workWord2=Physics23PlayerB8View1;
            call4=call6-112;
            if(!workWord2)goto vectorInput71;
            block_303:workWord2=Physics23PlayerA0View1;
            workWord2-=320;
            Physics23Player94View2=workWord2;
            return;
            vectorInput71:__asm__ volatile(""::"i"(0x800929FC):"memory");
            call5=call4;
            vectorCommit49:Physics23Call4F194View5(call4,call5,call6-20);
            return;
        }
    case 72:{
            int lowProduct3Case72,lowProduct4Case72;
            globalFieldA4Pointer=&Physics23Player4CView1;
            workWord2=Physics23Field(globalFieldA4Pointer,int*,0);
            if(workWord2)goto vector72;
            workWord2=combinedIndex<19;
            call4=globalFieldA4Pointer+64;
            if(workWord2)goto neutralVector72;
            call4=globalFieldA4Pointer+52;
            workWord3=Physics23Player8CView1;
            workWord2=workWord3*7;
            workWord3=Physics23Player90View1;
            workWord2<<=5;
            Physics23Field(globalFieldA4Pointer,int*,52)=workWord2;
            workWord2=workWord3*7;
            workWord3=Physics23Player94View2;
            workWord2<<=5;
            Physics23Player84View1=workWord2;
            workWord2=workWord3*7;
            workWord2<<=5;
            Physics23Player88View1=workWord2;
            Physics23Call4F110View2(call4,8);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            call4=globalFieldA4Pointer+64;
            neutralVector72:Physics23Call4F178View4(call4,globalFieldA4Pointer+52);
            workWord2=Physics23Player94View2;
            workWord2-=192;
            Physics23Player94View2=workWord2;
            workWord2=workWord2<-8960;
            clamp19:if(workWord2){
                workWord2=-8960;
                Physics23Player94View2=workWord2;
            }
            return;
            vector72:Physics23Call40D10View1(3200);
            Physics23Call41580View1(40,8);
            Physics23Call417FCView1(320,192);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            globalVector8C=globalFieldA4Pointer+64;
            workWord2=Physics23Call4EA2CView1(Physics23PlayerA4View1);
            __asm__ volatile(""::"r"(globalVector8C):"memory");
            workWord3=Physics23PlayerB0View1;
            lowProduct3Case72=workWord3*workWord2;
            call4=(void*)Physics23PlayerA4View1;
            workWord2=lowProduct3Case72>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spE8=workWord2;
            workWord2=Physics23Call4E9E4View1(call4);
            workWord3=Physics23PlayerB0View1;
            lowProduct4Case72=workWord3*workWord2;
            workWord2=lowProduct4Case72>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spEC=workWord2;
            Physics23Call4F1C8View1(&originalFrame.spE8, &originalFrame.spE8, globalVector8C);
            originalFrame.spF0 = 0;
            temp_v0_4 = Physics23Call4EDE8View1(&originalFrame.spE8, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer+52;
            if (temp_v0_4 >= 0x281) {
                Physics23Call4F08CView1(&originalFrame.spE8, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer+52;
            }
            Physics23Call4F194View1(var_a0_3, globalVector8C, &originalFrame.spE8);
            Physics23Call41B64View1();
            if(combinedIndex<13){
                __asm__(""::"r"(combinedIndex));
                workWord2=Physics23Player94View2;
                workWord2+=30;
            }
            else{
                workWord2=Physics23Player94View2;
                workWord2-=320;
            }
            Physics23Player94View2=workWord2;
            __asm__ volatile("" ::: "memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer=&Physics23Player0View1+0x148;
                __asm__("" : "=r"(globalPointer):"0"(globalPointer));
                particleIndex=0;
                if (Physics23Field(globalPointer,int*,0) != 0) {
                    workWord2=combinedIndex*4;
                    __asm__("" : "=r"(workWord2):"0"(workWord2));
                    particleThreshold=workWord2+combinedIndex;
                    globalByteE=globalPointer-0x13A;
                    vectorAt40=&originalFrame.sp108;
                    __asm__("" : "=r"(vectorAt40):"0"(vectorAt40));
                spawnParticleLoop72:
                    if (particleThreshold < (Physics23CallRandView1() & 0xFF)) {
                        workWord2=Physics23Call363DCView1(0,0xC);
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
                        signedTableWord = *(short*)(&Physics23Data65920View1 + workWord3);
                        call6=vectorAt40;
                        originalFrame.spF8 = (int) (signedTableWord * 5) >> 0xA;
                        workWord3=*(short*)(&Physics23Data658A0View1 + workWord3);
                        __asm__ volatile("" : "=r"(workWord3):"0"(workWord3):"memory");
                        originalFrame.sp100 = 0xE;
                        originalFrame.sp108 = -0x12C;
                        originalFrame.sp10C = 0;
                        originalFrame.sp110 = -0xC8;
                        __asm__ volatile("" ::: "memory");
                        originalFrame.spFC = (workWord3 * 5) >> 0xA;
                        Physics23Call4ED6CView1(call4, call5, call6, signedTableWord);
                        originalFrame.sp108 += Physics23Call363DCView1(0, 0x50);
                        originalFrame.sp10C += Physics23Call363DCView1(0, 0x50);
                        originalFrame.sp110 += Physics23Call363DCView1(0, 0x50);
                        Physics23Call4F194View1(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 = Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.spF8);
                        workWord2=(int)temp_v0_5;
                        workWord3=8;
                        Physics23Field((void*)workWord2,signed char*,2)=workWord3;
                        workWord3=32;
                        Physics23Field((void*)workWord2,signed char*,10)=workWord3;
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
            Physics23Call40D10View1(0x640);
            Physics23Call41580View1(0x28, 8);
            Physics23Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics23Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics23Call4EA2CView1(Physics23Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics23Field(&Physics23Player0View1,int*,0xB0);
            lowProduct3Case73=workWord3*workWord2;
            call4=(void*)Physics23Field(globalFieldA4Pointer,int*,0);
            workWord2=lowProduct3Case73>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spF8=workWord2;
            workWord2=Physics23Call4E9E4View1(call4);
            workWord3=Physics23Field(&Physics23Player0View1,int*,0xB0);
            lowProduct4Case73=workWord3*workWord2;
            workWord2=lowProduct4Case73>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.spFC=workWord2;
            Physics23Call4F1C8View1(&originalFrame.spF8, &originalFrame.spF8, globalVector8C);
            originalFrame.sp100 = 0;
            temp_v0_4 = Physics23Call4EDE8View1(&originalFrame.spF8, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics23Call4F08CView1(&originalFrame.spF8, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics23Call4F194View1(var_a0_3, globalVector8C, &originalFrame.spF8);
            Physics23Call41B64View1();
            workWord2=combinedIndex<19;
            if(!workWord2)goto subtract320_73;
            workWord3=Physics23Player4CView1;
            workWord2=1;
            if(workWord3==workWord2)goto subtract320_73;
            workWord2=Physics23Player94View2;
            workWord2+=100;
            Physics23Player94View2=workWord2;
            return;
            subtract320_73:globalPointer=&Physics23Player94View2;
            workWord2=Physics23Field(globalPointer,int*,0);
            workWord2-=320;
            Physics23Field(globalPointer,int*,0)=workWord2;
            return;
        }
    case 74:globalVector80=&Physics23Player0View2+0xB8;
        workWord2=Physics23Field(globalVector80,int*,0);
        if(!workWord2)goto zero105;
        vectorAt30=&originalFrame.sp118;
        Physics23Call4F168View1(vectorAt30);
        call4=vectorAt30;
        call5=vectorAt30;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalVector8CState20=globalVector80-44;
        Physics23Call4F1C8View2(call4,call5,globalVector8CState20);
        originalFrame.sp120=0;
        call5=(void*)Physics23Call4EDE8View2(vectorAt30,0);
        workWord2=(int)call5<65;
        if(!workWord2)Physics23Call4F08CView2(vectorAt30,call5,64);
        originalFrame.sp120=-320;
        globalVector80-=56;
        Physics23Call4F194View2(globalVector80,globalVector8CState20,vectorAt30);
        Physics23Call4F178View1(globalVector8CState20,globalVector80);
        goto clamp74;
        zero105:Physics23Call4F168View1(globalVector80-56);
        Physics23Call4F168View1(globalVector80-44);
        goto clamp74;
        clamp74:globalPointer=&Physics23Player94View2;
        workWord2=Physics23Field(globalPointer,int*,0);
        workWord2=workWord2<-12800;
        if(workWord2){
            workWord2=-12800;
            Physics23Field(globalPointer,int*,0)=workWord2;
        }
        return;
    case 75:case 76:case 77:{
            register int numeric5 __asm__("$5");
            int product75;
            call4=&Physics23Player8CView1;
            __asm__("":"=r"(call4):"0"(call4));
            workWord3=Physics23Field(call4,int*,-64);
            __asm__ volatile(""::"r"(workWord3):"memory");
            numeric5=1;
            __asm__("":"=r"(numeric5):"0"(numeric5));
            Physics23Field(call4,int*,0)=0;
            Physics23Field(call4,int*,4)=0;
            if(workWord3==numeric5)goto descend75;
            workWord2=workWord3<2;
            if(!workWord2)goto larger75;
            if(!workWord3)goto zero75;
            return;
            larger75:workWord2=2;
            if(workWord3==workWord2)goto zeroVelocity75;
            return;
        zero75:
            workWord2=Physics23Player144View1;
            workWord2++;
            Physics23Player144View1=workWord2;
            workWord2=workWord2<42;
            if(workWord2){
                workWord2=Physics23Player94View2;
                workWord2-=32;
                Physics23Player94View2=workWord2;
                return;
            }
            Physics23Field(call4,int*,-64)=numeric5;
            __asm__ volatile("":::"$2","memory");
            Physics23Player54View1=0;
            return;
            descend75:workWord2=Physics23Field(call4,int*,8);
            workWord2-=2048;
            Physics23Field(call4,int*,8)=workWord2;
            workWord2=workWord2<-12800;
            if(workWord2)Physics23Field(call4,int*,8)=-12800;
            workWord2=Physics23PlayerB8View1;
            if(workWord2)return;
            workWord2=Physics23Player54View1;
            workWord2=workWord2<9;
            if(workWord2)return;
            workWord2=Physics23PlayerE4View1;
            workWord2=workWord2<23;
            if(!workWord2)return;
            workWord3=Physics23PlayerD4View1;
            workWord2=Physics23Field(call4,int*,8);
            product75=workWord3*workWord2;
            if(product75>=0)return;
            workWord2=4096;
            particleCall3=Physics42_SpawnParticle;
            __asm__ volatile(""::"r"(particleCall3):"memory");
            Physics23Data6E1D4View1=workWord2;
            workWord2=30;
            Physics23Data6E1D8View1=workWord2;
            workWord2=2;
            Physics23Field(call4,int*,-64)=workWord2;
            Physics23Player54View1=0;
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
            globalPointer=Physics23Data6C654View1;
            __asm__ volatile(""::"r"(globalPointer):"memory");
            workWord2=120;
            Physics23Data6E530View1=workWord2;
            workWord2=15;
            Physics23Data6E52CView1=workWord2;
            call4=(void*)Physics23Field(globalPointer,unsigned char*,20);
            Physics23DataPlaySoundView1(call4,call5,0);
            return;
            zeroVelocity75:Physics23Player94View2=0;
            return;
        }
    }
}
#undef Physics23Field


/* AI generated; not human reviewed. SCUS-94467 80093120..800937D0.
 * Verified43 scalar/clamp and original23 case47 numeric pointer chain.
 * Original800935CC..8009373C supplies case47 register/call/access chain.
 * Player+44-14 and44-44 are byte offsets, not typed-element arithmetic.
 * Table8006D048+14, selector80071924&63, stride4 and entry+4 mask02000000
 * are numeric provenance. Original helper meaning and source producer remain open.
 * Separate absolute flagWord alias retains originalV3 producer at80093538;
 * empty lifetime/memory constraints emit no instructions. Units/cadence unresolved.
 * Acceptance requires every original code/table word, strict full TU/all hashes.
 */
extern int Callback23Step __asm__("D_80070328+0x144");
extern int Callback23Z __asm__("D_80070328+8");
extern int Callback23Limit __asm__("D_80070328+0x280");
extern Spyro Callback23Player __asm__("D_80070328");
int Callback23Call80037058(int x, int y) __asm__("func_80037058");
void Callback23Call80041930(void) __asm__("func_80041930");
void Callback23Call80041AE8(void) __asm__("func_80041AE8");
void Callback23Call80041C20(void) __asm__("func_80041C20");
void Callback23Call80042A44(void) __asm__("func_80042A44");
void Callback23Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback23Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38,D_8006C648;
int Callback23Query(Vector3D*,int) __asm__("func_8001A358");
int Callback23Length(Vector3D*, int) __asm__("func_8004EDE8");
extern int Callback23FlagWord __asm__("D_80070328+0x4C");
extern int D_80071924;
extern int** Callback23Table __asm__("D_8006D048+0x14");
int Callback23Call80055E84(Moby*) __asm__("func_80055E84");
void Callback23Call8004ED6C(void*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
void Callback23Call8001BA30(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int Callback23Call80019138(Vector3D*,int,int,int,int,Moby*) __asm__("func_80019138");
int Callback23Call8001830C(Vector3D*,Vector3D*,int,int,Moby*) __asm__("func_8001830C");
void func_level_23_80093120(void) {
    struct {Vector3D first; int reserved24; Vector3D second; int reserved34;} local;
    register int computedValue __asm__("$4");

    register int clampedValue __asm__("$4");
    register int positionDelta __asm__("$2");
    register int numerator __asm__("$2");
    register int belowLimit __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback23Player.animationState) {
    case 0x41:
        if(func_800438F4()==0)func_80043728();
        Callback23Call80041C20();
        Callback23Player.unk9a=0;
        Callback23Call80042A44();
        goto clearSharedValue;
    default:
        return;
    case 0x44:
    case 0x4A:
        Callback23Call80041C20();
        Callback23Call80042A44();
        goto clearSharedValue;
    case 0x42:
    case 0x45:
        func_800438F4();
        Callback23Call80041C20();
        Callback23Call80042A44();
        Callback23Call80041930();
        goto queryC00;
    case 0x13:
        Callback23Call80041C20();
        Callback23Call80042A44();
        goto call41930;
    case 0x1C:
        Callback23Call80041C20();
        Callback23Call80042A44();
        Callback23Call80041930();
        if(Callback23Player.unk7a[3].z < 0 && Callback23Player.animationStateFrames >= 4) {
setFirstFlag:
            Callback23Player.unk5=1;
        }
        goto clearSharedValue;
        case 0x1E: {
            register int* zWord __asm__("$5")=&Callback23Z;
            register int velocity __asm__("$6")=Callback23Step;
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
            status=Callback23Limit;
            velocity+=tick;
            Callback23Step=velocity;
            __asm__("" : : : "memory");
            if(status>=0 && D_8006FA38<0)goto lowerLimit;
            {
                register int limit __asm__("$3")=0x9000;
                register int exceeded __asm__("$2");
                __asm__("" : "=r"(limit) : "0"(limit));
                exceeded=limit<velocity;
                if(exceeded)Callback23Step=limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2")=velocity<0x2581;
                if(!below)Callback23Step=0x2580;
            }
        limitsDone:
            Callback23Call80041C20();
            Callback23Call80042A44();
            func_8004F178(&local.first,&Callback23Player.position);
            __asm__ volatile("" : : : "$16", "memory");
            local.first.z+=0x400;
            {register int queryResult __asm__("$2")=Callback23Query(&local.first,0xC00);
            __asm__("" : "=r"(queryResult) : "0"(queryResult));
            Callback23Player.unk4[0]=-queryResult;
            __asm__ volatile("" : : : "memory");}
            positionDelta=(int)Callback23Player.union144.a.unk13cb;
            positionValue=Callback23Player.position.z;
            positionDelta >>= 6;
            goto storePosition;
        }
    case 0x2B:
    case 0x2C:
        Callback23Call80041C20();
        Callback23Call80042A44();
        Callback23Call80041AE8();
        if ((unsigned char) Callback23Player.unk10[4] != 0) {
            computedValue = -Callback23Player.unk9ha[4] - Callback23Call80037058(Callback23Player.position.x, Callback23Player.position.y);
            positionValue = Callback23Player.unk4a - computedValue;
            Callback23Player.unk4[0] = computedValue;
            positionDelta = (int) Callback23Player.union144.a.unk13cc >> 6;
            goto storePosition;
        }
        break;
storePosition:
        positionValue -= positionDelta;
        __asm__("" : "=r"(positionValue) : "0"(positionValue));
        Callback23Player.position.z=positionValue;
        return;
    case 0x2F:
        Callback23Call80041C20();
        Callback23Call80042A44();
        Callback23Call80041930();
        func_80042F64();
        goto clearSharedValue;
    case 0x32:
        Callback23Call80041C20();
        Callback23Call80042A44();
        Callback23Call80041930();
        func_80042F64();
        numerator=(int)((unsigned int)Callback23Player.unk7a[3].z << 2);
        Callback23Player.unk4[0] = 0;
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
        Callback23Call80041C20();
        Callback23Call80042A44();
        Callback23Call80041930();
        func_80042F64();
        Callback23Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)(((unsigned int)Callback23Length((Vector3D *) ((unsigned char*)Callback23Player.unk4 + 0x70), 0) << 2) + 0x300U) / 1536;
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
    case 0x43:
    case 0x46:
    case 0x49:
        Callback23Call80041C20();
        Callback23Call80042A44();
        Callback23Call80041930();
        if(Callback23Player.unk7a[3].z < 0 && Callback23Player.animationStateFrames >= 4)goto setFirstFlag;
        {register int* flagWord __asm__("$3")=&Callback23FlagWord;
        __asm__("" : "=r"(flagWord) : "0"(flagWord));
        if(*flagWord==0 && !(Callback23Word8006E538 & 0x40) && Callback23Player.union144.a.unk13cb==0)
            *flagWord=2;}
        goto clearSharedValue;
    case 0x47: {
        register int progress __asm__("$4");
        register int value __asm__("$2");
        register int* sourceBase __asm__("$16");
        register Vector3D* vectorBase __asm__("$17");
        register int flags __asm__("$18");
        if(Callback23Player.ticksSinceLastSurfaceTouch) {
            Callback23Call80041C20();
            Callback23Call80042A44();
        } else {
            func_800438F4();
            Callback23Call80041C20();
            Callback23Call80042A44();
            Callback23Call80041930();
            Callback23Call80043A38(0xC00);
        }
        progress=Callback23Call80055E84(Callback23Player.critterMobyPtr);
        if(Callback23Player.critterMobyPtr->animationState.id==6 && (unsigned int)(progress-2)<6) {
            if(progress<6)value=(progress<<10)/6;
            else value=0x400;
            local.second.x=value;
            __asm__ volatile("" : : : "memory");
            sourceBase=&Callback23Player.unk4a;
            vectorBase=&local.second;
            local.second.y=0;
            local.second.z=0x200-*sourceBase;
            Callback23Call8004ED6C((unsigned char*)sourceBase-0x14,vectorBase,vectorBase);
            {register Vector3D* argument0 __asm__("$4")=vectorBase;
            register Vector3D* argument1 __asm__("$5")=vectorBase;
            __asm__("" : "=r"(argument0), "=r"(argument1) : "0"(argument0), "1"(argument1));
            sourceBase=(int*)((unsigned char*)sourceBase-0x44);
            func_8004F194(argument0,argument1,(Vector3D*)sourceBase);}
            flags=0x02000000;
            Callback23Call8001BA30(vectorBase,0x200,0,0,flags,Callback23Player.critterMobyPtr);
            if((Callback23Call80019138(vectorBase,0x200,0,0,flags,Callback23Player.critterMobyPtr)!=0 ||
                Callback23Call8001830C((Vector3D*)sourceBase,vectorBase,0,0x02000000,Callback23Player.critterMobyPtr)!=0)) {
                register int* selector __asm__("$16")=&D_80071924;
                if(func_80040954(*selector)==3) {
                    register int index __asm__("$2")=*selector;
                    register int** table __asm__("$3")=Callback23Table;
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
        Callback23Call80041C20();
        Callback23Call80042A44();
        if(Callback23Player.unk5==1)func_800494A8();
        goto clearSharedValue;
    case 0x48:
        Callback23Call80041C20();
        Callback23Call80042A44();
        if(Callback23Player.unk5!=0)goto call41930;
queryC00:
        Callback23Call80043A38(0xC00);
        goto clearSharedValue;
call41930:
        Callback23Call80041930();
clearSharedValue:
        Callback23Player.unk4[0]=0;
        return;
    }
}


#define LEVEL_ID 23
#define PlaySpyroSounds_level_23 func_level_23_800937D4
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_23_800939C0(int index) {
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
    case 0x1e:
    case 0x2b:
    case 0x2c:
    case 0x41:
    case 0x42:
    case 0x45:
    case 0x4a:
        func_80043ABC(&spyro.unk9e);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80093A68.
 * Verified16 character41..4D,32 swirl/drowning,37 vector/damage200, original23
 * grouped ladder and distinct stack10 surface / stack20 jump producers.
 * Numeric offsets are bytes. Signed table -2/0/2 maps to -1/0/1; original
 * word60 wrap800/801/FFF yields0/-7FF/-1. Each invocation preserves original
 * code/internal jumps/owned tables; strict complete TU and all hashes required.
 * Helper meanings, physical units, audio, cadence and live parity remain open.
 */
extern unsigned char Transition23RawUnion[] __asm__("D_80070328+0x144");
extern int Transition23RawMovement __asm__("D_80070328+0x50");
void Transition23_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");
void Transition23_func_8004F168(Vector3D*) __asm__("func_8004F168");
void Transition23_func_80043A38(int) __asm__("func_80043A38");
void Transition23_func_800441F0(void) __asm__("func_800441F0");
extern int Raw23Word __asm__("D_80070328+0x50");
extern int Raw23X __asm__("D_80070328+0x8C");
extern unsigned char Raw23Movement[] __asm__("D_80070328+0x50");
extern unsigned char Raw23Union[] __asm__("D_80070328+0x144");
extern int Raw23Animation __asm__("D_80070328+0x48");
extern short D_80065920[];
extern short D_800658A0[];
extern Spyro Transition23_D_80070328 __asm__("D_80070328");
int Transition23_func_8004EDE8(Vector3D*,int) __asm__("func_8004EDE8");
int Call23A358(Vector3D*,int) __asm__("func_8001A358");
extern int Transition23_D_8006E524 __asm__("D_8006E524");
extern int D_80071934;
void func_level_23_80093A68(int arg0) {
    struct {Vector3D first; int gap; Vector3D second;} vectors;
    register Vector3D *damageSource __asm__("$16");
    register Vector3D *damageDestination __asm__("$16");
    Vector3D *firstJumpSource;
    Vector3D *secondJumpSource;
    enum MovementState nextSubstate;
    int lengthResult;
    register int comparisonKind __asm__("$2");
    register int previousValue __asm__("$2");
    register int firstAnimation __asm__("$3");
    register int tableIndex __asm__("$2");
    register int tableValue __asm__("$3");
    register unsigned char* soundTable __asm__("$3");
    register unsigned char* unionBase __asm__("$5");
    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* movement __asm__("$3");
    register unsigned char* initialMovement __asm__("$5");
    register void *jumpPrivate __asm__("$18");
    register void *damagePrivate __asm__("$18");

    register Vector3D* jumpVector __asm__("$16");
    register unsigned char* stateBase __asm__("$17");
    register unsigned char* privateData __asm__("$16");
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");
    int maskedValue;
    switch (arg0) {
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        stateBase=(unsigned char*)&Transition23RawMovement;
        privateData = Transition23_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition23_D_80070328.unk5 = 0;
        Transition23_D_80070328.grounded = 0;
        Transition23_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition23_D_80070328.m_WhirlwindPointer;
        yawValue=Transition23_D_80070328.rotation.yaw;
        positionZ=Transition23_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition23_D_80070328.union144.a.unk13cc=yawValue;
        Transition23_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition23_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition23_D_80070328.union144.a.unk13ce.z=heightValue;
        __asm__ volatile("" : : : "memory");
        heightValue = ((int) (heightValue << 0xA) >> 0xA) + 0x400;
        __asm__("" : "=r"(heightValue) : "0"(heightValue));
        Transition23_D_80070328.union144.a.unk13ce.y = heightValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
        Transition23_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition23_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition23_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition23_D_80070328.unk13e[0] = (int) Transition23_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition23_D_80070328.unk20a = 0;
        Transition23_D_80070328.critterMobyPtr = 0;
        Transition23_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x1C:
        savedBase = Transition23RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Transition23RawMovement;
        Transition23RawMovement = MOVEMENT_STATE_HURT;
        Transition23_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Transition23_D_80070328.unk8[0] = Transition23_func_8004EDE8(sourceC, 0);
        Transition23_D_80070328.unk7a[2].z = 0xDC0;
        Transition23_D_80070328.grounded = 0;
        Transition23_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Transition23_D_80070328.damageFlags & 0x200) {
            Transition23_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition23_D_80070328.union144.a.unk13cc = 1;
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        goto clearPointers;
    case 0x1E: {
        register int oldState __asm__("$3")=Transition23RawMovement;
        register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$8")=SpawnParticle;
        register int* stateWord __asm__("$2");
        register int value __asm__("$2");
        __asm__ volatile("" : "=r"(oldState), "=r"(callback) : "0"(oldState), "1"(callback) : "memory");
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Transition23RawMovement=value;
        value=1;
        __asm__("" : "=r"(value) : "0"(value));
        Transition23_D_80070328.grounded=value;
        value=15;
        __asm__("" : "=r"(value) : "0"(value));
        Transition23_D_8006E524=value;
        stateWord=(int*)Transition23RawUnion;
        __asm__("" : "=r"(stateWord) : "0"(stateWord));
        Transition23_D_80070328.unk5=0;
        *stateWord=oldState;
        __asm__ volatile("" : : : "memory");
        *stateWord=0;
        if(callback)callback(5,10,0,0);
        Transition23_D_80070328.unk22[2]=PlaySound((int)D_8006C654->drown,0,0);
        value=(int)D_8006C654->drown;
        __asm__ volatile("" : "=r"(value) : "0"(value) : "memory");
        Transition23_D_80070328.unk20a=0;
        Transition23_D_80070328.critterMobyPtr=0;
        Transition23_D_80070328.unk22[3]=value;
        return;
    }
    case 0x2B:case 0x2C: {
        register unsigned char* unionPointer __asm__("$16");
        {register int stateWord __asm__("$3")=Raw23Word;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Raw23Union;
            *(int*)unionPointer=(-Transition23_D_80070328.unk7a[2].z)>>2;
            if(Raw23Word!=8){Transition23_D_80070328.union144.a.unk13cc=0x5900;Raw23Word=10;}
            Transition23_D_80070328.unk5=0;
            Transition23_D_80070328.unk8[0]=Transition23_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition23_D_80070328.grounded=1;
            Transition23_D_80070328.unk15b=1;
            func_8004F178(&vectors.first,(Vector3D*)(unionPointer-0x144));
            vectors.first.z+=0x400;
            lengthResult=Call23A358(&vectors.first,0x800);
            vectors.first.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,&vectors.first,0);SpawnParticle(6,0x2E,&vectors.first,0);}
        }
        }
        goto clearPointers;
    }
    case 0x2F:case 0x32:case 0x33:case 0x34:
        savedBase=Raw23Movement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition23_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            Transition23_D_80070328.grounded=1;
        }
clearPointers:
        Transition23_D_80070328.unk20a=0;
        Transition23_D_80070328.critterMobyPtr=0;
        return;
    case 0x41:
        Transition23_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition23_func_800441F0();
        Transition23_D_80070328.grounded = 1;
        return;
    case 0x42:
    case 0x45:
        Transition23_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition23_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition23_D_80070328.movementState) + 0x3C)), (Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition23_D_80070328.movementState) + 0x48)));
            Transition23_D_80070328.unk5 = MOVEMENT_STATE_WALK;
        } else {
            Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        }
        Transition23_D_80070328.unk8[0] = Transition23_func_8004EDE8(&Transition23_D_80070328.unk7a[3], 0);
        Transition23_func_80043A38(0xC00);
        Transition23_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition23_D_80070328.grounded = 1;
        goto clearFlags;
    case 0x43:
    case 0x49:
        initialMovement=Raw23Movement;
        __asm__("" : "=r"(initialMovement) : "0"(initialMovement));
        comparisonKind=10;
        __asm__("" : "=r"(comparisonKind) : "0"(comparisonKind));
        {register Moby* critter __asm__("$3")=Transition23_D_80070328.critterMobyPtr;
        register int current __asm__("$4")=*(int*)initialMovement;
        __asm__("" : "=r"(critter),"=r"(current) : "0"(critter),"1"(current));
        jumpPrivate=critter->mobyTag;
        __asm__("" : "=r"(jumpPrivate) : "0"(jumpPrivate));
        if ((current == comparisonKind) && (SpawnParticle != 0) && (Transition23_D_80070328.unk4[0] < 0)) {
            jumpVector=&vectors.second;
            func_8004F178(jumpVector, (Vector3D*)(initialMovement-0x50));
            vectors.second.z = -Transition23_D_80070328.unk4[0];
            SpawnParticle(6, 0x2E, jumpVector, 0);
            SpawnParticle(4, 0x29, jumpVector, 0);
        }
        }
        movement=Raw23Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        firstJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) firstJumpSource);
        Transition23_D_80070328.unk8[0] = Transition23_func_8004EDE8((Vector3D *) firstJumpSource, 0);
        if (arg0 == 0x49) {
            Transition23_D_80070328.unk7a[2].z = 0x2580;
        } else {
            Transition23_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)jumpPrivate+0x4C) = 0;
        }
        Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition23_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition23_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
        goto playJumpSound;
    case 0x44:
        Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        if (Transition23_D_80070328.movementState == MOVEMENT_STATE_JUMP_HOVER) {
            if(Transition23_D_80070328.animationState==0x43)Transition23_D_80070328.unk5=1;
            else if(Transition23_D_80070328.animationState==0x46)Transition23_D_80070328.unk5=Transition23_D_80070328.movementState;
            else if(Transition23_D_80070328.animationState==0x49)Transition23_D_80070328.unk5=4;
        } else {
            Transition23_D_80070328.movementState = MOVEMENT_STATE_FALL;
        }
        Transition23_D_80070328.unk8[0] = Transition23_func_8004EDE8(&Transition23_D_80070328.unk7a[3], 0);
        Transition23_D_80070328.grounded = 0;
        goto clearFlags;
    case 0x46:
        movement=Raw23Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        secondJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) secondJumpSource);
        Transition23_D_80070328.unk8[0] = Transition23_func_8004EDE8((Vector3D *) secondJumpSource, 0);
        Transition23_D_80070328.unk7a[2].z = 0x12C0;
        Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition23_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition23_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
playJumpSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
        return;
    case 0x47:
        if (Transition23_D_80070328.ticksSinceLastSurfaceTouch != 0) {
            if (Transition23_D_80070328.movementState != MOVEMENT_STATE_FALL) {
                if (Transition23_D_80070328.animationState == 0x43) {
                    Transition23_D_80070328.unk5 = MOVEMENT_STATE_WALK;
                } else if (Transition23_D_80070328.animationState == 0x46) {
                    Transition23_D_80070328.unk5 = MOVEMENT_STATE_JUMP_HOVER;
                } else {
                    Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
                }
            }
            Transition23_D_80070328.movementState = MOVEMENT_STATE_FALL;
            Transition23_D_80070328.grounded = 0;
            Transition23_D_80070328.idle = 0;
            Transition23_D_80070328.unk15g = 0;
        } else {
            Transition23_D_80070328.movementState = MOVEMENT_STATE_WALK;
            Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            Transition23_func_80043A38(0xC00);
            Transition23_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition23_D_80070328.grounded = 1;
        }
        Transition23_D_80070328.unk8[0] = Transition23_func_8004EDE8(&Transition23_D_80070328.unk7a[3], 0);
        goto clearFlags;
clearFlags:
        Transition23_D_80070328.idle = 0;
        Transition23_D_80070328.unk15g = 0;
        return;
    case 0x48: {
        register Moby* critter __asm__("$2")=Transition23_D_80070328.critterMobyPtr;
        __asm__ volatile("" : "=r"(critter) : "0"(critter) : "memory");
        damagePrivate=critter->mobyTag;
        __asm__ volatile("" : "=r"(damagePrivate) : "0"(damagePrivate) : "memory");
        previousValue=Raw23Word;
        __asm__ volatile("" : "=r"(previousValue) : "0"(previousValue) : "memory");
        unionBase=Raw23Union;
        __asm__("" : "=r"(previousValue),"=r"(unionBase) : "0"(previousValue),"1"(unionBase));
        *(int*)unionBase=previousValue;
        Raw23Word = MOVEMENT_STATE_HURT;
        if (Transition23_D_80070328.damageFlags & 8) {
            damageSource = (Vector3D *) (unionBase - 0xAC);
            Transition23_D_80070328.unk5 = MOVEMENT_STATE_WALK;
            func_8004F178((Vector3D *) (unionBase - 0xB8), damageSource);
            Transition23_D_80070328.unk8[0] = Transition23_func_8004EDE8(damageSource, 0);
            soundTable=(unsigned char*)D_8006C654;
            soundZero=0;
            __asm__ volatile("" : "=r"(soundTable),"=r"(soundZero) : "0"(soundTable),"1"(soundZero) : "memory");
            Transition23_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)damagePrivate+0x4C) = 0;
            Transition23_D_80070328.grounded = 0;
            Transition23_D_80070328.union144.a.unk13cc = 1;
            PlaySound(soundTable[12],(Moby*)soundZero,0);
        } else {
            Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            damageDestination = (Vector3D *) (unionBase - 0xB8);
            if (Transition23_D_80070328.unk17a & 0x400) {
                func_8004F178(damageDestination, (Vector3D *) ((Vector3D *) (unionBase + 0xD8)));
                Transition23_func_8004F0E8(damageDestination, 6);
            } else if (Transition23_D_80070328.unk22[5] >= 0) {
                tableIndex=Transition23_D_80070328.unk22[5]*2;
                tableValue=*(short*)((unsigned char*)D_80065920+tableIndex);
                __asm__("" : "=r"(tableValue) : "0"(tableValue));
                Raw23X=tableValue>>1;
                tableIndex=*(short*)((unsigned char*)D_800658A0+tableIndex);
                Transition23_D_80070328.unk7a[2].z=0;
                __asm__ volatile("" : "=r"(tableIndex) : "0"(tableIndex) : "memory");
                Transition23_D_80070328.unk7a[2].y=tableIndex>>1;
            } else {
                    __asm__("" : "=r"(unionBase) : "0"(unionBase));
                Transition23_func_8004F168((Vector3D*)(unionBase-0xB8));
            }
            func_8004F178(&Transition23_D_80070328.unk7a[1], (Vector3D *) ((unsigned char*)(&Transition23_D_80070328.unk7a[1]) + 0xC));
            Transition23_func_80043A38(0xC00);
            Transition23_D_80070328.grounded = 1;
        }
        Transition23_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
        break;
    }
    case 0x4A:
        Transition23_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition23_func_80043A38(0xC00);
        Transition23_D_80070328.grounded = 1;
        Transition23_D_8006E524 = 0xF;
        return;
    case 0x4B:
        firstAnimation=Raw23Animation;
        __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        if(firstAnimation==0x44){
            if(Transition23_D_80070328.unk5==4)goto setHeadbashFlag;
            comparisonKind=0x49;
            __asm__ volatile("" : "=r"(comparisonKind) : "0"(comparisonKind) : "memory");
            firstAnimation=Raw23Animation;
            __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        }else comparisonKind=0x49;
        if(firstAnimation==comparisonKind){
setHeadbashFlag:
            Transition23_D_80070328.union144.a.unk13cc=1;
        }else Transition23_D_80070328.union144.a.unk13cc=0;
        Transition23_D_80070328.movementState = MOVEMENT_STATE_HEADBASH;
        Transition23_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition23_func_8004F168((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition23_D_80070328.movementState) + 0x3C)));
        Transition23_D_80070328.unk7a[2].z = 0x800;
        Transition23_D_80070328.grounded = 0;
        Transition23_D_80070328.unk13a[0] = 0x20000;
        Transition23_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        return;
    case 0x4C:
        Transition23_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=1;
        goto setHeadbashSubstate;
    case 0x4D:
        Transition23_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=2;
setHeadbashSubstate:
        Transition23_D_80070328.unk5=nextSubstate;
        Transition23_D_80070328.grounded=0;
        Transition23_D_80070328.unk13a[0]=0x20000;
        return;
    }
}


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8009459C.
 * Assembly SHA256 1b7abf67037af309989f1de9dbe7de07346953de1ac9bfeff9af7ebaf5c99718.
 * AI-generated; not human reviewed. Verified donor state C is adapted to
 * all1346 original instructions and59 state-table entries (bias19).
 * Original65..77 chains retain callback9, masks, nested object/model fields,
 * signed products, query gates, the shared effect call inside71, its original
 * particle callback, descriptor-byte sound call and counter stores. Rev1
 * transition-table evidence is a decoding cross-reference; no browser-derived
 * behavior or values are used. Original18-byte S0/RA frame and actual helper
 * arguments, complete shared entries and all target selectors remain exact.
 * View names retain distinct original typed aliases; their exact assembly
 * symbol identities and donor sources are recorded in the provenance file.
 * Empty metadata consumes initialized values and original source addresses,
 * emits no CPU instructions and retains the original distinct branch joins.
 * C emits every CPU word through the unchanged compiler/assembler/pipeline
 * and flags. Original padding and every acceptance gate remain unchanged.
 * Raw physical units/fixed point, helper/callback contracts and invocation
 * cadence remain unresolved. Cadence per invocation; rate unknown.
 * Falsification: every original native/linked word, conditional/internal
 * target, selector/data record and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime/system completion. */
extern int Anim23Player48View1 __asm__("D_80070328 + 0x48");
extern int Anim23Player4CView1 __asm__("D_80070328 + 0x4C");
extern int Anim23Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim23PlayerA0View1 __asm__("D_80070328 + 0xA0");
extern int Anim23PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim23PlayerB0View1 __asm__("D_80070328 + 0xB0");
extern int Anim23PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim23PlayerCCView1 __asm__("D_80070328 + 0xCC");
extern int Anim23PlayerD0View1 __asm__("D_80070328 + 0xD0");
extern int Anim23PlayerD4View1 __asm__("D_80070328 + 0xD4");
extern int Anim23Player8CView1 __asm__("D_80070328 + 0x8C");
extern int Anim23Player90View1 __asm__("D_80070328 + 0x90");
extern int Anim23Player94View1 __asm__("D_80070328 + 0x94");
extern int Anim23PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern int Anim23Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim23Player280View1 __asm__("D_80070328 + 0x280");
extern unsigned char Anim23Player1B5View1 __asm__("D_80070328 + 0x1B5");
extern unsigned char Anim23Player1B6View1 __asm__("D_80070328 + 0x1B6");
extern int Anim23Data6E538View1 __asm__("D_8006E538"),Anim23Data6E53CView1 __asm__("D_8006E53C");
extern int (*Anim23Data74374View1)() __asm__("unk_ovlheader_80074374");
extern int Anim23Player28CView1 __asm__("D_80070328 + 0x28C");
extern int Anim23Player290View1 __asm__("D_80070328 + 0x290");
extern int Anim23Data6FA38View1 __asm__("D_8006FA38");
int Anim23Call3BF6CView1() __asm__("func_8003BF6C");
int Anim23Call3BE70View1() __asm__("func_8003BE70");
int Anim23Call40994View1() __asm__("func_80040994");
int Anim23Call4BEF8View1() __asm__("func_8004BEF8");
int Anim23Call498C0View1() __asm__("func_800498C0");
extern int Anim23PlayerB4View1 __asm__("D_80070328 + 0xB4");
extern int Anim23PlayerA4View1 __asm__("D_80070328 + 0xA4");
extern int Anim23Player44View1 __asm__("D_80070328 + 0x44");
extern int Anim23Player48View2 __asm__("D_80070328 + 0x48");
extern int Anim23Player4CView2 __asm__("D_80070328 + 0x4C");
extern int Anim23Player50View1 __asm__("D_80070328 + 0x50");
extern int Anim23Player54View2 __asm__("D_80070328 + 0x54");
extern int Anim23Player58View1 __asm__("D_80070328 + 0x58");
extern int Anim23Player8CView2 __asm__("D_80070328 + 0x8C");
extern int Anim23Player90View2 __asm__("D_80070328 + 0x90");
extern int Anim23Player94View2 __asm__("D_80070328 + 0x94");
extern int Anim23PlayerA8View1 __asm__("D_80070328 + 0xA8");
extern int Anim23PlayerACView2 __asm__("D_80070328 + 0xAC");
extern int Anim23PlayerB0View2 __asm__("D_80070328 + 0xB0");
extern int Anim23PlayerB8View2 __asm__("D_80070328 + 0xB8");
extern int Anim23PlayerCCView2 __asm__("D_80070328 + 0xCC");
extern int Anim23PlayerD0View2 __asm__("D_80070328 + 0xD0");
extern int Anim23PlayerD4View2 __asm__("D_80070328 + 0xD4");
extern int Anim23PlayerE4View2 __asm__("D_80070328 + 0xE4");
extern int Anim23Player144View2 __asm__("D_80070328 + 0x144");
extern int Anim23Player280View2 __asm__("D_80070328 + 0x280");
extern unsigned char Anim23Player0View1[] __asm__("D_80070328");
extern unsigned char *Anim23Player250View1 __asm__("D_80070328 + 0x250");
extern unsigned char Anim23Player1B6View2 __asm__("D_80070328 + 0x1B6");
extern unsigned char Anim23Data6E535View1 __asm__("D_8006E535");
extern int Anim23Data6E538View2 __asm__("D_8006E538");
extern int Anim23Data6E53CView2 __asm__("D_8006E53C");
extern int Anim23Data6E530View1 __asm__("D_8006E530");
extern int Anim23Data6E52CView1 __asm__("D_8006E52C");
extern unsigned char *Anim23Data6C654View1 __asm__("D_8006C654");
extern int (*Anim23Data7431CView1)(int) __asm__("unk_ovlheader_8007431C");
extern int (*Anim23DataSpawnParticleView1)(int,int,void*,int) __asm__("SpawnParticle");
int Anim23Call55E84View1(void*) __asm__("func_80055E84");
int Anim23Call1A358View1(void*,int) __asm__("func_8001A358");
int Anim23Call4BEF8View2(int) __asm__("func_8004BEF8");
int Anim23CallPlaySoundView1(unsigned char,int,int) __asm__("PlaySound");
extern int Anim23Player4CView3 __asm__("D_80070328 + 0x4C");
extern int Anim23Player54View3 __asm__("D_80070328 + 0x54");
extern int Anim23Player158View1 __asm__("D_80070328 + 0x158");
extern unsigned char Anim23Player0View2[] __asm__("D_80070328");
extern int A21Buttons __asm__("D_8006E538"),Anim23Data6E53CView3 __asm__("D_8006E53C");
extern int Anim23Data6E044View1 __asm__("D_8006E044"),Anim23Data6E344View1 __asm__("D_8006E344"),Anim23Data6C514View1 __asm__("D_8006C514");
extern int (*Anim23Data74374View2)() __asm__("unk_ovlheader_80074374");
int Anim23Call40994View2() __asm__("func_80040994");
int Anim23Call4BEF8View3() __asm__("func_8004BEF8");
int Anim23Call4F334View1() __asm__("func_8004F334");
extern unsigned char Anim23Player100View1 __asm__("D_80070328 + 0x100");
extern unsigned char Anim23Data6E535View2 __asm__("D_8006E535");
extern unsigned char* Anim23Data6EE2CView1 __asm__("D_8006EE2C");
int Anim23Call1A310View1() __asm__("func_8001A310");
#define Anim23Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
void func_level_23_8009459C(void){
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int nextSelector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* record16 __asm__("$16");
    register int (*callback3)(int) __asm__("$3");
    rawValue2=Anim23Player48View1;
    switch(rawValue2){
    case 19:
        if(Anim23Call40994View2())return;
        rawValue2=13;
        rawValue3=Anim23Data6E344View1;
        if(rawValue3==rawValue2){
            rawValue2=Anim23Data6C514View1;
            nextSelector4=17;
            if(rawValue2)goto select;
        }
        nextSelector4=(int)Anim23Player0View2;
        rawValue2=Anim23Call4F334View1((void*)nextSelector4,(void*)(nextSelector4+348));
        rawValue3=Anim23Player158View1;
        rawValue3=rawValue3<rawValue2;
        nextSelector4=17;
        if(!rawValue3)return;
        goto select;
    case 28:
        if(Anim23Player1B5View1 && (Anim23Data6E53CView1&64))Anim23Player1B6View1=1;
        if(!Anim23PlayerB8View1 && Anim23Player54View1>=16 && Anim23PlayerE4View1<23) {
            rawValue3=Anim23PlayerCCView1;
            rawValue2=Anim23Player8CView1;
            product5=rawValue3*rawValue2;
            rawValue3=Anim23PlayerD0View1;
            rawValue2=Anim23Player90View1;
            nextSelector4=rawValue3*rawValue2;
            rawValue3=Anim23PlayerD4View1;
            rawValue2=Anim23Player94View1;
            rawValue3*=rawValue2;
            rawValue2=product5+nextSelector4;
            rawValue2+=rawValue3;
            if(rawValue2<0) {
                if(Anim23PlayerACView1) {
                    rawValue3=Anim23PlayerB0View1;
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
                rawValue2=Anim23PlayerB0View1<1920;
                nextSelector4=0;
                if(rawValue2)goto select;
                __asm__ volatile("" ::: "memory");
                nextSelector4=4;
                goto select;
            }
        }
        rawValue2=Anim23Data6E538View1&128;
        if(rawValue2 && Anim23Player4CView1==1){
            nextSelector4=22;
            goto select;
        }
        if(Anim23Player1B5View1 && Anim23Player1B6View1) {
            rawValue3=Anim23Player4CView1;
            rawValue2=1;
            nextSelector4=17;
            if(rawValue3!=rawValue2)return;
            goto select;
        }
        rawValue3=Anim23Player4CView1;
        rawValue2=1;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim23PlayerA0View1<-6400;
        nextSelector4=7;
        if(rawValue2)goto select;
        if(Anim23Player54View1>=91)goto select;
        return;
    case 30: {
            register int* timer4 __asm__("$4");
            register int (*callback3)() __asm__("$3");
            if(Anim23Data6E53CView1&64)Anim23Player1B6View1=1;
            if(Anim23Data6FA38View1>=0){
                if(Anim23Player144View1<=0x8FFF)return;
                callback3=Anim23Data74374View1;
                Anim23Player28CView1=-1;
                if(callback3){
                    callback3();
                    return;
                }
                goto call498C0;
            }
            timer4=&Anim23Player280View1;
            __asm__("" : "=r"(timer4):"0"(timer4));
            if(*timer4<0){
                if(Anim23Player144View1<=0x8FFF)return;
                Anim23Player28CView1=-1;
                call498C0:Anim23Call498C0View1();
                __asm__ volatile("" ::: "memory");
                return;
            }
            rawValue3=Anim23Player54View1;
            if(rawValue3>=61){
                *timer4=-1;
                return;
            }
            rawValue2=rawValue3<16;
            __asm__("" : "=r"(rawValue2):"0"(rawValue2));
            if(rawValue2)return;
            if(!Anim23Player1B6View1)return;
            if(Anim23Player28CView1>=0){
                if(Anim23Call3BF6CView1(Anim23Player290View1,Anim23Player28CView1))Anim23Call3BE70View1(Anim23Player28CView1);
                Anim23Player28CView1=-1;
            }
            nextSelector4=6;
            goto select;
        }
    case 43: {
            register unsigned char* byte4 __asm__("$4");
            if(Anim23Call40994View2())return;
            if((Anim23Data6E53CView3&64) && Anim23Player54View3>=9){
                nextSelector4=6;
                goto partialCall;
            }
            byte4=&Anim23Player100View1;
            __asm__("" : "=r"(byte4):"0"(byte4));
            if(!*byte4){
                nextSelector4=7;
                goto partialCall;
            }
            if(!(Anim23Data6E53CView3&128))goto check44;
            if(Anim23Player54View3<9)goto check44;
            rawValue2=*(int*)(Anim23Data6EE2CView1+220);
            byte4-=256;
            if(!rawValue2)goto check44;
            rawValue2=Anim23Call1A310View1(byte4,1024,1,0);
            nextSelector4=40;
            if(rawValue2)goto check44;
            goto select;
            partialCall:Anim23Call4BEF8View3(nextSelector4);
            check44:rawValue2=Anim23Data6E535View2;
            nextSelector4=44;
            if(!rawValue2)return;
            goto select;
        }
    case 44: {
            register unsigned char* byte4 __asm__("$4");
            register int (*callback2)() __asm__("$2");
            rawValue3=Anim23Player4CView3;
            rawValue2=1;
            if(rawValue3!=rawValue2)goto other44;
            if(Anim23Data6E53CView3&0x850)goto callback44;
            if(Anim23Player54View3<61)return;
            callback44:callback2=Anim23Data74374View2;
            __asm__("" : "=r"(callback2):"0"(callback2));
            if(!callback2)goto missingCallback;
            callback2();
            return;
            missingCallback:goto call498C0;
            other44:if(Anim23Call40994View2())return;
            if((Anim23Data6E53CView3&64) && Anim23Player54View3>=9){
                nextSelector4=6;
                goto select;
            }
            byte4=&Anim23Player100View1;
            __asm__("" : "=r"(byte4):"0"(byte4));
            if(!*byte4){
                nextSelector4=7;
                goto select;
            }
            if(!(Anim23Data6E53CView3&128))goto mode44;
            if(Anim23Player54View3<9)goto mode44;
            rawValue2=*(int*)(Anim23Data6EE2CView1+220);
            byte4-=256;
            if(!rawValue2)goto mode44;
            rawValue2=Anim23Call1A310View1(byte4,1024,1,0);
            nextSelector4=40;
            if(!rawValue2)goto select;
            mode44:rawValue3=Anim23Data6E044View1;
            rawValue2=7;
            if(rawValue3==rawValue2)return;
            rawValue2=Anim23Data6E535View2;
            nextSelector4=43;
            if(rawValue2)return;
            goto select;
        }
    case 47:
        if(Anim23Call40994View1())return;
        if(Anim23Data6E53CView1&64){
            rawValue2=Anim23Data6E538View1&16384;
            nextSelector4=6;
            if(rawValue2)goto specialJump;
            __asm__ volatile("" ::: "memory");
            goto select;
        }
        rawValue2=Anim23PlayerACView1;
        nextSelector4=50;
        if(!rawValue2)return;
        goto select;
    case 50:
        if(Anim23Call40994View1())return;
        if(Anim23Data6E53CView1&64){
            rawValue2=Anim23Data6E538View1&16384;
            nextSelector4=6;
            if(rawValue2)goto specialJump;
            goto select;
        }
        rawValue2=Anim23PlayerACView1;
        nextSelector4=47;
        if(!rawValue2)goto select;
        rawValue2=Anim23PlayerA0View1;
        rawValue3=Anim23PlayerB4View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<rawValue3;
        if(!rawValue2)return;
        rawValue2=Anim23PlayerA4View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<1024;
        nextSelector4=52;
        if(!rawValue2)goto select;
        nextSelector4=51;
        goto select;
    case 51: case 52:
        if(Anim23Call40994View1())return;
        if(Anim23Data6E53CView1&64){
            rawValue2=Anim23Data6E538View1&16384;
            nextSelector4=6;
            if(!rawValue2)goto select;
            specialJump:Anim23Call4BEF8View1(7);
            rawValue2=3;
            Anim23Player4CView1=rawValue2;
            return;
        }
        rawValue2=Anim23PlayerACView1;
        nextSelector4=47;
        if(!rawValue2)goto select;
        rawValue2=Anim23PlayerA0View1;
        rawValue3=Anim23PlayerB4View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<rawValue3;
        nextSelector4=50;
        if(rawValue2)return;
        __asm__ volatile("" ::: "memory");
        goto select;
    case 65:
        rawValue2=Anim23Data7431CView1(9);
        if(rawValue2)return;
        rawValue3=Anim23Data6E53CView2;
        rawValue2=rawValue3&64;
        if(rawValue2){
            rawValue2=(int)Anim23Player250View1;
            rawValue2=(int)Anim23Field((void*)rawValue2,void**,0);
            rawValue2=Anim23Field((void*)rawValue2,int*,0x48);
            rawValue2=rawValue2<8;
            nextSelector4=67;
            if(!rawValue2)goto select;
            __asm__ volatile(""::"i"(0x80094DE0):"memory");
            nextSelector4=73;
            goto select;
        }
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=Anim23PlayerB8View2<4;
        nextSelector4=68;
        if(!rawValue2)goto select;
        rawValue2=Anim23PlayerE4View2<23;
        if(!rawValue2)goto select;
        rawValue2=Anim23PlayerA8View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<17;
        nextSelector4=66;
        if(!rawValue2)goto select;
        rawValue2=Anim23Data6E538View2&12;
        if(rawValue2)return;
        rawValue2=Anim23PlayerACView2;
        if(!rawValue2)return;
        goto select;
    case 66:
        rawValue2=Anim23Data7431CView1(9);
        if(rawValue2)return;
        rawValue3=Anim23Data6E53CView2;
        rawValue2=rawValue3&64;
        if(rawValue2){
            rawValue2=(int)Anim23Player250View1;
            rawValue2=(int)Anim23Field((void*)rawValue2,void**,0);
            rawValue2=Anim23Field((void*)rawValue2,int*,0x48);
            rawValue2=rawValue2<8;
            nextSelector4=67;
            if(!rawValue2)goto select;
            __asm__ volatile(""::"i"(0x80094ED4):"memory");
            nextSelector4=73;
            goto select;
        }
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=Anim23PlayerB8View2<4;
        nextSelector4=68;
        if(!rawValue2)goto select;
        rawValue2=Anim23PlayerE4View2<23;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim23Player250View1;
        rawValue2=Anim23Player48View2;
        rawValue3=Anim23Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)goto query66;
        rawValue2=Anim23Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(rawValue2)goto input66;
    query66:
        rawValue2=Anim23Call55E84View1((void*)nextSelector4);
        rawValue2=rawValue2<4;
        if(!rawValue2)return;
    input66:
        rawValue2=Anim23Data6E535View1;
        if(!rawValue2)goto held66;
        rawValue2=Anim23PlayerB0View2;
        nextSelector4=65;
        if(!rawValue2)goto select;
    held66:
        rawValue2=Anim23Data6E538View2&12;
        if(!rawValue2)return;
        rawValue2=Anim23Player144View2<16;
        nextSelector4=65;
        if(rawValue2)return;
        goto select;
    case 67:
        rawValue2=Anim23Data7431CView1(9);
        if(rawValue2)return;
        rawValue2=Anim23Player54View2<16;
        if(!rawValue2){
            rawValue2=Anim23Data6E53CView2&64;
            nextSelector4=70;
            if(rawValue2)goto select;
        }
        rawValue3=Anim23Data6E53CView2;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            product5=Anim23Player44View1;
            nextSelector4=(int)Anim23Player0View1;
            rawValue2=Anim23Call1A358View1((void*)nextSelector4,product5+512);
            nextSelector4=75;
            if(!rawValue2)goto select;
        }
        rawValue2=Anim23PlayerB8View2;
        if(rawValue2)goto finish67;
        rawValue2=Anim23Player54View2<16;
        if(rawValue2)goto finish67;
        rawValue2=Anim23PlayerE4View2<23;
        if(!rawValue2)return;
        rawValue3=Anim23PlayerCCView2;
        rawValue2=Anim23Player8CView2;
        product5=rawValue3*rawValue2;
        rawValue3=Anim23PlayerD0View2;
        rawValue2=Anim23Player90View2;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim23PlayerD4View2;
        rawValue2=Anim23Player94View2;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)return;
        rawValue2=Anim23PlayerACView2;
        nextSelector4=66;
        if(!rawValue2)goto select65;
        __asm__ volatile(""::"i"(0x80095108):"memory");
        goto select;
    finish67:
        nextSelector4=(int)Anim23Player250View1;
        rawValue2=Anim23Player48View2;
        rawValue3=Anim23Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim23Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=68;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x80095144):"memory");
        goto select;
    case 68:
        rawValue2=(int)Anim23Player250View1;
        callback3=Anim23Data7431CView1;
        record16=Anim23Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(9);
        if(rawValue2)return;
        rawValue2=Anim23Data6E53CView2&64;
        if(rawValue2){
            rawValue2=1;
            nextSelector4=(int)&Anim23Player4CView2;
            rawValue3=*(int*)nextSelector4;
            __asm__("":"=r"(rawValue2):"0"(rawValue2));
            if(rawValue3==rawValue2){
                rawValue2=Anim23Player54View2<31;
                nextSelector4-=76;
                if(rawValue2){
                    rawValue2=Anim23Call1A358View1((void*)nextSelector4,1024);
                    if(!rawValue2){
                        nextSelector4=70;
                        goto select;
                    }
                }
            }
            rawValue2=1;
            Anim23Player1B6View2=rawValue2;
            Anim23Field(record16,int*,0x48)=0;
        }
        rawValue3=Anim23Data6E53CView2;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            nextSelector4=(int)&Anim23Player4CView2;
            rawValue2=*(int*)nextSelector4;
            nextSelector4-=76;
            if(rawValue2){
                product5=Anim23Player44View1;
                rawValue2=Anim23Call1A358View1((void*)nextSelector4,product5+512);
                nextSelector4=75;
                if(!rawValue2)goto select;
            }
        }
        rawValue2=Anim23PlayerB8View2;
        if(rawValue2)return;
        rawValue2=Anim23PlayerE4View2<23;
        if(!rawValue2)return;
        rawValue2=Anim23Player1B6View2;
        if(rawValue2){
            rawValue2=Anim23Field(record16,int*,0x48)<7;
            if(rawValue2){
                rawValue2=2;
                rawValue3=Anim23Player50View1;
                nextSelector4=67;
                if(rawValue3!=rawValue2)goto effectSelect;
                nextSelector4=73;
                goto effectSelect;
            }
        }
        rawValue3=Anim23Player50View1;
        rawValue2=2;
        if(rawValue3==rawValue2){
            Anim23Field(record16,int*,0x48)=0;
        }
        else{
            rawValue2=255;
            Anim23Field(record16,int*,0x48)=rawValue2;
        }
        rawValue2=Anim23PlayerACView2;
        nextSelector4=66;
        if(rawValue2)goto effectSelect;
        nextSelector4=69;
        goto effectSelect;
    case 69:
        rawValue2=Anim23Data7431CView1(9);
        if(rawValue2)return;
        rawValue3=Anim23Data6E53CView2;
        rawValue2=rawValue3&64;
        if(rawValue2){
            rawValue2=(int)Anim23Player250View1;
            rawValue2=(int)Anim23Field((void*)rawValue2,void**,0);
            rawValue2=Anim23Field((void*)rawValue2,int*,0x48);
            rawValue2=rawValue2<8;
            nextSelector4=67;
            if(!rawValue2)goto select;
            __asm__ volatile(""::"i"(0x8009533C):"memory");
            nextSelector4=73;
            goto select;
        }
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=Anim23PlayerB8View2<4;
        nextSelector4=68;
        if(!rawValue2)goto select;
        rawValue2=Anim23PlayerE4View2<23;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim23Player250View1;
        rawValue2=Anim23Player48View2;
        rawValue3=Anim23Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)goto query69;
        rawValue2=Anim23Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(rawValue2)goto input69;
    query69:
        rawValue2=Anim23Call55E84View1((void*)nextSelector4);
        rawValue2=rawValue2<4;
        if(!rawValue2)return;
    input69:
        rawValue2=Anim23Data6E535View1;
        if(!rawValue2)goto held69;
        rawValue2=Anim23PlayerB0View2;
        nextSelector4=65;
        if(!rawValue2)goto select;
    held69:
        rawValue2=Anim23Data6E538View2&12;
        nextSelector4=66;
        if(!rawValue2)goto select;
        rawValue2=Anim23Player144View2<16;
        if(!rawValue2)goto select65;
        goto select;
    case 70: case 73:
        rawValue2=Anim23Data7431CView1(9);
        if(rawValue2)return;
        rawValue3=Anim23Data6E53CView2;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            product5=Anim23Player44View1;
            nextSelector4=(int)Anim23Player0View1;
            rawValue2=Anim23Call1A358View1((void*)nextSelector4,product5+512);
            nextSelector4=75;
            if(!rawValue2)goto select;
        }
        rawValue2=Anim23PlayerB8View2;
        if(rawValue2)goto finish70;
        rawValue2=Anim23Player54View2<16;
        if(rawValue2)goto finish70;
        rawValue2=Anim23PlayerE4View2<23;
        if(!rawValue2)return;
        rawValue3=Anim23PlayerCCView2;
        rawValue2=Anim23Player8CView2;
        product5=rawValue3*rawValue2;
        rawValue3=Anim23PlayerD0View2;
        rawValue2=Anim23Player90View2;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim23PlayerD4View2;
        rawValue2=Anim23Player94View2;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)return;
        rawValue2=Anim23PlayerACView2;
        nextSelector4=66;
        if(!rawValue2)goto select65;
        __asm__ volatile(""::"i"(0x80095540):"memory");
        goto select;
    finish70:
        nextSelector4=(int)Anim23Player250View1;
        rawValue2=Anim23Player48View2;
        rawValue3=Anim23Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim23Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=68;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x8009557C):"memory");
        goto select;
    case 71:
        rawValue2=Anim23Data7431CView1(9);
        if(rawValue2)return;
        rawValue2=3;
        rawValue3=Anim23Player50View1;
        if(rawValue3!=rawValue2)goto other71;
        rawValue2=Anim23PlayerB8View2;
        if(rawValue2)goto finish71;
        rawValue2=Anim23PlayerE4View2<23;
        nextSelector4=71;
        if(!rawValue2)return;
    effectSelect:
        Anim23Call4BEF8View2(nextSelector4);
        {
            register int (*spawn2)(int,int,void*,int) __asm__("$2")=Anim23DataSpawnParticleView1;
            if(spawn2)spawn2(8,33,0,2);
        }
        rawValue2=(int)Anim23Data6C654View1;
        product5=0;
        nextSelector4=Anim23Field((void*)rawValue2,unsigned char*,0x12);
        Anim23CallPlaySoundView1((unsigned char)nextSelector4,product5,0);
        rawValue2=Anim23Player58View1<24;
        if(rawValue2)return;
        rawValue2=120;
        Anim23Data6E530View1=rawValue2;
        rawValue2=15;
        Anim23Data6E52CView1=rawValue2;
        return;
    finish71:
        nextSelector4=(int)Anim23Player250View1;
        rawValue2=Anim23Player48View2;
        rawValue3=Anim23Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim23Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=68;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x8009568C):"memory");
        goto select;
    other71:
        rawValue2=Anim23PlayerB8View2<4;
        nextSelector4=71;
        if(!rawValue2)goto select;
        rawValue2=Anim23PlayerE4View2<23;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim23Player250View1;
        rawValue2=Anim23Player48View2;
        rawValue3=Anim23Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)goto query71;
        rawValue2=Anim23Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)goto query71;
        rawValue2=Anim23Data6E535View1;
        nextSelector4=65;
        if(rawValue2)goto select;
        nextSelector4=66;
        goto select;
    query71:
        rawValue2=Anim23Call55E84View1((void*)nextSelector4);
        rawValue2=rawValue2<16;
        if(rawValue2)return;
        rawValue2=Anim23Data6E535View1;
        nextSelector4=66;
        if(rawValue2)return;
        goto select;
    case 72:
        rawValue2=Anim23Player4CView2;
        if(!rawValue2)goto finish72;
        rawValue2=Anim23Player280View2;
        if(rawValue2<0)goto finish72;
        rawValue2=Anim23Player54View2<16;
        if(!rawValue2){
            rawValue2=Anim23Data6E53CView2&64;
            nextSelector4=70;
            if(rawValue2)goto select;
        }
        rawValue3=Anim23Data6E53CView2;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            product5=Anim23Player44View1;
            nextSelector4=(int)Anim23Player0View1;
            rawValue2=Anim23Call1A358View1((void*)nextSelector4,product5+512);
            nextSelector4=75;
            if(!rawValue2)goto select;
        }
        rawValue2=Anim23PlayerB8View2;
        if(rawValue2)goto finish72;
        rawValue2=Anim23Player54View2<16;
        if(rawValue2)goto finish72;
        rawValue2=Anim23PlayerE4View2<23;
        if(!rawValue2)goto finish72;
        rawValue3=Anim23PlayerCCView2;
        rawValue2=Anim23Player8CView2;
        product5=rawValue3*rawValue2;
        rawValue3=Anim23PlayerD0View2;
        rawValue2=Anim23Player90View2;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim23PlayerD4View2;
        rawValue2=Anim23Player94View2;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)goto finish72;
        rawValue2=Anim23PlayerACView2;
        nextSelector4=66;
        if(!rawValue2)goto select65;
        goto select;
    finish72:
        nextSelector4=(int)Anim23Player250View1;
        rawValue2=Anim23Player48View2;
        rawValue3=Anim23Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim23Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        rawValue2=Anim23Player280View2;
        if(rawValue2<0){
            nextSelector4=74;
            goto select;
        }
        rawValue2=10;
        rawValue3=Anim23Player144View2;
        nextSelector4=79;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim23PlayerB8View2;
        nextSelector4=68;
        if(!rawValue2)goto select65;
        goto select;
    case 74:
        nextSelector4=(int)Anim23Player250View1;
        rawValue2=Anim23Player48View2;
        rawValue3=Anim23Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim23Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        goto call498C0;
    case 75:
        rawValue2=Anim23Data7431CView1(9);
        if(rawValue2)return;
        rawValue2=2;
        rawValue3=Anim23Player4CView2;
        nextSelector4=77;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim23Player54View2<61;
        nextSelector4=68;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim23Player250View1;
        rawValue2=Anim23Player48View2;
        rawValue3=Anim23Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim23Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=76;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x800959DC):"memory");
        goto select;
    case 76:
        rawValue2=Anim23Data7431CView1(9);
        if(rawValue2)return;
        rawValue2=2;
        rawValue3=Anim23Player4CView2;
        nextSelector4=77;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim23Player54View2<61;
        nextSelector4=68;
        if(rawValue2)return;
        goto select;
    case 77:
        rawValue2=Anim23Data7431CView1(9);
        if(rawValue2)return;
        nextSelector4=(int)Anim23Player250View1;
        rawValue2=Anim23Player48View2;
        rawValue3=Anim23Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim23Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
    select65:
        nextSelector4=65;
        goto select;
        default:return;
    }
    select:Anim23Call4BEF8View1(nextSelector4);
    return;
}
#undef Anim23Field
