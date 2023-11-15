#include "head.h"

/**
 * custom_strpbrk - searches a string for any of a set of bytes.
 * @str: string
 * @charset: characters to accept
 * Return: pointer to the first occurrence or NULL if not found
 */
char *custom_strpbrk(char *str, char *charset)
{
int index_str, index_charset;

if (*str == '\0' && *charset == '\0')
return (NULL);

for (index_str = 0; str[index_str] != '\0'; index_str++)
{
for (index_charset = 0; charset[index_charset] != '\0'; index_charset++)
{
if (str[index_str] == charset[index_charset])
break;
}

if (charset[index_charset] != '\0')
break;
}

if (str[index_str] != '\0')
return (&str[index_str]);

return (NULL);
}


/**
 * custom_strcpy - copies the string pointed to by src to dest
 * @src_str: source string
 * @dest_str: destination buffer
 * Return: pointer to the destination string
 */
char *custom_strcpy(char *dest_str, char *src_str)
{
int i;

for (i = 0; src_str[i] != '\0'; i++)
dest_str[i] = src_str[i];

dest_str[i] = '\0';
return (dest_str);
}
