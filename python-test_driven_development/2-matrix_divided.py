#!/usr/bin/python3
"""Divide all elements of a matrix."""


def matrix_divided(matrix, div):
    """Divide all elements of a matrix by div."""
    if (not isinstance(matrix, list) or not matrix
            or not all(isinstance(row, list) and row for row in matrix)):
        raise TypeError(
            "matrix must be a matrix (list of lists) of integers/floats"
        )

    if not all(
        all(isinstance(value, (int, float)) and not isinstance(value, bool)
            for value in row)
        for row in matrix
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

    if div == float('inf') or div == float('-inf'):
        return [[0.0 for value in row] for row in matrix]

    return [[round(value / div, 2) for value in row] for row in matrix]
