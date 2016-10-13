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

#include "sorts.hpp"

#endif
