# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 19:55:44 by ahallali          #+#    #+#              #
#    Updated: 2023/03/12 17:59:56 by ahallali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
#FLAGS = -Wall -Werror -Wextra
SRCS = Push_swap.c \
		tools.c \
		parsing.c\
		stack.c\
		instructions.c\
		is_sorted.c\
		sorting_algo.c\
		sort_small.c
# 
LIB = libft/
LIBFT= libft/libft.a
LIBFT_DIR = $(LIB)
OBJECT = $(SRCS:.c=.o)
INCLUDE = Push_swap.h
$(NAME): $(OBJECT) $(LIBFT)
	$(CC) $(FLAGS) $(OBJECT) -L$(LIBFT_DIR) -lft -g -o $(NAME)
$(LIBFT) :
		@make -sC $(LIB)

%.o : %.c $(INCLUDE)
		$(CC) $(FLAGS) -c $< -o $@
all	: $(NAME) 
clean : 
		rm -rf $(OBJECT)
fclean: clean
	rm -rf $(NAME)
	@make fclean -sC $(LIB)
re : fclean all 