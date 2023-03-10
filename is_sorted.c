/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:46:59 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/10 01:19:41 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int is_sorted(int *t ,int len)
{
  int i =0;
  int j ;
    while (i<len)
    {
      j=i+1;
      while (j<len)
      {
        if (t[i]>t[j])
            return(1);         
        j++;
      }
      i++;
    }
    return(0);
 }