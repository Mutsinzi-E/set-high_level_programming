#!/usr/bin/python3
def square_matrix_simple(matrix=[]):
    """Returns a new matrix with all values squared."""
    return [[element ** 2 for element in row] for row in matrix]
