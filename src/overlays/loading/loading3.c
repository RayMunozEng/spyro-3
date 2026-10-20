#include "common.h"
#include "drawutil.h"

extern unsigned char* D_8006C668;
extern int D_8006FBC4, D_8006C518, D_8006C76C, D_8006C598;
extern const char* D_loading_8007B708[];
extern const char* D_loading_8007B70C[];
void func_80059358(int, int);
void func_8004E7AC(void*, int, int);
void func_8003CDA0(void);
void DecodedLoadingFade(int, int, int, int) __asm__("func_800200A0");
void func_loading_80076EE8(void) {
    register int* timer __asm__("$16");
    func_80059358(0x80, 0x80);
    func_8004E7AC(D_8006C668 - 0x3000, 0, 0xC00);
    func_8003CDA0();
    timer = &D_8006FBC4;
    __asm__("" : "=r"(timer) : "0"(timer));
    if (*timer >= 0x78 && D_8006C518 >= 7) {
        func_80020344(D_loading_8007B708[D_8006C76C], 0x100, 0x1E, 2);
        {
            register int style __asm__("$7") = 2;
            register const char** table __asm__("$4") = D_loading_8007B70C;
            register unsigned int index __asm__("$3");
            register int ticks __asm__("$2");
            const char** entry;
            __asm__("" : "=r"(table) : "0"(table), "r"(style) : "$2", "$3");
            index = D_8006C76C;
            ticks = *timer;
            __asm__("" : "=r"(ticks) : "0"(ticks), "r"(index));
            index *= 4;
            __asm__("" : "=r"(index) : "0"(index), "r"(ticks));
            entry = (const char**)(index + (unsigned int)table);
            if ((ticks & 0x1F) < 0x16) style = 3;
            func_80020344(*entry, 0x100, 0xC8, style);
        }
    }
    if (D_8006C598) DecodedLoadingFade(2, D_8006C598, D_8006C598, D_8006C598);
}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Matched C. Original source asm/nonmatchings/overlays/loading/loading3/func_loading_80076FEC.s SHA256 499447bdd27786aa40bffe8397c18648f81448432f80add188464c85a844b9ad. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Loading76FECField(p,t,o) (*(t)((unsigned char*)(p)+(o)))

void Loading76FEC_CDLoadSync(int,void*,int,int) __asm__("CDLoadSync");
             /* extern */
                          /* extern */
                      /* extern */
unsigned char Loading76FEC_func_8001EBAC() __asm__("func_8001EBAC");
                            /* extern */
unsigned char Loading76FEC_func_8001FB10(int) __asm__("func_8001FB10");
                     /* extern */
unsigned char Loading76FEC_func_8002CA50() __asm__("func_8002CA50");
                            /* extern */
unsigned char Loading76FEC_func_80044240() __asm__("func_80044240");
                            /* extern */
unsigned char Loading76FEC_func_80047190() __asm__("func_80047190");
                            /* extern */
unsigned char Loading76FEC_func_8004BEF8(unsigned char) __asm__("func_8004BEF8");
                     /* extern */
void Loading76FEC_func_8004F178(void*,void*) __asm__("func_8004F178");
        /* extern */
void Loading76FEC_func_8004F1C8(void*,void*,void*) __asm__("func_8004F1C8");
 /* extern */
extern int Loading76FEC_D_80011254 __asm__("D_80011254");
extern int Loading76FEC_D_8006C518 __asm__("D_8006C518");
extern int Loading76FEC_D_8006C58C __asm__("D_8006C58C");
extern int Loading76FEC_D_8006C598 __asm__("D_8006C598");
extern int Loading76FEC_D_8006C648 __asm__("D_8006C648");
extern int Loading76FEC_D_8006C714 __asm__("D_8006C714");
extern int Loading76FEC_D_8006C718 __asm__("D_8006C718");
extern unsigned char Loading76FEC_D_8006D8D8 __asm__("D_8006D8D8");
extern struct {int word0;
int pad[3];
} Loading76FEC_D_8006DBE0[] __asm__("D_8006DBE0");
extern int Loading76FEC_D_8006E020 __asm__("D_8006E020");
extern int Loading76FEC_D_8006E024 __asm__("D_8006E024");
extern int Loading76FEC_D_8006E028 __asm__("D_8006E028");
extern int Loading76FEC_D_8006E038 __asm__("D_8006E038");
extern short Loading76FEC_D_8006E03C __asm__("D_8006E03C");
extern short Loading76FEC_D_8006E03E __asm__("D_8006E03E");
extern short Loading76FEC_D_8006E040 __asm__("D_8006E040");
extern int Loading76FEC_D_8006E470 __asm__("D_8006E470");
extern int Loading76FEC_D_8006E53C __asm__("D_8006E53C");
extern int Loading76FEC_D_8006FBC4 __asm__("D_8006FBC4");
extern int Loading76FEC_D_8006FBC8 __asm__("D_8006FBC8");
extern unsigned char Loading76FEC_D_80070328 __asm__("D_80070328");
extern int Loading76FEC_D_80072098 __asm__("D_80072098");
extern int Loading76FEC_D_800722D0 __asm__("D_800722D0");

void func_loading_80076FEC(void) {
    /* Original 0x40 frame: RECT at SP10, three-word scratch vector at
     * SP18, padding through SP27 and saved registers beginning at SP28.
     * The image payload adds 0x1C BYTES before conversion to u_long*.
     * Both ratio numerators are produced before register2 is reused for a
     * coordinate write, retaining the original MULT/MFHI ordering. The
     * CD table has 16-byte records and reads word0;
      its native indexed
     * relocation is retained. BufferPointer18 is reloaded for both calls.
     * Empty constraints preserve register producers and read order;
      the
     * scratch sector4 output is overwritten by its disc load before use.
     * No CPU instructions are emitted by these constraints. Raw field
     * units, helper meanings, update cadence and synchronized runtime
     * validation remain unresolved. AI generated;
      not human reviewed. */
    struct {RECT rect;
    Vector3D vector;
    int pad24;
    } scratch;
    register Vector3D *scratchVector19 __asm__("$19");
    short unusedRectangleY;
    register int raw2 __asm__("$2");
    register int raw3 __asm__("$3");
    register int *counterPointer4 __asm__("$4");
    register int *bufferPointer18 __asm__("$18");
    register int rectangleWidth17 __asm__("$17");
    register int sector4 __asm__("$4");
    register void *data5 __asm__("$5");
    register int readLength6 __asm__("$6");
    register int readOffset7 __asm__("$7");
    register RECT *rectangle4 __asm__("$4");
    register int coordinate7 __asm__("$7");
    register int unusedCoordinate7 __asm__("$7");
    register int state16 __asm__("$16");
    register int counter2 __asm__("$2");
    register int remaining2 __asm__("$2");
    register int incrementedCounter3 __asm__("$3");
    register int blockIndex16 __asm__("$16");

    state16 = Loading76FEC_D_8006FBC8;
    switch (state16) {                              /* irregular */
    case 1:
        counter2 = Loading76FEC_D_8006FBC4;
        if (counter2 == 0) {
            Loading76FEC_func_8001FB10(0x1C000);
            Loading76FEC_CDLoadSync(Loading76FEC_D_8006E470,(void*)(Loading76FEC_D_80011254+Loading76FEC_D_8006C714), Loading76FECField(&Loading76FEC_D_8006D8D8, int *, 0x58C), Loading76FECField(&Loading76FEC_D_8006D8D8, int *, 0x588));
            scratch.rect.x = 0x200;
            scratch.rect.w = 0x200;
            scratch.rect.y = 0;
            scratch.rect.h = 0xD8;
            LoadImage(&scratch.rect, (u_long*)(Loading76FEC_D_80011254+Loading76FEC_D_8006C714+0x1C));
            DrawSync(0);
            Loading76FEC_D_8006E020 = 0x2000;
            Loading76FEC_D_8006E024 = 0x2000;
            Loading76FEC_D_8006E028 = 0x2000;
            Loading76FEC_D_8006E03C = 0;
            Loading76FEC_D_8006E03E = -0x30;
            Loading76FEC_D_8006E040 = 0;
            Loading76FEC_D_8006E038 = 0;
            Loading76FEC_func_80047190();
            Loading76FEC_func_8004BEF8(0x11);
            Loading76FEC_func_80044240();
            counter2=Loading76FEC_D_8006FBC4;
        }
        Loading76FEC_D_8006C648 = state16;
        __asm__ volatile("# counter-after-init":"=r"(counter2):"0"(counter2));
        Loading76FEC_D_8006FBC4=counter2+1;
        Loading76FEC_func_80044240();
        scratchVector19=&scratch.vector;
        if (Loading76FEC_D_8006FBC4 < 0x78) {
            Loading76FEC_func_8004F178(scratchVector19, &Loading76FEC_D_80070328);
            remaining2 = 0x78 - Loading76FEC_D_8006FBC4;
            raw3=remaining2*125;
            raw2=raw3<<3;
            raw3=(raw2-raw3)<<2;
            coordinate7=raw2/120;
            raw2=coordinate7+0x2AF8;
            coordinate7+=0x2247;
            Loading76FECField(&Loading76FEC_D_80070328,int*,0)=raw2;
            Loading76FECField(&Loading76FEC_D_80070328,int*,8)=coordinate7;
            raw2=raw3/120;
            raw2+=0x209E;
            Loading76FECField(&Loading76FEC_D_80070328,int*,4)=raw2;
            Loading76FEC_func_8004F1C8(scratchVector19,&Loading76FEC_D_80070328,scratchVector19);
            Loading76FECField(&Loading76FEC_D_80070328, signed char *, 0xC) = 0;
            Loading76FECField(&Loading76FEC_D_80070328, signed char *, 0xD) = 0;
            Loading76FECField(&Loading76FEC_D_80070328, signed char *, 0xE) = (signed char) ((((0x78 - Loading76FEC_D_8006FBC4) * 0x50) / 120) - 0x60);
            if (Loading76FEC_D_8006FBC4 == 0x74) {
                Loading76FEC_func_8004BEF8(0xF);
            }
        } else if (Loading76FEC_D_8006FBC4 == 0x78) {
            raw2=0x2AF8;
            __asm__("":"=r"(raw2):"0"(raw2));
            Loading76FECField(&Loading76FEC_D_80070328,int*,0)=raw2;
            raw2=0x209E;
            __asm__("":"=r"(raw2):"0"(raw2));
            Loading76FECField(&Loading76FEC_D_80070328,int*,4)=raw2;
            raw2=0x2247;
            __asm__("":"=r"(raw2):"0"(raw2));
            Loading76FECField(&Loading76FEC_D_80070328,int*,8)=raw2;
            Loading76FECField(&Loading76FEC_D_80070328, signed char *, 0xC) = 0;
            Loading76FECField(&Loading76FEC_D_80070328, signed char *, 0xD) = 0;
            raw2=0xA0;
            __asm__("":"=r"(raw2):"0"(raw2));
            Loading76FECField(&Loading76FEC_D_80070328,signed char*,14)=raw2;
        }
        if (Loading76FEC_D_8006C518 < 8) {
            Loading76FEC_func_8002CA50();
        }
        counterPointer4=&Loading76FEC_D_8006FBC4;
        raw3=*counterPointer4;
        if(raw3<17) {Loading76FEC_D_8006C598=(16-raw3)*16;
        }
        raw2=raw3<120;
        __asm__("":"=r"(raw2):"0"(raw2));
        if(!raw2) {
            raw2=Loading76FEC_D_8006C518;
            __asm__("":"=r"(raw2):"0"(raw2));
            raw2=raw2<7;
            if(!raw2) {
                raw2=Loading76FEC_D_8006E53C;
                __asm__("":"=r"(raw2):"0"(raw2));
                raw2&=0x840;
                if(raw2) {raw2=2;
                __asm__("":"=r"(raw2):"0"(raw2));
                Loading76FEC_D_8006FBC8=raw2;
                *counterPointer4=0;
                return;
                }
            }
        }
        return;
    case 2:
        raw2=Loading76FEC_D_8006FBC4;
        incrementedCounter3=raw2+1;
        raw2=incrementedCounter3<16;
        __asm__("":"=r"(raw2),"=r"(incrementedCounter3):"0"(raw2),"1"(incrementedCounter3));
        Loading76FEC_D_8006FBC4=incrementedCounter3;
        if (raw2) {
            raw2=incrementedCounter3<<4;
            Loading76FEC_D_8006C598=raw2;
            return;
        }
        __asm__ volatile("":::"$2");
        blockIndex16=0;
        Loading76FEC_func_8001EBAC();
        bufferPointer18=&Loading76FEC_D_800722D0;
        rectangleWidth17=512;
        readLength6=0x20000;
        do {
            readOffset7=blockIndex16<<17;
            raw2=Loading76FEC_D_8006C58C;
            __asm__ volatile("":"=r"(sector4)::"memory");
            sector4=Loading76FEC_D_8006E470;
            raw3=Loading76FEC_D_80072098;
            raw2=Loading76FEC_D_8006DBE0[raw2].word0;
            data5=(void*)*bufferPointer18;
            raw3+=raw2;
            Loading76FEC_CDLoadSync(sector4,data5,readLength6,raw3+readOffset7);
            rectangle4=&scratch.rect;
            __asm__("":"=r"(rectangle4):"0"(rectangle4));
            raw2=blockIndex16<<7;
            data5=(void*)*bufferPointer18;
            blockIndex16+=1;
            scratch.rect.y=raw2;
            raw2=128;
            scratch.rect.x=rectangleWidth17;
            scratch.rect.w=rectangleWidth17;
            scratch.rect.h=raw2;
            LoadImage(rectangle4,(u_long*)data5);
            readLength6=0x20000;
        } while (blockIndex16 < 4);
        Loading76FEC_D_8006FBC8 = 3;
        Loading76FEC_D_8006FBC4 = 0;
        Loading76FEC_D_8006C718 = 1;
        break;
    }
}
#undef Loading76FECField


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. UNINSTALLED inferred C. Original source asm/nonmatchings/overlays/loading/loading3/func_loading_80077438.s SHA256 3bd658d3bbb1336cd0ef2d2b8997f099fb204d11784654a9b3a3f038a07be7f2. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Loading77438Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))

int Loading77438_80079240() __asm__("func_loading_80079240");
                        /* extern */
unsigned char Loading77438_80079BA8(int) __asm__("func_loading_80079BA8");
                 /* extern */
unsigned char Loading77438_80079C18(int) __asm__("func_loading_80079C18");
                  /* extern */
unsigned char Loading77438_80079FDC(int) __asm__("func_loading_80079FDC");
                 /* extern */
unsigned char Loading77438_8007A718(int, int, void *, int, int) __asm__("func_loading_8007A718");
 /* extern */
int Loading77438_8007ABC8(int, unsigned char *, void *) __asm__("func_loading_8007ABC8");
 /* extern */
extern int Loading77438_D_8006C548 __asm__("D_8006C548");
extern int Loading77438_D_8006C5BC __asm__("D_8006C5BC");
extern int Loading77438_D_8006C648 __asm__("D_8006C648");
extern int Loading77438_D_8006C658 __asm__("D_8006C658");
extern int Loading77438_D_8006E344 __asm__("D_8006E344");
extern unsigned char Loading77438_D_800725B0 __asm__("D_800725B0");
extern int Loading77438_D_800725B8 __asm__("D_800725B8");
extern int Loading77438_D_800725BC __asm__("D_800725BC");
extern int Loading77438_D_800725C0 __asm__("D_800725C0");
extern int Loading77438_D_800725C4 __asm__("D_800725C4");
extern int Loading77438_D_800725C8 __asm__("D_800725C8");
extern int Loading77438_D_800725E0 __asm__("D_800725E0");
extern int Loading77438_D_800725E4 __asm__("D_800725E4");
extern int Loading77438_D_800725E8 __asm__("D_800725E8");
extern int Loading77438_D_loading_8007B710 __asm__("D_loading_8007B710");
extern unsigned char Loading77438_D_loading_8007B954 __asm__("D_loading_8007B954");
extern unsigned char Loading77438_D_loading_8007B955 __asm__("D_loading_8007B955");
extern unsigned char Loading77438_D_loading_8007B956 __asm__("D_loading_8007B956");
extern unsigned char Loading77438_D_loading_8007B95A __asm__("D_loading_8007B95A");
extern int Loading77438_D_loading_8007B95C __asm__("D_loading_8007B95C");
extern unsigned char Loading77438_D_loading_8007BBFC __asm__("D_loading_8007BBFC");

extern unsigned char Loading77438_phasePrevious __asm__("D_loading_8007B956 + 1");
int func_loading_80077438(void) {
    /* Original SCUS-94467 loading3 function at 0x80077438: 331 code
     * words and seven owned jump-table selectors at 0x80074510.
     * Frame size 0x28;
      saved registers16/17/18 at SP18/SP1C/SP20.
     * Header word reads use byte offsets 0 and 4. Payload selection
     * multiplies the original word index by 0x900 BYTES, then passes
     * offset+0x280 and read length128 to the five-argument helper.
     * Shared result stores and retry/increment paths retain their
     * original instruction targets. Empty constraints preserve the raw
     * selector, constant arguments and register producers without
     * emitting CPU instructions. Units, helper semantics, frame cadence
     * and synchronized runtime verification remain unresolved.
     * AI generated;
      not human reviewed. */
 register int completion2 __asm__("$2");
 register int completion3 __asm__("$3");
    register int payloadOffset7 __asm__("$7");
    register int callResult3 __asm__("$3");
    register int result18 __asm__("$18");
    register int unused2 __asm__("$2");
    register int maskedPhase3 __asm__("$3");
    register unsigned char *headerPointer16 __asm__("$16");
    register unsigned char *firstPhasePointer17 __asm__("$17");
    register int scratch2 __asm__("$2");
    register int input4 __asm__("$4");
    register unsigned char *unusedPointer6 __asm__("$6");
    register int scratch3 __asm__("$3");
    register int headerWord5 __asm__("$5");
    register int selector3 __asm__("$3");
    register unsigned char *sharedPhasePointer16 __asm__("$16");
    register int phase4 __asm__("$4");
    result18=0;
    if(Loading77438_D_8006E344==9)return 1;
    if(Loading77438_D_8006C5BC>=60)return 1;
    if(Loading77438_D_8006C658)return 1;
    if(Loading77438_D_8006C548)return 1;
    selector3=Loading77438_D_loading_8007B954;
    __asm__("":"=r"(selector3):"0"(selector3));
    switch(selector3) {
    case 0:
        __asm__ volatile("":"=r"(selector3):"0"(selector3));
        scratch2=Loading77438_D_800725B8;
        if(!scratch2)goto invalidInputs;
        input4=Loading77438_D_800725BC;
        __asm__("":"=r"(input4):"0"(input4));
        if(input4<0)goto invalidInputs;
        scratch3=Loading77438_D_800725C0;
        __asm__("":"=r"(scratch3):"0"(scratch3));
        if(scratch3>=0)goto checkChanged;
invalidInputs:
        Loading77438_D_800725B8=0;
        Loading77438_D_loading_8007B954=4;
        goto afterSwitch;
checkChanged:
        if(Loading77438_D_800725E8) {
            Loading77438_D_800725E8=0;
            Loading77438_D_loading_8007B954=5;
            goto afterSwitch;
        }
        Loading77438_D_800725E0=input4;
        Loading77438_D_800725E4=scratch3;
        Loading77438_80079BA8(input4);
        Loading77438_D_loading_8007B954=1;
        goto afterSwitch;
    case 1:
        phase4=1;
        __asm__("":"=r"(phase4):"0"(phase4):"memory");
        headerPointer16=&Loading77438_D_800725B0;
        if(!Loading77438_8007ABC8(phase4,headerPointer16,headerPointer16+4))goto afterSwitch;
        scratch2=1;
        __asm__("":"=r"(scratch2):"0"(scratch2));
        firstPhasePointer17=&Loading77438_D_loading_8007B956;
        phase4=*firstPhasePointer17;
        __asm__("":"=r"(phase4):"0"(phase4));
        if(phase4==scratch2)goto firstPhase1;
        scratch2=phase4<2;
        if(!scratch2)goto firstTest2;
        if(!phase4)goto firstPhase0;
        goto afterSwitch;
firstTest2:
        scratch2=2;
        if(phase4==scratch2)goto firstPhase2;
        goto afterSwitch;
firstPhase0:
        Loading77438_80079FDC(Loading77438_D_800725E0*16);
        goto incrementFirstPhase;
firstPhase1:
        headerWord5=Loading77438Field(headerPointer16,int*,4);
        if(!headerWord5)goto firstLoad;
        if(headerWord5!=3)goto firstRetry1;
firstLoad:
        scratch2=128;
        __asm__("":"=r"(scratch2):"0"(scratch2));
        Loading77438_8007A718(Loading77438_D_800725E0*16,Loading77438_D_loading_8007B710,
           &Loading77438_D_loading_8007BBFC+Loading77438_D_800725E4*0x900,
           Loading77438_D_800725E4*0x900+0x280,scratch2);
incrementFirstPhase:
        *firstPhasePointer17+=1;
        goto afterSwitch;
firstRetry1:
        scratch3=Loading77438_D_loading_8007B95A;
        if((unsigned int)scratch3<3) {scratch2=scratch3+1;
         *firstPhasePointer17=0;
        Loading77438_D_loading_8007B95A=scratch2;
        goto afterSwitch;
         }
        scratch2=4;
        if(headerWord5==scratch2) {scratch2=2;
        goto storeResult;
        }
        Loading77438_D_800725C8=phase4;
        scratch2=6;
        goto storeState6;
firstPhase2:
        headerWord5=Loading77438Field(headerPointer16,int*,4);
        if(headerWord5==5)goto firstError;
        if(headerWord5)goto firstRetry;
        scratch3=Loading77438_D_800725E4;
        scratch3=Loading77438Field(&Loading77438_D_loading_8007BBFC,int*,scratch3*0x900);
        if(scratch3!=Loading77438_D_800725C4)goto firstError;
        Loading77438_D_loading_8007B954=2;
        goto afterSwitch;
firstError:
        Loading77438_D_800725C8=phase4;
        Loading77438_D_loading_8007B954=6;
        __asm__ volatile("# first-error6");
        goto afterSwitch;
firstRetry:
        scratch3=Loading77438_D_loading_8007B95A;
        if((unsigned int)scratch3>=3)goto fallback3;
        scratch2=scratch3+1;
        Loading77438_D_loading_8007B95A=scratch2;
        *firstPhasePointer17=0;
        goto afterSwitch;
                case 2:
                    callResult3 = Loading77438_80079240();
                    __asm__("":"=r"(callResult3):"0"(callResult3));
                    if(callResult3==-1) {
fallback3:
                        scratch2=3;
storeResult:
                         Loading77438_D_800725C8=scratch2;
                         scratch2=6;
storeState6:
                         Loading77438_D_loading_8007B954=scratch2;
                         goto afterSwitch;
                    }
                    if (callResult3 == 1) {
                        Loading77438_D_loading_8007B954 = 3;
                    }
                    goto afterSwitch;

    case 3:
        if(Loading77438_8007ABC8(1,&Loading77438_D_800725B0,&Loading77438_D_800725B0+4)) {
            scratch2=1;
            __asm__("":"=r"(scratch2):"0"(scratch2));
            sharedPhasePointer16=&Loading77438_D_loading_8007B956;
            phase4=*sharedPhasePointer16;
            __asm__("":"=r"(phase4):"0"(phase4));
            maskedPhase3=phase4&255;
            if(maskedPhase3==scratch2)goto timedPhase;
            if(maskedPhase3<2)goto zeroPhase;
            if(maskedPhase3!=2)goto afterSwitch;
        }else goto afterSwitch;
    case 4:
    case 5:
        result18=1;
        goto afterSwitch;
    case 6:
        if(Loading77438_8007ABC8(1,&Loading77438_D_800725B0,&Loading77438_D_800725B0+4)) {
            scratch2=1;
            __asm__("":"=r"(scratch2):"0"(scratch2));
            sharedPhasePointer16=&Loading77438_D_loading_8007B956;
            phase4=*sharedPhasePointer16;
            __asm__("":"=r"(phase4):"0"(phase4));
            maskedPhase3=phase4&255;
            if(maskedPhase3==scratch2)goto timedPhase;
            if(maskedPhase3>=2)goto negativeTest;
            goto zeroPhase;
        }
        goto afterSwitch;
    default:goto afterSwitch;
    }
zeroPhase:
    if(!maskedPhase3)goto zeroCall;
    goto afterSwitch;
negativeTest:
    if(maskedPhase3==2)goto negativeResult;
    goto afterSwitch;
zeroCall:
    Loading77438_80079C18(phase4);
    *sharedPhasePointer16+=1;
    goto afterSwitch;
timedPhase:
    if(Loading77438_D_loading_8007B95C>=90) {scratch2=phase4+1;
    *sharedPhasePointer16=scratch2;
    }
    goto afterSwitch;
negativeResult:
    result18=-1;
afterSwitch:
    completion3=Loading77438_D_loading_8007B954;
    completion2=Loading77438_D_loading_8007B955;
    if(completion3==completion2)goto comparePhase;
    completion2=result18;
    Loading77438_D_loading_8007B955=completion3;
    Loading77438_D_loading_8007B956=0;
    Loading77438_phasePrevious=0;
    Loading77438_D_loading_8007B95A=0;
    Loading77438_D_loading_8007B95C=0;
    goto done;
comparePhase:
    completion3=Loading77438_D_loading_8007B956;
    completion2=Loading77438_phasePrevious;
    if(completion3==completion2)goto incrementTimer;
    completion2=result18;
    Loading77438_phasePrevious=completion3;
    Loading77438_D_loading_8007B95C=0;
    goto done;
incrementTimer:
    completion2=Loading77438_D_loading_8007B95C;
    completion3=Loading77438_D_8006C648;
    completion2+=completion3;
    Loading77438_D_loading_8007B95C=completion2;
    completion2=result18;
done:
    return completion2;
}
#undef Loading77438Field


/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80077964.
 * AI generated; not human reviewed. All837 native/linked instructions,every
 * actual transfer/data target,EXE and every overlay retail hash must match.
 * No owned selectors,padding or separate initializer objects. Original68hex
 * frame104 bytes saves S0..S5/RA;48-byte text bufferSP18..47 and original
 * fifth outgoing SP10 argument remain. Unwritten padding is never read.
 * Verified625 reuse retains only independently present text/table/math/draw
 * instructions. Original1/2,3,4 dispatch and extra31124 call remain. Cases3/4
 * each retain the original actor at archiveBase+36000hex,field widths and
 * duplicate initialization order. Original C528 low16 is stored to36036;
 * class651 uses signed C644%10,307 adjustment and original packed-byte stores.
 * Class516 uses34F80,byte200 and exact -2048/+1280 coordinate adjustments;
 * other classes use640. These are raw source words,not inferred physical units.
 * All MULT sites have complete initialized signed64 C products. New /10
 * products use66666667 high,SRA2,sign correction before remainder; retained
 * /40 uses the same magic,SRA4/sign. Low consumers narrow signed32 before
 * original arithmetic shifts and dynamic divisions. All original traps remain.
 * The division constant stages66660000 thenOR6667 as two fully initialized
 * C words,matching original LUI/ORI around byte stores and the scalar load.
 * No partial HILO producer is used. Original record byte4C is written once
 * here; the extra625 write is absent. Case4 table indices use original fresh
 * C4 timer reads. Table resides in S4,255 in S5,as original;no fixedFP/SP.
 * Empty metadata consumes full initialized values/addresses/products or its
 * already-written record byte68;dead clobbers precede fresh producers. No
 * opcode asm,incoming saved values,unwritten padding or live fixed aliases.
 * Falsification:every original word/target/hash;/10 -11->-1,-1->0,0->0,10->1;
 * /40 -41->-1,-1->0,0->0,40->1,41->1. All scalar pointers are byte addresses.
 * Known helper views reuse drawutil,mobyfunc,memcard,cyclorama,mobydraw and
 * matched stdutil/sprintf contracts. Confidence is binary identity after all
 * gates. Full producer/helper/consumer/caller chains,units/fixed point,cadence
 * beyond invocation,buffer bounds and synchronized retail runtime remain open.
 * Compiler/filter/flags and engine/browser unchanged. Next:human review and
 * synchronized retail captures;binary matching alone is no runtime claim.
 */
/* Original assembly SHA256 39b37a5040ba2d93e7c3c6085d79474e4ac9dddb8f6d210282c2f1d67abac642 */
#define Loading77964CompleteProductLow(a,b) ({int left=(a),right=(b),low;long long product;__asm__("":"=r"(left),"=r"(right):"0"(left),"1"(right));product=(long long)left*(long long)right;__asm__("":"=l"(low):"x"(product));low;})
extern volatile int Loading77964Data6FBC4View1 __asm__("D_8006FBC4");
#define Loading77964Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
void Loading77964CallDrawStringCenteredView1(char*,int,int,int) __asm__("DrawStringCentered");
void Loading77964CallDrawStringRightAlignedView1(char*,int,int,int) __asm__("DrawStringRightAligned");
void Loading77964Call1C368View1(void) __asm__("func_8001C368");
void Loading77964Call1EDECView1() __asm__("func_8001EDEC");
int Loading77964Call200A0View1() __asm__("func_800200A0");
void Loading77964Call20428View1(int,int,int,int) __asm__("func_80020428");
void Loading77964Call2E748View1(char*,int,int,int,int*) __asm__("func_8002E748");
void Loading77964Call30478View1(void) __asm__("func_80030478");
void Loading77964Call33C5CView1(void) __asm__("func_80033C5C");
int Loading77964Call3CDA0View1() __asm__("func_8003CDA0");
void Loading77964Call4E790View1(void*,int,int) __asm__("func_8004E790");
int Loading77964Call4E7ACView1() __asm__("func_8004E7AC");
int Loading77964Call75114View1() __asm__("func_loading_80075114");
int Loading77964CallsprintfView1(char*,const char*,...) __asm__("sprintf");
extern unsigned char Loading77964Data658A0View1 __asm__("D_800658A0");
extern unsigned char Loading77964Data65920View1 __asm__("D_80065920");
extern unsigned char Loading77964Data674C0View1 __asm__("D_800674C0");
extern unsigned char Loading77964Data674D8View1 __asm__("D_800674D8");
extern unsigned char Loading77964Data674E8View1 __asm__("D_800674E8");
extern unsigned char Loading77964Data674FCView1 __asm__("D_800674FC");
extern unsigned char Loading77964Data67510View1 __asm__("D_80067510");
extern unsigned char Loading77964Data67520View1 __asm__("D_80067520");
extern unsigned char Loading77964Data69CF8View1 __asm__("D_80069CF8");
extern unsigned char Loading77964Data69DC8View1 __asm__("D_80069DC8");
extern unsigned char Loading77964Data69DCCView1 __asm__("D_80069DCC");
extern unsigned char Loading77964Data69DD0View1 __asm__("D_80069DD0");
extern unsigned char Loading77964Data69DD4View1 __asm__("D_80069DD4");
extern int Loading77964Data6C508View1 __asm__("D_8006C508");
extern void * Loading77964Data6C550View1 __asm__("D_8006C550");
extern int Loading77964Data6C58CView1 __asm__("D_8006C58C");
extern int Loading77964Data6C598View1 __asm__("D_8006C598");
extern void * Loading77964Data6C604View1 __asm__("D_8006C604");
extern int Loading77964Data6C60CView1 __asm__("D_8006C60C");
extern int Loading77964Data6C668View1 __asm__("D_8006C668");
extern int Loading77964Data6C6F8View1 __asm__("D_8006C6F8");
extern int Loading77964Data6C71CView1 __asm__("D_8006C71C");
extern int Loading77964Data6C720View1 __asm__("D_8006C720");
extern int Loading77964Data6C764View1 __asm__("D_8006C764");
extern int Loading77964Data6C76CView1 __asm__("D_8006C76C");
extern int Loading77964Data6D058View1 __asm__("D_8006D058");
extern unsigned char Loading77964Data6E3B0View1 __asm__("D_8006E3B0");
extern int Loading77964Data6FBC4View2 __asm__("D_8006FBC4");
extern int Loading77964Data6FBC8View1 __asm__("D_8006FBC8");
extern unsigned char Loading77964Data70328View1 __asm__("D_80070328");
extern unsigned char Loading77964Data71A10View1 __asm__("D_80071A10");
extern void * Loading77964Data722D0View1 __asm__("D_800722D0");
extern unsigned char Loading77964Data74504View1 __asm__("D_loading_80074504");
void Loading77964Call31124View1(void) __asm__("func_80031124");
void Loading77964Call34F80View1(void*,int) __asm__("func_80034F80");
void Loading77964Call4F178View1(void*,void*) __asm__("func_8004F178");
extern int Loading77964Data6C528View1 __asm__("D_8006C528");
extern int Loading77964Data6C644View1 __asm__("D_8006C644");
void func_loading_80077964(void) {
    register int actorBaseOffsetOrAmount16 __asm__("$16");
    register int byteCursorRowOrSavedWord17 __asm__("$17");
    register int actorThenRecordIndex18 __asm__("$18");
    register int argumentWord5 __asm__("$5");
    register int argumentWord6 __asm__("$6");
    register int argumentWord7 __asm__("$7");
    register int argumentWord4 __asm__("$4");
    register int rawWord2 __asm__("$2");
    register int rawWord3 __asm__("$3");
    register int signedHalfwordTable20 __asm__("$20"),originalByte255In21 __asm__("$21");
    register int signedFortiethMagic19 __asm__("$19"),completeProductHalf8 __asm__("$8");
    char originalTextBuffer[48];
    rawWord3=Loading77964Data6FBC8View1;
    __asm__("":"=r"(rawWord3):"0"(rawWord3));
    switch(rawWord3) {
    case 1:
    case 2:
        if (Loading77964Data6FBC4View2 < 0x10) {
            Loading77964Call1EDECView1();
            Loading77964Call4E7ACView1(Loading77964Data6C668View1 - 0x3000, 0, 0xC00);
            goto queueOriginalCommonDraw;
        }
        break;
    case 3:
        {
            long long completeSignedTenthProduct;
            int completeTenthHighWord;
            rawWord2=0x36000;
            argumentWord5=0;
            actorBaseOffsetOrAmount16=(int)Loading77964Data722D0View1;
            argumentWord6=88;
            rawWord2=actorBaseOffsetOrAmount16+rawWord2;
            actorThenRecordIndex18=rawWord2;
            Loading77964Data6C550View1=(void*)actorThenRecordIndex18;
            Loading77964Call4E790View1((void*)actorThenRecordIndex18,argumentWord5,argumentWord6);
            rawWord2=Loading77964Data6C528View1;
            argumentWord5=(int)&Loading77964Data70328View1;
            Loading77964Field(actorBaseOffsetOrAmount16,short*,0x36036)=rawWord2;
            Loading77964Call4F178View1(actorThenRecordIndex18+12,argumentWord5);
            rawWord3=Loading77964Field((int)&Loading77964Data70328View1,unsigned char*,14);
            rawWord2=4;
            Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x36047)=rawWord2;
            rawWord2=32;
            Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x3604C)=rawWord2;
            Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x3604E)=rawWord2;
            rawWord2=255;
            Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x36052)=rawWord2;
            Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x36046)=rawWord3;
            rawWord3=Loading77964Field(actorBaseOffsetOrAmount16,short*,0x36036);
            rawWord2=651;
            if(rawWord3==rawWord2){
                rawWord3=0x66660000;
                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                rawWord2=1;
                Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x3603C)=rawWord2;
                Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x3603D)=rawWord2;
                argumentWord4=Loading77964Data6C644View1;
                __asm__ volatile("":"=r"(rawWord3):"0"(rawWord3):"memory");
                rawWord3|=0x6667;
                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                completeSignedTenthProduct=(long long)argumentWord4*(long long)rawWord3;
                rawWord2=argumentWord4>>31;
                __asm__("":"=h"(completeTenthHighWord):"x"(completeSignedTenthProduct),"r"(rawWord2));
                completeProductHalf8=completeTenthHighWord;
                __asm__("":"=r"(completeProductHalf8):"0"(completeProductHalf8));
                rawWord3=completeProductHalf8>>2;
                rawWord3-=rawWord2;
                rawWord2=rawWord3*10;
                rawWord3=argumentWord4-rawWord2;
                rawWord2=rawWord3>>1;
                rawWord3--;
                Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x3603F)=rawWord2;
                __asm__ volatile("":::"$17","memory");
                byteCursorRowOrSavedWord17=307;
                if(rawWord3<0)rawWord3+=10;
                rawWord2=rawWord3>>1;
                Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x3603E)=rawWord2;
                rawWord2=(rawWord3&1)<<7;
                Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x36040)=rawWord2;
            }
            else{
                byteCursorRowOrSavedWord17=640;
                if(rawWord3==516){
                    byteCursorRowOrSavedWord17=1540;
                    Loading77964Call34F80View1(actorThenRecordIndex18,2);
                    rawWord2=200;
                    Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x36045)=rawWord2;
                    rawWord2=Loading77964Field(actorBaseOffsetOrAmount16,int*,0x3600C);
                    rawWord3=Loading77964Field(actorBaseOffsetOrAmount16,int*,0x36014);
                    rawWord2-=2048;
                    rawWord3+=1280;
                    Loading77964Field(actorBaseOffsetOrAmount16,int*,0x3600C)=rawWord2;
                    Loading77964Field(actorBaseOffsetOrAmount16,int*,0x36014)=rawWord3;
                }
            }
            rawWord3=Loading77964Field((int)&Loading77964Data70328View1,int*,68);
            rawWord2=Loading77964Field(actorThenRecordIndex18,int*,20);
            argumentWord4=(int)Loading77964Data6C550View1;
            rawWord3+=byteCursorRowOrSavedWord17;
            rawWord2-=rawWord3;
            Loading77964Field(actorThenRecordIndex18,int*,20)=rawWord2;
            rawWord2=argumentWord4+88;
            Loading77964Data6C604View1=(void*)rawWord2;
            rawWord2=255;
            Loading77964Field(argumentWord4,unsigned char*,160)=rawWord2;
        }
        if ((unsigned int) (Loading77964Data6FBC4View2 - 0x21) < 0x48U) {
            actorThenRecordIndex18 = 0;
            signedFortiethMagic19=0x66666667;
            __asm__("":"=r"(signedFortiethMagic19):"0"(signedFortiethMagic19));
            signedHalfwordTable20=(int)&Loading77964Data658A0View1;
            __asm__("":"=r"(signedHalfwordTable20):"0"(signedHalfwordTable20));
            originalByte255In21=255;
            __asm__("":"=r"(originalByte255In21):"0"(originalByte255In21));
            byteCursorRowOrSavedWord17 = (int)&Loading77964Data6E3B0View1;
            do {
                actorBaseOffsetOrAmount16 = actorThenRecordIndex18 * 8;
                if (Loading77964Field((actorBaseOffsetOrAmount16 + Loading77964Data6C764View1), unsigned char *, 4) != 0) {
                    Loading77964Call4E790View1(Loading77964Data6C604View1,0,0x58);
                    Loading77964Field(Loading77964Data6C604View1, short *, 0x36) = 1;
                    Loading77964Field(Loading77964Data6C604View1, unsigned char *, 0x3C) = (unsigned char) Loading77964Field(byteCursorRowOrSavedWord17,unsigned char*,0);
                    argumentWord5=Loading77964Data6C764View1;
                    __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
                    argumentWord5=actorBaseOffsetOrAmount16+argumentWord5;
                    {
                        long long firstCompleteSignedProduct,secondCompleteSignedProduct,thirdCompleteSignedProduct,fourthCompleteSignedProduct,fifthCompleteSignedProduct;
                        int firstProductHigh,secondProductLow,thirdProductHigh,fourthProductHigh,fifthProductLow;
                        argumentWord6=Loading77964Field(argumentWord5,int*,0);
                        argumentWord4=argumentWord6<<7;
                        firstCompleteSignedProduct=(long long)argumentWord4*(long long)signedFortiethMagic19;
                        rawWord2=Loading77964Field(argumentWord5,unsigned char*,5);
                        rawWord2<<=1;
                        rawWord3=Loading77964Field((int)&Loading77964Data65920View1+rawWord2,short*,0);
                        argumentWord4>>=31;
                        rawWord2=rawWord3*3;
                        rawWord3=rawWord2<<4;
                        rawWord3-=rawWord2;
                        __asm__("":"=h"(firstProductHigh):"x"(firstCompleteSignedProduct),"r"(rawWord3));
                        completeProductHalf8=firstProductHigh;
                        __asm__("":"=r"(completeProductHalf8):"0"(completeProductHalf8));
                        rawWord2=completeProductHalf8>>4;
                        rawWord2-=argumentWord4;
                        rawWord2<<=1;
                        rawWord2+=signedHalfwordTable20;
                        rawWord2=Loading77964Field(rawWord2,short*,0);
                        __asm__("":"=r"(rawWord3):"0"(rawWord3),"r"(rawWord2));
                        rawWord3>>=10;
                        __asm__("":"=r"(rawWord3),"=r"(rawWord2):"0"(rawWord3),"1"(rawWord2),"r"(completeProductHalf8));
                        secondCompleteSignedProduct=(long long)rawWord3*(long long)rawWord2;
                        argumentWord7=(int)Loading77964Data6C604View1;
                        argumentWord6<<=2;
                        __asm__("":"=l"(secondProductLow):"x"(secondCompleteSignedProduct));
                        completeProductHalf8=secondProductLow;
                        __asm__("":"=r"(completeProductHalf8):"0"(completeProductHalf8));
                        rawWord2=completeProductHalf8>>12;
                        rawWord2+=340;
                        rawWord2-=argumentWord6;
                        Loading77964Field(argumentWord7,int*,12)=rawWord2;
                        rawWord2=Loading77964Field(argumentWord5,int*,0);
                        rawWord3=rawWord2*3;
                        rawWord2=rawWord3<<4;
                        rawWord2-=rawWord3;
                        rawWord2<<=2;
                        __asm__("":"=r"(rawWord2):"0"(rawWord2),"r"(completeProductHalf8));
                        thirdCompleteSignedProduct=(long long)rawWord2*(long long)signedFortiethMagic19;
                        rawWord2>>=31;
                        __asm__("":"=h"(thirdProductHigh):"x"(thirdCompleteSignedProduct));
                        completeProductHalf8=thirdProductHigh;
                        __asm__("":"=r"(completeProductHalf8):"0"(completeProductHalf8));
                        rawWord3=completeProductHalf8>>4;
                        rawWord3-=rawWord2;
                        rawWord3+=38;
                        Loading77964Field(argumentWord7,int*,16)=rawWord3;
                        rawWord3=Loading77964Field(argumentWord5,int*,0);
                        rawWord3<<=7;
                        __asm__("":"=r"(rawWord3):"0"(rawWord3),"r"(completeProductHalf8));
                        fourthCompleteSignedProduct=(long long)rawWord3*(long long)signedFortiethMagic19;
                        rawWord2=Loading77964Field(argumentWord5,unsigned char*,5);
                        rawWord2<<=1;
                        rawWord2+=signedHalfwordTable20;
                        argumentWord4=Loading77964Field(rawWord2,unsigned short*,0);
                        rawWord3>>=31;
                        argumentWord4<<=16;
                        __asm__("":"=h"(fourthProductHigh):"x"(fourthCompleteSignedProduct),"r"(argumentWord4));
                        completeProductHalf8=fourthProductHigh;
                        __asm__("":"=r"(completeProductHalf8):"0"(completeProductHalf8));
                        rawWord2=completeProductHalf8>>4;
                        rawWord2-=rawWord3;
                        rawWord2<<=1;
                        rawWord2+=signedHalfwordTable20;
                        rawWord2=Loading77964Field(rawWord2,short*,0);
                        __asm__("":"=r"(argumentWord4):"0"(argumentWord4),"r"(rawWord2));
                        argumentWord4>>=19;
                        __asm__("":"=r"(argumentWord4),"=r"(rawWord2):"0"(argumentWord4),"1"(rawWord2),"r"(completeProductHalf8));
                        fifthCompleteSignedProduct=(long long)argumentWord4*(long long)rawWord2;
                        Loading77964Field(argumentWord7,signed char*,68)=0;
                        rawWord3=Loading77964Data6C604View1;
                        __asm__("":"=l"(fifthProductLow):"x"(fifthCompleteSignedProduct),"r"(rawWord3),"m"(Loading77964Field(argumentWord7,signed char*,68)));
                        completeProductHalf8=fifthProductLow;
                        __asm__("":"=r"(completeProductHalf8):"0"(completeProductHalf8));
                        rawWord2=completeProductHalf8>>12;
                        rawWord2+=3200;
                        Loading77964Field(argumentWord7,int*,20)=rawWord2;
                    }
                    Loading77964Field(rawWord3,signed char*,69)=8;
                    Loading77964Field(Loading77964Data6C604View1, unsigned char *, 0x46) = (unsigned char) Loading77964Field((actorBaseOffsetOrAmount16 + Loading77964Data6C764View1), volatile unsigned char *, 6);
                    __asm__(""::"r"(actorBaseOffsetOrAmount16));
                    Loading77964Field(Loading77964Data6C604View1, signed char *, 0x47) = 0x3F;
                    Loading77964Field(Loading77964Data6C604View1, signed char *, 0x54) = (signed char) (Loading77964Field(byteCursorRowOrSavedWord17,unsigned char*,0) + 1);
                    Loading77964Field(Loading77964Data6C604View1, unsigned char *, 0x4C) = originalByte255In21;
                    Loading77964Field(Loading77964Data6C604View1, signed char *, 0x4E) = 0x40;
                    rawWord3 = Loading77964Data6C604View1;
                    Loading77964Data6C604View1 = rawWord3 + 0x58;
                    Loading77964Field(rawWord3, unsigned char *, 0xA0) = originalByte255In21;
                }
                actorThenRecordIndex18 += 1;
                byteCursorRowOrSavedWord17 += 1;
            }
            while (actorThenRecordIndex18 < 0x18);
        }
        rawWord3 = Loading77964Data6FBC4View2;
        if ((unsigned int) (rawWord3 - 4) < 0x5DU) {
            byteCursorRowOrSavedWord17 = 0x18;
            if (rawWord3 < 0x10) {
                rawWord2=Loading77964Field((int)&Loading77964Data67520View1+Loading77964Data6FBC4View1,unsigned char*,0);
                byteCursorRowOrSavedWord17=rawWord2-16;
            }
            else if((rawWord2=rawWord3<0x54, !rawWord2)){
                rawWord2=Loading77964Field((int)&Loading77964Data674E8View1+Loading77964Data6FBC4View1,unsigned char*,0);
                byteCursorRowOrSavedWord17=rawWord2-16;
            }
            argumentWord5=Loading77964Data6FBC4View2;
            if(argumentWord5<0x20){
                rawWord2=Loading77964Data6C60CView1;
                rawWord2<<=2;
                rawWord3=Loading77964Field((int)&Loading77964Data71A10View1+rawWord2,int*,0);
                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                rawWord2=Loading77964Data6C720View1;
                actorBaseOffsetOrAmount16=rawWord3-rawWord2;
            }
            else {
                rawWord3=Loading77964Data6C6F8View1;
                argumentWord4=rawWord3+1;
                if(rawWord3<16){
                    argumentWord4+=rawWord3;
                }
                if(argumentWord4>=33){
                    argumentWord4=32;
                    __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
                }
                rawWord2=argumentWord4+32;
                argumentWord5=rawWord2-argumentWord5;
                if(argumentWord5<0){
                    argumentWord5=0;
                }
                rawWord2=argumentWord4<argumentWord5;
                if (rawWord2 != 0) {
                    argumentWord5 = argumentWord4;
                }
                rawWord2=Loading77964CompleteProductLow((Loading77964Field((int)&Loading77964Data71A10View1+(Loading77964Data6C60CView1*4),int*,0)-Loading77964Data6C720View1),argumentWord5);
                __asm__("":"=r"(rawWord2):"0"(rawWord2));
                actorBaseOffsetOrAmount16=rawWord2/argumentWord4;
            }
            Loading77964CallDrawStringRightAlignedView1(Loading77964Field((int)&Loading77964Data69DC8View1 + (Loading77964Data6C76CView1 * 4),int*,0), 0x12C, byteCursorRowOrSavedWord17, 1);
            Loading77964Call20428View1(actorBaseOffsetOrAmount16, 0x17C, byteCursorRowOrSavedWord17, 1);
            Loading77964Call4E790View1(Loading77964Data6C604View1, 0, 0x58);
            rawWord3=Loading77964Data6C604View1;
            rawWord2=0x154;
            Loading77964Field(rawWord3,int*,12)=rawWord2;
            rawWord2=byteCursorRowOrSavedWord17+14;
            Loading77964Field(rawWord3,int*,16)=rawWord2;
            rawWord2=3072;
            Loading77964Field(rawWord3,int*,20)=rawWord2;
            Loading77964Field(Loading77964Data6C604View1, unsigned char *, 0x46) = (unsigned char) (Loading77964Data6FBC4View2 * 4);
            Loading77964Field(Loading77964Data6C604View1, short *, 0x36) = 1;
            Loading77964Field(Loading77964Data6C604View1, signed char *, 0x47) = 0x3F;
            Loading77964Field(Loading77964Data6C604View1, signed char *, 0x54) = 2;
            Loading77964Field(Loading77964Data6C604View1, unsigned char *, 0x4C) = 0xFF;
            Loading77964Field(Loading77964Data6C604View1, signed char *, 0x4E) = 0x40;
            rawWord3 = Loading77964Data6C604View1;
            Loading77964Data6C604View1 = rawWord3 + 0x58;
            Loading77964Field(rawWord3,unsigned char*,0xA0)=255;
        }
        rawWord3=Loading77964Data6FBC4View2;
        if ((unsigned int) (rawWord3 - 0x28) < 0x61U) {
            byteCursorRowOrSavedWord17 = 0xD0;
            if (rawWord3 < 0x34) {
                rawWord3 = Loading77964Field((int)&Loading77964Data674FCView1 + Loading77964Data6FBC4View1,unsigned char*,0);
                goto computeOriginalLowerRow;
            }
            if((rawWord2=rawWord3<0x7C, !rawWord2)){
                rawWord3 = Loading77964Field((int)&Loading77964Data674C0View1 + Loading77964Data6FBC4View1,unsigned char*,0);
            computeOriginalLowerRow:
                rawWord2=248;
                __asm__("":"=r"(rawWord2):"0"(rawWord2));
                byteCursorRowOrSavedWord17=rawWord2-rawWord3;
            }
            argumentWord5=Loading77964Data6FBC4View2;
            if(argumentWord5<0x48){
                rawWord2=Loading77964Data6C60CView1;
                rawWord3=Loading77964Data6C720View1;
                rawWord2<<=2;
                rawWord2=Loading77964Field((int)&Loading77964Data71A10View1+rawWord2,int*,0);
                argumentWord4=Loading77964Data6C71CView1;
                rawWord2-=rawWord3;
                actorBaseOffsetOrAmount16=argumentWord4-rawWord2;
            }
            else {
                rawWord3=Loading77964Data6C6F8View1;
                argumentWord4=rawWord3+1;
                if(rawWord3<16){
                    argumentWord4+=rawWord3;
                }
                if(argumentWord4>=33){
                    argumentWord4=32;
                    __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
                }
                rawWord2=argumentWord4+72;
                argumentWord5=rawWord2-argumentWord5;
                if(argumentWord5<0){
                    argumentWord5=0;
                }
                rawWord2=argumentWord4<argumentWord5;
                if (rawWord2 != 0) {
                    argumentWord5 = argumentWord4;
                }
                rawWord2=Loading77964CompleteProductLow((Loading77964Field((int)&Loading77964Data71A10View1+(Loading77964Data6C60CView1*4),int*,0)-Loading77964Data6C720View1),argumentWord5);
                __asm__("":"=r"(rawWord2):"0"(rawWord2));
                rawWord3=rawWord2/argumentWord4;
                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                rawWord2=Loading77964Data6C71CView1;
                actorBaseOffsetOrAmount16=rawWord2-rawWord3;
            }
            if (actorBaseOffsetOrAmount16 < 0) {
                actorBaseOffsetOrAmount16 = 0;
            }
            Loading77964Call2E748View1(Loading77964Field((int)&Loading77964Data69DCCView1 + (Loading77964Data6C76CView1 * 4),int*,0), 0xDC, byteCursorRowOrSavedWord17, 1, 0);
            Loading77964Call20428View1(actorBaseOffsetOrAmount16, -0x8C, byteCursorRowOrSavedWord17, 1);
            Loading77964Call4E790View1(Loading77964Data6C604View1, 0, 0x58);
            rawWord3=Loading77964Data6C604View1;
            rawWord2=0xB4;
            Loading77964Field(rawWord3,int*,12)=rawWord2;
            rawWord2=byteCursorRowOrSavedWord17+14;
            Loading77964Field(rawWord3,int*,16)=rawWord2;
            rawWord2=3072;
            Loading77964Field(rawWord3,int*,20)=rawWord2;
            Loading77964Field(Loading77964Data6C604View1, unsigned char *, 0x46) = (unsigned char) (Loading77964Data6FBC4View2 * 4);
            Loading77964Field(Loading77964Data6C604View1, short *, 0x36) = 1;
            Loading77964Field(Loading77964Data6C604View1, signed char *, 0x47) = 0x3F;
            Loading77964Field(Loading77964Data6C604View1, signed char *, 0x54) = 2;
            Loading77964Field(Loading77964Data6C604View1, unsigned char *, 0x4C) = 0xFF;
            Loading77964Field(Loading77964Data6C604View1, signed char *, 0x4E) = 0x40;
            rawWord3 = Loading77964Data6C604View1;
            Loading77964Data6C604View1 = rawWord3 + 0x58;
            Loading77964Field(rawWord3,unsigned char*,0xA0)=255;
        }
        goto renderOriginalCommonRecords;
    case 4:
        {
            long long completeSignedTenthProduct;
            int completeTenthHighWord;
            rawWord2=0x36000;
            argumentWord5=0;
            actorBaseOffsetOrAmount16=(int)Loading77964Data722D0View1;
            argumentWord6=88;
            rawWord2=actorBaseOffsetOrAmount16+rawWord2;
            actorThenRecordIndex18=rawWord2;
            Loading77964Data6C550View1=(void*)actorThenRecordIndex18;
            Loading77964Call4E790View1((void*)actorThenRecordIndex18,argumentWord5,argumentWord6);
            rawWord2=Loading77964Data6C528View1;
            argumentWord5=(int)&Loading77964Data70328View1;
            Loading77964Field(actorBaseOffsetOrAmount16,short*,0x36036)=rawWord2;
            Loading77964Call4F178View1(actorThenRecordIndex18+12,argumentWord5);
            rawWord3=Loading77964Field((int)&Loading77964Data70328View1,unsigned char*,14);
            rawWord2=4;
            Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x36047)=rawWord2;
            rawWord2=32;
            Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x3604C)=rawWord2;
            Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x3604E)=rawWord2;
            rawWord2=255;
            Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x36052)=rawWord2;
            Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x36046)=rawWord3;
            rawWord3=Loading77964Field(actorBaseOffsetOrAmount16,short*,0x36036);
            rawWord2=651;
            if(rawWord3==rawWord2){
                rawWord3=0x66660000;
                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                rawWord2=1;
                Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x3603C)=rawWord2;
                Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x3603D)=rawWord2;
                argumentWord4=Loading77964Data6C644View1;
                __asm__ volatile("":"=r"(rawWord3):"0"(rawWord3):"memory");
                rawWord3|=0x6667;
                __asm__("":"=r"(rawWord3):"0"(rawWord3));
                completeSignedTenthProduct=(long long)argumentWord4*(long long)rawWord3;
                rawWord2=argumentWord4>>31;
                __asm__("":"=h"(completeTenthHighWord):"x"(completeSignedTenthProduct),"r"(rawWord2));
                completeProductHalf8=completeTenthHighWord;
                __asm__("":"=r"(completeProductHalf8):"0"(completeProductHalf8));
                rawWord3=completeProductHalf8>>2;
                rawWord3-=rawWord2;
                rawWord2=rawWord3*10;
                rawWord3=argumentWord4-rawWord2;
                rawWord2=rawWord3>>1;
                rawWord3--;
                Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x3603F)=rawWord2;
                __asm__ volatile("":::"$17","memory");
                byteCursorRowOrSavedWord17=307;
                if(rawWord3<0)rawWord3+=10;
                rawWord2=rawWord3>>1;
                Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x3603E)=rawWord2;
                rawWord2=(rawWord3&1)<<7;
                Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x36040)=rawWord2;
            }
            else{
                byteCursorRowOrSavedWord17=640;
                if(rawWord3==516){
                    byteCursorRowOrSavedWord17=1540;
                    Loading77964Call34F80View1(actorThenRecordIndex18,2);
                    rawWord2=200;
                    Loading77964Field(actorBaseOffsetOrAmount16,unsigned char*,0x36045)=rawWord2;
                    rawWord2=Loading77964Field(actorBaseOffsetOrAmount16,int*,0x3600C);
                    rawWord3=Loading77964Field(actorBaseOffsetOrAmount16,int*,0x36014);
                    rawWord2-=2048;
                    rawWord3+=1280;
                    Loading77964Field(actorBaseOffsetOrAmount16,int*,0x3600C)=rawWord2;
                    Loading77964Field(actorBaseOffsetOrAmount16,int*,0x36014)=rawWord3;
                }
            }
            rawWord3=Loading77964Field((int)&Loading77964Data70328View1,int*,68);
            rawWord2=Loading77964Field(actorThenRecordIndex18,int*,20);
            argumentWord4=(int)Loading77964Data6C550View1;
            rawWord3+=byteCursorRowOrSavedWord17;
            rawWord2-=rawWord3;
            Loading77964Field(actorThenRecordIndex18,int*,20)=rawWord2;
            rawWord2=argumentWord4+88;
            Loading77964Data6C604View1=(void*)rawWord2;
            rawWord2=255;
            Loading77964Field(argumentWord4,unsigned char*,160)=rawWord2;
        }
        rawWord3=Loading77964Data6FBC4View2;
        __asm__("":"=r"(rawWord3):"0"(rawWord3));
        if ((unsigned int) (rawWord3 - 0x14) < 0x5DU) {
            actorBaseOffsetOrAmount16 = 0x18;
            if (rawWord3<0x20) {
                rawWord2=Loading77964Field((int)&Loading77964Data67510View1+Loading77964Data6FBC4View1,unsigned char*,0);
                actorBaseOffsetOrAmount16=rawWord2-16;
            }
            else if((rawWord2=rawWord3<100, !rawWord2)){
                rawWord2=Loading77964Field((int)&Loading77964Data674D8View1+Loading77964Data6FBC4View1,unsigned char*,0);
                actorBaseOffsetOrAmount16=rawWord2-16;
            }
            argumentWord4=(int)originalTextBuffer;
            if(Loading77964Data6C508View1!=0){
                rawWord3=Loading77964Data6C76CView1;
                __asm__("":"=r"(rawWord3):"0"(rawWord3):"memory");
                argumentWord5=(int)&Loading77964Data69CF8View1;
                __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
                rawWord2=rawWord3<<2;
                argumentWord6=Loading77964Field((int)&Loading77964Data69DD0View1+rawWord2,int*,0);
                rawWord2+=rawWord3;
                goto formatOriginalSharedText;
            }
            rawWord3=Loading77964Data6C76CView1;
            __asm__("":"=r"(rawWord3):"0"(rawWord3):"memory");
            argumentWord5=(int)&Loading77964Data69CF8View1;
            __asm__("":"=r"(argumentWord5):"0"(argumentWord5));
            rawWord2=rawWord3<<2;
            argumentWord6=Loading77964Field((int)&Loading77964Data69DD4View1+rawWord2,int*,0);
            rawWord2+=rawWord3;
        formatOriginalSharedText:
            rawWord2<<=5;
            rawWord3=Loading77964Data6C58CView1;
            rawWord2+=argumentWord5;
            rawWord3<<=2;
            rawWord3+=rawWord2;
            __asm__("":"=r"(rawWord3):"0"(rawWord3));
            argumentWord7=Loading77964Field(rawWord3,int*,0);
            argumentWord5=(int)&Loading77964Data74504View1;
            Loading77964CallsprintfView1(argumentWord4,argumentWord5,argumentWord6,argumentWord7);
            Loading77964CallDrawStringCenteredView1(originalTextBuffer, 0x10A, actorBaseOffsetOrAmount16, 1);
        }
        goto renderOriginalCommonRecords;
        default:break;
    }
    goto finishOriginalInvocation;
renderOriginalCommonRecords:
    actorBaseOffsetOrAmount16=(int)&Loading77964Data6D058View1;
    __asm__("":"=r"(actorBaseOffsetOrAmount16):"0"(actorBaseOffsetOrAmount16));
    byteCursorRowOrSavedWord17=Loading77964Field(actorBaseOffsetOrAmount16,int*,0);
    Loading77964Field(actorBaseOffsetOrAmount16,int*,0)=0;
    Loading77964Call1C368View1();
    argumentWord5=0;
    argumentWord4=Loading77964Data6C668View1;
    argumentWord6=3072;
    argumentWord4-=12288;
    __asm__("":"=r"(argumentWord4):"0"(argumentWord4));
    Loading77964Field(actorBaseOffsetOrAmount16,int*,0)=byteCursorRowOrSavedWord17;
    Loading77964Call4E7ACView1(argumentWord4,argumentWord5,argumentWord6);
    Loading77964Call30478View1();
    Loading77964Call31124View1();
    Loading77964Call33C5CView1();
queueOriginalCommonDraw:
    Loading77964Call3CDA0View1();
    argumentWord5=Loading77964Data6C598View1;
    argumentWord4=2;
    if(argumentWord5!=0){
        argumentWord6=argumentWord5;
        argumentWord7=argumentWord5;
    drawOriginalFade:
        Loading77964Call200A0View1(argumentWord4,argumentWord5,argumentWord6,argumentWord7);
    }
finishOriginalInvocation:
    Loading77964Call75114View1(0xAE);
}
#undef Loading77964Field
#undef Loading77964CompleteProductLow

