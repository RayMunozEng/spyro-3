# Verified overlay batch 2026-10-04-309

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 342 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch309.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: two further copies of the original actor trigger dispatch. Uses the existing Moby and Spyro layouts and a partial tag layout justified by the listed instruction offsets. Retains level/global gates, both box-helper calls and limits, states 0/1/2/3, selected actor callback, archive table addressing, signed division by 0x800, and the original numeric CD helper arguments. State 0 tests the inner box result directly; state 2 tests the separate global flag after a successful expanded-box test. Empty constraints preserve allocation and scheduling; no instructions are embedded in C. Unknown helper semantics and CD runtime timing remain unverified. Removed a repeated identical DecodedFragmentUpdate typedef in each touched translation unit; full hashes verify this declaration-only cleanup.

Categories: {'actor trigger state and numeric CD helper dispatch': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_32_8008A540` | actor trigger state and numeric CD helper dispatch | 171 | `ab292b45ef42e12e1f399b75eef9779ec963a14aee6091dece8f2ec06eed5b9f` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_8008A540.s` |
| `func_level_50_800857B4` | actor trigger state and numeric CD helper dispatch | 171 | `fee6c9ea0778a32ecefc86d757ca31953c03533f938ea18ae0a06cbb6d49119d` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_800857B4.s` |
