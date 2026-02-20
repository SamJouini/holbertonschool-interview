#!/usr/bin/python3
"""
Module that defines a function to calculate the minimum number
of operations needed to result in exactly n H characters in a file.
Only two operations are allowed: Copy All and Paste.
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to obtain
    exactly n H characters starting from one H.

    Args:
        n (int): The target number of H characters.

    Returns:
        int: The minimum number of operations required.
             Returns 0 if n is impossible to achieve.
    """
    if n <= 1:
        return 0

    operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1
