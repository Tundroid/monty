#include "monty.h"

/**
* pall - prints all elements in stack
* @stack: stack top
* @line_number: script line under execution
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	UNUSED(line_number);
	if (stack && *stack)
	{
		tmp = *stack;
		while (tmp)
		{
			printf("%d\n", tmp->n);
			fflush(stdout);
			tmp = tmp->next;
		}
	}
}
