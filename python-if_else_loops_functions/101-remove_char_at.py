#!/usr/bin/python3
def remove_char_at(str, n):
    """Create a copy of a string without the character at index n."""
    if n < 0 or n >= len(str):
        return str

    return str[:n] + str[n + 1:]
