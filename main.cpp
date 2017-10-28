#include <cstdlib>
#include <ctime>
#include <getopt.h>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>

#include "column.h"
#include "helpers.h"
#include "sorts.h"

using namespace std;

void usage(const char* prgname);

void init_curses();

int main(int argc, char* argv[])
{
    // Get configuration from command line
    Config config = get_config(argc, argv);
    if ((config.option == ERROR) || (config.fps < 1) || (config.fps > 60))
    {
        usage(argv[0]);
        return 1;
    }

    srand(time(NULL));

    init_curses();

    int x, y;
    getmaxyx(stdscr, y, x);

    refresh();

    Column columns[x];
    for (int i = 0; i < x; i++)
    {
        columns[i].setHeight(1 + (rand() % y));
        columns[i].setColor(WHITE);
    }

    draw_columns(columns, x, y);
    switch (config.option)
    {
        case BUBBLE: // Test Bubble Sort
            mvprintw(0, 0, "Bubble Sort");
            refresh();
            getchar();
            bubble_sort(columns, x, y, config.fps);
            mvprintw(0, 0, "Bubble Sort");
            break;

        case INSERTION: // Test Insertion Sort
            mvprintw(0, 0, "Insertion Sort");
            refresh();
            getchar();
            insertion_sort(columns, x, y, config.fps);
            mvprintw(0, 0, "Insertion Sort");
            break;

        case SELECTION: // Test Selection Sort
            mvprintw(0, 0, "Selection Sort");
            refresh();
            getchar();
            selection_sort(columns, x, y, config.fps);
            mvprintw(0, 0, "Selection Sort");
            break;

        case QUICK: // Test Quick Sort
            mvprintw(0, 0, "Quick Sort");
            refresh();
            getchar();
            quick_sort(columns, 0, x-1, y, config.fps);
            mvprintw(0, 0, "Quick Sort");
            break;

        default:
            break;
    }

    mvprintw(1, 0, "Done!");
    mvprintw(2, 0, "Press any key to exit...");
    refresh();
    getchar();
    clear();
    endwin();

    return 0;
}

void usage(const char* prgname)
{
    printf("Usage: %s --algorthim=<sort_type> --speed=<fps>\n", prgname);
    printf("SORTS\n");
    printf("\tbubble\n");
    printf("\tinsert\n");
    printf("\tselect\n");
    printf("\tquick\n");
    printf("\n");
    printf("<fps> must be in the range [1...60]\n");
}

void init_curses()
{
    // Set up ncurses
    initscr();

    // Hide the curser
    curs_set(0);

    // Set up colors
    start_color();
    init_pair(BLACK , COLOR_BLACK , COLOR_BLACK );
    init_pair(WHITE , COLOR_WHITE , COLOR_WHITE );
    init_pair(RED   , COLOR_RED   , COLOR_RED   );
    init_pair(YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(GREEN , COLOR_GREEN , COLOR_GREEN );
    init_pair(BLUE  , COLOR_BLUE  , COLOR_BLUE  );
}
