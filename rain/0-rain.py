#!/usr/bin/python3
"""Rainwater retention calculator"""


def rain(walls):
    """Return the total units of rainwater retained between walls.

    Args:
        walls: list of non-negative integers (wall heights, width 1).

    Returns:
        Integer amount of water retained.
    """
    if not walls:
        return 0

    left, right = 0, len(walls) - 1
    left_max, right_max = walls[left], walls[right]
    total = 0

    while left < right:
        if left_max <= right_max:
            left += 1
            left_max = max(left_max, walls[left])
            total += left_max - walls[left]
        else:
            right -= 1
            right_max = max(right_max, walls[right])
            total += right_max - walls[right]

    return total
