#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
extern char **environ;

/* ~ Define Macro ~ */
#define POP_DEL " \t\r\n\a"

/* ~ Shell interactive prototype ~ */
void interactive_mode(void);
void no_interactive_mode(void);

/* ~ Interactive mode ~ */
char *read_command(void);
char **parse_command(char *input);
int execute_command(char **argv);

/* ~ String ~ */
size_t _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);

/* ~ new_prcess ~ */
int updated_process(char **argv);

/* ~ no_interactive protoype ~ */ 
void no_interactive_mode(void);
char *interpret_stream(void);
int my_env(void);
int my_help(char **argc);
int my_cd(argc);
int my_exit(char **argv)

#endif
