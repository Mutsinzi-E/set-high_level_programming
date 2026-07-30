#!/usr/bin/python3
"""Solve the N queens problem."""

import sys


def is_safe(board, row, col):
    """Check if a queen can be placed."""
    for r in range(row):
        c = board[r]

        if c == col:
            return False

        if abs(c - col) == abs(r - row):
            return False

    return True


def solve(board, row, n):
    """Backtracking solution."""
    if row == n:
        solution = []
        for r in range(n):
            solution.append([r, board[r]])
        print(solution)
        return

    for col in range(n):
        if is_safe(board, row, col):
            board[row] = col
            solve(board, row + 1, n)


if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [0] * n
    solve(board, 0, n)
