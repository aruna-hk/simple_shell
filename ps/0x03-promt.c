#include "main.h"
/**
* exit_no - get the exit number
* @num: string number arguemrnt
* Return: int exit number
*/
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

/**
*/
void line_clean(char **line)
{
	char *ret_tok;
	char *line_tok;

	*line = strtok(*line, " ");

	*line = remov_comment(line);
}
int child_exit(char *name, char **line, int *child_id, int *p_count)
{
	int exit_number, sig;
	char **arr;

	arr = tokenizer(*line, " ");
	if (strcmp(arr[0], "exit") == 0)
	{
		free(*line);
		*line = NULL;
		if (arr[1] == NULL)
		{
			freegrid(arr);
			if (*child_id != 0)
				*child_id--;
			exit(0);
		}
		else
		{
			exit_number = exit_no(arr[1]);
			if (exit_number == -1)
			{
				p_e_error(name, (*p_count)++, arr);
				freegrid(arr);
				return (0);
			}
			else
			{
				freegrid(arr);
				if (*child_id != 0)
					*child_id--;
				exit(exit_number);
			}
		}
	}
	if (strcmp(arr[0],  name) == 0 && arr[1] == NULL)
	{
		free(*line);
		*line = NULL;
		freegrid(arr);
		dprintf(STDOUT_FILENO, "CHILD PROCESS\n");
		return (0);
	}
	freegrid(arr);
	return (1);
}

/**
* _start_prompt - shell entry point
* @name:number of arguements
* @p_count: process count
* Return: 0/errno
*/
int _start_prompt(char *name, int *p_count)
{
	static int prev_return;
	char *line = NULL;
	ssize_t nread;
	size_t r_read;
	char *p_string, *first_s, **arr, *line_;
	int child_id = 0, n = 0, b_in = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			if (child_id == 0)
				p_string = "$ ";
			else
				p_string = " ($) ";
			write(1, p_string, strlen(p_string));
		}
		nread = getline(&line, &r_read, stdin);
		if (nread == EOF)
		{
			free(line);
			if (isatty(STDIN_FILENO))
				write(1, NEWL, strlen(NEWL));
			break;
		}
		line[nread - 1] = '\0';
		line_ = line;
		while (*line_ == ' ')
			line_++;
		if (*line_ == '\0')
			continue;
		first_s = strtok(strdup(line_), " ");
		if (strcmp(first_s, name) == 0 || strcmp(first_s, "exit") == 0)
		{
			free(first_s);
			if (child_exit(name, &line, &child_id, p_count) == 0)
				continue;
		}
		else
			free(first_s);
		n = logic(name, line, p_count, &b_in);
	}
	return (n);
}
