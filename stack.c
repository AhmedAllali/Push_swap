/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:17:15 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/08 01:18:23 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Push_swap.h"

int	*init_stack(int len)
{
	int	*stack;

	stack =(int *) malloc(len * sizeof(int));
	ft_bzero(stack, len);
	if (!stack)
		return (0);
	return (stack);
}

void	ft_push(int data, int len, int *stack)
{
	static int k;

	if (k < len)
	{
		stack[k] = data;
		k++;
	}
	else if (k == len)
		ft_exit("STACK IS FULL");
	else 
		ft_exit("no element in stack ");
}


void print_stack(int *stack, int len, int a)
{
	if (a)
	printf("A ");
	else
	printf("B ");
	
	printf("Stack contents: \n");
	for	(int i = 0; i < len; i++) 
	{
		printf("%d\n ", stack[i]);
	}
	printf("\n");
}
