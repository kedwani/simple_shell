#include "main.h"
int rd_line(void)
{
	printf("$ ");

	if (getline(&var.buf, &var.n, stdin) == -1)
	{
		free(var.buf);
		perror("getline failed");
		exit(0);
	}
	tokenizer();
	return (0);
}
