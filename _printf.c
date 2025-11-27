#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: character to print
 * Return: 1 on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *str;
	char c;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				count += _putchar(c);
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					count += _putchar(*str);
					str++;
				}
			}
			else if (*format == '%')
				count += _putchar('%');
			else
				count += _putchar('%'), count += _putchar(*format);
		}
		else
			count += _putchar(*format);
		format++;
	}

	va_end(args);
	return (count);
}

