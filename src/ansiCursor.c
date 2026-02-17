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

#include "ansiCursor.h"

//Direction
void ansiCursor_fup(FILE *stream, const unsigned int val)
{
    fprintf(stream, "\033[%uA", val);
}

void ansiCursor_fdown(FILE *stream, const unsigned int val)
{
    fprintf(stream, "\033[%uB", val);
}

void ansiCursor_fforward(FILE *stream, const unsigned int val)
{
    fprintf(stream, "\033[%uC", val);
}

void ansiCursor_fback(FILE *stream, const unsigned int val)
{
    fprintf(stream, "\033[%uD", val);
}

//Line
void ansiCursor_fnextLine(FILE *stream, const unsigned int val)
{
    fprintf(stream, "\033[%uE", val);
}

void ansiCursor_fpreviousLine(FILE *stream, const unsigned int val)
{
    fprintf(stream, "\033[%uF", val);
}

void ansiCursor_fcolumn(FILE *stream, const unsigned int val)
{
    fprintf(stream, "\033[%uG", val);
}

//Position
void ansiCursor_fpositionHorizontal(FILE *stream, const unsigned int position)
{
    fprintf(stream, "\033[%uG", position);
}

void ansiCursor_fposition(FILE *stream, const unsigned int horizontal, const unsigned int vertical)
{
    fprintf(stream, "\033[%u;%uH", horizontal, vertical);
}

void ansiCursor_fhvPosition(FILE *stream, const unsigned int horizontal, const unsigned int vertical)
{
    fprintf(stream, "\033[%u;%uf", horizontal, vertical);
}

//Saving
void ansiCursor_fsavePosition(FILE *stream)
{
    fprintf(stream, "\033[s");
}

void ansiCursor_frestorePosition(FILE *stream)
{
    fprintf(stream, "\033[u");
}

