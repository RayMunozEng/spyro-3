import sys
import unittest
from pathlib import Path

from fix_coff_debug import filter_coff_debug

sys.path.insert(0, str(Path(__file__).parent / "maspsx"))
from maspsx import MaspsxProcessor


class CoffDebugTests(unittest.TestCase):
    def test_preserves_code_and_scheduler_metadata(self):
        code = ["lw\t$9,352($sp)\n", "#nop\n", "$L99:\n",
                ".set\tnoreorder\n", "#APP\n", "# ordinary comment\n"]
        debug = ["#.def\tblock_101;\n", "#.begin\t$Lb2\n", "#.bend\t$Le2\n",
                 ".set\tvolatile\n", ".set\tnovolatile\n"]
        self.assertEqual(list(filter_coff_debug(debug + code)), code)

    def test_load_delay_label_precedes_nop_once(self):
        assembly = [".set\treorder\n", "lw\t$9,352($sp)\n",
                    ".set\tnovolatile\n", "#.def\tblock_101;\n",
                    "$L99:\n", "addu\t$9,$9,68\n"]
        processor = MaspsxProcessor(list(filter_coff_debug(assembly)), sdata_limit=0)
        result = processor.process_lines()
        self.assertEqual(result.count("$L99:"), 1)
        self.assertTrue(result[result.index("$L99:") + 1].startswith("nop"), result)


if __name__ == "__main__":
    unittest.main()
