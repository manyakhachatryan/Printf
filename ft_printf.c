/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:17:43 by manykhac          #+#    #+#             */
/*   Updated: 2022/05/25 20:36:07 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include<unistd.h>
#include<stdarg.h>
#include "includes/ft_printf.h"
#include "libft/libft.h"

char	*ft_itoa(int n)
{
	int				i;
	int				index;
	unsigned int	num;
	char			*ptr;

	num = n;
	i = size(n);
	index = 0;
	ptr = malloc (i);
	ptr[--i] = '\0';
	if (n < 0)
	{
		num = n * -1;
		ptr[index] = '-';
		index++;
	}
	while (index < i--)
	{
		ptr[i] = num % 10 + '0';
		num /= 10;
	}
	return (ptr);
}

char	*ft_itoau(unsigned int n)
{
	int				i;
	int				index;
	unsigned int	num;
	char			*ptr;

	num = n;
	i = sizeu(n);
	index = 0;
	ptr = (char *)malloc(sizeof(char) * i);
	ptr[--i] = '\0';
	if (n < 0)
	{
		num = n * -1;
		ptr[index] = '-';
		index++;
	}
	while (index < i--)
	{
		ptr[i] = num % 10 + '0';
		num /= 10;
	}
	return (ptr);
}

int	format(va_list arg, const char k)
{
	int	length;

	length = 0;
	if (k == 'c')
		length += print_char(va_arg(arg, int));
	else if (k == 's')
		length = length + print_str(va_arg(arg, char *));
	else if (k == 'd')
		length += print_decimal(va_arg(arg, int));
	else if (k == 'i')
		length += print_integer(va_arg(arg, int));
	else if (k == 'u')
		length += print_integeru(va_arg(arg, unsigned int));
	else if (k == 'p')
		length = length + print_p(va_arg(arg, unsigned long long));
	else if (k == 'x')
		length += hexlow(va_arg(arg, unsigned int));
	else if (k == 'X')
		length += hexup(va_arg(arg, unsigned int));
	else if (k == '%')
	{
		write (1, "%", 1);
		length++;
	}
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		length;

	i = 0;
	length = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length = length + format(arg, str[i + 1]);
			i++;
		}
		else
			length += print_char(str[i]);
		i++;
	}
	va_end(arg);
	return (length);
}
