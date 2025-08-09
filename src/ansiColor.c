#include "ansiColor.h"

#include <stdio.h>

char ansiColor_4BitFlagsToParameter(char flags)
{
    return 30 + (flags & 0x7) + (flags & BRIGHT_FLAG ? 60 : 0);
}

char ansiColor_24BitRGBCharsTo4BitFlags(unsigned char red, unsigned char green, unsigned char blue)
{
    return 0 + (red & 0xC0 ? RED_FLAG : 0) + (green & 0xC0 ? GREEN_FLAG : 0) + (blue & 0xC0 ? BLUE_FLAG : 0) + (red & green & blue & 0x80 ? BRIGHT_FLAG : 0);
}


#ifdef _WIN32 //_WIN16 ||

void ansiColor_resetStream(FILE *stream)
{
    if (ansiColor_initSuccess)
    {
        fprintf(stream, "\033[%um", 0);
    }

    SetConsoleTextAttribute(consoleOutputHandle, initalConsoleAttributes);
}

void ansiColor_setStream4Bit(FILE *stream, char flags)
{
    SetConsoleTextAttribute(consoleOutputHandle, flags);
}

void ansiColor_setStreamForeground4Bit(FILE *stream, char flags)
{
    SetConsoleTextAttribute(consoleOutputHandle, 0x0F & (flags | (flags >> 4)));
}

void ansiColor_setStreamBackground4Bit(FILE *stream, char flags)
{
    SetConsoleTextAttribute(consoleOutputHandle, 0xF0 & (flags | (flags << 4)));
}

void ansiColor_setStream8BitGray(FILE *stream, unsigned char foreground, unsigned char background)
{
    if (ansiColor_initSuccess)
    {
        fprintf(stream, "\033[38;2;%u;%u;%um", foreground, foreground, foreground);
        fprintf(stream, "\033[48;2;%u;%u;%um", background, background, background);
    }
    else
    {
        ansiColor_setStream4Bit( stream, ansiColor_24BitRGBCharsTo4BitFlags(foreground, foreground, foreground) | (ansiColor_24BitRGBCharsTo4BitFlags(background, background, background) << 4) );
    }
}

void ansiColor_setStreamForeground8BitGray(FILE *stream, unsigned char val)
{
    if (ansiColor_initSuccess)
    {
        fprintf(stream, "\033[38;2;%u;%u;%um", val, val, val);
    }
    else
    {
        ansiColor_setStreamForeground4Bit( stream, ansiColor_24BitRGBCharsTo4BitFlags(val, val, val) );
    }
}

void ansiColor_setStreamBackground8BitGray(FILE *stream, unsigned char val)
{
    if (ansiColor_initSuccess)
    {
        fprintf(stream, "\033[48;2;%u;%u;%um", val, val, val);
    }
    else
    {
        ansiColor_setStreamBackground4Bit( stream, (ansiColor_24BitRGBCharsTo4BitFlags(val, val, val) << 4) );
    }
}

void ansiColor_setStream24Bit(FILE *stream, unsigned char foregroundRed, unsigned char foregroundGreen, unsigned char foregroundBlue, unsigned char backgroundRed, unsigned char backgroundGreen, unsigned char backgroundBlue)
{
    if (ansiColor_initSuccess)
    {
        fprintf(stream, "\033[38;2;%u;%u;%um", foregroundRed, foregroundGreen, foregroundBlue);
        fprintf(stream, "\033[48;2;%u;%u;%um", backgroundRed, backgroundGreen, backgroundBlue);
    }
    else
    {
        ansiColor_setStream4Bit( stream, ansiColor_24BitRGBCharsTo4BitFlags(foregroundRed, foregroundGreen, foregroundBlue) | (ansiColor_24BitRGBCharsTo4BitFlags(backgroundRed, backgroundGreen, backgroundBlue) << 4) );
    }
}

void ansiColor_setStreamForeground24Bit(FILE *stream, unsigned char red, unsigned char green, unsigned char blue)
{
    if (ansiColor_initSuccess)
    {
        fprintf(stream, "\033[38;2;%u;%u;%um", red, green, blue);
    }
    else
    {
        ansiColor_setStreamForeground4Bit( stream, ansiColor_24BitRGBCharsTo4BitFlags(red, green, blue) );
    }
}

void ansiColor_setStreamBackground24Bit(FILE *stream, unsigned char red, unsigned char green, unsigned char blue)
{
    if (ansiColor_initSuccess)
    {
        fprintf(stream, "\033[48;2;%u;%u;%um", red, green, blue);
    }
    else
    {
        ansiColor_setStreamBackground4Bit( stream, (ansiColor_24BitRGBCharsTo4BitFlags(red, green, blue) << 4) );
    }
}

#else //_WIN16 || _WIN32

void ansiColor_resetStream(FILE *stream)
{
    fprintf(stream, "\033[%um", 0);
}

void ansiColor_setStream4Bit(FILE *stream, char flags)
{
    fprintf(stream, "\033[%um", ansiColor_4BitFlagsToParameter(flags));
    fprintf(stream, "\033[%um", ansiColor_4BitFlagsToParameter(flags >> 4) + 10);
}

void ansiColor_setStreamForeground4Bit(FILE *stream, char flags)
{
    fprintf(stream, "\033[%um", ansiColor_4BitFlagsToParameter(flags | (flags >> 4)));
}

void ansiColor_setStreamBackground4Bit(FILE *stream, char flags)
{
    fprintf(stream, "\033[%um", ansiColor_4BitFlagsToParameter(flags | (flags >> 4)) + 10);
}

void ansiColor_setStream8BitGray(FILE *stream, unsigned char foreground, unsigned char background)
{
    fprintf(stream, "\033[38;2;%u;%u;%um", foreground, foreground, foreground);
    fprintf(stream, "\033[48;2;%u;%u;%um", background, background, background);
}

void ansiColor_setStreamForeground8BitGray(FILE *stream, unsigned char val)
{
    fprintf(stream, "\033[38;2;%u;%u;%um", val, val, val);
}

void ansiColor_setStreamBackground8BitGray(FILE *stream, unsigned char val)
{
    fprintf(stream, "\033[48;2;%u;%u;%um", val, val, val);
}

void ansiColor_setStream24Bit(FILE *stream, unsigned char foregroundRed, unsigned char foregroundGreen, unsigned char foregroundBlue, unsigned char backgroundRed, unsigned char backgroundGreen, unsigned char backgroundBlue)
{
    fprintf(stream, "\033[38;2;%u;%u;%um", foregroundRed, foregroundGreen, foregroundBlue);
    fprintf(stream, "\033[48;2;%u;%u;%um", backgroundRed, backgroundGreen, backgroundBlue);
}

void ansiColor_setStreamForeground24Bit(FILE *stream, unsigned char red, unsigned char green, unsigned char blue)
{
    fprintf(stream, "\033[38;2;%u;%u;%um", red, green, blue);
}

void ansiColor_setStreamBackground24Bit(FILE *stream, unsigned char red, unsigned char green, unsigned char blue)
{
    fprintf(stream, "\033[48;2;%u;%u;%um", red, green, blue);
}

#endif

void ansiColor_resetConsole()
{
    ansiColor_resetStream(stdout);
}

void ansiColor_setConsole4Bit(char flags)
{
    ansiColor_setStream4Bit(stdout, flags);
}

void ansiColor_setConsoleForeground4Bit(char flags)
{
    ansiColor_setStreamForeground4Bit(stdout, flags);
}

void ansiColor_setConsoleBackground4Bit(char flags)
{
    ansiColor_setStreamBackground4Bit(stdout, flags);
}

void ansiColor_setConsole8BitGray(unsigned char foreground, unsigned char background)
{
    ansiColor_setStream8BitGray(stdout, foreground, background);
}

void ansiColor_setConsoleForeground8BitGray(unsigned char val)
{
    ansiColor_setStreamForeground8BitGray(stdout, val);
}

void ansiColor_setConsoleBackground8BitGray(unsigned char val)
{
    ansiColor_setStreamBackground8BitGray(stdout, val);
}

void ansiColor_setConsole24Bit(unsigned char foregroundRed, unsigned char foregroundGreen, unsigned char foregroundBlue, unsigned char backgroundRed, unsigned char backgroundGreen, unsigned char backgroundBlue)
{
    ansiColor_setStream24Bit(stdout, foregroundRed, foregroundGreen, foregroundBlue, backgroundRed, backgroundGreen, backgroundBlue);
}

void ansiColor_setConsoleForeground24Bit(unsigned char red, unsigned char green, unsigned char blue)
{
    ansiColor_setStreamForeground24Bit(stdout, red, green, blue);
}

void ansiColor_setConsoleBackground24Bit(unsigned char red, unsigned char green, unsigned char blue)
{
    ansiColor_setStreamBackground24Bit(stdout, red, green, blue);
}

void ansiColor_fresetless4BitBlockPrint(FILE *stream, char flags)
{
    ansiColor_setConsole4Bit(flags);

    fprintf(stream, "%s", HALF_BLOCK);
}

void ansiColor_resetless4BitBlockPrint(char flags)
{
    ansiColor_fresetless4BitBlockPrint(stdout, flags);
}

void ansiColor_f4BitBlockPrint(FILE *stream, char flags)
{
    ansiColor_fresetless4BitBlockPrint(stream, flags);

    ansiColor_resetStream(stream);
}

void ansiColor_4BitBlockPrint(char flags)
{
    ansiColor_f4BitBlockPrint(stdout, flags);
}

void ansiColor_fresetless8BitGrayBlockPrint(FILE *stream, unsigned char upper, unsigned char lower)
{
    ansiColor_setStream8BitGray(stream, upper, lower);

    fprintf(stream, "%s", HALF_BLOCK);
}

void ansiColor_resetless8BitGrayBlockPrint(unsigned char upper, unsigned char lower)
{
    ansiColor_fresetless8BitGrayBlockPrint(stdout, upper, lower);
}

void ansiColor_f8BitGrayBlockPrint(FILE *stream, unsigned char upper, unsigned char lower)
{
    ansiColor_fresetless8BitGrayBlockPrint(stream, upper, lower);

    ansiColor_resetStream(stream);
}

void ansiColor_8BitGrayBlockPrint(unsigned char upper, unsigned char lower)
{
    ansiColor_f8BitGrayBlockPrint(stdout, upper, lower);
}

void ansiColor_fresetless24BitBlockPrint(FILE *stream, unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue)
{
    ansiColor_setStream24Bit(stream, upperRed, upperGreen, upperBlue, lowerRed, lowerGreen, lowerBlue);

    fprintf(stream, "%s", HALF_BLOCK);
}

void ansiColor_resetless24BitBlockPrint(unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue)
{
    ansiColor_fresetless24BitBlockPrint(stdout, upperRed,  upperGreen,  upperBlue, lowerRed, lowerGreen, lowerBlue);
}

void ansiColor_f24BitBlockPrint(FILE *stream, unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue)
{
    ansiColor_fresetless24BitBlockPrint(stream, upperRed, upperGreen, upperBlue, lowerRed, lowerGreen, lowerBlue);

    ansiColor_resetStream(stream);
}

void ansiColor_24BitBlockPrint(unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue)
{
    ansiColor_f24BitBlockPrint(stdout, upperRed, upperGreen, upperBlue, lowerRed, lowerGreen, lowerBlue);
}

void ansiColor_fresetless4BitBlockPrintFrom24BitRGBChars(FILE *stream, unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue)
{
    // fprintf(stream, "\033[38;2;%u;%u;%um", upperRed, upperGreen, upperBlue);
    // fprintf(stream, "\033[48;2;%u;%u;%um", lowerRed, lowerGreen, lowerBlue);
    // fprintf(stream, HALF_BLOCK);
    
    ansiColor_fresetless4BitBlockPrint( stream, ansiColor_24BitRGBCharsTo4BitFlags(upperRed, upperGreen, upperBlue) | (ansiColor_24BitRGBCharsTo4BitFlags(lowerRed, lowerGreen, lowerBlue) << 4) );
}

void ansiColor_resetless4BitBlockPrintFrom24BitRGBChars(unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue)
{
    ansiColor_fresetless4BitBlockPrintFrom24BitRGBChars(stdout, upperRed, upperGreen, upperBlue, lowerRed, lowerGreen, lowerBlue);
}

void ansiColor_f4BitBlockPrintFrom24BitRGBChars(FILE *stream, unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue)
{
    ansiColor_fresetless4BitBlockPrintFrom24BitRGBChars(stream, upperRed, upperGreen, upperBlue, lowerRed, lowerGreen, lowerBlue);

    ansiColor_resetStream(stream);
}

void ansiColor_4BitBlockPrintFrom24BitRGBChars(unsigned char upperRed, unsigned char upperGreen, unsigned char upperBlue, unsigned char lowerRed, unsigned char lowerGreen, unsigned char lowerBlue)
{
    ansiColor_f4BitBlockPrintFrom24BitRGBChars(stdout, upperRed, upperGreen, upperBlue, lowerRed, lowerGreen, lowerBlue);
}
