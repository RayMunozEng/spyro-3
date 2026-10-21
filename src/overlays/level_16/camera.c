#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 16

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

/* AI generated; not human reviewed.
 * SCUS-94467 USA Rev0 80086260..80086468: native signed shift,
 * upper-only index clamp, original target rereads and ordered table copies.
 * Table-copy baseline: upstream level10 camera func_level_10_8008AD44.
 * Camera/table units, target producer and caller cadence remain unresolved.
 * Acceptance: all 131 original linked words and complete retail hashes.
 */
void func_level_16_80086260(void) {
    int index = (camera.unk138 + 2) >> 2;
    if (index > 4)
        index = 4;
    switch (camera.cameraState) {
        case 12: {
            Vector3D delta;
            if (camera.unk134 == 0) {
                func_80014354();
                func_80013918(0x400);
            }
            func_800142E0();
            if (camera.unk16c != 0) {
                func_8004F1C8(&delta, &camera.unk16c->position, (Vector3D*)&spyro);
                camera.unk6c = func_8004E880(delta.x, delta.y, 1);
                func_800135A4(&camera.unk7c.pos[5], &D_8006929C[index], 0);
                func_800135A4(&camera.unk7c.pos[6], &D_80069328[index], 0);
                func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
                func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
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
                func_800135A4(&camera.unk7c.pos[5], &D_8006929C[index], 0);
                func_800135A4(&camera.unk7c.pos[6], &D_80069328[index], 0);
                func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
                func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
            }
            break;
        }
    }
}

/**
 * ???() - func_level_16_8008646C() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_16_8008646C() {
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

void func_level_16_80086494(int mode) {
    register int* state __asm__("$16");
    CameraPosition* position;
    register int one __asm__("$2");
    switch (mode) {
        case 0xC:
            state = &camera.unk50;
            MATCHING_KEEP(state);
            *state = 0;
            camera.unk140[0] = 0;
            camera.unk140[1] = 0;
            one = 1;
            goto shared;
        case 0xD:
            one = 1;
            MATCHING_KEEP_CLOBBER(one, "$16");
            state = &camera.unk50;
            __asm__("" : "=r"(state) : "0"(state), "r"(one));
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
/* USA SCUS-94467 Rev 0, 0x80086564..0x800866F8, 101 words.
 * Uses the verified camera selector structure and this overlay's original
 * mode 12/13 branches, masks and additional mode-table comparison with 2.
 * Empty constraints preserve separate lookup paths and fresh mode reads;
 * they emit no instructions. IDs/masks and player offsets remain raw values.
 * Caller cadence and player/table producers remain unresolved.
 * AI generated; not yet human reviewed.
 */
void func_level_16_80086564(void) {
    register int mode __asm__("$3") = DecodedCameraMode;
    register int next __asm__("$4");
    register int index __asm__("$2");
    switch (mode) {
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
        case 13:
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
            MATCHING_BARRIER("memory");
            if (next == DecodedCameraMode)
                return;
            break;
        default:
            return;
    }
change:
    func_80016764(next);
}
