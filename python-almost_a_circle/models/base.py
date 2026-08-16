#!/usr/bin/python3
"""Defines the Base class."""

import json
import csv


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
        """Return the JSON string representation of list_dictionaries."""
        if list_dictionaries is None or len(list_dictionaries) == 0:
            return "[]"
        return json.dumps(list_dictionaries)

    @classmethod
    def save_to_file(cls, list_objs):
        """Write the JSON string representation of list_objs to a file."""
        filename = cls.__name__ + ".json"

        if list_objs is None:
            list_objs = []

        list_dictionaries = [obj.to_dictionary() for obj in list_objs]

        with open(filename, "w") as file:
            file.write(cls.to_json_string(list_dictionaries))

    @staticmethod
    def from_json_string(json_string):
        """Return the list represented by the JSON string."""
        if json_string is None or json_string == "":
            return []
        return json.loads(json_string)

    @classmethod
    def create(cls, **dictionary):
        """Return an instance with attributes already set."""
        if cls.__name__ == "Rectangle":
            dummy = cls(1, 1)
        elif cls.__name__ == "Square":
            dummy = cls(1)
        else:
            dummy = cls()

        dummy.update(**dictionary)
        return dummy

    @classmethod
    def load_from_file(cls):
        """Return a list of instances from a JSON file."""
        filename = cls.__name__ + ".json"

        try:
            with open(filename, "r") as file:
                json_string = file.read()
        except FileNotFoundError:
            return []

        list_dictionaries = cls.from_json_string(json_string)

        return [cls.create(**dictionary)
                for dictionary in list_dictionaries]

    @classmethod
    def save_to_file_csv(cls, list_objs):
        """Serialize objects to CSV."""
        filename = cls.__name__ + ".csv"

        with open(filename, "w", newline="") as file:
            writer = csv.writer(file)

            if list_objs is None:
                return

            for obj in list_objs:
                if cls.__name__ == "Rectangle":
                    writer.writerow([
                        obj.id,
                        obj.width,
                        obj.height,
                        obj.x,
                        obj.y
                    ])
                elif cls.__name__ == "Square":
                    writer.writerow([
                        obj.id,
                        obj.size,
                        obj.x,
                        obj.y
                    ])

    @classmethod
    def load_from_file_csv(cls):
        """Deserialize objects from CSV."""
        filename = cls.__name__ + ".csv"

        try:
            with open(filename, "r", newline="") as file:
                reader = csv.reader(file)
                instances = []

                for row in reader:
                    if cls.__name__ == "Rectangle":
                        dictionary = {
                            "id": int(row[0]),
                            "width": int(row[1]),
                            "height": int(row[2]),
                            "x": int(row[3]),
                            "y": int(row[4])
                        }
                    elif cls.__name__ == "Square":
                        dictionary = {
                            "id": int(row[0]),
                            "size": int(row[1]),
                            "x": int(row[2]),
                            "y": int(row[3])
                        }

                    instances.append(cls.create(**dictionary))

                return instances

        except FileNotFoundError:
            return []

    @staticmethod
    def draw(list_rectangles, list_squares):
        """Open a window and draw all rectangles and squares."""
        import turtle

        screen = turtle.Screen()
        screen.title("Almost a Circle - Rectangles and Squares")

        pen = turtle.Turtle()
        pen.speed(0)

        def draw_shape(shape):
            pen.penup()
            pen.goto(shape.x, -shape.y)
            pen.pendown()

            pen.forward(shape.width)
            pen.right(90)
            pen.forward(shape.height)
            pen.right(90)
            pen.forward(shape.width)
            pen.right(90)
            pen.forward(shape.height)
            pen.right(90)

        for rectangle in list_rectangles:
            draw_shape(rectangle)

        for square in list_squares:
            draw_shape(square)

        screen.mainloop()
