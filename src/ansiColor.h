#ifndef ANSI_COLOR_
#define ANSI_COLOR_

#include <stdio.h>

#define RED_FLAG 0x01
#define GREEN_FLAG 0x02
#define BLUE_FLAG 0x04
#define BRIGHT_FLAG 0x08

#define HALF_BLOCK "▀"

char ansiColor_4BitFlagsToParameter(char flags);
char ansiColor_24BitRGBCharsTo4BitFlags(unsigned char red, unsigned char green, unsigned char blue);

void ansiColor_resetStream(FILE *stream);
void ansiColor_resetConsole();

void ansiColor_setStream4Bit(FILE *stream, char flags);
void ansiColor_setStreamForeground4Bit(FILE *stream, char flags);
void ansiColor_setStreamBackground4Bit(FILE *stream, char flags);
void ansiColor_setConsole4Bit(char flags);
void ansiColor_setConsoleForeground4Bit(char flags);
void ansiColor_setConsoleBackground4Bit(char flags);

void ansiColor_setStream8BitGray(FILE *stream, unsigned char foreground, unsigned char background);
void ansiColor_setStreamForeground8BitGray(FILE *stream, unsigned char val);
void ansiColor_setStreamBackground8BitGray(FILE *stream, unsigned char val);
void ansiColor_setConsole8BitGray(unsigned char foreground, unsigned char background);
void ansiColor_setConsoleForeground8BitGray(unsigned char val);
void ansiColor_setConsoleBackground8BitGray(unsigned char val);

void ansiColor_setStream24Bit(FILE *stream, unsigned char foregroundRed, unsigned char foregroundGreen, unsigned char foregroundBlue, unsigned char backgroundRed, unsigned char backgroundGreen, unsigned char backgroundBlue);
void ansiColor_setStreamForeground24Bit(FILE *stream, unsigned char red, unsigned char green, unsigned char blue);
void ansiColor_setStreamBackground24Bit(FILE *stream, unsigned char red, unsigned char green, unsigned char blue);
void ansiColor_setConsole24Bit(unsigned char foregroundRed, unsigned char foregroundGreen, unsigned char foregroundBlue, unsigned char backgroundRed, unsigned char backgroundGreen, unsigned char backgroundBlue);
void ansiColor_setConsoleForeground24Bit(unsigned char red, unsigned char green, unsigned char blue);
void ansiColor_setConsoleBackground24Bit(unsigned char red, unsigned char green, unsigned char blue);

void ansiColor_fresetless4BitBlockPrint(FILE *stream, char flags);
void ansiColor_f4BitBlockPrint(FILE *stream, char flags);
void ansiColor_resetless4BitBlockPrint(char flags);
void ansiColor_4BitBlockPrint(char flags);

void ansiColor_fresetless8BitGrayBlockPrint(FILE *stream, unsigned char upper, unsigned char lower);
void ansiColor_f8BitGrayBlockPrint(FILE *stream, unsigned char upper, unsigned char lower);
void ansiColor_resetless8BitGrayBlockPrint(unsigned char upper, unsigned char lower);
void ansiColor_8BitGrayBlockPrint(unsigned char upper, unsigned char lower);

void ansiColor_fresetless24BitBlockPrint(FILE *stream, unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue);
void ansiColor_f24BitBlockPrint(FILE *stream, unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue);
void ansiColor_resetless24BitBlockPrint(unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue);
void ansiColor_24BitBlockPrint(unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue);

void ansiColor_fresetless4BitBlockPrintFrom24BitRGBChars(FILE *stream, unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue);
void ansiColor_f4BitBlockPrintFrom24BitRGBChars(FILE *stream, unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue);
void ansiColor_resetless4BitBlockPrintFrom24BitRGBChars(unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue);
void ansiColor_4BitBlockPrintFrom24BitRGBChars(unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue);

#endif //ANSI_COLOR_