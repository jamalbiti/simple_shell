#include "head.h"

/**
 * check_alias_custom - checks for aliases in a custom function
 * @arguments: the array of arguments
 * @alias_list: the list of aliases
 * @index: an integer index
 * Return: none
 */
void check_alias_custom(char ***arguments, AliasStruct *alias_list, int index)
{
int i, alias_index;

for (i = 0; (*arguments)[i]; i++)
{
alias_index = custom_getalias(alias_list, (*arguments)[i], index);
if (alias_index != -1)
{
(*arguments)[i] = NULL;
(*arguments)[i] = malloc(my_strlen(alias_list[alias_index].value) + 1);
custom_strcpy((*arguments)[i], alias_list[alias_index].value);
}
}
}
/**
 * custom_and_handling - handles custom &&
 * @input_line: input command line
 * @file_name: file name
 * @alias_array: alias array
 * @index: integer
 * Return: integer
 */
int custom_and_handling(char *input_line,
char *file_name, AliasStruct *alias_array, int *index)
{
char **arguments, **line_split;
int should_break, arg_count, cmd_selector_result, i = 0;

line_split = custom_strtok(input_line, "&\n");
for (i = 0; line_split[i]; i++)
{
arguments = custom_strtok(line_split[i], " \t");
if (count_arguments(arguments) == 0)
{
custom_free(arguments);
custom_free(line_split);
return (report_error(file_name, NULL, NULL, 7));
}
custom_free(arguments);
}
for (i = 0; line_split[i]; i++)
{
should_break = 0;
arguments = custom_strtok(line_split[i], " \t");
if (custom_strcmp(arguments[0], "alias_array"))
check_alias_custom(&arguments, alias_array, *index);
arg_count = count_arguments(arguments);
cmd_selector_result = select_command(arguments[0],
arguments, file_name, alias_array, index, line_split, input_line);
if (arg_count > 0 && cmd_selector_result < 0)
should_break = 1 - custom_fork(file_name, arguments);
else if (arg_count > 0)
should_break = 1 - cmd_selector_result;
if (should_break)
{
custom_free(arguments);
break;
}
custom_free(arguments);
}
custom_free(line_split);
return (should_break ? 0 : EXIT_FAILURE);
}
