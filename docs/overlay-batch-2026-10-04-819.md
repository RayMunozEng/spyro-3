# Verified overlay batch 2026-10-04-819

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 10 functions, 770 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch819.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

This repeated family translates four packed words selected by a signed table halfword and the low eight bits of the selector argument. Each 28-byte entry supplies two coordinate triplets. Both packed XY words use arithmetic position shifts by 4. The second-triplet Z word preserves its low 16 bits and adds position Z shifted by 4 to its high halfword. The first-triplet Z word preserves its low 17 bits, adds position Z shifted by 5 to the table value and shifts that sum by 17. The count and table base are reread at the original points, including the base reread between the first two stores. Empty allocation and memory constraints emit no instructions; no instruction-bearing inline assembly is added.

Units: the shifts and packed bit widths above are proven by the original instructions; the table producer and meanings of these packed coordinates remain unresolved. Cadence: one table pass per invocation; live caller frequency remains unverified. No browser-runtime parity is claimed. Next evidence target: trace `D_8006C724`, `D_8006C77C` and `D_8006D048` producers and packet consumers before assigning semantic coordinate names.

Categories: {'packed position table translation': 10}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_13_800865F4` | packed position table translation | 77 | `87d01881bb1abf43dd0ee50bcfd25904e4558a7f3420af5595cddadeff981c72` | `asm/nonmatchings/overlays/level_13/level/func_level_13_800865F4.s` |
| `func_level_14_8008FB88` | packed position table translation | 77 | `87d01881bb1abf43dd0ee50bcfd25904e4558a7f3420af5595cddadeff981c72` | `asm/nonmatchings/overlays/level_14/level/func_level_14_8008FB88.s` |
| `func_level_21_8008755C` | packed position table translation | 77 | `87d01881bb1abf43dd0ee50bcfd25904e4558a7f3420af5595cddadeff981c72` | `asm/nonmatchings/overlays/level_21/level/func_level_21_8008755C.s` |
| `func_level_22_80092494` | packed position table translation | 77 | `87d01881bb1abf43dd0ee50bcfd25904e4558a7f3420af5595cddadeff981c72` | `asm/nonmatchings/overlays/level_22/level/func_level_22_80092494.s` |
| `func_level_24_8008F0A8` | packed position table translation | 77 | `87d01881bb1abf43dd0ee50bcfd25904e4558a7f3420af5595cddadeff981c72` | `asm/nonmatchings/overlays/level_24/level/func_level_24_8008F0A8.s` |
| `func_level_26_800865AC` | packed position table translation | 77 | `87d01881bb1abf43dd0ee50bcfd25904e4558a7f3420af5595cddadeff981c72` | `asm/nonmatchings/overlays/level_26/level/func_level_26_800865AC.s` |
| `func_level_30_80084F8C` | packed position table translation | 77 | `87d01881bb1abf43dd0ee50bcfd25904e4558a7f3420af5595cddadeff981c72` | `asm/nonmatchings/overlays/level_30/level/func_level_30_80084F8C.s` |
| `func_level_40_80083C08` | packed position table translation | 77 | `87d01881bb1abf43dd0ee50bcfd25904e4558a7f3420af5595cddadeff981c72` | `asm/nonmatchings/overlays/level_40/level/func_level_40_80083C08.s` |
| `func_level_42_80086350` | packed position table translation | 77 | `87d01881bb1abf43dd0ee50bcfd25904e4558a7f3420af5595cddadeff981c72` | `asm/nonmatchings/overlays/level_42/level/func_level_42_80086350.s` |
| `func_level_44_8008A7A4` | packed position table translation | 77 | `87d01881bb1abf43dd0ee50bcfd25904e4558a7f3420af5595cddadeff981c72` | `asm/nonmatchings/overlays/level_44/level/func_level_44_8008A7A4.s` |
