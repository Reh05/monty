#include "monty.h"
/**
 * swap - swaps the stack's top 2 components
 * @stack: the stack we're working on
 * @line_number: line to be read
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;

	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;

	*stack = second;
}
