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

#ifndef __ARRAY_PRINT__
#define __ARRAY_PRINT__

#include <stdio.h>

void arrayPrint_fchar(FILE *stream, char *array, size_t count);
#define arrayPrint_char(array, count) arrayPrint_fchar(stdout, array, count)

void arrayPrint_fuchar(FILE *stream, unsigned char *array, size_t count);
#define arrayPrint_uchar(array, count) arrayPrint_fuchar(stdout, array, count)

void arrayPrint_fshort(FILE *stream, short *array, size_t count);
#define arrayPrint_short(array, count) arrayPrint_fshort(stdout, array, count)

void arrayPrint_fushort(FILE *stream, unsigned short *array, size_t count);
#define arrayPrint_ushort(array, count) arrayPrint_fushort(stdout, array, count)

void arrayPrint_fint(FILE *stream, int *array, size_t count);
#define arrayPrint_int(array, count) arrayPrint_fint(stdout, array, count)

void arrayPrint_fuint(FILE *stream, unsigned int *array, size_t count);
#define arrayPrint_uint(array, count) arrayPrint_fuint(stdout, array, count)

void arrayPrint_flong(FILE *stream, long *array, size_t count);
#define arrayPrint_long(array, count) arrayPrint_flong(stdout, array, count)

void arrayPrint_fulong(FILE *stream, unsigned long *array, size_t count);
#define arrayPrint_ulong(array, count) arrayPrint_fulong(stdout, array, count)

void arrayPrint_flonglong(FILE *stream, long long *array, size_t count);
#define arrayPrint_longlong(array, count) arrayPrint_flonglong(stdout, array, count)

void arrayPrint_fulonglong(FILE *stream, unsigned long long *array, size_t count);
#define arrayPrint_ulonglong(array, count) arrayPrint_fulonglong(stdout, array, count)

void arrayPrint_ffloat(FILE *stream, float *array, size_t count);
#define arrayPrint_float(array, count) arrayPrint_ffloat(stdout, array, count)

void arrayPrint_fdouble(FILE *stream, double *array, size_t count);
#define arrayPrint_double(array, count) arrayPrint_fdouble(stdout, array, count)

#define farrayPrint(stream, array, count) _Generic((*array), \
    char: arrayPrint_fchar(stream, array, count), \
    unsigned char: arrayPrint_fuchar(stream, array, count), \
    short: arrayPrint_fshort(stream, array, count), \
    unsigned short: arrayPrint_fushort(stream, array, count), \
    int: arrayPrint_fint(stream, array, count), \
    unsigned int: arrayPrint_fuint(stream, array, count), \
    long: arrayPrint_flong(stream, array, count), \
    unsigned long: arrayPrint_fulong(stream, array, count), \
    long long: arrayPrint_flonglong(stream, array, count), \
    unsigned long long: arrayPrint_fulonglong(stream, array, count), \
    float: arrayPrint_ffloat(stream, array, count), \
    double: arrayPrint_fdouble(stream, array, count), \
    default: perror("ERR:farrayPrint unknown type.") \
    )

#define arrayPrint(array, count) farrayPrint(stdout, array, count)

#endif //__ARRAY_PRINT__
