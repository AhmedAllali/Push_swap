/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:15:52 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/09 22:36:22 by ahallali         ###   ########.fr       */
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
	
	if (len  == 0)
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
void swap (int *a , int *b)
{
	int tmp ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
 void pb(t_stack *stack)
{
	int i = stack->lenb;
	// int tmp =0;
	int j=0;
	if (stack->lena == 0)
		return;
	// stack->lena ++;
	if (stack->lenb == 0){
		stack->b[0] = stack->a[0];
		stack->lena--;
	}
	else
	{
		while (i>=0)
		{
		swap (&stack->b[i] , &stack->b[i-1]);
		i--;
		}
		stack->b[0] = stack->a[0];
		while (j<= stack->lena)
		{
		stack->a[j] = stack->a[j + 1];
		j++;
		}
		stack->lena--;
		stack->lenb++;
	}
	
}
	
	// while (i<=stack->lena)
	// {
	// 	stack->a[i]= stack->a[i+1];
	// 	i++;
	// }
	// // if (stack->lenb > 1)
	// // {
	// while  (j>=0)
	// {
	// 	stack->b[j] = stack->b[j - 1];
	// 	j--;
	// }
	// stack->lenb--;
	
//  void pa(t_stack *stack)
// {
// 	int tmp = 0;
// 	int i = 1;
// 	if (stack->lenb == 0)
// 		return;
// 	stack->lena++;
// 	while (i<stack->lena)
// 	{
// 		stack->a[i]=stack->a[i-1];
// 		i++;
// 	}
// 	tmp = stack->a[stack->lena];
// 	stack->a[0] = stack->b[0];
// 	stack->a[stack->lena] = tmp;
// 	stack->lenb--;
// }
void ra (t_stack *stack)
{
	int tmp = 0;
	if (stack->lena == 0)
		return;
	tmp = stack->a[0];
	stack->a[0] = stack->a[stack->lena-1];
	stack->a[stack->lena-1] = tmp;
}
void rb (t_stack *stack)
{
	int tmp = 0;
	if (stack->lenb == 0)
		return;
	tmp = stack->b[0];
	stack->b[0] = stack->b[stack->lenb-1];
	stack->b[stack->lenb-1] = tmp;
}
void rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
void rra(t_stack *stack)
{
	int i = 0;
	int tmp;
	tmp = stack->a[0];
	if (stack->lena == 0)
		return;
	stack->a[0]= stack->a[stack->lena-1];
	while (i<=stack->lena-1)
	{
		stack->a[i] =stack->a[i+1];
	 	i++;
	}
	 stack->a[stack->lena-1]=tmp ;
}
void rrb(t_stack *stack)
{
	int tmp;
	int i;

	i = 0;
	if (stack->lenb == 0)
		return;
	tmp = stack->b[0];
	stack->b[0]= stack->b[stack->lenb-1];
	while (i<=stack->lenb-1)
	{
		stack->b[i] =stack->b[i+1];
	 	i++;
	}
	 stack->b[stack->lenb-1]=tmp ;
}
void rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}