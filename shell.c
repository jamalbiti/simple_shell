#include "head.h"

/**
 * main - simple shell program
 * @argc_custom: arguments count
 * @args_custom: arguments set
 * Return: 0
 */
int main(int argc_custom, char **args_custom)
{
AliasStruct alias_custom;
int idx_custom = 0, ret_val_custom = 0;
char *input_custom = NULL, *name_custom = args_custom[0], *temp_custom = NULL;

(void) argc_custom;
alias_custom.name = NULL;
alias_custom.value = NULL;
while (1)
{
if (isatty(0) && argc_custom == 1)
write(STDOUT_FILENO, "$ ", 2);
if (argc_custom == 1 && read_line(&input_custom) <= 0)
{
free(input_custom);
if (isatty(0))
write(STDOUT_FILENO, "\n", 1);
exit(ret_val_custom);
}
else if (argc_custom != 1 && read_file(&input_custom, args_custom) <= 0)
{
free(input_custom);
if (isatty(0))
write(STDOUT_FILENO, "\n", 1);
exit(ret_val_custom);
}
temp_custom = find_substring(input_custom, "#");
if (temp_custom)
*temp_custom = '\0';
if (*input_custom != '\0' && custom_strcmp(input_custom, "\n"))
{
report_error(name_custom, NULL, NULL, 0);
ret_val_custom = split_command(input_custom,
		name_custom, &alias_custom, &idx_custom);
}
free(input_custom);
if (argc_custom != 1)
return (0);
}
}
