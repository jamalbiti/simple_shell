#include "head.h"

/**
 * custom_free - frees an array of strings
 * @str_array: Pointer to the array of strings to be freed
 */
void custom_free(char **str_array)
{
int index = 0;

if (str_array == NULL)
return;

for (index = 0; str_array[index]; index++)
free(str_array[index]);

free(str_array);
}

/**
 * custom_calloc - allocates memory for an array, using malloc.
 * @num_elements: Number of elements in the array
 * @element_size: Size of each element in bytes
 * Return: Pointer to the allocated memory or NULL if failure
 */
void *custom_calloc(unsigned int num_elements, unsigned int element_size)
{
char *ptr;
unsigned int i;

if (num_elements == 0 || element_size == 0)
return (NULL);

ptr = malloc(element_size * num_elements);
if (ptr == NULL)
return (NULL);

for (i = 0; i < element_size * num_elements; i++)
ptr[i] = 0;

return (ptr);
}
