#!/usr/bin/python3
"""Tests for Square."""
import os
import unittest

from models.square import Square


class TestSquare(unittest.TestCase):
    """Test Square."""

    def test_square_1(self):
        """Test Square(1)."""
        s = Square(1)
        self.assertEqual(s.size, 1)

    def test_square_1_2(self):
        """Test Square(1, 2)."""
        s = Square(1, 2)
        self.assertEqual(s.x, 2)

    def test_square_1_2_3(self):
        """Test Square(1, 2, 3)."""
        s = Square(1, 2, 3)
        self.assertEqual((s.x, s.y), (2, 3))

    def test_square_strings(self):
        """Test string size."""
        with self.assertRaises(TypeError):
            Square("1")

    def test_square_string_x(self):
        """Test string x."""
        with self.assertRaises(TypeError):
            Square(1, "2")

    def test_square_string_y(self):
        """Test string y."""
        with self.assertRaises(TypeError):
            Square(1, 2, "3")

    def test_square_with_id(self):
        """Test Square with id."""
        s = Square(1, 2, 3, 4)
        self.assertEqual(s.id, 4)

    def test_square_negative_size(self):
        """Test negative size."""
        with self.assertRaises(ValueError):
            Square(-1)

    def test_square_negative_x(self):
        """Test negative x."""
        with self.assertRaises(ValueError):
            Square(1, -2)

    def test_square_negative_y(self):
        """Test negative y."""
        with self.assertRaises(ValueError):
            Square(1, 2, -3)

    def test_square_zero(self):
        """Test zero size."""
        with self.assertRaises(ValueError):
            Square(0)

    def test_str(self):
        """Test Square __str__."""
        self.assertEqual(
            str(Square(5, 1, 2, 89)),
            "[Square] (89) 1/2 - 5"
        )

    def test_to_dictionary(self):
        """Test Square to_dictionary."""
        s = Square(10, 1, 9, 89)
        self.assertEqual(
            s.to_dictionary(),
            {"id": 89, "size": 10, "x": 1, "y": 9}
        )

    def test_update_89(self):
        """Test update(89)."""
        s = Square(1)
        s.update(89)
        self.assertEqual(s.id, 89)

    def test_update_89_1(self):
        """Test update(89, 1)."""
        s = Square(1)
        s.update(89, 1)
        self.assertEqual((s.id, s.size), (89, 1))

    def test_update_89_1_2(self):
        """Test update(89, 1, 2)."""
        s = Square(1)
        s.update(89, 1, 2)
        self.assertEqual((s.id, s.size, s.x), (89, 1, 2))

    def test_update_89_1_2_3(self):
        """Test update(89, 1, 2, 3)."""
        s = Square(1)
        s.update(89, 1, 2, 3)
        self.assertEqual(
            (s.id, s.size, s.x, s.y),
            (89, 1, 2, 3)
        )

    def test_update_kwargs_id(self):
        """Test update with id."""
        s = Square(1)
        s.update(id=89)
        self.assertEqual(s.id, 89)

    def test_update_kwargs_size(self):
        """Test update with size."""
        s = Square(1)
        s.update(id=89, size=1)
        self.assertEqual((s.id, s.size), (89, 1))

    def test_update_kwargs_x(self):
        """Test update with x."""
        s = Square(1)
        s.update(id=89, size=1, x=2)
        self.assertEqual((s.id, s.size, s.x), (89, 1, 2))

    def test_update_kwargs_y(self):
        """Test update with y."""
        s = Square(1)
        s.update(id=89, size=1, x=2, y=3)
        self.assertEqual(
            (s.id, s.size, s.x, s.y),
            (89, 1, 2, 3)
        )

    def test_create_id(self):
        """Test Square.create with id."""
        s = Square.create(id=89)
        self.assertEqual(s.id, 89)

    def test_create_size(self):
        """Test Square.create with size."""
        s = Square.create(id=89, size=1)
        self.assertEqual((s.id, s.size), (89, 1))

    def test_create_x(self):
        """Test Square.create with x."""
        s = Square.create(id=89, size=1, x=2)
        self.assertEqual((s.id, s.size, s.x), (89, 1, 2))

    def test_create_y(self):
        """Test Square.create with y."""
        s = Square.create(id=89, size=1, x=2, y=3)
        self.assertEqual(
            (s.id, s.size, s.x, s.y),
            (89, 1, 2, 3)
        )

    def test_save_none(self):
        """Test save_to_file(None)."""
        Square.save_to_file(None)
        self.assertTrue(os.path.exists("Square.json"))

    def test_save_empty(self):
        """Test save_to_file([])."""
        Square.save_to_file([])
        self.assertTrue(os.path.exists("Square.json"))

    def test_save_square(self):
        """Test save_to_file with Square."""
        s = Square(1, 2, 3, 4)
        Square.save_to_file([s])
        self.assertTrue(os.path.exists("Square.json"))

    def test_load_missing(self):
        """Test load_from_file when file does not exist."""
        if os.path.exists("Square.json"):
            os.remove("Square.json")
        self.assertEqual(Square.load_from_file(), [])

    def test_load_existing(self):
        """Test load_from_file when file exists."""
        s = Square(1, 2, 3, 4)
        Square.save_to_file([s])
        loaded = Square.load_from_file()
        self.assertEqual(len(loaded), 1)
        self.assertEqual(loaded[0].to_dictionary(), s.to_dictionary())

    @classmethod
    def tearDownClass(cls):
        """Remove generated JSON."""
        if os.path.exists("Square.json"):
            os.remove("Square.json")


if __name__ == "__main__":
    unittest.main()
