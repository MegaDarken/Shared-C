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

#ifndef __MERGE_SORT__
#define __MERGE_SORT__

#include <stddef.h>

void mergeSort(void* array, const size_t count, const size_t elementSize, int (* compar)(const void *, const void *));

void mergeSort_inPlace(void* array, const size_t count, const size_t elementSize, int (* compar)(const void *, const void *));

#endif //__MERGE_SORT__
