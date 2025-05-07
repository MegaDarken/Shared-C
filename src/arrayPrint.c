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

#include "arrayPrint.h"

void arrayPrint_fchar(FILE *stream, char *array, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        fprintf(stream, "%hhd,", array[i]);
    }
}

void arrayPrint_fuchar(FILE *stream, unsigned char *array, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        fprintf(stream, "%hhu,", array[i]);
    }
}

void arrayPrint_fshort(FILE *stream, short *array, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        fprintf(stream, "%hd,", array[i]);
    }
}

void arrayPrint_fushort(FILE *stream, unsigned short *array, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        fprintf(stream, "%hu,", array[i]);
    }
}

void arrayPrint_fint(FILE *stream, int *array, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        fprintf(stream, "%d,", array[i]);
    }
}

void arrayPrint_fuint(FILE *stream, unsigned int *array, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        fprintf(stream, "%u,", array[i]);
    }
}

void arrayPrint_flong(FILE *stream, long *array, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        fprintf(stream, "%ld,", array[i]);
    }
}

void arrayPrint_fulong(FILE *stream, unsigned long *array, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        fprintf(stream, "%lu,", array[i]);
    }
}

void arrayPrint_flonglong(FILE *stream, long long *array, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        fprintf(stream, "%lld,", array[i]);
    }
}

void arrayPrint_fulonglong(FILE *stream, unsigned long long *array, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        fprintf(stream, "%llu,", array[i]);
    }
}

void arrayPrint_ffloat(FILE *stream, float *array, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        fprintf(stream, "%f,", array[i]);
    }
}

void arrayPrint_fdouble(FILE *stream, double *array, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        fprintf(stream, "%f,", array[i]);
    }
}