#include "main.h"

int is_only_spaces(const char *str)
{
	while (*str != '\0') {
	if (!isspace((unsigned char)*str))
	{
		return 0;
	}
	str++;
	}
		return 1;
}
