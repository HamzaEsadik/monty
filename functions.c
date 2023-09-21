#include "monty.h"
/**
 * push - push in into the stack
 * @stack: ptr to the stack
 * @line_number: The line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = line_number;

	newnode->prev = NULL;
	newnode->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = newnode;

	*stack = newnode;
}

/**
 * pall - print all elements in the stack
 * @stack: ptr to the stack
 * @line_number: The line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pop - remove top element of a the stack
 * @stack: ptr to the stack
 * @line_number: The line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * swap - swap the top two elements
 * @stack: ptr to the stack
 * @line_number: The line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;

	(*stack)->next = temp->next;
	temp->next = *stack;

	temp->prev = NULL;
	(*stack)->prev = temp;

	*stack = temp;
}

/**
 * isinteger - Check if a string is a valid integer
 * @str: The input string
 * Return: 1 if is a valid integer, 0 otherwise
 */
int isinteger(const char *str)
{
	if (!str || !*str || (*str != '-' && !isdigit(*str)))
		return (0);

	for (int i = 1; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

