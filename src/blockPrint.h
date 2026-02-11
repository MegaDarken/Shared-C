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

#ifndef __BLOCK_PRINT__
#define __BLOCK_PRINT__

void blockPrint_8BitMono_resetlessLine(const unsigned char *data, const size_t width, const size_t height, const size_t lineNumber);
void blockPrint_8BitMono_line(const unsigned char *data, const size_t width, const size_t height, const size_t lineNumber);
void blockPrint_8BitMono(const unsigned char *data, const size_t width, const size_t height);

#endif //__BLOCK_PRINT__
