/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 00:26:53 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/13 16:04:54 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Push_swap.h"

void	pa(t_stack *stack)
{
	int	tmp;
	int	i;
	int	j;

	i = stack->lena;
	j = 0;
	tmp = 0;
	if (stack->lenb == 0)
		return ;
	tmp = stack->b[0];
	while (j < stack->lenb)
	{
		stack->b[j] = stack->b[j + 1];
		j++;
	}
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	stack->lena++;
	stack->lenb--;
	write(1, "pa\n", 3);
}

void	rra(t_stack *stack, int p)
{
	int	tmp;
	int	i;

	i = stack->lena;
	tmp = 0;
	if (stack->lena == 0)
		return ;
	tmp = stack->a[stack->lena - 1];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	if (p)
		write(1, "rra\n", 4);
}

void	mv_a_1(t_stack *stack)
	{
	int	j;

	j = 0;
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
}

void	mv_b_up_a_down(t_stack *stack, int i)
{
	int	j;

	j = 0;
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
