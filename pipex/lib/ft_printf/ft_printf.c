/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:07:01 by npaturzo          #+#    #+#             */
/*   Updated: 2023/10/04 16:38:17 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char conv)
{
	int	length;

	length = 0;
	if (conv == 'c')
		length += ft_printchar(va_arg(args, int));
	else if (conv == 's')
		length += ft_printstr(va_arg(args, char *));
	else if (conv == 'p')
		length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (conv == 'd' || conv == 'i')
		length += ft_printnbr(va_arg(args, int));
	else if (conv == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (conv == 'x' || conv == 'X')
		length += ft_print_hex(va_arg(args, unsigned int), conv);
	else if (conv == '%')
		length += ft_printpercent();
	return (length);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	va_list	args;
	int		length;

	i = 0;
	length = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			length += ft_formats(args, fmt[i + 1]);
			i++;
		}
		else
			length += ft_printchar(fmt[i]);
		i++;
	}
	va_end(args);
	return (length);
}
