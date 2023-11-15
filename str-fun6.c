#include "head.h"

/**
 * replace_custom_substring - custom implementation to replace a substring
 * @input_str: the input string
 * @old_sub: the old substring to be replaced
 * @new_sub: the new substring to replace with
 * Return: Nothing
 */
void replace_custom_substring(char *input_str, char *old_sub, char *new_sub)
{
char *start = NULL;
size_t old_sub_len = my_strlen(old_sub);
size_t new_sub_len = my_strlen(new_sub);
size_t k = new_sub_len, l = old_sub_len;

start = find_substring(input_str, old_sub);
if (!start)
return;

do {
start[k++] = start[l++];
} while (start[l]);
start[k] = '\0';
my_memcpy(start, new_sub, new_sub_len);
replace_custom_substring(start + new_sub_len, old_sub, new_sub);
}

/**
 * convert_string_to_integer - converts a string to an integer
 * @str: The input string to be converted
 *
 * Return: The converted integer value
 */

int convert_string_to_integer(char *str)
{
int index;
int result = 0;

for (index = 0; str[index] != '\0'; index++)
{
result *= 10;
result += (str[index] - '0');
}
return (result);
}
