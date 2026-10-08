# Verified overlay batch 2026-10-03-170

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 9 functions, 756 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch170.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

Baseline: upstream `SpeechProps`, `Moby`, existing dialogue helpers and the fully verified flow from batch 169. Each family preserves its original signed class comparison, unsigned progress byte, unsigned index-table lookup and progress-bit test, which selects next-message byte 0/1/2. Message byte two clears auto-talk byte +5. The manual-talk path calls the original helper only with input bit 0x10; only its failed result clears talkable byte +7. Auto-talk is then reloaded before the second helper path; success starts the original dialogue helper and sets state one. State one preserves the original signed game-state comparison, tag word +0x20 store and state-zero transition. That extension word is accessed explicitly by byte offset because upstream SpeechProps does not define it. Empty memory constraints preserve store/load order and emit no instructions. Byte/word representations and branch ordering are confirmed; message semantics, tag extension purpose and invocation cadence are unresolved. Next evidence target: dialogue helper mutations and producers/consumers of the extension word.

Categories: {'class and lookup-gated speech tag state chain': 9}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_14_8007A0DC` | class and lookup-gated speech tag state chain | 84 | `cc77a02dbbbdf6ec1b64388a8707ecfd2f0768a3e969152c36d86f9fa0bc9b99` | `asm/nonmatchings/overlays/level_14/moby/func_level_14_8007A0DC.s` |
| `func_level_23_8007AA78` | class and lookup-gated speech tag state chain | 84 | `f92fa8d35e5bb2e61029192e876e8a6b4140cecc3010afc17593cc6640701746` | `asm/nonmatchings/overlays/level_23/moby/func_level_23_8007AA78.s` |
| `func_level_42_8007C778` | class and lookup-gated speech tag state chain | 84 | `5788cf48fb35b32c77ce62bc4cc5f8a8f390e794b17fdbdf325f24cbc8417a61` | `asm/nonmatchings/overlays/level_42/moby/func_level_42_8007C778.s` |
| `func_level_24_8007BE04` | class and lookup-gated speech tag state chain | 84 | `39365e590df97a7622bf2858e3bd4cdd97822164329581b15d21311fa45647c3` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_8007BE04.s` |
| `func_level_31_8007A058` | class and lookup-gated speech tag state chain | 84 | `6ae5f34997945ce0f9abb8efd30737e780ec7661c4ae32ec9d73ee38b3512751` | `asm/nonmatchings/overlays/level_31/moby/func_level_31_8007A058.s` |
| `func_level_41_8007B968` | class and lookup-gated speech tag state chain | 84 | `3064dd0338b6cc6a3216464bb8f50b832be6fcc0fb849eb8daadf3aec2de34fb` | `asm/nonmatchings/overlays/level_41/moby/func_level_41_8007B968.s` |
| `func_level_33_8007B948` | class and lookup-gated speech tag state chain | 84 | `1a479a1a80161b6595e6a5540c7cdb9311b21db3a0d3804b6df03d3f8ec3bb76` | `asm/nonmatchings/overlays/level_33/moby/func_level_33_8007B948.s` |
| `func_level_43_8007A13C` | class and lookup-gated speech tag state chain | 84 | `d277ac655524023435099bbe620f0127ebef5d60fada9ce2fbe7b8a77b94f726` | `asm/nonmatchings/overlays/level_43/moby/func_level_43_8007A13C.s` |
| `func_level_44_8007A2C4` | class and lookup-gated speech tag state chain | 84 | `c5114e136daf61358a359a5409b258e97146e869fc98fb5831f56a727a7f25f6` | `asm/nonmatchings/overlays/level_44/moby/func_level_44_8007A2C4.s` |
