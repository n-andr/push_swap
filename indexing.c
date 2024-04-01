#include "push_swap.h"

int	*create_array(t_stack *stack)
{
	int	*array;
	t_stack *tmp;
	int	i;

	tmp = stack;
	i = 0;
	array = NULL;
	array = ft_calloc(sizeof(int), ft_lstsize(stack));

	while (tmp)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	printf("array: \n");
	i = 0;
	while (i < ft_lstsize(stack))
	{
		printf("%d ", array[i]);
		i++;
	}
	
	
	free (array);
	return(0);
}