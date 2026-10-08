# Verified overlay batch 2026-10-04-916

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 736 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch916.formatted.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Source baseline: original helper instructions listed below and existing upstream vector/helper declarations. Input helper func_80040F48 writes two word values to the stack with argument 1. The first target is multiplied by 30 when D_8006E044 equals 40, otherwise by 20, then arithmetically shifted by 7. The player word at +0xA8 is cleared on zero input or opposite sign, approached by steps 1/4 according to the same global condition, and clamped after an independently addressed reread. The +0xAC word receives 0 or 0xF00 according to the exact byte and mask-0xC gate; both helper parameters to func_800417FC remain 192. The work vector at player +0x80 is cleared, then its Y component follows bit-8 priority over bit-4, sign selection of the +0xB0 word, the original 32-bit multiply by 5 and shift 9, and signed division by 3840. Native C division reproduces the exact original signed multiply-high sequence; no explicit instruction-bearing assembly or approximation is used. Its X component preserves the second stack word times +0xB0 shifted by 7. The original matrix-relative transform, +0x8C vector copy, byte/word mode gate, vertical value minus 192, and alternative +0xE8 vector add are retained. Input domains, physical units, helper semantics, record producers, and caller cadence remain open evidence targets. Empty constraints preserve original literal-zero storage, pointer setups, and register lifetimes without emitting instructions. Confidence is exact linked words and complete binary hashes, not independently verified runtime character behavior.

Categories: {'signed input target approach and transformed player vector': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_33_80095D10` | signed input target approach and transformed player vector | 184 | `3716216192652f53fab381329b27177ba6491c28b129cd0729a9f11cd3c392dd` | `asm/nonmatchings/overlays/level_33/level/func_level_33_80095D10.s` |
| `func_level_43_8008DB04` | signed input target approach and transformed player vector | 184 | `75b93a713beef440d105263ee30fb934f6bf7fd5daf97674d457be81272ef72b` | `asm/nonmatchings/overlays/level_43/level/func_level_43_8008DB04.s` |
| `func_level_44_8008ACA0` | signed input target approach and transformed player vector | 184 | `f2e14a5d966c3cf7104e3d39f7a00cab373d433b0a9b51466c2117b1d46eb506` | `asm/nonmatchings/overlays/level_44/level/func_level_44_8008ACA0.s` |
| `func_level_46_8008BF44` | signed input target approach and transformed player vector | 184 | `d95078257c3f06c0ff1660db7157bdd6861fa7dda453752ba7f1d03b5ee07c1d` | `asm/nonmatchings/overlays/level_46/level/func_level_46_8008BF44.s` |
