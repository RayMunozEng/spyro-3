#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 25

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

extern CameraPosition D_800691D4;
/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * 800892FC..80089738, 271 original instructions. Upstream mode3 baseline;
 * mode29 reconstructed from original instructions, signed target-tag
 * inputs at +3C/+40, masked angles, original target reread after helper.
 * Units, helper semantics, tag producer and cadence remain unresolved.
 * Test: original linked words and complete retail hashes.
 */
void func_level_25_800892FC(void) {
    int tableIndex;
    int turnDelta;
    int* targetData;
    register int targetTurn __asm__("$4");
    register int angle __asm__("$2");
    register int reference __asm__("$3");

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

    case 29:
        targetData = (int*)camera.unk16c->mobyTag;
        if (camera.unk134 == 0) {
            func_800135A4(&camera.unk7c.pos[1], &D_800691D4, camera.unk6c);
            angle = camera.unk7c.pos[1].pos.elevation;
            reference = spyro.rotation.pitch;
            __asm__("" : "=r"(angle), "=r"(reference) : "0"(angle), "1"(reference));
            angle = angle - reference;
            reference = camera.unk7c.pos[0].pos.elevation;
            angle &= 0xFFF;
            camera.unk7c.pos[1].pos.elevation = angle;
            angle = angle - reference;
            reference = targetData[15];
            targetTurn = angle >> 2;
            reference >>= 1;
            __asm__("" : "=r"(targetTurn), "=r"(reference) : "0"(targetTurn), "1"(reference));
            targetTurn += reference;
            MAX(targetTurn, 0xC0);
            MIN(targetTurn, -0xC0);
            if (ABS(targetTurn) >= 9) {
                camera.unk7c.pos[1].yaw = (camera.unk7c.pos[1].yaw + targetTurn) & 0xFFF;
            }
            camera.unk7c.pos[1].pitch = targetData[16] >> 1;
            func_80013918(0xC0);
            func_800139A4();
        }
        func_800142E0();
        if (camera.unk16c != 0) {
            func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
            MIN(camera.unk7c.pos[5].pos.azimuth, 0x100);
            MIN(camera.unk7c.pos[5].pos.elevation, 0x60);
            MIN(camera.unk7c.pos[5].yaw, 0x80);
            MIN(camera.unk7c.pos[5].pitch, 0x80);
            func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
            func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
        }
        break;
    }
}


/**
 * ???() - func_level_25_80089738() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_25_80089738() {
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

void func_level_25_80089760(int mode) {
    if (mode == 3 || mode == 0x1D) {
        register int* state __asm__("$16") = &camera.unk50;
        CameraPosition* position;
        /* Keep the original shared address base; this constraint emits no code. */
        __asm__("" : "=r"(state) : "0"(state));
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

extern int D_8006E044, D_8006E538, D_8006E53C, D_8006E160;
extern int D_80068CAC[];
void func_level_25_80089808(void) {
    int next;
    if (D_8006E044 != 3 && D_8006E044 != 0x1D) return;
    next = D_8006E160;
    if (!next) {
        if ((D_8006E538 & 0x10) && *((unsigned char*)&spyro + 0x1B9)) next = 7;
        else if (D_8006E53C & 0xC) next = 8;
        else {
            register int animation __asm__("$2") = spyro.animationState;
            register int current __asm__("$3") = D_8006E044;
            __asm__("" : "=r"(current) : "0"(current), "r"(animation));
            animation *= 4;
            __asm__("" : "=r"(animation) : "0"(animation));
            next = *(int*)((unsigned char*)D_80068CAC + animation);
            if (current == next) return;
            if (!next) next = 6;
        }
    }
    func_80016764(next);
}
