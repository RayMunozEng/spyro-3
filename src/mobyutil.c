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

INCLUDE_ASM("asm/nonmatchings/mobyutil", func_80036708);

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

INCLUDE_ASM("asm/nonmatchings/mobyutil", func_80036A68);

INCLUDE_ASM("asm/nonmatchings/mobyutil", func_80036E60);

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

INCLUDE_ASM("asm/nonmatchings/mobyutil", func_80037168);

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

INCLUDE_ASM("asm/nonmatchings/mobyutil", func_80037768);

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

INCLUDE_ASM("asm/nonmatchings/mobyutil", func_80037BBC);

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

INCLUDE_ASM("asm/nonmatchings/mobyutil", func_80038000);

INCLUDE_ASM("asm/nonmatchings/mobyutil", func_800382F4);

INCLUDE_ASM("asm/nonmatchings/mobyutil", func_800387AC);

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

INCLUDE_ASM("asm/nonmatchings/mobyutil", func_80038BF8);

INCLUDE_ASM("asm/nonmatchings/mobyutil", func_80038F14);
//////////////////////////////////////////////////////////////// jtbl section above

/**
 * TODO
 */
INCLUDE_ASM("asm/nonmatchings/mobyutil", func_800391E8);

/**
 * TODO
 */
INCLUDE_ASM("asm/nonmatchings/mobyutil", func_80039714);

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
