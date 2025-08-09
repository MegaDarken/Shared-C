#include "hashTableEntry.h"

#include <string.h>

struct hashTableEntry* hashTableEntry_createSize(const char *key, size_t keySize, void *value, size_t valueSize, struct hashTableEntry *next)
{
    struct hashTableEntry* val = malloc(sizeof(struct hashTableEntry));

    if (!val)
    {
        perror("Error allocating memory for hashTableEntry!");
        abort();
    }

    memset(val, 0, sizeof(struct hashTableEntry));
    
    charArray_set(&val->key, key, keySize);
    val->valueSize = valueSize;
    val->next = next;

    val->value = malloc(valueSize);

    if (!val->value)
    {
        perror("Error allocating memory for hashTableEntry value!");
        abort();
    }

    memcpy(val->value, value, val->valueSize);

    return val;
}

void hashTableEntry_free(struct hashTableEntry *var)
{
    charArray_free(&var->key);
    free(var->value);
    //var->valueSize = 0;
    free(var);
}

int hashTableEntry_freeEntryChain(struct hashTableEntry *var)
{
    int freedCount = 0;

    struct hashTableEntry *currentHashTableEntry = var;

    for (size_t i = 0; currentHashTableEntry != NULL && i < 1024; i++)
    {
        struct hashTableEntry *nextHashTableEntry = currentHashTableEntry->next;

        hashTableEntry_free(currentHashTableEntry);
        currentHashTableEntry->next = NULL;
        //currentHashTableEntry->value

        freedCount++;

        currentHashTableEntry = nextHashTableEntry;
    }

    return freedCount;
}

void hashTableEntry_setValueSize(struct hashTableEntry *var, void *value, size_t valueSize)
{
    var->value = realloc(var->value, valueSize);

    if (!var->value)
    {
        perror("Error reallocating memory for hashTableEntry!");
        abort();
    }

    memcpy(var->value, value, var->valueSize);
}

struct hashTableEntry *hashTableEntry_ejectNext(struct hashTableEntry *var)
{
    if (var->next == NULL) return NULL;

    struct hashTableEntry *oldNext = var->next;
    var->next = oldNext->next;

    return oldNext;
}

void hashTableEntry_addEntryToTail(struct hashTableEntry *var, struct hashTableEntry *newEntry)
{
    struct hashTableEntry *currentEntry = var;

    for (;;)
    {
        if (currentEntry->next == NULL)
        {
            currentEntry->next = newEntry;
            return;
        }
        
        currentEntry = currentEntry->next;
    }
}