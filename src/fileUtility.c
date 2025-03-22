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

#include "fileUtility.h"

#include <ctype.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
FILE* fileUtility_open(const char* filename, const char* modes)
{
    FILE* filePointer = fopen(filename, modes);
    
    if (!filePointer)
    {
        fprintf(stderr, "Failed to open file: '%s'\n", filename);
        exit(1);
    }

    return filePointer;
}

size_t fileUtility_charBufferGet(char buffer[], size_t bufferSize, FILE* filePointer)
{
    for (size_t i = 0; i < bufferSize; i++)
    {
        buffer[i] = getc(filePointer);

        if (buffer[i] == EOF)
        {
            printf("EOF:%zd\n", i);

            return i + 1;
        }
    }

    return bufferSize;
}

size_t fileUtility_charBufferGetUntil(char buffer[], size_t bufferSize, char reference, FILE* filePointer)
{
    char value;

    for (size_t i = 0; i < bufferSize; i++)
    {
        value = getc(filePointer);

        buffer[i] = value;

        if (value == reference || value == EOF)
        {
            return i + 1;
        }
    }

    return bufferSize;
}

size_t fileUtility_charBufferGetUntilWhitespace(char buffer[], size_t bufferSize, FILE* filePointer)
{
    char value;

    for (size_t i = 0; i < bufferSize; i++)
    {
        value = getc(filePointer);

        buffer[i] = value;

        if (isspace(value) || value == EOF)
        {
            return i + 1;
        }
    }

    return bufferSize;
}

size_t fileUtility_intBufferGet(int buffer[], size_t bufferSize, FILE* filePointer)
{
    for (size_t i = 0; i < bufferSize; i++)
    {
        buffer[i] = getc(filePointer);

        if (buffer[i] == EOF)
        {
            printf("EOF:%zd\n", i);

            return i + 1;
        }
    }

    return bufferSize;
    
    // if (!fgets(buffer, sizeof(typeof(buffer[0])) * bufferSize, filePointer))
    // {
    //     perror("ERR: fileUtility_bufferGet threw");//filename);
    //     exit(1);
    // }
}

size_t fileUtility_intBufferGetUntil(int buffer[], size_t bufferSize, int reference, FILE* filePointer)
{
    int value;

    for (size_t i = 0; i < bufferSize; i++)
    {
        value = getc(filePointer);

        buffer[i] = value;

        if (value == reference || value == EOF)
        {
            return i + 1;
        }
    }

    return bufferSize;
}

size_t fileUtility_intBufferGetUntilWhitespace(int buffer[], size_t bufferSize, FILE* filePointer)
{
    int value;

    for (size_t i = 0; i < bufferSize; i++)
    {
        value = getc(filePointer);

        buffer[i] = value;

        if (isspace(value) || value == EOF)
        {
            return i + 1;
        }
    }

    return bufferSize;
}

int fileUtility_nextNonWhitespace(FILE* filePointer)
{
    int value;

    do
    {
        value = getc(filePointer);//fread(&value, sizeof(char), 1, filePointer);
        
    } while (isspace(value));

    return value;
}

int fileUtility_nextWhitespace(FILE* filePointer)
{
    int value;

    do
    {
        value = getc(filePointer);//fread(&value, sizeof(char), 1, filePointer);
        
    } while (!isspace(value));

    return value;
}

int fileUtility_upcoming(FILE* filePointer)
{
    int value = getc(filePointer);
    ungetc(value, filePointer);
    return value;
}

int fileUtility_nextAfterComment(int reference, FILE* filePointer)
{
    int value;

    value = getc(filePointer);

    while (value == reference)
    {
        while (getc(filePointer) != '\n') ;

        value = getc(filePointer);
    }

    return value;
}

void fileUtility_afterComment(int reference, FILE* filePointer)
{
    int value = fileUtility_nextAfterComment(reference, filePointer);
     
    ungetc(value, filePointer);
}