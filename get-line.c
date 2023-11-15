#include "head.h"

/**
 * read_line - Reads input from the standard input (stdin).
 * @user_input: Pointer to the string where the input will be stored.
 * Return: Length of the string read.
 */
int read_line(char **user_input)
{
int length;

*user_input = custom_calloc(10240, sizeof(char));
length = read(STDIN_FILENO, *user_input, 10240);
(*user_input)[length] = '\0';
return (length);
}

/**
 * read_file - Reads input from a file.
 * @user_input: Pointer to the string where the file content will be stored.
 * @file_args: Array containing file-related arguments.
 * Return: Number of characters read from the file.
 */
int read_file(char **user_input, char **file_args)
{
ssize_t length;
int file_descriptor;

file_descriptor = open(file_args[1], O_RDONLY);
if (file_descriptor == -1)
{
report_error(file_args[0], file_args, NULL, 11);
exit(EXIT_FAILURE);
}
*user_input = custom_calloc(10240, sizeof(char));
length = read(file_descriptor, *user_input, 10240);
close(file_descriptor);
while (**user_input == ' ' || **user_input == '\t')
(*user_input)++, length--;
(*user_input)[length] = '\0';
return (length);
}
