#ifndef MOLeCULE_MONTY
#define MOLeCULE_MONTY

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LINE_CHARS 1024
#define DELIM " \n"

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct bundle_s - number and text
* @line_number: of file
* @line_text: buffer to hold line text
* @tmp: temporal text buffer
* @file: pointer to script
* @stack: to hold items
* @status: code
*/
typedef struct bundle_s
{
	unsigned int line_number;
	char line_text[MAX_LINE_CHARS];
	char tmp[MAX_LINE_CHARS];
	FILE *file;
	stack_t *stack;
	short status;
} bundle_t;

extern bundle_t bundle;

void *stack_alloc(void);
void execute(void);
void pall(stack_t **, unsigned int);
void push(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
bool is_integer(char *);
void shutdown(void);

#endif
