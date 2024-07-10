/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:33:46 by aorynbay          #+#    #+#             */
/*   Updated: 2024/07/10 15:22:47 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	char	c;
	int		count;

	c = '\0';
	count = 0;
	if (n >= 10)
		count += ft_putnbr_u(n / 10);
	c = n % 10 + '0';
	count++;
	write (1, &c, 1);
	return (count);
}

int	ft_printf_unsigned(va_list *args)
{
	unsigned int	n;
	int				count;

	n = va_arg(*args, unsigned int);
	count = ft_putnbr_u(n);
	return (count);
}
