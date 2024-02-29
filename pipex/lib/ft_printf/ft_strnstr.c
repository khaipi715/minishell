/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:15:29 by npaturzo          #+#    #+#             */
/*   Updated: 2023/07/26 12:36:13 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		needlen;
	int		pos;

	i = 0;
	needlen = ft_strlen(needle);
	if (needlen == 0)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		pos = 0;
		if (haystack[i] == needle[pos])
		{
			while (pos < needlen && haystack[i + pos] == needle[pos])
			{
				if (pos + i == len)
					break ;
				pos++;
			}
			if (needle[pos] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
