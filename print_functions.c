#include "shell.h"

/**
 * _putchar - writes a character
 * @c: character to print
 *
 * Return: 1 on success, -1 0n error
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string_to_stdout - print a string to stdout
 * @s: string to be printed
 *
 * Return: number of characters printed
 */

void print_string_to_stdout(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}
