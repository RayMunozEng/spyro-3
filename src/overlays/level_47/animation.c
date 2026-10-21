#include "matching.h"
#include "common.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original8008BBD8.
 * Assembly SHA256 ba404c30144065e7261339c9d40c046c3c7b09a56ddd748e5bbefacfd29dd186.
 * AI-generated; not human reviewed. All953 original instructions,
 * 42 selectors bias19 and 0 owned padding words are required.
 * Original frame0xA8; every concrete field width and producer is retained.
 * Four exact groups reuse11/12; near29/27 reuse original34/50 rows.
 * Original scratch10..8C,savedS0..S4,combinedS2 and original selectors remain.
 * Flight S3 mode,S1 vector,S2/S4 deltas are separate initialized lifetimes;
 * ground S1 limit,S2 controls/vector and S0 divisor remain original.
 * Original29 enters27's final94 store; no invented store or branch is added.
 * Every original flight/input/division/trig/vector/particle word is required.
 * Typed aliases stay distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions; frozen C tools emit words.
 * Raw units/fixed point, helper contracts and caller rate remain unresolved.
 * Cadence is per invocation. Falsification: every native/linked instruction,
 * actual internal/conditional target,selector/data word and full EXE/every
 * overlay retail hash. Binary identity does not establish runtime completion. */
#define Physics47Field(p, t, o) (*(t)((unsigned char*)(p) + (o)))
int Physics47RandSignedBetweenView4() __asm__("func_800363DC");
unsigned char Physics47Call40D10View5() __asm__("func_80040D10");
unsigned char Physics47Call41580View5() __asm__("func_80041580");
unsigned char Physics47Call416F4View5() __asm__("func_800416F4");
unsigned char Physics47Call417FCView5() __asm__("func_800417FC");
unsigned char Physics47Call41B64View5() __asm__("func_80041B64");
int Physics47InterpolateSineView5() __asm__("func_8004E9E4");
int Physics47InterpolateCosineView5() __asm__("func_8004EA2C");
unsigned char Physics47TransformVectorByBasisView4() __asm__("func_8004ED6C");
int Physics47MeasureVectorLengthView5() __asm__("func_8004EDE8");
unsigned char Physics47ScaleVectorRatioQ15View5() __asm__("func_8004F08C");
unsigned char Physics47ShiftVectorRightTowardZeroView3() __asm__("func_8004F110");
unsigned char Physics47ClearVectorView5() __asm__("func_8004F168");
unsigned char Physics47CopyVectorView5() __asm__("func_8004F178");
unsigned char Physics47AddVectorView5() __asm__("func_8004F194");
unsigned char Physics47SubtractVectorView5() __asm__("func_8004F1C8");
int Physics47CallRandView4() __asm__("rand");
extern unsigned char Physics47Data658A0View5 __asm__("D_800658A0");
extern unsigned char Physics47Data65920View5 __asm__("D_80065920");
extern void* Physics47Data6C570View4 __asm__("D_8006C570");
extern int Physics47Data6C640View5 __asm__("D_8006C640");
extern int Physics47Data6E044View5 __asm__("D_8006E044");
extern unsigned char Physics47Data6E548View5 __asm__("D_8006E548");
extern unsigned char Physics47Player0View5 __asm__("D_80070328");
extern int Physics47Player94View4 __asm__("D_80070328+0x94");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics47Call40D10View6() __asm__("func_80040D10");
int Physics47Call40F48View3() __asm__("func_80040F48");
int Physics47Call410F8View3() __asm__("func_800410F8");
int Physics47Call41404View2() __asm__("func_80041404");
int Physics47Call41580View6() __asm__("func_80041580");
int Physics47Call416F4View6() __asm__("func_800416F4");
int Physics47Call417FCView6() __asm__("func_800417FC");
int Physics47Call41848View4() __asm__("func_80041848");
int Physics47Call41B64View6() __asm__("func_80041B64");
int Physics47InterpolateSineView6() __asm__("func_8004E9E4");
int Physics47InterpolateCosineView6() __asm__("func_8004EA2C");
int Physics47MeasureVectorLengthView6() __asm__("func_8004EDE8");
int Physics47ScaleVectorRatioQ15View6() __asm__("func_8004F08C");
int Physics47ClearVectorView6() __asm__("func_8004F168");
int Physics47CopyVectorView6() __asm__("func_8004F178");
int Physics47AddVectorView6() __asm__("func_8004F194");
int Physics47SubtractVectorView6() __asm__("func_8004F1C8");
int Physics47Absolute12BitAngleDeltaView3() __asm__("func_8004F284");
extern unsigned char Physics47Data658A0View6 __asm__("D_800658A0");
extern unsigned char Physics47Data65920View6 __asm__("D_80065920");
extern int Physics47Data6763CView2 __asm__("D_8006763C");
extern int Physics47Data67640View2 __asm__("D_80067640");
extern int Physics47Data67644View2 __asm__("D_80067644");
extern unsigned char Physics47Data676E8View3 __asm__("D_800676E8");
extern int* Physics47Data6C570View5 __asm__("D_8006C570");
extern int Physics47Data6C58CView3 __asm__("D_8006C58C");
extern int Physics47Data6C5C8View3 __asm__("D_8006C5C8");
extern int Physics47Data6C640View6 __asm__("D_8006C640");
extern short Physics47Data6E040View3 __asm__("D_8006E040");
extern int Physics47Data6E044View6 __asm__("D_8006E044");
extern int Physics47Data6E538View4 __asm__("D_8006E538");
extern unsigned char Physics47Data6E548View6 __asm__("D_8006E548");
extern unsigned char Physics47Player0View6 __asm__("D_80070328");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics47PlayerB8View3 __asm__("D_80070328+0xB8");
extern int Physics47Player94View5 __asm__("D_80070328+0x94");
extern int Physics47PlayerA8View3 __asm__("D_80070328+0xA8");
extern int Physics47Player80View2 __asm__("D_80070328+0x80");
extern int Physics47PlayerB0View3 __asm__("D_80070328+0xB0");
extern int Physics47Player64View3 __asm__("D_80070328+0x64");
extern int Physics47Player88View3 __asm__("D_80070328+0x88");
extern int Physics47Player84View2 __asm__("D_80070328+0x84");
extern int Physics47Player144View3 __asm__("D_80070328+0x144");
extern int Physics47Player60View3 __asm__("D_80070328+0x60");
extern int Physics47PlayerACView3 __asm__("D_80070328+0xAC");
extern int Physics47Player4CView3 __asm__("D_80070328+0x4C");
extern int Physics47Player14CView3 __asm__("D_80070328+0x14C");
extern int Physics47Player5CView3 __asm__("D_80070328+0x5C");
extern unsigned char Physics47PlayerFCView3 __asm__("D_80070328+0xFC");
extern int Physics47PlayerA0View3 __asm__("D_80070328+0xA0");
extern unsigned char Physics47Player1BAView2 __asm__("D_80070328+0x1BA");
extern signed char Physics47Player1B9View2 __asm__("D_80070328+0x1B9");
extern int Physics47Player20CView2 __asm__("D_80070328+0x20C");
extern unsigned char Physics47Player101View2 __asm__("D_80070328+0x101");
extern int Physics47PlayerA4View2 __asm__("D_80070328+0xA4");
extern int Physics47Player210View3 __asm__("D_80070328+0x210");
extern int Physics47PlayerF8View3 __asm__("D_80070328+0xF8");
extern int Physics47Player8View3 __asm__("D_80070328+0x8");
int Physics47RandSignedBetweenView5() __asm__("func_800363DC");
int Physics47Call40D10View7() __asm__("func_80040D10");
int Physics47Call40F48View4() __asm__("func_80040F48");
int Physics47Call41580View7() __asm__("func_80041580");
int Physics47Call416F4View7() __asm__("func_800416F4");
int Physics47Call417FCView7() __asm__("func_800417FC");
int Physics47Call41848View5() __asm__("func_80041848");
int Physics47Call41B64View7() __asm__("func_80041B64");
int Physics47Call43194View2() __asm__("func_80043194");
int Physics47PlanarHeadingLookupView3() __asm__("func_8004E880");
int Physics47InterpolateSineView7() __asm__("func_8004E9E4");
int Physics47InterpolateCosineView7() __asm__("func_8004EA2C");
int Physics47TransformVectorByBasisView5() __asm__("func_8004ED6C");
int Physics47MeasureVectorLengthView7() __asm__("func_8004EDE8");
int Physics47ScaleVectorRatioQ15View7() __asm__("func_8004F08C");
int Physics47ClearVectorView7() __asm__("func_8004F168");
int Physics47CopyVectorView7() __asm__("func_8004F178");
int Physics47AddVectorView7() __asm__("func_8004F194");
int Physics47SubtractVectorView7() __asm__("func_8004F1C8");
int Physics47Absolute12BitAngleDeltaView4() __asm__("func_8004F284");
int Physics47CallRandView5() __asm__("rand");
extern unsigned char Physics47Data658A0View7 __asm__("D_800658A0");
extern unsigned char Physics47Data65920View7 __asm__("D_80065920");
extern unsigned char Physics47Data676E8View4 __asm__("D_800676E8");
extern int Physics47Data6C514View3 __asm__("D_8006C514");
extern int* Physics47Data6C570View6 __asm__("D_8006C570");
extern int Physics47Data6C58CView4 __asm__("D_8006C58C");
extern int Physics47Data6C5C8View4 __asm__("D_8006C5C8");
extern int Physics47Data6C640View7 __asm__("D_8006C640");
extern short Physics47Data6E040View4 __asm__("D_8006E040");
extern int Physics47Data6E044View7 __asm__("D_8006E044");
extern int Physics47Data6E344View3 __asm__("D_8006E344");
extern int Physics47Data6E538View5 __asm__("D_8006E538");
extern unsigned char Physics47Data6E548View7 __asm__("D_8006E548");
extern unsigned char Physics47Player0View7 __asm__("D_80070328");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics47Player16CView2 __asm__("D_80070328+0x16C");
int Physics47Call13E38View2() __asm__("func_80013E38");
int Physics47RandSignedBetweenView6() __asm__("func_800363DC");
int Physics47Call40D10View8() __asm__("func_80040D10");
int Physics47Call410F8View4() __asm__("func_800410F8");
int Physics47Call41580View8() __asm__("func_80041580");
int Physics47Call416F4View8() __asm__("func_800416F4");
int Physics47Call417FCView8() __asm__("func_800417FC");
int Physics47Call41848View6() __asm__("func_80041848");
int Physics47Call41B64View8() __asm__("func_80041B64");
int Physics47Call4E4E4View2() __asm__("func_8004E4E4");
int Physics47PlanarHeadingLookupView4() __asm__("func_8004E880");
int Physics47InterpolateSineView8() __asm__("func_8004E9E4");
int Physics47InterpolateCosineView8() __asm__("func_8004EA2C");
int Physics47TransformVectorByBasisView6() __asm__("func_8004ED6C");
int Physics47MeasureVectorLengthView8() __asm__("func_8004EDE8");
int Physics47ScaleVectorRatioQ15View8() __asm__("func_8004F08C");
int Physics47ShiftVectorLeftView2() __asm__("func_8004F0E8");
int Physics47ShiftVectorRightTowardZeroView4() __asm__("func_8004F110");
int Physics47ClearVectorView8() __asm__("func_8004F168");
int Physics47CopyVectorView8() __asm__("func_8004F178");
int Physics47AddVectorView8() __asm__("func_8004F194");
int Physics47SubtractVectorView8() __asm__("func_8004F1C8");
int Physics47CallRandView6() __asm__("rand");
extern unsigned char Physics47Data658A0View8 __asm__("D_800658A0");
extern unsigned char Physics47Data65920View8 __asm__("D_80065920");
extern int Physics47Data67630View2 __asm__("D_80067630");
extern int Physics47Data67634View2 __asm__("D_80067634");
extern int Physics47Data67638View2 __asm__("D_80067638");
extern int Physics47Data6C514View4 __asm__("D_8006C514");
extern int Physics47Data6C640View8 __asm__("D_8006C640");
extern int Physics47Data6C7C4View2 __asm__("D_8006C7C4");
extern int Physics47Data6E044View8 __asm__("D_8006E044");
extern int Physics47Data6E344View4 __asm__("D_8006E344");
extern int Physics47Data6E538View6 __asm__("D_8006E538");
extern unsigned char Physics47Data6E548View8 __asm__("D_8006E548");
extern int Physics47Data6FA38View2 __asm__("D_8006FA38");
extern unsigned char Physics47Player0View8 __asm__("D_80070328");
extern int Physics47Data71908View2 __asm__("D_80071908");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics47Player130View2 __asm__("D_80070328+0x130");
extern int Physics47Player144View4 __asm__("D_80070328+0x144");
extern short Physics47Player148View3 __asm__("D_80070328+0x148");
extern short Physics47Player14AView2 __asm__("D_80070328+0x14A");
extern int Physics47Player14CView4 __asm__("D_80070328+0x14C");
extern int Physics47Player150View2 __asm__("D_80070328+0x150");
extern int Physics47Player154View2 __asm__("D_80070328+0x154");
extern int Physics47Player160View2 __asm__("D_80070328+0x160");
extern int Physics47Player48View2 __asm__("D_80070328+0x48");
extern int Physics47Player4CView4 __asm__("D_80070328+0x4C");
extern int Physics47Player5CView4 __asm__("D_80070328+0x5C");
extern int Physics47Player60View4 __asm__("D_80070328+0x60");
extern int Physics47Player64View4 __asm__("D_80070328+0x64");
extern int Physics47Player8View4 __asm__("D_80070328+0x8");
extern int Physics47Player88View4 __asm__("D_80070328+0x88");
extern int Physics47Player8CView2 __asm__("D_80070328+0x8C");
extern int Physics47Player90View2 __asm__("D_80070328+0x90");
extern int Physics47Player94View6 __asm__("D_80070328+0x94");
extern int Physics47PlayerA8View4 __asm__("D_80070328+0xA8");
extern int Physics47PlayerACView4 __asm__("D_80070328+0xAC");
extern int Physics47PlayerB0View4 __asm__("D_80070328+0xB0");
extern int Physics47PlayerF8View4 __asm__("D_80070328+0xF8");
extern int Physics47Player148View4 __asm__("D_80070328+0x148");
extern int Physics47Player210View4 __asm__("D_80070328+0x210");
extern int Physics47Player220View2 __asm__("D_80070328+0x220");
extern int Physics47Player98View2 __asm__("D_80070328+0x98");
extern int Physics47PlayerA0View4 __asm__("D_80070328+0xA0");
extern int Physics47PlayerB8View4 __asm__("D_80070328+0xB8");
extern int Physics47PlayerCCView2 __asm__("D_80070328+0xCC");
extern int Physics47PlayerD0View2 __asm__("D_80070328+0xD0");
extern int Physics47PlayerE4View2 __asm__("D_80070328+0xE4");
extern unsigned char Physics47PlayerFCView4 __asm__("D_80070328+0xFC");
int Physics47RandSignedBetweenView4() __asm__("func_800363DC");
unsigned char Physics47Call40D10View5() __asm__("func_80040D10");
unsigned char Physics47Call41580View5() __asm__("func_80041580");
unsigned char Physics47Call416F4View5() __asm__("func_800416F4");
unsigned char Physics47Call417FCView5() __asm__("func_800417FC");
unsigned char Physics47Call41B64View5() __asm__("func_80041B64");
int Physics47InterpolateSineView5() __asm__("func_8004E9E4");
int Physics47InterpolateCosineView5() __asm__("func_8004EA2C");
unsigned char Physics47TransformVectorByBasisView4() __asm__("func_8004ED6C");
int Physics47MeasureVectorLengthView5() __asm__("func_8004EDE8");
unsigned char Physics47ScaleVectorRatioQ15View5() __asm__("func_8004F08C");
unsigned char Physics47ShiftVectorRightTowardZeroView3() __asm__("func_8004F110");
unsigned char Physics47ClearVectorView5() __asm__("func_8004F168");
unsigned char Physics47CopyVectorView5() __asm__("func_8004F178");
unsigned char Physics47AddVectorView5() __asm__("func_8004F194");
unsigned char Physics47SubtractVectorView5() __asm__("func_8004F1C8");
int Physics47CallRandView4() __asm__("rand");
extern unsigned char Physics47Data658A0View5 __asm__("D_800658A0");
extern unsigned char Physics47Data65920View5 __asm__("D_80065920");
extern void* Physics47Data6C570View4 __asm__("D_8006C570");
extern int Physics47Data6C640View5 __asm__("D_8006C640");
extern int Physics47Data6E044View5 __asm__("D_8006E044");
extern unsigned char Physics47Data6E548View5 __asm__("D_8006E548");
extern unsigned char Physics47Player0View5 __asm__("D_80070328");
extern int Physics47Player94View4 __asm__("D_80070328+0x94");
extern void* (*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics47Call40D10View6() __asm__("func_80040D10");
int Physics47Call40F48View3() __asm__("func_80040F48");
int Physics47Call410F8View3() __asm__("func_800410F8");
int Physics47Call41404View2() __asm__("func_80041404");
int Physics47Call41580View6() __asm__("func_80041580");
int Physics47Call416F4View6() __asm__("func_800416F4");
int Physics47Call417FCView6() __asm__("func_800417FC");
int Physics47Call41848View4() __asm__("func_80041848");
int Physics47Call41B64View6() __asm__("func_80041B64");
int Physics47InterpolateSineView6() __asm__("func_8004E9E4");
int Physics47InterpolateCosineView6() __asm__("func_8004EA2C");
int Physics47MeasureVectorLengthView6() __asm__("func_8004EDE8");
int Physics47ScaleVectorRatioQ15View6() __asm__("func_8004F08C");
int Physics47ClearVectorView6() __asm__("func_8004F168");
int Physics47CopyVectorView6() __asm__("func_8004F178");
int Physics47AddVectorView6() __asm__("func_8004F194");
int Physics47SubtractVectorView6() __asm__("func_8004F1C8");
int Physics47Absolute12BitAngleDeltaView3() __asm__("func_8004F284");
extern unsigned char Physics47Data658A0View6 __asm__("D_800658A0");
extern unsigned char Physics47Data65920View6 __asm__("D_80065920");
extern int Physics47Data6763CView2 __asm__("D_8006763C");
extern int Physics47Data67640View2 __asm__("D_80067640");
extern int Physics47Data67644View2 __asm__("D_80067644");
extern unsigned char Physics47Data676E8View3 __asm__("D_800676E8");
extern int* Physics47Data6C570View5 __asm__("D_8006C570");
extern int Physics47Data6C58CView3 __asm__("D_8006C58C");
extern int Physics47Data6C5C8View3 __asm__("D_8006C5C8");
extern int Physics47Data6C640View6 __asm__("D_8006C640");
extern short Physics47Data6E040View3 __asm__("D_8006E040");
extern int Physics47Data6E044View6 __asm__("D_8006E044");
extern int Physics47Data6E538View4 __asm__("D_8006E538");
extern unsigned char Physics47Data6E548View6 __asm__("D_8006E548");
extern unsigned char Physics47Player0View6 __asm__("D_80070328");
extern void* (*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics47PlayerB8View3 __asm__("D_80070328+0xB8");
extern int Physics47Player94View5 __asm__("D_80070328+0x94");
extern int Physics47PlayerA8View3 __asm__("D_80070328+0xA8");
extern int Physics47Player80View2 __asm__("D_80070328+0x80");
extern int Physics47PlayerB0View3 __asm__("D_80070328+0xB0");
extern int Physics47Player64View3 __asm__("D_80070328+0x64");
extern int Physics47Player88View3 __asm__("D_80070328+0x88");
extern int Physics47Player84View2 __asm__("D_80070328+0x84");
extern int Physics47Player144View3 __asm__("D_80070328+0x144");
extern int Physics47Player60View3 __asm__("D_80070328+0x60");
extern int Physics47PlayerACView3 __asm__("D_80070328+0xAC");
extern int Physics47Player4CView3 __asm__("D_80070328+0x4C");
extern int Physics47Player14CView3 __asm__("D_80070328+0x14C");
extern int Physics47Player5CView3 __asm__("D_80070328+0x5C");
extern unsigned char Physics47PlayerFCView3 __asm__("D_80070328+0xFC");
extern int Physics47PlayerA0View3 __asm__("D_80070328+0xA0");
extern unsigned char Physics47Player1BAView2 __asm__("D_80070328+0x1BA");
extern signed char Physics47Player1B9View2 __asm__("D_80070328+0x1B9");
extern int Physics47Player20CView2 __asm__("D_80070328+0x20C");
extern unsigned char Physics47Player101View2 __asm__("D_80070328+0x101");
extern int Physics47PlayerA4View2 __asm__("D_80070328+0xA4");
extern int Physics47Player210View3 __asm__("D_80070328+0x210");
extern int Physics47PlayerF8View3 __asm__("D_80070328+0xF8");
extern int Physics47Player8View3 __asm__("D_80070328+0x8");
int Physics47RandSignedBetweenView5() __asm__("func_800363DC");
int Physics47Call40D10View7() __asm__("func_80040D10");
int Physics47Call40F48View4() __asm__("func_80040F48");
int Physics47Call41580View7() __asm__("func_80041580");
int Physics47Call416F4View7() __asm__("func_800416F4");
int Physics47Call417FCView7() __asm__("func_800417FC");
int Physics47Call41848View5() __asm__("func_80041848");
int Physics47Call41B64View7() __asm__("func_80041B64");
int Physics47Call43194View2() __asm__("func_80043194");
int Physics47PlanarHeadingLookupView3() __asm__("func_8004E880");
int Physics47InterpolateSineView7() __asm__("func_8004E9E4");
int Physics47InterpolateCosineView7() __asm__("func_8004EA2C");
int Physics47TransformVectorByBasisView5() __asm__("func_8004ED6C");
int Physics47MeasureVectorLengthView7() __asm__("func_8004EDE8");
int Physics47ScaleVectorRatioQ15View7() __asm__("func_8004F08C");
int Physics47ClearVectorView7() __asm__("func_8004F168");
int Physics47CopyVectorView7() __asm__("func_8004F178");
int Physics47AddVectorView7() __asm__("func_8004F194");
int Physics47SubtractVectorView7() __asm__("func_8004F1C8");
int Physics47Absolute12BitAngleDeltaView4() __asm__("func_8004F284");
int Physics47CallRandView5() __asm__("rand");
extern unsigned char Physics47Data658A0View7 __asm__("D_800658A0");
extern unsigned char Physics47Data65920View7 __asm__("D_80065920");
extern unsigned char Physics47Data676E8View4 __asm__("D_800676E8");
extern int Physics47Data6C514View3 __asm__("D_8006C514");
extern int* Physics47Data6C570View6 __asm__("D_8006C570");
extern int Physics47Data6C58CView4 __asm__("D_8006C58C");
extern int Physics47Data6C5C8View4 __asm__("D_8006C5C8");
extern int Physics47Data6C640View7 __asm__("D_8006C640");
extern short Physics47Data6E040View4 __asm__("D_8006E040");
extern int Physics47Data6E044View7 __asm__("D_8006E044");
extern int Physics47Data6E344View3 __asm__("D_8006E344");
extern int Physics47Data6E538View5 __asm__("D_8006E538");
extern unsigned char Physics47Data6E548View7 __asm__("D_8006E548");
extern unsigned char Physics47Player0View7 __asm__("D_80070328");
extern void* (*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics47Player16CView2 __asm__("D_80070328+0x16C");
int Physics47Call13E38View2() __asm__("func_80013E38");
int Physics47RandSignedBetweenView6() __asm__("func_800363DC");
int Physics47Call40D10View8() __asm__("func_80040D10");
int Physics47Call410F8View4() __asm__("func_800410F8");
int Physics47Call41580View8() __asm__("func_80041580");
int Physics47Call416F4View8() __asm__("func_800416F4");
int Physics47Call417FCView8() __asm__("func_800417FC");
int Physics47Call41848View6() __asm__("func_80041848");
int Physics47Call41B64View8() __asm__("func_80041B64");
int Physics47Call4E4E4View2() __asm__("func_8004E4E4");
int Physics47PlanarHeadingLookupView4() __asm__("func_8004E880");
int Physics47InterpolateSineView8() __asm__("func_8004E9E4");
int Physics47InterpolateCosineView8() __asm__("func_8004EA2C");
int Physics47TransformVectorByBasisView6() __asm__("func_8004ED6C");
int Physics47MeasureVectorLengthView8() __asm__("func_8004EDE8");
int Physics47ScaleVectorRatioQ15View8() __asm__("func_8004F08C");
int Physics47ShiftVectorLeftView2() __asm__("func_8004F0E8");
int Physics47ShiftVectorRightTowardZeroView4() __asm__("func_8004F110");
int Physics47ClearVectorView8() __asm__("func_8004F168");
int Physics47CopyVectorView8() __asm__("func_8004F178");
int Physics47AddVectorView8() __asm__("func_8004F194");
int Physics47SubtractVectorView8() __asm__("func_8004F1C8");
int Physics47CallRandView6() __asm__("rand");
extern unsigned char Physics47Data658A0View8 __asm__("D_800658A0");
extern unsigned char Physics47Data65920View8 __asm__("D_80065920");
extern int Physics47Data67630View2 __asm__("D_80067630");
extern int Physics47Data67634View2 __asm__("D_80067634");
extern int Physics47Data67638View2 __asm__("D_80067638");
extern int Physics47Data6C514View4 __asm__("D_8006C514");
extern int Physics47Data6C640View8 __asm__("D_8006C640");
extern int Physics47Data6C7C4View2 __asm__("D_8006C7C4");
extern int Physics47Data6E044View8 __asm__("D_8006E044");
extern int Physics47Data6E344View4 __asm__("D_8006E344");
extern int Physics47Data6E538View6 __asm__("D_8006E538");
extern unsigned char Physics47Data6E548View8 __asm__("D_8006E548");
extern int Physics47Data6FA38View2 __asm__("D_8006FA38");
extern unsigned char Physics47Player0View8 __asm__("D_80070328");
extern int Physics47Data71908View2 __asm__("D_80071908");
extern void* (*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics47Player130View2 __asm__("D_80070328+0x130");
extern int Physics47Player144View4 __asm__("D_80070328+0x144");
extern short Physics47Player148View3 __asm__("D_80070328+0x148");
extern short Physics47Player14AView2 __asm__("D_80070328+0x14A");
extern int Physics47Player14CView4 __asm__("D_80070328+0x14C");
extern int Physics47Player150View2 __asm__("D_80070328+0x150");
extern int Physics47Player154View2 __asm__("D_80070328+0x154");
extern int Physics47Player160View2 __asm__("D_80070328+0x160");
extern int Physics47Player48View2 __asm__("D_80070328+0x48");
extern int Physics47Player4CView4 __asm__("D_80070328+0x4C");
extern int Physics47Player5CView4 __asm__("D_80070328+0x5C");
extern int Physics47Player60View4 __asm__("D_80070328+0x60");
extern int Physics47Player64View4 __asm__("D_80070328+0x64");
extern int Physics47Player8View4 __asm__("D_80070328+0x8");
extern int Physics47Player88View4 __asm__("D_80070328+0x88");
extern int Physics47Player8CView2 __asm__("D_80070328+0x8C");
extern int Physics47Player90View2 __asm__("D_80070328+0x90");
extern int Physics47Player94View6 __asm__("D_80070328+0x94");
extern int Physics47PlayerA8View4 __asm__("D_80070328+0xA8");
extern int Physics47PlayerACView4 __asm__("D_80070328+0xAC");
extern int Physics47PlayerB0View4 __asm__("D_80070328+0xB0");
extern int Physics47PlayerF8View4 __asm__("D_80070328+0xF8");
extern int Physics47Player148View4 __asm__("D_80070328+0x148");
extern int Physics47Player210View4 __asm__("D_80070328+0x210");
extern int Physics47Player220View2 __asm__("D_80070328+0x220");
extern int Physics47Player98View2 __asm__("D_80070328+0x98");
extern int Physics47PlayerA0View4 __asm__("D_80070328+0xA0");
extern int Physics47PlayerB8View4 __asm__("D_80070328+0xB8");
extern int Physics47PlayerCCView2 __asm__("D_80070328+0xCC");
extern int Physics47PlayerD0View2 __asm__("D_80070328+0xD0");
extern int Physics47PlayerE4View2 __asm__("D_80070328+0xE4");
extern unsigned char Physics47PlayerFCView4 __asm__("D_80070328+0xFC");
extern void* (*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern void* (*Physics32_SpawnParticle)() __asm__("SpawnParticle");
int Physics47SubAngle12View1() __asm__("func_8003615C");
int Physics47Call40D10View9() __asm__("func_80040D10");
int Physics47Call410F8View5() __asm__("func_800410F8");
int Physics47Call41580View9() __asm__("func_80041580");
int Physics47Call41B64View9() __asm__("func_80041B64");
int Physics47InterpolateSineView9() __asm__("func_8004E9E4");
int Physics47InterpolateCosineView9() __asm__("func_8004EA2C");
int Physics47TransformVectorByBasisView7() __asm__("func_8004ED6C");
int Physics47MeasureVectorLengthView9() __asm__("func_8004EDE8");
int Physics47ScaleVectorRatioQ15View9() __asm__("func_8004F08C");
int Physics47ClearVectorView9() __asm__("func_8004F168");
int Physics47AddVectorView9() __asm__("func_8004F194");
int Physics47SubtractVectorView9() __asm__("func_8004F1C8");
extern short Physics47Data6E040View5 __asm__("D_8006E040");
extern int Physics47Data6E538View7 __asm__("D_8006E538");
extern void* (*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics47Player50View1 __asm__("D_80070328+0x50");
extern int Physics47PlayerB4View1 __asm__("D_80070328+0xB4");
extern int Physics47Player30View1 __asm__("D_80070328+0x30");
void func_level_47_8008BBD8(int slotIndex) {
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
            sp48, sp4C, sp50, sp54, sp58, sp5C, sp60, sp64, sp68, sp6C, sp70, sp74, sp78, sp7C,
            sp80, sp84, sp88, sp8C;
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
    void* raw34_temp_a0_3;
    void* raw34_temp_s1_2;
    int raw34_temp_v0_6;
    int raw34_temp_v0_7;
    workWord2 = slotIndex * 16;
    globalPointer = &Physics47Data6E548View5;
    workWord2 += (int)globalPointer;
    MATCHING_KEEP(workWord2);
    Physics47Data6C570View4 = (void*)workWord2;
    workWord2 = Physics47Field(&Physics47Player0View5, int*, 0x54);
    stateWord3 = Physics47Field(&Physics47Player0View5, int*, 0x48);
    combinedIndex = workWord2 + slotIndex;
    switch (stateWord3) {
        default:
            return;
        case 20:
            globalVector80 = &Physics47Player0View5 + 0x80;
            Physics47ClearVectorView5(globalVector80);
            Physics47ClearVectorView5(globalVector80 + 0xC);
            if (Physics47Data6E044View5 != 7) {
                Physics47Call40D10View5(0x1200);
                Physics47Call416F4View5();
                Physics47Call41580View5(0x5A, 0x10);
                return;
            }
            return;
        case 19: {
            int product19;
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            register int numeric7 __asm__("$7");
            register int angle16 __asm__("$16");
            register int square8 __asm__("$8");
            register int product10 __asm__("$10");
            workWord3 = Physics47Data6E344View3;
            workWord2 = 13;
            if (workWord3 == workWord2) {
                workWord2 = Physics47Data6C514View3;
                if (workWord2)
                    return;
            }
            vectorAt30 = &Physics47Player0View7 + 8;
            workWord3 = Physics47Field(vectorAt30, int*, 0);
            workWord2 = Physics47Field(&Physics47Player0View7, int*, 0x144);
            numeric4 = workWord3 - workWord2;
            workWord2 = numeric4 < 1024;
            if (!workWord2)
                goto beyond19;
            workWord2 = Physics47Player94View5;
            workWord2 += 128;
            Physics47Player94View5 = workWord2;
            workWord2 = workWord2 < 4801;
            __asm__("" : "=r"(numeric4) : "0"(numeric4), "r"(workWord2));
            if (!workWord2) {
                workWord2 = 4800;
                Physics47Player94View5 = workWord2;
            }
            product19 = numeric4 * numeric4;
            call4 = &originalFrame.sp10;
            workWord3 = Physics47Field(&Physics47Player0View7, int*, 0x148);
            MATCHING_OBSERVE3_VOLATILE_CLOBBER(workWord2, workWord3, call4, "memory");
            workWord2 = product19 >> 11;
            angle16 = workWord2 + workWord3;
            Physics47Player64View3 = angle16;
            __asm__ volatile("" : "=r"(vectorAt30) : "0"(vectorAt30), "r"(call4) : "memory");
            Physics47CopyVectorView7(call4, vectorAt30 + 340);
            call4 = &originalFrame.sp10;
            call5 = call4;
            Physics47SubtractVectorView7(call4, call5, vectorAt30 - 8);
            call4 = &originalFrame.sp10;
            call5 = 0;
            originalFrame.sp18 = 0;
            workWord2 = Physics47MeasureVectorLengthView7(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 1025;
            call4 = &originalFrame.sp10;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            __asm__ volatile("" ::"i"(0x8008BD74) : "memory");
            numeric6 = 1024;
            goto limit19;
        beyond19:
            numeric5 = Physics47Field(&Physics47Player0View7, int*, 0x14C);
            workWord2 = workWord3 - numeric5;
            workWord2 = workWord2 < -1024;
            numeric6 = numeric5 - workWord3;
            if (!workWord2)
                goto curve19;
            __asm__ volatile("" : "=r"(numeric6) : "0"(numeric6), "i"(0x8008BD98));
            workWord2 = Physics47Player4CView3;
            workWord3 = 1;
            if (!workWord2) {
                workWord2 = Physics47Field(&Physics47Player0View7, int*, 0x148);
                Physics47Player4CView3 = workWord3;
                workWord2 += 512;
                Physics47Field(&Physics47Player0View7, int*, 0x148) = workWord2;
            }
            workWord2 = Physics47Player94View5;
            workWord2 += 128;
            Physics47Player94View5 = workWord2;
            workWord2 = workWord2 < 4801;
            if (!workWord2)
                Physics47Player94View5 = 4800;
            workWord2 = Physics47Field(&Physics47Player0View7, int*, 0x150);
            numeric6 = numeric4 - 1024;
            workWord3 = workWord2 * numeric6;
            workWord2 = Physics47Field(&Physics47Player0View7, int*, 0x154);
            workWord2 = workWord3 / workWord2;
            call4 = &originalFrame.sp10;
            workWord3 = Physics47Field(&Physics47Player0View7, int*, 0x148);
            angle16 = workWord3 + workWord2;
            workWord2 = (numeric6 << 10) >> 10;
            workWord2 = angle16 + workWord2;
            angle16 = workWord2 & 4095;
            Physics47Player64View3 = angle16;
            Physics47CopyVectorView7(call4, vectorAt30 + 340);
            call4 = &originalFrame.sp10;
            call5 = call4;
            Physics47SubtractVectorView7(call4, call5, vectorAt30 - 8);
            call4 = &originalFrame.sp10;
            call5 = 0;
            originalFrame.sp18 = 0;
            workWord2 = Physics47MeasureVectorLengthView7(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 1025;
            call4 = &originalFrame.sp10;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            __asm__ volatile("" ::"i"(0x8008BEA8) : "memory");
            numeric6 = 1024;
            goto limit19;
        curve19:
            __asm__ volatile("" : "=r"(numeric6) : "0"(numeric6), "i"(0x8008BEB0));
            workWord2 = (numeric6 * 4800) >> 10;
            Physics47Player94View5 = workWord2;
            workWord2 = Physics47Player16CView2;
            numeric7 = Physics47Field(&Physics47Player0View7, int*, 0x168);
            workWord3 = Physics47Field(&Physics47Player0View7, int*, 0x158);
            workWord2 &= 127;
            numeric4 = numeric7 << 1;
            Physics47Player16CView2 = workWord2;
            workWord2 = *(short*)(&Physics47Data65920View7 + numeric4);
            workWord3 += 1024;
            product10 = workWord3 * workWord2;
            square8 = numeric6 * numeric6;
            workWord2 = product10 >> 12;
            originalFrame.sp10 = workWord2;
            workWord2 = *(short*)(&Physics47Data658A0View7 + numeric4);
            workWord3 = workWord3 * workWord2;
            numeric7 <<= 4;
            call4 = &originalFrame.sp10;
            call5 = call4;
            __asm__("" : "=r"(vectorAt30) : "0"(vectorAt30), "r"(call4), "r"(call5));
            numeric6 = (int)vectorAt30 + 340;
            workWord2 = square8 >> 11;
            angle16 = numeric7 - workWord2;
            workWord2 = workWord3 >> 12;
            originalFrame.sp14 = workWord2;
            Physics47AddVectorView7(call4, call5, numeric6, numeric7);
            call4 = &originalFrame.sp10;
            call5 = call4;
            Physics47Player64View3 = angle16;
            Physics47SubtractVectorView7(call4, call5, vectorAt30 - 8);
            call4 = &originalFrame.sp10;
            call5 = 0;
            originalFrame.sp18 = 0;
            workWord2 = Physics47MeasureVectorLengthView7(call4, call5);
            numeric6 = workWord2;
            workWord2 = numeric6 < 2049;
            call4 = &originalFrame.sp10;
            if (workWord2)
                goto commit19;
            call5 = (void*)numeric6;
            numeric6 = 2048;
        limit19:
            Physics47ScaleVectorRatioQ15View7(call4, call5, numeric6);
        commit19:
            workWord2 = originalFrame.sp10;
            workWord3 = originalFrame.sp14;
            Physics47Field(&Physics47Player0View7, int*, 0x8C) = workWord2;
            Physics47Field(&Physics47Player0View7, int*, 0x90) = workWord3;
            return;
        }
        case 29:
            Physics47ClearVectorView7(&originalFrame.sp20);
            raw34_temp_s1_2 = &Physics47Player0View7 + 0x8C;
            Physics47SubtractVectorView7(&originalFrame.sp20, &originalFrame.sp20, raw34_temp_s1_2);
            if (Physics47Field(&Physics47Player0View7, int*, 0xB8) != 0) {
                originalFrame.sp28 = 0;
                raw34_temp_v0_6 = Physics47MeasureVectorLengthView7(&originalFrame.sp20, 0);
                if (raw34_temp_v0_6 >= 0x41) {
                    Physics47ScaleVectorRatioQ15View7(&originalFrame.sp20, raw34_temp_v0_6, 0x40);
                }
                originalFrame.sp28 = -0xC0;
                call4 = raw34_temp_s1_2 - 12;
                call5 = raw34_temp_s1_2;
                call6 = &originalFrame.sp20;
                goto commit29;
            } else {
                raw34_temp_v0_7 = Physics47MeasureVectorLengthView7(&originalFrame.sp20, 1);
                if (raw34_temp_v0_7 >= 0x101) {
                    Physics47ScaleVectorRatioQ15View7(&originalFrame.sp20, raw34_temp_v0_7, 0x100);
                }
                Physics47AddVectorView7(raw34_temp_s1_2, raw34_temp_s1_2, &originalFrame.sp20);
                call4 = raw34_temp_s1_2 - 12;
                call5 = raw34_temp_s1_2;
                MATCHING_KEEP(call5);
                call6 = call5 + 92;
            }
        commit29:
            Physics47AddVectorView7(call4, call5, call6);
            raw34_temp_a0_3 = &Physics47Player0View7 + 0x8C;
            Physics47CopyVectorView7(raw34_temp_a0_3, raw34_temp_a0_3 - 0xC);
            if (Physics47Field(&Physics47Player0View7, int*, 0x94) < -0x2300) {
                workWord2 = -8960;
                goto store94From2;
            }
            break;
        case 28:
            Physics47Call40D10View5(0xC80);
            Physics47Call41580View5(0x28, 8);
            Physics47Call417FCView5(0x140, 0xC0);
            globalFieldA4Pointer = &Physics47Player0View5 + 0xA4;
            globalVector8C = globalFieldA4Pointer - 0x18;
            workWord2 =
                Physics47InterpolateCosineView5(Physics47Field(globalFieldA4Pointer, int*, 0));
            workWord3 = Physics47Field(&Physics47Player0View5, int*, 0xB0);
            lowProduct3 = workWord3 * workWord2;
            call4 = (void*)Physics47Field(globalFieldA4Pointer, int*, 0);
            workWord2 = lowProduct3 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp30 = workWord2;
            workWord2 = Physics47InterpolateSineView5(call4);
            workWord3 = Physics47Field(&Physics47Player0View5, int*, 0xB0);
            lowProduct4 = workWord3 * workWord2;
            workWord2 = lowProduct4 >> 12;
            MATCHING_KEEP(workWord2);
            originalFrame.sp34 = workWord2;
            Physics47SubtractVectorView5(&originalFrame.sp30, &originalFrame.sp30, globalVector8C);
            originalFrame.sp38 = 0;
            temp_v0_4 = Physics47MeasureVectorLengthView5(&originalFrame.sp30, 0);
            MATCHING_KEEP(globalFieldA4Pointer);
            var_a0_3 = globalFieldA4Pointer - 0x24;
            if (temp_v0_4 >= 0x281) {
                Physics47ScaleVectorRatioQ15View5(&originalFrame.sp30, temp_v0_4, 0x280);
                MATCHING_KEEP(globalFieldA4Pointer);
                var_a0_3 = globalFieldA4Pointer - 0x24;
            }
            Physics47AddVectorView5(var_a0_3, globalVector8C, &originalFrame.sp30);
            Physics47Call41B64View5();
            if (combinedIndex < 0xD) {
                MATCHING_OBSERVE(combinedIndex);
                nextField94 = Physics47Field(&Physics47Player0View5, int*, 0x94) + 0x17;
            } else {
                nextField94 = Physics47Field(&Physics47Player0View5, int*, 0x94) - 0xC0;
            }
            Physics47Player94View4 = nextField94;
            MATCHING_BARRIER_VOLATILE("memory");
            if (Controller88028_SpawnParticle != 0) {
                globalPointer = &Physics47Player0View5 + 0x148;
                MATCHING_KEEP(globalPointer);
                particleIndex = 0;
                if (Physics47Field(globalPointer, int*, 0) != 0) {
                    workWord2 = combinedIndex * 4;
                    MATCHING_KEEP(workWord2);
                    particleThreshold = workWord2 + combinedIndex;
                    globalByteE = globalPointer - 0x13A;
                    vectorAt40 = &originalFrame.sp50;
                    MATCHING_KEEP(vectorAt40);
                spawnParticleLoop:
                    if (particleThreshold < (Physics47CallRandView4() & 0xFF)) {
                        workWord2 = Physics47RandSignedBetweenView4(0, 0xC);
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
                        signedTableWord = *(short*)(&Physics47Data65920View5 + workWord3);
                        call6 = vectorAt40;
                        originalFrame.sp40 = (int)(signedTableWord * 5) >> 0xA;
                        workWord3 = *(short*)(&Physics47Data658A0View5 + workWord3);
                        MATCHING_KEEP_VOLATILE_CLOBBER(workWord3, "memory");
                        originalFrame.sp48 = 0xE;
                        originalFrame.sp50 = -0x12C;
                        originalFrame.sp54 = 0;
                        originalFrame.sp58 = -0xC8;
                        MATCHING_BARRIER_VOLATILE("memory");
                        originalFrame.sp44 = (workWord3 * 5) >> 0xA;
                        Physics47TransformVectorByBasisView4(call4, call5, call6, signedTableWord);
                        originalFrame.sp50 += Physics47RandSignedBetweenView4(0, 0x50);
                        originalFrame.sp54 += Physics47RandSignedBetweenView4(0, 0x50);
                        originalFrame.sp58 += Physics47RandSignedBetweenView4(0, 0x50);
                        Physics47AddVectorView5(vectorAt40, vectorAt40, globalByteE - 0xE);
                        temp_v0_5 =
                            Controller88028_SpawnParticle(1, 0xD, vectorAt40, &originalFrame.sp40);
                        Physics47Field(temp_v0_5, signed char*, 2) = 8;
                        Physics47Field(temp_v0_5, signed char*, 0xA) = 0x20;
                    }
                    particleIndex += 1;
                    if (particleIndex < 2) {
                        goto spawnParticleLoop;
                    }
                }
            }
            break;
        case 58:
            globalFieldB8PointerState20 = &Physics47Player0View5 + 0xB8;
            if (Physics47Field(&Physics47Player0View5, int*, 0xB8) != 0) {
                vectorAt30 = &originalFrame.sp40;
                Physics47ClearVectorView5(vectorAt30);
                call4 = vectorAt30;
                call5 = vectorAt30;
                MATCHING_KEEP2(call4, call5);
                globalVector8CState20 = globalFieldB8PointerState20 - 0x2C;
                Physics47SubtractVectorView5(call4, call5, globalVector8CState20);
                originalFrame.sp48 = 0;
                temp_v0_6 = Physics47MeasureVectorLengthView5(&originalFrame.sp40, 0);
                if (temp_v0_6 >= 0x41) {
                    Physics47ScaleVectorRatioQ15View5(&originalFrame.sp40, temp_v0_6, 0x40);
                }
                originalFrame.sp48 = -0xC0;
                globalVector80State20 = globalFieldB8PointerState20 - 0x38;
                Physics47AddVectorView5(globalVector80State20, globalVector8CState20,
                                        &originalFrame.sp40);
                Physics47CopyVectorView5(globalVector8CState20, globalVector80State20);
            } else {
                Physics47ClearVectorView5(globalFieldB8PointerState20 - 0x38);
                Physics47ClearVectorView5(globalFieldB8PointerState20 - 0x2C);
            }
            if (Physics47Field(&Physics47Player0View5, int*, 0x94) < -0x2300) {
                Physics47Field(&Physics47Player0View5, int*, 0x94) = -0x2300;
            }
            if ((Physics47Field(&Physics47Player0View5, int*, 0x48) == 0x3A) &&
                (Controller88028_SpawnParticle != 0) && (Physics47Data6C640View5 & 1)) {
                originalFrame.sp60 = 0;
                originalFrame.sp64 = 0;
                originalFrame.sp68 = 0xE;
                Physics47CopyVectorView5(&originalFrame.sp70,
                                         (&Physics47Player0View5 + 0x94) - 0x94);
                originalFrame.sp70 += Physics47RandSignedBetweenView4(0, 0x12C);
                originalFrame.sp74 += Physics47RandSignedBetweenView4(0, 0x12C);
                originalFrame.sp78 += Physics47RandSignedBetweenView4(0, 0x12C);
                temp_v0_7 =
                    Controller88028_SpawnParticle(1, 0xD, &originalFrame.sp70, &originalFrame.sp60);
                Physics47Field(temp_v0_7, signed char*, 2) = 6;
                Physics47Field(temp_v0_7, signed char*, 0xA) = 0x20;
            }
            break;
        case 27:
        case 60: {
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int delta18 __asm__("$18");
            register int delta19 __asm__("$20");
            register void* pointer17 __asm__("$19");
            register void* pointer16 __asm__("$16");
            register int limit16 __asm__("$16");
            int originalLow0, originalLow1, originalLow2;
            register void* flightVector17 __asm__("$17");
            register int groundLimit17 __asm__("$17");
            register void* groundPointer18 __asm__("$18");
            pointer17 = &Physics47Player50View1;
            workWord3 = Physics47Field(pointer17, int*, 0);
            workWord2 = 6;
            if (workWord3 != workWord2)
                goto ground27;
            Physics47Call410F8View5(&originalFrame.sp70, pointer17 + 260, 0);
            workWord2 = originalFrame.sp74;
            numeric4 = Physics47Player94View6;
            workWord2 = -workWord2;
            workWord3 = workWord2 * 5;
            workWord3 <<= 2;
            delta18 = workWord3 >> 7;
            numeric4 >>= 3;
            workWord3 = originalFrame.sp70;
            numeric4 -= 1024;
            originalFrame.sp88 = numeric4;
            workWord2 = workWord3 * 5;
            workWord2 <<= 2;
            delta19 = workWord2 >> 7;
            if (numeric4 < 0) {
                pointer16 = &originalFrame.sp80;
                call4 = pointer16;
                call5 = pointer16;
                __asm__ volatile(""
                                 : "=r"(pointer17)
                                 : "0"(pointer17), "r"(call4), "r"(call5)
                                 : "memory");
                flightVector17 = pointer17 - 80;
                call6 = flightVector17;
                workWord2 = Physics47Player8CView2;
                workWord3 = Physics47Player90View2;
                workWord2 >>= 3;
                workWord3 >>= 3;
                originalFrame.sp80 = workWord2;
                originalFrame.sp84 = workWord3;
                Physics47AddVectorView8(call4, call5, call6);
                if (!Physics47Call13E38View2(flightVector17, pointer16, 2)) {
                    workWord2 = Physics47Player8View4;
                    workWord3 = Physics47Data71908View2;
                    workWord2 -= workWord3;
                    workWord2 >>= 3;
                    originalFrame.sp74 = workWord2;
                    workWord2 = workWord2 < 11;
                    if (!workWord2)
                        originalFrame.sp74 = 10;
                    MATCHING_BARRIER_VOLATILE("memory");
                    workWord2 = originalFrame.sp74;
                    delta18 += workWord2;
                }
            }
            workWord2 = Physics47PlayerF8View4;
            workWord3 = Physics47Player8View4;
            workWord3 = workWord2 - workWord3;
            MATCHING_KEEP(workWord3);
            workWord2 = workWord3 < 4096;
            if (workWord2) {
                workWord2 = workWord3 * 3;
                workWord2 <<= 3;
                workWord2 += workWord3;
                workWord2 <<= 5;
                workWord3 = Physics47Player60View4;
                numeric4 = workWord2 >> 12;
                workWord3 = numeric4 - workWord3;
                numeric4 = workWord3 & 4095;
                workWord2 = numeric4 < 2049;
                if (!workWord2) {
                    numeric4 -= 4096;
                    workWord2 = numeric4 < delta18;
                } else
                    workWord2 = numeric4 < delta18;
                if (workWord2)
                    delta18 = numeric4;
            }
            call4 = &Physics47Player64View4;
            workWord2 = Physics47Field(call4, int*, 0);
            workWord3 = Physics47Player60View4;
            workWord2 += delta19;
            workWord2 &= 4095;
            workWord3 += delta18;
            workWord3 &= 4095;
            Physics47Field(call4, int*, 0) = workWord2;
            workWord2 = workWord3 < 2049;
            Physics47Player60View4 = workWord3;
            if (!workWord2) {
                workWord2 = workWord3 - 4096;
                MATCHING_KEEP(workWord2);
                Physics47Player60View4 = workWord2;
            }
            workWord2 = Physics47Player60View4;
            workWord2 = workWord2 < -800;
            if (workWord2)
                Physics47Player60View4 = -800;
            workWord2 = Physics47Player60View4;
            workWord2 = workWord2 < 801;
            if (!workWord2)
                Physics47Player60View4 = 800;
            workWord3 = Physics47Player60View4;
            if (workWord3 >= 0)
                goto positive27;
            numeric4 = Physics47Data67634View2;
            workWord2 = Physics47Data67630View2;
            workWord2 = numeric4 - workWord2;
            goto quotient27;
        positive27:
            if (workWord3 <= 0)
                goto zero27;
            workWord2 = Physics47Data67638View2;
            numeric4 = Physics47Data67634View2;
            workWord2 -= numeric4;
        quotient27:
            workWord2 = workWord3 * workWord2;
            workWord3 = workWord2 / 800;
            numeric4 += workWord3;
            Physics47PlayerACView4 = numeric4;
            goto speed27;
        zero27:
            workWord2 = Physics47Data67634View2;
            Physics47PlayerACView4 = workWord2;
        speed27:
            call5 = &Physics47Player144View4;
            workWord2 = Physics47PlayerACView4;
            numeric4 = Physics47PlayerB0View4;
            workWord3 = Physics47Field(call5, int*, 0);
            workWord2 -= numeric4;
            workWord2 -= workWord3;
            workWord2 = (workWord2 << 6) >> 6;
            workWord3 += workWord2;
            Physics47Field(call5, int*, 0) = workWord3;
            workWord3 >>= 6;
            numeric4 += workWord3;
            Physics47PlayerB0View4 = numeric4;
            numeric4 = numeric4 < 2048;
            if (numeric4)
                Physics47PlayerB0View4 = 2048;
            workWord2 = Physics47PlayerB0View4;
            workWord2 = workWord2 < 19201;
            if (!workWord2)
                Physics47PlayerB0View4 = 19200;
            goto spring27;
        spring27:
            workWord2 = Physics47InterpolateCosineView8(Physics47Player60View4);
            workWord2 <<= 5;
            workWord2 = -workWord2;
            originalLow0 = delta19 * workWord2;
            workWord3 = Physics47Player154View2;
            numeric5 = Physics47Player5CView4;
            workWord2 = (workWord3 << 4) >> 6;
            numeric4 = originalLow0 >> 12;
            numeric4 -= workWord2;
            workWord2 = (numeric5 << 6) >> 6;
            numeric4 -= workWord2;
            workWord3 += numeric4;
            Physics47Player154View2 = workWord3;
            workWord3 >>= 6;
            numeric5 += workWord3;
            numeric5 &= 4095;
            workWord2 = numeric5 < 2049;
            Physics47Player5CView4 = numeric5;
            if (workWord2)
                goto rotationDone27;
            workWord2 = numeric5 - 4096;
        storeAngle27:
            MATCHING_KEEP(workWord2);
            Physics47Player5CView4 = workWord2;
        rotationDone27:
            Physics47Call41848View6();
        finishPhysics50:
            Physics47Call41B64View9();
            return;
        ground27:
            Physics47Call40D10View9(4608);
            workWord2 = Physics47PlayerACView3;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(workWord2, "memory");
            limit16 = 4608;
            MATCHING_KEEP(limit16);
            workWord2 <<= 5;
            groundLimit17 = workWord2 / limit16;
            Physics47ClearVectorView9(pointer17 + 48);
            groundPointer18 = &Physics47Data6E538View7;
            workWord2 = Physics47Field(groundPointer18, int*, 0);
            workWord2 &= 12;
            groundLimit17 += 32;
            if (!workWord2)
                goto noInput27;
            Physics47Call41580View9(25, 5);
            workWord2 = Physics47PlayerB4View1;
            workWord3 = Physics47PlayerACView3;
            workWord2 = workWord2 < 2048;
            Physics47PlayerB0View3 = workWord3;
            if (workWord2) {
                workWord2 = groundLimit17 << 1;
                groundLimit17 += workWord2;
            }
            workWord3 = Physics47Field(groundPointer18, int*, 0);
            workWord2 = workWord3 & 8;
            if (workWord2) {
                Physics47Player84View2 = -4608;
                goto rotateGround27;
            }
            workWord2 = workWord3 & 4;
            if (workWord2)
                Physics47Player84View2 = limit16;
        rotateGround27:
            call4 = &Physics47Player30View1;
            call5 = call4 + 80;
            Physics47TransformVectorByBasisView7(call4, call5, call5);
            goto velocity27;
        noInput27:
            workWord2 = Physics47SubAngle12View1(Physics47Data6E040View5, Physics47PlayerA4View2);
            if (workWord2 < 0)
                workWord2 = -workWord2;
            workWord2 = workWord2 < 1800;
            if (workWord2) {
                Physics47Call41580View9(25, 5);
                workWord2 = Physics47PlayerACView3;
                Physics47PlayerB0View3 = workWord2;
            }
        velocity27:
            pointer16 = &Physics47PlayerA4View2;
            workWord2 = Physics47InterpolateCosineView9(Physics47Field(pointer16, int*, 0));
            workWord3 = Physics47PlayerACView3;
            originalLow1 = workWord3 * workWord2;
            call4 = (void*)Physics47Field(pointer16, int*, 0);
            workWord2 = Physics47Player80View2;
            workWord3 = originalLow1 >> 12;
            workWord2 += workWord3;
            Physics47Player80View2 = workWord2;
            workWord2 = Physics47InterpolateSineView9(call4);
            workWord3 = Physics47PlayerACView3;
            originalLow2 = workWord3 * workWord2;
            call4 = pointer16 - 12;
            Physics47Player88View3 = 0;
            workWord2 = Physics47Player84View2;
            workWord3 = originalLow2 >> 12;
            workWord2 += workWord3;
            Physics47Player84View2 = workWord2;
            workWord2 = Physics47MeasureVectorLengthView9(call4, 0);
            workWord2 = workWord2 < 256;
            pointer16 -= 24;
            if (!workWord2)
                goto vectors27;
            workWord2 = Physics47MeasureVectorLengthView9(pointer16, 0);
            workWord2 = workWord2 < 2049;
            if (!workWord2)
                Physics47ClearVectorView9(pointer16);
        vectors27:
            pointer16 = &originalFrame.sp60;
            call4 = pointer16;
            MATCHING_OBSERVE_VOLATILE_CLOBBER(call4, "memory");
            call5 = &Physics47Player80View2;
            groundPointer18 = call5 + 12;
            Physics47SubtractVectorView9(call4, call5, groundPointer18);
            originalFrame.sp68 = 0;
            workWord2 = Physics47MeasureVectorLengthView9(pointer16, 0);
            numeric5 = workWord2;
            workWord2 = groundLimit17 < numeric5;
            call4 = pointer16;
            if (workWord2)
                Physics47ScaleVectorRatioQ15View9(call4, numeric5, groundLimit17);
            call4 = groundPointer18;
            call5 = call4;
            Physics47AddVectorView9(call4, call5, pointer16);
            workWord2 = -3072;
        store94From2:
            Physics47Player94View5 = workWord2;
            return;
        }
    }
}
#undef Physics47Field


/* AI-generated integration; not human reviewed. SCUS-94467 USA Rev0
 * 8008CABC..8008CC44, 98 original instructions plus dispatch.
 * Baseline verified level27_8008874C; original modes19/27/60 retained.
 * Byte colors and word stores preserve widths. Semantic labels, helper
 * identities, input producers and caller cadence remain unresolved.
 * Test: original linked code/dispatch words and complete retail hashes.
 */
void func_level_47_8008CABC(void) {
    switch (spyro.animationState) {
        case 0x14:
            if (func_800438F4() == 0) {
                func_80043728();
            }
            func_80041C20();
            spyro.unk9a = 0;
            func_80042A44();
            goto clearWord28;
        case 0x1D:
            func_80041C20();
            func_80042A44();
            func_80043A38(0xC00);
            goto clearWord28;
        case 0x13:
            func_80041C20();
            func_80042A44();
            goto run41930;
        case 0x1C:
            func_80041C20();
            func_80042A44();
            func_80041930();
            if ((spyro.unk7a[3].z < 0) && (spyro.animationStateFrames >= 4)) {
                spyro.unk5 = 1;
            }
            goto clearWord28;
        case 0x3A:
            func_80041C20();
            func_80042A44();
            spyro.cheatColour.a = 0xFF;
            spyro.unk4[0] = 0;
            spyro.cheatColour.b = 0x20;
            spyro.cheatColour.g = 0x20;
            spyro.cheatColour.r = 0x20;
            return;

    case 0x1B:
        case 0x3C:
            func_80041C20();
            func_80042A44();
            if (spyro.movementState != 6)
                goto clearWord28;
        run41930:
            func_80041930();
        clearWord28:
            spyro.unk4[0] = 0;
            return;
        default:
            return;
    }
}

#define LEVEL_ID 47
#define PlaySpyroSounds_level_47 func_level_47_8008CC44
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_47_8008CD4C(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
        case 0x14:
        case 0x1D:
        case 0x3A:
            func_80043ABC(&spyro.unk9e);
            break;
        case 0x1B:
        case 0x3C:
            if (*(int*)((char*)&spyro + 0x50) == 6)
                break;
        case 0x13:
        case 0x1C:
            func_80043ABC(0);
            break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 8008CDDC..8008D2F0.
 * Baselines: verified level31_8008DEC0 case1D register/load-delay chain
 * and level27_80088AE4 case1C numeric pointer producers.
 * Original47 supplies case13's S1/S0/A2/A1/V0/V3/A0 chain, private words0/4/8,
 * signed shifts10, numeric pointer offsets and the remaining selector scope.
 * Empty lifetime constraints retain original loads/stores and independent calls;
 * otherwise unused V0 call results establish no helper-return meaning.
 * Source units/producers, audio semantics, helper contracts and caller cadence
 * remain open. Acceptance requires all original linked code/table words and
 * every complete retail EXE/overlay hash. Runtime/browser parity is not proved.
 */
extern Spyro Callback47_D_80070328 __asm__("D_80070328");
int Callback47MeasureVectorLength(Vector3D*, int) __asm__("func_8004EDE8");
int Callback47RandBetween(int low, int high) __asm__("func_8003636C");
void Callback47_func_80043A38(int scale) __asm__("func_80043A38");
void Callback47_func_800441F0(void) __asm__("func_800441F0");
void Callback47ClearVector(Vector3D*) __asm__("func_8004F168");
extern int Callback47_D_8006E524 __asm__("D_8006E524");
extern unsigned char Raw47Union[] __asm__("D_80070328+0x144");
extern int Raw47Movement __asm__("D_80070328+0x50");
void func_level_47_8008CDDC(int selector) {
    register unsigned char* savedBase __asm__("$3");
    register Vector3D* destination __asm__("$4");
    register Vector3D* sourceC __asm__("$16");
    register int oldMovementD __asm__("$6");
    register int oldMovement __asm__("$4");
    register int shiftedZ __asm__("$2");

    int deltaValue;

    short classValue;
    int lengthResult;

    int shiftedValue;
    int maskedValue;
    register unsigned char* privateData __asm__("$16");

    switch (selector) {
        case 0x14:
            Callback47_D_80070328.movementState = MOVEMENT_STATE_STAND;
            Callback47_D_80070328.unk5 = 0;
            Callback47_func_800441F0();
            Callback47_D_80070328.grounded = 1;
            Callback47_D_80070328.union144.a.unk13cb = Callback47RandBetween(1, 3);
            Callback47_D_80070328.union144.a.unk13cc = 0;
            goto clearPointers;
        case 0x13: {
            register Moby* sourceMoby __asm__("$6");
            register int yawValue __asm__("$5");
            register int positionZ __asm__("$2");
            register int heightValue __asm__("$3");
            register int privateValue __asm__("$4");
            privateData = Callback47_D_80070328.m_WhirlwindPointer->mobyTag;
            Callback47_D_80070328.movementState = MOVEMENT_STATE_WHIRLWIND;
            Callback47_D_80070328.unk5 = 0;
            Callback47_D_80070328.grounded = 0;
            Callback47ClearVector(
                (Vector3D*)((unsigned char*)&Callback47_D_80070328.movementState + 0x3C));
            sourceMoby = Callback47_D_80070328.m_WhirlwindPointer;
            yawValue = Callback47_D_80070328.rotation.yaw;
            positionZ = Callback47_D_80070328.position.z;
            heightValue = sourceMoby->position.z;
            privateValue = *(int*)privateData;
            MATCHING_KEEP4(sourceMoby, yawValue, positionZ, heightValue);
            Callback47_D_80070328.union144.a.unk13cc = yawValue;
            Callback47_D_80070328.union144.a.unk13cb = positionZ;
            MATCHING_BARRIER_VOLATILE("memory");
            heightValue += privateValue;
            Callback47_D_80070328.union144.a.unk13ce.x = heightValue;
            heightValue -= positionZ;
            heightValue -= 0x800;
            Callback47_D_80070328.union144.a.unk13ce.z = heightValue;
            deltaValue = heightValue;
            shiftedValue = ((int)(deltaValue << 0xA) >> 0xA) + 0x400;
            Callback47_D_80070328.union144.a.unk13ce.y = shiftedValue;
            maskedValue = (((sourceMoby->angle.yaw * 0x10) - yawValue) - shiftedValue) & 0xFFF;
            Callback47_D_80070328.union144.a.unk13ce.y = maskedValue;
            if (maskedValue >= 0x801) {
                Callback47_D_80070328.union144.a.unk13ce.y = maskedValue - 0x1000;
            }
            Callback47_D_80070328.union144.a.unk13da = *(int*)(privateData + 4);
            func_8004F178((Vector3D*)((unsigned char*)&Callback47_D_80070328.movementState + 0x10C),
                          &sourceMoby->position);
            Callback47_D_80070328.unk13e[0] =
                (int)Callback47_D_80070328.m_WhirlwindPointer->angle.yaw;
            positionZ = *(int*)(privateData + 8);
            MATCHING_KEEP_VOLATILE_CLOBBER(positionZ, "memory");
            Callback47_D_80070328.unk20a = 0;
            Callback47_D_80070328.critterMobyPtr = 0;
            Callback47_D_80070328.unk13e[1] = positionZ;
            return;
        }
        case 0x1D: {
            register int component __asm__("$3");
            register int word __asm__("$2");
            oldMovement = Raw47Movement;
            component = Callback47_D_80070328.unk17e.x;
            MATCHING_KEEP2(oldMovement, component);
            word = 7;
            Raw47Movement = word;
            word = Callback47_D_80070328.unk17e.y;
            Callback47_D_80070328.unk5 = 0;
            MATCHING_KEEP2_VOLATILE_CLOBBER(component, word, "memory");
            component <<= 6;
            Callback47_D_80070328.unk7a[2].x = component;
            component = Callback47_D_80070328.unk17e.z;
            MATCHING_KEEP_VOLATILE_CLOBBER(word, "memory");
            word <<= 6;
            MATCHING_KEEP(word);
            *(int*)Raw47Union = oldMovement;
            Callback47_D_80070328.unk7a[2].y = word;
            shiftedZ = component << 6;
            if (component == 0)
                shiftedZ = Callback47_D_80070328.unk7a[3].z;
            Callback47_D_80070328.unk7a[2].z = shiftedZ;
            Callback47_func_80043A38(0xC00);
            Callback47_D_80070328.grounded = 1;
            Callback47_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            {
                register int soundResult __asm__("$2") =
                    PlaySound((int)D_8006C654->spyroHurt, 0, 0);
                MATCHING_OBSERVE_VOLATILE_CLOBBER(soundResult, "$4");
            }
            goto clearPointers;
        }
        case 0x1C:
            savedBase = Raw47Union;
            MATCHING_KEEP(savedBase);
            destination = (Vector3D*)(savedBase - 0xB8);
            MATCHING_KEEP(destination);
            sourceC = (Vector3D*)(savedBase - 0xAC);
            oldMovementD = Raw47Movement;
            Raw47Movement = MOVEMENT_STATE_HURT;
            Callback47_D_80070328.unk5 = 0;
            *(int*)savedBase = oldMovementD;
            func_8004F178(destination, sourceC);
            Callback47_D_80070328.unk8[0] = Callback47MeasureVectorLength(sourceC, 0);
            Callback47_D_80070328.unk7a[2].z = 0xDC0;
            Callback47_D_80070328.grounded = 0;
            Callback47_D_8006E524 = 0xF;
            if (SpawnParticle != 0) {
                SpawnParticle(5, 0xA, 0, 0);
            }
            if (Callback47_D_80070328.damageFlags & 0x200) {
                Callback47_D_80070328.union144.a.unk13cc = 0;
            } else {
                Callback47_D_80070328.union144.a.unk13cc = 1;
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            goto clearPointers;
        case 0x3A:
            Callback47_D_80070328.movementState = MOVEMENT_STATE_DEATH;
            Callback47_D_80070328.unk5 = 0;
            Callback47_func_80043A38(0xC00);
            Callback47_D_80070328.grounded = 1;
            if ((selector == 0x3A) || (selector == 0x6C)) {
                PlaySound((int)D_8006C654->lavaBurn, 0, 0);
            }
            Callback47_D_8006E524 = 0xF;
        clearPointers:
            Callback47_D_80070328.unk20a = 0;
            Callback47_D_80070328.critterMobyPtr = 0;
            return;
        case 0x1B:
        case 0x3C:
            if ((Callback47_D_80070328.critterMobyPtr != 0) &&
                ((classValue = Callback47_D_80070328.critterMobyPtr->mobyClass,
                  (classValue == 0x2F5)) ||
                 (classValue == 0xF0))) {
                if (Callback47_D_80070328.movementState != MOVEMENT_STATE_SUPERFLY) {
                    Callback47_D_80070328.movementState = MOVEMENT_STATE_SUPERFLY;
                    Callback47_D_80070328.unk5 = 0;
                    Callback47ClearVector(
                        (Vector3D*)((unsigned char*)&Callback47_D_80070328.critterMobyPtr - 0xFC));
                    Callback47_D_80070328.union144.a.unk13db.y = 0;
                    lengthResult = Callback47MeasureVectorLength(
                        (Vector3D*)((unsigned char*)&Callback47_D_80070328.critterMobyPtr - 0x1B8),
                        0);
                    Callback47_D_80070328.unk8[0] = lengthResult;
                    if (lengthResult < 0x800) {
                        Callback47_D_80070328.unk8[0] = 0x800;
                    }
                    if (Callback47_D_80070328.unk8[0] >= 0x4B01) {
                        Callback47_D_80070328.unk8[0] = 0x4B00;
                    }
                    Callback47_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
                    Callback47_D_80070328.union144.b.unk148 = 0;
                    Callback47_D_80070328.union144.a.unk13ce.x = 0;
                    Callback47_D_80070328.union144.a.unk13ce.y = 0;
                    Callback47_D_80070328.grounded = 0;
                    Callback47_D_80070328.unk15b = 0;
                    return;
                }
            } else {
                Callback47_D_80070328.movementState = MOVEMENT_STATE_UNK_12;
                Callback47_D_80070328.unk5 = 0;
                Callback47_D_80070328.unk8[0] = Callback47MeasureVectorLength(
                    (Vector3D*)((unsigned char*)&Callback47_D_80070328.movementState + 0x48), 0);
                Callback47_D_80070328.grounded = 1;
                Callback47_func_80043A38(0xC00);
                Callback47_D_80070328.unk4a = 0x300;
                default:
                    return;
            }
            break;
    }
}

/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level47
 * 8008D2F4: original375 instructions and42 dispatch words in sibling4496
 * and original assembly. Verified40 state/helper and animation-byte C reused.
 * All raw field addresses, selectors and branches follow original47.
 * Meanings, units and cadence unresolved; native/linked/all hash gates required. */
extern int A47W48 __asm__("D_80070328 + 0x48");
extern int A47W4C __asm__("D_80070328 + 0x4C");
extern int A47W54 __asm__("D_80070328 + 0x54");
extern int A47WA0 __asm__("D_80070328 + 0xA0");
extern int A47WA8 __asm__("D_80070328 + 0xA8");
extern int A47WAC __asm__("D_80070328 + 0xAC");
extern int A47WB0 __asm__("D_80070328 + 0xB0");
extern int A47WB8 __asm__("D_80070328 + 0xB8");
extern int A47WCC __asm__("D_80070328 + 0xCC");
extern int A47WD0 __asm__("D_80070328 + 0xD0");
extern int A47WD4 __asm__("D_80070328 + 0xD4");
extern int A47W8C __asm__("D_80070328 + 0x8C");
extern int A47W90 __asm__("D_80070328 + 0x90");
extern int A47W94 __asm__("D_80070328 + 0x94");
extern int A47WE4 __asm__("D_80070328 + 0xE4");
extern int A47W144 __asm__("D_80070328 + 0x144");
extern int A47W158 __asm__("D_80070328 + 0x158");
extern int A47W1EC __asm__("D_80070328 + 0x1EC");
extern int A47W1F0 __asm__("D_80070328 + 0x1F0");
extern int A47W240 __asm__("D_80070328 + 0x240");
extern int A47W280 __asm__("D_80070328 + 0x280");
extern unsigned char A47B14 __asm__("D_80070328 + 0x14");
extern unsigned char A47B15 __asm__("D_80070328 + 0x15");
extern unsigned char A47B16 __asm__("D_80070328 + 0x16");
extern unsigned char A47B17 __asm__("D_80070328 + 0x17");
extern unsigned char A47B1C __asm__("D_80070328 + 0x1C");
extern unsigned char A47BFC __asm__("D_80070328 + 0xFC");
extern unsigned char A47B1B5 __asm__("D_80070328 + 0x1B5");
extern unsigned char A47B1B6 __asm__("D_80070328 + 0x1B6");
extern unsigned char A47Player[] __asm__("D_80070328");
extern unsigned char A47Table[] __asm__("D_80066530");
extern int A47Buttons __asm__("D_8006E538"), A47NewButtons __asm__("D_8006E53C");
extern int A47Mode __asm__("D_8006E044"), A47Gate __asm__("D_8006E344"),
    A47Count __asm__("D_8006C514");
extern int (*A47Callback)(int) __asm__("unk_ovlheader_8007431C");
int A47H40994() __asm__("func_80040994");
int A47H4BEF8() __asm__("func_8004BEF8");
int A47H49688() __asm__("func_80049688");
int A47ApproximatePlanarDistance() __asm__("func_8004F334");
int A47H498C0() __asm__("func_800498C0");
void func_level_47_8008D2F4(void) {
    register int work2 __asm__("$2");
    register int work3 __asm__("$3");
    register int work4 __asm__("$4");
    register int work5 __asm__("$5");
    register int* state __asm__("$16");
    switch (A47W48) {
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 59:
            return;
        case 20:
            if (A47H40994())
                return;
            if (A47NewButtons & 0x40) {
                A47H4BEF8(6);
                return;
            }
            if (A47WB8 >= 4 || A47WE4 >= 23)
                goto set7;
            work3 = A47Buttons;
            if (work3 & 0x80) {
                A47H4BEF8(13);
                return;
            }
            work2 = A47WA8;
            if (work2 < 0)
                work2 = -work2;
            if (work2 >= 17)
                goto set1;
            work2 = work3 & 12;
            MATCHING_KEEP(work2);
            if (!work2 && A47WAC)
                goto set1;
            if (A47Mode == 7 || A47W240) {
                state = &A47W48;
                MATCHING_KEEP(state);
                if (!*state)
                    return;
                A47H4BEF8(0);
                if (A47Table[*((unsigned char*)state - 0x2C)] >= 96) {
                    A47B14 = A47B15;
                    A47B16 = A47B17;
                }
                A47B17 = 0;
                work3 = *state;
                work2 = 113;
                *((unsigned char*)state - 0x2C) = work2;
                A47W1F0 = 0;
                A47B15 = work3;
                A47W1EC = work3;
                return;
            }
            if (A47BFC) {
                A47H4BEF8(15);
                return;
            }
            A47H49688();
            return;
        case 29:
            if (A47W54 < 25)
                return;
            if (A47W280 < 0)
                goto set31;
            work3 = A47W144;
            if (work3 == 10) {
                A47H4BEF8(44);
                return;
            }
            work2 = work3 - 11;
            MATCHING_KEEP(work2);
            if ((unsigned int)work2 < 2) {
                A47H4BEF8(41);
                return;
            }
            if (!A47WB8)
                goto set0;
            goto set7;
        case 19:
            if (A47H40994())
                return;
            if (A47Gate == 13 && A47Count)
                goto set17;
            work2 = A47ApproximatePlanarDistance(A47Player, A47Player + 0x15C);
            work3 = A47W158;
            work3 = work3 < work2;
            MATCHING_KEEP(work3);
            if (!work3)
                return;
            goto set17;
        case 27:
            if (A47W54 < 25)
                return;
            if (A47W280 < 0) {
            set31:
                A47H4BEF8(31);
                return;
            }
            A47H4BEF8(60);
            return;
        case 28:
            if (A47B1B5 && (A47NewButtons & 64))
                A47B1B6 = 1;
            if (A47WB8 || A47W54 < 16 || A47WE4 >= 23)
                goto buttons;
            work3 = A47WCC;
            work2 = A47W8C;
            work5 = work3 * work2;
            work3 = A47WD0;
            work2 = A47W90;
            work4 = work3 * work2;
            work3 = A47WD4;
            work2 = A47W94;
            work3 = work3 * work2;
            work2 = work5 + work4;
            work2 += work3;
            if (work2 >= 0)
                goto buttons;
            if (!A47WAC)
                goto checkSpeed;
            work3 = A47WB0;
            if (work3 > 3840) {
                A47H4BEF8(3);
                return;
            }
            work2 = work3 < 1921;
            MATCHING_KEEP(work2);
            if (!work2) {
                A47H4BEF8(2);
                return;
            }
        set1:
            A47H4BEF8(1);
            return;
        checkSpeed:
            if (A47WB0 < 1920)
                goto set0;
            A47H4BEF8(4);
            return;
        set0:
            A47H4BEF8(0);
            return;
        buttons:
            if ((A47Buttons & 128) && A47W4C == 1) {
                A47H4BEF8(22);
                return;
            }
            if (A47B1B5 && A47B1B6) {
                if (A47W4C != 1)
                    return;
            set17:
                A47H4BEF8(17);
                return;
            }
            if (A47W4C != 1)
                return;
            if (A47WA0 < -6400)
                goto set7;
            if (A47W54 < 91)
                return;
        set7:
            A47H4BEF8(7);
            return;
        case 58:
            if (A47W54 < 137)
                return;
            A47H498C0();
            return;
        case 60:
            A47Callback(1);
            return;
    }
}
