/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:03:36 by chfederi          #+#    #+#             */
/*   Updated: 2021/12/23 22:03:38 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *input, ...);
int	ft_check(va_list arg, char	input);
int	ft_print(char *input, va_list arg);
int	ft_putstr_fd(char *s);
int	ft_putnbr_fd(long n);
int	ft_nlen(long n);
int	ft_putnbr_16(unsigned int n);
int	ft_putnbr_x(unsigned long n);
int	ft_isdigit(int c);
int	ft_putnbr_u(unsigned int n);
int	n16len(unsigned long int n);
int	ft_putnbr_p(unsigned long n);
int	ft_putchar_fd(char c);

#endif