#include "valRead.h"

#include <stdio.h>

#include "clearInput.h"

#define VALREAD_BUFFERSIZE 256

void valRead_charDest(char *dest, const char *invalidInputText)
{
    for (;;)
    {
        int result = scanf(" %c", dest);

        if (result == 1) return;
        else
        {
            printf("%s", invalidInputText);
            clearInput_untilNewLine();
        }
    }
}

char valRead_char(const char *invalidInputText)
{
    char output;
    valRead_charDest(&output, invalidInputText); 
    return output;
}

void valRead_wcharDest(int *dest, const char *invalidInputText)
{
    for (;;)
    {
        int result = scanf(" %c", (char*)dest);

        if (result == 1) return;
        else
        {
            printf("%s", invalidInputText);
            clearInput_untilNewLine();
        }
    }
}

int valRead_wchar(const char *invalidInputText)
{
    int output;
    valRead_wcharDest(&output, invalidInputText); 
    return output;
}

void valRead_intDest(int *dest, const char *invalidInputText)
{
    for (;;)
    {
        int result = scanf(" %d", dest);

        if (result == 1) return;
        else
        {
            printf("%s", invalidInputText);
            clearInput_untilNewLine();
        }
    }
}

int valRead_int(const char *invalidInputText)
{
    int output;
    valRead_intDest(&output, invalidInputText); 
    return output;
}

void valRead_size_tDest(size_t *dest, const char *invalidInputText)
{
    for (;;)
    {
        int result = scanf(" %zu", dest);

        if (result == 1) return;
        else
        {
            printf("%s", invalidInputText);
            clearInput_untilNewLine();
        }
    }
}

size_t valRead_size_t(const char *invalidInputText)
{
    int output;
    valRead_intDest(&output, invalidInputText); 
    return output;
}