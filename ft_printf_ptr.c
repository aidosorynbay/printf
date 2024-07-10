/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:04:40 by aorynbay          #+#    #+#             */
/*   Updated: 2024/07/10 15:57:15 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_ptr(unsigned long n)
{
	char	*hex;
	int		i;
	char	buffer[17];
	int		count;
	int		write_count;

	hex = "0123456789abcdef";
	i = 0;
	count = 0;
	if (n == 0)
	{
		write_count = write(1, &hex[n], 1);
		if (write_count == -1)
			return (-1);
		return (1);
	}
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	count = i;
	while (i > 0)
	{
		write_count = write(1, &buffer[--i], 1);
		if (write_count == -1)
			return (-1);
	}
	return (count);
}

int	ft_printf_ptr(va_list *args)
{
	unsigned long	n;
	int				count;
	int				write_count;

	n = va_arg(*args, unsigned long);
	write_count = write(1, "0x", 2);
	if (write_count == -1)
		return (-1);
	count = 2;
	count += ft_puthexa_ptr(n);
	return (count);
}
