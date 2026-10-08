#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 12

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

/* AI-generated integration; not human reviewed. SCUS-94467 Rev0
 * 8008B480..8008B9AC. Baseline upstream level11_800915C8;
 * mode13 from verified level16_80086260 and original Rev0 instructions.
 * Raw units, unknown helpers and caller cadence remain unresolved.
 * Test: 331 original code words, linked words and complete retail hashes.
 */
void func_level_12_8008B480(void) {
    int tableIndex;
    int turnDelta;

    tableIndex = (camera.unk138 + 2) >> 2;
    MAX(tableIndex, 4);

    switch (camera.cameraState) {
    case 3:
        if (camera.unk134 == 0) {
            func_80014354();
            camera.unk7c.pos[1].pos.elevation = -spyro.rotation.pitch;

            turnDelta = (-spyro.rotation.pitch - camera.unk7c.pos[0].pos.elevation) >> 2;
            MAX(turnDelta, 0xC0);
            MIN(turnDelta, -0xC0);

            camera.unk7c.pos[1].yaw = (ABS(turnDelta) >= 9) ? turnDelta : 0;
            if ((spyro.movementState != 6) || (spyro.union144.b.unk148 <= 0)) {
                camera.unk7c.pos[1].pitch = -spyro.rotation.roll >> 2;
            }

            func_80013918(0xC0);
            func_800139A4();
        }
        func_800142E0();
        func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
        MIN(camera.unk7c.pos[5].pos.azimuth, 0x100);
        MIN(camera.unk7c.pos[5].pos.elevation, 0x60);
        MIN(camera.unk7c.pos[5].pitch, 0x40);
        func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
        func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
        func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
        if (spyro.movementState == 6) {
            camera.unk1c4[5] = -spyro.union144.b.unk14C;
        }
        return;

    case 12: {
        Vector3D delta;
        if (camera.unk134 == 0) {
            func_80014354();
            func_80013918(0x400);
        }
        func_800142E0();
        if (camera.unk16c != 0) {
            func_8004F1C8(&delta, &camera.unk16c->position, &spyro.position);
            camera.unk6c = func_8004E880(delta.x, delta.y, 1);
            func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
            func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
            return;
        }
        break;

    }
    case 13: {
        Vector3D delta;
        func_800142E0();
        if (camera.unk16c != 0) {
            func_8004F1C8(&delta, &camera.unk16c->position, (Vector3D*)&spyro);
            camera.unk6c = func_8004E880(delta.x, delta.y, 1);
            if (camera.unk134 == 0) {
                func_80014354();
                func_80013918(0x400);
            }
            func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
            func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
        }
        break;
    }

    case 23:
        if (camera.unk134 == 0) {
            if (spyro.unk13e[1] & 0x80) {
                func_800135A4(&camera.unk7c.pos[1], &D_80069260, camera.unk6c);
            } else {
                func_80014354();
                func_80013918(0x400);
            }
        }
        func_800142E0();
        camera.unk6c = spyro.m_WhirlwindPointer->angle.yaw * 0x10;
        func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
        func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
        func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
        func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
        if (!(camera.unk58 & 2)) {
            func_800136F0(&camera.unk7c.pos[0], &camera.nextCameraPosCartesian, &camera.unk60);
            camera.unk7c.pos[2].pos.azimuth = camera.unk7c.pos[0].pos.azimuth;
        }
        break;

    }
}

/**
 * ???() - func_level_12_8008B9AC() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_12_8008B9AC() {
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

void func_level_12_8008B9D4(int mode) {
    register int* state __asm__("$16");
    CameraPosition* position;
    register int one __asm__("$2");
    switch (mode) {
    case 3: case 0xC: case 0x17:
        state = &camera.unk50;
        __asm__("" : "=r"(state) : "0"(state));
        *state = 0;
        camera.unk140[0] = 0;
        camera.unk140[1] = 0;
        one = 1;
        goto shared;
    case 0xD:
        state = &camera.unk50;
        __asm__("" : "=r"(state) : "0"(state));
        one = 1;
        *state = 0;
        camera.unk140[0] = 0;
        camera.unk140[1] = one;
        break;
    default: return;
    }
shared:
    camera.unk140[2] = one;
    camera.unk140[5] = 0;
    camera.unk5c[0] = 0;
    position = (CameraPosition*)((char*)state + 0x2C);
    func_800142E0();
    func_800136F0(position, (Vector3D*)((char*)state - 0x28), (Vector3D*)((char*)state + 0x10));
    func_800138A0(position, position);
    func_800135A4((CameraPosition*)((char*)state + 0x54), position, 0);
}

extern int DecodedCameraMode __asm__("D_8006E044");
extern int DecodedCameraOverride __asm__("D_8006E160");
extern int DecodedCameraHeld __asm__("D_8006E538");
extern int DecodedCameraPressed __asm__("D_8006E53C");
extern unsigned char DecodedCameraPlayer[] __asm__("D_80070328");
extern int DecodedCameraModeTable[] __asm__("D_80068CAC");
/* SCUS-94467 USA Rev0 8008BAC4..8008BD14, 149 code words.
 * Reuses verified func_level_11_80091CA8. Mode13 input and fresh override equality path with shared table return.
 * Original dispatch entries, access widths and helper order are retained.
 * Units, table/flag producers and caller cadence remain open.
 * Empty constraints preserve compiler lifetime/control flow without instructions.
 * AI generated; not human reviewed. See batch2026-10-05-1676.
 */
void func_level_12_8008BAC4(void) {
    register int mode __asm__("$3") = DecodedCameraMode;
    register int next __asm__("$4");
    register int index __asm__("$2");
    switch (mode) {
    case 3:
        next = DecodedCameraOverride;
        if (next) goto change;
        if (DecodedCameraHeld & 16) {
            register int enabled __asm__("$2") = DecodedCameraPlayer[0x1B9];
            next = 7;
            if (enabled) goto change;
        }
        if (DecodedCameraPressed & 12) {
            next = 8;
            goto change;
        }
        index = *(int*)(DecodedCameraPlayer + 0x48);
        __asm__("" : : : "memory");
        mode = DecodedCameraMode;
        goto compareTable;
    case 12:
        if (DecodedCameraHeld & 16) {
            register int enabled __asm__("$2") = DecodedCameraPlayer[0x1B9];
            next = 7;
            if (enabled) goto change;
        }
        if (DecodedCameraPressed & 12) {
            next = 8;
            goto change;
        }
        next = DecodedCameraOverride;
        if (!next) {
tableRoute:
            next = DecodedCameraModeTable[*(int*)(DecodedCameraPlayer + 0x48)];
            __asm__("" : "=r"(next) : "0"(next));
            goto change;
        }
        __asm__("" : : : "memory");
        if (next != DecodedCameraMode) goto change;
        mode = DecodedCameraModeTable[*(int*)(DecodedCameraPlayer + 0x48)];
        next = 2;
        if (mode != 2) return;
        goto change;
    case 13:
        if (DecodedCameraHeld & 16) {
            register int enabled __asm__("$2") = DecodedCameraPlayer[0x1B9];
            next = 7;
            if (enabled) goto change;
        }
        if (DecodedCameraPressed & 12) {
            next = 8;
            goto change;
        }
        next = DecodedCameraOverride;
        if (!next) goto tableRoute;
        __asm__("" : : : "memory");
        if (next == DecodedCameraMode) return;
        goto change;
    case 23:
        next = DecodedCameraOverride;
        if (next) goto change;
        index = *(int*)(DecodedCameraPlayer + 0x48);
compareTable:
        next = DecodedCameraModeTable[index];
        if (next == mode) return;
        if (next) goto change;
defaultMode:
        next = 6;
        break;
    default:
        return;
    }
change:
    func_80016764(next);
}
