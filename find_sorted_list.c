#include "push_swap.h"


//to find the longest sorted sequence (in ascending order) within a given stack

int	find_sorted_list(t_stack *a)
{
	int	best_start_value; // можно заменить на поинтер на значение
	int	current_value;
	int	current_start_value;
	int list_len;
	int max_list_len;
	t_stack *tmp;
	t_stack *a_start;

	max_list_len = 1;
	list_len = 1;
	a_start = a;
	best_start_value = a->value;
	
	while (a != NULL)
	{
		tmp = a;
		current_start_value = tmp->value;
		current_value = tmp->value;
		tmp = tmp->next;
		while (tmp != NULL && tmp->value != current_start_value)
		{
			if (current_value < tmp->value)
			{
				list_len ++;
				current_value = tmp->value;
			}
			tmp = tmp->next;
			if (tmp == NULL)
			{
				tmp = a_start;
			}
		}
		// printf("list_len: %d\n", list_len);
		// printf("max_list_len: %d\n", max_list_len);
		if (list_len > max_list_len)
		{
			max_list_len = list_len;
			best_start_value = current_start_value;
			// printf("start value: %d\n", start_value);

		}
		list_len = 1;
		//print_stack("a", a);

		a = a->next;
	}
	// printf("best start v: %d\n", best_start_value);
	// printf("max_list_len: %d\n", max_list_len);
	// printf("start value: %d\n", start_value);
	//print_stack("a", a);
	return (best_start_value);
}

int	mark_sorted_list(t_stack *a, int start_value)
{
	t_stack	*a_start;
	int	curent_value;

	a_start = a;
	while (a->value != start_value)
	{
		a = a->next;
	}
	a->marker = 1;
	curent_value = start_value;
	a = a->next;
	while (a->value != start_value)
	{
		if (curent_value < a->value)
		{
			a->marker = 1;
			curent_value = a->value;
		}
		a = a->next;
		if (a == NULL)
		{
			a = a_start;
		}
	}
	while (a_start->marker != 1) 
	{
		a_start = a_start->next;
	}
	return (a_start->value);
}

void	extract_sorted_list(t_stack **a, t_stack **b)
{
	int start_value;
	//t_stack	*stack_start;

	start_value = find_sorted_list(*a);
	start_value = mark_sorted_list(*a, start_value);
	// print_stack("a", *a);
	// print_stack("b", *b);
	//stack_start = *a;
	while ((*a)->value != start_value && a != NULL)
		pb(a, b);
	// print_stack("a", *a);
	// print_stack("b", *b);

	ra(a);

	while ((*a)->value != start_value)
	{
		if ((*a)->marker == 1)
			ra(a);
		else
			pb(a,b);
		// print_stack("a", *a);
		// print_stack("b", *b);
	}
}
