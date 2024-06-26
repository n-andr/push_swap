/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:49:27 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/18 15:57:32 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Functions:
sort_2_a
	sorts 2 values in stack a
sort_3_a
	sorts 3 values in stack a (hardcoded all possible combinations)
sort_5
	sorts 4 and 5 values using both stacks
sort_all
	sorts all possible number of values, but is not optimal for sorting 2-5 values
main
	parces given arguments ang calls sorting functions
*/

// to print stack

// void	print_stack(char *ch, t_stack *stack)
// {
// 	printf("stack %s:\n", ch);
// 	while (stack!= NULL) 
// 	{
// 		printf("value: %d   ", stack->value); 
// 		// printf("index: %d   ", stack->index);
// 		printf("smallest: %d   ", stack->smallest);
// 		printf("biggest: %d   ", stack->biggest);
// 		printf("marker: %d   ", stack->marker);
// 		printf("moves: %d   ", stack->moves);
// 		printf("moves in a: %d   ", stack->moves_in_a);
// 		printf("moves in b: %d   ", stack->moves_in_b);
// 		if (stack->prev != NULL)
// 			printf("- prev value: %d   ", stack->prev->value);
// 		else
// 			printf("- prev value: NULL   ");
// 		if (stack->next != NULL)
// 			printf("- next value: %d\n", stack->next->value);
// 		else
// 			printf("- next value: NULL\n");
// 		stack = stack->next;
// 	}
// }
// print_stack("a", a);
// 	print_stack("b", b);
//end to print stack

void	sort_2_a(t_stack **stack)
{
	int	a;
	int	b;

	a = (*stack)->value;
	b = (*stack)->next->value;
	if ((a > b))
		sa(stack);
}

void	sort_3_a(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if ((a > b) && (a > c) && (b > c))
	{
		sa(stack);
		rra(stack);
	}
	else if ((a > b) && (a < c) && (b < c))
		sa(stack);
	else if ((a > b) && (b < c) && (a > c))
		ra(stack);
	else if ((a < b) && (a > c) && (b > c))
		rra(stack);
	else if ((a < b) && (b > c) && (a < c))
	{
		ra(stack);
		sa(stack);
		rra(stack);
	}
}

void	sort_5(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	while (ft_lstsize(*a) > 3)
		pb (a, &b);
	sort_3_a(a);
	while (b)
	{
		mark_smallest_and_biggest(a);
		if ((b->value < (*a)->value && b->value > (ft_lstlast(*a))->value)
			|| ((b->value > (ft_lstlast(*a))->value) 
				&& (ft_lstlast(*a))->biggest == 1)
			|| ((b->value < (*a)->value) && (*a)->smallest == 1))
			pa (a, &b);
		else
		{
			zeroing_moves(b);
			count_moves(*a, b);
			move_least_moves(a, &b);
		}
	}
	mark_smallest_and_biggest(a);
	while ((*a)->smallest != 1)
		move_smalest_top(a);
}

void	sort_all(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	extract_sorted_list(a, &b);
	while (b)
	{
		mark_smallest_and_biggest(a);
		if (b->value < (*a)->value && b->value > (ft_lstlast(*a))->value)
			pa (a, &b);
		else if ((b->value > (ft_lstlast(*a))->value) 
			&& (ft_lstlast(*a))->biggest == 1)
			pa (a, &b);
		else if ((b->value < (*a)->value) && (*a)->smallest == 1)
			pa (a, &b);
		else
		{
			zeroing_moves(b);
			count_moves(*a, b);
			move_least_moves(a, &b);
		}
	}
	mark_smallest_and_biggest(a);
	while ((*a)->smallest != 1)
		move_smalest_top(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	argc_check(argc);
	a = fill_stack((argc), (argv));
	check_if_sorted(&a);
	if (ft_lstsize(a) == 2)
		sort_2_a(&a);
	else if (ft_lstsize(a) == 3)
		sort_3_a(&a);
	else if (ft_lstsize(a) == 5 || ft_lstsize(a) == 4)
		sort_5(&a);
	else if (ft_lstsize(a) > 5)
		sort_all(&a);
	free_stack(a);
	return (0);
}
