#include "main.h"
#define MAX_COMMAND_LENGTH 100

/**
 * main - ex the command of a simple shell
 *
 * Return: Always 0.
 */
int main(void)
{
	int status;
	char *command = NULL;
	size_t len = 0;
	pid_t pid;

	while (1)
	{

		if (getline(&command, &len, stdin) == -1)
		{
			free(command);
			break;
		}
		command[strcspn(command, "\n")] = '\0';
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
			printf("\n");
		}
	}

	free(command);
	return (0);
}
