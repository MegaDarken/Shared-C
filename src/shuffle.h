#ifndef SHUFFLE_
#define SHUFFLE_

#include <stdlib.h>

#include "swapping.h"

#define shuffle_helper(_1, _2, _3, NAME, ...) NAME

#define shuffle_known(array, count) \
    do { \
        __typeof__ (count) _count = (count);\
        if (_count <= 1) break;\
        __typeof__ (array) _array = (array);\
        for ( __typeof__ (count) _i = _count - 1; _i > 0; _i-- ) { \
            __typeof__ (count) _rand = (rand() % (_i + 1)); \
            swap(&(_array[_i]), &(_array[_rand])); \
        } \
    } while(0)

#define shuffle_size(array, count, elementSize) \
    do { \
        __typeof__ (count) _count = (count);\
        if (_count <= 1) break;\
        char *_array = (char *)(array);\
        __typeof__ (elementSize) _elementSize = (elementSize);\
        for ( __typeof__ (_count) _i = _count - 1; _i > 0; _i-- ) { \
            __typeof__ (count) _rand = (rand() % (_i + 1)); \
            swap(&_array[_i * _elementSize], &_array[_rand * _elementSize], _elementSize); \
        } \
    } while(0)

#define shuffle(...) shuffle_helper(__VA_ARGS__, shuffle_size, shuffle_known)(__VA_ARGS__)

#endif //SHUFFLE_
