#include "head.h"

/**
 * is_valid_command - checks if a command is valid
 * @command: command
 * @program_name: program name
 * @environment: environment variable
 * Return: string
 */
char *is_valid_command(char *command, char *program_name, char **environment)
{
int i;
struct stat buffer;
char *path, **path_arr = NULL, *my_env_function;

my_env_function = custom_getenv("PATH");
if (!my_env_function)
{
if (!access(command, X_OK) && stat(command, &buffer) == 0)
return (command);
return (NULL);
}
else if (*my_env_function == '\0')
{
report_error(program_name, environment, NULL, 1);
exit(EXIT_FAILURE);
}
else
path_arr = custom_strtok(my_env_function, ":");
for (i = 0; path_arr[i]; i++)
{
if (!find_substring(command, "/"))
{
path = malloc(my_strlen(path_arr[i]) + my_strlen(command) + 3);
custom_strcpy(path, path_arr[i]);
custom_strcat(path, "/");
custom_strcat(path, command);
}
else
path = malloc(my_strlen(command) + 2), custom_strcpy(path, command);

if (!access(path, X_OK) && stat(path, &buffer) == 0)
{
custom_free(path_arr);
return (path);
}
free(path);
}

custom_free(path_arr);
return (NULL);
}
