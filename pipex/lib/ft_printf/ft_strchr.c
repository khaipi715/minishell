/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:02:58 by npaturzo          #+#    #+#             */
/*   Updated: 2023/07/26 17:55:02 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char)c;
	while (s[i] && s[i] != cc)
		i++;
	if (cc == '\0' && s[i] == '\0')
		return ((char *)&s[i]);
	if (s[i] == '\0')
		return (0);
	return ((char *)&s[i]);
}
