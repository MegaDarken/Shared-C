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

#ifndef __SUBSTRING_UTILITY__
#define __SUBSTRING_UTILITY__

#include <stddef.h>

/**
 * @param string
 * @param stringSize
 * @param substring
 * @param substringSize
 */
size_t substringUtility_count(const char* string, const size_t stringSize, const char* substring, const size_t substringSize);

/**
 * Presumes Var string has been allocated enough space already.
 * @param string
 * @param stringSize
 * @param foundSubstring
 * @param foundSubstringSize
 * @param replacementSubstring
 * @param replacementSubstringSize
*/
void substringUtility_replace(char* string, const size_t stringSize, const char* foundSubstring, const size_t foundSubstringSize, const char* replacementSubstring, const size_t replacementSubstringSize);

#endif //__SUBSTRING_UTILITY__
