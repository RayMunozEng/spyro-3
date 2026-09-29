#include "common.h"
#include "environment.h"
#include "hud.h"
#include "tracers.h"
#include "savepoint.h"
#include "camera.h"
#include "mobyupdate.h"
#include "pad.h"
#include "spu.h"
#include "stdutil.h"
#include "str.h"
#include "warp.h"
#include "ovl_header.h"
#include "spyro.h"

// spyroupdate
extern void func_8003E83C(); // UpdateSpyro

// updatepause
extern void func_80057834(); // pause updates

//extern void func_title_8007566C(); // title screen updates // "ovlHeader+0x139C"

// data
extern unsigned char levelIndexToHomeworldLevelId[40]; // 800671A0

// sdata
extern int loadStage; // 8006C518
extern int levelIndex; // 8006C58C
extern int D_8006C598;
extern Moby* D_8006C5F8; // dunno what this is but it's a Moby, probably bullet time related
extern int deltaTime; // 8006C648
extern short D_8006C67C;
extern int D_8006C718;
extern int D_8006C7C8;

// bss
extern Game game; // 8006E344 - game.state
extern PauseData pauseData; // 8006fbc4

////////////////////////////////////////////////////////////////////////////////////

/* Retail source: USA Rev 0 PSX.EXE 0x80050B90..0x80050F18 (226 instructions).
 * Raw SHA-256 13c06150...d8a7; Rev 1 0x80050BB4 corroborates behavior.
 * Units: six byte lanes, 18-byte level records, mask bits, byte thresholds, and
 * an integer timer advanced by 10 and capped at 30. Cadence: one call evaluates
 * the base mask and up to six lanes. Confidence: confirmed retail exact by the
 * PSX.EXE SHA-256 e5406997...e39f and all 62 manifest hashes.
 * Falsifiable vectors: override nonzero; timer -20/-19/10/11; entry remainder
 * 1..5; packed modes 0x10/0x20/0x30; mask bits; threshold edges; fresh mode 3. */
extern int D_8006C658;
extern int D_8006C7C4;
extern int D_8006C7A8;
extern int D_8006C564;
extern int D_8006C5BC;
extern int D_8006C58C;
extern int D_8006C5C8;
extern int D_8006C504;
extern unsigned char D_8006C7B4;
extern unsigned char D_80066BDC[];
extern unsigned char D_80066BDD[];
extern unsigned char D_80066BDE[];
extern unsigned char D_80070300[];
extern unsigned char D_800715BC[];
extern unsigned char D_800716AC[];
void func_80050B90(void) {
    register int lane __asm__("$7");
    register int laneOffset __asm__("$9");
    register int entryId __asm__("$4");
    register int entryRemainder __asm__("$8");
    register int level __asm__("$5");
    int level2;
    int recordOffset;
    register int packed __asm__("$5");
    register int packedMode __asm__("$3");
    register int remainderProduct __asm__("$3");
    register int firstPacked __asm__("$2");
    register int firstOffset __asm__("$2");
    register int divisionV0 __asm__("$2");
    register int divisionV1 __asm__("$3");
    register int divisionHi __asm__("$24");
    int mode;
    register int threshold __asm__("$3");
    register int two __asm__("$11");
    register int one __asm__("$12");
    register int three __asm__("$10");
    register int five __asm__("$13");
    register unsigned char* thresholdBase __asm__("$14");
    register unsigned char* stateBase __asm__("$15");

    if (D_8006C658 != 0) {
        D_8006C7C4 = 1;
        return;
    }
    if (D_8006C7A8 < -19) {
        D_8006C564 = 2;
    } else if (D_8006C7A8 < 11) {
        D_8006C564 = 1;
    } else {
        D_8006C564 = 0;
    }
    lane = 0;
    two = 2;
    thresholdBase = D_800716AC;
    one = 1;
    three = 3;
    five = 5;
    stateBase = D_800715BC;
    D_8006C7C4 = D_8006C564;
    laneOffset = 0;
loop:
    __asm__ volatile (
        "lui %1,0x6666\n"
        "lui %0,%%hi(D_8006C5BC)\n"
        "lw %0,%%lo(D_8006C5BC)(%0)\n"
        "ori %1,%1,0x6667\n"
        "mult %0,%1\n"
        "lui %2,%%hi(D_8006C58C)\n"
        "lw %2,%%lo(D_8006C58C)(%2)\n"
        "sra %1,%0,31\n"
        "mfhi %4\n"
        "sra %3,%4,2\n"
        "subu %5,%3,%1"
        : "=r"(entryId), "=r"(divisionV0), "=r"(level),
          "=r"(divisionV1), "=r"(divisionHi), "=r"(entryRemainder));
    remainderProduct = entryRemainder * 10;
    firstOffset = level * 18;
    __asm__ volatile ("addu %0,%1,%2" : "=r"(firstOffset) : "r"(laneOffset), "0"(firstOffset));
    firstPacked = D_80066BDC[firstOffset];
    entryRemainder = entryId - remainderProduct;
    packedMode = firstPacked & 0xF0;
    if (lane == 0 && (unsigned)(entryRemainder - 1) < 4) {
        if ((D_8006C7B4 & 1) != 0) goto next_lane;
        if ((D_80070300[level] & 1) != 0) goto next_lane;
    }
    if (packedMode == 0x30) goto next_lane;
    level2 = D_8006C58C;
    recordOffset = laneOffset + level2 * 18;
    packed = D_80066BDC[recordOffset];
    if ((packed & 0xF) != D_8006C5C8) goto next_lane;
    if (((D_8006C7B4 >> lane) & 1) != 0) goto next_lane;
    D_8006C504 = two;
    packedMode = packed & 0xF0;
    if (packedMode == 0x10) goto mode_10;
    if (packedMode == 0x20) goto mode_20;
    goto mode_done;
mode_10:
    threshold = (thresholdBase + level2 * 6)[lane];
    if (threshold < D_80066BDD[recordOffset]) goto set_one;
    if (!(D_80066BDE[recordOffset] < threshold)) goto set_two;
    goto set_three;
mode_20:
    threshold = (thresholdBase + level2 * 6)[lane];
    if (!(threshold < D_80066BDD[recordOffset])) goto check_high;
set_one:
    D_8006C504 = one;
    goto mode_done;
check_high:
    if (D_80066BDE[recordOffset] < threshold) goto set_three;
set_two:
    D_8006C504 = two;
    goto mode_done;
set_three:
    D_8006C504 = three;
mode_done:
    if (D_8006C504 == two) {
        if (lane != 0 || entryRemainder == five) {
            if (D_8006C7C4 >= 2) D_8006C7C4 = one;
        }
    }
    mode = D_8006C504;
    if (mode == three) D_8006C7C4 = 0;
    {
        register int stateLevel __asm__("$2") = D_8006C58C;
        register unsigned char* state __asm__("$3");
        state = (unsigned char*)(stateLevel * 6);
        state += (int)stateBase;
        state += lane;
        if (*state == 0 && mode == three) {
            *state = (unsigned char)mode;
            D_8006C7A8 += 10;
            if (D_8006C7A8 >= 31) D_8006C7A8 = 30;
        }
    }
    if (entryRemainder != five) return;
next_lane:
    lane++;
    if (lane < 6) {
        laneOffset += 3;
        goto loop;
    }
}
INCLUDE_ASM("asm/nonmatchings/update", func_80050F18);

INCLUDE_ASM("asm/nonmatchings/update", func_800512E4);

extern int D_8006E344;
extern int D_8006C74C;
extern char D_80070328;
extern int D_8006C620;
extern int D_8006C684[];
extern unsigned char* D_8006C68C[];
extern int D_8006C778;
extern int D_8006C72C;
extern Moby* D_8006C5A8;
extern int D_8006C770;
extern short D_8006C57C;
extern Moby* D_8006C69C;
extern int D_8006C5FC;
extern int D_8006C590;
extern void func_80035734(Moby*);
/* Retail source: asm/nonmatchings/update/func_800518F8.s,
 * 0x800518F8..0x80051A60; raw bytes and per-call state reset. */
void func_800518F8(void) {
    int i;
    int j;
    for (i = 0; i < D_8006C620; i++) {
        for (j = 0; j < D_8006C684[i]; j++) {
            D_8006C68C[i][j] = 0x5E;
        }
    }
    if (D_8006C778 != D_8006C72C) {
        Moby* moby = (Moby*)D_8006C5A8;
        if (moby->animationState.nextId != D_8006C72C) {
            D_8006C770 = 0;
            moby->animationProgress = 0xF2;
            ((Moby*)D_8006C5A8)->animationState.nextId = D_8006C72C;
            ((Moby*)D_8006C5A8)->animationState.nextFrame = 0;
            func_80035734((Moby*)D_8006C5A8);
        }
    }
    {
        int* current = (int*)D_8006C5A8;
        int tag;
        D_8006C57C = -1;
        D_8006E344 = 0;
        tag = *current;
        /* Preserve the retail load delay; this emits no instruction. */
        asm volatile ("" : : "r"(tag));
        D_8006C69C = 0;
        D_8006C5FC = 0;
        D_8006C590 = -1;
        D_8006C74C = 0;
        if (*((unsigned char*)tag + 5) == 2) {
            *(int*)(&D_80070328 + 0x20C) = 0x10000002;
        }
    }
}

/**
 * ???() - func_80051A60() - MATCHING
 * Ready to add
 * Differs in 1.1, so would be interesting to add
 * https://decomp.me/scratch/ziJbr
 */
/* Rev 0 source hypothesis: asm/nonmatchings/update/func_80051A60.s. */
extern int D_8006C790, D_8006C78C, D_8006C648, D_8006C5C4;
extern unsigned char D_8006C680;
void func_80047D00(Moby*);
void func_80055294(int);
extern short D_80065920[0x100], D_800658A0[0x100];
#define D_80070328 g_Spyro
typedef struct {
    short unk0;
    short unk2;
    short unk4;
    short unk6;
} MobyTag_132;
extern CameraPosition D_80069094[]; // this too
extern CameraPosition D_800690F8[]; // this one actually DOES seem to be an array of CameraPositions! Not sure how big
extern CameraPosition D_8006915C[]; // this too
extern int D_8006C51C;
extern int D_8006C520;
extern unsigned char D_8006C53C;
extern short D_8006C544;
extern int D_8006C594;
extern unsigned char D_8006C5AC;
extern int D_8006C624;
extern SoundTable* D_8006C654; // may be better off as a char*, really
extern int D_8006C66C;
extern int D_8006C674;
extern int D_8006C6A4;
extern int D_8006C6D8;
extern int D_8006C6DC;
extern unsigned char D_8006C6E4;
extern int D_8006C6E8;
extern int D_8006C6FC;
extern int D_8006C794;
extern int D_8006C798;
extern unsigned char D_8006C7A4;
extern int D_8006C7BC;
extern short D_80071938[]; // not sure how long this is

static inline void SetAnimation2(Moby* m, int prog, int next) {
    D_8006C770 = 0;
    m->animationProgress = prog;
    m->animationState.nextId = next;
    m->animationState.nextFrame = 0;
    func_80035734(m);
}

#define SetAnimation(moby, prog, id) \
    D_8006C770 = 0;\
    (moby)->animationProgress = (prog);\
    (moby)->animationState.nextId = (id);\
    (moby)->animationState.nextFrame = 0;\
    func_80035734(moby);

void func_80051A60() {
    Vector3D sp10;
    char temp_v0_3;
    int temp_v0_6;
    int var_s0;
    int var_v0_5;
    int var_v1;
    char temp_s1;

    // I struggled to find a match that didn't have a goto, good luck
	if (D_8006C778 != D_8006C72C) {
		if (D_8006C674 == 0xFF) {
			if (D_8006C5A8->animationState.nextId != D_8006C778) {
				SetAnimation(D_8006C5A8, 0xF2, D_8006C778);
			}
		}
		else {
			if (D_8006C5A8->animationState.nextId != D_8006C778) {
				if ((streamingData.dat_8006e4b4 == 2) && (streamingData.dat_8006e48c == 6 || streamingData.dat_8006e48c == 7)) {
					SetAnimation(D_8006C5A8, 0xF2, D_8006C778);
					goto block_out;
				}
				if (D_8006C5A8->animationState.nextId != D_8006C778) {
					goto block_out;
				}
			}
			if ((streamingData.dat_8006e4b4 != 2) || !((streamingData.dat_8006e48c == 6 || streamingData.dat_8006e48c == 7))) {
				if (D_8006C5A8->animationState.nextId != D_8006C72C) {
					SetAnimation(D_8006C5A8, 0xF2, D_8006C72C);
				}
				if (D_8006C798 != 0) {
                    // 1.1 only:
                    // D_8006C798 = 0;
					D_8006C790 = 2;
					D_8006C78C = 0;
				}
			}
		}
	}
block_out:

    D_8006C74C = 1;
    if (D_8006C790 == 0) {
        D_8006C78C += D_8006C648;
        if ((D_8006C78C >= 0x3C) && (D_8006C78C >= 0x4C)) { // ???????
            D_8006C78C = 0;
            D_8006C790 = 1;
        }
    }
    else if (D_8006C790 == 1) {
        if (D_8006C7A4 != 0) {
            D_8006C78C += D_8006C648;
            if ((D_8006C53C == 0) && (pad.state.pressed & 0x5000)) {
                PlaySound(D_8006C654->pauseMove, 0, 0);
                D_8006C78C = 0;
                if (pad.state.pressed & 0x1000) {
                    D_8006C57C--;
                }
                else if (pad.state.pressed & 0x4000) {
                    D_8006C57C++;
                }
                D_8006C57C = (D_8006C57C + D_8006C6E4) % D_8006C6E4;
            }
            if ((pad.state.pressed & 0x840) || ((D_8006C53C != 0) && (pad.state.pressed & 0x810))) {
                if (D_8006C53C != 0) {
                    PlaySound(D_8006C654->pauseExit, 0, 0x80);
                    D_8006C790 = 2;
                    D_8006C78C = 0;
                }
                else {
                    func_80037768(D_8006C5A8);
                    if (D_8006C7A4 != 0) {
                        func_800512E4(D_8006C5A8, D_8006C72C, D_8006C778);
                        if (D_8006C544 == 0) {
                            D_8006C57C = -1;
                        }
                    } else {
                        PlaySound(D_8006C654->pauseExit, 0, 0x80);
                        D_8006C790 = 2;
                        D_8006C78C = 0;
                    }
                }
            }
        } else if ((D_8006C5AC != 0) && (pad.state.pressed & 0x850)) {
            // 1.1: seems to have this here
            // D_8006C798 = 0;
            if (D_8006C544 != 0) {
                D_8006C7A4 = 1;
            } else if (D_8006C624 != -1) {
                func_80037768(D_8006C5A8);
                func_800512E4(D_8006C5A8, D_8006C72C, D_8006C778);
            } else {
                PlaySound(D_8006C654->pauseExit, 0, 0x80);
                D_8006C790 = 2;
                D_8006C78C = 0;
            }
        } else if (D_8006C6D8 != 0) {
            if (pad.state.pressed & 0x840) { // TODO - where pad.state is mentioned, replace this with the buttons
                // 1.1: this if statement also requires ((D_8006C798 == 0) || ((streamingData.dat_8006e4b4 == 2) && (streamingData.dat_8006e48c == 6 || streamingData.dat_8006e48c == 7)))
                // Ghidra suggests this if statement goes above this if:
                /*
                if ((DAT_8006c878 != 0) && ((DAT_8006e594 != 2 || (1 < DAT_8006e56c - 6U)))) {
                    bVar1 = true;
                }
                */
                D_8006C6E8 += 3;
                if (D_8006C6E8 >= D_8006C6A4) {
                    D_8006C6DC = D_8006C520;
                } else {
                    D_8006C6DC = D_80071938[D_8006C6E8];
                }
                D_8006C6D8 = 0;
            }
        } else {
            if (D_8006C794 != 0) {
                D_8006C78C += 2;
                D_8006C51C = (D_8006C78C * D_8006C520) / D_8006C594;
                if (pad.state.pressed & 0x840) {
                    D_8006C794 = 0;
                    streamingData.dat_8006e498 = 1;
                    if (D_8006C6FC < 5) {
                        D_8006C6E8 = 5;
                    }
                    else if (D_8006C6FC < 8) {
                        D_8006C6E8 = 8;
                    }
                    else if (D_8006C6FC < 11) {
                        D_8006C6E8 = 11;
                    }
                    if (D_8006C6A4 <= D_8006C6E8) {
                        D_8006C6DC = D_8006C520;
                    } else {
                        D_8006C6DC = D_80071938[D_8006C6E8];
                    }
                }
            } else {
                D_8006C51C += 3;
                if (pad.state.pressed & 0x840) {
                    D_8006C51C = D_8006C6DC;
                }
            }
            if (D_8006C51C >= D_8006C520) {
                D_8006C51C = D_8006C520;
                D_8006C5AC = 1;
            } else if (D_8006C51C >= D_8006C6DC) {
                D_8006C51C = D_8006C6DC;
                D_8006C6D8 = 1;
            } else if (D_8006C7BC != 0) {
                if (D_8006C51C >= D_80071938[1 + D_8006C6FC]) {
                    D_8006C51C = D_80071938[1 + D_8006C6FC] - 1;
                }
            }
        }
    }
    else if (D_8006C790 == 2) {
        if (D_8006C78C == 0) {
            func_80037768(D_8006C5A8);
            if ((D_8006C5FC != 0) && (D_8006C5C4 == 0)) {
                SpawnMoby(272, D_8006C5A8);
            }
        }
        D_8006C78C += D_8006C648;
        if (D_8006C78C >= 0x18) {
            if (D_8006C5C4 != 0) {
                D_8006C790 = 3;
                D_8006C78C = 0;
                temp_s1 = D_8006C5A8->angle.yaw;
                if ((D_80070328.critterMode == CRITTER_BENTLEY) || (D_80070328.critterMode == CRITTER_BENTLEY_BOXING)) {
                    var_v1 = D_800690F8[D_8006C590].pos.azimuth;
                    var_v0_5 = ((temp_s1 * 0x10 + 0x800 + var_v1) & 0xFFF) >> 4;
                } else {
                    var_v1 = D_80069094[D_8006C590].pos.azimuth;
                    var_v0_5 = ((temp_s1 * 0x10 + 0x800 + var_v1) & 0xFFF) >> 4; // :(
                }
                if (D_8006C590 == 0) {
                    D_8006C590 = 3;
                    var_s0 = 0x600;
                } else {
                    D_8006C590 = 4;
                    var_s0 = 0xA00;
                }
                if (camera.cameraState == 0x12) {
                    camera.unk50 = 1;
                }
                temp_v0_3 = temp_s1 - (func_8003613C(temp_s1, var_v0_5) >> 1);
                sp10.x = (D_80065920[temp_v0_3] * 0x27) >> 7;
                sp10.y = (D_800658A0[temp_v0_3] * 0x27) >> 7;
                sp10.z = 0;
                sp10.z = (D_80070328.position.z - D_8006C5A8->position.z) - 0x40;
                func_8004F194(&camera.unk60, &D_8006C5A8->position, &sp10);
                camera.unk6c = (D_80070328.rotation.yaw + var_s0) & 0xFFF;
                if (D_80070328.critterMode == CRITTER_BENTLEY) {
                    func_800135A4(&camera.unk170, &D_800690F8[D_8006C590], 0);
                }
                else if (D_80070328.critterMode == CRITTER_BENTLEY_BOXING) {
                    D_8006C590 &= 1;
                    if (D_8006C590 == 0) {
                        var_s0 = 0xC00;
                    }
                    else {
                        var_s0 = 0x400;
                    }
                    camera.unk6c = (D_80070328.rotation.yaw + var_s0) & 0xFFF;
                    func_800135A4(&camera.unk170, &D_8006915C[D_8006C590], 0);
                }
                else {
                    func_800135A4(&camera.unk170, &D_80069094[D_8006C590], 0);
                }
                func_800136F0(&camera.unk7c.pos[0], &camera.nextCameraPosCartesian, &camera.unk60);
                func_800138A0(&camera.unk7c.pos[0], &camera.unk7c.pos[0]);
                func_800135A4(&camera.unk7c.pos[2], &camera.unk7c.pos[0], 0);
            } else {
                if (D_8006C5FC != 0) {
                    D_8006C790 = 5;
                    D_8006C78C = 0;
                }
                else {
                    func_800518F8();
                }
            }
        }
    }
    else if (D_8006C790 == 3) {
        D_8006C78C++;
        if (D_8006C78C == 0x1E) {
            D_8006C69C = SpawnMoby(D_8006C5C4, D_8006C5A8);
            if (D_8006C69C != 0) {
                if (D_8006C5C4 == 0x84) {
                    MobyTag_132* tag = D_8006C69C->mobyTag;
                    tag->unk0 = D_8006C66C;
                    tag->unk6 = D_80070328.bodyRotation.yaw;
                    D_8006C69C->size = 0x7F;
                }
                func_8004F178(&D_8006C69C->position, &camera.unk60);
                D_8006C69C->position.z = D_8006C5A8->position.z;
                temp_v0_6 = func_80035D38(D_8006C69C);
                if (temp_v0_6 != 0) {
                    D_8006C69C->position.z = temp_v0_6;
                }
                D_8006C69C->state = 2;
                SpawnParticle(4, 0xC, (Vector3D* ) D_8006C69C, (Vector3D* )3);
            } else {
                D_8006C78C -= 1;
            }
        } else if ((D_8006C69C != 0) && (D_8006C69C->state & 0x80)) {
            func_800518F8();
        }
    }
    else {
        D_8006C78C++;
        if (D_8006C78C == 0x30) {
            func_800518F8();
        }
    }
    D_80070328.unk17a |= 0x10000002;
    if ((game.state == 1) && (D_8006C680 != 0)) {
        func_80047D00(D_8006C5A8);
    }
    if (D_8006C790 != 2) {
        func_80013ACC(D_8006C5A8, 0x12);
    }
    func_80055294(0x7B);
}



#undef D_80070328
/**
 * ???() - func_800527C4()
 * Does something with egg / dragon data, has placeholder struct and one register switch hasn't been fixed yet
 * https://decomp.me/scratch/i3rjG
 */
extern Moby* D_8006C5A8;
extern Moby* D_8006C69C;
extern int D_8006C590;
extern unsigned char D_8006C680;
extern unsigned char* D_8006C7A0;
extern int D_8006C790;
extern int D_8006C78C;
extern int D_8006C7D0;
extern int D_8006C5C4;
void func_800527C4(int arg0, int arg1) {
    game.state = 15;
    D_8006C680 = 1;
    D_8006C790 = 0;
    D_8006C78C = 0;
    D_8006C7D0 = 0;
    D_8006C5C4 = 0;
    D_8006C5A8 = arg0;
    D_8006C69C = arg0;
    {
    register unsigned int flag __asm__("$3") = D_8006C7A0[arg1 * 12 + 11];
    if (flag == 0) {
        __asm__ volatile ("" : "=r"(flag) : "0"(flag));
        D_8006C590 = 0;
    } else {
        D_8006C590 = 1;
    }
    }
}

extern short D_8006C57C;
extern Moby* D_8006C69C;
extern Moby* D_8006C5A8;
extern int D_8006C5FC;
extern int D_8006C590;
extern int D_8006E344;
extern int D_8006C74C;
void func_80052854(void) {
    D_8006C57C = -1;
    D_8006C69C = 0;
    D_8006C5A8 = 0;
    D_8006C5FC = 0;
    D_8006C590 = -1;
    D_8006E344 = 0;
    D_8006C74C = 0;
}

extern void func_80047D00(Moby*);
void func_80055294(int);
void func_8005289C(void) {
    Moby* current = (Moby*)D_8006C5A8;
    D_8006C74C = 1;
    func_80047D00(current);
    func_80013ACC((Moby*)D_8006C5A8, 0x12);
    func_80055294(0x7B);
    if (D_8006C69C != 0 &&
        (*((unsigned char*)D_8006C69C + 0x48) & 0x80) != 0) {
        func_80052854();
    }
}

extern Vector3D D_8006FA2C;
extern Vector3D D_800719BC;
extern unsigned char D_80071570[];
extern int D_8006C5C8, D_8006C75C, D_8006C5C0, D_8006C514;
extern int D_8006C6E0, D_8006C50C, D_8006C4F8, D_8006E49C;
extern int D_8006C5F4, D_8006C768;
/* Retail source: asm/nonmatchings/update/func_80052918.s,
 * 0x80052918..0x80052A84; raw Moby state and global reset fields. */
void func_80052918(int selected, Moby* moby) {
    register int current asm("$19") = selected;
    register Moby* actor asm("$17") = moby;
    register char* tag asm("$18") = (char*)actor->mobyTag;
    register Vector3D* position asm("$16");
    int prior;
    int angleAgain;
    int first;
    int second;
    position = &actor->position;
    func_800282D8();
    func_8004F178(&D_8006FA2C, position);
    func_8004F178(&D_800719BC, position);
    D_8006C5C0 = actor->angle.yaw << 4;
    prior = D_8006C5C8;
    angleAgain = actor->angle.yaw;
    D_8006C75C = prior;
    first = *(int*)(tag + 0x44);
    second = *(int*)(tag + 0x48);
    D_8006C5C8 = current;
    D_8006C514 = 0;
    D_8006C6E0 = angleAgain << 4;
    D_8006C50C = first;
    if (second >= 0) {
        if (D_80071570[second] == 0) D_8006C4F8 = 1;
        else D_8006C4F8 = 2;
    } else if (*(int*)(&D_80070328 + 0x24C)) {
        D_8006C4F8 = 2;
    } else {
        D_8006C4F8 = 0;
    }
    func_8003BEDC();
    D_8006E49C = 1;
    D_8006E344 = 13;
    D_8006C5F4 = 0;
    D_8006C768 = 0;
    *(int*)(&D_80070328 + 0x170) = 0;
    *(int*)(&D_80070328 + 0x178) = 0;
    *(int*)(&D_80070328 + 0x140) = 0;
    *(int*)(&D_80070328 + 0x254) = 0;
}

INCLUDE_ASM("asm/nonmatchings/update", func_80052A84);

INCLUDE_RODATA("asm/nonmatchings/update", D_80010C9C);

INCLUDE_ASM("asm/nonmatchings/update", func_80053374);

/**
 * InitStateFadeIn() - func_80053944() - MATCHING
 * https://decomp.me/scratch/zZDVz
 */
void func_80053944() {
    pauseData.dat_8006fbc8 = 0;
    pauseData.frameCount = 0;
    pauseData.menuType = 0;
    pauseData.dat_8006fbd4 = 0;
    game.state = GAMESTATE_FADE_IN;
    func_8003BEDC();
    streamingData.musicEnabled = 1;
}

/**
 * ???() - func_8005399C() - MATCHING
 * Worth reviewing for the structs etc.
 * https://decomp.me/scratch/MKuo7
 */
void func_8005399C() {
    func_80053944(); // init state fade in
    pauseData.dat_8006fbc8 = 2;
    pauseData.frameCount = 1;
    D_8006C598 = 0xFF;
    D_8006C718 = 1;
    func_8004E790(&savedData, 0, 0x850);
    func_8004E790(&unsavedData, 0, 0x850);
}

INCLUDE_ASM("asm/nonmatchings/update", func_80053A10);

/**
 * GoToLevel() - func_80053F50()
 * It's getting there, mostly register shit now
 * Actually pretty portal focused rather than going to levels in general
 * This is a function that is different in 1.1
 * https://decomp.me/scratch/0zqbG
 */
/* Rev 0 source hypothesis: asm/nonmatchings/update/func_80053F50.s. */
typedef struct {
    Vector3D polygonPoints[5]; // 00 0C 18 24 30
    unsigned int* skybox; // 3c
    char renderDistance; // 40
    char sidedness; // 41 // 0 is one-sided
    char levelId; // 42
    char animationState; // 43
} Portal;
typedef struct {
    int DAT_800722E8; // level ID (to load)?
    Vector3D DAT_800722EC;
    Vector3D DAT_800722F8;
    int DAT_80072304;
    Vector3D DAT_80072308;
    Vector3D DAT_80072314;
    short DAT_80072320;
    short DAT_80072322;
    int DAT_80072324;
    int DAT_80072328;
    int DAT_8007232C;
} Unknown;
extern unsigned char D_80066FCC[72];
extern unsigned char D_80070300[40];
extern ProgressFlags progressFlags;
extern Portal* D_8006C530;
extern Unknown D_800722E8;
extern int D_8006C508, D_8006C5BC, D_8006C73C;
int func_8004F2C8(int,int);
int func_8004F284(short,int);
void func_8004F178(Vector3D*,Vector3D*);
void func_8004F194(Vector3D*,Vector3D*,Vector3D*);
void func_8004F1C8(Vector3D*,Vector3D*,Vector3D*);
int func_8004EDE8(Vector3D*,int);
void func_80053F50(int arg0) {
    Vector3D sp10;
    int temp_a0;
    int homeworldNo;
    int temp_s0_4;
    register int temp_s3 __asm__("$19");
    int temp_s3a;
    unsigned int temp_v1;
    register int var_v0 __asm__("$2");
    Portal* temp_v0;
    int temp_s3b;

    if (arg0 >= 0) {
        temp_v0 = (Portal*)(arg0 * sizeof(Portal) + (int)D_8006C530);
        temp_s3 = func_8004E880(temp_v0->polygonPoints[4].x - temp_v0->polygonPoints[0].x,
                                temp_v0->polygonPoints[4].y - temp_v0->polygonPoints[0].y, 1);
        __asm__ volatile("" : : "r"(temp_s3) : "memory");
        temp_s3a = func_8004E880(spyro.position.x - D_8006C530[arg0].polygonPoints[2].x,
                                 spyro.position.y - D_8006C530[arg0].polygonPoints[2].y, 1);
        temp_s3b = func_8004F2C8(temp_s3, temp_s3a);

        var_v0 = ((temp_s3b < 0) ? temp_s3 - 0x400 : temp_s3 + 0x400);
        temp_s3 = var_v0 & 0xFFF;
        sp10.x = func_8004EA2C(temp_s3) >> 1;
        sp10.y = func_8004E9E4(temp_s3) >> 1;
        sp10.z = -1000;
        func_8004F194(&D_800722E8.DAT_800722EC, &D_8006C530[arg0].polygonPoints[2], &sp10);
        func_8004F178(&D_800722E8.DAT_800722F8, &sp10);
        sp10.x = -sp10.x >> 2;
        sp10.y = -sp10.y >> 2;
        func_8004F178(&D_800722E8.DAT_80072308, &camera.nextCameraPosCartesian);
        func_8004F194(&D_800722E8.DAT_80072314, &D_8006C530[arg0].polygonPoints[2], &sp10);
        D_800722E8.DAT_80072322 = temp_s3;
        D_800722E8.DAT_80072320 = camera.unk48;
        temp_s0_4 = func_8004E880(D_8006C530[arg0].polygonPoints[2].x - camera.nextCameraPosCartesian.x, D_8006C530[arg0].polygonPoints[2].y - camera.nextCameraPosCartesian.y, 1);
        func_8004F1C8(&sp10, &D_800722E8.DAT_80072308, &D_800722E8.DAT_80072314);

        D_800722E8.DAT_80072324 = (func_8004F284(temp_s3, temp_s0_4) * func_8004EDE8(&sp10, 0)) >> 0xB;
        if (D_800722E8.DAT_80072324 < 400) {
            D_800722E8.DAT_80072324 = 0;
        }

        D_800722E8.DAT_800722E8 = arg0;
        D_8006C7C8 = (!D_8006C508) ? levelIndexToHomeworldLevelId[levelIndex] : D_8006C530[arg0].levelId;
        pauseData.menuType = 0;
    } else {
        D_8006C7C8 = levelIndexToHomeworldLevelId[levelIndex];
        pauseData.menuType = 1;
    }
    homeworldNo = D_8006C7C8 / 10;

    if (D_8006C7C8 == (homeworldNo * 0xA)) {
        temp_v1 = D_8006C5BC % 10;
        if ((temp_v1 - 1 < 6) && (temp_v1 != 5)) {
            if ((D_8006C5BC < 60)
                && ((&progressFlags.lvl67_AMonsterToEndAllMonsters)[homeworldNo] == 0)) {

                temp_a0  = D_80070300[D_80066FCC[D_8006C7C8 + 1]] & 1;
				temp_a0 += D_80070300[D_80066FCC[D_8006C7C8 + 2]] & 1;
				temp_a0 += D_80070300[D_80066FCC[D_8006C7C8 + 3]] & 1;
				temp_a0 += D_80070300[D_80066FCC[D_8006C7C8 + 4]] & 1;
				temp_a0 += D_80070300[D_80066FCC[D_8006C7C8 + 6]] & 1;

                switch (D_8006C7C8) {
                case 10:
                    if (temp_a0 >= 2) {
                        progressFlags.lvl62_TheSecondWarning = 1;
                        func_800584BC(6, 62);
                        return;
                    }
                    break;
                case 20:
                    if (temp_a0 >= 2) {
                        progressFlags.lvl64_HuntersTussle = 1;
                        func_800584BC(6, 64);
                        return;
                    }
                    break;
                case 30:
                    if (temp_a0 >= 4) {
                        progressFlags.lvl66_AnApologyAndLunch = 1;
                        func_800584BC(6, 66);
                        return;
                    }
                    break;
                }
            }
        }
    }
    D_800722E8.DAT_8007232C = 0;
    pauseData.dat_8006fbc8 = 0;
    pauseData.frameCount = 0;
    loadStage = 0;
    game.state = GAMESTATE_LOADING_GLIDE;
    func_8003BEDC();
    streamingData.musicEnabled = 1;
    D_8006C73C = D_8006C5BC;
}





INCLUDE_ASM("asm/nonmatchings/update", func_80054450);

/**
 * InitGameOver() - func_80054AF8() - MATCHING
 * https://decomp.me/scratch/G5jiI
 */
void func_80054AF8() {
    game.state = GAMESTATE_GAME_OVER;
    pauseData.dat_8006fbc8 = 0;
    D_8006C598 = 0;
    D_8006C7C8 = levelIndexToHomeworldLevelId[levelIndex];
    loadStage = 0;
    func_8003BEDC();
    streamingData.musicEnabled = 1;
}

/* Retail source: asm/nonmatchings/update/func_80054B64.s,
 * 0x80054B64..0x80054CD8; one state update per call. */
extern int D_8006FBC8, D_8006FBC4, D_8006C518;
extern int D_8006C784, D_8006C5BC, D_8006C60C, D_8006C58C;
void func_8002CA50(void);
void func_8001FB10(int);
void func_title_80074DEC(int);
void func_loading_80076FEC(void);
void func_80054E5C(void);
void func_80054B64(void) {
    int state = D_8006FBC8;
    if (state >= 3) goto check_state_three;
    if (state > 0) goto loading;
    if (state == 0) goto state_zero;
    return;
check_state_three:
    if (state == 3) goto check_three;
    return;
state_zero:
    if (D_8006C518 < 2) func_8002CA50();
    D_8006C598 += 16;
    if (D_8006C598 < 256) return;
    func_8001EBAC();
    func_8001FB10(0x1C000);
    goto check_wait;
wait:
    func_8002CA50();
check_wait:
    if (D_8006C518 < 2) goto wait;
    if (D_8006C784 >= 0) {
        func_title_80074DEC(0);
        func_80054E5C();
        return;
    }
    D_8006FBC8 = 1;
    D_8006FBC4 = 0;
    D_8006C718 = 1;
    D_8006C5BC = D_8006C7C8;
    D_8006C60C = D_8006C58C;
    return;
loading:
    func_loading_80076FEC();
    return;
wait_three:
    func_8002CA50();
check_three:
    if (D_8006C518 >= 0) goto wait_three;
    func_8005399C();
}

/**
 * ???() - func_80054CD8() - MATCHING
 * Worth reviewing for the structs etc.
 * https://decomp.me/scratch/kCgmm
 */
extern char* D_80011254;
extern short D_8006C510;
extern short D_8006C540;
extern int D_8006C56C;
extern short D_8006C6A8;
extern int D_8006C6AC;
extern short D_8006C740;
extern short D_8006C744;
extern short D_8006C780;
extern int D_8006C7F0;
extern int D_8006DE88;
extern int D_8006DE8C;
extern int D_8006E470;
extern int D_8006E49C;
void func_80054CD8(void) {
    D_8006E344 = 0xA;
    D_8006C744 = 0;
    D_8006C740 = 0;
    D_8006C540 = 0;
    D_8006C510 = -1;
    D_8006C6AC = 0;
    D_8006C7F0 = 0;
    D_8006C780 = 0;
    D_8006C6A8 = 0;
    D_8006C56C = 0;
    CDLoadSync(D_8006E470, D_80011254, D_8006DE8C, D_8006DE88);
    func_8003BEDC();
    D_8006E49C = 1;
}

extern void func_credits_80074BA0(void);
extern void func_8002CA50(void);
void func_80054D84(void) {
    switch (D_8006C510) {
    case 0x63:
        {
        register int level __asm__("$5") = D_8006C67C;
        loadStage = 1;
        if (level > 0) {
            func_800584BC(0, level);
            D_8006C67C = -1;
        } else {
            func_800584BC(0, 0x28);
        }
        D_8006C780 = 0;
        D_8006C510 = (unsigned short)D_8006C510 + 1;
        }
        break;
    case 0x64:
        D_8006C780 = (unsigned short)D_8006C780 + deltaTime;
        func_8002CA50();
        break;
    default:
        func_credits_80074BA0();
        break;
    }
}

extern int D_8006C658;
extern int D_8006C7E4;
extern int D_8006C678;
extern int D_8006C64C;
extern int D_80065834;
extern char D_80070328;
extern char D_8006FBA8;
extern char D_8007179C;
extern char D_8006DFF8;
extern char D_8006D088;
extern char D_8006C7F8;
extern char g_CheatFlags;
extern void ActivateSparxPowers(void);
extern int func_8004F6A0(void);
extern void srand(int);
void func_80054E5C(void) {
    unsigned char cheat;
    D_8006E344 = 11;
    D_8006C658 = 0;
    D_8006C7E4 = 0;
    D_8006C678 = 0;
    D_8006C74C = 0;
    D_8006C64C = 0;
    func_8001FB10(0x1C000);
    func_8004E790(&D_80070328, 0, 0x2E8);
    func_8004E790(&D_8006FBA8, 0, 0x1C);
    func_8004E790(&D_8007179C, 0, 0x130);
    func_8004E790(&D_8006DFF8, 0, 0x1FC);
    *(int*)(&D_80070328 + 0x28C) = -1;
    *(int*)(&D_80070328 + 0x294) = -1;
    *(int*)(&D_80070328 + 0x280) = D_80065834;
    func_8004E790(&D_8006D088, 0, 0x850);
    func_8004E790(&D_8006C7F8, 0, 0x850);
    cheat = (&g_CheatFlags)[3];
    func_8004E790(&g_CheatFlags, 0, 0x18);
    (&g_CheatFlags)[3] = cheat;
    ActivateSparxPowers();
    srand(func_8004F6A0());
}

/**
 * ???() - func_80054F94() - MATCHING
 * Worth reviewing for the structs etc.
 * https://decomp.me/scratch/haRsG
 */
extern int D_8007232C;
extern int D_8006FBC8;
extern int D_8006FBC4;
extern int D_8006FBD0;
extern int D_8006C528;
extern int D_8006E49C;
extern int D_8006C73C;
extern int D_8006C5BC;
void func_80054F94(int arg0, Moby* arg1) {
    D_8007232C = 0;
    D_8006FBC8 = 0;
    D_8006FBC4 = 0;
    D_8006FBD0 = 1;
    loadStage = 0;
    D_8006E344 = 0xC;
    D_8006C7C8 = arg0;
    D_8006C528 = (int)arg1->mobyClass;
    func_8003BEDC();
    D_8006E49C = 1;
    D_8006C73C = D_8006C5BC;
}

/**
 * Loading-state updater - func_80055020() - MATCHING
 * Rev 0 target: asm/nonmatchings/update/func_80055020.s,
 * 0x80055020..0x80055294 (157 instruction words).
 * The 0x15000 buffer increment reads D_8006FC6C and writes D_8006FCE0.
 * https://decomp.me/scratch/bm0hn supplied the initial C candidate.
 */
extern int D_8006C508, D_8006C7DC, D_8006FC6C, D_8006FCE0;
extern char D_80070328, D_8006D088, D_8006C7F8;
extern Vector3D D_800722F8;
extern void func_80044240(void);
extern int func_80048444(Vector3D*);
extern void func_8004BEF8(int);
extern void func_loading_80078678(void);

void func_80055020(void) {
    int temp_v0;

    switch (pauseData.dat_8006fbc8) {
    case 0:
        if (((loadStage > 0) || (func_8002CA50(), (loadStage > 0))) && (CDLoadTime() == 0)) {
            func_8001FB10(0x1C000);
            D_8006C7DC = 0x15000;
            pauseData.dat_8006fbc8 = 1;
            pauseData.frameCount = 0;
            D_8006FCE0 = D_8006FC6C + 0x15000;
        }
        return;
    case 1:
    case 2:
    case 3:
    case 4:
        func_loading_80078678();
        break;
    case 5:
        if (pauseData.frameCount == 0) {
            if (loadStage >= 0) {
                do {
                    func_8002CA50();
                } while (loadStage >= 0);
            }
            func_8004E790(&D_8006D088, 0, 0x850);
            func_8004E790(&D_8006C7F8, 0, 0x850);
            func_8005399C();
        }
        if (game.state == GAMESTATE_LOADING_GLIDE) {
            pauseData.frameCount++;
            if (pauseData.frameCount < 9) {
                D_8006C598 = (8 - pauseData.frameCount) << 5;
            }
            if (D_8006C508 != 0) {
                func_80044240();
                if (pauseData.frameCount >= 0xA) {
                    temp_v0 = func_80048444(&D_800722F8);
                    (&D_80070328)[0xC] = 0;
                    (&D_80070328)[0xD] = 0;
                    func_8001204C();
                    if (!temp_v0) {
                        func_8004BEF8(0);
                        game.state = GAMESTATE_FADE_IN;
                        pauseData.dat_8006fbc8 = 4;
                        pauseData.frameCount = 0;
                        pauseData.menuType = 0;
                        D_8006C598 = 0;
                        D_8006C718 = 1;
                    }
                }
                (&D_80070328)[0x1E] = 0x20;
            }
        }
        return;
    }
}

/**
 * UpdateUsingFlags() - func_80055294() - MATCHING
 * https://decomp.me/scratch/JW1UB
 */
void func_80055294(int flags) {

    if (flags & UPDATE_ENV) {
        func_80020E74(deltaTime);
        func_80021FF4();
        func_80022158();
        func_80022260();
    }
    if (flags & UPDATE_MOBYS) {
        func_8003038C();
    }
    if (flags & UPDATE_SPYRO) {
        func_8003E83C();
    }
    if (flags & UPDATE_PARTS) {
        if (UpdateParticles != 0) {
            (*UpdateParticles)(deltaTime);
        }
        func_800509F0();
    }
    if (flags & UPDATE_CAMERA) {
        func_8001204C();
    }
    func_800285A4(flags & UPDATE_HUD);
}

/**
 * InitBulletTime() - func_80055364() - MATCHING
 * https://decomp.me/scratch/kHnWT
 */
void func_80055364(Moby* moby) {
    game.state = GAMESTATE_BULLET_TIME;
    D_8006C5F8 = moby;
}

/**
 * ExitBulletTime() - func_80055380() - MATCHING
 * https://decomp.me/scratch/TqcH3
 */
void func_80055380(void) {
    game.state = GAMESTATE_GAMEPLAY;
    D_8006C5F8 = 0;
}

/**
 * UpdateBulletTime() - func_80055398() - MATCHING
 * https://decomp.me/scratch/BtdFp
 */
void func_80055398(void) {
    void (*mobyUpdate)(Moby*);
    void (**mobyUpdateFuncs)(Moby*) = ovlHeader.MobyUpdate;

    if (mobyUpdateFuncs != 0) {
        mobyUpdate = mobyUpdateFuncs[D_8006C5F8->mobyClass];
        if (mobyUpdate != 0) {
            mobyUpdate(D_8006C5F8);
        }
    }
    func_8001204C();
    func_800285A4(0);
}

/**
 * Update() - func_80055400() - MATCHING
 * Retail Rev 0: asm/nonmatchings/update/Update.s,
 * 0x80055400..0x800555C0 plus 20-entry jump table at 0x80011204.
 * Dispatch runs once per call. Exact C source hypothesis:
 * https://decomp.me/scratch/X6Lxc
 */


/* externed functions, only to be used as notes
void func_80050F18(); // gameplay updates
void func_80051A60(); // speech updates
void func_8005289C(); // egg collect updates
void func_80053374(); // sublevel loading updates
void func_80053A10(); // fade-in updates
void func_80054450(); // loading glide updates
void func_80054B64(); // game over updates
void func_80054CD8(); // init credits cheat updates
void func_80054D84(); // credits updates
void func_80055020(); // loading vehicle updates
void func_80055294(enum UpdateFlags updateFlags); // update with flags
void func_80055398(); // bullet time updates
*/

void Update(void) {
    enum UpdateFlags var_a0;

    D_8006C718 = 0;
    func_8003A584();
    func_8004FA24();
    switch (game.state) {
    case GAMESTATE_GAMEPLAY:
    case GAMESTATE_UNK_0E:
        func_80050F18();
        break;
    case GAMESTATE_SPEECH:
        func_80051A60();
        break;
    case GAMESTATE_EGG_COLLECT:
        func_8005289C();
        break;
    case GAMESTATE_SPEEDWAY_MENU:
        var_a0 = 0x10;
        if (camera.unk50 == 2) { // unsigned in some places? maybe causing matching issues
            (*ovlHeader.UpdateSpeedwayMenu)(var_a0); // 0x10 // UpdateSpeedwayMenu
            var_a0 = 0x11;
        }
        func_80055294(var_a0);
        break;
    case GAMESTATE_FADE_IN:
        func_80053A10();
        break;
    case GAMESTATE_PAUSE:
        func_80057834();
        break;
    case GAMESTATE_LOADING_IMG:
        func_80058778();
        break;
    case GAMESTATE_CUTSCENE:
        (*ovlHeader.UpdateCutscene)(); // UpdateCutscene
        break;
    case GAMESTATE_LOADING_GLIDE:
        func_80054450();
        break;
    case GAMESTATE_GAME_OVER:
        func_80054B64();
        break;
    case GAMESTATE_CREDITS:
        func_80054D84();
        break;
    case GAMESTATE_INIT_CREDITS_CHEAT:
        func_80054CD8();
        D_8006C67C = -1;
        break;
    case GAMESTATE_TITLE_SCREEN:
        func_title_8007566C();
        break;
    case GAMESTATE_LOADING_VEHICLE:
        func_80055020();
        break;
    case GAMESTATE_LOADING_SUBLEVEL:
        func_80053374();
        break;
    case GAMESTATE_BULLET_TIME:
        func_80055398();
        break;
    case GAMESTATE_SKATEBOARD_MENU:
        (*ovlHeader.UpdateSkateMenu)(); // UpdateSkateMenu
        var_a0 = 0x3B;
        func_80055294(var_a0);
        break;
    }
    func_8003C184();
}
