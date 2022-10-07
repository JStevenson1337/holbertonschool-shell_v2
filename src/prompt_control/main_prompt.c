#include "../../include/shell.h"
/**
 * prompt - shell loop
 * @program: name of shell
 *
 */

void prompt(char *program)
{
	char *line;
	char **args;
	int x, status, line_num = 0;

	env = _environ();
	main_path = make_path();
	status = 1;
	signal(SIGINT, signal_handler);


	while (status)
	{
		line_num++;
		line = read_line();
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		args = tokenize(line, DELIM);
		if (check_builtin(args, line) == 1)
			status = execute(args, program, line_num);
		x = 0;
		while (args[x] != NULL)
		{
			if (args[x])
				free(args[x]);
			x++;
		}

		if (line)
			free(line);
		if (args)
			free(args);
	}
	free(args), free(line);
	free_path(main_path);
	free_path(env);
}

