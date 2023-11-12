#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - print formatted string into the standard console (stdout)
 * @format: format string
 *
 * Return: number of characters printed or -1 in case of failure
 */
int _strlen(char *str);
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

			switch (*format)
			{
				case 'c':
				{
					char ch = va_arg(arg, int);
					putchar(ch);
					count++;
					break;
				}
				case 's':
				{
					char *str = va_arg(arg, char *);
					if (str == NULL)
					{
						fputs("(null)", stdout);
						count += 6;
					}
					else
					{
						fputs(str, stdout);
						count += _strlen(str);
					}
					break;
				}
				case '%':
				{
					putchar('%');
					count++;
					break;
				}
				default:
				{
					putchar('%');
					putchar(*format);
					count += 2;
					break;
				}
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

/**
 * _strlen - calculate the length of a string
 * @str: input string
 *
 * Return: length of the string
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

