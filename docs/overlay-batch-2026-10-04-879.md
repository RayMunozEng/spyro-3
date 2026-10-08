# Verified overlay batch 2026-10-04-879

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 3 functions, 429 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch879.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: the already verified `func_level_36_8008653C` camera state-13 route was reused, then the state-17 route was reconstructed from the original assembly listed below. Existing upstream camera and vector declarations are reused. The signed counter index is `(counter + 2) >> 2`, capped only above 4; the table stride is 20 bytes. State 13 preserves the actor-to-player delta and angle-helper argument 1, the zero-counter initialization calls, and all four position-table calls. State 17 requires the previous camera-state value 17, preserves the initial conditional position update, saved-vector copy, angle reset, original table-call order, bit-2 guard, and final first-word copy. Record offsets are byte offsets relative to D_8006E130. Position units, table producer meanings, helper update semantics, and caller cadence remain separate evidence targets. Confidence is exact linked instruction equality, not semantic or runtime camera completeness. The additions use ordinary C without empty compiler constraints or instruction-bearing inline assembly.

Categories: {'camera-state target and position-table update': 3}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_17_80083A08` | camera-state target and position-table update | 143 | `f5f33bdfcececcffcdf26e13879805c40b2623de8bd60ad2ea248358bcc5aa92` | `asm/nonmatchings/overlays/level_17/camera/func_level_17_80083A08.s` |
| `func_level_27_800896FC` | camera-state target and position-table update | 143 | `b0df761b4d34528b1f5ae2c18ec9911a008d95553d3c85145c4fffe44a05c572` | `asm/nonmatchings/overlays/level_27/camera/func_level_27_800896FC.s` |
| `func_level_37_8008B554` | camera-state target and position-table update | 143 | `fe5f231efd3474bc7318745ee0dda988f3c1c4a82c63cada153b83d45bb89065` | `asm/nonmatchings/overlays/level_37/camera/func_level_37_8008B554.s` |
