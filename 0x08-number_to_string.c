#include "shell.h"
/**
 * print_number - takes int and prints the number
 * @n: int arguement
 * Return: string of number
 */
char *print_number(int n)
{
	char c;
	int j = n;
	int i;
	int len = 0;
	int power;
	char *str_num = malloc(11);

	if (str_num == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	if (n == 0)
	{
		str_num[0] = '0';
		str_num[1] = '\0';
	}
	else
	{
		while (j != 0)
		{
			len++;
			j = j / 10;
		}
		for (i = 0; i < len; i++)
		{
			power = 1;
			for (j = len - 1; j > i; j--)
				power *= 10;
			c = '0' + (n / power);
			str_num[i] = c;
			n = n % power;
		}
		str_num[i] = '\0';
	}
	return (str_num);
}
