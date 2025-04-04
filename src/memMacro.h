/*
Copyright (C) 2024 Joseph Swales

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

#ifndef __MEM_MACRO__
#define __MEM_MACRO__

#include <stdlib.h>
#include <stdio.h>

#define memMacro_malloc_helper(_1, _2, NAME, ...) NAME

/**
 * malloc based on size of the dereferenced pointer, aborts if allocation fails.
*/
#define memMacro_malloc_known(pointer) \
    do { \
        pointer = malloc(sizeof(*pointer)); \
        if (!pointer) { \
            perror("malloc error!"); \
            abort(); \
        } \
    } while(0)

#define memMacro_malloc_size(pointer, size) \
    do { \
        pointer = malloc(size); \
        if (!pointer) { \
            perror("malloc error!"); \
            abort(); \
        } \
    } while(0)

#define memMacro_malloc(...) memMacro_malloc_helper(__VA_ARGS__, memMacro_malloc_size, memMacro_malloc_known)(__VA_ARGS__)

#define memMacro_realloc_helper(_1, _2, NAME, ...) NAME

/**
 * realloc based on size of the dereferenced pointer, aborts if allocation fails.
*/
#define memMacro_realloc_known(pointer) \
    do { \
        pointer = realloc(pointer, sizeof(*pointer)); \
        if (!pointer) { \
            perror("realloc error!"); \
            abort(); \
        } \
    } while(0)

#define memMacro_realloc_size(pointer, size) \
    do { \
        pointer = realloc(pointer, size); \
        if (!pointer) { \
            perror("realloc error!"); \
            abort(); \
        } \
    } while(0)

#define memMacro_realloc(...) memMacro_realloc_helper(__VA_ARGS__, memMacro_realloc_size, memMacro_realloc_known)(__VA_ARGS__)

/**
 * calloc based on size of the dereferenced pointer, aborts if allocation fails.
*/
#define memMacro_calloc(pointer, count) \
    do { \
        __typeof__ (count) _count = (count); \
        pointer = calloc(_count, sizeof(*pointer)); \
        if (!pointer) { \
            perror("calloc error!"); \
            abort(); \
        } \
    } while(0)

/**
 * malloc based on size of the dereferenced pointer multiplied by the number of entries, aborts if allocation fails.
*/
#define memMacro_mallocArray(pointer, count) \
    do { \
        __typeof__ (count) _count = (count); \
        pointer = malloc(sizeof(*pointer) * _count); \
        if (!pointer) { \
            perror("malloc array error!"); \
            abort(); \
        } \
    } while(0)

/**
 * realloc based on size of the dereferenced pointer multiplied by the number of entries, aborts if allocation fails.
*/
#define memMacro_reallocArray(pointer, count) \
    do { \
        __typeof__ (count) _count = (count); \
        pointer = realloc(pointer, sizeof(*pointer) * _count); \
        if (!pointer) { \
            perror("realloc array error!"); \
            abort(); \
        } \
    } while(0)

#endif //__MEM_MACRO__