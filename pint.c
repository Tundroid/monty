#include "monty.h"

/**
* pint - prints value atop the stack
* @stack: stack top
* @line_number: script line under execution
*/
void pint(stack_t **stack, unsigned int line_number)
{
	char *opcode;

	opcode = strtok(bundle.line_text, DELIM);
	if (strtok(NULL, DELIM))
	{
		fprintf(stderr, "L%d: usage: %s", line_number, opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}

	if (stack && *stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't %s, stack empty", line_number, opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}
}
