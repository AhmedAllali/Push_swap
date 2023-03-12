/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:15:52 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/12 17:14:37 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Push_swap.h"

void sa(int *stack,int len,int p)
{
	int tmp=0;


	if (len ==1 || len  ==0)
		ft_exit("Error ");
	else
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	if (p)
		write (1,"sa\n",3);
}

void sb(int *stack,int len,int p)
{
	int tmp=0;
	
	if (len  == 0)
		ft_exit("Error ");
	else
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	if (p)
		write (1,"sb\n",3);
}
void ss(t_stack stack)
{
	sa(stack.a,stack.lena,0);
	sb(stack.b,stack.lenb,0);
	write(1, "ss\n", 3);
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
	int j=0;
	if (stack->lena == 0)
		return;
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
	write (1,"pb\n",3);
}

	
 void pa(t_stack *stack)
{
	int tmp = 0;
	int i = stack->lena;
	int j = 0;
	
	if (stack->lenb == 0)
		return;
	tmp = stack->b[0];
	while (j<stack->lenb)
	{
		stack->b[j]=stack->b[j+1];
		j++;
	}
	while (i > 0)
	{
		stack->a[i]=stack->a[i-1];
		i--;
	}
	stack->a[0] = tmp;
	stack->lena++;
	stack->lenb--;	
	write (1,"pa\n",3);
}
void rra (t_stack *stack,int p)
{
	int tmp = 0;
	if (stack->lena == 0)
		return;
	tmp = stack->a[0];
	stack->a[0] = stack->a[stack->lena-1];
	stack->a[stack->lena-1] = tmp;
	 if (p)
	 	write (1,"rra\n",4);
}
void rb (t_stack *stack,int p)
{
int tmp = 0;
int i =0;
	if (stack->lenb == 0)
		return;
	tmp = stack->b[0]; 
	while (i < stack->lenb)
	{
		stack->b[i] = stack->b[i+1];
		i++;
	}
	stack->b[stack->lenb-1] = tmp;
	 if (p)
	 	write (1,"rb\n",3);
}
void rr(t_stack *stack)
{
	ra(stack,0);
	rb(stack,0);
	write(1, "rr\n", 3);
}
void ra(t_stack *stack,int p)
{
	int i = 0;
	int tmp;
	tmp = stack->a[0];
	if (stack->lena == 0)
		return;
	while (i<=stack->lena-1)
	{
		stack->a[i] =stack->a[i+1];
	 	i++;
	}
	 stack->a[stack->lena-1]=tmp ;
	 if (p)
	 	write (1,"ra\n",3);
}
void rrb(t_stack *stack,int p)
{
	int tmp;
	int i;

	i = stack->lenb-1;
	if (stack->lenb == 0)
		return;
	tmp =  stack->b[stack->lenb-1];
	while (i > 0)
	{
		stack->b[i] =stack->b[i - 1];
	 	i--;
	}
	stack->b[0] = tmp;
	if (p)
		write(1, "rrb\n", 4);
}
void rrr(t_stack *stack)
{
	
	rra(stack,0);
	rrb(stack,0);	
	write (1,"rrr\n",4);
}