#include "head.h"

/**
 * find_substring - locates a substring in a given string.
 * @str: the string to search in
 * @sub: the substring to find
 * Return: pointer to the first occurrence of the
 * substring, or NULL if not found
 */

char *find_substring(char *str, char *sub)
{
int index_str, index_sub;

if (*str == '\0' && *sub == '\0')
return (NULL);

for (index_str = 0; str[index_str] != '\0'; index_str++)
{
for (index_sub = 0; sub[index_sub] != '\0'; index_sub++)
{
if (sub[index_sub] != str[index_str + index_sub])
break;
}

if (sub[index_sub] == '\0')
return (&str[index_str]);
}

return (NULL);
}

/**
 * my_memcpy - copies memory area.
 * @destination: destination memory area
 * @source: source memory area
 * @num_bytes: number of bytes to copy
 * Return: pointer to the destination memory area
 */
char *my_memcpy(char *destination, char *source, unsigned int num_bytes)
{
unsigned int i;

for (i = 0; i < num_bytes; i++)
{
destination[i] = source[i];
}
return (destination);
}
