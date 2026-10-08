# Verified overlay batch 2026-10-03-123

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 300 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch123.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream `Moby`, `Spyro`, `Colour` and vector/helper declarations. Both upstream Spyro aliases resolve to the same retail address; separate loads preserve the original ordering. The tag is read from the first actor before the second actor pointer is tested, as in retail. Tag words +0x1C/+0x24 control deletion: missing flag bit 0, nonpositive timer, or an undrawn actor calls the original deletion helper and clears tag word +0x2C. Otherwise the recorded helpers receive literal 0x400/1/0/0x80000. For timer <180, the sine-table index is ((timer-180)*8)&255; the signed halfword magnitude is shifted right eight bits, capped at 15 and ORed with 0x30 into the alpha byte after clearing the colour word. Empty constraints preserve the two distinct shifts/mask and register allocation. Timer cadence, position scale and flag semantics remain unresolved. Next evidence target: tag timer/flag producers and colour consumer, followed by synchronized retail runtime capture.

Categories: {'critter attachment gate and colour ramp': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_18_80079D7C` | critter attachment gate and colour ramp | 75 | `c81ec5dcd5b8d32dc7dc72fd6b216046d7a9b3ffd11b12448f2e71ec027c27ea` | `asm/nonmatchings/overlays/level_18/moby/func_level_18_80079D7C.s` |
| `func_level_28_80079D34` | critter attachment gate and colour ramp | 75 | `57889e14939412ede567a561b4c6a94522cf0d19135e99a44d8a40b533035bfb` | `asm/nonmatchings/overlays/level_28/moby/func_level_28_80079D34.s` |
| `func_level_38_80079D38` | critter attachment gate and colour ramp | 75 | `8c45dcb812918a660f3dbb1521a1b88518e2f276a0517f406056c6abb21d12e3` | `asm/nonmatchings/overlays/level_38/moby/func_level_38_80079D38.s` |
| `func_level_48_80079D5C` | critter attachment gate and colour ramp | 75 | `9b7a115feb9f7b9a24820c3041c1543e5d1bc71367d5515bcc54dd9d144b5423` | `asm/nonmatchings/overlays/level_48/moby/func_level_48_80079D5C.s` |
