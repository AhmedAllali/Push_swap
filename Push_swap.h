/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:31:42 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/05 16:29:57 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdio.h>
# include "libft/libft.h"
# include<limits.h>

typedef struct s_push
{
	char	*joined;
	char	**splited;
	int		*values;
	int		i;
	int		j;
}	t_push;

size_t	ft_getlen(char **av);
void	concatenateargs(char *av, char *p);
void	ft_pushswap(t_push push, char **av);
int		ft_isdigit(int c);
int		check_args(char *str);
int		check_operator(char *av);
void	ft_exit(char *error);
char	*ft_joinargs(char **av);
int		ft_check(t_push push);
int		hasduplicate(char **arr, int len);

#endif