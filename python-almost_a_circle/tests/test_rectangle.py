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

    def test_width_not_integer(self):
        """Test width must be an integer."""
        with self.assertRaisesRegex(
                TypeError, "width must be an integer"):
            Rectangle("10", 20)

    def test_height_not_integer(self):
        """Test height must be an integer."""
        with self.assertRaisesRegex(
                TypeError, "height must be an integer"):
            Rectangle(10, "20")

    def test_x_not_integer(self):
        """Test x must be an integer."""
        with self.assertRaisesRegex(
                TypeError, "x must be an integer"):
            Rectangle(10, 20, "3")

    def test_y_not_integer(self):
        """Test y must be an integer."""
        with self.assertRaisesRegex(
                TypeError, "y must be an integer"):
            Rectangle(10, 20, 3, "4")

    def test_width_zero(self):
        """Test width cannot be zero."""
        with self.assertRaisesRegex(
                ValueError, "width must be > 0"):
            Rectangle(0, 20)

    def test_height_zero(self):
        """Test height cannot be zero."""
        with self.assertRaisesRegex(
                ValueError, "height must be > 0"):
            Rectangle(10, 0)

    def test_width_negative(self):
        """Test width cannot be negative."""
        with self.assertRaisesRegex(
                ValueError, "width must be > 0"):
            Rectangle(-1, 20)

    def test_height_negative(self):
        """Test height cannot be negative."""
        with self.assertRaisesRegex(
                ValueError, "height must be > 0"):
            Rectangle(10, -1)

    def test_x_negative(self):
        """Test x cannot be negative."""
        with self.assertRaisesRegex(
                ValueError, "x must be >= 0"):
            Rectangle(10, 20, -1)

    def test_y_negative(self):
        """Test y cannot be negative."""
        with self.assertRaisesRegex(
                ValueError, "y must be >= 0"):
            Rectangle(10, 20, 0, -1)

    def test_width_setter_not_integer(self):
        """Test width setter validation."""
        r = Rectangle(10, 20)
        with self.assertRaisesRegex(
                TypeError, "width must be an integer"):
            r.width = "10"

    def test_height_setter_not_integer(self):
        """Test height setter validation."""
        r = Rectangle(10, 20)
        with self.assertRaisesRegex(
                TypeError, "height must be an integer"):
            r.height = "20"

    def test_x_setter_not_integer(self):
        """Test x setter validation."""
        r = Rectangle(10, 20)
        with self.assertRaisesRegex(
                TypeError, "x must be an integer"):
            r.x = "10"

    def test_y_setter_not_integer(self):
        """Test y setter validation."""
        r = Rectangle(10, 20)
        with self.assertRaisesRegex(
                TypeError, "y must be an integer"):
            r.y = "20"

    def test_width_setter_zero(self):
        """Test width setter rejects zero."""
        r = Rectangle(10, 20)
        with self.assertRaisesRegex(
                ValueError, "width must be > 0"):
            r.width = 0

    def test_height_setter_zero(self):
        """Test height setter rejects zero."""
        r = Rectangle(10, 20)
        with self.assertRaisesRegex(
                ValueError, "height must be > 0"):
            r.height = 0

    def test_x_setter_negative(self):
        """Test x setter rejects negative values."""
        r = Rectangle(10, 20)
        with self.assertRaisesRegex(
                ValueError, "x must be >= 0"):
            r.x = -1

    def test_y_setter_negative(self):
        """Test y setter rejects negative values."""
        r = Rectangle(10, 20)
        with self.assertRaisesRegex(
                ValueError, "y must be >= 0"):
            r.y = -1


if __name__ == "__main__":
    unittest.main()
