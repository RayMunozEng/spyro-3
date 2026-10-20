#include "common.h"
#include "stdutil.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80083354.
 * Assembly SHA256 085f16aaaa9a07345dc8e227b4985a0f6ccfe440f5df6bda2ccff217fcb037ae.
 * AI-generated; not human reviewed. All1247 original instructions,
 * 15 selectors bias65 and 1 owned padding words are required.
 * Original frame0xD8; every concrete field width and producer is retained.
 * Nine exact groups reuse verified11 Sheila physics. Original78/79 uses
 * direct frame addresses in place of23's saved frame pointer; original75..77
 * owns the final eight epilogue rows. Original scratch10..BC,savedS0..S3,
 * slotS2,combinedS3,all65..79 selectors and actual shared joins remain.
 * All original scalar/vector/control/spring/particle arithmetic is retained.
 * Typed aliases stay distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit words.
 * Raw units/fixed point, helper contracts and caller rate remain unresolved.
 * Cadence is per invocation. Falsification: every native/linked instruction,
 * actual internal/conditional target,selector/data word and full EXE/every
 * overlay retail hash. Binary identity does not establish runtime completion. */
#define Physics16Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Physics16Call363DCView1() __asm__("func_800363DC");
unsigned char Physics16Call40D10View1() __asm__("func_80040D10");
unsigned char Physics16Call41580View1() __asm__("func_80041580");
unsigned char Physics16Call417FCView1() __asm__("func_800417FC");
unsigned char Physics16Call41B64View1() __asm__("func_80041B64");
int Physics16Call4E9E4View1() __asm__("func_8004E9E4");
int Physics16Call4EA2CView1() __asm__("func_8004EA2C");
unsigned char Physics16Call4ED6CView1() __asm__("func_8004ED6C");
int Physics16Call4EDE8View1() __asm__("func_8004EDE8");
unsigned char Physics16Call4F08CView1() __asm__("func_8004F08C");
unsigned char Physics16Call4F194View1() __asm__("func_8004F194");
unsigned char Physics16Call4F1C8View1() __asm__("func_8004F1C8");
int Physics16CallRandView1() __asm__("rand");
extern unsigned char Physics16Data658A0View1 __asm__("D_800658A0");
extern unsigned char Physics16Data65920View1 __asm__("D_80065920");
extern void *Physics16Data6C570View1 __asm__("D_8006C570");
extern unsigned char Physics16Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics16Player0View1 __asm__("D_80070328");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics16Call40D10View2() __asm__("func_80040D10");
int Physics16Call41580View2() __asm__("func_80041580");
int Physics16Call416F4View1() __asm__("func_800416F4");
int Physics16Call417FCView2() __asm__("func_800417FC");
int Physics16Call41848View1() __asm__("func_80041848");
int Physics16Call41B64View2() __asm__("func_80041B64");
int Physics16Call4EDE8View2() __asm__("func_8004EDE8");
int Physics16Call4F08CView2() __asm__("func_8004F08C");
int Physics16Call4F168View1() __asm__("func_8004F168");
int Physics16Call4F178View1() __asm__("func_8004F178");
int Physics16Call4F194View2() __asm__("func_8004F194");
int Physics16Call4F1C8View2() __asm__("func_8004F1C8");
extern int Physics16Data6E044View1 __asm__("D_8006E044");
extern int Physics16Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics16Player0View2 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics16PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics16Player94View1 __asm__("D_80070328+0x94");
extern int Physics16PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics16PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics16Player88View1 __asm__("D_80070328+0x88");
extern int Physics16Player84View1 __asm__("D_80070328+0x84");
extern int Physics16Player144View1 __asm__("D_80070328+0x144");
extern int Physics16PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics16Player4CView1 __asm__("D_80070328+0x4C");
extern unsigned char Physics16PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics16PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics16Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics16Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics16Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics16Player101View1 __asm__("D_80070328+0x101");
extern int Physics16PlayerA4View1 __asm__("D_80070328+0xA4");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics16PlayerE4View1 __asm__("D_80070328+0xE4");
int Physics16Call40D10View3() __asm__("func_80040D10");
int Physics16Call41580View3() __asm__("func_80041580");
int Physics16Call417FCView3() __asm__("func_800417FC");
int Physics16Call41848View2() __asm__("func_80041848");
int Physics16Call41B64View3() __asm__("func_80041B64");
int Physics16Call4ED6CView2() __asm__("func_8004ED6C");
int Physics16Call4F110View1() __asm__("func_8004F110");
int Physics16Call4F168View2() __asm__("func_8004F168");
int Physics16Call4F178View2() __asm__("func_8004F178");
int Physics16Call4F194View3() __asm__("func_8004F194");
int Physics16CallRandView2() __asm__("rand");
extern int Physics16Data6C640View1 __asm__("D_8006C640");
extern int Physics16Data6E044View2 __asm__("D_8006E044");
extern unsigned char Physics16Player0View3 __asm__("D_80070328");
extern void *(*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics50_SpawnParticle)() __asm__("SpawnParticle");
int Physics16Call4F110View2() __asm__("func_8004F110");
int Physics16Call4F178View3() __asm__("func_8004F178");
int Physics16Call4F194View4() __asm__("func_8004F194");
extern int Physics16Data6E1D4View1 __asm__("D_8006E1D4");
extern int Physics16Data6E1D8View1 __asm__("D_8006E1D8");
extern int Physics16Data6E52CView1 __asm__("D_8006E52C");
extern int Physics16Data6E530View1 __asm__("D_8006E530");
extern void *(*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics16Player250View1 __asm__("D_80070328+0x250");
extern int Physics16Player54View1 __asm__("D_80070328+0x54");
extern int Physics16PlayerD4View1 __asm__("D_80070328+0xD4");
extern void *Physics16Data6C654View1 __asm__("D_8006C654");
int Physics16DataPlaySoundView1() __asm__("PlaySound");
extern int Physics16Player8CView1 __asm__("D_80070328+0x8C");
extern int Physics16Player90View1 __asm__("D_80070328+0x90");
extern void *(*Physics44_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Physics44Slot4454)() __asm__("unk_ovlheader_80074454");
extern int (*Physics44Slot432C)() __asm__("unk_ovlheader_8007432C");
void func_level_16_80083354(int slotIndex) {
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
    register int particleThreshold __asm__("$19");
    register void *vectorAt40 __asm__("$16");
    register void *vectorAt30 __asm__("$17");
    register void *call4 __asm__("$4");
    register void *call5 __asm__("$5");
    register void *call6 __asm__("$6");
    int lowProduct0,lowProduct1,lowProduct2,lowProduct3,lowProduct4,lowProduct5;
    register void *globalPointer __asm__("$3");
    struct {
        int sp10,sp14,sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4,spB8,spBC;
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
    globalPointer=&Physics16Data6E548View1;
    workWord2+=(int)globalPointer;
    __asm__("":"=r"(workWord2):"0"(workWord2));
    Physics16Data6C570View1=(void*)workWord2;
    workWord2=Physics16Field(&Physics16Player0View1,int*,0x54);
    stateWord3=Physics16Field(&Physics16Player0View1,int*,0x48);
    combinedIndex=workWord2+savedSlotIndex;
    switch(stateWord3){
        default:return;
    case 78:case 79:globalField4CPointer=&Physics16Player4CView1;
        __asm__("":"=r"(globalField4CPointer):"0"(globalField4CPointer));
        workWord3=Physics16Field(globalField4CPointer,int*,0);
        workWord2=1;
        if(workWord3!=workWord2)goto continue43;
        block_154:Physics16Call4F168View2(globalField4CPointer+52);
        Physics16Call4F168View2(globalField4CPointer+64);
        return;
        continue43:workWord2=7;
        workWord3=Physics16Data6E044View2;
        if (workWord3 == workWord2) {
            Physics16Field(&Physics16Player0View3, int *, 0xB0) = 0;
        }
        else {
            Physics16Call40D10View3(0x980);
            raw21_var_v0_2 = Physics16Call41580View3(0x5A, 0x10);
            if (raw21_var_v0_2 < 0) {
                raw21_var_v0_2 = -raw21_var_v0_2;
            }
            if (raw21_var_v0_2 >= 0x201) {
                Physics16Field(&Physics16Player0View3, int *, 0xAC) = 0;
            }
            raw21_var_a0_2 = 0xC0;
            if (Physics16Field(&Physics16Player0View3, int *, 0xB0) >= 0xC81) {
                raw21_var_a0_2 = 0;
                raw21_var_a1_4 = 0xC0;
            }
            else {
                raw21_var_a1_4 = 0x40;
            }
            Physics16Call417FCView3(raw21_var_a0_2, raw21_var_a1_4);
        }
        raw21_temp_s0_11 = &Physics16Player0View3 + 0xB0;
        if (Physics16Field(&Physics16Player0View3, int *, 0xB0) != 0) {
            Physics16Call41848View2();
            Physics16Call41B64View3();
            Physics16Field(&Physics16Player0View3, int *, 0x94) = 0;
        }
        else {
            Physics16Call4F168View2(raw21_temp_s0_11 - 0x30);
            Physics16Call4F168View2(raw21_temp_s0_11 - 0x24);
        }
        if (Physics21_SpawnParticle != 0) {
            raw21_temp_s4 = &Physics16Player0View3 + 0x28;
            if (Physics16Field(&Physics16Player0View3, int *, 0x28) < 0) {
                if ((Physics16Field(&Physics16Player0View3, int *, 0xB0) >= 0x401) && (savedSlotIndex < 2) && (Physics16Data6C640View1 & 1)) {
                    Physics16Call4F178View2(&originalFrame.sp10, raw21_temp_s4 - 0x28);
                    originalFrame.sp24 = 0x40;
                    originalFrame.sp28 = 0;
                    originalFrame.sp20 = (int) Physics16Field(&Physics16Player0View3, int *, 0xB0) >> 5;
                    if (savedSlotIndex != 0) {
                        originalFrame.sp24 = -0x40;
                    }
                    raw21_temp_s2_3 = raw21_temp_s4 + 8;
                    Physics16Call4ED6CView2(raw21_temp_s2_3, &originalFrame.sp20, &originalFrame.sp30);
                    Physics16Call4F194View3(&originalFrame.sp10, &originalFrame.sp10, &originalFrame.sp30);
                    originalFrame.sp20 = 0;
                    originalFrame.sp18 = -Physics16Field(&Physics16Player0View3, int *, 0x28);
                    Physics16Call4ED6CView2(raw21_temp_s2_3, &originalFrame.sp20, &originalFrame.sp20);
                    Physics16Call4F110View1(&originalFrame.sp20, 3);
                    Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp10, &originalFrame.sp20);
                    if (!(Physics16CallRandView2() & 0x1F)) {
                        Physics21_SpawnParticle(1, 0x29, &originalFrame.sp10, 0);
                    }
                }
                else {
                    raw21_temp_s1_7 = &Physics16Player0View3 + 0xB0;
                    if ((Physics16Field(&Physics16Player0View3, int *, 0xB0) < 0x201) && (savedSlotIndex == 0) && !(Physics16Data6C640View1 & 7) && !(Physics16CallRandView2() & 3)) {
                        originalFrame.sp40 = 0x80;
                        __asm__("":"=r"(savedSlotIndex):"0"(savedSlotIndex));
                        originalFrame.sp44 = 0;
                        originalFrame.sp48 = 0;
                        Physics16Call4ED6CView2(raw21_temp_s1_7 - 0x80, &originalFrame.sp40, &originalFrame.sp40);
                        Physics16Call4F194View3(&originalFrame.sp40, &originalFrame.sp40, raw21_temp_s1_7 - 0xB0);
                        originalFrame.sp48 = -Physics16Field(&Physics16Player0View3, int *, 0x28);
                        Physics21_SpawnParticle(1, 0x2B, &originalFrame.sp40, (int *)1);
                    }
                }
            }
        }
        raw21_temp_a1_4 = Physics16Field(&Physics16Player0View3, int *, 0x144) - ((int) ((Physics16Field(&Physics16Player0View3, int *, 0x148) * 2) + (Physics16Field(&Physics16Player0View3, int *, 0x144) * 0x14)) >> 8);
        raw21_temp_a0_7 = Physics16Field(&Physics16Player0View3, int *, 0x148) + raw21_temp_a1_4;
        Physics16Field(&Physics16Player0View3, int *, 0x144) = raw21_temp_a1_4;
        Physics16Field(&Physics16Player0View3, int *, 0x148) = raw21_temp_a0_7;
        if (raw21_temp_a0_7 >= 0x5901) {
            Physics16Field(&Physics16Player0View3, int *, 0x148) = 0x5900;
        }
        if (Physics16Field(&Physics16Player0View3, int *, 0x148) < -0x5900) {
            Physics16Field(&Physics16Player0View3, int *, 0x148) = -0x5900;
            return;
        }
        break;
    case 65:globalVector80=&Physics16Player0View2+0x80;
        Physics16Call4F168View1(globalVector80);
        Physics16Call4F168View1(globalVector80+12);
        if(Physics16Data6E044View1!=7){
            Physics16Call40D10View2(6016);
            Physics16Call416F4View1();
            Physics16Call41580View2(90,16);
        }
        workWord2=Physics16Player1BAView1;
        if(!workWord2)goto byteOne65;
        workWord2=Physics16Data6E538View1&16;
        if(workWord2)return;
        workWord2=1;
        Physics16Player1BAView1=0;
        Physics16Player1B9View1=workWord2;
        return;
        byteOne65:workWord2=1;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        Physics16Player1B9View1=workWord2;
        return;
    case 66:case 69:workWord3=Physics16Data6E044View1;
        workWord2=8;
        if(workWord3!=workWord2)Physics16Call40D10View2(6016);
        globalVector80=&Physics16Data6E538View1;
        workWord2=Physics16Field(globalVector80,int*,0)&12;
        if(workWord2)Physics16PlayerACView1=0;
        workWord2=Physics16Call416F4View1();
        call4=(void*)90;
        call5=(void*)16;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalFieldA4Pointer=(void*)workWord2;
        workWord2=Physics16Call41580View2(call4,call5);
        workWord3=Physics16PlayerA8View1;
        if(workWord3<0)workWord3=-workWord3;
        workWord3=workWord3<8;
        __asm__("":"=r"(workWord3):"0"(workWord3),"r"(workWord2));
        call5=(void*)workWord2;
        if(!workWord3)goto reset101;
        workWord2=Physics16Field(globalVector80,int*,0)&12;
        if(!workWord2)goto reset101;
        workWord2=Physics16Player144View1;
        workWord2++;
        Physics16Player144View1=workWord2;
        goto saved101;
        reset101:Physics16Player144View1=0;
        saved101:call4=&Physics16PlayerACView1;
        globalVector80=(void*)Physics16Field(call4,int*,0);
        if(globalFieldA4Pointer)goto collision101;
        workWord2=(int)call5;
        if((int)call5<0)workWord2=-workWord2;
        workWord2=workWord2<513;
        if(workWord2)goto pass101;
        collision101:workWord2=Physics16Player20CView1&64;
        if(workWord2)Physics16Field(call4,int*,0)=0;
        else{
            workWord3=Physics16PlayerB0View1;
            workWord2=workWord3<(int)globalVector80;
            if(workWord2)Physics16Field(call4,int*,0)=workWord3;
        }
        pass101:Physics16Call417FCView2(320,192);
        workWord2=Physics16Player101View1;
        call4=&Physics16PlayerACView1;
        Physics16Field(call4,int*,0)=(int)globalVector80;
        if(workWord2){
            Physics16Call4F168View1(call4-32);
            goto fields101;
        }
        Physics16Call41848View1(call4);
        Physics16Call41B64View2();
        fields101:call6=&Physics16PlayerFCView1;
        workWord2=Physics16Field(call6,unsigned char*,0);
        if(workWord2)goto block_303;
        workWord2=Physics16PlayerB8View1;
        call4=call6-112;
        if(workWord2)goto block_303;
        commit101:goto vectorInput71;
    case 67:{
            int lowProduct3Case67,lowProduct4Case67;
            Physics16Call40D10View1(0xC80);
            Physics16Call41580View1(0x28, 8);
            Physics16Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics16Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics16Call4EA2CView1(Physics16Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics16Field(&Physics16Player0View1,int*,0xB0);
            lowProduct3Case67=workWord3*workWord2;
            call4=(void*)Physics16Field(globalFieldA4Pointer,int*,0);
            workWord2=lowProduct3Case67>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp30=workWord2;
            workWord2=Physics16Call4E9E4View1(call4);
            workWord3=Physics16Field(&Physics16Player0View1,int*,0xB0);
            lowProduct4Case67=workWord3*workWord2;
            workWord2=lowProduct4Case67>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp34=workWord2;
            Physics16Call4F1C8View1(&originalFrame.sp30, &originalFrame.sp30, globalVector8C);
            originalFrame.sp38 = 0;
            temp_v0_4 = Physics16Call4EDE8View1(&originalFrame.sp30, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics16Call4F08CView1(&originalFrame.sp30, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics16Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp30);
            Physics16Call41B64View1();
            workWord2=combinedIndex<13;
            if(!workWord2)goto subtract320_73;
            workWord2=Physics16Player4CView1;
            if(workWord2)goto subtract320_73;
            workWord2=(int)Physics16Data6C570View1;
            workWord2=Physics16Field((void*)workWord2,int*,0)&64;
            if(workWord2)goto add30_70;
            workWord2=Physics16Player144View1;
            if(workWord2)goto add30_70;
            goto subtract320_73;
        }
    case 68:{
            register void *child19 __asm__("$19");
            register int numeric5 __asm__("$5");
            int lowProduct3Case68,lowProduct4Case68;
            globalFieldA4Pointer=&Physics16Player4CView1;
            workWord2=2;
            globalPointer=(void*)Physics16Player250View1;
            call4=(void*)Physics16Field(globalFieldA4Pointer,int*,0);
            child19=Physics16Field(globalPointer,void**,0);
            numeric5=1600;
            if((int)call4==workWord2)numeric5=3200;
            Physics16Call40D10View1(numeric5,numeric5);
            Physics16Call41580View1(22,4);
            Physics16Call417FCView1(320,192);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            globalVector8C=globalFieldA4Pointer+64;
            workWord2=Physics16Call4EA2CView1(Physics16Field(globalFieldA4Pointer,int*,88));
            workWord3=Physics16PlayerB0View1;
            lowProduct3Case68=workWord3*workWord2;
            call4=(void*)Physics16Field(globalFieldA4Pointer,int*,88);
            workWord2=lowProduct3Case68>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp50=workWord2;
            workWord2=Physics16Call4E9E4View1(call4);
            workWord3=Physics16PlayerB0View1;
            lowProduct4Case68=workWord3*workWord2;
            workWord2=lowProduct4Case68>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp54=workWord2;
            Physics16Call4F1C8View1(&originalFrame.sp50, &originalFrame.sp50, globalVector8C);
            originalFrame.sp58 = 0;
            temp_v0_4 = Physics16Call4EDE8View1(&originalFrame.sp50, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer+52;
            if (temp_v0_4 >= 0x141) {
                Physics16Call4F08CView1(&originalFrame.sp50, temp_v0_4, 0x140);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer+52;
            }
            Physics16Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp50);
            Physics16Call41B64View1();
            workWord2=Physics16Player94View1;
            workWord2-=320;
            Physics16Player94View1=workWord2;
            workWord2=workWord2<-12800;
            if(workWord2){
                workWord2=-12800;
                Physics16Field(globalFieldA4Pointer,int*,72)=workWord2;
            }
            workWord2=Physics16Field(globalFieldA4Pointer,unsigned char*,362);
            if(!workWord2)return;
            workWord2=Physics16Field(child19,int*,72);
            workWord2++;
            Physics16Field(child19,int*,72)=workWord2;
            return;
        }
    case 70:{
            int lowProduct3Case70,lowProduct4Case70;
            Physics16Call40D10View1(0xC80);
            Physics16Call41580View1(0x28, 8);
            Physics16Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics16Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics16Call4EA2CView1(Physics16Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics16Field(&Physics16Player0View1,int*,0xB0);
            lowProduct3Case70=workWord3*workWord2;
            call4=(void*)Physics16Field(globalFieldA4Pointer,int*,0);
            workWord2=lowProduct3Case70>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp60=workWord2;
            workWord2=Physics16Call4E9E4View1(call4);
            workWord3=Physics16Field(&Physics16Player0View1,int*,0xB0);
            lowProduct4Case70=workWord3*workWord2;
            workWord2=lowProduct4Case70>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp64=workWord2;
            Physics16Call4F1C8View1(&originalFrame.sp60, &originalFrame.sp60, globalVector8C);
            originalFrame.sp68 = 0;
            temp_v0_4 = Physics16Call4EDE8View1(&originalFrame.sp60, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics16Call4F08CView1(&originalFrame.sp60, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics16Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp60);
            Physics16Call41B64View1();
            workWord2=combinedIndex<7;
            if(!workWord2)goto subtract320_73;
            workWord3=Physics16Player4CView1;
            workWord2=1;
            if(workWord3==workWord2)goto subtract320_73;
            add30_70:workWord2=Physics16Player94View1;
            workWord2+=30;
            Physics16Player94View1=workWord2;
            return;
        }
    case 71:{
            register int numeric5 __asm__("$5");
            int lowProduct3Case71,lowProduct4Case71;
            globalFieldA4Pointer=&Physics16PlayerB8View1;
            workWord2=Physics16Field(globalFieldA4Pointer,int*,0);
            if(!workWord2)goto grounded71;
            workWord2=2;
            workWord3=Physics16Player4CView1;
            numeric5=1600;
            if(workWord3==workWord2)numeric5=3200;
            Physics16Call40D10View1(numeric5,numeric5);
            Physics16Call41580View1(22,4);
            Physics16Call417FCView1(320,192);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            globalVector8C=globalFieldA4Pointer-44;
            workWord2=Physics16Call4EA2CView1(Physics16PlayerA4View1);
            __asm__ volatile(""::"r"(globalVector8C):"memory");
            workWord3=Physics16PlayerB0View1;
            lowProduct3Case71=workWord3*workWord2;
            call4=(void*)Physics16PlayerA4View1;
            workWord2=lowProduct3Case71>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp70=workWord2;
            workWord2=Physics16Call4E9E4View1(call4);
            workWord3=Physics16PlayerB0View1;
            lowProduct4Case71=workWord3*workWord2;
            workWord2=lowProduct4Case71>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp74=workWord2;
            Physics16Call4F1C8View1(&originalFrame.sp70, &originalFrame.sp70, globalVector8C);
            originalFrame.sp78 = 0;
            temp_v0_4 = Physics16Call4EDE8View1(&originalFrame.sp70, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer-56;
            if (temp_v0_4 >= 0x141) {
                Physics16Call4F08CView1(&originalFrame.sp70, temp_v0_4, 0x140);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer-56;
            }
            Physics16Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp70);
            Physics16Call41B64View1();
            workWord2=Physics16Player94View1;
            workWord2-=320;
            Physics16Player94View1=workWord2;
            workWord2=workWord2<-12800;
            if(workWord2){
                workWord2=-12800;
                Physics16Player94View1=workWord2;
            }
            return;
        grounded71:
            workWord3=Physics16Data6E044View1;
            workWord2=8;
            if(workWord3!=workWord2)Physics16Call40D10View2(6016);
            globalVector80=&Physics16Data6E538View1;
            workWord2=Physics16Field(globalVector80,int*,0)&12;
            if(workWord2)Physics16PlayerACView1=0;
            workWord2=Physics16Call416F4View1();
            call4=(void*)90;
            call5=(void*)16;
            __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
            globalFieldA4Pointer=(void*)workWord2;
            workWord2=Physics16Call41580View2(call4,call5);
            workWord3=Physics16PlayerA8View1;
            if(workWord3<0)workWord3=-workWord3;
            workWord3=workWord3<8;
            __asm__("":"=r"(workWord3):"0"(workWord3),"r"(workWord2));
            call5=(void*)workWord2;
            if(!workWord3)goto reset71;
            workWord2=Physics16Field(globalVector80,int*,0)&12;
            if(!workWord2)goto reset71;
            workWord2=Physics16Player144View1;
            workWord2++;
            Physics16Player144View1=workWord2;
            goto saved71;
            reset71:Physics16Player144View1=0;
            saved71:call4=&Physics16PlayerACView1;
            globalVector80=(void*)Physics16Field(call4,int*,0);
            if(globalFieldA4Pointer)goto collision71;
            workWord2=(int)call5;
            if((int)call5<0)workWord2=-workWord2;
            workWord2=workWord2<513;
            if(workWord2)goto pass71;
            collision71:workWord2=Physics16Player20CView1&64;
            if(workWord2)Physics16Field(call4,int*,0)=0;
            else{
                workWord3=Physics16PlayerB0View1;
                workWord2=workWord3<(int)globalVector80;
                if(workWord2)Physics16Field(call4,int*,0)=workWord3;
            }
            pass71:Physics16Call417FCView2(320,192);
            workWord2=Physics16Player101View1;
            call4=&Physics16PlayerACView1;
            Physics16Field(call4,int*,0)=(int)globalVector80;
            if(workWord2){
                Physics16Call4F168View1(call4-32);
                goto fields71;
            }
            Physics16Call41848View1(call4);
            Physics16Call41B64View2();
            fields71:call6=&Physics16PlayerFCView1;
            workWord2=Physics16Field(call6,unsigned char*,0);
            if(workWord2)goto block_303;
            workWord2=Physics16PlayerB8View1;
            call4=call6-112;
            if(!workWord2)goto vectorInput71;
            block_303:workWord2=Physics16PlayerA0View1;
            workWord2-=320;
            Physics16Player94View1=workWord2;
            return;
            vectorInput71:__asm__ volatile(""::"i"(0x80083FB0):"memory");
            call5=call4;
            vectorCommit49:Physics16Call4F194View4(call4,call5,call6-20);
            return;
        }
    case 72:{
            int lowProduct3Case72,lowProduct4Case72;
            globalFieldA4Pointer=&Physics16Player4CView1;
            workWord2=Physics16Field(globalFieldA4Pointer,int*,0);
            if(workWord2)goto vector72;
            workWord2=combinedIndex<19;
            call4=globalFieldA4Pointer+64;
            if(workWord2)goto neutralVector72;
            call4=globalFieldA4Pointer+52;
            workWord3=Physics16Player8CView1;
            workWord2=workWord3*7;
            workWord3=Physics16Player90View1;
            workWord2<<=5;
            Physics16Field(globalFieldA4Pointer,int*,52)=workWord2;
            workWord2=workWord3*7;
            workWord3=Physics16Player94View1;
            workWord2<<=5;
            Physics16Player84View1=workWord2;
            workWord2=workWord3*7;
            workWord2<<=5;
            Physics16Player88View1=workWord2;
            Physics16Call4F110View2(call4,8);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            call4=globalFieldA4Pointer+64;
            neutralVector72:Physics16Call4F178View3(call4,globalFieldA4Pointer+52);
            workWord2=Physics16Player94View1;
            workWord2-=192;
            Physics16Player94View1=workWord2;
            workWord2=workWord2<-8960;
            clamp19:if(workWord2){
                workWord2=-8960;
                Physics16Player94View1=workWord2;
            }
            return;
            vector72:Physics16Call40D10View1(3200);
            Physics16Call41580View1(40,8);
            Physics16Call417FCView1(320,192);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            globalVector8C=globalFieldA4Pointer+64;
            workWord2=Physics16Call4EA2CView1(Physics16PlayerA4View1);
            __asm__ volatile(""::"r"(globalVector8C):"memory");
            workWord3=Physics16PlayerB0View1;
            lowProduct3Case72=workWord3*workWord2;
            call4=(void*)Physics16PlayerA4View1;
            workWord2=lowProduct3Case72>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp80=workWord2;
            workWord2=Physics16Call4E9E4View1(call4);
            workWord3=Physics16PlayerB0View1;
            lowProduct4Case72=workWord3*workWord2;
            workWord2=lowProduct4Case72>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp84=workWord2;
            Physics16Call4F1C8View1(&originalFrame.sp80, &originalFrame.sp80, globalVector8C);
            originalFrame.sp88 = 0;
            temp_v0_4 = Physics16Call4EDE8View1(&originalFrame.sp80, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer+52;
            if (temp_v0_4 >= 0x281) {
                Physics16Call4F08CView1(&originalFrame.sp80, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer+52;
            }
            Physics16Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp80);
            Physics16Call41B64View1();
            if(combinedIndex<13){
                __asm__(""::"r"(combinedIndex));
                workWord2=Physics16Player94View1;
                workWord2+=30;
            }
            else{
                workWord2=Physics16Player94View1;
                workWord2-=320;
            }
            Physics16Player94View1=workWord2;
            __asm__ volatile("" ::: "memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer=&Physics16Player0View1+0x148;
                __asm__("" : "=r"(globalPointer):"0"(globalPointer));
                particleIndex=0;
                if (Physics16Field(globalPointer,int*,0) != 0) {
                    workWord2=combinedIndex*4;
                    __asm__("" : "=r"(workWord2):"0"(workWord2));
                    particleThreshold=workWord2+combinedIndex;
                    globalByteE=globalPointer-0x13A;
                    vectorAt40=&originalFrame.spA0;
                    __asm__("" : "=r"(vectorAt40):"0"(vectorAt40));
                spawnParticleLoop72:
                    if (particleThreshold < (Physics16CallRandView1() & 0xFF)) {
                        workWord2=Physics16Call363DCView1(0,0xC);
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
                        signedTableWord = *(short*)(&Physics16Data65920View1 + workWord3);
                        call6=vectorAt40;
                        originalFrame.sp90 = (int) (signedTableWord * 5) >> 0xA;
                        workWord3=*(short*)(&Physics16Data658A0View1 + workWord3);
                        __asm__ volatile("" : "=r"(workWord3):"0"(workWord3):"memory");
                        originalFrame.sp98 = 0xE;
                        originalFrame.spA0 = -0x12C;
                        originalFrame.spA4 = 0;
                        originalFrame.spA8 = -0xC8;
                        __asm__ volatile("" ::: "memory");
                        originalFrame.sp94 = (workWord3 * 5) >> 0xA;
                        Physics16Call4ED6CView1(call4, call5, call6, signedTableWord);
                        originalFrame.spA0 += Physics16Call363DCView1(0, 0x50);
                        originalFrame.spA4 += Physics16Call363DCView1(0, 0x50);
                        originalFrame.spA8 += Physics16Call363DCView1(0, 0x50);
                        Physics16Call4F194View1(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 = Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp90);
                        workWord2=(int)temp_v0_5;
                        workWord3=8;
                        Physics16Field((void*)workWord2,signed char*,2)=workWord3;
                        workWord3=32;
                        Physics16Field((void*)workWord2,signed char*,10)=workWord3;
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
            Physics16Call40D10View1(0x640);
            Physics16Call41580View1(0x28, 8);
            Physics16Call417FCView1(0x140, 0xC0);
            globalFieldA4Pointer = &Physics16Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics16Call4EA2CView1(Physics16Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics16Field(&Physics16Player0View1,int*,0xB0);
            lowProduct3Case73=workWord3*workWord2;
            call4=(void*)Physics16Field(globalFieldA4Pointer,int*,0);
            workWord2=lowProduct3Case73>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp90=workWord2;
            workWord2=Physics16Call4E9E4View1(call4);
            workWord3=Physics16Field(&Physics16Player0View1,int*,0xB0);
            lowProduct4Case73=workWord3*workWord2;
            workWord2=lowProduct4Case73>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp94=workWord2;
            Physics16Call4F1C8View1(&originalFrame.sp90, &originalFrame.sp90, globalVector8C);
            originalFrame.sp98 = 0;
            temp_v0_4 = Physics16Call4EDE8View1(&originalFrame.sp90, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics16Call4F08CView1(&originalFrame.sp90, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics16Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp90);
            Physics16Call41B64View1();
            workWord2=combinedIndex<19;
            if(!workWord2)goto subtract320_73;
            workWord3=Physics16Player4CView1;
            workWord2=1;
            if(workWord3==workWord2)goto subtract320_73;
            workWord2=Physics16Player94View1;
            workWord2+=100;
            Physics16Player94View1=workWord2;
            return;
            subtract320_73:globalPointer=&Physics16Player94View1;
            workWord2=Physics16Field(globalPointer,int*,0);
            workWord2-=320;
            Physics16Field(globalPointer,int*,0)=workWord2;
            return;
        }
    case 74:globalVector80=&Physics16Player0View2+0xB8;
        workWord2=Physics16Field(globalVector80,int*,0);
        if(!workWord2)goto zero105;
        vectorAt30=&originalFrame.spB0;
        Physics16Call4F168View1(vectorAt30);
        call4=vectorAt30;
        call5=vectorAt30;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalVector8CState20=globalVector80-44;
        Physics16Call4F1C8View2(call4,call5,globalVector8CState20);
        originalFrame.spB8=0;
        call5=(void*)Physics16Call4EDE8View2(vectorAt30,0);
        workWord2=(int)call5<65;
        if(!workWord2)Physics16Call4F08CView2(vectorAt30,call5,64);
        originalFrame.spB8=-320;
        globalVector80-=56;
        Physics16Call4F194View2(globalVector80,globalVector8CState20,vectorAt30);
        Physics16Call4F178View1(globalVector8CState20,globalVector80);
        goto clamp74;
        zero105:Physics16Call4F168View1(globalVector80-56);
        Physics16Call4F168View1(globalVector80-44);
        goto clamp74;
        clamp74:globalPointer=&Physics16Player94View1;
        workWord2=Physics16Field(globalPointer,int*,0);
        workWord2=workWord2<-12800;
        if(workWord2){
            workWord2=-12800;
            Physics16Field(globalPointer,int*,0)=workWord2;
        }
        return;
    case 75:case 76:case 77:{
            register int numeric5 __asm__("$5");
            int product75;
            call4=&Physics16Player8CView1;
            __asm__("":"=r"(call4):"0"(call4));
            workWord3=Physics16Field(call4,int*,-64);
            __asm__ volatile(""::"r"(workWord3):"memory");
            numeric5=1;
            __asm__("":"=r"(numeric5):"0"(numeric5));
            Physics16Field(call4,int*,0)=0;
            Physics16Field(call4,int*,4)=0;
            if(workWord3==numeric5)goto descend75;
            workWord2=workWord3<2;
            if(!workWord2)goto larger75;
            if(!workWord3)goto zero75;
            return;
            larger75:workWord2=2;
            if(workWord3==workWord2)goto zeroVelocity75;
            return;
        zero75:
            workWord2=Physics16Player144View1;
            workWord2++;
            Physics16Player144View1=workWord2;
            workWord2=workWord2<42;
            if(workWord2){
                workWord2=Physics16Player94View1;
                workWord2-=32;
                Physics16Player94View1=workWord2;
                return;
            }
            Physics16Field(call4,int*,-64)=numeric5;
            __asm__ volatile("":::"$2","memory");
            Physics16Player54View1=0;
            return;
            descend75:workWord2=Physics16Field(call4,int*,8);
            workWord2-=2048;
            Physics16Field(call4,int*,8)=workWord2;
            workWord2=workWord2<-12800;
            if(workWord2)Physics16Field(call4,int*,8)=-12800;
            workWord2=Physics16PlayerB8View1;
            if(workWord2)return;
            workWord2=Physics16Player54View1;
            workWord2=workWord2<9;
            if(workWord2)return;
            workWord2=Physics16PlayerE4View1;
            workWord2=workWord2<23;
            if(!workWord2)return;
            workWord3=Physics16PlayerD4View1;
            workWord2=Physics16Field(call4,int*,8);
            product75=workWord3*workWord2;
            if(product75>=0)return;
            workWord2=4096;
            particleCall3=Physics42_SpawnParticle;
            __asm__ volatile(""::"r"(particleCall3):"memory");
            Physics16Data6E1D4View1=workWord2;
            workWord2=30;
            Physics16Data6E1D8View1=workWord2;
            workWord2=2;
            Physics16Field(call4,int*,-64)=workWord2;
            Physics16Player54View1=0;
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
            globalPointer=Physics16Data6C654View1;
            __asm__ volatile(""::"r"(globalPointer):"memory");
            workWord2=120;
            Physics16Data6E530View1=workWord2;
            workWord2=15;
            Physics16Data6E52CView1=workWord2;
            call4=(void*)Physics16Field(globalPointer,unsigned char*,20);
            Physics16DataPlaySoundView1(call4,call5,0);
            return;
            zeroVelocity75:Physics16Player94View1=0;
            return;
        }
    }
}
#undef Physics16Field


/* AI generated; not human reviewed. SCUS-94467 USA Rev0 800846D0.
 * Reuses verified11 character/table routes against original16 selectors41..4F.
 * Stack18 vector and source44-14/44-44 offsets are bytes; original selector
 * 80071924&63, stride4, table8006D048+14, entry+4 OR02000000 preserved.
 * Numeric vector progress2/5/6/7 yields341/853/1024/1024 before helpers;
 * unsigned gate accepts2..7. Empty constraints emit no instructions.
 * Every original code/internal jump/owned table word, strict complete TU and
 * all retail hashes required. Units, helpers, cadence, audio/live parity open.
 */
extern Spyro Callback16Player __asm__("D_80070328");
int Callback16Call80037058(int x, int y) __asm__("func_80037058");
void Callback16Call80041930(void) __asm__("func_80041930");
void Callback16Call80041AE8(void) __asm__("func_80041AE8");
void Callback16Call80041C20(void) __asm__("func_80041C20");
void Callback16Call80042A44(void) __asm__("func_80042A44");
void Callback16Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback16Word8006E538 __asm__("D_8006E538");
extern int D_80071924;
extern int** Callback16Table __asm__("D_8006D048+0x14");
int Callback16Call80055E84(Moby*) __asm__("func_80055E84");
void Callback16Call8004ED6C(void*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
void Callback16Call8001BA30(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int Callback16Call80019138(Vector3D*,int,int,int,int,Moby*) __asm__("func_80019138");
int Callback16Call8001830C(Vector3D*,Vector3D*,int,int,Moby*) __asm__("func_8001830C");
void func_level_16_800846D0(void) {
    Vector3D localVector;
    register int computedValue __asm__("$4");

    register int positionDelta __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback16Player.animationState) {
    case 0x41:
        if(func_800438F4()==0)func_80043728();
        Callback16Call80041C20();
        Callback16Player.unk9a=0;
        Callback16Call80042A44();
        goto clearSharedValue;
    default:
        return;
    case 0x44:
    case 0x4A:
        Callback16Call80041C20();
        Callback16Call80042A44();
        goto clearSharedValue;
    case 0x42:
    case 0x45:
        func_800438F4();
        Callback16Call80041C20();
        Callback16Call80042A44();
        Callback16Call80041930();
        goto queryC00;
    case 0x4E:
    case 0x4F:
        Callback16Call80041C20();
        Callback16Call80042A44();
        Callback16Call80041AE8();
        if ((unsigned char) Callback16Player.unk10[4] != 0) {
            computedValue = -Callback16Player.unk9ha[4] - Callback16Call80037058(Callback16Player.position.x, Callback16Player.position.y);
            positionValue = Callback16Player.unk4a - computedValue;
            Callback16Player.unk4[0] = computedValue;
            positionDelta = (int) Callback16Player.union144.a.unk13cc >> 6;
            positionValue -= positionDelta;
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            Callback16Player.position.z=positionValue;
            return;
        }
        break;
    case 0x43:
    case 0x46:
    case 0x49:
        Callback16Call80041C20();
        Callback16Call80042A44();
        Callback16Call80041930();
        if(Callback16Player.unk7a[3].z < 0 && Callback16Player.animationStateFrames >= 4) {
            Callback16Player.unk5=1;
        } else {
            if(Callback16Player.unk5==0 && !(Callback16Word8006E538 & 0x40) && Callback16Player.union144.a.unk13cb==0)
                Callback16Player.unk5=2;
        }
        goto clearSharedValue;
    case 0x47: {
        register int progress __asm__("$4");
        register int value __asm__("$2");
        register int* sourceBase __asm__("$16");
        register int flags __asm__("$17");
        if(Callback16Player.ticksSinceLastSurfaceTouch) {
            Callback16Call80041C20();
            Callback16Call80042A44();
        } else {
            func_800438F4();
            Callback16Call80041C20();
            Callback16Call80042A44();
            Callback16Call80041930();
            Callback16Call80043A38(0xC00);
        }
        progress=Callback16Call80055E84(Callback16Player.critterMobyPtr);
        if(Callback16Player.critterMobyPtr->animationState.id==6 && (unsigned int)(progress-2)<6) {
            if(progress<6)value=(progress<<10)/6;
            else value=0x400;
            localVector.x=value;
            __asm__ volatile("" : : : "memory");
            sourceBase=&Callback16Player.unk4a;
            localVector.y=0;
            localVector.z=0x200-*sourceBase;
            Callback16Call8004ED6C((unsigned char*)sourceBase-0x14,(&localVector),(&localVector));
            {register Vector3D* argument0 __asm__("$4")=(&localVector);
            register Vector3D* argument1 __asm__("$5")=(&localVector);
            __asm__("" : "=r"(argument0), "=r"(argument1) : "0"(argument0), "1"(argument1));
            sourceBase=(int*)((unsigned char*)sourceBase-0x44);
            func_8004F194(argument0,argument1,(Vector3D*)sourceBase);}
            flags=0x02000000;
            Callback16Call8001BA30((&localVector),0x200,0,0,flags,Callback16Player.critterMobyPtr);
            if((Callback16Call80019138((&localVector),0x200,0,0,flags,Callback16Player.critterMobyPtr)!=0 ||
                Callback16Call8001830C((Vector3D*)sourceBase,(&localVector),0,0x02000000,Callback16Player.critterMobyPtr)!=0)) {
                register int* selector __asm__("$16")=&D_80071924;
                if(func_80040954(*selector)==3) {
                    register int index __asm__("$2")=*selector;
                    register int** table __asm__("$3")=Callback16Table;
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
        Callback16Call80041C20();
        Callback16Call80042A44();
        if(Callback16Player.unk5==1)func_800494A8();
        goto clearSharedValue;
    case 0x48:
        Callback16Call80041C20();
        Callback16Call80042A44();
        if(Callback16Player.unk5!=0)goto call41930;
queryC00:
        Callback16Call80043A38(0xC00);
        goto clearSharedValue;
call41930:
        Callback16Call80041930();
clearSharedValue:
        Callback16Player.unk4[0]=0;
        return;
    }
}



#define LEVEL_ID 16
#define PlaySpyroSounds_level_16 func_level_16_80084B04
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_16_80084B0C(int index) {
    register Vector3D* position __asm__("$4");
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x43: case 0x44: case 0x46: case 0x49: case 0x4B: case 0x4C: case 0x4D:
        __asm__("" : : : "memory");
        position = 0;
        break;
    case 0x47: case 0x48:
        position = (Vector3D*)((char*)&spyro + 0xB8);
        __asm__("" : "=r"(position) : "0"(position));
        if (position->x) { position = 0; break; }
    case 0x41: case 0x42: case 0x45: case 0x4A: case 0x4E: case 0x4F:
        position = &g_Spyro.unk9e;
        break;
    default: return;
    }
    func_80043ABC(position);
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80084B9C.
 * Original16 character selectors41..4F; verified32 surface and signed-table
 * load lifetimes. Original player vectors8C/98, private250->0/4C, damage bit8,
 * signed table values>>1, surface stack20 and jump stack10 preserved.
 * Headbash movement is numeric0F; original44/49 condition and reload retained.
 * Numeric offsets are bytes. Signed table vectors -2/0/2 give -1/0/1.
 * Each call follows original instruction order; require every code/internal J,
 * owned table/pad, strict complete TU and all original hashes. Helper meanings,
 * physical units, audio semantics, caller cadence and live parity remain open.
 */
void Transition16_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");
void Transition16_func_8004F168(Vector3D*) __asm__("func_8004F168");
void Transition16_func_80043A38(int) __asm__("func_80043A38");
void Transition16_func_800441F0(void) __asm__("func_800441F0");
extern int Raw16Word __asm__("D_80070328+0x50");
extern int Raw16X __asm__("D_80070328+0x8C");
extern unsigned char Raw16Movement[] __asm__("D_80070328+0x50");
extern unsigned char Raw16Union[] __asm__("D_80070328+0x144");
extern int Raw16Animation __asm__("D_80070328+0x48");
extern short D_80065920[];
extern short D_800658A0[];
extern Spyro Transition16_D_80070328 __asm__("D_80070328");
int Transition16_func_8004EDE8(Vector3D*,int) __asm__("func_8004EDE8");
int Call16A358(Vector3D*,int) __asm__("func_8001A358");
extern int Transition16_D_8006E524 __asm__("D_8006E524");
extern int D_80071934;
void func_level_16_80084B9C(int arg0) {
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

    switch (arg0) {
    case 0x41:
        Transition16_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition16_func_800441F0();
        Transition16_D_80070328.grounded = 1;
        return;
    case 0x42:
    case 0x45:
        Transition16_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition16_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition16_D_80070328.movementState) + 0x3C)), (Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition16_D_80070328.movementState) + 0x48)));
            Transition16_D_80070328.unk5 = MOVEMENT_STATE_WALK;
        } else {
            Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        }
        Transition16_D_80070328.unk8[0] = Transition16_func_8004EDE8(&Transition16_D_80070328.unk7a[3], 0);
        Transition16_func_80043A38(0xC00);
        Transition16_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition16_D_80070328.grounded = 1;
        goto clearFlags;
    case 0x43:
    case 0x49:
        initialMovement=Raw16Movement;
        __asm__("" : "=r"(initialMovement) : "0"(initialMovement));
        comparisonKind=10;
        __asm__("" : "=r"(comparisonKind) : "0"(comparisonKind));
        {register Moby* critter __asm__("$3")=Transition16_D_80070328.critterMobyPtr;
        register int current __asm__("$4")=*(int*)initialMovement;
        __asm__("" : "=r"(critter),"=r"(current) : "0"(critter),"1"(current));
        jumpPrivate=critter->mobyTag;
        __asm__("" : "=r"(jumpPrivate) : "0"(jumpPrivate));
        if ((current == comparisonKind) && (SpawnParticle != 0) && (Transition16_D_80070328.unk4[0] < 0)) {
            func_8004F178(&vectors.first, (Vector3D*)(initialMovement-0x50));
            vectors.first.z = -Transition16_D_80070328.unk4[0];
            SpawnParticle(6, 0x2E, &vectors.first, 0);
            SpawnParticle(4, 0x29, &vectors.first, 0);
        }
        }
        movement=Raw16Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        firstJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) firstJumpSource);
        Transition16_D_80070328.unk8[0] = Transition16_func_8004EDE8((Vector3D *) firstJumpSource, 0);
        if (arg0 == 0x49) {
            Transition16_D_80070328.unk7a[2].z = 0x2580;
        } else {
            Transition16_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)jumpPrivate+0x4C) = 0;
        }
        Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition16_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition16_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
        goto playJumpSound;
    case 0x44:
        Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        if (Transition16_D_80070328.movementState == MOVEMENT_STATE_JUMP_HOVER) {
            if(Transition16_D_80070328.animationState==0x43)Transition16_D_80070328.unk5=1;
            else if(Transition16_D_80070328.animationState==0x46)Transition16_D_80070328.unk5=Transition16_D_80070328.movementState;
            else if(Transition16_D_80070328.animationState==0x49)Transition16_D_80070328.unk5=4;
        } else {
            Transition16_D_80070328.movementState = MOVEMENT_STATE_FALL;
        }
        Transition16_D_80070328.unk8[0] = Transition16_func_8004EDE8(&Transition16_D_80070328.unk7a[3], 0);
        Transition16_D_80070328.grounded = 0;
        goto clearFlags;
    case 0x46:
        movement=Raw16Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        secondJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) secondJumpSource);
        Transition16_D_80070328.unk8[0] = Transition16_func_8004EDE8((Vector3D *) secondJumpSource, 0);
        Transition16_D_80070328.unk7a[2].z = 0x12C0;
        Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition16_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition16_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
playJumpSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
        return;
    case 0x47:
        if (Transition16_D_80070328.ticksSinceLastSurfaceTouch != 0) {
            if (Transition16_D_80070328.movementState != MOVEMENT_STATE_FALL) {
                if (Transition16_D_80070328.animationState == 0x43) {
                    Transition16_D_80070328.unk5 = MOVEMENT_STATE_WALK;
                } else if (Transition16_D_80070328.animationState == 0x46) {
                    Transition16_D_80070328.unk5 = MOVEMENT_STATE_JUMP_HOVER;
                } else {
                    Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
                }
            }
            Transition16_D_80070328.movementState = MOVEMENT_STATE_FALL;
            Transition16_D_80070328.grounded = 0;
            Transition16_D_80070328.idle = 0;
            Transition16_D_80070328.unk15g = 0;
        } else {
            Transition16_D_80070328.movementState = MOVEMENT_STATE_WALK;
            Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            Transition16_func_80043A38(0xC00);
            Transition16_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition16_D_80070328.grounded = 1;
        }
        Transition16_D_80070328.unk8[0] = Transition16_func_8004EDE8(&Transition16_D_80070328.unk7a[3], 0);
        goto clearFlags;
clearFlags:
        Transition16_D_80070328.idle = 0;
        Transition16_D_80070328.unk15g = 0;
        return;
    case 0x4E:case 0x4F: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Raw16Word;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Raw16Union;
            *(int*)unionPointer=(-Transition16_D_80070328.unk7a[2].z)>>2;
            if(Raw16Word!=8){Transition16_D_80070328.union144.a.unk13cc=0x5900;Raw16Word=10;}
            Transition16_D_80070328.unk5=0;
            Transition16_D_80070328.unk8[0]=Transition16_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition16_D_80070328.grounded=1;
            Transition16_D_80070328.unk15b=1;
            localVector=&vectors.second;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.second.z+=0x400;
            lengthResult=Call16A358(localVector,0x800);
            vectors.second.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        return;
    }
    case 0x48: {
        register Moby* critter __asm__("$2")=Transition16_D_80070328.critterMobyPtr;
        __asm__ volatile("" : "=r"(critter) : "0"(critter) : "memory");
        damagePrivate=critter->mobyTag;
        __asm__ volatile("" : "=r"(damagePrivate) : "0"(damagePrivate) : "memory");
        previousValue=Raw16Word;
        __asm__ volatile("" : "=r"(previousValue) : "0"(previousValue) : "memory");
        unionBase=Raw16Union;
        __asm__("" : "=r"(previousValue),"=r"(unionBase) : "0"(previousValue),"1"(unionBase));
        *(int*)unionBase=previousValue;
        Raw16Word = MOVEMENT_STATE_HURT;
        if (Transition16_D_80070328.damageFlags & 8) {
            damageSource = (Vector3D *) (unionBase - 0xAC);
            Transition16_D_80070328.unk5 = MOVEMENT_STATE_WALK;
            func_8004F178((Vector3D *) (unionBase - 0xB8), damageSource);
            Transition16_D_80070328.unk8[0] = Transition16_func_8004EDE8(damageSource, 0);
            soundTable=(unsigned char*)D_8006C654;
            soundZero=0;
            __asm__ volatile("" : "=r"(soundTable),"=r"(soundZero) : "0"(soundTable),"1"(soundZero) : "memory");
            Transition16_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)damagePrivate+0x4C) = 0;
            Transition16_D_80070328.grounded = 0;
            Transition16_D_80070328.union144.a.unk13cc = 1;
            PlaySound(soundTable[12],(Moby*)soundZero,0);
        } else {
            Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            damageDestination = (Vector3D *) (unionBase - 0xB8);
            if (Transition16_D_80070328.unk17a & 0x400) {
                func_8004F178(damageDestination, (Vector3D *) ((Vector3D *) (unionBase + 0xD8)));
                Transition16_func_8004F0E8(damageDestination, 6);
            } else if (Transition16_D_80070328.unk22[5] >= 0) {
                tableIndex=Transition16_D_80070328.unk22[5]*2;
                tableValue=*(short*)((unsigned char*)D_80065920+tableIndex);
                __asm__("" : "=r"(tableValue) : "0"(tableValue));
                Raw16X=tableValue>>1;
                tableIndex=*(short*)((unsigned char*)D_800658A0+tableIndex);
                Transition16_D_80070328.unk7a[2].z=0;
                __asm__ volatile("" : "=r"(tableIndex) : "0"(tableIndex) : "memory");
                Transition16_D_80070328.unk7a[2].y=tableIndex>>1;
            } else {
                    __asm__("" : "=r"(unionBase) : "0"(unionBase));
                Transition16_func_8004F168((Vector3D*)(unionBase-0xB8));
            }
            func_8004F178(&Transition16_D_80070328.unk7a[1], (Vector3D *) ((unsigned char*)(&Transition16_D_80070328.unk7a[1]) + 0xC));
            Transition16_func_80043A38(0xC00);
            Transition16_D_80070328.grounded = 1;
        }
        Transition16_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
        break;
    }
    case 0x4A:
        Transition16_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition16_func_80043A38(0xC00);
        Transition16_D_80070328.grounded = 1;
        Transition16_D_8006E524 = 0xF;
        return;
    case 0x4B:
        firstAnimation=Raw16Animation;
        __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        if(firstAnimation==0x44){
            if(Transition16_D_80070328.unk5==4)goto setHeadbashFlag;
            comparisonKind=0x49;
            __asm__ volatile("" : "=r"(comparisonKind) : "0"(comparisonKind) : "memory");
            firstAnimation=Raw16Animation;
            __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        }else comparisonKind=0x49;
        if(firstAnimation==comparisonKind){
setHeadbashFlag:
            Transition16_D_80070328.union144.a.unk13cc=1;
        }else Transition16_D_80070328.union144.a.unk13cc=0;
        Transition16_D_80070328.movementState = MOVEMENT_STATE_HEADBASH;
        Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition16_func_8004F168((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition16_D_80070328.movementState) + 0x3C)));
        Transition16_D_80070328.unk7a[2].z = 0x800;
        Transition16_D_80070328.grounded = 0;
        Transition16_D_80070328.unk13a[0] = 0x20000;
        Transition16_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        return;
    case 0x4C:
        Transition16_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=1;
        goto setHeadbashSubstate;
    case 0x4D:
        Transition16_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=2;
setHeadbashSubstate:
        Transition16_D_80070328.unk5=nextSubstate;
        Transition16_D_80070328.grounded=0;
        Transition16_D_80070328.unk13a[0]=0x20000;
        return;
    }
}


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original800853D4.
 * Assembly SHA256 911d2188205deb322c6efda94a64cbaa5bc37a544ed9c1ddce4a80bfd96c91e1.
 * AI-generated; not human reviewed. All931 original instructions and15
 * selectors bias65 are required. Original frame18 retains savedS0/RA. All14 physical state groups reuse verified source cases with
 * exact original stack/address maps. Original74 uses selector bias65; last79 includes the five original
 * epilogue rows. All callbacks,input/effect/sound selectors,counters,fields
 * and actual internal/conditional targets remain original. Distinct66/76
 * timer guards and79 byte/selector producers retain original ordering.
 * Typed aliases stay distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit words.
 * Units/fixed point,helper contracts,caller rate and synchronized runtime
 * completeness remain open; cadence is per invocation.
 * Falsification: every native/linked word,actual target,selector/data and
 * full EXE/every overlay hash. Binary identity is the only parity claim. */
extern int Anim16Player48View1 __asm__("D_80070328 + 0x48");
extern unsigned char* Anim16Player250View1 __asm__("D_80070328 + 0x250");
void Anim16Call498C0View1(void) __asm__("func_800498C0");
int Anim16Call4BEF8View1() __asm__("func_8004BEF8");
extern int Anim16Data6E044View1 __asm__("D_8006E044"),A21Gate __asm__("D_8006E344"),A21Count __asm__("D_8006C514");
extern unsigned char Anim16Player100View1 __asm__("D_80070328 + 0x100");
extern int Anim16Player44View1 __asm__("D_80070328 + 0x44");
extern int Anim16Player48View2 __asm__("D_80070328 + 0x48");
extern int Anim16Player4CView1 __asm__("D_80070328 + 0x4C");
extern int Anim16Player50View1 __asm__("D_80070328 + 0x50");
extern int Anim16Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim16Player58View1 __asm__("D_80070328 + 0x58");
extern int Anim16Player8CView1 __asm__("D_80070328 + 0x8C");
extern int Anim16Player90View1 __asm__("D_80070328 + 0x90");
extern int Anim16Player94View1 __asm__("D_80070328 + 0x94");
extern int Anim16PlayerA8View1 __asm__("D_80070328 + 0xA8");
extern int Anim16PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim16PlayerB0View1 __asm__("D_80070328 + 0xB0");
extern int Anim16PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim16PlayerCCView1 __asm__("D_80070328 + 0xCC");
extern int Anim16PlayerD0View1 __asm__("D_80070328 + 0xD0");
extern int Anim16PlayerD4View1 __asm__("D_80070328 + 0xD4");
extern int Anim16PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern int Anim16Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim16Player280View1 __asm__("D_80070328 + 0x280");
extern unsigned char Anim16Player0View1[] __asm__("D_80070328");
extern unsigned char *Anim16Player250View2 __asm__("D_80070328 + 0x250");
extern unsigned char Anim16Player1B6View1 __asm__("D_80070328 + 0x1B6");
extern unsigned char Anim16Data6E535View1 __asm__("D_8006E535");
extern int Anim16Data6E538View1 __asm__("D_8006E538");
extern int Anim16Data6E53CView1 __asm__("D_8006E53C");
extern int Anim16Data6E530View1 __asm__("D_8006E530");
extern int Anim16Data6E52CView1 __asm__("D_8006E52C");
extern unsigned char *Anim16Data6C654View1 __asm__("D_8006C654");
extern int (*Anim16Data7431CView1)(int) __asm__("unk_ovlheader_8007431C");
extern int (*Anim16DataSpawnParticleView1)(int,int,void*,int) __asm__("SpawnParticle");
int Anim16Call55E84View1(void*) __asm__("func_80055E84");
int Anim16Call1A358View1(void*,int) __asm__("func_8001A358");
int Anim16Call4BEF8View2(int) __asm__("func_8004BEF8");
int Anim16CallPlaySoundView1(unsigned char,int,int) __asm__("PlaySound");
#define Anim16Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
#define Anim16Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
void func_level_16_800853D4(void){
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int nextSelector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* record16 __asm__("$16");
    register unsigned char* object4 __asm__("$4");
    register int (*callback3)(int) __asm__("$3");
    rawValue2=Anim16Player48View1;
    switch(rawValue2){
    case 65:
        rawValue2=Anim16Data7431CView1(9);
        if(rawValue2)return;
        rawValue3=Anim16Data6E53CView1;
        rawValue2=rawValue3&64;
        if(rawValue2){
            rawValue2=(int)Anim16Player250View2;
            rawValue2=(int)Anim16Field((void*)rawValue2,void**,0);
            rawValue2=Anim16Field((void*)rawValue2,int*,0x48);
            rawValue2=rawValue2<8;
            nextSelector4=67;
            if(!rawValue2)goto select;
            __asm__ volatile(""::"i"(0x8008546C):"memory");
            nextSelector4=73;
            goto select;
        }
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=Anim16PlayerB8View1<4;
        nextSelector4=68;
        if(!rawValue2)goto select;
        rawValue2=Anim16PlayerE4View1<23;
        if(!rawValue2)goto select;
        rawValue2=Anim16PlayerA8View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<17;
        nextSelector4=66;
        if(!rawValue2)goto select;
        rawValue2=Anim16Data6E538View1&12;
        if(rawValue2)return;
        rawValue2=Anim16PlayerACView1;
        if(!rawValue2)return;
        goto select;
    case 66:
        rawValue2=Anim16Data7431CView1(9);
        if(rawValue2)return;
        rawValue3=Anim16Data6E53CView1;
        rawValue2=rawValue3&64;
        if(rawValue2){
            rawValue2=(int)Anim16Player250View2;
            rawValue2=(int)Anim16Field((void*)rawValue2,void**,0);
            rawValue2=Anim16Field((void*)rawValue2,int*,0x48);
            rawValue2=rawValue2<8;
            nextSelector4=67;
            if(!rawValue2)goto select;
            __asm__ volatile(""::"i"(0x80085560):"memory");
            nextSelector4=73;
            goto select;
        }
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=Anim16PlayerB8View1<4;
        nextSelector4=68;
        if(!rawValue2)goto select;
        rawValue2=Anim16PlayerE4View1<23;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim16Player250View2;
        rawValue2=Anim16Player48View2;
        rawValue3=Anim16Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)goto query66;
        rawValue2=Anim16Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(rawValue2)goto input66;
    query66:
        rawValue2=Anim16Call55E84View1((void*)nextSelector4);
        rawValue2=rawValue2<4;
        if(!rawValue2)return;
    input66:
        rawValue2=Anim16Data6E535View1;
        if(!rawValue2)goto held66;
        rawValue2=Anim16PlayerB0View1;
        nextSelector4=65;
        if(!rawValue2)goto select;
    held66:
        rawValue2=Anim16Data6E538View1&12;
        if(!rawValue2)return;
        rawValue2=Anim16Player144View1<16;
        nextSelector4=65;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x80085640):"memory");
        goto select;
    case 67:
        rawValue2=Anim16Data7431CView1(9);
        if(rawValue2)return;
        rawValue2=Anim16Player54View1<16;
        if(!rawValue2){
            rawValue2=Anim16Data6E53CView1&64;
            nextSelector4=70;
            if(rawValue2)goto select;
        }
        rawValue3=Anim16Data6E53CView1;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            product5=Anim16Player44View1;
            nextSelector4=(int)Anim16Player0View1;
            rawValue2=Anim16Call1A358View1((void*)nextSelector4,product5+512);
            nextSelector4=75;
            if(!rawValue2)goto select;
        }
        rawValue2=Anim16PlayerB8View1;
        if(rawValue2)goto finish67;
        rawValue2=Anim16Player54View1<16;
        if(rawValue2)goto finish67;
        rawValue2=Anim16PlayerE4View1<23;
        if(!rawValue2)return;
        rawValue3=Anim16PlayerCCView1;
        rawValue2=Anim16Player8CView1;
        product5=rawValue3*rawValue2;
        rawValue3=Anim16PlayerD0View1;
        rawValue2=Anim16Player90View1;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim16PlayerD4View1;
        rawValue2=Anim16Player94View1;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)return;
        rawValue2=Anim16PlayerACView1;
        nextSelector4=66;
        if(rawValue2)goto select;
        __asm__ volatile(""::"i"(0x80085794):"memory");
        nextSelector4=65;
        goto select;
    finish67:
        nextSelector4=(int)Anim16Player250View2;
        rawValue2=Anim16Player48View2;
        rawValue3=Anim16Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim16Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=68;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x800857D0):"memory");
        goto select;
    case 68:
        rawValue2=(int)Anim16Player250View2;
        callback3=Anim16Data7431CView1;
        record16=Anim16Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(9);
        if(rawValue2)return;
        rawValue2=Anim16Data6E53CView1&64;
        if(rawValue2){
            rawValue2=1;
            nextSelector4=(int)&Anim16Player4CView1;
            rawValue3=*(int*)nextSelector4;
            __asm__("":"=r"(rawValue2):"0"(rawValue2));
            if(rawValue3==rawValue2){
                rawValue2=Anim16Player54View1<31;
                nextSelector4-=76;
                if(rawValue2){
                    rawValue2=Anim16Call1A358View1((void*)nextSelector4,1024);
                    if(!rawValue2){
                        nextSelector4=70;
                        goto select;
                    }
                }
            }
            rawValue2=1;
            Anim16Player1B6View1=rawValue2;
            Anim16Field(record16,int*,0x48)=0;
        }
        rawValue3=Anim16Data6E53CView1;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            nextSelector4=(int)&Anim16Player4CView1;
            rawValue2=*(int*)nextSelector4;
            nextSelector4-=76;
            if(rawValue2){
                product5=Anim16Player44View1;
                rawValue2=Anim16Call1A358View1((void*)nextSelector4,product5+512);
                nextSelector4=75;
                if(!rawValue2)goto select;
            }
        }
        rawValue2=Anim16PlayerB8View1;
        if(rawValue2)return;
        rawValue2=Anim16PlayerE4View1<23;
        if(!rawValue2)return;
        rawValue2=Anim16Player1B6View1;
        if(rawValue2){
            rawValue2=Anim16Field(record16,int*,0x48)<7;
            if(rawValue2){
                rawValue2=2;
                rawValue3=Anim16Player50View1;
                nextSelector4=67;
                if(rawValue3!=rawValue2)goto effectSelect;
                nextSelector4=73;
                goto effectSelect;
            }
        }
        rawValue3=Anim16Player50View1;
        rawValue2=2;
        if(rawValue3==rawValue2){
            Anim16Field(record16,int*,0x48)=0;
        }
        else{
            rawValue2=255;
            Anim16Field(record16,int*,0x48)=rawValue2;
        }
        rawValue2=Anim16PlayerACView1;
        nextSelector4=66;
        if(rawValue2)goto effectSelect;
        nextSelector4=69;
        goto effectSelect;
    case 69:
        rawValue2=Anim16Data7431CView1(9);
        if(rawValue2)return;
        rawValue3=Anim16Data6E53CView1;
        rawValue2=rawValue3&64;
        if(rawValue2){
            rawValue2=(int)Anim16Player250View2;
            rawValue2=(int)Anim16Field((void*)rawValue2,void**,0);
            rawValue2=Anim16Field((void*)rawValue2,int*,0x48);
            rawValue2=rawValue2<8;
            nextSelector4=67;
            if(!rawValue2)goto select;
            __asm__ volatile(""::"i"(0x800859C8):"memory");
            nextSelector4=73;
            goto select;
        }
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=Anim16PlayerB8View1<4;
        nextSelector4=68;
        if(!rawValue2)goto select;
        rawValue2=Anim16PlayerE4View1<23;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim16Player250View2;
        rawValue2=Anim16Player48View2;
        rawValue3=Anim16Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)goto query69;
        rawValue2=Anim16Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(rawValue2)goto input69;
    query69:
        rawValue2=Anim16Call55E84View1((void*)nextSelector4);
        rawValue2=rawValue2<4;
        if(!rawValue2)return;
    input69:
        rawValue2=Anim16Data6E535View1;
        if(!rawValue2)goto held69;
        rawValue2=Anim16PlayerB0View1;
        if(!rawValue2){
            __asm__ volatile(""::"i"(0x80085A78):"memory");
            nextSelector4=65;
            goto select;
        }
    held69:
        rawValue2=Anim16Data6E538View1&12;
        nextSelector4=66;
        if(!rawValue2)goto select;
        rawValue2=Anim16Player144View1<16;
        if(rawValue2)goto select;
        __asm__ volatile(""::"i"(0x80085AB0):"memory");
        nextSelector4=65;
        goto select;
    case 70:case 73:
        rawValue2=Anim16Data7431CView1(9);
        if(rawValue2)return;
        rawValue3=Anim16Data6E53CView1;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            product5=Anim16Player44View1;
            nextSelector4=(int)Anim16Player0View1;
            rawValue2=Anim16Call1A358View1((void*)nextSelector4,product5+512);
            nextSelector4=75;
            if(!rawValue2)goto select;
        }
        rawValue2=Anim16PlayerB8View1;
        if(rawValue2)goto finish70;
        rawValue2=Anim16Player54View1<16;
        if(rawValue2)goto finish70;
        rawValue2=Anim16PlayerE4View1<23;
        if(!rawValue2)return;
        rawValue3=Anim16PlayerCCView1;
        rawValue2=Anim16Player8CView1;
        product5=rawValue3*rawValue2;
        rawValue3=Anim16PlayerD0View1;
        rawValue2=Anim16Player90View1;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim16PlayerD4View1;
        rawValue2=Anim16Player94View1;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)return;
        rawValue2=Anim16PlayerACView1;
        nextSelector4=66;
        if(rawValue2)goto select;
        __asm__ volatile(""::"i"(0x80085BD4):"memory");
        nextSelector4=65;
        goto select;
    finish70:
        nextSelector4=(int)Anim16Player250View2;
        rawValue2=Anim16Player48View2;
        rawValue3=Anim16Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim16Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=68;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x80085C10):"memory");
        goto select;
    case 71:
        rawValue2=Anim16Data7431CView1(9);
        if(rawValue2)return;
        rawValue2=3;
        rawValue3=Anim16Player50View1;
        if(rawValue3!=rawValue2)goto other71;
        rawValue2=Anim16PlayerB8View1;
        if(rawValue2)goto finish71;
        rawValue2=Anim16PlayerE4View1<23;
        nextSelector4=71;
        if(!rawValue2)return;
    effectSelect:
        Anim16Call4BEF8View2(nextSelector4);
        {
            register int (*spawn2)(int,int,void*,int) __asm__("$2")=Anim16DataSpawnParticleView1;
            if(spawn2)spawn2(8,33,0,2);
        }
        rawValue2=(int)Anim16Data6C654View1;
        product5=0;
        nextSelector4=Anim16Field((void*)rawValue2,unsigned char*,0x12);
        Anim16CallPlaySoundView1((unsigned char)nextSelector4,product5,0);
        rawValue2=Anim16Player58View1<24;
        if(rawValue2)return;
        rawValue2=120;
        Anim16Data6E530View1=rawValue2;
        rawValue2=15;
        Anim16Data6E52CView1=rawValue2;
        return;
    finish71:
        nextSelector4=(int)Anim16Player250View2;
        rawValue2=Anim16Player48View2;
        rawValue3=Anim16Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim16Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=68;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x80085D20):"memory");
        goto select;
    other71:
        rawValue2=Anim16PlayerB8View1<4;
        nextSelector4=71;
        if(!rawValue2)goto select;
        rawValue2=Anim16PlayerE4View1<23;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim16Player250View2;
        rawValue2=Anim16Player48View2;
        rawValue3=Anim16Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)goto query71;
        rawValue2=Anim16Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)goto query71;
        rawValue2=Anim16Data6E535View1;
        nextSelector4=66;
        if(!rawValue2)goto select;
        __asm__ volatile(""::"i"(0x80085DA0):"memory");
        nextSelector4=65;
        goto select;
    query71:
        rawValue2=Anim16Call55E84View1((void*)nextSelector4);
        rawValue2=rawValue2<16;
        if(rawValue2)return;
        rawValue2=Anim16Data6E535View1;
        nextSelector4=66;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x80085DD0):"memory");
        goto select;
    case 72:
        rawValue2=Anim16Player4CView1;
        if(!rawValue2)goto finish72;
        rawValue2=Anim16Player280View1;
        if(rawValue2<0)goto finish72;
        rawValue2=Anim16Player54View1<16;
        if(!rawValue2){
            rawValue2=Anim16Data6E53CView1&64;
            nextSelector4=70;
            if(rawValue2)goto select;
        }
        rawValue3=Anim16Data6E53CView1;
        rawValue2=rawValue3&160;
        nextSelector4=71;
        if(rawValue2)goto select;
        rawValue2=rawValue3&16;
        if(rawValue2){
            product5=Anim16Player44View1;
            nextSelector4=(int)Anim16Player0View1;
            rawValue2=Anim16Call1A358View1((void*)nextSelector4,product5+512);
            nextSelector4=75;
            if(!rawValue2)goto select;
        }
        rawValue2=Anim16PlayerB8View1;
        if(rawValue2)goto finish72;
        rawValue2=Anim16Player54View1<16;
        if(rawValue2)goto finish72;
        rawValue2=Anim16PlayerE4View1<23;
        if(!rawValue2)goto finish72;
        rawValue3=Anim16PlayerCCView1;
        rawValue2=Anim16Player8CView1;
        product5=rawValue3*rawValue2;
        rawValue3=Anim16PlayerD0View1;
        rawValue2=Anim16Player90View1;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim16PlayerD4View1;
        rawValue2=Anim16Player94View1;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)goto finish72;
        rawValue2=Anim16PlayerACView1;
        nextSelector4=66;
        if(rawValue2)goto select;
        __asm__ volatile(""::"i"(0x80085F30):"memory");
        nextSelector4=65;
        goto select;
    finish72:
        nextSelector4=(int)Anim16Player250View2;
        rawValue2=Anim16Player48View2;
        rawValue3=Anim16Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim16Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        rawValue2=Anim16Player280View1;
        if(rawValue2<0){
            nextSelector4=74;
            goto select;
        }
        rawValue2=10;
        rawValue3=Anim16Player144View1;
        if(rawValue3==rawValue2){
            __asm__ volatile(""::"i"(0x80085F9C):"memory");
            nextSelector4=79;
            goto select;
        }
        rawValue2=Anim16PlayerB8View1;
        nextSelector4=65;
        if(!rawValue2)goto select;
        __asm__ volatile(""::"i"(0x80085FB8):"memory");
        nextSelector4=68;
        goto select;
    case 74:
        object4 = Anim16Player250View1;
        rawValue2 = Anim16Player48View1;
        rawValue3 = Anim16Field(object4, unsigned char*, 0x3C);
        rawValue2 -= 65;
        if (rawValue3 != rawValue2) return;
        rawValue2 = Anim16Field(object4, unsigned char*, 0x42) & 2;
        if (!rawValue2) return;
        Anim16Call498C0View1();
        return;
    case 75:
        rawValue2=Anim16Data7431CView1(9);
        if(rawValue2)return;
        rawValue2=2;
        rawValue3=Anim16Player4CView1;
        nextSelector4=77;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim16Player54View1<61;
        nextSelector4=68;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim16Player250View2;
        rawValue2=Anim16Player48View2;
        rawValue3=Anim16Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim16Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=76;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x80086080):"memory");
        goto select;
    case 76:
        rawValue2=Anim16Data7431CView1(9);
        if(rawValue2)return;
        rawValue2=2;
        rawValue3=Anim16Player4CView1;
        nextSelector4=77;
        if(rawValue3==rawValue2)goto select;
        rawValue2=Anim16Player54View1<61;
        nextSelector4=68;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x800860D0):"memory");
        goto select;
    case 77:
        rawValue2=Anim16Data7431CView1(9);
        if(rawValue2)return;
        nextSelector4=(int)Anim16Player250View2;
        rawValue2=Anim16Player48View2;
        rawValue3=Anim16Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=65;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim16Field((void*)nextSelector4,unsigned char*,0x42)&2;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=65;
        if(!rawValue2)return;
        goto select;
    case 78:
        rawValue2=Anim16Data7431CView1(9);
        if(rawValue2)return;
        rawValue2=Anim16Data6E53CView1&64;
        if(rawValue2){
            rawValue2=Anim16Player54View1<9;
            nextSelector4=67;
            if(!rawValue2)goto partial78;
        }
        rawValue2=Anim16Player100View1;
        nextSelector4=68;
        if(rawValue2)goto after78;
        partial78:Anim16Call4BEF8View2(nextSelector4);
        after78:rawValue2=Anim16Data6E535View1;
        nextSelector4=79;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x800861AC):"memory");
        goto select;
    case 79:
        rawValue2=Anim16Data7431CView1(9);
        if(rawValue2)return;
        if((Anim16Data6E53CView1&64) && Anim16Player54View1>=9){
            nextSelector4=67;
            goto select;
        }
        rawValue2=Anim16Player100View1;
        if(!rawValue2){
            nextSelector4=68;
            goto select;
        }
        rawValue2=7;
        rawValue3=Anim16Data6E044View1;
        if(rawValue3==rawValue2)return;
        rawValue2=Anim16Data6E535View1;
        __asm__ volatile("":"=r"(rawValue2):"0"(rawValue2):"$4","memory");
        nextSelector4=78;
        if(rawValue2)return;
        goto select;
        default:return;
    }
    select:Anim16Call4BEF8View1(nextSelector4);
    return;
}
#undef Anim16Field
