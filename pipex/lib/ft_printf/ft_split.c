/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:04:42 by npaturzo          #+#    #+#             */
/*   Updated: 2023/07/26 19:33:29 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c)
{
	int	newword;
	int	wc;

	newword = 0;
	wc = 0;
	while (*str)
	{
		if (*str != c && newword == 0)
		{
			newword = 1;
			wc++;
		}
		if (*str == c && newword == 1)
			newword = 0;
		str++;
	}
	return (wc);
}

static char	*copy_word(const char *str, char c)
{
	const char	*start;
	int			len;
	int			i;
	char		*ret;

	start = str;
	len = 0;
	while (*str && *str != c)
	{
		str++;
		len++;
	}
	ret = (char *)malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = start[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static void	free_mem(char **ret, int count)
{
	while (count > 0)
		free(ret[--count]);
	free(ret);
}

static void	find_word(char **ret, const char **s, char c, int *i)
{
	ret[*i] = copy_word(*s, c);
	if (ret[*i] == NULL)
	{
		free_mem(ret, *i);
		*i = 0;
	}
	else
	{
		(*i)++;
		while (**s && **s != c)
			(*s)++;
	}
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	int		wc;
	int		i;

	if (s == NULL)
		return (NULL);
	wc = word_count(s, c);
	ret = (char **)malloc(sizeof(char *) * (wc + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
			find_word(ret, &s, c, &i);
		else
		{
			while (*s == c)
				s++;
		}
	}
	ret[i] = NULL;
	return (ret);
}
