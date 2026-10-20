#include "common.h"
#include "spu.h"
#include "ovl_header.h"
#include "stdutil.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. Original-instruction-derived C candidate. Original source asm/nonmatchings/overlays/level_17/animation/func_level_17_80082528.s SHA256 0ce58b4667640ca62efa8138e2c9335d92f2ff89b5f9eb015050526e3f709395. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define M2C_FIELD(p,t,o) (*(t)((unsigned char*)(p)+(o)))

int Controller82528_func_800363DC() __asm__("func_800363DC");                /* extern */
unsigned char Controller82528_func_80040D10() __asm__("func_80040D10");                     /* extern */
unsigned char Controller82528_func_80041580() __asm__("func_80041580");            /* extern */
unsigned char Controller82528_func_800416F4() __asm__("func_800416F4");                            /* extern */
unsigned char Controller82528_func_800417FC() __asm__("func_800417FC");            /* extern */
unsigned char Controller82528_func_80041B64() __asm__("func_80041B64");                            /* extern */
int Controller82528_func_8004E9E4() __asm__("func_8004E9E4");                             /* extern */
int Controller82528_func_8004EA2C() __asm__("func_8004EA2C");                             /* extern */
unsigned char Controller82528_func_8004ED6C() __asm__("func_8004ED6C");   /* extern */
int Controller82528_func_8004EDE8() __asm__("func_8004EDE8");                  /* extern */
unsigned char Controller82528_func_8004F08C() __asm__("func_8004F08C");         /* extern */
unsigned char Controller82528_func_8004F110() __asm__("func_8004F110");             /* extern */
unsigned char Controller82528_func_8004F168() __asm__("func_8004F168");                       /* extern */
unsigned char Controller82528_func_8004F178() __asm__("func_8004F178");                /* extern */
unsigned char Controller82528_func_8004F194() __asm__("func_8004F194");         /* extern */
unsigned char Controller82528_func_8004F1C8() __asm__("func_8004F1C8");         /* extern */
int Controller82528_rand() __asm__("rand");                                         /* extern */
extern unsigned char Controller82528_D_800658A0 __asm__("D_800658A0");
extern unsigned char Controller82528_D_80065920 __asm__("D_80065920");
extern void *Controller82528_D_8006C570 __asm__("D_8006C570");
extern int Controller82528_D_8006C640 __asm__("D_8006C640");
extern int Controller82528_D_8006E044 __asm__("D_8006E044");
extern unsigned char Controller82528_D_8006E548 __asm__("D_8006E548");
extern unsigned char Controller82528_D_80070328 __asm__("D_80070328");
extern int Controller82528_globalField94 __asm__("D_80070328 + 0x94");
extern unsigned char Controller82528_globalVector80 __asm__("D_80070328 + 0x80");
extern unsigned char Controller82528_globalVector8C __asm__("D_80070328 + 0x8C");
extern void *(*Controller82528_SpawnParticle)() __asm__("SpawnParticle");

void func_level_17_80082528(int slotIndex) {
    register int workWord2 __asm__("$2");
    register int stateWord3 __asm__("$3");
    register int particleThreshold __asm__("$19");
    register void *vectorAt40 __asm__("$16");
    register void *vectorAt30 __asm__("$17");
    register void *call4 __asm__("$4");
    register void *call5 __asm__("$5");
    register void *call6 __asm__("$6");
    register int below19 __asm__("$2");
    register int rawProduct __asm__("$9");
    register void *globalPointer __asm__("$3");
    /* Original vectors occupy 0x10..0x6C; saved registers begin at 0x70. */
    struct {int sp10,sp14,sp18,pad1C,sp20,sp24,sp28,pad2C,sp30,sp34,sp38,pad3C,sp40,sp44,sp48,pad4C,sp50,sp54,sp58,pad5C,sp60,sp64,sp68,pad6C;} originalFrame;

    register int signedTableWord __asm__("$7");
    register void *globalVector80 __asm__("$16");
    register void *globalVector80State20 __asm__("$16");
    register void *globalVector8CState9 __asm__("$17");
    register void *globalVector8CState20 __asm__("$18");
    register void *globalVector8C __asm__("$19");
    register void *var_a0 __asm__("$4");
    register void *var_a0_2 __asm__("$4");
    register void *var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$18");
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_6;
    register int workWord3 __asm__("$3");
    register int particleIndex __asm__("$17");
    register int nextField94 __asm__("$2");
    register unsigned char *globalByteE __asm__("$18");
    register void *globalVector8CState1D __asm__("$16");
    register void *globalFieldB8PointerState1A __asm__("$16");
    register void *globalFieldB8PointerState20 __asm__("$16");
    register void *globalFieldA4Pointer __asm__("$17");
    void *temp_v0_5;
    void *temp_v0_7;

    workWord2=slotIndex*16;
    globalPointer=&Controller82528_D_8006E548;
    workWord2+= (int)globalPointer;
    __asm__("" : "=r"(workWord2):"0"(workWord2));
    Controller82528_D_8006C570=(void*)workWord2;
    workWord2=M2C_FIELD(&Controller82528_D_80070328,int*,0x54);
    stateWord3=M2C_FIELD(&Controller82528_D_80070328,int*,0x48);
    combinedIndex=workWord2+slotIndex;
    switch (stateWord3) {
    case 0x14:
        globalVector80 = &Controller82528_D_80070328 + 0x80;
        Controller82528_func_8004F168(globalVector80);
        Controller82528_func_8004F168(globalVector80 + 0xC);
        if (Controller82528_D_8006E044 != 7) {
            Controller82528_func_80040D10(0x1200);
            Controller82528_func_800416F4();
            Controller82528_func_80041580(0x5A, 0x10);
            return;
        }
    default:
        return;
    case 0x1D:
        Controller82528_func_8004F168(&originalFrame.sp10);
        call4=&originalFrame.sp10;call5=call4;
        __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
        globalVector8CState1D=&Controller82528_D_80070328+0x8C;
        Controller82528_func_8004F1C8(call4,call5,globalVector8CState1D);
        if(M2C_FIELD(&Controller82528_D_80070328,int*,0xB8)!=0) {
            originalFrame.sp18=0;
            temp_v0=Controller82528_func_8004EDE8(&originalFrame.sp10,0);
            if(temp_v0>=65) Controller82528_func_8004F08C(&originalFrame.sp10,temp_v0,64);
            originalFrame.sp18=-192;
            call4=globalVector8CState1D-12;call5=globalVector8CState1D;call6=&originalFrame.sp10;
        } else {
            temp_v0_2=Controller82528_func_8004EDE8(&originalFrame.sp10,1);
            call4=globalVector8CState1D;
            if(temp_v0_2>=257) {
                Controller82528_func_8004F08C(&originalFrame.sp10,temp_v0_2,256);
                call4=globalVector8CState1D;
            }
            Controller82528_func_8004F194(call4,globalVector8CState1D,&originalFrame.sp10);
            call4=globalVector8CState1D-12;call5=globalVector8CState1D;call6=call5+92;
        }
        Controller82528_func_8004F194(call4,call5,call6);
        call4=&Controller82528_D_80070328+0x8C;
        __asm__("" : "=r"(call4):"0"(call4));
        Controller82528_func_8004F178(call4,call4-12);
        if(Controller82528_globalField94<-0x2300) {
            Controller82528_globalField94=-0x2300;
            __asm__ volatile("" ::: "memory");
        }
        break;
    case 0x1A:
        globalFieldB8PointerState1A = &Controller82528_D_80070328 + 0xB8;
        if (M2C_FIELD(&Controller82528_D_80070328, int *, 0xB8) != 0) {
            temp_v0_3 = M2C_FIELD(&Controller82528_D_80070328, int *, 0x94) - 0x600;
            M2C_FIELD(&Controller82528_D_80070328, int *, 0x94) = temp_v0_3;
            if (temp_v0_3 < -0x2300) {
                M2C_FIELD(&Controller82528_D_80070328, int *, 0x94) = -0x2300;
            }
            Controller82528_func_8004F178(globalFieldB8PointerState1A - 0x38, globalFieldB8PointerState1A - 0x2C);
            return;
        }
        goto clearVectors;
    case 0x1C:
        Controller82528_func_80040D10(0xC80);
        Controller82528_func_80041580(0x28, 8);
        Controller82528_func_800417FC(0x140, 0xC0);
        globalFieldA4Pointer = &Controller82528_D_80070328 + 0xA4;
        globalVector8C = globalFieldA4Pointer - 0x18;
        workWord2=Controller82528_func_8004EA2C(M2C_FIELD(globalFieldA4Pointer,int*,0));
        workWord3=M2C_FIELD(&Controller82528_D_80070328,int*,0xB0);
        rawProduct=workWord3*workWord2;
        call4=(void*)M2C_FIELD(globalFieldA4Pointer,int*,0);
        workWord2=rawProduct>>12;
        __asm__("" : "=r"(workWord2):"0"(workWord2));
        originalFrame.sp20=workWord2;
        workWord2=Controller82528_func_8004E9E4(call4);
        workWord3=M2C_FIELD(&Controller82528_D_80070328,int*,0xB0);
        rawProduct=workWord3*workWord2;
        workWord2=rawProduct>>12;
        __asm__("" : "=r"(workWord2):"0"(workWord2));
        originalFrame.sp24=workWord2;
        Controller82528_func_8004F1C8(&originalFrame.sp20, &originalFrame.sp20, globalVector8C);
        originalFrame.sp28 = 0;
        temp_v0_4 = Controller82528_func_8004EDE8(&originalFrame.sp20, 0);
        __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
        var_a0_3 = globalFieldA4Pointer - 0x24;

        if (temp_v0_4 >= 0x281) {
            Controller82528_func_8004F08C(&originalFrame.sp20, temp_v0_4, 0x280);
            __asm__("" : "=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            var_a0_3 = globalFieldA4Pointer - 0x24;

        }
        Controller82528_func_8004F194(var_a0_3, globalVector8C, &originalFrame.sp20);
        Controller82528_func_80041B64();
        if (combinedIndex < 0xD) {
            __asm__("" :: "r"(combinedIndex));
            nextField94 = M2C_FIELD(&Controller82528_D_80070328, int *, 0x94) + 0x17;
        } else {
            nextField94 = M2C_FIELD(&Controller82528_D_80070328, int *, 0x94) - 0xC0;
        }
        Controller82528_globalField94=nextField94;
        __asm__ volatile("" ::: "memory");
        if (Controller82528_SpawnParticle != 0) {
            globalPointer=&Controller82528_D_80070328+0x148;
            __asm__("" : "=r"(globalPointer):"0"(globalPointer));
            particleIndex=0;
            if (M2C_FIELD(globalPointer,int*,0) != 0) {
                workWord2=combinedIndex*4;
            __asm__("" : "=r"(workWord2):"0"(workWord2));
            particleThreshold=workWord2+combinedIndex;
            globalByteE=globalPointer-0x13A;
            vectorAt40=&originalFrame.sp40;
            __asm__("" : "=r"(vectorAt40):"0"(vectorAt40));
spawnParticleLoop:
                if (particleThreshold < (Controller82528_rand() & 0xFF)) {
                    workWord2=Controller82528_func_800363DC(0,0xC);
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
                    signedTableWord = *(short*)(&Controller82528_D_80065920 + workWord3);
                    call6=vectorAt40;

                    originalFrame.sp30 = (int) (signedTableWord * 5) >> 0xA;
                    workWord3=*(short*)(&Controller82528_D_800658A0 + workWord3);
                    __asm__ volatile("" : "=r"(workWord3):"0"(workWord3):"memory");
                    originalFrame.sp38 = 0xE;
                    originalFrame.sp40 = -0x12C;
                    originalFrame.sp44 = 0;
                    originalFrame.sp48 = -0xC8;
                    __asm__ volatile("" ::: "memory");
                    originalFrame.sp34 = (workWord3 * 5) >> 0xA;
                    Controller82528_func_8004ED6C(call4, call5, call6, signedTableWord);
                    originalFrame.sp40 += Controller82528_func_800363DC(0, 0x50);
                    originalFrame.sp44 += Controller82528_func_800363DC(0, 0x50);
                    originalFrame.sp48 += Controller82528_func_800363DC(0, 0x50);
                    Controller82528_func_8004F194(vectorAt40, vectorAt40, globalByteE - 0xE);
                    temp_v0_5 = Controller82528_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp30);
                    M2C_FIELD(temp_v0_5, signed char *, 2) = 8;
                    M2C_FIELD(temp_v0_5, signed char *, 0xA) = 0x20;
                }
                particleIndex += 1;
                if (particleIndex < 2) {
                    goto spawnParticleLoop;
                }
            }
        }
        break;
    case 0x1E:
        /* Preserve the original saved-pointer producer before the shared path. */
        globalVector80=&Controller82528_D_80070328+0x80;
        __asm__ volatile("" : "=r"(globalVector80):"0"(globalVector80));
clearVectors:
        call4=&Controller82528_globalVector80;
        __asm__("" : "=r"(call4):"0"(call4));
        Controller82528_func_8004F168(call4);
        call4=&Controller82528_globalVector8C;
        __asm__("" : "=r"(call4):"0"(call4));
        Controller82528_func_8004F168(call4);
        return;
    case 0x20:
    case 0x3A:
        globalFieldB8PointerState20 = &Controller82528_D_80070328 + 0xB8;
        if (M2C_FIELD(&Controller82528_D_80070328, int *, 0xB8) != 0) {
            vectorAt30=&originalFrame.sp30;
            Controller82528_func_8004F168(vectorAt30);
            call4=vectorAt30;call5=vectorAt30;
            __asm__("" : "=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
            globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
            Controller82528_func_8004F1C8(call4, call5, globalVector8CState20);
            originalFrame.sp38 = 0;
            temp_v0_6 = Controller82528_func_8004EDE8(&originalFrame.sp30, 0);
            if (temp_v0_6 >= 0x41) {
                Controller82528_func_8004F08C(&originalFrame.sp30, temp_v0_6, 0x40);
            }
            originalFrame.sp38 = -0xC0;
            globalVector80State20 = globalFieldB8PointerState20 - 0x38;
            Controller82528_func_8004F194(globalVector80State20, globalVector8CState20, &originalFrame.sp30);
            Controller82528_func_8004F178(globalVector8CState20, globalVector80State20);
        } else {
            Controller82528_func_8004F168(globalFieldB8PointerState20 - 0x38);
            Controller82528_func_8004F168(globalFieldB8PointerState20 - 0x2C);
        }
        if (M2C_FIELD(&Controller82528_D_80070328, int *, 0x94) < -0x2300) {
            M2C_FIELD(&Controller82528_D_80070328, int *, 0x94) = -0x2300;
        }
        if ((M2C_FIELD(&Controller82528_D_80070328, int *, 0x48) == 0x3A) && (Controller82528_SpawnParticle != 0) && (Controller82528_D_8006C640 & 1)) {
            originalFrame.sp50 = 0;
            originalFrame.sp54 = 0;
            originalFrame.sp58 = 0xE;
            Controller82528_func_8004F178(&originalFrame.sp60, (&Controller82528_D_80070328 + 0x94) - 0x94);
            originalFrame.sp60 += Controller82528_func_800363DC(0, 0x12C);
            originalFrame.sp64 += Controller82528_func_800363DC(0, 0x12C);
            originalFrame.sp68 += Controller82528_func_800363DC(0, 0x12C);
            temp_v0_7 = Controller82528_SpawnParticle(1, 0xD, &originalFrame.sp60, &originalFrame.sp50);
            M2C_FIELD(temp_v0_7, signed char *, 2) = 6;
            M2C_FIELD(temp_v0_7, signed char *, 0xA) = 0x20;
        }
        break;
    }
}
#undef M2C_FIELD


extern unsigned char DecodedAnimationPlayer[] __asm__("D_80070328");
extern int D_8006C648, D_8006FA38;
extern int DecodedAnimationStep __asm__("D_80070328 + 0x144");
extern int DecodedAnimationZ __asm__("D_80070328 + 8");
extern int DecodedAnimationLimitSelector __asm__("D_80070328 + 0x280");
int func_8001A358(Vector3D*, int);
extern int DecodedAnimationWordA0 __asm__("D_80070328 + 0xA0");
extern int DecodedAnimationWord4C __asm__("D_80070328 + 0x4C");
extern unsigned char DecodedAnimationByte23 __asm__("D_80070328 + 0x23");
extern unsigned char DecodedAnimationByte22 __asm__("D_80070328 + 0x22");
extern unsigned char DecodedAnimationByte21 __asm__("D_80070328 + 0x21");
extern unsigned char DecodedAnimationByte20 __asm__("D_80070328 + 0x20");
void func_80043A38(int);
/* AI generated adaptation; not human reviewed.
 * SCUS-94467 USA Rev0 80082B84..80082DC0 and original mode dispatch.
 * Reuses verified level40_800863B8 ordered helpers and raw mode30 step/
 * position update: signed shift6, tick shift9, limits9000/2580, sampled
 * vector Z+400 and query argumentC00. Original modes26/29/32 and28/58
 * add their exact helper routes, signed word gates and byte/word stores.
 * Physical units, all producer/helper meanings and caller cadence are open.
 * Acceptance: every original code/table word and complete retail hashes.
 */
void func_level_17_80082B84(void) {
    Vector3D sample;
    switch (spyro.animationState) {
    case 20:
        if (!func_800438F4()) {
            func_80043728();
        }
        func_80041C20();
        spyro.unk9a = 0;
        func_80042A44();
        spyro.unk4[0] = 0;
        break;
    case 32:
        func_80041C20();
        func_80042A44();
        spyro.unk4[0] = 0;
        break;
    case 26: case 29:
        func_80041C20();
        func_80042A44();
        func_80043A38(0xC00);
        spyro.unk4[0] = 0;
        break;
    case 28:
        func_80041C20();
        func_80042A44();
        func_80041930();
        if (DecodedAnimationWordA0 < 0 && spyro.animationStateFrames >= 4)
            DecodedAnimationWord4C = 1;
        spyro.unk4[0] = 0;
        break;
    case 30: {
        register int* zPointer __asm__("$5") = (int*)(DecodedAnimationPlayer + 8);
        register int velocity __asm__("$6") = DecodedAnimationStep;
        register int position __asm__("$2") = *zPointer;
        register int tick __asm__("$3") = D_8006C648;
        register int status __asm__("$2");
        register int increment __asm__("$4");
        __asm__("" : "=r"(velocity) : "0"(velocity));
        __asm__("" : "=r"(position) : "0"(position));
        __asm__("" : "=r"(tick) : "0"(tick));
        increment = velocity >> 6;
        __asm__("" : "=r"(increment) : "0"(increment));
        position += increment;
        __asm__("" : "=r"(tick) : "0"(tick), "r"(position));
        tick <<= 9;
        *zPointer = position;
        status = DecodedAnimationLimitSelector;
        velocity += tick;
        DecodedAnimationStep = velocity;
        __asm__("" : : : "memory");
        if (status >= 0 && D_8006FA38 < 0) goto lowerLimit;
        {
            register int limit __asm__("$3") = 0x9000;
            register int exceeded __asm__("$2");
            __asm__("" : "=r"(limit) : "0"(limit));
            exceeded = limit < velocity;
            if (exceeded) DecodedAnimationStep = limit;
        }
        goto limitsDone;
    lowerLimit:
        {
            register int below __asm__("$2") = velocity < 0x2581;
            if (!below) DecodedAnimationStep = 0x2580;
        }
    limitsDone:
        func_80041C20();
        func_80042A44();
        func_8004F178(&sample, (Vector3D*)DecodedAnimationPlayer);
        sample.z += 0x400;
        spyro.unk4[0] = func_8001A358(&sample, 0xC00);
        DecodedAnimationZ -= DecodedAnimationStep >> 6;
        break;
    }
    case 58:
        func_80041C20();
        func_80042A44();
        DecodedAnimationByte23 = 255;
        spyro.unk4[0] = 0;
        DecodedAnimationByte22 = 32;
        DecodedAnimationByte21 = 32;
        DecodedAnimationByte20 = 32;
        break;
    }
}

#define LEVEL_ID 17
#define PlaySpyroSounds_level_17 func_level_17_80082DC4
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_17_80082ECC(int index) {
    Vector3D* position;
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x14: case 0x1a: case 0x1d: case 0x1e: case 0x20: case 0x3a: position = &spyro.unk9e; break;
    case 0x1c: position = 0; break;
    case 0x15: case 0x16: case 0x17: case 0x18: case 0x19: case 0x1b: case 0x1f: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f: case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: case 0x38: case 0x39: return;
    default: return;
    }
    func_80043ABC(position);
}

/* SCUS-94467: 80082F48..80083328; dispatch table 80074BBC..80074C58.
 * Empty constraints preserve original register lifetimes and memory ordering.
 * Existing field names do not establish helper, sound or state semantics.
 */
extern unsigned char Actor17SavedBase[] __asm__("D_80070328+0x144");
extern int Actor17Movement __asm__("D_80070328+0x50");
int Actor17CallSound15(int, Moby*, int) __asm__("PlaySound");
int Actor17CallSound09(int, Moby*, int) __asm__("PlaySound");
extern Spyro Actor17Spyro __asm__("D_80070328");
int Actor17Call8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
int Actor17Call8003636C(int low, int high) __asm__("func_8003636C");
void Actor17Call80043A38(int scale) __asm__("func_80043A38");
void Actor17Call800441F0(void) __asm__("func_800441F0");
void Actor17Call8004F168(Vector3D*) __asm__("func_8004F168");
extern int Actor17Word6E524 __asm__("D_8006E524");
void func_level_17_80082F48(int arg0) {
    register Vector3D *sourceVector __asm__("$16");
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register int previousMovementA0 __asm__("$4");
    register int previousMovementA1 __asm__("$5");
    register int previousMovementA2 __asm__("$6");
    register int previousMovementV1 __asm__("$3");
    register volatile int* savedWordPointer __asm__("$2");

    switch (arg0) {
    case 0x14:
        Actor17Movement = MOVEMENT_STATE_STAND;
        Actor17Spyro.unk5 = 0;
        Actor17Call800441F0();
        Actor17Spyro.grounded = 1;
        Actor17Spyro.union144.a.unk13cb = Actor17Call8003636C(1, 3);
        Actor17Spyro.union144.a.unk13cc = 0;
        goto clearSharedWords;
    default:
        return;
    case 0x1D:
        {
            register int component __asm__("$3");
            register int value __asm__("$2");
            previousMovementA0 = Actor17Movement;
            component = Actor17Spyro.unk17e.x;
            __asm__ __volatile__("" : : : "$2", "memory");
            value = 7;
            Actor17Movement = value;
            __asm__ __volatile__("" : : : "memory");
            value = Actor17Spyro.unk17e.y;
            Actor17Spyro.unk5 = 0;
            __asm__ __volatile__("" : : : "memory");
            component <<= 6;
            Actor17Spyro.unk7a[2].x = component;
            __asm__ __volatile__("" : : : "memory");
            component = Actor17Spyro.unk17e.z;
            value <<= 6;
            Actor17Spyro.union144.a.unk13cb = previousMovementA0;
            __asm__ __volatile__("" : : : "memory");
            Actor17Spyro.unk7a[2].y = value;
            value = component << 6;
            if (component == 0) {
                value = Actor17Spyro.unk7a[3].z;
            }
            __asm__("" : "=r"(value) : "0"(value));
            Actor17Spyro.unk7a[2].z = value;
        }
        Actor17Call80043A38(0xC00);
        Actor17Spyro.grounded = 1;
        Actor17Word6E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        Actor17CallSound15((int) D_8006C654->spyroHurt, 0, 0);
        goto clearSharedWords;
    case 0x1A:
        savedBase = Actor17SavedBase;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        previousMovementA1 = Actor17Movement;
        Actor17Movement = MOVEMENT_STATE_HURT;
        Actor17Spyro.unk5 = 0;
        *(int*)savedBase = previousMovementA1;
        Actor17Call8004F168(destination);
        Actor17Spyro.grounded = 1;
        Actor17Word6E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        Actor17CallSound09((int) D_8006C654->squish, 0, 0);
        goto clearSharedWords;
    case 0x1C:
        savedBase = Actor17SavedBase;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceVector = (Vector3D*)(savedBase - 0xAC);
        previousMovementA2 = Actor17Movement;
        Actor17Movement = MOVEMENT_STATE_HURT;
        Actor17Spyro.unk5 = 0;
        *(int*)savedBase = previousMovementA2;
        func_8004F178(destination, sourceVector);
        Actor17Spyro.unk8[0] = Actor17Call8004EDE8(sourceVector, 0);
        Actor17Spyro.unk7a[2].z = 0xDC0;
        Actor17Spyro.grounded = 0;
        Actor17Word6E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Actor17Spyro.damageFlags & 0x200) {
            Actor17Spyro.union144.a.unk13cc = 0;
        } else {
            Actor17Spyro.union144.a.unk13cc = 1;
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        goto clearSharedWords;
    case 0x1E:
        {
            register char* (*particles)(int,int,Vector3D*,Vector3D*) __asm__("$8");
            register int value __asm__("$2");
            previousMovementV1 = Actor17Movement;
            particles = SpawnParticle;
            __asm__ __volatile__("" : : : "$2", "memory");
            value = 7;
            __asm__("" : "=r"(particles) : "0"(particles), "r"(value));
            Actor17Movement = value;
            value = 1;
            Actor17Spyro.grounded = value;
            value = 15;
            Actor17Word6E524 = value;
            __asm__ __volatile__("" : : : "$2", "memory");
            savedWordPointer = (volatile int*)Actor17SavedBase;
            __asm__("" : "=r"(savedWordPointer) : "0"(savedWordPointer));
            Actor17Spyro.unk5 = 0;
            /* Preserve both original stores; the zero store fills a branch delay. */
            *savedWordPointer = previousMovementV1;
            *(int*)savedWordPointer = 0;
            if (particles) {
                particles(5, 10, 0, 0);
            }
        }
        Actor17Spyro.unk22[2] = PlaySound((int) D_8006C654->drown, 0, 0);
        {
            register int descriptor __asm__("$2") = D_8006C654->drown;
            __asm__ __volatile__("" : : : "memory");
            Actor17Spyro.unk20a = 0;
            Actor17Spyro.critterMobyPtr = 0;
            __asm__("" : "=r"(descriptor) : "0"(descriptor));
            Actor17Spyro.unk22[3] = descriptor;
        }
        return;
    case 0x20:
    case 0x3A:
        Actor17Movement = MOVEMENT_STATE_DEATH;
        Actor17Spyro.unk5 = 0;
        Actor17Call80043A38(0xC00);
        Actor17Spyro.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Actor17Word6E524 = 0xF;
        goto clearSharedWords;
    }
clearSharedWords:
    Actor17Spyro.unk20a = 0;
    Actor17Spyro.critterMobyPtr = 0;
}


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level17
 * 8008332C: original439 instructions and39 dispatch words in sibling4500
 * and original assembly. Verified40 state/helper and animation-byte C reused.
 * All raw field addresses, selectors and branches follow original17.
 * Meanings, units and cadence unresolved; native/linked/all hash gates required. */
extern int A17W48 __asm__("D_80070328 + 0x48");
extern int A17W4C __asm__("D_80070328 + 0x4C");
extern int A17W54 __asm__("D_80070328 + 0x54");
extern int A17WA0 __asm__("D_80070328 + 0xA0");
extern int A17WA8 __asm__("D_80070328 + 0xA8");
extern int A17WAC __asm__("D_80070328 + 0xAC");
extern int A17WB0 __asm__("D_80070328 + 0xB0");
extern int A17WB8 __asm__("D_80070328 + 0xB8");
extern int A17WCC __asm__("D_80070328 + 0xCC");
extern int A17WD0 __asm__("D_80070328 + 0xD0");
extern int A17WD4 __asm__("D_80070328 + 0xD4");
extern int A17W8C __asm__("D_80070328 + 0x8C");
extern int A17W90 __asm__("D_80070328 + 0x90");
extern int A17W94 __asm__("D_80070328 + 0x94");
extern int A17WE4 __asm__("D_80070328 + 0xE4");
extern int A17W144 __asm__("D_80070328 + 0x144");
extern int A17W158 __asm__("D_80070328 + 0x158");
extern int A17W1EC __asm__("D_80070328 + 0x1EC");
extern int A17W1F0 __asm__("D_80070328 + 0x1F0");
extern int A17W240 __asm__("D_80070328 + 0x240");
extern int A17W280 __asm__("D_80070328 + 0x280");
extern unsigned char A17B14 __asm__("D_80070328 + 0x14");
extern unsigned char A17B15 __asm__("D_80070328 + 0x15");
extern unsigned char A17B16 __asm__("D_80070328 + 0x16");
extern unsigned char A17B17 __asm__("D_80070328 + 0x17");
extern unsigned char A17B1C __asm__("D_80070328 + 0x1C");
extern unsigned char A17BFC __asm__("D_80070328 + 0xFC");
extern unsigned char A17B1B5 __asm__("D_80070328 + 0x1B5");
extern unsigned char A17B1B6 __asm__("D_80070328 + 0x1B6");
extern unsigned char A17Player[] __asm__("D_80070328");
extern unsigned char A17Table[] __asm__("D_80066530");
extern int A17Buttons __asm__("D_8006E538"),A17NewButtons __asm__("D_8006E53C");
extern int A17Mode __asm__("D_8006E044"),A17Gate __asm__("D_8006E344"),A17Count __asm__("D_8006C514");
extern int (*A17Callback)() __asm__("unk_ovlheader_80074374");
extern int A17W24 __asm__("D_80070328 + 0x24");
extern int A17W28C __asm__("D_80070328 + 0x28C");
extern int A17W290 __asm__("D_80070328 + 0x290");
extern int A17Surface __asm__("D_8006FA38");
extern unsigned char* A17SoundDesc __asm__("D_8006C654");
int A17Sound() __asm__("PlaySound");
int A17H3BF6C() __asm__("func_8003BF6C");
int A17H3BE70() __asm__("func_8003BE70");
int A17H40994() __asm__("func_80040994");
int A17H4BEF8() __asm__("func_8004BEF8");
int A17H49688() __asm__("func_80049688");
int A17H4F334() __asm__("func_8004F334");
int A17H498C0() __asm__("func_800498C0");
void func_level_17_8008332C(void) {
 register int work2 __asm__("$2");
 register int work3 __asm__("$3");
 register int work4 __asm__("$4");
 register int work5 __asm__("$5");
 register int* state __asm__("$16");
 switch(A17W48) {
 case 21: case 22: case 23: case 24: case 25: case 27: case 31: case 33: case 34: case 35: case 36: case 37: case 38: case 39: case 40: case 41: case 42: case 43: case 44: case 45: case 46: case 47: case 48: case 49: case 50: case 51: case 52: case 53: case 54: case 55: case 56: case 57: return;
 case 20:
  if(A17H40994())return;
  if(A17NewButtons&0x40)goto set6;
  if(A17WB8>=4 || A17WE4>=23)goto set7;
  work3=A17Buttons;
  if(work3&0x80){A17H4BEF8(13);return;}
  work2=A17WA8;if(work2<0)work2=-work2;
  if(work2>=17)goto set1;
  work2=work3&12;
  __asm__("" : "=r"(work2):"0"(work2));
  if(!work2 && A17WAC)goto set1;
  if(A17Mode==7 || A17W240) {
   state=&A17W48;__asm__("" : "=r"(state):"0"(state));
   if(!*state)return;
   A17H4BEF8(0);
   if(A17Table[*((unsigned char*)state-0x2C)]>=96){A17B14=A17B15;A17B16=A17B17;}
   A17B17=0;work3=*state;work2=113;*((unsigned char*)state-0x2C)=work2;
   A17W1F0=0;A17B15=work3;A17W1EC=work3;return;
  }
  if(A17BFC){A17H4BEF8(15);return;}
  A17H49688();return;
 case 29:
  if(A17W54<25)return;
  if(A17W280<0){A17H4BEF8(31);return;}
  selectState:
  work3=A17W144;
  if(work3==10)goto set44;
  work2=work3-11;
  __asm__("" : "=r"(work2):"0"(work2));
  if((unsigned int)work2<2)goto set41;
  if(!A17WB8)goto set0;
  goto set7;
 case 26:
  if(A17W24&16)return;
  if(A17W54<25)return;
  if(A17W280<0){A17H4BEF8(32);return;}
  A17Sound(A17SoundDesc[15],0,0);
  goto selectState;
  set44:A17H4BEF8(44);return;
  set41:A17H4BEF8(41);return;
 case 28:
  if(A17B1B5 && (A17NewButtons&64))A17B1B6=1;
  if(A17WB8 || A17W54<16 || A17WE4>=23)goto buttons;
  work3=A17WCC;work2=A17W8C;work5=work3*work2;
  work3=A17WD0;work2=A17W90;work4=work3*work2;
  work3=A17WD4;work2=A17W94;work3=work3*work2;
  work2=work5+work4;work2+=work3;
  if(work2>=0)goto buttons;
  if(!A17WAC)goto checkSpeed;
  work3=A17WB0;
  if(work3>3840){A17H4BEF8(3);return;}
  work2=work3<1921;
  __asm__("" : "=r"(work2):"0"(work2));
  if(!work2){A17H4BEF8(2);return;}
  set1:A17H4BEF8(1);return;
  checkSpeed:
  if(A17WB0<1920)goto set0;
  A17H4BEF8(4);return;
  set0:A17H4BEF8(0);return;
  buttons:
  if((A17Buttons&128) && A17W4C==1){A17H4BEF8(22);return;}
  if(A17B1B5 && A17B1B6){
   if(A17W4C!=1)return;
   set17:A17H4BEF8(17);return;
  }
  if(A17W4C!=1)return;
  if(A17WA0< -6400)goto set7;
  if(A17W54<91)return;
  set7:A17H4BEF8(7);return;
 case 30: {
  register int* timer4 __asm__("$4");
  register int (*callback3)() __asm__("$3");
  if(A17NewButtons&64)A17B1B6=1;
  if(A17Surface>=0){
   if(A17W144<=0x8FFF)return;
   callback3=A17Callback;A17W28C=-1;
   if(callback3){callback3();return;}
   goto call498C0;
  }
  timer4=&A17W280;__asm__("" : "=r"(timer4):"0"(timer4));
  if(*timer4<0){
   if(A17W144<=0x8FFF)return;
   A17W28C=-1;goto call498C0;
  }
  work3=A17W54;
  if(work3>=61){*timer4=-1;return;}
  work2=work3<16;
  __asm__("" : "=r"(work2):"0"(work2));
  if(work2)return;
  if(!A17B1B6)return;
  if(A17W28C>=0){
   if(A17H3BF6C(A17W290,A17W28C))A17H3BE70(A17W28C);
   A17W28C=-1;
  }
  set6:A17H4BEF8(6);return;
 }
 case 32:
  work2=A17W54<125;goto checkTimer;
 case 58:
  work2=A17W54<137;
  checkTimer:if(work2)return;
  call498C0:A17H498C0();return;
 }
}

