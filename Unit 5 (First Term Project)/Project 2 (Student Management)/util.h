#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

#define printfRed(...)  printf("\033[31m"); \
                        printf(__VA_ARGS__); \
                        printf("\033[37m")

#define printfBlue(...)  printf("\033[34m"); \
                         printf(__VA_ARGS__); \
                         printf("\033[37m")

#define printfGreen(...)  printf("\033[32m"); \
                          printf(__VA_ARGS__); \
                          printf("\033[37m")

#define printfMagenta(...)  printf("\033[35m"); \
                            printf(__VA_ARGS__); \
                            printf("\033[37m")

#define printfCyan(...)  printf("\033[36m"); \
                         printf(__VA_ARGS__); \
                         printf("\033[37m")

#define printfYellow(...)  printf("\033[33m"); \
                           printf(__VA_ARGS__); \
                           printf("\033[37m")

#define myScanf(...)  scanf(__VA_ARGS__); \
                      getchar();

void safeInput(char *inp , unsigned int maxLimit);

#endif