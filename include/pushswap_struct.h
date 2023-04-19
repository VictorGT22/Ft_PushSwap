#ifndef  PUSHSWAP_STRUCT_H
# define PUSHSWAP_STRUCT_H

#include <stdarg.h>

typedef struct linked_lst
{
	int num;
	int chunk;
	struct linked_lst	*next;
	struct linked_lst	*prev;
}	linked_lst;

typedef struct s_variables
{
	linked_lst	*lst_a;
	linked_lst	*lst_b;
	int			lst_a_len;
	int			lst_b_len;
}	s_variables;

#endif