/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:41:52 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/18 13:03:43 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Error list:
- only one arg : return control back to user
- empty string : error
- over min/max int limit : error
- duplicates : error
- invalid char (letter or ,.-/etc) : error 
5/5 done */

void	argc_check(int argc)
{
	if (argc == 1)
		exit (EXIT_FAILURE);
}

int	write_error(t_stack **stack)
{
	write (1, "Error\n", 6);
	free_stack(*stack);
	exit (EXIT_FAILURE);
	return (0);
}

int	check_for_dup(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*curent;

	curent = *a;
	while (curent != NULL)
	{
		tmp = curent->next;
		while (tmp != NULL)
		{
			if (curent ->value == tmp ->value)
				write_error(a);
			tmp = tmp -> next;
		}
		curent = curent -> next;
	}
	return (0);
}
