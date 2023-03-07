/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:31:45 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/07 05:02:08 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"



void	ft_pushswap(t_stack stack,t_push push, char **av)
{
	int check;
	stack.topb = 0;
	stack.lena = 0;
	push.i = 0;
	push.j = 0;
	push.joined = ft_joinargs(av);
	push.splited = ft_split(push.joined, ' ');
	check = ft_check(push);
	if (hasduplicate(push.splited, check )== 1)
		ft_exit("Error\n");
	push.values = malloc(sizeof(int) * check);
	if (!push.values)
		return ;
	while (push.splited[push.i] && check >= push.i + 1)
	{
		push.values[push.i] = ft_atoi(push.splited[push.i]);
		push.i++;
	}
	stack.a = init_stack(push.i);
	stack.b = init_stack(push.i);
	while (check)
	{
		ft_push(push.values[push.j], push.i, stack.a);
		push.j++;
		check--;
	}
	stack.lena =push.i;
	stack.lenb = 0;
	// while (push.i > 0)
	// {
	// 	stack.b[0] = 1;
	// 	stack.b[1] = 2;
	// 	stack.b[2] = 3;
	// 	push.i--;
	// }
	print_stack(stack.a, stack.lena);
	// print_stack(stack.b, stack.lenb);

	pb(&stack);
	printf("%d\n",stack.lena);
	printf("%d\n",stack.lenb);
	
	// pa(&stack);
	print_stack(stack.a, stack.lena);
	print_stack(stack.b, stack.lenb);
}

int	main(int ac, char **av)
{
	t_push	push;
	t_stack stack;
	stack.topb = 0;
	push.joined = NULL;
	if (ac > 1)
	{
		ft_pushswap(stack ,push, av);
	}
	else
		ft_exit("Error\n");
}

