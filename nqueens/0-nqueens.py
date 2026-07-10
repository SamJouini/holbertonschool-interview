#!/usr/bin/python3

import sys

if not len(sys.argv) == 2:
    print("Usage: nqueens N")
    sys.exit(1)

try:
    if isinstance(int(sys.argv[1]), int):
        n = int(sys.argv[1])
        if n < 4:
            print("N must be at least 4")
            sys.exit(1)

except (ValueError):
    print("N must be a number")
    sys.exit(1)


def is_safe(board, row, col):
    # Check against all previously placed queens
    for previous_row in range(row):
        previous_col = board[previous_row]

        # Check Column Conflict
        if previous_col == col:
            return False

        # Check Diagonal Conflict
        if abs(previous_row - row) == abs(previous_col - col):
            return False

    return True


def solve_nqueens(board, row, n, solutions):
    if row == n:
        solutions.append([[i, board[i]] for i in range(n)])
        return
    for col in range(n):
        if is_safe(board, row, col):
            board[row] = col
            solve_nqueens(board, row + 1, n, solutions)


board = [0] * n
solutions = []

solve_nqueens(board, 0, n, solutions)

for solution in solutions:
    print(solution)
