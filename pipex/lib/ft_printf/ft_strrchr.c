/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:42:00 by npaturzo          #+#    #+#             */
/*   Updated: 2023/07/26 20:44:41 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			ret = (char *)&s[i];
		i++;
	}
	if (s[i] == (unsigned char)c)
		ret = (char *)&s[i];
	return (ret);
}
