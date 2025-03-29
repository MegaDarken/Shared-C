#ifndef LOOP_UTILITY_
#define LOOP_UTILITY_

#define loop_each(count, expression) \
    for ( size_t _index = 0; _index < count; _index++ ) { \
        expression; \
    }

#define loop_eachDescending(count, expression) \
    for ( size_t _index = count - 1; _index >= 0 ; _index-- ) { \
        expression; \
    }

#define loop_checkEach(count, check, expression) \
    for ( size_t _index = 0; _index < count; _index++ ) { \
        if (check) { \
            expression; \
        } \
    }

#define loop_checkEachDescending(count, check, expression) \
    for ( size_t _index = count - 1; _index >= 0 ; _index-- ) { \
        if (check) { \
            expression; \
        } \
    }

#define loop_checkBreakEach(count, check, expression) \
    for ( size_t _index = 0; _index < count; _index++ ) { \
        if (check) { \
            expression; \
            break; \
        } \
    }

#define loop_checkBreakEachDescending(count, check, expression) \
    for ( size_t _index = count - 1; _index >= 0 ; _index-- ) { \
        if (check) { \
            expression; \
            break; \
        } \
    } \

#endif //LOOP_UTILITY_