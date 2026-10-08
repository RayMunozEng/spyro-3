# Verified overlay batch 2026-10-03-100

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 3 functions, 87 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch100.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Existing upstream overlay callback declarations, Moby and Spyro layouts are the baseline.

## Widths, scheduling and remaining evidence

The fragment wrapper reads the Moby damage word and forwards six original fragment arguments, then the original three helper calls. The animation selector advances by 16-byte records and only forwards a null vector or Spyro vector at +0xCC for the original states 0x13/0x14/0x1E. The title launcher preserves all three NUL-terminated original strings, callback order, address 0x801FFF00 and final argument 0. Complete overlay hashes also verify the string data and alignment. No full demo-loading or particle asset behavior is claimed. Next evidence target: callback/record producers and retail runtime captures of the launcher and event wrappers.

Categories: {'damage-gated fragment callback sequence': 1, 'animation record selection and state-gated vector callback': 1, 'original title demo-launch callback order and strings': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_26_80083C2C` | damage-gated fragment callback sequence | 31 | `7108e8515732be3d37f4151515f6e1a458d50bc300de6252f7154db9fa5979f7` | `asm/nonmatchings/overlays/level_26/moby/func_level_26_80083C2C.s` |
| `func_level_40_8008656C` | animation record selection and state-gated vector callback | 30 | `9044f933c9274ac9fb96579215601fdd8ed6a62f0a70165442ce3a4671075507` | `asm/nonmatchings/overlays/level_40/animation/func_level_40_8008656C.s` |
| `func_title_80078B88` | original title demo-launch callback order and strings | 26 | `de2cdd23c61ba2c87680e93744ca452e5db2b3a2fbbc569d673e1381eb2c0f84` | `asm/nonmatchings/overlays/title/crash/func_title_80078B88.s` |
