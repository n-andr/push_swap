#include "push_swap.h"

/* Error list:
- only one arg : return control back to user
- empty string : error
- over min/max int limit : error
- duplicates : error
- invalid char (letter or ,.-/etc) : error 
1/5 done */

void	argc_check (int argc)
{
	if (argc == 1)
        exit (EXIT_FAILURE);
}

int	check_args(int argc, char **argv)
{

}

int	check_duplicates()
{
	
		write (1, "Error/n", 8);
		exit (EXIT_FAILURE);
}
