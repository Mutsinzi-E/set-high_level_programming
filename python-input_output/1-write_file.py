#!/usr/bin/python3
"""Module for writing files."""


def write_file(filename="", text=""):
    """Write a string to a UTF-8 text file and return characters written."""
    with open(filename, mode="w", encoding="utf-8") as file:
        return file.write(text)
