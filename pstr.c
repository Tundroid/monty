#include "monty.h"

/**
* pstr - prints all elements in stack
* @stack: stack top
* @line_number: script line under execution
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	UNUSED(line_number);
	if (stack && *stack)
	{
		tmp = *stack;
		while (tmp)
		{
			if (!__isascii(tmp->n) || tmp->n == 0)
				break;
			printf("%c", tmp->n);
			tmp = tmp->next;
		}
	}
	putchar('\n');
}
