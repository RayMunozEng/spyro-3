#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_33/animation", func_level_33_800990E0);

/* AI generated; not human reviewed. SCUS-94467 8009AFA8..8009B594.
 * Baselines: linked-byte-verified 43_80092B50 scalar/clamp and 50_8009CF04
 * particle loop. Original33 supplies selector scope and numeric memory accesses.
 * Source +0x28+0x70, +0x148-0xB0 and -0x98 are byte offsets.
 * Original33 8009B278..8009B288 masks V0, loads the third component,
 * then computes A2 in its load delay; the empty memory boundary preserves this.
 * Empty lifetime constraints emit no instructions; helper meanings, units and
 * invocation cadence remain unresolved. Acceptance requires every original
 * code/table word, strict full translation unit and all EXE/overlay hashes.
 */
extern int Callback33Step __asm__("D_80070328+0x144");
extern int Callback33Z __asm__("D_80070328+8");
extern int Callback33Limit __asm__("D_80070328+0x280");
extern Spyro Callback33Player __asm__("D_80070328");
void Callback33Call80041930(void) __asm__("func_80041930");
void Callback33Call80041C20(void) __asm__("func_80041C20");
void Callback33Call80042A44(void) __asm__("func_80042A44");
void Callback33Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback33Word8006E538 __asm__("D_8006E538");
extern int D_8006FA38,D_8006C648;
int Callback33Query(Vector3D*,int) __asm__("func_8001A358");
int Callback33Length(Vector3D*, int) __asm__("func_8004EDE8");
void Callback33Call8004F110(Vector3D*, int) __asm__("func_8004F110");
extern short Callback33Count __asm__("D_80070328+0x148");
void func_level_33_8009AFA8(void) {
    struct {Vector3D first; int reserved1C; Vector3D second; int reserved2C; int reserved[2];} local;
    register unsigned char* countBase __asm__("$5");
    register unsigned char* sourceBytes __asm__("$19");
    register Vector3D* vectorPointer __asm__("$17");
    register int* descriptor __asm__("$16");
    register int iteration __asm__("$16");
    register int secondLimit __asm__("$18");
    register int sample __asm__("$2");
    register int height __asm__("$3");
    register int component __asm__("$3");
    register int kind __asm__("$4");
    register int subtype __asm__("$5");
    register unsigned char* position __asm__("$6");
    register Vector3D* vector __asm__("$7");
    register char* (*particles)(int,int,Vector3D*,Vector3D*) __asm__("$2");


    register int clampedValue __asm__("$4");
    register int positionDelta __asm__("$2");
    register int numerator __asm__("$2");
    register int belowLimit __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback33Player.animationState) {
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
        Callback33Call80041C20();
        Callback33Player.unk9a = 0;
        Callback33Call80042A44();
        goto clearSharedValue;
    default:
        return;
    case 0x35:
    case 0x36:
    case 0x80:
        Callback33Call80041C20();
        Callback33Call80042A44();
        goto clearSharedValue;
    case 0x79:
        Callback33Call80041C20();
        Callback33Call80042A44();
        goto queryC00;
    case 0x13:
    case 0x15:
        Callback33Call80041C20();
        Callback33Call80042A44();
        Callback33Call80041930();
        goto clearSharedValue;
    case 0x1C:
        Callback33Call80041C20();
        Callback33Call80042A44();
        Callback33Call80041930();
        if (Callback33Player.unk7a[3].z < 0 && Callback33Player.animationStateFrames >= 4)
            Callback33Player.unk5=1;
        goto clearSharedValue;
        case 0x81: {
            register int* zWord __asm__("$5")=&Callback33Z;
            register int velocity __asm__("$6")=Callback33Step;
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
            status=Callback33Limit;
            velocity+=tick;
            Callback33Step=velocity;
            __asm__("" : : : "memory");
            if(status>=0 && D_8006FA38<0)goto lowerLimit;
            {
                register int limit __asm__("$3")=0x9000;
                register int exceeded __asm__("$2");
                __asm__("" : "=r"(limit) : "0"(limit));
                exceeded=limit<velocity;
                if(exceeded)Callback33Step=limit;
            }
            goto limitsDone;
        lowerLimit:
            {
                register int below __asm__("$2")=velocity<0x2581;
                if(!below)Callback33Step=0x2580;
            }
        limitsDone:
            Callback33Call80041C20();
            Callback33Call80042A44();
            func_8004F178(&local.first,&Callback33Player.position);
            local.first.z+=0x400;
            Callback33Player.unk4[0]=Callback33Query(&local.first,0xC00);
            positionDelta=(int)Callback33Player.union144.a.unk13cb;
            positionValue=Callback33Player.position.z;
            positionDelta >>= 6;
            positionValue -= positionDelta;
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            Callback33Player.position.z=positionValue;
            return;
        }
        case 0x21:
        case 0x22:
        case 0x23:
            Callback33Call80041C20();
            Callback33Call80042A44();
            Callback33Call80041930();
            if (SpawnParticle != 0) {
                countBase=(unsigned char*)&Callback33Count;
                if (*(short*)countBase == 0) goto clearSharedValue;
                secondLimit = 1;
                if (*(short*)countBase >= 2) {
                    secondLimit = 2;
                }
                iteration = 0;
                if (secondLimit != 0) {
                    vectorPointer=&local.second;
                    __asm__("" : "=r"(vectorPointer), "=r"(countBase) : "0"(vectorPointer), "1"(countBase));
                    sourceBytes=countBase-0xB0;
                    do {
                        func_8004F178(vectorPointer, (Vector3D *) sourceBytes);
                        Callback33Call8004F110(vectorPointer, 7);
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
                        __asm__("" : "=r"(kind), "=r"(subtype), "=r"(sample) : "0"(kind), "1"(subtype), "2"(sample) : "memory");
                        sample &=254;
                        component=local.second.z;
                        __asm__ volatile("" : : : "memory");
                        position=sourceBytes - 0x98;
                        __asm__("" : "=r"(position) : "0"(position), "r"(sample));
                        component -=127;
                        component +=sample;
                        __asm__("" : "=r"(component) : "0"(component) : "$2", "memory");
                        particles=SpawnParticle;
                        __asm__ volatile("" : "=r"(particles) : "0"(particles) : "$7");
                        vector=vectorPointer;
                        __asm__("" : "=r"(particles), "=r"(vector), "=r"(component) : "0"(particles), "1"(vector), "2"(component));
                        local.second.z=component;
                        particles(kind,subtype,(Vector3D*)position,vector);
                    } while (iteration < secondLimit);
                }
            }
            goto clearSharedValue;
    case 0x2F:
        Callback33Call80041C20();
        Callback33Call80042A44();
        Callback33Call80041930();
        func_80042F64();
        goto clearSharedValue;
    case 0x32:
        Callback33Call80041C20();
        Callback33Call80042A44();
        Callback33Call80041930();
        func_80042F64();
        numerator=(int)((unsigned int)Callback33Player.unk7a[3].z << 2);
        Callback33Player.unk4[0] = 0;
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
        Callback33Call80041C20();
        Callback33Call80042A44();
        Callback33Call80041930();
        func_80042F64();
        Callback33Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)(((unsigned int)Callback33Length((Vector3D *) ((unsigned char*)Callback33Player.unk4 + 0x70), 0) << 2) + 0x300U) / 1536;
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
    case 0x3A:
        Callback33Call80041C20();
        Callback33Call80042A44();
        Callback33Player.cheatColour.a=0xFF;
        Callback33Player.unk4[0]=0;
        Callback33Player.cheatColour.b=0x20;
        Callback33Player.cheatColour.g=0x20;
        Callback33Player.cheatColour.r=0x20;
        return;
    case 0x76:
    case 0x77:
        Callback33Call80041C20();
        Callback33Call80042A44();
        Callback33Call80041930();
        if (Callback33Player.unk5 != 0x7F) {
            if ((Callback33Player.unk7a[3].z < 0) && (Callback33Player.animationStateFrames >= 4)) {
                Callback33Player.unk5 = 1;
            } else {
                goto checkSecondFlag;
            }
        }
        goto clearSharedValue;
    case 0x82:
        if (Callback33Player.movementState != MOVEMENT_STATE_WALK) goto other82;
    case 0x74:
        case 0x75:
        case 0x83:
        case 0x84:
            func_800438F4();
            Callback33Call80041C20();
            Callback33Call80042A44();
            Callback33Call80041930();
queryC00:
            Callback33Call80043A38(0xC00);
            goto clearSharedValue;
other82:
        Callback33Call80041C20();
        Callback33Call80042A44();
        Callback33Call80041930();
        if ((Callback33Player.unk7a[3].z < 0) && (Callback33Player.animationStateFrames >= 4)) {
            Callback33Player.unk5 = 1;
        } else {
checkSecondFlag:
                if ((Callback33Player.unk5 == 0) && !(Callback33Word8006E538 & 0x40) && (Callback33Player.union144.a.unk13cb == 0)) {
                    Callback33Player.unk5 = 2;
                }
        }
clearSharedValue:
        Callback33Player.unk4[0]=0;
        return;
    }
}


#define LEVEL_ID 33
#define PlaySpyroSounds_level_33 func_level_33_8009B598
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043E00(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_33_8009B800(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x13:
    case 0x15:
    case 0x1c:
    case 0x76:
    case 0x77:
        func_80043ABC(0);
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
    case 0x35:
    case 0x36:
    case 0x3a:
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

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8009B8A8.
 * Reuses verified12 transition/private0/4/8 and46 special-state producers.
 * Original33 supplies15 numeric flags490/shift6/trig signed shifts12 and
 * independent2F/32/33/34 ladder routes and35/36 shared grounded/pointer tail.
 * All numeric pointer offsets are bytes. Height signed shifts10, yaw maskFFF,
 * length clamp800/4B00, signed trig table halfwords/shift1, private5C/64/68/6C
 * and74/78 child48 chain retain the original instructions and access widths.
 * Empty register/memory constraints retain original independent branch blocks
 * and scheduling; they emit no instructions. Existing names do not establish
 * helper meanings, source units, audio semantics, or caller/update cadence.
 * Confidence is exact compiled code/data only. Falsifiable acceptance vectors:
 * every original code/local jump/owned table word, strict complete translation
 * unit, and complete EXE/every original overlay hashes. Runtime parity remains
 * unverified; this change does not modify the browser implementation.
 */
extern short Transition33SignedA[] __asm__("D_800658A0");
extern short Transition33SignedB[] __asm__("D_80065920");
extern int Transition33RawX __asm__("D_80070328+0x8C");
int Transition33_func_80040954(int) __asm__("func_80040954");
void Transition33_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");
extern int Transition33_D_8006E528 __asm__("D_8006E528");
int Transition33_func_8004E880(int,int,int) __asm__("func_8004E880");

extern Spyro Transition33_D_80070328 __asm__("D_80070328");
int Transition33_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
int Transition33_func_8003636C(int low, int high) __asm__("func_8003636C");
void Transition33_func_80043A38(int scale) __asm__("func_80043A38");
void Transition33_func_800441F0(void) __asm__("func_800441F0");
void Transition33_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Transition33_D_8006E524 __asm__("D_8006E524");
extern unsigned char Transition33RawUnion[] __asm__("D_80070328+0x144");
extern int Transition33RawMovement __asm__("D_80070328+0x50");
extern int Raw33Movement __asm__("D_80070328+0x50");
extern int Raw33Union __asm__("D_80070328+0x144");
void Call33ED6C(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
extern void (*Call33Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw33State[] __asm__("D_80070328+0x50");
extern Spyro Special33_D_80070328 __asm__("D_80070328");
extern short Signed33TableA[] __asm__("D_800658A0");
extern short Signed33TableB[] __asm__("D_80065920");
int Special33_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Special33_func_80043A38(int scale) __asm__("func_80043A38");
void Special33_func_800441F0(void) __asm__("func_800441F0");
void Special33_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern int Special33_D_8006E524 __asm__("D_8006E524");

int Call33EA2C(int) __asm__("func_8004EA2C");
int Call33E9E4(int) __asm__("func_8004E9E4");
void func_level_33_8009B8A8(int arg0){
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");


    int lengthResult;

    int shiftedValue;
    int maskedValue;
    register unsigned char* privateData __asm__("$16");

    register unsigned char* stateBase __asm__("$17");
    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* stateBaseA __asm__("$3");
    register unsigned char *sourceBytesA __asm__("$16");

    register unsigned char* walkBase __asm__("$5");
    register int walkFlag __asm__("$16");
    register int groundValue __asm__("$2");
    switch(arg0){
    case 0x14:
        Transition33_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition33_D_80070328.unk5 = 0;
        Transition33_func_800441F0();
        Transition33_D_80070328.grounded = 1;
        Transition33_D_80070328.union144.a.unk13cb = Transition33_func_8003636C(1, 3);
        Transition33_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0x13: {
        register Moby* sourceMoby __asm__("$6");
        register int yawValue __asm__("$5");
        register int positionZ __asm__("$2");
        register int heightValue __asm__("$3");
        register int privateValue __asm__("$4");
        stateBase=(unsigned char*)&Transition33RawMovement;
        privateData = Transition33_D_80070328.m_WhirlwindPointer->mobyTag;
        *(int*)stateBase=14;
        Transition33_D_80070328.unk5 = 0;
        Transition33_D_80070328.grounded = 0;
        Transition33_func_8004F168((Vector3D *) (stateBase + 0x3C));
        sourceMoby=Transition33_D_80070328.m_WhirlwindPointer;
        yawValue=Transition33_D_80070328.rotation.yaw;
        positionZ=Transition33_D_80070328.position.z;
        heightValue=sourceMoby->position.z;
        privateValue=*(int*)privateData;
        __asm__("" : "=r"(sourceMoby), "=r"(yawValue), "=r"(positionZ), "=r"(heightValue) : "0"(sourceMoby), "1"(yawValue), "2"(positionZ), "3"(heightValue));
        Transition33_D_80070328.union144.a.unk13cc=yawValue;
        Transition33_D_80070328.union144.a.unk13cb=positionZ;
        __asm__ volatile("" : : : "memory");
        heightValue+=privateValue;
        Transition33_D_80070328.union144.a.unk13ce.x=heightValue;
        heightValue-=positionZ;
        heightValue-=0x800;
        Transition33_D_80070328.union144.a.unk13ce.z=heightValue;
        __asm__ volatile("" : : : "memory");
        heightValue = ((int) (heightValue << 0xA) >> 0xA) + 0x400;
        __asm__("" : "=r"(heightValue) : "0"(heightValue));
        Transition33_D_80070328.union144.a.unk13ce.y = heightValue;
        maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - heightValue) & 0xFFF;
        Transition33_D_80070328.union144.a.unk13ce.y = maskedValue;
        if (maskedValue >= 0x801) {
            Transition33_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
        }
        Transition33_D_80070328.union144.a.unk13da = *(int*)(privateData+4);
        func_8004F178((Vector3D *) (stateBase + 0x10C), &sourceMoby->position);
        Transition33_D_80070328.unk13e[0] = (int) Transition33_D_80070328.m_WhirlwindPointer->angle.yaw;
        positionZ=*(int*)(privateData+8);
        __asm__ volatile("" : "=r"(positionZ) : "0"(positionZ) : "memory");
        Transition33_D_80070328.unk20a = 0;
        Transition33_D_80070328.critterMobyPtr = 0;
        Transition33_D_80070328.unk13e[1] = positionZ;
        return;
    }
    case 0x15:
        Transition33_D_80070328.movementState=7;
        Transition33_D_80070328.grounded=0;
        Transition33_D_80070328.unk5=0;
        if(Transition33_D_80070328.unk17a&0x490){
            Transition33_D_80070328.unk7a[2].x=Transition33_D_80070328.unk17e.x<<6;
            Transition33_D_80070328.unk7a[2].y=Transition33_D_80070328.unk17e.y<<6;
            Transition33_D_80070328.unk7a[2].z=Transition33_D_80070328.unk17e.z<<6;
        }else{
            shiftedValue=Transition33_func_8004E880(-Transition33_D_80070328.unk7a[2].x,-Transition33_D_80070328.unk7a[2].y,1);
            Transition33_D_80070328.unk7b=shiftedValue;
            Transition33_D_80070328.unk7a[2].x=(Call33EA2C(shiftedValue)<<12)>>12;
            Transition33_D_80070328.unk7a[2].y=(Call33E9E4(Transition33_D_80070328.unk7b)<<12)>>12;
            Transition33_D_80070328.unk7a[2].z=0x1000;
        }
        goto clearPointers;
    case 0x1C:
        savedBase = Transition33RawUnion;
        __asm__("" : "=r"(savedBase) : "0"(savedBase));
        destination = (Vector3D*)(savedBase - 0xB8);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceC = (Vector3D*)(savedBase - 0xAC);
        oldMovementD = Transition33RawMovement;
        Transition33RawMovement = MOVEMENT_STATE_HURT;
        Transition33_D_80070328.unk5 = 0;
        *(int*)savedBase = oldMovementD;
        func_8004F178(destination, sourceC);
        Transition33_D_80070328.unk8[0] = Transition33_func_8004EDE8(sourceC, 0);
        Transition33_D_80070328.unk7a[2].z = 0xDC0;
        Transition33_D_80070328.grounded = 0;
        Transition33_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
        }
        if (Transition33_D_80070328.damageFlags & 0x200) {
            Transition33_D_80070328.union144.a.unk13cc = 0;
        } else {
            Transition33_D_80070328.union144.a.unk13cc = 1;
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        goto clearPointers;
    case 0x3A:
        Transition33_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition33_D_80070328.unk5 = 0;
        Transition33_func_80043A38(0xC00);
        Transition33_D_80070328.grounded = 1;
        if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
            PlaySound((int) D_8006C654->lavaBurn, 0, 0);
        }
        Transition33_D_8006E524 = 0xF;
        goto clearPointers;
    case 0x21:
    case 0x22:
    case 0x23: {
        register unsigned char* flyState __asm__("$16")=(unsigned char*)&Transition33RawMovement;
        if(*(int*)flyState!=6) {
            *(int*)flyState=6;
            Transition33_D_80070328.unk5=0;
            Transition33_func_8004F168((Vector3D*)(flyState+0x104));
            Transition33_D_80070328.union144.a.unk13db.y=0;
            lengthResult=Transition33_func_8004EDE8((Vector3D*)(flyState+0x48),0);
            Transition33_D_80070328.unk8[0]=lengthResult;
            if(lengthResult<0x800)Transition33_D_80070328.unk8[0]=0x800;
            if(Transition33_D_80070328.unk8[0]>=0x4B01)Transition33_D_80070328.unk8[0]=0x4B00;
            Transition33_D_80070328.union144.a.unk13cb=0;
            Transition33_D_80070328.union144.b.unk148=0;
            Transition33_D_80070328.union144.a.unk13ce.x=0;
            Transition33_D_80070328.union144.a.unk13ce.y=0;
            Transition33_D_80070328.grounded=0;
            Transition33_D_80070328.unk15b=0;
        }
        if(arg0<0xA0)goto clearPointers;
        return;
    }
    case 0x2F:
        savedBase=(unsigned char*)&Transition33RawMovement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition33_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            __asm__ volatile("" : : : "memory");
            goto groundAndClear;
        }
        goto clearPointers;
    case 0x32:case 0x33:case 0x34:
        savedBase=(unsigned char*)&Transition33RawMovement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition33_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            goto groundAndClear;
        }
        goto clearPointers;
    case 0x35:case 0x36:
        Transition33_D_80070328.movementState=0;
        Transition33_D_80070328.unk5=0;
        Transition33_func_800441F0();
groundAndClear:
        Transition33_D_80070328.grounded=1;
clearPointers:
        Transition33_D_80070328.unk20a=0;
        Transition33_D_80070328.critterMobyPtr=0;
        return;
    case 0x73:
    case 0x78:
    case 0x7E:
        Special33_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Special33_D_80070328.unk5 = 0;
        Special33_func_800441F0();
        Special33_D_80070328.grounded = 1;
        return;
    case 0x74:
    case 0x75:
    case 0x83:
    case 0x84:
        walkBase=Raw33State;
        walkFlag=1;
        __asm__("" : "=r"(walkFlag) : "0"(walkFlag));
        *(int*)walkBase=walkFlag;
        if(arg0==0x57 && Special33_D_80070328.ticksSinceLastSurfaceTouch!=0) {
            __asm__ volatile("" : : : "memory");
            destination=(Vector3D*)(walkBase+0x3C);
            goto copyWalkVector;
        }
        goto clearWalkFlag;
    case 0x80:
        Special33_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Special33_D_80070328.unk5 = 0;
        Special33_func_80043A38(0xC00);
        Special33_D_80070328.grounded = 1;
        Special33_D_8006E524 = 0xF;
        return;
    case 0x81: {
        register int oldState __asm__("$3")=Raw33Movement;
        register void (*callback)(int,int,Vector3D*,Vector3D*) __asm__("$8")=SpawnParticle;
        register int* stateWord __asm__("$2");
        register int value __asm__("$2");
        __asm__ volatile("" : "=r"(oldState), "=r"(callback) : "0"(oldState), "1"(callback) : "memory");
        value=7;
        __asm__("" : "=r"(value) : "0"(value));
        Raw33Movement=value;
        value=1;
        __asm__("" : "=r"(value) : "0"(value));
        Special33_D_80070328.grounded=value;
        value=15;
        __asm__("" : "=r"(value) : "0"(value));
        Special33_D_8006E524=value;
        Special33_D_80070328.unk5=0;
        stateWord=&Raw33Union;
        __asm__("" : "=r"(stateWord) : "0"(stateWord));
        Special33_D_80070328.unk5=0;
        *stateWord=oldState;
        __asm__ volatile("" : : : "memory");
        *stateWord=0;
        if(callback)callback(5,10,0,0);
        Special33_D_80070328.unk22[2]=PlaySound((int)D_8006C654->drown,0,0);
        Special33_D_80070328.unk22[3]=(int)D_8006C654->drown;
        return;
    }
    case 0x79:
        Special33_D_80070328.movementState = MOVEMENT_STATE_HURT;
        Special33_D_80070328.unk5 = 0;
        if (Special33_D_80070328.unk22[5] >= 0) {
            tableOffsetOrValue = Special33_D_80070328.unk22[5] * 2;
            tableValueA = *(short*)((unsigned char*)Signed33TableB + tableOffsetOrValue);
            __asm__("" : "=r"(tableValueA) : "0"(tableValueA));
            tableValueA >>= 1;
            Special33_D_80070328.unk7a[2].x = tableValueA;
            tableOffsetOrValue = *(short*)((unsigned char*)Signed33TableA + tableOffsetOrValue);
            Special33_D_80070328.unk7a[2].z = 0;
            __asm__ __volatile__("" : "=r"(tableOffsetOrValue) : "0"(tableOffsetOrValue) : "memory");
            Special33_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
        } else {
            Special33_func_8004F168((Vector3D *) ((unsigned char*)&Special33_D_80070328.movementState + 0x3C));
        }
        Special33_D_80070328.unk7a[2].z = 0x200;
        func_8004F178((Vector3D *) ((unsigned char*)&Special33_D_80070328.unk7a[2].z - 0x14), (Vector3D *) ((unsigned char*)&Special33_D_80070328.unk7a[2].z - 8));
        Special33_D_80070328.grounded = 1;
        Special33_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
    default:
        return;
    case 0x7A: {
        register unsigned char* privateData __asm__("$17")=Special33_D_80070328.critterMobyPtr->mobyTag;
        register unsigned char* state __asm__("$18")=Raw33State;
        register Vector3D* vector __asm__("$16");
        *(int*)state=0;
        Special33_D_80070328.unk5=0;
        vector=(Vector3D*)(privateData+0x64);
        Special33_func_800441F0();
        Special33_D_80070328.grounded=1;
        Special33_D_80070328.idle=0;
        Special33_D_80070328.unk15g=0;
        *(int*)(privateData+0x5C)=0x180;
        *(int*)(privateData+0x64)=0x1800;
        *(int*)(privateData+0x68)=0;
        *(int*)(privateData+0x6C)=0;
        Call33ED6C((Vector3D*)(state-0x20),vector,vector);
        func_8004F194(vector,vector,(Vector3D*)(state-0x50));
        Call33Header(Special33_D_80070328.critterMobyPtr);
        return;
    }
    case 0x7B:
        Special33_D_80070328.movementState=0;
        Special33_func_800441F0();
        groundValue=1;
        goto sharedGround;
    case 0x7C: {
        register unsigned char* privateData __asm__("$16")=Special33_D_80070328.critterMobyPtr->mobyTag;
        register unsigned char* child __asm__("$4");
        Special33_D_80070328.movementState=0;
        Special33_func_800441F0();
        Special33_D_80070328.grounded=1;
        Special33_D_80070328.idle=0;
        Special33_D_80070328.unk15g=0;
        child=*(unsigned char**)(privateData+0x78);
        if(child) {
            if(*(short*)(privateData+0x74)==0x22A)child[0x48]=0x50;
            else child[0x48]=1;
        }
        return;
    }
    case 0x76:
        stateBaseA = Raw33State;
        __asm__("" : "=r"(stateBaseA) : "0"(stateBaseA));
        destination = (Vector3D*)(stateBaseA + 0x3C);
        __asm__("" : "=r"(destination) : "0"(destination));
        sourceBytesA = stateBaseA + 0x48;
        *(int*)stateBaseA = 2;
        func_8004F178(destination, (Vector3D*)sourceBytesA);
        Special33_D_80070328.unk8[0] = Special33_func_8004EDE8((Vector3D *) sourceBytesA, 0);
        Special33_D_80070328.unk7a[2].z = 0xDC0;
        Special33_D_80070328.unk5 = 0;
        if(Special33_D_80070328.animationState==0x81)Special33_D_80070328.union144.a.unk13cb=1;
        else Special33_D_80070328.union144.a.unk13cb=0;
        Special33_D_80070328.grounded = 0;
        PlaySound((int) D_8006C654->jump, 0, 0);
        return;
    case 0x77: {
        register unsigned char* state __asm__("$6")=Raw33State;
        if(*(int*)state!=2) {
            *(int*)state=3;
            Special33_D_80070328.unk8[0]=Special33_func_8004EDE8((Vector3D*)(state+0x48),0);
            Special33_D_80070328.grounded=0;
            Special33_D_80070328.unk15b=1;
            goto clearTail;
        }
        return;
    }
    case 0x82: {
        walkBase=Raw33State;
        if(*(int*)walkBase!=2) {
            walkFlag=1;
            __asm__("" : "=r"(walkFlag) : "0"(walkFlag));
            *(int*)walkBase=walkFlag;
            if(arg0==0x57 && Special33_D_80070328.ticksSinceLastSurfaceTouch!=0) {
                destination=(Vector3D*)(walkBase+0x3C);
copyWalkVector:
                func_8004F178(destination,(Vector3D*)(walkBase+0x48));
                Special33_D_80070328.unk5=walkFlag;
            } else {
clearWalkFlag:
                Special33_D_80070328.unk5=0;
            }
            Special33_D_80070328.unk8[0]=Special33_func_8004EDE8((Vector3D*)((unsigned char*)&Special33_D_80070328.movementState+0x48),0);
            Special33_func_80043A38(0xC00);
            groundValue=1;
            __asm__("" : "=r"(groundValue) : "0"(groundValue));
            Special33_D_80070328.union144.a.unk13cb=0;
sharedGround:
            Special33_D_80070328.grounded=groundValue;
clearTail:
            Special33_D_80070328.idle=0;
            Special33_D_80070328.unk15g=0;
        }
        return;
    }
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_33/animation", func_level_33_8009C2B8);
