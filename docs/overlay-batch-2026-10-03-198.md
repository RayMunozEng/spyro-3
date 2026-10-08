# Verified overlay batch 2026-10-03-198

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 201 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch198.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

These routines reuse existing SDK actor, player, camera and vector declarations. The callback-handle routine preserves states 0/1/2, the -1 sentinel, the original create/check/release calls and state reset. The camera selector retains modes 3/0x1D, override and input gates, repeated current-state load and fallback selector 6. The projection routine retains the drawn-byte gate, camera vector at offset 0x28, distance threshold 0x4000 and adjustment -15, then signed positive Z and unsigned X/Y range checks. The radius routine preserves helper result *80 + 0xC8, its six-argument query, angle-helper narrowing to actor byte 0x51, and the final query/deletion sequence. No new semantics of callback handles, projection units, or target-byte meaning are asserted. The pre-existing func_80039714 declaration in level 43 was corrected to int to agree with its actual EXE return type and existing callers; the full hash gate covers that translation unit.

Categories: {'two-state callback handle lifecycle': 1, 'two-mode camera selector with animation fallback': 1, 'drawn-actor vector projection and screen bounds': 1, 'radius query and target byte-angle update': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_43_8008862C` | two-state callback handle lifecycle | 50 | `a791f1f0a47f197ade41f24f873280949602d15c22520f5805b0bb93a27c471b` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_8008862C.s` |
| `func_level_25_80089808` | two-mode camera selector with animation fallback | 51 | `28a7e6102288fd3c7ae5d66c132a9506c34c3ee83c92dcc7f696bba232f0f5c2` | `asm/nonmatchings/overlays/level_25/camera/func_level_25_80089808.s` |
| `func_level_26_800866E0` | drawn-actor vector projection and screen bounds | 49 | `7dae1f38a69973b0407ae39599da08a0e7c186510168105a80c859179b8cfab9` | `asm/nonmatchings/overlays/level_26/level/func_level_26_800866E0.s` |
| `func_level_37_8007E758` | radius query and target byte-angle update | 51 | `6bc19457c97a5ab102a050a4589e35393b82016e729ba8006283699df8961b72` | `asm/nonmatchings/overlays/level_37/moby/func_level_37_8007E758.s` |
