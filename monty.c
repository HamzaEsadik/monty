#include "monty.h"

/**
 * main - Entry Point
 * @argc: argc
 * @argv: argv
 * Return: 0 if success
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r"); /*open file read only*/

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack_t *stack = NULL;

	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		exec_commands(&stack, line, line_number);
	}
	fclose(file);
	stackfree(stack);

	if (line)
		free(line);

	exit(EXIT_SUCCESS);
}

