NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = push_swap.c libft.c errors.c moves_both_stacks.c moves_a.c moves_b.c sort_all.c find_sorted_list.c fill_stack.c

OBJS:= $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re