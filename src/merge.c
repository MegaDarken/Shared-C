

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "swapping.h"
#include "rotate.h"

//See: https://en.m.wikipedia.org/wiki/Block_sort

void merge(
    void* leftArray,
    const size_t leftCount,
    void* rightArray,
    const size_t rightCount,
    const size_t elementSize,
    void* dest,
    int (* compar)(const void *, const void *
)
)
{
    __UINT8_TYPE__ *bleftArray = (__UINT8_TYPE__ *)leftArray;
    __UINT8_TYPE__ *brightArray = (__UINT8_TYPE__ *)rightArray;

    __UINT8_TYPE__ *bdest = (__UINT8_TYPE__ *)dest;

    size_t leftIndex = 0;
    size_t rightIndex = 0;
    size_t insert = 0;

    while(leftIndex < leftCount && rightIndex < rightCount)//insert <= (right - left) || 
    {
        int comparisonValue = compar(&bleftArray[leftIndex * elementSize], &brightArray[rightIndex * elementSize]);

        if (comparisonValue <= 0)
        {
            memcpy(&bdest[insert * elementSize], &bleftArray[leftIndex * elementSize], elementSize);
            leftIndex++;
        }
        else // (comparisonValue > 0)
        {
            memcpy(&bdest[insert * elementSize], &brightArray[rightIndex * elementSize], elementSize);
            rightIndex++;
        }

        insert++;
    }

    if(leftIndex < leftCount)
    {
        memcpy(&bdest[insert * elementSize], &bleftArray[leftIndex * elementSize], elementSize * ((leftCount - leftIndex)));
    }
    else if (rightIndex < rightCount)
    {
        memcpy(&bdest[insert * elementSize], &brightArray[rightIndex * elementSize], elementSize * ((rightCount - rightIndex)));
    }
}

void mergeInPlace(
    void* array,
    const size_t left,
    const size_t mid,
    const size_t right,
    const size_t elementSize,
    int (* compar)(const void *, const void *)
)
{
    if (compar(array + ((mid - 1) * elementSize), array + (mid * elementSize)) < 0)
    {
        return;
    }

    size_t leftIndex = left;
    size_t rightIndex = mid;

    while(leftIndex < rightIndex && rightIndex < right)
    {
        int comparisonValue = compar(array + (leftIndex * elementSize), array + (rightIndex * elementSize));

        if (comparisonValue > 0)
        {
            rotate_size(array + ((leftIndex) * elementSize), right - (leftIndex), elementSize, (right - rightIndex));
            rightIndex = right - (rightIndex - leftIndex);
        }

        leftIndex++;        
    }
}

void mergeRotating(
    void* array,
    const size_t left,
    const size_t mid,
    const size_t right,
    const size_t elementSize,
    int (* compar)(const void *, const void *)
)
{
    if (compar(array + ((mid - 1) * elementSize), array + (mid * elementSize)) < 0)
    {
        return;
    }

    size_t leftIndex = left;
    size_t rightIndex = mid;

    while(leftIndex < rightIndex && rightIndex < right)
    {
        int comparisonValue = compar(array + (leftIndex * elementSize), array + (rightIndex * elementSize));

        if (comparisonValue > 0)
        {
            rotate_right_size(array + ((leftIndex) * elementSize), 1 + (rightIndex - leftIndex), elementSize);
            rightIndex++;
        }
        else
        {
            leftIndex++;
        }        
    }
}

// #include <stdio.h>

// int int_comp(const void * a, const void * b)
// {
//     int arg1 = *(const int*)a;
//     int arg2 = *(const int*)b;
 
//     if (arg1 < arg2) return -1;
//     if (arg1 > arg2) return 1;
//     return 0;
// }

// int merge_test()
// {
// 	printf("\nMerge\n");

//     int array[] = {1,3,5,7,9,2,4,6,8,10};
//     int buffer[sizeof(array)/sizeof(array[0])];
    
//     for (size_t i = 0; i < (sizeof(array)/sizeof(array[0])); i++)
//     {
//         printf("%d ", array[i]);
//     }
    
//     printf("\ndoing.\n");

//     mergeBuffered(array, 0, 5, sizeof(array)/sizeof(array[0]), sizeof(array[0]), buffer, int_comp);

//     for (size_t i = 0; i < (sizeof(array)/sizeof(array[0])); i++)
//     {
//         printf("%d ", array[i]);
//     }

//     printf("\ndone.\n");

//     printf("InPlace\n");

//     int arrayB[] = {1,3,5,7,9,11,13,15,2,4,6,8,10};

//     mergeInPlace(arrayB, 0, 8, sizeof(arrayB)/sizeof(arrayB[0]), sizeof(arrayB[0]), int_comp);

//     for (size_t i = 0; i < (sizeof(arrayB)/sizeof(arrayB[0])); i++)
//     {
//         printf("%d ", arrayB[i]);
//     }

// }
