#include "../include/shell.h"
/**
 * check_builtin - checks if builtin has been called
 * @args: argv array
 * @line: user input
 *
 * Return: returns the proper builtin function or NULL on failure
 */
int check_builtin(char **args, char *line)
{
	int i = 0;
	builtin_t builtins[] = {
		{"exit", hsh_exit},
		{"env", hsh_env},
		{"setenv", hsh_setenv},
		{"unsetenv", hsh_unsetenv},
		{"cd", hsh_cd},
		{NULL, NULL}
	};
	if (args[0] == NULL)
		return (1);
	while (builtins[i].name != NULL)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
		{
			return ((*builtins[i].f)(args, line));
		}
		i++;
	}
	return (0);
}
