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

#include "floorPower.h"

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

__UINT8_TYPE__ floorPower_two_ui8(__UINT8_TYPE__ x)
{
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    return x - (x >> 1);
}

__UINT16_TYPE__ floorPower_two_ui16(__UINT16_TYPE__ x)
{
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    return x - (x >> 1);
}

__UINT64_TYPE__ floorPower_two_ui32(__UINT32_TYPE__ x)
{
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    return x - (x >> 1);
}

__UINT64_TYPE__ floorPower_two_ui64(__UINT64_TYPE__ x)
{
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    x = x | (x >> 32);
    return x - (x >> 1);
}

__INT8_TYPE__ floorPower_two_i8(__INT8_TYPE__ x)
{
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    return x - (x >> 1);
}

__INT16_TYPE__ floorPower_two_i16(__INT16_TYPE__ x)
{
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    return x - (x >> 1);
}

__INT64_TYPE__ floorPower_two_i32(__INT32_TYPE__ x)
{
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    return x - (x >> 1);
}

__INT64_TYPE__ floorPower_two_i64(__INT64_TYPE__ x)
{
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    x = x | (x >> 32);
    return x - (x >> 1);
}

#ifdef __cplusplus
}
#endif //__cplusplus
