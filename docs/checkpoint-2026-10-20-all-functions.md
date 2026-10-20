# Completed native function matching: 2026-10-20

AI generated; not human reviewed. Upstream work retains its original attribution.

Accepted authority 36300/36380: **3,098/3,098 overlays**, **337/337 EXE**,
**3,435/3,435 inventoried functions**. This checkpoint adds the remaining592
overlay functions since aa63abd. Some implementations are documented mixed
C/original assembly. No complete semantic decode or portable-C claim is made.

The fresh36307 run passed all95 commands, retaining all92 previous commands.
All62 complete BASE reference images match: the EXE plus61 overlays. These
are the upstream uncorrected build hashes, before antipiracy checksum
correction/encryption; this is not raw-disc or playable-disc verification.
The final three linked checks include all5,241 native instructions,46 switch
selectors, two padding words and44 additional literal-prefix bytes.

The preserved verification receipts are under `docs/verification/36300`.
Their historical absolute paths describe this machine's analysis workspace.
Intermediate probes and large generated artifacts are not required by the
source build and are not part of this checkpoint. The95-command historical
research chain needs those saved local artifacts; it is not presented as a
self-contained clean-checkout test suite. The62-hash verification below is
self-contained after installing the documented build dependencies.

## Reproduce the reference images

Initialize the existing MASPSX submodule with `git submodule update --init`.
Use the existing Dockerfile/Linux toolchain and Python dependencies from the
README. From the repository root, run:

```sh
python3 tools/verify_matching.py --build
```

`build.py` is copied byte-for-byte from the frozen `full_build3331.py` driver
used by the accepted95-check run. It preserves the tested compiler, flags,
COFF filtering, original-section metadata and assembler behavior. The verifier
requires all62 unchanged hashes in `sha256sum.txt` and exits nonzero on any
mismatch. The upstream manifest spells19 cutscene paths `build.wad/`; the verifier maps only that directory spelling to `build/wad/` and preserves every expected hash. Original disc images, game archives, build outputs, probes, unrelated
SpyroCode/browser work and incidental empty-file deletions are excluded.

## Remaining decoding work

Source identity and machine behavior are verified; helper/field meanings,
units/cadence, dynamic memory roots, state/lifetime chains, asset links,
synchronized retail runtime coverage and human review remain open.
In particular, Level18's earlier current-SP20/SP24 producers are unresolved;
the implementation retains their original native reads, without inventing
initializers or values. See `docs/native-matching-handoff.md` for the exact
evidence frontiers and historical rejected probes.

This commit is the user-authorized matching checkpoint. Historical receipts
that say "uncommitted" record their state when tested. Further decoding
continues after this checkpoint and is excluded from this commit. No PR.
