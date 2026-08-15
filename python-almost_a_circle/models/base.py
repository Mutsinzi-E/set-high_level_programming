#!/usr/bin/python3
"""Defines the Base class."""


class Base:
    """Represents the base class for the project."""

    __nb_objects = 0

    def __init__(self, id=None):
        """Initialize a Base instance."""
        if id is not None:
            self.id = id
        else:
            Base.__nb_objects += 1
            self.id = Base.__nb_objects
