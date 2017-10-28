#ifndef HELPERS_H
#define HELPERS_H

#define SECOND 1000000.0

enum Color
{
    BLACK,
    WHITE,
    RED,
    YELLOW,
    GREEN,
    BLUE,
};

enum Option
{
    BUBBLE,
    INSERTION,
    SELECTION,
    QUICK,
    ERROR,
};

struct Config
{
    Option option;
    int fps;
};

/* swap
 * Swaps 2 values
 *
 * example: swap(a, b)
 */
template <typename T>
void swap(T& x, T& y);

Config get_config(const int argc, char** argv);

#include "helpers.hpp"

#endif
