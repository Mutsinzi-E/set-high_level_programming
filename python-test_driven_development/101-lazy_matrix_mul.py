#!/usr/bin/python3
"""Module for multiplying two matrices using NumPy."""

import numpy as np


def lazy_matrix_mul(m_a, m_b):
    """Multiply two matrices using NumPy."""
    if type(m_a) is not list:
        raise TypeError("m_a must be a list")
    if type(m_b) is not list:
        raise TypeError("m_b must be a list")

    if any(type(row) is not list for row in m_a):
        raise TypeError("m_a must be a list of lists")
    if any(type(row) is not list for row in m_b):
        raise TypeError("m_b must be a list of lists")

    if len(m_a) == 0 or len(m_a[0]) == 0:
        raise ValueError("m_a can't be empty")
    if len(m_b) == 0 or len(m_b[0]) == 0:
        raise ValueError("m_b can't be empty")

    for row in m_a:
        for value in row:
            if type(value) not in (int, float):
                raise TypeError(
                    "m_a should contain only integers or floats"
                )

    for row in m_b:
        for value in row:
            if type(value) not in (int, float):
                raise TypeError(
                    "m_b should contain only integers or floats"
                )

    m_a_size = len(m_a[0])
    for row in m_a:
        if len(row) != m_a_size:
            raise TypeError(
                "each row of m_a must should be of the same size"
            )

    m_b_size = len(m_b[0])
    for row in m_b:
        if len(row) != m_b_size:
            raise TypeError(
                "each row of m_b must should be of the same size"
            )

    if m_a_size != len(m_b):
        raise ValueError("m_a and m_b can't be multiplied")

    return np.matmul(m_a, m_b)
