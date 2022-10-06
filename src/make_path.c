#include "../include/shell.h"

typedef struct env_s
{
	struct env_s *next;
	struct env_s *prev;
	char *key;
	char *value;
} env_t;

size_t print_envlist(const env_t *h)
{
	size_t i = 0;

	for (i = 0; h != NULL; i++, h = h->next)
	{
		printf("key = %s\n", h->key);
		printf("value = %s\n\n", h->value);
	}	

	return (i);
}

void free_list(char **list, int oi)
{
	int i = oi;

	while (i)
	{
		i--;
		free(list[i]);
	}

	free(list);
}

char **buildEnvList(env_t *h)
{
	size_t i = 0;
	char **retVal = NULL;

	for (i = 0; h != NULL; i++, h = h->next);	

	retVal = malloc(sizeof(char *) * i);
	return retVal;
}

void fillEnvList(env_t *h, char **outputList)
{
	int i = 0;
	int keysize;
	int valuesize;
	int strsize;

	for (i = 0; h != NULL; i++, h = h->next)
	{
		keysize = strlen(h->key);
		valuesize = strlen(h->value);
		strsize = (keysize + valuesize + 2);
		outputList[i] = malloc(strsize);
		strcpy(outputList[i], h->key);
		strcpy(&outputList[i][keysize], "=");
		strcpy(&outputList[i][keysize + 1], h->value);
		/* printf("filling with %s\n", outputList[i]); */
	}
	
}

char *getKey(char *str)
{
	char *retVal;

	int i = 0;
	while (str[i] != '=' && str[i] != '\0' )
	{
		i++;
	}
	retVal = strndup(str, i);
	return retVal;
}

char *getValue(char *str)
{
	char *retVal;

	int i = 0;
	while (str[i] != '=' && str[i] != '\0' )
	{
		i++;
	}
	retVal = strdup(&str[i+1]);
	return retVal;
}
/**
 * add_dnodeint_end - Adds a dlistint_t node to the end of 	the dlinked list
 * @head: The head of the dlistint_t doubly linked list
 * @envItem: The value to store in the node
 * Return: The address of the new node
 */

env_t *add_env_t_end(env_t **head, char *envItem)
{
	env_t *this_node = *head;
	env_t *new_node = NULL;

	new_node = malloc(sizeof(env_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = getKey(envItem);
	new_node->value = getValue(envItem);
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	this_node = *head;
	while (this_node->next != NULL)
	{
		this_node = this_node->next;
	}
	this_node->next = new_node;
	new_node->prev = this_node;

	return (*head);
}

void printList(char **list, int oi)
{
	int i = 0;
	while (i < oi)
	{
		printf("%s\n", list[i]);
		i++;
	}
}

void freeEnvList(env_t **head)
{
	env_t *thisNode = *head;
	env_t *nextNode;

	while (thisNode != NULL)
	{
		nextNode = thisNode->next;
		free(thisNode->key);
		free(thisNode->value);
		free(thisNode);
		thisNode = nextNode;
	}

}

int main(int argc, char **argv, char **env)
{
	int i = 0;
	env_t *head = NULL;
	char **outputList;

	(void) argc;
	(void) argv;
	while (env[i] != NULL)
	{
		/* printf("%s\n", env[i]); */
		add_env_t_end(&head, env[i]);
		i++;
	}
	/* print_envlist(head); */
	outputList = buildEnvList(head);
	fillEnvList(head, outputList);
	/* printf("\n\n\n\n\nPrinting outputList:\n"); */
	printList(outputList, i);
	freeEnvList(&head);
	free_list(outputList, i);
	return (0);

}




// #include "shell.h"

// /**
//  * make_path - make path
//  *
//  * Return: returns the head of the path;
//  */

// path_t *make_path(void)
// {
// 	path_t *head;
// 	path_t *temp;
// 	char *path_name, *token;

// 	path_name = NULL;
// 	temp = malloc(sizeof(path_t));
// 	if (!temp)
// 		exit(-1);

// 	path_name = _getenv("PATH");

// 	if (!path_name)
// 	{
// 		free(temp);
// 		return (NULL);
// 	}
// 	token = strtok(path_name, ":");

// 	head = temp;
// 	while (token)
// 	{
// 		temp->dir = _strdup(token);
// 		token = strtok(NULL, ":");
// 		if (token)
// 		{
// 			temp->next = malloc(sizeof(path_t));
// 			if (!temp->next)
// 			{
// 				free_path(head);
// 				exit(-1);
// 			}
// 			temp = temp->next;
// 		}
// 		else
// 			temp->next = NULL;
// 	}
// 	free(path_name);
// 	return (head);
// }

// /**
//  * free_path - frees a linked list
//  * @head: linked list
//  *
//  */

// void free_path(path_t *head)
// {
// 	if (head == NULL)
// 		return;
// 	if (head->next != NULL)
// 		free_path(head->next);
// 	free(head->dir);
// 	free(head);
// }
