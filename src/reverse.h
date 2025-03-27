
#ifndef __REVERSE__
#define __REVERSE__

#include "swapping.h"

#define reverse_helper(_1, _2, _3, NAME, ...) NAME

// #define reverse_size(array, count, elementSize) \
//     do { \
//         __typeof__ (array) _array = (array);\
//         __typeof__ (count) _count = (count);\
//         __typeof__ (elementSize) _elementSize = (elementSize);\
//         __typeof__ (array) _head = _array;\
//         __typeof__ (array) _tail = _array + ((_count - 1) * _elementSize);\
//         while (_head < _tail) { \
//             swap(_head,_tail,_elementSize);\
//             _head += _elementSize;\
//             _tail -= _elementSize;\
//         } \
//     } while(0)

void reverse_size(void *array, size_t count, size_t elementSize);

#define reverse_known(array, count) reverse_size(array, count, sizeof(array[0]))

#define reverse(...) reverse_helper(__VA_ARGS__, reverse_size, reverse_known)(__VA_ARGS__)

#endif //__REVERSE__
