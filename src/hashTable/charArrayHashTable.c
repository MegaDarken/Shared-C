#include "charArrayHashTable.h"

#include <stdlib.h>

void charArrayHashTable_free(struct hashTable *var)
{
    hashTable_valueFree( var, charArray_free((struct charArray*) _entry->value) );
}