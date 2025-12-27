#include "hashTable.h"

#include <stdlib.h>
#include <string.h>

#include "../mathUtility.h"
#include "../stringHash.h"

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

void hashTable_createDest(struct hashTable *dest)
{
    size_t count = 1 << dest->currentSizePower;

    size_t tableSize = sizeof(struct hashTableEntry*) * count;

    dest->table = malloc(tableSize);

    if (!dest->table)
    {
        perror("Error allocating memory for hashTable table!");
        abort();
    }

    //Set null
    memset(dest->table, 0, tableSize);

    dest->entryCount = 0;
}

struct hashTable hashTable_create(const int sizePower)
{
    struct hashTable var = { .currentSizePower = sizePower };

    hashTable_createDest(&var);

    return var;
}

struct hashTable *hashTable_mcreate(const int sizePower)
{
    struct hashTable* val = malloc(sizeof(struct hashTable));

    if (!val)
    {
        perror("Error allocating memory for hashTable!");
        abort();
    }

    val->currentSizePower = sizePower;

    hashTable_createDest(val);

    return val;
}

void hashTable_free(struct hashTable *var)
{
    size_t count = hashTable_tableCount(var);
    
    for (size_t i = 0; i < count; i++)
    {
        if (var->table[i] != NULL) hashTableEntry_free(var->table[i]);
    }
    
    free(var->table);
}

void hashTable_resize(struct hashTable *var, const int newSizePower)
{
    size_t oldCount = hashTable_tableCount(var);
    size_t newCount = 1 << newSizePower;

    size_t tableSize = sizeof(struct hashTableEntry*) * newCount;

    var->table = realloc(var->table, tableSize);

    if (!var->table)
    {
        perror("Error reallocating memory for hashTable table!");
        abort();
    }

    var->entryCount = min(var->entryCount, newCount);
    var->currentSizePower = newSizePower;

    memset(&var->table[oldCount], 0, tableSize >> 1);

    for (size_t i = 0; i < oldCount; i++)
    {
        struct hashTableEntry *entry = var->table[i];
        var->table[i] = NULL;

        while (entry != NULL)
        {
            struct hashTableEntry *nextEntry = entry->next;

            entry->next = NULL;
            hashTable_putEntry(var, entry);

            entry = nextEntry;
        }
        
    }

}

size_t hashTable_tableCount(struct hashTable *var)
{
    return 1 << var->currentSizePower;
}

size_t hashTable_hash(struct hashTable *var, const char *key, size_t keySize)
{
    size_t mask = (hashTable_tableCount(var)) - 1;
    return stringHash_size(key, keySize) & mask;
}



void hashTable_putEntry(struct hashTable *var, struct hashTableEntry *entry)
{
    if (var->entryCount >= hashTable_tableCount(var))
    {
        hashTable_resize(var, var->currentSizePower + 1);
    }
    
    size_t hash = hashTable_hash(var, entry->key.array, entry->key.size);
    struct hashTableEntry *gottenHashTableEntry = var->table[hash];

    if (gottenHashTableEntry == NULL)
    {
        var->table[hash] = entry;
        
        var->entryCount++;
    }
    else
    {

        for (;;) 
        {
            if (charArray_equals(&entry->key, &gottenHashTableEntry->key))
            {
                printf("Putting hashTable entry that already exists:\"");
                charArray_printAsChar(&entry->key);
                printf("\", overriding.\n");

                hashTableEntry_setValueSize(gottenHashTableEntry, entry->value, entry->valueSize);
                hashTableEntry_free(entry);

                return;
            }

            if (gottenHashTableEntry->next == NULL) break;
            
            gottenHashTableEntry = gottenHashTableEntry->next;
        }
        
        gottenHashTableEntry->next = entry;

        var->entryCount++;
    }
    
}

void hashTable_putSize(struct hashTable *var, const char *key, size_t keySize, void *value, size_t valueSize)
{
    hashTable_putEntry(var, hashTableEntry_createSize(key, keySize, value, valueSize, NULL));
}

struct hashTableEntry *hashTable_getEntry(struct hashTable *var, const char *key, size_t keySize)
{
    size_t hash = hashTable_hash(var, key, keySize);

    struct hashTableEntry *gottenHashTableEntry = var->table[hash];

    for (size_t i = 0; gottenHashTableEntry != NULL && i <= var->entryCount; i++)
    {
        if (charArray_equalsc(&gottenHashTableEntry->key, key, keySize))
        {
            return gottenHashTableEntry;
        }
        else
        {
            gottenHashTableEntry = gottenHashTableEntry->next;
        }
    }

    return NULL;
}

void *hashTable_get(struct hashTable *var, const char *key, size_t keySize)
{
    void *entry = hashTable_getEntry(var, key, keySize);
    if (entry != NULL) return ((struct hashTableEntry*)entry)->value;
    return NULL;
}

void *hashTable_remove(struct hashTable *var, const char *key, size_t keySize)
{
    size_t hash = hashTable_hash(var, key, keySize);

    struct hashTableEntry **entryPointerPointer = &var->table[hash];

    for (size_t i = 0; *entryPointerPointer != NULL && i < 1024; i++)
    {
        if (charArray_equalsc(&(*entryPointerPointer)->key, key, keySize))
        {
            struct hashTableEntry *entryPointer = *entryPointerPointer;
            void *output = entryPointer->value;

            charArray_free(&(*entryPointerPointer)->key);
            *entryPointerPointer = entryPointer->next;
            memset(entryPointer, 0, sizeof(struct hashTableEntry*));//entryPointer = NULL;//var->entries[var->entryCount];
            --var->entryCount;

            return output;
        }
        else
        {
            entryPointerPointer = &(*entryPointerPointer)->next;
        }
    }

    return NULL;
}

void hashTable_forEach(struct hashTable *var, void (*callback)(void *))
{
    size_t _count = hashTable_tableCount(var);

    struct hashTableEntry *entry;

    for (size_t i = 0; i < _count; i++)
    {
        entry = var->table[i];

        while (entry != NULL)
        {
            if (entry->value != NULL) callback(entry->value);
            entry = entry->next;
        }
    }
}

#ifdef __cplusplus
}
#endif //__cplusplus
