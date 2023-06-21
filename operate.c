#include "monty.h"
#include <ctype.h>

/**
 * _isdigit - checks if string is a number
 *
 * Description:
 * @strg: character string
 *
 * Return: 1 if string is number, otherwise (-1)
*/

int _isdigit(char *strg)
{
	int prv = 0;
	/** loop through char string **/
	while (strg[prv])
	{
		if (!(isdigit(strg[prv])))
			return (-1);
		prv++;
	}
	return (1);
}

/**
 * push - pushes stack element
 *
 * Description:
 * @stack: head of list double pointer
 * @lineNumb: bytcode line number
*/

void push(stack_t **stack, unsigned int lineNumb)
{
	int source;
	stack_t *newNode;

	newNode = malloc(sizeof(size_t));
	if (!newNode)
	{
		printf("Error: malloc(memory allocation) failed\n");
		exit(EXIT_FAILURE);
	}

	if (!monty.arg || (_isdigit(monty.arg) == -1))
	{
		printf("L%u: to usage: push the integer\n", lineNumb);
		exit(EXIT_FAILURE);
	}
	source = atoi(monty.arg);
	newNode->p = source;
	newNode->pres = NULL;
	new_node->prev = NULL;

	if (!(*stack))
	{
		(*stack) = newNode;
		return;
	}
	/* IF THE stack is ! NULL */
	newNode->pres = (*stack);
	(*stack)->past = newNode;
	(*stack) = newNode;
}

/**
 * pall - prints all elements
 *
 * Description:
 * @stack: head of list double pointer
 * @lineNumb: bytecode file line number
*/
void pall(stack_t **stack, unsigned int lineNumb)
{
	stack_t *temp;

	if (!(*stack))
		return;

	if (monty.arg)
	{
		printf("L%u: to usage: pall\n", lineNumb);
		exit(EXIT_FAILURE);
	}

	temp = (*stack);
	while (temp)
	{
		printf("%d\n", temp->p);
		temp = temp->pres;
	}
}
