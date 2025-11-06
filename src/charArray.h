#ifndef CHAR_ARRAY_
#define CHAR_ARRAY_

#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

typedef struct charArray
{
    size_t count;
    size_t size;
    char *array;
} CharArray;

void charArray_createDest(struct charArray *dest);
void charArray_createDestWithInitialValue(struct charArray *dest, const char initialValue);
struct charArray charArray_createWithInitialValue(const size_t count, const char initialValue);
struct charArray charArray_create(const size_t count);
struct charArray charArray_createFromString(const char *array);

void charArray_setAll(struct charArray *var, const char value);
void charArray_set(struct charArray *var, const char *array, const size_t count);
void charArray_setFromString(struct charArray *var, const char *array);

void charArray_resize(struct charArray *var, const size_t count);

void charArray_free(struct charArray *var);

void charArray_copy(struct charArray *dest, const struct charArray *src);
struct charArray charArray_clone(const struct charArray *var);

int charArray_equals(const struct charArray *first, const struct charArray *second);
int charArray_equalsc(const struct charArray *var, const char *charPointer, size_t charSize);

int charArray_isZero(const struct charArray *var);

int charArray_contains(const struct charArray *var, const char value);
int charArray_containsBw(const struct charArray *var, const char value);

size_t charArray_hash(const struct charArray *var);

size_t charArray_indicesOfValue(const struct charArray *var, size_t *buffer, const size_t bufferCount, const char value);

void charArray_resizeToString(struct charArray *var);

void charArray_resizeStringToLastInstance(struct charArray *var, int ch);

void charArray_catString(struct charArray *var, const char *string);
void charArray_catStringCA(struct charArray *var, struct charArray *other);

void charArray_tolower(struct charArray *var);
void charArray_toupper(struct charArray *var);

void charArray_trimspace(struct charArray *var);
void charArray_removespace(struct charArray *var);

void charArray_ensureNullTerminated(struct charArray* var);

void charArray_uniqueValuesDest(struct charArray *dest, struct charArray *var);
size_t charArray_uniqueValuesCount(struct charArray *var);

void charArray_intersectionValuesDest(struct charArray *dest, struct charArray *first, struct charArray *second);

void charArray_write(FILE* filePointer, struct charArray *var);

void charArray_readDest(FILE* filePointer, struct charArray *var);
struct charArray charArray_read(FILE* filePointer);

void charArray_fprint(FILE *stream, const struct charArray *var);
void charArray_print(const struct charArray *var);

void charArray_fprintAsChar(FILE *stream, const struct charArray *var);
void charArray_printAsChar(const struct charArray *var);

void charArray_fwprint(FILE *stream, const struct charArray *var);
void charArray_wprint(const struct charArray *var);

void charArray_fwprintAsChar(FILE *stream, const struct charArray *var);
void charArray_wprintAsChar(const struct charArray *var);

// void charArray_fprintAsVolume(FILE *stream, struct charArray *var);
// void charArray_printAsVolume(struct charArray *var);

int charArray_comparCount(const void * a, const void * b);
int charArray_comparCountDesc(const void * a, const void * b);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CHAR_ARRAY_
