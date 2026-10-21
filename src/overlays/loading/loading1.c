#include "matching.h"
#include "common.h"
#include "drawutil.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8007494C.
* Assembly SHA256 2daef163849d813742069c1a4b92fdd8a922a7e880f0edb658fc0586ea8dccba.
* AI generated; not human reviewed. All498 original instructions and every
* actual branch/call/internal target are required. Original.rodata.jtbl
* tables have7 selectors bias1 plus1 padding word, and13 selectors bias0
* plus1 padding word:22 owned words in addition to the498 instructions.
* Frame28 retains the original SP10..17 halfwords and S0/S1/RA saves.
* Archive pointers are raw32-bit word views. Every16/24-byte table addend,
* word load, independent global reload, pointer publication, RECT store,
* audio chunk offset and CD transfer argument producer remains original.
* Decoder-only section aliasing never modified original assembly or the
* frozen compiler/pipeline. The linked tables retain original.rodata.jtbl.
* Empty initialized dependencies and dead-before-producer clobbers emit no
* CPU instructions. No partial HI, FP shortcut or opcode assembly is used.
* Full helper contracts, field units/fixed point and caller cadence remain
* unresolved. Cadence here is per invocation. Binary identity does not
* establish synchronized retail runtime or complete game behavior.
* Falsification: every native/linked word and actual target, both original
* selector/padding tables, full EXE and every overlay retail hash. */
#define Loading498Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
unsigned char Loading498CallCDLoadAsyncView1() __asm__("CDLoadAsync");
unsigned char Loading498CallLoadImageView1() __asm__("LoadImage");
int Loading498Call2B31CView1() __asm__("func_8002B31C");
unsigned char Loading498Call4E7D4View1() __asm__("func_8004E7D4");
unsigned char Loading498Call64A2CView1() __asm__("func_80064A2C");
unsigned char Loading498Call64A8CView1() __asm__("func_80064A8C");
int Loading498Call64AECView1() __asm__("func_80064AEC");
int Loading498Call77438View1() __asm__("func_loading_80077438");
int Loading498Call795BCView1() __asm__("func_loading_800795BC");
extern int Loading498Data11254View1 __asm__("D_80011254");
extern unsigned char Loading498Data66FCCView1 __asm__("D_80066FCC");
extern int Loading498Data6C508View1 __asm__("D_8006C508");
extern int Loading498Data6C518View1 __asm__("D_8006C518");
extern int Loading498Data6C58CView1 __asm__("D_8006C58C");
extern int Loading498Data6C5BCView1 __asm__("D_8006C5BC");
extern int Loading498Data6C5C8View1 __asm__("D_8006C5C8");
extern int Loading498Data6C5DCView1 __asm__("D_8006C5DC");
extern unsigned int Loading498Data6C5E4View1 __asm__("D_8006C5E4");
extern int Loading498Data6C5F4View1 __asm__("D_8006C5F4");
extern signed char Loading498Data6C62CView1 __asm__("D_8006C62C");
extern int Loading498Data6C658View1 __asm__("D_8006C658");
extern int Loading498Data6C6A0View1 __asm__("D_8006C6A0");
extern int Loading498Data6C6B8View1 __asm__("D_8006C6B8");
extern int Loading498Data6C6BCView1 __asm__("D_8006C6BC");
extern int Loading498Data6C6C0View1 __asm__("D_8006C6C0");
extern int Loading498Data6C714View1 __asm__("D_8006C714");
extern signed char Loading498Data6C7B4View1 __asm__("D_8006C7B4");
extern unsigned char Loading498Data6D908View1 __asm__("D_8006D908");
extern unsigned char Loading498Data6D914View1 __asm__("D_8006D914");
extern unsigned char Loading498Data6DBE0View1 __asm__("D_8006DBE0");
extern unsigned char Loading498Data6DBECView1 __asm__("D_8006DBEC");
extern int Loading498Data6E344View1 __asm__("D_8006E344");
extern int Loading498Data6E470View1 __asm__("D_8006E470");
extern int Loading498Data6FA38View1 __asm__("D_8006FA38");
extern int Loading498Data6FA3CView1 __asm__("D_8006FA3C");
extern int Loading498Data71980View1 __asm__("D_80071980");
extern int Loading498Data72098View1 __asm__("D_80072098");
extern int Loading498Data7209CView1 __asm__("D_8007209C");
extern int Loading498Data720A0View1 __asm__("D_800720A0");
extern int Loading498Data720A4View1 __asm__("D_800720A4");
extern int Loading498Data720A8View1 __asm__("D_800720A8");
extern int Loading498Data720ACView1 __asm__("D_800720AC");
extern int Loading498Data720B0View1 __asm__("D_800720B0");
extern int Loading498Data720B4View1 __asm__("D_800720B4");
extern int Loading498Data722BCView1 __asm__("D_800722BC");
extern int Loading498Data722C0View1 __asm__("D_800722C0");
extern int Loading498Data722C4View1 __asm__("D_800722C4");
extern int Loading498Data722C8View1 __asm__("D_800722C8");
extern unsigned char Loading498Data7B6E4View1 __asm__("D_loading_8007B6E4");
extern signed char Loading498Data7B954View1 __asm__("D_loading_8007B954");
void func_loading_8007494C(void) {
    register int rawWord2 __asm__("$2");
    register int rawWord3 __asm__("$3");
    register int argumentWord4 __asm__("$4");
    register int argumentWord5 __asm__("$5");
    register int argumentWord6 __asm__("$6");
    register int argumentWord7 __asm__("$7");
    struct {
        short sp10, sp12, sp14, sp16;
    } imageRectangle;
    int temporaryWord1;
    register int temporaryWord2 __asm__("$17");
    register int headerAddressOrChunkLength16 __asm__("$16");
    switch (Loading498Data6C518View1) {
        case 1:
            Loading498Data7B954View1 = 0;
            Loading498Call77438View1();
            rawWord2 = 2;
            goto storeLoadingState;
        default:
            return;
        case 2:
            Loading498Call77438View1();
            Loading498Call4E7D4View1(&Loading498Data71980View1, Loading498Data6C6A0View1, 0x28);
            Loading498Data6C6A0View1 = (int)&Loading498Data71980View1;
            if (Loading498Data6C658View1 == 0) {
                Loading498Data6C5C8View1 = 0;
            }
            rawWord3 = Loading498Data6C5BCView1;
            rawWord2 = rawWord3 < 60;
            MATCHING_KEEP(rawWord2);
            if (rawWord2)
                rawWord2 = Loading498Field(&Loading498Data66FCCView1, unsigned char*, rawWord3);
            else
                rawWord2 = rawWord3 - 60;
            Loading498Data6C58CView1 = rawWord2;
            MATCHING_BARRIER_GNU_VOLATILE("memory");
            argumentWord4 = Loading498Data6C5BCView1;
            if (argumentWord4 < 0x3C) {
                Loading498Data6C5F4View1 = 0;
                Loading498Data6C6BCView1 = 0;
                Loading498Data6C6C0View1 = 0;
                temporaryWord1 = argumentWord4 % 10;
                Loading498Data6C508View1 = temporaryWord1 == 0;
                if (argumentWord4 == 0x32) {
                    Loading498Data6C508View1 = 0;
                }
                Loading498Data6C7B4View1 = 0;
                Loading498Data6C62CView1 = 0;
                if (temporaryWord1 == 5) {
                    Loading498Data6FA38View1 = (argumentWord4 / 10) - 1;
                    Loading498Data6FA3CView1 = 0;
                } else {
                    Loading498Data6FA38View1 = -1;
                }
            }
            Loading498Data6C5DCView1 = 0;
            if (Loading498Data6C5BCView1 >= 60) {
                rawWord3 = Loading498Data6C58CView1;
                rawWord2 = rawWord3 * 24;
                rawWord3 = Loading498Data11254View1;
                rawWord2 = Loading498Field(&Loading498Data6D914View1, int*, rawWord2);
                rawWord3 += rawWord2;
            } else {
                rawWord2 = Loading498Data6C58CView1;
                rawWord3 = Loading498Data11254View1;
                rawWord2 <<= 4;
                rawWord2 = Loading498Field(&Loading498Data6DBECView1, int*, rawWord2);
                rawWord3 += rawWord2;
            }
            Loading498Data722BCView1 = rawWord3;
            __asm__ __volatile__("" ::: "$5", "memory");
            argumentWord5 = (int)&Loading498Data722BCView1;
            MATCHING_KEEP(argumentWord5);
            rawWord2 = Loading498Field(argumentWord5, int*, 0);
            argumentWord4 = Loading498Data11254View1;
            rawWord3 = Loading498Data6C714View1;
            rawWord2 -= argumentWord4;
            if (rawWord2 < rawWord3) {
                rawWord2 = argumentWord4 + rawWord3;
                Loading498Field(argumentWord5, int*, 0) = rawWord2;
            }
            rawWord2 = Loading498Data6C5BCView1;
            argumentWord5 = Loading498Field(argumentWord5, int*, 0);
            rawWord2 = rawWord2 < 60;
            Loading498Data722C0View1 = argumentWord5;
            if (!rawWord2) {
                rawWord3 = Loading498Data6C58CView1;
                argumentWord4 = Loading498Data6E470View1;
                rawWord2 = rawWord3 * 24;
                argumentWord7 = Loading498Field(&Loading498Data6D908View1, int*, rawWord2);
            } else {
                rawWord2 = Loading498Data6C58CView1;
                argumentWord4 = Loading498Data6E470View1;
                rawWord2 <<= 4;
                argumentWord7 = Loading498Field(&Loading498Data6DBE0View1, int*, rawWord2);
            }
            Loading498CallCDLoadAsyncView1(argumentWord4, argumentWord5, 2048, argumentWord7);
            rawWord2 = 3;
            goto storeLoadingState;
        case 3:
            Loading498Call77438View1();
            headerAddressOrChunkLength16 = (int)&Loading498Data72098View1;
            argumentWord4 = headerAddressOrChunkLength16;
            temporaryWord2 = (int)&Loading498Data722C0View1;
            MATCHING_KEEP2(headerAddressOrChunkLength16, temporaryWord2);
            argumentWord5 = Loading498Field(temporaryWord2, int*, 0);
            Loading498Call4E7D4View1(argumentWord4, argumentWord5, 0x220);
            argumentWord6 = 0x80000;
            if (Loading498Data6C5BCView1 >= 60) {
                rawWord3 = Loading498Data6C58CView1;
                argumentWord4 = Loading498Data6E470View1;
                rawWord2 = rawWord3 * 24;
                rawWord3 = Loading498Field(headerAddressOrChunkLength16, int*, 0);
                argumentWord7 = Loading498Field(&Loading498Data6D908View1, int*, rawWord2);
            } else {
                rawWord2 = Loading498Data6C58CView1;
                argumentWord4 = Loading498Data6E470View1;
                rawWord3 = Loading498Field(headerAddressOrChunkLength16, int*, 0);
                rawWord2 <<= 4;
                argumentWord7 = Loading498Field(&Loading498Data6DBE0View1, int*, rawWord2);
            }
            argumentWord5 = Loading498Field(temporaryWord2, int*, 0);
            Loading498CallCDLoadAsyncView1(argumentWord4, argumentWord5, argumentWord6,
                                           rawWord3 + argumentWord7);
            if (Loading498Data6E344View1 != 9) {
                Loading498Data6C5E4View1 = 0;
                rawWord2 = 4;
            } else {
                Loading498Data6C5E4View1 = 2;
                rawWord2 = 4;
            }
            goto storeLoadingState;
        case 4:
            Loading498Call77438View1();
            switch (Loading498Data6C5E4View1) {
                case 0:
                    imageRectangle.sp10 = 0x200;
                    imageRectangle.sp14 = 0x200;
                    imageRectangle.sp12 = 0;
                    imageRectangle.sp16 = 0x100;
                    Loading498CallLoadImageView1(&imageRectangle.sp10, Loading498Data722C0View1);
                    Loading498Data6C5E4View1 = 1;
                    return;
                case 1:
                    argumentWord4 = (int)&imageRectangle.sp10;
                    MATCHING_KEEP(argumentWord4);
                    rawWord3 = 512;
                    rawWord2 = 256;
                    imageRectangle.sp12 = rawWord2;
                    imageRectangle.sp16 = rawWord2;
                    rawWord2 = Loading498Data722C0View1;
                    __asm__ __volatile__("" ::: "$5", "memory");
                    argumentWord5 = 0x40000;
                    imageRectangle.sp10 = rawWord3;
                    imageRectangle.sp14 = rawWord3;
                    Loading498CallLoadImageView1(argumentWord4, rawWord2 + argumentWord5);
                    Loading498Data6C5E4View1 = 2;
                    return;
                case 2:
                    rawWord2 = Loading498Data6C5BCView1;
                    rawWord2 = rawWord2 < 60;
                    argumentWord7 = -524288;
                    if (!rawWord2) {
                        argumentWord4 = Loading498Data6E470View1;
                        argumentWord5 = Loading498Data722C0View1;
                        rawWord3 = Loading498Data6C58CView1;
                        argumentWord6 = Loading498Data7209CView1;
                        rawWord2 = rawWord3 * 24;
                        rawWord3 = Loading498Data72098View1;
                        rawWord2 = Loading498Field(&Loading498Data6D908View1, int*, rawWord2);
                        __asm__ __volatile__(""
                                             : "=r"(argumentWord7)
                                             : "0"(argumentWord7), "i"(0x80074DE0)
                                             : "memory");
                        argumentWord6 += argumentWord7;
                        goto finishNestedTransfer;
                    } else {
                        argumentWord4 = Loading498Data6E470View1;
                        argumentWord5 = Loading498Data722C0View1;
                        rawWord2 = Loading498Data6C58CView1;
                        argumentWord6 = Loading498Data7209CView1;
                        rawWord3 = Loading498Data72098View1;
                        rawWord2 <<= 4;
                        MATCHING_KEEP(argumentWord7);
                        argumentWord6 += argumentWord7;
                        rawWord2 = Loading498Field(&Loading498Data6DBE0View1, int*, rawWord2);
                    }
                finishNestedTransfer:
                    argumentWord7 = 0x80000;
                    rawWord3 += rawWord2;
                    Loading498CallCDLoadAsyncView1(argumentWord4, argumentWord5, argumentWord6,
                                                   rawWord3 + argumentWord7);
                    rawWord2 = 4;
                    Loading498Data6C5E4View1 = rawWord2;
                    return;
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                    rawWord2 = 0x80000;
                    rawWord3 = Loading498Data6C5E4View1;
                    argumentWord4 = Loading498Data7209CView1;
                    rawWord3 = (rawWord3 - 4) << 16;
                    rawWord2 = rawWord3 + rawWord2;
                    headerAddressOrChunkLength16 = argumentWord4 - rawWord2;
                    temporaryWord2 = rawWord3;
                    if (headerAddressOrChunkLength16 > 65536)
                        headerAddressOrChunkLength16 = 65536;
                    if (headerAddressOrChunkLength16 > 0) {
                        Loading498Call64A2CView1(temporaryWord2 | 0x1010);
                        Loading498Call64A8CView1(Loading498Data722C0View1 + temporaryWord2,
                                                 headerAddressOrChunkLength16);
                        do {
                        } while (Loading498Call64AECView1(0) == 0);
                    }
                    Loading498Data6C5E4View1 += 1;
                    return;
                case 12:
                    if (Loading498Data6C5BCView1 >= 60) {
                        argumentWord4 = Loading498Data6E470View1;
                        rawWord3 = Loading498Data6C58CView1;
                        argumentWord5 = Loading498Data722C0View1;
                        rawWord2 = rawWord3 * 24;
                        rawWord3 = Loading498Data720A0View1;
                        argumentWord7 = Loading498Field(&Loading498Data6D908View1, int*, rawWord2);
                    } else {
                        argumentWord4 = Loading498Data6E470View1;
                        rawWord2 = Loading498Data6C58CView1;
                        argumentWord5 = Loading498Data722C0View1;
                        rawWord3 = Loading498Data720A0View1;
                        rawWord2 <<= 4;
                        argumentWord7 = Loading498Field(&Loading498Data6DBE0View1, int*, rawWord2);
                    }
                    argumentWord6 = Loading498Data720A4View1;
                    Loading498CallCDLoadAsyncView1(argumentWord4, argumentWord5, argumentWord6,
                                                   rawWord3 + argumentWord7);
                    rawWord2 = 5;
                    goto storeLoadingState;
            }
            break;
        case 5:
            Loading498Call77438View1();
            rawWord2 = Loading498Call795BCView1(Loading498Data722C0View1);
            MATCHING_KEEP(rawWord2);
            rawWord3 = Loading498Data6C5BCView1;
            Loading498Data722C4View1 = rawWord2;
            __asm__ __volatile__("" : "=r"(rawWord2) : "0"(rawWord2) : "$5", "memory");
            rawWord3 = rawWord3 < 60;
            argumentWord5 = rawWord2;
            if (!rawWord3) {
                rawWord3 = Loading498Data6C58CView1;
                argumentWord4 = Loading498Data6E470View1;
                rawWord2 = rawWord3 * 24;
                rawWord3 = Loading498Data720A8View1;
                argumentWord7 = Loading498Field(&Loading498Data6D908View1, int*, rawWord2);
            } else {
                rawWord2 = Loading498Data6C58CView1;
                argumentWord4 = Loading498Data6E470View1;
                rawWord3 = Loading498Data720A8View1;
                rawWord2 <<= 4;
                argumentWord7 = Loading498Field(&Loading498Data6DBE0View1, int*, rawWord2);
            }
            argumentWord6 = Loading498Data720ACView1;
            Loading498CallCDLoadAsyncView1(argumentWord4, argumentWord5, argumentWord6,
                                           rawWord3 + argumentWord7);
            rawWord2 = 6;
            goto storeLoadingState;
        case 6:
            Loading498Call77438View1();
            rawWord2 = Loading498Call2B31CView1(Loading498Data722C4View1, 0x80800000);
            MATCHING_KEEP(rawWord2);
            rawWord3 = Loading498Data6C5BCView1;
            Loading498Data722C8View1 = rawWord2;
            __asm__ __volatile__("" : "=r"(rawWord2) : "0"(rawWord2) : "$5", "memory");
            rawWord3 = rawWord3 < 60;
            argumentWord5 = rawWord2;
            if (!rawWord3) {
                rawWord3 = Loading498Data6C58CView1;
                argumentWord4 = Loading498Data6E470View1;
                rawWord2 = rawWord3 * 24;
                rawWord3 = Loading498Data720B0View1;
                argumentWord7 = Loading498Field(&Loading498Data6D908View1, int*, rawWord2);
            } else {
                rawWord2 = Loading498Data6C58CView1;
                argumentWord4 = Loading498Data6E470View1;
                rawWord3 = Loading498Data720B0View1;
                rawWord2 <<= 4;
                argumentWord7 = Loading498Field(&Loading498Data6DBE0View1, int*, rawWord2);
            }
            argumentWord6 = Loading498Data720B4View1;
            Loading498CallCDLoadAsyncView1(argumentWord4, argumentWord5, argumentWord6,
                                           rawWord3 + argumentWord7);
            rawWord2 = 7;
            goto storeLoadingState;
        case 7:
            if (Loading498Call77438View1()) {
                rawWord3 = Loading498Data6C6B8View1;
                rawWord2 = (int)&Loading498Data7B6E4View1;
                if (rawWord3 == rawWord2) {
                    rawWord2 = 8;
                    goto storeLoadingState;
                }
            }
            break;
    }
    return;
storeLoadingState:
    Loading498Data6C518View1 = rawWord2;
}
#undef Loading498Field


/* AI generated; not human reviewed. Retail numeric loading text routes. */
extern int D_800725B8, D_800725C8, D_8006C76C;
extern unsigned char Decoded2073State __asm__("D_loading_8007B954");
extern char* D_loading_8007B6E4[];
extern char* D_loading_8007B6E8[];
extern char* D_loading_8007B6EC[];
extern char* D_loading_8007B6F0[];
extern char* D_loading_8007B6F4[];
extern char* D_loading_8007B6F8[];
extern char* D_loading_8007B6FC[];
extern char* D_loading_8007B700[];
extern char* D_loading_8007B704[];
void func_loading_80075114(int y) {
    if (!D_800725B8) {
        int state = Decoded2073State;
        if (state != 4)
            return;
    }
    MATCHING_BARRIER("memory");
    switch (Decoded2073State) {
        case 4:
            func_80020344(D_loading_8007B6F0[D_8006C76C], 256, y, 11);
            func_80020344(D_loading_8007B6F4[D_8006C76C], 256, y + 15, 11);
            break;
        case 3:
            func_80020344(D_loading_8007B6EC[D_8006C76C], 256, y + 7, 2);
            break;
        case 6:
            switch (D_800725C8) {
                case 1:
                    func_80020344(D_loading_8007B6F0[D_8006C76C], 256, y, 11);
                    func_80020344(D_loading_8007B6F8[D_8006C76C], 256, y + 15, 11);
                    break;
                case 2:
                    func_80020344(D_loading_8007B6F0[D_8006C76C], 256, y, 11);
                    func_80020344(D_loading_8007B6FC[D_8006C76C], 256, y + 15, 11);
                    break;
                default:
                    func_80020344(D_loading_8007B700[D_8006C76C], 256, y, 11);
                    func_80020344(D_loading_8007B704[D_8006C76C], 256, y + 15, 11);
                    break;
            }
            break;
        case 0:
        case 5:
            break;
        default:
            func_80020344(D_loading_8007B6E4[D_8006C76C], 256, y, 2);
            func_80020344(D_loading_8007B6E8[D_8006C76C], 256, y + 15, 2);
            break;
    }
}
