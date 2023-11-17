#include "main.h"
/**
 * interactive - Reads a line from standard input into a buffer.
 * @buf: Double pointer to a character array for input storage.
 * @n: Pointer to a size_t variable for buffer size.
 *
 * Description: Displays a prompt ('$ ') on standard output, then reads a line
 * from standard input using getline. If getline encounters an error,
 * the function prints an error message with perror and exits. Assumes
 * memory management for 'buf' is handled by the caller.
 */
void interactive(char **buf, size_t *n)
{
	write(STDOUT_FILENO, "$ ", 2);

	if (getline(buf, n, stdin) == -1)
	{
	perror("getline failed");
	exit(0);
	}
}
