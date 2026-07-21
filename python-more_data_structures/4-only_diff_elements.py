#!/usr/bin/python3
"""Function that returns elements present in only one set."""


def only_diff_elements(set_1, set_2):
    """Return elements that are in only one of the two sets."""
    return set_1 ^ set_2
