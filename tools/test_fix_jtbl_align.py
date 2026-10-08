import subprocess
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

class OverlayTableLayoutTests(unittest.TestCase):
    def run_filter(self, fixture, *arguments):
        return subprocess.run([sys.executable, str(ROOT / "tools/fix_jtbl_align.py"), *arguments], input=fixture, text=True, capture_output=True, cwd=ROOT)

    def fixture(self, function=None, count=9):
        return (".ent " + function + "\n" if function else "") + ".section .rodata\n.align 3\n" + ".word $L1\n" * count + ".text\n"

    def test_executable_section_policy_is_preserved(self):
        fixture = self.fixture()
        result = self.run_filter(fixture)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(result.stdout, fixture.replace(".section .rodata", ".section .rodata.jtbl"))

    def test_overlay_table_preserves_recorded_padding(self):
        fixture = self.fixture("func_level_10_80089B9C")
        result = self.run_filter(fixture, "--overlay-source", "src/overlays/level_10/animation")
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(result.stdout, fixture.replace(".text\n", ".word 0x00000000\n.text\n"))

    def test_overlay_table_without_padding_stays_unpadded(self):
        fixture = self.fixture("func_level_15_800886FC")
        result = self.run_filter(fixture, "--overlay-source", "src/overlays/level_15/animation")
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(result.stdout, fixture)

    def test_wrong_entry_count_is_rejected(self):
        result = self.run_filter(self.fixture("func_level_10_80089B9C", 8), "--overlay-source", "src/overlays/level_10/animation")
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("AssertionError", result.stderr)

if __name__ == "__main__":
    unittest.main()
