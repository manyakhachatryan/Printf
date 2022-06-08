/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:06:43 by manykhac          #+#    #+#             */
/*   Updated: 2022/05/25 20:54:07 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"
#include<unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	sizeu(unsigned int n)
{
	int	i;

	i = 0 ;
	if (n < 0 || n == 0)
	{
		n *= -1;
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

int	print_integeru(int k)
{
	int		length;
	char	*n;

	n = ft_itoau(k);
	length = print_str(n);
	free(n);
	return (length);
}
