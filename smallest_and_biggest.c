/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_and_biggest.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:53:17 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/18 12:53:20 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Functions:
find_smallest :
	finds and marks the smallest value in the given stak

find_biggest :
	finds and marks the biggest value in the given stack
*/
void	mark_smallest_and_biggest(t_stack **stack)
{
	find_smallest(stack);
	find_biggest(stack);
}

void	find_smallest(t_stack **stack)
{
	t_stack	*current;
	t_stack	*smallest;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	smallest = *stack;
	while (current)
	{
		current->smallest = 0;
		current = current->next;
	}
	current = *stack;
	while (current != NULL)
	{
		if (current->value < smallest->value)
			smallest = current;
		current = current->next;
	}
	smallest->smallest = 1;
}

void	find_biggest(t_stack **stack)
{
	t_stack	*current;
	t_stack	*biggest;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	biggest = *stack;
	while (current)
	{
		current->biggest = 0;
		current = current->next;
	}
	current = *stack;
	while (current != NULL)
	{
		if (current->value > biggest->value)
			biggest = current;
		current = current->next;
	}
	biggest->biggest = 1;
}
