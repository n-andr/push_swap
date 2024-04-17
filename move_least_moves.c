#include "push_swap.h"

/*
Functions:
do_rr :
	to do ra & rb sumultaniasly, and to continue doing ra OR rb, 
	when one of the stack is placed correctly, and other is not yet done.
do_rrr :
	to do rra & rrb sumultaniasly, and to continue doing rra OR rrb, 
	when one of the stack is placed correctly, and other is not yet done.
rotate_a :
	to calculate in which direction stack a needs to be rotated and 
	to perform ra or rra
rotate_b :
	to calculate in which direction stack b needs to be rotated and 
	to perform rb or rrb
move_least_moves :
	to decide how rotations should be performed
	- both stacks same direction rr or rrr
	- both stacks different derections
	- only one stack
*/

void	do_rr(t_stack **a, t_stack **b, int moves_in_a, int moves_in_b)
{
	while (moves_in_a > 0 && moves_in_b > 0)
	{
		rr(a, b);
		moves_in_a --;
		moves_in_b --;
	}
	while (moves_in_a > 0)
	{
		ra(a);
		moves_in_a --;
	}
	while (moves_in_b > 0)
	{
		rb(b);
		moves_in_b --;
	}
}

void	do_rrr(t_stack **a, t_stack **b, int moves_in_a, int moves_in_b)
{
	moves_in_a = ft_lstsize(*a) - moves_in_a;
	moves_in_b = ft_lstsize(*b) - moves_in_b;
	while (moves_in_a > 0 && moves_in_b > 0)
	{
		rrr(a, b);
		moves_in_a --;
		moves_in_b --;
	}
	while (moves_in_a > 0)
	{
		rra(a);
		moves_in_a --;
	}
	while (moves_in_b > 0)
	{
		rrb(b);
		moves_in_b --;
	}
}

void	rotate_a(t_stack **a, int moves_in_a)
{
	if (moves_in_a > 0 && ft_lstsize(*a) / 2 < moves_in_a)
	{
		moves_in_a = ft_lstsize(*a) - moves_in_a;
		while (moves_in_a > 0)
		{
			rra(a);
			moves_in_a --;
		}
	}
	else
	{
		while (moves_in_a > 0)
		{
			ra(a);
			moves_in_a --;
		}
	}
}

void	rotate_b(t_stack **b, int moves_in_b)
{
	if (moves_in_b > 0 && ft_lstsize(*b) / 2 < moves_in_b)
	{
		moves_in_b = ft_lstsize(*b) - moves_in_b;
		while (moves_in_b > 0)
		{
			rrb(b);
			moves_in_b --;
		}
	}
	else
	{
		while (moves_in_b > 0)
		{
			rb(b);
			moves_in_b --;
		}
	}
}

void	move_least_moves(t_stack **a, t_stack **b)
{
	t_stack	*b_tmp;
	int		moves_in_a;
	int		moves_in_b;

	b_tmp = find_least_moves(*b);
	moves_in_a = b_tmp->moves_in_a;
	moves_in_b = b_tmp->moves_in_b;
	if (ft_lstsize(*a) / 2 >= moves_in_a && ft_lstsize(*b) / 2 >= moves_in_b)
		do_rr(a, b, moves_in_a, moves_in_b);
	else if (ft_lstsize(*a) / 2 < moves_in_a && ft_lstsize(*b) / 2 < moves_in_b)
		do_rrr(a, b, moves_in_a, moves_in_b);
	else
	{
		if (moves_in_a > 0)
			rotate_a(a, moves_in_a);
		if (moves_in_b > 0)
			rotate_b(b, moves_in_b);
	}
}
