#include "main.h"
/**
* err_mesg - write error message to stderr
* @program: - program name--shell name
* @p_count: process count
* @cmd: command
* @err_no: previous function error number
*/
void err_mesg(char *program, int p_count, char *cmd, int err_no)
{
	char *del = ": ";
	char *err_m;
	char  *num = print_number(p_count);

	write(2, program, strlen(program));
	write(2, del, strlen(del));
	write(2, num, strlen(num));
	write(2, del, strlen(del));
	write(2, cmd, strlen(cmd));
	write(2, del, strlen(del));
	if (err_no == 2)
	{
		err_m = "not found";
		write(2, err_m, strlen(err_m));
		write(2, NEWL, strlen(NEWL));
	}
	else
		perror(NULL);
}
