#ifndef __DIGITS__
#define __DIGITS__

#ifdef __cplusplus
inline constexpr {
#endif //__cplusplus

//BASE TWO (2)

unsigned int digits_baseTwo_uint(unsigned int val);
unsigned int digits_baseTwo_ul(unsigned long val);
unsigned int digits_baseTwo_ull(unsigned long long val);

unsigned int digits_baseTwo_int(int val);
unsigned int digits_baseTwo_l(long val);
unsigned int digits_baseTwo_ll(long long val);

#define digits_baseTwo(val) _Generic((val), \
    unsigned int: digits_baseTwo_uint(val), \
    unsigned long: digits_baseTwo_ul(val), \
    unsigned long long: digits_baseTwo_ull(val) \
    int: digits_baseTwo_int(val), \
    long: digits_baseTwo_l(val), \
    long long: digits_baseTwo_ll(val) \
    )

//BASE TEN (10)

unsigned int digits_baseTen_uint(unsigned int val);
unsigned int digits_baseTen_ul(unsigned long val);
unsigned int digits_baseTen_ull(unsigned long long val);

unsigned int digits_baseTen_int(int val);
unsigned int digits_baseTen_l(long val);
unsigned int digits_baseTen_ll(long long val);

#define digits_baseTen(val) _Generic((val), \
    unsigned int: digits_baseTen_uint(val), \
    unsigned long: digits_baseTen_ul(val), \
    unsigned long long: digits_baseTen_ull(val) \
    int: digits_baseTen_int(val), \
    long: digits_baseTen_l(val), \
    long long: digits_baseTen_ll(val) \
    )

//BASE SIXTEEN (16)

unsigned int digits_baseSixteen_uint(unsigned int val);
unsigned int digits_baseSixteen_ul(unsigned long val);
unsigned int digits_baseSixteen_ull(unsigned long long val);

#define digits_baseSixteen(val) _Generic((val), \
    unsigned int: digits_baseSixteen_uint(val), \
    unsigned long: digits_baseSixteen_ul(val), \
    unsigned long long: digits_baseSixteen_ull(val) \
    )


#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__DIGITS__
