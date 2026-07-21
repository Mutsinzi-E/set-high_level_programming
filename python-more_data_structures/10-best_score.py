#!/usr/bin/python3
"""Function that returns the key with the biggest integer value."""


def best_score(a_dictionary):
    """Return the key with the highest value in a dictionary."""
    if not a_dictionary:
        return None

    best_key = None
    best_value = None

    for key, value in a_dictionary.items():
        if best_value is None or value > best_value:
            best_value = value
            best_key = key

    return best_key
