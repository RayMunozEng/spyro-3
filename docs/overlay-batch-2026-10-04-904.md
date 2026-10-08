# Verified overlay batch 2026-10-04-904

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 9 functions, 2016 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch904.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Source baseline: original controller instructions listed below, existing upstream Moby/vector declarations, and callback symbols. The function initializes a zero substate from the low byte of rand(), preserves the global >=2 gate, distance-helper comparison, absolute signed player-Z difference from actor-Z+356, and the original actor-position query call. The referenced private record has a signed halfword timer at +0, byte selector at +2, and selected-actor pointer at +20. It preserves same-actor/positive-timer checks, global actor rereads after stores and calls, and query result handling. The word at actor +24 is tested against 0x101B0000. The triggered route makes at most 12 ordered child-spawn calls while the global word difference stays >=21; first six children get substate 9, remaining children get animation byte 1 and substate 0. It then makes exactly eight pairs of particle calls, preserving every rand mask, per-axis offset, callback selector, pointer-valued argument, and final helper/deletion call. The untriggered route independently rereads the frame word for each angle component and preserves unsigned trig-table loads followed by signed shifts 16/25 and byte stores. Labels are working descriptions, not evidence of asset or actor identity. World units, distance-helper domain, private-record producers, word-difference meaning, particle payloads, and caller cadence remain separate evidence targets. Empty constraints emit no instructions and preserve original register lifetimes, load ordering, and initialization sequence; no instruction-bearing inline assembly is introduced.

Categories: {'global gated actor selection and ordered child and particle bursts': 9}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_10_80077C68` | global gated actor selection and ordered child and particle bursts | 224 | `e619cd87499df03acefa387eb685f6265db59965c7f3a445a9bb4ece37474803` | `asm/nonmatchings/overlays/level_10/moby/func_level_10_80077C68.s` |
| `func_level_14_8007846C` | global gated actor selection and ordered child and particle bursts | 224 | `ea060d06a5c67fa87f6dbe983d4b69cbaccbaed51253224201cbb0cc0b3e864c` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_8007846C.s` |
| `func_level_20_80078284` | global gated actor selection and ordered child and particle bursts | 224 | `fc2f1aea36cdaae25971a4c21dcb4f0d46b783ca90283e9f19bc42d24afe01c5` | `asm/nonmatchings/overlays/level_20/moby/func_level_20_80078284.s` |
| `func_level_24_80078E88` | global gated actor selection and ordered child and particle bursts | 224 | `0bcb2148fbc93187345b41631f2ffa2bca2a79a704c4a0235d5c8a8a77c49891` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_80078E88.s` |
| `func_level_30_80077F74` | global gated actor selection and ordered child and particle bursts | 224 | `ecb63292e285dd06c7334d0eedf3947a2506bb0a349ffdf9e30e7426050ad906` | `asm/nonmatchings/overlays/level_30/moby/func_level_30_80077F74.s` |
| `func_level_32_80078DD8` | global gated actor selection and ordered child and particle bursts | 224 | `af3485bd4853dac3ef7b7f64b9b77122873000752aa1abeb9d1e9bfc13799c7e` | `asm/nonmatchings/overlays/level_32/moby/func_level_32_80078DD8.s` |
| `func_level_41_800799AC` | global gated actor selection and ordered child and particle bursts | 224 | `621d76ac4e441f5cb7be6c86cefc08f9bcc3ec30be2350903a4352ad7e087987` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_800799AC.s` |
| `func_level_42_80078CAC` | global gated actor selection and ordered child and particle bursts | 224 | `2eab84d7b3e796799904dd397dc755f690d172b6c2049394800f5f1c8749be40` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_80078CAC.s` |
| `func_level_44_800785C4` | global gated actor selection and ordered child and particle bursts | 224 | `729267f9bb8366375b7772ff0f073ddbad169a2520b92bffaf4cefeefff0a320` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_800785C4.s` |
