#include "common.h"
#include "stdutil.h"
#include "spyro.h"
#include "camera.h"

#define LEVEL_ID 21

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

extern CameraPosition D_80068FCC, D_8006901C, D_80069030, D_80069300, D_8006938C, D_80069238;
extern int D_8006C5BC;
extern Moby* CameraMode14Target __asm__("D_8006E164");
/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * 8008E988..8008F1BC,526 code words plus30 dispatch words.
 * Verified native camera cases4/5/12/13/14/23/33 independently retargeted.
 * Raw units, helper/input/table/target producers and cadence unresolved.
 * Test: original linked code/dispatch words and complete retail hashes.
 */
void func_level_21_8008E988(void) {
    int tableIndex = (camera.unk138 + 2) >> 2;
    MAX(tableIndex,4);
    switch (camera.cameraState) {
    case 4: {
        int pitchDelta;
        if ((camera.unk134 == 0) && (game.state != 7)) {
            func_800135A4(&camera.unk7c.pos[1], &D_80069008, camera.unk6c);
            camera.unk7c.pos[1].pos.elevation = -spyro.rotation.pitch;
            
            pitchDelta = (-spyro.rotation.pitch - camera.unk7c.pos[0].pos.elevation) >> 2;
            MAX(pitchDelta, 0xC0);
            MIN(pitchDelta, -0xC0);
            
            camera.unk7c.pos[1].yaw = (ABS(pitchDelta) >= 9) ? pitchDelta : 0;
            camera.unk7c.pos[1].pitch = -spyro.rotation.roll >> 2;
            
            func_80013918(0x180);
            func_800139A4();
        }
        func_800142E0();
        func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
        MIN(camera.unk7c.pos[5].pos.azimuth, 0x80);
        MIN(camera.unk7c.pos[5].pos.elevation, 0x60);
        MIN(camera.unk7c.pos[5].pitch, 0x40);
        func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
        func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
        func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
        break;
        
    }
    case 5: {
        int turnDelta;
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
    case 12: {
        Vector3D delta;
        if (camera.unk134 == 0) {
            func_80014354();
            func_80013918(0x400);
        }
        func_800142E0();
        if (camera.unk16c != 0) {
            func_8004F1C8(&delta, &camera.unk16c->position, &spyro.position);
            camera.unk6c = func_8004E880(delta.x, delta.y, 1);
            func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
            func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
            func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
            return;
        }
        break;

    }
    case 13: {
        Vector3D delta;
        func_800142E0();
        if (camera.unk16c != 0) {
            func_8004F1C8(&delta, &camera.unk16c->position, (Vector3D*)&spyro);
            camera.unk6c = func_8004E880(delta.x, delta.y, 1);
            if (camera.unk134 == 0) {
                func_80014354();
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
            case 33:
        if (camera.unk134 == 0) {
            func_800135A4(&camera.unk7c.pos[1], &D_80069238, camera.unk6c);
            func_80013918(0xC0);
            func_800139A4();
        }
        func_800142E0();
        camera.unk6c = camera.unk170.pos.azimuth;
        func_800135A4(&camera.unk7c.pos[5], &D_8006929C[tableIndex], 0);
        if (camera.unk138 == 0) {
            camera.unk7c.pos[5].pos.azimuth >>= 1;
            *(int*)&camera.unk7c.pos[5].pos.radius >>= 1;
        }
        func_800135A4(&camera.unk7c.pos[6], &D_80069328[tableIndex], 0);
        func_800135A4(&camera.unk7c.pos[7], &D_800693C8, 0);
        func_800135A4(&camera.unk7c.pos[8], &D_800693B4, 0);
        break;
    }
}

/**
 * ???() - func_level_21_8008F1C0() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_21_8008F1C0() {
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
extern int CameraSettleValue __asm__("D_8006E168");
/* SCUS-94467 USA Rev0 8008F1E8..8008F41C, 142 code words plus 30 dispatch words.
 * Reuses verified func_level_32_8009CC30. Original modes4/5/12/23 share
 * reset; mode13 shares settle; mode33 reads camera+168 into camera+64.
 * Retains raw byte flags, halfword classes and exact helper order.
 * Units, complete helper/producer semantics and caller cadence remain open.
 * Empty constraints preserve lifetimes and emit no instructions.
 * AI generated; not human reviewed. See batch2026-10-05-1663.
 */
void func_level_21_8008F1E8(int mode) {
    register int* base __asm__("$16");
    register CameraPosition* position __asm__("$17");
    register int* copyBase __asm__("$17");
    register CameraPosition* copiedPosition __asm__("$16");
    register int enabled __asm__("$2");
    register unsigned char* flagBase __asm__("$16");
    register CameraPosition* flagPosition __asm__("$17");
    register Vector3D* target __asm__("$18");
    switch (mode) {
    case 4:
    case 5:
    case 12:
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
        __asm__("" : "=r"(position) : "0"(position));
        func_800136F0(position, (Vector3D*)((char*)base - 40), (Vector3D*)((char*)base + 16));
        goto settle;
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
        __asm__ volatile ("" : "=r"(enabled) : "0"(enabled) : "memory", "$16");
        flagBase = &D_8006E13A;
        *flagBase = 1;
        D_8006E13D = 0;
        D_8006E054 = 0;
        func_800142E0();
        flagPosition = (CameraPosition*)((char*)flagBase - 198);
        __asm__("" : "=r"(flagPosition) : "0"(flagPosition));
        func_800136F0(flagPosition, (Vector3D*)((char*)flagBase - 282), (Vector3D*)((char*)flagBase - 226));
        func_800138A0(flagPosition, flagPosition);
        func_800135A4((CameraPosition*)((char*)flagBase - 158), flagPosition, 0);
        break;
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
        D_8006E064 = CameraSettleValue;
        func_800136F0(copiedPosition, (Vector3D*)((char*)copyBase - 40), (Vector3D*)((char*)copyBase + 16));
settle:
        func_800138A0(&D_8006E074, &DecodedSettleInput);
        func_800135A4(&D_8006E09C, &DecodedSettleFinal, 0);
        break;
    }
}

extern int DecodedCameraMode __asm__("D_8006E044");
extern int DecodedCameraOverride __asm__("D_8006E160");
extern int DecodedCameraHeld __asm__("D_8006E538");
extern int DecodedCameraPressed __asm__("D_8006E53C");
extern unsigned char DecodedCameraPlayer[] __asm__("D_80070328");
extern int DecodedCameraModeTable[] __asm__("D_80068CAC");
/* SCUS-94467 USA Rev0 8008F420..8008F69C, 160 code words and 30 dispatch words.
 * Reuses verified func_level_12_8008BAC4. Mode5 has a separate table path;
 * modes14/33 join mode13 after input at its override load. Mode23
 * retains the separate fresh-mode comparison/table-zero fallback.
 * Original dispatch entries, access widths and helper order are retained.
 * Units, table/flag producers and caller cadence remain open.
 * Empty constraints preserve compiler control flow without instructions.
 * AI generated; not human reviewed. See batch2026-10-05-1690.
 */
void func_level_21_8008F420(void) {
    register int mode __asm__("$3");
    register int next __asm__("$4");
    register int index __asm__("$2");
    switch (DecodedCameraMode) {
    case 4:
        next = DecodedCameraOverride;
        if (next) goto change;
        if (DecodedCameraHeld & 16) {
            register int enabled __asm__("$2") = DecodedCameraPlayer[0x1B9];
            next = 7;
            if (enabled) goto change;
        }
        if (DecodedCameraPressed & 12) {
            next = 8;
            goto change;
        }
        goto indexedRoute;
    case 5:
        next = DecodedCameraOverride;
        if (next) goto change;
        index = *(int*)(DecodedCameraPlayer + 0x48);
        mode = DecodedCameraMode;
        next = DecodedCameraModeTable[index];
        if (mode == next) return;
        if (!next) goto defaultMode;
        __asm__ volatile("" : : : "memory");
        goto change;
    case 12:
        if (DecodedCameraHeld & 16) {
            register int enabled __asm__("$2") = DecodedCameraPlayer[0x1B9];
            next = 7;
            if (enabled) goto change;
        }
        if (DecodedCameraPressed & 12) {
            next = 8;
            goto change;
        }
        next = DecodedCameraOverride;
        if (!next) {
tableRoute:
            next = DecodedCameraModeTable[*(int*)(DecodedCameraPlayer + 0x48)];
            __asm__("" : "=r"(next) : "0"(next));
            goto change;
        }
        __asm__("" : : : "memory");
        if (next != DecodedCameraMode) goto change;
        mode = DecodedCameraModeTable[*(int*)(DecodedCameraPlayer + 0x48)];
        next = 2;
        if (mode != 2) return;
        goto change;
    case 13:
        if (DecodedCameraHeld & 16) {
            register int enabled __asm__("$2") = DecodedCameraPlayer[0x1B9];
            next = 7;
            if (enabled) goto change;
        }
        if (DecodedCameraPressed & 12) {
            next = 8;
            goto change;
        }
    case 14:
    case 33:
        next = DecodedCameraOverride;
        if (!next) goto tableRoute;
        __asm__("" : : : "memory");
        if (next == DecodedCameraMode) return;
        goto change;
    case 23:
        next = DecodedCameraOverride;
        if (next) goto change;
indexedRoute:
        index = *(int*)(DecodedCameraPlayer + 0x48);
        mode = DecodedCameraMode;
        next = DecodedCameraModeTable[index];
        if (mode == next) return;
        if (next) goto change;
defaultMode:
        next = 6;
        break;
    default:
        return;
    }
change:
    func_80016764(next);
}
