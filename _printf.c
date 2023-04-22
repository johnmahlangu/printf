#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _printf - print according to a format
 * @format: ...
 * Return: number of characters
 */
int _printf(const char *format, ...)
{
	int len = 0;
	int i;
	va_list args;
	char *s;
	int cnt;
	char c;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		c = format[i];

		if (c == '%')
		{
			i++;
			c = format[i];

			switch (c)
			{
				case 's':
					s = va_arg(args, char *);
					for (cnt = 0; s[cnt] != '\0'; cnt++);
					len += cnt;
					printf("%s", s);
					break;
				case 'c':
					c = va_arg(args, int);
					len++;
					printf("%c", c);
					break;
				case '%':
					printf("%%");
					len = len + 2;
					break;
				default:
					printf("%c", c);
					len++;
			}
		}
		else	
		{
			printf("%c", format[i]);
			len++;
		}
	}
	return (len);
}
