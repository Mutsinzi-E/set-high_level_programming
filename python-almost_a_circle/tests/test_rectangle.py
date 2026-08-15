#!/usr/bin/python3
"""Unit tests for the Rectangle class."""

import unittest

from models.rectangle import Rectangle


class TestRectangle(unittest.TestCase):
    """Test cases for Rectangle."""

    def test_rectangle_creation(self):
        """Test Rectangle creation."""
        r = Rectangle(10, 20)
        self.assertEqual(r.width, 10)
        self.assertEqual(r.height, 20)
        self.assertEqual(r.x, 0)
        self.assertEqual(r.y, 0)

    def test_rectangle_id(self):
        """Test Rectangle ID."""
        r = Rectangle(10, 20, 3, 4, 89)
        self.assertEqual(r.id, 89)

    def test_rectangle_inherits_base(self):
        """Test Rectangle inherits from Base."""
        from models.base import Base
        self.assertTrue(issubclass(Rectangle, Base))

    def test_width_setter(self):
        """Test width setter."""
        r = Rectangle(10, 20)
        r.width = 30
        self.assertEqual(r.width, 30)

    def test_height_setter(self):
        """Test height setter."""
        r = Rectangle(10, 20)
        r.height = 30
        self.assertEqual(r.height, 30)

    def test_x_setter(self):
        """Test x setter."""
        r = Rectangle(10, 20)
        r.x = 5
        self.assertEqual(r.x, 5)

    def test_y_setter(self):
        """Test y setter."""
        r = Rectangle(10, 20)
        r.y = 5
        self.assertEqual(r.y, 5)

    def test_private_attributes(self):
        """Test private attributes exist."""
        r = Rectangle(10, 20)
        self.assertTrue(hasattr(r, "_Rectangle__width"))
        self.assertTrue(hasattr(r, "_Rectangle__height"))
        self.assertTrue(hasattr(r, "_Rectangle__x"))
        self.assertTrue(hasattr(r, "_Rectangle__y"))


if __name__ == "__main__":
    unittest.main()
