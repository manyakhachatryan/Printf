/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:01:01 by manykhac          #+#    #+#             */
/*   Updated: 2022/04/28 21:20:48 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;
	size_t			j;

	ptr1 = (unsigned char *)haystack;
	ptr2 = (unsigned char *)needle;
	if (!*needle)
		return ((char *) ptr1);
	if (len == 0)
		return (NULL);
	if (!*ptr1)
		return (NULL);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && needle[j]
			&& i + j < len && haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
