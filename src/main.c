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
		line = read_line();
		args = *parse_line(line);
		status = check_builtin(args, line);
		free(line);
		free(args);
	}
	return (0);
}
	// if (!hsh)
	// 	return (1);
	
	// while (status)
	// {
	// 	if (argc > 1)
	// 		__error(args, argv[0], 2, 0);
	// 	/* print prompt */
	// 	prompter();

	// 	/* read line */
	// 	line = read_line();
	// 	if (line == NULL)
	// 		continue;
	// 	/* parse line */
	// 	args = parse_line(line);
	// 	if (args == NULL)
	// 		continue;
	// 	/* check if builtin */
	// 	status = check_builtin(args, line);
	// 	if (status == 1)
	// 		continue;
	// 	/* execute */
	// 	status = execute(args, line, hsh);
	// 	if (status == 1)
	// 		continue;

	// 	/* free memory */
	// 	free(line);
	// 	free(args);
	// }


	return (0);
}

