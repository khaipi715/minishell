/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:14:27 by npaturzo          #+#    #+#             */
/*   Updated: 2023/10/04 16:33:41 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*ret;
	int		len;

	len = ft_num_len(n);
	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	while (n != 0)
	{
		ret[len - 1] = n % 10 + '0';
		n = n / 10;
		len --;
	}
	return (ret);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		len += ft_printstr(num);
		free(num);
	}
	return (len);
}
