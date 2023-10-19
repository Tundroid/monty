#include "monty.h"

/**
* rotr - prints all elements in stack
* @stack: stack top
* @line_number: script line under execution
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	UNUSED(line_number);
	if (stack && *stack && (*stack)->next)
	{
		top = *stack;
		bottom = top;
		while ((bottom = bottom->next) && bottom->next)
			;
		bottom->prev->next = NULL;
		bottom->next = *stack;
		bottom->next->prev = bottom;
		bottom->prev = NULL;
		*stack = bottom;
	}
}
