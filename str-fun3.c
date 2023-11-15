#include "head.h"

/**
 * my_strlen - Calculate the length of a string
 * @str: The input string
 * Return: The length of the string
 */
size_t my_strlen(char *str)
{
if (!str || *str == '\0')
return (0);
return (1 + my_strlen(str + 1));
}

/**
 * custom_strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: an integer value indicating the comparison result
 */
int custom_strcmp(const char *str1, char *str2)
{
for (; *str1 == *str2; str1++, str2++)
{
if (*str1 == '\0')
return (0);
}
return (*str1 - *str2);
}

/**
 * my_strncmp - compares n characters of two strings
 * @str1: pointer to the first string
 * @str2: pointer to the second string
 * @num_chars: number of characters to compare
 * Return: an integer less than, equal to, or greater than zero if the first
 * n characters of str1 are found to be less than, equal to, or greater than
 * the first n characters of str2, respectively
 */
int my_strncmp(const char *str1, char *str2, int num_chars)
{
for (; num_chars && *str1 == *str2; num_chars--, str1++, str2++)
;
if (num_chars)
return (*str1 - *str2);
return (0);
}
