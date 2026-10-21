#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 37

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

extern int D_8006E130, D_8006E12C, D_8006E044, D_8006E064;
extern int D_8006E160, D_8006E050;
extern CameraPosition D_8006E09C;
extern Moby* D_8006E164;
/* Rev 0 camera states 13 and 17; offsets follow the original camera record. */
void func_level_37_8008B554(void) {
    int* counter = &D_8006E130;
    int index = (*counter + 2) >> 2;
    Vector3D delta;
    Vector3D* savedPosition;
    if (index > 4)
        index = 4;
    switch (D_8006E044) {
        case 13:
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
            break;
        case 17:
            if (D_8006E160 == 17) {
                if (D_8006E12C == 0) {
                    func_800135A4((CameraPosition*)((char*)counter - 0xA8),
                                  (CameraPosition*)((char*)counter + 0x38), D_8006E064);
                }
                savedPosition = (Vector3D*)((char*)counter - 0xD8);
                func_8004F178(savedPosition, (Vector3D*)((char*)counter + 0x4C));
                D_8006E064 = 0;
                func_800135A4((CameraPosition*)((char*)counter - 0x58), &D_8006929C[index], 0);
                func_800135A4((CameraPosition*)((char*)counter - 0x44), &D_80069328[index], 0);
                func_800135A4((CameraPosition*)((char*)counter - 0x1C), &D_800693B4, 0);
                func_800135A4((CameraPosition*)((char*)counter - 0x30), &D_800693C8, 0);
                if (!(D_8006E050 & 2)) {
                    func_800136F0((CameraPosition*)((char*)counter - 0xBC),
                                  (Vector3D*)((char*)counter - 0x110), savedPosition);
                    *(int*)&D_8006E09C = *(int*)((char*)counter - 0xBC);
                }
            }
    }
}

/**
 * ???() - func_level_37_8008B790() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_37_8008B790() {
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

extern CameraPosition D_8006E074, D_8006E09C;
/* Aliases retain independent retail address setups for the two calls. */
extern CameraPosition DecodedCameraCopy __asm__("D_8006E074");
extern CameraPosition DecodedCameraSource __asm__("D_8006E074");
void func_8004F178(Vector3D*, Vector3D*);
void func_level_37_8008B7F4(int mode) {
    switch (mode) {
        case 0xD: {
            register int* state __asm__("$16") = &camera.unk50;
            register CameraPosition* position __asm__("$17");
            MATCHING_KEEP(state);
            *state = 0;
            camera.unk140[0] = 0;
            camera.unk140[1] = 1;
            camera.unk140[2] = 1;
            camera.unk140[5] = 0;
            camera.unk5c[0] = 0;
            position = (CameraPosition*)((char*)state + 0x2C);
            func_800142E0();
            func_800136F0(position, (Vector3D*)((char*)state - 0x28),
                          (Vector3D*)((char*)state + 0x10));
            break;
        }
        case 0x11: {
            register int one __asm__("$2") = 1;
            register int* state __asm__("$17") = &camera.unk50;
            register Vector3D* vector __asm__("$18");
            register CameraPosition* position __asm__("$16");
            MATCHING_KEEP(one);
            MATCHING_KEEP(state);
            vector = (Vector3D*)((char*)state + 0x10);
            *state = 0;
            camera.unk140[0] = 0;
            camera.unk140[1] = one;
            camera.unk140[2] = one;
            camera.unk140[5] = 0;
            func_8004F178(vector, (Vector3D*)((char*)state + 0x134));
            position = (CameraPosition*)((char*)state + 0x2C);
            MATCHING_KEEP(position);
            camera.unk6c = 0;
            func_800136F0(position, (Vector3D*)((char*)state - 0x28), vector);
            break;
        }
        default:
            return;
    }
    func_800138A0(&D_8006E074, &DecodedCameraCopy);
    func_800135A4(&D_8006E09C, &DecodedCameraSource, 0);
}

extern int D_8006E044, D_8006E160, D_8006E538, D_8006E53C;
extern int D_80068CAC[];
/* Same retail table; alias retains the two original lookup blocks. */
extern int DecodedCameraStateTable[] __asm__("D_80068CAC");
void func_level_37_8008B91C(void) {
    int state = D_8006E044;
    register int next __asm__("$4");
    switch (state) {
        case 0xD:
            if ((D_8006E538 & 0x10) && spyro.idle) {
                next = 7;
                goto change;
            }
            if (D_8006E53C & 0xC) {
                next = 8;
                goto change;
            }
            next = D_8006E160;
            if (!next) {
                next = DecodedCameraStateTable[spyro.animationState];
                goto change;
            }
            if (next == D_8006E044)
                return;
            goto change;
        case 0x11:
            next = D_8006E160;
            if (!next) {
                next = D_80068CAC[spyro.animationState];
                goto change;
            }
            if (next == state)
                return;
            goto change;
        default:
            return;
    }
change:
    func_80016764(next);
}
