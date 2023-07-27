#include "shell.h"

/**
 * string_compare - cpmpares two strings
 * @str1: first srtig to compare
 * @str2: second string to compare
 *
 * Return: the diffrience betwee the two srtings
 */

int string_compare(const char *str1, const char *str2)
{
	int i = 0;
	int output;

	while (str1[i] == str2[i] && str1[i] != '\0')
	{
		i++;
		output = (str1[i] - str2[i]);
	}
	return (output);
}

/**
 * string_length - calculates the length of a string
 * @s: the string
 *
 * Return: the length of the string passed
 */

int string_length(const char *s)
{
	int count = 0;

	while (*S != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
 * string_n_compare - compares two strings to n bytes
 * @str1: first string to compare
 * @str2: second string to compare
 * @n: number of bytes
 *
 * Return: the difference between the two strings
 */

int string_n_compare(const char *str1, cost char *str2, size_t n)
{
	size_t i;

	for (i = 0; str1[i] && str2[i] && i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
	}
	return (0);
}

/**
 * string_duplicate - duplictes a string
 * @s: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *string_duplicate(const char *s)
{
	char *ptr;
	int i, len;

	if (s == NULL)
	{
		return (NULL);
	}
	len = string_length(s);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
	{
		return (NULL);
	}
	for (i = 0; *s != '\0'; s++, i++)
	{
		ptr[i] = s[0];
	}
	ptr[i++] = '\0';
	return (ptr);
}

/**
 * string_locate - locates a char in a string
 * @*s: the string
 * @c: the char to locate
 *
 * Return: pointer to the first occurence of the char
 */

char *string_locate(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
		{
			return ((char *)s);
			s++;
		}
		if (!c)
		{
			return ((char *)s);
			return (NULL);
		}
	}
}
