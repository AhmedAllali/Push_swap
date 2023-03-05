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

void	push1(int data, int len, char *stack, int *top)
{
	if (*top == -1)
	{
		stack[len - 1] = data;
		*top = len -1;
	}
	else if (*top == 0)
		printf("stack full\n");
	else
	{
		stack[*top -1] = data;
		(*top)--;
	}
}
	// printf("pushed %d onto stack, top is now %d\n", data, *top);

void	print_stack(char *stack, int len, int top)
{
	printf("Stack contents: ");
	for	(int i = top; i < len; i++) 
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}

char	*init_stack(int len)
{
	char	*stack;

	stack = malloc(len * sizeof(char));
	return (stack);
}

void	ft_pushswap(t_push push, char **av)
{
	char	*stacka;
	int		top;

	push.i = 0;
	push.j = 0;
	top = -1;
	push.joined = ft_joinargs(av);
	printf("%s\n", push.joined);
	push.splited = ft_split(push.joined, ' ');
	if (hasduplicate(push.splited, ft_check (push)) == 1)
		ft_exit("error: Duplication found\n");
	push.values = malloc(sizeof(int) * ft_check (push) + 1);
	while (push.splited[push.i] && ft_check (push) >= push.i)
	{
		push.values[push.i] = ft_atoi(push.splited[push.i]);
			push.i++;
	}
	stacka = init_stack(push.i + 1);
	while (push.values[push.j])
	{
		push1(push.values[push.j], push.i + 1, stacka, &top);
		push.j++;
	}
	print_stack(stacka, push.i + 1, top);
}

int	main(int ac, char **av)
{
	t_push	push;

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