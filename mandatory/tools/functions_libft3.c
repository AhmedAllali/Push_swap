/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_libft3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:33:44 by ahallali          #+#    #+#             */
/*   Updated: 2023/03/13 17:37:21 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*ptr;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	if (start >= len_s)
		len = 0;
	else if (len > len_s)
		len = len_s - start;
	ptr = (char *)malloc(len + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start + i];
			i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strncmp(const char *str1, const char	*str2, size_t lenght)
{
	size_t	i;

	i = 0;
	if (lenght == 0)
		return (0);
	while (i < lenght)
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i]
			|| !str1[i] || !str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
