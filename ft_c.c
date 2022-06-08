/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:32:25 by manykhac          #+#    #+#             */
/*   Updated: 2022/05/25 20:50:48 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"
#include<unistd.h>

int	size(int n)
{
	int	i;

	i = 0;
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

void	random_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	print_str(char *str)
{
	int	length;

	length = 0;
	if (str == NULL)
	{
		random_str("(null)");
		length = length + 6;
	}
	else
	{
		while (str[length] != '\0')
		{
			write(1, &str[length], 1);
			length++;
		}
	}
	return (length);
}

int	print_decimal(int k)
{
	int		length;
	char	*n;

	n = ft_itoa(k);
	length = print_str(n);
	free(n);
	return (length);
}
