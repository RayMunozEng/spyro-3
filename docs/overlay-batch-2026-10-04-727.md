# Verified overlay batch 2026-10-04-727

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 1 functions, 107 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch727.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Rev 1 reuse: SpyroCode `playable-haunted-raw977-controller-runtime.md` and its source-locked 107-instruction decoder identify the three local state routes, pool actor indices, and HUD callback argument order. Rev 0 state zero checks bounds with radius 0x2800 and advances the indexed actor and owner; state one invokes the overlay callback, clears elapsed time, obtains duration minus one, and stores a sign-extended 16-bit HUD result; state two advances the previous pool actor and releases the HUD/owner after elapsed reaches duration. Existing SDK structures and helper declarations are reused. No register or scheduling constraints were needed. Unknown callbacks, elapsed-time producer, and live timing remain unestablished.

Categories: {'three-state sequence gate and HUD duration': 1}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_43_800887D4` | three-state sequence gate and HUD duration | 107 | `3631f993c1914e840e899de2055df8ab0a5e810d98dfdface6b0e446857136ec` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_800887D4.s` |
