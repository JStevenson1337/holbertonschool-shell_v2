#include "../include/shell.h"


/**
 * hsh_exit - exits the current process
 * @args: arguments
 * @line: user input
 *
 */
void hsh_exit(char **args, char *line)
{
	(void)args;
	(void)line;
	exit(0);
}
/**
 * print_env - prints the entire environment array
 *
 */
void print_env(void)
{
	int i = 0;

	while (env[i])
	{
		_puts(env[i]);
		_puts("\n");
		i++;
	}
}
/**
 * cd - changes directory
 * @command: Direcotry to change to
 *
 * Return: 0
 */
int cd(char **command)
{
	chdir(command[1]);
	return (0);
}

