#include "monty.h"

/**
* nop - removes last element from stack
* @stack: stack top
* @line_number: script line under execution
*/
void nop(stack_t **stack, unsigned int line_number)
{
	char *opcode;
	int stat;

	stat = UNUSED(*stack, EXIT_FAILURE);
	opcode = strtok(bundle.line_text, DELIM);
	if (strtok(NULL, DELIM))
	{
		fprintf(stderr, "L%d: usage: %s\n", line_number, opcode);
		bundle.status = stat;
		shutdown();
	}
}
