#!/usr/bin/python3
"""Defines a function that multiplies two matrices."""


def matrix_mul(m_a, m_b):
    """Multiply two matrices."""
    if type(m_a) is not list:
        raise TypeError("m_a must be a list")
    if type(m_b) is not list:
        raise TypeError("m_b must be a list")

    if type(m_a) is not list or any(type(row) is not list for row in m_a):
        raise TypeError("m_a must be a list of lists")
    if type(m_b) is not list or any(type(row) is not list for row in m_b):
        raise TypeError("m_b must be a list of lists")

    if len(m_a) == 0 or (len(m_a) > 0 and len(m_a[0]) == 0):
        raise ValueError("m_a can't be empty")
    if len(m_b) == 0 or (len(m_b) > 0 and len(m_b[0]) == 0):
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
            raise TypeError("each row of m_a must be of the same size")

    m_b_size = len(m_b[0])
    for row in m_b:
        if len(row) != m_b_size:
            raise TypeError("each row of m_b must be of the same size")

    if m_a_size != len(m_b):
        raise ValueError("m_a and m_b can't be multiplied")

    result = []
    for row_a in m_a:
        row_result = []
        for column in range(m_b_size):
            total = 0
            for row_b in range(len(m_b)):
                total += row_a[row_b] * m_b[row_b][column]
            row_result.append(total)
        result.append(row_result)

    return result
