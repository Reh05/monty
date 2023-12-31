#include "monty.h"
/**
 * _readline - reads a line in the file
 * @file: file to be worked on
 * @stack: stack
 * Return: nothing
 */
void _readline(FILE *file, stack_t **stack)
{
	char line[BUFFER_SIZE], *opcode;
	int i;
	unsigned int line_number = 0;
	instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{NULL, NULL}
	};

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \n");
		if (opcode == NULL)
			continue;
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(stack, line_number);
				break;
			}
		}
		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number,
					opcode);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
}
