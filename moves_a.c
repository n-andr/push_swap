/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:47:05 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/18 12:47:06 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if ((*a)->next != NULL)
		(*a)->next->prev = tmp;
	(*a)->prev = NULL;
	tmp->prev = *a;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write(1, "sa\n", 3);
}

void	ra(t_stack **a)
{
	t_stack	*last;
	t_stack	*first;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	first = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_stack **a)
{
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	(*a)->prev = last;
	last->next = (*a);
	last->prev = NULL;
	*a = last;
	write(1, "rra\n", 4);
}

void	move_smalest_top(t_stack **a)
{
	int		i;
	t_stack	*smallest;

	i = ft_lstsize(*a);
	smallest = *a;
	while (smallest->smallest != 1 && smallest != NULL)
	{
		smallest = smallest->next;
	}
	if (ft_lstsize(smallest) >= i / 2)
		ra(a);
	else
		rra(a);
}
