#include "monty.h"

/**
 * init_monty - initialise monty globally
 */

void init_monty(void)
{
	monty.arg = NULL;
	monty.stack = NULL;
	monty.lineNumb = 0;
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
	size_t n = 0;
	ssize_t flag;
	const char DELIM[3] = " \t\n";
	void (*func)(stack_t **, unsigned int);

	fp = check_args(arc, arv);

	while ((flag = getline(&lineptr, &n, fp) != -1))
	{
		monty.lineNumb++;
		opCode = strtok(lineptr, DELIM);
		if (opCode)
		{
			func = ops_acq(opCode);
			if (!func)
			{
				printf("L%d: unknown command %s\n", monty.lineNumb, opCode);
				exit(EXIT_FAILURE);
			}
			monty.arg = strtok(NULL, DELIM);
			func(&monty.stack, monty.lineNumb);
		}
	}
	free(lineptr);
	fclose(fp);
	return (0);
}
