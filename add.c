#include "monty.h"
/**
 * add - Adds the stack's top 2 components
 * @stack: the stack being worked on
 * @line_number: line to be read
 *
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	int total;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	total = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = total;
