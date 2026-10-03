"""Remove non-emitting GCC COFF metadata before MASPSX lookahead.

MASPSX 2.56 lookahead treats commented .def/.begin/.bend records and
.set volatile/novolatile as instructions. That hides load-use hazards or
causes its label-skip counter to consume metadata instead of the label.
GNU as never receives these records: MASPSX already discards them. Remove
them before lookahead so labels remain attached to load-delay NOPs.
Instruction lines, labels, #nop scheduling hints and reorder directives
are preserved. Retail executable and overlay hashes are the acceptance gate.
"""
import sys


def filter_coff_debug(lines):
    for line in lines:
        stripped = line.strip()
        if stripped.startswith(("#.def", "#.begin", "#.bend")):
            continue
        if stripped.split() in ([".set", "volatile"], [".set", "novolatile"]):
            continue
        yield line


if __name__ == "__main__":
    sys.stdout.writelines(filter_coff_debug(sys.stdin))
