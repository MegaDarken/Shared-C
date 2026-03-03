#ifndef ARRAY_MATH_UTILITY_
#define ARRAY_MATH_UTILITY_

#include "mathUtility.h"
#include "typeUtility.h"

#define arrayMathUtility_max(array, count) \
    ({ __typeof__ (array) _array = (array); \
    __typeof__ (array[0] + 0) _output = typeMin(array[0]); \
    for ( size_t _index = 0; _index < count; _index++ ) { \
        _output = max(_output, _array[_index]); \
    } \
    _output; })

#define arrayMathUtility_min(array, count) \
    ({ __typeof__ (array) _array = (array); \
    __typeof__ (array[0] + 0) _output = typeMax(array[0]); \
    for ( size_t _index = 0; _index < count; _index++ ) { \
        _output = min(_output, _array[_index]); \
    } \
    _output; })

#define arrayMathUtility_absMax(array, count) \
    ({ __typeof__ (array) _array = (array); \
    __typeof__ (array[0] + 0) _output = typeMin(array[0]); \
    for ( size_t _index = 0; _index < count; _index++ ) { \
        _output = absMax(_output, _array[_index]); \
    } \
    _output; })

#define arrayMathUtility_absMin(array, count) \
    ({ __typeof__ (array) _array = (array); \
    __typeof__ (array[0] + 0) _output = typeMax(array[0]); \
    for ( size_t _index = 0; _index < count; _index++ ) { \
        _output = absMin(_output, _array[_index]); \
    } \
    _output; })

// Index focused

#define arrayMathUtility_maxIndex(array, count) \
    ({ __typeof__ (array) _array = (array); \
    __typeof__ (count) _maxIndex = 0; \
    for ( size_t _index = 1; _index < count; _index++ ) { \
        if (_array[_maxIndex] < _array[_index]) { \
            _maxIndex = _index; \
        } \
    } \
    _maxIndex; })

#define arrayMathUtility_minIndex(array, count) \
    ({ __typeof__ (array) _array = (array); \
    __typeof__ (count) _minIndex = 0; \
    for ( size_t _index = 1; _index < count; _index++ ) { \
        if (_array[_minIndex] > _array[_index]) { \
            _minIndex = _index; \
        } \
    } \
    _minIndex; })

#define arrayMathUtility_absMaxIndex(array, count) \
    ({ __typeof__ (array) _array = (array); \
    __typeof__ (count) _maxIndex = 0; \
    for ( size_t _index = 1; _index < count; _index++ ) { \
        if (abs(_array[_maxIndex]) < abs(_array[_index])) { \
            _maxIndex = _index; \
        } \
    } \
    _maxIndex; })

#define arrayMathUtility_absMinIndex(array, count) \
    ({ __typeof__ (array) _array = (array); \
    __typeof__ (count) _minIndex = 0; \
    for ( size_t _index = 1; _index < count; _index++ ) { \
        if (abs(_array[_minIndex]) > abs(_array[_index])) { \
            _minIndex = _index; \
        } \
    } \
    _minIndex; })

#endif //ARRAY_MATH_UTILITY_