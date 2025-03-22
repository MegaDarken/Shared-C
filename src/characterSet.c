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

#include "characterSet.h"

#include <stdio.h>

#ifdef _WIN32 //_WIN16 ||
#include <Windows.h>

UINT WINAPI originalCodePage = 0;//GetConsoleOutputCP();
#else //_WIN16 || _WIN32
#include <locale.h>
#endif //_WIN16 || _WIN32

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#ifdef _WIN32 //_WIN16 ||
/**
 * Adapted from:
 * https://stackoverflow.com/questions/1387064/how-to-get-the-error-message-from-the-error-code-returned-by-getlasterror
 * 
*/
void winError_printLast()
{
    DWORD errorMessageID = GetLastError();

    LPSTR messageBuffer = (void*)0;

    size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);
    
    printf("%.*s", (int)size, messageBuffer);
    
    LocalFree(messageBuffer);
}
#endif //_WIN16 || _WIN32

void characterSet_Reset()
{
    #ifdef _WIN32 //_WIN16 ||
    if (originalCodePage != 0 && !SetConsoleOutputCP(originalCodePage))
    {
        winError_printLast();
    }
    #else //_WIN16 || _WIN32
    setlocale(LC_ALL, "C");
    #endif //_WIN16 || _WIN32
}

void characterSet_UTF8()
{
    #ifdef _WIN32 //_WIN16 ||
    if (originalCodePage == 0)
    {
        originalCodePage = GetConsoleOutputCP();
    }

    if (!SetConsoleOutputCP(CP_UTF8))
    {
        winError_printLast();
    }
    #else //_WIN16 || _WIN32
    setlocale(LC_ALL, "C.UTF-8");
    #endif //_WIN16 || _WIN32
}

#ifdef __cplusplus
}
#endif //__cplusplus
