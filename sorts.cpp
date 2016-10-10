#include "sorts.h"
#include "helpers.h"

void quick_sort(int a[], int b, int e)
{
    if (b >= e)
        return;

    int pivot = a[e];
    int w = b-1;
    int j = b;
    while (j != e)
    {
        if (a[j] < pivot)
        {
            w++;
            swap(a[w], a[j]);
        }
        j++;
    }
    w++;
    swap(a[w], a[e]);
    quick_sort(a, b, w-1);
    quick_sort(a, w+1, e);
    return;
}

