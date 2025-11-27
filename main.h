#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Function prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int print_number(int n);
int handle_percent(char specifier, va_list args);

#endif /* MAIN_H */

