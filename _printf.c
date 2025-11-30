#include "main.h"

/**
 * handle_percent - handles a conversion specifier
 * @specifier: the character after %
 * @args: va_list of arguments
 * Return: number of characters printed
 */
int handle_percent(char specifier, va_list args)
{
	int count = 0;
	char *str;
	char c;

	if (specifier == 'c')
	{
		c = va_arg(args, int);
		count += _putchar(c);
	}
	else if (specifier == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		while (*str)
			count += _putchar(*str++);
	}
	else if (specifier == '%')
		count += _putchar('%');
	else if (specifier == 'd' || specifier == 'i')
		count += print_number(va_arg(args, int));
	else
	{
		count += _putchar('%');
		count += _putchar(specifier);
	}

	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: format strin*

