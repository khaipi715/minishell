/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:25:44 by lnaulak           #+#    #+#             */
/*   Updated: 2024/03/12 11:20:31 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	write_error(char *str)
{
	printf("Error: %s\n", str);
	return (1);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int	ft_isredirect(char c)
{
	return (c == '<' || c == '>' || c == '|');
}

char	*display_prompt_msg(void)
{
	char	*line;

	line = readline("42-Minishell ~ $ ");
	if (ft_strlen(line) > 0)
		add_history(line);
	return (line);
}

int	ft_tlen(char **s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != NULL)
	{
		if (s[i][0] == '<' || s[i][0] == '>' || s[i][0] == '|')
			j++;
		i++;
	}
	return ((2 * j) + 1);
}
