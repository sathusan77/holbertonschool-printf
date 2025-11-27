#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    int i = 0, count = 0;
    va_list args;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (format[i] == 's')
            {
                char *str = va_arg(args, char *);
                int j = 0;

                if (!str)
                    str = "(null)";
                while (str[j])
                    count += write(1, &str[j++], 1);
            }
            else if (format[i] == '%')
            {
                write(1, "%", 1);
                count++;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}

