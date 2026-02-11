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

set(CMAKE_C_STANDARD 99)

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
src/hashTable/charArrayHashTable.c
src/hashTable/charArrayHashTable.h
src/hashTable/hashTable.c
src/hashTable/hashTable.h
src/hashTable/hashTableEntry.c
src/hashTable/hashTableEntry.h
    src/abs.h
    src/ansiColor.c
    src/ansiColor.h
    src/ansiCursor.c
    src/ansiCursor.h
    src/arrayCheck.h
    src/arrayMathUtility.h
    src/arrayPrint.c
    src/arrayPrint.h
    src/binarySearch.c
    src/binarySearch.h
    src/binarySort.c
    src/binarySort.h
    src/blockPrint.c
    src/blockPrint.h
    src/boxDrawing.c
    src/boxDrawing.h
    src/characterSet.c
    src/characterSet.h
    src/charArray_substringUtility.c
    src/charArray_substringUtility.h
    src/charArray.c
    src/charArray.h
    src/charMenu.c
    src/charMenu.h
    src/clamp.c
    src/clamp.h
    src/clearInput.c
    src/clearInput.h
    src/consoleProcessing.c
    src/consoleProcessing.h
    src/digits.c
    src/digits.h
    src/fileCharArray.c
    src/fileCharArray.c
    src/fileUtility.c
    src/fileUtility.h
    src/floorPower.c
    src/floorPower.h
    src/fuzzyD.c
    src/fuzzyD.h
    src/heapSort.c
    src/heapSort.h
    src/insertionSort.c
    src/insertionSort.h
    src/linearInterpolation.c
    src/linearInterpolation.h
    src/loopUtility.h
    src/mathUtility.h
    src/memMacro.h
    src/merge.c
    src/merge.h
    src/mergeSort.c
    src/mergeSort.h
    src/midpoint.c
    src/midpoint.h
    src/rawRead.c
    src/rawRead.h
    src/reverse.c
    src/reverse.h
    src/rotate.h
    src/smoothstep.h
    src/smoothstep.h
    src/spansUtility.h
    src/stringConstexpr.h
    src/stringHash.h
    src/substringUtility.c
    src/substringUtility.h
    src/swapping.h
    src/typeUtility.h
    src/valRead.c
    src/valRead.h
)