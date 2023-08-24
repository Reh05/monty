#include "monty.h"
/**
 * pall - displays values in the stack
 * @stack: stack to be displayed
 * @line_number: present line number being read
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void) line_number;
	while (current != NULL)
	{
		stack_t *tmp = current;

		printf("%d\n", current->n);
		current = current->next;
		free(tmp);
	}
	*stack = NULL;
}
