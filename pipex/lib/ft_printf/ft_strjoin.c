/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:50:53 by npaturzo          #+#    #+#             */
/*   Updated: 2023/07/26 13:32:17 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len;
	size_t	i;
	char	*ret;

	i = 0;
	len1 = ft_strlen(s1);
	len = len1 + ft_strlen(s2);
	ret = malloc(len + 1);
	if (ret == NULL)
		return (ret);
	while (i < len)
	{
		if (i < len1)
			ret[i] = s1[i];
		else
			ret[i] = s2[i - len1];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
