#!/usr/bin/python3
"""
Function to determe if all lockboxes can be opened.
"""


def canUnlockAll(boxes):
    """
    Determines if all the boxes can be opened.

    Args:
        boxes (list of lists): Each index represents a box, and the inner
        lists contain keys to other boxes.

    Returns:
        boolean: True if all boxes can be opened, False otherwise.
    """
    if not boxes or not isinstance(boxes, list):
        return False

    n = len(boxes)
    # Keep track of boxes that have been opened
    opened = set([0])
    # Start with the first box
    keys = [0]

    while keys:
        box = keys.pop()

        for key in boxes[box]:
            # Only consider valid box numbers
            if key < n and key not in opened:
                opened.add(key)
                keys.append(key)
                
    # If all boxes are in the opened set, return True
    return len(opened) == n
