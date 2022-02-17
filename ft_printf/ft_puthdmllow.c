/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdmllow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:27:16 by yismaili          #+#    #+#             */
/*   Updated: 2021/12/04 22:38:52 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_puthdmllow(unsigned int hdml)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (hdml < 16)
	{
		ft_putchar(hex[hdml]);
	}
	else
	{
		ft_puthdmllow(hdml / 16);
		ft_puthdmllow(hdml % 16);
	}
	return (ft_len(hdml));
}
