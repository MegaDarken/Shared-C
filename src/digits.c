#include "digits.h"

#define DIGITS_UINT (sizeof(unsigned int) << 3)
#define DIGITS_UL (sizeof(unsigned long) << 3)
#define DIGITS_ULL (sizeof(unsigned long long) << 3)

#define DIGITS_SINT_MASK __INT_MAX__
#define DIGITS_SL_MASK __LONG_MAX__
#define DIGITS_SLL_MASK __LONG_LONG_MAX__

#ifdef __cplusplus
inline constexpr {
#endif //__cplusplus

//BASE TWO (2)

unsigned int digits_baseTwo_uint(unsigned int val)
{
    return val ? DIGITS_UINT - __builtin_clz(val) : 0;
}

unsigned int digits_baseTwo_ul(unsigned long val)
{
    return val ? DIGITS_UL - __builtin_clzl(val) : 0;
}

unsigned int digits_baseTwo_ull(unsigned long long val)
{
    return val ? DIGITS_ULL - __builtin_clzll(val) : 0;
}

unsigned int digits_baseTwo_int(int val)
{
    return digits_baseTwo_uint(val & DIGITS_SINT_MASK);
}

unsigned int digits_baseTwo_l(long val)
{
    return digits_baseTwo_ul(val & DIGITS_SL_MASK);
}

unsigned int digits_baseTwo_ll(long long val)
{
    return digits_baseTwo_ull(val & DIGITS_SLL_MASK);
}

//BASE TEN (10)

const unsigned char DIGITS_LOGTEN_POWERSOFTWO[129] = {0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 17, 17, 17, 18, 18, 18, 18, 19, 19, 19, 20, 20, 20, 21, 21, 21, 21, 22, 22, 22, 23, 23, 23, 24, 24, 24, 24, 25, 25, 25, 26, 26, 26, 27, 27, 27, 27, 28, 28, 28, 29, 29, 29, 30, 30, 30, 31, 31, 31, 31, 32, 32, 32, 33, 33, 33, 34, 34, 34, 34, 35, 35, 35, 36, 36, 36, 37, 37, 37, 37, 38, 38};
const unsigned long long DIGITS_POWERSOFTEN[20] = {1ull, 10ull, 100ull, 1000ull, 10000ull, 100000ull, 1000000ull, 10000000ull, 100000000ull, 1000000000ull, 10000000000ull, 100000000000ull, 1000000000000ull, 10000000000000ull, 100000000000000ull, 1000000000000000ull, 10000000000000000ull, 100000000000000000ull, 1000000000000000000ull, 10000000000000000000ull};

unsigned int digits_baseTen_uint(unsigned int val)
{
    unsigned int digits = DIGITS_LOGTEN_POWERSOFTWO[digits_baseTwo_uint(val)];
    return digits + (val >= DIGITS_POWERSOFTEN[digits]);
}

unsigned int digits_baseTen_ul(unsigned long val)
{
    unsigned int digits = DIGITS_LOGTEN_POWERSOFTWO[digits_baseTwo_ul(val)];
    return digits + (val >= DIGITS_POWERSOFTEN[digits]);
}

unsigned int digits_baseTen_ull(unsigned long long val)
{
    unsigned int digits = DIGITS_LOGTEN_POWERSOFTWO[digits_baseTwo_ull(val)];
    return digits + (val >= DIGITS_POWERSOFTEN[digits]);
}

unsigned int digits_baseTen_int(int val)
{
    unsigned int digits = DIGITS_LOGTEN_POWERSOFTWO[digits_baseTwo_int(val)];
    return digits + (val >= DIGITS_POWERSOFTEN[digits]);
}

unsigned int digits_baseTen_l(long val)
{
    unsigned int digits = DIGITS_LOGTEN_POWERSOFTWO[digits_baseTwo_l(val)];
    return digits + (val >= DIGITS_POWERSOFTEN[digits]);
}

unsigned int digits_baseTen_ll(long long val)
{
    unsigned int digits = DIGITS_LOGTEN_POWERSOFTWO[digits_baseTwo_ll(val)];
    return digits + (val >= DIGITS_POWERSOFTEN[digits]);
}

//BASE SIXTEEN (16)

const unsigned long long DIGITS_POWERSOFSIXTEEN[20] = {0x1ull, 0x10ull, 0x100ull, 0x1000ull, 0x10000ull, 0x100000ull, 0x1000000ull, 0x10000000ull, 0x100000000ull, 0x1000000000ull, 0x10000000000ull, 0x100000000000ull, 0x1000000000000ull, 0x10000000000000ull, 0x100000000000000ull, 0x1000000000000000ull};

unsigned int digits_baseSixteen_uint(unsigned int val)
{
    unsigned int digits = digits_baseTwo_uint(val) >> 2;
    return digits + (val >= DIGITS_POWERSOFSIXTEEN[digits]);
}

unsigned int digits_baseSixteen_ul(unsigned long val)
{
    unsigned int digits = digits_baseTwo_ul(val) >> 2;
    return digits + (val >= DIGITS_POWERSOFSIXTEEN[digits]);
}

unsigned int digits_baseSixteen_ull(unsigned long long val)
{
    unsigned int digits = digits_baseTwo_ull(val) >> 2;
    return digits + (val >= DIGITS_POWERSOFSIXTEEN[digits]);
}

#ifdef __cplusplus
}
#endif //__cplusplus
