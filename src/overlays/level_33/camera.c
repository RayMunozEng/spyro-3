#include "common.h"
#include "camera.h"

// File likely to be one that can be genericised

#define LEVEL_ID 33

#if (LEVEL_ID == 33) || (LEVEL_ID == 43) || (LEVEL_ID == 44) || (LEVEL_ID == 46)
    #define IS_AGENT_9_LEVEL
#endif

#if (LEVEL_ID == 10) || (LEVEL_ID == 20) || (LEVEL_ID == 30) || (LEVEL_ID == 40) \
 || (LEVEL_ID == 50) || (LEVEL_ID == 17) || (LEVEL_ID == 27) || (LEVEL_ID == 37) \
 || (LEVEL_ID == 23) || (LEVEL_ID == 32) || (LEVEL_ID == 33) || (LEVEL_ID == 44)
    #define IS_ZOOM_OUT_CAMERA_LEVEL
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/level_33/camera", func_level_33_8009DE6C);

/**
 * ???() - func_level_33_8009EA3C() - MATCHING
 * https://decomp.me/scratch/wQiRZ
 */
void func_level_33_8009EA3C() {
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
extern Vector3D DecodedMode40Position __asm__("D_8006E1B0");
extern short DecodedMode40InputX __asm__("D_8006E03C");
extern short DecodedMode40InputY __asm__("D_8006E03E");
extern short DecodedMode40InputZ __asm__("D_8006E040");
extern int DecodedMode40OutputX __asm__("D_8006E1BC");
extern int DecodedMode40OutputY __asm__("D_8006E1C0");
extern int DecodedMode40OutputZ __asm__("D_8006E1C4");
/* AI generated adaptation; not human reviewed.
 * SCUS-94467 USA Rev0 8009EAC4..8009ED5C and original mode dispatch.
 * Reuses verified level44_8009387C reset/copy and raw mode31 routes.
 * Original reset modes3/23/39 and new modes40/41 retain every field width,
 * post-helper read, signed-halfword extension and ordered raw word store.
 * Mode40 copies E020->E1B0, then E03C/E03E/E040 to E1BC/E1C0/E1C4;
 * mode41 transfers player+64 to E140 after zeroing E144/E158/E15C.
 * Shared enable tail retains original argument/helper and flag ordering.
 * Input/tag producers, units and caller cadence remain unresolved.
 * Acceptance: every original code/table word and complete retail hashes.
 */
void func_level_33_8009EAC4(int mode) {
    register int* base __asm__("$16");
    register unsigned char* actor __asm__("$16");
    register CameraPosition* position __asm__("$17");
    register int* copyBase __asm__("$17");
    register CameraPosition* copiedPosition __asm__("$16");
    register int enabled __asm__("$2");
    register unsigned char* flagBase __asm__("$16");
    register CameraPosition* flagPosition __asm__("$17");
    register Vector3D* target __asm__("$18");
    register Vector3D* savedPosition __asm__("$16");
    register CameraPosition* resetPosition __asm__("$4");
    switch (mode) {
    case 3:
    case 23:
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
    }
    case 40: {
        register int x __asm__("$2");
        register int y __asm__("$3");
        register int z __asm__("$5");
        savedPosition = &DecodedMode40Position;
        func_8004F178(savedPosition, (Vector3D*)((char*)savedPosition - 0x190));
        x = DecodedMode40InputX;
        y = DecodedMode40InputY;
        z = DecodedMode40InputZ;
        __asm__("" : "=r"(x), "=r"(y), "=r"(z) : "0"(x), "1"(y), "2"(z));
        DecodedMode40OutputX = x;
        DecodedMode40OutputY = y;
        DecodedMode40OutputZ = z;
        resetPosition = (CameraPosition*)((char*)savedPosition - 0xEC);
        goto enable;
    }
    case 41: {
        register int* state __asm__("$2") = &DecodedMode31CameraState;
        register int value __asm__("$3") = DecodedMode31Value;
        __asm__("" : "=r"(state), "=r"(value) : "0"(state), "1"(value));
        resetPosition = (CameraPosition*)((char*)state - 0x7C);
        DecodedMode31Camera144 = 0;
        DecodedMode31Camera158 = 0;
        DecodedMode31Camera15C = 0;
        *state = value;
    }
enable:
    func_80013900(resetPosition);
    D_8006E13D = 1;
    D_8006E138 = 1;
    D_8006E139 = 1;
    DecodedMode31Camera12C = 0;
    DecodedMode31Camera130 = 0;
    D_8006E054 = 0;
    DecodedMode31Flag = 1;
    break;
    }

}

extern unsigned char Camera33Flags[] __asm__("D_80070328+0x210");
extern CameraPosition Camera33Position __asm__("D_8006E088");
void Camera33Subtract(Vector3D*,Vector3D*,Vector3D*) __asm__("func_8004F1C8");
extern CameraPosition D_80068FE0;
extern int Camera33Mode __asm__("D_8006E044");
extern int Camera33Override __asm__("D_8006E160");
extern int Camera33Held __asm__("D_8006E538");
extern int Camera33Pressed __asm__("D_8006E53C");
extern unsigned char Camera33Player[] __asm__("D_80070328");
extern int Camera33ModeTable[] __asm__("D_80068CAC");
/* AI generated; not human reviewed. SCUS-94467 8009ED60..8009F260.
 * Baseline: verified level44_80093AB8 selector/copy structure. Original level33
 * supplies independent table routes, selectors23/40/41 and numeric pointer chains.
 * Empty constraints preserve original producer ordering and shared branch tails.
 * Helper contracts, table/actor producers, units and invocation cadence remain open.
 * Acceptance: every original code/table word and every complete retail hash.
 */
void func_level_33_8009ED60(void) {
    Vector3D local;
    register int mode __asm__("$2") = Camera33Mode;
    register int next __asm__("$4");
    register int index __asm__("$2");
    register int flag __asm__("$2");
    switch (mode) {
    case 3:
        next = Camera33Override;
        if (next) goto applySelector;
        if (Camera33Held & 16) {
            flag = Camera33Player[0x1B9];
            __asm__ __volatile__("" : "=r"(flag) : "0"(flag) : "$4");
            next = 7;
            if (flag) goto applySelector;
        }
        flag = Camera33Pressed & 12;
        __asm__ __volatile__("" : "=r"(flag) : "0"(flag) : "$4");
        next = 8;
        if (flag) goto applySelector;

        index = *(int*)(Camera33Player + 0x48);
        { register int current __asm__("$3") = Camera33Mode;
        __asm__ __volatile__("" : "=r"(index) : "0"(index), "r"(current));
        next = Camera33ModeTable[index];
        if (current == next) return;
        if (next) goto applySelector;
        __asm__ __volatile__("" : "=r"(current) : "0"(current) : "$4");
        next = 6;
        goto applySelector;
        }

    case 17:
        next = Camera33Override;
        if (!next) goto readTable;
        if (next == 17) return;
        goto applySelector;
    case 23:
        next=Camera33Override;
        if(next)goto applySelector;

        index = *(int*)(Camera33Player + 0x48);
        { register int current __asm__("$3") = Camera33Mode;
        __asm__ __volatile__("" : "=r"(current) : "0"(current), "r"(index));
        next = Camera33ModeTable[index];
        if (current == next) return;
        if (next) goto applySelector;
        __asm__ __volatile__("" : : "r"(current) : "$4");
        next = 6;
        goto applySelector;
        }

    case 31:
        next = Camera33Override;
        if (next && next != 40) func_80016764(next);
        if (Camera33Player[0x1B9] == 0) {
            register int* overrideState __asm__("$17") = &Camera33Override;
            register CameraPosition* initial __asm__("$16") = (CameraPosition*)((char*)overrideState - 0xD8);
            if (*overrideState == 40) {
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
            func_80016764(Camera33ModeTable[*(int*)(Camera33Player + 0x48)]);
            ((unsigned char*)*(unsigned int*)(Camera33Player + 0x250))[0x4C] = 16;
            return;
        }
        if (Camera33Pressed & 16) {
            register int* overrideState __asm__("$17") = &Camera33Override;
            register CameraPosition* initial __asm__("$16") = (CameraPosition*)((char*)overrideState - 0xD8);
            if (*overrideState == 40) {
                __asm__ __volatile__("" : : "r"(overrideState) : "$4");
                next=40;
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
            func_80016764(0);
            camera.unk50 = 2;
            ((unsigned char*)*(unsigned int*)(Camera33Player + 0x250))[0x4C] = 16;
        }
        return;
    case 39:
        next = Camera33Override;
        if (next) goto applySelector;
        if ((Camera33Pressed & 16) && Camera33Player[0x1B9] &&
                *(int*)(Camera33Player + 0x24C) == 4) {
            next = 31;
            goto applySelector;
        }

        index = *(int*)(Camera33Player + 0x48);
        { register int current __asm__("$3") = Camera33Mode;
        next = Camera33ModeTable[index];
        if (current == next) return;
        if (next) goto applySelector;
        next = 6;
        goto applySelector;
        }
    case 40:
        next=Camera33Override;
        if(next && next!=Camera33Mode)goto applySelector;
        if((Camera33Pressed&16) && Camera33Player[0x1B9] && *(int*)(Camera33Player+0x24C)==4) {
            next=31;
            goto applySelector;
        }
        return;
    case 41:
        next=Camera33Override;
        if(next && next!=Camera33Mode)goto applySelector;
        {
            register unsigned char* flagBase __asm__("$18")=Camera33Flags;
            register Vector3D* source __asm__("$17");
            register CameraPosition* destination __asm__("$16");
            register Vector3D* argument __asm__("$4");
            if(*(int*)flagBase&0x20000)return;
            func_8004F178(&local,(Vector3D*)(flagBase+0xC));
            argument=&local;
            __asm__("" : "=r"(argument) : "0"(argument) : "$17");
            source=(Vector3D*)(flagBase-0x210);
            Camera33Subtract(argument,source,argument);
            destination=&Camera33Position;
            func_800136F0(destination,&local,source);
            func_8004F178((Vector3D*)((char*)destination-0x30),source);
            __asm__("" : "=r"(flagBase) : "0"(flagBase));
            camera.unk6c=*(int*)(flagBase-0x1AC);
            func_800135A4((CameraPosition*)((char*)destination+0x14),destination,0);
            camera.unk140[0]=0;
            camera.unk140[1]=0;
            camera.unk140[2]=1;
            camera.unk140[5]=0;
            func_80012AC8();
            func_80012B34();
readTable:next=Camera33ModeTable[*(int*)(Camera33Player+0x48)];
goto applySelector;
        }
    default:
        return;
    }
applySelector:
    func_80016764(next);
}
