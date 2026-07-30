#!/usr/bin/python3
"""Defines a Rectangle class."""


class Rectangle:
    """Represents a rectangle."""

    def __init__(self, width=0, height=0):
        """Initialize a Rectangle."""
        self.width = width
        self.height = height

    @property
    def width(self):
        """Get the rectangle width."""
        return self.__width

    @width.setter
    def width(self, value):
        """Set the rectangle width."""
        if not isinstance(value, int):
            raise TypeError("width must be an integer")
        if value < 0:
            raise ValueError("width must be >= 0")
        self.__width = value

    @property
    def height(self):
        """Get the rectangle height."""
        return self.__height

    @height.setter
    def height(self, value):
        """Set the rectangle height."""
        if not isinstance(value, int):
            raise TypeError("height must be an integer")
        if value < 0:
            raise ValueError("height must be >= 0")
        self.__height = value

    def area(self):
        """Return the rectangle area."""
        return self.__width * self.__height

    def perimeter(self):
        """Return the rectangle perimeter."""
        if self.__width == 0 or self.__height == 0:
            return 0
        return 2 * (self.__width + self.__height)

    def __str__(self):
        """Return the rectangle drawn with #."""
        if self.__width == 0 or self.__height == 0:
            return ""

        rows = []
        for i in range(self.__height):
            rows.append("#" * self.__width)
        return "\n".join(rows)

    def __repr__(self):
        """Return a string representation for eval()."""
        return "Rectangle({}, {})".format(
            self.__width, self.__height
        )
