#include <string.h>
#include <ctype.h>
/**
 * verify_int - checks if the num in an int
 * @str: the str int to check
 * Return: Returns 0 if the string has no ints otherwise return 1
 */
int verify_int(char str[])
{
	size_t y;

	if (str == NULL)
		return (0);

	for (y = 0; y < strlen(str); y++)
	{
		if (str[0] == '-')
			continue;

		if (!isdigit(str[y]))
			return (0);
	}
	return (1);
}
