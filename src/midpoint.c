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

#include "midpoint.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char midpoint_char(const char a, const char b)
{
    return (a + b) >> 1;
}

int midpoint_int(const int a, const int b)
{
    return (a + b) >> 1;
}

long midpoint_long(const long a, const long b)
{
    return (a + b) >> 1;
}

long long midpoint_longLong(const long long a, const long long b)
{
    return (a + b) >> 1;
}

float midpoint_float(const float a, const float b)
{
    return (a + b) * 0.5f;
}

double midpoint_double(const double a, const double b)
{
    return (a + b) * 0.5;
}

long double midpoint_longDouble(const long double a, const long double b)
{
    return (a + b) * 0.5;
}

char midpoint_4char(const char a, const char b, const char c, const char d)
{
    return (a + b + c + d) >> 2;
}

int midpoint_4int(const int a, const int b, const int c, const int d)
{
    return (a + b + c + d) >> 2;
}

long midpoint_4long(const long a, const long b, const long c, const long d)
{
    return (a + b + c + d) >> 2;
}

long long midpoint_4longLong(const long long a, const long long b, const long long c, const long long d)
{
    return (a + b + c + d) >> 2;
}

float midpoint_4float(const float a, const float b, const float c, const float d)
{
    return (a + b + c + d) * 0.25f;
}

double midpoint_4double(const double a, const double b, const double c, const double d)
{
    return (a + b + c + d) * 0.25;
}

long double midpoint_4longDouble(const long double a, const long double b, const long double c, const long double d)
{
    return (a + b + c + d) * 0.25;
}

// int main(int argc, char** argv)
// {
//     printf("%Lf\n", midpoint_longDouble(0, 1));
//     printf("%Lf\n", midpoint_longDouble(1, 10));
//     printf("%Lf\n", midpoint_longDouble(1000, 1234));
//     printf("%Lf\n", midpoint_longDouble(0.9, -3.7));
// }