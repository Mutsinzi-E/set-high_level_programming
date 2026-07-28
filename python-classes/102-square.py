#!/usr/bin/python3
"""Defines a Square class."""


class Square:
    """Represents a square."""

    def __init__(self, size=0):
        """Initialize a square."""
        self.size = size

    @property
    def size(self):
        """Retrieve the size of the square."""
        return self.__size

    @size.setter
    def size(self, value):
        """Set the size of the square."""
        if not isinstance(value, (int, float)):
            raise TypeError("size must be a number")

        if value < 0:
            raise ValueError("size must be >= 0")

        self.__size = value

    def area(self):
        """Return the current square area."""
        return self.__size ** 2

    def __lt__(self, other):
        """Less than comparison based on area."""
        return self.area() < other.area()

    def __le__(self, other):
        """Less than or equal comparison based on area."""
        return self.area() <= other.area()

    def __eq__(self, other):
        """Equal comparison based on area."""
        return self.area() == other.area()

    def __ne__(self, other):
        """Not equal comparison based on area."""
        return self.area() != other.area()

    def __gt__(self, other):
        """Greater than comparison based on area."""
        return self.area() > other.area()

    def __ge__(self, other):
        """Greater than or equal comparison based on area."""
        return self.area() >= other.area()
