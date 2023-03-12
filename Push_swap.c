/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:31:45 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/12 18:02:23 by ahallali         ###   ########.fr       */
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
	if (is_sorted(push.values, push.i) == 0)
		ft_exit("Error++");

	stack.a = init_stack(push.i);
	stack.b = init_stack(push.i);
	while (check)
	{
		ft_push(push.values[push.j], push.j, stack.a);
		push.j++;
		check--;
	}
	stack.lena =push.i;
	stack.lenb = 0;
	if (stack.lena == 3)
{
		sort_3(&stack);
		exit(0);
}
	sort_table(push.values,push.i);
	f_to_b(&stack);
	back_to_a(&stack);

	


}

// {
// 	system ("leaks push_swap");
// }
int	main(int ac, char **av)
{
	// atexit(check_leaks);
	//FILE *ptr = freopen("output.txt","w+",stdout);
	t_push push;
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

