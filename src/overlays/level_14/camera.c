#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 14

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

extern CameraPosition D_80069080;
/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * 800990A4..80099450, 235 original instructions. Reuses upstream mode4
 * and verified mode13; original mode19 uses its distinct camera table.
 * Units, helper/target/table producers and cadence remain unresolved.
 * Test: original linked code words and complete retail hashes.
 */
void func_level_14_800990A4() {
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

        case 19: {
            Vector3D delta;
            func_800142E0();
            if (camera.unk16c != 0) {
                func_8004F1C8(&delta, &camera.unk16c->position, (Vector3D*)&spyro);
                camera.unk6c = func_8004E880(delta.x, delta.y, 1);
                if (camera.unk134 == 0) {
                    func_800135A4(&camera.unk7c.pos[1], &D_80069080, camera.unk6c);
                    func_80013918(0x400);
                }
                func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
                func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
                func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
                func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
            }
            break;
        }
    }
}

/**
 * ???() - func_level_14_80099450() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_14_80099450() {
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

void func_level_14_80099478(int mode) {
    register int* state __asm__("$16");
    CameraPosition* position;
    register int one __asm__("$2");
    switch (mode) {
        case 4:
            state = &camera.unk50;
            MATCHING_KEEP(state);
            *state = 0;
            camera.unk140[0] = 0;
            camera.unk140[1] = 0;
            one = 1;
            goto shared;
        case 0xD:
        case 0x13:
            state = &camera.unk50;
            MATCHING_KEEP(state);
            one = 1;
            *state = 0;
            camera.unk140[0] = 0;
            camera.unk140[1] = one;
            break;
        default:
            return;
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
/* USA SCUS-94467 Rev 0, 0x80099568..0x800996EC, 97 words.
 * Baseline: the verified level-35 camera selector, retaining this overlay's
 * mode 4/13/19 branches, raw input masks and player byte/word offsets.
 * The empty memory constraint preserves the retail fresh mode-word read;
 * it emits no instructions. Mode IDs and table values remain raw integers.
 * Caller cadence and player/table producers are unresolved.
 * AI generated; not yet human reviewed.
 */
void func_level_14_80099568(void) {
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
            next = DecodedCameraModeTable[index];
            if (mode == next)
                return;
            if (next)
                goto change;
            next = 6;
            goto change;
        case 13:
        case 19:
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
                goto change;
            }
            if (next == DecodedCameraMode)
                return;
            break;
        default:
            return;
    }
change:
    func_80016764(next);
}
