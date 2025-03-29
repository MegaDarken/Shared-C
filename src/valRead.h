#ifndef __VAL_READ__
#define __VAL_READ__

#include "stdlib.h"

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void valRead_charDest(char *dest, const char *invalidInputText);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
char valRead_char(const char *invalidInputText);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void valRead_wcharDest(int *dest, const char *invalidInputText);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
int valRead_wchar(const char *invalidInputText);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void valRead_intDest(int *dest, const char *invalidInputText);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
int valRead_int(const char *invalidInputText);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
void valRead_size_tDest(size_t *dest, const char *invalidInputText);

#ifdef __cplusplus
extern "C"
#endif //__cplusplus
size_t valRead_size_t(const char *invalidInputText);

#endif //__VAL_READ__