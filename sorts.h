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
void bubble_sort(T a[], int size, int y);

/* selection_sort
 * Sort using selection sort
 *
 * Inital call: selection_sort(array, size-1)
 *
 * Running time: ~ O(n^2)
 */
template <typename T>
void selection_sort(T a[], int size, int y);

/* insertion_sort
 * Sort using insertion sort
 *
 * Inital call: insertion_sort(array, size-1)
 *
 * Running time: ~ O(n^2)
 */
template <typename T>
void insertion_sort(T a[], int size, int y);


#include "sorts.hpp"

#endif
