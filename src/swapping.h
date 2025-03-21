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

#ifndef SWAPPING_
#define SWAPPING_

#include <string.h>

#define swap_helper(_1, _2, _3, NAME, ...) NAME

#define swap_known(a,b) \
    do { \
        __typeof__ (a) _a = (a); \
        __typeof__ (b) _b = (b); \
        if (_a == _b) break; \
        unsigned char swap_temp[sizeof(*_a) == sizeof(*_b) ? (signed)sizeof(*_a) : -1]; \
        memcpy(swap_temp,_b,sizeof(*_a)); \
        memcpy(_b,_a,sizeof(*_a)); \
        memcpy(_a,swap_temp,sizeof(*_a)); \
    } while(0)

#define swap_size(a,b,size) \
    do { \
        __typeof__ (a) _a = (a); \
        __typeof__ (b) _b = (b); \
        if (_a == _b) break; \
        unsigned char swap_temp[size]; \
        memcpy(swap_temp,_b,size); \
        memcpy(_b,_a,size); \
        memcpy(_a,swap_temp,size); \
    } while(0)

#define swap(...) swap_helper(__VA_ARGS__, swap_size, swap_known)(__VA_ARGS__)

#endif //SWAPPING_