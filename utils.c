/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 22:03:43 by chfederi          #+#    #+#             */
/*   Updated: 2021/12/23 22:03:46 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar_fd(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_nlen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i = 1;
		return (i);
	}
	if (n > 0)
	{
		if (n <= 9 && n > 0)
		{
			i = 1;
			return (i);
		}
		while ((n / 10) > 9)
		{
			n = n / 10;
			i++;
		}
		i = i + 2;
	}
	return (i);
}

int	ft_putnbr_16(unsigned int n)
{
	int		i;

	i = n16len(n);
	if (n < 0)
	{
		ft_putchar_fd('-');
		n = -n;
		i++;
	}
	if (n > 0xf)
		ft_putnbr_16(n / 0x10);
	if (ft_isdigit(n % 0x10 + '0') == 1)
		ft_putchar_fd(n % 0x10 + '0');
	else
		ft_putchar_fd((n % 0x10) + 0x37);
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
