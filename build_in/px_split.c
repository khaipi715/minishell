// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   px_split.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/03/01 12:32:03 by lnaulak           #+#    #+#             */
// /*   Updated: 2024/03/01 12:58:41 by lnaulak          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/minishell.h"

// int	get_word2(int in_word, char *str, int i)
// {
// 	int		len;
// 	char	stop;

// 	len = 0;
// 	if (in_word == 1)
// 		stop = ' ';
// 	if (in_word == 2)
// 		stop = 39;
// 	if (in_word == 3)
// 		stop = 34;
// 	while (str[i + len] != stop && str[i + len])
// 		len++;
// 	return (len);
// }

// int	get_word(char *str, char **ret, int ret_pos)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	int		in_word;

// 	i = 0;
// 	j = 0;
// 	while ((str[i] == ' ' || str[i] == 39 || str[i] == 34) && str[i])
// 		i++;
// 	if (str[i] == 39)
// 		in_word = 2;
// 	else if (str[i] == 34)
// 		in_word = 3;
// 	else
// 		in_word = 1;
// 	len = get_word2(in_word, str, i);
// 	ret[ret_pos] = (char *)malloc(len + 1);
// 	while (j < len)
// 	{
// 		ret[ret_pos][j] = str[i + j];
// 		j++;
// 	}
// 	ret[ret_pos][j] = 0;
// 	return (i + len);
// }

// int	word_count2(int *in_word, char c)
// {
// 	if (*in_word == 0 && c != ' ')
// 	{
// 		if (c == 39)
// 			*in_word = 2;
// 		if (c == 34)
// 			*in_word = 3;
// 		else
// 			*in_word = 1;
// 		return (1);
// 	}
// 	else if (*in_word != 0)
// 	{
// 		if (*in_word == 1 && c == ' ')
// 			*in_word = 0;
// 		if (*in_word == 2 && c == 39)
// 			*in_word = 0;
// 		if (*in_word == 3 && c == 34)
// 			*in_word = 0;
// 	}
// 	return (0);
// }

// int	word_count(char *str)
// {
// 	int	i;
// 	int	wc;
// 	int	in_word;

// 	wc = 0;
// 	i = 0;
// 	in_word = 0;
// 	while (str[i])
// 	{
// 		wc += word_count2(&in_word, str[i]);
// 		i++;
// 	}
// 	return (wc);
// }

// char	**px_split(char *str)
// {
// 	char	**ret;
// 	int		wc;
// 	int		pos;
// 	int		i;

// 	wc = word_count(str);
// 	ret = (char **)malloc(sizeof(char *) * (wc + 1));
// 	if (ret == NULL)
// 		return (NULL);
// 	pos = 0;
// 	i = 0;
// 	while (i < wc)
// 	{
// 		pos += get_word(&str[pos], ret, i);
// 		i++;
// 	}
// 	return (ret);
// }