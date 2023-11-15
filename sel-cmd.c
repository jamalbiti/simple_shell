#include "head.h"

/**
 * select_command - checks for built-in functions
 * @command: command name
 * @arguments: arguments
 * @program_name: name of the program
 * @alias_data: struct containing aliases
 * @index: index value
 * @split_line: split line of input
 * @input_line: input line
 * Return: success value
 */
int select_command(const char *command, char **arguments,
char *program_name, AliasStruct *alias_data,
int *index, char **split_line, char *input_line)
{
cmd_executer executers[] = {
{"exit", my_exit_function},
{"cd", custom_change_dir},
{"setenv", custom_export},
{"unsetenv", custom_unsetenv},
{"env", my_env_function},
{"alias", handle_aliases},
{NULL, NULL}
};
int j = 0;

while (executers[j].execute_func != NULL &&
custom_strcmp(command, executers[j].command) != 0)
j++;

if (executers[j].execute_func != NULL)
return (executers[j].execute_func(count_arguments(arguments), arguments,
program_name, alias_data, index, split_line, input_line));
return (-1);
}

/**
 * count_arguments - counts the number of arguments
 * @arguments: arguments
 * Return: number of arguments (argc)
 */
int count_arguments(char **arguments)
{
if (arguments == NULL || *arguments == NULL)
return (0);
return (1 + count_arguments(arguments + 1));
}
