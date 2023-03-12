/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:06:45 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/12 17:48:31 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Push_swap.h"

int * f_to_b(t_stack *stack)
	{
	int index1 = 0,index2=0;
	int j;
	int len ;
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
		sort_table(stack->fake,stack->lena);
		index1 = (len / 8);
		index2 = ((len / 9)/2);
		if (stack->a[j] <= stack->fake[index2])
		{
			pb(stack);
		}
		else if (stack->a[j]<=stack->fake[index1])
		{
			pb(stack);
			if (stack->lenb >= 2)
				rb(stack,1);
		}
		else
		{
			ra(stack,1);
		}
		free(stack->fake);
	}
    return (stack->b);
}
void back_to_a(t_stack *stack)
	{
	int max = 0;
	
	int target;
	while (stack->lenb)
	{
			max = (max_stack(stack->b, stack->lenb));
			target = stack->b[max];
			if (max <= stack->lenb / 2)
			{
				while (max > 0)
				{
					rb(stack,1);
					--max;
				}
				
			}
			else if (max > stack->lenb / 2)
			{
				while (max < stack->lenb)
				{
					rrb(stack,1);
					max++;
					
				}

				
			}
			pa(stack);
	}
}
int max_stack (int *stack, int len)
{
	int i = 0;
	int max = stack[0];
	int max_id = 0;
	while (i < len)
	{
		// printf("|%d\n",stack[i]);
		if (max < stack[i+1])
		{
			max = stack[i+1];
			max_id = i + 1;
		}
		i++;
	}
	 return (max_id);
}

void sort_table(int * stack,int len)
{
	int i, j ,n,position,swap ;
	n = len ;
	i=0;
	while ( i < n - 1)
	{
		position = i;
			j = i + 1;
		while(j < n)
		{
			if (stack[position] > stack[j])
				position = j;
			j++;
		}
		if(position != i)
		{
			swap=stack[i];
			stack[i]=stack[position];
			stack[position]=swap;
		}
		
		i++;
	}
}