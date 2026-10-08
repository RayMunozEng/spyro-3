#include "common.h"
#include "stdutil.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_40/animation", func_level_40_80085FA8);

extern unsigned char DecodedAnimationPlayer[] __asm__("D_80070328");
extern int D_8006C648, D_8006FA38;
extern int DecodedAnimationStep __asm__("D_80070328 + 0x144");
extern int DecodedAnimationZ __asm__("D_80070328 + 8");
extern int DecodedAnimationLimitSelector __asm__("D_80070328 + 0x280");
int func_8001A358(Vector3D*, int);
/* USA SCUS-94467 Rev 0, 0x800863B8..0x80086564, 107 words.
 * Mode20/19 helper order reuses verified level27 animation C. Mode30
 * preserves raw position/step words, signed shift6, tick shift9, limits
 * 0x9000/0x2580 and the sampled vector's Z+0x400 / helper argument0xC00.
 * Scalar assembler aliases identify original player offsets; empty constraints
 * retain original fresh reads and scheduling without emitting instructions.
 * Physical units, update cadence, producer and helper semantic chains remain
 * unresolved. AI generated; not yet human reviewed.
 */
void func_level_40_800863B8(void) {
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
    case 19:
        func_80041C20();
        func_80042A44();
        func_80041930();
        spyro.unk4[0] = 0;
        break;
    case 30: {
        register int velocity __asm__("$5") = DecodedAnimationStep;
        register int position __asm__("$2") = DecodedAnimationZ;
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
        DecodedAnimationZ = position;
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
    }
}

#define LEVEL_ID 40
#define PlaySpyroSounds_level_40 func_level_40_80086564
#include "overlay/animation.inc.h"

typedef struct { int words[4]; } DecodedAnimationEntry16;
extern DecodedAnimationEntry16 D_8006E548[];
extern DecodedAnimationEntry16* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_40_8008656C(int index) {
    D_8006C570 = &D_8006E548[index];
    switch (spyro.animationState) {
    case 0x13:
        func_80043ABC(0);
        break;
    case 0x14:
    case 0x1E:
        func_80043ABC(&spyro.unk9e);
        break;
    }
}


/* AI-generated; not human reviewed. Numeric offsets from SCUS-94467. */
extern int RawW4C __asm__("D_80070328+0x4C");
extern int RawW50 __asm__("D_80070328+0x50");
extern int RawW08 __asm__("D_80070328+8");
extern int RawW64 __asm__("D_80070328+0x64");
extern int RawW144 __asm__("D_80070328+0x144"), RawW148 __asm__("D_80070328+0x148");
extern int RawW14C __asm__("D_80070328+0x14C"), RawW150 __asm__("D_80070328+0x150");
extern int RawW154 __asm__("D_80070328+0x154"), RawW158 __asm__("D_80070328+0x158");
extern int RawW168 __asm__("D_80070328+0x168"), RawW16C __asm__("D_80070328+0x16C");
extern int RawW244 __asm__("D_80070328+0x244"), RawW250 __asm__("D_80070328+0x250");
extern int RawW28C __asm__("D_80070328+0x28C"), RawW290 __asm__("D_80070328+0x290");
extern unsigned char RawB1B4 __asm__("D_80070328+0x1B4");
extern unsigned char* RawActor __asm__("D_80070328+0x218");
extern unsigned char* RawDescriptor __asm__("D_8006C654");
extern int RawGlobal __asm__("D_8006E524");
extern int (*RawCallback)(int,int,void*,void*) __asm__("SpawnParticle");
void Raw441F0(void) __asm__("func_800441F0");
int Raw3636C(int,int) __asm__("func_8003636C");
void Raw4F168(void*) __asm__("func_8004F168");
void Raw4F178(void*,void*) __asm__("func_8004F178");
int RawSound(int,void*,int) __asm__("PlaySound");
typedef int (*RawCallbackType)(int,int,void*,void*);
void func_level_40_800865E4(int selector) {
    register unsigned char* data __asm__("$16");
    register unsigned char* stateBase __asm__("$17");
    switch (selector) {
    case 20:
        RawW50 = 0;
        RawW4C = 0;
        Raw441F0();
        RawB1B4 = 1;
        RawW144 = Raw3636C(1, 3);
        RawW148 = 0;
        RawW244 = 0;
        RawW250 = 0;
        return;
    case 19: {
        register unsigned char* actor __asm__("$6");
        register int rotation __asm__("$5");
        register int z __asm__("$2");
        register int value __asm__("$3");
        register int right __asm__("$4");
        register int result __asm__("$2");
        register unsigned char* destination __asm__("$4");
        stateBase = (unsigned char*)&RawW50;
        data = *(unsigned char**)RawActor;
        *(int*)stateBase = 14;
        RawW4C = 0;
        RawB1B4 = 0;
        Raw4F168(stateBase + 60);
        actor = RawActor;
        rotation = RawW64;
        z = RawW08;
        value = *(int*)(actor + 20);
        right = *(int*)data;
        RawW148 = rotation;
        RawW144 = z;
        value = value + right;
        RawW14C = value;
        value = value - z;
        __asm__("" : "=r"(value) : "0"(value));
        value = value - 2048;
        RawW154 = value;
        value = ((int)((unsigned int)value << 10) >> 10) + 1024;
        RawW150 = value;
        value = ((actor[70] * 16 - rotation) - value) & 4095;
        RawW150 = value;
        destination = stateBase + 268;
        if (value >= 2049) {
            result = value - 4096;
            __asm__("" : "=r"(result) : "0"(result), "r"(destination));
            RawW150 = result;
        }
        RawW158 = *(int*)(data + 4);
        Raw4F178(destination, actor + 12);
        RawW168 = RawActor[70];
        result = *(int*)(data + 8);
        RawW244 = 0;
        RawW250 = 0;
        RawW16C = result;
        return;
    }
    case 30: {
        register int previous __asm__("$3") = RawW50;
        register int state __asm__("$2");
        register int* word __asm__("$2");
        register RawCallbackType callback __asm__("$8") = RawCallback;
        state = 7;
        RawW50 = state;
        state = 1;
        RawB1B4 = state;
        state = 15;
        RawGlobal = state;
        word = &RawW144;
        RawW4C = 0;
        *word = previous;
        __asm__ volatile("" : : "r"(word) : "memory");
        *word = 0;
        if (callback) callback(5, 10, 0, 0);
        RawW28C = RawSound(RawDescriptor[14], 0, 0);
        state = RawDescriptor[14];
        RawW244 = 0;
        RawW250 = 0;
        RawW290 = state;
        return;
    }
    }
}


extern int P86860FieldB8 __asm__("D_80070328 + 0xB8");
extern int P86860FieldE4 __asm__("D_80070328 + 0xE4");
extern int P86860FieldA8 __asm__("D_80070328 + 0xA8");
extern int P86860FieldAC __asm__("D_80070328 + 0xAC");
extern int P86860Field240 __asm__("D_80070328 + 0x240");
extern unsigned char P86860FieldFC __asm__("D_80070328 + 0xFC");
extern int P86860Field158 __asm__("D_80070328 + 0x158");
extern int P86860Field144 __asm__("D_80070328 + 0x144");
extern int P86860Field280 __asm__("D_80070328 + 0x280");
extern int P86860Field54 __asm__("D_80070328 + 0x54");
extern unsigned char P86860Field1B6 __asm__("D_80070328 + 0x1B6");
extern int P86860Field28C __asm__("D_80070328 + 0x28C");
extern int P86860Field290 __asm__("D_80070328 + 0x290");
extern int P86860State __asm__("D_80070328 + 0x48");
extern unsigned char P86860Table[] __asm__("D_80066530");
extern int D_8006C514;
extern int D_8006E044;
extern int D_8006E344;
extern int D_8006E538;
extern int D_8006E53C;
extern int D_8006FA38;

/* USA Rev 0, 0x80086860..0x80086C10: 237 original instructions.
 * Raw aliases preserve exact field addresses; complete field/helper meanings,
 * units and caller cadence remain unresolved. Empty constraints emit no opcodes.
 * AI generated; not yet human reviewed. */
void func_level_40_80086860(void) {
    register int magnitude2 __asm__("$2");
    register int sampledState3 __asm__("$3"), literal2 __asm__("$2");
    register unsigned int requestedState4 __asm__("$4");
    register int *state16 __asm__("$16");

    switch (P86860State) {
    case ANIMATION_STATE_IDLE_LOOK_AROUND:
        if (func_80040994() == 0) {
            requestedState4 = 6;
            if (!(D_8006E53C & 0x40) && (requestedState4 = 7, ((P86860FieldB8 < 4) != 0)) && (P86860FieldE4 < 0x17) && (requestedState4 = 0xD, ((D_8006E538 & 0x80) == 0))) {
                magnitude2 = P86860FieldA8;
                if (magnitude2 < 0) {
                    magnitude2 = -magnitude2;
                }
                if (magnitude2 >= 0x11) {
                    requestedState4 = 1;
                    goto setAnimationState;
                }
                if ((D_8006E538 & 0xC) || (requestedState4 = 1, (P86860FieldAC == 0))) {
                    if ((D_8006E044 == 7) || (P86860Field240 != 0)) {
                        state16=&P86860State;
                        __asm__("" : "=r"(state16) : "0"(state16));
                        if (*state16 != ANIMATION_STATE_STAND) {
                            func_8004BEF8(0U);
                            if (P86860Table[*((unsigned char*)state16-0x2C)] >= 0x60U) {
                                spyro.bodyAnimation.id = spyro.bodyAnimation.nextId;
                                spyro.bodyAnimation.frame = spyro.bodyAnimation.nextFrame;
                            }
                            spyro.bodyAnimation.nextFrame = 0;
                            sampledState3=*state16;
                            __asm__("" : "=r"(sampledState3) : "0"(sampledState3) : "$2");
                            literal2=0x71;
                            *((unsigned char*)state16-0x2C) = literal2;
                            spyro.unk17q = 0;
                            spyro.bodyAnimation.nextId = (unsigned char) sampledState3;
                            spyro.unknownAnimationStateVariable = sampledState3;
                            return;
                        }
                    } else {
                        requestedState4 = 0xF;
                        if ((unsigned char) P86860FieldFC == 0) {
                            func_80049688((unsigned char *)0xF);
                            return;
                        }
                        goto setAnimationState;
                    }
                } else {
                    goto setAnimationState;
                }
            } else {
                goto setAnimationState;
            }
        } else {
            return;
        }
        break;
    case ANIMATION_STATE_WHIRLWIND:
        if (func_80040994() == 0) {
            if ((D_8006E344 != 0xD) || (requestedState4 = 0x11, (D_8006C514 == 0))) {
                if (P86860Field158 < func_8004F334(&spyro.position, &spyro.union144.a.unk13db)) {
                    requestedState4 = 0x11;
                    goto setAnimationState;
                }
            } else {
                goto setAnimationState;
            }
        }
        break;
    case ANIMATION_STATE_SINK:
        if (D_8006E53C & 0x40) {
            P86860Field1B6 = 1;
        }
        if (D_8006FA38 >= 0) {
            if (P86860Field144 > 0x8FFF) {
                P86860Field28C = -1;
                if (unk_ovlheader_80074374 != 0) {
                    unk_ovlheader_80074374();
                    return;
                }
                goto call498C0;
            }
        } else if (P86860Field280 < 0) {
            if (P86860Field144 > 0x8FFF) {
                P86860Field28C = -1;
call498C0:
                func_800498C0();
                return;
            }
        } else {
            if (P86860Field54 >= 0x3D) {
                P86860Field280 = -1;
                return;
            }
            if ((P86860Field54 >= 0x10) && ((unsigned char) P86860Field1B6 != 0)) {
                requestedState4 = 6;
                if (P86860Field28C >= 0) {
                    if (func_8003BF6C(P86860Field290, P86860Field28C) != 0) {
                        func_8003BE70(P86860Field28C);
                    }
                    P86860Field28C = -1;
                    requestedState4 = 6;
                }
                goto setAnimationState;
            }
        }
        break;
    }
    return;
setAnimationState:
    func_8004BEF8(requestedState4);
}

