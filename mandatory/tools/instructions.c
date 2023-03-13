/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:15:52 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/13 16:04:10 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Push_swap.h"

void	sa(int *stack, int len, int p)
{
	int	tmp;

	tmp = 0;
	if (len == 1 || len == 0)
		ft_exit("Error ");
	else
		tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	if (p)
		write(1, "sa\n", 3);
}

void	sb(int *stack, int len, int p)
{
	int	tmp;

	tmp = 0;
	if (len == 0)
		ft_exit("Error ");
	else
		tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	if (p)
		write(1, "sb\n", 3);
}

void	ss(t_stack stack)
{
	sa(stack.a, stack.lena, 0);
	sb(stack.b, stack.lenb, 0);
	write(1, "ss\n", 3);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	pb(t_stack *stack)
{
	int	i;
	int	j;

	i = stack->lenb;
	j = 0;
	if (stack->lena == 0)
		return ;
	if (stack->lenb == 0)
		mv_a_1(stack);
	else
		mv_b_up_a_down(stack, i);
	write(1, "pb\n", 3);
}
