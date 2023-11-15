#include "head.h"

/**
 * custom_unsetenv - handles the unsetenv functionality
 * @count: number of arguments
 * @arguments: array of arguments
 * @programName: name of the program
 * @data: pointer to some data structure
 * @index: index value
 * @splitLine: split line data
 * @currentLine: current line data
 * Return: success flag (1 on success, 0 on failure)
 */
int custom_unsetenv(int count, char **arguments, char *programName,
AliasStruct *data, int *index, char **splitLine, char *currentLine)
{
int i;

(void)data;
(void)index;
(void)splitLine;
(void)currentLine;

if (count != 2)
{
report_error(programName, arguments, NULL, 5);
return (0);
}
else if (custom_getenv(arguments[1]) == NULL)
{
report_error(programName, arguments, NULL, 6);
return (0);
}
else
{
for (i = (0); environ[i]; i++)
{
if (my_strncmp(environ[i], arguments[1], my_strlen(arguments[1])) == 0)
{
free(environ[i]);
break;
}
}
return (1);
}
}


/**
 * my_env_function - handles and prints environment variables
 * @count: count of arguments
 * @arguments: array of arguments
 * @program_name: name of the program
 * @my_aliases: pointer to aliases struct
 * @index_ptr: pointer to index
 * @my_split: array of split line
 * @input_line: input line
 * Return: success (1)
 */
int my_env_function(int count, char **arguments, char *program_name,
AliasStruct *my_aliases, int *index_ptr, char **my_split, char *input_line)
{
int i;

(void) count;
(void) arguments;
(void) program_name;
(void) my_split;
(void) my_aliases;
(void) index_ptr;
(void) input_line;

for (i = 0; environ[i]; i++)
{
custom_print_string(1, environ[i]);
write(STDOUT_FILENO, "\n", 1);
}

return (1);
}
