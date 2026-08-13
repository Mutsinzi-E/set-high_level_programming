#!/usr/bin/python3
"""Defines a function that prints text with 2 new lines after ., ? and :."""


def text_indentation(text):
    """Print text with 2 new lines after ., ? and :."""
    if type(text) is not str:
        raise TypeError("text must be a string")

    lines = []
    current = ""

    for char in text:
        if char in ".?:":
            current += char
            lines.append(current.strip())
            current = ""
        else:
            current += char

    if current.strip():
        lines.append(current.strip())

    for line in lines:
        print(line)
        if line[-1] in ".?:":
            print()
