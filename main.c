#include "monty.h"
/**
 * main - starting point of the program
 * @argc: Number of arguments
 * @argv: array of the arguments
 * Return: Return 0 on success, otherwise -1
 */
int main(int argc, char **argv)
{
	FILE *file;
	stack_t *stack = NULL;

	(void) argv;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	_readline(file, &stack);
	fclose(file);
	return (0);
}
