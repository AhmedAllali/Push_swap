/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 00:24:37 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/13 00:24:56 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	rb(t_stack *stack, int p)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	if (stack->lenb == 0)
		return ;
	tmp = stack->b[0];
	while (i < stack->lenb)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->lenb - 1] = tmp;
	if (p)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	ra(stack, 0);
	rb(stack, 0);
	write(1, "rr\n", 3);
}

void	ra(t_stack *stack, int p)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->a[0];
	if (stack->lena == 0)
		return ;
	while (i <= stack->lena - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->lena - 1] = tmp;
	if (p)
		write(1, "ra\n", 3);
}

void	rrb(t_stack *stack, int p)
{
	int	tmp;
	int	i;

	i = stack->lenb - 1;
	if (stack->lenb == 0)
		return ;
	tmp = stack->b[stack->lenb - 1];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
	if (p)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
{
	rra(stack, 0);
	rrb(stack, 0);
	write(1, "rrr\n", 4);
}
