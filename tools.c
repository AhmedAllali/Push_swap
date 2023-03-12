/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:57:26 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/13 00:35:54 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_exit(char *error)
{
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}

int	ft_check(t_push push)
{
	int	i;

	i = 0;
	while (push.splited && push.splited[i])
	{
		if (check_args(push.splited[i]) == 1)
			ft_exit("Error\n");
		if (check_operator(push.splited[i]) != 0)
			ft_exit("Error\n");
		i++;
	}
	return (i);
}

int	hasduplicate(char **arr, int len)
	{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[j][0] == '+' )
				arr[j] = arr[j] + 1;
			if (arr[i][0] == '+' )
				arr[i] = arr[i] + 1;
			if (ft_strncmp(arr[i], arr[j], ft_strlen(arr[i])) == 0 && \
				ft_strlen(arr[i]) == ft_strlen(arr[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && \
		!(str[i] == '+' || str[i] == '-'))
			return (1);
		i++;
	}
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		ft_exit("Roor");
	return (0);
}
