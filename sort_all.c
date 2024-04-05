#include "push_swap.h"

void	count_moves(t_stack *a, t_stack *b)
{
	int i;
	t_stack *a_tmp;
	t_stack *b_tmp;

	a_tmp = a;
	b_tmp = b;
	//if a biggest
	//if a smalest
	//if null pointer
	
	i = 1; // cuz we start from the second number
	while (a_tmp)
	{
		if ((b_tmp->index > a_tmp->previous->index) 
		&& (b_tmp->index < a_tmp->index))
		{
			break;
		}
		if ((b_tmp->index > a_tmp->index) 
		&& (a_tmp->next == NULL))
		{
			break;
		}
		a_tmp = a_tmp->next;
		i++;
	}
	// printf("i = %d\n", i);
	// print_stack("a (ra or rra)", *a);
	// print_stack("b (ra or rra)", *b);
	// if (ft_lstsize(a) / 2 >= i)
	// {
	// 	//ra(a);
	// }
	// else
	// 	//rra(a);
}

void	sort_all(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	extract_sorted_list(a, &b);
	// print_stack("a", *a);
	// print_stack("b", b);
	// if (ft_lstsize(*a) < 3)
	// {
	// 	while ((ft_lstsize(*a) < 3))
	// 		pa (a, &b);
	// 	sort_3_a(a);
	// }
	// print_stack("a", *a);
	// print_stack("b", b);
	while (b)
	{	
		find_smallest(a);
		find_biggest(a);
		//count_moves(*a, b);
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
			//ra (a);
		}
		// else if (b->biggest == 1)
		// {
		// 	pa (a, &b);
		// 	ra (a);
		// }
		else if ((b->value < (*a)->value) && (*a)->smallest == 1)
		{
			pa (a, &b);
		}
		else
			ra_or_rra(a, &b);
			// ra (a);
		// print_stack("a (while (b))", *a);
		// print_stack("b (while (b))", b);
	}
	// print_stack("a", *a);
	// print_stack("b", b);
	find_smallest(a);
	find_biggest(a);
	while ((*a)->smallest != 1) // можно крутить в обратную сторону если самое маленькое внизу
		move_smalest_top(a);
}