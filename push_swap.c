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

// moves
//
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a == NULL)
		return;
	temp = *a;
	*a = (*a)->next;
	if (*a != NULL)
		(*a)->previous = NULL;
	temp->next = *b;
	if ((*b) != NULL)
		(*b)->previous = temp;
	*b = temp;
	write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b == NULL)
		return;
	temp = *b;
	*b = (*b)->next;
	if (*b != NULL)
		(*b)->previous = NULL;
	temp->next = *a;
	if ((*a) != NULL)
		(*a)->previous = temp;
	*a = temp;
	write(1, "pa\n", 3);
}
void	ra(t_stack **a)
{
	t_stack	*last;
	t_stack *first;

	if (*a == NULL || (*a)->next == NULL)
		return;
	last = *a;
	while (last->next)
		last = last->next;
	first = *a;
	*a = (*a)->next;
	(*a)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	write(1, "ra\n", 3);
}

//
// end moves

//sort
//

void sort_2(t_stack *stack)
{
	int	a;
	int	b;

	a = stack->value;
	b = stack->next->value;
	
	if ((a > b))
	{
		
		stack->value = b;
		stack->next->value = a;
		write(1, "sa\n", 3);
	}
}

void sort_3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->value;
	b = stack->next->value;
	c = stack->next->next->value;
	if ((a > b) && (a > c) && (b > c))
	{
		stack->value = c;
		stack->next->next->value = a;
		write(1, "sa\nrra\n", 7);
	}
	if ((a > b) && (a < c) && (b < c))
	{
		stack->value = b;
		stack->next->value = a;
		//stack->next->next->value = a;
		write(1, "sa\n", 3);
	}
	if ((a > b) && (b < c) && (a > c))
	{
		stack->value = b;
		stack->next->value = c;
		stack->next->next->value = a;
		write(1, "ra\n", 3);
	}
	if ((a < b) && (a > c) && (b > c))
	{
		stack->value = c;
		stack->next->value = a;
		stack->next->next->value = b;
		write(1, "rra\n", 4);
	}
	// if ((a < b) && (b < c) && (a < c))
	// {
		//do nothing
	// }
	if ((a < b) && (b > c) &&(a < c))
	{
		//stack->value = a;
		stack->next->value = c;
		stack->next->next->value = b;
		write(1, "ra\nsa\nrra\n", 10);
	}
}

void	sort_5(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	while (ft_lstsize(*a) > 3)
		pb (a, &b);
	sort_3(*a);
	while (b)
	{
		if (b->value < (*a)->value)
			pa (a, &b);
		
		if (b->biggest == 1)
		{
			pa (a, &b);
			ra (a);
		}
		else
			ra (a);
			
	}
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
	t_stack *curent;
	t_stack *tmp;

	curent = *stack;
	curent->smallest = 1;
	tmp = (*stack)->next;
	while (tmp != NULL)
	{
		if (curent->value > tmp->value)
		{
			curent->smallest = 0;
			tmp->smallest = 1;
			curent = tmp;
		}
		tmp = tmp->next;
	}
}
void	find_biggest(t_stack **stack)
{
	t_stack *curent;
	t_stack *tmp;

	curent = *stack;
	curent->biggest = 1;
	tmp = (*stack)->next;
	while (tmp != NULL)
	{
		if (curent->value < tmp->value)
		{
			curent->biggest = 0;
			tmp->biggest = 1;
			curent = tmp;
		}
		tmp = tmp->next;
	}
}

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
		sort_2(a);
	else if (ft_lstsize(a) == 3)
		sort_3(a);
	else if (ft_lstsize(a) == 5 || ft_lstsize(a) == 4)
		sort_5(&a);
	//print_stack("a", a);

	free_stack(a);
	return (0);
} 
// 
// to do:
// read about sorting args

// print_stack("a", a);
// 	print_stack("b", b);