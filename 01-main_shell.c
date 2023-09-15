#include "shell.h"
/**
* main - carries out the read, execute then print outputto stdout
* ac: Argument count (argc)
* av: Argument vector (argv)
* envp: Environment pointer
* Return: 0
*/
int main(int ac, char **av, char *envp[])
{
	(void)envp, (void)av;
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **cmd = NULL, **paths = NULL;

	(void)envp, (void)av;
	if (ac < 1)
		return (-1);

		/*Set up signal handlers for SIGINT (Ctrl+C)*/
	signal(sigint, verif_sig);
	signal(SIGINT, verif_sig);
	while (1)
	{
		/*Free memory for command tokens*/
		free_buffs(cmd);

		/* Free memory for path tokens*/
		free_buffs(paths);

		/*Free memory for path command*/
		free(pathcommand);

		/*Display the shell prompt*/
		prompt_user();

		/*Read user input*/
		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;

			/*Increment line count*/
		info.ln_count++;
		if (line[linesize - 1] == '\n')

			/*Remove trailing newline*/
			line[linesize - 1] = '\0';

		/*Tokenize user input into command and arguments*/
		cmd = tokenizer(line);
		if (cmd == NULL || *cmd == NULL || **cmd == '\0')

			/*Skip empty lines or lines with no valid command*/
			continue;
		if (verif(cmd, line))

			/*Handle built-in commands*/
			continue;

		/*Find the value of the "PATH" environment variable*/
		path = find_path();

		/*Tokenize the "PATH" variable*/
		paths = tokenizer(path);

		/*Search for the executable in paths*/
		pathcommand = test_path(paths, cmd[0]);
		if (!pathcommand)

			/*Error if the executable is not found*/
			perror(av[0]);
		else

			/* Execute the command*/
			execution(pathcommand, cmd);
	}
	if (linesize < 0 && flags.interactive)

		/*Print a newline if Ctrl+D is used in interactive mode*/
		write(STDERR_FILENO, "\n", 1);

		/*Free memory allocated for user input*/
	free(line);
	return (0);
}
