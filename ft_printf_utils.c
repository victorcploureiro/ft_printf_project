/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:43:47 by vcarrara          #+#    #+#             */
/*   Updated: 2023/11/29 18:09:32 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[count])
	{
		ft_putchar(str[count]);
		count++;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	long	x;
	int		i;

	x = (long) nb;
	i = 0;
	if (x < 0)
	{
		ft_putchar('-');
		x = -x;
		i++;
	}
	if (x >= 10)
	{
		i += ft_putnbr(x / 10);
		ft_putchar(x % 10 + '0');
	}
	else
		ft_putchar(x + '0');
	return (i + 1);
}

int	ft_putunbr(int nb)
{
	unsigned int	x;
	int				i;

	x = (unsigned int) nb;
	i = 0;
	if (x >= 10)
	{
		i += ft_putnbr(x / 10);
		ft_putchar(x % 10 + '0');
	}
	else
		ft_putchar(x + '0');
	return (i + 1);
}
