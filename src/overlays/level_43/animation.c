#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_43/animation", func_level_43_80091058);

int Callback43First42A44(void) __asm__("func_80042A44");
/* AI generated; not human reviewed. SCUS-94467 80092B50..800930D0.
 * Baseline: verified level50_8009CF04 scalar state producers. Original43
 * supplies dispatch, helper/flag/clamp tails and signed division by1536.
 * Numeric pointer addition0x70 is a byte offset from player+0x28.
 * Empty constraints retain register lifetimes, including the otherwise unused
 * V0 result after case1A's call; no helper-return meaning is established.
 * Units, producer chains, invocation cadence and runtime parity remain open.
 * Acceptance: every original code/table word and every complete retail hash.
 */
extern int Callback43Step __asm__("D_80070328+0x144");
extern int Callback43Z __asm__("D_80070328+8");
extern int Callback43Limit __asm__("D_80070328+0x280");
extern Spyro Callback43Player __asm__("D_80070328");
int Callback43Call80037058(int x, int y) __asm__("func_80037058");
int Callback43Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback43Call80041930(void) __asm__("func_80041930");
void Callback43Call80041AE8(void) __asm__("func_80041AE8");
void Callback43Call80041C20(void) __asm__("func_80041C20");
void Callback43Call80042A44(void) __asm__("func_80042A44");
void Callback43Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback43Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38,D_8006C648;
int Callback43Query(Vector3D*,int) __asm__("func_8001A358");
int Callback43Length(Vector3D*, int) __asm__("func_8004EDE8");
void func_level_43_80092B50(void) {
    struct {Vector3D first; int reserved1C;} local;
    register int computedValue __asm__("$4");

    register int clampedValue __asm__("$4");
    register int positionDelta __asm__("$2");
    register int numerator __asm__("$2");
    register int belowLimit __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback43Player.animationState) {
    case 0x14:
    case 0x73:
    case 0x78:
    case 0x7A:
    case 0x7B:
    case 0x7C:
    case 0x7E:
        if (func_800438F4() == 0) {
            func_80043728();
        }
        Callback43Call80041C20();
        Callback43Player.unk9a = 0;
        Callback43First42A44();
        __asm__ volatile("" : : : "memory");
        goto clearSharedValue;
    default:
        return;
    case 0x1B:
    case 0x20:
    case 0x35:
    case 0x36:
    case 0x3C:
    case 0x80:
        Callback43Call80041C20();
        Callback43Call80042A44();
        goto clearSharedValue;
    case 0x1D:
    case 0x79:
        Callback43Call80041C20();
        Callback43Call80042A44();
        goto queryC00;
    case 0x1A:
        Callback43Call80041C20();
        {register int helperResult __asm__("$2")=Callback43First42A44();
        __asm__ volatile("" : : "r"(helperResult));}
        goto queryC00;
        case 0x81: {
            register int* zWord __asm__("$5")=&Callback43Z;
            register int velocity __asm__("$6")=Callback43Step;
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
            status=Callback43Limit;
            velocity+=tick;
            Callback43Step=velocity;
            __asm__("" : : : "memory");
            if(status>=0 && D_8006FA38<0)goto lowerLimit;
            {
                register int limit __asm__("$3")=0x9000;
                register int exceeded __asm__("$2");
                __asm__("" : "=r"(limit) : "0"(limit));
                exceeded=limit<velocity;
                if(exceeded)Callback43Step=limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2")=velocity<0x2581;
                if(!below)Callback43Step=0x2580;
            }
        limitsDone:
            Callback43Call80041C20();
            Callback43Call80042A44();
            func_8004F178(&local.first,&Callback43Player.position);
            local.first.z+=0x400;
            Callback43Player.unk4[0]=Callback43Query(&local.first,0xC00);
            positionDelta=(int)Callback43Player.union144.a.unk13cb;
            positionValue=Callback43Player.position.z;
            positionDelta >>= 6;
            goto storePosition;
        }
    case 0x2B:
    case 0x2C:
        Callback43Call80041C20();
        Callback43Call80042A44();
        Callback43Call80041AE8();
        if ((unsigned char) Callback43Player.unk10[4] != 0) {
            computedValue = -Callback43Player.unk9ha[4] - Callback43Call80037058(Callback43Player.position.x, Callback43Player.position.y);
            positionValue = Callback43Player.unk4a - computedValue;
            Callback43Player.unk4[0] = computedValue;
            positionDelta = (int) Callback43Player.union144.a.unk13cc >> 6;
            goto storePosition;
        }
        break;
storePosition:
        positionValue -= positionDelta;
        __asm__("" : "=r"(positionValue) : "0"(positionValue));
        Callback43Player.position.z=positionValue;
        return;
    case 0x2F:
        Callback43Call80041C20();
        Callback43Call80042A44();
        Callback43Call80041930();
        func_80042F64();
        goto clearSharedValue;
    case 0x31:
        Callback43Call80041C20();
        Callback43Call80042A44();
        Callback43Call80043A38(0xC00);
        if (func_80040954(Callback43Player.unk11[2]) == 0xA) {
            Callback43Player.union144.a.unk13cb = 0;
        } else {
            Callback43Player.union144.a.unk13cb += D_8006C648;
        }
        Callback43Player.unk4[0] = 0;
        if (Callback43Call8003BF6C((int) D_8006C654->unk32, Callback43Player.unk22[2]) == 0) {
            Callback43Player.unk22[2] = PlaySound((int) D_8006C654->unk32, 0, 4);
            Callback43Player.unk22[3] = (int) D_8006C654->unk32;
            return;
        }
        break;
    case 0x32:
        Callback43Call80041C20();
        Callback43Call80042A44();
        Callback43Call80041930();
        func_80042F64();
        numerator=(int)((unsigned int)Callback43Player.unk7a[3].z << 2);
        Callback43Player.unk4[0] = 0;
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
        Callback43Call80041C20();
        Callback43Call80042A44();
        Callback43Call80041930();
        func_80042F64();
        Callback43Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)(((unsigned int)Callback43Length((Vector3D *) ((unsigned char*)Callback43Player.unk4 + 0x70), 0) << 2) + 0x300U) / 1536;
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
    case 0x76:
    case 0x77:
        Callback43Call80041C20();
        Callback43Call80042A44();
        Callback43Call80041930();
        if (Callback43Player.unk5 != 0x7F) {
            if ((Callback43Player.unk7a[3].z < 0) && (Callback43Player.animationStateFrames >= 4)) {
                Callback43Player.unk5 = 1;
            } else {
                goto checkSecondFlag;
            }
        }
        goto clearSharedValue;
    case 0x82:
        if (Callback43Player.movementState != MOVEMENT_STATE_WALK) goto other82;
    case 0x74:
        case 0x75:
        case 0x83:
        case 0x84:
            func_800438F4();
            Callback43Call80041C20();
            Callback43Call80042A44();
            Callback43Call80041930();
queryC00:
            Callback43Call80043A38(0xC00);
            goto clearSharedValue;
other82:
        Callback43Call80041C20();
        Callback43Call80042A44();
        Callback43Call80041930();
        if ((Callback43Player.unk7a[3].z < 0) && (Callback43Player.animationStateFrames >= 4)) {
            Callback43Player.unk5 = 1;
        } else {
checkSecondFlag:
                if ((Callback43Player.unk5 == 0) && !(Callback43Word8006E538 & 0x40) && (Callback43Player.union144.a.unk13cb == 0)) {
                    Callback43Player.unk5 = 2;
                }
        }
clearSharedValue:
        Callback43Player.unk4[0]=0;
        return;
    }
}


#define LEVEL_ID 43
#define PlaySpyroSounds_level_43 func_level_43_800930D4
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_43_80093310(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x76:
    case 0x77:
        func_80043ABC(0);
        break;
    case 0x1b:
    case 0x3c:
        if (*(int*)((char*)&spyro + 0x50) != 6) func_80043ABC(0);
        break;
    case 0x2f:
    case 0x32:
    case 0x33:
    case 0x34:
        func_80043F3C(&spyro.unk9h);
        break;
    case 0x82:
        {
            register int* state __asm__("$4") = (int*)((char*)&spyro + 0xB8);
            __asm__("" : "=r"(state) : "0"(state));
            if (*state) func_80043ABC(0);
            else func_80043ABC(&spyro.unk9e);
        }
        break;
    case 0x14:
    case 0x1a:
    case 0x1d:
    case 0x20:
    case 0x2b:
    case 0x2c:
    case 0x31:
    case 0x35:
    case 0x36:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x78:
    case 0x79:
    case 0x7a:
    case 0x7b:
    case 0x7c:
    case 0x7e:
    case 0x80:
    case 0x81:
    case 0x83:
    case 0x84:
        func_80043ABC(&spyro.unk9e);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 800933D4.
 * Reuses newly verified33 ladder and special-state transitions, verified12
 * slide route and verified27 selector1A. Original43 supplies1D numeric words
 * 21C/220/224 to8C/90/94, signed shift6/fallbackA0 and stack10 vector route
 * with helper1A358(800), two particle callbacks and numeric table byte selectors.
 * Numeric pointer offsets are bytes. Access widths, shifts and conditions
 * follow original instructions. Empty constraints emit no instructions and
 * retain original source order, independent helper branches and saved selector
 * S0/walk flagS1. Reused semantic names do not establish meanings, units,
 * conversions, audio mappings or caller cadence. Acceptance requires every
 * original code/internal jump/owned dispatch word, strict complete translation
 * unit, complete EXE/every overlay hashes. Live runtime parity remains open.
 */
extern short Transition43SignedA[] __asm__("D_800658A0");
extern short Transition43SignedB[] __asm__("D_80065920");
extern int Transition43RawX __asm__("D_80070328+0x8C");
int Transition43_func_80040954(int) __asm__("func_80040954");
void Transition43_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");
extern int Transition43_D_8006E528 __asm__("D_8006E528");
int Transition43_func_8004E880(int,int,int) __asm__("func_8004E880");

extern Spyro Transition43_D_80070328 __asm__("D_80070328");
int Transition43_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
int Transition43_func_8003636C(int low, int high) __asm__("func_8003636C");
void Transition43_func_80043A38(int scale) __asm__("func_80043A38");
void Transition43_func_800441F0(void) __asm__("func_800441F0");
void Transition43_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition43_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition43RawUnion[] __asm__("D_80070328+0x144");
extern int Transition43RawMovement __asm__("D_80070328+0x50");
extern int Raw43Movement __asm__("D_80070328+0x50");
extern int Raw43Union __asm__("D_80070328+0x144");
void Call43ED6C(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
extern void (*Call43Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw43State[] __asm__("D_80070328+0x50");
extern Spyro Special43_D_80070328 __asm__("D_80070328");
extern short Signed43TableA[] __asm__("D_800658A0");
extern short Signed43TableB[] __asm__("D_80065920");
int Special43_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Special43_func_80043A38(int scale) __asm__("func_80043A38");
void Special43_func_800441F0(void) __asm__("func_800441F0");
void Special43_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Special43_D_8006E524 __asm__("D_8006E524");

int Call43EA2C(int) __asm__("func_8004EA2C");
int Call43E9E4(int) __asm__("func_8004E9E4");
extern int D_80071934;
int Call43A358(Vector3D*,int) __asm__("func_8001A358");
void func_level_43_800933D4(int arg0){
    Vector3D vector;
    register int oldMovementC __asm__("$5");
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");


    int lengthResult;

    register unsigned char* privateData __asm__("$16");

    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    register unsigned char *sourceBytesA __asm__("$16");

    register unsigned char* walkBase __asm__("$5");
    register int walkFlag __asm__("$17");
    register int groundValue __asm__("$2");
    switch(arg0){
    case 0x14:
        Transition43_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition43_D_80070328.unk5 = 0;
        Transition43_func_800441F0();
        Transition43_D_80070328.grounded = 1;
        Transition43_D_80070328.union144.a.unk13cb = Transition43_func_8003636C(1, 3);
        Transition43_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x1D: {
        register int oldState __asm__("$4")=Transition43RawMovement;
        register int first __asm__("$3")=Transition43_D_80070328.unk17e.x;
        register int second __asm__("$2");
        register int third __asm__("$3");
        __asm__("" : "=r"(oldState),"=r"(first) : "0"(oldState),"1"(first) : "memory");
        second=7;
        __asm__("" : "=r"(second) : "0"(second));
        Transition43RawMovement=second;
        __asm__ volatile("" : : : "memory");
        second=Transition43_D_80070328.unk17e.y;
        __asm__ volatile("" : "=r"(second) : "0"(second) : "memory");
        Transition43_D_80070328.unk5=0;
        __asm__ volatile("" : "=r"(first) : "0"(first) : "memory");
        first<<=6;
        __asm__("" : "=r"(first) : "0"(first));
        Transition43_D_80070328.unk7a[2].x=first;
        __asm__ volatile("" : : : "memory");
        third=Transition43_D_80070328.unk17e.z;
        second<<=6;
        Transition43_D_80070328.union144.a.unk13cb=oldState;
        Transition43_D_80070328.unk7a[2].y=second;
        second=third<<6;
        if(third==0)second=Transition43_D_80070328.unk7a[3].z;
        Transition43_D_80070328.unk7a[2].z=second;
        Transition43_func_80043A38(0xC00);
        Transition43_D_80070328.grounded=1;
        Transition43_D_8006E524=15;
        if(SpawnParticle)SpawnParticle(5,10,0,0);
        PlaySound((int)D_8006C654->spyroHurt,0,0);
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    }
    case 0x1A:
        savedBase = Transition43RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        oldMovementC = Transition43RawMovement;
        Transition43RawMovement = MOVEMENT_STATE_HURT;
        Transition43_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementC;
        Transition43_func_8004F168(destination);
        Transition43_D_80070328.grounded = 1;
        Transition43_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        PlaySound((int) D_8006C654->squish, 0, 0);
        goto clearPointers;
    case 0x20:
        Transition43_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition43_D_80070328.unk5 = 0;
        Transition43_func_80043A38(0xC00);
        Transition43_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition43_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x2B:case 0x2C: {
        register unsigned char* unionPointer __asm__("$16");
        {register int stateWord __asm__("$3")=Transition43RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition43RawUnion;
            *(int*)unionPointer=(-Transition43_D_80070328.unk7a[2].z)>>2;
            if(Transition43RawMovement!=8){Transition43_D_80070328.union144.a.unk13cc=0x5900;Transition43RawMovement=10;}
            Transition43_D_80070328.unk5=0;
            Transition43_D_80070328.unk8[0]=Transition43_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition43_D_80070328.grounded=1;
            Transition43_D_80070328.unk15b=1;
            func_8004F178(&vector,(Vector3D*)(unionPointer-0x144));
            vector.z+=0x400;
            lengthResult=Call43A358(&vector,0x800);
            vector.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,&vector,0);SpawnParticle(6,0x2E,&vector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x2F:
        savedBase=(unsigned char*)&Transition43RawMovement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition43_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            __asm__ volatile("" : : : "memory");
            goto groundAndClear;
        }
        goto clearPointers;
    case 0x31: {
        register unsigned char* lengthBase __asm__("$5")=(unsigned char*)&Transition43_D_80070328.unk8[0];
        register int valueA __asm__("$4");
        register int valueB __asm__("$5");
        register int valueKind __asm__("$6");
        *(int*)lengthBase=0;
        if(Transition43_D_80070328.animationState==0xD || Transition43_D_80070328.movementState==1)
            func_8004F178((Vector3D*)(lengthBase-0x30),(Vector3D*)(lengthBase-0x18));
        else Transition43_func_8004F168((Vector3D*)(lengthBase-0x30));
        func_8004F178(&Transition43_D_80070328.unk7a[2],(Vector3D*)((unsigned char*)&Transition43_D_80070328.unk7a[2]-0xC));
        Transition43_D_80070328.movementState=17;
        Transition43_D_80070328.unk5=0;
        Transition43_func_80043A38(0xC00);
        Transition43_D_80070328.grounded=0;
        Transition43_D_80070328.union144.a.unk13cb=0;
        valueKind=1;
        if(Transition43_D_80070328.unk9ha[0]>=11) {
            valueA=Transition43_D_80070328.unk9e.x;
            valueB=Transition43_D_80070328.unk9e.y;
        } else {
            valueA=Transition43_D_80070328.unk7a[3].x;
            valueB=valueA;
        }
        Transition43_D_80070328.union144.a.unk13cc=Transition43_func_8004E880(valueA,valueB,valueKind);
        goto clearPointers;
    }
    case 0x32:case 0x33:case 0x34:
        savedBase=(unsigned char*)&Transition43RawMovement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition43_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            goto groundAndClear;
        }
        goto clearPointers;
    case 0x35:case 0x36:
        Transition43_D_80070328.movementState=0;
        Transition43_D_80070328.unk5=0;
        Transition43_func_800441F0();
groundAndClear:
        Transition43_D_80070328.grounded=1;
clearPointers:
        Transition43_D_80070328.unk20a=0;
        Transition43_D_80070328.critterMobyPtr=0;
        return;
    case 0x1B:case 0x3C: {
        register unsigned char* state __asm__("$3")=(unsigned char*)&Transition43RawMovement;
        *(int*)state=18;
        Transition43_D_80070328.unk5=0;
        Transition43_D_80070328.unk8[0]=Transition43_func_8004EDE8((Vector3D*)(state+0x48),0);
        Transition43_D_80070328.grounded=1;
        Transition43_func_80043A38(0xC00);
        Transition43_D_80070328.unk4a=0x300;
        return;
    }
    case 0x73:
    case 0x78:
    case 0x7E:
        Special43_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Special43_D_80070328.unk5 = 0;
        Special43_func_800441F0();
        Special43_D_80070328.grounded = 1;
        return;
    case 0x74:
    case 0x75:
    case 0x83:
    case 0x84:
        walkBase=Raw43State;
        walkFlag=1;
        __asm__("" : "=r"(walkFlag) : "0"(walkFlag));
        *(int*)walkBase=walkFlag;
        if(arg0==0x57 && Special43_D_80070328.ticksSinceLastSurfaceTouch!=0) {
            __asm__ volatile("" : : : "memory");
            destination=(Vector3D*)(walkBase+0x3C);
            goto copyWalkVector;
        }
        goto clearWalkFlag;
    case 0x80:
        Special43_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Special43_D_80070328.unk5 = 0;
        Special43_func_80043A38(0xC00);
        Special43_D_80070328.grounded = 1;
        Special43_D_8006E524 = 0xF;
        return;
    case 0x81: {
        register int oldState __asm__("$3")=Raw43Movement;
        register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$8")=SpawnParticle;
        register int* stateWord __asm__("$2");
        register int value __asm__("$2");
        __asm__ volatile("" : "=r"(oldState), "=r"(callback) : "0"(oldState), "1"(callback) : "memory");
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Raw43Movement=value;
        value=1;
        __asm__("" : "=r"(value) : "0"(value));
        Special43_D_80070328.grounded=value;
        value=15;
        __asm__("" : "=r"(value) : "0"(value));
        Special43_D_8006E524=value;
        Special43_D_80070328.unk5=0;
        stateWord=&Raw43Union;
        __asm__("" : "=r"(stateWord) : "0"(stateWord));
        Special43_D_80070328.unk5=0;
        *stateWord=oldState;
        __asm__ volatile("" : : : "memory");
        *stateWord=0;
        if(callback)callback(5,10,0,0);
        Special43_D_80070328.unk22[2]=PlaySound((int)D_8006C654->drown,0,0);
        Special43_D_80070328.unk22[3]=(int)D_8006C654->drown;
        return;
    }
    case 0x79:
        Special43_D_80070328.movementState = MOVEMENT_STATE_HURT;
        Special43_D_80070328.unk5 = 0;
        if (Special43_D_80070328.unk22[5] >= 0) {
            tableOffsetOrValue = Special43_D_80070328.unk22[5] * 2;
            tableValueA = *(short*)((unsigned char*)Signed43TableB + tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            tableValueA >>= 1;
            Special43_D_80070328.unk7a[2].x = tableValueA;
            tableOffsetOrValue = *(short*)((unsigned char*)Signed43TableA + tableOffsetOrValue);
            Special43_D_80070328.unk7a[2].z = 0;
            __asm__ __volatile__("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Special43_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
        } else {
            Special43_func_8004F168((Vector3D *) ((unsigned char*)&Special43_D_80070328.movementState + 0x3C));
        }
        Special43_D_80070328.unk7a[2].z = 0x200;
        func_8004F178((Vector3D *) ((unsigned char*)&Special43_D_80070328.unk7a[2].z - 0x14), (Vector3D *) ((unsigned char*)&Special43_D_80070328.unk7a[2].z - 8));
        Special43_D_80070328.grounded = 1;
        Special43_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
    default:
        return;
    case 0x7A: {
        register unsigned char* privateData __asm__("$17")=Special43_D_80070328.critterMobyPtr->mobyTag;
        register unsigned char* state __asm__("$18")=Raw43State;
        register Vector3D* vector __asm__("$16");
        *(int*)state=0;
        Special43_D_80070328.unk5=0;
        vector=(Vector3D*)(privateData+0x64);
        Special43_func_800441F0();
        Special43_D_80070328.grounded=1;
        Special43_D_80070328.idle=0;
        Special43_D_80070328.unk15g=0;
        *(int*)(privateData+0x5C)=0x180;
        *(int*)(privateData+0x64)=0x1800;
        *(int*)(privateData+0x68)=0;
        *(int*)(privateData+0x6C)=0;
        Call43ED6C((Vector3D*)(state-0x20),vector,vector);
        func_8004F194(vector,vector,(Vector3D*)(state-0x50));
        Call43Header(Special43_D_80070328.critterMobyPtr);
        return;
    }
    case 0x7B:
        Special43_D_80070328.movementState=0;
        Special43_func_800441F0();
        groundValue=1;
        goto sharedGround;
    case 0x7C: {
        register unsigned char* privateData __asm__("$16")=Special43_D_80070328.critterMobyPtr->mobyTag;
        register unsigned char* child __asm__("$4");
        Special43_D_80070328.movementState=0;
        Special43_func_800441F0();
        Special43_D_80070328.grounded=1;
        Special43_D_80070328.idle=0;
        Special43_D_80070328.unk15g=0;
        child=*(unsigned char**)(privateData+0x78);
        if(child) {
            if(*(short*)(privateData+0x74)==0x22A)child[0x48]=0x50;
            else child[0x48]=1;
        }
        return;
    }
    case 0x76:
        stateBaseA = Raw43State;
        __asm__("" : "=r"(stateBaseA) : "0"(stateBaseA));
        destination = (Vector3D*)(stateBaseA + 0x3C);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceBytesA = stateBaseA + 0x48;
        *(int*)stateBaseA = 2;
        func_8004F178(destination, (Vector3D*)sourceBytesA);
        Special43_D_80070328.unk8[0] = Special43_func_8004EDE8((Vector3D *) sourceBytesA, 0);
        Special43_D_80070328.unk7a[2].z = 0xDC0;
        Special43_D_80070328.unk5 = 0;
        if(Special43_D_80070328.animationState==0x81)Special43_D_80070328.union144.a.unk13cb=1;
        else Special43_D_80070328.union144.a.unk13cb=0;
        Special43_D_80070328.grounded = 0;
        PlaySound((int) D_8006C654->jump, 0, 0);
        return;
    case 0x77: {
        register unsigned char* state __asm__("$6")=Raw43State;
        if(*(int*)state!=2) {
            *(int*)state=3;
            Special43_D_80070328.unk8[0]=Special43_func_8004EDE8((Vector3D*)(state+0x48),0);
            Special43_D_80070328.grounded=0;
            Special43_D_80070328.unk15b=1;
            goto clearTail;
        }
        return;
    }
    case 0x82: {
        walkBase=Raw43State;
        if(*(int*)walkBase!=2) {
            walkFlag=1;
            __asm__("" : "=r"(walkFlag) : "0"(walkFlag));
            *(int*)walkBase=walkFlag;
            if(arg0==0x57 && Special43_D_80070328.ticksSinceLastSurfaceTouch!=0) {
                destination=(Vector3D*)(walkBase+0x3C);
copyWalkVector:
                func_8004F178(destination,(Vector3D*)(walkBase+0x48));
                Special43_D_80070328.unk5=walkFlag;
            } else {
clearWalkFlag:
                Special43_D_80070328.unk5=0;
            }
            Special43_D_80070328.unk8[0]=Special43_func_8004EDE8((Vector3D*)((unsigned char*)&Special43_D_80070328.movementState+0x48),0);
            Special43_func_80043A38(0xC00);
            groundValue=1;
            __asm__("" : "=r"(groundValue) : "0"(groundValue));
            Special43_D_80070328.union144.a.unk13cb=0;
sharedGround:
            Special43_D_80070328.grounded=groundValue;
clearTail:
            Special43_D_80070328.idle=0;
            Special43_D_80070328.unk15g=0;
        }
        return;
    }
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_43/animation", func_level_43_80093DF4);
