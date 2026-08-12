#!/usr/bin/python3
"""Defines a BaseGeometry class."""


class BaseGeometry:
    """Represents a base geometry."""

    def area(self):
        """Public method that raises an exception."""
        raise Exception("area() is not implemented")

    def integer_validator(self, name, value):
        """Validate that value is a positive integer."""
        if type(value) is not int:
            raise TypeError("{} must be an integer".format(name))
        if value <= 0:
            raise ValueError("{} must be greater than 0".format(name))
