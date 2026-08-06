#!/usr/bin/python3
"""Module for converting class instances to dictionaries."""


def class_to_json(obj):
    """Return the dictionary description of an object."""
    return obj.__dict__
