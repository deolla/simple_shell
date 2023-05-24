#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* shell interactive prototype*/
void interactive_mode(void);
void no_interactive_mode(void);

/*read line prototype*/
char *read_command(void);

#endif
