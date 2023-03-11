/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:15:52 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/11 22:36:14 by ahallali         ###   ########.fr       */
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
	printf("pb\n");
	
}

	
 void pa(t_stack *stack)
{
	printf("--------------start \n");
	print_stack(stack->b,stack->lenb,'b');
	
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
	// stack->a[stack->lena] = tmp;
	stack->lenb--;
	// write(1, "pa\n", 3);
	printf("--------------end \n");
	
	printf("pa\n");
		
}
	// print_stack(stack->b,stack->lenb,'b');
void rra (t_stack *stack)
{
	int tmp = 0;
	if (stack->lena == 0)
{	printf("here");
		return;}
	tmp = stack->a[0];
	stack->a[0] = stack->a[stack->lena-1];
	stack->a[stack->lena-1] = tmp;
}
void rrb (t_stack *stack)
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
void ra(t_stack *stack)
{
	int i = 0;
	int tmp;
	tmp = stack->a[0];
	if (stack->lena == 0)
		return;
	// stack->a[0]= stack->a[stack->lena-1];
	while (i<=stack->lena-1)
	{
		stack->a[i] =stack->a[i+1];
	 	i++;
	}
	 stack->a[stack->lena-1]=tmp ;
	printf("ra\n");
	 
}
void rb(t_stack *stack)
{
	int tmp;
	int i;

	i = 0;
	if (stack->lenb == 0)
		return;
	tmp = stack->b[0];
	// stack->b[0]= stack->b[stack->lenb-1];
	while (i<=stack->lenb)
	{
		stack->b[i] =stack->b[i+1];
	 	i++;
	}
	 stack->b[stack->lenb-1]=tmp ;
	 printf("rb\n");
}
void rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	printf("rrr\n");
	
}