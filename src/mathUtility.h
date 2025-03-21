#ifndef MATH_UTILITY_
#define MATH_UTILITY_

#include "abs.h"

#undef max
#define max(a,b) \
    ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; })

#undef min
#define min(a,b) \
    ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a < _b ? _a : _b; })


#undef absMax
#define absMax(a,b) \
    ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    abs(_a) > abs(_b) ? _a : _b; })

#undef absMin
#define absMin(a,b) \
    ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    abs(_a) < abs(_b) ? _a : _b; })

#endif //MATH_UTILITY_
