#include "monty.h"

/**
* mode - prints all elements in stack
* @stack: stack top
* @line_number: script line under execution
*/
void mode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	char *opcode;

	UNUSED(line_number);
	opcode = strtok(bundle.line_text, " \n");
	if (strcmp("stack", opcode) == 0)
	{
		if (bundle.mode != _stack)
			bundle.mode = _stack;
		else
			return;
	}
	if (strcmp("queue", opcode) == 0)
	{
		if (bundle.mode != _queue)
			bundle.mode = _queue;
		else
			return;
	}
	if (stack && *stack && (*stack)->next)
	{
		tmp = *stack;
		while ((tmp = tmp->next) && tmp->next)
			;
		tmp->next = tmp->prev;
		tmp->prev = NULL;
		(*stack)->prev = (*stack)->next;
		(*stack)->next = NULL;
		*stack = tmp;
	}
}
