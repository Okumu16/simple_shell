#include "shell1.h"

/**
  * sig_handler - Handle the sigs
  * @sign_id: The idntfier of the sigs to handle
  *
  * Return: void
  */
void sig_handler(int sign_id)
{
	if (sign_id == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
}

/**
 * openHelp - Opens the Shell help
 *
 * Return: void
 */
void openHelp(void)
{
	_enter("\n***WELCOME TO THE SHELL HELP***\n");
}
