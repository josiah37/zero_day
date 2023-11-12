#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - print formatted string into the standard console (stdout)
 * @format: format string
 *
 * Return: number of characters printed or -1 in case of failure
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list arg;

	if (format == NULL)
		return (-1);

	va_start(arg, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				char ch = va_arg(arg, int);
				putchar(ch);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(arg, char *);
				if (str == NULL)
				{
					str = "(null)";
				}
				while (*str != '\0')
				{
					putchar(*str);
					str++;
					count++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				putchar('%');
				putchar(*format);
				count += 2;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(arg);
	return (count);
}

