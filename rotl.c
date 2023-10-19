#include "monty.h"

/**
* rotl - prints all elements in stack
* @stack: stack top
* @line_number: script line under execution
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	UNUSED(line_number);
	if (stack && *stack && (*stack)->next)
	{
		top = *stack;
		bottom = top;
		while ((bottom = bottom->next) && bottom->next)
			;
		top->next->prev = NULL;
		*stack = top->next;
		bottom->next = top;
		top->next = NULL;
		top->prev = bottom;
	}
}
