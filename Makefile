# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 11:02:09 by ccormon           #+#    #+#              #
#    Updated: 2024/01/23 11:02:16 by ccormon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap

CC 			= cc
RM			= rm -f

CFLAGS 		+= -Wall -Wextra -Werror

SRC 		=	main.c\
				ft_split.c\
				ft_printf.c\
				ft_printf_utils1.c\
				ft_printf_utils2.c\
				check_errors.c\
				check_errors_utils.c\
				init_stack.c\
				commands_swap.c\
				commands_push.c\
				commands_rotate.c\
				commands_rev_rotate.c\
				sort_turk.c\
				sort_turk_utils1.c\
				sort_turk_utils2.c\

OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all bonus clean fclean re
