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

#ifndef MIDPOINT_
#define MIDPOINT_

#define midpointi(a,b) \
    ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    (_a + _b) >> 1; })

#define midpointf(a,b) \
    ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    (_a + _b) * 0.5f; })

#define midpoint(a,b) _Generic((a & b), \
    default: midpointf(a,b), \
    char: midpointi(a,b), \
    short int: midpointi(a,b), \
    int: midpointi(a,b), \
    long int: midpointi(a,b), \
    long long int: midpointi(a,b), \
    unsigned char: midpointi(a,b), \
    signed char: midpointi(a,b), \
    unsigned short int: midpointi(a,b), \
    unsigned int: midpointi(a,b), \
    unsigned long int: midpointi(a,b), \
    unsigned long long int: midpointi(a,b), \
    float: midpointf(a,b), \
    double: midpointf(a,b), \
    long double: midpointf(a,b) \
    )

#define midpoint3(a,b,c) \
    ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    __typeof__ (c) _c = (c); \
    (_a + _b + _c) / 3; })

#define midpoint4i(a,b,c,d) \
    ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    __typeof__ (c) _c = (c); \
    __typeof__ (d) _d = (d); \
    (_a + _b + _c + _d) >> 2; })

#define midpoint4f(a,b,c,d) \
    ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    __typeof__ (c) _c = (c); \
    __typeof__ (d) _d = (d); \
    (_a + _b + _c + _d) * 0.25f; })

#define midpoint4(a,b,c,d) _Generic((a & b & c & d), \
    default: midpoint4f(a,b,c,d), \
    char: midpoint4i(a,b,c,d), \
    short int: midpoint4i(a,b,c,d), \
    int: midpoint4i(a,b,c,d), \
    long int: midpoint4i(a,b,c,d), \
    long long int: midpoint4i(a,b,c,d), \
    unsigned char: midpoint4i(a,b,c,d), \
    signed char: midpoint4i(a,b,c,d), \
    unsigned short int: midpoint4i(a,b,c,d), \
    unsigned int: midpoint4i(a,b,c,d), \
    unsigned long int: midpoint4i(a,b,c,d), \
    unsigned long long int: midpoint4i(a,b,c,d), \
    float: midpoint4f(a,b,c,d), \
    double: midpoint4f(a,b,c,d), \
    long double: midpoint4f(a,b,c,d) \
    )

char midpoint_char(const char a, const char b);
int midpoint_int(const int a, const int b);
long midpoint_long(const long a, const long b);
long long midpoint_longLong(const long long a, const long long b);

float midpoint_float(const float a, const float b);
double midpoint_double(const double a, const double b);
long double midpoint_longDouble(const long double a, const long double b);

char midpoint_4char(const char a, const char b, const char c, const char d);
int midpoint_4int(const int a, const int b, const int c, const int d);
long midpoint_4long(const long a, const long b, const long c, const long d);
long long midpoint_4longLong(const long long a, const long long b, const long long c, const long long d);

float midpoint_4float(const float a, const float b, const float c, const float d);
double midpoint_4double(const double a, const double b, const double c, const double d);
long double midpoint_4longDouble(const long double a, const long double b, const long double c, const long double d);

#endif //MIDPOINT_
