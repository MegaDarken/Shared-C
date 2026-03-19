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

#ifndef __STACK__
#define __STACK__

#include <stddef.h>

#include "mathUtility.h"

#define define_stack(type) \
    struct stack_##type { \
        size_t allocatedCount; \
        size_t usedCount; \
        type* data; \
    }; \
    void stack_createDest_##type(struct stack_##type* dest); \
    struct stack_##type stack_create_##type(); \
    void stack_free_##type(struct stack_##type* var); \
    void stack_resize_##type(struct stack_##type* var, size_t newAllocationCount); \
    void stack_push_##type(struct stack_##type* var, type entry); \
    type stack_pop_##type(struct stack_##type* var); \
    type stack_peek_##type(struct stack_##type* var); \
    int stack_isEmpty_##type();

#define declare_stack(type) \
    void stack_createDest_##type(struct stack_##type* dest){ \
        dest->allocatedCount = 1; \
        dest->usedCount = 0; \
        dest->data = malloc(sizeof(type) * dest->allocatedCount); \
        if (!dest->data){ \
            perror("Error allocating memory for stack!"); \
            abort(); \
        } \
    } \
    struct stack_##type stack_create_##type(){ \
        struct stack_##type output; \
        stack_createDest_##type(&output); \
        return output; \
    } \
    void stack_free_##type(struct stack_##type* var){ \
        free(var->data); \
        var->data = NULL; \
        var->allocatedCount; \
    } \
    void stack_resize_##type(struct stack_##type* var, size_t newAllocationCount){ \
        var->allocatedCount = newAllocationCount; \
        var->data = realloc(var->data, sizeof(type) * var->allocatedCount); \
        if (!var->data && var->allocatedCount != 0){ \
            perror("Error reallocating memory for stack!"); \
            abort(); \
        } \
        if (var->usedCount > var->allocatedCount){ \
            var->usedCount = var->allocatedCount; \
        } \
    } \
    void stack_push_##type(struct stack_##type* var, type entry){ \
        if (var->usedCount >= var->allocatedCount) stack_resize_##type(var, max(1, var->usedCount << 1)); \
        var->data[++var->usedCount] = entry; \
    } \
    type stack_pop_##type(struct stack_##type* var){ \
        return var->data[var->usedCount--]; \
    } \
    type stack_peek_##type(struct stack_##type* var){ \
        return var->data[var->usedCount]; \
    } \
    int stack_isEmpty_##type(struct stack_##type* var){ \
        return var->usedCount <= 0; \
    }

#endif //__STACK__
