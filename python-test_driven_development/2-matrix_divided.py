#!/usr/bin/python3
"""Defines a function that divides all elements of a matrix."""


def matrix_divided(matrix, div):
    """Divide all elements of a matrix by div."""
    if not isinstance(matrix, list) or not matrix:
        raise TypeError(
            "matrix must be a matrix (list of lists) of integers/floats"
        )

    if not all(isinstance(row, list) for row in matrix):
        raise TypeError(
            "matrix must be a matrix (list of lists) of integers/floats"
        )

    if not all(row for row in matrix):
        raise TypeError(
            "matrix must be a matrix (list of lists) of integers/floats"
        )

    if not all(
        isinstance(element, (int, float)) and not isinstance(element, bool)
        for row in matrix
        for element in row
    ):
        raise TypeError(
            "matrix must be a matrix (list of lists) of integers/floats"
        )

    row_size = len(matrix[0])
    if not all(len(row) == row_size for row in matrix):
        raise TypeError(
            "Each row of the matrix must have the same size"
        )

    if not isinstance(div, (int, float)) or isinstance(div, bool):
        raise TypeError("div must be a number")

    if div == 0:
        raise ZeroDivisionError("division by zero")

    return [[round(element / div, 2) for element in row]
            for row in matrix]
