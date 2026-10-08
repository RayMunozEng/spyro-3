# Verified overlay batch 2026-10-04-698

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 177 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch698.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Reuses the verified level 40 camera initializer structure, retargeted to the original level 32 mode dispatch and complete table extent. Adds the original actor-class checks for 371 and 659. Empty register and memory constraints preserve byte-store ordering and pointer allocation; all emit no instructions. Camera units and semantics remain those of the existing upstream structures, with no new runtime interpretation claimed.

Categories: {'three-mode camera initialization': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_32_8009CC30` | three-mode camera initialization | 177 | `295b489965fce4737392526873569062e188766518117a84662d54aacb73d472` | `asm/nonmatchings/overlays/level_32/camera/func_level_32_8009CC30.s` |
