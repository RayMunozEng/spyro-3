#include "matching.h"
extern unsigned char Raw26Union[] __asm__("D_80070328+0x144");
extern int Raw26Movement __asm__("D_80070328+0x50");
extern short Signed26A[] __asm__("D_800658A0");
extern short Signed26B[] __asm__("D_80065920");
#include "common.h"
#include "ovl_header.h"
#include "drawutil.h"
#include "spu.h"
#include "hud.h"
#include "mobyutil.h"
#include "stdutil.h"
#include "camera.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original80088AD8.
 * Assembly SHA256 56e47dd8825b626e18f9890d269a7b190b137dc9f4c684e212245ddb55020630.
 * AI-generated; not human reviewed. All782 original instructions,
 * 10 selectors bias100 and 0 owned padding words are required.
 * Original frame0x98; every concrete field width and producer is retained.
 * Eight state bodies reuse verified13/50/11 with exact concrete stack maps.
 * Original scratch10..7C,savedS0..S3,combinedS2 and selectors100..109 remain.
 * Original107 uses50's two-pointer vector/particle path; original109 includes
 * its eight original epilogue rows. All original scalar,vector,control,gate and
 * byte/halfword producers remain original,without inferred helper semantics.
 * Typed aliases stay distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit words.
 * Raw units/fixed point, helper contracts and caller rate remain unresolved.
 * Cadence is per invocation. Falsification: every native/linked instruction,
 * actual internal/conditional target,selector/data word and full EXE/every
 * overlay retail hash. Binary identity does not establish runtime completion. */
#define Physics26Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Physics26RandSignedBetweenView4() __asm__("func_800363DC");
unsigned char Physics26UpdatePlayerGroundInputTargetsView5() __asm__("func_80040D10");
unsigned char Physics26ApproachPlayerTargetHeadingView5() __asm__("func_80041580");
unsigned char Physics26BlendPlayerHeadingFromInputVectorView5() __asm__("func_800416F4");
unsigned char Physics26ApproachPlayerTargetSpeedView5() __asm__("func_800417FC");
unsigned char Physics26BuildPlayerResponseVectorView5() __asm__("func_80041B64");
int Physics26InterpolateSineView5() __asm__("func_8004E9E4");
int Physics26InterpolateCosineView5() __asm__("func_8004EA2C");
unsigned char Physics26TransformVectorByBasisView4() __asm__("func_8004ED6C");
int Physics26MeasureVectorLengthView5() __asm__("func_8004EDE8");
unsigned char Physics26ScaleVectorRatioQ15View5() __asm__("func_8004F08C");
unsigned char Physics26ShiftVectorRightTowardZeroView3() __asm__("func_8004F110");
unsigned char Physics26ClearVectorView5() __asm__("func_8004F168");
unsigned char Physics26CopyVectorView5() __asm__("func_8004F178");
unsigned char Physics26AddVectorView5() __asm__("func_8004F194");
unsigned char Physics26SubtractVectorView5() __asm__("func_8004F1C8");
int Physics26CallRandView4() __asm__("rand");
extern unsigned char Physics26Data658A0View5 __asm__("D_800658A0");
extern unsigned char Physics26Data65920View5 __asm__("D_80065920");
extern void* Physics26Data6C570View4 __asm__("D_8006C570");
extern int Physics26Data6C640View5 __asm__("D_8006C640");
extern int Physics26Data6E044View5 __asm__("D_8006E044");
extern unsigned char Physics26Data6E548View5 __asm__("D_8006E548");
extern unsigned char Physics26Player0View5 __asm__("D_80070328");
extern int Physics26Player94View4 __asm__("D_80070328+0x94");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics26UpdatePlayerGroundInputTargetsView6() __asm__("func_80040D10");
int Physics26BuildOrientedInputPairView3() __asm__("func_80040F48");
int Physics26UpdateSmoothedInputPairView3() __asm__("func_800410F8");
int Physics26ApplyPlayerRotationStepView2() __asm__("func_80041404");
int Physics26ApproachPlayerTargetHeadingView6() __asm__("func_80041580");
int Physics26BlendPlayerHeadingFromInputVectorView6() __asm__("func_800416F4");
int Physics26ApproachPlayerTargetSpeedView6() __asm__("func_800417FC");
int Physics26BuildPlayerMovementVectorView4() __asm__("func_80041848");
int Physics26BuildPlayerResponseVectorView6() __asm__("func_80041B64");
int Physics26InterpolateSineView6() __asm__("func_8004E9E4");
int Physics26InterpolateCosineView6() __asm__("func_8004EA2C");
int Physics26MeasureVectorLengthView6() __asm__("func_8004EDE8");
int Physics26ScaleVectorRatioQ15View6() __asm__("func_8004F08C");
int Physics26ClearVectorView6() __asm__("func_8004F168");
int Physics26CopyVectorView6() __asm__("func_8004F178");
int Physics26AddVectorView6() __asm__("func_8004F194");
int Physics26SubtractVectorView6() __asm__("func_8004F1C8");
int Physics26Absolute12BitAngleDeltaView3() __asm__("func_8004F284");
extern unsigned char Physics26Data658A0View6 __asm__("D_800658A0");
extern unsigned char Physics26Data65920View6 __asm__("D_80065920");
extern int Physics26Data6763CView2 __asm__("D_8006763C");
extern int Physics26Data67640View2 __asm__("D_80067640");
extern int Physics26Data67644View2 __asm__("D_80067644");
extern unsigned char Physics26Data676E8View3 __asm__("D_800676E8");
extern int* Physics26Data6C570View5 __asm__("D_8006C570");
extern int Physics26Data6C58CView3 __asm__("D_8006C58C");
extern int Physics26Data6C5C8View3 __asm__("D_8006C5C8");
extern int Physics26Data6C640View6 __asm__("D_8006C640");
extern short Physics26Data6E040View3 __asm__("D_8006E040");
extern int Physics26Data6E044View6 __asm__("D_8006E044");
extern int Physics26Data6E538View4 __asm__("D_8006E538");
extern unsigned char Physics26Data6E548View6 __asm__("D_8006E548");
extern unsigned char Physics26Player0View6 __asm__("D_80070328");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics26PlayerB8View3 __asm__("D_80070328+0xB8");
extern int Physics26Player94View5 __asm__("D_80070328+0x94");
extern int Physics26PlayerA8View3 __asm__("D_80070328+0xA8");
extern int Physics26Player80View2 __asm__("D_80070328+0x80");
extern int Physics26PlayerB0View3 __asm__("D_80070328+0xB0");
extern int Physics26Player64View3 __asm__("D_80070328+0x64");
extern int Physics26Player88View3 __asm__("D_80070328+0x88");
extern int Physics26Player84View2 __asm__("D_80070328+0x84");
extern int Physics26Player144View3 __asm__("D_80070328+0x144");
extern int Physics26Player60View3 __asm__("D_80070328+0x60");
extern int Physics26PlayerACView3 __asm__("D_80070328+0xAC");
extern int Physics26Player4CView3 __asm__("D_80070328+0x4C");
extern int Physics26Player14CView3 __asm__("D_80070328+0x14C");
extern int Physics26Player5CView3 __asm__("D_80070328+0x5C");
extern unsigned char Physics26PlayerFCView3 __asm__("D_80070328+0xFC");
extern int Physics26PlayerA0View3 __asm__("D_80070328+0xA0");
extern unsigned char Physics26Player1BAView2 __asm__("D_80070328+0x1BA");
extern signed char Physics26Player1B9View2 __asm__("D_80070328+0x1B9");
extern int Physics26Player20CView2 __asm__("D_80070328+0x20C");
extern unsigned char Physics26Player101View2 __asm__("D_80070328+0x101");
extern int Physics26PlayerA4View2 __asm__("D_80070328+0xA4");
extern int Physics26Player210View3 __asm__("D_80070328+0x210");
extern int Physics26PlayerF8View3 __asm__("D_80070328+0xF8");
extern int Physics26Player8View3 __asm__("D_80070328+0x8");
int Physics26RandSignedBetweenView5() __asm__("func_800363DC");
int Physics26UpdatePlayerGroundInputTargetsView7() __asm__("func_80040D10");
int Physics26BuildOrientedInputPairView4() __asm__("func_80040F48");
int Physics26ApproachPlayerTargetHeadingView7() __asm__("func_80041580");
int Physics26BlendPlayerHeadingFromInputVectorView7() __asm__("func_800416F4");
int Physics26ApproachPlayerTargetSpeedView7() __asm__("func_800417FC");
int Physics26BuildPlayerMovementVectorView5() __asm__("func_80041848");
int Physics26BuildPlayerResponseVectorView7() __asm__("func_80041B64");
int Physics26TestPlayerProbePatternView2() __asm__("func_80043194");
int Physics26PlanarHeadingLookupView3() __asm__("func_8004E880");
int Physics26InterpolateSineView7() __asm__("func_8004E9E4");
int Physics26InterpolateCosineView7() __asm__("func_8004EA2C");
int Physics26TransformVectorByBasisView5() __asm__("func_8004ED6C");
int Physics26MeasureVectorLengthView7() __asm__("func_8004EDE8");
int Physics26ScaleVectorRatioQ15View7() __asm__("func_8004F08C");
int Physics26ClearVectorView7() __asm__("func_8004F168");
int Physics26CopyVectorView7() __asm__("func_8004F178");
int Physics26AddVectorView7() __asm__("func_8004F194");
int Physics26SubtractVectorView7() __asm__("func_8004F1C8");
int Physics26Absolute12BitAngleDeltaView4() __asm__("func_8004F284");
int Physics26CallRandView5() __asm__("rand");
extern unsigned char Physics26Data658A0View7 __asm__("D_800658A0");
extern unsigned char Physics26Data65920View7 __asm__("D_80065920");
extern unsigned char Physics26Data676E8View4 __asm__("D_800676E8");
extern int Physics26Data6C514View3 __asm__("D_8006C514");
extern int* Physics26Data6C570View6 __asm__("D_8006C570");
extern int Physics26Data6C58CView4 __asm__("D_8006C58C");
extern int Physics26Data6C5C8View4 __asm__("D_8006C5C8");
extern int Physics26Data6C640View7 __asm__("D_8006C640");
extern short Physics26Data6E040View4 __asm__("D_8006E040");
extern int Physics26Data6E044View7 __asm__("D_8006E044");
extern int Physics26Data6E344View3 __asm__("D_8006E344");
extern int Physics26Data6E538View5 __asm__("D_8006E538");
extern unsigned char Physics26Data6E548View7 __asm__("D_8006E548");
extern unsigned char Physics26Player0View7 __asm__("D_80070328");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics26Player16CView2 __asm__("D_80070328+0x16C");
int Physics26TestSubdividedSegmentPathView2() __asm__("func_80013E38");
int Physics26RandSignedBetweenView6() __asm__("func_800363DC");
int Physics26UpdatePlayerGroundInputTargetsView8() __asm__("func_80040D10");
int Physics26UpdateSmoothedInputPairView4() __asm__("func_800410F8");
int Physics26ApproachPlayerTargetHeadingView8() __asm__("func_80041580");
int Physics26BlendPlayerHeadingFromInputVectorView8() __asm__("func_800416F4");
int Physics26ApproachPlayerTargetSpeedView8() __asm__("func_800417FC");
int Physics26BuildPlayerMovementVectorView6() __asm__("func_80041848");
int Physics26BuildPlayerResponseVectorView8() __asm__("func_80041B64");
int Physics26EvaluateClampedPlayerRootCurveView2() __asm__("func_8004E4E4");
int Physics26PlanarHeadingLookupView4() __asm__("func_8004E880");
int Physics26InterpolateSineView8() __asm__("func_8004E9E4");
int Physics26InterpolateCosineView8() __asm__("func_8004EA2C");
int Physics26TransformVectorByBasisView6() __asm__("func_8004ED6C");
int Physics26MeasureVectorLengthView8() __asm__("func_8004EDE8");
int Physics26ScaleVectorRatioQ15View8() __asm__("func_8004F08C");
int Physics26ShiftVectorLeftView2() __asm__("func_8004F0E8");
int Physics26ShiftVectorRightTowardZeroView4() __asm__("func_8004F110");
int Physics26ClearVectorView8() __asm__("func_8004F168");
int Physics26CopyVectorView8() __asm__("func_8004F178");
int Physics26AddVectorView8() __asm__("func_8004F194");
int Physics26SubtractVectorView8() __asm__("func_8004F1C8");
int Physics26CallRandView6() __asm__("rand");
extern unsigned char Physics26Data658A0View8 __asm__("D_800658A0");
extern unsigned char Physics26Data65920View8 __asm__("D_80065920");
extern int Physics26Data67630View2 __asm__("D_80067630");
extern int Physics26Data67634View2 __asm__("D_80067634");
extern int Physics26Data67638View2 __asm__("D_80067638");
extern int Physics26Data6C514View4 __asm__("D_8006C514");
extern int Physics26Data6C640View8 __asm__("D_8006C640");
extern int Physics26Data6C7C4View2 __asm__("D_8006C7C4");
extern int Physics26Data6E044View8 __asm__("D_8006E044");
extern int Physics26Data6E344View4 __asm__("D_8006E344");
extern int Physics26Data6E538View6 __asm__("D_8006E538");
extern unsigned char Physics26Data6E548View8 __asm__("D_8006E548");
extern int Physics26Data6FA38View2 __asm__("D_8006FA38");
extern unsigned char Physics26Player0View8 __asm__("D_80070328");
extern int Physics26Data71908View2 __asm__("D_80071908");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics26Player130View2 __asm__("D_80070328+0x130");
extern int Physics26Player144View4 __asm__("D_80070328+0x144");
extern short Physics26Player148View3 __asm__("D_80070328+0x148");
extern short Physics26Player14AView2 __asm__("D_80070328+0x14A");
extern int Physics26Player14CView4 __asm__("D_80070328+0x14C");
extern int Physics26Player150View2 __asm__("D_80070328+0x150");
extern int Physics26Player154View2 __asm__("D_80070328+0x154");
extern int Physics26Player160View2 __asm__("D_80070328+0x160");
extern int Physics26Player48View2 __asm__("D_80070328+0x48");
extern int Physics26Player4CView4 __asm__("D_80070328+0x4C");
extern int Physics26Player5CView4 __asm__("D_80070328+0x5C");
extern int Physics26Player60View4 __asm__("D_80070328+0x60");
extern int Physics26Player64View4 __asm__("D_80070328+0x64");
extern int Physics26Player8View4 __asm__("D_80070328+0x8");
extern int Physics26Player88View4 __asm__("D_80070328+0x88");
extern int Physics26Player8CView2 __asm__("D_80070328+0x8C");
extern int Physics26Player90View2 __asm__("D_80070328+0x90");
extern int Physics26Player94View6 __asm__("D_80070328+0x94");
extern int Physics26PlayerA8View4 __asm__("D_80070328+0xA8");
extern int Physics26PlayerACView4 __asm__("D_80070328+0xAC");
extern int Physics26PlayerB0View4 __asm__("D_80070328+0xB0");
extern int Physics26PlayerF8View4 __asm__("D_80070328+0xF8");
extern int Physics26Player148View4 __asm__("D_80070328+0x148");
extern int Physics26Player210View4 __asm__("D_80070328+0x210");
extern int Physics26Player220View2 __asm__("D_80070328+0x220");
extern int Physics26Player98View2 __asm__("D_80070328+0x98");
extern int Physics26PlayerA0View4 __asm__("D_80070328+0xA0");
extern int Physics26PlayerB8View4 __asm__("D_80070328+0xB8");
extern int Physics26PlayerCCView2 __asm__("D_80070328+0xCC");
extern int Physics26PlayerD0View2 __asm__("D_80070328+0xD0");
extern int Physics26PlayerE4View2 __asm__("D_80070328+0xE4");
extern unsigned char Physics26PlayerFCView4 __asm__("D_80070328+0xFC");
int Physics26RandSignedBetweenView4() __asm__("func_800363DC");
unsigned char Physics26UpdatePlayerGroundInputTargetsView5() __asm__("func_80040D10");
unsigned char Physics26ApproachPlayerTargetHeadingView5() __asm__("func_80041580");
unsigned char Physics26BlendPlayerHeadingFromInputVectorView5() __asm__("func_800416F4");
unsigned char Physics26ApproachPlayerTargetSpeedView5() __asm__("func_800417FC");
unsigned char Physics26BuildPlayerResponseVectorView5() __asm__("func_80041B64");
int Physics26InterpolateSineView5() __asm__("func_8004E9E4");
int Physics26InterpolateCosineView5() __asm__("func_8004EA2C");
unsigned char Physics26TransformVectorByBasisView4() __asm__("func_8004ED6C");
int Physics26MeasureVectorLengthView5() __asm__("func_8004EDE8");
unsigned char Physics26ScaleVectorRatioQ15View5() __asm__("func_8004F08C");
unsigned char Physics26ShiftVectorRightTowardZeroView3() __asm__("func_8004F110");
unsigned char Physics26ClearVectorView5() __asm__("func_8004F168");
unsigned char Physics26CopyVectorView5() __asm__("func_8004F178");
unsigned char Physics26AddVectorView5() __asm__("func_8004F194");
unsigned char Physics26SubtractVectorView5() __asm__("func_8004F1C8");
int Physics26CallRandView4() __asm__("rand");
extern unsigned char Physics26Data658A0View5 __asm__("D_800658A0");
extern unsigned char Physics26Data65920View5 __asm__("D_80065920");
extern void* Physics26Data6C570View4 __asm__("D_8006C570");
extern int Physics26Data6C640View5 __asm__("D_8006C640");
extern int Physics26Data6E044View5 __asm__("D_8006E044");
extern unsigned char Physics26Data6E548View5 __asm__("D_8006E548");
extern unsigned char Physics26Player0View5 __asm__("D_80070328");
extern int Physics26Player94View4 __asm__("D_80070328+0x94");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics26UpdatePlayerGroundInputTargetsView6() __asm__("func_80040D10");
int Physics26BuildOrientedInputPairView3() __asm__("func_80040F48");
int Physics26UpdateSmoothedInputPairView3() __asm__("func_800410F8");
int Physics26ApplyPlayerRotationStepView2() __asm__("func_80041404");
int Physics26ApproachPlayerTargetHeadingView6() __asm__("func_80041580");
int Physics26BlendPlayerHeadingFromInputVectorView6() __asm__("func_800416F4");
int Physics26ApproachPlayerTargetSpeedView6() __asm__("func_800417FC");
int Physics26BuildPlayerMovementVectorView4() __asm__("func_80041848");
int Physics26BuildPlayerResponseVectorView6() __asm__("func_80041B64");
int Physics26InterpolateSineView6() __asm__("func_8004E9E4");
int Physics26InterpolateCosineView6() __asm__("func_8004EA2C");
int Physics26MeasureVectorLengthView6() __asm__("func_8004EDE8");
int Physics26ScaleVectorRatioQ15View6() __asm__("func_8004F08C");
int Physics26ClearVectorView6() __asm__("func_8004F168");
int Physics26CopyVectorView6() __asm__("func_8004F178");
int Physics26AddVectorView6() __asm__("func_8004F194");
int Physics26SubtractVectorView6() __asm__("func_8004F1C8");
int Physics26Absolute12BitAngleDeltaView3() __asm__("func_8004F284");
extern unsigned char Physics26Data658A0View6 __asm__("D_800658A0");
extern unsigned char Physics26Data65920View6 __asm__("D_80065920");
extern int Physics26Data6763CView2 __asm__("D_8006763C");
extern int Physics26Data67640View2 __asm__("D_80067640");
extern int Physics26Data67644View2 __asm__("D_80067644");
extern unsigned char Physics26Data676E8View3 __asm__("D_800676E8");
extern int* Physics26Data6C570View5 __asm__("D_8006C570");
extern int Physics26Data6C58CView3 __asm__("D_8006C58C");
extern int Physics26Data6C5C8View3 __asm__("D_8006C5C8");
extern int Physics26Data6C640View6 __asm__("D_8006C640");
extern short Physics26Data6E040View3 __asm__("D_8006E040");
extern int Physics26Data6E044View6 __asm__("D_8006E044");
extern int Physics26Data6E538View4 __asm__("D_8006E538");
extern unsigned char Physics26Data6E548View6 __asm__("D_8006E548");
extern unsigned char Physics26Player0View6 __asm__("D_80070328");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics26PlayerB8View3 __asm__("D_80070328+0xB8");
extern int Physics26Player94View5 __asm__("D_80070328+0x94");
extern int Physics26PlayerA8View3 __asm__("D_80070328+0xA8");
extern int Physics26Player80View2 __asm__("D_80070328+0x80");
extern int Physics26PlayerB0View3 __asm__("D_80070328+0xB0");
extern int Physics26Player64View3 __asm__("D_80070328+0x64");
extern int Physics26Player88View3 __asm__("D_80070328+0x88");
extern int Physics26Player84View2 __asm__("D_80070328+0x84");
extern int Physics26Player144View3 __asm__("D_80070328+0x144");
extern int Physics26Player60View3 __asm__("D_80070328+0x60");
extern int Physics26PlayerACView3 __asm__("D_80070328+0xAC");
extern int Physics26Player4CView3 __asm__("D_80070328+0x4C");
extern int Physics26Player14CView3 __asm__("D_80070328+0x14C");
extern int Physics26Player5CView3 __asm__("D_80070328+0x5C");
extern unsigned char Physics26PlayerFCView3 __asm__("D_80070328+0xFC");
extern int Physics26PlayerA0View3 __asm__("D_80070328+0xA0");
extern unsigned char Physics26Player1BAView2 __asm__("D_80070328+0x1BA");
extern signed char Physics26Player1B9View2 __asm__("D_80070328+0x1B9");
extern int Physics26Player20CView2 __asm__("D_80070328+0x20C");
extern unsigned char Physics26Player101View2 __asm__("D_80070328+0x101");
extern int Physics26PlayerA4View2 __asm__("D_80070328+0xA4");
extern int Physics26Player210View3 __asm__("D_80070328+0x210");
extern int Physics26PlayerF8View3 __asm__("D_80070328+0xF8");
extern int Physics26Player8View3 __asm__("D_80070328+0x8");
int Physics26RandSignedBetweenView5() __asm__("func_800363DC");
int Physics26UpdatePlayerGroundInputTargetsView7() __asm__("func_80040D10");
int Physics26BuildOrientedInputPairView4() __asm__("func_80040F48");
int Physics26ApproachPlayerTargetHeadingView7() __asm__("func_80041580");
int Physics26BlendPlayerHeadingFromInputVectorView7() __asm__("func_800416F4");
int Physics26ApproachPlayerTargetSpeedView7() __asm__("func_800417FC");
int Physics26BuildPlayerMovementVectorView5() __asm__("func_80041848");
int Physics26BuildPlayerResponseVectorView7() __asm__("func_80041B64");
int Physics26TestPlayerProbePatternView2() __asm__("func_80043194");
int Physics26PlanarHeadingLookupView3() __asm__("func_8004E880");
int Physics26InterpolateSineView7() __asm__("func_8004E9E4");
int Physics26InterpolateCosineView7() __asm__("func_8004EA2C");
int Physics26TransformVectorByBasisView5() __asm__("func_8004ED6C");
int Physics26MeasureVectorLengthView7() __asm__("func_8004EDE8");
int Physics26ScaleVectorRatioQ15View7() __asm__("func_8004F08C");
int Physics26ClearVectorView7() __asm__("func_8004F168");
int Physics26CopyVectorView7() __asm__("func_8004F178");
int Physics26AddVectorView7() __asm__("func_8004F194");
int Physics26SubtractVectorView7() __asm__("func_8004F1C8");
int Physics26Absolute12BitAngleDeltaView4() __asm__("func_8004F284");
int Physics26CallRandView5() __asm__("rand");
extern unsigned char Physics26Data658A0View7 __asm__("D_800658A0");
extern unsigned char Physics26Data65920View7 __asm__("D_80065920");
extern unsigned char Physics26Data676E8View4 __asm__("D_800676E8");
extern int Physics26Data6C514View3 __asm__("D_8006C514");
extern int* Physics26Data6C570View6 __asm__("D_8006C570");
extern int Physics26Data6C58CView4 __asm__("D_8006C58C");
extern int Physics26Data6C5C8View4 __asm__("D_8006C5C8");
extern int Physics26Data6C640View7 __asm__("D_8006C640");
extern short Physics26Data6E040View4 __asm__("D_8006E040");
extern int Physics26Data6E044View7 __asm__("D_8006E044");
extern int Physics26Data6E344View3 __asm__("D_8006E344");
extern int Physics26Data6E538View5 __asm__("D_8006E538");
extern unsigned char Physics26Data6E548View7 __asm__("D_8006E548");
extern unsigned char Physics26Player0View7 __asm__("D_80070328");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics26Player16CView2 __asm__("D_80070328+0x16C");
int Physics26TestSubdividedSegmentPathView2() __asm__("func_80013E38");
int Physics26RandSignedBetweenView6() __asm__("func_800363DC");
int Physics26UpdatePlayerGroundInputTargetsView8() __asm__("func_80040D10");
int Physics26UpdateSmoothedInputPairView4() __asm__("func_800410F8");
int Physics26ApproachPlayerTargetHeadingView8() __asm__("func_80041580");
int Physics26BlendPlayerHeadingFromInputVectorView8() __asm__("func_800416F4");
int Physics26ApproachPlayerTargetSpeedView8() __asm__("func_800417FC");
int Physics26BuildPlayerMovementVectorView6() __asm__("func_80041848");
int Physics26BuildPlayerResponseVectorView8() __asm__("func_80041B64");
int Physics26EvaluateClampedPlayerRootCurveView2() __asm__("func_8004E4E4");
int Physics26PlanarHeadingLookupView4() __asm__("func_8004E880");
int Physics26InterpolateSineView8() __asm__("func_8004E9E4");
int Physics26InterpolateCosineView8() __asm__("func_8004EA2C");
int Physics26TransformVectorByBasisView6() __asm__("func_8004ED6C");
int Physics26MeasureVectorLengthView8() __asm__("func_8004EDE8");
int Physics26ScaleVectorRatioQ15View8() __asm__("func_8004F08C");
int Physics26ShiftVectorLeftView2() __asm__("func_8004F0E8");
int Physics26ShiftVectorRightTowardZeroView4() __asm__("func_8004F110");
int Physics26ClearVectorView8() __asm__("func_8004F168");
int Physics26CopyVectorView8() __asm__("func_8004F178");
int Physics26AddVectorView8() __asm__("func_8004F194");
int Physics26SubtractVectorView8() __asm__("func_8004F1C8");
int Physics26CallRandView6() __asm__("rand");
extern unsigned char Physics26Data658A0View8 __asm__("D_800658A0");
extern unsigned char Physics26Data65920View8 __asm__("D_80065920");
extern int Physics26Data67630View2 __asm__("D_80067630");
extern int Physics26Data67634View2 __asm__("D_80067634");
extern int Physics26Data67638View2 __asm__("D_80067638");
extern int Physics26Data6C514View4 __asm__("D_8006C514");
extern int Physics26Data6C640View8 __asm__("D_8006C640");
extern int Physics26Data6C7C4View2 __asm__("D_8006C7C4");
extern int Physics26Data6E044View8 __asm__("D_8006E044");
extern int Physics26Data6E344View4 __asm__("D_8006E344");
extern int Physics26Data6E538View6 __asm__("D_8006E538");
extern unsigned char Physics26Data6E548View8 __asm__("D_8006E548");
extern int Physics26Data6FA38View2 __asm__("D_8006FA38");
extern unsigned char Physics26Player0View8 __asm__("D_80070328");
extern int Physics26Data71908View2 __asm__("D_80071908");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics26Player130View2 __asm__("D_80070328+0x130");
extern int Physics26Player144View4 __asm__("D_80070328+0x144");
extern short Physics26Player148View3 __asm__("D_80070328+0x148");
extern short Physics26Player14AView2 __asm__("D_80070328+0x14A");
extern int Physics26Player14CView4 __asm__("D_80070328+0x14C");
extern int Physics26Player150View2 __asm__("D_80070328+0x150");
extern int Physics26Player154View2 __asm__("D_80070328+0x154");
extern int Physics26Player160View2 __asm__("D_80070328+0x160");
extern int Physics26Player48View2 __asm__("D_80070328+0x48");
extern int Physics26Player4CView4 __asm__("D_80070328+0x4C");
extern int Physics26Player5CView4 __asm__("D_80070328+0x5C");
extern int Physics26Player60View4 __asm__("D_80070328+0x60");
extern int Physics26Player64View4 __asm__("D_80070328+0x64");
extern int Physics26Player8View4 __asm__("D_80070328+0x8");
extern int Physics26Player88View4 __asm__("D_80070328+0x88");
extern int Physics26Player8CView2 __asm__("D_80070328+0x8C");
extern int Physics26Player90View2 __asm__("D_80070328+0x90");
extern int Physics26Player94View6 __asm__("D_80070328+0x94");
extern int Physics26PlayerA8View4 __asm__("D_80070328+0xA8");
extern int Physics26PlayerACView4 __asm__("D_80070328+0xAC");
extern int Physics26PlayerB0View4 __asm__("D_80070328+0xB0");
extern int Physics26PlayerF8View4 __asm__("D_80070328+0xF8");
extern int Physics26Player148View4 __asm__("D_80070328+0x148");
extern int Physics26Player210View4 __asm__("D_80070328+0x210");
extern int Physics26Player220View2 __asm__("D_80070328+0x220");
extern int Physics26Player98View2 __asm__("D_80070328+0x98");
extern int Physics26PlayerA0View4 __asm__("D_80070328+0xA0");
extern int Physics26PlayerB8View4 __asm__("D_80070328+0xB8");
extern int Physics26PlayerCCView2 __asm__("D_80070328+0xCC");
extern int Physics26PlayerD0View2 __asm__("D_80070328+0xD0");
extern int Physics26PlayerE4View2 __asm__("D_80070328+0xE4");
extern unsigned char Physics26PlayerFCView4 __asm__("D_80070328+0xFC");
extern void* (*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics50_SpawnParticle)() __asm__("SpawnParticle");
void func_level_26_80088AD8(int slotIndex) {
    int lowProduct6;
    register void* fieldA4State28 __asm__("$16");
    register void* vector8CState28 __asm__("$17");
    register int workWord2 __asm__("$2");
    register int stateWord3 __asm__("$3");
    register int particleThreshold __asm__("$19");
    register void* vectorAt40 __asm__("$16");
    register void* vectorAt30 __asm__("$17");
    register void* call4 __asm__("$4");
    register void* call5 __asm__("$5");
    register void* call6 __asm__("$6");
    int lowProduct0, lowProduct1, lowProduct2, lowProduct3, lowProduct4, lowProduct5;
    register void* globalPointer __asm__("$3");
    struct {
        int sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44,
            sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C;
    } originalFrame;
    register int signedTableWord __asm__("$7");
    register void* globalVector80 __asm__("$16");
    register void* globalVector80State20 __asm__("$16");
    register void* globalVector8CState20 __asm__("$18");
    register void* globalVector8C __asm__("$19");
    register void* var_a0_3 __asm__("$4");
    register int combinedIndex __asm__("$18");
    int temp_v0_4;
    int temp_v0_6;
    register int workWord3 __asm__("$3");
    register int particleIndex __asm__("$17");
    register int nextField94 __asm__("$2");
    register unsigned char* globalByteE __asm__("$18");
    register void* globalFieldB8PointerState20 __asm__("$16");
    register void* globalFieldA4Pointer __asm__("$17");
    void* temp_v0_5;
    void* temp_v0_7;
    void* raw13_temp_s0_9;
    void* raw13_temp_s1_4;
    void* raw13_temp_s1_5;
    int raw13_temp_v0_15;
    int raw13_temp_v0_16;
    workWord2 = slotIndex * 16;
    globalPointer = &Physics26Data6E548View5;
    workWord2 += (int)globalPointer;
    MATCHING_KEEP(workWord2);
    Physics26Data6C570View4 = (void*)workWord2;
    workWord2 = Physics26Field(&Physics26Player0View5, int*, 0x54);
    stateWord3 = Physics26Field(&Physics26Player0View5, int*, 0x48);
    combinedIndex = workWord2 + slotIndex;
    switch (stateWord3) {
        default:
            return;
        case 107:
            Physics26UpdatePlayerGroundInputTargetsView5(0xC80);
            Physics26ApproachPlayerTargetHeadingView5(0x28, 8);
            Physics26ApproachPlayerTargetSpeedView5(0x140, 0xC0);
            fieldA4State28 = &Physics26Player0View5 + 0xA4;
            vector8CState28 = fieldA4State28 - 0x18;
            workWord2 = Physics26InterpolateCosineView5(Physics26Field(fieldA4State28, int*, 0));
            workWord3 = Physics26Field(&Physics26Player0View5, int*, 0xB0);
            lowProduct3 = workWord3 * workWord2;
            call4 = (void*)Physics26Field(fieldA4State28, int*, 0);
            workWord2 = lowProduct3 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp10 = workWord2;
            workWord2 = Physics26InterpolateSineView5(call4);
            workWord3 = Physics26Field(&Physics26Player0View5, int*, 0xB0);
            lowProduct4 = workWord3 * workWord2;
            workWord2 = lowProduct4 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp14 = workWord2;
            Physics26SubtractVectorView5(&originalFrame.sp10, &originalFrame.sp10, vector8CState28);
            originalFrame.sp18 = 0;
            temp_v0_4 = Physics26MeasureVectorLengthView5(&originalFrame.sp10, 0);
            MATCHING_KEEP(fieldA4State28);
            var_a0_3 = fieldA4State28 - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics26ScaleVectorRatioQ15View5(&originalFrame.sp10, temp_v0_4, 0x280);
                MATCHING_KEEP(fieldA4State28);
                var_a0_3 = fieldA4State28 - 0x24;
            }
            Physics26AddVectorView5(var_a0_3, vector8CState28, &originalFrame.sp10);
            Physics26BuildPlayerResponseVectorView5();
            if (combinedIndex < 0xD) {
                MATCHING_OBSERVE(combinedIndex);
                nextField94 = Physics26Field(&Physics26Player0View5, int*, 0x94) + 0x17;
            } else {
                nextField94 = Physics26Field(&Physics26Player0View5, int*, 0x94) - 0xC0;
            }
            Physics26Player94View4 = nextField94;
            MATCHING_BARRIER_VOLATILE("memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer = &Physics26Player0View5 + 0x148;
                MATCHING_KEEP(globalPointer);
                particleIndex = 0;
                if (Physics26Field(globalPointer, int*, 0) != 0) {
                    workWord2 = combinedIndex * 4;
                    MATCHING_KEEP(workWord2);
                    particleThreshold = workWord2 + combinedIndex;
                    globalByteE = globalPointer - 0x13A;
                    vectorAt40 = &originalFrame.sp30;
                    MATCHING_KEEP(vectorAt40);
                spawnParticleLoop:
                    if (particleThreshold < (Physics26CallRandView4() & 0xFF)) {
                        workWord2 = Physics26RandSignedBetweenView4(0, 0xC);
                        call4 = globalByteE + 0x22;
                        workWord3 = *globalByteE;
                        MATCHING_KEEP(workWord3);
                        call5 = vectorAt40;
                        MATCHING_KEEP2(call4, call5);
                        workWord3 += 0x80;
                        MATCHING_KEEP(workWord3);
                        workWord3 += workWord2;
                        MATCHING_KEEP(workWord3);
                        workWord3 = (workWord3 & 0xFF) * 2;
                        signedTableWord = *(short*)(&Physics26Data65920View5 + workWord3);
                        call6 = vectorAt40;
                        originalFrame.sp20 = (int)(signedTableWord * 5) >> 0xA;
                        workWord3 = *(short*)(&Physics26Data658A0View5 + workWord3);
                        MATCHING_KEEP_VOLATILE_CLOBBER(workWord3, "memory");
                        originalFrame.sp28 = 0xE;
                        originalFrame.sp30 = -0x12C;
                        originalFrame.sp34 = 0;
                        originalFrame.sp38 = -0xC8;
                        MATCHING_BARRIER_VOLATILE("memory");
                        originalFrame.sp24 = (workWord3 * 5) >> 0xA;
                        Physics26TransformVectorByBasisView4(call4, call5, call6, signedTableWord);
                        originalFrame.sp30 += Physics26RandSignedBetweenView4(0, 0x50);
                        originalFrame.sp34 += Physics26RandSignedBetweenView4(0, 0x50);
                        originalFrame.sp38 += Physics26RandSignedBetweenView4(0, 0x50);
                        Physics26AddVectorView5(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 =
                            Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp20);
                        Physics26Field(temp_v0_5, signed char*, 2) = 8;
                        Physics26Field(temp_v0_5, signed char*, 0xA) = 0x20;
                    }
                    particleIndex += 1;
                    if (particleIndex < 2) {
                        goto spawnParticleLoop;
                    }
                }
            }
            break;
        case 108:
            globalFieldB8PointerState20 = &Physics26Player0View5 + 0xB8;
            if (Physics26Field(&Physics26Player0View5, int*, 0xB8) != 0) {
                vectorAt30 = &originalFrame.sp20;
                Physics26ClearVectorView5(vectorAt30);
                call4 = vectorAt30;
                call5 = vectorAt30;
                MATCHING_KEEP2(call4, call5);
                globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
                Physics26SubtractVectorView5(call4, call5, globalVector8CState20);
                originalFrame.sp28 = 0;
                temp_v0_6 = Physics26MeasureVectorLengthView5(&originalFrame.sp20, 0);
                if (temp_v0_6 >= 0x41) {
                    Physics26ScaleVectorRatioQ15View5(&originalFrame.sp20, temp_v0_6, 0x40);
                }
                originalFrame.sp28 = -0xC0;
                globalVector80State20 = globalFieldB8PointerState20 - 0x38;
                Physics26AddVectorView5(globalVector80State20, globalVector8CState20,
                                        &originalFrame.sp20);
                Physics26CopyVectorView5(globalVector8CState20, globalVector80State20);
            } else {
                Physics26ClearVectorView5(globalFieldB8PointerState20 - 0x38);
                Physics26ClearVectorView5(globalFieldB8PointerState20 - 0x2C);
            }
            if (Physics26Field(&Physics26Player0View5, int*, 0x94) < -0x2300) {
                Physics26Field(&Physics26Player0View5, int*, 0x94) = -0x2300;
            }
            if ((Physics26Field(&Physics26Player0View5, int*, 0x48) == 0x3A) &&
                (Controller88028_SpawnParticle != 0) && (Physics26Data6C640View5 & 1)) {
                originalFrame.sp40 = 0;
                originalFrame.sp44 = 0;
                originalFrame.sp48 = 0xE;
                Physics26CopyVectorView5(&originalFrame.sp50,
                                         (&Physics26Player0View5 + 0x94) - 0x94);
                originalFrame.sp50 += Physics26RandSignedBetweenView4(0, 0x12C);
                originalFrame.sp54 += Physics26RandSignedBetweenView4(0, 0x12C);
                originalFrame.sp58 += Physics26RandSignedBetweenView4(0, 0x12C);
                temp_v0_7 =
                    Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp50, &originalFrame.sp40);
                Physics26Field(temp_v0_7, signed char*, 2) = 6;
                Physics26Field(temp_v0_7, signed char*, 0xA) = 0x20;
            }
            break;
        case 105:
            globalVector80 = &Physics26Player0View6 + 0xB8;
            workWord2 = Physics26Field(globalVector80, int*, 0);
            if (!workWord2)
                goto zero105;
            vectorAt30 = &originalFrame.sp40;
            Physics26ClearVectorView6(vectorAt30);
            call4 = vectorAt30;
            call5 = vectorAt30;
            MATCHING_KEEP2(call4, call5);
            globalVector8CState20 = globalVector80 - 44;
            Physics26SubtractVectorView6(call4, call5, globalVector8CState20);
            originalFrame.sp48 = 0;
            call5 = (void*)Physics26MeasureVectorLengthView6(vectorAt30, 0);
            workWord2 = (int)call5 < 65;
            if (!workWord2)
                Physics26ScaleVectorRatioQ15View6(vectorAt30, call5, 64);
            originalFrame.sp48 = -192;
            globalVector80 -= 56;
            Physics26AddVectorView6(globalVector80, globalVector8CState20, vectorAt30);
            Physics26CopyVectorView6(globalVector8CState20, globalVector80);
            goto clamp104;
        zero105:
            Physics26ClearVectorView6(globalVector80 - 56);
            Physics26ClearVectorView6(globalVector80 - 44);
            goto clamp104;
        case 100:
            globalVector80 = &Physics26Player0View6 + 0x80;
            Physics26ClearVectorView6(globalVector80);
            Physics26ClearVectorView6(globalVector80 + 12);
            if (Physics26Data6E044View6 != 7) {
                Physics26UpdatePlayerGroundInputTargetsView6(3840);
                Physics26BlendPlayerHeadingFromInputVectorView6();
                Physics26ApproachPlayerTargetHeadingView6(90, 16);
            }
            workWord2 = Physics26Player1BAView2;
            if (!workWord2) {
                workWord2 = 1;
                goto byteOne;
            }
            workWord2 = Physics26Data6E538View4 & 16;
            if (workWord2) {
                workWord2 = 1;
                goto wordOneReturn;
            }
            workWord2 = 1;
            Physics26Player1BAView2 = 0;
            __asm__ volatile("" ::"i"(0x8008906C) : "memory");
            goto byteOne;
        case 101:
            workWord3 = Physics26Data6E044View6;
            workWord2 = 8;
            if (workWord3 != workWord2)
                Physics26UpdatePlayerGroundInputTargetsView6(3840);
            globalVector80 = &Physics26Data6E538View4;
            workWord2 = Physics26Field(globalVector80, int*, 0) & 12;
            if (workWord2)
                Physics26PlayerACView3 = 0;
            workWord2 = Physics26BlendPlayerHeadingFromInputVectorView6();
            call4 = (void*)90;
            call5 = (void*)16;
            MATCHING_KEEP2(call4, call5);
            globalFieldA4Pointer = (void*)workWord2;
            workWord2 = Physics26ApproachPlayerTargetHeadingView6(call4, call5);
            workWord3 = Physics26PlayerA8View3;
            if (workWord3 < 0)
                workWord3 = -workWord3;
            workWord3 = workWord3 < 8;
            __asm__("" : "=r"(workWord3) : "0"(workWord3), "r"(workWord2));
            call5 = (void*)workWord2;
            if (!workWord3)
                goto reset101;
            workWord2 = Physics26Field(globalVector80, int*, 0) & 12;
            if (!workWord2)
                goto reset101;
            workWord2 = Physics26Player144View3;
            workWord2++;
            Physics26Player144View3 = workWord2;
            goto saved101;
        reset101:
            Physics26Player144View3 = 0;
        saved101:
            call4 = &Physics26PlayerACView3;
            globalVector80 = (void*)Physics26Field(call4, int*, 0);
            if (globalFieldA4Pointer)
                goto collision101;
            workWord2 = (int)call5;
            if ((int)call5 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 513;
            if (workWord2)
                goto pass101;
        collision101:
            workWord2 = Physics26Player20CView2 & 64;
            if (workWord2)
                Physics26Field(call4, int*, 0) = 0;
            else {
                workWord3 = Physics26PlayerB0View3;
                workWord2 = workWord3 < (int)globalVector80;
                if (workWord2)
                    Physics26Field(call4, int*, 0) = workWord3;
            }
        pass101:
            Physics26ApproachPlayerTargetSpeedView6(256, 384);
            workWord2 = Physics26Player101View2;
            call4 = &Physics26PlayerACView3;
            Physics26Field(call4, int*, 0) = (int)globalVector80;
            if (workWord2) {
                Physics26ClearVectorView6(call4 - 32);
                goto fields101;
            }
            Physics26BuildPlayerMovementVectorView4(call4);
            Physics26BuildPlayerResponseVectorView6();
        fields101:
            call6 = &Physics26PlayerFCView3;
            workWord2 = Physics26Field(call6, unsigned char*, 0);
            if (workWord2)
                goto field94FromA0;
            workWord2 = Physics26PlayerB8View3;
            call4 = call6 - 112;
            if (!workWord2)
                goto commit101;
        field94FromA0:
            workWord2 = Physics26PlayerA0View3;
            workWord2 -= 192;
            Physics26Player94View5 = workWord2;
            return;
        commit101:
            call5 = call4;
        vectorCommit61:
            Physics26AddVectorView6(call4, call5, call6 - 20);
            return;
        case 102:
        case 103:
        case 106: {
            register int limit17 __asm__("$17");
            register int numeric5 __asm__("$5");
            Physics26UpdatePlayerGroundInputTargetsView6(6400);
            workWord2 = Physics26Data6E538View4;
            workWord3 = workWord2 & 12;
            if (workWord3)
                goto held106;
            workWord2 = Physics26Absolute12BitAngleDeltaView3(Physics26PlayerA4View2,
                                                              Physics26Player64View3);
            workWord2 = workWord2 < 1665;
            if (workWord2)
                Physics26ApproachPlayerTargetHeadingView6(44, 6);
            limit17 = 80;
            goto move106;
        held106:
            workWord2 = 8;
            if (workWord3 != workWord2)
                goto other106;
            workWord2 = Physics26Data6E040View3;
            workWord3 = 6400;
            Physics26PlayerACView3 = workWord3;
            workWord2 -= 1024;
            goto heading106;
        other106:
            workWord2 = 4;
            limit17 = 320;
            if (workWord3 != workWord2)
                goto move106;
            workWord2 = Physics26Data6E040View3;
            workWord3 = 6400;
            Physics26PlayerACView3 = workWord3;
            workWord2 += 1024;
        heading106:
            Physics26PlayerA4View2 = workWord2;
            limit17 = 320;
        move106:
            Physics26ApproachPlayerTargetSpeedView6(256, 384);
            globalVector8C = &Physics26Player210View3;
            workWord2 = Physics26Field(globalVector8C, int*, 0) & 1024;
            if (workWord2)
                goto clamp106;
            call4 = (void*)Physics26PlayerA4View2;
            globalVector8CState20 = globalVector8C - 388;
            workWord2 = Physics26InterpolateCosineView6(call4);
            workWord3 = Physics26PlayerB0View3;
            lowProduct5 = workWord3 * workWord2;
            call4 = (void*)Physics26PlayerA4View2;
            workWord2 = lowProduct5 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp60 = workWord2;
            workWord2 = Physics26InterpolateSineView6(call4);
            workWord3 = Physics26PlayerB0View3;
            lowProduct6 = workWord3 * workWord2;
            call4 = globalVector8CState20;
            call5 = globalVector8C - 376;
            workWord2 = lowProduct6 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp64 = workWord2;
            Physics26CopyVectorView6(call4, call5);
            globalVector80 = &originalFrame.sp60;
            Physics26SubtractVectorView6(globalVector80, globalVector80, globalVector8CState20);
            originalFrame.sp68 = 0;
            call5 = (void*)Physics26MeasureVectorLengthView6(globalVector80, 0);
            workWord2 = limit17 < (int)call5;
            if (workWord2)
                Physics26ScaleVectorRatioQ15View6(globalVector80, call5, limit17);
            Physics26AddVectorView6(globalVector8C - 400, globalVector8CState20, globalVector80);
            Physics26BuildPlayerResponseVectorView6();
            workWord2 = (int)Physics26Data6C570View5;
            workWord2 = Physics26Field((void*)workWord2, int*, 0) & 64;
            if (workWord2)
                Physics26Player144View3 = 0;
            else {
                workWord2 = Physics26Player144View3;
                workWord2++;
                Physics26Player144View3 = workWord2;
            }
            workWord2 = Physics26Player144View3;
            workWord2 = workWord2 < 10;
            if (workWord2) {
                workWord2 = Physics26Player94View5;
                workWord2 += 256;
                goto store106;
            }
            workWord2 = Physics26Player94View5;
            workWord2 -= 96;
        store106:
            Physics26Player94View5 = workWord2;
            workWord2 = Physics26PlayerF8View3;
            workWord3 = Physics26Player8View3;
            numeric5 = workWord2 - workWord3;
            workWord2 = numeric5 < 4096;
            workWord3 = numeric5 << 2;
            if (!workWord2)
                goto mode106;
            workWord2 = Physics26Player94View5;
            workWord2 = workWord3 < workWord2;
            if (workWord2)
                Physics26Player94View5 = workWord3;
        mode106:
            workWord3 = Physics26Player4CView3;
            workWord2 = 127;
            if (workWord3 == workWord2)
                goto clamp106;
            call4 = &Physics26Data676E8View3;
            workWord2 = Physics26Data6C58CView3;
            workWord3 = Physics26Data6C5C8View3;
            workWord2 <<= 4;
            workWord2 += (int)call4;
            workWord3 <<= 2;
            workWord3 += workWord2;
            workWord2 = Physics26Player8View3;
            workWord3 = Physics26Field((void*)workWord3, int*, 0);
            workWord2 -= workWord3;
            numeric5 = workWord2 - 1024;
            workWord2 = numeric5 < 4096;
            workWord3 = -numeric5;
            if (workWord2) {
                workWord2 = Physics26Player94View5;
                MATCHING_OBSERVE2(workWord3, workWord2);
                workWord3 <<= 1;
                workWord2 = workWord2 < workWord3;
                if (workWord2)
                    Physics26Player94View5 = workWord3;
            }
        clamp106:
            globalPointer = &Physics26Player94View5;
            workWord2 = Physics26Field(globalPointer, int*, 0);
            workWord2 = workWord2 < -4480;
            if (workWord2) {
                workWord2 = -4480;
                Physics26Field(globalPointer, int*, 0) = workWord2;
            }
            workWord2 = Physics26Field(globalPointer, int*, 0);
            workWord2 = workWord2 < 1921;
            if (!workWord2) {
                workWord2 = 1920;
                Physics26Field(globalPointer, int*, 0) = workWord2;
            }
            return;
        }
        case 104: {
            register int numeric5 __asm__("$5");
            Physics26ClearVectorView6(&originalFrame.sp70);
            raw13_temp_s1_4 = &Physics26Player0View6 + 0x8C;
            Physics26SubtractVectorView6(&originalFrame.sp70, &originalFrame.sp70, raw13_temp_s1_4);
            if (Physics26PlayerB8View3 != 0) {
                originalFrame.sp78 = 0;
                raw13_temp_v0_15 = Physics26MeasureVectorLengthView6(&originalFrame.sp70, 0);
                if (raw13_temp_v0_15 >= 0x41) {
                    Physics26ScaleVectorRatioQ15View6(&originalFrame.sp70, raw13_temp_v0_15, 0x40);
                }
            } else {
                raw13_temp_v0_16 = Physics26MeasureVectorLengthView6(&originalFrame.sp70, 1);
                if (raw13_temp_v0_16 >= 0x101) {
                    Physics26ScaleVectorRatioQ15View6(&originalFrame.sp70, raw13_temp_v0_16, 0x100);
                }
                Physics26AddVectorView6(raw13_temp_s1_4, raw13_temp_s1_4, &originalFrame.sp70);
            }
            raw13_temp_s0_9 = &Physics26Player0View6 + 0x80;
            raw13_temp_s1_5 = raw13_temp_s0_9 + 0xC;
            originalFrame.sp78 = -0xC0;
            Physics26AddVectorView6(raw13_temp_s0_9, raw13_temp_s1_5, &originalFrame.sp70);
            Physics26CopyVectorView6(raw13_temp_s1_5, raw13_temp_s0_9);
            call4 = &Physics26Data676E8View3;
            workWord2 = Physics26Data6C58CView3;
            workWord3 = Physics26Data6C5C8View3;
            workWord2 <<= 4;
            workWord2 += (int)call4;
            workWord3 <<= 2;
            workWord3 += workWord2;
            workWord2 = Physics26Player8View3;
            workWord3 = Physics26Field((void*)workWord3, int*, 0);
            workWord2 -= workWord3;
            numeric5 = workWord2 - 1024;
            workWord2 = numeric5 < 4096;
            workWord3 = -numeric5;
            if (workWord2) {
                workWord2 = Physics26Player94View5;
                MATCHING_OBSERVE2(workWord3, workWord2);
                workWord3 <<= 1;
                workWord2 = workWord2 < workWord3;
                if (workWord2)
                    Physics26Player94View5 = workWord3;
            }
        clamp104:
            globalPointer = &Physics26Player94View5;
            workWord2 = Physics26Field(globalPointer, int*, 0);
            workWord2 = workWord2 < -8960;
            if (!workWord2)
                return;
            workWord2 = -8960;
            Physics26Field(globalPointer, int*, 0) = workWord2;
            return;
        }
        case 109:
            globalVector80 = &Physics26Player0View6 + 0x80;
            Physics26ClearVectorView6(globalVector80);
            Physics26ClearVectorView6(globalVector80 + 12);
            workWord2 = Physics26Player1BAView2;
            if (!workWord2) {
                workWord2 = 1;
                goto byteOne;
            }
            workWord2 = Physics26Data6E538View4 & 16;
            if (workWord2) {
                workWord2 = 1;
                goto wordOneReturn;
            }
            workWord2 = 1;
            Physics26Player1BAView2 = 0;
        byteOne:
            Physics26Player1B9View2 = workWord2;
        wordOneReturn:
            MATCHING_OBSERVE(workWord2);
            return;
    }
}
#undef Physics26Field


/* AI generated; not human reviewed. SCUS-94467 USA Rev0 80089710.
 * Reuses verified13 child/vector and descriptor routes; original26 selectors
 * 64..6D and shared numeric tails preserved. Byte offsets private30 child,
 * child38 halfword, source74+24/-74/+58 and descriptor table6 remain numeric.
 * Signed halfword-2/0/2 maps-1/0/1 via original16/17 shifts. Division vector
 * -7/0/7 by2 gives-3/0/3; original zero/overflow traps retained.
 * Empty constraints emit no instructions. All original code/internal jumps/
 * dispatch words, strict full TU and every original EXE/overlay hash required.
 * Units, helper meanings, audio semantics, cadence and live parity remain open.
 */
extern Spyro Callback26Player __asm__("D_80070328");
int Callback26SoundHandleMatchesIdInStates1Or2(int soundId, int index) __asm__("func_8003BF6C");
void Callback26ProbePlayerContactSegment(void) __asm__("func_80041930");
void Callback26UpdatePlayerCollisionResponse(void) __asm__("func_80041C20");
void Callback26UpdatePlayerSurfaceState(void) __asm__("func_80042A44");
void Callback26BuildNegatedNormalizedPlayerVectorAlias(int scale) __asm__("func_80043A38");
extern int D_8006C648;
int Callback26Query(Vector3D*, int) __asm__("func_8001A358");
extern unsigned char* Callback26Table[] __asm__("D_8006EE2C");
extern unsigned char Callback26Source[] __asm__("D_80070328+0x74");
extern int D_80071908;
extern Vector3D D_80071918;
void Callback26ShiftVectorRightTowardZero(Vector3D*, int) __asm__("func_8004F110");
int Callback26ResolveMobyMotionCollision(Moby*, Vector3D*, int, int, int) __asm__("func_80038000");
void Callback26SubtractVector(Vector3D*, Vector3D*, Vector3D*) __asm__("func_8004F1C8");
void Callback26TransitionSoundHandleTo3Or5(int) __asm__("func_8003BE70");
void func_level_26_80089710(void) {
    Vector3D localVector;
    int reserved;
    Vector3D copyVector;
    register Moby* descriptorMoby __asm__("$2");
    register unsigned int selector __asm__("$16");


    switch (Callback26Player.animationState) {
        case 0x64:
            if (func_800438F4() == 0)
                func_80043728();
            Callback26UpdatePlayerCollisionResponse();
            Callback26Player.unk9a = 0;
            goto call42A44;
        case 0x67:
        case 0x69:
        case 0x6C:
            Callback26UpdatePlayerCollisionResponse();
        call42A44:
            Callback26UpdatePlayerSurfaceState();
        clearSharedValue:
            Callback26Player.unk4[0] = 0;
            return;
        case 0x66:
            Callback26UpdatePlayerCollisionResponse();
            Callback26UpdatePlayerSurfaceState();
            descriptorMoby = Callback26Player.critterMobyPtr;
            MATCHING_KEEP_VOLATILE_CLOBBER(descriptorMoby, "memory");
            Callback26Player.unk4[0] = 0;
            goto descriptorTail;
        case 0x65:
            func_800438F4();
            Callback26UpdatePlayerCollisionResponse();
            Callback26UpdatePlayerSurfaceState();
            Callback26ProbePlayerContactSegment();
            goto queryC00;
        case 0x68:
            Callback26UpdatePlayerCollisionResponse();
            Callback26UpdatePlayerSurfaceState();
        queryC00:
            Callback26BuildNegatedNormalizedPlayerVectorAlias(0xC00);
            goto clearSharedValue;
        case 0x6B:
            Callback26UpdatePlayerCollisionResponse();
            Callback26UpdatePlayerSurfaceState();
            Callback26ProbePlayerContactSegment();
            if (Callback26Player.unk7a[3].z < 0 && Callback26Player.animationStateFrames >= 4)
                Callback26Player.unk5 = 1;
            goto clearSharedValue;
        case 0x6A:
        case 0x6D: {
            register unsigned char* privateData __asm__("$16") =
                Callback26Player.critterMobyPtr->mobyTag;
            register int changed __asm__("$19") = 0;
            register Vector3D* copyBase __asm__("$17");
            register unsigned char* sourceBase __asm__("$18");
            register int queryHeight __asm__("$16");
            if (*(Moby**)(privateData + 0x30) != 0) {
                sourceBase = Callback26Source;
                func_8004F178((&localVector), (Vector3D*)sourceBase);
                Callback26ShiftVectorRightTowardZero((&localVector), 6);
                {
                    Moby* child = *(Moby**)(privateData + 0x30);
                    child->position.z +=
                        ((int)((unsigned int)*(unsigned short*)((unsigned char*)child + 0x38)
                               << 16)) >>
                        17;
                }
                func_8004F194((&localVector), (&localVector),
                              (Vector3D*)((unsigned char*)*(Moby**)(privateData + 0x30) + 0xC));
                copyBase = &copyVector;
                func_8004F178(copyBase, (&localVector));
                {
                    int height =
                        ((int)((unsigned int)*(
                                   unsigned short*)((unsigned char*)*(Moby**)(privateData + 0x30) +
                                                    0x38)
                               << 16)) >>
                        17;
                    register int result = Callback26ResolveMobyMotionCollision(
                        *(Moby**)(privateData + 0x30), (&localVector), height, height, 0x1022);
                    register Vector3D* childVector __asm__("$4") = (&localVector);
                    if (result != 0) {
                        register Vector3D* childCopy __asm__("$6") = copyBase;
                        {
                            register Moby* childArgument __asm__("$5") =
                                *(Moby**)(privateData + 0x30);
                            MATCHING_KEEP_VOLATILE_CLOBBER(changed, "memory");
                            changed = 1;
                            Callback26SubtractVector(
                                childVector, (Vector3D*)((unsigned char*)childArgument + 0xC),
                                childCopy);
                        }
                        func_8004F0E8((&localVector), 6);
                        func_8004F194((Vector3D*)sourceBase, (Vector3D*)sourceBase, (&localVector));
                    }
                }
                Callback26UpdatePlayerCollisionResponse();
                {
                    register Vector3D* argument0 __asm__("$4") = (Vector3D*)(sourceBase + 0x24);
                    if (changed != 0) {
                        register int componentX __asm__("$8") = localVector.x;
                        register int divisor __asm__("$2") = D_8006C648;
                        register int componentY __asm__("$7");
                        register int componentZ __asm__("$3");
                        componentX /= divisor;
                        MATCHING_KEEP(componentX);
                        componentY = localVector.y / divisor;
                        MATCHING_KEEP(componentY);
                        componentZ = localVector.z / divisor;
                        MATCHING_KEEP2_VOLATILE_CLOBBER(componentZ, argument0, "memory");
                        localVector.x = componentX;
                        localVector.y = componentY;
                        localVector.z = componentZ;
                        Callback26SubtractVector(argument0, argument0, (&localVector));
                    }
                }
                {
                    register Moby* child __asm__("$2") = *(Moby**)(privateData + 0x30);
                    register int childValue __asm__("$3") = *(short*)((unsigned char*)child + 0x38);
                    register int playerValue __asm__("$2") = Callback26Player.unk4a;
                    playerValue += childValue;
                    MATCHING_KEEP(playerValue);
                    queryHeight = playerValue + 64;
                }
                if (Callback26Query((Vector3D*)(sourceBase - 0x74), queryHeight) != 0 &&
                    Callback26Player.unk7a[2].z <= 0) {
                    if (Callback26Player.unk7a[2].z >= -2047)
                        Callback26Player.position.z = D_80071908 + queryHeight - 64;
                    Callback26Player.ticksSinceLastSurfaceTouch = 0;
                    func_8004F178((Vector3D*)(sourceBase + 0x58), &D_80071918);
                } else {
                    register int* counterPointer __asm__("$2") =
                        &Callback26Player.ticksSinceLastSurfaceTouch;
                    register int counterValue __asm__("$3");
                    register int vectorZ __asm__("$4");
                    MATCHING_KEEP(counterPointer);
                    Callback26Player.unk9e.x = 0;
                    Callback26Player.unk9e.y = 0;
                    counterValue = *counterPointer;
                    MATCHING_KEEP_VOLATILE_CLOBBER(counterPointer, "memory");
                    vectorZ = 4096;
                    Callback26Player.unk9e.z = vectorZ;
                    counterValue += 1;
                    *counterPointer = counterValue;
                }
            } else
                Callback26UpdatePlayerCollisionResponse();
            Callback26Player.unk4[0] = 0;
            if (Callback26Player.animationState != 0x6A)
                return;
            descriptorMoby = Callback26Player.critterMobyPtr;
        descriptorTail:
            selector = Callback26Table[descriptorMoby->mobyClass][6];
            if (selector != (unsigned int)Callback26Player.unk22[3]) {
                if (Callback26SoundHandleMatchesIdInStates1Or2(Callback26Player.unk22[3],
                                                               Callback26Player.unk22[2]) != 0)
                    Callback26TransitionSoundHandleTo3Or5(Callback26Player.unk22[2]);
                Callback26Player.unk22[2] = -1;
            }
            Callback26Player.unk22[3] = selector;
            if (Callback26SoundHandleMatchesIdInStates1Or2(selector, Callback26Player.unk22[2]) ==
                0)
                Callback26Player.unk22[2] = PlaySound(Callback26Player.unk22[3], 0, 4);
            return;
        }
        default:
            return;
    }
}




#define LEVEL_ID 26
#define PlaySpyroSounds_level_26 func_level_26_80089BC4
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_level_26_80089CEC(int index) {
    Vector3D* position;
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
        case 0x64:
        case 0x65:
        case 0x68:
        case 0x69:
        case 0x6C:
        case 0x6D:
            position = &spyro.unk9e;
            break;
        case 0x66:
        case 0x67:
        case 0x6A:
        case 0x6B:
            position = 0;
            break;
        default:
            return;
    }
    func_80043ABC(position);
}

extern Spyro Callback26_D_80070328 __asm__("D_80070328");
extern short Callback26_D_800658A0[], Callback26_D_80065920[] __asm__("D_800658A0");
int Callback26MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
void Callback26BuildNegatedNormalizedPlayerVector(int scale) __asm__("func_80043A38");
void Callback26ClearPlayerMotionVectors(void) __asm__("func_800441F0");
void Callback26ShiftVectorLeft(Vector3D*, int) __asm__("func_8004F0E8");
void Callback26ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Callback26_D_8006E524 __asm__("D_8006E524");

void func_level_26_80089D68(int arg0) {
    register int tableOffsetOrValue __asm__("$2");
    register int tableValueA __asm__("$3");
    register unsigned char* savedBase __asm__("$3");
    register unsigned char* hurtBase __asm__("$5");
    register Vector3D* destination __asm__("$4");
    register int flags __asm__("$3");
    register int hurtState __asm__("$3");
    register Vector3D* sourceA __asm__("$16");
    register Vector3D* sourceB __asm__("$16");
    register int savedMovementA __asm__("$6");
    register int savedMovementB __asm__("$2");

    switch (arg0) {
        case 0x64:
        case 0x6D:
            Callback26_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Callback26_D_80070328.unk5 = 0;
            Callback26ClearPlayerMotionVectors();
            Callback26_D_80070328.grounded = 1;
            return;
        case 0x65:
            Callback26_D_80070328.movementState = MOVEMENT_STATE_WALK;
            if ((arg0 == 0x57) && (Callback26_D_80070328.ticksSinceLastSurfaceTouch != 0)) {
                func_8004F178(
                    (Vector3D*)((unsigned char*)&Callback26_D_80070328.movementState + 0x3C),
                    (Vector3D*)((unsigned char*)&Callback26_D_80070328.movementState + 0x48));
                Callback26_D_80070328.unk5 = 1;
            } else {
                Callback26_D_80070328.unk5 = 0;
            }
            Callback26_D_80070328.unk8[0] =
                Callback26MeasureVectorLength(&Callback26_D_80070328.unk7a[3], 0);
            Callback26BuildNegatedNormalizedPlayerVector(0xC00);
            Callback26_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Callback26_D_80070328.grounded = 1;
            goto clearTail;
        case 0x69:
            Callback26_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Callback26_D_80070328.unk5 = 0;
            Callback26BuildNegatedNormalizedPlayerVector(0xC00);
            Callback26_D_80070328.grounded = 1;
            goto storeCommonValue;
        case 0x66:
        case 0x67:
        case 0x6A:
            Callback26_D_80070328.movementState = MOVEMENT_STATE_FALL;
            Callback26_D_80070328.unk8[0] = Callback26MeasureVectorLength(
                (Vector3D*)((unsigned char*)&Callback26_D_80070328.movementState + 0x48), 0);
            Callback26_D_80070328.unk15b = 1;
            Callback26_D_80070328.grounded = 0;
            Callback26_D_80070328.union144.a.unk13cb = 0x14;
        clearTail:
            Callback26_D_80070328.idle = 0;
            Callback26_D_80070328.unk15g = 0;
            return;
        case 0x6B:
            savedBase = Raw26Union;
            MATCHING_KEEP(savedBase);
            destination = (Vector3D*)(savedBase - 0xB8);
            MATCHING_KEEP(destination);
            sourceA = (Vector3D*)(savedBase - 0xAC);
            savedMovementA = Raw26Movement;
            Raw26Movement = MOVEMENT_STATE_HURT;
            Callback26_D_80070328.unk5 = 0;
            *(int*)savedBase = savedMovementA;
            func_8004F178(destination, sourceA);
            Callback26_D_80070328.unk8[0] = Callback26MeasureVectorLength(sourceA, 0);
            Callback26_D_80070328.unk7a[2].z = 0xDC0;
            Callback26_D_80070328.grounded = 0;
            Callback26_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            if (Callback26_D_80070328.damageFlags & 0x200) {
                Callback26_D_80070328.union144.a.unk13cc = 0;
                return;
            }
            Callback26_D_80070328.union144.a.unk13cc = 1;
            PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            return;
        case 0x6C:
            Callback26_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Callback26_D_80070328.unk5 = 0;
            Callback26BuildNegatedNormalizedPlayerVector(0xC00);
            Callback26_D_80070328.grounded = 1;
            if ((arg0 == 0x3A) || (arg0 == 0x6C)) {
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
        storeCommonValue:
            Callback26_D_8006E524 = 0xF;
            return;
        case 0x68:
            savedMovementB = Raw26Movement;
            MATCHING_KEEP(savedMovementB);
            hurtState = 7;
            Raw26Movement = hurtState;
            flags = Callback26_D_80070328.unk17a;
            MATCHING_KEEP(flags);
            hurtBase = Raw26Union;
            MATCHING_KEEP(hurtBase);
            Callback26_D_80070328.unk5 = 0;
            MATCHING_KEEP_GNU_VOLATILE_CLOBBER(flags, "memory");
            *(int*)hurtBase = savedMovementB;
            if (flags & 0x400) {
                sourceB = (Vector3D*)(hurtBase - 0xB8);
                func_8004F178(sourceB, (Vector3D*)(hurtBase + 0xD8));
                Callback26ShiftVectorLeft(sourceB, 6);
            } else if (Callback26_D_80070328.unk22[5] >= 0) {
                tableOffsetOrValue = Callback26_D_80070328.unk22[5] * 2;
                tableValueA = *(short*)((unsigned char*)Signed26B + tableOffsetOrValue);
                MATCHING_KEEP(tableValueA);
                Callback26_D_80070328.unk7a[2].x = tableValueA >> 1;
                tableOffsetOrValue = *(short*)((unsigned char*)Signed26A + tableOffsetOrValue);
                Callback26_D_80070328.unk7a[2].z = 0;
                MATCHING_KEEP_GNU_VOLATILE_CLOBBER(tableOffsetOrValue, "memory");
                Callback26_D_80070328.unk7a[2].y = tableOffsetOrValue >> 1;
            } else {
                Callback26ClearVector((Vector3D*)(hurtBase - 0xB8));
            }
            func_8004F178(&Callback26_D_80070328.unk7a[1],
                          (Vector3D*)((unsigned char*)&Callback26_D_80070328.unk7a[1] + 0xC));
            Callback26_D_80070328.grounded = 1;
            Callback26_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }

        default:
            return;
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 original
 * func_level_26_8008A144:441 instructions and10 dispatch words, evidence4888.
 * Verified animation selector/input handler idioms reused; raw100..109 states
 * follow original private pointer, callback and numeric branch chains.
 * Field units, helper meanings and update cadence unresolved. Acceptance:
 * every original native/internal-target/table word and full retail hashes. */
#define A4891Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
extern int A4891W48 __asm__("D_80070328 + 0x48");
extern unsigned char* A4891W250 __asm__("D_80070328 + 0x250");
extern volatile int A4891Buttons __asm__("D_8006E538");
extern unsigned char A4891E535 __asm__("D_8006E535");
extern int A4891WB8 __asm__("D_80070328 + 0xB8");
extern int A4891WE4 __asm__("D_80070328 + 0xE4");
extern int A4891WA8 __asm__("D_80070328 + 0xA8");
extern int A4891WAC __asm__("D_80070328 + 0xAC");
extern int A4891WB0 __asm__("D_80070328 + 0xB0");
extern int A4891W144 __asm__("D_80070328 + 0x144");
extern int A4891WA0 __asm__("D_80070328 + 0xA0");
extern int A4891W8 __asm__("D_80070328 + 8");
extern int A4891W4C __asm__("D_80070328 + 0x4C");
extern int A4891W94 __asm__("D_80070328 + 0x94");
extern int A4891W54 __asm__("D_80070328 + 0x54");
extern int A4891WCC __asm__("D_80070328 + 0xCC");
extern int A4891W8C __asm__("D_80070328 + 0x8C");
extern int A4891WD0 __asm__("D_80070328 + 0xD0");
extern int A4891W90 __asm__("D_80070328 + 0x90");
extern int A4891WD4 __asm__("D_80070328 + 0xD4");
extern unsigned char A4891Table[] __asm__("D_800676E8");
extern int A4891Row __asm__("D_8006C58C"), A4891Column __asm__("D_8006C5C8");
extern int (*A4891Callback)(int) __asm__("unk_ovlheader_8007431C");
void A4891Select(int) __asm__("func_8004BEF8");
void A4891UpdatePlayerRetryState(void) __asm__("func_800498C0");

void func_level_26_8008A144(void) {
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int selector4 __asm__("$4");
    register int product5 __asm__("$5");
    register unsigned char* private16 __asm__("$16");
    register unsigned char* object4 __asm__("$4");
    register unsigned char* table4 __asm__("$4");
    register int (*callback3)(int) __asm__("$3");

    work2 = A4891W48;
    switch (work2) {
        case 100:
            work2 = (int)A4891W250;
            callback3 = A4891Callback;
            private16 = A4891Field((void*)work2, unsigned char**, 0);
            if (callback3(25))
                return;
            work2 = A4891Field(private16, int*, 0x30);
            selector4 = 106;
            if (work2)
                goto select;
            work3 = A4891Buttons;
            work2 = work3 & 64;
            selector4 = 102;
            if (work2)
                goto select;
            work2 = A4891WB8 < 4;
            selector4 = 103;
            if (!work2)
                goto select;
            if (A4891WE4 >= 23)
                goto select;
            work2 = A4891WA8;
            if (work2 < 0)
                work2 = -work2;
            if (work2 >= 17) {
                MATCHING_BARRIER_VOLATILE("memory");
                selector4 = 101;
                goto select;
            }
            work2 = work3 & 12;
            if (work2)
                return;
            work2 = A4891WAC;
            selector4 = 101;
            if (!work2)
                return;
            goto select;

        case 101:
            work2 = (int)A4891W250;
            callback3 = A4891Callback;
            private16 = A4891Field((void*)work2, unsigned char**, 0);
            if (callback3(25))
                return;
            work2 = A4891Field(private16, int*, 0x30);
            selector4 = 106;
            if (work2)
                goto select;
            work2 = A4891Buttons & 64;
            selector4 = 102;
            if (work2)
                goto select;
            work2 = A4891WB8 < 4;
            selector4 = 103;
            if (!work2)
                goto select;
            if (A4891WE4 >= 23)
                goto select;
            if (A4891E535) {
                work2 = A4891WB0;
                selector4 = 100;
                if (!work2)
                    goto select;
            }
            if (!(A4891Buttons & 12))
                return;
            work2 = A4891W144 < 16;
            selector4 = 100;
            if (work2)
                return;
            goto select;

        case 102:
            work2 = (int)A4891W250;
            callback3 = A4891Callback;
            private16 = A4891Field((void*)work2, unsigned char**, 0);
            if (callback3(25))
                return;
            work2 = A4891Field(private16, int*, 0x30);
            selector4 = 106;
            if (work2)
                goto select;
            if (!A4891WB8 && A4891WA0 <= 0) {
                MATCHING_BARRIER_VOLATILE("memory");
                if (A4891WE4 >= 23)
                    return;
                work2 = A4891WAC;
                selector4 = 101;
                if (work2)
                    goto select;
                MATCHING_BARRIER_VOLATILE("memory");
                selector4 = 100;
                goto select;
            }
            if (A4891W144 < 11)
                return;
            table4 = A4891Table;
            work2 = A4891Row;
            work3 = A4891Column;
            work2 = (work2 << 4) + (int)table4;
            work3 = (work3 << 2) + work2;
            work2 = A4891W8;
            work3 = A4891Field((void*)work3, int*, 0);
            work2 -= work3;
            if (work2 <= 4096)
                return;
            work3 = A4891W4C;
            selector4 = 103;
            if (work3 == 127)
                return;
            goto select;

        case 103:
            work2 = (int)A4891W250;
            callback3 = A4891Callback;
            private16 = A4891Field((void*)work2, unsigned char**, 0);
            if (callback3(25))
                return;
            work2 = A4891Field(private16, int*, 0x30);
            selector4 = 106;
            if (work2)
                goto select;
            work2 = A4891Buttons & 64;
            selector4 = 102;
            if (work2)
                goto select;
            if (!A4891WB8) {
                if (A4891WE4 >= 23)
                    return;
                work2 = A4891WAC;
                selector4 = 101;
                if (work2)
                    goto select;
                selector4 = 100;
                goto select;
            }
            table4 = A4891Table;
            work2 = A4891Row;
            work3 = A4891Column;
            work2 = (work2 << 4) + (int)table4;
            work3 = (work3 << 2) + work2;
            work2 = A4891W8;
            work3 = A4891Field((void*)work3, int*, 0);
            work2 -= work3;
            selector4 = 102;
            if (work2 >= 4096)
                return;
            goto select;

        case 104:
            object4 = A4891W250;
            work2 = A4891W48;
            work3 = A4891Field(object4, unsigned char*, 0x3C);
            work2 -= 100;
            if (work3 != work2)
                return;
            work2 = A4891Field(object4, unsigned char*, 0x42) & 2;
            if (!work2)
                return;
            work2 = A4891WB8;
            selector4 = 100;
            if (!work2)
                goto select;
            selector4 = 103;
            goto select;

        case 105:
        case 108:
            object4 = A4891W250;
            work2 = A4891W48;
            work3 = A4891Field(object4, unsigned char*, 0x3C);
            work2 -= 100;
            if (work3 != work2)
                return;
            work2 = A4891Field(object4, unsigned char*, 0x42) & 2;
            if (!work2)
                return;
            A4891UpdatePlayerRetryState();
            return;

        case 106:
            work2 = (int)A4891W250;
            callback3 = A4891Callback;
            private16 = A4891Field((void*)work2, unsigned char**, 0);
            if (callback3(25))
                return;
            if (!A4891Field(private16, int*, 0x30)) {
                work2 = A4891Buttons & 64;
                selector4 = 102;
                if (work2)
                    goto select;
                selector4 = 103;
                goto select;
            }
            if (A4891WB8)
                return;
            work2 = A4891W94;
            if (work2 > 0)
                return;
            work2 = -(work2 << 1) >> 2;
            A4891W94 = work2;
            A4891WA0 = work2;
            selector4 = 109;
            if (work2 >= 1024)
                return;
            goto select;

        case 107:
            if (!A4891WB8 && A4891W54 >= 16) {
                if (A4891WE4 >= 23)
                    return;
                work3 = A4891WCC;
                work2 = A4891W8C;
                product5 = work3 * work2;
                work3 = A4891WD0;
                work2 = A4891W90;
                selector4 = work3 * work2;
                work3 = A4891WD4;
                work2 = A4891W94;
                work3 *= work2;
                work2 = product5 + selector4;
                work2 += work3;
                if (work2 >= 0)
                    return;
                work2 = A4891WAC;
                selector4 = 100;
                if (!work2)
                    goto select;
                selector4 = 101;
                goto select;
            }
            work2 = A4891Buttons & 64;
            if (work2 && A4891W4C == 1) {
                selector4 = 102;
                goto select;
            }
            object4 = A4891W250;
            work2 = A4891W48;
            work3 = A4891Field(object4, unsigned char*, 0x3C);
            work2 -= 100;
            if (work3 != work2)
                return;
            work2 = A4891Field(object4, unsigned char*, 0x42) & 2;
            if (!work2)
                return;
            selector4 = 103;
            goto select;

        case 109:
            work2 = (int)A4891W250;
            callback3 = A4891Callback;
            private16 = A4891Field((void*)work2, unsigned char**, 0);
            if (callback3(25))
                return;
            if (!A4891Field(private16, int*, 0x30) || A4891WB8 >= 4) {
                MATCHING_BARRIER_VOLATILE("memory");
                selector4 = 103;
                goto select;
            }
            work2 = A4891Buttons & 64;
            selector4 = 102;
            if (work2)
                goto select;
            MATCHING_BARRIER("$4");
            if (A4891E535)
                return;
            A4891WA0 = 1536;
            selector4 = 102;
            goto select;
    }
    return;
select:
    A4891Select(selector4);
}
#undef A4891Field
