#ifndef SORTS_H
#define SORTS_H

/* quick_sort
 * Sort using quicksort
 *
 * Initial call: quick_sort(array, 0, size-1)
 *
 * Running time: ~ O(nlg(n))
 */
template <typename T>
void quick_sort(T a[], int b, int e);

/* bubble_sort
 * Sort using bubblesort
 *
 * Inital call: bubble_sort(array, size-1)
 *
 * Running time: ~ O(n^3)
 */
template <typename T>
void bubble_sort(T a[], int size);

#include "sorts.hpp"

#endif
