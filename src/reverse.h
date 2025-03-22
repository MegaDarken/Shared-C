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

#ifndef __REVERSE__
#define __REVERSE__

#include "swapping.h"

#define reverse_helper(_1, _2, _3, NAME, ...) NAME

#define reverse_size(array, count, elementSize) \
    do { \
        __typeof__ (array) _array = (array);\
        __typeof__ (count) _count = (count);\
        __typeof__ (elementSize) _elementSize = (elementSize);\
        __typeof__ (array) _head = _array;\
        __typeof__ (array) _tail = _array + (_count * _elementSize);\
        for (;_head < _tail;) { \
            swap(_head,_tail,_elementSize);\
            _head++;\
            _tail--;\
        } \
    } while(0)

#define reverse_known(array, count) reverse_size(array, count, sizeof(*array))

#define reverse(...) reverse_helper(__VA_ARGS__, reverse_size, reverse_known)(__VA_ARGS__)

#endif //__REVERSE__
