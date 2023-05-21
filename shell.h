#ifndef _SHELL_H_
#define _SHELL_H_

#define END_OF_FILE     (-1)
#define ERROR_CHARACTER  (0)
#define SOURCE_INIT_POINT (-2)

#define MAX_ARGS 256
extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/**
 * struct new_source - source.
 *
 * @boff: buffer.
 * @boffsize: buffer size.
 * @new_post: new nude.
 */
struct new_source
{
	char *boff;
	long boffsize;
	long new_post;
};


/**
 * struct toks - represent end of file.
 *
 * @source: source.
 * @input_len: lenght of input.
 * @input: user input.
 */
struct toks
{
	struct new_source *source;
	int input_len;
	char *input;
};

extern struct toks eof_tok;

/**
 * enum node_type - Represent the type of nodes.
 * @NODE_COMMAND: Node representing a command.
 * @NODE_S: Node representing s.
 */
enum node_type
{
	NODE_COMMAND,
	NODE_S};
/**
 * enum s_type - represent the types of valuse in sy,val_u union.
 * @S_SINT: Signed interger type.
 * @S_UINT: Unsigned interger type.
 * @S_SLLONG: Signed long long interget type.
 * @S_ULLONG: Unsigned long long interger type.
 * @S_FLOAT: Floating point type.
 * @S_LDOUBLE: Long double floating-point type.
 * @S_CHR: Character type.
 * @S_STR: String type.
 */
enum s_type
{
	S_SINT = 1,   /* signed int */
	S_UINT,       /*  unsigned int */
	S_SLLONG,     /* signed long int */
	S_ULLONG,     /* unsigned long int */
	S_FLOAT,      /* floating point */
	S_LDOUBLE,    /*long double */
	S_CHR,        /* char */
	S_STR};

/**
 * union symval_u - Representa a union of various data types.
 * @sint: Signed long integer type.
 * @uint: Unsigned long integer type.
 * @sllong: Signed long long integer type.
 * @ullong: Unsigned long long integer type.
 * @sfloat: Double precision floating point type.
 * @ldouble: Long double precision floating point type.
 * @chr: Character type.
 * @str: Pointer to a character(string) type.
 */
union symval_u
{
	long                sint;
	unsigned long       uint;
	long int            sllong;
	unsigned long int   ullong;
	double              sfloat;

	long double         ldouble;
	char                chr;
	char                *str;
};

/**
 * struct node - node in a data structure.
 * @type: Type of node.
 * @s_type: Type of value store in the union.
 * @s: Union that hold the value of diff. types.
 * @children: Number of child nodees.
 * @first_child: Pointer to the first child.
 * @next_sib: Pointer to the next sibling node.
 * @prev_sib: Pointer to the previous sibling node.
 */
struct node
{
	enum     node_type type;
	enum     s_type s_type;
	union    symval_u s;
	int      children;
	struct node *first_child;
	struct node *next_sib, *prev_sib;
};

struct node *new_node(enum node_type type);
void child_node(struct node *parent, struct node  *child);
void free_node(struct node *snode);
void set_node(struct node *snode, char *s);
struct node *parsing_simple_command(struct toks *token);

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

/** Scaning input **/
void get_last_char(struct new_source *source);
char my_next_char(struct new_source *source);
char pick_char(struct new_source *source);
void ignore_spaces(struct new_source *source);

/** Tokenizing Input **/
struct toks *tokinise(struct new_source *source);
void free_all_toks(struct toks *token);
void process_chars(struct new_source *source, char f);
void adjust_buffer_size(void);
void set_token_source(struct toks *token, struct new_source *source);
void include_buff(char k);
struct toks *generate_token(char *st);

/* Executing functions */
char *find_path(char *doc);
int implement_command(int argc, char **argv);
int simple_command(struct node *snode);
char *extract_path_segement(char **path_ptr);
char *find_file_in_path(const char *doc, const char *path);
static inline void free_argv(int argc, char **argv);
int execute_simple_command(int argc, char **argv);
int allocate_argument(struct node *child, int argc, char **argv);
#endif
