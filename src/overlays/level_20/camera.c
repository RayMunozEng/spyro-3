#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 20

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * original camera modes4/17; complete 200-instruction copies independently
 * compared. Baseline upstream level10_8008AD44, original bounds and copies.
 * Units, helper/input/table producers and cadence remain unresolved.
 * Test: each original linked code word and complete retail hashes.
 */
void func_level_20_8008BF8C() {
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

        case 17:
            if (camera.unk168 != camera.cameraState)
                break;

            if (camera.unk134 == 0) {
                func_800135A4(&camera.unk7c.pos[1], &camera.unk170, camera.unk6c);
            }
            func_8004F178(&camera.unk60, &camera.unk184);
            camera.unk6c = 0;
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
}

/**
 * ???() - func_level_20_8008C2AC() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_20_8008C2AC() {
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

extern CameraPosition DecodedCameraCurrentA __asm__("D_8006E074");
extern CameraPosition DecodedCameraCurrentB __asm__("D_8006E074");
extern CameraPosition DecodedCameraCurrentC __asm__("D_8006E074");
extern CameraPosition DecodedCameraTarget __asm__("D_8006E09C");
void func_level_20_8008C310(int mode) {
    switch (mode) {
        case 4: {
            register int* state __asm__("$16") = &camera.unk50;
            register CameraPosition* position __asm__("$17");
            *state = 0;
            camera.unk140[0] = 0;
            camera.unk140[1] = 0;
            camera.unk140[2] = 1;
            camera.unk140[5] = 0;
            camera.unk5c[0] = 0;
            func_800142E0();
            position = (CameraPosition*)((char*)state + 0x2C);
            MATCHING_KEEP(position);
            func_800136F0(position, (Vector3D*)((char*)state - 0x28),
                          (Vector3D*)((char*)state + 0x10));
            break;
        }
        case 0x11: {
            register int* state __asm__("$17") = &camera.unk50;
            register Vector3D* target __asm__("$18") = (Vector3D*)((char*)state + 0x10);
            register CameraPosition* position __asm__("$16");
            *state = 0;
            camera.unk140[0] = 0;
            camera.unk140[1] = 1;
            camera.unk140[2] = 1;
            camera.unk140[5] = 0;
            func_8004F178(target, (Vector3D*)((char*)state + 0x134));
            position = (CameraPosition*)((char*)state + 0x2C);
            MATCHING_KEEP(position);
            *((int*)((char*)&camera + 0x6C)) = 0;
            func_800136F0(position, (Vector3D*)((char*)state - 0x28), target);
            break;
        }
        default:
            return;
    }
    func_800138A0(&DecodedCameraCurrentA, &DecodedCameraCurrentB);
    func_800135A4(&DecodedCameraTarget, &DecodedCameraCurrentC, 0);
}

extern int D_8006E044, D_8006E538, D_8006E53C, D_8006E160;
extern int D_80068CAC[];
extern int DecodedCameraStateTable[] __asm__("D_80068CAC");
void func_level_20_8008C438(void) {
    int next;
    register int mode __asm__("$3") = D_8006E044;
    switch (mode) {
        case 4:
            next = D_8006E160;
            if (!next) {
                if ((D_8006E538 & 0x10) && *((unsigned char*)&spyro + 0x1B9))
                    next = 7;
                else if (D_8006E53C & 0xC)
                    next = 8;
                else {
                    register int animation __asm__("$2") = spyro.animationState;
                    register int current __asm__("$3") = D_8006E044;
                    __asm__("" : "=r"(current) : "0"(current), "r"(animation));
                    animation *= 4;
                    MATCHING_KEEP(animation);
                    next = *(int*)((unsigned char*)DecodedCameraStateTable + animation);
                    if (current == next)
                        return;
                    if (!next)
                        next = 6;
                }
            }
            break;
        case 0x11:
            next = D_8006E160;
            if (!next)
                next = D_80068CAC[spyro.animationState];
            else if (next == mode)
                return;
            break;
        default:
            return;
    }
    func_80016764(next);
}
