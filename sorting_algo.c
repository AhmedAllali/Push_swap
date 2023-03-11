/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:06:45 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/11 17:18:18 by ahallali         ###   ########.fr       */
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
		// print_stack(stack.fake, stack->lena, 'c');
			index1 = (len / 8);
			index2 = ((len / 9)/2);
		// printf("------[%d]<", stack.a[0]);
		// printf("[%d]", stack.fake[index2]);
		if (stack->a[j] <= stack->fake[index2])
		{
			// printf("[[%d]]\n", stack.a[0]);
			pb(stack);
		}
		else if (stack->a[j]<=stack->fake[index1])
		{
			pb(stack);
			if (stack->lenb >= 2)
				rb(stack);
		}
		else
		{
			ra(stack);
		}
		free(stack->fake);
	}
    return (stack->b);
}