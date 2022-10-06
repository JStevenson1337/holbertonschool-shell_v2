#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void handle_sigtstp(int sig)
{
	printf("Caught signal\n");


}

void handle_sigcont(int sig)
{
	printf("Input Number: ");
	fflush(stdout);

}

int main(int argc, char *argv[])
{
	/*signal(SIGTSTP, handle_sigtstp);
	struct sigaction sa;
	sa.sa_handler = &handle_sigtstp;
	sigaction(SIGTSTP, &sa, NULL);
	sa.sa_flags = SA_RESTART;
	*/
	
	struct sigaction sa;
	sa.sa_handler = &handle_sigcont;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &sa, NULL);



	int x;
	printf("Input Number: ");
	scanf("%d", &x);
	printf("number is: %d * 5 = %d\n", x, x * 5);
	return (0);
}
