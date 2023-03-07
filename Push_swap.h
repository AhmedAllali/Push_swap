/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:31:42 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/07 23:10:06 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdio.h>
# include "libft/libft.h"
# include<limits.h>
#include<string.h>
typedef struct s_push
{
	char	*joined;
	char	**splited;
	int		*values;
	int		i;
	int		j;
	
} t_push;

typedef struct s_stack
{
	int		*a;
	int		*b;
	int *tmp;
	int		topa;
	int		topb;
	int lena;
	int lenb;
} t_stack;

size_t	ft_getlen(char **av);
void	concatenateargs(char *av, char *p);
void	ft_pushswap(t_stack stack,t_push push, char **av);
int		ft_isdigit(int c);
int		check_args(char *str);
int		check_operator(char *av);
void	ft_exit(char *error);
char	*ft_joinargs(char **av);
int		ft_check(t_push push);
int		hasduplicate(char **arr, int len);
int		*init_stack(int len);
void 	ss(t_stack stack);
void	ft_push(int data, int len, int *stack);
void 	print_stack(int *stack, int len, int a);
void	 sa(int *stack, int len);
void 	sb(int *stack, int len);
void	pb(t_stack *stack);
void	pa(t_stack *stack);
void	ra(t_stack *stack);
void	rb (t_stack *stack);
void	rr(t_stack *stack);
void rra(t_stack *stack);
void rrb(t_stack *stack);
void rrr(t_stack *stack);



#endif