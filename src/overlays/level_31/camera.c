#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 31

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

extern CameraPosition D_80068FCC, D_80069224;
extern int D_8006C6D0;
/* AI-generated; not human reviewed. SCUS-94467 USA Rev0
 * 8008F4E4..8008F86C: original modes5/34; existing table-copy baseline
 * verified level20_8008BF8C. Signed LH at E040, native205 shift8,
 * two distinct stack vectors and original signed radius comparisons.
 * Units, helper/table/input producers and cadence remain unresolved.
 * Test: all226 original linked code words and complete retail hashes.
 */
void func_level_31_8008F4E4(void) {
    int tableIndex = (camera.unk138 + 2) >> 2;
    int turnDelta;
    if (tableIndex > 4) tableIndex = 4;
    switch (camera.cameraState) {
    case 5: {
        Vector3D delta;
        if (camera.unk134 == 0) {
            func_800135A4(&camera.unk7c.pos[1], &D_80068FCC, camera.unk6c);
            func_8004F178(&delta, &spyro.unk7a[2]);
            func_8004F110(&delta, 2);
            func_8004F194(&delta, (Vector3D*)&spyro, &delta);
            func_8004F1C8(&delta, &delta, &camera.nextCameraPosCartesian);
            turnDelta = (func_8004E880(delta.x, delta.y, 1) - camera.unk48) & 0xFFF;
            if (turnDelta > 0x800) turnDelta -= 0x1000;
            turnDelta = turnDelta * 205 >> 8;
            MAX(turnDelta, 0xC0);
            MIN(turnDelta, -0xC0);
            camera.unk7c.pos[1].pitch = ABS(turnDelta) >= 9 ? turnDelta : 0;
            func_80013918(0x180);
            func_800139A4();
        }
        func_800142E0();
        func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
        MIN(camera.unk7c.pos[5].pos.azimuth, 0x80);
        MIN(camera.unk7c.pos[5].pitch, 0x40);
        func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
        func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
        func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
        break;
    }
    case 34: {
        Vector3D delta;
        if (camera.unk16c == 0) break;
        func_8004F1C8(&delta, &camera.unk16c->position, (Vector3D*)&spyro);
        delta.z = 0;
        camera.unk6c = func_8004E880(delta.x, delta.y, 1) + 0x400;
        func_800135A4(&camera.unk7c.pos[1], &D_80069224, camera.unk6c);
        camera.unk7c.pos[1].pos.radius = func_8004EDE8(&delta, 0) + 0x400;
        MIN(*(int*)&camera.unk7c.pos[1].pos.radius, 0x1000);
        func_8004F110(&delta, 1);
        func_8004F194(&camera.unk60, &delta, (Vector3D*)&spyro);
        camera.unk148[2] = 0;
        camera.unk60.z += D_8006C6D0;
        func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
        func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
        if ((int)camera.unk7c.pos[2].pos.radius > (int)camera.unk7c.pos[1].pos.radius) {
            camera.unk7c.pos[6].pos.radius = 24;
        }
        func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
        func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
        break;
    }
    }
}


/**
 * ???() - func_level_31_8008F86C() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_31_8008F86C() {
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
extern int D_8006E060, D_8006C6D0;
extern char DecodedBoxPlayer[] __asm__("D_80070328");
int func_8004E880(int, int, int);
void func_8004F1C8(Vector3D*, Vector3D*, Vector3D*);
void func_8004F110(Vector3D*, int);
void func_8004F194(Vector3D*, Vector3D*, Vector3D*);
extern int D_8006E048, D_8006E064;
extern unsigned char D_8006E138, D_8006E139, D_8006E13A, D_8006E13D, D_8006E054;
extern CameraPosition D_8006E074, D_8006E09C;
extern CameraPosition DecodedSettleInput __asm__("D_8006E074");
extern CameraPosition DecodedSettleFinal __asm__("D_8006E074");
extern Vector3D D_8006E020, D_8006E058, D_8006E17C;
void func_8004F178(Vector3D*, Vector3D*);
void func_level_31_8008F894(int mode) {
    Vector3D delta;
    register Vector3D* deltaArgument __asm__("$4");
    register Vector3D* player __asm__("$16");
    register Vector3D* playerArgument __asm__("$6");
    register int* base __asm__("$16");
    register CameraPosition* position __asm__("$17");
    register int* copyBase __asm__("$17");
    register CameraPosition* copiedPosition __asm__("$16");
    register Vector3D* target __asm__("$18");
    switch (mode) {
    case 5:
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
        func_800136F0(position, (Vector3D*)((char*)base - 40), (Vector3D*)((char*)base + 16));
        goto settle;
    case 34:
        deltaArgument = &delta;
        player = (Vector3D*)DecodedBoxPlayer;
        playerArgument = player;
        __asm__ volatile ("" : "=r"(playerArgument) : "0"(playerArgument), "r"(deltaArgument) : "$17");
        copyBase = &D_8006E048;
        *copyBase = 0;
        D_8006E138 = 0;
        D_8006E139 = 1;
        D_8006E13A = 1;
        D_8006E13D = 0;
        D_8006E054 = 0;
        func_8004F1C8(deltaArgument, &D_8006E164->position, playerArgument);
        delta.z = 0;
        D_8006E064 = func_8004E880(delta.x, delta.y, 1) + 1024;
        func_8004F110(&delta, 1);
        target = (Vector3D*)((char*)copyBase + 16);
        func_8004F194(target, &delta, player);
        copiedPosition = (CameraPosition*)((char*)copyBase + 44);
        __asm__("" : "=r"(copiedPosition) : "0"(copiedPosition));
        D_8006E060 += D_8006C6D0;
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
void func_level_31_8008FA28(void) {
    int next;
    register int mode __asm__("$3") = D_8006E044;
    switch (mode) {
    case 5:
        next = D_8006E160;
        if (!next) {
            next = DecodedCameraStateTable[spyro.animationState];
            if (next == mode) return;
            if (!next) next = 6;
        }
        break;
    case 0x22:
        next = D_8006E160;
        if (!next) next = D_80068CAC[spyro.animationState];
        else if (next == mode) return;
        break;
    default: return;
    }
    func_80016764(next);
}
