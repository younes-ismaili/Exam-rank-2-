/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:23:11 by yismaili          #+#    #+#             */
/*   Updated: 2021/12/04 22:47:43 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num = num * (-1);
	}
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int ft_putchar(int c)
{
	write(1, &c, 1);
	return(1);
}

int	ft_putnbr(int nu)
{
	long int	n;

	n = nu;
	if (n < 0)
	{
		ft_putchar('-');
		n = n * (-1);
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	return (ft_len(nu));
}
