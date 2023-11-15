#ifndef HEAD_H
#define HEAD_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>

/*Global Variables  */
extern char **environ;
extern int EXIT_STATUS;

/**
 * struct AliasStruct - struct Aliases
 * @name: alias name
 * @value: alias value
 */
typedef struct AliasStruct
{
char *name;
char *value;
} AliasStruct;

void *custom_calloc(unsigned int num_elements, unsigned int element_size);
void custom_free(char **ptr);

char *custom_strcpy(char *destination, char *source);
char *custom_strcat(char *destination, char *source);
void remove_first_char(char **string_ptr);
size_t my_strlen(char *str);
int custom_getalias(AliasStruct *alias, char *var, int idx);
void remove_first_char(char **string_ptr);
int custom_and_handling(char *input_line,
char *file_name, AliasStruct *alias_array, int *index);
void check_alias_custom(char ***arguments, AliasStruct *alias_list, int index);
void replace_custom_substring(char *input_str, char *old_sub, char *new_sub);
int custom_strcmp(const char *str1, char *str2);
int my_strncmp(const char *str1, char *str2, int num_chars);
char *find_substring(char *str, char *sub);
void check_alias_custom(char ***arguments, AliasStruct *alias_list, int index);
char *my_memcpy(char *destination, char *source, unsigned int num_bytes);
void replace_custom_substring(char *input_str, char *old_sub, char *new_sub);
char **custom_strtok(char *input_string, char *delimiters);
char *custom_getenv(char *variable);
int custom_fork(char *cmd_name, char **cmd_args);
int execute_command(char **args, char *program_name, char *program_path);
int check_fork_error(char *program_name, char **args, char *program_path);
int read_line(char **user_input);
int read_file(char **user_input, char **file_args);
int custom_to_string(int output_fd, unsigned int number);
int custom_print_string(int output_fd, char *str);
void display_error(char **arguments, char *file_path, int error_code);
int report_error(char *cmd_name, char **cmd_args,
char *program_name, int error_code);
int split_command(char *, char *,AliasStruct *, int *);
void get_cmds(char ***, char *);
int count_arguments(char **);
char *is_valid_command(char *command, char *program_name, char **environment);
char *check_ops(char **);
int custom_export(int arg_count, char **arguments, char *program_name,
AliasStruct *custom_alias,
int *index_ptr, char **custom_split, char *custom_line);
int custom_unsetenv(int, char **, char *,
AliasStruct *, int *, char **, char *);
int my_echo(char **arguments);
int custom_change_dir(int arg_count, char **arg_list, char *prog_name,
AliasStruct *alias_struct, int *index_ptr,
char **split_line, char *input_line);
int my_exit_function(int num_args, char **arguments, char *program_name,
AliasStruct *my_alias, int *index_value, char **split_line,
char *input_line);
int my_env_function(int count, char **arguments, char *program_name,
AliasStruct *my_aliases, int *index_ptr, char **my_split, char *input_line);
int handle_aliases(int count, char **arguments, char *program_name,
AliasStruct *alias_list, int *alias_count,
char **split_line, char *input_line);

/**
 * struct cmd_executer - structure
 * @command: command
 * @execute_func: function
 */
typedef struct cmd_executer
{
char *command;
int (*execute_func)(int, char **, char *, AliasStruct *,
int *, char **, char *);
} cmd_executer;
int select_command(const char *command, char **arguments,
char *program_name, AliasStruct *alias_data,
int *index, char **split_line, char *input_line);
int convert_string_to_integer(char *str);

#endif
