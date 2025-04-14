#ifndef ARRAY_MATH_UTILITY_
#define ARRAY_MATH_UTILITY_

#include "mathUtility.h"

#define arrayMathUtility_max(array, count) \
    ({ __typeof__ (array[0]) _output = typeMin(array[0]); \
    for ( size_t _index = 0; _index < count; _index++ ) { \
        _output = max(_output, _array[_index]); \
    } \
    _output; })

#define arrayMathUtility_min(array, count) \
    ({ __typeof__ (array[0]) _output = typeMax(array[0]); \
    for ( size_t _index = 0; _index < count; _index++ ) { \
        _output = min(_output, _array[_index]); \
    } \
    _output; })

#define arrayMathUtility_absMax(array, count) \
    ({ __typeof__ (array[0]) _output = typeMin(array[0]); \
    for ( size_t _index = 0; _index < count; _index++ ) { \
        _output = absMax(_output, _array[_index]); \
    } \
    _output; })

#define arrayMathUtility_absMin(array, count) \
    ({ __typeof__ (array[0]) _output = typeMax(array[0]); \
    for ( size_t _index = 0; _index < count; _index++ ) { \
        _output = absMin(_output, _array[_index]); \
    } \
    _output; })

#endif //ARRAY_MATH_UTILITY_