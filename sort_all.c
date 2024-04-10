#include "push_swap.h"

void	zeroing_moves(t_stack *b)
{
	while (b)
	{
		b->moves = 0;
		b = b->next;
	}
	

}
t_stack *find_cheapest(t_stack *stack)
{
	t_stack *b_tmp;

	b_tmp = stack;
	while (stack)
	{
		if (stack->moves < b_tmp->moves)
			b_tmp = stack;
		stack = stack->next;
	}
	return(b_tmp);
}

void	move_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*b_tmp;
	int	moves_in_a;
	int	moves_in_b;

	b_tmp = find_cheapest(*b);
	moves_in_a = b_tmp->moves_in_a;
	moves_in_b = b_tmp->moves_in_b;
	// printf("cheapest = %d\n", b_tmp->value);
	// print_stack("a (move cheapest)", *a);
	// print_stack("b (move cheapest)", *b);
	if (ft_lstsize(*a) / 2 >= moves_in_a && ft_lstsize(*b) / 2 >= moves_in_b)
	{
		while (moves_in_a > 0 && moves_in_b > 0)
		{
			rr(a,b);
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
		// print_stack("a (58 move cheapest)", *a);
		// print_stack("b (59 move cheapest)", *b);
	}
	else if (ft_lstsize(*a) / 2 < moves_in_a && ft_lstsize(*b) / 2 < moves_in_b)
	{
		moves_in_a = ft_lstsize(*a) - moves_in_a;
		moves_in_b = ft_lstsize(*b) - moves_in_b;
		while (moves_in_a > 0 && moves_in_b > 0)
		{
			rrr(a,b);
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
		// print_stack("a (81 move cheapest)", *a);
		// print_stack("b (82 move cheapest)", *b);
	}
	else
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
		// print_stack("a (120 move cheapest)", *a);
		// print_stack("b (121 move cheapest)", *b);
	}
}

void	count_moves(t_stack *a, t_stack *b)
{
	t_stack *a_tmp;
	t_stack *b_tmp;
	int	moves_in_b;
	int	moves_in_a;
	b_tmp = b;
	while (b_tmp && ft_lstlast(b_tmp)->moves == 0)
	{
		a_tmp = a;
		moves_in_a = 0; 
		moves_in_b = 0;
		b_tmp = b;
		while (b_tmp && b_tmp->moves != 0)
		{
			moves_in_b++;
			b_tmp = b_tmp->next;
		}
		while (a_tmp && b_tmp)
		{
			if (((a_tmp->previous == NULL) && (b_tmp->value < a_tmp->value) && (b_tmp->value > ft_lstlast(a_tmp)->value))
			|| ((a_tmp->previous != NULL) && (b_tmp->value > a_tmp->previous->value) && (b_tmp->value < a_tmp->value))
			|| ((a_tmp->smallest == 1) && (b_tmp->value < a_tmp->value))
			|| ((a_tmp->previous != NULL) && (a_tmp->previous->biggest == 1) && (b_tmp->value > a_tmp->previous->value))
			|| ((a_tmp->previous == NULL) && (ft_lstlast(a_tmp)->biggest == 1) && (b_tmp->value > ft_lstlast(a_tmp)->value)))
			{
				break;
			}
			a_tmp = a_tmp->next;
			moves_in_a++;
		}
		b_tmp->moves_in_a = moves_in_a;
		b_tmp->moves_in_b = moves_in_b;
		if (ft_lstsize(a) / 2 >= moves_in_a && ft_lstsize(b) / 2 >= moves_in_b)
		{
			if (moves_in_a >= moves_in_b)
				b_tmp->moves = moves_in_a;
			else
				b_tmp->moves = moves_in_b;
		}
		else if (ft_lstsize(a) / 2 < moves_in_a && ft_lstsize(b) / 2 < moves_in_b)
		{
			moves_in_a = ft_lstsize(a) - moves_in_a;
			moves_in_b = ft_lstsize(b) - moves_in_b;
			if (moves_in_a >= moves_in_b)
				b_tmp->moves = moves_in_a;
			else
				b_tmp->moves = moves_in_b;
		}
		else if (ft_lstsize(a) / 2 < moves_in_a && ft_lstsize(b) / 2 >= moves_in_b)
		{
			moves_in_a = ft_lstsize(a) - moves_in_a;
			b_tmp->moves = moves_in_a + moves_in_b;
		}
		else if (ft_lstsize(a) / 2 >= moves_in_a && ft_lstsize(b) / 2 < moves_in_b)
		{
			moves_in_b = ft_lstsize(b) - moves_in_b;
			b_tmp->moves = moves_in_a + moves_in_b;
		}
		else
			b_tmp->moves = moves_in_a + moves_in_b;
	}
// 	print_stack("56 a (count moves)", a);
// 	print_stack("57 b (count moves)", b);
}

void	sort_all(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	extract_sorted_list(a, &b);
	// print_stack("a", *a);
	// print_stack("b", b);
	while (b)
	{	
		find_smallest(a);
		find_biggest(a);
		// if (ft_lstsize(b) >= 2 && (b->value > b->next->value))
		// 	sb(&b);
		if (b->value < (*a)->value && b->value > (ft_lstlast(*a))->value) // what if there is only one element in a?
		{
			pa (a, &b);
			// print_stack("a/pa", *a);
			// print_stack("b/pa", b);
		}
		else if ((b->value > (ft_lstlast(*a))->value) && (ft_lstlast(*a))->biggest == 1)
		{
			pa (a, &b);
		}
		else if ((b->value < (*a)->value) && (*a)->smallest == 1)
		{
			pa (a, &b);
		}
		else
		{
			zeroing_moves(b);
			count_moves(*a, b);
			move_cheapest(a, &b);
			//ra_or_rra(a, &b);
		}
		// if(b)
		// 	zeroing_moves(b);
		// 	count_moves(*a, b);
		// print_stack("a (while (b))", *a);
		// print_stack("b (while (b))", b);
	}
	// print_stack("a", *a);
	// print_stack("b", b);
	find_smallest(a);
	find_biggest(a);
	while ((*a)->smallest != 1) // можно крутить в обратную сторону если самое маленькое внизу
	{
		move_smalest_top(a);
	}
}
