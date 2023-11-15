#include "head.h"

/**
 * handle_aliases - Handles aliases for the shell.
 * @count: Number of arguments.
 * @arguments: Array of arguments.
 * @program_name: Name of the program.
 * @alias_list: List of aliases with name and value.
 * @alias_count: Number of existing aliases.
 * @split_line: Split line.
 * @input_line: Input line.
 * Return: Returns success.
 */
int handle_aliases(int count, char **arguments, char *program_name,
AliasStruct *alias_list, int *alias_count,
char **split_line, char *input_line)
{
char **alias_parts;
int i, j;
(void)program_name;
(void)split_line;
(void)input_line;

if (count == 1)
{
for (i = 0; *alias_count && i < *alias_count; i++)
{
custom_print_string(1, alias_list[i].name), custom_print_string(1, "='");
custom_print_string(1, alias_list[i].value), custom_print_string(1, "'\n");
}
}
for (i = 1; i < count; i++)
{
alias_parts = custom_strtok(arguments[i], "'="),
j = custom_getalias(alias_list, alias_parts[0], *alias_count);
if (!find_substring(arguments[i], "="))
{
if (j != -1)
{
custom_print_string(1, alias_list[j].name), custom_print_string(1, "='");
custom_print_string(1, alias_list[j].value), custom_print_string(1, "'\n");
}
else
report_error(program_name, arguments, arguments[i], 10);
}
else if (j != -1)
{
alias_list[j].value = malloc(my_strlen(alias_parts[1]) + 1 + my_strlen("''"));
custom_strcpy(alias_list[j].value, alias_parts[1]);
}
else
{
alias_list[*alias_count].name = malloc(my_strlen(alias_parts[0]) + 1);
alias_list[*alias_count].value = malloc(my_strlen(alias_parts[1]) +
		1 + my_strlen("''"));
custom_strcpy(alias_list[*alias_count].name, alias_parts[0]);
custom_strcpy(alias_list[*alias_count].value, alias_parts[1]);
(*alias_count)++;
}
}
return (1);
}
