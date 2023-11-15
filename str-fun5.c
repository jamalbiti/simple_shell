#include "head.h"

/**
 * check_character - checks whether character is within delimiters
 * @ch: character
 * @delimiters: delimiters string
 * Return: boolean
 */
int check_character(char ch, char *delimiters)
{
if (*delimiters == '\0')
return (ch == *delimiters);
return (ch == *delimiters ? 1 : check_character(ch, delimiters + 1));
}

/**
 * custom_strtok - custom string tokenizer
 * @input_string: string to be tokenized
 * @delimiters: string containing delimiters
 * Return: array of tokens
 */
char **custom_strtok(char *input_string, char *delimiters)
{
char **tokens_array;
size_t current_token_index = 0, i,
input_string_length = my_strlen(input_string) + 1;
int delimiter_found = 1, char_index = 0;

tokens_array = (char **)custom_calloc(input_string_length *
sizeof(char *), sizeof(char));
*tokens_array = (char *)custom_calloc(input_string_length, sizeof(char));
if (!*tokens_array)
free(tokens_array);
for (i = 0; input_string[i]; i++)
{
if (check_character(input_string[i], delimiters))
{
if (!delimiter_found)
{
tokens_array[current_token_index++][char_index] = '\0';
tokens_array[current_token_index] = (char *)
custom_calloc(input_string_length, sizeof(char));
if (!tokens_array[current_token_index])
custom_free(tokens_array);
}
delimiter_found = 1;
char_index = 0;
}
else
{
tokens_array[current_token_index][char_index++] = input_string[i];
delimiter_found = 0;
}
}
if (delimiter_found)
{
free(tokens_array[current_token_index]);
tokens_array[current_token_index] = NULL;
}
else
tokens_array[current_token_index][char_index] = '\0';
return (tokens_array);
}
