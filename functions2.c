#include "monty.h"
/**
 * add - Add the top two elements
 * @stack: ptr to the stack
 * @line_number: The line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	(*stack)->n = sum;

	free(temp);
}

/**
 * pint - Print the value at the top
 * @stack: ptr to the stack
 * @line_number: The line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * nop - Do nothing
 * @stack: ptr to the stack
 * @line_number: The line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

