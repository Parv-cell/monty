#include "monty.h"

/**
 * ops_acq - acquires the corresponding function of the opcode
 *
 * Description:
 * @opCode: opcode from bytecode
 *
 * Return: NULL if function is invalid
*/

void (*ops_acq(char *opCode))(stack_t **stack, unsigned int lineNumb)
{
	int parv = 0;

	instruct_t op_list[] = {
		{"push", push},
		{"pint", pint},
		{"pall", pall},
		{NULL, NULL},
	};

	while (op_list[parv].opCode)
	{
		if (strcmp(opCode, op_list[i].opCode) == 0)
			return (op_list[parv].fun);
		parv++;
	}
	return (NULL);
}
