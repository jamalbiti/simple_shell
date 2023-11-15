#include "head.h"

/**
 * custom_strcat - concatenates two strings
 * @destination: destination string
 * @source: source string
 * Return: pointer to the destination string
 */
char *custom_strcat(char *destination, char *source)
{
int i, j;

for (i = 0; destination[i] != '\0'; i++)
;

destination[i] = ' ';

for (j = 0; source[j] != '\0'; i++, j++)
destination[i] = source[j];

destination[i] = '\0';
return (destination);
}


/**
 * remove_first_char - removes the first character of a given string
 * @string_ptr: pointer to the string whose first character needs to be removed
 */
void remove_first_char(char **string_ptr)
{
int index;

for (index = 0; (*string_ptr)[index]; index++)
(*string_ptr)[index] = (*string_ptr)[index + 1];
}
