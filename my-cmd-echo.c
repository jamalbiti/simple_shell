#include "head.h"

/**
 * my_echo - handles echo $$ and $?
 * @arguments: arguments
 * Return: success
 */
int my_echo(char **arguments)
{
int process_status;

if (!custom_strcmp(arguments[0], "echo") && arguments[1])
{
if (!custom_strcmp(arguments[1], "$$"))
{
custom_to_string(1, getpid());
write(STDOUT_FILENO, "\n", 1);
return (1);
}
else if (!custom_strcmp(arguments[1], "$?"))
{
waitpid(getpid() - 1, &process_status, 0);
custom_to_string(1, WEXITSTATUS(process_status));
write(STDOUT_FILENO, "\n", 1);
return (1);
}
}
return (0);
}
