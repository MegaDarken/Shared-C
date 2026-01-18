
#include "fuzzyD.h"

#include <stddef.h>
#include <math.h>

#include "mathUtility.h"

// https://en.wikipedia.org/wiki/Machine_epsilon#How_to_determine_machine_epsilon

typedef union {
  __INT64_TYPE__ integer;
  double floating;
} doubleInteger;

double fuzzyD_epsilon(const double value)
{
    doubleInteger u;
    u.floating = value;
    u.integer++;
    return (u.integer < 0 ? value - u.floating : u.floating - value);
}

int fuzzyD_isInteger_epsilon(const double value, const double epsilon)
{
    return abs(fmod(value, 1.0)) < epsilon;
}

int fuzzyD_isInteger(const double value)
{
    fuzzyD_isInteger_epsilon(value, fuzzyD_epsilon(value));
}

int fuzzyD_equals_epsilon(const double a, const double b, const double epsilon)
{
    return abs(a - b) < epsilon;
}

int fuzzyD_equals(const double a, const double b)
{
    fuzzyD_equals_epsilon(a, b, fuzzyD_epsilon(absMax(a, b)));
}
