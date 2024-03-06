#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
// # include "libft/libft.h"

# include <stdio.h> // remove

// *value type change to int 

typedef struct s_stack
{
	int	value; 
	struct s_stack	*next;
}	t_stack;


void	argc_check (int argc);
void	free_stack(t_stack **stack);


#endif