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

#include "blockPrint.h"

#include <stdlib.h>
#include <stdio.h>

#include "ansiColor.h"

void blockPrint_8BitMono_resetlessLine(const unsigned char *data, const size_t width, const size_t height, const size_t lineNumber)
{
    int x = 0;
    int y = lineNumber << 1;

    int upperIndex = y * width;

    if (lineNumber == height && height & 1)
    {
        for (; x < width; x++)
        {
            upperIndex++;

            ansiColor_setConsoleForeground8BitGray(data[upperIndex]);

            printf(HALF_BLOCK);
        }

        ansiColor_resetConsole();
        printf("\n");
    }
    else
    {
        int lowerIndex;

        for (; x < width; x++)
        {
            upperIndex++;
            lowerIndex = (upperIndex + width);

            ansiColor_resetless8BitGrayBlockPrint(data[upperIndex], data[lowerIndex]);
            
        }
    }
}

void blockPrint_8BitMono_line(const unsigned char *data, const size_t width, const size_t height, const size_t lineNumber)
{
    blockPrint_8BitMono_resetlessLine(data, width, height, lineNumber);

    ansiColor_resetConsole();
}

void blockPrint_8BitMono(const unsigned char *data, const size_t width, const size_t height)
{
    for (size_t i = 0; i < height >> 1 + (height & 1); i++)
    {
        blockPrint_8BitMono_line(data, width, height, i);

        printf("\n");
    }
}

void blockPrint_24Bit_resetlessLine(const unsigned char *data, const size_t width, const size_t height, const size_t lineNumber)
{
    int x = 0;
    int y = lineNumber << 1;

    int upperIndex = y * width * 3;

    if (lineNumber == height && height & 1)
    {
        for (; x < width; x++)
        {
            upperIndex += 3;

            ansiColor_setConsoleForeground24Bit(data[upperIndex], data[upperIndex + 1], data[upperIndex + 2]);

            printf(HALF_BLOCK);
        }

        ansiColor_resetConsole();
        printf("\n");
    }
    else
    {
        int lowerIndex = (upperIndex + (width * 3));

        for (; x < width; x++)
        {
            upperIndex += 3;
            lowerIndex += 3;

            ansiColor_resetless24BitBlockPrint(
                    data[upperIndex], data[upperIndex + 1], data[upperIndex + 2],
                    data[lowerIndex], data[lowerIndex + 1], data[lowerIndex + 2]);
        }
    }
}

void blockPrint_24Bit_line(const unsigned char *data, const size_t width, const size_t height, const size_t lineNumber)
{
    blockPrint_24Bit_resetlessLine(data, width, height, lineNumber);

    ansiColor_resetConsole();
}

void blockPrint_24Bit(const unsigned char *data, const size_t width, const size_t height)
{
    for (size_t i = 0; i < height >> 1 + (height & 1); i++)
    {
        blockPrint_24Bit_line(data, width, height, i);

        printf("\n");
    }
}
