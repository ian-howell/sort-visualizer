#ifndef HELPERS_H
#define HELPERS_H

#define SECOND 1000000

enum Color
{
    BLACK,
    WHITE,
    RED,
    YELLOW,
    GREEN,
};

enum Option
{
    BUBBLE,
    INSERTION,
    SELECTION,
    QUICK,
};

/* swap
 * Swaps 2 values
 *
 * example: swap(a, b)
 */
template <typename T>
void swap(T& x, T& y);

#include "helpers.hpp"

#endif
