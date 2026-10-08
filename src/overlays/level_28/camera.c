#include "common.h"
#include "spyro.h"
#include "stdutil.h"
#include "camera.h"

#define LEVEL_ID 28

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

extern int D_8006E044, D_8006E048, D_8006E04C, D_8006C598;
extern Vector3D D_8006E1E0;
extern short D_8006E1EC, D_8006E1EE, D_8006E1F0;
void func_level_28_80086094(void) {
    Vector3D offset;
    /* Empty constraint retains the retail return-address save before the branch. */
    __asm__ volatile("" : : : "$31");
    if (D_8006E044 == CAMERA_SPARX_OVERHEAD) {
        if (D_8006E048 == 1) {
            D_8006C598 = 0x100 - D_8006E04C * 16;
            if (D_8006C598 <= 0) {
                D_8006C598 = 0;
                D_8006E048 = 0;
            }
        }
        offset.x = 0;
        offset.y = 0;
        offset.z = 0x3000;
        func_8004F194(&D_8006E1E0, &spyro.position, &offset);
        D_8006E1EC = 0;
        D_8006E1EE = 0x400;
        D_8006E1F0 = 0;
    }
}

/**
 * ???() - func_level_28_80086148() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_28_80086148() {
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

extern short D_8006E03C;
extern short D_8006E03E;
extern short D_8006E040;
extern int D_8006E044;
extern int D_8006E048;
extern signed char D_8006E054;
extern int D_8006E12C;
extern int D_8006E130;
extern signed char D_8006E138;
extern signed char D_8006E139;
extern signed char D_8006E13D;
extern Vector3D D_8006E1B0;
extern int D_8006E1BC;
extern int D_8006E1C0;
extern int D_8006E1C4;

void func_level_28_80086170(int mode) {
    if (mode == 0x25) {
        if (D_8006E044 == 0xB) {
            D_8006E048 = 1;
        } else {
            D_8006E048 = 0;
        }
        func_8004F178(&D_8006E1B0, (Vector3D*)((char*)&D_8006E1B0 - 0x190));
        D_8006E1BC = (int) D_8006E03C;
        D_8006E1C0 = (int) D_8006E03E;
        D_8006E1C4 = (int) D_8006E040;
        func_80013900((void*)((char*)&D_8006E1B0 - 0xEC));
        D_8006E13D = 1;
        D_8006E12C = 0;
        D_8006E130 = 0;
        D_8006E138 = 1;
        D_8006E139 = 1;
        D_8006E054 = 0;
    }
}


extern int D_8006E044, D_8006E048, D_8006E160;
extern int D_80068CAC[];
void func_level_28_80086244(void) {
    if (D_8006E044 == CAMERA_SPARX_OVERHEAD) {
        int choice = D_8006E160;
        if (choice == 0 || D_8006E048 != 0) {
            int animation = spyro.animationState;
            register int mode __asm__("$3");
            /* Non-emitting barrier retains the second retail state read. */
            __asm__ volatile("" : : : "memory");
            mode = D_8006E044;
            choice = D_80068CAC[animation];
            if (mode == choice) return;
            if (choice == 0) choice = 6;
        }
        func_80016764(choice);
    }
}
