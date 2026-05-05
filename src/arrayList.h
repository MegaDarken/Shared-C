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

#ifndef __ARRAY_LIST__
#define __ARRAY_LIST__

#include <stddef.h>
#include <stdio.h>

#include "mathUtility.h"

#define define_arrayList(type) \
    typedef struct { \
        size_t count; \
        type* data; \
    } arrayList_##type; \
    void arrayList_createDest_##type(arrayList_##type* dest, size_t count); \
    arrayList_##type arrayList_create_##type(size_t count); \
    void arrayList_free_##type(arrayList_##type* var); \
    void arrayList_resize_##type(arrayList_##type* var, size_t newCount); \

#define declare_arrayList(type) \
    void arrayList_createDest_##type(arrayList_##type* dest, size_t count){ \
        dest->count = count; \
        dest->data = malloc(sizeof(type) * dest->count); \
        if (!dest->data){ \
            perror("Error allocating memory for arrayList!"); \
            abort(); \
        } \
    } \
    arrayList_##type arrayList_create_##type(size_t count){ \
        arrayList_##type output; \
        arrayList_createDest_##type(&output, count); \
        return output; \
    } \
    void arrayList_free_##type(arrayList_##type* var){ \
        free(var->data); \
        var->data = NULL; \
        var->count = 0; \
    } \
    void arrayList_resize_##type(arrayList_##type* var, size_t newCount){ \
        var->count = newCount; \
        var->data = realloc(var->data, sizeof(type) * var->count); \
        if (!var->data && var->count != 0){ \
            perror("Error reallocating memory for arrayList!"); \
            abort(); \
        } \
    }

#endif //__ARRAY_LIST__
