/*
Copyright (C) 2026 Joseph Swales

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

#ifndef __ARRAY_COMBINE__
#define __ARRAY_COMBINE__

#define arrayCombine_sumScaledDest(arrayDest, arrayA, arrayB, arraySize, multiplierA, multiplierB) \
    do { \
        __typeof__ (arraySize) __arraySize = (arraySize); \
        __typeof__ (multiplierA) __multiplierA = (multiplierA); \
        __typeof__ (multiplierB) __multiplierB = (multiplierB); \
        for (size_t __i = 0; __i < __arraySize; __i++) \
        { \
            arrayDest[__i] = arrayA[__i] * __multiplierA + arrayB[__i] * __multiplierB; \
        } \
    } while(0)

#define arrayCombine_sumScaled(arrayA, arrayB, arraySize, multiplierA, multiplierB) arrayCombine_sumScaledDest(arrayA, arrayA, arrayB, arraySize, multiplierA, multiplierB)

#endif //__ARRAY_COMBINE__
