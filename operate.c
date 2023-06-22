#include "monty.h"

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
 * pop - removes top element of the stack
 *
 * Description:
 * @stack: double pointer to head node list
 * @lineNumb: line number of bytecode
*/

void pop(stack_t **stack, unsigned int lineNumb)
{
	stack_t *temp;

	if (!(*stack))
	{
		printf("L%u: sorry can't pop an empty stack\n", lineNumb);
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
 * @lineNumb: line number of bytecode
*/

void swap(stack_t **stack, unsigned int lineNumb)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->pres)
	{
		printf("L%u: sorry can't swap, stack too short\n", lineNumb);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->pres;
	/* if the stack has more > two element */
	if (temp->pres)
	{
		(*stack)->pres = temp->pres;
		temp->pres->pres = *stack;
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
 * @lineNumb: bytecode file line number
*/


void pall(stack_t **stack, unsigned int lineNumb)
{
	void lineNumb;
	stack_t *temp;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->p);
		temp = temp->pres;
	}
}
