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

#ifndef __RAW_READ__
#define __RAW_READ__

#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

void disableRawMode();
void enableRawMode();
ssize_t rawReadBuffer(void* array, ssize_t count);
int rawRead();
void rawReadLoop(const int escape);
char rawReadBool(const int trueChar, const int falseChar);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__RAW_READ__
