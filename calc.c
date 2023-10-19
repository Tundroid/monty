#include "monty.h"

/**
* add - removes last element from stack
* @stack: stack top
* @line_number: script line under execution
*/
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	char *opcode;

	opcode = strtok(bundle.line_text, DELIM);
	if (stack && *stack && (*stack)->next)
	{
		sum = (*stack)->n + (*stack)->next->n;
		pop_helper(stack);
		pop_helper(stack);
		push_helper(stack, sum);
	}
	else
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}
}

/**
* sub - removes last element from stack
* @stack: stack top
* @line_number: script line under execution
*/
void sub(stack_t **stack, unsigned int line_number)
{
	int diff;
	char *opcode;

	opcode = strtok(bundle.line_text, DELIM);
	if (stack && *stack && (*stack)->next)
	{
		diff = (*stack)->next->n - (*stack)->n;
		pop_helper(stack);
		pop_helper(stack);
		push_helper(stack, diff);
	}
	else
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}
}

/**
* _div - removes last element from stack
* @stack: stack top
* @line_number: script line under execution
*/
void _div(stack_t **stack, unsigned int line_number)
{
	int quo;
	char *opcode;

	opcode = strtok(bundle.line_text, DELIM);
	if (stack && *stack && (*stack)->next)
	{
		if (!(*stack)->n)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			bundle.status = EXIT_FAILURE;
			shutdown();
		}
		quo = (*stack)->next->n / (*stack)->n;
		pop_helper(stack);
		pop_helper(stack);
		push_helper(stack, quo);
	}
	else
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}
}

/**
* mul - removes last element from stack
* @stack: stack top
* @line_number: script line under execution
*/
void mul(stack_t **stack, unsigned int line_number)
{
	int prod;
	char *opcode;

	opcode = strtok(bundle.line_text, DELIM);
	if (stack && *stack && (*stack)->next)
	{
		prod = (*stack)->next->n * (*stack)->n;
		pop_helper(stack);
		pop_helper(stack);
		push_helper(stack, prod);
	}
	else
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}
}

/**
* mod - removes last element from stack
* @stack: stack top
* @line_number: script line under execution
*/
void mod(stack_t **stack, unsigned int line_number)
{
	int rem;
	char *opcode;

	opcode = strtok(bundle.line_text, DELIM);
	if (stack && *stack && (*stack)->next)
	{
		if (!(*stack)->n)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			bundle.status = EXIT_FAILURE;
			shutdown();
		}
		rem = (*stack)->next->n % (*stack)->n;
		pop_helper(stack);
		pop_helper(stack);
		push_helper(stack, rem);
	}
	else
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
		bundle.status = EXIT_FAILURE;
		shutdown();
	}
}
