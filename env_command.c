#include "main.h"
/**
 * env_command - main for environnement
 * Description prints the current environment
 * Return: 0
 */
void env_command(void)
{
	int i = 0;

	for (; environ[i]; i++)
		printf("%s\n", environ[i]);
}
