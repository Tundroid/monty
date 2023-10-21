#include "monty.h"

/**
* push - adds an elements to top of stack
* @stack: stack top
* @line_number: script line under execution
*/
void push(stack_t **stack, unsigned int line_number)
{
	char *opcode, *n;

	opcode = strtok(bundle.line_text, DELIM);
	n = strtok(NULL, DELIM);
	if (!n || !is_integer(n))
	{
		fprintf(stderr, "L%d: usage: %s integer\n", line_number, opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}

	push_helper(stack, atoi(n));
}

/**
* push_helper - helps add an element to top of stack
* @head: stack top
* @n: number to be pushed
*/
void push_helper(stack_t **head, int n)
{
	stack_t *item;
	short not_push;

	not_push = strcmp(bundle.line_text, "push");
	item = node_alloc();
	item->n = n;
	item->next = not_push || bundle.mode == _stack ? *head : NULL;
	item->prev = not_push || bundle.mode == _stack ? NULL : *head;
	if (*head)
	{
		if (not_push || bundle.mode == _stack)
			(*head)->prev = item;
		else
			(*head)->next = item;
		*head = item;
	}
	else
	{
		bundle.stack = bundle.queue = item;
	}
}
