#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 40

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

extern CameraPosition D_80069184;
/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * 80086C14..80086FBC,235 original instructions. Verified native camera
 * mode17 from batch1806, mode21 from1790 and mode23 from1813.
 * Raw units, helper/table/input producers and cadence remain unresolved.
 * Test: original linked words and every complete retail hash.
 */
void func_level_40_80086C14(void) {
    int tableIndex = (camera.unk138 + 2) >> 2;
    if (tableIndex > 4)
        tableIndex = 4;
    switch (camera.cameraState) {
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
        case 23:
            if (camera.unk134 == 0) {
                if (spyro.unk13e[1] & 0x80) {
                    func_800135A4(&camera.unk7c.pos[1], &D_80069260, camera.unk6c);
                } else {
                    func_80014354();
                    func_80013918(0x400);
                }
            }
            func_800142E0();
            camera.unk6c = spyro.m_WhirlwindPointer->angle.yaw * 0x10;
            func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
            func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
            if (!(camera.unk58 & 2)) {
                func_800136F0(&camera.unk7c.pos[0], &camera.nextCameraPosCartesian, &camera.unk60);
                camera.unk7c.pos[2].pos.azimuth = camera.unk7c.pos[0].pos.azimuth;
            }
            break;
    }
}

/**
 * ???() - func_level_40_80086FC0() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_40_80086FC0() {
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

extern int D_8006E048, D_8006E064;
extern unsigned char D_8006E138, D_8006E139, D_8006E13A, D_8006E13D, D_8006E054;
extern CameraPosition D_8006E074, D_8006E09C;
extern CameraPosition DecodedSettleInput __asm__("D_8006E074");
extern CameraPosition DecodedSettleFinal __asm__("D_8006E074");
extern Vector3D D_8006E020, D_8006E058, D_8006E17C;
void func_8004F178(Vector3D*, Vector3D*);
void func_level_40_80087024(int mode) {
    register int* base __asm__("$16");
    register CameraPosition* position __asm__("$17");
    register int* copyBase __asm__("$17");
    register CameraPosition* copiedPosition __asm__("$16");
    register Vector3D* target __asm__("$18");
    switch (mode) {
        case 23:
            base = &D_8006E048;
            *base = 0;
            D_8006E138 = 0;
            D_8006E139 = 0;
            D_8006E13A = 1;
            D_8006E13D = 0;
            D_8006E054 = 0;
            func_800142E0();
            position = (CameraPosition*)((char*)base + 44);
            MATCHING_KEEP(position);
            func_800136F0(position, (Vector3D*)((char*)base - 40), (Vector3D*)((char*)base + 16));
            goto settle;
        case 21:
            base = &D_8006E048;
            *base = 0;
            D_8006E138 = 0;
            D_8006E139 = 1;
            D_8006E13A = 1;
            D_8006E13D = 0;
            D_8006E054 = 0;
            func_800142E0();
            position = (CameraPosition*)((char*)base + 44);
            MATCHING_KEEP(position);
            func_800136F0(position, (Vector3D*)((char*)base - 40), (Vector3D*)((char*)base + 16));
            func_800138A0(position, position);
            func_800135A4((CameraPosition*)((char*)base + 84), position, 0);
            break;
        case 17:
            copyBase = &D_8006E048;
            target = (Vector3D*)((char*)copyBase + 16);
            *copyBase = 0;
            D_8006E138 = 0;
            D_8006E139 = 1;
            D_8006E13A = 1;
            D_8006E13D = 0;
            func_8004F178(target, (Vector3D*)((char*)copyBase + 308));
            copiedPosition = (CameraPosition*)((char*)copyBase + 44);
            MATCHING_KEEP(copiedPosition);
            D_8006E064 = 0;
            func_800136F0(copiedPosition, (Vector3D*)((char*)copyBase - 40), target);
        settle:
            func_800138A0(&D_8006E074, &DecodedSettleInput);
            func_800135A4(&D_8006E09C, &DecodedSettleFinal, 0);
            break;
    }
}

extern int D_8006E044, D_8006E160;
extern int D_80068CAC[];
extern int DecodedCameraStateTable[] __asm__("D_80068CAC");
void func_level_40_800871C4(void) {
    int next;
    register int mode __asm__("$3") = D_8006E044;
    switch (mode) {
        case 0x11:
            next = D_8006E160;
            if (!next)
                next = D_80068CAC[spyro.animationState];
            else if (next == mode)
                return;
            break;
        case 0x15:
        case 0x17:
            next = D_8006E160;
            if (!next) {
                next = DecodedCameraStateTable[spyro.animationState];
                if (next == mode)
                    return;
                if (!next)
                    next = 6;
            }
            break;
        default:
            return;
    }
    func_80016764(next);
}
