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

#ifndef __ROTATE__
#define __ROTATE__

#include "reverse.h"

#define rotate_helper(_1, _2, _3, _4, NAME, ...) NAME

#define rotate_size(array, arrayCount, elementSize, rotationCount) \
do { \
    __typeof__ (array) _array = (array);\
    __typeof__ (arrayCount) _arrayCount = (arrayCount);\
    __typeof__ (elementSize) _elementSize = (elementSize);\
    __typeof__ (rotationCount) _rotationCount = (rotationCount);\
    reverse_size(_array, _arrayCount, _elementSize); \
    reverse_size(_array, _rotationCount, _elementSize); \
    reverse_size(_array + (_rotationCount * _elementSize), _arrayCount - _rotationCount, _elementSize); \
} while(0)

#define rotate_known(array, arrayCount, rotationCount) \
do { \
    __typeof__ (array) _array = (array);\
    __typeof__ (arrayCount) _arrayCount = (arrayCount);\
    __typeof__ (rotationCount) _rotationCount = (rotationCount);\
    reverse_size(_array, _arrayCount, sizeof(*_array)); \
    reverse_size(_array, _rotationCount, sizeof(*_array)); \
    reverse_size(&_array[_rotationCount], _arrayCount - _rotationCount, sizeof(*_array)); \
} while(0)

#define rotate(...) rotate_helper(__VA_ARGS__, rotate_size, rotate_known)(__VA_ARGS__)

//LEFT
#define rotate_left_helper(_1, _2, _3, _4, NAME, ...) NAME

#define rotate_left_size(array, arrayCount, elementSize) \
do { \
    __typeof__ (array) _array = (array);\
    __typeof__ (arrayCount) _arrayCount = (arrayCount);\
    __typeof__ (elementSize) _elementSize = (elementSize);\
    unsigned char _element_temp[_elementSize]; \
    memcpy(_element_temp, _array, _elementSize); \
    memmove(_array, _array + _elementSize, (_arrayCount - 1) * _elementSize); \
    memcpy(_array + ((_arrayCount - 1) * _elementSize), _element_temp, _elementSize); \
} while(0)

#define rotate_left_known(array, arrayCount) \
do { \
    __typeof__ (array) _array = (array);\
    __typeof__ (arrayCount) _arrayCount = (arrayCount);\
    unsigned char _element_temp[sizeof(*array)]; \
    memcpy(_element_temp, _array, sizeof(*array)); \
    memmove(_array, &_array[1], (_arrayCount - 1) * sizeof(*array)); \
    memcpy(&_array[_arrayCount - 1], _element_temp, sizeof(*array)); \
} while(0)

#define rotate_left(...) rotate_left_helper(__VA_ARGS__, rotate_left_size, rotate_left_known)(__VA_ARGS__)

//RIGHT
#define rotate_right_helper(_1, _2, _3, _4, NAME, ...) NAME

#define rotate_right_size(array, arrayCount, elementSize) \
do { \
    __typeof__ (array) _array = (array);\
    __typeof__ (arrayCount) _arrayCount = (arrayCount);\
    __typeof__ (elementSize) _elementSize = (elementSize);\
    unsigned char _element_temp[_elementSize]; \
    memcpy(_element_temp, _array + ((_arrayCount - 1) * _elementSize), _elementSize); \
    memmove(_array + _elementSize, _array, (_arrayCount - 1) * _elementSize); \
    memcpy(_array, _element_temp, _elementSize); \
} while(0)

#define rotate_right_known(array, arrayCount) \
do { \
    __typeof__ (array) _array = (array);\
    __typeof__ (arrayCount) _arrayCount = (arrayCount);\
    unsigned char _element_temp[sizeof(*array)]; \
    memcpy(_element_temp, &_array[_arrayCount - 1], sizeof(*array)); \
    memmove(&_array[1], _array, (_arrayCount - 1) * sizeof(*array)); \
    memcpy(_array, _element_temp, sizeof(*array)); \
} while(0)

#define rotate_right(...) rotate_right_helper(__VA_ARGS__, rotate_right_size, rotate_right_known)(__VA_ARGS__)

#endif //__ROTATE__
