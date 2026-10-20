"""Regression tests for non-emitting COFF metadata filtering."""
import unittest
from fix_coff_debug import filter_coff_debug

class CoffFilterTests(unittest.TestCase):
    def test_scope_end_does_not_hide_loop_entry(self):
        source = ["lw $4,0($2)\n", "$Le344:\n", "#.bend $Le344 72\n",
                  "$L1039:\n", "lhu $5,0($4)\n", "bgez $2,$L1039\n"]
        self.assertEqual(list(filter_coff_debug(source)),
                         [source[i] for i in (0, 3, 4, 5)])

    def test_labels_without_coff_records_are_preserved(self):
        source = ["$Le999:\n", "j $Le999\n", "nop\n"]
        self.assertEqual(list(filter_coff_debug(source)), source)

    def test_load_hints_and_assembler_modes_are_preserved(self):
        source = [".set noreorder\n", "#nop\n", "$L7:\n", "lw $2,0($4)\n",
                  ".set reorder\n", ".set volatile\n", ".set novolatile\n"]
        self.assertEqual(list(filter_coff_debug(source)), source[:5])

if __name__ == "__main__":
    unittest.main()
