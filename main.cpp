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

int main(int argc, char* argv[])
{
    Config config = get_config(argc, argv);
    if (config.option == ERROR)
    {
        usage(argv[0]);
        return 1;
    }

    srand(time(NULL));

    // Begin visual testing
    initscr();
    curs_set(0);
    start_color();
    init_pair(BLACK , COLOR_BLACK , COLOR_BLACK );
    init_pair(WHITE , COLOR_WHITE , COLOR_WHITE );
    init_pair(RED   , COLOR_RED   , COLOR_RED   );
    init_pair(YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(GREEN , COLOR_GREEN , COLOR_GREEN );
    init_pair(BLUE  , COLOR_BLUE  , COLOR_BLUE  );

    int x, y;
    getmaxyx(stdscr, y, x);

    refresh();

    Column columns[x];
    for (int i = 0; i < x; i++)
    {
        columns[i].setHeight(1 + (rand() % y));
        columns[i].setColor(WHITE);
    }

    test_column_printing(columns, x, y);
    switch (config.option)
    {
        case BUBBLE: // Test Bubble Sort
            mvprintw(0, 0, "Bubble Sort");
            refresh();
            getchar();
            bubble_sort(columns, x, y);
            mvprintw(0, 0, "Bubble Sort");
            break;

        case INSERTION: // Test Insertion Sort
            mvprintw(0, 0, "Insertion Sort");
            refresh();
            getchar();
            insertion_sort(columns, x, y);
            mvprintw(0, 0, "Insertion Sort");
            break;

        case SELECTION: // Test Selection Sort
            mvprintw(0, 0, "Selection Sort");
            refresh();
            getchar();
            selection_sort(columns, x, y);
            mvprintw(0, 0, "Selection Sort");
            break;

        case QUICK: // Test Quick Sort
            mvprintw(0, 0, "Quick Sort");
            refresh();
            getchar();
            quick_sort(columns, 0, x-1, y);
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
    printf("Usage: %s <sort type>\n", prgname);
    printf("SORTS\n");
    printf("\tbubble\n");
    printf("\tinsert\n");
    printf("\tselect\n");
    printf("\tquick\n");
}
