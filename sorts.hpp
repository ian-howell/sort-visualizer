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

template <typename T>
void bubble_sort(T a[], int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size-1; j++)
            if (a[j] > a[j+1])
                swap(a[j], a[j+1]);
    return;
}

template <typename T>
void selection_sort(T a[], int size)
{
    T min;
    int minIndex;
    for (int i = 0; i < size - 1; i++)
    {
        min = a[i];
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

template <typename T>
void insertion_sort(T a[], int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i - 1; j >= 0 && a[j] > a[j+1]; j--)
        {
            swap(a[j], a[j+1]);
        }
    }
}
