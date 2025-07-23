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

#include "substringUtility.h"

#include <string.h>

size_t substringUtility_count(const char* string, const size_t stringSize, const char* substring, const size_t substringSize)
{
    size_t output = 0;

    const char* currentPointer = string;

    while (currentPointer < (string + stringSize))
    {
        currentPointer = strstr(currentPointer, substring);

        if (currentPointer != NULL)
        {
            output++;
            currentPointer += substringSize;
        }
        else
        {
            break;
        }
        
    }
    
    return output;
}

/**
 * Presumes Var string has been allocated enough space already.
*/
size_t substringUtility_replace(char* string, const size_t stringSize, const char* foundSubstring, const size_t foundSubstringSize, const char* replacementSubstring, const size_t replacementSubstringSize)
{
    const size_t maxPossibleInstances = stringSize / foundSubstringSize;

    char* currentPointer = string;

    for (size_t i = 0; i < maxPossibleInstances; i++)
    {
        currentPointer = strstr(currentPointer, foundSubstring);

        if (currentPointer != NULL)
        {
            memmove(currentPointer + replacementSubstringSize,
            currentPointer + foundSubstringSize,
            stringSize - (foundSubstringSize + currentPointer - string));

            memcpy(currentPointer, replacementSubstring, replacementSubstringSize);

            currentPointer += replacementSubstringSize;
        }
        else
        {
            break;
        }
    }
    
}

