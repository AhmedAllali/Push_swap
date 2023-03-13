/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:55:40 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/13 16:03:53 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Push_swap.h"

int	check_operator(char *av)
{
	int	i ;

	i = 0;
	while (av[i])
	{
		if (av[i] == '-' || av[i] == '+')
		{
			if (av[i + 1] == '-' || av[i + 1] == '+')
				return (1);
			if (!ft_isdigit(av[i + 1]))
				return (1);
		}
		i++;
	}
	return (0);
}

size_t	ft_getlen(char **av)
{
	int		i;
	int		j;
	size_t	len;

	i = 1;
	len = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '\0')
			ft_exit("Error");
		while (av[i][j] && (av[i][j] == ' ' || av[i][j] == '\t'))
			j++;
		if (av[i][j] == '\0')
			ft_exit("Error");
		len += ft_strlen(av[i]) + 1;
		i++;
	}
	return (len);
}

void	concatenateargs(char *av, char *p)
{	
	while (*av)
	{
		*p++ = *av++;
	}
}

char	*ft_joinargs(char **av)
{
	size_t	len;
	size_t	i;
	char	*res;
	char	*p;

	i = 1;
	len = ft_getlen(av);
	if (len == 0)
		return (NULL);
	res = (char *)malloc(len * sizeof (char));
	if (!res)
		return (NULL);
	p = res;
	while (av[i])
	{
		concatenateargs(av[i], p);
		p += ft_strlen(av[i]);
		if (av[i + 1])
		{
			*p++ = ' ';
		}
		i++;
	}
	*p = '\0';
	return (res);
}
