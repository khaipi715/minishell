/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:31:31 by lnaulak           #+#    #+#             */
/*   Updated: 2024/03/08 15:40:24 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

int	ft_isqoutes(char	*s, int i)
{
	if (s[i] == '\'')
	{
		i++;
		while (s[i] && !(s[i] == '\''))
			i++;
		i++;
	}
	else if (s[i] == '\"')
	{
		i++;
		while (s[i] && !(s[i] == '\"'))
			i++;
		i++;
	}
	return (i);
}

int	ft_tokens(char *s)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i] && (s[i] == '\'' || s[i] == '\"'))
			i = ft_isqoutes(s, i);
		else if (s[i] && ft_isredirect(s[i]))
			while (s[i] && ft_isredirect(s[i]))
				i++;
		else
			while (s[i] && !ft_isspace(s[i]) && !ft_isredirect(s[i])
				&& !(s[i] == '\'' || s[i] == '\"'))
				i++;
		count++;
	}
	return (count);
}

char	*ft_mal(char *s, int start, int end)
{
	char	*mal;
	int		i;

	i = start;
	while (s[i] && i < end)
		i++;
	mal = malloc(sizeof(char) * i + 1);
	i = 0;
	while (s[i] && start < end)
		mal[i++] = s[start++];
	mal[++i] = '\0';
	return (mal);
}

int	end_of_token(char	*s, int i)
{
	if (s[i] == '\'' || s[i] == '\"')
		i = ft_isqoutes(s, i);
	else if (s[i] && ft_isredirect(s[i]))
		while (s[i] && ft_isredirect(s[i]))
			i++;
	else if (s[i] && !ft_isspace(s[i]) && !ft_isredirect(s[i])
		&& !(s[i] == '\'' || s[i] == '\"'))
		while (s[i] && !ft_isspace(s[i]) && !ft_isredirect(s[i])
			&& !(s[i] == '\'' || s[i] == '\"'))
			i++;
	return (i);
}

char	**ft_tokenizer(char *s, t_monitor *monitor)
{
	char	**tokenizer;
	int		i;
	int		j;
	int		start;

	j = ft_tokens(s);
	monitor->sub_token = j;
	tokenizer = malloc(sizeof(char *) * j + 1);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		start = i;
		i = end_of_token(s, i);
		if (s[start] == '\'' || s[start] == '\"')
			tokenizer[j++] = ft_mal(s, start + 1, i - 1);
		else
			tokenizer[j++] = ft_mal(s, start, i);
	}
	tokenizer[j] = NULL;
	return (tokenizer);
}
