#include "push_swap.h"
// to be deleted

void	print_stack(char *ch, t_stack *stack)
{
	printf("stack %s:\n", ch);
	while (stack!= NULL) 
	{
		printf("value: %d   ", stack->value); 
		printf("smallest: %d   ", stack->smallest);
		printf("biggest: %d   ", stack->biggest);
		if (stack->previous != NULL)
			printf("- previous value: %d   ", stack->previous->value);
		else
			printf("- previous value: NULL   ");
		if (stack->next != NULL)
			printf("- next value: %d\n", stack->next->value);
		else
			printf("- next value: NULL\n");
		stack = stack->next;
	}
}
//end to be deleted

//free memory
//

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (stack == NULL || stack == NULL)
		return;
	current = stack;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	stack = NULL;
}

//
// end free memory

//sort
//
int	find_sorted_list(t_stack *a)
{
	int	start_value; // можно заменить на поинтер на значение
	int	current_value;
	int	current_start_value;
	int list_len;
	int max_list_len;
	t_stack *tmp;

	max_list_len = 1;
	list_len = 1;
	start_value = a->value;
	
	while (a != NULL)
	{
		tmp = a;
		current_start_value = tmp->value;
		current_value = tmp->value;
		
		while (tmp != NULL)
		{
			if (current_value < tmp->value)
			{
				list_len ++;
				current_value = tmp->value;
			}
			tmp = tmp->next;
		}
		// printf("list_len: %d\n", list_len);
		// printf("max_list_len: %d\n", max_list_len);
		if (list_len > max_list_len)
		{
			max_list_len = list_len;
			start_value = current_start_value;
			// printf("start value: %d\n", start_value);

		}
		list_len = 1;
		//print_stack("a", a);

		a = a->next;
	}
	// printf("start value: %d\n", start_value);
	//print_stack("a", a);
	return (start_value);
}

void	extract_sorted_list(t_stack **a, t_stack **b)
{
	int start_value;
	t_stack	*start_stack;

	start_value = find_sorted_list(*a);

	while ((*a)->value != start_value && a != NULL)
		pb(a, b);
	start_stack = *a;
	ra(a);
	
	while (a != NULL && (*a)->value != start_stack->value)
	{
		if (start_value < (*a)->value)
		{
			start_value = (*a)->value;
			// printf ("start value: %d\n", start_value);
			// printf ("(*a)->value: %d\n", (*a)->value);
			ra(a);
		}
		else
			pb(a,b);
		// print_stack("a", *a);
		// print_stack("b", *b);
	}
	*a = start_stack;
}

void sort_2_a(t_stack **stack)
{
	int	a;
	int	b;

	a = (*stack)->value;
	b = (*stack)->next->value;
	// ONLY IN STACK A!!!! 
	// ALL COMANDS FOR STACK A! 
	if ((a > b))
		sa(stack);
}

void sort_3_a(t_stack **stack)
{
	int	a;
	int	b;
	int	c;
// ONLY IN STACK A!!!! 
// ALL COMANDS FOR STACK A! 
	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if ((a > b) && (a > c) && (b > c))
	{
		sa(stack);
		rra(stack);
	}
	else if ((a > b) && (a < c) && (b < c))
	{
		sa(stack);
	}
	else if ((a > b) && (b < c) && (a > c))
	{
		ra(stack);
	}
	else if ((a < b) && (a > c) && (b > c))
	{
		rra(stack);
	}
	// if ((a < b) && (b < c) && (a < c))
	// {
		//do nothing
	// }
	else if ((a < b) && (b > c) &&(a < c))
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
	print_stack("a", *a);
	print_stack("b", b);
	if (ft_lstsize(b) == 2 && (b->value > b->next->value))
		{
			print_stack("b", b);
			sb(&b);
			print_stack("b", b);
		}

	print_stack("a", *a);
	print_stack("b", b);
	while (b)
	{
		find_smallest(a);
		find_biggest(a);
		if (b->value < (*a)->value && b->value > (ft_lstlast(*a))->value) // what if there is only one element in a?
		{
			pa (a, &b);
		}
		else if ((b->value > (ft_lstlast(*a))->value) && (ft_lstlast(*a))->biggest == 1)
		{
			pa (a, &b);
		}
		else if ((b->value < (*a)->value) && (*a)->smallest == 1)
		{
			pa (a, &b);
		}
		else
			ra (a);
	}
	find_smallest(a);
	find_biggest(a);
	while ((*a)->smallest != 1) // можно крутить в обратную сторону если самое маленькое внизу
		ra(a);
}

void	sort_all(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	extract_sorted_list(a, &b);
	// print_stack("a", *a);
	// print_stack("b", b);
	if (ft_lstsize(*a) < 3)
	{
		while ((ft_lstsize(*a) < 3))
			pa (a, &b);
		sort_3_a(a);
	}
	// print_stack("a", *a);
	// print_stack("b", b);
	while (b)
	{
		find_smallest(a);
		find_biggest(a);
		if (b->value < (*a)->value && b->value > (ft_lstlast(*a))->value) // what if there is only one element in a?
		{
			pa (a, &b);
			// print_stack("a/pa", *a);
			// print_stack("b/pa", b);
		}
		else if ((b->value > (ft_lstlast(*a))->value) && (ft_lstlast(*a))->biggest == 1)
		{
			pa (a, &b);
			//ra (a);
		}
		// else if (b->biggest == 1)
		// {
		// 	pa (a, &b);
		// 	ra (a);
		// }
		else if ((b->value < (*a)->value) && (*a)->smallest == 1)
		{
			pa (a, &b);
		}
		else
			ra (a);
		// print_stack("a (while (b))", *a);
		// print_stack("b (while (b))", b);
	}
	// print_stack("a", *a);
	// print_stack("b", b);
	find_smallest(a);
	find_biggest(a);
	while ((*a)->smallest != 1) // можно крутить в обратную сторону если самое маленькое внизу
		ra(a);
}


//
//end sort

int	char_to_numbers(t_stack **a, char *str)
{
	long int	result;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9'))
		{
			result = result * 10 + (str[i] - '0');
			if (result > INT_MAX || result < INT_MIN)
				write_error(a);
			i++;
		}
		else
			write_error(a);
	}
	return (result * sign);
}
void	find_smallest(t_stack **stack)
{
	t_stack *current;
	t_stack *smallest;

	if (stack == NULL || *stack == NULL)
        return;
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
	t_stack *current;
	t_stack *biggest;

	if (stack == NULL || *stack == NULL)
        return;
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
// void	assign_index(t_stack **a)
// {

// }

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack *a;
	t_stack *new;

	a = NULL;
	while (argc > 1)
	{
		new = ft_lstnew(char_to_numbers(&a, argv[argc - 1]));
		if (new == NULL)
        {
            free_stack(a); // Free memory if allocation fails
            return NULL;
        }
		ft_lstadd_front(&a, new);
		argc--;
	}
	check_for_dup(&a);
	find_smallest(&a);
	find_biggest(&a);
	//assign_index(&a);
	return(a);
}

int	main(int argc, char **argv)
{
// int	main()
// {
// 	int argc = 6;
// 	char *argv[] = {"program_name", "100", "-30", "8", "2", "-10"};

	t_stack *a;

	argc_check(argc);
	
	a = fill_stack((argc), (argv));
	//printf("list size:%d\n", ft_lstsize(a));
	if (ft_lstsize(a) == 2)
		sort_2_a(&a);
	else if (ft_lstsize(a) == 3)
		sort_3_a(&a);
	else if (ft_lstsize(a) == 5 || ft_lstsize(a) == 4)
		sort_5(&a);
	else if (ft_lstsize(a) > 5)
		sort_all(&a);

	//print_stack("a", a);

	free_stack(a);
	return (0);
} 
// 
// to do:
// read about sorting args

// print_stack("a", a);
// 	print_stack("b", b);