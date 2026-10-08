# Verified overlay batch 2026-10-04-614

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 159 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch614.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: existing upstream Moby, animation and vector helpers, with control flow transcribed from the original level 50 handler. This preserves the linked actor guard, dialogue reset, player bounds query, actor allocation and saved-position calculation. An empty pointer constraint preserves the original player-field address reuse; it emits no instructions.

Categories: {'linked actor dialogue and save position': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_50_8007BAF4` | linked actor dialogue and save position | 159 | `7aa2dff996e165cda7f72301ec4a1ffd019d6e293d3b164d67f3d8e3eda381e7` | `asm/nonmatchings/overlays/level_50/moby/func_level_50_8007BAF4.s` |
