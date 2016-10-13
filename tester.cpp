#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <ncurses.h>
#include "column.h"
#include "sorts.h"
using namespace std;

int main()
{
    const int SIZE = 10;
    srand(time(NULL));

    // Test quicksort with integers
    cout << "INTS" << endl;

    int a[SIZE];

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

    // Test quicksort with doubles
    cout << "DOUBLES" << endl;
    double b[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        b[i] = (rand() % 100) / 2.0;
        cout << b[i] << " ";
    }
    cout << endl;

    quick_sort(a, 0, SIZE-1);

    for (int i = 0; i < SIZE; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    initscr();
    getchar();
    clear();

    int x, y;
    getmaxyx(stdscr, y, x);

    printw("%d === %d\n", x, y);
    refresh();
    getchar();

    Column* columns[y];
    for (int i = 0; i < y; i++)
    {
        columns[i] = new Column(i);
        columns[i]->draw(i, y);
        refresh();
        getchar();
    }

    getchar();
    endwin();

    return 0;
}
