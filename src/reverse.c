
#include "reverse.h"

#include <stddef.h>

#include "swapping.h"

void reverse_size(void *array, size_t count, size_t elementSize)
{
    void * head = array;
    void * tail = array + ((count - 1) * elementSize);

    while (head < tail)
    { 
        swap(head, tail, elementSize);
        
        head += elementSize;
        tail -= elementSize;
    }
}