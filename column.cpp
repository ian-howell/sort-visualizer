#include <ncurses.h>
#include "column.h"

void Column::draw(int x, int y)
{
    int h = height;

    attron(COLOR_PAIR(2));

    // Start at the (x, y-h) location and draw downward
    while (h > 0)
    {
        mvprintw(y-h, x, "#");
        h--;
    }

    attroff(COLOR_PAIR(2));
}
