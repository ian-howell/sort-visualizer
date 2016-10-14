#include <ncurses.h>
#include "column.h"

void Column::draw(int x, int y)
{
    int h = height;

    attron(COLOR_PAIR(color));

    // Start at the (x, y-h) location and draw downward
    while (h > 0)
    {
        mvprintw(y-h, x, "#");
        h--;
    }

    attroff(COLOR_PAIR(color));
}

bool operator < (const Column& c1, const Column& c2)
{
    return c1.height < c2.height;
}

bool operator > (const Column& c1, const Column& c2)
{
    return c1.height > c2.height;
}
