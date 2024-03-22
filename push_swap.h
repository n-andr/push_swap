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
//	int	index;
}	t_stack;

//to be deleted
void	print_stack(char *ch, t_stack *stack);

//errors
void	argc_check (int argc);
int		write_error(t_stack **stack);
int	check_for_dup(t_stack **a);

//free
void	free_stack(t_stack *stack);

//fill stack
void	find_smallest(t_stack **stack);
void	find_biggest(t_stack **stack);

//libft
void	*ft_memset(void *ptr, int value, size_t num);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n_items, size_t size);
int	ft_lstsize(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *stack);

//moves
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);


#endif