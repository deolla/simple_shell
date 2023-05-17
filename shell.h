#ifndef _SHELL_H_
#define _SHELL_H_

#define END_OF_FILE     (-1)
#define ERROR_CHARACTER  (0)
#define SOURCE_INIT_POINT (-2)

struct new_source
{
	char *boff;
	long boffsize;
	long new_post;
};

#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

/** STRING PROTOTYPE **/
int strcmp(const char *str1, const char *str2);
size_t strlen(const char *str);
char *strcpy(char *dest, const char *src);

/** prompt **/
void print_shell_prompt(void);
void print_shell_prompt1(void);

/** functions **/
char *read_user_input(void);
void *realloc(void *pointer, size_t size);
void *memcpy(void *dest, const void *src, size_t n);

void get_last_char(struct new_source *source);
char my_next_char(struct new_source *source);
char pick_char(struct new_source *source);
void ignore_spaces(struct new_source *source);
#endif
