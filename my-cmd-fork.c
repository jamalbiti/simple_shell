#include "head.h"

/**
 * custom_fork - custom implementation of fork to create a new process
 * @cmd_name: command name
 * @cmd_args: arguments
 * Return: success
 */
int custom_fork(char *cmd_name, char **cmd_args)
{
pid_t pid;
int status, success = 1;
char *custom_path = NULL;

custom_path = is_valid_command(cmd_args[0], cmd_name, cmd_args);
if (custom_path != NULL)
{
pid = fork();
if (pid == 0)
{
success = execute_command(cmd_args, cmd_name, custom_path);
exit(0);
}
else
waitpid(pid, &status, 0);
free(custom_path);
}
else
{
report_error(cmd_name, cmd_args, NULL, 1);
success = 0;
}
return (success);
}
