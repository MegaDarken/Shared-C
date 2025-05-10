#include "heapSort.h"

#include "swapping.h"

size_t heapSort_parent(const size_t index)
{
    return (index - 1) >> 1;
}

size_t heapSort_left(const size_t index)
{
    return (index << 1) + 1;
}

size_t heapSort_right(const size_t index)
{
    return (index << 1) + 2;
}

void heapSort_siftDown(void* array, const size_t start, const size_t count, const size_t elementSize, int (* compar)(const void *, const void *))
{
    size_t current = start;

    while (heapSort_left(current) < count)
    {
        size_t child = heapSort_left(current);
        size_t right = heapSort_right(current);

        void* childPtr = array + (child * elementSize);

        if (right < count)
        {
            void* rightPtr = array + (right * elementSize);

            if (compar(rightPtr, childPtr) > 0)
            {
                            
                child = right;
                childPtr = rightPtr;
            }
        }
        
        void* currentPtr = array + (current * elementSize);

        if (compar(childPtr, currentPtr) > 0)
        {
            swap(currentPtr, childPtr, elementSize);
            current = child;
        }
        else
        {
            return;
        }
    }
    
}

/**
 * Williams heap construction
 */
void heapSort_siftUp(void* array, const size_t count, const size_t elementSize, int (* compar)(const void *, const void *))
{
    size_t end = count - 1;

    while (end > 0)
    {
        size_t parent = heapSort_parent(end);

        void* endPtr = array + (end * elementSize);
        void* parentPtr = array + (parent * elementSize);

        if (compar(endPtr, parentPtr) > 0)
        {
            swap(parentPtr, endPtr, elementSize);
            end = parent;
        }
        else
        {
            return;
        }
    }
    
}

void heapSort_heapify(void* array, const size_t count, const size_t elementSize, int (* compar)(const void *, const void *))
{
    size_t current = heapSort_parent(count - 1) + 1;

    while (current > 0)
    {
        current--;

        heapSort_siftDown(array, current, count, elementSize, compar);
    }
}

void heapSort(void* array, const size_t count, const size_t elementSize, int (* compar)(const void *, const void *))
{
    heapSort_heapify(array, count, elementSize, compar);

    size_t end = count;

    while (end > 1)
    {
        end--;

        swap(array + (end * elementSize), array, elementSize);

        heapSort_siftDown(array, 0, end, elementSize, compar);
    }
    
}
