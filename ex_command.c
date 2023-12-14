#include "main.h"
/**
 * execute_command - a function that execute commands
 * @commands: commands
 * @filename: filename
 *
 * Return: Nothing.
 */

int execute_command(char **commands, char *filename)
{
	pid_t pid;
	int status = 0;

	pid = fork();

	if (pid == 0 && commands[0])
	{
		if (execve(commands[0], commands, environ) == -1)
		{
			dprintf(STDERR_FILENO, "%s: cannot execute '%s': No such file or directory\n",
                    commands[0], filename);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid == -1)
	{
		perror("Error creating child process");
		return (1);
	}

	waitpid(pid, &status, 0);

	return (1);
}
