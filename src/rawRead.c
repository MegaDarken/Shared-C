/*
Copyright (C) 2025 Joseph Swales

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

//Source of Unix-like implentations: https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html
#include "rawRead.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef _WIN32 //_WIN16 ||
#include <conio.h>
#else //_WIN16 || _WIN32
#include <termios.h>

struct termios orig_termios;
#endif //_WIN16 || _WIN32

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

void disableRawMode()
{
#ifdef _WIN32 //_WIN16 ||

#else //_WIN16 || _WIN32
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
#endif //_WIN16 || _WIN32
}

void enableRawMode()
{
#ifdef _WIN32 //_WIN16 ||

#else //_WIN16 || _WIN32
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);
  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
#endif //_WIN16 || _WIN32
}

ssize_t rawReadBuffer(void* array, ssize_t count)
{
    enableRawMode();

    ssize_t result;
#ifdef _WIN32 //_WIN16 ||
    ((int*)array)[0] = getch();
    result = 1;
#else //_WIN16 || _WIN32
    result = read(STDIN_FILENO, array, count);
    if ( result != 1 )
    {
        printf("Issue with rawRead: ");

        if (iscntrl(((int*)array)[0]))
        {
            printf("%s\n", ((char*)array));
        }
        else
        {
            printf("%d ('%s')\n", ((int*)array)[0], ((char*)array));
        }
    }
#endif //_WIN16 || _WIN32

    disableRawMode();

    return result;
} 

int rawRead()
{
  int c = 0;
  rawReadBuffer(&c, 2);

  return c;
}

void rawReadLoop(const int escape)
{
    enableRawMode();

    int c = 0;

#ifdef _WIN32 //_WIN16 ||
    for (c = getch();c != escape;c = getch())
#else //_WIN16 || _WIN32
    while (read(STDIN_FILENO, &c, 2) == 1 && c != escape)
#endif //_WIN16 || _WIN32
    {
        if (iscntrl(c))
        {
            printf("%s\n", ((char*)&c));
        }
        else
        {
            printf("%d ('%s')\n", c, ((char*)&c));
        }
    }

    disableRawMode();
}

char rawReadBool(const int trueChar, const int falseChar)
{
    for (;;)
    {
        printf("(%c/%c):\n", trueChar, falseChar);
        int input = rawRead();
        if (input == trueChar) return 1;
        if (input == falseChar) return 0;
    }
}

#ifdef __cplusplus
}
#endif //__cplusplus
