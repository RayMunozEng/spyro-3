#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 36

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

extern int D_8006E130, D_8006E12C, D_8006E044, D_8006E064;
extern Moby* D_8006E164;
void func_level_36_8008653C(void) {
    int* counter = &D_8006E130;
    int index = (*counter + 2) >> 2;
    Vector3D delta;
    if (index > 4) index = 4;
    if (D_8006E044 == 13) {
        func_800142E0();
        if (D_8006E164) {
            func_8004F1C8(&delta, &D_8006E164->position, (Vector3D*)&spyro);
            D_8006E064 = func_8004E880(delta.x, delta.y, 1);
            if (D_8006E12C == 0) {
                func_80014354();
                func_80013918(0x400);
            }
            func_800135A4((CameraPosition*)((char*)counter - 0x58), &D_8006929C[index], 0);
            func_800135A4((CameraPosition*)((char*)counter - 0x44), &D_80069328[index], 0);
            func_800135A4((CameraPosition*)((char*)counter - 0x30), &D_800693C8, 0);
            func_800135A4((CameraPosition*)((char*)counter - 0x1C), &D_800693B4, 0);
        }
    }
}

/**
 * ???() - func_level_36_80086670() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_36_80086670() {
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

void func_level_36_80086698(int mode) {
    if (mode == 0xD) {
        register int* state __asm__("$16") = &camera.unk50;
        CameraPosition* position;
        /* Keep the original shared address base; this constraint emits no code. */
        __asm__("" : "=r"(state) : "0"(state));
        *state = 0;
        camera.unk140[0] = 0;
        camera.unk140[1] = 1;
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
void func_80016764(int);
void func_level_36_80086734(void) {
    int next;
    if (D_8006E044 != 0xD) return;
    if ((D_8006E538 & 0x10) && *((unsigned char*)&spyro + 0x1B9)) next = 7;
    else if (D_8006E53C & 0xC) next = 8;
    else {
        next = D_8006E160;
        if (!next) next = D_80068CAC[spyro.animationState];
        else if (next == D_8006E044) return;
    }
    func_80016764(next);
}
