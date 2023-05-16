#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <unistd.h>

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
#endif
