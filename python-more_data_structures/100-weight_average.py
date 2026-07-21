#!/usr/bin/python3
"""Function that returns the weighted average of integers tuples."""


def weight_average(my_list=[]):
    """Return the weighted average of scores and weights."""
    if not my_list:
        return 0

    total_score = 0
    total_weight = 0

    for score, weight in my_list:
        total_score += score * weight
        total_weight += weight

    return total_score / total_weight
