#include "shell.h"
/**
* print_s - Prints a string
* @str: String to be printed
*
* Return: The number of characters printed
*/
int print_s(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: 1 On success.
* On error, -1 is returned and errno is set appropriately
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
