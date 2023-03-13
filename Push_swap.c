/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:31:45 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/13 15:52:22 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_pushswap(t_stack stack, t_push push, char **av)
{
	int	check;

	stack.topb = 0;
	stack.lena = 0;
	push.i = 0;
	push.j = 0;
	push.joined = ft_joinargs(av);
	push.splited = ft_split(push.joined, ' ');
	check = ft_check(push);
	free(push.joined);
	if (hasduplicate(push.splited, check) == 1)
		ft_exit("Error\n");
	push.values = init_stack(check);
	s_to_v(&push, check);
	if (is_sorted(push.values, push.i) == 0)
		exit(0);
	stack.a = init_stack(push.i);
	stack.b = init_stack(push.i);
	v_to_a(&push, &stack, check);
	stack.lena = push.i;
	stack.lenb = 0;
	sort_stack(&stack);
	free (stack.b);
	free (stack.a);
}

int	main(int ac, char **av)
{
	t_push	push;
	t_stack	stack;

	stack.topb = 0;
	push.joined = NULL;
	if (ac > 1)
	{
		ft_pushswap(stack, push, av);
	}
	else
		exit(1);
}
