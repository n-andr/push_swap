#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

# include <stdio.h> // remove

typedef struct s_stack
{
	int	value; 
	struct s_stack	*next;
	struct s_stack	*previous;
	int	biggest;
	int	smallest;
}	t_stack;


//errors
void	argc_check (int argc);
int		write_error(t_stack **stack);
int	check_for_dup(t_stack **a);

//free
void	free_stack(t_stack *stack);

//libft
void	*ft_memset(void *ptr, int value, size_t num);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n_items, size_t size);
int	ft_lstsize(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);




#endif