#include <iostream>
#include <cstdlib>
#include <ctime>
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
}
