#include "monty.h"

/**
* pop - removes last element from stack
* @stack: stack top
* @line_number: script line under execution
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	char *opcode;

	opcode = strtok(bundle.line_text, DELIM);
	if (strtok(NULL, DELIM))
	{
		fprintf(stderr, "L%d: usage: %s\n", line_number, opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}

	if (stack && *stack)
	{
		printf("%d\n", (*stack)->n);
		tmp = (*stack)->next;
		if (tmp)
			tmp->prev = NULL;
		free(*stack);
		*stack = tmp;
	}
	else
	{
		fprintf(stderr, "L%d: can't %s an empty stack\n", line_number, opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}
}
