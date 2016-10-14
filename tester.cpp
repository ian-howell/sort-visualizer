#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <ncurses.h>
#include "column.h"
#include "sorts.h"


using namespace std;

const int SIZE = 10;

void test_qsort_ints();
void test_qsort_doubles();
void test_column_comparison();
/* void test_column_printing(Column columns[], int x, int y); */

int main()
{
    srand(time(NULL));

    // Test quicksort with integers
    /* test_qsort_ints(); */

    // Test quicksort with doubles
    /* test_qsort_doubles(); */

    // Test column comparison
    /* test_column_comparison(); */

    // Begin visual testing
    initscr();
    start_color();
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(RED  , COLOR_RED  , COLOR_RED  );

    int x, y;
    getmaxyx(stdscr, y, x);

    refresh();

    Column columns[x];

    // Test Bubble Sort
    for (int i = 0; i < x; i++)
    {
        columns[i].setHeight(1 + (rand() % y));
        if (i%2)
            columns[i].setColor(WHITE);
        else
            columns[i].setColor(RED);
    }

    test_column_printing(columns, x, y);
    mvprintw(0, 0, "Bubble Sort");
    refresh();
    getchar();
    bubble_sort(columns, x, y);
    getchar();
    clear();

    // Test Insertion Sort
    for (int i = 0; i < x; i++)
    {
        columns[i].setHeight(1 + (rand() % y));
        if (i%2)
            columns[i].setColor(WHITE);
        else
            columns[i].setColor(RED);
    }

    test_column_printing(columns, x, y);
    mvprintw(0, 0, "Insertion Sort");
    refresh();
    getchar();
    insertion_sort(columns, x, y);
    getchar();
    clear();

    // Test Selection Sort
    for (int i = 0; i < x; i++)
    {
        columns[i].setHeight(1 + (rand() % y));
        if (i%2)
            columns[i].setColor(WHITE);
        else
            columns[i].setColor(RED);
    }

    test_column_printing(columns, x, y);
    mvprintw(0, 0, "Selection Sort");
    refresh();
    getchar();
    selection_sort(columns, x, y);
    getchar();
    clear();

    // Test Quick Sort
    for (int i = 0; i < x; i++)
    {
        columns[i].setHeight(1 + (rand() % y));
        if (i%2)
            columns[i].setColor(WHITE);
        else
            columns[i].setColor(RED);
    }

    test_column_printing(columns, x, y);
    mvprintw(0, 0, "Quick Sort");
    refresh();
    getchar();
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
    Column* c1 = new Column(5, WHITE);
    Column* c2 = new Column(10, WHITE);

    if (c1 > c2)
        cout << "c1 is > c2" << endl;
    else if (c1 < c2)
        cout << "c1 is < c2" << endl;
    delete c1;
    delete c2;
}

/* void test_column_printing(Column columns[], int x, int y) */
/* { */
/*     for (int i = 0; i < x; i++) */
/*     { */
/*         columns[i].draw(i, y); */
/*         refresh(); */
/*         usleep(SECOND * 0.01); */
/*     } */
/* } */

