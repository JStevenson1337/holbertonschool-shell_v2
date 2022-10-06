#ifndef __SHELL_H__
#define __SHELL_H__
#define __GETLINE_H__


#define DELIM " \t\a\v\r\f"


/* Libraries */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#include "_getline.h"


#define SHELL_NAME "hsh"
#define SHELL_VERSION "2.0"

#define UNUSED(x) (void)x


#define COMMAND_GET_MAXIMUM_CMD_SIZE	(4096*4096)

#define ENV_BUFFER_SIZE 1024
#define LINE_BUFFER_SIZE 4096

typedef struct env_s
{
	struct env_s *next;
	struct env_s *prev;
	char *key;
	char *value;
} env_t;

typedef struct input_string_s
{
	char *cmd;
	char **args;
	char *input;
	char *output;
	int input_fd;
	int output_fd;
	int append;
	int background;
} input_string_t;

typedef struct hsh_h
{
	char *name;
	char *version;
	char *line;
	char **tokens;
	char *input;
	char *output;
	int input_fd;
	int output_fd;
	int append;
	int background;
	int exit;
	int status;
	int interactive;
	int argc;
	char **argv;
	char **env;
	env_t *env_list;
} hsh_t;

extern hsh_t *shell;



#define OK 1

#define ERR_GET_COMMAND_EOF	0
#define ERR_GET_COMMAND_READ	-1
#define ERR_GET_COMMAND_TO_BIG	-2
#define ERR_GET_COMMAND_MEMORY	-3

/* Function Prototypes */


/* GETLINE */
fd_t *get_fd(fd_t **head, int fd);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *flush_buffer(char *line, size_t *pos, size_t *size, size_t need, fd_t *desc);
char *read_descriptor(fd_t *desc);
char *_getline(const int fd);
/* END GETLINE */


char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_itoa(int num);


char *read_line(void);
char **tokenize(char *buffer, char *delim);
int execute(char **args, char *program, int n);
void prompt(char *program);
void prompter(void);
void signal_handler (int sig);

int word_count(char *s);

char *_getenv(char *name);
path_t *make_path(void);
char *check_path(path_t *head, char *command);
char *path_concat(char *s1, char *s2);
path_t *_environ(void);

void free_path(path_t *head);

int check_builtin(char **args, char *line);
void hsh_exit(char **args, char *line);
void print_env(void);
int cd(char **command);
int check_command(char **args, char *program, int n);


void __error(char **args, char *program, int code, int n);
char clear_screen(void);
void signal_handler (int sig);
char *read_line(void);


int exit_builtin(char **args, char *line);
int env_builtin(char **args, char *line);
int setenv_builtin(char **args, char *line);
int unsetenv_builtin(char **args, char *line);
int cd_builtin(char **args, char *line);


char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);


#endif /* SHELL_H */
