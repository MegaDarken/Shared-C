//Source: https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html
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
extern "C"
#endif //__cplusplus
void disableRawMode()
{
#ifdef _WIN32 //_WIN16 ||

#else //_WIN16 || _WIN32
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
#endif //_WIN16 || _WIN32
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
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

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
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

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
int rawRead()
{
  int c = 0;
  rawReadBuffer(&c, 2);

  return c;
}

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
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

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
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

// int main(int argc, char** argv)
// {
//     //rawRead(27);//27 is Esc
// }
