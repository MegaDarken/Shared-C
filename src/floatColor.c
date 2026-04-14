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

#include "floatColor.h"

float floatColor_fromByte(const unsigned char value, const float lower, const float upper)
{
    return ((float)value / 255) * (upper - lower) + lower;
}

unsigned char floatColor_toByte(const float value, const float lower, const float upper)
{
    return (value - lower) * 255 / (upper - lower);
}

float floatColor_arrayFromByte(const unsigned char* source, float* dest, const unsigned long count, const float lower, const float upper)
{
    float inverse = ((float)1 / (float)255) * (upper - lower);

    for (unsigned long i = 0; i < count; i++)
    {
        dest[i] = ((float)source[i] * inverse) + lower;
    }
}

unsigned char floatColor_arrayToByte(const float* source, unsigned char* dest, const unsigned long count, const float lower, const float upper)
{
    float inverse = (float)255 / (upper - lower);

    for (unsigned long i = 0; i < count; i++)
    {
        dest[i] = (source[i] - lower) * inverse;
    }
}

