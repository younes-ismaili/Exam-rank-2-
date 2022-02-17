/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 00:47:11 by yismaili          #+#    #+#             */
/*   Updated: 2021/12/04 22:22:10 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	int	lenprint;

	lenprint = 0;
	if (format == 's')
		lenprint += ft_putstr(va_arg(args, char *));
	else if (format == 'x')
		lenprint += ft_puthdmllow(va_arg(args, unsigned int));
	else if (format == 'd')
		lenprint += ft_putnbr(va_arg(args, int));
	return (lenprint);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		lenprint;

	i = 0;
	lenprint = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			lenprint += ft_format(args, str[i]);
		}
		else
		{
			lenprint += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (lenprint);
}
