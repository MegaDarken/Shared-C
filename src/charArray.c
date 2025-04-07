//Imports
#include "charArray.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>

#include "loopUtility.h"
#include "stringConstexpr.h"
#include "stringHash.h"
#include "arrayCheck.h"
#include "mathUtility.h"

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

size_t allocatedCharArrayCount = 0;

//Methods
void charArray_createDest(struct charArray *dest)
{
    dest->size = sizeof(char) * dest->count;

    dest->array = malloc(dest->size);

    if (!dest->array)
    {
        perror("Error allocating memory for array!");
        abort();
    }

    allocatedCharArrayCount++;
}

void charArray_createDestWithInitialValue(struct charArray *dest, const char initialValue)
{
    charArray_createDest(dest);
    
    charArray_setAll(dest, initialValue);
}

struct charArray charArray_createWithInitialValue(const size_t count, const char initialValue)
{
    struct charArray val = { .count = count };

    charArray_createDestWithInitialValue(&val, initialValue);

    return val;
}

struct charArray charArray_create(const size_t count)
{
    struct charArray val = { .count = count };

    charArray_createDest(&val);

    return val;
}

struct charArray charArray_createFromString(const char *array)
{
    struct charArray val = charArray_create(1);

    charArray_setFromString(&val, array);

    return val;
}

void charArray_setAll(struct charArray *var, const char value)
{
    memset(var->array, value, var->size);
}

void charArray_set(struct charArray *var, const char *array, const size_t count)
{
    charArray_resize(var, count);

    memcpy(var->array, array, count);
}

void charArray_setFromString(struct charArray *var, const char *array)
{
    charArray_set(var, array, stringConstexpr_length(array));
}

void charArray_resize(struct charArray *var, const size_t count)
{
    var->count = count;

    var->size = sizeof(char) * var->count;

    var->array = realloc(var->array, var->size);

    if (!var->array)
    {
        perror("Error reallocating memory for array!");
        abort();
    }
}

void charArray_free(struct charArray *var)
{
    var->count = 0;
    var->size = 0;

    free(var->array);

    allocatedCharArrayCount--;
}

void charArray_copy(struct charArray *dest, const struct charArray *src)
{
    charArray_resize(dest, src->count);

    memcpy(dest->array, src->array, src->size);
}

struct charArray charArray_clone(const struct charArray *var)
{
    struct charArray val = charArray_create(var->count);

    memcpy(val.array, var->array, var->size);

    return val;
}

int charArray_equals(const struct charArray *first, const struct charArray *second)
{
    if (first->count != second->count) return 0;
    if (first->size != second->size) return 0;

    for (size_t i = 0; i < first->count; i++)
    {
        if (first->array[i] != second->array[i]) return 0;
    }

    return 1;
}

int charArray_contains(const struct charArray *var, const char value)
{
    for (size_t i = 0; i < var->count; i++)
    {
        if (var->array[i] == value)
        {
            return 1;
        }
    }
    
    return 0;
}

int charArray_containsBw(const struct charArray *var, const char value)
{
    for (size_t i = var->count - 1; i >= 0; i--)
    {
        if (var->array[i] == value)
        {
            return 1;
        }
    }
    
    return 0;
}

size_t charArray_hash(const struct charArray *var)
{
    return stringHash(var->array, var->size);
}

size_t charArray_indicesOfValue(const struct charArray *var, size_t *buffer, const size_t bufferCount, const char value)
{
    size_t count = 0;

    for (size_t i = 0; i < var->count && count < bufferCount; i++)
    {
        if (var->array[i] == value)
        {
            buffer[count] = i;

            count++;
        }
    }
    
    return count;
}

void charArray_resizeToString(struct charArray *var)
{
    charArray_resize(var, stringConstexpr_length(var->array));
}

void charArray_resizeStringToLastInstance(struct charArray *var, int ch)
{
    const char * chPtr = strrchr(var->array, ch);

    if (chPtr != NULL)
    {
        size_t newSize = (chPtr - var->array) + 1;
        
        if (newSize <= var->size)
        {
            charArray_resize(var, newSize/sizeof(char));
            var->array[var->count-1] = '\0';
        } 
    }
}

void charArray_catString(struct charArray *var, const char *string)
{
    if(!charArray_containsBw(var, '\0')) return;

    size_t newCount = var->count + stringConstexpr_length(string) - 1;

    charArray_resize(var, newCount);

    strcat(var->array, string);
}

void charArray_catStringCA(struct charArray *var, struct charArray *other)
{
    if(!charArray_containsBw(var, '\0')) return;
    if(!charArray_containsBw(other, '\0')) return;

    size_t newCount = var->count + other->count - 1;

    charArray_resize(var, newCount);

    strcat(var->array, other->array);
}

void charArray_tolower(struct charArray *var)
{
    for (size_t i = 0; i < var->count; i++)
    {
        var->array[i] = tolower(var->array[i]);
    }
}

void charArray_toupper(struct charArray *var)
{
    for (size_t i = 0; i < var->count; i++)
    {
        var->array[i] = toupper(var->array[i]);
    }
}

void charArray_trimspace(struct charArray *var)
{
    size_t startIndex = 0;
    size_t endIndex = var->count - 1;

    loop_checkBreakEach(var->count, !isspace(var->array[_index]), startIndex = _index);
    loop_checkBreakEachDescending(var->count, !isspace(var->array[_index]), endIndex = _index);
    
    if (startIndex > 0)
    {
        for (size_t i = 0; i < endIndex - startIndex; i++)
        {
            var->array[i] = var->array[i + startIndex];
        }
    }
    else if (endIndex == (var->count - 1))
    {
        return;
    }
    
    charArray_resize(var, endIndex - startIndex);
}

void charArray_removespace(struct charArray *var)
{
    size_t toIndex = 0;
    for (size_t fromIndex = 0; fromIndex < var->count; fromIndex++)
    {
        if (!isspace(var->array[fromIndex]))
        {
            var->array[toIndex] = var->array[fromIndex];
            toIndex++;
        }
    }
    charArray_resize(var, toIndex);
}

void charArray_uniqueValuesDest(struct charArray *dest, struct charArray *var)
{
    char uniqueValues[var->count];

    size_t uniqueValueCount = 0;

    for (size_t i = 0; i < var->count; i++)
    {
        char value = var->array[i];

        if (!array_contains(uniqueValues, uniqueValueCount, value))
        {
            uniqueValues[uniqueValueCount] = value;
            uniqueValueCount++;
        }
    }
    
    charArray_set(dest, uniqueValues, uniqueValueCount);
}

size_t charArray_uniqueValuesCount(struct charArray *var)
{
    char uniqueValues[var->count];

    size_t uniqueValueCount = 0;

    for (size_t i = 0; i < var->count; i++)
    {
        char value = var->array[i];

        if (!array_contains(uniqueValues, uniqueValueCount, value))
        {
            uniqueValues[uniqueValueCount] = value;
            uniqueValueCount++;
        }
    }
    
    return uniqueValueCount;
}

void charArray_intersectionValuesDest(struct charArray *dest, struct charArray *first, struct charArray *second)
{
    int maxCount = max(first->count, second->count);

    struct charArray firstUnique = charArray_create(maxCount);
    struct charArray secondUnique = charArray_create(maxCount);

    charArray_uniqueValuesDest(&firstUnique, first);
    charArray_uniqueValuesDest(&secondUnique, second);

    char values[maxCount];
    size_t valueCount = 0;

    for (size_t i = 0; i < firstUnique.count; i++)
    {
        char value = firstUnique.array[i];

        if (array_contains(secondUnique.array, secondUnique.count, value))
        {
            values[valueCount] = value;
            valueCount++;
        }
    }

    charArray_set(dest, values, valueCount);

    charArray_free(&firstUnique);
    charArray_free(&secondUnique);
}

void charArray_write(FILE* filePointer, struct charArray *var)
{
    size_t size = 0;
    size += fwrite(&var->count, sizeof(var->count), 1, filePointer);
    size += fwrite(&var->size, sizeof(var->size), 1, filePointer);
    size += fwrite(var->array, sizeof(var->array[0]), var->count, filePointer);
    if ( size != sizeof(struct charArray) ) printf("Mis-size from charArray fwrite");
}

void charArray_readDest(FILE* filePointer, struct charArray *var)
{
    size_t size = 0;
    size += fread(&var->count, sizeof(var->count), 1, filePointer);
    size += fread(&var->size, sizeof(var->size), 1, filePointer);
    size += fread(var->array, sizeof(var->array[0]), var->count, filePointer);
    if ( size != sizeof(struct charArray) ) printf("Mis-size from charArray fread");
}

struct charArray charArray_read(FILE* filePointer)
{
    struct charArray val = { };

    charArray_readDest(filePointer, &val);

    return val;
}

void charArray_fprint(FILE *stream, const struct charArray *var)
{
    if (var->count <= 0)
    {
        return;
    }
    
    for (size_t i = 0; i < (var->count - 1); i++)
    {
        fprintf(stream, "%u,", var->array[i]);
    }

    fprintf(stream, "%u", var->array[var->count - 1]);
}

void charArray_print(const struct charArray *var)
{
    charArray_fprint(stdout, var);
}

void charArray_fprintAsChar(FILE *stream, const struct charArray *var)
{
    fprintf(stream, "%.*s", (int)var->count, var->array);
}

void charArray_printAsChar(const struct charArray *var)
{
    charArray_fprintAsChar(stdout, var);
}

void charArray_fwprint(FILE *stream, const struct charArray *var)
{
    if (var->count <= 0)
    {
        return;
    }

    for (size_t i = 0; i < (var->count - 1); i++)
    {
        fwprintf(stream, L"%u,", var->array[i]);
    }

    fwprintf(stream, L"%u", var->array[var->count - 1]);
}

void charArray_wprint(const struct charArray *var)
{
    charArray_fwprint(stdout, var);
}

void charArray_fwprintAsChar(FILE *stream, const struct charArray *var)
{
    fwprintf(stream, L"%.*hs", (int)var->count, var->array);
}

void charArray_wprintAsChar(const struct charArray *var)
{
    charArray_fwprintAsChar(stdout, var);
}

int charArray_comparCount(const void * a, const void * b)
{
    const struct charArray *arg1 = (const struct charArray *)a;
    const struct charArray *arg2 = (const struct charArray *)b;

    return arg1->count - arg2->count;
}

int charArray_comparCountDesc(const void * a, const void * b)
{
    const struct charArray *arg1 = (const struct charArray *)a;
    const struct charArray *arg2 = (const struct charArray *)b;

    return arg2->count - arg1->count;
}

#ifdef __cplusplus
}
#endif //__cplusplus
