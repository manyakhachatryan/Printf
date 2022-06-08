/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:51:03 by manykhac          #+#    #+#             */
/*   Updated: 2022/05/25 21:01:39 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"
#include<unistd.h>

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_hexlow(unsigned int num)
{
	int	length;

	length = 0;
	if (num >= 16)
	{
		ft_hexlow(num / 16);
		ft_hexlow(num % 16);
	}
	else
	{
		if (num <= 9)
		{
			ft_putchar_fd((num + '0'), 1);
		}
		else
		{
			length++;
			ft_putchar_fd((num - 10 + 'a'), 1);
		}
	}
	return (length);
}

int	ft_hexup(unsigned int num)
{
	int	length;

	length = 0;
	if (num >= 16)
	{
		ft_hexup(num / 16);
		ft_hexup(num % 16);
	}
	else
	{
		if (num <= 9)
		{
			ft_putchar_fd((num + '0'), 1);
		}
		else
		{
			length++;
			ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
	return (length);
}

int	hexup(unsigned int n)
{
	int	length;

	length = 0;
	ft_hexup(n);
	length = ft_hex_len(n);
	return (length);
}

int	hexlow(unsigned	int n)
{	
	int	length;

	length = 0;
	ft_hexlow(n);
	length = ft_hex_len(n);
	return (length);
}
