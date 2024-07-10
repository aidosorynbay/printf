/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:07:59 by aorynbay          #+#    #+#             */
/*   Updated: 2024/07/10 10:41:56 by aorynbay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	handle_char(va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	write(1, &c, 1);
	return 1;
}

int	handle_str(va_list *args)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(*args, char*);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return i;
}

int	handle_percent(char c)
{
	write(1, &c, 1);
	return 1;
}

int ft_putnbr_d(int n)
{
	char	c;
	int		count;

	c = '\0';
	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return 11;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		count++;
	}
	if (n >= 10)
	{
		count += ft_putnbr_d(n / 10);
	}
	c = n % 10 + '0';
	count++;
	write (1, &c, 1);
	return count;
}

int ft_putnbr_u(unsigned int n)
{
	char	c;
	int		count;

	c = '\0';
	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr_u(n / 10);
	}
	c = n % 10 + '0';
	count++;
	write (1, &c, 1);
	return count;
}

int	handle_decimal(va_list *args)
{
	int		n;
	int		count;

	n = va_arg(*args, int);
	count = ft_putnbr_d(n);
	return count;
}

int	handle_unsigned(va_list *args)
{
	unsigned int	n;
	int				count;

	n = va_arg(*args, unsigned int);
	count = ft_putnbr_u(n);
	return count;
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			count++;
		}
		else
		{
			i++;
			if (str[i] == 'c')
				count += handle_char(&args);
			else if (str[i] == 's')
			{
				count += handle_str(&args);
			}
			else if (str[i] == '%')
			{
				count += handle_percent(str[i]);
			}
			else if (str[i] == 'd')
			{
				count += handle_decimal(&args);
			}
			else if (str[i] == 'u')
			{
				count += handle_unsigned(&args);
			}
			
		}
		i++;
	}
	va_end(args);
	return count;
}

int	main(void)
{
	int a = printf("char: %c, string: %s, percent: %%, num_d: %d, num_u: %u\n", 't', "hello", 42, -1);
	int b = ft_printf("char: %c, string: %s, percent: %%, num_d: %d, num_u: %u\n", 't', "hello", 42, -1);
	printf("%d\n", a);
	printf("%d\n", b);
}