#!/usr/bin/python3
"""Tests for Base."""
import unittest
from models.base import Base


class TestBase(unittest.TestCase):
    """Test Base."""

    def test_auto_id(self):
        """Test Base() assigns an ID automatically."""
        first = Base()
        self.assertIsInstance(first.id, int)

    def test_auto_id_increment(self):
        """Test automatic IDs increment."""
        first = Base()
        second = Base()
        self.assertEqual(second.id, first.id + 1)

    def test_explicit_id(self):
        """Test Base(89) saves the passed ID."""
        obj = Base(89)
        self.assertEqual(obj.id, 89)

    def test_to_json_none(self):
        """Test to_json_string(None)."""
        self.assertEqual(Base.to_json_string(None), "[]")

    def test_to_json_empty(self):
        """Test to_json_string([])."""
        self.assertEqual(Base.to_json_string([]), "[]")

    def test_to_json_dictionary(self):
        """Test JSON conversion of dictionaries."""
        self.assertEqual(Base.to_json_string([{"id": 12}]), '[{"id": 12}]')

    def test_to_json_returns_string(self):
        """Test JSON result is a string."""
        result = Base.to_json_string([{"id": 12}])
        self.assertIsInstance(result, str)

    def test_from_json_none(self):
        """Test from_json_string(None)."""
        self.assertEqual(Base.from_json_string(None), [])

    def test_from_json_empty(self):
        """Test from_json_string('[]')."""
        self.assertEqual(Base.from_json_string("[]"), [])

    def test_from_json_dictionary(self):
        """Test from JSON dictionary."""
        self.assertEqual(
            Base.from_json_string('[{ "id": 89 }]'),
            [{"id": 89}]
        )

    def test_from_json_returns_list(self):
        """Test from_json_string returns a list."""
        result = Base.from_json_string('[{ "id": 89 }]')
        self.assertIsInstance(result, list)


if __name__ == "__main__":
    unittest.main()
