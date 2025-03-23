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

#ifndef FILE_UTILITY_
#define FILE_UTILITY_

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

FILE* fileUtility_open(const char* filename, const char* modes);

size_t fileUtility_charBufferGet(char buffer[], size_t bufferSize, FILE* filePointer);
size_t fileUtility_charBufferGetUntil(char buffer[], size_t bufferSize, char reference, FILE* filePointer);
size_t fileUtility_charBufferGetUntilWhitespace(char buffer[], size_t bufferSize, FILE* filePointer);

size_t fileUtility_intBufferGet(int buffer[], size_t bufferSize, FILE* filePointer);
size_t fileUtility_intBufferGetUntil(int buffer[], size_t bufferSize, int reference, FILE* filePointer);
size_t fileUtility_intBufferGetUntilWhitespace(int buffer[], size_t bufferSize, FILE* filePointer);

int fileUtility_nextNonWhitespace(FILE* filePointer);
int fileUtility_nextWhitespace(FILE* filePointer);

int fileUtility_upcoming(FILE* filePointer);

int fileUtility_nextAfterComment(int reference, FILE* filePointer);
void fileUtility_afterComment(int reference, FILE* filePointer);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //FILE_UTILITY_