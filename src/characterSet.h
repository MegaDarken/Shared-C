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

#ifndef __CHARACTER_SET__
#define __CHARACTER_SET__

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#ifdef _WIN32 //_WIN16 ||
void winError_printLast();
#endif //_WIN16 || _WIN32

void characterSet_Reset();
void characterSet_UTF8();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__CHARACTER_SET__
