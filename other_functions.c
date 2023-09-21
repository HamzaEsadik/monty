#include "monty.h"

/**
 * stackfree - Free the memory allocated for the stack
 * @stack: ptr to the stack
 */
void stackfree(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
/**
 * exec_commands - execute commands
 * @stack: ptr to a stack
 * @line: command  line
 * @line_number: line number
 */
void exec_commands(stack_t **stack, char *line, unsigned int line_number)
{
	char *opcode = strtok(line, " \t\n$");
	int i;

	if (!opcode)
		return;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"pint", pint},
		{"nop", nop},
		{NULL, NULL}};

	for (i = 0; instructions[i].opcode; i++)
	{
		if (!strcmp(opcode, instructions[i].opcode))
		{
			if (!strcmp(opcode, "push"))
			{
				char *arg = strtok(NULL, " \t\n$");

				if (!isinteger(arg))
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				instructions[i].f(stack, atoi(arg));
			}
			else
				instructions[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
