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

#include "consoleProcessing.h"

#include <stdio.h>

#ifdef _WIN32 //_WIN16 ||

#include <windows.h>

HANDLE consoleOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
int initalConsoleAttributes = GetConsoleScreenBufferInfo(consoleOutputHandle);
unsigned char ansiColor_initStatus = 0;

#endif //_WIN16 || _WIN32

void consoleProcessing_init()
{
    #ifdef _WIN32 //_WIN16 ||

    DWORD dwordMode;

    GetConsoleMode(consoleOutputHandle, &dwordMode);
    
    dwordMode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if (!SetConsoleMode(consoleOutputHandle, dwordMode))
    {
        printf("SetConsoleMode failed. Expect ");
        return;
    }

    ansiColor_initStatus = 1;

    #endif //_WIN16 || _WIN32
}

void consoleProcessing_reset()
{
    #ifdef _WIN32 //_WIN16 ||

    if (ansiColor_initStatus == 0) return;

    #endif //_WIN16 || _WIN32

    printf("\033[%um", 0);

    #ifdef _WIN32 //_WIN16 ||

    SetConsoleTextAttribute(consoleOutputHandle, initalConsoleAttributes);

    #endif //_WIN16 || _WIN32
}
