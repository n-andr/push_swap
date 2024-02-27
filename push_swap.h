#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	value;
	struct s_stack	*next;
}	t_stack;


void	argc_check (int argc);

#endif