# Verified overlay batch 2026-10-03-115

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 276 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch115.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream camera helper declaration and original speedway instructions. All state selectors, counters and timer accesses are signed 32-bit words. Mode 2 sets the recorded state directly or uses result 1 when its companion word is 4. The other branch tests four consecutive words for 8, otherwise selects result 1/2 according to the original signed timer comparison. Shared store and finish labels retain the original branch layout; an empty timer constraint preserves its original register. No update interval or interpretation of the timer is inferred. Next evidence target: producers of the speedway globals and consumer of the selected state.

Categories: {'speedway word state selection and camera helper transition': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_15_80080AC0` | speedway word state selection and camera helper transition | 69 | `9ef513b0302a841322d2f0c30976b49f777435bcf8f11a96891c889221290df4` | `asm/nonmatchings/overlays/level_15/level/func_level_15_80080AC0.s` |
| `func_level_25_80081478` | speedway word state selection and camera helper transition | 69 | `b61f62a6a2aab0bd7d23d9759da66ec70827c3329bda609f3e84ced9a120b468` | `asm/nonmatchings/overlays/level_25/level/func_level_25_80081478.s` |
| `func_level_35_800827FC` | speedway word state selection and camera helper transition | 69 | `aeced037f9394a1725d404d9032b14546047ecc1feabd1a34f6f11ddbe8cb9db` | `asm/nonmatchings/overlays/level_35/level/func_level_35_800827FC.s` |
| `func_level_45_80080DB8` | speedway word state selection and camera helper transition | 69 | `8ce57875ec075eee45a405b4ffab4c30895d88f1bc5129367ed77de9ddca78ba` | `asm/nonmatchings/overlays/level_45/level/func_level_45_80080DB8.s` |
