# Verified overlay batch 2026-10-04-387

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 576 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch387.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: uses the existing upstream GemToll layout for the original value/paid checks and a partial view of the interaction tag. Preserves selector dispatch, actor substate updates, helper calls, and the single cached actor-state read used by retail. No emitted instruction assembly or inferred interaction semantics is added.

Categories: {'toll table interaction gate and selector dispatch': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_12_8007B344` | toll table interaction gate and selector dispatch | 144 | `c0cf2ada7deb429f06ac0c6d4b886512a8bc0734ce649321490409abde0b6c12` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_8007B344.s` |
| `func_level_21_8007A874` | toll table interaction gate and selector dispatch | 144 | `eefc71bc0446bb02bd9ddc608b63b2f16ae9c22dc570a3c3cb254cb293ef6b35` | `asm/nonmatchings/overlays/level_21/moby/func_level_21_8007A874.s` |
| `func_level_31_80079E18` | toll table interaction gate and selector dispatch | 144 | `1482e615dcec344be8d936c0b292130100f6a566b3bf5c01a21db9ea4c937dd4` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_80079E18.s` |
| `func_level_41_8007B728` | toll table interaction gate and selector dispatch | 144 | `225d22ce301b87ffbf1ff0eb9ecf673573aa7d62fe4e860422848ba855c262d5` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_8007B728.s` |
