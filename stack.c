/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:17:15 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/07 03:30:29 by ahallali         ###   ########.fr       */
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


void print_stack(int *stack, int len)
{
	printf("Stack contents: ");
	for	(int i = 0; i < len; i++) 
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}
