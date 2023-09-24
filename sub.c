#include "monty.h"
/**
  *h_sub- the sustration
  *@head: stack
  *@counter: line number
  *Return: no return
 */
void h_sub(stack_t **head, unsigned int counter)
{
	stack_t *ax;
	int sus, nodes;

	ax = *head;
	for (nodes = 0; ax != NULL; nodes++)
		ax = ax->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ax = *head;
	sus = ax->next->n - ax->n;
	ax->next->n = sus;
	*head = ax->next;
	free(ax);
}
/**
 * h_swap - adds the top two elements
 * @head: stack
 * @counter: line number
 * Return: no return
*/
void h_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, ax;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	ax = h->n;
	h->n = h->next->n;
	h->next->n = ax;
}
/**
  *h_rotr- rotates stack to the bottom
  *@head: stack
  *@counter: line number
  *Return: no return
 */
void h_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *new;

	new = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (new->next)
	{
		new = new->next;
	}
	new->next = *head;
	new->prev->next = NULL;
	new->prev = NULL;
	(*head)->prev = new;
	(*head) = new;
}
