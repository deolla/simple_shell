#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Shell interactive prototype*/
void interactive_mode(void);
void no_interactive_mode(void);

/* Interactive mode */
void interactive_mode(void);

/* Read line prototype */
char *read_command(void);

/* Tokenising Prototype */
char **parse_command(char *input);

#endif
