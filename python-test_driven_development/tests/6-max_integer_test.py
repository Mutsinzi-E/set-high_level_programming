#!/usr/bin/python3
"""Unittest for max_integer([..])."""

import unittest
max_integer = __import__('6-max_integer').max_integer


class TestMaxInteger(unittest.TestCase):
    """Test cases for max_integer."""

    def test_ordered_list(self):
        """Test a list in ascending order."""
        self.assertEqual(max_integer([1, 2, 3, 4]), 4)

    def test_unordered_list(self):
        """Test a list in random order."""
        self.assertEqual(max_integer([1, 3, 4, 2]), 4)

    def test_max_at_beginning(self):
        """Test when the maximum integer is at the beginning."""
        self.assertEqual(max_integer([10, 5, 3, 1]), 10)

    def test_negative_numbers(self):
        """Test a list containing negative numbers."""
        self.assertEqual(max_integer([-4, -2, -10, -1]), -1)

    def test_mixed_numbers(self):
        """Test positive, negative, and zero."""
        self.assertEqual(max_integer([-5, 0, 10, -2, 3]), 10)

    def test_single_element(self):
        """Test a list with one element."""
        self.assertEqual(max_integer([7]), 7)

    def test_duplicate_max(self):
        """Test duplicate maximum values."""
        self.assertEqual(max_integer([2, 5, 5, 1]), 5)

    def test_duplicate_values(self):
        """Test a list containing only duplicate values."""
        self.assertEqual(max_integer([4, 4, 4, 4]), 4)

    def test_empty_list(self):
        """Test an empty list."""
        self.assertIsNone(max_integer([]))

    def test_float_values(self):
        """Test a list containing floats."""
        self.assertEqual(max_integer([1.5, 3.7, 2.2]), 3.7)

    def test_negative_float_values(self):
        """Test negative floats."""
        self.assertEqual(max_integer([-1.5, -3.7, -0.2]), -0.2)

    def test_large_numbers(self):
        """Test large integers."""
        self.assertEqual(max_integer([1000000, 999999, 2000000]), 2000000)

    def test_zero_values(self):
        """Test a list containing zero."""
        self.assertEqual(max_integer([0, 0, 0]), 0)


if __name__ == '__main__':
    unittest.main()
