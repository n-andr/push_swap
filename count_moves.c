/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:41:44 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/18 13:04:28 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Functions:
find_least_moves :
	to find the value, that requaers least amount of moves to place in stack a
	part of the move_least_moves function in this file only for normonette :(
zeroing_moves :
	to set all markers (moves, moves_in_a, moves_in_b) to 0;
count_a :
	to count how many rotations (from top - ra) 
	needs to be done in stack a to fit the number from stack b
moves_total:
	to count minimum number of moves to bring a value from b to a
	that includes simultanious rotations (rr & rrr), and/or reverse rotations
count_moves:
	to iterate through stack b, assign markers of moves in a and b to each value,
	count total moves for each value
*/

t_stack	*find_least_moves(t_stack *stack)
{
	t_stack	*b_tmp;

	b_tmp = stack;
	while (stack)
	{
		if (stack->moves < b_tmp->moves)
			b_tmp = stack;
		stack = stack->next;
	}
	return (b_tmp);
}

void	zeroing_moves(t_stack *b)
{
	while (b)
	{
		b->moves = 0;
		b->moves_in_a = 0;
		b->moves_in_b = 0;
		b = b->next;
	}
}

int	count_a(t_stack *a_tmp, t_stack *current, int moves_in_a)
{
	while (a_tmp && current)
	{
		if (((a_tmp->prev == NULL) && (current->value < a_tmp->value)
				&& (current->value > ft_lstlast(a_tmp)->value))
			|| ((a_tmp->prev != NULL)
				&& (current->value > a_tmp->prev->value)
				&& (current->value < a_tmp->value))
			|| ((a_tmp->smallest == 1) && (current->value < a_tmp->value))
			|| ((a_tmp->prev != NULL) && (a_tmp->prev->biggest == 1)
				&& (current->value > a_tmp->prev->value))
			|| ((a_tmp->prev == NULL) && (ft_lstlast(a_tmp)->biggest == 1)
				&& (current->value > ft_lstlast(a_tmp)->value)))
		{
			return (moves_in_a);
		}
		a_tmp = a_tmp->next;
		moves_in_a++;
	}
	return (moves_in_a);
}

void	moves_total(t_stack *a, t_stack *b, t_stack *current)
{
	int	moves_a;
	int	moves_b;

	moves_a = current->moves_in_a;
	moves_b = current->moves_in_b;
	if (ft_lstsize(a) / 2 >= moves_a && ft_lstsize(b) / 2 >= moves_b)
	{
		if (moves_a >= moves_b)
			current->moves = moves_a;
		else
			current->moves = moves_b;
	}
	else if (ft_lstsize(a) / 2 < moves_a && ft_lstsize(b) / 2 < moves_b)
	{
		if ((ft_lstsize(a) - moves_a) >= (ft_lstsize(b) - moves_b))
			current->moves = ft_lstsize(a) - moves_a;
		else
			current->moves = ft_lstsize(b) - moves_b;
	}
	else if (ft_lstsize(a) / 2 < moves_a && ft_lstsize(b) / 2 >= moves_b)
		current->moves = (ft_lstsize(a) - moves_a) + moves_b;
	else if (ft_lstsize(a) / 2 >= moves_a && ft_lstsize(b) / 2 < moves_b)
		current->moves = moves_a + (ft_lstsize(b) - moves_b);
	else
		current->moves = moves_a + moves_b;
}

void	count_moves(t_stack *a, t_stack *b)
{
	t_stack	*a_tmp;
	t_stack	*current;
	int		moves_in_b;
	int		moves_in_a;

	current = b;
	while (current && ft_lstlast(current)->moves == 0)
	{
		a_tmp = a;
		moves_in_a = 0;
		moves_in_b = 0;
		current = b;
		while (current && current->moves != 0)
		{
			moves_in_b++;
			current = current->next;
		}
		moves_in_a = count_a(a_tmp, current, moves_in_a);
		current->moves_in_a = moves_in_a;
		current->moves_in_b = moves_in_b;
		moves_total(a, b, current);
	}
}
