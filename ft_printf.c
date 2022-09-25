/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:03:28 by chfederi          #+#    #+#             */
/*   Updated: 2021/12/23 22:03:30 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list		arg;
	int			n;

	va_start(arg, input);
	n = ft_print((char *)input, arg);
	va_end(arg);
	return ((int)n);
}

int	ft_print(char *input, va_list arg)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
		{
			x += ft_check(arg, input[i + 1]);
			i++;
		}
		else
			x += ft_putchar_fd(input[i]);
		i++;
	}
	return (x);
}

int	ft_check(va_list arg, char	input)
{
	if (input == '%')
		return (ft_putchar_fd('%'));
	if (input == 's')
		return (ft_putstr_fd(va_arg(arg, char *)));
	if (input == 'i' || input == 'd' )
		return (ft_putnbr_fd(va_arg(arg, int)));
	if (input == 'u')
		return (ft_putnbr_u(va_arg(arg, unsigned int)));
	if (input == 'c')
		return (ft_putchar_fd(va_arg(arg, int)));
	if (input == 'X')
		return (ft_putnbr_16(va_arg(arg, unsigned int)));
	if (input == 'x')
		return (ft_putnbr_x(va_arg(arg, unsigned int)));
	if (input == 'p')
		return (ft_putnbr_p((unsigned long)va_arg(arg, void *)));
	return (0);
}

int	ft_putstr_fd(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(long n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-');
		n = -n;
		i++;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10);
	ft_putchar_fd((n % 10) + 48);
	return (i + ft_nlen(n));
}
