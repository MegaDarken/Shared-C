

#ifndef __MERGE__
#define __MERGE__

#include <stdlib.h>

void merge(void* leftArray, const size_t leftCount, void* rightArray, const size_t rightCount, const size_t elementSize, void* dest, int (* compar)(const void *, const void *));
void mergeInPlace(void* array, const size_t left, const size_t mid, const size_t right, const size_t elementSize, int (* compar)(const void *, const void *));

// int int_comp(const void * a, const void * b);
// int merge_test();

#endif //__MERGE__
