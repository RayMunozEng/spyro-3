# Verified overlay batch 2026-10-04-457

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 6 functions, 557 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch457.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The level 45 enemy handler reuses the verified level 25 damage-transition baseline, adding only its evidenced sound call and next-animation pitch increment. The level 12 particle tag follows byte/halfword loads for angle steps, radius, timer and size adjustment; matrix and vector operations retain the original stack layout. Levels 27 and 37 preserve short velocity decay, byte timer wrap, exact pitch reversal conditions 32/224, and the random yaw increment. The menu copies use their own original helper addresses and retain the field-array addressing and changed-value branches. Empty constraints preserve register allocation and original memory reloads; they emit no instructions. These partial structures describe access offsets, not unproven asset or gameplay meanings.

Categories: {'damage transition callback and enemy state update': 1, 'tagged angular update, matrix offset, timer and size clamp': 1, 'fragment velocity decay, pitch reversal and lifetime': 2, 'menu field update and changed-value reporting': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_45_8007BD54` | damage transition callback and enemy state update | 94 | `21117cdfea745c6b9106dfa9bd4f6ce05437fbad54d6665b978fe51954a31467` | `asm/nonmatchings/overlays/level_45/moby/func_level_45_8007BD54.s` |
| `func_level_12_80081B1C` | tagged angular update, matrix offset, timer and size clamp | 91 | `ca959face3c4f4c026ceed6f96c47942b346cc739e55e23c16985a893fb593bb` | `asm/nonmatchings/overlays/level_12/moby/func_level_12_80081B1C.s` |
| `func_level_27_8007A230` | fragment velocity decay, pitch reversal and lifetime | 100 | `02279d704462b9c4077cebeb850bf87443db80fb4cd316e4010d41af6aa44e31` | `asm/nonmatchings/overlays/level_27/moby/func_level_27_8007A230.s` |
| `func_level_37_8007D9F4` | fragment velocity decay, pitch reversal and lifetime | 100 | `cb72be0458f1b82deb6580979efb3815a7cc34398483be42a35d599bfd39bc8a` | `asm/nonmatchings/overlays/level_37/moby/func_level_37_8007D9F4.s` |
| `func_options_8007833C` | menu field update and changed-value reporting | 86 | `b6936db325628d13e6bbbd7cf5b593ac517ab546ae1ad9fbd90f3da22ca9d41b` | `asm/nonmatchings/overlays/options/options3/func_options_8007833C.s` |
| `func_title_8007AD80` | menu field update and changed-value reporting | 86 | `3a10b68367831c55bd50ba295d6757370cbe1de6cca76f56a850bb77b27049fe` | `asm/nonmatchings/overlays/title/title4/func_title_8007AD80.s` |
