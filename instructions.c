/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:15:52 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/13 00:35:00 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

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
	{
		stack->b[0] = stack->a[0];
		while (j <= stack->lena)
		{
			stack->a[j] = stack->a[j + 1];
			j++;
		}
		stack->lena--;
		stack->lenb++;
	}
	else
	{
		while (i >= 0)
		{
			swap(&stack->b[i], &stack->b[i - 1]);
			i--;
		}
		stack->b[0] = stack->a[0];
		while (j <= stack->lena)
		{
			stack->a[j] = stack->a[j + 1];
			j++;
		}
		stack->lena--;
		stack->lenb++;
	}
	write(1, "pb\n", 3);
}
