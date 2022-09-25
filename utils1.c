/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:23:47 by chfederi          #+#    #+#             */
/*   Updated: 2021/12/23 22:23:50 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_x(unsigned long n)
{
	int		i;

	i = n16len(n);
	if (n > 0xf)
		ft_putnbr_x(n / 0x10);
	if (ft_isdigit(n % 0x10 + '0') == 1)
		ft_putchar_fd(n % 0x10 + '0');
	else
		ft_putchar_fd((n % 0x10) + 87);
	return (i);
}

int	n16len(unsigned long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 0x10;
		i++;
	}
	return (i);
}

int	ft_putnbr_p(unsigned long n)
{
	write (1, "0x", 2);
	if (n > 0xf)
		ft_putnbr_x(n / 0x10);
	if (ft_isdigit(n % 0x10 + '0') == 1)
		ft_putchar_fd(n % 0x10 + '0');
	else
		ft_putchar_fd((n % 0x10) + 87);
	return (n16len(n) + 2);
}

int	ft_putnbr_u(unsigned int n)
{
	if (n > 9)
		ft_putnbr_fd(n / 10);
	ft_putchar_fd((n % 10) + 48);
	return (ft_nlen(n));
}
