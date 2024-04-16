#include "push_swap.h"
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
// 		if (stack->previous != NULL)
// 			printf("- previous value: %d   ", stack->previous->value);
// 		else
// 			printf("- previous value: NULL   ");
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


// ONLY IN STACK A!!!! 
// ALL COMANDS FOR STACK A! 
void sort_2_a(t_stack **stack)
{
	int	a;
	int	b;

	a = (*stack)->value;
	b = (*stack)->next->value;
	if ((a > b))
		sa(stack);
}

// ONLY IN STACK A!!!! 
// ALL COMANDS FOR STACK A! 
void sort_3_a(t_stack **stack)
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
	while (b)
	{
		find_smallest(a);
		find_biggest(a);
		if (b->value < (*a)->value && b->value > (ft_lstlast(*a))->value)
			pa (a, &b);
		else if ((b->value > (ft_lstlast(*a))->value) && (ft_lstlast(*a))->biggest == 1)
			pa (a, &b);
		else if ((b->value < (*a)->value) && (*a)->smallest == 1)
			pa (a, &b);
		else
		{
			zeroing_moves(b);
			count_moves(*a, b);
			move_cheapest(a, &b);
		}
	}
	find_smallest(a);
	find_biggest(a);
	while ((*a)->smallest != 1)
		move_smalest_top(a);
}

//
//end sort


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



int	main(int argc, char **argv)
{
	t_stack *a;

	argc_check(argc);
	a = fill_stack((argc), (argv));
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
