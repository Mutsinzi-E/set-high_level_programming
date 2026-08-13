#!/usr/bin/python3
"""Defines a function that prints text with 2 new lines after ., ? and :."""


def text_indentation(text):
    """Print text with 2 new lines after ., ? and :."""
    if type(text) is not str:
        raise TypeError("text must be a string")

    new_line = True

    for char in text:
        if char in ".?:":
            print(char)
            print()
            new_line = True
        elif char == " " and new_line:
            continue
        else:
            print(char, end="")
            new_line = False
