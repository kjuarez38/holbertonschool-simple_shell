#include "main.h"
#define MAX_COMMAND_LENGTH 100

/**
 * main - ex the command of a simple shell
 *
 * Return: Always 0.
 */
int main(void)
{
	
	char *command = NULL;
	size_t len = 0;

	while (1)
	{

		if (getline(&command, &len, stdin) == -1)
		{
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		free(command);
	}
	return (0);
}
