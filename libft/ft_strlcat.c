/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:11:23 by manykhac          #+#    #+#             */
/*   Updated: 2022/04/27 20:43:47 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	size_t	i;
	size_t	c;

	a = 0;
	b = 0;
	i = 0;
	while (dst[a] != '\0')
		a++;
	while (src[b] != '\0')
		b++;
	c = a;
	if (a > dstsize)
		return (b + dstsize);
	else if (a < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && (a < dstsize - 1))
			dst[a++] = src[i++];
		return (c + b);
	}
	return (b + a);
}
