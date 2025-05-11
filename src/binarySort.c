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

#include "binarySort.h"

#include <limits.h>

#include "mathUtility.h"
#include "digits.h"
#include "swapping.h"
#include "memMacro.h"

void binarySort_lsd(void* array, const size_t count, const size_t elementSize, int (* eval)(const void *))
{
    __UINT8_TYPE__ *buffer;
    memMacro_malloc_size(buffer, count * elementSize);
    int max = INT_MIN;

    void* highPtr = array;
    void* endPtr = array + (elementSize * count);

    for (size_t i = 0; i < count; i++)
    {
        max = max(max, eval(highPtr));
        highPtr += elementSize;
    }

    unsigned int mask = 1;
    unsigned int digits = digits_baseTwo_uint(max);

    for (size_t i = 0; i < digits; i++)
    {
        void* arrayPtr = array;
        void* lowPtr = array;
        void* bufferPtr = buffer;
        size_t lowCount = 0;
        size_t highCount = 0;

        for (size_t i = 0; i < count; i++)
        {
            if (eval(arrayPtr) & mask)
            {
                memcpy(bufferPtr, arrayPtr, elementSize);
                highCount++;
                bufferPtr += elementSize;
            }
            else
            {
                if (lowPtr != arrayPtr) memcpy(lowPtr, arrayPtr, elementSize);
                lowCount++;
                lowPtr += elementSize;
            }

            arrayPtr += elementSize;
        }
        
        if (lowCount > 0 && highCount > 0)
        {
            memcpy(lowPtr, buffer, highCount * elementSize);
        }
        
        mask = mask << 1;
        
    }

    free(buffer);
}

// void binarySort_lsd_inPlace(void* array, const size_t count, const size_t elementSize, int (* eval)(const void *))
// {
//     int max = INT_MIN;

//     void* highPtr = array;
//     void* endPtr = array + (elementSize * count);

//     for (size_t i = 0; i < count; i++)
//     {
//         max = max(max, eval(highPtr));
//         highPtr += elementSize;
//     }

//     unsigned int mask = 1;
//     unsigned int digits = digits_baseTwo_uint(max);

//     for (size_t i = 0; i < digits; i++)
//     {
//         void* lowPtr = array;
//         size_t lowCount = 0;
//         size_t highCount = 0;

//         for (size_t i = 0; i < count; i++)
//         {
//             if (eval(lowPtr) & mask)
//             {
//                 highCount++;
//             }
//             else
//             {
//                 lowCount++;
//             }

//             lowPtr += elementSize;
//         }

//         if (lowCount > 0 && highCount > 0)
//         {
//             lowPtr = array;
//             highPtr = array + (elementSize * lowCount);

//             while ( highPtr < endPtr )
//             {
//                 if (eval(lowPtr) & mask)
//                 {
//                     while (highPtr < endPtr && (eval(highPtr) & mask))
//                     {
//                         highPtr += elementSize;
//                     }

//                     if (highPtr < endPtr)
//                     {
//                         swap(lowPtr, highPtr, elementSize);
//                     }
                    
//                 }
//                 else
//                 {
//                     lowPtr += elementSize;
//                 }
                
//             }

//         }

//         printf("%u:", mask );
//         void* printPtr = array;
//         for (size_t p = 0; p < count; p++)
//         {
//             printf("%u,", (eval(printPtr) & mask));
//             printPtr += elementSize;
//         }
//         printf("\n");
//         arrayPrint_int(array, count);
//         printf("\n");

//         barDrawing_fverticalChart_int(stdout, array, count, 5);
        
//         mask = mask << 1;

//         //reverse(highPtr, highCount, elementSize);
        
//     }
    
// }

void binarySort_msd_below(void* array, const size_t count, const size_t elementSize, int (* eval)(const void *), unsigned int mask)
{
    if (mask <= 0 || count <= 1) return;

    void* lowPtr = array;
    void* highPtr = array + (elementSize * count) - elementSize;
    size_t lowCount = 0;
    size_t highCount = 0;

    while (lowPtr < highPtr)
    {
        if (eval(lowPtr) & mask)
        {
            while ((eval(highPtr) & mask) && lowPtr < highPtr)
            {
                highPtr -= elementSize;
                highCount++;
            }

            if (lowPtr < highPtr)
            {
                swap(lowPtr, highPtr, elementSize);
            }
            
        }
        else
        {
            lowPtr += elementSize;
            lowCount++;
        }
        
    }

    if (eval(lowPtr) & mask)
    {
        highCount++;
    }
    else
    {
        lowCount++;
    }

    binarySort_msd_below(array, lowCount, elementSize, eval, mask >> 1);
    binarySort_msd_below(highPtr, highCount, elementSize, eval, mask >> 1);
}

void binarySort_msd(void* array, const size_t count, const size_t elementSize, int (* eval)(const void *))
{
    int max = INT_MIN;

    void* highPtr = array;

    for (size_t i = 0; i < count; i++)
    {
        max = max(max, eval(highPtr));
        highPtr += elementSize;
    }

    unsigned int digits = digits_baseTwo_uint(max);
    unsigned int mask = 1 << (digits - 1);

    binarySort_msd_below(array, count, elementSize, eval, mask);
    
}
