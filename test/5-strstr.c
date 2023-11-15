#include "main.h"
#include <stdio.h>

/**
 * *_strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to look for
 *
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
					break;
		}
		if (needle[j] == '\0')
				return &haystack[i];		

}

return (NULL);
}
int main()
{
	char *ar = "mohamed mahmoud ahmed";
	char *er = "mohamed";
	char *et;
	et = _strstr("mohamed","mi");
	printf("%s",et);
	return 0;
}
