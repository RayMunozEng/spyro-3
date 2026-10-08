# Verified overlay batch 2026-10-03-193

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 99 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch193.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The camera initializer reuses the verified level 36 initializer with the retail-specific selectors 4, 0xC and 0x17 and byte 0x141 cleared. SDK CameraPosition declarations and helper calls are unchanged. The damage routine retains its tag, invokes the original damage and selector callbacks, sets tag word 0 to 1 and records that same word in both saved-state buffers. A nonzero tag word then invokes the environment helper with literal 0xFC, sets actor state 1, and selects animation 1. Numeric selector meanings remain unknown.

Categories: {'three-mode camera initialization': 1, 'damage-gated saved state and animation transition': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_24_800968CC` | three-mode camera initialization | 49 | `28069b3b01c750e0dc9ca1f881cfb27f5ad420ca7bf74d777f38e9100916e831` | `asm/nonmatchings/overlays/level_24/camera/func_level_24_800968CC.s` |
| `func_level_22_8007B02C` | damage-gated saved state and animation transition | 50 | `b5b6c483c6ad91f03418c08542223f7af18bf88a862cdb990cfddff5f0ba65ec` | `asm/nonmatchings/overlays/level_22/moby/func_level_22_8007B02C.s` |
