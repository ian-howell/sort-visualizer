#include "helpers.h"
template <typename T>
void quick_sort(T a[], int b, int e)
{
    if (b >= e)
        return;

    T pivot = a[e];
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

