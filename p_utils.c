#include "monty.h"
#include <ctype.h>

/**
 * _isdigit - checks if the string is a number
 *
 * Description:
 * @strg: character string
 * Return: 1 if string is a number, else -1
*/

int _isdigit(char *strg)
{
	int parv = 0;

	while (strg[parv])
	{
		if (!(isdigit(strg[parv])))
			return (-1);
		parv++;
	}
	return (1);
}
