#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 35

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

extern CameraPosition D_80069184, D_80069288;
extern Moby* D_8006C550;
extern Moby* D_8006C704;
int func_8001A358(Vector3D*, int);
int func_8004F334(Vector3D*, Vector3D*);
/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * 8008BD08..8008C21C. Mode3 upstream level11 camera baseline;
 * original mode21/25 instructions preserve access widths and actor rereads.
 * Units, helper semantics, actor-tag producer and cadence remain unresolved.
 * Test: 325 original linked code words and complete retail hashes.
 */
void func_level_35_8008BD08(void) {
    int tableIndex;
    int turnDelta;
    Moby* actor;
    int* actorData;

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
        case 25:
            if (camera.unk134 == 0) {
                func_800135A4(&camera.unk7c.pos[1], &D_80069288, camera.unk6c);
            }
            if (func_8001A358(&camera.nextCameraPosCartesian, 0x400)) {
                camera.unk7c.pos[1].pos.elevation = 0x12C;
            } else {
                actor = D_8006C550;
                camera.unk7c.pos[1].pos.elevation = 0xF5;
                while (actor < D_8006C704) {
                    if (actor->mobyClass == 0x3AD) {
                        actorData = (int*)actor->mobyTag;
                        if (actorData[0] >=
                            func_8004F334(&camera.nextCameraPosCartesian, &actor->position)) {
                            camera.unk7c.pos[1].pos.elevation = actorData[1];
                        }
                    }
                    actor++;
                }
            }
            func_800142E0();
            func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
            MIN(camera.unk7c.pos[5].pos.azimuth, 0x100);
            func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
            func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
            break;
    }
}


/**
 * ???() - func_level_35_8008C21C() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_35_8008C21C() {
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

void func_level_35_8008C244(int mode) {
    register int* state __asm__("$16");
    CameraPosition* position;
    register int one __asm__("$2");
    switch (mode) {
        case 3:
            one = 1;
            MATCHING_KEEP_CLOBBER(one, "$16");
            state = &camera.unk50;
            __asm__("" : "=r"(state) : "0"(state), "r"(one));
            *state = 0;
            camera.unk140[0] = 0;
            camera.unk140[1] = 0;
            camera.unk140[2] = one;
            goto shared;
        case 0x15:
            state = &camera.unk50;
            MATCHING_KEEP(state);
            one = 1;
            *state = 0;
            camera.unk140[0] = 0;
            camera.unk140[1] = one;
            camera.unk140[2] = one;
            goto shared;
        case 0x19:
            one = 1;
            MATCHING_KEEP_CLOBBER(one, "$16");
            state = &camera.unk50;
            __asm__("" : "=r"(state) : "0"(state), "r"(one));
            *state = 0;
            camera.unk140[0] = one;
            camera.unk140[1] = one;
            camera.unk140[2] = 0;
            break;
        default:
            return;
    }
shared:
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
/* USA SCUS-94467 Rev 0, 0x8008C368..0x8008C4CC, 89 words.
 * The original mode dispatch, input masks and word-indexed lookup are retained.
 * Raw player byte/word offsets are not assigned new semantic or unit claims.
 * Caller cadence remains unresolved. AI generated; not yet human reviewed.
 */
void func_level_35_8008C368(void) {
    register int mode __asm__("$3") = DecodedCameraMode;
    register int next __asm__("$4");
    register int index __asm__("$2");
    switch (mode) {
        /* The default mode responds to the existing override and input words. */
        case 3:
            next = DecodedCameraOverride;
            if (next)
                goto change;
            if ((DecodedCameraHeld & 16) && DecodedCameraPlayer[0x1B9]) {
                next = 7;
                goto change;
            }
            if (DecodedCameraPressed & 12) {
                next = 8;
                goto change;
            }
            index = *(int*)(DecodedCameraPlayer + 0x48);
            mode = DecodedCameraMode;
            goto lookup;
        /* Keep the two lookup paths and their shared zero fallback distinct. */
        case 25:
            next = DecodedCameraOverride;
            if (next)
                goto change;
            next = DecodedCameraModeTable[*(int*)(DecodedCameraPlayer + 0x48)];
            if (next == mode)
                return;
            if (!next)
                goto fallback;
            goto change;
        case 21:
            next = DecodedCameraOverride;
            if (next)
                goto change;
            index = *(int*)(DecodedCameraPlayer + 0x48);
        lookup:
            next = DecodedCameraModeTable[index];
            if (next == mode)
                return;
            if (next)
                goto change;
        fallback:
            next = 6;
            break;
        default:
            return;
    }
change:
    func_80016764(next);
}
