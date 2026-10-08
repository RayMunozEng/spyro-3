#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 26

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

extern CameraPosition D_80069300, D_8006938C;
extern int D_8006E538;
/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0.
 * Native camera modes30/38 reused from verified batch1818; mode13
 * reused from verified level12 camera when present. Each original
 * copy compared independently; raw units, helper/table/object/input
 * producers and caller cadence remain unresolved.
 * Test: every original linked word and complete retail hashes.
 */
void func_level_26_8008A828(void) {
    int tableIndex = (camera.unk138 + 2) >> 2;
    MAX(tableIndex,4);
    switch (camera.cameraState) {
    case 30: {
        int turnDelta;
        int* object = **(int***)( (char*)&spyro + 0x250);
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
            func_8004F110(&delta,2);
            func_8004F194(&delta,&spyro.position,&delta);
            func_8004F1C8(&delta,&delta,&camera.nextCameraPosCartesian);
            turnDelta = (func_8004E880(delta.x,delta.y,1) - camera.unk48) & 0xFFF;
            if (turnDelta > 0x800) turnDelta -= 0x1000;
            turnDelta = turnDelta * 205 >> 8;
            MAX(turnDelta,0xC0);
            MIN(turnDelta,-0xC0);
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
 * ???() - func_level_26_8008ABAC() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_26_8008ABAC() {
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

void func_level_26_8008ABD4(int mode) {
    if (mode == 0x1E || mode == 0x26) {
        register int* state __asm__("$16") = &camera.unk50;
        CameraPosition* position;
        /* Keep the original shared address base; this constraint emits no code. */
        __asm__("" : "=r"(state) : "0"(state));
        *state = 0;
        camera.unk140[0] = 0;
        camera.unk140[1] = 0;
        camera.unk140[2] = 1;
        camera.unk140[5] = 0;
        position = (CameraPosition*)((char*)state + 0x2C);
        func_800142E0();
        func_800136F0(position, (Vector3D*)((char*)state - 0x28), (Vector3D*)((char*)state + 0x10));
        func_800138A0(position, position);
        func_800135A4((CameraPosition*)((char*)state + 0x54), position, 0);
    }
}

extern int DecodedCameraMode __asm__("D_8006E044");
extern int DecodedCameraOverride __asm__("D_8006E160");
extern int DecodedCameraHeld __asm__("D_8006E538");
extern int DecodedCameraPressed __asm__("D_8006E53C");
extern unsigned char DecodedCameraPlayer[] __asm__("D_80070328");
extern int DecodedCameraModeTable[] __asm__("D_80068CAC");
extern int DecodedCameraPlayerMode __asm__("D_8006E344");
/* USA SCUS-94467 Rev 0, 0x8008AC74..0x8008ADD8, 89 words.
 * Retain mode 30/38 dispatch and the original two pointer reads at player
 * offset 0x250, followed by raw object word tests at 0x2C and 0x30.
 * No new coordinate scale, object semantics or caller cadence is claimed.
 * AI generated; not yet human reviewed.
 */
void func_level_26_8008AC74(void) {
    register int mode __asm__("$3") = DecodedCameraMode;
    register int next __asm__("$4");
    register int index __asm__("$2");
    switch (mode) {
    case 30: {
        register int* object __asm__("$5") = **(int***)(DecodedCameraPlayer + 0x250);
        next = DecodedCameraOverride;
        if (next) goto change;
        if ((DecodedCameraPressed & 12) && DecodedCameraPlayerMode != 7) {
            next = 8;
            goto change;
        }
        index = *(int*)(DecodedCameraPlayer + 0x48);
        mode = DecodedCameraMode;
        next = DecodedCameraModeTable[index];
        if (mode == next) goto firstFlags;
        if (next) goto change;
        /* Keep this retail fallback distinct; the constraint emits no code. */
        __asm__("" : : "r"(next));
        next = 6;
        goto change;
    firstFlags:
        if (!object[11] || !object[12]) return;
        next = 38;
        goto change;
    }
    case 38: {
        register int* object __asm__("$3") = **(int***)(DecodedCameraPlayer + 0x250);
        next = DecodedCameraOverride;
        if (next) goto change;
        next = DecodedCameraModeTable[*(int*)(DecodedCameraPlayer + 0x48)];
        if (next == 30) goto secondFlags;
        if (next) goto change;
        next = 6;
        goto change;
    secondFlags:
        next = 30;
        if (!object[11]) goto change;
        if (object[12]) return;
        break;
    }
    default:
        return;
    }
change:
    func_80016764(next);
}
