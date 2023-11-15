#include "head.h"

/**
 * custom_getenv - retrieves custom environmental variables
 * @custom_var: custom variable name
 * Return: custom string
 */
char *custom_getenv(char *custom_var)
{
int i;
char *custom_temp;

for (i = 0; environ[i]; i++)
{
if (!my_strncmp(custom_var, environ[i],
my_strlen(custom_var)))
{
custom_temp = find_substring(environ[i], "=");
custom_temp++;
return (custom_temp);
}
}
return (NULL);
}

/**
 * custom_getalias -retrieve aliases
 * @alias: aliases
 * @var: variable name
 * @idx: index
 * Return: string
 */
int custom_getalias(AliasStruct *alias, char *var, int idx)
{
	int i;

	for (i = 0; i < idx; i++)
	{
		if (!custom_strcmp(var, alias[i].name))
			return (i);
	}
	return (-1);
}
