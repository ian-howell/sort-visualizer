#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <ncurses.h>
#include "sorts.h"
using namespace std;

int main()
{
    const int SIZE = 10;
    int a[SIZE];

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl;

    quick_sort(a, 0, SIZE-1);

    for (int i = 0; i < SIZE; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    initscr();
    clear();

    int x, y;
    getmaxyx(stdscr, y, x);

    for (int i = y; i >= 0; i--)
    {
        mvprintw(i, 0, "M");
        refresh();
        usleep(1000000);
    }
    endwin();

    return 0;
}
