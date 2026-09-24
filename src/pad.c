#include "common.h"
#include "stdutil.h"
#include "pad.h"
#include "str.h"

// psyq
extern void VSync(int); // VSync

// sdata
extern PsyqPad* currentDemoInput; // 8006C538, note that if PsyqPad is updated any ptr arithmetic will need updating
extern char D_8006C5B4;
extern int* D_8006C55C; // ptr to start of demo inputs block (specifically length)
extern int D_8006C644;
extern int isDemoMode; // 8006C658 - note that isDemoMode should not be volatile in here
extern char D_8006C760;
extern int D_8006C7CC;

// TODO - hardware types (e.g. 0x53 is The Contraption)

////////////////////////////////////////////////////////////////////////////////////

/**
 * ???() - func_80039E34()
 * Nearly there, maybe bad structs
 * https://decomp.me/scratch/8klxB
 */
void func_80039E34(StickState* arg0, Pad* arg1) {
    int i = 0;
    int max;

    *(int*)arg0 = 0x7F7F7F7F;
    *(int*)&arg1->unk2a = 0x7F7F7F7F;
    /* Keep the constant load after the two initialization stores. */
    __asm__ volatile("" ::: "memory");
    max = 0xFF;
    for (i = 0; i < 4; i++) {
        int high;
        int low;
        arg0 = (StickState*)((char*)arg1 + i);
        high = *(volatile unsigned char*)((char*)arg0 + 8);
        low = *(volatile unsigned char*)((char*)arg0 + 8);
        high += 0x30;
        ((unsigned char*)arg0)[0xC] = high;
        ((unsigned char*)arg0)[0x14] = max - high;
        low -= 0x30;
        ((unsigned char*)arg0)[0x10] = low;
        ((unsigned char*)arg0)[0x18] = low;
    }
}

/**
 * ???() - func_80039E88() - MATCHING? INVESTIGATION NEEDED
 * May want to confirm this takes a Pad* input, also comes with a slight modification to Pad
 * What are these inputs??
 * Also worth noting that changing the StickState from "typedef (unsigned) char StickState[4]" to the new def breaks this?
 * Possibly requires rewriting some functions in here to use the old typedef
 * https://decomp.me/scratch/i6QZs
 */
/* Retail source: 0x80039E88..0x8003A010. Four analog stick bytes
 * are normalized using per-axis limits at Pad offsets 0xC..0x1B. */
extern volatile int D_8006C658;
void func_80039E88(unsigned char* arg0, Pad* arg1) {
    int var_t0;
    int var_v1;
    unsigned char temp_a2;
    unsigned char temp_a2_2;
    unsigned char temp_v1;
    unsigned char temp_v1_2;
    unsigned char* axis;
    if (D_8006C658 == 0) {
        for (var_t0 = 0; var_t0 < 4; var_t0++) {
            temp_v1 = arg0[var_t0];
            axis = (unsigned char*)arg1 + var_t0;
            temp_a2 = axis[0xC];
            if (temp_v1 > temp_a2)
                arg0[var_t0] = (((temp_v1 - temp_a2) << 7) / axis[0x14]) + 0x7F;
            else {
                temp_a2_2 = axis[0x10];
                if (temp_v1 < temp_a2_2)
                    arg0[var_t0] = (((temp_v1 - temp_a2_2) << 7) / axis[0x18]) - 0x80;
                else arg0[var_t0] = 0x7F;
            }
        }
        return;
    }
    for (var_v1 = 0; var_v1 < 4; var_v1++) {
        temp_v1_2 = arg0[var_v1];
        if (temp_v1_2 >= 0xB0)
            arg0[var_v1] = (((temp_v1_2 - 0xAF) << 7) / 80) + 0x7F;
        else if (temp_v1_2 < 0x4F)
            arg0[var_v1] = (((temp_v1_2 - 0x4F) << 7) / 79) - 0x80;
        else arg0[var_v1] = 0x7F;
    }
}

/**
 * ???() - func_8003A010() - MATCHING
 * Probably VSync callback?
 * https://decomp.me/scratch/qY3Qr
 */
void func_8003A010(Pad* arg0) {
    PadState* var_s4; // specifically should be a pointer to an array of four PadStates
    PsyqPad* var_s5;
    int i;
    enum PadInput var_v1;
    unsigned char storedControllerType;

    storedControllerType = arg0->controllerType;
    if (arg0 == &pad) {
        var_s5 = &demoPadState;
        var_s4 = &D_80071500[0];
    } else {
        var_s5 = &D_800718DC;
        var_s4 = &D_80071FD8[0];
    }
    
    if (var_s5->status) {
        arg0->controllerType = CONTROLLER_TYPE_DISCONNECTED;
        arg0->unk1c = 0;
        arg0->unk1d = 0;
        arg0->unk1b = 0;
    }
    else {
    	switch(var_s5->size_type) {
    		case 0x41:
    			arg0->controllerType = CONTROLLER_TYPE_DPAD;
    			break;
    		case 0x53:
    		case 0x73:
    			if (arg0->controllerType != CONTROLLER_TYPE_STICK) func_80039E34(&var_s5->stick, arg0);
    			arg0->controllerType = CONTROLLER_TYPE_STICK;
    			break;
    		default:
    			arg0->controllerType = CONTROLLER_TYPE_INVALID;
    			break;
    	}
        
        if (arg0->controllerType != storedControllerType) {
            arg0->unk2[0] = 1;
            arg0->unk1d = 0;
            arg0->unk1b = 0;
        }
    }
    
    for (i = 3; i > 0; i--) func_8004E7D4((int*)&var_s4[i], (int*)&var_s4[i - 1], 0x10);
    if (arg0->controllerType < 2) return; // invalid or disconnected

    var_s4->held = (~((var_s5->input[0] << 8) | var_s5->input[1]) & 0xFFFF); // convert the psyq inputs to controller inputs
    if (arg0->controllerType == CONTROLLER_TYPE_STICK) {
        *(int*)&var_s4->stick = *(int*)&var_s5->stick;
        func_80039E88(&var_s4->stick, arg0);
        
        if (var_s5->size_type == 0x53) { // SCPH-1110 remapping
            var_v1 = var_s4->held & ~(SQU | TRI | R1 | L1 | R2);
            if (var_s4->held & SQU) var_v1 |= R2;
            if (var_s4->held & TRI) var_v1 |= R1;
            if (var_s4->held &  R1) var_v1 |= TRI;
            if (var_s4->held &  R2) var_v1 |= L1;
            if (var_s4->held &  L1) var_v1 |= SQU;
            var_s4->held = var_v1;
        }
        
        if (!(var_s4->held & (U | R | D | L))) { // set pad inputs based on sticks
            if      (var_s4->stick.lx >= 193) var_s4->held |= R;
            else if (var_s4->stick.lx  <  64) var_s4->held |= L;
            
            if      (var_s4->stick.ly >= 193) var_s4->held |= D;
            else if (var_s4->stick.ly  <  64) var_s4->held |= U;
        }
    } else {
        *(int*)&var_s4->stick = 0x7F7F7F7F;
    }
    var_s4->pressed = (~var_s4[1].held & var_s4->held);
    var_s4->released = (var_s4[1].held & ~var_s4->held);   
}

/**
 * ???() - func_8003A2B0() - MATCHING
 * This one required isDemoMode to be non-volatile and needed -G0 / G4!
 * https://decomp.me/scratch/lUhLW
 */
void func_8003A2B0(void) {
    int i;
    int x;

    pad.unk3[0] = 0;
    pad.unk3[1] = 0;
    pad.unk3[2] = 0;
    if (isDemoMode == 2) {
        *(int*)&currentDemoInput->status = *(int*)&demoPadState.status;
        x = ((int)currentDemoInput - (int)D_8006C55C) >> 2;
        *(int*)&currentDemoInput->stick  = *(int*)&demoPadState.stick;
        *D_8006C55C = (x + 1) / 2;
    }
    for (i = 0; i < 2; i++) {
        D_8006C644++;
        *(int*)&demoPadState.status = *(int*)&currentDemoInput->status;
        *(int*)&demoPadState.stick = *(int*)&currentDemoInput->stick;
        func_8003A010(&pad);
        D_8006C7CC++;
    };
    if (isDemoMode == 2) {
        VSync(2);
    }
    *(int*)&demoPadState.status = 0xFFFF7300;
    *(int*)&demoPadState.stick = 0x7F7F7F7F;
    currentDemoInput++;
}

/**
 * ???() - func_8003A40C() - MATCHING
 * Now matches without isDemoMode volatile!
 * https://decomp.me/scratch/F8T5A
 */
void func_8003A40C() {
    Pad* var_v1;
    char* var_a0;
    int var_a1;
    int x;

    cdState.readTime++; 
    x = isDemoMode; // need this to match, or otherwise to make isDemoMode volatile
    if (x == 0) {
        
        D_8006C644++;
        for (var_a1 = 0; var_a1 < 2; var_a1++) {
            
            if (var_a1 != 0) {
                var_v1 = &pad2; // pad2
                var_a0 = &D_8006C5B4;
            } else {
                var_v1 = &pad; // pad
                var_a0 = &D_8006C760;
            }

            var_a0[0] = 0;
            var_a0[1] = 0;
            if ((var_v1->unk1d != 0) && (var_v1->vibrationMode != 0)) {
                
                if (var_v1->unk3[2] != 0) {
                    var_v1->unk3[2]--;
                    var_a0[0] = 0;
                    var_a0[1] = var_v1->unk3[3];
                }
                
                if (var_v1->unk3[1] != 0) {
                    var_v1->unk3[1]--;
                    var_a0[0] = 1;
                    var_a0[1] = 0;
                }
                
                if (var_v1->unk3[0] != 0) {
                    var_v1->unk3[0]--;
                    var_a0[0] = 1;
                    var_a0[1] = 0x78;
                }
                
            } else {
                var_v1->unk3[0] = 0;
                var_v1->unk3[1] = 0;
                var_v1->unk3[2] = 0;
            }
        }
    }
    
    if (!isDemoMode) {
        func_8003A010(&pad);
        func_8003A010(&pad2);
        D_8006C7CC++;
    }
}

/**
 * ???() - func_8003A584()
 * Rev 0 target: asm/nonmatchings/pad/func_8003A584.s,
 * 0x8003A584..0x8003A908 (225 words). The complete linked EXE matches retail.
 * PadState history entries are 0x10 bytes; the count is capped at four here.
 * https://decomp.me/scratch/5tZWF supplied a candidate, refined against the target.
 */
extern int D_8006C648;
extern short D_80065870[4];
extern void func_8004E7D4(int*, int*, int);
extern unsigned int func_8005DCAC();
extern unsigned int func_8005DD78(int, int, int);
extern unsigned int func_8005DE70(int, int, int);
extern int func_8005DF44(int, short*);
extern int func_8005DF7C(int, char, char);
extern void func_8005DFC4(int, char*, char);

void func_8003A584() {
    char* sp10;
    int var_s5;
    Pad* var_s1;
    PadState* var_s6;
    int temp_a1, temp_v0, temp_v0_2, temp_v0_3;
    int var_fp, var_s0_2, i, var_s2_2, var_s4, var_s3;
    unsigned char temp_v1;
    if (isDemoMode) func_8003A2B0();
    temp_v0 = D_8006C7CC;
    D_8006C7CC = 0;
    D_8006C648 = temp_v0;
    if (temp_v0 >= 5) D_8006C648 = 4;
    for (var_fp = 0; var_fp < 2; var_fp++) {
        if (var_fp) {
            var_s1 = &pad2;
            var_s6 = &D_80071FD8[0];
            var_s5 = 0x10;
            sp10 = &D_8006C5B4;
        } else {
            var_s1 = &pad;
            var_s6 = &D_80071500[0];
            var_s5 = 0;
            sp10 = &D_8006C760;
        }
        var_s1->buttonPressed = 1;
        var_s1->dpadPressed = 1;
        var_s1->unk4 = 0;
        var_s1->state.pressed = 0;
        var_s1->state.released = 0;
        if (D_8006C648 >= 4) {
            var_s1->state.pressed = ~var_s1->state.held & var_s6[3].held;
            var_s1->state.released = var_s1->state.held & ~var_s6[3].held;
        }
        for (i = 0; i < (temp_a1 = D_8006C648); i++) {
            var_s3 = (i + 4) * 0x10;
            var_s4 = (i + 1) * 0x10;
            func_8004E7D4((int*)((char*)var_s1 + var_s3), (int*)((char*)var_s6 + temp_a1 * 0x10 - var_s4), 0x10);
            var_s1->state.pressed |= var_s1->store[i].pressed;
            var_s1->state.released |= var_s1->store[i].released;
            temp_v1 = var_s1->store[i].stick.lx;
            if (temp_v1 != 0x7F || var_s1->store[i].stick.ly != temp_v1) {
                var_s1->unk4 = 1;
                var_s1->dpadPressed = 0;
            } else if (var_s1->store[i].held & 0xF000) {
                var_s1->dpadPressed = 0;
            }
            if (var_s1->dpadPressed == 0 || (var_s1->store[i].held & 0xF0FF)) {
                var_s1->buttonPressed = 0;
            }
        }
        var_s1->state.held = (int)var_s6[0].held;
        *(int*)&var_s1->state.stick = *(int*)&var_s6[0].stick;
        if (var_s1->unk2[0] != 0) {
            temp_v0_2 = func_8005DCAC(var_s5, temp_a1);
            if (temp_v0_2 == 2) {
                var_s1->unk1b = 1;
                var_s1->unk2[0] = 0;
            } else if (temp_v0_2 == 6) {
                if (var_s1->unk1c == 0 || var_s1->unk1b == 0) {
                    var_s1->unk1d = 0;
                    if (func_8005DD78(var_s5, 4, 1) == 7) {
                        temp_v0_3 = func_8005DE70(var_s5, -1, 0);
                        var_s2_2 = 0;
                        if (temp_v0_3 == 2) {
                            for (var_s0_2 = 0; var_s0_2 < temp_v0_3; var_s0_2++) {
                                var_s2_2 += func_8005DE70(var_s5, var_s0_2, 4);
                            }
                            if (var_s2_2 < 0x3C) {
                                if (var_s1->unk1b == 0) {
                                    func_8005DFC4(var_s5, sp10, 2);
                                    if (func_8005DF44(var_s5, D_80065870) != 0) var_s1->unk1b = 1;
                                }
                                var_s1->unk1d = 1;
                                if (func_8005DF7C(var_s5, 1, 0) != 0) var_s1->unk1c = 1;
                            } else var_s1->unk2[0] = 0;
                        } else var_s1->unk2[0] = 0;
                    }
                } else var_s1->unk2[0] = 0;
            }
        }
    }
    if (D_8006C648 < 2) D_8006C648 = 2;
}

/**
 * ???() - func_8003A908() - MATCHING
 * Seems to suggest the extra pad states are separate from the first
 * https://decomp.me/scratch/dDgAz
 */
void func_8003A908(Pad* arg0) {
    int var_v1;

    *(int*)&arg0->state.stick = 0x7F7F7F7F;
    arg0->state.held = 0;
    arg0->state.pressed = 0;
    arg0->state.released = 0;
    arg0->buttonPressed = 1;
    arg0->dpadPressed = 1;
    arg0->unk4 = 0;
    for (var_v1 = 0; var_v1 < 4; var_v1++) {
        arg0->store[var_v1].held = 0;
        arg0->store[var_v1].pressed = 0;
        arg0->store[var_v1].released = 0;
        *(int*)&arg0->store[var_v1].stick = 0x7F7F7F7F;
    }
}

/**
 * ???() - func_8003A964() - MATCHING
 * https://decomp.me/scratch/v1zl4
 */
void func_8003A964(Pad* arg0, Pad* arg1) {
    int temp_s1;
    int temp_s2;
    int temp_s3;
    int temp_s4;

    temp_s1 = arg1->unk3[0];
    temp_s2 = arg1->unk3[1];
    temp_s3 = arg1->unk3[2];
    temp_s4 = arg1->unk3[3];
    func_8004E7D4((int*)arg1, (int*)arg0, 0x80); // copy arg0 into arg1
    arg1->unk3[0] = temp_s1;
    arg1->unk3[1] = temp_s2;
    arg1->unk3[2] = temp_s3;
    arg1->unk3[3] = temp_s4;
    func_8003A908(arg0);
}

/**
 * ???() - func_8003A9EC() - MATCHING
 * https://decomp.me/scratch/pUFWe
 */
void func_8003A9EC() {
    pad.unk2[0] = 1;
    pad.unk1c = 0;
    pad.unk1d = 0;
    pad.unk1b = 0;
    pad2.unk2[0] = 1;
    pad2.unk1c = 0;
    pad2.unk1d = 0;
    pad2.unk1b = 0;
}
