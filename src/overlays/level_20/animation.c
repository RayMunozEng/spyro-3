#include "common.h"
#include "stdutil.h"
#include "spu.h"
#include "ovl_header.h"
#include "spyro.h"

/* AI-generated; not human reviewed. Derived from this function's
 * original SCUS-94467 instructions; native words and targets matched.
 * Raw field units, helper meanings and update cadence remain unresolved. */
/* SCUS-94467 USA Rev0, original800895A0.
 * Assembly SHA256 9a35d6848774dc5c1733f27643003588ffe3b0e849784fd5509f6444e1df50f4.
 * AI-generated; not human reviewed. All1177 original instructions,
 * 45 selectors bias10 and original owned padding are required.
 * Frame0xD0 preserves scratch10..B4,savedS0..S4 and incoming slotS2.
 * Original selector remains A0, bias10. Eight exact physical groups reuse
 * verified21/11/44; original50 omits the final jump by falling straight to
 * the epilogue. Original38 enters50's shared F178 tail,43 enters47's clear
 * calls. All original scalar/vector/water/particle arithmetic remains exact.
 * State10's complete signed64 product retains the previously verified
 * production context and original MFHI division sequence. Every result
 * is initialized. No uninitialized HI input or CPU instruction asm is used.
 * Typed aliases stay distinct. Initialized empty constraints and original
 * address metadata emit zero CPU instructions. Frozen C tools emit words.
 * Raw field units/fixed point, helper contracts and caller cadence remain
 * unresolved; cadence is per invocation, rate unknown.
 * Falsification: every native/linked instruction, actual internal/conditional
 * target, selector/data word and full EXE/every-overlay retail hash.
 * Binary identity does not establish synchronized runtime completeness. */
#define Physics20Field(p,t,o) (*(t)((unsigned char*)(p)+(o)))
int Physics20Call363DCView5() __asm__("func_800363DC");
unsigned char Physics20Call40D10View6() __asm__("func_80040D10");
unsigned char Physics20Call41580View6() __asm__("func_80041580");
unsigned char Physics20Call416F4View6() __asm__("func_800416F4");
unsigned char Physics20Call417FCView6() __asm__("func_800417FC");
unsigned char Physics20Call41B64View6() __asm__("func_80041B64");
int Physics20Call4E9E4View6() __asm__("func_8004E9E4");
int Physics20Call4EA2CView6() __asm__("func_8004EA2C");
unsigned char Physics20Call4ED6CView5() __asm__("func_8004ED6C");
int Physics20Call4EDE8View6() __asm__("func_8004EDE8");
unsigned char Physics20Call4F08CView6() __asm__("func_8004F08C");
unsigned char Physics20Call4F110View4() __asm__("func_8004F110");
unsigned char Physics20Call4F168View6() __asm__("func_8004F168");
unsigned char Physics20Call4F178View6() __asm__("func_8004F178");
unsigned char Physics20Call4F194View6() __asm__("func_8004F194");
unsigned char Physics20Call4F1C8View6() __asm__("func_8004F1C8");
int Physics20CallRandView5() __asm__("rand");
extern unsigned char Physics20Data658A0View6 __asm__("D_800658A0");
extern unsigned char Physics20Data65920View6 __asm__("D_80065920");
extern void *Physics20Data6C570View5 __asm__("D_8006C570");
extern int Physics20Data6C640View6 __asm__("D_8006C640");
extern int Physics20Data6E044View6 __asm__("D_8006E044");
extern unsigned char Physics20Data6E548View6 __asm__("D_8006E548");
extern unsigned char Physics20Player0View6 __asm__("D_80070328");
extern int Physics20Player94View4 __asm__("D_80070328+0x94");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics20Call40D10View7() __asm__("func_80040D10");
int Physics20Call40F48View4() __asm__("func_80040F48");
int Physics20Call410F8View4() __asm__("func_800410F8");
int Physics20Call41404View3() __asm__("func_80041404");
int Physics20Call41580View7() __asm__("func_80041580");
int Physics20Call416F4View7() __asm__("func_800416F4");
int Physics20Call417FCView7() __asm__("func_800417FC");
int Physics20Call41848View5() __asm__("func_80041848");
int Physics20Call41B64View7() __asm__("func_80041B64");
int Physics20Call4E9E4View7() __asm__("func_8004E9E4");
int Physics20Call4EA2CView7() __asm__("func_8004EA2C");
int Physics20Call4EDE8View7() __asm__("func_8004EDE8");
int Physics20Call4F08CView7() __asm__("func_8004F08C");
int Physics20Call4F168View7() __asm__("func_8004F168");
int Physics20Call4F178View7() __asm__("func_8004F178");
int Physics20Call4F194View7() __asm__("func_8004F194");
int Physics20Call4F1C8View7() __asm__("func_8004F1C8");
int Physics20Call4F284View3() __asm__("func_8004F284");
extern unsigned char Physics20Data658A0View7 __asm__("D_800658A0");
extern unsigned char Physics20Data65920View7 __asm__("D_80065920");
extern int Physics20Data6763CView3 __asm__("D_8006763C");
extern int Physics20Data67640View3 __asm__("D_80067640");
extern int Physics20Data67644View3 __asm__("D_80067644");
extern unsigned char Physics20Data676E8View3 __asm__("D_800676E8");
extern int* Physics20Data6C570View6 __asm__("D_8006C570");
extern int Physics20Data6C58CView3 __asm__("D_8006C58C");
extern int Physics20Data6C5C8View3 __asm__("D_8006C5C8");
extern int Physics20Data6C640View7 __asm__("D_8006C640");
extern short Physics20Data6E040View3 __asm__("D_8006E040");
extern int Physics20Data6E044View7 __asm__("D_8006E044");
extern int Physics20Data6E538View5 __asm__("D_8006E538");
extern unsigned char Physics20Data6E548View7 __asm__("D_8006E548");
extern unsigned char Physics20Player0View7 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics20PlayerB8View3 __asm__("D_80070328+0xB8");
extern int Physics20Player94View5 __asm__("D_80070328+0x94");
extern int Physics20PlayerA8View3 __asm__("D_80070328+0xA8");
extern int Physics20Player80View3 __asm__("D_80070328+0x80");
extern int Physics20PlayerB0View3 __asm__("D_80070328+0xB0");
extern int Physics20Player64View3 __asm__("D_80070328+0x64");
extern int Physics20Player88View3 __asm__("D_80070328+0x88");
extern int Physics20Player84View2 __asm__("D_80070328+0x84");
extern int Physics20Player144View3 __asm__("D_80070328+0x144");
extern int Physics20Player60View3 __asm__("D_80070328+0x60");
extern int Physics20PlayerACView3 __asm__("D_80070328+0xAC");
extern int Physics20Player4CView3 __asm__("D_80070328+0x4C");
extern int Physics20Player14CView3 __asm__("D_80070328+0x14C");
extern int Physics20Player5CView3 __asm__("D_80070328+0x5C");
extern unsigned char Physics20PlayerFCView3 __asm__("D_80070328+0xFC");
extern int Physics20PlayerA0View3 __asm__("D_80070328+0xA0");
extern unsigned char Physics20Player1BAView2 __asm__("D_80070328+0x1BA");
extern signed char Physics20Player1B9View2 __asm__("D_80070328+0x1B9");
extern int Physics20Player20CView3 __asm__("D_80070328+0x20C");
extern unsigned char Physics20Player101View2 __asm__("D_80070328+0x101");
extern int Physics20PlayerA4View2 __asm__("D_80070328+0xA4");
extern int Physics20Player210View3 __asm__("D_80070328+0x210");
extern int Physics20PlayerF8View3 __asm__("D_80070328+0xF8");
extern int Physics20Player8View3 __asm__("D_80070328+0x8");
int Physics20Call363DCView6() __asm__("func_800363DC");
int Physics20Call40D10View8() __asm__("func_80040D10");
int Physics20Call40F48View5() __asm__("func_80040F48");
int Physics20Call41580View8() __asm__("func_80041580");
int Physics20Call416F4View8() __asm__("func_800416F4");
int Physics20Call417FCView8() __asm__("func_800417FC");
int Physics20Call41848View6() __asm__("func_80041848");
int Physics20Call41B64View8() __asm__("func_80041B64");
int Physics20Call43194View2() __asm__("func_80043194");
int Physics20Call4E880View3() __asm__("func_8004E880");
int Physics20Call4E9E4View8() __asm__("func_8004E9E4");
int Physics20Call4EA2CView8() __asm__("func_8004EA2C");
int Physics20Call4ED6CView6() __asm__("func_8004ED6C");
int Physics20Call4EDE8View8() __asm__("func_8004EDE8");
int Physics20Call4F08CView8() __asm__("func_8004F08C");
int Physics20Call4F168View8() __asm__("func_8004F168");
int Physics20Call4F178View8() __asm__("func_8004F178");
int Physics20Call4F194View8() __asm__("func_8004F194");
int Physics20Call4F1C8View8() __asm__("func_8004F1C8");
int Physics20Call4F284View4() __asm__("func_8004F284");
int Physics20CallRandView6() __asm__("rand");
extern unsigned char Physics20Data658A0View8 __asm__("D_800658A0");
extern unsigned char Physics20Data65920View8 __asm__("D_80065920");
extern unsigned char Physics20Data676E8View4 __asm__("D_800676E8");
extern int Physics20Data6C514View4 __asm__("D_8006C514");
extern int* Physics20Data6C570View7 __asm__("D_8006C570");
extern int Physics20Data6C58CView4 __asm__("D_8006C58C");
extern int Physics20Data6C5C8View4 __asm__("D_8006C5C8");
extern int Physics20Data6C640View8 __asm__("D_8006C640");
extern short Physics20Data6E040View4 __asm__("D_8006E040");
extern int Physics20Data6E044View8 __asm__("D_8006E044");
extern int Physics20Data6E344View4 __asm__("D_8006E344");
extern int Physics20Data6E538View6 __asm__("D_8006E538");
extern unsigned char Physics20Data6E548View8 __asm__("D_8006E548");
extern unsigned char Physics20Player0View8 __asm__("D_80070328");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics20Player16CView2 __asm__("D_80070328+0x16C");
int Physics20Call13E38View2() __asm__("func_80013E38");
int Physics20Call363DCView7() __asm__("func_800363DC");
int Physics20Call40D10View9() __asm__("func_80040D10");
int Physics20Call410F8View5() __asm__("func_800410F8");
int Physics20Call41580View9() __asm__("func_80041580");
int Physics20Call416F4View9() __asm__("func_800416F4");
int Physics20Call417FCView9() __asm__("func_800417FC");
int Physics20Call41848View7() __asm__("func_80041848");
int Physics20Call41B64View9() __asm__("func_80041B64");
int Physics20Call4E4E4View2() __asm__("func_8004E4E4");
int Physics20Call4E880View4() __asm__("func_8004E880");
int Physics20Call4E9E4View9() __asm__("func_8004E9E4");
int Physics20Call4EA2CView9() __asm__("func_8004EA2C");
int Physics20Call4ED6CView7() __asm__("func_8004ED6C");
int Physics20Call4EDE8View9() __asm__("func_8004EDE8");
int Physics20Call4F08CView9() __asm__("func_8004F08C");
int Physics20Call4F0E8View2() __asm__("func_8004F0E8");
int Physics20Call4F110View5() __asm__("func_8004F110");
int Physics20Call4F168View9() __asm__("func_8004F168");
int Physics20Call4F178View9() __asm__("func_8004F178");
int Physics20Call4F194View9() __asm__("func_8004F194");
int Physics20Call4F1C8View9() __asm__("func_8004F1C8");
int Physics20CallRandView7() __asm__("rand");
extern unsigned char Physics20Data658A0View9 __asm__("D_800658A0");
extern unsigned char Physics20Data65920View9 __asm__("D_80065920");
extern int Physics20Data67630View2 __asm__("D_80067630");
extern int Physics20Data67634View2 __asm__("D_80067634");
extern int Physics20Data67638View2 __asm__("D_80067638");
extern int Physics20Data6C514View5 __asm__("D_8006C514");
extern int Physics20Data6C640View9 __asm__("D_8006C640");
extern int Physics20Data6C7C4View2 __asm__("D_8006C7C4");
extern int Physics20Data6E044View9 __asm__("D_8006E044");
extern int Physics20Data6E344View5 __asm__("D_8006E344");
extern int Physics20Data6E538View7 __asm__("D_8006E538");
extern unsigned char Physics20Data6E548View9 __asm__("D_8006E548");
extern int Physics20Data6FA38View2 __asm__("D_8006FA38");
extern unsigned char Physics20Player0View9 __asm__("D_80070328");
extern int Physics20Data71908View2 __asm__("D_80071908");
extern void *(*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics20Player130View2 __asm__("D_80070328+0x130");
extern int Physics20Player144View4 __asm__("D_80070328+0x144");
extern short Physics20Player148View3 __asm__("D_80070328+0x148");
extern short Physics20Player14AView2 __asm__("D_80070328+0x14A");
extern int Physics20Player14CView4 __asm__("D_80070328+0x14C");
extern int Physics20Player150View2 __asm__("D_80070328+0x150");
extern int Physics20Player154View2 __asm__("D_80070328+0x154");
extern int Physics20Player160View2 __asm__("D_80070328+0x160");
extern int Physics20Player48View2 __asm__("D_80070328+0x48");
extern int Physics20Player4CView4 __asm__("D_80070328+0x4C");
extern int Physics20Player5CView4 __asm__("D_80070328+0x5C");
extern int Physics20Player60View4 __asm__("D_80070328+0x60");
extern int Physics20Player64View4 __asm__("D_80070328+0x64");
extern int Physics20Player8View4 __asm__("D_80070328+0x8");
extern int Physics20Player88View4 __asm__("D_80070328+0x88");
extern int Physics20Player8CView4 __asm__("D_80070328+0x8C");
extern int Physics20Player90View2 __asm__("D_80070328+0x90");
extern int Physics20Player94View6 __asm__("D_80070328+0x94");
extern int Physics20PlayerA8View4 __asm__("D_80070328+0xA8");
extern int Physics20PlayerACView4 __asm__("D_80070328+0xAC");
extern int Physics20PlayerB0View4 __asm__("D_80070328+0xB0");
extern int Physics20PlayerF8View4 __asm__("D_80070328+0xF8");
extern int Physics20Player148View4 __asm__("D_80070328+0x148");
extern int Physics20Player210View4 __asm__("D_80070328+0x210");
extern int Physics20Player220View2 __asm__("D_80070328+0x220");
extern int Physics20Player98View2 __asm__("D_80070328+0x98");
extern int Physics20PlayerA0View4 __asm__("D_80070328+0xA0");
extern int Physics20PlayerB8View4 __asm__("D_80070328+0xB8");
extern int Physics20PlayerCCView2 __asm__("D_80070328+0xCC");
extern int Physics20PlayerD0View2 __asm__("D_80070328+0xD0");
extern int Physics20PlayerE4View2 __asm__("D_80070328+0xE4");
extern unsigned char Physics20PlayerFCView4 __asm__("D_80070328+0xFC");
int Physics20Call363DCView8() __asm__("func_800363DC");
int Physics20Call40D10View10() __asm__("func_80040D10");
int Physics20Call40F48View6() __asm__("func_80040F48");
int Physics20Call410F8View6() __asm__("func_800410F8");
int Physics20Call41404View4() __asm__("func_80041404");
int Physics20Call41580View10() __asm__("func_80041580");
int Physics20Call416F4View10() __asm__("func_800416F4");
int Physics20Call417FCView10() __asm__("func_800417FC");
int Physics20Call41848View8() __asm__("func_80041848");
int Physics20Call41B64View10() __asm__("func_80041B64");
int Physics20Call4E9E4View10() __asm__("func_8004E9E4");
int Physics20Call4EA2CView10() __asm__("func_8004EA2C");
int Physics20Call4ED6CView8() __asm__("func_8004ED6C");
int Physics20Call4EDE8View10() __asm__("func_8004EDE8");
int Physics20Call4F08CView10() __asm__("func_8004F08C");
int Physics20Call4F110View6() __asm__("func_8004F110");
int Physics20Call4F168View10() __asm__("func_8004F168");
int Physics20Call4F178View10() __asm__("func_8004F178");
int Physics20Call4F194View10() __asm__("func_8004F194");
int Physics20Call4F1C8View10() __asm__("func_8004F1C8");
int Physics20CallRandView8() __asm__("rand");
extern unsigned char Physics20Data658A0View10 __asm__("D_800658A0");
extern unsigned char Physics20Data65920View10 __asm__("D_80065920");
extern int Physics20Data6763CView4 __asm__("D_8006763C");
extern int Physics20Data67640View4 __asm__("D_80067640");
extern int Physics20Data67644View4 __asm__("D_80067644");
extern int Physics20Data6C514View6 __asm__("D_8006C514");
extern int* Physics20Data6C570View8 __asm__("D_8006C570");
extern int Physics20Data6C640View10 __asm__("D_8006C640");
extern int Physics20Data6E044View10 __asm__("D_8006E044");
extern int Physics20Data6E344View6 __asm__("D_8006E344");
extern int Physics20Data6E538View8 __asm__("D_8006E538");
extern unsigned char Physics20Data6E548View10 __asm__("D_8006E548");
extern unsigned char Physics20Player0View10 __asm__("D_80070328");
extern void *(*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics20Player8CView5 __asm__("D_80070328+0x8C");
extern int Physics20PlayerB4View2 __asm__("D_80070328+0xB4");
extern int Physics20Player158View2 __asm__("D_80070328+0x158");
extern int Physics20Player20CView4 __asm__("D_80070328+0x20C");
extern void *(*Physics32_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics50_SpawnParticle)() __asm__("SpawnParticle");
extern void *(*Physics42_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics20Player8CView3 __asm__("D_80070328+0x8C");
extern int Physics20Player80View2 __asm__("D_80070328+0x80");
extern void *(*Physics44_SpawnParticle)() __asm__("SpawnParticle");
extern int (*Physics44Slot4454)() __asm__("unk_ovlheader_80074454");
extern int (*Physics44Slot432C)() __asm__("unk_ovlheader_8007432C");
int Physics20Call363DCView5() __asm__("func_800363DC");
unsigned char Physics20Call40D10View6() __asm__("func_80040D10");
unsigned char Physics20Call41580View6() __asm__("func_80041580");
unsigned char Physics20Call416F4View6() __asm__("func_800416F4");
unsigned char Physics20Call417FCView6() __asm__("func_800417FC");
unsigned char Physics20Call41B64View6() __asm__("func_80041B64");
int Physics20Call4E9E4View6() __asm__("func_8004E9E4");
int Physics20Call4EA2CView6() __asm__("func_8004EA2C");
unsigned char Physics20Call4ED6CView5() __asm__("func_8004ED6C");
int Physics20Call4EDE8View6() __asm__("func_8004EDE8");
unsigned char Physics20Call4F08CView6() __asm__("func_8004F08C");
unsigned char Physics20Call4F110View4() __asm__("func_8004F110");
unsigned char Physics20Call4F168View6() __asm__("func_8004F168");
unsigned char Physics20Call4F178View6() __asm__("func_8004F178");
unsigned char Physics20Call4F194View6() __asm__("func_8004F194");
unsigned char Physics20Call4F1C8View6() __asm__("func_8004F1C8");
int Physics20CallRandView5() __asm__("rand");
extern unsigned char Physics20Data658A0View6 __asm__("D_800658A0");
extern unsigned char Physics20Data65920View6 __asm__("D_80065920");
extern void *Physics20Data6C570View5 __asm__("D_8006C570");
extern int Physics20Data6C640View6 __asm__("D_8006C640");
extern int Physics20Data6E044View6 __asm__("D_8006E044");
extern unsigned char Physics20Data6E548View6 __asm__("D_8006E548");
extern unsigned char Physics20Player0View6 __asm__("D_80070328");
extern int Physics20Player94View4 __asm__("D_80070328+0x94");
extern void *(*Controller88028_SpawnParticle)() __asm__("SpawnParticle");
int Physics20Call40D10View7() __asm__("func_80040D10");
int Physics20Call40F48View4() __asm__("func_80040F48");
int Physics20Call410F8View4() __asm__("func_800410F8");
int Physics20Call41404View3() __asm__("func_80041404");
int Physics20Call41580View7() __asm__("func_80041580");
int Physics20Call416F4View7() __asm__("func_800416F4");
int Physics20Call417FCView7() __asm__("func_800417FC");
int Physics20Call41848View5() __asm__("func_80041848");
int Physics20Call41B64View7() __asm__("func_80041B64");
int Physics20Call4E9E4View7() __asm__("func_8004E9E4");
int Physics20Call4EA2CView7() __asm__("func_8004EA2C");
int Physics20Call4EDE8View7() __asm__("func_8004EDE8");
int Physics20Call4F08CView7() __asm__("func_8004F08C");
int Physics20Call4F168View7() __asm__("func_8004F168");
int Physics20Call4F178View7() __asm__("func_8004F178");
int Physics20Call4F194View7() __asm__("func_8004F194");
int Physics20Call4F1C8View7() __asm__("func_8004F1C8");
int Physics20Call4F284View3() __asm__("func_8004F284");
extern unsigned char Physics20Data658A0View7 __asm__("D_800658A0");
extern unsigned char Physics20Data65920View7 __asm__("D_80065920");
extern int Physics20Data6763CView3 __asm__("D_8006763C");
extern int Physics20Data67640View3 __asm__("D_80067640");
extern int Physics20Data67644View3 __asm__("D_80067644");
extern unsigned char Physics20Data676E8View3 __asm__("D_800676E8");
extern int* Physics20Data6C570View6 __asm__("D_8006C570");
extern int Physics20Data6C58CView3 __asm__("D_8006C58C");
extern int Physics20Data6C5C8View3 __asm__("D_8006C5C8");
extern int Physics20Data6C640View7 __asm__("D_8006C640");
extern short Physics20Data6E040View3 __asm__("D_8006E040");
extern int Physics20Data6E044View7 __asm__("D_8006E044");
extern int Physics20Data6E538View5 __asm__("D_8006E538");
extern unsigned char Physics20Data6E548View7 __asm__("D_8006E548");
extern unsigned char Physics20Player0View7 __asm__("D_80070328");
extern void *(*Physics13_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics20PlayerB8View3 __asm__("D_80070328+0xB8");
extern int Physics20Player94View5 __asm__("D_80070328+0x94");
extern int Physics20PlayerA8View3 __asm__("D_80070328+0xA8");
extern int Physics20Player80View3 __asm__("D_80070328+0x80");
extern int Physics20PlayerB0View3 __asm__("D_80070328+0xB0");
extern int Physics20Player64View3 __asm__("D_80070328+0x64");
extern int Physics20Player88View3 __asm__("D_80070328+0x88");
extern int Physics20Player84View2 __asm__("D_80070328+0x84");
extern int Physics20Player144View3 __asm__("D_80070328+0x144");
extern int Physics20Player60View3 __asm__("D_80070328+0x60");
extern int Physics20PlayerACView3 __asm__("D_80070328+0xAC");
extern int Physics20Player4CView3 __asm__("D_80070328+0x4C");
extern int Physics20Player14CView3 __asm__("D_80070328+0x14C");
extern int Physics20Player5CView3 __asm__("D_80070328+0x5C");
extern unsigned char Physics20PlayerFCView3 __asm__("D_80070328+0xFC");
extern int Physics20PlayerA0View3 __asm__("D_80070328+0xA0");
extern unsigned char Physics20Player1BAView2 __asm__("D_80070328+0x1BA");
extern signed char Physics20Player1B9View2 __asm__("D_80070328+0x1B9");
extern int Physics20Player20CView3 __asm__("D_80070328+0x20C");
extern unsigned char Physics20Player101View2 __asm__("D_80070328+0x101");
extern int Physics20PlayerA4View2 __asm__("D_80070328+0xA4");
extern int Physics20Player210View3 __asm__("D_80070328+0x210");
extern int Physics20PlayerF8View3 __asm__("D_80070328+0xF8");
extern int Physics20Player8View3 __asm__("D_80070328+0x8");
int Physics20Call363DCView6() __asm__("func_800363DC");
int Physics20Call40D10View8() __asm__("func_80040D10");
int Physics20Call40F48View5() __asm__("func_80040F48");
int Physics20Call41580View8() __asm__("func_80041580");
int Physics20Call416F4View8() __asm__("func_800416F4");
int Physics20Call417FCView8() __asm__("func_800417FC");
int Physics20Call41848View6() __asm__("func_80041848");
int Physics20Call41B64View8() __asm__("func_80041B64");
int Physics20Call43194View2() __asm__("func_80043194");
int Physics20Call4E880View3() __asm__("func_8004E880");
int Physics20Call4E9E4View8() __asm__("func_8004E9E4");
int Physics20Call4EA2CView8() __asm__("func_8004EA2C");
int Physics20Call4ED6CView6() __asm__("func_8004ED6C");
int Physics20Call4EDE8View8() __asm__("func_8004EDE8");
int Physics20Call4F08CView8() __asm__("func_8004F08C");
int Physics20Call4F168View8() __asm__("func_8004F168");
int Physics20Call4F178View8() __asm__("func_8004F178");
int Physics20Call4F194View8() __asm__("func_8004F194");
int Physics20Call4F1C8View8() __asm__("func_8004F1C8");
int Physics20Call4F284View4() __asm__("func_8004F284");
int Physics20CallRandView6() __asm__("rand");
extern unsigned char Physics20Data658A0View8 __asm__("D_800658A0");
extern unsigned char Physics20Data65920View8 __asm__("D_80065920");
extern unsigned char Physics20Data676E8View4 __asm__("D_800676E8");
extern int Physics20Data6C514View4 __asm__("D_8006C514");
extern int* Physics20Data6C570View7 __asm__("D_8006C570");
extern int Physics20Data6C58CView4 __asm__("D_8006C58C");
extern int Physics20Data6C5C8View4 __asm__("D_8006C5C8");
extern int Physics20Data6C640View8 __asm__("D_8006C640");
extern short Physics20Data6E040View4 __asm__("D_8006E040");
extern int Physics20Data6E044View8 __asm__("D_8006E044");
extern int Physics20Data6E344View4 __asm__("D_8006E344");
extern int Physics20Data6E538View6 __asm__("D_8006E538");
extern unsigned char Physics20Data6E548View8 __asm__("D_8006E548");
extern unsigned char Physics20Player0View8 __asm__("D_80070328");
extern void *(*Physics34_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics20Player16CView2 __asm__("D_80070328+0x16C");
int Physics20Call13E38View2() __asm__("func_80013E38");
int Physics20Call363DCView7() __asm__("func_800363DC");
int Physics20Call40D10View9() __asm__("func_80040D10");
int Physics20Call410F8View5() __asm__("func_800410F8");
int Physics20Call41580View9() __asm__("func_80041580");
int Physics20Call416F4View9() __asm__("func_800416F4");
int Physics20Call417FCView9() __asm__("func_800417FC");
int Physics20Call41848View7() __asm__("func_80041848");
int Physics20Call41B64View9() __asm__("func_80041B64");
int Physics20Call4E4E4View2() __asm__("func_8004E4E4");
int Physics20Call4E880View4() __asm__("func_8004E880");
int Physics20Call4E9E4View9() __asm__("func_8004E9E4");
int Physics20Call4EA2CView9() __asm__("func_8004EA2C");
int Physics20Call4ED6CView7() __asm__("func_8004ED6C");
int Physics20Call4EDE8View9() __asm__("func_8004EDE8");
int Physics20Call4F08CView9() __asm__("func_8004F08C");
int Physics20Call4F0E8View2() __asm__("func_8004F0E8");
int Physics20Call4F110View5() __asm__("func_8004F110");
int Physics20Call4F168View9() __asm__("func_8004F168");
int Physics20Call4F178View9() __asm__("func_8004F178");
int Physics20Call4F194View9() __asm__("func_8004F194");
int Physics20Call4F1C8View9() __asm__("func_8004F1C8");
int Physics20CallRandView7() __asm__("rand");
extern unsigned char Physics20Data658A0View9 __asm__("D_800658A0");
extern unsigned char Physics20Data65920View9 __asm__("D_80065920");
extern int Physics20Data67630View2 __asm__("D_80067630");
extern int Physics20Data67634View2 __asm__("D_80067634");
extern int Physics20Data67638View2 __asm__("D_80067638");
extern int Physics20Data6C514View5 __asm__("D_8006C514");
extern int Physics20Data6C640View9 __asm__("D_8006C640");
extern int Physics20Data6C7C4View2 __asm__("D_8006C7C4");
extern int Physics20Data6E044View9 __asm__("D_8006E044");
extern int Physics20Data6E344View5 __asm__("D_8006E344");
extern int Physics20Data6E538View7 __asm__("D_8006E538");
extern unsigned char Physics20Data6E548View9 __asm__("D_8006E548");
extern int Physics20Data6FA38View2 __asm__("D_8006FA38");
extern unsigned char Physics20Player0View9 __asm__("D_80070328");
extern int Physics20Data71908View2 __asm__("D_80071908");
extern void *(*Physics12_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics20Player130View2 __asm__("D_80070328+0x130");
extern int Physics20Player144View4 __asm__("D_80070328+0x144");
extern short Physics20Player148View3 __asm__("D_80070328+0x148");
extern short Physics20Player14AView2 __asm__("D_80070328+0x14A");
extern int Physics20Player14CView4 __asm__("D_80070328+0x14C");
extern int Physics20Player150View2 __asm__("D_80070328+0x150");
extern int Physics20Player154View2 __asm__("D_80070328+0x154");
extern int Physics20Player160View2 __asm__("D_80070328+0x160");
extern int Physics20Player48View2 __asm__("D_80070328+0x48");
extern int Physics20Player4CView4 __asm__("D_80070328+0x4C");
extern int Physics20Player5CView4 __asm__("D_80070328+0x5C");
extern int Physics20Player60View4 __asm__("D_80070328+0x60");
extern int Physics20Player64View4 __asm__("D_80070328+0x64");
extern int Physics20Player8View4 __asm__("D_80070328+0x8");
extern int Physics20Player88View4 __asm__("D_80070328+0x88");
extern int Physics20Player8CView4 __asm__("D_80070328+0x8C");
extern int Physics20Player90View2 __asm__("D_80070328+0x90");
extern int Physics20Player94View6 __asm__("D_80070328+0x94");
extern int Physics20PlayerA8View4 __asm__("D_80070328+0xA8");
extern int Physics20PlayerACView4 __asm__("D_80070328+0xAC");
extern int Physics20PlayerB0View4 __asm__("D_80070328+0xB0");
extern int Physics20PlayerF8View4 __asm__("D_80070328+0xF8");
extern int Physics20Player148View4 __asm__("D_80070328+0x148");
extern int Physics20Player210View4 __asm__("D_80070328+0x210");
extern int Physics20Player220View2 __asm__("D_80070328+0x220");
extern int Physics20Player98View2 __asm__("D_80070328+0x98");
extern int Physics20PlayerA0View4 __asm__("D_80070328+0xA0");
extern int Physics20PlayerB8View4 __asm__("D_80070328+0xB8");
extern int Physics20PlayerCCView2 __asm__("D_80070328+0xCC");
extern int Physics20PlayerD0View2 __asm__("D_80070328+0xD0");
extern int Physics20PlayerE4View2 __asm__("D_80070328+0xE4");
extern unsigned char Physics20PlayerFCView4 __asm__("D_80070328+0xFC");
int Physics20Call363DCView8() __asm__("func_800363DC");
int Physics20Call40D10View10() __asm__("func_80040D10");
int Physics20Call40F48View6() __asm__("func_80040F48");
int Physics20Call410F8View6() __asm__("func_800410F8");
int Physics20Call41404View4() __asm__("func_80041404");
int Physics20Call41580View10() __asm__("func_80041580");
int Physics20Call416F4View10() __asm__("func_800416F4");
int Physics20Call417FCView10() __asm__("func_800417FC");
int Physics20Call41848View8() __asm__("func_80041848");
int Physics20Call41B64View10() __asm__("func_80041B64");
int Physics20Call4E9E4View10() __asm__("func_8004E9E4");
int Physics20Call4EA2CView10() __asm__("func_8004EA2C");
int Physics20Call4ED6CView8() __asm__("func_8004ED6C");
int Physics20Call4EDE8View10() __asm__("func_8004EDE8");
int Physics20Call4F08CView10() __asm__("func_8004F08C");
int Physics20Call4F110View6() __asm__("func_8004F110");
int Physics20Call4F168View10() __asm__("func_8004F168");
int Physics20Call4F178View10() __asm__("func_8004F178");
int Physics20Call4F194View10() __asm__("func_8004F194");
int Physics20Call4F1C8View10() __asm__("func_8004F1C8");
int Physics20CallRandView8() __asm__("rand");
extern unsigned char Physics20Data658A0View10 __asm__("D_800658A0");
extern unsigned char Physics20Data65920View10 __asm__("D_80065920");
extern int Physics20Data6763CView4 __asm__("D_8006763C");
extern int Physics20Data67640View4 __asm__("D_80067640");
extern int Physics20Data67644View4 __asm__("D_80067644");
extern int Physics20Data6C514View6 __asm__("D_8006C514");
extern int* Physics20Data6C570View8 __asm__("D_8006C570");
extern int Physics20Data6C640View10 __asm__("D_8006C640");
extern int Physics20Data6E044View10 __asm__("D_8006E044");
extern int Physics20Data6E344View6 __asm__("D_8006E344");
extern int Physics20Data6E538View8 __asm__("D_8006E538");
extern unsigned char Physics20Data6E548View10 __asm__("D_8006E548");
extern unsigned char Physics20Player0View10 __asm__("D_80070328");
extern void *(*Physics21_SpawnParticle)() __asm__("SpawnParticle");
extern int Physics20Player8CView5 __asm__("D_80070328+0x8C");
extern int Physics20PlayerB4View2 __asm__("D_80070328+0xB4");
extern int Physics20Player158View2 __asm__("D_80070328+0x158");
extern int Physics20Player20CView4 __asm__("D_80070328+0x20C");
void func_level_20_800895A0(int slotIndex) {
    register int stateSelector4 __asm__("$4");
    int agentProduct0,agentProduct1,agentProduct2,agentProduct3,agentProduct4,agentProduct5,agentProduct6,agentProduct7;
    register void *fieldA4State28 __asm__("$16");
    register void *vector8CState28 __asm__("$17");
    register int signedWord19 __asm__("$20");
    register int signedWord20 __asm__("$21");
    register int signedWord21 __asm__("$22");
    register void *savedPointer22 __asm__("$19");
    register void *savedPointer17 __asm__("$17");
    register void *(*particleCall3)() __asm__("$3");
    register int particleArg7 __asm__("$7");
    register int workWord2 __asm__("$2");
    register void *vectorAt30 __asm__("$17");
    register void *call4 __asm__("$4");
    register void *call5 __asm__("$5");
    register void *call6 __asm__("$6");
    int lowProduct0,lowProduct1,lowProduct2,lowProduct3,lowProduct4,lowProduct5;
    register void *globalPointer __asm__("$3");
    struct {
        int sp10,sp14,sp18,sp1C,sp20,sp24,sp28,sp2C,sp30,sp34,sp38,sp3C,sp40,sp44,sp48,sp4C,sp50,sp54,sp58,sp5C,sp60,sp64,sp68,sp6C,sp70,sp74,sp78,sp7C,sp80,sp84,sp88,sp8C,sp90,sp94,sp98,sp9C,spA0,spA4,spA8,spAC,spB0,spB4;
    }
    originalFrame;
    register void *globalVector80 __asm__("$16");
    register void *globalVector8CState20 __asm__("$18");
    register int workWord3 __asm__("$3");
    register void *globalField4CPointer __asm__("$16");
    register void *globalFieldA4Pointer __asm__("$17");
    register int savedSlotIndex __asm__("$18");
    int lowProduct6;
    int raw21_var_a0_2;
    int raw21_var_a1_4;
    void *raw21_temp_s0_9;
    int raw21_temp_a0_5;
    int raw21_temp_a0_6;
    int raw21_temp_a0_7;
    int raw21_temp_a1_2;
    int raw21_temp_a1_3;
    int raw21_temp_a1_4;
    int raw21_temp_s0_10;
    register int raw21_temp_s0_8 __asm__("$16");
    int raw21_temp_s1_4;
    int raw21_temp_v1_13;
    int raw21_temp_v1_14;
    int raw21_temp_v1_6;
    int raw21_temp_v1_7;
    int raw21_var_v0_2;
    void *raw21_temp_s0_11;
    void *raw21_temp_s0_7;
    register void *raw21_temp_s1_5 __asm__("$17");
    void *raw21_temp_s1_6;
    void *raw21_temp_s1_7;
    void *raw21_temp_s2_3;
    void *raw21_temp_s4;
    savedSlotIndex=slotIndex;
    workWord2=savedSlotIndex*16;
    globalPointer=&Physics20Data6E548View6;
    stateSelector4=Physics20Field(&Physics20Player0View6,int*,0x48);
    __asm__("":"=r"(globalPointer):"0"(globalPointer),"r"(stateSelector4),"r"(workWord2));
    workWord2+=(int)globalPointer;
    Physics20Data6C570View5=(void*)workWord2;
    switch(stateSelector4){
        default:return;
    case 20:case 53:case 54:globalVector80 = &Physics20Player0View6 + 0x80;
        Physics20Call4F168View6(globalVector80);
        Physics20Call4F168View6(globalVector80 + 0xC);
        if (Physics20Data6E044View6 != 7) {
            Physics20Call40D10View6(0x1200);
            Physics20Call416F4View6();
            Physics20Call41580View6(0x5A, 0x10);
            return;
        }
        return;
    case 10:case 11:case 12:{
            register void *pointer16 __asm__("$16");
            register int limit17 __asm__("$17");
            int product10a,product10b;
            union {
                long long wide;
                struct {
                    int high;
                    unsigned int low;
                }
                words;
            }
            product144;
            workWord3=Physics20Data6E044View10;
            workWord2=7;
            call4=(void*)50;
            if(workWord3!=workWord2){
                Physics20Call40D10View10(4608);
                call4=(void*)50;
            }
            else{
                workWord2=Physics20Player64View3;
                Physics20PlayerACView3=0;
                Physics20PlayerA4View2=workWord2;
            }
            Physics20Call41580View10(call4,10);
            workWord3=0x38E30000;
            __asm__("":"=r"(workWord3):"0"(workWord3));
            pointer16=&Physics20PlayerACView3;
            workWord2=Physics20Field(pointer16,int*,0);
            workWord3|=0x8E39;
            product144.wide=(long long)workWord2*workWord3;
            call4=(void*)Physics20PlayerA4View2;
            Physics20PlayerB0View3=workWord2;
            workWord2>>=31;
            workWord3=product144.words.high>>5;
            limit17=workWord3-workWord2;
            workWord2=Physics20Call4EA2CView10(call4);
            workWord3=Physics20PlayerB0View3;
            product10a=workWord3*workWord2;
            call4=(void*)Physics20PlayerA4View2;
            workWord2=product10a>>12;
            __asm__("":"=r"(workWord2),"=r"(pointer16):"0"(workWord2),"1"(pointer16));
            Physics20Field(pointer16,int*,-44)=workWord2;
            workWord2=Physics20Call4E9E4View10(call4);
            workWord3=Physics20PlayerB0View3;
            product10b=workWord3*workWord2;
            __asm__("":"=r"(limit17):"0"(limit17),"r"(workWord2),"r"(workWord3));
            limit17+=32;
            call4=&originalFrame.sp10;
            __asm__ volatile(""::"r"(call4):"memory");
            call5=pointer16-44;
            pointer16-=32;
            Physics20Player88View3=0;
            workWord2=product10b>>12;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics20Player84View2=workWord2;
            __asm__ volatile("":"=r"(pointer16):"0"(pointer16):"memory");
            Physics20Call4F1C8View10(call4,call5,pointer16);
            originalFrame.sp18=0;
            call5=(void*)Physics20Call4EDE8View10(&originalFrame.sp10,0);
            workWord2=limit17<(int)call5;
            if(workWord2)Physics20Call4F08CView10(&originalFrame.sp10,call5,limit17);
            call4=pointer16;
            call5=call4;
            Physics20Call4F194View10(call4,call5,&originalFrame.sp10);
            workWord2=Physics20PlayerB4View2;
            workWord3=-3072;
            Physics20Player94View5=workWord3;
            workWord2=workWord2<65;
            if(workWord2){
                Physics20Player1B9View2=1;
                return;
            }
            Physics20Player1B9View2=0;
            return;
        }
    case 38:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            Physics20Call410F8View4(&originalFrame.sp20,&Physics20Player14CView3,0);
            workWord3=Physics20Player60View3;
            workWord2=workWord3+800;
            workWord2=(unsigned int)workWord2<1825;
            if(!workWord2){
                __asm__ volatile("":::"$2");
                globalVector80=0;
                numeric5=23;
                goto rotate38;
            }
            workWord2=workWord3<801;
            if(!workWord2){
                workWord3=originalFrame.sp24;
                workWord3=-workWord3;
                __asm__("":"=r"(workWord3):"0"(workWord3));
                workWord2=workWord3*23;
                workWord3=originalFrame.sp20;
                __asm__(""::"r"(workWord3),"r"(workWord2));
                numeric5=workWord2>>8;
                goto lateral38;
            }
            workWord3=originalFrame.sp24;
            workWord3=-workWord3;
            __asm__("":"=r"(workWord3):"0"(workWord3));
            workWord2=workWord3*23;
            workWord3=originalFrame.sp20;
            __asm__(""::"r"(workWord3),"r"(workWord2));
            numeric5=workWord2>>7;
            lateral38:workWord2=workWord3*30;
            globalVector80=(void*)(workWord2>>7);
            rotate38:call4=&Physics20Player64View3;
            workWord2=Physics20Field(call4,int*,0);
            workWord3=Physics20Player60View3;
            workWord2+=(int)globalVector80;
            workWord2&=4095;
            workWord3+=numeric5;
            workWord3&=4095;
            Physics20Field(call4,int*,0)=workWord2;
            workWord2=workWord3<2049;
            Physics20Player60View3=workWord3;
            if(!workWord2){
                workWord2=workWord3-4096;
                __asm__("":"=r"(workWord2):"0"(workWord2));
                Physics20Player60View3=workWord2;
            }
            workWord2=Physics20Data6E538View5;
            workWord3=6144;
            Physics20PlayerACView3=workWord3;
            workWord2&=192;
            if(workWord2){
                workWord2=12800;
                Physics20PlayerACView3=workWord2;
            }
            workWord3=Physics20Player4CView3;
            workWord2=2;
            if(workWord3==workWord2){
                Physics20Call417FCView7(320,192);
                workWord2=Physics20PlayerB0View3<6145;
                if(workWord2)Physics20Player4CView3=0;
            }
            else Physics20Call417FCView7(320,80);
            globalFieldA4Pointer=&Physics20Player60View3;
            __asm__("":"=r"(globalFieldA4Pointer):"0"(globalFieldA4Pointer));
            workWord2=Physics20Call4EA2CView7(Physics20Field(globalFieldA4Pointer,int*,0));
            workWord2<<=5;
            workWord2=-workWord2;
            lowProduct5=(int)globalVector80*workWord2;
            workWord3=Physics20Player14CView3;
            numeric5=Physics20Player5CView3;
            workWord2=(workWord3<<4)>>6;
            numeric4=lowProduct5>>12;
            numeric4-=workWord2;
            workWord2=(numeric5<<6)>>6;
            numeric4-=workWord2;
            workWord3+=numeric4;
            Physics20Player14CView3=workWord3;
            workWord3>>=6;
            numeric5+=workWord3;
            numeric5&=4095;
            workWord2=numeric5<2049;
            Physics20Player5CView3=numeric5;
            if(!workWord2){
                workWord2=numeric5-4096;
                Physics20Player5CView3=workWord2;
            }
            workWord2=Physics20Player5CView3;
            workWord2=workWord2<-768;
            if(workWord2){
                workWord2=-768;
                Physics20Player5CView3=workWord2;
            }
            workWord2=Physics20Player5CView3;
            workWord2=workWord2<769;
            if(!workWord2){
                workWord2=768;
                Physics20Player5CView3=workWord2;
            }
            Physics20Call41848View5(numeric4,numeric5);
            goto vectorFinal50;
        }
    case 40:{
            register int numeric4 __asm__("$4");
            call5=&Physics20Player20CView4;
            __asm__("":"=r"(call5):"0"(call5));
            workWord2=Physics20Field(call5,int*,0)&64;
            call4=&originalFrame.sp28;
            if(workWord2)goto block_132;
            call5-=192;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics20Call410F8View6(call4,call5,0);
            workWord3=Physics20Player4CView3;
            workWord2=1;
            if(workWord3==workWord2){
                workWord2=512;
                workWord3=Physics20Player60View3;
                numeric4=Physics20Player144View3;
                workWord2-=workWord3;
                workWord3=numeric4<<4;
                workWord2-=workWord3;
                workWord3=workWord2&4095;
                originalFrame.sp2C=workWord3;
                workWord2=workWord3<2049;
                if(!workWord2){
                    workWord2=workWord3-4096;
                    __asm__("":"=r"(workWord2):"0"(workWord2));
                    originalFrame.sp2C=workWord2;
                }
                __asm__ volatile("":::"memory");
                workWord2=originalFrame.sp2C;
                workWord3=numeric4+1;
                Physics20Player144View3=workWord3;
                workWord3=workWord3<21;
                workWord2=(workWord2<<7)>>8;
                originalFrame.sp2C=workWord2;
                if(!workWord3){
                    __asm__ volatile("":"=r"(workWord3):"0"(workWord3));
                    Physics20Player4CView3=0;
                }
            }
            raw21_temp_s1_4 = (int) (originalFrame.sp28 * 0x14) >> 7;
            Physics20Field(&Physics20Player0View10, int *, 0x64) = (int) ((Physics20Field(&Physics20Player0View10, int *, 0x64) + raw21_temp_s1_4) & 0xFFF);
            raw21_temp_v1_6 = (Physics20Field(&Physics20Player0View10, int *, 0x60) + ((int) (originalFrame.sp2C * -0xF) >> 7)) & 0xFFF;
            Physics20Field(&Physics20Player0View10, int *, 0x60) = raw21_temp_v1_6;
            if (raw21_temp_v1_6 >= 0x801) {
                Physics20Field(&Physics20Player0View10, int *, 0x60) = (int) (raw21_temp_v1_6 - 0x1000);
            }
            if (Physics20Field(&Physics20Player0View10, int *, 0x60) < -0x320) {
                Physics20Field(&Physics20Player0View10, int *, 0x60) = -0x320;
            }
            if (Physics20Field(&Physics20Player0View10, int *, 0x60) >= 0x321) {
                Physics20Field(&Physics20Player0View10, int *, 0x60) = 0x320;
            }
            if ((*Physics20Data6C570View8 & 0x40) || (Physics20Field(&Physics20Player0View10, int *, 0x4C) == 1)) {
                Physics20Field(&Physics20Player0View10, int *, 0xAC) = 0xE00;
            }
            else {
                Physics20Field(&Physics20Player0View10, int *, 0xAC) = 0;
            }
            if (Physics20Field(&Physics20Player0View10, int *, 0x4C) == 2) {
                Physics20Call417FCView10(0xC0, 0xC0);
                if (Physics20Field(&Physics20Player0View10, int *, 0xB0) < 0xE01) {
                    Physics20Field(&Physics20Player0View10, int *, 0x4C) = 0;
                }
            }
            else {
                Physics20Call417FCView10(0xC0, 0x30);
            }
            raw21_temp_s0_7 = &Physics20Player0View10 + 0x60;
            raw21_temp_a0_5 = (((int) (raw21_temp_s1_4 * -(Physics20Call4EA2CView10(Physics20Field(&Physics20Player0View10, int *, 0x60)) << 5)) >> 0xC) - ((int) (Physics20Field(&Physics20Player0View10, int *, 0x14C) * 0x10) >> 6)) - ((int) (Physics20Field(&Physics20Player0View10, int *, 0x5C) << 6) >> 6);
            raw21_temp_v1_7 = Physics20Field(&Physics20Player0View10, int *, 0x14C) + raw21_temp_a0_5;
            Physics20Field(&Physics20Player0View10, int *, 0x14C) = raw21_temp_v1_7;
            raw21_temp_a1_2 = (Physics20Field(&Physics20Player0View10, int *, 0x5C) + (raw21_temp_v1_7 >> 6)) & 0xFFF;
            Physics20Field(&Physics20Player0View10, int *, 0x5C) = raw21_temp_a1_2;
            if (raw21_temp_a1_2 >= 0x801) {
                Physics20Field(&Physics20Player0View10, int *, 0x5C) = (int) (raw21_temp_a1_2 - 0x1000);
            }
            if (Physics20Field(&Physics20Player0View10, int *, 0x5C) < -0x300) {
                Physics20Field(&Physics20Player0View10, int *, 0x5C) = -0x300;
            }
            if (Physics20Field(&Physics20Player0View10, int *, 0x5C) >= 0x301) {
                Physics20Field(&Physics20Player0View10, int *, 0x5C) = 0x300;
            }
            Physics20Call41848View8(raw21_temp_a0_5, raw21_temp_a1_2);
            Physics20Call4F178View10(raw21_temp_s0_7 + 0x2C, raw21_temp_s0_7 + 0x20);
            workWord2=Physics20CallRandView8()&31;
            if(workWord2)goto block_130;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            particleCall3=Physics21_SpawnParticle;
            call4=(void*)1;
            if(!particleCall3)goto block_130;
            call5=(void*)44;
            call6=&originalFrame.sp30;
            particleArg7=0;
            __asm__("":"=r"(particleArg7):"0"(particleArg7));
            workWord2=544;
            originalFrame.sp30=workWord2;
            workWord2=64;
            originalFrame.sp34=0;
            __asm__ volatile(""::"i"(0x80089CD8):"memory");
            originalFrame.sp38=workWord2;
            goto block_129;
        }
    case 41:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            int product41;
            raw21_temp_s1_5 = &Physics20Player0View10 + 0x20C;
            if (!(Physics20Field(&Physics20Player0View10, int *, 0x20C) & 0x40)) {
                if (Physics20Data6E044View10 != 7) {
                    Physics20Call410F8View6(&originalFrame.sp30, raw21_temp_s1_5 - 0xC0, 0);
                    workWord3=originalFrame.sp30;
                    numeric4=originalFrame.sp34;
                    workWord2=workWord3*5;
                    workWord2<<=2;
                    raw21_temp_s0_8=workWord2>>7;
                    workWord2=numeric4<<4;
                    numeric4-=workWord2;
                    numeric4>>=7;
                    workWord3=Physics20Player64View3;
                    workWord2=Physics20Player60View3;
                    workWord3+=raw21_temp_s0_8;
                    workWord3&=4095;
                    workWord2+=numeric4;
                    Physics20Player64View3=workWord3;
                    workWord3=workWord2&4095;
                    workWord2=workWord3<2049;
                    Physics20Player60View3=workWord3;
                    if(!workWord2){
                        workWord2=workWord3-4096;
                        __asm__("":"=r"(workWord2):"0"(workWord2));
                        Physics20Player60View3=workWord2;
                    }
                    if (Physics20Field(&Physics20Player0View10, int *, 0x60) < -0x320) {
                        Physics20Field(&Physics20Player0View10, int *, 0x60) = -0x320;
                    }
                    if (Physics20Field(&Physics20Player0View10, int *, 0x60) >= 0x321) {
                        Physics20Field(&Physics20Player0View10, int *, 0x60) = 0x320;
                    }
                    workWord2=Physics20Call4EA2CView10(Physics20Player60View3);
                    workWord2<<=5;
                    workWord2=-workWord2;
                    product41=raw21_temp_s0_8*workWord2;
                    workWord3=Physics20Field(raw21_temp_s1_5,int*,-192);
                    numeric5=Physics20Player5CView3;
                    workWord2=(workWord3<<4)>>6;
                    numeric4=product41>>12;
                    numeric4-=workWord2;
                    workWord2=(numeric5<<6)>>6;
                    numeric4-=workWord2;
                    workWord3+=numeric4;
                    Physics20Field(raw21_temp_s1_5,int*,-192)=workWord3;
                    workWord3>>=6;
                    numeric5+=workWord3;
                    numeric5&=4095;
                    workWord2=numeric5<2049;
                    Physics20Player5CView3=numeric5;
                    if(!workWord2){
                        workWord2=numeric5-4096;
                        __asm__("":"=r"(workWord2):"0"(workWord2));
                        Physics20Player5CView3=workWord2;
                    }
                    if (Physics20Field(&Physics20Player0View10, int *, 0x5C) < -0x300) {
                        Physics20Field(&Physics20Player0View10, int *, 0x5C) = -0x300;
                    }
                    if (Physics20Field(&Physics20Player0View10, int *, 0x5C) >= 0x301) {
                        Physics20Field(&Physics20Player0View10, int *, 0x5C) = 0x300;
                    }
                }
                raw21_temp_s0_9 = &Physics20Player0View10 + 0x80;
                Physics20Call4F168View10(raw21_temp_s0_9);
                Physics20Call4F168View10(raw21_temp_s0_9 + 0xC);
                workWord2=Physics20CallRandView8()&31;
                if(workWord2)goto block_130;
                __asm__("":"=r"(workWord2):"0"(workWord2));
                particleCall3=Physics21_SpawnParticle;
                call4=(void*)1;
                if(!particleCall3)goto block_130;
                call5=(void*)44;
                call6=&originalFrame.sp40;
                particleArg7=0;
                __asm__("":"=r"(particleArg7):"0"(particleArg7));
                workWord2=544;
                originalFrame.sp40=workWord2;
                workWord2=64;
                originalFrame.sp44=0;
                originalFrame.sp48=workWord2;
                block_129:particleCall3(call4,call5,call6,particleArg7);
                block_130:globalPointer=&Physics20Player158View2;
                workWord2=Physics20Field(globalPointer,int*,0);
                workWord2++;
                Physics20Field(globalPointer,int*,0)=workWord2;
                return;
            }
            goto block_132;
        }
    case 42:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            call5=&Physics20Player20CView4;
            __asm__("":"=r"(call5):"0"(call5));
            workWord2=Physics20Field(call5,int*,0)&64;
            call4=&originalFrame.sp40;
            if(!workWord2)goto run42;
            block_132:Physics20PlayerACView3=0;
            Physics20PlayerB0View3=0;
            return;
            run42:call5-=192;
            __asm__("":"=r"(workWord2):"0"(workWord2));
            Physics20Call410F8View6(call4,call5,0);
            workWord3=Physics20Player4CView3;
            workWord2=1;
            if(workWord3==workWord2){
                workWord2=512;
                workWord3=Physics20Player60View3;
                numeric5=Physics20Player144View3;
                workWord2-=workWord3;
                workWord3=numeric5<<4;
                workWord2-=workWord3;
                workWord3=workWord2&4095;
                originalFrame.sp44=workWord3;
                workWord2=workWord3<2049;
                if(!workWord2){
                    workWord2=workWord3-4096;
                    __asm__("":"=r"(workWord2):"0"(workWord2));
                    originalFrame.sp44=workWord2;
                }
                __asm__ volatile("":::"memory");
                numeric4=originalFrame.sp44;
                workWord3=numeric5+1;
                Physics20Player144View3=workWord3;
                workWord3=workWord3<13;
                workWord2=numeric4*3;
                workWord2<<=5;
                workWord2>>=8;
                originalFrame.sp44=workWord2;
                if(!workWord3){
                    __asm__ volatile("":"=r"(workWord3):"0"(workWord3));
                    Physics20Player4CView3=0;
                }
            }
            raw21_temp_s1_6 = &Physics20Player0View10 + 0x64;
            raw21_temp_s0_10 = (int) (originalFrame.sp40 * 0x14) >> 7;
            Physics20Field(&Physics20Player0View10, int *, 0x64) = (int) ((Physics20Field(&Physics20Player0View10, int *, 0x64) + raw21_temp_s0_10) & 0xFFF);
            raw21_temp_v1_13 = (Physics20Field(&Physics20Player0View10, int *, 0x60) + ((int) (originalFrame.sp44 * -0xF) >> 7)) & 0xFFF;
            Physics20Field(&Physics20Player0View10, int *, 0x60) = raw21_temp_v1_13;
            if (raw21_temp_v1_13 >= 0x801) {
                Physics20Field(&Physics20Player0View10, int *, 0x60) = (int) (raw21_temp_v1_13 - 0x1000);
            }
            if (Physics20Field(&Physics20Player0View10, int *, 0x60) < -0x320) {
                Physics20Field(&Physics20Player0View10, int *, 0x60) = -0x320;
            }
            if (Physics20Field(&Physics20Player0View10, int *, 0x60) >= 0x321) {
                Physics20Field(&Physics20Player0View10, int *, 0x60) = 0x320;
            }
            Physics20Field(&Physics20Player0View10, int *, 0xAC) = 0x1C00;
            Physics20Call417FCView10(0x240, 0x30);
            raw21_temp_a0_6 = (((int) (raw21_temp_s0_10 * -(Physics20Call4EA2CView10(Physics20Field(&Physics20Player0View10, int *, 0x60)) << 5)) >> 0xC) - ((int) (Physics20Field(&Physics20Player0View10, int *, 0x14C) * 0x10) >> 6)) - ((int) (Physics20Field(&Physics20Player0View10, int *, 0x5C) << 6) >> 6);
            raw21_temp_v1_14 = Physics20Field(&Physics20Player0View10, int *, 0x14C) + raw21_temp_a0_6;
            Physics20Field(&Physics20Player0View10, int *, 0x14C) = raw21_temp_v1_14;
            raw21_temp_a1_3 = (Physics20Field(&Physics20Player0View10, int *, 0x5C) + (raw21_temp_v1_14 >> 6)) & 0xFFF;
            Physics20Field(&Physics20Player0View10, int *, 0x5C) = raw21_temp_a1_3;
            if (raw21_temp_a1_3 >= 0x801) {
                Physics20Field(&Physics20Player0View10, int *, 0x5C) = (int) (raw21_temp_a1_3 - 0x1000);
            }
            if (Physics20Field(&Physics20Player0View10, int *, 0x5C) < -0x300) {
                Physics20Field(&Physics20Player0View10, int *, 0x5C) = -0x300;
            }
            if (Physics20Field(&Physics20Player0View10, int *, 0x5C) >= 0x301) {
                Physics20Field(&Physics20Player0View10, int *, 0x5C) = 0x300;
            }
            Physics20Call41848View8(raw21_temp_a0_6, raw21_temp_a1_3);
            Physics20Call4F178View10(raw21_temp_s1_6 + 0x28, raw21_temp_s1_6 + 0x1C);
            if ((Physics21_SpawnParticle != 0) && (Physics20Field(&Physics20Player0View10, int *, 0xB4) >= 0x7D1)) {
                originalFrame.sp50 = -0x190;
                originalFrame.sp54 = 0x40 - (Physics20CallRandView8() & 0x7F);
                originalFrame.sp58 = -0x12C;
                Physics21_SpawnParticle(1, 0x2C, &originalFrame.sp50, 0);
                return;
            }
            break;
        }
    case 43:case 44:globalField4CPointer=&Physics20Player4CView3;
        __asm__("":"=r"(globalField4CPointer):"0"(globalField4CPointer));
        workWord3=Physics20Field(globalField4CPointer,int*,0);
        workWord2=1;
        if(workWord3==workWord2)goto clear47Calls;
        continue43:workWord2=7;
        workWord3=Physics20Data6E044View10;
        if (workWord3 == workWord2) {
            Physics20Field(&Physics20Player0View10, int *, 0xB0) = 0;
        }
        else {
            Physics20Call40D10View10(0x980);
            raw21_var_v0_2 = Physics20Call41580View10(0x5A, 0x10);
            if (raw21_var_v0_2 < 0) {
                raw21_var_v0_2 = -raw21_var_v0_2;
            }
            if (raw21_var_v0_2 >= 0x201) {
                Physics20Field(&Physics20Player0View10, int *, 0xAC) = 0;
            }
            raw21_var_a0_2 = 0xC0;
            if (Physics20Field(&Physics20Player0View10, int *, 0xB0) >= 0xC81) {
                raw21_var_a0_2 = 0;
                raw21_var_a1_4 = 0xC0;
            }
            else {
                raw21_var_a1_4 = 0x40;
            }
            Physics20Call417FCView10(raw21_var_a0_2, raw21_var_a1_4);
        }
        raw21_temp_s0_11 = &Physics20Player0View10 + 0xB0;
        if (Physics20Field(&Physics20Player0View10, int *, 0xB0) != 0) {
            Physics20Call41848View8();
            Physics20Call41B64View10();
            Physics20Field(&Physics20Player0View10, int *, 0x94) = 0;
        }
        else {
            Physics20Call4F168View10(raw21_temp_s0_11 - 0x30);
            Physics20Call4F168View10(raw21_temp_s0_11 - 0x24);
        }
        if (Physics21_SpawnParticle != 0) {
            raw21_temp_s4 = &Physics20Player0View10 + 0x28;
            if (Physics20Field(&Physics20Player0View10, int *, 0x28) < 0) {
                if ((Physics20Field(&Physics20Player0View10, int *, 0xB0) >= 0x401) && (savedSlotIndex < 2) && (Physics20Data6C640View10 & 1)) {
                    Physics20Call4F178View10(&originalFrame.sp50, raw21_temp_s4 - 0x28);
                    originalFrame.sp64 = 0x40;
                    originalFrame.sp68 = 0;
                    originalFrame.sp60 = (int) Physics20Field(&Physics20Player0View10, int *, 0xB0) >> 5;
                    if (savedSlotIndex != 0) {
                        originalFrame.sp64 = -0x40;
                    }
                    raw21_temp_s2_3 = raw21_temp_s4 + 8;
                    Physics20Call4ED6CView8(raw21_temp_s2_3, &originalFrame.sp60, &originalFrame.sp70);
                    Physics20Call4F194View10(&originalFrame.sp50, &originalFrame.sp50, &originalFrame.sp70);
                    originalFrame.sp60 = 0;
                    originalFrame.sp58 = -Physics20Field(&Physics20Player0View10, int *, 0x28);
                    Physics20Call4ED6CView8(raw21_temp_s2_3, &originalFrame.sp60, &originalFrame.sp60);
                    Physics20Call4F110View6(&originalFrame.sp60, 3);
                    Physics21_SpawnParticle(1, 0x2A, &originalFrame.sp50, &originalFrame.sp60);
                    if (!(Physics20CallRandView8() & 0x1F)) {
                        Physics21_SpawnParticle(1, 0x29, &originalFrame.sp50, 0);
                    }
                }
                else {
                    raw21_temp_s1_7 = &Physics20Player0View10 + 0xB0;
                    if ((Physics20Field(&Physics20Player0View10, int *, 0xB0) < 0x201) && (savedSlotIndex == 0) && !(Physics20Data6C640View10 & 7) && !(Physics20CallRandView8() & 3)) {
                        originalFrame.sp80 = 0x80;
                        __asm__("":"=r"(savedSlotIndex):"0"(savedSlotIndex));
                        originalFrame.sp84 = 0;
                        originalFrame.sp88 = 0;
                        Physics20Call4ED6CView8(raw21_temp_s1_7 - 0x80, &originalFrame.sp80, &originalFrame.sp80);
                        Physics20Call4F194View10(&originalFrame.sp80, &originalFrame.sp80, raw21_temp_s1_7 - 0xB0);
                        originalFrame.sp88 = -Physics20Field(&Physics20Player0View10, int *, 0x28);
                        Physics21_SpawnParticle(1, 0x2B, &originalFrame.sp80, (int *)1);
                    }
                }
            }
        }
        raw21_temp_a1_4 = Physics20Field(&Physics20Player0View10, int *, 0x144) - ((int) ((Physics20Field(&Physics20Player0View10, int *, 0x148) * 2) + (Physics20Field(&Physics20Player0View10, int *, 0x144) * 0x14)) >> 8);
        raw21_temp_a0_7 = Physics20Field(&Physics20Player0View10, int *, 0x148) + raw21_temp_a1_4;
        Physics20Field(&Physics20Player0View10, int *, 0x144) = raw21_temp_a1_4;
        Physics20Field(&Physics20Player0View10, int *, 0x148) = raw21_temp_a0_7;
        if (raw21_temp_a0_7 >= 0x5901) {
            Physics20Field(&Physics20Player0View10, int *, 0x148) = 0x5900;
        }
        if (Physics20Field(&Physics20Player0View10, int *, 0x148) < -0x5900) {
            Physics20Field(&Physics20Player0View10, int *, 0x148) = -0x5900;
            return;
        }
        break;
    case 47:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            workWord3=Physics20Data6E044View8;
            workWord2=7;
            if(workWord3==workWord2)goto zero47;
            Physics20Call40F48View5(&originalFrame.sp70,0);
            workWord2=originalFrame.sp70;
            numeric6=originalFrame.sp74;
            originalFrame.sp90=0;
            workWord3=(workWord2*9<<7)>>7;
            workWord2=(numeric6*3<<9)>>7;
            originalFrame.sp70=workWord3;
            workWord3=-workWord3;
            originalFrame.sp74=workWord2;
            originalFrame.sp94=workWord3;
            originalFrame.sp98=workWord2;
            workWord2=Physics20Call4EDE8View8(&originalFrame.sp90,0,numeric6);
            numeric4=originalFrame.sp98;
            workWord3=numeric4;
            if(numeric4<0){
                __asm__("":"=r"(workWord3):"0"(workWord3));
                workWord3=-workWord3;
            }
            workWord3=workWord3<workWord2;
            if(workWord3){
                workWord2=originalFrame.sp94;
                originalFrame.sp98=0;
                __asm__ volatile("":::"$4");
                numeric4=0;
                if(workWord2>0){
                    __asm__ volatile(""::"i"(0x8008A5B0):"memory");
                    numeric4=1;
                }
                if(!Physics20Call43194View2(numeric4)){
                    originalFrame.sp94=0;
                }
            }
            else{
                __asm__ volatile("":::"$3");
                originalFrame.sp94=0;
                originalFrame.sp90=0;
                if(numeric4>0){
                    __asm__ volatile(""::"i"(0x8008A5D8):"memory");
                    numeric4=2;
                }
                else numeric4=3;
                if(!Physics20Call43194View2(numeric4)){
                    originalFrame.sp98=0;
                }
            }
            call4=&originalFrame.sp90;
            workWord2=Physics20Call4EDE8View8(call4,1);
            Physics20PlayerACView3=workWord2;
            __asm__ volatile(""::"i"(0x8008A608):"memory");
            goto clear47;
            zero47:Physics20PlayerACView3=0;
            clear47:globalVector80=&Physics20Player80View3;
            __asm__ volatile(""::"r"(globalVector80):"memory");
            clear47Calls:call4=&Physics20Player80View2;
            __asm__("":"=r"(call4):"0"(call4));
            Physics20Call4F168View8(call4);
            call4=&Physics20Player8CView3;
            __asm__("":"=r"(call4):"0"(call4));
            Physics20Call4F168View8(call4);
            return;
        }
    case 50:case 51:case 52:{
            register int numeric4 __asm__("$4");
            register int numeric5 __asm__("$5");
            register int numeric6 __asm__("$6");
            Physics20Call40F48View5(&originalFrame.spA0,0);
            workWord2=originalFrame.spA0;
            numeric6=originalFrame.spA4;
            originalFrame.spA8=0;
            workWord3=(workWord2*9<<7)>>7;
            workWord2=(numeric6*3<<9)>>7;
            originalFrame.spA0=workWord3;
            workWord3=-workWord3;
            originalFrame.spA4=workWord2;
            originalFrame.spAC=workWord3;
            originalFrame.spB0=workWord2;
            workWord2=Physics20Call4EDE8View8(&originalFrame.spA8,0,numeric6);
            numeric4=originalFrame.spB0;
            workWord3=numeric4;
            if(numeric4<0){
                __asm__("":"=r"(workWord3):"0"(workWord3));
                workWord3=-workWord3;
            }
            workWord3=workWord3<workWord2;
            if(workWord3){
                workWord2=originalFrame.spAC;
                originalFrame.spB0=0;
                __asm__ volatile("":::"$4");
                numeric4=0;
                if(workWord2>0){
                    __asm__ volatile(""::"i"(0x8008A6D0):"memory");
                    numeric4=1;
                }
                if(!Physics20Call43194View2(numeric4)){
                    originalFrame.spAC=0;
                }
            }
            else{
                __asm__ volatile("":::"$3");
                originalFrame.spAC=0;
                originalFrame.spA8=0;
                if(numeric4>0){
                    __asm__ volatile(""::"i"(0x8008A6F8):"memory");
                    numeric4=2;
                }
                else numeric4=3;
                if(!Physics20Call43194View2(numeric4)){
                    originalFrame.spB0=0;
                }
            }
            vectorAt30=&originalFrame.spA8;
            workWord2=Physics20Call4EDE8View8(vectorAt30,1);
            numeric6=1;
            __asm__("":"=r"(numeric6):"0"(numeric6));
            numeric4=originalFrame.spA0;
            numeric5=originalFrame.spA4;
            globalVector80=&Physics20PlayerACView3;
            Physics20Field(globalVector80,int*,0)=workWord2;
            workWord2=Physics20Call4E880View3(numeric4,numeric5,numeric6);
            workWord3=workWord2;
            workWord2=workWord3<2049;
            Physics20PlayerA4View2=workWord3;
            call4=globalVector80-124;
            if(!workWord2){
                workWord2=workWord3-4096;
                Physics20PlayerA4View2=workWord2;
            }
            call5=vectorAt30;
            workWord2=originalFrame.spA8;
            call6=vectorAt30;
            workWord2+=1024;
            originalFrame.spA8=workWord2;
            Physics20Call4ED6CView6(call4,call5,call6);
            call4=vectorAt30;
            call5=vectorAt30;
            __asm__("":"=r"(globalVector80):"0"(globalVector80),"r"(call4),"r"(call5));
            globalVector8CState20=globalVector80-32;
            Physics20Call4F1C8View8(call4,call5,globalVector8CState20);
            call5=(void*)Physics20Call4EDE8View8(vectorAt30,0);
            workWord2=(int)call5<385;
            if(!workWord2)Physics20Call4F08CView8(vectorAt30,call5,384);
            globalVector80-=44;
            __asm__("":"=r"(globalVector80):"0"(globalVector80));
            Physics20Call4F194View8(globalVector80,globalVector8CState20,vectorAt30);
            vectorFinal50:call4=&Physics20Player8CView3;
            call5=&Physics20Player80View2;
            __asm__("":"=r"(call4),"=r"(call5):"0"(call4),"1"(call5));
            Physics20Call4F178View8(call4,call5);
            return;
        }
    }
}
#undef Physics20Field


/* AI generated; not human reviewed. SCUS-94467 8008A804..8008AC80.
 * Verified37 independent table tails and43 clamp producers reused against
 * original20 selectors and independent case2B store. Numeric byte accesses
 * establish no helper meanings, units/cadence. Original20 frame18 has no
 * local vector. Table8006FCF0/8006FCE6 stride44 and numeric200/5096 limits
 * plus signed division1536 match original words, not inferred semantics.
 * All words, strict full TU and every retail EXE/overlay hash required.
 */
extern Spyro Callback20Player __asm__("D_80070328");
int Callback20Call80037058(int x, int y) __asm__("func_80037058");
int Callback20Call8003BF6C(int soundId, int index) __asm__("func_8003BF6C");
void Callback20Call80041930(void) __asm__("func_80041930");
void Callback20Call80041AE8(void) __asm__("func_80041AE8");
void Callback20Call80041C20(void) __asm__("func_80041C20");
void Callback20Call80042A44(void) __asm__("func_80042A44");
void Callback20Call80043A38(int scale) __asm__("func_80043A38");
extern int D_8006FA38,D_8006C648;
extern int Callback20Word290 __asm__("D_80070328+0x290");
extern unsigned char Callback20Flags[] __asm__("D_8006FCE6");
extern unsigned char Callback20Values[] __asm__("D_8006FCF0");
void Callback20Call80049590(void) __asm__("func_80049590");
int Callback20Length(Vector3D*,int) __asm__("func_8004EDE8");
void func_level_20_8008A804(void) {
    register int computedValue __asm__("$4");
    register int* descriptor __asm__("$16");
    register int decreasingValue __asm__("$4");
    register int increasingValue __asm__("$4");
    register int tableValue __asm__("$2");
    register int valueOffset __asm__("$3");
    int descriptorResult;
    int flagOffset;

    register int clampedValue __asm__("$4");
    register int positionDelta __asm__("$2");
    register int numerator __asm__("$2");
    register int belowLimit __asm__("$2");
    register int positionValue __asm__("$3");

    switch (Callback20Player.animationState) {
    case 0x14:
        if(func_800438F4()==0)func_80043728();
        Callback20Call80041C20();
        Callback20Player.unk9a=0;
        goto call42A44;
    case 0x35:
    case 0x36:
        Callback20Call80041C20();
call42A44:
        Callback20Call80042A44();
clearSharedValue:
        Callback20Player.unk4[0]=0;
        return;
    case 0xA:
    case 0xB:
    case 0xC:
        func_800438F4();
        Callback20Call80041C20();
        Callback20Call80042A44();
        Callback20Call80041930();
        Callback20Call80043A38(0xC00);
        goto clearSharedValue;
    case 0x26:
    case 0x28:
    case 0x29:
        Callback20Call80041C20();
        Callback20Call80042A44();
        descriptor=&Callback20Player.unk22[2];
        if (Callback20Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            decreasingValue = *(int*)(Callback20Values + valueOffset);
            {
                register int below __asm__("$2") = decreasingValue < 0xC8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setDecreasingFlag;
            tableValue=decreasingValue-0xC8;
            goto storeDecreasingValue;
            }
            goto setDecreasingFlag;
storeDecreasingValue:
            *(int*)(Callback20Values + valueOffset) = tableValue;
setDecreasingFlag:
            flagOffset = *descriptor * 0x2C;
            Callback20Flags[flagOffset] = Callback20Flags[flagOffset] | 0x10;
            __asm__ volatile("" : : : "memory");
        }
        goto clearSharedValue;
    case 0x2A:
        Callback20Call80041C20();
        Callback20Call80042A44();
        Callback20Call80049590();
        descriptor=&Callback20Player.unk22[2];
        if (Callback20Call8003BF6C((int) D_8006C654->underwater, *descriptor) == 0) {
            descriptorResult = PlaySound((int) D_8006C654->underwater, 0, 4);
            *descriptor = descriptorResult;
            if (descriptorResult >= 0) {
                func_8003C0B0(descriptorResult, 0x157C);
                func_8003C140(*descriptor, 0x190);
            }
            Callback20Word290 = (int) D_8006C654->underwater;
            __asm__ volatile("" : : : "$16", "memory");
            descriptor=&Callback20Player.unk22[2];
        }
        if (Callback20Call8003BF6C((int) D_8006C654->underwater, *descriptor) != 0) {
            valueOffset = *descriptor * 0x2C;
            increasingValue = *(int*)(Callback20Values + valueOffset);
            {
                register int below __asm__("$2") = increasingValue < 0x13E8;
            __asm__ volatile("" : "=r"(below) : "0"(below) : "$4");
            if(!below)goto setTableFlag;
            tableValue=increasingValue+0xC8;
            goto storeTableValue;
            }
            goto setTableFlag;
storeTableValue:
            *(int*)(Callback20Values + valueOffset) = tableValue;
setTableFlag:
            flagOffset = *descriptor * 0x2C;
            Callback20Flags[flagOffset] = Callback20Flags[flagOffset] | 0x10;
        }
        goto clearSharedValue;
    case 0x2B:
    case 0x2C:
        Callback20Call80041C20();
        Callback20Call80042A44();
        Callback20Call80041AE8();
        if ((unsigned char) Callback20Player.unk10[4] != 0) {
            computedValue = -Callback20Player.unk9ha[4] - Callback20Call80037058(Callback20Player.position.x, Callback20Player.position.y);
            positionValue = Callback20Player.unk4a - computedValue;
            Callback20Player.unk4[0] = computedValue;
            positionDelta = (int) Callback20Player.union144.a.unk13cc >> 6;
            goto storePosition;
        }
        break;
storePosition:
        positionValue -= positionDelta;
        __asm__("" : "=r"(positionValue) : "0"(positionValue));
        Callback20Player.position.z=positionValue;
        return;
    case 0x2F:
        Callback20Call80041C20();
        Callback20Call80042A44();
        Callback20Call80041930();
        func_80042F64();
        goto clearSharedValue;
    case 0x32:
        Callback20Call80041C20();
        Callback20Call80042A44();
        Callback20Call80041930();
        func_80042F64();
        numerator=(int)((unsigned int)Callback20Player.unk7a[3].z << 2);
        Callback20Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)((unsigned int)ABS(numerator) + 0x300U) / 1536;
        __asm__("" : "=r"(quotient) : "0"(quotient));
        clampedValue=quotient<<4;}
        belowLimit = clampedValue < 0x10;
        __asm__("" : "=r"(belowLimit) : "0"(belowLimit));
        if (belowLimit) {
            clampedValue = 0x10;
            goto compareUpperLimit;
        }
        goto compareUpperLimit;
    case 0x33:
    case 0x34:
        Callback20Call80041C20();
        Callback20Call80042A44();
        Callback20Call80041930();
        func_80042F64();
        Callback20Player.unk4[0] = 0;
        {register int quotient __asm__("$3") =
            (int)(((unsigned int)Callback20Length((Vector3D *) ((unsigned char*)Callback20Player.unk4 + 0x70), 0) << 2) + 0x300U) / 1536;
        __asm__("" : "=r"(quotient) : "0"(quotient));
        clampedValue=quotient<<4;}
        belowLimit = clampedValue < 8;
        __asm__("" : "=r"(belowLimit) : "0"(belowLimit));
        if (belowLimit) {
            clampedValue = 8;
            goto compareUpperLimit;
        }
        goto compareUpperLimit;
compareUpperLimit:
        belowLimit=clampedValue<0x41;
applyUpperLimit:
        if(!belowLimit)clampedValue=0x40;
        func_800443A4(clampedValue);
        return;
    default:
        return;
    }
}


#define LEVEL_ID 20
#define PlaySpyroSounds_level_20 func_level_20_8008AC84
#include "overlay/animation.inc.h"

extern unsigned char D_8006E548[];
extern unsigned char* D_8006C570;
void func_80043ABC(Vector3D*);
void func_80043F3C(Vector3D*);
void func_level_20_8008AED4(int index) {
    D_8006C570 = D_8006E548 + index * 16;
    switch (spyro.animationState) {
    case 0xa:
    case 0xb:
    case 0xc:
    case 0x14:
    case 0x2b:
    case 0x2c:
    case 0x35:
    case 0x36:
        func_80043ABC(&spyro.unk9e);
        break;
    case 0x2f:
    case 0x32:
    case 0x33:
    case 0x34:
        func_80043F3C(&spyro.unk9h);
        break;
    }
}

/* AI generated; not human reviewed. SCUS-94467 USA Rev0 8008AF5C.
 * Reuses verified37 underwater/surface vectors, verified34 independent ladders
 * and shared grounded tail, verified21 state10 ice and stateB helper14C/98.
 * Original20 retains scalar44=280 and shared244/250 clears. Word60 FFF wrap,
 * signed801 boundary and positive clamp:800/801/FFF yield0/-7FF/-1 before helpers.
 * Numeric offsets are bytes; original widths, shifts and branches are retained.
 * Empty constraints preserve lifetimes without emitting instructions. Acceptance
 * requires all code/internal jumps/owned tables and complete retail binary hashes.
 * Helper/audio semantics, units, cadence and live runtime parity remain open.
 */
extern Spyro Transition20_D_80070328 __asm__("D_80070328");
int Transition20_func_8004EDE8(Vector3D*, int) __asm__("func_8004EDE8");
void Transition20_func_8004F168(Vector3D*) __asm__("func_8004F168");
extern unsigned char Transition20RawUnion[] __asm__("D_80070328+0x144");
extern int Transition20RawMovement __asm__("D_80070328+0x50");
extern void (*Call20Header)(Moby*) __asm__("unk_ovlheader_8007432C");
extern unsigned char Raw20State[] __asm__("D_80070328+0x50");

extern int D_80071934;
int Call20A358(Vector3D*,int) __asm__("func_8001A358");
extern int Raw20NegativeWord __asm__("D_80070328+0x28");
int Transition20_func_8003636C(int,int) __asm__("func_8003636C");
void Transition20_func_800441F0(void) __asm__("func_800441F0");
void Transition20_func_80043A38(int) __asm__("func_80043A38");
void func_80047138(void);
void func_level_20_8008AF5C(int arg0){
    struct {Vector3D first; int gap1; Vector3D second; int gap2; Vector3D third;} vectors;
    register int negativeWord __asm__("$3");
    int firstResult,secondResult,firstWrappedWord,secondWrappedWord,firstParticleKind,secondParticleKind,firstParticleSubtype,secondParticleSubtype;
    register Vector3D* destination __asm__("$4");

    int lengthResult;


    register unsigned char* savedBase __asm__("$3");
    switch(arg0){
    case 0x14:
        Transition20_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition20_D_80070328.unk5 = 0;
        Transition20_func_800441F0();
        Transition20_D_80070328.grounded = 1;
        Transition20_D_80070328.union144.a.unk13cb = Transition20_func_8003636C(1, 3);
        Transition20_D_80070328.union144.a.unk13cc = 0;
        goto clearPointers;
    case 0xA:case 0xB:case 0xC: {
        register unsigned char* state __asm__("$2")=Raw20State;
        register int kind __asm__("$3");
        destination=(Vector3D*)(state+0x48);
        __asm__("" : "=r"(destination) : "0"(destination));
        kind=16;
        __asm__("" : "=r"(kind) : "0"(kind));
        *(int*)state=kind;
        Transition20_D_80070328.unk5=0;
        Transition20_D_80070328.unk8[0]=Transition20_func_8004EDE8(destination,0);
        Transition20_func_80043A38(0xC00);
        goto setGrounded;
    }
    case 0x26:
        Transition20_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        if (Transition20_D_80070328.animationState == 0x2A) {
            Transition20_D_80070328.unk5 = 2;
        }
        Transition20_func_8004F168((Vector3D *) ((unsigned char*)&Transition20_D_80070328.movementState + 0xFC));
        Transition20_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
        Transition20_D_80070328.unk8[0] = Transition20_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition20_D_80070328.movementState + 0x48), 0);
        Transition20_D_80070328.grounded = 1;
        Transition20_D_80070328.unk4a = 0x280;
        return;
    case 0x28:
    case 0x29:
        if (((unsigned) (Transition20_D_80070328.movementState - 0xB) >= 2U) && (Transition20_D_80070328.movementState != MOVEMENT_STATE_HURT)) {
            if (SpawnParticle != 0) {
                func_8004F178(&vectors.first, (Vector3D *) ((unsigned char*)&Transition20_D_80070328.movementState - 0x50));
                if ((Transition20_D_80070328.movementState == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw20NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.first.z = -negativeWord;
                    SpawnParticle(6, 0x2E, &vectors.first, 0);
                    firstParticleKind = 4;
                    firstParticleSubtype = 0x29;
                    goto emitFirstParticle;
                }
                if (Transition20_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    vectors.first.z += 0x400;
                    firstResult = Call20A358(&vectors.first, 0x800);
                    vectors.first.z = firstResult;
                    if (firstResult != 0) {
                        firstParticleKind = 6;
                        if (D_80071934 != 0) {
                            firstParticleSubtype = 0x2E;
emitFirstParticle:
                            SpawnParticle(firstParticleKind, firstParticleSubtype, &vectors.first, 0);
                        }
                    }
                }
            }
            firstWrappedWord = Transition20_D_80070328.rotation.pitch & 0xFFF;
            Transition20_D_80070328.rotation.pitch = firstWrappedWord;
            if (firstWrappedWord >= 0x801) {
                Transition20_D_80070328.rotation.pitch = firstWrappedWord - 0x1000;
            }
            if (Transition20_D_80070328.rotation.pitch > 0) {
                Transition20_D_80070328.rotation.pitch = 0;
            }
            if (arg0 == 0x28) {
                Transition20_D_80070328.unk5 = 1;
            }
            Transition20_func_8004F168((Vector3D *) ((unsigned char*)&Transition20_D_80070328.rotation.pitch + 0xEC));
            Transition20_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition20_D_80070328.unk8[0] = Transition20_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition20_D_80070328.rotation.pitch + 0x38), 0);
            Transition20_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
            goto clearUnderwaterWord;
        }
        if (Transition20_D_80070328.animationState == 0x2A) {
            Transition20_D_80070328.unk5 = 2;
clearUnderwaterWord:
            Transition20_D_80070328.union144.a.unk13da = 0;
        }
        Transition20_D_80070328.movementState = MOVEMENT_STATE_SWIM_UNDERWATER;
        Transition20_D_80070328.unk20a = 0;
        Transition20_D_80070328.critterMobyPtr = 0;
        __asm__ volatile("" : : : "memory");
        goto clearPointers;
    case 0x2A: {
        register unsigned char* state __asm__("$17")=Raw20State;
        register Vector3D* localVector __asm__("$16");
        if ((unsigned) (*(int*)state - 0xB) >= 2U) {
            if (SpawnParticle != 0) {
                localVector=&vectors.second;
                func_8004F178(localVector,(Vector3D*)(state-0x50));
                if ((*(int*)state == MOVEMENT_STATE_SWIM_SURFACE) && (({
                        negativeWord = Raw20NegativeWord;
                        __asm__("" : "=r"(negativeWord) : "0"(negativeWord));
                        negativeWord;
                    }) < 0)) {
                    vectors.second.z = -negativeWord;
                    SpawnParticle(6, 0x2E, localVector, 0);
                    secondParticleKind = 4;
                    secondParticleSubtype = 0x29;
                    goto emitSecondParticle;
                }
                if (Transition20_D_80070328.movementState == MOVEMENT_STATE_CHARGE) {
                    localVector=&vectors.second;
                    vectors.second.z += 0x400;
                    secondResult = Call20A358(localVector, 0x800);
                    vectors.second.z = secondResult;
                    if (secondResult != 0) {
                        secondParticleKind = 6;
                        if (D_80071934 != 0) {
                            secondParticleSubtype = 0x2E;
emitSecondParticle:
                            SpawnParticle(secondParticleKind, secondParticleSubtype, localVector, 0);
                        }
                    }
                }
            }
            if (Transition20_D_80070328.animationState == 0x2E) {
                Transition20_D_80070328.rotation.pitch -= 0x400;
            }
            secondWrappedWord = Transition20_D_80070328.rotation.pitch & 0xFFF;
            Transition20_D_80070328.rotation.pitch = secondWrappedWord;
            if (secondWrappedWord >= 0x801) {
                Transition20_D_80070328.rotation.pitch = secondWrappedWord - 0x1000;
            }
            if (Transition20_D_80070328.rotation.pitch > 0) {
                Transition20_D_80070328.rotation.pitch = 0;
            }
            Transition20_D_80070328.unk5 = 1;
            Transition20_func_8004F168((Vector3D *) ((unsigned char*)&Transition20_D_80070328.animationState + 0x104));
            Transition20_D_80070328.union144.a.unk13cb = MOVEMENT_STATE_STAND;
            Transition20_D_80070328.unk8[0] = Transition20_func_8004EDE8((Vector3D *) ((unsigned char*)&Transition20_D_80070328.animationState + 0x50), 0);
            Transition20_D_80070328.grounded = 1;
            PlaySound((int) D_8006C654->waterDive, 0, 0);
        }
        Transition20_D_80070328.movementState = MOVEMENT_STATE_SWIM_CHARGE;
        Transition20_D_80070328.unk13a[0] = 0x20000;
        goto clearPointers;
    }
    case 0x2B:case 0x2C: {
        register Vector3D* localVector __asm__("$16");
        register unsigned char* unionPointer __asm__("$17");
        {register int stateWord __asm__("$3")=Transition20RawMovement;
        register int initialKind __asm__("$2")=10;
        __asm__("" : "=r"(stateWord),"=r"(initialKind) : "0"(stateWord),"1"(initialKind));
        if(stateWord!=initialKind){
            PlaySound((int)D_8006C654->waterSurface,0,0);
            unionPointer=Transition20RawUnion;
            *(int*)unionPointer=(-Transition20_D_80070328.unk7a[2].z)>>2;
            if(Transition20RawMovement!=8){Transition20_D_80070328.union144.a.unk13cc=0x5900;Transition20RawMovement=10;}
            Transition20_D_80070328.unk5=0;
            Transition20_D_80070328.unk8[0]=Transition20_func_8004EDE8((Vector3D*)(unionPointer-0xAC),0);
            Transition20_D_80070328.grounded=1;
            Transition20_D_80070328.unk15b=1;
            localVector=&vectors.third;
            func_8004F178(localVector,(Vector3D*)(unionPointer-0x144));
            vectors.third.z+=0x400;
            lengthResult=Call20A358(localVector,0x800);
            vectors.third.z=lengthResult;
            if(lengthResult!=0 && D_80071934!=0 && SpawnParticle){SpawnParticle(10,0x29,localVector,0);SpawnParticle(6,0x2E,localVector,0);}
        }
        }
        goto clearPointers;
    }
    case 0x2F:
        savedBase=(unsigned char*)&Transition20RawMovement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition20_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            __asm__ volatile("" : : : "memory");
            goto setGrounded;
        }
        goto clearPointers;
    case 0x32:case 0x33:case 0x34:
        savedBase=(unsigned char*)&Transition20RawMovement;
        destination=(Vector3D*)(savedBase+0x3C);
        if(*(int*)savedBase!=13){
            *(int*)savedBase=13;
            Transition20_D_80070328.unk5=0;
            func_8004F178(destination,(Vector3D*)(savedBase+0x48));
            goto setGrounded;
        }
        goto clearPointers;
    case 0x35:
    case 0x36:
        Transition20_D_80070328.movementState = MOVEMENT_STATE_STAND;
        Transition20_D_80070328.unk5 = 0;
        Transition20_func_800441F0();
setGrounded:
        Transition20_D_80070328.grounded = 1;
clearPointers:
        Transition20_D_80070328.unk20a=0;
        Transition20_D_80070328.critterMobyPtr=0;
        return;
    }
}


/* AI-generated; not human reviewed. Verified sibling C adapted only
 * to this function's original SCUS-94467 instructions. Raw field units,
 * helper meanings and update cadence remain unresolved. */
/* AI generated; not human reviewed. SCUS-94467 USA Rev0 level20
 * 8008B628: original601 instructions and45 dispatch words in sibling4825
 * and original assembly. Verified40 state/helper and animation-byte C reused.
 * All raw field addresses, selectors and branches follow original20.
 * Meanings, units and cadence unresolved; native/linked/all hash gates required. */
extern int A20W48 __asm__("D_80070328 + 0x48");
extern int A20W4C __asm__("D_80070328 + 0x4C");
extern int A20W54 __asm__("D_80070328 + 0x54");
extern int A20WA0 __asm__("D_80070328 + 0xA0");
extern int A20WA8 __asm__("D_80070328 + 0xA8");
extern int A20WAC __asm__("D_80070328 + 0xAC");
extern int A20WB0 __asm__("D_80070328 + 0xB0");
extern int A20WB8 __asm__("D_80070328 + 0xB8");
extern int A20WCC __asm__("D_80070328 + 0xCC");
extern int A20WD0 __asm__("D_80070328 + 0xD0");
extern int A20WD4 __asm__("D_80070328 + 0xD4");
extern int A20W8C __asm__("D_80070328 + 0x8C");
extern int A20W90 __asm__("D_80070328 + 0x90");
extern int A20W94 __asm__("D_80070328 + 0x94");
extern int A20WE4 __asm__("D_80070328 + 0xE4");
extern int A20W144 __asm__("D_80070328 + 0x144");
extern int A20W158 __asm__("D_80070328 + 0x158");
extern int A20W1EC __asm__("D_80070328 + 0x1EC");
extern int A20W1F0 __asm__("D_80070328 + 0x1F0");
extern int A20W240 __asm__("D_80070328 + 0x240");
extern int A20W280 __asm__("D_80070328 + 0x280");
extern unsigned char A20B14 __asm__("D_80070328 + 0x14");
extern unsigned char A20B15 __asm__("D_80070328 + 0x15");
extern unsigned char A20B16 __asm__("D_80070328 + 0x16");
extern unsigned char A20B17 __asm__("D_80070328 + 0x17");
extern unsigned char A20B1C __asm__("D_80070328 + 0x1C");
extern unsigned char A20BFC __asm__("D_80070328 + 0xFC");
extern unsigned char A20B1B5 __asm__("D_80070328 + 0x1B5");
extern unsigned char A20B1B6 __asm__("D_80070328 + 0x1B6");
extern unsigned char A20Player[] __asm__("D_80070328");
extern unsigned char A20Table[] __asm__("D_80066530");
extern int A20Buttons __asm__("D_8006E538"),A20NewButtons __asm__("D_8006E53C");
extern int A20Mode __asm__("D_8006E044"),A20Gate __asm__("D_8006E344"),A20Count __asm__("D_8006C514");
extern int (*A20Callback)() __asm__("unk_ovlheader_80074374");
extern int A20W24 __asm__("D_80070328 + 0x24");
extern int A20W28C __asm__("D_80070328 + 0x28C");
extern int A20W290 __asm__("D_80070328 + 0x290");
extern int A20Surface __asm__("D_8006FA38");
extern unsigned char* A20SoundDesc __asm__("D_8006C654");
int A20Sound() __asm__("PlaySound");
int A20H3BF6C() __asm__("func_8003BF6C");
int A20H3BE70() __asm__("func_8003BE70");
int A20H40994() __asm__("func_80040994");
int A20H4BEF8() __asm__("func_8004BEF8");
int A20H49688() __asm__("func_80049688");
int A20H4F334() __asm__("func_8004F334");
int A20H498C0() __asm__("func_800498C0");
extern volatile int A20W20C __asm__("D_80070328 + 0x20C");
extern int A20W214 __asm__("D_80070328 + 0x214");
extern unsigned char A20B100 __asm__("D_80070328 + 0x100");
extern unsigned char A20E535 __asm__("D_8006E535");
extern unsigned char* A20Models __asm__("D_8006EE2C");
int A20H40BCC() __asm__("func_80040BCC");
int A20H1A310() __asm__("func_8001A310");
extern int A20W10C __asm__("D_80070328 + 0x10C");
extern int A20WB4 __asm__("D_80070328 + 0xB4");
extern int A20WA4 __asm__("D_80070328 + 0xA4");
extern int (*A20Callback1)(int) __asm__("unk_ovlheader_8007431C");
int A20H40954() __asm__("func_80040954");
void func_level_20_8008B628(void) {
 register int work2 __asm__("$2");
 register int work3 __asm__("$3");
 register int work4 __asm__("$4");
 register int work5 __asm__("$5");
 register int* state __asm__("$16");
 switch(A20W48) {
 case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 21: case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31: case 32: case 33: case 34: case 35: case 36: case 37: case 39: case 45: case 46: case 48: case 49: return;
 case 20:
  if(A20H40994())return;
  work2=A20NewButtons&64;work4=6;if(work2)goto call;
  work2=A20WB8<4;work4=7;if(!work2)goto call;if(A20WE4>=23)goto call;
  work3=A20Buttons;
  work2=work3&128;work4=13;if(work2)goto call;
  work2=A20WA8;if(work2<0)work2=-work2;
  if(work2>=17){work4=1;goto call;}
  work2=work3&12;
  __asm__("" : "=r"(work2):"0"(work2));
  if(!work2){work2=A20WAC;work4=1;if(work2)goto call;}
  if(A20Mode==7 || A20W240) {
   state=&A20W48;__asm__("" : "=r"(state):"0"(state));
   if(!*state)return;
   A20H4BEF8(0);
   if(A20Table[*((unsigned char*)state-0x2C)]>=96){A20B14=A20B15;A20B16=A20B17;}
   A20B17=0;work3=*state;work2=113;*((unsigned char*)state-0x2C)=work2;
   A20W1F0=0;A20B15=work3;A20W1EC=work3;return;
  }
  work2=A20BFC;work4=15;if(work2)goto call;
  A20H49688();return;
 case 53: case 54:
  work2=A20H40994();work4=0;if(work2)return;goto call;
 case 10:
  if(A20H40994())return;
  work2=A20WB8<4;work4=7;if(!work2)goto call;if(A20WE4>=23)goto call;
  work2=A20H40954(A20W10C);work3=4;work4=1;if(work2!=work3)goto call;
  work3=A20Mode;work2=7;if(work3==work2)return;
  work2=A20E535;work4=11;if(!work2)goto call;
  work2=A20WB4<2305;work4=12;if(work2)return;goto call;
 case 11:
  if(A20H40994())return;
  work2=A20WB8<4;work4=7;if(!work2)goto call;if(A20WE4>=23)goto call;
  work2=A20H40954(A20W10C);work3=4;work4=1;if(work2!=work3)goto call;
  if(!A20E535)return;
  work2=A20WB4<2305;work4=10;if(work2)goto call;work4=12;goto call;
 case 12:
  if(A20H40994())return;
  work2=A20WB8<4;work4=7;if(!work2)goto call;if(A20WE4>=23)goto call;
  work2=A20H40954(A20W10C);work3=4;work4=1;if(work2!=work3)goto call;
  work2=A20E535;work4=11;if(!work2)goto call;
  work2=A20WB4<1536;work4=10;if(!work2)return;goto call;
 case 38: {
  register int (*callback2)(int) __asm__("$2");
  callback2=A20Callback1;callback2(1);return;
 }
 case 40:
  if(A20H40994())return;
  if((A20Buttons&128) && A20W4C!=1){work4=42;goto call;}
  if(A20WB0)return;
  work2=A20W20C&64;work4=41;if(!work2)goto call;
  if(A20W214<=0)return;goto call;
 case 41:
  if(A20H40994())return;
  work4=A20Buttons;work2=work4&128;if(work2){work4=42;goto call;}
  work2=7;work3=A20Mode;if(work3==work2)return;
  work2=work4&64;work4=40;if(work2)goto call;
  if(!(A20W20C&64))return;
  if(!A20W214)goto call;return;
 case 42:
  if(A20H40BCC())return;
  if((A20Buttons&128) || A20W4C==1)goto flag64;
  work2=A20W20C&128;work4=40;if(!work2)goto call;
  flag64:work2=A20W20C&64;work4=40;if(!work2)return;goto call;
 case 43: {
  register unsigned char* byte4 __asm__("$4");
  if(A20H40994())return;
  if((A20NewButtons&64) && A20W54>=9){work4=6;goto partialCall;}
  byte4=&A20B100;__asm__("" : "=r"(byte4):"0"(byte4));
  if(!*byte4){work4=7;goto partialCall;}
  if(!(A20NewButtons&128))goto check44;
  if(A20W54<9)goto check44;
  work2=*(int*)(A20Models+220);byte4-=256;if(!work2)goto check44;
  work2=A20H1A310(byte4,1024,1,0);work4=40;
  if(work2)goto check44;goto call;
  partialCall:A20H4BEF8(work4);
  check44:work2=A20E535;work4=44;if(!work2)return;goto call;
 }
 case 44: {
  register unsigned char* byte4 __asm__("$4");
  register int (*callback2)() __asm__("$2");
  work3=A20W4C;work2=1;if(work3!=work2)goto other44;
  if(A20NewButtons&0x850)goto callback44;
  if(A20W54<61)return;
  callback44:callback2=A20Callback;__asm__("" : "=r"(callback2):"0"(callback2));
  if(!callback2)goto missingCallback;
  callback2();return;
  missingCallback:A20H498C0();return;
  other44:if(A20H40994())return;
  if((A20NewButtons&64) && A20W54>=9){work4=6;goto call;}
  byte4=&A20B100;__asm__("" : "=r"(byte4):"0"(byte4));
  if(!*byte4){work4=7;goto call;}
  if(!(A20NewButtons&128))goto mode44;
  if(A20W54<9)goto mode44;
  work2=*(int*)(A20Models+220);byte4-=256;if(!work2)goto mode44;
  work2=A20H1A310(byte4,1024,1,0);work4=40;if(!work2)goto call;
  mode44:work3=A20Mode;work2=7;if(work3==work2)return;
  work2=A20E535;work4=43;if(work2)return;goto call;
 }
 case 47:
  if(A20H40994())return;
  if(A20NewButtons&64){work2=A20Buttons&16384;work4=6;if(work2)goto specialJump;__asm__ volatile("" ::: "memory");goto call;}
  work2=A20WAC;work4=50;if(!work2)return;goto call;
 case 50:
  if(A20H40994())return;
  if(A20NewButtons&64){work2=A20Buttons&16384;work4=6;if(work2)goto specialJump;goto call;}
  work2=A20WAC;work4=47;if(!work2)goto call;
  work2=A20WA0;work3=A20WB4;if(work2<0)work2=-work2;work2=work2<work3;if(!work2)return;
  work2=A20WA4;if(work2<0)work2=-work2;work2=work2<1024;work4=52;if(!work2)goto call;work4=51;goto call;
 case 51: case 52:
  if(A20H40994())return;
  if(A20NewButtons&64){work2=A20Buttons&16384;work4=6;if(!work2)goto call;
   specialJump:A20H4BEF8(7);work2=3;A20W4C=work2;return;
  }
  work2=A20WAC;work4=47;if(!work2)goto call;
  work2=A20WA0;work3=A20WB4;if(work2<0)work2=-work2;work2=work2<work3;work4=50;if(work2)return;__asm__ volatile("" ::: "memory");
  call:__asm__ volatile("" ::: "memory");A20H4BEF8(work4);return;
 }
}
