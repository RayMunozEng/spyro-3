#include "common.h"
#include "camera.h"

#define LEVEL_ID 44

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/level_44/camera", func_level_44_80092E18);

/**
 * ???() - func_level_44_800937F4() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_44_800937F4() {
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
/* SCUS-94467 USA Rev0 8009387C..80093AB4, 143 code words.
 * Reuses verified func_level_50_800A0320. Modes4/39 reset, mode13 settle, mode17 vector copy and raw mode31 tag path.
 * Original dispatch entries, access widths and helper order are retained.
 * Units, table/flag/tag producers and caller cadence remain open.
 * Empty constraints preserve compiler lifetime/control flow without instructions.
 * AI generated; not human reviewed. See batch2026-10-05-1690.
 */
void func_level_44_8009387C(int mode) {
    register int* base __asm__("$16");
    register unsigned char* actor __asm__("$16");
    register CameraPosition* position __asm__("$17");
    register int* copyBase __asm__("$17");
    register CameraPosition* copiedPosition __asm__("$16");
    register int enabled __asm__("$2");
    register unsigned char* flagBase __asm__("$16");
    register CameraPosition* flagPosition __asm__("$17");
    register Vector3D* target __asm__("$18");
    switch (mode) {
    case 4:
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
        __asm__("" : "=r"(copiedPosition) : "0"(copiedPosition));
        D_8006E064 = 0;
        func_800136F0(copiedPosition, (Vector3D*)((char*)copyBase - 40), target);
settle:
        func_800138A0(&D_8006E074, &DecodedSettleInput);
        func_800135A4(&D_8006E09C, &DecodedSettleFinal, 0);
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
    }    }
}

extern CameraPosition D_80068FE0;
extern int Camera44Mode __asm__("D_8006E044");
extern int Camera44Override __asm__("D_8006E160");
extern int Camera44Held __asm__("D_8006E538");
extern int Camera44Pressed __asm__("D_8006E53C");
extern unsigned char Camera44Player[] __asm__("D_80070328");
extern int Camera44ModeTable[] __asm__("D_80068CAC");
/* AI generated; not human reviewed. SCUS-94467 80093AB8..80093E58.
 * Baseline: verified level43_80096108 selector/copy structure; original level44
 * supplies its selector13, state31 and input/global access chains.
 * Empty flag constraints preserve the original late A0 branch-delay values.
 * Helper contracts, table producers, physical units and cadence remain open.
 * Acceptance requires every original code/table word and complete retail hashes.
 */
void func_level_44_80093AB8(void) {
    register int mode __asm__("$2") = Camera44Mode;
    register int next __asm__("$4");
    register int index __asm__("$2");
    register int flag __asm__("$2");
    switch (mode) {
    case 4:
        next = Camera44Override;
        if (next) goto applySelector;
        if (Camera44Held & 16) {
            flag = Camera44Player[0x1B9];
            __asm__ __volatile__("" : "=r"(flag) : "0"(flag) : "$4");
            next = 7;
            if (flag) goto applySelector;
        }
        flag = Camera44Pressed & 12;
        __asm__ __volatile__("" : "=r"(flag) : "0"(flag) : "$4");
        next = 8;
        if (!flag) goto freshTable;
        goto applySelector;
    case 13:
        if (Camera44Held & 16) {
            flag = Camera44Player[0x1B9];
            __asm__ __volatile__("" : "=r"(flag) : "0"(flag) : "$4");
            next = 7;
            if (flag) goto applySelector;
        }
        flag = Camera44Pressed & 12;
        __asm__ __volatile__("" : "=r"(flag) : "0"(flag) : "$4");
        next = 8;
        if (flag) goto applySelector;
        next = Camera44Override;
        if (!next) {
readTable:
            next = Camera44ModeTable[*(int*)(Camera44Player + 0x48)];
            goto applySelector;
        }
        if (next == Camera44Mode) return;
        goto applySelector;

    case 17:
        next = Camera44Override;
        if (!next) goto readTable;
        if (next == 17) return;
        goto applySelector;
    case 31:
        next = Camera44Override;
        if (next && next != 40) func_80016764(next);
        if (Camera44Player[0x1B9] == 0) {
            register int* overrideState __asm__("$17") = &Camera44Override;
            register CameraPosition* initial __asm__("$16") = (CameraPosition*)((char*)overrideState - 0xD8);
            if (*overrideState == 40) {
force40:
                next = 40;
                goto applySelector;
            }
            func_800135A4(initial, &D_80068FE0, camera.unk6c);
            func_800135A4((CameraPosition*)((char*)overrideState - 0xC4), initial, 0);
            camera.unk140[0] = 0;
            camera.unk140[1] = 0;
            camera.unk140[2] = 1;
            camera.unk140[5] = 0;
            func_80012AC8();
            func_80012B34();
            func_80016764(Camera44ModeTable[*(int*)(Camera44Player + 0x48)]);
            ((unsigned char*)*(unsigned int*)(Camera44Player + 0x250))[0x4C] = 16;
            return;
        }
        if (Camera44Pressed & 16) {
            register int* overrideState __asm__("$17") = &Camera44Override;
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
            ((unsigned char*)*(unsigned int*)(Camera44Player + 0x250))[0x4C] = 16;
        }
        return;
    case 39:
        next = Camera44Override;
        if (next) goto applySelector;
        if ((Camera44Pressed & 16) && Camera44Player[0x1B9] &&
                *(int*)(Camera44Player + 0x24C) == 4) {
            next = 31;
            goto applySelector;
        }
freshTable:
        index = *(int*)(Camera44Player + 0x48);
        { register int current __asm__("$3") = Camera44Mode;
        next = Camera44ModeTable[index];
        if (current == next) return;
        if (next) goto applySelector;
        next = 6;
        goto applySelector;
        }
    default:
        return;
    }
applySelector:
    func_80016764(next);
}
