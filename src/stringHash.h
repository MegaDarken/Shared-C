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

#ifndef __STRING_HASH__
#define __STRING_HASH__

#include <stdlib.h>

#include "stringConstexpr.h"

//Constant(s)
#define CHAR_ARRAY_PRIME_A 777767777ul
#define CHAR_ARRAY_PRIME_B 322222223ul
#define CHAR_ARRAY_PRIME_C 6661111ul
#define CHAR_ARRAY_PRIME_D 841069ul

// #ifdef __cplusplus
// extern "C" {
// #endif //__cplusplus

#define stringHash_helper(_1, _2, NAME, ...) NAME

#ifdef __cplusplus
inline constexpr
#endif //__cplusplus
__UINT64_TYPE__ stringHash_size(const char *string, size_t stringSize)
{
    size_t hash = CHAR_ARRAY_PRIME_D;

    for (size_t i = 0; i < stringSize; i++)
    {
        hash = (hash * CHAR_ARRAY_PRIME_A) + (string[i] * (i & 1 ? CHAR_ARRAY_PRIME_B : CHAR_ARRAY_PRIME_C));
    }

    return hash;
}

#ifdef __cplusplus
inline constexpr
#endif //__cplusplus
__UINT64_TYPE__ stringHash_nullTerminated(const char* string)
{
    return stringHash_size(string, stringConstexpr_length(string));
}

#define stringHash(...) stringHash_helper(__VA_ARGS__, stringHash_size, stringHash_nullTerminated)(__VA_ARGS__)

// #ifdef __cplusplus
// }
// #endif //__cplusplus

#endif //__STRING_HASH__