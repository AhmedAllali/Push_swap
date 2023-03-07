/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:15:52 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/07 05:00:51 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Push_swap.h"

void sa(int *stack,int len)
{
	int tmp=0;


	if (len ==1 || len  ==0)
		ft_exit("Error ");
	else
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void sb(int *stack,int len)
{
	int tmp=0;


	if (len ==1 || len  ==0)
		ft_exit("Error ");
	else
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}
void ss(t_stack stack)
{
	sa(stack.a,stack.lena);
	sb(stack.b,stack.lenb);
}
 void pb(t_stack *stack)
{
	if (stack->lena == 0)
	ft_exit("Error*-*-*-");
	stack->b[stack->lenb] = stack->a[stack->lena];
	stack->lena--;
	stack->lenb++;
}
 void pa(t_stack *stack)
{
	stack->lena++;
	printf("%d\n",stack->lena);
	stack->a[stack->lena] = stack->b[stack->lenb-1];
	printf("%d----***-*-\n",stack->a[stack->lena]);
	stack->lenb--;
}
// 	// stack.lenb--;
// }
// char * 