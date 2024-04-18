/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sorted_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:42:52 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/18 12:43:11 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
These functions work together to identify, mark, and extract 
the longest sorted sequence (in ascending order) within the stack a, 
moving everything else to stack b.

calc_list_len :
	Calculates the length of the sorted sublist starting from a given node.
	It iterates through the sublist and counts the number of elements in 
	the increasing sequence.
find_sorted_list:
	This function takes a stack a, its starting node a_start, 
	and an iterator a_iterator as input.
	It iterates through the stack to find the longest increasing sequence.
	It returns the value of the node where the longest sequence starts.
mark_sorted_list:
	This function marks the nodes in the stack a that belong 
	to the longest increasing sequence.
	It returns the value of the first node in the marked sequence.
extract_sorted_list:
	This function extracts the longest increasing sequence from stack a to b.
	It uses the previous two functions to find and mark the longest sequence.
	Then, it moves the unmarked nodes to b, leaving the sorted sequence in a.
*/

int	calc_list_len(t_stack *a, t_stack *a_start)
{
	t_stack	*a_iterator;
	int		compare_value;
	int		list_len;

	list_len = 1;
	compare_value = a->value;
	a_iterator = a->next;
	while (a_iterator != NULL && a_iterator->value != a->value)
	{
		if (compare_value < a_iterator->value)
		{
			list_len ++;
			compare_value = a_iterator->value;
		}
		a_iterator = a_iterator->next;
		if (a_iterator == NULL)
			a_iterator = a_start;
	}
	return (list_len);
}

int	find_sorted_list(t_stack *a, t_stack *a_start)
{
	int	best_start_value;
	int	list_len;
	int	max_list_len;

	max_list_len = 1;
	best_start_value = a->value;
	while (a != NULL)
	{
		list_len = 1;
		list_len = calc_list_len(a, a_start);
		if (list_len > max_list_len)
		{
			max_list_len = list_len;
			best_start_value = a->value;
		}
		a = a->next;
	}
	return (best_start_value);
}

int	mark_sorted_list(t_stack *a, int start_value)
{
	t_stack	*a_start;
	int		compare_value;

	a_start = a;
	while (a->value != start_value)
		a = a->next;
	a->marker = 1;
	compare_value = start_value;
	a = a->next;
	while (a->value != start_value)
	{
		if (compare_value < a->value)
		{
			a->marker = 1;
			compare_value = a->value;
		}
		a = a->next;
		if (a == NULL)
			a = a_start;
	}
	while (a_start->marker != 1)
		a_start = a_start->next;
	return (a_start->value);
}

void	extract_sorted_list(t_stack **a, t_stack **b)
{
	int	start_value;

	start_value = find_sorted_list(*a, *a);
	start_value = mark_sorted_list(*a, start_value);
	while ((*a)->value != start_value && a != NULL)
		pb(a, b);
	ra(a);
	while ((*a)->value != start_value && a != NULL)
	{
		if ((*a)->marker == 1)
			ra(a);
		else
			pb(a, b);
	}
}
