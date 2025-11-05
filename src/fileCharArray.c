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

#include "fileCharArray.h"

#include "fileUtility.h"

#define FILE_CHAR_ARRAY_STARTING_SIZE 0

void fileCharArray_readPointerDest(FILE* filePointer, struct charArray *var)
{
    fseek(filePointer, 0, SEEK_END);
    size_t fileSize = ftell(filePointer);
    fseek(filePointer, 0, SEEK_SET);

    charArray_resize(var, fileSize);

    fread(var->array, sizeof(var->array), fileSize, filePointer);
}

struct charArray fileCharArray_readPointer(FILE* filePointer)
{
    struct charArray output = charArray_create(FILE_CHAR_ARRAY_STARTING_SIZE);

    fileCharArray_readPointerDest(filePointer, &output);

    return output;
}
