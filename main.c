/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:52:41 by lnaulak           #+#    #+#             */
/*   Updated: 2024/02/16 13:09:57 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	end_of_file(t_data *data, char *user_input)
{
	free_env(data->env);
	free(user_input);
	free(data->pwd);
	ft_putstr_fd("exit\n", 2);
	exit(EXIT_SUCCESS);
}

int	init_data(int ac, char **av, char **env, t_data *data)
{
	ac = 0;
	av = NULL;
	data->env = dup_env(env);
	data->pwd = getcwd(NULL, 0);
	data->fd_in = 0;
	data->fd_out = 1;
	data->redir = 1;
	if (!(data->env))
		return (1);
	else
		return (0);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		gnl;

	if (init_data(ac, av, env, &data) == 1)
		return (1);
	g_status = 0;
	g_user_input = NULL;
	while (1)
	{
		g_quit = 0;
		free(g_user_input);
		sig_init();
		ft_putstr_fd("minishell> ", 2);
		gnl = get_next_line(0, &g_user_input);
		if (gnl != 0)
			end_of_file(&data, g_user_input);
		else
			parser_start(g_user_input, &data);
	}
	return (0);
}
