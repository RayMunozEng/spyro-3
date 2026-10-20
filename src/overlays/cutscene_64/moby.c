#include "common.h"
#include "ovl_header.h"
#include "stdutil.h"
#include "spyro.h"

void func_cutscene_64_80074780(void) {}

extern short D_800658A0[], D_80065920[];
extern int DecodedParticleColour __asm__("D_80065868");
extern void* func_8002EC50(int, int, int);
void func_cutscene_64_80074788(Moby* moby) {
    Vector3D offset, middle;
    void* effect;
    int angle = func_8003636C(0, 0xFF);
    func_80055D24(moby, 4);
    *(int*)&moby->colour = DecodedParticleColour;
    func_80055F14(moby, 1, &middle);
    func_80055F14(moby, 0, &offset);
    func_8004F194(&middle, &middle, &offset);
    func_8004F110(&middle, 1);
    offset.x = D_80065920[angle & 0xFF] * func_8003636C(1, 20) >> 12;
    offset.y = D_800658A0[angle & 0xFF] * func_8003636C(1, 20) >> 12;
    offset.z = 0;
    func_8004F194(&offset, &middle, &offset);
    SpawnParticle(2, 0x42, &offset, (Vector3D*)1);
    func_80055F14(moby, 2, &middle);
    func_80055F14(moby, 0, &offset);
    func_8004F194(&middle, &middle, &offset);
    func_8004F110(&middle, 1);
    angle = func_8003636C(0, 0xFF);
    offset.x = D_80065920[angle & 0xFF] * func_8003636C(1, 20) >> 12;
    offset.y = D_800658A0[angle & 0xFF] * func_8003636C(1, 20) >> 12;
    offset.z = 0;
    func_8004F194(&offset, &middle, &offset);
    SpawnParticle(2, 0x42, &offset, (Vector3D*)1);
    if (!moby->mobyTag) {
        moby->mobyTag = func_8002EC50(1, 0x40, 0x489090);
        if (!moby->mobyTag) return;
    }
    {
        effect = moby->mobyTag;
        *((unsigned char*)effect + 0x10) = 1;
        func_80055F14(moby, 0, effect);
    }
}

void func_cutscene_64_800749DC(void) {}

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* AI generated;
 not human reviewed. Matched C. Original source asm/nonmatchings/overlays/cutscene_64/moby/func_cutscene_64_800749E4.s SHA256 4845922c3a1ca3827759876e832499c36fcdfe106ea5f6f6ff3798f70f0299ef. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Cutscene64_749E4Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
extern int Cutscene64_749E4_func_8002EC50(char, char, int) __asm__("func_8002EC50");
int Cutscene64_749E4_func_8003636C(int low, int high) __asm__("func_8003636C");
extern void Cutscene64_749E4_func_8004F178(Vector3D*, Vector3D*) __asm__("func_8004F178");
extern void Cutscene64_749E4_func_80055D24(Moby*, int) __asm__("func_80055D24");

unsigned char Cutscene64_749E4_func_8004F168(Vector3D *) __asm__("func_8004F168");
                  /* extern */
unsigned char Cutscene64_749E4_func_80055F14(Moby *, unsigned char, int *) __asm__("func_80055F14");
      /* extern */
extern int Cutscene64_749E4_D_8006EDDC __asm__("D_8006EDDC");

void func_cutscene_64_800749E4(Moby *inputOwner) {
    /* Original 0x50 frame: vectors at SP10 and SP20, with padding at
     * SP1C and SP2C. The five unsigned counter windows reload D_8006EDDC
     * independently. Each random result is combined with the current
     * scratch coordinate, including the original subtraction by 100.
     * Particle selectors, loop counts, state stores and shared branch
     * destinations retain their original producers. Empty constraints
     * preserve the native register ordering and emit no instructions.
     * Helper meanings, physical units/fixed point, update cadence and
     * runtime capture validation remain unresolved. AI generated;
     * not human reviewed. */
    register Moby* owner18 __asm__("$18")=inputOwner;
    struct {Vector3D first;
    int pad1C;
    Vector3D second;
    int pad2C;
    } scratch;
    register Vector3D* particleTag7 __asm__("$7");
    register Vector3D* secondaryParticleTag7 __asm__("$7");
    register int argument4 __asm__("$4");
    register int argument5 __asm__("$5");
    register Vector3D *argument6 __asm__("$6");
    register int raw2 __asm__("$2");
    register int raw3 __asm__("$3");
    int temp_a0;
    int temp_a0_2;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v1;
    int temp_v1_3;
    int var_a0;
    int var_a0_2;
    int var_a1;
    int var_a1_2;
    register int activeOrLoop16 __asm__("$16");
    register int secondary19 __asm__("$19");
    register int threshold20 __asm__("$20");
    register int primary21 __asm__("$21");
    int var_v0;
    int var_v0_2;
    unsigned char temp_a1;
    unsigned char temp_a1_2;
    unsigned char temp_v1_2;
    unsigned char temp_v1_4;
    register void* private17 __asm__("$17");

    __asm__("":"=r"(owner18):"0"(owner18));
    activeOrLoop16=0;
    secondary19 = 0;
    primary21 = 1;
    if (owner18->substate == 0) {
        owner18->substate = 1;
        owner18->mobyTag = SpawnMoby(0x2C3A, owner18)->mobyTag;
    }
    private17 = owner18->mobyTag;
    if (((unsigned int) (Cutscene64_749E4_D_8006EDDC - 0x22B) < 0x91U) && (owner18->state != 2)) {
        activeOrLoop16 = 1;
        threshold20 = 0x280;
    } else if (((unsigned int) (Cutscene64_749E4_D_8006EDDC - 0x369) < 0x7FU) && (owner18->state != 2)) {
        activeOrLoop16 = 1;
        threshold20 = 0x3A2;
    } else if (((unsigned int) (Cutscene64_749E4_D_8006EDDC - 0x54D) < 0xA3U) && (owner18->state != 2)) {
        activeOrLoop16 = 1;
        threshold20 = 0x5AE;
    } else if (((unsigned int) (Cutscene64_749E4_D_8006EDDC - 0xFAA) < 0x8CU) && (owner18->state != 2)) {
        activeOrLoop16 = 1;
        threshold20 = 0xFFA;
        secondary19 = 1;
        primary21 = 0;
    } else if (((unsigned int) (Cutscene64_749E4_D_8006EDDC - 0x147D) < 0x87U) && (owner18->state != 2)) {
        activeOrLoop16 = 1;
        threshold20 = 0x14B4;
        secondary19 = 1;
    } else {
        owner18->state = 0;
    }
    if (activeOrLoop16 != 0) {
        if (owner18->state == 0) {
            if (primary21 != 0) {
                temp_v0 = Cutscene64_749E4_func_8002EC50(1, 0x10, 0x489090);
                Cutscene64_749E4Field(private17, int *, 0) = temp_v0;
                Cutscene64_749E4Field(temp_v0, signed char *, 0x10) = 4;
                Cutscene64_749E4Field(Cutscene64_749E4Field(private17, int *, 0), signed char *, 0x13) = 8;
            }
            if (secondary19 != 0) {
                temp_v0_2 = Cutscene64_749E4_func_8002EC50(1, 0x10, 0x489090);
                Cutscene64_749E4Field(private17, int *, 4) = temp_v0_2;
                Cutscene64_749E4Field(temp_v0_2, signed char *, 0x10) = 4;
                Cutscene64_749E4Field(Cutscene64_749E4Field(private17, int *, 4), signed char *, 0x13) = 8;
            }
            owner18->state = 1;
        }
        Cutscene64_749E4_func_80055D24(owner18, 4);
        if (primary21 != 0) {
            Cutscene64_749E4_func_80055F14(owner18, 0, &scratch.first.x);
            if (Cutscene64_749E4_D_8006EDDC >= threshold20) {
                var_a0 = 0xC;
                if (secondary19 != 0) {
                    var_a0 = 0x10;
                }
                temp_v1 = Cutscene64_749E4Field(private17, int *, 0);
                temp_a1 = Cutscene64_749E4Field(temp_v1, unsigned char *, 0x11);
                if ((int) temp_a1 >= (var_a0 + 1)) {
                    Cutscene64_749E4Field(temp_v1, unsigned char *, 0x11) = (unsigned char) (temp_a1 - var_a0);
                    goto updatePrimaryPosition;
                }
                if (temp_v1 != 0) {
                    Cutscene64_749E4Field(temp_v1, signed char *, 0x10) = 0;
                    temp_v0_3 = Cutscene64_749E4Field(private17, int *, 4);
                    Cutscene64_749E4Field(private17, int *, 0) = 0;
                    if (temp_v0_3 != 0) {
                        Cutscene64_749E4Field(temp_v0_3, signed char *, 0x10) = 0;
                        Cutscene64_749E4Field(private17, int *, 4) = 0;
                    }
                    activeOrLoop16 = 0;
                    if (secondary19 != 0) {
                        do {
                            raw2=Cutscene64_749E4_func_8003636C(0,200);
                            argument4=0;
                            argument5=200;
                            __asm__ volatile("":"=r"(argument4),"=r"(argument5):"0"(argument4),"1"(argument5),"r"(raw2):"memory");
                            raw3=scratch.first.x;
                            __asm__ volatile("":"=r"(activeOrLoop16):"0"(activeOrLoop16),"r"(raw3):"memory");
                            activeOrLoop16+=1;
                            raw3-=100;
                            __asm__("":"=r"(raw3):"0"(raw3));
                            raw3+=raw2;
                            scratch.first.x=raw3;
                            raw2=Cutscene64_749E4_func_8003636C(argument4,argument5);
                            raw3=scratch.first.y;
                            raw3-=100;
                            __asm__("":"=r"(raw3):"0"(raw3));
                            raw3+=raw2;
                            scratch.first.y=raw3;
                            raw2=Cutscene64_749E4_func_8003636C(0,200);
                            raw3=scratch.first.z;
                            raw3-=100;
                            __asm__("":"=r"(raw3):"0"(raw3));
                            raw3+=raw2;
                            scratch.first.z=raw3;
                            Cutscene64_749E4_func_8004F168(&scratch.second);
                            SpawnParticle(1, 0, (Vector3D *) &scratch.first.x, &scratch.second);
                        } while (activeOrLoop16 < 5);
                    }
                    goto finishState2;
                }
                goto updatePrimaryPosition;
            }
            var_v0 = 0x80;
            var_a1 = 0xC;
            if (secondary19 != 0) {
                var_v0 = 0xA0;
                var_a1 = 8;
            }
            temp_a0 = Cutscene64_749E4Field(private17, int *, 0);
            temp_v1_2 = Cutscene64_749E4Field(temp_a0, unsigned char *, 0x11);
            if (var_v0 >= (int) temp_v1_2) {
                Cutscene64_749E4Field(temp_a0, unsigned char *, 0x11) = (unsigned char) (temp_v1_2 + var_a1);
updatePrimaryPosition:
            }
            argument4=Cutscene64_749E4Field(private17,int*,0);
            argument5=(int)&scratch.first;
            __asm__ volatile("":"=r"(argument4),"=r"(argument5):"0"(argument4),"1"(argument5):"memory");
            Cutscene64_749E4_func_8004F178((Vector3D*)argument4,(Vector3D*)argument5);
            activeOrLoop16=0;
            do {
                raw2=Cutscene64_749E4_func_8003636C(0,200);
                raw3=scratch.first.x;
                raw3-=100;
                __asm__("":"=r"(raw3):"0"(raw3));
                raw3+=raw2;
                scratch.first.x=raw3;
                raw2=Cutscene64_749E4_func_8003636C(0,200);
                raw3=scratch.first.y;
                raw3-=100;
                __asm__("":"=r"(raw3):"0"(raw3));
                raw3+=raw2;
                scratch.first.y=raw3;
                raw2=Cutscene64_749E4_func_8003636C(0,200);
                raw3=scratch.first.z;
                raw3-=100;
                __asm__("":"=r"(raw3):"0"(raw3));
                raw3+=raw2;
                scratch.first.z=raw3;
                particleTag7=(Vector3D*)1;
                if (activeOrLoop16 == 0) {
                    particleTag7 = (Vector3D *)2;
                }
                argument4=2;
                argument5=0x42;
                argument6=&scratch.first;
                __asm__ volatile("":"=r"(argument4),"=r"(argument5),"=r"(argument6):"0"(argument4),"1"(argument5),"2"(argument6),"r"(particleTag7));
                SpawnParticle(argument4,argument5,argument6,particleTag7);
                activeOrLoop16+=1;
            } while (activeOrLoop16 < 4);
            goto updateSecondary;
        }
updateSecondary:
        if (secondary19 != 0) {
            Cutscene64_749E4_func_80055F14(owner18, 1, &scratch.first.x);
            var_a1_2 = 0xC;
            if (Cutscene64_749E4_D_8006EDDC >= threshold20) {
                var_a0_2 = 0xC;
                if (primary21 != 0) {
                    var_a0_2 = 0x10;
                }
                temp_v1_3 = Cutscene64_749E4Field(private17, int *, 4);
                temp_a1_2 = Cutscene64_749E4Field(temp_v1_3, unsigned char *, 0x11);
                if ((int) temp_a1_2 >= (var_a0_2 + 1)) {
                    Cutscene64_749E4Field(temp_v1_3, unsigned char *, 0x11) = (unsigned char) (temp_a1_2 - var_a0_2);
                    goto updateSecondaryPosition;
                }
                if (temp_v1_3 != 0) {
                    Cutscene64_749E4Field(temp_v1_3, signed char *, 0x10) = 0;
                    temp_v0_4 = Cutscene64_749E4Field(private17, int *, 0);
                    Cutscene64_749E4Field(private17, int *, 4) = 0;
                    if (temp_v0_4 != 0) {
                        Cutscene64_749E4Field(temp_v0_4, signed char *, 0x10) = 0;
                        Cutscene64_749E4Field(private17, int *, 0) = 0;
                    }
                    activeOrLoop16 = 0;
                    if (primary21 != 0) {
                        do {
                            raw2=Cutscene64_749E4_func_8003636C(0,200);
                            argument4=0;
                            argument5=200;
                            __asm__ volatile("":"=r"(argument4),"=r"(argument5):"0"(argument4),"1"(argument5),"r"(raw2):"memory");
                            raw3=scratch.first.x;
                            __asm__ volatile("":"=r"(activeOrLoop16):"0"(activeOrLoop16),"r"(raw3):"memory");
                            activeOrLoop16+=1;
                            raw3-=100;
                            __asm__("":"=r"(raw3):"0"(raw3));
                            raw3+=raw2;
                            scratch.first.x=raw3;
                            raw2=Cutscene64_749E4_func_8003636C(argument4,argument5);
                            raw3=scratch.first.y;
                            raw3-=100;
                            __asm__("":"=r"(raw3):"0"(raw3));
                            raw3+=raw2;
                            scratch.first.y=raw3;
                            raw2=Cutscene64_749E4_func_8003636C(0,200);
                            raw3=scratch.first.z;
                            raw3-=100;
                            __asm__("":"=r"(raw3):"0"(raw3));
                            raw3+=raw2;
                            scratch.first.z=raw3;
                            Cutscene64_749E4_func_8004F168(&scratch.second);
                            SpawnParticle(1, 0, (Vector3D *) &scratch.first.x, &scratch.second);
                        } while (activeOrLoop16 < 5);
                    }
finishState2:
                    owner18->state = 2;
                    return;
                }
                goto updateSecondaryPosition;
            }
            var_v0_2 = 0x80;
            if (primary21 != 0) {
                var_a1_2 = 8;
                var_v0_2 = 0xA0;
            }
            temp_a0_2 = Cutscene64_749E4Field(private17, int *, 4);
            temp_v1_4 = Cutscene64_749E4Field(temp_a0_2, unsigned char *, 0x11);
            if (var_v0_2 >= (int) temp_v1_4) {
                Cutscene64_749E4Field(temp_a0_2, unsigned char *, 0x11) = (unsigned char) (temp_v1_4 + var_a1_2);
updateSecondaryPosition:
            }
            argument4=Cutscene64_749E4Field(private17,int*,4);
            argument5=(int)&scratch.first;
            __asm__ volatile("":"=r"(argument4),"=r"(argument5):"0"(argument4),"1"(argument5):"memory");
            Cutscene64_749E4_func_8004F178((Vector3D*)argument4,(Vector3D*)argument5);
            activeOrLoop16=0;
            do {
                raw2=Cutscene64_749E4_func_8003636C(0,200);
                raw3=scratch.first.x;
                raw3-=100;
                __asm__("":"=r"(raw3):"0"(raw3));
                raw3+=raw2;
                scratch.first.x=raw3;
                raw2=Cutscene64_749E4_func_8003636C(0,200);
                raw3=scratch.first.y;
                raw3-=100;
                __asm__("":"=r"(raw3):"0"(raw3));
                raw3+=raw2;
                scratch.first.y=raw3;
                raw2=Cutscene64_749E4_func_8003636C(0,200);
                raw3=scratch.first.z;
                raw3-=100;
                __asm__("":"=r"(raw3):"0"(raw3));
                raw3+=raw2;
                scratch.first.z=raw3;
                secondaryParticleTag7=(Vector3D*)1;
                if (activeOrLoop16 == 0) {
                    secondaryParticleTag7 = (Vector3D *)2;
                }
                argument4=2;
                argument5=0x42;
                argument6=&scratch.first;
                __asm__ volatile("":"=r"(argument4),"=r"(argument5),"=r"(argument6):"0"(argument4),"1"(argument5),"2"(argument6),"r"(secondaryParticleTag7));
                SpawnParticle(argument4,argument5,argument6,secondaryParticleTag7);
                activeOrLoop16+=1;
            } while (activeOrLoop16 < 4);
        }
    }
}
#undef Cutscene64_749E4Field


extern Moby* D_8006C550;
Moby* func_80055A7C(void);
void func_80034FEC(Moby*);
int func_80055D10(Moby*);
int func_80055C24(Moby*);
void func_8004F178(Vector3D*, Vector3D*);
Moby* func_cutscene_64_80075008(int mobyClass, Moby* parent) {
    Moby* moby = func_80055A7C();
    void* tag;
    if (!moby) return 0;
    tag = moby->mobyTag;
    func_8004E790(moby, 0, sizeof(Moby));
    moby->mobyTag = tag;
    func_8004E790(tag, 0, 0x18);
    moby->mobyClass = mobyClass;
    if (parent) {
        int index = parent - D_8006C550;
        if ((unsigned int)index < 0x100) moby->linkedMoby = index;
        else moby->linkedMoby = 0xFF;
    } else moby->linkedMoby = 0xFF;
    func_80034FEC(moby);
    if (mobyClass == 0x2C3A) {
        func_8004F178(&moby->position, &parent->position);
        moby->mobyClass = 0xFF;
        moby->distanceToGround = 0x2C3A;
        func_80055D10(moby);
        moby->updateDistance = 0xFF;
    } else {
        if (parent) func_8004F178(&moby->position, &parent->position);
        else func_8004F178(&moby->position, &spyro.position);
        func_80055C24(moby);
    }
    return moby;
}
