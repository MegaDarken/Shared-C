#ifndef HASH_TABLE_ENTRY_
#define HASH_TABLE_ENTRY_

#include "../charArray.h"

struct hashTableEntry
{
    struct charArray key;
    void *value;
    size_t valueSize;
    struct hashTableEntry *next;
};

struct hashTableEntry* hashTableEntry_createSize(const char *key, size_t keySize, void *value, size_t valueSize, struct hashTableEntry *next);

#define hashTableEntry_create(key, valuePointer, nextPointer) \
    ({ \
        __typeof__ (key) _key = (key); \
        __typeof__ (valuePointer) _valuePointer = (valuePointer); \
        __typeof__ (nextPointer) _nextPointer = (nextPointer); \
        hashTableEntry_createSize(_key, _valuePointer, sizeof(*_valuePointer), _nextPointer); \
    })

void hashTableEntry_free(struct hashTableEntry *var);
int hashTableEntry_freeEntryChain(struct hashTableEntry *var);

void hashTableEntry_setValueSize(struct hashTableEntry *var, void *value, size_t valueSize);

#define hashTableEntry_setValue(entryPointer, valuePointer) \
    do { \
        __typeof__ (entryPointer) _entryPointer = (entryPointer); \
        __typeof__ (valuePointer) _valuePointer = (valuePointer); \
        hashTableEntry_setValueSize(_entryPointer, _valuePointer, sizeof(*_valuePointer)); \
    } while(0)

struct hashTableEntry *hashTableEntry_ejectNext(struct hashTableEntry *var);

void hashTableEntry_addEntryToTail(struct hashTableEntry *var, struct hashTableEntry *newEntry);

#endif //HASH_TABLE_ENTRY_