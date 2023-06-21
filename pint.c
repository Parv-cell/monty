/**
 * pint - prints element at the top of a list
 *
 * Description:
 * @stack: double pointer to head node list
 * @lineNumb: line number of bytecode
*/

void pint(stack_t **stack, unsigned int lineNumb)
{
	if (!(*stack))
	{
		printf("L%u: can't pint file, empty stack\n", lineNumb);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->p);
}
