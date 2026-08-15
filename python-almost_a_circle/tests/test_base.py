#!/usr/bin/python3
"""Unit tests for the Base class."""

import unittest

from models.base import Base


class TestBase(unittest.TestCase):
    """Test cases for Base."""

    def test_id_automatic(self):
        """Test automatic ID assignment."""
        b1 = Base()
        b2 = Base()
        self.assertEqual(b2.id, b1.id + 1)

    def test_id_given(self):
        """Test given ID."""
        b = Base(89)
        self.assertEqual(b.id, 89)

    def test_id_given_does_not_increment(self):
        """Test given ID does not affect automatic IDs."""
        b1 = Base()
        Base(89)
        b2 = Base()
        self.assertEqual(b2.id, b1.id + 1)

    def test_id_zero(self):
        """Test ID zero."""
        b = Base(0)
        self.assertEqual(b.id, 0)

    def test_id_negative(self):
        """Test negative ID."""
        b = Base(-1)
        self.assertEqual(b.id, -1)

    def test_id_string(self):
        """Test string ID."""
        b = Base("test")
        self.assertEqual(b.id, "test")


if __name__ == "__main__":
    unittest.main()
