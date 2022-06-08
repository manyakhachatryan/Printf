/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:52:14 by manykhac          #+#    #+#             */
/*   Updated: 2022/04/26 20:25:27 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_func(char d, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == d)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0 ;
	while (s1[start] && ft_func(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_func(s1[end - 1], set))
		end--;
	ptr = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (start < end)
ptr[i++] = s1[start++];
	ptr[i] = 0;
	return (ptr);
}
