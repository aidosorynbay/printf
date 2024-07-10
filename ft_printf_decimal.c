/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:33:00 by aorynbay          #+#    #+#             */
/*   Updated: 2024/07/10 16:35:11 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_d(int n)
{
	char	c;
	int		count;
	int		write_count;

	c = '\0';
	count = 0;
	if (n == -2147483648)
	{
		write_count = write(1, "-2147483648", 11);
		if (write_count == -1)
			return (-1);
		return (11);
	}
	else if (n < 0)
	{
		write_count = write(1, "-", 1);
		if (write_count == -1)
			return (-1);
		n = -n;
		count++;
	}
	if (n >= 10)
		count += ft_putnbr_d(n / 10);
	if (count == -1)
		return (-1);
	c = n % 10 + '0';
	write_count = write(1, &c, 1);
	if (write_count == -1)
		return (-1);
	return (count + write_count);
}

int	ft_printf_decimal(va_list *args)
{
	int		n;
	int		count;

	n = va_arg(*args, int);
	count = ft_putnbr_d(n);
	return (count);
}
