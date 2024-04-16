#include "push_swap.h"

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
			if (((a_tmp->previous == NULL) && (b_tmp->value < a_tmp->value) 
			&& (b_tmp->value > ft_lstlast(a_tmp)->value))
			|| ((a_tmp->previous != NULL) 
			&& (b_tmp->value > a_tmp->previous->value) 
			&& (b_tmp->value < a_tmp->value))
			|| ((a_tmp->smallest == 1) && (b_tmp->value < a_tmp->value))
			|| ((a_tmp->previous != NULL) && (a_tmp->previous->biggest == 1) 
			&& (b_tmp->value > a_tmp->previous->value))
			|| ((a_tmp->previous == NULL) && (ft_lstlast(a_tmp)->biggest == 1) 
			&& (b_tmp->value > ft_lstlast(a_tmp)->value)))
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
}
