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

#include "charArray_substringUtility.h"

#include "substringUtility.h"

size_t charArray_substringUtility_count(struct charArray *var, const char* substring, const size_t substringSize)
{
    return substringUtility_count(var->array, var->size, substring, substringSize);
}

void charArray_substringUtility_replace(struct charArray *var, const char* foundSubstring, const size_t foundSubstringSize, const char* replacementSubstring, const size_t replacementSubstringSize)
{
    size_t foundCount = charArray_substringUtility_count(var, foundSubstring, foundSubstringSize);

    if (foundCount <= 0) return;

    size_t newSize = var->size + ((replacementSubstringSize - 1) * foundCount) - ((foundSubstringSize - 1) * foundCount);

    if (foundSubstringSize < replacementSubstringSize)
    {
        charArray_resize(var, newSize);
    }

    substringUtility_replace(var->array, var->size, foundSubstring, foundSubstringSize, replacementSubstring, replacementSubstringSize);

    if (foundSubstringSize > replacementSubstringSize)
    {
        charArray_resize(var, newSize);
    }
}

