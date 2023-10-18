#include "monty.h"

/**
* add - removes last element from stack
* @stack: stack top
* @line_number: script line under execution
*/
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	char *opcode;

	opcode = strtok(bundle.line_text, DELIM);
	if (strtok(NULL, DELIM))
	{
		fprintf(stderr, "L%d: usage: %s\n", line_number, opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}

	if (stack && *stack && (*stack)->next)
	{
		sum = (*stack)->n + (*stack)->next->n;
		pop_helper(stack);
		pop_helper(stack);
		push_helper(stack, sum);
	}
	else
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}
}
