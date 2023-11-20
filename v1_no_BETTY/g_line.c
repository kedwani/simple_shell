#include "main.h"
int g_line(void)
{
	if (getline(&var.buf, &var.n, stdin) == -1)
	{
		free(var.buf);
		exit(WEXITSTATUS(var.status));
	}
	tokenizer();
	return (0);
}
