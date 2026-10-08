# Verified overlay batch 2026-10-04-721

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 2 functions, 282 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch721.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Rev 1 reuse: SpyroCode `playable_enchanted_raw1014_direct_controller_runtime.py` identifies the identical 141-word controller shape and stack target/output offsets 0x18/0x28. The controller decrements its timer, checks the existing child state, creates a child when the timer is zero, selects the farthest path point, and initializes velocity with signed Q12 table products and the vertical helper. Empty register constraints emit no instructions and retain retail allocation/scheduling. The Rev 1 decoder parameter named `owner_state` actually refers to the child: source word 0x90430048 at 0x8008309C reads v0+0x48 after v0 is loaded from owner.private+4. This addition follows original Rev 0 child-state instructions. Rev 1 helper identities and gameplay semantics are not established by structural reuse alone.

Categories: {'farthest path point selection and timed actor launch': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_22_80082F38` | farthest path point selection and timed actor launch | 141 | `a8be210bfdadf5477a1d9f5c956ff86cc954bfbec4a152a20cca203cb6b6d159` | `asm/nonmatchings/overlays/level_22/moby/func_level_22_80082F38.s` |
| `func_level_32_8008A30C` | farthest path point selection and timed actor launch | 141 | `3e92e1ad6fca6378bfe2858f7b0a6b4a48222697dc668bf94404f4c4c95d0305` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_8008A30C.s` |
