#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 42

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

extern CameraPosition D_80069274, D_80069044, D_80069210;
/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * 8008F4FC..8008FB64,411 code words plus30 dispatch/padding.
 * Verified native camera modes4/23/32, original modes15/16 and
 * mode32 radius input1800, signed limits834/1194 preserved.
 * Raw units, helper/input/table producers and cadence remain unresolved.
 * Test: original linked code/dispatch words and complete retail hashes.
 */
void func_level_42_8008F4FC(void) {
    int tableIndex = (camera.unk138 + 2) >> 2;
    MAX(tableIndex, 4);
    switch (camera.cameraState) {
        case 4: {
            int pitchDelta;
            if ((camera.unk134 == 0) && (game.state != 7)) {
                func_800135A4(&camera.unk7c.pos[1], &D_80069008, camera.unk6c);
                camera.unk7c.pos[1].pos.elevation = -spyro.rotation.pitch;

                pitchDelta = (-spyro.rotation.pitch - camera.unk7c.pos[0].pos.elevation) >> 2;
                MAX(pitchDelta, 0xC0);
                MIN(pitchDelta, -0xC0);

                camera.unk7c.pos[1].yaw = (ABS(pitchDelta) >= 9) ? pitchDelta : 0;
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
        }
        case 15: {
            int angle;
            func_800135A4(&camera.unk7c.pos[1], &D_80069274, 0);
            angle = spyro.unk7b & 0xFFF;
            if (angle > 0x800)
                angle -= 0x1000;
            camera.unk7c.pos[1].pitch = ABS(angle) > 0x400 ? 0x80 : -0x80;
            func_800142E0();
            camera.unk6c = 0;
            func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
            func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
            break;
        }
        case 16:
            func_80013918(0x400);
            if (camera.unk148[2] != 0) {
                camera.unk140[2] = 1;
            } else {
                camera.unk140[2] = 0;
            }
            if (camera.unk134 == 0) {
                func_800135A4(&camera.unk7c.pos[1], &D_80069044, camera.unk6c);
            } else {
                camera.unk148[2] = 0;
            }
            func_800142E0();
            func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
            MIN(camera.unk7c.pos[5].pos.elevation, 0x40);
            func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
            func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
            if (!(camera.unk58 & 2)) {
                func_800136F0(&camera.unk7c.pos[0], &camera.nextCameraPosCartesian, &camera.unk60);
                camera.unk7c.pos[2].pos.azimuth = camera.unk7c.pos[0].pos.azimuth;
            }
            break;
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
        case 32:
            if (camera.unk134 == 0) {
                func_800135A4(&camera.unk7c.pos[1], &D_80069210, camera.unk6c);
                camera.unk7c.pos[1].pos.elevation -= spyro.rotation.pitch;
                camera.unk7c.pos[1].pitch = -spyro.rotation.roll >> 2;
                camera.unk7c.pos[1].pos.radius += (spyro.unk8[0] - 0x1800) >> 2;
                MIN(*(int*)&camera.unk7c.pos[1].pos.radius, 0x834);
                MAX(*(int*)&camera.unk7c.pos[1].pos.radius, 0x1194);
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
            break;
    }
}

/**
 * ???() - func_level_42_8008FB68() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_42_8008FB68() {
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

extern int D_8006E048, D_8006E064;
extern unsigned char D_8006E138, D_8006E139, D_8006E13A, D_8006E13D, D_8006E054;
extern CameraPosition D_8006E074, D_8006E09C;
extern CameraPosition DecodedSettleTarget __asm__("D_8006E074");
extern CameraPosition DecodedSettleInput __asm__("D_8006E074");
extern CameraPosition DecodedSettleFinal __asm__("D_8006E074");
extern Vector3D D_8006E020, D_8006E058, D_8006E17C;
void func_8004F178(Vector3D*, Vector3D*);
void func_level_42_8008FB90(int mode) {
    register int* base __asm__("$16");
    register CameraPosition* position __asm__("$17");
    register int* copyBase __asm__("$17");
    register CameraPosition* copiedPosition __asm__("$16");
    switch (mode) {
        case 4:
        case 23:
        case 32:
            base = &D_8006E048;
            *base = 0;
            D_8006E138 = 0;
            D_8006E139 = 0;
            D_8006E13A = 1;
            D_8006E13D = 0;
            D_8006E054 = 0;
            func_800142E0();
            position = (CameraPosition*)((char*)base + 44);
            MATCHING_KEEP_VOLATILE(position);
            goto settle;
        case 15:
            base = &D_8006E048;
            *base = 0;
            D_8006E138 = 1;
            D_8006E139 = 1;
            D_8006E13A = 0;
            D_8006E13D = 0;
            D_8006E054 = 0;
            func_800142E0();
            position = (CameraPosition*)((char*)base + 44);
            MATCHING_KEEP_VOLATILE(position);
            func_800136F0(position, (Vector3D*)((char*)base - 40), (Vector3D*)((char*)base + 16));
            func_800138A0(position, position);
            func_800135A4((CameraPosition*)((char*)base + 84), position, 0);
            break;
        case 16:
            copyBase = &D_8006E048;
            *copyBase = 0;
            D_8006E138 = 0;
            D_8006E139 = 0;
            D_8006E13A = 0;
            D_8006E13D = 0;
            D_8006E054 = 0;
            func_800142E0();
            copiedPosition = (CameraPosition*)((char*)copyBase + 44);
            MATCHING_KEEP_VOLATILE(copiedPosition);
        settle:
            func_800136F0(&DecodedSettleTarget, &D_8006E020, &D_8006E058);
            func_800138A0(&D_8006E074, &DecodedSettleInput);
            func_800135A4(&D_8006E09C, &DecodedSettleFinal, 0);
            break;
    }
}

extern int DecodedCameraMode __asm__("D_8006E044");
extern int DecodedCameraOverride __asm__("D_8006E160");
extern int DecodedCameraHeld __asm__("D_8006E538");
extern int DecodedCameraPressed __asm__("D_8006E53C");
extern unsigned char DecodedCameraPlayer[] __asm__("D_80070328");
extern int DecodedCameraModeTable[] __asm__("D_80068CAC");
/* SCUS-94467 USA Rev0 8008FD1C..8008FEB8, 104 code words.
 * Reuses verified func_level_23_80096270. Modes4/32 input, mode15 fresh override, mode16 override/input, mode23 table.
 * Original dispatch entries, access widths and helper order are retained.
 * Units, table/flag producers and caller cadence remain open.
 * Empty constraints preserve compiler lifetime/control flow without instructions.
 * AI generated; not human reviewed. See batch2026-10-05-1673.
 */
void func_level_42_8008FD1C(void) {
    register int mode __asm__("$3");
    register int next __asm__("$4");
    register int index __asm__("$2");
    switch (DecodedCameraMode) {
        case 4:
        case 32:
            next = DecodedCameraOverride;
            if (next)
                goto change;
            if (DecodedCameraHeld & 16) {
                register int enabled __asm__("$2") = DecodedCameraPlayer[0x1B9];
                if (enabled)
                    goto enable;
            }
            if (DecodedCameraPressed & 12) {
                next = 8;
                goto change;
            }
            goto indexedRoute;
        case 15:
            next = DecodedCameraOverride;
            if (!next) {
            tableRoute:
                next = DecodedCameraModeTable[*(int*)(DecodedCameraPlayer + 0x48)];
                goto change;
            }
            MATCHING_BARRIER("memory");
            if (next == DecodedCameraMode)
                return;
            goto change;
        case 16:
            next = DecodedCameraOverride;
            if (!next)
                goto tableRoute;
            if (next != 16)
                goto change;
            if (!(DecodedCameraHeld & 16) || !DecodedCameraPlayer[0x1B9])
                return;
        enable:
            next = 7;
            goto change;
        case 23:
            next = DecodedCameraOverride;
            if (next)
                goto change;
        indexedRoute:
            index = *(int*)(DecodedCameraPlayer + 0x48);
            mode = DecodedCameraMode;
            next = DecodedCameraModeTable[index];
            if (mode == next)
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
