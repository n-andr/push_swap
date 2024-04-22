# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 12:45:18 by nandreev          #+#    #+#              #
#    Updated: 2024/04/18 15:12:44 by nandreev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = push_swap.c \
			libft.c lst_libft.c \
			errors.c \
			moves_both_stacks.c moves_a.c moves_b.c \
			count_moves.c move_least_moves.c \
			find_sorted_list.c \
			fill_stack.c \
			free.c \
			smallest_and_biggest.c

OBJS:= $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re