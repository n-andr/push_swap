#include "push_swap.h"

/* Functions list:
- char_to_numbers aka atoi
- fill_stack 
 */


int	char_to_numbers(t_stack **a, char *str)
{
	long int	result;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	if ((str[i] == '-') || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i ++;
	}
	if (str[i] == '\0')
		write_error(a);
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9'))
		{
			result = result * 10 + (str[i] - '0');
			if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
					write_error(a);
			i ++;
		}
		else
			write_error(a);
	}
	return (result * sign);
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
            free_stack(a);
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
