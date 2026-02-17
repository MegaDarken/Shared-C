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

#ifndef __ANSI_CURSOR__
#define __ANSI_CURSOR__

#include <stdio.h>

//Direction
void ansiCursor_fup(FILE *stream, const unsigned int val);
#define ansiCursor_up(val) ansiCursor_fup(stdout, val)

void ansiCursor_fdown(FILE *stream, const unsigned int val);
#define ansiCursor_down(val) ansiCursor_fdown(stdout, val)

void ansiCursor_fforward(FILE *stream, const unsigned int val);
#define ansiCursor_forward(val) ansiCursor_fforward(stdout, val)

void ansiCursor_fback(FILE *stream, const unsigned int val);
#define ansiCursor_back(val) ansiCursor_fback(stdout, val)

//Line
void ansiCursor_fnextLine(FILE *stream, const unsigned int val);
#define ansiCursor_nextLine(val) ansiCursor_fnextLine(stdout, val)

void ansiCursor_fpreviousLine(FILE *stream, const unsigned int val);
#define ansiCursor_previousLine(val) ansiCursor_fpreviousLine(stdout, val)

void ansiCursor_fcolumn(FILE *stream, const unsigned int val);
#define ansiCursor_column(val) ansiCursor_fcolumn(stdout, val)

//Position
void ansiCursor_fpositionHorizontal(FILE *stream, const unsigned int position);
#define ansiCursor_positionHorizontal(position) ansiCursor_fpositionHorizontal(stdout, position)

void ansiCursor_fposition(FILE *stream, const unsigned int horizontal, const unsigned int vertical);
#define ansiCursor_position(horizontal, vertical) ansiCursor_fposition(stdout, horizontal, vertical)

void ansiCursor_fhvPosition(FILE *stream, const unsigned int horizontal, const unsigned int vertical);
#define ansiCursor_hvPosition(horizontal, vertical) ansiCursor_fhvPosition(stdout, horizontal, vertical)

//Saving
void ansiCursor_fsavePosition(FILE *stream);
#define ansiCursor_savePosition() ansiCursor_fsavePosition(stdout)

void ansiCursor_frestorePosition(FILE *stream);
#define ansiCursor_restorePosition() ansiCursor_frestorePosition(stdout)

#endif //__ANSI_CURSOR__
