/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarrara <vcarrara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:19:36 by vcarrara          #+#    #+#             */
/*   Updated: 2023/12/04 16:22:51 by vcarrara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags(va_list ap, const char flag)
{
	int	i;

	i = 0;
	if (flag == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (flag == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (flag == 'p')
		i += ft_putptr(va_arg(ap, unsigned long long));
	else if (flag == 'd' || flag == 'i')
		i += ft_putnbr(va_arg(ap, int));
	else if (flag == 'u')
		i += ft_putunbr(va_arg(ap, unsigned int));
	else if (flag == 'x' || flag == 'X')
		i += ft_puthex(va_arg(ap, unsigned int), flag);
	return (i);
}

int	ft_printf(const char *f, ...)
{
	va_list	ap;
	int		len;

	if (f == NULL)
		return (-1);
	len = 0;
	va_start(ap, f);
	while (*f)
	{
		if (*f != '%')
			len += ft_putchar(*f++);
		else
		{
			f++;
			if (*f == '%')
				len += ft_putchar('%');
			else
				len += ft_flags(ap, *f);
			f++;
		}
	}
	va_end(ap);
	return (len);
}
