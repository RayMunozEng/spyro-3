#include "common.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008C864.
 * Assembly SHA256 1ff93a5bdcf043463c8fe9d185c0df89d3718ce9d7ebaef233a58a99eefe6c5b.
 * AI-generated; not human reviewed. All890 original instructions,
 * 138 selectors bias10 and 0 owned padding words are required.
 * Original frame0xD0; every concrete field width and producer is retained.
 * Six verified donor groups retain their original widths, stack maps and
 * helper aliases. Five original unique groups135..147 preserve the full
 * copied-vector clamp, wrapped multiply3200 then signed shift7, axial
 * selection and sign branches, selector142..145 fallback decision tree,
 * heading updates and original matrix/vector consumers. Short-circuit
 * orientation guards retain both compiler-generated SP argument delay slots.
 * Independent135/136/147 flag tails retain original addresses and share only
 * the actual1B9 store. The original8004ED6C call has an explicit linker alias.
 * All values entering joins are initialized; every metadata template is empty.
 * Repeated identical declarations are removed; distinct typed aliases stay
 * distinct. Initialized empty constraints and original address metadata emit
 * zero CPU instructions; frozen C tools emit words. Units/fixed point,helper
 * contracts and caller rate remain unresolved; cadence is per invocation.
 * Falsification: every native/linked instruction,actual internal/conditional
 * target,selector/data and full EXE/every-overlay retail hashes. Binary identity
 * does not establish synchronized runtime or system completeness. */
#define Physics31Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Physics31Call363DCView1() __asm__("func_800363DC");
unsigned char Physics31Call40D10View1() __asm__("func_80040D10");
unsigned char Physics31Call41580View1() __asm__("func_80041580");
unsigned char Physics31Call416F4View1() __asm__("func_800416F4");
int Physics31Call4EDE8View1() __asm__("func_8004EDE8");
unsigned char Physics31Call4F08CView1() __asm__("func_8004F08C");
unsigned char Physics31Call4F168View1() __asm__("func_8004F168");
unsigned char Physics31Call4F178View1() __asm__("func_8004F178");
unsigned char Physics31Call4F194View1() __asm__("func_8004F194");
unsigned char Physics31Call4F1C8View1() __asm__("func_8004F1C8");
extern void *Physics31Data6C570View1 __asm__("D_8006C570");
extern int Physics31Data6C640View1 __asm__("D_8006C640");
extern int Physics31Data6E044View1 __asm__("D_8006E044");
extern unsigned char Physics31Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics31Player0View1 __asm__("D_80070328");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics31Call40F48View1() __asm__("func_80040F48");
int Physics31Call41580View2() __asm__("func_80041580");
int Physics31Call4EDE8View2() __asm__("func_8004EDE8");
int Physics31Call4F08CView2() __asm__("func_8004F08C");
int Physics31Call4F168View2() __asm__("func_8004F168");
int Physics31Call4F178View2() __asm__("func_8004F178");
int Physics31Call4F194View2() __asm__("func_8004F194");
int Physics31Call4F1C8View2() __asm__("func_8004F1C8");
extern int Physics31Data6E044View2 __asm__("D_8006E044");
extern int Physics31Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics31Player0View2 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics31Player94View1 __asm__("D_80070328+0x94");
extern int Physics31Player80View1 __asm__("D_80070328+0x80");
extern int Physics31PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics31Player64View1 __asm__("D_80070328+0x64");
extern int Physics31Player88View1 __asm__("D_80070328+0x88");
extern int Physics31Player84View1 __asm__("D_80070328+0x84");
extern int Physics31PlayerACView1 __asm__("D_80070328+0xAC");
extern unsigned char Physics31Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics31Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics31PlayerA4View1 __asm__("D_80070328+0xA4");
int Physics31Call4EDE8View3() __asm__("func_8004EDE8");
int Physics31Call4F08CView3() __asm__("func_8004F08C");
int Physics31Call4F168View3() __asm__("func_8004F168");
int Physics31Call4F178View3() __asm__("func_8004F178");
int Physics31Call4F194View3() __asm__("func_8004F194");
int Physics31Call4F1C8View3() __asm__("func_8004F1C8");
extern unsigned char Physics31Player0View3 __asm__("D_80070328");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics31Player48View1 __asm__("D_80070328+0x48");
int Physics31Call40D10View2() __asm__("func_80040D10");
int Physics31Call41580View3() __asm__("func_80041580");
int Physics31Call4E9E4View1() __asm__("func_8004E9E4");
int Physics31Call4EA2CView1() __asm__("func_8004EA2C");
int Physics31Call4EDE8View4() __asm__("func_8004EDE8");
int Physics31Call4F08CView4() __asm__("func_8004F08C");
int Physics31Call4F194View4() __asm__("func_8004F194");
int Physics31Call4F1C8View4() __asm__("func_8004F1C8");
extern int Physics31Data6E044View3 __asm__("D_8006E044");
extern void *(*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics31PlayerB4View1 __asm__("D_80070328+0xB4");
extern void *(*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics44_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Physics44Slot4454)() __asm__("unk_ovlheader_80074454");
extern int (*Physics44Slot432C)() __asm__("unk_ovlheader_8007432C");
int Physics31Call4E880View1() __asm__("func_8004E880");
extern int Physics31Data6E160View1 __asm__("D_8006E160");
extern void *Physics31Data6E164View1 __asm__("D_8006E164");
int Physics31Call4ED6CView1() __asm__("func_8004ED6C");
void func_level_31_8008C864(int slotIndex) {
    register int inputSlot4 __asm__("$4");
    register int numeric4 __asm__("$4");
    register void *frame16 __asm__("$16");
    register void *heading17 __asm__("$17");
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
    register void *globalVector80 __asm__("$16");
    register void *globalVector80State20 __asm__("$16");
    register void *globalVector8CState20 __asm__("$18");
    int temp_v0_6;
    register int workWord3 __asm__("$3");
    register void *globalFieldB8PointerState1A __asm__("$16");
    register void *globalFieldB8PointerState20 __asm__("$16");
    void *raw34_temp_a0_3;
    void *raw34_temp_s1_2;
    int raw34_temp_v0_6;
    int raw34_temp_v0_7;
    int raw34_temp_v0_8;
    register int savedSlotIndex __asm__("$18");
    int lowProduct6;
    inputSlot4=slotIndex*16;
    workWord2=(int)&Physics31Data6E548View1;
    stateWord3=Physics31Field(&Physics31Player0View1,int*,0x48);
    __asm__("":"=r"(workWord2):"0"(workWord2),"r"(stateWord3),"r"(inputSlot4));
    inputSlot4+=workWord2;
    Physics31Data6C570View1=(void*)inputSlot4;
    switch(stateWord3){
        default:return;
    case 20:globalVector80 = &Physics31Player0View1 + 0x80;
        Physics31Call4F168View1(globalVector80);
        Physics31Call4F168View1(globalVector80 + 0xC);
        if (Physics31Data6E044View1 != 7) {
            Physics31Call40D10View1(0x1200);
            Physics31Call416F4View1();
            Physics31Call41580View1(0x5A, 0x10);
            return;
        }
        return;
    case 10:case 11:case 12:{
            register void *pointer16 __asm__("$16");
            register int limit17 __asm__("$17");
            int product10a,product10b;
            union {
                long long wide;
                struct {
                    int high;
                    unsigned int low;
                }
                words;
            }
            product144;
            workWord3=Physics31Data6E044View3;
            workWord2=7;
            call4=(void*)50;
            if(workWord3!=workWord2){
                Physics31Call40D10View2(4608);
                call4=(void*)50;
            }
            else{
                workWord2=Physics31Player64View1;
                Physics31PlayerACView1=0;
                Physics31PlayerA4View1=workWord2;
            }
            Physics31Call41580View3(call4,10);
            workWord3=0x38E30000;
            __asm__("":"=r"(workWord3):"0"(workWord3));
            pointer16=&Physics31PlayerACView1;
            workWord2=Physics31Field(pointer16,int*,0);
            workWord3|=0x8E39;
            product144.wide=(long long)workWord2*workWord3;
            call4=(void*)Physics31PlayerA4View1;
            Physics31PlayerB0View1=workWord2;
            workWord2>>=31;
            workWord3=product144.words.high>>5;
            limit17=workWord3-workWord2;
            workWord2=Physics31Call4EA2CView1(call4);
            workWord3=Physics31PlayerB0View1;
            product10a=workWord3*workWord2;
            call4=(void*)Physics31PlayerA4View1;
            workWord2=product10a>>12;
            __asm__("":"=r"(workWord2),"=r"(pointer16):"0"(workWord2),"1"(pointer16));
            Physics31Field(pointer16,int*,-44)=workWord2;
            workWord2=Physics31Call4E9E4View1(call4);
            workWord3=Physics31PlayerB0View1;
            product10b=workWord3*workWord2;
            __asm__("":"=r"(limit17):"0"(limit17),"r"(workWord2),"r"(workWord3));
            limit17+=32;
            call4=&originalFrame.sp10;
            __asm__ volatile(""::"r"(call4):"memory");
            call5=pointer16-44;
            pointer16-=32;
            Physics31Player88View1=0;
            workWord2=product10b>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics31Player84View1=workWord2;
            __asm__ volatile("":"=r"(pointer16):"0"(pointer16):"memory");
            Physics31Call4F1C8View4(call4,call5,pointer16);
            originalFrame.sp18=0;
            call5=(void*)Physics31Call4EDE8View4(&originalFrame.sp10,0);
            workWord2=limit17<(int)call5;
            if(workWord2)Physics31Call4F08CView4(&originalFrame.sp10,call5,limit17);
            call4=pointer16;
            call5=call4;
            Physics31Call4F194View4(call4,call5,&originalFrame.sp10);
            workWord2=Physics31PlayerB4View1;
            workWord3=-3072;
            Physics31Player94View1=workWord3;
            workWord2=workWord2<65;
            if(workWord2){
                Physics31Player1B9View1=1;
                return;
            }
            Physics31Player1B9View1=0;
            return;
        }
    case 29:Physics31Call4F168View3(&originalFrame.sp20);
        raw34_temp_s1_2 = &Physics31Player0View3 + 0x8C;
        Physics31Call4F1C8View3(&originalFrame.sp20, &originalFrame.sp20, raw34_temp_s1_2);
        if (Physics31Field(&Physics31Player0View3, int *, 0xB8) != 0) {
            originalFrame.sp28 = 0;
            raw34_temp_v0_6 = Physics31Call4EDE8View3(&originalFrame.sp20, 0);
            if (raw34_temp_v0_6 >= 0x41) {
                Physics31Call4F08CView3(&originalFrame.sp20, raw34_temp_v0_6, 0x40);
            }
            originalFrame.sp28 = -0xC0;
            call4=raw34_temp_s1_2-12;
            call5=raw34_temp_s1_2;
            call6=&originalFrame.sp20;
            goto commit29;
        }
        else {
            raw34_temp_v0_7 = Physics31Call4EDE8View3(&originalFrame.sp20, 1);
            if (raw34_temp_v0_7 >= 0x101) {
                Physics31Call4F08CView3(&originalFrame.sp20, raw34_temp_v0_7, 0x100);
            }
            Physics31Call4F194View3(raw34_temp_s1_2, raw34_temp_s1_2, &originalFrame.sp20);
            call4=raw34_temp_s1_2-12;
            call5=raw34_temp_s1_2;
            __asm__("":"=r"(call5):"0"(call5));
            call6=call5+92;
        }
        commit29:Physics31Call4F194View3(call4,call5,call6);
        raw34_temp_a0_3 = &Physics31Player0View3 + 0x8C;
        Physics31Call4F178View3(raw34_temp_a0_3, raw34_temp_a0_3 - 0xC);
        workWord2=Physics31Player94View1;
        workWord2=workWord2<-8960;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        if(workWord2){
            workWord2=-8960;
            Physics31Player94View1=workWord2;
            return;
        }
        break;
    case 26:globalFieldB8PointerState1A = &Physics31Player0View3 + 0xB8;
        if (Physics31Field(&Physics31Player0View3, int *, 0xB8) != 0) {
            raw34_temp_v0_8 = Physics31Field(&Physics31Player0View3, int *, 0x94) - 0x600;
            Physics31Field(&Physics31Player0View3, int *, 0x94) = raw34_temp_v0_8;
            if (raw34_temp_v0_8 < -0x2300) {
                Physics31Field(&Physics31Player0View3, int *, 0x94) = -0x2300;
            }
            Physics31Call4F178View3(globalFieldB8PointerState1A - 0x38, globalFieldB8PointerState1A - 0x2C);
            return;
        }
        Physics31Call4F168View3(globalFieldB8PointerState1A-56);
        Physics31Call4F168View3(globalFieldB8PointerState1A-44);
        return;
    case 32:globalFieldB8PointerState20 = &Physics31Player0View1 + 0xB8;
        if (Physics31Field(&Physics31Player0View1, int *, 0xB8) != 0) {
            vectorAt30=&originalFrame.sp30;
            Physics31Call4F168View1(vectorAt30);
            call4=vectorAt30;
            call5=vectorAt30;
            __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
            globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
            Physics31Call4F1C8View1(call4, call5, globalVector8CState20);
            originalFrame.sp38 = 0;
            temp_v0_6 = Physics31Call4EDE8View1(&originalFrame.sp30, 0);
            if (temp_v0_6 >= 0x41) {
                Physics31Call4F08CView1(&originalFrame.sp30, temp_v0_6, 0x40);
            }
            originalFrame.sp38 = -0xC0;
            globalVector80State20 = globalFieldB8PointerState20 - 0x38;
            Physics31Call4F194View1(globalVector80State20, globalVector8CState20, &originalFrame.sp30);
            Physics31Call4F178View1(globalVector8CState20, globalVector80State20);
        }
        else {
            Physics31Call4F168View1(globalFieldB8PointerState20 - 0x38);
            Physics31Call4F168View1(globalFieldB8PointerState20 - 0x2C);
        }
        call5=&Physics31Player94View1;
        __asm__("":"=r"(call5):"0"(call5));
        workWord2=Physics31Field(call5,int*,0);
        workWord2=workWord2<-8960;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        if(workWord2){
            workWord2=-8960;
            Physics31Field(call5,int*,0)=workWord2;
        }
        workWord3=Physics31Player48View1;
        workWord2=58;
        if(workWord3!=workWord2)return;
        workWord2=(int)Controller88028_SpawnParticle;
        if(!workWord2)return;
        workWord2=Physics31Data6C640View1;
        workWord2&=1;
        if(!workWord2)return;
        {
            originalFrame.sp40 = 0;
            originalFrame.sp44 = 0;
            originalFrame.sp48 = 0xE;
            Physics31Call4F178View1(&originalFrame.sp50, call5-148);
            originalFrame.sp50 += Physics31Call363DCView1(0, 0x12C);
            originalFrame.sp54 += Physics31Call363DCView1(0, 0x12C);
            originalFrame.sp58 += Physics31Call363DCView1(0, 0x12C);
            workWord2 = (int)Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp50, &originalFrame.sp40);
            Physics31Field(workWord2, signed char *, 2) = 6;
            Physics31Field(workWord2, signed char *, 0xA) = 0x20;
        }
        break;
    case 146:globalVector80=&Physics31Player0View2+0xB8;
        workWord2=Physics31Field(globalVector80,int*,0);
        if(!workWord2)goto zero128;
        vectorAt30=&originalFrame.sp40;
        Physics31Call4F168View2(vectorAt30);
        call4=vectorAt30;
        call5=vectorAt30;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalVector8CState20=globalVector80-44;
        Physics31Call4F1C8View2(call4,call5,globalVector8CState20);
        originalFrame.sp48=0;
        call5=(void*)Physics31Call4EDE8View2(vectorAt30,0);
        workWord2=(int)call5<65;
        if(!workWord2)Physics31Call4F08CView2(vectorAt30,call5,64);
        originalFrame.sp48=-192;
        globalVector80-=56;
        Physics31Call4F194View2(globalVector80,globalVector8CState20,vectorAt30);
        Physics31Call4F178View2(globalVector8CState20,globalVector80);
        goto clamp128;
        zero128:Physics31Call4F168View2(globalVector80-56);
        Physics31Call4F168View2(globalVector80-44);
        goto clamp128;
        clamp128:globalPointer=&Physics31Player94View1;
        workWord2=Physics31Field(globalPointer,int*,0);
        workWord2=workWord2<-8960;
        if(workWord2){
            workWord2=-8960;
            Physics31Field(globalPointer,int*,0)=workWord2;
        }
        return;
    case 135:case 139:
        frame16=&originalFrame.sp60;
        call4=frame16;
        __asm__("":"=r"(call4):"0"(call4));
        heading17=&Physics31Player80View1;
        __asm__("":"=r"(heading17):"0"(heading17));
        Physics31Call4F178View2(call4,heading17);
        originalFrame.sp68=0;
        workWord2=Physics31Call4EDE8View2(frame16,0);
        call5=(void*)workWord2;
        workWord2=(int)call5<193;
        call4=heading17;
        if(!workWord2){
            Physics31Call4F08CView2(frame16,call5,192);
            call4=heading17;
        }
        call5=heading17;
        Physics31Call4F1C8View2(call4,call5,frame16);
        Physics31Call4F194View2(heading17+12,heading17,heading17+104);
        workWord3=Physics31Data6E044View2;
        workWord2=7;
        if(workWord3==workWord2)goto flag135;
        workWord3=Physics31Data6E160View1;
        workWord2=34;
        if(workWord3==workWord2 && (call5=Physics31Data6E164View1)){
            call4=frame16;
            Physics31Call4F1C8View2(call4,call5+12,heading17-128);
            workWord2=Physics31Call4E880View1(originalFrame.sp60,originalFrame.sp64,1);
            call4=(void*)32;
            Physics31PlayerA4View1=workWord2;
            Physics31Call41580View2(call4,8);
        }
        Physics31Call40F48View1(&originalFrame.sp50,1);
        workWord2=originalFrame.sp50;
        numeric4=originalFrame.sp54;
        originalFrame.sp68=0;
        workWord3=workWord2*25;
        workWord3<<=7;
        workWord3>>=7;
        workWord2=numeric4*25;
        workWord2<<=7;
        workWord2>>=7;
        originalFrame.sp54=workWord2;
        originalFrame.sp60=workWord2;
        __asm__ volatile("":::"memory");
        if(workWord2<0)workWord2=-workWord2;
        originalFrame.sp50=workWord3;
        originalFrame.sp64=workWord3;
        __asm__ volatile("":::"memory");
        if(workWord3<0)workWord3=-workWord3;
        workWord3=workWord3<workWord2;
        if(workWord3)originalFrame.sp64=0;
        else{
            __asm__ volatile("":::"$3");
            originalFrame.sp60=0;
        }
        workWord2=Physics31Call4EDE8View2(&originalFrame.sp60,0);
        call4=(void*)originalFrame.sp50;
        call5=(void*)originalFrame.sp54;
        Physics31PlayerACView1=workWord2;
        workWord2=Physics31Call4E880View1(call4,call5,1);
        workWord3=workWord2;
        workWord2=workWord3<2049;
        Physics31PlayerA4View1=workWord3;
        if(!workWord2){
            workWord2=workWord3-4096;
            Physics31PlayerA4View1=workWord2;
        }
        flag135:__asm__ volatile(""::"i"(0x8008CFBC):"memory");
        globalPointer=&Physics31Player1BAView1;
        workWord2=Physics31Field(globalPointer,unsigned char*,0);
        if(!workWord2){
            workWord2=1;
            goto mark1B9;
        }
        __asm__ volatile(""::"i"(0x8008CFD4):"memory");
        workWord2=Physics31Data6E538View1;
        workWord2&=16;
        if(workWord2)return;
        workWord2=1;
        __asm__ volatile(""::"i"(0x8008CFEC):"memory");
        Physics31Field(globalPointer,unsigned char*,0)=0;
        goto mark1B9;
    case 136:case 137:case 138:
        globalVector80=&Physics31Player80View1;
        __asm__("":"=r"(globalVector80):"0"(globalVector80));
        Physics31Call4F168View2(globalVector80);
        Physics31Call4F168View2(globalVector80+12);
        workWord3=Physics31Data6E044View2;
        workWord2=7;
        if(workWord3==workWord2)goto flag136;
        workWord2=34;
        workWord3=Physics31Data6E160View1;
        if(workWord3!=workWord2)goto input136;
        call5=Physics31Data6E164View1;
        call4=&originalFrame.sp78;
        if(!call5)goto input136;
        call5+=12;
        Physics31Call4F1C8View2(call4,call5,globalVector80-128);
        workWord2=Physics31Call4E880View1(originalFrame.sp78,originalFrame.sp7C,1);
        call4=(void*)32;
        Physics31PlayerA4View1=workWord2;
        Physics31Call41580View2(call4,8);
        input136:Physics31Call40F48View1(&originalFrame.sp70,1);
        workWord2=originalFrame.sp70;
        numeric4=originalFrame.sp74;
        Physics31Player88View1=0;
        workWord3=workWord2*25;
        workWord3<<=7;
        workWord3>>=7;
        workWord2=numeric4*25;
        workWord2<<=7;
        workWord2>>=7;
        call4=&Physics31Player80View1;
        originalFrame.sp70=workWord3;
        originalFrame.sp74=workWord2;
        Physics31Field(call4,int*,0)=workWord2;
        __asm__ volatile("":::"memory");
        if(workWord2<0)workWord2=-workWord2;
        Physics31Player84View1=workWord3;
        __asm__ volatile("":::"memory");
        if(workWord3<0)workWord3=-workWord3;
        workWord3=workWord3<workWord2;
        if(workWord3)Physics31Player84View1=0;
        else{
            __asm__ volatile("":::"$3");
            Physics31Field(call4,int*,0)=0;
        }
        workWord2=Physics31Call4EDE8View2(&Physics31Player80View1,0);
        call4=(void*)originalFrame.sp70;
        call5=(void*)originalFrame.sp74;
        Physics31PlayerACView1=workWord2;
        workWord2=Physics31Call4E880View1(call4,call5,1);
        workWord3=workWord2;
        workWord2=workWord3<2049;
        Physics31PlayerA4View1=workWord3;
        if(!workWord2){
            workWord2=workWord3-4096;
            Physics31PlayerA4View1=workWord2;
        }
        flag136:__asm__ volatile(""::"i"(0x8008D160):"memory");
        globalPointer=&Physics31Player1BAView1;
        workWord2=Physics31Field(globalPointer,unsigned char*,0);
        if(!workWord2){
            workWord2=1;
            goto mark1B9;
        }
        __asm__ volatile(""::"i"(0x8008D178):"memory");
        workWord2=Physics31Data6E538View1;
        workWord2&=16;
        if(workWord2)return;
        workWord2=1;
        __asm__ volatile(""::"i"(0x8008D190):"memory");
        Physics31Field(globalPointer,unsigned char*,0)=0;
        goto mark1B9;
    case 140:case 141:
        frame16=&originalFrame.sp78;
        call4=frame16;
        __asm__("":"=r"(call4):"0"(call4));
        heading17=&Physics31Player80View1;
        __asm__("":"=r"(heading17):"0"(heading17));
        Physics31Call4F178View2(call4,heading17);
        originalFrame.sp80=0;
        workWord2=Physics31Call4EDE8View2(frame16,0);
        call5=(void*)workWord2;
        workWord2=(int)call5<193;
        call4=heading17;
        if(!workWord2){
            Physics31Call4F08CView2(frame16,call5,192);
            call4=heading17;
        }
        call5=heading17;
        Physics31Call4F1C8View2(call4,call5,frame16);
        Physics31Call4F194View2(heading17+12,heading17,heading17+104);
        workWord3=Physics31Data6E044View2;
        workWord2=7;
        if(workWord3==workWord2)return;
        workWord2=34;
        workWord3=Physics31Data6E160View1;
        if(workWord3!=workWord2)return;
        call5=Physics31Data6E164View1;
        call4=&originalFrame.sp88;
        if(!call5)goto done140;
        call5+=12;
        Physics31Call4F1C8View2(call4,call5,heading17-128);
        workWord2=Physics31Call4E880View1(originalFrame.sp88,originalFrame.sp8C,1);
        call4=(void*)32;
        Physics31PlayerA4View1=workWord2;
        Physics31Call41580View2(call4,8);
        done140:return;
    case 142:case 143:case 144:case 145:
        workWord3=Physics31Data6E160View1;
        workWord2=34;
        if(workWord3==workWord2 && (call5=Physics31Data6E164View1)){
            call4=&originalFrame.sp98;
            Physics31Call4F1C8View2(call4,call5+12,&Physics31Player0View2);
            workWord2=Physics31Call4E880View1(originalFrame.sp98,originalFrame.sp9C,1);
            call4=(void*)32;
            Physics31PlayerA4View1=workWord2;
            Physics31Call41580View2(call4,8);
        }
        Physics31Call40F48View1(&originalFrame.sp88,1);
        workWord2=originalFrame.sp88;
        numeric4=originalFrame.sp8C;
        workWord3=workWord2*25;
        workWord3<<=7;
        workWord3>>=7;
        workWord2=numeric4*25;
        workWord2<<=7;
        workWord2>>=7;
        originalFrame.sp88=workWord3;
        originalFrame.sp8C=workWord2;
        if(workWord3)goto active142;
        if(workWord2)goto active142;
        workWord3=Physics31Player48View1;
        switch(workWord3){
        case 142:originalFrame.sp8C=3200;
            break;
        case 143:originalFrame.sp8C=-3200;
            break;
        case 144:originalFrame.sp88=3200;
            break;
        case 145:originalFrame.sp88=-3200;
            break;
        }
        call5=(void*)1;
        goto vectors142;
        active142:call5=0;
        vectors142:workWord3=originalFrame.sp8C;
        workWord2=originalFrame.sp88;
        call4=&Physics31Player80View1;
        Physics31Player88View1=0;
        Physics31Field(call4,int*,0)=workWord3;
        __asm__ volatile("":::"memory");
        if(workWord3<0)workWord3=-workWord3;
        Physics31Player84View1=workWord2;
        if(workWord2<0)workWord2=-workWord2;
        workWord2=workWord2<workWord3;
        if(workWord2)Physics31Player84View1=0;
        else{
            __asm__ volatile("":::"$2");
            Physics31Field(call4,int*,0)=0;
        }
        if(call5)Physics31PlayerACView1=0;
        else{
            __asm__("":"=r"(call5):"0"(call5));
            workWord2=Physics31Call4EDE8View2(&Physics31Player80View1,0);
            Physics31PlayerACView1=workWord2;
        }
        workWord2=Physics31Call4E880View1(originalFrame.sp88,originalFrame.sp8C,1);
        workWord3=workWord2;
        heading17=&Physics31PlayerA4View1;
        workWord2=workWord3<2049;
        Physics31Field(heading17,int*,0)=workWord3;
        if(!workWord2){
            workWord2=workWord3-4096;
            Physics31Field(heading17,int*,0)=workWord2;
        }
        call4=heading17-116;
        __asm__("":"=r"(call4):"0"(call4));
        globalVector80=heading17-36;
        Physics31Call4ED6CView1(call4,globalVector80,globalVector80);
        Physics31Call4F194View2(heading17-24,globalVector80,heading17+68);
        return;
    case 147:
        frame16=&originalFrame.spB0;
        call4=frame16;
        __asm__("":"=r"(call4):"0"(call4));
        heading17=&Physics31Player80View1;
        __asm__("":"=r"(heading17):"0"(heading17));
        Physics31Call4F178View2(call4,heading17);
        originalFrame.spB8=0;
        workWord2=Physics31Call4EDE8View2(frame16,0);
        call5=(void*)workWord2;
        workWord2=(int)call5<193;
        call4=heading17;
        if(!workWord2){
            Physics31Call4F08CView2(frame16,call5,192);
            call4=heading17;
        }
        call5=heading17;
        Physics31Call4F1C8View2(call4,call5,frame16);
        Physics31Call4F194View2(heading17+12,heading17,heading17+104);
        call5=&Physics31Data6E044View2;
        workWord3=Physics31Field(call5,int*,0);
        workWord2=7;
        call4=frame16;
        if(workWord3==workWord2)goto flag147;
        call5-=36;
        Physics31Call4F1C8View2(call4,call5,heading17-128);
        workWord2=Physics31Call4E880View1(originalFrame.spB0,originalFrame.spB4,1);
        call4=(void*)32;
        Physics31PlayerA4View1=workWord2;
        Physics31Call41580View2(call4,8);
        Physics31Call40F48View1(&originalFrame.spA8,1);
        workWord2=originalFrame.spA8;
        numeric4=originalFrame.spAC;
        originalFrame.spB8=0;
        workWord3=workWord2*25;
        workWord3<<=7;
        workWord3>>=7;
        workWord2=numeric4*25;
        workWord2<<=7;
        workWord2>>=7;
        originalFrame.spAC=workWord2;
        originalFrame.spB0=workWord2;
        __asm__ volatile("":::"memory");
        if(workWord2<0)workWord2=-workWord2;
        originalFrame.spA8=workWord3;
        originalFrame.spB4=workWord3;
        __asm__ volatile("":::"memory");
        if(workWord3<0)workWord3=-workWord3;
        workWord3=workWord3<workWord2;
        if(workWord3)originalFrame.spB4=0;
        else{
            __asm__ volatile("":::"$3");
            originalFrame.spB0=0;
        }
        workWord2=Physics31Call4EDE8View2(&originalFrame.spB0,0);
        call4=(void*)originalFrame.spA8;
        call5=(void*)originalFrame.spAC;
        Physics31PlayerACView1=workWord2;
        workWord2=Physics31Call4E880View1(call4,call5,1);
        workWord3=workWord2;
        workWord2=workWord3<2049;
        Physics31PlayerA4View1=workWord3;
        if(!workWord2){
            workWord2=workWord3-4096;
            Physics31PlayerA4View1=workWord2;
        }
        flag147:__asm__ volatile(""::"i"(0x8008D5F4):"memory");
        globalPointer=&Physics31Player1BAView1;
        workWord2=Physics31Field(globalPointer,unsigned char*,0);
        if(!workWord2){
            workWord2=1;
            goto mark1B9;
        }
        __asm__ volatile(""::"i"(0x8008D60C):"memory");
        workWord2=Physics31Data6E538View1;
        workWord2&=16;
        if(workWord2)return;
        workWord2=1;
        __asm__ volatile(""::"i"(0x8008D624):"memory");
        Physics31Field(globalPointer,unsigned char*,0)=0;
        goto mark1B9;
    }
    return;
    mark1B9:Physics31Player1B9View1=workWord2;
    return;
}
#undef Physics31Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_31/animation/func_level_31_8008D64C.s SHA256 f9ec073208eb23fb238afad6b4bd0948868409a8f263152baf39d52a8340f3a8. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Level31_8D64CField(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern short Level31_8D64C_D_800658A0[0x100] __asm__("D_800658A0");
extern short Level31_8D64C_D_80065920[0x100] __asm__("D_80065920");
extern Moby* Level31_8D64C_D_8006C550 __asm__("D_8006C550");
extern Spyro Level31_8D64C_D_80070328 __asm__("D_80070328");
extern void Level31_8D64C_func_8004F110(Vector3D*, int) __asm__("func_8004F110");
extern void Level31_8D64C_func_8004F178(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern void Level31_8D64C_func_8004F194(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F194");
extern void Level31_8D64C_func_80055D24(Moby*, int) __asm__("func_80055D24");
extern int Level31_8D64C_func_80055E84(Moby*) __asm__("func_80055E84");

unsigned char Level31_8D64C_func_8001BA30() __asm__("func_8001BA30");
 /* extern */
unsigned char Level31_8D64C_func_80041930() __asm__("func_80041930");
                            /* extern */
unsigned char Level31_8D64C_func_80041C20() __asm__("func_80041C20");
                            /* extern */
unsigned char Level31_8D64C_func_80042A44() __asm__("func_80042A44");
                            /* extern */
unsigned char Level31_8D64C_func_80043728() __asm__("func_80043728");
                            /* extern */
int Level31_8D64C_func_800438F4() __asm__("func_800438F4");
                                /* extern */
unsigned char Level31_8D64C_func_80043A38() __asm__("func_80043A38");
                     /* extern */
unsigned char Level31_8D64C_func_80055F14() __asm__("func_80055F14");
 /* extern */

void func_level_31_8008D64C(void) {
    /* Original scratch vectors occupy SP+0x18/+0x28/+0x38/+0x48/+0x58/+0x68.
     * Shared calls retain original incoming edges;
      the final vector addition
     * is original8008DCCC. Signed LH table values retain (value*5)>>6.
     * Table byte offsets, argument registers and zero-store ordering follow
     * original instructions. Empty constraints add no instruction opcodes.
     * Physical units, helper semantics and update cadence remain unresolved. */
    struct {Vector3D sp18;
     unsigned char pad24[4];
     Vector3D sp28;
     unsigned char pad34[4];
     Vector3D sp38;
     unsigned char pad44[4];
     Vector3D sp48;
     unsigned char pad54[4];
     Vector3D sp58;
     unsigned char pad64[4];
     Vector3D sp68;
     unsigned char pad74[4];
    } scratch;

    register Vector3D *destination4 __asm__("$4");
    register Vector3D *source5 __asm__("$5");
    register Vector3D *offset6 __asm__("$6");
    register int tableByteOffset3 __asm__("$3");
    register int tableWord6 __asm__("$6");
    register int cosineWord3 __asm__("$3");
    void *privateRecord17;
    void *linkedPrivate18;
    void *privateRecord18b;
    void *privateRecord18c;
    void *linkedPrivate19;
    void *linkedPrivate20;

    switch (Level31_8D64C_D_80070328.animationState) {
    case 0x14:
    case 0x87:
    case 0x8B:
    case 0x8C:
    case 0x8D:
    case 0x93:
        if (Level31_8D64C_func_800438F4() == 0) {
            Level31_8D64C_func_80043728();
        }
        Level31_8D64C_func_80041C20();
        Level31_8D64C_D_80070328.unk9a = 0;
        goto sharedClearAnimationState;
    case 0x20:
    case 0x92:
        Level31_8D64C_func_80041C20();
sharedClearAnimationState:
        Level31_8D64C_func_80042A44();
        Level31_8D64C_D_80070328.unk4[0] = 0;
        return;
    case 0xA:
    case 0xB:
    case 0xC:
    case 0x8E:
    case 0x8F:
    case 0x90:
    case 0x91:
        Level31_8D64C_func_800438F4();
        Level31_8D64C_func_80041C20();
        Level31_8D64C_func_80042A44();
        Level31_8D64C_func_80041930();
        goto sharedRotationCall;
    case 0x1A:
    case 0x1D:
        Level31_8D64C_func_80041C20();
        Level31_8D64C_func_80042A44();
sharedRotationCall:
        Level31_8D64C_func_80043A38(0xC00);
        Level31_8D64C_D_80070328.unk4[0] = 0;
        return;
    case 0x88:
        if (Level31_8D64C_func_800438F4() == 0) {
            Level31_8D64C_func_80043728();
        }
        Level31_8D64C_func_80041C20();
        Level31_8D64C_D_80070328.unk9a = 0;
        Level31_8D64C_func_80042A44();
        Level31_8D64C_D_80070328.unk4[0] = 0;
        if ((Level31_8D64C_D_80070328.critterMobyPtr->animationState.id == (Level31_8D64C_D_80070328.animationState - 0x87)) && ((unsigned int) (Level31_8D64C_func_80055E84(Level31_8D64C_D_80070328.critterMobyPtr) - 1) < 3U)) {
            privateRecord17 = Level31_8D64C_D_80070328.critterMobyPtr->mobyTag;
            linkedPrivate18 = Level31_8D64C_D_8006C550[Level31_8D64CField(privateRecord17, int *, 0x2C)].mobyTag;
            Level31_8D64C_func_80055D24(Level31_8D64C_D_80070328.critterMobyPtr, 4);
            Level31_8D64C_func_80055F14(Level31_8D64C_D_80070328.critterMobyPtr, 0, &scratch.sp18);
            Level31_8D64C_func_80055F14(Level31_8D64C_D_80070328.critterMobyPtr, 1, &scratch.sp28);
            Level31_8D64C_func_8004F194(&scratch.sp18, &scratch.sp18, &scratch.sp28);
            Level31_8D64C_func_8004F110(&scratch.sp18, 1);
            Level31_8D64C_func_8001BA30(&scratch.sp18, 0x140, 1, 0, 1, Level31_8D64C_D_80070328.critterMobyPtr);
            if (Level31_8D64CField(privateRecord17, int *, 0x3C) > 0) {
                Level31_8D64C_func_8004F194(&scratch.sp28, &scratch.sp18, privateRecord17 + 0x3C);
                Level31_8D64C_func_8004F110(&scratch.sp28, 1);
                Level31_8D64C_func_8001BA30(&scratch.sp28, 0x100, 1, 0, 4, Level31_8D64C_D_80070328.critterMobyPtr);
            }
            Level31_8D64C_func_8004F178(privateRecord17 + 0x3C, &scratch.sp18);
            tableByteOffset3 = Level31_8D64C_D_80070328.bodyRotation.yaw;
            __asm__("" : "=r"(tableByteOffset3): "0"(tableByteOffset3): "$4");
            destination4 = linkedPrivate18 + 0x28;
            tableByteOffset3 *= 2;
            tableWord6 = *(short *)((unsigned char*)Level31_8D64C_D_80065920 + tableByteOffset3);
            __asm__("" : "=r"(tableWord6): "0"(tableWord6): "$5");
            source5 = &scratch.sp18;
            scratch.sp28.x = (tableWord6 * 5) >> 6;
            cosineWord3 = *(short *)((unsigned char*)Level31_8D64C_D_800658A0 + tableByteOffset3);
            __asm__("" : "=r"(cosineWord3): "0"(cosineWord3): "$6");
            offset6 = &scratch.sp28;
            scratch.sp28.z = 0;
            __asm__ volatile("" : "=m"(scratch.sp28.z): "m"(scratch.sp28.z), "r"(cosineWord3));
            scratch.sp28.y = (cosineWord3 * 5) >> 6;
            goto sharedVectorAdd;
        }
    default:
        return;
    case 0x89:
        if (Level31_8D64C_func_800438F4() == 0) {
            Level31_8D64C_func_80043728();
        }
        Level31_8D64C_func_80041C20();
        Level31_8D64C_D_80070328.unk9a = 0;
        Level31_8D64C_func_80042A44();
        Level31_8D64C_D_80070328.unk4[0] = 0;
        if ((Level31_8D64C_D_80070328.critterMobyPtr->animationState.id == (Level31_8D64C_D_80070328.animationState - 0x87)) && ((unsigned int) (Level31_8D64C_func_80055E84(Level31_8D64C_D_80070328.critterMobyPtr) - 0xB) < 3U)) {
            privateRecord18b = Level31_8D64C_D_80070328.critterMobyPtr->mobyTag;
            linkedPrivate19 = Level31_8D64C_D_8006C550[Level31_8D64CField(privateRecord18b, int *, 0x2C)].mobyTag;
            Level31_8D64C_func_80055D24(Level31_8D64C_D_80070328.critterMobyPtr, 4);
            Level31_8D64C_func_80055F14(Level31_8D64C_D_80070328.critterMobyPtr, 2, &scratch.sp38);
            Level31_8D64C_func_80055F14(Level31_8D64C_D_80070328.critterMobyPtr, 3, &scratch.sp48);
            Level31_8D64C_func_8004F194(&scratch.sp38, &scratch.sp38, &scratch.sp48);
            Level31_8D64C_func_8004F110(&scratch.sp38, 1);
            Level31_8D64C_func_8001BA30(&scratch.sp38, 0x140, 1, 0, 2, Level31_8D64C_D_80070328.critterMobyPtr);
            if (Level31_8D64CField(privateRecord18b, int *, 0x3C) > 0) {
                Level31_8D64C_func_8004F194(&scratch.sp48, &scratch.sp38, privateRecord18b + 0x3C);
                Level31_8D64C_func_8004F110(&scratch.sp48, 1);
                Level31_8D64C_func_8001BA30(&scratch.sp48, 0x100, 1, 0, 4, Level31_8D64C_D_80070328.critterMobyPtr);
            }
            Level31_8D64C_func_8004F178(privateRecord18b + 0x3C, &scratch.sp38);
            tableByteOffset3 = Level31_8D64C_D_80070328.bodyRotation.yaw;
            __asm__("" : "=r"(tableByteOffset3): "0"(tableByteOffset3): "$4");
            destination4 = linkedPrivate19 + 0x28;
            tableByteOffset3 *= 2;
            tableWord6 = *(short *)((unsigned char*)Level31_8D64C_D_80065920 + tableByteOffset3);
            __asm__("" : "=r"(tableWord6): "0"(tableWord6): "$5");
            source5 = &scratch.sp38;
            scratch.sp48.x = (tableWord6 * 5) >> 6;
            cosineWord3 = *(short *)((unsigned char*)Level31_8D64C_D_800658A0 + tableByteOffset3);
            __asm__("" : "=r"(cosineWord3): "0"(cosineWord3): "$6");
            offset6 = &scratch.sp48;
            scratch.sp48.z = 0;
            __asm__ volatile("" : "=m"(scratch.sp48.z): "m"(scratch.sp48.z), "r"(cosineWord3));
            scratch.sp48.y = (cosineWord3 * 5) >> 6;
            goto sharedVectorAdd;
        }
        break;
    case 0x8A:
        if (Level31_8D64C_func_800438F4() == 0) {
            Level31_8D64C_func_80043728();
        }
        Level31_8D64C_func_80041C20();
        Level31_8D64C_D_80070328.unk9a = 0;
        Level31_8D64C_func_80042A44();
        Level31_8D64C_D_80070328.unk4[0] = 0;
        if ((Level31_8D64C_D_80070328.critterMobyPtr->animationState.id == (Level31_8D64C_D_80070328.animationState - 0x87)) && ((unsigned int) (Level31_8D64C_func_80055E84(Level31_8D64C_D_80070328.critterMobyPtr) - 3) < 3U)) {
            privateRecord18c = Level31_8D64C_D_80070328.critterMobyPtr->mobyTag;
            linkedPrivate20 = Level31_8D64C_D_8006C550[Level31_8D64CField(privateRecord18c, int *, 0x2C)].mobyTag;
            Level31_8D64C_func_80055D24(Level31_8D64C_D_80070328.critterMobyPtr, 4);
            Level31_8D64C_func_80055F14(Level31_8D64C_D_80070328.critterMobyPtr, 2, &scratch.sp58);
            Level31_8D64C_func_80055F14(Level31_8D64C_D_80070328.critterMobyPtr, 3, &scratch.sp68);
            Level31_8D64C_func_8004F194(&scratch.sp58, &scratch.sp58, &scratch.sp68);
            Level31_8D64C_func_8004F110(&scratch.sp58, 1);
            Level31_8D64C_func_8001BA30(&scratch.sp58, 0x100, 1, 0, 4, Level31_8D64C_D_80070328.critterMobyPtr);
            if (Level31_8D64CField(privateRecord18c, int *, 0x3C) > 0) {
                Level31_8D64C_func_8004F194(&scratch.sp68, &scratch.sp58, privateRecord18c + 0x3C);
                Level31_8D64C_func_8004F110(&scratch.sp68, 1);
                Level31_8D64C_func_8001BA30(&scratch.sp68, 0x100, 1, 0, 4, Level31_8D64C_D_80070328.critterMobyPtr);
            }
            Level31_8D64C_func_8004F178(privateRecord18c + 0x3C, &scratch.sp58);
            tableByteOffset3 = Level31_8D64C_D_80070328.bodyRotation.yaw;
            __asm__("" : "=r"(tableByteOffset3): "0"(tableByteOffset3): "$4");
            destination4 = linkedPrivate20 + 0x28;
            tableByteOffset3 *= 2;
            tableWord6 = *(short *)((unsigned char*)Level31_8D64C_D_80065920 + tableByteOffset3);
            __asm__("" : "=r"(tableWord6): "0"(tableWord6): "$5");
            source5 = &scratch.sp58;
            scratch.sp68.x = (tableWord6 * 5) >> 6;
            cosineWord3 = *(short *)((unsigned char*)Level31_8D64C_D_800658A0 + tableByteOffset3);
            __asm__("" : "=r"(cosineWord3): "0"(cosineWord3): "$6");
            offset6 = &scratch.sp68;
            scratch.sp68.z = 0;
            __asm__ volatile("" : "=m"(scratch.sp68.z): "m"(scratch.sp68.z), "r"(cosineWord3));
            scratch.sp68.y = (cosineWord3 * 5) >> 6;
sharedVectorAdd:
            Level31_8D64C_func_8004F194(destination4, source5, offset6);
        }
        break;
    }
}
#undef Level31_8D64CField


#define LEVEL_ID 31
#define PlaySpyroSounds_level_31 func_level_31_8008DCF8
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_31_8008DE1C(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x87:
    case 0x8b:
    case 0x8e:
    case 0x8f:
    case 0x90:
    case 0x91:
    case 0x93:
        {
            int* tag = spyro.critterMobyPtr->mobyTag;
            tag[10]++;
            if (tag[10] > 60) tag[10] = 60;
            func_80043ABC(&spyro.unk9e);
        }
        break;
    case 0xa:
    case 0xb:
    case 0xc:
    case 0x14:
    case 0x1a:
    case 0x1d:
    case 0x20:
    case 0x88:
    case 0x89:
    case 0x8a:
    case 0x8c:
    case 0x8d:
    case 0x92:
        func_80043ABC(&spyro.unk9e);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 8008DEC0..8008E3C4.
 * Baseline: verified level27_80088AE4 transition case1A and numeric schemas.
 * Original31 supplies independent private-data routes88/89/8A, byte offsets
 * 0x28/0x3C and signed trig reads from byte-scaled table indices.
 * Empty constraints preserve original stores/load delays and duplicated calls;
 * otherwise unused V0 call results establish no helper-return meaning.
 * Source units/producers, sound semantics, helper contracts, invocation cadence
 * and runtime/browser parity remain open. Test every original code/table word
 * and all complete retail EXE/overlay hashes before acceptance.
 */
int Transition31Zero(Vector3D*) __asm__("func_8004F168");
int Transition31Call441F0(void) __asm__("func_800441F0");
extern Spyro Callback31_D_80070328 __asm__("D_80070328");
extern short Callback31_D_800658A0[] __asm__("D_800658A0");
extern short Callback31_D_80065920[] __asm__("D_80065920");
int Callback31_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
int Callback31_func_8003636C(int low, int high) __asm__("func_8003636C");
void Callback31_func_80043A38(int scale) __asm__("func_80043A38");
void Callback31_func_800441F0(void) __asm__("func_800441F0");
void Callback31_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Callback31_D_8006E524 __asm__("D_8006E524");
extern unsigned char Raw31Union[] __asm__("D_80070328+0x144");
extern int Raw31Movement __asm__("D_80070328+0x50");
int Squish31Call(int,int,int) __asm__("PlaySound");
void func_level_31_8008DEC0(int selector) {
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register int oldMovementC __asm__("$5");
    register int oldMovement __asm__("$4");
    register int shiftedZ __asm__("$2");
    register int tableByteOffset __asm__("$3");
    unsigned char *private88;
    unsigned char *private89;
    unsigned char *private8A;

    switch (selector) {
    case 0x14:
        Callback31_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback31_D_80070328.unk5 = 0;
        Callback31_func_800441F0();
        Callback31_D_80070328.grounded = 1;
        Callback31_D_80070328.union144.a.unk13cb = Callback31_func_8003636C(1, 3);
        Callback31_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0xA:
    case 0xB:
    case 0xC:
        Callback31_D_80070328.movementState = MOVEMENT_STATE_ICE_SKATE;
        Callback31_D_80070328.unk5 = 0;
        Callback31_D_80070328.unk8[0] = Callback31_func_8004EDE8((Vector3D *) ((unsigned char*)&Callback31_D_80070328.movementState + 0x48), 0);
        Callback31_func_80043A38(0xC00);
        Callback31_D_80070328.grounded = 1;
        goto clearPointers;
    case 0x1D: {
        register int component __asm__("$3");
        register int word __asm__("$2");
        oldMovement=Raw31Movement;
        component=Callback31_D_80070328.unk17e.x;
        __asm__("" : "=r"(oldMovement), "=r"(component) : "0"(oldMovement), "1"(component));
        word=7;
        Raw31Movement=word;
        word=Callback31_D_80070328.unk17e.y;
        Callback31_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(component), "=r"(word) : "0"(component), "1"(word) : "memory");
        component<<=6;
        Callback31_D_80070328.unk7a[2].x=component;
        component=Callback31_D_80070328.unk17e.z;
        __asm__ volatile("" : "=r"(word) : "0"(word) : "memory");
        word<<=6;
        __asm__("" : "=r"(word) : "0"(word));
        *(int*)Raw31Union=oldMovement;
        Callback31_D_80070328.unk7a[2].y=word;
        shiftedZ=component<<6;
        if(component==0)shiftedZ=Callback31_D_80070328.unk7a[3].z;
        Callback31_D_80070328.unk7a[2].z=shiftedZ;
        Callback31_func_80043A38(0xC00);
        Callback31_D_80070328.grounded = 1;
        Callback31_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        PlaySound((int) D_8006C654->spyroHurt, 0, 0);
        goto clearPointers;
    }
    case 0x1A:
        savedBase = Raw31Union;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        oldMovementC = Raw31Movement;
        Raw31Movement = MOVEMENT_STATE_HURT;
        Callback31_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementC;
        Callback31_func_8004F168(destination);
        Callback31_D_80070328.grounded = 1;
        Callback31_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        Squish31Call((int) D_8006C654->squish, 0, 0);
        goto clearPointers;
    case 0x20:
        Callback31_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Callback31_D_80070328.unk5 = 0;
        Callback31_func_80043A38(0xC00);
        Callback31_D_80070328.grounded = 1;
        if ((selector == 0x3A) || (selector == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Callback31_D_8006E524 = 0xF;
clearPointers:
        Callback31_D_80070328.unk20a = 0;
        Callback31_D_80070328.critterMobyPtr = 0;
        return;
    case 0x87:
    case 0x8B:
    case 0x93:
        Callback31_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback31_D_80070328.unk5 = 0;
        {register int callResult __asm__("$2")=Transition31Call441F0();
        __asm__ volatile("" : : "r"(callResult) : "$4");}
        goto markGrounded;
    default:
        return;
    case 0x8E:
    case 0x8F:
    case 0x90:
    case 0x91:
        Callback31_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((selector == 0x57) && (Callback31_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((unsigned char*)&Callback31_D_80070328.movementState + 0x3C), (Vector3D *) ((unsigned char*)&Callback31_D_80070328.movementState + 0x48));
            Callback31_D_80070328.unk5 = 1;
        } else {
            Callback31_D_80070328.unk5 = 0;
        }
        Callback31_D_80070328.unk8[0] = Callback31_func_8004EDE8(&Callback31_D_80070328.unk7a[3], 0);
        Callback31_func_80043A38(0xC00);
        Callback31_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Callback31_D_80070328.grounded = 1;
        Callback31_D_80070328.idle = 0;
        Callback31_D_80070328.unk15g = 0;
        return;
    case 0x88:
        private88 = Callback31_D_80070328.critterMobyPtr->mobyTag;
        *(int*)(private88 + 0x28) = (int) (*(int*)(private88 + 0x28) - 0xF);
        {register int zeroResult __asm__("$2")=Transition31Zero((Vector3D*)(private88 + 0x3C));
        __asm__ volatile("" : : "r"(zeroResult) : "$5");}
        Callback31_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback31_D_80070328.unk5 = 0;
        {register int callResult __asm__("$2")=Transition31Call441F0();
        __asm__ volatile("" : : "r"(callResult) : "$5");}
        goto markGrounded;
    case 0x89:
        private89 = Callback31_D_80070328.critterMobyPtr->mobyTag;
        *(int*)(private89 + 0x28) = (int) (*(int*)(private89 + 0x28) - 0x1E);
        {register int zeroResult __asm__("$2")=Transition31Zero((Vector3D*)(private89 + 0x3C));
        __asm__ volatile("" : : "r"(zeroResult) : "$6");}
        Callback31_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback31_D_80070328.unk5 = 0;
        {register int callResult __asm__("$2")=Transition31Call441F0();
        __asm__ volatile("" : : "r"(callResult) : "$6");}
        goto markGrounded;
    case 0x8A:
        private8A = Callback31_D_80070328.critterMobyPtr->mobyTag;
        *(int*)(private8A + 0x28) = (int) (*(int*)(private8A + 0x28) - 0x14);
        {register int zeroResult __asm__("$2")=Transition31Zero((Vector3D*)(private8A + 0x3C));
        __asm__ volatile("" : : "r"(zeroResult) : "$7");}
        Callback31_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback31_D_80070328.unk5 = 0;
        {register int callResult __asm__("$2")=Transition31Call441F0();
        __asm__ volatile("" : : "r"(callResult) : "$7");}
        goto markGrounded;
    case 0x8C:
    case 0x8D:
        Callback31_D_80070328.movementState = MOVEMENT_STATE_HURT;
        Callback31_D_80070328.unk5 = 0;
        Callback31_func_800441F0();
        tableByteOffset = Callback31_D_80070328.unk22[5] * 2;
        if (Callback31_D_80070328.unk22[5] < 0) {
            {register int yaw __asm__("$2")=Callback31_D_80070328.bodyRotation.yaw;
            __asm__("" : "=r"(yaw) : "0"(yaw));
            yaw += 0x80;
            yaw &= 0xFF;
            tableByteOffset=yaw<<1;}
        }
        Callback31_D_80070328.unk7a[1].x = (int) *(short*)((unsigned char*)Callback31_D_80065920 + tableByteOffset);
        {register int sample __asm__("$2")=*(short*)((unsigned char*)Callback31_D_800658A0 + tableByteOffset);
        __asm__ volatile("" : "=r"(sample) : "0"(sample) : "memory");
        Callback31_D_80070328.unk7a[1].z=0;
        Callback31_D_80070328.unk7a[1].y=sample;}
        Callback31_func_80043A38(0xC00);
        Callback31_D_80070328.grounded = 1;
        Callback31_D_8006E524 = 0xF;
        return;
    case 0x92:
        Callback31_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Callback31_D_80070328.unk5 = 0;
        Callback31_func_80043A38(0xC00);
markGrounded:
        Callback31_D_80070328.grounded = 1;
        return;
    }
}


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008E3C8.
 * Assembly SHA256 535d992eb3ea119f2c5667615221a5481aadcf0c8305bc454017bee7287f7ae8.
 * AI generated; not human reviewed. All 1095 original instructions and 138
 * selector words (bias 10, no padding) are required. Original frame 0x20
 * preserves saved S0/S1 and RA. Common state C uses the verified level12
 * baseline; 135..147 retain original branches and shared transition tails.
 * Context reloads at 8008EB80/8008EE74 remain independent before the original
 * shared byte store 8008EE80. The final 146 path retains every original
 * argument producer and the shared 147 epilogue. Numeric states are unnamed.
 * Resident transition helper takes A0 only; original dominating A1 write at
 * 8004BF54 precedes its first A1 read. The explicit original A1 zero producer
 * in state 26 is retained. Indirect callbacks keep their actual arguments.
 * Typed symbol views remain distinct. Initialized empty constraints and
 * original-address metadata emit zero CPU instructions. Frozen C tools emit
 * every original CPU word; no instruction assembly or opcode patching.
 * Physical units/fixed point, complete helper contracts and caller rate are
 * unresolved; cadence is per invocation. Falsification requires every native
 * and linked instruction, actual conditional/internal target, selector/data
 * word and the complete EXE/every-overlay retail hashes. Binary identity does
 * not establish synchronized runtime or system completeness. */
int Anim31CallPlaySoundView1() __asm__("PlaySound");
int Anim31Call3B7B4View1() __asm__("func_8003B7B4");
int Anim31Call4BEF8View1() __asm__("func_8004BEF8");
int Anim31Call4EF04View1() __asm__("func_8004EF04");
int Anim31Call4F1C8View1() __asm__("func_8004F1C8");
int Anim31Call55E84View1() __asm__("func_80055E84");
extern int Anim31Data6C550View1 __asm__("D_8006C550");
extern void * Anim31Data6C654View1 __asm__("D_8006C654");
extern unsigned char Anim31Data6C7F8View1 __asm__("D_8006C7F8");
extern int Anim31Data6E538View1 __asm__("D_8006E538");
extern int Anim31Data6E53CView1 __asm__("D_8006E53C");
extern unsigned char Anim31Player0View1 __asm__("D_80070328");
extern int Anim31Data7203CView1 __asm__("D_8007203C");
extern int Anim31Data72040View1 __asm__("D_80072040");
extern int (*Anim31OverlayCallbackView1)() __asm__("unk_ovlheader_8007431C");
extern int Anim31Player48View1 __asm__("D_80070328 + 0x48");
extern int Anim31Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim31PlayerA8View1 __asm__("D_80070328 + 0xA8");
extern int Anim31PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim31PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim31PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern int Anim31Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim31Player1ECView1 __asm__("D_80070328 + 0x1EC");
extern int Anim31Player1F0View1 __asm__("D_80070328 + 0x1F0");
extern int Anim31Player240View1 __asm__("D_80070328 + 0x240");
extern int Anim31Player280View1 __asm__("D_80070328 + 0x280");
extern unsigned char Anim31Player14View1 __asm__("D_80070328 + 0x14");
extern unsigned char Anim31Player15View1 __asm__("D_80070328 + 0x15");
extern unsigned char Anim31Player16View1 __asm__("D_80070328 + 0x16");
extern unsigned char Anim31Player17View1 __asm__("D_80070328 + 0x17");
extern unsigned char Anim31PlayerFCView1 __asm__("D_80070328 + 0xFC");
extern unsigned char Anim31Data66530View1[] __asm__("D_80066530");
extern int Anim31Data6E538View2 __asm__("D_8006E538"), Anim31Data6E53CView2 __asm__("D_8006E53C");
extern int Anim31Data6E044View1 __asm__("D_8006E044"), Anim31Data6E344View1 __asm__("D_8006E344"), Anim31Data6C514View1 __asm__("D_8006C514");
extern int Anim31Player24View1 __asm__("D_80070328 + 0x24");
int Anim31Call40994View1() __asm__("func_80040994");
int Anim31Call4BEF8View2() __asm__("func_8004BEF8");
int Anim31Call49688View1() __asm__("func_80049688");
int Anim31Call498C0View1() __asm__("func_800498C0");
extern unsigned char Anim31Data6E535View1 __asm__("D_8006E535");
int Anim31Call40954View1() __asm__("func_80040954");
extern int Anim31Player10CView1 __asm__("D_80070328 + 0x10C");
extern int Anim31PlayerB4View1 __asm__("D_80070328 + 0xB4");
extern void* Anim31Player250View1 __asm__("D_80070328 + 0x250");
extern int Anim31Player48View2 __asm__("D_80070328 + 0x48");
extern int Anim31PlayerACView2 __asm__("D_80070328 + 0xAC");
extern int Anim31PlayerA4View1 __asm__("D_80070328 + 0xA4");
extern int Anim31Player24View2 __asm__("D_80070328 + 0x24");
#define Anim31Field(p, t, o) (*(t)((unsigned char*)(p)+(o)))
void func_level_31_8008E3C8(void) {
    register int rawValue2 __asm__("$2");
    register int rawValue3 __asm__("$3");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register int argument6 __asm__("$6");
    register int* statePointer16 __asm__("$16");
    register void* savedPointer16 __asm__("$16");
    register void* savedPointer17 __asm__("$17");
    rawValue2 = Anim31Player48View2;
    switch (rawValue2) {
    case 20:
        if (Anim31Call40994View1())return;
        if (Anim31Data6E53CView2&0x40) {
            Anim31Call4BEF8View2(6);
            return;
        }
        if (Anim31PlayerB8View1 >= 4 || Anim31PlayerE4View1 >= 23)goto set7;
        rawValue3 = Anim31Data6E538View2;
        if (rawValue3&0x80) {
            Anim31Call4BEF8View2(13);
            return;
        }
        rawValue2 = Anim31PlayerA8View1;
        if (rawValue2 < 0)rawValue2 = -rawValue2;
        if (rawValue2 >= 17)goto set1;
        rawValue2 = rawValue3&12;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2));
        if (!rawValue2 && Anim31PlayerACView1)goto set1;
        if (Anim31Data6E044View1 == 7 || Anim31Player240View1) {
            statePointer16 = &Anim31Player48View1;
            __asm__("" : "=r"(statePointer16):"0"(statePointer16));
            if (!*statePointer16)return;
            Anim31Call4BEF8View2(0);
            if (Anim31Data66530View1[*((unsigned char*)statePointer16-0x2C)] >= 96) {
                Anim31Player14View1 = Anim31Player15View1;
                Anim31Player16View1 = Anim31Player17View1;
            }
            Anim31Player17View1 = 0;
            rawValue3 = *statePointer16;
            rawValue2 = 113;
            *((unsigned char*)statePointer16-0x2C) = rawValue2;
            Anim31Player1F0View1 = 0;
            Anim31Player15View1 = rawValue3;
            Anim31Player1ECView1 = rawValue3;
            return;
        }
        if (Anim31PlayerFCView1) {
            Anim31Call4BEF8View2(15);
            return;
        }
        Anim31Call49688View1();
        return;
    case 10:
        if (Anim31Call40994View1())return;
        if (Anim31PlayerB8View1 >= 4 || Anim31PlayerE4View1 >= 23)goto set7;
        rawValue2 = Anim31Call40954View1(Anim31Player10CView1);
        rawValue3 = 4;
        if (rawValue2 != rawValue3)goto set1;
        rawValue3 = Anim31Data6E044View1;
        rawValue2 = 7;
        if (rawValue3 == rawValue2)return;
        if (!Anim31Data6E535View1)goto set11;
        if (Anim31PlayerB4View1 >= 2305)goto set12;
        return;
    case 11:
        if (Anim31Call40994View1())return;
        if (Anim31PlayerB8View1 >= 4 || Anim31PlayerE4View1 >= 23)goto set7;
        rawValue2 = Anim31Call40954View1(Anim31Player10CView1);
        rawValue3 = 4;
        if (rawValue2 != rawValue3)goto set1;
        if (!Anim31Data6E535View1)return;
        if (Anim31PlayerB4View1 < 2305)goto set10;
        set12:Anim31Call4BEF8View2(12);
        return;
    case 12:
        if (Anim31Call40994View1())return;
        if (Anim31PlayerB8View1 >= 4 || Anim31PlayerE4View1 >= 23)goto set7;
        rawValue2 = Anim31Call40954View1(Anim31Player10CView1);
        rawValue3 = 4;
        if (rawValue2 != rawValue3) {
            set1:Anim31Call4BEF8View2(1);
            return;
        }
        if (!Anim31Data6E535View1) {
            set11:Anim31Call4BEF8View2(11);
            return;
        }
        if (Anim31PlayerB4View1 >= 1536)return;
        set10:Anim31Call4BEF8View2(10);
        return;
    case 29:
        if (Anim31Player54View1 < 25)return;
        if (Anim31Player280View1 < 0) {
            Anim31Call4BEF8View2(31);
            return;
        }
        rawValue3 = Anim31Player144View1;
        if (rawValue3 == 10)goto set44;
        rawValue2 = rawValue3-11;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2));
        if ((unsigned int)rawValue2 < 2)goto set41;
        if (!Anim31PlayerB8View1)goto set0;
        __asm__ volatile("" ::: "memory");
        goto set7;
    case 26:
        if (Anim31Player24View1&16)return;
        if (Anim31Player54View1 < 25)return;
        if (Anim31Player280View1 < 0) {
            argument5 = 0;
            __asm__ volatile("" : "=r"(argument5):"0"(argument5));
            Anim31Call4BEF8View2(32);
            return;
        }
        Anim31CallPlaySoundView1(Anim31Field(Anim31Data6C654View1, unsigned char*, 15), 0, 0);
        rawValue3 = Anim31Player144View1;
        rawValue2 = 10;
        if (rawValue3 == rawValue2) {
            set44:Anim31Call4BEF8View2(44);
            return;
        }
        rawValue2 = rawValue3-11;
        if ((unsigned int)rawValue2 < 2) {
            set41:Anim31Call4BEF8View2(41);
            return;
        }
        if (Anim31PlayerB8View1) {
            set7:Anim31Call4BEF8View2(7);
            return;
        }
        set0:Anim31Call4BEF8View2(0);
        return;
    case 32:
        if (Anim31Player54View1 < 125)return;
        Anim31Call498C0View1();
        return;
    case 135:
        rawValue2 = (int)Anim31Player250View1;
        savedPointer17 = Anim31Field((void*)rawValue2, void**, 0);
        rawValue3 = Anim31Field(savedPointer17, int*, 0x2C);
        rawValue2 = rawValue3*88;
        rawValue3 = Anim31Data6C550View1;
        rawValue2 += rawValue3;
        rawValue3 = Anim31Field((void*)rawValue2, unsigned char*, 0x48);
        rawValue2 = 17;
        if (rawValue3 == rawValue2)goto set147;
        rawValue2 = (int)Anim31OverlayCallbackView1;
        if (((int(*)())rawValue2)(3))return;
        rawValue2 = Anim31Data6E53CView1;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2):"memory");
        rawValue2 &= 128;
        if (rawValue2) {
            rawValue2 = Anim31Field(savedPointer17, int*, 0x28) < 15;
            if (!rawValue2)goto set136;
        }
        rawValue2 = Anim31Data6E53CView1;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2):"memory");
        rawValue2 &= 64;
        if (rawValue2) {
            rawValue2 = Anim31Field(savedPointer17, int*, 0x28) < 20;
            if (!rawValue2)goto set138;
        }
        rawValue2 = Anim31Data6E53CView1;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2):"memory");
        rawValue2 &= 32;
        if (rawValue2) {
            rawValue2 = Anim31Field(savedPointer17, int*, 0x28) < 30;
            if (!rawValue2)goto set137;
        }
        rawValue2 = Anim31Data6E538View1&16;
        if (rawValue2)goto set139;
        argument5 = (int)&Anim31PlayerACView2;
        __asm__("" : "=r"(argument5):"0"(argument5));
        rawValue2 = Anim31Field((void*)argument5, int*, 0);
        if (!rawValue2)goto readFlags135;
        rawValue2 = Anim31PlayerA4View1;
        rawValue2 -= 512;
        rawValue3 = rawValue2&4095;
        rawValue2 = rawValue3 < 1024;
        if (rawValue2)goto set142;
        rawValue2 = rawValue3-1024;
        if ((unsigned)rawValue2 < 1024)goto set145;
        rawValue2 = rawValue3-2048;
        if ((unsigned)rawValue2 < 1024)goto set143;
        rawValue2 = rawValue3 < 3072;
        if (!rawValue2)goto set144;
        __asm__ volatile("" : : "i"(0x8008EA98) : "memory");
        return;
        readFlags135:rawValue2 = Anim31Player24View2&4;
        goto consumeFlags;
    case 136:
        rawValue2 = (int)Anim31Player250View1;
        rawValue2 = Anim31Field((void*)rawValue2, int*, 0);
        rawValue3 = Anim31Field((void*)rawValue2, int*, 0x2C);
        rawValue2 = rawValue3*88;
        rawValue3 = Anim31Data6C550View1;
        rawValue2 += rawValue3;
        rawValue3 = Anim31Field((void*)rawValue2, unsigned char*, 0x48);
        rawValue2 = 17;
        if (rawValue3 == rawValue2)goto set147;
        rawValue2 = (int)Anim31OverlayCallbackView1;
        if (((int(*)())rawValue2)(7))return;
        rawValue2 = Anim31Call55E84View1(Anim31Player250View1);
        rawValue2 = rawValue2 < 8;
        if (rawValue2)goto checkSelector136;
        rawValue2 = Anim31Data6E53CView1;
        rawValue3 = (int)Anim31Player250View1;
        rawValue2 &= 128;
        rawValue3 = Anim31Field((void*)rawValue3, int*, 0);
        if (rawValue2) {
            rawValue2 = Anim31Field((void*)rawValue3, int*, 0x28) < 15;
            if (!rawValue2) {
                Anim31Call4BEF8View1(136);
                rawValue3 = (int)Anim31Player250View1;
                rawValue2 = 114;
                Anim31Field((void*)rawValue3, signed char*, 0x40) = rawValue2;
                __asm__ volatile("" : "=r"(rawValue3) : "0"(rawValue3), "i"(0x8008EB80) : "memory");
                rawValue3 = (int)Anim31Player250View1;
                __asm__ volatile("" : "=r"(rawValue3) : "0"(rawValue3), "i"(0x8008EB88) : "$2", "memory");
                rawValue2 = 1;
                goto storeContext3D;
            }
        }
        rawValue2 = Anim31Data6E538View1;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2):"memory");
        rawValue2 &= 64;
        if (rawValue2) {
            rawValue2 = Anim31Field((void*)rawValue3, int*, 0x28) < 20;
            if (!rawValue2)goto set138;
        }
        rawValue2 = Anim31Data6E538View1&32;
        if (!rawValue2)return;
        rawValue2 = Anim31Field((void*)rawValue3, int*, 0x28) < 30;
        if (!rawValue2)goto set137;
        __asm__ volatile("" : : "i"(0x8008EBE8) : "memory");
        return;
    checkSelector136:
        argument4 = (int)Anim31Player250View1;
        rawValue2 = Anim31Player48View2;
        rawValue3 = Anim31Field((void*)argument4, unsigned char*, 0x3C);
        rawValue2 -= 135;
        if (rawValue3 != rawValue2)return;
        rawValue2 = Anim31Field((void*)argument4, unsigned char*, 0x42)&2;
        if (!rawValue2)return;
        rawValue2 = Anim31PlayerACView2;
        if (!rawValue2)goto set135;
        rawValue2 = Anim31PlayerA4View1;
        rawValue2 -= 512;
        rawValue3 = rawValue2&4095;
        rawValue2 = rawValue3 < 1024;
        if (rawValue2)goto set142;
        rawValue2 = rawValue3-1024;
        if ((unsigned)rawValue2 < 1024)goto set145;
        rawValue2 = rawValue3-2048;
        if ((unsigned)rawValue2 < 1024)goto set143;
        rawValue2 = rawValue3 < 3072;
        if (!rawValue2)goto set144;
        __asm__ volatile("" : : "i"(0x8008EC78) : "memory");
        return;
    case 137:
        rawValue2 = (int)Anim31Player250View1;
        rawValue2 = Anim31Field((void*)rawValue2, int*, 0);
        rawValue3 = Anim31Field((void*)rawValue2, int*, 0x2C);
        rawValue2 = rawValue3*88;
        rawValue3 = Anim31Data6C550View1;
        rawValue2 += rawValue3;
        rawValue3 = Anim31Field((void*)rawValue2, unsigned char*, 0x48);
        rawValue2 = 17;
        if (rawValue3 == rawValue2)goto set147;
        rawValue2 = (int)Anim31OverlayCallbackView1;
        if (((int(*)())rawValue2)(7))return;
        argument4 = (int)Anim31Player250View1;
        rawValue2 = Anim31Player48View2;
        rawValue3 = Anim31Field((void*)argument4, unsigned char*, 0x3C);
        rawValue2 -= 135;
        if (rawValue3 != rawValue2)return;
        rawValue2 = Anim31Field((void*)argument4, unsigned char*, 0x42)&2;
        if (!rawValue2)return;
        rawValue2 = Anim31PlayerACView2;
        if (!rawValue2)goto set135;
        rawValue2 = Anim31PlayerA4View1;
        rawValue2 -= 512;
        rawValue3 = rawValue2&4095;
        rawValue2 = rawValue3 < 1024;
        if (rawValue2)goto set142;
        rawValue2 = rawValue3-1024;
        if ((unsigned)rawValue2 < 1024)goto set145;
        rawValue2 = rawValue3-2048;
        if ((unsigned)rawValue2 < 1024)goto set143;
        rawValue2 = rawValue3 < 3072;
        if (!rawValue2)goto set144;
        __asm__ volatile("" : : "i"(0x8008ED70) : "memory");
        return;
    case 138:
        rawValue2 = (int)Anim31Player250View1;
        rawValue2 = Anim31Field((void*)rawValue2, int*, 0);
        rawValue3 = Anim31Field((void*)rawValue2, int*, 0x2C);
        rawValue2 = rawValue3*88;
        rawValue3 = Anim31Data6C550View1;
        rawValue2 += rawValue3;
        rawValue3 = Anim31Field((void*)rawValue2, unsigned char*, 0x48);
        rawValue2 = 17;
        if (rawValue3 == rawValue2)goto set147;
        rawValue2 = (int)Anim31OverlayCallbackView1;
        if (((int(*)())rawValue2)(7))return;
        rawValue2 = Anim31Call55E84View1(Anim31Player250View1);
        rawValue2 = rawValue2 < 10;
        if (rawValue2)goto checkSelector138;
        rawValue2 = Anim31Data6E538View1;
        rawValue3 = (int)Anim31Player250View1;
        rawValue2 &= 128;
        rawValue3 = Anim31Field((void*)rawValue3, int*, 0);
        if (rawValue2) {
            rawValue2 = Anim31Field((void*)rawValue3, int*, 0x28) < 15;
            if (!rawValue2)goto set136;
        }
        rawValue2 = Anim31Data6E53CView1;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2):"memory");
        rawValue2 &= 64;
        if (rawValue2) {
            rawValue2 = Anim31Field((void*)rawValue3, int*, 0x28) < 20;
            if (!rawValue2) {
                Anim31Call4BEF8View1(138);
                rawValue3 = (int)Anim31Player250View1;
                rawValue2 = 114;
                Anim31Field((void*)rawValue3, signed char*, 0x40) = rawValue2;
                __asm__ volatile("" : : "i"(0x8008EE74) : "memory");
                rawValue3 = (int)Anim31Player250View1;
                __asm__ volatile("" : "=r"(rawValue3) : "0"(rawValue3), "i"(0x8008EE7C) : "$2", "memory");
                rawValue2 = 3;
                storeContext3D:__asm__ volatile("" : : "i"(0x8008EE80) : "memory");
                Anim31Field((void*)rawValue3, signed char*, 0x3D) = rawValue2;
                rawValue2 = (int)Anim31Player250View1;
                Anim31Field((void*)rawValue2, signed char*, 0x3F) = 0;
                return;
            }
        }
        rawValue2 = Anim31Data6E538View1&32;
        if (!rawValue2)return;
        rawValue2 = Anim31Field((void*)rawValue3, int*, 0x28) < 30;
        if (!rawValue2)goto set137;
        return;
    checkSelector138:
        argument4 = (int)Anim31Player250View1;
        rawValue2 = Anim31Player48View2;
        rawValue3 = Anim31Field((void*)argument4, unsigned char*, 0x3C);
        rawValue2 -= 135;
        if (rawValue3 != rawValue2)return;
        rawValue2 = Anim31Field((void*)argument4, unsigned char*, 0x42)&2;
        if (!rawValue2)return;
        rawValue2 = Anim31PlayerACView2;
        if (!rawValue2)goto set135;
        rawValue2 = Anim31PlayerA4View1;
        rawValue2 -= 512;
        rawValue3 = rawValue2&4095;
        rawValue2 = rawValue3 < 1024;
        if (rawValue2)goto set142;
        rawValue2 = rawValue3-1024;
        if ((unsigned)rawValue2 < 1024)goto set145;
        rawValue2 = rawValue3-2048;
        if ((unsigned)rawValue2 < 1024)goto set143;
        rawValue2 = rawValue3 < 3072;
        if (!rawValue2)goto set144;
        __asm__ volatile("" : : "i"(0x8008EF50) : "memory");
        return;
    case 139:
        argument5 = (int)Anim31Player250View1;
        savedPointer17 = Anim31Field((void*)argument5, void**, 0);
        rawValue3 = Anim31Field(savedPointer17, int*, 0x2C);
        rawValue2 = rawValue3*88;
        rawValue3 = Anim31Data6C550View1;
        rawValue2 += rawValue3;
        rawValue3 = Anim31Field((void*)rawValue2, unsigned char*, 0x48);
        rawValue2 = 17;
        if (rawValue3 == rawValue2)goto set147;
        rawValue2 = Anim31Player48View2;
        rawValue3 = Anim31Field((void*)argument5, unsigned char*, 0x3C);
        rawValue2 -= 135;
        argument4 = 4;
        if (rawValue3 != rawValue2)argument4 = 3;
        rawValue2 = (int)Anim31OverlayCallbackView1;
        if (((int(*)())rawValue2)(argument4, (void*)argument5))return;
        rawValue2 = Anim31Data6E53CView1;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2):"memory");
        rawValue2 &= 128;
        if (rawValue2) {
            rawValue2 = Anim31Field(savedPointer17, int*, 0x28) < 15;
            if (!rawValue2)goto set136;
        }
        rawValue2 = Anim31Data6E53CView1;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2):"memory");
        rawValue2 &= 64;
        if (rawValue2) {
            rawValue2 = Anim31Field(savedPointer17, int*, 0x28) < 20;
            if (!rawValue2)goto set138;
        }
        rawValue2 = Anim31Data6E53CView1;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2):"memory");
        rawValue2 &= 32;
        if (rawValue2) {
            rawValue2 = Anim31Field(savedPointer17, int*, 0x28) < 30;
            if (!rawValue2)goto set137;
        }
        rawValue2 = Anim31Data6E538View1&16;
        if (rawValue2)goto readFlags139;
        rawValue2 = Anim31PlayerACView2;
        if (!rawValue2)goto set135;
        rawValue2 = Anim31PlayerA4View1;
        rawValue2 -= 512;
        rawValue3 = rawValue2&4095;
        rawValue2 = rawValue3 < 1024;
        if (rawValue2)goto set142;
        rawValue2 = rawValue3-1024;
        if ((unsigned)rawValue2 < 1024)goto set145;
        rawValue2 = rawValue3-2048;
        if ((unsigned)rawValue2 < 1024)goto set143;
        rawValue2 = rawValue3 < 3072;
        if (!rawValue2)goto set144;
        __asm__ volatile("" : : "i"(0x8008F0CC) : "memory");
        return;
    readFlags139:
        argument5 = (int)&Anim31Player24View2;
        __asm__("" : "=r"(argument5):"0"(argument5));
        rawValue2 = Anim31Field((void*)argument5, int*, 0)&3;
    consumeFlags:
        if (!rawValue2)return;
        savedPointer16 = &Anim31Player0View1+0x80;
        __asm__("" : "=r"(savedPointer16):"0"(savedPointer16));
        argument4 = (int)savedPointer16;
        argument5 = (int)&Anim31Player0View1;
        rawValue3 = Anim31Field(savedPointer17, int*, 0x2C);
        argument6 = Anim31Data6C550View1;
        rawValue2 = rawValue3*88;
        argument6 += rawValue2;
        Anim31Call4F1C8View1((void*)argument4, (void*)argument5, argument6+12);
        Anim31Call4EF04View1(savedPointer16, 2560);
        rawValue2 = 120;
        Anim31Data72040View1 = rawValue2;
        rawValue2 = 10;
        Anim31Data7203CView1 = rawValue2;
        return;
    case 142:case 143:case 144:case 145:
        rawValue2 = (int)Anim31Player250View1;
        savedPointer16 = Anim31Field((void*)rawValue2, void**, 0);
        rawValue3 = Anim31Field(savedPointer16, int*, 0x2C);
        rawValue2 = rawValue3*88;
        rawValue3 = Anim31Data6C550View1;
        rawValue2 += rawValue3;
        rawValue3 = Anim31Field((void*)rawValue2, unsigned char*, 0x48);
        rawValue2 = 17;
        if (rawValue3 == rawValue2)goto set147;
        rawValue2 = (int)Anim31OverlayCallbackView1;
        if (((int(*)())rawValue2)(7))return;
        rawValue2 = Anim31Data6E53CView1;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2):"memory");
        rawValue2 &= 128;
        if (rawValue2) {
            rawValue2 = Anim31Field(savedPointer16, int*, 0x28) < 15;
            if (!rawValue2) {
                set136:Anim31Call4BEF8View1(136);
                return;
            }
        }
        rawValue2 = Anim31Data6E53CView1;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2):"memory");
        rawValue2 &= 64;
        if (rawValue2) {
            rawValue2 = Anim31Field(savedPointer16, int*, 0x28) < 20;
            if (!rawValue2) {
                set138:Anim31Call4BEF8View1(138);
                return;
            }
        }
        rawValue2 = Anim31Data6E53CView1;
        __asm__("" : "=r"(rawValue2):"0"(rawValue2):"memory");
        rawValue2 &= 32;
        if (rawValue2) {
            rawValue2 = Anim31Field(savedPointer16, int*, 0x28) < 30;
            if (!rawValue2) {
                set137:Anim31Call4BEF8View1(137);
                return;
            }
        }
        rawValue2 = Anim31Data6E538View1&16;
        if (rawValue2) {
            set139:Anim31Call4BEF8View1(139);
            return;
        }
        rawValue2 = Anim31PlayerACView2;
        if (!rawValue2) {
            argument4 = (int)Anim31Player250View1;
            rawValue2 = Anim31Player48View2;
            rawValue3 = Anim31Field((void*)argument4, unsigned char*, 0x3C);
            rawValue2 -= 135;
            if (rawValue3 == rawValue2) {
                rawValue2 = Anim31Field((void*)argument4, unsigned char*, 0x42)&2;
                if (rawValue2)goto set135;
            }
        }
        rawValue2 = Anim31PlayerA4View1;
        rawValue2 -= 512;
        argument4 = rawValue2&4095;
        rawValue2 = argument4 < 1024;
        if (rawValue2) {
            rawValue3 = Anim31Player48View2;
            rawValue2 = 142;
            if (rawValue3 != rawValue2) {
                set142:Anim31Call4BEF8View1(142);
                return;
            }
        }
        rawValue2 = argument4-1024;
        if ((unsigned)rawValue2 < 1024) {
            rawValue3 = Anim31Player48View2;
            rawValue2 = 145;
            if (rawValue3 != rawValue2) {
                set145:Anim31Call4BEF8View1(145);
                return;
            }
        }
        rawValue2 = argument4-2048;
        if ((unsigned)rawValue2 < 1024) {
            rawValue3 = Anim31Player48View2;
            rawValue2 = 143;
            if (rawValue3 != rawValue2) {
                set143:Anim31Call4BEF8View1(143);
                return;
            }
        }
        rawValue2 = argument4 < 3072;
        if (rawValue2)return;
        rawValue3 = Anim31Player48View2;
        rawValue2 = 144;
        if (rawValue3 == rawValue2)return;
        set144:Anim31Call4BEF8View1(144);
        return;
    case 140:case 141:
        argument4 = (int)Anim31Player250View1;
        argument5 = Anim31Field((void*)argument4, int*, 0);
        rawValue3 = Anim31Field((void*)argument5, int*, 0x2C);
        rawValue2 = rawValue3*88;
        rawValue3 = Anim31Data6C550View1;
        rawValue2 += rawValue3;
        rawValue3 = Anim31Field((void*)rawValue2, unsigned char*, 0x48);
        rawValue2 = 17;
        if (rawValue3 == rawValue2) {
            set147:Anim31Call4BEF8View1(147);
            return;
        }
        rawValue2 = Anim31Player48View2;
        rawValue3 = Anim31Field((void*)argument4, unsigned char*, 0x3C);
        rawValue2 -= 135;
        if (rawValue3 != rawValue2)return;
        rawValue2 = Anim31Field((void*)argument4, unsigned char*, 0x42)&2;
        if (!rawValue2)return;
        rawValue2 = Anim31Field((void*)argument5, int*, 0x24);
        if (rawValue2 > 0)goto set135;
        Anim31Call4BEF8View1(146);
        return;
        set135:Anim31Call4BEF8View1(135);
        return;
    case 146:
        argument4 = (int)Anim31Player250View1;
        rawValue2 = Anim31Player48View2;
        rawValue3 = Anim31Field((void*)argument4, unsigned char*, 0x3C);
        rawValue2 -= 135;
        if (rawValue3 != rawValue2)return;
        rawValue2 = Anim31Field((void*)argument4, unsigned char*, 0x42)&2;
        argument5 = 4;
        if (!rawValue2)return;
        argument6 = (int)&Anim31Data6C7F8View1;
        __asm__ volatile("" : "=r"(argument6) : "0"(argument6) : "$2", "$3", "memory");
        rawValue3 = Anim31Field((void*)argument4, int*, 0);
        rawValue2 = -1;
        argument4 = rawValue3+0x24;
        Anim31Field((void*)rawValue3, int*, 0x24) = rawValue2;
        Anim31Call3B7B4View1((void*)argument4, argument5, (void*)argument6);
    case 147:
        __asm__ volatile("" : : "i"(0x8008F4CC) : "memory");
        return;
        default:return;
    }
}
#undef Anim31Field
