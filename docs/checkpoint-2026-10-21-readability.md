# Native source readability cleanup

AI-generated changes; not human reviewed. Retained or imported original code
remains attributable to its original contributors. The fork owner directed the
work and did not personally write these added implementations.

This cleanup follows the all-functions matching checkpoint
`2a4b15ee1d24dbe333fd3e758193711647907fa3`. All 337 executable and 3,098 overlay
functions remain matched. The frozen compiler, flags and filters were retained.

The working-source verification passed all 95 retained native checks and all 62
BASE reference image hashes. Exact staged Git source bytes also passed those checks before publication; see `readability-verification.json`.

The changes format 384 C files, name proved helper operations, replace repeated
empty compiler annotations with exact-expansion macros, reuse 36 typed callbacks,
polish 7 shared actor variants, and remove 338 unused private helper prototypes.
All four original shared actor include families are accounted for. Three original
same-line observer clauses are protected because the compiler's branch merging
depends on their shared source line.

Reference images are the upstream BASE images before antipiracy checksum
correction/encryption. Matching is not semantic or runtime completeness.
Unknown helper contracts, gameplay units and the retained raw588 private-field
and cold-frame producer frontier remain explicit. Source names make no new
audible sound-ID or universal coordinate-scale claims.

Reproduce the complete native image comparison in a configured checkout:

```sh
python3 tools/verify_matching.py --build
```

See `source-readability.md` and the naming/shared-family evidence under
`decoding/` for scope, provenance and unresolved semantic targets.
