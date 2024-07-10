/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:35:46 by aorynbay          #+#    #+#             */
/*   Updated: 2024/07/10 15:21:43 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char c)
{
	char	*hex;
	int		i;
	char	buffer[9];
	int		count;

	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	i = 0;
	count = 0;
	if (n == 0)
	{
		write(1, &hex[n], 1);
		return (1);
	}
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	count = i;
	while (i > 0)
		write(1, &buffer[--i], 1);
	return (count);
}

int	ft_printf_hexa(va_list *args, char c)
{
	int				count;
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	count = ft_puthexa(n, c);
	return (count);
}
