#include "monty.h"


void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack && *stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		if (tmp->next)
			tmp->next->prev = *stack;
		(*stack)->next = tmp->next;
		(*stack)->prev = tmp;
		tmp->next = *stack;
		tmp->prev = NULL;
		*stack = tmp;
	}
	else
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n"
						, line_number, bundle.opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}
}
