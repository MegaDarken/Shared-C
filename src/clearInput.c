#include "clearInput.h"

#include <stdio.h>

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void clearInput_until(const int val)
{
    for (int ch = getchar(); ch != EOF && ch != val;ch = getchar());
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void clearInput_untilNewLine()
{
    clearInput_until('\n');
}
