#include "push_swap.h"
// errorc.c
//

void	argc_check (int argc)
{
	if (argc == 1)
        exit (EXIT_FAILURE);
}

int		write_error(t_stack **stack)
{
	write (1, "Error\n", 6);
	free_stack(stack);
	exit (EXIT_FAILURE);
	return (0);
}

int	check_for_dup(t_stack **a)
{
	t_stack *tmp;
	t_stack *curent;

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

//
// end errorc.c

//free
//

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (stack == NULL)
		return;
	current = *stack;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

//
// end free

//sort
//

void sort_2(t_stack *stack)
{
	int	a;
	int	b;

	a = stack->value;
	b = stack->next->value;
	
	if ((a > b))
		write(1, "sa\n", 3);
}

void sort_3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->value;
	b = stack->next->value;
	c = stack->next->next->value;
	
	// if ((a > b) && (a > c))
	// 	write(1, "sa\nrra\n", 6);
	// if ((a > b) && (a < c))
	// 	write(1, "ra\n", 3);
	// if ((a > b) && (b < c))
	// 	write(1, "sa\n", 3);
	// if ((a < b) && (a > c))
	// 	write(1, "rra\n", 4);
	// if ((a < b) && (b < c))
	// 	write(1, "\n", 1);
	// if ((a < b) && (b > c))
	// 	write(1, "ra\nsa\nrra\n", 9);
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
	*lst = new;
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == 0)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack *a;
	t_stack *new;

	while (argc > 1)
	{
		new = ft_lstnew(char_to_numbers(&a, argv[argc - 1]));
		printf("c_t_n:%d\n",char_to_numbers(&a, argv[argc - 1]));
		ft_lstadd_front(&a, new);
		argc--;
	}
	check_for_dup(&a);
	return(a);
}

int	main(int argc, char **argv)
{
// int	main()
// {
// 	int argc = 5;
// 	char *argv[] = {"program_name", "1", "3", "8", "2"};

	t_stack *a;

	argc_check(argc);
	
	a = fill_stack((argc), (argv));
	printf("%d\n", ft_lstsize(a));
	if (ft_lstsize(a) == 2)
		sort_2(a);
	else if (ft_lstsize(a) == 3)

		sort_3(a);
	while (a!= NULL)
	{
		printf("%d\n", a->value);
		a = a->next;
	}

	free_stack(&a);
	//free(a); not sure
	return (0);
} 
// 
// to do:
// read about sorting args