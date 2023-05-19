#ifndef PARSE_H
#define PARSE_H

#include "shell.h"

struct node *parsing_simple_command(struct toks *token);

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
}

struct parsenode *parsing_simple_command(struct parsetoken *tok);
struct node *new_node(enum node_type type);
void child_node(struct node *parent, struct node  *child);
void free_node(struct node *snode);
void set_node(struct node *snode, char *s);

#endif
