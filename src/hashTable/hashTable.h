#ifndef HASH_TABLE_
#define HASH_TABLE_

#include "../charArray.h"
#include "hashTableEntry.h"

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

typedef struct hashTable
{
    struct hashTableEntry **table;
    int entryCount;
    int currentSizePower;
} HashTable;

void hashTable_createDest(struct hashTable *dest);
struct hashTable hashTable_create(const int sizePower);
struct hashTable *hashTable_mcreate(const int sizePower);

void hashTable_free(struct hashTable *var);

#define hashTable_valueFree(hashTablePointer, freeExpression) \
    do { \
        __typeof__ (hashTablePointer) _hashTablePointer = (hashTablePointer); \
        size_t _count = hashTable_tableCount(_hashTablePointer); \
        struct hashTableEntry *_entry; \
        for (size_t _i = 0; _i < _count; _i++) { \
            _entry = _hashTablePointer->table[_i]; \
            while (_entry != NULL) { \
                freeExpression; \
                _entry = _entry->next; \
            } \
        } \
        hashTable_free(_hashTablePointer); \
    } while (0);
    
void hashTable_resize(struct hashTable *var, const int newSizePower);

size_t hashTable_tableCount(struct hashTable *var);
size_t hashTable_hash(struct hashTable *var, const char *key, size_t keySize);

//Put
void hashTable_putEntry(struct hashTable *var, struct hashTableEntry *entry);
void hashTable_putSize(struct hashTable *var, const char *key, size_t keySize, void *value, size_t valueSize);

#define hashTable_put(hashTablePointer, key, keySize, valuePointer) \
    do { \
        __typeof__ (hashTablePointer) _hashTablePointer = (hashTablePointer); \
        __typeof__ (key) _key = (key); \
        __typeof__ (keySize) _keySize = (keySize); \
        __typeof__ (valuePointer) _valuePointer = (valuePointer); \
        hashTable_putSize(_hashTablePointer, _key, _keySize, _valuePointer, sizeof(*_valuePointer)); \
    } while(0)

//Get
struct hashTableEntry *hashTable_getEntry(struct hashTable *var, const char *key, size_t keySize);
void *hashTable_get(struct hashTable *var, const char *key, size_t keySize);

//Remove
void *hashTable_remove(struct hashTable *var, const char *key, size_t keySize);

void hashTable_forEach(struct hashTable *var, void (*callback)(void *));

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //HASH_TABLE_