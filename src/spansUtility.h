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

#ifndef _SPANS_UTILITY_
#define _SPANS_UTILITY_

#include <stddef.h>
#include <string.h>

/**
 * @param array The input array of data that is looped through.
 * @param count The length of the input array and the maximum length of the spans array.
 * @param spanArray The output array of how many instances in a row have the same answer from the 'check' statement.
 * @param check A statement that is run every iteration of the loop with the variable '_loopIndex' being the current array index.
 */
#define spans(array, count, spanArray, check) \
    do { \
        __typeof__ (array) _array = (array); \
        __typeof__ (count) _count = (count); \
        __typeof__ (spanArray[0]) *_spanArray = (spanArray); \
        memset(_spanArray, 0, sizeof(_spanArray[0]) * _count); \
        size_t _loopIndex = 0; \
        size_t _spanIndex = 0; \
        __typeof__ (check) _previousState = check; \
        for ( ; _loopIndex < _count; _loopIndex++ ) { \
            __typeof__ (check) _currentState = check; \
            if (_previousState != _currentState) { \
                _previousState = _currentState; \
                _spanIndex++; \
            } \
            _spanArray[_spanIndex]++; \
        } \
    } while(0);

#endif //_SPANS_UTILITY_