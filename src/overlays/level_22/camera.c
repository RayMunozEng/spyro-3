#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 22

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

extern CameraPosition D_80069184, D_80069300, D_8006938C;
extern int D_8006E538;
/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * 8009A254..8009AB7C,587 instructions plus dispatch/padding.
 * Verified camera cases4/12/21/23/36; original modes30/38 retained.
 * Signed LH E040 and native205 shift8 reuse batch1811 arithmetic.
 * Units, helper/input/table/object producers and cadence remain unresolved.
 * Test: original linked code/dispatch words and complete retail hashes.
 */
void func_level_22_8009A254(void) {
    int tableIndex;
    Vector3D* temp_a0;
    tableIndex = (camera.unk138 + 2) >> 2;
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
        case 21:
            func_80013918(0x400);
            if (camera.unk148[2] != 0) {
                camera.unk140[2] = 1;
            } else {
                camera.unk140[2] = 0;
            }
            if (camera.unk134 == 0) {
                func_800135A4(&camera.unk7c.pos[1], &D_80069184, camera.unk6c);
            } else {
                camera.unk148[2] = 0;
            }
            func_800142E0();
            func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
            func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
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
        case 30: {
            int turnDelta;
            int* object = **(int***)((char*)&spyro + 0x250);
            Vector3D delta;
            if (camera.unk134 == 0) {
                if (camera.unk5c[0] == 0 &&
                    func_8004F284(spyro.rotation.yaw, camera.unk7c.pos[0].pos.azimuth) < 0x140 &&
                    (D_8006E538 & 3) != 3 && object[11] == 0) {
                    func_80014450();
                } else {
                    func_80014354();
                }
                if (object[11] != 0) {
                    camera.unk7c.pos[1].pos.radius = 0xC00;
                    camera.unk7c.pos[1].pos.elevation = 0x400;
                    camera.unk7c.pos[1].yaw = -0x80;
                }
                func_8004F178(&delta, &spyro.unk7a[2]);
                func_8004F110(&delta, 2);
                func_8004F194(&delta, &spyro.position, &delta);
                func_8004F1C8(&delta, &delta, &camera.nextCameraPosCartesian);
                turnDelta = (func_8004E880(delta.x, delta.y, 1) - camera.unk48) & 0xFFF;
                if (turnDelta > 0x800)
                    turnDelta -= 0x1000;
                turnDelta = turnDelta * 205 >> 8;
                MAX(turnDelta, 0xC0);
                MIN(turnDelta, -0xC0);
                camera.unk7c.pos[1].pitch = (ABS(turnDelta) >= 9) ? turnDelta : 0;
                func_80013918(0x400);
            }
            func_800142E0();
            func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
            func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
            if (!(camera.unk58 & 2)) {
                func_800136F0(&camera.unk7c.pos[0], &camera.nextCameraPosCartesian, &camera.unk60);
                camera.unk7c.pos[2].pos.azimuth = camera.unk7c.pos[0].pos.azimuth;
            }
            break;
        }
        case 36:
            if (spyro.unk5 == 5) {
                temp_a0 = &camera.unk60;
                func_8004F178(temp_a0, &spyro.position);
                if (camera.unk134 == 0) {
                    func_800135A4(&camera.unk7c.pos[1], &D_80068F7C, camera.unk6c + 0x800);
                    camera.unk7c.pos[1].pos.elevation = 0x320;
                }
            } else {
                func_800142E0();
                if (func_8004EDE8(&spyro.unk7a[2], 0) >= 0x180) {
                    camera.unk6c = func_8004E880(spyro.unk7a[2].x, spyro.unk7a[2].y, 1);
                }
                if (camera.unk134 == 0) {
                    func_800135A4(&camera.unk7c.pos[1], &D_80068F7C, camera.unk6c);
                }
            }
            func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
            if ((spyro.unk5 != 5) && (camera.unk7c.pos[5].pos.azimuth < 0x100)) {
                camera.unk7c.pos[5].pos.azimuth = 0x100;
            }
            func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
            func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
            camera.unk1c4[5] = -spyro.unk13e[0];
            break;
        case 38:
            if (camera.unk134 == 0) {
                func_80014354();
                camera.unk7c.pos[1].pos.radius = 0x200;
                camera.unk7c.pos[1].pos.elevation = 0x400;
                camera.unk7c.pos[1].yaw = 0;
            }
            func_800142E0();
            func_800135A4(&camera.unk7c.pos[5], &D_80069300, 0);
            camera.unk7c.pos[5].pos.azimuth = D_8006929C[tableIndex].pos.azimuth;
            func_800135A4(&camera.unk7c.pos[6], &D_8006938C, 0);
            func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
            func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
            break;
    }
}

/**
 * ???() - func_level_22_8009AB80() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_22_8009AB80() {
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

extern int DecodedCameraInitTimer __asm__("D_8006E048");
extern unsigned char DecodedCameraInit138 __asm__("D_8006E138");
extern unsigned char DecodedCameraInit139 __asm__("D_8006E139");
extern unsigned char DecodedCameraInit13A __asm__("D_8006E13A");
extern unsigned char DecodedCameraInit13D __asm__("D_8006E13D");
extern unsigned char DecodedCameraInit054 __asm__("D_8006E054");
void func_level_22_8009ABA8(int state) {
    register int* timer __asm__("$16");
    CameraPosition* position;
    switch (state) {
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 22:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 37:
            break;
        case 4:
        case 12:
        case 23:
        case 36:
            timer = &DecodedCameraInitTimer;
            *timer = 0;
            DecodedCameraInit138 = 0;
            DecodedCameraInit139 = 0;
            DecodedCameraInit13A = 1;
            DecodedCameraInit13D = 0;
            DecodedCameraInit054 = 0;
            MATCHING_KEEP_CLOBBER(timer, "memory");
            goto initialize;
        case 21:
            timer = &DecodedCameraInitTimer;
            *timer = 0;
            DecodedCameraInit138 = 0;
            DecodedCameraInit139 = 1;
            DecodedCameraInit13A = 1;
            DecodedCameraInit13D = 0;
            DecodedCameraInit054 = 0;
            MATCHING_KEEP_CLOBBER(timer, "memory");
            goto initialize;
        case 30:
        case 38:
            timer = &DecodedCameraInitTimer;
            *timer = 0;
            DecodedCameraInit138 = 0;
            DecodedCameraInit139 = 0;
            DecodedCameraInit13A = 1;
            DecodedCameraInit13D = 0;
        initialize:
            MATCHING_KEEP(timer);
            func_800142E0();
            position = (CameraPosition*)((char*)timer + 0x2C);
            func_800136F0(position, (Vector3D*)((char*)timer - 0x28),
                          (Vector3D*)((char*)timer + 0x10));
            func_800138A0(position, position);
            func_800135A4((CameraPosition*)((char*)timer + 0x54), position, 0);
            break;
    }
}

extern int DecodedCameraThirdModeTable[] __asm__("D_80068CAC");
extern int DecodedCameraFourthModeTable[] __asm__("D_80068CAC");
/* AI-generated adaptation; not human reviewed. SCUS-94467 USA Rev0
 * 8009ACDC..8009B090, 237 instructions plus original dispatch.
 * Verified level34 selector baseline with original modes4/12/36.
 * Table aliases identify the same retail table and preserve distinct paths.
 * Units, helper/input/table/tag producers and cadence remain unresolved.
 * Test: original linked code/dispatch words and full retail hashes.
 */
extern int DecodedCameraOtherModeTable[] __asm__("D_80068CAC");
extern int DecodedCameraMode __asm__("D_8006E044");
extern int DecodedCameraOverride __asm__("D_8006E160");
extern int DecodedCameraHeld __asm__("D_8006E538");
extern int DecodedCameraPressed __asm__("D_8006E53C");
extern unsigned char DecodedCameraPlayer[] __asm__("D_80070328");
extern int DecodedCameraModeTable[] __asm__("D_80068CAC");
extern int DecodedCameraPlayerMode __asm__("D_8006E344");
void func_level_22_8009ACDC(void) {
    register int mode __asm__("$3");
    register int next __asm__("$4");
    register int index __asm__("$2");
    switch (DecodedCameraMode) {
        case 4:
            next = DecodedCameraOverride;
            if (next)
                goto change;
            if (DecodedCameraHeld & 16) {
                index = DecodedCameraPlayer[0x1B9];
                MATCHING_KEEP_VOLATILE_CLOBBER(index, "$4");
                next = 7;
                if (index)
                    goto change;
            }
            if (DecodedCameraPressed & 12) {
                next = 8;
                goto change;
            }
            index = *(int*)(DecodedCameraPlayer + 0x48);
            mode = DecodedCameraMode;
            next = DecodedCameraFourthModeTable[index];
            if (mode == next)
                return;
            if (next)
                goto change;
            MATCHING_OBSERVE(next);
            next = 6;
            goto change;
        case 12:
            if ((DecodedCameraHeld & 16) && DecodedCameraPlayer[0x1B9]) {
                next = 7;
                goto change;
            }
            if (DecodedCameraPressed & 12) {
                next = 8;
                goto change;
            }
            next = DecodedCameraOverride;
            if (!next) {
                next = DecodedCameraModeTable[*(int*)(DecodedCameraPlayer + 0x48)];
                goto change;
            }
            if (next != DecodedCameraMode)
                goto change;
            index = *(int*)(DecodedCameraPlayer + 0x48);
            mode = DecodedCameraModeTable[index];
            MATCHING_KEEP_VOLATILE_CLOBBER(mode, "$2");
            index = 2;
            MATCHING_KEEP(index);
            if (mode != index)
                return;
            next = 2;
            goto change;

        case 21:
            next = DecodedCameraOverride;
            if (next)
                goto change;
            index = *(int*)(DecodedCameraPlayer + 0x48);
            mode = DecodedCameraMode;
            next = DecodedCameraModeTable[index];
            if (mode == next)
                return;
            if (next)
                goto change;
            MATCHING_OBSERVE(next);
            next = 6;
            goto change;
        case 23:
            next = DecodedCameraOverride;
            if (next)
                goto change;
            index = *(int*)(DecodedCameraPlayer + 0x48);
            mode = DecodedCameraMode;
            next = DecodedCameraOtherModeTable[index];
            if (mode == next)
                return;
            if (next)
                goto change;
            MATCHING_OBSERVE(next);
            next = 6;
            goto change;
        case 30: {
            register int* object __asm__("$5") = **(int***)(DecodedCameraPlayer + 0x250);
            next = DecodedCameraOverride;
            if (next)
                goto change;
            if ((DecodedCameraPressed & 12) && DecodedCameraPlayerMode != 7) {
                next = 8;
                goto change;
            }
            index = *(int*)(DecodedCameraPlayer + 0x48);
            mode = DecodedCameraMode;
            next = DecodedCameraModeTable[index];
            if (mode == next)
                goto firstFlags;
            if (next)
                goto change;
            /* Keep this retail fallback distinct; the constraint emits no code. */
            MATCHING_OBSERVE(next);
            next = 6;
            goto change;
        firstFlags:
            if (!object[11] || !object[12])
                return;
            next = 38;
            goto change;
        }
        case 36:
            next = DecodedCameraOverride;
            if (next)
                goto change;
            index = *(int*)(DecodedCameraPlayer + 0x48);
            mode = DecodedCameraMode;
            next = DecodedCameraThirdModeTable[index];
            if (mode == next)
                return;
            if (next)
                goto change;
            MATCHING_OBSERVE(next);
            next = 6;
            goto change;
        case 38: {
            register int* object __asm__("$3") = **(int***)(DecodedCameraPlayer + 0x250);
            next = DecodedCameraOverride;
            if (next)
                goto change;
            next = DecodedCameraModeTable[*(int*)(DecodedCameraPlayer + 0x48)];
            if (next == 30)
                goto secondFlags;
            if (next)
                goto change;
            next = 6;
            goto change;
        secondFlags:
            next = 30;
            if (!object[11])
                goto change;
            if (object[12])
                return;
            break;
        }
        default:
            return;
    }
change:
    func_80016764(next);
}
