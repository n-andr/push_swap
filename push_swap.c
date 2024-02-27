#include "push_swap.h"
// errorc.c
//
void	argc_check (int argc)
{
	if (argc == 1)
        exit (EXIT_FAILURE);
}
//
// end errorc.c

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_lstnew(void *content)
{
	t_stack	*vasya;

	vasya = (t_stack *)malloc(sizeof(t_stack));
	if (vasya == 0)
		return (NULL);
	vasya->value = content;
	vasya->next = NULL;
	return (vasya);
}

void	fill_stack(t_stack *a, int argc, char **argv)
{
	t_stack *new;

	while (argc > 1)
	{
		new = ft_lstnew(&(*argv[argc - 1]));
		ft_lstadd_front(&a, new);
		argc--;
	}
}

int	main(int argc, char **argv)
{
	t_stack *a;

	a = malloc(sizeof(t_stack));
	argc_check(argc);
	fill_stack(a, argc, argv);
	
	while (a->next != NULL)
	{
		printf("%p\n", a->value);
		a = a->next;
	}

	
	return (0);
} 