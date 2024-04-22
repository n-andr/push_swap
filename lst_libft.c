/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:08:46 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/18 13:49:51 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Functions :
ft_lstsize
ft_lstadd_front
ft_lstnew
ft_lstnew
ft_lstlast
*/

int	ft_lstsize(t_stack *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	if (*lst != NULL)
		(*lst)->prev = new; 
	*lst = new;
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (new == 0)
		return (NULL);
	new->value = content;
	new->biggest = 0;
	new->smallest = 0;
	new->marker = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_stack	*ft_lstlast(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
