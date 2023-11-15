#include "head.h"
/**
 * or_handling - handles ||
 * @input_line: input command line
 * @filename: file name
 * @alias_list: alias array
 * @index: integer
 * Return: integer
 */
int or_handling(char *input_line,
char *filename, AliasStruct *alias_list, int *index)
{
char **args_array, **split_line;
int break_condition, arg_count, selector, i = 0;

split_line = custom_strtok(input_line, "|\n");
for (i = 0; split_line[i]; i++)
{
args_array = custom_strtok(split_line[i], " \t");
if (count_arguments(args_array) == 0)
{
custom_free(args_array);
custom_free(split_line);
return (report_error(filename, NULL, NULL, 8));
}
custom_free(args_array);
}
i = 0;
for (i = 0; split_line[i]; i++)
{
args_array = custom_strtok(split_line[i], " \t");
if (custom_strcmp(args_array[0], "alias"))
check_alias_custom(&args_array, alias_list, *index);
break_condition = 0;
arg_count = count_arguments(args_array);
selector = select_command(args_array[0], args_array,
filename, alias_list, index, split_line, input_line);
if (arg_count > 0 && selector < 0)
break_condition = custom_fork(filename, args_array);
else if (arg_count > 0)
break_condition = selector;
if (break_condition)
{
custom_free(args_array);
break;
}
custom_free(args_array);
}
custom_free(split_line);
return (break_condition ? 0 : EXIT_FAILURE);
}

/**
 * handle_semicolon - handles ;
 * @input_line: input command line
 * @file_name: file name
 * @alias_array: alias array
 * @index: integer
 * Return: integer
 */
int handle_semicolon(char *input_line,
char *file_name, AliasStruct *alias_array, int *index)
{
char **tokens, **line_split;
int argument_count, i = 0, fork_status = 0;

line_split = custom_strtok(input_line, ";\n");
for (i = 0; line_split[i]; i++)
{
tokens = custom_strtok(line_split[i], " \t");
if (count_arguments(tokens) == 0)
{
custom_free(tokens);
custom_free(line_split);
return (report_error(file_name, NULL, NULL, 9));
}
custom_free(tokens);
}
custom_free(line_split);

line_split = custom_strtok(input_line, "@;\n");
for (i = 0; line_split[i]; i++)
{
tokens = custom_strtok(line_split[i], " \t");
if (find_substring(input_line, "alias"))
check_alias_custom(&tokens, alias_array, *index);
argument_count = count_arguments(tokens);
if (argument_count > 0 && select_command(tokens[0], tokens,
file_name, alias_array, index, line_split, input_line) < 0)
custom_fork(file_name, tokens);
else if (!find_substring(input_line, "@") && argument_count == 0)
{
custom_free(line_split);
custom_free(tokens);
return (report_error(file_name, NULL, NULL, 9));
}
custom_free(tokens);
}
custom_free(line_split);
return (fork_status ? EXIT_FAILURE : 0);
}


/**
 * split_command - reads command line (input)
 * @command: input command line
 * @program_name: file name
 * @aliases_list: alias array
 * @index_ptr: integer
 * Return: integer
 */
int split_command(char *command,
char *program_name, AliasStruct *aliases_list, int *index_ptr)
{
size_t old_length;
size_t new_length;

while (*command == ' ' || *command == '\t')
remove_first_char(&command);

old_length = my_strlen(command);
if (old_length == 1)
return (0);

replace_custom_substring(command, "&&", "&");
new_length = my_strlen(command);
if (new_length < old_length)
{
replace_custom_substring(command, "&&", "&");
if (my_strlen(command) < new_length)
return (report_error(program_name, NULL, NULL, 7));
return (custom_and_handling(command, program_name, aliases_list, index_ptr));
}

replace_custom_substring(command, "||", "|");
new_length = my_strlen(command);
if (new_length < old_length)
{
replace_custom_substring(command, "||", "|");
if (my_strlen(command) < new_length)
return (report_error(program_name, NULL, NULL, 8));
return (or_handling(command, program_name, aliases_list, index_ptr));
}

if (find_substring(command, ";;"))
return (report_error(program_name, NULL, NULL, 9));

replace_custom_substring(command, "\n", "@");
return (handle_semicolon(command, program_name, aliases_list, index_ptr));
}
