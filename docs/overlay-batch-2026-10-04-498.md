# Verified overlay batch 2026-10-04-498

AI-generated additions and integration; not yet human-reviewed.

Retail authority: SCUS-94467 USA Rev 0, original assembly sources listed below. Existing field and helper names are reused; no new interpretation of unknown fields is claimed. Each routine operates once per invocation; original access widths, constants and branch conditions are preserved. Confidence: exact compiled bytes.

Accepted 3 functions, 312 retail words including tables. Full EXE and all overlay hash verification passed in `build/overlay_batch498.full.log`; the focused linked audit found zero mismatches. EXE SHA-256: `e5406997dccc7300c8198498c20b9d6c4c0a547813be1010446b6c4e5d50e39f`.

Falsifiable vectors: compare each original instruction/table word at its recorded assembly address against the corresponding linked overlay; rebuild and check every complete overlay hash. Browser-engine and semantic runtime interpretations are not established by this batch.

The particle-path handler preserves the original signed count, point stride of sixteen bytes, timer decrement, random mask 4095, two signed divisions, quotient/remainder reuse and rational-vector helper arguments. It retains the fallback to the actor position and timer reset `(rand() & 3) + 3`. The nearest-point helpers read byte counts and points at offset 8 within 28-byte records following a 12-byte header. Both original distance scans use initial limit 9,999,999 and -1 indices, then select and possibly reverse the signed halfword direction before signed modulo. Empty constraints preserve store/load ordering, the signed halfword reload and logical count shift. The compiler allocates and saves its frame-pointer register naturally; no fixed frame-pointer binding is used. Numerical behavior is confirmed by exact linked words and complete binary hashes; asset semantics remain unreviewed.

Categories: {'timed particle position from original tagged path interpolation': 1, 'nearest tagged point pair and shorter circular traversal direction': 2}.

| Function | Kind | Retail words | Original words SHA-256 | Assembly source |
| --- | --- | ---: | --- | --- |
| `func_level_24_8008997C` | timed particle position from original tagged path interpolation | 92 | `08a3b293c484bd89d4949f7145cbc5ce0d45cdadd903947ec57011ddd28e9d5f` | `asm/nonmatchings/overlays/level_24/moby/func_level_24_8008997C.s` |
| `func_level_34_80091C98` | nearest tagged point pair and shorter circular traversal direction | 110 | `2821cc70515f5b40173f35a9f5d2a0722caae02d957312248143bdacd432f094` | `asm/nonmatchings/overlays/level_34/level/func_level_34_80091C98.s` |
| `func_level_41_8008C128` | nearest tagged point pair and shorter circular traversal direction | 110 | `2821cc70515f5b40173f35a9f5d2a0722caae02d957312248143bdacd432f094` | `asm/nonmatchings/overlays/level_41/level/func_level_41_8008C128.s` |
