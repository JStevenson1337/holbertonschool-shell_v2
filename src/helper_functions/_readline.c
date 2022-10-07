#include "../../include/shell.h"

/**
 * read_line - gets command line from user
 *
 * Return: returns the user input from the command line
 */
char *read_line(void)
{
	char *buf = NULL;
	size_t bufsize = 0;

	if (isatty(STDIN_FILENO) == 1)
		write(1, "$ ", 2);
	if (getline(&buf, &bufsize, stdin) <= 0)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);
		hsh_exit(NULL, buf);
	}
	return (buf);
}
