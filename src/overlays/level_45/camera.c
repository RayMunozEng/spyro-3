#include "matching.h"
#include "common.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 45

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

extern int D_8006E044;
extern int D_8006E078;
extern int D_8006E08C;
extern int D_8006E094;
extern int D_8006E098;
extern CameraPosition D_8006E0D8;
extern int D_8006E0DC;
extern int D_8006E0E8;
extern int D_8006E12C;
extern int D_8006E130;
extern int D_8006E1D0;

void func_level_45_800896FC(void) {
    int temp_v0;
    int var_s0;
    int var_v0;
    register int var_v0_2 __asm__("$2");
    int var_v1;

    var_s0 = (int)(D_8006E130 + 2) >> 2;
    if (var_s0 >= 5) {
        var_s0 = 4;
    }
    if (D_8006E044 == 3) {
        if (D_8006E12C == 0) {
            func_80014354();
            temp_v0 = -spyro.rotation.pitch;
            var_v1 = (int)(temp_v0 - D_8006E078) >> 2;
            D_8006E08C = temp_v0;
            if (var_v1 > 0xC0)
                var_v1 = 0xC0;
            if (var_v1 < -0xC0)
                var_v1 = -0xC0;
            var_v0_2 = var_v1;
            if (var_v1 < 0) {
                MATCHING_KEEP_VOLATILE(var_v0_2);
                var_v0_2 = -var_v0_2;
            }
            if (var_v0_2 >= 9) {
                D_8006E094 = var_v1;
            } else {
                D_8006E094 = 0;
            }
            if ((spyro.movementState != MOVEMENT_STATE_SUPERFLY) ||
                (spyro.union144.b.unk148 <= 0)) {
                D_8006E098 = (int)-spyro.rotation.roll >> 2;
            }
            func_80013918(0xC0);
            func_800139A4();
        }
        func_800142E0();
        func_800135A4(&D_8006E0D8, &D_8006929C[var_s0], 0);
        if (D_8006E0D8.pos.azimuth < 0x100) {
            D_8006E0D8.pos.azimuth = 0x100;
        }
        if (D_8006E0DC < 0x60) {
            D_8006E0DC = 0x60;
        }
        if (D_8006E0E8 < 0x40) {
            D_8006E0E8 = 0x40;
        }
        func_800135A4((CameraPosition*)((unsigned char*)&D_8006E0D8 + 0x14), &D_80069328[var_s0],
                      0);
        func_800135A4((CameraPosition*)((unsigned char*)&D_8006E0D8 + 0x28), &D_800693C8, 0);
        func_800135A4((CameraPosition*)((unsigned char*)&D_8006E0D8 + 0x3C), &D_800693B4, 0);
        if (spyro.movementState == MOVEMENT_STATE_SUPERFLY) {
            D_8006E1D0 = -spyro.union144.a.unk13ce.x;
        }
    }
}

/**
 * ???() - func_level_45_80089934() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_45_80089934() {
	switch (camera.cameraState) {
        
#ifdef IS_ZOOM_OUT_CAMERA_LEVEL
	case CAMERA_ZOOM_OUT:
		if (camera.cameraState != camera.unk168) {
			func_80013900(&camera.unk7c.pos[3]);
			func_80012530();
			return;
		}
        func_8001241C();
		func_80012530();
		return;
#endif
        
#ifdef IS_AGENT_9_LEVEL  
	case CAMERA_AGENT_9_POV:
		func_800135A4(&camera.unk7c.pos[2], &camera.unk7c.pos[1], 0);
		return;
#endif
        
	default:
		func_8001241C();
		func_80012530();
		return;
	}

}

void func_level_45_8008995C(int mode) {
    if (mode == 3) {
        register int* state __asm__("$16") = &camera.unk50;
        CameraPosition* position;
        /* Keep the original shared address base; this constraint emits no code. */
        MATCHING_KEEP(state);
        *state = 0;
        camera.unk140[0] = 0;
        camera.unk140[1] = 0;
        camera.unk140[2] = 1;
        camera.unk140[5] = 0;
        camera.unk5c[0] = 0;
        position = (CameraPosition*)((char*)state + 0x2C);
        func_800142E0();
        func_800136F0(position, (Vector3D*)((char*)state - 0x28), (Vector3D*)((char*)state + 0x10));
        func_800138A0(position, position);
        func_800135A4((CameraPosition*)((char*)state + 0x54), position, 0);
    }
}

extern int D_8006E044, D_8006E160, D_8006E538, D_8006E53C;
extern int D_80068CAC[];
void func_level_45_800899F8(void) {
    register int next __asm__("$4");
    if (D_8006E044 == 3) {
        next = D_8006E160;
        if (next)
            goto change;
        if ((D_8006E538 & 0x10) && spyro.idle) {
            next = 7;
            goto change;
        }
        if (D_8006E53C & 0xC) {
            next = 8;
            goto change;
        }
        {
            register int animation __asm__("$2") = spyro.animationState;
            register int current __asm__("$3") = D_8006E044;
            __asm__("" : "=r"(current) : "0"(current), "r"(animation));
            animation *= 4;
            MATCHING_KEEP(animation);
            next = *(int*)((char*)D_80068CAC + animation);
            if (current == next)
                return;
        }
        if (!next)
            next = 6;
    change:
        func_80016764(next);
    }
}
