#include "head.h"

/**
 * my_exit_function - function to exit
 * @num_args: arguments count
 * @arguments: arguments
 * @program_name: program name
 * @my_alias: struct
 * @index_value: index
 * @split_line: split line
 * @input_line: line
 * Return: success
 */
int my_exit_function(int num_args, char **arguments, char *program_name,
AliasStruct *my_alias, int *index_value, char **split_line,
char *input_line)
{
int i = 0;

(void)my_alias;
(void)index_value;
for (; num_args > 1 && arguments[1][i]; i++)
{
if (arguments[1][i] < '0' || arguments[1][i] > '9')
{
report_error(program_name, arguments, NULL, 2);
return (0);
}
}
if (num_args > 1)
i = convert_string_to_integer(arguments[1]);
custom_free(split_line);
free(input_line);
custom_free(arguments);
exit(i);
return (1);
}
/**
 * custom_change_dir - handles cd
 * @arg_count: arguments count
 * @arg_list: arguments
 * @prog_name: program name
 * @alias_struct: struct
 * @index_ptr: index
 * @split_line: split line
 * @input_line: line
 * Return: success
 */
int custom_change_dir(int arg_count, char **arg_list, char *prog_name,
AliasStruct *alias_struct, int *index_ptr,
char **split_line, char *input_line)
{
char *path, *temp;

(void)alias_struct;
(void)index_ptr;
(void)input_line;
(void)split_line;
path = arg_count == 1 || custom_strcmp(arg_list[1], "~") == 0
? custom_getenv("HOME") : arg_list[1];
if (chdir(path) < 0)
{
report_error(prog_name, arg_list, path, 3);
return (0);
}
temp = custom_getenv("PWD");
custom_strcpy(temp, path);
if (arg_count == 1)
{
custom_print_string(1, path);
write(STDOUT_FILENO, "\n", 1);
}
return (1);
}
/**
 * custom_export - handles setenv
 * @arg_count: arguments count
 * @arguments: arguments
 * @program_name: program name
 * @custom_alias: struct
 * @index_ptr: index
 * @custom_split: split line
 * @custom_line: line
 * Return: success
 */
int custom_export(int arg_count, char **arguments, char *program_name,
AliasStruct *custom_alias, int *index_ptr, char **custom_split, char *custom_line)
{
int i = 0;
char *temp = NULL;

(void)custom_alias;
(void)index_ptr;
(void)custom_split;
(void)custom_line;
if (arg_count != 3)
{
report_error(program_name, arguments, NULL, 4);
return (0);
}
else
{
temp = custom_getenv(arguments[1]);
if (temp)
custom_strcpy(temp, arguments[2]);
else
{
while (environ[i])
i++;
environ[i] = custom_calloc(my_strlen(arguments[1]) + my_strlen(arguments[2]) + 3, 1);
custom_strcat(environ[i], arguments[1]);
custom_strcat(environ[i], "=");
custom_strcat(environ[i], arguments[2]);
environ[++i] = NULL;
}
return (1);
}
}

