#include "slide_line.h"

/**
 * slide_left - slides and merges a line to the left
 * @line: array
 * @size: size of array
 */
static void slide_left(int *line, size_t size)
{
    size_t i, k;

    /* shift non-zero values to the left */
    for (i = 0, k = 0; i < size; i++)
    {
        if (line[i] != 0)
            line[k++] = line[i];
    }
    while (k < size)
        line[k++] = 0;

    /* merge */
    for (i = 0; i + 1 < size; i++)
    {
        if (line[i] != 0 && line[i] == line[i + 1])
        {
            line[i] *= 2;
            line[i + 1] = 0;
        }
    }

    /* shift again */
    for (i = 0, k = 0; i < size; i++)
    {
        if (line[i] != 0)
            line[k++] = line[i];
    }
    while (k < size)
        line[k++] = 0;
}

/**
 * slide_right - slides and merges a line to the right
 * @line: array
 * @size: size of array
 */
static void slide_right(int *line, size_t size)
{
    int i;
    size_t k;

    /* shift non-zero values to the right */
    k = size;
    for (i = (int)size - 1; i >= 0; i--)
    {
        if (line[i] != 0)
            line[--k] = line[i];
    }
    while (k > 0)
        line[--k] = 0;

    /* merge */
    for (i = (int)size - 1; i > 0; i--)
    {
        if (line[i] != 0 && line[i] == line[i - 1])
        {
            line[i] *= 2;
            line[i - 1] = 0;
        }
    }

    /* shift again */
    k = size;
    for (i = (int)size - 1; i >= 0; i--)
    {
        if (line[i] != 0)
            line[--k] = line[i];
    }
    while (k > 0)
        line[--k] = 0;
}

/**
 * slide_line - slides and merges an array like 2048
 * @line: array of integers
 * @size: size of array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (!line || size == 0)
        return (0);

    if (direction == SLIDE_LEFT)
        slide_left(line, size);
    else if (direction == SLIDE_RIGHT)
        slide_right(line, size);
    else
        return (0);

    return (1);
}