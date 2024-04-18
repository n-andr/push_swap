/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:47:25 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/18 12:47:27 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if ((*b)->next != NULL)
		(*b)->next->prev = tmp;
	(*b)->prev = NULL;
	tmp->prev = *b;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	write(1, "sb\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*last;
	t_stack	*first;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	last = *b;
	while (last->next)
		last = last->next;
	first = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rrb(t_stack **b)
{
	t_stack	*last;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	last = *b;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	(*b)->prev = last;
	last->next = (*b);
	last->prev = NULL;
	*b = last;
	write(1, "rrb\n", 4);
}
