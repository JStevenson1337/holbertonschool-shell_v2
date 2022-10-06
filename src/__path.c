#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>



int __path(int argc, char **argv, char **env_var)
{
	int i = 0;

	while (env_var[i])
	{
		if (strncmp(env_var[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	
}
