#!/usr/bin/python3
"""Defines the Base class."""

import json


class Base:
    """Base class for all other classes."""

    __nb_objects = 0

    def __init__(self, id=None):
        """Initialize a Base instance."""
        if id is not None:
            self.id = id
        else:
            Base.__nb_objects += 1
            self.id = Base.__nb_objects

    @staticmethod
    def to_json_string(list_dictionaries):
        """Return the JSON string representation of a list of dictionaries."""
        if list_dictionaries is None or len(list_dictionaries) == 0:
            return "[]"
        return json.dumps(list_dictionaries)

    @classmethod
    def save_to_file(cls, list_objs):
        """Write the JSON representation of objects to a file."""
        if list_objs is None:
            list_objs = []

        list_dictionaries = [obj.to_dictionary() for obj in list_objs]

        filename = cls.__name__ + ".json"

        with open(filename, "w") as file:
            file.write(cls.to_json_string(list_dictionaries))
