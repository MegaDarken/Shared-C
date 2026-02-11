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

#ifndef __FLOAT_COLOR__
#define __FLOAT_COLOR__

float floatColor_fromByte(const unsigned char value, const float lower, const float upper);
unsigned char floatColor_toByte(const float value, const float lower, const float upper);

#endif //__FLOAT_COLOR__
