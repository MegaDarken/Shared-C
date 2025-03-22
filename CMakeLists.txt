# Copyright (C) 2025 Joseph Swales
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#         http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required( VERSION 3.15 )

project( Shared-C 
    VERSION 0.0.1
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)

set(SHAREDC_BUILD)

option(SHAREDC_SHARED "Shared build" ON)
option(SHAREDC_STATIC "Static build" OFF)

if(CMAKE_SYSTEM_NAME STREQUAL WASI)
  set(SHAREDC_STATIC ON CACHE BOOL "Static option" FORCE)
  set(SHAREDC_SHARED OFF CACHE BOOL "Shared option" FORCE)
endif()

if(NOT SHAREDC_STATIC AND SHAREDC_SHARED)
  set(SHAREDC_BUILD SHARED)
else(SHAREDC_STATIC)
  set(SHAREDC_BUILD STATIC)
endif()

add_library(${PROJECT_NAME}
    ${SHAREDC_BUILD}
    src/abs.h
    src/characterSet.c
    src/characterSet.h
    src/fileUtility.c
    src/fileUtility.h
    src/mathUtility.h
    src/rawRead.c
    src/rawRead.h
    src/reverse.h
    src/spansUtility.h
    src/stringConstexpr.h
    src/stringHash.h
    src/swapping.h
)