/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:29:39 by manykhac          #+#    #+#             */
/*   Updated: 2022/05/25 20:13:50 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		print_str(char *str);
void	random_str(char *str);
int		print_decimal(int k);
char	*ft_itoa(int n);
int		size(int n);
int		hexup(unsigned int n);
int		ft_hexup(unsigned int num);
int		ft_hex_len(unsigned int num);
int		ft_hexlow(unsigned int num);
int		hexlow(unsigned int n);
int		print_p(unsigned long long ptr);
int		ptr_len(uintptr_t num);
void	ft_print_ptr(uintptr_t num);
int		print_char(int k);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
int		sizeu(unsigned int n);
char	*ft_itoau(unsigned int n);
int		print_integeru(int k);
int		print_integer(int k);
int		format(va_list arg, const char k);

#endif
