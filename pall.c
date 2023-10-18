#include "monty.h"

/**
* pall - prints all elements in stack
* @stack: stack top
* @line_number: script line under execution
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	char *opcode;

	opcode = strtok(bundle.line_text, DELIM);
	if (stack && *stack)
	{
		tmp = *stack;
		while (tmp)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}
}
