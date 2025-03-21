#ifndef __ABS__
#define __ABS__

#undef abs
#define abs(a) \
    ({ __typeof__ (a) _a = (a); \
    _a < 0 ? -_a : _a; })

#endif //__ABS__