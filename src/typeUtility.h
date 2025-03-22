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

#ifndef TYPE_UTILITY_
#define TYPE_UTILITY_

#include <limits.h>
#include <float.h>

#define typeMax(value) _Generic((value), \
    default: 0xffffffffffffffff, \
    signed char: SCHAR_MAX, \
    unsigned char: UCHAR_MAX, \
    char: CHAR_MAX, \
    short: SHRT_MAX, \
    unsigned short: USHRT_MAX, \
    int: INT_MAX, \
    unsigned int: UINT_MAX, \
    long: LONG_MAX, \
    unsigned long: ULONG_MAX, \
    long long: LLONG_MAX, \
    unsigned long long: ULLONG_MAX, \
    float: FLT_MAX, \
    double: DBL_MAX, \
    long double: LDBL_MAX \
)

#define typeMin(value) _Generic((value), \
    default: 0, \
    signed char: SCHAR_MIN, \
    unsigned char: UCHAR_MIN, \
    char: CHAR_MIN, \
    short: SHRT_MIN, \
    unsigned short: USHRT_MIN, \
    int: INT_MIN, \
    unsigned int: UINT_MIN, \
    long: LONG_MIN, \
    unsigned long: ULONG_MIN, \
    long long: LLONG_MIN, \
    unsigned long long: ULLONG_MIN, \
    float: FLT_MIN, \
    double: DBL_MIN, \
    long double: LDBL_MIN \
)

#endif //TYPE_UTILITY_