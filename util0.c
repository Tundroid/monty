#include "monty.h"

/**
 * stack_alloc - allocs memory for stack item
 *
 * Return: pointer to allocated stack item
 * Description: prints error and exit if malloc fails
*/
void *stack_alloc(void)
{
	stack_t *tmp = malloc(sizeof(stack_t));

	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		bundle.status = EXIT_FAILURE;
		shutdown();
	}
	return (tmp);
}

/**
 * execute - finds and calls function corresponding to opcode
*/
void execute(void)
{
	short i = 0;
	char *opcode;
	instruction_t action[] = {
		{"pall", pall},
		{"push", push},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	strcpy(bundle.tmp, bundle.line_text);
	opcode = strtok(bundle.tmp, DELIM);
	if (!opcode)
		return;
	bundle.line_number++;
	while (action[i].opcode)
	{
		if (strcmp(opcode, action[i++].opcode) == 0)
		{
			action[--i].f(&bundle.stack, bundle.line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", bundle.line_number, opcode);
	bundle.status = EXIT_FAILURE;
	shutdown();
}

/**
 * is_integer - checks if a string contains only integers
 * @str: string to be checked
 *
 * Return: true if str contains only integers else false
*/
bool is_integer(char *str)
{
	char *tmp = str;
	if (*tmp == '-')
		tmp++;
	while (*tmp)
		if (!isdigit(*tmp++))
			return (false);
	return (true);
}

/**
 * shutdown - terminates program
 *
 * Description: exits with appropriate status code and
 * prints error message on error
*/
void shutdown(void)
{
	stack_t *tmp;

	fclose(bundle.file);

	while ((tmp = bundle.stack))
	{
		bundle.stack = bundle.stack->next;
		free(tmp);
	}
	exit(bundle.status);
}
