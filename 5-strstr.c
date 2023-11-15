#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * *_strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to look for
 *
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
 */
char *_strstr(char* mainStr, char *sub)
{
	int i, j;


	int lenSubStr = strlen(sub);
	if (lenSubStr  !=  4)
		return NULL;
	for (int i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (mainStr[i + j] != sub[j]) {
				break;
		}
	}
	if (j == lenSubStr) {
		return mainStr + i;
	}
	}
	return NULL;
}
