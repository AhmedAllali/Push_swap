/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:31:05 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/13 17:32:19 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Push_swap.h"

int	ft_atoi(const char *s)
{
	int				sign;
	unsigned long	r;

	r = 0;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{	
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		r = r * 10 + *s - '0';
		s++;
	}
	if (r > INT_MAX && sign == 1)
		ft_exit("Error\n");
	if (r > (unsigned long )INT_MAX + 1 && sign == -1)
		ft_exit("Error\n");
	return ((int)(sign * r));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memset(void *ptr, int c, size_t len)
{
	size_t	i ;

	i = 0;
	while (i < len)
		((int *)ptr)[i++] = (int)c;
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
