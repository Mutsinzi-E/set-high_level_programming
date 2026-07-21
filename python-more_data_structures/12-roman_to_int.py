#!/usr/bin/python3
"""Function that converts Roman numerals to integers."""


def roman_to_int(roman_string):
    """Convert a Roman numeral string to an integer."""
    if not isinstance(roman_string, str) or roman_string is None:
        return 0

    roman_values = {
        "I": 1,
        "V": 5,
        "X": 10,
        "L": 50,
        "C": 100,
        "D": 500,
        "M": 1000
    }

    total = 0
    previous = 0

    for char in roman_string[::-1]:
        value = roman_values[char]

        if value < previous:
            total -= value
        else:
            total += value
            previous = value

    return total
