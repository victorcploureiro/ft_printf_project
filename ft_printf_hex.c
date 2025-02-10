/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:56:41 by vcarrara          #+#    #+#             */
/*   Updated: 2023/11/29 11:00:17 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char flag)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, flag);
		ft_put_hex(num % 16, flag);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (flag == 'x')
				ft_putchar((num - 10 + 'a'));
			if (flag == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
}

int	ft_puthex(unsigned int num, const char flag)
{
	if (num == 0)
		return (ft_putchar('0'));
	else
		ft_put_hex(num, flag);
	return (ft_hex_len(num));
}
