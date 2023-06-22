#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/**
 * struct stack_s - doubly linked list rep of stack / queue
 *
 * Description: doubly linked list node structure
 * for FIFO, LIFO, stack, queues
 * @p: integer
 * @past: it points to past element of stack / queue
 * @pres: it points to the present element of the stack / queue
 *
 */

typedef struct stack_s
{
	int p;
	struct stack_s *past;
	struct stack_s *pres;
} stack_t;

/**
 * struct monty_s - global variable for monty interpreter
 *
 * Description:
 * @line: line number of byte code
 * @arg: the opcode argument
 * @stack: stack of opcode
 *
*/

typedef struct monty_s
{
	char *arg;
	unsigned int line;
	stack_t *stack;
} monty_t;

/**
 * struct instruct_s - the opcode and its function
 *
 * Description: opcode and its function
 * for stack, queues, FIFO, LIFO
 * @opCode: opcode
 * @fun: function to handle opcode
 *
 */

typedef struct instruct_s
{
	char *opCode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruct_t;


FILE *check_args(int, char **);
void (*ops_acq(char *))(stack_t **, unsigned int);
void init_monty(void);

extern monty_t monty;
monty_t monty;

/* code operations */

void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void push(stack_t **, unsigned int);

int _isdigit(char *);

#endif
