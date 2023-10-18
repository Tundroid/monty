#include "monty.h"

/**
* push - adds an elements to top of stack
* @stack: stack top
* @line_number: script line under execution
*/
void push(stack_t **stack, unsigned int line_number)
{
	char *opcode, *n;

	opcode = strtok(bundle.line_text, DELIM);
	n = strtok(NULL, DELIM);
	if (!n || !is_integer(n) || strtok(NULL, DELIM))
	{
		fprintf(stderr, "L%d: usage: %s %s\n", line_number, opcode, n);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}

	push_helper(stack, atoi(n));
}

/**
* push_helper - helps add an element to top of stack
* @stack: stack top
* @n: number to be pushed
*/
void push_helper(stack_t **stack, int n)
{
	stack_t *item;

	item = stack_alloc();
	item->n = n;
	item->next = *stack;
	item->prev = NULL;
	if (*stack)
		(*stack)->prev = item;
	*stack = item;
}
