#include "head.h"
/**
 * display_error - prints error messages to stderr (part 2)
 * @arguments: the arguments passed to the function
 * @file_path: the path of the file
 * @error_code: the error index
 */
void display_error(char **arguments, char *file_path, int error_code)
{
char semicolon = ';';

if (error_code == 5)
custom_print_string(2, "usage: unsetenv VARIABLE VALUE");
else if (error_code == 6)
{
custom_print_string(2, "environment variable ");
custom_print_string(2, arguments[1]);
custom_print_string(2, " not found");
}
else if (error_code == 7)
custom_print_string(2, "Syntax error: \"&\" unexpected");
else if (error_code == 8)
custom_print_string(2, "Syntax error: \"|\" unexpected");
else if (error_code == 9)
{
custom_print_string(2, "Syntax error: \"");
write(STDERR_FILENO, &semicolon, 1);
write(STDERR_FILENO, &semicolon, 1);
custom_print_string(2, "\" unexpected");
}
else if (error_code == 10)
{
custom_print_string(2, "alias: ");
custom_print_string(2, file_path);
custom_print_string(2, " not found");
}
}
/**
 * report_error - prints error messages to stderr (part 1)
 * @prog_name: name of the program
 * @arguments: array of arguments
 * @file_path: path to the file
 * @error_code: error index
 * Return: return value
 */
int report_error(char *prog_name, char
**arguments, char *file_path, int error_code)
{
static unsigned int error_count;

if (!error_code)
{
error_count++;
return (0);
}
if (error_code == 11)
{
custom_print_string(2, prog_name);
custom_print_string(2, ": 0: Can't open ");
custom_print_string(2, arguments[1]);
write(STDERR_FILENO, "\n", 1);
return (EXIT_FAILURE);
}
custom_print_string(2, prog_name);
custom_print_string(2, ": ");
custom_to_string(2, error_count);
custom_print_string(2, ": ");
if (error_code == 1)
{
custom_print_string(2, arguments[0]);
custom_print_string(2, ": not found");
}
else if (error_code == 2)
{
custom_print_string(2, "exit: Illegal number: ");
custom_print_string(2, arguments[1]);
}
else if (error_code == 3)
{
custom_print_string(2, "cd: can't cd to ");
custom_print_string(2, file_path);
}
else if (error_code == 4)
custom_print_string(2, "usage: setenv VARIABLE VALUE");
else
display_error(arguments, file_path, error_code);
write(STDERR_FILENO, "\n", 1);
return (EXIT_FAILURE);
}
