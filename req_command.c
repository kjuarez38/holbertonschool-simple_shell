#include "main.h"

/**
 * check_and_execute_command - Check commands before executing them
 * @commands: Array of commands
 * @filename: Filename
 *
 * Return: Exit status of the executed command.
 */
int check_and_execute_command(char **commands, char *filename)
{
	char *with_path = NULL;
	int status = 0;

	if (strcmp(commands[0], "env") == 0)
	{
		env_command();
		return (1);
	}

	if (!is_path(commands[0]))
	{
		with_path = path_command(commands[0]);
		if (!with_path)
		{
			dprintf(STDERR_FILENO, "%s: 1: %s: not found\n", filename, commands[0]);
			return (0);
		}
		commands[0] = command_with_path;
	}

	if (access(commands[0], F_OK) == -1)
	{
		dprintf(STDERR_FILENO, "%s: 1: %s: not found\n", filename, commands[0]);
		return (0);
	}

	status = execute_command(commands, filename);

	if (command_with_path)
		free(command_with_path);

	return (status);
}

