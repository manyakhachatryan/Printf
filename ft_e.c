/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:58:38 by manykhac          #+#    #+#             */
/*   Updated: 2022/05/25 20:44:19 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"
#include<unistd.h>

int	print_char(int k)
{
	write(1, &k, 1);
	return (1);
}

int	print_integer(int k)
{
	int		length;
	char	*n;

	n = ft_itoa(k);
	length = print_str(n);
	free(n);
	return (length);
}

void	ft_print_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_print_ptr(num / 16);
		ft_print_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	print_p(unsigned long long ptr)
{
	int	length;

	length = 0;
	write (1, "0x", 2);
	length = length + 2;
	if (ptr == 0)
	{
		length += write(1, "0", 1);
	}
	else
	{
		ft_print_ptr(ptr);
		length += ptr_len(ptr);
	}
	return (length);
}
