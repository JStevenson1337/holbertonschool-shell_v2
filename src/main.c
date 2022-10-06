#include "../include/shell.h"
/**
 * main - super simple shell
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: environment
 *
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	char **args = NULL;
	int status = 1;
	(void)argc;
	(void)argv;
	(void)env;
	while (status)
	{
		if (argc > 1)
			line = argv[1];
		else
			line = _getline();
		/* print prompt */
		prompter();

		if(line)
			free(line);
		line = read_line();
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		args = tokenize(line, DELIM);
		if (check_builtin(args, line) == 1)
			status = execute(args, argv[0], 0);
		if (line)
			free(line);
		if (args)
			free(args);
	}
	free(args), free(line);
	return (0);
}

