#include "head.h"

/**
 * execute_command - executes commands
 * @args: argument array
 * @program_name: name of the program
 * @program_path: path of the program
 * Return: 1 on success, 0 on failure
 */
int execute_command(char **args, char *program_name, char *program_path)
{
int i = 0, success = 1;
char *environment_variable;

(void)program_name;
if (args)
{
i = my_echo(args);
if (i == 0 && args[1] && args[1][0] == '$')
{
environment_variable = custom_getenv(args[1] + 1);
if (environment_variable)
{
args[1] = malloc(sizeof(environment_variable));
custom_strcpy(args[1], environment_variable);
}
else
{
write(STDOUT_FILENO, "\n", 1);
return (1);
}
}
if (i == 0)
{
if (execve(program_path, args, environ) == -1)
success = 0;
}
custom_free(args);
}
return (success);
}
