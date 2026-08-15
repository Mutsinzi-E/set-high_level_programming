#!/usr/bin/python3
"""Tests for Rectangle."""
import io
import os
import unittest
from contextlib import redirect_stdout

from models.rectangle import Rectangle


class TestRectangle(unittest.TestCase):
    """Test Rectangle."""

    def test_rectangle_1_2(self):
        """Test Rectangle(1, 2)."""
        r = Rectangle(1, 2)
        self.assertEqual(r.width, 1)
        self.assertEqual(r.height, 2)

    def test_rectangle_with_id(self):
        """Test Rectangle(1, 2, 3)."""
        r = Rectangle(1, 2, 3)
        self.assertEqual(r.x, 3)

    def test_rectangle_with_x_y(self):
        """Test Rectangle(1, 2, 3, 4)."""
        r = Rectangle(1, 2, 3, 4)
        self.assertEqual(r.x, 3)
        self.assertEqual(r.y, 4)

    def test_width_string(self):
        """Test string width."""
        with self.assertRaises(TypeError):
            Rectangle("1", 2)

    def test_height_string(self):
        """Test string height."""
        with self.assertRaises(TypeError):
            Rectangle(1, "2")

    def test_x_string(self):
        """Test string x."""
        with self.assertRaises(TypeError):
            Rectangle(1, 2, "3")

    def test_y_string(self):
        """Test string y."""
        with self.assertRaises(TypeError):
            Rectangle(1, 2, 3, "4")

    def test_rectangle_with_id(self):
        """Test Rectangle with id."""
        r = Rectangle(1, 2, 3, 4, 5)
        self.assertEqual(r.id, 5)

    def test_negative_width(self):
        """Test negative width."""
        with self.assertRaises(ValueError):
            Rectangle(-1, 2)

    def test_negative_height(self):
        """Test negative height."""
        with self.assertRaises(ValueError):
            Rectangle(1, -2)

    def test_zero_width(self):
        """Test zero width."""
        with self.assertRaises(ValueError):
            Rectangle(0, 2)

    def test_zero_height(self):
        """Test zero height."""
        with self.assertRaises(ValueError):
            Rectangle(1, 0)

    def test_negative_x(self):
        """Test negative x."""
        with self.assertRaises(ValueError):
            Rectangle(1, 2, -3)

    def test_negative_y(self):
        """Test negative y."""
        with self.assertRaises(ValueError):
            Rectangle(1, 2, 3, -4)

    def test_area(self):
        """Test area."""
        self.assertEqual(Rectangle(3, 2).area(), 6)

    def test_str(self):
        """Test __str__."""
        self.assertEqual(
            str(Rectangle(4, 6, 2, 1, 12)),
            "[Rectangle] (12) 2/1 - 4/6"
        )

    def test_display_no_xy(self):
        """Test display without x and y."""
        output = io.StringIO()
        with redirect_stdout(output):
            Rectangle(2, 2).display()
        self.assertEqual(output.getvalue(), "##\n##\n")

    def test_display_without_x(self):
        """Test display with y."""
        output = io.StringIO()
        with redirect_stdout(output):
            Rectangle(2, 2, 0, 1).display()
        self.assertEqual(output.getvalue(), "\n##\n##\n")

    def test_display(self):
        """Test display with x and y."""
        output = io.StringIO()
        with redirect_stdout(output):
            Rectangle(2, 2, 1, 1).display()
        self.assertEqual(output.getvalue(), "\n ##\n ##\n")

    def test_to_dictionary(self):
        """Test to_dictionary."""
        r = Rectangle(10, 2, 1, 9, 89)
        self.assertEqual(
            r.to_dictionary(),
            {"id": 89, "width": 10, "height": 2, "x": 1, "y": 9}
        )

    def test_update_89(self):
        """Test update(89)."""
        r = Rectangle(1, 2)
        r.update(89)
        self.assertEqual(r.id, 89)

    def test_update_89_1(self):
        """Test update(89, 1)."""
        r = Rectangle(1, 2)
        r.update(89, 1)
        self.assertEqual((r.id, r.width), (89, 1))

    def test_update_89_1_2(self):
        """Test update(89, 1, 2)."""
        r = Rectangle(1, 2)
        r.update(89, 1, 2)
        self.assertEqual((r.id, r.width, r.height), (89, 1, 2))

    def test_update_89_1_2_3(self):
        """Test update(89, 1, 2, 3)."""
        r = Rectangle(1, 2)
        r.update(89, 1, 2, 3)
        self.assertEqual((r.id, r.width, r.height, r.x), (89, 1, 2, 3))

    def test_update_89_1_2_3_4(self):
        """Test update(89, 1, 2, 3, 4)."""
        r = Rectangle(1, 2)
        r.update(89, 1, 2, 3, 4)
        self.assertEqual(
            (r.id, r.width, r.height, r.x, r.y),
            (89, 1, 2, 3, 4)
        )

    def test_update_kwargs_id(self):
        """Test update with id."""
        r = Rectangle(1, 2)
        r.update(id=89)
        self.assertEqual(r.id, 89)

    def test_update_kwargs_width(self):
        """Test update with id and width."""
        r = Rectangle(1, 2)
        r.update(id=89, width=1)
        self.assertEqual((r.id, r.width), (89, 1))

    def test_update_kwargs_height(self):
        """Test update with id, width and height."""
        r = Rectangle(1, 2)
        r.update(id=89, width=1, height=2)
        self.assertEqual((r.id, r.width, r.height), (89, 1, 2))

    def test_update_kwargs_x(self):
        """Test update through x."""
        r = Rectangle(1, 2)
        r.update(id=89, width=1, height=2, x=3)
        self.assertEqual((r.id, r.width, r.height, r.x), (89, 1, 2, 3))

    def test_update_kwargs_y(self):
        """Test update through y."""
        r = Rectangle(1, 2)
        r.update(id=89, width=1, height=2, x=3, y=4)
        self.assertEqual(
            (r.id, r.width, r.height, r.x, r.y),
            (89, 1, 2, 3, 4)
        )

    def test_create_id(self):
        """Test create with id."""
        r = Rectangle.create(id=89)
        self.assertEqual(r.id, 89)

    def test_create_width(self):
        """Test create with id and width."""
        r = Rectangle.create(id=89, width=1)
        self.assertEqual((r.id, r.width), (89, 1))

    def test_create_height(self):
        """Test create with height."""
        r = Rectangle.create(id=89, width=1, height=2)
        self.assertEqual((r.id, r.width, r.height), (89, 1, 2))

    def test_create_x(self):
        """Test create with x."""
        r = Rectangle.create(id=89, width=1, height=2, x=3)
        self.assertEqual((r.id, r.width, r.height, r.x), (89, 1, 2, 3))

    def test_create_y(self):
        """Test create with y."""
        r = Rectangle.create(id=89, width=1, height=2, x=3, y=4)
        self.assertEqual(
            (r.id, r.width, r.height, r.x, r.y),
            (89, 1, 2, 3, 4)
        )

    def test_save_none(self):
        """Test save_to_file(None)."""
        Rectangle.save_to_file(None)
        self.assertTrue(os.path.exists("Rectangle.json"))

    def test_save_empty(self):
        """Test save_to_file([])."""
        Rectangle.save_to_file([])
        self.assertTrue(os.path.exists("Rectangle.json"))

    def test_save_rectangle(self):
        """Test save_to_file with a Rectangle."""
        r = Rectangle(1, 2, 3, 4, 5)
        Rectangle.save_to_file([r])
        self.assertTrue(os.path.exists("Rectangle.json"))

    def test_load_missing(self):
        """Test load_from_file when file does not exist."""
        if os.path.exists("Rectangle.json"):
            os.remove("Rectangle.json")
        self.assertEqual(Rectangle.load_from_file(), [])

    def test_load_existing(self):
        """Test load_from_file when file exists."""
        r = Rectangle(1, 2, 3, 4, 5)
        Rectangle.save_to_file([r])
        loaded = Rectangle.load_from_file()
        self.assertEqual(len(loaded), 1)
        self.assertEqual(loaded[0].to_dictionary(), r.to_dictionary())

    @classmethod
    def tearDownClass(cls):
        """Remove generated JSON."""
        if os.path.exists("Rectangle.json"):
            os.remove("Rectangle.json")


if __name__ == "__main__":
    unittest.main()
