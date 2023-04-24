#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/* Miscellous */
#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/* SIZE(S) */
#define SIZE_SHORT 1
#define SIZE_LONG 2

/* FLAG(S) */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

int _printf(const char *format, ...);
void print_buffers(char buffer[], int *buff_ind);

#endif /* MAIN_H */
