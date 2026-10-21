#include "matching.h"
#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 47

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

extern CameraPosition D_8006906C, D_8006901C, D_80069030, D_80069300, D_8006938C;
extern int D_8006C5BC;
extern Moby* CameraMode14Target __asm__("D_8006E164");
/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * 8008D8D0..8008DC38,218 original instructions. Verified mode13/14/23
 * camera baselines; mode13's original movement6 camera table retained.
 * Units, helper/target/table/input producers and cadence remain unresolved.
 * Test: original linked code words and complete retail hashes.
 */
void func_level_47_8008D8D0(void) {
    int tableIndex = (camera.unk138 + 2) >> 2;
    if (tableIndex > 4)
        tableIndex = 4;
    switch (camera.cameraState) {
        case 13: {
            Vector3D delta;
            func_800142E0();
            if (camera.unk16c != 0) {
                func_8004F1C8(&delta, &camera.unk16c->position, (Vector3D*)&spyro);
                camera.unk6c = func_8004E880(delta.x, delta.y, 1);
                if (camera.unk134 == 0) {
                    func_80014354();
                    if (spyro.movementState == 6) {
                        func_800135A4(&camera.unk7c.pos[1], &D_8006906C, camera.unk6c);
                    }
                    func_80013918(0x400);
                }
                func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
                func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
                func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
                func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
            }
            break;
        }

        case 14:
            if (camera.unk134 == 0) {
                if (D_8006C5BC == 47) {
                    func_800135A4(&camera.unk7c.pos[1], &D_80069030, camera.unk6c);
                } else {
                    func_800135A4(&camera.unk7c.pos[1], &D_8006901C, camera.unk6c);
                }
            }
            func_800142E0();
            if (camera.unk16c != 0) {
                camera.unk6c = CameraMode14Target->angle.yaw * 16;
                func_800135A4(&camera.unk7c.pos[5], &D_80069300, 0);
                func_800135A4(&camera.unk7c.pos[6], &D_8006938C, 0);
                func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
                func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
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
 * ???() - func_level_47_8008DC38() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_47_8008DC38() {
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

extern Moby* D_8006E164;
extern int D_8006E048, D_8006E064;
extern unsigned char D_8006E138, D_8006E139, D_8006E13A, D_8006E13D, D_8006E054;
extern CameraPosition D_8006E074, D_8006E09C;
extern CameraPosition DecodedSettleInput __asm__("D_8006E074");
extern CameraPosition DecodedSettleFinal __asm__("D_8006E074");
extern Vector3D D_8006E020, D_8006E058, D_8006E17C;
void func_8004F178(Vector3D*, Vector3D*);
void func_level_47_8008DC60(int mode) {
    register int* base __asm__("$16");
    register CameraPosition* position __asm__("$17");
    register int* copyBase __asm__("$17");
    register CameraPosition* copiedPosition __asm__("$16");
    register int enabled __asm__("$2");
    register unsigned char* flagBase __asm__("$16");
    register CameraPosition* flagPosition __asm__("$17");
    register Vector3D* target __asm__("$18");
    switch (mode) {
        case 23:
            base = &D_8006E048;
            *base = 0;
            D_8006E138 = 0;
            D_8006E139 = 0;
            D_8006E13A = 1;
            MATCHING_KEEP_VOLATILE(base);
            goto reset;
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
            MATCHING_KEEP(position);
            func_800136F0(position, (Vector3D*)((char*)base - 40), (Vector3D*)((char*)base + 16));
            func_800138A0(position, position);
            func_800135A4((CameraPosition*)((char*)base + 84), position, 0);
            break;
        case 14:
            D_8006E048 = 0;
            if (D_8006E164->mobyClass == 371 || D_8006E164->mobyClass == 659) {
                enabled = 1;
                D_8006E138 = enabled;
            } else {
                enabled = 1;
                D_8006E138 = 0;
            }
            D_8006E139 = enabled;
            __asm__ volatile("" : "=r"(enabled) : "0"(enabled) : "memory", "$16");
            flagBase = &D_8006E13A;
            *flagBase = 1;
            MATCHING_KEEP_VOLATILE(flagBase);
        reset:
            D_8006E13D = 0;
            D_8006E054 = 0;
            func_800142E0();
            MATCHING_BARRIER_VOLATILE("$17");
            position = &D_8006E074;
            func_800136F0(position, &D_8006E020, &D_8006E058);
            func_800138A0(position, position);
            func_800135A4(&D_8006E09C, position, 0);
            break;
    }
}

extern int D_8006E044, D_8006E160, D_8006E538, D_8006E53C;
extern char DecodedSelectorPlayer[] __asm__("D_80070328");
extern int D_80068CAC[];
void func_80016764(int);
void func_level_47_8008DDF8(void) {
    int mode, selected;
    mode = D_8006E044;
    switch (mode) {
        case 13:
            if ((D_8006E538 & 16) && DecodedSelectorPlayer[441]) {
                selected = 7;
                goto change;
            }
            if (D_8006E53C & 12) {
                selected = 8;
                goto change;
            }
            selected = D_8006E160;
            if (!selected) {
            fromPlayer:
                selected = D_80068CAC[*(int*)(DecodedSelectorPlayer + 72)];
                goto change;
            }
            if (selected == D_8006E044)
                return;
            goto change;
        case 14:
            selected = D_8006E160;
            if (!selected)
                goto fromPlayer;
            if (selected == mode)
                return;
            goto change;
        case 23:
            selected = D_8006E160;
            if (!selected) {
                selected = D_80068CAC[*(int*)(DecodedSelectorPlayer + 72)];
                if (selected == mode)
                    return;
                if (!selected)
                    selected = 6;
            }
            goto change;
        default:
            return;
    }
change:
    func_80016764(selected);
}
