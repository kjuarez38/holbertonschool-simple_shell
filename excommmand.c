#include "main.h"

/**
 * main - ex the command of a simple shell
 *
 * Return: Always 0.
 */
int excommand(void)
{
	int status;
	pid_t pid;

	pid = fork();

	if (pid < 0)
	{
		perror("Error forking process");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execlp(command, command, (char *)NULL) == -1)
		{
			fprintf(stderr, "simple_shell: %s: command not found\n", command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (0);
}
