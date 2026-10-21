#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 24

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * 80096480..800968A4, 265 original instructions. Upstream level10 mode4
 * and verified level12 modes12/23; original branch/access order retained.
 * Units, helper/target/table producers and cadence remain unresolved.
 * Test: original linked words and complete retail hashes.
 */
void func_level_24_80096480(void) {
    int tableIndex;
    int turnDelta;

    tableIndex = (camera.unk138 + 2) >> 2;
    MAX(tableIndex, 4);

    switch (camera.cameraState) {
        case 4:
            if ((camera.unk134 == 0) && (game.state != 7)) {
                func_800135A4(&camera.unk7c.pos[1], &D_80069008, camera.unk6c);
                camera.unk7c.pos[1].pos.elevation = -spyro.rotation.pitch;

                turnDelta = (-spyro.rotation.pitch - camera.unk7c.pos[0].pos.elevation) >> 2;
                MAX(turnDelta, 0xC0);
                MIN(turnDelta, -0xC0);

                camera.unk7c.pos[1].yaw = (ABS(turnDelta) >= 9) ? turnDelta : 0;
                camera.unk7c.pos[1].pitch = -spyro.rotation.roll >> 2;

                func_80013918(0x180);
                func_800139A4();
            }
            func_800142E0();
            func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
            MIN(camera.unk7c.pos[5].pos.azimuth, 0x80);
            MIN(camera.unk7c.pos[5].pos.elevation, 0x60);
            MIN(camera.unk7c.pos[5].pitch, 0x40);
            func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
            func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
            break;

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
 * ???() - func_level_24_800968A4() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_24_800968A4() {
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

void func_level_24_800968CC(int mode) {
    switch (mode) {
        case 4:
        case 0xC:
        case 0x17: {
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
            func_800136F0(position, (Vector3D*)((char*)state - 0x28),
                          (Vector3D*)((char*)state + 0x10));
            func_800138A0(position, position);
            func_800135A4((CameraPosition*)((char*)state + 0x54), position, 0);
            break;
        }
    }
}

extern int DecodedCameraMode __asm__("D_8006E044");
extern int DecodedCameraOverride __asm__("D_8006E160");
extern int DecodedCameraHeld __asm__("D_8006E538");
extern int DecodedCameraPressed __asm__("D_8006E53C");
extern unsigned char DecodedCameraPlayer[] __asm__("D_80070328");
extern int DecodedCameraModeTable[] __asm__("D_80068CAC");
/* Rev0 80096990..80096B68,118 words: verified level16 camera selector
 * baseline plus this overlay's mode4 and23 shared table path. Mode4
 * rereads the global mode after the player index; mode23 retains dispatch
 * mode. Raw masks/IDs only; units, caller cadence and table producers open.
 * AI generated; not yet human reviewed. */
void func_level_24_80096990(void) {
    register int mode __asm__("$3") = DecodedCameraMode;
    register int next __asm__("$4");
    register int index __asm__("$2");
    switch (mode) {
        case 4:
            next = DecodedCameraOverride;
            if (next)
                goto change;
            if (DecodedCameraHeld & 16) {
                register int enabled __asm__("$2") = DecodedCameraPlayer[0x1B9];
                next = 7;
                if (enabled)
                    goto change;
            }
            if (DecodedCameraPressed & 12) {
                next = 8;
                goto change;
            }
            index = *(int*)(DecodedCameraPlayer + 0x48);
            MATCHING_BARRIER("memory");
            mode = DecodedCameraMode;
            goto compareTable;
        case 12:
            if (DecodedCameraHeld & 16) {
                register int enabled __asm__("$2") = DecodedCameraPlayer[0x1B9];
                next = 7;
                if (enabled)
                    goto change;
            }
            if (DecodedCameraPressed & 12) {
                next = 8;
                goto change;
            }
            next = DecodedCameraOverride;
            if (!next) {
                next = DecodedCameraModeTable[*(int*)(DecodedCameraPlayer + 0x48)];
                MATCHING_KEEP(next);
                goto change;
            }
            MATCHING_BARRIER("memory");
            if (next != DecodedCameraMode)
                goto change;
            mode = DecodedCameraModeTable[*(int*)(DecodedCameraPlayer + 0x48)];
            next = 2;
            if (mode != 2)
                return;
            goto change;
        case 23:
            next = DecodedCameraOverride;
            if (next)
                goto change;
            index = *(int*)(DecodedCameraPlayer + 0x48);
        compareTable:
            next = DecodedCameraModeTable[index];
            if (next == mode)
                return;
            if (!next)
                next = 6;
            break;
        default:
            return;
    }
change:
    func_80016764(next);
}

