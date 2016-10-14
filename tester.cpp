#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <ncurses.h>
#include "column.h"
#include "sorts.h"
using namespace std;

const int SIZE = 10;

enum
{
    BLACK,
    WHITE,
    RED,
};

void test_qsort_ints();
void test_qsort_doubles();
void test_column_comparison();
void test_column_printing(Column columns[], int x, int y);

int main()
{
    srand(time(NULL));

    // Test quicksort with integers
    test_qsort_ints();

    // Test quicksort with doubles
    test_qsort_doubles();

    // Test column comparison
    test_column_comparison();

    // Begin visual testing
    initscr();
    start_color();
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(RED  , COLOR_RED  , COLOR_RED  );
    getchar();
    clear();

    int x, y;
    getmaxyx(stdscr, y, x);

    refresh();

    Column columns[x];
    for (int i = 0; i < x; i++)
        columns[i].setHeight(rand() % y);

    // Test printing unsorted columns
    test_column_printing(columns, x, y);

    clear();

    // Test sorting columns
    quick_sort(columns, 0, x);
    test_column_printing(columns, x, y);

    getchar();
    endwin();

    return 0;
}

void test_qsort_ints()
{
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
    return;
}

void test_qsort_doubles()
{
    cout << "DOUBLES" << endl;
    double b[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        b[i] = (rand() % 100) / 2.0;
        cout << b[i] << " ";
    }
    cout << endl;

    quick_sort(b, 0, SIZE-1);

    for (int i = 0; i < SIZE; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}

void test_column_comparison()
{
    Column* c1 = new Column(5);
    Column* c2 = new Column(10);

    if (c1 > c2)
        cout << "c1 is > c2" << endl;
    else if (c1 < c2)
        cout << "c1 is < c2" << endl;
    delete c1;
    delete c2;
}

void test_column_printing(Column columns[], int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        columns[i].draw(i, y, RED);
        refresh();
        getchar();
    }
}

