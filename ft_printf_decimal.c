/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:33:00 by aorynbay          #+#    #+#             */
/*   Updated: 2024/07/10 15:21:11 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_d(int n)
{
	char	c;
	int		count;

	c = '\0';
	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		count++;
	}
	if (n >= 10)
		count += ft_putnbr_d(n / 10);
	c = n % 10 + '0';
	count++;
	write (1, &c, 1);
	return (count);
}

int	ft_printf_decimal(va_list *args)
{
	int		n;
	int		count;

	n = va_arg(*args, int);
	count = ft_putnbr_d(n);
	return (count);
}
