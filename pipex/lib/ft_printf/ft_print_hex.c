/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:15:14 by npaturzo          #+#    #+#             */
/*   Updated: 2023/10/04 14:20:24 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char conv)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, conv);
		ft_put_hex(num % 16, conv);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (conv == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (conv == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char conv)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, conv);
	return (ft_hex_len(num));
}
