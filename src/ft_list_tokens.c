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
            while (s[i] && ft_isredirect(s[i]))
                i++;
        }
		else
		{
			if (s[i])
				count++;
            while (s[i] && !ft_isspace(s[i]) && !ft_isredirect(s[i]) && !(s[i] == '\'' || s[i] == '\"'))
                i++;
        }
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

char	**ft_tokenizer(char *s)
{
	char	**tokenizer;
	int		i;
	int		j;
	int		start;

	j = ft_tokens(s);
	tokenizer = malloc(sizeof(char *) * j + 1);
	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i] == '\'' || s[i] == '\"')
		{
			start = i;
			i++;
			while (s[i] && !(s[i] == '\'' || s[i] == '\"'))
                i++;
			i++;
			tokenizer[j] = ft_mal(s, start, i);
			j++;
		}
		else if (s[i] && ft_isredirect(s[i]))
		{
            start = i;
            while (s[i] && ft_isredirect(s[i]))
                i++;
			tokenizer[j] = ft_mal(s, start, i);
			j++;
        }
		else if (s[i] && !ft_isspace(s[i]) && !ft_isredirect(s[i]) && !(s[i] == '\'' || s[i] == '\"'))
		{
			start = i;
            while (s[i] && !ft_isspace(s[i]) && !ft_isredirect(s[i]) && !(s[i] == '\'' || s[i] == '\"'))
                i++;
			tokenizer[j] = ft_mal(s, start, i);
			j++;
			
        }
	}
	tokenizer[j] = NULL;
	return (tokenizer);
}

// int main() {
//     char str[] = "ok'   because it work  ' ok";
//     int result = ft_tokens(str);
// 	char	**s = ft_tokenizer(str);
// 	int		i = 0;
// 	while (s[i])
//     {
// 		printf("%s\n", s[i]);
// 		i++;
// 	}
//     return 0;
// }
