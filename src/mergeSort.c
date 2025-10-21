/*
Copyright (C) 2025 Joseph Swales

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "mergeSort.h"

#include <string.h>

#include "merge.h"
#include "memMacro.h"

/**
 * Actually an iterative mergesort for log(n) less memory usage.
 */
void mergeSort(void *array, const size_t count, const size_t elementSize, int (*compar)(const void *, const void *))
{
    if (count <= 1)
    {
        return;
    }

    __UINT8_TYPE__ *barray = (__UINT8_TYPE__ *)array;
    __UINT8_TYPE__ *buffer = 0x0;

    memMacro_malloc_size(buffer, count * elementSize);

    size_t i = 2;

    for (; i < count; i = i << 1)
    {
        size_t j = 0;

        for (; j + i < count; j += i)
        {
            merge(&barray[j * elementSize],
                (i >> 1),
                &barray[(j + (i >> 1)) * elementSize],
                (i >> 1),
                elementSize, &buffer[j * elementSize],
                compar);
        }

        if (j + (i >> 1) < count)
        {
            merge(&barray[j * elementSize],
                (i >> 1),
                &barray[(j + (i >> 1)) * elementSize],
                count - (j + (i >> 1)),
                elementSize,
                &buffer[j * elementSize],
                compar);

            j = count;
        }

        memcpy(barray, buffer, j * elementSize);
    }

    merge(barray, (i >> 1), &barray[(i >> 1) * elementSize], count - ((i >> 1)), elementSize, buffer, compar);

    memcpy(barray, buffer, count * elementSize);

    free(buffer);
}

/**
 * Actually an iterative mergesort for log(n) less memory usage.
 */
// void mergeSort_inPlace(void *array, const size_t count, const size_t elementSize, int (*compar)(const void *, const void *))
// {
//     size_t i = 2;

//     for (; i < count; i = i << 1)
//     {
//         size_t j = 0;

//         for (; j + i < count; j += i)
//         {
//             mergeInPlace(array, j, j + (i >> 1), j + i, elementSize, compar);
//         }

//         mergeInPlace(array, j, j + (i >> 1), count, elementSize, compar);
//     }

//     mergeInPlace(array, 0, i >> 1, count, elementSize, compar); // See if you can get the loop to occur once more rather than having to call this again.
// }

/**
 * Actually an iterative mergesort for log(n) less memory usage.
 */
void mergeSort_inPlace(void *array, const size_t count, const size_t elementSize, int (*compar)(const void *, const void *))
{
    size_t i = 2;

    for (; i < count; i = i << 1)
    {
        size_t j = 0;

        for (; j + i < count; j += i)
        {
            mergeRotating(array, j, j + (i >> 1), j + i, elementSize, compar);
        }

        mergeRotating(array, j, j + (i >> 1), count, elementSize, compar);
    }

    mergeRotating(array, 0, i >> 1, count, elementSize, compar); // See if you can get the loop to occur once more rather than having to call this again.
}