/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:31:45 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/05 16:37:07 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	push1(int data, int len, int *stack, int *top)
{
	if (*top == -1)
	{
		stack[len - 1] = data;
		*top = len -1;
	}
	else if (*top == 0)
	{
		printf("%d\n", *top);
		printf("stack full\n");
	}
	else
	{
		stack[*top -1] = data;
		(*top)--;
	}
}
	// printf("pushed %d onto stack, top is now %d\n", data, *top);

void	print_stack(int *stack, int len, int top)
{
	printf("Stack contents: ");
	for	(int i = top; i < len; i++) 
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}

int	*init_stack(int len)
{
	int	*stack;

	stack = malloc(len * sizeof(int));
	return (stack);
}

void	ft_pushswap(t_push push, char **av)
{
	int 	*stacka;
	int		top;

	push.i = 0;
	push.j = 0;
	top = -1;
	push.joined = ft_joinargs(av);
	push.splited = ft_split(push.joined, ' ');
	int check = ft_check(push);
	if (hasduplicate(push.splited, check/*ft_check(push))*/ )== 1)
		ft_exit("error: Duplication found\n");
	push.values = malloc(sizeof(int) * check/*ft_check(push)*/);
	if (!push.values)
		return ;
	while (push.splited[push.i] && check/*ft_check(push)*/ >= push.i + 1)
	{
		push.values[push.i] = ft_atoi(push.splited[push.i]);
		push.i++;
	}
	stacka = init_stack(push.i);
	while (check--)
	{
			push1(push.values[push.j], push.i, stacka, &top);
			push.j++;
	}
	print_stack(stacka, push.i , top);
}

int	main(int ac, char **av)
{
	t_push	push;

	push.joined = NULL;
	if (ac > 1)
	{
		ft_pushswap(push, av);
	}
	else
		ft_exit("Args more than 1");
}

/* check arguments
join them then split
check forbidden char
check duplicate
init stacks a et b  using linked list
choose an algo of sort
and use it to store sorted numbers in the stack a
i can use stack b if there is some big numbers
*/