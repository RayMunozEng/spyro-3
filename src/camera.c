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

INCLUDE_ASM("asm/nonmatchings/camera", func_80012530);

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

INCLUDE_ASM("asm/nonmatchings/camera", func_80012D18);

INCLUDE_ASM("asm/nonmatchings/camera", func_800130DC);

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

INCLUDE_ASM("asm/nonmatchings/camera", func_800144B4);

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

INCLUDE_ASM("asm/nonmatchings/camera", func_80016764);

INCLUDE_ASM("asm/nonmatchings/camera", func_80017028);
