/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:06:45 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/13 16:04:28 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Push_swap.h"

int	*f_to_b(t_stack *stack)
{
	int	index1;
	int	index2;
	int	j;
	int	len;

	index1 = 0;
	index2 = 0;
	while (stack->lena)
	{
		len = stack->lena;
		stack->fake = init_stack(stack->lena);
		j = 0;
		while (j < len)
		{
			stack->fake[j] = stack->a[j];
			j++;
		}
		j = 0;
		sort_table(stack->fake, stack->lena);
		index1 = (len / 8);
		index2 = ((len / 9) / 2);
		check_fi_ai(stack, j, index2, index1);
		free(stack->fake);
	}	
	return (stack->b);
}

void	check_fi_ai(t_stack *stack, int j, int index2, int index1)
{
	if (stack->a[j] <= stack->fake[index2])
	{
		pb(stack);
	}
	else if (stack->a[j] <= stack->fake[index1])
	{
		pb(stack);
		if (stack->lenb >= 2)
			rb(stack, 1);
	}
	else
	{
		ra(stack, 1);
	}	
}

void	back_to_a(t_stack *stack)
{
	int	max;
	int	target;

	max = 0;
	while (stack->lenb)
	{
		max = (max_stack(stack->b, stack->lenb));
		target = stack->b[max];
		if (max <= stack->lenb / 2)
		{
			while (max-- > 0)
			{
				rb(stack, 1);
			}
		}
		else if (max > stack->lenb / 2)
		{
			while (max++ < stack->lenb)
			{
				rrb(stack, 1);
			}
		}
		pa(stack);
	}
}

int	max_stack(int *stack, int len)
{
	int	i;
	int	max;
	int	max_id;

	i = 0;
	max = stack[0];
	max_id = 0;
	while (i < len - 1)
	{
		if (max < stack[i + 1])
		{
			max = stack[i + 1];
			max_id = i + 1;
		}
		i++;
	}
	return (max_id);
}

void	sort_table(int *stack, int len)
{
	int	i;
	int	j;
	int	n;
	int	position;
	int	swap;

	n = len;
	i = 0;
	while (i++ < n - 1)
	{
		position = i;
		j = i + 1;
		while (j < n)
		{
			if (stack[position] > stack[j])
				position = j;
			j++;
		}
		if (position != i)
		{
			swap = stack[i];
			stack[i] = stack[position];
			stack[position] = swap;
		}
	}
}
