# Verified overlay batch 2026-10-04-939

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 776 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch939.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Source reconstruction uses the original Rev0 assembly, existing Moby/Vector3D structures, upstream SpawnParticle and savepoint declarations, and the already verified indexed-actor/savepoint patterns in batch928. No additional Rev1 decoder reuse is claimed. Private words +0/+4/+8 are the wrapped table index, helper timer input, and actor-pool selector; actor stride is 88 bytes. Roll/pitch use unsigned halfword table values shifted right7; vector offsets sign-extend through left16/arithmetic-right20, with X published before Z and Y. The near gate separately checks both signs of (owner Z minus signed ground halfword minus player Z) against512; it is not replaced by an invented absolute-distance rule. The allocator result is null-checked, random selector is masked to8bits, and timer helper arguments remain120/200 with unknown duration units. Two escaped state-byte savepoint calls are retained. Empty constraints emit no instructions and retain the original branch routes, callback argument allocation, and vector store ordering. Caller cadence, allocator payload meaning, helper side effects, and runtime presentation remain open.

Categories: {'timed vector allocation and ordered state save callbacks': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_13_800795C8` | timed vector allocation and ordered state save callbacks | 194 | `cfe808e1521a979c2a51f355c009ccc9c6f90a08173069998a8d226face999f3` | `asm/nonmatchings/overlays/level_13/moby/func_level_13_800795C8.s` |
| `func_level_23_80079304` | timed vector allocation and ordered state save callbacks | 194 | `74cd4a69c31e17bc8361c8882e165f7958417e2e3c7232a63bb9f13d2714646f` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_80079304.s` |
| `func_level_41_8007A19C` | timed vector allocation and ordered state save callbacks | 194 | `cd0a28a1f6fda6b68f1c5c0c96fd29bec48baaade39d1fe6d7a8075d0b6c79c9` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_8007A19C.s` |
| `func_level_42_80079330` | timed vector allocation and ordered state save callbacks | 194 | `722b0f4f8af125192cf8572a1d63af5935277d6d2b42f562cf2d2a20da1bea7a` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_80079330.s` |
