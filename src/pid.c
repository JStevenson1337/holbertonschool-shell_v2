#include "../include/shell.h"

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t my_ppid;

	fork();

	my_pid = getpid();
	printf("%u\n", my_pid);
	printf("%u\n", my_ppid);
	return (0);
}

