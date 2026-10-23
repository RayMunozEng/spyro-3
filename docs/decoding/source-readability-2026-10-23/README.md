# Accepted source readability cleanup, 2026-10-23

AI generated; not human reviewed. Acceptance preceded publication; the containing cleanup commit records publication.

- [Publication verification](publication-verification.json): exact staged native
  source equals the accepted source; all original output hashes are retained.
- [Acceptance receipt](accepted.json): final source pins, unchanged commands,
  output hashes, compiler-sensitive exception and gate-log hashes.
- [Existing helper operations](helper-operations.json): original and Rev 1
  operation references, alias declarations and name mappings.
- [Existing Moby member authority](moby-member-authority.json): exact header
  member types/offsets and original callback bindings for the applied fields.

The original repository baseline is
`4c5d4f34cbf91c4c67a993bca66cb051b2b52a04`. Its existing Moby structure and
ordinary typed C are the style/layout references. Rev 1 evidence supplies only
the already decoded operation names; revision addresses are mapped individually.

There are 9,354 typed member expressions, 269 aliases for 12 operations, and
226 rewrapped definitions across 74 changed C files. All 96 unchanged native
commands and all 62 original BASE image hashes pass; the linked ELF and PSX EXE
are bit-identical. The one retained raw read is a compiler scheduling constraint.

These checks establish the matching output and the bounded source cleanup.
They do not add whole-game semantic or live runtime claims. Extra raw588
lifetime/null-route verification was stopped at the user's request. Existing
unknown private layouts and producer/lifecycle histories remain documented.
