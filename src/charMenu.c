#include "charMenu.h"

#include "rawRead.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void charMenu_present(const int optionCount, char options[optionCount], char **messages)
{
    for (int i = 0; i < optionCount; i++)
    {
        putchar(options[i]);
        printf("%s", messages[i]);
        printf("\n");
    }
}

int charMenu_choice(const int optionCount, char options[optionCount])
{
    unsigned char input = rawRead();

    for (int i = 0; i < optionCount; i++)
    {
        if (options[i] == input)
        {
            return i;
        }
    }
    
    return -1;
}

int charMenu_presentChoice(const int optionCount, char options[optionCount], char **messages)
{
    charMenu_present(optionCount, options, messages);
    return charMenu_choice(optionCount, options);
}
