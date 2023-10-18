#include "monty.h"

/**
* push - adds an elements to top of stack
* @stack: stack top
* @line_number: script line under execution
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *item;
	char *opcode, *n;

	opcode = strtok(bundle.line_text, DELIM);
	n = strtok(NULL, DELIM);
	if (!n || !is_integer(n) || strtok(NULL, DELIM))
	{
		fprintf(stderr, "L%d: usage: %s %s", line_number, opcode, n);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}

	item = stack_alloc();
	item->n = atoi(n);
	item->next = *stack;
	item->prev = NULL;
	if (*stack)
		(*stack)->prev = item;
	*stack = item;
}
