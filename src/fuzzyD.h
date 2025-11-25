
#ifndef __FUZZY_D__
#define __FUZZY_D__

double fuzzyD_epsilon(const double value);
int fuzzyD_isInteger_epsilon(const double value, const double epsilon);
int fuzzyD_isInteger(const double value);
int fuzzyD_equals_epsilon(const double a, const double b, const double epsilon);
int fuzzyD_equals(const double a, const double b);

#endif //__FUZZY_D__
