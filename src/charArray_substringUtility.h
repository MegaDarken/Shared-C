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

#ifndef __CHARARRAY_SUBSTRING_UTILITY__
#define __CHARARRAY_SUBSTRING_UTILITY__

#include <stddef.h>

#include "charArray.h"

size_t charArray_substringUtility_count(struct charArray *var, const char* substring, const size_t substringSize);
void charArray_substringUtility_replace(struct charArray *var, const char* foundSubstring, const size_t foundSubstringSize, const char* replacementSubstring, const size_t replacementSubstringSize);

#endif //__CHARARRAY_SUBSTRING_UTILITY__
