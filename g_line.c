#include "main.h"

/**
 * g_line- Read a line of input from standard input and tokenize it.
 *
 * This function uses the getline function to read a line
 * from the standard input and stores the input in the global
 * variable `var.buf`. It then calls the
 * `tokenizer` function to tokenize the input line.
 * If the input line is terminated or an error occurs during reading,
 * the function frees the allocated memory and
 * exits with the exit status from the global variable `var.status`.
 *
 * Return: Always returns 0 after reading and tokenizing the input line.
 */
int g_line(void)
{
/* Use getline to read a line from standard input */
	if (getline(&var.buf, &var.n, stdin) == -1)
	{
		free(var.buf);
		exit(WEXITSTATUS(var.status));
	}

/* Tokenize the input line*/
	tokenizer();

/* Return 0 after reading and tokenizing the input line */
	return (0);
}
