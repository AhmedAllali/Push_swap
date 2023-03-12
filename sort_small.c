/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:49:34 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/12 18:29:30 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Push_swap.h"


void sort_3(t_stack *stack)
{
    int max = max_stack(stack->a,3);
    printf("max ; %d", max);
   
    if (max == 0)
        ra(stack, 1);
    else if (max == 1)
        ra(stack, 3);
    print_stack(stack->a, stack->lena, 'a');

    if (stack->a[0]> stack->a[1])
        sa(stack->a,3, 3);
    print_stack(stack->a, stack->lena, 'a');
        
}