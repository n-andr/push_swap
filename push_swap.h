#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
// # include "libft/libft.h"

# include <stdio.h> // remove

// *value type change to int 

typedef struct s_stack
{
	char	*value; 
	struct s_stack	*next;
}	t_stack;


void	argc_check (int argc);

#endif