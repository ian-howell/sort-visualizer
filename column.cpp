#include <ncurses.h>
#include "column.h"

void Column::draw(int x, int y)
{
    int h = height;

    // Start at the (x, y-h) location and draw downward
    while (h > 0)
    {
        mvprintw(y-h, x, "#");
        h--;
    }
}
