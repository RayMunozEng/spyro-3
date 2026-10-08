#include "common.h"
#include "camera.h"

#define LEVEL_ID 46

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/level_46/camera", func_level_46_80090D84);

/**
 * ???() - func_level_46_80091604() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_46_80091604() {
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

extern int D_8006E048, D_8006E140, D_8006E144, D_8006E158, D_8006E15C;
extern int D_8006C768, D_8006E12C, D_8006E130;
extern unsigned char D_8006E138, D_8006E139, D_8006E13A, D_8006E13D, D_8006E054;
extern char DecodedPovPlayer[] __asm__("D_80070328");
void func_level_46_80091658(int mode) {
    register int* base __asm__("$16");
    register CameraPosition* position __asm__("$17");
    register int enabled __asm__("$2");
    volatile int* tag;
    register int* angles __asm__("$3");
    switch (mode) {
    case 39:
        base = &D_8006E048;
        *base = 0;
        D_8006E138 = 0;
        D_8006E139 = 0;
        enabled = 1;
        goto reset;
    case 13:
    case 21:
        base = &D_8006E048;
        *base = 0;
        D_8006E138 = 0;
        enabled = 1;
        D_8006E139 = enabled;
reset:
        D_8006E13A = enabled;
        D_8006E13D = 0;
        D_8006E054 = 0;
        func_800142E0();
        position = (CameraPosition*)((char*)base + 44);
        __asm__("" : "=r"(position) : "0"(position));
        func_800136F0(position, (Vector3D*)((char*)base - 40), (Vector3D*)((char*)base + 16));
        func_800138A0(position, position);
        func_800135A4((CameraPosition*)((char*)base + 84), position, 0);
        break;
    case 31:
        tag = (int*)(*(Moby**)(DecodedPovPlayer + 592))->mobyTag;
        angles = &D_8006E140;
        __asm__("" : "=r"(angles) : "0"(angles));
        *angles = *(int*)(DecodedPovPlayer + 100);
        __asm__ volatile ("" : : : "memory");
        D_8006E144 = 0;
        D_8006E158 = 0;
        D_8006E15C = 0;
        func_80013900((CameraPosition*)((char*)angles - 124));
        D_8006E13D = 1;
        D_8006E138 = 1;
        D_8006E139 = 1;
        D_8006C768 = 1;
        D_8006E12C = 0;
        D_8006E130 = 0;
        D_8006E054 = 0;
        tag[20] = 0;
        tag[21] = 0;
        tag[22] = 512;
        break;
    }
}

extern CameraPosition D_80068FE0;
extern int DecodedCameraMode __asm__("D_8006E044");
extern int DecodedCameraOverride __asm__("D_8006E160");
extern int DecodedCameraHeld __asm__("D_8006E538");
extern int DecodedCameraPressed __asm__("D_8006E53C");
extern unsigned char DecodedCameraPlayer[] __asm__("D_80070328");
extern int DecodedCameraModeTable[] __asm__("D_80068CAC");
/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * 800917E4..80091B3C,215 original words. Verified selector mode13,
 * original modes21/31/39 retain setup/calls and post-callee rereads.
 * Raw units, helper/input/table/actor producers and cadence unresolved.
 * Test: original linked words and complete retail hashes.
 */
void func_level_46_800917E4(void) {
    register int mode __asm__("$3") = DecodedCameraMode;
    register int next __asm__("$4");
    register int index __asm__("$2");
    switch (mode) {
    case 13:
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
readTable:
            index = *(int*)(DecodedCameraPlayer + 0x48);
            next = DecodedCameraModeTable[index];
            goto change;
        }
        if (next == DecodedCameraMode) return;
        goto change;

    case 21:
        next = DecodedCameraOverride;
        if (next) goto change;
        index = *(int*)(DecodedCameraPlayer + 0x48);
        /* Preserve the original independent index read; emits no code. */
        __asm__("" : "=r"(index) : "0"(index));
        goto tableForIndex;
    case 31:
        next = DecodedCameraOverride;
        if (next && next != 40) func_80016764(next);
        if (DecodedCameraPlayer[0x1B9] == 0) {
            register int* overrideState __asm__("$17") = &DecodedCameraOverride;
            register CameraPosition* initial __asm__("$16") = (CameraPosition*)((char*)overrideState - 0xD8);
            if (*overrideState == 40) {
force40:
                next = 40;
                goto change;
            }
            func_800135A4(initial, &D_80068FE0, camera.unk6c);
            func_800135A4((CameraPosition*)((char*)overrideState - 0xC4), initial, 0);
            camera.unk140[0] = 0;
            camera.unk140[1] = 0;
            camera.unk140[2] = 1;
            camera.unk140[5] = 0;
            func_80012AC8();
            func_80012B34();
            func_80016764(DecodedCameraModeTable[*(int*)(DecodedCameraPlayer + 0x48)]);
            ((unsigned char*)*(unsigned int*)(DecodedCameraPlayer + 0x250))[0x4C] = 16;
            return;
        }
        if (DecodedCameraPressed & 16) {
            register int* overrideState __asm__("$17") = &DecodedCameraOverride;
            register CameraPosition* initial __asm__("$16") = (CameraPosition*)((char*)overrideState - 0xD8);
            if (*overrideState == 40) goto force40;
            func_800135A4(initial, &D_80068FE0, camera.unk6c);
            func_800135A4((CameraPosition*)((char*)overrideState - 0xC4), initial, 0);
            camera.unk140[0] = 0;
            camera.unk140[1] = 0;
            camera.unk140[2] = 1;
            camera.unk140[5] = 0;
            func_80012AC8();
            func_80012B34();
            func_80016764(0);
            camera.unk50 = 2;
            ((unsigned char*)*(unsigned int*)(DecodedCameraPlayer + 0x250))[0x4C] = 16;
        }
        return;
    case 39:
        next = DecodedCameraOverride;
        if (next) goto change;
        if ((DecodedCameraPressed & 16) && DecodedCameraPlayer[0x1B9] &&
                *(int*)(DecodedCameraPlayer + 0x24C) == 4) {
            next = 31;
            goto change;
        }
        index = *(int*)(DecodedCameraPlayer + 0x48);
        mode = DecodedCameraMode;
tableForIndex:
        next = DecodedCameraModeTable[index];
        if (mode == next) return;
        if (next) goto change;
        next = 6;
        goto change;
    default:
        return;
    }
change:
    func_80016764(next);
}
