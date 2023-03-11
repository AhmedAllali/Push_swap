/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:17:15 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/11 05:07:20 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Push_swap.h"

int	*init_stack(int len)
{
	int	*stack;

	stack =(int *) malloc((len + 1) * sizeof(int));
	ft_bzero(stack, len);
	if (!stack)
		return (0);
	return (stack);
}

void	ft_push(int data, int len, int *stack)
{
//  int k ;

// 	 if (k < len)
// 	 {
		stack[len] = data;
		// len++;
		// printf("------>%d\n",stack[len]);
		// 		 k++;
		// 	 }
		// 	 else if (k == len)
		// 	 	ft_exit("STACK IS FULL");
		// 	 else
		// 		ft_exit("no element in stack ");
}


void print_stack(int *stack, int len, int a)
{
	if (a=='a')
	printf("A ");
	else if (a=='b')
	printf("B ");
	else
	printf("fake ");
	printf("Stack contents: \n");
	for	(int i = 0; i < len; i++) 
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}
