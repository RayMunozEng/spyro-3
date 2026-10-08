# Verified overlay batch 2026-10-04-362

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 444 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch362.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: four actor spawn/update routines built from the original instruction branches and existing Moby, Vector3D and overlay callback layouts. Preserves states 0/1/2, free-capacity threshold 0x15, masked random threshold comparison, the two global-selected actor helpers, the count-triggered callback and substate store, the every-fourth-invocation global gate, and the particle parameter vectors with +0x80 Z and masked random X/Y. Callback selectors remain numeric; their visual or gameplay meaning is not newly inferred. No empty constraints or embedded instructions are needed.

Categories: {'actor spawn gate transition and particle dispatch': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_13_8007B3F8` | actor spawn gate transition and particle dispatch | 111 | `f64c2e87e814132c411183639b18c7523191d1234b9bac99f1cc38e6e7fbbc40` | `asm/nonmatchings/overlays/level_13/moby/func_level_13_8007B3F8.s` |
| `func_level_26_8007A4CC` | actor spawn gate transition and particle dispatch | 111 | `b84e769a81a7712b8bf559d40b94a6d4c23b0b5a396e8301da09d788daf73811` | `asm/nonmatchings/overlays/level_26/moby/func_level_26_8007A4CC.s` |
| `func_level_35_8007860C` | actor spawn gate transition and particle dispatch | 111 | `8cb6e1cf8c52aa9b6eecc2d53c1a8911684c7e8b268127be4495a0e271c00158` | `asm/nonmatchings/overlays/level_35/moby/func_level_35_8007860C.s` |
| `func_level_42_8007DE10` | actor spawn gate transition and particle dispatch | 111 | `5300c1270bc7b9a0c393c4095a7f5f78653722307d8cd3652492415f6571e644` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_8007DE10.s` |
