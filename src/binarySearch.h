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

#ifndef __BINARY_SEARCH__
#define __BINARY_SEARCH__

#include <stddef.h>

size_t binarySearch(void* array, const size_t count, const size_t elementSize, int (* compar)(const void *, const void *), const void* value);

#endif //__BINARY_SEARCH__
