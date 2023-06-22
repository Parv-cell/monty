#include "monty.h"

/**
 * initMonty - initialise monty globally
 */

void initMonty(void)
{
	monty.arg = NULL;
	monty.stack = NULL;
	monty.line = 0;
}

/**
 * check_args - checks byte code
 *
 * Description:
 * @arc: argument cound
 * @arv: argument vector
 *
 * Return: byte code file pointer
 */

FILE *check_args(int arc, char **arv)
{
	FILE *fp;

	if (arc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: my monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(arv[1], "r");
	if (!fp)
	{
		dprintf(STDERR_FILENO, "Error: Can't open the file %s\n", arv[1]);
		exit(EXIT_FAILURE);
	}

	return (fp);
}

/**
 * main - runs the bytecode
 *
 *description:
 * @arc: integer argument count
 * @arv: character argument vector
 *
 * Return: 0 on success
 */

int main(int arc, char **arv)
{
	FILE *fp;
	size_t p = 0;
	char *lineptr = NULL, *opCode;
	ssize_t flag;
	const char DELIM[3] = " \t\n";
	void (*func)(stack_t **, unsigned int);

	fp = check_args(arc, arv);

	while ((flag = getline(&lineptr, &p, fp) != -1))
	{
		monty.line++;
		opCode = strtok(lineptr, DELIM);
		if (opCode)
		{
			func = ops_acq(opCode);
			if (!func)
			{
				dprintf(2, "L%d: unknown command %s\n", monty.line, opCode);
				exit(EXIT_FAILURE);
			}
			monty.arg = strtok(NULL, DELIM);
			func(&monty.stack, monty.line);
		}
	}
	free(lineptr);
	fclose(fp);
	return (0);
}
