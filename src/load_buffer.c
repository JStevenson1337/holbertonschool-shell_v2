#include "../include/shell.h"
/**
 * load_buffer - load buffer
 * @args: arguments
 *
 * Return: 0
 */
int load_buffer(char **args)
{
	node_contructor_t *node = malloc(sizeof(node_contructor_t));
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;
	int i = 0;

	if (node == NULL)
	{
		fprintf(stderr, "hsh: allocation error \n");
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	
	while (1)
	{
		printf("$ ");
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == EOF)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
			args = parse_line(buffer);
			if (check_builtin(args, buffer) == 0)
			{
				if (fork() == 0)
				{
					if (execve(args[0], args, NULL) == -1)
					{
						perror("hsh");
					}
				}
				else
				{
					wait(NULL);
				}
			}
		}
	}
}
