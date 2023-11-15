#include "head.h"

/**
 * custom_to_string - cast an integer to decimal
 * and print it to the specified output
 * @output_fd: the file descriptor for the
 * output (STDOUT_FILENO or STDERR_FILENO)
 * @number: the input number to be converted to a string
 * Return: the length of the string printed
 */
int custom_to_string(int output_fd, unsigned int number)
{
char digit;

if (number >= 10)
return (custom_to_string(output_fd, number / 10) +
custom_to_string(output_fd, number % 10));
digit = '0' + number;
if (output_fd == STDOUT_FILENO)
return (write(STDOUT_FILENO, &digit, 1));
return (write(STDERR_FILENO, &digit, 1));
}

/**
 * custom_print_string - print a
 * string to the specified output
 * @output_fd: the file descriptor for the
 * output (STDOUT_FILENO or STDERR_FILENO)
 * @str: the input string to be printed
 * Return: the length of the string printed
 */
int custom_print_string(int output_fd, char *str)
{
if (output_fd == STDOUT_FILENO)
return (write(STDOUT_FILENO, str, my_strlen(str)));
return (write(STDERR_FILENO, str, my_strlen(str)));
}
