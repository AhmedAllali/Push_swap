/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:17:15 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/13 16:04:02 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Push_swap.h"

int	*init_stack(int len)
{
	int	*stack;

	stack = (int *)malloc((len + 1) * sizeof(int));
	ft_bzero(stack, len);
	if (!stack)
		return (0);
	return (stack);
}

void	ft_push(int data, int len, int *stack)
{
	stack[len] = data;
}

void	sort_stack(t_stack *stack)
	{
	if (stack->lena == 2)
		sort_2(stack);
	else if (stack->lena == 3)
		sort_3(stack);
	else if (stack->lena == 4)
		sort_4(stack);
	else if (stack->lena == 5)
		sort_5(stack);
	else
	{
		f_to_b(stack);
		back_to_a(stack);
	}
}

void	s_to_v(t_push *push, int check)
{
	while (push->splited[push->i] && check >= push->i + 1)
	{
		push->values[push->i] = ft_atoi(push->splited[push->i]);
		push->i++;
	}
}

void	v_to_a(t_push *push, t_stack *stack, int check)
{
	while (check)
	{
		ft_push(push->values[push->j], push->j, stack->a);
		push->j++;
		check--;
	}
}

// void	print_stack(int *stack, int len, int a)
// {
// 	if (a == 'a')
// 		printf("A ");
// 	else if (a == 'b')
// 		printf("B ");
// 	else
// 		printf("fake ");
// 	printf("Stack contents: \n");
// 	for (int i = 0; i < len; i++)
// 	{
// 		printf("%d ", stack[i]);
// 	}
// 	printf("\n");
// }
