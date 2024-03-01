/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:59:48 by npaturzo          #+#    #+#             */
/*   Updated: 2023/07/26 17:47:34 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	ftrim;
	size_t	rtrim;

	if (s1 != NULL && set != NULL)
	{
		ftrim = 0;
		rtrim = ft_strlen(s1);
		while (s1[ftrim] && ft_strchr(set, s1[ftrim]))
			ftrim++;
		while (rtrim > ftrim && ft_strchr(set, s1[rtrim - 1]))
			rtrim--;
		ret = (char *)malloc(rtrim - ftrim + 1);
		if (ret == NULL)
			return (ret);
		ft_strlcpy(ret, &s1[ftrim], rtrim - ftrim + 1);
		return (ret);
	}
	return (NULL);
}
