# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahallali <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 19:55:44 by ahallali          #+#    #+#              #
#    Updated: 2023/03/05 16:37:41 by ahallali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra 
SRCS = Push_swap.c \
		tools.c \
		parsing.c 

LIB = libft/
LIBFT= libft/libft.a
LIBFT_DIR = $(LIB)
OBJECT = $(SRCS:.c=.o)
INCLUDE = Push_swap.h
$(NAME): $(OBJECT) $(LIBFT)
	$(CC) $(FLAGS) $(OBJECT) -L$(LIBFT_DIR) -lft -o $(NAME)
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