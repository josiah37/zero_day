#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - print formated string into the standard console (stdout)
 * @format: format string
 *
 * Return: number of char printed or -1 incase of failure
 */

int _printf(const char *format, ...)
{
 	if (format == NULL)
		return(-1);
	while (*format != '\0')
	{
		if (*format== '%')
			*format++;
			if (*format == 'c')
			write(1, format, 1);	
		//	if (*format == 's')
		//	if (*format == '%')
		//	else	
			
	}

	return (strlen(format));
}


int mian ()
{
	_printf("j");
	return (0);
}
