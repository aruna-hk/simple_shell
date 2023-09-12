#include "main.h"
int exit_no(char *num)
{
	int i = 0;

	while (num[i] != '\0')
	{
		if ((int)num[i] < 48 || (int)num[i] > 57)
			return (-1);
		i++;
	}
	return (atoi(num));
}
void p_e_error(char *name, int p_no, char **il_no)
{
	char *num = print_number(p_no);

	int len = strlen(name) + strlen(num) + strlen(il_no[0]) + strlen(il_no[1]) + 30;
	char *err = malloc(len);

	err[0] = '\0';

	strcpy(err, name);
	strcat(err, ": ");
	strcat(err, num);	
	strcat(err, ": ");
	strcat(err, il_no[0]);
	strcat(err, ": ");
	strcat(err, "Illegal number");
	strcat(err, ": ");
	strcat(err, il_no[1]);
	strcat(err, "\n");

	write(2, err, strlen(err));
	free(err);
}
/**
* create_child() - create child process is ar == name
* of the program
* Also exit the program
* @arr: array of command tokens
*/
int create_child(char **arr, int *p_count, char *name, int *c_id, int p_ret)
{
	static int prev_p_count = 0;
	pid_t child;
	int signal, n;

	if (strcmp(name, arr[0]) == 0 && arr[1] == NULL)
	{
		child = fork();
		if (child != 0)
			wait(&signal);
		else
		{
			prev_p_count = *p_count;
			*p_count  = 0;
			(*c_id)++;
		}
		return (1);
	}
	else if (strcmp(arr[0], "exit") == 0)
	{
		(*p_count)++;
		if (arr[1] == NULL)
		{
			*p_count = prev_p_count;
			prev_p_count = 0;
			if (p_ret == 0)
				exit(0);
			else
				exit(p_ret);
		}
		n = exit_no(arr[1]);
		if (n == -1)
			p_e_error(name, *p_count, arr);
		else
		{
			*p_count = prev_p_count;
			prev_p_count = 0;
			exit(n);
		}	
	}
	return (2);
}
