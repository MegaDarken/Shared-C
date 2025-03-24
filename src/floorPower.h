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

#ifndef __FLOOR_POWER__
#define __FLOOR_POWER__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

__UINT8_TYPE__ floorPower_two_ui8(__UINT8_TYPE__ x);
__UINT16_TYPE__ floorPower_two_ui16(__UINT16_TYPE__ x);
__UINT64_TYPE__ floorPower_two_ui32(__UINT32_TYPE__ x);
__UINT64_TYPE__ floorPower_two_ui64(__UINT64_TYPE__ x);

__INT8_TYPE__ floorPower_two_i8(__INT8_TYPE__ x);
__INT16_TYPE__ floorPower_two_i16(__INT16_TYPE__ x);
__INT64_TYPE__ floorPower_two_i32(__INT32_TYPE__ x);
__INT64_TYPE__ floorPower_two_i64(__INT64_TYPE__ x);

#define floorPower_two(x) _Generic(x, \
    __UINT8_TYPE__: floorPower_two_ui8(x), \
    __UINT16_TYPE__: floorPower_two_ui16(x), \
    __UINT32_TYPE__: floorPower_two_ui32(x), \
    __UINT64_TYPE__: floorPower_two_ui64(x), \
    __INT8_TYPE__: floorPower_two_i8(x), \
    __INT16_TYPE__: floorPower_two_i16(x), \
    __INT32_TYPE__: floorPower_two_i32(x), \
    __INT64_TYPE__: floorPower_two_i64(x), \
)

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__FLOOR_POWER__
