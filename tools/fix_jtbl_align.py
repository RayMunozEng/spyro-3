# Preserve compiler jump-table placement using original overlay assembly metadata.
import sys
import re
from pathlib import Path

def fix_section(lines):
    source = sys.argv[sys.argv.index("--overlay-source") + 1] if "--overlay-source" in sys.argv else None
    function = None
    table_index = 0
    lines = iter(lines)
    for line in lines:
        entry = re.match(r"\s*\.ent\s+(\w+)", line)
        if entry:
            function = entry.group(1)
            table_index = 0
        if line.strip().startswith(".section .rodata"):
            next_line = next(lines, "")
            if next_line.strip().replace("\t", " ").startswith(".align 3"):
                if source:
                    block = []
                    for item in lines:
                        block.append(item)
                        if item.strip() == ".text":
                            break
                    entries = sum(bool(re.search(r"\.word\s+\$L", item)) for item in block)
                    if entries:
                        original = Path("asm/nonmatchings") / Path(source).relative_to("src") / (function + ".s")
                        original_text = original.read_text().split(".section .text")[0]
                        tables = re.split(r"\.size[^\n]*", original_text)
                        tables = [part for part in tables if re.search(r"\.word\s+\.L", part)]
                        table = tables[table_index]
                        table_index += 1
                        expected_entries = len(re.findall(r"\.word\s+\.L", table))
                        assert entries == expected_entries, (function, entries, expected_entries)
                        padding = len(re.findall(r"\.word\s+0x00000000", table))
                        original_prefix = original_text[:original_text.index(table) + len(table)]
                        original_sections = re.findall(r"(?m)^\s*\.section\s+(\.rodata(?:\.jtbl)?)\s*$", original_prefix)
                        assert original_sections, (function, "original table section missing")
                        yield ".section " + original_sections[-1] + "\n"
                        yield next_line
                        for item in block:
                            if item.strip() == ".text":
                                for unused in range(padding):
                                    yield ".word 0x00000000\n"
                            yield item
                    else:
                        yield ".section .rodata.jtbl\n"
                        yield next_line
                        yield from block
                else:
                    yield ".section .rodata.jtbl\n"
                    yield next_line
            else:
                yield line
                yield next_line
        else:
            yield line

for line in fix_section(sys.stdin.readlines()):
    sys.stdout.write(line)
