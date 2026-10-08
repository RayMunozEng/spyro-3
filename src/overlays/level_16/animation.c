#include "common.h"
#include "stdutil.h"
#include "ovl_header.h"
#include "spyro.h"

INCLUDE_ASM("asm/nonmatchings/overlays/level_16/animation", func_level_16_80083354);

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 800846D0.
 * Reuses verified11 character/table routes against original16 selectors41..4F.
 * Stack18 vector and source44-14/44-44 offsets are bytes; original selector
 * 80071924&63, stride4, table8006D048+14, entry+4 OR02000000 preserved.
 * Numeric vector progress2/5/6/7 yields341/853/1024/1024 before helpers;
 * unsigned gate accepts2..7. Empty constraints emit no instructions.
 * Every original code/internal jump/owned table word, strict complete TU and
 * all retail hashes required. Units, helpers, cadence, audio/live parity open.
 */
extern Spyro Callback16Player __asm__("D_80070328");
int Callback16Call80037058(int x, int y) __asm__("func_80037058");
void Callback16Call80041930(void) __asm__("func_80041930");
void Callback16Call80041AE8(void) __asm__("func_80041AE8");
void Callback16Call80041C20(void) __asm__("func_80041C20");
void Callback16Call80042A44(void) __asm__("func_80042A44");
void Callback16Call80043A38(int scale) __asm__("func_80043A38");
extern int Callback16Word8006E538 __asm__("D_8006E538");
extern int D_80071924;
extern int** Callback16Table __asm__("D_8006D048+0x14");
int Callback16Call80055E84(Moby*) __asm__("func_80055E84");
void Callback16Call8004ED6C(void*,Vector3D*,Vector3D*) __asm__("func_8004ED6C");
void Callback16Call8001BA30(Vector3D*,int,int,int,int,Moby*) __asm__("func_8001BA30");
int Callback16Call80019138(Vector3D*,int,int,int,int,Moby*) __asm__("func_80019138");
int Callback16Call8001830C(Vector3D*,Vector3D*,int,int,Moby*) __asm__("func_8001830C");
void func_level_16_800846D0(void) {
    Vector3D localVector;
    register int computedValue __asm__("$4");

    register int positionDelta __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback16Player.animationState) {
    case 0x41:
        if(func_800438F4()==0)func_80043728();
        Callback16Call80041C20();
        Callback16Player.unk9a=0;
        Callback16Call80042A44();
        goto clearSharedValue;
    default:
        return;
    case 0x44:
    case 0x4A:
        Callback16Call80041C20();
        Callback16Call80042A44();
        goto clearSharedValue;
    case 0x42:
    case 0x45:
        func_800438F4();
        Callback16Call80041C20();
        Callback16Call80042A44();
        Callback16Call80041930();
        goto queryC00;
    case 0x4E:
    case 0x4F:
        Callback16Call80041C20();
        Callback16Call80042A44();
        Callback16Call80041AE8();
        if ((unsigned char) Callback16Player.unk10[4] != 0) {
            computedValue = -Callback16Player.unk9ha[4] - Callback16Call80037058(Callback16Player.position.x, Callback16Player.position.y);
            positionValue = Callback16Player.unk4a - computedValue;
            Callback16Player.unk4[0] = computedValue;
            positionDelta = (int) Callback16Player.union144.a.unk13cc >> 6;
            positionValue -= positionDelta;
            __asm__("" : "=r"(positionValue) : "0"(positionValue));
            Callback16Player.position.z=positionValue;
            return;
        }
        break;
    case 0x43:
    case 0x46:
    case 0x49:
        Callback16Call80041C20();
        Callback16Call80042A44();
        Callback16Call80041930();
        if(Callback16Player.unk7a[3].z < 0 && Callback16Player.animationStateFrames >= 4) {
            Callback16Player.unk5=1;
        } else {
            if(Callback16Player.unk5==0 && !(Callback16Word8006E538 & 0x40) && Callback16Player.union144.a.unk13cb==0)
                Callback16Player.unk5=2;
        }
        goto clearSharedValue;
    case 0x47: {
        register int progress __asm__("$4");
        register int value __asm__("$2");
        register int* sourceBase __asm__("$16");
        register int flags __asm__("$17");
        if(Callback16Player.ticksSinceLastSurfaceTouch) {
            Callback16Call80041C20();
            Callback16Call80042A44();
        } else {
            func_800438F4();
            Callback16Call80041C20();
            Callback16Call80042A44();
            Callback16Call80041930();
            Callback16Call80043A38(0xC00);
        }
        progress=Callback16Call80055E84(Callback16Player.critterMobyPtr);
        if(Callback16Player.critterMobyPtr->animationState.id==6 && (unsigned int)(progress-2)<6) {
            if(progress<6)value=(progress<<10)/6;
            else value=0x400;
            localVector.x=value;
            __asm__ volatile("" : : : "memory");
            sourceBase=&Callback16Player.unk4a;
            localVector.y=0;
            localVector.z=0x200-*sourceBase;
            Callback16Call8004ED6C((unsigned char*)sourceBase-0x14,(&localVector),(&localVector));
            {register Vector3D* argument0 __asm__("$4")=(&localVector);
            register Vector3D* argument1 __asm__("$5")=(&localVector);
            __asm__("" : "=r"(argument0), "=r"(argument1) : "0"(argument0), "1"(argument1));
            sourceBase=(int*)((unsigned char*)sourceBase-0x44);
            func_8004F194(argument0,argument1,(Vector3D*)sourceBase);}
            flags=0x02000000;
            Callback16Call8001BA30((&localVector),0x200,0,0,flags,Callback16Player.critterMobyPtr);
            if((Callback16Call80019138((&localVector),0x200,0,0,flags,Callback16Player.critterMobyPtr)!=0 ||
                Callback16Call8001830C((Vector3D*)sourceBase,(&localVector),0,0x02000000,Callback16Player.critterMobyPtr)!=0)) {
                register int* selector __asm__("$16")=&D_80071924;
                if(func_80040954(*selector)==3) {
                    register int index __asm__("$2")=*selector;
                    register int** table __asm__("$3")=Callback16Table;
                    register int* entry __asm__("$3");
                    index &= 63;
                    entry=table[index];
                    entry[1] |= flags;
                }
            }
        }
        goto clearSharedValue;
    }
    case 0x4B:
    case 0x4C:
    case 0x4D:
        Callback16Call80041C20();
        Callback16Call80042A44();
        if(Callback16Player.unk5==1)func_800494A8();
        goto clearSharedValue;
    case 0x48:
        Callback16Call80041C20();
        Callback16Call80042A44();
        if(Callback16Player.unk5!=0)goto call41930;
queryC00:
        Callback16Call80043A38(0xC00);
        goto clearSharedValue;
call41930:
        Callback16Call80041930();
clearSharedValue:
        Callback16Player.unk4[0]=0;
        return;
    }
}



#define LEVEL_ID 16
#define PlaySpyroSounds_level_16 func_level_16_80084B04
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_16_80084B0C(int index) {
    register Vector3D* position __asm__("$4");
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0x43: case 0x44: case 0x46: case 0x49: case 0x4B: case 0x4C: case 0x4D:
        __asm__("" : : : "memory");
        position = 0;
        break;
    case 0x47: case 0x48:
        position = (Vector3D*)((char*)&spyro + 0xB8);
        __asm__("" : "=r"(position) : "0"(position));
        if (position->x) { position = 0; break; }
    case 0x41: case 0x42: case 0x45: case 0x4A: case 0x4E: case 0x4F:
        position = &g_Spyro.unk9e;
        break;
    default: return;
    }
    func_80043ABC(position);
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80084B9C.
 * Original16 character selectors41..4F; verified32 surface and signed-table
 * load lifetimes. Original player vectors8C/98, private250->0/4C, damage bit8,
 * signed table values>>1, surface stack20 and jump stack10 preserved.
 * Headbash movement is numeric0F; original44/49 condition and reload retained.
 * Numeric offsets are bytes. Signed table vectors -2/0/2 give -1/0/1.
 * Each call follows original instruction order; require every code/internal J,
 * owned table/pad, strict complete TU and all original hashes. Helper meanings,
 * physical units, audio semantics, caller cadence and live parity remain open.
 */
void Transition16_func_8004F0E8(Vector3D*,int) __asm__("func_8004F0E8");
void Transition16_func_8004F168(Vector3D*) __asm__("func_8004F168");
void Transition16_func_80043A38(int) __asm__("func_80043A38");
void Transition16_func_800441F0(void) __asm__("func_800441F0");
extern int Raw16Word __asm__("D_80070328+0x50");
extern int Raw16X __asm__("D_80070328+0x8C");
extern unsigned char Raw16Movement[] __asm__("D_80070328+0x50");
extern unsigned char Raw16Union[] __asm__("D_80070328+0x144");
extern int Raw16Animation __asm__("D_80070328+0x48");
extern short D_80065920[];
extern short D_800658A0[];
extern Spyro Transition16_D_80070328 __asm__("D_80070328");
int Transition16_func_8004EDE8(Vector3D*,int) __asm__("func_8004EDE8");
int Call16A358(Vector3D*,int) __asm__("func_8001A358");
extern int Transition16_D_8006E524 __asm__("D_8006E524");
extern int D_80071934;
void func_level_16_80084B9C(int arg0) {
    struct {Vector3D first; int gap; Vector3D second;} vectors;
    register Vector3D *damageSource __asm__("$16");
    register Vector3D *damageDestination __asm__("$16");
    Vector3D *firstJumpSource;
    Vector3D *secondJumpSource;
    enum MovementState nextSubstate;
    int lengthResult;
    register int comparisonKind __asm__("$2");
    register int previousValue __asm__("$2");
    register int firstAnimation __asm__("$3");
    register int tableIndex __asm__("$2");
    register int tableValue __asm__("$3");
    register unsigned char* soundTable __asm__("$3");
    register unsigned char* unionBase __asm__("$5");
    register int soundSelector __asm__("$4");
    register int soundZero __asm__("$5");
    register unsigned char* movement __asm__("$3");
    register unsigned char* initialMovement __asm__("$5");
    register void *jumpPrivate __asm__("$18");
    register void *damagePrivate __asm__("$18");

    switch (arg0) {
    case 0x41:
        Transition16_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition16_func_800441F0();
        Transition16_D_80070328.grounded = 1;
        return;
    case 0x42:
    case 0x45:
        Transition16_D_80070328.movementState = MOVEMENT_STATE_WALK;
        if ((arg0 == 0x57) && (Transition16_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
            func_8004F178((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition16_D_80070328.movementState) + 0x3C)), (Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition16_D_80070328.movementState) + 0x48)));
            Transition16_D_80070328.unk5 = MOVEMENT_STATE_WALK;
        } else {
            Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        }
        Transition16_D_80070328.unk8[0] = Transition16_func_8004EDE8(&Transition16_D_80070328.unk7a[3], 0);
        Transition16_func_80043A38(0xC00);
        Transition16_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition16_D_80070328.grounded = 1;
        goto clearFlags;
    case 0x43:
    case 0x49:
        initialMovement=Raw16Movement;
        __asm__("" : "=r"(initialMovement) : "0"(initialMovement));
        comparisonKind=10;
        __asm__("" : "=r"(comparisonKind) : "0"(comparisonKind));
        {register Moby* critter __asm__("$3")=Transition16_D_80070328.critterMobyPtr;
        register int current __asm__("$4")=*(int*)initialMovement;
        __asm__("" : "=r"(critter),"=r"(current) : "0"(critter),"1"(current));
        jumpPrivate=critter->mobyTag;
        __asm__("" : "=r"(jumpPrivate) : "0"(jumpPrivate));
        if ((current == comparisonKind) && (SpawnParticle != 0) && (Transition16_D_80070328.unk4[0] < 0)) {
            func_8004F178(&vectors.first, (Vector3D*)(initialMovement-0x50));
            vectors.first.z = -Transition16_D_80070328.unk4[0];
            SpawnParticle(6, 0x2E, &vectors.first, 0);
            SpawnParticle(4, 0x29, &vectors.first, 0);
        }
        }
        movement=Raw16Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        firstJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) firstJumpSource);
        Transition16_D_80070328.unk8[0] = Transition16_func_8004EDE8((Vector3D *) firstJumpSource, 0);
        if (arg0 == 0x49) {
            Transition16_D_80070328.unk7a[2].z = 0x2580;
        } else {
            Transition16_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)jumpPrivate+0x4C) = 0;
        }
        Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition16_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition16_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
        goto playJumpSound;
    case 0x44:
        Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        if (Transition16_D_80070328.movementState == MOVEMENT_STATE_JUMP_HOVER) {
            if(Transition16_D_80070328.animationState==0x43)Transition16_D_80070328.unk5=1;
            else if(Transition16_D_80070328.animationState==0x46)Transition16_D_80070328.unk5=Transition16_D_80070328.movementState;
            else if(Transition16_D_80070328.animationState==0x49)Transition16_D_80070328.unk5=4;
        } else {
            Transition16_D_80070328.movementState = MOVEMENT_STATE_FALL;
        }
        Transition16_D_80070328.unk8[0] = Transition16_func_8004EDE8(&Transition16_D_80070328.unk7a[3], 0);
        Transition16_D_80070328.grounded = 0;
        goto clearFlags;
    case 0x46:
        movement=Raw16Movement;
        __asm__("" : "=r"(movement) : "0"(movement));
        secondJumpSource=(Vector3D*)(movement+0x48);
        *(int*)movement=MOVEMENT_STATE_JUMP_HOVER;
        func_8004F178((Vector3D*)(movement+0x3C), (Vector3D *) secondJumpSource);
        Transition16_D_80070328.unk8[0] = Transition16_func_8004EDE8((Vector3D *) secondJumpSource, 0);
        Transition16_D_80070328.unk7a[2].z = 0x12C0;
        Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition16_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition16_D_80070328.grounded = 0;
        soundSelector = D_8006C654->jump;
        soundZero=0;
playJumpSound:
        PlaySound(soundSelector,(Moby*)soundZero,0);
        return;
    case 0x47:
        if (Transition16_D_80070328.ticksSinceLastSurfaceTouch != 0) {
            if (Transition16_D_80070328.movementState != MOVEMENT_STATE_FALL) {
                if (Transition16_D_80070328.animationState == 0x43) {
                    Transition16_D_80070328.unk5 = MOVEMENT_STATE_WALK;
                } else if (Transition16_D_80070328.animationState == 0x46) {
                    Transition16_D_80070328.unk5 = MOVEMENT_STATE_JUMP_HOVER;
                } else {
                    Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
                }
            }
            Transition16_D_80070328.movementState = MOVEMENT_STATE_FALL;
            Transition16_D_80070328.grounded = 0;
            Transition16_D_80070328.idle = 0;
            Transition16_D_80070328.unk15g = 0;
        } else {
            Transition16_D_80070328.movementState = MOVEMENT_STATE_WALK;
            Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            Transition16_func_80043A38(0xC00);
            Transition16_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition16_D_80070328.grounded = 1;
        }
        Transition16_D_80070328.unk8[0] = Transition16_func_8004EDE8(&Transition16_D_80070328.unk7a[3], 0);
        goto clearFlags;
clearFlags:
        Transition16_D_80070328.idle = 0;
        Transition16_D_80070328.unk15g = 0;
        return;
    case 0x4E:case 0x4F: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Raw16Word;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Raw16Union;
            *(int*)unionPointer=(-Transition16_D_80070328.unk7a[2].z)>>2;
            if(Raw16Word!=8){Transition16_D_80070328.union144.a.unk13cc=0x5900;Raw16Word=10;}
            Transition16_D_80070328.unk5=0;
            Transition16_D_80070328.unk8[0]=Transition16_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition16_D_80070328.grounded=1;
            Transition16_D_80070328.unk15b=1;
            localVector=&vectors.second;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.second.z+=0x400;
            lengthResult=Call16A358(localVector,0x800);
            vectors.second.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        return;
    }
    case 0x48: {
        register Moby* critter __asm__("$2")=Transition16_D_80070328.critterMobyPtr;
        __asm__ volatile("" : "=r"(critter) : "0"(critter) : "memory");
        damagePrivate=critter->mobyTag;
        __asm__ volatile("" : "=r"(damagePrivate) : "0"(damagePrivate) : "memory");
        previousValue=Raw16Word;
        __asm__ volatile("" : "=r"(previousValue) : "0"(previousValue) : "memory");
        unionBase=Raw16Union;
        __asm__("" : "=r"(previousValue),"=r"(unionBase) : "0"(previousValue),"1"(unionBase));
        *(int*)unionBase=previousValue;
        Raw16Word = MOVEMENT_STATE_HURT;
        if (Transition16_D_80070328.damageFlags & 8) {
            damageSource = (Vector3D *) (unionBase - 0xAC);
            Transition16_D_80070328.unk5 = MOVEMENT_STATE_WALK;
            func_8004F178((Vector3D *) (unionBase - 0xB8), damageSource);
            Transition16_D_80070328.unk8[0] = Transition16_func_8004EDE8(damageSource, 0);
            soundTable=(unsigned char*)D_8006C654;
            soundZero=0;
            __asm__ volatile("" : "=r"(soundTable),"=r"(soundZero) : "0"(soundTable),"1"(soundZero) : "memory");
            Transition16_D_80070328.unk7a[2].z = 0x1680;
            *(int*)((unsigned char*)damagePrivate+0x4C) = 0;
            Transition16_D_80070328.grounded = 0;
            Transition16_D_80070328.union144.a.unk13cc = 1;
            PlaySound(soundTable[12],(Moby*)soundZero,0);
        } else {
            Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
            damageDestination = (Vector3D *) (unionBase - 0xB8);
            if (Transition16_D_80070328.unk17a & 0x400) {
                func_8004F178(damageDestination, (Vector3D *) ((Vector3D *) (unionBase + 0xD8)));
                Transition16_func_8004F0E8(damageDestination, 6);
            } else if (Transition16_D_80070328.unk22[5] >= 0) {
                tableIndex=Transition16_D_80070328.unk22[5]*2;
                tableValue=*(short*)((unsigned char*)D_80065920+tableIndex);
                __asm__("" : "=r"(tableValue) : "0"(tableValue));
                Raw16X=tableValue>>1;
                tableIndex=*(short*)((unsigned char*)D_800658A0+tableIndex);
                Transition16_D_80070328.unk7a[2].z=0;
                __asm__ volatile("" : "=r"(tableIndex) : "0"(tableIndex) : "memory");
                Transition16_D_80070328.unk7a[2].y=tableIndex>>1;
            } else {
                    __asm__("" : "=r"(unionBase) : "0"(unionBase));
                Transition16_func_8004F168((Vector3D*)(unionBase-0xB8));
            }
            func_8004F178(&Transition16_D_80070328.unk7a[1], (Vector3D *) ((unsigned char*)(&Transition16_D_80070328.unk7a[1]) + 0xC));
            Transition16_func_80043A38(0xC00);
            Transition16_D_80070328.grounded = 1;
        }
        Transition16_D_8006E524 = 0xF;
        if (SpawnParticle != 0) {
            SpawnParticle(5, 0xA, 0, 0);
            return;
        }
        break;
    }
    case 0x4A:
        Transition16_D_80070328.movementState = MOVEMENT_STATE_DEATH;
        Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition16_func_80043A38(0xC00);
        Transition16_D_80070328.grounded = 1;
        Transition16_D_8006E524 = 0xF;
        return;
    case 0x4B:
        firstAnimation=Raw16Animation;
        __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        if(firstAnimation==0x44){
            if(Transition16_D_80070328.unk5==4)goto setHeadbashFlag;
            comparisonKind=0x49;
            __asm__ volatile("" : "=r"(comparisonKind) : "0"(comparisonKind) : "memory");
            firstAnimation=Raw16Animation;
            __asm__("" : "=r"(firstAnimation) : "0"(firstAnimation));
        }else comparisonKind=0x49;
        if(firstAnimation==comparisonKind){
setHeadbashFlag:
            Transition16_D_80070328.union144.a.unk13cc=1;
        }else Transition16_D_80070328.union144.a.unk13cc=0;
        Transition16_D_80070328.movementState = MOVEMENT_STATE_HEADBASH;
        Transition16_D_80070328.unk5 = MOVEMENT_STATE_STAND;
        Transition16_func_8004F168((Vector3D *) ((Vector3D *) ((unsigned char*)(&Transition16_D_80070328.movementState) + 0x3C)));
        Transition16_D_80070328.unk7a[2].z = 0x800;
        Transition16_D_80070328.grounded = 0;
        Transition16_D_80070328.unk13a[0] = 0x20000;
        Transition16_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        return;
    case 0x4C:
        Transition16_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=1;
        goto setHeadbashSubstate;
    case 0x4D:
        Transition16_D_80070328.movementState=MOVEMENT_STATE_HEADBASH;
        nextSubstate=2;
setHeadbashSubstate:
        Transition16_D_80070328.unk5=nextSubstate;
        Transition16_D_80070328.grounded=0;
        Transition16_D_80070328.unk13a[0]=0x20000;
        return;
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/level_16/animation", func_level_16_800853D4);
