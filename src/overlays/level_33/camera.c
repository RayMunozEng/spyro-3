#include "matching.h"
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

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0; originalfunc_level_33_8009DE6C.
* Assembly SHA256 5ccccf359bcf3e1f18fba891b40682c4967803cac8f578fccfb38bae49bd7731.
* AI-generated; not human reviewed. Original numeric and address roles only:
* raw32 input masks, signed integer sums/shifts, literal clamps and byte-domain
* table addressing are preserved. Physical units/fixed point, complete helper
* meanings and per-frame caller cadence remain unresolved.
* Original branch306 skips the input-word reload after the first
* override store. The no-override route retains the already loaded word; the
* override route stores first and then reloads, with a zero-instruction memory
* boundary preserving that observed order. Both paths retain original targets.
* Original branch387 uses LI4096 in its delay slot. Paired .set modes
* are zero-CPU assembler metadata; C generates the predicate, constant/store.
* The same original frame, scratch fields, signed table loads, low-product
* producers, wrap/clamp arithmetic and per-level joins remain unchanged.
* No incoming HI/LO state is invented. Empty constraints consume initialized
* original values or mark dead replacements. Do not remove producer captures,
* pad fields or unused original frame storage as cosmetic cleanup.
* Falsification: every native/linked instruction and owned table word, all
* conditional/internal targets, preserved data and EXE/every-overlay hashes.
* Compiler/assembler pipeline, flags and acceptance requirements are unchanged.
* Binary identity does not establish synchronized runtime/system completion. */
#define Camera33_9DE6C_Zero()                     \
    ({                                            \
        register int z0 __asm__("$0");            \
        __asm__ volatile("" : "=r"(z0) : "i"(0)); \
        z0;                                       \
    })
#include "spyro.h"
/* AI generated; not human reviewed. Original-instruction-derived C. Original source asm/nonmatchings/overlays/level_33/camera/func_level_33_8009DE6C.s SHA256 5ccccf359bcf3e1f18fba891b40682c4967803cac8f578fccfb38bae49bd7731. No semantic or runtime parity claim. Exact native/linked/full retail hashes required. */
#define Camera33_9DE6C_Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern CameraPosition Camera33_9DE6C_D_80069260 __asm__("D_80069260");
extern CameraPosition Camera33_9DE6C_D_8006929C[5] __asm__("D_8006929C");
extern CameraPosition Camera33_9DE6C_D_80069328[5] __asm__("D_80069328");
extern CameraPosition Camera33_9DE6C_D_800693B4 __asm__("D_800693B4");
extern CameraPosition Camera33_9DE6C_D_800693C8 __asm__("D_800693C8");
extern int Camera33_9DE6C_D_8006C5BC __asm__("D_8006C5BC");
extern Spyro Camera33_9DE6C_D_80070328 __asm__("D_80070328");
void Camera33_9DE6CCopyCameraPositionWithWrappedAngle(CameraPosition*, CameraPosition*,
                                                      int) __asm__("func_800135A4");
int Camera33_9DE6CBuildCameraVectorOrientation(CameraPosition*, Vector3D*,
                                               Vector3D*) __asm__("func_800136F0");
void Camera33_9DE6CSelectSignedCameraOrbitRequest(int) __asm__("func_80013918");
void Camera33_9DE6CUpdateCameraOrbitReturn() __asm__("func_800139A4");
void Camera33_9DE6CRefreshCameraPlayerAnchor() __asm__("func_800142E0");
void Camera33_9DE6CSelectCameraFollowProfile() __asm__("func_80014354");
int Camera33_9DE6CSubAngle12(int arg0, int arg1) __asm__("func_8003615C");
extern void Camera33_9DE6CCopyVector(Vector3D*, Vector3D*) __asm__("func_8004F178");
unsigned char Camera33_9DE6CUpdateSmoothedInputPair() __asm__("func_800410F8");
/* extern */
extern CameraPosition Camera33_9DE6C_D_80069314 __asm__("D_80069314");
extern CameraPosition Camera33_9DE6C_D_800693A0 __asm__("D_800693A0");
extern short Camera33_9DE6C_D_8006E040 __asm__("D_8006E040");
extern int Camera33_9DE6C_D_8006E044 __asm__("D_8006E044");
extern int Camera33_9DE6C_D_8006E050 __asm__("D_8006E050");
extern unsigned char Camera33_9DE6C_D_8006E064 __asm__("D_8006E064");
extern int Camera33_9DE6C_D_8006E078 __asm__("D_8006E078");
extern int Camera33_9DE6C_D_8006E08C __asm__("D_8006E08C");
extern int Camera33_9DE6C_D_8006E094 __asm__("D_8006E094");
extern int Camera33_9DE6C_D_8006E098 __asm__("D_8006E098");
extern int Camera33_9DE6C_D_8006E09C __asm__("D_8006E09C");
extern CameraPosition Camera33_9DE6C_D_8006E0D8 __asm__("D_8006E0D8");
extern int Camera33_9DE6C_D_8006E0DC __asm__("D_8006E0DC");
extern int Camera33_9DE6C_D_8006E0E8 __asm__("D_8006E0E8");
extern int Camera33_9DE6C_D_8006E114 __asm__("D_8006E114");
extern int Camera33_9DE6C_D_8006E118 __asm__("D_8006E118");
extern int Camera33_9DE6C_D_8006E11C __asm__("D_8006E11C");
extern int Camera33_9DE6C_D_8006E120 __asm__("D_8006E120");
extern int Camera33_9DE6C_D_8006E124 __asm__("D_8006E124");
extern CameraPosition Camera33_9DE6C_D_8006E12C __asm__("D_8006E12C");
extern int Camera33_9DE6C_D_8006E130 __asm__("D_8006E130");
extern int Camera33_9DE6C_D_8006E140 __asm__("D_8006E140");
extern int Camera33_9DE6C_D_8006E144 __asm__("D_8006E144");
extern unsigned char Camera33_9DE6C_D_8006E154 __asm__("D_8006E154");
extern unsigned char Camera33_9DE6C_D_8006E160 __asm__("D_8006E160");
extern int Camera33_9DE6C_D_8006E1D0 __asm__("D_8006E1D0");
extern Vector3D Camera33_9DE6C_D_8006E1E0 __asm__("D_8006E1E0");
extern int Camera33_9DE6C_D_8006E1E8 __asm__("D_8006E1E8");
extern short Camera33_9DE6C_D_8006E1EC __asm__("D_8006E1EC");
extern short Camera33_9DE6C_D_8006E1EE __asm__("D_8006E1EE");
extern short Camera33_9DE6C_D_8006E1F0 __asm__("D_8006E1F0");
extern unsigned char Camera33_9DE6C_D_8006E536 __asm__("D_8006E536");
extern int Camera33_9DE6C_D_8006E538 __asm__("D_8006E538");
extern unsigned char Camera33_9DE6C_D_8006E546 __asm__("D_8006E546");
extern unsigned char Camera33_9DE6C_D_8006E547 __asm__("D_8006E547");
extern unsigned char Camera33_9DE6C_D_80071A04 __asm__("D_80071A04");
void func_level_33_8009DE6C(void) {
    struct {
        int sp10;
        int sp14;
    } originalFrame;
    register unsigned char* base17 __asm__("$17");
    register int word2 __asm__("$2");
    register int word3 __asm__("$3");
    register int* address4 __asm__("$4");
    register int product7 __asm__("$7");
    int rawLow;
    CameraPosition* temp_a0_4;
    Vector3D* var_s3;
    int temp_a0;
    int temp_a0_2;
    int temp_a0_3;
    int temp_a0_5;
    int temp_a1;
    register int temp_v0 __asm__("$2");
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v1;
    int temp_v1_2;
    int temp_v1_3;
    int temp_v1_4;
    register int temp_v1_5 __asm__("$3");
    int temp_v1_6;
    int temp_v1_7;
    register int var_a1 __asm__("$5");
    int var_s2;
    register int var_v0 __asm__("$2");
    register int var_v0_2 __asm__("$2");
    register int var_v0_3 __asm__("$2");
    register int var_v0_4 __asm__("$2");
    register int var_v0_5 __asm__("$2");
    int var_v0_6;
    register int var_v0_7 __asm__("$2");
    register int var_v1 __asm__("$3");
    int var_v1_2;
    register int var_v1_3 __asm__("$3");
    void* temp_s0;
    var_s2 = (int)(Camera33_9DE6C_D_8006E130 + 2) >> 2;
    if (var_s2 >= 5) {
        var_s2 = 4;
    }
    switch (Camera33_9DE6C_D_8006E044) {
        case 3:
            if (Camera33_9DE6C_D_8006E12C.pos.azimuth == 0) {
                Camera33_9DE6CSelectCameraFollowProfile();
                temp_v0 = -Camera33_9DE6C_D_80070328.rotation.pitch;
                var_v1 = (int)(temp_v0 - Camera33_9DE6C_D_8006E078) >> 2;
                Camera33_9DE6C_D_8006E08C = temp_v0;
                if (var_v1 >= 0xC1) {
                    var_v1 = Camera33_9DE6C_Zero() + 0xC0;
                }
                var_v0 = var_v1 < -0xC0;
                MATCHING_KEEP(var_v0);
                if (var_v0 != 0) {
                    var_v1 = -0xC0;
                }
                var_v0_2 = var_v1 + Camera33_9DE6C_Zero();
                if (var_v1 < 0) {
                    var_v0_2 = -var_v0_2;
                }
                if (var_v0_2 >= 9) {
                    Camera33_9DE6C_D_8006E094 = var_v1;
                } else {
                    Camera33_9DE6C_D_8006E094 = 0;
                }
                if ((Camera33_9DE6C_D_80070328.movementState != MOVEMENT_STATE_SUPERFLY) ||
                    (Camera33_9DE6C_D_80070328.union144.b.unk148 <= 0)) {
                    Camera33_9DE6C_D_8006E098 = (int)-Camera33_9DE6C_D_80070328.rotation.roll >> 2;
                }
                Camera33_9DE6CSelectSignedCameraOrbitRequest(0xC0);
                Camera33_9DE6CUpdateCameraOrbitReturn();
            }
            Camera33_9DE6CRefreshCameraPlayerAnchor();
            Camera33_9DE6CCopyCameraPositionWithWrappedAngle(&Camera33_9DE6C_D_8006E0D8,
                                                             &Camera33_9DE6C_D_8006929C[var_s2], 0);
            if (Camera33_9DE6C_D_8006E0D8.pos.azimuth < 0x100) {
                Camera33_9DE6C_D_8006E0D8.pos.azimuth = 0x100;
            }
            if (Camera33_9DE6C_D_8006E0DC < 0x60) {
                Camera33_9DE6C_D_8006E0DC = 0x60;
            }
            if (Camera33_9DE6C_D_8006E0E8 < 0x40) {
                Camera33_9DE6C_D_8006E0E8 = 0x40;
            }
            Camera33_9DE6CCopyCameraPositionWithWrappedAngle(
                (CameraPosition*)((unsigned char*)&Camera33_9DE6C_D_8006E0D8 + 0x14),
                &Camera33_9DE6C_D_80069328[var_s2], 0);
            Camera33_9DE6CCopyCameraPositionWithWrappedAngle(
                (CameraPosition*)((unsigned char*)&Camera33_9DE6C_D_8006E0D8 + 0x28),
                &Camera33_9DE6C_D_800693C8, 0);
            Camera33_9DE6CCopyCameraPositionWithWrappedAngle(
                (CameraPosition*)((unsigned char*)&Camera33_9DE6C_D_8006E0D8 + 0x3C),
                &Camera33_9DE6C_D_800693B4, 0);
            if (Camera33_9DE6C_D_80070328.movementState == MOVEMENT_STATE_SUPERFLY) {
                Camera33_9DE6C_D_8006E1D0 = -Camera33_9DE6C_D_80070328.union144.a.unk13ce.x;
                return;
            }
        default:
            return;
        case 17:
            base17 = &Camera33_9DE6C_D_8006E160;
            if (Camera33_9DE6C_Field(base17, int*, 0) == Camera33_9DE6C_D_8006E044) {
                var_s3 = base17 - 0x108;
                if (Camera33_9DE6C_D_8006E12C.pos.azimuth == 0) {
                    Camera33_9DE6CCopyCameraPositionWithWrappedAngle(
                        base17 - 0xD8, base17 + 8,
                        Camera33_9DE6C_Field(&Camera33_9DE6C_D_8006E064, int*, 0));
                    __asm__ volatile("" : "=r"(base17) : "0"(base17) : "$16", "$19");
                    var_s3 = base17 - 0x108;
                }
                Camera33_9DE6CCopyVector(var_s3, base17 + 0x1C);
                Camera33_9DE6C_Field(&Camera33_9DE6C_D_8006E064, int*, 0) = 0;
                Camera33_9DE6CCopyCameraPositionWithWrappedAngle(
                    base17 - 0x88, &Camera33_9DE6C_D_8006929C[var_s2], 0);
                Camera33_9DE6CCopyCameraPositionWithWrappedAngle(
                    base17 - 0x74, &Camera33_9DE6C_D_80069328[var_s2], 0);
                Camera33_9DE6CCopyCameraPositionWithWrappedAngle(base17 - 0x4C,
                                                                 &Camera33_9DE6C_D_800693B4, 0);
                Camera33_9DE6CCopyCameraPositionWithWrappedAngle(base17 - 0x60,
                                                                 &Camera33_9DE6C_D_800693C8, 0);
                if (!(Camera33_9DE6C_D_8006E050 & 2)) {
                    Camera33_9DE6CBuildCameraVectorOrientation(base17 - 0xEC, base17 - 0x140,
                                                               var_s3);
                    Camera33_9DE6C_D_8006E09C = Camera33_9DE6C_Field(base17, int*, -0xEC);
                    return;
                }
            }
            break;
        case 23:
            if (Camera33_9DE6C_D_8006E12C.pos.azimuth == 0) {
                if (Camera33_9DE6C_D_80070328.unk13e[1] & 0x80) {
                    Camera33_9DE6CCopyCameraPositionWithWrappedAngle(
                        (CameraPosition*)((unsigned char*)&Camera33_9DE6C_D_8006E12C - 0xA4),
                        &Camera33_9DE6C_D_80069260,
                        Camera33_9DE6C_Field(&Camera33_9DE6C_D_8006E064, int*, 0));
                } else {
                    Camera33_9DE6CSelectCameraFollowProfile(&Camera33_9DE6C_D_8006E12C);
                    Camera33_9DE6CSelectSignedCameraOrbitRequest(0x400);
                }
            }
            Camera33_9DE6CRefreshCameraPlayerAnchor();
            Camera33_9DE6C_Field(&Camera33_9DE6C_D_8006E064, int*, 0) =
                (int)(Camera33_9DE6C_D_80070328.m_WhirlwindPointer->angle.yaw * 0x10);
            Camera33_9DE6CCopyCameraPositionWithWrappedAngle(&Camera33_9DE6C_D_8006E064 + 0x74,
                                                             &Camera33_9DE6C_D_8006929C[var_s2], 0);
            Camera33_9DE6CCopyCameraPositionWithWrappedAngle(&Camera33_9DE6C_D_8006E064 + 0x88,
                                                             &Camera33_9DE6C_D_80069328[var_s2], 0);
            Camera33_9DE6CCopyCameraPositionWithWrappedAngle(&Camera33_9DE6C_D_8006E064 + 0x9C,
                                                             &Camera33_9DE6C_D_800693C8, 0);
            Camera33_9DE6CCopyCameraPositionWithWrappedAngle(&Camera33_9DE6C_D_8006E064 + 0xB0,
                                                             &Camera33_9DE6C_D_800693B4, 0);
            if (!(Camera33_9DE6C_D_8006E050 & 2)) {
                Camera33_9DE6CBuildCameraVectorOrientation(&Camera33_9DE6C_D_8006E064 + 0x10,
                                                           &Camera33_9DE6C_D_8006E064 - 0x44,
                                                           &Camera33_9DE6C_D_8006E064 - 0xC);
                Camera33_9DE6C_D_8006E09C =
                    Camera33_9DE6C_Field(&Camera33_9DE6C_D_8006E064, int*, 0x10);
                return;
            }
            break;
        case 31:
            temp_s0 = Camera33_9DE6C_D_80070328.critterMobyPtr->mobyTag;
            originalFrame.sp10 = 0;
            originalFrame.sp14 = 0;
            if (Camera33_9DE6C_D_8006E536 != 0) {
                originalFrame.sp10 = Camera33_9DE6C_D_8006E546 - 0x7F;
                originalFrame.sp14 = 0x7F - Camera33_9DE6C_D_8006E547;
            }
            word3 = Camera33_9DE6C_D_8006E538;
            MATCHING_KEEP(word3);
            word2 = word3 & 8192;
            MATCHING_KEEP(word2);
            if (word2)
                goto positive_sp10;
            word2 = word3 & 32768;
            MATCHING_KEEP(word2);
            if (!word2)
                goto after_sp10;
            word2 = -0x7F;
            goto store_sp10;
        positive_sp10:
            word2 = 0x7F;
        store_sp10:
            originalFrame.sp10 = word2;
            MATCHING_BARRIER_VOLATILE("memory");
            word3 = Camera33_9DE6C_D_8006E538;
            MATCHING_KEEP(word3);
        after_sp10:;
            word2 = word3 & 4096;
            MATCHING_KEEP(word2);
            if (word2)
                goto positive_sp14;
            word2 = word3 & 16384;
            MATCHING_KEEP(word2);
            if (!word2)
                goto after_sp14;
            word2 = -0x7F;
            goto store_sp14;
        positive_sp14:
            word2 = 0x7F;
        store_sp14:
            originalFrame.sp14 = word2;
        after_sp14:;
            temp_v1 = Camera33_9DE6C_Field(temp_s0, int*, 0x50) + originalFrame.sp10;
            Camera33_9DE6C_Field(temp_s0, int*, 0x50) = temp_v1;
            if (originalFrame.sp10 > 0) {
                if (temp_v1 < 0) {
                    Camera33_9DE6C_Field(temp_s0, int*, 0x50) = 0;
                }
                if (originalFrame.sp10 >= 0x7F) {
                    if (Camera33_9DE6C_Field(temp_s0, int*, 0x50) >= 0x1001) {
                        Camera33_9DE6C_Field(temp_s0, int*, 0x50) = 0x1000;
                    }
                } else {
                    temp_v1_2 = originalFrame.sp10 * 0x10;
                    if (temp_v1_2 < Camera33_9DE6C_Field(temp_s0, int*, 0x50)) {
                        Camera33_9DE6C_Field(temp_s0, int*, 0x50) = temp_v1_2;
                    }
                }
            } else {
                if (originalFrame.sp10 < -0x7E) {
                    if (temp_v1 < -0x1000) {
                        Camera33_9DE6C_Field(temp_s0, int*, 0x50) = -0x1000;
                    }
                } else {
                    temp_a0 = originalFrame.sp10 * 0x10;
                    if (temp_v1 < temp_a0) {
                        Camera33_9DE6C_Field(temp_s0, int*, 0x50) = temp_a0;
                    }
                }
                if (Camera33_9DE6C_Field(temp_s0, int*, 0x50) > 0) {
                    Camera33_9DE6C_Field(temp_s0, int*, 0x50) = 0;
                }
            }
            temp_v1_3 = Camera33_9DE6C_Field(temp_s0, int*, 0x54) + originalFrame.sp14;
            Camera33_9DE6C_Field(temp_s0, int*, 0x54) = temp_v1_3;
            if (originalFrame.sp14 > 0) {
                if (temp_v1_3 < 0) {
                    Camera33_9DE6C_Field(temp_s0, int*, 0x54) = 0;
                }
                if (originalFrame.sp14 >= 0x7F) {
                    /* Original branch387/delay388 is BNE/LI4096.
                * Mode directives emit zero CPU instructions; C emits the
                * predicate, constant and store. Original targets/hashes required. */
                    word2 = Camera33_9DE6C_Field(temp_s0, int*, 0x54) < 0x1001;
                    __asm__ volatile(".set\tnoreorder" : : "r"(word2));
                    if (!word2) {
                        word2 = 0x1000;
                        __asm__ volatile(".set\treorder" : "=r"(word2) : "0"(word2));
                        Camera33_9DE6C_Field(temp_s0, int*, 0x54) = word2;
                    }
                } else {
                    temp_v1_4 = originalFrame.sp14 * 0x10;
                    if (temp_v1_4 < Camera33_9DE6C_Field(temp_s0, int*, 0x54)) {
                        Camera33_9DE6C_Field(temp_s0, int*, 0x54) = temp_v1_4;
                    }
                }
            } else {
                if (originalFrame.sp14 < -0x7E) {
                    if (temp_v1_3 < -0x1000) {
                        Camera33_9DE6C_Field(temp_s0, int*, 0x54) = -0x1000;
                    }
                } else {
                    temp_a0_2 = originalFrame.sp14 * 0x10;
                    if (temp_v1_3 < temp_a0_2) {
                        Camera33_9DE6C_Field(temp_s0, int*, 0x54) = temp_a0_2;
                    }
                }
                if (Camera33_9DE6C_Field(temp_s0, int*, 0x54) > 0) {
                    Camera33_9DE6C_Field(temp_s0, int*, 0x54) = 0;
                }
            }
            word3 = Camera33_9DE6C_Field(temp_s0, int*, 0x58);
            MATCHING_KEEP(word3);
            word2 = 0x555;
            word2 -= word3;
            word2 >>= 8;
            MATCHING_KEEP(word2);
            var_a1 = word2 + 1;
            var_v0_5 = var_a1 < 6;
            if (var_a1 <= 0) {
                var_a1 = Camera33_9DE6C_Zero() + 1;
                var_v0_5 = var_a1 < 6;
            }
            if (var_v0_5 == 0) {
                var_a1 = 5;
            }
            if (((unsigned int)(Camera33_9DE6C_D_80070328.animationState - 0x7A) < 2U) ||
                (Camera33_9DE6C_D_80070328.animationState == 0x7C)) {
                word2 = Camera33_9DE6C_Field(temp_s0, int*, 0x50);
                __asm__ volatile("" : "=l"(rawLow) : "l"(var_a1 * word2) : "memory");
                address4 = &Camera33_9DE6C_D_8006E140;
                MATCHING_KEEP(address4);
                word2 = *address4;
                product7 = rawLow;
                __asm__("" : "=r"(product7) : "0"(product7), "r"(word2));
                word3 = product7 >> 9;
                word2 -= word3;
                *address4 = word2;
                word2 = Camera33_9DE6C_Field(temp_s0, int*, 0x54);
                __asm__ volatile("" : "=l"(rawLow) : "l"(var_a1 * word2) : "memory");
                word2 = Camera33_9DE6C_D_8006E144;
                product7 = rawLow;
                __asm__("" : "=r"(product7) : "0"(product7), "r"(word2));
                word3 = product7 >> 9;
                word2 += word3;
                Camera33_9DE6C_D_8006E144 = word2;
            } else {
                word2 = Camera33_9DE6C_Field(temp_s0, int*, 0x50);
                __asm__ volatile("" : "=l"(rawLow) : "l"(var_a1 * word2) : "memory");
                address4 = &Camera33_9DE6C_D_8006E140;
                MATCHING_KEEP(address4);
                word2 = *address4;
                product7 = rawLow;
                __asm__("" : "=r"(product7) : "0"(product7), "r"(word2));
                word3 = product7 >> 8;
                word2 -= word3;
                *address4 = word2;
                word2 = Camera33_9DE6C_Field(temp_s0, int*, 0x54);
                __asm__ volatile("" : "=l"(rawLow) : "l"(var_a1 * word2) : "memory");
                word2 = Camera33_9DE6C_D_8006E144;
                product7 = rawLow;
                __asm__("" : "=r"(product7) : "0"(product7), "r"(word2));
                word3 = product7 >> 8;
                word2 += word3;
                Camera33_9DE6C_D_8006E144 = word2;
            }
            address4 = &Camera33_9DE6C_D_8006E144;
            MATCHING_KEEP(address4);
            word2 = *address4;
            MATCHING_KEEP(word2);
            temp_v1_5 = word2 & 0xFFF;
            *address4 = temp_v1_5;
            if (temp_v1_5 >= 0x801) {
                word2 = temp_v1_5 - 0x1000;
                MATCHING_KEEP(word2);
                *address4 = word2;
            }
            if (*address4 < -0x200) {
                *address4 = -0x200;
            }
            if (*address4 >= 0x201) {
                *address4 = 0x200;
            }
            temp_v1_6 = Camera33_9DE6C_D_8006E140 & 0xFFF;
            Camera33_9DE6C_D_8006E140 = temp_v1_6;
            if (temp_v1_6 >= 0x801) {
                Camera33_9DE6C_D_8006E140 = temp_v1_6 - 0x1000;
            }
            if ((Camera33_9DE6C_D_8006C5BC != 0x2C) || (Camera33_9DE6C_D_80071A04 == 0)) {
                var_v0_6 = Camera33_9DE6C_D_8006E140;
                Camera33_9DE6C_D_80070328.rotation.yaw = var_v0_6;
            } else {
                var_v1_3 = Camera33_9DE6CSubAngle12(Camera33_9DE6C_D_80070328.rotation.yaw,
                                                    (int)Camera33_9DE6C_D_8006E040) >>
                           2;
                if (var_v1_3 == 0) {
                    var_v0_6 = Camera33_9DE6C_D_80070328.rotation.yaw;
                } else {
                    if (var_v1_3 >= 0x81) {
                        var_v1_3 = Camera33_9DE6C_Zero() + 0x80;
                    }
                    var_v0_7 = var_v1_3 < -0x80;
                    MATCHING_KEEP(var_v0_7);
                    if (var_v0_7 != 0) {
                        var_v1_3 = -0x80;
                    }
                    var_v0_6 = (unsigned short)Camera33_9DE6C_D_8006E040 - var_v1_3;
                }
            }
            Camera33_9DE6C_D_8006E1F0 = var_v0_6;
            __asm__ volatile("" ::: "$4", "$5", "memory");
            Camera33_9DE6CCopyVector(&Camera33_9DE6C_D_8006E1E0,
                                     &Camera33_9DE6C_D_80070328.position);
            Camera33_9DE6C_D_8006E1EC = 0;
            Camera33_9DE6C_D_8006E1E8 += 0xE0;
            Camera33_9DE6C_D_8006E1EE = Camera33_9DE6C_D_8006E144;
            temp_a0_3 = Camera33_9DE6C_Field(temp_s0, int*, 0x58);
            temp_a1 = ((int)(temp_a0_3 - 0x155) >> 4) + 0x10;
            if (Camera33_9DE6C_D_8006E538 & 9) {
                temp_v0_2 = temp_a0_3 + temp_a1;
                Camera33_9DE6C_Field(temp_s0, int*, 0x58) = temp_v0_2;
                if (temp_v0_2 >= 0x801) {
                    Camera33_9DE6C_Field(temp_s0, int*, 0x58) = 0x800;
                }
            }
            if (Camera33_9DE6C_D_8006E538 & 6) {
                temp_v0_3 = Camera33_9DE6C_Field(temp_s0, int*, 0x58) - temp_a1;
                Camera33_9DE6C_Field(temp_s0, int*, 0x58) = temp_v0_3;
                if (temp_v0_3 < 0x155) {
                    Camera33_9DE6C_Field(temp_s0, int*, 0x58) = 0x155;
                }
            }
            Camera33_9DE6C_D_8006E1D0 = Camera33_9DE6C_Field(temp_s0, int*, 0x58) - 0x155;
            return;
        case 39:
            base17 = (unsigned char*)&Camera33_9DE6C_D_8006E12C;
            MATCHING_KEEP(base17);
            temp_a0_4 = (CameraPosition*)(base17 - 0x54);
            if (Camera33_9DE6C_Field(base17, int*, 0) == 0) {
                Camera33_9DE6CSelectCameraFollowProfile(temp_a0_4);
                MATCHING_KEEP_VOLATILE_CLOBBER(base17, "$4");
                Camera33_9DE6CCopyCameraPositionWithWrappedAngle((CameraPosition*)(base17 - 0x54),
                                                                 &Camera33_9DE6C_D_80069314, 0);
                Camera33_9DE6CCopyCameraPositionWithWrappedAngle((CameraPosition*)(base17 - 0x40),
                                                                 &Camera33_9DE6C_D_800693A0, 0);
                Camera33_9DE6CCopyCameraPositionWithWrappedAngle((CameraPosition*)(base17 - 0x2C),
                                                                 &Camera33_9DE6C_D_800693C8, 0);
                Camera33_9DE6C_D_8006E114 = -1;
                Camera33_9DE6C_D_8006E118 = -1;
                Camera33_9DE6C_D_8006E11C = -1;
                Camera33_9DE6C_D_8006E120 = -1;
                Camera33_9DE6C_D_8006E124 = -1;
            } else {
                Camera33_9DE6CCopyCameraPositionWithWrappedAngle(
                    temp_a0_4, &Camera33_9DE6C_D_8006929C[var_s2], 0);
                Camera33_9DE6CCopyCameraPositionWithWrappedAngle(
                    (CameraPosition*)(base17 - 0x40), &Camera33_9DE6C_D_80069328[var_s2], 0);
                Camera33_9DE6CCopyCameraPositionWithWrappedAngle((CameraPosition*)(base17 - 0x18),
                                                                 &Camera33_9DE6C_D_800693B4, 0);
                Camera33_9DE6CCopyCameraPositionWithWrappedAngle((CameraPosition*)(base17 - 0x2C),
                                                                 &Camera33_9DE6C_D_800693C8, 0);
            }
            Camera33_9DE6CRefreshCameraPlayerAnchor();
            return;
        case 40:
            Camera33_9DE6CCopyVector(&Camera33_9DE6C_D_8006E1E0,
                                     &Camera33_9DE6C_D_80070328.position);
            Camera33_9DE6C_D_8006E1E8 += 0xE0;
            Camera33_9DE6C_D_8006E1EC = (short)Camera33_9DE6C_D_80070328.rotation.roll;
            Camera33_9DE6C_D_8006E1EE = (short)Camera33_9DE6C_D_80070328.rotation.pitch;
            Camera33_9DE6C_D_8006E1F0 = (short)Camera33_9DE6C_D_80070328.rotation.yaw;
            return;
        case 41:
            Camera33_9DE6CUpdateSmoothedInputPair(&originalFrame.sp10, &Camera33_9DE6C_D_8006E154,
                                                  1);
            temp_a0_5 = Camera33_9DE6C_D_8006E140 + (originalFrame.sp10 >> 2);
            Camera33_9DE6C_D_8006E140 = temp_a0_5;
            temp_v0_4 = Camera33_9DE6C_D_8006E144 + (originalFrame.sp14 >> 2);
            Camera33_9DE6C_D_8006E144 = temp_v0_4;
            if (temp_v0_4 < -0x200) {
                Camera33_9DE6C_D_8006E144 = -0x200;
            }
            temp_v1_7 = temp_a0_5 & 0xFFF;
            if (Camera33_9DE6C_D_8006E144 >= 0x201) {
                Camera33_9DE6C_D_8006E144 = 0x200;
            }
            Camera33_9DE6C_D_8006E140 = temp_v1_7;
            if (temp_v1_7 >= 0x801) {
                Camera33_9DE6C_D_8006E140 = temp_v1_7 - 0x1000;
            }
            Camera33_9DE6C_D_80070328.rotation.yaw = Camera33_9DE6C_D_8006E140;
            Camera33_9DE6CCopyVector(
                &Camera33_9DE6C_D_8006E154 + 0x8C,
                (Vector3D*)((unsigned char*)&Camera33_9DE6C_D_80070328.rotation.yaw - 0x64));
            Camera33_9DE6C_D_8006E1EC = 0;
            Camera33_9DE6C_D_8006E1EE = Camera33_9DE6C_D_8006E144;
            Camera33_9DE6C_D_8006E1F0 = (short)Camera33_9DE6C_D_80070328.rotation.yaw;
            break;
    }
}
#undef Camera33_9DE6C_Field


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
            MATCHING_KEEP(position);
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
            MATCHING_KEEP(copiedPosition);
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
            MATCHING_KEEP(pointer);
            state = &DecodedMode31CameraState;
            __asm__("" : "=r"(state) : "0"(state), "r"(pointer));
            actor = *pointer;
            value = DecodedMode31Value;
            MATCHING_KEEP(value);
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
            MATCHING_KEEP3(x, y, z);
            DecodedMode40OutputX = x;
            DecodedMode40OutputY = y;
            DecodedMode40OutputZ = z;
            resetPosition = (CameraPosition*)((char*)savedPosition - 0xEC);
            goto enable;
        }
        case 41: {
            register int* state __asm__("$2") = &DecodedMode31CameraState;
            register int value __asm__("$3") = DecodedMode31Value;
            MATCHING_KEEP2(state, value);
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
void Camera33Subtract(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
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
            if (next)
                goto applySelector;
            if (Camera33Held & 16) {
                flag = Camera33Player[0x1B9];
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(flag, "$4");
                next = 7;
                if (flag)
                    goto applySelector;
            }
            flag = Camera33Pressed & 12;
            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(flag, "$4");
            next = 8;
            if (flag)
                goto applySelector;

            index = *(int*)(Camera33Player + 0x48);
            {
                register int current __asm__("$3") = Camera33Mode;
                __asm__ __volatile__("" : "=r"(index) : "0"(index), "r"(current));
                next = Camera33ModeTable[index];
                if (current == next)
                    return;
                if (next)
                    goto applySelector;
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(current, "$4");
                next = 6;
                goto applySelector;
            }

        case 17:
            next = Camera33Override;
            if (!next)
                goto readTable;
            if (next == 17)
                return;
            goto applySelector;
        case 23:
            next = Camera33Override;
            if (next)
                goto applySelector;

            index = *(int*)(Camera33Player + 0x48);
            {
                register int current __asm__("$3") = Camera33Mode;
                __asm__ __volatile__("" : "=r"(current) : "0"(current), "r"(index));
                next = Camera33ModeTable[index];
                if (current == next)
                    return;
                if (next)
                    goto applySelector;
                MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(current, "$4");
                next = 6;
                goto applySelector;
            }

        case 31:
            next = Camera33Override;
            if (next && next != 40)
                func_80016764(next);
            if (Camera33Player[0x1B9] == 0) {
                register int* overrideState __asm__("$17") = &Camera33Override;
                register CameraPosition* initial __asm__("$16") =
                    (CameraPosition*)((char*)overrideState - 0xD8);
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
                register CameraPosition* initial __asm__("$16") =
                    (CameraPosition*)((char*)overrideState - 0xD8);
                if (*overrideState == 40) {
                    MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(overrideState, "$4");
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
                func_80016764(0);
                camera.unk50 = 2;
                ((unsigned char*)*(unsigned int*)(Camera33Player + 0x250))[0x4C] = 16;
            }
            return;
        case 39:
            next = Camera33Override;
            if (next)
                goto applySelector;
            if ((Camera33Pressed & 16) && Camera33Player[0x1B9] &&
                *(int*)(Camera33Player + 0x24C) == 4) {
                next = 31;
                goto applySelector;
            }

            index = *(int*)(Camera33Player + 0x48);
            {
                register int current __asm__("$3") = Camera33Mode;
                next = Camera33ModeTable[index];
                if (current == next)
                    return;
                if (next)
                    goto applySelector;
                next = 6;
                goto applySelector;
            }
        case 40:
            next = Camera33Override;
            if (next && next != Camera33Mode)
                goto applySelector;
            if ((Camera33Pressed & 16) && Camera33Player[0x1B9] &&
                *(int*)(Camera33Player + 0x24C) == 4) {
                next = 31;
                goto applySelector;
            }
            return;
        case 41:
            next = Camera33Override;
            if (next && next != Camera33Mode)
                goto applySelector;
            {
                register unsigned char* flagBase __asm__("$18") = Camera33Flags;
                register Vector3D* source __asm__("$17");
                register CameraPosition* destination __asm__("$16");
                register Vector3D* argument __asm__("$4");
                if (*(int*)flagBase & 0x20000)
                    return;
                func_8004F178(&local, (Vector3D*)(flagBase + 0xC));
                argument = &local;
                MATCHING_KEEP_CLOBBER(argument, "$17");
                source = (Vector3D*)(flagBase - 0x210);
                Camera33Subtract(argument, source, argument);
                destination = &Camera33Position;
                func_800136F0(destination, &local, source);
                func_8004F178((Vector3D*)((char*)destination - 0x30), source);
                MATCHING_KEEP(flagBase);
                camera.unk6c = *(int*)(flagBase - 0x1AC);
                func_800135A4((CameraPosition*)((char*)destination + 0x14), destination, 0);
                camera.unk140[0] = 0;
                camera.unk140[1] = 0;
                camera.unk140[2] = 1;
                camera.unk140[5] = 0;
                func_80012AC8();
                func_80012B34();
            readTable:
                next = Camera33ModeTable[*(int*)(Camera33Player + 0x48)];
                goto applySelector;
            }
        default:
            return;
    }
applySelector:
    func_80016764(next);
}
