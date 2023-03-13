# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 19:55:44 by ahallali          #+#    #+#              #
#    Updated: 2023/03/13 17:42:57 by ahallali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra
SRCS = Push_swap.c \
		mandatory/tools/tools.c \
		mandatory/tools/parsing.c\
		mandatory/tools/stack.c\
		mandatory/tools/instructions.c\
		mandatory/tools/is_sorted.c\
		mandatory/tools/sorting_algo.c\
		mandatory/tools/sort_small.c\
		mandatory/tools/instructions2.c\
		mandatory/tools/instructions3.c\
		mandatory/tools/functions_libft.c\
		mandatory/tools/functions_libft2.c\
		mandatory/tools/functions_libft3.c\


OBJECT = $(SRCS:.c=.o)
INCLUDE = Push_swap.h

all	: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(FLAGS) $(OBJECT)  -o $(NAME)

%.o : %.c $(INCLUDE)
		$(CC) $(FLAGS) -c $< -o $@
clean : 
	@rm -rf $(OBJECT)
	@echo "Cleaning objects"
fclean: clean
	@rm -rf $(NAME)
	@echo "Cleaning objects && executable"
re : fclean all 