#ifndef ARRAY_CHECK_
#define ARRAY_CHECK_

#define array_contains(array, arraySize, value) ({\
    char __returnValue = 0; \
    do { \
        for (size_t i = 0; i < arraySize; i++) \
        { \
            if (array[i] == value) \
            { \
                __returnValue = 1; \
                break; \
            } \
        } \
    } while(0); \
    __returnValue; \
})

#endif //ARRAY_CHECK_
