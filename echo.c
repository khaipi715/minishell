/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:44:09 by npaturzo          #+#    #+#             */
/*   Updated: 2024/02/20 13:07:26 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//echo with option -n

#include "minishell.h"

int	ms_echo_ops(char *str)
{
	if (str[0] == '-')
		if (str[1] == 'n')
			if (str[2] == '\0')
				return (1);
	return (0);
}

void	ms_echo(int argc, char *args[])
{
	int	n;
	int	i;

	n = ms_echo_ops(args[0]);
	i = 0;
	if (n == 1)
	{
		i++;
		argc--;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (i < argc)
			printf(" ");
		i++;
	}
	if (n == 0)
		printf("\n");
}

//main for testing
/*
int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (1);
	ms_echo(argc - 1, &argv[1]);
	return (0);
}
*/
