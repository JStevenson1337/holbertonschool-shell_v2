#include "../../include/shell.h"
/**
 * clear_screen - clears the screen
 * Return: 0
 */

char clear_screen(void)
{
	write(1, "\033[H\033[J", 7);
	return (0);
}
