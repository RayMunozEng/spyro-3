#include "common.h"
#include "mobyfunc.h"
#include "mobyutil.h"
#include "stdutil.h"
#include "ovl_header.h"
#include "spyro.h"
#include "str.h"

// collision
extern int func_8001A310(Vector3D*, int, int, Moby*);
extern int func_8001A358(Vector3D*, int);

// spyro
extern int func_80040954(int);

// updatemobys
extern void func_80055B18(Moby*); // delete moby
extern void func_80056270(Moby*);
extern void func_8005629C(Moby*);

// lib
extern int rand(); // rand

// data
extern short D_800658A0[0x100]; // sin
extern short D_80065920[0x100]; // cos
extern unsigned char D_80066964[28]; // GemValueToSubstate
extern unsigned char D_80066980[];
extern unsigned char D_80066988[8]; // GemAnimationIds
extern unsigned char D_80066990[8]; // GemColourIndices
extern unsigned char D_80066F54[40]; // gems per level / 100
extern unsigned char D_80066F7C[40]; // eggs per level
extern TalkTextData D_80067554[7]; // TriangleToTalkData

// sdata / sbss
extern int levelIndex; // 8006C58C
extern int* dragonModelPtr; // 8006C5B0
extern int D_8006C648; // deltaTime
extern Moby* D_8006C550; // MobyArrayPointer
extern int D_8006C580;
extern Moby* D_8006C704; // FirstAllocatedMobyPointer
extern unsigned short** D_8006C730;
extern int D_8006C770;
extern int D_8006C6F8;
extern int D_8006C71C;
extern int D_8006C79C;
extern unsigned char D_8006E3B0[];
extern int D_80071A10[];
extern unsigned int D_80071AB0[40][8];

// bss
extern WadHeader wadHeader; // 8006d8d8
extern CollisionData D_80071900;
extern LevelWadHeader levelWadHeader; // 80072098

////////////////////////////////////////////////////////////////////////////////////

/**
 * ???() - func_80034DAC()
 * WIP, lots of externs but a fairly short function
 * https://decomp.me/scratch/cbDKn
 */
/* Retail source: asm/nonmatchings/mobyutil/func_80034DAC.s,
 * 0x80034DAC..0x80034F40; Moby update occurs once per call. */
extern unsigned char D_80070130[];
extern char D_8006E00C[];
extern char D_80070328;
void func_8004ECF4(SHORTMATRIX*, void*);
void func_8004ED6C(SHORTMATRIX*, void*, Vector3D*);
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
void func_8004F110(Vector3D*, int);
void func_80055D24(Moby*, int);
void func_80055F14(Moby*, int, void*);
void func_80034DAC(Moby* moby) {
    Vector3D delta;
    SHORTMATRIX matrix;
    char* tag = moby->mobyTag;
    char* linked;
    if ((*(unsigned char*)((char*)moby + 0x42) & 2) && moby->animationState.nextId != 0) {
        D_8006C770 = 0;
        {
            unsigned char nextId = moby->animationState.nextId;
            unsigned char nextFrame = moby->animationState.nextFrame;
            moby->animationProgress = 0x72;
            moby->animationState.nextId = 0;
            moby->animationState.nextFrame = 0;
            moby->animationState.id = nextId;
            moby->animationState.frame = nextFrame;
        }
        func_80035734(moby);
    }
    *(unsigned char*)((char*)moby + 0x44) = D_80070130[0];
    *(unsigned char*)((char*)moby + 0x45) = D_80070130[1];
    func_8003585C(moby, D_80070130[2], 16, 0, 0, 0);
    func_8004ECF4(&matrix, D_8006E00C);
    func_8004ED6C(&matrix, D_80070130 - 0x18, &delta);
    func_8004F194(&delta, &delta, (Vector3D*)(D_8006E00C + 0x14));
    func_8004F1C8(&delta, &delta, &moby->position);
    func_8004F110(&delta, 2);
    func_8004F194(&moby->position, &moby->position, &delta);
    func_80055D24(moby, 4);
    linked = *(char**)(tag + 0x10);
    if (linked != 0) {
        int value;
        linked[0x13] = 0x7F;
        value = *(int*)(&D_80070328 + 0x280);
        if (value >= 4) {
            (*(char**)(tag + 0x10))[0x10] = value;
        } else {
            (*(char**)(tag + 0x10))[0x10] = 1;
        }
        func_80055F14(moby, 0, *(void**)(tag + 0x10));
    }
}

/** 
 * DoMobyAnimation - func_80034F40() - MATCHING
 * https://decomp.me/scratch/QgLnA
 */
void func_80034F40(Moby* moby, int newId) {
    if (moby->animationState.nextId != newId) {
        D_8006C770 = 0;
        moby->animationProgress = 0x72;
        moby->animationState.nextId = newId;
        moby->animationState.nextFrame = 0;
        func_80035734(moby); // moby lerp error thing ??
    }
}

/** 
 * SetMobyAnimation() - func_80034F80()
 * Weird, has that weird array I've labelled as "moby sound pointers"??
 * https://decomp.me/scratch/wbxvf
 */
extern int D_8006EE2C[];
void func_80034F80(Moby* moby, int animation) {
    unsigned char* bytes = (unsigned char*)moby;
    if (bytes[0x3C] != animation) {
        int klass;
        int table;
        unsigned char* descriptor;
        register unsigned int first __asm__("$2");
        int flag;
        klass = *(short*)(bytes + 0x36);
        bytes[0x42] = 0;
        table = D_8006EE2C[klass];
        descriptor = *(unsigned char**)(table + animation * 4 + 0x3C);
        first = descriptor[0];
        __asm__ volatile ("" : "=r"(first) : "0"(first));
        bytes[0x3C] = animation;
        bytes[0x3D] = animation;
        bytes[0x3E] = 0;
        bytes[0x3F] = 1;
        __asm__ volatile ("" : "=r"(first) : "0"(first), "m"(bytes[0x3F]));
        flag = first < 2;
        __asm__ volatile ("" : "=r"(flag) : "0"(flag));
        flag ^= 1;
        flag = -flag;
        bytes[0x40] = flag & 0x30;
    }
}

/**
 * SetDefaultMobyProperties() - func_80034FEC() - MATCHING
 * https://decomp.me/scratch/Ya4ab
 */
void func_80034FEC(Moby* arg0) {
    arg0->lowDrawDistance = 0x10;
    arg0->updateDistance = 0xFF;
    arg0->unknown4 = 4;
    arg0->animationState.nextFrame = 1;    
    arg0->animationProgress = 0x30;
    arg0->unknown3[0] = 1;
    arg0->animationRun = 0xFF;
    arg0->highDrawDistance = 0x40;
    arg0->subtype = 0xFF;
    arg0->gemValue = 0xFF;
}

/**
 * ???() - func_80035030() - MATCHING
 * Ready to implement, might want to spend a small amount of time cleaning it too
 * Maybe consider making a txt file with my common functions and externed variables when this is in too
 * https://decomp.me/scratch/KUovp
 */
int func_80035030(Moby* arg0, int* arg1, int arg2, int* arg3, int arg4, int arg5, int arg6, int arg7) {
    int temp_v0;
    int temp_v1_2;
    int temp_v1_3;
    int var_a3;
    int var_s3;
    int var_v0;
    int var_v1;
    var_v1 = arg7;
    var_s3 = 0;
    var_a3 = arg6;
    if (arg3 == 0) var_v1 |= 4;
    if (var_v1 & 0x4000) var_a3 = 0;
    if (*arg1 != 0) {
        var_s3 = func_80035EE0(arg0, arg2, *arg1, var_a3, arg6, var_v1 | 0x2000);
        *arg1 -= arg4;
        if (*arg1 < 0) *arg1 = 0;
    }
    if (arg3 != 0) {
        var_v0 = var_s3;
        if (*arg3 != 0xFFFF) {
            temp_v0 = func_80035D84(arg0, 0x258);
            arg0->position.z += *arg3;
            temp_v1_2 = *arg3 - arg5;
            *arg3 = temp_v1_2;
            if (temp_v1_2 < -0x104) *arg3 = -0x104;
            if (*arg3 <= 0) {
                temp_v1_3 = temp_v0 + arg0->distanceToGround;
                if (arg0->position.z < temp_v1_3) {
                    arg0->position.z = temp_v1_3;
                    var_s3 = 3;
                }
            }
            func_80056270(arg0);
            func_8005629C(arg0);
        }
    }
    return var_s3;
}

INCLUDE_ASM("asm/nonmatchings/mobyutil", func_80035194);

/** 
 * ???() - func_80035734() - MATCHING
 * Content is possibly not included in retail versions (moby lerp error from Spyro 1?)
 * Based on other functions, seems to take in a moby, which makes sense
 * https://decomp.me/scratch/Dz93r
 */
void func_80035734(Moby* moby) {
    return;
}

/**
 * ???() - func_8003573C() - MATCHING
 * Possibly responsible for turning a moby towards the player?
 * https://decomp.me/scratch/rAQLx
 */
int func_8003573C(Moby* arg0, int arg1, int arg2, int arg3) {
    int temp_a0;
    int temp_v0;

    temp_v0 = func_8004E880(spyro.position.x - arg0->position.x, spyro.position.y - arg0->position.y, 0);
    temp_a0 = func_8004F264(temp_v0, arg0->angle.yaw);
    
    if      (D_8006C648 == 3) arg1 += (arg1 >> 1);
    else if (D_8006C648 == 4) arg1 *= 2;
    
    if (temp_a0 < arg1) arg1 = temp_a0; // temp_a0 acts as an upper bound
    
    if (arg2 < func_8004F264(temp_v0, arg0->angle.yaw)) {
        arg0->angle.yaw = func_8004F2EC(temp_v0, arg0->angle.yaw, arg1, (arg1 >> 1) + 1);
        return 0;
    }
    if (arg3 != 0) {
        arg0->angle.yaw = func_8004F2EC(temp_v0, arg0->angle.yaw, arg1, (arg1 >> 1) + 1);
    }
    return 1;
}

/**
 * ???() - func_8003585C() - MATCHING
 * https://decomp.me/scratch/LaxWp
 */
int func_8003585C(Moby* arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    int temp_v1;

    temp_v1 = func_8004F264(arg1, arg0->angle.yaw);
    if (D_8006C648 == 3) {
        arg2 += arg2 >> 1;
        if (temp_v1 < arg2) arg2 = temp_v1;
    }
    else if (D_8006C648 == 4) {
        arg2 *= 2;
        if (temp_v1 < arg2) arg2 = temp_v1;
    }
    else if (temp_v1 < arg2) arg2 = temp_v1;
    
    if (arg3 < temp_v1) {
        if (arg5 != 0) {
            arg0->angle.yaw += (arg2 * arg5);
        } else {
            arg0->angle.yaw = func_8004F2EC(arg1, arg0->angle.yaw, arg2, (arg2 >> 1) + 1);
        }
        return (arg3 >= func_8004F264(arg1, arg0->angle.yaw));
    }
    if ((arg4 != 0) && (temp_v1 >= 3)) {
        if (arg5 != 0) {
            arg0->angle.yaw += (arg2 * arg5);
        } else {
            arg0->angle.yaw = func_8004F2EC(arg1, arg0->angle.yaw, arg2, (arg2 >> 1) + 1);
        }
        
    }
    return 1;
}

/**
 * CountTimerDown() - func_800359A4() - MATCHING
 * https://decomp.me/scratch/YfBcS
 */
int func_800359A4(void* pTimer, int pTimerType) {

    if (pTimerType == sizeof(int)) {
        int timer = *(int*)pTimer;
        if (D_8006C648 >= timer) {
            if (timer != 0) {
                *(int*)pTimer = 0;
                return 2;
            }
            return 1;
        } else {
            *(int*)pTimer -= D_8006C648;
            return 0;
        }
    } else if (pTimerType == sizeof(short)) {
        short timer = *(short*)pTimer;
        if (D_8006C648 >= timer) {
            if (timer != 0) {
                *(short*)pTimer = 0;
                return 2;
            }
            return 1;
        } else {
            *(short*)pTimer -= D_8006C648;
            return 0;
        }
    } else if (pTimerType == sizeof(char)) {
        char timer = *(char*)pTimer;
        if (D_8006C648 >= timer) {
            if (timer != 0) {
                *(char*)pTimer = 0;
                return 2;
            }
            return 1;
        }
        else {
            *(char*)pTimer -= D_8006C648;
            return 0; 
        }
    }
    return 0;
}

/**
 * ???() - func_80035A80() - MATCHING
 * Path related, needs better struct naming but is ready to add
 * https://decomp.me/scratch/MfTDY
 */
/* Retail Rev 0: 0x80035A80..0x80035D38. Path nodes hold runtime
 * Vector3D coordinates; updates run on each call with D_8006C648 ticks. */
typedef struct { Vector3D unk0; int unkC; } PathNodeRev0;
typedef struct {
    short unk0, unk2;
    int unk4;
    short unk8, unkA;
    PathNodeRev0* unkC;
} PathHeaderRev0;
int func_8004F334(Vector3D*, Vector3D*);
int func_80035DDC(Moby*, int, int, int, int);
int func_80035A80(Moby* arg0, PathHeaderRev0* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    int temp_a0;
    int temp_v0;
    int temp_v0_4;
    int temp_v0_5;
    int var_s0_2;
    int var_s4;
    int var_s6;
    int var_v0;
    var_s4 = 0;
    var_s6 = 0;
    if (arg7 & 0x100) {
        temp_v0 = arg0->position.z - arg1->unkC[arg1->unk2].unk0.z;
        var_s0_2 = (ABS(temp_v0) < arg2);
    } else {
        var_s0_2 = 1;
    }
    if (func_8004F334(&arg0->position, &arg1->unkC[arg1->unk2].unk0) < arg2) {
        if (var_s0_2) var_s4 = 1;
    }
    if (arg7 & 0x20000) {
        if (func_8004F264(arg0->angle.yaw, func_8004E880(arg1->unkC[arg1->unk2].unk0.x - arg0->position.x, arg1->unkC[arg1->unk2].unk0.y - arg0->position.y, 0)) >= 0x41)
            var_s4 = 1;
    }
    if (var_s4 != 0) {
        temp_a0 = arg1->unk2 + arg1->unkA;
        arg1->unk2 = (temp_a0 + arg1->unk0) % arg1->unk0;
        if (temp_a0 != arg1->unk2) var_s6 = 3;
        else var_s6 = 1;
    }
    temp_v0_4 = func_8004E880(arg1->unkC[arg1->unk2].unk0.x - arg0->position.x, arg1->unkC[arg1->unk2].unk0.y - arg0->position.y, 0);
    temp_v0_5 = func_8004F264(temp_v0_4, arg0->angle.yaw);
    if (arg6 >= temp_v0_5) {
        func_8003585C(arg0, temp_v0_4, arg5, arg6, 1, 0);
        func_80035DDC(arg0, arg3, arg4, 0, arg7);
    } else {
        if (D_8006C648 == 3) arg5 += arg5 >> 1;
        else if (D_8006C648 == 4) arg5 *= 2;
        MAX(arg5, temp_v0_5);
        func_8003585C(arg0, temp_v0_4, arg5, 0x80, 1, 0);
    }
    if (func_8004F264(temp_v0_4, arg0->angle.yaw) > 0) var_s6 |= 4;
    return var_s6;
}

/**
 * SnapMobyToGround() - func_80035D38() - MATCHING
 * Snaps moby to ground
 * https://decomp.me/scratch/pnSZL
 */
int func_80035D38(Moby* moby) {
    int x;
    
    moby->position.z += 0x5DC;
    x = func_8001A358(&moby->position, 0x1000);
    moby->position.z -= 0x5DC;
    return x;
}

/**
 * SnapMobyToGroundRange() - func_80035D84() - MATCHING
 * Ready to add
 * https://decomp.me/scratch/pfFhX
 */
int func_80035D84(Moby* moby, int range) {
    int result;
    moby->position.z += range;
    result = func_8001A358(&moby->position, 0x1000);
    moby->position.z -= range;
    return result;
}

/**
 * ???() - func_80035DDC() - MATCHING
 * Does something involving moving a moby and some sin / cos stuff
 * https://decomp.me/scratch/dRDSG
 */
int func_80035DDC(Moby* arg0, int arg1, int arg2, int arg3, int arg4) {
    Vector3D sp18;

    if (!(arg4 & 0x10000)) {
        if      (D_8006C648 == 3) arg1 += arg1 >> 1;
        else if (D_8006C648 == 4) arg1 *= 2;
    }
    sp18.x = (D_80065920[arg0->angle.yaw] * arg1) >> 0xC;
    sp18.y = (D_800658A0[arg0->angle.yaw] * arg1) >> 0xC;
    sp18.z = 0;
    func_8004F194(&sp18, &sp18, &arg0->position);
    return func_80038000(arg0, &sp18, arg3, arg2, arg4);
}

/**
 * ???() - func_80035EE0() - MATCHING
 * Ready to add
 * Does something involving moving a moby and some sin / cos stuff
 * https://decomp.me/scratch/jDsId
 */
int func_80035EE0(Moby* arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    Vector3D sp18;
    if (!(arg5 & 0x10000)) {
        if (D_8006C648 == 3) arg2 += arg2 >> 1;
        else if (D_8006C648 == 4) arg2 *= 2;
    }
    sp18.x = (D_80065920[arg1] * arg2) >> 0xC;
    sp18.y = (D_800658A0[arg1] * arg2) >> 0xC;
    sp18.z = 0;
    func_8004F194(&sp18, &sp18, &arg0->position);
    if (arg5 & 0x2000) {
        if (sp18.x < 0x400) sp18.x = 0x400;
        if (sp18.y < 0x400) sp18.y = 0x400;
        if (sp18.z < 0x400) sp18.z = 0x400;
    }
    return func_80038000(arg0, &sp18, arg4, arg3, arg5);
}

/** 
 * ???() - func_80036018() - MATCHING
 * Does some arithmetic
 * https://decomp.me/scratch/u3loU
 */
int func_80036018(int arg0, int arg1, int arg2) {
    int diff;
    int absDiff;

    diff = func_8003613C(arg0, arg1); // arg1 - arg0
    absDiff = ABS(diff); // |arg1 - arg0|
    if (arg2 < absDiff) {
        if (diff < 0) return func_8003617C(arg1, arg2);  // if arg1 < arg0,  return arg1 + arg2
        else          return func_8003617C(arg1, -arg2); // if arg1 >= arg0, return arg1 - arg2
    }
    return arg0;
}

/**
 * ???() - func_800360A0() - MATCHING
 * Does some simple but very specific arithmetic, types took a while to get exactly right
 * https://decomp.me/scratch/J8wdV
 */
int func_800360A0(int arg0, int arg1, unsigned char arg2) {
    return func_8003617C(arg1, (func_8003613C(arg1, arg0) * arg2) >> 8); // y + ((x - y) * z) / 256
}

/**
 * ???() - func_800360F8 - MATCHING
 * Mixes some functions
 * https://decomp.me/scratch/aUHyS
 */
int func_800360F8(int arg0, int arg1, int arg2, unsigned char arg3) {
    return func_800360A0(func_80036018(arg0, arg1, arg2), arg1, arg3);
}

/**
 * ???() - func_8003613C - MATCHING
 * Signed difference mod 0x80
 * https://decomp.me/scratch/bt3wL
 */
int func_8003613C(int arg0, int arg1) {
    int var_a0;

    var_a0 = (arg1 - arg0) & 0xFF;
    if (var_a0 >= 0x81) {
        var_a0 -= 0x100;
    }
    return var_a0;
}

/**
 * ???() - func_8003615C - MATCHING
 * Signed difference mod 0x800
 * https://decomp.me/scratch/jXP9Z
 */
int func_8003615C(int arg0, int arg1) {
    int var_a0;

    var_a0 = (arg1 - arg0) & 0xFFF;
    if (var_a0 >= 0x801) {
        var_a0 -= 0x1000;
    }
    return var_a0;
}

/**
 * ???() - func_8003617C() - MATCHING
 * Add two ints and make them char
 * https://decomp.me/scratch/Ijb5H
 */
int func_8003617C(int arg0, int arg1) {
    return (arg0 + arg1) & 0xFF;
}

/**
 * ???() - func_80036188() - MATCHING
 * Ready to implement
 * https://decomp.me/scratch/a5QDz
 */
extern int func_8004F388(int);
void func_80036188(Angle* out) {
    Vector3D* vec = &D_80071900.D_80071918;
    int magnitude = func_8004F388(vec->x * vec->x + vec->z * vec->z);
    ((char*)out)[0] = -func_8004E880(magnitude, vec->y, 0);
    ((char*)out)[1] = -func_8004E880(vec->z, vec->x, 0);
}

void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
int func_80036220(Vector3D* position, char* bounds, int margin, int zLimit) {
    Vector3D rotated;
    Vector3D delta;
    int angle = *(int*)(bounds + 0x14);
    register int rx __asm__("$3");
    register int ry __asm__("$4");
    int width;
    int height;
    int z;
    func_8004F1C8(&delta, position, (Vector3D*)bounds);
    {
        int firstProduct = delta.x * D_80065920[angle];
        int secondProduct = delta.y * D_800658A0[angle];
        register int first __asm__("$3") = firstProduct >> 12;
        register int second __asm__("$2") = secondProduct >> 12;
        rx = first - second;
    }
    rotated.x = rx;
    {
        int firstProduct = delta.x * D_800658A0[angle];
        int secondProduct = delta.y * D_80065920[angle];
        register int first __asm__("$4") = firstProduct >> 12;
        register int second __asm__("$2") = secondProduct >> 12;
        ry = first + second;
    }
    rotated.y = ry;
    width = *(int*)(bounds + 0xC);
    if (rx < 0) rx = -rx;
    if (rx >= width + margin) return 0;
    height = *(int*)(bounds + 0x10);
    {
        register int absY __asm__("$3");
        if (ry >= 0) {
            absY = ry;
        } else {
            absY = ry;
            __asm__ volatile ("subu %0,$zero,%0" : "=r"(absY) : "0"(absY));
        }
        if (absY < height + margin) {
            if (zLimit == 0) return 1;
            z = delta.z;
            if (z < 0) z = -z;
            return z <= zLimit;
        }
    }
    return 0;
}
/**
 * RandBetween() - func_8003636C() - MATCHING
 * https://decomp.me/scratch/GldaF
 */
int func_8003636C(int low, int high) {
    return (rand() % ((high - low) + 1)) + low;
}

/**
 * RandSignedBetween() - func_800363DC() - MATCHING
 * https://decomp.me/scratch/8cKXa
 */
int func_800363DC(int low, int high) {
    int r;
    int out;

    r = rand();
    out = (r % ((high - low) + 1)) + low;
    if (r & 1) {
        return out;
    }
    return -out;
}

typedef struct {
    short count;
    short selectedIndex;
    int unknown4;
    int unknown8;
    char* points;
} PathPointSet;

extern int func_8004F334(Vector3D*, Vector3D*);

int func_8003645C(Vector3D* position, PathPointSet* path, int* selectedIndex) {
    int index;
    int bestIndex = 0;
    int bestDistance = 0xFFFFFF;

    for (index = 0; index < path->count; index++) {
        int distance = func_8004F334(position, (Vector3D*)(path->points + index * 16));
        if (distance < bestDistance) {
            bestDistance = distance;
            bestIndex = index;
        }
    }

    if (selectedIndex != 0) {
        *selectedIndex = bestIndex;
    }
    return bestDistance;
}

/* Retail source: asm/nonmatchings/mobyutil/func_80036518.s,
 * 0x80036518..0x800365E4; path node stride is 16 runtime bytes. */
typedef struct { short count, unk2; int unk4, unk8; char* nodes; } PathFindHeader;
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
int func_8004EDE8(Vector3D*, int);
int func_80036518(Vector3D* position, PathFindHeader* path, int* closestIndex) {
    int best = 0xFFFFFF;
    int bestIndex = 0;
    int i;
    for (i = 0; i < path->count; i++) {
        Vector3D delta;
        int distance;
        func_8004F1C8(&delta, (Vector3D*)(path->nodes + i * 16), position);
        distance = func_8004EDE8(&delta, 1);
        if (distance < best) {
            best = distance;
            bestIndex = i;
        }
    }
    if (closestIndex != 0) *closestIndex = bestIndex;
    return best;
}

int func_800365E4(Vector3D* first, Vector3D* second, int divisor,
                  int acceleration, int* outSteps) {
    int delta[2];
    int steps;
    delta[0] = first->x - second->x;
    delta[1] = first->y - second->y;
    steps = func_8004EDE8((Vector3D*)delta, 0) / divisor;
    if (outSteps != 0) *outSteps = steps;
    if (steps != 0) {
        return -(first->z - second->z + ((acceleration * (steps * steps)) >> 1)) / steps;
    }
    return 0;
}

extern short D_8006E040;

/* Retail source: USA Rev 0 PSX.EXE 0x80036708..0x800368A4 (103 words).
 * One call emits one display Moby per decimal digit. Positions and velocities
 * use raw integer world units; the retail 12-bit-turn heading is reduced to an
 * 8-bit table index. Confidence: exact. Falsifiable by all 103 instruction
 * words, the full PSX.EXE SHA-256, and every overlay hash. */
void func_80036708(int arg0, Moby* arg1) {
    short velocity[3];
    register int count __asm__("$18") = arg0;
    register Moby* source __asm__("$22") = arg1;
    register int place __asm__("$19") = 1;
    register int var_s0 __asm__("$16") = (int)&D_8006E040;
    register int x __asm__("$21") = source->position.x;
    register int y __asm__("$20");
    register int trig_arg __asm__("$4");
    register int trig_result __asm__("$2");
    int digit;
    int product;

    __asm__ volatile("" : "=r"(source), "=r"(place) : "0"(source), "1"(place));
    __asm__ volatile("" : "=r"(var_s0) : "0"(var_s0));
    trig_arg = *(short*)var_s0;
    y = source->position.y;
    trig_result = func_8004EA2C(trig_arg - 0x400);
    trig_arg = *(short*)var_s0;
    velocity[0] = trig_result >> 8;
    velocity[1] = func_8004E9E4(trig_arg - 0x400) >> 8;
    velocity[2] = 0x80;
    while (count != 0) {
        register Moby* spawned __asm__("$2");
        register int* tag __asm__("$4");
        register int z __asm__("$3");
        int place_temp;

        digit = count / 10;
        var_s0 = digit;
        digit = count - digit * 10;
        spawned = SpawnMoby(0x104, 0);
        spawned->animationState.id = digit;
        spawned->position.x = x;
        spawned->position.y = y;
        z = source->position.z;
        product = digit * place;
        spawned->angle.roll = 0;
        spawned->angle.pitch = 0;
        spawned->position.z = z;
        tag = (int*)spawned->mobyTag;
        spawned->angle.yaw = (unsigned short)D_8006E040 >> 4;
        tag[1] = 0x60;
        tag[3] = velocity[0];
        tag[4] = velocity[1];
        count = var_s0;
        tag[5] = velocity[2];
        __asm__ volatile("sll %0, %1, 2" : "=&r"(place_temp) : "r"(place));
        __asm__ volatile("addu %0, %0, %2" : "=&r"(place_temp) : "0"(place_temp), "r"(place));
        __asm__ volatile("sll %0, %1, 1" : "=r"(place) : "r"(place_temp));
        tag[2] = product;
        {
            register unsigned int angle __asm__("$4") = spawned->angle.yaw;
            register int sine __asm__("$3") = D_800658A0[angle];
            int cosine = D_80065920[angle];

            velocity[2] -= 0x10;
            __asm__ volatile("" : "=r"(sine) : "0"(sine));
            __asm__ volatile("" : "=r"(cosine) : "0"(cosine));
            x -= sine >> 4;
            y += cosine >> 4;
        }
    }
}

/* Retail source: asm/nonmatchings/mobyutil/func_800368A4.s,
 * 0x800368A4..0x800369B8; raw integer state fields. */
int func_800368A4(void* object, int value, int mode) {
    register int level asm("$7") = value;
    register char* state asm("$8") = object;
    register int high asm("$5");
    register int part asm("$3");
    register int base asm("$4");
    register int temp asm("$2");
    int flags;
    if (level == 0) {
        if (!(*(int*)(state + 0x18) & 0x10000)) {
            return level;
        }
    }
    flags = *(int*)(state + 0x18);
    if (flags & 0x10000) {
        if (mode == 2) {
            level += 0x20;
            if (level >= 0x51) level = 0x50;
        } else {
            level += 0x10;
            if (level >= 0x40) level = 0x3F;
        }
    } else {
        level--;
        if (level >= 0x21) level--;
    }
    if (mode == 0) {
        *(int*)(state + 0x54) = 0x30000080 + ((level >> 2) << 24);
    } else {
        if (mode == 2) {
            temp = 0xF0000000;
            high = *(int*)(state + 0x54);
            base = 0x0D000000;
            high &= temp;
            temp = 0x50 - level;
            part = temp << 16;
        } else {
            temp = 0xF0000000;
            part = 0x60 - level;
            part <<= 16;
            high = *(int*)(state + 0x54);
            base = 0x0D000000;
            high &= temp;
            temp = 0x50 - level;
        }
        temp <<= 8;
        temp += base;
        part += temp;
        part += 0x50;
        temp = level << 1;
        part += temp;
        high += part;
        *(int*)(state + 0x54) = high;
    }
    return level;
}

/**
 * ???() - func_800369B8() - MATCHING
 * https://decomp.me/scratch/fWFU8
 */
void func_800369B8() {
    func_8002E2D0();
}

/**
 * ???() - func_800369D8() - MATCHING
 * Seems to count the alive mobys
 * https://decomp.me/scratch/Fc1Ui
 */
int func_800369D8(int arg0) {
    int liveMobys;
    short temp_a1;
    short* var_a0;

    liveMobys = 0;
    if (arg0 >= D_8006C580) return 0;
    
    var_a0 = D_8006C730[arg0];
    do {
        temp_a1 = *var_a0;
        if (D_8006C550[temp_a1 & 0x7FFF].state < 0x80) liveMobys++; // Moby is live, increment
        var_a0++;
    } while (0 <= temp_a1);
    return liveMobys;
}

typedef struct {
    unsigned char pad0[4];
    short velocityX;
    short velocityY;
    short velocityZ;
    unsigned char padA[4];
    unsigned char randomX;
    unsigned char randomY;
    unsigned char randomZ;
    unsigned char movementMode;
    unsigned char settleMode;
    unsigned char timer;
} GemMobyTag;

extern int D_8006C5C8;
extern Vector3D D_8007190C;
extern Vector3D D_80071918;
extern int D_80071920;
extern int D_80071930;
extern int g_CurrentLevel;
extern Spyro g_Spyro;
extern int func_8001BA30(Vector3D*, int, int, int, int, Moby*);
extern int func_8004EDE8(Vector3D*, int);

/* Retail source: USA Rev 0 0x80036A68..0x80036E60 (254 words).
 * One call spawns and initializes one gem Moby. Position, velocity, collision,
 * and distance values remain in the raw signed integer units consumed by the
 * retail vector and collision helpers; random masks and all state transitions
 * execute once at their corresponding branch in this call. Confidence: exact.
 * Falsifiable test: compare all 254 words, the full PSX.EXE SHA-256, and every
 * corrected and encrypted overlay hash through build_multiproc.py. */
Moby* func_80036A68(Moby* arg0, int arg1, Vector3D* arg2, Vector3D* arg3) {
    Vector3D sp18;
    Vector3D sp28;
    register Moby* sourceMoby asm("$19");
    register Moby* spawnedMoby asm("$17");
    register Vector3D* requestedPosition asm("$20");
    register int temp_a0 asm("$4");
    register int var_a1 asm("$5");
    register int temp_v0_2 asm("$2");
    int var_a0;
    register int var_s0 asm("$16");
    int var_s2;
    register int var_v1 asm("$3");
    unsigned char temp_v0;
    register GemMobyTag* spawnedTag asm("$21");

    sourceMoby = arg0;
    __asm__("" : "=r"(sourceMoby) : "0"(sourceMoby));
    var_s2 = arg1;
    var_s0 = (int)arg2;
    requestedPosition = arg3;
    if (sourceMoby->gemValue == 0xFF) {
        return 0;
    }
    var_a0 = 1;
    if (sourceMoby->mobyClass == 0xB3) {
        var_a0 = 0x141;
    }
    spawnedMoby = SpawnMoby(var_a0, sourceMoby);
    __asm__ volatile("" : "=r"(spawnedMoby) : "0"(spawnedMoby) : "memory");
    spawnedTag = spawnedMoby->mobyTag;
    if (((g_CurrentLevel / 10) * 10) == (g_CurrentLevel - 8)) {
        spawnedMoby->mobyClass = 0x17D;
        spawnedMoby->unknown4 = 0;
    }
    spawnedMoby->state = 2;
    temp_v0 = D_80066964[sourceMoby->gemValue];
    spawnedMoby->substate = temp_v0;
    spawnedMoby->animationState.id = D_80066988[temp_v0 & 0xFF];
    spawnedMoby->colour.r = D_80066990[spawnedMoby->substate];
    spawnedTag->timer = 0xFF;
    if (var_s2 & 4) {
        spawnedTag->movementMode = 1;
    }
    if (var_s2 & 8) {
        spawnedTag->movementMode = 3;
    }
    if (var_s2 & 2) {
        spawnedTag->settleMode = 0;
    } else {
        spawnedTag->settleMode = 3;
    }
    temp_a0 = (int)&spawnedMoby->position;
    if (var_s0 != 0) {
        func_8004F178((Vector3D*)temp_a0, (Vector3D*)var_s0);
    } else {
        func_8004F178((Vector3D*)temp_a0, &sourceMoby->position);
        spawnedMoby->position.z += 0x100;
    }
    if ((g_CurrentLevel == 42) && (D_8006C5C8 == 1)) {
        var_s2 |= 16;
    }
    temp_a0 = (int)&sp18;
    if (requestedPosition == 0) {
        goto no_requested_position;
    }
    var_a1 = (int)requestedPosition;
    goto block_39;

no_requested_position:
    var_s0 = (int)&sp28;
    if ((var_s2 & 16) ||
            (!(var_s2 & 1) &&
             ((g_Spyro.movementState == MOVEMENT_STATE_CHARGE) ||
              (g_Spyro.movementState == MOVEMENT_STATE_SWIM_CHARGE) ||
              (g_Spyro.movementState == MOVEMENT_STATE_SKATEBOARD)))) {
        var_s0 = (int)&sp28;
        temp_a0 = var_s0;
        __asm__("" : "=r"(temp_a0) : "0"(temp_a0));
        requestedPosition = &spawnedMoby->position;
        func_8004F1C8((Vector3D*)temp_a0, requestedPosition, &g_Spyro.position);
        if ((var_s2 & 16) ||
                (func_8004EDE8((Vector3D*)var_s0, 1) < 0xA00)) {
            func_8004F504((Vector3D16*)((char*)spawnedTag + 4),
                          (Vector3D16*)requestedPosition);
            spawnedTag->randomX = rand() & 0xE;
            spawnedTag->randomY = rand() & 0xE;
            spawnedTag->randomZ = rand() & 0xE;
            spawnedMoby->state = 3;
            spawnedMoby->updateDistance = 0xFF;
            return spawnedMoby;
        }
    }

    var_s0 = 0;
    var_s2 = (int)&D_80071918;
loop_32:
    func_8004F178(&sp18, &sourceMoby->position);
    temp_v0_2 = rand();
    var_v1 = sp18.x;
    __asm__("" : "=r"(var_v1) : "0"(var_v1));
    temp_v0_2 &= 0x3FF;
    var_v1 -= 0x200;
    var_v1 += temp_v0_2;
    __asm__("" : "=r"(var_v1) : "0"(var_v1));
    sp18.x = var_v1;
    temp_v0_2 = rand();
    var_v1 = sp18.y;
    var_v1 -= 0x200;
    sp18.y = var_v1 + (temp_v0_2 & 0x3FF);
    sp18.z += 0x400;
    temp_v0_2 = func_8001A358(&sp18, 0x800);
    sp18.z = temp_v0_2;
    if ((temp_v0_2 <= 0) ||
            (func_8004E880(D_80071920, func_8004EDE8((Vector3D*)var_s2, 0), 0) >= 0x18) ||
            (func_8001BA30(&sp18, 0xC8, 0, 0, 0, sourceMoby) != 0)) {
        var_s0 += 1;
        if (var_s0 < 4) {
            goto loop_32;
        }
    }
    var_v1 = 0x8C;
    if (var_s0 == 4) {
        temp_a0 = (int)&sp18;
        var_a1 = (int)&sourceMoby->position;
block_39:
        func_8004F178((Vector3D*)temp_a0, (Vector3D*)var_a1);
        var_v1 = 0x8C;
    }
    temp_a0 = spawnedMoby->position.z;
    var_a1 = sp18.z;
    var_s0 = 0;
loop_41:
    temp_a0 += var_v1;
loop_42:
    var_v1 -= 10;
    var_s0 += 1;
    if (var_v1 > 0) {
        goto loop_41;
    }
    temp_v0_2 = var_a1 < temp_a0;
    temp_a0 += var_v1;
    if (temp_v0_2) {
        goto loop_42;
    }
    func_8004F1C8(&sp18, &sp18, &spawnedMoby->position);
    func_8004F228(&sp18, &sp18, var_s0);
    sp18.z = 0x8C;
    spawnedTag->velocityX = sp18.x;
    spawnedTag->velocityY = sp18.y;
    spawnedTag->velocityZ = sp18.z;
    return spawnedMoby;
}

void func_8003BA00(Moby*);
/* Retail source: USA Rev 0 0x80036E60..0x80037014 (109 words).
 * One call records one collected value; integer fields have no fixed-point scale.
 * Exact test: full PSX.EXE SHA-256 plus all overlay hashes in build_multiproc.py. */
void func_80036E60(Moby* arg0) {
    int gemValue;
    int temp_v0;
    register int temp_a1 __asm__("$5");
    int var_s0;
    unsigned char temp_v1;
    register Moby* var_a0 __asm__("$4");

    gemValue = D_80066980[arg0->substate];
    if (arg0->mobyClass != 0x141) {
        D_8006C71C += gemValue;
        D_80071A10[levelIndex] += gemValue;
    }
    D_8006E3B0[D_8006C6F8 & 0x1F] = arg0->substate;
    D_8006C6F8 += 1;
    if ((arg0->mobyClass == 1) && (arg0->position.z >= 0x300)) {
        func_80036708(gemValue, arg0);
    }
    if (arg0->mobyClass != 0x141) {
        temp_v1 = arg0->linkedMoby;
        if (temp_v1 != 0xFF) {
            var_s0 = temp_v1 + D_8006C79C;
            var_a0 = &D_8006C550[temp_v1];
        } else {
            var_a0 = arg0;
            temp_a1 = (unsigned int)var_a0 - (unsigned int)D_8006C550;
            temp_v0 = temp_a1 * -0x45D1745D;
            var_s0 = (temp_v0 >> 3) + D_8006C79C;
        }
        func_8003BA00(var_a0);
        temp_a1 = var_s0 & 0x1F;
        var_s0 >>= 5;
        D_80071AB0[levelIndex][var_s0] |= 1 << temp_a1;
    }
}

/**
 * ???() - func_80037014() - MATCHING
 * https://decomp.me/scratch/tufAO
 */
void func_80037014(Moby* moby) {
    moby->position.z = func_80035D38(moby) + moby->distanceToGround;
    func_80056270(moby);
    func_8005629C(moby);
}

extern int D_8006C644;
int func_80037058(int x, int y) {
    Vector3D planar;
    int distance;
    int phase;
    int value;
    planar.x = 0x1400 - (x % 10240);
    planar.y = 0x1400 - (y % 10240);
    distance = func_8004EDE8(&planar, 0);
    phase = 0xFF - (distance * 255) / 7241;
    phase += (D_8006C644 * 3) / 2;
    value = D_80065920[phase & 0xFF];
    return ((short)(value / 200)) << 2;
}

typedef struct {
    Vector3D target;
    short unkC;
    unsigned char active;
    unsigned char timer;
    unsigned char movement;
    unsigned char turnSpeed;
    unsigned char maxDistance;
    unsigned char angle;
    unsigned char timerLow;
    unsigned char timerHigh;
} MobyWanderStateRev0;

/* Retail evidence: USA Rev 0 PSX.EXE 0x80037168..0x80037324 (111 words).
 * Target and Moby positions are runtime integer coordinates; maxDistance is
 * stored in 16-unit steps, and timer/heading state advances once per call.
 * Confidence: exact. Falsifiable by the full-image hash and a word comparison
 * over this address span. */
void func_80037168(Moby* moby, MobyWanderStateRev0* state, int flags) {
    int movement = state->movement;
    int result;
    int distance;
    Vector3D* position;

    if (state->active == 0) {
        state->angle += func_8003636C(-0x20, 0x20);
        state->timer = func_8003636C(state->timerLow, state->timerHigh);
        state->active = 1;
    } else {
        func_8003585C(moby, state->angle, state->turnSpeed, 0, 1, 0);
        if (func_800359A4(&state->timer, 1) != 0) {
            state->active = 0;
        }
    }
    result = func_80035DDC(moby, movement, state->unkC, state->unkC, flags);
    position = &moby->position;
    distance = func_8004F334(position, &state->target);
    if ((result != 0) || ((state->maxDistance * 0x10) < distance)) {
        state->angle = func_8004E880(state->target.x - moby->position.x,
                                    state->target.y - moby->position.y, 0);
        state->timer = func_8003636C(0x1E, 0x5A);
        state->active = 1;
        return;
    }
    distance = func_8004F334(position, (Vector3D*)&D_80070328);
    if (distance < 0x1000) {
        state->angle = ((state->angle * distance) +
            (func_8004E880(moby->position.x - *(int*)(&D_80070328),
                           moby->position.y - *(int*)(&D_80070328 + 4), 0) *
             (0x1000 - distance))) >> 0xC;
    }
}

//////////////////////////////////////////////////////////////// jtbl section below
/*
80037324
Dialogue header
There's a few groups of data in the header, usually 2 bytes for each one
First byte is always the total length of the header, but the rest of the blocks are all iterated over (no early return unless otherwise stated), some other stuff happens after this if it doesn't return early
Block contents e.g. h[], e.g. h[0] for the first value

h[0]:
1 - 9 (2 bytes):
	eggNo = max(0, h[0] - 2)
	eggBm = 1 << (eggNo & 0x1f);
	If egg bitmask eggBm has been collected since entering + some other condition involving 8006c62c (?):
		nextMsg = this message;
		Spawn moby class h[1];
		Some other stuff
	h[0] = 1 and 2 therefore seem to do the same thing? and this supports up to 8 eggs

0x23 (3 bytes):
	Just jump over this // both other bytes unused?

0x24 (2 bytes):
	if (h[1] == 1)
		var = EggsCollectedSinceEnteredBitmask & 1;
		if (var != 0)
			nextMsg = this message;
			h[1] = 0xff; DAT_8006c624 = 0xffffffff; DAT_8006c798 = 0; DAT_8006c608 = 0;
			FUN_8003b7b4(&h[1],1,&CurrentCheckpointData);
	else if (h[1] - 1 < 10) // I think 0 is excluded here // seems to be indicating an egg number
		if (EggsCollectedSinceEnteredBitmask & (1 << (h[1] - 2 & 0x1f)))
			nextMsg = this message;
			h[1] = 0xff; DAT_8006c624 = 0xffffffff; DAT_8006c798 = 0; DAT_8006c608 = 0;
			FUN_8003b7b4(&h[1],1,&CurrentCheckpointData);	  
	else if (h[1] - 1 < 0x14) // I think 0 is excluded here
		var = *(byte *)((int)&CameraPosition_800719f0.Pos.ρ + h[1] + 1); // no idea
		if (var != 0)
			nextMsg = this message;
			h[1] = 0xff; DAT_8006c624 = 0xffffffff; DAT_8006c798 = 0; DAT_8006c608 = 0;
			FUN_8003b7b4(&h[1],1,&CurrentCheckpointData);

0x25 (8 bytes):
	if (nextMsg == this message)
		var = h[6] - 1; // Moneybags level ID		
		if (var != 0xfe)
			DAT_8006c59c = MoneybagsValues[var].Value;
			DAT_8006c750 = 1;
			if (!MoneybagsValues[var].Paid && TotalGems < MoneybagsValues[var].Value)
				nextMsg = h[7] - 1;
				return; // EARLY RETURN

		DAT_8006c6e4 = 0;
		for (var = 0; var < 5; var++)
			if (h[1 + var] != 0xff) DAT_8006c6e4++;

0x26 (1 byte):
	if (this message == nextMsg) DAT_8006c5fc = 1;

0x27 (2 bytes):
	if (this message == nextMsg)
		DialogueBitmaskArray[LevelNumber] = // not sure this is ever actually used!
			DialogueBitmaskArray[LevelNumber] | (1 << ((h[1] - 1) & 0x1f));

0x29 (2 bytes):
	if (nextMsg == this message) DAT_8006c624 = 1; // second byte unused?

0x2a - 0x2b (1 byte):
	Just jump over this

0x2c (2 bytes):
	if (this message == nextMsg) DAT_8006c590 = h[1] - 1; // dialogue camera, many different possible angles

0x2d (2 bytes):
	if (nextMsg == this message) DAT_8006c608 = h[1] - 1;

0x3b (1 byte):
	DAT_8006c798 = 1; // used for instance when Zoe demonstrates saving to the player

Default:
	Repeat?

TODO: investigate what the headers are for each line of dialogue
*/
INCLUDE_ASM("asm/nonmatchings/mobyutil", func_80037324);

/* Retail source: USA Rev 0 PSX.EXE 0x80037768..0x80037A60
 * (190 instruction words), body SHA-256
 * F5F22629324F1DBCCCF4A53EEF4A260B71117BA83F30191E5DA0F6817D92BF42.
 * The two 26-word tables at 0x8001040C and 0x80010474 have combined raw
 * SHA-256 815EBB0309969E292E32F77A81A8BC23FF71244B5A71F446CF5D16EE4A5E882F.
 * Stream lengths and opcodes are bytes; encoded selection values are reduced
 * by one, while D_8006C71C and table halfwords remain raw integer units. Each
 * stream is parsed once per call. Confidence: confirmed by an exact 227-record
 * instruction/relocation comparison. Falsifiable vectors cover empty streams,
 * opcodes 0x23/0x25/0x26/0x29/0x2A/0x2B/0x3B, the two-byte default, equal and
 * unequal 0x23 bounds, selector values zero/nonzero, item 0xFE, insufficient
 * D_8006C71C, and selected bytes below/above 0x80. */
extern int D_8006C76C, D_8006C71C;
extern short D_8006C57C;
extern unsigned char D_8006C7A4;
extern char D_8006C7F8;
extern short D_80066EAC[];
extern short D_80066EAE[];
extern int func_8003636C(int, int);
extern void func_8003B7B4(void*, int, void*);
void func_80037768(void* arg) {
    unsigned char* state = *(unsigned char**)arg;
    unsigned char* cursor;
    unsigned char* end;
    int values[5];
    register int* valuesBase __asm__("$21");
    register int low __asm__("$18");
    register int high __asm__("$17");
    register int selected __asm__("$2");

    {
        register int offset __asm__("$2") = state[2];
        register int tableOffset __asm__("$3") = D_8006C76C;
        tableOffset <<= 2;
        offset <<= 2;
        offset += (int)state;
        offset += tableOffset;
        cursor = *(unsigned char**)(offset + 0x10);
    }
    end = cursor + cursor[0];
    cursor++;
    if (cursor < end) {
        valuesBase = values;
        do {
        switch (*cursor) {
        case 0x2A:
            state[5] = 0xFF;
            func_8003B7B4(state + 5, 1, &D_8006C7F8);
            cursor++;
            break;
        case 0x26:
        case 0x2B:
        case 0x3B:
            cursor++;
            break;
        case 0x29:
            state[2] = cursor[1] - 1;
            cursor += 2;
            break;
        case 0x23:
            {
                register int first __asm__("$2") = cursor[1];
                register int second __asm__("$3") = cursor[2];
                low = first - 1;
                high = second - 1;
            }
            if (low != high) {
                selected = func_8003636C(low, high);
                if (state[2] == selected) {
                    state[2]++;
                    selected = high < state[2];
                    if (selected)
                        state[2] = low;
                }
            } else {
                state[2] = low;
            }
            cursor += 3;
            break;
        case 0x25:
            {
                register int itemByte __asm__("$2") = cursor[6];
                register int item __asm__("$6") = itemByte - 1;
                register int fallback __asm__("$3") = cursor[7] - 1;
                register int i __asm__("$4") = 0;
                register int* output __asm__("$5") = valuesBase;
                register unsigned char* entry __asm__("$2");
                do {
                    entry = cursor + i;
                    *output = entry[1] - 1;
                    i++;
                    output++;
                } while (i < 5);
            state[2] = valuesBase[D_8006C57C];
            if (D_8006C57C == 0 && item != 0xFE) {
                int cost = D_80066EAC[item * 2];
                if (D_8006C71C >= cost) {
                    D_8006C71C -= cost;
                    D_80066EAE[item * 2] = 1;
                } else {
                    state[2] = fallback;
                }
            }
            }
            if (state[2] >= 0x80) {
                state[2] += 0x80;
                D_8006C7A4 = 0;
            }
            cursor += 8;
            break;
        default:
            cursor += 2;
            break;
        }
        } while (cursor < end);
    }

    {
        register int offset __asm__("$2") = state[2];
        register int tableOffset __asm__("$3") = D_8006C76C;
        offset <<= 2;
        offset += (int)state;
        tableOffset <<= 2;
        offset += tableOffset;
        cursor = *(unsigned char**)(offset + 0x10);
    }
    end = cursor + cursor[0];
    cursor++;
    while (cursor < end) {
        switch (*cursor) {
        case 0x2B:
            state[5] = 2;
            cursor++;
            break;
        case 0x26:
        case 0x2A:
        case 0x3B:
            cursor++;
            break;
        case 0x23:
            cursor += 3;
            break;
        case 0x25:
            cursor += 8;
            break;
        default:
            cursor += 2;
            break;
        }
    }
    func_8003B7B4(state + 2, 1, &D_8006C7F8);
}

/* Retail source: asm/nonmatchings/mobyutil/func_80037A60.s,
 * 0x80037A60..0x80037BBC. Values use raw integer storage;
 * D_8006C648 products shift right by one. Cadence is once per call. */
int func_80037A60(Moby* moby, void* state, int widthArg, int decrementArg, int minimum) {
    register int width asm("$18") = widthArg;
    register int decrement asm("$17") = decrementArg;
    int ground = func_80035D38(moby);
    int step = (decrement * D_8006C648) >> 1;
    int velocity;
    volatile char compilerLocal[1]; /* preserves the retail 48-byte frame */
    if (width == 4) {
        int old;
        old = *(int*)state;
        velocity = old;
        *(int*)state = old - step;
        if (*(int*)state < minimum) *(int*)state = minimum;
    } else if (width == 2) {
        int old;
        old = *(short*)state;
        velocity = old;
        *(short*)state = old - step;
        if (*(short*)state < minimum) *(short*)state = minimum;
    } else {
        register int byteOld asm("$2");
        byteOld = *(unsigned char*)state;
        __asm__("" : "=r"(byteOld) : "0"(byteOld));
        velocity = byteOld & 0xFF;
        *(unsigned char*)state = byteOld - step;
        if (*(unsigned char*)state < minimum) *(unsigned char*)state = minimum;
    }
    velocity = (velocity * D_8006C648) >> 1;
    if (velocity <= 0 && moby->position.z - moby->distanceToGround + velocity < ground) {
        moby->position.z = ground + moby->distanceToGround;
        return 1;
    }
    moby->position.z += velocity;
    return 0;
}

/* Retail source: USA Rev 0 PSX.EXE 0x80037BBC..0x80037F50 (229 instructions),
 * raw SHA-256 7E27B7113ACFEA112F48427CC3E49A462FE3F92825ADEE56D50691EBDCF8632C.
 * Evaluates a Moby's talk prompt once per call. Positions and distance limits
 * are signed world units; facing limits are 12-bit angle deltas and flags are
 * the retail bitfield (1, 2, 4, 8). Confidence: confirmed by an exact 229-word
 * comparison, the linked USA Rev 0 EXE, and all 62 manifest hashes. Falsifiable
 * vectors: tag states 0/2/255; distances 0x4FF/0x500/0x9FF/0xA00/0xBB3/0xBB4;
 * both vertical bounds; facing deltas 0x20/0x40/0x48/0x80; player states
 * 4/9/11/19; pause gates; prompt age 9/10; and input bit 0x10. */
extern int D_8006C74C, D_8006C64C, D_8006E344, D_8006C640;
extern int D_8006C508, D_8006E53C;
extern char D_8006D088, D_8006C7F8;
int func_8004F334(Vector3D*, Vector3D*);
void func_8003B7B4(void*, int, void*);
void func_80037F50(Moby*);
int func_80037BBC(Moby* moby, int flags) {
    unsigned char* tag = moby->mobyTag;
    int distance = func_8004F334(&moby->position, (Vector3D*)&D_80070328);
    int enabled;
    int upper;
    int lower;
    int nearFacing;
    int farFacing;
    int previousPrompt;
    int angle;

    if (tag[5] == 0xFF) {
        tag[7] = 0;
        return 0;
    }
    if (tag[5] == 2) {
        if (distance >= 0xBB4) return 0;
    } else if (distance >= 0xA00) {
        return 0;
    }

    previousPrompt = tag[7];
    tag[7] = 0;
    enabled = ((flags & 1) != 0 || *(int*)(&D_80070328 + 0xB8) == 0);
    {
        register int retailUpper __asm__("$5");
        __asm__ volatile (
            "lh $2,56(%1)\n"
            "lw $3,20(%1)\n"
            "nop\n"
            "subu %0,$3,$2"
            : "=r"(retailUpper) : "r"(moby) : "$2", "$3");
        upper = retailUpper;
        lower = upper;
    }
    if (flags & 8) lower -= 0x320;
    if (*(int*)(&D_80070328 + 0x50) == 11) {
        upper += 0x708;
        lower -= 0x190;
        enabled = 1;
    } else {
        int playerOffset = *(int*)(&D_80070328 + 0x44);
        upper += 0x1BC + playerOffset;
        lower += -0x164 + playerOffset;
    }
    if (distance < 0x500) {
        nearFacing = 0x40;
        farFacing = 0x80;
    } else {
        nearFacing = 0x20;
        farFacing = 0x48;
    }
    if (!enabled) return 0;
    if (upper < *(int*)(&D_80070328 + 8) || *(int*)(&D_80070328 + 8) < lower) return 0;
    if (!(flags & 2)) {
        angle = func_8004E880(*(int*)&D_80070328 - moby->position.x,
                             *(int*)(&D_80070328 + 4) - moby->position.y, 0);
        if (func_8004F264(moby->angle.yaw, angle) > nearFacing) return 0;
    }
    angle = func_8004E880(moby->position.x - *(int*)&D_80070328,
                         moby->position.y - *(int*)(&D_80070328 + 4), 0);
    if (func_8004F264(*(unsigned char*)(&D_80070328 + 0xE), angle) > farFacing) return 0;
    if (moby->drawn == 0) return 0;
    if (*(int*)(&D_80070328 + 0x50) == 0x13) return 0;
    if ((D_8006C74C != 0 || D_8006C64C != 0) && tag[5] != 2) return 0;
    if (D_8006E344 != 0) return 0;
    if (!(flags & 4) && *(int*)(&D_80070328 + 0x50) == 4) return 0;
    if (*(int*)(&D_80070328 + 0x50) == 9) return 0;
    if (D_8006C640 < 10 && tag[5] != 0 && D_8006C508 != 0 && tag[2] != 0) tag[5] = 0;
    if ((D_8006E53C & 0x10) != 0 || tag[5] != 0) {
        if (tag[5] == 2) *(int*)(&D_80070328 + 0x20C) |= 0x10000002;
        tag[5] = 0;
        tag += 5;
        func_8003B7B4(tag, 1, &D_8006D088);
        func_8003B7B4(tag, 1, &D_8006C7F8);
        return 1;
    }
    if (previousPrompt == 0) func_80037F50(moby);
    tag[7] = 2;
    return 0;
}

/**
 * SpawnTalkText() - func_80037F50() - MATCHING
 * https://decomp.me/scratch/IWP83
 */
void func_80037F50(Moby* arg0) {
    int var_s1;
    Moby* temp_v0;

    for (var_s1 = 0; var_s1 < 7; var_s1++) {
        temp_v0 = SpawnMoby(311, arg0);
        *(Moby**)temp_v0->mobyTag = arg0;
        temp_v0->animationState.id = D_80067554[var_s1].model;
        temp_v0->substate = var_s1;
        temp_v0->position.z = temp_v0->position.z - 0xA00;
        temp_v0->colour.r = D_80067554[var_s1].colour;
        temp_v0->unknown4 = 4;
    }
}

/* Retail source: USA Rev 0 PSX.EXE 0x80038000..0x800382F4 (189 words).
 * Tests a candidate world-space position against collision and ground results,
 * then conditionally applies it to the moby. Coordinates and height deltas are
 * signed integer world units; arg4 is a behavior bitfield evaluated once per
 * caller invocation. Confirmed by an exact 189/189 instruction comparison;
 * falsify with any word mismatch in this span or a different retail revision. */
int func_80038000(Moby *arg0, Vector3D *arg1, int arg2, int arg3, int arg4)
{
  register int vertical asm("$18");
  register int result asm("$17");
  register int collision asm("$20");
  int difference;
  int angle;
  result = 0;
  if (arg4 & 1)
  {
    arg1->z += 0x12C + arg2;
  }
  if ((arg3 != 0) && (!(arg4 & 0x4000)))
  {
    collision = func_8001BA30(arg1, arg3, 0, 0, 0, arg0);
  }
  else
  {
    collision = 0;
  }
  if (collision != 0)
  {
    result |= 0x20;
    if (!(arg4 & 2))
    {
      goto store_collision;
    }
    func_8004F178(arg1, &D_8007190C);
  }
  if ((arg2 != 0) && (func_80019194(arg1, arg2) != 0))
  {
    result |= 0x10;
    if (!(arg4 & 0x20))
    {
      goto done;
    }
    func_8004F178(arg1, &D_8007190C);
  }
  if ((arg4 & 0x400) && (func_80018368(&arg0->position, arg1) != 0))
  {
    result |= 0x10;
    goto done;
  }
  if (arg4 & 1)
  {
    arg1->z -= 0x12C + arg2;
  }
  arg1->z += 0x400;
  vertical = func_8001A358(arg1, 0x2000);
  if (arg4 & 0x1000)
  {
    arg1->z -= 0x400;
  }
  if (arg4 & 0x10)
  {
    int currentZ = arg0->position.z;
    int combined = vertical + arg0->distanceToGround;
    difference = combined - currentZ;
    if (difference < 0)
    {
      goto negative_height;
    }
    if (difference >= 0x191)
    {
      goto height_fail;
    }
    goto height_ok;
    negative_height:
    difference = currentZ - combined;

    if (difference < 0x191)
    {
      goto height_ok;
    }
    height_fail:
    asm volatile("" : "=r"(result) : "0"(result));

    result |= 0x40;
    goto done;
  }
  height_ok:
  if (arg4 & 0x200)
  {
    difference = (vertical + arg0->distanceToGround) - arg0->position.z;
    if (difference < 0xC9)
    {
      goto angle_check;
    }
    asm volatile("" : "=r"(result) : "0"(result));
    result |= 0x40;
    goto done;
  }

  angle_check:
  if (arg4 & 0x40)
  {
    register int magnitude asm("$2");
    angle = func_8004E880(func_8004EDE8(&D_80071918, 0), D_80071920, 0);
    if (angle >= 0x81)
    {
      angle -= 0x100;
    }
    magnitude = angle;
    if (angle < 0)
    {
      magnitude = -magnitude;
    }
    if (magnitude < 0x17)
    {
      result |= 0x40;
      goto done;
    }
  }

  arg0->position.x = arg1->x;
  arg0->position.y = arg1->y;
  if (arg4 & 4)
  {
    int oldZ = arg0->position.z;
    register int temp_v0 asm("$2");
    temp_v0 = vertical + arg0->distanceToGround;
    vertical = temp_v0 - oldZ;
    temp_v0 = vertical < (-0xFA);
    if (temp_v0)
    {
      vertical = -0xFA;
      asm volatile("" : "=r"(vertical) : "0"(vertical));
      temp_v0 = vertical < 0xFB;
    }
    else
    {
      temp_v0 = vertical < 0xFB;
    }
    if (temp_v0)
    {
      temp_v0 = oldZ + vertical;
      goto assign_z;
    }
    vertical = 0xFA;
    asm volatile("" : "=r"(vertical) : "0"(vertical));
    temp_v0 = oldZ + vertical;
    assign_z:
    arg0->position.z = temp_v0;

  }
  else
    if (arg4 & 0x1000)
  {
    arg0->position.z = arg1->z;
  }
  asm volatile("" : "=r"(arg4) : "0"(arg4));
  func_80056270(arg0);
  func_8005629C(arg0);
  func_80055D24(arg0, 2);
  done:
  if (collision != 0)
  {
    store_collision:
    D_80071930 = collision;
    asm volatile("" : : : "memory");
  }

  return result;
}

INCLUDE_ASM("asm/nonmatchings/mobyutil", func_800382F4);

/* Retail source: USA Rev 0 PSX.EXE 0x800387AC..0x80038B44 (230 instructions).
 * Disc identity: SHA-256 e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f.
 * Raw function words SHA-256: 1b61fbbfc7bfbd74999c981e92bbe44da72414c83caea430fa808b5f8b9eecbe.
 * Polygon line coefficients and projections use signed Q10 arithmetic; input/output points
 * and maxDistance are runtime integer coordinates. Each call tests every 28-byte edge
 * until an accepted projection or terminal endpoint condition is found. Confidence: exact.
 * Falsify with any mismatch among the 230 opcodes, seven function-relative relocations,
 * or the linked executable hash above; test vectors include inside-edge, endpoint-wrap,
 * rejected half-plane, optional angle output, and distance-threshold paths. */
int func_800387AC(unsigned char* polygon, int* point, int* projected,
                  int* projectedAngle, volatile int referenceAngle, volatile int maxDistance) {
    register unsigned char* shape __asm__("$21") = polygon;
    register int* source __asm__("$18") = point;
    register int* output __asm__("$19") = projected;
    register int firstEndpoint = ({
        int zero;
        __asm__ ("move %0,$0" : "=r"(zero) : "r"(shape), "r"(source), "r"(output));
        zero;
    });
    register int previousEndpoint __asm__("$23") = ({
        int zero;
        __asm__ ("move %0,$0" : "=r"(zero) : "r"(firstEndpoint));
        zero;
    });
    register int index __asm__("$20");
    register int offset __asm__("$22");
    register int* edge __asm__("$16");
    register int angle __asm__("$17");
    int delta[2];
    int closest[2];
    struct {
        int* angleOutput;
        int pad;
        int result;
    } local;
    int count;
    local.angleOutput = projectedAngle;
    local.result = 0;

    index = 0;
    if (index >= shape[1]) goto done_387ac;
    offset = 12;
loop_387ac:
    {
        int distance;
        int projection;
        register int deltaY __asm__("$3");
        register int edgeY __asm__("$2");
        edge = (int*)(shape + offset);
        __asm__ volatile ("" : "=r"(edge) : "0"(edge));
        delta[0] = source[0] - edge[2];
        deltaY = source[1];
        edgeY = edge[3];
        deltaY = deltaY - edgeY;
        delta[1] = deltaY;
        __asm__ volatile ("" : : "m"(delta[1]));
        if (edge[0] * deltaY - edge[1] * delta[0] <= 0) {
            goto reset_endpoint_387ac;
        }
        projection = (edge[6] + (edge[4] * source[0] + edge[5] * source[1])) >> 10;
        output[0] = source[0] - ((projection * edge[4]) >> 10);
        projection = projection * edge[5];
        output[1] = source[1] - (projection >> 10);
        distance = func_8004F334((Vector3D*)output, (Vector3D*)source);
        angle = func_8004E880(edge[0], edge[1], 0);
        {
            register int difference __asm__("$2") = func_8004F264(angle, referenceAngle);
            __asm__ volatile (
                "slti $2,%2,65\n"
                "bnez $2,.Langle_done_387ac\n"
                "addiu $2,%0,128\n"
                "andi %0,$2,255\n"
                ".Langle_done_387ac:"
                : "=r"(angle) : "0"(angle), "r"(difference) : "$2");
        }

        if (output[0] > edge[2] && output[0] > edge[2] + edge[0]) goto outside_edge;
        if (output[0] < edge[2] && output[0] < edge[2] + edge[0]) goto outside_edge;
        if (output[1] > edge[3] && output[1] > edge[3] + edge[1]) goto outside_edge;
        if (output[1] < edge[3] && output[1] < edge[3] + edge[1]) goto outside_edge;
        {
            register int withinDistance __asm__("$2") = func_8004F334((Vector3D*)output, (Vector3D*)source);
            __asm__ volatile (
                "lw $8,%1\n"
                "nop\n"
                "slt %0,%0,$8"
                : "=r"(withinDistance) : "m"(maxDistance), "0"(withinDistance));
            if (withinDistance) {
                __asm__ volatile (
                    "lw $8,%1\n"
                    "nop\n"
                    "beqz $8,1f\n"
                    "nop\n"
                    "sw %2,0($8)\n"
                    "1:\n"
                    "li $8,1\n"
                    ".word 0x08000000\n"
                    ".reloc .-4,R_MIPS_26,.Ldone_387ac\n"
                    "sw $8,%0"
                    : "=m"(local.result)
                    : "m"(local.angleOutput), "r"(angle)
                    : "memory");
            }
        }
outside_edge:
        {
            register int minX __asm__("$7");
            register int maxX __asm__("$5");
            register int minY __asm__("$6");
            register int maxY __asm__("$4");
            register int endpoint __asm__("$3");
            register int base __asm__("$4");
            register int extent __asm__("$2");
            base = edge[2];
            extent = edge[0];
            minX = base;
            endpoint = base + extent;
            if (endpoint < minX) minX = endpoint;
            maxX = base;
            if (maxX < endpoint) maxX = endpoint;
            base = edge[3];
            extent = edge[1];
            minY = base;
            endpoint = base + extent;
            if (endpoint < minY) minY = endpoint;
            maxY = base;
            if (maxY < endpoint) maxY = endpoint;
            closest[0] = output[0];
            closest[1] = output[1];
            if (maxX < closest[0]) closest[0] = maxX;
            if (maxY < closest[1]) closest[1] = maxY;
            if (closest[0] < minX) closest[0] = minX;
            if (closest[1] < minY) closest[1] = minY;
            {
                register int exceedsDistance __asm__("$2") = func_8004F334((Vector3D*)closest, (Vector3D*)source);
                __asm__ volatile (
                    "lw $8,%1\n"
                    "nop\n"
                    "slt %0,$8,%0"
                    : "=r"(exceedsDistance) : "m"(maxDistance), "0"(exceedsDistance));
                if (!exceedsDistance) {
                    if (index == shape[1] - 1 && firstEndpoint != 0) return 0x2000;
                    if (previousEndpoint != 0) return 0x2000;
                    previousEndpoint = 1;
                    if (index == 0) firstEndpoint = 1;
                }
            }
        }
        goto increment_387ac;
reset_endpoint_387ac:
        previousEndpoint = 0;
increment_387ac:
        count = shape[1];
        index++;
        if (index < count) {
            offset += 28;
            goto loop_387ac;
        }
    }
done_387ac:
    __asm__ volatile (".Ldone_387ac:");
    return local.result;
}

/**
 * CalculateAtlasPercentage() - func_80038B44() - MATCHING
 * https://decomp.me/scratch/BzAVm
 */
int func_80038B44(int lvlIndex, int gems, int eggs) {
    int num;
    int den;
    int percentage;

    int gemTotal;
    int eggTotal;

    gemTotal = D_80066F54[lvlIndex] * 25;
    num = gems + eggs * 100;
    eggTotal = D_80066F7C[lvlIndex] * 25;
    
    den = (eggTotal + gemTotal) * 4;
    percentage = (num * 100/*%*/) / den;
    
    if ((num != 0) && (percentage == 0)) {
        percentage = 1;
    }
    return percentage;
}

typedef struct {
    unsigned char pad0[4];
    short unk4;
    short unk6;
    unsigned char pad8[6];
    unsigned char unkE;
    unsigned char unkF;
    unsigned char pad10;
    unsigned char unk11;
    unsigned char pad12;
    unsigned char unk13;
    unsigned char unk14;
    unsigned char unk15;
    unsigned char unk16;
    signed char unk17;
} MobyStateSetup;

/* Retail source: USA Rev 0 PSX.EXE 0x80038BF8..0x80038F14 (199 words).
 * Initializes an enemy hit-motion descriptor when its requested animation
 * differs from the active state. Descriptor fields are bytes and halfwords;
 * damage flags select the exact duration adjustment once per invocation.
 * Confirmed by an exact 199/199 instruction comparison and all 62 retail
 * hashes; falsify with any mismatch in this span or a different revision. */

void func_80038BF8(Moby* arg0, EnemyTag* arg1, int arg2, int arg3) {
    register Moby* moby __asm__("$16") = arg0;
    register MobyStateSetup* setup __asm__("$17") = (MobyStateSetup*)arg1;
    unsigned int mode = arg2;
    int animation = arg3;
    register int temp_v0 __asm__("$2");
    register int temp_v1 __asm__("$3");
    register int base __asm__("$4");
    register int animationOffset __asm__("$5");
    unsigned char value;
    register unsigned int first __asm__("$2");
    int flag;
    int firstRandom;
    int secondRandom;
    int randomLow;
    int randomHigh;
    int damageFlags;
    /* Preserves the retail 0x30-byte frame and otherwise-unused 8-byte local. */
    volatile int stackPad[2];

    if (moby->state != animation) {
        moby->updateDistance = 0xFF;
        moby->subtype = 0xFF;
        setup->unk4 = 0x10E;
        value = moby->unkb;
        if (value == 0) {
            value = func_800360F8(
                func_8004E880(moby->position.x - ((Spyro*)&D_80070328)->position.x,
                              moby->position.y - ((Spyro*)&D_80070328)->position.y, 0),
                ((Spyro*)&D_80070328)->bodyRotation.yaw, 0x20, 0x40);
        }
        setup->unk11 = value;
        setup->unk6 = 0;
        __asm__ volatile ("" ::: "memory");
        animationOffset = animation * 4;
        temp_v0 = moby->mobyClass;
        temp_v1 = moby->animationState.id;
        temp_v0 <<= 2;
        temp_v0 = *(int*)((char*)D_8006EE2C + temp_v0);
        temp_v1 <<= 2;
        temp_v1 += temp_v0;
        temp_v0 = animationOffset + temp_v0;
        temp_v1 = *(int*)(temp_v1 + 0x3C);
        temp_v0 = *(int*)(temp_v0 + 0x3C);
        temp_v1 = *(unsigned char*)(temp_v1 + 4);
        temp_v0 = *(unsigned char*)(temp_v0 + 4);
        base = (int)D_8006EE2C;
        if (temp_v1 != temp_v0) {
            temp_v1 = 1;
            __asm__ volatile ("" ::: "memory");
            temp_v0 = moby->mobyClass;
            moby->state = animation;
            temp_v0 <<= 2;
            temp_v0 += base;
            temp_v0 = *(int*)temp_v0;
            temp_v0 = animationOffset + temp_v0;
            temp_v0 = *(int*)(temp_v0 + 0x3C);
            first = *(unsigned char*)temp_v0;
            __asm__ volatile ("" : "=r"(first) : "0"(first));
            moby->animationState.id = animation;
            moby->animationState.nextId = animation;
            moby->animationState.frame = 0;
            moby->animationState.nextFrame = temp_v1;
            __asm__ volatile ("" : "=r"(first) : "0"(first), "m"(moby->animationState.nextFrame));
            flag = first < 2;
            __asm__ volatile ("" : "=r"(flag) : "0"(flag));
            flag ^= 1;
            flag = -flag;
            moby->animationProgress = flag & 0x30;
        } else {
            moby->state = animation;
            func_80034F40(moby, animation);
        }

        damageFlags = moby->damageFlags;
        if (damageFlags & 0x02000000) {
            setup->unk4 = (unsigned short)setup->unk4 + 0xB4;
        } else if (damageFlags & 0x00020000) {
            setup->unk4 = (unsigned short)setup->unk4 + 0x8C;
        }

        switch (mode) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
            break;
        case 1:
            setup->unk13 = 1;
            setup->unk15 = animation;
            setup->unk14 = animation;
            setup->unk6 = 0xC8;
            if (moby->damageFlags & 0x00020000) {
                setup->unk6 = 0xF0;
            }
            break;
        case 6:
            setup->unk13 = 1;
            setup->unk15 = animation;
            setup->unk14 = animation;
            setup->unk6 = 0xC8;
            if (moby->damageFlags & 0x00020000) {
                setup->unk6 = 0xF0;
            }
            setup->unk16 = func_8003636C(0x28, 0x46);
            break;
        case 7:
            setup->unk13 = 1;
            setup->unk15 = animation;
            setup->unk14 = animation;
            setup->unk6 = 0xC8;
            if (moby->damageFlags & 0x00020000) {
                setup->unk6 = 0xF0;
            }
            temp_v0 = func_8003636C(0x28, 0x46);
            randomLow = 8;
            randomHigh = 0xF;
            setup->unk16 = temp_v0;
            goto randomize_38bf8;
        case 8:
            setup->unk13 = 1;
            setup->unk15 = animation;
            setup->unk14 = animation;
            setup->unk6 = 0xC8;
            if (moby->damageFlags & 0x00020000) {
                setup->unk6 = 0xF0;
            }
            setup->unk16 = func_8003636C(0x28, 0x46);
            randomLow = 8;
            setup->unk15 = setup->unk14 + 1;
            randomHigh = 0xF;
randomize_38bf8:
            firstRandom = func_800363DC(randomLow, randomHigh);
            secondRandom = func_800363DC(8, 0xF);
            setup->unk17 = ((firstRandom / 2) * 0x10) + ((secondRandom / 2) & 0xF);
            break;
        }
    }
}

/* Retail source: USA Rev 0 PSX.EXE 0x80038F14..0x800391E8 (181 words).
 * Initializes a moby state and its caller-owned 0x18-byte animation/effect
 * control block once when the requested state differs. Mode is an unsigned
 * switch selector; animation/state values and packed random values are bytes,
 * durations are signed 16-bit values, and the routine advances once per call.
 * Confirmed by an exact 181/181 instruction comparison; falsify with any word
 * mismatch in that address span or a nonmatching retail executable. */
void func_80038F14(Moby* arg0, void* arg1, unsigned int arg2, int arg3) {
    register Moby* moby __asm__("$18") = arg0;
    register MobyStateSetup* setup __asm__("$17") = arg1;
    unsigned int mode = arg2;
    int animation = arg3;
    register int temp_v0 __asm__("$2");
    register int temp_v1 __asm__("$3");
    register int base __asm__("$4");
    register int animationOffset __asm__("$5");
    unsigned char value;
    register unsigned int first __asm__("$2");
    int flag;
    int firstRandom;
    int secondRandom;
    int randomLow;
    int randomHigh;
    /* Preserves the retail 0x30-byte frame and otherwise-unused 8-byte local. */
    volatile int stackPad[2];

    if (moby->state != animation) {
        moby->updateDistance = 0xFF;
        setup->unk4 = 0x96;
        setup->unkE = 5;
        value = moby->unkb;
        if (value == 0) {
            value = func_800360F8(
                func_8004E880(moby->position.x - ((Spyro*)&D_80070328)->position.x,
                              moby->position.y - ((Spyro*)&D_80070328)->position.y, 0),
                ((Spyro*)&D_80070328)->bodyRotation.yaw, 0x20, 0x40);
        }
        setup->unk11 = value;
        setup->unk6 = 0;
        __asm__ volatile ("" ::: "memory");
        animationOffset = animation * 4;
        temp_v0 = moby->mobyClass;
        temp_v1 = moby->animationState.id;
        temp_v0 <<= 2;
        temp_v0 = *(int*)((char*)D_8006EE2C + temp_v0);
        temp_v1 <<= 2;
        temp_v1 += temp_v0;
        temp_v0 = animationOffset + temp_v0;
        temp_v1 = *(int*)(temp_v1 + 0x3C);
        temp_v0 = *(int*)(temp_v0 + 0x3C);
        temp_v1 = *(unsigned char*)(temp_v1 + 4);
        temp_v0 = *(unsigned char*)(temp_v0 + 4);
        base = (int)D_8006EE2C;
        if (temp_v1 != temp_v0) {
            temp_v1 = 1;
            __asm__ volatile ("" ::: "memory");
            temp_v0 = moby->mobyClass;
            moby->state = animation;
            temp_v0 <<= 2;
            temp_v0 += base;
            temp_v0 = *(int*)temp_v0;
            temp_v0 = animationOffset + temp_v0;
            temp_v0 = *(int*)(temp_v0 + 0x3C);
            first = *(unsigned char*)temp_v0;
            __asm__ volatile ("" : "=r"(first) : "0"(first));
            moby->animationState.id = animation;
            moby->animationState.nextId = animation;
            moby->animationState.frame = 0;
            moby->animationState.nextFrame = temp_v1;
            __asm__ volatile ("" : "=r"(first) : "0"(first), "m"(moby->animationState.nextFrame));
            flag = first < 2;
            __asm__ volatile ("" : "=r"(flag) : "0"(flag));
            flag ^= 1;
            flag = -flag;
            moby->animationProgress = flag & 0x30;
        } else {
            moby->state = animation;
            func_80034F40(moby, animation);
        }
        switch (mode) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
            break;
        case 1:
            setup->unk13 = 1;
            setup->unk6 = 0xE6;
            setup->unk4 = 0x78;
            setup->unkE = 3;
            setup->unk15 = animation;
            setup->unk14 = animation;
            setup->unkF = 0x17;
            break;
        case 6:
            setup->unk13 = 1;
            setup->unk6 = 0xE6;
            setup->unk15 = animation;
            setup->unk14 = animation;
            setup->unkF = 0x17;
            setup->unk16 = func_8003636C(0x28, 0x46);
            break;
        case 7:
            setup->unk6 = 0xE6;
            setup->unk16 = func_8003636C(0x28, 0x46);
            randomLow = 8;
            randomHigh = 0xF;
            goto randomize;
        case 8:
            setup->unk13 = 1;
            setup->unk15 = animation;
            setup->unk14 = animation;
            setup->unk6 = 0xC8;
            if (moby->damageFlags & 0x20000) {
                setup->unk6 = 0xF0;
            }
            setup->unk16 = func_8003636C(0x28, 0x46);
            randomLow = 8;
            setup->unk15 = setup->unk14 + 1;
            randomHigh = 0xF;
randomize:
            firstRandom = func_800363DC(randomLow, randomHigh);
            secondRandom = func_800363DC(8, 0xF);
            setup->unk17 = ((firstRandom / 2) * 0x10) + ((secondRandom / 2) & 0xF);
            break;
        }
        if (moby->damageFlags & 0x04000000) {
            setup->unk4 = (setup->unk4 * 3) >> 1;
        }
    }
}
//////////////////////////////////////////////////////////////// jtbl section above

/**
 * TODO
 */
INCLUDE_ASM("asm/nonmatchings/mobyutil", func_800391E8);

typedef struct {
    short velocityX;
    short velocityY;
    short velocityZ;
    unsigned char angleX;
    unsigned char pad7;
    unsigned char angleY;
    unsigned char pad9;
    unsigned char angleZ;
    unsigned char padB;
    short lifetime;
    short minimumZ;
    short gravity;
    short collisionDistance;
    int collisionCooldown;
} MobyPhysicsTag;

extern int func_80019194(Vector3D*, int);
extern void func_8004EF04(Vector3D*, int);
extern void func_8004F08C(Vector3D*, int, int);

/* Retail source: USA Rev 0 PSX.EXE 0x80039714..0x80039974 (152 words).
 * Moby position uses runtime world units; tag velocities and gravity are signed
 * 16-bit values, angles are unsigned bytes, and lifetime/cooldown update once
 * per call. Confirmed by an exact 152/152 instruction comparison; falsify with
 * any word mismatch in that address span or a nonmatching retail executable. */
int func_80039714(Moby* arg0) {
    register Moby* moby __asm__("$17") = arg0;
    register MobyPhysicsTag* tag __asm__("$16");
    register Vector3D* normal __asm__("$18");
    int dot;
    register int projection __asm__("$7");

    __asm__ volatile ("" : "=r"(moby) : "0"(moby));
    tag = moby->mobyTag;

    if ((tag->lifetime <= 0) || (moby->drawn == 0) ||
        ((tag->collisionDistance == 0) && (moby->position.z < tag->minimumZ))) {
        func_80055B18(moby);
        return 1;
    }

    if (tag->collisionCooldown == 0) {
        if ((tag->collisionDistance != 0) &&
            func_80019194(&moby->position, tag->collisionDistance)) {
            normal = &D_80071900.D_80071918;
            func_8004EF04(normal, 0x1000);
            dot = tag->velocityX * normal->x + tag->velocityY * normal->y +
                  tag->velocityZ * normal->z;
            projection = dot >> 11;
            if (projection < 0) {
                func_8004F08C(normal, 0x1000, (dot >> 13) - projection);
                tag->velocityX = (unsigned short)tag->velocityX + normal->x;
                tag->velocityY = (unsigned short)tag->velocityY + normal->y;
                tag->velocityZ = (unsigned short)tag->velocityZ + normal->z;
            }
        }
        if (tag->collisionCooldown == 0) {
            goto update_velocity;
        }
    }

    tag->collisionCooldown--;
    if (tag->collisionCooldown < 0) {
        tag->collisionCooldown = 0;
    }

update_velocity:
    tag->velocityZ = (unsigned short)tag->velocityZ - (unsigned short)tag->gravity;
    if (tag->velocityZ < -0x80) {
        tag->velocityZ = -0x80;
    }
    moby->position.x += tag->velocityX;
    moby->position.y += tag->velocityY;
    moby->position.z += tag->velocityZ;
    moby->angle.roll += tag->angleX;
    moby->angle.pitch += tag->angleY;
    moby->angle.yaw += tag->angleZ;
    tag->lifetime--;
    return 0;
}

/**
 * LoadDragonModel() - func_80039974() - MATCHING
 * https://decomp.me/scratch/MIiGP
 */
void func_80039974(int dragonNo, int localOffset, int sizeLeft) {
    int var_a2;
    DataHeader* temp_a0;

    var_a2 = sizeLeft;
    temp_a0 = &levelWadHeader.dragonModels[dragonNo];
    if (var_a2 == 0) {
        var_a2 = temp_a0->size - localOffset;
    }
    CDLoadAsync(cdState.wadSector, dragonModelPtr, var_a2, localOffset + (wadHeader.lvl[levelIndex].lvl.offset + temp_a0->offset));
}

/**
 * SpawnReflectionMoby() - func_800399E8() - MATCHING
 * https://decomp.me/scratch/Nr1VQ
 */
void func_800399E8(Moby* moby, Moby** reflectionMoby) {
    Vector3D sp10;
    int temp_s0;
    int* reflectionTag;

    func_8004F178(&sp10, &moby->position);
    D_80071900.D_80071924 = 0xFF;
    sp10.z += 0x12C;
    temp_s0 = func_8001A310(&sp10, 0x7D0, 0, moby);
    if (func_80040954(D_80071900.D_80071924) == 4) {
        *reflectionMoby = ovlHeader.SpawnMoby(moby->mobyClass, moby);
        if (moby->mobyClass == 1) {
            if ((unsigned int)moby < (unsigned int)D_8006C704) {
                (*reflectionMoby)->substate = D_80066964[moby->gemValue];
            } else {
                (*reflectionMoby)->substate = moby->substate;
            }
            (*reflectionMoby)->animationState.id = D_80066988[(*reflectionMoby)->substate];
            (*reflectionMoby)->colour.r = D_80066990[(*reflectionMoby)->substate];
        }
        if (*reflectionMoby != 0) {
            reflectionTag = (*reflectionMoby)->mobyTag;
            (*reflectionMoby)->unknown4 = 0xFD;
            (*reflectionMoby)->unknownCollision = 0;
            (*reflectionMoby)->state = 0x7D;
            if (*(int*)&(*reflectionMoby)->colour == 0) {
                (*reflectionMoby)->colour.a = 0x50;
            }
            *reflectionTag = temp_s0;
        }
    }
}

/**
 * UpdateMobyReflection() - func_80039B6C() - MATCHING
 * https://decomp.me/scratch/qDlNV
 */
void func_80039B6C(Moby* moby, Moby** reflectionMoby) {
    Vector3D sp10;
    int* reflectionTag;
    
    if (moby->state >= 0x80) {
        if ((*reflectionMoby != 0) && ((unsigned char)(*reflectionMoby)->state < 0x80U)) {
            func_80055B18(*reflectionMoby);
        }
    } else {
        if ((*reflectionMoby != 0) && (moby->mobyClass == 0x78)) {
            func_8004F178(&sp10, &(moby->position));
            D_80071900.D_80071924 = 0xFF;
            sp10.z += 300;
            func_8001A310(&sp10, 0x7D0, 0, moby);
            if (func_80040954(D_80071900.D_80071924) != 4) {
                func_80055B18(*reflectionMoby);
                *reflectionMoby = 0;
                return;
            }
        }
        if ((spyro.position.z < moby->position.z) && (spyro.movementState - 11 < 2)) {
            if (*reflectionMoby != 0) {
                func_80055B18(*reflectionMoby);
            }
            *reflectionMoby = 0;
            return;
        }
        if ((*reflectionMoby) != 0) {
            reflectionTag = (*reflectionMoby)->mobyTag;
            if (moby->position.z < *reflectionTag) {
                (*reflectionMoby)->drawn = 0;
                (*reflectionMoby)->lowDrawDistance = 0U;
                return;
            }
            (*reflectionMoby)->lowDrawDistance = moby->lowDrawDistance;
            (*reflectionMoby)->updateDistance = moby->updateDistance;
            (*reflectionMoby)->unknown3[0] = 0;
            (*reflectionMoby)->animationState.id = moby->animationState.id;
            (*reflectionMoby)->animationState.nextId = moby->animationState.nextId;
            (*reflectionMoby)->animationState.frame = moby->animationState.frame;
            (*reflectionMoby)->animationState.nextFrame = moby->animationState.nextFrame;
            (*reflectionMoby)->animationProgress = moby->animationProgress;
            (*reflectionMoby)->position.x = moby->position.x;
            (*reflectionMoby)->position.y = moby->position.y;
            (*reflectionMoby)->position.z = ((*reflectionTag * 2) - moby->position.z);
            (*reflectionMoby)->angle.roll = moby->angle.roll;
            (*reflectionMoby)->angle.pitch = -moby->angle.pitch;
            (*reflectionMoby)->angle.yaw = moby->angle.yaw;
            if ((*reflectionMoby)->colour.a != 0x50) {
                if (moby->mobyClass == 120) {
                    (*reflectionMoby)->angle.roll = moby->angle.roll + 0x80;
                } else {
                    (*reflectionMoby)->angle.pitch = 0x80 - moby->angle.pitch;
                }
            }
            (*reflectionMoby)->subtype = moby->subtype;
        }
    }
}
