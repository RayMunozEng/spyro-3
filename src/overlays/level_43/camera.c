#include "common.h"
#include "camera.h"

#define LEVEL_ID 43

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/level_43/camera", func_level_43_80095668);

/**
 * ???() - func_level_43_80095E78() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_43_80095E78() {
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

extern unsigned char** DecodedMode31Tag __asm__("D_80070328 + 0x250");
extern int DecodedMode31Value __asm__("D_80070328 + 0x64");
extern int DecodedMode31CameraState __asm__("D_8006E140");
extern int DecodedMode31Camera144 __asm__("D_8006E144");
extern int DecodedMode31Camera158 __asm__("D_8006E158");
extern int DecodedMode31Camera15C __asm__("D_8006E15C");
extern int DecodedMode31Flag __asm__("D_8006C768");
extern int DecodedMode31Camera12C __asm__("D_8006E12C");
extern int DecodedMode31Camera130 __asm__("D_8006E130");
extern Moby* D_8006E164;
extern int D_8006E048, D_8006E064;
extern unsigned char D_8006E138, D_8006E139, D_8006E13A, D_8006E13D, D_8006E054;
extern CameraPosition D_8006E074, D_8006E09C;
extern CameraPosition DecodedSettleInput __asm__("D_8006E074");
extern CameraPosition DecodedSettleFinal __asm__("D_8006E074");
extern Vector3D D_8006E020, D_8006E058, D_8006E17C;
void func_8004F178(Vector3D*, Vector3D*);
extern int D_8006E168;
/* AI generated adaptation; not human reviewed.
 * SCUS-94467 USA Rev0 80095ECC..80096104, 143 words.
 * Reuses verified level40_80087024 reset/settle and level44_8009387C
 * raw mode31 tag route. Original dispatch uses13/31/33/39; mode33
 * retains the D_8006E168 -> D_8006E064 word transfer before common update.
 * The shared update label preserves original helper and argument ordering.
 * Raw tag producers, units and caller cadence remain unresolved.
 * Acceptance: every original linked word and complete retail hashes.
 */
void func_level_43_80095ECC(int mode) {
    register int* base __asm__("$16");
    register unsigned char* actor __asm__("$16");
    register CameraPosition* position __asm__("$17");
    register int* copyBase __asm__("$17");
    register CameraPosition* copiedPosition __asm__("$16");
    register int enabled __asm__("$2");
    register unsigned char* flagBase __asm__("$16");
    register CameraPosition* flagPosition __asm__("$17");
    register CameraPosition* updatePosition __asm__("$4");
    register Vector3D* updateOrigin __asm__("$5");
    register Vector3D* updateTarget __asm__("$6");
    switch (mode) {
    case 39:
        base = &D_8006E048;
        *base = 0;
        D_8006E138 = 0;
        D_8006E139 = 0;
        D_8006E13A = 1;
        D_8006E13D = 0;
        D_8006E054 = 0;
        func_800142E0();
        position = (CameraPosition*)((char*)base + 44);
        __asm__("" : "=r"(position) : "0"(position));
        updatePosition = position;
        updateOrigin = (Vector3D*)((char*)base - 40);
        updateTarget = (Vector3D*)((char*)base + 16);
        goto update;
    case 13:
        base = &D_8006E048;
        *base = 0;
        D_8006E138 = 0;
        D_8006E139 = 1;
        D_8006E13A = 1;
        D_8006E13D = 0;
        D_8006E054 = 0;
        func_800142E0();
        position = (CameraPosition*)((char*)base + 44);
        __asm__("" : "=r"(position) : "0"(position));
        func_800136F0(position, (Vector3D*)((char*)base - 40), (Vector3D*)((char*)base + 16));
        func_800138A0(position, position);
        func_800135A4((CameraPosition*)((char*)base + 84), position, 0);
        break;
    case 31: {
        register int* state __asm__("$3");
        register int value __asm__("$2");
        register unsigned char** pointer __asm__("$2") = DecodedMode31Tag;
        __asm__("" : "=r"(pointer) : "0"(pointer));
        state = &DecodedMode31CameraState;
        __asm__("" : "=r"(state) : "0"(state),"r"(pointer));
        actor = *pointer;
        value = DecodedMode31Value;
        __asm__("" : "=r"(value) : "0"(value));
        *state = value;
        DecodedMode31Camera144 = 0;
        DecodedMode31Camera158 = 0;
        DecodedMode31Camera15C = 0;
        func_80013900((CameraPosition*)((char*)state - 0x7C));
        D_8006E13D = 1;
        D_8006E138 = 1;
        D_8006E139 = 1;
        DecodedMode31Flag = 1;
        DecodedMode31Camera12C = 0;
        DecodedMode31Camera130 = 0;
        D_8006E054 = 0;
        *(int*)(actor + 0x50) = 0;
        *(int*)(actor + 0x54) = 0;
        *(int*)(actor + 0x58) = 0x200;
        break;
    }
    case 33:
        copyBase = &D_8006E048;
        *copyBase = 0;
        D_8006E138 = 0;
        D_8006E139 = 0;
        D_8006E13A = 1;
        D_8006E13D = 0;
        D_8006E054 = 0;
        func_800142E0();
        copiedPosition = (CameraPosition*)((char*)copyBase + 44);
        __asm__("" : "=r"(copiedPosition) : "0"(copiedPosition));
        updatePosition = copiedPosition;
        updateOrigin = (Vector3D*)((char*)copyBase - 40);
        D_8006E064 = D_8006E168;
        updateTarget = (Vector3D*)((char*)copyBase + 16);
update:
        func_800136F0(updatePosition, updateOrigin, updateTarget);
        func_800138A0(&D_8006E074, &DecodedSettleInput);
        func_800135A4(&D_8006E09C, &DecodedSettleFinal, 0);
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
 * 80096108..80096460,215 original words. Verified selector mode13,
 * original modes31/33/39 retain setup/calls and post-callee rereads.
 * Raw units, helper/input/table/actor producers and cadence unresolved.
 * Test: original linked words and complete retail hashes.
 */
void func_level_43_80096108(void) {
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
            next = DecodedCameraModeTable[*(int*)(DecodedCameraPlayer + 0x48)];
            goto change;
        }
        if (next == DecodedCameraMode) return;
        goto change;

    case 33:
        next = DecodedCameraOverride;
        if (!next) goto readTable;
        if (next == mode) return;
        goto change;
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
