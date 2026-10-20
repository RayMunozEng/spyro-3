extern unsigned char Raw36State[] __asm__("D_80070328+0x50");
#include "common.h"
#include "ovl_header.h"
#include "drawutil.h"
#include "spu.h"
#include "hud.h"
#include "mobyutil.h"
#include "stdutil.h"
#include "camera.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80084060.
 * Assembly SHA256 476137ee94d52f217533ae60032b636210784a1ea7dc7b8f865512f0100e5190.
 * AI-generated; not human reviewed. All810 original instructions,
 * 13 selectors bias85 and 1 owned padding words are required.
 * Original frame0x78; every concrete field width and producer is retained.
 * Five aligned references and three complete87/89/95 bodies retain the
 * original85..97 Bentley family. Frame scratch10..5C,savedS0..S3,combinedS3,
 * incomingA0 prefix,all heading-selection and relative-store lifetimes remain.
 * All product7 results are initialized by original MULT. Original86's A2
 * producer,87/93's separate subtract paths,95 scalar/vector joins and90's
 * shared clamp/store target80084CE4 remain exact. Every actual target is required.
 * Identified Rev1 Bentley update/orientation/input-owner decoders are recorded
 * as cross-references. Raw Rev0 instructions and full hashes stay authoritative.
 * Typed aliases stay distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit words.
 * Raw units/fixed point, helper contracts and caller rate remain unresolved.
 * Cadence is per invocation. Falsification: every native/linked instruction,
 * actual internal/conditional target,selector/data word and full EXE/every
 * overlay retail hash. Binary identity does not establish runtime completion. */
#define Physics36Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
unsigned char Physics36Call40D10View1() __asm__("func_80040D10");
unsigned char Physics36Call41580View1() __asm__("func_80041580");
unsigned char Physics36Call417FCView1() __asm__("func_800417FC");
unsigned char Physics36Call41B64View1() __asm__("func_80041B64");
int Physics36Call4E9E4View1() __asm__("func_8004E9E4");
int Physics36Call4EA2CView1() __asm__("func_8004EA2C");
int Physics36Call4EDE8View1() __asm__("func_8004EDE8");
unsigned char Physics36Call4F08CView1() __asm__("func_8004F08C");
unsigned char Physics36Call4F194View1() __asm__("func_8004F194");
unsigned char Physics36Call4F1C8View1() __asm__("func_8004F1C8");
extern void *Physics36Data6C570View1 __asm__("D_8006C570");
extern unsigned char Physics36Data6E548View1 __asm__("D_8006E548");
extern unsigned char Physics36Player0View1 __asm__("D_80070328");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics36Call40D10View2() __asm__("func_80040D10");
int Physics36Call41580View2() __asm__("func_80041580");
int Physics36Call416F4View1() __asm__("func_800416F4");
int Physics36Call417FCView2() __asm__("func_800417FC");
int Physics36Call41848View1() __asm__("func_80041848");
int Physics36Call41B64View2() __asm__("func_80041B64");
int Physics36Call4E9E4View2() __asm__("func_8004E9E4");
int Physics36Call4EA2CView2() __asm__("func_8004EA2C");
int Physics36Call4EDE8View2() __asm__("func_8004EDE8");
int Physics36Call4F08CView2() __asm__("func_8004F08C");
int Physics36Call4F168View1() __asm__("func_8004F168");
int Physics36Call4F178View1() __asm__("func_8004F178");
int Physics36Call4F194View2() __asm__("func_8004F194");
int Physics36Call4F1C8View2() __asm__("func_8004F1C8");
extern int Physics36Data6E044View1 __asm__("D_8006E044");
extern int Physics36Data6E538View1 __asm__("D_8006E538");
extern unsigned char Physics36Player0View2 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics36PlayerB8View1 __asm__("D_80070328+0xB8");
extern int Physics36Player94View1 __asm__("D_80070328+0x94");
extern int Physics36PlayerA8View1 __asm__("D_80070328+0xA8");
extern int Physics36Player80View1 __asm__("D_80070328+0x80");
extern int Physics36PlayerB0View1 __asm__("D_80070328+0xB0");
extern int Physics36Player64View1 __asm__("D_80070328+0x64");
extern int Physics36Player84View1 __asm__("D_80070328+0x84");
extern int Physics36Player144View1 __asm__("D_80070328+0x144");
extern int Physics36PlayerACView1 __asm__("D_80070328+0xAC");
extern int Physics36Player4CView1 __asm__("D_80070328+0x4C");
extern unsigned char Physics36PlayerFCView1 __asm__("D_80070328+0xFC");
extern int Physics36PlayerA0View1 __asm__("D_80070328+0xA0");
extern unsigned char Physics36Player1BAView1 __asm__("D_80070328+0x1BA");
extern signed char Physics36Player1B9View1 __asm__("D_80070328+0x1B9");
extern int Physics36Player20CView1 __asm__("D_80070328+0x20C");
extern unsigned char Physics36Player101View1 __asm__("D_80070328+0x101");
extern int Physics36PlayerA4View1 __asm__("D_80070328+0xA4");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics36Player8CView1 __asm__("D_80070328+0x8C");
extern void *(*Physics44_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Physics44Slot4454)() __asm__("unk_ovlheader_80074454");
extern int (*Physics44Slot432C)() __asm__("unk_ovlheader_8007432C");
extern void *Physics36Player250View1 __asm__("D_80070328+0x250");
extern int Physics36Player88View1 __asm__("D_80070328+0x88");
extern int Physics36PlayerE8View1 __asm__("D_80070328+0xE8");
void func_level_36_80084060(int slotIndex) {
    register int product7 __asm__("$7");
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
        int sp10,sp14,sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C;
    }
    originalFrame;
    register void *globalVector80 __asm__("$16");
    register void *globalVector8CState20 __asm__("$18");
    register void *globalVector8C __asm__("$18");
    register void *var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$19");
    int temp_v0_4;
    register int workWord3 __asm__("$3");
    register void *globalFieldA4Pointer __asm__("$17");
    register int savedSlotIndex __asm__("$18");
    int lowProduct6;
    workWord2=slotIndex*16;
    globalPointer=&Physics36Data6E548View1;
    workWord2+=(int)globalPointer;
    __asm__("":"=r"(workWord2):"0"(workWord2));
    Physics36Data6C570View1=(void*)workWord2;
    workWord2=Physics36Field(&Physics36Player0View1,int*,0x54);
    stateWord3=Physics36Field(&Physics36Player0View1,int*,0x48);
    combinedIndex=workWord2+slotIndex;
    switch(stateWord3){
        default:return;
    case 85:case 91:globalVector80=&Physics36Player0View2+0x80;
        Physics36Call4F168View1(globalVector80);
        Physics36Call4F168View1(globalVector80+12);
        if(Physics36Data6E044View1!=7){
            Physics36Call40D10View2(3840);
            Physics36Call416F4View1();
            Physics36Call41580View2(90,16);
        }
        workWord2=Physics36Player1BAView1;
        if(!workWord2)goto byteOne65;
        workWord2=Physics36Data6E538View1&16;
        if(workWord2)return;
        workWord2=1;
        Physics36Player1BAView1=0;
        Physics36Player1B9View1=workWord2;
        return;
        byteOne65:workWord2=1;
        __asm__("":"=r"(workWord2):"0"(workWord2));
        Physics36Player1B9View1=workWord2;
        return;
    case 86:case 92:workWord3=Physics36Data6E044View1;
        workWord2=8;
        if(workWord3!=workWord2)Physics36Call40D10View2(3840);
        globalVector80=&Physics36Data6E538View1;
        workWord2=Physics36Field(globalVector80,int*,0)&12;
        if(workWord2)Physics36PlayerACView1=0;
        workWord2=Physics36Call416F4View1();
        call4=(void*)90;
        call5=(void*)16;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalFieldA4Pointer=(void*)workWord2;
        workWord2=Physics36Call41580View2(call4,call5);
        workWord3=Physics36PlayerA8View1;
        if(workWord3<0)workWord3=-workWord3;
        workWord3=workWord3<8;
        __asm__("":"=r"(workWord3):"0"(workWord3),"r"(workWord2));
        call5=(void*)workWord2;
        if(!workWord3)goto reset101;
        workWord2=Physics36Field(globalVector80,int*,0)&12;
        if(!workWord2)goto reset101;
        workWord2=Physics36Player144View1;
        workWord2++;
        Physics36Player144View1=workWord2;
        goto saved101;
        reset101:Physics36Player144View1=0;
        saved101:call4=&Physics36PlayerACView1;
        globalVector80=(void*)Physics36Field(call4,int*,0);
        if(globalFieldA4Pointer)goto collision101;
        workWord2=(int)call5;
        if((int)call5<0)workWord2=-workWord2;
        workWord2=workWord2<513;
        if(workWord2)goto pass101;
        collision101:workWord2=Physics36Player20CView1&64;
        if(workWord2)Physics36Field(call4,int*,0)=0;
        else{
            workWord3=Physics36PlayerB0View1;
            workWord2=workWord3<(int)globalVector80;
            if(workWord2)Physics36Field(call4,int*,0)=workWord3;
        }
        pass101:Physics36Call417FCView2(256,384);
        workWord2=Physics36Player101View1;
        call4=&Physics36PlayerACView1;
        Physics36Field(call4,int*,0)=(int)globalVector80;
        if(workWord2){
            Physics36Call4F168View1(call4-32);
            goto fields101;
        }
        Physics36Call41848View1(call4);
        Physics36Call41B64View2();
        fields101:call6=&Physics36PlayerFCView1;
        __asm__("":"=r"(call6):"0"(call6));
        workWord2=Physics36Field(call6,unsigned char*,0);
        if(workWord2)goto scalar95;
        workWord2=Physics36PlayerB8View1;
        if(!workWord2)goto vector95;
        __asm__ volatile(""::"i"(0x800842F8):"memory");
        goto scalar95;
    case 87:{
            globalVector80=&Physics36Player4CView1;
            workWord3=Physics36Field(globalVector80,int*,0);
            workWord2=1;
            if(workWord3!=workWord2)goto ground87;
            Physics36Call40D10View2(3200);
            Physics36Call41580View2(40,8);
            Physics36Call417FCView2(256,384);
            globalFieldA4Pointer=globalVector80+64;
            workWord2=Physics36Call4EA2CView2(Physics36PlayerA4View1);
            workWord3=Physics36PlayerB0View1;
            product7=workWord3*workWord2;
            call4=(void*)Physics36PlayerA4View1;
            workWord2=product7>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.sp10=workWord2;
            workWord2=Physics36Call4E9E4View2(call4);
            workWord3=Physics36PlayerB0View1;
            product7=workWord3*workWord2;
            call4=&originalFrame.sp10;
            call5=call4;
            call6=globalFieldA4Pointer;
            workWord2=product7>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.sp14=workWord2;
            Physics36Call4F1C8View2(call4,call5,call6);
            originalFrame.sp18=0;
            temp_v0_4=Physics36Call4EDE8View2(&originalFrame.sp10,0);
            __asm__("":"=r"(globalVector80):"0"(globalVector80));
            var_a0_3=globalVector80+52;
            if(temp_v0_4>=641){
                Physics36Call4F08CView2(&originalFrame.sp10,temp_v0_4,640);
                __asm__("":"=r"(globalVector80):"0"(globalVector80));
                var_a0_3=globalVector80+52;
            }
            Physics36Call4F194View2(var_a0_3,globalFieldA4Pointer,&originalFrame.sp10);
            Physics36Call41B64View2();
            workWord2=combinedIndex<13;
            if(!workWord2)goto subtract87;
            workWord2=Physics36Field(globalVector80,int*,0);
            if(workWord2)goto subtract87;
            workWord2=(int)Physics36Data6C570View1;
            workWord2=Physics36Field((void*)workWord2,int*,0)&64;
            if(workWord2)goto add23_93;
            workWord2=Physics36Player144View1;
            if(workWord2)goto add23_93;
            subtract87:globalPointer=&Physics36Player94View1;
            workWord2=Physics36Field(globalPointer,int*,0);
            __asm__("":"=r"(workWord2):"0"(workWord2),"i"(0x80084438));
            workWord2-=192;
            goto store95;
        ground87:
            workWord3=Physics36Data6E044View1;
            workWord2=8;
            if(workWord3!=workWord2)Physics36Call40D10View2(3840);
            globalVector80=&Physics36Data6E538View1;
            workWord2=Physics36Field(globalVector80,int*,0)&12;
            if(workWord2)Physics36PlayerACView1=0;
            workWord2=Physics36Call416F4View1();
            call4=(void*)90;
            call5=(void*)16;
            __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
            globalFieldA4Pointer=(void*)workWord2;
            workWord2=Physics36Call41580View2(call4,call5);
            workWord3=Physics36PlayerA8View1;
            if(workWord3<0)workWord3=-workWord3;
            workWord3=workWord3<8;
            __asm__("":"=r"(workWord3):"0"(workWord3),"r"(workWord2));
            call5=(void*)workWord2;
            if(!workWord3)goto reset87;
            workWord2=Physics36Field(globalVector80,int*,0)&12;
            if(!workWord2)goto reset87;
            workWord2=Physics36Player144View1;
            workWord2++;
            Physics36Player144View1=workWord2;
            goto saved87;
            reset87:Physics36Player144View1=0;
            saved87:call4=&Physics36PlayerACView1;
            globalVector80=(void*)Physics36Field(call4,int*,0);
            if(globalFieldA4Pointer)goto collision87;
            workWord2=(int)call5;
            if((int)call5<0)workWord2=-workWord2;
            workWord2=workWord2<513;
            if(workWord2)goto pass87;
            collision87:workWord2=Physics36Player20CView1&64;
            if(workWord2)Physics36Field(call4,int*,0)=0;
            else{
                workWord3=Physics36PlayerB0View1;
                workWord2=workWord3<(int)globalVector80;
                if(workWord2)Physics36Field(call4,int*,0)=workWord3;
            }
            pass87:Physics36Call417FCView2(256,384);
            workWord2=Physics36Player101View1;
            call4=&Physics36PlayerACView1;
            Physics36Field(call4,int*,0)=(int)globalVector80;
            if(workWord2){
                Physics36Call4F168View1(call4-32);
                goto fields87;
            }
            Physics36Call41848View1(call4);
            Physics36Call41B64View2();
            fields87:call6=&Physics36PlayerFCView1;
            workWord2=Physics36Field(call6,unsigned char*,0);
            if(workWord2)goto scalar95;
            workWord2=Physics36PlayerB8View1;
            call4=call6-112;
            if(workWord2)goto scalar95;
            commit87:call5=call4;
            Physics36Call4F194View2(call4,call5,call6-20);
            return;
        }
    case 88:vectorAt40=&originalFrame.sp20;
        Physics36Call4F168View1(vectorAt40);
        call4=vectorAt40;
        call5=call4;
        Physics36Call4F1C8View2(call4,call5,&Physics36Player8CView1);
        workWord2=Physics36PlayerB8View1;
        call4=vectorAt40;
        if(!workWord2)goto detached121;
        originalFrame.sp28=0;
        workWord2=Physics36Call4EDE8View2(call4,0);
        call5=(void*)workWord2;
        workWord2=(int)call5<9;
        call4=vectorAt40;
        if(workWord2)goto vectors121;
        call6=(void*)8;
        goto limit121;
        detached121:workWord2=Physics36Call4EDE8View2(call4,1);
        call5=(void*)workWord2;
        workWord2=(int)call5<65;
        call4=vectorAt40;
        if(workWord2)goto vectors121;
        call6=(void*)64;
        limit121:__asm__ volatile(""::"r"(call4),"r"(call5),"r"(call6):"memory");
        Physics36Call4F08CView2(call4,call5,call6);
        vectors121:globalVector80=&Physics36Player80View1;
        call4=globalVector80;
        __asm__ volatile(""::"r"(call4):"memory");
        globalFieldA4Pointer=globalVector80+12;
        call5=globalFieldA4Pointer;
        call6=&originalFrame.sp20;
        __asm__ volatile(""::"r"(call5),"r"(call6):"memory");
        workWord2=-192;
        originalFrame.sp28=workWord2;
        Physics36Call4F194View2(call4,call5,call6);
        Physics36Call4F178View1(globalFieldA4Pointer,globalVector80);
        workWord2=Physics36Player94View1;
        workWord2=workWord2<-8960;
        clamp119:if(workWord2){
            workWord2=-8960;
            Physics36Player94View1=workWord2;
        }
        return;
    case 89:{
            register int numeric4 __asm__("$4");
            workWord3=Physics36Player4CView1;
            workWord2=1;
            if(workWord3!=workWord2)goto free89;
            workWord2=(int)Physics36Player250View1;
            workWord2=Physics36Field((void*)workWord2,int*,0);
            numeric4=Physics36Field((void*)workWord2,int*,80);
            workWord2=Physics36Player64View1;
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
            Physics36PlayerA4View1=workWord3;
            Physics36PlayerACView1=workWord2;
            call4=(void*)22;
            goto speed89;
            free89:Physics36Call40D10View2(1600);
            call4=(void*)22;
            speed89:Physics36Call41580View2(call4,4);
            Physics36Call417FCView2(256,384);
            globalFieldA4Pointer=&Physics36Player4CView1;
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            workWord3=Physics36Field(globalFieldA4Pointer,int*,0);
            workWord2=1;
            if(workWord3!=workWord2)goto air89;
            workWord2=Physics36Call4EA2CView2(Physics36PlayerA4View1);
            workWord3=Physics36PlayerB0View1;
            product7=workWord3*workWord2;
            call4=(void*)Physics36PlayerA4View1;
            workWord2=product7>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics36Field(globalFieldA4Pointer,int*,52)=workWord2;
            workWord2=Physics36Call4E9E4View2(call4);
            workWord3=Physics36PlayerB0View1;
            product7=workWord3*workWord2;
            call4=globalFieldA4Pointer+64;
            workWord2=Physics36Player94View1;
            Physics36Player88View1=workWord2;
            workWord2=product7>>12;
            Physics36Player84View1=workWord2;
            Physics36Call4F178View1(call4,globalFieldA4Pointer+52);
            goto subtract89;
            air89:globalVector8C=globalFieldA4Pointer+64;
            workWord2=Physics36Call4EA2CView2(Physics36PlayerA4View1);
            workWord3=Physics36PlayerB0View1;
            product7=workWord3*workWord2;
            call4=(void*)Physics36PlayerA4View1;
            workWord2=product7>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.sp30=workWord2;
            workWord2=Physics36Call4E9E4View2(call4);
            workWord3=Physics36PlayerB0View1;
            product7=workWord3*workWord2;
            globalVector80=&originalFrame.sp30;
            call4=globalVector80;
            call5=globalVector80;
            call6=globalVector8C;
            __asm__("":"=r"(call4),"=r"(call5),"=r"(call6):"0"(call4),"1"(call5),"2"(call6));
            workWord2=product7>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            originalFrame.sp34=workWord2;
            Physics36Call4F1C8View2(call4,call5,call6);
            originalFrame.sp38=0;
            temp_v0_4=Physics36Call4EDE8View2(globalVector80,0);
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3=globalFieldA4Pointer+52;
            if(temp_v0_4>=321){
                Physics36Call4F08CView2(globalVector80,temp_v0_4,320);
                __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3=globalFieldA4Pointer+52;
            }
            Physics36Call4F194View2(var_a0_3,globalVector8C,globalVector80);
            Physics36Call41B64View2();
            subtract89:globalPointer=&Physics36Player94View1;
            workWord2=Physics36Field(globalPointer,int*,0);
            workWord2-=192;
            Physics36Field(globalPointer,int*,0)=workWord2;
            goto clamp95;
        }
    case 93:case 94:{
            Physics36Call40D10View1(0xC80);
            Physics36Call41580View1(0x28, 8);
            Physics36Call417FCView1(256,384);
            globalFieldA4Pointer = &Physics36Player0View1 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2=Physics36Call4EA2CView1(Physics36Field(globalFieldA4Pointer,int*,0));
            workWord3=Physics36Field(&Physics36Player0View1,int*,0xB0);
            product7=workWord3*workWord2;
            call4=(void*)Physics36Field(globalFieldA4Pointer,int*,0);
            workWord2=product7>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp40=workWord2;
            workWord2=Physics36Call4E9E4View1(call4);
            workWord3=Physics36Field(&Physics36Player0View1,int*,0xB0);
            product7=workWord3*workWord2;
            workWord2=product7>>12;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            originalFrame.sp44=workWord2;
            Physics36Call4F1C8View1(&originalFrame.sp40, &originalFrame.sp40, globalVector8C);
            originalFrame.sp48 = 0;
            temp_v0_4 = Physics36Call4EDE8View1(&originalFrame.sp40, 0);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics36Call4F08CView1(&originalFrame.sp40, temp_v0_4, 0x280);
                __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics36Call4F194View1(var_a0_3, globalVector8C, &originalFrame.sp40);
            Physics36Call41B64View1();
            workWord2=combinedIndex<13;
            if(!workWord2)goto subtract93;
            workWord2=Physics36Player4CView1;
            if(workWord2)goto subtract93;
            workWord2=(int)Physics36Data6C570View1;
            workWord2=Physics36Field((void*)workWord2,int*,0)&64;
            if(workWord2)goto add23_93;
            workWord2=Physics36Player144View1;
            if(workWord2)goto add23_93;
            goto subtract93;
            add23_93:workWord2=Physics36Player94View1;
            workWord2+=23;
            Physics36Player94View1=workWord2;
            return;
            subtract93:globalPointer=&Physics36Player94View1;
            workWord2=Physics36Field(globalPointer,int*,0);
            workWord2-=192;
            goto store95;
        }
    case 95:case 96:case 97:{
            register int numeric4 __asm__("$4");
            register int angle17 __asm__("$17");
            register void *vector17 __asm__("$17");
            workWord2=(int)Physics36Player250View1;
            globalVector80=Physics36Field((void*)workWord2,void**,0);
            workWord2=Physics36Field(globalVector80,int*,76);
            if(!workWord2){
                workWord2=Physics36Field(globalVector80,int*,88);
                workWord2++;
                Physics36Field(globalVector80,int*,88)=workWord2;
            }
            workWord3=Physics36Data6E044View1;
            workWord2=8;
            if(workWord3!=workWord2)Physics36Call40D10View2(1536);
            numeric4=Physics36Field(globalVector80,int*,80);
            workWord2=Physics36PlayerA4View1;
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
            snapped95:globalVector80=&Physics36PlayerA4View1;
            numeric4=Physics36Field(globalVector80,int*,0);
            workWord2=Physics36Call4EA2CView2(numeric4-angle17);
            workWord3=Physics36PlayerACView1;
            product7=workWord3*workWord2;
            Physics36Field(globalVector80,int*,0)=angle17;
            workWord2=product7>>12;
            Physics36PlayerACView1=workWord2;
            if(workWord2<0)Physics36PlayerACView1=0;
            workWord2=Physics36Call41580View2(90,16);
            angle17=Physics36PlayerACView1;
            if(workWord2<0)workWord2=-workWord2;
            workWord2=workWord2<513;
            call4=(void*)128;
            if(!workWord2){
                workWord3=Physics36PlayerB0View1;
                workWord2=workWord3<angle17;
                if(workWord2)Physics36PlayerACView1=workWord3;
            }
            Physics36Call417FCView2(call4,256);
            call4=(void*)Physics36PlayerA4View1;
            __asm__ volatile(""::"r"(call4):"memory");
            globalVector80=&Physics36PlayerACView1;
            __asm__("":"=r"(globalVector80):"0"(globalVector80));
            Physics36Field(globalVector80,int*,0)=angle17;
            workWord2=Physics36Call4EA2CView2(call4);
            workWord3=Physics36PlayerB0View1;
            product7=workWord3*workWord2;
            call4=(void*)Physics36PlayerA4View1;
            workWord2=product7>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics36Field(globalVector80,int*,-44)=workWord2;
            workWord2=Physics36Call4E9E4View2(call4);
            workWord3=Physics36PlayerB0View1;
            product7=workWord3*workWord2;
            vector17=globalVector80-32;
            __asm__("":"=r"(vector17):"0"(vector17));
            call4=vector17;
            Physics36Player88View1=0;
            workWord2=product7>>12;
            Physics36Player84View1=workWord2;
            Physics36Call4F178View1(call4,globalVector80-44);
            workWord2=Physics36PlayerFCView1;
            if(workWord2)goto scalar95;
            workWord2=Physics36PlayerB8View1;
            if(!workWord2)goto vector95;
            scalar95:workWord2=Physics36PlayerA0View1;
            workWord2-=192;
            Physics36Player94View1=workWord2;
            return;
            vector95:call4=&Physics36Player8CView1;
            __asm__ volatile(""::"r"(call4):"memory");
            call6=&Physics36PlayerE8View1;
            Physics36Call4F194View2(call4,call4,call6);
            return;
        }
    case 90:globalVector80=&Physics36Player0View2+0xB8;
        workWord2=Physics36Field(globalVector80,int*,0);
        if(!workWord2)goto zero128;
        vectorAt30=&originalFrame.sp50;
        Physics36Call4F168View1(vectorAt30);
        call4=vectorAt30;
        call5=vectorAt30;
        __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalVector8CState20=globalVector80-44;
        Physics36Call4F1C8View2(call4,call5,globalVector8CState20);
        originalFrame.sp58=0;
        call5=(void*)Physics36Call4EDE8View2(vectorAt30,0);
        workWord2=(int)call5<65;
        if(!workWord2)Physics36Call4F08CView2(vectorAt30,call5,64);
        originalFrame.sp58=-192;
        globalVector80-=56;
        Physics36Call4F194View2(globalVector80,globalVector8CState20,vectorAt30);
        Physics36Call4F178View1(globalVector8CState20,globalVector80);
        goto clamp128;
        zero128:Physics36Call4F168View1(globalVector80-56);
        Physics36Call4F168View1(globalVector80-44);
        goto clamp128;
        clamp128:globalPointer=&Physics36Player94View1;
        workWord2=Physics36Field(globalPointer,int*,0);
        clamp95:workWord2=workWord2<-8960;
        if(workWord2){
            workWord2=-8960;
            store95:__asm__ volatile(""::"i"(0x80084CE4):"memory");
            Physics36Field(globalPointer,int*,0)=workWord2;
        }
        return;
    }
}
#undef Physics36Field


/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80084D08.
 * Reuses verified24 private selector55..61 C. Original36 dispatch and BC base
 * lifetime preserved. Byte offsets private4C/50/54/58; unsigned selected46
 * shifts4, signed class36 filters4B/4F/2FF. Source vectors stack18/28 retain
 * 600/0/-380 and400/0/200; helper roles/units/physical meaning remain open.
 * Numeric vectors byte46=0/80/FF ->0/800/FF0 before subsequent helpers.
 * Empty constraints emit no instructions. Every original code/internal jump/
 * dispatch word, strict full TU and every EXE/overlay hash required. Cadence,
 * audio semantics and live runtime parity remain open.
 */
extern Moby* Callback36QueryMoby __asm__("D_80070328+0x250");
extern Moby* Callback36FirstCallMoby __asm__("D_80070328+0x250");
extern Moby* Callback36SecondCallMoby __asm__("D_80070328+0x250");
extern Moby* Callback36InitialMoby __asm__("D_80070328+0x250");
extern int Callback36ClearedWord __asm__("D_80070328+0x28");
extern unsigned char Callback36MobyPointer[] __asm__("D_80070328+0x250");
extern Moby* Callback36Word71930 __asm__("D_80071930");
extern int Callback36WordE1D4 __asm__("D_8006E1D4");
extern int Callback36WordE1D8 __asm__("D_8006E1D8");
extern int Callback36WordE530 __asm__("D_8006E530");
extern int Callback36WordE52C __asm__("D_8006E52C");
extern void (*Callback36Header344)(void) __asm__("unk_ovlheader_80074344");
int Callback36Call80018368(Vector3D*,Vector3D*) __asm__("func_80018368");
extern Spyro Callback36Player __asm__("D_80070328");
void Callback36Call80041930(void) __asm__("func_80041930");
void Callback36Call80041C20(void) __asm__("func_80041C20");
void Callback36Call80042A44(void) __asm__("func_80042A44");
void Callback36Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback36Word8006E538 __asm__("D_8006E538");
int Callback36Call80055E84(Moby*) __asm__("func_80055E84");
void Callback36Call8004ED6C(void*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
void* Callback36Call8001BA30(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int Callback36Call80019138(Vector3D*,int,int,int,int,Moby*) __asm__("func_80019138");
int Callback36Call8001830C(Vector3D*,Vector3D*,int,int,Moby*) __asm__("func_8001830C");
void func_level_36_80084D08(void) {
    struct {Vector3D first; int reserved24; Vector3D second; int reserved34; } local;
    register unsigned char* privateData __asm__("$16");
    register unsigned char* privateOther __asm__("$16");
    register Moby* selected __asm__("$2");
    register int selectedClass __asm__("$3");


    switch(Callback36Player.animationState) {
    case 0x55:
        if(func_800438F4()==0)func_80043728();
        Callback36Call80041C20();
        Callback36Player.unk9a=0;
        Callback36Call80042A44();
        goto clearSharedValue;
    case 0x5A:
        Callback36Call80041C20();
        Callback36Call80042A44();
        goto clearSharedValue;
    case 0x58:
        Callback36Call80041C20();
        Callback36Call80042A44();
        goto queryC00;
    case 0x56:
    case 0x5C:
        privateData=Callback36Player.critterMobyPtr->mobyTag;
        func_800438F4();
        Callback36Call80041C20();
        Callback36Call80042A44();
        Callback36Call80041930();
        if((unsigned char)Callback36Player.unk10[2]!=0) {
            selected=Callback36Word71930;
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
        register unsigned char* sourceBase __asm__("$17");
        register int* clearedWord __asm__("$16");
        register Moby** mobyPointer __asm__("$16");
        void* result;
        register Moby* initialMoby __asm__("$4");
        func_800438F4();
        Callback36Call80041C20();
        Callback36Call80042A44();
        Callback36Call80041930();
        Callback36Call80043A38(0xC00);
        initialMoby=Callback36InitialMoby;
        __asm__ volatile("" : "=r"(initialMoby) : "0"(initialMoby) : "memory");
        clearedWord=&Callback36ClearedWord;
        *clearedWord=0;
        if(initialMoby->animationState.id==2 &&
           Callback36Call80055E84(initialMoby)>=4 &&
           Callback36Call80055E84(Callback36QueryMoby)<13) {
            local.first.x=0x600;
            local.first.y=0;
            local.first.z=-0x380;
            Callback36Call8004ED6C((unsigned char*)clearedWord+8,&local.first,&local.first);
            {register Vector3D* destination __asm__("$4")=&local.first;
            register Vector3D* firstSource __asm__("$5")=destination;
            __asm__("" : "=r"(destination),"=r"(firstSource) : "0"(destination),"1"(firstSource));
            sourceBase=(unsigned char*)clearedWord-0x28;
            func_8004F194(destination,firstSource,(Vector3D*)sourceBase);}

            result=Callback36Call8001BA30(&local.first,0x400,1,0,0,Callback36FirstCallMoby);
            if(result) {
                func_8004F178(&local.second,(Vector3D*)((unsigned char*)result+0xC));
                local.second.z+=0x80;
                if(Callback36Call80018368((Vector3D*)sourceBase,&local.second)==0)
                    Callback36Call8001BA30(&local.first,0x400,1,0,0x04000000,Callback36SecondCallMoby);
            }
            {register Vector3D* argument0 __asm__("$4")=&local.first;
            register int argument1 __asm__("$5")=0x400;
            register int argument2 __asm__("$6")=0;
            register int argument3 __asm__("$7")=0;
            register Moby* lastMoby __asm__("$3");
            __asm__ volatile("" : "=r"(argument0), "=r"(argument1), "=r"(argument2), "=r"(argument3) : "0"(argument0), "1"(argument1), "2"(argument2), "3"(argument3) : "memory");
            mobyPointer=(Moby**)Callback36MobyPointer;
            lastMoby=*mobyPointer;
            Callback36Call80019138(argument0,argument1,argument2,argument3,0x04000000,lastMoby); }
            Callback36Call8001830C((Vector3D*)((unsigned char*)mobyPointer-0x250),&local.first,0,0x04000000,*mobyPointer);
            if(Callback36Call80055E84(*mobyPointer)>=8) {
                register int* limitPointer __asm__("$3")=&Callback36WordE1D4;
                if(*limitPointer<0xC00)*limitPointer=0xC00;
                if(Callback36WordE1D8<10)Callback36WordE1D8=10;
                Callback36WordE530=120;
                Callback36WordE52C=5;
            }
        }
        if(Callback36Player.unk5==1) {
            if(Callback36Player.ticksSinceLastSurfaceTouch==0)Callback36Player.unk5=0;
        } else if(Callback36Player.ticksSinceLastSurfaceTouch!=0) {
            Callback36Player.unk5=1;
            Callback36Player.unk7a[2].z=Callback36Player.unk7a[3].z;
        }
        return;
    }
    case 0x59:
        privateOther=Callback36Player.critterMobyPtr->mobyTag;
        Callback36Header344();
        Callback36Call80041C20();
        Callback36Call80042A44();
        Callback36Call80041930();
        if((unsigned char)Callback36Player.unk10[2]!=0) {
            selected=Callback36Word71930;
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
                    Callback36Player.unk5=1;
                } else goto clearSelectedOther;
            }
        } else {
clearSelectedOther:
            *(Moby**)(privateOther+0x4C)=0;
            Callback36Player.unk5=0;
        }
        goto clearSharedValue;
    case 0x5B: {
        register unsigned char* originalBase __asm__("$17");
        register Vector3D* vectorBase __asm__("$16");
        register void* argument0 __asm__("$4");
        if(func_800438F4()==0)func_80043728();
        Callback36Call80041C20();
        originalBase=(unsigned char*)&Callback36Player.unk9a;
        *(int*)originalBase=0;
        Callback36Call80042A44();
        Callback36Player.unk4[0]=0;
        argument0=originalBase-0x8C;
        if(Callback36Player.critterMobyPtr->animationState.id==6) {
            vectorBase=&local.second;
            local.second.x=0x400;
            local.second.y=0;
            local.second.z=0x200;
            Callback36Call8004ED6C(argument0,vectorBase,vectorBase);
            func_8004F194(vectorBase,vectorBase,(Vector3D*)(originalBase-0xBC));
            Callback36Call8001BA30(vectorBase,0x400,0,0,0x08000000,Callback36Player.critterMobyPtr);
        }
        return;
    }
    case 0x5D:
    case 0x5E:
        Callback36Call80041C20();
        Callback36Call80042A44();
        Callback36Call80041930();
        if(Callback36Player.unk5!=0x7F) {
            if(Callback36Player.unk7a[3].z<0 && Callback36Player.animationStateFrames>=4)
                Callback36Player.unk5=1;
            else if(Callback36Player.unk5==0 && !(Callback36Word8006E538&0x40) && Callback36Player.union144.a.unk13cb==0)
                Callback36Player.unk5=2;
        }
        goto clearSharedValue;
    case 0x5F:
    case 0x60:
    case 0x61:
        privateData=Callback36Player.critterMobyPtr->mobyTag;
        Callback36Header344();
        func_800438F4();
        Callback36Call80041C20();
        Callback36Call80042A44();
        Callback36Call80041930();
        if((unsigned char)Callback36Player.unk10[2]!=0) {
            selected=Callback36Word71930;
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
        Callback36Call80043A38(0xC00);
clearSharedValue:
        Callback36Player.unk4[0]=0;
        return;
    default:
        return;
    }
}




#define LEVEL_ID 36
#define PlaySpyroSounds_level_36 func_level_36_8008537C
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_36_800854A4(int index) {
    Vector3D* position;
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x55: case 0x56: case 0x57: case 0x58: case 0x5a: case 0x5b: case 0x5c: case 0x5f: case 0x60: case 0x61:
        position = &spyro.unk9e;
        break;
    case 0x59: case 0x5d: case 0x5e:
        position = 0;
        break;
    default: return;
    }
    func_80043ABC(position);
}

extern Spyro Callback36_D_80070328 __asm__("D_80070328");
extern short Signed36TableA[] __asm__("D_800658A0");
extern short Signed36TableB[] __asm__("D_80065920");
int Callback36_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Callback36_func_80043A38(int scale) __asm__("func_80043A38");
void Callback36_func_800441F0(void) __asm__("func_800441F0");
void Callback36_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Callback36_D_8006E524 __asm__("D_8006E524");

void func_level_36_80085520(int arg0) {
    register Vector3D* destination __asm__("$4");
    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    register unsigned char* stateBaseB __asm__("$2");
    register unsigned char *sourceBytesA __asm__("$16");
    register unsigned char *sourceBytesB __asm__("$16");

    switch (arg0) {
    case 0x55:
    case 0x5B:
        Callback36_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Callback36_D_80070328.unk5 = 0;
        Callback36_func_800441F0();
        Callback36_D_80070328.grounded = 1;
        return;
    case 0x56:
    case 0x57:
    case 0x5C:
    case 0x5F:
    case 0x60:
    case 0x61:
        Callback36_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Callback36_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((unsigned char*)&Callback36_D_80070328.movementState + 0x3C), (Vector3D *) ((unsigned char*)&Callback36_D_80070328.movementState + 0x48));
            Callback36_D_80070328.unk5 = 1;
        } else {
            Callback36_D_80070328.unk5 = 0;
        }
        Callback36_D_80070328.unk8[0] = Callback36_func_8004EDE8(&Callback36_D_80070328.unk7a[3], 0);
        Callback36_func_80043A38(0xC00);
        Callback36_D_80070328.union144.a.unk13cb = 0;
        Callback36_D_80070328.grounded = 1;
        goto clearTail;
    case 0x58:
        Callback36_D_80070328.movementState = MOVEMENT_STATE_HURT;
        Callback36_D_80070328.unk5 = 0;
        if (Callback36_D_80070328.unk22[5] >= 0) {
            tableOffsetOrValue = Callback36_D_80070328.unk22[5] * 2;
            tableValueA = *(short*)((unsigned char*)Signed36TableB + tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            tableValueA >>= 1;
            Callback36_D_80070328.unk7a[2].x = tableValueA;
            tableOffsetOrValue = *(short*)((unsigned char*)Signed36TableA + tableOffsetOrValue);
            Callback36_D_80070328.unk7a[2].z = 0;
            __asm__ __volatile__("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Callback36_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
        } else {
            Callback36_func_8004F168((Vector3D *) ((unsigned char*)&Callback36_D_80070328.movementState + 0x3C));
        }
        Callback36_D_80070328.unk7a[2].z = 0x200;
        func_8004F178((Vector3D *) ((unsigned char*)&Callback36_D_80070328.unk7a[2].z - 0x14), (Vector3D *) ((unsigned char*)&Callback36_D_80070328.unk7a[2].z - 8));
        Callback36_D_80070328.grounded = 1;
        Callback36_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
    default:
        return;
    case 0x5A:
        Callback36_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Callback36_D_80070328.unk5 = 0;
        Callback36_func_80043A38(0xC00);
        Callback36_D_80070328.grounded = 1;
        Callback36_D_8006E524 = 0xF;
        return;
    case 0x59:
        Callback36_D_80070328.movementState = MOVEMENT_STATE_FALL;
        if (Callback36_D_80070328.animationState == 0x5F) {
            Callback36_D_80070328.unk5 = 1;
        } else {
            Callback36_D_80070328.unk5 = 0;
        }
        Callback36_D_80070328.unk8[0] = Callback36_func_8004EDE8(&Callback36_D_80070328.unk7a[3], 0);
        Callback36_D_80070328.grounded = 0;
        Callback36_D_80070328.unk15b = 1;
clearTail:
        Callback36_D_80070328.idle = 0;
        Callback36_D_80070328.unk15g = 0;
        return;
    case 0x5D:
        stateBaseA = Raw36State;
        __asm__("" : "=r"(stateBaseA) : "0"(stateBaseA));
        destination = (Vector3D*)(stateBaseA + 0x3C);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceBytesA = stateBaseA + 0x48;
        *(int*)stateBaseA = 2;
        func_8004F178(destination, (Vector3D*)sourceBytesA);
        Callback36_D_80070328.unk8[0] = Callback36_func_8004EDE8((Vector3D *) sourceBytesA, 0);
        Callback36_D_80070328.unk7a[2].z = 0xA00;
        Callback36_D_80070328.unk5 = 0;
        Callback36_D_80070328.union144.a.unk13cb = 0;
        Callback36_D_80070328.grounded = 0;
        PlaySound((int) D_8006C654->jump, 0, 0);
        return;
    case 0x5E:
        stateBaseB = Raw36State;
        __asm__("" : "=r"(stateBaseB) : "0"(stateBaseB));
        destination = (Vector3D*)(stateBaseB + 0x3C);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceBytesB = stateBaseB + 0x48;
        *(int*)stateBaseB = 2;
        func_8004F178(destination, (Vector3D*)sourceBytesB);
        Callback36_D_80070328.unk8[0] = Callback36_func_8004EDE8((Vector3D *) sourceBytesB, 0);
        Callback36_D_80070328.unk5 = 2;
        Callback36_D_80070328.union144.a.unk13cb = 0;
        Callback36_D_80070328.grounded = 0;
        break;
    }
}


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80085870.
 * Assembly SHA256 477aaf4c291dc6c7179d89ee3f4d825d93a91aa1d07f898a91fdd2f340de89b2.
 * AI-generated; not human reviewed. All819 original instructions and13
 * selectors bias85 are required. Original frame38 retains scratch10..2C
 * and savedS0/RA. All13 state bodies reuse verified source cases with
 * exact original stack/address maps. Last97 includes the five original
 * epilogue rows. All callbacks,input/effect/sound selectors,counters,fields
 * and actual internal/conditional targets remain original.
 * Typed aliases stay distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit words.
 * Units/fixed point,helper contracts,caller rate and synchronized runtime
 * completeness remain open; cadence is per invocation.
 * Falsification: every native/linked word,actual target,selector/data and
 * full EXE/every overlay hash. Binary identity is the only parity claim. */
extern int Anim36Player48View1 __asm__("D_80070328 + 0x48");
int Anim36Call4BEF8View1() __asm__("func_8004BEF8");
int Anim36Call498C0View1() __asm__("func_800498C0");
extern int Anim36Player48View2 __asm__("D_80070328 + 0x48");
extern int Anim36Player4CView1 __asm__("D_80070328 + 0x4C");
extern int Anim36Player54View1 __asm__("D_80070328 + 0x54");
extern int Anim36Player58View1 __asm__("D_80070328 + 0x58");
extern int Anim36Player8CView1 __asm__("D_80070328 + 0x8C");
extern int Anim36Player90View1 __asm__("D_80070328 + 0x90");
extern int Anim36Player94View1 __asm__("D_80070328 + 0x94");
extern int Anim36PlayerA8View1 __asm__("D_80070328 + 0xA8");
extern int Anim36PlayerACView1 __asm__("D_80070328 + 0xAC");
extern int Anim36PlayerB0View1 __asm__("D_80070328 + 0xB0");
extern int Anim36PlayerB8View1 __asm__("D_80070328 + 0xB8");
extern int Anim36PlayerCCView1 __asm__("D_80070328 + 0xCC");
extern int Anim36PlayerD0View1 __asm__("D_80070328 + 0xD0");
extern int Anim36PlayerD4View1 __asm__("D_80070328 + 0xD4");
extern int Anim36PlayerE4View1 __asm__("D_80070328 + 0xE4");
extern int Anim36Player144View1 __asm__("D_80070328 + 0x144");
extern int Anim36Player280View1 __asm__("D_80070328 + 0x280");
extern unsigned char Anim36Player0View1[] __asm__("D_80070328");
extern unsigned char *Anim36Player250View1 __asm__("D_80070328 + 0x250");
extern unsigned char Anim36Data6E535View1 __asm__("D_8006E535");
extern int Anim36Data6E538View1 __asm__("D_8006E538");
extern int Anim36Data6E53CView1 __asm__("D_8006E53C");
extern int Anim36Data6E530View1 __asm__("D_8006E530");
extern int Anim36Data6E52CView1 __asm__("D_8006E52C");
extern int (*Anim36Data7431CView1)(int) __asm__("unk_ovlheader_8007431C");
extern int (*Anim36DataSpawnParticleView1)(int,int,void*,int) __asm__("SpawnParticle");
int Anim36Call55E84View1(void*) __asm__("func_80055E84");
int Anim36Call4BEF8View2(int) __asm__("func_8004BEF8");
extern int Anim36PlayerA4View1 __asm__("D_80070328 + 0xA4");
extern int Anim36PlayerB4View1 __asm__("D_80070328 + 0xB4");
extern int Anim36PlayerA0View1 __asm__("D_80070328 + 0xA0");
int Anim36Call4F1C8View1(void*,void*,void*) __asm__("func_8004F1C8");
int Anim36Call4E880View1(int,int,int) __asm__("func_8004E880");
int Anim36Call3BABCView1(void*,int,int) __asm__("func_8003BABC");
#define Anim36Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
void func_level_36_80085870(void){
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
    rawValue2=Anim36Player48View1;
    switch(rawValue2){
    case 85:
        rawValue2=Anim36Data7431CView1(1);
        if(rawValue2)return;
        rawValue3=Anim36Data6E53CView1;
        rawValue2=rawValue3&64;
        nextSelector4=93;
        if(rawValue2)goto select;
        rawValue2=Anim36PlayerB8View1<4;
        nextSelector4=89;
        if(!rawValue2)goto select;
        rawValue2=Anim36PlayerE4View1<23;
        if(!rawValue2)goto select;
        rawValue2=rawValue3&32;
        nextSelector4=87;
        if(rawValue2)goto select;
        rawValue2=rawValue3&128;
        nextSelector4=91;
        if(rawValue2)goto select;
        rawValue2=Anim36PlayerA8View1;
        if(rawValue2<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<17;
        nextSelector4=86;
        if(!rawValue2)goto select;
        rawValue2=Anim36Data6E538View1&12;
        if(rawValue2)return;
        rawValue2=Anim36PlayerACView1;
        if(!rawValue2)return;
        goto select;
    case 86:
        rawValue2=(int)Anim36Player250View1;
        callback3=Anim36Data7431CView1;
        record16=Anim36Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue3=Anim36Data6E53CView1;
        rawValue2=rawValue3&64;
        nextSelector4=93;
        if(rawValue2)goto select;
        rawValue2=Anim36PlayerB8View1<4;
        nextSelector4=89;
        if(!rawValue2)goto select;
        rawValue2=Anim36PlayerE4View1<23;
        if(!rawValue2)goto select;
        rawValue2=rawValue3&32;
        nextSelector4=87;
        if(rawValue2)goto select;
        rawValue2=rawValue3&128;
        nextSelector4=91;
        if(rawValue2)goto select;
        rawValue2=Anim36Data6E535View1;
        if(!rawValue2)goto held86;
        rawValue2=Anim36PlayerB0View1;
        nextSelector4=85;
        if(!rawValue2)goto select;
        held86:rawValue2=Anim36Data6E538View1&12;
        if(!rawValue2)goto angle86;
        rawValue2=Anim36Player144View1<16;
        nextSelector4=85;
        if(!rawValue2)goto select;
        angle86:rawValue2=Anim36Field(record16,int*,0x4C);
        nextSelector4=(int)frame.at10;
        if(!rawValue2)goto distance86;
        Anim36Call4F1C8View1((void*)nextSelector4,(void*)(rawValue2+12),Anim36Player0View1);
        rawValue2=Anim36Call4E880View1(frame.at10[0],frame.at10[1],1);
        rawValue3=Anim36PlayerA4View1;
        rawValue2-=rawValue3;
        rawValue3=rawValue2&4095;
        rawValue2=rawValue3<2049;
        if(!rawValue2)rawValue3-=4096;
        rawValue2=rawValue3;
        if(rawValue3<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<256;
        nextSelector4=96;
        if(rawValue2)goto select;
        distance86:rawValue2=Anim36PlayerB4View1<3585;
        if(rawValue2)return;
        nextSelector4=(int)Anim36Player250View1;
        rawValue2=Anim36Call55E84View1((void*)nextSelector4);
        rawValue2=rawValue2<33;
        nextSelector4=92;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x80085AF4):"memory");
        goto select;
    case 87:
        rawValue2=Anim36Data7431CView1(1);
        if(rawValue2)return;
        nextSelector4=(int)Anim36Player250View1;
        rawValue2=Anim36Player48View2;
        rawValue3=Anim36Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=85;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim36Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        rawValue2=Anim36PlayerB8View1<4;
        if(!rawValue2)goto airborne87;
        rawValue2=Anim36PlayerE4View1<23;
        if(rawValue2)goto ground87;
        airborne87:__asm__ volatile(""::"i"(0x80085B7C):"memory");
        nextSelector4=89;
        goto select;
        ground87:rawValue2=Anim36PlayerACView1;
        nextSelector4=86;
        if(!rawValue2)goto select85;
        __asm__ volatile(""::"i"(0x80085B98):"memory");
        goto select;
    case 88:
        nextSelector4=(int)Anim36Player250View1;
        rawValue2=Anim36Player48View2;
        rawValue3=Anim36Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=85;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim36Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        rawValue2=Anim36Player280View1;
        nextSelector4=90;
        if(rawValue2<0)goto select;
        rawValue2=Anim36PlayerB8View1;
        nextSelector4=89;
        if(!rawValue2)goto select85;
        goto select;
    case 89:
        rawValue2=Anim36Data7431CView1(1);
        if(rawValue2)return;
        rawValue2=Anim36PlayerB8View1;
        if(rawValue2)return;
        rawValue2=Anim36PlayerE4View1<23;
        if(!rawValue2)return;
        rawValue2=Anim36PlayerACView1;
        nextSelector4=86;
        if(!rawValue2)nextSelector4=85;
        Anim36Call4BEF8View2(nextSelector4);
        {
            register int (*spawn2)(int,int,void*,int) __asm__("$2")=Anim36DataSpawnParticleView1;
            if(spawn2)spawn2(8,33,0,2);
        }
        product5=2;
        nextSelector4=(int)Anim36Player250View1;
        Anim36Call3BABCView1((void*)nextSelector4,product5,0);
        rawValue2=Anim36Player58View1<24;
        if(rawValue2)return;
        rawValue2=120;
        Anim36Data6E530View1=rawValue2;
        rawValue2=15;
        Anim36Data6E52CView1=rawValue2;
        return;
    case 90:
        nextSelector4=(int)Anim36Player250View1;
        rawValue2=Anim36Player48View2;
        rawValue3=Anim36Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=85;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim36Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        call498C0:Anim36Call498C0View1();
        return;
    case 91:
        rawValue2=Anim36Data7431CView1(1);
        if(rawValue2)return;
        rawValue2=Anim36PlayerB8View1<4;
        if(!rawValue2)goto airborne91;
        rawValue2=Anim36PlayerE4View1<23;
        if(rawValue2)goto held91;
        airborne91:__asm__ volatile(""::"i"(0x80085D68):"memory");
        nextSelector4=89;
        goto select;
        held91:rawValue2=Anim36Data6E538View1&128;
        if(rawValue2)goto age91;
        rawValue2=Anim36Player54View1<30;
        if(!rawValue2)goto input91;
        age91:rawValue2=Anim36Player54View1<120;
        if(rawValue2)return;
        input91:rawValue2=Anim36Data6E535View1;
        nextSelector4=85;
        if(rawValue2)goto select;
        nextSelector4=86;
        goto select;
    case 92:
        rawValue2=(int)Anim36Player250View1;
        callback3=Anim36Data7431CView1;
        record16=Anim36Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue3=Anim36Data6E53CView1;
        rawValue2=rawValue3&64;
        nextSelector4=93;
        if(rawValue2)goto select;
        rawValue2=Anim36PlayerB8View1<4;
        nextSelector4=89;
        if(!rawValue2)goto select;
        rawValue2=Anim36PlayerE4View1<23;
        if(!rawValue2)goto select;
        rawValue2=rawValue3&32;
        nextSelector4=87;
        if(rawValue2)goto select;
        rawValue2=rawValue3&128;
        nextSelector4=91;
        if(rawValue2)goto select;
        rawValue2=Anim36Data6E535View1;
        if(!rawValue2)goto held92;
        rawValue2=Anim36PlayerB0View1;
        nextSelector4=85;
        if(!rawValue2)goto select;
        held92:rawValue2=Anim36Data6E538View1&12;
        if(!rawValue2)goto angle92;
        rawValue2=Anim36Player144View1<16;
        nextSelector4=85;
        if(!rawValue2)goto select;
        angle92:rawValue2=Anim36Field(record16,int*,0x4C);
        nextSelector4=(int)frame.at10;
        if(!rawValue2)goto distance92;
        Anim36Call4F1C8View1((void*)nextSelector4,(void*)(rawValue2+12),Anim36Player0View1);
        rawValue2=Anim36Call4E880View1(frame.at10[0],frame.at10[1],1);
        rawValue3=Anim36PlayerA4View1;
        rawValue2-=rawValue3;
        rawValue3=rawValue2&4095;
        rawValue2=rawValue3<2049;
        if(!rawValue2)rawValue3-=4096;
        rawValue2=rawValue3;
        if(rawValue3<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<256;
        nextSelector4=96;
        if(rawValue2)goto select;
        distance92:rawValue2=Anim36PlayerB4View1<3072;
        if(!rawValue2)return;
        rawValue3=(int)Anim36Player250View1;
        rawValue2=Anim36Field((void*)rawValue3,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        rawValue2=Anim36Player48View2;
        rawValue3=Anim36Field((void*)rawValue3,unsigned char*,0x3C);
        rawValue2-=85;
        nextSelector4=86;
        if(rawValue3!=rawValue2)return;
        __asm__ volatile(""::"i"(0x80085F68):"memory");
        goto select;
    case 93:
        rawValue2=Anim36Data7431CView1(1);
        if(rawValue2)return;
        rawValue2=Anim36Data6E53CView1&32;
        nextSelector4=87;
        if(rawValue2)goto select;
        rawValue2=Anim36PlayerB8View1;
        if(rawValue2)goto finish93;
        rawValue2=Anim36Player54View1<16;
        if(rawValue2)goto finish93;
        rawValue2=Anim36PlayerE4View1<23;
        if(!rawValue2)return;
        rawValue3=Anim36PlayerCCView1;
        rawValue2=Anim36Player8CView1;
        product5=rawValue3*rawValue2;
        rawValue3=Anim36PlayerD0View1;
        rawValue2=Anim36Player90View1;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim36PlayerD4View1;
        rawValue2=Anim36Player94View1;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)return;
        rawValue2=Anim36PlayerACView1;
        nextSelector4=86;
        if(!rawValue2)goto select85;
        __asm__ volatile(""::"i"(0x80086060):"memory");
        goto select;
        finish93:nextSelector4=(int)Anim36Player250View1;
        rawValue2=Anim36Player48View2;
        rawValue3=Anim36Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=85;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim36Field((void*)nextSelector4,unsigned char*,0x42)&2;
        nextSelector4=94;
        if(!rawValue2)return;
        __asm__ volatile(""::"i"(0x8008609C):"memory");
        goto select;
    case 94:
        rawValue2=Anim36Data7431CView1(1);
        if(rawValue2)return;
        rawValue2=Anim36Data6E53CView1&32;
        nextSelector4=87;
        if(rawValue2)goto select;
        rawValue2=Anim36PlayerB8View1;
        if(rawValue2)goto finish94;
        rawValue2=Anim36Player54View1<16;
        if(rawValue2)goto finish94;
        rawValue2=Anim36PlayerE4View1<23;
        if(!rawValue2)return;
        rawValue3=Anim36PlayerCCView1;
        rawValue2=Anim36Player8CView1;
        product5=rawValue3*rawValue2;
        rawValue3=Anim36PlayerD0View1;
        rawValue2=Anim36Player90View1;
        nextSelector4=rawValue3*rawValue2;
        rawValue3=Anim36PlayerD4View1;
        rawValue2=Anim36Player94View1;
        rawValue3*=rawValue2;
        rawValue2=product5+nextSelector4;
        rawValue2+=rawValue3;
        if(rawValue2>=0)return;
        rawValue2=Anim36PlayerACView1;
        nextSelector4=86;
        if(!rawValue2)goto select85;
        __asm__ volatile(""::"i"(0x80086194):"memory");
        goto select;
        finish94:rawValue3=Anim36Player4CView1;
        rawValue2=1;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim36PlayerA0View1<-6400;
        nextSelector4=89;
        if(rawValue2)goto select;
        rawValue2=Anim36Player54View1<121;
        if(!rawValue2)goto select;
        return;
    case 95:
        rawValue2=(int)Anim36Player250View1;
        callback3=Anim36Data7431CView1;
        record16=Anim36Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue2=Anim36PlayerB8View1<4;
        if(!rawValue2)goto airborne95;
        rawValue2=Anim36PlayerE4View1<23;
        if(rawValue2)goto input95;
        airborne95:__asm__ volatile(""::"i"(0x8008623C):"memory");
        nextSelector4=89;
        goto select;
        input95:rawValue2=Anim36Data6E535View1;
        if(!rawValue2)goto held95;
        rawValue2=Anim36PlayerB0View1;
        nextSelector4=97;
        if(!rawValue2)goto select;
        held95:rawValue2=Anim36Data6E538View1&12;
        if(!rawValue2)goto private95;
        rawValue2=Anim36Player144View1<16;
        nextSelector4=97;
        if(!rawValue2)goto select;
        private95:rawValue2=Anim36Field(record16,int*,0x58)<16;
        nextSelector4=97;
        if(!rawValue2)goto select;
        rawValue2=Anim36Field(record16,int*,0x4C);
        nextSelector4=(int)frame.at10;
        if(!rawValue2)return;
        Anim36Call4F1C8View1((void*)nextSelector4,(void*)(rawValue2+12),Anim36Player0View1);
        rawValue2=Anim36Call4E880View1(frame.at10[0],frame.at10[1],1);
        rawValue3=Anim36PlayerA4View1;
        rawValue2-=rawValue3;
        rawValue3=rawValue2&4095;
        rawValue2=rawValue3<2049;
        if(!rawValue2)rawValue3-=4096;
        rawValue2=rawValue3;
        if(rawValue3<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<321;
        nextSelector4=97;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x8008631C):"memory");
        goto select;
    case 96:
        rawValue2=(int)Anim36Player250View1;
        callback3=Anim36Data7431CView1;
        record16=Anim36Field((void*)rawValue2,unsigned char**,0);
        rawValue2=callback3(1);
        if(rawValue2)return;
        rawValue2=Anim36PlayerB8View1<4;
        if(!rawValue2)goto airborne96;
        rawValue2=Anim36PlayerE4View1<23;
        if(rawValue2)goto input96;
        airborne96:__asm__ volatile(""::"i"(0x80086378):"memory");
        nextSelector4=89;
        goto select;
        input96:rawValue2=Anim36Data6E535View1;
        if(!rawValue2)goto held96;
        rawValue2=Anim36PlayerB0View1;
        nextSelector4=97;
        if(!rawValue2)goto select;
        held96:rawValue2=Anim36Data6E538View1&12;
        if(!rawValue2)goto private96;
        rawValue2=Anim36Player144View1<16;
        nextSelector4=97;
        if(!rawValue2)goto select;
        private96:rawValue2=Anim36Field(record16,int*,0x58)<16;
        nextSelector4=97;
        if(!rawValue2)goto select;
        nextSelector4=(int)Anim36Player250View1;
        rawValue2=Anim36Player48View2;
        rawValue3=Anim36Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=85;
        if(rawValue3!=rawValue2)goto angle96;
        rawValue2=Anim36Field((void*)nextSelector4,unsigned char*,0x42)&2;
        nextSelector4=95;
        if(rawValue2)goto select;
        angle96:rawValue2=Anim36Field(record16,int*,0x4C);
        nextSelector4=(int)frame.at20;
        if(!rawValue2)return;
        Anim36Call4F1C8View1((void*)nextSelector4,(void*)(rawValue2+12),Anim36Player0View1);
        rawValue2=Anim36Call4E880View1(frame.at20[0],frame.at20[1],1);
        rawValue3=Anim36PlayerA4View1;
        rawValue2-=rawValue3;
        rawValue3=rawValue2&4095;
        rawValue2=rawValue3<2049;
        if(!rawValue2)rawValue3-=4096;
        rawValue2=rawValue3;
        if(rawValue3<0)rawValue2=-rawValue2;
        rawValue2=rawValue2<321;
        nextSelector4=97;
        if(rawValue2)return;
        __asm__ volatile(""::"i"(0x8008648C):"memory");
        goto select;
    case 97:
        rawValue2=Anim36Data7431CView1(1);
        if(rawValue2)return;
        rawValue2=Anim36PlayerB8View1<4;
        if(!rawValue2)goto airborne97;
        rawValue2=Anim36PlayerE4View1<23;
        if(rawValue2)goto finish97;
        airborne97:__asm__ volatile(""::"i"(0x800864E0):"memory");
        nextSelector4=89;
        goto select;
        finish97:nextSelector4=(int)Anim36Player250View1;
        rawValue2=Anim36Player48View2;
        rawValue3=Anim36Field((void*)nextSelector4,unsigned char*,0x3C);
        rawValue2-=85;
        if(rawValue3!=rawValue2)return;
        rawValue2=Anim36Field((void*)nextSelector4,unsigned char*,0x42)&2;
        if(!rawValue2)return;
        select85:nextSelector4=85;
        goto select;
        default:return;
    }
    select:Anim36Call4BEF8View1(nextSelector4);
    return;
}
#undef Anim36Field
