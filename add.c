#include "monty.h"

/**
 * f_add - Adds the top two elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */
void f_add(stack_t **head, unsigned int counter)
{
    S tack_t *current = *head;
    int len = 0, sum;

    while (current)
    {
        current = current->next;
        len++;
    }

    if (len < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;
    sum = current->n + current->next->n;
    current->next->n = sum;
    *head = current->next;
    free(current);
}
