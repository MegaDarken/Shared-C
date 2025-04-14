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

#include "boxDrawing.h"

#include <stdio.h>
#include <wchar.h>
#include <string.h>

const char boxDrawingArray[][4] = {
    " ","╴","╸","?", "╶","─","╾","?", "╺","╼","━","?", "?","?","?","═",
    "╵","┘","┙","╛", "└","┴","┵","?", "┕","┶","┷","?", "?","?","?","╧",
    "╹","┚","┛","?", "┖","┸","┹","?", "┗","┺","┻","?", "?","?","?","?",
    "?","╜","?","╝", "╙","╨","?","?", "?","?","?","?", "╚","?","?","╩",
    
    "╷","┐","┑","╕", "┌","┬","┭","?", "┍","┮","┯","?", "?","?","?","╤",
    "│","┤","┥","╡", "├","┼","┽","?", "┝","┾","┿","?", "?","?","?","╪",
    "╿","┦","┩","?", "┞","╀","╃","?", "┡","╄","╇","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",

    "╻","┒","┓","?", "┎","┰","┱","?", "┏","┲","┳","?", "?","?","?","?",
    "╽","┧","┪","?", "┟","╁","╅","?", "┢","╆","╈","?", "?","?","?","?",
    "┃","┨","┫","?", "┠","╂","╉","?", "┣","╊","╋","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",

    "?","╖","?","?", "╓","╥","?","?", "?","?","?","?", "?","?","?","╦",
    "?","?","?","╛", "?","?","?","?", "?","?","?","?", "?","?","?","╧",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","╢","?","╣", "╟","╫","?","?", "?","?","?","?", "╠","?","?","╬",
};

const char *boxDrawing_indexValue(const int index)
{
    return boxDrawingArray[index];
}

const char *boxDrawing_value(const enum boxDrawingLineType left, const enum boxDrawingLineType right, const enum boxDrawingLineType up, const enum boxDrawingLineType down)
{
    return boxDrawing_indexValue(left | (right << 2) | (up << 4) | (down << 6));
}

void boxDrawing_fprint_horizontalLine(FILE *stream, const enum boxDrawingLineType across, const enum boxDrawingLineType *up, const enum boxDrawingLineType *down, const size_t count)
{
    if (count < 1)
    {
        return;
    }

    if (count == 1)
    {
        fprintf(stream, "%s", boxDrawing_value(noLine, noLine, up[0], down[0]));
        return;
    }
    
    fprintf(stream, "%s", boxDrawing_value(noLine, across, up[0], down[0]));

    for (size_t i = 1; i < count - 1; i++)
    {
        fprintf(stream, "%s", boxDrawing_value(across, across, up[i], down[i]));
    }
    fprintf(stream, "%s", boxDrawing_value(across, noLine, up[count - 1], down[count - 1]));
    
}

void boxDrawing_print_horizontalLine(const enum boxDrawingLineType across, const enum boxDrawingLineType *up, const enum boxDrawingLineType *down, const size_t count)
{
    boxDrawing_fprint_horizontalLine(stdout, across, up, down, count);
}

void boxDrawing_fprint_intervalHorizontalLine(FILE *stream, const enum boxDrawingLineType across, const enum boxDrawingLineType up, const enum boxDrawingLineType down, const size_t verticalCount, const size_t interval)
{
    if (verticalCount < 1)
    {
        return;
    }

    if (verticalCount == 1)
    {
        fprintf(stream, "%s", boxDrawing_value(noLine, noLine, up, down));
        return;
    }

    fprintf(stream, "%s", boxDrawing_value(noLine, across, up, down));

    const char *intervalChar = boxDrawing_value(across, across, noLine, noLine);

    for (size_t i = 0; i < interval; i++)
    {
        fprintf(stream, "%s", intervalChar);
    }

    for (size_t j = 1; j < verticalCount - 1; j++)
    { 
        fprintf(stream, "%s", boxDrawing_value(across, across, up, down));

        for (size_t i = 0; i < interval; i++)
        {
            fprintf(stream, "%s", intervalChar);
        }
    }

    fprintf(stream, "%s", boxDrawing_value(across, noLine, up, down));
}

void boxDrawing_print_intervalHorizontalLine(const enum boxDrawingLineType across, const enum boxDrawingLineType up, const enum boxDrawingLineType down, const size_t verticalCount, const size_t interval)
{
    boxDrawing_fprint_intervalHorizontalLine(stdout, across, up, down, verticalCount, interval);
}