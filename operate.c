#include "monty.h"

/**
 * push - pushes stack element
 *
 * Description:
 * @stack: head of list double pointer
 * @line: bytcode line number
*/

void push(stack_t **stack, unsigned int line)
{
	int source;
	stack_t *newNode;

	newNode = malloc(sizeof(size_t));
	if (!newNode)
	{
		dprintf(STDERR_FILENO, "Error: malloc(memory allocation) failed\n");
		exit(EXIT_FAILURE);
	}

	if (!monty.arg || (_isdigit(monty.arg) == -1))
	{
		dprintf(STDERR_FILENO, "L%u: to usage: push the integer\n", line);
		exit(EXIT_FAILURE);
	}
	source = atoi(monty.arg);
	newNode->p = source;
	newNode->pres = NULL;
	newNode->past = NULL;

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
 * pop - removes top element of the stack
 *
 * Description:
 * @stack: double pointer to head node list
 * @line: line number of bytecode
*/

void pop(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: sorry can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (!(*stack)->pres)
		*stack = NULL;
	else
		*stack = (*stack)->pres, (*stack)->past = NULL;
	free(temp);
}

/**
 * swap - swaps top two elements of the stack
 *
 * Description:
 * @stack: double pointer to head node list
 * @line: line number of bytecode
*/

void swap(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->pres)
	{
		dprintf(STDERR_FILENO, "L%u: sorry can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->pres;
	/* if the stack has more > two element */
	if (temp->pres)
	{
		(*stack)->pres = temp->pres;
		temp->pres->past = *stack;
	}
	else /* if stack has only two elements */
		(*stack)->pres = NULL;
	(*stack)->past = temp;
	temp->pres = *stack;
	temp->past = NULL;
	*stack = temp;
}

/**
 * pall - prints all elements
 *
 * Description:
 * @stack: head of list double pointer
 * @line: bytecode file line number
*/


void pall(stack_t **stack, unsigned int line)
{
	stack_t *temp;
	(void)line;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->p);
		temp = temp->pres;
	}
}

/**
 * pint - prints element top of list
 *
 * Description:
 * @stack: double pointer to head node of list
 * @line: line number of bytecode
*/

void pint(stack_t **stack, unsigned int line)
{
	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: sorry can't pint, the stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->p);
}
