/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:24:15 by lnaulak           #+#    #+#             */
/*   Updated: 2024/03/12 18:22:32 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	token_print(t_monitor *monitor)
{
	int	i = -1;
	while (++i < monitor->nb_tokens)
	{
		int	j = 0;
		printf("inside token[%d]: ", i);
		while (monitor->tokens[i].argv[j])
		{
			printf("%s ", monitor->tokens[i].argv[j]);
			j++;
		}
		printf("\n");
	}
}
// might be good to change it to while loop with i > less then 3 for redirect

char	**ft_tjoin(char **s, t_monitor *monitor)
{
	char	**mal;
	int		i;
	int		j;

	mal = malloc(sizeof(char *) * monitor->sub_token + 1);
	i = monitor->start;
	j = 0;
	if ((s[i][0] == '<' || s[i][0] == '>' || s[i][0] == '|'))
	{
		mal[j] = s[i];
		i++;
		j++;
		monitor->has_redirect = true;
	}
	else if (s[i])
	{
		while (s[i] && s[i][0] != '<' && s[i][0] != '>' && s[i][0] != '|')
		{
			mal[j] = s[i];
			i++;
			j++;
		}
	}
	mal[j] = NULL;
	monitor->start = i;
	return (mal);
}

void	init_tokens(t_monitor *monitor)
{
	int				i;
	t_tokens		*tokens;

	monitor->tokens = malloc(sizeof(t_tokens) * monitor->nb_tokens);
	tokens = monitor->tokens;
	i = -1;
	while (++i < monitor->nb_tokens)
	{
		tokens[i].id = i;
		tokens[i].monitor = monitor;
		tokens[i].argv = ft_tjoin(monitor->input_token, monitor);
	}
	// token_print(monitor);
	monitor->start = 0;
}
