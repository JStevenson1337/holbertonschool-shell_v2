#include "../include/shell.h"
/**
 * check_path - checks path
 * @head: head of PATH linked list
 * @command: command from arguments
 *
 * Return: returns the proper path or NULL on failure
 */

char *check_path(path_t *head, char *command)
{
	char *path = NULL;
	char *temp = NULL;
	struct stat st;

	while (head)
	{
		path = _strcat(head->path, "/");
		temp = _strcat(path, command);
		if (stat(temp, &st) == 0)
		{
			return (temp);
		}
		head = head->next;
	}
	return (NULL);
}

