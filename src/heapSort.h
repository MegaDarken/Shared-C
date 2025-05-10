#ifndef HEAP_SORT_
#define HEAP_SORT_

#include <stdlib.h>

size_t heapSort_parent(const size_t index);
size_t heapSort_left(const size_t index);
size_t heapSort_right(const size_t index);

void heapSort_siftDown(void* array, const size_t start, const size_t count, const size_t elementSize, int (* compar)(const void *, const void *));
void heapSort_siftUp(void* array, const size_t count, const size_t elementSize, int (* compar)(const void *, const void *));

void heapSort_heapify(void* array, const size_t count, const size_t elementSize, int (* compar)(const void *, const void *));

void heapSort(void* array, const size_t count, const size_t elementSize, int (* compar)(const void *, const void *));

#endif //HEAP_SORT_