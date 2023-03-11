/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:31:45 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/11 06:18:08 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int max_stack (int *stack, int len)
{
	int i = 0;
	int max = stack[0];
	int max_id = 0;
	while (i < len)
	{
		// printf("|%d\n",stack[i]);
		if (max<stack[i+1])
		{
			max = stack[i+1];
			max_id = i + 1;
		}
		i++;
	}
	// printf("******max[%d]max_id[%d]len[%d]*******\n", max, max_id, len);
	 return (max_id);
}
void sort_table(int * stack,int len)
{
	int i, j ,n,position,swap ;
	n = len ;
	i=0;
	while ( i < n - 1)
	{
		position = i;
			j = i + 1;
		while(j < n)
		{
			if (stack[position] > stack[j])
				position = j;
			j++;
		}
		if(position != i)
		{
			swap=stack[i];
			stack[i]=stack[position];
			stack[position]=swap;
		}
		
		i++;
	}
}


void	ft_pushswap(t_stack stack,t_push push, char **av)
{
	int len;
	int check;
	int index1,index2;
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
	free(push.values);
	stack.lena =push.i;
	stack.lenb = 0;
	sort_table(push.values,push.i);
	int i = 0;
	int j;
	while (stack.lena)
	{
		len = stack.lena;
		stack.fake = init_stack(stack.lena);
		j = 0;
		while (j < len)
		{
			stack.fake[j] = stack.a[j];
			j++;
		}
		j = 0;
		sort_table(stack.fake,stack.lena);
		// print_stack(stack.fake, stack.lena, 'c');
			index1 = (len / 8);
			index2 = ((len / 9)/2);
		// printf("------[%d]<", stack.a[0]);
		// printf("[%d]", stack.fake[index2]);
		if (stack.a[j] <= stack.fake[index2])
		{
			// printf("[[%d]]\n", stack.a[0]);
			pb(&stack);
		}
		else if (stack.a[j]<=stack.fake[index1])
		{
			pb(&stack);
			if (stack.lenb >= 2)
				rb(&stack);
		}
		else
		{
			ra(&stack);
		}
		free(stack.fake);
		i++;
	}
	// printf("------------------siuuuuuuuuu\n");
	// int i=0;
	// while (i < 10)
	// {
	// 	pb(&stack);
	// 	i++;
	// }
	// printf("---------%d",push.i);
	// print_stack(stack.a, stack.lena, 'a');
	int max = 0;
		// int count;
		 int target;
		while (stack.lenb)
		{
			max = (max_stack(stack.b, stack.lenb));
			 target = stack.b[max];
			// printf("max value is : [%d] value is : [%d]\n", max, stack.b[max]);
			// if (max ==0)
			// 	pa(&stack);
			// printf("max [%d] len/2 [%d] target [%d] stackb0 [%d]\n", max, stack.lenb / 2, target, stack.b[0]);
			// print_stack(stack.b, stack.lenb, 0);
			if (max <= stack.lenb / 2)
			{
				// while (max <= stack.lenb && target != stack.b[0])
				while (max-- >0)
				{
					// printf("max [%d] len [%d] ch&al khaso [%d]\n", max, stack.lenb, stack.lenb - count );
					// printf("stack length [%d]\n", stack.lenb);
					rb(&stack);
				}
			}
			else
			{

				// while (max > 0 && target != stack.b[0])
				while (max++ < stack.lenb)
				{
					printf("max [%d] length [%d]\n", max, stack.lenb);
					rrb(&stack);
				}
			}
			printf("expedition de zabi target [%d]  top [%d]\n", target, stack.b[0]);
			if (target== stack.b[0])
				pa(&stack);
			// print_stack(stack.b, stack.lenb, 'b');
		}
		print_stack(stack.a, stack.lena, 'a');
		printf("\n");
		ra(&stack);
		print_stack(stack.a, stack.lena, 'a');
	}
	// stack.lenb++;
	// print_stack(stack.a, stack.lena, 1);
	// }
	// // printf("%d\n", stack.lenb);
void check_leaks()
{
	system ("leaks push_swap");
}
int	main(int ac, char **av)
{
	// atexit(check_leaks);
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

