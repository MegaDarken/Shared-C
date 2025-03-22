//Ensure loaded only once
#ifndef __RAW_READ__
#define __RAW_READ__

#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

void disableRawMode();
void enableRawMode();
ssize_t rawReadBuffer(void* array, ssize_t count);
int rawRead();
void rawReadLoop(const int escape);
char rawReadBool(const int trueChar, const int falseChar);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__RAW_READ__
