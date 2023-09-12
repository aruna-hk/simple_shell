#include "main.h"
/**
* 
*/
int execute_line(char *p_name, char *f_path, char **arglist, int p_count)
{
        int sig, status;
        pid_t process = fork();

        if (process != 0)
	{
                wait(&sig);
		if (WIFEXITED(sig))
		{
        	    status = WEXITSTATUS(sig);
        	    return (status);
       		 }
	}
        else if (process == 0)
        {
                if (execve(f_path, arglist, environ) == -1) 
                {
                        err_mesg(p_name, p_count, arglist[0], errno);
                        exit(errno);
                }
                else
                        exit(EXIT_SUCCESS);
        }
        return (-1);
}
