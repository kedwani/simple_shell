#include "main.h"

/**
 * rd_line-  Read a line of input from the terminal,
 * display a prompt, and tokenize it.
 *
 * This function prints a prompt ("$ ") to the standard output and uses the
 * getline function to read a line from the terminal. The input line is stored
 * in the global variable `var.buf`. It then calls the `tokenizer` function to
 * tokenize the input line. If the input line is terminated or an error occurs
 * during reading, the function frees the allocated memory and exits with the
 * exit status from the global variable `var.status`.
 *
 * Return: Always returns 0 after reading, displaying the prompt,
 * and tokenizine the input line.
 */
int rd_line(void)
{
/*    // Display a prompt to the user*/
	printf("$ ");

/*  // Use getline to read a line from the terminal*/
	if (getline(&var.buf, &var.n, stdin) == -1)
	{
		free(var.buf);
		perror("getline failed");
		exit(0);
	}

/*Tokenize the input line*/
	tokenizer();

/*Return 0 after reading, and failed tokenizing the input line*/
	return (0);
}
