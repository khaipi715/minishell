/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:10:42 by lnaulak           #+#    #+#             */
/*   Updated: 2024/02/23 13:16:19 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int ft_isredirect(char c)
{
	return (c == '<' || c == '>' || c == '|');
}

int ft_tokens(char *s)
{
    int count = 0;
    int i = 0;

    while (s[i])
	{
        while (s[i] && ft_isspace(s[i]))
            i++;
        if (s[i] == '\'' || s[i] == '\"')
		{
            count++;
            i++;
            while (s[i] && !(s[i] == '\'' || s[i] == '\"'))
                i++;
			i++;
        }
		else if (s[i] && ft_isredirect(s[i]))
		{
            count++;
            i++;
            while (s[i] && ft_isredirect(s[i]))//for >> <<< and | but a bit of a problem as it does not handle " adf" adfa" afd" since it considers the insdie the first part to be one
                i++;
        }
		else
		{
			count++;
            while (s[i] && !ft_isspace(s[i]) && !ft_isredirect(s[i]))
                i++;
        }
    }

    return count;
}

char	*malloc_redirect(char *str, int i, int *j)
{
	char	*word;

	while (str[i] && !ft_isspace(str[i]) && !ft_isredirect(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_isspace(str[i]) && !ft_isredirect(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	*malloc_quote(char *str, int i, int *j)
{
	char	*word;

	while (str[i] && !ft_isspace(str[i]) && !(str[i] == '\'' || str[i] == '\"'))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_isspace(str[i]) && !(str[i] == '\'' || str[i] == '\"'))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
char	*malloc_word(char *str, int i, int *j)
{
	char	*word;

	while (str[i] && !ft_isspace(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_tokenizer(char	*s)
{
	char	**tokens;
	int		i;
	int		count;
	int		j;

	count = ft_tokens(s);//doesn't work with triple "" inside
	tokens = malloc(sizeof(char *) * count + 1);
	i = 0;
	count = 0;
	j = 0;
    while (s[i])
	{
        while (s[i] && ft_isspace(s[i]))
            i++;
        if (s[i] == '\'' || s[i] == '\"')
		{
			tokens[count++] = malloc_quote(s, i, &j);
			i = j;
        }
		else if (s[i] && ft_isredirect(s[i]))
		{
			tokens[count++] = malloc_redirect(s, i, &j);
			i = j;
        }
		else
		{
            tokens[count++] = malloc_word(s, i, &j);
			i = j;
			i++;
        }
    }
	tokens[i] = NULL;
	return (tokens);
}

int main() {
    char str[] = "11 22 33 << 55 | 'afasf j 'wer a dsk' adfjhak' 88";
    int result = ft_tokens(str);
    printf("Number of tokens: %d\n", result);
	char	**c = ft_tokenizer(str);
	int		i = 0;
	while (result--)
		printf("%s\n", c[i++]);
    return 0;
}
