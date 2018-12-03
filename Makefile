# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 14:37:37 by oyenyi-           #+#    #+#              #
#    Updated: 2018/09/22 13:44:12 by oyenyi-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	=	checker
NAME2	=	push_swap
CC		=	gcc -o
FLAGS	=	-Wall -Wextra -Werror
INC		= 	-I ./includes/
LIB		= 	./libft/
SRC1 	= 	./srcs/ft_algorithm.c ./srcs/ft_moves.c ./srcs/ft_do.c\
			./srcs/ft_help_moves.c ./srcs/ft_printing.c ./srcs/ft_rotation_cmd.c\
			./srcs/initializer.c ./srcs/ft_rev_rotation_cmd.c ./srcs/ft_get_operation.c\
			./srcs/ft_pushswap_cmd.c ./srcs/ft_make_stacks.c\
			./srcs/ft_order.c ./srcs/ft_update_op.c  ./srcs/help.c\
		./srcs/ft_checker_main.c
SRC2 	= 	./srcs/ft_algorithm.c ./srcs/ft_moves.c ./srcs/ft_do.c\
			./srcs/ft_help_moves.c ./srcs/ft_printing.c ./srcs/ft_rotation_cmd.c\
			./srcs/initializer.c ./srcs/ft_rev_rotation_cmd.c ./srcs/ft_get_operation.c\
			./srcs/ft_pushswap_cmd.c ./srcs/ft_make_stacks.c\
			./srcs/ft_order.c ./srcs/ft_update_op.c ./srcs/help.c\
			./srcs/ft_push_swap.c
RM		= 	rm -rf

$(NAME1):
	@make -C $(LIB)
	@$(CC) $(NAME1) $(FLAGS) $(SRC1) $(INC) -L libft/ -lft
	@echo "\x1B[32mChecker compiled successfully\x1B[3m"

$(NAME2):
	@make -C $(LIB)
	@$(CC) $(NAME2) $(FLAGS) $(SRC2) $(INC) -L libft/ -lft
	@echo "\x1B[32mPush_swap compiled successfully\x1B[3m"

all: $(NAME1) $(NAME2)
clean:
	@make clean -C $(LIB)
fclean:
	@make fclean -C $(LIB)
	@$(RM) $(NAME1) $(NAME2)
re: fclean all
