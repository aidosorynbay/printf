/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:31:19 by aorynbay          #+#    #+#             */
/*   Updated: 2024/07/10 15:22:30 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(va_list *args)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(*args, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}
