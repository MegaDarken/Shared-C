/*
Copyright (C) 2026 Joseph Swales

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

#ifndef __CLAMP__
#define __CLAMP__

#define CLAMP_DEFAULT_LOWER_LIMIT 0.0f
#define CLAMP_DEFAULT_UPPER_LIMIT 1.0f

#define clamp_helper(_1, _2, _3, NAME, ...) NAME

float clamp_limits(const float value, const float lowerLimit, const float upperLimit);

#define clamp_defaultLower(value, upperLimit) clamp_limits(value, CLAMP_DEFAULT_LOWER_LIMIT, upperLimit)
#define clamp_default(value) clamp_limits(value, CLAMP_DEFAULT_LOWER_LIMIT, CLAMP_DEFAULT_UPPER_LIMIT)

#define clamp(...) clamp_helper(__VA_ARGS__, clamp_limits, clamp_defaultLower, clamp_default)(__VA_ARGS__)

#endif //__CLAMP__
