#!/usr/bin/python3
"""Module that defines BaseGeometry."""


class BaseGeometry:
    """Base class for geometry objects."""

    def area(self):
        """Raise an exception because area is not implemented."""
        raise Exception("area() is not implemented")
