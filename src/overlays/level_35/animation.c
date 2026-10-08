#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_35/animation", func_level_35_80088A0C);

/* AI generated; not human reviewed. SCUS-94467 8008A2EC..8008A804.
 * Baselines: verified level45_80087D60 particle loop and level17_80082B84
 * state30 scalar producers, adapted only to the original level35 instructions.
 * Two vector stack slots, byte offsets, signed shifts6/9 and numeric limits
 * retain original domains; helper meanings, units and cadence remain open.
 * Empty constraints preserve original register and memory lifetimes.
 * Acceptance requires all original linked words and complete retail hashes.
 */
extern int Callback35Step __asm__("D_80070328+0x144");
extern int Callback35Z __asm__("D_80070328+8");
extern int Callback35Limit __asm__("D_80070328+0x280");
extern Spyro Callback35Player __asm__("D_80070328");
int Callback35Call80037058(int x, int y) __asm__("func_80037058");
int Callback35Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback35Call80041930(void) __asm__("func_80041930");
void Callback35Call80041AE8(void) __asm__("func_80041AE8");
void Callback35Call80041C20(void) __asm__("func_80041C20");
void Callback35Call80042A44(void) __asm__("func_80042A44");
void Callback35Call80043A38(int scale) __asm__("func_80043A38");
void Callback35Call80049590(void) __asm__("func_80049590");
void Callback35Call8004F110(Vector3D*, int) __asm__("func_8004F110");
extern int Callback35Word8006E344 __asm__("D_8006E344");
extern int Callback35Word8006E52C __asm__("D_8006E52C");
extern int Callback35Word8006E530 __asm__("D_8006E530");
extern int Callback35Word8006E538 __asm__("D_8006E538");
extern short Callback35Count __asm__("D_80070328+0x148");
extern int D_8006FA38,D_8006C648;
int Callback35Query(Vector3D*,int) __asm__("func_8001A358");
void func_level_35_8008A2EC(void) {
    struct {Vector3D first; int reserved1C; Vector3D second; int reserved2C; int reserved[2];} local;
    register int* stateWord __asm__("$19")=&Callback35Player.animationState;
    register unsigned char* sourceBytes __asm__("$19");
    register Vector3D* vectorPointer __asm__("$17");
    register int iteration __asm__("$16");
    register int secondLimit __asm__("$18");
    register int sample __asm__("$2");
    register int height __asm__("$3");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    register char* (*particles)(int,int,Vector3D*,Vector3D*) __asm__("$8");
    int computedValue;
    switch(*stateWord) {
        case 0x35:
        case 0x36:
            Callback35Call80041C20();
            Callback35Call80042A44();
clearSharedValue:Callback35Player.unk4[0]=0;
return;
        case 25:
            Callback35Call80041C20();
            Callback35Call80042A44();
            Callback35Call80041930();
            Callback35Call80049590();
            if ((Callback35Player.movementState == MOVEMENT_STATE_SUPERCHARGE) && (SpawnParticle != 0)) {
                SpawnParticle(1, 9, 0, 0);
            }
            if ((Callback35Player.unk7a[3].z < 0) && (Callback35Player.animationStateFrames >= 4)) {
                Callback35Player.unk5 = 1;
            } else if ((Callback35Player.unk5 == 0) && !(Callback35Word8006E538 & 0x40)) {
                Callback35Player.unk5 = 2;
            }
            goto clearSharedValue;
        case 0x1E: {
            register int velocity __asm__("$5")=Callback35Step;
            register int positionValue __asm__("$2")=Callback35Z;
            register int tick __asm__("$3")=D_8006C648;
            register int increment __asm__("$4");
            register int status __asm__("$2");
            __asm__("" : "=r"(velocity) : "0"(velocity));
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            __asm__("" : "=r"(tick) : "0"(tick));
            increment=velocity>>6;
            __asm__("" : "=r"(increment) : "0"(increment));
            positionValue+=increment;
            __asm__("" : "=r"(tick) : "0"(tick), "r"(positionValue));
            tick<<=9;
            Callback35Z=positionValue;
            status=Callback35Limit;
            velocity+=tick;
            Callback35Step=velocity;
            __asm__("" : : : "memory");
            if(status>=0 && D_8006FA38<0)goto lowerLimit;
            {
                register int limit __asm__("$3")=0x9000;
                register int exceeded __asm__("$2");
                __asm__("" : "=r"(limit) : "0"(limit));
                exceeded=limit<velocity;
                if(exceeded)Callback35Step=limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2")=velocity<0x2581;
                if(!below)Callback35Step=0x2580;
            }
        limitsDone:
            Callback35Call80041C20();
            Callback35Call80042A44();
            func_8004F178(&local.first,&Callback35Player.position);
            local.first.z+=0x400;
            Callback35Player.unk4[0]=Callback35Query(&local.first,0xC00);
            sample=(int)Callback35Player.union144.a.unk13cb;
            height=Callback35Player.position.z;
            sample>>=6;
            goto storePosition;
        }
        case 0x21:
        case 0x22:
        case 0x23:
            Callback35Call80041C20();
            Callback35Call80042A44();
            Callback35Call80041930();
            if (SpawnParticle != 0) {
                if (Callback35Count == 0) goto clearSharedValue;
                secondLimit = 1;
                if (Callback35Count >= 2) {
                    secondLimit = 2;
                }
                iteration = 0;
                if (secondLimit != 0) {
                    vectorPointer=&local.second;
                    __asm__("" : "=r"(vectorPointer), "=r"(stateWord) : "0"(vectorPointer), "1"(stateWord));
                    sourceBytes=(unsigned char*)stateWord+0x50;
                    do {
                        func_8004F178(vectorPointer, (Vector3D *) sourceBytes);
                        Callback35Call8004F110(vectorPointer, 7);
                        iteration += 1;
                        sample=rand();
                        component=local.second.x;
                        sample &= 254;
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        local.second.x=component;
                        sample=rand();
                        component=local.second.y;
                        sample &= 254;
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        local.second.y=component;
                        sample=rand();
                        kind=1;
                        subtype=0x17;
                        position=sourceBytes - 0x98;
                        vector=vectorPointer;
                        __asm__("" : "=r"(kind), "=r"(subtype), "=r"(position), "=r"(vector) : "0"(kind), "1"(subtype), "2"(position), "3"(vector), "r"(sample) : "$3", "$8", "memory");
                        sample &=254;
                        __asm__("" : "=r"(sample) : "0"(sample) : "$3", "$8", "memory");
                        component=local.second.z;
                        __asm__("" : "=r"(component) : "0"(component) : "$8", "memory");
                        particles=SpawnParticle;
                        __asm__("" : "=r"(particles), "=r"(component) : "0"(particles), "1"(component));
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component));
                        local.second.z=component;
                        particles(kind,subtype,(Vector3D*)position,vector);
                    } while (iteration < secondLimit);
                }
            }
            goto clearSharedValue;
        case 0x2B:
        case 0x2C:
        case 0x37:
        Callback35Call80041C20();
        Callback35Call80042A44();
        Callback35Call80041AE8();
        if ((unsigned char) Callback35Player.unk10[4] != 0) {
            computedValue = -Callback35Player.unk9ha[4] - Callback35Call80037058(Callback35Player.position.x, Callback35Player.position.y);
            height=Callback35Player.unk4a-computedValue;
            Callback35Player.unk4[0]=computedValue;
            sample=(int)Callback35Player.union144.a.unk13cc >>6;
            goto storePosition;
        }

            return;
storePosition:height-=sample;
__asm__("" : "=r"(height) : "0"(height));
Callback35Player.position.z=height;
return;
        case 0x3D:
            Callback35Call80041C20();
            Callback35Call80042A44();
            Callback35Call80043A38(0xC00);
            Callback35Call80049590();
            if (SpawnParticle != 0) {
                SpawnParticle(1, 9, 0, 0);
            }
            Callback35Word8006E530 = 0x78;
            Callback35Player.unk4[0] = 0;
            Callback35Word8006E52C = 4;
            if ((Callback35Word8006E344 == 0) && (Callback35Call8003BF6C((int) D_8006C654->supercharge, Callback35Player.unk22[2]) == 0)) {
                Callback35Player.unk22[2] = PlaySound((int) D_8006C654->supercharge, 0, 4);
                Callback35Player.unk22[3] = (int) D_8006C654->supercharge;
            }

            return;
        case 0xA5:case 0xA6:case 0xA7:case 0xA8:case 0xA9:case 0xAA:case 0xAB:
            Callback35Call80041C20();
            Callback35Call80042A44();
            return;
        case 0xAC:Callback35Call80041C20();
        return;
        default:return;
    }
}


#define LEVEL_ID 35
#define PlaySpyroSounds_level_35 func_level_35_8008A808
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_level_35_8008A910(int index) {
    register int* state __asm__("$5");
    register int value __asm__("$3");
    register unsigned char* base __asm__("$2");
    register unsigned int offset __asm__("$4");
    offset = index * 16;
    __asm__("" : "=r"(offset) : "0"(offset) : "$2");
    base = D_8006E548;
    __asm__("" : "=r"(base) : "0"(base), "r"(offset) : "$5");
    state = &spyro.animationState;
    value = *state;
    __asm__("" : "=r"(value) : "0"(value) : "memory");
    offset = offset + (unsigned int)base;
    __asm__("" : "=r"(offset) : "0"(offset), "r"(value));
    D_8006C570 = (unsigned char*)offset;
    __asm__("" : : "r"(value) : "$2", "memory");
    if (value < 0x2D) {
        if (value >= 0x2B) goto vector;
        if (value == 0x1E) goto vector;
        if (value >= 0x1F) return;
        if (value == 0x19) goto other;
        return;
    } else {
        if (value == 0x3D) goto vector;
        if (value >= 0x3E) return;
        if (value >= 0x38) return;
        if (value < 0x35) return;
    }
vector:
    __asm__("" : : "r"(value));
    func_80043ABC(&spyro.unk9e);
    return;
other:
    func_80043E00((Vector3D*)((char*)state + 0x44));
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008A9C4.
 * Verified25 fly/surface/charge and23 drowning. Original35 independent35/36
 * dispatch, surface stack10, A5..AC state12 and A9 vector/C18 path retained.
 * Numeric offsets are bytes; clamp7FF/800/4B00/4B01 gives800/800/4B00/4B00
 * before later helpers. Every code/internal jump/owned word, complete TU and
 * all retail hashes required. Helpers, units, audio, cadence/live parity open.
 */
extern Spyro Transition35Player __asm__("D_80070328");
extern int D_80071934;
extern int Raw35Word __asm__("D_80070328+0x50");
extern unsigned char Raw35State[] __asm__("D_80070328+0x50");
extern unsigned char Raw35Union[] __asm__("D_80070328+0x144");
extern int Raw35Spit __asm__("D_80070328+0x170");
void Call35_8004F168(Vector3D*) __asm__("func_8004F168");
int Call35_8004EDE8(Vector3D*,int) __asm__("func_8004EDE8");
int Call35A358(Vector3D*,int) __asm__("func_8001A358");
void Call35_800441F0(void) __asm__("func_800441F0");
void Call35_80043A38(int) __asm__("func_80043A38");
void func_80047138(void);
extern int Transition35DamageTimer __asm__("D_8006E524");
void func_level_35_8008A9C4(int arg0) {
    Vector3D surfaceVector;
    int vectorLength,surfaceResult;
    unsigned char soundSelector;
    register unsigned char* stateBase __asm__("$3");
    register int* spitWord __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* soundTable __asm__("$3");
    register int originalZ __asm__("$2");
    switch(arg0){
    case 0x35:
        __asm__ volatile("" : : : "memory");
        goto standEntry;
    case 0x36:
standEntry:
        Transition35Player.movementState = MOVEMENT_STATE_STAND;
        Transition35Player.unk5 = 0;
        Call35_800441F0();
        Transition35Player.grounded = 1;
        goto clearPointers;

    case 0x19:
        soundZero=0;
        __asm__("" : "=r"(soundZero) : "0"(soundZero));
        soundTable=(unsigned char*)D_8006C654;
        __asm__("" : "=r"(soundTable) : "0"(soundTable));
        Transition35Player.movementState = MOVEMENT_STATE_SUPERCHARGE;
        Transition35Player.unk13a[0] = 0x60000;
        Transition35Player.unk5 = 0;
        Transition35Player.union144.a.unk13cb = 0;
        Transition35Player.grounded = 0;
        Transition35Player.unk15b = 1;
        soundSelector = soundTable[0x22];
playSharedSound:
        PlaySound((int) soundSelector, (Moby*)soundZero, 0);
        goto clearPointers;
    case 0x1E: {
        register int oldState __asm__("$3")=Raw35Word;
        register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$8")=SpawnParticle;
        register int* stateWord __asm__("$2");
        register int value __asm__("$2");
        __asm__ volatile("" : "=r"(oldState), "=r"(callback) : "0"(oldState), "1"(callback) : "memory");
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Raw35Word=value;
        value=1;
        __asm__("" : "=r"(value) : "0"(value));
        Transition35Player.grounded=value;
        value=15;
        __asm__("" : "=r"(value) : "0"(value));
        Transition35DamageTimer=value;
        stateWord=(int*)Raw35Union;
        __asm__("" : "=r"(stateWord) : "0"(stateWord));
        Transition35Player.unk5=0;
        *stateWord=oldState;
        __asm__ volatile("" : : : "memory");
        *stateWord=0;
        if(callback)callback(5,10,0,0);
        Transition35Player.unk22[2]=PlaySound((int)D_8006C654->drown,0,0);
        value=(int)D_8006C654->drown;
        __asm__ volatile("" : "=r"(value) : "0"(value) : "memory");
        Transition35Player.unk20a=0;
        Transition35Player.critterMobyPtr=0;
        Transition35Player.unk22[3]=value;
        return;
    }
    case 0x21:
    case 0x22:
    case 0x23: {
        register unsigned char* flyState __asm__("$17")=(unsigned char*)&Raw35Word;
        if(*(int*)flyState!=6) {
            *(int*)flyState=6;
            Transition35Player.unk5=0;
            Call35_8004F168((Vector3D*)(flyState+0x104));
            Transition35Player.union144.a.unk13db.y=0;
            vectorLength=Call35_8004EDE8((Vector3D*)(flyState+0x48),0);
            Transition35Player.unk8[0]=vectorLength;
            if(vectorLength<0x800)Transition35Player.unk8[0]=0x800;
            if(Transition35Player.unk8[0]>=0x4B01)Transition35Player.unk8[0]=0x4B00;
            Transition35Player.union144.a.unk13cb=0;
            Transition35Player.union144.b.unk148=0;
            Transition35Player.union144.a.unk13ce.x=0;
            Transition35Player.union144.a.unk13ce.y=0;
            Transition35Player.grounded=0;
            Transition35Player.unk15b=0;
        }
        if(arg0<0xA0)goto clearPointers;
        return;
    }
    case 0x2B:case 0x2C:{

        register unsigned char* unionPointer __asm__("$16");
        {register int stateWord __asm__("$3")=Raw35Word;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Raw35Union;
            *(int*)unionPointer=(-Transition35Player.unk7a[2].z)>>2;
            if(Raw35Word!=8){Transition35Player.union144.a.unk13cc=0x5900;Raw35Word=10;}
            Transition35Player.unk5=0;
            Transition35Player.unk8[0]=Call35_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition35Player.grounded=1;
            Transition35Player.unk15b=1;
            func_8004F178(&surfaceVector,(Vector3D*)(unionPointer-0x144));
            surfaceVector.z+=0x400;
            surfaceResult=Call35A358(&surfaceVector,0x800);
            surfaceVector.z=surfaceResult;
            if(surfaceResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,&surfaceVector,0);SpawnParticle(6,0x2E,&surfaceVector,0);}
        }
        }
        goto clearPointers;

    }

    case 0x37:
        originalZ=8;
        __asm__("" : "=r"(originalZ) : "0"(originalZ));
        Raw35Word=originalZ;
        __asm__ volatile("" : : : "memory");
        originalZ=Transition35Player.unk7a[2].z;
        __asm__("" : "=r"(originalZ) : "0"(originalZ));
        {register int flagValue __asm__("$3")=1;
        __asm__("" : "=r"(flagValue) : "0"(flagValue));
        Transition35Player.unk15b=flagValue;
        __asm__ volatile("" : : : "memory");}
        soundTable=(unsigned char*)D_8006C654;
        __asm__("" : "=r"(soundTable) : "0"(soundTable));
        Transition35Player.union144.a.unk13cc = 0;
        Transition35Player.unk5 = 0;
        Transition35Player.grounded = 0;
        __asm__ volatile("" : "=r"(originalZ) : "0"(originalZ) : "memory");
        Transition35Player.union144.a.unk13cb = -originalZ >> 2;
        soundSelector = soundTable[7];
        soundZero=0;
        goto playSharedSound;
    case 0x3D:
        stateBase=Raw35State;
        *(int*)stateBase = MOVEMENT_STATE_SUPERCHARGE;
        Transition35Player.unk5 = 0;
        Transition35Player.unk13a[0] = 0x60000;
        Transition35Player.unk8[0] = Call35_8004EDE8((Vector3D *) (stateBase + 0x48), 0);
        Transition35Player.horizontalSpeed = 0x1E80;
        Call35_80043A38(0xC00);
        Transition35Player.grounded = 1;
        if ((Transition35Player.unk13f[0] != 0) || (Transition35Player.spitState != 0) || (Transition35Player.unk17t != 6)) {
            spitWord=&Raw35Spit;
            if (((unsigned) (*spitWord - 3) < 2U) || (*spitWord == 5)) {
                *spitWord = 5;
            } else {
                *spitWord = 0;
            }
            Transition35Player.spitState = 0;
            Transition35Player.unk17t = 6;
            func_80047138();
        }
clearPointers:
        Transition35Player.unk20a=0;
        Transition35Player.critterMobyPtr=0;
        return;
    case 0xA5:case 0xA6:case 0xA7:case 0xA8:
    case 0xA9:case 0xAA:case 0xAB:case 0xAC: {
        register unsigned char* state __asm__("$17")=Raw35State;
        register Vector3D* vector __asm__("$16");
        if(*(int*)state!=18){
            *(int*)state=18;
            Transition35Player.unk5=0;
            Transition35Player.grounded=0;
            Transition35Player.unk15b=0;
            Call35_8004F168((Vector3D*)(state+0x30));
            Call35_8004F168((Vector3D*)(state+0x3C));
            return;
        }
        if(arg0==0xA9){
            {register Vector3D* destination __asm__("$4")=(Vector3D*)(state+0x3C);
            __asm__("" : "=r"(destination) : "0"(destination));
            vector=(Vector3D*)(state+0x48);
            func_8004F178(destination,vector);}
            Transition35Player.unk8[0]=Call35_8004EDE8(vector,0);
            Transition35Player.unk7a[2].z=0xC18;
        }
        return;
    }
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_35/animation", func_level_35_8008AF8C);
