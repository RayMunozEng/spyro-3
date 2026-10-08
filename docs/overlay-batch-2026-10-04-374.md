# Verified overlay batch 2026-10-04-374

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 4 functions, 520 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch374.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Implementation: four record table update routines, using the existing SpeedwayRecord fields and original per-record stride. Retains all global gates, the original counter equality chain, comparison/store conditions, completion flag bits, global reset and optional transition helper. Private aliases expose the scalar accesses to symbols also declared elsewhere as a struct or array; linked-word verification proves the original addresses. Names inherit upstream labels and do not establish independently reviewed challenge semantics. No compiler constraints or instruction assembly are needed.

Categories: {'record table updates and transition gate': 4}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_15_80080BD4` | record table updates and transition gate | 130 | `ee73d9d450f4f0ddd694278b4d5b4c4ac0e6a68f6892a2a1f3c90d50aefac2be` | `asm/nonmatchings/overlays/level_15/level/func_level_15_80080BD4.s` |
| `func_level_25_8008158C` | record table updates and transition gate | 130 | `56ff925ab77b4f06554d6c34a1aac1b91e78ceae5b39e4f48a49db260be95609` | `asm/nonmatchings/overlays/level_25/level/func_level_25_8008158C.s` |
| `func_level_35_80082910` | record table updates and transition gate | 130 | `2bb042fd9c520e8ec7b848431060889d28158cdd20201e45a89a89827f3a1ebe` | `asm/nonmatchings/overlays/level_35/level/func_level_35_80082910.s` |
| `func_level_45_80080ECC` | record table updates and transition gate | 130 | `d212ec4f903b596da889885dd84c1072a0a533253bb5e84bc9bdf5a0b00cf0f0` | `asm/nonmatchings/overlays/level_45/level/func_level_45_80080ECC.s` |
