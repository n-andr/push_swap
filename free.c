/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:43:15 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/18 13:04:54 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//free memory

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (stack == NULL || stack == NULL)
		return ;
	current = stack;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	stack = NULL;
}
