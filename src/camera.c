#include "common.h"
#include "camera.h"
#include "stdutil.h"
#include "spyro.h"

// sbss
extern int D_8006C6D0;
extern char g_CheatFlags;
extern int D_8006E050;

///////////////////////////////////////////////////////////////////////

/* Retail source: asm/nonmatchings/camera/func_8001204C.s,
 * 0x8001204C..0x80012168; reset and cleanup execute once on call. */
extern int D_8006E1D0, D_8006E1CC, D_8006E538, D_8006E044, D_8006E038;
extern char D_80070328;
extern void (*unk_ovlheader_80074328)(void*);
void func_8005955C(int);
void func_80055D24(void*, int);
void func_80050B88(void*);
void func_80055B18(void*);
void func_8001204C(void) {
    char* moby;
    void* outer;
    void* object;
    func_80012168();
    func_80017028();
    func_8005955C(D_8006E1D0 + 0x155);
    D_8006E1CC = 0;
    if (*(int*)(&D_80070328 + 0x24C) == 4) {
        outer = *(void**)(&D_80070328 + 0x250);
        moby = *(char**)outer;
        if ((D_8006E538 & 0x80) != 0) {
            int stage = *(int*)(&D_80070328 + 0x48);
            if (stage == 0x7B || (stage == 0x7A && D_8006E044 == 0x1F)) {
                func_80055D24(outer, 4);
                if (unk_ovlheader_80074328 != 0)
                    unk_ovlheader_80074328(*(void**)(&D_80070328 + 0x250));
                goto end;
            }
        }
        object = *(void**)(moby + 0x88);
        if (object != 0) {
            func_80050B88(object);
            *(void**)(moby + 0x88) = 0;
        }
        object = *(void**)(moby + 0x70);
        if (object != 0) {
            func_80055B18(object);
            *(void**)(moby + 0x70) = 0;
        }
    }
end:
    D_8006E038 = 0;
}

/**
 * Camera update - func_80012168() - MATCHING
 * Rev 0 target: asm/nonmatchings/camera/func_80012168.s,
 * 0x80012168..0x8001241C (173 instruction words).
 * https://decomp.me/scratch/IUiur supplied the initial C candidate.
 */
extern int D_8006C640;
extern int deltaTime;
extern int D_8006E0CC, D_8006E0D0, D_8006E0D4;
extern int D_8006E1D4, D_8006E1D8, D_8006E1DC, D_8006E148;
extern unsigned char D_8006E054;
void func_80012168(void) {
    int var_s0;
    int var_v0;
    int var_v1;
    short framePad[2]; /* GCC 2.7.2 frame layout; no runtime access. */

    func_800144B4();
    if (camera.unk140[5] != 0) {
        func_8004F178(&camera.nextCameraPosCartesian, (Vector3D*)&camera.unk1c4[9]);
        camera.unk44 = camera.unk1f4[0];
        camera.unk46 = camera.unk1f4[1];
        camera.unk48 = camera.unk1f4[2];
    } else {
        var_s0 = 0;
        if (deltaTime > 0) {
            do {
                var_s0 += 1;
                func_80016568();
            } while (var_s0 < deltaTime);
        }
        func_80012AC8();
        func_80012B34();
    }
    var_v1 = ABS(camera.unk7c.pos[4].pos.azimuth)
        + ABS(camera.unk7c.pos[4].pos.elevation) + ABS(D_8006E0CC);
    camera.unk130 = var_v1 + ABS(D_8006E0D0) + ABS(D_8006E0D4);
    if (D_8006E1D8 != 0) {
        if (D_8006E1DC < D_8006E1D8) {
            D_8006E1DC = D_8006E1D8;
        }
        D_8006E1D8 = D_8006E1D8 - deltaTime;
        if (D_8006E1D8 < 0) {
            D_8006E1D8 = 0;
        }
        camera.nextCameraPosCartesian.z +=
            ((D_8006E1D4 * D_8006E1D8 * ((D_8006C640 & 2) - 1)) / camera.unk1c4[8]) >> 6;
    } else {
        camera.unk1c4[8] = 0;
    }
    if (camera.unk5c[0] != 0) {
        var_s0 = ((camera.unk7c.pos[0].pos.azimuth - spyro.rotation.yaw) - 0x800) & 0xFFF;
        if (var_s0 >= 0x801) {
            var_s0 -= 0x1000;
        }
        var_v0 = ABS(var_s0);
        if ((var_v0 < 0x40) || (D_8006E148 != 0) || (camera.unk140[4] != 0)) {
            D_8006E054 = 0;
        }
    }
}

/**
 * ???() - func_8001241C() - MATCHING
 * Almost ready to add, but must have struct usage corrected first
 * https://decomp.me/scratch/FD6TW
 */
extern int D_8006E088;
extern int D_8006E08C;
extern int D_8006E090;
extern int D_8006E094;
extern int D_8006E098;
extern int D_8006E09C;
extern int D_8006E0A0;
extern int D_8006E0A4;
extern int D_8006E0A8;
extern int D_8006E0AC;
extern int D_8006E0B0;
extern int D_8006E0B4;
extern int D_8006E0B8;
extern int D_8006E0BC;
extern int D_8006E0C0;
extern int D_8006E148;
void func_8001241C(void) {
    int temp_v1;
    int var_v0;
    var_v0 = D_8006E148;
    if (var_v0 != 0) {
        D_8006E0B0 = var_v0;
    } else {
        temp_v1 = ((D_8006E088 - D_8006E09C) & 0xFFF);
        D_8006E0B0 = (D_8006E088 - D_8006E09C) & 0xFFF;
        D_8006E0B0 = temp_v1 < 0x801 ? D_8006E0B0 : temp_v1 - 0x1000;
    }
    D_8006E0B8 = D_8006E090 - D_8006E0A4;
    D_8006E0B4 = (D_8006E08C - D_8006E0A0) & 0xFFF;
    if (D_8006E0B4 >= 0x801) D_8006E0B4 -= 0x1000;
    D_8006E0BC = (D_8006E094 - D_8006E0A8) & 0xFFF;
    if (D_8006E0BC >= 0x801) D_8006E0BC -= 0x1000;
    D_8006E0C0 = (D_8006E098 - D_8006E0AC) & 0xFFF;
    if (D_8006E0C0 >= 0x801) D_8006E0C0 -= 0x1000;
}

extern int D_8006E0C4, D_8006E0C8;
extern int D_8006E0D8, D_8006E0DC, D_8006E0E0, D_8006E0E4, D_8006E0E8;
extern int D_8006E0EC, D_8006E0F0, D_8006E0F4, D_8006E0F8, D_8006E0FC;
extern int D_8006E100, D_8006E104, D_8006E108, D_8006E10C, D_8006E110;
extern int D_8006E114, D_8006E118, D_8006E11C, D_8006E120, D_8006E124;

/* Retail source: USA Rev 0 PSX.EXE 0x80012530..0x80012AC8
 * (358 words; raw text SHA-256
 * 76507c8f73224e31d15b5bc7b5fd2f805aa94b14bfec7405e8e56b4b4f4e059d).
 * Each call advances five signed camera axis velocities with Q6 damping,
 * applies the high byte to signed 12-bit camera angles, and clamps settled
 * velocities to +/-0x100. It runs once per normal camera update and is also
 * called explicitly by retail overlay camera paths. Confidence: exact;
 * falsifiable by 478 instruction/relocation records and the complete
 * executable and overlay SHA-256 checks. */void func_80012530(void) {
    register int factor asm ("$2") = D_8006E0D8;
    register int input asm ("$6");
    register int *velocity asm ("$5");
    register int product asm ("$4");
    int value;

    input = D_8006E0B0;
    product = factor * input;
    velocity = &D_8006E0C4;
    value = *velocity;
    factor = D_8006E0EC * value;
    factor = (product - factor) >> 6;
    value += factor;
    *velocity = value;
    {
        int threshold = D_8006E100;
        __asm__ volatile ("" : "=r"(threshold) : "0"(threshold));
        if (value < 0) value = -value;
        value = value < threshold;
    }
    if (value != 0) {
        int scaled = input << 7;
        __asm__ volatile ("" : "=r"(input) : "0"(input));
        *velocity = scaled;
        if (scaled >= 0x101) *velocity = 0x100;
        if (*velocity < -0x100) *velocity = -0x100;
    }
    {
        register int *controlPtr asm ("$5") = &D_8006E114;
        register int control asm ("$4");
        register int bound asm ("$3");
        __asm__ volatile ("" : "=r"(controlPtr) : "0"(controlPtr));
        control = *controlPtr;
        bound = -control;
        if (control >= 0) {
            bound <<= 8;
            if (controlPtr[-20] < bound) controlPtr[-20] = bound;
            bound = control << 8;
            if (bound < controlPtr[-20]) controlPtr[-20] = bound;
        }
    }
    {
        register int *angle asm ("$4") = &D_8006E09C;
        int next = (*angle + (D_8006E0C4 >> 8)) & 0xFFF;
        *angle = next;
        if (next >= 0x801) *angle = next - 0x1000;
    }
    {
        register int factor2 asm ("$2") = D_8006E0DC;
        register int input2 asm ("$5") = D_8006E0B4;
        register int product2 asm ("$4");
        register int value2 asm ("$3");
        product2 = factor2 * input2;
        value2 = D_8006E0C8;
        factor2 = D_8006E0F0 * value2;
        factor2 = (product2 - factor2) >> 6;
        value2 += factor2;
        factor2 = D_8006E104;
        D_8006E0C8 = value2;
        if (value2 < 0) value2 = -value2;
        value2 = value2 < factor2;
        if (value2 != 0) {
            factor2 = input2 << 7;
            D_8006E0C8 = factor2;
            if (factor2 >= 0x101) D_8006E0C8 = 0x100;
            if (D_8006E0C8 < -0x100) D_8006E0C8 = -0x100;
        }
    }
    {
        register int *controlPtr2 asm ("$5") = &D_8006E118;
        register int control2 asm ("$4");
        register int bound2 asm ("$3");
        __asm__ volatile ("" : "=r"(controlPtr2) : "0"(controlPtr2));
        control2 = *controlPtr2;
        bound2 = -control2;
        if (control2 >= 0) {
            bound2 <<= 8;
            if (controlPtr2[-20] < bound2) controlPtr2[-20] = bound2;
            bound2 = control2 << 8;
            if (bound2 < controlPtr2[-20]) controlPtr2[-20] = bound2;
        }
    }
    {
        register int *angle2 asm ("$4") = &D_8006E0A0;
        int next2 = (*angle2 + (D_8006E0C8 >> 8)) & 0xFFF;
        *angle2 = next2;
        if (next2 >= 0x801) *angle2 = next2 - 0x1000;
    }
    {
        register int factor3 asm ("$2") = D_8006E0E0;
        register int input3 asm ("$5") = D_8006E0B8;
        register int product3 asm ("$4");
        register int value3 asm ("$3");
        product3 = factor3 * input3;
        value3 = D_8006E0CC;
        factor3 = D_8006E0F4 * value3;
        factor3 = (product3 - factor3) >> 6;
        value3 += factor3;
        factor3 = D_8006E108;
        D_8006E0CC = value3;
        if (value3 < 0) value3 = -value3;
        value3 = value3 < factor3;
        if (value3 != 0) {
            factor3 = input3 << 7;
            D_8006E0CC = factor3;
            if (factor3 >= 0x101) D_8006E0CC = 0x100;
            if (D_8006E0CC < -0x100) D_8006E0CC = -0x100;
        }
    }
    {
        register int *controlPtr3 asm ("$5") = &D_8006E11C;
        register int control3 asm ("$4");
        register int bound3 asm ("$3");
        __asm__ volatile ("" : "=r"(controlPtr3) : "0"(controlPtr3));
        control3 = *controlPtr3;
        bound3 = -control3;
        if (control3 >= 0) {
            bound3 <<= 8;
            if (controlPtr3[-20] < bound3) controlPtr3[-20] = bound3;
            bound3 = control3 << 8;
            if (bound3 < controlPtr3[-20]) controlPtr3[-20] = bound3;
        }
    }
    {
        register int factor4 asm ("$2") = D_8006E0E4;
        register int input4 asm ("$7") = D_8006E0BC;
        register int product4 asm ("$6");
        register int value4 asm ("$4");
        int damping4;
        product4 = factor4 * input4;
        value4 = D_8006E0D0;
        damping4 = D_8006E0F8 * value4;
        {
            register int *angle3 asm ("$5") = &D_8006E0A4;
            register int angleValue3 asm ("$3");
            factor4 = D_8006E0CC;
            angleValue3 = *angle3;
            factor4 >>= 8;
            angleValue3 += factor4;
            *angle3 = angleValue3;
        }
        factor4 = (product4 - damping4) >> 6;
        value4 += factor4;
        factor4 = D_8006E10C;
        D_8006E0D0 = value4;
        if (value4 < 0) value4 = -value4;
        value4 = value4 < factor4;
        if (value4 != 0) {
            factor4 = input4 << 7;
            D_8006E0D0 = factor4;
            if (factor4 >= 0x101) D_8006E0D0 = 0x100;
            if (D_8006E0D0 < -0x100) D_8006E0D0 = -0x100;
        }
    }
    {
        register int *controlPtr4 asm ("$5") = &D_8006E120;
        register int control4 asm ("$4");
        register int bound4 asm ("$3");
        __asm__ volatile ("" : "=r"(controlPtr4) : "0"(controlPtr4));
        control4 = *controlPtr4;
        bound4 = -control4;
        if (control4 >= 0) {
            bound4 <<= 8;
            if (controlPtr4[-20] < bound4) controlPtr4[-20] = bound4;
            bound4 = control4 << 8;
            if (bound4 < controlPtr4[-20]) controlPtr4[-20] = bound4;
        }
    }
    {
        register int *angle4 asm ("$4") = &D_8006E0A8;
        int next4 = (*angle4 + (D_8006E0D0 >> 8)) & 0xFFF;
        *angle4 = next4;
        if (next4 >= 0x801) *angle4 = next4 - 0x1000;
    }
    {
        register int factor5 asm ("$2") = D_8006E0E8;
        register int input5 asm ("$5") = D_8006E0C0;
        register int product5 asm ("$4");
        register int value5 asm ("$3");
        product5 = factor5 * input5;
        value5 = D_8006E0D4;
        factor5 = D_8006E0FC * value5;
        factor5 = (product5 - factor5) >> 6;
        value5 += factor5;
        factor5 = D_8006E110;
        D_8006E0D4 = value5;
        if (value5 < 0) value5 = -value5;
        value5 = value5 < factor5;
        if (value5 != 0) {
            factor5 = input5 << 7;
            D_8006E0D4 = factor5;
            if (factor5 >= 0x101) D_8006E0D4 = 0x100;
            if (D_8006E0D4 < -0x100) D_8006E0D4 = -0x100;
        }
    }
    {
        register int *controlPtr5 asm ("$5") = &D_8006E124;
        register int control5 asm ("$4");
        register int bound5 asm ("$3");
        __asm__ volatile ("" : "=r"(controlPtr5) : "0"(controlPtr5));
        control5 = *controlPtr5;
        bound5 = -control5;
        if (control5 >= 0) {
            bound5 <<= 8;
            if (controlPtr5[-20] < bound5) controlPtr5[-20] = bound5;
            bound5 = control5 << 8;
            if (bound5 < controlPtr5[-20]) controlPtr5[-20] = bound5;
        }
    }
    {
        register int *angle5 asm ("$4") = &D_8006E0AC;
        int next5 = (*angle5 + (D_8006E0D4 >> 8)) & 0xFFF;
        *angle5 = next5;
        if (next5 >= 0x801) *angle5 = next5 - 0x1000;
    }
}


/**
 * ???() - func_80012AC8() - MATCHING
 * https://decomp.me/scratch/qc25h
 */
void func_80012AC8() {
    func_800135F8(&camera.unk70, &camera.unk7c.pos[2].pos, &camera.unk60);
    func_80012D18();
    camera.unk140[3] = func_800136F0(&camera.unk7c.pos[0], &camera.nextCameraPosCartesian, &camera.unk60);
    func_800130DC();
}

/**
 * ???() - func_80012B34() - MATCHING
 * https://decomp.me/scratch/GhuLg
 */
void func_80012B34() {
    camera.unk44 = 0;
    camera.unk46 = (camera.unk7c.pos[0].pos.elevation + camera.unk7c.pos[2].yaw) & 0xFFF;
    camera.unk48 = ((camera.unk7c.pos[0].pos.azimuth + 0x800) + camera.unk7c.pos[2].pitch) & 0xFFF;
    func_800138A0(&camera.unk7c.pos[0], &camera.unk7c.pos[0]);
}

/**
 * ???() - func_80012BA8()
 * WIP
 * https://decomp.me/scratch/b1d0d
 */
/* Retail source: asm/nonmatchings/camera/func_80012BA8.s,
 * 0x80012BA8..0x80012D18; one camera setup sequence per call. */
extern char D_8006E058;
extern int D_8006E064, D_8006E12C, D_8006E130;
extern int D_8006E134, D_80071934;
extern unsigned char D_8006E13E;
void func_8004E790(void*, int, int);
int func_80018368(Vector3D*, Vector3D*);
void func_80012BA8(CameraPosition* origin) {
    char* state = (char*)&D_8006E058;
    CameraPosition* current;
    CameraPosition* next;
    Vector3D temp;
    func_800142AC();
    func_8004F178((Vector3D*)state, (Vector3D*)&D_80070328);
    current = (CameraPosition*)(state + 0x30);
    D_8006E064 = *(int*)(&D_80070328 + 0x64);
    func_800135A4(current, origin, D_8006E064);
    next = (CameraPosition*)(state + 0x44);
    func_800135A4(next, current, 0);
    func_800135A4((CameraPosition*)(state + 0x1C), current, 0);
    func_80013900((CameraPosition*)(state + 0x6C));
    func_800135F8((Vector3D*)(state + 0x10), (SphericalPosition*)next,
                   (Vector3D*)state);
    func_8004F178((Vector3D*)(state - 0x38), (Vector3D*)(state + 0x10));
    func_80012B34();
    D_8006E12C = 0;
    D_8006E130 = 0;
    func_8004E790(state + 0x108, 0, 0x70);
    func_8004E790(state + 0x17C, 0, 0xC);
    func_80016764(1);
    if ((unsigned int)(*(int*)(&D_80070328 + 0x50) - 11) < 2) {
        func_8004F178(&temp, (Vector3D*)(state - 0x38));
        {
            register Vector3D* a0 __asm__("$4") = (Vector3D*)(state - 0x38);
            register Vector3D* a1 __asm__("$5") = &temp;
            register int* hit __asm__("$16");
            int z;
            __asm__ volatile ("" : "=r"(a0), "=r"(a1) : "0"(a0), "1"(a1) : "memory");
            z = temp.z;
            __asm__ volatile ("" : "=r"(z) : "0"(z));
            hit = &D_80071934;
            *hit = 0;
            __asm__ volatile ("" : "=r"(z) : "0"(z) : "memory");
            temp.z = z - 0x1000;
            func_80018368(a0, a1);
            if (*hit != 0) D_8006E038 = 0;
        }
    } else {
        D_8006E038 = 0;
    }
    D_8006E13E = 0;
    D_8006E134 = 0;
}

/* Retail source: USA Rev 0 PSX.EXE 0x80012D18..0x800130DC (241 words),
 * raw function SHA-256
 * E978A7EE10472A51337B028E9AC09FCF3FC75A2A5D0E13943E08C3326600B947.
 * Positions and deltas use runtime Vector3D world units. Path segments are
 * divided into (distance(mode 1) / 240) + 1 steps; collision probes use a
 * 0x100 radius and at most six corrections per step. The final ground probe
 * adds 0x80 world units to Z and uses a 0x300 range. This runs once per call.
 * Confidence: confirmed by a 241/241 instruction comparison. Falsifiable
 * vectors are the D_8006E138 direct-copy branch, distances on both sides of
 * 240, collision results with Moby flag 0x80 clear/set, six failed retries,
 * and zero/nonzero ground results with D_80071934 clear/set. */
extern unsigned char D_8006E138, D_8006E139;
extern signed char D_8006E13C;
extern Vector3D D_8006E020, D_8007190C;
extern int D_8006E028, D_8006E038, D_8006E044;
extern int D_8006E134, D_80071934;
extern unsigned char D_8006E13E;
extern Moby* func_8001BA30(Vector3D*, int, int, int, int, Moby*);
extern int func_80019194(Vector3D*, int);
extern int func_8001A358(Vector3D*, int);
extern void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
void func_80012D18(void) {
    Vector3D delta;
    Vector3D position;
    Vector3D savedPosition;
    Vector3D groundProbe;
    Moby* collision;
    int stepCount;
    int step;
    int attempt;
    int foundMoby = 0;
    signed char* stateFlag = &D_8006E13C;
    int retry;
    volatile int stackPad[2];

    *stateFlag = 0;
    if (D_8006E138 != 0) {
        func_8004F178((Vector3D*)(stateFlag - 0x11C), (Vector3D*)(stateFlag - 0xD4));
    } else {
        Vector3D* start = (Vector3D*)(stateFlag - 0x11C);
        func_8004F1C8(&delta, (Vector3D*)(stateFlag - 0xD4), start);
        stepCount = func_8004EDE8(&delta, 1);
        __asm__ volatile ("" : "=r"(stepCount) : "0"(stepCount));
        stepCount = (stepCount / 240) + 1;
        if (stepCount >= 2) {
            delta.x /= stepCount;
            delta.y /= stepCount;
            delta.z /= stepCount;
        }
        func_8004F178(&position, start);
        step = 0;
        if (stepCount > 0) {
            do {
                func_8004F194(&position, &position, &delta);
                func_8004F178(&savedPosition, &position);
                attempt = 0;
                do {
                    collision = 0;
                    if (D_8006E139 == 0)
                        collision = func_8001BA30(&position, 0x100, 0, 0, 0, 0);
                    if (collision != 0) {
                        if (((unsigned char*)collision)[0x53] & 0x80) {
                            collision = 0;
                        } else {
                            func_8004F178(&position, &D_8007190C);
                            foundMoby = 1;
                        }
                    }
                    if (func_80019194(&position, 0x100) == 0) {
                        retry = attempt < 6;
                        if (collision == 0)
                            break;
                    } else {
                        func_8004F178(&position, &D_8007190C);
                        D_8006E13C = 1;
                    }
                    attempt++;
                    retry = attempt < 6;
                } while (retry);
                if (!retry && foundMoby) {
                    func_8004F178(&position, &savedPosition);
                    attempt = 0;
                    do {
                        if (func_80019194(&position, 0x100) == 0)
                            break;
                        func_8004F178(&position, &D_8007190C);
                        D_8006E13C = 1;
                        attempt++;
                    } while (attempt < 6);
                }
                step++;
            } while (step < stepCount);
        }
        func_8004F178(&D_8006E020, &position);
    }

    {
        register int* cameraState __asm__("$5") = &D_8006E044;
        if (*cameraState != 0x23) {
            func_8004F178(&groundProbe, (Vector3D*)((char*)cameraState - 0x24));
            groundProbe.z += 0x80;
            groundProbe.z = func_8001A358(&groundProbe, 0x300);
            if (groundProbe.z != 0 && D_80071934 != 0) {
                D_8006E13E = 1;
                D_8006E134 = groundProbe.z;
            } else {
                register unsigned char* groundFlag __asm__("$3") = &D_8006E13E;
                if (*groundFlag == 0)
                    D_8006E134 = 0;
                *groundFlag = 0;
            }
            if (D_8006E134 == 0)
                return;
            if (D_8006E028 < D_8006E134) {
                D_8006E038 = 0x800;
                return;
            }
        }
    }
    D_8006E038 = 0;
}

/* Retail source: USA Rev 0 PSX.EXE 0x800130DC..0x800135A4 (306 words),
 * raw function SHA-256
 * 7397B247488B76D4D7C2DA96CF6CB05F32937652A9079056B1F6295885DE1CAC.
 * Angles are 12-bit turns; positions and radii are runtime world units.
 * The camera timer advances by D_8006C648 once per call. After 61 ticks,
 * five fixed camera entries are tested; before that, four signed angle/radius
 * offsets are tested at scales 1, 2, and 4 with 0x100 collision probes.
 * Confidence: confirmed by a 306/306 instruction comparison. Falsifiable
 * vectors are camera lock clear/set, mode 7/other, timer 60/61, each of the
 * five fixed entries, each four-bit candidate mask, and collision results at
 * all three scales. Runtime camera appearance and Rev 1 equivalence remain
 * unverified. */
extern char D_800693DC, D_800693E0, D_800693E4, D_8006942C;
extern unsigned char D_8006E13A;
extern int D_8006C648, D_8006E074, D_8006E344;
#define CAMERA_FIELD(p, t, o) (*(t)((char *)(p) + (o)))
void func_800130DC(void) {
    struct { Vector3D sp10; char pad1C[4]; Vector3D sp20; char pad2C[4]; int sp30, sp34, sp38; char pad3C[8]; } frame;
    register unsigned char *var_s1 asm ("$17");
    int temp_v0;
    int temp_v1;
    int temp_v1_2;
    int temp_v1_3;
    int collisionResult;
    register int var_s0 asm ("$16");
    register int var_s3 asm ("$19");
    register unsigned char *temp_s2 asm ("$18");
    register unsigned char *var_s4 asm ("$20");
    register unsigned char *var_s5 asm ("$21");

    var_s1 = &D_8006E139;
    if ((*var_s1 == 0) && (D_8006E344 != 7)) {
        func_8004F178(&frame.sp10, (Vector3D *)&D_80070328);
        temp_s2 = var_s1 - 0x119;
        frame.sp10.z -= 0x124;
        if (func_80013E38((Vector3D *) temp_s2, &frame.sp10, 1) == 0) {
            D_8006E13C = 1;
            temp_v0 = D_8006E130 + D_8006C648;
            D_8006E130 = temp_v0;
            var_s3 = 0;
            if (temp_v0 >= 0x3D) {
                var_s0 = 0;
                var_s1 = &D_8006942C;
loop_5:
                func_80012BA8(var_s1);
                if ((func_80019194((Vector3D *) temp_s2, 0x100) != 0) || (func_80013E38((Vector3D *) temp_s2, &frame.sp10, 1) == 0)) {
                    var_s0 += 1;
                    var_s1 += 0x14;
                    if (var_s0 < 5) {
                        goto loop_5;
                    }
                    return;
                }
            } else {
                var_s0 = 0;
                var_s4 = var_s1 - 0xC5;
                temp_s2 = (unsigned char *)&frame.sp20;
                var_s5 = var_s1 - 0xE1;
                var_s1 = (unsigned char *)0;
loop_10:
                frame.sp30 = (CAMERA_FIELD(var_s4, int *, 0) + CAMERA_FIELD(&D_800693DC, int *, (int)var_s1)) & 0xFFF;
                temp_v1 = (CAMERA_FIELD(var_s4, int *, 4) + CAMERA_FIELD(&D_800693E0, int *, (int)var_s1)) & 0xFFF;
                frame.sp34 = temp_v1;
                if (temp_v1 >= 0x801) {
                    frame.sp34 = temp_v1 - 0x1000;
                }
                if (frame.sp34 >= 0x401) {
                    frame.sp34 = 0x400;
                }
                frame.sp38 = CAMERA_FIELD(var_s4, int *, 8) + CAMERA_FIELD(&D_800693E4, int *, (int)var_s1);
                func_800135F8((Vector3D *) temp_s2, (SphericalPosition *) &frame.sp30, (Vector3D *) var_s5);
                if ((func_80019194((Vector3D *) temp_s2, 0x100) != 0) || (func_80013E38((Vector3D *) (var_s4 - 0x54), (Vector3D *) temp_s2, 1) == 0) || (var_s3 |= 1 << var_s0, (func_80013E38((Vector3D *) temp_s2, &frame.sp10, 1) == 0))) {
                    var_s0 += 1;
                    var_s1 += 0x14;
                    if (var_s0 >= 4) {
                        var_s0 = 0;
                        if (var_s3 != 0) {
                            temp_s2 = (unsigned char *)&frame.sp20;
                                    var_s4 = (unsigned char *)&D_8006E074;
                            var_s5 = (unsigned char *)&D_8006E074 - 0x1C;
                            var_s1 = (unsigned char *)0;
loop_20:
                            if ((var_s3 >> var_s0) & 1) {
                                frame.sp30 = (CAMERA_FIELD(var_s4, int *, 0) + (CAMERA_FIELD(&D_800693DC, int *, (int)var_s1) * 2)) & 0xFFF;
                                temp_v1_2 = (CAMERA_FIELD(var_s4, int *, 4) + (CAMERA_FIELD(&D_800693E0, int *, (int)var_s1) * 2)) & 0xFFF;
                                frame.sp34 = temp_v1_2;
                                if (temp_v1_2 >= 0x801) {
                                    frame.sp34 = temp_v1_2 - 0x1000;
                                }
                                if (frame.sp34 >= 0x401) {
                                    frame.sp34 = 0x400;
                                }
                                frame.sp38 = CAMERA_FIELD(var_s4, int *, 8) + (CAMERA_FIELD(&D_800693E4, int *, (int)var_s1) * 2);
                                func_800135F8((Vector3D *) temp_s2, (SphericalPosition *) &frame.sp30, (Vector3D *) var_s5);
                                if (func_80019194((Vector3D *) temp_s2, 0x100) == 0) {
                                    if (func_80013E38((Vector3D *) (var_s4 - 0x54), (Vector3D *) temp_s2, 1) != 0) {
                                        collisionResult = func_80013E38((Vector3D *) temp_s2, &frame.sp10, 1);
                                        var_s0 += 1;
                                        if (collisionResult == 0) {
                                            goto block_32;
                                        }
                                        goto block_51;
                                    }
                                    goto block_30;
                                }
block_30:
                                var_s3 &= ~(1 << var_s0);
                                goto block_31;
                            }
block_31:
                            var_s0 += 1;
block_32:
                            var_s1 += 0x14;
                            if (var_s0 >= 4) {
                                var_s0 = 0;
                                if (var_s3 != 0) {
                                    temp_s2 = (unsigned char *)&frame.sp20;
                                    var_s4 = (unsigned char *)&D_8006E074;
                                    var_s5 = (unsigned char *)&D_8006E074 - 0x1C;
                                    var_s1 = (unsigned char *)0;
loop_35:
                                    if ((var_s3 >> var_s0) & 1) {
                                        frame.sp30 = (CAMERA_FIELD(var_s4, int *, 0) + (CAMERA_FIELD(&D_800693DC, int *, (int)var_s1) * 4)) & 0xFFF;
                                        temp_v1_3 = (CAMERA_FIELD(var_s4, int *, 4) + (CAMERA_FIELD(&D_800693E0, int *, (int)var_s1) * 4)) & 0xFFF;
                                        frame.sp34 = temp_v1_3;
                                        if (temp_v1_3 >= 0x801) {
                                            frame.sp34 = temp_v1_3 - 0x1000;
                                        }
                                        if (frame.sp34 >= 0x401) {
                                            frame.sp34 = 0x400;
                                        }
                                        frame.sp38 = CAMERA_FIELD(var_s4, int *, 8) + (CAMERA_FIELD(&D_800693E4, int *, (int)var_s1) * 4);
                                        func_800135F8((Vector3D *) temp_s2, (SphericalPosition *) &frame.sp30, (Vector3D *) var_s5);
                                        if (func_80019194((Vector3D *) temp_s2, 0x100) == 0) {
                                            if (func_80013E38((Vector3D *) (var_s4 - 0x54), (Vector3D *) temp_s2, 1) != 0) {
                                                collisionResult = func_80013E38((Vector3D *) temp_s2, &frame.sp10, 1);
                                                var_s0 += 1;
                                                if (collisionResult == 0) {
                                                    goto block_47;
                                                }
                                                goto block_51;
                                            }
                                            goto block_45;
                                        }
block_45:
                                        var_s3 &= ~(1 << var_s0);
                                        goto block_46;
                                    }
block_46:
                                    var_s0 += 1;
block_47:
                                    var_s1 += 0x14;
                                    if (var_s0 < 4) {
                                        goto loop_35;
                                    }
                                    return;
                                }
                            } else {
                                goto loop_20;
                            }
                        }
                    } else {
                        goto loop_10;
                    }
                } else {
                    goto block_51;
                }
            }
            return;
        } else {
            if (D_8006E13A == 0) {
                goto block_53;
            }
            goto block_52;
        }
    } else {
        goto block_52;
    }

block_51:
    func_800136F0((CameraPosition *) (var_s4 + 0x14), (Vector3D *) temp_s2, (Vector3D *) var_s5);
    CAMERA_FIELD(var_s4, int *, 0xB8) = 0x10;
    return;
block_52:
    D_8006E12C = 0;
block_53:
    D_8006E130 = 0;
}
#undef CAMERA_FIELD

/**
 * SetCameraPosition() - func_800135A4() - MATCHING
 * https://decomp.me/scratch/fNZc2
 */
void func_800135A4(CameraPosition* arg0, CameraPosition* arg1, int arg2) {
    arg0->pos.azimuth = (arg1->pos.azimuth + arg2) & 0xFFF;
    MAX_SIGNED(arg0->pos.azimuth, 0x800);
    arg0->pos.elevation = arg1->pos.elevation;
    arg0->pos.radius = arg1->pos.radius;
    arg0->yaw = arg1->yaw;
    arg0->pitch = arg1->pitch;
}

/**
 * ???() - func_800135F8() - MATCHING
 * Needs clean up but nearly ready to add
 * https://decomp.me/scratch/LWgh2
 */
extern int func_8004EA2C(int);
extern int func_8004E9E4(int);
void func_800135F8(Vector3D* arg0, SphericalPosition* arg1, Vector3D* arg2) {
    arg0->x = (((int)(arg1->radius * func_8004EA2C(arg1->elevation)) >> 0xC) * func_8004EA2C(arg1->azimuth)) >> 0xC;
    arg0->y = (((int)(arg1->radius * func_8004EA2C(arg1->elevation)) >> 0xC) * func_8004E9E4(arg1->azimuth)) >> 0xC;
    arg0->z = (int)(arg1->radius * func_8004E9E4(arg1->elevation)) >> 0xC;
    if (arg2 != 0) {
        func_8004F194(arg0, arg0, arg2);
    }
}

extern unsigned char D_8006E13B;
extern int D_8006E144;
int func_8004EDE8(Vector3D*, int);
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
/* Retail source: USA Rev 0 0x800136F0..0x800138A0 (108 words).
 * Angles use 12-bit turns; Cartesian inputs use the producer's world units.
 * Exact test: full PSX.EXE SHA-256 plus all overlay hashes in build_multiproc.py. */
int func_800136F0(CameraPosition* output, Vector3D* first, Vector3D* second) {
    Vector3D difference;
    int flipped = 0;
    int azimuth;
    register int delta __asm__("$3");
    register int magnitude __asm__("$2");
    if (second != 0) {
        func_8004F1C8(&difference, first, second);
    } else {
        func_8004F178(&difference, first);
    }
    output->pos.elevation = func_8004E880(func_8004EDE8(&difference, 0), difference.z, 1);
    azimuth = func_8004E880(difference.x, difference.y, 1);
    delta = (azimuth - output->pos.azimuth) & 0xFFF;
    if (delta >= 0x801) delta -= 0x1000;
    magnitude = delta;
    if (delta < 0) magnitude = -magnitude;
    if (magnitude > 0x400) {
        if (D_8006E13B != 0 ||
            (D_8006E044 == 7 && D_8006E144 >= 0x401) ||
            *(int*)(&D_80070328 + 0x48) == 0x26) {
            azimuth = (azimuth + 0x800) & 0xFFF;
            flipped = 1;
            output->pos.elevation = (0x800 - output->pos.elevation) & 0xFFF;
        }
    }
    {
        int x = difference.x;
        if (x < 0) x = -x;
        if (x < 0x80) {
            int y = difference.y;
            if (y < 0) y = -y;
            if (y < 0x80) {
                azimuth = D_8006E09C;
                /* Retail load-delay word at 0x80013844. */
                __asm__ volatile("nop");
            }
        }
    }
    if (azimuth >= 0x801) azimuth -= 0x1000;
    output->pos.azimuth = azimuth;
    if (output->pos.elevation >= 0x801) output->pos.elevation -= 0x1000;
    output->pos.radius = func_8004EDE8(&difference, 1);
    return flipped;
}

/**
 * ???() - func_800138A0() - MATCHING
 * https://decomp.me/scratch/HAbNC
 */
void func_800138A0(CameraPosition* arg0, CameraPosition* arg1) {
    arg0->yaw = (camera.unk46 - arg1->pos.elevation) & 0xFFF;
    MAX_SIGNED(arg0->yaw, 0x800);
    
    arg0->pitch = ((camera.unk48 - 0x800) - arg1->pos.azimuth) & 0xFFF;
    MAX_SIGNED(arg0->pitch, 0x800);
}

/**
 * ResetCameraPosition() - func_80013900() - MATCHING
 * https://decomp.me/scratch/QcQTl
 */
void func_80013900(CameraPosition* arg0) {
    arg0->pos.azimuth = 0;
    arg0->pos.elevation = 0;
    arg0->pos.radius = 0;
    arg0->yaw = 0;
    arg0->pitch = 0;
}

extern int D_8006E14C;
extern int D_8006E344;
extern int D_8006E538;
extern char D_80070328;
void func_80013918(int arg0) {
    register int* pair __asm__("$5") = &D_8006E148;
    int flags;
    register int one __asm__("$6");
    __asm__ volatile ("" : "=r"(pair) : "0"(pair));
    *pair = 0;
    if (D_8006E344 == 7) return;
    flags = D_8006E538;
    if (flags & 12) return;
    one = 1;
    if (pair[1] == one) pair[1] = 3;
    if (*(int*)(&D_80070328 + 0x240)) return;
    if ((flags & 3) == 2) {
        *pair = arg0;
        pair[1] = one;
    }
    if ((flags & 3) == one) {
        *pair = -arg0;
        __asm__ volatile ("" : "=r"(one) : "0"(one));
        pair[1] = one;
    }
}

extern int D_8006E150;
extern int D_8006E074;
void func_800139A4(void) {
    if (D_8006E148 != 0) {
        D_8006E14C = 1;
        return;
    }
    if (D_8006E14C == 1) {
        D_8006E150 = (D_8006E074 - D_8006E088) & 0xFFF;
        if (D_8006E150 >= 0x801) D_8006E150 -= 0x1000;
        D_8006E088 = D_8006E074;
        D_8006E14C = 2;
        return;
    }
    if (D_8006E14C == 2) {
        if (D_8006E150 > 0) {
            D_8006E150 -= 0x18;
            if (D_8006E150 <= 0) {
                D_8006E150 = 0;
                D_8006E14C = 0;
            }
        } else {
            D_8006E150 += 0x18;
            if (D_8006E150 >= 0) {
                D_8006E150 = 0;
                D_8006E14C = 0;
            }
        }
        {
            register int* angle __asm__("$4") = &D_8006E088;
            __asm__ volatile ("" : "=r"(angle) : "0"(angle));
            *angle = (*angle + D_8006E150) & 0xFFF;
            if (*angle >= 0x801) *angle -= 0x1000;
        }
    }
}

/**
 * ???() - func_80013ACC() - MATCHING
 * https://decomp.me/scratch/EJWHL
 */
void func_80013ACC(Moby* arg0, int arg1) {
    camera.unk168 = arg1;
    camera.unk16c = arg0;
}

/**
 * ???() - func_80013AE4() - MATCHING
 * https://decomp.me/scratch/daGzw
 */
void func_80013AE4(Vector3D* arg0, Vector3D* arg1) {
    if (camera.cameraState != 9) {
        func_800135A4(&camera.unk190, &camera.unk7c.pos[0], 0);
    }
    camera.unk168 = 9;
    func_8004F178(&camera.unk184, arg1);
    func_800136F0(&camera.unk170, arg0, arg1);
    camera.unk170.yaw = 0;
    camera.unk170.pitch = 0;
}

/* Retail source: asm/nonmatchings/camera/func_80013B7C.s,
 * 0x80013B7C..0x80013CC4; state and offsets are Rev 0 runtime addresses. */
extern int D_8006E160, D_8006C74C, D_8006E048, D_8006E04C;
extern unsigned char D_8006E13B;
extern int D_80068CAC[];
void func_80013B7C(int enabled) {
    char* state = (char*)&D_8006E044;
    char* shifted;
    char* work;
    int choice;
    if (*(int*)state == 9) {
        shifted = state + 0x14;
        if (!enabled) goto disabled;
        func_8004F178((Vector3D*)(state + 0x138), (Vector3D*)&D_80070328);
        func_800135A4((CameraPosition*)(state + 0x124),
                        (CameraPosition*)(state + 0x144), 0);
        goto set_flag;
    }
    if (*(int*)state != 10) return;
    shifted = state + 0x14;
    if (enabled) goto enabled_ten;
disabled:
    D_8006E160 = 0;
    func_8004F178((Vector3D*)shifted, (Vector3D*)&D_80070328);
    work = state + 0x30;
    D_8006E13B = func_800136F0((CameraPosition*)work,
                                (Vector3D*)(state - 0x24), (Vector3D*)shifted);
    func_800138A0((CameraPosition*)work, (CameraPosition*)work);
    func_800135A4((CameraPosition*)(state + 0x58), (CameraPosition*)work, 0);
    choice = D_80068CAC[*(int*)(&D_80070328 + 0x48)];
    if (choice == 0) choice = 6;
    func_80016764(choice);
    D_8006C74C = 0;
    return;
enabled_ten:
    if (*(int*)(state + 4) & 0x80) return;
set_flag:
    D_8006E048 = 0x80;
    D_8006E04C = 0;
}
/**
 * ???() - func_80013CC4() - MATCHING
 * https://decomp.me/scratch/XL6u3
 */
void func_80013CC4(int arg0, int arg1) {
    if (camera.cameraState < 9 || camera.cameraState > 10) {
        func_800135A4(&camera.unk190, &camera.unk7c.pos[0], 0);
    }
    camera.unk168 = 10;
    camera.unk1a4 = arg0;
    camera.unk1a8 = 0;
    camera.unk1b4 = arg1;
}

extern int D_8006E160;
extern int D_8006E044;
extern int D_8006E04C;
extern int D_8006C598;
extern void func_8004F168(Vector3D*);
void func_80013D44(Vector3D* source, int shift, Vector3D* optional, int mode) {
    if (*(int*)(&D_80070328 + 0x280) >= 0) {
        int flag = 0;
        register int* state __asm__("$4");
        int shifted;
        func_8004F178((Vector3D*)(&D_80070328 + 0x22C), source);
        shifted = shift << 4;
        __asm__ volatile ("" : "=r"(shifted) : "0"(shifted));
        state = &D_8006E160;
        __asm__ volatile ("" : "=r"(state) : "0"(state));
        *(int*)(&D_80070328 + 0x238) = shifted;
        *state = 11;
        *(int*)(&D_80070328 + 0x23C) = mode;
        if (optional != 0) {
            func_8004F178((Vector3D*)((char*)state + 0x1C), optional);
        } else {
            func_8004F168((Vector3D*)((char*)state + 0x1C));
        }
        if (D_8006E044 == 9 && D_8006C598 >= 128) {
            flag = 16;
        }
        func_80016764(11);
        D_8006E04C = flag;
    }
}

/* Retail source: asm/nonmatchings/camera/func_80013E38.s,
 * 0x80013E38..0x8001405C; positions are raw world units and the path is
 * sampled in 0x400-unit intervals once per call. Confidence: exact (137/137
 * instruction words). Falsifiable vector: flag 4 adds 0x80 to step.z before
 * count=(length>>10)+1; a clear path returns 1 after exactly count samples. */
extern int func_8001830C(Vector3D*, Vector3D*, int, int, int);
extern Moby* func_8001AD60(Vector3D*, Vector3D*, int, int, int);
int func_80013E38(Vector3D* start, Vector3D* end, int flags) {
    Vector3D step;
    Vector3D current;
    Vector3D next;
    register Vector3D* startPosition asm("$17") = start;
    register int count asm("$16");
    register int flagBits asm("$20");
    int i;

    D_80071934 = 0;
    flagBits = flags;
    func_8004F1C8(&step, end, startPosition);
    if (flagBits & 4) {
        step.z += 0x80;
    }
    count = (func_8004EDE8(&step, 1) >> 10) + 1;
    if (count >= 2) {
        step.x /= count;
        step.y /= count;
        step.z /= count;
    }
    func_8004F178(&current, startPosition);
    i = 0;
    while (i < count) {
        Moby* hit;
        func_8004F194(&next, &current, &step);
        if (func_8001830C(&current, &next, 2, 0,
                          *(int*)(&D_80070328 + 0x250)) != 0) {
            if (D_80071934 == 0) {
                return 0;
            }
        }
        if ((flagBits & 2) && D_80071934 != 0) {
            return 0;
        }
        if (flagBits & 1) {
            hit = func_8001AD60(&current, &next, 1, 0,
                                *(int*)(&D_80070328 + 0x250));
            if (hit != 0 && !(hit->difficultyFlags & 0x80)) {
                return 0;
            }
        }
        func_8004F178(&current, &next);
        i++;
    }
    return 1;
}

/* Retail source: USA Rev 0 PSX.EXE 0x8001405C..0x800142AC (148 words).
 * Selects a 20-byte camera-position record from the retail mode jump table,
 * applies controller deltas once per camera tick, then updates both camera
 * positions. Values are signed integers; angles use the engine's 0x1000-turn
 * domain. Confidence is exact only when every cited word and the complete
 * executable hash match; any mismatch falsifies this implementation. */
extern CameraPosition D_80068FB8, D_80068FCC, D_80068FF4;
extern CameraPosition D_8006901C, D_80069030, D_80069044, D_80069058;
extern CameraPosition D_80069184, D_80069198, D_800691AC, D_800691C0;
extern CameraPosition D_80069288, D_8006E168;
extern int D_8006C5BC, D_8006E064, D_8006E074;
void func_80040F48(void*, int);
int func_8004F284(int, int);
void func_8001405C(void) {
    int input[2];
    CameraPosition* target;

    switch (D_8006E044) {
    case 1:
        target = &D_80068F7C;
        if (func_8004F284(*(int*)(&D_80070328 + 0x64), D_8006E074) < 0x280)
            target = &D_80068F90;
        goto update;
    case 2:
        target = &D_80068FB8;
        goto update_input;
    case 3:
        target = &D_80068FF4;
        goto update_input;
    case 0:
    case 4:
    case 8:
    case 12:
    case 23:
        target = &D_80068F7C;
        goto update_input;
    case 5:
        target = &D_80068FCC;
        goto update_input;
    case 6:
        func_80016764(0);
        return;
    case 14:
        target = &D_8006901C;
        if (D_8006C5BC == 0x2F)
            target = &D_80069030;
        goto update_input;
    case 16:
        target = &D_80069044;
        goto update_input;
    case 17:
    case 18:
        target = &D_8006E168;
        goto update_input;
    case 13:
        target = &D_80069058;
        goto update_input;
    case 21:
        target = &D_80069184;
        goto update_input;
    case 22:
        target = &D_80069198;
        goto update_input;
    case 24:
        target = &D_800691AC;
        goto update_input;
    case 25:
        target = &D_80069288;
        goto update_input;
    case 26:
        target = &D_800691C0;
        goto update;
    default:
        return;
    }

update_input:
update:
    func_80040F48(input, 0);
    if (D_8006E538 & 8) {
        target->pos.radius -= input[1] >> 2;
    } else if (D_8006E538 & 4) {
        target->pitch -= input[0] >> 3;
        target->yaw += input[1] >> 3;
    } else if (D_8006E538 & 0x40) {
        target->pos.azimuth += input[0] >> 3;
        target->pos.elevation += input[1] >> 3;
    }
    func_800135A4((CameraPosition*)&D_8006E088, target, D_8006E064);
    func_800135A4((CameraPosition*)((char*)&D_8006E088 + 0x14),
                  (CameraPosition*)&D_8006E088, 0);
}

void func_800142AC(void) {
    if (*((unsigned char*)&g_CheatFlags + 2)) {
        D_8006E050 = 0;
    } else {
        D_8006E050 = 7;
    }
}

/**
 * ???() - func_800142E0() - MATCHING
 * https://decomp.me/scratch/ZbiyF
 */
void func_800142E0() {
    func_8004F178(&camera.unk60, &spyro.position);
    if (spyro.unk20a) camera.unk60.z += D_8006C6D0;
    camera.unk6c = spyro.rotation.yaw;
}

/**
 * ???() - func_80014354() - MATCHING
 * Ready to add
 * https://decomp.me/scratch/Oix8L
 */
extern CameraPosition D_80069058, D_800719A8, D_80068FA4, D_80068FF4;
extern int D_8006E1CC;
void func_80014354(void) {
    int* state = &camera.unk168;
    if (*state == 13) {
        func_800135A4((CameraPosition*)((char*)state - 0xD8), &D_80069058, camera.unk6c);
    } else if (*(int*)((char*)&spyro + 0x244) != 0) {
        func_800135A4((CameraPosition*)((char*)state - 0xD8), &D_800719A8, camera.unk6c);
    } else if (*(int*)((char*)&spyro + 0x50) == 5) {
        func_800135A4((CameraPosition*)((char*)state - 0xD8), &D_80068FA4, camera.unk6c);
    } else if (*(int*)((char*)&spyro + 0x50) == 6) {
        func_800135A4((CameraPosition*)((char*)state - 0xD8), &D_80068FF4, camera.unk6c);
    } else {
        func_800135A4((CameraPosition*)((char*)state - 0xD8), &D_80068F7C, camera.unk6c);
    }
    { int* angle = &D_8006E094; *angle = (*angle - D_8006E1CC) & 0xFFF; }
}

/**
 * ???() - func_80014450() - MATCHING
 * https://decomp.me/scratch/L6LBh
 */
void func_80014450() {
    if (spyro.unk20a) func_800135A4(&camera.unk7c.pos[1], &D_800719F0, camera.unk6c);
    else              func_800135A4(&camera.unk7c.pos[1], &D_80068F90, camera.unk6c);
}

#include "camera_update.inc"

/* Retail source: USA Rev 0 PSX.EXE 0x80016568..0x80016764 (127 words).
 * Camera mode and angle deltas are scalar state updated once per camera tick.
 * Confidence is exact: all 127 words and the complete executable match;
 * falsify with any mismatch in the cited span or final executable hash. */
extern int D_80068F80;
extern int D_8006E048, D_8006E094, D_8006E0A0, D_8006E0A8;
extern int D_8006E0B0, D_8006E0B4, D_8006E0BC;
extern void (*unk_ovlheader_80074308)(void);
void func_80016568(void) {
    int* var_a0;
    int temp_v1;
    int temp_v1_2;

    var_a0 = &D_8006E044;
    temp_v1 = *var_a0;
    if (temp_v1 == 8) goto block_16;
    if (temp_v1 < 9) {
        if (temp_v1 == 6) goto block_5;
        goto block_22;
    }
    if (temp_v1 < 0xC) goto block_17;
    goto block_22;

block_5:
    func_80013900((CameraPosition*)(var_a0 + 0x1B));
    if (D_8006E1CC != 0) {
        temp_v1 = (D_8006E094 - D_8006E0A8) & 0xFFF;
        D_8006E0BC = temp_v1;
        if (temp_v1 >= 0x801) {
            D_8006E0BC = temp_v1 - 0x1000;
        }
    }
    if ((D_8006E050 & 4) || (D_8006E038 != 0)) {
        temp_v1_2 = (D_80068F80 - D_8006E0A0) & 0xFFF;
        D_8006E0B4 = temp_v1_2;
        if (temp_v1_2 >= 0x801) {
            D_8006E0B4 = temp_v1_2 - 0x1000;
        }
    }
    if (D_8006E148 != 0) {
        D_8006E0B0 = D_8006E148;
    }
    goto block_25;

block_16:
    temp_v1 = D_8006E048;
    if (temp_v1 == 2) {
        func_80013900((CameraPosition*)(var_a0 + 0x1B));
        goto block_25;
    }
    goto block_24;

block_17:
    var_a0 = &D_8006E048;
    if (*var_a0 == 0) {
        func_80013900((CameraPosition*)(var_a0 + 0x1A));
        goto block_25;
    }
    if ((*(int*)(&D_80070328 + 0x48) != 7) ||
        (*(int*)(&D_80070328 + 0x4C) != 0x7F)) {
        func_800135A4((CameraPosition*)&D_8006E09C,
                      (CameraPosition*)((char*)&D_8006E09C - 0x14), 0);
        return;
    }
    goto block_24;

block_22:
    if (unk_ovlheader_80074308 != 0) {
        unk_ovlheader_80074308();
        return;
    }
    goto block_24;

block_24:
    func_8001241C();
block_25:
    func_80012530();
}

/* Retail source: USA Rev 0 SCUS-94467, PSX.EXE 0x80016764..0x80017028.
 * Camera mode dispatch preserves retail packed byte angles, 12-bit yaw wrap,
 * signed 16-bit trigonometric tables and integer vector arithmetic.
 * Cadence: one camera mode update invocation; mode transition counters reset here.
 * Falsifiable vectors: modes 0/1/2/6/7/8/9/10/11/18/35, yaw wrap at 0x801,
 * collision retries 0/1/2 and template selectors 2/5/other.
 * Confidence: complete retail executable and overlay hash match.
 * Empty register constraints emit no instructions; symbol aliases prevent
 * compiler address reuse while all resolving to the same retail address. */
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern short D_800658A0[];
extern short D_80065920[];
extern CameraPosition D_80068FE0;
extern int D_8006C590;
extern void *D_8006C5A8;
extern int D_8006C768;
extern short D_8006E03C;
extern short D_8006E03E;
extern short D_8006E040;
extern unsigned char D_8006E13D;
extern unsigned char D_8006E13F;
extern int D_8006E140;
extern int D_8006E158;
extern int D_8006E15C;
extern int D_8006E1AC;
extern int D_8006E1BC;
extern int D_8006E1C0;
extern int D_8006E1C4;
extern void (*unk_ovlheader_8007430C)(unsigned int);

extern char cameraCurrentArg asm("D_8006E074+0");
extern char cameraCopyArg asm("D_8006E074+0x0");
extern char cameraCurrentSecond asm("D_8006E074+00");
extern char cameraCurrentTail asm("D_8006E074+0x00");
void func_80016764(int arg0) {
    struct { Vector3D first; int gap; Vector3D second; int gap2; Vector3D third; } frame;
    register CameraPosition *var_v0 asm("$2");
    register CameraPosition *var_v0_2 asm("$2");
    register char *temp_s0 asm("$16");
    register char *temp_s0_2 asm("$16");
    register char *temp_s1 asm("$17");
    register char *temp_s1_2 asm("$17");
    register char *temp_s5 asm("$21");
    register char *var_a0 asm("$4");
    register char *var_a0_2 asm("$4");
    register char *var_a1 asm("$5");
    register int temp_s4 asm("$20");
    int temp_v0;
    register char *root0 asm("$16");
    register char *root1 asm("$17");
    register Vector3D *vector0 asm("$16");
    register Vector3D *vector1 asm("$17");
    register Vector3D *vector3 asm("$19");
    register char *cameraRoot asm("$4");
    register int var_a1_2 asm("$5");
    register int var_a1_3 asm("$5");
    register int var_s0 asm("$16");
    register int var_s2 asm("$18");
    register int var_s6 asm("$22");
    register unsigned int var_s0_2 asm("$16");

    var_s6 = arg0;
    if (var_s6 == 6) {
        if ((!(D_8006E050 & 1) && (D_8006E044 != 8) && (D_8006E14C != 3)) || (M2C_FIELD(&D_80070328, int *, 0x50) == 0xD) || (D_8006E054 != 0) || (D_8006E538 & 0xC)) {
            var_s6 = 0;
        }
    }
    if (var_s6 == 7) {
        if (M2C_FIELD(&D_80070328, int *, 0x210) & 0x20000) {
            if (D_8006C5BC == 0x21) {
                var_s6 = 0x29;
            }
        }
    }
    if ((var_s6 != 0x1F) || (D_8006E344 != 1)) {
        D_8006E13F = 0;
        D_8006C768 = 0;
        if (!(M2C_FIELD(&D_80070328, int *, 0x210) & 0x2000) && (M2C_FIELD(&D_80070328, int *, 0x244) == 0)) {
            M2C_FIELD(&D_80070328, int *, 0x288) = 0;
        }
        D_8006E1D0 = 0;
        switch (var_s6) {
        case 0:
        case 6:
            root1 = (char *)&D_8006E048;
            *(int *)root1 = 0;
            D_8006E138 = 0;
            D_8006E139 = 0;
            D_8006E13A = 0;
            D_8006E13D = 0;
            func_800142E0();
            root0 = root1 + 0x2C;
            __asm__("" : : "r"(root0));
            goto block_64;
        case 1:
            root0 = (char *)&D_8006E048;
            *(int *)root0 = 0;
            D_8006E138 = 0;
            D_8006E139 = 0;
            D_8006E13A = 1;
            D_8006E13D = 0;
            temp_s1 = (root0 + 0x2C);
            func_800142E0();
            func_800136F0((CameraPosition *) temp_s1, (Vector3D *) ((root0 - 0x28)), (Vector3D *) ((root0 + 0x10)));
            func_800138A0((CameraPosition *) temp_s1, (CameraPosition *) temp_s1);
            __asm__ volatile("" : : : "memory");
            var_a0 = (root0 + 0x54);
            __asm__("" : "=r"(var_a0) : "0"(var_a0) : "$5");
            var_a1 = temp_s1;
            goto block_65;
        case 2:
        case 8:
            root0 = (char *)&D_8006E048;
            *(int *)root0 = 0;
            D_8006E138 = 0;
            D_8006E139 = 0;
            D_8006E13A = 1;
            D_8006E13D = 0;
            D_8006E054 = 0;
            temp_s1_2 = (root0 + 0x2C);
            func_800142E0();
            func_800136F0((CameraPosition *) temp_s1_2, (Vector3D *) ((root0 - 0x28)), (Vector3D *) ((root0 + 0x10)));
            func_800138A0((CameraPosition *) temp_s1_2, (CameraPosition *) temp_s1_2);
            var_a0 = (root0 + 0x54);
            var_a1 = temp_s1_2;
            goto block_65;
        case 7:
            root1 = (char *)&D_8006E140;
            *(int *)root1 = 0;
            D_8006E144 = 0;
            D_8006E158 = 0;
            D_8006E15C = 0;
            D_8006E138 = 0;
            D_8006E139 = 0;
            D_8006E13A = 1;
            D_8006E13D = 0;
            D_8006E054 = 0;
            temp_s0 = (root1 - 0xCC);
            func_800142E0();
            func_800136F0((CameraPosition *) temp_s0, (Vector3D *) ((root1 - 0x120)), (Vector3D *) ((root1 - 0xE8)));
            func_800138A0((CameraPosition *) temp_s0, (CameraPosition *) temp_s0);
            if (M2C_FIELD(&D_80070328, int *, 0x210) & 0x20000) {
                temp_s0_2 = (root1 - 0xB8);
                D_8006E048 = 3;
                func_800135A4((CameraPosition *) temp_s0_2, &D_80068FE0, D_8006E064);
                var_a0 = (root1 - 0xA4);
                __asm__("" : "=r"(var_a0) : "0"(var_a0) : "$5");
                var_a1 = temp_s0_2;
            } else {
                D_8006E048 = 0;
                var_a0 = (root1 - 0xA4);
                __asm__("" : "=r"(var_a0) : "0"(var_a0) : "$5");
                var_a1 = temp_s0;
            }
            goto block_65;
        case 9:
        case 11:
            if (D_8006C640 < 3) {
                if (var_s6 == 9) {
                    D_8006E048 = 1;
                } else {
                    goto block_32;
                }
            } else if ((var_s6 != 9) || (D_8006E044 != 0xB)) {
block_32:
                D_8006E048 = 0;
            }
            goto block_38;
        case 10:
            { register char *state asm("$5") = (char *)&D_8006E1AC;
            if (!(*(int *)state & 2)) {
                if (((unsigned int) (D_8006E044 - 9) >= 2U) && (D_8006E048 = 0, (D_8006C598 == 0xFF))) {
                    D_8006E044 = var_s6;
                    D_8006E04C = 0x10;
                    goto end_update;
                } else {
                    goto block_38;
                }
            } else {
                D_8006E048 = 3;
                func_8004F178((Vector3D *)(state + 4), (Vector3D *)(state - 0x18C));
                D_8006E13D = 1;
                D_8006E1BC = (int) D_8006E03C;
                D_8006E1C0 = (int) D_8006E03E;
                D_8006E1C4 = (int) D_8006E040;
                goto block_38;
            }
            }
block_38:
            D_8006E12C = 0;
            D_8006E130 = 0;
            D_8006E138 = 1;
            D_8006E139 = 1;
            D_8006E054 = 0;
            goto block_68;
        case 18:
            { register int one asm("$2") = 1;
              register char *actor asm("$6");
              register int angle asm("$2");
              register int trig asm("$3");
              __asm__("" : : "r"(one));
              actor = D_8006C5A8;
              __asm__("" : "=r"(actor) : "0"(actor));
              vector0 = &frame.third;
            D_8006E048 = 0;
            D_8006E138 = 0;
            D_8006E139 = one;
            D_8006E13A = one;
            D_8006E13D = 0;
            D_8006E054 = 0;
              angle = M2C_FIELD(actor, unsigned char *, 0x46);
              __asm__ volatile("" : : : "$4", "$5", "memory");
              var_a0 = (char *)vector0;
              __asm__("" : "=r"(var_a0) : "0"(var_a0), "r"(angle));
              angle <<= 1;
              __asm__("" : "=r"(angle) : "0"(angle));
              trig = *(short *)((char *)D_80065920 + angle);
              __asm__ volatile("" : : : "$5", "memory");
              var_a1 = (char *)vector0;
              __asm__("" : "=r"(var_a1) : "0"(var_a1));
              frame.third.x = (trig * 13) >> 5;
              angle = M2C_FIELD(actor, unsigned char *, 0x46);
              __asm__ volatile("" : : : "$17", "memory");
              root1 = &D_80070328 + 0x44;
              __asm__("" : "=r"(root1) : "0"(root1));
              angle <<= 1;
              __asm__("" : "=r"(angle) : "0"(angle));
              trig = *(short *)((char *)D_800658A0 + angle);
              { register int height asm("$2");
                __asm__ volatile("" : : : "memory");
                height = *(int *)root1;
                __asm__("" : "=r"(height) : "0"(height));
                temp_v0 = height; }
              actor += 12;
              *(volatile int *)&frame.third.z = 0;
              frame.third.z = temp_v0;
              frame.third.y = (trig * 13) >> 5;
              func_8004F194((Vector3D *)var_a0, (Vector3D *)var_a1, (Vector3D *)actor);
            }
            { register int result asm("$3");
            result = func_8001A358(vector0, 0x800);
            frame.third.z = result;
            if (result != 0) {
                { register int sum asm("$2") = result + *(int *)root1;
                  __asm__("" : "=r"(sum) : "0"(sum)); frame.third.z = sum; }
            } else {
                func_8004F178(vector0, (Vector3D *) (root1 - 0x44));
            }
            }
            func_8004F178(&frame.first, (Vector3D *) &D_80070328);
            {
                register int height asm("$2") = frame.first.z;
                register int z asm("$3") = M2C_FIELD(&D_80070328, int *, 0x44);
                register char *actor asm("$4") = D_8006C5A8;
                height += 64;
                frame.first.z = height - z;
                z = M2C_FIELD(actor, unsigned char *, 0x46);
                __asm__ volatile("" : : : "$4", "memory");
                cameraRoot = (char *)&D_8006E074;
                height = *(int *)cameraRoot;
                z <<= 4;
                __asm__("" : "=r"(z) : "0"(z));
                temp_s4 = z + 0x800;
                height -= temp_s4;
                __asm__("" : "=r"(height) : "0"(height));
                var_s0 = height & 0xFFF;
            }
            if (var_s0 >= 0x801) {
                var_s0 -= 0x1000;
            }
            var_s0_2 = (unsigned int) var_s0 >> 0x1F;
            if (M2C_FIELD(&D_80070328, int *, 0x24C) != 5) {
                var_s2 = 0;
                vector1 = &frame.second;
                temp_s5 = cameraRoot + 0x14;
                vector3 = &frame.third;
                __asm__("" : : "r"(vector1), "r"(temp_s5), "r"(vector3));
loop_46:
                if (M2C_FIELD(&D_80070328, int *, 0x24C) == 2) {
                    var_a0 = (char *)&D_8006E088;
                    __asm__("" : "=r"(var_a0) : "0"(var_a0));
                    var_a1_2 = var_s0_2 * 0x14;
                    var_v0 = D_800690F8;
                } else {
                    var_a0 = (char *)&D_8006E088;
                    __asm__("" : "=r"(var_a0) : "0"(var_a0));
                    var_a1_2 = var_s0_2 * 0x14;
                    var_v0 = D_80069094;
                }
                func_800135A4((CameraPosition *)var_a0, (CameraPosition *)(var_a1_2 + (int)var_v0), temp_s4);
                func_800135F8(vector1, (SphericalPosition *) temp_s5, vector3);
                if (func_80019194(vector1, 0x100) == 0) {
                    if ((func_80013E38((Vector3D *) (temp_s5 - 0x68), vector1, 0) == 0) || (func_80013E38(vector1, vector3, 0) == 0)) {
                        goto block_53;
                    }
                } else {
block_53:
                    var_s0_2 = 1 - var_s0_2;
                    var_s2 += 1;
                    if (var_s2 < 2) {
                        goto loop_46;
                    }
                }
                if (var_s2 == 2) {
                    __asm__("" : "=r"(var_s2) : "0"(var_s2));
                    var_s0_2 = 2;
                    __asm__("" : "=r"(var_s0_2) : "0"(var_s0_2));
                }
            }
            if (D_8006C590 >= 0) {
                var_s0_2 = (unsigned int) D_8006C590;
            }
            D_8006C590 = (int) var_s0_2;
            func_800142E0();
            {
                register char *actor asm("$2") = D_8006C5A8;
                register int angle asm("$2") = M2C_FIELD(actor, unsigned char *, 0x46);
                register int index asm("$2");
                register int zero asm("$6");
                __asm__ volatile("" : "=r"(angle) : "0"(angle) : "$4", "memory");
                cameraRoot = (char *)&D_8006E064;
                __asm__("" : "=r"(cameraRoot) : "0"(cameraRoot));
                angle <<= 4;
                *(int *)cameraRoot = angle + 0x800;
                if ((M2C_FIELD(&D_80070328, int *, 0x24C) == 2) || (M2C_FIELD(&D_80070328, int *, 0x24C) == 5)) {
                    var_a0_2 = cameraRoot + 0x104;
                    __asm__("" : "=r"(var_a0_2) : "0"(var_a0_2));
                    index = D_8006C590;
                    zero = 0;
                    __asm__("" : : "r"(zero), "r"(index));
                    var_a1_3 = index * 20;
                    var_v0_2 = D_800690F8;
                } else {
                    var_a0_2 = cameraRoot + 0x104;
                    __asm__("" : "=r"(var_a0_2) : "0"(var_a0_2));
                    index = D_8006C590;
                    zero = 0;
                    __asm__("" : : "r"(zero), "r"(index));
                    var_a1_3 = index * 20;
                    var_v0_2 = D_80069094;
                }
                func_800135A4((CameraPosition *)var_a0_2, (CameraPosition *)(var_a1_3 + (int)var_v0_2), zero);
            }
            func_800136F0((CameraPosition *) &D_8006E074, (Vector3D *) (((char *)&D_8006E074 - 0x54)), (Vector3D *) (((char *)&D_8006E074 - 0x1C)));
            func_800138A0((CameraPosition *) &D_8006E074, (CameraPosition *) &D_8006E074);
            var_a0 = ((char *)&D_8006E074 + 0x28);
            var_a1 = &D_8006E074;
            goto block_65;
        case 35:
            root0 = (char *)&D_8006E048;
            *(int *)root0 = 0;
            D_8006E138 = 1;
            D_8006E139 = 1;
            D_8006E13A = 0;
            D_8006E13D = 0;
            root1 = root0 + 0x2C;
            func_800142E0();
            __asm__("" : : "r"(root1));
block_64:
            func_800136F0((CameraPosition *) &cameraCurrentArg, &D_8006E020, (Vector3D *) &D_8006E058);
            func_800138A0((CameraPosition *)&cameraCurrentSecond, (CameraPosition *)&cameraCopyArg);
            var_a0 = &D_8006E09C;
            var_a1 = &cameraCurrentTail;
block_65:
            func_800135A4((CameraPosition *) var_a0, (CameraPosition *) var_a1, 0);
            goto block_68;
        default:
            if (unk_ovlheader_8007430C != 0) {
                unk_ovlheader_8007430C((unsigned int) var_s6);
            }
            goto block_68;
        }
block_68:
        D_8006E044 = var_s6;
        D_8006E04C = 0;
end_update:
        D_8006E14C = 0;
    }
}

#undef M2C_FIELD

/* Retail source: USA Rev 0 SCUS-94467, PSX.EXE 0x80017028..0x80017A04.
 * Camera mode transition conditions use retail integer counters, flags and
 * unscaled player-state fields; yaw thresholds are 12-bit angular values.
 * Cadence: one camera transition update invocation.
 * Falsifiable vectors: modes 0/1/2/6/7/8/9/10/11/18/35, mode-11 selectors
 * 0/9/other, timer thresholds 14/16/30/60 and transition marker 0x82.
 * Confidence: complete retail executable and overlay hash match.
 * Empty register constraints preserve retail instruction ordering. */
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern int D_8006E128;
extern int *D_8006E19C;
extern int D_8006E1A0;
extern unsigned char D_8006E535;
extern int D_8006E53C;
extern void (*unk_ovlheader_80074310)();

void func_80017028(void) {
    int temp_s0;
    register int four asm("$2");
    register int *state asm("$16");
    register int *stateArg asm("$4");
    register int var_a0 asm("$4");
    register int var_a0_2 asm("$4");
    register int var_v0 asm("$2");
    register int mode asm("$3");
    register int index asm("$2");

    switch (D_8006E044) {                           /* switch 1 */
    case 0:                                         /* switch 1 */
        var_a0 = D_8006E160;
        if (var_a0 == 0) {
            if (!(D_8006E538 & 0x10) || (M2C_FIELD(&D_80070328, unsigned char *, 0x1B9) == 0) || (M2C_FIELD(&D_80070328, int *, 0x24C) == 4)) {
                if (!(D_8006E53C & 0x10) || (M2C_FIELD(&D_80070328, unsigned char *, 0x1B9) == 0) || (M2C_FIELD(&D_80070328, int *, 0x24C) != 4)) {
                    var_a0 = 8;
                    if (!(D_8006E53C & 0xC)) {
                        index = M2C_FIELD(&D_80070328, int *, 0x48);
                        mode = D_8006E044;
                        __asm__("" : "=r"(mode) : "0"(mode), "r"(index));
                        index <<= 2;
                        __asm__("" : "=r"(index) : "0"(index));
                        var_a0 = *(int *)((char *)D_80068CAC + index);
                        if (mode == var_a0) {
                            if (D_8006E14C == 3) {
                                func_80016764(6);
                                goto block_94;
                            }
                            if ((D_8006E050 & 1) && (D_8006E128 < 0x400) && (D_8006E12C == 0) && (D_8006E054 == 0) && ((unsigned int) (D_8006E048 - 1) >= 2U)) {
                                var_a0 = 6;
                                if (D_8006E538 & 0xC) return;
                                __asm__ volatile("" : : : "memory");
                                goto block_37;
                            }
                            return;
                        }
                    }
                    goto block_37;
                }
                goto block_81;
            }
            goto block_77;
        }
        goto block_37;
    case 1:                                         /* switch 1 */
        var_a0 = D_8006E160;
        if (var_a0 == 0) {
            if (!(D_8006E538 & 0x10) || (M2C_FIELD(&D_80070328, unsigned char *, 0x1B9) == 0) || (M2C_FIELD(&D_80070328, int *, 0x24C) == 4)) {
                if (!(D_8006E53C & 0x10) || (M2C_FIELD(&D_80070328, unsigned char *, 0x1B9) == 0) || (M2C_FIELD(&D_80070328, int *, 0x24C) != 4)) {
                    if (!(D_8006E53C & 0xC) || (var_a0 = 8, (D_8006E344 == 7))) {
                        index = M2C_FIELD(&D_80070328, int *, 0x48);
                        mode = D_8006E044;
                        __asm__("" : "=r"(mode) : "0"(mode), "r"(index));
                        index <<= 2;
                        __asm__("" : "=r"(index) : "0"(index));
                        var_a0 = *(int *)((char *)D_80068CAC + index);
                        if (mode != var_a0) {
                            if (var_a0 != 0) {

                            } else {
                                goto block_36;
                            }
                            goto block_37;
                        }
                    } else {
                        goto block_37;
                    }
                } else {
                    goto block_81;
                }
            } else {
                goto block_77;
            }
        } else {
            goto block_37;
        }
        break;
    case 2:                                         /* switch 1 */
        var_a0 = D_8006E160;
        if ((var_a0 == 0) || (var_a0 == 0xC)) {
            index = M2C_FIELD(&D_80070328, int *, 0x48);
            mode = D_8006E044;
            __asm__("" : "=r"(mode) : "0"(mode), "r"(index));
            index <<= 2;
                        __asm__("" : "=r"(index) : "0"(index));
                        var_a0 = *(int *)((char *)D_80068CAC + index);
            if (mode != var_a0) {
                if (var_a0 == 0) {
                    goto block_36;
                }
                goto block_37;
            }
        } else {
            goto block_37;
        }
        break;
block_36:
        var_a0 = 6;
block_37:
        __asm__("" : "=r"(var_a0) : "0"(var_a0));
        func_80016764(var_a0);
        return;
    case 7:                                         /* switch 1 */
        if ((D_8006E160 != 0) && ((unsigned int) (D_8006E160 - 0xC) >= 2U) && (D_8006E160 != 0xE) && ((unsigned int) (D_8006E160 - 0x10) >= 2U) && ((unsigned int) (D_8006E160 - 0x12) >= 2U) && (D_8006E160 != 0x14) && (D_8006E160 != 0x16) && (D_8006E160 != 0x1A) && (D_8006E160 != 0x18)) {
            func_80016764(D_8006E160);
        }
        if (M2C_FIELD(&D_80070328, unsigned char *, 0x1B9) == 0) {
            D_8006C768 = 0;
            if (M2C_FIELD(&D_80070328, int *, 0x244) == 0) {
                M2C_FIELD(&D_80070328, int *, 0x288) = 0;
            }
                goto block_122;
        }
        if (!(D_8006E538 & 0x10)) {
            state = &D_8006E048;
            __asm__("" : "=r"(state) : "0"(state));
            if (*state == 3) {
                *state = 4;
                D_8006E04C = 0;
                return;
            }
            if (*state == 4) {
                if (M2C_FIELD(&D_80070328, int *, 0x170) == *state) {
                    if (D_8006E04C >= 0xE) {
                        D_8006E04C = 0xD;
                        return;
                    }
                } else if (D_8006E04C >= 0x10) {
                    goto block_59;
                }
            } else {
block_59:
                D_8006C768 = 0;
                if (M2C_FIELD(&D_80070328, int *, 0x244) == 0) {
                    M2C_FIELD(&D_80070328, int *, 0x288) = 0;
                }
                func_80016764(0);
                *state = 2;
                return;
            }
        } else {
            four = 4;
            __asm__("" : "=r"(four) : "0"(four));
            stateArg = &D_8006E048;
            __asm__("" : "=r"(stateArg) : "0"(stateArg));
            if (*stateArg == four) {
                *stateArg = 3;
                return;
            }
            if ((D_8006E13F != 0) && (M2C_FIELD(&D_80070328, int *, 0x1D0) == 0) && !(M2C_FIELD(&D_80070328, int *, 0x210) & 0x20000) && (M2C_FIELD(&g_CheatFlags, unsigned char *, 3) == 0) && (M2C_FIELD(&D_80070328, int *, 0x48) != 0x64)) {
                D_8006C768 = 0;
                if (M2C_FIELD(&D_80070328, int *, 0x244) == 0) {
                    M2C_FIELD(&D_80070328, int *, 0x288) = 0;
                }
                D_8006E13F = 0;
                return;
            }
        }
        break;
    case 6:                                         /* switch 1 */
        var_a0 = D_8006E160;
        if ((var_a0 == 0) || (var_a0 == 0x11)) {
            if ((D_8006E538 & 0x10) && (M2C_FIELD(&D_80070328, unsigned char *, 0x1B9) != 0) && (M2C_FIELD(&D_80070328, int *, 0x24C) != 4)) {
block_77:
                var_a0 = 7;
                goto block_37;
            }
            if ((D_8006E53C & 0x10) && (M2C_FIELD(&D_80070328, unsigned char *, 0x1B9) != 0) && (M2C_FIELD(&D_80070328, int *, 0x24C) == 4)) {
block_81:
                var_a0 = 0x1F;
                goto block_37;
            }
            var_a0 = 8;
            if (!(D_8006E53C & 0xC) && (var_a0 = D_80068CAC[M2C_FIELD(&D_80070328, int *, 0x48)], (var_a0 == 0))) {
                if (D_8006E12C == 0) {
                    if ((D_8006E048 != 1) && (D_8006E04C >= 0x3C)) {
                        mode = D_8006E160;
                        var_a0_2 = 0;
                        if (mode == 0x11) {
                            __asm__("" : "=r"(mode) : "0"(mode));
                            var_a0_2 = 0x11;
                            __asm__("" : "=r"(var_a0_2) : "0"(var_a0_2));
                        }
                        func_80016764(var_a0_2);
                        __asm__ volatile("" : : : "memory");
                        goto block_94;
                    }
                    if (((D_8006E050 & 1) || (var_a0 = 0, (D_8006E048 == 1))) && (var_a0 = 0, (D_8006E054 == 0))) {
                        if (D_8006E14C == 3) {
                            goto block_94;
                        }
                    } else {
                        goto block_37;
                    }
                } else {
                    goto block_101;
                }
            } else {
                goto block_37;
            }
        } else {
            goto block_37;
        }
        break;
block_94:
        D_8006E048 = 1;
        return;
    case 8:                                         /* switch 1 */
        var_a0 = D_8006E160;
        if ((var_a0 == 0) || (var_a0 == 0x11)) {
            if (((D_8006E04C >= 0x1E) || (D_8006E128 < 0x1000)) && ((D_8006E535 == 0) || (D_8006E538 & 0xD3))) {
block_101:
                var_a0 = 0;
                goto block_37;
            }
        } else {
            goto block_37;
        }
        break;
    case 9:                                         /* switch 1 */
        if (D_8006E048 == 0x82) {
            D_8006E160 = 0;
            var_v0 = M2C_FIELD(&D_80070328, int *, 0x48) * 4;
            goto block_123;
        }
        break;
    case 10:                                        /* switch 1 */
        if (D_8006E048 == 0x82) {
            D_8006E160 = 0;
            var_v0 = M2C_FIELD(&D_80070328, int *, 0x48) * 4;
            goto block_123;
        }
        if ((D_8006E1AC & 8) && (D_8006E1A0 >= (*D_8006E19C - 1))) {
            index = M2C_FIELD(&D_80070328, int *, 0x48);
            __asm__("" : "=r"(index) : "0"(index));
            D_8006E160 = 0;
            __asm__ volatile("" : : : "memory");
            func_80016764(D_80068CAC[index]);
            D_8006C74C = 0;
            return;
        }
        if ((D_8006E160 == 0) && !(D_8006E048 & 0x80)) {
            D_8006E048 = 0x80;
            D_8006E04C = 0;
            D_8006E1AC &= ~8;
            return;
        }
        break;
    case 11:                                        /* switch 1 */
        if (D_8006E160 == 0) goto block_122;
        switch (D_8006E160) {                       /* switch 2; irregular */
        case 9:                                     /* switch 2 */
            temp_s0 = (D_8006C598 >= 0x80) * 0x10;
            func_80016764(9);
            D_8006E04C = temp_s0;
            return;
        }
        break;
    case 18:                                        /* switch 1 */
        var_a0 = D_8006E160;
        if ((var_a0 == 0) || (var_a0 == D_8006E044)) {
            if ((D_8006E344 != 1) && (D_8006E344 != 0xF)) {
                D_8006E160 = 0;
                var_v0 = M2C_FIELD(&D_80070328, int *, 0x48) * 4;
                goto block_123;
            }
        } else {
            goto block_37;
        }
        break;
    case 35:                                        /* switch 1 */
        if (D_8006E344 != 0xD) {
            var_a0 = D_8006E160;
            if (var_a0 == 0) {
                goto block_122;
            }
            goto block_37;
        }
        break;
block_122:
        var_v0 = M2C_FIELD(&D_80070328, int *, 0x48) * 4;
block_123:
        var_a0 = *(int *)((char *)D_80068CAC + var_v0);
        goto block_37;
    default:                                        /* switch 1 */
        if (unk_ovlheader_80074310 != 0) {
            unk_ovlheader_80074310();
        }
        break;
    }
}

#undef M2C_FIELD
