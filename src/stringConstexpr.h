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

#ifndef __STRING_CONSTEXPR__
#define __STRING_CONSTEXPR__

#include <stddef.h>

// #ifdef __cplusplus
// extern "C" {
// #endif //__cplusplus

#ifdef __cplusplus
inline constexpr
#endif //__cplusplus
size_t stringConstexpr_length(const char* string)
{
    const char* character = string;
    for (; *character; ++character);
    return(character - string);
}

#define stringMacro_length(string) \
    ({ const char* _string = string; \
    const char* _character = _string; \
    for (; *_character; ++_character); \
    (_character - _string); })

#ifdef __cplusplus
inline constexpr
#endif //__cplusplus
size_t stringConstexpr_match(const char* string, const char match)
{
    const char* character = string;
    for (; *character == match; ++character);
    return(character - string);
}

#define stringMacro_match(string, match) \
    ({ const char* _string = string; \
    const char _match = match; \
    const char* _character = _string; \
    for (; *_character == _match; ++_character); \
    (_character - _string); })

// #ifdef __cplusplus
// }
// #endif //__cplusplus

#endif //__STRING_CONSTEXPR__
