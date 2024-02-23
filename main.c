/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:52:41 by lnaulak           #+#    #+#             */
/*   Updated: 2024/02/23 13:16:25 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	end_of_file(t_data *data, char *user_input)
{
	free_env(data->env);//free env
	free(user_input);
	free(data->pwd);
	ft_putstr_fd("exit\n", 2);
	exit(EXIT_SUCCESS);
}

int	init_data(int ac, char **av, char **env, t_data *data)
{
	ac = 0;
	av = NULL;
	data->env = dup_env(env);//get malloc of enviroment
	data->pwd = getcwd(NULL, 0);//might need to change
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
	char	*input;
	char	**token;

	if (init_data(ac, av, env, &data) == 1)
		return (1);
	while (1)
	{
		input = readline("minshell$ ");
		token = ft_tokenizer(input);
	}
	return (0);
}
